// Screen.cpp : implementation file
//

#include "stdafx.h"
#include "Screen.h"
#include "afxdialogex.h"
#include "resource.h"


// Screen dialog

IMPLEMENT_DYNAMIC(Screen, CDialog)

Screen::Screen(CWnd* pParent /*=NULL*/)
	: CDialog(IDD_SCREEN, pParent)
	, ViewerDistance(0)
	, ScreenGeometry(_T(""))
	, ScreenHFOV(0)
	, ScreenVFOV(0)
	, NumberOfChannels(_T(""))
{

}

Screen::~Screen()
{
}

void Screen::DoDataExchange(CDataExchange* pDX)
{
	CDialog::DoDataExchange(pDX);
	DDX_Text(pDX, IDC_VIEWER_DISTANCE, ViewerDistance);
	DDV_MinMaxInt(pDX, ViewerDistance, 0, 9999);
	DDX_CBString(pDX, IDC_SCREEN_GEOMETRY, ScreenGeometry);
	DDV_MaxChars(pDX, ScreenGeometry, 15);
	DDX_Text(pDX, IDC__SCREEN_HFOV, ScreenHFOV);
	DDV_MinMaxInt(pDX, ScreenHFOV, 0, 99999);
	DDX_Text(pDX, IDC_SCREEN_VFOV, ScreenVFOV);
	DDV_MinMaxInt(pDX, ScreenVFOV, 0, 99999);
	DDX_CBString(pDX, IDC_NUMBER_OF_CHANNELS, NumberOfChannels);
	DDV_MaxChars(pDX, NumberOfChannels, 15);
}


BEGIN_MESSAGE_MAP(Screen, CDialog)
//	ON_CBN_SELCHANGE(IDC_COMBOBOXEX1, &Screen::OnCbnSelchangeComboboxex1)
	//ON_CBN_SELCHANGE(IDC_COMBO3, &Screen::OnCbnSelchangeCombo3)
	ON_STN_CLICKED(IDC_SCREEN_VFOV, &Screen::OnStnClickedScreenVfov)
	ON_CBN_SELCHANGE(IDC_SCREEN_GEOMETRY, &Screen::OnCbnSelchangeScreenGeometry)
	ON_CBN_SELCHANGE(IDC_NUMBER_OF_CHANNELS, &Screen::OnCbnSelchangeNumberOfChannels)
END_MESSAGE_MAP()


// Screen message handlers


void Screen::OnCbnSelchangeComboboxex1()
{
	// TODO: Add your control notification handler code here
}


void Screen::OnCbnSelchangeCombo3()
{
	// TODO: Add your control notification handler code here
}


void Screen::OnStnClickedScreenVfov()
{
	// TODO: Add your control notification handler code here
}


void Screen::OnCbnSelchangeScreenGeometry()
{
	// TODO: Add your control notification handler code here
}


void Screen::OnCbnSelchangeNumberOfChannels()
{
	// TODO: Add your control notification handler code here
}
