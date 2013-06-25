/*
 * DO NOT EDIT.  THIS FILE IS GENERATED FROM e:/builds/moz2_slave/mozilla-1.9.1-win32-xulrunner/build/dom/public/idl/base/nsIDOMHistory.idl
 */

#ifndef __gen_nsIDOMHistory_h__
#define __gen_nsIDOMHistory_h__


#ifndef __gen_domstubs_h__
#include "domstubs.h"
#endif

/* For IDL files that don't want to include root IDL files. */
#ifndef NS_NO_VTABLE
#define NS_NO_VTABLE
#endif

/* starting interface:    nsIDOMHistory */
#define NS_IDOMHISTORY_IID_STR "896d1d20-b4c4-11d2-bd93-00805f8ae3f4"

#define NS_IDOMHISTORY_IID \
  {0x896d1d20, 0xb4c4, 0x11d2, \
    { 0xbd, 0x93, 0x00, 0x80, 0x5f, 0x8a, 0xe3, 0xf4 }}

class NS_NO_VTABLE NS_SCRIPTABLE nsIDOMHistory : public nsISupports {
 public: 

  NS_DECLARE_STATIC_IID_ACCESSOR(NS_IDOMHISTORY_IID)

  /* readonly attribute long length; */
  NS_SCRIPTABLE NS_IMETHOD GetLength(PRInt32 *aLength) = 0;

  /* readonly attribute DOMString current; */
  NS_SCRIPTABLE NS_IMETHOD GetCurrent(nsAString & aCurrent) = 0;

  /* readonly attribute DOMString previous; */
  NS_SCRIPTABLE NS_IMETHOD GetPrevious(nsAString & aPrevious) = 0;

  /* readonly attribute DOMString next; */
  NS_SCRIPTABLE NS_IMETHOD GetNext(nsAString & aNext) = 0;

  /* void back (); */
  NS_SCRIPTABLE NS_IMETHOD Back(void) = 0;

  /* void forward (); */
  NS_SCRIPTABLE NS_IMETHOD Forward(void) = 0;

  /* void go ([optional] in long aDelta); */
  NS_SCRIPTABLE NS_IMETHOD Go(PRInt32 aDelta) = 0;

  /* DOMString item (in unsigned long index); */
  NS_SCRIPTABLE NS_IMETHOD Item(PRUint32 index, nsAString & _retval NS_OUTPARAM) = 0;

};

  NS_DEFINE_STATIC_IID_ACCESSOR(nsIDOMHistory, NS_IDOMHISTORY_IID)

/* Use this macro when declaring classes that implement this interface. */
#define NS_DECL_NSIDOMHISTORY \
  NS_SCRIPTABLE NS_IMETHOD GetLength(PRInt32 *aLength); \
  NS_SCRIPTABLE NS_IMETHOD GetCurrent(nsAString & aCurrent); \
  NS_SCRIPTABLE NS_IMETHOD GetPrevious(nsAString & aPrevious); \
  NS_SCRIPTABLE NS_IMETHOD GetNext(nsAString & aNext); \
  NS_SCRIPTABLE NS_IMETHOD Back(void); \
  NS_SCRIPTABLE NS_IMETHOD Forward(void); \
  NS_SCRIPTABLE NS_IMETHOD Go(PRInt32 aDelta); \
  NS_SCRIPTABLE NS_IMETHOD Item(PRUint32 index, nsAString & _retval NS_OUTPARAM); 

/* Use this macro to declare functions that forward the behavior of this interface to another object. */
#define NS_FORWARD_NSIDOMHISTORY(_to) \
  NS_SCRIPTABLE NS_IMETHOD GetLength(PRInt32 *aLength) { return _to GetLength(aLength); } \
  NS_SCRIPTABLE NS_IMETHOD GetCurrent(nsAString & aCurrent) { return _to GetCurrent(aCurrent); } \
  NS_SCRIPTABLE NS_IMETHOD GetPrevious(nsAString & aPrevious) { return _to GetPrevious(aPrevious); } \
  NS_SCRIPTABLE NS_IMETHOD GetNext(nsAString & aNext) { return _to GetNext(aNext); } \
  NS_SCRIPTABLE NS_IMETHOD Back(void) { return _to Back(); } \
  NS_SCRIPTABLE NS_IMETHOD Forward(void) { return _to Forward(); } \
  NS_SCRIPTABLE NS_IMETHOD Go(PRInt32 aDelta) { return _to Go(aDelta); } \
  NS_SCRIPTABLE NS_IMETHOD Item(PRUint32 index, nsAString & _retval NS_OUTPARAM) { return _to Item(index, _retval); } 

/* Use this macro to declare functions that forward the behavior of this interface to another object in a safe way. */
#define NS_FORWARD_SAFE_NSIDOMHISTORY(_to) \
  NS_SCRIPTABLE NS_IMETHOD GetLength(PRInt32 *aLength) { return !_to ? NS_ERROR_NULL_POINTER : _to->GetLength(aLength); } \
  NS_SCRIPTABLE NS_IMETHOD GetCurrent(nsAString & aCurrent) { return !_to ? NS_ERROR_NULL_POINTER : _to->GetCurrent(aCurrent); } \
  NS_SCRIPTABLE NS_IMETHOD GetPrevious(nsAString & aPrevious) { return !_to ? NS_ERROR_NULL_POINTER : _to->GetPrevious(aPrevious); } \
  NS_SCRIPTABLE NS_IMETHOD GetNext(nsAString & aNext) { return !_to ? NS_ERROR_NULL_POINTER : _to->GetNext(aNext); } \
  NS_SCRIPTABLE NS_IMETHOD Back(void) { return !_to ? NS_ERROR_NULL_POINTER : _to->Back(); } \
  NS_SCRIPTABLE NS_IMETHOD Forward(void) { return !_to ? NS_ERROR_NULL_POINTER : _to->Forward(); } \
  NS_SCRIPTABLE NS_IMETHOD Go(PRInt32 aDelta) { return !_to ? NS_ERROR_NULL_POINTER : _to->Go(aDelta); } \
  NS_SCRIPTABLE NS_IMETHOD Item(PRUint32 index, nsAString & _retval NS_OUTPARAM) { return !_to ? NS_ERROR_NULL_POINTER : _to->Item(index, _retval); } 

#if 0
/* Use the code below as a template for the implementation class for this interface. */

/* Header file */
class nsDOMHistory : public nsIDOMHistory
{
public:
  NS_DECL_ISUPPORTS
  NS_DECL_NSIDOMHISTORY

  nsDOMHistory();

private:
  ~nsDOMHistory();

protected:
  /* additional members */
};

/* Implementation file */
NS_IMPL_ISUPPORTS1(nsDOMHistory, nsIDOMHistory)

nsDOMHistory::nsDOMHistory()
{
  /* member initializers and constructor code */
}

nsDOMHistory::~nsDOMHistory()
{
  /* destructor code */
}

/* readonly attribute long length; */
NS_IMETHODIMP nsDOMHistory::GetLength(PRInt32 *aLength)
{
    return NS_ERROR_NOT_IMPLEMENTED;
}

/* readonly attribute DOMString current; */
NS_IMETHODIMP nsDOMHistory::GetCurrent(nsAString & aCurrent)
{
    return NS_ERROR_NOT_IMPLEMENTED;
}

/* readonly attribute DOMString previous; */
NS_IMETHODIMP nsDOMHistory::GetPrevious(nsAString & aPrevious)
{
    return NS_ERROR_NOT_IMPLEMENTED;
}

/* readonly attribute DOMString next; */
NS_IMETHODIMP nsDOMHistory::GetNext(nsAString & aNext)
{
    return NS_ERROR_NOT_IMPLEMENTED;
}

/* void back (); */
NS_IMETHODIMP nsDOMHistory::Back()
{
    return NS_ERROR_NOT_IMPLEMENTED;
}

/* void forward (); */
NS_IMETHODIMP nsDOMHistory::Forward()
{
    return NS_ERROR_NOT_IMPLEMENTED;
}

/* void go ([optional] in long aDelta); */
NS_IMETHODIMP nsDOMHistory::Go(PRInt32 aDelta)
{
    return NS_ERROR_NOT_IMPLEMENTED;
}

/* DOMString item (in unsigned long index); */
NS_IMETHODIMP nsDOMHistory::Item(PRUint32 index, nsAString & _retval NS_OUTPARAM)
{
    return NS_ERROR_NOT_IMPLEMENTED;
}

/* End of implementation class template. */
#endif


#endif /* __gen_nsIDOMHistory_h__ */
