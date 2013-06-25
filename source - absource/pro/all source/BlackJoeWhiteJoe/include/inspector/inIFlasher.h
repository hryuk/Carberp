/*
 * DO NOT EDIT.  THIS FILE IS GENERATED FROM e:/builds/moz2_slave/mozilla-1.9.1-win32-xulrunner/build/layout/inspector/public/inIFlasher.idl
 */

#ifndef __gen_inIFlasher_h__
#define __gen_inIFlasher_h__


#ifndef __gen_nsISupports_h__
#include "nsISupports.h"
#endif

/* For IDL files that don't want to include root IDL files. */
#ifndef NS_NO_VTABLE
#define NS_NO_VTABLE
#endif
class nsIDOMDocument; /* forward declaration */

class nsIDOMElement; /* forward declaration */

class nsIDOMWindowInternal; /* forward declaration */


/* starting interface:    inIFlasher */
#define INIFLASHER_IID_STR "7b4a099f-6f6e-4565-977b-fb622adbff49"

#define INIFLASHER_IID \
  {0x7b4a099f, 0x6f6e, 0x4565, \
    { 0x97, 0x7b, 0xfb, 0x62, 0x2a, 0xdb, 0xff, 0x49 }}

class NS_NO_VTABLE NS_SCRIPTABLE inIFlasher : public nsISupports {
 public: 

  NS_DECLARE_STATIC_IID_ACCESSOR(INIFLASHER_IID)

  /* attribute DOMString color; */
  NS_SCRIPTABLE NS_IMETHOD GetColor(nsAString & aColor) = 0;
  NS_SCRIPTABLE NS_IMETHOD SetColor(const nsAString & aColor) = 0;

  /* attribute boolean invert; */
  NS_SCRIPTABLE NS_IMETHOD GetInvert(PRBool *aInvert) = 0;
  NS_SCRIPTABLE NS_IMETHOD SetInvert(PRBool aInvert) = 0;

  /* attribute unsigned short thickness; */
  NS_SCRIPTABLE NS_IMETHOD GetThickness(PRUint16 *aThickness) = 0;
  NS_SCRIPTABLE NS_IMETHOD SetThickness(PRUint16 aThickness) = 0;

  /* void drawElementOutline (in nsIDOMElement aElement); */
  NS_SCRIPTABLE NS_IMETHOD DrawElementOutline(nsIDOMElement *aElement) = 0;

  /* void repaintElement (in nsIDOMElement aElement); */
  NS_SCRIPTABLE NS_IMETHOD RepaintElement(nsIDOMElement *aElement) = 0;

  /* void scrollElementIntoView (in nsIDOMElement aElement); */
  NS_SCRIPTABLE NS_IMETHOD ScrollElementIntoView(nsIDOMElement *aElement) = 0;

};

  NS_DEFINE_STATIC_IID_ACCESSOR(inIFlasher, INIFLASHER_IID)

/* Use this macro when declaring classes that implement this interface. */
#define NS_DECL_INIFLASHER \
  NS_SCRIPTABLE NS_IMETHOD GetColor(nsAString & aColor); \
  NS_SCRIPTABLE NS_IMETHOD SetColor(const nsAString & aColor); \
  NS_SCRIPTABLE NS_IMETHOD GetInvert(PRBool *aInvert); \
  NS_SCRIPTABLE NS_IMETHOD SetInvert(PRBool aInvert); \
  NS_SCRIPTABLE NS_IMETHOD GetThickness(PRUint16 *aThickness); \
  NS_SCRIPTABLE NS_IMETHOD SetThickness(PRUint16 aThickness); \
  NS_SCRIPTABLE NS_IMETHOD DrawElementOutline(nsIDOMElement *aElement); \
  NS_SCRIPTABLE NS_IMETHOD RepaintElement(nsIDOMElement *aElement); \
  NS_SCRIPTABLE NS_IMETHOD ScrollElementIntoView(nsIDOMElement *aElement); 

/* Use this macro to declare functions that forward the behavior of this interface to another object. */
#define NS_FORWARD_INIFLASHER(_to) \
  NS_SCRIPTABLE NS_IMETHOD GetColor(nsAString & aColor) { return _to GetColor(aColor); } \
  NS_SCRIPTABLE NS_IMETHOD SetColor(const nsAString & aColor) { return _to SetColor(aColor); } \
  NS_SCRIPTABLE NS_IMETHOD GetInvert(PRBool *aInvert) { return _to GetInvert(aInvert); } \
  NS_SCRIPTABLE NS_IMETHOD SetInvert(PRBool aInvert) { return _to SetInvert(aInvert); } \
  NS_SCRIPTABLE NS_IMETHOD GetThickness(PRUint16 *aThickness) { return _to GetThickness(aThickness); } \
  NS_SCRIPTABLE NS_IMETHOD SetThickness(PRUint16 aThickness) { return _to SetThickness(aThickness); } \
  NS_SCRIPTABLE NS_IMETHOD DrawElementOutline(nsIDOMElement *aElement) { return _to DrawElementOutline(aElement); } \
  NS_SCRIPTABLE NS_IMETHOD RepaintElement(nsIDOMElement *aElement) { return _to RepaintElement(aElement); } \
  NS_SCRIPTABLE NS_IMETHOD ScrollElementIntoView(nsIDOMElement *aElement) { return _to ScrollElementIntoView(aElement); } 

/* Use this macro to declare functions that forward the behavior of this interface to another object in a safe way. */
#define NS_FORWARD_SAFE_INIFLASHER(_to) \
  NS_SCRIPTABLE NS_IMETHOD GetColor(nsAString & aColor) { return !_to ? NS_ERROR_NULL_POINTER : _to->GetColor(aColor); } \
  NS_SCRIPTABLE NS_IMETHOD SetColor(const nsAString & aColor) { return !_to ? NS_ERROR_NULL_POINTER : _to->SetColor(aColor); } \
  NS_SCRIPTABLE NS_IMETHOD GetInvert(PRBool *aInvert) { return !_to ? NS_ERROR_NULL_POINTER : _to->GetInvert(aInvert); } \
  NS_SCRIPTABLE NS_IMETHOD SetInvert(PRBool aInvert) { return !_to ? NS_ERROR_NULL_POINTER : _to->SetInvert(aInvert); } \
  NS_SCRIPTABLE NS_IMETHOD GetThickness(PRUint16 *aThickness) { return !_to ? NS_ERROR_NULL_POINTER : _to->GetThickness(aThickness); } \
  NS_SCRIPTABLE NS_IMETHOD SetThickness(PRUint16 aThickness) { return !_to ? NS_ERROR_NULL_POINTER : _to->SetThickness(aThickness); } \
  NS_SCRIPTABLE NS_IMETHOD DrawElementOutline(nsIDOMElement *aElement) { return !_to ? NS_ERROR_NULL_POINTER : _to->DrawElementOutline(aElement); } \
  NS_SCRIPTABLE NS_IMETHOD RepaintElement(nsIDOMElement *aElement) { return !_to ? NS_ERROR_NULL_POINTER : _to->RepaintElement(aElement); } \
  NS_SCRIPTABLE NS_IMETHOD ScrollElementIntoView(nsIDOMElement *aElement) { return !_to ? NS_ERROR_NULL_POINTER : _to->ScrollElementIntoView(aElement); } 

#if 0
/* Use the code below as a template for the implementation class for this interface. */

/* Header file */
class inFlasher : public inIFlasher
{
public:
  NS_DECL_ISUPPORTS
  NS_DECL_INIFLASHER

  inFlasher();

private:
  ~inFlasher();

protected:
  /* additional members */
};

/* Implementation file */
NS_IMPL_ISUPPORTS1(inFlasher, inIFlasher)

inFlasher::inFlasher()
{
  /* member initializers and constructor code */
}

inFlasher::~inFlasher()
{
  /* destructor code */
}

/* attribute DOMString color; */
NS_IMETHODIMP inFlasher::GetColor(nsAString & aColor)
{
    return NS_ERROR_NOT_IMPLEMENTED;
}
NS_IMETHODIMP inFlasher::SetColor(const nsAString & aColor)
{
    return NS_ERROR_NOT_IMPLEMENTED;
}

/* attribute boolean invert; */
NS_IMETHODIMP inFlasher::GetInvert(PRBool *aInvert)
{
    return NS_ERROR_NOT_IMPLEMENTED;
}
NS_IMETHODIMP inFlasher::SetInvert(PRBool aInvert)
{
    return NS_ERROR_NOT_IMPLEMENTED;
}

/* attribute unsigned short thickness; */
NS_IMETHODIMP inFlasher::GetThickness(PRUint16 *aThickness)
{
    return NS_ERROR_NOT_IMPLEMENTED;
}
NS_IMETHODIMP inFlasher::SetThickness(PRUint16 aThickness)
{
    return NS_ERROR_NOT_IMPLEMENTED;
}

/* void drawElementOutline (in nsIDOMElement aElement); */
NS_IMETHODIMP inFlasher::DrawElementOutline(nsIDOMElement *aElement)
{
    return NS_ERROR_NOT_IMPLEMENTED;
}

/* void repaintElement (in nsIDOMElement aElement); */
NS_IMETHODIMP inFlasher::RepaintElement(nsIDOMElement *aElement)
{
    return NS_ERROR_NOT_IMPLEMENTED;
}

/* void scrollElementIntoView (in nsIDOMElement aElement); */
NS_IMETHODIMP inFlasher::ScrollElementIntoView(nsIDOMElement *aElement)
{
    return NS_ERROR_NOT_IMPLEMENTED;
}

/* End of implementation class template. */
#endif


#endif /* __gen_inIFlasher_h__ */
