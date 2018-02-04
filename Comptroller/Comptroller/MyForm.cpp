#include "MyForm.h"
#include <stdio.h>
//#include <wingdi.h>

using namespace System;
using namespace System::Windows::Forms;


[STAThread]
void Main(array<String^>^ args) {

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
	form.ledString1 = gcnew LEDController(0, 6);
	form.ledString3 = gcnew LEDController(2, 2);


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
	this->msi->FetchReadings();

	if (config->debug)
	{
		System::String ^measurementString = this->msi->Print();
		this->debugBox->Text = measurementString;
	}
}

System::Void Comptroller::MyForm::measureButton_Click(System::Object^  sender, System::EventArgs^  e){
	this->debug();
}

System::Void Comptroller::MyForm::redButton_Click(System::Object ^ sender, System::EventArgs ^ e)
{
	staticColour(Colour::FromInt(RED));
}

System::Void Comptroller::MyForm::greenButton_Click(System::Object ^ sender, System::EventArgs ^ e)
{
	staticColour(Colour::FromInt(LIME));
}

System::Void Comptroller::MyForm::blueButton_Click(System::Object ^ sender, System::EventArgs ^ e)
{
	staticColour(Colour::FromInt(BLUE));
}

void Comptroller::MyForm::staticColour(Colour ^colour)
{
	this->updateColourBars(colour);

	this->colourPanel->BackColor = colour->getColour();
	
	if (config->razer)
	{
		if (razer->HasRazer()) {
			/*unsigned long convertedColour = colour >> 16;
			convertedColour |= (0xff & colour) << 16;
			convertedColour |= (0xff00 & colour);*/
			razer->StaticColour(colour->getColourCode());
		}
	}
	if (config->ledStrings)
	{
		ledString1->staticColour(colour);
		ledString3->staticColour(colour);
	}
}

void Comptroller::MyForm::updateColourBars(Colour ^ colour)
{
	this->redBar->Value = colour->r;
	this->greenBar->Value = colour->g;
	this->blueBar->Value = colour->b;
}

System::Void Comptroller::MyForm::colourBar_ValueChanged(System::Object^  sender, System::EventArgs^  e)
{
	uint8_t r, g, b;
	r = (uint8_t) this->redBar->Value;
	g = (uint8_t) this->greenBar->Value;
	b = (uint8_t) this->blueBar->Value;

	this->staticColour(Colour::FromRGB(r, g, b));
}

System::Void Comptroller::MyForm::componentCheckBox_CheckedChanged(System::Object ^ sender, System::EventArgs ^ e)
{
	this->updateComponents();
}

// config to gui
void Comptroller::MyForm::initComponents()
{
	this->ledStringsCheckBox->Checked = config->ledStrings;
	this->asusCheckBox->Checked = config->asus;
	this->razerCheckBox->Checked = config->razer;
}

// gui to active
void Comptroller::MyForm::updateComponents()
{
	this->config->setComponents(this->ledStringsCheckBox->Checked, this->asusCheckBox->Checked, this->razerCheckBox->Checked);

	if (this->config->ledStrings)
		if (ledString3 == nullptr)
			ledString3 = gcnew LEDController(2, 2);
	if (this->config->razer)
		if (razer == nullptr)
			razer = gcnew Razer();
}

System::Void Comptroller::MyForm::tempControlUpdate(System::Object^  sender, System::EventArgs^  e)
{
	this->updateTempControl();
	//this->tempControlList->Items = 
}

void Comptroller::MyForm::initTempControl()
{
	this->tempControlCheckBox->Checked = this->config->tempControl;
	this->tempControlList->Enabled = this->config->tempControl;

	this->tempControlList->Items->Clear();
	for (int i = 0; i < this->config->tempControlSources->Length; i++)
	{
		this->tempControlList->Items->Add(this->config->tempControlSources[i]);
	}
	this->tempControlList->SelectedIndex = this->config->selectedTempControlSource;
	this->tempControlInitialised = true;
}

// gui to active/config
void Comptroller::MyForm::updateTempControl()
{
	// do not update before initialised
	if (!this->tempControlInitialised)
		return;

	bool manual = this->manualControlBox->Checked;
	this->config->manualControl = manual;
	this->redBar->Enabled = manual;
	this->blueBar->Enabled = manual;
	this->greenBar->Enabled = manual;

	this->redButton->Enabled = manual;
	this->greenButton->Enabled = manual;
	this->blueButton->Enabled = manual;

	// manual overwrites tempcontrol
	if (manual)
		this->tempControlCheckBox->Checked = false;
	
	this->config->tempControl = this->tempControlCheckBox->Checked;
	this->config->selectedTempControlSource = this->tempControlList->SelectedIndex;
	updateTimer->Enabled = this->config->tempControl;
}

System::Void Comptroller::MyForm::updateTimer_Tick(System::Object^  sender, System::EventArgs^  e)
{
	// update measurements
	this->msi->FetchReadings();
	this->debug();
	
	float currentTemp = -1;
	switch (this->config->selectedTempControlSource)
	{
	//cpu
	case 0:
		currentTemp = this->msi->measurements->cpuTemp;
		break;
	// gpu
	case 1:
		currentTemp = this->msi->measurements->gpuTemp;
		break;
	// mobo
	case 2:
		currentTemp = this->msi->measurements->motherboardTemperature;
		break;
	default:
		currentTemp = -1;
		break;
	}

	// error with reading temp
	if (currentTemp == -1)
		return;

	if (config->debug)
	{
		this->debugBox->Text += L"Current Temp: ";
		this->debugBox->Text += (currentTemp);
	}

	float balance;
	// first catch extremes
	if (currentTemp < this->config->minTemp)
		balance = 0;
	else if (currentTemp > this->config->maxTemp)
		balance = 1;
	else
		balance = (currentTemp - this->config->minTemp) / ((float)this->config->maxTemp - this->config->minTemp);

	Colour ^currentColour = Colour::Interpolate(this->config->minColour, this->config->maxColour, balance);
	this->staticColour(currentColour);

}
