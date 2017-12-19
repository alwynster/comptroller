// ComptrollerConsole.cpp: Definiert den Einstiegspunkt für die Konsolenanwendung.
//

#include "StdAfx.h"

#include <stdio.h>
#include "lib\MSI Afterburner\MSIAfterBurnerPlugin.h"
#include "lib\UART\UART.h"

#include "lib\Measurements\Measurements.h"
#include "lib\LED\LED.h"
#include "lib\LED\LEDController.h"
#include "lib\LED\WS2812_Definitions.h"

int main()
{
	printf("Test\n");

	printf("Starting MSI Afterburner plugin\n");

	//MSIAfterBurnerPlugin sensors; //  = MSIAfterBurnerPlugin::MSIAfterBurnerPlugin();
	//sensors.FetchReadings();

	Measurements measurements;
	measurements.Update();
	measurements.Print();

	SetupUart();

	LEDController ledString1 = LEDController(0, 5);
	LEDController ledString2 = LEDController(1, 5);
	LEDController ledString3 = LEDController(2, 1);
	//ledString1.breathingColour(1000, MAGENTA, BLACK);
	//ledString2.breathingColour(1000, RED, BLACK);
	//ledString3.breathingColour(10000, MAGENTA, GREEN);
	ledString1.staticColour(BLACK);
	ledString2.staticColour(BLACK);
	ledString3.staticColour(BLACK);

	printf("Enter to exit...\n");
	scanf_s("Enter");

	CloseUart();

    return 0;
}