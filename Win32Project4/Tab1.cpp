// Tab1.cpp : implementation file
//

#include "stdafx.h"
#include "Tab1.h"
#include "afxdialogex.h"
#include "resource.h"

// Tab1 dialog

IMPLEMENT_DYNAMIC(Tab1, CPropertyPage)

Tab1::Tab1()
	: CPropertyPage(IDD_TAB1)
{

}

Tab1::~Tab1()
{
}

void Tab1::DoDataExchange(CDataExchange* pDX)
{
	CPropertyPage::DoDataExchange(pDX);
}


BEGIN_MESSAGE_MAP(Tab1, CPropertyPage)
END_MESSAGE_MAP()


// Tab1 message handlers
