#include "QMK.h"

// This function should be embedded in a try/catch block in case of
// an exception.  It offers the user a choice of MIDI ports to open.
// It returns false if there are no ports available.
bool chooseMidiPort(RtMidiOut ^rtmidi);

QMK::QMK()
{
	this->midiout = gcnew RtMidiOut(RtMidi::Api::WINDOWS_MM, "QMK");
	//this->FindMidiPorts();
}

QMK::~QMK()
{
	delete this->midiout;
	//delete this->midiin;
}

void QMK::FindMidiPorts()
{
	if (this->midiports != nullptr)
		delete this->midiports;

	std::string portName;
	unsigned int i = 0, nPorts = this->midiout->getPortCount();

	this->midiports = gcnew array<System::String ^>(nPorts);

	if (nPorts == 0) {
		std::cout << "No output ports available!" << std::endl;
		return;
	}

	if (nPorts == 1) {
		std::cout << "\nOpening " << this->midiout->getPortName(0) << std::endl;
	}
	else {
		for (i = 0; i<nPorts; i++) {
			portName = this->midiout->getPortName(i);
			this->midiports[i] = gcnew System::String(portName.c_str());
			//std::cout << "  Output port #" << i << ": " << portName << '\n';
		}

		//do {
			//std::cout << "\nChoose a port number: ";
			//std::cin >> i;
		//} while (i >= nPorts);
	}

	//std::cout << std::endl;
	//this->midiout->openPort(i, "RTMidi");
}

void QMK::Connect(int selectedDevice)
{
	//RtMidiOut ^midiout;
	//RtMidiIn *midiin = 0;
	std::vector<unsigned char> message;
	unsigned int i, nBytes;

	// Minimal command-line check.
	//if (argc != 2) usage();
	//nBytes = (unsigned int)atoi(argv[1]);
	nBytes = 10;

	// RtMidiOut and RtMidiIn constructors
	//try {
	//	this->midiout = gcnew RtMidiOut(RtMidi::Api::WINDOWS_MM, "RtMidi Output Client");
	//	//midiin = new RtMidiIn();
	//}
	//catch (RtMidiError &error) {
	//	error.printMessage();
	//	return;
	//	//goto cleanup;
	//}

	// Don't ignore sysex, timing, or active sensing messages.
	//midiin->ignoreTypes(false, true, true);

	try {
		//if (chooseMidiPort(midiin) == false) goto cleanup;
		//if (chooseMidiPort(midiout) == false) return;
		this->midiout->openPort(selectedDevice, "RTMidi");
	}
	catch (RtMidiError &error) {
		error.printMessage();
		//goto cleanup;
		return;
	}

	//midiin->setCallback(&mycallback);

	//Sysex::MT_SET_DATA(Sysex::DT::HANDSHAKE, nullptr, 0, this->midiout);

	//message.push_back(0xF6);
	//midiout->sendMessage(&message);
	////SLEEP(500); // pause a little

	//			// Create a long sysex message of numbered bytes and send it out ... twice.
	//for (int n = 0; n<2; n++) {
	//	message.clear();
	//	message.push_back(240);
	//	for (i = 0; i<nBytes; i++)
	//		message.push_back(i % 128);
	//	message.push_back(247);
	//	midiout->sendMessage(&message);

	//	//SLEEP(500); // pause a little
	//}

}

void QMK::staticColour(Colour ^colour)
{
	float r_float = (float)(colour->r / 255.0f);
	float g_float = (float)(colour->g / 255.0f);
	float b_float = (float)(colour->b / 255.0f);

	float h_float, s_float, v_float;

	uint16_t hue;
	uint8_t sat, val;

	RGBtoHSV(r_float, g_float, b_float, h_float, s_float, v_float);
	
	hue = (uint16_t) h_float;
	sat = s_float * 255;
	val = v_float * 255;

 	char *hsv = new char[4];
	char mode = 1; // static
	char enabled = 1;
	uint32_t dword = (uint32_t)(val << 24) | (uint32_t)(sat << 16) | (uint32_t)(hue << 7) | (uint32_t)(mode << 1) | (enabled);

	char *bytes = new char[4]{ (char)((dword >> 24) & 0xFF), (char)((dword >> 16) & 0xFF), (char)((dword >> 8) & 0xFF), (char)((dword) & 0xFF) };


	Sysex::MT_SET_DATA(Sysex::DT::RGBLIGHT, bytes, 4, this->midiout);
}

void QMK::staticColour(uint8_t red, uint8_t green, uint8_t blue)
{
	

}
