/*
 * DO NOT EDIT.  THIS FILE IS GENERATED FROM e:/builds/moz2_slave/mozilla-1.9.1-win32-xulrunner/build/docshell/base/nsIGlobalHistory3.idl
 */

#ifndef __gen_nsIGlobalHistory3_h__
#define __gen_nsIGlobalHistory3_h__


#ifndef __gen_nsISupports_h__
#include "nsISupports.h"
#endif

#ifndef __gen_nsIGlobalHistory2_h__
#include "nsIGlobalHistory2.h"
#endif

/* For IDL files that don't want to include root IDL files. */
#ifndef NS_NO_VTABLE
#define NS_NO_VTABLE
#endif
class nsIChannel; /* forward declaration */

// This is NOT part of the interface! It could change.
#define NS_GECKO_FLAG_NEEDS_VERTICAL_SCROLLBAR (1 << 0)

/* starting interface:    nsIGlobalHistory3 */
#define NS_IGLOBALHISTORY3_IID_STR "24306852-c60e-49c3-a455-90f6747118ba"

#define NS_IGLOBALHISTORY3_IID \
  {0x24306852, 0xc60e, 0x49c3, \
    { 0xa4, 0x55, 0x90, 0xf6, 0x74, 0x71, 0x18, 0xba }}

/**
 * Provides information about global history to gecko, extending GlobalHistory2
 */
class NS_NO_VTABLE NS_SCRIPTABLE nsIGlobalHistory3 : public nsIGlobalHistory2 {
 public: 

  NS_DECLARE_STATIC_IID_ACCESSOR(NS_IGLOBALHISTORY3_IID)

  /**
   * Notifies the history system that the page loading via aOldChannel
   * redirected to aNewChannel. Implementations should generally add the URI for
   * aOldChannel to history for link coloring, but are advised not to expose it
   * in the history user interface. This function is preferred if
   * nsIGlobalHistory3 is available. Otherwise, nsIGlobalHistory2.addURI should
   * be called with redirect=true.
   *
   * This function is preferred to nsIGlobalHistory2.addURI because it provides
   * more information (including the redirect destination, channels involved,
   * and redirect flags) to the history implementation.
   *
   * For implementors of nsIGlobalHistory3: The history implementation is
   * responsible for sending NS_LINK_VISITED_EVENT_TOPIC to observers for
   * redirect pages. This notification must be sent for history consumers for
   * all non-redirect pages.
   *
   * @param aToplevel whether the URI is loaded in a top-level window.  If
   *        false, the load is in a subframe.
   *
   * The other params to this function are the same as those for
   * nsIChannelEventSink::OnChannelRedirect.
   *
   * Note: Implementors who wish to implement this interface but rely on
   * nsIGlobalHistory2.addURI for redirect processing may throw
   * NS_ERROR_NOT_IMPLEMENTED from this method.  If they do so, then callers
   * must call nsIGlobalHistory2.addURI upon getting the
   * NS_ERROR_NOT_IMPLEMENTED result.
   */
  /* void addDocumentRedirect (in nsIChannel aOldChannel, in nsIChannel aNewChannel, in PRInt32 aFlags, in boolean aTopLevel); */
  NS_SCRIPTABLE NS_IMETHOD AddDocumentRedirect(nsIChannel *aOldChannel, nsIChannel *aNewChannel, PRInt32 aFlags, PRBool aTopLevel) = 0;

  /**
   * Get the Gecko flags for this URI. These flags are used by Gecko as hints
   * to optimize page loading. Not all histories have them; this need not be
   * supported (just return NS_ERROR_NOT_IMPLEMENTED. These flags are opaque
   * and should not be interpreted by the history engine.
   */
  /* unsigned long getURIGeckoFlags (in nsIURI aURI); */
  NS_SCRIPTABLE NS_IMETHOD GetURIGeckoFlags(nsIURI *aURI, PRUint32 *_retval NS_OUTPARAM) = 0;

  /**
   * Set the Gecko flags for this URI. May fail if the history entry
   * doesn't have any flags or if there is no entry for the URI.
   */
  /* void setURIGeckoFlags (in nsIURI aURI, in unsigned long aFlags); */
  NS_SCRIPTABLE NS_IMETHOD SetURIGeckoFlags(nsIURI *aURI, PRUint32 aFlags) = 0;

};

  NS_DEFINE_STATIC_IID_ACCESSOR(nsIGlobalHistory3, NS_IGLOBALHISTORY3_IID)

/* Use this macro when declaring classes that implement this interface. */
#define NS_DECL_NSIGLOBALHISTORY3 \
  NS_SCRIPTABLE NS_IMETHOD AddDocumentRedirect(nsIChannel *aOldChannel, nsIChannel *aNewChannel, PRInt32 aFlags, PRBool aTopLevel); \
  NS_SCRIPTABLE NS_IMETHOD GetURIGeckoFlags(nsIURI *aURI, PRUint32 *_retval NS_OUTPARAM); \
  NS_SCRIPTABLE NS_IMETHOD SetURIGeckoFlags(nsIURI *aURI, PRUint32 aFlags); 

/* Use this macro to declare functions that forward the behavior of this interface to another object. */
#define NS_FORWARD_NSIGLOBALHISTORY3(_to) \
  NS_SCRIPTABLE NS_IMETHOD AddDocumentRedirect(nsIChannel *aOldChannel, nsIChannel *aNewChannel, PRInt32 aFlags, PRBool aTopLevel) { return _to AddDocumentRedirect(aOldChannel, aNewChannel, aFlags, aTopLevel); } \
  NS_SCRIPTABLE NS_IMETHOD GetURIGeckoFlags(nsIURI *aURI, PRUint32 *_retval NS_OUTPARAM) { return _to GetURIGeckoFlags(aURI, _retval); } \
  NS_SCRIPTABLE NS_IMETHOD SetURIGeckoFlags(nsIURI *aURI, PRUint32 aFlags) { return _to SetURIGeckoFlags(aURI, aFlags); } 

/* Use this macro to declare functions that forward the behavior of this interface to another object in a safe way. */
#define NS_FORWARD_SAFE_NSIGLOBALHISTORY3(_to) \
  NS_SCRIPTABLE NS_IMETHOD AddDocumentRedirect(nsIChannel *aOldChannel, nsIChannel *aNewChannel, PRInt32 aFlags, PRBool aTopLevel) { return !_to ? NS_ERROR_NULL_POINTER : _to->AddDocumentRedirect(aOldChannel, aNewChannel, aFlags, aTopLevel); } \
  NS_SCRIPTABLE NS_IMETHOD GetURIGeckoFlags(nsIURI *aURI, PRUint32 *_retval NS_OUTPARAM) { return !_to ? NS_ERROR_NULL_POINTER : _to->GetURIGeckoFlags(aURI, _retval); } \
  NS_SCRIPTABLE NS_IMETHOD SetURIGeckoFlags(nsIURI *aURI, PRUint32 aFlags) { return !_to ? NS_ERROR_NULL_POINTER : _to->SetURIGeckoFlags(aURI, aFlags); } 

#if 0
/* Use the code below as a template for the implementation class for this interface. */

/* Header file */
class nsGlobalHistory3 : public nsIGlobalHistory3
{
public:
  NS_DECL_ISUPPORTS
  NS_DECL_NSIGLOBALHISTORY3

  nsGlobalHistory3();

private:
  ~nsGlobalHistory3();

protected:
  /* additional members */
};

/* Implementation file */
NS_IMPL_ISUPPORTS1(nsGlobalHistory3, nsIGlobalHistory3)

nsGlobalHistory3::nsGlobalHistory3()
{
  /* member initializers and constructor code */
}

nsGlobalHistory3::~nsGlobalHistory3()
{
  /* destructor code */
}

/* void addDocumentRedirect (in nsIChannel aOldChannel, in nsIChannel aNewChannel, in PRInt32 aFlags, in boolean aTopLevel); */
NS_IMETHODIMP nsGlobalHistory3::AddDocumentRedirect(nsIChannel *aOldChannel, nsIChannel *aNewChannel, PRInt32 aFlags, PRBool aTopLevel)
{
    return NS_ERROR_NOT_IMPLEMENTED;
}

/* unsigned long getURIGeckoFlags (in nsIURI aURI); */
NS_IMETHODIMP nsGlobalHistory3::GetURIGeckoFlags(nsIURI *aURI, PRUint32 *_retval NS_OUTPARAM)
{
    return NS_ERROR_NOT_IMPLEMENTED;
}

/* void setURIGeckoFlags (in nsIURI aURI, in unsigned long aFlags); */
NS_IMETHODIMP nsGlobalHistory3::SetURIGeckoFlags(nsIURI *aURI, PRUint32 aFlags)
{
    return NS_ERROR_NOT_IMPLEMENTED;
}

/* End of implementation class template. */
#endif


#endif /* __gen_nsIGlobalHistory3_h__ */
