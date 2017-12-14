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
	PORTD &= ~_BV(3);
	DDRD |= _BV(5);
	PORTD |= _BV(5);

	uartInit(&uartReceive);
	uartWriteString("Starting...");
	_delay_ms(500);

	ledString leds1, leds2, leds3;
	initLedString(&leds1, &DDRB, &PORTB, 4, 30);
	initLedString(&leds2, &DDRB, &PORTB, 3, 30);
	initLedString(&leds3, &DDRD, &PORTD, 6, 1);

	ledStatic(&leds1, 0, 0, 0);
	ledStatic(&leds2, 0, 0, 0);
	ledStatic(&leds3, 0, 0, 0);

	uint8_t uart = 0x00;
	uint8_t r, g, b;
	// uint16_t num_leds = 0;
	uint8_t index;
	ledString *string;

	while(1)
	{
		uart = 0;	
		// receive configs
		while (uart != 'S')
		{
			uart = uartReceiveCharBlocking();
			// uartWriteString("receiving...");
			// _delay_ms(500);
		}

		index = uartReceiveCharBlocking();

		// num_leds = uartReceiveCharBlocking();
		// num_leds |= (uartReceiveCharBlocking()) << 8;
		// changeNumLeds(num_leds);
		
		// receive colour
		r = uartReceiveCharBlocking();
		g = uartReceiveCharBlocking();
		b = uartReceiveCharBlocking();

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
		ledStatic(string, r, g, b);
	}
	return 0;
}

void uartReceive(uint8_t data)
{

}