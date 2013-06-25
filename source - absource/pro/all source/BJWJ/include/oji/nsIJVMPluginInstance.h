/*
 * DO NOT EDIT.  THIS FILE IS GENERATED FROM e:/builds/moz2_slave/mozilla-1.9.1-win32-xulrunner/build/modules/oji/public/nsIJVMPluginInstance.idl
 */

#ifndef __gen_nsIJVMPluginInstance_h__
#define __gen_nsIJVMPluginInstance_h__


#ifndef __gen_nsISupports_h__
#include "nsISupports.h"
#endif

/* For IDL files that don't want to include root IDL files. */
#ifndef NS_NO_VTABLE
#define NS_NO_VTABLE
#endif
#include "jni.h"

/* starting interface:    nsIJVMPluginInstance */
#define NS_IJVMPLUGININSTANCE_IID_STR "a0c057d0-01c1-11d2-815b-006008119d7a"

#define NS_IJVMPLUGININSTANCE_IID \
  {0xa0c057d0, 0x01c1, 0x11d2, \
    { 0x81, 0x5b, 0x00, 0x60, 0x08, 0x11, 0x9d, 0x7a }}

class NS_NO_VTABLE NS_SCRIPTABLE nsIJVMPluginInstance : public nsISupports {
 public: 

  NS_DECLARE_STATIC_IID_ACCESSOR(NS_IJVMPLUGININSTANCE_IID)

  /* [noscript] void GetJavaObject (out jobject result); */
  NS_IMETHOD GetJavaObject(jobject *result NS_OUTPARAM) = 0;

  /* [noscript] void GetText (in nChar result); */
  NS_IMETHOD GetText(const char ** result) = 0;

};

  NS_DEFINE_STATIC_IID_ACCESSOR(nsIJVMPluginInstance, NS_IJVMPLUGININSTANCE_IID)

/* Use this macro when declaring classes that implement this interface. */
#define NS_DECL_NSIJVMPLUGININSTANCE \
  NS_IMETHOD GetJavaObject(jobject *result NS_OUTPARAM); \
  NS_IMETHOD GetText(const char ** result); 

/* Use this macro to declare functions that forward the behavior of this interface to another object. */
#define NS_FORWARD_NSIJVMPLUGININSTANCE(_to) \
  NS_IMETHOD GetJavaObject(jobject *result NS_OUTPARAM) { return _to GetJavaObject(result); } \
  NS_IMETHOD GetText(const char ** result) { return _to GetText(result); } 

/* Use this macro to declare functions that forward the behavior of this interface to another object in a safe way. */
#define NS_FORWARD_SAFE_NSIJVMPLUGININSTANCE(_to) \
  NS_IMETHOD GetJavaObject(jobject *result NS_OUTPARAM) { return !_to ? NS_ERROR_NULL_POINTER : _to->GetJavaObject(result); } \
  NS_IMETHOD GetText(const char ** result) { return !_to ? NS_ERROR_NULL_POINTER : _to->GetText(result); } 

#if 0
/* Use the code below as a template for the implementation class for this interface. */

/* Header file */
class nsJVMPluginInstance : public nsIJVMPluginInstance
{
public:
  NS_DECL_ISUPPORTS
  NS_DECL_NSIJVMPLUGININSTANCE

  nsJVMPluginInstance();

private:
  ~nsJVMPluginInstance();

protected:
  /* additional members */
};

/* Implementation file */
NS_IMPL_ISUPPORTS1(nsJVMPluginInstance, nsIJVMPluginInstance)

nsJVMPluginInstance::nsJVMPluginInstance()
{
  /* member initializers and constructor code */
}

nsJVMPluginInstance::~nsJVMPluginInstance()
{
  /* destructor code */
}

/* [noscript] void GetJavaObject (out jobject result); */
NS_IMETHODIMP nsJVMPluginInstance::GetJavaObject(jobject *result NS_OUTPARAM)
{
    return NS_ERROR_NOT_IMPLEMENTED;
}

/* [noscript] void GetText (in nChar result); */
NS_IMETHODIMP nsJVMPluginInstance::GetText(const char ** result)
{
    return NS_ERROR_NOT_IMPLEMENTED;
}

/* End of implementation class template. */
#endif


#endif /* __gen_nsIJVMPluginInstance_h__ */
