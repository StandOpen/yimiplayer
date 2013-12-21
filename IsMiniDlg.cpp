// IsMiniDlg.cpp : implementation file
//

#include "stdafx.h"
#include "youyouplayer.h"
#include "IsMiniDlg.h"
#ifdef _DEBUG
#define new DEBUG_NEW
#undef THIS_FILE
static char THIS_FILE[] = __FILE__;
#endif

/////////////////////////////////////////////////////////////////////////////
// IsMiniDlg dialog


IsMiniDlg::IsMiniDlg(CWnd* pParent /*=NULL*/)
	: CDialog(IsMiniDlg::IDD, pParent)
{
	//{{AFX_DATA_INIT(IsMiniDlg)
		// NOTE: the ClassWizard will add member initialization here
	//}}AFX_DATA_INIT
}


void IsMiniDlg::DoDataExchange(CDataExchange* pDX)
{
	CDialog::DoDataExchange(pDX);
	//{{AFX_DATA_MAP(IsMiniDlg)
	DDX_Control(pDX, IDOK, m_yes);
	DDX_Control(pDX, IDCANCEL, m_no);
	//}}AFX_DATA_MAP
}


BEGIN_MESSAGE_MAP(IsMiniDlg, CDialog)
	//{{AFX_MSG_MAP(IsMiniDlg)
	ON_BN_CLICKED(IDC_RADIO1, OnRadio1)
	ON_WM_PAINT()
	ON_WM_CTLCOLOR()
	//}}AFX_MSG_MAP
END_MESSAGE_MAP()

/////////////////////////////////////////////////////////////////////////////
// IsMiniDlg message handlers

void IsMiniDlg::OnRadio1() 
{
	// TODO: Add your control notification handler code here
	char  exepath[MAX_PATH];
    CString  strdir,tempdir; 
    memset(exepath,0,MAX_PATH); 
    GetModuleFileName(NULL,exepath,MAX_PATH); 
    tempdir=exepath; 
    strdir=tempdir.Left(tempdir.ReverseFind('\\'));
	CString IsShow;
	IsShow.Format("%d",0);
   ::WritePrivateProfileString("Main","IsShow",IsShow,strdir+"\\IsMiniDlg.ini");
}

void IsMiniDlg::OnOK() 
{
	// TODO: Add extra validation here
	 char  exepath[MAX_PATH];
    CString  strdir,tempdir; 
    memset(exepath,0,MAX_PATH); 
    GetModuleFileName(NULL,exepath,MAX_PATH); 
    tempdir=exepath; 
    strdir=tempdir.Left(tempdir.ReverseFind('\\'));
	int temp=GetPrivateProfileInt("Main","IsShow",1,strdir+"\\IsMiniDlg.ini");
	if(temp==0)
	{
	CString IsShow;
	IsShow.Format("%d",1);
   ::WritePrivateProfileString("Main","IsShow",IsShow,strdir+"\\IsMiniDlg1.ini");
	}
	CDialog::OnOK();
}

void IsMiniDlg::OnCancel() 
{
	// TODO: Add extra cleanup here
	char  exepath[MAX_PATH];
    CString  strdir,tempdir; 
    memset(exepath,0,MAX_PATH); 
    GetModuleFileName(NULL,exepath,MAX_PATH); 
    tempdir=exepath; 
    strdir=tempdir.Left(tempdir.ReverseFind('\\'));
	int temp=GetPrivateProfileInt("Main","IsShow",1,strdir+"\\IsMiniDlg.ini");
	if(temp==0)
	{
	CString IsShow;
	IsShow.Format("%d",0);
   ::WritePrivateProfileString("Main","IsShow",IsShow,strdir+"\\IsMiniDlg1.ini");
	}
	CDialog::OnCancel();
}

BOOL IsMiniDlg::OnInitDialog() 
{
	CDialog::OnInitDialog();
	
	// TODO: Add extra initialization here
	SetWindowLong(this->GetSafeHwnd(),GWL_EXSTYLE,GetWindowLong(this->GetSafeHwnd(),GWL_EXSTYLE)^0x80000);
    HINSTANCE hInst = LoadLibrary(_T("User32.DLL"));
    if (hInst)
		
    {
        typedef BOOL (WINAPI * MYFUNC)(HWND,COLORREF,BYTE,DWORD);
        MYFUNC fun = NULL;
        fun = (MYFUNC)GetProcAddress(hInst,"SetLayeredWindowAttributes");
        if (fun)
            fun(this->GetSafeHwnd(),RGB(255,0,0),0xCC,2);//0xAA用来控制透明度
        FreeLibrary(hInst);
    }
	return TRUE;  // return TRUE unless you set the focus to a control
	              // EXCEPTION: OCX Property Pages should return FALSE
}

void IsMiniDlg::OnPaint() 
{
	CPaintDC dc(this); // device context for painting
	
	// TODO: Add your message handler code here
	    CRect rect;
        GetClientRect(rect);
        dc.FillSolidRect(rect,RGB(147,112,219));
	// Do not call CDialog::OnPaint() for painting messages
}

HBRUSH IsMiniDlg::OnCtlColor(CDC* pDC, CWnd* pWnd, UINT nCtlColor) 
{
	HBRUSH hbr = CDialog::OnCtlColor(pDC, pWnd, nCtlColor);
	
	// TODO: Change any attributes of the DC here
	
	// TODO: Return a different brush if the default is not desired


	switch(nCtlColor)
{

case CTLCOLOR_STATIC: //静态文本控件
{
pDC->SetBkMode(TRANSPARENT);  
pDC->SetTextColor(RGB(255,0,0)); //设置字体颜色  
return   (HBRUSH)::GetStockObject(NULL_BRUSH);
}
}
	return hbr;
}
