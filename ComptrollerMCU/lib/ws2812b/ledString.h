#ifndef _LED_STRING_H
#define _LED_STRING_H

#include <stdint.h>

typedef enum byteOrderTmp{RGB, GRB} byteOrder;
typedef struct {
	uint8_t numLeds;
	uint8_t index;
	uint8_t *buffer;
	volatile uint8_t *ddr;
	volatile uint8_t *port;
	uint8_t pin;
	byteOrder order;
} ledString;

void initLedString(ledString *string, volatile uint8_t *ddr, volatile uint8_t *port, uint8_t pin, uint8_t numberLeds);
void ledStatic(ledString *string, uint8_t red, uint8_t green, uint8_t blue);

#endif