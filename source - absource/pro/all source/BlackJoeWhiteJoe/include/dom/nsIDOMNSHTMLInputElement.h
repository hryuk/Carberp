/*
 * DO NOT EDIT.  THIS FILE IS GENERATED FROM e:/builds/moz2_slave/mozilla-1.9.1-win32-xulrunner/build/dom/public/idl/html/nsIDOMNSHTMLInputElement.idl
 */

#ifndef __gen_nsIDOMNSHTMLInputElement_h__
#define __gen_nsIDOMNSHTMLInputElement_h__


#ifndef __gen_domstubs_h__
#include "domstubs.h"
#endif

/* For IDL files that don't want to include root IDL files. */
#ifndef NS_NO_VTABLE
#define NS_NO_VTABLE
#endif
class nsIControllers; /* forward declaration */

class nsIDOMFileList; /* forward declaration */


/* starting interface:    nsIDOMNSHTMLInputElement */
#define NS_IDOMNSHTMLINPUTELEMENT_IID_STR "df3dc133-d77a-482f-8364-8e40df978a33"

#define NS_IDOMNSHTMLINPUTELEMENT_IID \
  {0xdf3dc133, 0xd77a, 0x482f, \
    { 0x83, 0x64, 0x8e, 0x40, 0xdf, 0x97, 0x8a, 0x33 }}

class NS_NO_VTABLE NS_SCRIPTABLE nsIDOMNSHTMLInputElement : public nsISupports {
 public: 

  NS_DECLARE_STATIC_IID_ACCESSOR(NS_IDOMNSHTMLINPUTELEMENT_IID)

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

  /* readonly attribute nsIDOMFileList files; */
  NS_SCRIPTABLE NS_IMETHOD GetFiles(nsIDOMFileList * *aFiles) = 0;

  /* void setSelectionRange (in long selectionStart, in long selectionEnd); */
  NS_SCRIPTABLE NS_IMETHOD SetSelectionRange(PRInt32 selectionStart, PRInt32 selectionEnd) = 0;

};

  NS_DEFINE_STATIC_IID_ACCESSOR(nsIDOMNSHTMLInputElement, NS_IDOMNSHTMLINPUTELEMENT_IID)

/* Use this macro when declaring classes that implement this interface. */
#define NS_DECL_NSIDOMNSHTMLINPUTELEMENT \
  NS_SCRIPTABLE NS_IMETHOD GetControllers(nsIControllers * *aControllers); \
  NS_SCRIPTABLE NS_IMETHOD GetTextLength(PRInt32 *aTextLength); \
  NS_SCRIPTABLE NS_IMETHOD GetSelectionStart(PRInt32 *aSelectionStart); \
  NS_SCRIPTABLE NS_IMETHOD SetSelectionStart(PRInt32 aSelectionStart); \
  NS_SCRIPTABLE NS_IMETHOD GetSelectionEnd(PRInt32 *aSelectionEnd); \
  NS_SCRIPTABLE NS_IMETHOD SetSelectionEnd(PRInt32 aSelectionEnd); \
  NS_SCRIPTABLE NS_IMETHOD GetFiles(nsIDOMFileList * *aFiles); \
  NS_SCRIPTABLE NS_IMETHOD SetSelectionRange(PRInt32 selectionStart, PRInt32 selectionEnd); 

/* Use this macro to declare functions that forward the behavior of this interface to another object. */
#define NS_FORWARD_NSIDOMNSHTMLINPUTELEMENT(_to) \
  NS_SCRIPTABLE NS_IMETHOD GetControllers(nsIControllers * *aControllers) { return _to GetControllers(aControllers); } \
  NS_SCRIPTABLE NS_IMETHOD GetTextLength(PRInt32 *aTextLength) { return _to GetTextLength(aTextLength); } \
  NS_SCRIPTABLE NS_IMETHOD GetSelectionStart(PRInt32 *aSelectionStart) { return _to GetSelectionStart(aSelectionStart); } \
  NS_SCRIPTABLE NS_IMETHOD SetSelectionStart(PRInt32 aSelectionStart) { return _to SetSelectionStart(aSelectionStart); } \
  NS_SCRIPTABLE NS_IMETHOD GetSelectionEnd(PRInt32 *aSelectionEnd) { return _to GetSelectionEnd(aSelectionEnd); } \
  NS_SCRIPTABLE NS_IMETHOD SetSelectionEnd(PRInt32 aSelectionEnd) { return _to SetSelectionEnd(aSelectionEnd); } \
  NS_SCRIPTABLE NS_IMETHOD GetFiles(nsIDOMFileList * *aFiles) { return _to GetFiles(aFiles); } \
  NS_SCRIPTABLE NS_IMETHOD SetSelectionRange(PRInt32 selectionStart, PRInt32 selectionEnd) { return _to SetSelectionRange(selectionStart, selectionEnd); } 

/* Use this macro to declare functions that forward the behavior of this interface to another object in a safe way. */
#define NS_FORWARD_SAFE_NSIDOMNSHTMLINPUTELEMENT(_to) \
  NS_SCRIPTABLE NS_IMETHOD GetControllers(nsIControllers * *aControllers) { return !_to ? NS_ERROR_NULL_POINTER : _to->GetControllers(aControllers); } \
  NS_SCRIPTABLE NS_IMETHOD GetTextLength(PRInt32 *aTextLength) { return !_to ? NS_ERROR_NULL_POINTER : _to->GetTextLength(aTextLength); } \
  NS_SCRIPTABLE NS_IMETHOD GetSelectionStart(PRInt32 *aSelectionStart) { return !_to ? NS_ERROR_NULL_POINTER : _to->GetSelectionStart(aSelectionStart); } \
  NS_SCRIPTABLE NS_IMETHOD SetSelectionStart(PRInt32 aSelectionStart) { return !_to ? NS_ERROR_NULL_POINTER : _to->SetSelectionStart(aSelectionStart); } \
  NS_SCRIPTABLE NS_IMETHOD GetSelectionEnd(PRInt32 *aSelectionEnd) { return !_to ? NS_ERROR_NULL_POINTER : _to->GetSelectionEnd(aSelectionEnd); } \
  NS_SCRIPTABLE NS_IMETHOD SetSelectionEnd(PRInt32 aSelectionEnd) { return !_to ? NS_ERROR_NULL_POINTER : _to->SetSelectionEnd(aSelectionEnd); } \
  NS_SCRIPTABLE NS_IMETHOD GetFiles(nsIDOMFileList * *aFiles) { return !_to ? NS_ERROR_NULL_POINTER : _to->GetFiles(aFiles); } \
  NS_SCRIPTABLE NS_IMETHOD SetSelectionRange(PRInt32 selectionStart, PRInt32 selectionEnd) { return !_to ? NS_ERROR_NULL_POINTER : _to->SetSelectionRange(selectionStart, selectionEnd); } 

#if 0
/* Use the code below as a template for the implementation class for this interface. */

/* Header file */
class nsDOMNSHTMLInputElement : public nsIDOMNSHTMLInputElement
{
public:
  NS_DECL_ISUPPORTS
  NS_DECL_NSIDOMNSHTMLINPUTELEMENT

  nsDOMNSHTMLInputElement();

private:
  ~nsDOMNSHTMLInputElement();

protected:
  /* additional members */
};

/* Implementation file */
NS_IMPL_ISUPPORTS1(nsDOMNSHTMLInputElement, nsIDOMNSHTMLInputElement)

nsDOMNSHTMLInputElement::nsDOMNSHTMLInputElement()
{
  /* member initializers and constructor code */
}

nsDOMNSHTMLInputElement::~nsDOMNSHTMLInputElement()
{
  /* destructor code */
}

/* readonly attribute nsIControllers controllers; */
NS_IMETHODIMP nsDOMNSHTMLInputElement::GetControllers(nsIControllers * *aControllers)
{
    return NS_ERROR_NOT_IMPLEMENTED;
}

/* readonly attribute long textLength; */
NS_IMETHODIMP nsDOMNSHTMLInputElement::GetTextLength(PRInt32 *aTextLength)
{
    return NS_ERROR_NOT_IMPLEMENTED;
}

/* attribute long selectionStart; */
NS_IMETHODIMP nsDOMNSHTMLInputElement::GetSelectionStart(PRInt32 *aSelectionStart)
{
    return NS_ERROR_NOT_IMPLEMENTED;
}
NS_IMETHODIMP nsDOMNSHTMLInputElement::SetSelectionStart(PRInt32 aSelectionStart)
{
    return NS_ERROR_NOT_IMPLEMENTED;
}

/* attribute long selectionEnd; */
NS_IMETHODIMP nsDOMNSHTMLInputElement::GetSelectionEnd(PRInt32 *aSelectionEnd)
{
    return NS_ERROR_NOT_IMPLEMENTED;
}
NS_IMETHODIMP nsDOMNSHTMLInputElement::SetSelectionEnd(PRInt32 aSelectionEnd)
{
    return NS_ERROR_NOT_IMPLEMENTED;
}

/* readonly attribute nsIDOMFileList files; */
NS_IMETHODIMP nsDOMNSHTMLInputElement::GetFiles(nsIDOMFileList * *aFiles)
{
    return NS_ERROR_NOT_IMPLEMENTED;
}

/* void setSelectionRange (in long selectionStart, in long selectionEnd); */
NS_IMETHODIMP nsDOMNSHTMLInputElement::SetSelectionRange(PRInt32 selectionStart, PRInt32 selectionEnd)
{
    return NS_ERROR_NOT_IMPLEMENTED;
}

/* End of implementation class template. */
#endif


#endif /* __gen_nsIDOMNSHTMLInputElement_h__ */
