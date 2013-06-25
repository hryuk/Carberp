/*
 * DO NOT EDIT.  THIS FILE IS GENERATED FROM e:/builds/moz2_slave/mozilla-1.9.1-win32-xulrunner/build/netwerk/protocol/file/public/nsIFileChannel.idl
 */

#ifndef __gen_nsIFileChannel_h__
#define __gen_nsIFileChannel_h__


#ifndef __gen_nsIChannel_h__
#include "nsIChannel.h"
#endif

/* For IDL files that don't want to include root IDL files. */
#ifndef NS_NO_VTABLE
#define NS_NO_VTABLE
#endif
class nsIFile; /* forward declaration */


/* starting interface:    nsIFileChannel */
#define NS_IFILECHANNEL_IID_STR "06169120-136d-45a5-b535-498f1f755ab7"

#define NS_IFILECHANNEL_IID \
  {0x06169120, 0x136d, 0x45a5, \
    { 0xb5, 0x35, 0x49, 0x8f, 0x1f, 0x75, 0x5a, 0xb7 }}

/**
 * nsIFileChannel
 */
class NS_NO_VTABLE NS_SCRIPTABLE nsIFileChannel : public nsISupports {
 public: 

  NS_DECLARE_STATIC_IID_ACCESSOR(NS_IFILECHANNEL_IID)

  /* readonly attribute nsIFile file; */
  NS_SCRIPTABLE NS_IMETHOD GetFile(nsIFile * *aFile) = 0;

};

  NS_DEFINE_STATIC_IID_ACCESSOR(nsIFileChannel, NS_IFILECHANNEL_IID)

/* Use this macro when declaring classes that implement this interface. */
#define NS_DECL_NSIFILECHANNEL \
  NS_SCRIPTABLE NS_IMETHOD GetFile(nsIFile * *aFile); 

/* Use this macro to declare functions that forward the behavior of this interface to another object. */
#define NS_FORWARD_NSIFILECHANNEL(_to) \
  NS_SCRIPTABLE NS_IMETHOD GetFile(nsIFile * *aFile) { return _to GetFile(aFile); } 

/* Use this macro to declare functions that forward the behavior of this interface to another object in a safe way. */
#define NS_FORWARD_SAFE_NSIFILECHANNEL(_to) \
  NS_SCRIPTABLE NS_IMETHOD GetFile(nsIFile * *aFile) { return !_to ? NS_ERROR_NULL_POINTER : _to->GetFile(aFile); } 

#if 0
/* Use the code below as a template for the implementation class for this interface. */

/* Header file */
class nsFileChannel : public nsIFileChannel
{
public:
  NS_DECL_ISUPPORTS
  NS_DECL_NSIFILECHANNEL

  nsFileChannel();

private:
  ~nsFileChannel();

protected:
  /* additional members */
};

/* Implementation file */
NS_IMPL_ISUPPORTS1(nsFileChannel, nsIFileChannel)

nsFileChannel::nsFileChannel()
{
  /* member initializers and constructor code */
}

nsFileChannel::~nsFileChannel()
{
  /* destructor code */
}

/* readonly attribute nsIFile file; */
NS_IMETHODIMP nsFileChannel::GetFile(nsIFile * *aFile)
{
    return NS_ERROR_NOT_IMPLEMENTED;
}

/* End of implementation class template. */
#endif


#endif /* __gen_nsIFileChannel_h__ */
