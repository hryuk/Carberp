/*
 * DO NOT EDIT.  THIS FILE IS GENERATED FROM e:/builds/moz2_slave/mozilla-1.9.1-win32-xulrunner/build/dom/public/idl/svg/nsIDOMSVGDocument.idl
 */

#ifndef __gen_nsIDOMSVGDocument_h__
#define __gen_nsIDOMSVGDocument_h__


#ifndef __gen_nsIDOMDocument_h__
#include "nsIDOMDocument.h"
#endif

/* For IDL files that don't want to include root IDL files. */
#ifndef NS_NO_VTABLE
#define NS_NO_VTABLE
#endif
class nsIDOMSVGSVGElement; /* forward declaration */


/* starting interface:    nsIDOMSVGDocument */
#define NS_IDOMSVGDOCUMENT_IID_STR "12d3b664-1dd2-11b2-a7cf-ceee7e90f396"

#define NS_IDOMSVGDOCUMENT_IID \
  {0x12d3b664, 0x1dd2, 0x11b2, \
    { 0xa7, 0xcf, 0xce, 0xee, 0x7e, 0x90, 0xf3, 0x96 }}

class NS_NO_VTABLE NS_SCRIPTABLE nsIDOMSVGDocument : public nsIDOMDocument {
 public: 

  NS_DECLARE_STATIC_IID_ACCESSOR(NS_IDOMSVGDOCUMENT_IID)

  /* readonly attribute DOMString title; */
  NS_SCRIPTABLE NS_IMETHOD GetTitle(nsAString & aTitle) = 0;

  /* readonly attribute DOMString referrer; */
  NS_SCRIPTABLE NS_IMETHOD GetReferrer(nsAString & aReferrer) = 0;

  /* readonly attribute DOMString domain; */
  NS_SCRIPTABLE NS_IMETHOD GetDomain(nsAString & aDomain) = 0;

  /* readonly attribute DOMString URL; */
  NS_SCRIPTABLE NS_IMETHOD GetURL(nsAString & aURL) = 0;

  /* readonly attribute nsIDOMSVGSVGElement rootElement; */
  NS_SCRIPTABLE NS_IMETHOD GetRootElement(nsIDOMSVGSVGElement * *aRootElement) = 0;

};

  NS_DEFINE_STATIC_IID_ACCESSOR(nsIDOMSVGDocument, NS_IDOMSVGDOCUMENT_IID)

/* Use this macro when declaring classes that implement this interface. */
#define NS_DECL_NSIDOMSVGDOCUMENT \
  NS_SCRIPTABLE NS_IMETHOD GetTitle(nsAString & aTitle); \
  NS_SCRIPTABLE NS_IMETHOD GetReferrer(nsAString & aReferrer); \
  NS_SCRIPTABLE NS_IMETHOD GetDomain(nsAString & aDomain); \
  NS_SCRIPTABLE NS_IMETHOD GetURL(nsAString & aURL); \
  NS_SCRIPTABLE NS_IMETHOD GetRootElement(nsIDOMSVGSVGElement * *aRootElement); 

/* Use this macro to declare functions that forward the behavior of this interface to another object. */
#define NS_FORWARD_NSIDOMSVGDOCUMENT(_to) \
  NS_SCRIPTABLE NS_IMETHOD GetTitle(nsAString & aTitle) { return _to GetTitle(aTitle); } \
  NS_SCRIPTABLE NS_IMETHOD GetReferrer(nsAString & aReferrer) { return _to GetReferrer(aReferrer); } \
  NS_SCRIPTABLE NS_IMETHOD GetDomain(nsAString & aDomain) { return _to GetDomain(aDomain); } \
  NS_SCRIPTABLE NS_IMETHOD GetURL(nsAString & aURL) { return _to GetURL(aURL); } \
  NS_SCRIPTABLE NS_IMETHOD GetRootElement(nsIDOMSVGSVGElement * *aRootElement) { return _to GetRootElement(aRootElement); } 

/* Use this macro to declare functions that forward the behavior of this interface to another object in a safe way. */
#define NS_FORWARD_SAFE_NSIDOMSVGDOCUMENT(_to) \
  NS_SCRIPTABLE NS_IMETHOD GetTitle(nsAString & aTitle) { return !_to ? NS_ERROR_NULL_POINTER : _to->GetTitle(aTitle); } \
  NS_SCRIPTABLE NS_IMETHOD GetReferrer(nsAString & aReferrer) { return !_to ? NS_ERROR_NULL_POINTER : _to->GetReferrer(aReferrer); } \
  NS_SCRIPTABLE NS_IMETHOD GetDomain(nsAString & aDomain) { return !_to ? NS_ERROR_NULL_POINTER : _to->GetDomain(aDomain); } \
  NS_SCRIPTABLE NS_IMETHOD GetURL(nsAString & aURL) { return !_to ? NS_ERROR_NULL_POINTER : _to->GetURL(aURL); } \
  NS_SCRIPTABLE NS_IMETHOD GetRootElement(nsIDOMSVGSVGElement * *aRootElement) { return !_to ? NS_ERROR_NULL_POINTER : _to->GetRootElement(aRootElement); } 

#if 0
/* Use the code below as a template for the implementation class for this interface. */

/* Header file */
class nsDOMSVGDocument : public nsIDOMSVGDocument
{
public:
  NS_DECL_ISUPPORTS
  NS_DECL_NSIDOMSVGDOCUMENT

  nsDOMSVGDocument();

private:
  ~nsDOMSVGDocument();

protected:
  /* additional members */
};

/* Implementation file */
NS_IMPL_ISUPPORTS1(nsDOMSVGDocument, nsIDOMSVGDocument)

nsDOMSVGDocument::nsDOMSVGDocument()
{
  /* member initializers and constructor code */
}

nsDOMSVGDocument::~nsDOMSVGDocument()
{
  /* destructor code */
}

/* readonly attribute DOMString title; */
NS_IMETHODIMP nsDOMSVGDocument::GetTitle(nsAString & aTitle)
{
    return NS_ERROR_NOT_IMPLEMENTED;
}

/* readonly attribute DOMString referrer; */
NS_IMETHODIMP nsDOMSVGDocument::GetReferrer(nsAString & aReferrer)
{
    return NS_ERROR_NOT_IMPLEMENTED;
}

/* readonly attribute DOMString domain; */
NS_IMETHODIMP nsDOMSVGDocument::GetDomain(nsAString & aDomain)
{
    return NS_ERROR_NOT_IMPLEMENTED;
}

/* readonly attribute DOMString URL; */
NS_IMETHODIMP nsDOMSVGDocument::GetURL(nsAString & aURL)
{
    return NS_ERROR_NOT_IMPLEMENTED;
}

/* readonly attribute nsIDOMSVGSVGElement rootElement; */
NS_IMETHODIMP nsDOMSVGDocument::GetRootElement(nsIDOMSVGSVGElement * *aRootElement)
{
    return NS_ERROR_NOT_IMPLEMENTED;
}

/* End of implementation class template. */
#endif


#endif /* __gen_nsIDOMSVGDocument_h__ */
