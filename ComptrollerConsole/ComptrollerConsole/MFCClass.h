#pragma once


// MFCClass-Frame

class MFCClass : public CFrameWnd
{
	DECLARE_DYNCREATE(MFCClass)
protected:
	MFCClass();           // Dynamische Erstellung verwendet geschützten Konstruktor
	virtual ~MFCClass();

protected:
	DECLARE_MESSAGE_MAP()
};


