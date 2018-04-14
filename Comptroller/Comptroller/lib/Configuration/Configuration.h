#pragma once

#include <list>
#include "..\LED\LED.h"
#include "..\LED\WS2812_Definitions.h"
#include <atlstr.h>
#include "ConfigFile.h"

public ref class Config
{
private:
	ConfigFile *cfg;
public:
	bool debug;
	bool ledStrings, razer, asus, qmk, logitech;
	bool manualControl, tempControl;
	array<System::String ^> ^tempControlSources;
	int selectedTempControlSource;
	float minTemp, maxTemp; // scaled auto temp colours
	Colour ^minColour, ^maxColour;
	int ledCount;

	int selectedQMK;
	void extractConfig(ConfigFile *cfg);

public:
	Config();
	~Config();

	void saveConfig(void);

	void setComponents(bool ledStrings, bool asus, bool razer, bool logitech, bool qmk);
};