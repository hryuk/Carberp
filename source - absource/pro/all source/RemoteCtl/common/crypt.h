#pragma once

bool CryptInit();
bool CryptCleanup();
bool CreateHash( vector<BYTE>& data, vector<BYTE>& hash );
bool Decode( vector<BYTE>& data, vector<BYTE>& key, vector<BYTE>& result );
bool Encode( vector<BYTE>& data, vector<BYTE>& key, vector<BYTE>& result );
bool CreateKey( vector<BYTE>& data );

bool AppendValue( vector<BYTE>& data, vector<BYTE>& value );
bool AppendValue( vector<BYTE>& data, wstring& value );

bool ExtractValue( vector<BYTE>& data, vector<BYTE>& value, int& curpos );
bool ExtractValue( vector<BYTE>& data, wstring& value, int& curpos );

