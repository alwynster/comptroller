// ComptrollerConsole.cpp: Definiert den Einstiegspunkt für die Konsolenanwendung.
//

#include "StdAfx.h"

#include <stdio.h>
#include <wingdi.h>

#include "lib\MSI Afterburner\MSIAfterBurnerPlugin.h"
#include "lib\Razer\Razer.h"
#include "lib\UART\UART.h"

#include "lib\Measurements\Measurements.h"
#include "lib\LED\LED.h"
#include "lib\LED\LEDController.h"
#include "lib\LED\WS2812_Definitions.h"

#include "lib\Asus\Asus.h"

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

	LEDController ledString3 = LEDController(2, 2);

	//ledString1 = LEDController(0, 6);

	//LEDController ledString2 = LEDController(1, 5);
	//LEDController ledString3 = LEDController(2, 1);
	//ledString1.breathingColour(1000, BLUE, RED);
	//ledString2.breathingColour(1000, RED, BLACK);
	//ledString3.breathingColour(10000, MAGENTA, GREEN);
	//ledString1.staticColour(RED);
	//ledString2.staticColour(BLACK);
	//ledString3.staticColour(GREEN);

	//ledString1.waveColour(1000, 3, GREEN, ORANGE);

	printf("Enter to exit...\n");


	ledString3.staticColour(BLUE);


	printf("Starting razer plugin\n");

	int red, green, blue;
	red = 0;
	green = 0;
	blue = 255;

	Razer razer;
	if (razer.HasRazer()) {
		razer.StaticColour(RGB(red, green, blue));
	}

	printf("Starting ASUS plugin\n");
	Asus asus;

	BYTE color[3];
	color[0] = char(red);
	color[1] = char(green);
	color[2] = char(blue);

	asus.StaticColour(&color[0]);

	scanf_s("Enter");


	// turn off all leds before closing
	ledString3.staticColour(BLACK);
	CloseUart();

	return 0;
}