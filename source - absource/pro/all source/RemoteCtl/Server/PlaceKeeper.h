#pragma once



class CPlaceKeeper
{
protected:

	class CPlace
	{
	public:
		bool m_FullScr;
		int m_Id;
		HWND m_hw;		
		RECT m_OriginalPos;
		RECT m_Bindings;
	};

	HWND m_hw;
	RECT m_OriginalPos;
	list<CPlace> m_Elements;

public:

	CPlaceKeeper( );
	~CPlaceKeeper( );

	void Init( HWND hw );
	void SetBindings( int id, CRect flags );
	void UpdatePositions( );
	void UpdateMinRect( LPRECT pRect );
	void SetFullScrElement(int id,bool bIsFullScr);
};
