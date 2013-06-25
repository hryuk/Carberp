/*
 * DO NOT EDIT.  THIS FILE IS GENERATED FROM e:/builds/moz2_slave/mozilla-1.9.1-win32-xulrunner/build/modules/plugin/base/public/nsIScriptablePlugin.idl
 */

#ifndef __gen_nsIScriptablePlugin_h__
#define __gen_nsIScriptablePlugin_h__


#ifndef __gen_nsISupports_h__
#include "nsISupports.h"
#endif

/* For IDL files that don't want to include root IDL files. */
#ifndef NS_NO_VTABLE
#define NS_NO_VTABLE
#endif

/* starting interface:    nsIScriptablePlugin */
#define NS_ISCRIPTABLEPLUGIN_IID_STR "f1a12bba-1dd1-11b2-a95f-cdc118605e92"

#define NS_ISCRIPTABLEPLUGIN_IID \
  {0xf1a12bba, 0x1dd1, 0x11b2, \
    { 0xa9, 0x5f, 0xcd, 0xc1, 0x18, 0x60, 0x5e, 0x92 }}

class NS_NO_VTABLE nsIScriptablePlugin : public nsISupports {
 public: 

  NS_DECLARE_STATIC_IID_ACCESSOR(NS_ISCRIPTABLEPLUGIN_IID)

  /**
     * The object to be wrapped and exposed to JavaScript.  It should
     * be an XPCOM object, and it can be the same object as the plugin.
     */
  /* readonly attribute nsQIResult scriptablePeer; */
  NS_IMETHOD GetScriptablePeer(void * *aScriptablePeer) = 0;

  /**
     * The interface that XPConnect should use when exposing the peer
     * object to JavaScript.  All scriptable methods on the interface
     * will be available to JavaScript.
     */
  /* readonly attribute nsIIDPtr scriptableInterface; */
  NS_IMETHOD GetScriptableInterface(nsIID * *aScriptableInterface) = 0;

};

  NS_DEFINE_STATIC_IID_ACCESSOR(nsIScriptablePlugin, NS_ISCRIPTABLEPLUGIN_IID)

/* Use this macro when declaring classes that implement this interface. */
#define NS_DECL_NSISCRIPTABLEPLUGIN \
  NS_IMETHOD GetScriptablePeer(void * *aScriptablePeer); \
  NS_IMETHOD GetScriptableInterface(nsIID * *aScriptableInterface); 

/* Use this macro to declare functions that forward the behavior of this interface to another object. */
#define NS_FORWARD_NSISCRIPTABLEPLUGIN(_to) \
  NS_IMETHOD GetScriptablePeer(void * *aScriptablePeer) { return _to GetScriptablePeer(aScriptablePeer); } \
  NS_IMETHOD GetScriptableInterface(nsIID * *aScriptableInterface) { return _to GetScriptableInterface(aScriptableInterface); } 

/* Use this macro to declare functions that forward the behavior of this interface to another object in a safe way. */
#define NS_FORWARD_SAFE_NSISCRIPTABLEPLUGIN(_to) \
  NS_IMETHOD GetScriptablePeer(void * *aScriptablePeer) { return !_to ? NS_ERROR_NULL_POINTER : _to->GetScriptablePeer(aScriptablePeer); } \
  NS_IMETHOD GetScriptableInterface(nsIID * *aScriptableInterface) { return !_to ? NS_ERROR_NULL_POINTER : _to->GetScriptableInterface(aScriptableInterface); } 

#if 0
/* Use the code below as a template for the implementation class for this interface. */

/* Header file */
class nsScriptablePlugin : public nsIScriptablePlugin
{
public:
  NS_DECL_ISUPPORTS
  NS_DECL_NSISCRIPTABLEPLUGIN

  nsScriptablePlugin();

private:
  ~nsScriptablePlugin();

protected:
  /* additional members */
};

/* Implementation file */
NS_IMPL_ISUPPORTS1(nsScriptablePlugin, nsIScriptablePlugin)

nsScriptablePlugin::nsScriptablePlugin()
{
  /* member initializers and constructor code */
}

nsScriptablePlugin::~nsScriptablePlugin()
{
  /* destructor code */
}

/* readonly attribute nsQIResult scriptablePeer; */
NS_IMETHODIMP nsScriptablePlugin::GetScriptablePeer(void * *aScriptablePeer)
{
    return NS_ERROR_NOT_IMPLEMENTED;
}

/* readonly attribute nsIIDPtr scriptableInterface; */
NS_IMETHODIMP nsScriptablePlugin::GetScriptableInterface(nsIID * *aScriptableInterface)
{
    return NS_ERROR_NOT_IMPLEMENTED;
}

/* End of implementation class template. */
#endif


#endif /* __gen_nsIScriptablePlugin_h__ */
