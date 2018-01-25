// MAHMSharedMemorySampleDlg.cpp : implementation file
//
// created by Unwinder
/////////////////////////////////////////////////////////////////////////////
#include "../../StdAfx.h"
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

	m_hMapFile = OpenFileMapping(FILE_MAP_ALL_ACCESS, FALSE, "MAHMSharedMemory");

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
void MSIAfterBurnerPlugin::FetchReadings(Measurements *destination)
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
			CString strBuf = time.Format("%d-%m-%Y %H:%M:%S");
				//format data polling time
			destination->time = time; // time.Format("%d-%m-%Y %H:%M:%S");

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

					CString strStatus = DumpGpuEntry(lpGpuEntry, destination);

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

						strStatus += DumpEntry(lpEntry, destination);
							//dump data source entry
					}

					if (!strStatus.IsEmpty())
					{
						strBuf.Format("GPU%d\n", dwGpu + 1);
							//keep in mind that GPU indices are 0-based, so we need to correct index when
							//formatting the GPU section header 

						m_strStatus += strBuf;
						m_strStatus += strStatus;
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

					strStatus += DumpEntry(lpEntry, destination);
						//dump data source entry
				}

				if (!strStatus.IsEmpty())
				{
					m_strStatus += "Global\n";
					m_strStatus += strStatus;
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

					m_strStatus += DumpEntry(lpEntry, destination);
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
		if (m_strInstallPath.IsEmpty())
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
CString MSIAfterBurnerPlugin::DumpEntry(LPMAHM_SHARED_MEMORY_ENTRY lpEntry, Measurements *destination)
{
	CString strValue;

	if (lpEntry->data == FLT_MAX)
		strValue = "N/A";
	else
	{
		if (strcmp(lpEntry->szSrcName, "Motherboard temperature") == 0)
			destination->motherboardTemperature = lpEntry->data;
		else if ((strcmp(lpEntry->szSrcName, "GPU1 temperature") == 0) || (strcmp(lpEntry->szSrcName, "GPU temperature") == 0))
			destination->gpuTemp = lpEntry->data;
		else if ((strcmp(lpEntry->szSrcName, "GPU1 memory temperature") == 0) || (strcmp(lpEntry->szSrcName, "Memory temperature") == 0))
			destination->gpuMemoryTemp = lpEntry->data;
		else if ((strcmp(lpEntry->szSrcName, "GPU1 usage") == 0) || (strcmp(lpEntry->szSrcName, "GPU usage") == 0))
			destination->gpuUsage = lpEntry->data;
		else if ((strcmp(lpEntry->szSrcName, "GPU1 power") == 0) || (strcmp(lpEntry->szSrcName, "GPU power") == 0))
			destination->gpuPower = lpEntry->data;
		else if ((strcmp(lpEntry->szSrcName, "GPU1 memory usage") == 0) || (strcmp(lpEntry->szSrcName, "Memory usage") == 0))
			destination->gpuMemory = lpEntry->data;
		else if ((strcmp(lpEntry->szSrcName, "GPU1 core clock") == 0) || (strcmp(lpEntry->szSrcName, "Core clock") == 0))
			destination->gpuCore = lpEntry->data;
		else if ((strcmp(lpEntry->szSrcName, "GPU1 memory clock") == 0) || (strcmp(lpEntry->szSrcName, "Memory clock") == 0))
			destination->gpuMemoryClock = lpEntry->data;
		else if (strcmp(lpEntry->szSrcName, "GPU voltage") == 0)
			destination->gpuVoltage = lpEntry->data;
		else if (strcmp(lpEntry->szSrcName, "Power") == 0)
			destination->gpuPower = lpEntry->data;
		else if (strcmp(lpEntry->szSrcName, "Fan tachometer") == 0)
			destination->gpuFanPwm = lpEntry->data;
		else if (strcmp(lpEntry->szSrcName, "CPU temperature") == 0)
			destination->cpuTemp = lpEntry->data;
		else if (strcmp(lpEntry->szSrcName, "CPU usage") == 0)
			destination->cpuUsage = lpEntry->data;
		else if (strcmp(lpEntry->szSrcName, "RAM usage") == 0)
			destination->ramUsage = lpEntry->data;
		else if (strcmp(lpEntry->szSrcName, "Pagefile usage") == 0)
			destination->pageFileUsage = lpEntry->data;
	
		strValue.Format(lpEntry->szRecommendedFormat, lpEntry->data); // this is the name
		strValue += " ";
		strValue += lpEntry->szLocalizedSrcUnits; // this is the value
	}

	printf("\n%s\n", strValue);
	CString strEntry;

	strEntry.Format("%-32s\t : %-16s\t", lpEntry->szLocalizedSrcName, strValue);

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
CString MSIAfterBurnerPlugin::DumpGpuEntry(LPMAHM_SHARED_MEMORY_GPU_ENTRY lpGpuEntry, Measurements *destination)
{
	CString strEntry;
	CString strBuf;

	strBuf.Format("%-32s\t : %-16s\n", "GUID", lpGpuEntry->szGpuId);
	//strEntry += strBuf;

	if (strlen(lpGpuEntry->szDevice))
	{
		CString strDevice;

		if (strlen(lpGpuEntry->szFamily))
			strDevice.Format("%s on %s GPU", lpGpuEntry->szDevice, lpGpuEntry->szFamily);
		else
			strDevice = lpGpuEntry->szDevice;

		destination->gpuName = strDevice;

		strBuf.Format("%-32s\t : %s\n", "Device", strDevice);
		strEntry += strBuf;
	}

	if (strlen(lpGpuEntry->szDriver))
	{
		strBuf.Format("%-32s\t : %s\n", "Driver", lpGpuEntry->szDriver);
		strEntry += strBuf;
	}

	if (strlen(lpGpuEntry->szBIOS))
	{
		strBuf.Format("%-32s\t : %s\n", "BIOS", lpGpuEntry->szBIOS);
		strEntry += strBuf;
	}

	if (lpGpuEntry->dwMemAmount)
	{
		strBuf.Format("%-32s\t : %d MB\n", "On-board memory", lpGpuEntry->dwMemAmount / 1024);
		strEntry += strBuf;
	}



	return strEntry;
}
/////////////////////////////////////////////////////////////////////////////
void MSIAfterBurnerPlugin::UpdateStatus()
{
	printf(m_strStatus);
}

