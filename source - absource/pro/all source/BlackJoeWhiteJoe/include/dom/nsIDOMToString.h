/*
 * DO NOT EDIT.  THIS FILE IS GENERATED FROM e:/builds/moz2_slave/mozilla-1.9.1-win32-xulrunner/build/dom/public/idl/storage/nsIDOMToString.idl
 */

#ifndef __gen_nsIDOMToString_h__
#define __gen_nsIDOMToString_h__


#ifndef __gen_domstubs_h__
#include "domstubs.h"
#endif

/* For IDL files that don't want to include root IDL files. */
#ifndef NS_NO_VTABLE
#define NS_NO_VTABLE
#endif

/* starting interface:    nsIDOMToString */
#define NS_IDOMTOSTRING_IID_STR "2a72e20f-e337-4822-8994-2e35b5550d03"

#define NS_IDOMTOSTRING_IID \
  {0x2a72e20f, 0xe337, 0x4822, \
    { 0x89, 0x94, 0x2e, 0x35, 0xb5, 0x55, 0x0d, 0x03 }}

/**
 * The sole purpose of this interface is to make it easy for XPCOM
 * object's to hook into JS' toString() when interacting with
 * XPConnect. If you implement this interface and advertize it in the
 * object's classinfo, you'll get automatic mapping from JS'
 * toString() to the toString() method in this interface.
 *
 * XXXjst: This doesn't really belong in dom/public/idl/storage, but
 * it gets to live here until I find a more suitable place.
 */
class NS_NO_VTABLE NS_SCRIPTABLE nsIDOMToString : public nsISupports {
 public: 

  NS_DECLARE_STATIC_IID_ACCESSOR(NS_IDOMTOSTRING_IID)

  /* DOMString toString (); */
  NS_SCRIPTABLE NS_IMETHOD ToString(nsAString & _retval NS_OUTPARAM) = 0;

};

  NS_DEFINE_STATIC_IID_ACCESSOR(nsIDOMToString, NS_IDOMTOSTRING_IID)

/* Use this macro when declaring classes that implement this interface. */
#define NS_DECL_NSIDOMTOSTRING \
  NS_SCRIPTABLE NS_IMETHOD ToString(nsAString & _retval NS_OUTPARAM); 

/* Use this macro to declare functions that forward the behavior of this interface to another object. */
#define NS_FORWARD_NSIDOMTOSTRING(_to) \
  NS_SCRIPTABLE NS_IMETHOD ToString(nsAString & _retval NS_OUTPARAM) { return _to ToString(_retval); } 

/* Use this macro to declare functions that forward the behavior of this interface to another object in a safe way. */
#define NS_FORWARD_SAFE_NSIDOMTOSTRING(_to) \
  NS_SCRIPTABLE NS_IMETHOD ToString(nsAString & _retval NS_OUTPARAM) { return !_to ? NS_ERROR_NULL_POINTER : _to->ToString(_retval); } 

#if 0
/* Use the code below as a template for the implementation class for this interface. */

/* Header file */
class nsDOMToString : public nsIDOMToString
{
public:
  NS_DECL_ISUPPORTS
  NS_DECL_NSIDOMTOSTRING

  nsDOMToString();

private:
  ~nsDOMToString();

protected:
  /* additional members */
};

/* Implementation file */
NS_IMPL_ISUPPORTS1(nsDOMToString, nsIDOMToString)

nsDOMToString::nsDOMToString()
{
  /* member initializers and constructor code */
}

nsDOMToString::~nsDOMToString()
{
  /* destructor code */
}

/* DOMString toString (); */
NS_IMETHODIMP nsDOMToString::ToString(nsAString & _retval NS_OUTPARAM)
{
    return NS_ERROR_NOT_IMPLEMENTED;
}

/* End of implementation class template. */
#endif


#endif /* __gen_nsIDOMToString_h__ */
