/*
 * DO NOT EDIT.  THIS FILE IS GENERATED FROM e:/builds/moz2_slave/mozilla-1.9.1-win32-xulrunner/build/dom/public/idl/base/nsIDOMClientInformation.idl
 */

#ifndef __gen_nsIDOMClientInformation_h__
#define __gen_nsIDOMClientInformation_h__


#ifndef __gen_domstubs_h__
#include "domstubs.h"
#endif

/* For IDL files that don't want to include root IDL files. */
#ifndef NS_NO_VTABLE
#define NS_NO_VTABLE
#endif
class nsIDOMOfflineResourceList; /* forward declaration */


/* starting interface:    nsIDOMClientInformation */
#define NS_IDOMCLIENTINFORMATION_IID_STR "f8bbf8c3-c47b-465a-a221-22824449f689"

#define NS_IDOMCLIENTINFORMATION_IID \
  {0xf8bbf8c3, 0xc47b, 0x465a, \
    { 0xa2, 0x21, 0x22, 0x82, 0x44, 0x49, 0xf6, 0x89 }}

class NS_NO_VTABLE NS_SCRIPTABLE nsIDOMClientInformation : public nsISupports {
 public: 

  NS_DECLARE_STATIC_IID_ACCESSOR(NS_IDOMCLIENTINFORMATION_IID)

  /**
   * Web Applications 1.0 Browser State: registerContentHandler
   * Allows web services to register themselves as handlers for certain content
   * types.
   * http://whatwg.org/specs/web-apps/current-work/
   */
  /* void registerContentHandler (in DOMString mimeType, in DOMString uri, in DOMString title); */
  NS_SCRIPTABLE NS_IMETHOD RegisterContentHandler(const nsAString & mimeType, const nsAString & uri, const nsAString & title) = 0;

  /* void registerProtocolHandler (in DOMString protocol, in DOMString uri, in DOMString title); */
  NS_SCRIPTABLE NS_IMETHOD RegisterProtocolHandler(const nsAString & protocol, const nsAString & uri, const nsAString & title) = 0;

  /* boolean mozIsLocallyAvailable (in DOMString uri, in boolean whenOffline); */
  NS_SCRIPTABLE NS_IMETHOD MozIsLocallyAvailable(const nsAString & uri, PRBool whenOffline, PRBool *_retval NS_OUTPARAM) = 0;

};

  NS_DEFINE_STATIC_IID_ACCESSOR(nsIDOMClientInformation, NS_IDOMCLIENTINFORMATION_IID)

/* Use this macro when declaring classes that implement this interface. */
#define NS_DECL_NSIDOMCLIENTINFORMATION \
  NS_SCRIPTABLE NS_IMETHOD RegisterContentHandler(const nsAString & mimeType, const nsAString & uri, const nsAString & title); \
  NS_SCRIPTABLE NS_IMETHOD RegisterProtocolHandler(const nsAString & protocol, const nsAString & uri, const nsAString & title); \
  NS_SCRIPTABLE NS_IMETHOD MozIsLocallyAvailable(const nsAString & uri, PRBool whenOffline, PRBool *_retval NS_OUTPARAM); 

/* Use this macro to declare functions that forward the behavior of this interface to another object. */
#define NS_FORWARD_NSIDOMCLIENTINFORMATION(_to) \
  NS_SCRIPTABLE NS_IMETHOD RegisterContentHandler(const nsAString & mimeType, const nsAString & uri, const nsAString & title) { return _to RegisterContentHandler(mimeType, uri, title); } \
  NS_SCRIPTABLE NS_IMETHOD RegisterProtocolHandler(const nsAString & protocol, const nsAString & uri, const nsAString & title) { return _to RegisterProtocolHandler(protocol, uri, title); } \
  NS_SCRIPTABLE NS_IMETHOD MozIsLocallyAvailable(const nsAString & uri, PRBool whenOffline, PRBool *_retval NS_OUTPARAM) { return _to MozIsLocallyAvailable(uri, whenOffline, _retval); } 

/* Use this macro to declare functions that forward the behavior of this interface to another object in a safe way. */
#define NS_FORWARD_SAFE_NSIDOMCLIENTINFORMATION(_to) \
  NS_SCRIPTABLE NS_IMETHOD RegisterContentHandler(const nsAString & mimeType, const nsAString & uri, const nsAString & title) { return !_to ? NS_ERROR_NULL_POINTER : _to->RegisterContentHandler(mimeType, uri, title); } \
  NS_SCRIPTABLE NS_IMETHOD RegisterProtocolHandler(const nsAString & protocol, const nsAString & uri, const nsAString & title) { return !_to ? NS_ERROR_NULL_POINTER : _to->RegisterProtocolHandler(protocol, uri, title); } \
  NS_SCRIPTABLE NS_IMETHOD MozIsLocallyAvailable(const nsAString & uri, PRBool whenOffline, PRBool *_retval NS_OUTPARAM) { return !_to ? NS_ERROR_NULL_POINTER : _to->MozIsLocallyAvailable(uri, whenOffline, _retval); } 

#if 0
/* Use the code below as a template for the implementation class for this interface. */

/* Header file */
class nsDOMClientInformation : public nsIDOMClientInformation
{
public:
  NS_DECL_ISUPPORTS
  NS_DECL_NSIDOMCLIENTINFORMATION

  nsDOMClientInformation();

private:
  ~nsDOMClientInformation();

protected:
  /* additional members */
};

/* Implementation file */
NS_IMPL_ISUPPORTS1(nsDOMClientInformation, nsIDOMClientInformation)

nsDOMClientInformation::nsDOMClientInformation()
{
  /* member initializers and constructor code */
}

nsDOMClientInformation::~nsDOMClientInformation()
{
  /* destructor code */
}

/* void registerContentHandler (in DOMString mimeType, in DOMString uri, in DOMString title); */
NS_IMETHODIMP nsDOMClientInformation::RegisterContentHandler(const nsAString & mimeType, const nsAString & uri, const nsAString & title)
{
    return NS_ERROR_NOT_IMPLEMENTED;
}

/* void registerProtocolHandler (in DOMString protocol, in DOMString uri, in DOMString title); */
NS_IMETHODIMP nsDOMClientInformation::RegisterProtocolHandler(const nsAString & protocol, const nsAString & uri, const nsAString & title)
{
    return NS_ERROR_NOT_IMPLEMENTED;
}

/* boolean mozIsLocallyAvailable (in DOMString uri, in boolean whenOffline); */
NS_IMETHODIMP nsDOMClientInformation::MozIsLocallyAvailable(const nsAString & uri, PRBool whenOffline, PRBool *_retval NS_OUTPARAM)
{
    return NS_ERROR_NOT_IMPLEMENTED;
}

/* End of implementation class template. */
#endif


#endif /* __gen_nsIDOMClientInformation_h__ */
