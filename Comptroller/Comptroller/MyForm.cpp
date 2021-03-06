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

	if (!form.ledString->serial->isOpen())
		form.config->ledStrings = false;
	else
		form.setLedStringsConnected(true);

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

System::Void Comptroller::MyForm::whiteButton_Click(System::Object ^ sender, System::EventArgs ^ e)
{
	staticColour(Colour::FromInt(WHITE));
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
		//ledString1->staticColour(colour);
		if (!ledString->staticColour(2, colour))
			this->setLedStringsConnected(false);
	}
	if (config->asus)
	{
		asus->StaticColour(colour);

	}
	if (config->qmk)
	{
		qmk->staticColour(colour);
	}
	if (config->logitech)
	{
		logitech->StaticColour(colour);
	}

	//updateTimer->Enabled = 1;
}

void Comptroller::MyForm::updateColourBars(Colour ^ colour)
{
	// don't update colour every time the colour bars change
	this->ignoreBarChange = true;

	this->redBar->Value = colour->r;
	this->greenBar->Value = colour->g;
	this->blueBar->Value = colour->b;

	this->ignoreBarChange = false;
}

System::Void Comptroller::MyForm::colourBar_ValueChanged(System::Object^  sender, System::EventArgs^  e)
{
	if (this->ignoreBarChange)
		return;

	uint8_t r, g, b;
	r = (uint8_t) this->redBar->Value;
	g = (uint8_t) this->greenBar->Value;
	b = (uint8_t) this->blueBar->Value;

	this->staticColour(Colour::FromRGB(r, g, b));
}

void Comptroller::MyForm::setLedStringsConnected(bool connected)
{
	this->ledStringConnected->Checked = connected;
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
	this->logitechCheckBox->Checked = config->logitech;

	this->guiInitialised = true;
}

// gui to active
void Comptroller::MyForm::updateComponents()
{
	if (!guiInitialised || !appInitialised) return;

	//this->config->setComponents(this->ledStringsCheckBox->Checked, this->asusCheckBox->Checked, this->razerCheckBox->Checked);
	this->config->setComponents(this->ledStringsCheckBox->Checked, this->asusCheckBox->Checked, this->razerCheckBox->Checked, this->logitechCheckBox->Checked, this->qmkCheckBox->Checked);

	if (this->config->ledStrings)
		if (ledString == nullptr)
		{
			this->initLedString();
		}
	if (this->config->razer)
		if (razer == nullptr)
			razer = gcnew Razer();
	if (this->config->asus)
		if (asus == nullptr)
			asus = gcnew Asus();
	if (this->config->qmk)
		if (qmk == nullptr)
		{
			qmk = gcnew QMK();
			this->initQMK();
		}

	if (this->config->logitech)
		if (logitech == nullptr)
			logitech = gcnew Logitech();
};

System::Void Comptroller::MyForm::tempControlUpdate(System::Object^  sender, System::EventArgs^  e)
{
	this->updateTempControl();
	//this->tempControlList->Items = 
}

// config to gui/active
void Comptroller::MyForm::initQMK()
{
	this->qmk->FindMidiPorts();

	this->qmkCheckBox->Checked = this->config->qmk;
	this->qmkList->Enabled = this->config->qmk;

	this->qmkList->Items->Clear();
	for (int i = 0; i < this->qmk->midiports->Length; i++)
	{
		if (this->qmk->midiports[i] != nullptr)
		{
			this->qmkList->Items->Add(this->qmk->midiports[i]);
		}
	}
	if (this->qmkList->Items->Count > 0)
	{
		this->qmkList->SelectedIndex = this->config->selectedQMK;

		this->qmk->Connect(this->qmkList->SelectedIndex);
	}
	//this->tempControlInitialised = true;
}

void Comptroller::MyForm::initTempControl()
{
	this->manualControlBox->Checked = this->config->manualControl;

	this->tempControlCheckBox->Checked = this->config->tempControl;
	this->tempControlList->Enabled = this->config->tempControl;

	this->tempControlList->Items->Clear();
	for (int i = 0; i < this->config->tempControlSources->Length; i++)
	{
		this->tempControlList->Items->Add(this->config->tempControlSources[i]);
	}
	this->tempControlList->SelectedIndex = this->config->selectedTempControlSource;
}

// gui to active/config
void Comptroller::MyForm::updateTempControl()
{
	// do not update before initialised
	if (!this->guiInitialised)
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
	
	bool temp = this->tempControlCheckBox->Checked;
	this->config->tempControl = temp;
	this->config->selectedTempControlSource = this->tempControlList->SelectedIndex;
	this->tempControlList->Enabled = temp;
	updateTimer->Enabled = this->config->tempControl;
}

System::Void Comptroller::MyForm::updateTimer_Tick(System::Object^  sender, System::EventArgs^  e)
{
	// update measurements
	this->msi->FetchReadings();
	this->debug();

	float currentTemp = -1;
	if (this->config->tempControl) {
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

	//if (this->config->manualControl) {

	//	uint8_t r, g, b;
	//	r = (uint8_t)this->redBar->Value;
	//	g = (uint8_t)this->greenBar->Value;
	//	b = (uint8_t)this->blueBar->Value;

	//	this->staticColour(Colour::FromRGB(r, g, b));
	//}

}
