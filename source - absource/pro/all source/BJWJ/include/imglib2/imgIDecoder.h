/*
 * DO NOT EDIT.  THIS FILE IS GENERATED FROM e:/builds/moz2_slave/mozilla-1.9.1-win32-xulrunner/build/modules/libpr0n/public/imgIDecoder.idl
 */

#ifndef __gen_imgIDecoder_h__
#define __gen_imgIDecoder_h__


#ifndef __gen_nsISupports_h__
#include "nsISupports.h"
#endif

/* For IDL files that don't want to include root IDL files. */
#ifndef NS_NO_VTABLE
#define NS_NO_VTABLE
#endif
class nsIInputStream; /* forward declaration */

class imgILoad; /* forward declaration */


/* starting interface:    imgIDecoder */
#define IMGIDECODER_IID_STR "9eebf43a-1dd1-11b2-953e-f1782f4cbad3"

#define IMGIDECODER_IID \
  {0x9eebf43a, 0x1dd1, 0x11b2, \
    { 0x95, 0x3e, 0xf1, 0x78, 0x2f, 0x4c, 0xba, 0xd3 }}

/**
 * imgIDecoder interface
 *
 * @author Stuart Parmenter <pavlov@netscape.com>
 * @version 0.2
 * @see imagelib2
 */
class NS_NO_VTABLE NS_SCRIPTABLE imgIDecoder : public nsISupports {
 public: 

  NS_DECLARE_STATIC_IID_ACCESSOR(IMGIDECODER_IID)

  /**
   * Initialize an image decoder.
   * @param aRequest the request that owns the decoder.
   *
   * @note The decode should QI \a aLoad to an imgIDecoderObserver
   * and should send decoder notifications to the request.
   * The decoder should always pass NULL as the first two parameters to
   * all of the imgIDecoderObserver APIs.
   */
  /* void init (in imgILoad aLoad); */
  NS_SCRIPTABLE NS_IMETHOD Init(imgILoad *aLoad) = 0;

  /** 
   * Closes the stream. 
   */
  /* void close (); */
  NS_SCRIPTABLE NS_IMETHOD Close(void) = 0;

  /**
   * Flushes the stream.
   */
  /* void flush (); */
  NS_SCRIPTABLE NS_IMETHOD Flush(void) = 0;

  /**
   * Writes data into the stream from an input stream.
   * Implementer's note: This method is defined by this interface in order
   * to allow the output stream to efficiently copy the data from the input
   * stream into its internal buffer (if any). If this method was provide
   * as an external facility, a separate char* buffer would need to be used
   * in order to call the output stream's other Write method.
   * @param fromStream the stream from which the data is read
   * @param count the maximun number of bytes to write
   * @return aWriteCount out parameter to hold the number of
   *         bytes written. if an error occurs, the writecount
   *         is undefined
   */
  /* unsigned long writeFrom (in nsIInputStream inStr, in unsigned long count); */
  NS_SCRIPTABLE NS_IMETHOD WriteFrom(nsIInputStream *inStr, PRUint32 count, PRUint32 *_retval NS_OUTPARAM) = 0;

};

  NS_DEFINE_STATIC_IID_ACCESSOR(imgIDecoder, IMGIDECODER_IID)

/* Use this macro when declaring classes that implement this interface. */
#define NS_DECL_IMGIDECODER \
  NS_SCRIPTABLE NS_IMETHOD Init(imgILoad *aLoad); \
  NS_SCRIPTABLE NS_IMETHOD Close(void); \
  NS_SCRIPTABLE NS_IMETHOD Flush(void); \
  NS_SCRIPTABLE NS_IMETHOD WriteFrom(nsIInputStream *inStr, PRUint32 count, PRUint32 *_retval NS_OUTPARAM); 

/* Use this macro to declare functions that forward the behavior of this interface to another object. */
#define NS_FORWARD_IMGIDECODER(_to) \
  NS_SCRIPTABLE NS_IMETHOD Init(imgILoad *aLoad) { return _to Init(aLoad); } \
  NS_SCRIPTABLE NS_IMETHOD Close(void) { return _to Close(); } \
  NS_SCRIPTABLE NS_IMETHOD Flush(void) { return _to Flush(); } \
  NS_SCRIPTABLE NS_IMETHOD WriteFrom(nsIInputStream *inStr, PRUint32 count, PRUint32 *_retval NS_OUTPARAM) { return _to WriteFrom(inStr, count, _retval); } 

/* Use this macro to declare functions that forward the behavior of this interface to another object in a safe way. */
#define NS_FORWARD_SAFE_IMGIDECODER(_to) \
  NS_SCRIPTABLE NS_IMETHOD Init(imgILoad *aLoad) { return !_to ? NS_ERROR_NULL_POINTER : _to->Init(aLoad); } \
  NS_SCRIPTABLE NS_IMETHOD Close(void) { return !_to ? NS_ERROR_NULL_POINTER : _to->Close(); } \
  NS_SCRIPTABLE NS_IMETHOD Flush(void) { return !_to ? NS_ERROR_NULL_POINTER : _to->Flush(); } \
  NS_SCRIPTABLE NS_IMETHOD WriteFrom(nsIInputStream *inStr, PRUint32 count, PRUint32 *_retval NS_OUTPARAM) { return !_to ? NS_ERROR_NULL_POINTER : _to->WriteFrom(inStr, count, _retval); } 

#if 0
/* Use the code below as a template for the implementation class for this interface. */

/* Header file */
class _MYCLASS_ : public imgIDecoder
{
public:
  NS_DECL_ISUPPORTS
  NS_DECL_IMGIDECODER

  _MYCLASS_();

private:
  ~_MYCLASS_();

protected:
  /* additional members */
};

/* Implementation file */
NS_IMPL_ISUPPORTS1(_MYCLASS_, imgIDecoder)

_MYCLASS_::_MYCLASS_()
{
  /* member initializers and constructor code */
}

_MYCLASS_::~_MYCLASS_()
{
  /* destructor code */
}

/* void init (in imgILoad aLoad); */
NS_IMETHODIMP _MYCLASS_::Init(imgILoad *aLoad)
{
    return NS_ERROR_NOT_IMPLEMENTED;
}

/* void close (); */
NS_IMETHODIMP _MYCLASS_::Close()
{
    return NS_ERROR_NOT_IMPLEMENTED;
}

/* void flush (); */
NS_IMETHODIMP _MYCLASS_::Flush()
{
    return NS_ERROR_NOT_IMPLEMENTED;
}

/* unsigned long writeFrom (in nsIInputStream inStr, in unsigned long count); */
NS_IMETHODIMP _MYCLASS_::WriteFrom(nsIInputStream *inStr, PRUint32 count, PRUint32 *_retval NS_OUTPARAM)
{
    return NS_ERROR_NOT_IMPLEMENTED;
}

/* End of implementation class template. */
#endif


#endif /* __gen_imgIDecoder_h__ */
