/*
 * DO NOT EDIT.  THIS FILE IS GENERATED FROM e:/builds/moz2_slave/mozilla-1.9.1-win32-xulrunner/build/dom/public/idl/xul/nsIDOMXULSelectCntrlEl.idl
 */

#ifndef __gen_nsIDOMXULSelectCntrlEl_h__
#define __gen_nsIDOMXULSelectCntrlEl_h__


#ifndef __gen_nsIDOMXULControlElement_h__
#include "nsIDOMXULControlElement.h"
#endif

/* For IDL files that don't want to include root IDL files. */
#ifndef NS_NO_VTABLE
#define NS_NO_VTABLE
#endif
class nsIDOMXULSelectControlItemElement; /* forward declaration */


/* starting interface:    nsIDOMXULSelectControlElement */
#define NS_IDOMXULSELECTCONTROLELEMENT_IID_STR "919d9808-8937-4cec-9390-91225eb8864b"

#define NS_IDOMXULSELECTCONTROLELEMENT_IID \
  {0x919d9808, 0x8937, 0x4cec, \
    { 0x93, 0x90, 0x91, 0x22, 0x5e, 0xb8, 0x86, 0x4b }}

class NS_NO_VTABLE NS_SCRIPTABLE nsIDOMXULSelectControlElement : public nsIDOMXULControlElement {
 public: 

  NS_DECLARE_STATIC_IID_ACCESSOR(NS_IDOMXULSELECTCONTROLELEMENT_IID)

  /* attribute nsIDOMXULSelectControlItemElement selectedItem; */
  NS_SCRIPTABLE NS_IMETHOD GetSelectedItem(nsIDOMXULSelectControlItemElement * *aSelectedItem) = 0;
  NS_SCRIPTABLE NS_IMETHOD SetSelectedItem(nsIDOMXULSelectControlItemElement * aSelectedItem) = 0;

  /* attribute long selectedIndex; */
  NS_SCRIPTABLE NS_IMETHOD GetSelectedIndex(PRInt32 *aSelectedIndex) = 0;
  NS_SCRIPTABLE NS_IMETHOD SetSelectedIndex(PRInt32 aSelectedIndex) = 0;

  /* attribute DOMString value; */
  NS_SCRIPTABLE NS_IMETHOD GetValue(nsAString & aValue) = 0;
  NS_SCRIPTABLE NS_IMETHOD SetValue(const nsAString & aValue) = 0;

  /* nsIDOMXULSelectControlItemElement appendItem (in DOMString label, in DOMString value); */
  NS_SCRIPTABLE NS_IMETHOD AppendItem(const nsAString & label, const nsAString & value, nsIDOMXULSelectControlItemElement **_retval NS_OUTPARAM) = 0;

  /* nsIDOMXULSelectControlItemElement insertItemAt (in long index, in DOMString label, in DOMString value); */
  NS_SCRIPTABLE NS_IMETHOD InsertItemAt(PRInt32 index, const nsAString & label, const nsAString & value, nsIDOMXULSelectControlItemElement **_retval NS_OUTPARAM) = 0;

  /* nsIDOMXULSelectControlItemElement removeItemAt (in long index); */
  NS_SCRIPTABLE NS_IMETHOD RemoveItemAt(PRInt32 index, nsIDOMXULSelectControlItemElement **_retval NS_OUTPARAM) = 0;

  /* readonly attribute unsigned long itemCount; */
  NS_SCRIPTABLE NS_IMETHOD GetItemCount(PRUint32 *aItemCount) = 0;

  /* long getIndexOfItem (in nsIDOMXULSelectControlItemElement item); */
  NS_SCRIPTABLE NS_IMETHOD GetIndexOfItem(nsIDOMXULSelectControlItemElement *item, PRInt32 *_retval NS_OUTPARAM) = 0;

  /* nsIDOMXULSelectControlItemElement getItemAtIndex (in long index); */
  NS_SCRIPTABLE NS_IMETHOD GetItemAtIndex(PRInt32 index, nsIDOMXULSelectControlItemElement **_retval NS_OUTPARAM) = 0;

};

  NS_DEFINE_STATIC_IID_ACCESSOR(nsIDOMXULSelectControlElement, NS_IDOMXULSELECTCONTROLELEMENT_IID)

/* Use this macro when declaring classes that implement this interface. */
#define NS_DECL_NSIDOMXULSELECTCONTROLELEMENT \
  NS_SCRIPTABLE NS_IMETHOD GetSelectedItem(nsIDOMXULSelectControlItemElement * *aSelectedItem); \
  NS_SCRIPTABLE NS_IMETHOD SetSelectedItem(nsIDOMXULSelectControlItemElement * aSelectedItem); \
  NS_SCRIPTABLE NS_IMETHOD GetSelectedIndex(PRInt32 *aSelectedIndex); \
  NS_SCRIPTABLE NS_IMETHOD SetSelectedIndex(PRInt32 aSelectedIndex); \
  NS_SCRIPTABLE NS_IMETHOD GetValue(nsAString & aValue); \
  NS_SCRIPTABLE NS_IMETHOD SetValue(const nsAString & aValue); \
  NS_SCRIPTABLE NS_IMETHOD AppendItem(const nsAString & label, const nsAString & value, nsIDOMXULSelectControlItemElement **_retval NS_OUTPARAM); \
  NS_SCRIPTABLE NS_IMETHOD InsertItemAt(PRInt32 index, const nsAString & label, const nsAString & value, nsIDOMXULSelectControlItemElement **_retval NS_OUTPARAM); \
  NS_SCRIPTABLE NS_IMETHOD RemoveItemAt(PRInt32 index, nsIDOMXULSelectControlItemElement **_retval NS_OUTPARAM); \
  NS_SCRIPTABLE NS_IMETHOD GetItemCount(PRUint32 *aItemCount); \
  NS_SCRIPTABLE NS_IMETHOD GetIndexOfItem(nsIDOMXULSelectControlItemElement *item, PRInt32 *_retval NS_OUTPARAM); \
  NS_SCRIPTABLE NS_IMETHOD GetItemAtIndex(PRInt32 index, nsIDOMXULSelectControlItemElement **_retval NS_OUTPARAM); 

/* Use this macro to declare functions that forward the behavior of this interface to another object. */
#define NS_FORWARD_NSIDOMXULSELECTCONTROLELEMENT(_to) \
  NS_SCRIPTABLE NS_IMETHOD GetSelectedItem(nsIDOMXULSelectControlItemElement * *aSelectedItem) { return _to GetSelectedItem(aSelectedItem); } \
  NS_SCRIPTABLE NS_IMETHOD SetSelectedItem(nsIDOMXULSelectControlItemElement * aSelectedItem) { return _to SetSelectedItem(aSelectedItem); } \
  NS_SCRIPTABLE NS_IMETHOD GetSelectedIndex(PRInt32 *aSelectedIndex) { return _to GetSelectedIndex(aSelectedIndex); } \
  NS_SCRIPTABLE NS_IMETHOD SetSelectedIndex(PRInt32 aSelectedIndex) { return _to SetSelectedIndex(aSelectedIndex); } \
  NS_SCRIPTABLE NS_IMETHOD GetValue(nsAString & aValue) { return _to GetValue(aValue); } \
  NS_SCRIPTABLE NS_IMETHOD SetValue(const nsAString & aValue) { return _to SetValue(aValue); } \
  NS_SCRIPTABLE NS_IMETHOD AppendItem(const nsAString & label, const nsAString & value, nsIDOMXULSelectControlItemElement **_retval NS_OUTPARAM) { return _to AppendItem(label, value, _retval); } \
  NS_SCRIPTABLE NS_IMETHOD InsertItemAt(PRInt32 index, const nsAString & label, const nsAString & value, nsIDOMXULSelectControlItemElement **_retval NS_OUTPARAM) { return _to InsertItemAt(index, label, value, _retval); } \
  NS_SCRIPTABLE NS_IMETHOD RemoveItemAt(PRInt32 index, nsIDOMXULSelectControlItemElement **_retval NS_OUTPARAM) { return _to RemoveItemAt(index, _retval); } \
  NS_SCRIPTABLE NS_IMETHOD GetItemCount(PRUint32 *aItemCount) { return _to GetItemCount(aItemCount); } \
  NS_SCRIPTABLE NS_IMETHOD GetIndexOfItem(nsIDOMXULSelectControlItemElement *item, PRInt32 *_retval NS_OUTPARAM) { return _to GetIndexOfItem(item, _retval); } \
  NS_SCRIPTABLE NS_IMETHOD GetItemAtIndex(PRInt32 index, nsIDOMXULSelectControlItemElement **_retval NS_OUTPARAM) { return _to GetItemAtIndex(index, _retval); } 

/* Use this macro to declare functions that forward the behavior of this interface to another object in a safe way. */
#define NS_FORWARD_SAFE_NSIDOMXULSELECTCONTROLELEMENT(_to) \
  NS_SCRIPTABLE NS_IMETHOD GetSelectedItem(nsIDOMXULSelectControlItemElement * *aSelectedItem) { return !_to ? NS_ERROR_NULL_POINTER : _to->GetSelectedItem(aSelectedItem); } \
  NS_SCRIPTABLE NS_IMETHOD SetSelectedItem(nsIDOMXULSelectControlItemElement * aSelectedItem) { return !_to ? NS_ERROR_NULL_POINTER : _to->SetSelectedItem(aSelectedItem); } \
  NS_SCRIPTABLE NS_IMETHOD GetSelectedIndex(PRInt32 *aSelectedIndex) { return !_to ? NS_ERROR_NULL_POINTER : _to->GetSelectedIndex(aSelectedIndex); } \
  NS_SCRIPTABLE NS_IMETHOD SetSelectedIndex(PRInt32 aSelectedIndex) { return !_to ? NS_ERROR_NULL_POINTER : _to->SetSelectedIndex(aSelectedIndex); } \
  NS_SCRIPTABLE NS_IMETHOD GetValue(nsAString & aValue) { return !_to ? NS_ERROR_NULL_POINTER : _to->GetValue(aValue); } \
  NS_SCRIPTABLE NS_IMETHOD SetValue(const nsAString & aValue) { return !_to ? NS_ERROR_NULL_POINTER : _to->SetValue(aValue); } \
  NS_SCRIPTABLE NS_IMETHOD AppendItem(const nsAString & label, const nsAString & value, nsIDOMXULSelectControlItemElement **_retval NS_OUTPARAM) { return !_to ? NS_ERROR_NULL_POINTER : _to->AppendItem(label, value, _retval); } \
  NS_SCRIPTABLE NS_IMETHOD InsertItemAt(PRInt32 index, const nsAString & label, const nsAString & value, nsIDOMXULSelectControlItemElement **_retval NS_OUTPARAM) { return !_to ? NS_ERROR_NULL_POINTER : _to->InsertItemAt(index, label, value, _retval); } \
  NS_SCRIPTABLE NS_IMETHOD RemoveItemAt(PRInt32 index, nsIDOMXULSelectControlItemElement **_retval NS_OUTPARAM) { return !_to ? NS_ERROR_NULL_POINTER : _to->RemoveItemAt(index, _retval); } \
  NS_SCRIPTABLE NS_IMETHOD GetItemCount(PRUint32 *aItemCount) { return !_to ? NS_ERROR_NULL_POINTER : _to->GetItemCount(aItemCount); } \
  NS_SCRIPTABLE NS_IMETHOD GetIndexOfItem(nsIDOMXULSelectControlItemElement *item, PRInt32 *_retval NS_OUTPARAM) { return !_to ? NS_ERROR_NULL_POINTER : _to->GetIndexOfItem(item, _retval); } \
  NS_SCRIPTABLE NS_IMETHOD GetItemAtIndex(PRInt32 index, nsIDOMXULSelectControlItemElement **_retval NS_OUTPARAM) { return !_to ? NS_ERROR_NULL_POINTER : _to->GetItemAtIndex(index, _retval); } 

#if 0
/* Use the code below as a template for the implementation class for this interface. */

/* Header file */
class nsDOMXULSelectControlElement : public nsIDOMXULSelectControlElement
{
public:
  NS_DECL_ISUPPORTS
  NS_DECL_NSIDOMXULSELECTCONTROLELEMENT

  nsDOMXULSelectControlElement();

private:
  ~nsDOMXULSelectControlElement();

protected:
  /* additional members */
};

/* Implementation file */
NS_IMPL_ISUPPORTS1(nsDOMXULSelectControlElement, nsIDOMXULSelectControlElement)

nsDOMXULSelectControlElement::nsDOMXULSelectControlElement()
{
  /* member initializers and constructor code */
}

nsDOMXULSelectControlElement::~nsDOMXULSelectControlElement()
{
  /* destructor code */
}

/* attribute nsIDOMXULSelectControlItemElement selectedItem; */
NS_IMETHODIMP nsDOMXULSelectControlElement::GetSelectedItem(nsIDOMXULSelectControlItemElement * *aSelectedItem)
{
    return NS_ERROR_NOT_IMPLEMENTED;
}
NS_IMETHODIMP nsDOMXULSelectControlElement::SetSelectedItem(nsIDOMXULSelectControlItemElement * aSelectedItem)
{
    return NS_ERROR_NOT_IMPLEMENTED;
}

/* attribute long selectedIndex; */
NS_IMETHODIMP nsDOMXULSelectControlElement::GetSelectedIndex(PRInt32 *aSelectedIndex)
{
    return NS_ERROR_NOT_IMPLEMENTED;
}
NS_IMETHODIMP nsDOMXULSelectControlElement::SetSelectedIndex(PRInt32 aSelectedIndex)
{
    return NS_ERROR_NOT_IMPLEMENTED;
}

/* attribute DOMString value; */
NS_IMETHODIMP nsDOMXULSelectControlElement::GetValue(nsAString & aValue)
{
    return NS_ERROR_NOT_IMPLEMENTED;
}
NS_IMETHODIMP nsDOMXULSelectControlElement::SetValue(const nsAString & aValue)
{
    return NS_ERROR_NOT_IMPLEMENTED;
}

/* nsIDOMXULSelectControlItemElement appendItem (in DOMString label, in DOMString value); */
NS_IMETHODIMP nsDOMXULSelectControlElement::AppendItem(const nsAString & label, const nsAString & value, nsIDOMXULSelectControlItemElement **_retval NS_OUTPARAM)
{
    return NS_ERROR_NOT_IMPLEMENTED;
}

/* nsIDOMXULSelectControlItemElement insertItemAt (in long index, in DOMString label, in DOMString value); */
NS_IMETHODIMP nsDOMXULSelectControlElement::InsertItemAt(PRInt32 index, const nsAString & label, const nsAString & value, nsIDOMXULSelectControlItemElement **_retval NS_OUTPARAM)
{
    return NS_ERROR_NOT_IMPLEMENTED;
}

/* nsIDOMXULSelectControlItemElement removeItemAt (in long index); */
NS_IMETHODIMP nsDOMXULSelectControlElement::RemoveItemAt(PRInt32 index, nsIDOMXULSelectControlItemElement **_retval NS_OUTPARAM)
{
    return NS_ERROR_NOT_IMPLEMENTED;
}

/* readonly attribute unsigned long itemCount; */
NS_IMETHODIMP nsDOMXULSelectControlElement::GetItemCount(PRUint32 *aItemCount)
{
    return NS_ERROR_NOT_IMPLEMENTED;
}

/* long getIndexOfItem (in nsIDOMXULSelectControlItemElement item); */
NS_IMETHODIMP nsDOMXULSelectControlElement::GetIndexOfItem(nsIDOMXULSelectControlItemElement *item, PRInt32 *_retval NS_OUTPARAM)
{
    return NS_ERROR_NOT_IMPLEMENTED;
}

/* nsIDOMXULSelectControlItemElement getItemAtIndex (in long index); */
NS_IMETHODIMP nsDOMXULSelectControlElement::GetItemAtIndex(PRInt32 index, nsIDOMXULSelectControlItemElement **_retval NS_OUTPARAM)
{
    return NS_ERROR_NOT_IMPLEMENTED;
}

/* End of implementation class template. */
#endif


#endif /* __gen_nsIDOMXULSelectCntrlEl_h__ */
