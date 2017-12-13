#pragma once

#include <stdint.h>
#include "LED.h"

#define NUM_LEDS 30
#define BUFFER_SIZE (3 + NUM_LEDS * 3)

class LEDController
{
public:
	LEDController();
	~LEDController();
	void staticColour(uint8_t red, uint8_t green, uint8_t blue);

protected:
	uint8_t *buffer;
	LED leds[NUM_LEDS];
};