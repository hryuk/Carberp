// ClientViewCtrl.cpp : implementation file
//

#include "stdafx.h"
#include "Server.h"
#include "ClientViewCtrl.h"
#include "../common/protocol.h"
#include "DlgNameValue.h"
#include "ClientDlg.h"

// CClientViewCtrl

IMPLEMENT_DYNAMIC(CClientViewCtrl, CWnd)
#define CLIENTVIEW_NAME L"MFCClientViewCtrl"

CClientViewCtrl::CClientViewCtrl()
	: m_bImageSet( false )
	, m_iXOffset( 0 )
	, m_iYOffset( 0 )
	, m_iXScrollMax( 0 )
	, m_iYScrollMax( 0 )
	, m_bVFlip( false )
	, m_bHFlip( false )
	, lastProfile(-1)
{
    WNDCLASS wndcls;
    HINSTANCE hInst = AfxGetInstanceHandle();

    if (!(::GetClassInfo(hInst, CLIENTVIEW_NAME, &wndcls)))
    {
        // otherwise we need to register a new class

        wndcls.style            = CS_DBLCLKS | CS_HREDRAW | CS_VREDRAW;
        wndcls.lpfnWndProc      = ::DefWindowProc;
        wndcls.cbClsExtra       = wndcls.cbWndExtra = 0;
        wndcls.hInstance        = hInst;
        wndcls.hIcon            = NULL;
        wndcls.hCursor          = AfxGetApp()->LoadStandardCursor(IDC_ARROW);
		wndcls.hbrBackground    = (HBRUSH) (COLOR_3DHIGHLIGHT + 1);
        wndcls.lpszMenuName     = NULL;
        wndcls.lpszClassName    = CLIENTVIEW_NAME;

        AfxRegisterClass(&wndcls);
    }
}

CClientViewCtrl::~CClientViewCtrl()
{
}


BEGIN_MESSAGE_MAP(CClientViewCtrl, CWnd)
	ON_WM_ERASEBKGND()
	ON_WM_PAINT()
	ON_WM_CREATE()
	ON_WM_VSCROLL()
	ON_WM_HSCROLL()
	ON_WM_LBUTTONDOWN()
	ON_WM_RBUTTONDOWN()
	ON_WM_SIZE()
END_MESSAGE_MAP()



// CClientViewCtrl message handlers



BOOL CClientViewCtrl::OnEraseBkgnd(CDC* pDC)
{
	return TRUE;
}

void CClientViewCtrl::OnPaint()
{
	CPaintDC dc(this);

	RECT rcClient;
	GetClientRect( &rcClient );

	if( m_bImageSet )
	{
		BITMAP bmInfo;
		ZeroMemory( &bmInfo, sizeof(bmInfo) );
		m_Canvas.GetBitmap( &bmInfo );

		CDC tmpDC;
		tmpDC.CreateCompatibleDC( &dc );
		tmpDC.SelectObject( m_Canvas );

		int x = 0;
		int w = bmInfo.bmWidth;
		if( m_bHFlip )
		{
			x = bmInfo.bmWidth;
			w = -bmInfo.bmWidth;
		}

		int y = 0;
		int h = bmInfo.bmHeight;
		if( m_bVFlip )
		{
			y = bmInfo.bmHeight;
			h = -bmInfo.bmHeight;
		}

		dc.StretchBlt(
			-m_iXOffset, -m_iYOffset,
			bmInfo.bmWidth, bmInfo.bmHeight,
			&tmpDC,
			x, y, w, h,
			SRCCOPY );

		if( rcClient.right > bmInfo.bmWidth )
		{
			dc.BitBlt(
				bmInfo.bmWidth, 0,
				rcClient.right - bmInfo.bmWidth, rcClient.bottom,
				0, 0, 0, BLACKNESS );
		}

		if( rcClient.bottom > bmInfo.bmHeight )
		{
			dc.BitBlt(
				0, bmInfo.bmHeight,
				rcClient.right, rcClient.bottom - bmInfo.bmHeight,
				0, 0, 0, BLACKNESS );
		}
	}
	else
	{
		dc.BitBlt( 0, 0, rcClient.right, rcClient.bottom, 0, 0, 0, BLACKNESS );
	}
}

void CClientViewCtrl::SetFlips( bool bVert, bool bHorz )
{
	m_bVFlip = bVert;
	m_bHFlip = bHorz;
}


void CClientViewCtrl::SetImage( vector<BYTE>& image )
{
	BYTE *pMain = image.get_allocator().address(image.front());
	WIN_SHOT *pInfo = (WIN_SHOT *)pMain;

	// TODO: add more formats
	if( pInfo->compression == 1 ) // BMP
	{
		BITMAPINFOHEADER *bmih = (BITMAPINFOHEADER *)(pMain + sizeof(BITMAPFILEHEADER) + sizeof(WIN_SHOT));
		BYTE *pData = pMain + sizeof(BITMAPINFOHEADER) + sizeof(BITMAPFILEHEADER) + sizeof(WIN_SHOT);

		CDC *pdc = GetDC();
		m_Canvas.DeleteObject();
		m_Canvas.CreateCompatibleBitmap( pdc, bmih->biWidth, bmih->biHeight );
		::SetDIBits( pdc->m_hDC, m_Canvas, 0, bmih->biHeight, pData, (BITMAPINFO*)bmih, DIB_RGB_COLORS );
		ReleaseDC( pdc );

		m_bImageSet = true;
		m_iXOffset = m_iYOffset = 0;
		UpdateScrollBars();
		InvalidateRect( 0, FALSE );
	}
	else if( pInfo->compression == 2 ) // JPEG
	{
		IStream *pStream = 0;
		if( CreateStreamOnHGlobal( 0, TRUE, &pStream ) == S_OK )
		{
			ULONG written = 0;
			if( pStream->Write( pInfo->imagedata, pInfo->imagelength, &written ) == S_OK )
			{
				HBITMAP hbm = 0;
				Bitmap DstBitmap( pStream, FALSE );
				if( DstBitmap.GetHBITMAP( Color(), &hbm ) == Ok )
				{
					m_Canvas.DeleteObject();
					m_Canvas.Attach( hbm );
				}
			}
			pStream->Release();
		}

		m_bImageSet = true;
		m_iXOffset = m_iYOffset = 0;
		UpdateScrollBars();
		InvalidateRect( 0, FALSE );
	}
	else
	{
		m_bImageSet = false;
		InvalidateRect( 0, FALSE );
	}
}

void CClientViewCtrl::ClearImage( )
{
	m_bImageSet = false;
	m_iXOffset = m_iYOffset = 0;
	UpdateScrollBars();
	InvalidateRect( 0, FALSE );
}

void CClientViewCtrl::UpdateScrollBarsOnce()
{
	BITMAP bmInfo;
	ZeroMemory( &bmInfo, sizeof(bmInfo) );
	m_Canvas.GetBitmap( &bmInfo );

	RECT rcClient;
	ZeroMemory( &rcClient, sizeof(rcClient) );
	GetClientRect( &rcClient );

	if( rcClient.bottom >= bmInfo.bmHeight )
	{
		m_iYScrollMax = 0;
		SetScrollRange( SB_VERT, 0, 0, TRUE );
	}
	else
	{
		m_iYScrollMax = bmInfo.bmHeight-rcClient.bottom;
		SetScrollRange( SB_VERT, 0, m_iYScrollMax, FALSE );
		SetScrollPos( SB_VERT, m_iYOffset, TRUE );
	}

	if( rcClient.right >= bmInfo.bmWidth )
	{
		m_iXScrollMax = 0;
		SetScrollRange( SB_HORZ, 0, 0, TRUE );
	}
	else
	{
		m_iXScrollMax = bmInfo.bmWidth-rcClient.right;
		SetScrollRange( SB_HORZ, 0, m_iXScrollMax, FALSE );
		SetScrollPos( SB_HORZ, m_iXOffset, TRUE );
	}
}

void CClientViewCtrl::UpdateScrollBars()
{
	if( m_bImageSet )
	{
		UpdateScrollBarsOnce();
		UpdateScrollBarsOnce();

		if( m_iYOffset > m_iYScrollMax )
		{
			m_iYOffset = m_iYScrollMax;
		}
		if( m_iYOffset < 0 )
		{
			m_iYOffset = 0;
		}

		if( m_iXOffset > m_iXScrollMax )
		{
			m_iXOffset = m_iXScrollMax;
		}
		if( m_iXOffset < 0 )
		{
			m_iXOffset = 0;
		}
	}
	else
	{
		m_iXOffset = m_iYOffset = 0;
		SetScrollRange( SB_VERT, 0, 0, TRUE );
		SetScrollRange( SB_HORZ, 0, 0, TRUE );
	}
}



void CClientViewCtrl::OnVScroll(UINT nSBCode, UINT nPos, CScrollBar* pScrollBar)
{
	RECT rcClient;
	GetClientRect( &rcClient );

	bool bNoUpdate = false;
	switch( nSBCode )
	{
	case SB_LINEDOWN:
		m_iYOffset++;
		break;
	case SB_LINEUP:
		m_iYOffset--;
		break;
	case SB_PAGEDOWN:
		m_iYOffset+=rcClient.bottom;
		break;
	case SB_PAGEUP:
		m_iYOffset-=rcClient.bottom;
		break;
	case SB_THUMBTRACK:
	case SB_THUMBPOSITION:
		m_iYOffset = nPos;
		break;
	default:
		bNoUpdate = true;
		break;
	}

	if( m_iYOffset > m_iYScrollMax )
	{
		m_iYOffset = m_iYScrollMax;
	}
	if( m_iYOffset < 0 )
	{
		m_iYOffset = 0;
	}

	if( !bNoUpdate )
	{
		SetScrollPos( SB_VERT, m_iYOffset, TRUE );
		InvalidateRect( 0, FALSE );
	}
}


void CClientViewCtrl::OnHScroll(UINT nSBCode, UINT nPos, CScrollBar* pScrollBar)
{
	RECT rcClient;
	GetClientRect( &rcClient );

	bool bNoUpdate = false;
	switch( nSBCode )
	{
	case SB_LINERIGHT:
		m_iXOffset++;
		break;
	case SB_LINELEFT:
		m_iXOffset--;
		break;
	case SB_PAGERIGHT:
		m_iXOffset+=rcClient.right;
		break;
	case SB_PAGELEFT:
		m_iXOffset-=rcClient.right;
		break;
	case SB_THUMBTRACK:
	case SB_THUMBPOSITION:
		m_iXOffset = nPos;
		break;
	default:
		bNoUpdate = true;
		break;
	}

	if( m_iXOffset > m_iXScrollMax )
	{
		m_iXOffset = m_iXScrollMax;
	}
	if( m_iXOffset < 0 )
	{
		m_iXOffset = 0;
	}

	if( !bNoUpdate )
	{
		SetScrollPos( SB_HORZ, m_iXOffset, TRUE );
		InvalidateRect( 0, FALSE );
	}
}

void CClientViewCtrl::OnLButtonDown(UINT nFlags, CPoint point)
{
	CWnd::OnLButtonDown(nFlags, point);
	int x = point.x + m_iXOffset, y = point.y + m_iYOffset;
	if( nFlags & MK_CONTROL )
	{
		DlgNameValue dlg( x, y, "profiles", lastProfile, this );
		if( dlg.DoModal() == IDOK )
		{
			lastProfile = dlg.GetCurProfile();
			DWORD_PTR id = parentDlg->GetId();
			if( id != NULL )
			{
				CString s(dlg.GetValue());
				parentDlg->m_pClient->RequestKeys( id, x, y, s.GetBuffer(), false, false, true );
			}
		}
	}
	else
		GetParent()->SendMessage( PM_CLIENT_LCLICK, x, y );
}

void CClientViewCtrl::OnRButtonDown(UINT nFlags, CPoint point)
{
	CWnd::OnRButtonDown(nFlags, point);
	GetParent()->SendMessage( PM_CLIENT_RCLICK, point.x+m_iXOffset, point.y+m_iYOffset );
}

void CClientViewCtrl::OnSize(UINT nType, int cx, int cy)
{
	CWnd::OnSize(nType, cx, cy);
	UpdateScrollBars();
}
