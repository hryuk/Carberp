/*
 * DO NOT EDIT.  THIS FILE IS GENERATED FROM e:/builds/moz2_slave/mozilla-1.9.1-win32-xulrunner/build/xpcom/io/nsIMultiplexInputStream.idl
 */

#ifndef __gen_nsIMultiplexInputStream_h__
#define __gen_nsIMultiplexInputStream_h__


#ifndef __gen_nsIInputStream_h__
#include "nsIInputStream.h"
#endif

/* For IDL files that don't want to include root IDL files. */
#ifndef NS_NO_VTABLE
#define NS_NO_VTABLE
#endif

/* starting interface:    nsIMultiplexInputStream */
#define NS_IMULTIPLEXINPUTSTREAM_IID_STR "a076fd12-1dd1-11b2-b19a-d53b5dffaade"

#define NS_IMULTIPLEXINPUTSTREAM_IID \
  {0xa076fd12, 0x1dd1, 0x11b2, \
    { 0xb1, 0x9a, 0xd5, 0x3b, 0x5d, 0xff, 0xaa, 0xde }}

/**
 * The multiplex stream concatenates a list of input streams into a single
 * stream.
 */
class NS_NO_VTABLE NS_SCRIPTABLE nsIMultiplexInputStream : public nsIInputStream {
 public: 

  NS_DECLARE_STATIC_IID_ACCESSOR(NS_IMULTIPLEXINPUTSTREAM_IID)

  /**
     * Number of streams in this multiplex-stream
     */
  /* readonly attribute unsigned long count; */
  NS_SCRIPTABLE NS_IMETHOD GetCount(PRUint32 *aCount) = 0;

  /**
     * Appends a stream to the end of the streams. The cursor of the stream
     * should be located at the beginning of the stream if the implementation
     * of this nsIMultiplexInputStream also is used as an nsISeekableStream.
     * @param stream  stream to append
     */
  /* void appendStream (in nsIInputStream stream); */
  NS_SCRIPTABLE NS_IMETHOD AppendStream(nsIInputStream *stream) = 0;

  /**
     * Insert a stream at specified index.  If the cursor of this stream is at
     * the beginning of the stream at index, the cursor will be placed at the
     * beginning of the inserted stream instead.
     * The cursor of the new stream should be located at the beginning of the
     * stream if the implementation of this nsIMultiplexInputStream also is
     * used as an nsISeekableStream.
     * @param stream  stream to insert
     * @param index   index to insert stream at, must be <= count
     */
  /* void insertStream (in nsIInputStream stream, in unsigned long index); */
  NS_SCRIPTABLE NS_IMETHOD InsertStream(nsIInputStream *stream, PRUint32 index) = 0;

  /**
     * Remove stream at specified index. If this stream is the one currently
     * being read the readcursor is moved to the beginning of the next
     * stream
     * @param index   remove stream at this index, must be < count
     */
  /* void removeStream (in unsigned long index); */
  NS_SCRIPTABLE NS_IMETHOD RemoveStream(PRUint32 index) = 0;

  /**
     * Get stream at specified index.
     * @param index   return stream at this index, must be < count
     * @return        stream at specified index
     */
  /* nsIInputStream getStream (in unsigned long index); */
  NS_SCRIPTABLE NS_IMETHOD GetStream(PRUint32 index, nsIInputStream **_retval NS_OUTPARAM) = 0;

};

  NS_DEFINE_STATIC_IID_ACCESSOR(nsIMultiplexInputStream, NS_IMULTIPLEXINPUTSTREAM_IID)

/* Use this macro when declaring classes that implement this interface. */
#define NS_DECL_NSIMULTIPLEXINPUTSTREAM \
  NS_SCRIPTABLE NS_IMETHOD GetCount(PRUint32 *aCount); \
  NS_SCRIPTABLE NS_IMETHOD AppendStream(nsIInputStream *stream); \
  NS_SCRIPTABLE NS_IMETHOD InsertStream(nsIInputStream *stream, PRUint32 index); \
  NS_SCRIPTABLE NS_IMETHOD RemoveStream(PRUint32 index); \
  NS_SCRIPTABLE NS_IMETHOD GetStream(PRUint32 index, nsIInputStream **_retval NS_OUTPARAM); 

/* Use this macro to declare functions that forward the behavior of this interface to another object. */
#define NS_FORWARD_NSIMULTIPLEXINPUTSTREAM(_to) \
  NS_SCRIPTABLE NS_IMETHOD GetCount(PRUint32 *aCount) { return _to GetCount(aCount); } \
  NS_SCRIPTABLE NS_IMETHOD AppendStream(nsIInputStream *stream) { return _to AppendStream(stream); } \
  NS_SCRIPTABLE NS_IMETHOD InsertStream(nsIInputStream *stream, PRUint32 index) { return _to InsertStream(stream, index); } \
  NS_SCRIPTABLE NS_IMETHOD RemoveStream(PRUint32 index) { return _to RemoveStream(index); } \
  NS_SCRIPTABLE NS_IMETHOD GetStream(PRUint32 index, nsIInputStream **_retval NS_OUTPARAM) { return _to GetStream(index, _retval); } 

/* Use this macro to declare functions that forward the behavior of this interface to another object in a safe way. */
#define NS_FORWARD_SAFE_NSIMULTIPLEXINPUTSTREAM(_to) \
  NS_SCRIPTABLE NS_IMETHOD GetCount(PRUint32 *aCount) { return !_to ? NS_ERROR_NULL_POINTER : _to->GetCount(aCount); } \
  NS_SCRIPTABLE NS_IMETHOD AppendStream(nsIInputStream *stream) { return !_to ? NS_ERROR_NULL_POINTER : _to->AppendStream(stream); } \
  NS_SCRIPTABLE NS_IMETHOD InsertStream(nsIInputStream *stream, PRUint32 index) { return !_to ? NS_ERROR_NULL_POINTER : _to->InsertStream(stream, index); } \
  NS_SCRIPTABLE NS_IMETHOD RemoveStream(PRUint32 index) { return !_to ? NS_ERROR_NULL_POINTER : _to->RemoveStream(index); } \
  NS_SCRIPTABLE NS_IMETHOD GetStream(PRUint32 index, nsIInputStream **_retval NS_OUTPARAM) { return !_to ? NS_ERROR_NULL_POINTER : _to->GetStream(index, _retval); } 

#if 0
/* Use the code below as a template for the implementation class for this interface. */

/* Header file */
class nsMultiplexInputStream : public nsIMultiplexInputStream
{
public:
  NS_DECL_ISUPPORTS
  NS_DECL_NSIMULTIPLEXINPUTSTREAM

  nsMultiplexInputStream();

private:
  ~nsMultiplexInputStream();

protected:
  /* additional members */
};

/* Implementation file */
NS_IMPL_ISUPPORTS1(nsMultiplexInputStream, nsIMultiplexInputStream)

nsMultiplexInputStream::nsMultiplexInputStream()
{
  /* member initializers and constructor code */
}

nsMultiplexInputStream::~nsMultiplexInputStream()
{
  /* destructor code */
}

/* readonly attribute unsigned long count; */
NS_IMETHODIMP nsMultiplexInputStream::GetCount(PRUint32 *aCount)
{
    return NS_ERROR_NOT_IMPLEMENTED;
}

/* void appendStream (in nsIInputStream stream); */
NS_IMETHODIMP nsMultiplexInputStream::AppendStream(nsIInputStream *stream)
{
    return NS_ERROR_NOT_IMPLEMENTED;
}

/* void insertStream (in nsIInputStream stream, in unsigned long index); */
NS_IMETHODIMP nsMultiplexInputStream::InsertStream(nsIInputStream *stream, PRUint32 index)
{
    return NS_ERROR_NOT_IMPLEMENTED;
}

/* void removeStream (in unsigned long index); */
NS_IMETHODIMP nsMultiplexInputStream::RemoveStream(PRUint32 index)
{
    return NS_ERROR_NOT_IMPLEMENTED;
}

/* nsIInputStream getStream (in unsigned long index); */
NS_IMETHODIMP nsMultiplexInputStream::GetStream(PRUint32 index, nsIInputStream **_retval NS_OUTPARAM)
{
    return NS_ERROR_NOT_IMPLEMENTED;
}

/* End of implementation class template. */
#endif


#endif /* __gen_nsIMultiplexInputStream_h__ */
