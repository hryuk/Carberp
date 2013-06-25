/*
 * DO NOT EDIT.  THIS FILE IS GENERATED FROM e:/builds/moz2_slave/mozilla-1.9.1-win32-xulrunner/build/webshell/public/nsIDocumentLoaderFactory.idl
 */

#ifndef __gen_nsIDocumentLoaderFactory_h__
#define __gen_nsIDocumentLoaderFactory_h__


#ifndef __gen_nsISupports_h__
#include "nsISupports.h"
#endif

/* For IDL files that don't want to include root IDL files. */
#ifndef NS_NO_VTABLE
#define NS_NO_VTABLE
#endif
class nsIChannel; /* forward declaration */

class nsIContentViewer; /* forward declaration */

class nsIStreamListener; /* forward declaration */

class nsIDocument; /* forward declaration */

class nsILoadGroup; /* forward declaration */

class nsIPrincipal; /* forward declaration */


/* starting interface:    nsIDocumentLoaderFactory */
#define NS_IDOCUMENTLOADERFACTORY_IID_STR "5e7d2967-5a07-444f-95d5-25b533252d38"

#define NS_IDOCUMENTLOADERFACTORY_IID \
  {0x5e7d2967, 0x5a07, 0x444f, \
    { 0x95, 0xd5, 0x25, 0xb5, 0x33, 0x25, 0x2d, 0x38 }}

/**
 * To get a component that implements nsIDocumentLoaderFactory
 * for a given mimetype, use nsICategoryManager to find an entry
 * with the mimetype as its name in the category "Gecko-Content-Viewers".
 * The value of the entry is the contractid of the component.
 * The component is a service, so use GetService, not CreateInstance to get it.
 */
class NS_NO_VTABLE NS_SCRIPTABLE nsIDocumentLoaderFactory : public nsISupports {
 public: 

  NS_DECLARE_STATIC_IID_ACCESSOR(NS_IDOCUMENTLOADERFACTORY_IID)

  /* nsIContentViewer createInstance (in string aCommand, in nsIChannel aChannel, in nsILoadGroup aLoadGroup, in string aContentType, in nsISupports aContainer, in nsISupports aExtraInfo, out nsIStreamListener aDocListenerResult); */
  NS_SCRIPTABLE NS_IMETHOD CreateInstance(const char *aCommand, nsIChannel *aChannel, nsILoadGroup *aLoadGroup, const char *aContentType, nsISupports *aContainer, nsISupports *aExtraInfo, nsIStreamListener **aDocListenerResult NS_OUTPARAM, nsIContentViewer **_retval NS_OUTPARAM) = 0;

  /* nsIContentViewer createInstanceForDocument (in nsISupports aContainer, in nsIDocument aDocument, in string aCommand); */
  NS_SCRIPTABLE NS_IMETHOD CreateInstanceForDocument(nsISupports *aContainer, nsIDocument *aDocument, const char *aCommand, nsIContentViewer **_retval NS_OUTPARAM) = 0;

  /**
     * Create a blank document using the given loadgroup and given
     * principal.  aPrincipal is allowed to be null, in which case the
     * new document will get the about:blank codebase principal.
     */
  /* nsIDocument createBlankDocument (in nsILoadGroup aLoadGroup, in nsIPrincipal aPrincipal); */
  NS_SCRIPTABLE NS_IMETHOD CreateBlankDocument(nsILoadGroup *aLoadGroup, nsIPrincipal *aPrincipal, nsIDocument **_retval NS_OUTPARAM) = 0;

};

  NS_DEFINE_STATIC_IID_ACCESSOR(nsIDocumentLoaderFactory, NS_IDOCUMENTLOADERFACTORY_IID)

/* Use this macro when declaring classes that implement this interface. */
#define NS_DECL_NSIDOCUMENTLOADERFACTORY \
  NS_SCRIPTABLE NS_IMETHOD CreateInstance(const char *aCommand, nsIChannel *aChannel, nsILoadGroup *aLoadGroup, const char *aContentType, nsISupports *aContainer, nsISupports *aExtraInfo, nsIStreamListener **aDocListenerResult NS_OUTPARAM, nsIContentViewer **_retval NS_OUTPARAM); \
  NS_SCRIPTABLE NS_IMETHOD CreateInstanceForDocument(nsISupports *aContainer, nsIDocument *aDocument, const char *aCommand, nsIContentViewer **_retval NS_OUTPARAM); \
  NS_SCRIPTABLE NS_IMETHOD CreateBlankDocument(nsILoadGroup *aLoadGroup, nsIPrincipal *aPrincipal, nsIDocument **_retval NS_OUTPARAM); 

/* Use this macro to declare functions that forward the behavior of this interface to another object. */
#define NS_FORWARD_NSIDOCUMENTLOADERFACTORY(_to) \
  NS_SCRIPTABLE NS_IMETHOD CreateInstance(const char *aCommand, nsIChannel *aChannel, nsILoadGroup *aLoadGroup, const char *aContentType, nsISupports *aContainer, nsISupports *aExtraInfo, nsIStreamListener **aDocListenerResult NS_OUTPARAM, nsIContentViewer **_retval NS_OUTPARAM) { return _to CreateInstance(aCommand, aChannel, aLoadGroup, aContentType, aContainer, aExtraInfo, aDocListenerResult, _retval); } \
  NS_SCRIPTABLE NS_IMETHOD CreateInstanceForDocument(nsISupports *aContainer, nsIDocument *aDocument, const char *aCommand, nsIContentViewer **_retval NS_OUTPARAM) { return _to CreateInstanceForDocument(aContainer, aDocument, aCommand, _retval); } \
  NS_SCRIPTABLE NS_IMETHOD CreateBlankDocument(nsILoadGroup *aLoadGroup, nsIPrincipal *aPrincipal, nsIDocument **_retval NS_OUTPARAM) { return _to CreateBlankDocument(aLoadGroup, aPrincipal, _retval); } 

/* Use this macro to declare functions that forward the behavior of this interface to another object in a safe way. */
#define NS_FORWARD_SAFE_NSIDOCUMENTLOADERFACTORY(_to) \
  NS_SCRIPTABLE NS_IMETHOD CreateInstance(const char *aCommand, nsIChannel *aChannel, nsILoadGroup *aLoadGroup, const char *aContentType, nsISupports *aContainer, nsISupports *aExtraInfo, nsIStreamListener **aDocListenerResult NS_OUTPARAM, nsIContentViewer **_retval NS_OUTPARAM) { return !_to ? NS_ERROR_NULL_POINTER : _to->CreateInstance(aCommand, aChannel, aLoadGroup, aContentType, aContainer, aExtraInfo, aDocListenerResult, _retval); } \
  NS_SCRIPTABLE NS_IMETHOD CreateInstanceForDocument(nsISupports *aContainer, nsIDocument *aDocument, const char *aCommand, nsIContentViewer **_retval NS_OUTPARAM) { return !_to ? NS_ERROR_NULL_POINTER : _to->CreateInstanceForDocument(aContainer, aDocument, aCommand, _retval); } \
  NS_SCRIPTABLE NS_IMETHOD CreateBlankDocument(nsILoadGroup *aLoadGroup, nsIPrincipal *aPrincipal, nsIDocument **_retval NS_OUTPARAM) { return !_to ? NS_ERROR_NULL_POINTER : _to->CreateBlankDocument(aLoadGroup, aPrincipal, _retval); } 

#if 0
/* Use the code below as a template for the implementation class for this interface. */

/* Header file */
class nsDocumentLoaderFactory : public nsIDocumentLoaderFactory
{
public:
  NS_DECL_ISUPPORTS
  NS_DECL_NSIDOCUMENTLOADERFACTORY

  nsDocumentLoaderFactory();

private:
  ~nsDocumentLoaderFactory();

protected:
  /* additional members */
};

/* Implementation file */
NS_IMPL_ISUPPORTS1(nsDocumentLoaderFactory, nsIDocumentLoaderFactory)

nsDocumentLoaderFactory::nsDocumentLoaderFactory()
{
  /* member initializers and constructor code */
}

nsDocumentLoaderFactory::~nsDocumentLoaderFactory()
{
  /* destructor code */
}

/* nsIContentViewer createInstance (in string aCommand, in nsIChannel aChannel, in nsILoadGroup aLoadGroup, in string aContentType, in nsISupports aContainer, in nsISupports aExtraInfo, out nsIStreamListener aDocListenerResult); */
NS_IMETHODIMP nsDocumentLoaderFactory::CreateInstance(const char *aCommand, nsIChannel *aChannel, nsILoadGroup *aLoadGroup, const char *aContentType, nsISupports *aContainer, nsISupports *aExtraInfo, nsIStreamListener **aDocListenerResult NS_OUTPARAM, nsIContentViewer **_retval NS_OUTPARAM)
{
    return NS_ERROR_NOT_IMPLEMENTED;
}

/* nsIContentViewer createInstanceForDocument (in nsISupports aContainer, in nsIDocument aDocument, in string aCommand); */
NS_IMETHODIMP nsDocumentLoaderFactory::CreateInstanceForDocument(nsISupports *aContainer, nsIDocument *aDocument, const char *aCommand, nsIContentViewer **_retval NS_OUTPARAM)
{
    return NS_ERROR_NOT_IMPLEMENTED;
}

/* nsIDocument createBlankDocument (in nsILoadGroup aLoadGroup, in nsIPrincipal aPrincipal); */
NS_IMETHODIMP nsDocumentLoaderFactory::CreateBlankDocument(nsILoadGroup *aLoadGroup, nsIPrincipal *aPrincipal, nsIDocument **_retval NS_OUTPARAM)
{
    return NS_ERROR_NOT_IMPLEMENTED;
}

/* End of implementation class template. */
#endif


#endif /* __gen_nsIDocumentLoaderFactory_h__ */
