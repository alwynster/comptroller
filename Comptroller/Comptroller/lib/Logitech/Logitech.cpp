#include <stdio.h>
#include <tchar.h>
#include <vector>
//#include "Header.h"
#include <Windows.h>

#include "Logitech.h"

HMODULE lLib = nullptr;

Logitech::Logitech() {


	if (!LogiLedInit())
	{
		return;
	}
	m_targetDevice = LOGI_DEVICETYPE_ALL;
	LogiLedSetTargetDevice(m_targetDevice);

	/*lLib = LoadLibrary(L"LogitechLedEnginesWrapper.dll");


	if (lLib == nullptr) {

		printf("DLL not found\n");
		return;
	}*/

}

Logitech::~Logitech()
{
	//FreeLibrary(lLib);
}

void Logitech::StaticColour(Colour ^colour) {

	int redVal = colour->r / 255.0*100.0;
	int greenVal = colour->g / 255.0*100.0;
	int blueVal = colour->b / 255.0*100.0;

	LogiLedSetLighting(redVal, greenVal, blueVal);
}