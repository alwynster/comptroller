// ComptrollerConsole.cpp: Definiert den Einstiegspunkt für die Konsolenanwendung.
//

#include "StdAfx.h"

#include <stdio.h>
#include "lib\MSI Afterburner\MSIAfterBurnerPlugin.h"

#include "lib\Measurements\Measurements.h"

int main()
{
	printf("Test\n");

	printf("Starting MSI Afterburner plugin\n");

	//MSIAfterBurnerPlugin sensors; //  = MSIAfterBurnerPlugin::MSIAfterBurnerPlugin();
	//sensors.FetchReadings();

	Measurements measurements;
	measurements.Update();
	measurements.Print();

	printf("Enter to exit...\n");
	scanf_s("Enter");
    return 0;
}