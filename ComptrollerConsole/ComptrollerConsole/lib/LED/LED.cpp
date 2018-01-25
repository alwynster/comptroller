#include "LED.h"

LED::LED()
{
	r = g = b = 0;
}

LED::~LED()
{

}

void LED::setColour(uint8_t r, uint8_t g, uint8_t b)
{
	this->r = r;
	this->b = b;
	this->g = g;
}

void LED::getColour(uint8_t *destination)
{
	*(destination + 0) = r;
	*(destination + 1) = g;
	*(destination + 2) = b;
}
