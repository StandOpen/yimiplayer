// YouYouPlayerDlg.h : header file
//

#if !defined(AFX_YOUYOUPLAYERDLG_H__E442E01A_0B3E_480D_BBF7_A1869C0D5A55__INCLUDED_)
#define AFX_YOUYOUPLAYERDLG_H__E442E01A_0B3E_480D_BBF7_A1869C0D5A55__INCLUDED_
#include"MyButton.h"
#include"MySlider.h"
#include"LrcDlg.h"
#if _MSC_VER > 1000
#pragma once
#endif // _MSC_VER > 1000
#include"MyMemDC.h"
#include <windows.h>
#include <stdio.h>
#include <mmsystem.h>
#include <shellapi.h>
#include <AFXCOM_.H>
#include<mmsystem.h>
#pragma comment (lib,"winmm.lib")
#define WM_NC WM_USER+1
/////////////////////////////////////////////////////////////////////////////
// CYouYouPlayerDlg dialog

class CYouYouPlayerDlg : public CDialog
{
// Construction
public:
	int IsMini();
	int IsMiniShow();
	void ReadDemo();
	void ReadMusicList();
	void WriteMusicList();
	void changeMini();
	BOOL IsLrcShow;
	void ChangeLrc();
	void IsHide();
	LrcDlg *pdlg;
	static UINT WorkProc(LPVOID lpParam);
	void FindFile();
	CString pathname;
	BOOL StopPlay();
	BOOL m_bPlaying;
	UINT m_nTotalLen;
	TCHAR m_szFullName[MAX_PATH];
	TCHAR m_szShortName[MAX_PATH];
	void ErrBox(DWORD dwErr);
	MCI_OPEN_PARMS mciOpen;
	CYouYouPlayerDlg(CWnd* pParent = NULL);	// standard constructor
public:
	void SystemVolum();
	CPoint pointmove;
	BOOL IsMove;
	void DrawBmp(UINT nID,UINT bmp);
	CStringArray list;
	
// Dialog Data
	//{{AFX_DATA(CYouYouPlayerDlg)
	enum { IDD = IDD_YOUYOUPLAYER_DIALOG };
	MySlider	m_voice;
	//}}AFX_DATA

	// ClassWizard generated virtual function overrides
	//{{AFX_VIRTUAL(CYouYouPlayerDlg)
	public:
	virtual BOOL DestroyWindow();
	protected:
	virtual void DoDataExchange(CDataExchange* pDX);
	//}}AFX_VIRTUAL

// Implementation
protected:
	HICON m_hIcon;
TCHAR m_szFile[MAX_PATH];
     CMyMemDC m_dc;
	 NOTIFYICONDATA NotifyIcon;
	 
	// Generated message map functions
	//{{AFX_MSG(CYouYouPlayerDlg)
	virtual BOOL OnInitDialog();
	afx_msg void OnSysCommand(UINT nID, LPARAM lParam);
	afx_msg void OnPaint();
	afx_msg HCURSOR OnQueryDragIcon();
	afx_msg void OnMusiclist();
	afx_msg void OnPlay();
	afx_msg void OnUpsong();
	afx_msg void OnDownsong();
	afx_msg void OnStop();
	afx_msg void OnAdd();
	afx_msg void OnAddmore();
	afx_msg void OnRemove();
	afx_msg void OnDblclkSonglist();
	afx_msg void OnTimer(UINT nIDEvent);
	afx_msg void OnSetmemory();
	afx_msg void OnSelchangeMemory();
	afx_msg void OnSkin();
	afx_msg HBRUSH OnCtlColor(CDC* pDC, CWnd* pWnd, UINT nCtlColor);
	afx_msg void OnLrc();
	afx_msg void OnMove(int x, int y);
	afx_msg void OnCustomdrawSlider(NMHDR* pNMHDR, LRESULT* pResult);
	afx_msg void OnHScroll(UINT nSBCode, UINT nPos, CScrollBar* pScrollBar);
	afx_msg void OnNotifyIcon(WPARAM wParam,LPARAM IParam);
	afx_msg void OnTopwnd();
	afx_msg void OnClose();
	afx_msg void OnRemoveall();
	afx_msg void OnMouseMove(UINT nFlags, CPoint point);
	afx_msg void OnLButtonDown(UINT nFlags, CPoint point);
	afx_msg void OnLButtonUp(UINT nFlags, CPoint point);
	afx_msg BOOL SetTipText(UINT id, NMHDR *pTTTStruct, LRESULT *pResult);
	//}}AFX_MSG
	DECLARE_MESSAGE_MAP()
};

//{{AFX_INSERT_LOCATION}}
// Microsoft Visual C++ will insert additional declarations immediately before the previous line.

#endif // !defined(AFX_YOUYOUPLAYERDLG_H__E442E01A_0B3E_480D_BBF7_A1869C0D5A55__INCLUDED_)
