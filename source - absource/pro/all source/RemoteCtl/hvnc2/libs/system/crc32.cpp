#include <windows.h>

DWORD crc_tab[256];

void chksum_crc32gentab ();

bool bCrcInit=false;
/* chksum_crc() -- to a given block, this one calculates the
 *				crc32-checksum until the length is
 *				reached. the crc32-checksum will be
 *				the result.
 */
DWORD chksum_crc32 (unsigned char *block, unsigned int length)
{
    if (!bCrcInit)
        chksum_crc32gentab();
   register unsigned long crc;
   unsigned long i;

   crc = 0xFFFFFFFF;
   for (i = 0; i < length; i++)
   {
      crc = ((crc >> 8) & 0x00FFFFFF) ^ crc_tab[(crc ^ *block++) & 0xFF];
   }
   return (crc ^ 0xFFFFFFFF);
}

DWORD CalcFuncCRC32i(byte *data)
{
    byte buf[300], *p=buf;
    while (*data)
    {
        byte tmp=*data++;
        if (((tmp > 0xC0) && (tmp < 0xDF)) || ((tmp > 'A') && (tmp < 'Z')))
            tmp+=0x20;
        *p++=tmp;
    }
    *p=0;

    return chksum_crc32(buf,p-buf);
}

/* chksum_crc32gentab() --      to a global crc_tab[256], this one will
 *				calculate the crcTable for crc32-checksums.
 *				it is generated to the polynom [..]
 */

void chksum_crc32gentab ()
{
    if (bCrcInit)
        return;
    bCrcInit=true;

   unsigned long crc, poly;
   int i, j;

   poly = 0xEDB88320L;
   for (i = 0; i < 256; i++)
   {
      crc = i;
      for (j = 8; j > 0; j--)
      {
	 if (crc & 1)
	 {
	    crc = (crc >> 1) ^ poly;
	 }
	 else
	 {
	    crc >>= 1;
	 }
      }
      crc_tab[i] = crc;
   }
}

