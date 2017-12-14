#include "ledString.h"
#include "ws2812b.h"
#include <avr/io.h>
#include <stdlib.h>
#include <stdio.h>
#include <string.h>


void initLedString(ledString *string, volatile uint8_t *ddr, volatile uint8_t *port, uint8_t pin, uint8_t numberLeds)
{
  string->ddr = ddr;
  string->port = port;
  string->pin = pin;

  // change these based on pin
  *string->ddr |= _BV(string->pin);
  *string->port &= ~_BV(string->pin);
  
  if (string->buffer)
    free(string->buffer);

  string->numLeds = numberLeds;
  string->buffer = malloc(string->numLeds * 3);
  memset(string->buffer, 0, 3 * string->numLeds);
  
  showLeds(string);
}


void ledStatic(ledString *string, uint8_t red, uint8_t green, uint8_t blue)
{
  uint8_t *ptr = string->buffer;
  for (int i = 0; i < string->numLeds; i++)
  {
    *ptr++ = green;
    *ptr++ = red;
    *ptr++ = blue;
  }
  // memset(pixels, 255, numBytes);
  showLeds(string);
}
