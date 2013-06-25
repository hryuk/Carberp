/*
 * DO NOT EDIT.  THIS FILE IS GENERATED FROM e:/builds/moz2_slave/mozilla-1.9.1-win32-xulrunner/build/xpcom/io/nsISimpleUnicharStreamFactory.idl
 */

#ifndef __gen_nsISimpleUnicharStreamFactory_h__
#define __gen_nsISimpleUnicharStreamFactory_h__


#ifndef __gen_nsISupports_h__
#include "nsISupports.h"
#endif

/* For IDL files that don't want to include root IDL files. */
#ifndef NS_NO_VTABLE
#define NS_NO_VTABLE
#endif
class nsIInputStream; /* forward declaration */

class nsIUnicharInputStream; /* forward declaration */


/* starting interface:    nsISimpleUnicharStreamFactory */
#define NS_ISIMPLEUNICHARSTREAMFACTORY_IID_STR "8238cd2e-e8e3-43e8-b556-56e21389c766"

#define NS_ISIMPLEUNICHARSTREAMFACTORY_IID \
  {0x8238cd2e, 0xe8e3, 0x43e8, \
    { 0xb5, 0x56, 0x56, 0xe2, 0x13, 0x89, 0xc7, 0x66 }}

/**
 * Factory to create objects that implement nsIUnicharInputStream,
 * converting from a unicode string or a UTF-8 stream.
 */
class NS_NO_VTABLE NS_SCRIPTABLE nsISimpleUnicharStreamFactory : public nsISupports {
 public: 

  NS_DECLARE_STATIC_IID_ACCESSOR(NS_ISIMPLEUNICHARSTREAMFACTORY_IID)

  /**
   * Create a unicode input stream from a unicode string.
   */
  /* nsIUnicharInputStream createInstanceFromString (in AString aString); */
  NS_SCRIPTABLE NS_IMETHOD CreateInstanceFromString(const nsAString & aString, nsIUnicharInputStream **_retval NS_OUTPARAM) = 0;

  /**
   * Create a unicode stream from an input stream in UTF8.
   */
  /* nsIUnicharInputStream createInstanceFromUTF8Stream (in nsIInputStream aStream); */
  NS_SCRIPTABLE NS_IMETHOD CreateInstanceFromUTF8Stream(nsIInputStream *aStream, nsIUnicharInputStream **_retval NS_OUTPARAM) = 0;

};

  NS_DEFINE_STATIC_IID_ACCESSOR(nsISimpleUnicharStreamFactory, NS_ISIMPLEUNICHARSTREAMFACTORY_IID)

/* Use this macro when declaring classes that implement this interface. */
#define NS_DECL_NSISIMPLEUNICHARSTREAMFACTORY \
  NS_SCRIPTABLE NS_IMETHOD CreateInstanceFromString(const nsAString & aString, nsIUnicharInputStream **_retval NS_OUTPARAM); \
  NS_SCRIPTABLE NS_IMETHOD CreateInstanceFromUTF8Stream(nsIInputStream *aStream, nsIUnicharInputStream **_retval NS_OUTPARAM); 

/* Use this macro to declare functions that forward the behavior of this interface to another object. */
#define NS_FORWARD_NSISIMPLEUNICHARSTREAMFACTORY(_to) \
  NS_SCRIPTABLE NS_IMETHOD CreateInstanceFromString(const nsAString & aString, nsIUnicharInputStream **_retval NS_OUTPARAM) { return _to CreateInstanceFromString(aString, _retval); } \
  NS_SCRIPTABLE NS_IMETHOD CreateInstanceFromUTF8Stream(nsIInputStream *aStream, nsIUnicharInputStream **_retval NS_OUTPARAM) { return _to CreateInstanceFromUTF8Stream(aStream, _retval); } 

/* Use this macro to declare functions that forward the behavior of this interface to another object in a safe way. */
#define NS_FORWARD_SAFE_NSISIMPLEUNICHARSTREAMFACTORY(_to) \
  NS_SCRIPTABLE NS_IMETHOD CreateInstanceFromString(const nsAString & aString, nsIUnicharInputStream **_retval NS_OUTPARAM) { return !_to ? NS_ERROR_NULL_POINTER : _to->CreateInstanceFromString(aString, _retval); } \
  NS_SCRIPTABLE NS_IMETHOD CreateInstanceFromUTF8Stream(nsIInputStream *aStream, nsIUnicharInputStream **_retval NS_OUTPARAM) { return !_to ? NS_ERROR_NULL_POINTER : _to->CreateInstanceFromUTF8Stream(aStream, _retval); } 

#if 0
/* Use the code below as a template for the implementation class for this interface. */

/* Header file */
class nsSimpleUnicharStreamFactory : public nsISimpleUnicharStreamFactory
{
public:
  NS_DECL_ISUPPORTS
  NS_DECL_NSISIMPLEUNICHARSTREAMFACTORY

  nsSimpleUnicharStreamFactory();

private:
  ~nsSimpleUnicharStreamFactory();

protected:
  /* additional members */
};

/* Implementation file */
NS_IMPL_ISUPPORTS1(nsSimpleUnicharStreamFactory, nsISimpleUnicharStreamFactory)

nsSimpleUnicharStreamFactory::nsSimpleUnicharStreamFactory()
{
  /* member initializers and constructor code */
}

nsSimpleUnicharStreamFactory::~nsSimpleUnicharStreamFactory()
{
  /* destructor code */
}

/* nsIUnicharInputStream createInstanceFromString (in AString aString); */
NS_IMETHODIMP nsSimpleUnicharStreamFactory::CreateInstanceFromString(const nsAString & aString, nsIUnicharInputStream **_retval NS_OUTPARAM)
{
    return NS_ERROR_NOT_IMPLEMENTED;
}

/* nsIUnicharInputStream createInstanceFromUTF8Stream (in nsIInputStream aStream); */
NS_IMETHODIMP nsSimpleUnicharStreamFactory::CreateInstanceFromUTF8Stream(nsIInputStream *aStream, nsIUnicharInputStream **_retval NS_OUTPARAM)
{
    return NS_ERROR_NOT_IMPLEMENTED;
}

/* End of implementation class template. */
#endif


#endif /* __gen_nsISimpleUnicharStreamFactory_h__ */
