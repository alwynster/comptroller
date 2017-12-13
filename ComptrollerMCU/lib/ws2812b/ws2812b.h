#ifndef _ws2812b_h
#define _ws2812b_h

#include <stdint.h>

void initLedString(void);
void ledStatic(uint8_t red, uint8_t green, uint8_t blue);
void changeNumLeds(uint16_t numLeds);

#endif