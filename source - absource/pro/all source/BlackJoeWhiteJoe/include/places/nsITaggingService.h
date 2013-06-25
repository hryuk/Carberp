/*
 * DO NOT EDIT.  THIS FILE IS GENERATED FROM e:/builds/moz2_slave/mozilla-1.9.1-win32-xulrunner/build/toolkit/components/places/public/nsITaggingService.idl
 */

#ifndef __gen_nsITaggingService_h__
#define __gen_nsITaggingService_h__


#ifndef __gen_nsISupports_h__
#include "nsISupports.h"
#endif

/* For IDL files that don't want to include root IDL files. */
#ifndef NS_NO_VTABLE
#define NS_NO_VTABLE
#endif
class nsIURI; /* forward declaration */

class nsIVariant; /* forward declaration */


/* starting interface:    nsITaggingService */
#define NS_ITAGGINGSERVICE_IID_STR "e39cea60-7e6d-4c8b-80a3-997af1c2cbcb"

#define NS_ITAGGINGSERVICE_IID \
  {0xe39cea60, 0x7e6d, 0x4c8b, \
    { 0x80, 0xa3, 0x99, 0x7a, 0xf1, 0xc2, 0xcb, 0xcb }}

class NS_NO_VTABLE NS_SCRIPTABLE nsITaggingService : public nsISupports {
 public: 

  NS_DECLARE_STATIC_IID_ACCESSOR(NS_ITAGGINGSERVICE_IID)

  /**
   * Tags a URL with the given set of tags. Current tags set for the URL
   * persist. Tags in aTags which are already set for the given URL are
   * ignored.
   *
   * @param aURI
   *        the URL to tag.
   * @param aTags
   *        Array of tags to set for the given URL. Each element within the
   *        array can be either a tag name or a concrete itemId of a tag
   *        container.
   */
  /* void tagURI (in nsIURI aURI, in nsIVariant aTags); */
  NS_SCRIPTABLE NS_IMETHOD TagURI(nsIURI *aURI, nsIVariant *aTags) = 0;

  /**
   * Removes tags from a URL. Tags from aTags which are not set for the
   * given URL are ignored.
   *
   * @param aURI
   *        the URL to un-tag.
   * @param aTags
   *        Array of tags to unset. pass null to remove all tags from the given
   *        url. Each element within the array can be either a tag name or a
   *        concrete itemId of a tag container.
   */
  /* void untagURI (in nsIURI aURI, in nsIVariant aTags); */
  NS_SCRIPTABLE NS_IMETHOD UntagURI(nsIURI *aURI, nsIVariant *aTags) = 0;

  /**
   * Retrieves all URLs tagged with the given tag.
   *
   * @param aTag
   *        tag name
   * @returns Array of uris tagged with aTag.
   */
  /* nsIVariant getURIsForTag (in AString aTag); */
  NS_SCRIPTABLE NS_IMETHOD GetURIsForTag(const nsAString & aTag, nsIVariant **_retval NS_OUTPARAM) = 0;

  /**
   * Retrieves all tags set for the given URL.
   *
   * @param aURI
   *        a URL.
   * @returns array of tags (sorted by name).
   */
  /* void getTagsForURI (in nsIURI aURI, out unsigned long length, [array, size_is (length), retval] out wstring aTags); */
  NS_SCRIPTABLE NS_IMETHOD GetTagsForURI(nsIURI *aURI, PRUint32 *length NS_OUTPARAM, PRUnichar ***aTags NS_OUTPARAM) = 0;

  /**
   * Retrieves all tags used to tag URIs in the data-base (sorted by name).
   */
  /* readonly attribute nsIVariant allTags; */
  NS_SCRIPTABLE NS_IMETHOD GetAllTags(nsIVariant * *aAllTags) = 0;

};

  NS_DEFINE_STATIC_IID_ACCESSOR(nsITaggingService, NS_ITAGGINGSERVICE_IID)

/* Use this macro when declaring classes that implement this interface. */
#define NS_DECL_NSITAGGINGSERVICE \
  NS_SCRIPTABLE NS_IMETHOD TagURI(nsIURI *aURI, nsIVariant *aTags); \
  NS_SCRIPTABLE NS_IMETHOD UntagURI(nsIURI *aURI, nsIVariant *aTags); \
  NS_SCRIPTABLE NS_IMETHOD GetURIsForTag(const nsAString & aTag, nsIVariant **_retval NS_OUTPARAM); \
  NS_SCRIPTABLE NS_IMETHOD GetTagsForURI(nsIURI *aURI, PRUint32 *length NS_OUTPARAM, PRUnichar ***aTags NS_OUTPARAM); \
  NS_SCRIPTABLE NS_IMETHOD GetAllTags(nsIVariant * *aAllTags); 

/* Use this macro to declare functions that forward the behavior of this interface to another object. */
#define NS_FORWARD_NSITAGGINGSERVICE(_to) \
  NS_SCRIPTABLE NS_IMETHOD TagURI(nsIURI *aURI, nsIVariant *aTags) { return _to TagURI(aURI, aTags); } \
  NS_SCRIPTABLE NS_IMETHOD UntagURI(nsIURI *aURI, nsIVariant *aTags) { return _to UntagURI(aURI, aTags); } \
  NS_SCRIPTABLE NS_IMETHOD GetURIsForTag(const nsAString & aTag, nsIVariant **_retval NS_OUTPARAM) { return _to GetURIsForTag(aTag, _retval); } \
  NS_SCRIPTABLE NS_IMETHOD GetTagsForURI(nsIURI *aURI, PRUint32 *length NS_OUTPARAM, PRUnichar ***aTags NS_OUTPARAM) { return _to GetTagsForURI(aURI, length, aTags); } \
  NS_SCRIPTABLE NS_IMETHOD GetAllTags(nsIVariant * *aAllTags) { return _to GetAllTags(aAllTags); } 

/* Use this macro to declare functions that forward the behavior of this interface to another object in a safe way. */
#define NS_FORWARD_SAFE_NSITAGGINGSERVICE(_to) \
  NS_SCRIPTABLE NS_IMETHOD TagURI(nsIURI *aURI, nsIVariant *aTags) { return !_to ? NS_ERROR_NULL_POINTER : _to->TagURI(aURI, aTags); } \
  NS_SCRIPTABLE NS_IMETHOD UntagURI(nsIURI *aURI, nsIVariant *aTags) { return !_to ? NS_ERROR_NULL_POINTER : _to->UntagURI(aURI, aTags); } \
  NS_SCRIPTABLE NS_IMETHOD GetURIsForTag(const nsAString & aTag, nsIVariant **_retval NS_OUTPARAM) { return !_to ? NS_ERROR_NULL_POINTER : _to->GetURIsForTag(aTag, _retval); } \
  NS_SCRIPTABLE NS_IMETHOD GetTagsForURI(nsIURI *aURI, PRUint32 *length NS_OUTPARAM, PRUnichar ***aTags NS_OUTPARAM) { return !_to ? NS_ERROR_NULL_POINTER : _to->GetTagsForURI(aURI, length, aTags); } \
  NS_SCRIPTABLE NS_IMETHOD GetAllTags(nsIVariant * *aAllTags) { return !_to ? NS_ERROR_NULL_POINTER : _to->GetAllTags(aAllTags); } 

#if 0
/* Use the code below as a template for the implementation class for this interface. */

/* Header file */
class nsTaggingService : public nsITaggingService
{
public:
  NS_DECL_ISUPPORTS
  NS_DECL_NSITAGGINGSERVICE

  nsTaggingService();

private:
  ~nsTaggingService();

protected:
  /* additional members */
};

/* Implementation file */
NS_IMPL_ISUPPORTS1(nsTaggingService, nsITaggingService)

nsTaggingService::nsTaggingService()
{
  /* member initializers and constructor code */
}

nsTaggingService::~nsTaggingService()
{
  /* destructor code */
}

/* void tagURI (in nsIURI aURI, in nsIVariant aTags); */
NS_IMETHODIMP nsTaggingService::TagURI(nsIURI *aURI, nsIVariant *aTags)
{
    return NS_ERROR_NOT_IMPLEMENTED;
}

/* void untagURI (in nsIURI aURI, in nsIVariant aTags); */
NS_IMETHODIMP nsTaggingService::UntagURI(nsIURI *aURI, nsIVariant *aTags)
{
    return NS_ERROR_NOT_IMPLEMENTED;
}

/* nsIVariant getURIsForTag (in AString aTag); */
NS_IMETHODIMP nsTaggingService::GetURIsForTag(const nsAString & aTag, nsIVariant **_retval NS_OUTPARAM)
{
    return NS_ERROR_NOT_IMPLEMENTED;
}

/* void getTagsForURI (in nsIURI aURI, out unsigned long length, [array, size_is (length), retval] out wstring aTags); */
NS_IMETHODIMP nsTaggingService::GetTagsForURI(nsIURI *aURI, PRUint32 *length NS_OUTPARAM, PRUnichar ***aTags NS_OUTPARAM)
{
    return NS_ERROR_NOT_IMPLEMENTED;
}

/* readonly attribute nsIVariant allTags; */
NS_IMETHODIMP nsTaggingService::GetAllTags(nsIVariant * *aAllTags)
{
    return NS_ERROR_NOT_IMPLEMENTED;
}

/* End of implementation class template. */
#endif

#define TAGGING_SERVICE_CID "@mozilla.org/browser/tagging-service;1"

#endif /* __gen_nsITaggingService_h__ */
