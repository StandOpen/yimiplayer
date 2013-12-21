// LrcDlg.cpp : implementation file
//

#include "stdafx.h"
#include "YouYouPlayer.h"
#include "LrcDlg.h"

#ifdef _DEBUG
#define new DEBUG_NEW
#undef THIS_FILE
static char THIS_FILE[] = __FILE__;
#endif

/////////////////////////////////////////////////////////////////////////////
// LrcDlg dialog


LrcDlg::LrcDlg(CWnd* pParent /*=NULL*/)
	: CDialog(LrcDlg::IDD, pParent)
{
	//{{AFX_DATA_INIT(LrcDlg)
	//}}AFX_DATA_INIT
}


void LrcDlg::DoDataExchange(CDataExchange* pDX)
{
	CDialog::DoDataExchange(pDX);
	//{{AFX_DATA_MAP(LrcDlg)
	//}}AFX_DATA_MAP
}


BEGIN_MESSAGE_MAP(LrcDlg, CDialog)
	//{{AFX_MSG_MAP(LrcDlg)
	ON_WM_TIMER()
	ON_WM_CTLCOLOR()
	ON_WM_PAINT()
	ON_WM_LBUTTONDOWN()
	ON_WM_LBUTTONUP()
	ON_WM_MOUSEMOVE()
	//}}AFX_MSG_MAP
END_MESSAGE_MAP()

/////////////////////////////////////////////////////////////////////////////
// LrcDlg message handlers

BOOL LrcDlg::OnInitDialog() 
{
	CDialog::OnInitDialog();
	
	// TODO: Add extra initialization here
	CString path;
	path=strpath.Left(strpath.GetLength()-4)+".lrc";
	CFileStatus status;
	if(!CFile::GetStatus(path,status))
	{
		strlrc="没有找到匹配的歌词文件...";
	
	}
   CString input;
	CFile theFile;
	if(theFile.Open(path,CFile::modeRead))
	{
	//	MessageBox("文件无法打开！");
	//	return TRUE;
   char Buffer[80];
	UINT Actual=0;
	while(Actual=theFile.Read(Buffer,sizeof(Buffer)))
	{
		CString str(Buffer,Actual);
		 input+=str;
	}
	
	 for(int i=0;i<input.GetLength();i++)
	 {
		 char ch=input.GetAt(i);
		 if(ch=='['&&i!=0)
		 {
			CString str;
			 str=input.Left(i);
			/* COLORREF fgColor;  
			 COLORREF bgColor; 
			 COLORREF bgColor1; 
			 fgColor = RGB(128, 0, 128);  
			 bgColor = RGB(240,255,255); 
			 bgColor1 = RGB(175,238,238);
			 static int num=0;
			 if(num%2==0)
				 m_list.AppendString(str, fgColor, bgColor);  
			 else
				 m_list.AppendString(str, fgColor, bgColor1);
			 num++;
			 */
			// m_list.InsertString(-1,str);
			 input=input.Right(input.GetLength()-i);
			 i=0;
			
		 }
	 }
     
	theFile.Close();
	}
	
	SetTimer(1,1000,NULL);

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





IsStop=TRUE;
IsMove=FALSE;
	 
	return TRUE;  // return TRUE unless you set the focus to a control
	              // EXCEPTION: OCX Property Pages should return FALSE
}

void LrcDlg::OnTimer(UINT nIDEvent) 
{
	// TODO: Add your message handler code here and/or call default
/*	if(IsStop)
	{
	for(int i=0;i<m_list.GetCount();i++)
	{
		CString strtemp;
        m_list.GetText(i,strtemp);
		for(int k=0;k<strtemp.GetLength();k++)
		{
			char ch=strtemp.GetAt(k);
			if(ch==']')
			{
             strtemp=strtemp.Left(k);
			 break;
			}
		}
		strtemp=strtemp.Right(strtemp.GetLength()-1);
		for(int j=0;j<strtemp.GetLength();j++)
		{
			int time;
			char ch=strtemp.GetAt(j);
			if(ch==':')
			{
				CString left=strtemp.Left(j);
				CString right=strtemp.Right(strtemp.GetLength()-j-1);
				CString rightleft=right.Left(2);
				CString doubleright=right.Right(2);
				if(rightleft==doubleright)
				time=_ttoi(left)*60+_ttoi(rightleft);
				else
				{
					if(_ttoi(doubleright)>=30)
                     time=_ttoi(left)*60+_ttoi(rightleft)+1;
					else
						time=_ttoi(left)*60+_ttoi(rightleft);
				}
				
				if(time==lrctime+1)
				{
					m_list.SetCurSel(i);
					m_list.SetTopIndex(i-2);
				}
			}
		}
	}
	UpdateData(FALSE);

	lrctime++;

	}
	*/
	CDialog::OnTimer(nIDEvent);
}

BOOL LrcDlg::DestroyWindow() 
{
	// TODO: Add your specialized code here and/or call the base class
	
	return CDialog::DestroyWindow();
}

HBRUSH LrcDlg::OnCtlColor(CDC* pDC, CWnd* pWnd, UINT nCtlColor) 
{
	HBRUSH hbr = CDialog::OnCtlColor(pDC, pWnd, nCtlColor);
	
	// TODO: Change any attributes of the DC here
	switch(nCtlColor)
{
case CTLCOLOR_LISTBOX: //按钮控件
{
pDC->SetBkMode(TRANSPARENT);
 pDC->SetTextColor(RGB(255,255,0));
HBRUSH B = CreateSolidBrush(RGB(34,139,34));  
return (HBRUSH) B;  
}
	}
	// TODO: Return a different brush if the default is not desired
	return hbr;
}



void LrcDlg::OnPaint() 
{
	CPaintDC dc(this); // device context for painting
	
	// TODO: Add your message handler code here
	    CRect rect;
        GetClientRect(rect);
        dc.FillSolidRect(rect,RGB(34,139,34));
	// Do not call CDialog::OnPaint() for painting messages
}






void LrcDlg::OnLButtonDown(UINT nFlags, CPoint point) 
{
	// TODO: Add your message handler code here and/or call default
	IsMove=TRUE;
	pointmove=point;
	HCURSOR hCur=AfxGetApp()->LoadCursor(IDC_CURSOR1);
    ::SetCursor(hCur);
	CDialog::OnLButtonDown(nFlags, point);
}

void LrcDlg::OnLButtonUp(UINT nFlags, CPoint point) 
{
	// TODO: Add your message handler code here and/or call default
	HCURSOR hCur=AfxGetApp()->LoadCursor(IDC_CURSOR2);
    ::SetCursor(hCur);
	IsMove=FALSE;
	CDialog::OnLButtonUp(nFlags, point);
}

void LrcDlg::OnMouseMove(UINT nFlags, CPoint point) 
{
	// TODO: Add your message handler code here and/or call default
	if(IsMove)
	{
	HCURSOR hCur=AfxGetApp()->LoadCursor(IDC_CURSOR1);
    ::SetCursor(hCur);
	 CRect rect,rect1;
		GetClientRect(&rect);
        ClientToScreen(&rect);
		int xtopleft=rect.TopLeft().x+point.x-pointmove.x;
		int ytopleft=rect.TopLeft().y+point.y-pointmove.y;
		CRect rc,rc1;
		GetWindowRect(&rc);
         MoveWindow(xtopleft,ytopleft,rc.Width(),rc.Height(),TRUE);

	}
	else
	{
HCURSOR hCur=AfxGetApp()->LoadCursor(IDC_CURSOR2);
    ::SetCursor(hCur);
	}
	CDialog::OnMouseMove(nFlags, point);
}

void LrcDlg::OnShut()
{
OnOK();
}
