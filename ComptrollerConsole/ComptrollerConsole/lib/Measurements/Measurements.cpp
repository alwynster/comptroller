#include "Measurements.h"
#include "../MSI Afterburner/MSIAfterBurnerPlugin.h"
#include "../AIDA/AIDA.h"

MSIAfterBurnerPlugin afterburner;
AIDA aida;

Measurements::Measurements()
{
	// connect to MSI Afterburner plugin
	//sensors = new MSIAfterBurnerPlugin();

 	motherboardTemperature = gpuTemp = gpuFanPwm = gpuUsage = gpuPower = gpuVoltage = gpuMemoryTemp = gpuMemoryClock = gpuMemoryPower = gpuMemory = gpuCore = gpuVrm = cpuTemp = cpuFan = cpuUsage = cpuPower = ramUsage = pageFileUsage = -1;

	gpuName = "";
	time = CTime::CTime();
}


Measurements::~Measurements()
{
	time = NULL;
}

void Measurements::Update()
{
	afterburner.FetchReadings(this);
	//Print();
	aida.FetchReadings(this);
}

void Measurements::Print()
{
	printf("Measurements: (");
	printf(time.Format("%d-%m-%Y %H:%M:%S"));
	printf(")\n\n");
	printf("GPU Name:\t\t");
	printf(gpuName);
	printf("\nGPU Temp:\t\t%.2f", gpuTemp);
	printf("\nGPU Fan Duty:\t\t%.2f", gpuFanPwm);
	printf("\nGPU Mem:\t\t%.2f", gpuMemory);
	printf("\nGPU Mem Power:\t\t%.2f", gpuMemoryPower);
	printf("\nGPU Mem Temp:\t\t%.2f", gpuMemoryTemp);
	printf("\nGPU Mem Clock:\t\t%.2f", gpuMemoryClock);
	printf("\nGPU Core Clock:\t\t%.2f", gpuCore);
	printf("\nGPU Usage:\t\t%.2f", gpuUsage);
	printf("\nGPU Power:\t\t%.2f", gpuPower);
	printf("\nGPU VRM:\t\t%.2f", gpuVrm);
	printf("\nCPU Temp:\t\t%.2f", cpuTemp);
	printf("\nCPU Usage:\t\t%.2f", cpuUsage);
	printf("\nCPU Fan:\t\t%.2f", cpuFan);
	printf("\nCPU Power:\t\t%.2f", cpuPower);
	printf("\nRAM Usage:\t\t%.2f", ramUsage);
	printf("\nPF Usage:\t\t%.2f", pageFileUsage);
	printf("\nMotherboard Temp:\t%.2f", motherboardTemperature);

	printf("\n\n");

}