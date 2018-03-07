#include "Configuration.h"

Config::Config()
{
	// load configuration from text here i guess
	debug = true;

	ledStrings = true;
	razer = false;
	asus = false;
	logitech = false;

	manualControl = false;
	tempControl = true; 

	tempControlSources = gcnew array<System::String^>(3);
	tempControlSources[0] = L"CPU";
	tempControlSources[1] = L"GPU";
	tempControlSources[2] = L"Motherboard";

	selectedTempControlSource = 0;

	// scales temperature for scaling temp lights
	minTemp = 25;
	maxTemp = 65;

	minColour = Colour::FromInt(LIME);
	maxColour = Colour::FromInt(RED);
}

Config::~Config()
{

}

void Config::setComponents(bool ledStrings, bool asus, bool razer, bool logitech)
{
	this->ledStrings = ledStrings;
	this->asus = asus;
	this->razer = razer;
	this->logitech = logitech;
}