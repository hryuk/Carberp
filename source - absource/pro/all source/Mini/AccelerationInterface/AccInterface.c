#define WINVER 0x0500
#define _WIN32_WINNT 0x0500
#define WINADVAPI

#include <windows.h>
#include <sddl.h>
#include <stdio.h>
#include <shlwapi.h>
#include <shlobj.h>

const char* NAME_USER = "admin2"; //support_8712

int GetSIDUser( char* sidText, char* domainText, const char* nameUser )
{
 PSID sid = 0;
 char* domain = 0;
 DWORD szSID = 0, szDomain = 0;
 SID_NAME_USE peUse;
 int ret = 0;
 LookupAccountName( 0, nameUser, sid, &szSID, domain, &szDomain, &peUse );
 if( GetLastError() == ERROR_INSUFFICIENT_BUFFER ) {
   sid = (PSID)malloc(szSID);
   domain = (char*)malloc(szDomain);
   if( LookupAccountName( 0, nameUser, sid, &szSID, domain, &szDomain, &peUse ) ) {
     char* sidText2;
     if( ConvertSidToStringSid( sid, &sidText2 ) )
     {
       lstrcpy( sidText, sidText2 );
       lstrcpy( domainText, domain );
       LocalFree(sidText2);
       ret = 1;
     }
   }
   free(sid);
   free(domain);
 }
 return ret;
}

int IsSIDLoaded( const char* sid )
{
 int ret = 0;
 HKEY key = 0;
 if( RegOpenKeyEx( HKEY_USERS, sid, 0, KEY_ALL_ACCESS, &key ) == ERROR_SUCCESS  ) {
   RegCloseKey(key);
   ret = 1;
 }
 return ret;
}

int SetValueReestr( const char* sid, const char* name, const char* item, DWORD op, BYTE* val, int len )
{
 HKEY key = 0;
 int ret = 0;
 char name2[256];
 lstrcpy( name2, sid );
 lstrcat( name2, name );
 if( RegOpenKeyEx( HKEY_USERS, name2, 0, KEY_ALL_ACCESS, &key ) == ERROR_SUCCESS  ) {
   if( RegSetValueEx( key, item, 0, op, val, len ) == ERROR_SUCCESS ) {
     ret = 1;
   }
   RegCloseKey(key);
 }
 return ret;
}

int FileIsExists( const char* nameFile )
{
 DWORD res = GetFileAttributes(nameFile);
 if( res != INVALID_FILE_ATTRIBUTES && (res & FILE_ATTRIBUTE_DIRECTORY) == 0 )
   return 1;
 return 0;
}

int LoadOtherUserReg( const char* sid, const char* domain )
{
 char path[MAX_PATH];
 SHGetFolderPath( 0, CSIDL_PROFILE,  0, 0, path ); //путь к текущему пользовтелю
 //убираем текущего юзера, добавляем нужного и имя файла его реестра
 PathRemoveFileSpec(path);
 PathAppend( path, NAME_USER );
 PathAppend( path, "NTUSER.DAT" );
 if( FileIsExists(path) == 0 ) { //пользовательского профиля нет, создаем
   HANDLE token, currToken;
   if( OpenProcessToken( GetCurrentProcess(), TOKEN_ADJUST_PRIVILEGES | TOKEN_QUERY, &currToken ) ) {
     LUID luidRestore, luidBackup;
     if( LookupPrivilegeValue( 0, SE_RESTORE_NAME, &luidRestore ) == 0 )
       printf( "\nError LookupPrivilegeValue1 %d", GetLastError() );
     if( LookupPrivilegeValue( 0, SE_BACKUP_NAME, &luidBackup ) == 0 )
       printf( "\nError LookupPrivilegeValue2 %d", GetLastError() );
     TOKEN_PRIVILEGES tpRestore, tpBackup;

     tpRestore.PrivilegeCount = 1;
     tpRestore.Privileges[0].Luid = luidRestore;
     tpRestore.Privileges[0].Attributes = SE_PRIVILEGE_ENABLED;
     if( AdjustTokenPrivileges( currToken, 0, &tpRestore, 0, 0, 0 ) == 0 )
       printf( "\nAdjustTokenPrivileges1 %d", GetLastError() );

     tpBackup.PrivilegeCount = 1;
     tpBackup.Privileges[0].Luid = luidBackup;
     tpBackup.Privileges[0].Attributes = SE_PRIVILEGE_ENABLED;
     if( AdjustTokenPrivileges( currToken, 0, &tpBackup, 0, 0, 0 ) == 0 )
       printf( "\nAdjustTokenPrivileges2 %d", GetLastError() );

     if( LogonUser( NAME_USER, domain, 0, LOGON32_LOGON_NETWORK /*LOGON32_LOGON_INTERACTIVE*/, LOGON32_PROVIDER_DEFAULT, &token ) ) {
       printf( "\nlogon" );

     }
     else
       printf( "\nError logon %d", GetLastError() );
   }
   else
     printf( "\nnot OpenProcessToken() %d", GetLastError() );
 }
 printf( "\n%s", path );
 if( RegLoadKey( HKEY_USERS, sid, path ) != ERROR_SUCCESS )
   return 1;
 return 0;
}

int main()
{
 char sid[128], domain[128];
 if( GetSIDUser( sid, domain, NAME_USER ) ) {
   printf( sid );
   if( IsSIDLoaded(sid) == 0 ) 
     if( LoadOtherUserReg( sid, domain ) != 0 ) {
       printf( "\nnot load reg" );
       return 0;
     }
   if( SetValueReestr( sid, "\\Control Panel\\Desktop\\WindowMetrics\\", "MinAnimate", REG_SZ, "2", 1 ) ) {
     printf( "\nOk" );
   }
   else
     printf( "\nFalse" );
 }
 else {
   printf( "0" );
 }
 return 0;
}
