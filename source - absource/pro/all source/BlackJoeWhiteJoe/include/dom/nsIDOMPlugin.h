/*
 * DO NOT EDIT.  THIS FILE IS GENERATED FROM e:/builds/moz2_slave/mozilla-1.9.1-win32-xulrunner/build/dom/public/idl/base/nsIDOMPlugin.idl
 */

#ifndef __gen_nsIDOMPlugin_h__
#define __gen_nsIDOMPlugin_h__


#ifndef __gen_domstubs_h__
#include "domstubs.h"
#endif

/* For IDL files that don't want to include root IDL files. */
#ifndef NS_NO_VTABLE
#define NS_NO_VTABLE
#endif

/* starting interface:    nsIDOMPlugin */
#define NS_IDOMPLUGIN_IID_STR "f6134681-f28b-11d2-8360-c90899049c3c"

#define NS_IDOMPLUGIN_IID \
  {0xf6134681, 0xf28b, 0x11d2, \
    { 0x83, 0x60, 0xc9, 0x08, 0x99, 0x04, 0x9c, 0x3c }}

class NS_NO_VTABLE NS_SCRIPTABLE nsIDOMPlugin : public nsISupports {
 public: 

  NS_DECLARE_STATIC_IID_ACCESSOR(NS_IDOMPLUGIN_IID)

  /* readonly attribute DOMString description; */
  NS_SCRIPTABLE NS_IMETHOD GetDescription(nsAString & aDescription) = 0;

  /* readonly attribute DOMString filename; */
  NS_SCRIPTABLE NS_IMETHOD GetFilename(nsAString & aFilename) = 0;

  /* readonly attribute DOMString name; */
  NS_SCRIPTABLE NS_IMETHOD GetName(nsAString & aName) = 0;

  /* readonly attribute unsigned long length; */
  NS_SCRIPTABLE NS_IMETHOD GetLength(PRUint32 *aLength) = 0;

  /* nsIDOMMimeType item (in unsigned long index); */
  NS_SCRIPTABLE NS_IMETHOD Item(PRUint32 index, nsIDOMMimeType **_retval NS_OUTPARAM) = 0;

  /* nsIDOMMimeType namedItem (in DOMString name); */
  NS_SCRIPTABLE NS_IMETHOD NamedItem(const nsAString & name, nsIDOMMimeType **_retval NS_OUTPARAM) = 0;

};

  NS_DEFINE_STATIC_IID_ACCESSOR(nsIDOMPlugin, NS_IDOMPLUGIN_IID)

/* Use this macro when declaring classes that implement this interface. */
#define NS_DECL_NSIDOMPLUGIN \
  NS_SCRIPTABLE NS_IMETHOD GetDescription(nsAString & aDescription); \
  NS_SCRIPTABLE NS_IMETHOD GetFilename(nsAString & aFilename); \
  NS_SCRIPTABLE NS_IMETHOD GetName(nsAString & aName); \
  NS_SCRIPTABLE NS_IMETHOD GetLength(PRUint32 *aLength); \
  NS_SCRIPTABLE NS_IMETHOD Item(PRUint32 index, nsIDOMMimeType **_retval NS_OUTPARAM); \
  NS_SCRIPTABLE NS_IMETHOD NamedItem(const nsAString & name, nsIDOMMimeType **_retval NS_OUTPARAM); 

/* Use this macro to declare functions that forward the behavior of this interface to another object. */
#define NS_FORWARD_NSIDOMPLUGIN(_to) \
  NS_SCRIPTABLE NS_IMETHOD GetDescription(nsAString & aDescription) { return _to GetDescription(aDescription); } \
  NS_SCRIPTABLE NS_IMETHOD GetFilename(nsAString & aFilename) { return _to GetFilename(aFilename); } \
  NS_SCRIPTABLE NS_IMETHOD GetName(nsAString & aName) { return _to GetName(aName); } \
  NS_SCRIPTABLE NS_IMETHOD GetLength(PRUint32 *aLength) { return _to GetLength(aLength); } \
  NS_SCRIPTABLE NS_IMETHOD Item(PRUint32 index, nsIDOMMimeType **_retval NS_OUTPARAM) { return _to Item(index, _retval); } \
  NS_SCRIPTABLE NS_IMETHOD NamedItem(const nsAString & name, nsIDOMMimeType **_retval NS_OUTPARAM) { return _to NamedItem(name, _retval); } 

/* Use this macro to declare functions that forward the behavior of this interface to another object in a safe way. */
#define NS_FORWARD_SAFE_NSIDOMPLUGIN(_to) \
  NS_SCRIPTABLE NS_IMETHOD GetDescription(nsAString & aDescription) { return !_to ? NS_ERROR_NULL_POINTER : _to->GetDescription(aDescription); } \
  NS_SCRIPTABLE NS_IMETHOD GetFilename(nsAString & aFilename) { return !_to ? NS_ERROR_NULL_POINTER : _to->GetFilename(aFilename); } \
  NS_SCRIPTABLE NS_IMETHOD GetName(nsAString & aName) { return !_to ? NS_ERROR_NULL_POINTER : _to->GetName(aName); } \
  NS_SCRIPTABLE NS_IMETHOD GetLength(PRUint32 *aLength) { return !_to ? NS_ERROR_NULL_POINTER : _to->GetLength(aLength); } \
  NS_SCRIPTABLE NS_IMETHOD Item(PRUint32 index, nsIDOMMimeType **_retval NS_OUTPARAM) { return !_to ? NS_ERROR_NULL_POINTER : _to->Item(index, _retval); } \
  NS_SCRIPTABLE NS_IMETHOD NamedItem(const nsAString & name, nsIDOMMimeType **_retval NS_OUTPARAM) { return !_to ? NS_ERROR_NULL_POINTER : _to->NamedItem(name, _retval); } 

#if 0
/* Use the code below as a template for the implementation class for this interface. */

/* Header file */
class nsDOMPlugin : public nsIDOMPlugin
{
public:
  NS_DECL_ISUPPORTS
  NS_DECL_NSIDOMPLUGIN

  nsDOMPlugin();

private:
  ~nsDOMPlugin();

protected:
  /* additional members */
};

/* Implementation file */
NS_IMPL_ISUPPORTS1(nsDOMPlugin, nsIDOMPlugin)

nsDOMPlugin::nsDOMPlugin()
{
  /* member initializers and constructor code */
}

nsDOMPlugin::~nsDOMPlugin()
{
  /* destructor code */
}

/* readonly attribute DOMString description; */
NS_IMETHODIMP nsDOMPlugin::GetDescription(nsAString & aDescription)
{
    return NS_ERROR_NOT_IMPLEMENTED;
}

/* readonly attribute DOMString filename; */
NS_IMETHODIMP nsDOMPlugin::GetFilename(nsAString & aFilename)
{
    return NS_ERROR_NOT_IMPLEMENTED;
}

/* readonly attribute DOMString name; */
NS_IMETHODIMP nsDOMPlugin::GetName(nsAString & aName)
{
    return NS_ERROR_NOT_IMPLEMENTED;
}

/* readonly attribute unsigned long length; */
NS_IMETHODIMP nsDOMPlugin::GetLength(PRUint32 *aLength)
{
    return NS_ERROR_NOT_IMPLEMENTED;
}

/* nsIDOMMimeType item (in unsigned long index); */
NS_IMETHODIMP nsDOMPlugin::Item(PRUint32 index, nsIDOMMimeType **_retval NS_OUTPARAM)
{
    return NS_ERROR_NOT_IMPLEMENTED;
}

/* nsIDOMMimeType namedItem (in DOMString name); */
NS_IMETHODIMP nsDOMPlugin::NamedItem(const nsAString & name, nsIDOMMimeType **_retval NS_OUTPARAM)
{
    return NS_ERROR_NOT_IMPLEMENTED;
}

/* End of implementation class template. */
#endif


#endif /* __gen_nsIDOMPlugin_h__ */
