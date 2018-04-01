#include "ledString.h"
#include "ws2812b.h"
#include <avr/io.h>
#include <stdlib.h>
#include <stdio.h>
#include <string.h>
#include <util/delay.h>

#include "../uart/uart.h"

void initLedString(ledString *string, uint8_t index, volatile uint8_t *ddr, volatile uint8_t *port, uint8_t pin)
{
  string->buffer = NULL;
  string->animationIndexes = NULL;
  string->animationDirections = NULL;
  
  string->index = index;

  string->ddr = ddr;
  string->port = port;
  string->pin = pin;

  // change these based on pin
  *string->ddr |= _BV(string->pin);
  *string->port &= ~_BV(string->pin);
  
  // if (string->buffer)
  //   free(string->buffer);

  // updateNumLeds(string, numberLeds);
  
  // showLeds(string);

  string->animating = NONE;
}

void updateNumLeds(ledString volatile *string, uint16_t numberLeds)
{
  string->numLeds = numberLeds;

  if(string->buffer)
  {
    // uartWriteLine("need to clear buffer");
    free(string->buffer);
  }
  // if(string->animationIndexes)
  //   free(string->animationIndexes);  
  // if(string->animationDirections)
  //   free(string->animationDirections);

  // string->animationIndexes = (uint16_t *) malloc(string->numLeds * sizeof(uint16_t));
  // string->animationDirections = (animationDirection *) malloc(string->numLeds * sizeof(animationDirection));
  string->buffer = (uint8_t *) malloc(string->numLeds * 3);
  memset(string->buffer, 0, 3 * string->numLeds);
}

void ledStatic(ledString volatile *string, uint8_t red, uint8_t green, uint8_t blue)
{
  uint8_t *ptr = string->buffer;
  for (uint16_t i = 0; i < string->numLeds; i++)
  {
    *ptr++ = green;
    *ptr++ = red;
    *ptr++ = blue;
  }
  // memset(pixels, 255, numBytes);
  showLeds(string);
  string->animation = NONE;
}

void ledWave(ledString *string, uint8_t red1, uint8_t green1, uint8_t blue1, uint8_t red2, uint8_t green2, uint8_t blue2)
{
  uint16_t *steps = (uint16_t *) malloc(string->animationLength * 2 * sizeof(uint16_t));
  uint16_t *stepsPtr = steps;
  // count up
  uint16_t increments = string->animationSteps / (string->animationLength - 1);
  uartNewLine();
  for (int i = 0; i < string->animationLength; i++)
  {
    *stepsPtr++ = i * increments;
  }
  for (int i = 0; i < string->animationLength; i++)
  {
    *stepsPtr++ = string->animationSteps - i * increments;
  }

  uartNewLine();
  // assign initial values for each led
  uint8_t *ptr = string->buffer;
  uint8_t index = 0; // counts to animationLength * 2
  for (int i = 0; i < string->numLeds; i++)
  {
    *ptr++ = green1;
    *ptr++ = red1;
    *ptr++ = blue1;

    if (index < string->animationLength)
      string->animationDirections[i] = FORWARD;
    else
      string->animationDirections[i] = BACKWARD;
    string->animationIndexes[i] = steps[index++];
    if (index > string->animationLength * 2 - 1) index = 0;

    uartWriteHex8(string->animationDirections[i]);
    uartWriteChar(' ');
    uartWriteDec16(string->animationIndexes[i]);
    uartNewLine();
  }
  free(steps);

  // save colour for animation
  string->colour[0] = green1;
  string->colour[1] = red1;
  string->colour[2] = blue1;

  // set up animations  
  string->animationVector[0] = ((float) green2 - (float) green1) / (float) string->animationSteps;
  string->animationVector[1] = ((float) red2 - (float) red1) / (float) string->animationSteps;
  string->animationVector[2] = ((float) blue2 - (float) blue1) / (float) string->animationSteps;
  
  // string->animationIndex = 0;

  string->animation = WAVE;

  // uint8_t *ptr = string->buffer;
  // uint8_t index = 0; // counts to animationLength and down again

  // float r_inc, g_inc, b_inc; // difference between neighbouring leds
  // g_inc = ((float) green2 - (float) green1) / (float) (string->animationLength - 1);
  // r_inc = ((float) red2 - (float) red1) / (float) (string->animationLength - 1);
  // b_inc = ((float) blue2 - (float) blue1) / (float) (string->animationLength - 1);

  // // precalculate each step in the fade
  // uint8_t *steps = (uint8_t *) malloc(3 * string->animationLength * 2); // rgb, up and down 
  // ptr = steps;

  // // increasing
  // for (float i = 0; i < string->animationLength; i++)
  // {
  //   *ptr++ = red1 + (uint8_t) (i * r_inc);
  //   *ptr++ = green1 + (uint8_t) (i * g_inc);
  //   *ptr++ = blue1 + (uint8_t) (i * b_inc);
  // }
  // // decreasing
  // for (int i = 0; i < string->animationLength; i++)
  // {
  //   *ptr++ = red1 + (uint8_t) ((string->animationLength - i - 1) * r_inc);
  //   *ptr++ = green1 + (uint8_t) ((string->animationLength - i - 1) * g_inc);
  //   *ptr++ = blue1 + (uint8_t) ((string->animationLength - i - 1) * b_inc);
  // }

  // // initial colours
  // ptr = string->buffer;
  // for (int i = 0; i < string->numLeds; i++)
  // {


  //   *ptr++ = steps[3 * index + 1];
  //   *ptr++ = steps[3 * index + 0];
  //   *ptr++ = steps[3 * index + 2];

  //   // update index
  //   if (index < 2 * string->animationLength - 1)
  //     index++;
  //   else
  //     index = 0;
  // }
  // free(steps);

  // // save colour for animation
  // string->colour[0] = green1;
  // string->colour[1] = red1;
  // string->colour[2] = blue1;

  // // set up animations  
  // string->animationVector[0] = ((float) green2 - (float) green1) / (float) string->animationSteps;
  // string->animationVector[1] = ((float) red2 - (float) red1) / (float) string->animationSteps;
  // string->animationVector[2] = ((float) blue2 - (float) blue1) / (float) string->animationSteps;
  
  // // string->animationIndex = 0;

  // string->animating = FORWARD;

  // memset(pixels, 255, numBytes);
  showLeds(string);
}

void ledBreathe(ledString *string, uint8_t red1, uint8_t green1, uint8_t blue1, uint8_t red2, uint8_t green2, uint8_t blue2)
{
  uint8_t *ptr = string->buffer;
  for (int i = 0; i < string->numLeds; i++)
  {
    *ptr++ = green1;
    *ptr++ = red1;
    *ptr++ = blue1;

    string->animationDirections[i] = FORWARD;
    string->animationIndexes[i] = 0;
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

  string->animation = BREATHE;

  // memset(pixels, 255, numBytes);
  showLeds(string);
}

void ledAnimate(ledString *string)
{
  // do nothing if string is not being animated
  if (string->animation == NONE)
    return;

  // find next colour
  uint8_t *ptr;
  ptr = string->buffer;

  // // check if done with animation in either direction
  // if ((string->animating == FORWARD) && (string->animationIndex == string->animationSteps))
  // {
  //   uartWriteString("BACKWARD\n");
  //   string->animating = BACKWARD;
  // }
  // else if ((string->animating == BACKWARD) && (string->animationIndex == 0))
  // {
  //   uartWriteString("FORWARD\n");
  //   string->animating = FORWARD;
  // }

  // // update animation
  // if (string->animating == FORWARD)
  //   string->animationIndex++;
  // else 
  //   string->animationIndex--;

  // set colours correctly
  for (int i = 0; i < string->numLeds; i++)
  {
    // check if done with animation in either direction
    if ((string->animationDirections[i] == FORWARD) && (string->animationIndexes[i] == string->animationSteps))
    {
      // uartWriteString("BACKWARD\n");
      string->animationDirections[i] = BACKWARD;
    }
    else if ((string->animationDirections[i] == BACKWARD) && (string->animationIndexes[i] == 0))
    {
      // uartWriteString("FORWARD\n");
      string->animationDirections[i] = FORWARD;
    }

    // update animation
    if (string->animationDirections[i] == FORWARD)
      string->animationIndexes[i]++;
    else 
      string->animationIndexes[i]--;

    *ptr++ = string->colour[0] + ((uint8_t) (string->animationVector[0] * (float) string->animationIndexes[i]));
    *ptr++ = string->colour[1] + ((uint8_t) (string->animationVector[1] * (float) string->animationIndexes[i]));
    *ptr++ = string->colour[2] + ((uint8_t) (string->animationVector[2] * (float) string->animationIndexes[i]));
  }

  // for (int i = 0; i < 3; i++)
  // {
  //   if (string->animating == FORWARD)
  //     string->colour[i] += string->animationVector[i];
  //   else
  //     string->colour[i] -= string->animationVector[i];
  // }

  // // write buffer for leds
  // ptr = string->buffer;
  // for (int j = 0; j < string->numLeds; j++)
  // {
  //   for (int i = 0; i < 3; i++)
  //   { 
  //     *ptr++ = (uint8_t) string->colour[i];
  //   }
  // }

  showLeds(string);
}

// https://www.rapidtables.com/convert/color/hsv-to-rgb.html
void ledRainbow(ledString volatile *string, animationDirection direction, uint16_t animationDelay)
{
	// rainbow uses hsv for easier transition
	float C, X, S, V, m;

	S = 1.0f; // saturation
	V = 0.1f; // intensity

	for (int i = 0; i < 50; i++)
	{
		for (float H = 0; H < 360; H += 1.0f)
		{
			C = S * V;
			X = C * (1 - fabsf(fmodf((H / 60.0f), 2.0f) - 1.0f));
			m = V - C;

			float r, g, b;

			if (H >= 0 && H < 60)
			{
				r = C;
				g = X;
				b = 0;
			}
			else if (H >= 60 && H < 120)
			{
				r = X;
				g = C;
				b = 0;
			}
			else if (H >= 0 && H < 180)
			{
				r = 0;
				g = C;
				b = X;
			}
			else if (H >= 0 && H < 240)
			{
				r = 0;
				g = X;
				b = C;
			}
			else if (H >= 0 && H < 300)
			{
				r = X;
				g = 0;
				b = C;
			}
			else // if (H >= 0 && H < 360)
			{
				r = C;
				g = 0;
				b = X;
			}

			// ignore adding m because it's 0

			uint8_t *ptr = string->buffer;
			for (uint16_t i = 0; i < string->numLeds; i++)
			{
				*ptr++ = (uint8_t)((g + m) * 255);
				*ptr++ = (uint8_t)((r + m) * 255);
				*ptr++ = (uint8_t)((b + m) * 255);
			}
			// memset(pixels, 255, numBytes);
			showLeds(string);

			_delay_ms(10);
		}
	}
	string->animation = RAINBOW;
}