/*
 * DO NOT EDIT.  THIS FILE IS GENERATED FROM e:/builds/moz2_slave/mozilla-1.9.1-win32-xulrunner/build/embedding/components/windowwatcher/public/nsIPromptService2.idl
 */

#ifndef __gen_nsIPromptService2_h__
#define __gen_nsIPromptService2_h__


#ifndef __gen_nsIPromptService_h__
#include "nsIPromptService.h"
#endif

/* For IDL files that don't want to include root IDL files. */
#ifndef NS_NO_VTABLE
#define NS_NO_VTABLE
#endif
class nsIAuthInformation; /* forward declaration */

class nsIAuthPromptCallback; /* forward declaration */

class nsICancelable; /* forward declaration */

class nsIChannel; /* forward declaration */

class nsIDOMWindow; /* forward declaration */


/* starting interface:    nsIPromptService2 */
#define NS_IPROMPTSERVICE2_IID_STR "cf86d196-dbee-4482-9dfa-3477aa128319"

#define NS_IPROMPTSERVICE2_IID \
  {0xcf86d196, 0xdbee, 0x4482, \
    { 0x9d, 0xfa, 0x34, 0x77, 0xaa, 0x12, 0x83, 0x19 }}

/**
 * This is an improved version of nsIPromptService that is less prescriptive
 * about the resulting user interface.
 *
 * @status INCOMPLETE do not freeze before fixing bug 228207
 */
class NS_NO_VTABLE NS_SCRIPTABLE nsIPromptService2 : public nsIPromptService {
 public: 

  NS_DECLARE_STATIC_IID_ACCESSOR(NS_IPROMPTSERVICE2_IID)

  /* boolean promptAuth (in nsIDOMWindow aParent, in nsIChannel aChannel, in PRUint32 level, in nsIAuthInformation authInfo, in wstring checkboxLabel, inout boolean checkValue); */
  NS_SCRIPTABLE NS_IMETHOD PromptAuth(nsIDOMWindow *aParent, nsIChannel *aChannel, PRUint32 level, nsIAuthInformation *authInfo, const PRUnichar *checkboxLabel, PRBool *checkValue NS_INOUTPARAM, PRBool *_retval NS_OUTPARAM) = 0;

  /* nsICancelable asyncPromptAuth (in nsIDOMWindow aParent, in nsIChannel aChannel, in nsIAuthPromptCallback aCallback, in nsISupports aContext, in PRUint32 level, in nsIAuthInformation authInfo, in wstring checkboxLabel, inout boolean checkValue); */
  NS_SCRIPTABLE NS_IMETHOD AsyncPromptAuth(nsIDOMWindow *aParent, nsIChannel *aChannel, nsIAuthPromptCallback *aCallback, nsISupports *aContext, PRUint32 level, nsIAuthInformation *authInfo, const PRUnichar *checkboxLabel, PRBool *checkValue NS_INOUTPARAM, nsICancelable **_retval NS_OUTPARAM) = 0;

};

  NS_DEFINE_STATIC_IID_ACCESSOR(nsIPromptService2, NS_IPROMPTSERVICE2_IID)

/* Use this macro when declaring classes that implement this interface. */
#define NS_DECL_NSIPROMPTSERVICE2 \
  NS_SCRIPTABLE NS_IMETHOD PromptAuth(nsIDOMWindow *aParent, nsIChannel *aChannel, PRUint32 level, nsIAuthInformation *authInfo, const PRUnichar *checkboxLabel, PRBool *checkValue NS_INOUTPARAM, PRBool *_retval NS_OUTPARAM); \
  NS_SCRIPTABLE NS_IMETHOD AsyncPromptAuth(nsIDOMWindow *aParent, nsIChannel *aChannel, nsIAuthPromptCallback *aCallback, nsISupports *aContext, PRUint32 level, nsIAuthInformation *authInfo, const PRUnichar *checkboxLabel, PRBool *checkValue NS_INOUTPARAM, nsICancelable **_retval NS_OUTPARAM); 

/* Use this macro to declare functions that forward the behavior of this interface to another object. */
#define NS_FORWARD_NSIPROMPTSERVICE2(_to) \
  NS_SCRIPTABLE NS_IMETHOD PromptAuth(nsIDOMWindow *aParent, nsIChannel *aChannel, PRUint32 level, nsIAuthInformation *authInfo, const PRUnichar *checkboxLabel, PRBool *checkValue NS_INOUTPARAM, PRBool *_retval NS_OUTPARAM) { return _to PromptAuth(aParent, aChannel, level, authInfo, checkboxLabel, checkValue, _retval); } \
  NS_SCRIPTABLE NS_IMETHOD AsyncPromptAuth(nsIDOMWindow *aParent, nsIChannel *aChannel, nsIAuthPromptCallback *aCallback, nsISupports *aContext, PRUint32 level, nsIAuthInformation *authInfo, const PRUnichar *checkboxLabel, PRBool *checkValue NS_INOUTPARAM, nsICancelable **_retval NS_OUTPARAM) { return _to AsyncPromptAuth(aParent, aChannel, aCallback, aContext, level, authInfo, checkboxLabel, checkValue, _retval); } 

/* Use this macro to declare functions that forward the behavior of this interface to another object in a safe way. */
#define NS_FORWARD_SAFE_NSIPROMPTSERVICE2(_to) \
  NS_SCRIPTABLE NS_IMETHOD PromptAuth(nsIDOMWindow *aParent, nsIChannel *aChannel, PRUint32 level, nsIAuthInformation *authInfo, const PRUnichar *checkboxLabel, PRBool *checkValue NS_INOUTPARAM, PRBool *_retval NS_OUTPARAM) { return !_to ? NS_ERROR_NULL_POINTER : _to->PromptAuth(aParent, aChannel, level, authInfo, checkboxLabel, checkValue, _retval); } \
  NS_SCRIPTABLE NS_IMETHOD AsyncPromptAuth(nsIDOMWindow *aParent, nsIChannel *aChannel, nsIAuthPromptCallback *aCallback, nsISupports *aContext, PRUint32 level, nsIAuthInformation *authInfo, const PRUnichar *checkboxLabel, PRBool *checkValue NS_INOUTPARAM, nsICancelable **_retval NS_OUTPARAM) { return !_to ? NS_ERROR_NULL_POINTER : _to->AsyncPromptAuth(aParent, aChannel, aCallback, aContext, level, authInfo, checkboxLabel, checkValue, _retval); } 

#if 0
/* Use the code below as a template for the implementation class for this interface. */

/* Header file */
class nsPromptService2 : public nsIPromptService2
{
public:
  NS_DECL_ISUPPORTS
  NS_DECL_NSIPROMPTSERVICE2

  nsPromptService2();

private:
  ~nsPromptService2();

protected:
  /* additional members */
};

/* Implementation file */
NS_IMPL_ISUPPORTS1(nsPromptService2, nsIPromptService2)

nsPromptService2::nsPromptService2()
{
  /* member initializers and constructor code */
}

nsPromptService2::~nsPromptService2()
{
  /* destructor code */
}

/* boolean promptAuth (in nsIDOMWindow aParent, in nsIChannel aChannel, in PRUint32 level, in nsIAuthInformation authInfo, in wstring checkboxLabel, inout boolean checkValue); */
NS_IMETHODIMP nsPromptService2::PromptAuth(nsIDOMWindow *aParent, nsIChannel *aChannel, PRUint32 level, nsIAuthInformation *authInfo, const PRUnichar *checkboxLabel, PRBool *checkValue NS_INOUTPARAM, PRBool *_retval NS_OUTPARAM)
{
    return NS_ERROR_NOT_IMPLEMENTED;
}

/* nsICancelable asyncPromptAuth (in nsIDOMWindow aParent, in nsIChannel aChannel, in nsIAuthPromptCallback aCallback, in nsISupports aContext, in PRUint32 level, in nsIAuthInformation authInfo, in wstring checkboxLabel, inout boolean checkValue); */
NS_IMETHODIMP nsPromptService2::AsyncPromptAuth(nsIDOMWindow *aParent, nsIChannel *aChannel, nsIAuthPromptCallback *aCallback, nsISupports *aContext, PRUint32 level, nsIAuthInformation *authInfo, const PRUnichar *checkboxLabel, PRBool *checkValue NS_INOUTPARAM, nsICancelable **_retval NS_OUTPARAM)
{
    return NS_ERROR_NOT_IMPLEMENTED;
}

/* End of implementation class template. */
#endif


#endif /* __gen_nsIPromptService2_h__ */
