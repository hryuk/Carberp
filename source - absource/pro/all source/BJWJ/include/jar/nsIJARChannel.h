/*
 * DO NOT EDIT.  THIS FILE IS GENERATED FROM e:/builds/moz2_slave/mozilla-1.9.1-win32-xulrunner/build/modules/libjar/nsIJARChannel.idl
 */

#ifndef __gen_nsIJARChannel_h__
#define __gen_nsIJARChannel_h__


#ifndef __gen_nsIChannel_h__
#include "nsIChannel.h"
#endif

/* For IDL files that don't want to include root IDL files. */
#ifndef NS_NO_VTABLE
#define NS_NO_VTABLE
#endif

/* starting interface:    nsIJARChannel */
#define NS_IJARCHANNEL_IID_STR "6e6cc56d-51eb-4299-a795-dcfd1229ab3d"

#define NS_IJARCHANNEL_IID \
  {0x6e6cc56d, 0x51eb, 0x4299, \
    { 0xa7, 0x95, 0xdc, 0xfd, 0x12, 0x29, 0xab, 0x3d }}

class NS_NO_VTABLE NS_SCRIPTABLE nsIJARChannel : public nsIChannel {
 public: 

  NS_DECLARE_STATIC_IID_ACCESSOR(NS_IJARCHANNEL_IID)

  /**
     * Returns TRUE if the JAR file is not safe (if the content type reported
     * by the server for a remote JAR is not of an expected type).  Scripting,
     * redirects, and plugins should be disabled when loading from this
     * channel.
     */
  /* readonly attribute boolean isUnsafe; */
  NS_SCRIPTABLE NS_IMETHOD GetIsUnsafe(PRBool *aIsUnsafe) = 0;

};

  NS_DEFINE_STATIC_IID_ACCESSOR(nsIJARChannel, NS_IJARCHANNEL_IID)

/* Use this macro when declaring classes that implement this interface. */
#define NS_DECL_NSIJARCHANNEL \
  NS_SCRIPTABLE NS_IMETHOD GetIsUnsafe(PRBool *aIsUnsafe); 

/* Use this macro to declare functions that forward the behavior of this interface to another object. */
#define NS_FORWARD_NSIJARCHANNEL(_to) \
  NS_SCRIPTABLE NS_IMETHOD GetIsUnsafe(PRBool *aIsUnsafe) { return _to GetIsUnsafe(aIsUnsafe); } 

/* Use this macro to declare functions that forward the behavior of this interface to another object in a safe way. */
#define NS_FORWARD_SAFE_NSIJARCHANNEL(_to) \
  NS_SCRIPTABLE NS_IMETHOD GetIsUnsafe(PRBool *aIsUnsafe) { return !_to ? NS_ERROR_NULL_POINTER : _to->GetIsUnsafe(aIsUnsafe); } 

#if 0
/* Use the code below as a template for the implementation class for this interface. */

/* Header file */
class nsJARChannel : public nsIJARChannel
{
public:
  NS_DECL_ISUPPORTS
  NS_DECL_NSIJARCHANNEL

  nsJARChannel();

private:
  ~nsJARChannel();

protected:
  /* additional members */
};

/* Implementation file */
NS_IMPL_ISUPPORTS1(nsJARChannel, nsIJARChannel)

nsJARChannel::nsJARChannel()
{
  /* member initializers and constructor code */
}

nsJARChannel::~nsJARChannel()
{
  /* destructor code */
}

/* readonly attribute boolean isUnsafe; */
NS_IMETHODIMP nsJARChannel::GetIsUnsafe(PRBool *aIsUnsafe)
{
    return NS_ERROR_NOT_IMPLEMENTED;
}

/* End of implementation class template. */
#endif


#endif /* __gen_nsIJARChannel_h__ */
