/*
 * DO NOT EDIT.  THIS FILE IS GENERATED FROM e:/builds/moz2_slave/mozilla-1.9.1-win32-xulrunner/build/content/base/public/nsIObjectLoadingContent.idl
 */

#ifndef __gen_nsIObjectLoadingContent_h__
#define __gen_nsIObjectLoadingContent_h__


#ifndef __gen_nsISupports_h__
#include "nsISupports.h"
#endif

/* For IDL files that don't want to include root IDL files. */
#ifndef NS_NO_VTABLE
#define NS_NO_VTABLE
#endif
class nsIObjectFrame; /* forward declaration */

class nsIPluginInstance; /* forward declaration */


/* starting interface:    nsIObjectLoadingContent */
#define NS_IOBJECTLOADINGCONTENT_IID_STR "90ab443e-3e99-405e-88c9-9c42adaa3217"

#define NS_IOBJECTLOADINGCONTENT_IID \
  {0x90ab443e, 0x3e99, 0x405e, \
    { 0x88, 0xc9, 0x9c, 0x42, 0xad, 0xaa, 0x32, 0x17 }}

/**
 * This interface represents a content node that loads objects.
 */
class NS_NO_VTABLE NS_SCRIPTABLE nsIObjectLoadingContent : public nsISupports {
 public: 

  NS_DECLARE_STATIC_IID_ACCESSOR(NS_IOBJECTLOADINGCONTENT_IID)

  enum { TYPE_LOADING = 0U };

  enum { TYPE_IMAGE = 1U };

  enum { TYPE_PLUGIN = 2U };

  enum { TYPE_DOCUMENT = 3U };

  enum { TYPE_NULL = 4U };

  /**
   * The actual mime type (the one we got back from the network
   * request) for the element.
   */
  /* readonly attribute ACString actualType; */
  NS_SCRIPTABLE NS_IMETHOD GetActualType(nsACString & aActualType) = 0;

  /**
   * Gets the type of the content that's currently loaded. See
   * the constants above for the list of possible values.
   */
  /* readonly attribute unsigned long displayedType; */
  NS_SCRIPTABLE NS_IMETHOD GetDisplayedType(PRUint32 *aDisplayedType) = 0;

  /**
   * Gets the content type that corresponds to the give MIME type.  See the
   * constants above for the list of possible values.  If nothing else fits,
   * TYPE_NULL will be returned.
   */
  /* unsigned long getContentTypeForMIMEType (in AUTF8String aMimeType); */
  NS_SCRIPTABLE NS_IMETHOD GetContentTypeForMIMEType(const nsACString & aMimeType, PRUint32 *_retval NS_OUTPARAM) = 0;

  /**
   * Returns the plugin instance if it has already been instantiated. This
   * will never instantiate the plugin and so is safe to call even when
   * content script must not execute.
   */
  /* [noscript] readonly attribute nsIPluginInstance pluginInstance; */
  NS_IMETHOD GetPluginInstance(nsIPluginInstance * *aPluginInstance) = 0;

  /**
   * Makes sure that a frame for this object exists, and that the plugin is
   * instantiated. This method does nothing if the type is not #TYPE_PLUGIN.
   * There is no guarantee that there will be a frame after this method is
   * called; for example, the node may have a display:none style. If plugin
   * instantiation is possible, it will be done synchronously by this method,
   * and the plugin instance will be returned. A success return value does not
   * necessarily mean that the instance is nonnull.
   *
   * This is a noscript method because it is internal and will go away once
   * plugin loading moves to content.
   *
   * @note If there is an error instantiating the plugin, this method will
   * trigger fallback to replacement content, and the type will change (and
   * this method will return a failure code)
   */
  /* [noscript] nsIPluginInstance ensureInstantiation (); */
  NS_IMETHOD EnsureInstantiation(nsIPluginInstance **_retval NS_OUTPARAM) = 0;

  /**
   * Tells the content about an associated object frame.
   * This can be called multiple times for different frames.
   *
   * This is noscript because this is an internal method that will go away, and
   * because nsIObjectFrame is unscriptable.
   */
  /* [noscript] void hasNewFrame (in nsIObjectFrame aFrame); */
  NS_IMETHOD HasNewFrame(nsIObjectFrame *aFrame) = 0;

};

  NS_DEFINE_STATIC_IID_ACCESSOR(nsIObjectLoadingContent, NS_IOBJECTLOADINGCONTENT_IID)

/* Use this macro when declaring classes that implement this interface. */
#define NS_DECL_NSIOBJECTLOADINGCONTENT \
  NS_SCRIPTABLE NS_IMETHOD GetActualType(nsACString & aActualType); \
  NS_SCRIPTABLE NS_IMETHOD GetDisplayedType(PRUint32 *aDisplayedType); \
  NS_SCRIPTABLE NS_IMETHOD GetContentTypeForMIMEType(const nsACString & aMimeType, PRUint32 *_retval NS_OUTPARAM); \
  NS_IMETHOD GetPluginInstance(nsIPluginInstance * *aPluginInstance); \
  NS_IMETHOD EnsureInstantiation(nsIPluginInstance **_retval NS_OUTPARAM); \
  NS_IMETHOD HasNewFrame(nsIObjectFrame *aFrame); 

/* Use this macro to declare functions that forward the behavior of this interface to another object. */
#define NS_FORWARD_NSIOBJECTLOADINGCONTENT(_to) \
  NS_SCRIPTABLE NS_IMETHOD GetActualType(nsACString & aActualType) { return _to GetActualType(aActualType); } \
  NS_SCRIPTABLE NS_IMETHOD GetDisplayedType(PRUint32 *aDisplayedType) { return _to GetDisplayedType(aDisplayedType); } \
  NS_SCRIPTABLE NS_IMETHOD GetContentTypeForMIMEType(const nsACString & aMimeType, PRUint32 *_retval NS_OUTPARAM) { return _to GetContentTypeForMIMEType(aMimeType, _retval); } \
  NS_IMETHOD GetPluginInstance(nsIPluginInstance * *aPluginInstance) { return _to GetPluginInstance(aPluginInstance); } \
  NS_IMETHOD EnsureInstantiation(nsIPluginInstance **_retval NS_OUTPARAM) { return _to EnsureInstantiation(_retval); } \
  NS_IMETHOD HasNewFrame(nsIObjectFrame *aFrame) { return _to HasNewFrame(aFrame); } 

/* Use this macro to declare functions that forward the behavior of this interface to another object in a safe way. */
#define NS_FORWARD_SAFE_NSIOBJECTLOADINGCONTENT(_to) \
  NS_SCRIPTABLE NS_IMETHOD GetActualType(nsACString & aActualType) { return !_to ? NS_ERROR_NULL_POINTER : _to->GetActualType(aActualType); } \
  NS_SCRIPTABLE NS_IMETHOD GetDisplayedType(PRUint32 *aDisplayedType) { return !_to ? NS_ERROR_NULL_POINTER : _to->GetDisplayedType(aDisplayedType); } \
  NS_SCRIPTABLE NS_IMETHOD GetContentTypeForMIMEType(const nsACString & aMimeType, PRUint32 *_retval NS_OUTPARAM) { return !_to ? NS_ERROR_NULL_POINTER : _to->GetContentTypeForMIMEType(aMimeType, _retval); } \
  NS_IMETHOD GetPluginInstance(nsIPluginInstance * *aPluginInstance) { return !_to ? NS_ERROR_NULL_POINTER : _to->GetPluginInstance(aPluginInstance); } \
  NS_IMETHOD EnsureInstantiation(nsIPluginInstance **_retval NS_OUTPARAM) { return !_to ? NS_ERROR_NULL_POINTER : _to->EnsureInstantiation(_retval); } \
  NS_IMETHOD HasNewFrame(nsIObjectFrame *aFrame) { return !_to ? NS_ERROR_NULL_POINTER : _to->HasNewFrame(aFrame); } 

#if 0
/* Use the code below as a template for the implementation class for this interface. */

/* Header file */
class nsObjectLoadingContent : public nsIObjectLoadingContent
{
public:
  NS_DECL_ISUPPORTS
  NS_DECL_NSIOBJECTLOADINGCONTENT

  nsObjectLoadingContent();

private:
  ~nsObjectLoadingContent();

protected:
  /* additional members */
};

/* Implementation file */
NS_IMPL_ISUPPORTS1(nsObjectLoadingContent, nsIObjectLoadingContent)

nsObjectLoadingContent::nsObjectLoadingContent()
{
  /* member initializers and constructor code */
}

nsObjectLoadingContent::~nsObjectLoadingContent()
{
  /* destructor code */
}

/* readonly attribute ACString actualType; */
NS_IMETHODIMP nsObjectLoadingContent::GetActualType(nsACString & aActualType)
{
    return NS_ERROR_NOT_IMPLEMENTED;
}

/* readonly attribute unsigned long displayedType; */
NS_IMETHODIMP nsObjectLoadingContent::GetDisplayedType(PRUint32 *aDisplayedType)
{
    return NS_ERROR_NOT_IMPLEMENTED;
}

/* unsigned long getContentTypeForMIMEType (in AUTF8String aMimeType); */
NS_IMETHODIMP nsObjectLoadingContent::GetContentTypeForMIMEType(const nsACString & aMimeType, PRUint32 *_retval NS_OUTPARAM)
{
    return NS_ERROR_NOT_IMPLEMENTED;
}

/* [noscript] readonly attribute nsIPluginInstance pluginInstance; */
NS_IMETHODIMP nsObjectLoadingContent::GetPluginInstance(nsIPluginInstance * *aPluginInstance)
{
    return NS_ERROR_NOT_IMPLEMENTED;
}

/* [noscript] nsIPluginInstance ensureInstantiation (); */
NS_IMETHODIMP nsObjectLoadingContent::EnsureInstantiation(nsIPluginInstance **_retval NS_OUTPARAM)
{
    return NS_ERROR_NOT_IMPLEMENTED;
}

/* [noscript] void hasNewFrame (in nsIObjectFrame aFrame); */
NS_IMETHODIMP nsObjectLoadingContent::HasNewFrame(nsIObjectFrame *aFrame)
{
    return NS_ERROR_NOT_IMPLEMENTED;
}

/* End of implementation class template. */
#endif


#endif /* __gen_nsIObjectLoadingContent_h__ */
