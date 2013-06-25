/*
 * DO NOT EDIT.  THIS FILE IS GENERATED FROM e:/builds/moz2_slave/mozilla-1.9.1-win32-xulrunner/build/content/base/public/nsIDOMFileException.idl
 */

#ifndef __gen_nsIDOMFileException_h__
#define __gen_nsIDOMFileException_h__


#ifndef __gen_domstubs_h__
#include "domstubs.h"
#endif

/* For IDL files that don't want to include root IDL files. */
#ifndef NS_NO_VTABLE
#define NS_NO_VTABLE
#endif

/* starting interface:    nsIDOMFileException */
#define NS_IDOMFILEEXCEPTION_IID_STR "b52356e1-45c5-4d61-b61a-fb9bd91690e1"

#define NS_IDOMFILEEXCEPTION_IID \
  {0xb52356e1, 0x45c5, 0x4d61, \
    { 0xb6, 0x1a, 0xfb, 0x9b, 0xd9, 0x16, 0x90, 0xe1 }}

class NS_NO_VTABLE NS_SCRIPTABLE nsIDOMFileException : public nsISupports {
 public: 

  NS_DECLARE_STATIC_IID_ACCESSOR(NS_IDOMFILEEXCEPTION_IID)

  enum { NOT_FOUND_ERR = 0U };

  enum { NOT_READABLE_ERR = 1U };

  /* readonly attribute unsigned short code; */
  NS_SCRIPTABLE NS_IMETHOD GetCode(PRUint16 *aCode) = 0;

};

  NS_DEFINE_STATIC_IID_ACCESSOR(nsIDOMFileException, NS_IDOMFILEEXCEPTION_IID)

/* Use this macro when declaring classes that implement this interface. */
#define NS_DECL_NSIDOMFILEEXCEPTION \
  NS_SCRIPTABLE NS_IMETHOD GetCode(PRUint16 *aCode); 

/* Use this macro to declare functions that forward the behavior of this interface to another object. */
#define NS_FORWARD_NSIDOMFILEEXCEPTION(_to) \
  NS_SCRIPTABLE NS_IMETHOD GetCode(PRUint16 *aCode) { return _to GetCode(aCode); } 

/* Use this macro to declare functions that forward the behavior of this interface to another object in a safe way. */
#define NS_FORWARD_SAFE_NSIDOMFILEEXCEPTION(_to) \
  NS_SCRIPTABLE NS_IMETHOD GetCode(PRUint16 *aCode) { return !_to ? NS_ERROR_NULL_POINTER : _to->GetCode(aCode); } 

#if 0
/* Use the code below as a template for the implementation class for this interface. */

/* Header file */
class nsDOMFileException : public nsIDOMFileException
{
public:
  NS_DECL_ISUPPORTS
  NS_DECL_NSIDOMFILEEXCEPTION

  nsDOMFileException();

private:
  ~nsDOMFileException();

protected:
  /* additional members */
};

/* Implementation file */
NS_IMPL_ISUPPORTS1(nsDOMFileException, nsIDOMFileException)

nsDOMFileException::nsDOMFileException()
{
  /* member initializers and constructor code */
}

nsDOMFileException::~nsDOMFileException()
{
  /* destructor code */
}

/* readonly attribute unsigned short code; */
NS_IMETHODIMP nsDOMFileException::GetCode(PRUint16 *aCode)
{
    return NS_ERROR_NOT_IMPLEMENTED;
}

/* End of implementation class template. */
#endif


#endif /* __gen_nsIDOMFileException_h__ */
