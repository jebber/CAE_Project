// Channel.cpp : implementation file
//

#include "stdafx.h"
#include "Channel.h"
#include "afxdialogex.h"
#include "resource.h"

// Channel dialog

IMPLEMENT_DYNAMIC(Channel, CDialog)

Channel::Channel(CWnd* pParent /*=NULL*/)
	: CDialog(IDD_CHANNEL, pParent)
	, ChannelNumber(_T(""))
	, ChannelHFOV(0)
	, ChannelVFOV(0)
	, ChannelResolutionL(0)
	, ChannelResolutionR(0)
	, ChannelDistance(0)
	, ChannelIP(_T("TEST TEST TEST"))
	, ChannelNumberChange(_T(""))
	, ChannelPossitionL(0)
	, ChannelPossitionR(0)
{

}

Channel::~Channel()
{
}

void Channel::DoDataExchange(CDataExchange* pDX)
{
	CDialog::DoDataExchange(pDX);
	//DDX_CBString(pDX, IDC_CHANNEL_NUMBER, ChannelNumber);
	//DDV_MaxChars(pDX, ChannelNumber, 99);
	DDX_Text(pDX, IDC_CHANNEL_HFOV, ChannelHFOV);
	DDV_MinMaxInt(pDX, ChannelHFOV, -9999, 9999);
	DDX_Text(pDX, IDC_CHANNEL_VFOC, ChannelVFOV);
	DDV_MinMaxInt(pDX, ChannelVFOV, -9999, 9999);
	DDX_Text(pDX, IDC_CHANNEL_RESOLUTION_L, ChannelResolutionL);
	DDV_MinMaxInt(pDX, ChannelResolutionL, -99999, 99999);
	DDX_Text(pDX, IDC_CHANNEL_RESOLUTION_R, ChannelResolutionR);
	DDV_MinMaxInt(pDX, ChannelResolutionR, -99999, 99999);
	DDX_Text(pDX, IDC_CHANNEL_DISTANCE_TO_SCREEN, ChannelDistance);
	DDV_MinMaxInt(pDX, ChannelDistance, -9999, 9999);
	DDX_Text(pDX, IDC_CHANNEL_IP, ChannelIP);
	DDV_MaxChars(pDX, ChannelIP, 99);
	DDX_Text(pDX, IDC_STATIC_CHANNEL_NUMBER, ChannelNumberChange);
	DDV_MaxChars(pDX, ChannelNumberChange, 99);
	DDX_Text(pDX, IDC_CHANNEL_POSSITION_L, ChannelPossitionL);
	DDV_MinMaxInt(pDX, ChannelPossitionL, -9999, 9999);
	DDX_Text(pDX, IDC_CHANNEL_POSSITION_R, ChannelPossitionR);
	DDV_MinMaxInt(pDX, ChannelPossitionR, -9999, 9999);
}


BEGIN_MESSAGE_MAP(Channel, CDialog)
	ON_BN_CLICKED(IDOK, &Channel::OnBnClickedOk)
	//ON_CBN_SELCHANGE(IDC_CHANNEL_NUMBER, &Channel::OnCbnSelchangeCombo1)
	ON_EN_CHANGE(IDC_CHANNEL_IP, &Channel::OnEnChangeChannelIp)
	ON_COMMAND(ID_CHANNEL_CHANNEL1, &Channel::OnChannelChannel1)
	ON_COMMAND(ID_CHANNEL_CHANNEL2, &Channel::OnChannelChannel2)
END_MESSAGE_MAP()


// Channel message handlers


void Channel::OnBnClickedOk()
{
	// TODO: Add your control notification handler code here
	CDialog::OnOK();
}

/*
void Channel::OnCbnSelchangeCombo1()
{
	// TODO: Add your control notification handler code here
}
*/

void Channel::OnEnChangeChannelIp()
{
	// TODO:  If this is a RICHEDIT control, the control will not
	// send this notification unless you override the CDialog::OnInitDialog()
	// function and call CRichEditCtrl().SetEventMask()
	// with the ENM_CHANGE flag ORed into the mask.

	// TODO:  Add your control notification handler code here
}


void Channel::OnChannelChannel1()
{
	// TODO: Add your command handler code here
}


void Channel::OnChannelChannel2()
{
	// TODO: Add your command handler code here
}
