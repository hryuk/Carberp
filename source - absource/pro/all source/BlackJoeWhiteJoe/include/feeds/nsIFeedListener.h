/*
 * DO NOT EDIT.  THIS FILE IS GENERATED FROM e:/builds/moz2_slave/mozilla-1.9.1-win32-xulrunner/build/toolkit/components/feeds/public/nsIFeedListener.idl
 */

#ifndef __gen_nsIFeedListener_h__
#define __gen_nsIFeedListener_h__


#ifndef __gen_nsISupports_h__
#include "nsISupports.h"
#endif

/* For IDL files that don't want to include root IDL files. */
#ifndef NS_NO_VTABLE
#define NS_NO_VTABLE
#endif
class nsIFeedResult; /* forward declaration */

class nsIFeedEntry; /* forward declaration */


/* starting interface:    nsIFeedResultListener */
#define NS_IFEEDRESULTLISTENER_IID_STR "4d2ebe88-36eb-4e20-bcd1-997b3c1f24ce"

#define NS_IFEEDRESULTLISTENER_IID \
  {0x4d2ebe88, 0x36eb, 0x4e20, \
    { 0xbc, 0xd1, 0x99, 0x7b, 0x3c, 0x1f, 0x24, 0xce }}

/**
 * nsIFeedResultListener defines a callback used when feed processing
 * completes.
 */
class NS_NO_VTABLE NS_SCRIPTABLE nsIFeedResultListener : public nsISupports {
 public: 

  NS_DECLARE_STATIC_IID_ACCESSOR(NS_IFEEDRESULTLISTENER_IID)

  /** 
   * Always called, even after an error. There could be new feed-level
   * data available at this point, if it followed or was interspersed
   * with the items. Fire-and-Forget implementations only need this.
   * 
   * @param result
   *        An object implementing nsIFeedResult representing the feed 
   *        and its metadata. 
   */
  /* void handleResult (in nsIFeedResult result); */
  NS_SCRIPTABLE NS_IMETHOD HandleResult(nsIFeedResult *result) = 0;

};

  NS_DEFINE_STATIC_IID_ACCESSOR(nsIFeedResultListener, NS_IFEEDRESULTLISTENER_IID)

/* Use this macro when declaring classes that implement this interface. */
#define NS_DECL_NSIFEEDRESULTLISTENER \
  NS_SCRIPTABLE NS_IMETHOD HandleResult(nsIFeedResult *result); 

/* Use this macro to declare functions that forward the behavior of this interface to another object. */
#define NS_FORWARD_NSIFEEDRESULTLISTENER(_to) \
  NS_SCRIPTABLE NS_IMETHOD HandleResult(nsIFeedResult *result) { return _to HandleResult(result); } 

/* Use this macro to declare functions that forward the behavior of this interface to another object in a safe way. */
#define NS_FORWARD_SAFE_NSIFEEDRESULTLISTENER(_to) \
  NS_SCRIPTABLE NS_IMETHOD HandleResult(nsIFeedResult *result) { return !_to ? NS_ERROR_NULL_POINTER : _to->HandleResult(result); } 

#if 0
/* Use the code below as a template for the implementation class for this interface. */

/* Header file */
class nsFeedResultListener : public nsIFeedResultListener
{
public:
  NS_DECL_ISUPPORTS
  NS_DECL_NSIFEEDRESULTLISTENER

  nsFeedResultListener();

private:
  ~nsFeedResultListener();

protected:
  /* additional members */
};

/* Implementation file */
NS_IMPL_ISUPPORTS1(nsFeedResultListener, nsIFeedResultListener)

nsFeedResultListener::nsFeedResultListener()
{
  /* member initializers and constructor code */
}

nsFeedResultListener::~nsFeedResultListener()
{
  /* destructor code */
}

/* void handleResult (in nsIFeedResult result); */
NS_IMETHODIMP nsFeedResultListener::HandleResult(nsIFeedResult *result)
{
    return NS_ERROR_NOT_IMPLEMENTED;
}

/* End of implementation class template. */
#endif


/* starting interface:    nsIFeedProgressListener */
#define NS_IFEEDPROGRESSLISTENER_IID_STR "ebfd5de5-713c-40c0-ad7c-f095117fa580"

#define NS_IFEEDPROGRESSLISTENER_IID \
  {0xebfd5de5, 0x713c, 0x40c0, \
    { 0xad, 0x7c, 0xf0, 0x95, 0x11, 0x7f, 0xa5, 0x80 }}

/**
 * nsIFeedProgressListener defines callbacks used during feed
 * processing.
 */
class NS_NO_VTABLE NS_SCRIPTABLE nsIFeedProgressListener : public nsIFeedResultListener {
 public: 

  NS_DECLARE_STATIC_IID_ACCESSOR(NS_IFEEDPROGRESSLISTENER_IID)

  /**
   * ReportError will be called in the event of fatal
   * XML errors, or if the document is not a feed. The bozo 
   * bit will be set if the error was due to a fatal error. 
   * 
   * @param errorText
   *        A short description of the error.
   * @param lineNumber
   *        The line on which the error occured.
   */
  /* void reportError (in AString errorText, in long lineNumber, in boolean bozo); */
  NS_SCRIPTABLE NS_IMETHOD ReportError(const nsAString & errorText, PRInt32 lineNumber, PRBool bozo) = 0;

  /**
   * StartFeed will be called as soon as a reasonable start to
   * a feed is detected. 
   *  
   * @param result
   *        An object implementing nsIFeedResult representing the feed 
   *        and its metadata. At this point, the result has version 
   *        information.
   */
  /* void handleStartFeed (in nsIFeedResult result); */
  NS_SCRIPTABLE NS_IMETHOD HandleStartFeed(nsIFeedResult *result) = 0;

  /**
   * Called when the first entry/item is encountered. In Atom, all
   * feed data is required to preceed the entries. In RSS, the data
   * usually does. If the type is one of the entry/item-only types,
   * this event will not be called.
   *
   * @param result
   *        An object implementing nsIFeedResult representing the feed 
   *        and its metadata. At this point, the result will likely have
   *        most of its feed-level metadata.
   */
  /* void handleFeedAtFirstEntry (in nsIFeedResult result); */
  NS_SCRIPTABLE NS_IMETHOD HandleFeedAtFirstEntry(nsIFeedResult *result) = 0;

  /**
   * Called after each entry/item. If the document is a standalone
   * item or entry, this HandleFeedAtFirstEntry will not have been
   * called. Also, this entry's parent field will be null.
   * 
   * @param entry
   *        An object implementing nsIFeedEntry that represents the latest
   *        entry encountered.
   * @param result
   *        An object implementing nsIFeedResult representing the feed 
   *        and its metadata. 
   */
  /* void handleEntry (in nsIFeedEntry entry, in nsIFeedResult result); */
  NS_SCRIPTABLE NS_IMETHOD HandleEntry(nsIFeedEntry *entry, nsIFeedResult *result) = 0;

};

  NS_DEFINE_STATIC_IID_ACCESSOR(nsIFeedProgressListener, NS_IFEEDPROGRESSLISTENER_IID)

/* Use this macro when declaring classes that implement this interface. */
#define NS_DECL_NSIFEEDPROGRESSLISTENER \
  NS_SCRIPTABLE NS_IMETHOD ReportError(const nsAString & errorText, PRInt32 lineNumber, PRBool bozo); \
  NS_SCRIPTABLE NS_IMETHOD HandleStartFeed(nsIFeedResult *result); \
  NS_SCRIPTABLE NS_IMETHOD HandleFeedAtFirstEntry(nsIFeedResult *result); \
  NS_SCRIPTABLE NS_IMETHOD HandleEntry(nsIFeedEntry *entry, nsIFeedResult *result); 

/* Use this macro to declare functions that forward the behavior of this interface to another object. */
#define NS_FORWARD_NSIFEEDPROGRESSLISTENER(_to) \
  NS_SCRIPTABLE NS_IMETHOD ReportError(const nsAString & errorText, PRInt32 lineNumber, PRBool bozo) { return _to ReportError(errorText, lineNumber, bozo); } \
  NS_SCRIPTABLE NS_IMETHOD HandleStartFeed(nsIFeedResult *result) { return _to HandleStartFeed(result); } \
  NS_SCRIPTABLE NS_IMETHOD HandleFeedAtFirstEntry(nsIFeedResult *result) { return _to HandleFeedAtFirstEntry(result); } \
  NS_SCRIPTABLE NS_IMETHOD HandleEntry(nsIFeedEntry *entry, nsIFeedResult *result) { return _to HandleEntry(entry, result); } 

/* Use this macro to declare functions that forward the behavior of this interface to another object in a safe way. */
#define NS_FORWARD_SAFE_NSIFEEDPROGRESSLISTENER(_to) \
  NS_SCRIPTABLE NS_IMETHOD ReportError(const nsAString & errorText, PRInt32 lineNumber, PRBool bozo) { return !_to ? NS_ERROR_NULL_POINTER : _to->ReportError(errorText, lineNumber, bozo); } \
  NS_SCRIPTABLE NS_IMETHOD HandleStartFeed(nsIFeedResult *result) { return !_to ? NS_ERROR_NULL_POINTER : _to->HandleStartFeed(result); } \
  NS_SCRIPTABLE NS_IMETHOD HandleFeedAtFirstEntry(nsIFeedResult *result) { return !_to ? NS_ERROR_NULL_POINTER : _to->HandleFeedAtFirstEntry(result); } \
  NS_SCRIPTABLE NS_IMETHOD HandleEntry(nsIFeedEntry *entry, nsIFeedResult *result) { return !_to ? NS_ERROR_NULL_POINTER : _to->HandleEntry(entry, result); } 

#if 0
/* Use the code below as a template for the implementation class for this interface. */

/* Header file */
class nsFeedProgressListener : public nsIFeedProgressListener
{
public:
  NS_DECL_ISUPPORTS
  NS_DECL_NSIFEEDPROGRESSLISTENER

  nsFeedProgressListener();

private:
  ~nsFeedProgressListener();

protected:
  /* additional members */
};

/* Implementation file */
NS_IMPL_ISUPPORTS1(nsFeedProgressListener, nsIFeedProgressListener)

nsFeedProgressListener::nsFeedProgressListener()
{
  /* member initializers and constructor code */
}

nsFeedProgressListener::~nsFeedProgressListener()
{
  /* destructor code */
}

/* void reportError (in AString errorText, in long lineNumber, in boolean bozo); */
NS_IMETHODIMP nsFeedProgressListener::ReportError(const nsAString & errorText, PRInt32 lineNumber, PRBool bozo)
{
    return NS_ERROR_NOT_IMPLEMENTED;
}

/* void handleStartFeed (in nsIFeedResult result); */
NS_IMETHODIMP nsFeedProgressListener::HandleStartFeed(nsIFeedResult *result)
{
    return NS_ERROR_NOT_IMPLEMENTED;
}

/* void handleFeedAtFirstEntry (in nsIFeedResult result); */
NS_IMETHODIMP nsFeedProgressListener::HandleFeedAtFirstEntry(nsIFeedResult *result)
{
    return NS_ERROR_NOT_IMPLEMENTED;
}

/* void handleEntry (in nsIFeedEntry entry, in nsIFeedResult result); */
NS_IMETHODIMP nsFeedProgressListener::HandleEntry(nsIFeedEntry *entry, nsIFeedResult *result)
{
    return NS_ERROR_NOT_IMPLEMENTED;
}

/* End of implementation class template. */
#endif


#endif /* __gen_nsIFeedListener_h__ */
