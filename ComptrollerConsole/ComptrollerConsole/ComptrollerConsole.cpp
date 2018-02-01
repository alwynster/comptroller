// ComptrollerConsole.cpp: Definiert den Einstiegspunkt für die Konsolenanwendung.
//

#include "StdAfx.h"

#include <stdio.h>
#include <wingdi.h>

#include "lib\Measurements\Measurements.h"
#include "lib\Razer\Razer.h"

int main()
{
	printf("Starting measurements plugin\n");

	Measurements measurements;
	measurements.Update();
	//measurements.Print();

	printf("Starting razer plugin\n");

	Razer razer;
	if (razer.HasRazer()) {

		razer.StaticColour(RGB(255, 255, 255));
	}


	printf("Enter to exit...\n");
	scanf_s("Enter");
    return 0;
}