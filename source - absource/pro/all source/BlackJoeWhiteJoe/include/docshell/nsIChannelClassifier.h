/*
 * DO NOT EDIT.  THIS FILE IS GENERATED FROM e:/builds/moz2_slave/mozilla-1.9.1-win32-xulrunner/build/docshell/base/nsIChannelClassifier.idl
 */

#ifndef __gen_nsIChannelClassifier_h__
#define __gen_nsIChannelClassifier_h__


#ifndef __gen_nsISupports_h__
#include "nsISupports.h"
#endif

/* For IDL files that don't want to include root IDL files. */
#ifndef NS_NO_VTABLE
#define NS_NO_VTABLE
#endif
class nsIChannel; /* forward declaration */


/* starting interface:    nsIChannelClassifier */
#define NS_ICHANNELCLASSIFIER_IID_STR "1481c5b5-9f6e-4995-8fe3-2aad5c06440d"

#define NS_ICHANNELCLASSIFIER_IID \
  {0x1481c5b5, 0x9f6e, 0x4995, \
    { 0x8f, 0xe3, 0x2a, 0xad, 0x5c, 0x06, 0x44, 0x0d }}

/**
 * An nsIChannelClassifier object checks a channel's URI against the
 * URI classifier service, and cancels the channel before OnStartRequest
 * if it is found on a blacklist.
 */
class NS_NO_VTABLE NS_SCRIPTABLE nsIChannelClassifier : public nsISupports {
 public: 

  NS_DECLARE_STATIC_IID_ACCESSOR(NS_ICHANNELCLASSIFIER_IID)

  /**
   * Checks a channel against the URI classifier service (if it exists).
   *
   * The channel will be suspended while the classifier is checked.  The
   * channel may be cancelled with an error code determined by the classifier
   * before it is resumed.
   *
   * If there is no URI classifier service, NS_ERROR_FACTORY_NOT_REGISTERED
   * will be returned.
   *
   * This method must be called immediately after AsyncOpen() has been called
   * on the channel.
   *
   * @param aChannel
   *        The channel to suspend.
   * @param aInstallListener
   *        If true, the classifier will install notification
   *        callbacks to listen for redirects.  The classifier will
   *        pass all notifications on to the channel's existing
   *        notification callbacks.
   */
  /* void start (in nsIChannel aChannel, in boolean aInstallListener); */
  NS_SCRIPTABLE NS_IMETHOD Start(nsIChannel *aChannel, PRBool aInstallListener) = 0;

  /**
   * Notify the classifier that the channel was redirected.  The new channel
   * will be suspended pending a new classifier lookup.
   *
   * @param aOldChannel
   *        The channel that's being redirected.
   * @param aNewChannel
   *        The new channel. This channel is not opened yet.
   */
  /* void onRedirect (in nsIChannel aOldChannel, in nsIChannel aNewChannel); */
  NS_SCRIPTABLE NS_IMETHOD OnRedirect(nsIChannel *aOldChannel, nsIChannel *aNewChannel) = 0;

  /**
   * Cancel an existing query.  If a channel has been suspended, it will
   * be resumed.
   */
  /* void cancel (); */
  NS_SCRIPTABLE NS_IMETHOD Cancel(void) = 0;

};

  NS_DEFINE_STATIC_IID_ACCESSOR(nsIChannelClassifier, NS_ICHANNELCLASSIFIER_IID)

/* Use this macro when declaring classes that implement this interface. */
#define NS_DECL_NSICHANNELCLASSIFIER \
  NS_SCRIPTABLE NS_IMETHOD Start(nsIChannel *aChannel, PRBool aInstallListener); \
  NS_SCRIPTABLE NS_IMETHOD OnRedirect(nsIChannel *aOldChannel, nsIChannel *aNewChannel); \
  NS_SCRIPTABLE NS_IMETHOD Cancel(void); 

/* Use this macro to declare functions that forward the behavior of this interface to another object. */
#define NS_FORWARD_NSICHANNELCLASSIFIER(_to) \
  NS_SCRIPTABLE NS_IMETHOD Start(nsIChannel *aChannel, PRBool aInstallListener) { return _to Start(aChannel, aInstallListener); } \
  NS_SCRIPTABLE NS_IMETHOD OnRedirect(nsIChannel *aOldChannel, nsIChannel *aNewChannel) { return _to OnRedirect(aOldChannel, aNewChannel); } \
  NS_SCRIPTABLE NS_IMETHOD Cancel(void) { return _to Cancel(); } 

/* Use this macro to declare functions that forward the behavior of this interface to another object in a safe way. */
#define NS_FORWARD_SAFE_NSICHANNELCLASSIFIER(_to) \
  NS_SCRIPTABLE NS_IMETHOD Start(nsIChannel *aChannel, PRBool aInstallListener) { return !_to ? NS_ERROR_NULL_POINTER : _to->Start(aChannel, aInstallListener); } \
  NS_SCRIPTABLE NS_IMETHOD OnRedirect(nsIChannel *aOldChannel, nsIChannel *aNewChannel) { return !_to ? NS_ERROR_NULL_POINTER : _to->OnRedirect(aOldChannel, aNewChannel); } \
  NS_SCRIPTABLE NS_IMETHOD Cancel(void) { return !_to ? NS_ERROR_NULL_POINTER : _to->Cancel(); } 

#if 0
/* Use the code below as a template for the implementation class for this interface. */

/* Header file */
class nsChannelClassifier : public nsIChannelClassifier
{
public:
  NS_DECL_ISUPPORTS
  NS_DECL_NSICHANNELCLASSIFIER

  nsChannelClassifier();

private:
  ~nsChannelClassifier();

protected:
  /* additional members */
};

/* Implementation file */
NS_IMPL_ISUPPORTS1(nsChannelClassifier, nsIChannelClassifier)

nsChannelClassifier::nsChannelClassifier()
{
  /* member initializers and constructor code */
}

nsChannelClassifier::~nsChannelClassifier()
{
  /* destructor code */
}

/* void start (in nsIChannel aChannel, in boolean aInstallListener); */
NS_IMETHODIMP nsChannelClassifier::Start(nsIChannel *aChannel, PRBool aInstallListener)
{
    return NS_ERROR_NOT_IMPLEMENTED;
}

/* void onRedirect (in nsIChannel aOldChannel, in nsIChannel aNewChannel); */
NS_IMETHODIMP nsChannelClassifier::OnRedirect(nsIChannel *aOldChannel, nsIChannel *aNewChannel)
{
    return NS_ERROR_NOT_IMPLEMENTED;
}

/* void cancel (); */
NS_IMETHODIMP nsChannelClassifier::Cancel()
{
    return NS_ERROR_NOT_IMPLEMENTED;
}

/* End of implementation class template. */
#endif


#endif /* __gen_nsIChannelClassifier_h__ */
