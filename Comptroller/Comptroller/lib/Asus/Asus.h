#pragma once

#include "../LED/LED.h"
#include "AURALightingSDK.h"

public ref class Asus
{
public:
	Asus();
	~Asus();

	void StaticColour(Colour ^colour);
	void AsusTest();
	void SetMoboColor();
};

