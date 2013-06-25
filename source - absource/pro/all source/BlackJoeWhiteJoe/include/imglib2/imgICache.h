/*
 * DO NOT EDIT.  THIS FILE IS GENERATED FROM e:/builds/moz2_slave/mozilla-1.9.1-win32-xulrunner/build/modules/libpr0n/public/imgICache.idl
 */

#ifndef __gen_imgICache_h__
#define __gen_imgICache_h__


#ifndef __gen_nsISupports_h__
#include "nsISupports.h"
#endif

/* For IDL files that don't want to include root IDL files. */
#ifndef NS_NO_VTABLE
#define NS_NO_VTABLE
#endif
class nsIURI; /* forward declaration */

class imgIRequest; /* forward declaration */

class nsIProperties; /* forward declaration */


/* starting interface:    imgICache */
#define IMGICACHE_IID_STR "f1b74aae-5661-4753-a21c-66dd644afebc"

#define IMGICACHE_IID \
  {0xf1b74aae, 0x5661, 0x4753, \
    { 0xa2, 0x1c, 0x66, 0xdd, 0x64, 0x4a, 0xfe, 0xbc }}

/**
 * imgICache interface
 *
 * @author Stuart Parmenter <pavlov@netscape.com>
 * @version 0.1
 * @see imagelib2
 */
class NS_NO_VTABLE NS_SCRIPTABLE imgICache : public nsISupports {
 public: 

  NS_DECLARE_STATIC_IID_ACCESSOR(IMGICACHE_IID)

  /**
   * Evict images from the cache.
   *
   * @param chrome If TRUE,  evict only chrome images.
   *               If FALSE, evict everything except chrome images.
   */
  /* void clearCache (in boolean chrome); */
  NS_SCRIPTABLE NS_IMETHOD ClearCache(PRBool chrome) = 0;

  /**
   * Evict images from the cache.
   *
   * @param uri The URI to remove.
   * @return NS_OK if \a uri was removed from the cache.
   *         NS_ERROR_NOT_AVAILABLE if \a uri was unable to be removed from the cache.
   */
  /* void removeEntry (in nsIURI uri); */
  NS_SCRIPTABLE NS_IMETHOD RemoveEntry(nsIURI *uri) = 0;

  /**
   * Find Properties
   * Used to get properties such as 'type' and 'content-disposition'
   * 'type' is a nsISupportsCString containing the images' mime type such as 'image/png'
   * 'content-disposition' will be a nsISupportsCString containing the header
   * If you call this before any data has been loaded from a URI, it will succeed,
   * but come back empty.
   *
   * @param uri The URI to look up.
   * @returns NULL if the URL was not found in the cache
   */
  /* nsIProperties findEntryProperties (in nsIURI uri); */
  NS_SCRIPTABLE NS_IMETHOD FindEntryProperties(nsIURI *uri, nsIProperties **_retval NS_OUTPARAM) = 0;

};

  NS_DEFINE_STATIC_IID_ACCESSOR(imgICache, IMGICACHE_IID)

/* Use this macro when declaring classes that implement this interface. */
#define NS_DECL_IMGICACHE \
  NS_SCRIPTABLE NS_IMETHOD ClearCache(PRBool chrome); \
  NS_SCRIPTABLE NS_IMETHOD RemoveEntry(nsIURI *uri); \
  NS_SCRIPTABLE NS_IMETHOD FindEntryProperties(nsIURI *uri, nsIProperties **_retval NS_OUTPARAM); 

/* Use this macro to declare functions that forward the behavior of this interface to another object. */
#define NS_FORWARD_IMGICACHE(_to) \
  NS_SCRIPTABLE NS_IMETHOD ClearCache(PRBool chrome) { return _to ClearCache(chrome); } \
  NS_SCRIPTABLE NS_IMETHOD RemoveEntry(nsIURI *uri) { return _to RemoveEntry(uri); } \
  NS_SCRIPTABLE NS_IMETHOD FindEntryProperties(nsIURI *uri, nsIProperties **_retval NS_OUTPARAM) { return _to FindEntryProperties(uri, _retval); } 

/* Use this macro to declare functions that forward the behavior of this interface to another object in a safe way. */
#define NS_FORWARD_SAFE_IMGICACHE(_to) \
  NS_SCRIPTABLE NS_IMETHOD ClearCache(PRBool chrome) { return !_to ? NS_ERROR_NULL_POINTER : _to->ClearCache(chrome); } \
  NS_SCRIPTABLE NS_IMETHOD RemoveEntry(nsIURI *uri) { return !_to ? NS_ERROR_NULL_POINTER : _to->RemoveEntry(uri); } \
  NS_SCRIPTABLE NS_IMETHOD FindEntryProperties(nsIURI *uri, nsIProperties **_retval NS_OUTPARAM) { return !_to ? NS_ERROR_NULL_POINTER : _to->FindEntryProperties(uri, _retval); } 

#if 0
/* Use the code below as a template for the implementation class for this interface. */

/* Header file */
class _MYCLASS_ : public imgICache
{
public:
  NS_DECL_ISUPPORTS
  NS_DECL_IMGICACHE

  _MYCLASS_();

private:
  ~_MYCLASS_();

protected:
  /* additional members */
};

/* Implementation file */
NS_IMPL_ISUPPORTS1(_MYCLASS_, imgICache)

_MYCLASS_::_MYCLASS_()
{
  /* member initializers and constructor code */
}

_MYCLASS_::~_MYCLASS_()
{
  /* destructor code */
}

/* void clearCache (in boolean chrome); */
NS_IMETHODIMP _MYCLASS_::ClearCache(PRBool chrome)
{
    return NS_ERROR_NOT_IMPLEMENTED;
}

/* void removeEntry (in nsIURI uri); */
NS_IMETHODIMP _MYCLASS_::RemoveEntry(nsIURI *uri)
{
    return NS_ERROR_NOT_IMPLEMENTED;
}

/* nsIProperties findEntryProperties (in nsIURI uri); */
NS_IMETHODIMP _MYCLASS_::FindEntryProperties(nsIURI *uri, nsIProperties **_retval NS_OUTPARAM)
{
    return NS_ERROR_NOT_IMPLEMENTED;
}

/* End of implementation class template. */
#endif


#endif /* __gen_imgICache_h__ */
