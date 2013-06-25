/*
 * DO NOT EDIT.  THIS FILE IS GENERATED FROM e:/builds/moz2_slave/mozilla-1.9.1-win32-xulrunner/build/dom/public/idl/xul/nsIDOMXULContainerElement.idl
 */

#ifndef __gen_nsIDOMXULContainerElement_h__
#define __gen_nsIDOMXULContainerElement_h__


#ifndef __gen_nsIDOMXULElement_h__
#include "nsIDOMXULElement.h"
#endif

/* For IDL files that don't want to include root IDL files. */
#ifndef NS_NO_VTABLE
#define NS_NO_VTABLE
#endif
class nsIDOMXULContainerElement; /* forward declaration */


/* starting interface:    nsIDOMXULContainerItemElement */
#define NS_IDOMXULCONTAINERITEMELEMENT_IID_STR "4650e55f-4777-4271-8b62-9603a7dd4614"

#define NS_IDOMXULCONTAINERITEMELEMENT_IID \
  {0x4650e55f, 0x4777, 0x4271, \
    { 0x8b, 0x62, 0x96, 0x03, 0xa7, 0xdd, 0x46, 0x14 }}

class NS_NO_VTABLE NS_SCRIPTABLE nsIDOMXULContainerItemElement : public nsIDOMXULElement {
 public: 

  NS_DECLARE_STATIC_IID_ACCESSOR(NS_IDOMXULCONTAINERITEMELEMENT_IID)

  /**
   * Returns the parent container if any.
   */
  /* readonly attribute nsIDOMXULContainerElement parentContainer; */
  NS_SCRIPTABLE NS_IMETHOD GetParentContainer(nsIDOMXULContainerElement * *aParentContainer) = 0;

};

  NS_DEFINE_STATIC_IID_ACCESSOR(nsIDOMXULContainerItemElement, NS_IDOMXULCONTAINERITEMELEMENT_IID)

/* Use this macro when declaring classes that implement this interface. */
#define NS_DECL_NSIDOMXULCONTAINERITEMELEMENT \
  NS_SCRIPTABLE NS_IMETHOD GetParentContainer(nsIDOMXULContainerElement * *aParentContainer); 

/* Use this macro to declare functions that forward the behavior of this interface to another object. */
#define NS_FORWARD_NSIDOMXULCONTAINERITEMELEMENT(_to) \
  NS_SCRIPTABLE NS_IMETHOD GetParentContainer(nsIDOMXULContainerElement * *aParentContainer) { return _to GetParentContainer(aParentContainer); } 

/* Use this macro to declare functions that forward the behavior of this interface to another object in a safe way. */
#define NS_FORWARD_SAFE_NSIDOMXULCONTAINERITEMELEMENT(_to) \
  NS_SCRIPTABLE NS_IMETHOD GetParentContainer(nsIDOMXULContainerElement * *aParentContainer) { return !_to ? NS_ERROR_NULL_POINTER : _to->GetParentContainer(aParentContainer); } 

#if 0
/* Use the code below as a template for the implementation class for this interface. */

/* Header file */
class nsDOMXULContainerItemElement : public nsIDOMXULContainerItemElement
{
public:
  NS_DECL_ISUPPORTS
  NS_DECL_NSIDOMXULCONTAINERITEMELEMENT

  nsDOMXULContainerItemElement();

private:
  ~nsDOMXULContainerItemElement();

protected:
  /* additional members */
};

/* Implementation file */
NS_IMPL_ISUPPORTS1(nsDOMXULContainerItemElement, nsIDOMXULContainerItemElement)

nsDOMXULContainerItemElement::nsDOMXULContainerItemElement()
{
  /* member initializers and constructor code */
}

nsDOMXULContainerItemElement::~nsDOMXULContainerItemElement()
{
  /* destructor code */
}

/* readonly attribute nsIDOMXULContainerElement parentContainer; */
NS_IMETHODIMP nsDOMXULContainerItemElement::GetParentContainer(nsIDOMXULContainerElement * *aParentContainer)
{
    return NS_ERROR_NOT_IMPLEMENTED;
}

/* End of implementation class template. */
#endif


/* starting interface:    nsIDOMXULContainerElement */
#define NS_IDOMXULCONTAINERELEMENT_IID_STR "bc07c626-4294-43ae-9b0a-e726de0adcad"

#define NS_IDOMXULCONTAINERELEMENT_IID \
  {0xbc07c626, 0x4294, 0x43ae, \
    { 0x9b, 0x0a, 0xe7, 0x26, 0xde, 0x0a, 0xdc, 0xad }}

class NS_NO_VTABLE NS_SCRIPTABLE nsIDOMXULContainerElement : public nsIDOMXULContainerItemElement {
 public: 

  NS_DECLARE_STATIC_IID_ACCESSOR(NS_IDOMXULCONTAINERELEMENT_IID)

  /**
   * Creates an item for the given label and value and appends it to the
   * container.
   *
   * @param aLabel - the label for the new item
   * @param aValue - the value of the new item
   */
  /* nsIDOMXULElement appendItem (in DOMString aLabel, in DOMString aValue); */
  NS_SCRIPTABLE NS_IMETHOD AppendItem(const nsAString & aLabel, const nsAString & aValue, nsIDOMXULElement **_retval NS_OUTPARAM) = 0;

  /**
   * Creates an item for the given label and value and inserts it into the
   * container at the specified position.
   *
   * @param aIndex - the index where the new item will be inserted
   * @param aLabel - the label for the new item
   * @param aValue - the value of the new item
   */
  /* nsIDOMXULElement insertItemAt (in long aIndex, in DOMString aLabel, in DOMString aValue); */
  NS_SCRIPTABLE NS_IMETHOD InsertItemAt(PRInt32 aIndex, const nsAString & aLabel, const nsAString & aValue, nsIDOMXULElement **_retval NS_OUTPARAM) = 0;

  /**
   * Removes an item from the container.
   *
   * @param aIndex - index of the item to remove
   */
  /* nsIDOMXULElement removeItemAt (in long aIndex); */
  NS_SCRIPTABLE NS_IMETHOD RemoveItemAt(PRInt32 aIndex, nsIDOMXULElement **_retval NS_OUTPARAM) = 0;

  /**
   * Returns a count of items in the container.
   */
  /* readonly attribute unsigned long itemCount; */
  NS_SCRIPTABLE NS_IMETHOD GetItemCount(PRUint32 *aItemCount) = 0;

  /**
   * Returns the index of an item or -1 if the item is not in the container.
   *
   * @param aItem - the item to determine the index of
   */
  /* long getIndexOfItem (in nsIDOMXULElement aItem); */
  NS_SCRIPTABLE NS_IMETHOD GetIndexOfItem(nsIDOMXULElement *aItem, PRInt32 *_retval NS_OUTPARAM) = 0;

  /**
   * Returns the item at a given index or null if the item is not is the
   * container.
   *
   * @param aIndex - the index of the item to return
   */
  /* nsIDOMXULElement getItemAtIndex (in long aIndex); */
  NS_SCRIPTABLE NS_IMETHOD GetItemAtIndex(PRInt32 aIndex, nsIDOMXULElement **_retval NS_OUTPARAM) = 0;

};

  NS_DEFINE_STATIC_IID_ACCESSOR(nsIDOMXULContainerElement, NS_IDOMXULCONTAINERELEMENT_IID)

/* Use this macro when declaring classes that implement this interface. */
#define NS_DECL_NSIDOMXULCONTAINERELEMENT \
  NS_SCRIPTABLE NS_IMETHOD AppendItem(const nsAString & aLabel, const nsAString & aValue, nsIDOMXULElement **_retval NS_OUTPARAM); \
  NS_SCRIPTABLE NS_IMETHOD InsertItemAt(PRInt32 aIndex, const nsAString & aLabel, const nsAString & aValue, nsIDOMXULElement **_retval NS_OUTPARAM); \
  NS_SCRIPTABLE NS_IMETHOD RemoveItemAt(PRInt32 aIndex, nsIDOMXULElement **_retval NS_OUTPARAM); \
  NS_SCRIPTABLE NS_IMETHOD GetItemCount(PRUint32 *aItemCount); \
  NS_SCRIPTABLE NS_IMETHOD GetIndexOfItem(nsIDOMXULElement *aItem, PRInt32 *_retval NS_OUTPARAM); \
  NS_SCRIPTABLE NS_IMETHOD GetItemAtIndex(PRInt32 aIndex, nsIDOMXULElement **_retval NS_OUTPARAM); 

/* Use this macro to declare functions that forward the behavior of this interface to another object. */
#define NS_FORWARD_NSIDOMXULCONTAINERELEMENT(_to) \
  NS_SCRIPTABLE NS_IMETHOD AppendItem(const nsAString & aLabel, const nsAString & aValue, nsIDOMXULElement **_retval NS_OUTPARAM) { return _to AppendItem(aLabel, aValue, _retval); } \
  NS_SCRIPTABLE NS_IMETHOD InsertItemAt(PRInt32 aIndex, const nsAString & aLabel, const nsAString & aValue, nsIDOMXULElement **_retval NS_OUTPARAM) { return _to InsertItemAt(aIndex, aLabel, aValue, _retval); } \
  NS_SCRIPTABLE NS_IMETHOD RemoveItemAt(PRInt32 aIndex, nsIDOMXULElement **_retval NS_OUTPARAM) { return _to RemoveItemAt(aIndex, _retval); } \
  NS_SCRIPTABLE NS_IMETHOD GetItemCount(PRUint32 *aItemCount) { return _to GetItemCount(aItemCount); } \
  NS_SCRIPTABLE NS_IMETHOD GetIndexOfItem(nsIDOMXULElement *aItem, PRInt32 *_retval NS_OUTPARAM) { return _to GetIndexOfItem(aItem, _retval); } \
  NS_SCRIPTABLE NS_IMETHOD GetItemAtIndex(PRInt32 aIndex, nsIDOMXULElement **_retval NS_OUTPARAM) { return _to GetItemAtIndex(aIndex, _retval); } 

/* Use this macro to declare functions that forward the behavior of this interface to another object in a safe way. */
#define NS_FORWARD_SAFE_NSIDOMXULCONTAINERELEMENT(_to) \
  NS_SCRIPTABLE NS_IMETHOD AppendItem(const nsAString & aLabel, const nsAString & aValue, nsIDOMXULElement **_retval NS_OUTPARAM) { return !_to ? NS_ERROR_NULL_POINTER : _to->AppendItem(aLabel, aValue, _retval); } \
  NS_SCRIPTABLE NS_IMETHOD InsertItemAt(PRInt32 aIndex, const nsAString & aLabel, const nsAString & aValue, nsIDOMXULElement **_retval NS_OUTPARAM) { return !_to ? NS_ERROR_NULL_POINTER : _to->InsertItemAt(aIndex, aLabel, aValue, _retval); } \
  NS_SCRIPTABLE NS_IMETHOD RemoveItemAt(PRInt32 aIndex, nsIDOMXULElement **_retval NS_OUTPARAM) { return !_to ? NS_ERROR_NULL_POINTER : _to->RemoveItemAt(aIndex, _retval); } \
  NS_SCRIPTABLE NS_IMETHOD GetItemCount(PRUint32 *aItemCount) { return !_to ? NS_ERROR_NULL_POINTER : _to->GetItemCount(aItemCount); } \
  NS_SCRIPTABLE NS_IMETHOD GetIndexOfItem(nsIDOMXULElement *aItem, PRInt32 *_retval NS_OUTPARAM) { return !_to ? NS_ERROR_NULL_POINTER : _to->GetIndexOfItem(aItem, _retval); } \
  NS_SCRIPTABLE NS_IMETHOD GetItemAtIndex(PRInt32 aIndex, nsIDOMXULElement **_retval NS_OUTPARAM) { return !_to ? NS_ERROR_NULL_POINTER : _to->GetItemAtIndex(aIndex, _retval); } 

#if 0
/* Use the code below as a template for the implementation class for this interface. */

/* Header file */
class nsDOMXULContainerElement : public nsIDOMXULContainerElement
{
public:
  NS_DECL_ISUPPORTS
  NS_DECL_NSIDOMXULCONTAINERELEMENT

  nsDOMXULContainerElement();

private:
  ~nsDOMXULContainerElement();

protected:
  /* additional members */
};

/* Implementation file */
NS_IMPL_ISUPPORTS1(nsDOMXULContainerElement, nsIDOMXULContainerElement)

nsDOMXULContainerElement::nsDOMXULContainerElement()
{
  /* member initializers and constructor code */
}

nsDOMXULContainerElement::~nsDOMXULContainerElement()
{
  /* destructor code */
}

/* nsIDOMXULElement appendItem (in DOMString aLabel, in DOMString aValue); */
NS_IMETHODIMP nsDOMXULContainerElement::AppendItem(const nsAString & aLabel, const nsAString & aValue, nsIDOMXULElement **_retval NS_OUTPARAM)
{
    return NS_ERROR_NOT_IMPLEMENTED;
}

/* nsIDOMXULElement insertItemAt (in long aIndex, in DOMString aLabel, in DOMString aValue); */
NS_IMETHODIMP nsDOMXULContainerElement::InsertItemAt(PRInt32 aIndex, const nsAString & aLabel, const nsAString & aValue, nsIDOMXULElement **_retval NS_OUTPARAM)
{
    return NS_ERROR_NOT_IMPLEMENTED;
}

/* nsIDOMXULElement removeItemAt (in long aIndex); */
NS_IMETHODIMP nsDOMXULContainerElement::RemoveItemAt(PRInt32 aIndex, nsIDOMXULElement **_retval NS_OUTPARAM)
{
    return NS_ERROR_NOT_IMPLEMENTED;
}

/* readonly attribute unsigned long itemCount; */
NS_IMETHODIMP nsDOMXULContainerElement::GetItemCount(PRUint32 *aItemCount)
{
    return NS_ERROR_NOT_IMPLEMENTED;
}

/* long getIndexOfItem (in nsIDOMXULElement aItem); */
NS_IMETHODIMP nsDOMXULContainerElement::GetIndexOfItem(nsIDOMXULElement *aItem, PRInt32 *_retval NS_OUTPARAM)
{
    return NS_ERROR_NOT_IMPLEMENTED;
}

/* nsIDOMXULElement getItemAtIndex (in long aIndex); */
NS_IMETHODIMP nsDOMXULContainerElement::GetItemAtIndex(PRInt32 aIndex, nsIDOMXULElement **_retval NS_OUTPARAM)
{
    return NS_ERROR_NOT_IMPLEMENTED;
}

/* End of implementation class template. */
#endif


#endif /* __gen_nsIDOMXULContainerElement_h__ */
