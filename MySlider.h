#if !defined(AFX_MYSLIDER_H__F1222893_FD3B_484B_B5DF_849771C23FC7__INCLUDED_)
#define AFX_MYSLIDER_H__F1222893_FD3B_484B_B5DF_849771C23FC7__INCLUDED_

#if _MSC_VER > 1000
#pragma once
#endif // _MSC_VER > 1000
// MySlider.h : header file
//

/////////////////////////////////////////////////////////////////////////////
// MySlider window

class MySlider : public CSliderCtrl
{
// Construction

public:
	MySlider();

// Attributes
public:

// Operations
public:

// Overrides
	// ClassWizard generated virtual function overrides
	//{{AFX_VIRTUAL(MySlider)
	protected:
	virtual LRESULT WindowProc(UINT message, WPARAM wParam, LPARAM lParam);
	//}}AFX_VIRTUAL

// Implementation
public:
	virtual ~MySlider();

	// Generated message map functions
protected:
	//{{AFX_MSG(MySlider)
	afx_msg void OnPaint();
	afx_msg void OnMouseMove(UINT nFlags, CPoint point);
	afx_msg void OnLButtonDown(UINT nFlags, CPoint point);
	afx_msg void OnLButtonUp(UINT nFlags, CPoint point);
	//}}AFX_MSG

	DECLARE_MESSAGE_MAP()

public: 
	BOOL IsMove;

private: 

};

/////////////////////////////////////////////////////////////////////////////

//{{AFX_INSERT_LOCATION}}
// Microsoft Visual C++ will insert additional declarations immediately before the previous line.

#endif // !defined(AFX_MYSLIDER_H__F1222893_FD3B_484B_B5DF_849771C23FC7__INCLUDED_)
