// MySlider.cpp : implementation file
//

#include "stdafx.h"
#include "YouYouPlayer.h"
#include "MySlider.h"


#ifdef _DEBUG
#define new DEBUG_NEW
#undef THIS_FILE
static char THIS_FILE[] = __FILE__;
#endif

/////////////////////////////////////////////////////////////////////////////
// MySlider

MySlider::MySlider()
{
	IsMove=FALSE;
}

MySlider::~MySlider()
{
}


BEGIN_MESSAGE_MAP(MySlider, CSliderCtrl)
//{{AFX_MSG_MAP(MySlider)
ON_WM_PAINT()
	ON_WM_MOUSEMOVE()
	ON_WM_LBUTTONDOWN()
	ON_WM_LBUTTONUP()
	//}}AFX_MSG_MAP
END_MESSAGE_MAP()

/////////////////////////////////////////////////////////////////////////////
// MySlider message handlers

LRESULT MySlider::WindowProc(UINT message, WPARAM wParam, LPARAM lParam) 
{
	// TODO: Add your specialized code here and/or call the base class
	
	return CSliderCtrl::WindowProc(message, wParam, lParam);
}

void MySlider::OnPaint() 
{
	CPaintDC dc(this); // device context for painting
	
	// TODO: Add your message handler code here
	
	// Do not call CSliderCtrl::OnPaint() for painting messages
	// device context for painting

	CRect rcClient;
	GetClientRect(rcClient);
	
	CDC MemDC;
	CBitmap m_bitmap;
	
	MemDC.CreateCompatibleDC(NULL);
	m_bitmap.CreateCompatibleBitmap(&dc, rcClient.Width(), rcClient.Height() );
	
	CBitmap *oldbitmap = (CBitmap*)MemDC.SelectObject(&m_bitmap);
	
	MemDC.FillSolidRect(rcClient, RGB(218,165,32)); //用内存DC绘背景
	
	CRect rc1, rc2;
	GetChannelRect(rc1);
	GetThumbRect(rc2);
	rc2.InflateRect(3,3);
	rc1.bottom*=2;
	rc1.right+=5;
	rc1.TopLeft().y-=2;
	MemDC.FillSolidRect(rc1,RGB(218,165,32));//绘中间那条滑块区域
//	MemDC.Ellipse(rc2);
	dc.BitBlt(0, 0, rcClient.Width(), rcClient.Height(), &MemDC, 0, 0, SRCCOPY);
    this->ReleaseDC(&dc);
	this->ReleaseDC(&MemDC);
	    CDC *pDC=GetDC();
		 CBitmap m_bitmap1;
		 CDC memdc;
		 memdc.CreateCompatibleDC(pDC);
		 m_bitmap1.LoadBitmap(IDB_BITMAP8);
		 BITMAP Bmp;
		 m_bitmap.GetBitmap(&Bmp);
		 memdc.SelectObject(&m_bitmap1);
		 pDC->BitBlt(rc2.TopLeft().x,rc2.TopLeft().y,Bmp.bmWidth,Bmp.bmHeight,&memdc,0,0,SRCCOPY);
		 m_bitmap.DeleteObject();
		 ReleaseDC(&memdc);
		 ReleaseDC(pDC);

}


void MySlider::OnMouseMove(UINT nFlags, CPoint point) 
{
	// TODO: Add your message handler code here and/or call default
	CRect rc;
	GetThumbRect(rc);
	if(point.x>rc.TopLeft().x&&point.x<rc.TopLeft().x+rc.Width())
	{
      HCURSOR hCur=AfxGetApp()->LoadCursor(IDC_CURSOR3);
    ::SetCursor(hCur);
	}
	if(IsMove)
		Invalidate();
	CSliderCtrl::OnMouseMove(nFlags, point);
}

void MySlider::OnLButtonDown(UINT nFlags, CPoint point) 
{
	// TODO: Add your message handler code here and/or call default
	 HCURSOR hCur=AfxGetApp()->LoadCursor(IDC_CURSOR3);
    ::SetCursor(hCur);
	IsMove=TRUE;
		Invalidate();
	CSliderCtrl::OnLButtonDown(nFlags, point);
}

void MySlider::OnLButtonUp(UINT nFlags, CPoint point) 
{
	// TODO: Add your message handler code here and/or call default
	IsMove=FALSE;
		Invalidate();
	CSliderCtrl::OnLButtonUp(nFlags, point);
}
