#include "LEDController.h"
#include "LED.h"
//#include "../UART/UART.h"
#include "../LED/WS2812_Definitions.h"
#include <iostream>   
//#include <stdlib.h>
#include <cstdlib>
#include <atlstr.h>

void setBufferColour(uint8_t *buffer, uint8_t r, uint8_t g, uint8_t b);
#define SERIAL_TIMEOUT 5000

LEDController::LEDController(std::list<uint16_t> numLeds)
{
	// do not allow colour update before previous is done
	this->updating = false;

	this->serial = new serial::Serial("COM3", 9600, serial::Timeout::simpleTimeout(SERIAL_TIMEOUT));
	this->serial->flush();
	//Sleep(1000); 
	std::string readstr, readstr2;
	bool match = false;
	for (int i = 0; i < 5; i++)
	{
		this->serial->write("H");
		readstr = this->serial->readline(200, "\n");
		if (readstr.length() == 2)
			match = readstr.front() == 'H';
		
		if (match)
			break;
	}
	//while (!match);

	if (!match)
	{
		// takes the bootloader some time to load
		this->serial->close();
		MessageBox(NULL, L"Nothing received at startup", L"UART Fail", MB_OK);
		return;
	}

	//this->serial->flush();
	this->readAll();
	this->serial->setTimeout(serial::Timeout::simpleTimeout(SERIAL_TIMEOUT));

	
	//if (readstr.length() > 0)
	//	MessageBox(NULL, CStringW(readstr.c_str()), L"UART Success", MB_OK);

	/*if (readstr.length() == 0)
	{*/
		// try handshake to see if mcu already running
		
	//}
	//MessageBox(NULL, CStringW(this->serial->readline().c_str()), L"UART Success", MB_OK);

	//this->uart = gcnew Uart();

	//if (!this->uart->isOpen())
	//	return;

	//SetupUart();
	//this->numLeds = numLeds;
	//this->index = index;

	// set number of all used strings
	this->numLedStrings = numLeds.size();
	for (uint8_t i = 0; i < numLedStrings; i++)
	{
		this->setNumLeds(i, numLeds.front());
		numLeds.pop_front();
	}

	//Sleep(2000);

	this->leds = gcnew Colour();

	//this->uart->SetupUart();
}

std::string LEDController::readline(void)
{
	std::string str = this->serial->readline(200, "\n");
	if (str.length() == 0)
		this->serial->close();
	return str;
}

std::string LEDController::readAll(void)
{
	std::string str = "";
	if (this->serial->available() > 0)
		str = this->serial->read(this->serial->available());
	return str;
}

LEDController::~LEDController()
{
	this->blackout();
}

void LEDController::blackout()
{
	for (uint8_t i = 0; i < this->numLedStrings; i++)
		staticColour(i, BLACK);
}


void LEDController::setNumLeds(uint8_t index, uint16_t numLeds)
{
	if (!this->serial->isOpen())
		return;

	uint8_t *buffer = new uint8_t[4];// (unsigned char *)std::malloc(4);
	*(buffer + 0) = 'I';
	*(buffer + 1) = index;
	*(buffer + 2) = 0xff & numLeds;
	*(buffer + 3) = 0xff & (numLeds >> 8);

	this->serial->write(buffer, 4);
	//uart->WriteUart(buffer, 4);
	//uint8_t *readbuffer = new uint8_t[100];
	//int readNum = 0; 
	std::string readStr = "";
	
	// weird flashing here on second string
	// related to animation... turned it off

	readStr = this->readline();
	//if (readStr.length() > 0)
	//	MessageBox(NULL, CStringW(readStr.c_str()), L"UART Success", MB_OK);
	//else
	if (readStr.length() == 0)
		MessageBox(NULL, L"Nothing received", L"UART Fail", MB_OK);
	else if (readStr.front() != 'I')
		MessageBox(NULL, CStringW(readStr.c_str()), L"Incorrect response", MB_OK);

	//printf("Setting string %d to %d LEDs\n", this->index, this->numLeds);

	delete[] buffer;
	//delete[] readbuffer;
}


bool LEDController::staticColour(uint8_t index, Colour ^colour)
{
	return this->staticColour(index, colour->r, colour->g, colour->b);
}

bool LEDController::staticColour(uint8_t index, uint32_t colour)
{
	return this->staticColour(index, (colour >> 0) & 0xff, (colour >> 8) & 0xff, (colour >> 16) & 0xff);
}

bool LEDController::staticColour(uint8_t index, uint8_t red, uint8_t green, uint8_t blue)
{
	if (!this->serial->isOpen() || this->updating)
		return false;

	this->updating = true;

	uint8_t header = 2;
	uint16_t size = header + 3;
	uint8_t *buffer = new uint8_t[size];
	*(buffer + 0) = 'S';
	*(buffer + 1) = index;

	//printf("Setting all LEDs (%d) on %d to (%d, %d, %d)\n", this->numLeds, this->index, red, green, blue);
	unsigned char *ptr = buffer + header;

	setBufferColour(ptr, red, green, blue);

	this->serial->write(buffer, size);
	std::string readStr = "";

	readStr = this->readline();
	if (readStr.length() == 0)
		//MessageBox(NULL, CStringW(readStr.c_str()), L"UART Success", MB_OK);
	//else
		MessageBox(NULL, L"Nothing received", L"UART Fail", MB_OK);
	else if (readStr.front() != 'S')
		MessageBox(NULL, CStringW(readStr.c_str()), L"Incorrect response", MB_OK);
	//uart->WriteUart(buffer, size);
	
	delete[] buffer;

	this->updating = false;

	return true;
}

bool LEDController::waveColour(uint8_t index, uint16_t steps, uint8_t length, uint32_t colour1, uint32_t colour2)
{
	return this->waveColour(index, steps, length, (colour1 >> 16) & 0xff, (colour1 >> 8) & 0xff, colour1 & 0xff, (colour2 >> 16) & 0xff, (colour2 >> 8) & 0xff, colour2 & 0xff);
}

bool LEDController::waveColour(uint8_t index, uint16_t steps, uint8_t length, uint8_t red1, uint8_t green1, uint8_t blue1, uint8_t red2, uint8_t green2, uint8_t blue2)
{
	uint8_t header = 3;
	uint16_t size = header + 2 * 3 + 2;
	uint8_t *buffer = new uint8_t[size];

	*(buffer + 0) = 'W';
	*(buffer + 1) = index;
	*(buffer + 2) = length;


	printf("Setting all LEDs on %d to wave (%d, %d, %d)\n", index, red1, green1, blue1);
	uint8_t *ptr = buffer + header;

	setBufferColour(ptr, red1, green1, blue1);

	ptr += 3;
	setBufferColour(ptr, red2, green2, blue2);
	ptr += 3;
	
	*ptr++ = steps & 0xff;
	*ptr++ = (steps >> 8) & 0xff;

	this->serial->write(buffer, size);
	//uart->WriteUart(buffer, size);

	delete[] buffer;
	return true;
}

void setBufferColour(uint8_t * buffer, uint8_t r, uint8_t g, uint8_t b)
{
	*(buffer + 0) = r;
	*(buffer + 1) = g;
	*(buffer + 2) = b;
}

bool LEDController::breathingColour(uint8_t index, uint16_t steps, uint32_t colour1, uint32_t colour2)
{
	return this->breathingColour(index, steps, (colour1 >> 16) & 0xff, (colour1 >> 8) & 0xff, colour1 & 0xff, (colour2 >> 16) & 0xff, (colour2 >> 8) & 0xff, colour2 & 0xff);
}

bool LEDController::breathingColour(uint8_t index, uint16_t steps, uint8_t red1, uint8_t green1, uint8_t blue1, uint8_t red2, uint8_t green2, uint8_t blue2)
{
	uint8_t header = 2;
	uint16_t size = header + 2 * 3 + 2;
	uint8_t *buffer = new uint8_t[size];
	*(buffer + 0) = 'B';
	*(buffer + 1) = index;
	
	printf("Setting all LEDs on %d to breathe (%d, %d, %d)\n", index, red1, green1, blue1);
	unsigned char *ptr = buffer + header;

	setBufferColour(ptr, red1, green1, blue1);
	ptr += 3;
	setBufferColour(ptr, red2, green2, blue2);
	ptr += 3;
	*ptr++ = steps & 0xff;
	*ptr++ = (steps >> 8) & 0xff;

	this->serial->write(buffer, size);

	//uart->WriteUart(buffer, size);
	
	delete[] buffer;
	return true;
}