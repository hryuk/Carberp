/*
 * DO NOT EDIT.  THIS FILE IS GENERATED FROM e:/builds/moz2_slave/mozilla-1.9.1-win32-xulrunner/build/netwerk/base/public/nsIAuthPromptProvider.idl
 */

#ifndef __gen_nsIAuthPromptProvider_h__
#define __gen_nsIAuthPromptProvider_h__


#ifndef __gen_nsISupports_h__
#include "nsISupports.h"
#endif

/* For IDL files that don't want to include root IDL files. */
#ifndef NS_NO_VTABLE
#define NS_NO_VTABLE
#endif

/* starting interface:    nsIAuthPromptProvider */
#define NS_IAUTHPROMPTPROVIDER_IID_STR "bd9dc0fa-68ce-47d0-8859-6418c2ae8576"

#define NS_IAUTHPROMPTPROVIDER_IID \
  {0xbd9dc0fa, 0x68ce, 0x47d0, \
    { 0x88, 0x59, 0x64, 0x18, 0xc2, 0xae, 0x85, 0x76 }}

class NS_NO_VTABLE NS_SCRIPTABLE nsIAuthPromptProvider : public nsISupports {
 public: 

  NS_DECLARE_STATIC_IID_ACCESSOR(NS_IAUTHPROMPTPROVIDER_IID)

  /**
     * Normal (non-proxy) prompt request.
     */
  enum { PROMPT_NORMAL = 0U };

  /**
     * Proxy auth request.
     */
  enum { PROMPT_PROXY = 1U };

  /**
     * Request a prompt interface for the given prompt reason;
     * @throws NS_ERROR_NOT_AVAILABLE if no prompt is allowed or
     * available for the given reason.
     *
     * @param aPromptReason   The reason for the auth prompt;
     *                        one of #PROMPT_NORMAL or #PROMPT_PROXY
     * @param iid             The desired interface, e.g.
     *                        NS_GET_IID(nsIAuthPrompt2).
     * @returns an nsIAuthPrompt2 interface, or throws NS_ERROR_NOT_AVAILABLE
     */
  /* void getAuthPrompt (in PRUint32 aPromptReason, in nsIIDRef iid, [iid_is (iid), retval] out nsQIResult result); */
  NS_SCRIPTABLE NS_IMETHOD GetAuthPrompt(PRUint32 aPromptReason, const nsIID & iid, void * *result NS_OUTPARAM) = 0;

};

  NS_DEFINE_STATIC_IID_ACCESSOR(nsIAuthPromptProvider, NS_IAUTHPROMPTPROVIDER_IID)

/* Use this macro when declaring classes that implement this interface. */
#define NS_DECL_NSIAUTHPROMPTPROVIDER \
  NS_SCRIPTABLE NS_IMETHOD GetAuthPrompt(PRUint32 aPromptReason, const nsIID & iid, void * *result NS_OUTPARAM); 

/* Use this macro to declare functions that forward the behavior of this interface to another object. */
#define NS_FORWARD_NSIAUTHPROMPTPROVIDER(_to) \
  NS_SCRIPTABLE NS_IMETHOD GetAuthPrompt(PRUint32 aPromptReason, const nsIID & iid, void * *result NS_OUTPARAM) { return _to GetAuthPrompt(aPromptReason, iid, result); } 

/* Use this macro to declare functions that forward the behavior of this interface to another object in a safe way. */
#define NS_FORWARD_SAFE_NSIAUTHPROMPTPROVIDER(_to) \
  NS_SCRIPTABLE NS_IMETHOD GetAuthPrompt(PRUint32 aPromptReason, const nsIID & iid, void * *result NS_OUTPARAM) { return !_to ? NS_ERROR_NULL_POINTER : _to->GetAuthPrompt(aPromptReason, iid, result); } 

#if 0
/* Use the code below as a template for the implementation class for this interface. */

/* Header file */
class nsAuthPromptProvider : public nsIAuthPromptProvider
{
public:
  NS_DECL_ISUPPORTS
  NS_DECL_NSIAUTHPROMPTPROVIDER

  nsAuthPromptProvider();

private:
  ~nsAuthPromptProvider();

protected:
  /* additional members */
};

/* Implementation file */
NS_IMPL_ISUPPORTS1(nsAuthPromptProvider, nsIAuthPromptProvider)

nsAuthPromptProvider::nsAuthPromptProvider()
{
  /* member initializers and constructor code */
}

nsAuthPromptProvider::~nsAuthPromptProvider()
{
  /* destructor code */
}

/* void getAuthPrompt (in PRUint32 aPromptReason, in nsIIDRef iid, [iid_is (iid), retval] out nsQIResult result); */
NS_IMETHODIMP nsAuthPromptProvider::GetAuthPrompt(PRUint32 aPromptReason, const nsIID & iid, void * *result NS_OUTPARAM)
{
    return NS_ERROR_NOT_IMPLEMENTED;
}

/* End of implementation class template. */
#endif


#endif /* __gen_nsIAuthPromptProvider_h__ */
