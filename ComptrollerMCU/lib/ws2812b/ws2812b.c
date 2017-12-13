#include <stdint.h>
#include <stdlib.h>
#include <util/delay.h>
#include <avr/io.h>
#include <avr/interrupt.h>
#include <stdio.h>
#include <string.h>
#include "ws2812b.h"

#define PIN 0

uint8_t *pixels;
uint8_t num_leds = 20;
#define numBytes (num_leds * 3)

void showPixels(void);

void initLedString(void)
{
  // change these based on pin
  DDRC |= _BV(PIN);
  PORTC |= _BV(PIN);

  changeNumLeds(num_leds); 

  showPixels();
}

void changeNumLeds(uint16_t numLeds)
{
  num_leds = numLeds;

  if (pixels)
    free(pixels);
  pixels = malloc(numBytes);

}

void ledStatic(uint8_t red, uint8_t green, uint8_t blue)
{
  uint8_t *ptr = pixels;
  for (int i = 0; i < num_leds; i++)
  {
    *ptr++ = green;
    *ptr++ = red;
    *ptr++ = blue;
  }
  // memset(pixels, 255, numBytes);
  showPixels();
}

void showPixels(void)
{
  if(!pixels) return;

  _delay_us(50);
  // Data latch = 50+ microsecond pause in the output stream.  Rather than
  // put a delay at the end of the function, the ending time is noted and
  // the function will simply hold off (if needed) on issuing the
  // subsequent round of data until the latch time has elapsed.  This
  // allows the mainline code to start generating the next frame of data
  // rather than stalling for the latch.
  // while((micros() - endTime) < 50L);
  // endTime is a private member (rather than global var) so that mutliple
  // instances on different pins can be quickly issued in succession (each
  // instance doesn't delay the next).

  // In order to make this code runtime-configurable to work with any pin,
  // SBI/CBI instructions are eschewed in favor of full PORT writes via the
  // OUT or ST instructions.  It relies on two facts: that peripheral
  // functions (such as PWM) take precedence on output pins, so our PORT-
  // wide writes won't interfere, and that interrupts are globally disabled
  // while data is being issued to the LEDs, so no other code will be
  // accessing the PORT.  The code takes an initial 'snapshot' of the PORT
  // state, computes 'pin high' and 'pin low' values, and writes these back
  // to the PORT register as needed.

  cli(); // Need 100% focus on instruction timing

  volatile uint16_t i   = numBytes; // Loop counter
  volatile uint8_t
   *ptr = pixels,   // Pointer to next byte
    b   = *ptr++,   // Current byte value
    hi,             // PORT w/output bit set high
    lo;             // PORT w/output bit set low

  // Hand-tuned assembly code issues data to the LED drivers at a specific
  // rate.  There's separate code for different CPU speeds (8, 12, 16 MHz)
  // for both the WS2811 (400 KHz) and WS2812 (800 KHz) drivers.  The
  // datastream timing for the LED drivers allows a little wiggle room each
  // way (listed in the datasheets), so the conditions for compiling each
  // case are set up for a range of frequencies rather than just the exact
  // 8, 12 or 16 MHz values, permitting use with some close-but-not-spot-on
  // devices (e.g. 16.5 MHz DigiSpark).  The ranges were arrived at based
  // on the datasheet figures and have not been extensively tested outside
  // the canonical 8/12/16 MHz speeds; there's no guarantee these will work
  // close to the extremes (or possibly they could be pushed further).
  // Keep in mind only one CPU speed case actually gets compiled; the
  // resulting program isn't as massive as it might look from source here.

    // WS2811 and WS2812 have different hi/lo duty cycles; this is
    // similar but NOT an exact copy of the prior 400-on-8 code.

    // 20 inst. clocks per bit: HHHHHxxxxxxxxLLLLLLL
    // ST instructions:         ^   ^        ^       (T=0,5,13)

    volatile uint8_t next, bit;

    volatile uint8_t *port = &PORTC;
    uint8_t pinMask = _BV(PIN);

    hi   = *port |  pinMask;
    lo   = *port & ~pinMask;
    next = lo;
    bit  = 8;

    asm volatile(
     "head20:\n\t"          // Clk  Pseudocode    (T =  0)
      "st   %a0, %1\n\t"    // 2    PORT = hi     (T =  2)
      "sbrc %2, 7\n\t"      // 1-2  if(b & 128)
       "mov  %4, %1\n\t"    // 0-1   next = hi    (T =  4)
      "dec  %3\n\t"         // 1    bit--         (T =  5)
      "st   %a0, %4\n\t"    // 2    PORT = next   (T =  7) ST and MOV don't
      "mov  %4, %5\n\t"     // 1    next = lo     (T =  8) change Z flag,
      "breq nextbyte20\n\t" // 1-2  if(bit == 0)       <-- so this is OK.
      "rol  %2\n\t"         // 1    b <<= 1       (T = 10)
      "rjmp .+0\n\t"        // 2    nop nop       (T = 12)
      "nop\n\t"             // 1    nop           (T = 13)
      "st   %a0, %5\n\t"    // 2    PORT = lo     (T = 15)
      "nop\n\t"             // 1    nop           (T = 16)
      "rjmp .+0\n\t"        // 2    nop nop       (T = 18)
      "rjmp head20\n\t"     // 2    -> head20 (next bit out)
     "nextbyte20:\n\t"      //                    (T = 10)
      "ldi  %3, 8\n\t"      // 1    bit = 8       (T = 11)
      "ld   %2, %a6+\n\t"   // 2    b = *ptr++    (T = 13)
      "st   %a0, %5\n\t"    // 2    PORT = lo     (T = 15)
      "nop\n\t"             // 1    nop           (T = 16)
      "sbiw %7, 1\n\t"      // 2    i--           (T = 18)
      "brne head20\n\t"     // 2    if(i != 0) -> head20 (next byte)
      ::
      "e" (port),          // %a0
      "r" (hi),            // %1
      "r" (b),             // %2
      "r" (bit),           // %3
      "r" (next),          // %4
      "r" (lo),            // %5
      "e" (ptr),           // %a6
      "w" (i)              // %7
    ); // end asm

  
  
  sei();

  // endTime = micros(); // Save EOD time for latch on next call
}