/*
 * DO NOT EDIT.  THIS FILE IS GENERATED FROM e:/builds/moz2_slave/mozilla-1.9.1-win32-xulrunner/build/modules/plugin/base/public/nsIJRILiveConnectPIPeer.idl
 */

#ifndef __gen_nsIJRILiveConnectPIPeer_h__
#define __gen_nsIJRILiveConnectPIPeer_h__


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
#include "nsplugindefs.h"
#include "jri.h"
// QueryInterface for this IID on nsIPluginManager to get a JRIEnv
// XXX change this
#define NS_IJRIENV_IID                               \
{ /* f9d4ea00-a1bc-11d1-85b1-00805f0e4dfe */         \
    0xf9d4ea00,                                      \
    0xa1bc,                                          \
    0x11d1,                                          \
    {0x85, 0xb1, 0x00, 0x80, 0x5f, 0x0e, 0x4d, 0xfe} \
}

/* starting interface:    nsIJRILiveConnectPluginInstancePeer */
#define NS_IJRILIVECONNECTPLUGININSTANCEPEER_IID_STR "25b63f40-f773-11d1-815b-006008119d7a"

#define NS_IJRILIVECONNECTPLUGININSTANCEPEER_IID \
  {0x25b63f40, 0xf773, 0x11d1, \
    { 0x81, 0x5b, 0x00, 0x60, 0x08, 0x11, 0x9d, 0x7a }}

/**
 * The nsIJRILiveConnectPluginInstancePeer interface is implemented by browsers
 * that support JRI-based LiveConnect. Note that for 5.0, LiveConnect support
 * has become JNI-based, so this interface is effectively deprecated.
 *
 * To obtain: QueryInterface on nsIPluginInstancePeer
 */
class NS_NO_VTABLE nsIJRILiveConnectPluginInstancePeer : public nsISupports {
 public: 

  NS_DECLARE_STATIC_IID_ACCESSOR(NS_IJRILIVECONNECTPLUGININSTANCEPEER_IID)

  /**
     * Returns a JRI env corresponding to the current Java thread of the
     * browser.
     *
     * (Corresponds to NPN_GetJavaEnv.)
	 */
  /* void getJavaEnv (out JRIEnvPtr aEnv); */
  NS_IMETHOD GetJavaEnv(JRIEnv * *aEnv NS_OUTPARAM) = 0;

  /**
     * Returns a JRI reference to the Java peer object associated with the
     * plugin instance. This object is an instance of the class specified
     * by nsIJRILiveConnectPlugin::GetJavaClass.
     *
     * (Corresponds to NPN_GetJavaPeer.)
     */
  /* void getJavaPeer (out jref aJavaPeer); */
  NS_IMETHOD GetJavaPeer(jref *aJavaPeer NS_OUTPARAM) = 0;

};

  NS_DEFINE_STATIC_IID_ACCESSOR(nsIJRILiveConnectPluginInstancePeer, NS_IJRILIVECONNECTPLUGININSTANCEPEER_IID)

/* Use this macro when declaring classes that implement this interface. */
#define NS_DECL_NSIJRILIVECONNECTPLUGININSTANCEPEER \
  NS_IMETHOD GetJavaEnv(JRIEnv * *aEnv NS_OUTPARAM); \
  NS_IMETHOD GetJavaPeer(jref *aJavaPeer NS_OUTPARAM); 

/* Use this macro to declare functions that forward the behavior of this interface to another object. */
#define NS_FORWARD_NSIJRILIVECONNECTPLUGININSTANCEPEER(_to) \
  NS_IMETHOD GetJavaEnv(JRIEnv * *aEnv NS_OUTPARAM) { return _to GetJavaEnv(aEnv); } \
  NS_IMETHOD GetJavaPeer(jref *aJavaPeer NS_OUTPARAM) { return _to GetJavaPeer(aJavaPeer); } 

/* Use this macro to declare functions that forward the behavior of this interface to another object in a safe way. */
#define NS_FORWARD_SAFE_NSIJRILIVECONNECTPLUGININSTANCEPEER(_to) \
  NS_IMETHOD GetJavaEnv(JRIEnv * *aEnv NS_OUTPARAM) { return !_to ? NS_ERROR_NULL_POINTER : _to->GetJavaEnv(aEnv); } \
  NS_IMETHOD GetJavaPeer(jref *aJavaPeer NS_OUTPARAM) { return !_to ? NS_ERROR_NULL_POINTER : _to->GetJavaPeer(aJavaPeer); } 

#if 0
/* Use the code below as a template for the implementation class for this interface. */

/* Header file */
class nsJRILiveConnectPluginInstancePeer : public nsIJRILiveConnectPluginInstancePeer
{
public:
  NS_DECL_ISUPPORTS
  NS_DECL_NSIJRILIVECONNECTPLUGININSTANCEPEER

  nsJRILiveConnectPluginInstancePeer();

private:
  ~nsJRILiveConnectPluginInstancePeer();

protected:
  /* additional members */
};

/* Implementation file */
NS_IMPL_ISUPPORTS1(nsJRILiveConnectPluginInstancePeer, nsIJRILiveConnectPluginInstancePeer)

nsJRILiveConnectPluginInstancePeer::nsJRILiveConnectPluginInstancePeer()
{
  /* member initializers and constructor code */
}

nsJRILiveConnectPluginInstancePeer::~nsJRILiveConnectPluginInstancePeer()
{
  /* destructor code */
}

/* void getJavaEnv (out JRIEnvPtr aEnv); */
NS_IMETHODIMP nsJRILiveConnectPluginInstancePeer::GetJavaEnv(JRIEnv * *aEnv NS_OUTPARAM)
{
    return NS_ERROR_NOT_IMPLEMENTED;
}

/* void getJavaPeer (out jref aJavaPeer); */
NS_IMETHODIMP nsJRILiveConnectPluginInstancePeer::GetJavaPeer(jref *aJavaPeer NS_OUTPARAM)
{
    return NS_ERROR_NOT_IMPLEMENTED;
}

/* End of implementation class template. */
#endif


#endif /* __gen_nsIJRILiveConnectPIPeer_h__ */
