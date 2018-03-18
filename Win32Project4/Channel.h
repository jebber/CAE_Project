#pragma once


// Channel dialog

class Channel : public CDialog
{
	DECLARE_DYNAMIC(Channel)

public:
	Channel(CWnd* pParent = NULL);   // standard constructor
	virtual ~Channel();

// Dialog Data
#ifdef AFX_DESIGN_TIME
	enum { IDD = IDD_CHANNEL };
#endif

protected:
	virtual void DoDataExchange(CDataExchange* pDX);    // DDX/DDV support

	DECLARE_MESSAGE_MAP()
public:
	afx_msg void OnBnClickedOk();
	//afx_msg void OnCbnSelchangeCombo1();
	CString ChannelNumber;
	int ChannelHFOV;
	int ChannelVFOV;
	int ChannelResolutionL;
	int ChannelResolutionR;
	int ChannelDistance;
	CString ChannelIP;
	afx_msg void OnEnChangeChannelIp();
	afx_msg void OnChannelChannel1();
	afx_msg void OnChannelChannel2();
	CString ChannelNumberChange;
	int ChannelPossitionL;
	int ChannelPossitionR;
};
