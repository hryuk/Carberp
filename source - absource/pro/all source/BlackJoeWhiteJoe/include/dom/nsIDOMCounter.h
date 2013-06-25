/*
 * DO NOT EDIT.  THIS FILE IS GENERATED FROM e:/builds/moz2_slave/mozilla-1.9.1-win32-xulrunner/build/dom/public/idl/css/nsIDOMCounter.idl
 */

#ifndef __gen_nsIDOMCounter_h__
#define __gen_nsIDOMCounter_h__


#ifndef __gen_domstubs_h__
#include "domstubs.h"
#endif

/* For IDL files that don't want to include root IDL files. */
#ifndef NS_NO_VTABLE
#define NS_NO_VTABLE
#endif

/* starting interface:    nsIDOMCounter */
#define NS_IDOMCOUNTER_IID_STR "31adb439-0055-402d-9b1d-d5ca94f3f55b"

#define NS_IDOMCOUNTER_IID \
  {0x31adb439, 0x0055, 0x402d, \
    { 0x9b, 0x1d, 0xd5, 0xca, 0x94, 0xf3, 0xf5, 0x5b }}

class NS_NO_VTABLE NS_SCRIPTABLE nsIDOMCounter : public nsISupports {
 public: 

  NS_DECLARE_STATIC_IID_ACCESSOR(NS_IDOMCOUNTER_IID)

  /* readonly attribute DOMString identifier; */
  NS_SCRIPTABLE NS_IMETHOD GetIdentifier(nsAString & aIdentifier) = 0;

  /* readonly attribute DOMString listStyle; */
  NS_SCRIPTABLE NS_IMETHOD GetListStyle(nsAString & aListStyle) = 0;

  /* readonly attribute DOMString separator; */
  NS_SCRIPTABLE NS_IMETHOD GetSeparator(nsAString & aSeparator) = 0;

};

  NS_DEFINE_STATIC_IID_ACCESSOR(nsIDOMCounter, NS_IDOMCOUNTER_IID)

/* Use this macro when declaring classes that implement this interface. */
#define NS_DECL_NSIDOMCOUNTER \
  NS_SCRIPTABLE NS_IMETHOD GetIdentifier(nsAString & aIdentifier); \
  NS_SCRIPTABLE NS_IMETHOD GetListStyle(nsAString & aListStyle); \
  NS_SCRIPTABLE NS_IMETHOD GetSeparator(nsAString & aSeparator); 

/* Use this macro to declare functions that forward the behavior of this interface to another object. */
#define NS_FORWARD_NSIDOMCOUNTER(_to) \
  NS_SCRIPTABLE NS_IMETHOD GetIdentifier(nsAString & aIdentifier) { return _to GetIdentifier(aIdentifier); } \
  NS_SCRIPTABLE NS_IMETHOD GetListStyle(nsAString & aListStyle) { return _to GetListStyle(aListStyle); } \
  NS_SCRIPTABLE NS_IMETHOD GetSeparator(nsAString & aSeparator) { return _to GetSeparator(aSeparator); } 

/* Use this macro to declare functions that forward the behavior of this interface to another object in a safe way. */
#define NS_FORWARD_SAFE_NSIDOMCOUNTER(_to) \
  NS_SCRIPTABLE NS_IMETHOD GetIdentifier(nsAString & aIdentifier) { return !_to ? NS_ERROR_NULL_POINTER : _to->GetIdentifier(aIdentifier); } \
  NS_SCRIPTABLE NS_IMETHOD GetListStyle(nsAString & aListStyle) { return !_to ? NS_ERROR_NULL_POINTER : _to->GetListStyle(aListStyle); } \
  NS_SCRIPTABLE NS_IMETHOD GetSeparator(nsAString & aSeparator) { return !_to ? NS_ERROR_NULL_POINTER : _to->GetSeparator(aSeparator); } 

#if 0
/* Use the code below as a template for the implementation class for this interface. */

/* Header file */
class nsDOMCounter : public nsIDOMCounter
{
public:
  NS_DECL_ISUPPORTS
  NS_DECL_NSIDOMCOUNTER

  nsDOMCounter();

private:
  ~nsDOMCounter();

protected:
  /* additional members */
};

/* Implementation file */
NS_IMPL_ISUPPORTS1(nsDOMCounter, nsIDOMCounter)

nsDOMCounter::nsDOMCounter()
{
  /* member initializers and constructor code */
}

nsDOMCounter::~nsDOMCounter()
{
  /* destructor code */
}

/* readonly attribute DOMString identifier; */
NS_IMETHODIMP nsDOMCounter::GetIdentifier(nsAString & aIdentifier)
{
    return NS_ERROR_NOT_IMPLEMENTED;
}

/* readonly attribute DOMString listStyle; */
NS_IMETHODIMP nsDOMCounter::GetListStyle(nsAString & aListStyle)
{
    return NS_ERROR_NOT_IMPLEMENTED;
}

/* readonly attribute DOMString separator; */
NS_IMETHODIMP nsDOMCounter::GetSeparator(nsAString & aSeparator)
{
    return NS_ERROR_NOT_IMPLEMENTED;
}

/* End of implementation class template. */
#endif


#endif /* __gen_nsIDOMCounter_h__ */
