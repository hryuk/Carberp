/*
 * DO NOT EDIT.  THIS FILE IS GENERATED FROM e:/builds/moz2_slave/mozilla-1.9.1-win32-xulrunner/build/content/xtf/public/nsIXTFElementFactory.idl
 */

#ifndef __gen_nsIXTFElementFactory_h__
#define __gen_nsIXTFElementFactory_h__


#ifndef __gen_nsISupports_h__
#include "nsISupports.h"
#endif

/* For IDL files that don't want to include root IDL files. */
#ifndef NS_NO_VTABLE
#define NS_NO_VTABLE
#endif
class nsIXTFElement; /* forward declaration */


/* starting interface:    nsIXTFElementFactory */
#define NS_IXTFELEMENTFACTORY_IID_STR "27c10dca-2efc-416b-ae36-9794380a661e"

#define NS_IXTFELEMENTFACTORY_IID \
  {0x27c10dca, 0x2efc, 0x416b, \
    { 0xae, 0x36, 0x97, 0x94, 0x38, 0x0a, 0x66, 0x1e }}

class NS_NO_VTABLE NS_SCRIPTABLE nsIXTFElementFactory : public nsISupports {
 public: 

  NS_DECLARE_STATIC_IID_ACCESSOR(NS_IXTFELEMENTFACTORY_IID)

  /* nsIXTFElement createElement (in AString tagName); */
  NS_SCRIPTABLE NS_IMETHOD CreateElement(const nsAString & tagName, nsIXTFElement **_retval NS_OUTPARAM) = 0;

};

  NS_DEFINE_STATIC_IID_ACCESSOR(nsIXTFElementFactory, NS_IXTFELEMENTFACTORY_IID)

/* Use this macro when declaring classes that implement this interface. */
#define NS_DECL_NSIXTFELEMENTFACTORY \
  NS_SCRIPTABLE NS_IMETHOD CreateElement(const nsAString & tagName, nsIXTFElement **_retval NS_OUTPARAM); 

/* Use this macro to declare functions that forward the behavior of this interface to another object. */
#define NS_FORWARD_NSIXTFELEMENTFACTORY(_to) \
  NS_SCRIPTABLE NS_IMETHOD CreateElement(const nsAString & tagName, nsIXTFElement **_retval NS_OUTPARAM) { return _to CreateElement(tagName, _retval); } 

/* Use this macro to declare functions that forward the behavior of this interface to another object in a safe way. */
#define NS_FORWARD_SAFE_NSIXTFELEMENTFACTORY(_to) \
  NS_SCRIPTABLE NS_IMETHOD CreateElement(const nsAString & tagName, nsIXTFElement **_retval NS_OUTPARAM) { return !_to ? NS_ERROR_NULL_POINTER : _to->CreateElement(tagName, _retval); } 

#if 0
/* Use the code below as a template for the implementation class for this interface. */

/* Header file */
class nsXTFElementFactory : public nsIXTFElementFactory
{
public:
  NS_DECL_ISUPPORTS
  NS_DECL_NSIXTFELEMENTFACTORY

  nsXTFElementFactory();

private:
  ~nsXTFElementFactory();

protected:
  /* additional members */
};

/* Implementation file */
NS_IMPL_ISUPPORTS1(nsXTFElementFactory, nsIXTFElementFactory)

nsXTFElementFactory::nsXTFElementFactory()
{
  /* member initializers and constructor code */
}

nsXTFElementFactory::~nsXTFElementFactory()
{
  /* destructor code */
}

/* nsIXTFElement createElement (in AString tagName); */
NS_IMETHODIMP nsXTFElementFactory::CreateElement(const nsAString & tagName, nsIXTFElement **_retval NS_OUTPARAM)
{
    return NS_ERROR_NOT_IMPLEMENTED;
}

/* End of implementation class template. */
#endif

    
#define NS_XTF_ELEMENT_FACTORY_CONTRACTID         "@mozilla.org/xtf/element-factory;1"
#define NS_XTF_ELEMENT_FACTORY_CONTRACTID_PREFIX  NS_XTF_ELEMENT_FACTORY_CONTRACTID "?namespace="

#endif /* __gen_nsIXTFElementFactory_h__ */
