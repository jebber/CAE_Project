#pragma once

#include "stdafx.h"
#include "Tab1.h"
#include "Tab2.h"

// TabsDialog

class TabsDialog : public CPropertySheet
{
	DECLARE_DYNAMIC(TabsDialog)

public:

	TabsDialog(UINT nIDCaption, CWnd* pParentWnd = NULL, UINT iSelectPage = 0);
	TabsDialog(LPCTSTR pszCaption, CWnd* pParentWnd = NULL, UINT iSelectPage = 0);
	virtual ~TabsDialog();

protected:
	Tab1 tab1;
	Tab2 tab2;

	DECLARE_MESSAGE_MAP()
};


