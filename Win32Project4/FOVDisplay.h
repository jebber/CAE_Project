#pragma once


// FOVDisplay dialog

class FOVDisplay : public CDialog
{
	DECLARE_DYNAMIC(FOVDisplay)

public:
	FOVDisplay(CWnd* pParent = NULL);   // standard constructor
	virtual ~FOVDisplay();

// Dialog Data
#ifdef AFX_DESIGN_TIME
	enum { IDD = IDD_FOV_DISPLAY };
#endif

protected:
	virtual void DoDataExchange(CDataExchange* pDX);    // DDX/DDV support

	DECLARE_MESSAGE_MAP()
};
