#if !defined(AFX_MYLISTBOX_H__4CAC4F7A_A658_447F_A691_2C2E7E20AD16__INCLUDED_)
#define AFX_MYLISTBOX_H__4CAC4F7A_A658_447F_A691_2C2E7E20AD16__INCLUDED_

#if _MSC_VER > 1000
#pragma once
#endif // _MSC_VER > 1000
// MyListBox.h : header file
//

/////////////////////////////////////////////////////////////////////////////
// MyListBox window

class MyListBox : public CListBox
{
// Construction
public:
	MyListBox();

// Attributes
public:

// Operations
public:

// Overrides
	// ClassWizard generated virtual function overrides
	//{{AFX_VIRTUAL(MyListBox)
	//}}AFX_VIRTUAL

// Implementation
public:
	void AppendString(LPCSTR lpszText);
	virtual ~MyListBox();

	// Generated message map functions
protected:
	//{{AFX_MSG(MyListBox)
	afx_msg void DrawItem(LPDRAWITEMSTRUCT lpDrawItemStruct);
	afx_msg void MeasureItem(LPMEASUREITEMSTRUCT lpMeasureItemStruct);
	//}}AFX_MSG

	DECLARE_MESSAGE_MAP()
};

/////////////////////////////////////////////////////////////////////////////

//{{AFX_INSERT_LOCATION}}
// Microsoft Visual C++ will insert additional declarations immediately before the previous line.

#endif // !defined(AFX_MYLISTBOX_H__4CAC4F7A_A658_447F_A691_2C2E7E20AD16__INCLUDED_)
