/*
 * DO NOT EDIT.  THIS FILE IS GENERATED FROM e:/builds/moz2_slave/mozilla-1.9.1-win32-xulrunner/build/netwerk/base/public/nsIAuthPrompt2.idl
 */

#ifndef __gen_nsIAuthPrompt2_h__
#define __gen_nsIAuthPrompt2_h__


#ifndef __gen_nsISupports_h__
#include "nsISupports.h"
#endif

/* For IDL files that don't want to include root IDL files. */
#ifndef NS_NO_VTABLE
#define NS_NO_VTABLE
#endif
class nsIAuthPromptCallback; /* forward declaration */

class nsIChannel; /* forward declaration */

class nsICancelable; /* forward declaration */

class nsIAuthInformation; /* forward declaration */


/* starting interface:    nsIAuthPrompt2 */
#define NS_IAUTHPROMPT2_IID_STR "447fc780-1d28-412a-91a1-466d48129c65"

#define NS_IAUTHPROMPT2_IID \
  {0x447fc780, 0x1d28, 0x412a, \
    { 0x91, 0xa1, 0x46, 0x6d, 0x48, 0x12, 0x9c, 0x65 }}

/**
 * An interface allowing to prompt for a username and password. This interface
 * is usually acquired using getInterface on notification callbacks or similar.
 * It can be used to prompt users for authentication information, either
 * synchronously or asynchronously.
 */
class NS_NO_VTABLE NS_SCRIPTABLE nsIAuthPrompt2 : public nsISupports {
 public: 

  NS_DECLARE_STATIC_IID_ACCESSOR(NS_IAUTHPROMPT2_IID)

  /** @name Security Levels */
/**
   * The password will be sent unencrypted. No security provided.
   */
  enum { LEVEL_NONE = 0U };

  /**
   * Password will be sent encrypted, but the connection is otherwise
   * insecure.
   */
  enum { LEVEL_PW_ENCRYPTED = 1U };

  /**
   * The connection, both for password and data, is secure.
   */
  enum { LEVEL_SECURE = 2U };

  /**
   * Requests a username and a password. Implementations will commonly show a
   * dialog with a username and password field, depending on flags also a
   * domain field.
   *
   * @param aChannel
   *        The channel that requires authentication.
   * @param level
   *        One of the level constants from above. See there for descriptions
   *        of the levels.
   * @param authInfo
   *        Authentication information object. The implementation should fill in
   *        this object with the information entered by the user before
   *        returning.
   *
   * @retval true
   *         Authentication can proceed using the values in the authInfo
   *         object.
   * @retval false
   *         Authentication should be cancelled, usually because the user did
   *         not provide username/password.
   *
   * @note   Exceptions thrown from this function will be treated like a
   *         return value of false.
   */
  /* boolean promptAuth (in nsIChannel aChannel, in PRUint32 level, in nsIAuthInformation authInfo); */
  NS_SCRIPTABLE NS_IMETHOD PromptAuth(nsIChannel *aChannel, PRUint32 level, nsIAuthInformation *authInfo, PRBool *_retval NS_OUTPARAM) = 0;

  /**
   * Asynchronously prompt the user for a username and password.
   * This has largely the same semantics as promptUsernameAndPassword(),
   * but must return immediately after calling and return the entered
   * data in a callback.
   *
   * If the user closes the dialog using a cancel button or similar,
   * the callback's nsIAuthPromptCallback::onAuthCancelled method must be
   * called.
   * Calling nsICancelable::cancel on the returned object SHOULD close the
   * dialog and MUST call nsIAuthPromptCallback::onAuthCancelled on the provided
   * callback.
   *
   * @throw NS_ERROR_NOT_IMPLEMENTED
   *        Asynchronous authentication prompts are not supported;
   *        the caller should fall back to promptUsernameAndPassword().
   */
  /* nsICancelable asyncPromptAuth (in nsIChannel aChannel, in nsIAuthPromptCallback aCallback, in nsISupports aContext, in PRUint32 level, in nsIAuthInformation authInfo); */
  NS_SCRIPTABLE NS_IMETHOD AsyncPromptAuth(nsIChannel *aChannel, nsIAuthPromptCallback *aCallback, nsISupports *aContext, PRUint32 level, nsIAuthInformation *authInfo, nsICancelable **_retval NS_OUTPARAM) = 0;

};

  NS_DEFINE_STATIC_IID_ACCESSOR(nsIAuthPrompt2, NS_IAUTHPROMPT2_IID)

/* Use this macro when declaring classes that implement this interface. */
#define NS_DECL_NSIAUTHPROMPT2 \
  NS_SCRIPTABLE NS_IMETHOD PromptAuth(nsIChannel *aChannel, PRUint32 level, nsIAuthInformation *authInfo, PRBool *_retval NS_OUTPARAM); \
  NS_SCRIPTABLE NS_IMETHOD AsyncPromptAuth(nsIChannel *aChannel, nsIAuthPromptCallback *aCallback, nsISupports *aContext, PRUint32 level, nsIAuthInformation *authInfo, nsICancelable **_retval NS_OUTPARAM); 

/* Use this macro to declare functions that forward the behavior of this interface to another object. */
#define NS_FORWARD_NSIAUTHPROMPT2(_to) \
  NS_SCRIPTABLE NS_IMETHOD PromptAuth(nsIChannel *aChannel, PRUint32 level, nsIAuthInformation *authInfo, PRBool *_retval NS_OUTPARAM) { return _to PromptAuth(aChannel, level, authInfo, _retval); } \
  NS_SCRIPTABLE NS_IMETHOD AsyncPromptAuth(nsIChannel *aChannel, nsIAuthPromptCallback *aCallback, nsISupports *aContext, PRUint32 level, nsIAuthInformation *authInfo, nsICancelable **_retval NS_OUTPARAM) { return _to AsyncPromptAuth(aChannel, aCallback, aContext, level, authInfo, _retval); } 

/* Use this macro to declare functions that forward the behavior of this interface to another object in a safe way. */
#define NS_FORWARD_SAFE_NSIAUTHPROMPT2(_to) \
  NS_SCRIPTABLE NS_IMETHOD PromptAuth(nsIChannel *aChannel, PRUint32 level, nsIAuthInformation *authInfo, PRBool *_retval NS_OUTPARAM) { return !_to ? NS_ERROR_NULL_POINTER : _to->PromptAuth(aChannel, level, authInfo, _retval); } \
  NS_SCRIPTABLE NS_IMETHOD AsyncPromptAuth(nsIChannel *aChannel, nsIAuthPromptCallback *aCallback, nsISupports *aContext, PRUint32 level, nsIAuthInformation *authInfo, nsICancelable **_retval NS_OUTPARAM) { return !_to ? NS_ERROR_NULL_POINTER : _to->AsyncPromptAuth(aChannel, aCallback, aContext, level, authInfo, _retval); } 

#if 0
/* Use the code below as a template for the implementation class for this interface. */

/* Header file */
class nsAuthPrompt2 : public nsIAuthPrompt2
{
public:
  NS_DECL_ISUPPORTS
  NS_DECL_NSIAUTHPROMPT2

  nsAuthPrompt2();

private:
  ~nsAuthPrompt2();

protected:
  /* additional members */
};

/* Implementation file */
NS_IMPL_ISUPPORTS1(nsAuthPrompt2, nsIAuthPrompt2)

nsAuthPrompt2::nsAuthPrompt2()
{
  /* member initializers and constructor code */
}

nsAuthPrompt2::~nsAuthPrompt2()
{
  /* destructor code */
}

/* boolean promptAuth (in nsIChannel aChannel, in PRUint32 level, in nsIAuthInformation authInfo); */
NS_IMETHODIMP nsAuthPrompt2::PromptAuth(nsIChannel *aChannel, PRUint32 level, nsIAuthInformation *authInfo, PRBool *_retval NS_OUTPARAM)
{
    return NS_ERROR_NOT_IMPLEMENTED;
}

/* nsICancelable asyncPromptAuth (in nsIChannel aChannel, in nsIAuthPromptCallback aCallback, in nsISupports aContext, in PRUint32 level, in nsIAuthInformation authInfo); */
NS_IMETHODIMP nsAuthPrompt2::AsyncPromptAuth(nsIChannel *aChannel, nsIAuthPromptCallback *aCallback, nsISupports *aContext, PRUint32 level, nsIAuthInformation *authInfo, nsICancelable **_retval NS_OUTPARAM)
{
    return NS_ERROR_NOT_IMPLEMENTED;
}

/* End of implementation class template. */
#endif


#endif /* __gen_nsIAuthPrompt2_h__ */
