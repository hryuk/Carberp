/*
 * DO NOT EDIT.  THIS FILE IS GENERATED FROM e:/builds/moz2_slave/mozilla-1.9.1-win32-xulrunner/build/modules/plugin/base/public/nsPIPluginHost.idl
 */

#ifndef __gen_nsPIPluginHost_h__
#define __gen_nsPIPluginHost_h__


#ifndef __gen_nsISupports_h__
#include "nsISupports.h"
#endif

#ifndef __gen_nsIPluginInstance_h__
#include "nsIPluginInstance.h"
#endif

/* For IDL files that don't want to include root IDL files. */
#ifndef NS_NO_VTABLE
#define NS_NO_VTABLE
#endif
#include "nsPluginNativeWindow.h"
class nsIPluginInstanceOwner; /* forward declaration */


/* starting interface:    nsPIPluginHost */
#define NS_PIPLUGINHOST_IID_STR "673811fb-83d6-4b8f-b1a9-bb3a9033f256"

#define NS_PIPLUGINHOST_IID \
  {0x673811fb, 0x83d6, 0x4b8f, \
    { 0xb1, 0xa9, 0xbb, 0x3a, 0x90, 0x33, 0xf2, 0x56 }}

class NS_NO_VTABLE nsPIPluginHost : public nsISupports {
 public: 

  NS_DECLARE_STATIC_IID_ACCESSOR(NS_PIPLUGINHOST_IID)

  /**
  * To notify the plugin manager that the plugin created a script object 
  */
  /* void setIsScriptableInstance (in nsIPluginInstance aInstance, in boolean aScriptable); */
  NS_IMETHOD SetIsScriptableInstance(nsIPluginInstance *aInstance, PRBool aScriptable) = 0;

  /**
  * This method parses post buffer to find out case insensitive "Content-length" string
  * and CR or LF some where after that, then it assumes there is http headers in
  * the input buffer and continue to search for end of headers (CRLFCRLF or LFLF).
  * It will *always malloc()* output buffer (caller is responsible to free it) 
  * if input buffer starts with LF, which comes from 4.x spec 
  * http://developer.netscape.com/docs/manuals/communicator/plugin/pgfn2.htm#1007754
  * "If no custom headers are required, simply add a blank
  * line ('\n') to the beginning of the file or buffer.",
  * it skips that '\n' and considers rest of the input buffer as data.
  * If "Content-length" string and end of headers is found 
  *   it substitutes single LF with CRLF in the headers, so the end of headers
  *   always will be CRLFCRLF (single CR in headers, if any, remain untouched)
  * else
  *   it puts "Content-length: "+size_of_data+CRLFCRLF at the beginning of the output buffer
  * and memcpy data to the output buffer 
  *
  * On failure outPostData and outPostDataLen will be set in 0.  
  * @param aInPostData      - the post data
  * @param aInPostDataLen   - the length aInPostData
  * @param aOutPostData     - the buffer
  * @param aOutPostDataLen  - the length of aOutPostData
  **/
  /* void parsePostBufferToFixHeaders (in string aInPostData, in unsigned long aInPostDataLen, out string aOutPostData, out unsigned long aOutPostDataLen); */
  NS_IMETHOD ParsePostBufferToFixHeaders(const char *aInPostData, PRUint32 aInPostDataLen, char **aOutPostData NS_OUTPARAM, PRUint32 *aOutPostDataLen NS_OUTPARAM) = 0;

  /**
  * To create tmp file with Content len header in, it will use by http POST
  */
  /* void createTmpFileToPost (in string aPostDataURL, out string aTmpFileName); */
  NS_IMETHOD CreateTmpFileToPost(const char *aPostDataURL, char **aTmpFileName NS_OUTPARAM) = 0;

  /**
  *  Creates a new plugin native window object
  */
  /* void newPluginNativeWindow (out nsPluginNativeWindowPtr aPluginNativeWindow); */
  NS_IMETHOD NewPluginNativeWindow(nsPluginNativeWindow * *aPluginNativeWindow NS_OUTPARAM) = 0;

  /**
  *  Deletes plugin native window object created by NewPluginNativeWindow
  */
  /* void deletePluginNativeWindow (in nsPluginNativeWindowPtr aPluginNativeWindow); */
  NS_IMETHOD DeletePluginNativeWindow(nsPluginNativeWindow * aPluginNativeWindow) = 0;

  /**
   * Instantiate a "dummy" java plugin if a java plugin that supports
   * NPRuntime is installed. This plugin is used for exposing
   * window.java and window.Packages. If the java plugin supports
   * NPRuntime and instantiation was successful, aOwners instance will
   * be non-null, if not, it will be null.
   */
  /* [noscript] void instantiateDummyJavaPlugin (in nsIPluginInstanceOwner aOwner); */
  NS_IMETHOD InstantiateDummyJavaPlugin(nsIPluginInstanceOwner *aOwner) = 0;

  /**
  * Get the plugin name for the plugin instance.
  * @param aInstance the plugin instance object
  * @param aPluginName returns a pointer to a shared readonly string value,
  *        it's only valid for the lifetime of the plugin instance - you must
  *        copy the string value if you need it longer than that.
  */
  /* [noscript] void getPluginName (in nsIPluginInstance aInstance, [shared] out string aPluginName); */
  NS_IMETHOD GetPluginName(nsIPluginInstance *aInstance, const char **aPluginName NS_OUTPARAM) = 0;

};

  NS_DEFINE_STATIC_IID_ACCESSOR(nsPIPluginHost, NS_PIPLUGINHOST_IID)

/* Use this macro when declaring classes that implement this interface. */
#define NS_DECL_NSPIPLUGINHOST \
  NS_IMETHOD SetIsScriptableInstance(nsIPluginInstance *aInstance, PRBool aScriptable); \
  NS_IMETHOD ParsePostBufferToFixHeaders(const char *aInPostData, PRUint32 aInPostDataLen, char **aOutPostData NS_OUTPARAM, PRUint32 *aOutPostDataLen NS_OUTPARAM); \
  NS_IMETHOD CreateTmpFileToPost(const char *aPostDataURL, char **aTmpFileName NS_OUTPARAM); \
  NS_IMETHOD NewPluginNativeWindow(nsPluginNativeWindow * *aPluginNativeWindow NS_OUTPARAM); \
  NS_IMETHOD DeletePluginNativeWindow(nsPluginNativeWindow * aPluginNativeWindow); \
  NS_IMETHOD InstantiateDummyJavaPlugin(nsIPluginInstanceOwner *aOwner); \
  NS_IMETHOD GetPluginName(nsIPluginInstance *aInstance, const char **aPluginName NS_OUTPARAM); 

/* Use this macro to declare functions that forward the behavior of this interface to another object. */
#define NS_FORWARD_NSPIPLUGINHOST(_to) \
  NS_IMETHOD SetIsScriptableInstance(nsIPluginInstance *aInstance, PRBool aScriptable) { return _to SetIsScriptableInstance(aInstance, aScriptable); } \
  NS_IMETHOD ParsePostBufferToFixHeaders(const char *aInPostData, PRUint32 aInPostDataLen, char **aOutPostData NS_OUTPARAM, PRUint32 *aOutPostDataLen NS_OUTPARAM) { return _to ParsePostBufferToFixHeaders(aInPostData, aInPostDataLen, aOutPostData, aOutPostDataLen); } \
  NS_IMETHOD CreateTmpFileToPost(const char *aPostDataURL, char **aTmpFileName NS_OUTPARAM) { return _to CreateTmpFileToPost(aPostDataURL, aTmpFileName); } \
  NS_IMETHOD NewPluginNativeWindow(nsPluginNativeWindow * *aPluginNativeWindow NS_OUTPARAM) { return _to NewPluginNativeWindow(aPluginNativeWindow); } \
  NS_IMETHOD DeletePluginNativeWindow(nsPluginNativeWindow * aPluginNativeWindow) { return _to DeletePluginNativeWindow(aPluginNativeWindow); } \
  NS_IMETHOD InstantiateDummyJavaPlugin(nsIPluginInstanceOwner *aOwner) { return _to InstantiateDummyJavaPlugin(aOwner); } \
  NS_IMETHOD GetPluginName(nsIPluginInstance *aInstance, const char **aPluginName NS_OUTPARAM) { return _to GetPluginName(aInstance, aPluginName); } 

/* Use this macro to declare functions that forward the behavior of this interface to another object in a safe way. */
#define NS_FORWARD_SAFE_NSPIPLUGINHOST(_to) \
  NS_IMETHOD SetIsScriptableInstance(nsIPluginInstance *aInstance, PRBool aScriptable) { return !_to ? NS_ERROR_NULL_POINTER : _to->SetIsScriptableInstance(aInstance, aScriptable); } \
  NS_IMETHOD ParsePostBufferToFixHeaders(const char *aInPostData, PRUint32 aInPostDataLen, char **aOutPostData NS_OUTPARAM, PRUint32 *aOutPostDataLen NS_OUTPARAM) { return !_to ? NS_ERROR_NULL_POINTER : _to->ParsePostBufferToFixHeaders(aInPostData, aInPostDataLen, aOutPostData, aOutPostDataLen); } \
  NS_IMETHOD CreateTmpFileToPost(const char *aPostDataURL, char **aTmpFileName NS_OUTPARAM) { return !_to ? NS_ERROR_NULL_POINTER : _to->CreateTmpFileToPost(aPostDataURL, aTmpFileName); } \
  NS_IMETHOD NewPluginNativeWindow(nsPluginNativeWindow * *aPluginNativeWindow NS_OUTPARAM) { return !_to ? NS_ERROR_NULL_POINTER : _to->NewPluginNativeWindow(aPluginNativeWindow); } \
  NS_IMETHOD DeletePluginNativeWindow(nsPluginNativeWindow * aPluginNativeWindow) { return !_to ? NS_ERROR_NULL_POINTER : _to->DeletePluginNativeWindow(aPluginNativeWindow); } \
  NS_IMETHOD InstantiateDummyJavaPlugin(nsIPluginInstanceOwner *aOwner) { return !_to ? NS_ERROR_NULL_POINTER : _to->InstantiateDummyJavaPlugin(aOwner); } \
  NS_IMETHOD GetPluginName(nsIPluginInstance *aInstance, const char **aPluginName NS_OUTPARAM) { return !_to ? NS_ERROR_NULL_POINTER : _to->GetPluginName(aInstance, aPluginName); } 

#if 0
/* Use the code below as a template for the implementation class for this interface. */

/* Header file */
class _MYCLASS_ : public nsPIPluginHost
{
public:
  NS_DECL_ISUPPORTS
  NS_DECL_NSPIPLUGINHOST

  _MYCLASS_();

private:
  ~_MYCLASS_();

protected:
  /* additional members */
};

/* Implementation file */
NS_IMPL_ISUPPORTS1(_MYCLASS_, nsPIPluginHost)

_MYCLASS_::_MYCLASS_()
{
  /* member initializers and constructor code */
}

_MYCLASS_::~_MYCLASS_()
{
  /* destructor code */
}

/* void setIsScriptableInstance (in nsIPluginInstance aInstance, in boolean aScriptable); */
NS_IMETHODIMP _MYCLASS_::SetIsScriptableInstance(nsIPluginInstance *aInstance, PRBool aScriptable)
{
    return NS_ERROR_NOT_IMPLEMENTED;
}

/* void parsePostBufferToFixHeaders (in string aInPostData, in unsigned long aInPostDataLen, out string aOutPostData, out unsigned long aOutPostDataLen); */
NS_IMETHODIMP _MYCLASS_::ParsePostBufferToFixHeaders(const char *aInPostData, PRUint32 aInPostDataLen, char **aOutPostData NS_OUTPARAM, PRUint32 *aOutPostDataLen NS_OUTPARAM)
{
    return NS_ERROR_NOT_IMPLEMENTED;
}

/* void createTmpFileToPost (in string aPostDataURL, out string aTmpFileName); */
NS_IMETHODIMP _MYCLASS_::CreateTmpFileToPost(const char *aPostDataURL, char **aTmpFileName NS_OUTPARAM)
{
    return NS_ERROR_NOT_IMPLEMENTED;
}

/* void newPluginNativeWindow (out nsPluginNativeWindowPtr aPluginNativeWindow); */
NS_IMETHODIMP _MYCLASS_::NewPluginNativeWindow(nsPluginNativeWindow * *aPluginNativeWindow NS_OUTPARAM)
{
    return NS_ERROR_NOT_IMPLEMENTED;
}

/* void deletePluginNativeWindow (in nsPluginNativeWindowPtr aPluginNativeWindow); */
NS_IMETHODIMP _MYCLASS_::DeletePluginNativeWindow(nsPluginNativeWindow * aPluginNativeWindow)
{
    return NS_ERROR_NOT_IMPLEMENTED;
}

/* [noscript] void instantiateDummyJavaPlugin (in nsIPluginInstanceOwner aOwner); */
NS_IMETHODIMP _MYCLASS_::InstantiateDummyJavaPlugin(nsIPluginInstanceOwner *aOwner)
{
    return NS_ERROR_NOT_IMPLEMENTED;
}

/* [noscript] void getPluginName (in nsIPluginInstance aInstance, [shared] out string aPluginName); */
NS_IMETHODIMP _MYCLASS_::GetPluginName(nsIPluginInstance *aInstance, const char **aPluginName NS_OUTPARAM)
{
    return NS_ERROR_NOT_IMPLEMENTED;
}

/* End of implementation class template. */
#endif


#endif /* __gen_nsPIPluginHost_h__ */
