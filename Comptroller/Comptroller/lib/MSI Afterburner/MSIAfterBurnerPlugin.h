// MAHMSharedMemorySampleDlg.h : header file
//

#if !defined(AFX_MAHMSHAREDMEMORYSAMPLEDLG_H__7725E949_F929_49A9_AFBE_468EFA16948B__INCLUDED_)
#define AFX_MAHMSHAREDMEMORYSAMPLEDLG_H__7725E949_F929_49A9_AFBE_468EFA16948B__INCLUDED_

#if _MSC_VER > 1000
#pragma once
#endif // _MSC_VER > 1000

#include "MAHMSharedMemory.h"
#include "resource.h"
#include "../Measurements/Measurements.h"
#include <Windows.h>
#include <atlstr.h>  
#include <atltime.h>

/////////////////////////////////////////////////////////////////////////////
// CMAHMSharedMemorySampleDlg dialog
/////////////////////////////////////////////////////////////////////////////
ref class MSIAfterBurnerPlugin // : public CDialog
{
// Construction
public:
	void UpdateStatus();
	CString		DumpGpuEntry(LPMAHM_SHARED_MEMORY_GPU_ENTRY lpGpuEntry);
	CString		DumpEntry(LPMAHM_SHARED_MEMORY_ENTRY lpEntry);
	void		Disconnect();

	MSIAfterBurnerPlugin(); // CWnd* pParent = NULL);	// standard constructor
	~MSIAfterBurnerPlugin();

	void MSIAfterBurnerPlugin::FetchReadings(void);
	// Dialog Data
	System::String ^Print();

	//enum { IDD = IDD_MSI_AFTERBURNER_PLUGIN };

public:
	Measurements ^ measurements;
// Implementation
protected:
	UINT			m_nTimerID;

	HANDLE			m_hMapFile;
	LPVOID			m_pMapAddr;

	System::String^			m_strStatus;
	System::String^			m_strInstallPath;

	void			Connect();
	void			FetchInstallationPath();

	BOOL			IsSystemSource(DWORD id);
};

//{{AFX_INSERT_LOCATION}}
// Microsoft Visual C++ will insert additional declarations immediately before the previous line.

#endif // !defined(AFX_MAHMSHAREDMEMORYSAMPLEDLG_H__7725E949_F929_49A9_AFBE_468EFA16948B__INCLUDED_)
