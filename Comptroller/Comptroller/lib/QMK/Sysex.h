#pragma once

#include <stdint.h>
#include <sys/types.h>
#include <cstdint>
#include "RtMidi.h"
#include <array>

//typedef char byte;

public class Sysex
{
	typedef unsigned char ushort;

public:
	enum MT {
		GET_DATA = 0x10, // Get data from keyboard
		GET_DATA_ACK = 0x11, // returned data to process (ACK)
		SET_DATA = 0x20, // Set data on keyboard
		SET_DATA_ACK = 0x21, // returned data to confirm (ACK)
		SEND_DATA = 0x30, // Sending data/action from keyboard
		SEND_DATA_ACK = 0x31, // returned data/action confirmation (ACK)
		EXE_ACTION = 0x40, // executing actions on keyboard
		EXE_ACTION_ACK = 0x41, // return confirmation/value (ACK)
		TYPE_ERROR = 0x80 // type not recofgnised (ACK)
	};

	enum DT {
		NONE = 0x00,
		HANDSHAKE,
		DEFAULT_LAYER,
		CURRENT_LAYER,
		KEYMAP_OPTIONS,
		BACKLIGHT,
		RGBLIGHT,
		UNICODETYPE,
		DEBUGTYPE,
		AUDIO,
		QUANTUM_ACTION,
		KEYBOARD_ACTION,
		USER_ACTION,
	};

	enum RGBLightModes {
		Static = 1,
		Breathing_Slow = 2,
		Breathing_Medium,
		Breathing_Fast,
		Breathing_Very_Fast,
		Rainbow_Slow = 6,
		Rainbow_Medium,
		Rainbow_Fast,
		Rainbow_Swirl_Super_Slow = 9,
		Rainbow_Swirl_Very_Slow,
		Rainbow_Swirl_Slow,
		Rainbow_Swirl_Medium,
		Rainbow_Swirl_Fast,
		Rainbow_Swirl_Very_Fast,
		Snake_Slow = 15,
		Snake_Reverse_Slow,
		Snake_Medium,
		Snake_Reverse_Medium,
		Snake_Fast,
		Snake_Reverse_Fast,
		Knight_Slow = 21,
		Knight_Medium,
		Knight_Fast
	};

public:
	static unsigned char sysex_encoded_length(unsigned char decoded_length);
	static unsigned char sysex_decoded_length(unsigned char encoded_length);
	static unsigned char sysex_encode(char *encoded, char *source, unsigned char length);
	static unsigned char sysex_decode(char *decoded, char *source, unsigned char length);
	static void sendBytes(MT message_type, DT data_type, char *bytes, unsigned char length, RtMidiOut ^output);
	static void MT_SET_DATA(DT data_type, char *data, unsigned char length, RtMidiOut ^device);

};