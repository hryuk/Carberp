/*
 * DO NOT EDIT.  THIS FILE IS GENERATED FROM e:/builds/moz2_slave/mozilla-1.9.1-win32-xulrunner/build/netwerk/base/public/nsIMultiPartChannel.idl
 */

#ifndef __gen_nsIMultiPartChannel_h__
#define __gen_nsIMultiPartChannel_h__


#ifndef __gen_nsISupports_h__
#include "nsISupports.h"
#endif

/* For IDL files that don't want to include root IDL files. */
#ifndef NS_NO_VTABLE
#define NS_NO_VTABLE
#endif
class nsIChannel; /* forward declaration */


/* starting interface:    nsIMultiPartChannel */
#define NS_IMULTIPARTCHANNEL_IID_STR "ba78db7b-b88c-4b76-baf9-3c2296a585ae"

#define NS_IMULTIPARTCHANNEL_IID \
  {0xba78db7b, 0xb88c, 0x4b76, \
    { 0xba, 0xf9, 0x3c, 0x22, 0x96, 0xa5, 0x85, 0xae }}

/**
 * An interface to access the the base channel 
 * associated with a MultiPartChannel.
 */
class NS_NO_VTABLE NS_SCRIPTABLE nsIMultiPartChannel : public nsISupports {
 public: 

  NS_DECLARE_STATIC_IID_ACCESSOR(NS_IMULTIPARTCHANNEL_IID)

  /**
     * readonly attribute to access the underlying channel
     */
  /* readonly attribute nsIChannel baseChannel; */
  NS_SCRIPTABLE NS_IMETHOD GetBaseChannel(nsIChannel * *aBaseChannel) = 0;

  /**
     * Access to the Content-Disposition header field of this part of
     * a multipart message.  This allows getting the preferred
     * handling method, preferred filename, etc.  See RFC 2183.
     */
  /* attribute ACString contentDisposition; */
  NS_SCRIPTABLE NS_IMETHOD GetContentDisposition(nsACString & aContentDisposition) = 0;
  NS_SCRIPTABLE NS_IMETHOD SetContentDisposition(const nsACString & aContentDisposition) = 0;

  /**
     * Attribute guaranteed to be different for different parts of
     * the same multipart document.
     */
  /* readonly attribute PRUint32 partID; */
  NS_SCRIPTABLE NS_IMETHOD GetPartID(PRUint32 *aPartID) = 0;

  /**
     * Set to true when onStopRequest is received from the base channel.
     * The listener can check this from its onStopRequest to determine
     * whether more data can be expected.
     */
  /* readonly attribute boolean isLastPart; */
  NS_SCRIPTABLE NS_IMETHOD GetIsLastPart(PRBool *aIsLastPart) = 0;

};

  NS_DEFINE_STATIC_IID_ACCESSOR(nsIMultiPartChannel, NS_IMULTIPARTCHANNEL_IID)

/* Use this macro when declaring classes that implement this interface. */
#define NS_DECL_NSIMULTIPARTCHANNEL \
  NS_SCRIPTABLE NS_IMETHOD GetBaseChannel(nsIChannel * *aBaseChannel); \
  NS_SCRIPTABLE NS_IMETHOD GetContentDisposition(nsACString & aContentDisposition); \
  NS_SCRIPTABLE NS_IMETHOD SetContentDisposition(const nsACString & aContentDisposition); \
  NS_SCRIPTABLE NS_IMETHOD GetPartID(PRUint32 *aPartID); \
  NS_SCRIPTABLE NS_IMETHOD GetIsLastPart(PRBool *aIsLastPart); 

/* Use this macro to declare functions that forward the behavior of this interface to another object. */
#define NS_FORWARD_NSIMULTIPARTCHANNEL(_to) \
  NS_SCRIPTABLE NS_IMETHOD GetBaseChannel(nsIChannel * *aBaseChannel) { return _to GetBaseChannel(aBaseChannel); } \
  NS_SCRIPTABLE NS_IMETHOD GetContentDisposition(nsACString & aContentDisposition) { return _to GetContentDisposition(aContentDisposition); } \
  NS_SCRIPTABLE NS_IMETHOD SetContentDisposition(const nsACString & aContentDisposition) { return _to SetContentDisposition(aContentDisposition); } \
  NS_SCRIPTABLE NS_IMETHOD GetPartID(PRUint32 *aPartID) { return _to GetPartID(aPartID); } \
  NS_SCRIPTABLE NS_IMETHOD GetIsLastPart(PRBool *aIsLastPart) { return _to GetIsLastPart(aIsLastPart); } 

/* Use this macro to declare functions that forward the behavior of this interface to another object in a safe way. */
#define NS_FORWARD_SAFE_NSIMULTIPARTCHANNEL(_to) \
  NS_SCRIPTABLE NS_IMETHOD GetBaseChannel(nsIChannel * *aBaseChannel) { return !_to ? NS_ERROR_NULL_POINTER : _to->GetBaseChannel(aBaseChannel); } \
  NS_SCRIPTABLE NS_IMETHOD GetContentDisposition(nsACString & aContentDisposition) { return !_to ? NS_ERROR_NULL_POINTER : _to->GetContentDisposition(aContentDisposition); } \
  NS_SCRIPTABLE NS_IMETHOD SetContentDisposition(const nsACString & aContentDisposition) { return !_to ? NS_ERROR_NULL_POINTER : _to->SetContentDisposition(aContentDisposition); } \
  NS_SCRIPTABLE NS_IMETHOD GetPartID(PRUint32 *aPartID) { return !_to ? NS_ERROR_NULL_POINTER : _to->GetPartID(aPartID); } \
  NS_SCRIPTABLE NS_IMETHOD GetIsLastPart(PRBool *aIsLastPart) { return !_to ? NS_ERROR_NULL_POINTER : _to->GetIsLastPart(aIsLastPart); } 

#if 0
/* Use the code below as a template for the implementation class for this interface. */

/* Header file */
class nsMultiPartChannel : public nsIMultiPartChannel
{
public:
  NS_DECL_ISUPPORTS
  NS_DECL_NSIMULTIPARTCHANNEL

  nsMultiPartChannel();

private:
  ~nsMultiPartChannel();

protected:
  /* additional members */
};

/* Implementation file */
NS_IMPL_ISUPPORTS1(nsMultiPartChannel, nsIMultiPartChannel)

nsMultiPartChannel::nsMultiPartChannel()
{
  /* member initializers and constructor code */
}

nsMultiPartChannel::~nsMultiPartChannel()
{
  /* destructor code */
}

/* readonly attribute nsIChannel baseChannel; */
NS_IMETHODIMP nsMultiPartChannel::GetBaseChannel(nsIChannel * *aBaseChannel)
{
    return NS_ERROR_NOT_IMPLEMENTED;
}

/* attribute ACString contentDisposition; */
NS_IMETHODIMP nsMultiPartChannel::GetContentDisposition(nsACString & aContentDisposition)
{
    return NS_ERROR_NOT_IMPLEMENTED;
}
NS_IMETHODIMP nsMultiPartChannel::SetContentDisposition(const nsACString & aContentDisposition)
{
    return NS_ERROR_NOT_IMPLEMENTED;
}

/* readonly attribute PRUint32 partID; */
NS_IMETHODIMP nsMultiPartChannel::GetPartID(PRUint32 *aPartID)
{
    return NS_ERROR_NOT_IMPLEMENTED;
}

/* readonly attribute boolean isLastPart; */
NS_IMETHODIMP nsMultiPartChannel::GetIsLastPart(PRBool *aIsLastPart)
{
    return NS_ERROR_NOT_IMPLEMENTED;
}

/* End of implementation class template. */
#endif


#endif /* __gen_nsIMultiPartChannel_h__ */
