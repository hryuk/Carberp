/*
 * DO NOT EDIT.  THIS FILE IS GENERATED FROM e:/builds/moz2_slave/mozilla-1.9.1-win32-xulrunner/build/netwerk/dns/public/nsIDNSListener.idl
 */

#ifndef __gen_nsIDNSListener_h__
#define __gen_nsIDNSListener_h__


#ifndef __gen_nsISupports_h__
#include "nsISupports.h"
#endif

/* For IDL files that don't want to include root IDL files. */
#ifndef NS_NO_VTABLE
#define NS_NO_VTABLE
#endif
class nsICancelable; /* forward declaration */

class nsIDNSRecord; /* forward declaration */


/* starting interface:    nsIDNSListener */
#define NS_IDNSLISTENER_IID_STR "41466a9f-f027-487d-a96c-af39e629b8d2"

#define NS_IDNSLISTENER_IID \
  {0x41466a9f, 0xf027, 0x487d, \
    { 0xa9, 0x6c, 0xaf, 0x39, 0xe6, 0x29, 0xb8, 0xd2 }}

/**
 * nsIDNSListener
 */
class NS_NO_VTABLE NS_SCRIPTABLE nsIDNSListener : public nsISupports {
 public: 

  NS_DECLARE_STATIC_IID_ACCESSOR(NS_IDNSLISTENER_IID)

  /**
     * called when an asynchronous host lookup completes.
     *
     * @param aRequest
     *        the value returned from asyncResolve.
     * @param aRecord
     *        the DNS record corresponding to the hostname that was resolved.
     *        this parameter is null if there was an error.
     * @param aStatus
     *        if the lookup failed, this parameter gives the reason.
     */
  /* void onLookupComplete (in nsICancelable aRequest, in nsIDNSRecord aRecord, in nsresult aStatus); */
  NS_SCRIPTABLE NS_IMETHOD OnLookupComplete(nsICancelable *aRequest, nsIDNSRecord *aRecord, nsresult aStatus) = 0;

};

  NS_DEFINE_STATIC_IID_ACCESSOR(nsIDNSListener, NS_IDNSLISTENER_IID)

/* Use this macro when declaring classes that implement this interface. */
#define NS_DECL_NSIDNSLISTENER \
  NS_SCRIPTABLE NS_IMETHOD OnLookupComplete(nsICancelable *aRequest, nsIDNSRecord *aRecord, nsresult aStatus); 

/* Use this macro to declare functions that forward the behavior of this interface to another object. */
#define NS_FORWARD_NSIDNSLISTENER(_to) \
  NS_SCRIPTABLE NS_IMETHOD OnLookupComplete(nsICancelable *aRequest, nsIDNSRecord *aRecord, nsresult aStatus) { return _to OnLookupComplete(aRequest, aRecord, aStatus); } 

/* Use this macro to declare functions that forward the behavior of this interface to another object in a safe way. */
#define NS_FORWARD_SAFE_NSIDNSLISTENER(_to) \
  NS_SCRIPTABLE NS_IMETHOD OnLookupComplete(nsICancelable *aRequest, nsIDNSRecord *aRecord, nsresult aStatus) { return !_to ? NS_ERROR_NULL_POINTER : _to->OnLookupComplete(aRequest, aRecord, aStatus); } 

#if 0
/* Use the code below as a template for the implementation class for this interface. */

/* Header file */
class nsDNSListener : public nsIDNSListener
{
public:
  NS_DECL_ISUPPORTS
  NS_DECL_NSIDNSLISTENER

  nsDNSListener();

private:
  ~nsDNSListener();

protected:
  /* additional members */
};

/* Implementation file */
NS_IMPL_ISUPPORTS1(nsDNSListener, nsIDNSListener)

nsDNSListener::nsDNSListener()
{
  /* member initializers and constructor code */
}

nsDNSListener::~nsDNSListener()
{
  /* destructor code */
}

/* void onLookupComplete (in nsICancelable aRequest, in nsIDNSRecord aRecord, in nsresult aStatus); */
NS_IMETHODIMP nsDNSListener::OnLookupComplete(nsICancelable *aRequest, nsIDNSRecord *aRecord, nsresult aStatus)
{
    return NS_ERROR_NOT_IMPLEMENTED;
}

/* End of implementation class template. */
#endif


#endif /* __gen_nsIDNSListener_h__ */
