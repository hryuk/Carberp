#ifndef VNC_H_INCLUDED
#define VNC_H_INCLUDED

extern HDESK hDefaultDesktop;
extern bool bXP;

void EnableSystemSounds(bool bEnable);
bool InitGlobalData(PHVNC lpServer);
void InitGlobalDataNames(PHVNC lpServer);

void ChangePowerCfg();
bool IsConnectionActive(PHVNC lpServer);

#define MAX_RECONNECTIONS_PER_SECOND 6

#endif // VNC_H_INCLUDED
