
#if !defined(AFX_CLISTBOXEBX_) 
#define AFX_CLISTBOXEBX_ 
 
#if _MSC_VER >= 1000 
#pragma once 
#endif // _MSC_VER >= 1000 
 
//-------------------------------------------------------------------------- 
//	Copyright 2001 (C) Enver Buzoku, ebuzoku@hotmail.com 
// 
//	This class extends CListBox. 
//	Idea was taken from the CColorListBox class, found at www.codeguru.com, 
//	designed and updated by Patrice Godard and Paul M. Meidinger. 
// 
//	CListBoxEBX features. 
//		Background colour. 
//		Foreground colour. 
//		Text horizontal alignment. 
//		Text vertical alignment. 
//		Indicating inactive items. 
//		Hooking of a DWORD value per item as in original SetItemData. 
//		Allows for setting of the item height 
// 
//	Desired features. 
//		Font manipulation. 
//		Use of images 
//		Horisontal scrolling. 
// 
//	Points to note: 
//	---------------- 
//	Default index is set to (-1) for all set functions this means that the 
//	operation will apply to the currently selected item. 
// 
//	DEF_COL - definition is used to indicate that the item is using windows 
//  colours. 
// 
//	Required style flags, that must be set, are: 'Owner Draw' and 'Has Strings' 
//-------------------------------------------------------------------------- 
 
///////////////////////////////////////////////////////////////////////////// 
// CListBoxEBX window 
 
#define DEF_COL 17000000 
 
class CListBoxEBX : public CListBox 
{ 
protected: 
	struct LItem 
	{ 
		COLORREF	cBg,	cFg; 
		UINT		uHal,	uVal; 
		BOOL		bActive; 
		DWORD		dw; 
		DWORD_PTR	id;
	}; 
 
	CListBox*	m_pSuper; 
	int			m_iItemHeight; 
 
	int		Ix(int ix); 
	LItem*	Item(int ix); 
 
	static bool AlphaBlendU(HDC dcDest, int x, int y, int cx, int cy, 
		HDC dcSrc, int sx, int sy, int scx, int scy, int alpha); 
 
public: 
	CListBoxEBX(); 
	virtual ~CListBoxEBX(); 
 
 
	// Adds an item to the end of the list 
	int AddItem 
		( 
			LPCTSTR lpszItem, 
			COLORREF bg=DEF_COL,	  COLORREF fg=DEF_COL, 
			DWORD_PTR	id=0,
			UINT hal=DT_LEFT, UINT val=DT_VCENTER, 
			BOOL active=TRUE, DWORD res=NULL 
		); 
 
 
	// Adds an item at specified index. 
	int InsertItem 
		( 
			LPCTSTR lpszItem, int ix, 
			COLORREF bg=DEF_COL,	  COLORREF fg=DEF_COL, 
			DWORD_PTR	id=0,
			UINT hal=DT_LEFT, UINT val=DT_VCENTER, 
			BOOL active=TRUE, DWORD res=NULL 
		);
	DWORD_PTR GetItemData1(int Item);
 
	// Removes an item 
	BOOL RemoveAt(int ix); 
 
	// Removes all items 
	void ResetContent(); 
 
	// 
	BOOL SetBg(COLORREF color,	int ix = -1);	// item background 0 - 16777215 
	BOOL SetFg(COLORREF color,	int ix = -1);	// item foreground 0 - 16777215 
	BOOL SetVal(UINT align,		int ix = -1);	// DT_TOP, DT_VCENTER, DT_BOTTOM 
	BOOL SetHal(UINT align,		int ix = -1);	// DT_LEFT, DT_CENTER, DT_RIGHT 
	BOOL SetActive(BOOL bActive,		int ix = -1);	// TRUE/FALSE 
	BOOL SetData(DWORD data,	int ix = -1);	// DWORD ? 
 
 
	COLORREF GetBg(int ix = -1)		{ return Item(ix)->cBg;		} 
	COLORREF GetFg(int ix = -1)		{ return Item(ix)->cFg;		} 
	UINT	 GetVal(int ix = -1)	{ return Item(ix)->uVal;	} 
	UINT	 GetHal(int ix = -1)	{ return Item(ix)->uHal;	} 
	BOOL	 GetActive(int ix = -1) { return Item(ix)->bActive;	} 
	DWORD	 GetData(int ix = -1)	{ return Item(ix)->dw;		} 
 
	// call this to set item height, it should be called before items are added. 
	int SetItemHeight(int h) 
	{ 
		int oldH = m_iItemHeight; 
		m_iItemHeight = h; 
 
		return oldH; 
	} 
 
// Overrides 
	// ClassWizard generated virtual function overrides 
	//{{AFX_VIRTUAL(CListBoxEBX) 
	public: 
	virtual void DrawItem(LPDRAWITEMSTRUCT lpDrawItemStruct); 
	virtual void MeasureItem(LPMEASUREITEMSTRUCT lpMeasureItemStruct); 
	//}}AFX_VIRTUAL 
 
 
	// Generated message map functions 
protected: 
	//{{AFX_MSG(CListBoxEBX) 
	afx_msg void OnDestroy(); 
	afx_msg void OnSysColorChange(); 
	//}}AFX_MSG 
 
	DECLARE_MESSAGE_MAP() 
}; 
 
///////////////////////////////////////////////////////////////////////////// 
 
//{{AFX_INSERT_LOCATION}} 
// Microsoft Developer Studio will insert additional declarations immediately before the previous line. 
 
#endif 
