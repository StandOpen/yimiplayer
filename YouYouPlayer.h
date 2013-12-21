// YouYouPlayer.h : main header file for the YOUYOUPLAYER application
//

#if !defined(AFX_YOUYOUPLAYER_H__4A81E79F_5A52_4418_91B5_E4D49A566AF6__INCLUDED_)
#define AFX_YOUYOUPLAYER_H__4A81E79F_5A52_4418_91B5_E4D49A566AF6__INCLUDED_

#if _MSC_VER > 1000
#pragma once
#endif // _MSC_VER > 1000

#ifndef __AFXWIN_H__
	#error include 'stdafx.h' before including this file for PCH
#endif

#include "resource.h"		// main symbols

/////////////////////////////////////////////////////////////////////////////
// CYouYouPlayerApp:
// See YouYouPlayer.cpp for the implementation of this class
//

class CYouYouPlayerApp : public CWinApp
{
public:
	CYouYouPlayerApp();
 GdiplusStartupInput m_gdiplusStartupInput;
	ULONG_PTR m_gdiplusToken;
// Overrides
	// ClassWizard generated virtual function overrides
	//{{AFX_VIRTUAL(CYouYouPlayerApp)
	public:
	virtual BOOL InitInstance();
	virtual int ExitInstance();
	//}}AFX_VIRTUAL

// Implementation

	//{{AFX_MSG(CYouYouPlayerApp)
		// NOTE - the ClassWizard will add and remove member functions here.
		//    DO NOT EDIT what you see in these blocks of generated code !
	//}}AFX_MSG
	DECLARE_MESSAGE_MAP()
};


/////////////////////////////////////////////////////////////////////////////

//{{AFX_INSERT_LOCATION}}
// Microsoft Visual C++ will insert additional declarations immediately before the previous line.

#endif // !defined(AFX_YOUYOUPLAYER_H__4A81E79F_5A52_4418_91B5_E4D49A566AF6__INCLUDED_)
