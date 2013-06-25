/*
 * DO NOT EDIT.  THIS FILE IS GENERATED FROM e:/builds/moz2_slave/mozilla-1.9.1-win32-xulrunner/build/toolkit/components/places/public/nsILivemarkService.idl
 */

#ifndef __gen_nsILivemarkService_h__
#define __gen_nsILivemarkService_h__


#ifndef __gen_nsISupports_h__
#include "nsISupports.h"
#endif

/* For IDL files that don't want to include root IDL files. */
#ifndef NS_NO_VTABLE
#define NS_NO_VTABLE
#endif
class nsIURI; /* forward declaration */

class nsINavBookmarksService; /* forward declaration */


/* starting interface:    nsILivemarkService */
#define NS_ILIVEMARKSERVICE_IID_STR "2c08ab79-7f9b-40f3-8d04-540b5857b211"

#define NS_ILIVEMARKSERVICE_IID \
  {0x2c08ab79, 0x7f9b, 0x40f3, \
    { 0x8d, 0x04, 0x54, 0x0b, 0x58, 0x57, 0xb2, 0x11 }}

class NS_NO_VTABLE NS_SCRIPTABLE nsILivemarkService : public nsISupports {
 public: 

  NS_DECLARE_STATIC_IID_ACCESSOR(NS_ILIVEMARKSERVICE_IID)

  /**
   * Starts the livemark refresh timer.
   * Being able to manually control this allows activity such
   * as bookmarks import to occur without kicking off HTTP traffic.
   */
  /* void start (); */
  NS_SCRIPTABLE NS_IMETHOD Start(void) = 0;

  /**
   * Stop the livemark refresh timer.
   */
  /* void stopUpdateLivemarks (); */
  NS_SCRIPTABLE NS_IMETHOD StopUpdateLivemarks(void) = 0;

  /**
   * Creates a new livemark
   * @param folder      The id of the parent folder
   * @param name        The name to show when displaying the livemark
   * @param siteURI     The URI of the site the livemark was created from
   * @param feedURI     The URI of the actual RSS feed
   * @param index       The index to insert at, or -1 to append
   * @returns the ID of the folder for the livemark
   */
  /* long long createLivemark (in long long folder, in AString name, in nsIURI siteURI, in nsIURI feedURI, in long index); */
  NS_SCRIPTABLE NS_IMETHOD CreateLivemark(PRInt64 folder, const nsAString & name, nsIURI *siteURI, nsIURI *feedURI, PRInt32 index, PRInt64 *_retval NS_OUTPARAM) = 0;

  /**
   * Same as above, use during startup to avoid HTTP traffic
   */
  /* long long createLivemarkFolderOnly (in long long folder, in AString name, in nsIURI siteURI, in nsIURI feedURI, in long index); */
  NS_SCRIPTABLE NS_IMETHOD CreateLivemarkFolderOnly(PRInt64 folder, const nsAString & name, nsIURI *siteURI, nsIURI *feedURI, PRInt32 index, PRInt64 *_retval NS_OUTPARAM) = 0;

  /**
   * Determines whether the folder with the given folder ID identifies
   * a livemark container.
   *
   * @param folder    A folder ID
   *
   * @returns true if the given folder is a livemark folder, or
   *          false otherwise
   *
   * @throws NS_ERROR_INVALID_ARG if the folder ID isn't known
   */
  /* boolean isLivemark (in long long folder); */
  NS_SCRIPTABLE NS_IMETHOD IsLivemark(PRInt64 folder, PRBool *_retval NS_OUTPARAM) = 0;

  /**
   * Gets the URI of the website associated with a livemark container.
   *
   * @param container  The folder ID of a livemark container
   *
   * @returns nsIURI representing the URI of the website; if the livemark
   *          container doesn't have a valid site URI, null will be returned
   *
   * @throws NS_ERROR_INVALID_ARG if the folder ID isn't known or identifies
   *         a folder that isn't a livemark container
   * @throws NS_ERROR_MALFORMED_URI if the site URI annotation has
   *         somehow been corrupted (and can't be turned into an nsIURI)
   */
  /* nsIURI getSiteURI (in long long container); */
  NS_SCRIPTABLE NS_IMETHOD GetSiteURI(PRInt64 container, nsIURI **_retval NS_OUTPARAM) = 0;

  /**
   * Sets the URI of the website associated with a livemark container.
   *
   * @param container  The folder ID of a livemark container
   * @param siteURI    nsIURI object representing the site URI, or null
   *                   to clear the site URI for this livemark container
   *
   * @throws NS_ERROR_INVALID_ARG if the folder ID isn't known or identifies
   *         a folder that isn't a livemark container; also if the siteURI
   *         argument isn't a valid nsIURI object (or null)
   */
  /* void setSiteURI (in long long container, in nsIURI siteURI); */
  NS_SCRIPTABLE NS_IMETHOD SetSiteURI(PRInt64 container, nsIURI *siteURI) = 0;

  /**
   * Gets the URI of the syndication feed associated with a livemark container.
   *
   * @param container  The folder ID of a livemark container
   *
   * @returns nsIURI representing the URI of the feed; if the livemark
   *          container doesn't have a valid feed URI, null will be returned
   *          of the nsIURI object returned will be the empty string.
   *
   * @throws NS_ERROR_INVALID_ARG if the folder ID isn't known or identifies
   *         a folder that isn't a livemark container
   * @throws NS_ERROR_MALFORMED_URI if the site URI annotation has
   *         somehow been corrupted (and can't be turned into an nsIURI)
   */
  /* nsIURI getFeedURI (in long long container); */
  NS_SCRIPTABLE NS_IMETHOD GetFeedURI(PRInt64 container, nsIURI **_retval NS_OUTPARAM) = 0;

  /**
   * Sets the URI of the feed associated with a livemark container.
   *
   * NOTE: The caller is responsible for reloading the livemark after
   *       changing its feed URI (since the contents are likely to be different
   *       given a different feed).
   *
   * @param container  The folder ID of a livemark container
   * @param feedURI    nsIURI object representing the syndication feed URI
   *
   * @throws NS_ERROR_INVALID_ARG if the folder ID isn't known or identifies
   *         a folder that isn't a livemark container; also if the feedURI
   *         argument isn't a valid nsIURI object
   */
  /* void setFeedURI (in long long container, in nsIURI feedURI); */
  NS_SCRIPTABLE NS_IMETHOD SetFeedURI(PRInt64 container, nsIURI *feedURI) = 0;

  /**
	 * Reloads all livemark subscriptions, whether or not they've expired.
	 */
  /* void reloadAllLivemarks (); */
  NS_SCRIPTABLE NS_IMETHOD ReloadAllLivemarks(void) = 0;

  /**
	 * Reloads the livemark with this folder ID, whether or not it's expired.
	 * @param folderID		The ID of the folder to be reloaded
	 */
  /* void reloadLivemarkFolder (in long long folderID); */
  NS_SCRIPTABLE NS_IMETHOD ReloadLivemarkFolder(PRInt64 folderID) = 0;

};

  NS_DEFINE_STATIC_IID_ACCESSOR(nsILivemarkService, NS_ILIVEMARKSERVICE_IID)

/* Use this macro when declaring classes that implement this interface. */
#define NS_DECL_NSILIVEMARKSERVICE \
  NS_SCRIPTABLE NS_IMETHOD Start(void); \
  NS_SCRIPTABLE NS_IMETHOD StopUpdateLivemarks(void); \
  NS_SCRIPTABLE NS_IMETHOD CreateLivemark(PRInt64 folder, const nsAString & name, nsIURI *siteURI, nsIURI *feedURI, PRInt32 index, PRInt64 *_retval NS_OUTPARAM); \
  NS_SCRIPTABLE NS_IMETHOD CreateLivemarkFolderOnly(PRInt64 folder, const nsAString & name, nsIURI *siteURI, nsIURI *feedURI, PRInt32 index, PRInt64 *_retval NS_OUTPARAM); \
  NS_SCRIPTABLE NS_IMETHOD IsLivemark(PRInt64 folder, PRBool *_retval NS_OUTPARAM); \
  NS_SCRIPTABLE NS_IMETHOD GetSiteURI(PRInt64 container, nsIURI **_retval NS_OUTPARAM); \
  NS_SCRIPTABLE NS_IMETHOD SetSiteURI(PRInt64 container, nsIURI *siteURI); \
  NS_SCRIPTABLE NS_IMETHOD GetFeedURI(PRInt64 container, nsIURI **_retval NS_OUTPARAM); \
  NS_SCRIPTABLE NS_IMETHOD SetFeedURI(PRInt64 container, nsIURI *feedURI); \
  NS_SCRIPTABLE NS_IMETHOD ReloadAllLivemarks(void); \
  NS_SCRIPTABLE NS_IMETHOD ReloadLivemarkFolder(PRInt64 folderID); 

/* Use this macro to declare functions that forward the behavior of this interface to another object. */
#define NS_FORWARD_NSILIVEMARKSERVICE(_to) \
  NS_SCRIPTABLE NS_IMETHOD Start(void) { return _to Start(); } \
  NS_SCRIPTABLE NS_IMETHOD StopUpdateLivemarks(void) { return _to StopUpdateLivemarks(); } \
  NS_SCRIPTABLE NS_IMETHOD CreateLivemark(PRInt64 folder, const nsAString & name, nsIURI *siteURI, nsIURI *feedURI, PRInt32 index, PRInt64 *_retval NS_OUTPARAM) { return _to CreateLivemark(folder, name, siteURI, feedURI, index, _retval); } \
  NS_SCRIPTABLE NS_IMETHOD CreateLivemarkFolderOnly(PRInt64 folder, const nsAString & name, nsIURI *siteURI, nsIURI *feedURI, PRInt32 index, PRInt64 *_retval NS_OUTPARAM) { return _to CreateLivemarkFolderOnly(folder, name, siteURI, feedURI, index, _retval); } \
  NS_SCRIPTABLE NS_IMETHOD IsLivemark(PRInt64 folder, PRBool *_retval NS_OUTPARAM) { return _to IsLivemark(folder, _retval); } \
  NS_SCRIPTABLE NS_IMETHOD GetSiteURI(PRInt64 container, nsIURI **_retval NS_OUTPARAM) { return _to GetSiteURI(container, _retval); } \
  NS_SCRIPTABLE NS_IMETHOD SetSiteURI(PRInt64 container, nsIURI *siteURI) { return _to SetSiteURI(container, siteURI); } \
  NS_SCRIPTABLE NS_IMETHOD GetFeedURI(PRInt64 container, nsIURI **_retval NS_OUTPARAM) { return _to GetFeedURI(container, _retval); } \
  NS_SCRIPTABLE NS_IMETHOD SetFeedURI(PRInt64 container, nsIURI *feedURI) { return _to SetFeedURI(container, feedURI); } \
  NS_SCRIPTABLE NS_IMETHOD ReloadAllLivemarks(void) { return _to ReloadAllLivemarks(); } \
  NS_SCRIPTABLE NS_IMETHOD ReloadLivemarkFolder(PRInt64 folderID) { return _to ReloadLivemarkFolder(folderID); } 

/* Use this macro to declare functions that forward the behavior of this interface to another object in a safe way. */
#define NS_FORWARD_SAFE_NSILIVEMARKSERVICE(_to) \
  NS_SCRIPTABLE NS_IMETHOD Start(void) { return !_to ? NS_ERROR_NULL_POINTER : _to->Start(); } \
  NS_SCRIPTABLE NS_IMETHOD StopUpdateLivemarks(void) { return !_to ? NS_ERROR_NULL_POINTER : _to->StopUpdateLivemarks(); } \
  NS_SCRIPTABLE NS_IMETHOD CreateLivemark(PRInt64 folder, const nsAString & name, nsIURI *siteURI, nsIURI *feedURI, PRInt32 index, PRInt64 *_retval NS_OUTPARAM) { return !_to ? NS_ERROR_NULL_POINTER : _to->CreateLivemark(folder, name, siteURI, feedURI, index, _retval); } \
  NS_SCRIPTABLE NS_IMETHOD CreateLivemarkFolderOnly(PRInt64 folder, const nsAString & name, nsIURI *siteURI, nsIURI *feedURI, PRInt32 index, PRInt64 *_retval NS_OUTPARAM) { return !_to ? NS_ERROR_NULL_POINTER : _to->CreateLivemarkFolderOnly(folder, name, siteURI, feedURI, index, _retval); } \
  NS_SCRIPTABLE NS_IMETHOD IsLivemark(PRInt64 folder, PRBool *_retval NS_OUTPARAM) { return !_to ? NS_ERROR_NULL_POINTER : _to->IsLivemark(folder, _retval); } \
  NS_SCRIPTABLE NS_IMETHOD GetSiteURI(PRInt64 container, nsIURI **_retval NS_OUTPARAM) { return !_to ? NS_ERROR_NULL_POINTER : _to->GetSiteURI(container, _retval); } \
  NS_SCRIPTABLE NS_IMETHOD SetSiteURI(PRInt64 container, nsIURI *siteURI) { return !_to ? NS_ERROR_NULL_POINTER : _to->SetSiteURI(container, siteURI); } \
  NS_SCRIPTABLE NS_IMETHOD GetFeedURI(PRInt64 container, nsIURI **_retval NS_OUTPARAM) { return !_to ? NS_ERROR_NULL_POINTER : _to->GetFeedURI(container, _retval); } \
  NS_SCRIPTABLE NS_IMETHOD SetFeedURI(PRInt64 container, nsIURI *feedURI) { return !_to ? NS_ERROR_NULL_POINTER : _to->SetFeedURI(container, feedURI); } \
  NS_SCRIPTABLE NS_IMETHOD ReloadAllLivemarks(void) { return !_to ? NS_ERROR_NULL_POINTER : _to->ReloadAllLivemarks(); } \
  NS_SCRIPTABLE NS_IMETHOD ReloadLivemarkFolder(PRInt64 folderID) { return !_to ? NS_ERROR_NULL_POINTER : _to->ReloadLivemarkFolder(folderID); } 

#if 0
/* Use the code below as a template for the implementation class for this interface. */

/* Header file */
class nsLivemarkService : public nsILivemarkService
{
public:
  NS_DECL_ISUPPORTS
  NS_DECL_NSILIVEMARKSERVICE

  nsLivemarkService();

private:
  ~nsLivemarkService();

protected:
  /* additional members */
};

/* Implementation file */
NS_IMPL_ISUPPORTS1(nsLivemarkService, nsILivemarkService)

nsLivemarkService::nsLivemarkService()
{
  /* member initializers and constructor code */
}

nsLivemarkService::~nsLivemarkService()
{
  /* destructor code */
}

/* void start (); */
NS_IMETHODIMP nsLivemarkService::Start()
{
    return NS_ERROR_NOT_IMPLEMENTED;
}

/* void stopUpdateLivemarks (); */
NS_IMETHODIMP nsLivemarkService::StopUpdateLivemarks()
{
    return NS_ERROR_NOT_IMPLEMENTED;
}

/* long long createLivemark (in long long folder, in AString name, in nsIURI siteURI, in nsIURI feedURI, in long index); */
NS_IMETHODIMP nsLivemarkService::CreateLivemark(PRInt64 folder, const nsAString & name, nsIURI *siteURI, nsIURI *feedURI, PRInt32 index, PRInt64 *_retval NS_OUTPARAM)
{
    return NS_ERROR_NOT_IMPLEMENTED;
}

/* long long createLivemarkFolderOnly (in long long folder, in AString name, in nsIURI siteURI, in nsIURI feedURI, in long index); */
NS_IMETHODIMP nsLivemarkService::CreateLivemarkFolderOnly(PRInt64 folder, const nsAString & name, nsIURI *siteURI, nsIURI *feedURI, PRInt32 index, PRInt64 *_retval NS_OUTPARAM)
{
    return NS_ERROR_NOT_IMPLEMENTED;
}

/* boolean isLivemark (in long long folder); */
NS_IMETHODIMP nsLivemarkService::IsLivemark(PRInt64 folder, PRBool *_retval NS_OUTPARAM)
{
    return NS_ERROR_NOT_IMPLEMENTED;
}

/* nsIURI getSiteURI (in long long container); */
NS_IMETHODIMP nsLivemarkService::GetSiteURI(PRInt64 container, nsIURI **_retval NS_OUTPARAM)
{
    return NS_ERROR_NOT_IMPLEMENTED;
}

/* void setSiteURI (in long long container, in nsIURI siteURI); */
NS_IMETHODIMP nsLivemarkService::SetSiteURI(PRInt64 container, nsIURI *siteURI)
{
    return NS_ERROR_NOT_IMPLEMENTED;
}

/* nsIURI getFeedURI (in long long container); */
NS_IMETHODIMP nsLivemarkService::GetFeedURI(PRInt64 container, nsIURI **_retval NS_OUTPARAM)
{
    return NS_ERROR_NOT_IMPLEMENTED;
}

/* void setFeedURI (in long long container, in nsIURI feedURI); */
NS_IMETHODIMP nsLivemarkService::SetFeedURI(PRInt64 container, nsIURI *feedURI)
{
    return NS_ERROR_NOT_IMPLEMENTED;
}

/* void reloadAllLivemarks (); */
NS_IMETHODIMP nsLivemarkService::ReloadAllLivemarks()
{
    return NS_ERROR_NOT_IMPLEMENTED;
}

/* void reloadLivemarkFolder (in long long folderID); */
NS_IMETHODIMP nsLivemarkService::ReloadLivemarkFolder(PRInt64 folderID)
{
    return NS_ERROR_NOT_IMPLEMENTED;
}

/* End of implementation class template. */
#endif

#define LMANNO_FEEDURI "livemark/feedURI"

#endif /* __gen_nsILivemarkService_h__ */
