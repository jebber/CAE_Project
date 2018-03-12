#pragma once


// Tab2 dialog

class Tab2 : public CPropertyPage
{
	DECLARE_DYNAMIC(Tab2)

public:
	Tab2();
	virtual ~Tab2();

// Dialog Data
#ifdef AFX_DESIGN_TIME
	enum { IDD = IDD_TAB2 };
#endif

protected:
	virtual void DoDataExchange(CDataExchange* pDX);    // DDX/DDV support

	DECLARE_MESSAGE_MAP()
};
