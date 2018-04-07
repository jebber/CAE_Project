#pragma once


// Screen dialog

class Screen : public CDialog
{
	DECLARE_DYNAMIC(Screen)

public:
	Screen(CWnd* pParent = NULL);   // standard constructor
	virtual ~Screen();

// Dialog Data
#ifdef AFX_DESIGN_TIME
	enum { IDD = IDD_SCREEN };
#endif

protected:
	virtual void DoDataExchange(CDataExchange* pDX);    // DDX/DDV support

	DECLARE_MESSAGE_MAP()
public:
	int ViewerDistance;
	afx_msg void OnCbnSelchangeComboboxex1();
	afx_msg void OnCbnSelchangeCombo3();
	CString ScreenGeometry;
	afx_msg void OnStnClickedScreenVfov();
	afx_msg void OnCbnSelchangeScreenGeometry();
	int ScreenHFOV;
	int ScreenVFOV;
	CString NumberOfChannels;
	afx_msg void OnCbnSelchangeNumberOfChannels();
};
