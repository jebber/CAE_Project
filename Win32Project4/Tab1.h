#pragma once


// Tab1 dialog

class Tab1 : public CPropertyPage
{
	DECLARE_DYNAMIC(Tab1)

public:
	Tab1();
	virtual ~Tab1();

// Dialog Data
#ifdef AFX_DESIGN_TIME
	enum { IDD = IDD_PROPPAGE_SMALL };
#endif

protected:
	virtual void DoDataExchange(CDataExchange* pDX);    // DDX/DDV support

	DECLARE_MESSAGE_MAP()
};
