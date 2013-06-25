#pragma once

class CClientDlg;

#define PM_CLIENT_LCLICK		WM_USER+301
#define PM_CLIENT_RCLICK		WM_USER+302

// CClientViewCtrl

class CClientViewCtrl : public CWnd
{
	DECLARE_DYNAMIC(CClientViewCtrl)

public:
	CClientViewCtrl();
	virtual ~CClientViewCtrl();

	bool m_bImageSet;
	int m_iXOffset;
	int m_iYOffset;
	int m_iXScrollMax;
	int m_iYScrollMax;
	bool m_bVFlip;
	bool m_bHFlip;
	CBitmap m_Canvas;
	int lastProfile; //какой был последний выбран профиль 
	CClientDlg* parentDlg;

	void SetFlips( bool bVert, bool bHorz );
	void SetImage( vector<BYTE>& image );
	void ClearImage( );

protected:
	void UpdateScrollBarsOnce();
	void UpdateScrollBars();

protected:
	DECLARE_MESSAGE_MAP()
public:
	afx_msg BOOL OnEraseBkgnd(CDC* pDC);
	afx_msg void OnPaint();
	afx_msg void OnVScroll(UINT nSBCode, UINT nPos, CScrollBar* pScrollBar);
	afx_msg void OnHScroll(UINT nSBCode, UINT nPos, CScrollBar* pScrollBar);
	afx_msg void OnLButtonDown(UINT nFlags, CPoint point);
	afx_msg void OnRButtonDown(UINT nFlags, CPoint point);
public:
	afx_msg void OnSize(UINT nType, int cx, int cy);
};


