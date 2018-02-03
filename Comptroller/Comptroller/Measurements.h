#pragma once

#include "StdAfx.h"
class Measurements
{
public:
	Measurements();
	~Measurements();

	void Update();
// members
public:
	CString gpuName;
	CTime time;
};

