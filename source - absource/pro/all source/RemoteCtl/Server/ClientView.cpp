// ClientView.cpp : implementation file
//

#include "stdafx.h"
#include "Server.h"
#include "ClientView.h"


// CClientView

IMPLEMENT_DYNCREATE(CClientView, CView)

CClientView::CClientView()
{

}

CClientView::~CClientView()
{
}

BEGIN_MESSAGE_MAP(CClientView, CView)
END_MESSAGE_MAP()


// CClientView drawing

void CClientView::OnDraw(CDC* pDC)
{
	CDocument* pDoc = GetDocument();
	// TODO: add draw code here
}


// CClientView diagnostics

#ifdef _DEBUG
void CClientView::AssertValid() const
{
	CView::AssertValid();
}

#ifndef _WIN32_WCE
void CClientView::Dump(CDumpContext& dc) const
{
	CView::Dump(dc);
}
#endif
#endif //_DEBUG


// CClientView message handlers
