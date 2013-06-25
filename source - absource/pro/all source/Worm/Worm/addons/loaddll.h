
char* LoadFileFromAdminka( const char* nameFile, int* size );
char* LoadFileFromRequest( HINTERNET request, int* size );
char* LoadFileFromInet( const char* host, const char* url, int* size, const char* postData = 0, int szPostData = 0 );

