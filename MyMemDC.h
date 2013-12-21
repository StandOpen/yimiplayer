// MyMemDC.h: interface for the CMyMemDC class.
//
//////////////////////////////////////////////////////////////////////
#include"gdiplus.h"

#define RectWidth(x) ((x)->right-(x)->left)
#define RectHeight(x) ((x)->bottom-(x)->top)
#if !defined(AFX_MYMEMDC_H__4F28864C_93EF_45B7_9B2E_01A2DC16C81F__INCLUDED_)
#define AFX_MYMEMDC_H__4F28864C_93EF_45B7_9B2E_01A2DC16C81F__INCLUDED_

#if _MSC_VER > 1000
#pragma once
#endif // _MSC_VER > 1000

class CMyMemDC  
{
public:
	CMyMemDC();
	virtual ~CMyMemDC();
public:
	LPRECT GetImageRect();
	int GetHeight();
	int GetWidth();
	HBITMAP GetBitmap() const;
	BOOL CreateFromFile(LPCTSTR lpFile);
	BOOL CreateFromFile(LPCTSTR lpFile,LPRECT lprcBmp);
	BOOL CreateFromFile(LPCTSTR lpFile,HDC hDC,LPRECT lprcBmp);
	operator HDC();
    HDC GetDC()const;
	BOOL DeleteObj();
	BOOL CreateObj(HDC hDC,int nWidth,int nHeight);
protected:
	RECT m_rcImg;
	HBITMAP m_hOldBmp;
	HBITMAP m_hBmp;
	HDC m_hDC;
 
};

#endif // !defined(AFX_MYMEMDC_H__4F28864C_93EF_45B7_9B2E_01A2DC16C81F__INCLUDED_)
