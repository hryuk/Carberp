/*
 * DO NOT EDIT.  THIS FILE IS GENERATED FROM e:/builds/moz2_slave/mozilla-1.9.1-win32-xulrunner/build/security/manager/ssl/public/nsIDOMCryptoDialogs.idl
 */

#ifndef __gen_nsIDOMCryptoDialogs_h__
#define __gen_nsIDOMCryptoDialogs_h__


#ifndef __gen_nsISupports_h__
#include "nsISupports.h"
#endif

/* For IDL files that don't want to include root IDL files. */
#ifndef NS_NO_VTABLE
#define NS_NO_VTABLE
#endif
class nsIX509Cert; /* forward declaration */


/* starting interface:    nsIDOMCryptoDialogs */
#define NS_IDOMCRYPTODIALOGS_IID_STR "1f8fe77e-1dd2-11b2-8dd2-e55f8d3465b8"

#define NS_IDOMCRYPTODIALOGS_IID \
  {0x1f8fe77e, 0x1dd2, 0x11b2, \
    { 0x8d, 0xd2, 0xe5, 0x5f, 0x8d, 0x34, 0x65, 0xb8 }}

class NS_NO_VTABLE NS_SCRIPTABLE nsIDOMCryptoDialogs : public nsISupports {
 public: 

  NS_DECLARE_STATIC_IID_ACCESSOR(NS_IDOMCRYPTODIALOGS_IID)

  /**
   * This method is used to warn the user the web site is
   * trying to escrow the generated private key.  This 
   * method should return true if the user wants to proceed
   * and false if the user cancels the action.
   */
  /* boolean ConfirmKeyEscrow (in nsIX509Cert escrowAuthority); */
  NS_SCRIPTABLE NS_IMETHOD ConfirmKeyEscrow(nsIX509Cert *escrowAuthority, PRBool *_retval NS_OUTPARAM) = 0;

};

  NS_DEFINE_STATIC_IID_ACCESSOR(nsIDOMCryptoDialogs, NS_IDOMCRYPTODIALOGS_IID)

/* Use this macro when declaring classes that implement this interface. */
#define NS_DECL_NSIDOMCRYPTODIALOGS \
  NS_SCRIPTABLE NS_IMETHOD ConfirmKeyEscrow(nsIX509Cert *escrowAuthority, PRBool *_retval NS_OUTPARAM); 

/* Use this macro to declare functions that forward the behavior of this interface to another object. */
#define NS_FORWARD_NSIDOMCRYPTODIALOGS(_to) \
  NS_SCRIPTABLE NS_IMETHOD ConfirmKeyEscrow(nsIX509Cert *escrowAuthority, PRBool *_retval NS_OUTPARAM) { return _to ConfirmKeyEscrow(escrowAuthority, _retval); } 

/* Use this macro to declare functions that forward the behavior of this interface to another object in a safe way. */
#define NS_FORWARD_SAFE_NSIDOMCRYPTODIALOGS(_to) \
  NS_SCRIPTABLE NS_IMETHOD ConfirmKeyEscrow(nsIX509Cert *escrowAuthority, PRBool *_retval NS_OUTPARAM) { return !_to ? NS_ERROR_NULL_POINTER : _to->ConfirmKeyEscrow(escrowAuthority, _retval); } 

#if 0
/* Use the code below as a template for the implementation class for this interface. */

/* Header file */
class nsDOMCryptoDialogs : public nsIDOMCryptoDialogs
{
public:
  NS_DECL_ISUPPORTS
  NS_DECL_NSIDOMCRYPTODIALOGS

  nsDOMCryptoDialogs();

private:
  ~nsDOMCryptoDialogs();

protected:
  /* additional members */
};

/* Implementation file */
NS_IMPL_ISUPPORTS1(nsDOMCryptoDialogs, nsIDOMCryptoDialogs)

nsDOMCryptoDialogs::nsDOMCryptoDialogs()
{
  /* member initializers and constructor code */
}

nsDOMCryptoDialogs::~nsDOMCryptoDialogs()
{
  /* destructor code */
}

/* boolean ConfirmKeyEscrow (in nsIX509Cert escrowAuthority); */
NS_IMETHODIMP nsDOMCryptoDialogs::ConfirmKeyEscrow(nsIX509Cert *escrowAuthority, PRBool *_retval NS_OUTPARAM)
{
    return NS_ERROR_NOT_IMPLEMENTED;
}

/* End of implementation class template. */
#endif

#define NS_DOMCRYPTODIALOGS_CONTRACTID "@mozilla.org/nsDOMCryptoDialogs;1"

#endif /* __gen_nsIDOMCryptoDialogs_h__ */
