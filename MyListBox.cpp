// MyListBox.cpp : implementation file
//

#include "stdafx.h"
#include "youyouplayer.h"
#include "MyListBox.h"

#ifdef _DEBUG
#define new DEBUG_NEW
#undef THIS_FILE
static char THIS_FILE[] = __FILE__;
#endif

/////////////////////////////////////////////////////////////////////////////
// MyListBox

MyListBox::MyListBox()
{
}

MyListBox::~MyListBox()
{
}


BEGIN_MESSAGE_MAP(MyListBox, CListBox)
	//{{AFX_MSG_MAP(MyListBox)
	ON_WM_DRAWITEM_REFLECT()
	ON_WM_MEASUREITEM_REFLECT()
	//}}AFX_MSG_MAP
END_MESSAGE_MAP()

/////////////////////////////////////////////////////////////////////////////
// MyListBox message handlers

void MyListBox::DrawItem(LPDRAWITEMSTRUCT lpDrawItemStruct) 
{
	// TODO: Add your message handler code here
ASSERT(lpDrawItemStruct->CtlType == ODT_LISTBOX);  
 LPCTSTR lpszText = (LPCTSTR) lpDrawItemStruct->itemData;  
 ASSERT(lpszText != NULL);  
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
  dc.SetTextColor(::GetSysColor(COLOR_HIGHLIGHTTEXT));  
  dc.SetBkColor(::GetSysColor(COLOR_HIGHLIGHT));  
  dc.FillSolidRect(&lpDrawItemStruct->rcItem,   
   ::GetSysColor(COLOR_HIGHLIGHT));  
 }  
 else  
 {  
  if(lpDrawItemStruct->itemID%2)  
   dc.FillSolidRect(&lpDrawItemStruct->rcItem, RGB(128,128,128));  
  else  
   dc.FillSolidRect(&lpDrawItemStruct->rcItem, RGB(255,128,255));  
 }  
   
 // If this item has the focus, draw a red frame around the  
 // item's rect.  
 if ((lpDrawItemStruct->itemAction | ODA_FOCUS) &&  
  (lpDrawItemStruct->itemState & ODS_FOCUS))  
 {  
  CBrush br(RGB(218,165,32));  
  dc.FrameRect(&lpDrawItemStruct->rcItem, &br);  
 }  
 lpDrawItemStruct->rcItem.left += 5;  
 // Draw the text.  
 /* dc.DrawText(  
  lpszText,  
  strlen(lpszText),  
  &lpDrawItemStruct->rcItem,  
  DT_LEFT|DT_SINGLELINE|DT_VCENTER);  
  */
 SetItemDataPtr(InsertString(-1,lpszText),NULL);
 // Reset the background color and the text color back to their  
 // original values.  
 dc.SetTextColor(crOldTextColor);  
 dc.SetBkColor(crOldBkColor);  
   
 dc.Detach();  
}

void MyListBox::MeasureItem(LPMEASUREITEMSTRUCT lpMeasureItemStruct) 
{
	// TODO: Add your message handler code here
	ASSERT(lpMeasureItemStruct->CtlType == ODT_LISTBOX);  
 LPCTSTR lpszText = (LPCTSTR) lpMeasureItemStruct->itemData;  
 ASSERT(lpszText != NULL);  
 CSize   sz;  
 CDC*    pDC = GetDC();  
   
 sz = pDC->GetTextExtent(lpszText);  
   
 ReleaseDC(pDC);  
   
 lpMeasureItemStruct->itemHeight = 2*sz.cy; 
}

void MyListBox::AppendString(LPCSTR lpszText)
{
 // LISTBOX_COLOR* pInfo = new LISTBOX_COLOR; 
  CString strText;
   strText.Format(_T("%s"), lpszText);   
   SetItemDataPtr(InsertString(-1,strText),this);  
}
