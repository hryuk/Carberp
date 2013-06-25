#include "stdafx.h"   
#include "CListBoxEBX.h"   
    
#ifdef _DEBUG   
#define new DEBUG_NEW   
#undef THIS_FILE   
static char THIS_FILE[] = __FILE__;   
#endif   
   
/////////////////////////////////////////////////////////////////////////////   
// CListBoxEBX   
   
//-------------------------------------------------------------------   
//   
CListBoxEBX::CListBoxEBX()   
{   
    m_pSuper = (CListBox*)this;   
    m_iItemHeight = 0;   
}   
   
CListBoxEBX::~CListBoxEBX(){}   
   
BEGIN_MESSAGE_MAP(CListBoxEBX, CListBox)   
    //{{AFX_MSG_MAP(CListBoxEBX)   
    ON_WM_DESTROY()   
    ON_WM_SYSCOLORCHANGE()   
    //}}AFX_MSG_MAP   
END_MESSAGE_MAP()   
   
/////////////////////////////////////////////////////////////////////////////   
// CListBoxEBX message handlers   
   
//-------------------------------------------------------------------   
//   
   
void CListBoxEBX::OnSysColorChange()   
{   
    CListBox::OnSysColorChange();   
    this->RedrawWindow();   
}   
   
void CListBoxEBX::OnDestroy()   
{   
    //Clean up items and their strings   
    ResetContent();   
   
    CListBox::OnDestroy();   
}   
   
void CListBoxEBX::DrawItem(LPDRAWITEMSTRUCT lpDIS)   
{   
    if ((int)lpDIS->itemID < 0)   
        return;   
   
    int     iPenSize    = 3;   
    CDC     *pDC        = CDC::FromHandle(lpDIS->hDC);   
   
    LItem   *pItem      = Item((int)lpDIS->itemID);      // pointer to data item   
   
   
    COLORREF bg         = pItem->cBg;   
    COLORREF fg         = pItem->cFg;   
   
    if(bg == DEF_COL) bg = ::GetSysColor(COLOR_WINDOW);   
    if(fg == DEF_COL) fg = ::GetSysColor(COLOR_WINDOWTEXT);   
   
   
    // Draw background   
    // -------------------------------------------------------------------   
    CBrush brush(bg);   
    pDC->FillRect(&lpDIS->rcItem, &brush);   
   
    // Draw text   
    //--------------------------------------------------------------------   
    UINT nFormat = DT_SINGLELINE | pItem->uVal | pItem->uHal;   
   
    int      nOldBkMode     = pDC->SetBkMode(TRANSPARENT);   
    COLORREF cOldFg         = pDC->SetTextColor(fg);   
    CString  sItemText;   
   
    CRect rc(lpDIS->rcItem);   
    rc.DeflateRect(iPenSize, iPenSize);   
   
    GetText((int)lpDIS->itemID, sItemText);   
    pDC->DrawText(sItemText, -1, &rc, nFormat);   
   
    pDC->SetTextColor(cOldFg);   
    pDC->SetBkMode(nOldBkMode);   
   
   
    // Draw disabled   
    //--------------------------------------------------------------------   
    if(pItem->bActive == FALSE)   
    {   
        CRect rc(lpDIS->rcItem);   
   
        rc.DeflateRect(iPenSize, iPenSize);   
   
        CDC memDC0;   
   
        memDC0.CreateCompatibleDC(pDC);   
   
       AlphaBlendU(*pDC, rc.left, rc.top, rc.Width(), rc.Height(),   
            memDC0, rc.left, rc.top, rc.Width(), rc.Height(), 50);   
   
        memDC0.DeleteDC();   
    }   
   
         // if selected no 3D border   
     //--------------------------------------------------------------------   
     if((lpDIS->itemAction & ODA_FOCUS) && (lpDIS->itemState & ODS_FOCUS))   
     {   
         CRect rc(lpDIS->rcItem);   
         for(int i = 0; i < iPenSize; i++)   
         {   
             pDC->DrawFocusRect(rc);   
             rc.DeflateRect(1, 1);   
         }   
     }   
}   
    
void CListBoxEBX::MeasureItem(LPMEASUREITEMSTRUCT lpMIS)   
{   
    if(m_iItemHeight == 0)   
    {   
        CPaintDC dc(this);   
        CRect r;   
        dc.DrawText((LPCTSTR)"M", -1, &r, DT_CALCRECT);   
        lpMIS->itemHeight = r.Height() + 6;   
    }   
    else   
        lpMIS->itemHeight = m_iItemHeight + 6;   
   
}   
   
   
// private   
int CListBoxEBX::Ix(int ix)   
{   
    if(GetCount() == 0)                 // not populated yet   
        return -1;   
   
    if(ix == -1)                        // asking for the selected item   
        return GetCurSel();   
    else if(ix < 0 || ix >= GetCount())   // out of range   
        return -1;   
    else   
        return ix;   
}   
   
// private   
CListBoxEBX::LItem* CListBoxEBX::Item(int ix)   
{   
    int i =Ix(ix);   
   
    if(i == -1) return NULL;   
   
    return (LItem *)m_pSuper->GetItemData(i);   
}   
   
// Member functions   
// public   
int CListBoxEBX::AddItem   
    (LPCTSTR lpszItem, COLORREF bg, COLORREF fg,DWORD_PTR	id, UINT hal, UINT val, BOOL active, DWORD res)   
{   
    // Add to the end   
    return InsertItem(lpszItem, GetCount(), bg, fg,id, hal, val, active, res);   
}   
   
    
int CListBoxEBX::InsertItem   
    (LPCTSTR lpszItem, int ix, COLORREF bg, COLORREF fg,DWORD_PTR	id, UINT hal, UINT val, BOOL active, DWORD res)   
{   
    if(ix < 0 || ix > GetCount()) //out of range thing   
        return LB_ERR;   
   
   
    int iRet = m_pSuper->InsertString(ix, lpszItem);   
   
    if(iRet == LB_ERR)   
        return iRet;   
   
    LItem *lbi = new LItem;   
   
    lbi->cBg	= bg;   
    lbi->cFg	= fg;   
    lbi->uHal   = hal;   
    lbi->uVal   = val;   
    lbi->bActive= active;   
    lbi->dw     = res;   
	lbi->id		=id;
    if(m_pSuper->SetItemData(ix, (DWORD)lbi) == LB_ERR)   
        return LB_ERR;   
   
    return iRet;   
}   
   
BOOL CListBoxEBX::RemoveAt(int ix)   
{   
    int i =Ix(ix);   
   
    if(i == -1) return FALSE;   
   
    LItem *plbi = (LItem*)m_pSuper->GetItemData(i);   
  
    if(m_pSuper->DeleteString(i) == LB_ERR || plbi == NULL)   
        return FALSE;   
   
    delete plbi;   
   
    return TRUE;   
}  
DWORD_PTR CListBoxEBX::GetItemData1(int Item)
{   
    int i =Ix(Item);   
   
    if(i == -1) return 0;   
   
    LItem *plbi = (LItem*)m_pSuper->GetItemData(i);   
       
   
    return plbi->id;   
}
   
void CListBoxEBX::ResetContent()   
{   
    while(GetCount()) RemoveAt(0);   
}   
   
   
BOOL CListBoxEBX::SetBg(COLORREF color, int ix)   
{   
    LItem *plbi = Item(ix);   
   
    if(!plbi) return FALSE;   
   
    plbi->cBg = color;   
   
    RedrawWindow();   
   
    return TRUE;   
}   
   
BOOL CListBoxEBX::SetFg(COLORREF color, int ix)   
{   
    LItem *plbi = Item(ix);   
   
    if(!plbi) return FALSE;   
   
    plbi->cFg = color;   
   
    RedrawWindow();   
   
    return TRUE;   
}   
   
BOOL CListBoxEBX::SetVal(UINT align, int ix)   
{   
    LItem *plbi = Item(ix);   
   
    if(!plbi) return FALSE;   
   
    plbi->uVal = align;   
   
    RedrawWindow();   
   
    return TRUE;   
}   
   
BOOL CListBoxEBX::SetHal(UINT align, int ix)   
{   
    LItem *plbi = Item(ix);   
   
    if(!plbi) return FALSE;   
   
    plbi->uHal = align;   
   
    RedrawWindow();   
   
    return TRUE;   
}   
   
BOOL CListBoxEBX::SetActive(BOOL bActive, int ix)   
{   
    LItem *plbi = Item(ix);   
   
    if(!plbi) return FALSE;   
   
    plbi->bActive = bActive;   
   
    RedrawWindow();   
   
    return TRUE;   
}   
   
BOOL CListBoxEBX::SetData(DWORD data, int ix)   
{   
    LItem *plbi = Item(ix);   
   
    if(!plbi) return FALSE;   
   
    plbi->dw = data;   
   
    RedrawWindow();   
   
    return TRUE;   
}   
   
   
// private   
bool CListBoxEBX::AlphaBlendU   
    (   
        HDC dcDest, int x, int y, int cx, int cy,   
        HDC dcSrc, int sx, int sy, int scx, int scy, int alpha   
    )   
{   
    BITMAPINFOHEADER BMI;   
    // Fill in the header info.   
    BMI.biSize = sizeof(BITMAPINFOHEADER);   
    BMI.biWidth = cx;   
    BMI.biHeight = cy;   
    BMI.biPlanes = 1;   
    BMI.biBitCount = 32;   
    BMI.biCompression = BI_RGB;   // No compression   
    BMI.biSizeImage = 0;   
    BMI.biXPelsPerMeter = 0;   
    BMI.biYPelsPerMeter = 0;   
    BMI.biClrUsed = 0;           // Always use the whole palette.   
    BMI.biClrImportant = 0;   
    
    BYTE * pSrcBits;   
    HBITMAP hbmSrc;   
    // Create DIB section in shared memory   
    hbmSrc = CreateDIBSection (dcSrc, (BITMAPINFO *)&BMI,   
        DIB_RGB_COLORS, (void **)&pSrcBits, 0, 0l);   
   
    BYTE * pDestBits;   
    HBITMAP hbmDest;   
    // Create DIB section in shared memory   
    hbmDest = CreateDIBSection (dcDest, (BITMAPINFO *)&BMI,   
        DIB_RGB_COLORS, (void **)&pDestBits, 0, 0l);   
   
   
    // Copy our source and destination bitmaps onto our DIBSections,   
    // so we can get access to their bits using the BYTE *'s we passed into CreateDIBSection   
   
    HDC dc = CreateCompatibleDC(NULL);   
   
    HBITMAP dcOld = (HBITMAP) SelectObject(dc, hbmSrc);   
   
    if (!StretchBlt(dc, 0, 0, cx, cy, dcSrc, sx, sy, scx, scy, SRCCOPY))   
        return false;   
   
    SelectObject(dc, hbmDest);   
    if (!StretchBlt(dc, 0, 0, cx, cy, dcDest, x, y, cx, cy, SRCCOPY))   
        return false;   
   
    SelectObject(dc, dcOld);   
    DeleteDC(dc);   
   
    for (int j = 0; j < cy; ++j)   
    {   
       LPBYTE pbDestRGB = (LPBYTE)&((DWORD*)pDestBits)[j * cx];   
        LPBYTE pbSrcRGB = (LPBYTE)&((DWORD*)pSrcBits)[j * cx];   
   
        for (int i = 0; i < cx; ++i)   
        {   
            pbSrcRGB[0]=(pbDestRGB[0] * (255-alpha) + pbSrcRGB[0] * alpha)>>8;   
            pbSrcRGB[1]=(pbDestRGB[1] * (255-alpha) + pbSrcRGB[1] * alpha)>>8;   
            pbSrcRGB[2]=(pbDestRGB[2] * (255-alpha) + pbSrcRGB[2] * alpha)>>8;   
            pbSrcRGB += 4;   
            pbDestRGB += 4;   
        }   
    }   
   
    dc = CreateCompatibleDC(NULL);   
   
     dcOld = (HBITMAP) SelectObject(dc, hbmSrc);   
     if (!BitBlt(dcDest, x, y, cx, cy, dc, 0, 0, SRCCOPY))   
         return false;   
     DeleteDC(dc);   
    
     DeleteObject(hbmSrc);   
     DeleteObject(hbmDest);   
    
     return true;   
 }   