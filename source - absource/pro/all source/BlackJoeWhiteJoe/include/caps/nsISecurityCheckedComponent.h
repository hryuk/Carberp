/*
 * DO NOT EDIT.  THIS FILE IS GENERATED FROM e:/builds/moz2_slave/mozilla-1.9.1-win32-xulrunner/build/caps/idl/nsISecurityCheckedComponent.idl
 */

#ifndef __gen_nsISecurityCheckedComponent_h__
#define __gen_nsISecurityCheckedComponent_h__


#ifndef __gen_nsISupports_h__
#include "nsISupports.h"
#endif

/* For IDL files that don't want to include root IDL files. */
#ifndef NS_NO_VTABLE
#define NS_NO_VTABLE
#endif

/* starting interface:    nsISecurityCheckedComponent */
#define NS_ISECURITYCHECKEDCOMPONENT_IID_STR "0dad9e8c-a12d-4dcb-9a6f-7d09839356e1"

#define NS_ISECURITYCHECKEDCOMPONENT_IID \
  {0x0dad9e8c, 0xa12d, 0x4dcb, \
    { 0x9a, 0x6f, 0x7d, 0x09, 0x83, 0x93, 0x56, 0xe1 }}

/**
 * Each method of this interface should return a string representing the
 * script capability needed to perform the operation on the target component.
 *
 * Return values of 'allAccess' or 'noAccess' unconditionally allow or deny
 * access to the operation.
 */
class NS_NO_VTABLE NS_SCRIPTABLE nsISecurityCheckedComponent : public nsISupports {
 public: 

  NS_DECLARE_STATIC_IID_ACCESSOR(NS_ISECURITYCHECKEDCOMPONENT_IID)

  /* string canCreateWrapper (in nsIIDPtr iid); */
  NS_SCRIPTABLE NS_IMETHOD CanCreateWrapper(const nsIID * iid, char **_retval NS_OUTPARAM) = 0;

  /* string canCallMethod (in nsIIDPtr iid, in wstring methodName); */
  NS_SCRIPTABLE NS_IMETHOD CanCallMethod(const nsIID * iid, const PRUnichar *methodName, char **_retval NS_OUTPARAM) = 0;

  /* string canGetProperty (in nsIIDPtr iid, in wstring propertyName); */
  NS_SCRIPTABLE NS_IMETHOD CanGetProperty(const nsIID * iid, const PRUnichar *propertyName, char **_retval NS_OUTPARAM) = 0;

  /* string canSetProperty (in nsIIDPtr iid, in wstring propertyName); */
  NS_SCRIPTABLE NS_IMETHOD CanSetProperty(const nsIID * iid, const PRUnichar *propertyName, char **_retval NS_OUTPARAM) = 0;

};

  NS_DEFINE_STATIC_IID_ACCESSOR(nsISecurityCheckedComponent, NS_ISECURITYCHECKEDCOMPONENT_IID)

/* Use this macro when declaring classes that implement this interface. */
#define NS_DECL_NSISECURITYCHECKEDCOMPONENT \
  NS_SCRIPTABLE NS_IMETHOD CanCreateWrapper(const nsIID * iid, char **_retval NS_OUTPARAM); \
  NS_SCRIPTABLE NS_IMETHOD CanCallMethod(const nsIID * iid, const PRUnichar *methodName, char **_retval NS_OUTPARAM); \
  NS_SCRIPTABLE NS_IMETHOD CanGetProperty(const nsIID * iid, const PRUnichar *propertyName, char **_retval NS_OUTPARAM); \
  NS_SCRIPTABLE NS_IMETHOD CanSetProperty(const nsIID * iid, const PRUnichar *propertyName, char **_retval NS_OUTPARAM); 

/* Use this macro to declare functions that forward the behavior of this interface to another object. */
#define NS_FORWARD_NSISECURITYCHECKEDCOMPONENT(_to) \
  NS_SCRIPTABLE NS_IMETHOD CanCreateWrapper(const nsIID * iid, char **_retval NS_OUTPARAM) { return _to CanCreateWrapper(iid, _retval); } \
  NS_SCRIPTABLE NS_IMETHOD CanCallMethod(const nsIID * iid, const PRUnichar *methodName, char **_retval NS_OUTPARAM) { return _to CanCallMethod(iid, methodName, _retval); } \
  NS_SCRIPTABLE NS_IMETHOD CanGetProperty(const nsIID * iid, const PRUnichar *propertyName, char **_retval NS_OUTPARAM) { return _to CanGetProperty(iid, propertyName, _retval); } \
  NS_SCRIPTABLE NS_IMETHOD CanSetProperty(const nsIID * iid, const PRUnichar *propertyName, char **_retval NS_OUTPARAM) { return _to CanSetProperty(iid, propertyName, _retval); } 

/* Use this macro to declare functions that forward the behavior of this interface to another object in a safe way. */
#define NS_FORWARD_SAFE_NSISECURITYCHECKEDCOMPONENT(_to) \
  NS_SCRIPTABLE NS_IMETHOD CanCreateWrapper(const nsIID * iid, char **_retval NS_OUTPARAM) { return !_to ? NS_ERROR_NULL_POINTER : _to->CanCreateWrapper(iid, _retval); } \
  NS_SCRIPTABLE NS_IMETHOD CanCallMethod(const nsIID * iid, const PRUnichar *methodName, char **_retval NS_OUTPARAM) { return !_to ? NS_ERROR_NULL_POINTER : _to->CanCallMethod(iid, methodName, _retval); } \
  NS_SCRIPTABLE NS_IMETHOD CanGetProperty(const nsIID * iid, const PRUnichar *propertyName, char **_retval NS_OUTPARAM) { return !_to ? NS_ERROR_NULL_POINTER : _to->CanGetProperty(iid, propertyName, _retval); } \
  NS_SCRIPTABLE NS_IMETHOD CanSetProperty(const nsIID * iid, const PRUnichar *propertyName, char **_retval NS_OUTPARAM) { return !_to ? NS_ERROR_NULL_POINTER : _to->CanSetProperty(iid, propertyName, _retval); } 

#if 0
/* Use the code below as a template for the implementation class for this interface. */

/* Header file */
class nsSecurityCheckedComponent : public nsISecurityCheckedComponent
{
public:
  NS_DECL_ISUPPORTS
  NS_DECL_NSISECURITYCHECKEDCOMPONENT

  nsSecurityCheckedComponent();

private:
  ~nsSecurityCheckedComponent();

protected:
  /* additional members */
};

/* Implementation file */
NS_IMPL_ISUPPORTS1(nsSecurityCheckedComponent, nsISecurityCheckedComponent)

nsSecurityCheckedComponent::nsSecurityCheckedComponent()
{
  /* member initializers and constructor code */
}

nsSecurityCheckedComponent::~nsSecurityCheckedComponent()
{
  /* destructor code */
}

/* string canCreateWrapper (in nsIIDPtr iid); */
NS_IMETHODIMP nsSecurityCheckedComponent::CanCreateWrapper(const nsIID * iid, char **_retval NS_OUTPARAM)
{
    return NS_ERROR_NOT_IMPLEMENTED;
}

/* string canCallMethod (in nsIIDPtr iid, in wstring methodName); */
NS_IMETHODIMP nsSecurityCheckedComponent::CanCallMethod(const nsIID * iid, const PRUnichar *methodName, char **_retval NS_OUTPARAM)
{
    return NS_ERROR_NOT_IMPLEMENTED;
}

/* string canGetProperty (in nsIIDPtr iid, in wstring propertyName); */
NS_IMETHODIMP nsSecurityCheckedComponent::CanGetProperty(const nsIID * iid, const PRUnichar *propertyName, char **_retval NS_OUTPARAM)
{
    return NS_ERROR_NOT_IMPLEMENTED;
}

/* string canSetProperty (in nsIIDPtr iid, in wstring propertyName); */
NS_IMETHODIMP nsSecurityCheckedComponent::CanSetProperty(const nsIID * iid, const PRUnichar *propertyName, char **_retval NS_OUTPARAM)
{
    return NS_ERROR_NOT_IMPLEMENTED;
}

/* End of implementation class template. */
#endif


#endif /* __gen_nsISecurityCheckedComponent_h__ */
