#include "MyForm.h"
#include <stdio.h>
//#include <wingdi.h>

using namespace System;
using namespace System::Windows::Forms;


[STAThread]
void Main(array<String^>^ args) {

	printf("Test\n");

	printf("Starting MSI Afterburner plugin\n");

	////MSIAfterBurnerPlugin sensors; //  = MSIAfterBurnerPlugin::MSIAfterBurnerPlugin();
	////sensors.FetchReadings();

	//measurements.Update();
	//measurements.Print();

	
	//printf("Starting razer plugin\n");

	//if (razer.HasRazer()) {
	//	razer.StaticColour(RGB(255, 255, 255));
	//}

	////scanf_s("Enter");

	////return 0;

	Application::EnableVisualStyles();
	Application::SetCompatibleTextRenderingDefault(false);
	Comptroller::MyForm form;

	SetupUart();
	form.ledString3 = gcnew LEDController(2, 2);

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

	//printf("Enter to exit...\n");


	//form.ledString3->staticColour(RED);


	Application::Run(%form);


	//// turn off all leds before closing
}

void Comptroller::MyForm::debug()
{
	this->msi = gcnew MSIAfterBurnerPlugin();
	this->msi->FetchReadings();

	System::String ^measurementString = this->msi->Print();

	this->debugBox->Text = measurementString;
}

System::Void Comptroller::MyForm::measureButton_Click(System::Object^  sender, System::EventArgs^  e){
	this->debug();
}

System::Void Comptroller::MyForm::redButton_Click(System::Object ^ sender, System::EventArgs ^ e)
{
	staticColour(RED);
}

System::Void Comptroller::MyForm::greenButton_Click(System::Object ^ sender, System::EventArgs ^ e)
{
	staticColour(GREEN);
}

System::Void Comptroller::MyForm::blueButton_Click(System::Object ^ sender, System::EventArgs ^ e)
{
	staticColour(BLUE);
}

void Comptroller::MyForm::staticColour(unsigned long colour)
{
	if (razer->HasRazer()) {
		unsigned long convertedColour = colour >> 16;
		convertedColour |= (0xff & colour) << 16;
		convertedColour |= (0xff00 & colour);
		razer->StaticColour(convertedColour);
	}
	ledString3->staticColour(colour);
}