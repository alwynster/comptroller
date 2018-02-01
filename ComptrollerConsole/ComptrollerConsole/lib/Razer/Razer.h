#pragma once

#include "../../StdAfx.h"
#include "ChromaSDK/RzChromaSDKTypes.h"
#include "ChromaSDK/ChromaSDKImpl.h"

class Razer
{
public:
	Razer();
	~Razer();

	void StaticColour(unsigned long colour);
	bool HasRazer();
};

