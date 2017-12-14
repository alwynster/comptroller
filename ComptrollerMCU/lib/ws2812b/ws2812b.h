#ifndef _ws2812b_h
#define _ws2812b_h

#include <stdint.h>
#include "ledString.h"

void changeNumLeds(uint16_t numLeds);
void showLeds(ledString *leds);

#endif