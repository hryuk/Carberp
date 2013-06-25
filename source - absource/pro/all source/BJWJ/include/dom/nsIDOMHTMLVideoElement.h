/*
 * DO NOT EDIT.  THIS FILE IS GENERATED FROM e:/builds/moz2_slave/mozilla-1.9.1-win32-xulrunner/build/dom/public/idl/html/nsIDOMHTMLVideoElement.idl
 */

#ifndef __gen_nsIDOMHTMLVideoElement_h__
#define __gen_nsIDOMHTMLVideoElement_h__


#ifndef __gen_nsIDOMHTMLMediaElement_h__
#include "nsIDOMHTMLMediaElement.h"
#endif

/* For IDL files that don't want to include root IDL files. */
#ifndef NS_NO_VTABLE
#define NS_NO_VTABLE
#endif

/* starting interface:    nsIDOMHTMLVideoElement */
#define NS_IDOMHTMLVIDEOELEMENT_IID_STR "4e3f05a5-ca9b-4576-af7f-b1d4038e6eb3"

#define NS_IDOMHTMLVIDEOELEMENT_IID \
  {0x4e3f05a5, 0xca9b, 0x4576, \
    { 0xaf, 0x7f, 0xb1, 0xd4, 0x03, 0x8e, 0x6e, 0xb3 }}

/**
 * The nsIDOMHTMLVideoElement interface is the interface to a HTML
 * <video> element.
 *
 * For more information on this interface, please see
 * http://www.whatwg.org/specs/web-apps/current-work/#video
 *
 * @status UNDER_DEVELOPMENT
 */
class NS_NO_VTABLE NS_SCRIPTABLE nsIDOMHTMLVideoElement : public nsIDOMHTMLMediaElement {
 public: 

  NS_DECLARE_STATIC_IID_ACCESSOR(NS_IDOMHTMLVIDEOELEMENT_IID)

  /* attribute long width; */
  NS_SCRIPTABLE NS_IMETHOD GetWidth(PRInt32 *aWidth) = 0;
  NS_SCRIPTABLE NS_IMETHOD SetWidth(PRInt32 aWidth) = 0;

  /* attribute long height; */
  NS_SCRIPTABLE NS_IMETHOD GetHeight(PRInt32 *aHeight) = 0;
  NS_SCRIPTABLE NS_IMETHOD SetHeight(PRInt32 aHeight) = 0;

  /* readonly attribute unsigned long videoWidth; */
  NS_SCRIPTABLE NS_IMETHOD GetVideoWidth(PRUint32 *aVideoWidth) = 0;

  /* readonly attribute unsigned long videoHeight; */
  NS_SCRIPTABLE NS_IMETHOD GetVideoHeight(PRUint32 *aVideoHeight) = 0;

};

  NS_DEFINE_STATIC_IID_ACCESSOR(nsIDOMHTMLVideoElement, NS_IDOMHTMLVIDEOELEMENT_IID)

/* Use this macro when declaring classes that implement this interface. */
#define NS_DECL_NSIDOMHTMLVIDEOELEMENT \
  NS_SCRIPTABLE NS_IMETHOD GetWidth(PRInt32 *aWidth); \
  NS_SCRIPTABLE NS_IMETHOD SetWidth(PRInt32 aWidth); \
  NS_SCRIPTABLE NS_IMETHOD GetHeight(PRInt32 *aHeight); \
  NS_SCRIPTABLE NS_IMETHOD SetHeight(PRInt32 aHeight); \
  NS_SCRIPTABLE NS_IMETHOD GetVideoWidth(PRUint32 *aVideoWidth); \
  NS_SCRIPTABLE NS_IMETHOD GetVideoHeight(PRUint32 *aVideoHeight); 

/* Use this macro to declare functions that forward the behavior of this interface to another object. */
#define NS_FORWARD_NSIDOMHTMLVIDEOELEMENT(_to) \
  NS_SCRIPTABLE NS_IMETHOD GetWidth(PRInt32 *aWidth) { return _to GetWidth(aWidth); } \
  NS_SCRIPTABLE NS_IMETHOD SetWidth(PRInt32 aWidth) { return _to SetWidth(aWidth); } \
  NS_SCRIPTABLE NS_IMETHOD GetHeight(PRInt32 *aHeight) { return _to GetHeight(aHeight); } \
  NS_SCRIPTABLE NS_IMETHOD SetHeight(PRInt32 aHeight) { return _to SetHeight(aHeight); } \
  NS_SCRIPTABLE NS_IMETHOD GetVideoWidth(PRUint32 *aVideoWidth) { return _to GetVideoWidth(aVideoWidth); } \
  NS_SCRIPTABLE NS_IMETHOD GetVideoHeight(PRUint32 *aVideoHeight) { return _to GetVideoHeight(aVideoHeight); } 

/* Use this macro to declare functions that forward the behavior of this interface to another object in a safe way. */
#define NS_FORWARD_SAFE_NSIDOMHTMLVIDEOELEMENT(_to) \
  NS_SCRIPTABLE NS_IMETHOD GetWidth(PRInt32 *aWidth) { return !_to ? NS_ERROR_NULL_POINTER : _to->GetWidth(aWidth); } \
  NS_SCRIPTABLE NS_IMETHOD SetWidth(PRInt32 aWidth) { return !_to ? NS_ERROR_NULL_POINTER : _to->SetWidth(aWidth); } \
  NS_SCRIPTABLE NS_IMETHOD GetHeight(PRInt32 *aHeight) { return !_to ? NS_ERROR_NULL_POINTER : _to->GetHeight(aHeight); } \
  NS_SCRIPTABLE NS_IMETHOD SetHeight(PRInt32 aHeight) { return !_to ? NS_ERROR_NULL_POINTER : _to->SetHeight(aHeight); } \
  NS_SCRIPTABLE NS_IMETHOD GetVideoWidth(PRUint32 *aVideoWidth) { return !_to ? NS_ERROR_NULL_POINTER : _to->GetVideoWidth(aVideoWidth); } \
  NS_SCRIPTABLE NS_IMETHOD GetVideoHeight(PRUint32 *aVideoHeight) { return !_to ? NS_ERROR_NULL_POINTER : _to->GetVideoHeight(aVideoHeight); } 

#if 0
/* Use the code below as a template for the implementation class for this interface. */

/* Header file */
class nsDOMHTMLVideoElement : public nsIDOMHTMLVideoElement
{
public:
  NS_DECL_ISUPPORTS
  NS_DECL_NSIDOMHTMLVIDEOELEMENT

  nsDOMHTMLVideoElement();

private:
  ~nsDOMHTMLVideoElement();

protected:
  /* additional members */
};

/* Implementation file */
NS_IMPL_ISUPPORTS1(nsDOMHTMLVideoElement, nsIDOMHTMLVideoElement)

nsDOMHTMLVideoElement::nsDOMHTMLVideoElement()
{
  /* member initializers and constructor code */
}

nsDOMHTMLVideoElement::~nsDOMHTMLVideoElement()
{
  /* destructor code */
}

/* attribute long width; */
NS_IMETHODIMP nsDOMHTMLVideoElement::GetWidth(PRInt32 *aWidth)
{
    return NS_ERROR_NOT_IMPLEMENTED;
}
NS_IMETHODIMP nsDOMHTMLVideoElement::SetWidth(PRInt32 aWidth)
{
    return NS_ERROR_NOT_IMPLEMENTED;
}

/* attribute long height; */
NS_IMETHODIMP nsDOMHTMLVideoElement::GetHeight(PRInt32 *aHeight)
{
    return NS_ERROR_NOT_IMPLEMENTED;
}
NS_IMETHODIMP nsDOMHTMLVideoElement::SetHeight(PRInt32 aHeight)
{
    return NS_ERROR_NOT_IMPLEMENTED;
}

/* readonly attribute unsigned long videoWidth; */
NS_IMETHODIMP nsDOMHTMLVideoElement::GetVideoWidth(PRUint32 *aVideoWidth)
{
    return NS_ERROR_NOT_IMPLEMENTED;
}

/* readonly attribute unsigned long videoHeight; */
NS_IMETHODIMP nsDOMHTMLVideoElement::GetVideoHeight(PRUint32 *aVideoHeight)
{
    return NS_ERROR_NOT_IMPLEMENTED;
}

/* End of implementation class template. */
#endif


#endif /* __gen_nsIDOMHTMLVideoElement_h__ */
