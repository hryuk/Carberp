/*
 * DO NOT EDIT.  THIS FILE IS GENERATED FROM e:/builds/moz2_slave/mozilla-1.9.1-win32-xulrunner/build/modules/plugin/base/public/nsIJRILiveConnectPlugin.idl
 */

#ifndef __gen_nsIJRILiveConnectPlugin_h__
#define __gen_nsIJRILiveConnectPlugin_h__


#ifndef __gen_nsISupports_h__
#include "nsISupports.h"
#endif

#ifndef __gen_nspluginroot_h__
#include "nspluginroot.h"
#endif

/* For IDL files that don't want to include root IDL files. */
#ifndef NS_NO_VTABLE
#define NS_NO_VTABLE
#endif
#include "jri.h"

/* starting interface:    nsIJRILiveConnectPlugin */
#define NS_IJRILIVECONNECTPLUGIN_IID_STR "c94058e0-f772-11d1-815b-006008119d7a"

#define NS_IJRILIVECONNECTPLUGIN_IID \
  {0xc94058e0, 0xf772, 0x11d1, \
    { 0x81, 0x5b, 0x00, 0x60, 0x08, 0x11, 0x9d, 0x7a }}

/** 
 * The nsIJRILiveConnectPlugin interface defines additional entry points that a
 * plugin developer needs to implement in order for the plugin to support 
 * JRI-based LiveConnect, as opposed to the standard JNI-based LiveConnect
 * (which new in 5.0).
 *
 * Plugin developers requiring this capability should implement this interface
 * in addition to the basic nsIPlugin interface.
 */
class NS_NO_VTABLE nsIJRILiveConnectPlugin : public nsISupports {
 public: 

  NS_DECLARE_STATIC_IID_ACCESSOR(NS_IJRILIVECONNECTPLUGIN_IID)

  /**
     * Returns the class of the Java instance to be associated with the
     * plugin.
     *
   * (New JNI-based entry point, roughly corresponds to NPP_GetJavaClass.)
     *
   * @param aJavaClass - a resulting reference to the Java class
   * @result           - NS_OK if this operation was successful
     */
  /* void getJavaClass (in JRIEnvPtr aEnv, out jref aJavaClass); */
  NS_IMETHOD GetJavaClass(JRIEnv * aEnv, jref *aJavaClass NS_OUTPARAM) = 0;

};

  NS_DEFINE_STATIC_IID_ACCESSOR(nsIJRILiveConnectPlugin, NS_IJRILIVECONNECTPLUGIN_IID)

/* Use this macro when declaring classes that implement this interface. */
#define NS_DECL_NSIJRILIVECONNECTPLUGIN \
  NS_IMETHOD GetJavaClass(JRIEnv * aEnv, jref *aJavaClass NS_OUTPARAM); 

/* Use this macro to declare functions that forward the behavior of this interface to another object. */
#define NS_FORWARD_NSIJRILIVECONNECTPLUGIN(_to) \
  NS_IMETHOD GetJavaClass(JRIEnv * aEnv, jref *aJavaClass NS_OUTPARAM) { return _to GetJavaClass(aEnv, aJavaClass); } 

/* Use this macro to declare functions that forward the behavior of this interface to another object in a safe way. */
#define NS_FORWARD_SAFE_NSIJRILIVECONNECTPLUGIN(_to) \
  NS_IMETHOD GetJavaClass(JRIEnv * aEnv, jref *aJavaClass NS_OUTPARAM) { return !_to ? NS_ERROR_NULL_POINTER : _to->GetJavaClass(aEnv, aJavaClass); } 

#if 0
/* Use the code below as a template for the implementation class for this interface. */

/* Header file */
class nsJRILiveConnectPlugin : public nsIJRILiveConnectPlugin
{
public:
  NS_DECL_ISUPPORTS
  NS_DECL_NSIJRILIVECONNECTPLUGIN

  nsJRILiveConnectPlugin();

private:
  ~nsJRILiveConnectPlugin();

protected:
  /* additional members */
};

/* Implementation file */
NS_IMPL_ISUPPORTS1(nsJRILiveConnectPlugin, nsIJRILiveConnectPlugin)

nsJRILiveConnectPlugin::nsJRILiveConnectPlugin()
{
  /* member initializers and constructor code */
}

nsJRILiveConnectPlugin::~nsJRILiveConnectPlugin()
{
  /* destructor code */
}

/* void getJavaClass (in JRIEnvPtr aEnv, out jref aJavaClass); */
NS_IMETHODIMP nsJRILiveConnectPlugin::GetJavaClass(JRIEnv * aEnv, jref *aJavaClass NS_OUTPARAM)
{
    return NS_ERROR_NOT_IMPLEMENTED;
}

/* End of implementation class template. */
#endif


#endif /* __gen_nsIJRILiveConnectPlugin_h__ */
