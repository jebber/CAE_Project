// MainDialog.cpp : implementation file
//

#include "stdafx.h"
#include "MainDialog.h"
#include "afxdialogex.h"
#include "resource.h"


// MainDialog dialog

IMPLEMENT_DYNAMIC(MainDialog, CDialog)

MainDialog::MainDialog(CWnd* pParent /*= NULL*/)
	: CDialog(IDD_MAINDIALOG, pParent)
{

}

MainDialog::~MainDialog()
{
}

void MainDialog::DoDataExchange(CDataExchange* pDX)
{
	CDialog::DoDataExchange(pDX);
}


BEGIN_MESSAGE_MAP(MainDialog, CDialog)
END_MESSAGE_MAP()


// MainDialog message handlers
