#if !defined(AFX_MULITLINELISTBOX_H__2FDD4D2A_8F0E_4353_A208_3FCEA2662221__INCLUDED_)
#define AFX_MULITLINELISTBOX_H__2FDD4D2A_8F0E_4353_A208_3FCEA2662221__INCLUDED_
#if _MSC_VER > 1000
#pragma once
#endif // _MSC_VER > 1000
// MulitLineListBox.h : header file
//

/////////////////////////////////////////////////////////////////////////////
// CMulitLineListBox window

typedef struct _LISTBOX_COLOR_  
{  
    CString strText;  
    COLORREF fgColor;  
    COLORREF bgColor;  
}LISTBOX_COLOR, *PLISTBOX_COLOR;  
  
class CMulitLineListBox : public CListBox  
{  
// Construction  
public:  
    CMulitLineListBox();  
// Attributes  
public:  
    void AppendString(LPCSTR lpszText, COLORREF fgColor, COLORREF bgColor);  
// Operations  
public:  
      
// Overrides  
    // ClassWizard generated virtual function overrides  
    //{{AFX_VIRTUAL(CMulitLineListBox)  
    public:  
    virtual void MeasureItem(LPMEASUREITEMSTRUCT lpMeasureItemStruct);  
    virtual void DrawItem(LPDRAWITEMSTRUCT lpDrawItemStruct);  
    //}}AFX_VIRTUAL  
  
// Implementation  
public:  
	LPMEASUREITEMSTRUCT lpMeasureItemStruct1;
	int Height;
    virtual ~CMulitLineListBox();  
  
    // Generated message map functions  
protected:  
    //{{AFX_MSG(CMulitLineListBox)  
    afx_msg void OnDestroy();  
	afx_msg void OnMouseMove(UINT nFlags, CPoint point);
	//}}AFX_MSG
  
    DECLARE_MESSAGE_MAP()  
};  
  
/////////////////////////////////////////////////////////////////////////////  
  
//{{AFX_INSERT_LOCATION}}  
// Microsoft Visual C++ will insert additional declarations immediately before the previous line.  
  
#endif // !defined(AFX_MULITLINELISTBOX_H__D705CB99_9FD0_424E_BD71_027547449AE5__INCLUDED_)  
