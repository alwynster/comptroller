// MAHMSharedMemorySampleDlg.cpp : implementation file
//
// created by Unwinder
/////////////////////////////////////////////////////////////////////////////
//#include "../../StdAfx.h"
#include "MSIAfterBurnerPlugin.h"

#include <float.h>
#include <io.h>

#ifdef _DEBUG
#define new DEBUG_NEW
#undef THIS_FILE
static char THIS_FILE[] = __FILE__;
#endif

/////////////////////////////////////////////////////////////////////////////
// CMAHMSharedMemorySampleDlg dialog
/////////////////////////////////////////////////////////////////////////////
MSIAfterBurnerPlugin::MSIAfterBurnerPlugin() // CWnd* pParent /*=NULL*/): CDialog(CMAHMSharedMemorySampleDlg::IDD, pParent)
{
	m_hMapFile			= NULL;
	m_pMapAddr			= NULL;
	m_nTimerID			= 0;

	m_strInstallPath	= "";

	measurements = gcnew Measurements();
}
/////////////////////////////////////////////////////////////////////////////
// This function is used to connect to MSI Afterburner hardware monitoring
// shared memory
/////////////////////////////////////////////////////////////////////////////
void MSIAfterBurnerPlugin::Connect()
{
	Disconnect();
		//we must disconnect from the previously connected shared memory before
		//connecting to new one

	m_hMapFile = OpenFileMapping(FILE_MAP_ALL_ACCESS, FALSE, L"MAHMSharedMemory");

	if (m_hMapFile)
		m_pMapAddr = MapViewOfFile(m_hMapFile, FILE_MAP_ALL_ACCESS, 0, 0, 0);
}
/////////////////////////////////////////////////////////////////////////////
// This function is used to disconnect from MSI Afterburner hardware monitoring
// shared memory
/////////////////////////////////////////////////////////////////////////////
void MSIAfterBurnerPlugin::Disconnect()
{
	if (m_pMapAddr)
		UnmapViewOfFile(m_pMapAddr);

	m_pMapAddr = NULL;

	if (m_hMapFile)
		CloseHandle(m_hMapFile);

	m_hMapFile = NULL;
}
/////////////////////////////////////////////////////////////////////////////
BOOL MSIAfterBurnerPlugin::IsSystemSource(DWORD id)
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

void MSIAfterBurnerPlugin::FetchInstallationPath()
{
	//init MSI Afterburner installation path

	if (m_strInstallPath == (L""))
	{
		HKEY hKey;

		if (ERROR_SUCCESS == RegOpenKey(HKEY_LOCAL_MACHINE, L"Software\\MSI\\Afterburner", &hKey))
		{
			char buf[MAX_PATH];

			DWORD dwSize = MAX_PATH;
			DWORD dwType;

			if (ERROR_SUCCESS == RegQueryValueEx(hKey, L"InstallPath", 0, &dwType, (LPBYTE)buf, &dwSize))
			{
				if (dwType == REG_SZ)
					m_strInstallPath = gcnew System::String(buf);
			}

			RegCloseKey(hKey);
		}
	}

	//validate MSI Afterburner installation path

	pin_ptr<const wchar_t> wch = PtrToStringChars(m_strInstallPath);

	if (_taccess(wch, 0))
		m_strInstallPath = "";
}

/////////////////////////////////////////////////////////////////////////////
// we'll update sample's window on timer once per second
/////////////////////////////////////////////////////////////////////////////
void MSIAfterBurnerPlugin::FetchReadings(void)
{
	this->FetchInstallationPath();
	
	//if we're not connected to MSI Afterburner hardware monitoring shared memory yet - do it now

	if (!m_pMapAddr)
		Connect();

	if (m_pMapAddr)
		//if we're connected to shared memory, we must check if it is valid or not and reconnect if necessary
	{
		LPMAHM_SHARED_MEMORY_HEADER lpHeader = (LPMAHM_SHARED_MEMORY_HEADER)m_pMapAddr;

		if (lpHeader->dwSignature == 0xDEAD)
			//if the memory is marked as dead (e.g. MSI Afterburner was unloaded), we should disconnect from it and
			//try to connect again
			Connect();
	}

	if (m_pMapAddr)
	{
		LPMAHM_SHARED_MEMORY_HEADER	lpHeader = (LPMAHM_SHARED_MEMORY_HEADER)m_pMapAddr;

		if (lpHeader->dwSignature == 'MAHM')
			//check if we're connected to valid memory
		{
			CTime time(lpHeader->time);
			//.Format(L"%d-%m-%Y %H:%M:%S")

			measurements->time = System::DateTime::Now.ToString();
			CString strBuf = L"";// time.Format(L"%d-%m-%Y %H:%M:%S");
			//	//format data polling time
			//measurements->time = gcnew System::String(strBuf); // time; // time.Format("%d-%m-%Y %H:%M:%S");

			DWORD dwSources = lpHeader->dwNumEntries;
				//get number of data sources

			m_strStatus = "";

			if (lpHeader->dwVersion >= 0x00020000)
				//GPU entries are available only in v2.0 and newer shared memory format
			{
				DWORD dwGpus = lpHeader->dwNumGpuEntries;
				//get number of GPUs
				
				dwGpus = 1;
				// NOTE: Only considering the first gpu

				for (DWORD dwGpu=0; dwGpu<dwGpus; dwGpu++)
					//display info for each GPU
				{
					LPMAHM_SHARED_MEMORY_GPU_ENTRY	lpGpuEntry = (LPMAHM_SHARED_MEMORY_GPU_ENTRY)((LPBYTE)lpHeader + lpHeader->dwHeaderSize + lpHeader->dwNumEntries * lpHeader->dwEntrySize + dwGpu * lpHeader->dwGpuEntrySize);
						//get ptr to the current GPU entry

					CString strStatus = DumpGpuEntry(lpGpuEntry);

					for (DWORD dwSource=0; dwSource<dwSources; dwSource++)
						//display info for each data source
					{
						LPMAHM_SHARED_MEMORY_ENTRY	lpEntry		= (LPMAHM_SHARED_MEMORY_ENTRY)((LPBYTE)lpHeader + lpHeader->dwHeaderSize + dwSource * lpHeader->dwEntrySize);
							//get ptr to the current data source entry

						if (IsSystemSource(lpEntry->dwSrcId))
							//filter system data sources
							continue;

						if (lpEntry->dwGpu != dwGpu)
							//filter data source entries by GPU index
							continue;

						strStatus += DumpEntry(lpEntry);
							//dump data source entry
					}

					if (!strStatus.IsEmpty())
					{
						strBuf.Format(L"GPU%d\n", dwGpu + 1);
							//keep in mind that GPU indices are 0-based, so we need to correct index when
							//formatting the GPU section header 

						m_strStatus->Concat(gcnew System::String(strBuf));
						m_strStatus->Concat(gcnew System::String(strStatus));

						//m_strStatus += strBuf;
						//m_strStatus += strStatus;
						m_strStatus += "\n";
					}
				}

				//additional pass for system data sources

				CString strStatus;

				for (DWORD dwSource=0; dwSource<dwSources; dwSource++)
					//display info for each data source
				{
					LPMAHM_SHARED_MEMORY_ENTRY	lpEntry		= (LPMAHM_SHARED_MEMORY_ENTRY)((LPBYTE)lpHeader + lpHeader->dwHeaderSize + dwSource * lpHeader->dwEntrySize);
						//get ptr to the current data source entry

					if (!IsSystemSource(lpEntry->dwSrcId))
						//filter GPU-specific data sources
						continue;

					strStatus += DumpEntry(lpEntry);
						//dump data source entry
				}

				if (!strStatus.IsEmpty())
				{
					m_strStatus += "Global\n";
					//m_strStatus += strStatus;
					m_strStatus->Concat(gcnew System::String(strStatus));
					m_strStatus += "\n";
				}
			}
			else
			{
				for (DWORD dwSource=0; dwSource<dwSources; dwSource++)
					//display info for each data source
				{
					LPMAHM_SHARED_MEMORY_ENTRY	lpEntry		= (LPMAHM_SHARED_MEMORY_ENTRY)((LPBYTE)lpHeader + lpHeader->dwHeaderSize + dwSource * lpHeader->dwEntrySize);
						//get ptr to the current data source entry

					m_strStatus->Concat(gcnew System::String(DumpEntry(lpEntry)));
						//dump data source entry
				}

				m_strStatus += "\n";
			}
		}
		else
			m_strStatus = "Connected to uninitialized MSI Afterburner Hardware Monitoring shared memory\n\n";

		//m_strStatus += "Hints:\n-Press <Space> to open MSI Afterburner hardware monitoring properties\n-Press <1>...<5> to load and apply the profiles from the corresponding MSI Afterburner profile slots";
	}
	else
	{
		if (m_strInstallPath->Length == 0)
			m_strStatus = "Failed to connect to MSI Afterburner Hardware Monitoring shared memory!\n\nHints:\n-Install MSI Afterburner";
		else
			m_strStatus = "Failed to connect to MSI Afterburner Hardware Monitoring shared memory!\n\nHints:\n-Press <Space> to start MSI Afterburner";
	}
	

	UpdateStatus();

	//CDialog::OnTimer(nIDEvent);
}
/////////////////////////////////////////////////////////////////////////////
MSIAfterBurnerPlugin::~MSIAfterBurnerPlugin()
{
	Disconnect();
}


/////////////////////////////////////////////////////////////////////////////
CString MSIAfterBurnerPlugin::DumpEntry(LPMAHM_SHARED_MEMORY_ENTRY lpEntry)
{
	CString strValue;

	if (lpEntry->data == FLT_MAX)
		strValue = "N/A";
	else
	{
		if (strcmp(lpEntry->szSrcName, "Motherboard temperature") == 0)
			measurements->motherboardTemperature = lpEntry->data;
		else if ((strcmp(lpEntry->szSrcName, "GPU1 temperature") == 0) || (strcmp(lpEntry->szSrcName, "GPU temperature") == 0))
			measurements->gpuTemp = lpEntry->data;
		else if ((strcmp(lpEntry->szSrcName, "GPU1 memory temperature") == 0) || (strcmp(lpEntry->szSrcName, "Memory temperature") == 0))
			measurements->gpuMemoryTemp = lpEntry->data;
		else if ((strcmp(lpEntry->szSrcName, "GPU1 usage") == 0) || (strcmp(lpEntry->szSrcName, "GPU usage") == 0))
			measurements->gpuUsage = lpEntry->data;
		else if ((strcmp(lpEntry->szSrcName, "GPU1 power") == 0) || (strcmp(lpEntry->szSrcName, "GPU power") == 0))
			measurements->gpuPower = lpEntry->data;
		else if ((strcmp(lpEntry->szSrcName, "GPU1 memory usage") == 0) || (strcmp(lpEntry->szSrcName, "Memory usage") == 0))
			measurements->gpuMemory = lpEntry->data;
		else if ((strcmp(lpEntry->szSrcName, "GPU1 core clock") == 0) || (strcmp(lpEntry->szSrcName, "Core clock") == 0))
			measurements->gpuCore = lpEntry->data;
		else if ((strcmp(lpEntry->szSrcName, "GPU1 memory clock") == 0) || (strcmp(lpEntry->szSrcName, "Memory clock") == 0))
			measurements->gpuMemoryClock = lpEntry->data;
		else if (strcmp(lpEntry->szSrcName, "GPU voltage") == 0)
			measurements->gpuVoltage = lpEntry->data;
		else if (strcmp(lpEntry->szSrcName, "Power") == 0)
			measurements->gpuPower = lpEntry->data;
		else if (strcmp(lpEntry->szSrcName, "Fan tachometer") == 0)
			measurements->gpuFanPwm = lpEntry->data;
		else if (strcmp(lpEntry->szSrcName, "CPU temperature") == 0)
			measurements->cpuTemp = lpEntry->data;
		else if (strcmp(lpEntry->szSrcName, "CPU usage") == 0)
			measurements->cpuUsage = lpEntry->data;
		else if (strcmp(lpEntry->szSrcName, "RAM usage") == 0)
			measurements->ramUsage = lpEntry->data;
		else if (strcmp(lpEntry->szSrcName, "Pagefile usage") == 0)
			measurements->pageFileUsage = lpEntry->data;
		
		// :::::::
		//strValue.Format(lpEntry->szRecommendedFormat, lpEntry->data); // this is the name
		strValue += " ";
		strValue += lpEntry->szLocalizedSrcUnits; // this is the value
	}

	////////////////printf("\n%s\n", strValue);
	CString strEntry;

	// :::::::

	//strEntry.Format("%-32s\t : %-16s\t", lpEntry->szLocalizedSrcName, strValue);

	//CString strProperties;

	//if (lpEntry->dwFlags & MAHM_SHARED_MEMORY_ENTRY_FLAG_SHOW_IN_OSD)
	//{
	//	if (!strProperties.IsEmpty())
	//		strProperties += ", ";

	//	strProperties += "OSD";
	//}

	//if (lpEntry->dwFlags & MAHM_SHARED_MEMORY_ENTRY_FLAG_SHOW_IN_LCD)
	//{
	//	if (!strProperties.IsEmpty())
	//		strProperties += ", ";

	//	strProperties += "LCD";
	//}

	//if (lpEntry->dwFlags & MAHM_SHARED_MEMORY_ENTRY_FLAG_SHOW_IN_TRAY)
	//{
	//	if (!strProperties.IsEmpty())
	//		strProperties += ", ";

	//	strProperties += "tray";
	//}

	//if (!strProperties.IsEmpty())
	//	strProperties = "in " + strProperties;

	//strEntry += strProperties;
	strEntry += "\n";

	return strEntry;
}
/////////////////////////////////////////////////////////////////////////////
CString MSIAfterBurnerPlugin::DumpGpuEntry(LPMAHM_SHARED_MEMORY_GPU_ENTRY lpGpuEntry)
{
	CString strEntry;
	CString strBuf;

	strBuf.Format(L"%-32s\t : %-16s\n", "GUID", lpGpuEntry->szGpuId);
	//strEntry += strBuf;

	if (strlen(lpGpuEntry->szDevice))
	{
		CString strDevice;

		if (strlen(lpGpuEntry->szFamily))
		{
			//strDevice.Format(L"%s on %s GPU", (LPCTSTR)lpGpuEntry->szDevice, lpGpuEntry->szFamily);
			strDevice = lpGpuEntry->szDevice;
			strDevice += " on ";
			strDevice += lpGpuEntry->szFamily;
			strDevice += " GPU";
		}
		else
			strDevice = lpGpuEntry->szDevice;

		measurements->gpuName = gcnew System::String(strDevice);

		strBuf.Format(L"%-32s\t : %s\n", "Device", strDevice);
		strEntry += strBuf;
	}

	if (strlen(lpGpuEntry->szDriver))
	{
		strBuf.Format(L"%-32s\t : %s\n", "Driver", lpGpuEntry->szDriver);
		strEntry += strBuf;
	}

	if (strlen(lpGpuEntry->szBIOS))
	{
		strBuf.Format(L"%-32s\t : %s\n", "BIOS", lpGpuEntry->szBIOS);
		strEntry += strBuf;
	}

	if (lpGpuEntry->dwMemAmount)
	{
		strBuf.Format(L"%-32s\t : %d MB\n", "On-board memory", lpGpuEntry->dwMemAmount / 1024);
		strEntry += strBuf;
	}



	return strEntry;
}
/////////////////////////////////////////////////////////////////////////////
void MSIAfterBurnerPlugin::UpdateStatus()
{
	//printf(CT2A(m_strStatus));
}


System::String ^MSIAfterBurnerPlugin::Print()
{
	CString printStr = L"Measurements: (";

	char *buffer = (char *) malloc(100);
	printStr += (CString) this->measurements->time;
	printStr += ")\r\n\r\n";
	printStr += "GPU Name:\t\t";
	printStr += (CString) this->measurements->gpuName;
	sprintf(buffer, "\r\nGPU Temp:\t\t%.2f", this->measurements->gpuTemp);
	printStr += buffer;
	sprintf(buffer, "\r\nGPU Fan Duty:\t\t%.2f", this->measurements->gpuFanPwm); printStr += buffer;
	sprintf(buffer, "\r\nGPU Mem:\t\t%.2f", this->measurements->gpuMemory); printStr += buffer;
	sprintf(buffer, "\r\nGPU Mem Power:\t\t%.2f", this->measurements->gpuMemoryPower); printStr += buffer;
	sprintf(buffer, "\r\nGPU Mem Temp:\t\t%.2f", this->measurements->gpuMemoryTemp); printStr += buffer;
	sprintf(buffer, "\r\nGPU Mem Clock:\t\t%.2f", this->measurements->gpuMemoryClock); printStr += buffer;
	sprintf(buffer, "\r\nGPU Core Clock:\t\t%.2f", this->measurements->gpuCore); printStr += buffer;
	sprintf(buffer, "\r\nGPU Usage:\t\t%.2f", this->measurements->gpuUsage); printStr += buffer;
	sprintf(buffer, "\r\nGPU Power:\t\t%.2f", this->measurements->gpuPower); printStr += buffer;
	sprintf(buffer, "\r\nGPU VRM:\t\t%.2f", this->measurements->gpuVrm); printStr += buffer;
	sprintf(buffer, "\r\nCPU Temp:\t\t%.2f", this->measurements->cpuTemp); printStr += buffer;
	sprintf(buffer, "\r\nCPU Usage:\t\t%.2f", this->measurements->cpuUsage); printStr += buffer;
	sprintf(buffer, "\r\nCPU Fan:\t\t\t%.2f", this->measurements->cpuFan); printStr += buffer;
	sprintf(buffer, "\r\nCPU Power:\t\t%.2f", this->measurements->cpuPower); printStr += buffer;
	sprintf(buffer, "\r\nRAM Usage:\t\t%.2f", this->measurements->ramUsage); printStr += buffer;
	sprintf(buffer, "\r\nPF Usage:\t\t%.2f", this->measurements->pageFileUsage); printStr += buffer;
	sprintf(buffer, "\r\nMotherboard Temp:\t\t%.2f", this->measurements->motherboardTemperature); printStr += buffer;

	printStr += "\r\n\r\n";

	return gcnew System::String(printStr);
}