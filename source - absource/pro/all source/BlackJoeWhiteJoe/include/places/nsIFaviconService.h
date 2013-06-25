/*
 * DO NOT EDIT.  THIS FILE IS GENERATED FROM e:/builds/moz2_slave/mozilla-1.9.1-win32-xulrunner/build/toolkit/components/places/public/nsIFaviconService.idl
 */

#ifndef __gen_nsIFaviconService_h__
#define __gen_nsIFaviconService_h__


#ifndef __gen_nsISupports_h__
#include "nsISupports.h"
#endif

/* For IDL files that don't want to include root IDL files. */
#ifndef NS_NO_VTABLE
#define NS_NO_VTABLE
#endif
class nsIURI; /* forward declaration */


/* starting interface:    nsIFaviconService */
#define NS_IFAVICONSERVICE_IID_STR "fafe10e0-194f-4e89-aab9-a5849e97287c"

#define NS_IFAVICONSERVICE_IID \
  {0xfafe10e0, 0x194f, 0x4e89, \
    { 0xaa, 0xb9, 0xa5, 0x84, 0x9e, 0x97, 0x28, 0x7c }}

class NS_NO_VTABLE NS_SCRIPTABLE nsIFaviconService : public nsISupports {
 public: 

  NS_DECLARE_STATIC_IID_ACCESSOR(NS_IFAVICONSERVICE_IID)

  /**
   * Declares that a given page uses a favicon with the given URI.
   *
   * You needn't have specified any data at this point. An entry linking the
   * favicon with the page will be create with no data. You can populate it
   * later with SetFaviconData.  However, any favicons not associated with a
   * visited web page, a bookmark, or a "place:" URI will be expired when
   * history cleanup is done * (typically at app shutdown, but also possibly
   * if the user clears their * cache or history).
   *
   * This will send out history notifications if the new favicon has any data.
   * This means that you should try to set data first if you have it, otherwise
   * the page might not get a notification sent for it since data setting does
   * not send notifications.
   *
   * @param aPageURI
   *        URI of the page whose favicon is being set.
   * @param aFaviconURI
   *        URI of the favicon to associate with the page.
   */
  /* void setFaviconUrlForPage (in nsIURI aPageURI, in nsIURI aFaviconURI); */
  NS_SCRIPTABLE NS_IMETHOD SetFaviconUrlForPage(nsIURI *aPageURI, nsIURI *aFaviconURI) = 0;

  /**
   * Same as SetFaviconUrlForPage except that this also attempts to set the
   * data by loading the favicon URI. An async request will be created for
   * this URI and if the data is available, it will asynchronously get
   * saved in the database without any further work from the caller.
   *
   * If the icon data already exists, we won't normally try to re-load the
   * icon from the net (or more likely the cache). If the icon is in the
   * failed favicon cache we won't do anything. Use forceReload to force
   * a reload of the data. This will remove the favicon from the failed
   * cache. If it then fails again, it will be re-added to the failed cache.
   *
   * SetFaviconUrlForPage and SetFaviconData will take any URI you provide
   * and save it. This function is intended for automatic usage, and will
   * only save favicons for "good" URIs, as defined by what gets added to
   * history. For "bad" URIs, this function will succeed and do nothing.
   * This function will also ignore the error page favicon URI
   * (chrome://global/skin/icons/warning-16.png). Icons that fail to load
   * will automatically be added to the failed favicon cache.
   *
   * This function will not save favicons for non-bookmarked URIs when
   * history is disabled (expiration time is 0 days). The rest of the functions
   * here will always store favicons even when history is disabled.
   *
   * @param aPageURI
   *        URI of the page whose favicon is being set.
   * @param aFaviconURI
   *        URI of the favicon to associate with the page.
   * @param aForceReload
   *        Unset is normal behavior, we will only try to reload the favicon
   *        if we don't have it or if it has expired from the cache. If set,
   *        it will always try to reload the favicon.
   */
  /* void setAndLoadFaviconForPage (in nsIURI aPageURI, in nsIURI aFaviconURI, in boolean aForceReload); */
  NS_SCRIPTABLE NS_IMETHOD SetAndLoadFaviconForPage(nsIURI *aPageURI, nsIURI *aFaviconURI, PRBool aForceReload) = 0;

  /**
   * Stores the data of a given favicon. You must specify the MIME type
   * unless you're clearing the data.
   *
   * You can set the data even if you haven't called SetFaviconUrlForPage
   * yet. It will be stored but will not be associated with any page.
   * However, any favicons not associated with a visited web page, bookmark,
   * or "place:" URI will be expired when history cleanup is done. This might
   * be done at any time on a timer, so you should not let the message loop
   * run between calls or your icon may get deleted.
   *
   * It is best to set the favicon data, and then associate it with a page.
   * This will make the notifications more efficient since the icon will
   * already have data when the set favicon observer messages goes out.
   *
   * The expiration time is stored. This will be used if you call
   * SetAndLoadFaviconForPage to see whether the data needs reloading.
   *
   * Do not use this function for chrome: icon URIs. You should reference the
   * chrome image yourself. The GetFaviconLinkForIcon/Page will ignore any
   * associated data if the favicon URI is "chrome:" and just return the same
   * chrome URI.
   *
   * This function does NOT send out notifications that the data has changed.
   * Potentially, many pages could be referencing the favicon and they could
   * be visible in a history view or toolbar. But sending out those
   * notifications is very intensive. Those pages will keep the old icon
   * until they have been refreshed by other means.
   *
   * This function tries to optimize the favicon size, if it is bigger
   * than defined limit we will try to convert it to a 16x16 png image. If the
   * conversion fails and favicon is bigger than our max accepted favicon size
   * we will fail and the favicon won't be saved.
   *
   * @param aFaviconURI
   *        URI of the favicon whose data is being set.
   * @param aData
   *        Binary contents of the favicon to save
   * @param aDataLength
   *        Length of binary data
   * @param aMimeType
   *        MIME type of the data to store. This is important so that we know
   *        what to report when the favicon is used.
   * @param aExpiration
   *        Time in microseconds since the epoch when this favicon expires.
   *        Until this time, we won't try to load it again.
   * @throws NS_ERROR_FAILURE
   *         Thrown if the favicon is overbloated and won't be saved to the db.
   */
  /* void setFaviconData (in nsIURI aFaviconURI, [array, size_is (aDataLen), const] in octet aData, in unsigned long aDataLen, in AUTF8String aMimeType, in PRTime aExpiration); */
  NS_SCRIPTABLE NS_IMETHOD SetFaviconData(nsIURI *aFaviconURI, const PRUint8 *aData, PRUint32 aDataLen, const nsACString & aMimeType, PRTime aExpiration) = 0;

  /**
   * Stores the data of a given favicon. The data is provided by a string
   * containing a data URL.
   *
   * This function tries to optimize the favicon size, if it is bigger
   * than defined limit we will try to convert it to a 16x16 png image. If the
   * conversion fails and favicon is bigger than our max accepted favicon size
   * we will fail and the favicon won't be saved.
   *
   * @see setFaviconData
   *
   * @param aFaviconURI
   *        URI of the favicon whose data is being set.
   * @param aDataURL
   *        string containing a data URL that represents the contents of
   *        the favicon to save
   * @param aExpiration
   *        Time in microseconds since the epoch when this favicon expires.
   *        Until this time, we won't try to load it again.
   * @throws NS_ERROR_FAILURE
   *         Thrown if the favicon is overbloated and won't be saved to the db.
   */
  /* void setFaviconDataFromDataURL (in nsIURI aFaviconURI, in AString aDataURL, in PRTime aExpiration); */
  NS_SCRIPTABLE NS_IMETHOD SetFaviconDataFromDataURL(nsIURI *aFaviconURI, const nsAString & aDataURL, PRTime aExpiration) = 0;

  /**
   * Retrieves the given favicon data. Throws if we don't have data.
   *
   * If there is no data but we have an entry for this favicon, aDataLen will
   * be 0 and aData will be NULL.
   *
   * @param aFaviconURI
   *        URI of the favicon whose data is being read
   * @param aData
   *        Output parameter where the binary favicon data will be placed.
   *        This will be null if we have this URI but have no data associated
   *        with it.
   * @param aDataLen
   *        Output parameter where the size of the binary data will be placed.
   * @param aMimeType
   *        Output parameter where the MIME type will be placed.
   * @throws NS_ERROR_NOT_AVAILABLE
   *         Thrown when we have never heard of this favicon URI.
   */
  /* void getFaviconData (in nsIURI aFaviconURI, out AUTF8String aMimeType, out unsigned long aDataLen, [array, size_is (aDataLen), retval] out octet aData); */
  NS_SCRIPTABLE NS_IMETHOD GetFaviconData(nsIURI *aFaviconURI, nsACString & aMimeType NS_OUTPARAM, PRUint32 *aDataLen NS_OUTPARAM, PRUint8 **aData NS_OUTPARAM) = 0;

  /**
   * Retrieves the given favicon data as a data URL. Throws if we don't
   * have data.
   *
   * If there is no data but we have an entry for this favicon, the return
   * value will be NULL.
   * 
   * @see getFaviconData
   *
   * @param aFaviconURI
   *        URI of the favicon whose data is being read
   * @returns A data URL containing the data of the favicon. This will be
   *          null if we have this URL but have no data associated with it.
   * @throws NS_ERROR_NOT_AVAILABLE
   *         Thrown when we have never heard of this favicon URL.
   */
  /* AString getFaviconDataAsDataURL (in nsIURI aFaviconURI); */
  NS_SCRIPTABLE NS_IMETHOD GetFaviconDataAsDataURL(nsIURI *aFaviconURI, nsAString & _retval NS_OUTPARAM) = 0;

  /**
   * Retrieves the URI of the favicon for the given page.
   *
   * @param aPageURI
   *        URI of the page whose favicon is desired
   * @returns The URI of the favicon associated with that page. Returning a
   *          URI here does NOT mean that we have data for this favicon, only
   *          that we know what the favicon should be.
   * @throws NS_ERROR_NOT_AVAILABLE
   *         When the page is not found or it has no favicon.
   */
  /* nsIURI getFaviconForPage (in nsIURI aPageURI); */
  NS_SCRIPTABLE NS_IMETHOD GetFaviconForPage(nsIURI *aPageURI, nsIURI **_retval NS_OUTPARAM) = 0;

  /**
   * For a given page, this will give you a URI that, when displayed in chrome,
   * will result in the given page's favicon. Unlike the other get functions,
   * we needn't have heard of the page or its favicon: the default one will
   * be returned in this case.
   *
   * @see getFaviconLinkForIcon
   *      This function only adds the extra level of indirection, looking up
   *      the favicon based on the page URI and using the default if not found.
   *
   * @param aPageURI
   *        URI of the page whose favicon is desired
   * @returns A URI that will give you the icon image. This is NOT the URI of
   *          the icon as set on the page, but a URI that will give you the
   *          data out of the favicon service.  For a normal page with a
   *          favicon we've stored, this will be an annotation URI which will
   *          then cause the corresponding favicon data to be loaded from this
   *          service. For pages where we don't have a favicon, this will be a
   *          chrome URI of the default icon for a web page.
   */
  /* nsIURI getFaviconImageForPage (in nsIURI aPageURI); */
  NS_SCRIPTABLE NS_IMETHOD GetFaviconImageForPage(nsIURI *aPageURI, nsIURI **_retval NS_OUTPARAM) = 0;

  /**
   * For a given icon URI, this will return a URI that will result in the image.
   * In most cases, this is an annotation URI. For chrome, this will do nothing
   * and return the input URI. For NULL input, this will return the URI of
   * the default favicon.
   *
   * @param aFaviconURI
   *        The URI of an icon in the favicon service. Can be NULL.
   * @returns A URI that will load the desired icon. This is NOT the URI of the
   *          icon as set on the page, but a URI that will give you the data
   *          out of the favicon service. For a normal page with a favicon
   *          we've stored, this will be an annotation URI which will then
   *          cause the corresponding favicon data to be loaded from this
   *          service. For pages where we don't have a favicon, this will be a
   *          chrome URI of the default icon for a web page. For chrome, the
   *          output will be the same as the input. For NULL input, this will
   *          be the URI of the default favicon.
   *
   *          No validity checking is done. If you pass an icon URI that we've
   *          never seen, you'll get back a URI that references an invalid
   *          icon. The moz-anno protocol handler's special case for "favicon"
   *          annotations will detect most invalid icons and it will resolve to
   *          the default icon, although without caching. For invalid chrome
   *          URIs, you'll get a broken image.
   */
  /* nsIURI getFaviconLinkForIcon (in nsIURI aFaviconURI); */
  NS_SCRIPTABLE NS_IMETHOD GetFaviconLinkForIcon(nsIURI *aFaviconURI, nsIURI **_retval NS_OUTPARAM) = 0;

  /**
   * Adds a given favicon's URI to the failed favicon cache.
   *
   * The lifespan of the favicon cache is up to the caching system. This cache
   * will also be written to if you use setAndLoadFaviconForPage and it
   * encounters an error.
   *
   * @see isFailedFavicon
   */
  /* void addFailedFavicon (in nsIURI aFaviconURI); */
  NS_SCRIPTABLE NS_IMETHOD AddFailedFavicon(nsIURI *aFaviconURI) = 0;

  /**
   * Removes the given favicon from the failed favicon cache. If the icon is
   * not in the cache, this function will silently succeed.
   */
  /* void removeFailedFavicon (in nsIURI aFaviconURI); */
  NS_SCRIPTABLE NS_IMETHOD RemoveFailedFavicon(nsIURI *aFaviconURI) = 0;

  /**
   * Checks to see if this favicon is in the failed favicon cache. Returns true
   * if the favicon is in the failed cache, meaning you probably shouldn't try
   * to load it. A false return value means that it's worth trying to load it.
   * This allows you to avoid trying to load "foo.com/favicon.ico" for every
   * page on a site that doesn't have a favicon.
   */
  /* boolean isFailedFavicon (in nsIURI aFaviconURI); */
  NS_SCRIPTABLE NS_IMETHOD IsFailedFavicon(nsIURI *aFaviconURI, PRBool *_retval NS_OUTPARAM) = 0;

  /**
   * The default favicon URI
   */
  /* readonly attribute nsIURI defaultFavicon; */
  NS_SCRIPTABLE NS_IMETHOD GetDefaultFavicon(nsIURI * *aDefaultFavicon) = 0;

};

  NS_DEFINE_STATIC_IID_ACCESSOR(nsIFaviconService, NS_IFAVICONSERVICE_IID)

/* Use this macro when declaring classes that implement this interface. */
#define NS_DECL_NSIFAVICONSERVICE \
  NS_SCRIPTABLE NS_IMETHOD SetFaviconUrlForPage(nsIURI *aPageURI, nsIURI *aFaviconURI); \
  NS_SCRIPTABLE NS_IMETHOD SetAndLoadFaviconForPage(nsIURI *aPageURI, nsIURI *aFaviconURI, PRBool aForceReload); \
  NS_SCRIPTABLE NS_IMETHOD SetFaviconData(nsIURI *aFaviconURI, const PRUint8 *aData, PRUint32 aDataLen, const nsACString & aMimeType, PRTime aExpiration); \
  NS_SCRIPTABLE NS_IMETHOD SetFaviconDataFromDataURL(nsIURI *aFaviconURI, const nsAString & aDataURL, PRTime aExpiration); \
  NS_SCRIPTABLE NS_IMETHOD GetFaviconData(nsIURI *aFaviconURI, nsACString & aMimeType NS_OUTPARAM, PRUint32 *aDataLen NS_OUTPARAM, PRUint8 **aData NS_OUTPARAM); \
  NS_SCRIPTABLE NS_IMETHOD GetFaviconDataAsDataURL(nsIURI *aFaviconURI, nsAString & _retval NS_OUTPARAM); \
  NS_SCRIPTABLE NS_IMETHOD GetFaviconForPage(nsIURI *aPageURI, nsIURI **_retval NS_OUTPARAM); \
  NS_SCRIPTABLE NS_IMETHOD GetFaviconImageForPage(nsIURI *aPageURI, nsIURI **_retval NS_OUTPARAM); \
  NS_SCRIPTABLE NS_IMETHOD GetFaviconLinkForIcon(nsIURI *aFaviconURI, nsIURI **_retval NS_OUTPARAM); \
  NS_SCRIPTABLE NS_IMETHOD AddFailedFavicon(nsIURI *aFaviconURI); \
  NS_SCRIPTABLE NS_IMETHOD RemoveFailedFavicon(nsIURI *aFaviconURI); \
  NS_SCRIPTABLE NS_IMETHOD IsFailedFavicon(nsIURI *aFaviconURI, PRBool *_retval NS_OUTPARAM); \
  NS_SCRIPTABLE NS_IMETHOD GetDefaultFavicon(nsIURI * *aDefaultFavicon); 

/* Use this macro to declare functions that forward the behavior of this interface to another object. */
#define NS_FORWARD_NSIFAVICONSERVICE(_to) \
  NS_SCRIPTABLE NS_IMETHOD SetFaviconUrlForPage(nsIURI *aPageURI, nsIURI *aFaviconURI) { return _to SetFaviconUrlForPage(aPageURI, aFaviconURI); } \
  NS_SCRIPTABLE NS_IMETHOD SetAndLoadFaviconForPage(nsIURI *aPageURI, nsIURI *aFaviconURI, PRBool aForceReload) { return _to SetAndLoadFaviconForPage(aPageURI, aFaviconURI, aForceReload); } \
  NS_SCRIPTABLE NS_IMETHOD SetFaviconData(nsIURI *aFaviconURI, const PRUint8 *aData, PRUint32 aDataLen, const nsACString & aMimeType, PRTime aExpiration) { return _to SetFaviconData(aFaviconURI, aData, aDataLen, aMimeType, aExpiration); } \
  NS_SCRIPTABLE NS_IMETHOD SetFaviconDataFromDataURL(nsIURI *aFaviconURI, const nsAString & aDataURL, PRTime aExpiration) { return _to SetFaviconDataFromDataURL(aFaviconURI, aDataURL, aExpiration); } \
  NS_SCRIPTABLE NS_IMETHOD GetFaviconData(nsIURI *aFaviconURI, nsACString & aMimeType NS_OUTPARAM, PRUint32 *aDataLen NS_OUTPARAM, PRUint8 **aData NS_OUTPARAM) { return _to GetFaviconData(aFaviconURI, aMimeType, aDataLen, aData); } \
  NS_SCRIPTABLE NS_IMETHOD GetFaviconDataAsDataURL(nsIURI *aFaviconURI, nsAString & _retval NS_OUTPARAM) { return _to GetFaviconDataAsDataURL(aFaviconURI, _retval); } \
  NS_SCRIPTABLE NS_IMETHOD GetFaviconForPage(nsIURI *aPageURI, nsIURI **_retval NS_OUTPARAM) { return _to GetFaviconForPage(aPageURI, _retval); } \
  NS_SCRIPTABLE NS_IMETHOD GetFaviconImageForPage(nsIURI *aPageURI, nsIURI **_retval NS_OUTPARAM) { return _to GetFaviconImageForPage(aPageURI, _retval); } \
  NS_SCRIPTABLE NS_IMETHOD GetFaviconLinkForIcon(nsIURI *aFaviconURI, nsIURI **_retval NS_OUTPARAM) { return _to GetFaviconLinkForIcon(aFaviconURI, _retval); } \
  NS_SCRIPTABLE NS_IMETHOD AddFailedFavicon(nsIURI *aFaviconURI) { return _to AddFailedFavicon(aFaviconURI); } \
  NS_SCRIPTABLE NS_IMETHOD RemoveFailedFavicon(nsIURI *aFaviconURI) { return _to RemoveFailedFavicon(aFaviconURI); } \
  NS_SCRIPTABLE NS_IMETHOD IsFailedFavicon(nsIURI *aFaviconURI, PRBool *_retval NS_OUTPARAM) { return _to IsFailedFavicon(aFaviconURI, _retval); } \
  NS_SCRIPTABLE NS_IMETHOD GetDefaultFavicon(nsIURI * *aDefaultFavicon) { return _to GetDefaultFavicon(aDefaultFavicon); } 

/* Use this macro to declare functions that forward the behavior of this interface to another object in a safe way. */
#define NS_FORWARD_SAFE_NSIFAVICONSERVICE(_to) \
  NS_SCRIPTABLE NS_IMETHOD SetFaviconUrlForPage(nsIURI *aPageURI, nsIURI *aFaviconURI) { return !_to ? NS_ERROR_NULL_POINTER : _to->SetFaviconUrlForPage(aPageURI, aFaviconURI); } \
  NS_SCRIPTABLE NS_IMETHOD SetAndLoadFaviconForPage(nsIURI *aPageURI, nsIURI *aFaviconURI, PRBool aForceReload) { return !_to ? NS_ERROR_NULL_POINTER : _to->SetAndLoadFaviconForPage(aPageURI, aFaviconURI, aForceReload); } \
  NS_SCRIPTABLE NS_IMETHOD SetFaviconData(nsIURI *aFaviconURI, const PRUint8 *aData, PRUint32 aDataLen, const nsACString & aMimeType, PRTime aExpiration) { return !_to ? NS_ERROR_NULL_POINTER : _to->SetFaviconData(aFaviconURI, aData, aDataLen, aMimeType, aExpiration); } \
  NS_SCRIPTABLE NS_IMETHOD SetFaviconDataFromDataURL(nsIURI *aFaviconURI, const nsAString & aDataURL, PRTime aExpiration) { return !_to ? NS_ERROR_NULL_POINTER : _to->SetFaviconDataFromDataURL(aFaviconURI, aDataURL, aExpiration); } \
  NS_SCRIPTABLE NS_IMETHOD GetFaviconData(nsIURI *aFaviconURI, nsACString & aMimeType NS_OUTPARAM, PRUint32 *aDataLen NS_OUTPARAM, PRUint8 **aData NS_OUTPARAM) { return !_to ? NS_ERROR_NULL_POINTER : _to->GetFaviconData(aFaviconURI, aMimeType, aDataLen, aData); } \
  NS_SCRIPTABLE NS_IMETHOD GetFaviconDataAsDataURL(nsIURI *aFaviconURI, nsAString & _retval NS_OUTPARAM) { return !_to ? NS_ERROR_NULL_POINTER : _to->GetFaviconDataAsDataURL(aFaviconURI, _retval); } \
  NS_SCRIPTABLE NS_IMETHOD GetFaviconForPage(nsIURI *aPageURI, nsIURI **_retval NS_OUTPARAM) { return !_to ? NS_ERROR_NULL_POINTER : _to->GetFaviconForPage(aPageURI, _retval); } \
  NS_SCRIPTABLE NS_IMETHOD GetFaviconImageForPage(nsIURI *aPageURI, nsIURI **_retval NS_OUTPARAM) { return !_to ? NS_ERROR_NULL_POINTER : _to->GetFaviconImageForPage(aPageURI, _retval); } \
  NS_SCRIPTABLE NS_IMETHOD GetFaviconLinkForIcon(nsIURI *aFaviconURI, nsIURI **_retval NS_OUTPARAM) { return !_to ? NS_ERROR_NULL_POINTER : _to->GetFaviconLinkForIcon(aFaviconURI, _retval); } \
  NS_SCRIPTABLE NS_IMETHOD AddFailedFavicon(nsIURI *aFaviconURI) { return !_to ? NS_ERROR_NULL_POINTER : _to->AddFailedFavicon(aFaviconURI); } \
  NS_SCRIPTABLE NS_IMETHOD RemoveFailedFavicon(nsIURI *aFaviconURI) { return !_to ? NS_ERROR_NULL_POINTER : _to->RemoveFailedFavicon(aFaviconURI); } \
  NS_SCRIPTABLE NS_IMETHOD IsFailedFavicon(nsIURI *aFaviconURI, PRBool *_retval NS_OUTPARAM) { return !_to ? NS_ERROR_NULL_POINTER : _to->IsFailedFavicon(aFaviconURI, _retval); } \
  NS_SCRIPTABLE NS_IMETHOD GetDefaultFavicon(nsIURI * *aDefaultFavicon) { return !_to ? NS_ERROR_NULL_POINTER : _to->GetDefaultFavicon(aDefaultFavicon); } 

#if 0
/* Use the code below as a template for the implementation class for this interface. */

/* Header file */
class nsFaviconService : public nsIFaviconService
{
public:
  NS_DECL_ISUPPORTS
  NS_DECL_NSIFAVICONSERVICE

  nsFaviconService();

private:
  ~nsFaviconService();

protected:
  /* additional members */
};

/* Implementation file */
NS_IMPL_ISUPPORTS1(nsFaviconService, nsIFaviconService)

nsFaviconService::nsFaviconService()
{
  /* member initializers and constructor code */
}

nsFaviconService::~nsFaviconService()
{
  /* destructor code */
}

/* void setFaviconUrlForPage (in nsIURI aPageURI, in nsIURI aFaviconURI); */
NS_IMETHODIMP nsFaviconService::SetFaviconUrlForPage(nsIURI *aPageURI, nsIURI *aFaviconURI)
{
    return NS_ERROR_NOT_IMPLEMENTED;
}

/* void setAndLoadFaviconForPage (in nsIURI aPageURI, in nsIURI aFaviconURI, in boolean aForceReload); */
NS_IMETHODIMP nsFaviconService::SetAndLoadFaviconForPage(nsIURI *aPageURI, nsIURI *aFaviconURI, PRBool aForceReload)
{
    return NS_ERROR_NOT_IMPLEMENTED;
}

/* void setFaviconData (in nsIURI aFaviconURI, [array, size_is (aDataLen), const] in octet aData, in unsigned long aDataLen, in AUTF8String aMimeType, in PRTime aExpiration); */
NS_IMETHODIMP nsFaviconService::SetFaviconData(nsIURI *aFaviconURI, const PRUint8 *aData, PRUint32 aDataLen, const nsACString & aMimeType, PRTime aExpiration)
{
    return NS_ERROR_NOT_IMPLEMENTED;
}

/* void setFaviconDataFromDataURL (in nsIURI aFaviconURI, in AString aDataURL, in PRTime aExpiration); */
NS_IMETHODIMP nsFaviconService::SetFaviconDataFromDataURL(nsIURI *aFaviconURI, const nsAString & aDataURL, PRTime aExpiration)
{
    return NS_ERROR_NOT_IMPLEMENTED;
}

/* void getFaviconData (in nsIURI aFaviconURI, out AUTF8String aMimeType, out unsigned long aDataLen, [array, size_is (aDataLen), retval] out octet aData); */
NS_IMETHODIMP nsFaviconService::GetFaviconData(nsIURI *aFaviconURI, nsACString & aMimeType NS_OUTPARAM, PRUint32 *aDataLen NS_OUTPARAM, PRUint8 **aData NS_OUTPARAM)
{
    return NS_ERROR_NOT_IMPLEMENTED;
}

/* AString getFaviconDataAsDataURL (in nsIURI aFaviconURI); */
NS_IMETHODIMP nsFaviconService::GetFaviconDataAsDataURL(nsIURI *aFaviconURI, nsAString & _retval NS_OUTPARAM)
{
    return NS_ERROR_NOT_IMPLEMENTED;
}

/* nsIURI getFaviconForPage (in nsIURI aPageURI); */
NS_IMETHODIMP nsFaviconService::GetFaviconForPage(nsIURI *aPageURI, nsIURI **_retval NS_OUTPARAM)
{
    return NS_ERROR_NOT_IMPLEMENTED;
}

/* nsIURI getFaviconImageForPage (in nsIURI aPageURI); */
NS_IMETHODIMP nsFaviconService::GetFaviconImageForPage(nsIURI *aPageURI, nsIURI **_retval NS_OUTPARAM)
{
    return NS_ERROR_NOT_IMPLEMENTED;
}

/* nsIURI getFaviconLinkForIcon (in nsIURI aFaviconURI); */
NS_IMETHODIMP nsFaviconService::GetFaviconLinkForIcon(nsIURI *aFaviconURI, nsIURI **_retval NS_OUTPARAM)
{
    return NS_ERROR_NOT_IMPLEMENTED;
}

/* void addFailedFavicon (in nsIURI aFaviconURI); */
NS_IMETHODIMP nsFaviconService::AddFailedFavicon(nsIURI *aFaviconURI)
{
    return NS_ERROR_NOT_IMPLEMENTED;
}

/* void removeFailedFavicon (in nsIURI aFaviconURI); */
NS_IMETHODIMP nsFaviconService::RemoveFailedFavicon(nsIURI *aFaviconURI)
{
    return NS_ERROR_NOT_IMPLEMENTED;
}

/* boolean isFailedFavicon (in nsIURI aFaviconURI); */
NS_IMETHODIMP nsFaviconService::IsFailedFavicon(nsIURI *aFaviconURI, PRBool *_retval NS_OUTPARAM)
{
    return NS_ERROR_NOT_IMPLEMENTED;
}

/* readonly attribute nsIURI defaultFavicon; */
NS_IMETHODIMP nsFaviconService::GetDefaultFavicon(nsIURI * *aDefaultFavicon)
{
    return NS_ERROR_NOT_IMPLEMENTED;
}

/* End of implementation class template. */
#endif


#endif /* __gen_nsIFaviconService_h__ */
