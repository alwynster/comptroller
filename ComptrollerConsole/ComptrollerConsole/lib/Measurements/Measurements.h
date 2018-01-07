#pragma once

#include "../../StdAfx.h"
//#include "../MSI Afterburner/MSIAfterBurnerPlugin.h"

class Measurements
{
public:
	Measurements();
	~Measurements();

	void Update();
	void Print();

// members
public:
	CString gpuName;
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
	CTime time;
	float motherboardTemperature;
};

