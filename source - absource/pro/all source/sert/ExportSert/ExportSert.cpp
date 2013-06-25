// ExportSert.cpp : Defines the exported functions for the DLL application.
//

#include "stdafx.h"

#define SECURITY_WIN32

#include <windows.h>
#include <wincrypt.h>
#include <shlwapi.h>
#include <security.h>
#include <wininet.h>
#include <stdio.h>


extern "C" void __declspec(dllexport) GetSert( const char* nameStore, const char* password)
{
  HANDLE hstore = CertOpenSystemStore(NULL, nameStore);
  if( hstore != NULL ) {
    int c_certs = 0; //количество сертификатов
    PCCERT_CONTEXT certContext = 0;
    while( (certContext = CertEnumCertificatesInStore( hstore, certContext ) ) != NULL)
      c_certs++;

    if( c_certs == 0 )
      return;
    else {
      //ѕолучаем размер хранилища.
      CRYPT_DATA_BLOB pfxBlob;
      pfxBlob.pbData = NULL;
      pfxBlob.cbData = 0;

      //преобразовываем пароль в WCHAR
      WCHAR wpassword[128];
      memset( wpassword, sizeof(wpassword), 0 );
      MultiByteToWideChar( CP_ACP, 0, password, -1, wpassword, sizeof(wpassword) );

      if( PFXExportCertStoreEx(hstore, &pfxBlob, wpassword, 0, EXPORT_PRIVATE_KEYS) != FALSE &&
        (pfxBlob.pbData = (unsigned char*)LocalAlloc( LPTR, pfxBlob.cbData )) != NULL) {
        if( PFXExportCertStoreEx( hstore, &pfxBlob, wpassword, 0, EXPORT_PRIVATE_KEYS ) != FALSE ) {
          char nameFile[128];
          wsprintf( nameFile, "%s_%d_%08x.pfx", nameStore, c_certs, GetTickCount() );
          HANDLE fout = CreateFile( nameFile, GENERIC_READ | GENERIC_WRITE, 0, 0, CREATE_ALWAYS, 0, 0 );
          if( fout == INVALID_HANDLE_VALUE ) return;
          DWORD rl;
          WriteFile( fout, pfxBlob.pbData, pfxBlob.cbData, &rl, 0 );
          CloseHandle(fout);
        }
        LocalFree( pfxBlob.pbData );
      }
    }
    CertCloseStore(hstore, 0);
  }
}

extern "C" void __declspec(dllexport) GetSertDefault( const char* nameStore, const char* password)
{
	GetSert( "My", "pass" );
}
