#pragma once

//#include "../../StdAfx.h"
#include "ChromaSDK/RzChromaSDKTypes.h"
#include "ChromaSDK/ChromaSDKImpl.h"

public ref class Razer
{
public:
	Razer();
	~Razer();

	void StaticColour(unsigned long colour);
	bool HasRazer();
};

