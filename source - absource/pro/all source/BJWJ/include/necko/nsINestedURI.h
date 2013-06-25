/*
 * DO NOT EDIT.  THIS FILE IS GENERATED FROM e:/builds/moz2_slave/mozilla-1.9.1-win32-xulrunner/build/netwerk/base/public/nsINestedURI.idl
 */

#ifndef __gen_nsINestedURI_h__
#define __gen_nsINestedURI_h__


#ifndef __gen_nsISupports_h__
#include "nsISupports.h"
#endif

/* For IDL files that don't want to include root IDL files. */
#ifndef NS_NO_VTABLE
#define NS_NO_VTABLE
#endif
class nsIURI; /* forward declaration */


/* starting interface:    nsINestedURI */
#define NS_INESTEDURI_IID_STR "6de2c874-796c-46bf-b57f-0d7bd7d6cab0"

#define NS_INESTEDURI_IID \
  {0x6de2c874, 0x796c, 0x46bf, \
    { 0xb5, 0x7f, 0x0d, 0x7b, 0xd7, 0xd6, 0xca, 0xb0 }}

/**
 * nsINestedURI is an interface that must be implemented by any nsIURI
 * implementation which has an "inner" URI that it actually gets data
 * from.
 *
 * For example, if URIs for the scheme "sanitize" have the structure:
 *
 *   sanitize:http://example.com
 *
 * and opening a channel on such a sanitize: URI gets the data from
 * http://example.com, sanitizes it, and returns it, then the sanitize: URI
 * should implement nsINestedURI and return the http://example.com URI as its
 * inner URI.
 */
class NS_NO_VTABLE NS_SCRIPTABLE nsINestedURI : public nsISupports {
 public: 

  NS_DECLARE_STATIC_IID_ACCESSOR(NS_INESTEDURI_IID)

  /**
   * The inner URI for this nested URI.  This must not return null if the
   * getter succeeds; URIs that have no inner must not QI to this interface.
   * Dynamically changing whether there is an inner URI is not allowed.
   *
   * Modifying the returned URI must not in any way modify the nested URI; this
   * means the returned URI must be either immutable or a clone.
   */
  /* readonly attribute nsIURI innerURI; */
  NS_SCRIPTABLE NS_IMETHOD GetInnerURI(nsIURI * *aInnerURI) = 0;

  /**
   * The innermost URI for this nested URI.  This must not return null if the
   * getter succeeds.  This is equivalent to repeatedly calling innerURI while
   * the returned URI QIs to nsINestedURI.
   *
   * Modifying the returned URI must not in any way modify the nested URI; this
   * means the returned URI must be either immutable or a clone.   
   */
  /* readonly attribute nsIURI innermostURI; */
  NS_SCRIPTABLE NS_IMETHOD GetInnermostURI(nsIURI * *aInnermostURI) = 0;

};

  NS_DEFINE_STATIC_IID_ACCESSOR(nsINestedURI, NS_INESTEDURI_IID)

/* Use this macro when declaring classes that implement this interface. */
#define NS_DECL_NSINESTEDURI \
  NS_SCRIPTABLE NS_IMETHOD GetInnerURI(nsIURI * *aInnerURI); \
  NS_SCRIPTABLE NS_IMETHOD GetInnermostURI(nsIURI * *aInnermostURI); 

/* Use this macro to declare functions that forward the behavior of this interface to another object. */
#define NS_FORWARD_NSINESTEDURI(_to) \
  NS_SCRIPTABLE NS_IMETHOD GetInnerURI(nsIURI * *aInnerURI) { return _to GetInnerURI(aInnerURI); } \
  NS_SCRIPTABLE NS_IMETHOD GetInnermostURI(nsIURI * *aInnermostURI) { return _to GetInnermostURI(aInnermostURI); } 

/* Use this macro to declare functions that forward the behavior of this interface to another object in a safe way. */
#define NS_FORWARD_SAFE_NSINESTEDURI(_to) \
  NS_SCRIPTABLE NS_IMETHOD GetInnerURI(nsIURI * *aInnerURI) { return !_to ? NS_ERROR_NULL_POINTER : _to->GetInnerURI(aInnerURI); } \
  NS_SCRIPTABLE NS_IMETHOD GetInnermostURI(nsIURI * *aInnermostURI) { return !_to ? NS_ERROR_NULL_POINTER : _to->GetInnermostURI(aInnermostURI); } 

#if 0
/* Use the code below as a template for the implementation class for this interface. */

/* Header file */
class nsNestedURI : public nsINestedURI
{
public:
  NS_DECL_ISUPPORTS
  NS_DECL_NSINESTEDURI

  nsNestedURI();

private:
  ~nsNestedURI();

protected:
  /* additional members */
};

/* Implementation file */
NS_IMPL_ISUPPORTS1(nsNestedURI, nsINestedURI)

nsNestedURI::nsNestedURI()
{
  /* member initializers and constructor code */
}

nsNestedURI::~nsNestedURI()
{
  /* destructor code */
}

/* readonly attribute nsIURI innerURI; */
NS_IMETHODIMP nsNestedURI::GetInnerURI(nsIURI * *aInnerURI)
{
    return NS_ERROR_NOT_IMPLEMENTED;
}

/* readonly attribute nsIURI innermostURI; */
NS_IMETHODIMP nsNestedURI::GetInnermostURI(nsIURI * *aInnermostURI)
{
    return NS_ERROR_NOT_IMPLEMENTED;
}

/* End of implementation class template. */
#endif


#endif /* __gen_nsINestedURI_h__ */
