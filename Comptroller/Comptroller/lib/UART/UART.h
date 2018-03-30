#pragma once

#include <windows.h>
#include <commctrl.h>

public ref class Uart
{
private:
	//DCB            ^PortDCB;
	HANDLE         hPort;
	bool connected;
	//COMMTIMEOUTS   ^CommTimeouts;

private:
	int configure(DCB *PortDCB);
	int configuretimeout(COMMTIMEOUTS *CommTimeouts);

public:
	int initialise(void);
	bool isOpen(void);
	Uart::Uart(void); //  char *Port = "COM1", int baud = 9600, int Bitsize = 8, int StopBits = 1, int Parity = NOPARITY);
	int WriteUart(unsigned char *buf, int len);
	int ReadUart(unsigned char *buf, int len);
	//int ReadUart(unsigned char *buf);
	int CloseUart(void);
};