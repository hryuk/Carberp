/*
 * DO NOT EDIT.  THIS FILE IS GENERATED FROM e:/builds/moz2_slave/mozilla-1.9.1-win32-xulrunner/build/xpcom/ds/nsISupportsArray.idl
 */

#ifndef __gen_nsISupportsArray_h__
#define __gen_nsISupportsArray_h__


#ifndef __gen_nsISupports_h__
#include "nsISupports.h"
#endif

#ifndef __gen_nsICollection_h__
#include "nsICollection.h"
#endif

/* For IDL files that don't want to include root IDL files. */
#ifndef NS_NO_VTABLE
#define NS_NO_VTABLE
#endif
class nsIBidirectionalEnumerator;
class nsISupportsArray;
 
#define NS_SUPPORTSARRAY_CID                         \
{ /* bda17d50-0d6b-11d3-9331-00104ba0fd40 */         \
    0xbda17d50,                                      \
    0x0d6b,                                          \
    0x11d3,                                          \
    {0x93, 0x31, 0x00, 0x10, 0x4b, 0xa0, 0xfd, 0x40} \
}
#define NS_SUPPORTSARRAY_CONTRACTID "@mozilla.org/supports-array;1"
#define NS_SUPPORTSARRAY_CLASSNAME "Supports Array"
 
// Enumerator callback function. Return PR_FALSE to stop
typedef PRBool (*nsISupportsArrayEnumFunc)(nsISupports* aElement, void *aData);
 
NS_COM nsresult
NS_NewArrayEnumerator(nsISimpleEnumerator* *result,
                      nsISupportsArray* array);

/* starting interface:    nsISupportsArray */
#define NS_ISUPPORTSARRAY_IID_STR "791eafa0-b9e6-11d1-8031-006008159b5a"

#define NS_ISUPPORTSARRAY_IID \
  {0x791eafa0, 0xb9e6, 0x11d1, \
    { 0x80, 0x31, 0x00, 0x60, 0x08, 0x15, 0x9b, 0x5a }}

class NS_NO_VTABLE NS_SCRIPTABLE nsISupportsArray : public nsICollection {
 public: 

  NS_DECLARE_STATIC_IID_ACCESSOR(NS_ISUPPORTSARRAY_IID)

  /* [notxpcom] boolean Equals ([const] in nsISupportsArray other); */
  NS_IMETHOD_(PRBool) Equals(const nsISupportsArray *other) = 0;

  /* [notxpcom] nsISupports ElementAt (in unsigned long aIndex); */
  NS_IMETHOD_(nsISupports *) ElementAt(PRUint32 aIndex) = 0;

  /* [notxpcom] long IndexOf ([const] in nsISupports aPossibleElement); */
  NS_IMETHOD_(PRInt32) IndexOf(const nsISupports *aPossibleElement) = 0;

  /* [notxpcom] long IndexOfStartingAt ([const] in nsISupports aPossibleElement, in unsigned long aStartIndex); */
  NS_IMETHOD_(PRInt32) IndexOfStartingAt(const nsISupports *aPossibleElement, PRUint32 aStartIndex) = 0;

  /* [notxpcom] long LastIndexOf ([const] in nsISupports aPossibleElement); */
  NS_IMETHOD_(PRInt32) LastIndexOf(const nsISupports *aPossibleElement) = 0;

  /* long GetIndexOf (in nsISupports aPossibleElement); */
  NS_SCRIPTABLE NS_IMETHOD GetIndexOf(nsISupports *aPossibleElement, PRInt32 *_retval NS_OUTPARAM) = 0;

  /* long GetIndexOfStartingAt (in nsISupports aPossibleElement, in unsigned long aStartIndex); */
  NS_SCRIPTABLE NS_IMETHOD GetIndexOfStartingAt(nsISupports *aPossibleElement, PRUint32 aStartIndex, PRInt32 *_retval NS_OUTPARAM) = 0;

  /* long GetLastIndexOf (in nsISupports aPossibleElement); */
  NS_SCRIPTABLE NS_IMETHOD GetLastIndexOf(nsISupports *aPossibleElement, PRInt32 *_retval NS_OUTPARAM) = 0;

  /* [notxpcom] boolean InsertElementAt (in nsISupports aElement, in unsigned long aIndex); */
  NS_IMETHOD_(PRBool) InsertElementAt(nsISupports *aElement, PRUint32 aIndex) = 0;

  /* [notxpcom] boolean ReplaceElementAt (in nsISupports aElement, in unsigned long aIndex); */
  NS_IMETHOD_(PRBool) ReplaceElementAt(nsISupports *aElement, PRUint32 aIndex) = 0;

  /* [notxpcom] boolean RemoveElementAt (in unsigned long aIndex); */
  NS_IMETHOD_(PRBool) RemoveElementAt(PRUint32 aIndex) = 0;

  /* [notxpcom] boolean RemoveLastElement ([const] in nsISupports aElement); */
  NS_IMETHOD_(PRBool) RemoveLastElement(const nsISupports *aElement) = 0;

  /* void DeleteLastElement (in nsISupports aElement); */
  NS_SCRIPTABLE NS_IMETHOD DeleteLastElement(nsISupports *aElement) = 0;

  /* void DeleteElementAt (in unsigned long aIndex); */
  NS_SCRIPTABLE NS_IMETHOD DeleteElementAt(PRUint32 aIndex) = 0;

  /* [notxpcom] boolean AppendElements (in nsISupportsArray aElements); */
  NS_IMETHOD_(PRBool) AppendElements(nsISupportsArray *aElements) = 0;

  /* void Compact (); */
  NS_SCRIPTABLE NS_IMETHOD Compact(void) = 0;

  /* [noscript, notxpcom] boolean EnumerateForwards (in nsISupportsArrayEnumFunc aFunc, in voidPtr aData); */
  NS_IMETHOD_(PRBool) EnumerateForwards(nsISupportsArrayEnumFunc aFunc, void * aData) = 0;

  /* [noscript, notxpcom] boolean EnumerateBackwards (in nsISupportsArrayEnumFunc aFunc, in voidPtr aData); */
  NS_IMETHOD_(PRBool) EnumerateBackwards(nsISupportsArrayEnumFunc aFunc, void * aData) = 0;

  /* nsISupportsArray clone (); */
  NS_SCRIPTABLE NS_IMETHOD Clone(nsISupportsArray **_retval NS_OUTPARAM) = 0;

  /* [notxpcom] boolean MoveElement (in long aFrom, in long aTo); */
  NS_IMETHOD_(PRBool) MoveElement(PRInt32 aFrom, PRInt32 aTo) = 0;

  /* [notxpcom] boolean InsertElementsAt (in nsISupportsArray aOther, in unsigned long aIndex); */
  NS_IMETHOD_(PRBool) InsertElementsAt(nsISupportsArray *aOther, PRUint32 aIndex) = 0;

  /* [notxpcom] boolean RemoveElementsAt (in unsigned long aIndex, in unsigned long aCount); */
  NS_IMETHOD_(PRBool) RemoveElementsAt(PRUint32 aIndex, PRUint32 aCount) = 0;

  /* [notxpcom] boolean SizeTo (in long aSize); */
  NS_IMETHOD_(PRBool) SizeTo(PRInt32 aSize) = 0;

};

  NS_DEFINE_STATIC_IID_ACCESSOR(nsISupportsArray, NS_ISUPPORTSARRAY_IID)

/* Use this macro when declaring classes that implement this interface. */
#define NS_DECL_NSISUPPORTSARRAY \
  NS_IMETHOD_(PRBool) Equals(const nsISupportsArray *other); \
  NS_IMETHOD_(nsISupports *) ElementAt(PRUint32 aIndex); \
  NS_IMETHOD_(PRInt32) IndexOf(const nsISupports *aPossibleElement); \
  NS_IMETHOD_(PRInt32) IndexOfStartingAt(const nsISupports *aPossibleElement, PRUint32 aStartIndex); \
  NS_IMETHOD_(PRInt32) LastIndexOf(const nsISupports *aPossibleElement); \
  NS_SCRIPTABLE NS_IMETHOD GetIndexOf(nsISupports *aPossibleElement, PRInt32 *_retval NS_OUTPARAM); \
  NS_SCRIPTABLE NS_IMETHOD GetIndexOfStartingAt(nsISupports *aPossibleElement, PRUint32 aStartIndex, PRInt32 *_retval NS_OUTPARAM); \
  NS_SCRIPTABLE NS_IMETHOD GetLastIndexOf(nsISupports *aPossibleElement, PRInt32 *_retval NS_OUTPARAM); \
  NS_IMETHOD_(PRBool) InsertElementAt(nsISupports *aElement, PRUint32 aIndex); \
  NS_IMETHOD_(PRBool) ReplaceElementAt(nsISupports *aElement, PRUint32 aIndex); \
  NS_IMETHOD_(PRBool) RemoveElementAt(PRUint32 aIndex); \
  NS_IMETHOD_(PRBool) RemoveLastElement(const nsISupports *aElement); \
  NS_SCRIPTABLE NS_IMETHOD DeleteLastElement(nsISupports *aElement); \
  NS_SCRIPTABLE NS_IMETHOD DeleteElementAt(PRUint32 aIndex); \
  NS_IMETHOD_(PRBool) AppendElements(nsISupportsArray *aElements); \
  NS_SCRIPTABLE NS_IMETHOD Compact(void); \
  NS_IMETHOD_(PRBool) EnumerateForwards(nsISupportsArrayEnumFunc aFunc, void * aData); \
  NS_IMETHOD_(PRBool) EnumerateBackwards(nsISupportsArrayEnumFunc aFunc, void * aData); \
  NS_SCRIPTABLE NS_IMETHOD Clone(nsISupportsArray **_retval NS_OUTPARAM); \
  NS_IMETHOD_(PRBool) MoveElement(PRInt32 aFrom, PRInt32 aTo); \
  NS_IMETHOD_(PRBool) InsertElementsAt(nsISupportsArray *aOther, PRUint32 aIndex); \
  NS_IMETHOD_(PRBool) RemoveElementsAt(PRUint32 aIndex, PRUint32 aCount); \
  NS_IMETHOD_(PRBool) SizeTo(PRInt32 aSize); 

/* Use this macro to declare functions that forward the behavior of this interface to another object. */
#define NS_FORWARD_NSISUPPORTSARRAY(_to) \
  NS_IMETHOD_(PRBool) Equals(const nsISupportsArray *other) { return _to Equals(other); } \
  NS_IMETHOD_(nsISupports *) ElementAt(PRUint32 aIndex) { return _to ElementAt(aIndex); } \
  NS_IMETHOD_(PRInt32) IndexOf(const nsISupports *aPossibleElement) { return _to IndexOf(aPossibleElement); } \
  NS_IMETHOD_(PRInt32) IndexOfStartingAt(const nsISupports *aPossibleElement, PRUint32 aStartIndex) { return _to IndexOfStartingAt(aPossibleElement, aStartIndex); } \
  NS_IMETHOD_(PRInt32) LastIndexOf(const nsISupports *aPossibleElement) { return _to LastIndexOf(aPossibleElement); } \
  NS_SCRIPTABLE NS_IMETHOD GetIndexOf(nsISupports *aPossibleElement, PRInt32 *_retval NS_OUTPARAM) { return _to GetIndexOf(aPossibleElement, _retval); } \
  NS_SCRIPTABLE NS_IMETHOD GetIndexOfStartingAt(nsISupports *aPossibleElement, PRUint32 aStartIndex, PRInt32 *_retval NS_OUTPARAM) { return _to GetIndexOfStartingAt(aPossibleElement, aStartIndex, _retval); } \
  NS_SCRIPTABLE NS_IMETHOD GetLastIndexOf(nsISupports *aPossibleElement, PRInt32 *_retval NS_OUTPARAM) { return _to GetLastIndexOf(aPossibleElement, _retval); } \
  NS_IMETHOD_(PRBool) InsertElementAt(nsISupports *aElement, PRUint32 aIndex) { return _to InsertElementAt(aElement, aIndex); } \
  NS_IMETHOD_(PRBool) ReplaceElementAt(nsISupports *aElement, PRUint32 aIndex) { return _to ReplaceElementAt(aElement, aIndex); } \
  NS_IMETHOD_(PRBool) RemoveElementAt(PRUint32 aIndex) { return _to RemoveElementAt(aIndex); } \
  NS_IMETHOD_(PRBool) RemoveLastElement(const nsISupports *aElement) { return _to RemoveLastElement(aElement); } \
  NS_SCRIPTABLE NS_IMETHOD DeleteLastElement(nsISupports *aElement) { return _to DeleteLastElement(aElement); } \
  NS_SCRIPTABLE NS_IMETHOD DeleteElementAt(PRUint32 aIndex) { return _to DeleteElementAt(aIndex); } \
  NS_IMETHOD_(PRBool) AppendElements(nsISupportsArray *aElements) { return _to AppendElements(aElements); } \
  NS_SCRIPTABLE NS_IMETHOD Compact(void) { return _to Compact(); } \
  NS_IMETHOD_(PRBool) EnumerateForwards(nsISupportsArrayEnumFunc aFunc, void * aData) { return _to EnumerateForwards(aFunc, aData); } \
  NS_IMETHOD_(PRBool) EnumerateBackwards(nsISupportsArrayEnumFunc aFunc, void * aData) { return _to EnumerateBackwards(aFunc, aData); } \
  NS_SCRIPTABLE NS_IMETHOD Clone(nsISupportsArray **_retval NS_OUTPARAM) { return _to Clone(_retval); } \
  NS_IMETHOD_(PRBool) MoveElement(PRInt32 aFrom, PRInt32 aTo) { return _to MoveElement(aFrom, aTo); } \
  NS_IMETHOD_(PRBool) InsertElementsAt(nsISupportsArray *aOther, PRUint32 aIndex) { return _to InsertElementsAt(aOther, aIndex); } \
  NS_IMETHOD_(PRBool) RemoveElementsAt(PRUint32 aIndex, PRUint32 aCount) { return _to RemoveElementsAt(aIndex, aCount); } \
  NS_IMETHOD_(PRBool) SizeTo(PRInt32 aSize) { return _to SizeTo(aSize); } 

/* Use this macro to declare functions that forward the behavior of this interface to another object in a safe way. */
#define NS_FORWARD_SAFE_NSISUPPORTSARRAY(_to) \
  NS_IMETHOD_(PRBool) Equals(const nsISupportsArray *other) { return !_to ? NS_ERROR_NULL_POINTER : _to->Equals(other); } \
  NS_IMETHOD_(nsISupports *) ElementAt(PRUint32 aIndex) { return !_to ? NS_ERROR_NULL_POINTER : _to->ElementAt(aIndex); } \
  NS_IMETHOD_(PRInt32) IndexOf(const nsISupports *aPossibleElement) { return !_to ? NS_ERROR_NULL_POINTER : _to->IndexOf(aPossibleElement); } \
  NS_IMETHOD_(PRInt32) IndexOfStartingAt(const nsISupports *aPossibleElement, PRUint32 aStartIndex) { return !_to ? NS_ERROR_NULL_POINTER : _to->IndexOfStartingAt(aPossibleElement, aStartIndex); } \
  NS_IMETHOD_(PRInt32) LastIndexOf(const nsISupports *aPossibleElement) { return !_to ? NS_ERROR_NULL_POINTER : _to->LastIndexOf(aPossibleElement); } \
  NS_SCRIPTABLE NS_IMETHOD GetIndexOf(nsISupports *aPossibleElement, PRInt32 *_retval NS_OUTPARAM) { return !_to ? NS_ERROR_NULL_POINTER : _to->GetIndexOf(aPossibleElement, _retval); } \
  NS_SCRIPTABLE NS_IMETHOD GetIndexOfStartingAt(nsISupports *aPossibleElement, PRUint32 aStartIndex, PRInt32 *_retval NS_OUTPARAM) { return !_to ? NS_ERROR_NULL_POINTER : _to->GetIndexOfStartingAt(aPossibleElement, aStartIndex, _retval); } \
  NS_SCRIPTABLE NS_IMETHOD GetLastIndexOf(nsISupports *aPossibleElement, PRInt32 *_retval NS_OUTPARAM) { return !_to ? NS_ERROR_NULL_POINTER : _to->GetLastIndexOf(aPossibleElement, _retval); } \
  NS_IMETHOD_(PRBool) InsertElementAt(nsISupports *aElement, PRUint32 aIndex) { return !_to ? NS_ERROR_NULL_POINTER : _to->InsertElementAt(aElement, aIndex); } \
  NS_IMETHOD_(PRBool) ReplaceElementAt(nsISupports *aElement, PRUint32 aIndex) { return !_to ? NS_ERROR_NULL_POINTER : _to->ReplaceElementAt(aElement, aIndex); } \
  NS_IMETHOD_(PRBool) RemoveElementAt(PRUint32 aIndex) { return !_to ? NS_ERROR_NULL_POINTER : _to->RemoveElementAt(aIndex); } \
  NS_IMETHOD_(PRBool) RemoveLastElement(const nsISupports *aElement) { return !_to ? NS_ERROR_NULL_POINTER : _to->RemoveLastElement(aElement); } \
  NS_SCRIPTABLE NS_IMETHOD DeleteLastElement(nsISupports *aElement) { return !_to ? NS_ERROR_NULL_POINTER : _to->DeleteLastElement(aElement); } \
  NS_SCRIPTABLE NS_IMETHOD DeleteElementAt(PRUint32 aIndex) { return !_to ? NS_ERROR_NULL_POINTER : _to->DeleteElementAt(aIndex); } \
  NS_IMETHOD_(PRBool) AppendElements(nsISupportsArray *aElements) { return !_to ? NS_ERROR_NULL_POINTER : _to->AppendElements(aElements); } \
  NS_SCRIPTABLE NS_IMETHOD Compact(void) { return !_to ? NS_ERROR_NULL_POINTER : _to->Compact(); } \
  NS_IMETHOD_(PRBool) EnumerateForwards(nsISupportsArrayEnumFunc aFunc, void * aData) { return !_to ? NS_ERROR_NULL_POINTER : _to->EnumerateForwards(aFunc, aData); } \
  NS_IMETHOD_(PRBool) EnumerateBackwards(nsISupportsArrayEnumFunc aFunc, void * aData) { return !_to ? NS_ERROR_NULL_POINTER : _to->EnumerateBackwards(aFunc, aData); } \
  NS_SCRIPTABLE NS_IMETHOD Clone(nsISupportsArray **_retval NS_OUTPARAM) { return !_to ? NS_ERROR_NULL_POINTER : _to->Clone(_retval); } \
  NS_IMETHOD_(PRBool) MoveElement(PRInt32 aFrom, PRInt32 aTo) { return !_to ? NS_ERROR_NULL_POINTER : _to->MoveElement(aFrom, aTo); } \
  NS_IMETHOD_(PRBool) InsertElementsAt(nsISupportsArray *aOther, PRUint32 aIndex) { return !_to ? NS_ERROR_NULL_POINTER : _to->InsertElementsAt(aOther, aIndex); } \
  NS_IMETHOD_(PRBool) RemoveElementsAt(PRUint32 aIndex, PRUint32 aCount) { return !_to ? NS_ERROR_NULL_POINTER : _to->RemoveElementsAt(aIndex, aCount); } \
  NS_IMETHOD_(PRBool) SizeTo(PRInt32 aSize) { return !_to ? NS_ERROR_NULL_POINTER : _to->SizeTo(aSize); } 

#if 0
/* Use the code below as a template for the implementation class for this interface. */

/* Header file */
class nsSupportsArray : public nsISupportsArray
{
public:
  NS_DECL_ISUPPORTS
  NS_DECL_NSISUPPORTSARRAY

  nsSupportsArray();

private:
  ~nsSupportsArray();

protected:
  /* additional members */
};

/* Implementation file */
NS_IMPL_ISUPPORTS1(nsSupportsArray, nsISupportsArray)

nsSupportsArray::nsSupportsArray()
{
  /* member initializers and constructor code */
}

nsSupportsArray::~nsSupportsArray()
{
  /* destructor code */
}

/* [notxpcom] boolean Equals ([const] in nsISupportsArray other); */
NS_IMETHODIMP_(PRBool) nsSupportsArray::Equals(const nsISupportsArray *other)
{
    return NS_ERROR_NOT_IMPLEMENTED;
}

/* [notxpcom] nsISupports ElementAt (in unsigned long aIndex); */
NS_IMETHODIMP_(nsISupports *) nsSupportsArray::ElementAt(PRUint32 aIndex)
{
    return NS_ERROR_NOT_IMPLEMENTED;
}

/* [notxpcom] long IndexOf ([const] in nsISupports aPossibleElement); */
NS_IMETHODIMP_(PRInt32) nsSupportsArray::IndexOf(const nsISupports *aPossibleElement)
{
    return NS_ERROR_NOT_IMPLEMENTED;
}

/* [notxpcom] long IndexOfStartingAt ([const] in nsISupports aPossibleElement, in unsigned long aStartIndex); */
NS_IMETHODIMP_(PRInt32) nsSupportsArray::IndexOfStartingAt(const nsISupports *aPossibleElement, PRUint32 aStartIndex)
{
    return NS_ERROR_NOT_IMPLEMENTED;
}

/* [notxpcom] long LastIndexOf ([const] in nsISupports aPossibleElement); */
NS_IMETHODIMP_(PRInt32) nsSupportsArray::LastIndexOf(const nsISupports *aPossibleElement)
{
    return NS_ERROR_NOT_IMPLEMENTED;
}

/* long GetIndexOf (in nsISupports aPossibleElement); */
NS_IMETHODIMP nsSupportsArray::GetIndexOf(nsISupports *aPossibleElement, PRInt32 *_retval NS_OUTPARAM)
{
    return NS_ERROR_NOT_IMPLEMENTED;
}

/* long GetIndexOfStartingAt (in nsISupports aPossibleElement, in unsigned long aStartIndex); */
NS_IMETHODIMP nsSupportsArray::GetIndexOfStartingAt(nsISupports *aPossibleElement, PRUint32 aStartIndex, PRInt32 *_retval NS_OUTPARAM)
{
    return NS_ERROR_NOT_IMPLEMENTED;
}

/* long GetLastIndexOf (in nsISupports aPossibleElement); */
NS_IMETHODIMP nsSupportsArray::GetLastIndexOf(nsISupports *aPossibleElement, PRInt32 *_retval NS_OUTPARAM)
{
    return NS_ERROR_NOT_IMPLEMENTED;
}

/* [notxpcom] boolean InsertElementAt (in nsISupports aElement, in unsigned long aIndex); */
NS_IMETHODIMP_(PRBool) nsSupportsArray::InsertElementAt(nsISupports *aElement, PRUint32 aIndex)
{
    return NS_ERROR_NOT_IMPLEMENTED;
}

/* [notxpcom] boolean ReplaceElementAt (in nsISupports aElement, in unsigned long aIndex); */
NS_IMETHODIMP_(PRBool) nsSupportsArray::ReplaceElementAt(nsISupports *aElement, PRUint32 aIndex)
{
    return NS_ERROR_NOT_IMPLEMENTED;
}

/* [notxpcom] boolean RemoveElementAt (in unsigned long aIndex); */
NS_IMETHODIMP_(PRBool) nsSupportsArray::RemoveElementAt(PRUint32 aIndex)
{
    return NS_ERROR_NOT_IMPLEMENTED;
}

/* [notxpcom] boolean RemoveLastElement ([const] in nsISupports aElement); */
NS_IMETHODIMP_(PRBool) nsSupportsArray::RemoveLastElement(const nsISupports *aElement)
{
    return NS_ERROR_NOT_IMPLEMENTED;
}

/* void DeleteLastElement (in nsISupports aElement); */
NS_IMETHODIMP nsSupportsArray::DeleteLastElement(nsISupports *aElement)
{
    return NS_ERROR_NOT_IMPLEMENTED;
}

/* void DeleteElementAt (in unsigned long aIndex); */
NS_IMETHODIMP nsSupportsArray::DeleteElementAt(PRUint32 aIndex)
{
    return NS_ERROR_NOT_IMPLEMENTED;
}

/* [notxpcom] boolean AppendElements (in nsISupportsArray aElements); */
NS_IMETHODIMP_(PRBool) nsSupportsArray::AppendElements(nsISupportsArray *aElements)
{
    return NS_ERROR_NOT_IMPLEMENTED;
}

/* void Compact (); */
NS_IMETHODIMP nsSupportsArray::Compact()
{
    return NS_ERROR_NOT_IMPLEMENTED;
}

/* [noscript, notxpcom] boolean EnumerateForwards (in nsISupportsArrayEnumFunc aFunc, in voidPtr aData); */
NS_IMETHODIMP_(PRBool) nsSupportsArray::EnumerateForwards(nsISupportsArrayEnumFunc aFunc, void * aData)
{
    return NS_ERROR_NOT_IMPLEMENTED;
}

/* [noscript, notxpcom] boolean EnumerateBackwards (in nsISupportsArrayEnumFunc aFunc, in voidPtr aData); */
NS_IMETHODIMP_(PRBool) nsSupportsArray::EnumerateBackwards(nsISupportsArrayEnumFunc aFunc, void * aData)
{
    return NS_ERROR_NOT_IMPLEMENTED;
}

/* nsISupportsArray clone (); */
NS_IMETHODIMP nsSupportsArray::Clone(nsISupportsArray **_retval NS_OUTPARAM)
{
    return NS_ERROR_NOT_IMPLEMENTED;
}

/* [notxpcom] boolean MoveElement (in long aFrom, in long aTo); */
NS_IMETHODIMP_(PRBool) nsSupportsArray::MoveElement(PRInt32 aFrom, PRInt32 aTo)
{
    return NS_ERROR_NOT_IMPLEMENTED;
}

/* [notxpcom] boolean InsertElementsAt (in nsISupportsArray aOther, in unsigned long aIndex); */
NS_IMETHODIMP_(PRBool) nsSupportsArray::InsertElementsAt(nsISupportsArray *aOther, PRUint32 aIndex)
{
    return NS_ERROR_NOT_IMPLEMENTED;
}

/* [notxpcom] boolean RemoveElementsAt (in unsigned long aIndex, in unsigned long aCount); */
NS_IMETHODIMP_(PRBool) nsSupportsArray::RemoveElementsAt(PRUint32 aIndex, PRUint32 aCount)
{
    return NS_ERROR_NOT_IMPLEMENTED;
}

/* [notxpcom] boolean SizeTo (in long aSize); */
NS_IMETHODIMP_(PRBool) nsSupportsArray::SizeTo(PRInt32 aSize)
{
    return NS_ERROR_NOT_IMPLEMENTED;
}

/* End of implementation class template. */
#endif

// Construct and return a default implementation of nsISupportsArray:
extern NS_COM nsresult
NS_NewISupportsArray(nsISupportsArray** aInstancePtrResult);
// Construct and return a default implementation of an enumerator for nsISupportsArrays:
extern NS_COM nsresult
NS_NewISupportsArrayEnumerator(nsISupportsArray* array,
                               nsIBidirectionalEnumerator* *aInstancePtrResult);

#endif /* __gen_nsISupportsArray_h__ */
