#pragma once

#include <stdint.h>
#include <Windows.h>

public ref class Colour
{
public:
	uint8_t r, g, b;

public:
	Colour();
	Colour(int colourCode);
	~Colour();

	void setColour(uint8_t r, uint8_t g, uint8_t b);
	int getColourCode();

	System::Drawing::Color getColour();

	void storeColour(uint8_t *destination);

	static Colour ^FromRGB(uint8_t r, uint8_t g, uint8_t b);
	static Colour ^FromInt(int colourCode);
	static Colour ^Interpolate(Colour ^colour1, Colour ^colour2, float balance);

	System::String ^toString();
};