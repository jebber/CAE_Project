// GrayScale.cpp : implementation file
//

#include "stdafx.h"
#include "GrayScale.h"
#include "afxdialogex.h"
#include "resource.h"


// GrayScale dialog

IMPLEMENT_DYNAMIC(GrayScale, CDialog)

GrayScale::GrayScale(CWnd* pParent /*=NULL*/)
	: CDialog(IDD_GRAY_SCALE, pParent)
{

}

GrayScale::~GrayScale()
{
}

void GrayScale::DoDataExchange(CDataExchange* pDX)
{
	CDialog::DoDataExchange(pDX);
}


BEGIN_MESSAGE_MAP(GrayScale, CDialog)
END_MESSAGE_MAP()


// GrayScale message handlers
