/*
 * DO NOT EDIT.  THIS FILE IS GENERATED FROM e:/builds/moz2_slave/mozilla-1.9.1-win32-xulrunner/build/uriloader/base/nsIContentHandler.idl
 */

#ifndef __gen_nsIContentHandler_h__
#define __gen_nsIContentHandler_h__


#ifndef __gen_nsISupports_h__
#include "nsISupports.h"
#endif

/* For IDL files that don't want to include root IDL files. */
#ifndef NS_NO_VTABLE
#define NS_NO_VTABLE
#endif
class nsIRequest; /* forward declaration */

class nsIInterfaceRequestor; /* forward declaration */


/* starting interface:    nsIContentHandler */
#define NS_ICONTENTHANDLER_IID_STR "49439df2-b3d2-441c-bf62-866bdaf56fd2"

#define NS_ICONTENTHANDLER_IID \
  {0x49439df2, 0xb3d2, 0x441c, \
    { 0xbf, 0x62, 0x86, 0x6b, 0xda, 0xf5, 0x6f, 0xd2 }}

class NS_NO_VTABLE NS_SCRIPTABLE nsIContentHandler : public nsISupports {
 public: 

  NS_DECLARE_STATIC_IID_ACCESSOR(NS_ICONTENTHANDLER_IID)

  /**
   * Tells the content handler to take over handling the content. If this
   * function succeeds, the URI Loader will leave this request alone, ignoring
   * progress notifications. Failure of this method will cause the request to be
   * cancelled, unless the error code is NS_ERROR_WONT_HANDLE_CONTENT (see
   * below).
   *
   * @param aWindowContext
   *        Window context, used to get things like the current nsIDOMWindow
   *        for this request. May be null.
   * @param aContentType
   *        The content type of aRequest
   * @param aRequest
   *        A request whose content type is already known.
   *
   * @throw NS_ERROR_WONT_HANDLE_CONTENT Indicates that this handler does not
   *        want to handle this content. A different way for handling this
   *        content should be tried.
   */
  /* void handleContent (in string aContentType, in nsIInterfaceRequestor aWindowContext, in nsIRequest aRequest); */
  NS_SCRIPTABLE NS_IMETHOD HandleContent(const char *aContentType, nsIInterfaceRequestor *aWindowContext, nsIRequest *aRequest) = 0;

};

  NS_DEFINE_STATIC_IID_ACCESSOR(nsIContentHandler, NS_ICONTENTHANDLER_IID)

/* Use this macro when declaring classes that implement this interface. */
#define NS_DECL_NSICONTENTHANDLER \
  NS_SCRIPTABLE NS_IMETHOD HandleContent(const char *aContentType, nsIInterfaceRequestor *aWindowContext, nsIRequest *aRequest); 

/* Use this macro to declare functions that forward the behavior of this interface to another object. */
#define NS_FORWARD_NSICONTENTHANDLER(_to) \
  NS_SCRIPTABLE NS_IMETHOD HandleContent(const char *aContentType, nsIInterfaceRequestor *aWindowContext, nsIRequest *aRequest) { return _to HandleContent(aContentType, aWindowContext, aRequest); } 

/* Use this macro to declare functions that forward the behavior of this interface to another object in a safe way. */
#define NS_FORWARD_SAFE_NSICONTENTHANDLER(_to) \
  NS_SCRIPTABLE NS_IMETHOD HandleContent(const char *aContentType, nsIInterfaceRequestor *aWindowContext, nsIRequest *aRequest) { return !_to ? NS_ERROR_NULL_POINTER : _to->HandleContent(aContentType, aWindowContext, aRequest); } 

#if 0
/* Use the code below as a template for the implementation class for this interface. */

/* Header file */
class nsContentHandler : public nsIContentHandler
{
public:
  NS_DECL_ISUPPORTS
  NS_DECL_NSICONTENTHANDLER

  nsContentHandler();

private:
  ~nsContentHandler();

protected:
  /* additional members */
};

/* Implementation file */
NS_IMPL_ISUPPORTS1(nsContentHandler, nsIContentHandler)

nsContentHandler::nsContentHandler()
{
  /* member initializers and constructor code */
}

nsContentHandler::~nsContentHandler()
{
  /* destructor code */
}

/* void handleContent (in string aContentType, in nsIInterfaceRequestor aWindowContext, in nsIRequest aRequest); */
NS_IMETHODIMP nsContentHandler::HandleContent(const char *aContentType, nsIInterfaceRequestor *aWindowContext, nsIRequest *aRequest)
{
    return NS_ERROR_NOT_IMPLEMENTED;
}

/* End of implementation class template. */
#endif

#define NS_ERROR_WONT_HANDLE_CONTENT   NS_ERROR_GENERATE_FAILURE(NS_ERROR_MODULE_URILOADER, 1)

#endif /* __gen_nsIContentHandler_h__ */
