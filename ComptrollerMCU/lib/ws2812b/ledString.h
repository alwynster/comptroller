#ifndef _LED_STRING_H
#define _LED_STRING_H

#include <stdint.h>

// #define ANIMATION_STEPS 1000

typedef enum byteOrderTmp{RGB, GRB} byteOrder;
typedef enum animationTmp{FORWARD, BACKWARD} animationDirection;
typedef enum animationTypeTmp{NONE, BREATHE, WAVE} animationType;
typedef struct {
	uint16_t numLeds;
	uint8_t index;
	uint8_t *buffer; // change buffer to list of LED uint24_t
	volatile uint8_t *ddr;
	volatile uint8_t *port;
	uint8_t pin;
	byteOrder order;

	float animationVector[3];
	float colour[3];
	uint16_t animationIndex;
	uint16_t *animationIndexes; // the index for each led
	animationDirection *animationDirections;
	uint16_t animationSteps;
	uint8_t animationLength;
	animationDirection animating;
	animationType animation;
} ledString;

void initLedString(ledString *string, volatile uint8_t *ddr, volatile uint8_t *port, uint8_t pin);
void updateNumLeds(ledString *string, uint16_t numberLeds);
void ledStatic(ledString *string, uint8_t red, uint8_t green, uint8_t blue);
void ledWave(ledString *string, uint8_t red1, uint8_t green1, uint8_t blue1, uint8_t red2, uint8_t green2, uint8_t blue2);
void ledBreathe(ledString *string, uint8_t red1, uint8_t green1, uint8_t blue1, uint8_t red2, uint8_t green2, uint8_t blue2);
void ledAnimate(ledString *string);
#endif