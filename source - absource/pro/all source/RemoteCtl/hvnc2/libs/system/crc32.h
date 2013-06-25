#ifndef CRC32_H_INCLUDED
#define CRC32_H_INCLUDED

DWORD chksum_crc32 (unsigned char *block, unsigned int length);
void chksum_crc32gentab ();
DWORD CalcFuncCRC32i(byte *data);

#endif // CRC32_H_INCLUDED
