#pragma once


// GrayScale dialog

class GrayScale : public CDialog
{
	DECLARE_DYNAMIC(GrayScale)

public:
	GrayScale(CWnd* pParent = NULL);   // standard constructor
	virtual ~GrayScale();

// Dialog Data
#ifdef AFX_DESIGN_TIME
	enum { IDD = IDD_GRAY_SCALE };
#endif

protected:
	virtual void DoDataExchange(CDataExchange* pDX);    // DDX/DDV support

	DECLARE_MESSAGE_MAP()
};
