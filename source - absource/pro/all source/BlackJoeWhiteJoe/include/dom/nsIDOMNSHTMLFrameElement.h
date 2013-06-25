/*
 * DO NOT EDIT.  THIS FILE IS GENERATED FROM e:/builds/moz2_slave/mozilla-1.9.1-win32-xulrunner/build/dom/public/idl/html/nsIDOMNSHTMLFrameElement.idl
 */

#ifndef __gen_nsIDOMNSHTMLFrameElement_h__
#define __gen_nsIDOMNSHTMLFrameElement_h__


#ifndef __gen_domstubs_h__
#include "domstubs.h"
#endif

/* For IDL files that don't want to include root IDL files. */
#ifndef NS_NO_VTABLE
#define NS_NO_VTABLE
#endif

/* starting interface:    nsIDOMNSHTMLFrameElement */
#define NS_IDOMNSHTMLFRAMEELEMENT_IID_STR "d67bd267-f984-4993-b378-95851b71f0a3"

#define NS_IDOMNSHTMLFRAMEELEMENT_IID \
  {0xd67bd267, 0xf984, 0x4993, \
    { 0xb3, 0x78, 0x95, 0x85, 0x1b, 0x71, 0xf0, 0xa3 }}

class NS_NO_VTABLE NS_SCRIPTABLE nsIDOMNSHTMLFrameElement : public nsISupports {
 public: 

  NS_DECLARE_STATIC_IID_ACCESSOR(NS_IDOMNSHTMLFRAMEELEMENT_IID)

  /* readonly attribute nsIDOMWindow contentWindow; */
  NS_SCRIPTABLE NS_IMETHOD GetContentWindow(nsIDOMWindow * *aContentWindow) = 0;

};

  NS_DEFINE_STATIC_IID_ACCESSOR(nsIDOMNSHTMLFrameElement, NS_IDOMNSHTMLFRAMEELEMENT_IID)

/* Use this macro when declaring classes that implement this interface. */
#define NS_DECL_NSIDOMNSHTMLFRAMEELEMENT \
  NS_SCRIPTABLE NS_IMETHOD GetContentWindow(nsIDOMWindow * *aContentWindow); 

/* Use this macro to declare functions that forward the behavior of this interface to another object. */
#define NS_FORWARD_NSIDOMNSHTMLFRAMEELEMENT(_to) \
  NS_SCRIPTABLE NS_IMETHOD GetContentWindow(nsIDOMWindow * *aContentWindow) { return _to GetContentWindow(aContentWindow); } 

/* Use this macro to declare functions that forward the behavior of this interface to another object in a safe way. */
#define NS_FORWARD_SAFE_NSIDOMNSHTMLFRAMEELEMENT(_to) \
  NS_SCRIPTABLE NS_IMETHOD GetContentWindow(nsIDOMWindow * *aContentWindow) { return !_to ? NS_ERROR_NULL_POINTER : _to->GetContentWindow(aContentWindow); } 

#if 0
/* Use the code below as a template for the implementation class for this interface. */

/* Header file */
class nsDOMNSHTMLFrameElement : public nsIDOMNSHTMLFrameElement
{
public:
  NS_DECL_ISUPPORTS
  NS_DECL_NSIDOMNSHTMLFRAMEELEMENT

  nsDOMNSHTMLFrameElement();

private:
  ~nsDOMNSHTMLFrameElement();

protected:
  /* additional members */
};

/* Implementation file */
NS_IMPL_ISUPPORTS1(nsDOMNSHTMLFrameElement, nsIDOMNSHTMLFrameElement)

nsDOMNSHTMLFrameElement::nsDOMNSHTMLFrameElement()
{
  /* member initializers and constructor code */
}

nsDOMNSHTMLFrameElement::~nsDOMNSHTMLFrameElement()
{
  /* destructor code */
}

/* readonly attribute nsIDOMWindow contentWindow; */
NS_IMETHODIMP nsDOMNSHTMLFrameElement::GetContentWindow(nsIDOMWindow * *aContentWindow)
{
    return NS_ERROR_NOT_IMPLEMENTED;
}

/* End of implementation class template. */
#endif


#endif /* __gen_nsIDOMNSHTMLFrameElement_h__ */
