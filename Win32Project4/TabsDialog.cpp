// TabsDialog.cpp : implementation file
//

#include "stdafx.h"
#include "TabsDialog.h"
#include "Tab1.h"
#include "Tab2.h"


// TabsDialog

IMPLEMENT_DYNAMIC(TabsDialog, CPropertySheet)

TabsDialog::TabsDialog(UINT nIDCaption, CWnd* pParentWnd, UINT iSelectPage)
	:CPropertySheet(nIDCaption, pParentWnd, iSelectPage)
{
	AddPage(&tab1);
	AddPage(&tab2);

}

TabsDialog::TabsDialog(LPCTSTR pszCaption, CWnd* pParentWnd, UINT iSelectPage)
	:CPropertySheet(pszCaption, pParentWnd, iSelectPage)
{

}

TabsDialog::~TabsDialog()
{
}


BEGIN_MESSAGE_MAP(TabsDialog, CPropertySheet)
END_MESSAGE_MAP()


// TabsDialog message handlers
