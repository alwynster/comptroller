#pragma once

#include <stdint.h>
#include "LED.h"

//#define NUM_LEDS 30
//#define BUFFER_SIZE (2 + NUM_LEDS * 3)

class LEDController
{
public:
	LEDController(uint8_t index, uint8_t numLeds);
	~LEDController();
	void staticColour(uint32_t colour);
	void staticColour(uint8_t red, uint8_t green, uint8_t blue);

protected:
	uint8_t numLeds, index;

	uint8_t *buffer;
	LED *leds;
	//LED leds[NUM_L EDS];
};