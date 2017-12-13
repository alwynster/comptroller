#include "LEDController.h"
#include "LED.h"
#include "../UART/UART.h"
#include <stdio.h>

LEDController::LEDController()
{
	SetupUart();
	buffer = (unsigned char *) malloc(BUFFER_SIZE);
	buffer[0] = 'S';
	*(buffer + 1) = NUM_LEDS & 0xff;
	*(buffer + 2) = (NUM_LEDS >> 8) & 0xff;
}

LEDController::~LEDController()
{
	free(buffer);
}

void LEDController::staticColour(uint8_t red, uint8_t green, uint8_t blue)
{
	printf("Setting all LEDs to (%d, %d, %d)\n", red, green, blue);
	unsigned char *ptr = this->buffer + 3;

	
	for (int i = 0; i < NUM_LEDS; i++)
	{
		leds->setColour(red, green, blue);
		leds->getColour(ptr);
		ptr += 3;
	}

	WriteUart(buffer, BUFFER_SIZE);
}