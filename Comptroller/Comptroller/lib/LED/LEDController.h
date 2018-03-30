#pragma once

#include <stdint.h>
#include "LED.h"
#include "serial/serial.h"
#include <list>

//#include "../UART/UART.h"
//#define NUM_LEDS 30
//#define BUFFER_SIZE (2 + NUM_LEDS * 3)

public ref class LEDController
{
public:
	LEDController(std::list<uint16_t> numLeds); //  uint8_t index, uint16_t numLeds);
	~LEDController();
	void setNumLeds(uint8_t index, uint16_t numLeds);
	bool staticColour(uint8_t index, Colour ^colour);
	bool staticColour(uint8_t index, uint32_t colour);
	bool staticColour(uint8_t index, uint8_t red, uint8_t green, uint8_t blue);
	bool breathingColour(uint8_t index, uint16_t steps, uint32_t colour1, uint32_t colour2);
	bool breathingColour(uint8_t index, uint16_t steps, uint8_t red1, uint8_t green1, uint8_t blue1, uint8_t red2, uint8_t green2, uint8_t blue2);
	bool waveColour(uint8_t index, uint16_t steps, uint8_t length, uint32_t colour1, uint32_t colour2);
	bool waveColour(uint8_t index, uint16_t steps, uint8_t length, uint8_t red1, uint8_t green1, uint8_t blue1, uint8_t red2, uint8_t green2, uint8_t blue2);
	void blackout(void);

protected:
	//uint8_t numLeds, index;

	//uint8_t *buffer;
	Colour ^leds;
	uint8_t numLedStrings;

//private:
	//public: Uart ^ uart;
private:
	std::string readline(void);

private:
	bool updating;
public:
	serial::Serial *serial;

	//void clearBuffer(void);

	//LED leds[NUM_L EDS];
};