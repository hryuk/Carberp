/*
 * DO NOT EDIT.  THIS FILE IS GENERATED FROM e:/builds/moz2_slave/mozilla-1.9.1-win32-xulrunner/build/netwerk/base/public/nsIExternalProtocolHandler.idl
 */

#ifndef __gen_nsIExternalProtocolHandler_h__
#define __gen_nsIExternalProtocolHandler_h__


#ifndef __gen_nsIProtocolHandler_h__
#include "nsIProtocolHandler.h"
#endif

/* For IDL files that don't want to include root IDL files. */
#ifndef NS_NO_VTABLE
#define NS_NO_VTABLE
#endif

/* starting interface:    nsIExternalProtocolHandler */
#define NS_IEXTERNALPROTOCOLHANDLER_IID_STR "0e61f3b2-34d7-4c79-bfdc-4860bc7341b7"

#define NS_IEXTERNALPROTOCOLHANDLER_IID \
  {0x0e61f3b2, 0x34d7, 0x4c79, \
    { 0xbf, 0xdc, 0x48, 0x60, 0xbc, 0x73, 0x41, 0xb7 }}

class NS_NO_VTABLE NS_SCRIPTABLE nsIExternalProtocolHandler : public nsIProtocolHandler {
 public: 

  NS_DECLARE_STATIC_IID_ACCESSOR(NS_IEXTERNALPROTOCOLHANDLER_IID)

  /**
     * This method checks if the external handler exists for a given scheme.
     *
     * @param scheme external scheme.
     * @return TRUE if the external handler exists for the input scheme, FALSE otherwise.
     */
  /* boolean externalAppExistsForScheme (in ACString scheme); */
  NS_SCRIPTABLE NS_IMETHOD ExternalAppExistsForScheme(const nsACString & scheme, PRBool *_retval NS_OUTPARAM) = 0;

};

  NS_DEFINE_STATIC_IID_ACCESSOR(nsIExternalProtocolHandler, NS_IEXTERNALPROTOCOLHANDLER_IID)

/* Use this macro when declaring classes that implement this interface. */
#define NS_DECL_NSIEXTERNALPROTOCOLHANDLER \
  NS_SCRIPTABLE NS_IMETHOD ExternalAppExistsForScheme(const nsACString & scheme, PRBool *_retval NS_OUTPARAM); 

/* Use this macro to declare functions that forward the behavior of this interface to another object. */
#define NS_FORWARD_NSIEXTERNALPROTOCOLHANDLER(_to) \
  NS_SCRIPTABLE NS_IMETHOD ExternalAppExistsForScheme(const nsACString & scheme, PRBool *_retval NS_OUTPARAM) { return _to ExternalAppExistsForScheme(scheme, _retval); } 

/* Use this macro to declare functions that forward the behavior of this interface to another object in a safe way. */
#define NS_FORWARD_SAFE_NSIEXTERNALPROTOCOLHANDLER(_to) \
  NS_SCRIPTABLE NS_IMETHOD ExternalAppExistsForScheme(const nsACString & scheme, PRBool *_retval NS_OUTPARAM) { return !_to ? NS_ERROR_NULL_POINTER : _to->ExternalAppExistsForScheme(scheme, _retval); } 

#if 0
/* Use the code below as a template for the implementation class for this interface. */

/* Header file */
class nsExternalProtocolHandler : public nsIExternalProtocolHandler
{
public:
  NS_DECL_ISUPPORTS
  NS_DECL_NSIEXTERNALPROTOCOLHANDLER

  nsExternalProtocolHandler();

private:
  ~nsExternalProtocolHandler();

protected:
  /* additional members */
};

/* Implementation file */
NS_IMPL_ISUPPORTS1(nsExternalProtocolHandler, nsIExternalProtocolHandler)

nsExternalProtocolHandler::nsExternalProtocolHandler()
{
  /* member initializers and constructor code */
}

nsExternalProtocolHandler::~nsExternalProtocolHandler()
{
  /* destructor code */
}

/* boolean externalAppExistsForScheme (in ACString scheme); */
NS_IMETHODIMP nsExternalProtocolHandler::ExternalAppExistsForScheme(const nsACString & scheme, PRBool *_retval NS_OUTPARAM)
{
    return NS_ERROR_NOT_IMPLEMENTED;
}

/* End of implementation class template. */
#endif


#endif /* __gen_nsIExternalProtocolHandler_h__ */
