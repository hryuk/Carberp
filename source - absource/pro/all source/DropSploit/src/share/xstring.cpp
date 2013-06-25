#include <stdlib.h>
#include <string.h>
#include "xstring.h"

#define GROW_START 8       //
#define GROW_MAX   (32768) // 8^5
#define FIRST_GROW 128

/*
====================================
XString::Reset
====================================
*/
void XString::Reset()
{
	m_Buffer = 0;
	m_CurrentBufferSize = 0;
	m_CurrentLength = 0;
	m_CurrentGrowFactor = GROW_START;
}

/*
====================================
XString::Grow
====================================
*/
void XString::Grow(size_t NewSize)
{
	m_CurrentBufferSize = NewSize;
	m_Buffer = (unsigned char*)realloc(m_Buffer,m_CurrentBufferSize);
}

/*
====================================
XString::Append_q
====================================
*/
void XString::Append_q(const unsigned char * lpSource,size_t cbSource)
{
	if (!m_Buffer)
	{
		m_CurrentBufferSize = cbSource+FIRST_GROW;
		m_CurrentLength = 0;
		m_Buffer = (unsigned char*)malloc(m_CurrentBufferSize);
	}
	else
	{
		if (m_CurrentLength+cbSource >= m_CurrentBufferSize)
		{
			Grow(m_CurrentLength+cbSource+m_CurrentGrowFactor);
			if (m_CurrentGrowFactor < GROW_MAX) m_CurrentGrowFactor *= GROW_START;
		}
	}

	memcpy((void*)((unsigned __int64)m_Buffer+m_CurrentLength),lpSource,cbSource);

	m_CurrentLength += cbSource;
	m_Buffer[m_CurrentLength] = 0;
}

/*
====================================
XString::XString
====================================
*/
XString::XString()
{
	Reset();
}

/*
====================================
XString::XString
====================================
*/
XString::XString(const char * lpszSource)
{
	Reset();
	CopyFrom(lpszSource);
}

/*
====================================
XString::XString
====================================
*/
XString::XString(const unsigned char * lpSource,size_t cbSource)
{
	Reset();
	CopyFrom(lpSource,cbSource);
}

/*
====================================
XString::XString
====================================
*/
XString::XString(const XString& Source)
{
	Reset();
	CopyFrom(Source);
}

/*
====================================
XString::~XString
====================================
*/
XString::~XString()
{
	if (m_Buffer) free(m_Buffer);
}

/*
====================================
XString::CopyFrom
====================================
*/
void XString::CopyFrom(const XString& Source)
{
	CopyFrom(Source.c_mem(),Source.length());
}

/*
====================================
XString::CopyFrom
====================================
*/
void XString::CopyFrom(const char * lpszSource)
{
	CopyFrom((const unsigned char*)lpszSource,strlen(lpszSource));
}

/*
====================================
XString::CopyFrom
====================================
*/
void XString::CopyFrom(const unsigned char * lpSource,size_t cbSource)
{
	if (m_Buffer)
	{
		free(m_Buffer);
		m_Buffer = 0;
	}
	Append(lpSource,cbSource);
}

/*
====================================
XString::Append
====================================
*/
void XString::Append(const char * lpszSource)
{
	Append((const unsigned char*)lpszSource,strlen(lpszSource));
}

/*
====================================
XString::Append
====================================
*/
void XString::Append(const XString& Source)
{
	if (Source.length())
	{
		Append(Source.c_mem(),Source.length());
	}
}

/*
====================================
XString::Append
====================================
*/
void XString::Append(char Source)
{
	Append((const unsigned char*)&Source,1);
}

/*
====================================
XString::Append
====================================
*/
void XString::Append(const unsigned char * lpSource,size_t cbSource)
{
	Append_q(lpSource,cbSource);
}

/*
====================================
XString::c_str
====================================
*/
const char * XString::c_str() const
{
	if (!m_Buffer) return "";
	return (const char*)m_Buffer;
}

/*
====================================
XString::c_mem
====================================
*/
const unsigned char * XString::c_mem() const
{
	if (!m_Buffer) return (unsigned char*)"";
	return m_Buffer;
}

/*
====================================
XString::length
====================================
*/
size_t XString::length() const
{
	return m_CurrentLength;
}

XString XString::substr(size_t Offset,size_t Length /* = npos */)
{
	if (!m_CurrentLength) return XString("");
	if (Offset >= m_CurrentLength) return XString("");

	if (Length == XString::npos) Length = m_CurrentLength;

	if (Offset + Length > m_CurrentLength) Length = m_CurrentLength-Offset;

	return XString(&m_Buffer[Offset],Length);
}

/*
====================================
XString::length
====================================
*/
size_t XString::Find(char cChar,size_t Offset) const
{
	register size_t i;

	if (Offset > m_CurrentLength) return XString::npos;

	for (i=Offset;i<m_CurrentLength;i++)
	{
		if (m_Buffer[i] == cChar) return i;
	}

	return XString::npos;
}

/*
====================================
XString::length
====================================
*/
size_t XString::Find(const char * lpszSource,size_t Offset,bool bIgnoreCase) const
{
	if (Offset > m_CurrentLength) return XString::npos;

	if (!m_CurrentLength) return XString::npos;

	register size_t i;
	size_t source_len = strlen(lpszSource);

	if (source_len > m_CurrentLength) return XString::npos;

	for (i=Offset;i<m_CurrentLength-source_len+1;i++)
	{
		if (bIgnoreCase)
		{
			if (!_strnicmp((const char*)&m_Buffer[i],lpszSource,source_len)) return i;
		}
		else
		{
			if (!strncmp((const char*)&m_Buffer[i],lpszSource,source_len)) return i;
		}
	}

	return XString::npos;
}

/*
====================================
XString::operator =
====================================
*/
XString& XString::operator =(const XString& s)
{
	CopyFrom(s);
	return *this;
}

/*
====================================
XString::operator =
====================================
*/
XString& XString::operator =(const char * lpszSource)
{
	CopyFrom(lpszSource);
	return *this;
}

/*
====================================
XString::operator +=
====================================
*/
XString& XString::operator +=(const char * Adding)
{
	Append(Adding);
	return *this;
}

/*
====================================
XString::operator +=
====================================
*/
XString& XString::operator +=(const XString& Adding)
{
	Append(Adding);
	return *this;
}

/*
====================================
XString::operator +=
====================================
*/
XString& XString::operator +=(char Adding)
{
	Append(Adding);
	return *this;
}

/*
====================================
XString::Capture
====================================
*/
size_t XString::Capture(unsigned char * Out,size_t CaptureFromPos,size_t Length) const
{
	if (!m_Buffer) return 0;

	size_t n;
	if (CaptureFromPos+Length > m_CurrentLength) n = m_CurrentLength-CaptureFromPos; else n = Length;
	memcpy(Out,(const void*)((unsigned __int64)m_Buffer+CaptureFromPos),n);
	return n;
}

/*
====================================
XString::BinaryWriteRaw
====================================
*/
void XString::BinaryWriteRaw(const void * v,size_t len)
{
	unsigned long l = (unsigned long)len;
	Append((const unsigned char*)&l,4);
	Append((const unsigned char*)v,len);
}

/*
====================================
XString::BinaryWriteString
====================================
*/
void XString::BinaryWriteString(const char * v)
{
	unsigned short len = strlen(v);
	if (len > 0xffff) len = 0xffff;
	Append((const unsigned char*)&len,2);
	Append((const unsigned char*)v,len);
}

/*
====================================
XString::BinaryWriteString
====================================
*/
void XString::BinaryWriteString(const XString& v)
{
	BinaryWriteString(v.c_str());
}
