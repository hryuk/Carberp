/*
 * DO NOT EDIT.  THIS FILE IS GENERATED FROM e:/builds/moz2_slave/mozilla-1.9.1-win32-xulrunner/build/modules/plugin/base/public/nsIPluginHost.idl
 */

#ifndef __gen_nsIPluginHost_h__
#define __gen_nsIPluginHost_h__


#ifndef __gen_nspluginroot_h__
#include "nspluginroot.h"
#endif

#ifndef __gen_nsIFactory_h__
#include "nsIFactory.h"
#endif

#ifndef __gen_nsIPluginInstanceOwner_h__
#include "nsIPluginInstanceOwner.h"
#endif

#ifndef __gen_nsIStreamListener_h__
#include "nsIStreamListener.h"
#endif

#ifndef __gen_nsIStringStream_h__
#include "nsIStringStream.h"
#endif

#ifndef __gen_nsIPluginTag_h__
#include "nsIPluginTag.h"
#endif

/* For IDL files that don't want to include root IDL files. */
#ifndef NS_NO_VTABLE
#define NS_NO_VTABLE
#endif
#include "nsplugindefs.h"
#ifdef MOZILLA_INTERNAL_API
#include "nsString.h"
#include "nsNetUtil.h"
#endif
#include "prlink.h"  // for PRLibrary
class nsIPlugin; /* forward declaration */

class nsIURI; /* forward declaration */

class nsIDOMPlugin; /* forward declaration */

class nsIChannel; /* forward declaration */


/* starting interface:    nsIPluginHost */
#define NS_IPLUGINHOST_IID_STR "2af1c32d-38dd-4f72-b0ab-24697d836e61"

#define NS_IPLUGINHOST_IID \
  {0x2af1c32d, 0x38dd, 0x4f72, \
    { 0xb0, 0xab, 0x24, 0x69, 0x7d, 0x83, 0x6e, 0x61 }}

class NS_NO_VTABLE NS_SCRIPTABLE nsIPluginHost : public nsIFactory {
 public: 

  NS_DECLARE_STATIC_IID_ACCESSOR(NS_IPLUGINHOST_IID)

  /* [noscript] void init (); */
  NS_IMETHOD Init(void) = 0;

  /* [noscript] void destroy (); */
  NS_IMETHOD Destroy(void) = 0;

  /* [noscript] void loadPlugins (); */
  NS_IMETHOD LoadPlugins(void) = 0;

  /* [noscript] nsIPlugin getPluginFactory (in string aMimeType); */
  NS_IMETHOD GetPluginFactory(const char *aMimeType, nsIPlugin **_retval NS_OUTPARAM) = 0;

  /* [noscript] void instantiateEmbeddedPlugin (in string aMimeType, in nsIURI aURL, in nsIPluginInstanceOwner aOwner); */
  NS_IMETHOD InstantiateEmbeddedPlugin(const char *aMimeType, nsIURI *aURL, nsIPluginInstanceOwner *aOwner) = 0;

  /* [noscript] void instantiateFullPagePlugin (in string aMimeType, in nsIURI aURI, in nsIStreamListenerRef aStreamListener, in nsIPluginInstanceOwner aOwner); */
  NS_IMETHOD InstantiateFullPagePlugin(const char *aMimeType, nsIURI *aURI, nsIStreamListener * & aStreamListener, nsIPluginInstanceOwner *aOwner) = 0;

  /**
   * Instantiate an embedded plugin for an existing channel. The caller is
   * responsible for opening the channel. It may or may not be already opened
   * when this function is called.
   */
  /* [noscript] nsIStreamListener instantiatePluginForChannel (in nsIChannel aChannel, in nsIPluginInstanceOwner aOwner); */
  NS_IMETHOD InstantiatePluginForChannel(nsIChannel *aChannel, nsIPluginInstanceOwner *aOwner, nsIStreamListener **_retval NS_OUTPARAM) = 0;

  /* [noscript] void setUpPluginInstance (in string aMimeType, in nsIURI aURL, in nsIPluginInstanceOwner aOwner); */
  NS_IMETHOD SetUpPluginInstance(const char *aMimeType, nsIURI *aURL, nsIPluginInstanceOwner *aOwner) = 0;

  /* [noscript] void isPluginEnabledForType (in string aMimeType); */
  NS_IMETHOD IsPluginEnabledForType(const char *aMimeType) = 0;

  /* [noscript] void isPluginEnabledForExtension (in string aExtension, in constCharStarRef aMimeType); */
  NS_IMETHOD IsPluginEnabledForExtension(const char *aExtension, const char * & aMimeType) = 0;

  /* [noscript] readonly attribute unsigned long pluginCount; */
  NS_IMETHOD GetPluginCount(PRUint32 *aPluginCount) = 0;

  /* [noscript] void getPlugins (in unsigned long aPluginCount, out nsIDOMPlugin aPluginArray); */
  NS_IMETHOD GetPlugins(PRUint32 aPluginCount, nsIDOMPlugin **aPluginArray NS_OUTPARAM) = 0;

  /* void getPluginTags (out unsigned long aPluginCount, [array, size_is (aPluginCount), retval] out nsIPluginTag aResults); */
  NS_SCRIPTABLE NS_IMETHOD GetPluginTags(PRUint32 *aPluginCount NS_OUTPARAM, nsIPluginTag ***aResults NS_OUTPARAM) = 0;

  /* [noscript] void stopPluginInstance (in nsIPluginInstance aInstance); */
  NS_IMETHOD StopPluginInstance(nsIPluginInstance *aInstance) = 0;

  /* [noscript] void handleBadPlugin (in PRLibraryPtr aLibrary, in nsIPluginInstance instance); */
  NS_IMETHOD HandleBadPlugin(PRLibrary * aLibrary, nsIPluginInstance *instance) = 0;

};

  NS_DEFINE_STATIC_IID_ACCESSOR(nsIPluginHost, NS_IPLUGINHOST_IID)

/* Use this macro when declaring classes that implement this interface. */
#define NS_DECL_NSIPLUGINHOST \
  NS_IMETHOD Init(void); \
  NS_IMETHOD Destroy(void); \
  NS_IMETHOD LoadPlugins(void); \
  NS_IMETHOD GetPluginFactory(const char *aMimeType, nsIPlugin **_retval NS_OUTPARAM); \
  NS_IMETHOD InstantiateEmbeddedPlugin(const char *aMimeType, nsIURI *aURL, nsIPluginInstanceOwner *aOwner); \
  NS_IMETHOD InstantiateFullPagePlugin(const char *aMimeType, nsIURI *aURI, nsIStreamListener * & aStreamListener, nsIPluginInstanceOwner *aOwner); \
  NS_IMETHOD InstantiatePluginForChannel(nsIChannel *aChannel, nsIPluginInstanceOwner *aOwner, nsIStreamListener **_retval NS_OUTPARAM); \
  NS_IMETHOD SetUpPluginInstance(const char *aMimeType, nsIURI *aURL, nsIPluginInstanceOwner *aOwner); \
  NS_IMETHOD IsPluginEnabledForType(const char *aMimeType); \
  NS_IMETHOD IsPluginEnabledForExtension(const char *aExtension, const char * & aMimeType); \
  NS_IMETHOD GetPluginCount(PRUint32 *aPluginCount); \
  NS_IMETHOD GetPlugins(PRUint32 aPluginCount, nsIDOMPlugin **aPluginArray NS_OUTPARAM); \
  NS_SCRIPTABLE NS_IMETHOD GetPluginTags(PRUint32 *aPluginCount NS_OUTPARAM, nsIPluginTag ***aResults NS_OUTPARAM); \
  NS_IMETHOD StopPluginInstance(nsIPluginInstance *aInstance); \
  NS_IMETHOD HandleBadPlugin(PRLibrary * aLibrary, nsIPluginInstance *instance); 

/* Use this macro to declare functions that forward the behavior of this interface to another object. */
#define NS_FORWARD_NSIPLUGINHOST(_to) \
  NS_IMETHOD Init(void) { return _to Init(); } \
  NS_IMETHOD Destroy(void) { return _to Destroy(); } \
  NS_IMETHOD LoadPlugins(void) { return _to LoadPlugins(); } \
  NS_IMETHOD GetPluginFactory(const char *aMimeType, nsIPlugin **_retval NS_OUTPARAM) { return _to GetPluginFactory(aMimeType, _retval); } \
  NS_IMETHOD InstantiateEmbeddedPlugin(const char *aMimeType, nsIURI *aURL, nsIPluginInstanceOwner *aOwner) { return _to InstantiateEmbeddedPlugin(aMimeType, aURL, aOwner); } \
  NS_IMETHOD InstantiateFullPagePlugin(const char *aMimeType, nsIURI *aURI, nsIStreamListener * & aStreamListener, nsIPluginInstanceOwner *aOwner) { return _to InstantiateFullPagePlugin(aMimeType, aURI, aStreamListener, aOwner); } \
  NS_IMETHOD InstantiatePluginForChannel(nsIChannel *aChannel, nsIPluginInstanceOwner *aOwner, nsIStreamListener **_retval NS_OUTPARAM) { return _to InstantiatePluginForChannel(aChannel, aOwner, _retval); } \
  NS_IMETHOD SetUpPluginInstance(const char *aMimeType, nsIURI *aURL, nsIPluginInstanceOwner *aOwner) { return _to SetUpPluginInstance(aMimeType, aURL, aOwner); } \
  NS_IMETHOD IsPluginEnabledForType(const char *aMimeType) { return _to IsPluginEnabledForType(aMimeType); } \
  NS_IMETHOD IsPluginEnabledForExtension(const char *aExtension, const char * & aMimeType) { return _to IsPluginEnabledForExtension(aExtension, aMimeType); } \
  NS_IMETHOD GetPluginCount(PRUint32 *aPluginCount) { return _to GetPluginCount(aPluginCount); } \
  NS_IMETHOD GetPlugins(PRUint32 aPluginCount, nsIDOMPlugin **aPluginArray NS_OUTPARAM) { return _to GetPlugins(aPluginCount, aPluginArray); } \
  NS_SCRIPTABLE NS_IMETHOD GetPluginTags(PRUint32 *aPluginCount NS_OUTPARAM, nsIPluginTag ***aResults NS_OUTPARAM) { return _to GetPluginTags(aPluginCount, aResults); } \
  NS_IMETHOD StopPluginInstance(nsIPluginInstance *aInstance) { return _to StopPluginInstance(aInstance); } \
  NS_IMETHOD HandleBadPlugin(PRLibrary * aLibrary, nsIPluginInstance *instance) { return _to HandleBadPlugin(aLibrary, instance); } 

/* Use this macro to declare functions that forward the behavior of this interface to another object in a safe way. */
#define NS_FORWARD_SAFE_NSIPLUGINHOST(_to) \
  NS_IMETHOD Init(void) { return !_to ? NS_ERROR_NULL_POINTER : _to->Init(); } \
  NS_IMETHOD Destroy(void) { return !_to ? NS_ERROR_NULL_POINTER : _to->Destroy(); } \
  NS_IMETHOD LoadPlugins(void) { return !_to ? NS_ERROR_NULL_POINTER : _to->LoadPlugins(); } \
  NS_IMETHOD GetPluginFactory(const char *aMimeType, nsIPlugin **_retval NS_OUTPARAM) { return !_to ? NS_ERROR_NULL_POINTER : _to->GetPluginFactory(aMimeType, _retval); } \
  NS_IMETHOD InstantiateEmbeddedPlugin(const char *aMimeType, nsIURI *aURL, nsIPluginInstanceOwner *aOwner) { return !_to ? NS_ERROR_NULL_POINTER : _to->InstantiateEmbeddedPlugin(aMimeType, aURL, aOwner); } \
  NS_IMETHOD InstantiateFullPagePlugin(const char *aMimeType, nsIURI *aURI, nsIStreamListener * & aStreamListener, nsIPluginInstanceOwner *aOwner) { return !_to ? NS_ERROR_NULL_POINTER : _to->InstantiateFullPagePlugin(aMimeType, aURI, aStreamListener, aOwner); } \
  NS_IMETHOD InstantiatePluginForChannel(nsIChannel *aChannel, nsIPluginInstanceOwner *aOwner, nsIStreamListener **_retval NS_OUTPARAM) { return !_to ? NS_ERROR_NULL_POINTER : _to->InstantiatePluginForChannel(aChannel, aOwner, _retval); } \
  NS_IMETHOD SetUpPluginInstance(const char *aMimeType, nsIURI *aURL, nsIPluginInstanceOwner *aOwner) { return !_to ? NS_ERROR_NULL_POINTER : _to->SetUpPluginInstance(aMimeType, aURL, aOwner); } \
  NS_IMETHOD IsPluginEnabledForType(const char *aMimeType) { return !_to ? NS_ERROR_NULL_POINTER : _to->IsPluginEnabledForType(aMimeType); } \
  NS_IMETHOD IsPluginEnabledForExtension(const char *aExtension, const char * & aMimeType) { return !_to ? NS_ERROR_NULL_POINTER : _to->IsPluginEnabledForExtension(aExtension, aMimeType); } \
  NS_IMETHOD GetPluginCount(PRUint32 *aPluginCount) { return !_to ? NS_ERROR_NULL_POINTER : _to->GetPluginCount(aPluginCount); } \
  NS_IMETHOD GetPlugins(PRUint32 aPluginCount, nsIDOMPlugin **aPluginArray NS_OUTPARAM) { return !_to ? NS_ERROR_NULL_POINTER : _to->GetPlugins(aPluginCount, aPluginArray); } \
  NS_SCRIPTABLE NS_IMETHOD GetPluginTags(PRUint32 *aPluginCount NS_OUTPARAM, nsIPluginTag ***aResults NS_OUTPARAM) { return !_to ? NS_ERROR_NULL_POINTER : _to->GetPluginTags(aPluginCount, aResults); } \
  NS_IMETHOD StopPluginInstance(nsIPluginInstance *aInstance) { return !_to ? NS_ERROR_NULL_POINTER : _to->StopPluginInstance(aInstance); } \
  NS_IMETHOD HandleBadPlugin(PRLibrary * aLibrary, nsIPluginInstance *instance) { return !_to ? NS_ERROR_NULL_POINTER : _to->HandleBadPlugin(aLibrary, instance); } 

#if 0
/* Use the code below as a template for the implementation class for this interface. */

/* Header file */
class nsPluginHost : public nsIPluginHost
{
public:
  NS_DECL_ISUPPORTS
  NS_DECL_NSIPLUGINHOST

  nsPluginHost();

private:
  ~nsPluginHost();

protected:
  /* additional members */
};

/* Implementation file */
NS_IMPL_ISUPPORTS1(nsPluginHost, nsIPluginHost)

nsPluginHost::nsPluginHost()
{
  /* member initializers and constructor code */
}

nsPluginHost::~nsPluginHost()
{
  /* destructor code */
}

/* [noscript] void init (); */
NS_IMETHODIMP nsPluginHost::Init()
{
    return NS_ERROR_NOT_IMPLEMENTED;
}

/* [noscript] void destroy (); */
NS_IMETHODIMP nsPluginHost::Destroy()
{
    return NS_ERROR_NOT_IMPLEMENTED;
}

/* [noscript] void loadPlugins (); */
NS_IMETHODIMP nsPluginHost::LoadPlugins()
{
    return NS_ERROR_NOT_IMPLEMENTED;
}

/* [noscript] nsIPlugin getPluginFactory (in string aMimeType); */
NS_IMETHODIMP nsPluginHost::GetPluginFactory(const char *aMimeType, nsIPlugin **_retval NS_OUTPARAM)
{
    return NS_ERROR_NOT_IMPLEMENTED;
}

/* [noscript] void instantiateEmbeddedPlugin (in string aMimeType, in nsIURI aURL, in nsIPluginInstanceOwner aOwner); */
NS_IMETHODIMP nsPluginHost::InstantiateEmbeddedPlugin(const char *aMimeType, nsIURI *aURL, nsIPluginInstanceOwner *aOwner)
{
    return NS_ERROR_NOT_IMPLEMENTED;
}

/* [noscript] void instantiateFullPagePlugin (in string aMimeType, in nsIURI aURI, in nsIStreamListenerRef aStreamListener, in nsIPluginInstanceOwner aOwner); */
NS_IMETHODIMP nsPluginHost::InstantiateFullPagePlugin(const char *aMimeType, nsIURI *aURI, nsIStreamListener * & aStreamListener, nsIPluginInstanceOwner *aOwner)
{
    return NS_ERROR_NOT_IMPLEMENTED;
}

/* [noscript] nsIStreamListener instantiatePluginForChannel (in nsIChannel aChannel, in nsIPluginInstanceOwner aOwner); */
NS_IMETHODIMP nsPluginHost::InstantiatePluginForChannel(nsIChannel *aChannel, nsIPluginInstanceOwner *aOwner, nsIStreamListener **_retval NS_OUTPARAM)
{
    return NS_ERROR_NOT_IMPLEMENTED;
}

/* [noscript] void setUpPluginInstance (in string aMimeType, in nsIURI aURL, in nsIPluginInstanceOwner aOwner); */
NS_IMETHODIMP nsPluginHost::SetUpPluginInstance(const char *aMimeType, nsIURI *aURL, nsIPluginInstanceOwner *aOwner)
{
    return NS_ERROR_NOT_IMPLEMENTED;
}

/* [noscript] void isPluginEnabledForType (in string aMimeType); */
NS_IMETHODIMP nsPluginHost::IsPluginEnabledForType(const char *aMimeType)
{
    return NS_ERROR_NOT_IMPLEMENTED;
}

/* [noscript] void isPluginEnabledForExtension (in string aExtension, in constCharStarRef aMimeType); */
NS_IMETHODIMP nsPluginHost::IsPluginEnabledForExtension(const char *aExtension, const char * & aMimeType)
{
    return NS_ERROR_NOT_IMPLEMENTED;
}

/* [noscript] readonly attribute unsigned long pluginCount; */
NS_IMETHODIMP nsPluginHost::GetPluginCount(PRUint32 *aPluginCount)
{
    return NS_ERROR_NOT_IMPLEMENTED;
}

/* [noscript] void getPlugins (in unsigned long aPluginCount, out nsIDOMPlugin aPluginArray); */
NS_IMETHODIMP nsPluginHost::GetPlugins(PRUint32 aPluginCount, nsIDOMPlugin **aPluginArray NS_OUTPARAM)
{
    return NS_ERROR_NOT_IMPLEMENTED;
}

/* void getPluginTags (out unsigned long aPluginCount, [array, size_is (aPluginCount), retval] out nsIPluginTag aResults); */
NS_IMETHODIMP nsPluginHost::GetPluginTags(PRUint32 *aPluginCount NS_OUTPARAM, nsIPluginTag ***aResults NS_OUTPARAM)
{
    return NS_ERROR_NOT_IMPLEMENTED;
}

/* [noscript] void stopPluginInstance (in nsIPluginInstance aInstance); */
NS_IMETHODIMP nsPluginHost::StopPluginInstance(nsIPluginInstance *aInstance)
{
    return NS_ERROR_NOT_IMPLEMENTED;
}

/* [noscript] void handleBadPlugin (in PRLibraryPtr aLibrary, in nsIPluginInstance instance); */
NS_IMETHODIMP nsPluginHost::HandleBadPlugin(PRLibrary * aLibrary, nsIPluginInstance *instance)
{
    return NS_ERROR_NOT_IMPLEMENTED;
}

/* End of implementation class template. */
#endif

#ifdef MOZILLA_INTERNAL_API
/**
 * Used for creating the correct input stream for plugins
 * We can either have raw data (with or without \r\n\r\n) or a path to a file (but it must be native!)
 * When making an nsIInputStream stream for the plugins POST data, be sure to take into 
 * account that it could be binary and full of nulls, see bug 105417. Also, we need 
 * to make a copy of the buffer because the plugin may have allocated it on the stack.
 * For an example of this, see Shockwave registration or bug 108966
 * We malloc only for headers here, buffer for data itself is malloced by ParsePostBufferToFixHeaders()
 */
inline nsresult
NS_NewPluginPostDataStream(nsIInputStream **result,
                           const char *data,
                           PRUint32 contentLength,
                           PRBool isFile = PR_FALSE,
                           PRBool headers = PR_FALSE)
{
  nsresult rv = NS_ERROR_UNEXPECTED;
  if (!data)
    return rv;
  if (!isFile) { // do raw data case first
    if (contentLength < 1)
      return rv;
    
    char *buf = (char*) data;
    if (headers) {
      // in assumption we got correctly formated headers just passed in
      if (!(buf = (char*)nsMemory::Alloc(contentLength)))
        return NS_ERROR_OUT_OF_MEMORY;
      memcpy(buf, data, contentLength);
    }
    nsCOMPtr<nsIStringInputStream> sis = do_CreateInstance("@mozilla.org/io/string-input-stream;1",&rv);
    if (NS_SUCCEEDED(rv)) {
      sis->AdoptData(buf, contentLength);  // let the string stream manage our data
      rv = CallQueryInterface(sis, result);
    }
    else if (headers)
      nsMemory::Free(buf); // Cleanup the memory if the data was copied.
  } else {
    nsCOMPtr<nsILocalFile> file; // tmp file will be deleted on release of stream
    nsCOMPtr<nsIInputStream> fileStream;
    if (NS_SUCCEEDED(rv = NS_NewNativeLocalFile(nsDependentCString(data), PR_FALSE, getter_AddRefs(file))) &&
        NS_SUCCEEDED(rv = NS_NewLocalFileInputStream(getter_AddRefs(fileStream),
                                     file,
                                     PR_RDONLY,
                                     0600,
                                     nsIFileInputStream::DELETE_ON_CLOSE |
                                     nsIFileInputStream::CLOSE_ON_EOF))
                                     ) 
    {
      // wrap the file stream with a buffered input stream
      return NS_NewBufferedInputStream(result, fileStream, 8192);
    }
  }
  return rv;
}
#endif

#endif /* __gen_nsIPluginHost_h__ */
