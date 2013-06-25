/*
 * DO NOT EDIT.  THIS FILE IS GENERATED FROM e:/builds/moz2_slave/mozilla-1.9.1-win32-xulrunner/build/netwerk/base/public/nsIAuthPromptCallback.idl
 */

#ifndef __gen_nsIAuthPromptCallback_h__
#define __gen_nsIAuthPromptCallback_h__


#ifndef __gen_nsISupports_h__
#include "nsISupports.h"
#endif

/* For IDL files that don't want to include root IDL files. */
#ifndef NS_NO_VTABLE
#define NS_NO_VTABLE
#endif
class nsIAuthInformation; /* forward declaration */


/* starting interface:    nsIAuthPromptCallback */
#define NS_IAUTHPROMPTCALLBACK_IID_STR "bdc387d7-2d29-4cac-92f1-dd75d786631d"

#define NS_IAUTHPROMPTCALLBACK_IID \
  {0xbdc387d7, 0x2d29, 0x4cac, \
    { 0x92, 0xf1, 0xdd, 0x75, 0xd7, 0x86, 0x63, 0x1d }}

/**
 * Interface for callback methods for the asynchronous nsIAuthPrompt2 method.
 * Callers MUST call exactly one method if nsIAuthPrompt2::promptPasswordAsync
 * returns successfully. They MUST NOT call any method on this interface before
 * promptPasswordAsync returns.
 */
class NS_NO_VTABLE NS_SCRIPTABLE nsIAuthPromptCallback : public nsISupports {
 public: 

  NS_DECLARE_STATIC_IID_ACCESSOR(NS_IAUTHPROMPTCALLBACK_IID)

  /**
   * Authentication information is available.
   *
   * @param aContext
   *        The context as passed to promptPasswordAsync
   * @param aAuthInfo
   *        Authentication information. Must be the same object that was passed
   *        to promptPasswordAsync.
   *
   * @note  Any exceptions thrown from this method should be ignored.
   */
  /* void onAuthAvailable (in nsISupports aContext, in nsIAuthInformation aAuthInfo); */
  NS_SCRIPTABLE NS_IMETHOD OnAuthAvailable(nsISupports *aContext, nsIAuthInformation *aAuthInfo) = 0;

  /**
   * Notification that the prompt was cancelled.
   *
   * @param aContext
   *        The context that was passed to promptPasswordAsync.
   * @param userCancel
   *        If false, this prompt was cancelled by calling the
   *        the cancel method on the nsICancelable; otherwise,
   *        it was cancelled by the user.
   */
  /* void onAuthCancelled (in nsISupports aContext, in boolean userCancel); */
  NS_SCRIPTABLE NS_IMETHOD OnAuthCancelled(nsISupports *aContext, PRBool userCancel) = 0;

};

  NS_DEFINE_STATIC_IID_ACCESSOR(nsIAuthPromptCallback, NS_IAUTHPROMPTCALLBACK_IID)

/* Use this macro when declaring classes that implement this interface. */
#define NS_DECL_NSIAUTHPROMPTCALLBACK \
  NS_SCRIPTABLE NS_IMETHOD OnAuthAvailable(nsISupports *aContext, nsIAuthInformation *aAuthInfo); \
  NS_SCRIPTABLE NS_IMETHOD OnAuthCancelled(nsISupports *aContext, PRBool userCancel); 

/* Use this macro to declare functions that forward the behavior of this interface to another object. */
#define NS_FORWARD_NSIAUTHPROMPTCALLBACK(_to) \
  NS_SCRIPTABLE NS_IMETHOD OnAuthAvailable(nsISupports *aContext, nsIAuthInformation *aAuthInfo) { return _to OnAuthAvailable(aContext, aAuthInfo); } \
  NS_SCRIPTABLE NS_IMETHOD OnAuthCancelled(nsISupports *aContext, PRBool userCancel) { return _to OnAuthCancelled(aContext, userCancel); } 

/* Use this macro to declare functions that forward the behavior of this interface to another object in a safe way. */
#define NS_FORWARD_SAFE_NSIAUTHPROMPTCALLBACK(_to) \
  NS_SCRIPTABLE NS_IMETHOD OnAuthAvailable(nsISupports *aContext, nsIAuthInformation *aAuthInfo) { return !_to ? NS_ERROR_NULL_POINTER : _to->OnAuthAvailable(aContext, aAuthInfo); } \
  NS_SCRIPTABLE NS_IMETHOD OnAuthCancelled(nsISupports *aContext, PRBool userCancel) { return !_to ? NS_ERROR_NULL_POINTER : _to->OnAuthCancelled(aContext, userCancel); } 

#if 0
/* Use the code below as a template for the implementation class for this interface. */

/* Header file */
class nsAuthPromptCallback : public nsIAuthPromptCallback
{
public:
  NS_DECL_ISUPPORTS
  NS_DECL_NSIAUTHPROMPTCALLBACK

  nsAuthPromptCallback();

private:
  ~nsAuthPromptCallback();

protected:
  /* additional members */
};

/* Implementation file */
NS_IMPL_ISUPPORTS1(nsAuthPromptCallback, nsIAuthPromptCallback)

nsAuthPromptCallback::nsAuthPromptCallback()
{
  /* member initializers and constructor code */
}

nsAuthPromptCallback::~nsAuthPromptCallback()
{
  /* destructor code */
}

/* void onAuthAvailable (in nsISupports aContext, in nsIAuthInformation aAuthInfo); */
NS_IMETHODIMP nsAuthPromptCallback::OnAuthAvailable(nsISupports *aContext, nsIAuthInformation *aAuthInfo)
{
    return NS_ERROR_NOT_IMPLEMENTED;
}

/* void onAuthCancelled (in nsISupports aContext, in boolean userCancel); */
NS_IMETHODIMP nsAuthPromptCallback::OnAuthCancelled(nsISupports *aContext, PRBool userCancel)
{
    return NS_ERROR_NOT_IMPLEMENTED;
}

/* End of implementation class template. */
#endif


#endif /* __gen_nsIAuthPromptCallback_h__ */
