/*
 * DO NOT EDIT.  THIS FILE IS GENERATED FROM e:/builds/moz2_slave/mozilla-1.9.1-win32-xulrunner/build/xpcom/io/nsIStringStream.idl
 */

#ifndef __gen_nsIStringStream_h__
#define __gen_nsIStringStream_h__


#ifndef __gen_nsIInputStream_h__
#include "nsIInputStream.h"
#endif

/* For IDL files that don't want to include root IDL files. */
#ifndef NS_NO_VTABLE
#define NS_NO_VTABLE
#endif

/* starting interface:    nsIStringInputStream */
#define NS_ISTRINGINPUTSTREAM_IID_STR "450cd2d4-f0fd-424d-b365-b1251f80fd53"

#define NS_ISTRINGINPUTSTREAM_IID \
  {0x450cd2d4, 0xf0fd, 0x424d, \
    { 0xb3, 0x65, 0xb1, 0x25, 0x1f, 0x80, 0xfd, 0x53 }}

/**
 * nsIStringInputStream
 *
 * Provides scriptable and specialized C++-only methods for initializing a
 * nsIInputStream implementation with a simple character array.
 *
 * @status UNDER_REVIEW
 */
class NS_NO_VTABLE NS_SCRIPTABLE nsIStringInputStream : public nsIInputStream {
 public: 

  NS_DECLARE_STATIC_IID_ACCESSOR(NS_ISTRINGINPUTSTREAM_IID)

  /**
     * SetData - assign data to the input stream (copied on assignment).
     *
     * @param data    - stream data
     * @param dataLen - stream data length (-1 if length should be computed)
     *
     * NOTE: C++ code should consider using AdoptData or ShareData to avoid
     * making an extra copy of the stream data.
     *
     * NOTE: For JS callers, the given data must not contain null characters
     * (other than a null terminator) because a null character in the middle of
     * the data string will be seen as a terminator when the data is converted
     * from a JS string to a C++ character array.
     */
  /* void setData (in string data, in long dataLen); */
  NS_SCRIPTABLE NS_IMETHOD SetData(const char *data, PRInt32 dataLen) = 0;

  /**
     * NOTE: the following methods are designed to give C++ code added control
     * over the ownership and lifetime of the stream data.  Use with care :-)
     */
/**
     * AdoptData - assign data to the input stream.  the input stream takes
     * ownership of the given data buffer and will nsMemory::Free it when
     * the input stream is destroyed.
     *
     * @param data      - stream data
     * @param dataLen   - stream data length (-1 if length should be computed)
     */
  /* [noscript] void adoptData (in charPtr data, in long dataLen); */
  NS_IMETHOD AdoptData(char * data, PRInt32 dataLen) = 0;

  /**
     * ShareData - assign data to the input stream.  the input stream references
     * the given data buffer until the input stream is destroyed.  the given
     * data buffer must outlive the input stream.
     *
     * @param data      - stream data
     * @param dataLen   - stream data length (-1 if length should be computed)
     */
  /* [noscript] void shareData (in string data, in long dataLen); */
  NS_IMETHOD ShareData(const char *data, PRInt32 dataLen) = 0;

};

  NS_DEFINE_STATIC_IID_ACCESSOR(nsIStringInputStream, NS_ISTRINGINPUTSTREAM_IID)

/* Use this macro when declaring classes that implement this interface. */
#define NS_DECL_NSISTRINGINPUTSTREAM \
  NS_SCRIPTABLE NS_IMETHOD SetData(const char *data, PRInt32 dataLen); \
  NS_IMETHOD AdoptData(char * data, PRInt32 dataLen); \
  NS_IMETHOD ShareData(const char *data, PRInt32 dataLen); 

/* Use this macro to declare functions that forward the behavior of this interface to another object. */
#define NS_FORWARD_NSISTRINGINPUTSTREAM(_to) \
  NS_SCRIPTABLE NS_IMETHOD SetData(const char *data, PRInt32 dataLen) { return _to SetData(data, dataLen); } \
  NS_IMETHOD AdoptData(char * data, PRInt32 dataLen) { return _to AdoptData(data, dataLen); } \
  NS_IMETHOD ShareData(const char *data, PRInt32 dataLen) { return _to ShareData(data, dataLen); } 

/* Use this macro to declare functions that forward the behavior of this interface to another object in a safe way. */
#define NS_FORWARD_SAFE_NSISTRINGINPUTSTREAM(_to) \
  NS_SCRIPTABLE NS_IMETHOD SetData(const char *data, PRInt32 dataLen) { return !_to ? NS_ERROR_NULL_POINTER : _to->SetData(data, dataLen); } \
  NS_IMETHOD AdoptData(char * data, PRInt32 dataLen) { return !_to ? NS_ERROR_NULL_POINTER : _to->AdoptData(data, dataLen); } \
  NS_IMETHOD ShareData(const char *data, PRInt32 dataLen) { return !_to ? NS_ERROR_NULL_POINTER : _to->ShareData(data, dataLen); } 

#if 0
/* Use the code below as a template for the implementation class for this interface. */

/* Header file */
class nsStringInputStream : public nsIStringInputStream
{
public:
  NS_DECL_ISUPPORTS
  NS_DECL_NSISTRINGINPUTSTREAM

  nsStringInputStream();

private:
  ~nsStringInputStream();

protected:
  /* additional members */
};

/* Implementation file */
NS_IMPL_ISUPPORTS1(nsStringInputStream, nsIStringInputStream)

nsStringInputStream::nsStringInputStream()
{
  /* member initializers and constructor code */
}

nsStringInputStream::~nsStringInputStream()
{
  /* destructor code */
}

/* void setData (in string data, in long dataLen); */
NS_IMETHODIMP nsStringInputStream::SetData(const char *data, PRInt32 dataLen)
{
    return NS_ERROR_NOT_IMPLEMENTED;
}

/* [noscript] void adoptData (in charPtr data, in long dataLen); */
NS_IMETHODIMP nsStringInputStream::AdoptData(char * data, PRInt32 dataLen)
{
    return NS_ERROR_NOT_IMPLEMENTED;
}

/* [noscript] void shareData (in string data, in long dataLen); */
NS_IMETHODIMP nsStringInputStream::ShareData(const char *data, PRInt32 dataLen)
{
    return NS_ERROR_NOT_IMPLEMENTED;
}

/* End of implementation class template. */
#endif


#endif /* __gen_nsIStringStream_h__ */
