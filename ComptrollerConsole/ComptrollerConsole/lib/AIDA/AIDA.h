// MAHMSharedMemorySampleDlg.h : header file
//

#pragma once

#if _MSC_VER > 1000
#pragma once
#endif // _MSC_VER > 1000

#include "MAHMSharedMemory.h"
#include "resource.h"
#include "../Measurements/Measurements.h"

/////////////////////////////////////////////////////////////////////////////
// CMAHMSharedMemorySampleDlg dialog
/////////////////////////////////////////////////////////////////////////////
class AIDA // : public CDialog
{
// Construction
public:
	/*void UpdateStatus();
	CString		DumpGpuEntry(LPMAHM_SHARED_MEMORY_GPU_ENTRY lpGpuEntry, Measurements *destination);
	CString		DumpEntry(LPMAHM_SHARED_MEMORY_ENTRY lpEntry, Measurements *destination);*/
	void		Disconnect();

	AIDA(); // CWnd* pParent = NULL);	// standard constructor
	~AIDA();

	void AIDA::FetchReadings(Measurements *destination);
	// Dialog Data

	enum { IDD = IDD_MSI_AFTERBURNER_PLUGIN };

// Implementation
protected:
	UINT			m_nTimerID;

	HANDLE			m_hMapFile;
	LPVOID			m_pMapAddr;

	CString			m_strStatus;
	CString			m_strInstallPath;

	void			Connect();
	void			FetchInstallationPath();

	BOOL			IsSystemSource(DWORD id);
};

//{{AFX_INSERT_LOCATION}}
// Microsoft Visual C++ will insert additional declarations immediately before the previous line.

// #endif // !defined(AFX_MAHMSHAREDMEMORYSAMPLEDLG_H__7725E949_F929_49A9_AFBE_468EFA16948B__INCLUDED_)
