#pragma once
#pragma comment(lib, "LogitechLEDLib.lib")

#include "../LED/LED.h"
#include "LogitechLEDLib.h"

public ref class Logitech
{
public:
	Logitech();
	~Logitech();

	void StaticColour(Colour ^colour);

private:
	int m_targetDevice;
};

