//MFC1.CPP - MFC Tutorial Part 1

#include <afxwin.h>
#include "resource.h"
#include "MainDialog.h"
#include "TabsDialog.h"

class MainFrame :public CFrameWnd
{
private: 
	CMenu MainMenu;
	MainDialog *dlg;
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
};

BEGIN_MESSAGE_MAP(MainFrame, CFrameWnd)
ON_COMMAND(ID_FILE_NEW, &MainFrame::OnFileNew)
ON_BN_CLICKED(IDC_BUTTON2, &MainFrame::OnBnClickedButton2)
ON_COMMAND(ID_FILE_OPEN, &MainFrame::OnFileOpen)
ON_WM_PAINT()
END_MESSAGE_MAP()

class MyApp :public CWinApp
{
	MainFrame *wnd;
public:
	BOOL InitInstance()
	{
		wnd = new MainFrame();
		m_pMainWnd = wnd;
		m_pMainWnd->ShowWindow(SW_SHOW);
		m_pMainWnd->UpdateWindow();
		return TRUE;
	}
};

MyApp theApp
;

void MainFrame::OnFileNew()
{
	//MessageBox(_T("Clicked New"));

	MainDialog *dlg;
	dlg = new MainDialog;
	dlg->Create(IDD_MAINDIALOG);
	dlg->ShowWindow(1);
}


void MainFrame::OnBnClickedButton2()
{

}


void MainFrame::OnFileOpen()
{
	// TODO: Add your command handler code here
}
