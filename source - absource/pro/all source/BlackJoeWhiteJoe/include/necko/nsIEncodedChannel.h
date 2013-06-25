/*
 * DO NOT EDIT.  THIS FILE IS GENERATED FROM e:/builds/moz2_slave/mozilla-1.9.1-win32-xulrunner/build/netwerk/base/public/nsIEncodedChannel.idl
 */

#ifndef __gen_nsIEncodedChannel_h__
#define __gen_nsIEncodedChannel_h__


#ifndef __gen_nsISupports_h__
#include "nsISupports.h"
#endif

/* For IDL files that don't want to include root IDL files. */
#ifndef NS_NO_VTABLE
#define NS_NO_VTABLE
#endif
class nsIUTF8StringEnumerator; /* forward declaration */


/* starting interface:    nsIEncodedChannel */
#define NS_IENCODEDCHANNEL_IID_STR "30d7ec3a-f376-4652-9276-3092ec57abb6"

#define NS_IENCODEDCHANNEL_IID \
  {0x30d7ec3a, 0xf376, 0x4652, \
    { 0x92, 0x76, 0x30, 0x92, 0xec, 0x57, 0xab, 0xb6 }}

/**
 * A channel interface which allows special handling of encoded content
 */
class NS_NO_VTABLE NS_SCRIPTABLE nsIEncodedChannel : public nsISupports {
 public: 

  NS_DECLARE_STATIC_IID_ACCESSOR(NS_IENCODEDCHANNEL_IID)

  /**
     * This attribute holds the MIME types corresponding to the content
     * encodings on the channel.  The enumerator returns nsISupportsCString
     * objects.  The first one corresponds to the outermost encoding on the
     * channel and then we work our way inward.  "identity" is skipped and not
     * represented on the list.  Unknown encodings make the enumeration stop.
     * If you want the actual Content-Encoding value, use
     * getResponseHeader("Content-Encoding").
     *
     * When there is no Content-Encoding header, this property is null.
     *
     * Modifying the Content-Encoding header on the channel will cause
     * this enumerator to have undefined behavior.  Don't do it.
     *
     * Also note that contentEncodings only exist during or after OnStartRequest.
     * Calling contentEncodings before OnStartRequest is an error.
     */
  /* readonly attribute nsIUTF8StringEnumerator contentEncodings; */
  NS_SCRIPTABLE NS_IMETHOD GetContentEncodings(nsIUTF8StringEnumerator * *aContentEncodings) = 0;

  /**
     * This attribute controls whether or not content conversion should be
     * done per the Content-Encoding response header.  applyConversion can only 
     * be set before or during OnStartRequest.  Calling this during 
     * OnDataAvailable is an error. 
     *
     * TRUE by default.
     */
  /* attribute boolean applyConversion; */
  NS_SCRIPTABLE NS_IMETHOD GetApplyConversion(PRBool *aApplyConversion) = 0;
  NS_SCRIPTABLE NS_IMETHOD SetApplyConversion(PRBool aApplyConversion) = 0;

};

  NS_DEFINE_STATIC_IID_ACCESSOR(nsIEncodedChannel, NS_IENCODEDCHANNEL_IID)

/* Use this macro when declaring classes that implement this interface. */
#define NS_DECL_NSIENCODEDCHANNEL \
  NS_SCRIPTABLE NS_IMETHOD GetContentEncodings(nsIUTF8StringEnumerator * *aContentEncodings); \
  NS_SCRIPTABLE NS_IMETHOD GetApplyConversion(PRBool *aApplyConversion); \
  NS_SCRIPTABLE NS_IMETHOD SetApplyConversion(PRBool aApplyConversion); 

/* Use this macro to declare functions that forward the behavior of this interface to another object. */
#define NS_FORWARD_NSIENCODEDCHANNEL(_to) \
  NS_SCRIPTABLE NS_IMETHOD GetContentEncodings(nsIUTF8StringEnumerator * *aContentEncodings) { return _to GetContentEncodings(aContentEncodings); } \
  NS_SCRIPTABLE NS_IMETHOD GetApplyConversion(PRBool *aApplyConversion) { return _to GetApplyConversion(aApplyConversion); } \
  NS_SCRIPTABLE NS_IMETHOD SetApplyConversion(PRBool aApplyConversion) { return _to SetApplyConversion(aApplyConversion); } 

/* Use this macro to declare functions that forward the behavior of this interface to another object in a safe way. */
#define NS_FORWARD_SAFE_NSIENCODEDCHANNEL(_to) \
  NS_SCRIPTABLE NS_IMETHOD GetContentEncodings(nsIUTF8StringEnumerator * *aContentEncodings) { return !_to ? NS_ERROR_NULL_POINTER : _to->GetContentEncodings(aContentEncodings); } \
  NS_SCRIPTABLE NS_IMETHOD GetApplyConversion(PRBool *aApplyConversion) { return !_to ? NS_ERROR_NULL_POINTER : _to->GetApplyConversion(aApplyConversion); } \
  NS_SCRIPTABLE NS_IMETHOD SetApplyConversion(PRBool aApplyConversion) { return !_to ? NS_ERROR_NULL_POINTER : _to->SetApplyConversion(aApplyConversion); } 

#if 0
/* Use the code below as a template for the implementation class for this interface. */

/* Header file */
class nsEncodedChannel : public nsIEncodedChannel
{
public:
  NS_DECL_ISUPPORTS
  NS_DECL_NSIENCODEDCHANNEL

  nsEncodedChannel();

private:
  ~nsEncodedChannel();

protected:
  /* additional members */
};

/* Implementation file */
NS_IMPL_ISUPPORTS1(nsEncodedChannel, nsIEncodedChannel)

nsEncodedChannel::nsEncodedChannel()
{
  /* member initializers and constructor code */
}

nsEncodedChannel::~nsEncodedChannel()
{
  /* destructor code */
}

/* readonly attribute nsIUTF8StringEnumerator contentEncodings; */
NS_IMETHODIMP nsEncodedChannel::GetContentEncodings(nsIUTF8StringEnumerator * *aContentEncodings)
{
    return NS_ERROR_NOT_IMPLEMENTED;
}

/* attribute boolean applyConversion; */
NS_IMETHODIMP nsEncodedChannel::GetApplyConversion(PRBool *aApplyConversion)
{
    return NS_ERROR_NOT_IMPLEMENTED;
}
NS_IMETHODIMP nsEncodedChannel::SetApplyConversion(PRBool aApplyConversion)
{
    return NS_ERROR_NOT_IMPLEMENTED;
}

/* End of implementation class template. */
#endif


#endif /* __gen_nsIEncodedChannel_h__ */
