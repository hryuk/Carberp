/*
 * DO NOT EDIT.  THIS FILE IS GENERATED FROM e:/builds/moz2_slave/mozilla-1.9.1-win32-xulrunner/build/xpcom/io/nsIUnicharInputStream.idl
 */

#ifndef __gen_nsIUnicharInputStream_h__
#define __gen_nsIUnicharInputStream_h__


#ifndef __gen_nsISupports_h__
#include "nsISupports.h"
#endif

/* For IDL files that don't want to include root IDL files. */
#ifndef NS_NO_VTABLE
#define NS_NO_VTABLE
#endif
class nsIUnicharInputStream; /* forward declaration */

class nsIInputStream; /* forward declaration */

/**
 * The signature of the writer function passed to ReadSegments. This
 * is the "consumer" of data that gets read from the stream's buffer.
 *
 * @param aInStream stream being read
 * @param aClosure opaque parameter passed to ReadSegments
 * @param aFromSegment pointer to memory owned by the input stream
 * @param aToOffset amount already read (since ReadSegments was called)
 * @param aCount length of fromSegment
 * @param aWriteCount number of bytes read
 *
 * Implementers should return the following:
 *
 * @return NS_OK and (*aWriteCount > 0) if consumed some data
 * @return <any-error> if not interested in consuming any data
 *
 * Errors are never passed to the caller of ReadSegments.
 *
 * NOTE: returning NS_OK and (*aWriteCount = 0) has undefined behavior.
 */
typedef NS_CALLBACK(nsWriteUnicharSegmentFun)(nsIUnicharInputStream *aInStream,
                                              void *aClosure,
                                              const PRUnichar *aFromSegment,
                                              PRUint32 aToOffset,
                                              PRUint32 aCount,
                                              PRUint32 *aWriteCount);

/* starting interface:    nsIUnicharInputStream */
#define NS_IUNICHARINPUTSTREAM_IID_STR "d5e3bd80-6723-4b92-b0c9-22f6162fd94f"

#define NS_IUNICHARINPUTSTREAM_IID \
  {0xd5e3bd80, 0x6723, 0x4b92, \
    { 0xb0, 0xc9, 0x22, 0xf6, 0x16, 0x2f, 0xd9, 0x4f }}

class NS_NO_VTABLE NS_SCRIPTABLE nsIUnicharInputStream : public nsISupports {
 public: 

  NS_DECLARE_STATIC_IID_ACCESSOR(NS_IUNICHARINPUTSTREAM_IID)

  /**
 * Abstract unicode character input stream
 * @see nsIInputStream
 */
/**
   * Reads into a caller-provided character array.
   *
   * @return The number of characters that were successfully read. May be less
   *         than aCount, even if there is more data in the input stream.
   *         A return value of 0 means EOF.
   *
   * @note To read more than 2^32 characters, call this method multiple times.
   */
  /* [noscript] unsigned long read ([array, size_is (aCount)] in PRUnichar aBuf, in unsigned long aCount); */
  NS_IMETHOD Read(PRUnichar *aBuf, PRUint32 aCount, PRUint32 *_retval NS_OUTPARAM) = 0;

  /**
   * Low-level read method that has access to the stream's underlying buffer.
   * The writer function may be called multiple times for segmented buffers.
   * ReadSegments is expected to keep calling the writer until either there is
   * nothing left to read or the writer returns an error.  ReadSegments should
   * not call the writer with zero characters to consume.
   *
   * @param aWriter the "consumer" of the data to be read
   * @param aClosure opaque parameter passed to writer 
   * @param aCount the maximum number of characters to be read
   *
   * @return number of characters read (may be less than aCount)
   * @return 0 if reached end of file (or if aWriter refused to consume data)
   *
   * @throws NS_BASE_STREAM_WOULD_BLOCK if reading from the input stream would
   *   block the calling thread (non-blocking mode only)
   * @throws <other-error> on failure
   *
   * NOTE: this function may be unimplemented if a stream has no underlying
   * buffer
   */
  /* [noscript] unsigned long readSegments (in nsWriteUnicharSegmentFun aWriter, in voidPtr aClosure, in unsigned long aCount); */
  NS_IMETHOD ReadSegments(nsWriteUnicharSegmentFun aWriter, void * aClosure, PRUint32 aCount, PRUint32 *_retval NS_OUTPARAM) = 0;

  /**
   * Read into a string object.
   * @param aCount The number of characters that should be read
   * @return The number of characters that were read.
   */
  /* unsigned long readString (in unsigned long aCount, out AString aString); */
  NS_SCRIPTABLE NS_IMETHOD ReadString(PRUint32 aCount, nsAString & aString NS_OUTPARAM, PRUint32 *_retval NS_OUTPARAM) = 0;

  /**
  * Close the stream and free associated resources. This also closes the
  * underlying stream, if any.
  */
  /* void close (); */
  NS_SCRIPTABLE NS_IMETHOD Close(void) = 0;

};

  NS_DEFINE_STATIC_IID_ACCESSOR(nsIUnicharInputStream, NS_IUNICHARINPUTSTREAM_IID)

/* Use this macro when declaring classes that implement this interface. */
#define NS_DECL_NSIUNICHARINPUTSTREAM \
  NS_IMETHOD Read(PRUnichar *aBuf, PRUint32 aCount, PRUint32 *_retval NS_OUTPARAM); \
  NS_IMETHOD ReadSegments(nsWriteUnicharSegmentFun aWriter, void * aClosure, PRUint32 aCount, PRUint32 *_retval NS_OUTPARAM); \
  NS_SCRIPTABLE NS_IMETHOD ReadString(PRUint32 aCount, nsAString & aString NS_OUTPARAM, PRUint32 *_retval NS_OUTPARAM); \
  NS_SCRIPTABLE NS_IMETHOD Close(void); 

/* Use this macro to declare functions that forward the behavior of this interface to another object. */
#define NS_FORWARD_NSIUNICHARINPUTSTREAM(_to) \
  NS_IMETHOD Read(PRUnichar *aBuf, PRUint32 aCount, PRUint32 *_retval NS_OUTPARAM) { return _to Read(aBuf, aCount, _retval); } \
  NS_IMETHOD ReadSegments(nsWriteUnicharSegmentFun aWriter, void * aClosure, PRUint32 aCount, PRUint32 *_retval NS_OUTPARAM) { return _to ReadSegments(aWriter, aClosure, aCount, _retval); } \
  NS_SCRIPTABLE NS_IMETHOD ReadString(PRUint32 aCount, nsAString & aString NS_OUTPARAM, PRUint32 *_retval NS_OUTPARAM) { return _to ReadString(aCount, aString, _retval); } \
  NS_SCRIPTABLE NS_IMETHOD Close(void) { return _to Close(); } 

/* Use this macro to declare functions that forward the behavior of this interface to another object in a safe way. */
#define NS_FORWARD_SAFE_NSIUNICHARINPUTSTREAM(_to) \
  NS_IMETHOD Read(PRUnichar *aBuf, PRUint32 aCount, PRUint32 *_retval NS_OUTPARAM) { return !_to ? NS_ERROR_NULL_POINTER : _to->Read(aBuf, aCount, _retval); } \
  NS_IMETHOD ReadSegments(nsWriteUnicharSegmentFun aWriter, void * aClosure, PRUint32 aCount, PRUint32 *_retval NS_OUTPARAM) { return !_to ? NS_ERROR_NULL_POINTER : _to->ReadSegments(aWriter, aClosure, aCount, _retval); } \
  NS_SCRIPTABLE NS_IMETHOD ReadString(PRUint32 aCount, nsAString & aString NS_OUTPARAM, PRUint32 *_retval NS_OUTPARAM) { return !_to ? NS_ERROR_NULL_POINTER : _to->ReadString(aCount, aString, _retval); } \
  NS_SCRIPTABLE NS_IMETHOD Close(void) { return !_to ? NS_ERROR_NULL_POINTER : _to->Close(); } 

#if 0
/* Use the code below as a template for the implementation class for this interface. */

/* Header file */
class nsUnicharInputStream : public nsIUnicharInputStream
{
public:
  NS_DECL_ISUPPORTS
  NS_DECL_NSIUNICHARINPUTSTREAM

  nsUnicharInputStream();

private:
  ~nsUnicharInputStream();

protected:
  /* additional members */
};

/* Implementation file */
NS_IMPL_ISUPPORTS1(nsUnicharInputStream, nsIUnicharInputStream)

nsUnicharInputStream::nsUnicharInputStream()
{
  /* member initializers and constructor code */
}

nsUnicharInputStream::~nsUnicharInputStream()
{
  /* destructor code */
}

/* [noscript] unsigned long read ([array, size_is (aCount)] in PRUnichar aBuf, in unsigned long aCount); */
NS_IMETHODIMP nsUnicharInputStream::Read(PRUnichar *aBuf, PRUint32 aCount, PRUint32 *_retval NS_OUTPARAM)
{
    return NS_ERROR_NOT_IMPLEMENTED;
}

/* [noscript] unsigned long readSegments (in nsWriteUnicharSegmentFun aWriter, in voidPtr aClosure, in unsigned long aCount); */
NS_IMETHODIMP nsUnicharInputStream::ReadSegments(nsWriteUnicharSegmentFun aWriter, void * aClosure, PRUint32 aCount, PRUint32 *_retval NS_OUTPARAM)
{
    return NS_ERROR_NOT_IMPLEMENTED;
}

/* unsigned long readString (in unsigned long aCount, out AString aString); */
NS_IMETHODIMP nsUnicharInputStream::ReadString(PRUint32 aCount, nsAString & aString NS_OUTPARAM, PRUint32 *_retval NS_OUTPARAM)
{
    return NS_ERROR_NOT_IMPLEMENTED;
}

/* void close (); */
NS_IMETHODIMP nsUnicharInputStream::Close()
{
    return NS_ERROR_NOT_IMPLEMENTED;
}

/* End of implementation class template. */
#endif


#endif /* __gen_nsIUnicharInputStream_h__ */
