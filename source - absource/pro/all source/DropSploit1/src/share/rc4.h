#ifndef _RC4_H_
#define _RC4_H_

typedef struct _RC4_CTX 
{
	unsigned char   S[256];
	unsigned char   x, y;
} RC4_CTX;

void arc4_set_key(RC4_CTX *ctx, const unsigned char *in_key, int key_len);
void arc4_crypt(RC4_CTX *ctx, unsigned char *byte);
void arc4_crypt_message(RC4_CTX *ctx, const void *msg, size_t msg_len, void *dst);

void EncryptRc4(const void* key,size_t keylen,void* dst,const void* src,size_t len);

#endif
