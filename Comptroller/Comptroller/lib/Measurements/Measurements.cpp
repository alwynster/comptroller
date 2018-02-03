#include "Measurements.h"
#include "../MSI Afterburner/MSIAfterBurnerPlugin.h"
//#include "../AIDA/AIDA.h"

//MSIAfterBurnerPlugin afterburner;
//AIDA aida;

Measurements::Measurements()
{
	// connect to MSI Afterburner plugin
	//sensors = new MSIAfterBurnerPlugin();

 	motherboardTemperature = gpuTemp = gpuFanPwm = gpuUsage = gpuPower = gpuVoltage = gpuMemoryTemp = gpuMemoryClock = gpuMemoryPower = gpuMemory = gpuCore = gpuVrm = cpuTemp = cpuFan = cpuUsage = cpuPower = ramUsage = pageFileUsage = -1;

	gpuName = L"";
	time = L""; // CTime::CTime();
}


Measurements::~Measurements()
{
	time = L"";
}

void Measurements::Update()
{
	//afterburner.FetchReadings(this);
	//Print();
	//aida.FetchReadings(this);
}
