#include "LEDController.h"
#include "LED.h"
#include "../UART/UART.h"
#include <stdio.h>

LEDController::LEDController(uint8_t index, uint8_t numLeds)
{
	//SetupUart();
	this->numLeds = numLeds;
	this->index = index;

	this->buffer = NULL;
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
	if (buffer)
		free(buffer);
	
	buffer = (unsigned char *)malloc(3 + 3);
	*(buffer + 0) = 'S';
	*(buffer + 1) = index;
	*(buffer + 2) = this->numLeds;


	printf("Setting all LEDs (%d) on %d to (%d, %d, %d)\n", this->numLeds, this->index, red, green, blue);
	unsigned char *ptr = this->buffer + 3;


	//for (int i = 0; i < this->numLeds; i++)
	//{
		leds->setColour(red, green, blue);
		leds->getColour(ptr);
		//ptr += 3;
	//}

	WriteUart(buffer, 3 + 3);
}


void LEDController::breathingColour(uint16_t steps, uint32_t colour1, uint32_t colour2)
{
	this->breathingColour(steps, (colour1 >> 16) & 0xff, (colour1 >> 8) & 0xff, colour1 & 0xff, (colour2 >> 16) & 0xff, (colour2 >> 8) & 0xff, colour2 & 0xff);
}

void LEDController::breathingColour(uint16_t steps, uint8_t red1, uint8_t green1, uint8_t blue1, uint8_t red2, uint8_t green2, uint8_t blue2)
{
	if (buffer)
		free(buffer);

	buffer = (unsigned char *)malloc(3 + 2 * 3 + 2);
	*(buffer + 0) = 'B';
	*(buffer + 1) = index;
	*(buffer + 2) = this->numLeds;

	printf("Setting all LEDs on %d to breathe (%d, %d, %d)\n", this->index, red1, green1, blue1);
	unsigned char *ptr = this->buffer + 3;


	//for (int i = 0; i < this->numLeds; i++)
	//{
		leds->setColour(red1, green1, blue1);
		leds->getColour(ptr);
		ptr += 3;
		leds->setColour(red2, green2, blue2);
		leds->getColour(ptr);
		ptr += 3;
		*ptr++ = steps & 0xff;
		*ptr++ = (steps >> 8) & 0xff;
	//}

	WriteUart(buffer, 3 + 2 * 3 + 2);
}