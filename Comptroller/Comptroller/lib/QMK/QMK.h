#pragma once

#include "RtMidi.h"

public ref class QMK
{
public:
	QMK::QMK();
	QMK::~QMK();

public:
	void Connect(System::String ^hint);

private:
	RtMidiOut ^midiout;
	//RtMidiIn ^midiin;
};