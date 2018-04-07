//MFC1.CPP - MFC Tutorial Part 1

#include "stdafx.h"
#include <afxwin.h>
#include <afxdlgs.h>
#include <iostream>
#include <fstream>
#include "resource.h"
#include "MainDialog.h"
#include "Screen.h"
#include "Channel.h"
#include "GrayScale.h"
#include "ChannelDisplay.h"
#include "FOVDisplay.h"
#include "Configuration.h"
#include "Generator.h"
#include "ChannelConfig.h"


Configuration *myConfig = NULL;

class MainFrame :public CFrameWnd
{
private: 
	CMenu MainMenu;
	MainDialog *dlg;
	std::ofstream outFile;
	std::ifstream inFile;

	//IDD_SCREEN:
	int ViewerDistance{ 0 };
	int ScreenHFOV{ 0 };
	int ScreenVFOV{ 0 };
	CString NumberOfChannels{ _T("0") };
	CString ScreenGeometry{ _T("") };

	//IDD_CHANNEL:
	//CString ChannelNumber;
	int ChannelHFOV{ 0 };
	int ChannelVFOV{ 0 };
	int ChannelResolutionL{ 0 };
	int ChannelResolutionR{ 0 };
	int ChannelDistance{ 0 };
	int ChannelPossitionL{ 0 };
	int ChannelPossitionR{ 0 };
	CString ChannelIP{ _T("0") };
	CString ChannelNumberChange{ _T("TEST") };

public:
	MainFrame()
	{
		Create(NULL, _T("Design Tool"), WS_OVERLAPPEDWINDOW, CRect(300,300,2000,1500));
		MainMenu.LoadMenu(IDR_MENU);
		SetMenu(&MainMenu);
	}

	DECLARE_MESSAGE_MAP()
	afx_msg void OnFileNew();
	afx_msg void OnBnClickedButton2();
	afx_msg void OnFileOpen();
	afx_msg void OnConfigurationScreen();
	afx_msg void OnConfigurationChannel();
	afx_msg void OnChannelChannel1();
	afx_msg void OnChannelChannel2();
	afx_msg void OnTestpatternsGrayscale();
	afx_msg void OnBnClickedButtonDisplayFov();
	afx_msg void OnDisplayChannels();
	afx_msg void OnDisplayFov();
	afx_msg void OnFileSave();
};

BEGIN_MESSAGE_MAP(MainFrame, CFrameWnd)
ON_COMMAND(ID_FILE_NEW, &MainFrame::OnFileNew)
ON_BN_CLICKED(IDC_BUTTON2, &MainFrame::OnBnClickedButton2)
ON_COMMAND(ID_FILE_OPEN, &MainFrame::OnFileOpen)
ON_WM_PAINT()
ON_COMMAND(ID_CONFIGURATION_SCREEN, &MainFrame::OnConfigurationScreen)
ON_COMMAND(ID_CONFIGURATION_CHANNEL, &MainFrame::OnConfigurationChannel)
ON_COMMAND(ID_CHANNEL_CHANNEL1, &MainFrame::OnChannelChannel1)
ON_COMMAND(ID_CHANNEL_CHANNEL2, &MainFrame::OnChannelChannel2)
ON_COMMAND(ID_TESTPATTERNS_GRAYSCALE, &MainFrame::OnTestpatternsGrayscale)
ON_BN_CLICKED(ID_BUTTON_DISPLAY_FOV, &MainFrame::OnBnClickedButtonDisplayFov)
ON_COMMAND(ID_DISPLAY_CHANNELS, &MainFrame::OnDisplayChannels)
ON_COMMAND(ID_DISPLAY_FOV, &MainFrame::OnDisplayFov)
ON_COMMAND(ID_FILE_SAVE, &MainFrame::OnFileSave)
END_MESSAGE_MAP()

class MyApp :public CWinApp
{
	MainFrame *wnd;
public:
	GdiplusStartupInput gdiplusStartupInput;
	ULONG_PTR gdiplusToken;

	BOOL InitInstance()
	{
		wnd = new MainFrame();
		m_pMainWnd = wnd;
		m_pMainWnd->ShowWindow(SW_SHOW);
		m_pMainWnd->UpdateWindow();
		GdiplusStartup(&gdiplusToken, &gdiplusStartupInput, NULL);
		return TRUE;
	}
	//MAYBE ADD THE BOOL ECITINSTANCE???
	/*
	BOOL ExitInstancs()
	{
	delete myConfig;
	GdiplusShutdown(gdiplusToken);
	return TRUE;
	}
	*/
};

MyApp theApp;

void MainFrame::OnFileNew()
{
	myConfig = new Configuration();
}


void MainFrame::OnBnClickedButton2()
{

}


void MainFrame::OnFileOpen()
{
	CFileDialog openDlg(TRUE, NULL, NULL,
		OFN_HIDEREADONLY | OFN_FILEMUSTEXIST, _T("txt Files(*.txt)|*.txt||"), this);
	if (openDlg.DoModal() == IDOK) {
		inFile.open(openDlg.GetPathName(), std::ios::in);
		myConfig = new Configuration(inFile);
		inFile.close();
	}
}

void MainFrame::OnFileSave()
{
	if (myConfig == NULL) {
		MessageBox(_T("No Configuration to save"));
		return;
	}
	CFileDialog saveDlg(FALSE, NULL, NULL,
		OFN_HIDEREADONLY | OFN_OVERWRITEPROMPT, _T("txt Files(*.txt)|*.txt||"), this);
	if (saveDlg.DoModal() == IDOK) {
		outFile.open(saveDlg.GetPathName(), std::ios::out);
		myConfig->output_config_file(outFile);
		outFile.close();
	}
}


void MainFrame::OnConfigurationScreen()
{
	Screen dlg;
	dlg.ViewerDistance = myConfig->get_viewer_distance();
	dlg.ScreenGeometry = ScreenGeometry;
	dlg.ScreenHFOV = myConfig->get_total_fov_h();
	dlg.ScreenVFOV = myConfig->get_total_fov_v();
	//dlg.NumberOfChannels = myConfig->get_num_channels();
	
	if (dlg.DoModal() == IDOK)
	{
						//ViewerDistance = dlg.ViewerDistance;
		myConfig->set_viewer_distance(dlg.ViewerDistance);
		ScreenGeometry = dlg.ScreenGeometry;
		myConfig->set_total_fov_h(dlg.ScreenHFOV);
		myConfig->set_total_fov_v(dlg.ScreenVFOV);
					//myConfig->set_num_channels(dlg.NumberOfChannels);
	}
	//Invalidate();
	//UpdateWindow();
	
}


void MainFrame::OnConfigurationChannel()
{
	//DO NOTHING CHANNEL
}


void MainFrame::OnChannelChannel1()
{
	Channel dlg;

	dlg.ChannelHFOV = myConfig->get_channels().at(0).get_fov_h();
	dlg.ChannelVFOV = myConfig->get_channels().at(0).get_fov_v();
	dlg.ChannelResolutionL = ChannelResolutionL;		//DONT HAVE in CONFIG
	dlg.ChannelResolutionR = ChannelResolutionR;		//DONT HAVE in CONFIG
	dlg.ChannelDistance = ChannelDistance;			//DONT HAVE in CONFIG
	dlg.ChannelIP = ChannelIP;		//DONT HAVE in CONFIG
	dlg.ChannelPossitionL = myConfig->get_channels().at(0).get_location_h();
	dlg.ChannelPossitionR = myConfig->get_channels().at(0).get_location_v();

	dlg.ChannelNumberChange = _T("Channel Number : 1");

	if (dlg.DoModal() == IDOK)
	{
		myConfig->get_channels().at(0).set_fov_h(dlg.ChannelHFOV);
		myConfig->get_channels().at(0).set_fov_v(dlg.ChannelVFOV);
		ChannelResolutionL = dlg.ChannelResolutionL;
		ChannelResolutionR = dlg.ChannelResolutionR;
		ChannelDistance = dlg.ChannelDistance;
		ChannelIP = dlg.ChannelIP;
		myConfig->get_channels().at(0).set_location_h(dlg.ChannelPossitionL);
		myConfig->get_channels().at(0).set_location_v(dlg.ChannelPossitionR);
	}

}


void MainFrame::OnChannelChannel2()
{
	Channel dlg;
	
	dlg.ChannelHFOV = myConfig->get_channels().at(1).get_fov_h();
	dlg.ChannelVFOV = myConfig->get_channels().at(1).get_fov_v();
	dlg.ChannelResolutionL = ChannelResolutionL;		//DONT HAVE in CONFIG
	dlg.ChannelResolutionR = ChannelResolutionR;		//DONT HAVE in CONFIG
	dlg.ChannelDistance = ChannelDistance;			//DONT HAVE in CONFIG
	dlg.ChannelIP = ChannelIP;		//DONT HAVE in CONFIG
	dlg.ChannelPossitionL = myConfig->get_channels().at(1).get_location_h();
	dlg.ChannelPossitionR = myConfig->get_channels().at(1).get_location_v();

	dlg.ChannelNumberChange = _T("Channel Number : 2");

	if (dlg.DoModal() == IDOK)
	{
		myConfig->get_channels().at(1).set_fov_h(dlg.ChannelHFOV);
		myConfig->get_channels().at(1).set_fov_v(dlg.ChannelVFOV);
		ChannelResolutionL = dlg.ChannelResolutionL;
		ChannelResolutionR = dlg.ChannelResolutionR;
		ChannelDistance = dlg.ChannelDistance;
		ChannelIP = dlg.ChannelIP;
		myConfig->get_channels().at(1).set_location_h(dlg.ChannelPossitionL);
		myConfig->get_channels().at(1).set_location_v(dlg.ChannelPossitionR);
	}

}


void MainFrame::OnTestpatternsGrayscale()
{
	GrayScale dlg;
	dlg.DoModal();

	//GrayScale dlg;
	//INT_PTR nRet = -1;
	//nRet = dlg.DoModal();
	
	/*GrayScale *dlg;
	dlg = new GrayScale;
	dlg->Create(IDD_GRAY_SCALE);
	dlg->ShowWindow(1); 

	if (dlg->ID_BUTTON_DISPLAY_FOV)
	{
		dlg->EndDialog(IDD_GRAY_SCALE);

	}*/

	/*switch (nRet = dlg.DoModal())
	{
	case -1:
		AfxMessageBox(_T("Dialog box could not be created!"));
		break;
	case IDOK:
		//MessageBox(_T("Clicked New"));
		break;
	case IDCANCEL:
		//MessageBox(_T("Clicked New"));
		break;
	case ID_BUTTON_DISPLAY_FOV:
		MessageBox(_T("Clicked New"));
		MessageBox(_T("Dialog box could not be created!"));
		break;
	default:
		break;
	}*/
}


void MainFrame::OnBnClickedButtonDisplayFov()
{
	//EndDialog(IDD_GRAY_SCALE);
	//CFrameWnd::OnOK();
	//ChannelDisplay* GetParent() const;
	//ChannelDisplay dlg2(const);
	//dlg2.DoModal();
}


void MainFrame::OnDisplayChannels()
{
	Generator dlg(NULL, FALSE, myConfig);
	dlg.DoModal();
}


void MainFrame::OnDisplayFov()
{
	Generator dlg(NULL, TRUE, myConfig);
	dlg.DoModal();
}
