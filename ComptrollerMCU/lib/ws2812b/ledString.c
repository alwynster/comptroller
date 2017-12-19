#include "ledString.h"
#include "ws2812b.h"
#include <avr/io.h>
#include <stdlib.h>
#include <stdio.h>
#include <string.h>
#include "../uart/uart.h"

void initLedString(ledString *string, volatile uint8_t *ddr, volatile uint8_t *port, uint8_t pin, uint8_t numberLeds)
{
  string->buffer = NULL;
  
  string->ddr = ddr;
  string->port = port;
  string->pin = pin;

  // change these based on pin
  *string->ddr |= _BV(string->pin);
  *string->port &= ~_BV(string->pin);
  
  // if (string->buffer)
  //   free(string->buffer);

  updateNumLeds(string, numberLeds);
  
  showLeds(string);

  string->animating = NONE;
}

void updateNumLeds(ledString *string, uint8_t numberLeds)
{
  string->numLeds = numberLeds;

  if(string->buffer)
    free(string->buffer);

  string->buffer = (uint8_t *) malloc(string->numLeds * 3);
  memset(string->buffer, 0, 3 * string->numLeds);
}

void ledStatic(ledString *string, uint8_t red, uint8_t green, uint8_t blue)
{
  uint8_t *ptr = string->buffer;
  for (int i = 0; i < string->numLeds; i++)
  {
    *ptr++ = green;
    *ptr++ = red;
    *ptr++ = blue;
  }
  // memset(pixels, 255, numBytes);
  showLeds(string);
  string->animating = NONE;
}

void ledBreathe(ledString *string, uint8_t red1, uint8_t green1, uint8_t blue1, uint8_t red2, uint8_t green2, uint8_t blue2)
{
  uint8_t *ptr = string->buffer;
  for (int i = 0; i < string->numLeds; i++)
  {
    *ptr++ = green1;
    *ptr++ = red1;
    *ptr++ = blue1;
  }

  // save colour for animation
  string->colour[0] = green1;
  string->colour[1] = red1;
  string->colour[2] = blue1;

  // set up animations  
  string->animationVector[0] = ((float) green2 - (float) green1) / (float) string->animationSteps;
  string->animationVector[1] = ((float) red2 - (float) red1) / (float) string->animationSteps;
  string->animationVector[2] = ((float) blue2 - (float) blue1) / (float) string->animationSteps;
  
  string->animationIndex = 0;

  string->animating = FORWARD;

  // memset(pixels, 255, numBytes);
  showLeds(string);
}

void ledAnimate(ledString *string)
{
  // do nothing if string is not being animated
  if (string->animating == NONE)
    return;

  // find next colour
  uint8_t *ptr;

  // check if done with animation in either direction
  if ((string->animating == FORWARD) && (string->animationIndex == string->animationSteps))
  {
    uartWriteString("BACKWARD\n");
    string->animating = BACKWARD;
  }
  else if ((string->animating == BACKWARD) && (string->animationIndex == 0))
  {
    uartWriteString("FORWARD\n");
    string->animating = FORWARD;
  }

  // update animation
  if (string->animating == FORWARD)
    string->animationIndex++;
  else 
    string->animationIndex--;

  
  // set colours correctly
  for (int i = 0; i < 3; i++)
  {
    if (string->animating == FORWARD)
      string->colour[i] += string->animationVector[i];
    else
      string->colour[i] -= string->animationVector[i];
  }

  // write buffer for leds
  ptr = string->buffer;
  for (int j = 0; j < string->numLeds; j++)
  {
    for (int i = 0; i < 3; i++)
    { 
      *ptr++ = (uint8_t) string->colour[i];
    }
  }

  showLeds(string);
}