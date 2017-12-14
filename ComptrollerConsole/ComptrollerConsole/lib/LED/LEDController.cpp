#include "LEDController.h"
#include "LED.h"
#include "../UART/UART.h"
#include <stdio.h>

LEDController::LEDController(uint8_t index, uint8_t numLeds)
{
	//SetupUart();
	this->numLeds = numLeds;
	this->index = index;

	buffer = (unsigned char *) malloc(2 + this->numLeds * 3);
	*(buffer + 0) = 'S';
	*(buffer + 1) = index;

	this->leds = new LED[numLeds];
	/**(buffer + 2) = numLeds & 0xff;
	*(buffer + 3) = (numLeds >> 8) & 0xff;*/
}

LEDController::~LEDController()
{
	free(buffer);
}

void LEDController::staticColour(uint32_t colour)
{
	this->staticColour((colour >> 16) & 0xff, (colour >> 8) & 0xff, colour & 0xff);
}

void LEDController::staticColour(uint8_t red, uint8_t green, uint8_t blue)
{
	printf("Setting all LEDs on %d to (%d, %d, %d)\n", this->index, red, green, blue);
	unsigned char *ptr = this->buffer + 2;

	
	for (int i = 0; i < this->numLeds; i++)
	{
		leds->setColour(red, green, blue);
		leds->getColour(ptr);
		ptr += 3;
	}

	WriteUart(buffer, 2 + this->numLeds * 3);
}