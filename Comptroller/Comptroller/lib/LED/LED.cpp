#include "LED.h"

Colour::Colour()
{
	r = g = b = 0;
}

Colour::Colour(int colourCode)
{
	r = colourCode >> 16;
	g = colourCode >> 8;
	b = colourCode >> 0;
}

Colour::~Colour()
{

}

void Colour::setColour(uint8_t r, uint8_t g, uint8_t b)
{
	this->r = r;
	this->b = b;
	this->g = g;
}

int Colour::getColourCode()
{
	return (((uint8_t)(r) | ((uint16_t)((uint8_t)(g)) << 8)) | (((uint32_t)(uint8_t)(b)) << 16));
}

System::Drawing::Color Colour::getColour()
{
	return System::Drawing::Color::FromArgb(255, this->r, this->g, this->b);
}

void Colour::storeColour(uint8_t *destination)
{
	*(destination + 0) = r;
	*(destination + 1) = g;
	*(destination + 2) = b;
}

Colour ^ Colour::FromRGB(uint8_t r, uint8_t g, uint8_t b)
{
	Colour ^colour = gcnew Colour();
	colour->setColour(r, g, b);
	return colour;
}

Colour ^ Colour::FromInt(int colourCode)
{
	Colour ^colour = gcnew Colour(colourCode);
	return colour;
}

Colour ^ Colour::Interpolate(Colour ^colour1, Colour ^colour2, float balance)
{
	Colour ^result = gcnew Colour();
	result->r = (uint8_t)((float)colour1->r + balance * ((float)(colour2->r - colour1->r)));
	result->g = (uint8_t)((float)colour1->g + balance * ((float)(colour2->g - colour1->g)));
	result->b = (uint8_t)((float)colour1->b + balance * ((float)(colour2->b - colour1->b)));
	return result;
}

System::String ^Colour::toString()
{
	System::String ^str = L"";
	str += "(";
	str += this->r;
	str += ", ";
	str += this->g;
	str += ", ";
	str += this->b;
	str += ")";
	return str;
}
