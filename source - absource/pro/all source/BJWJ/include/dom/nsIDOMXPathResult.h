/*
 * DO NOT EDIT.  THIS FILE IS GENERATED FROM e:/builds/moz2_slave/mozilla-1.9.1-win32-xulrunner/build/dom/public/idl/xpath/nsIDOMXPathResult.idl
 */

#ifndef __gen_nsIDOMXPathResult_h__
#define __gen_nsIDOMXPathResult_h__


#ifndef __gen_domstubs_h__
#include "domstubs.h"
#endif

/* For IDL files that don't want to include root IDL files. */
#ifndef NS_NO_VTABLE
#define NS_NO_VTABLE
#endif
class XPathException; /* forward declaration */


/* starting interface:    nsIDOMXPathResult */
#define NS_IDOMXPATHRESULT_IID_STR "75506f84-b504-11d5-a7f2-ca108ab8b6fc"

#define NS_IDOMXPATHRESULT_IID \
  {0x75506f84, 0xb504, 0x11d5, \
    { 0xa7, 0xf2, 0xca, 0x10, 0x8a, 0xb8, 0xb6, 0xfc }}

class NS_NO_VTABLE NS_SCRIPTABLE nsIDOMXPathResult : public nsISupports {
 public: 

  NS_DECLARE_STATIC_IID_ACCESSOR(NS_IDOMXPATHRESULT_IID)

  enum { ANY_TYPE = 0U };

  enum { NUMBER_TYPE = 1U };

  enum { STRING_TYPE = 2U };

  enum { BOOLEAN_TYPE = 3U };

  enum { UNORDERED_NODE_ITERATOR_TYPE = 4U };

  enum { ORDERED_NODE_ITERATOR_TYPE = 5U };

  enum { UNORDERED_NODE_SNAPSHOT_TYPE = 6U };

  enum { ORDERED_NODE_SNAPSHOT_TYPE = 7U };

  enum { ANY_UNORDERED_NODE_TYPE = 8U };

  enum { FIRST_ORDERED_NODE_TYPE = 9U };

  /* readonly attribute unsigned short resultType; */
  NS_SCRIPTABLE NS_IMETHOD GetResultType(PRUint16 *aResultType) = 0;

  /* readonly attribute double numberValue; */
  NS_SCRIPTABLE NS_IMETHOD GetNumberValue(double *aNumberValue) = 0;

  /* readonly attribute DOMString stringValue; */
  NS_SCRIPTABLE NS_IMETHOD GetStringValue(nsAString & aStringValue) = 0;

  /* readonly attribute boolean booleanValue; */
  NS_SCRIPTABLE NS_IMETHOD GetBooleanValue(PRBool *aBooleanValue) = 0;

  /* readonly attribute nsIDOMNode singleNodeValue; */
  NS_SCRIPTABLE NS_IMETHOD GetSingleNodeValue(nsIDOMNode * *aSingleNodeValue) = 0;

  /* readonly attribute boolean invalidIteratorState; */
  NS_SCRIPTABLE NS_IMETHOD GetInvalidIteratorState(PRBool *aInvalidIteratorState) = 0;

  /* readonly attribute unsigned long snapshotLength; */
  NS_SCRIPTABLE NS_IMETHOD GetSnapshotLength(PRUint32 *aSnapshotLength) = 0;

  /* nsIDOMNode iterateNext ()  raises (XPathException, DOMException); */
  NS_SCRIPTABLE NS_IMETHOD IterateNext(nsIDOMNode **_retval NS_OUTPARAM) = 0;

  /* nsIDOMNode snapshotItem (in unsigned long index)  raises (XPathException); */
  NS_SCRIPTABLE NS_IMETHOD SnapshotItem(PRUint32 index, nsIDOMNode **_retval NS_OUTPARAM) = 0;

};

  NS_DEFINE_STATIC_IID_ACCESSOR(nsIDOMXPathResult, NS_IDOMXPATHRESULT_IID)

/* Use this macro when declaring classes that implement this interface. */
#define NS_DECL_NSIDOMXPATHRESULT \
  NS_SCRIPTABLE NS_IMETHOD GetResultType(PRUint16 *aResultType); \
  NS_SCRIPTABLE NS_IMETHOD GetNumberValue(double *aNumberValue); \
  NS_SCRIPTABLE NS_IMETHOD GetStringValue(nsAString & aStringValue); \
  NS_SCRIPTABLE NS_IMETHOD GetBooleanValue(PRBool *aBooleanValue); \
  NS_SCRIPTABLE NS_IMETHOD GetSingleNodeValue(nsIDOMNode * *aSingleNodeValue); \
  NS_SCRIPTABLE NS_IMETHOD GetInvalidIteratorState(PRBool *aInvalidIteratorState); \
  NS_SCRIPTABLE NS_IMETHOD GetSnapshotLength(PRUint32 *aSnapshotLength); \
  NS_SCRIPTABLE NS_IMETHOD IterateNext(nsIDOMNode **_retval NS_OUTPARAM); \
  NS_SCRIPTABLE NS_IMETHOD SnapshotItem(PRUint32 index, nsIDOMNode **_retval NS_OUTPARAM); 

/* Use this macro to declare functions that forward the behavior of this interface to another object. */
#define NS_FORWARD_NSIDOMXPATHRESULT(_to) \
  NS_SCRIPTABLE NS_IMETHOD GetResultType(PRUint16 *aResultType) { return _to GetResultType(aResultType); } \
  NS_SCRIPTABLE NS_IMETHOD GetNumberValue(double *aNumberValue) { return _to GetNumberValue(aNumberValue); } \
  NS_SCRIPTABLE NS_IMETHOD GetStringValue(nsAString & aStringValue) { return _to GetStringValue(aStringValue); } \
  NS_SCRIPTABLE NS_IMETHOD GetBooleanValue(PRBool *aBooleanValue) { return _to GetBooleanValue(aBooleanValue); } \
  NS_SCRIPTABLE NS_IMETHOD GetSingleNodeValue(nsIDOMNode * *aSingleNodeValue) { return _to GetSingleNodeValue(aSingleNodeValue); } \
  NS_SCRIPTABLE NS_IMETHOD GetInvalidIteratorState(PRBool *aInvalidIteratorState) { return _to GetInvalidIteratorState(aInvalidIteratorState); } \
  NS_SCRIPTABLE NS_IMETHOD GetSnapshotLength(PRUint32 *aSnapshotLength) { return _to GetSnapshotLength(aSnapshotLength); } \
  NS_SCRIPTABLE NS_IMETHOD IterateNext(nsIDOMNode **_retval NS_OUTPARAM) { return _to IterateNext(_retval); } \
  NS_SCRIPTABLE NS_IMETHOD SnapshotItem(PRUint32 index, nsIDOMNode **_retval NS_OUTPARAM) { return _to SnapshotItem(index, _retval); } 

/* Use this macro to declare functions that forward the behavior of this interface to another object in a safe way. */
#define NS_FORWARD_SAFE_NSIDOMXPATHRESULT(_to) \
  NS_SCRIPTABLE NS_IMETHOD GetResultType(PRUint16 *aResultType) { return !_to ? NS_ERROR_NULL_POINTER : _to->GetResultType(aResultType); } \
  NS_SCRIPTABLE NS_IMETHOD GetNumberValue(double *aNumberValue) { return !_to ? NS_ERROR_NULL_POINTER : _to->GetNumberValue(aNumberValue); } \
  NS_SCRIPTABLE NS_IMETHOD GetStringValue(nsAString & aStringValue) { return !_to ? NS_ERROR_NULL_POINTER : _to->GetStringValue(aStringValue); } \
  NS_SCRIPTABLE NS_IMETHOD GetBooleanValue(PRBool *aBooleanValue) { return !_to ? NS_ERROR_NULL_POINTER : _to->GetBooleanValue(aBooleanValue); } \
  NS_SCRIPTABLE NS_IMETHOD GetSingleNodeValue(nsIDOMNode * *aSingleNodeValue) { return !_to ? NS_ERROR_NULL_POINTER : _to->GetSingleNodeValue(aSingleNodeValue); } \
  NS_SCRIPTABLE NS_IMETHOD GetInvalidIteratorState(PRBool *aInvalidIteratorState) { return !_to ? NS_ERROR_NULL_POINTER : _to->GetInvalidIteratorState(aInvalidIteratorState); } \
  NS_SCRIPTABLE NS_IMETHOD GetSnapshotLength(PRUint32 *aSnapshotLength) { return !_to ? NS_ERROR_NULL_POINTER : _to->GetSnapshotLength(aSnapshotLength); } \
  NS_SCRIPTABLE NS_IMETHOD IterateNext(nsIDOMNode **_retval NS_OUTPARAM) { return !_to ? NS_ERROR_NULL_POINTER : _to->IterateNext(_retval); } \
  NS_SCRIPTABLE NS_IMETHOD SnapshotItem(PRUint32 index, nsIDOMNode **_retval NS_OUTPARAM) { return !_to ? NS_ERROR_NULL_POINTER : _to->SnapshotItem(index, _retval); } 

#if 0
/* Use the code below as a template for the implementation class for this interface. */

/* Header file */
class nsDOMXPathResult : public nsIDOMXPathResult
{
public:
  NS_DECL_ISUPPORTS
  NS_DECL_NSIDOMXPATHRESULT

  nsDOMXPathResult();

private:
  ~nsDOMXPathResult();

protected:
  /* additional members */
};

/* Implementation file */
NS_IMPL_ISUPPORTS1(nsDOMXPathResult, nsIDOMXPathResult)

nsDOMXPathResult::nsDOMXPathResult()
{
  /* member initializers and constructor code */
}

nsDOMXPathResult::~nsDOMXPathResult()
{
  /* destructor code */
}

/* readonly attribute unsigned short resultType; */
NS_IMETHODIMP nsDOMXPathResult::GetResultType(PRUint16 *aResultType)
{
    return NS_ERROR_NOT_IMPLEMENTED;
}

/* readonly attribute double numberValue; */
NS_IMETHODIMP nsDOMXPathResult::GetNumberValue(double *aNumberValue)
{
    return NS_ERROR_NOT_IMPLEMENTED;
}

/* readonly attribute DOMString stringValue; */
NS_IMETHODIMP nsDOMXPathResult::GetStringValue(nsAString & aStringValue)
{
    return NS_ERROR_NOT_IMPLEMENTED;
}

/* readonly attribute boolean booleanValue; */
NS_IMETHODIMP nsDOMXPathResult::GetBooleanValue(PRBool *aBooleanValue)
{
    return NS_ERROR_NOT_IMPLEMENTED;
}

/* readonly attribute nsIDOMNode singleNodeValue; */
NS_IMETHODIMP nsDOMXPathResult::GetSingleNodeValue(nsIDOMNode * *aSingleNodeValue)
{
    return NS_ERROR_NOT_IMPLEMENTED;
}

/* readonly attribute boolean invalidIteratorState; */
NS_IMETHODIMP nsDOMXPathResult::GetInvalidIteratorState(PRBool *aInvalidIteratorState)
{
    return NS_ERROR_NOT_IMPLEMENTED;
}

/* readonly attribute unsigned long snapshotLength; */
NS_IMETHODIMP nsDOMXPathResult::GetSnapshotLength(PRUint32 *aSnapshotLength)
{
    return NS_ERROR_NOT_IMPLEMENTED;
}

/* nsIDOMNode iterateNext ()  raises (XPathException, DOMException); */
NS_IMETHODIMP nsDOMXPathResult::IterateNext(nsIDOMNode **_retval NS_OUTPARAM)
{
    return NS_ERROR_NOT_IMPLEMENTED;
}

/* nsIDOMNode snapshotItem (in unsigned long index)  raises (XPathException); */
NS_IMETHODIMP nsDOMXPathResult::SnapshotItem(PRUint32 index, nsIDOMNode **_retval NS_OUTPARAM)
{
    return NS_ERROR_NOT_IMPLEMENTED;
}

/* End of implementation class template. */
#endif


#endif /* __gen_nsIDOMXPathResult_h__ */
