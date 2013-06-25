/*
 * DO NOT EDIT.  THIS FILE IS GENERATED FROM e:/builds/moz2_slave/mozilla-1.9.1-win32-xulrunner/build/layout/xul/base/public/nsIListBoxObject.idl
 */

#ifndef __gen_nsIListBoxObject_h__
#define __gen_nsIListBoxObject_h__


#ifndef __gen_nsIBoxObject_h__
#include "nsIBoxObject.h"
#endif

/* For IDL files that don't want to include root IDL files. */
#ifndef NS_NO_VTABLE
#define NS_NO_VTABLE
#endif
class nsIDOMElement; /* forward declaration */


/* starting interface:    nsIListBoxObject */
#define NS_ILISTBOXOBJECT_IID_STR "aa9def4e-2e59-412d-a6df-b76f52167795"

#define NS_ILISTBOXOBJECT_IID \
  {0xaa9def4e, 0x2e59, 0x412d, \
    { 0xa6, 0xdf, 0xb7, 0x6f, 0x52, 0x16, 0x77, 0x95 }}

class NS_NO_VTABLE NS_SCRIPTABLE nsIListBoxObject : public nsISupports {
 public: 

  NS_DECLARE_STATIC_IID_ACCESSOR(NS_ILISTBOXOBJECT_IID)

  /* long getRowCount (); */
  NS_SCRIPTABLE NS_IMETHOD GetRowCount(PRInt32 *_retval NS_OUTPARAM) = 0;

  /* long getNumberOfVisibleRows (); */
  NS_SCRIPTABLE NS_IMETHOD GetNumberOfVisibleRows(PRInt32 *_retval NS_OUTPARAM) = 0;

  /* long getIndexOfFirstVisibleRow (); */
  NS_SCRIPTABLE NS_IMETHOD GetIndexOfFirstVisibleRow(PRInt32 *_retval NS_OUTPARAM) = 0;

  /* void ensureIndexIsVisible (in long rowIndex); */
  NS_SCRIPTABLE NS_IMETHOD EnsureIndexIsVisible(PRInt32 rowIndex) = 0;

  /* void scrollToIndex (in long rowIndex); */
  NS_SCRIPTABLE NS_IMETHOD ScrollToIndex(PRInt32 rowIndex) = 0;

  /* void scrollByLines (in long numLines); */
  NS_SCRIPTABLE NS_IMETHOD ScrollByLines(PRInt32 numLines) = 0;

  /* nsIDOMElement getItemAtIndex (in long index); */
  NS_SCRIPTABLE NS_IMETHOD GetItemAtIndex(PRInt32 index, nsIDOMElement **_retval NS_OUTPARAM) = 0;

  /* long getIndexOfItem (in nsIDOMElement item); */
  NS_SCRIPTABLE NS_IMETHOD GetIndexOfItem(nsIDOMElement *item, PRInt32 *_retval NS_OUTPARAM) = 0;

};

  NS_DEFINE_STATIC_IID_ACCESSOR(nsIListBoxObject, NS_ILISTBOXOBJECT_IID)

/* Use this macro when declaring classes that implement this interface. */
#define NS_DECL_NSILISTBOXOBJECT \
  NS_SCRIPTABLE NS_IMETHOD GetRowCount(PRInt32 *_retval NS_OUTPARAM); \
  NS_SCRIPTABLE NS_IMETHOD GetNumberOfVisibleRows(PRInt32 *_retval NS_OUTPARAM); \
  NS_SCRIPTABLE NS_IMETHOD GetIndexOfFirstVisibleRow(PRInt32 *_retval NS_OUTPARAM); \
  NS_SCRIPTABLE NS_IMETHOD EnsureIndexIsVisible(PRInt32 rowIndex); \
  NS_SCRIPTABLE NS_IMETHOD ScrollToIndex(PRInt32 rowIndex); \
  NS_SCRIPTABLE NS_IMETHOD ScrollByLines(PRInt32 numLines); \
  NS_SCRIPTABLE NS_IMETHOD GetItemAtIndex(PRInt32 index, nsIDOMElement **_retval NS_OUTPARAM); \
  NS_SCRIPTABLE NS_IMETHOD GetIndexOfItem(nsIDOMElement *item, PRInt32 *_retval NS_OUTPARAM); 

/* Use this macro to declare functions that forward the behavior of this interface to another object. */
#define NS_FORWARD_NSILISTBOXOBJECT(_to) \
  NS_SCRIPTABLE NS_IMETHOD GetRowCount(PRInt32 *_retval NS_OUTPARAM) { return _to GetRowCount(_retval); } \
  NS_SCRIPTABLE NS_IMETHOD GetNumberOfVisibleRows(PRInt32 *_retval NS_OUTPARAM) { return _to GetNumberOfVisibleRows(_retval); } \
  NS_SCRIPTABLE NS_IMETHOD GetIndexOfFirstVisibleRow(PRInt32 *_retval NS_OUTPARAM) { return _to GetIndexOfFirstVisibleRow(_retval); } \
  NS_SCRIPTABLE NS_IMETHOD EnsureIndexIsVisible(PRInt32 rowIndex) { return _to EnsureIndexIsVisible(rowIndex); } \
  NS_SCRIPTABLE NS_IMETHOD ScrollToIndex(PRInt32 rowIndex) { return _to ScrollToIndex(rowIndex); } \
  NS_SCRIPTABLE NS_IMETHOD ScrollByLines(PRInt32 numLines) { return _to ScrollByLines(numLines); } \
  NS_SCRIPTABLE NS_IMETHOD GetItemAtIndex(PRInt32 index, nsIDOMElement **_retval NS_OUTPARAM) { return _to GetItemAtIndex(index, _retval); } \
  NS_SCRIPTABLE NS_IMETHOD GetIndexOfItem(nsIDOMElement *item, PRInt32 *_retval NS_OUTPARAM) { return _to GetIndexOfItem(item, _retval); } 

/* Use this macro to declare functions that forward the behavior of this interface to another object in a safe way. */
#define NS_FORWARD_SAFE_NSILISTBOXOBJECT(_to) \
  NS_SCRIPTABLE NS_IMETHOD GetRowCount(PRInt32 *_retval NS_OUTPARAM) { return !_to ? NS_ERROR_NULL_POINTER : _to->GetRowCount(_retval); } \
  NS_SCRIPTABLE NS_IMETHOD GetNumberOfVisibleRows(PRInt32 *_retval NS_OUTPARAM) { return !_to ? NS_ERROR_NULL_POINTER : _to->GetNumberOfVisibleRows(_retval); } \
  NS_SCRIPTABLE NS_IMETHOD GetIndexOfFirstVisibleRow(PRInt32 *_retval NS_OUTPARAM) { return !_to ? NS_ERROR_NULL_POINTER : _to->GetIndexOfFirstVisibleRow(_retval); } \
  NS_SCRIPTABLE NS_IMETHOD EnsureIndexIsVisible(PRInt32 rowIndex) { return !_to ? NS_ERROR_NULL_POINTER : _to->EnsureIndexIsVisible(rowIndex); } \
  NS_SCRIPTABLE NS_IMETHOD ScrollToIndex(PRInt32 rowIndex) { return !_to ? NS_ERROR_NULL_POINTER : _to->ScrollToIndex(rowIndex); } \
  NS_SCRIPTABLE NS_IMETHOD ScrollByLines(PRInt32 numLines) { return !_to ? NS_ERROR_NULL_POINTER : _to->ScrollByLines(numLines); } \
  NS_SCRIPTABLE NS_IMETHOD GetItemAtIndex(PRInt32 index, nsIDOMElement **_retval NS_OUTPARAM) { return !_to ? NS_ERROR_NULL_POINTER : _to->GetItemAtIndex(index, _retval); } \
  NS_SCRIPTABLE NS_IMETHOD GetIndexOfItem(nsIDOMElement *item, PRInt32 *_retval NS_OUTPARAM) { return !_to ? NS_ERROR_NULL_POINTER : _to->GetIndexOfItem(item, _retval); } 

#if 0
/* Use the code below as a template for the implementation class for this interface. */

/* Header file */
class nsListBoxObject : public nsIListBoxObject
{
public:
  NS_DECL_ISUPPORTS
  NS_DECL_NSILISTBOXOBJECT

  nsListBoxObject();

private:
  ~nsListBoxObject();

protected:
  /* additional members */
};

/* Implementation file */
NS_IMPL_ISUPPORTS1(nsListBoxObject, nsIListBoxObject)

nsListBoxObject::nsListBoxObject()
{
  /* member initializers and constructor code */
}

nsListBoxObject::~nsListBoxObject()
{
  /* destructor code */
}

/* long getRowCount (); */
NS_IMETHODIMP nsListBoxObject::GetRowCount(PRInt32 *_retval NS_OUTPARAM)
{
    return NS_ERROR_NOT_IMPLEMENTED;
}

/* long getNumberOfVisibleRows (); */
NS_IMETHODIMP nsListBoxObject::GetNumberOfVisibleRows(PRInt32 *_retval NS_OUTPARAM)
{
    return NS_ERROR_NOT_IMPLEMENTED;
}

/* long getIndexOfFirstVisibleRow (); */
NS_IMETHODIMP nsListBoxObject::GetIndexOfFirstVisibleRow(PRInt32 *_retval NS_OUTPARAM)
{
    return NS_ERROR_NOT_IMPLEMENTED;
}

/* void ensureIndexIsVisible (in long rowIndex); */
NS_IMETHODIMP nsListBoxObject::EnsureIndexIsVisible(PRInt32 rowIndex)
{
    return NS_ERROR_NOT_IMPLEMENTED;
}

/* void scrollToIndex (in long rowIndex); */
NS_IMETHODIMP nsListBoxObject::ScrollToIndex(PRInt32 rowIndex)
{
    return NS_ERROR_NOT_IMPLEMENTED;
}

/* void scrollByLines (in long numLines); */
NS_IMETHODIMP nsListBoxObject::ScrollByLines(PRInt32 numLines)
{
    return NS_ERROR_NOT_IMPLEMENTED;
}

/* nsIDOMElement getItemAtIndex (in long index); */
NS_IMETHODIMP nsListBoxObject::GetItemAtIndex(PRInt32 index, nsIDOMElement **_retval NS_OUTPARAM)
{
    return NS_ERROR_NOT_IMPLEMENTED;
}

/* long getIndexOfItem (in nsIDOMElement item); */
NS_IMETHODIMP nsListBoxObject::GetIndexOfItem(nsIDOMElement *item, PRInt32 *_retval NS_OUTPARAM)
{
    return NS_ERROR_NOT_IMPLEMENTED;
}

/* End of implementation class template. */
#endif

nsresult
NS_NewListBoxObject(nsIBoxObject** aResult);

#endif /* __gen_nsIListBoxObject_h__ */
