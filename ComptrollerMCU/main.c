#include "lib/ws2812b/ws2812b.h"
#include "lib/ws2812b/ledString.h"
#include "lib/uart/uart.h"
#include <avr/io.h>
#include <util/delay.h>

void uartReceive(uint8_t data);

int main(void)
{
	// enable random pins for single leds
	DDRD |= _BV(3);
	PORTD |= _BV(3);
	DDRD |= _BV(4);
	PORTD &= ~_BV(4);

	uartInit(&uartReceive);
	uartWriteString("Starting...");
	_delay_ms(500);

	ledString leds1, leds2, leds3;
	initLedString(&leds1, &DDRC, &PORTC, 0);
	initLedString(&leds2, &DDRB, &PORTB, 3);
	initLedString(&leds3, &DDRD, &PORTD, 2);

	updateNumLeds(&leds1, 2);
	updateNumLeds(&leds2, 2);
	updateNumLeds(&leds3, 2);

	// ledStatic(&leds1, 0, 0, 255);
	// ledStatic(&leds2, 0, 255, 0);
	// ledStatic(&leds3, 255, 0, 0);

	leds3.animationLength = 2;
	leds3.animationSteps = 1000;
	updateNumLeds(&leds3, 2);
	ledWave(&leds3, 100, 0, 1, 1, 0, 100);

// void ledWave(ledString *string, uint8_t red1, uint8_t green1, uint8_t blue1, uint8_t red2, uint8_t green2, uint8_t blue2)

	uint8_t uart = 0x00;
	uint8_t r, g, b;
	uint8_t r2, g2, b2;
	uint16_t num_leds = 0;
	uint8_t index;
	ledString *string;

	while(1)
	{
		// check if new uart data is available
		if (uartAvailable())
		{

			uart = 0;	
			// receive configs
			// while (uart != 'S')
			{
				uart = uartReceiveCharBlocking();
				// uartWriteString("receiving...");
				// _delay_ms(500);
			}

			index = uartReceiveCharBlocking();

			// num_leds = uartReceiveCharBlocking();

			// num_leds |= (uartReceiveCharBlocking()) << 8;
			

			switch(index)
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



			// receive data
			switch(uart)
			{
				case 'I':
					// init 
					num_leds = uartReceiveCharBlocking();
					num_leds |= (uartReceiveCharBlocking() << 8);

					uartWriteString("setting num leds ");
					uartWriteDec16(num_leds);
					uartNewLine();

					updateNumLeds(string, num_leds);
					break;

				case 'S':
					// receive colour
					r = uartReceiveCharBlocking();
					g = uartReceiveCharBlocking();
					b = uartReceiveCharBlocking();


					ledStatic(string, r, g, b);

					break;
				case 'W':
					string->animationLength = uartReceiveCharBlocking();
				case 'B':
					// receive colour
					r = uartReceiveCharBlocking();
					g = uartReceiveCharBlocking();
					b = uartReceiveCharBlocking();

					r2 = uartReceiveCharBlocking();
					g2 = uartReceiveCharBlocking();
					b2 = uartReceiveCharBlocking();

					string->animationSteps = uartReceiveCharBlocking();
					string->animationSteps |= (uartReceiveCharBlocking() << 8);

					updateNumLeds(string, num_leds);

					if (uart == 'B')
						ledBreathe(string, r, g, b, r2, g2, b2);
					else
						ledWave(string, r, g, b, r2, g2, b2);

					break;
				default:
					break;
			}
		}
		// otherwise check if leds are breathing
		else
		{
			ledAnimate(&leds1);
			if (uartAvailable())
				continue;
			ledAnimate(&leds2);
			if (uartAvailable())
				continue;
			ledAnimate(&leds3);
			if (uartAvailable())
				continue;
		}
	}
	return 0;
}

void uartReceive(uint8_t data)
{

}