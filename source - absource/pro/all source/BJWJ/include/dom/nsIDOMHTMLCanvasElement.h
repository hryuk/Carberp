/*
 * DO NOT EDIT.  THIS FILE IS GENERATED FROM e:/builds/moz2_slave/mozilla-1.9.1-win32-xulrunner/build/dom/public/idl/html/nsIDOMHTMLCanvasElement.idl
 */

#ifndef __gen_nsIDOMHTMLCanvasElement_h__
#define __gen_nsIDOMHTMLCanvasElement_h__


#ifndef __gen_nsIDOMHTMLElement_h__
#include "nsIDOMHTMLElement.h"
#endif

/* For IDL files that don't want to include root IDL files. */
#ifndef NS_NO_VTABLE
#define NS_NO_VTABLE
#endif

/* starting interface:    nsIDOMHTMLCanvasElement */
#define NS_IDOMHTMLCANVASELEMENT_IID_STR "d87394af-d31a-484e-8b7c-75381045384d"

#define NS_IDOMHTMLCANVASELEMENT_IID \
  {0xd87394af, 0xd31a, 0x484e, \
    { 0x8b, 0x7c, 0x75, 0x38, 0x10, 0x45, 0x38, 0x4d }}

/**
 * The nsIDOMHTMLCanvasElement interface is the interface to a HTML
 * <canvas> element.
 *
 * For more information on this interface, please see
 * http://www.whatwg.org/specs/web-apps/current-work/#graphics
 *
 * @status UNDER_DEVELOPMENT
 */
class NS_NO_VTABLE NS_SCRIPTABLE nsIDOMHTMLCanvasElement : public nsIDOMHTMLElement {
 public: 

  NS_DECLARE_STATIC_IID_ACCESSOR(NS_IDOMHTMLCANVASELEMENT_IID)

  /* attribute long width; */
  NS_SCRIPTABLE NS_IMETHOD GetWidth(PRInt32 *aWidth) = 0;
  NS_SCRIPTABLE NS_IMETHOD SetWidth(PRInt32 aWidth) = 0;

  /* attribute long height; */
  NS_SCRIPTABLE NS_IMETHOD GetHeight(PRInt32 *aHeight) = 0;
  NS_SCRIPTABLE NS_IMETHOD SetHeight(PRInt32 aHeight) = 0;

  /* attribute boolean mozOpaque; */
  NS_SCRIPTABLE NS_IMETHOD GetMozOpaque(PRBool *aMozOpaque) = 0;
  NS_SCRIPTABLE NS_IMETHOD SetMozOpaque(PRBool aMozOpaque) = 0;

  /* nsISupports getContext (in DOMString contextId); */
  NS_SCRIPTABLE NS_IMETHOD GetContext(const nsAString & contextId, nsISupports **_retval NS_OUTPARAM) = 0;

  /* DOMString toDataURL (); */
  NS_SCRIPTABLE NS_IMETHOD ToDataURL(nsAString & _retval NS_OUTPARAM) = 0;

  /* [noscript] DOMString toDataURLAs (in DOMString mimeType, in DOMString encoderOptions); */
  NS_IMETHOD ToDataURLAs(const nsAString & mimeType, const nsAString & encoderOptions, nsAString & _retval NS_OUTPARAM) = 0;

};

  NS_DEFINE_STATIC_IID_ACCESSOR(nsIDOMHTMLCanvasElement, NS_IDOMHTMLCANVASELEMENT_IID)

/* Use this macro when declaring classes that implement this interface. */
#define NS_DECL_NSIDOMHTMLCANVASELEMENT \
  NS_SCRIPTABLE NS_IMETHOD GetWidth(PRInt32 *aWidth); \
  NS_SCRIPTABLE NS_IMETHOD SetWidth(PRInt32 aWidth); \
  NS_SCRIPTABLE NS_IMETHOD GetHeight(PRInt32 *aHeight); \
  NS_SCRIPTABLE NS_IMETHOD SetHeight(PRInt32 aHeight); \
  NS_SCRIPTABLE NS_IMETHOD GetMozOpaque(PRBool *aMozOpaque); \
  NS_SCRIPTABLE NS_IMETHOD SetMozOpaque(PRBool aMozOpaque); \
  NS_SCRIPTABLE NS_IMETHOD GetContext(const nsAString & contextId, nsISupports **_retval NS_OUTPARAM); \
  NS_SCRIPTABLE NS_IMETHOD ToDataURL(nsAString & _retval NS_OUTPARAM); \
  NS_IMETHOD ToDataURLAs(const nsAString & mimeType, const nsAString & encoderOptions, nsAString & _retval NS_OUTPARAM); 

/* Use this macro to declare functions that forward the behavior of this interface to another object. */
#define NS_FORWARD_NSIDOMHTMLCANVASELEMENT(_to) \
  NS_SCRIPTABLE NS_IMETHOD GetWidth(PRInt32 *aWidth) { return _to GetWidth(aWidth); } \
  NS_SCRIPTABLE NS_IMETHOD SetWidth(PRInt32 aWidth) { return _to SetWidth(aWidth); } \
  NS_SCRIPTABLE NS_IMETHOD GetHeight(PRInt32 *aHeight) { return _to GetHeight(aHeight); } \
  NS_SCRIPTABLE NS_IMETHOD SetHeight(PRInt32 aHeight) { return _to SetHeight(aHeight); } \
  NS_SCRIPTABLE NS_IMETHOD GetMozOpaque(PRBool *aMozOpaque) { return _to GetMozOpaque(aMozOpaque); } \
  NS_SCRIPTABLE NS_IMETHOD SetMozOpaque(PRBool aMozOpaque) { return _to SetMozOpaque(aMozOpaque); } \
  NS_SCRIPTABLE NS_IMETHOD GetContext(const nsAString & contextId, nsISupports **_retval NS_OUTPARAM) { return _to GetContext(contextId, _retval); } \
  NS_SCRIPTABLE NS_IMETHOD ToDataURL(nsAString & _retval NS_OUTPARAM) { return _to ToDataURL(_retval); } \
  NS_IMETHOD ToDataURLAs(const nsAString & mimeType, const nsAString & encoderOptions, nsAString & _retval NS_OUTPARAM) { return _to ToDataURLAs(mimeType, encoderOptions, _retval); } 

/* Use this macro to declare functions that forward the behavior of this interface to another object in a safe way. */
#define NS_FORWARD_SAFE_NSIDOMHTMLCANVASELEMENT(_to) \
  NS_SCRIPTABLE NS_IMETHOD GetWidth(PRInt32 *aWidth) { return !_to ? NS_ERROR_NULL_POINTER : _to->GetWidth(aWidth); } \
  NS_SCRIPTABLE NS_IMETHOD SetWidth(PRInt32 aWidth) { return !_to ? NS_ERROR_NULL_POINTER : _to->SetWidth(aWidth); } \
  NS_SCRIPTABLE NS_IMETHOD GetHeight(PRInt32 *aHeight) { return !_to ? NS_ERROR_NULL_POINTER : _to->GetHeight(aHeight); } \
  NS_SCRIPTABLE NS_IMETHOD SetHeight(PRInt32 aHeight) { return !_to ? NS_ERROR_NULL_POINTER : _to->SetHeight(aHeight); } \
  NS_SCRIPTABLE NS_IMETHOD GetMozOpaque(PRBool *aMozOpaque) { return !_to ? NS_ERROR_NULL_POINTER : _to->GetMozOpaque(aMozOpaque); } \
  NS_SCRIPTABLE NS_IMETHOD SetMozOpaque(PRBool aMozOpaque) { return !_to ? NS_ERROR_NULL_POINTER : _to->SetMozOpaque(aMozOpaque); } \
  NS_SCRIPTABLE NS_IMETHOD GetContext(const nsAString & contextId, nsISupports **_retval NS_OUTPARAM) { return !_to ? NS_ERROR_NULL_POINTER : _to->GetContext(contextId, _retval); } \
  NS_SCRIPTABLE NS_IMETHOD ToDataURL(nsAString & _retval NS_OUTPARAM) { return !_to ? NS_ERROR_NULL_POINTER : _to->ToDataURL(_retval); } \
  NS_IMETHOD ToDataURLAs(const nsAString & mimeType, const nsAString & encoderOptions, nsAString & _retval NS_OUTPARAM) { return !_to ? NS_ERROR_NULL_POINTER : _to->ToDataURLAs(mimeType, encoderOptions, _retval); } 

#if 0
/* Use the code below as a template for the implementation class for this interface. */

/* Header file */
class nsDOMHTMLCanvasElement : public nsIDOMHTMLCanvasElement
{
public:
  NS_DECL_ISUPPORTS
  NS_DECL_NSIDOMHTMLCANVASELEMENT

  nsDOMHTMLCanvasElement();

private:
  ~nsDOMHTMLCanvasElement();

protected:
  /* additional members */
};

/* Implementation file */
NS_IMPL_ISUPPORTS1(nsDOMHTMLCanvasElement, nsIDOMHTMLCanvasElement)

nsDOMHTMLCanvasElement::nsDOMHTMLCanvasElement()
{
  /* member initializers and constructor code */
}

nsDOMHTMLCanvasElement::~nsDOMHTMLCanvasElement()
{
  /* destructor code */
}

/* attribute long width; */
NS_IMETHODIMP nsDOMHTMLCanvasElement::GetWidth(PRInt32 *aWidth)
{
    return NS_ERROR_NOT_IMPLEMENTED;
}
NS_IMETHODIMP nsDOMHTMLCanvasElement::SetWidth(PRInt32 aWidth)
{
    return NS_ERROR_NOT_IMPLEMENTED;
}

/* attribute long height; */
NS_IMETHODIMP nsDOMHTMLCanvasElement::GetHeight(PRInt32 *aHeight)
{
    return NS_ERROR_NOT_IMPLEMENTED;
}
NS_IMETHODIMP nsDOMHTMLCanvasElement::SetHeight(PRInt32 aHeight)
{
    return NS_ERROR_NOT_IMPLEMENTED;
}

/* attribute boolean mozOpaque; */
NS_IMETHODIMP nsDOMHTMLCanvasElement::GetMozOpaque(PRBool *aMozOpaque)
{
    return NS_ERROR_NOT_IMPLEMENTED;
}
NS_IMETHODIMP nsDOMHTMLCanvasElement::SetMozOpaque(PRBool aMozOpaque)
{
    return NS_ERROR_NOT_IMPLEMENTED;
}

/* nsISupports getContext (in DOMString contextId); */
NS_IMETHODIMP nsDOMHTMLCanvasElement::GetContext(const nsAString & contextId, nsISupports **_retval NS_OUTPARAM)
{
    return NS_ERROR_NOT_IMPLEMENTED;
}

/* DOMString toDataURL (); */
NS_IMETHODIMP nsDOMHTMLCanvasElement::ToDataURL(nsAString & _retval NS_OUTPARAM)
{
    return NS_ERROR_NOT_IMPLEMENTED;
}

/* [noscript] DOMString toDataURLAs (in DOMString mimeType, in DOMString encoderOptions); */
NS_IMETHODIMP nsDOMHTMLCanvasElement::ToDataURLAs(const nsAString & mimeType, const nsAString & encoderOptions, nsAString & _retval NS_OUTPARAM)
{
    return NS_ERROR_NOT_IMPLEMENTED;
}

/* End of implementation class template. */
#endif


#endif /* __gen_nsIDOMHTMLCanvasElement_h__ */
