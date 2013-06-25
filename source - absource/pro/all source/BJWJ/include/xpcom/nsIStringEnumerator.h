/*
 * DO NOT EDIT.  THIS FILE IS GENERATED FROM e:/builds/moz2_slave/mozilla-1.9.1-win32-xulrunner/build/xpcom/ds/nsIStringEnumerator.idl
 */

#ifndef __gen_nsIStringEnumerator_h__
#define __gen_nsIStringEnumerator_h__


#ifndef __gen_nsISupports_h__
#include "nsISupports.h"
#endif

/* For IDL files that don't want to include root IDL files. */
#ifndef NS_NO_VTABLE
#define NS_NO_VTABLE
#endif

/* starting interface:    nsIStringEnumerator */
#define NS_ISTRINGENUMERATOR_IID_STR "50d3ef6c-9380-4f06-9fb2-95488f7d141c"

#define NS_ISTRINGENUMERATOR_IID \
  {0x50d3ef6c, 0x9380, 0x4f06, \
    { 0x9f, 0xb2, 0x95, 0x48, 0x8f, 0x7d, 0x14, 0x1c }}

/**
 * Used to enumerate over an ordered list of strings.
 */
class NS_NO_VTABLE NS_SCRIPTABLE nsIStringEnumerator : public nsISupports {
 public: 

  NS_DECLARE_STATIC_IID_ACCESSOR(NS_ISTRINGENUMERATOR_IID)

  /* boolean hasMore (); */
  NS_SCRIPTABLE NS_IMETHOD HasMore(PRBool *_retval NS_OUTPARAM) = 0;

  /* AString getNext (); */
  NS_SCRIPTABLE NS_IMETHOD GetNext(nsAString & _retval NS_OUTPARAM) = 0;

};

  NS_DEFINE_STATIC_IID_ACCESSOR(nsIStringEnumerator, NS_ISTRINGENUMERATOR_IID)

/* Use this macro when declaring classes that implement this interface. */
#define NS_DECL_NSISTRINGENUMERATOR \
  NS_SCRIPTABLE NS_IMETHOD HasMore(PRBool *_retval NS_OUTPARAM); \
  NS_SCRIPTABLE NS_IMETHOD GetNext(nsAString & _retval NS_OUTPARAM); 

/* Use this macro to declare functions that forward the behavior of this interface to another object. */
#define NS_FORWARD_NSISTRINGENUMERATOR(_to) \
  NS_SCRIPTABLE NS_IMETHOD HasMore(PRBool *_retval NS_OUTPARAM) { return _to HasMore(_retval); } \
  NS_SCRIPTABLE NS_IMETHOD GetNext(nsAString & _retval NS_OUTPARAM) { return _to GetNext(_retval); } 

/* Use this macro to declare functions that forward the behavior of this interface to another object in a safe way. */
#define NS_FORWARD_SAFE_NSISTRINGENUMERATOR(_to) \
  NS_SCRIPTABLE NS_IMETHOD HasMore(PRBool *_retval NS_OUTPARAM) { return !_to ? NS_ERROR_NULL_POINTER : _to->HasMore(_retval); } \
  NS_SCRIPTABLE NS_IMETHOD GetNext(nsAString & _retval NS_OUTPARAM) { return !_to ? NS_ERROR_NULL_POINTER : _to->GetNext(_retval); } 

#if 0
/* Use the code below as a template for the implementation class for this interface. */

/* Header file */
class nsStringEnumerator : public nsIStringEnumerator
{
public:
  NS_DECL_ISUPPORTS
  NS_DECL_NSISTRINGENUMERATOR

  nsStringEnumerator();

private:
  ~nsStringEnumerator();

protected:
  /* additional members */
};

/* Implementation file */
NS_IMPL_ISUPPORTS1(nsStringEnumerator, nsIStringEnumerator)

nsStringEnumerator::nsStringEnumerator()
{
  /* member initializers and constructor code */
}

nsStringEnumerator::~nsStringEnumerator()
{
  /* destructor code */
}

/* boolean hasMore (); */
NS_IMETHODIMP nsStringEnumerator::HasMore(PRBool *_retval NS_OUTPARAM)
{
    return NS_ERROR_NOT_IMPLEMENTED;
}

/* AString getNext (); */
NS_IMETHODIMP nsStringEnumerator::GetNext(nsAString & _retval NS_OUTPARAM)
{
    return NS_ERROR_NOT_IMPLEMENTED;
}

/* End of implementation class template. */
#endif


/* starting interface:    nsIUTF8StringEnumerator */
#define NS_IUTF8STRINGENUMERATOR_IID_STR "9bdf1010-3695-4907-95ed-83d0410ec307"

#define NS_IUTF8STRINGENUMERATOR_IID \
  {0x9bdf1010, 0x3695, 0x4907, \
    { 0x95, 0xed, 0x83, 0xd0, 0x41, 0x0e, 0xc3, 0x07 }}

class NS_NO_VTABLE NS_SCRIPTABLE nsIUTF8StringEnumerator : public nsISupports {
 public: 

  NS_DECLARE_STATIC_IID_ACCESSOR(NS_IUTF8STRINGENUMERATOR_IID)

  /* boolean hasMore (); */
  NS_SCRIPTABLE NS_IMETHOD HasMore(PRBool *_retval NS_OUTPARAM) = 0;

  /* AUTF8String getNext (); */
  NS_SCRIPTABLE NS_IMETHOD GetNext(nsACString & _retval NS_OUTPARAM) = 0;

};

  NS_DEFINE_STATIC_IID_ACCESSOR(nsIUTF8StringEnumerator, NS_IUTF8STRINGENUMERATOR_IID)

/* Use this macro when declaring classes that implement this interface. */
#define NS_DECL_NSIUTF8STRINGENUMERATOR \
  NS_SCRIPTABLE NS_IMETHOD HasMore(PRBool *_retval NS_OUTPARAM); \
  NS_SCRIPTABLE NS_IMETHOD GetNext(nsACString & _retval NS_OUTPARAM); 

/* Use this macro to declare functions that forward the behavior of this interface to another object. */
#define NS_FORWARD_NSIUTF8STRINGENUMERATOR(_to) \
  NS_SCRIPTABLE NS_IMETHOD HasMore(PRBool *_retval NS_OUTPARAM) { return _to HasMore(_retval); } \
  NS_SCRIPTABLE NS_IMETHOD GetNext(nsACString & _retval NS_OUTPARAM) { return _to GetNext(_retval); } 

/* Use this macro to declare functions that forward the behavior of this interface to another object in a safe way. */
#define NS_FORWARD_SAFE_NSIUTF8STRINGENUMERATOR(_to) \
  NS_SCRIPTABLE NS_IMETHOD HasMore(PRBool *_retval NS_OUTPARAM) { return !_to ? NS_ERROR_NULL_POINTER : _to->HasMore(_retval); } \
  NS_SCRIPTABLE NS_IMETHOD GetNext(nsACString & _retval NS_OUTPARAM) { return !_to ? NS_ERROR_NULL_POINTER : _to->GetNext(_retval); } 

#if 0
/* Use the code below as a template for the implementation class for this interface. */

/* Header file */
class nsUTF8StringEnumerator : public nsIUTF8StringEnumerator
{
public:
  NS_DECL_ISUPPORTS
  NS_DECL_NSIUTF8STRINGENUMERATOR

  nsUTF8StringEnumerator();

private:
  ~nsUTF8StringEnumerator();

protected:
  /* additional members */
};

/* Implementation file */
NS_IMPL_ISUPPORTS1(nsUTF8StringEnumerator, nsIUTF8StringEnumerator)

nsUTF8StringEnumerator::nsUTF8StringEnumerator()
{
  /* member initializers and constructor code */
}

nsUTF8StringEnumerator::~nsUTF8StringEnumerator()
{
  /* destructor code */
}

/* boolean hasMore (); */
NS_IMETHODIMP nsUTF8StringEnumerator::HasMore(PRBool *_retval NS_OUTPARAM)
{
    return NS_ERROR_NOT_IMPLEMENTED;
}

/* AUTF8String getNext (); */
NS_IMETHODIMP nsUTF8StringEnumerator::GetNext(nsACString & _retval NS_OUTPARAM)
{
    return NS_ERROR_NOT_IMPLEMENTED;
}

/* End of implementation class template. */
#endif


#endif /* __gen_nsIStringEnumerator_h__ */
