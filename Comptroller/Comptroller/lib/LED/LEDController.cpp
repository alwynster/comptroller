#include "LEDController.h"
#include "LED.h"
#include "../UART/UART.h"
#include "../LED/WS2812_Definitions.h"
#include <iostream>   
//#include <stdlib.h>
#include <cstdlib>
#include <atlstr.h>

void setBufferColour(uint8_t *buffer, uint8_t r, uint8_t g, uint8_t b);

LEDController::LEDController(uint8_t index, uint16_t numLeds)
{
	this->uart = gcnew Uart();

	if (!this->uart->isOpen())
		return;

	//SetupUart();
	this->numLeds = numLeds;
	this->index = index;

	this->setNumLeds();

	this->leds = gcnew Colour();

	//this->uart->SetupUart();
}

LEDController::~LEDController()
{
	staticColour(BLACK);
}


void LEDController::setNumLeds(void)
{
	uint8_t *buffer = new uint8_t[4];// (unsigned char *)std::malloc(4);
	*(buffer + 0) = 'I';
	*(buffer + 1) = this->index;
	*(buffer + 2) = 0xff & this->numLeds;
	*(buffer + 3) = 0xff & (this->numLeds >> 8);

	uart->WriteUart(buffer, 4);
	uint8_t *readbuffer = new uint8_t[100];
	int readNum = 0; 
	
	do
	{
		readNum = uart->ReadUart(readbuffer, 100);


		if (readNum < 0)
			MessageBox(NULL, L"Error with reading uart...", L"UART Error", MB_OK);
		else if (readNum > 0)
			MessageBox(NULL, CStringW(readbuffer), L"UART Success", MB_OK);
		uart->WriteUart(buffer, 4);
	}
	while (readNum == 0);

	printf("Setting string %d to %d LEDs\n", this->index, this->numLeds);

	delete[] buffer;
	delete[] readbuffer;
}


void LEDController::staticColour(Colour ^colour)
{
	this->staticColour(colour->r, colour->g, colour->b);
}

void LEDController::staticColour(uint32_t colour)
{
	this->staticColour((colour >> 0) & 0xff, (colour >> 8) & 0xff, (colour >> 16) & 0xff);
}

void LEDController::staticColour(uint8_t red, uint8_t green, uint8_t blue)
{
	uint8_t header = 2;
	uint16_t size = header + 3;
	uint8_t *buffer = new uint8_t[size];
	*(buffer + 0) = 'S';
	*(buffer + 1) = index;

	printf("Setting all LEDs (%d) on %d to (%d, %d, %d)\n", this->numLeds, this->index, red, green, blue);
	unsigned char *ptr = buffer + header;

	setBufferColour(ptr, red, green, blue);

	uart->WriteUart(buffer, size);
	
	delete[] buffer;
}

void LEDController::waveColour(uint16_t steps, uint8_t length, uint32_t colour1, uint32_t colour2)
{
	this->waveColour(steps, length, (colour1 >> 16) & 0xff, (colour1 >> 8) & 0xff, colour1 & 0xff, (colour2 >> 16) & 0xff, (colour2 >> 8) & 0xff, colour2 & 0xff);
}

void LEDController::waveColour(uint16_t steps, uint8_t length, uint8_t red1, uint8_t green1, uint8_t blue1, uint8_t red2, uint8_t green2, uint8_t blue2)
{
	uint8_t header = 3;
	uint16_t size = header + 2 * 3 + 2;
	uint8_t *buffer = new uint8_t[size];

	*(buffer + 0) = 'W';
	*(buffer + 1) = index;
	*(buffer + 2) = length;


	printf("Setting all LEDs on %d to wave (%d, %d, %d)\n", this->index, red1, green1, blue1);
	uint8_t *ptr = buffer + header;

	setBufferColour(ptr, red1, green1, blue1);

	ptr += 3;
	setBufferColour(ptr, red2, green2, blue2);
	ptr += 3;
	
	*ptr++ = steps & 0xff;
	*ptr++ = (steps >> 8) & 0xff;

	uart->WriteUart(buffer, size);

	delete[] buffer;
}

void setBufferColour(uint8_t * buffer, uint8_t r, uint8_t g, uint8_t b)
{
	*(buffer + 0) = r;
	*(buffer + 1) = g;
	*(buffer + 2) = b;
}

void LEDController::breathingColour(uint16_t steps, uint32_t colour1, uint32_t colour2)
{
	this->breathingColour(steps, (colour1 >> 16) & 0xff, (colour1 >> 8) & 0xff, colour1 & 0xff, (colour2 >> 16) & 0xff, (colour2 >> 8) & 0xff, colour2 & 0xff);
}

void LEDController::breathingColour(uint16_t steps, uint8_t red1, uint8_t green1, uint8_t blue1, uint8_t red2, uint8_t green2, uint8_t blue2)
{
	uint8_t header = 2;
	uint16_t size = header + 2 * 3 + 2;
	uint8_t *buffer = new uint8_t[size];
	*(buffer + 0) = 'B';
	*(buffer + 1) = index;
	
	printf("Setting all LEDs on %d to breathe (%d, %d, %d)\n", this->index, red1, green1, blue1);
	unsigned char *ptr = buffer + header;

	setBufferColour(ptr, red1, green1, blue1);
	ptr += 3;
	setBufferColour(ptr, red2, green2, blue2);
	ptr += 3;
	*ptr++ = steps & 0xff;
	*ptr++ = (steps >> 8) & 0xff;

	uart->WriteUart(buffer, size);
	
	delete[] buffer;
}