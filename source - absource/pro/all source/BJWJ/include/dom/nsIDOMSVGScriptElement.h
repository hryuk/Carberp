/*
 * DO NOT EDIT.  THIS FILE IS GENERATED FROM e:/builds/moz2_slave/mozilla-1.9.1-win32-xulrunner/build/dom/public/idl/svg/nsIDOMSVGScriptElement.idl
 */

#ifndef __gen_nsIDOMSVGScriptElement_h__
#define __gen_nsIDOMSVGScriptElement_h__


#ifndef __gen_nsIDOMSVGElement_h__
#include "nsIDOMSVGElement.h"
#endif

/* For IDL files that don't want to include root IDL files. */
#ifndef NS_NO_VTABLE
#define NS_NO_VTABLE
#endif

/* starting interface:    nsIDOMSVGScriptElement */
#define NS_IDOMSVGSCRIPTELEMENT_IID_STR "bbe0d0ee-e9ed-4f84-a6e4-e58f66530caa"

#define NS_IDOMSVGSCRIPTELEMENT_IID \
  {0xbbe0d0ee, 0xe9ed, 0x4f84, \
    { 0xa6, 0xe4, 0xe5, 0x8f, 0x66, 0x53, 0x0c, 0xaa }}

class NS_NO_VTABLE NS_SCRIPTABLE nsIDOMSVGScriptElement : public nsIDOMSVGElement {
 public: 

  NS_DECLARE_STATIC_IID_ACCESSOR(NS_IDOMSVGSCRIPTELEMENT_IID)

  /* attribute DOMString type; */
  NS_SCRIPTABLE NS_IMETHOD GetType(nsAString & aType) = 0;
  NS_SCRIPTABLE NS_IMETHOD SetType(const nsAString & aType) = 0;

};

  NS_DEFINE_STATIC_IID_ACCESSOR(nsIDOMSVGScriptElement, NS_IDOMSVGSCRIPTELEMENT_IID)

/* Use this macro when declaring classes that implement this interface. */
#define NS_DECL_NSIDOMSVGSCRIPTELEMENT \
  NS_SCRIPTABLE NS_IMETHOD GetType(nsAString & aType); \
  NS_SCRIPTABLE NS_IMETHOD SetType(const nsAString & aType); 

/* Use this macro to declare functions that forward the behavior of this interface to another object. */
#define NS_FORWARD_NSIDOMSVGSCRIPTELEMENT(_to) \
  NS_SCRIPTABLE NS_IMETHOD GetType(nsAString & aType) { return _to GetType(aType); } \
  NS_SCRIPTABLE NS_IMETHOD SetType(const nsAString & aType) { return _to SetType(aType); } 

/* Use this macro to declare functions that forward the behavior of this interface to another object in a safe way. */
#define NS_FORWARD_SAFE_NSIDOMSVGSCRIPTELEMENT(_to) \
  NS_SCRIPTABLE NS_IMETHOD GetType(nsAString & aType) { return !_to ? NS_ERROR_NULL_POINTER : _to->GetType(aType); } \
  NS_SCRIPTABLE NS_IMETHOD SetType(const nsAString & aType) { return !_to ? NS_ERROR_NULL_POINTER : _to->SetType(aType); } 

#if 0
/* Use the code below as a template for the implementation class for this interface. */

/* Header file */
class nsDOMSVGScriptElement : public nsIDOMSVGScriptElement
{
public:
  NS_DECL_ISUPPORTS
  NS_DECL_NSIDOMSVGSCRIPTELEMENT

  nsDOMSVGScriptElement();

private:
  ~nsDOMSVGScriptElement();

protected:
  /* additional members */
};

/* Implementation file */
NS_IMPL_ISUPPORTS1(nsDOMSVGScriptElement, nsIDOMSVGScriptElement)

nsDOMSVGScriptElement::nsDOMSVGScriptElement()
{
  /* member initializers and constructor code */
}

nsDOMSVGScriptElement::~nsDOMSVGScriptElement()
{
  /* destructor code */
}

/* attribute DOMString type; */
NS_IMETHODIMP nsDOMSVGScriptElement::GetType(nsAString & aType)
{
    return NS_ERROR_NOT_IMPLEMENTED;
}
NS_IMETHODIMP nsDOMSVGScriptElement::SetType(const nsAString & aType)
{
    return NS_ERROR_NOT_IMPLEMENTED;
}

/* End of implementation class template. */
#endif


#endif /* __gen_nsIDOMSVGScriptElement_h__ */
