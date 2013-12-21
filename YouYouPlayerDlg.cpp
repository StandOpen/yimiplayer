// YouYouPlayerDlg.cpp : implementation file
//

#include "stdafx.h"
#include "YouYouPlayer.h"
#include "YouYouPlayerDlg.h"
#include"LrcDlg.h"
#include"MySlider.h"
#include"IsMiniDlg.h"
#include <Digitalv.h>
#ifdef _DEBUG
#define new DEBUG_NEW
#undef THIS_FILE
static char THIS_FILE[] = __FILE__;
#endif
CMulitLineListBox	m_music;
CMyButton	m_removeall;
	MySlider	m_slider;
	CButton	m_play;
	CMyButton	m_skin;
	CMyButton	m_setmrmory;
	CMyButton	m_remove;
	CMyButton	m_musiclist;
	CMyButton	m_lrc;
	CMyButton	m_addmore;
	CMyButton	m_add;
	CComboBox	m_combo;
	CButton	m_upsong;
	CButton	m_stop;
	CButton	m_downsong;
	CString	m_songname;
	CString	m_time;
/////////////////////////////////////////////////////////////////////////////
// CAboutDlg dialog used for App About
class CAboutDlg : public CDialog
{
public:
	CAboutDlg();

// Dialog Data
	//{{AFX_DATA(CAboutDlg)
	enum { IDD = IDD_ABOUTBOX };
	//}}AFX_DATA

	// ClassWizard generated virtual function overrides
	//{{AFX_VIRTUAL(CAboutDlg)
	protected:
	virtual void DoDataExchange(CDataExchange* pDX);    // DDX/DDV support
	//}}AFX_VIRTUAL

// Implementation
protected:
	//{{AFX_MSG(CAboutDlg)
	//}}AFX_MSG
	DECLARE_MESSAGE_MAP()
};

CAboutDlg::CAboutDlg() : CDialog(CAboutDlg::IDD)
{
	//{{AFX_DATA_INIT(CAboutDlg)
	//}}AFX_DATA_INIT
}

void CAboutDlg::DoDataExchange(CDataExchange* pDX)
{
	CDialog::DoDataExchange(pDX);
	//{{AFX_DATA_MAP(CAboutDlg)
	//}}AFX_DATA_MAP
}

BEGIN_MESSAGE_MAP(CAboutDlg, CDialog)
	//{{AFX_MSG_MAP(CAboutDlg)
		// No message handlers
	//}}AFX_MSG_MAP
END_MESSAGE_MAP()

/////////////////////////////////////////////////////////////////////////////
// CYouYouPlayerDlg dialog

CYouYouPlayerDlg::CYouYouPlayerDlg(CWnd* pParent /*=NULL*/)
	: CDialog(CYouYouPlayerDlg::IDD, pParent)
{
	//{{AFX_DATA_INIT(CYouYouPlayerDlg)
	m_songname = _T("");
	m_time = _T("");
	//}}AFX_DATA_INIT
	// Note that LoadIcon does not require a subsequent DestroyIcon in Win32
	m_hIcon = AfxGetApp()->LoadIcon(IDR_MAINFRAME);
}

void CYouYouPlayerDlg::DoDataExchange(CDataExchange* pDX)
{
	CDialog::DoDataExchange(pDX);
	//{{AFX_DATA_MAP(CYouYouPlayerDlg)
	DDX_Control(pDX, IDC_VOICE, m_voice);
	DDX_Control(pDX, IDC_SONGLIST, m_music);
	DDX_Control(pDX, IDC_REMOVEALL, m_removeall);
	DDX_Control(pDX, IDC_SLIDER, m_slider);
	DDX_Control(pDX, IDC_PLAY, m_play);
	DDX_Control(pDX, IDC_SKIN, m_skin);
	DDX_Control(pDX, IDC_SETMEMORY, m_setmrmory);
	DDX_Control(pDX, IDC_REMOVE, m_remove);
	DDX_Control(pDX, IDC_MUSICLIST, m_musiclist);
	DDX_Control(pDX, IDC_LRC, m_lrc);
	DDX_Control(pDX, IDC_ADDMORE, m_addmore);
	DDX_Control(pDX, IDC_ADD, m_add);
	DDX_Control(pDX, IDC_MEMORY, m_combo);
	DDX_Control(pDX, IDC_UPSONG, m_upsong);
	DDX_Control(pDX, IDC_STOP, m_stop);
	DDX_Control(pDX, IDC_DOWNSONG, m_downsong);
	DDX_Text(pDX, IDC_SONGNAME, m_songname);
	DDX_Text(pDX, IDC_TIME, m_time);
	//}}AFX_DATA_MAP
}

BEGIN_MESSAGE_MAP(CYouYouPlayerDlg, CDialog)
	//{{AFX_MSG_MAP(CYouYouPlayerDlg)
	ON_WM_SYSCOMMAND()
	ON_WM_PAINT()
	ON_WM_QUERYDRAGICON()
	ON_BN_CLICKED(IDC_MUSICLIST, OnMusiclist)
	ON_BN_CLICKED(IDC_PLAY, OnPlay)
	ON_BN_CLICKED(IDC_UPSONG, OnUpsong)
	ON_BN_CLICKED(IDC_DOWNSONG, OnDownsong)
	ON_BN_CLICKED(IDC_STOP, OnStop)
	ON_BN_CLICKED(IDC_ADD, OnAdd)
	ON_BN_CLICKED(IDC_ADDMORE, OnAddmore)
	ON_BN_CLICKED(IDC_REMOVE, OnRemove)
	ON_LBN_DBLCLK(IDC_SONGLIST, OnDblclkSonglist)
	ON_WM_TIMER()
	ON_BN_CLICKED(IDC_SETMEMORY, OnSetmemory)
	ON_CBN_SELCHANGE(IDC_MEMORY, OnSelchangeMemory)
	ON_BN_CLICKED(IDC_SKIN, OnSkin)
	ON_WM_CTLCOLOR()
	ON_BN_CLICKED(IDC_LRC, OnLrc)
	ON_WM_MOVE()
	ON_NOTIFY(NM_CUSTOMDRAW, IDC_SLIDER, OnCustomdrawSlider)
	ON_WM_HSCROLL()
	ON_MESSAGE(WM_NC,OnNotifyIcon)
	ON_BN_CLICKED(IDC_TOPWND, OnTopwnd)
	ON_WM_CLOSE()
	ON_BN_CLICKED(IDC_REMOVEALL, OnRemoveall)
	ON_WM_MOUSEMOVE()
	ON_WM_LBUTTONDOWN()
	ON_WM_LBUTTONUP()
	ON_NOTIFY_EX(TTN_NEEDTEXT, 0, SetTipText)
	//}}AFX_MSG_MAP
END_MESSAGE_MAP()

/////////////////////////////////////////////////////////////////////////////
// CYouYouPlayerDlg message handlers

BOOL CYouYouPlayerDlg::OnInitDialog()
{
	CDialog::OnInitDialog();

	// Add "About..." menu item to system menu.

	// IDM_ABOUTBOX must be in the system command range.
	ASSERT((IDM_ABOUTBOX & 0xFFF0) == IDM_ABOUTBOX);
	ASSERT(IDM_ABOUTBOX < 0xF000);

	CMenu* pSysMenu = GetSystemMenu(FALSE);
	if (pSysMenu != NULL)
	{
		CString strAboutMenu;
		strAboutMenu.LoadString(IDS_ABOUTBOX);
		if (!strAboutMenu.IsEmpty())
		{
			pSysMenu->AppendMenu(MF_SEPARATOR);
			pSysMenu->AppendMenu(MF_STRING, IDM_ABOUTBOX, strAboutMenu);
		}
	}

	// Set the icon for this dialog.  The framework does this automatically
	//  when the application's main window is not a dialog
	SetIcon(m_hIcon, TRUE);			// Set big icon
	SetIcon(m_hIcon, FALSE);		// Set small icon
	
	// TODO: Add extra initialization here
	m_play.SetIcon(AfxGetApp()->LoadIcon(IDI_PLAY1));
	m_upsong.SetIcon(AfxGetApp()->LoadIcon(IDI_UP1));
	m_downsong.SetIcon(AfxGetApp()->LoadIcon(IDI_DOWN1));
	m_stop.SetIcon(AfxGetApp()->LoadIcon(IDI_STOP1));
	m_combo.SetWindowText("请选择记忆点");
	m_bPlaying=FALSE;
	m_nTotalLen=0;
	*m_szShortName=_T('\0');
	*m_szFullName=_T('\0');
	SetTimer(1,1000,NULL);
	m_time="00:00/00:00";
	UpdateData(FALSE);

    char  exepath[MAX_PATH];
    CString  strdir,tempdir,str; 
    memset(exepath,0,MAX_PATH); 
    GetModuleFileName(NULL,exepath,MAX_PATH); 
    tempdir=exepath; 
    strdir=tempdir.Left(tempdir.ReverseFind('\\'));
	str=strdir+"\\BKPIC.jpg";
//	GetPrivateProfileString("Main","BKPIC",strdir+"\\BKPIC.jpg",str.GetBuffer(0),MAX_PATH,strdir+"\\bkpathname.ini");
	_tcscpy(m_szFile,str);
	//open pic
	if(m_dc.GetDC())
		m_dc.DeleteObj();
	m_dc.CreateFromFile(m_szFile);




		NotifyIcon.cbSize=sizeof(NOTIFYICONDATA);
         NotifyIcon.hIcon=AfxGetApp()->LoadIcon(IDR_MAINFRAME);
         NotifyIcon.hWnd=m_hWnd;
        lstrcpy(NotifyIcon.szTip,"一米音乐");
        NotifyIcon.uCallbackMessage=WM_NC;
        NotifyIcon.uFlags=NIF_ICON | NIF_MESSAGE | NIF_TIP;
        Shell_NotifyIcon(NIM_ADD,&NotifyIcon);
		
		pdlg=new LrcDlg;
		IsLrcShow=FALSE;



		CString strText(_T(""));  
    COLORREF fgColor;  
    COLORREF bgColor;  
	strText = _T("歌曲列表：");   
	fgColor = RGB(128,0,128);  
	bgColor = RGB(119,136,153);  
	m_music.AppendString(strText, fgColor, bgColor);  
	list.Add(strText);
       ReadMusicList();
       ReadDemo();
	   SetWindowText("一米音乐");
	   IsMove=FALSE;
	   m_voice.SetRange(0,1000);
	   m_voice.SetPos(500);
	   WORD m_wDeviceID=mciOpen.wDeviceID;
    MCI_DGV_SETAUDIO_PARMS mciSetAudioPara; 
    mciSetAudioPara.dwItem = MCI_DGV_SETAUDIO_VOLUME; 
    mciSetAudioPara.dwValue =500;
    mciSendCommand(m_wDeviceID, MCI_SETAUDIO, MCI_DGV_SETAUDIO_VALUE | MCI_DGV_SETAUDIO_ITEM, (DWORD)(LPVOID)&mciSetAudioPara); 
	   EnableToolTips(TRUE);


	   HRGN m_hRgn;
	   RECT rect={0};
	   GetClientRect(&rect);
	   m_hRgn=CreateRoundRectRgn(rect.left,rect.top,rect.right,rect.bottom,5,5);
	   SetWindowRgn(m_hRgn,TRUE);
	return TRUE;  // return TRUE  unless you set the focus to a control
}

void CYouYouPlayerDlg::OnSysCommand(UINT nID, LPARAM lParam)
{
	if ((nID & 0xFFF0) == IDM_ABOUTBOX)
	{
		CAboutDlg dlgAbout;
		dlgAbout.DoModal();
	}
	switch(nID)
	{
	case SC_CLOSE: 
	{ 
		if(IsMiniShow())
		{
       IsMiniDlg minidlg;
       if(minidlg.DoModal()==IDOK)
		   changeMini();
	   else
		   OnClose();
		}
		else
		{
			if(IsMini())
				changeMini();
			else
				OnClose();
		}
	   break;
	   
	}
	case SC_MINIMIZE: 
	{ 
       changeMini();
	   break;
	} 
	default:
	{
		CDialog::OnSysCommand(nID, lParam);
	}
	}
}

// If you add a minimize button to your dialog, you will need the code below
//  to draw the icon.  For MFC applications using the document/view model,
//  this is automatically done for you by the framework.

void CYouYouPlayerDlg::OnPaint() 
{
	if (IsIconic())
	{
		CPaintDC dc(this); // device context for painting

		SendMessage(WM_ICONERASEBKGND, (WPARAM) dc.GetSafeHdc(), 0);

		// Center icon in client rectangle
		int cxIcon = GetSystemMetrics(SM_CXICON);
		int cyIcon = GetSystemMetrics(SM_CYICON);
		CRect rect;
		GetClientRect(&rect);
		int x = (rect.Width() - cxIcon + 1) / 2;
		int y = (rect.Height() - cyIcon + 1) / 2;
		// Draw the icon
		dc.DrawIcon(x, y, m_hIcon);


		
	}
	else
	{ 



		if(m_dc.GetDC())
		
		{
			CRect rect;
			GetClientRect(&rect);
			static int cx=rect.Width();
			static int cy=rect.Height();
			CPaintDC dc(this);
			int nMode=SetStretchBltMode(dc,COLORONCOLOR);
			::StretchBlt(dc,0,0,cx,cy,m_dc,0,0,m_dc.GetWidth(),m_dc.GetHeight(),SRCCOPY);
			SetStretchBltMode(dc,nMode);
			DrawBmp(IDC_CLOSE,IDB_BITMAP2);
			DrawBmp(IDC_MINI,IDB_BITMAP4);
			DrawBmp(IDC_LOGO,IDB_BITMAP5);
			DrawBmp(IDC_VOICEBMP,IDB_BITMAP6);
		}
		else
		CDialog::OnPaint();
	}
}

// The system calls this to obtain the cursor to display while the user drags
//  the minimized window.
HCURSOR CYouYouPlayerDlg::OnQueryDragIcon()
{
	return (HCURSOR) m_hIcon;
}

BOOL CYouYouPlayerDlg::DestroyWindow() 
{
	// TODO: Add your specialized code here and/or call the base class
	mciSendCommand (mciOpen.wDeviceID,MCI_CLOSE,NULL,NULL);
	KillTimer(1);
	delete []pdlg;
	WriteMusicList();
	Shell_NotifyIcon(NIM_DELETE, &NotifyIcon);
	return CDialog::DestroyWindow();
}

void CYouYouPlayerDlg::OnMusiclist() 
{
	// TODO: Add your control notification handler code here
	static int num=0;
	if(num==0)
	{
	    CRect rect;
		GetClientRect(&rect);
        ClientToScreen(&rect);
		CRect rc;
		GetWindowRect(&rc);
        MoveWindow(rect.TopLeft().x,rect.TopLeft().y,rc.Width(),rc.Height()-295,TRUE);
		num++;
		GetDlgItem(IDC_MUSICLIST)->SetWindowText("显示列表");
	}
	else
	{
        CRect rect;
		GetClientRect(&rect);
        ClientToScreen(&rect);
		CRect rc;
		GetWindowRect(&rc);
        MoveWindow(rect.TopLeft().x,rect.TopLeft().y,rc.Width(),rc.Height()+295,TRUE);
		num=0;
		GetDlgItem(IDC_MUSICLIST)->SetWindowText("隐藏列表");
		Invalidate();
		
	}
		CRect rect,rect1;
		GetClientRect(&rect);
	    pdlg->GetClientRect(&rect1);
        ClientToScreen(&rect);
		pdlg->ClientToScreen(&rect1);
		CRect rc;
		pdlg->GetWindowRect(&rc);
		pdlg->MoveWindow(rect.TopLeft().x,rect.TopLeft().y+rect.Height(),rc.Width(),rc.Height(),TRUE);

}
BOOL CYouYouPlayerDlg::StopPlay()
{

	pdlg->IsStop=FALSE;
	 if(!m_bPlaying)
	 {
		return TRUE;
	 }
	CString strCmd;
	DWORD dwErr;
	dwErr=mciSendCommand(mciOpen.wDeviceID,MCI_PAUSE,NULL ,NULL);
	if(dwErr!=0)
	{
		ErrBox(dwErr);
		return FALSE;
	}
	else
	{
		SetDlgItemText(IDC_PLAY,_T("播放"));
		m_play.SetIcon(AfxGetApp()->LoadIcon(IDI_PLAY1));
		m_bPlaying=FALSE;
		
	}
	 return TRUE;
}
void CYouYouPlayerDlg::ErrBox(DWORD dwErr)
{
	TCHAR szBuf[MAX_PATH]={0};
	mciGetErrorString(dwErr,szBuf,MAX_PATH);
//	AfxMessageBox(szBuf);
}

void CYouYouPlayerDlg::OnPlay() 
{
	// TODO: Add your control notification handler code here
	pdlg->IsStop=TRUE;
	  if(m_bPlaying)
	{
		StopPlay();
	}
	else
	{
		ChangeLrc();
		CString strCmd;
		int nIndex=m_music.GetCurSel();
		if(nIndex<1)
			return;
		//m_music.GetText(nIndex,m_szFullName);
	//	GetShortPathName(m_szFullName,m_szShortName,MAX_PATH);
	    //strCmd.Format("%s",m_szShortName);
	    strCmd=list.GetAt(nIndex);
		CString strname;
		strname=strCmd;
       // m_music.GetText(nIndex,strname);
		 CString temp;
			for(int i=strname.GetLength()-1;i>=0;i--)
			{
				char ch=strname.GetAt(i);
				if(ch=='\\')
				{
				temp=strname.Right(strname.GetLength()-i-1);
				temp=temp.Left(temp.GetLength()-4);
				break;
				}
			}
			
			m_songname="正在播放：  "+temp;
		SetWindowText("一米音乐  "+temp);
		Shell_NotifyIcon(NIM_DELETE, &NotifyIcon);
		NotifyIcon.cbSize=sizeof(NOTIFYICONDATA);
         NotifyIcon.hIcon=AfxGetApp()->LoadIcon(IDR_MAINFRAME);
         NotifyIcon.hWnd=m_hWnd;
        lstrcpy(NotifyIcon.szTip,"一米音乐:"+temp);
        NotifyIcon.uCallbackMessage=WM_NC;
        NotifyIcon.uFlags=NIF_ICON | NIF_MESSAGE | NIF_TIP;
        Shell_NotifyIcon(NIM_ADD,&NotifyIcon);
	
		char str[128]={0};
		char buf[128]={0};
		
		
		MCIERROR mciError;
		mciOpen.lpstrDeviceType = "mpegvideo";
		mciOpen.lpstrElementName = strCmd;
		
		mciError = mciSendCommand(0,MCI_OPEN,MCI_OPEN_TYPE | MCI_OPEN_ELEMENT,(DWORD)&mciOpen);
		if(mciError)
		{
			mciGetErrorString(mciError,buf,128);
		//	MessageBox(buf);
			
		}
		UINT DeviceID = mciOpen.wDeviceID;
		MCI_PLAY_PARMS mciPlay;
		
		mciError = mciSendCommand(DeviceID,MCI_PLAY,0 ,(DWORD)&mciPlay);
		if(mciError)
		{
		//	MessageBox("send MCI_PLAY command failed/n");
			
		}
		m_bPlaying=TRUE;
		strCmd.Empty();


		int pos=m_voice.GetPos();
    WORD m_wDeviceID=mciOpen.wDeviceID;
    MCI_DGV_SETAUDIO_PARMS mciSetAudioPara; 
    mciSetAudioPara.dwItem = MCI_DGV_SETAUDIO_VOLUME; 
    mciSetAudioPara.dwValue =pos;
    mciSendCommand(m_wDeviceID, MCI_SETAUDIO, MCI_DGV_SETAUDIO_VALUE | MCI_DGV_SETAUDIO_ITEM, (DWORD)(LPVOID)&mciSetAudioPara);
	}
	
	
	if(m_bPlaying)
	{
		SetDlgItemText(IDC_PLAY,_T("暂停"));
		m_play.SetIcon(AfxGetApp()->LoadIcon(IDI_PAUSE1));
	}
	CRect recttime;
    GetDlgItem(IDC_SONGNAME)->GetWindowRect(&recttime);
    ScreenToClient(recttime);
	InvalidateRect((LPCRECT)recttime,FALSE) ;
	UpdateData(FALSE);
}

void CYouYouPlayerDlg::OnUpsong() 
{
	// TODO: Add your control notification handler code here
		int Index=m_music.GetCurSel();
	if(Index>0)
	Index--;
	else
		Index=m_music.GetCount()-1;
	m_music.SetCurSel(Index);
	StopPlay();
	OnPlay();
}

void CYouYouPlayerDlg::OnDownsong() 
{
	// TODO: Add your control notification handler code here
		int Index=m_music.GetCurSel();
	if(Index<m_music.GetCount()-1)
	Index++;
	else
		Index=0;
	m_music.SetCurSel(Index);
	StopPlay();
	OnPlay();
}

void CYouYouPlayerDlg::OnStop() 
{
	// TODO: Add your control notification handler code here
	pdlg->lrctime=0;
	pdlg->cursel=0;
	StopPlay();
	mciSendCommand(mciOpen.wDeviceID,MCI_STOP,NULL ,NULL);
	
	mciSendCommand(mciOpen.wDeviceID,MCI_SEEK,MCI_SEEK_TO_START ,NULL);
	m_slider.SetPos(0);
}

void CYouYouPlayerDlg::OnAdd() 
{
	// TODO: Add your control notification handler code here
	CFileDialog dlg(TRUE,NULL,NULL,OFN_FILEMUSTEXIST|OFN_ALLOWMULTISELECT,_T("音乐文件(*.mp3;*.wma;*.wav)|*.mp3;*.wma;*.wav|所有文件(*.*)|*.*||"),this);
	TCHAR *pBuf=new TCHAR[MAX_PATH*50];
	*pBuf=0;
	dlg.m_ofn.lpstrFile=pBuf;
	dlg.m_ofn.nMaxFile=MAX_PATH*50;
	if(dlg.DoModal()==IDOK)
	{
		POSITION pos=dlg.GetStartPosition();
		CString strFile;
		while(pos!=NULL)
		{
			strFile=dlg.GetNextPathName(pos);
		CString temp;
			for(int i=strFile.GetLength()-1;i>=0;i--)
			{
				char ch=strFile.GetAt(i);
				if(ch=='\\')
				{
				temp=strFile.Right(strFile.GetLength()-i-1);
				temp=temp.Left(temp.GetLength()-4);
				break;
				}
			}
			
			COLORREF fgColor;  
			 COLORREF bgColor; 
			 COLORREF bgColor1; 
			 fgColor = RGB(128, 0, 128);  
			 bgColor = RGB(240,255,255); 
			 bgColor1 = RGB(175,238,238);
			 static int num=0;
			 if(num%2==0)
				 m_music.AppendString(temp, fgColor, bgColor);  
			 else
				 m_music.AppendString(temp, fgColor, bgColor1);
			 num++;
			 list.Add(strFile);
		//	m_music.InsertString(-1,strFile);
		
		}
         
	}
	delete []pBuf;

	
}

void CYouYouPlayerDlg::OnAddmore() 
{
	// TODO: Add your control notification handler code here
//	AfxBeginThread(WorkProc,this);
	FindFile();
}
void CYouYouPlayerDlg::FindFile()
{
CString str;
BROWSEINFO bi;
char name[MAX_PATH];
ZeroMemory(&bi,sizeof(BROWSEINFO));
bi.hwndOwner = GetSafeHwnd();
bi.pszDisplayName = name;
bi.lpszTitle = "请选择添加的文件夹:";
 
bi.ulFlags = BIF_RETURNFSANCESTORS;
LPITEMIDLIST idl = SHBrowseForFolder(&bi);
if(idl == NULL)
return;
SHGetPathFromIDList(idl, str.GetBuffer(MAX_PATH));
str.ReleaseBuffer();
  for(int i=0;i<str.GetLength();i++)
  {
	  char ch=str.GetAt(i);
	  if(ch=='\\')
	  {
		  CString temp1=str.Left(i);
		  CString temp2=str.Right(str.GetLength()-i-1);
		  str.Empty();
		  str=temp1+"\\\\"+temp2;
		  i++;
	  }
  }
  str+="\\\\";
 CFileFind finder;
BOOL bWorking=finder.FindFile(str+"*.mp3");
  static int num=0;
	 
	CString str1(_T(""));
	while(bWorking)
	{
		bWorking=finder.FindNextFile();
		if(finder.IsArchived())
		{
			str1=finder.GetFilePath();
			CString temp;
			for(int i=str1.GetLength()-1;i>=0;i--)
			{
				char ch=str1.GetAt(i);
				if(ch=='\\')
				{
				temp=str1.Right(str1.GetLength()-i-1);
				temp=temp.Left(temp.GetLength()-4);
				break;
				}
			}
			
			COLORREF fgColor;  
			 COLORREF bgColor; 
			 COLORREF bgColor1; 
			 fgColor = RGB(128, 0, 128);  
			 bgColor = RGB(240,255,255); 
			 bgColor1 = RGB(175,238,238);
			
			 if(num%2==0)
				 m_music.AppendString(temp, fgColor, bgColor);  
			 else
				 m_music.AppendString(temp, fgColor, bgColor1);
			 num++;
			 list.Add(str1);
		//	m_music.InsertString(-1,str1);
			str1.Empty();
		}
	}

 bWorking=finder.FindFile(str+"*.wav");
 
	 
	CString str2;
	while(bWorking)
	{
		bWorking=finder.FindNextFile();
		if(finder.IsArchived())
		{
			str2=finder.GetFilePath();
			CString temp;
			for(int i=str2.GetLength()-1;i>=0;i--)
			{
				char ch=str2.GetAt(i);
				if(ch=='\\')
				{
				temp=str2.Right(str2.GetLength()-i-1);
				temp=temp.Left(temp.GetLength()-4);
				break;
				}
			}
			COLORREF fgColor;  
			 COLORREF bgColor; 
			 COLORREF bgColor1; 
			 fgColor = RGB(128, 0, 128);  
			 bgColor = RGB(240,255,255); 
			 bgColor1 = RGB(175,238,238);
			 if(num%2==0)
				 m_music.AppendString(temp, fgColor, bgColor);  
			 else
				 m_music.AppendString(temp, fgColor, bgColor1);
			 num++;
			 list.Add(str2);
            //m_music.AddString(str2);
		  
		}
	}

bWorking=finder.FindFile(str+"*.wma");
 
	 
	CString str3;
	while(bWorking)
	{
		bWorking=finder.FindNextFile();
		if(finder.IsArchived())
		{
			str3=finder.GetFilePath();
			CString temp;
			for(int i=str3.GetLength()-1;i>=0;i--)
			{
				char ch=str3.GetAt(i);
				if(ch=='\\')
				{
				temp=str3.Right(str3.GetLength()-i-1);
				temp=temp.Left(temp.GetLength()-4);
				break;
				}
			}
			COLORREF fgColor;  
			 COLORREF bgColor; 
			 COLORREF bgColor1; 
			 fgColor = RGB(128, 0, 128);  
			 bgColor = RGB(240,255,255); 
			 bgColor1 = RGB(175,238,238);
			 if(num%2==0)
				 m_music.AppendString(temp, fgColor, bgColor);  
			 else
				 m_music.AppendString(temp, fgColor, bgColor1);
			 num++;
			 list.Add(str3);
            //m_music.AddString(str3);
		  
		}
	}

}

UINT CYouYouPlayerDlg::WorkProc(LPVOID lpParam)
{
CYouYouPlayerDlg *pDlg=(CYouYouPlayerDlg *)lpParam;
pDlg->FindFile();
return 0;
}

void CYouYouPlayerDlg::OnRemove() 
{
	// TODO: Add your control notification handler code here
	int nIndex=m_music.GetCurSel();
	if(nIndex<0)
		return;
	m_music.DeleteString(nIndex);
}

void CYouYouPlayerDlg::OnDblclkSonglist() 
{
	// TODO: Add your control notification handler code he
	int nIndex=m_music.GetCurSel();
	if(nIndex==0)
	{
		static int num=0;
		if(num==0)
		{
			while(m_music.GetCount()!=1)
			{
			for(int i=1;i<m_music.GetCount();i++)
			{
				m_music.DeleteString(i);
			}
			}
			num++;
		}
		else
		{
			for(int i=1;i<list.GetSize();i++)
			{
				CString str=list.GetAt(i);

					CString temp;
			for(int i=str.GetLength()-1;i>=0;i--)
			{
				char ch=str.GetAt(i);
				if(ch=='\\')
				{
				temp=str.Right(str.GetLength()-i-1);
				temp=temp.Left(temp.GetLength()-4);
				break;
				}
			}
			COLORREF fgColor;  
    COLORREF bgColor; 
	COLORREF bgColor1; 
        fgColor = RGB(128, 0, 128);  
        bgColor = RGB(240,255,255); 
		bgColor1 = RGB(175,238,238);
		static int number=0;
		if(number%2==0)
        m_music.AppendString(temp, fgColor, bgColor);  
		else
       m_music.AppendString(temp, fgColor, bgColor1);
		number++;
		num=0;
			}
			
		}

	}
	else
	{
		if(StopPlay())
	{
		mciSendCommand (mciOpen.wDeviceID,MCI_CLOSE,NULL,NULL);
		OnPlay();
	}
	}
}

void CYouYouPlayerDlg::OnTimer(UINT nIDEvent) 
{
	// TODO: Add your message handler code here and/or call default
		if(m_bPlaying)
	{
	MCI_STATUS_PARMS mciStatusParms;
      WORD m_wDeviceID=mciOpen.wDeviceID;
	mciStatusParms.dwItem=MCI_STATUS_POSITION;   
	mciSendCommand(m_wDeviceID,MCI_STATUS,MCI_WAIT|MCI_STATUS_ITEM,(DWORD)(LPVOID)&mciStatusParms);//关键,取得位置
    int m_dPosition=mciStatusParms.dwReturn;
	int currentpos=m_dPosition/1000;
	 UINT DeviceID = mciOpen.wDeviceID ;
 mciStatusParms.dwItem=MCI_STATUS_LENGTH; mciSendCommand(DeviceID,MCI_STATUS,MCI_WAIT|MCI_STATUS_ITEM,(DWORD)(LPVOID)&mciStatusParms);//关键,取得长度
     int m_dLength=mciStatusParms.dwReturn;
	 int minute=m_dLength/60000;
	 int second=(m_dLength%60000)/1000;
	CString str;
	str.Format("0%d:%d/0%d:%d",currentpos/60,currentpos%60,minute,second);
	m_time.Empty();
	m_time=str;
	m_slider.SetRange(0,minute*60+second,TRUE);
	m_slider.SetTicFreq(10);
    m_slider.SetPos(currentpos);
	currentpos++;
	if(currentpos==minute*60+second+1)
	{
		currentpos=0;
		m_bPlaying=FALSE;
		int nIndex=m_music.GetCurSel();
		m_music.SetCurSel(nIndex+1);
		 OnPlay();
	}
	UpdateData(FALSE);

	CRect recttime;
    GetDlgItem(IDC_TIME)->GetWindowRect(&recttime);
    ScreenToClient(recttime);
	InvalidateRect((LPCRECT)recttime,FALSE) ;
	}
	IsHide();
	CDialog::OnTimer(nIDEvent);
}

void CYouYouPlayerDlg::OnSetmemory() 
{
	// TODO: Add your control notification handler code here
	MCI_STATUS_PARMS mciStatusParms;
     WORD m_wDeviceID=mciOpen.wDeviceID;
	mciStatusParms.dwItem=MCI_STATUS_POSITION;   
	mciSendCommand(m_wDeviceID,MCI_STATUS,MCI_WAIT|MCI_STATUS_ITEM,(DWORD)(LPVOID)&mciStatusParms);//关键,取得位置
    int m_dPosition=mciStatusParms.dwReturn;
	int minute=m_dPosition/60000;
	int second=(m_dPosition%60000)/1000;
	CString str;
	str.Format("%d:%d",minute,second);
	m_combo.AddString(str);
}

 

void CYouYouPlayerDlg::OnSelchangeMemory() 
{
	// TODO: Add your control notification handler code here
		CString strtime;
	int l=m_combo.GetCurSel();
	m_combo.GetLBText( l, strtime );
	int time;
	 for(int i=0;i<strtime.GetLength();i++)
	 {
		 char ch=strtime.GetAt(i);
		 if(ch==':')
		 {
			 CString left=strtime.Left(i);
             CString right=strtime.Right(strtime.GetLength()-i-1);
			 time=_ttoi(left)*60000+_ttoi(right)*1000;
			 break;
		 }
	 }
WORD m_wDeviceID=mciOpen.wDeviceID;
 MCI_PLAY_PARMS mciPlay;
 mciPlay.dwFrom=time;
 mciSendCommand(m_wDeviceID,MCI_PLAY,MCI_FROM,(DWORD)&mciPlay);
 ChangeLrc();
}

void CYouYouPlayerDlg::OnSkin() 
{
	// TODO: Add your control notification handler code here
	LPCTSTR lpFilter=_T("*.bmp;*.jpg;*.gif;*.png;*.tiff;*.ico;*.tga;|*.bmp;*.jpg;*.gif;*.png;*.tiff;*.ico;*.tga;||");
	CFileDialog dlg(TRUE,NULL,NULL,OFN_FILEMUSTEXIST,lpFilter,this);
	if(dlg.DoModal()==IDOK)
	{
   char  exepath[MAX_PATH];
    CString  strdir,tempdir; 
    memset(exepath,0,MAX_PATH); 
    GetModuleFileName(NULL,exepath,MAX_PATH); 
    tempdir=exepath; 
    strdir=tempdir.Left(tempdir.ReverseFind('\\'));
   ::WritePrivateProfileString("Main","BKPIC",dlg.GetPathName(),strdir+"\\bkpathname.ini");
		_tcscpy(m_szFile,dlg.GetPathName());
		//open pic
		if(m_dc.GetDC())
		      m_dc.DeleteObj();
		m_dc.CreateFromFile(m_szFile);
	}
		Invalidate();
}


HBRUSH CYouYouPlayerDlg::OnCtlColor(CDC* pDC, CWnd* pWnd, UINT nCtlColor) 
{
	HBRUSH hbr = CDialog::OnCtlColor(pDC, pWnd, nCtlColor);
switch(nCtlColor)
{case CTLCOLOR_LISTBOX: //按钮控件
{

pDC->SetBkMode(TRANSPARENT);
 pDC->SetTextColor(RGB(255,255,0));
HBRUSH B = CreateSolidBrush(RGB(218,165,32));  
return (HBRUSH) B;  
}

case CTLCOLOR_STATIC: //静态文本控件
{
pDC->SetBkMode(TRANSPARENT);  
pDC->SetTextColor(RGB(255,0,0)); //设置字体颜色
//pWnd->SetFont(cfont); //设置字体
//HBRUSH B = CreateSolidBrush(RGB(173,255,47)); //创建画刷
//return (HBRUSH) B;  
return   (HBRUSH)::GetStockObject(NULL_BRUSH);
}
}
return hbr;
}

void CYouYouPlayerDlg::OnLrc() 
{
	// TODO: Add your control notification handler code here
	static int num=0;
	
	if(num==0)
	{
		pdlg=new LrcDlg;
	CString strtemp;
	MCI_STATUS_PARMS mciStatusParms;
      WORD m_wDeviceID=mciOpen.wDeviceID;
	mciStatusParms.dwItem=MCI_STATUS_POSITION;   
	mciSendCommand(m_wDeviceID,MCI_STATUS,MCI_WAIT|MCI_STATUS_ITEM,(DWORD)(LPVOID)&mciStatusParms);//关键,取得位置
    int m_dPosition=mciStatusParms.dwReturn;
	int nIndex=m_music.GetCurSel();
		if(nIndex<0)
			return;
	pdlg->strpath=list.GetAt(nIndex);
	pdlg->lrctime=m_dPosition/1000;
	pdlg->Create(IDD_DIALOG1);
	pdlg->ShowWindow(SW_NORMAL);
	GetDlgItem(IDC_LRC)->SetWindowText("隐藏歌词");
		num++;
		CRect rect,rect1;
		GetClientRect(&rect);
	 pdlg->GetClientRect(&rect1);
        ClientToScreen(&rect);
		pdlg->ClientToScreen(&rect1);
		CRect rc;
		pdlg->GetWindowRect(&rc);
		pdlg->MoveWindow(rect.TopLeft().x,rect.TopLeft().y+rect.Height(),rc.Width(),rc.Height(),TRUE);
        IsLrcShow=TRUE;
	}
	else
	{
	 pdlg->OnShut();
	 num=0;
	 GetDlgItem(IDC_LRC)->SetWindowText("显示歌词");
	delete []pdlg;
	IsLrcShow=FALSE;
	}



	
}




void CYouYouPlayerDlg::OnMove(int x, int y) 
{
	CDialog::OnMove(x, y);


static int num=0;
if(num!=0)
{

	CRect rect,rect1;
	GetClientRect(&rect);
	pdlg->GetClientRect(&rect1);
    ClientToScreen(&rect);
	pdlg->ClientToScreen(&rect1);
	CRect rc;
	pdlg->GetWindowRect(&rc);
	pdlg->MoveWindow(rect.TopLeft().x,rect.TopLeft().y+rect.Height(),rc.Width(),rc.Height(),TRUE);
}
num=1;
	// TODO: Add your message handler code here
	
}

void CYouYouPlayerDlg::OnCustomdrawSlider(NMHDR* pNMHDR, LRESULT* pResult) 
{
	// TODO: Add your control notification handler code here
	int nPos = m_slider.GetPos();
//	*pResult = 0;
}

void CYouYouPlayerDlg::OnHScroll(UINT nSBCode, UINT nPos, CScrollBar* pScrollBar) 
{
 // TODO: Add your message handler code here and/or call default
 
 if(pScrollBar != NULL )
 {
  // 强制转换成CSliderCtrl
  CSliderCtrl* pSlider = (CSliderCtrl*)pScrollBar;
  // 根据CSliderCtrl ID 来判断是哪一个CSliderCtrl
  if(pSlider->GetDlgCtrlID() == IDC_SLIDER)
  {
   int pos=m_slider.GetPos();
   WORD m_wDeviceID=mciOpen.wDeviceID;
 MCI_PLAY_PARMS mciPlay;
 mciPlay.dwFrom=pos*1000;
 mciSendCommand(m_wDeviceID,MCI_PLAY,MCI_FROM,(DWORD)&mciPlay);
  }
  if(pSlider->GetDlgCtrlID() == IDC_VOICE)
  {
   int pos=m_voice.GetPos();
    WORD m_wDeviceID=mciOpen.wDeviceID;
    MCI_DGV_SETAUDIO_PARMS mciSetAudioPara; 
    mciSetAudioPara.dwItem = MCI_DGV_SETAUDIO_VOLUME; 
    mciSetAudioPara.dwValue =pos;
    mciSendCommand(m_wDeviceID, MCI_SETAUDIO, MCI_DGV_SETAUDIO_VALUE | MCI_DGV_SETAUDIO_ITEM, (DWORD)(LPVOID)&mciSetAudioPara); 
  }
 }
}

void CYouYouPlayerDlg::IsHide()
{
     CRect rc;
	CRect rect;
	GetWindowRect(&rect);
	rc.CopyRect(&rect);
	CPoint point;
	GetCursorPos(&point);
	if(rect.top<0&&PtInRect(rect,point))
	{
		rect.top=0;
		MoveWindow(rect.left,rect.top,rc.Width(),rc.Height());
	}
	else if(rect.top>-3&&rect.top<3&&!PtInRect(rect,point))
	{
		rect.top=3-rect.Height();
		MoveWindow(rect.left,rect.top,rc.Width(),rc.Height());
	}
}
void CYouYouPlayerDlg::ChangeLrc()
{

	if(IsLrcShow)
	{
    pdlg->OnShut();
	delete []pdlg;
	pdlg=new LrcDlg;
	CString strtemp;
	MCI_STATUS_PARMS mciStatusParms;
      WORD m_wDeviceID=mciOpen.wDeviceID;
	mciStatusParms.dwItem=MCI_STATUS_POSITION;   
	mciSendCommand(m_wDeviceID,MCI_STATUS,MCI_WAIT|MCI_STATUS_ITEM,(DWORD)(LPVOID)&mciStatusParms);//关键,取得位置
    int m_dPosition=mciStatusParms.dwReturn;
	int nIndex=m_music.GetCurSel();
		if(nIndex<0)
			return;
		m_music.GetText(nIndex,strtemp);
	
	pdlg->strpath=strtemp;
	pdlg->lrctime=m_dPosition/1000;
	pdlg->Create(IDD_DIALOG1);
	pdlg->ShowWindow(SW_NORMAL);
		CRect rect,rect1;
		GetClientRect(&rect);
	 pdlg->GetClientRect(&rect1);
        ClientToScreen(&rect);
		pdlg->ClientToScreen(&rect1);
		CRect rc;
		pdlg->GetWindowRect(&rc);
		pdlg->MoveWindow(rect.TopLeft().x,rect.TopLeft().y+rect.Height(),rc.Width(),rc.Height(),TRUE);
	}
}
void CYouYouPlayerDlg::changeMini()
{
	ShowWindow(SW_HIDE);
	NotifyIcon.cbSize=sizeof(NOTIFYICONDATA);
	NotifyIcon.hIcon=AfxGetApp()->LoadIcon(IDR_MAINFRAME);
	NotifyIcon.hWnd=m_hWnd;
	lstrcpy(NotifyIcon.szTip,"一米音乐");
	NotifyIcon.uCallbackMessage=WM_NC;
	NotifyIcon.uFlags=NIF_ICON | NIF_MESSAGE | NIF_TIP;
	Shell_NotifyIcon(NIM_ADD,&NotifyIcon);
}

 void CYouYouPlayerDlg::OnNotifyIcon(WPARAM wParam,LPARAM IParam)
{
	 switch(IParam)
	 {
	 case WM_LBUTTONDOWN:
		 { 
			 ModifyStyleEx(0,WS_EX_TOPMOST);
			 ShowWindow(SW_SHOW);
			 pdlg->ShowWindow(SW_SHOW);
			 break;
			 
		 }
	 case WM_RBUTTONDOWN:
		 {
			 LPPOINT lpoint=new tagPOINT;   
			 ::GetCursorPos(lpoint); 
			 CMenu menu;   
			 menu.CreatePopupMenu();       
			 CString str;
			 GetWindowText(str);
			 menu.AppendMenu(MF_STRING,IDC_NOTHING,_T(str));
			 menu.AppendMenu(MF_STRING,IDC_UPSONG,_T("上一首"));
			 CString strplay;
			 m_play.GetWindowText(strplay);
			 menu.AppendMenu(MF_STRING,IDC_PLAY,_T(strplay));
			 menu.AppendMenu(MF_STRING,IDC_DOWNSONG,_T("下一首"));
			 menu.AppendMenu(MF_STRING,IDC_LRC,_T("歌词"));
			 menu.AppendMenu(MF_STRING,WM_DESTROY,_T("关闭"));
			 menu.TrackPopupMenu(TPM_LEFTALIGN,lpoint->x,lpoint->y,this);                 
			 HMENU hmenu=menu.Detach(); 
			 menu.DestroyMenu();   
			 delete lpoint;   
			 break;
		 }
	 }
}

void CYouYouPlayerDlg::OnTopwnd() 
{
	// TODO: Add your control notification handler code here
	static int num=0;
	if(num==0)
	{
	static_cast<CButton*>(GetDlgItem(IDC_TOPWND))->SetCheck(1);
	num++;
	}
	else
	{
	static_cast<CButton*>(GetDlgItem(IDC_TOPWND))->SetCheck(0);
		
	num=0;
	}
	BOOL btop=static_cast<CButton*>(GetDlgItem(IDC_TOPWND))->GetCheck();
	if(btop)
	{
		::SetWindowPos(m_hWnd,HWND_TOPMOST,0,0,0,0,SWP_NOMOVE|SWP_NOSIZE);
	}
	else
	{
		::SetWindowPos(m_hWnd,HWND_NOTOPMOST,0,0,0,0,SWP_NOMOVE|SWP_NOSIZE);
	}
}

void CYouYouPlayerDlg::WriteMusicList()
{
	CString temp;

	for(int i=1;i<list.GetSize();i++)
	{
		CString str;
		str=list.GetAt(i);
		if(i==1)
		temp=str;
		else
		temp=temp+"|"+str;
	}

	char  exepath[MAX_PATH];
    CString  strdir,tempdir,strlist; 
    memset(exepath,0,MAX_PATH); 
    GetModuleFileName(NULL,exepath,MAX_PATH); 
    tempdir=exepath; 
    strdir=tempdir.Left(tempdir.ReverseFind('\\'));
	strlist=strdir+"\\musiclist.list";
	static const char * list=temp.GetBuffer(0);
	 HANDLE hFile=CreateFile(_T(strlist),GENERIC_WRITE,FILE_SHARE_READ,NULL,CREATE_ALWAYS,FILE_ATTRIBUTE_NORMAL,NULL);
if(hFile==INVALID_HANDLE_VALUE)
AfxMessageBox(_T("Fail to Crate"));
else
{
  CFile myFile((int)hFile);
myFile.Write(list,lstrlen(list));
myFile.Close();
}

}

void CYouYouPlayerDlg::ReadMusicList()
{
	char  exepath[MAX_PATH];
    CString  strdir,tempdir; 
    memset(exepath,0,MAX_PATH); 
    GetModuleFileName(NULL,exepath,MAX_PATH); 
    tempdir=exepath; 
    strdir=tempdir.Left(tempdir.ReverseFind('\\'));
	CString path=strdir+"\\musiclist.list";
	CFileStatus status;
	if(!CFile::GetStatus(path,status))
	{
      //文件不存在
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
	
	 for(int i=1;i<input.GetLength();i++)
	 {
		 char ch=input.GetAt(i);
		 if(ch=='|'&&i!=0)
		 {
			 CString str;
			 str=input.Left(i);
			 CString temp;
			 
			for(int j=str.GetLength()-1;j>=0;j--)
			{
				char ch=str.GetAt(j);
				if(ch=='\\')
				{
				temp=str.Right(str.GetLength()-j-1);
				temp=temp.Left(temp.GetLength()-4);
				break;
				}
			}
			list.Add(str);
			 COLORREF fgColor;  
			 COLORREF bgColor; 
			 COLORREF bgColor1; 
			 fgColor = RGB(128, 0, 128);  
			 bgColor = RGB(240,255,255); 
			 bgColor1 = RGB(175,238,238);
			 static int num=0;
			 if(num%2==0)
				 m_music.AppendString(temp, fgColor, bgColor);  
			 else
				 m_music.AppendString(temp, fgColor, bgColor1);
			 num++;
			 input=input.Right(input.GetLength()-i-1);
			 i=0;
		 }
	 }
     
	theFile.Close();
	}
}

void CYouYouPlayerDlg::ReadDemo()
{

char  exepath[MAX_PATH];
    CString  strdir,tempdir; 
    memset(exepath,0,MAX_PATH); 
    GetModuleFileName(NULL,exepath,MAX_PATH); 
    tempdir=exepath; 
    strdir=tempdir.Left(tempdir.ReverseFind('\\'));

	HKEY hSubKey;
	LONG lRet=RegCreateKeyEx(HKEY_CURRENT_USER,_T("Software\\MyTestApp"),0,NULL,REG_OPTION_NON_VOLATILE,KEY_READ|KEY_WRITE,NULL,&hSubKey,NULL);
	if(lRet!=ERROR_SUCCESS)
	{
		AfxMessageBox(_T("DJFKAJ"));
		return;
	}
	
	//读取注册表数据
	DWORD dwType=0,dwRunCount=0,dwLen=sizeof(DWORD);
	lRet=RegQueryValueEx(hSubKey,_T("RunCount"),0,&dwType,(PBYTE)&dwRunCount,&dwLen);
	if(ERROR_SUCCESS!=lRet||dwLen!=sizeof(DWORD)||dwType!=REG_DWORD)
		dwRunCount=0;
	SYSTEMTIME time1={0};
	dwLen=sizeof(SYSTEMTIME);
	lRet=RegQueryValueEx(hSubKey,_T("LastRunTime"),0,&dwType,(PBYTE)&time1,&dwLen);
	
	//显示数据
	if(dwRunCount==0)
	{
		//	SetDlgItemText(IDC_MSG,_T("程序首次运行！"));
		this->SetWindowText("程序首次运行！");
	}
	else
	{
		
		TCHAR szMsg[256]={0};
		CString str;
		str.Format("已经运行了%d次.上次是%d月%d日%.2d:%.2d:%.2d",dwRunCount,time1.wMonth,time1.wDay,time1.wHour,time1.wMinute,time1.wSecond);
		::WritePrivateProfileString("Main","Time",str,strdir+"\\Time.ini");
	}
	//更新注册表
	dwRunCount++;
	GetLocalTime(&time1);
	lRet=RegSetValueEx(hSubKey,_T("RunCount"),0,REG_DWORD,(PBYTE)&dwRunCount,sizeof(DWORD));
	lRet=RegSetValueEx(hSubKey,_T("LastRunTime"),0,REG_BINARY,(PBYTE)&time1,sizeof(SYSTEMTIME));
	RegCloseKey(hSubKey);
}

int CYouYouPlayerDlg::IsMiniShow()
{
   char  exepath[MAX_PATH];
    CString  strdir,tempdir; 
    memset(exepath,0,MAX_PATH); 
    GetModuleFileName(NULL,exepath,MAX_PATH); 
    tempdir=exepath; 
    strdir=tempdir.Left(tempdir.ReverseFind('\\'));
	int temp=GetPrivateProfileInt("Main","IsShow",1,strdir+"\\IsMiniDlg.ini");
	return temp;
}

int CYouYouPlayerDlg::IsMini()
{
    char  exepath[MAX_PATH];
    CString  strdir,tempdir; 
    memset(exepath,0,MAX_PATH); 
    GetModuleFileName(NULL,exepath,MAX_PATH); 
    tempdir=exepath; 
    strdir=tempdir.Left(tempdir.ReverseFind('\\'));
	int temp=GetPrivateProfileInt("Main","IsShow",1,strdir+"\\IsMiniDlg1.ini");
	return temp;
}

void CYouYouPlayerDlg::OnClose() 
{
	// TODO: Add your message handler code here and/or call default
   //AnimateWindow(GetSafeHwnd(),300,AW_HIDE|AW_CENTER);
	CDialog::OnClose();
}

void CYouYouPlayerDlg::OnRemoveall() 
{
	// TODO: Add your control notification handler code here
	         while(m_music.GetCount()!=1)
			{
			for(int i=1;i<m_music.GetCount();i++)
			{
				m_music.DeleteString(i);
			}
			}
}

void CYouYouPlayerDlg::DrawBmp(UINT nID, UINT bmp)
{
	CRect rectclose;
    GetDlgItem(nID)->GetWindowRect(&rectclose);
    ScreenToClient(rectclose);
	    CDC *pDC=GetDC();
		 CBitmap m_bitmap;
		 CDC memdc;
		 memdc.CreateCompatibleDC(pDC);
		 m_bitmap.LoadBitmap(bmp);
		 BITMAP Bmp;
		 m_bitmap.GetBitmap(&Bmp);
		 memdc.SelectObject(&m_bitmap);
		 pDC->BitBlt(rectclose.TopLeft().x,rectclose.TopLeft().y,Bmp.bmWidth,Bmp.bmHeight,&memdc,0,0,SRCCOPY);
		 m_bitmap.DeleteObject();
		 ReleaseDC(&memdc);
		 ReleaseDC(pDC);

}

void CYouYouPlayerDlg::OnMouseMove(UINT nFlags, CPoint point) 
{
	// TODO: Add your message handler code here and/or call default
	CRect m_rtButtExit,rectmini,rectvoice;
	GetDlgItem(IDC_CLOSE)->GetWindowRect(&m_rtButtExit);
    ScreenToClient(m_rtButtExit);
	GetDlgItem(IDC_MINI)->GetWindowRect(&rectmini);
    ScreenToClient(rectmini);
	GetDlgItem(IDC_VOICEBMP)->GetWindowRect(&rectvoice);
    ScreenToClient(rectvoice);
	if (m_rtButtExit.PtInRect(point))
	{
		DrawBmp(IDC_CLOSE,IDB_BITMAP3);
	}
	else if (rectmini.PtInRect(point))
	{
       DrawBmp(IDC_MINI,IDB_BITMAP1);
	}
	else if (rectvoice.PtInRect(point))
	{
      DrawBmp(IDC_VOICEBMP,IDB_BITMAP7);
	}
	else
	{
		DrawBmp(IDC_CLOSE,IDB_BITMAP2);
		DrawBmp(IDC_MINI,IDB_BITMAP4);
		DrawBmp(IDC_VOICEBMP,IDB_BITMAP6);
		if(IsMove)
		{
		CRect rect;
		GetClientRect(&rect);
		ClientToScreen(&rect);
		int xtopleft=rect.TopLeft().x+point.x-pointmove.x;
		int ytopleft=rect.TopLeft().y+point.y-pointmove.y;
		CRect rc;
		GetWindowRect(&rc);
        MoveWindow(xtopleft,ytopleft,rc.Width(),rc.Height(),TRUE);
		}
	}

	CDialog::OnMouseMove(nFlags, point);
}

void CYouYouPlayerDlg::OnLButtonDown(UINT nFlags, CPoint point) 
{
	// TODO: Add your message handler code here and/or call default
	CRect m_rtButtExit,rectmini,rectvoice;
	GetDlgItem(IDC_CLOSE)->GetWindowRect(&m_rtButtExit);
    ScreenToClient(m_rtButtExit);
	GetDlgItem(IDC_MINI)->GetWindowRect(&rectmini);
    ScreenToClient(rectmini);
	GetDlgItem(IDC_VOICEBMP)->GetWindowRect(&rectvoice);
    ScreenToClient(rectvoice);
	if (m_rtButtExit.PtInRect(point))
    //SendMessage(WM_CLOSE);
	SendMessage(WM_SYSCOMMAND, SC_CLOSE, MAKELPARAM(point.x, point.y) );
	else if (rectmini.PtInRect(point))
    SendMessage(WM_SYSCOMMAND, SC_MINIMIZE, MAKELPARAM(point.x, point.y) );
	else if (rectvoice.PtInRect(point))
    SystemVolum();
	else 
	{
	IsMove=TRUE;
	pointmove=point;
	}
	
	CDialog::OnLButtonDown(nFlags, point);
}

void CYouYouPlayerDlg::OnLButtonUp(UINT nFlags, CPoint point) 
{
	// TODO: Add your message handler code here and/or call default
		IsMove=FALSE;
	CDialog::OnLButtonUp(nFlags, point);
}
BOOL CYouYouPlayerDlg::SetTipText(UINT id, NMHDR *pTTTStruct, LRESULT *pResult)  
{  
 TOOLTIPTEXT *pTTT = (TOOLTIPTEXT *)pTTTStruct;          
 UINT nID = pTTTStruct->idFrom;   //得到相应窗口ID，有可能是HWND  
 
 //表明nID是否为HWND
 if (pTTT->uFlags & TTF_IDISHWND)  
 {
  //从HWND得到ID值，当然你也可以通过HWND值来判断
  nID = ::GetDlgCtrlID((HWND)nID);
  if (NULL == nID)
   return FALSE;
  CString str;
  GetDlgItem(nID)->GetWindowText(str);
  strcpy(pTTT->lpszText,str);
  return TRUE;
 }
 return FALSE;  
}  

void CYouYouPlayerDlg::SystemVolum()
{
WinExec("sndvol32.exe",SW_SHOWNORMAL);
}
