#include "lib/ws2812b/ws2812b.h"
#include "lib/ws2812b/ledString.h"
#include "lib/uart/uart.h"
#include <avr/io.h>
#include <util/delay.h>
#include <avr/sleep.h>
#include <avr/interrupt.h>

void uartReceive(uint8_t data);
typedef enum { uartIdle, uartIndex, uartRGB, uartNumLeds } uartState;
volatile uartState currentUartMode;
uint8_t uartStateCount; 

uint8_t uartCommand;
uint16_t numLeds;
// uint8_t index;
uint8_t r, g, b;

ledString leds1, leds2, leds3;
ledString volatile *string;

int main(void)
{
	// enable random pins for single leds
	DDRD |= _BV(3);
	PORTD |= _BV(3);
	DDRD |= _BV(4);
	PORTD &= ~_BV(4);

	// onboard LED
	DDRB |= _BV(5);
	PORTB &= ~_BV(5);

	uartInit(&uartReceive);
	// uartWriteLine("Starting...");
	// _delay_ms(500);

	initLedString(&leds1, 0, &DDRC, &PORTC, 0);
	initLedString(&leds2, 1, &DDRB, &PORTB, 3);
	initLedString(&leds3, 2, &DDRD, &PORTD, 2);

	updateNumLeds(&leds1, 120);
	updateNumLeds(&leds2, 2);
	updateNumLeds(&leds3, 2);

	ledStatic(&leds3, 0, 0, 0);

	ledRainbow(&leds3, FORWARD, 000000);
	// ledStatic(&leds2, 0, 255, 0);
	// ledStatic(&leds3, 255, 255, 255);

	// leds3.animationLength = 2;
	// leds3.animationSteps = 1000;
	// updateNumLeds(&leds3, 2);
	// ledWave(&leds3, 100, 0, 1, 1, 0, 100);

// void ledWave(ledString *string, uint8_t red1, uint8_t green1, uint8_t blue1, uint8_t red2, uint8_t green2, uint8_t blue2)

	uartStateCount = 0;

	// uint8_t uart = 0x00;
	// uint8_t r, g, b;
	// uint8_t r2, g2, b2;
	// uint16_t num_leds = 0;
	// uint8_t index;

	while(1)
	{
		PORTB |= _BV(5);
		_delay_ms(500);
		PORTB &= ~_BV(5);
		_delay_ms(500);
		sei();

		set_sleep_mode(SLEEP_MODE_IDLE);
		sleep_mode();
	}

	// 		// receive data
	// 		switch(uart)
	// 		{

	// 			case 'W':
	// 				string->animationLength = uartReceiveCharBlocking();
	// 			case 'B':
	// 				// receive colour
	// 				r = uartReceiveCharBlocking();
	// 				g = uartReceiveCharBlocking();
	// 				b = uartReceiveCharBlocking();

	// 				r2 = uartReceiveCharBlocking();
	// 				g2 = uartReceiveCharBlocking();
	// 				b2 = uartReceiveCharBlocking();

	// 				string->animationSteps = uartReceiveCharBlocking();
	// 				string->animationSteps |= (uartReceiveCharBlocking() << 8);

	// 				updateNumLeds(string, num_leds);

	// 				if (uart == 'B')
	// 					ledBreathe(string, r, g, b, r2, g2, b2);
	// 				else
	// 					ledWave(string, r, g, b, r2, g2, b2);

	// 				break;
	// 			default:
	// 				break;
	// 		}
	// 	}
	// 	// otherwise check if leds are breathing
	// 	// else
	// 	// {
	// 	// 	ledAnimate(&leds1);
	// 	// 	if (uartAvailable())
	// 	// 		continue;
	// 	// 	ledAnimate(&leds2);
	// 	// 	if (uartAvailable())
	// 	// 		continue;
	// 	// 	ledAnimate(&leds3);
	// 	// 	if (uartAvailable())
	// 	// 		continue;
	// 	// }
	// }
	return 0;
}

// uart rx interrupt
void uartReceive(uint8_t data)
{
	switch(currentUartMode)
	{
		case uartIdle:
			uartCommand = data;
			switch(uartCommand)
			{
				case 'H':
					uartWriteLine("H");
					break;
				default:
					// every other command requires an index
					currentUartMode = uartIndex;
					break;
			}
			break;
		case uartIndex:
			// create led string pointer
			switch(data)
			{
				case 0:
					string = &leds1;
					break;
				case 1:
					string = &leds2;
					break;
				case 2:
				default:
					string = &leds3;
					break;
			}

			uartStateCount = 0;

			// what to receive next
			switch(uartCommand)
			{
				case 'I':
					currentUartMode = uartNumLeds;
					break;
				case 'S':
				case 'W':
				case 'B':
					currentUartMode = uartRGB;
					break;
				default:
					currentUartMode = uartIdle;
					break;
			}
			break;
		case uartNumLeds:
			numLeds |= ((uint16_t) data) << ((uartStateCount++) * 8);

			// finished receiving number of leds
			if (uartStateCount == 2)
			{
				uartWriteChar(uartCommand);

				uartWriteString("setting num leds on ");
				uartWriteDec8(string->index);
				uartWriteString(" to ");
				uartWriteDec16(numLeds);
				uartNewLine();	
				

				updateNumLeds(string, numLeds);
				numLeds = 0; // clear variable for next string 
				
				currentUartMode = uartIdle;
			}
			break;
		case uartRGB:
			switch(uartStateCount)
			{
				case 0:
					r = data;
					break;
				case 1:
					g = data;
					break;
				case 2:
					b = data;
					break;
				default:
					currentUartMode = uartIdle;
					break;
			}

			// received rgb
			if (uartStateCount == 2)
			{
				ledStatic(string, r, g, b);
				uartWriteChar(uartCommand);
				uartWriteString("Setting string ");
				uartWriteDec8(string->index);
				uartWriteString(" to (");
				uartWriteDec8(r);
				uartWriteString(", ");
				uartWriteDec8(g);
				uartWriteString(", ");
				uartWriteDec8(b);
				uartWriteLine(")");

				currentUartMode = uartIdle;
			}

			uartStateCount++;
			break;
		default:
			// shouldn't happen
			currentUartMode = uartIdle;
			break;
	}
} 