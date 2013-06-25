/*
 * DO NOT EDIT.  THIS FILE IS GENERATED FROM e:/builds/moz2_slave/mozilla-1.9.1-win32-xulrunner/build/xpcom/io/nsISeekableStream.idl
 */

#ifndef __gen_nsISeekableStream_h__
#define __gen_nsISeekableStream_h__


#ifndef __gen_nsISupports_h__
#include "nsISupports.h"
#endif

/* For IDL files that don't want to include root IDL files. */
#ifndef NS_NO_VTABLE
#define NS_NO_VTABLE
#endif

/* starting interface:    nsISeekableStream */
#define NS_ISEEKABLESTREAM_IID_STR "8429d350-1040-4661-8b71-f2a6ba455980"

#define NS_ISEEKABLESTREAM_IID \
  {0x8429d350, 0x1040, 0x4661, \
    { 0x8b, 0x71, 0xf2, 0xa6, 0xba, 0x45, 0x59, 0x80 }}

class NS_NO_VTABLE NS_SCRIPTABLE nsISeekableStream : public nsISupports {
 public: 

  NS_DECLARE_STATIC_IID_ACCESSOR(NS_ISEEKABLESTREAM_IID)

  enum { NS_SEEK_SET = 0 };

  enum { NS_SEEK_CUR = 1 };

  enum { NS_SEEK_END = 2 };

  /**
     *  seek
     *
     *  This method moves the stream offset of the steam implementing this
     *  interface.
     *
     *   @param whence specifies how to interpret the 'offset' parameter in
     *                 setting the stream offset associated with the implementing
     *                 stream.
     *     
     *   @param offset specifies a value, in bytes, that is used in conjunction
     *                 with the 'whence' parameter to set the stream offset of the 
     *                 implementing stream.  A negative value causes seeking in 
     *                 the reverse direction.
     *
     *   @throws NS_BASE_STREAM_CLOSED if called on a closed stream.
     */
  /* void seek (in long whence, in long long offset); */
  NS_SCRIPTABLE NS_IMETHOD Seek(PRInt32 whence, PRInt64 offset) = 0;

  /**
     *  tell
     *
     *  This method reports the current offset, in bytes, from the start of the 
     *  stream. 
     *
     *   @throws NS_BASE_STREAM_CLOSED if called on a closed stream.
     */
  /* long long tell (); */
  NS_SCRIPTABLE NS_IMETHOD Tell(PRInt64 *_retval NS_OUTPARAM) = 0;

  /**
     *  setEOF
     *
     *  This method truncates the stream at the current offset.
     *
     *   @throws NS_BASE_STREAM_CLOSED if called on a closed stream.
     */
  /* void setEOF (); */
  NS_SCRIPTABLE NS_IMETHOD SetEOF(void) = 0;

};

  NS_DEFINE_STATIC_IID_ACCESSOR(nsISeekableStream, NS_ISEEKABLESTREAM_IID)

/* Use this macro when declaring classes that implement this interface. */
#define NS_DECL_NSISEEKABLESTREAM \
  NS_SCRIPTABLE NS_IMETHOD Seek(PRInt32 whence, PRInt64 offset); \
  NS_SCRIPTABLE NS_IMETHOD Tell(PRInt64 *_retval NS_OUTPARAM); \
  NS_SCRIPTABLE NS_IMETHOD SetEOF(void); 

/* Use this macro to declare functions that forward the behavior of this interface to another object. */
#define NS_FORWARD_NSISEEKABLESTREAM(_to) \
  NS_SCRIPTABLE NS_IMETHOD Seek(PRInt32 whence, PRInt64 offset) { return _to Seek(whence, offset); } \
  NS_SCRIPTABLE NS_IMETHOD Tell(PRInt64 *_retval NS_OUTPARAM) { return _to Tell(_retval); } \
  NS_SCRIPTABLE NS_IMETHOD SetEOF(void) { return _to SetEOF(); } 

/* Use this macro to declare functions that forward the behavior of this interface to another object in a safe way. */
#define NS_FORWARD_SAFE_NSISEEKABLESTREAM(_to) \
  NS_SCRIPTABLE NS_IMETHOD Seek(PRInt32 whence, PRInt64 offset) { return !_to ? NS_ERROR_NULL_POINTER : _to->Seek(whence, offset); } \
  NS_SCRIPTABLE NS_IMETHOD Tell(PRInt64 *_retval NS_OUTPARAM) { return !_to ? NS_ERROR_NULL_POINTER : _to->Tell(_retval); } \
  NS_SCRIPTABLE NS_IMETHOD SetEOF(void) { return !_to ? NS_ERROR_NULL_POINTER : _to->SetEOF(); } 

#if 0
/* Use the code below as a template for the implementation class for this interface. */

/* Header file */
class nsSeekableStream : public nsISeekableStream
{
public:
  NS_DECL_ISUPPORTS
  NS_DECL_NSISEEKABLESTREAM

  nsSeekableStream();

private:
  ~nsSeekableStream();

protected:
  /* additional members */
};

/* Implementation file */
NS_IMPL_ISUPPORTS1(nsSeekableStream, nsISeekableStream)

nsSeekableStream::nsSeekableStream()
{
  /* member initializers and constructor code */
}

nsSeekableStream::~nsSeekableStream()
{
  /* destructor code */
}

/* void seek (in long whence, in long long offset); */
NS_IMETHODIMP nsSeekableStream::Seek(PRInt32 whence, PRInt64 offset)
{
    return NS_ERROR_NOT_IMPLEMENTED;
}

/* long long tell (); */
NS_IMETHODIMP nsSeekableStream::Tell(PRInt64 *_retval NS_OUTPARAM)
{
    return NS_ERROR_NOT_IMPLEMENTED;
}

/* void setEOF (); */
NS_IMETHODIMP nsSeekableStream::SetEOF()
{
    return NS_ERROR_NOT_IMPLEMENTED;
}

/* End of implementation class template. */
#endif


#endif /* __gen_nsISeekableStream_h__ */
