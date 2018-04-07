// FOVDisplay.cpp : implementation file
//

#include "stdafx.h"
#include "FOVDisplay.h"
#include "afxdialogex.h"
#include "resource.h"


// FOVDisplay dialog

IMPLEMENT_DYNAMIC(FOVDisplay, CDialog)

FOVDisplay::FOVDisplay(CWnd* pParent /*=NULL*/)
	: CDialog(IDD_FOV_DISPLAY, pParent)
{

}

FOVDisplay::~FOVDisplay()
{
}

void FOVDisplay::DoDataExchange(CDataExchange* pDX)
{
	CDialog::DoDataExchange(pDX);
}


BEGIN_MESSAGE_MAP(FOVDisplay, CDialog)
END_MESSAGE_MAP()


// FOVDisplay message handlers
