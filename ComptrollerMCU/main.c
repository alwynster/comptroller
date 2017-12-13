#include "lib/ws2812b/ws2812b.h"
#include "lib/uart/uart.h"
#include <util/delay.h>

void uartReceive(uint8_t data);

int main(void)
{
	uartInit(&uartReceive);
	uartWriteString("Starting...");
	_delay_ms(500);

	initLedString();
	ledStatic(0, 0, 0);

	uint8_t uart = 0x00;
	uint8_t r, g, b;
	uint16_t num_leds = 0;
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

		num_leds = uartReceiveCharBlocking();
		num_leds |= (uartReceiveCharBlocking()) << 8;
		changeNumLeds(num_leds);
		
		// receive colour
		r = uartReceiveCharBlocking();
		g = uartReceiveCharBlocking();
		b = uartReceiveCharBlocking();

		ledStatic(r, g, b);
	}
	return 0;
}

void uartReceive(uint8_t data)
{

}