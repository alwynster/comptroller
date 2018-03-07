#pragma once

#include <list>
#include "..\LED\LED.h"
#include "..\LED\WS2812_Definitions.h"

public ref class Config
{
public:
	bool debug;
	bool ledStrings, razer, asus, qmk, logitech;
	bool manualControl, tempControl;
	array<System::String ^> ^tempControlSources;
	int selectedTempControlSource;
	float minTemp, maxTemp;
	Colour ^minColour, ^maxColour;
	int ledCount;

	int selectedQMK;

public:
	Config();
	~Config();

	void setComponents(bool ledStrings, bool asus, bool razer, bool logitech);
};
