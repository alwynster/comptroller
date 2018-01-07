#pragma once

#include <stdint.h>
#include "LED.h"

//#define NUM_LEDS 30
//#define BUFFER_SIZE (2 + NUM_LEDS * 3)

class LEDController
{
public:
	LEDController(uint8_t index, uint16_t numLeds);
	~LEDController();
	void setNumLeds(void);
	void staticColour(uint32_t colour);
	void staticColour(uint8_t red, uint8_t green, uint8_t blue);
	void breathingColour(uint16_t steps, uint32_t colour1, uint32_t colour2);
	void breathingColour(uint16_t steps, uint8_t red1, uint8_t green1, uint8_t blue1, uint8_t red2, uint8_t green2, uint8_t blue2);
	void waveColour(uint16_t steps, uint8_t length, uint32_t colour1, uint32_t colour2);
	void waveColour(uint16_t steps, uint8_t length, uint8_t red1, uint8_t green1, uint8_t blue1, uint8_t red2, uint8_t green2, uint8_t blue2);

protected:
	uint8_t numLeds, index;

	uint8_t *buffer;
	LED *leds;
	//LED leds[NUM_L EDS];
};