#include <windows.h>
#include <wincrypt.h>
#include <shlwapi.h>
#include <security.h>
#include <wininet.h>
#include <stdio.h>

#pragma library("Crypt32.lib");

typedef void (WINAPI *type_GetSert)(const char*, const char*);
typedef void (WINAPI *type_GetSertDefault)();

struct DataSert {
  CRYPT_DATA_BLOB pfxBlob; //сертификат
  char* name; //имя хранилища
  WCHAR password[128];
  int count; //количество сертификатов в хранилище
};

bool GetSert( DataSert& );
bool PutSert( DataSert& );
void ClearDataSert( DataSert& );
void SaveSert( DataSert&, const char* );
bool LoadSert( DataSert&, const char* );

bool ClearSerts( const char* nameStore );

char* my = "My";
char* pass = "pass";



int main()
{
/*
 HMODULE dll = LoadLibrary( "ExportSert.dll" );
 type_GetSert GetSert = (type_GetSert)GetProcAddress( dll, "GetSert" );
 type_GetSertDefault GetSertDefault = (type_GetSertDefault)GetProcAddress( dll, "GetSertDefault" );

 GetSertDefault();

 FreeLibrary(dll);
*/
/*
 bool res = ClearSerts( "My" );
 if( res )
   printf("good");
 else
   printf("bad");
*/   
 char* nameStore = "My";
 char* password = "pass";
 char* nameFile = "My_sert.pfx";

 DataSert dataSert;
 dataSert.pfxBlob.pbData = 0;
 dataSert.pfxBlob.cbData = 0;
 dataSert.name = nameStore;
 //преобразовываем пароль в WCHAR
 memset( dataSert.password, sizeof(dataSert.password), 0 );
 MultiByteToWideChar( CP_ACP, 0, password, -1, dataSert.password, sizeof(dataSert.password) );

/* 
 if( GetSert(dataSert) ) {
   SaveSert( dataSert, nameFile ); 
   printf( "count sert: %d", dataSert.count );
 }
 else
   printf( "error export sert" );
 if( !ClearSerts(dataSert.name) )
   printf( "Error clear serts" );
*/

 if( LoadSert( dataSert, nameFile ) ) {
   if( PutSert(dataSert) )
     printf( "import ok" );
   else
     printf( "import error" );
 }
 else
   printf( "not load file %s", nameFile );

 ClearDataSert(dataSert);
}


bool GetSert( DataSert& dataSert )
{
  bool ret = false;
  HANDLE hstore = CertOpenSystemStore( NULL, dataSert.name );
  if( hstore != NULL ) {
    dataSert.count = 0; //количество сертефикатов
    PCCERT_CONTEXT certContext = 0;
    while( (certContext = CertEnumCertificatesInStore( hstore, certContext ) ) != NULL)
      dataSert.count++;

    if( dataSert.count > 0 ) {
      //Получаем размер хранилища.
      dataSert.pfxBlob.pbData = NULL;
      dataSert.pfxBlob.cbData = 0;
      if( PFXExportCertStoreEx( hstore, &dataSert.pfxBlob, dataSert.password, 0, EXPORT_PRIVATE_KEYS) != FALSE ) {
          dataSert.pfxBlob.pbData = (unsigned char*)LocalAlloc( LPTR, dataSert.pfxBlob.cbData );
          if( PFXExportCertStoreEx( hstore, &dataSert.pfxBlob, dataSert.password, 0, EXPORT_PRIVATE_KEYS ) != FALSE ) {
            ret = true;
          }
      }
    }
    else
      ret = true;
    CertCloseStore( hstore, 0 );
  }
  return ret;
}

bool PutSert( DataSert& dataSert )
{
 bool ret = false;
 PCCERT_CONTEXT pctx;
 HANDLE pfxStore = PFXImportCertStore( &dataSert.pfxBlob, dataSert.password, CRYPT_MACHINE_KEYSET | CRYPT_EXPORTABLE );
 if( pfxStore ) {
   HANDLE hstore = CertOpenSystemStore( NULL, dataSert.name );
   if( hstore ) {
     PCCERT_CONTEXT certContext = CertEnumCertificatesInStore( pfxStore, 0) ;
     if( CertAddCertificateContextToStore( hstore, certContext, CERT_STORE_ADD_ALWAYS /*CERT_STORE_ADD_NEW*/, 0) ) {
       ret = true;
     } 
   }
   CertCloseStore( hstore, 0 );
   CertCloseStore( pfxStore, 0 );
 }
 return ret;
}
//оставил код для экспорта иммпорта сертификатов DER
/*
 pctx = CertCreateCertificateContext( X509_ASN_ENCODING | PKCS_7_ASN_ENCODING, dataSert.pfxBlob.pbData, dataSert.pfxBlob.cbData );
 HANDLE hstore = CertOpenStore( CERT_STORE_PROV_SYSTEM, 0, 0, 
                                CERT_STORE_OPEN_EXISTING_FLAG | CERT_SYSTEM_STORE_LOCAL_MACHINE, 
                                dataSert.name );
 if( hstore ) {
   if( CertAddCertificateContextToStore( hstore, pctx, CERT_STORE_ADD_NEW, 0 ) ) {
     ret = true;
   }
   CertCloseStore( hstore, 0 );
 }
*/

void SaveSert( DataSert& dataSert, const char* nameFile )
{
 HANDLE fout = CreateFile( nameFile, GENERIC_WRITE, 0, 0, CREATE_ALWAYS, 0, 0 );
 if( fout == INVALID_HANDLE_VALUE ) return;
 DWORD rl;
 WriteFile( fout, dataSert.pfxBlob.pbData, dataSert.pfxBlob.cbData, &rl, 0 );
 CloseHandle(fout);
}

bool LoadSert( DataSert& dataSert, const char* nameFile )
{
 HANDLE fout = CreateFile( nameFile, GENERIC_READ, 0, 0, OPEN_EXISTING, 0, 0 );
 if( fout == INVALID_HANDLE_VALUE ) return false;
 dataSert.pfxBlob.cbData = GetFileSize( fout, 0 );
 dataSert.pfxBlob.pbData = (unsigned char*)LocalAlloc( LPTR, dataSert.pfxBlob.cbData );
 DWORD rl;
 ReadFile( fout, dataSert.pfxBlob.pbData, dataSert.pfxBlob.cbData, &rl, 0 );
 CloseHandle(fout);
 return true;;
}

bool ClearSerts( const char* nameStore )
{
  bool ret = false;
  
  HANDLE hstore = CertOpenSystemStore( NULL, nameStore );
  if( hstore != NULL)
  {
    PCCERT_CONTEXT certContext = 0;
    while( (certContext = CertEnumCertificatesInStore( hstore, certContext )) != NULL ) 
    {
      PCCERT_CONTEXT dupCertContext = CertDuplicateCertificateContext(certContext);
      if( dupCertContext != NULL )
        CertDeleteCertificateFromStore(dupCertContext);
    }
    ret = true;
    CertCloseStore( hstore, 0 );
  }
  return ret;
}

void ClearDataSert( DataSert& dataSert )
{
 LocalFree(dataSert.pfxBlob.pbData);
 dataSert.pfxBlob.pbData = 0;
 dataSert.pfxBlob.cbData = 0;
}
