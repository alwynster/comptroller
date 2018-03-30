#include "UART.h"
#include <stdio.h>
#include <stdint.h>
#include <sstream>
#include <atlstr.h>

//int configure();
char           lastError[1024], buf1[100], buf2[100];


bool Uart::isOpen(void)
{
	return this->connected;
}


Uart::Uart(void) //  char *Port = "COM1", int baud = 9600, int Bitsize = 8, int StopBits = 1, int Parity = NOPARITY);
{
	//this->connected = false;
	this->connected = this->initialise();
	if (!this->connected)
		MessageBox(NULL, L"Error initialising UART", L"Error", MB_OK);
}

int Uart::initialise(void)
{
	int STOPBITS;
	DCB PortDCB;
	//HANDLE         hPort;
	COMMTIMEOUTS CommTimeouts;

	this->hPort = CreateFile(TEXT("COM3"),			            // Name of the port 
		GENERIC_READ | GENERIC_WRITE,     // Access (read-write) mode 
		0,
		NULL,
		OPEN_EXISTING,
		FILE_ATTRIBUTE_NORMAL,
		NULL);


	if (this->hPort == INVALID_HANDLE_VALUE)
	{
		MessageBox(NULL, L"Port Open Failed\n", L"Uart Problem", MB_OK);
		return 0;
	}

	//Initialize the DCBlength member. 
	PortDCB.DCBlength = sizeof(DCB);

	// Get the default port setting information.
	GetCommState(hPort, &PortDCB);
	this->configure(&PortDCB);

	// Retrieve the time-out parameters for all read and write operations  
	GetCommTimeouts(hPort, &CommTimeouts);
	this->configuretimeout(&CommTimeouts);



	//Re-configure the port with the new DCB structure. 
	if (!SetCommState(hPort, &PortDCB))
	{
		printf("1.Could not create the read thread.(SetCommState Failed)");
		CloseHandle(hPort);
		return 0;
	}

	// Set the time-out parameters for all read and write operations on the port. 
	if (!SetCommTimeouts(hPort, &CommTimeouts))
	{
		printf("Could not create the read thread.(SetCommTimeouts Failed)");
		CloseHandle(hPort);
		return 0;
	}

	// Clear the port of any existing data. 
	if (PurgeComm(hPort, PURGE_TXCLEAR | PURGE_RXCLEAR) == 0)
	{
		printf("Clearing The Port Failed");
		CloseHandle(hPort);
		return 0;
	}

	printf("COM3 SERIAL SETUP OK.\n");
	return 1;
}

int Uart::configure(DCB *PortDCB)
{
	// Change the DCB structure settings
	PortDCB->fBinary = FALSE;                         // Binary mode; no EOF check
	PortDCB->fParity = FALSE;                         // Enable parity checking 
	PortDCB->fDsrSensitivity = FALSE;                // DSR sensitivity 
	PortDCB->fErrorChar = FALSE;                     // Disable error replacement 
	PortDCB->fOutxDsrFlow = FALSE;                   // No DSR output flow control 
	PortDCB->fAbortOnError = FALSE;                  // Do not abort reads/writes on error
	PortDCB->fNull = FALSE;                          // Disable null stripping 
	PortDCB->fTXContinueOnXoff = FALSE;                // XOFF continues Tx 

	PortDCB->BaudRate = 9600;
	PortDCB->ByteSize = 8;
	PortDCB->Parity = NOPARITY;
	PortDCB->StopBits = ONESTOPBIT;
	

	return 1;
}

int Uart::configuretimeout(COMMTIMEOUTS *CommTimeouts)
{
	memset(CommTimeouts, 0x00, sizeof(CommTimeouts)); 
	CommTimeouts->ReadIntervalTimeout = 50;
	CommTimeouts->ReadTotalTimeoutConstant = 50;
	CommTimeouts->ReadTotalTimeoutMultiplier = 10;
	CommTimeouts->WriteTotalTimeoutMultiplier = 10;
	CommTimeouts->WriteTotalTimeoutConstant = 50;
	return 1;
}

int Uart::WriteUart(unsigned char *buf1, int len) // , HANDLE hPort)
{
	DWORD dwNumBytesWritten;

	WriteFile(this->hPort, buf1, len, &dwNumBytesWritten, NULL);

	if (dwNumBytesWritten > 0)
	{
		//MessageBox (NULL, L"Transmission Success" ,L"Success", MB_OK);
		return 1;
	}

	else
	{
		printf("Transmission Failed\n");
		return 0;
	}
}



int Uart::ReadUart(unsigned char *buf, int len) // , HANDLE hPort)
{
	BOOL ret;
	DWORD dwRead;
	BOOL fWaitingOnRead = FALSE;
	OVERLAPPED osReader = { 0 };
	unsigned long retlen = 0;
	std::ostringstream str;
	char buffer[33];
	// Create the overlapped event. Must be closed before exiting to avoid a handle leak.

	osReader.hEvent = CreateEvent(NULL, TRUE, FALSE, NULL);
	if (osReader.hEvent == NULL)
		printf("Error in creating Overlapped event\n");
	if (!fWaitingOnRead)
	{
		if (!ReadFile(this->hPort, buf, len, &dwRead, &osReader))
		{
			return -1;
			// printf("could not read UART\n");
		}
		else
		{
			// MessageBox (NULL, L"ReadFile Suceess" ,L"Success", MB_OK);
		}

	}
	
	if (dwRead > 0)
	{

		MessageBox (NULL, CStringW(buf) ,L"Success", MB_OK);//If we have data
		return (int)retlen;
	}
	//return the length

	else return 0;     //else no data has been read
}

int Uart::CloseUart()
{
	CloseHandle(this->hPort);
	return 1;
}