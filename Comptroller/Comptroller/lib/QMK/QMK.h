#pragma once

#include "RtMidi.h"
#include "../LED/LED.h"
#include "Sysex.h"
#include <stdint.h>
#include "Sysex.h"
#include "../LED/hsvrgb-cpp.h"

public ref class QMK
{
public:
	QMK::QMK();
	QMK::~QMK();

public:
	void Connect(int selectedDevice);
	void FindMidiPorts();
	void staticColour(Colour ^colour);
	void staticColour(uint8_t red, uint8_t green, uint8_t blue);

private:
	RtMidiOut ^midiout;
	//RtMidiIn ^midiin;

public:
	array<System::String ^> ^midiports;
};