#ifndef _XSTRING_H_
#define _XSTRING_H_

class XString
{
	unsigned char * m_Buffer;
	size_t m_CurrentBufferSize;
	size_t m_CurrentLength;
	size_t m_CurrentGrowFactor;

	void Reset();
	void Grow(size_t NewSize);
	void Append_q(const unsigned char * lpSource,size_t cbSource);

public:

	static const size_t npos = -1;

	XString();
	XString(const char * lpszSource);
	XString(const unsigned char * lpSource,size_t cbSource);
	XString(const XString& Source);
	~XString();
	size_t Capture(unsigned char * Out,size_t CaptureFromPos,size_t Length) const;
	void CopyFrom(const XString& Source);
	void CopyFrom(const char * lpszSource);
	void CopyFrom(const unsigned char * lpSource,size_t cbSource);
	void Append(const char * lpszSource);
	void Append(const XString& Source);
	void Append(char Source);
	void Append(const unsigned char * lpSource,size_t cbSource);
	void Append_base64(const unsigned char * lpSource,size_t cbSource);
	const char * c_str() const;
	const unsigned char * c_mem() const;
	size_t length() const;
	XString substr(size_t Offset,size_t Length = npos);
	size_t Find(char cChar,size_t Offset = 0) const;
	size_t Find(const char * lpszSource,size_t Offset = 0,bool bIgnoreCase = false) const;
	XString& operator =(const XString& s);
	XString& operator =(const char * lpszSource);
	XString& operator +=(const char * Adding);
	XString& operator +=(const XString& Adding);
	XString& operator +=(char Adding);

	template <typename _T> void BinaryWrite(const _T& Value)
	{
		Append((const unsigned char*)&Value,sizeof(_T));
	}

	void BinaryWriteRaw(const void * v,size_t len);
	void BinaryWriteString(const char * v);
	void BinaryWriteString(const XString& v);
};

#endif
