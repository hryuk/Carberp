/*
 * DO NOT EDIT.  THIS FILE IS GENERATED FROM e:/builds/moz2_slave/mozilla-1.9.1-win32-xulrunner/build/dom/public/idl/base/nsIDOMMimeType.idl
 */

#ifndef __gen_nsIDOMMimeType_h__
#define __gen_nsIDOMMimeType_h__


#ifndef __gen_domstubs_h__
#include "domstubs.h"
#endif

/* For IDL files that don't want to include root IDL files. */
#ifndef NS_NO_VTABLE
#define NS_NO_VTABLE
#endif

/* starting interface:    nsIDOMMimeType */
#define NS_IDOMMIMETYPE_IID_STR "f6134682-f28b-11d2-8360-c90899049c3c"

#define NS_IDOMMIMETYPE_IID \
  {0xf6134682, 0xf28b, 0x11d2, \
    { 0x83, 0x60, 0xc9, 0x08, 0x99, 0x04, 0x9c, 0x3c }}

class NS_NO_VTABLE NS_SCRIPTABLE nsIDOMMimeType : public nsISupports {
 public: 

  NS_DECLARE_STATIC_IID_ACCESSOR(NS_IDOMMIMETYPE_IID)

  /* readonly attribute DOMString description; */
  NS_SCRIPTABLE NS_IMETHOD GetDescription(nsAString & aDescription) = 0;

  /* readonly attribute nsIDOMPlugin enabledPlugin; */
  NS_SCRIPTABLE NS_IMETHOD GetEnabledPlugin(nsIDOMPlugin * *aEnabledPlugin) = 0;

  /* readonly attribute DOMString suffixes; */
  NS_SCRIPTABLE NS_IMETHOD GetSuffixes(nsAString & aSuffixes) = 0;

  /* readonly attribute DOMString type; */
  NS_SCRIPTABLE NS_IMETHOD GetType(nsAString & aType) = 0;

};

  NS_DEFINE_STATIC_IID_ACCESSOR(nsIDOMMimeType, NS_IDOMMIMETYPE_IID)

/* Use this macro when declaring classes that implement this interface. */
#define NS_DECL_NSIDOMMIMETYPE \
  NS_SCRIPTABLE NS_IMETHOD GetDescription(nsAString & aDescription); \
  NS_SCRIPTABLE NS_IMETHOD GetEnabledPlugin(nsIDOMPlugin * *aEnabledPlugin); \
  NS_SCRIPTABLE NS_IMETHOD GetSuffixes(nsAString & aSuffixes); \
  NS_SCRIPTABLE NS_IMETHOD GetType(nsAString & aType); 

/* Use this macro to declare functions that forward the behavior of this interface to another object. */
#define NS_FORWARD_NSIDOMMIMETYPE(_to) \
  NS_SCRIPTABLE NS_IMETHOD GetDescription(nsAString & aDescription) { return _to GetDescription(aDescription); } \
  NS_SCRIPTABLE NS_IMETHOD GetEnabledPlugin(nsIDOMPlugin * *aEnabledPlugin) { return _to GetEnabledPlugin(aEnabledPlugin); } \
  NS_SCRIPTABLE NS_IMETHOD GetSuffixes(nsAString & aSuffixes) { return _to GetSuffixes(aSuffixes); } \
  NS_SCRIPTABLE NS_IMETHOD GetType(nsAString & aType) { return _to GetType(aType); } 

/* Use this macro to declare functions that forward the behavior of this interface to another object in a safe way. */
#define NS_FORWARD_SAFE_NSIDOMMIMETYPE(_to) \
  NS_SCRIPTABLE NS_IMETHOD GetDescription(nsAString & aDescription) { return !_to ? NS_ERROR_NULL_POINTER : _to->GetDescription(aDescription); } \
  NS_SCRIPTABLE NS_IMETHOD GetEnabledPlugin(nsIDOMPlugin * *aEnabledPlugin) { return !_to ? NS_ERROR_NULL_POINTER : _to->GetEnabledPlugin(aEnabledPlugin); } \
  NS_SCRIPTABLE NS_IMETHOD GetSuffixes(nsAString & aSuffixes) { return !_to ? NS_ERROR_NULL_POINTER : _to->GetSuffixes(aSuffixes); } \
  NS_SCRIPTABLE NS_IMETHOD GetType(nsAString & aType) { return !_to ? NS_ERROR_NULL_POINTER : _to->GetType(aType); } 

#if 0
/* Use the code below as a template for the implementation class for this interface. */

/* Header file */
class nsDOMMimeType : public nsIDOMMimeType
{
public:
  NS_DECL_ISUPPORTS
  NS_DECL_NSIDOMMIMETYPE

  nsDOMMimeType();

private:
  ~nsDOMMimeType();

protected:
  /* additional members */
};

/* Implementation file */
NS_IMPL_ISUPPORTS1(nsDOMMimeType, nsIDOMMimeType)

nsDOMMimeType::nsDOMMimeType()
{
  /* member initializers and constructor code */
}

nsDOMMimeType::~nsDOMMimeType()
{
  /* destructor code */
}

/* readonly attribute DOMString description; */
NS_IMETHODIMP nsDOMMimeType::GetDescription(nsAString & aDescription)
{
    return NS_ERROR_NOT_IMPLEMENTED;
}

/* readonly attribute nsIDOMPlugin enabledPlugin; */
NS_IMETHODIMP nsDOMMimeType::GetEnabledPlugin(nsIDOMPlugin * *aEnabledPlugin)
{
    return NS_ERROR_NOT_IMPLEMENTED;
}

/* readonly attribute DOMString suffixes; */
NS_IMETHODIMP nsDOMMimeType::GetSuffixes(nsAString & aSuffixes)
{
    return NS_ERROR_NOT_IMPLEMENTED;
}

/* readonly attribute DOMString type; */
NS_IMETHODIMP nsDOMMimeType::GetType(nsAString & aType)
{
    return NS_ERROR_NOT_IMPLEMENTED;
}

/* End of implementation class template. */
#endif


#endif /* __gen_nsIDOMMimeType_h__ */
