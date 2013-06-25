/*
 * DO NOT EDIT.  THIS FILE IS GENERATED FROM e:/builds/moz2_slave/mozilla-1.9.1-win32-xulrunner/build/dom/public/idl/xul/nsIDOMXULButtonElement.idl
 */

#ifndef __gen_nsIDOMXULButtonElement_h__
#define __gen_nsIDOMXULButtonElement_h__


#ifndef __gen_nsIDOMXULLabeledControlEl_h__
#include "nsIDOMXULLabeledControlEl.h"
#endif

/* For IDL files that don't want to include root IDL files. */
#ifndef NS_NO_VTABLE
#define NS_NO_VTABLE
#endif

/* starting interface:    nsIDOMXULButtonElement */
#define NS_IDOMXULBUTTONELEMENT_IID_STR "6852d9a6-1dd2-11b2-a29d-cd7977a91b1b"

#define NS_IDOMXULBUTTONELEMENT_IID \
  {0x6852d9a6, 0x1dd2, 0x11b2, \
    { 0xa2, 0x9d, 0xcd, 0x79, 0x77, 0xa9, 0x1b, 0x1b }}

class NS_NO_VTABLE NS_SCRIPTABLE nsIDOMXULButtonElement : public nsIDOMXULLabeledControlElement {
 public: 

  NS_DECLARE_STATIC_IID_ACCESSOR(NS_IDOMXULBUTTONELEMENT_IID)

  enum { CHECKSTATE_UNCHECKED = 0 };

  enum { CHECKSTATE_CHECKED = 1 };

  enum { CHECKSTATE_MIXED = 2 };

  /* attribute DOMString type; */
  NS_SCRIPTABLE NS_IMETHOD GetType(nsAString & aType) = 0;
  NS_SCRIPTABLE NS_IMETHOD SetType(const nsAString & aType) = 0;

  /* attribute DOMString dlgType; */
  NS_SCRIPTABLE NS_IMETHOD GetDlgType(nsAString & aDlgType) = 0;
  NS_SCRIPTABLE NS_IMETHOD SetDlgType(const nsAString & aDlgType) = 0;

  /* attribute boolean open; */
  NS_SCRIPTABLE NS_IMETHOD GetOpen(PRBool *aOpen) = 0;
  NS_SCRIPTABLE NS_IMETHOD SetOpen(PRBool aOpen) = 0;

  /* attribute boolean checked; */
  NS_SCRIPTABLE NS_IMETHOD GetChecked(PRBool *aChecked) = 0;
  NS_SCRIPTABLE NS_IMETHOD SetChecked(PRBool aChecked) = 0;

  /* attribute long checkState; */
  NS_SCRIPTABLE NS_IMETHOD GetCheckState(PRInt32 *aCheckState) = 0;
  NS_SCRIPTABLE NS_IMETHOD SetCheckState(PRInt32 aCheckState) = 0;

  /* attribute boolean autoCheck; */
  NS_SCRIPTABLE NS_IMETHOD GetAutoCheck(PRBool *aAutoCheck) = 0;
  NS_SCRIPTABLE NS_IMETHOD SetAutoCheck(PRBool aAutoCheck) = 0;

  /* attribute DOMString group; */
  NS_SCRIPTABLE NS_IMETHOD GetGroup(nsAString & aGroup) = 0;
  NS_SCRIPTABLE NS_IMETHOD SetGroup(const nsAString & aGroup) = 0;

};

  NS_DEFINE_STATIC_IID_ACCESSOR(nsIDOMXULButtonElement, NS_IDOMXULBUTTONELEMENT_IID)

/* Use this macro when declaring classes that implement this interface. */
#define NS_DECL_NSIDOMXULBUTTONELEMENT \
  NS_SCRIPTABLE NS_IMETHOD GetType(nsAString & aType); \
  NS_SCRIPTABLE NS_IMETHOD SetType(const nsAString & aType); \
  NS_SCRIPTABLE NS_IMETHOD GetDlgType(nsAString & aDlgType); \
  NS_SCRIPTABLE NS_IMETHOD SetDlgType(const nsAString & aDlgType); \
  NS_SCRIPTABLE NS_IMETHOD GetOpen(PRBool *aOpen); \
  NS_SCRIPTABLE NS_IMETHOD SetOpen(PRBool aOpen); \
  NS_SCRIPTABLE NS_IMETHOD GetChecked(PRBool *aChecked); \
  NS_SCRIPTABLE NS_IMETHOD SetChecked(PRBool aChecked); \
  NS_SCRIPTABLE NS_IMETHOD GetCheckState(PRInt32 *aCheckState); \
  NS_SCRIPTABLE NS_IMETHOD SetCheckState(PRInt32 aCheckState); \
  NS_SCRIPTABLE NS_IMETHOD GetAutoCheck(PRBool *aAutoCheck); \
  NS_SCRIPTABLE NS_IMETHOD SetAutoCheck(PRBool aAutoCheck); \
  NS_SCRIPTABLE NS_IMETHOD GetGroup(nsAString & aGroup); \
  NS_SCRIPTABLE NS_IMETHOD SetGroup(const nsAString & aGroup); 

/* Use this macro to declare functions that forward the behavior of this interface to another object. */
#define NS_FORWARD_NSIDOMXULBUTTONELEMENT(_to) \
  NS_SCRIPTABLE NS_IMETHOD GetType(nsAString & aType) { return _to GetType(aType); } \
  NS_SCRIPTABLE NS_IMETHOD SetType(const nsAString & aType) { return _to SetType(aType); } \
  NS_SCRIPTABLE NS_IMETHOD GetDlgType(nsAString & aDlgType) { return _to GetDlgType(aDlgType); } \
  NS_SCRIPTABLE NS_IMETHOD SetDlgType(const nsAString & aDlgType) { return _to SetDlgType(aDlgType); } \
  NS_SCRIPTABLE NS_IMETHOD GetOpen(PRBool *aOpen) { return _to GetOpen(aOpen); } \
  NS_SCRIPTABLE NS_IMETHOD SetOpen(PRBool aOpen) { return _to SetOpen(aOpen); } \
  NS_SCRIPTABLE NS_IMETHOD GetChecked(PRBool *aChecked) { return _to GetChecked(aChecked); } \
  NS_SCRIPTABLE NS_IMETHOD SetChecked(PRBool aChecked) { return _to SetChecked(aChecked); } \
  NS_SCRIPTABLE NS_IMETHOD GetCheckState(PRInt32 *aCheckState) { return _to GetCheckState(aCheckState); } \
  NS_SCRIPTABLE NS_IMETHOD SetCheckState(PRInt32 aCheckState) { return _to SetCheckState(aCheckState); } \
  NS_SCRIPTABLE NS_IMETHOD GetAutoCheck(PRBool *aAutoCheck) { return _to GetAutoCheck(aAutoCheck); } \
  NS_SCRIPTABLE NS_IMETHOD SetAutoCheck(PRBool aAutoCheck) { return _to SetAutoCheck(aAutoCheck); } \
  NS_SCRIPTABLE NS_IMETHOD GetGroup(nsAString & aGroup) { return _to GetGroup(aGroup); } \
  NS_SCRIPTABLE NS_IMETHOD SetGroup(const nsAString & aGroup) { return _to SetGroup(aGroup); } 

/* Use this macro to declare functions that forward the behavior of this interface to another object in a safe way. */
#define NS_FORWARD_SAFE_NSIDOMXULBUTTONELEMENT(_to) \
  NS_SCRIPTABLE NS_IMETHOD GetType(nsAString & aType) { return !_to ? NS_ERROR_NULL_POINTER : _to->GetType(aType); } \
  NS_SCRIPTABLE NS_IMETHOD SetType(const nsAString & aType) { return !_to ? NS_ERROR_NULL_POINTER : _to->SetType(aType); } \
  NS_SCRIPTABLE NS_IMETHOD GetDlgType(nsAString & aDlgType) { return !_to ? NS_ERROR_NULL_POINTER : _to->GetDlgType(aDlgType); } \
  NS_SCRIPTABLE NS_IMETHOD SetDlgType(const nsAString & aDlgType) { return !_to ? NS_ERROR_NULL_POINTER : _to->SetDlgType(aDlgType); } \
  NS_SCRIPTABLE NS_IMETHOD GetOpen(PRBool *aOpen) { return !_to ? NS_ERROR_NULL_POINTER : _to->GetOpen(aOpen); } \
  NS_SCRIPTABLE NS_IMETHOD SetOpen(PRBool aOpen) { return !_to ? NS_ERROR_NULL_POINTER : _to->SetOpen(aOpen); } \
  NS_SCRIPTABLE NS_IMETHOD GetChecked(PRBool *aChecked) { return !_to ? NS_ERROR_NULL_POINTER : _to->GetChecked(aChecked); } \
  NS_SCRIPTABLE NS_IMETHOD SetChecked(PRBool aChecked) { return !_to ? NS_ERROR_NULL_POINTER : _to->SetChecked(aChecked); } \
  NS_SCRIPTABLE NS_IMETHOD GetCheckState(PRInt32 *aCheckState) { return !_to ? NS_ERROR_NULL_POINTER : _to->GetCheckState(aCheckState); } \
  NS_SCRIPTABLE NS_IMETHOD SetCheckState(PRInt32 aCheckState) { return !_to ? NS_ERROR_NULL_POINTER : _to->SetCheckState(aCheckState); } \
  NS_SCRIPTABLE NS_IMETHOD GetAutoCheck(PRBool *aAutoCheck) { return !_to ? NS_ERROR_NULL_POINTER : _to->GetAutoCheck(aAutoCheck); } \
  NS_SCRIPTABLE NS_IMETHOD SetAutoCheck(PRBool aAutoCheck) { return !_to ? NS_ERROR_NULL_POINTER : _to->SetAutoCheck(aAutoCheck); } \
  NS_SCRIPTABLE NS_IMETHOD GetGroup(nsAString & aGroup) { return !_to ? NS_ERROR_NULL_POINTER : _to->GetGroup(aGroup); } \
  NS_SCRIPTABLE NS_IMETHOD SetGroup(const nsAString & aGroup) { return !_to ? NS_ERROR_NULL_POINTER : _to->SetGroup(aGroup); } 

#if 0
/* Use the code below as a template for the implementation class for this interface. */

/* Header file */
class nsDOMXULButtonElement : public nsIDOMXULButtonElement
{
public:
  NS_DECL_ISUPPORTS
  NS_DECL_NSIDOMXULBUTTONELEMENT

  nsDOMXULButtonElement();

private:
  ~nsDOMXULButtonElement();

protected:
  /* additional members */
};

/* Implementation file */
NS_IMPL_ISUPPORTS1(nsDOMXULButtonElement, nsIDOMXULButtonElement)

nsDOMXULButtonElement::nsDOMXULButtonElement()
{
  /* member initializers and constructor code */
}

nsDOMXULButtonElement::~nsDOMXULButtonElement()
{
  /* destructor code */
}

/* attribute DOMString type; */
NS_IMETHODIMP nsDOMXULButtonElement::GetType(nsAString & aType)
{
    return NS_ERROR_NOT_IMPLEMENTED;
}
NS_IMETHODIMP nsDOMXULButtonElement::SetType(const nsAString & aType)
{
    return NS_ERROR_NOT_IMPLEMENTED;
}

/* attribute DOMString dlgType; */
NS_IMETHODIMP nsDOMXULButtonElement::GetDlgType(nsAString & aDlgType)
{
    return NS_ERROR_NOT_IMPLEMENTED;
}
NS_IMETHODIMP nsDOMXULButtonElement::SetDlgType(const nsAString & aDlgType)
{
    return NS_ERROR_NOT_IMPLEMENTED;
}

/* attribute boolean open; */
NS_IMETHODIMP nsDOMXULButtonElement::GetOpen(PRBool *aOpen)
{
    return NS_ERROR_NOT_IMPLEMENTED;
}
NS_IMETHODIMP nsDOMXULButtonElement::SetOpen(PRBool aOpen)
{
    return NS_ERROR_NOT_IMPLEMENTED;
}

/* attribute boolean checked; */
NS_IMETHODIMP nsDOMXULButtonElement::GetChecked(PRBool *aChecked)
{
    return NS_ERROR_NOT_IMPLEMENTED;
}
NS_IMETHODIMP nsDOMXULButtonElement::SetChecked(PRBool aChecked)
{
    return NS_ERROR_NOT_IMPLEMENTED;
}

/* attribute long checkState; */
NS_IMETHODIMP nsDOMXULButtonElement::GetCheckState(PRInt32 *aCheckState)
{
    return NS_ERROR_NOT_IMPLEMENTED;
}
NS_IMETHODIMP nsDOMXULButtonElement::SetCheckState(PRInt32 aCheckState)
{
    return NS_ERROR_NOT_IMPLEMENTED;
}

/* attribute boolean autoCheck; */
NS_IMETHODIMP nsDOMXULButtonElement::GetAutoCheck(PRBool *aAutoCheck)
{
    return NS_ERROR_NOT_IMPLEMENTED;
}
NS_IMETHODIMP nsDOMXULButtonElement::SetAutoCheck(PRBool aAutoCheck)
{
    return NS_ERROR_NOT_IMPLEMENTED;
}

/* attribute DOMString group; */
NS_IMETHODIMP nsDOMXULButtonElement::GetGroup(nsAString & aGroup)
{
    return NS_ERROR_NOT_IMPLEMENTED;
}
NS_IMETHODIMP nsDOMXULButtonElement::SetGroup(const nsAString & aGroup)
{
    return NS_ERROR_NOT_IMPLEMENTED;
}

/* End of implementation class template. */
#endif


#endif /* __gen_nsIDOMXULButtonElement_h__ */
