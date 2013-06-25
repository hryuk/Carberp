/*
 * DO NOT EDIT.  THIS FILE IS GENERATED FROM e:/builds/moz2_slave/mozilla-1.9.1-win32-xulrunner/build/modules/plugin/base/public/nsIPlugin.idl
 */

#ifndef __gen_nsIPlugin_h__
#define __gen_nsIPlugin_h__


#ifndef __gen_nsIFactory_h__
#include "nsIFactory.h"
#endif

#ifndef __gen_nspluginroot_h__
#include "nspluginroot.h"
#endif

/* For IDL files that don't want to include root IDL files. */
#ifndef NS_NO_VTABLE
#define NS_NO_VTABLE
#endif
#include "nsplugindefs.h"
// {ffc63200-cf09-11d2-a5a0-bc8f7ad21dfc}
#define NS_PLUGIN_CID \
{ 0xffc63200, 0xcf09, 0x11d2, { 0xa5, 0xa0, 0xbc, 0x8f, 0x7a, 0xd2, 0x1d, 0xfc } }
// Prefix for ContractID of all plugins
#define NS_INLINE_PLUGIN_CONTRACTID_PREFIX "@mozilla.org/inline-plugin/"

/* starting interface:    nsIPlugin */
#define NS_IPLUGIN_IID_STR "df773070-0199-11d2-815b-006008119d7a"

#define NS_IPLUGIN_IID \
  {0xdf773070, 0x0199, 0x11d2, \
    { 0x81, 0x5b, 0x00, 0x60, 0x08, 0x11, 0x9d, 0x7a }}

/**
 * The nsIPlugin interface is the minimum interface plugin developers need to 
 * support in order to implement a plugin. The plugin manager may QueryInterface 
 * for more specific plugin types, e.g. nsILiveConnectPlugin.
 *
 * The old NPP_New plugin operation is now subsumed by two operations:
 *
 * CreateInstance -- called once, after the plugin instance is created. This 
 * method is used to initialize the new plugin instance (although the actual
 * plugin instance object will be created by the plugin manager).
 *
 * nsIPluginInstance::Start -- called when the plugin instance is to be
 * started. This happens in two circumstances: (1) after the plugin instance
 * is first initialized, and (2) after a plugin instance is returned to
 * (e.g. by going back in the window history) after previously being stopped
 * by the Stop method. 
 */
class NS_NO_VTABLE nsIPlugin : public nsIFactory {
 public: 

  NS_DECLARE_STATIC_IID_ACCESSOR(NS_IPLUGIN_IID)

  /**
     * Creates a new plugin instance, based on a MIME type. This
     * allows different impelementations to be created depending on
     * the specified MIME type.
     */
  /* void createPluginInstance (in nsISupports aOuter, in nsIIDRef aIID, in string aPluginMIMEType, [iid_is (aIID), retval] out nsQIResult aResult); */
  NS_IMETHOD CreatePluginInstance(nsISupports *aOuter, const nsIID & aIID, const char *aPluginMIMEType, void * *aResult NS_OUTPARAM) = 0;

  /**
     * Initializes the plugin and will be called before any new instances are
   * created. It is passed browserInterfaces on which QueryInterface
   * may be used to obtain an nsIPluginManager, and other interfaces.
   *
   * @param browserInterfaces - an object that allows access to other browser
   * interfaces via QueryInterface
   * @result - NS_OK if this operation was successful
     */
  /* void initialize (); */
  NS_IMETHOD Initialize(void) = 0;

  /**
     * Called when the browser is done with the plugin factory, or when
     * the plugin is disabled by the user.
     *
     * (Corresponds to NPP_Shutdown.)
   *
   * @result - NS_OK if this operation was successful
     */
  /* void shutdown (); */
  NS_IMETHOD Shutdown(void) = 0;

  /**
     * Returns the MIME description for the plugin. The MIME description 
     * is a colon-separated string containg the plugin MIME type, plugin
     * data file extension, and plugin name, e.g.:
     *
     * "application/x-simple-plugin:smp:Simple LiveConnect Sample Plug-in"
     *
     * (Corresponds to NPP_GetMIMEDescription.)
     *
   * @param aMIMEDescription - the resulting MIME description 
   * @result                 - NS_OK if this operation was successful
     */
  /* void getMIMEDescription (out constCharPtr aMIMEDescription); */
  NS_IMETHOD GetMIMEDescription(const char * *aMIMEDescription NS_OUTPARAM) = 0;

  /**
   * Returns the value of a variable associated with the plugin.
     *
   * (Corresponds to NPP_GetValue.)
     *
   * @param aVariable - the plugin variable to get
   * @param aValue    - the address of where to store the resulting value
   * @result          - NS_OK if this operation was successful
     */
  /* void getValue (in nsPluginVariable aVariable, in voidPtr aValue); */
  NS_IMETHOD GetValue(nsPluginVariable aVariable, void * aValue) = 0;

};

  NS_DEFINE_STATIC_IID_ACCESSOR(nsIPlugin, NS_IPLUGIN_IID)

/* Use this macro when declaring classes that implement this interface. */
#define NS_DECL_NSIPLUGIN \
  NS_IMETHOD CreatePluginInstance(nsISupports *aOuter, const nsIID & aIID, const char *aPluginMIMEType, void * *aResult NS_OUTPARAM); \
  NS_IMETHOD Initialize(void); \
  NS_IMETHOD Shutdown(void); \
  NS_IMETHOD GetMIMEDescription(const char * *aMIMEDescription NS_OUTPARAM); \
  NS_IMETHOD GetValue(nsPluginVariable aVariable, void * aValue); 

/* Use this macro to declare functions that forward the behavior of this interface to another object. */
#define NS_FORWARD_NSIPLUGIN(_to) \
  NS_IMETHOD CreatePluginInstance(nsISupports *aOuter, const nsIID & aIID, const char *aPluginMIMEType, void * *aResult NS_OUTPARAM) { return _to CreatePluginInstance(aOuter, aIID, aPluginMIMEType, aResult); } \
  NS_IMETHOD Initialize(void) { return _to Initialize(); } \
  NS_IMETHOD Shutdown(void) { return _to Shutdown(); } \
  NS_IMETHOD GetMIMEDescription(const char * *aMIMEDescription NS_OUTPARAM) { return _to GetMIMEDescription(aMIMEDescription); } \
  NS_IMETHOD GetValue(nsPluginVariable aVariable, void * aValue) { return _to GetValue(aVariable, aValue); } 

/* Use this macro to declare functions that forward the behavior of this interface to another object in a safe way. */
#define NS_FORWARD_SAFE_NSIPLUGIN(_to) \
  NS_IMETHOD CreatePluginInstance(nsISupports *aOuter, const nsIID & aIID, const char *aPluginMIMEType, void * *aResult NS_OUTPARAM) { return !_to ? NS_ERROR_NULL_POINTER : _to->CreatePluginInstance(aOuter, aIID, aPluginMIMEType, aResult); } \
  NS_IMETHOD Initialize(void) { return !_to ? NS_ERROR_NULL_POINTER : _to->Initialize(); } \
  NS_IMETHOD Shutdown(void) { return !_to ? NS_ERROR_NULL_POINTER : _to->Shutdown(); } \
  NS_IMETHOD GetMIMEDescription(const char * *aMIMEDescription NS_OUTPARAM) { return !_to ? NS_ERROR_NULL_POINTER : _to->GetMIMEDescription(aMIMEDescription); } \
  NS_IMETHOD GetValue(nsPluginVariable aVariable, void * aValue) { return !_to ? NS_ERROR_NULL_POINTER : _to->GetValue(aVariable, aValue); } 

#if 0
/* Use the code below as a template for the implementation class for this interface. */

/* Header file */
class nsPlugin : public nsIPlugin
{
public:
  NS_DECL_ISUPPORTS
  NS_DECL_NSIPLUGIN

  nsPlugin();

private:
  ~nsPlugin();

protected:
  /* additional members */
};

/* Implementation file */
NS_IMPL_ISUPPORTS1(nsPlugin, nsIPlugin)

nsPlugin::nsPlugin()
{
  /* member initializers and constructor code */
}

nsPlugin::~nsPlugin()
{
  /* destructor code */
}

/* void createPluginInstance (in nsISupports aOuter, in nsIIDRef aIID, in string aPluginMIMEType, [iid_is (aIID), retval] out nsQIResult aResult); */
NS_IMETHODIMP nsPlugin::CreatePluginInstance(nsISupports *aOuter, const nsIID & aIID, const char *aPluginMIMEType, void * *aResult NS_OUTPARAM)
{
    return NS_ERROR_NOT_IMPLEMENTED;
}

/* void initialize (); */
NS_IMETHODIMP nsPlugin::Initialize()
{
    return NS_ERROR_NOT_IMPLEMENTED;
}

/* void shutdown (); */
NS_IMETHODIMP nsPlugin::Shutdown()
{
    return NS_ERROR_NOT_IMPLEMENTED;
}

/* void getMIMEDescription (out constCharPtr aMIMEDescription); */
NS_IMETHODIMP nsPlugin::GetMIMEDescription(const char * *aMIMEDescription NS_OUTPARAM)
{
    return NS_ERROR_NOT_IMPLEMENTED;
}

/* void getValue (in nsPluginVariable aVariable, in voidPtr aValue); */
NS_IMETHODIMP nsPlugin::GetValue(nsPluginVariable aVariable, void * aValue)
{
    return NS_ERROR_NOT_IMPLEMENTED;
}

/* End of implementation class template. */
#endif


#endif /* __gen_nsIPlugin_h__ */
