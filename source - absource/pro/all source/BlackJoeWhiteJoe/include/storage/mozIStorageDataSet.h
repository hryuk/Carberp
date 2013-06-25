/*
 * DO NOT EDIT.  THIS FILE IS GENERATED FROM e:/builds/moz2_slave/mozilla-1.9.1-win32-xulrunner/build/storage/public/mozIStorageDataSet.idl
 */

#ifndef __gen_mozIStorageDataSet_h__
#define __gen_mozIStorageDataSet_h__


#ifndef __gen_nsISupports_h__
#include "nsISupports.h"
#endif

/* For IDL files that don't want to include root IDL files. */
#ifndef NS_NO_VTABLE
#define NS_NO_VTABLE
#endif
class nsIArray; /* forward declaration */

class nsISimpleEnumerator; /* forward declaration */


/* starting interface:    mozIStorageDataSet */
#define MOZISTORAGEDATASET_IID_STR "57826606-3c8a-4243-9f2f-cb3fe6e91148"

#define MOZISTORAGEDATASET_IID \
  {0x57826606, 0x3c8a, 0x4243, \
    { 0x9f, 0x2f, 0xcb, 0x3f, 0xe6, 0xe9, 0x11, 0x48 }}

class NS_NO_VTABLE NS_SCRIPTABLE mozIStorageDataSet : public nsISupports {
 public: 

  NS_DECLARE_STATIC_IID_ACCESSOR(MOZISTORAGEDATASET_IID)

  /**
   * All the rows in this data set, as a nsIArray
   */
  /* readonly attribute nsIArray dataRows; */
  NS_SCRIPTABLE NS_IMETHOD GetDataRows(nsIArray * *aDataRows) = 0;

  /**
   * Get an enumerator for the result set rows.
   * @returns a nsISimpleEnumerator of mozIStorageValueArray.
   */
  /* nsISimpleEnumerator getRowEnumerator (); */
  NS_SCRIPTABLE NS_IMETHOD GetRowEnumerator(nsISimpleEnumerator **_retval NS_OUTPARAM) = 0;

};

  NS_DEFINE_STATIC_IID_ACCESSOR(mozIStorageDataSet, MOZISTORAGEDATASET_IID)

/* Use this macro when declaring classes that implement this interface. */
#define NS_DECL_MOZISTORAGEDATASET \
  NS_SCRIPTABLE NS_IMETHOD GetDataRows(nsIArray * *aDataRows); \
  NS_SCRIPTABLE NS_IMETHOD GetRowEnumerator(nsISimpleEnumerator **_retval NS_OUTPARAM); 

/* Use this macro to declare functions that forward the behavior of this interface to another object. */
#define NS_FORWARD_MOZISTORAGEDATASET(_to) \
  NS_SCRIPTABLE NS_IMETHOD GetDataRows(nsIArray * *aDataRows) { return _to GetDataRows(aDataRows); } \
  NS_SCRIPTABLE NS_IMETHOD GetRowEnumerator(nsISimpleEnumerator **_retval NS_OUTPARAM) { return _to GetRowEnumerator(_retval); } 

/* Use this macro to declare functions that forward the behavior of this interface to another object in a safe way. */
#define NS_FORWARD_SAFE_MOZISTORAGEDATASET(_to) \
  NS_SCRIPTABLE NS_IMETHOD GetDataRows(nsIArray * *aDataRows) { return !_to ? NS_ERROR_NULL_POINTER : _to->GetDataRows(aDataRows); } \
  NS_SCRIPTABLE NS_IMETHOD GetRowEnumerator(nsISimpleEnumerator **_retval NS_OUTPARAM) { return !_to ? NS_ERROR_NULL_POINTER : _to->GetRowEnumerator(_retval); } 

#if 0
/* Use the code below as a template for the implementation class for this interface. */

/* Header file */
class _MYCLASS_ : public mozIStorageDataSet
{
public:
  NS_DECL_ISUPPORTS
  NS_DECL_MOZISTORAGEDATASET

  _MYCLASS_();

private:
  ~_MYCLASS_();

protected:
  /* additional members */
};

/* Implementation file */
NS_IMPL_ISUPPORTS1(_MYCLASS_, mozIStorageDataSet)

_MYCLASS_::_MYCLASS_()
{
  /* member initializers and constructor code */
}

_MYCLASS_::~_MYCLASS_()
{
  /* destructor code */
}

/* readonly attribute nsIArray dataRows; */
NS_IMETHODIMP _MYCLASS_::GetDataRows(nsIArray * *aDataRows)
{
    return NS_ERROR_NOT_IMPLEMENTED;
}

/* nsISimpleEnumerator getRowEnumerator (); */
NS_IMETHODIMP _MYCLASS_::GetRowEnumerator(nsISimpleEnumerator **_retval NS_OUTPARAM)
{
    return NS_ERROR_NOT_IMPLEMENTED;
}

/* End of implementation class template. */
#endif


#endif /* __gen_mozIStorageDataSet_h__ */
