// ChannelDisplay.cpp : implementation file
//

#include "stdafx.h"
#include "ChannelDisplay.h"
#include "afxdialogex.h"
#include "resource.h"


// ChannelDisplay dialog

IMPLEMENT_DYNAMIC(ChannelDisplay, CDialog)

ChannelDisplay::ChannelDisplay(CWnd* pParent /*=NULL*/)
	: CDialog(IDD_CHANNEL_DISPLAY, pParent)
{

}

ChannelDisplay::~ChannelDisplay()
{
}

void ChannelDisplay::DoDataExchange(CDataExchange* pDX)
{
	CDialog::DoDataExchange(pDX);
}


BEGIN_MESSAGE_MAP(ChannelDisplay, CDialog)
END_MESSAGE_MAP()


// ChannelDisplay message handlers
