/*
 * DO NOT EDIT.  THIS FILE IS GENERATED FROM e:/builds/moz2_slave/mozilla-1.9.1-win32-xulrunner/build/dom/public/idl/ls/nsIDOMDOMImplementationLS.idl
 */

#ifndef __gen_nsIDOMDOMImplementationLS_h__
#define __gen_nsIDOMDOMImplementationLS_h__


#ifndef __gen_domstubs_h__
#include "domstubs.h"
#endif

/* For IDL files that don't want to include root IDL files. */
#ifndef NS_NO_VTABLE
#define NS_NO_VTABLE
#endif
class nsIDOMLSParser; /* forward declaration */

class nsIDOMLSSerializer; /* forward declaration */

class nsIDOMLSInput; /* forward declaration */

class nsIDOMLSOutput; /* forward declaration */


/* starting interface:    nsIDOMDOMImplementationLS */
#define NS_IDOMDOMIMPLEMENTATIONLS_IID_STR "e2c8b03c-a49a-4923-81b0-ba9a86da0e21"

#define NS_IDOMDOMIMPLEMENTATIONLS_IID \
  {0xe2c8b03c, 0xa49a, 0x4923, \
    { 0x81, 0xb0, 0xba, 0x9a, 0x86, 0xda, 0x0e, 0x21 }}

class NS_NO_VTABLE NS_SCRIPTABLE nsIDOMDOMImplementationLS : public nsISupports {
 public: 

  NS_DECLARE_STATIC_IID_ACCESSOR(NS_IDOMDOMIMPLEMENTATIONLS_IID)

  enum { MODE_SYNCHRONOUS = 1U };

  enum { MODE_ASYNCHRONOUS = 2U };

  /* nsIDOMLSParser createLSParser (in unsigned short mode, in DOMString schemaType)  raises (DOMException); */
  NS_SCRIPTABLE NS_IMETHOD CreateLSParser(PRUint16 mode, const nsAString & schemaType, nsIDOMLSParser **_retval NS_OUTPARAM) = 0;

  /* nsIDOMLSSerializer createLSSerializer (); */
  NS_SCRIPTABLE NS_IMETHOD CreateLSSerializer(nsIDOMLSSerializer **_retval NS_OUTPARAM) = 0;

  /* nsIDOMLSInput createLSInput (); */
  NS_SCRIPTABLE NS_IMETHOD CreateLSInput(nsIDOMLSInput **_retval NS_OUTPARAM) = 0;

  /* nsIDOMLSOutput createLSOutput (); */
  NS_SCRIPTABLE NS_IMETHOD CreateLSOutput(nsIDOMLSOutput **_retval NS_OUTPARAM) = 0;

};

  NS_DEFINE_STATIC_IID_ACCESSOR(nsIDOMDOMImplementationLS, NS_IDOMDOMIMPLEMENTATIONLS_IID)

/* Use this macro when declaring classes that implement this interface. */
#define NS_DECL_NSIDOMDOMIMPLEMENTATIONLS \
  NS_SCRIPTABLE NS_IMETHOD CreateLSParser(PRUint16 mode, const nsAString & schemaType, nsIDOMLSParser **_retval NS_OUTPARAM); \
  NS_SCRIPTABLE NS_IMETHOD CreateLSSerializer(nsIDOMLSSerializer **_retval NS_OUTPARAM); \
  NS_SCRIPTABLE NS_IMETHOD CreateLSInput(nsIDOMLSInput **_retval NS_OUTPARAM); \
  NS_SCRIPTABLE NS_IMETHOD CreateLSOutput(nsIDOMLSOutput **_retval NS_OUTPARAM); 

/* Use this macro to declare functions that forward the behavior of this interface to another object. */
#define NS_FORWARD_NSIDOMDOMIMPLEMENTATIONLS(_to) \
  NS_SCRIPTABLE NS_IMETHOD CreateLSParser(PRUint16 mode, const nsAString & schemaType, nsIDOMLSParser **_retval NS_OUTPARAM) { return _to CreateLSParser(mode, schemaType, _retval); } \
  NS_SCRIPTABLE NS_IMETHOD CreateLSSerializer(nsIDOMLSSerializer **_retval NS_OUTPARAM) { return _to CreateLSSerializer(_retval); } \
  NS_SCRIPTABLE NS_IMETHOD CreateLSInput(nsIDOMLSInput **_retval NS_OUTPARAM) { return _to CreateLSInput(_retval); } \
  NS_SCRIPTABLE NS_IMETHOD CreateLSOutput(nsIDOMLSOutput **_retval NS_OUTPARAM) { return _to CreateLSOutput(_retval); } 

/* Use this macro to declare functions that forward the behavior of this interface to another object in a safe way. */
#define NS_FORWARD_SAFE_NSIDOMDOMIMPLEMENTATIONLS(_to) \
  NS_SCRIPTABLE NS_IMETHOD CreateLSParser(PRUint16 mode, const nsAString & schemaType, nsIDOMLSParser **_retval NS_OUTPARAM) { return !_to ? NS_ERROR_NULL_POINTER : _to->CreateLSParser(mode, schemaType, _retval); } \
  NS_SCRIPTABLE NS_IMETHOD CreateLSSerializer(nsIDOMLSSerializer **_retval NS_OUTPARAM) { return !_to ? NS_ERROR_NULL_POINTER : _to->CreateLSSerializer(_retval); } \
  NS_SCRIPTABLE NS_IMETHOD CreateLSInput(nsIDOMLSInput **_retval NS_OUTPARAM) { return !_to ? NS_ERROR_NULL_POINTER : _to->CreateLSInput(_retval); } \
  NS_SCRIPTABLE NS_IMETHOD CreateLSOutput(nsIDOMLSOutput **_retval NS_OUTPARAM) { return !_to ? NS_ERROR_NULL_POINTER : _to->CreateLSOutput(_retval); } 

#if 0
/* Use the code below as a template for the implementation class for this interface. */

/* Header file */
class nsDOMDOMImplementationLS : public nsIDOMDOMImplementationLS
{
public:
  NS_DECL_ISUPPORTS
  NS_DECL_NSIDOMDOMIMPLEMENTATIONLS

  nsDOMDOMImplementationLS();

private:
  ~nsDOMDOMImplementationLS();

protected:
  /* additional members */
};

/* Implementation file */
NS_IMPL_ISUPPORTS1(nsDOMDOMImplementationLS, nsIDOMDOMImplementationLS)

nsDOMDOMImplementationLS::nsDOMDOMImplementationLS()
{
  /* member initializers and constructor code */
}

nsDOMDOMImplementationLS::~nsDOMDOMImplementationLS()
{
  /* destructor code */
}

/* nsIDOMLSParser createLSParser (in unsigned short mode, in DOMString schemaType)  raises (DOMException); */
NS_IMETHODIMP nsDOMDOMImplementationLS::CreateLSParser(PRUint16 mode, const nsAString & schemaType, nsIDOMLSParser **_retval NS_OUTPARAM)
{
    return NS_ERROR_NOT_IMPLEMENTED;
}

/* nsIDOMLSSerializer createLSSerializer (); */
NS_IMETHODIMP nsDOMDOMImplementationLS::CreateLSSerializer(nsIDOMLSSerializer **_retval NS_OUTPARAM)
{
    return NS_ERROR_NOT_IMPLEMENTED;
}

/* nsIDOMLSInput createLSInput (); */
NS_IMETHODIMP nsDOMDOMImplementationLS::CreateLSInput(nsIDOMLSInput **_retval NS_OUTPARAM)
{
    return NS_ERROR_NOT_IMPLEMENTED;
}

/* nsIDOMLSOutput createLSOutput (); */
NS_IMETHODIMP nsDOMDOMImplementationLS::CreateLSOutput(nsIDOMLSOutput **_retval NS_OUTPARAM)
{
    return NS_ERROR_NOT_IMPLEMENTED;
}

/* End of implementation class template. */
#endif


#endif /* __gen_nsIDOMDOMImplementationLS_h__ */
