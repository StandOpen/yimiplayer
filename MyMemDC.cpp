// MyMemDC.cpp: implementation of the CMyMemDC class.
//
//////////////////////////////////////////////////////////////////////

#include "stdafx.h"
#include "MyMemDC.h"

#ifdef _DEBUG
#undef THIS_FILE
static char THIS_FILE[]=__FILE__;
#define new DEBUG_NEW
#endif

//////////////////////////////////////////////////////////////////////
// Construction/Destruction
//////////////////////////////////////////////////////////////////////

CMyMemDC::CMyMemDC()
{
m_hDC=NULL;
	m_hBmp=NULL;
	m_hOldBmp=NULL;
	SetRect(&m_rcImg,0,0,0,0);
}

CMyMemDC::~CMyMemDC()
{
DeleteObj();
}
BOOL CMyMemDC::CreateObj(HDC hDC,int nWidth,int nHeight)
{
	if(nWidth<=0||nHeight<=0)
	{
		return FALSE;
	}
	DeleteObj();
	SetRect(&m_rcImg,0,0,nWidth,nHeight);
	if(hDC==NULL)
	{
		HWND hDesktop=GetDesktopWindow();
		HDC hDC1=::GetDC(hDesktop);
		m_hDC=CreateCompatibleDC(hDC1);
		m_hBmp=CreateCompatibleBitmap(hDC1,nWidth,nHeight);
		ReleaseDC(hDesktop,hDC1);
	}
	else
	{
		m_hDC=CreateCompatibleDC(hDC);
		m_hBmp=CreateCompatibleBitmap(hDC,nWidth,nHeight);
	}
	m_hOldBmp=(HBITMAP)SelectObject(m_hDC,m_hBmp);
	return (m_hDC!=NULL&&m_hBmp!=NULL);
}

BOOL CMyMemDC::DeleteObj()
{
	HDC hTempDC=m_hDC;
	HBITMAP hTempBmp=m_hBmp;
	if(m_hDC!=NULL)
	{
		m_hDC=NULL;
		SelectObject(m_hDC,m_hOldBmp);
		DeleteDC(hTempDC);
	}
	if(m_hBmp!=NULL)
	{
		m_hBmp=NULL;
		DeleteObject(hTempBmp);
	}
	return TRUE;
}
HDC CMyMemDC::GetDC() const
{
	return this==NULL?NULL:m_hDC;
	 
}
CMyMemDC::operator HDC()
{
	return GetDC();
}
BOOL CMyMemDC::CreateFromFile(LPCTSTR lpFile,HDC hDC,LPRECT lprcBmp)
{
	try
	{
		WCHAR szFile[MAX_PATH]={0};
#ifdef UNICODE
		_tcscpy(szFile,lpFile);
#else
		MultiByteToWideChar(CP_ACP,0,lpFile,-1,szFile,sizeof(szFile)/sizeof(szFile[0]));
#endif
		Gdiplus::Image img(szFile);
		/*
		if(img.GetLastStatus()!=Gdiplus::OK)
		{
			return FALSE;
		}
		*/
		if(lprcBmp==NULL)
		{
			SetRect(&m_rcImg,0,0,img.GetWidth(),img.GetHeight());
			lprcBmp=&m_rcImg;
		}
		else
		{
			SetRect(&m_rcImg,0,0,lprcBmp->right,lprcBmp->bottom);
		}
		if(!CreateObj(hDC,lprcBmp->right,lprcBmp->bottom))
			return FALSE;
		Gdiplus::Graphics g(m_hDC);
		g.DrawImage(&img,0,0,lprcBmp->right,lprcBmp->bottom);
		return TRUE;
	}
	catch(...)
	{
		return FALSE;
	}
}
HBITMAP CMyMemDC::GetBitmap()const
{
	return m_hBmp;
}
BOOL CMyMemDC::CreateFromFile(LPCTSTR lpFile)
{
	return CreateFromFile(lpFile,NULL);
}
BOOL CMyMemDC::CreateFromFile(LPCTSTR lpFile,LPRECT lprcBmp)
{
	HWND hDesktop=GetDesktopWindow();
	HDC hDC=::GetDC(hDesktop);
	BOOL bRet=CreateFromFile(lpFile,hDC,lprcBmp);
	ReleaseDC(hDesktop,hDC);
	return bRet;
}
int CMyMemDC::GetWidth()
{
	return RectWidth(&m_rcImg);
}
int CMyMemDC::GetHeight()
{
	return RectHeight(&m_rcImg);
}
LPRECT CMyMemDC::GetImageRect()
{
	return &m_rcImg;
 
} 