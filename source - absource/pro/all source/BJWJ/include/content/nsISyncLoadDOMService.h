/*
 * DO NOT EDIT.  THIS FILE IS GENERATED FROM e:/builds/moz2_slave/mozilla-1.9.1-win32-xulrunner/build/content/base/public/nsISyncLoadDOMService.idl
 */

#ifndef __gen_nsISyncLoadDOMService_h__
#define __gen_nsISyncLoadDOMService_h__


#ifndef __gen_nsISupports_h__
#include "nsISupports.h"
#endif

/* For IDL files that don't want to include root IDL files. */
#ifndef NS_NO_VTABLE
#define NS_NO_VTABLE
#endif
class nsIURI; /* forward declaration */

class nsIPrincipal; /* forward declaration */

class nsIDOMDocument; /* forward declaration */

class nsIChannel; /* forward declaration */


/* starting interface:    nsISyncLoadDOMService */
#define NS_ISYNCLOADDOMSERVICE_IID_STR "8095998d-ae1c-4cfa-9b43-0973e5d77eb0"

#define NS_ISYNCLOADDOMSERVICE_IID \
  {0x8095998d, 0xae1c, 0x4cfa, \
    { 0x9b, 0x43, 0x09, 0x73, 0xe5, 0xd7, 0x7e, 0xb0 }}

/*************************************************************************
 *                                                                       *
 *                          **** NOTICE ****                             *
 *                                                                       *
 *                                                                       *
 *    This interface is DEPRECATED!                                      *
 *    You should instead use XMLHttpRequest which now works both from    *
 *    Javascript and C++.                                                *
 *                                                                       *
 *    Additionally, synchronous network loads are evil.  Any delays      *
 *    from the server will appear as a hang in the mozilla UI.           *
 *    Therefore, they should be avoided as much as possible.             *
 *                                                                       *
 *    Don't make me come over there!!                                    *
 *                                                                       *
 *                                                                       *
 ************************************************************************/
/**
 * The nsISyncDOMLoadService interface can be used to synchronously load
 * a document.
 */
class NS_NO_VTABLE NS_SCRIPTABLE nsISyncLoadDOMService : public nsISupports {
 public: 

  NS_DECLARE_STATIC_IID_ACCESSOR(NS_ISYNCLOADDOMSERVICE_IID)

  /**
     * Synchronously load the document from the specified channel.
     *
     * @param aChannel   The channel to load the document from.
     * @param aLoaderPrincipal Principal of loading document. For security
     *                         checks null if no securitychecks should be done
     *
     * @returns The document loaded from the URI.
     */
  /* nsIDOMDocument loadDocument (in nsIChannel aChannel, in nsIPrincipal aLoaderPrincipal); */
  NS_SCRIPTABLE NS_IMETHOD LoadDocument(nsIChannel *aChannel, nsIPrincipal *aLoaderPrincipal, nsIDOMDocument **_retval NS_OUTPARAM) = 0;

  /* nsIDOMDocument loadDocumentAsXML (in nsIChannel aChannel, in nsIPrincipal aLoaderPrincipal); */
  NS_SCRIPTABLE NS_IMETHOD LoadDocumentAsXML(nsIChannel *aChannel, nsIPrincipal *aLoaderPrincipal, nsIDOMDocument **_retval NS_OUTPARAM) = 0;

  /**
     * Synchronously load an XML document from the specified
     * channel. The channel must be possible to open synchronously.
     *
     * @param aChannel   The channel to load the document from.
     * @param aLoaderPrincipal Principal of loading document. For security
     *                         checks null if no securitychecks should be done
     *
     * @returns The document loaded from the URI.
     */
  /* nsIDOMDocument loadLocalDocument (in nsIChannel aChannel, in nsIPrincipal aLoaderPrincipal); */
  NS_SCRIPTABLE NS_IMETHOD LoadLocalDocument(nsIChannel *aChannel, nsIPrincipal *aLoaderPrincipal, nsIDOMDocument **_retval NS_OUTPARAM) = 0;

};

  NS_DEFINE_STATIC_IID_ACCESSOR(nsISyncLoadDOMService, NS_ISYNCLOADDOMSERVICE_IID)

/* Use this macro when declaring classes that implement this interface. */
#define NS_DECL_NSISYNCLOADDOMSERVICE \
  NS_SCRIPTABLE NS_IMETHOD LoadDocument(nsIChannel *aChannel, nsIPrincipal *aLoaderPrincipal, nsIDOMDocument **_retval NS_OUTPARAM); \
  NS_SCRIPTABLE NS_IMETHOD LoadDocumentAsXML(nsIChannel *aChannel, nsIPrincipal *aLoaderPrincipal, nsIDOMDocument **_retval NS_OUTPARAM); \
  NS_SCRIPTABLE NS_IMETHOD LoadLocalDocument(nsIChannel *aChannel, nsIPrincipal *aLoaderPrincipal, nsIDOMDocument **_retval NS_OUTPARAM); 

/* Use this macro to declare functions that forward the behavior of this interface to another object. */
#define NS_FORWARD_NSISYNCLOADDOMSERVICE(_to) \
  NS_SCRIPTABLE NS_IMETHOD LoadDocument(nsIChannel *aChannel, nsIPrincipal *aLoaderPrincipal, nsIDOMDocument **_retval NS_OUTPARAM) { return _to LoadDocument(aChannel, aLoaderPrincipal, _retval); } \
  NS_SCRIPTABLE NS_IMETHOD LoadDocumentAsXML(nsIChannel *aChannel, nsIPrincipal *aLoaderPrincipal, nsIDOMDocument **_retval NS_OUTPARAM) { return _to LoadDocumentAsXML(aChannel, aLoaderPrincipal, _retval); } \
  NS_SCRIPTABLE NS_IMETHOD LoadLocalDocument(nsIChannel *aChannel, nsIPrincipal *aLoaderPrincipal, nsIDOMDocument **_retval NS_OUTPARAM) { return _to LoadLocalDocument(aChannel, aLoaderPrincipal, _retval); } 

/* Use this macro to declare functions that forward the behavior of this interface to another object in a safe way. */
#define NS_FORWARD_SAFE_NSISYNCLOADDOMSERVICE(_to) \
  NS_SCRIPTABLE NS_IMETHOD LoadDocument(nsIChannel *aChannel, nsIPrincipal *aLoaderPrincipal, nsIDOMDocument **_retval NS_OUTPARAM) { return !_to ? NS_ERROR_NULL_POINTER : _to->LoadDocument(aChannel, aLoaderPrincipal, _retval); } \
  NS_SCRIPTABLE NS_IMETHOD LoadDocumentAsXML(nsIChannel *aChannel, nsIPrincipal *aLoaderPrincipal, nsIDOMDocument **_retval NS_OUTPARAM) { return !_to ? NS_ERROR_NULL_POINTER : _to->LoadDocumentAsXML(aChannel, aLoaderPrincipal, _retval); } \
  NS_SCRIPTABLE NS_IMETHOD LoadLocalDocument(nsIChannel *aChannel, nsIPrincipal *aLoaderPrincipal, nsIDOMDocument **_retval NS_OUTPARAM) { return !_to ? NS_ERROR_NULL_POINTER : _to->LoadLocalDocument(aChannel, aLoaderPrincipal, _retval); } 

#if 0
/* Use the code below as a template for the implementation class for this interface. */

/* Header file */
class nsSyncLoadDOMService : public nsISyncLoadDOMService
{
public:
  NS_DECL_ISUPPORTS
  NS_DECL_NSISYNCLOADDOMSERVICE

  nsSyncLoadDOMService();

private:
  ~nsSyncLoadDOMService();

protected:
  /* additional members */
};

/* Implementation file */
NS_IMPL_ISUPPORTS1(nsSyncLoadDOMService, nsISyncLoadDOMService)

nsSyncLoadDOMService::nsSyncLoadDOMService()
{
  /* member initializers and constructor code */
}

nsSyncLoadDOMService::~nsSyncLoadDOMService()
{
  /* destructor code */
}

/* nsIDOMDocument loadDocument (in nsIChannel aChannel, in nsIPrincipal aLoaderPrincipal); */
NS_IMETHODIMP nsSyncLoadDOMService::LoadDocument(nsIChannel *aChannel, nsIPrincipal *aLoaderPrincipal, nsIDOMDocument **_retval NS_OUTPARAM)
{
    return NS_ERROR_NOT_IMPLEMENTED;
}

/* nsIDOMDocument loadDocumentAsXML (in nsIChannel aChannel, in nsIPrincipal aLoaderPrincipal); */
NS_IMETHODIMP nsSyncLoadDOMService::LoadDocumentAsXML(nsIChannel *aChannel, nsIPrincipal *aLoaderPrincipal, nsIDOMDocument **_retval NS_OUTPARAM)
{
    return NS_ERROR_NOT_IMPLEMENTED;
}

/* nsIDOMDocument loadLocalDocument (in nsIChannel aChannel, in nsIPrincipal aLoaderPrincipal); */
NS_IMETHODIMP nsSyncLoadDOMService::LoadLocalDocument(nsIChannel *aChannel, nsIPrincipal *aLoaderPrincipal, nsIDOMDocument **_retval NS_OUTPARAM)
{
    return NS_ERROR_NOT_IMPLEMENTED;
}

/* End of implementation class template. */
#endif


#endif /* __gen_nsISyncLoadDOMService_h__ */
