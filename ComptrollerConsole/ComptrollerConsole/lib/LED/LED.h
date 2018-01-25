#pragma once

#include <stdint.h>

class LED
{
protected:
	uint8_t r, g, b;

public:
	LED();
	~LED();

	void setColour(uint8_t r, uint8_t g, uint8_t b);

	void getColour(uint8_t *destination);	
};