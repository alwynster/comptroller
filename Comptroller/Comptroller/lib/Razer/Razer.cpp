#include "Razer.h"



Razer::Razer()
{
	g_ChromaSDKImpl.Initialize();
}


Razer::~Razer()
{
	g_ChromaSDKImpl.UnInitialize();
}

void Razer::StaticColour(unsigned long colour)
{
	static RZEFFECTID EffectId = GUID_NULL;
	if (IsEqualGUID(EffectId, GUID_NULL))
	{
		g_ChromaSDKImpl.CreateEffectGroup(&EffectId);

		// mouse
		RZEFFECTID Frame1;

		ChromaSDK::Mouse::STATIC_EFFECT_TYPE StaticMouse = {};
		StaticMouse.LEDId = ChromaSDK::Mouse::RZLED_LOGO;
		StaticMouse.Color = colour;

		g_ChromaSDKImpl.CreateMouseEffectImpl(ChromaSDK::Mouse::CHROMA_STATIC, &StaticMouse, &Frame1);
		g_ChromaSDKImpl.AddToGroup(EffectId, Frame1, 200);  // Clear the LEDs

		// mousepad
		RZEFFECTID Frame2;

		ChromaSDK::Mousepad::STATIC_EFFECT_TYPE StaticMousePad = {};
		// Static.LEDId = ChromaSDK::Mousepad::LED;
		StaticMousePad.Color = colour;

		g_ChromaSDKImpl.CreateMousematEffectImpl(ChromaSDK::Mousepad::CHROMA_STATIC, &StaticMousePad, &Frame2);
		g_ChromaSDKImpl.AddToGroup(EffectId, Frame2, 200);  // Clear the LEDs


		// keyboard
		RZEFFECTID Frame3;

		ChromaSDK::Keyboard::STATIC_EFFECT_TYPE StaticKeyboard = {};
		// Static.LEDId = ChromaSDK::Mousepad::LED;
		StaticMousePad.Color = colour;

		g_ChromaSDKImpl.CreateKeyboardEffectImpl(ChromaSDK::Keyboard	::CHROMA_STATIC, &StaticMousePad, &Frame2);
		g_ChromaSDKImpl.AddToGroup(EffectId, Frame2, 200);  // Clear the LEDs
	}

	g_ChromaSDKImpl.SetEffectImpl(EffectId);
	EffectId = GUID_NULL;
}

void Razer::Rainbow(bool forward)
{
	static RZEFFECTID EffectId = GUID_NULL;
	if (IsEqualGUID(EffectId, GUID_NULL))
	{
		g_ChromaSDKImpl.CreateEffectGroup(&EffectId);

		// mouse
		RZEFFECTID Frame1;

		ChromaSDK::Mouse::WAVE_EFFECT_TYPE WaveMouse = {};
		if (forward)
			WaveMouse.Direction = WaveMouse.FRONT_TO_BACK;
		else
			WaveMouse.Direction = WaveMouse.BACK_TO_FRONT;

		g_ChromaSDKImpl.CreateMouseEffectImpl(ChromaSDK::Mouse::CHROMA_WAVE, &WaveMouse, &Frame1);
		//g_ChromaSDKImpl.CreateMouseEffectImpl(ChromaSDK::Mouse::CHROMA_STATIC, &StaticMouse, &Frame1);
		g_ChromaSDKImpl.AddToGroup(EffectId, Frame1, 200);  // Clear the LEDs

															// mousepad
		RZEFFECTID Frame2;

		ChromaSDK::Mousepad::WAVE_EFFECT_TYPE WaveMousePad = {};
		if (forward)
			WaveMousePad.Direction = WaveMousePad.DIRECTION_LEFT_TO_RIGHT;
		else
			WaveMousePad.Direction = WaveMousePad.DIRECTION_RIGHT_TO_LEFT;

		//ChromaSDK::Mousepad::STATIC_EFFECT_TYPE StaticMousePad = {};
		//// Static.LEDId = ChromaSDK::Mousepad::LED;
		//StaticMousePad.Color = colour;

		g_ChromaSDKImpl.CreateMousematEffectImpl(ChromaSDK::Mousepad::CHROMA_WAVE, &WaveMousePad, &Frame2);
		g_ChromaSDKImpl.AddToGroup(EffectId, Frame2, 200);  // Clear the LEDs


															// keyboard
		RZEFFECTID Frame3;

		ChromaSDK::Keyboard::WAVE_EFFECT_TYPE WaveKeyboard = {};
		if (forward)
			WaveKeyboard.Direction = WaveKeyboard.DIRECTION_LEFT_TO_RIGHT;
		else
			WaveKeyboard.Direction = WaveKeyboard.DIRECTION_RIGHT_TO_LEFT;
		//ChromaSDK::Keyboard::STATIC_EFFECT_TYPE StaticKeyboard = {};
		// Static.LEDId = ChromaSDK::Mousepad::LED;
		//StaticMousePad.Color = colour;

		g_ChromaSDKImpl.CreateKeyboardEffectImpl(ChromaSDK::Keyboard::CHROMA_WAVE, &WaveKeyboard, &Frame2);
		g_ChromaSDKImpl.AddToGroup(EffectId, Frame2, 200);  // Clear the LEDs
	}

	g_ChromaSDKImpl.SetEffectImpl(EffectId);
	EffectId = GUID_NULL;
}

bool Razer::HasRazer(){

	if (g_ChromaSDKImpl.m_hModule == NULL) {
		return 0;
	}
	else {

		return 1;
	}
}