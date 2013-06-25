/*
 * DO NOT EDIT.  THIS FILE IS GENERATED FROM e:/builds/moz2_slave/mozilla-1.9.1-win32-xulrunner/build/dom/public/idl/base/nsIDOMConstructor.idl
 */

#ifndef __gen_nsIDOMConstructor_h__
#define __gen_nsIDOMConstructor_h__


#ifndef __gen_domstubs_h__
#include "domstubs.h"
#endif

/* For IDL files that don't want to include root IDL files. */
#ifndef NS_NO_VTABLE
#define NS_NO_VTABLE
#endif

/* starting interface:    nsIDOMDOMConstructor */
#define NS_IDOMDOMCONSTRUCTOR_IID_STR "0ccbcf19-d1b4-489e-984c-cd8c43672bb9"

#define NS_IDOMDOMCONSTRUCTOR_IID \
  {0x0ccbcf19, 0xd1b4, 0x489e, \
    { 0x98, 0x4c, 0xcd, 0x8c, 0x43, 0x67, 0x2b, 0xb9 }}

class NS_NO_VTABLE NS_SCRIPTABLE nsIDOMDOMConstructor : public nsISupports {
 public: 

  NS_DECLARE_STATIC_IID_ACCESSOR(NS_IDOMDOMCONSTRUCTOR_IID)

  /* AString toString (); */
  NS_SCRIPTABLE NS_IMETHOD ToString(nsAString & _retval NS_OUTPARAM) = 0;

};

  NS_DEFINE_STATIC_IID_ACCESSOR(nsIDOMDOMConstructor, NS_IDOMDOMCONSTRUCTOR_IID)

/* Use this macro when declaring classes that implement this interface. */
#define NS_DECL_NSIDOMDOMCONSTRUCTOR \
  NS_SCRIPTABLE NS_IMETHOD ToString(nsAString & _retval NS_OUTPARAM); 

/* Use this macro to declare functions that forward the behavior of this interface to another object. */
#define NS_FORWARD_NSIDOMDOMCONSTRUCTOR(_to) \
  NS_SCRIPTABLE NS_IMETHOD ToString(nsAString & _retval NS_OUTPARAM) { return _to ToString(_retval); } 

/* Use this macro to declare functions that forward the behavior of this interface to another object in a safe way. */
#define NS_FORWARD_SAFE_NSIDOMDOMCONSTRUCTOR(_to) \
  NS_SCRIPTABLE NS_IMETHOD ToString(nsAString & _retval NS_OUTPARAM) { return !_to ? NS_ERROR_NULL_POINTER : _to->ToString(_retval); } 

#if 0
/* Use the code below as a template for the implementation class for this interface. */

/* Header file */
class nsDOMDOMConstructor : public nsIDOMDOMConstructor
{
public:
  NS_DECL_ISUPPORTS
  NS_DECL_NSIDOMDOMCONSTRUCTOR

  nsDOMDOMConstructor();

private:
  ~nsDOMDOMConstructor();

protected:
  /* additional members */
};

/* Implementation file */
NS_IMPL_ISUPPORTS1(nsDOMDOMConstructor, nsIDOMDOMConstructor)

nsDOMDOMConstructor::nsDOMDOMConstructor()
{
  /* member initializers and constructor code */
}

nsDOMDOMConstructor::~nsDOMDOMConstructor()
{
  /* destructor code */
}

/* AString toString (); */
NS_IMETHODIMP nsDOMDOMConstructor::ToString(nsAString & _retval NS_OUTPARAM)
{
    return NS_ERROR_NOT_IMPLEMENTED;
}

/* End of implementation class template. */
#endif


#endif /* __gen_nsIDOMConstructor_h__ */
