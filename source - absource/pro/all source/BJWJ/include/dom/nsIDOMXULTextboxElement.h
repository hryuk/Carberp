/*
 * DO NOT EDIT.  THIS FILE IS GENERATED FROM e:/builds/moz2_slave/mozilla-1.9.1-win32-xulrunner/build/dom/public/idl/xul/nsIDOMXULTextboxElement.idl
 */

#ifndef __gen_nsIDOMXULTextboxElement_h__
#define __gen_nsIDOMXULTextboxElement_h__


#ifndef __gen_nsIDOMXULLabeledControlEl_h__
#include "nsIDOMXULLabeledControlEl.h"
#endif

/* For IDL files that don't want to include root IDL files. */
#ifndef NS_NO_VTABLE
#define NS_NO_VTABLE
#endif
class nsIDOMHTMLInputElement; /* forward declaration */


/* starting interface:    nsIDOMXULTextBoxElement */
#define NS_IDOMXULTEXTBOXELEMENT_IID_STR "71135b6c-294e-4634-a8e4-a72398f1e72a"

#define NS_IDOMXULTEXTBOXELEMENT_IID \
  {0x71135b6c, 0x294e, 0x4634, \
    { 0xa8, 0xe4, 0xa7, 0x23, 0x98, 0xf1, 0xe7, 0x2a }}

class NS_NO_VTABLE NS_SCRIPTABLE nsIDOMXULTextBoxElement : public nsIDOMXULControlElement {
 public: 

  NS_DECLARE_STATIC_IID_ACCESSOR(NS_IDOMXULTEXTBOXELEMENT_IID)

  /* readonly attribute nsIDOMNode inputField; */
  NS_SCRIPTABLE NS_IMETHOD GetInputField(nsIDOMNode * *aInputField) = 0;

  /* readonly attribute long textLength; */
  NS_SCRIPTABLE NS_IMETHOD GetTextLength(PRInt32 *aTextLength) = 0;

  /* attribute long maxLength; */
  NS_SCRIPTABLE NS_IMETHOD GetMaxLength(PRInt32 *aMaxLength) = 0;
  NS_SCRIPTABLE NS_IMETHOD SetMaxLength(PRInt32 aMaxLength) = 0;

  /* attribute long size; */
  NS_SCRIPTABLE NS_IMETHOD GetSize(PRInt32 *aSize) = 0;
  NS_SCRIPTABLE NS_IMETHOD SetSize(PRInt32 aSize) = 0;

  /* attribute long selectionStart; */
  NS_SCRIPTABLE NS_IMETHOD GetSelectionStart(PRInt32 *aSelectionStart) = 0;
  NS_SCRIPTABLE NS_IMETHOD SetSelectionStart(PRInt32 aSelectionStart) = 0;

  /* attribute long selectionEnd; */
  NS_SCRIPTABLE NS_IMETHOD GetSelectionEnd(PRInt32 *aSelectionEnd) = 0;
  NS_SCRIPTABLE NS_IMETHOD SetSelectionEnd(PRInt32 aSelectionEnd) = 0;

  /* attribute DOMString value; */
  NS_SCRIPTABLE NS_IMETHOD GetValue(nsAString & aValue) = 0;
  NS_SCRIPTABLE NS_IMETHOD SetValue(const nsAString & aValue) = 0;

  /* attribute DOMString type; */
  NS_SCRIPTABLE NS_IMETHOD GetType(nsAString & aType) = 0;
  NS_SCRIPTABLE NS_IMETHOD SetType(const nsAString & aType) = 0;

  /* void select (); */
  NS_SCRIPTABLE NS_IMETHOD Select(void) = 0;

  /* void setSelectionRange (in long selectionStart, in long selectionEnd); */
  NS_SCRIPTABLE NS_IMETHOD SetSelectionRange(PRInt32 selectionStart, PRInt32 selectionEnd) = 0;

};

  NS_DEFINE_STATIC_IID_ACCESSOR(nsIDOMXULTextBoxElement, NS_IDOMXULTEXTBOXELEMENT_IID)

/* Use this macro when declaring classes that implement this interface. */
#define NS_DECL_NSIDOMXULTEXTBOXELEMENT \
  NS_SCRIPTABLE NS_IMETHOD GetInputField(nsIDOMNode * *aInputField); \
  NS_SCRIPTABLE NS_IMETHOD GetTextLength(PRInt32 *aTextLength); \
  NS_SCRIPTABLE NS_IMETHOD GetMaxLength(PRInt32 *aMaxLength); \
  NS_SCRIPTABLE NS_IMETHOD SetMaxLength(PRInt32 aMaxLength); \
  NS_SCRIPTABLE NS_IMETHOD GetSize(PRInt32 *aSize); \
  NS_SCRIPTABLE NS_IMETHOD SetSize(PRInt32 aSize); \
  NS_SCRIPTABLE NS_IMETHOD GetSelectionStart(PRInt32 *aSelectionStart); \
  NS_SCRIPTABLE NS_IMETHOD SetSelectionStart(PRInt32 aSelectionStart); \
  NS_SCRIPTABLE NS_IMETHOD GetSelectionEnd(PRInt32 *aSelectionEnd); \
  NS_SCRIPTABLE NS_IMETHOD SetSelectionEnd(PRInt32 aSelectionEnd); \
  NS_SCRIPTABLE NS_IMETHOD GetValue(nsAString & aValue); \
  NS_SCRIPTABLE NS_IMETHOD SetValue(const nsAString & aValue); \
  NS_SCRIPTABLE NS_IMETHOD GetType(nsAString & aType); \
  NS_SCRIPTABLE NS_IMETHOD SetType(const nsAString & aType); \
  NS_SCRIPTABLE NS_IMETHOD Select(void); \
  NS_SCRIPTABLE NS_IMETHOD SetSelectionRange(PRInt32 selectionStart, PRInt32 selectionEnd); 

/* Use this macro to declare functions that forward the behavior of this interface to another object. */
#define NS_FORWARD_NSIDOMXULTEXTBOXELEMENT(_to) \
  NS_SCRIPTABLE NS_IMETHOD GetInputField(nsIDOMNode * *aInputField) { return _to GetInputField(aInputField); } \
  NS_SCRIPTABLE NS_IMETHOD GetTextLength(PRInt32 *aTextLength) { return _to GetTextLength(aTextLength); } \
  NS_SCRIPTABLE NS_IMETHOD GetMaxLength(PRInt32 *aMaxLength) { return _to GetMaxLength(aMaxLength); } \
  NS_SCRIPTABLE NS_IMETHOD SetMaxLength(PRInt32 aMaxLength) { return _to SetMaxLength(aMaxLength); } \
  NS_SCRIPTABLE NS_IMETHOD GetSize(PRInt32 *aSize) { return _to GetSize(aSize); } \
  NS_SCRIPTABLE NS_IMETHOD SetSize(PRInt32 aSize) { return _to SetSize(aSize); } \
  NS_SCRIPTABLE NS_IMETHOD GetSelectionStart(PRInt32 *aSelectionStart) { return _to GetSelectionStart(aSelectionStart); } \
  NS_SCRIPTABLE NS_IMETHOD SetSelectionStart(PRInt32 aSelectionStart) { return _to SetSelectionStart(aSelectionStart); } \
  NS_SCRIPTABLE NS_IMETHOD GetSelectionEnd(PRInt32 *aSelectionEnd) { return _to GetSelectionEnd(aSelectionEnd); } \
  NS_SCRIPTABLE NS_IMETHOD SetSelectionEnd(PRInt32 aSelectionEnd) { return _to SetSelectionEnd(aSelectionEnd); } \
  NS_SCRIPTABLE NS_IMETHOD GetValue(nsAString & aValue) { return _to GetValue(aValue); } \
  NS_SCRIPTABLE NS_IMETHOD SetValue(const nsAString & aValue) { return _to SetValue(aValue); } \
  NS_SCRIPTABLE NS_IMETHOD GetType(nsAString & aType) { return _to GetType(aType); } \
  NS_SCRIPTABLE NS_IMETHOD SetType(const nsAString & aType) { return _to SetType(aType); } \
  NS_SCRIPTABLE NS_IMETHOD Select(void) { return _to Select(); } \
  NS_SCRIPTABLE NS_IMETHOD SetSelectionRange(PRInt32 selectionStart, PRInt32 selectionEnd) { return _to SetSelectionRange(selectionStart, selectionEnd); } 

/* Use this macro to declare functions that forward the behavior of this interface to another object in a safe way. */
#define NS_FORWARD_SAFE_NSIDOMXULTEXTBOXELEMENT(_to) \
  NS_SCRIPTABLE NS_IMETHOD GetInputField(nsIDOMNode * *aInputField) { return !_to ? NS_ERROR_NULL_POINTER : _to->GetInputField(aInputField); } \
  NS_SCRIPTABLE NS_IMETHOD GetTextLength(PRInt32 *aTextLength) { return !_to ? NS_ERROR_NULL_POINTER : _to->GetTextLength(aTextLength); } \
  NS_SCRIPTABLE NS_IMETHOD GetMaxLength(PRInt32 *aMaxLength) { return !_to ? NS_ERROR_NULL_POINTER : _to->GetMaxLength(aMaxLength); } \
  NS_SCRIPTABLE NS_IMETHOD SetMaxLength(PRInt32 aMaxLength) { return !_to ? NS_ERROR_NULL_POINTER : _to->SetMaxLength(aMaxLength); } \
  NS_SCRIPTABLE NS_IMETHOD GetSize(PRInt32 *aSize) { return !_to ? NS_ERROR_NULL_POINTER : _to->GetSize(aSize); } \
  NS_SCRIPTABLE NS_IMETHOD SetSize(PRInt32 aSize) { return !_to ? NS_ERROR_NULL_POINTER : _to->SetSize(aSize); } \
  NS_SCRIPTABLE NS_IMETHOD GetSelectionStart(PRInt32 *aSelectionStart) { return !_to ? NS_ERROR_NULL_POINTER : _to->GetSelectionStart(aSelectionStart); } \
  NS_SCRIPTABLE NS_IMETHOD SetSelectionStart(PRInt32 aSelectionStart) { return !_to ? NS_ERROR_NULL_POINTER : _to->SetSelectionStart(aSelectionStart); } \
  NS_SCRIPTABLE NS_IMETHOD GetSelectionEnd(PRInt32 *aSelectionEnd) { return !_to ? NS_ERROR_NULL_POINTER : _to->GetSelectionEnd(aSelectionEnd); } \
  NS_SCRIPTABLE NS_IMETHOD SetSelectionEnd(PRInt32 aSelectionEnd) { return !_to ? NS_ERROR_NULL_POINTER : _to->SetSelectionEnd(aSelectionEnd); } \
  NS_SCRIPTABLE NS_IMETHOD GetValue(nsAString & aValue) { return !_to ? NS_ERROR_NULL_POINTER : _to->GetValue(aValue); } \
  NS_SCRIPTABLE NS_IMETHOD SetValue(const nsAString & aValue) { return !_to ? NS_ERROR_NULL_POINTER : _to->SetValue(aValue); } \
  NS_SCRIPTABLE NS_IMETHOD GetType(nsAString & aType) { return !_to ? NS_ERROR_NULL_POINTER : _to->GetType(aType); } \
  NS_SCRIPTABLE NS_IMETHOD SetType(const nsAString & aType) { return !_to ? NS_ERROR_NULL_POINTER : _to->SetType(aType); } \
  NS_SCRIPTABLE NS_IMETHOD Select(void) { return !_to ? NS_ERROR_NULL_POINTER : _to->Select(); } \
  NS_SCRIPTABLE NS_IMETHOD SetSelectionRange(PRInt32 selectionStart, PRInt32 selectionEnd) { return !_to ? NS_ERROR_NULL_POINTER : _to->SetSelectionRange(selectionStart, selectionEnd); } 

#if 0
/* Use the code below as a template for the implementation class for this interface. */

/* Header file */
class nsDOMXULTextBoxElement : public nsIDOMXULTextBoxElement
{
public:
  NS_DECL_ISUPPORTS
  NS_DECL_NSIDOMXULTEXTBOXELEMENT

  nsDOMXULTextBoxElement();

private:
  ~nsDOMXULTextBoxElement();

protected:
  /* additional members */
};

/* Implementation file */
NS_IMPL_ISUPPORTS1(nsDOMXULTextBoxElement, nsIDOMXULTextBoxElement)

nsDOMXULTextBoxElement::nsDOMXULTextBoxElement()
{
  /* member initializers and constructor code */
}

nsDOMXULTextBoxElement::~nsDOMXULTextBoxElement()
{
  /* destructor code */
}

/* readonly attribute nsIDOMNode inputField; */
NS_IMETHODIMP nsDOMXULTextBoxElement::GetInputField(nsIDOMNode * *aInputField)
{
    return NS_ERROR_NOT_IMPLEMENTED;
}

/* readonly attribute long textLength; */
NS_IMETHODIMP nsDOMXULTextBoxElement::GetTextLength(PRInt32 *aTextLength)
{
    return NS_ERROR_NOT_IMPLEMENTED;
}

/* attribute long maxLength; */
NS_IMETHODIMP nsDOMXULTextBoxElement::GetMaxLength(PRInt32 *aMaxLength)
{
    return NS_ERROR_NOT_IMPLEMENTED;
}
NS_IMETHODIMP nsDOMXULTextBoxElement::SetMaxLength(PRInt32 aMaxLength)
{
    return NS_ERROR_NOT_IMPLEMENTED;
}

/* attribute long size; */
NS_IMETHODIMP nsDOMXULTextBoxElement::GetSize(PRInt32 *aSize)
{
    return NS_ERROR_NOT_IMPLEMENTED;
}
NS_IMETHODIMP nsDOMXULTextBoxElement::SetSize(PRInt32 aSize)
{
    return NS_ERROR_NOT_IMPLEMENTED;
}

/* attribute long selectionStart; */
NS_IMETHODIMP nsDOMXULTextBoxElement::GetSelectionStart(PRInt32 *aSelectionStart)
{
    return NS_ERROR_NOT_IMPLEMENTED;
}
NS_IMETHODIMP nsDOMXULTextBoxElement::SetSelectionStart(PRInt32 aSelectionStart)
{
    return NS_ERROR_NOT_IMPLEMENTED;
}

/* attribute long selectionEnd; */
NS_IMETHODIMP nsDOMXULTextBoxElement::GetSelectionEnd(PRInt32 *aSelectionEnd)
{
    return NS_ERROR_NOT_IMPLEMENTED;
}
NS_IMETHODIMP nsDOMXULTextBoxElement::SetSelectionEnd(PRInt32 aSelectionEnd)
{
    return NS_ERROR_NOT_IMPLEMENTED;
}

/* attribute DOMString value; */
NS_IMETHODIMP nsDOMXULTextBoxElement::GetValue(nsAString & aValue)
{
    return NS_ERROR_NOT_IMPLEMENTED;
}
NS_IMETHODIMP nsDOMXULTextBoxElement::SetValue(const nsAString & aValue)
{
    return NS_ERROR_NOT_IMPLEMENTED;
}

/* attribute DOMString type; */
NS_IMETHODIMP nsDOMXULTextBoxElement::GetType(nsAString & aType)
{
    return NS_ERROR_NOT_IMPLEMENTED;
}
NS_IMETHODIMP nsDOMXULTextBoxElement::SetType(const nsAString & aType)
{
    return NS_ERROR_NOT_IMPLEMENTED;
}

/* void select (); */
NS_IMETHODIMP nsDOMXULTextBoxElement::Select()
{
    return NS_ERROR_NOT_IMPLEMENTED;
}

/* void setSelectionRange (in long selectionStart, in long selectionEnd); */
NS_IMETHODIMP nsDOMXULTextBoxElement::SetSelectionRange(PRInt32 selectionStart, PRInt32 selectionEnd)
{
    return NS_ERROR_NOT_IMPLEMENTED;
}

/* End of implementation class template. */
#endif


#endif /* __gen_nsIDOMXULTextboxElement_h__ */
