/*
 * DO NOT EDIT.  THIS FILE IS GENERATED FROM e:/builds/moz2_slave/mozilla-1.9.1-win32-xulrunner/build/toolkit/components/feeds/public/nsIFeed.idl
 */

#ifndef __gen_nsIFeed_h__
#define __gen_nsIFeed_h__


#ifndef __gen_nsIFeedContainer_h__
#include "nsIFeedContainer.h"
#endif

/* For IDL files that don't want to include root IDL files. */
#ifndef NS_NO_VTABLE
#define NS_NO_VTABLE
#endif
class nsIArray; /* forward declaration */

class nsIFeedGenerator; /* forward declaration */


/* starting interface:    nsIFeed */
#define NS_IFEED_IID_STR "3b8aae33-80e2-4efa-99c8-a6c5b99f76ea"

#define NS_IFEED_IID \
  {0x3b8aae33, 0x80e2, 0x4efa, \
    { 0x99, 0xc8, 0xa6, 0xc5, 0xb9, 0x9f, 0x76, 0xea }}

/**
 * An nsIFeed represents a single Atom or RSS feed.
 */
class NS_NO_VTABLE NS_SCRIPTABLE nsIFeed : public nsIFeedContainer {
 public: 

  NS_DECLARE_STATIC_IID_ACCESSOR(NS_IFEED_IID)

  /** 
  * Uses description, subtitle, and extensions
  * to generate a summary. 
  */
  /* attribute nsIFeedTextConstruct subtitle; */
  NS_SCRIPTABLE NS_IMETHOD GetSubtitle(nsIFeedTextConstruct * *aSubtitle) = 0;
  NS_SCRIPTABLE NS_IMETHOD SetSubtitle(nsIFeedTextConstruct * aSubtitle) = 0;

  enum { TYPE_FEED = 0U };

  enum { TYPE_AUDIO = 1U };

  enum { TYPE_IMAGE = 2U };

  enum { TYPE_VIDEO = 4U };

  /**
  * The type of feed. For example, a podcast would be TYPE_AUDIO.
  */
  /* readonly attribute unsigned long type; */
  NS_SCRIPTABLE NS_IMETHOD GetType(PRUint32 *aType) = 0;

  /**
  * The total number of enclosures found in the feed.
  */
  /* attribute long enclosureCount; */
  NS_SCRIPTABLE NS_IMETHOD GetEnclosureCount(PRInt32 *aEnclosureCount) = 0;
  NS_SCRIPTABLE NS_IMETHOD SetEnclosureCount(PRInt32 aEnclosureCount) = 0;

  /**
  * The items or entries in feed.
  */
  /* attribute nsIArray items; */
  NS_SCRIPTABLE NS_IMETHOD GetItems(nsIArray * *aItems) = 0;
  NS_SCRIPTABLE NS_IMETHOD SetItems(nsIArray * aItems) = 0;

  /**
  * No one really knows what cloud is for.
  *
  * It supposedly enables some sort of interaction with an XML-RPC or
  * SOAP service.
  */
  /* attribute nsIWritablePropertyBag2 cloud; */
  NS_SCRIPTABLE NS_IMETHOD GetCloud(nsIWritablePropertyBag2 * *aCloud) = 0;
  NS_SCRIPTABLE NS_IMETHOD SetCloud(nsIWritablePropertyBag2 * aCloud) = 0;

  /**
  * Information about the software that produced the feed.
  */
  /* attribute nsIFeedGenerator generator; */
  NS_SCRIPTABLE NS_IMETHOD GetGenerator(nsIFeedGenerator * *aGenerator) = 0;
  NS_SCRIPTABLE NS_IMETHOD SetGenerator(nsIFeedGenerator * aGenerator) = 0;

  /**
  * An image url and some metadata (as defined by RSS2).
  *
  */
  /* attribute nsIWritablePropertyBag2 image; */
  NS_SCRIPTABLE NS_IMETHOD GetImage(nsIWritablePropertyBag2 * *aImage) = 0;
  NS_SCRIPTABLE NS_IMETHOD SetImage(nsIWritablePropertyBag2 * aImage) = 0;

  /**
  * No one really knows what textInput is for.
  *
  * See
  * <http://www.cadenhead.org/workbench/news/2894/rss-joy-textinput>
  * for more details.
  */
  /* attribute nsIWritablePropertyBag2 textInput; */
  NS_SCRIPTABLE NS_IMETHOD GetTextInput(nsIWritablePropertyBag2 * *aTextInput) = 0;
  NS_SCRIPTABLE NS_IMETHOD SetTextInput(nsIWritablePropertyBag2 * aTextInput) = 0;

  /**
  * Days to skip fetching. This field was supposed to designate
  * intervals for feed fetching. It's not generally implemented. For
  * example, if this array contained "Monday", aggregators should not
  * fetch the feed on Mondays.
  */
  /* attribute nsIArray skipDays; */
  NS_SCRIPTABLE NS_IMETHOD GetSkipDays(nsIArray * *aSkipDays) = 0;
  NS_SCRIPTABLE NS_IMETHOD SetSkipDays(nsIArray * aSkipDays) = 0;

  /**
  * Hours to skip fetching. This field was supposed to designate
  * intervals for feed fetching. It's not generally implemented. See
  * <http://blogs.law.harvard.edu/tech/rss> for more information.
  */
  /* attribute nsIArray skipHours; */
  NS_SCRIPTABLE NS_IMETHOD GetSkipHours(nsIArray * *aSkipHours) = 0;
  NS_SCRIPTABLE NS_IMETHOD SetSkipHours(nsIArray * aSkipHours) = 0;

};

  NS_DEFINE_STATIC_IID_ACCESSOR(nsIFeed, NS_IFEED_IID)

/* Use this macro when declaring classes that implement this interface. */
#define NS_DECL_NSIFEED \
  NS_SCRIPTABLE NS_IMETHOD GetSubtitle(nsIFeedTextConstruct * *aSubtitle); \
  NS_SCRIPTABLE NS_IMETHOD SetSubtitle(nsIFeedTextConstruct * aSubtitle); \
  NS_SCRIPTABLE NS_IMETHOD GetType(PRUint32 *aType); \
  NS_SCRIPTABLE NS_IMETHOD GetEnclosureCount(PRInt32 *aEnclosureCount); \
  NS_SCRIPTABLE NS_IMETHOD SetEnclosureCount(PRInt32 aEnclosureCount); \
  NS_SCRIPTABLE NS_IMETHOD GetItems(nsIArray * *aItems); \
  NS_SCRIPTABLE NS_IMETHOD SetItems(nsIArray * aItems); \
  NS_SCRIPTABLE NS_IMETHOD GetCloud(nsIWritablePropertyBag2 * *aCloud); \
  NS_SCRIPTABLE NS_IMETHOD SetCloud(nsIWritablePropertyBag2 * aCloud); \
  NS_SCRIPTABLE NS_IMETHOD GetGenerator(nsIFeedGenerator * *aGenerator); \
  NS_SCRIPTABLE NS_IMETHOD SetGenerator(nsIFeedGenerator * aGenerator); \
  NS_SCRIPTABLE NS_IMETHOD GetImage(nsIWritablePropertyBag2 * *aImage); \
  NS_SCRIPTABLE NS_IMETHOD SetImage(nsIWritablePropertyBag2 * aImage); \
  NS_SCRIPTABLE NS_IMETHOD GetTextInput(nsIWritablePropertyBag2 * *aTextInput); \
  NS_SCRIPTABLE NS_IMETHOD SetTextInput(nsIWritablePropertyBag2 * aTextInput); \
  NS_SCRIPTABLE NS_IMETHOD GetSkipDays(nsIArray * *aSkipDays); \
  NS_SCRIPTABLE NS_IMETHOD SetSkipDays(nsIArray * aSkipDays); \
  NS_SCRIPTABLE NS_IMETHOD GetSkipHours(nsIArray * *aSkipHours); \
  NS_SCRIPTABLE NS_IMETHOD SetSkipHours(nsIArray * aSkipHours); 

/* Use this macro to declare functions that forward the behavior of this interface to another object. */
#define NS_FORWARD_NSIFEED(_to) \
  NS_SCRIPTABLE NS_IMETHOD GetSubtitle(nsIFeedTextConstruct * *aSubtitle) { return _to GetSubtitle(aSubtitle); } \
  NS_SCRIPTABLE NS_IMETHOD SetSubtitle(nsIFeedTextConstruct * aSubtitle) { return _to SetSubtitle(aSubtitle); } \
  NS_SCRIPTABLE NS_IMETHOD GetType(PRUint32 *aType) { return _to GetType(aType); } \
  NS_SCRIPTABLE NS_IMETHOD GetEnclosureCount(PRInt32 *aEnclosureCount) { return _to GetEnclosureCount(aEnclosureCount); } \
  NS_SCRIPTABLE NS_IMETHOD SetEnclosureCount(PRInt32 aEnclosureCount) { return _to SetEnclosureCount(aEnclosureCount); } \
  NS_SCRIPTABLE NS_IMETHOD GetItems(nsIArray * *aItems) { return _to GetItems(aItems); } \
  NS_SCRIPTABLE NS_IMETHOD SetItems(nsIArray * aItems) { return _to SetItems(aItems); } \
  NS_SCRIPTABLE NS_IMETHOD GetCloud(nsIWritablePropertyBag2 * *aCloud) { return _to GetCloud(aCloud); } \
  NS_SCRIPTABLE NS_IMETHOD SetCloud(nsIWritablePropertyBag2 * aCloud) { return _to SetCloud(aCloud); } \
  NS_SCRIPTABLE NS_IMETHOD GetGenerator(nsIFeedGenerator * *aGenerator) { return _to GetGenerator(aGenerator); } \
  NS_SCRIPTABLE NS_IMETHOD SetGenerator(nsIFeedGenerator * aGenerator) { return _to SetGenerator(aGenerator); } \
  NS_SCRIPTABLE NS_IMETHOD GetImage(nsIWritablePropertyBag2 * *aImage) { return _to GetImage(aImage); } \
  NS_SCRIPTABLE NS_IMETHOD SetImage(nsIWritablePropertyBag2 * aImage) { return _to SetImage(aImage); } \
  NS_SCRIPTABLE NS_IMETHOD GetTextInput(nsIWritablePropertyBag2 * *aTextInput) { return _to GetTextInput(aTextInput); } \
  NS_SCRIPTABLE NS_IMETHOD SetTextInput(nsIWritablePropertyBag2 * aTextInput) { return _to SetTextInput(aTextInput); } \
  NS_SCRIPTABLE NS_IMETHOD GetSkipDays(nsIArray * *aSkipDays) { return _to GetSkipDays(aSkipDays); } \
  NS_SCRIPTABLE NS_IMETHOD SetSkipDays(nsIArray * aSkipDays) { return _to SetSkipDays(aSkipDays); } \
  NS_SCRIPTABLE NS_IMETHOD GetSkipHours(nsIArray * *aSkipHours) { return _to GetSkipHours(aSkipHours); } \
  NS_SCRIPTABLE NS_IMETHOD SetSkipHours(nsIArray * aSkipHours) { return _to SetSkipHours(aSkipHours); } 

/* Use this macro to declare functions that forward the behavior of this interface to another object in a safe way. */
#define NS_FORWARD_SAFE_NSIFEED(_to) \
  NS_SCRIPTABLE NS_IMETHOD GetSubtitle(nsIFeedTextConstruct * *aSubtitle) { return !_to ? NS_ERROR_NULL_POINTER : _to->GetSubtitle(aSubtitle); } \
  NS_SCRIPTABLE NS_IMETHOD SetSubtitle(nsIFeedTextConstruct * aSubtitle) { return !_to ? NS_ERROR_NULL_POINTER : _to->SetSubtitle(aSubtitle); } \
  NS_SCRIPTABLE NS_IMETHOD GetType(PRUint32 *aType) { return !_to ? NS_ERROR_NULL_POINTER : _to->GetType(aType); } \
  NS_SCRIPTABLE NS_IMETHOD GetEnclosureCount(PRInt32 *aEnclosureCount) { return !_to ? NS_ERROR_NULL_POINTER : _to->GetEnclosureCount(aEnclosureCount); } \
  NS_SCRIPTABLE NS_IMETHOD SetEnclosureCount(PRInt32 aEnclosureCount) { return !_to ? NS_ERROR_NULL_POINTER : _to->SetEnclosureCount(aEnclosureCount); } \
  NS_SCRIPTABLE NS_IMETHOD GetItems(nsIArray * *aItems) { return !_to ? NS_ERROR_NULL_POINTER : _to->GetItems(aItems); } \
  NS_SCRIPTABLE NS_IMETHOD SetItems(nsIArray * aItems) { return !_to ? NS_ERROR_NULL_POINTER : _to->SetItems(aItems); } \
  NS_SCRIPTABLE NS_IMETHOD GetCloud(nsIWritablePropertyBag2 * *aCloud) { return !_to ? NS_ERROR_NULL_POINTER : _to->GetCloud(aCloud); } \
  NS_SCRIPTABLE NS_IMETHOD SetCloud(nsIWritablePropertyBag2 * aCloud) { return !_to ? NS_ERROR_NULL_POINTER : _to->SetCloud(aCloud); } \
  NS_SCRIPTABLE NS_IMETHOD GetGenerator(nsIFeedGenerator * *aGenerator) { return !_to ? NS_ERROR_NULL_POINTER : _to->GetGenerator(aGenerator); } \
  NS_SCRIPTABLE NS_IMETHOD SetGenerator(nsIFeedGenerator * aGenerator) { return !_to ? NS_ERROR_NULL_POINTER : _to->SetGenerator(aGenerator); } \
  NS_SCRIPTABLE NS_IMETHOD GetImage(nsIWritablePropertyBag2 * *aImage) { return !_to ? NS_ERROR_NULL_POINTER : _to->GetImage(aImage); } \
  NS_SCRIPTABLE NS_IMETHOD SetImage(nsIWritablePropertyBag2 * aImage) { return !_to ? NS_ERROR_NULL_POINTER : _to->SetImage(aImage); } \
  NS_SCRIPTABLE NS_IMETHOD GetTextInput(nsIWritablePropertyBag2 * *aTextInput) { return !_to ? NS_ERROR_NULL_POINTER : _to->GetTextInput(aTextInput); } \
  NS_SCRIPTABLE NS_IMETHOD SetTextInput(nsIWritablePropertyBag2 * aTextInput) { return !_to ? NS_ERROR_NULL_POINTER : _to->SetTextInput(aTextInput); } \
  NS_SCRIPTABLE NS_IMETHOD GetSkipDays(nsIArray * *aSkipDays) { return !_to ? NS_ERROR_NULL_POINTER : _to->GetSkipDays(aSkipDays); } \
  NS_SCRIPTABLE NS_IMETHOD SetSkipDays(nsIArray * aSkipDays) { return !_to ? NS_ERROR_NULL_POINTER : _to->SetSkipDays(aSkipDays); } \
  NS_SCRIPTABLE NS_IMETHOD GetSkipHours(nsIArray * *aSkipHours) { return !_to ? NS_ERROR_NULL_POINTER : _to->GetSkipHours(aSkipHours); } \
  NS_SCRIPTABLE NS_IMETHOD SetSkipHours(nsIArray * aSkipHours) { return !_to ? NS_ERROR_NULL_POINTER : _to->SetSkipHours(aSkipHours); } 

#if 0
/* Use the code below as a template for the implementation class for this interface. */

/* Header file */
class nsFeed : public nsIFeed
{
public:
  NS_DECL_ISUPPORTS
  NS_DECL_NSIFEED

  nsFeed();

private:
  ~nsFeed();

protected:
  /* additional members */
};

/* Implementation file */
NS_IMPL_ISUPPORTS1(nsFeed, nsIFeed)

nsFeed::nsFeed()
{
  /* member initializers and constructor code */
}

nsFeed::~nsFeed()
{
  /* destructor code */
}

/* attribute nsIFeedTextConstruct subtitle; */
NS_IMETHODIMP nsFeed::GetSubtitle(nsIFeedTextConstruct * *aSubtitle)
{
    return NS_ERROR_NOT_IMPLEMENTED;
}
NS_IMETHODIMP nsFeed::SetSubtitle(nsIFeedTextConstruct * aSubtitle)
{
    return NS_ERROR_NOT_IMPLEMENTED;
}

/* readonly attribute unsigned long type; */
NS_IMETHODIMP nsFeed::GetType(PRUint32 *aType)
{
    return NS_ERROR_NOT_IMPLEMENTED;
}

/* attribute long enclosureCount; */
NS_IMETHODIMP nsFeed::GetEnclosureCount(PRInt32 *aEnclosureCount)
{
    return NS_ERROR_NOT_IMPLEMENTED;
}
NS_IMETHODIMP nsFeed::SetEnclosureCount(PRInt32 aEnclosureCount)
{
    return NS_ERROR_NOT_IMPLEMENTED;
}

/* attribute nsIArray items; */
NS_IMETHODIMP nsFeed::GetItems(nsIArray * *aItems)
{
    return NS_ERROR_NOT_IMPLEMENTED;
}
NS_IMETHODIMP nsFeed::SetItems(nsIArray * aItems)
{
    return NS_ERROR_NOT_IMPLEMENTED;
}

/* attribute nsIWritablePropertyBag2 cloud; */
NS_IMETHODIMP nsFeed::GetCloud(nsIWritablePropertyBag2 * *aCloud)
{
    return NS_ERROR_NOT_IMPLEMENTED;
}
NS_IMETHODIMP nsFeed::SetCloud(nsIWritablePropertyBag2 * aCloud)
{
    return NS_ERROR_NOT_IMPLEMENTED;
}

/* attribute nsIFeedGenerator generator; */
NS_IMETHODIMP nsFeed::GetGenerator(nsIFeedGenerator * *aGenerator)
{
    return NS_ERROR_NOT_IMPLEMENTED;
}
NS_IMETHODIMP nsFeed::SetGenerator(nsIFeedGenerator * aGenerator)
{
    return NS_ERROR_NOT_IMPLEMENTED;
}

/* attribute nsIWritablePropertyBag2 image; */
NS_IMETHODIMP nsFeed::GetImage(nsIWritablePropertyBag2 * *aImage)
{
    return NS_ERROR_NOT_IMPLEMENTED;
}
NS_IMETHODIMP nsFeed::SetImage(nsIWritablePropertyBag2 * aImage)
{
    return NS_ERROR_NOT_IMPLEMENTED;
}

/* attribute nsIWritablePropertyBag2 textInput; */
NS_IMETHODIMP nsFeed::GetTextInput(nsIWritablePropertyBag2 * *aTextInput)
{
    return NS_ERROR_NOT_IMPLEMENTED;
}
NS_IMETHODIMP nsFeed::SetTextInput(nsIWritablePropertyBag2 * aTextInput)
{
    return NS_ERROR_NOT_IMPLEMENTED;
}

/* attribute nsIArray skipDays; */
NS_IMETHODIMP nsFeed::GetSkipDays(nsIArray * *aSkipDays)
{
    return NS_ERROR_NOT_IMPLEMENTED;
}
NS_IMETHODIMP nsFeed::SetSkipDays(nsIArray * aSkipDays)
{
    return NS_ERROR_NOT_IMPLEMENTED;
}

/* attribute nsIArray skipHours; */
NS_IMETHODIMP nsFeed::GetSkipHours(nsIArray * *aSkipHours)
{
    return NS_ERROR_NOT_IMPLEMENTED;
}
NS_IMETHODIMP nsFeed::SetSkipHours(nsIArray * aSkipHours)
{
    return NS_ERROR_NOT_IMPLEMENTED;
}

/* End of implementation class template. */
#endif


#endif /* __gen_nsIFeed_h__ */
