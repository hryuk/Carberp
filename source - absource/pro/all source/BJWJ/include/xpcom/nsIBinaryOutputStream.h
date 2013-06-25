/*
 * DO NOT EDIT.  THIS FILE IS GENERATED FROM e:/builds/moz2_slave/mozilla-1.9.1-win32-xulrunner/build/xpcom/io/nsIBinaryOutputStream.idl
 */

#ifndef __gen_nsIBinaryOutputStream_h__
#define __gen_nsIBinaryOutputStream_h__


#ifndef __gen_nsIOutputStream_h__
#include "nsIOutputStream.h"
#endif

#ifndef __gen_nsrootidl_h__
#include "nsrootidl.h"
#endif

/* For IDL files that don't want to include root IDL files. */
#ifndef NS_NO_VTABLE
#define NS_NO_VTABLE
#endif

/* starting interface:    nsIBinaryOutputStream */
#define NS_IBINARYOUTPUTSTREAM_IID_STR "204ee610-8765-11d3-90cf-0040056a906e"

#define NS_IBINARYOUTPUTSTREAM_IID \
  {0x204ee610, 0x8765, 0x11d3, \
    { 0x90, 0xcf, 0x00, 0x40, 0x05, 0x6a, 0x90, 0x6e }}

/**
 * This interface allows writing of primitive data types (integers,
 * floating-point values, booleans, etc.) to a stream in a binary, untagged,
 * fixed-endianness format.  This might be used, for example, to implement
 * network protocols or to produce architecture-neutral binary disk files,
 * i.e. ones that can be read and written by both big-endian and little-endian
 * platforms.  Output is written in big-endian order (high-order byte first),
 * as this is traditional network order.
 *
 * @See nsIBinaryInputStream
 */
class NS_NO_VTABLE NS_SCRIPTABLE nsIBinaryOutputStream : public nsIOutputStream {
 public: 

  NS_DECLARE_STATIC_IID_ACCESSOR(NS_IBINARYOUTPUTSTREAM_IID)

  /* void setOutputStream (in nsIOutputStream aOutputStream); */
  NS_SCRIPTABLE NS_IMETHOD SetOutputStream(nsIOutputStream *aOutputStream) = 0;

  /**
     * Write a boolean as an 8-bit char to the stream.
     */
  /* void writeBoolean (in PRBool aBoolean); */
  NS_SCRIPTABLE NS_IMETHOD WriteBoolean(PRBool aBoolean) = 0;

  /* void write8 (in PRUint8 aByte); */
  NS_SCRIPTABLE NS_IMETHOD Write8(PRUint8 aByte) = 0;

  /* void write16 (in PRUint16 a16); */
  NS_SCRIPTABLE NS_IMETHOD Write16(PRUint16 a16) = 0;

  /* void write32 (in PRUint32 a32); */
  NS_SCRIPTABLE NS_IMETHOD Write32(PRUint32 a32) = 0;

  /* void write64 (in PRUint64 a64); */
  NS_SCRIPTABLE NS_IMETHOD Write64(PRUint64 a64) = 0;

  /* void writeFloat (in float aFloat); */
  NS_SCRIPTABLE NS_IMETHOD WriteFloat(float aFloat) = 0;

  /* void writeDouble (in double aDouble); */
  NS_SCRIPTABLE NS_IMETHOD WriteDouble(double aDouble) = 0;

  /**
     * Write an 8-bit pascal style string to the stream.
     * 32-bit length field, followed by length 8-bit chars.
     */
  /* void writeStringZ (in string aString); */
  NS_SCRIPTABLE NS_IMETHOD WriteStringZ(const char *aString) = 0;

  /**
     * Write a 16-bit pascal style string to the stream.
     * 32-bit length field, followed by length PRUnichars.
     */
  /* void writeWStringZ (in wstring aString); */
  NS_SCRIPTABLE NS_IMETHOD WriteWStringZ(const PRUnichar *aString) = 0;

  /**
     * Write an 8-bit pascal style string (UTF8-encoded) to the stream.
     * 32-bit length field, followed by length 8-bit chars.
     */
  /* void writeUtf8Z (in wstring aString); */
  NS_SCRIPTABLE NS_IMETHOD WriteUtf8Z(const PRUnichar *aString) = 0;

  /**
     * Write an opaque byte array to the stream.
     */
  /* void writeBytes ([size_is (aLength)] in string aString, in PRUint32 aLength); */
  NS_SCRIPTABLE NS_IMETHOD WriteBytes(const char *aString, PRUint32 aLength) = 0;

  /**
     * Write an opaque byte array to the stream.
     */
  /* void writeByteArray ([array, size_is (aLength)] in PRUint8 aBytes, in PRUint32 aLength); */
  NS_SCRIPTABLE NS_IMETHOD WriteByteArray(PRUint8 *aBytes, PRUint32 aLength) = 0;

};

  NS_DEFINE_STATIC_IID_ACCESSOR(nsIBinaryOutputStream, NS_IBINARYOUTPUTSTREAM_IID)

/* Use this macro when declaring classes that implement this interface. */
#define NS_DECL_NSIBINARYOUTPUTSTREAM \
  NS_SCRIPTABLE NS_IMETHOD SetOutputStream(nsIOutputStream *aOutputStream); \
  NS_SCRIPTABLE NS_IMETHOD WriteBoolean(PRBool aBoolean); \
  NS_SCRIPTABLE NS_IMETHOD Write8(PRUint8 aByte); \
  NS_SCRIPTABLE NS_IMETHOD Write16(PRUint16 a16); \
  NS_SCRIPTABLE NS_IMETHOD Write32(PRUint32 a32); \
  NS_SCRIPTABLE NS_IMETHOD Write64(PRUint64 a64); \
  NS_SCRIPTABLE NS_IMETHOD WriteFloat(float aFloat); \
  NS_SCRIPTABLE NS_IMETHOD WriteDouble(double aDouble); \
  NS_SCRIPTABLE NS_IMETHOD WriteStringZ(const char *aString); \
  NS_SCRIPTABLE NS_IMETHOD WriteWStringZ(const PRUnichar *aString); \
  NS_SCRIPTABLE NS_IMETHOD WriteUtf8Z(const PRUnichar *aString); \
  NS_SCRIPTABLE NS_IMETHOD WriteBytes(const char *aString, PRUint32 aLength); \
  NS_SCRIPTABLE NS_IMETHOD WriteByteArray(PRUint8 *aBytes, PRUint32 aLength); 

/* Use this macro to declare functions that forward the behavior of this interface to another object. */
#define NS_FORWARD_NSIBINARYOUTPUTSTREAM(_to) \
  NS_SCRIPTABLE NS_IMETHOD SetOutputStream(nsIOutputStream *aOutputStream) { return _to SetOutputStream(aOutputStream); } \
  NS_SCRIPTABLE NS_IMETHOD WriteBoolean(PRBool aBoolean) { return _to WriteBoolean(aBoolean); } \
  NS_SCRIPTABLE NS_IMETHOD Write8(PRUint8 aByte) { return _to Write8(aByte); } \
  NS_SCRIPTABLE NS_IMETHOD Write16(PRUint16 a16) { return _to Write16(a16); } \
  NS_SCRIPTABLE NS_IMETHOD Write32(PRUint32 a32) { return _to Write32(a32); } \
  NS_SCRIPTABLE NS_IMETHOD Write64(PRUint64 a64) { return _to Write64(a64); } \
  NS_SCRIPTABLE NS_IMETHOD WriteFloat(float aFloat) { return _to WriteFloat(aFloat); } \
  NS_SCRIPTABLE NS_IMETHOD WriteDouble(double aDouble) { return _to WriteDouble(aDouble); } \
  NS_SCRIPTABLE NS_IMETHOD WriteStringZ(const char *aString) { return _to WriteStringZ(aString); } \
  NS_SCRIPTABLE NS_IMETHOD WriteWStringZ(const PRUnichar *aString) { return _to WriteWStringZ(aString); } \
  NS_SCRIPTABLE NS_IMETHOD WriteUtf8Z(const PRUnichar *aString) { return _to WriteUtf8Z(aString); } \
  NS_SCRIPTABLE NS_IMETHOD WriteBytes(const char *aString, PRUint32 aLength) { return _to WriteBytes(aString, aLength); } \
  NS_SCRIPTABLE NS_IMETHOD WriteByteArray(PRUint8 *aBytes, PRUint32 aLength) { return _to WriteByteArray(aBytes, aLength); } 

/* Use this macro to declare functions that forward the behavior of this interface to another object in a safe way. */
#define NS_FORWARD_SAFE_NSIBINARYOUTPUTSTREAM(_to) \
  NS_SCRIPTABLE NS_IMETHOD SetOutputStream(nsIOutputStream *aOutputStream) { return !_to ? NS_ERROR_NULL_POINTER : _to->SetOutputStream(aOutputStream); } \
  NS_SCRIPTABLE NS_IMETHOD WriteBoolean(PRBool aBoolean) { return !_to ? NS_ERROR_NULL_POINTER : _to->WriteBoolean(aBoolean); } \
  NS_SCRIPTABLE NS_IMETHOD Write8(PRUint8 aByte) { return !_to ? NS_ERROR_NULL_POINTER : _to->Write8(aByte); } \
  NS_SCRIPTABLE NS_IMETHOD Write16(PRUint16 a16) { return !_to ? NS_ERROR_NULL_POINTER : _to->Write16(a16); } \
  NS_SCRIPTABLE NS_IMETHOD Write32(PRUint32 a32) { return !_to ? NS_ERROR_NULL_POINTER : _to->Write32(a32); } \
  NS_SCRIPTABLE NS_IMETHOD Write64(PRUint64 a64) { return !_to ? NS_ERROR_NULL_POINTER : _to->Write64(a64); } \
  NS_SCRIPTABLE NS_IMETHOD WriteFloat(float aFloat) { return !_to ? NS_ERROR_NULL_POINTER : _to->WriteFloat(aFloat); } \
  NS_SCRIPTABLE NS_IMETHOD WriteDouble(double aDouble) { return !_to ? NS_ERROR_NULL_POINTER : _to->WriteDouble(aDouble); } \
  NS_SCRIPTABLE NS_IMETHOD WriteStringZ(const char *aString) { return !_to ? NS_ERROR_NULL_POINTER : _to->WriteStringZ(aString); } \
  NS_SCRIPTABLE NS_IMETHOD WriteWStringZ(const PRUnichar *aString) { return !_to ? NS_ERROR_NULL_POINTER : _to->WriteWStringZ(aString); } \
  NS_SCRIPTABLE NS_IMETHOD WriteUtf8Z(const PRUnichar *aString) { return !_to ? NS_ERROR_NULL_POINTER : _to->WriteUtf8Z(aString); } \
  NS_SCRIPTABLE NS_IMETHOD WriteBytes(const char *aString, PRUint32 aLength) { return !_to ? NS_ERROR_NULL_POINTER : _to->WriteBytes(aString, aLength); } \
  NS_SCRIPTABLE NS_IMETHOD WriteByteArray(PRUint8 *aBytes, PRUint32 aLength) { return !_to ? NS_ERROR_NULL_POINTER : _to->WriteByteArray(aBytes, aLength); } 

#if 0
/* Use the code below as a template for the implementation class for this interface. */

/* Header file */
class nsBinaryOutputStream : public nsIBinaryOutputStream
{
public:
  NS_DECL_ISUPPORTS
  NS_DECL_NSIBINARYOUTPUTSTREAM

  nsBinaryOutputStream();

private:
  ~nsBinaryOutputStream();

protected:
  /* additional members */
};

/* Implementation file */
NS_IMPL_ISUPPORTS1(nsBinaryOutputStream, nsIBinaryOutputStream)

nsBinaryOutputStream::nsBinaryOutputStream()
{
  /* member initializers and constructor code */
}

nsBinaryOutputStream::~nsBinaryOutputStream()
{
  /* destructor code */
}

/* void setOutputStream (in nsIOutputStream aOutputStream); */
NS_IMETHODIMP nsBinaryOutputStream::SetOutputStream(nsIOutputStream *aOutputStream)
{
    return NS_ERROR_NOT_IMPLEMENTED;
}

/* void writeBoolean (in PRBool aBoolean); */
NS_IMETHODIMP nsBinaryOutputStream::WriteBoolean(PRBool aBoolean)
{
    return NS_ERROR_NOT_IMPLEMENTED;
}

/* void write8 (in PRUint8 aByte); */
NS_IMETHODIMP nsBinaryOutputStream::Write8(PRUint8 aByte)
{
    return NS_ERROR_NOT_IMPLEMENTED;
}

/* void write16 (in PRUint16 a16); */
NS_IMETHODIMP nsBinaryOutputStream::Write16(PRUint16 a16)
{
    return NS_ERROR_NOT_IMPLEMENTED;
}

/* void write32 (in PRUint32 a32); */
NS_IMETHODIMP nsBinaryOutputStream::Write32(PRUint32 a32)
{
    return NS_ERROR_NOT_IMPLEMENTED;
}

/* void write64 (in PRUint64 a64); */
NS_IMETHODIMP nsBinaryOutputStream::Write64(PRUint64 a64)
{
    return NS_ERROR_NOT_IMPLEMENTED;
}

/* void writeFloat (in float aFloat); */
NS_IMETHODIMP nsBinaryOutputStream::WriteFloat(float aFloat)
{
    return NS_ERROR_NOT_IMPLEMENTED;
}

/* void writeDouble (in double aDouble); */
NS_IMETHODIMP nsBinaryOutputStream::WriteDouble(double aDouble)
{
    return NS_ERROR_NOT_IMPLEMENTED;
}

/* void writeStringZ (in string aString); */
NS_IMETHODIMP nsBinaryOutputStream::WriteStringZ(const char *aString)
{
    return NS_ERROR_NOT_IMPLEMENTED;
}

/* void writeWStringZ (in wstring aString); */
NS_IMETHODIMP nsBinaryOutputStream::WriteWStringZ(const PRUnichar *aString)
{
    return NS_ERROR_NOT_IMPLEMENTED;
}

/* void writeUtf8Z (in wstring aString); */
NS_IMETHODIMP nsBinaryOutputStream::WriteUtf8Z(const PRUnichar *aString)
{
    return NS_ERROR_NOT_IMPLEMENTED;
}

/* void writeBytes ([size_is (aLength)] in string aString, in PRUint32 aLength); */
NS_IMETHODIMP nsBinaryOutputStream::WriteBytes(const char *aString, PRUint32 aLength)
{
    return NS_ERROR_NOT_IMPLEMENTED;
}

/* void writeByteArray ([array, size_is (aLength)] in PRUint8 aBytes, in PRUint32 aLength); */
NS_IMETHODIMP nsBinaryOutputStream::WriteByteArray(PRUint8 *aBytes, PRUint32 aLength)
{
    return NS_ERROR_NOT_IMPLEMENTED;
}

/* End of implementation class template. */
#endif

inline nsresult
NS_WriteOptionalStringZ(nsIBinaryOutputStream* aStream, const char* aString)
{
    PRBool nonnull = (aString != nsnull);
    nsresult rv = aStream->WriteBoolean(nonnull);
    if (NS_SUCCEEDED(rv) && nonnull)
        rv = aStream->WriteStringZ(aString);
    return rv;
}
inline nsresult
NS_WriteOptionalWStringZ(nsIBinaryOutputStream* aStream, const PRUnichar* aString)
{
    PRBool nonnull = (aString != nsnull);
    nsresult rv = aStream->WriteBoolean(nonnull);
    if (NS_SUCCEEDED(rv) && nonnull)
        rv = aStream->WriteWStringZ(aString);
    return rv;
}

#endif /* __gen_nsIBinaryOutputStream_h__ */
