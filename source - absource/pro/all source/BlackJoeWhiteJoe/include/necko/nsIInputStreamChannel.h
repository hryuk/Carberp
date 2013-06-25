/*
 * DO NOT EDIT.  THIS FILE IS GENERATED FROM e:/builds/moz2_slave/mozilla-1.9.1-win32-xulrunner/build/netwerk/base/public/nsIInputStreamChannel.idl
 */

#ifndef __gen_nsIInputStreamChannel_h__
#define __gen_nsIInputStreamChannel_h__


#ifndef __gen_nsIChannel_h__
#include "nsIChannel.h"
#endif

/* For IDL files that don't want to include root IDL files. */
#ifndef NS_NO_VTABLE
#define NS_NO_VTABLE
#endif
class nsIInputStream; /* forward declaration */


/* starting interface:    nsIInputStreamChannel */
#define NS_IINPUTSTREAMCHANNEL_IID_STR "274c4d7a-2447-4ceb-a6de-80db1b83f5d2"

#define NS_IINPUTSTREAMCHANNEL_IID \
  {0x274c4d7a, 0x2447, 0x4ceb, \
    { 0xa6, 0xde, 0x80, 0xdb, 0x1b, 0x83, 0xf5, 0xd2 }}

/**
 * nsIInputStreamChannel
 *
 * This interface provides methods to initialize an input stream channel.
 * The input stream channel serves as a data pump for an input stream.
 */
class NS_NO_VTABLE NS_SCRIPTABLE nsIInputStreamChannel : public nsISupports {
 public: 

  NS_DECLARE_STATIC_IID_ACCESSOR(NS_IINPUTSTREAMCHANNEL_IID)

  /**
     * Sets the URI for this channel.  This must be called before the
     * channel is opened, and it may only be called once.
     */
  /* void setURI (in nsIURI aURI); */
  NS_SCRIPTABLE NS_IMETHOD SetURI(nsIURI *aURI) = 0;

  /**
     * Get/set the content stream
     *
     * This stream contains the data that will be pushed to the channel's
     * stream listener.  If the stream is non-blocking and supports the
     * nsIAsyncInputStream interface, then the stream will be read directly.
     * Otherwise, the stream will be read on a background thread.
     *
     * This attribute must be set before the channel is opened, and it may
     * only be set once.
     *
     * @throws NS_ERROR_IN_PROGRESS if the setter is called after the channel
     * has been opened.
     */
  /* attribute nsIInputStream contentStream; */
  NS_SCRIPTABLE NS_IMETHOD GetContentStream(nsIInputStream * *aContentStream) = 0;
  NS_SCRIPTABLE NS_IMETHOD SetContentStream(nsIInputStream * aContentStream) = 0;

};

  NS_DEFINE_STATIC_IID_ACCESSOR(nsIInputStreamChannel, NS_IINPUTSTREAMCHANNEL_IID)

/* Use this macro when declaring classes that implement this interface. */
#define NS_DECL_NSIINPUTSTREAMCHANNEL \
  NS_SCRIPTABLE NS_IMETHOD SetURI(nsIURI *aURI); \
  NS_SCRIPTABLE NS_IMETHOD GetContentStream(nsIInputStream * *aContentStream); \
  NS_SCRIPTABLE NS_IMETHOD SetContentStream(nsIInputStream * aContentStream); 

/* Use this macro to declare functions that forward the behavior of this interface to another object. */
#define NS_FORWARD_NSIINPUTSTREAMCHANNEL(_to) \
  NS_SCRIPTABLE NS_IMETHOD SetURI(nsIURI *aURI) { return _to SetURI(aURI); } \
  NS_SCRIPTABLE NS_IMETHOD GetContentStream(nsIInputStream * *aContentStream) { return _to GetContentStream(aContentStream); } \
  NS_SCRIPTABLE NS_IMETHOD SetContentStream(nsIInputStream * aContentStream) { return _to SetContentStream(aContentStream); } 

/* Use this macro to declare functions that forward the behavior of this interface to another object in a safe way. */
#define NS_FORWARD_SAFE_NSIINPUTSTREAMCHANNEL(_to) \
  NS_SCRIPTABLE NS_IMETHOD SetURI(nsIURI *aURI) { return !_to ? NS_ERROR_NULL_POINTER : _to->SetURI(aURI); } \
  NS_SCRIPTABLE NS_IMETHOD GetContentStream(nsIInputStream * *aContentStream) { return !_to ? NS_ERROR_NULL_POINTER : _to->GetContentStream(aContentStream); } \
  NS_SCRIPTABLE NS_IMETHOD SetContentStream(nsIInputStream * aContentStream) { return !_to ? NS_ERROR_NULL_POINTER : _to->SetContentStream(aContentStream); } 

#if 0
/* Use the code below as a template for the implementation class for this interface. */

/* Header file */
class nsInputStreamChannel : public nsIInputStreamChannel
{
public:
  NS_DECL_ISUPPORTS
  NS_DECL_NSIINPUTSTREAMCHANNEL

  nsInputStreamChannel();

private:
  ~nsInputStreamChannel();

protected:
  /* additional members */
};

/* Implementation file */
NS_IMPL_ISUPPORTS1(nsInputStreamChannel, nsIInputStreamChannel)

nsInputStreamChannel::nsInputStreamChannel()
{
  /* member initializers and constructor code */
}

nsInputStreamChannel::~nsInputStreamChannel()
{
  /* destructor code */
}

/* void setURI (in nsIURI aURI); */
NS_IMETHODIMP nsInputStreamChannel::SetURI(nsIURI *aURI)
{
    return NS_ERROR_NOT_IMPLEMENTED;
}

/* attribute nsIInputStream contentStream; */
NS_IMETHODIMP nsInputStreamChannel::GetContentStream(nsIInputStream * *aContentStream)
{
    return NS_ERROR_NOT_IMPLEMENTED;
}
NS_IMETHODIMP nsInputStreamChannel::SetContentStream(nsIInputStream * aContentStream)
{
    return NS_ERROR_NOT_IMPLEMENTED;
}

/* End of implementation class template. */
#endif


#endif /* __gen_nsIInputStreamChannel_h__ */
