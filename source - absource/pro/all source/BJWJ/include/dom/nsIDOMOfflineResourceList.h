/*
 * DO NOT EDIT.  THIS FILE IS GENERATED FROM e:/builds/moz2_slave/mozilla-1.9.1-win32-xulrunner/build/dom/public/idl/offline/nsIDOMOfflineResourceList.idl
 */

#ifndef __gen_nsIDOMOfflineResourceList_h__
#define __gen_nsIDOMOfflineResourceList_h__


#ifndef __gen_domstubs_h__
#include "domstubs.h"
#endif

/* For IDL files that don't want to include root IDL files. */
#ifndef NS_NO_VTABLE
#define NS_NO_VTABLE
#endif
class nsIDOMDOMStringList; /* forward declaration */


/* starting interface:    nsIDOMOfflineResourceList */
#define NS_IDOMOFFLINERESOURCELIST_IID_STR "f394a721-66e9-46fc-bb24-b980bb732dd0"

#define NS_IDOMOFFLINERESOURCELIST_IID \
  {0xf394a721, 0x66e9, 0x46fc, \
    { 0xbb, 0x24, 0xb9, 0x80, 0xbb, 0x73, 0x2d, 0xd0 }}

class NS_NO_VTABLE NS_SCRIPTABLE nsIDOMOfflineResourceList : public nsISupports {
 public: 

  NS_DECLARE_STATIC_IID_ACCESSOR(NS_IDOMOFFLINERESOURCELIST_IID)

  /**
   * Get the list of dynamically-managed entries.
   */
  /* readonly attribute nsIDOMDOMStringList mozItems; */
  NS_SCRIPTABLE NS_IMETHOD GetMozItems(nsIDOMDOMStringList * *aMozItems) = 0;

  /**
   * Check that an entry exists in the list of dynamically-managed entries.
   *
   * @param uri
   *        The resource to check.
   */
  /* boolean mozHasItem (in DOMString uri); */
  NS_SCRIPTABLE NS_IMETHOD MozHasItem(const nsAString & uri, PRBool *_retval NS_OUTPARAM) = 0;

  /**
   * Get the number of dynamically-managed entries.
   * @status DEPRECATED
   *         Clients should use the "items" attribute.
   */
  /* readonly attribute unsigned long mozLength; */
  NS_SCRIPTABLE NS_IMETHOD GetMozLength(PRUint32 *aMozLength) = 0;

  /**
   * Get the URI of a dynamically-managed entry.
   * @status DEPRECATED
   *         Clients should use the "items" attribute.
   */
  /* DOMString mozItem (in unsigned long index); */
  NS_SCRIPTABLE NS_IMETHOD MozItem(PRUint32 index, nsAString & _retval NS_OUTPARAM) = 0;

  /**
   * Add an item to the list of dynamically-managed entries.  The resource
   * will be fetched into the application cache.
   *
   * @param uri
   *        The resource to add.
   */
  /* void mozAdd (in DOMString uri); */
  NS_SCRIPTABLE NS_IMETHOD MozAdd(const nsAString & uri) = 0;

  /**
   * Remove an item from the list of dynamically-managed entries.  If this
   * was the last reference to a URI in the application cache, the cache
   * entry will be removed.
   *
   * @param uri
   *        The resource to remove.
   */
  /* void mozRemove (in DOMString uri); */
  NS_SCRIPTABLE NS_IMETHOD MozRemove(const nsAString & uri) = 0;

  /**
   * State of the application cache this object is associated with.
   */
  enum { UNCACHED = 0U };

  enum { IDLE = 1U };

  enum { CHECKING = 2U };

  enum { DOWNLOADING = 3U };

  enum { UPDATEREADY = 4U };

  enum { OBSOLETE = 5U };

  /* readonly attribute unsigned short status; */
  NS_SCRIPTABLE NS_IMETHOD GetStatus(PRUint16 *aStatus) = 0;

  /**
   * Begin the application update process on the associated application cache.
   */
  /* void update (); */
  NS_SCRIPTABLE NS_IMETHOD Update(void) = 0;

  /**
   * Swap in the newest version of the application cache, or disassociate
   * from the cache if the cache group is obsolete.
   */
  /* void swapCache (); */
  NS_SCRIPTABLE NS_IMETHOD SwapCache(void) = 0;

  /* attribute nsIDOMEventListener onchecking; */
  NS_SCRIPTABLE NS_IMETHOD GetOnchecking(nsIDOMEventListener * *aOnchecking) = 0;
  NS_SCRIPTABLE NS_IMETHOD SetOnchecking(nsIDOMEventListener * aOnchecking) = 0;

  /* attribute nsIDOMEventListener onerror; */
  NS_SCRIPTABLE NS_IMETHOD GetOnerror(nsIDOMEventListener * *aOnerror) = 0;
  NS_SCRIPTABLE NS_IMETHOD SetOnerror(nsIDOMEventListener * aOnerror) = 0;

  /* attribute nsIDOMEventListener onnoupdate; */
  NS_SCRIPTABLE NS_IMETHOD GetOnnoupdate(nsIDOMEventListener * *aOnnoupdate) = 0;
  NS_SCRIPTABLE NS_IMETHOD SetOnnoupdate(nsIDOMEventListener * aOnnoupdate) = 0;

  /* attribute nsIDOMEventListener ondownloading; */
  NS_SCRIPTABLE NS_IMETHOD GetOndownloading(nsIDOMEventListener * *aOndownloading) = 0;
  NS_SCRIPTABLE NS_IMETHOD SetOndownloading(nsIDOMEventListener * aOndownloading) = 0;

  /* attribute nsIDOMEventListener onprogress; */
  NS_SCRIPTABLE NS_IMETHOD GetOnprogress(nsIDOMEventListener * *aOnprogress) = 0;
  NS_SCRIPTABLE NS_IMETHOD SetOnprogress(nsIDOMEventListener * aOnprogress) = 0;

  /* attribute nsIDOMEventListener onupdateready; */
  NS_SCRIPTABLE NS_IMETHOD GetOnupdateready(nsIDOMEventListener * *aOnupdateready) = 0;
  NS_SCRIPTABLE NS_IMETHOD SetOnupdateready(nsIDOMEventListener * aOnupdateready) = 0;

  /* attribute nsIDOMEventListener oncached; */
  NS_SCRIPTABLE NS_IMETHOD GetOncached(nsIDOMEventListener * *aOncached) = 0;
  NS_SCRIPTABLE NS_IMETHOD SetOncached(nsIDOMEventListener * aOncached) = 0;

  /* attribute nsIDOMEventListener onobsolete; */
  NS_SCRIPTABLE NS_IMETHOD GetOnobsolete(nsIDOMEventListener * *aOnobsolete) = 0;
  NS_SCRIPTABLE NS_IMETHOD SetOnobsolete(nsIDOMEventListener * aOnobsolete) = 0;

};

  NS_DEFINE_STATIC_IID_ACCESSOR(nsIDOMOfflineResourceList, NS_IDOMOFFLINERESOURCELIST_IID)

/* Use this macro when declaring classes that implement this interface. */
#define NS_DECL_NSIDOMOFFLINERESOURCELIST \
  NS_SCRIPTABLE NS_IMETHOD GetMozItems(nsIDOMDOMStringList * *aMozItems); \
  NS_SCRIPTABLE NS_IMETHOD MozHasItem(const nsAString & uri, PRBool *_retval NS_OUTPARAM); \
  NS_SCRIPTABLE NS_IMETHOD GetMozLength(PRUint32 *aMozLength); \
  NS_SCRIPTABLE NS_IMETHOD MozItem(PRUint32 index, nsAString & _retval NS_OUTPARAM); \
  NS_SCRIPTABLE NS_IMETHOD MozAdd(const nsAString & uri); \
  NS_SCRIPTABLE NS_IMETHOD MozRemove(const nsAString & uri); \
  NS_SCRIPTABLE NS_IMETHOD GetStatus(PRUint16 *aStatus); \
  NS_SCRIPTABLE NS_IMETHOD Update(void); \
  NS_SCRIPTABLE NS_IMETHOD SwapCache(void); \
  NS_SCRIPTABLE NS_IMETHOD GetOnchecking(nsIDOMEventListener * *aOnchecking); \
  NS_SCRIPTABLE NS_IMETHOD SetOnchecking(nsIDOMEventListener * aOnchecking); \
  NS_SCRIPTABLE NS_IMETHOD GetOnerror(nsIDOMEventListener * *aOnerror); \
  NS_SCRIPTABLE NS_IMETHOD SetOnerror(nsIDOMEventListener * aOnerror); \
  NS_SCRIPTABLE NS_IMETHOD GetOnnoupdate(nsIDOMEventListener * *aOnnoupdate); \
  NS_SCRIPTABLE NS_IMETHOD SetOnnoupdate(nsIDOMEventListener * aOnnoupdate); \
  NS_SCRIPTABLE NS_IMETHOD GetOndownloading(nsIDOMEventListener * *aOndownloading); \
  NS_SCRIPTABLE NS_IMETHOD SetOndownloading(nsIDOMEventListener * aOndownloading); \
  NS_SCRIPTABLE NS_IMETHOD GetOnprogress(nsIDOMEventListener * *aOnprogress); \
  NS_SCRIPTABLE NS_IMETHOD SetOnprogress(nsIDOMEventListener * aOnprogress); \
  NS_SCRIPTABLE NS_IMETHOD GetOnupdateready(nsIDOMEventListener * *aOnupdateready); \
  NS_SCRIPTABLE NS_IMETHOD SetOnupdateready(nsIDOMEventListener * aOnupdateready); \
  NS_SCRIPTABLE NS_IMETHOD GetOncached(nsIDOMEventListener * *aOncached); \
  NS_SCRIPTABLE NS_IMETHOD SetOncached(nsIDOMEventListener * aOncached); \
  NS_SCRIPTABLE NS_IMETHOD GetOnobsolete(nsIDOMEventListener * *aOnobsolete); \
  NS_SCRIPTABLE NS_IMETHOD SetOnobsolete(nsIDOMEventListener * aOnobsolete); 

/* Use this macro to declare functions that forward the behavior of this interface to another object. */
#define NS_FORWARD_NSIDOMOFFLINERESOURCELIST(_to) \
  NS_SCRIPTABLE NS_IMETHOD GetMozItems(nsIDOMDOMStringList * *aMozItems) { return _to GetMozItems(aMozItems); } \
  NS_SCRIPTABLE NS_IMETHOD MozHasItem(const nsAString & uri, PRBool *_retval NS_OUTPARAM) { return _to MozHasItem(uri, _retval); } \
  NS_SCRIPTABLE NS_IMETHOD GetMozLength(PRUint32 *aMozLength) { return _to GetMozLength(aMozLength); } \
  NS_SCRIPTABLE NS_IMETHOD MozItem(PRUint32 index, nsAString & _retval NS_OUTPARAM) { return _to MozItem(index, _retval); } \
  NS_SCRIPTABLE NS_IMETHOD MozAdd(const nsAString & uri) { return _to MozAdd(uri); } \
  NS_SCRIPTABLE NS_IMETHOD MozRemove(const nsAString & uri) { return _to MozRemove(uri); } \
  NS_SCRIPTABLE NS_IMETHOD GetStatus(PRUint16 *aStatus) { return _to GetStatus(aStatus); } \
  NS_SCRIPTABLE NS_IMETHOD Update(void) { return _to Update(); } \
  NS_SCRIPTABLE NS_IMETHOD SwapCache(void) { return _to SwapCache(); } \
  NS_SCRIPTABLE NS_IMETHOD GetOnchecking(nsIDOMEventListener * *aOnchecking) { return _to GetOnchecking(aOnchecking); } \
  NS_SCRIPTABLE NS_IMETHOD SetOnchecking(nsIDOMEventListener * aOnchecking) { return _to SetOnchecking(aOnchecking); } \
  NS_SCRIPTABLE NS_IMETHOD GetOnerror(nsIDOMEventListener * *aOnerror) { return _to GetOnerror(aOnerror); } \
  NS_SCRIPTABLE NS_IMETHOD SetOnerror(nsIDOMEventListener * aOnerror) { return _to SetOnerror(aOnerror); } \
  NS_SCRIPTABLE NS_IMETHOD GetOnnoupdate(nsIDOMEventListener * *aOnnoupdate) { return _to GetOnnoupdate(aOnnoupdate); } \
  NS_SCRIPTABLE NS_IMETHOD SetOnnoupdate(nsIDOMEventListener * aOnnoupdate) { return _to SetOnnoupdate(aOnnoupdate); } \
  NS_SCRIPTABLE NS_IMETHOD GetOndownloading(nsIDOMEventListener * *aOndownloading) { return _to GetOndownloading(aOndownloading); } \
  NS_SCRIPTABLE NS_IMETHOD SetOndownloading(nsIDOMEventListener * aOndownloading) { return _to SetOndownloading(aOndownloading); } \
  NS_SCRIPTABLE NS_IMETHOD GetOnprogress(nsIDOMEventListener * *aOnprogress) { return _to GetOnprogress(aOnprogress); } \
  NS_SCRIPTABLE NS_IMETHOD SetOnprogress(nsIDOMEventListener * aOnprogress) { return _to SetOnprogress(aOnprogress); } \
  NS_SCRIPTABLE NS_IMETHOD GetOnupdateready(nsIDOMEventListener * *aOnupdateready) { return _to GetOnupdateready(aOnupdateready); } \
  NS_SCRIPTABLE NS_IMETHOD SetOnupdateready(nsIDOMEventListener * aOnupdateready) { return _to SetOnupdateready(aOnupdateready); } \
  NS_SCRIPTABLE NS_IMETHOD GetOncached(nsIDOMEventListener * *aOncached) { return _to GetOncached(aOncached); } \
  NS_SCRIPTABLE NS_IMETHOD SetOncached(nsIDOMEventListener * aOncached) { return _to SetOncached(aOncached); } \
  NS_SCRIPTABLE NS_IMETHOD GetOnobsolete(nsIDOMEventListener * *aOnobsolete) { return _to GetOnobsolete(aOnobsolete); } \
  NS_SCRIPTABLE NS_IMETHOD SetOnobsolete(nsIDOMEventListener * aOnobsolete) { return _to SetOnobsolete(aOnobsolete); } 

/* Use this macro to declare functions that forward the behavior of this interface to another object in a safe way. */
#define NS_FORWARD_SAFE_NSIDOMOFFLINERESOURCELIST(_to) \
  NS_SCRIPTABLE NS_IMETHOD GetMozItems(nsIDOMDOMStringList * *aMozItems) { return !_to ? NS_ERROR_NULL_POINTER : _to->GetMozItems(aMozItems); } \
  NS_SCRIPTABLE NS_IMETHOD MozHasItem(const nsAString & uri, PRBool *_retval NS_OUTPARAM) { return !_to ? NS_ERROR_NULL_POINTER : _to->MozHasItem(uri, _retval); } \
  NS_SCRIPTABLE NS_IMETHOD GetMozLength(PRUint32 *aMozLength) { return !_to ? NS_ERROR_NULL_POINTER : _to->GetMozLength(aMozLength); } \
  NS_SCRIPTABLE NS_IMETHOD MozItem(PRUint32 index, nsAString & _retval NS_OUTPARAM) { return !_to ? NS_ERROR_NULL_POINTER : _to->MozItem(index, _retval); } \
  NS_SCRIPTABLE NS_IMETHOD MozAdd(const nsAString & uri) { return !_to ? NS_ERROR_NULL_POINTER : _to->MozAdd(uri); } \
  NS_SCRIPTABLE NS_IMETHOD MozRemove(const nsAString & uri) { return !_to ? NS_ERROR_NULL_POINTER : _to->MozRemove(uri); } \
  NS_SCRIPTABLE NS_IMETHOD GetStatus(PRUint16 *aStatus) { return !_to ? NS_ERROR_NULL_POINTER : _to->GetStatus(aStatus); } \
  NS_SCRIPTABLE NS_IMETHOD Update(void) { return !_to ? NS_ERROR_NULL_POINTER : _to->Update(); } \
  NS_SCRIPTABLE NS_IMETHOD SwapCache(void) { return !_to ? NS_ERROR_NULL_POINTER : _to->SwapCache(); } \
  NS_SCRIPTABLE NS_IMETHOD GetOnchecking(nsIDOMEventListener * *aOnchecking) { return !_to ? NS_ERROR_NULL_POINTER : _to->GetOnchecking(aOnchecking); } \
  NS_SCRIPTABLE NS_IMETHOD SetOnchecking(nsIDOMEventListener * aOnchecking) { return !_to ? NS_ERROR_NULL_POINTER : _to->SetOnchecking(aOnchecking); } \
  NS_SCRIPTABLE NS_IMETHOD GetOnerror(nsIDOMEventListener * *aOnerror) { return !_to ? NS_ERROR_NULL_POINTER : _to->GetOnerror(aOnerror); } \
  NS_SCRIPTABLE NS_IMETHOD SetOnerror(nsIDOMEventListener * aOnerror) { return !_to ? NS_ERROR_NULL_POINTER : _to->SetOnerror(aOnerror); } \
  NS_SCRIPTABLE NS_IMETHOD GetOnnoupdate(nsIDOMEventListener * *aOnnoupdate) { return !_to ? NS_ERROR_NULL_POINTER : _to->GetOnnoupdate(aOnnoupdate); } \
  NS_SCRIPTABLE NS_IMETHOD SetOnnoupdate(nsIDOMEventListener * aOnnoupdate) { return !_to ? NS_ERROR_NULL_POINTER : _to->SetOnnoupdate(aOnnoupdate); } \
  NS_SCRIPTABLE NS_IMETHOD GetOndownloading(nsIDOMEventListener * *aOndownloading) { return !_to ? NS_ERROR_NULL_POINTER : _to->GetOndownloading(aOndownloading); } \
  NS_SCRIPTABLE NS_IMETHOD SetOndownloading(nsIDOMEventListener * aOndownloading) { return !_to ? NS_ERROR_NULL_POINTER : _to->SetOndownloading(aOndownloading); } \
  NS_SCRIPTABLE NS_IMETHOD GetOnprogress(nsIDOMEventListener * *aOnprogress) { return !_to ? NS_ERROR_NULL_POINTER : _to->GetOnprogress(aOnprogress); } \
  NS_SCRIPTABLE NS_IMETHOD SetOnprogress(nsIDOMEventListener * aOnprogress) { return !_to ? NS_ERROR_NULL_POINTER : _to->SetOnprogress(aOnprogress); } \
  NS_SCRIPTABLE NS_IMETHOD GetOnupdateready(nsIDOMEventListener * *aOnupdateready) { return !_to ? NS_ERROR_NULL_POINTER : _to->GetOnupdateready(aOnupdateready); } \
  NS_SCRIPTABLE NS_IMETHOD SetOnupdateready(nsIDOMEventListener * aOnupdateready) { return !_to ? NS_ERROR_NULL_POINTER : _to->SetOnupdateready(aOnupdateready); } \
  NS_SCRIPTABLE NS_IMETHOD GetOncached(nsIDOMEventListener * *aOncached) { return !_to ? NS_ERROR_NULL_POINTER : _to->GetOncached(aOncached); } \
  NS_SCRIPTABLE NS_IMETHOD SetOncached(nsIDOMEventListener * aOncached) { return !_to ? NS_ERROR_NULL_POINTER : _to->SetOncached(aOncached); } \
  NS_SCRIPTABLE NS_IMETHOD GetOnobsolete(nsIDOMEventListener * *aOnobsolete) { return !_to ? NS_ERROR_NULL_POINTER : _to->GetOnobsolete(aOnobsolete); } \
  NS_SCRIPTABLE NS_IMETHOD SetOnobsolete(nsIDOMEventListener * aOnobsolete) { return !_to ? NS_ERROR_NULL_POINTER : _to->SetOnobsolete(aOnobsolete); } 

#if 0
/* Use the code below as a template for the implementation class for this interface. */

/* Header file */
class nsDOMOfflineResourceList : public nsIDOMOfflineResourceList
{
public:
  NS_DECL_ISUPPORTS
  NS_DECL_NSIDOMOFFLINERESOURCELIST

  nsDOMOfflineResourceList();

private:
  ~nsDOMOfflineResourceList();

protected:
  /* additional members */
};

/* Implementation file */
NS_IMPL_ISUPPORTS1(nsDOMOfflineResourceList, nsIDOMOfflineResourceList)

nsDOMOfflineResourceList::nsDOMOfflineResourceList()
{
  /* member initializers and constructor code */
}

nsDOMOfflineResourceList::~nsDOMOfflineResourceList()
{
  /* destructor code */
}

/* readonly attribute nsIDOMDOMStringList mozItems; */
NS_IMETHODIMP nsDOMOfflineResourceList::GetMozItems(nsIDOMDOMStringList * *aMozItems)
{
    return NS_ERROR_NOT_IMPLEMENTED;
}

/* boolean mozHasItem (in DOMString uri); */
NS_IMETHODIMP nsDOMOfflineResourceList::MozHasItem(const nsAString & uri, PRBool *_retval NS_OUTPARAM)
{
    return NS_ERROR_NOT_IMPLEMENTED;
}

/* readonly attribute unsigned long mozLength; */
NS_IMETHODIMP nsDOMOfflineResourceList::GetMozLength(PRUint32 *aMozLength)
{
    return NS_ERROR_NOT_IMPLEMENTED;
}

/* DOMString mozItem (in unsigned long index); */
NS_IMETHODIMP nsDOMOfflineResourceList::MozItem(PRUint32 index, nsAString & _retval NS_OUTPARAM)
{
    return NS_ERROR_NOT_IMPLEMENTED;
}

/* void mozAdd (in DOMString uri); */
NS_IMETHODIMP nsDOMOfflineResourceList::MozAdd(const nsAString & uri)
{
    return NS_ERROR_NOT_IMPLEMENTED;
}

/* void mozRemove (in DOMString uri); */
NS_IMETHODIMP nsDOMOfflineResourceList::MozRemove(const nsAString & uri)
{
    return NS_ERROR_NOT_IMPLEMENTED;
}

/* readonly attribute unsigned short status; */
NS_IMETHODIMP nsDOMOfflineResourceList::GetStatus(PRUint16 *aStatus)
{
    return NS_ERROR_NOT_IMPLEMENTED;
}

/* void update (); */
NS_IMETHODIMP nsDOMOfflineResourceList::Update()
{
    return NS_ERROR_NOT_IMPLEMENTED;
}

/* void swapCache (); */
NS_IMETHODIMP nsDOMOfflineResourceList::SwapCache()
{
    return NS_ERROR_NOT_IMPLEMENTED;
}

/* attribute nsIDOMEventListener onchecking; */
NS_IMETHODIMP nsDOMOfflineResourceList::GetOnchecking(nsIDOMEventListener * *aOnchecking)
{
    return NS_ERROR_NOT_IMPLEMENTED;
}
NS_IMETHODIMP nsDOMOfflineResourceList::SetOnchecking(nsIDOMEventListener * aOnchecking)
{
    return NS_ERROR_NOT_IMPLEMENTED;
}

/* attribute nsIDOMEventListener onerror; */
NS_IMETHODIMP nsDOMOfflineResourceList::GetOnerror(nsIDOMEventListener * *aOnerror)
{
    return NS_ERROR_NOT_IMPLEMENTED;
}
NS_IMETHODIMP nsDOMOfflineResourceList::SetOnerror(nsIDOMEventListener * aOnerror)
{
    return NS_ERROR_NOT_IMPLEMENTED;
}

/* attribute nsIDOMEventListener onnoupdate; */
NS_IMETHODIMP nsDOMOfflineResourceList::GetOnnoupdate(nsIDOMEventListener * *aOnnoupdate)
{
    return NS_ERROR_NOT_IMPLEMENTED;
}
NS_IMETHODIMP nsDOMOfflineResourceList::SetOnnoupdate(nsIDOMEventListener * aOnnoupdate)
{
    return NS_ERROR_NOT_IMPLEMENTED;
}

/* attribute nsIDOMEventListener ondownloading; */
NS_IMETHODIMP nsDOMOfflineResourceList::GetOndownloading(nsIDOMEventListener * *aOndownloading)
{
    return NS_ERROR_NOT_IMPLEMENTED;
}
NS_IMETHODIMP nsDOMOfflineResourceList::SetOndownloading(nsIDOMEventListener * aOndownloading)
{
    return NS_ERROR_NOT_IMPLEMENTED;
}

/* attribute nsIDOMEventListener onprogress; */
NS_IMETHODIMP nsDOMOfflineResourceList::GetOnprogress(nsIDOMEventListener * *aOnprogress)
{
    return NS_ERROR_NOT_IMPLEMENTED;
}
NS_IMETHODIMP nsDOMOfflineResourceList::SetOnprogress(nsIDOMEventListener * aOnprogress)
{
    return NS_ERROR_NOT_IMPLEMENTED;
}

/* attribute nsIDOMEventListener onupdateready; */
NS_IMETHODIMP nsDOMOfflineResourceList::GetOnupdateready(nsIDOMEventListener * *aOnupdateready)
{
    return NS_ERROR_NOT_IMPLEMENTED;
}
NS_IMETHODIMP nsDOMOfflineResourceList::SetOnupdateready(nsIDOMEventListener * aOnupdateready)
{
    return NS_ERROR_NOT_IMPLEMENTED;
}

/* attribute nsIDOMEventListener oncached; */
NS_IMETHODIMP nsDOMOfflineResourceList::GetOncached(nsIDOMEventListener * *aOncached)
{
    return NS_ERROR_NOT_IMPLEMENTED;
}
NS_IMETHODIMP nsDOMOfflineResourceList::SetOncached(nsIDOMEventListener * aOncached)
{
    return NS_ERROR_NOT_IMPLEMENTED;
}

/* attribute nsIDOMEventListener onobsolete; */
NS_IMETHODIMP nsDOMOfflineResourceList::GetOnobsolete(nsIDOMEventListener * *aOnobsolete)
{
    return NS_ERROR_NOT_IMPLEMENTED;
}
NS_IMETHODIMP nsDOMOfflineResourceList::SetOnobsolete(nsIDOMEventListener * aOnobsolete)
{
    return NS_ERROR_NOT_IMPLEMENTED;
}

/* End of implementation class template. */
#endif


#endif /* __gen_nsIDOMOfflineResourceList_h__ */
