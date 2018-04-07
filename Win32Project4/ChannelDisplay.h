#pragma once


// ChannelDisplay dialog

class ChannelDisplay : public CDialog
{
	DECLARE_DYNAMIC(ChannelDisplay)

public:
	ChannelDisplay(CWnd* pParent = NULL);   // standard constructor
	virtual ~ChannelDisplay();

// Dialog Data
#ifdef AFX_DESIGN_TIME
	enum { IDD = IDD_CHANNEL_DISPLAY };
#endif

protected:
	virtual void DoDataExchange(CDataExchange* pDX);    // DDX/DDV support

	DECLARE_MESSAGE_MAP()
};
