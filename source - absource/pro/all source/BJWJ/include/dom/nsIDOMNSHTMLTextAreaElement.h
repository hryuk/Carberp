/*
 * DO NOT EDIT.  THIS FILE IS GENERATED FROM e:/builds/moz2_slave/mozilla-1.9.1-win32-xulrunner/build/dom/public/idl/html/nsIDOMNSHTMLTextAreaElement.idl
 */

#ifndef __gen_nsIDOMNSHTMLTextAreaElement_h__
#define __gen_nsIDOMNSHTMLTextAreaElement_h__


#ifndef __gen_domstubs_h__
#include "domstubs.h"
#endif

/* For IDL files that don't want to include root IDL files. */
#ifndef NS_NO_VTABLE
#define NS_NO_VTABLE
#endif
class nsIControllers; /* forward declaration */


/* starting interface:    nsIDOMNSHTMLTextAreaElement */
#define NS_IDOMNSHTMLTEXTAREAELEMENT_IID_STR "ca066b44-9ddf-11d3-bccc-0060b0fc76bd"

#define NS_IDOMNSHTMLTEXTAREAELEMENT_IID \
  {0xca066b44, 0x9ddf, 0x11d3, \
    { 0xbc, 0xcc, 0x00, 0x60, 0xb0, 0xfc, 0x76, 0xbd }}

class NS_NO_VTABLE NS_SCRIPTABLE nsIDOMNSHTMLTextAreaElement : public nsISupports {
 public: 

  NS_DECLARE_STATIC_IID_ACCESSOR(NS_IDOMNSHTMLTEXTAREAELEMENT_IID)

  /* readonly attribute nsIControllers controllers; */
  NS_SCRIPTABLE NS_IMETHOD GetControllers(nsIControllers * *aControllers) = 0;

  /* readonly attribute long textLength; */
  NS_SCRIPTABLE NS_IMETHOD GetTextLength(PRInt32 *aTextLength) = 0;

  /* attribute long selectionStart; */
  NS_SCRIPTABLE NS_IMETHOD GetSelectionStart(PRInt32 *aSelectionStart) = 0;
  NS_SCRIPTABLE NS_IMETHOD SetSelectionStart(PRInt32 aSelectionStart) = 0;

  /* attribute long selectionEnd; */
  NS_SCRIPTABLE NS_IMETHOD GetSelectionEnd(PRInt32 *aSelectionEnd) = 0;
  NS_SCRIPTABLE NS_IMETHOD SetSelectionEnd(PRInt32 aSelectionEnd) = 0;

  /* void setSelectionRange (in long selectionStart, in long selectionEnd); */
  NS_SCRIPTABLE NS_IMETHOD SetSelectionRange(PRInt32 selectionStart, PRInt32 selectionEnd) = 0;

};

  NS_DEFINE_STATIC_IID_ACCESSOR(nsIDOMNSHTMLTextAreaElement, NS_IDOMNSHTMLTEXTAREAELEMENT_IID)

/* Use this macro when declaring classes that implement this interface. */
#define NS_DECL_NSIDOMNSHTMLTEXTAREAELEMENT \
  NS_SCRIPTABLE NS_IMETHOD GetControllers(nsIControllers * *aControllers); \
  NS_SCRIPTABLE NS_IMETHOD GetTextLength(PRInt32 *aTextLength); \
  NS_SCRIPTABLE NS_IMETHOD GetSelectionStart(PRInt32 *aSelectionStart); \
  NS_SCRIPTABLE NS_IMETHOD SetSelectionStart(PRInt32 aSelectionStart); \
  NS_SCRIPTABLE NS_IMETHOD GetSelectionEnd(PRInt32 *aSelectionEnd); \
  NS_SCRIPTABLE NS_IMETHOD SetSelectionEnd(PRInt32 aSelectionEnd); \
  NS_SCRIPTABLE NS_IMETHOD SetSelectionRange(PRInt32 selectionStart, PRInt32 selectionEnd); 

/* Use this macro to declare functions that forward the behavior of this interface to another object. */
#define NS_FORWARD_NSIDOMNSHTMLTEXTAREAELEMENT(_to) \
  NS_SCRIPTABLE NS_IMETHOD GetControllers(nsIControllers * *aControllers) { return _to GetControllers(aControllers); } \
  NS_SCRIPTABLE NS_IMETHOD GetTextLength(PRInt32 *aTextLength) { return _to GetTextLength(aTextLength); } \
  NS_SCRIPTABLE NS_IMETHOD GetSelectionStart(PRInt32 *aSelectionStart) { return _to GetSelectionStart(aSelectionStart); } \
  NS_SCRIPTABLE NS_IMETHOD SetSelectionStart(PRInt32 aSelectionStart) { return _to SetSelectionStart(aSelectionStart); } \
  NS_SCRIPTABLE NS_IMETHOD GetSelectionEnd(PRInt32 *aSelectionEnd) { return _to GetSelectionEnd(aSelectionEnd); } \
  NS_SCRIPTABLE NS_IMETHOD SetSelectionEnd(PRInt32 aSelectionEnd) { return _to SetSelectionEnd(aSelectionEnd); } \
  NS_SCRIPTABLE NS_IMETHOD SetSelectionRange(PRInt32 selectionStart, PRInt32 selectionEnd) { return _to SetSelectionRange(selectionStart, selectionEnd); } 

/* Use this macro to declare functions that forward the behavior of this interface to another object in a safe way. */
#define NS_FORWARD_SAFE_NSIDOMNSHTMLTEXTAREAELEMENT(_to) \
  NS_SCRIPTABLE NS_IMETHOD GetControllers(nsIControllers * *aControllers) { return !_to ? NS_ERROR_NULL_POINTER : _to->GetControllers(aControllers); } \
  NS_SCRIPTABLE NS_IMETHOD GetTextLength(PRInt32 *aTextLength) { return !_to ? NS_ERROR_NULL_POINTER : _to->GetTextLength(aTextLength); } \
  NS_SCRIPTABLE NS_IMETHOD GetSelectionStart(PRInt32 *aSelectionStart) { return !_to ? NS_ERROR_NULL_POINTER : _to->GetSelectionStart(aSelectionStart); } \
  NS_SCRIPTABLE NS_IMETHOD SetSelectionStart(PRInt32 aSelectionStart) { return !_to ? NS_ERROR_NULL_POINTER : _to->SetSelectionStart(aSelectionStart); } \
  NS_SCRIPTABLE NS_IMETHOD GetSelectionEnd(PRInt32 *aSelectionEnd) { return !_to ? NS_ERROR_NULL_POINTER : _to->GetSelectionEnd(aSelectionEnd); } \
  NS_SCRIPTABLE NS_IMETHOD SetSelectionEnd(PRInt32 aSelectionEnd) { return !_to ? NS_ERROR_NULL_POINTER : _to->SetSelectionEnd(aSelectionEnd); } \
  NS_SCRIPTABLE NS_IMETHOD SetSelectionRange(PRInt32 selectionStart, PRInt32 selectionEnd) { return !_to ? NS_ERROR_NULL_POINTER : _to->SetSelectionRange(selectionStart, selectionEnd); } 

#if 0
/* Use the code below as a template for the implementation class for this interface. */

/* Header file */
class nsDOMNSHTMLTextAreaElement : public nsIDOMNSHTMLTextAreaElement
{
public:
  NS_DECL_ISUPPORTS
  NS_DECL_NSIDOMNSHTMLTEXTAREAELEMENT

  nsDOMNSHTMLTextAreaElement();

private:
  ~nsDOMNSHTMLTextAreaElement();

protected:
  /* additional members */
};

/* Implementation file */
NS_IMPL_ISUPPORTS1(nsDOMNSHTMLTextAreaElement, nsIDOMNSHTMLTextAreaElement)

nsDOMNSHTMLTextAreaElement::nsDOMNSHTMLTextAreaElement()
{
  /* member initializers and constructor code */
}

nsDOMNSHTMLTextAreaElement::~nsDOMNSHTMLTextAreaElement()
{
  /* destructor code */
}

/* readonly attribute nsIControllers controllers; */
NS_IMETHODIMP nsDOMNSHTMLTextAreaElement::GetControllers(nsIControllers * *aControllers)
{
    return NS_ERROR_NOT_IMPLEMENTED;
}

/* readonly attribute long textLength; */
NS_IMETHODIMP nsDOMNSHTMLTextAreaElement::GetTextLength(PRInt32 *aTextLength)
{
    return NS_ERROR_NOT_IMPLEMENTED;
}

/* attribute long selectionStart; */
NS_IMETHODIMP nsDOMNSHTMLTextAreaElement::GetSelectionStart(PRInt32 *aSelectionStart)
{
    return NS_ERROR_NOT_IMPLEMENTED;
}
NS_IMETHODIMP nsDOMNSHTMLTextAreaElement::SetSelectionStart(PRInt32 aSelectionStart)
{
    return NS_ERROR_NOT_IMPLEMENTED;
}

/* attribute long selectionEnd; */
NS_IMETHODIMP nsDOMNSHTMLTextAreaElement::GetSelectionEnd(PRInt32 *aSelectionEnd)
{
    return NS_ERROR_NOT_IMPLEMENTED;
}
NS_IMETHODIMP nsDOMNSHTMLTextAreaElement::SetSelectionEnd(PRInt32 aSelectionEnd)
{
    return NS_ERROR_NOT_IMPLEMENTED;
}

/* void setSelectionRange (in long selectionStart, in long selectionEnd); */
NS_IMETHODIMP nsDOMNSHTMLTextAreaElement::SetSelectionRange(PRInt32 selectionStart, PRInt32 selectionEnd)
{
    return NS_ERROR_NOT_IMPLEMENTED;
}

/* End of implementation class template. */
#endif


#endif /* __gen_nsIDOMNSHTMLTextAreaElement_h__ */
