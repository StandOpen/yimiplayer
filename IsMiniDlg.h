#if !defined(AFX_ISMINIDLG_H__EFCF488F_1F8D_4754_A886_584382E7EE05__INCLUDED_)
#define AFX_ISMINIDLG_H__EFCF488F_1F8D_4754_A886_584382E7EE05__INCLUDED_
#include"MyButton.h"
#if _MSC_VER > 1000
#pragma once
#endif // _MSC_VER > 1000
// IsMiniDlg.h : header file
//

/////////////////////////////////////////////////////////////////////////////
// IsMiniDlg dialog

class IsMiniDlg : public CDialog
{
// Construction
public:
	IsMiniDlg(CWnd* pParent = NULL);   // standard constructor

// Dialog Data
	//{{AFX_DATA(IsMiniDlg)
	enum { IDD = IDD_DIALOG2 };
	CMyButton	m_yes;
	CMyButton	m_no;
	//}}AFX_DATA


// Overrides
	// ClassWizard generated virtual function overrides
	//{{AFX_VIRTUAL(IsMiniDlg)
	protected:
	virtual void DoDataExchange(CDataExchange* pDX);    // DDX/DDV support
	//}}AFX_VIRTUAL

// Implementation
protected:

	// Generated message map functions
	//{{AFX_MSG(IsMiniDlg)
	afx_msg void OnRadio1();
	virtual void OnOK();
	virtual void OnCancel();
	virtual BOOL OnInitDialog();
	afx_msg void OnPaint();
	afx_msg HBRUSH OnCtlColor(CDC* pDC, CWnd* pWnd, UINT nCtlColor);
	//}}AFX_MSG
	DECLARE_MESSAGE_MAP()
};

//{{AFX_INSERT_LOCATION}}
// Microsoft Visual C++ will insert additional declarations immediately before the previous line.

#endif // !defined(AFX_ISMINIDLG_H__EFCF488F_1F8D_4754_A886_584382E7EE05__INCLUDED_)
