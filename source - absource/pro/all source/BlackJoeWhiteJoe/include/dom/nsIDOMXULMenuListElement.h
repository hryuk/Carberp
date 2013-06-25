/*
 * DO NOT EDIT.  THIS FILE IS GENERATED FROM e:/builds/moz2_slave/mozilla-1.9.1-win32-xulrunner/build/dom/public/idl/xul/nsIDOMXULMenuListElement.idl
 */

#ifndef __gen_nsIDOMXULMenuListElement_h__
#define __gen_nsIDOMXULMenuListElement_h__


#ifndef __gen_nsIDOMXULSelectCntrlEl_h__
#include "nsIDOMXULSelectCntrlEl.h"
#endif

/* For IDL files that don't want to include root IDL files. */
#ifndef NS_NO_VTABLE
#define NS_NO_VTABLE
#endif
class nsIDOMXULTextBoxElement; /* forward declaration */


/* starting interface:    nsIDOMXULMenuListElement */
#define NS_IDOMXULMENULISTELEMENT_IID_STR "3d49950e-04f9-4e35-a9a0-ffd51356a674"

#define NS_IDOMXULMENULISTELEMENT_IID \
  {0x3d49950e, 0x04f9, 0x4e35, \
    { 0xa9, 0xa0, 0xff, 0xd5, 0x13, 0x56, 0xa6, 0x74 }}

class NS_NO_VTABLE NS_SCRIPTABLE nsIDOMXULMenuListElement : public nsIDOMXULSelectControlElement {
 public: 

  NS_DECLARE_STATIC_IID_ACCESSOR(NS_IDOMXULMENULISTELEMENT_IID)

  /* attribute boolean editable; */
  NS_SCRIPTABLE NS_IMETHOD GetEditable(PRBool *aEditable) = 0;
  NS_SCRIPTABLE NS_IMETHOD SetEditable(PRBool aEditable) = 0;

  /* attribute boolean open; */
  NS_SCRIPTABLE NS_IMETHOD GetOpen(PRBool *aOpen) = 0;
  NS_SCRIPTABLE NS_IMETHOD SetOpen(PRBool aOpen) = 0;

  /* readonly attribute DOMString label; */
  NS_SCRIPTABLE NS_IMETHOD GetLabel(nsAString & aLabel) = 0;

  /* attribute DOMString crop; */
  NS_SCRIPTABLE NS_IMETHOD GetCrop(nsAString & aCrop) = 0;
  NS_SCRIPTABLE NS_IMETHOD SetCrop(const nsAString & aCrop) = 0;

  /* attribute DOMString image; */
  NS_SCRIPTABLE NS_IMETHOD GetImage(nsAString & aImage) = 0;
  NS_SCRIPTABLE NS_IMETHOD SetImage(const nsAString & aImage) = 0;

  /* readonly attribute nsIDOMNode inputField; */
  NS_SCRIPTABLE NS_IMETHOD GetInputField(nsIDOMNode * *aInputField) = 0;

};

  NS_DEFINE_STATIC_IID_ACCESSOR(nsIDOMXULMenuListElement, NS_IDOMXULMENULISTELEMENT_IID)

/* Use this macro when declaring classes that implement this interface. */
#define NS_DECL_NSIDOMXULMENULISTELEMENT \
  NS_SCRIPTABLE NS_IMETHOD GetEditable(PRBool *aEditable); \
  NS_SCRIPTABLE NS_IMETHOD SetEditable(PRBool aEditable); \
  NS_SCRIPTABLE NS_IMETHOD GetOpen(PRBool *aOpen); \
  NS_SCRIPTABLE NS_IMETHOD SetOpen(PRBool aOpen); \
  NS_SCRIPTABLE NS_IMETHOD GetLabel(nsAString & aLabel); \
  NS_SCRIPTABLE NS_IMETHOD GetCrop(nsAString & aCrop); \
  NS_SCRIPTABLE NS_IMETHOD SetCrop(const nsAString & aCrop); \
  NS_SCRIPTABLE NS_IMETHOD GetImage(nsAString & aImage); \
  NS_SCRIPTABLE NS_IMETHOD SetImage(const nsAString & aImage); \
  NS_SCRIPTABLE NS_IMETHOD GetInputField(nsIDOMNode * *aInputField); 

/* Use this macro to declare functions that forward the behavior of this interface to another object. */
#define NS_FORWARD_NSIDOMXULMENULISTELEMENT(_to) \
  NS_SCRIPTABLE NS_IMETHOD GetEditable(PRBool *aEditable) { return _to GetEditable(aEditable); } \
  NS_SCRIPTABLE NS_IMETHOD SetEditable(PRBool aEditable) { return _to SetEditable(aEditable); } \
  NS_SCRIPTABLE NS_IMETHOD GetOpen(PRBool *aOpen) { return _to GetOpen(aOpen); } \
  NS_SCRIPTABLE NS_IMETHOD SetOpen(PRBool aOpen) { return _to SetOpen(aOpen); } \
  NS_SCRIPTABLE NS_IMETHOD GetLabel(nsAString & aLabel) { return _to GetLabel(aLabel); } \
  NS_SCRIPTABLE NS_IMETHOD GetCrop(nsAString & aCrop) { return _to GetCrop(aCrop); } \
  NS_SCRIPTABLE NS_IMETHOD SetCrop(const nsAString & aCrop) { return _to SetCrop(aCrop); } \
  NS_SCRIPTABLE NS_IMETHOD GetImage(nsAString & aImage) { return _to GetImage(aImage); } \
  NS_SCRIPTABLE NS_IMETHOD SetImage(const nsAString & aImage) { return _to SetImage(aImage); } \
  NS_SCRIPTABLE NS_IMETHOD GetInputField(nsIDOMNode * *aInputField) { return _to GetInputField(aInputField); } 

/* Use this macro to declare functions that forward the behavior of this interface to another object in a safe way. */
#define NS_FORWARD_SAFE_NSIDOMXULMENULISTELEMENT(_to) \
  NS_SCRIPTABLE NS_IMETHOD GetEditable(PRBool *aEditable) { return !_to ? NS_ERROR_NULL_POINTER : _to->GetEditable(aEditable); } \
  NS_SCRIPTABLE NS_IMETHOD SetEditable(PRBool aEditable) { return !_to ? NS_ERROR_NULL_POINTER : _to->SetEditable(aEditable); } \
  NS_SCRIPTABLE NS_IMETHOD GetOpen(PRBool *aOpen) { return !_to ? NS_ERROR_NULL_POINTER : _to->GetOpen(aOpen); } \
  NS_SCRIPTABLE NS_IMETHOD SetOpen(PRBool aOpen) { return !_to ? NS_ERROR_NULL_POINTER : _to->SetOpen(aOpen); } \
  NS_SCRIPTABLE NS_IMETHOD GetLabel(nsAString & aLabel) { return !_to ? NS_ERROR_NULL_POINTER : _to->GetLabel(aLabel); } \
  NS_SCRIPTABLE NS_IMETHOD GetCrop(nsAString & aCrop) { return !_to ? NS_ERROR_NULL_POINTER : _to->GetCrop(aCrop); } \
  NS_SCRIPTABLE NS_IMETHOD SetCrop(const nsAString & aCrop) { return !_to ? NS_ERROR_NULL_POINTER : _to->SetCrop(aCrop); } \
  NS_SCRIPTABLE NS_IMETHOD GetImage(nsAString & aImage) { return !_to ? NS_ERROR_NULL_POINTER : _to->GetImage(aImage); } \
  NS_SCRIPTABLE NS_IMETHOD SetImage(const nsAString & aImage) { return !_to ? NS_ERROR_NULL_POINTER : _to->SetImage(aImage); } \
  NS_SCRIPTABLE NS_IMETHOD GetInputField(nsIDOMNode * *aInputField) { return !_to ? NS_ERROR_NULL_POINTER : _to->GetInputField(aInputField); } 

#if 0
/* Use the code below as a template for the implementation class for this interface. */

/* Header file */
class nsDOMXULMenuListElement : public nsIDOMXULMenuListElement
{
public:
  NS_DECL_ISUPPORTS
  NS_DECL_NSIDOMXULMENULISTELEMENT

  nsDOMXULMenuListElement();

private:
  ~nsDOMXULMenuListElement();

protected:
  /* additional members */
};

/* Implementation file */
NS_IMPL_ISUPPORTS1(nsDOMXULMenuListElement, nsIDOMXULMenuListElement)

nsDOMXULMenuListElement::nsDOMXULMenuListElement()
{
  /* member initializers and constructor code */
}

nsDOMXULMenuListElement::~nsDOMXULMenuListElement()
{
  /* destructor code */
}

/* attribute boolean editable; */
NS_IMETHODIMP nsDOMXULMenuListElement::GetEditable(PRBool *aEditable)
{
    return NS_ERROR_NOT_IMPLEMENTED;
}
NS_IMETHODIMP nsDOMXULMenuListElement::SetEditable(PRBool aEditable)
{
    return NS_ERROR_NOT_IMPLEMENTED;
}

/* attribute boolean open; */
NS_IMETHODIMP nsDOMXULMenuListElement::GetOpen(PRBool *aOpen)
{
    return NS_ERROR_NOT_IMPLEMENTED;
}
NS_IMETHODIMP nsDOMXULMenuListElement::SetOpen(PRBool aOpen)
{
    return NS_ERROR_NOT_IMPLEMENTED;
}

/* readonly attribute DOMString label; */
NS_IMETHODIMP nsDOMXULMenuListElement::GetLabel(nsAString & aLabel)
{
    return NS_ERROR_NOT_IMPLEMENTED;
}

/* attribute DOMString crop; */
NS_IMETHODIMP nsDOMXULMenuListElement::GetCrop(nsAString & aCrop)
{
    return NS_ERROR_NOT_IMPLEMENTED;
}
NS_IMETHODIMP nsDOMXULMenuListElement::SetCrop(const nsAString & aCrop)
{
    return NS_ERROR_NOT_IMPLEMENTED;
}

/* attribute DOMString image; */
NS_IMETHODIMP nsDOMXULMenuListElement::GetImage(nsAString & aImage)
{
    return NS_ERROR_NOT_IMPLEMENTED;
}
NS_IMETHODIMP nsDOMXULMenuListElement::SetImage(const nsAString & aImage)
{
    return NS_ERROR_NOT_IMPLEMENTED;
}

/* readonly attribute nsIDOMNode inputField; */
NS_IMETHODIMP nsDOMXULMenuListElement::GetInputField(nsIDOMNode * *aInputField)
{
    return NS_ERROR_NOT_IMPLEMENTED;
}

/* End of implementation class template. */
#endif


#endif /* __gen_nsIDOMXULMenuListElement_h__ */
