#include "Configuration.h"

Config::Config()
{
	// load configuration from text here i guess
	cfg = new ConfigFile("config.cfg");
	this->extractConfig(cfg);

	tempControlSources = gcnew array<System::String^>(3);
	tempControlSources[0] = L"CPU";
	tempControlSources[1] = L"GPU";
	tempControlSources[2] = L"Motherboard";

	selectedTempControlSource = 0;

	// QMK variables
	selectedQMK = 1;
}

Config::~Config()
{

}

void Config::saveConfig()
{
	cfg->openWriteConfig();
	
	cfg->putBooleanConfig("debug", debug);

	cfg->putBooleanConfig("ledStrings", ledStrings);
	cfg->putBooleanConfig("razer", razer);
	cfg->putBooleanConfig("asus", asus);
	cfg->putBooleanConfig("qmk", qmk);
	cfg->putBooleanConfig("logitech", logitech);
	
	cfg->putBooleanConfig("manualControl", manualControl);
	cfg->putBooleanConfig("tempControl", tempControl);
	
	cfg->putColourConfig("minColour", minColour);
	cfg->putColourConfig("maxColour", maxColour);

	cfg->putIntConfig("minTemp", minTemp);
	cfg->putIntConfig("maxTemp", maxTemp);
}


void Config::extractConfig(ConfigFile *cfg)
{
	debug = cfg->getBooleanConfig("debug"); 

	ledStrings = cfg->getBooleanConfig("ledStrings");
	razer = cfg->getBooleanConfig("razer");
	asus = cfg->getBooleanConfig("asus");
	qmk = cfg->getBooleanConfig("qmk");
	logitech = cfg->getBooleanConfig("logitech");

	manualControl = cfg->getBooleanConfig("manualControl");
	tempControl = cfg->getBooleanConfig("tempControl");

	
	minColour = cfg->getColourConfig("minColour");
	maxColour = cfg->getColourConfig("maxColour");

	minTemp = cfg->getIntConfig("minTemp");
	maxTemp = cfg->getIntConfig("maxTemp");
}

void Config::setComponents(bool ledStrings, bool asus, bool razer, bool logitech, bool qmk)
{
	this->ledStrings = ledStrings;
	this->asus = asus;
	this->razer = razer;
	this->logitech = logitech;
	this->qmk = qmk;
}

