/*
 * DO NOT EDIT.  THIS FILE IS GENERATED FROM e:/builds/moz2_slave/mozilla-1.9.1-win32-xulrunner/build/toolkit/components/places/public/nsIAnnotationService.idl
 */

#ifndef __gen_nsIAnnotationService_h__
#define __gen_nsIAnnotationService_h__


#ifndef __gen_nsISupports_h__
#include "nsISupports.h"
#endif

/* For IDL files that don't want to include root IDL files. */
#ifndef NS_NO_VTABLE
#define NS_NO_VTABLE
#endif
class nsIURI; /* forward declaration */

class nsIVariant; /* forward declaration */


/* starting interface:    nsIAnnotationObserver */
#define NS_IANNOTATIONOBSERVER_IID_STR "63fe98e0-6889-4c2c-ac9f-703e4bc25027"

#define NS_IANNOTATIONOBSERVER_IID \
  {0x63fe98e0, 0x6889, 0x4c2c, \
    { 0xac, 0x9f, 0x70, 0x3e, 0x4b, 0xc2, 0x50, 0x27 }}

class NS_NO_VTABLE NS_SCRIPTABLE nsIAnnotationObserver : public nsISupports {
 public: 

  NS_DECLARE_STATIC_IID_ACCESSOR(NS_IANNOTATIONOBSERVER_IID)

  /**
     * Called when an annotation value is set. It could be a new annotation,
     * or it could be a new value for an existing annotation.
     */
  /* void onPageAnnotationSet (in nsIURI aPage, in AUTF8String aName); */
  NS_SCRIPTABLE NS_IMETHOD OnPageAnnotationSet(nsIURI *aPage, const nsACString & aName) = 0;

  /* void onItemAnnotationSet (in long long aItemId, in AUTF8String aName); */
  NS_SCRIPTABLE NS_IMETHOD OnItemAnnotationSet(PRInt64 aItemId, const nsACString & aName) = 0;

  /**
     * Called when an annotation is deleted. If aName is empty, then ALL
     * annotations for the given URI have been deleted. This is not called when
     * annotations are expired (normally happens when the app exits).
     */
  /* void onPageAnnotationRemoved (in nsIURI aURI, in AUTF8String aName); */
  NS_SCRIPTABLE NS_IMETHOD OnPageAnnotationRemoved(nsIURI *aURI, const nsACString & aName) = 0;

  /* void onItemAnnotationRemoved (in long long aItemId, in AUTF8String aName); */
  NS_SCRIPTABLE NS_IMETHOD OnItemAnnotationRemoved(PRInt64 aItemId, const nsACString & aName) = 0;

};

  NS_DEFINE_STATIC_IID_ACCESSOR(nsIAnnotationObserver, NS_IANNOTATIONOBSERVER_IID)

/* Use this macro when declaring classes that implement this interface. */
#define NS_DECL_NSIANNOTATIONOBSERVER \
  NS_SCRIPTABLE NS_IMETHOD OnPageAnnotationSet(nsIURI *aPage, const nsACString & aName); \
  NS_SCRIPTABLE NS_IMETHOD OnItemAnnotationSet(PRInt64 aItemId, const nsACString & aName); \
  NS_SCRIPTABLE NS_IMETHOD OnPageAnnotationRemoved(nsIURI *aURI, const nsACString & aName); \
  NS_SCRIPTABLE NS_IMETHOD OnItemAnnotationRemoved(PRInt64 aItemId, const nsACString & aName); 

/* Use this macro to declare functions that forward the behavior of this interface to another object. */
#define NS_FORWARD_NSIANNOTATIONOBSERVER(_to) \
  NS_SCRIPTABLE NS_IMETHOD OnPageAnnotationSet(nsIURI *aPage, const nsACString & aName) { return _to OnPageAnnotationSet(aPage, aName); } \
  NS_SCRIPTABLE NS_IMETHOD OnItemAnnotationSet(PRInt64 aItemId, const nsACString & aName) { return _to OnItemAnnotationSet(aItemId, aName); } \
  NS_SCRIPTABLE NS_IMETHOD OnPageAnnotationRemoved(nsIURI *aURI, const nsACString & aName) { return _to OnPageAnnotationRemoved(aURI, aName); } \
  NS_SCRIPTABLE NS_IMETHOD OnItemAnnotationRemoved(PRInt64 aItemId, const nsACString & aName) { return _to OnItemAnnotationRemoved(aItemId, aName); } 

/* Use this macro to declare functions that forward the behavior of this interface to another object in a safe way. */
#define NS_FORWARD_SAFE_NSIANNOTATIONOBSERVER(_to) \
  NS_SCRIPTABLE NS_IMETHOD OnPageAnnotationSet(nsIURI *aPage, const nsACString & aName) { return !_to ? NS_ERROR_NULL_POINTER : _to->OnPageAnnotationSet(aPage, aName); } \
  NS_SCRIPTABLE NS_IMETHOD OnItemAnnotationSet(PRInt64 aItemId, const nsACString & aName) { return !_to ? NS_ERROR_NULL_POINTER : _to->OnItemAnnotationSet(aItemId, aName); } \
  NS_SCRIPTABLE NS_IMETHOD OnPageAnnotationRemoved(nsIURI *aURI, const nsACString & aName) { return !_to ? NS_ERROR_NULL_POINTER : _to->OnPageAnnotationRemoved(aURI, aName); } \
  NS_SCRIPTABLE NS_IMETHOD OnItemAnnotationRemoved(PRInt64 aItemId, const nsACString & aName) { return !_to ? NS_ERROR_NULL_POINTER : _to->OnItemAnnotationRemoved(aItemId, aName); } 

#if 0
/* Use the code below as a template for the implementation class for this interface. */

/* Header file */
class nsAnnotationObserver : public nsIAnnotationObserver
{
public:
  NS_DECL_ISUPPORTS
  NS_DECL_NSIANNOTATIONOBSERVER

  nsAnnotationObserver();

private:
  ~nsAnnotationObserver();

protected:
  /* additional members */
};

/* Implementation file */
NS_IMPL_ISUPPORTS1(nsAnnotationObserver, nsIAnnotationObserver)

nsAnnotationObserver::nsAnnotationObserver()
{
  /* member initializers and constructor code */
}

nsAnnotationObserver::~nsAnnotationObserver()
{
  /* destructor code */
}

/* void onPageAnnotationSet (in nsIURI aPage, in AUTF8String aName); */
NS_IMETHODIMP nsAnnotationObserver::OnPageAnnotationSet(nsIURI *aPage, const nsACString & aName)
{
    return NS_ERROR_NOT_IMPLEMENTED;
}

/* void onItemAnnotationSet (in long long aItemId, in AUTF8String aName); */
NS_IMETHODIMP nsAnnotationObserver::OnItemAnnotationSet(PRInt64 aItemId, const nsACString & aName)
{
    return NS_ERROR_NOT_IMPLEMENTED;
}

/* void onPageAnnotationRemoved (in nsIURI aURI, in AUTF8String aName); */
NS_IMETHODIMP nsAnnotationObserver::OnPageAnnotationRemoved(nsIURI *aURI, const nsACString & aName)
{
    return NS_ERROR_NOT_IMPLEMENTED;
}

/* void onItemAnnotationRemoved (in long long aItemId, in AUTF8String aName); */
NS_IMETHODIMP nsAnnotationObserver::OnItemAnnotationRemoved(PRInt64 aItemId, const nsACString & aName)
{
    return NS_ERROR_NOT_IMPLEMENTED;
}

/* End of implementation class template. */
#endif


/* starting interface:    nsIAnnotationService */
#define NS_IANNOTATIONSERVICE_IID_STR "ba249b58-346f-42a9-a393-203ae34ec6c4"

#define NS_IANNOTATIONSERVICE_IID \
  {0xba249b58, 0x346f, 0x42a9, \
    { 0xa3, 0x93, 0x20, 0x3a, 0xe3, 0x4e, 0xc6, 0xc4 }}

class NS_NO_VTABLE NS_SCRIPTABLE nsIAnnotationService : public nsISupports {
 public: 

  NS_DECLARE_STATIC_IID_ACCESSOR(NS_IANNOTATIONSERVICE_IID)

  /**
     * Valid values for aExpiration, which sets the expiration policy for your
     * annotation. The times for the days, weeks and months policies are
     * measured since the last visit date of the page in question. These 
     * will not expire so long as the user keeps visiting the page from time
     * to time.
     */
  enum { EXPIRE_SESSION = 0U };

  enum { EXPIRE_WEEKS = 2U };

  enum { EXPIRE_MONTHS = 3U };

  enum { EXPIRE_NEVER = 4U };

  enum { EXPIRE_WITH_HISTORY = 5U };

  enum { EXPIRE_DAYS = 6U };

  enum { TYPE_INT32 = 1U };

  enum { TYPE_DOUBLE = 2U };

  enum { TYPE_STRING = 3U };

  enum { TYPE_BINARY = 4U };

  enum { TYPE_INT64 = 5U };

  /**
     * Sets an annotation, overwriting any previous annotation with the same
     * URL/name. IT IS YOUR JOB TO NAMESPACE YOUR ANNOTATION NAMES.
     * Use the form "namespace/value", so your name would be like
     * "bills_extension/page_state" or "history/thumbnail".
     *
     * Do not use characters that are not valid in URLs such as spaces, ":",
     * commas, or most other symbols. You should stick to ASCII letters and
     * numbers plus "_", "-", and "/".
     *
     * aExpiration is one of EXPIRE_* above. aFlags should be 0 for now, some
     * flags will be defined in the future.
     *
     * NOTE: ALL ANNOTATIONS WILL GET DELETED WHEN THE PAGE IS REMOVED FROM HISTORY,
     * UNLESS YOU USE THE EXPIRE_NEVER FLAG. This means that if you create an
     * annotation on a random unvisited URI, it will get deleted when the
     * browser shuts down. Otherwise, things can exist in history as
     * annotations but the user has no way of knowing it, potentially violating
     * their privacy expectations about actions such as "Clear history." If
     * there is an important annotation that the user wants to keep, you should
     * make sure that you use EXPIRE_NEVER. This will ensure the item is never
     * completely deleted from the Places database.
     *
     * The annotation "favicon" is special. Favicons are stored in the favicon
     * service, but are special cased in the protocol handler so they look like
     * annotations. Do not set favicons using this service, it will not work.
     *
     * Binary annotations should be set using
     * setItemAnnotationBinary/setPageAnnotationBinary. For other types, only
     * C++ consumers may use the type-specific methods.
     */
  /* void setPageAnnotation (in nsIURI aURI, in AUTF8String aName, in nsIVariant aValue, in long aFlags, in unsigned short aExpiration); */
  NS_SCRIPTABLE NS_IMETHOD SetPageAnnotation(nsIURI *aURI, const nsACString & aName, nsIVariant *aValue, PRInt32 aFlags, PRUint16 aExpiration) = 0;

  /* void setItemAnnotation (in long long aItemId, in AUTF8String aName, in nsIVariant aValue, in long aFlags, in unsigned short aExpiration); */
  NS_SCRIPTABLE NS_IMETHOD SetItemAnnotation(PRInt64 aItemId, const nsACString & aName, nsIVariant *aValue, PRInt32 aFlags, PRUint16 aExpiration) = 0;

  /* [noscript] void setPageAnnotationString (in nsIURI aURI, in AUTF8String aName, in AString aValue, in long aFlags, in unsigned short aExpiration); */
  NS_IMETHOD SetPageAnnotationString(nsIURI *aURI, const nsACString & aName, const nsAString & aValue, PRInt32 aFlags, PRUint16 aExpiration) = 0;

  /* [noscript] void setItemAnnotationString (in long long aItemId, in AUTF8String aName, in AString aValue, in long aFlags, in unsigned short aExpiration); */
  NS_IMETHOD SetItemAnnotationString(PRInt64 aItemId, const nsACString & aName, const nsAString & aValue, PRInt32 aFlags, PRUint16 aExpiration) = 0;

  /**
     * Sets an annotation just like setAnnotationString, but takes an Int32 as
     * input.
     */
  /* [noscript] void setPageAnnotationInt32 (in nsIURI aURI, in AUTF8String aName, in long aValue, in long aFlags, in unsigned short aExpiration); */
  NS_IMETHOD SetPageAnnotationInt32(nsIURI *aURI, const nsACString & aName, PRInt32 aValue, PRInt32 aFlags, PRUint16 aExpiration) = 0;

  /* [noscript] void setItemAnnotationInt32 (in long long aItemId, in AUTF8String aName, in long aValue, in long aFlags, in unsigned short aExpiration); */
  NS_IMETHOD SetItemAnnotationInt32(PRInt64 aItemId, const nsACString & aName, PRInt32 aValue, PRInt32 aFlags, PRUint16 aExpiration) = 0;

  /**
     * Sets an annotation just like setAnnotationString, but takes an Int64 as
     * input.
     */
  /* [noscript] void setPageAnnotationInt64 (in nsIURI aURI, in AUTF8String aName, in long long aValue, in long aFlags, in unsigned short aExpiration); */
  NS_IMETHOD SetPageAnnotationInt64(nsIURI *aURI, const nsACString & aName, PRInt64 aValue, PRInt32 aFlags, PRUint16 aExpiration) = 0;

  /* [noscript] void setItemAnnotationInt64 (in long long aItemId, in AUTF8String aName, in long long aValue, in long aFlags, in unsigned short aExpiration); */
  NS_IMETHOD SetItemAnnotationInt64(PRInt64 aItemId, const nsACString & aName, PRInt64 aValue, PRInt32 aFlags, PRUint16 aExpiration) = 0;

  /**
     * Sets an annotation just like setAnnotationString, but takes a double as
     * input.
     */
  /* [noscript] void setPageAnnotationDouble (in nsIURI aURI, in AUTF8String aName, in double aValue, in long aFlags, in unsigned short aExpiration); */
  NS_IMETHOD SetPageAnnotationDouble(nsIURI *aURI, const nsACString & aName, double aValue, PRInt32 aFlags, PRUint16 aExpiration) = 0;

  /* [noscript] void setItemAnnotationDouble (in long long aItemId, in AUTF8String aName, in double aValue, in long aFlags, in unsigned short aExpiration); */
  NS_IMETHOD SetItemAnnotationDouble(PRInt64 aItemId, const nsACString & aName, double aValue, PRInt32 aFlags, PRUint16 aExpiration) = 0;

  /* void setPageAnnotationBinary (in nsIURI aURI, in AUTF8String aName, [array, size_is (aDataLen), const] in octet aData, in unsigned long aDataLen, in AUTF8String aMimeType, in long aFlags, in unsigned short aExpiration); */
  NS_SCRIPTABLE NS_IMETHOD SetPageAnnotationBinary(nsIURI *aURI, const nsACString & aName, const PRUint8 *aData, PRUint32 aDataLen, const nsACString & aMimeType, PRInt32 aFlags, PRUint16 aExpiration) = 0;

  /* void setItemAnnotationBinary (in long long aItemId, in AUTF8String aName, [array, size_is (aDataLen), const] in octet aData, in unsigned long aDataLen, in AUTF8String aMimeType, in long aFlags, in unsigned short aExpiration); */
  NS_SCRIPTABLE NS_IMETHOD SetItemAnnotationBinary(PRInt64 aItemId, const nsACString & aName, const PRUint8 *aData, PRUint32 aDataLen, const nsACString & aMimeType, PRInt32 aFlags, PRUint16 aExpiration) = 0;

  /**
     * Retrieves the value of a given annotation. Throws an error if the
     * annotation does not exist. Throws for binary annotations, for which
     * getPageAnnotationBinary/getItemAnnotationBinary should be used. C++
     * consumers may use the type-specific methods.
     *
     * The type-specific methods throw if the given annotation is set in
     * a different type.
     */
  /* nsIVariant getPageAnnotation (in nsIURI aURI, in AUTF8String aName); */
  NS_SCRIPTABLE NS_IMETHOD GetPageAnnotation(nsIURI *aURI, const nsACString & aName, nsIVariant **_retval NS_OUTPARAM) = 0;

  /* nsIVariant getItemAnnotation (in long long aItemId, in AUTF8String aName); */
  NS_SCRIPTABLE NS_IMETHOD GetItemAnnotation(PRInt64 aItemId, const nsACString & aName, nsIVariant **_retval NS_OUTPARAM) = 0;

  /**
     * @see getPageAnnotation
     */
  /* [noscript] AString getPageAnnotationString (in nsIURI aURI, in AUTF8String aName); */
  NS_IMETHOD GetPageAnnotationString(nsIURI *aURI, const nsACString & aName, nsAString & _retval NS_OUTPARAM) = 0;

  /* [noscript] AString getItemAnnotationString (in long long aItemId, in AUTF8String aName); */
  NS_IMETHOD GetItemAnnotationString(PRInt64 aItemId, const nsACString & aName, nsAString & _retval NS_OUTPARAM) = 0;

  /**
     * @see getPageAnnotation
     */
  /* [noscript] long getPageAnnotationInt32 (in nsIURI aURI, in AUTF8String aName); */
  NS_IMETHOD GetPageAnnotationInt32(nsIURI *aURI, const nsACString & aName, PRInt32 *_retval NS_OUTPARAM) = 0;

  /* [noscript] long getItemAnnotationInt32 (in long long aItemId, in AUTF8String aName); */
  NS_IMETHOD GetItemAnnotationInt32(PRInt64 aItemId, const nsACString & aName, PRInt32 *_retval NS_OUTPARAM) = 0;

  /**
     * @see getPageAnnotation
     */
  /* [noscript] long long getPageAnnotationInt64 (in nsIURI aURI, in AUTF8String aName); */
  NS_IMETHOD GetPageAnnotationInt64(nsIURI *aURI, const nsACString & aName, PRInt64 *_retval NS_OUTPARAM) = 0;

  /* [noscript] long long getItemAnnotationInt64 (in long long aItemId, in AUTF8String aName); */
  NS_IMETHOD GetItemAnnotationInt64(PRInt64 aItemId, const nsACString & aName, PRInt64 *_retval NS_OUTPARAM) = 0;

  /**
     * @see getPageAnnotation
     */
  /* [noscript] double getPageAnnotationDouble (in nsIURI aURI, in AUTF8String aName); */
  NS_IMETHOD GetPageAnnotationDouble(nsIURI *aURI, const nsACString & aName, double *_retval NS_OUTPARAM) = 0;

  /* [noscript] double getItemAnnotationDouble (in long long aItemId, in AUTF8String aName); */
  NS_IMETHOD GetItemAnnotationDouble(PRInt64 aItemId, const nsACString & aName, double *_retval NS_OUTPARAM) = 0;

  /**
     * @see getPageAnnotation. This also returns the
     * MIME type.
     */
  /* void getPageAnnotationBinary (in nsIURI aURI, in AUTF8String aName, [array, size_is (aDataLen)] out octet aData, out unsigned long aDataLen, out AUTF8String aMimeType); */
  NS_SCRIPTABLE NS_IMETHOD GetPageAnnotationBinary(nsIURI *aURI, const nsACString & aName, PRUint8 **aData NS_OUTPARAM, PRUint32 *aDataLen NS_OUTPARAM, nsACString & aMimeType NS_OUTPARAM) = 0;

  /* void getItemAnnotationBinary (in long long aItemId, in AUTF8String aName, [array, size_is (aDataLen)] out octet aData, out unsigned long aDataLen, out AUTF8String aMimeType); */
  NS_SCRIPTABLE NS_IMETHOD GetItemAnnotationBinary(PRInt64 aItemId, const nsACString & aName, PRUint8 **aData NS_OUTPARAM, PRUint32 *aDataLen NS_OUTPARAM, nsACString & aMimeType NS_OUTPARAM) = 0;

  /**
     * Retrieves info about an existing annotation. aMimeType will be empty
     * if the value was not binary data.
     *
     * aType will be one of TYPE_* constansts above
     *
     * example JS:
     *   var flags = {}, exp = {}, mimeType = {};
     *   annotator.getAnnotationInfo(myURI, "foo", flags, exp, mimeType);
     *   // now you can use 'exp.value' and 'flags.value'
     */
  /* void getPageAnnotationInfo (in nsIURI aURI, in AUTF8String aName, out PRInt32 aFlags, out unsigned short aExpiration, out AUTF8String aMimeType, out unsigned short aType); */
  NS_SCRIPTABLE NS_IMETHOD GetPageAnnotationInfo(nsIURI *aURI, const nsACString & aName, PRInt32 *aFlags NS_OUTPARAM, PRUint16 *aExpiration NS_OUTPARAM, nsACString & aMimeType NS_OUTPARAM, PRUint16 *aType NS_OUTPARAM) = 0;

  /* void getItemAnnotationInfo (in long long aItemId, in AUTF8String aName, out long aFlags, out unsigned short aExpiration, out AUTF8String aMimeType, out unsigned short aType); */
  NS_SCRIPTABLE NS_IMETHOD GetItemAnnotationInfo(PRInt64 aItemId, const nsACString & aName, PRInt32 *aFlags NS_OUTPARAM, PRUint16 *aExpiration NS_OUTPARAM, nsACString & aMimeType NS_OUTPARAM, PRUint16 *aType NS_OUTPARAM) = 0;

  /**
     * Retrieves the type of an existing annotation
     * Use getAnnotationInfo if you need this along with the mime-type etc.
     *
     * @param aURI
     *        the uri on which the annotation is set
     * @param aName
     *        the annotation name
     * @return one of the TYPE_* constants above
     * @throws if the annotation is not set
     */
  /* PRUint16 getPageAnnotationType (in nsIURI aURI, in AUTF8String aName); */
  NS_SCRIPTABLE NS_IMETHOD GetPageAnnotationType(nsIURI *aURI, const nsACString & aName, PRUint16 *_retval NS_OUTPARAM) = 0;

  /* PRUint16 getItemAnnotationType (in long long aItemId, in AUTF8String aName); */
  NS_SCRIPTABLE NS_IMETHOD GetItemAnnotationType(PRInt64 aItemId, const nsACString & aName, PRUint16 *_retval NS_OUTPARAM) = 0;

  /**
     * Returns a list of all URIs having a given annotation.
     */
  /* void getPagesWithAnnotation (in AUTF8String name, out unsigned long resultCount, [array, size_is (resultCount), retval] out nsIURI results); */
  NS_SCRIPTABLE NS_IMETHOD GetPagesWithAnnotation(const nsACString & name, PRUint32 *resultCount NS_OUTPARAM, nsIURI ***results NS_OUTPARAM) = 0;

  /* void getItemsWithAnnotation (in AUTF8String name, out unsigned long resultCount, [array, size_is (resultCount), retval] out long long results); */
  NS_SCRIPTABLE NS_IMETHOD GetItemsWithAnnotation(const nsACString & name, PRUint32 *resultCount NS_OUTPARAM, PRInt64 **results NS_OUTPARAM) = 0;

  /**
     * Get the names of all annotations for this URI.
     *
     * example JS:
     *   var annotations = annotator.getPageAnnotations(myURI, {});
     */
  /* void getPageAnnotationNames (in nsIURI aURI, out unsigned long count, [array, size_is (count), retval] out nsIVariant result); */
  NS_SCRIPTABLE NS_IMETHOD GetPageAnnotationNames(nsIURI *aURI, PRUint32 *count NS_OUTPARAM, nsIVariant ***result NS_OUTPARAM) = 0;

  /* void getItemAnnotationNames (in long long aItemId, out unsigned long count, [array, size_is (count), retval] out nsIVariant result); */
  NS_SCRIPTABLE NS_IMETHOD GetItemAnnotationNames(PRInt64 aItemId, PRUint32 *count NS_OUTPARAM, nsIVariant ***result NS_OUTPARAM) = 0;

  /**
     * Test for annotation existance.
     */
  /* boolean pageHasAnnotation (in nsIURI aURI, in AUTF8String aName); */
  NS_SCRIPTABLE NS_IMETHOD PageHasAnnotation(nsIURI *aURI, const nsACString & aName, PRBool *_retval NS_OUTPARAM) = 0;

  /* boolean itemHasAnnotation (in long long aItemId, in AUTF8String aName); */
  NS_SCRIPTABLE NS_IMETHOD ItemHasAnnotation(PRInt64 aItemId, const nsACString & aName, PRBool *_retval NS_OUTPARAM) = 0;

  /**
     * Removes a specific annotation. Succeeds even if the annotation is
     * not found.
     */
  /* void removePageAnnotation (in nsIURI aURI, in AUTF8String aName); */
  NS_SCRIPTABLE NS_IMETHOD RemovePageAnnotation(nsIURI *aURI, const nsACString & aName) = 0;

  /* void removeItemAnnotation (in long long aItemId, in AUTF8String aName); */
  NS_SCRIPTABLE NS_IMETHOD RemoveItemAnnotation(PRInt64 aItemId, const nsACString & aName) = 0;

  /**
     * Removes all annotations for the given page/item.
     * We may want some other similar functions to get annotations with given
     * flags (once we have flags defined).
     */
  /* void removePageAnnotations (in nsIURI aURI); */
  NS_SCRIPTABLE NS_IMETHOD RemovePageAnnotations(nsIURI *aURI) = 0;

  /* void removeItemAnnotations (in long long aItemId); */
  NS_SCRIPTABLE NS_IMETHOD RemoveItemAnnotations(PRInt64 aItemId) = 0;

  /**
     * Copies all annotations from the source to the destination URI/item. If
     * the destination already has an annotation with the same name as one on
     * the source, it will be overwritten if aOverwriteDest is set. Otherwise,
     * the destination URIs will be preferred.
     *
     * All the source annotations will stay as-is. If you don't want them
     * any more, use removePageAnnotations on that URI.
     */
  /* void copyPageAnnotations (in nsIURI aSourceURI, in nsIURI aDestURI, in boolean aOverwriteDest); */
  NS_SCRIPTABLE NS_IMETHOD CopyPageAnnotations(nsIURI *aSourceURI, nsIURI *aDestURI, PRBool aOverwriteDest) = 0;

  /* void copyItemAnnotations (in long long aSourceItemId, in long long aDestItemId, in boolean aOverwriteDest); */
  NS_SCRIPTABLE NS_IMETHOD CopyItemAnnotations(PRInt64 aSourceItemId, PRInt64 aDestItemId, PRBool aOverwriteDest) = 0;

  /**
     * Adds an annotation observer. The annotation service will keep an owning
     * reference to the observer object.
     */
  /* void addObserver (in nsIAnnotationObserver aObserver); */
  NS_SCRIPTABLE NS_IMETHOD AddObserver(nsIAnnotationObserver *aObserver) = 0;

  /**
     * Removes an annotaton observer previously registered by addObserver.
     */
  /* void removeObserver (in nsIAnnotationObserver aObserver); */
  NS_SCRIPTABLE NS_IMETHOD RemoveObserver(nsIAnnotationObserver *aObserver) = 0;

  /**
     * Returns a URI that can be used to access the given binary annotation.
     * This function does NOT check that the annotation exists. Also, note that
     * you can only load URIs for annotations that have have a valid MIME type
     * set by setAnnotationBinary. No non-URI valid chars in name, especially
     * colon, which will mess up parsing.
     */
  /* nsIURI getAnnotationURI (in nsIURI aURI, in AUTF8String aName); */
  NS_SCRIPTABLE NS_IMETHOD GetAnnotationURI(nsIURI *aURI, const nsACString & aName, nsIURI **_retval NS_OUTPARAM) = 0;

};

  NS_DEFINE_STATIC_IID_ACCESSOR(nsIAnnotationService, NS_IANNOTATIONSERVICE_IID)

/* Use this macro when declaring classes that implement this interface. */
#define NS_DECL_NSIANNOTATIONSERVICE \
  NS_SCRIPTABLE NS_IMETHOD SetPageAnnotation(nsIURI *aURI, const nsACString & aName, nsIVariant *aValue, PRInt32 aFlags, PRUint16 aExpiration); \
  NS_SCRIPTABLE NS_IMETHOD SetItemAnnotation(PRInt64 aItemId, const nsACString & aName, nsIVariant *aValue, PRInt32 aFlags, PRUint16 aExpiration); \
  NS_IMETHOD SetPageAnnotationString(nsIURI *aURI, const nsACString & aName, const nsAString & aValue, PRInt32 aFlags, PRUint16 aExpiration); \
  NS_IMETHOD SetItemAnnotationString(PRInt64 aItemId, const nsACString & aName, const nsAString & aValue, PRInt32 aFlags, PRUint16 aExpiration); \
  NS_IMETHOD SetPageAnnotationInt32(nsIURI *aURI, const nsACString & aName, PRInt32 aValue, PRInt32 aFlags, PRUint16 aExpiration); \
  NS_IMETHOD SetItemAnnotationInt32(PRInt64 aItemId, const nsACString & aName, PRInt32 aValue, PRInt32 aFlags, PRUint16 aExpiration); \
  NS_IMETHOD SetPageAnnotationInt64(nsIURI *aURI, const nsACString & aName, PRInt64 aValue, PRInt32 aFlags, PRUint16 aExpiration); \
  NS_IMETHOD SetItemAnnotationInt64(PRInt64 aItemId, const nsACString & aName, PRInt64 aValue, PRInt32 aFlags, PRUint16 aExpiration); \
  NS_IMETHOD SetPageAnnotationDouble(nsIURI *aURI, const nsACString & aName, double aValue, PRInt32 aFlags, PRUint16 aExpiration); \
  NS_IMETHOD SetItemAnnotationDouble(PRInt64 aItemId, const nsACString & aName, double aValue, PRInt32 aFlags, PRUint16 aExpiration); \
  NS_SCRIPTABLE NS_IMETHOD SetPageAnnotationBinary(nsIURI *aURI, const nsACString & aName, const PRUint8 *aData, PRUint32 aDataLen, const nsACString & aMimeType, PRInt32 aFlags, PRUint16 aExpiration); \
  NS_SCRIPTABLE NS_IMETHOD SetItemAnnotationBinary(PRInt64 aItemId, const nsACString & aName, const PRUint8 *aData, PRUint32 aDataLen, const nsACString & aMimeType, PRInt32 aFlags, PRUint16 aExpiration); \
  NS_SCRIPTABLE NS_IMETHOD GetPageAnnotation(nsIURI *aURI, const nsACString & aName, nsIVariant **_retval NS_OUTPARAM); \
  NS_SCRIPTABLE NS_IMETHOD GetItemAnnotation(PRInt64 aItemId, const nsACString & aName, nsIVariant **_retval NS_OUTPARAM); \
  NS_IMETHOD GetPageAnnotationString(nsIURI *aURI, const nsACString & aName, nsAString & _retval NS_OUTPARAM); \
  NS_IMETHOD GetItemAnnotationString(PRInt64 aItemId, const nsACString & aName, nsAString & _retval NS_OUTPARAM); \
  NS_IMETHOD GetPageAnnotationInt32(nsIURI *aURI, const nsACString & aName, PRInt32 *_retval NS_OUTPARAM); \
  NS_IMETHOD GetItemAnnotationInt32(PRInt64 aItemId, const nsACString & aName, PRInt32 *_retval NS_OUTPARAM); \
  NS_IMETHOD GetPageAnnotationInt64(nsIURI *aURI, const nsACString & aName, PRInt64 *_retval NS_OUTPARAM); \
  NS_IMETHOD GetItemAnnotationInt64(PRInt64 aItemId, const nsACString & aName, PRInt64 *_retval NS_OUTPARAM); \
  NS_IMETHOD GetPageAnnotationDouble(nsIURI *aURI, const nsACString & aName, double *_retval NS_OUTPARAM); \
  NS_IMETHOD GetItemAnnotationDouble(PRInt64 aItemId, const nsACString & aName, double *_retval NS_OUTPARAM); \
  NS_SCRIPTABLE NS_IMETHOD GetPageAnnotationBinary(nsIURI *aURI, const nsACString & aName, PRUint8 **aData NS_OUTPARAM, PRUint32 *aDataLen NS_OUTPARAM, nsACString & aMimeType NS_OUTPARAM); \
  NS_SCRIPTABLE NS_IMETHOD GetItemAnnotationBinary(PRInt64 aItemId, const nsACString & aName, PRUint8 **aData NS_OUTPARAM, PRUint32 *aDataLen NS_OUTPARAM, nsACString & aMimeType NS_OUTPARAM); \
  NS_SCRIPTABLE NS_IMETHOD GetPageAnnotationInfo(nsIURI *aURI, const nsACString & aName, PRInt32 *aFlags NS_OUTPARAM, PRUint16 *aExpiration NS_OUTPARAM, nsACString & aMimeType NS_OUTPARAM, PRUint16 *aType NS_OUTPARAM); \
  NS_SCRIPTABLE NS_IMETHOD GetItemAnnotationInfo(PRInt64 aItemId, const nsACString & aName, PRInt32 *aFlags NS_OUTPARAM, PRUint16 *aExpiration NS_OUTPARAM, nsACString & aMimeType NS_OUTPARAM, PRUint16 *aType NS_OUTPARAM); \
  NS_SCRIPTABLE NS_IMETHOD GetPageAnnotationType(nsIURI *aURI, const nsACString & aName, PRUint16 *_retval NS_OUTPARAM); \
  NS_SCRIPTABLE NS_IMETHOD GetItemAnnotationType(PRInt64 aItemId, const nsACString & aName, PRUint16 *_retval NS_OUTPARAM); \
  NS_SCRIPTABLE NS_IMETHOD GetPagesWithAnnotation(const nsACString & name, PRUint32 *resultCount NS_OUTPARAM, nsIURI ***results NS_OUTPARAM); \
  NS_SCRIPTABLE NS_IMETHOD GetItemsWithAnnotation(const nsACString & name, PRUint32 *resultCount NS_OUTPARAM, PRInt64 **results NS_OUTPARAM); \
  NS_SCRIPTABLE NS_IMETHOD GetPageAnnotationNames(nsIURI *aURI, PRUint32 *count NS_OUTPARAM, nsIVariant ***result NS_OUTPARAM); \
  NS_SCRIPTABLE NS_IMETHOD GetItemAnnotationNames(PRInt64 aItemId, PRUint32 *count NS_OUTPARAM, nsIVariant ***result NS_OUTPARAM); \
  NS_SCRIPTABLE NS_IMETHOD PageHasAnnotation(nsIURI *aURI, const nsACString & aName, PRBool *_retval NS_OUTPARAM); \
  NS_SCRIPTABLE NS_IMETHOD ItemHasAnnotation(PRInt64 aItemId, const nsACString & aName, PRBool *_retval NS_OUTPARAM); \
  NS_SCRIPTABLE NS_IMETHOD RemovePageAnnotation(nsIURI *aURI, const nsACString & aName); \
  NS_SCRIPTABLE NS_IMETHOD RemoveItemAnnotation(PRInt64 aItemId, const nsACString & aName); \
  NS_SCRIPTABLE NS_IMETHOD RemovePageAnnotations(nsIURI *aURI); \
  NS_SCRIPTABLE NS_IMETHOD RemoveItemAnnotations(PRInt64 aItemId); \
  NS_SCRIPTABLE NS_IMETHOD CopyPageAnnotations(nsIURI *aSourceURI, nsIURI *aDestURI, PRBool aOverwriteDest); \
  NS_SCRIPTABLE NS_IMETHOD CopyItemAnnotations(PRInt64 aSourceItemId, PRInt64 aDestItemId, PRBool aOverwriteDest); \
  NS_SCRIPTABLE NS_IMETHOD AddObserver(nsIAnnotationObserver *aObserver); \
  NS_SCRIPTABLE NS_IMETHOD RemoveObserver(nsIAnnotationObserver *aObserver); \
  NS_SCRIPTABLE NS_IMETHOD GetAnnotationURI(nsIURI *aURI, const nsACString & aName, nsIURI **_retval NS_OUTPARAM); 

/* Use this macro to declare functions that forward the behavior of this interface to another object. */
#define NS_FORWARD_NSIANNOTATIONSERVICE(_to) \
  NS_SCRIPTABLE NS_IMETHOD SetPageAnnotation(nsIURI *aURI, const nsACString & aName, nsIVariant *aValue, PRInt32 aFlags, PRUint16 aExpiration) { return _to SetPageAnnotation(aURI, aName, aValue, aFlags, aExpiration); } \
  NS_SCRIPTABLE NS_IMETHOD SetItemAnnotation(PRInt64 aItemId, const nsACString & aName, nsIVariant *aValue, PRInt32 aFlags, PRUint16 aExpiration) { return _to SetItemAnnotation(aItemId, aName, aValue, aFlags, aExpiration); } \
  NS_IMETHOD SetPageAnnotationString(nsIURI *aURI, const nsACString & aName, const nsAString & aValue, PRInt32 aFlags, PRUint16 aExpiration) { return _to SetPageAnnotationString(aURI, aName, aValue, aFlags, aExpiration); } \
  NS_IMETHOD SetItemAnnotationString(PRInt64 aItemId, const nsACString & aName, const nsAString & aValue, PRInt32 aFlags, PRUint16 aExpiration) { return _to SetItemAnnotationString(aItemId, aName, aValue, aFlags, aExpiration); } \
  NS_IMETHOD SetPageAnnotationInt32(nsIURI *aURI, const nsACString & aName, PRInt32 aValue, PRInt32 aFlags, PRUint16 aExpiration) { return _to SetPageAnnotationInt32(aURI, aName, aValue, aFlags, aExpiration); } \
  NS_IMETHOD SetItemAnnotationInt32(PRInt64 aItemId, const nsACString & aName, PRInt32 aValue, PRInt32 aFlags, PRUint16 aExpiration) { return _to SetItemAnnotationInt32(aItemId, aName, aValue, aFlags, aExpiration); } \
  NS_IMETHOD SetPageAnnotationInt64(nsIURI *aURI, const nsACString & aName, PRInt64 aValue, PRInt32 aFlags, PRUint16 aExpiration) { return _to SetPageAnnotationInt64(aURI, aName, aValue, aFlags, aExpiration); } \
  NS_IMETHOD SetItemAnnotationInt64(PRInt64 aItemId, const nsACString & aName, PRInt64 aValue, PRInt32 aFlags, PRUint16 aExpiration) { return _to SetItemAnnotationInt64(aItemId, aName, aValue, aFlags, aExpiration); } \
  NS_IMETHOD SetPageAnnotationDouble(nsIURI *aURI, const nsACString & aName, double aValue, PRInt32 aFlags, PRUint16 aExpiration) { return _to SetPageAnnotationDouble(aURI, aName, aValue, aFlags, aExpiration); } \
  NS_IMETHOD SetItemAnnotationDouble(PRInt64 aItemId, const nsACString & aName, double aValue, PRInt32 aFlags, PRUint16 aExpiration) { return _to SetItemAnnotationDouble(aItemId, aName, aValue, aFlags, aExpiration); } \
  NS_SCRIPTABLE NS_IMETHOD SetPageAnnotationBinary(nsIURI *aURI, const nsACString & aName, const PRUint8 *aData, PRUint32 aDataLen, const nsACString & aMimeType, PRInt32 aFlags, PRUint16 aExpiration) { return _to SetPageAnnotationBinary(aURI, aName, aData, aDataLen, aMimeType, aFlags, aExpiration); } \
  NS_SCRIPTABLE NS_IMETHOD SetItemAnnotationBinary(PRInt64 aItemId, const nsACString & aName, const PRUint8 *aData, PRUint32 aDataLen, const nsACString & aMimeType, PRInt32 aFlags, PRUint16 aExpiration) { return _to SetItemAnnotationBinary(aItemId, aName, aData, aDataLen, aMimeType, aFlags, aExpiration); } \
  NS_SCRIPTABLE NS_IMETHOD GetPageAnnotation(nsIURI *aURI, const nsACString & aName, nsIVariant **_retval NS_OUTPARAM) { return _to GetPageAnnotation(aURI, aName, _retval); } \
  NS_SCRIPTABLE NS_IMETHOD GetItemAnnotation(PRInt64 aItemId, const nsACString & aName, nsIVariant **_retval NS_OUTPARAM) { return _to GetItemAnnotation(aItemId, aName, _retval); } \
  NS_IMETHOD GetPageAnnotationString(nsIURI *aURI, const nsACString & aName, nsAString & _retval NS_OUTPARAM) { return _to GetPageAnnotationString(aURI, aName, _retval); } \
  NS_IMETHOD GetItemAnnotationString(PRInt64 aItemId, const nsACString & aName, nsAString & _retval NS_OUTPARAM) { return _to GetItemAnnotationString(aItemId, aName, _retval); } \
  NS_IMETHOD GetPageAnnotationInt32(nsIURI *aURI, const nsACString & aName, PRInt32 *_retval NS_OUTPARAM) { return _to GetPageAnnotationInt32(aURI, aName, _retval); } \
  NS_IMETHOD GetItemAnnotationInt32(PRInt64 aItemId, const nsACString & aName, PRInt32 *_retval NS_OUTPARAM) { return _to GetItemAnnotationInt32(aItemId, aName, _retval); } \
  NS_IMETHOD GetPageAnnotationInt64(nsIURI *aURI, const nsACString & aName, PRInt64 *_retval NS_OUTPARAM) { return _to GetPageAnnotationInt64(aURI, aName, _retval); } \
  NS_IMETHOD GetItemAnnotationInt64(PRInt64 aItemId, const nsACString & aName, PRInt64 *_retval NS_OUTPARAM) { return _to GetItemAnnotationInt64(aItemId, aName, _retval); } \
  NS_IMETHOD GetPageAnnotationDouble(nsIURI *aURI, const nsACString & aName, double *_retval NS_OUTPARAM) { return _to GetPageAnnotationDouble(aURI, aName, _retval); } \
  NS_IMETHOD GetItemAnnotationDouble(PRInt64 aItemId, const nsACString & aName, double *_retval NS_OUTPARAM) { return _to GetItemAnnotationDouble(aItemId, aName, _retval); } \
  NS_SCRIPTABLE NS_IMETHOD GetPageAnnotationBinary(nsIURI *aURI, const nsACString & aName, PRUint8 **aData NS_OUTPARAM, PRUint32 *aDataLen NS_OUTPARAM, nsACString & aMimeType NS_OUTPARAM) { return _to GetPageAnnotationBinary(aURI, aName, aData, aDataLen, aMimeType); } \
  NS_SCRIPTABLE NS_IMETHOD GetItemAnnotationBinary(PRInt64 aItemId, const nsACString & aName, PRUint8 **aData NS_OUTPARAM, PRUint32 *aDataLen NS_OUTPARAM, nsACString & aMimeType NS_OUTPARAM) { return _to GetItemAnnotationBinary(aItemId, aName, aData, aDataLen, aMimeType); } \
  NS_SCRIPTABLE NS_IMETHOD GetPageAnnotationInfo(nsIURI *aURI, const nsACString & aName, PRInt32 *aFlags NS_OUTPARAM, PRUint16 *aExpiration NS_OUTPARAM, nsACString & aMimeType NS_OUTPARAM, PRUint16 *aType NS_OUTPARAM) { return _to GetPageAnnotationInfo(aURI, aName, aFlags, aExpiration, aMimeType, aType); } \
  NS_SCRIPTABLE NS_IMETHOD GetItemAnnotationInfo(PRInt64 aItemId, const nsACString & aName, PRInt32 *aFlags NS_OUTPARAM, PRUint16 *aExpiration NS_OUTPARAM, nsACString & aMimeType NS_OUTPARAM, PRUint16 *aType NS_OUTPARAM) { return _to GetItemAnnotationInfo(aItemId, aName, aFlags, aExpiration, aMimeType, aType); } \
  NS_SCRIPTABLE NS_IMETHOD GetPageAnnotationType(nsIURI *aURI, const nsACString & aName, PRUint16 *_retval NS_OUTPARAM) { return _to GetPageAnnotationType(aURI, aName, _retval); } \
  NS_SCRIPTABLE NS_IMETHOD GetItemAnnotationType(PRInt64 aItemId, const nsACString & aName, PRUint16 *_retval NS_OUTPARAM) { return _to GetItemAnnotationType(aItemId, aName, _retval); } \
  NS_SCRIPTABLE NS_IMETHOD GetPagesWithAnnotation(const nsACString & name, PRUint32 *resultCount NS_OUTPARAM, nsIURI ***results NS_OUTPARAM) { return _to GetPagesWithAnnotation(name, resultCount, results); } \
  NS_SCRIPTABLE NS_IMETHOD GetItemsWithAnnotation(const nsACString & name, PRUint32 *resultCount NS_OUTPARAM, PRInt64 **results NS_OUTPARAM) { return _to GetItemsWithAnnotation(name, resultCount, results); } \
  NS_SCRIPTABLE NS_IMETHOD GetPageAnnotationNames(nsIURI *aURI, PRUint32 *count NS_OUTPARAM, nsIVariant ***result NS_OUTPARAM) { return _to GetPageAnnotationNames(aURI, count, result); } \
  NS_SCRIPTABLE NS_IMETHOD GetItemAnnotationNames(PRInt64 aItemId, PRUint32 *count NS_OUTPARAM, nsIVariant ***result NS_OUTPARAM) { return _to GetItemAnnotationNames(aItemId, count, result); } \
  NS_SCRIPTABLE NS_IMETHOD PageHasAnnotation(nsIURI *aURI, const nsACString & aName, PRBool *_retval NS_OUTPARAM) { return _to PageHasAnnotation(aURI, aName, _retval); } \
  NS_SCRIPTABLE NS_IMETHOD ItemHasAnnotation(PRInt64 aItemId, const nsACString & aName, PRBool *_retval NS_OUTPARAM) { return _to ItemHasAnnotation(aItemId, aName, _retval); } \
  NS_SCRIPTABLE NS_IMETHOD RemovePageAnnotation(nsIURI *aURI, const nsACString & aName) { return _to RemovePageAnnotation(aURI, aName); } \
  NS_SCRIPTABLE NS_IMETHOD RemoveItemAnnotation(PRInt64 aItemId, const nsACString & aName) { return _to RemoveItemAnnotation(aItemId, aName); } \
  NS_SCRIPTABLE NS_IMETHOD RemovePageAnnotations(nsIURI *aURI) { return _to RemovePageAnnotations(aURI); } \
  NS_SCRIPTABLE NS_IMETHOD RemoveItemAnnotations(PRInt64 aItemId) { return _to RemoveItemAnnotations(aItemId); } \
  NS_SCRIPTABLE NS_IMETHOD CopyPageAnnotations(nsIURI *aSourceURI, nsIURI *aDestURI, PRBool aOverwriteDest) { return _to CopyPageAnnotations(aSourceURI, aDestURI, aOverwriteDest); } \
  NS_SCRIPTABLE NS_IMETHOD CopyItemAnnotations(PRInt64 aSourceItemId, PRInt64 aDestItemId, PRBool aOverwriteDest) { return _to CopyItemAnnotations(aSourceItemId, aDestItemId, aOverwriteDest); } \
  NS_SCRIPTABLE NS_IMETHOD AddObserver(nsIAnnotationObserver *aObserver) { return _to AddObserver(aObserver); } \
  NS_SCRIPTABLE NS_IMETHOD RemoveObserver(nsIAnnotationObserver *aObserver) { return _to RemoveObserver(aObserver); } \
  NS_SCRIPTABLE NS_IMETHOD GetAnnotationURI(nsIURI *aURI, const nsACString & aName, nsIURI **_retval NS_OUTPARAM) { return _to GetAnnotationURI(aURI, aName, _retval); } 

/* Use this macro to declare functions that forward the behavior of this interface to another object in a safe way. */
#define NS_FORWARD_SAFE_NSIANNOTATIONSERVICE(_to) \
  NS_SCRIPTABLE NS_IMETHOD SetPageAnnotation(nsIURI *aURI, const nsACString & aName, nsIVariant *aValue, PRInt32 aFlags, PRUint16 aExpiration) { return !_to ? NS_ERROR_NULL_POINTER : _to->SetPageAnnotation(aURI, aName, aValue, aFlags, aExpiration); } \
  NS_SCRIPTABLE NS_IMETHOD SetItemAnnotation(PRInt64 aItemId, const nsACString & aName, nsIVariant *aValue, PRInt32 aFlags, PRUint16 aExpiration) { return !_to ? NS_ERROR_NULL_POINTER : _to->SetItemAnnotation(aItemId, aName, aValue, aFlags, aExpiration); } \
  NS_IMETHOD SetPageAnnotationString(nsIURI *aURI, const nsACString & aName, const nsAString & aValue, PRInt32 aFlags, PRUint16 aExpiration) { return !_to ? NS_ERROR_NULL_POINTER : _to->SetPageAnnotationString(aURI, aName, aValue, aFlags, aExpiration); } \
  NS_IMETHOD SetItemAnnotationString(PRInt64 aItemId, const nsACString & aName, const nsAString & aValue, PRInt32 aFlags, PRUint16 aExpiration) { return !_to ? NS_ERROR_NULL_POINTER : _to->SetItemAnnotationString(aItemId, aName, aValue, aFlags, aExpiration); } \
  NS_IMETHOD SetPageAnnotationInt32(nsIURI *aURI, const nsACString & aName, PRInt32 aValue, PRInt32 aFlags, PRUint16 aExpiration) { return !_to ? NS_ERROR_NULL_POINTER : _to->SetPageAnnotationInt32(aURI, aName, aValue, aFlags, aExpiration); } \
  NS_IMETHOD SetItemAnnotationInt32(PRInt64 aItemId, const nsACString & aName, PRInt32 aValue, PRInt32 aFlags, PRUint16 aExpiration) { return !_to ? NS_ERROR_NULL_POINTER : _to->SetItemAnnotationInt32(aItemId, aName, aValue, aFlags, aExpiration); } \
  NS_IMETHOD SetPageAnnotationInt64(nsIURI *aURI, const nsACString & aName, PRInt64 aValue, PRInt32 aFlags, PRUint16 aExpiration) { return !_to ? NS_ERROR_NULL_POINTER : _to->SetPageAnnotationInt64(aURI, aName, aValue, aFlags, aExpiration); } \
  NS_IMETHOD SetItemAnnotationInt64(PRInt64 aItemId, const nsACString & aName, PRInt64 aValue, PRInt32 aFlags, PRUint16 aExpiration) { return !_to ? NS_ERROR_NULL_POINTER : _to->SetItemAnnotationInt64(aItemId, aName, aValue, aFlags, aExpiration); } \
  NS_IMETHOD SetPageAnnotationDouble(nsIURI *aURI, const nsACString & aName, double aValue, PRInt32 aFlags, PRUint16 aExpiration) { return !_to ? NS_ERROR_NULL_POINTER : _to->SetPageAnnotationDouble(aURI, aName, aValue, aFlags, aExpiration); } \
  NS_IMETHOD SetItemAnnotationDouble(PRInt64 aItemId, const nsACString & aName, double aValue, PRInt32 aFlags, PRUint16 aExpiration) { return !_to ? NS_ERROR_NULL_POINTER : _to->SetItemAnnotationDouble(aItemId, aName, aValue, aFlags, aExpiration); } \
  NS_SCRIPTABLE NS_IMETHOD SetPageAnnotationBinary(nsIURI *aURI, const nsACString & aName, const PRUint8 *aData, PRUint32 aDataLen, const nsACString & aMimeType, PRInt32 aFlags, PRUint16 aExpiration) { return !_to ? NS_ERROR_NULL_POINTER : _to->SetPageAnnotationBinary(aURI, aName, aData, aDataLen, aMimeType, aFlags, aExpiration); } \
  NS_SCRIPTABLE NS_IMETHOD SetItemAnnotationBinary(PRInt64 aItemId, const nsACString & aName, const PRUint8 *aData, PRUint32 aDataLen, const nsACString & aMimeType, PRInt32 aFlags, PRUint16 aExpiration) { return !_to ? NS_ERROR_NULL_POINTER : _to->SetItemAnnotationBinary(aItemId, aName, aData, aDataLen, aMimeType, aFlags, aExpiration); } \
  NS_SCRIPTABLE NS_IMETHOD GetPageAnnotation(nsIURI *aURI, const nsACString & aName, nsIVariant **_retval NS_OUTPARAM) { return !_to ? NS_ERROR_NULL_POINTER : _to->GetPageAnnotation(aURI, aName, _retval); } \
  NS_SCRIPTABLE NS_IMETHOD GetItemAnnotation(PRInt64 aItemId, const nsACString & aName, nsIVariant **_retval NS_OUTPARAM) { return !_to ? NS_ERROR_NULL_POINTER : _to->GetItemAnnotation(aItemId, aName, _retval); } \
  NS_IMETHOD GetPageAnnotationString(nsIURI *aURI, const nsACString & aName, nsAString & _retval NS_OUTPARAM) { return !_to ? NS_ERROR_NULL_POINTER : _to->GetPageAnnotationString(aURI, aName, _retval); } \
  NS_IMETHOD GetItemAnnotationString(PRInt64 aItemId, const nsACString & aName, nsAString & _retval NS_OUTPARAM) { return !_to ? NS_ERROR_NULL_POINTER : _to->GetItemAnnotationString(aItemId, aName, _retval); } \
  NS_IMETHOD GetPageAnnotationInt32(nsIURI *aURI, const nsACString & aName, PRInt32 *_retval NS_OUTPARAM) { return !_to ? NS_ERROR_NULL_POINTER : _to->GetPageAnnotationInt32(aURI, aName, _retval); } \
  NS_IMETHOD GetItemAnnotationInt32(PRInt64 aItemId, const nsACString & aName, PRInt32 *_retval NS_OUTPARAM) { return !_to ? NS_ERROR_NULL_POINTER : _to->GetItemAnnotationInt32(aItemId, aName, _retval); } \
  NS_IMETHOD GetPageAnnotationInt64(nsIURI *aURI, const nsACString & aName, PRInt64 *_retval NS_OUTPARAM) { return !_to ? NS_ERROR_NULL_POINTER : _to->GetPageAnnotationInt64(aURI, aName, _retval); } \
  NS_IMETHOD GetItemAnnotationInt64(PRInt64 aItemId, const nsACString & aName, PRInt64 *_retval NS_OUTPARAM) { return !_to ? NS_ERROR_NULL_POINTER : _to->GetItemAnnotationInt64(aItemId, aName, _retval); } \
  NS_IMETHOD GetPageAnnotationDouble(nsIURI *aURI, const nsACString & aName, double *_retval NS_OUTPARAM) { return !_to ? NS_ERROR_NULL_POINTER : _to->GetPageAnnotationDouble(aURI, aName, _retval); } \
  NS_IMETHOD GetItemAnnotationDouble(PRInt64 aItemId, const nsACString & aName, double *_retval NS_OUTPARAM) { return !_to ? NS_ERROR_NULL_POINTER : _to->GetItemAnnotationDouble(aItemId, aName, _retval); } \
  NS_SCRIPTABLE NS_IMETHOD GetPageAnnotationBinary(nsIURI *aURI, const nsACString & aName, PRUint8 **aData NS_OUTPARAM, PRUint32 *aDataLen NS_OUTPARAM, nsACString & aMimeType NS_OUTPARAM) { return !_to ? NS_ERROR_NULL_POINTER : _to->GetPageAnnotationBinary(aURI, aName, aData, aDataLen, aMimeType); } \
  NS_SCRIPTABLE NS_IMETHOD GetItemAnnotationBinary(PRInt64 aItemId, const nsACString & aName, PRUint8 **aData NS_OUTPARAM, PRUint32 *aDataLen NS_OUTPARAM, nsACString & aMimeType NS_OUTPARAM) { return !_to ? NS_ERROR_NULL_POINTER : _to->GetItemAnnotationBinary(aItemId, aName, aData, aDataLen, aMimeType); } \
  NS_SCRIPTABLE NS_IMETHOD GetPageAnnotationInfo(nsIURI *aURI, const nsACString & aName, PRInt32 *aFlags NS_OUTPARAM, PRUint16 *aExpiration NS_OUTPARAM, nsACString & aMimeType NS_OUTPARAM, PRUint16 *aType NS_OUTPARAM) { return !_to ? NS_ERROR_NULL_POINTER : _to->GetPageAnnotationInfo(aURI, aName, aFlags, aExpiration, aMimeType, aType); } \
  NS_SCRIPTABLE NS_IMETHOD GetItemAnnotationInfo(PRInt64 aItemId, const nsACString & aName, PRInt32 *aFlags NS_OUTPARAM, PRUint16 *aExpiration NS_OUTPARAM, nsACString & aMimeType NS_OUTPARAM, PRUint16 *aType NS_OUTPARAM) { return !_to ? NS_ERROR_NULL_POINTER : _to->GetItemAnnotationInfo(aItemId, aName, aFlags, aExpiration, aMimeType, aType); } \
  NS_SCRIPTABLE NS_IMETHOD GetPageAnnotationType(nsIURI *aURI, const nsACString & aName, PRUint16 *_retval NS_OUTPARAM) { return !_to ? NS_ERROR_NULL_POINTER : _to->GetPageAnnotationType(aURI, aName, _retval); } \
  NS_SCRIPTABLE NS_IMETHOD GetItemAnnotationType(PRInt64 aItemId, const nsACString & aName, PRUint16 *_retval NS_OUTPARAM) { return !_to ? NS_ERROR_NULL_POINTER : _to->GetItemAnnotationType(aItemId, aName, _retval); } \
  NS_SCRIPTABLE NS_IMETHOD GetPagesWithAnnotation(const nsACString & name, PRUint32 *resultCount NS_OUTPARAM, nsIURI ***results NS_OUTPARAM) { return !_to ? NS_ERROR_NULL_POINTER : _to->GetPagesWithAnnotation(name, resultCount, results); } \
  NS_SCRIPTABLE NS_IMETHOD GetItemsWithAnnotation(const nsACString & name, PRUint32 *resultCount NS_OUTPARAM, PRInt64 **results NS_OUTPARAM) { return !_to ? NS_ERROR_NULL_POINTER : _to->GetItemsWithAnnotation(name, resultCount, results); } \
  NS_SCRIPTABLE NS_IMETHOD GetPageAnnotationNames(nsIURI *aURI, PRUint32 *count NS_OUTPARAM, nsIVariant ***result NS_OUTPARAM) { return !_to ? NS_ERROR_NULL_POINTER : _to->GetPageAnnotationNames(aURI, count, result); } \
  NS_SCRIPTABLE NS_IMETHOD GetItemAnnotationNames(PRInt64 aItemId, PRUint32 *count NS_OUTPARAM, nsIVariant ***result NS_OUTPARAM) { return !_to ? NS_ERROR_NULL_POINTER : _to->GetItemAnnotationNames(aItemId, count, result); } \
  NS_SCRIPTABLE NS_IMETHOD PageHasAnnotation(nsIURI *aURI, const nsACString & aName, PRBool *_retval NS_OUTPARAM) { return !_to ? NS_ERROR_NULL_POINTER : _to->PageHasAnnotation(aURI, aName, _retval); } \
  NS_SCRIPTABLE NS_IMETHOD ItemHasAnnotation(PRInt64 aItemId, const nsACString & aName, PRBool *_retval NS_OUTPARAM) { return !_to ? NS_ERROR_NULL_POINTER : _to->ItemHasAnnotation(aItemId, aName, _retval); } \
  NS_SCRIPTABLE NS_IMETHOD RemovePageAnnotation(nsIURI *aURI, const nsACString & aName) { return !_to ? NS_ERROR_NULL_POINTER : _to->RemovePageAnnotation(aURI, aName); } \
  NS_SCRIPTABLE NS_IMETHOD RemoveItemAnnotation(PRInt64 aItemId, const nsACString & aName) { return !_to ? NS_ERROR_NULL_POINTER : _to->RemoveItemAnnotation(aItemId, aName); } \
  NS_SCRIPTABLE NS_IMETHOD RemovePageAnnotations(nsIURI *aURI) { return !_to ? NS_ERROR_NULL_POINTER : _to->RemovePageAnnotations(aURI); } \
  NS_SCRIPTABLE NS_IMETHOD RemoveItemAnnotations(PRInt64 aItemId) { return !_to ? NS_ERROR_NULL_POINTER : _to->RemoveItemAnnotations(aItemId); } \
  NS_SCRIPTABLE NS_IMETHOD CopyPageAnnotations(nsIURI *aSourceURI, nsIURI *aDestURI, PRBool aOverwriteDest) { return !_to ? NS_ERROR_NULL_POINTER : _to->CopyPageAnnotations(aSourceURI, aDestURI, aOverwriteDest); } \
  NS_SCRIPTABLE NS_IMETHOD CopyItemAnnotations(PRInt64 aSourceItemId, PRInt64 aDestItemId, PRBool aOverwriteDest) { return !_to ? NS_ERROR_NULL_POINTER : _to->CopyItemAnnotations(aSourceItemId, aDestItemId, aOverwriteDest); } \
  NS_SCRIPTABLE NS_IMETHOD AddObserver(nsIAnnotationObserver *aObserver) { return !_to ? NS_ERROR_NULL_POINTER : _to->AddObserver(aObserver); } \
  NS_SCRIPTABLE NS_IMETHOD RemoveObserver(nsIAnnotationObserver *aObserver) { return !_to ? NS_ERROR_NULL_POINTER : _to->RemoveObserver(aObserver); } \
  NS_SCRIPTABLE NS_IMETHOD GetAnnotationURI(nsIURI *aURI, const nsACString & aName, nsIURI **_retval NS_OUTPARAM) { return !_to ? NS_ERROR_NULL_POINTER : _to->GetAnnotationURI(aURI, aName, _retval); } 

#if 0
/* Use the code below as a template for the implementation class for this interface. */

/* Header file */
class nsAnnotationService : public nsIAnnotationService
{
public:
  NS_DECL_ISUPPORTS
  NS_DECL_NSIANNOTATIONSERVICE

  nsAnnotationService();

private:
  ~nsAnnotationService();

protected:
  /* additional members */
};

/* Implementation file */
NS_IMPL_ISUPPORTS1(nsAnnotationService, nsIAnnotationService)

nsAnnotationService::nsAnnotationService()
{
  /* member initializers and constructor code */
}

nsAnnotationService::~nsAnnotationService()
{
  /* destructor code */
}

/* void setPageAnnotation (in nsIURI aURI, in AUTF8String aName, in nsIVariant aValue, in long aFlags, in unsigned short aExpiration); */
NS_IMETHODIMP nsAnnotationService::SetPageAnnotation(nsIURI *aURI, const nsACString & aName, nsIVariant *aValue, PRInt32 aFlags, PRUint16 aExpiration)
{
    return NS_ERROR_NOT_IMPLEMENTED;
}

/* void setItemAnnotation (in long long aItemId, in AUTF8String aName, in nsIVariant aValue, in long aFlags, in unsigned short aExpiration); */
NS_IMETHODIMP nsAnnotationService::SetItemAnnotation(PRInt64 aItemId, const nsACString & aName, nsIVariant *aValue, PRInt32 aFlags, PRUint16 aExpiration)
{
    return NS_ERROR_NOT_IMPLEMENTED;
}

/* [noscript] void setPageAnnotationString (in nsIURI aURI, in AUTF8String aName, in AString aValue, in long aFlags, in unsigned short aExpiration); */
NS_IMETHODIMP nsAnnotationService::SetPageAnnotationString(nsIURI *aURI, const nsACString & aName, const nsAString & aValue, PRInt32 aFlags, PRUint16 aExpiration)
{
    return NS_ERROR_NOT_IMPLEMENTED;
}

/* [noscript] void setItemAnnotationString (in long long aItemId, in AUTF8String aName, in AString aValue, in long aFlags, in unsigned short aExpiration); */
NS_IMETHODIMP nsAnnotationService::SetItemAnnotationString(PRInt64 aItemId, const nsACString & aName, const nsAString & aValue, PRInt32 aFlags, PRUint16 aExpiration)
{
    return NS_ERROR_NOT_IMPLEMENTED;
}

/* [noscript] void setPageAnnotationInt32 (in nsIURI aURI, in AUTF8String aName, in long aValue, in long aFlags, in unsigned short aExpiration); */
NS_IMETHODIMP nsAnnotationService::SetPageAnnotationInt32(nsIURI *aURI, const nsACString & aName, PRInt32 aValue, PRInt32 aFlags, PRUint16 aExpiration)
{
    return NS_ERROR_NOT_IMPLEMENTED;
}

/* [noscript] void setItemAnnotationInt32 (in long long aItemId, in AUTF8String aName, in long aValue, in long aFlags, in unsigned short aExpiration); */
NS_IMETHODIMP nsAnnotationService::SetItemAnnotationInt32(PRInt64 aItemId, const nsACString & aName, PRInt32 aValue, PRInt32 aFlags, PRUint16 aExpiration)
{
    return NS_ERROR_NOT_IMPLEMENTED;
}

/* [noscript] void setPageAnnotationInt64 (in nsIURI aURI, in AUTF8String aName, in long long aValue, in long aFlags, in unsigned short aExpiration); */
NS_IMETHODIMP nsAnnotationService::SetPageAnnotationInt64(nsIURI *aURI, const nsACString & aName, PRInt64 aValue, PRInt32 aFlags, PRUint16 aExpiration)
{
    return NS_ERROR_NOT_IMPLEMENTED;
}

/* [noscript] void setItemAnnotationInt64 (in long long aItemId, in AUTF8String aName, in long long aValue, in long aFlags, in unsigned short aExpiration); */
NS_IMETHODIMP nsAnnotationService::SetItemAnnotationInt64(PRInt64 aItemId, const nsACString & aName, PRInt64 aValue, PRInt32 aFlags, PRUint16 aExpiration)
{
    return NS_ERROR_NOT_IMPLEMENTED;
}

/* [noscript] void setPageAnnotationDouble (in nsIURI aURI, in AUTF8String aName, in double aValue, in long aFlags, in unsigned short aExpiration); */
NS_IMETHODIMP nsAnnotationService::SetPageAnnotationDouble(nsIURI *aURI, const nsACString & aName, double aValue, PRInt32 aFlags, PRUint16 aExpiration)
{
    return NS_ERROR_NOT_IMPLEMENTED;
}

/* [noscript] void setItemAnnotationDouble (in long long aItemId, in AUTF8String aName, in double aValue, in long aFlags, in unsigned short aExpiration); */
NS_IMETHODIMP nsAnnotationService::SetItemAnnotationDouble(PRInt64 aItemId, const nsACString & aName, double aValue, PRInt32 aFlags, PRUint16 aExpiration)
{
    return NS_ERROR_NOT_IMPLEMENTED;
}

/* void setPageAnnotationBinary (in nsIURI aURI, in AUTF8String aName, [array, size_is (aDataLen), const] in octet aData, in unsigned long aDataLen, in AUTF8String aMimeType, in long aFlags, in unsigned short aExpiration); */
NS_IMETHODIMP nsAnnotationService::SetPageAnnotationBinary(nsIURI *aURI, const nsACString & aName, const PRUint8 *aData, PRUint32 aDataLen, const nsACString & aMimeType, PRInt32 aFlags, PRUint16 aExpiration)
{
    return NS_ERROR_NOT_IMPLEMENTED;
}

/* void setItemAnnotationBinary (in long long aItemId, in AUTF8String aName, [array, size_is (aDataLen), const] in octet aData, in unsigned long aDataLen, in AUTF8String aMimeType, in long aFlags, in unsigned short aExpiration); */
NS_IMETHODIMP nsAnnotationService::SetItemAnnotationBinary(PRInt64 aItemId, const nsACString & aName, const PRUint8 *aData, PRUint32 aDataLen, const nsACString & aMimeType, PRInt32 aFlags, PRUint16 aExpiration)
{
    return NS_ERROR_NOT_IMPLEMENTED;
}

/* nsIVariant getPageAnnotation (in nsIURI aURI, in AUTF8String aName); */
NS_IMETHODIMP nsAnnotationService::GetPageAnnotation(nsIURI *aURI, const nsACString & aName, nsIVariant **_retval NS_OUTPARAM)
{
    return NS_ERROR_NOT_IMPLEMENTED;
}

/* nsIVariant getItemAnnotation (in long long aItemId, in AUTF8String aName); */
NS_IMETHODIMP nsAnnotationService::GetItemAnnotation(PRInt64 aItemId, const nsACString & aName, nsIVariant **_retval NS_OUTPARAM)
{
    return NS_ERROR_NOT_IMPLEMENTED;
}

/* [noscript] AString getPageAnnotationString (in nsIURI aURI, in AUTF8String aName); */
NS_IMETHODIMP nsAnnotationService::GetPageAnnotationString(nsIURI *aURI, const nsACString & aName, nsAString & _retval NS_OUTPARAM)
{
    return NS_ERROR_NOT_IMPLEMENTED;
}

/* [noscript] AString getItemAnnotationString (in long long aItemId, in AUTF8String aName); */
NS_IMETHODIMP nsAnnotationService::GetItemAnnotationString(PRInt64 aItemId, const nsACString & aName, nsAString & _retval NS_OUTPARAM)
{
    return NS_ERROR_NOT_IMPLEMENTED;
}

/* [noscript] long getPageAnnotationInt32 (in nsIURI aURI, in AUTF8String aName); */
NS_IMETHODIMP nsAnnotationService::GetPageAnnotationInt32(nsIURI *aURI, const nsACString & aName, PRInt32 *_retval NS_OUTPARAM)
{
    return NS_ERROR_NOT_IMPLEMENTED;
}

/* [noscript] long getItemAnnotationInt32 (in long long aItemId, in AUTF8String aName); */
NS_IMETHODIMP nsAnnotationService::GetItemAnnotationInt32(PRInt64 aItemId, const nsACString & aName, PRInt32 *_retval NS_OUTPARAM)
{
    return NS_ERROR_NOT_IMPLEMENTED;
}

/* [noscript] long long getPageAnnotationInt64 (in nsIURI aURI, in AUTF8String aName); */
NS_IMETHODIMP nsAnnotationService::GetPageAnnotationInt64(nsIURI *aURI, const nsACString & aName, PRInt64 *_retval NS_OUTPARAM)
{
    return NS_ERROR_NOT_IMPLEMENTED;
}

/* [noscript] long long getItemAnnotationInt64 (in long long aItemId, in AUTF8String aName); */
NS_IMETHODIMP nsAnnotationService::GetItemAnnotationInt64(PRInt64 aItemId, const nsACString & aName, PRInt64 *_retval NS_OUTPARAM)
{
    return NS_ERROR_NOT_IMPLEMENTED;
}

/* [noscript] double getPageAnnotationDouble (in nsIURI aURI, in AUTF8String aName); */
NS_IMETHODIMP nsAnnotationService::GetPageAnnotationDouble(nsIURI *aURI, const nsACString & aName, double *_retval NS_OUTPARAM)
{
    return NS_ERROR_NOT_IMPLEMENTED;
}

/* [noscript] double getItemAnnotationDouble (in long long aItemId, in AUTF8String aName); */
NS_IMETHODIMP nsAnnotationService::GetItemAnnotationDouble(PRInt64 aItemId, const nsACString & aName, double *_retval NS_OUTPARAM)
{
    return NS_ERROR_NOT_IMPLEMENTED;
}

/* void getPageAnnotationBinary (in nsIURI aURI, in AUTF8String aName, [array, size_is (aDataLen)] out octet aData, out unsigned long aDataLen, out AUTF8String aMimeType); */
NS_IMETHODIMP nsAnnotationService::GetPageAnnotationBinary(nsIURI *aURI, const nsACString & aName, PRUint8 **aData NS_OUTPARAM, PRUint32 *aDataLen NS_OUTPARAM, nsACString & aMimeType NS_OUTPARAM)
{
    return NS_ERROR_NOT_IMPLEMENTED;
}

/* void getItemAnnotationBinary (in long long aItemId, in AUTF8String aName, [array, size_is (aDataLen)] out octet aData, out unsigned long aDataLen, out AUTF8String aMimeType); */
NS_IMETHODIMP nsAnnotationService::GetItemAnnotationBinary(PRInt64 aItemId, const nsACString & aName, PRUint8 **aData NS_OUTPARAM, PRUint32 *aDataLen NS_OUTPARAM, nsACString & aMimeType NS_OUTPARAM)
{
    return NS_ERROR_NOT_IMPLEMENTED;
}

/* void getPageAnnotationInfo (in nsIURI aURI, in AUTF8String aName, out PRInt32 aFlags, out unsigned short aExpiration, out AUTF8String aMimeType, out unsigned short aType); */
NS_IMETHODIMP nsAnnotationService::GetPageAnnotationInfo(nsIURI *aURI, const nsACString & aName, PRInt32 *aFlags NS_OUTPARAM, PRUint16 *aExpiration NS_OUTPARAM, nsACString & aMimeType NS_OUTPARAM, PRUint16 *aType NS_OUTPARAM)
{
    return NS_ERROR_NOT_IMPLEMENTED;
}

/* void getItemAnnotationInfo (in long long aItemId, in AUTF8String aName, out long aFlags, out unsigned short aExpiration, out AUTF8String aMimeType, out unsigned short aType); */
NS_IMETHODIMP nsAnnotationService::GetItemAnnotationInfo(PRInt64 aItemId, const nsACString & aName, PRInt32 *aFlags NS_OUTPARAM, PRUint16 *aExpiration NS_OUTPARAM, nsACString & aMimeType NS_OUTPARAM, PRUint16 *aType NS_OUTPARAM)
{
    return NS_ERROR_NOT_IMPLEMENTED;
}

/* PRUint16 getPageAnnotationType (in nsIURI aURI, in AUTF8String aName); */
NS_IMETHODIMP nsAnnotationService::GetPageAnnotationType(nsIURI *aURI, const nsACString & aName, PRUint16 *_retval NS_OUTPARAM)
{
    return NS_ERROR_NOT_IMPLEMENTED;
}

/* PRUint16 getItemAnnotationType (in long long aItemId, in AUTF8String aName); */
NS_IMETHODIMP nsAnnotationService::GetItemAnnotationType(PRInt64 aItemId, const nsACString & aName, PRUint16 *_retval NS_OUTPARAM)
{
    return NS_ERROR_NOT_IMPLEMENTED;
}

/* void getPagesWithAnnotation (in AUTF8String name, out unsigned long resultCount, [array, size_is (resultCount), retval] out nsIURI results); */
NS_IMETHODIMP nsAnnotationService::GetPagesWithAnnotation(const nsACString & name, PRUint32 *resultCount NS_OUTPARAM, nsIURI ***results NS_OUTPARAM)
{
    return NS_ERROR_NOT_IMPLEMENTED;
}

/* void getItemsWithAnnotation (in AUTF8String name, out unsigned long resultCount, [array, size_is (resultCount), retval] out long long results); */
NS_IMETHODIMP nsAnnotationService::GetItemsWithAnnotation(const nsACString & name, PRUint32 *resultCount NS_OUTPARAM, PRInt64 **results NS_OUTPARAM)
{
    return NS_ERROR_NOT_IMPLEMENTED;
}

/* void getPageAnnotationNames (in nsIURI aURI, out unsigned long count, [array, size_is (count), retval] out nsIVariant result); */
NS_IMETHODIMP nsAnnotationService::GetPageAnnotationNames(nsIURI *aURI, PRUint32 *count NS_OUTPARAM, nsIVariant ***result NS_OUTPARAM)
{
    return NS_ERROR_NOT_IMPLEMENTED;
}

/* void getItemAnnotationNames (in long long aItemId, out unsigned long count, [array, size_is (count), retval] out nsIVariant result); */
NS_IMETHODIMP nsAnnotationService::GetItemAnnotationNames(PRInt64 aItemId, PRUint32 *count NS_OUTPARAM, nsIVariant ***result NS_OUTPARAM)
{
    return NS_ERROR_NOT_IMPLEMENTED;
}

/* boolean pageHasAnnotation (in nsIURI aURI, in AUTF8String aName); */
NS_IMETHODIMP nsAnnotationService::PageHasAnnotation(nsIURI *aURI, const nsACString & aName, PRBool *_retval NS_OUTPARAM)
{
    return NS_ERROR_NOT_IMPLEMENTED;
}

/* boolean itemHasAnnotation (in long long aItemId, in AUTF8String aName); */
NS_IMETHODIMP nsAnnotationService::ItemHasAnnotation(PRInt64 aItemId, const nsACString & aName, PRBool *_retval NS_OUTPARAM)
{
    return NS_ERROR_NOT_IMPLEMENTED;
}

/* void removePageAnnotation (in nsIURI aURI, in AUTF8String aName); */
NS_IMETHODIMP nsAnnotationService::RemovePageAnnotation(nsIURI *aURI, const nsACString & aName)
{
    return NS_ERROR_NOT_IMPLEMENTED;
}

/* void removeItemAnnotation (in long long aItemId, in AUTF8String aName); */
NS_IMETHODIMP nsAnnotationService::RemoveItemAnnotation(PRInt64 aItemId, const nsACString & aName)
{
    return NS_ERROR_NOT_IMPLEMENTED;
}

/* void removePageAnnotations (in nsIURI aURI); */
NS_IMETHODIMP nsAnnotationService::RemovePageAnnotations(nsIURI *aURI)
{
    return NS_ERROR_NOT_IMPLEMENTED;
}

/* void removeItemAnnotations (in long long aItemId); */
NS_IMETHODIMP nsAnnotationService::RemoveItemAnnotations(PRInt64 aItemId)
{
    return NS_ERROR_NOT_IMPLEMENTED;
}

/* void copyPageAnnotations (in nsIURI aSourceURI, in nsIURI aDestURI, in boolean aOverwriteDest); */
NS_IMETHODIMP nsAnnotationService::CopyPageAnnotations(nsIURI *aSourceURI, nsIURI *aDestURI, PRBool aOverwriteDest)
{
    return NS_ERROR_NOT_IMPLEMENTED;
}

/* void copyItemAnnotations (in long long aSourceItemId, in long long aDestItemId, in boolean aOverwriteDest); */
NS_IMETHODIMP nsAnnotationService::CopyItemAnnotations(PRInt64 aSourceItemId, PRInt64 aDestItemId, PRBool aOverwriteDest)
{
    return NS_ERROR_NOT_IMPLEMENTED;
}

/* void addObserver (in nsIAnnotationObserver aObserver); */
NS_IMETHODIMP nsAnnotationService::AddObserver(nsIAnnotationObserver *aObserver)
{
    return NS_ERROR_NOT_IMPLEMENTED;
}

/* void removeObserver (in nsIAnnotationObserver aObserver); */
NS_IMETHODIMP nsAnnotationService::RemoveObserver(nsIAnnotationObserver *aObserver)
{
    return NS_ERROR_NOT_IMPLEMENTED;
}

/* nsIURI getAnnotationURI (in nsIURI aURI, in AUTF8String aName); */
NS_IMETHODIMP nsAnnotationService::GetAnnotationURI(nsIURI *aURI, const nsACString & aName, nsIURI **_retval NS_OUTPARAM)
{
    return NS_ERROR_NOT_IMPLEMENTED;
}

/* End of implementation class template. */
#endif


#endif /* __gen_nsIAnnotationService_h__ */
