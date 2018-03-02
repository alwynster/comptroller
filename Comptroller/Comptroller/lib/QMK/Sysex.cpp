#include "Sysex.h"



unsigned char Sysex::sysex_encoded_length(unsigned char decoded_length) {
	char remainder = (char)(decoded_length % 7);
	if (remainder > 0)
		return (unsigned char)((decoded_length / 7) * 8 + remainder + 1);
	else
		return (unsigned char)((decoded_length / 7) * 8);
}

unsigned char Sysex::sysex_decoded_length(unsigned char encoded_length) {
	char remainder = (char)(encoded_length % 8);
	if (remainder > 0)
		return (unsigned char)((encoded_length / 8) * 7 + remainder - 1);
	else
		return (unsigned char)((encoded_length / 8) * 7);
}

unsigned char Sysex::sysex_encode(char *encoded, char *source, unsigned char length) {
	unsigned char encoded_full = (unsigned char)(length / 7); //number of full 8 byte sections from 7 bytes of input
	unsigned char i, j;

	//fill out the fully encoded sections
	for (i = 0; i<encoded_full; i++) {
		unsigned char encoded_msb_idx = (unsigned char)(i * 8);
		unsigned char input_start_idx = (unsigned char)(i * 7);
		encoded[encoded_msb_idx] = 0;
		for (j = 0; j< 7; j++) {
			char current = source[input_start_idx + j];
			encoded[encoded_msb_idx] |= (char)((0x80 & current) >> (1 + j));
			encoded[encoded_msb_idx + 1 + j] = (char)(0x7F & current);
		}
	}

	//fill out the rest if there is any more
	char remainder = (char)(length % 7);
	if (remainder > 0) {
		unsigned char encoded_msb_idx = (unsigned char)(encoded_full * 8);
		unsigned char input_start_idx = (unsigned char)(encoded_full * 7);
		encoded[encoded_msb_idx] = 0;
		for (j = 0; j<remainder; j++) {
			char current = source[input_start_idx + j];
			encoded[encoded_msb_idx] |= (char)((0x80 & current) >> (1 + j));
			encoded[encoded_msb_idx + 1 + j] = (char)(0x7F & current);
		}
		return (unsigned char)(encoded_msb_idx + remainder + 1);
	}
	else {
		return (unsigned char)(encoded_full * 8);
	}
}

unsigned char Sysex::sysex_decode(char *decoded, char *source, unsigned char length) {
	unsigned char decoded_full = (unsigned char)(length / 8);
	unsigned char i, j;

	if (length < 2)
		return 0;

	//fill out the fully encoded sections
	for (i = 0; i < decoded_full; i++) {
		unsigned char encoded_msb_idx = (unsigned char)(i * 8);
		unsigned char output_start_index = (unsigned char)(i * 7);
		for (j = 0; j < 7; j++) {
			decoded[output_start_index + j] = (char)(0x7F & source[encoded_msb_idx + j + 1]);
			decoded[output_start_index + j] |= (char)((0x80 & (source[encoded_msb_idx] << (1 + j))));
		}
	}
	char remainder = (char)(length % 8);
	if (remainder > 0) {
		unsigned char encoded_msb_idx = (unsigned char)(decoded_full * 8);
		unsigned char output_start_index = (unsigned char)(decoded_full * 7);
		for (j = 0; j < (remainder - 1); j++) {
			decoded[output_start_index + j] = (char)(0x7F & source[encoded_msb_idx + j + 1]);
			decoded[output_start_index + j] |= (char)((0x80 & (source[encoded_msb_idx] << (1 + j))));
		}
		return (unsigned char)(decoded_full * 7 + remainder - 1);
	}
	else {
		return (unsigned char)(decoded_full * 7);
	}
}

void Sysex::sendBytes(MT message_type, DT data_type, char *bytes, unsigned char length, RtMidiOut ^output) {
	if (bytes == nullptr)
		bytes = new char[0]{};
	//if (output == null)
	//	output = Output;
	//setupOutput(output);
	unsigned char precodedLength = length + 2;
	char *precoded = new char[length + 2];
	precoded[0] = (char)message_type;
	precoded[1] = (char)data_type;
	//std::copy(bytes, bytes+length - 1, precoded + 2);
	memcpy(precoded + 2, bytes, length);
	char *encoded = new char[sysex_encoded_length(precodedLength)];
	unsigned char encoded_length = sysex_encode(encoded, precoded, precodedLength);
	unsigned char messageLength = encoded_length + 5;
	unsigned char *message = new unsigned char[messageLength];
	//std::copy(encoded, encoded + encoded_length - 1, message + 4);
	memcpy(message + 4, encoded, encoded_length);
	message[0] = 0xF0;              // 01: F0 - specifies SysEx 
	message[1] = 0x7E;              // 02: 7E - manufacturer ID
	message[2] = 0x00;              // 03: 00 - device ID (not readable?)
	message[3] = 0x00;              // 04: 00 - model ID
	message[messageLength - 1] = 0xF7; // 0x: F7 - end of transmission
	output->sendMessage(message, (size_t) messageLength);
	//output.SendSysEx(message);
	//output.Close();

	//System.Diagnostics.Debug.WriteLine("TX: " + BitConverter.ToString(message) + " (" + output.Name + ")");
}

void Sysex::MT_SET_DATA(DT data_type, char *data, unsigned char length, RtMidiOut ^device) {
	Sysex::sendBytes(Sysex::MT::SET_DATA, data_type, data, length, device);
}