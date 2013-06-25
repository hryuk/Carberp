#include "StdAfx.h"
#include "PlaceKeeper.h"


CPlaceKeeper::CPlaceKeeper( )
	: m_hw( 0 )
{
}


CPlaceKeeper::~CPlaceKeeper( )
{
}


void CPlaceKeeper::Init( HWND hw )
{
	m_hw = hw;
	GetClientRect( hw, &m_OriginalPos );
}

void CPlaceKeeper::SetBindings( int id, CRect flags )
{
	CPlace item;
	item.m_FullScr=false;
	item.m_Id = id;
	item.m_hw = GetDlgItem( m_hw, id );
	item.m_Bindings = flags;
	GetWindowRect( item.m_hw, &item.m_OriginalPos );
	MapWindowPoints( 0, m_hw, (LPPOINT)&item.m_OriginalPos, 2 );
	m_Elements.push_back( item );
}

void CPlaceKeeper::SetFullScrElement(int id,bool bIsFullScr)
{
	list<CPlace>::iterator I = m_Elements.begin();
	I->m_FullScr=bIsFullScr;
	
	for( ; I != m_Elements.end(); I++ )
	{
		if (!I->m_FullScr)
		{
			ShowWindow(I->m_hw,SW_SHOW);
		}
	}

}


void CPlaceKeeper::UpdatePositions( )
{
	RECT mainRect;
	GetClientRect( m_hw, &mainRect );

	list<CPlace>::iterator I = m_Elements.begin();
	bool bIsHide=false;
	for( ; I != m_Elements.end(); I++ )
	{
		RECT newRect;
		if (!I->m_FullScr)
		{
		
		ZeroMemory( &newRect, sizeof(newRect) );

		switch( I->m_Bindings.left )
		{
		case TA_LEFT:
			newRect.left = I->m_OriginalPos.left - m_OriginalPos.left;
			break;
		case TA_RIGHT:
			newRect.left = mainRect.right - (m_OriginalPos.right - I->m_OriginalPos.left);
			break;
		}

		switch( I->m_Bindings.right )
		{
		case TA_RIGHT:
			newRect.right = mainRect.right - (m_OriginalPos.right - I->m_OriginalPos.right);
			break;
		case TA_LEFT:
			newRect.right = I->m_OriginalPos.right;
			break;
		}

		switch( I->m_Bindings.top )
		{
		case TA_TOP:
			newRect.top = I->m_OriginalPos.top - m_OriginalPos.top;
			break;
		case TA_BOTTOM:
			newRect.top = mainRect.bottom - (m_OriginalPos.bottom - I->m_OriginalPos.top);
			break;
		}

		switch( I->m_Bindings.bottom )
		{
		case TA_BOTTOM:
			newRect.bottom = mainRect.bottom - (m_OriginalPos.bottom - I->m_OriginalPos.bottom);
			break;
		case TA_TOP:
			newRect.bottom = I->m_OriginalPos.bottom;
			break;
		}
		}
		else 
		{
			
			newRect.left=0;
			newRect.top=0;
			newRect.right=GetSystemMetrics( SM_CXSCREEN );;
			newRect.bottom=GetSystemMetrics( SM_CYSCREEN );
			bIsHide=true;
		}	

		SetWindowPos( I->m_hw, 0, 
			newRect.left, newRect.top,
			newRect.right - newRect.left,
			newRect.bottom - newRect.top,
			SWP_NOZORDER );
	}
	
	if (bIsHide)
	{
		I = m_Elements.begin();
		for( ; I != m_Elements.end(); I++ )
		{
			if (!I->m_FullScr)
			{
				ShowWindow(I->m_hw,SW_HIDE);

			}
		}
	}
}

void CPlaceKeeper::UpdateMinRect( LPRECT pRect )
{
	if( pRect->right - pRect->left < m_OriginalPos.right - m_OriginalPos.left )
	{
		pRect->right = pRect->left + (m_OriginalPos.right - m_OriginalPos.left);
	}
	if( pRect->bottom - pRect->top < m_OriginalPos.bottom - m_OriginalPos.top )
	{
		pRect->bottom = pRect->top + (m_OriginalPos.bottom - m_OriginalPos.top);
	}
}
