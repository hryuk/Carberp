/*
 * DO NOT EDIT.  THIS FILE IS GENERATED FROM e:/builds/moz2_slave/mozilla-1.9.1-win32-xulrunner/build/docshell/base/nsILoadContext.idl
 */

#ifndef __gen_nsILoadContext_h__
#define __gen_nsILoadContext_h__


#ifndef __gen_nsISupports_h__
#include "nsISupports.h"
#endif

/* For IDL files that don't want to include root IDL files. */
#ifndef NS_NO_VTABLE
#define NS_NO_VTABLE
#endif
class nsIDOMWindow; /* forward declaration */


/* starting interface:    nsILoadContext */
#define NS_ILOADCONTEXT_IID_STR "314d8a54-1caf-4721-94d7-f6c82d9b82ed"

#define NS_ILOADCONTEXT_IID \
  {0x314d8a54, 0x1caf, 0x4721, \
    { 0x94, 0xd7, 0xf6, 0xc8, 0x2d, 0x9b, 0x82, 0xed }}

/**
 * An nsILoadContext represents the context of a load.  This interface
 * can be queried for various information about where the load is
 * happening.
 */
class NS_NO_VTABLE NS_SCRIPTABLE nsILoadContext : public nsISupports {
 public: 

  NS_DECLARE_STATIC_IID_ACCESSOR(NS_ILOADCONTEXT_IID)

  /**
   * associatedWindow is the window with which the load is associated, if any.
   * Note that the load may be triggered by a document which is different from
   * the document in associatedWindow, and in fact the source of the load need
   * not be same-origin with the document in associatedWindow.  This attribute
   * may be null if there is no associated window.
   */
  /* readonly attribute nsIDOMWindow associatedWindow; */
  NS_SCRIPTABLE NS_IMETHOD GetAssociatedWindow(nsIDOMWindow * *aAssociatedWindow) = 0;

  /**
   * topWindow is the top window which is of same type as associatedWindow.
   * This is equivalent to associatedWindow.top, but is provided here as a
   * convenience.  All the same caveats as associatedWindow of apply, of
   * course.  This attribute may be null if there is no associated window.
   */
  /* readonly attribute nsIDOMWindow topWindow; */
  NS_SCRIPTABLE NS_IMETHOD GetTopWindow(nsIDOMWindow * *aTopWindow) = 0;

  /**
   * Check whether the load is happening in a particular type of application.
   *
   * @param an application type.  For now, the constants to be passed here are
   *        the nsIDocShell APP_TYPE_* constants.
   *
   * @return whether there is some ancestor of the associatedWindow that is of
   *         the given app type.
   */
  /* boolean isAppOfType (in unsigned long appType); */
  NS_SCRIPTABLE NS_IMETHOD IsAppOfType(PRUint32 appType, PRBool *_retval NS_OUTPARAM) = 0;

  /**
   * True if the load context is content (as opposed to chrome).  This is
   * determined based on the type of window the load is performed in, NOT based
   * on any URIs that might be around.
   */
  /* readonly attribute boolean isContent; */
  NS_SCRIPTABLE NS_IMETHOD GetIsContent(PRBool *aIsContent) = 0;

};

  NS_DEFINE_STATIC_IID_ACCESSOR(nsILoadContext, NS_ILOADCONTEXT_IID)

/* Use this macro when declaring classes that implement this interface. */
#define NS_DECL_NSILOADCONTEXT \
  NS_SCRIPTABLE NS_IMETHOD GetAssociatedWindow(nsIDOMWindow * *aAssociatedWindow); \
  NS_SCRIPTABLE NS_IMETHOD GetTopWindow(nsIDOMWindow * *aTopWindow); \
  NS_SCRIPTABLE NS_IMETHOD IsAppOfType(PRUint32 appType, PRBool *_retval NS_OUTPARAM); \
  NS_SCRIPTABLE NS_IMETHOD GetIsContent(PRBool *aIsContent); 

/* Use this macro to declare functions that forward the behavior of this interface to another object. */
#define NS_FORWARD_NSILOADCONTEXT(_to) \
  NS_SCRIPTABLE NS_IMETHOD GetAssociatedWindow(nsIDOMWindow * *aAssociatedWindow) { return _to GetAssociatedWindow(aAssociatedWindow); } \
  NS_SCRIPTABLE NS_IMETHOD GetTopWindow(nsIDOMWindow * *aTopWindow) { return _to GetTopWindow(aTopWindow); } \
  NS_SCRIPTABLE NS_IMETHOD IsAppOfType(PRUint32 appType, PRBool *_retval NS_OUTPARAM) { return _to IsAppOfType(appType, _retval); } \
  NS_SCRIPTABLE NS_IMETHOD GetIsContent(PRBool *aIsContent) { return _to GetIsContent(aIsContent); } 

/* Use this macro to declare functions that forward the behavior of this interface to another object in a safe way. */
#define NS_FORWARD_SAFE_NSILOADCONTEXT(_to) \
  NS_SCRIPTABLE NS_IMETHOD GetAssociatedWindow(nsIDOMWindow * *aAssociatedWindow) { return !_to ? NS_ERROR_NULL_POINTER : _to->GetAssociatedWindow(aAssociatedWindow); } \
  NS_SCRIPTABLE NS_IMETHOD GetTopWindow(nsIDOMWindow * *aTopWindow) { return !_to ? NS_ERROR_NULL_POINTER : _to->GetTopWindow(aTopWindow); } \
  NS_SCRIPTABLE NS_IMETHOD IsAppOfType(PRUint32 appType, PRBool *_retval NS_OUTPARAM) { return !_to ? NS_ERROR_NULL_POINTER : _to->IsAppOfType(appType, _retval); } \
  NS_SCRIPTABLE NS_IMETHOD GetIsContent(PRBool *aIsContent) { return !_to ? NS_ERROR_NULL_POINTER : _to->GetIsContent(aIsContent); } 

#if 0
/* Use the code below as a template for the implementation class for this interface. */

/* Header file */
class nsLoadContext : public nsILoadContext
{
public:
  NS_DECL_ISUPPORTS
  NS_DECL_NSILOADCONTEXT

  nsLoadContext();

private:
  ~nsLoadContext();

protected:
  /* additional members */
};

/* Implementation file */
NS_IMPL_ISUPPORTS1(nsLoadContext, nsILoadContext)

nsLoadContext::nsLoadContext()
{
  /* member initializers and constructor code */
}

nsLoadContext::~nsLoadContext()
{
  /* destructor code */
}

/* readonly attribute nsIDOMWindow associatedWindow; */
NS_IMETHODIMP nsLoadContext::GetAssociatedWindow(nsIDOMWindow * *aAssociatedWindow)
{
    return NS_ERROR_NOT_IMPLEMENTED;
}

/* readonly attribute nsIDOMWindow topWindow; */
NS_IMETHODIMP nsLoadContext::GetTopWindow(nsIDOMWindow * *aTopWindow)
{
    return NS_ERROR_NOT_IMPLEMENTED;
}

/* boolean isAppOfType (in unsigned long appType); */
NS_IMETHODIMP nsLoadContext::IsAppOfType(PRUint32 appType, PRBool *_retval NS_OUTPARAM)
{
    return NS_ERROR_NOT_IMPLEMENTED;
}

/* readonly attribute boolean isContent; */
NS_IMETHODIMP nsLoadContext::GetIsContent(PRBool *aIsContent)
{
    return NS_ERROR_NOT_IMPLEMENTED;
}

/* End of implementation class template. */
#endif


#endif /* __gen_nsILoadContext_h__ */
