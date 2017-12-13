// ComptrollerConsole.cpp: Definiert den Einstiegspunkt für die Konsolenanwendung.
//

#include "StdAfx.h"

#include <stdio.h>
#include "lib\MSI Afterburner\MSIAfterBurnerPlugin.h"
#include "lib\UART\UART.h"

#include "lib\Measurements\Measurements.h"
#include "lib\LED\LED.h"
#include "lib\LED\LEDController.h"

int main()
{
	printf("Test\n");

	printf("Starting MSI Afterburner plugin\n");

	//MSIAfterBurnerPlugin sensors; //  = MSIAfterBurnerPlugin::MSIAfterBurnerPlugin();
	//sensors.FetchReadings();

	Measurements measurements;
	measurements.Update();
	measurements.Print();

	LEDController ledc;
	ledc.staticColour(50,50,50);

	printf("Enter to exit...\n");
	scanf_s("Enter");

	CloseUart();

    return 0;
}