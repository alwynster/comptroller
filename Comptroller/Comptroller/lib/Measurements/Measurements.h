#pragma once

//#include "../../StdAfx.h"
//#include "../MSI Afterburner/MSIAfterBurnerPlugin.h"

//#include <atlstr.h>  
//#include <atltime.h>

ref class Measurements
{
public:
	Measurements();
	~Measurements();

	void Update();

// members
public:
	System::String ^gpuName;
	float gpuTemp;
	float gpuFanPwm;
	float gpuUsage;
	float gpuPower;
	float gpuVoltage;
	float gpuMemoryTemp;
	float gpuMemoryClock;
	float gpuMemoryPower;
	float gpuMemory;
	float gpuCore;
	float gpuVrm;
	float cpuTemp;
	float cpuFan;
	float cpuUsage;
	float cpuPower;
	float ramUsage, pageFileUsage;
	System::String ^time;
	float motherboardTemperature;
};

