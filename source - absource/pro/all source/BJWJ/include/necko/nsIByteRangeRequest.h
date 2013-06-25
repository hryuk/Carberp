/*
 * DO NOT EDIT.  THIS FILE IS GENERATED FROM e:/builds/moz2_slave/mozilla-1.9.1-win32-xulrunner/build/netwerk/base/public/nsIByteRangeRequest.idl
 */

#ifndef __gen_nsIByteRangeRequest_h__
#define __gen_nsIByteRangeRequest_h__


#ifndef __gen_nsISupports_h__
#include "nsISupports.h"
#endif

/* For IDL files that don't want to include root IDL files. */
#ifndef NS_NO_VTABLE
#define NS_NO_VTABLE
#endif

/* starting interface:    nsIByteRangeRequest */
#define NS_IBYTERANGEREQUEST_IID_STR "c1b1f426-7e83-4759-9f88-0e1b17f49366"

#define NS_IBYTERANGEREQUEST_IID \
  {0xc1b1f426, 0x7e83, 0x4759, \
    { 0x9f, 0x88, 0x0e, 0x1b, 0x17, 0xf4, 0x93, 0x66 }}

class NS_NO_VTABLE NS_SCRIPTABLE nsIByteRangeRequest : public nsISupports {
 public: 

  NS_DECLARE_STATIC_IID_ACCESSOR(NS_IBYTERANGEREQUEST_IID)

  /** 
     * Returns true IFF this request is a byte range request, otherwise it
     * returns false (This is effectively the same as checking to see if 
     * |startRequest| is zero and |endRange| is the content length.)
     */
  /* readonly attribute boolean isByteRangeRequest; */
  NS_SCRIPTABLE NS_IMETHOD GetIsByteRangeRequest(PRBool *aIsByteRangeRequest) = 0;

  /** 
     * Absolute start position in remote file for this request.
     */
  /* readonly attribute long long startRange; */
  NS_SCRIPTABLE NS_IMETHOD GetStartRange(PRInt64 *aStartRange) = 0;

  /**
     * Absolute end postion in remote file for this request
     */
  /* readonly attribute long long endRange; */
  NS_SCRIPTABLE NS_IMETHOD GetEndRange(PRInt64 *aEndRange) = 0;

};

  NS_DEFINE_STATIC_IID_ACCESSOR(nsIByteRangeRequest, NS_IBYTERANGEREQUEST_IID)

/* Use this macro when declaring classes that implement this interface. */
#define NS_DECL_NSIBYTERANGEREQUEST \
  NS_SCRIPTABLE NS_IMETHOD GetIsByteRangeRequest(PRBool *aIsByteRangeRequest); \
  NS_SCRIPTABLE NS_IMETHOD GetStartRange(PRInt64 *aStartRange); \
  NS_SCRIPTABLE NS_IMETHOD GetEndRange(PRInt64 *aEndRange); 

/* Use this macro to declare functions that forward the behavior of this interface to another object. */
#define NS_FORWARD_NSIBYTERANGEREQUEST(_to) \
  NS_SCRIPTABLE NS_IMETHOD GetIsByteRangeRequest(PRBool *aIsByteRangeRequest) { return _to GetIsByteRangeRequest(aIsByteRangeRequest); } \
  NS_SCRIPTABLE NS_IMETHOD GetStartRange(PRInt64 *aStartRange) { return _to GetStartRange(aStartRange); } \
  NS_SCRIPTABLE NS_IMETHOD GetEndRange(PRInt64 *aEndRange) { return _to GetEndRange(aEndRange); } 

/* Use this macro to declare functions that forward the behavior of this interface to another object in a safe way. */
#define NS_FORWARD_SAFE_NSIBYTERANGEREQUEST(_to) \
  NS_SCRIPTABLE NS_IMETHOD GetIsByteRangeRequest(PRBool *aIsByteRangeRequest) { return !_to ? NS_ERROR_NULL_POINTER : _to->GetIsByteRangeRequest(aIsByteRangeRequest); } \
  NS_SCRIPTABLE NS_IMETHOD GetStartRange(PRInt64 *aStartRange) { return !_to ? NS_ERROR_NULL_POINTER : _to->GetStartRange(aStartRange); } \
  NS_SCRIPTABLE NS_IMETHOD GetEndRange(PRInt64 *aEndRange) { return !_to ? NS_ERROR_NULL_POINTER : _to->GetEndRange(aEndRange); } 

#if 0
/* Use the code below as a template for the implementation class for this interface. */

/* Header file */
class nsByteRangeRequest : public nsIByteRangeRequest
{
public:
  NS_DECL_ISUPPORTS
  NS_DECL_NSIBYTERANGEREQUEST

  nsByteRangeRequest();

private:
  ~nsByteRangeRequest();

protected:
  /* additional members */
};

/* Implementation file */
NS_IMPL_ISUPPORTS1(nsByteRangeRequest, nsIByteRangeRequest)

nsByteRangeRequest::nsByteRangeRequest()
{
  /* member initializers and constructor code */
}

nsByteRangeRequest::~nsByteRangeRequest()
{
  /* destructor code */
}

/* readonly attribute boolean isByteRangeRequest; */
NS_IMETHODIMP nsByteRangeRequest::GetIsByteRangeRequest(PRBool *aIsByteRangeRequest)
{
    return NS_ERROR_NOT_IMPLEMENTED;
}

/* readonly attribute long long startRange; */
NS_IMETHODIMP nsByteRangeRequest::GetStartRange(PRInt64 *aStartRange)
{
    return NS_ERROR_NOT_IMPLEMENTED;
}

/* readonly attribute long long endRange; */
NS_IMETHODIMP nsByteRangeRequest::GetEndRange(PRInt64 *aEndRange)
{
    return NS_ERROR_NOT_IMPLEMENTED;
}

/* End of implementation class template. */
#endif


#endif /* __gen_nsIByteRangeRequest_h__ */
