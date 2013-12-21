#if !defined(AFX_LRCDLG_H__8C693797_6018_4E8B_98D9_2D957A25C502__INCLUDED_)
#define AFX_LRCDLG_H__8C693797_6018_4E8B_98D9_2D957A25C502__INCLUDED_
#include"MyButton.h"
#include"MulitLineListBox.h"
#if _MSC_VER > 1000
#pragma once
#endif // _MSC_VER > 1000
// LrcDlg.h : header file
//

/////////////////////////////////////////////////////////////////////////////
// LrcDlg dialog

class LrcDlg : public CDialog
{
// Construction
public:
	void OnShut();
	CPoint pointmove;
	BOOL IsMove;
CString strlrc;
	BOOL IsStop;
	int ypos;
	int xpos;
	CString pathname;
	int cursel;
	int lrctime;
	CString strpath;
	LrcDlg(CWnd* pParent = NULL);   // standard constructor

// Dialog Data
	//{{AFX_DATA(LrcDlg)
	enum { IDD = IDD_DIALOG1 };
	//}}AFX_DATA


// Overrides
	// ClassWizard generated virtual function overrides
	//{{AFX_VIRTUAL(LrcDlg)
	public:
	virtual BOOL DestroyWindow();
	protected:
	virtual void DoDataExchange(CDataExchange* pDX);    // DDX/DDV support
	//}}AFX_VIRTUAL

// Implementation
protected:

	// Generated message map functions
	//{{AFX_MSG(LrcDlg)
	virtual BOOL OnInitDialog();
	afx_msg void OnTimer(UINT nIDEvent);
	afx_msg HBRUSH OnCtlColor(CDC* pDC, CWnd* pWnd, UINT nCtlColor);
	afx_msg void OnPaint();
	afx_msg void OnLButtonDown(UINT nFlags, CPoint point);
	afx_msg void OnLButtonUp(UINT nFlags, CPoint point);
	afx_msg void OnMouseMove(UINT nFlags, CPoint point);
	//}}AFX_MSG
	DECLARE_MESSAGE_MAP()
};

//{{AFX_INSERT_LOCATION}}
// Microsoft Visual C++ will insert additional declarations immediately before the previous line.

#endif // !defined(AFX_LRCDLG_H__8C693797_6018_4E8B_98D9_2D957A25C502__INCLUDED_)
