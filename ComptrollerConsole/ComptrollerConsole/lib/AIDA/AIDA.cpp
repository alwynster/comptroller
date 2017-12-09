// MAHMSharedMemorySampleDlg.cpp : implementation file
//
// created by Unwinder
/////////////////////////////////////////////////////////////////////////////
#include "../../StdAfx.h"
#include "AIDA.h"

#include <float.h>
#include <io.h>
#include <string>
#include "../tinyxml2/tinyxml2.h"

#ifdef _DEBUG
#define new DEBUG_NEW
#undef THIS_FILE
static char THIS_FILE[] = __FILE__;
#endif

/////////////////////////////////////////////////////////////////////////////
// CMAHMSharedMemorySampleDlg dialog
/////////////////////////////////////////////////////////////////////////////
AIDA::AIDA() // CWnd* pParent /*=NULL*/): CDialog(CMAHMSharedMemorySampleDlg::IDD, pParent)
{
	m_hMapFile			= NULL;
	m_pMapAddr			= NULL;
	m_nTimerID			= 0;

	m_strInstallPath	= "";
}
/////////////////////////////////////////////////////////////////////////////
// This function is used to connect to MSI Afterburner hardware monitoring
// shared memory
/////////////////////////////////////////////////////////////////////////////
void AIDA::Connect()
{
	Disconnect();
		//we must disconnect from the previously connected shared memory before
		//connecting to new one

	m_hMapFile = OpenFileMapping(FILE_MAP_ALL_ACCESS, FALSE, "AIDA64_SensorValues");

	if (m_hMapFile)
		m_pMapAddr = MapViewOfFile(m_hMapFile, FILE_MAP_ALL_ACCESS, 0, 0, 0);
}
/////////////////////////////////////////////////////////////////////////////
// This function is used to disconnect from MSI Afterburner hardware monitoring
// shared memory
/////////////////////////////////////////////////////////////////////////////
void AIDA::Disconnect()
{
	if (m_pMapAddr)
		UnmapViewOfFile(m_pMapAddr);

	m_pMapAddr = NULL;

	if (m_hMapFile)
		CloseHandle(m_hMapFile);

	m_hMapFile = NULL;
}
/////////////////////////////////////////////////////////////////////////////
BOOL AIDA::IsSystemSource(DWORD id)
{
	switch (id)
	{
	case MONITORING_SOURCE_ID_CPU_TEMPERATURE:
	case MONITORING_SOURCE_ID_CPU_USAGE:
	case MONITORING_SOURCE_ID_RAM_USAGE:
	case MONITORING_SOURCE_ID_PAGEFILE_USAGE:
	case MONITORING_SOURCE_ID_CPU_CLOCK:
	case MONITORING_SOURCE_ID_FRAMERATE:
	case MONITORING_SOURCE_ID_FRAMETIME:
		return TRUE;
	}

	return FALSE;
}

void AIDA::FetchInstallationPath()
{
	//init MSI Afterburner installation path

	if (m_strInstallPath.IsEmpty())
	{
		HKEY hKey;

		if (ERROR_SUCCESS == RegOpenKey(HKEY_LOCAL_MACHINE, "Software\\MSI\\Afterburner", &hKey))
		{
			char buf[MAX_PATH];

			DWORD dwSize = MAX_PATH;
			DWORD dwType;

			if (ERROR_SUCCESS == RegQueryValueEx(hKey, "InstallPath", 0, &dwType, (LPBYTE)buf, &dwSize))
			{
				if (dwType == REG_SZ)
					m_strInstallPath = buf;
			}

			RegCloseKey(hKey);
		}
	}

	//validate MSI Afterburner installation path

	if (_taccess(m_strInstallPath, 0))
		m_strInstallPath = "";
}

/////////////////////////////////////////////////////////////////////////////
// we'll update sample's window on timer once per second
/////////////////////////////////////////////////////////////////////////////
void AIDA::FetchReadings(Measurements *destination)
{
	//this->FetchInstallationPath();
	
	//if we're not connected to MSI Afterburner hardware monitoring shared memory yet - do it now

	if (!m_pMapAddr)
		Connect();

	if (m_pMapAddr)
		//if we're connected to shared memory, we must check if it is valid or not and reconnect if necessary
	{
		char * memory = (char *)((LPVOID *)m_pMapAddr);

		//printf(memory);

		tinyxml2::XMLDocument doc;
		doc.Parse(memory);
		doc.Print();

		float value;
		std::string name;
		std::string type;
		std::string id;

		for (tinyxml2::XMLNode *node = doc.FirstChild(); node; node = node->NextSibling())
		{
			type = node->Value();
			//printf("%s \n", node->Value());
			for (tinyxml2::XMLNode *attr = node->FirstChild(); attr; attr = attr->NextSibling())
			{
				// luckily id happens first in the xml
				if (!strcmp(attr->Value(), "id"))
					id = attr->FirstChild()->Value();

				// find the value of the attribute
				else if (!strcmp(attr->Value(), "value"))
				{
					const char *valueC = attr->FirstChild()->Value();

					// TRIAL does not show all values 
					if (strcmp(valueC, "TRIAL"))
					{
						// new value available
						value = std::stof(attr->FirstChild()->Value(), 0);

						// id should already be available
						if (!strcmp(id.c_str(), "FCPU"))
							destination->cpuFan = value;
						else if (!strcmp(id.c_str(), "PCPUPKG"))
							destination->cpuPower = value;
						/*else if (!strcmp(id.c_str(), "PGPU1"))
							destination->gpuPower = value;*/
						else if (!strcmp(id.c_str(), "PGPU1MEM"))
							destination->gpuMemoryPower = value;
						else if (!strcmp(id.c_str(), "PGPU1VRM"))
							destination->gpuVrm = value;	
						else if (!strcmp(id.c_str(), "DGPU1"))
							destination->gpuFanPwm = value;
					}
				}

				//printf("%s %s", attr->Value(), attr->FirstChild()->Value());
			}
			//printf("\n");
		}

	}
	else
	{
		if (m_strInstallPath.IsEmpty())
			m_strStatus = "Failed to connect to AIDA Hardware Monitoring shared memory!\n\nHints:\n-Install MSI Afterburner";
		else
			m_strStatus = "Failed to connect to AIDA Hardware Monitoring shared memory!\n\nHints:\n-Press <Space> to start MSI Afterburner";
	}
	

	//UpdateStatus();

	//CDialog::OnTimer(nIDEvent);
}
/////////////////////////////////////////////////////////////////////////////
AIDA::~AIDA()
{
	Disconnect();
}


///////////////////////////////////////////////////////////////////////////////
//CString AIDA::DumpEntry(LPMAHM_SHARED_MEMORY_ENTRY lpEntry, Measurements *destination)
//{
//	CString strValue;
//
//	if (lpEntry->data == FLT_MAX)
//		strValue = "N/A";
//	else
//	{
//		if (strcmp(lpEntry->szSrcName, "Motherboard temperature") == 0)
//			destination->motherboardTemperature = lpEntry->data;
//		else if (strcmp(lpEntry->szSrcName, "GPU1 temperature") == 0)
//			destination->gpuTemp = lpEntry->data;		
//		else if (strcmp(lpEntry->szSrcName, "GPU1 memory temperature") == 0)
//			destination->gpuMemoryTemp = lpEntry->data;
//		else if (strcmp(lpEntry->szSrcName, "GPU1 usage") == 0)
//			destination->gpuUsage = lpEntry->data;
//		else if (strcmp(lpEntry->szSrcName, "GPU1 power") == 0)
//			destination->gpuPower = lpEntry->data;	\
//		else if (strcmp(lpEntry->szSrcName, "CPU temperature") == 0)
//			destination->cpuTemp = lpEntry->data;
//		else if (strcmp(lpEntry->szSrcName, "CPU usage") == 0)
//			destination->cpuUsage = lpEntry->data;
//		else if (strcmp(lpEntry->szSrcName, "RAM usage") == 0)
//			destination->ramUsage = lpEntry->data;
//		else if (strcmp(lpEntry->szSrcName, "Pagefile usage") == 0)
//			destination->pageFileUsage = lpEntry->data;
//	
//		strValue.Format(lpEntry->szRecommendedFormat, lpEntry->data); // this is the name
//		strValue += " ";
//		strValue += lpEntry->szLocalizedSrcUnits; // this is the value
//	}
//
//	CString strEntry;
//
//	strEntry.Format("%-32s\t : %-16s\t", lpEntry->szLocalizedSrcName, strValue);
//
//	//CString strProperties;
//
//	//if (lpEntry->dwFlags & MAHM_SHARED_MEMORY_ENTRY_FLAG_SHOW_IN_OSD)
//	//{
//	//	if (!strProperties.IsEmpty())
//	//		strProperties += ", ";
//
//	//	strProperties += "OSD";
//	//}
//
//	//if (lpEntry->dwFlags & MAHM_SHARED_MEMORY_ENTRY_FLAG_SHOW_IN_LCD)
//	//{
//	//	if (!strProperties.IsEmpty())
//	//		strProperties += ", ";
//
//	//	strProperties += "LCD";
//	//}
//
//	//if (lpEntry->dwFlags & MAHM_SHARED_MEMORY_ENTRY_FLAG_SHOW_IN_TRAY)
//	//{
//	//	if (!strProperties.IsEmpty())
//	//		strProperties += ", ";
//
//	//	strProperties += "tray";
//	//}
//
//	//if (!strProperties.IsEmpty())
//	//	strProperties = "in " + strProperties;
//
//	//strEntry += strProperties;
//	strEntry += "\n";
//
//	return strEntry;
//}
///////////////////////////////////////////////////////////////////////////////
//CString AIDA::DumpGpuEntry(LPMAHM_SHARED_MEMORY_GPU_ENTRY lpGpuEntry, Measurements *destination)
//{
//	CString strEntry;
//	CString strBuf;
//
//	strBuf.Format("%-32s\t : %-16s\n", "GUID", lpGpuEntry->szGpuId);
//	//strEntry += strBuf;
//
//	if (strlen(lpGpuEntry->szDevice))
//	{
//		CString strDevice;
//
//		if (strlen(lpGpuEntry->szFamily))
//			strDevice.Format("%s on %s GPU", lpGpuEntry->szDevice, lpGpuEntry->szFamily);
//		else
//			strDevice = lpGpuEntry->szDevice;
//
//		destination->gpuName = strDevice;
//
//		strBuf.Format("%-32s\t : %s\n", "Device", strDevice);
//		strEntry += strBuf;
//	}
//
//	if (strlen(lpGpuEntry->szDriver))
//	{
//		strBuf.Format("%-32s\t : %s\n", "Driver", lpGpuEntry->szDriver);
//		strEntry += strBuf;
//	}
//
//	if (strlen(lpGpuEntry->szBIOS))
//	{
//		strBuf.Format("%-32s\t : %s\n", "BIOS", lpGpuEntry->szBIOS);
//		strEntry += strBuf;
//	}
//
//	if (lpGpuEntry->dwMemAmount)
//	{
//		strBuf.Format("%-32s\t : %d MB\n", "On-board memory", lpGpuEntry->dwMemAmount / 1024);
//		strEntry += strBuf;
//	}
//
//
//
//	return strEntry;
//}
///////////////////////////////////////////////////////////////////////////////
//void AIDA::UpdateStatus()
//{
//	printf(m_strStatus);
//}

