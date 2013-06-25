/*
 * DO NOT EDIT.  THIS FILE IS GENERATED FROM e:/builds/moz2_slave/mozilla-1.9.1-win32-xulrunner/build/dom/public/idl/core/nsIDOMDOMConfiguration.idl
 */

#ifndef __gen_nsIDOMDOMConfiguration_h__
#define __gen_nsIDOMDOMConfiguration_h__


#ifndef __gen_domstubs_h__
#include "domstubs.h"
#endif

/* For IDL files that don't want to include root IDL files. */
#ifndef NS_NO_VTABLE
#define NS_NO_VTABLE
#endif
class nsIVariant; /* forward declaration */


/* starting interface:    nsIDOMDOMConfiguration */
#define NS_IDOMDOMCONFIGURATION_IID_STR "cfb5b821-9016-4a79-9d98-87b57c3ea0c7"

#define NS_IDOMDOMCONFIGURATION_IID \
  {0xcfb5b821, 0x9016, 0x4a79, \
    { 0x9d, 0x98, 0x87, 0xb5, 0x7c, 0x3e, 0xa0, 0xc7 }}

/**
 * The nsIDOMDOMConfiguration interface represents the configuration
 * of a document and maintains a table of recognized parameters.
 *
 * For more information on this interface, please see
 * http://www.w3.org/TR/DOM-Level-3-Core/
 */
class NS_NO_VTABLE NS_SCRIPTABLE nsIDOMDOMConfiguration : public nsISupports {
 public: 

  NS_DECLARE_STATIC_IID_ACCESSOR(NS_IDOMDOMCONFIGURATION_IID)

  /* void setParameter (in DOMString name, in nsIVariant value)  raises (DOMException); */
  NS_SCRIPTABLE NS_IMETHOD SetParameter(const nsAString & name, nsIVariant *value) = 0;

  /* nsIVariant getParameter (in DOMString name)  raises (DOMException); */
  NS_SCRIPTABLE NS_IMETHOD GetParameter(const nsAString & name, nsIVariant **_retval NS_OUTPARAM) = 0;

  /* boolean canSetParameter (in DOMString name, in nsIVariant value); */
  NS_SCRIPTABLE NS_IMETHOD CanSetParameter(const nsAString & name, nsIVariant *value, PRBool *_retval NS_OUTPARAM) = 0;

};

  NS_DEFINE_STATIC_IID_ACCESSOR(nsIDOMDOMConfiguration, NS_IDOMDOMCONFIGURATION_IID)

/* Use this macro when declaring classes that implement this interface. */
#define NS_DECL_NSIDOMDOMCONFIGURATION \
  NS_SCRIPTABLE NS_IMETHOD SetParameter(const nsAString & name, nsIVariant *value); \
  NS_SCRIPTABLE NS_IMETHOD GetParameter(const nsAString & name, nsIVariant **_retval NS_OUTPARAM); \
  NS_SCRIPTABLE NS_IMETHOD CanSetParameter(const nsAString & name, nsIVariant *value, PRBool *_retval NS_OUTPARAM); 

/* Use this macro to declare functions that forward the behavior of this interface to another object. */
#define NS_FORWARD_NSIDOMDOMCONFIGURATION(_to) \
  NS_SCRIPTABLE NS_IMETHOD SetParameter(const nsAString & name, nsIVariant *value) { return _to SetParameter(name, value); } \
  NS_SCRIPTABLE NS_IMETHOD GetParameter(const nsAString & name, nsIVariant **_retval NS_OUTPARAM) { return _to GetParameter(name, _retval); } \
  NS_SCRIPTABLE NS_IMETHOD CanSetParameter(const nsAString & name, nsIVariant *value, PRBool *_retval NS_OUTPARAM) { return _to CanSetParameter(name, value, _retval); } 

/* Use this macro to declare functions that forward the behavior of this interface to another object in a safe way. */
#define NS_FORWARD_SAFE_NSIDOMDOMCONFIGURATION(_to) \
  NS_SCRIPTABLE NS_IMETHOD SetParameter(const nsAString & name, nsIVariant *value) { return !_to ? NS_ERROR_NULL_POINTER : _to->SetParameter(name, value); } \
  NS_SCRIPTABLE NS_IMETHOD GetParameter(const nsAString & name, nsIVariant **_retval NS_OUTPARAM) { return !_to ? NS_ERROR_NULL_POINTER : _to->GetParameter(name, _retval); } \
  NS_SCRIPTABLE NS_IMETHOD CanSetParameter(const nsAString & name, nsIVariant *value, PRBool *_retval NS_OUTPARAM) { return !_to ? NS_ERROR_NULL_POINTER : _to->CanSetParameter(name, value, _retval); } 

#if 0
/* Use the code below as a template for the implementation class for this interface. */

/* Header file */
class nsDOMDOMConfiguration : public nsIDOMDOMConfiguration
{
public:
  NS_DECL_ISUPPORTS
  NS_DECL_NSIDOMDOMCONFIGURATION

  nsDOMDOMConfiguration();

private:
  ~nsDOMDOMConfiguration();

protected:
  /* additional members */
};

/* Implementation file */
NS_IMPL_ISUPPORTS1(nsDOMDOMConfiguration, nsIDOMDOMConfiguration)

nsDOMDOMConfiguration::nsDOMDOMConfiguration()
{
  /* member initializers and constructor code */
}

nsDOMDOMConfiguration::~nsDOMDOMConfiguration()
{
  /* destructor code */
}

/* void setParameter (in DOMString name, in nsIVariant value)  raises (DOMException); */
NS_IMETHODIMP nsDOMDOMConfiguration::SetParameter(const nsAString & name, nsIVariant *value)
{
    return NS_ERROR_NOT_IMPLEMENTED;
}

/* nsIVariant getParameter (in DOMString name)  raises (DOMException); */
NS_IMETHODIMP nsDOMDOMConfiguration::GetParameter(const nsAString & name, nsIVariant **_retval NS_OUTPARAM)
{
    return NS_ERROR_NOT_IMPLEMENTED;
}

/* boolean canSetParameter (in DOMString name, in nsIVariant value); */
NS_IMETHODIMP nsDOMDOMConfiguration::CanSetParameter(const nsAString & name, nsIVariant *value, PRBool *_retval NS_OUTPARAM)
{
    return NS_ERROR_NOT_IMPLEMENTED;
}

/* End of implementation class template. */
#endif


#endif /* __gen_nsIDOMDOMConfiguration_h__ */
