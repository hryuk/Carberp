#include "rc4.h"

void arc4_set_key(RC4_CTX *ctx, const unsigned char *in_key, int key_len)
{
	int i, k = 0;

	ctx->x = 1;
	ctx->y = 0;

	for (i = 0; i < 256; i++)
		ctx->S[i] = (unsigned char)i;

	for (i = 0; i < 256; i++)
	{
		ctx->S[i] = ctx->S[i] ^ in_key[k];
		if (++k >= key_len)
			k = 0;
	}
}

void arc4_crypt(RC4_CTX *ctx, unsigned char *byte)
{
	unsigned char * const S = ctx->S;
	unsigned char x = ctx->x;
	unsigned char y = ctx->y;
	unsigned char a, b;

	a = S[x];
	y = (y + a) & 0xff;
	b = S[y];
	S[x] = b;
	S[y] = a;
	x = (x + 1) & 0xff;
	*byte ^= S[(a + b) & 0xff];

	ctx->x = x;
	ctx->y = y;
}

void arc4_crypt_message(RC4_CTX *ctx, const void *msg, size_t msg_len, void *dst)
{
	for (register size_t i=0; i<msg_len; i++)
	{
		register unsigned char b = ((unsigned char*)msg)[i];
		arc4_crypt(ctx,&b);
		((unsigned char*)dst)[i] = b;
	}
}

void EncryptRc4(const void* key,size_t keylen,void* dst,const void* src,size_t len)
{
	RC4_CTX Ctx;

	arc4_set_key(&Ctx,(const unsigned char*)key,keylen);
	arc4_crypt_message(&Ctx,src,len,dst);
}