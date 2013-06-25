/*
 * DO NOT EDIT.  THIS FILE IS GENERATED FROM e:/builds/moz2_slave/mozilla-1.9.1-win32-xulrunner/build/dom/public/idl/base/nsIDOMNSFeatureFactory.idl
 */

#ifndef __gen_nsIDOMNSFeatureFactory_h__
#define __gen_nsIDOMNSFeatureFactory_h__


#ifndef __gen_domstubs_h__
#include "domstubs.h"
#endif

/* For IDL files that don't want to include root IDL files. */
#ifndef NS_NO_VTABLE
#define NS_NO_VTABLE
#endif

/* starting interface:    nsIDOMNSFeatureFactory */
#define NS_IDOMNSFEATUREFACTORY_IID_STR "dc5ba787-b648-4b01-a8e7-b293ffb044ef"

#define NS_IDOMNSFEATUREFACTORY_IID \
  {0xdc5ba787, 0xb648, 0x4b01, \
    { 0xa8, 0xe7, 0xb2, 0x93, 0xff, 0xb0, 0x44, 0xef }}

class NS_NO_VTABLE NS_SCRIPTABLE nsIDOMNSFeatureFactory : public nsISupports {
 public: 

  NS_DECLARE_STATIC_IID_ACCESSOR(NS_IDOMNSFEATUREFACTORY_IID)

  /**
   * @param object: usually either nsIDOMNode or nsIDOMDOMImplementation
   * @param feature: the name of the feature
   * @param version: the version of the feature
   */
  /* boolean hasFeature (in nsISupports object, in DOMString feature, in DOMString version); */
  NS_SCRIPTABLE NS_IMETHOD HasFeature(nsISupports *object, const nsAString & feature, const nsAString & version, PRBool *_retval NS_OUTPARAM) = 0;

  /**
   * @param object: usually either nsIDOMNode or nsIDOMDOMImplementation
   * @param feature: the name of the feature
   * @param version: the version of the feature
   */
  /* nsISupports getFeature (in nsISupports object, in DOMString feature, in DOMString version); */
  NS_SCRIPTABLE NS_IMETHOD GetFeature(nsISupports *object, const nsAString & feature, const nsAString & version, nsISupports **_retval NS_OUTPARAM) = 0;

};

  NS_DEFINE_STATIC_IID_ACCESSOR(nsIDOMNSFeatureFactory, NS_IDOMNSFEATUREFACTORY_IID)

/* Use this macro when declaring classes that implement this interface. */
#define NS_DECL_NSIDOMNSFEATUREFACTORY \
  NS_SCRIPTABLE NS_IMETHOD HasFeature(nsISupports *object, const nsAString & feature, const nsAString & version, PRBool *_retval NS_OUTPARAM); \
  NS_SCRIPTABLE NS_IMETHOD GetFeature(nsISupports *object, const nsAString & feature, const nsAString & version, nsISupports **_retval NS_OUTPARAM); 

/* Use this macro to declare functions that forward the behavior of this interface to another object. */
#define NS_FORWARD_NSIDOMNSFEATUREFACTORY(_to) \
  NS_SCRIPTABLE NS_IMETHOD HasFeature(nsISupports *object, const nsAString & feature, const nsAString & version, PRBool *_retval NS_OUTPARAM) { return _to HasFeature(object, feature, version, _retval); } \
  NS_SCRIPTABLE NS_IMETHOD GetFeature(nsISupports *object, const nsAString & feature, const nsAString & version, nsISupports **_retval NS_OUTPARAM) { return _to GetFeature(object, feature, version, _retval); } 

/* Use this macro to declare functions that forward the behavior of this interface to another object in a safe way. */
#define NS_FORWARD_SAFE_NSIDOMNSFEATUREFACTORY(_to) \
  NS_SCRIPTABLE NS_IMETHOD HasFeature(nsISupports *object, const nsAString & feature, const nsAString & version, PRBool *_retval NS_OUTPARAM) { return !_to ? NS_ERROR_NULL_POINTER : _to->HasFeature(object, feature, version, _retval); } \
  NS_SCRIPTABLE NS_IMETHOD GetFeature(nsISupports *object, const nsAString & feature, const nsAString & version, nsISupports **_retval NS_OUTPARAM) { return !_to ? NS_ERROR_NULL_POINTER : _to->GetFeature(object, feature, version, _retval); } 

#if 0
/* Use the code below as a template for the implementation class for this interface. */

/* Header file */
class nsDOMNSFeatureFactory : public nsIDOMNSFeatureFactory
{
public:
  NS_DECL_ISUPPORTS
  NS_DECL_NSIDOMNSFEATUREFACTORY

  nsDOMNSFeatureFactory();

private:
  ~nsDOMNSFeatureFactory();

protected:
  /* additional members */
};

/* Implementation file */
NS_IMPL_ISUPPORTS1(nsDOMNSFeatureFactory, nsIDOMNSFeatureFactory)

nsDOMNSFeatureFactory::nsDOMNSFeatureFactory()
{
  /* member initializers and constructor code */
}

nsDOMNSFeatureFactory::~nsDOMNSFeatureFactory()
{
  /* destructor code */
}

/* boolean hasFeature (in nsISupports object, in DOMString feature, in DOMString version); */
NS_IMETHODIMP nsDOMNSFeatureFactory::HasFeature(nsISupports *object, const nsAString & feature, const nsAString & version, PRBool *_retval NS_OUTPARAM)
{
    return NS_ERROR_NOT_IMPLEMENTED;
}

/* nsISupports getFeature (in nsISupports object, in DOMString feature, in DOMString version); */
NS_IMETHODIMP nsDOMNSFeatureFactory::GetFeature(nsISupports *object, const nsAString & feature, const nsAString & version, nsISupports **_retval NS_OUTPARAM)
{
    return NS_ERROR_NOT_IMPLEMENTED;
}

/* End of implementation class template. */
#endif

#define NS_DOMNS_FEATURE_PREFIX "MozillaDOMFeature-"

#endif /* __gen_nsIDOMNSFeatureFactory_h__ */
