/*
 * DO NOT EDIT.  THIS FILE IS GENERATED FROM e:/builds/moz2_slave/mozilla-1.9.1-win32-xulrunner/build/dom/public/idl/xul/nsIDOMXULMultSelectCntrlEl.idl
 */

#ifndef __gen_nsIDOMXULMultSelectCntrlEl_h__
#define __gen_nsIDOMXULMultSelectCntrlEl_h__


#ifndef __gen_nsIDOMXULSelectCntrlEl_h__
#include "nsIDOMXULSelectCntrlEl.h"
#endif

/* For IDL files that don't want to include root IDL files. */
#ifndef NS_NO_VTABLE
#define NS_NO_VTABLE
#endif

/* starting interface:    nsIDOMXULMultiSelectControlElement */
#define NS_IDOMXULMULTISELECTCONTROLELEMENT_IID_STR "82c72eca-9886-473e-94cd-9de5694b3f88"

#define NS_IDOMXULMULTISELECTCONTROLELEMENT_IID \
  {0x82c72eca, 0x9886, 0x473e, \
    { 0x94, 0xcd, 0x9d, 0xe5, 0x69, 0x4b, 0x3f, 0x88 }}

class NS_NO_VTABLE NS_SCRIPTABLE nsIDOMXULMultiSelectControlElement : public nsIDOMXULSelectControlElement {
 public: 

  NS_DECLARE_STATIC_IID_ACCESSOR(NS_IDOMXULMULTISELECTCONTROLELEMENT_IID)

  /* attribute DOMString selType; */
  NS_SCRIPTABLE NS_IMETHOD GetSelType(nsAString & aSelType) = 0;
  NS_SCRIPTABLE NS_IMETHOD SetSelType(const nsAString & aSelType) = 0;

  /* attribute nsIDOMXULSelectControlItemElement currentItem; */
  NS_SCRIPTABLE NS_IMETHOD GetCurrentItem(nsIDOMXULSelectControlItemElement * *aCurrentItem) = 0;
  NS_SCRIPTABLE NS_IMETHOD SetCurrentItem(nsIDOMXULSelectControlItemElement * aCurrentItem) = 0;

  /* attribute long currentIndex; */
  NS_SCRIPTABLE NS_IMETHOD GetCurrentIndex(PRInt32 *aCurrentIndex) = 0;
  NS_SCRIPTABLE NS_IMETHOD SetCurrentIndex(PRInt32 aCurrentIndex) = 0;

  /* readonly attribute nsIDOMNodeList selectedItems; */
  NS_SCRIPTABLE NS_IMETHOD GetSelectedItems(nsIDOMNodeList * *aSelectedItems) = 0;

  /* void addItemToSelection (in nsIDOMXULSelectControlItemElement item); */
  NS_SCRIPTABLE NS_IMETHOD AddItemToSelection(nsIDOMXULSelectControlItemElement *item) = 0;

  /* void removeItemFromSelection (in nsIDOMXULSelectControlItemElement item); */
  NS_SCRIPTABLE NS_IMETHOD RemoveItemFromSelection(nsIDOMXULSelectControlItemElement *item) = 0;

  /* void toggleItemSelection (in nsIDOMXULSelectControlItemElement item); */
  NS_SCRIPTABLE NS_IMETHOD ToggleItemSelection(nsIDOMXULSelectControlItemElement *item) = 0;

  /* void selectItem (in nsIDOMXULSelectControlItemElement item); */
  NS_SCRIPTABLE NS_IMETHOD SelectItem(nsIDOMXULSelectControlItemElement *item) = 0;

  /* void selectItemRange (in nsIDOMXULSelectControlItemElement startItem, in nsIDOMXULSelectControlItemElement item); */
  NS_SCRIPTABLE NS_IMETHOD SelectItemRange(nsIDOMXULSelectControlItemElement *startItem, nsIDOMXULSelectControlItemElement *item) = 0;

  /* void selectAll (); */
  NS_SCRIPTABLE NS_IMETHOD SelectAll(void) = 0;

  /* void invertSelection (); */
  NS_SCRIPTABLE NS_IMETHOD InvertSelection(void) = 0;

  /* void clearSelection (); */
  NS_SCRIPTABLE NS_IMETHOD ClearSelection(void) = 0;

  /* readonly attribute long selectedCount; */
  NS_SCRIPTABLE NS_IMETHOD GetSelectedCount(PRInt32 *aSelectedCount) = 0;

  /* nsIDOMXULSelectControlItemElement getSelectedItem (in long index); */
  NS_SCRIPTABLE NS_IMETHOD GetSelectedItem(PRInt32 index, nsIDOMXULSelectControlItemElement **_retval NS_OUTPARAM) = 0;

};

  NS_DEFINE_STATIC_IID_ACCESSOR(nsIDOMXULMultiSelectControlElement, NS_IDOMXULMULTISELECTCONTROLELEMENT_IID)

/* Use this macro when declaring classes that implement this interface. */
#define NS_DECL_NSIDOMXULMULTISELECTCONTROLELEMENT \
  NS_SCRIPTABLE NS_IMETHOD GetSelType(nsAString & aSelType); \
  NS_SCRIPTABLE NS_IMETHOD SetSelType(const nsAString & aSelType); \
  NS_SCRIPTABLE NS_IMETHOD GetCurrentItem(nsIDOMXULSelectControlItemElement * *aCurrentItem); \
  NS_SCRIPTABLE NS_IMETHOD SetCurrentItem(nsIDOMXULSelectControlItemElement * aCurrentItem); \
  NS_SCRIPTABLE NS_IMETHOD GetCurrentIndex(PRInt32 *aCurrentIndex); \
  NS_SCRIPTABLE NS_IMETHOD SetCurrentIndex(PRInt32 aCurrentIndex); \
  NS_SCRIPTABLE NS_IMETHOD GetSelectedItems(nsIDOMNodeList * *aSelectedItems); \
  NS_SCRIPTABLE NS_IMETHOD AddItemToSelection(nsIDOMXULSelectControlItemElement *item); \
  NS_SCRIPTABLE NS_IMETHOD RemoveItemFromSelection(nsIDOMXULSelectControlItemElement *item); \
  NS_SCRIPTABLE NS_IMETHOD ToggleItemSelection(nsIDOMXULSelectControlItemElement *item); \
  NS_SCRIPTABLE NS_IMETHOD SelectItem(nsIDOMXULSelectControlItemElement *item); \
  NS_SCRIPTABLE NS_IMETHOD SelectItemRange(nsIDOMXULSelectControlItemElement *startItem, nsIDOMXULSelectControlItemElement *item); \
  NS_SCRIPTABLE NS_IMETHOD SelectAll(void); \
  NS_SCRIPTABLE NS_IMETHOD InvertSelection(void); \
  NS_SCRIPTABLE NS_IMETHOD ClearSelection(void); \
  NS_SCRIPTABLE NS_IMETHOD GetSelectedCount(PRInt32 *aSelectedCount); \
  NS_SCRIPTABLE NS_IMETHOD GetSelectedItem(PRInt32 index, nsIDOMXULSelectControlItemElement **_retval NS_OUTPARAM); 

/* Use this macro to declare functions that forward the behavior of this interface to another object. */
#define NS_FORWARD_NSIDOMXULMULTISELECTCONTROLELEMENT(_to) \
  NS_SCRIPTABLE NS_IMETHOD GetSelType(nsAString & aSelType) { return _to GetSelType(aSelType); } \
  NS_SCRIPTABLE NS_IMETHOD SetSelType(const nsAString & aSelType) { return _to SetSelType(aSelType); } \
  NS_SCRIPTABLE NS_IMETHOD GetCurrentItem(nsIDOMXULSelectControlItemElement * *aCurrentItem) { return _to GetCurrentItem(aCurrentItem); } \
  NS_SCRIPTABLE NS_IMETHOD SetCurrentItem(nsIDOMXULSelectControlItemElement * aCurrentItem) { return _to SetCurrentItem(aCurrentItem); } \
  NS_SCRIPTABLE NS_IMETHOD GetCurrentIndex(PRInt32 *aCurrentIndex) { return _to GetCurrentIndex(aCurrentIndex); } \
  NS_SCRIPTABLE NS_IMETHOD SetCurrentIndex(PRInt32 aCurrentIndex) { return _to SetCurrentIndex(aCurrentIndex); } \
  NS_SCRIPTABLE NS_IMETHOD GetSelectedItems(nsIDOMNodeList * *aSelectedItems) { return _to GetSelectedItems(aSelectedItems); } \
  NS_SCRIPTABLE NS_IMETHOD AddItemToSelection(nsIDOMXULSelectControlItemElement *item) { return _to AddItemToSelection(item); } \
  NS_SCRIPTABLE NS_IMETHOD RemoveItemFromSelection(nsIDOMXULSelectControlItemElement *item) { return _to RemoveItemFromSelection(item); } \
  NS_SCRIPTABLE NS_IMETHOD ToggleItemSelection(nsIDOMXULSelectControlItemElement *item) { return _to ToggleItemSelection(item); } \
  NS_SCRIPTABLE NS_IMETHOD SelectItem(nsIDOMXULSelectControlItemElement *item) { return _to SelectItem(item); } \
  NS_SCRIPTABLE NS_IMETHOD SelectItemRange(nsIDOMXULSelectControlItemElement *startItem, nsIDOMXULSelectControlItemElement *item) { return _to SelectItemRange(startItem, item); } \
  NS_SCRIPTABLE NS_IMETHOD SelectAll(void) { return _to SelectAll(); } \
  NS_SCRIPTABLE NS_IMETHOD InvertSelection(void) { return _to InvertSelection(); } \
  NS_SCRIPTABLE NS_IMETHOD ClearSelection(void) { return _to ClearSelection(); } \
  NS_SCRIPTABLE NS_IMETHOD GetSelectedCount(PRInt32 *aSelectedCount) { return _to GetSelectedCount(aSelectedCount); } \
  NS_SCRIPTABLE NS_IMETHOD GetSelectedItem(PRInt32 index, nsIDOMXULSelectControlItemElement **_retval NS_OUTPARAM) { return _to GetSelectedItem(index, _retval); } 

/* Use this macro to declare functions that forward the behavior of this interface to another object in a safe way. */
#define NS_FORWARD_SAFE_NSIDOMXULMULTISELECTCONTROLELEMENT(_to) \
  NS_SCRIPTABLE NS_IMETHOD GetSelType(nsAString & aSelType) { return !_to ? NS_ERROR_NULL_POINTER : _to->GetSelType(aSelType); } \
  NS_SCRIPTABLE NS_IMETHOD SetSelType(const nsAString & aSelType) { return !_to ? NS_ERROR_NULL_POINTER : _to->SetSelType(aSelType); } \
  NS_SCRIPTABLE NS_IMETHOD GetCurrentItem(nsIDOMXULSelectControlItemElement * *aCurrentItem) { return !_to ? NS_ERROR_NULL_POINTER : _to->GetCurrentItem(aCurrentItem); } \
  NS_SCRIPTABLE NS_IMETHOD SetCurrentItem(nsIDOMXULSelectControlItemElement * aCurrentItem) { return !_to ? NS_ERROR_NULL_POINTER : _to->SetCurrentItem(aCurrentItem); } \
  NS_SCRIPTABLE NS_IMETHOD GetCurrentIndex(PRInt32 *aCurrentIndex) { return !_to ? NS_ERROR_NULL_POINTER : _to->GetCurrentIndex(aCurrentIndex); } \
  NS_SCRIPTABLE NS_IMETHOD SetCurrentIndex(PRInt32 aCurrentIndex) { return !_to ? NS_ERROR_NULL_POINTER : _to->SetCurrentIndex(aCurrentIndex); } \
  NS_SCRIPTABLE NS_IMETHOD GetSelectedItems(nsIDOMNodeList * *aSelectedItems) { return !_to ? NS_ERROR_NULL_POINTER : _to->GetSelectedItems(aSelectedItems); } \
  NS_SCRIPTABLE NS_IMETHOD AddItemToSelection(nsIDOMXULSelectControlItemElement *item) { return !_to ? NS_ERROR_NULL_POINTER : _to->AddItemToSelection(item); } \
  NS_SCRIPTABLE NS_IMETHOD RemoveItemFromSelection(nsIDOMXULSelectControlItemElement *item) { return !_to ? NS_ERROR_NULL_POINTER : _to->RemoveItemFromSelection(item); } \
  NS_SCRIPTABLE NS_IMETHOD ToggleItemSelection(nsIDOMXULSelectControlItemElement *item) { return !_to ? NS_ERROR_NULL_POINTER : _to->ToggleItemSelection(item); } \
  NS_SCRIPTABLE NS_IMETHOD SelectItem(nsIDOMXULSelectControlItemElement *item) { return !_to ? NS_ERROR_NULL_POINTER : _to->SelectItem(item); } \
  NS_SCRIPTABLE NS_IMETHOD SelectItemRange(nsIDOMXULSelectControlItemElement *startItem, nsIDOMXULSelectControlItemElement *item) { return !_to ? NS_ERROR_NULL_POINTER : _to->SelectItemRange(startItem, item); } \
  NS_SCRIPTABLE NS_IMETHOD SelectAll(void) { return !_to ? NS_ERROR_NULL_POINTER : _to->SelectAll(); } \
  NS_SCRIPTABLE NS_IMETHOD InvertSelection(void) { return !_to ? NS_ERROR_NULL_POINTER : _to->InvertSelection(); } \
  NS_SCRIPTABLE NS_IMETHOD ClearSelection(void) { return !_to ? NS_ERROR_NULL_POINTER : _to->ClearSelection(); } \
  NS_SCRIPTABLE NS_IMETHOD GetSelectedCount(PRInt32 *aSelectedCount) { return !_to ? NS_ERROR_NULL_POINTER : _to->GetSelectedCount(aSelectedCount); } \
  NS_SCRIPTABLE NS_IMETHOD GetSelectedItem(PRInt32 index, nsIDOMXULSelectControlItemElement **_retval NS_OUTPARAM) { return !_to ? NS_ERROR_NULL_POINTER : _to->GetSelectedItem(index, _retval); } 

#if 0
/* Use the code below as a template for the implementation class for this interface. */

/* Header file */
class nsDOMXULMultiSelectControlElement : public nsIDOMXULMultiSelectControlElement
{
public:
  NS_DECL_ISUPPORTS
  NS_DECL_NSIDOMXULMULTISELECTCONTROLELEMENT

  nsDOMXULMultiSelectControlElement();

private:
  ~nsDOMXULMultiSelectControlElement();

protected:
  /* additional members */
};

/* Implementation file */
NS_IMPL_ISUPPORTS1(nsDOMXULMultiSelectControlElement, nsIDOMXULMultiSelectControlElement)

nsDOMXULMultiSelectControlElement::nsDOMXULMultiSelectControlElement()
{
  /* member initializers and constructor code */
}

nsDOMXULMultiSelectControlElement::~nsDOMXULMultiSelectControlElement()
{
  /* destructor code */
}

/* attribute DOMString selType; */
NS_IMETHODIMP nsDOMXULMultiSelectControlElement::GetSelType(nsAString & aSelType)
{
    return NS_ERROR_NOT_IMPLEMENTED;
}
NS_IMETHODIMP nsDOMXULMultiSelectControlElement::SetSelType(const nsAString & aSelType)
{
    return NS_ERROR_NOT_IMPLEMENTED;
}

/* attribute nsIDOMXULSelectControlItemElement currentItem; */
NS_IMETHODIMP nsDOMXULMultiSelectControlElement::GetCurrentItem(nsIDOMXULSelectControlItemElement * *aCurrentItem)
{
    return NS_ERROR_NOT_IMPLEMENTED;
}
NS_IMETHODIMP nsDOMXULMultiSelectControlElement::SetCurrentItem(nsIDOMXULSelectControlItemElement * aCurrentItem)
{
    return NS_ERROR_NOT_IMPLEMENTED;
}

/* attribute long currentIndex; */
NS_IMETHODIMP nsDOMXULMultiSelectControlElement::GetCurrentIndex(PRInt32 *aCurrentIndex)
{
    return NS_ERROR_NOT_IMPLEMENTED;
}
NS_IMETHODIMP nsDOMXULMultiSelectControlElement::SetCurrentIndex(PRInt32 aCurrentIndex)
{
    return NS_ERROR_NOT_IMPLEMENTED;
}

/* readonly attribute nsIDOMNodeList selectedItems; */
NS_IMETHODIMP nsDOMXULMultiSelectControlElement::GetSelectedItems(nsIDOMNodeList * *aSelectedItems)
{
    return NS_ERROR_NOT_IMPLEMENTED;
}

/* void addItemToSelection (in nsIDOMXULSelectControlItemElement item); */
NS_IMETHODIMP nsDOMXULMultiSelectControlElement::AddItemToSelection(nsIDOMXULSelectControlItemElement *item)
{
    return NS_ERROR_NOT_IMPLEMENTED;
}

/* void removeItemFromSelection (in nsIDOMXULSelectControlItemElement item); */
NS_IMETHODIMP nsDOMXULMultiSelectControlElement::RemoveItemFromSelection(nsIDOMXULSelectControlItemElement *item)
{
    return NS_ERROR_NOT_IMPLEMENTED;
}

/* void toggleItemSelection (in nsIDOMXULSelectControlItemElement item); */
NS_IMETHODIMP nsDOMXULMultiSelectControlElement::ToggleItemSelection(nsIDOMXULSelectControlItemElement *item)
{
    return NS_ERROR_NOT_IMPLEMENTED;
}

/* void selectItem (in nsIDOMXULSelectControlItemElement item); */
NS_IMETHODIMP nsDOMXULMultiSelectControlElement::SelectItem(nsIDOMXULSelectControlItemElement *item)
{
    return NS_ERROR_NOT_IMPLEMENTED;
}

/* void selectItemRange (in nsIDOMXULSelectControlItemElement startItem, in nsIDOMXULSelectControlItemElement item); */
NS_IMETHODIMP nsDOMXULMultiSelectControlElement::SelectItemRange(nsIDOMXULSelectControlItemElement *startItem, nsIDOMXULSelectControlItemElement *item)
{
    return NS_ERROR_NOT_IMPLEMENTED;
}

/* void selectAll (); */
NS_IMETHODIMP nsDOMXULMultiSelectControlElement::SelectAll()
{
    return NS_ERROR_NOT_IMPLEMENTED;
}

/* void invertSelection (); */
NS_IMETHODIMP nsDOMXULMultiSelectControlElement::InvertSelection()
{
    return NS_ERROR_NOT_IMPLEMENTED;
}

/* void clearSelection (); */
NS_IMETHODIMP nsDOMXULMultiSelectControlElement::ClearSelection()
{
    return NS_ERROR_NOT_IMPLEMENTED;
}

/* readonly attribute long selectedCount; */
NS_IMETHODIMP nsDOMXULMultiSelectControlElement::GetSelectedCount(PRInt32 *aSelectedCount)
{
    return NS_ERROR_NOT_IMPLEMENTED;
}

/* nsIDOMXULSelectControlItemElement getSelectedItem (in long index); */
NS_IMETHODIMP nsDOMXULMultiSelectControlElement::GetSelectedItem(PRInt32 index, nsIDOMXULSelectControlItemElement **_retval NS_OUTPARAM)
{
    return NS_ERROR_NOT_IMPLEMENTED;
}

/* End of implementation class template. */
#endif


#endif /* __gen_nsIDOMXULMultSelectCntrlEl_h__ */
