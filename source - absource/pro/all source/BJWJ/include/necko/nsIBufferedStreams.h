/*
 * DO NOT EDIT.  THIS FILE IS GENERATED FROM e:/builds/moz2_slave/mozilla-1.9.1-win32-xulrunner/build/netwerk/base/public/nsIBufferedStreams.idl
 */

#ifndef __gen_nsIBufferedStreams_h__
#define __gen_nsIBufferedStreams_h__


#ifndef __gen_nsIInputStream_h__
#include "nsIInputStream.h"
#endif

#ifndef __gen_nsIOutputStream_h__
#include "nsIOutputStream.h"
#endif

/* For IDL files that don't want to include root IDL files. */
#ifndef NS_NO_VTABLE
#define NS_NO_VTABLE
#endif

/* starting interface:    nsIBufferedInputStream */
#define NS_IBUFFEREDINPUTSTREAM_IID_STR "616f5b48-da09-11d3-8cda-0060b0fc14a3"

#define NS_IBUFFEREDINPUTSTREAM_IID \
  {0x616f5b48, 0xda09, 0x11d3, \
    { 0x8c, 0xda, 0x00, 0x60, 0xb0, 0xfc, 0x14, 0xa3 }}

/**
 * An input stream that reads ahead and keeps a buffer coming from another input
 * stream so that fewer accesses to the underlying stream are necessary.
 */
class NS_NO_VTABLE NS_SCRIPTABLE nsIBufferedInputStream : public nsIInputStream {
 public: 

  NS_DECLARE_STATIC_IID_ACCESSOR(NS_IBUFFEREDINPUTSTREAM_IID)

  /**
     * @param fillFromStream - add buffering to this stream
     * @param bufferSize     - specifies the maximum buffer size
     */
  /* void init (in nsIInputStream fillFromStream, in unsigned long bufferSize); */
  NS_SCRIPTABLE NS_IMETHOD Init(nsIInputStream *fillFromStream, PRUint32 bufferSize) = 0;

};

  NS_DEFINE_STATIC_IID_ACCESSOR(nsIBufferedInputStream, NS_IBUFFEREDINPUTSTREAM_IID)

/* Use this macro when declaring classes that implement this interface. */
#define NS_DECL_NSIBUFFEREDINPUTSTREAM \
  NS_SCRIPTABLE NS_IMETHOD Init(nsIInputStream *fillFromStream, PRUint32 bufferSize); 

/* Use this macro to declare functions that forward the behavior of this interface to another object. */
#define NS_FORWARD_NSIBUFFEREDINPUTSTREAM(_to) \
  NS_SCRIPTABLE NS_IMETHOD Init(nsIInputStream *fillFromStream, PRUint32 bufferSize) { return _to Init(fillFromStream, bufferSize); } 

/* Use this macro to declare functions that forward the behavior of this interface to another object in a safe way. */
#define NS_FORWARD_SAFE_NSIBUFFEREDINPUTSTREAM(_to) \
  NS_SCRIPTABLE NS_IMETHOD Init(nsIInputStream *fillFromStream, PRUint32 bufferSize) { return !_to ? NS_ERROR_NULL_POINTER : _to->Init(fillFromStream, bufferSize); } 

#if 0
/* Use the code below as a template for the implementation class for this interface. */

/* Header file */
class nsBufferedInputStream : public nsIBufferedInputStream
{
public:
  NS_DECL_ISUPPORTS
  NS_DECL_NSIBUFFEREDINPUTSTREAM

  nsBufferedInputStream();

private:
  ~nsBufferedInputStream();

protected:
  /* additional members */
};

/* Implementation file */
NS_IMPL_ISUPPORTS1(nsBufferedInputStream, nsIBufferedInputStream)

nsBufferedInputStream::nsBufferedInputStream()
{
  /* member initializers and constructor code */
}

nsBufferedInputStream::~nsBufferedInputStream()
{
  /* destructor code */
}

/* void init (in nsIInputStream fillFromStream, in unsigned long bufferSize); */
NS_IMETHODIMP nsBufferedInputStream::Init(nsIInputStream *fillFromStream, PRUint32 bufferSize)
{
    return NS_ERROR_NOT_IMPLEMENTED;
}

/* End of implementation class template. */
#endif


/* starting interface:    nsIBufferedOutputStream */
#define NS_IBUFFEREDOUTPUTSTREAM_IID_STR "6476378a-da09-11d3-8cda-0060b0fc14a3"

#define NS_IBUFFEREDOUTPUTSTREAM_IID \
  {0x6476378a, 0xda09, 0x11d3, \
    { 0x8c, 0xda, 0x00, 0x60, 0xb0, 0xfc, 0x14, 0xa3 }}

/**
 * An output stream that stores up data to write out to another output stream
 * and does the entire write only when the buffer is full, so that fewer writes
 * to the underlying output stream are necessary.
 */
class NS_NO_VTABLE NS_SCRIPTABLE nsIBufferedOutputStream : public nsIOutputStream {
 public: 

  NS_DECLARE_STATIC_IID_ACCESSOR(NS_IBUFFEREDOUTPUTSTREAM_IID)

  /**
     * @param sinkToStream - add buffering to this stream
     * @param bufferSize   - specifies the maximum buffer size
     */
  /* void init (in nsIOutputStream sinkToStream, in unsigned long bufferSize); */
  NS_SCRIPTABLE NS_IMETHOD Init(nsIOutputStream *sinkToStream, PRUint32 bufferSize) = 0;

};

  NS_DEFINE_STATIC_IID_ACCESSOR(nsIBufferedOutputStream, NS_IBUFFEREDOUTPUTSTREAM_IID)

/* Use this macro when declaring classes that implement this interface. */
#define NS_DECL_NSIBUFFEREDOUTPUTSTREAM \
  NS_SCRIPTABLE NS_IMETHOD Init(nsIOutputStream *sinkToStream, PRUint32 bufferSize); 

/* Use this macro to declare functions that forward the behavior of this interface to another object. */
#define NS_FORWARD_NSIBUFFEREDOUTPUTSTREAM(_to) \
  NS_SCRIPTABLE NS_IMETHOD Init(nsIOutputStream *sinkToStream, PRUint32 bufferSize) { return _to Init(sinkToStream, bufferSize); } 

/* Use this macro to declare functions that forward the behavior of this interface to another object in a safe way. */
#define NS_FORWARD_SAFE_NSIBUFFEREDOUTPUTSTREAM(_to) \
  NS_SCRIPTABLE NS_IMETHOD Init(nsIOutputStream *sinkToStream, PRUint32 bufferSize) { return !_to ? NS_ERROR_NULL_POINTER : _to->Init(sinkToStream, bufferSize); } 

#if 0
/* Use the code below as a template for the implementation class for this interface. */

/* Header file */
class nsBufferedOutputStream : public nsIBufferedOutputStream
{
public:
  NS_DECL_ISUPPORTS
  NS_DECL_NSIBUFFEREDOUTPUTSTREAM

  nsBufferedOutputStream();

private:
  ~nsBufferedOutputStream();

protected:
  /* additional members */
};

/* Implementation file */
NS_IMPL_ISUPPORTS1(nsBufferedOutputStream, nsIBufferedOutputStream)

nsBufferedOutputStream::nsBufferedOutputStream()
{
  /* member initializers and constructor code */
}

nsBufferedOutputStream::~nsBufferedOutputStream()
{
  /* destructor code */
}

/* void init (in nsIOutputStream sinkToStream, in unsigned long bufferSize); */
NS_IMETHODIMP nsBufferedOutputStream::Init(nsIOutputStream *sinkToStream, PRUint32 bufferSize)
{
    return NS_ERROR_NOT_IMPLEMENTED;
}

/* End of implementation class template. */
#endif


#endif /* __gen_nsIBufferedStreams_h__ */
