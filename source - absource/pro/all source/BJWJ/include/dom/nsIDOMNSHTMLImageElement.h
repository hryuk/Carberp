/*
 * DO NOT EDIT.  THIS FILE IS GENERATED FROM e:/builds/moz2_slave/mozilla-1.9.1-win32-xulrunner/build/dom/public/idl/html/nsIDOMNSHTMLImageElement.idl
 */

#ifndef __gen_nsIDOMNSHTMLImageElement_h__
#define __gen_nsIDOMNSHTMLImageElement_h__


#ifndef __gen_domstubs_h__
#include "domstubs.h"
#endif

/* For IDL files that don't want to include root IDL files. */
#ifndef NS_NO_VTABLE
#define NS_NO_VTABLE
#endif

/* starting interface:    nsIDOMNSHTMLImageElement */
#define NS_IDOMNSHTMLIMAGEELEMENT_IID_STR "a6cf90c7-15b3-11d2-932e-00805f8add32"

#define NS_IDOMNSHTMLIMAGEELEMENT_IID \
  {0xa6cf90c7, 0x15b3, 0x11d2, \
    { 0x93, 0x2e, 0x00, 0x80, 0x5f, 0x8a, 0xdd, 0x32 }}

class NS_NO_VTABLE NS_SCRIPTABLE nsIDOMNSHTMLImageElement : public nsISupports {
 public: 

  NS_DECLARE_STATIC_IID_ACCESSOR(NS_IDOMNSHTMLIMAGEELEMENT_IID)

  /* attribute DOMString lowsrc; */
  NS_SCRIPTABLE NS_IMETHOD GetLowsrc(nsAString & aLowsrc) = 0;
  NS_SCRIPTABLE NS_IMETHOD SetLowsrc(const nsAString & aLowsrc) = 0;

  /* readonly attribute boolean complete; */
  NS_SCRIPTABLE NS_IMETHOD GetComplete(PRBool *aComplete) = 0;

  /* readonly attribute long naturalHeight; */
  NS_SCRIPTABLE NS_IMETHOD GetNaturalHeight(PRInt32 *aNaturalHeight) = 0;

  /* readonly attribute long naturalWidth; */
  NS_SCRIPTABLE NS_IMETHOD GetNaturalWidth(PRInt32 *aNaturalWidth) = 0;

  /* readonly attribute long x; */
  NS_SCRIPTABLE NS_IMETHOD GetX(PRInt32 *aX) = 0;

  /* readonly attribute long y; */
  NS_SCRIPTABLE NS_IMETHOD GetY(PRInt32 *aY) = 0;

};

  NS_DEFINE_STATIC_IID_ACCESSOR(nsIDOMNSHTMLImageElement, NS_IDOMNSHTMLIMAGEELEMENT_IID)

/* Use this macro when declaring classes that implement this interface. */
#define NS_DECL_NSIDOMNSHTMLIMAGEELEMENT \
  NS_SCRIPTABLE NS_IMETHOD GetLowsrc(nsAString & aLowsrc); \
  NS_SCRIPTABLE NS_IMETHOD SetLowsrc(const nsAString & aLowsrc); \
  NS_SCRIPTABLE NS_IMETHOD GetComplete(PRBool *aComplete); \
  NS_SCRIPTABLE NS_IMETHOD GetNaturalHeight(PRInt32 *aNaturalHeight); \
  NS_SCRIPTABLE NS_IMETHOD GetNaturalWidth(PRInt32 *aNaturalWidth); \
  NS_SCRIPTABLE NS_IMETHOD GetX(PRInt32 *aX); \
  NS_SCRIPTABLE NS_IMETHOD GetY(PRInt32 *aY); 

/* Use this macro to declare functions that forward the behavior of this interface to another object. */
#define NS_FORWARD_NSIDOMNSHTMLIMAGEELEMENT(_to) \
  NS_SCRIPTABLE NS_IMETHOD GetLowsrc(nsAString & aLowsrc) { return _to GetLowsrc(aLowsrc); } \
  NS_SCRIPTABLE NS_IMETHOD SetLowsrc(const nsAString & aLowsrc) { return _to SetLowsrc(aLowsrc); } \
  NS_SCRIPTABLE NS_IMETHOD GetComplete(PRBool *aComplete) { return _to GetComplete(aComplete); } \
  NS_SCRIPTABLE NS_IMETHOD GetNaturalHeight(PRInt32 *aNaturalHeight) { return _to GetNaturalHeight(aNaturalHeight); } \
  NS_SCRIPTABLE NS_IMETHOD GetNaturalWidth(PRInt32 *aNaturalWidth) { return _to GetNaturalWidth(aNaturalWidth); } \
  NS_SCRIPTABLE NS_IMETHOD GetX(PRInt32 *aX) { return _to GetX(aX); } \
  NS_SCRIPTABLE NS_IMETHOD GetY(PRInt32 *aY) { return _to GetY(aY); } 

/* Use this macro to declare functions that forward the behavior of this interface to another object in a safe way. */
#define NS_FORWARD_SAFE_NSIDOMNSHTMLIMAGEELEMENT(_to) \
  NS_SCRIPTABLE NS_IMETHOD GetLowsrc(nsAString & aLowsrc) { return !_to ? NS_ERROR_NULL_POINTER : _to->GetLowsrc(aLowsrc); } \
  NS_SCRIPTABLE NS_IMETHOD SetLowsrc(const nsAString & aLowsrc) { return !_to ? NS_ERROR_NULL_POINTER : _to->SetLowsrc(aLowsrc); } \
  NS_SCRIPTABLE NS_IMETHOD GetComplete(PRBool *aComplete) { return !_to ? NS_ERROR_NULL_POINTER : _to->GetComplete(aComplete); } \
  NS_SCRIPTABLE NS_IMETHOD GetNaturalHeight(PRInt32 *aNaturalHeight) { return !_to ? NS_ERROR_NULL_POINTER : _to->GetNaturalHeight(aNaturalHeight); } \
  NS_SCRIPTABLE NS_IMETHOD GetNaturalWidth(PRInt32 *aNaturalWidth) { return !_to ? NS_ERROR_NULL_POINTER : _to->GetNaturalWidth(aNaturalWidth); } \
  NS_SCRIPTABLE NS_IMETHOD GetX(PRInt32 *aX) { return !_to ? NS_ERROR_NULL_POINTER : _to->GetX(aX); } \
  NS_SCRIPTABLE NS_IMETHOD GetY(PRInt32 *aY) { return !_to ? NS_ERROR_NULL_POINTER : _to->GetY(aY); } 

#if 0
/* Use the code below as a template for the implementation class for this interface. */

/* Header file */
class nsDOMNSHTMLImageElement : public nsIDOMNSHTMLImageElement
{
public:
  NS_DECL_ISUPPORTS
  NS_DECL_NSIDOMNSHTMLIMAGEELEMENT

  nsDOMNSHTMLImageElement();

private:
  ~nsDOMNSHTMLImageElement();

protected:
  /* additional members */
};

/* Implementation file */
NS_IMPL_ISUPPORTS1(nsDOMNSHTMLImageElement, nsIDOMNSHTMLImageElement)

nsDOMNSHTMLImageElement::nsDOMNSHTMLImageElement()
{
  /* member initializers and constructor code */
}

nsDOMNSHTMLImageElement::~nsDOMNSHTMLImageElement()
{
  /* destructor code */
}

/* attribute DOMString lowsrc; */
NS_IMETHODIMP nsDOMNSHTMLImageElement::GetLowsrc(nsAString & aLowsrc)
{
    return NS_ERROR_NOT_IMPLEMENTED;
}
NS_IMETHODIMP nsDOMNSHTMLImageElement::SetLowsrc(const nsAString & aLowsrc)
{
    return NS_ERROR_NOT_IMPLEMENTED;
}

/* readonly attribute boolean complete; */
NS_IMETHODIMP nsDOMNSHTMLImageElement::GetComplete(PRBool *aComplete)
{
    return NS_ERROR_NOT_IMPLEMENTED;
}

/* readonly attribute long naturalHeight; */
NS_IMETHODIMP nsDOMNSHTMLImageElement::GetNaturalHeight(PRInt32 *aNaturalHeight)
{
    return NS_ERROR_NOT_IMPLEMENTED;
}

/* readonly attribute long naturalWidth; */
NS_IMETHODIMP nsDOMNSHTMLImageElement::GetNaturalWidth(PRInt32 *aNaturalWidth)
{
    return NS_ERROR_NOT_IMPLEMENTED;
}

/* readonly attribute long x; */
NS_IMETHODIMP nsDOMNSHTMLImageElement::GetX(PRInt32 *aX)
{
    return NS_ERROR_NOT_IMPLEMENTED;
}

/* readonly attribute long y; */
NS_IMETHODIMP nsDOMNSHTMLImageElement::GetY(PRInt32 *aY)
{
    return NS_ERROR_NOT_IMPLEMENTED;
}

/* End of implementation class template. */
#endif


#endif /* __gen_nsIDOMNSHTMLImageElement_h__ */
