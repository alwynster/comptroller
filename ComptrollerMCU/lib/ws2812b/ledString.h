#ifndef _LED_STRING_H
#define _LED_STRING_H

#include <stdint.h>

// #define ANIMATION_STEPS 1000

typedef enum byteOrderTmp{RGB, GRB} byteOrder;
typedef enum animationTmp{NONE, FORWARD, BACKWARD} animationDirection;
typedef struct {
	uint8_t numLeds;
	uint8_t index;
	uint8_t *buffer; // change buffer to list of LED uint24_t
	volatile uint8_t *ddr;
	volatile uint8_t *port;
	uint8_t pin;
	byteOrder order;

	float animationVector[3];
	float colour[3];
	uint16_t animationIndex;
	uint16_t animationSteps;
	animationDirection animating;
} ledString;

void initLedString(ledString *string, volatile uint8_t *ddr, volatile uint8_t *port, uint8_t pin, uint8_t numberLeds);
void updateNumLeds(ledString *string, uint8_t numberLeds);
void ledStatic(ledString *string, uint8_t red, uint8_t green, uint8_t blue);
void ledBreathe(ledString *string, uint8_t red1, uint8_t green1, uint8_t blue1, uint8_t red2, uint8_t green2, uint8_t blue2);
void ledAnimate(ledString *string);
#endif