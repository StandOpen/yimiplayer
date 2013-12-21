// MulitLineListBox.cpp : implementation file
//

#include "stdafx.h"
#include "MulitLineListBox.h"

#ifdef _DEBUG
#define new DEBUG_NEW
#undef THIS_FILE
static char THIS_FILE[] = __FILE__;
#endif


/////////////////////////////////////////////////////////////////////////////  
// CMulitLineListBox  
  
CMulitLineListBox::CMulitLineListBox()  
{  
}  
  
CMulitLineListBox::~CMulitLineListBox()  
{  
}  
  
  
BEGIN_MESSAGE_MAP(CMulitLineListBox, CListBox)  
    //{{AFX_MSG_MAP(CMulitLineListBox)  
    ON_WM_DESTROY()  
	ON_WM_MOUSEMOVE()
	//}}AFX_MSG_MAP
END_MESSAGE_MAP()  
  
/////////////////////////////////////////////////////////////////////////////  
// CMulitLineListBox message handlers  
void CMulitLineListBox::AppendString(LPCSTR lpszText, COLORREF fgColor, COLORREF bgColor)  
{  
    LISTBOX_COLOR* pInfo = new LISTBOX_COLOR;  
  
    pInfo->strText.Format(_T("%s"), lpszText);  
    pInfo->fgColor = fgColor;   
    pInfo->bgColor = bgColor;  
  
    SetItemDataPtr(InsertString(-1,pInfo->strText), pInfo);  
}  
  
void CMulitLineListBox::MeasureItem(LPMEASUREITEMSTRUCT lpMeasureItemStruct)   
{  
    // TODO: Add your code to determine the size of specified item  
   /* ASSERT(lpMeasureItemStruct->CtlType == ODT_LISTBOX);  
      
    CString strText(_T(""));  
    GetText(lpMeasureItemStruct->itemID, strText);  
    ASSERT(TRUE != strText.IsEmpty());  
  
    CRect rect;  
    GetItemRect(lpMeasureItemStruct->itemID, &rect);  
      
    CDC* pDC = GetDC();   
    lpMeasureItemStruct->itemHeight = pDC->DrawText(strText, -1, rect, DT_WORDBREAK | DT_CALCRECT);   
    ReleaseDC(pDC);  
	*/
LPCTSTR lpszText = (LPCTSTR) lpMeasureItemStruct->itemData;  
 ASSERT(lpszText != NULL);  
 CSize   sz;  
 CDC* pDC = GetDC();  
   
 sz = pDC->GetTextExtent(lpszText);  
 lpMeasureItemStruct->itemHeight=2*sz.cy;
 Height=2*sz.cy;
 ReleaseDC(pDC);  
}  
  
void CMulitLineListBox::DrawItem(LPDRAWITEMSTRUCT lpDrawItemStruct)   
{  
    // TODO: Add your code to draw the specified item  
    ASSERT(lpDrawItemStruct->CtlType == ODT_LISTBOX);  
  
    LISTBOX_COLOR* pListBox = (LISTBOX_COLOR*)GetItemDataPtr(lpDrawItemStruct->itemID);  
    ASSERT(NULL != pListBox);  
  
    CDC dc;  
      
    dc.Attach(lpDrawItemStruct->hDC);  
      
    // Save these value to restore them when done drawing.  
    COLORREF crOldTextColor = dc.GetTextColor();  
    COLORREF crOldBkColor = dc.GetBkColor();  
      
    // If this item is selected, set the background color   
    // and the text color to appropriate values. Also, erase  
    // rect by filling it with the background color.  
    if ((lpDrawItemStruct->itemAction | ODA_SELECT) &&  
        (lpDrawItemStruct->itemState & ODS_SELECTED))  
    {  
        dc.SetTextColor(pListBox->bgColor);  
        dc.SetBkColor(pListBox->fgColor);  
        dc.FillSolidRect(&lpDrawItemStruct->rcItem, pListBox->fgColor);  
    }  
    else  
    {  
        dc.SetTextColor(pListBox->fgColor);  
        dc.SetBkColor(pListBox->bgColor);  
        dc.FillSolidRect(&lpDrawItemStruct->rcItem, pListBox->bgColor);  
    }  
      
    lpDrawItemStruct->rcItem.left +=5;  
    // Draw the text.  
      
    dc.DrawText(pListBox->strText,pListBox->strText.GetLength(), &lpDrawItemStruct->rcItem, DT_WORDBREAK|DT_CENTER|DT_SINGLELINE|DT_VCENTER);  
      
    // Reset the background color and the text color back to their  
    // original values.  
    dc.SetTextColor(crOldTextColor);  
    dc.SetBkColor(crOldBkColor);  
      
    dc.Detach(); 
	
}  
  
  
void CMulitLineListBox::OnDestroy()   
{  
    int nCount = GetCount();  
    for(int i=0; i<nCount; i++)  
    {  
        LISTBOX_COLOR* pList = (LISTBOX_COLOR*)GetItemDataPtr(i);  
        delete pList;  
        pList = NULL;  
    }  
  
    CListBox::OnDestroy();  
      
    // TODO: Add your message handler code here   
}  


void CMulitLineListBox::OnMouseMove(UINT nFlags, CPoint point) 
{
	// TODO: Add your message handler code here and/or call default
	int currentnumber=point.y/Height;
	int firstnumber=GetTopIndex();
	static int prenumber=currentnumber+firstnumber;
	static	COLORREF oldbgColor=RGB(255,0,0);
	if((currentnumber+firstnumber)<GetCount()&&(currentnumber+firstnumber)!=prenumber)
	{
	CRect rc;
	GetClientRect(&rc);
	CRect rect(0,currentnumber*Height,rc.Width(),(currentnumber+1)*Height);
    CRect prerect(0,(prenumber-firstnumber)*Height,rc.Width(),(prenumber-firstnumber+1)*Height);
	LISTBOX_COLOR* pListBox = (LISTBOX_COLOR*)GetItemDataPtr(currentnumber+firstnumber);
    LISTBOX_COLOR* prepListBox = (LISTBOX_COLOR*)GetItemDataPtr(prenumber);
	static int num=0;
	if(num!=0)
	{
	prepListBox->bgColor=oldbgColor;
	}
	num=1;
	oldbgColor=pListBox->bgColor;
	pListBox->bgColor=RGB(147,112,219);
	InvalidateRect((LPCRECT)rect,FALSE);
    InvalidateRect((LPCRECT)prerect,FALSE);
	prenumber=currentnumber+firstnumber;
	}
	//CRect client;
   // GetWindowRect(&client);
//	if(point.x<0||point.y<0||point.x>)
	CListBox::OnMouseMove(nFlags, point);
}
