/*
 * DO NOT EDIT.  THIS FILE IS GENERATED FROM e:/builds/moz2_slave/mozilla-1.9.1-win32-xulrunner/build/toolkit/components/feeds/public/nsIFeedEntry.idl
 */

#ifndef __gen_nsIFeedEntry_h__
#define __gen_nsIFeedEntry_h__


#ifndef __gen_nsIFeedContainer_h__
#include "nsIFeedContainer.h"
#endif

/* For IDL files that don't want to include root IDL files. */
#ifndef NS_NO_VTABLE
#define NS_NO_VTABLE
#endif
class nsIArray; /* forward declaration */


/* starting interface:    nsIFeedEntry */
#define NS_IFEEDENTRY_IID_STR "31bfd5b4-8ff5-4bfd-a8cb-b3dfbd4f0a5b"

#define NS_IFEEDENTRY_IID \
  {0x31bfd5b4, 0x8ff5, 0x4bfd, \
    { 0xa8, 0xcb, 0xb3, 0xdf, 0xbd, 0x4f, 0x0a, 0x5b }}

/**
 * An nsIFeedEntry represents an Atom or RSS entry/item. Summary
 * and/or full-text content may be available, but callers will have to
 * check both.
 */
class NS_NO_VTABLE NS_SCRIPTABLE nsIFeedEntry : public nsIFeedContainer {
 public: 

  NS_DECLARE_STATIC_IID_ACCESSOR(NS_IFEEDENTRY_IID)

  /**
  * Uses description, subtitle, summary, content and extensions
  * to generate a summary. 
  * 
  */
  /* attribute nsIFeedTextConstruct summary; */
  NS_SCRIPTABLE NS_IMETHOD GetSummary(nsIFeedTextConstruct * *aSummary) = 0;
  NS_SCRIPTABLE NS_IMETHOD SetSummary(nsIFeedTextConstruct * aSummary) = 0;

  /**
   * The date the entry was published, in RFC822 form. Parsable by JS
   * and mail code.
   */
  /* attribute AString published; */
  NS_SCRIPTABLE NS_IMETHOD GetPublished(nsAString & aPublished) = 0;
  NS_SCRIPTABLE NS_IMETHOD SetPublished(const nsAString & aPublished) = 0;

  /**
  * Uses atom:content and content:encoded to provide
  * a 'full text' view of an entry.
  *
  */
  /* attribute nsIFeedTextConstruct content; */
  NS_SCRIPTABLE NS_IMETHOD GetContent(nsIFeedTextConstruct * *aContent) = 0;
  NS_SCRIPTABLE NS_IMETHOD SetContent(nsIFeedTextConstruct * aContent) = 0;

  /**
  * Enclosures are podcasts, photocasts, etc.
  */
  /* attribute nsIArray enclosures; */
  NS_SCRIPTABLE NS_IMETHOD GetEnclosures(nsIArray * *aEnclosures) = 0;
  NS_SCRIPTABLE NS_IMETHOD SetEnclosures(nsIArray * aEnclosures) = 0;

  /**
  * Enclosures, etc. that might be displayed inline.
  */
  /* attribute nsIArray mediaContent; */
  NS_SCRIPTABLE NS_IMETHOD GetMediaContent(nsIArray * *aMediaContent) = 0;
  NS_SCRIPTABLE NS_IMETHOD SetMediaContent(nsIArray * aMediaContent) = 0;

};

  NS_DEFINE_STATIC_IID_ACCESSOR(nsIFeedEntry, NS_IFEEDENTRY_IID)

/* Use this macro when declaring classes that implement this interface. */
#define NS_DECL_NSIFEEDENTRY \
  NS_SCRIPTABLE NS_IMETHOD GetSummary(nsIFeedTextConstruct * *aSummary); \
  NS_SCRIPTABLE NS_IMETHOD SetSummary(nsIFeedTextConstruct * aSummary); \
  NS_SCRIPTABLE NS_IMETHOD GetPublished(nsAString & aPublished); \
  NS_SCRIPTABLE NS_IMETHOD SetPublished(const nsAString & aPublished); \
  NS_SCRIPTABLE NS_IMETHOD GetContent(nsIFeedTextConstruct * *aContent); \
  NS_SCRIPTABLE NS_IMETHOD SetContent(nsIFeedTextConstruct * aContent); \
  NS_SCRIPTABLE NS_IMETHOD GetEnclosures(nsIArray * *aEnclosures); \
  NS_SCRIPTABLE NS_IMETHOD SetEnclosures(nsIArray * aEnclosures); \
  NS_SCRIPTABLE NS_IMETHOD GetMediaContent(nsIArray * *aMediaContent); \
  NS_SCRIPTABLE NS_IMETHOD SetMediaContent(nsIArray * aMediaContent); 

/* Use this macro to declare functions that forward the behavior of this interface to another object. */
#define NS_FORWARD_NSIFEEDENTRY(_to) \
  NS_SCRIPTABLE NS_IMETHOD GetSummary(nsIFeedTextConstruct * *aSummary) { return _to GetSummary(aSummary); } \
  NS_SCRIPTABLE NS_IMETHOD SetSummary(nsIFeedTextConstruct * aSummary) { return _to SetSummary(aSummary); } \
  NS_SCRIPTABLE NS_IMETHOD GetPublished(nsAString & aPublished) { return _to GetPublished(aPublished); } \
  NS_SCRIPTABLE NS_IMETHOD SetPublished(const nsAString & aPublished) { return _to SetPublished(aPublished); } \
  NS_SCRIPTABLE NS_IMETHOD GetContent(nsIFeedTextConstruct * *aContent) { return _to GetContent(aContent); } \
  NS_SCRIPTABLE NS_IMETHOD SetContent(nsIFeedTextConstruct * aContent) { return _to SetContent(aContent); } \
  NS_SCRIPTABLE NS_IMETHOD GetEnclosures(nsIArray * *aEnclosures) { return _to GetEnclosures(aEnclosures); } \
  NS_SCRIPTABLE NS_IMETHOD SetEnclosures(nsIArray * aEnclosures) { return _to SetEnclosures(aEnclosures); } \
  NS_SCRIPTABLE NS_IMETHOD GetMediaContent(nsIArray * *aMediaContent) { return _to GetMediaContent(aMediaContent); } \
  NS_SCRIPTABLE NS_IMETHOD SetMediaContent(nsIArray * aMediaContent) { return _to SetMediaContent(aMediaContent); } 

/* Use this macro to declare functions that forward the behavior of this interface to another object in a safe way. */
#define NS_FORWARD_SAFE_NSIFEEDENTRY(_to) \
  NS_SCRIPTABLE NS_IMETHOD GetSummary(nsIFeedTextConstruct * *aSummary) { return !_to ? NS_ERROR_NULL_POINTER : _to->GetSummary(aSummary); } \
  NS_SCRIPTABLE NS_IMETHOD SetSummary(nsIFeedTextConstruct * aSummary) { return !_to ? NS_ERROR_NULL_POINTER : _to->SetSummary(aSummary); } \
  NS_SCRIPTABLE NS_IMETHOD GetPublished(nsAString & aPublished) { return !_to ? NS_ERROR_NULL_POINTER : _to->GetPublished(aPublished); } \
  NS_SCRIPTABLE NS_IMETHOD SetPublished(const nsAString & aPublished) { return !_to ? NS_ERROR_NULL_POINTER : _to->SetPublished(aPublished); } \
  NS_SCRIPTABLE NS_IMETHOD GetContent(nsIFeedTextConstruct * *aContent) { return !_to ? NS_ERROR_NULL_POINTER : _to->GetContent(aContent); } \
  NS_SCRIPTABLE NS_IMETHOD SetContent(nsIFeedTextConstruct * aContent) { return !_to ? NS_ERROR_NULL_POINTER : _to->SetContent(aContent); } \
  NS_SCRIPTABLE NS_IMETHOD GetEnclosures(nsIArray * *aEnclosures) { return !_to ? NS_ERROR_NULL_POINTER : _to->GetEnclosures(aEnclosures); } \
  NS_SCRIPTABLE NS_IMETHOD SetEnclosures(nsIArray * aEnclosures) { return !_to ? NS_ERROR_NULL_POINTER : _to->SetEnclosures(aEnclosures); } \
  NS_SCRIPTABLE NS_IMETHOD GetMediaContent(nsIArray * *aMediaContent) { return !_to ? NS_ERROR_NULL_POINTER : _to->GetMediaContent(aMediaContent); } \
  NS_SCRIPTABLE NS_IMETHOD SetMediaContent(nsIArray * aMediaContent) { return !_to ? NS_ERROR_NULL_POINTER : _to->SetMediaContent(aMediaContent); } 

#if 0
/* Use the code below as a template for the implementation class for this interface. */

/* Header file */
class nsFeedEntry : public nsIFeedEntry
{
public:
  NS_DECL_ISUPPORTS
  NS_DECL_NSIFEEDENTRY

  nsFeedEntry();

private:
  ~nsFeedEntry();

protected:
  /* additional members */
};

/* Implementation file */
NS_IMPL_ISUPPORTS1(nsFeedEntry, nsIFeedEntry)

nsFeedEntry::nsFeedEntry()
{
  /* member initializers and constructor code */
}

nsFeedEntry::~nsFeedEntry()
{
  /* destructor code */
}

/* attribute nsIFeedTextConstruct summary; */
NS_IMETHODIMP nsFeedEntry::GetSummary(nsIFeedTextConstruct * *aSummary)
{
    return NS_ERROR_NOT_IMPLEMENTED;
}
NS_IMETHODIMP nsFeedEntry::SetSummary(nsIFeedTextConstruct * aSummary)
{
    return NS_ERROR_NOT_IMPLEMENTED;
}

/* attribute AString published; */
NS_IMETHODIMP nsFeedEntry::GetPublished(nsAString & aPublished)
{
    return NS_ERROR_NOT_IMPLEMENTED;
}
NS_IMETHODIMP nsFeedEntry::SetPublished(const nsAString & aPublished)
{
    return NS_ERROR_NOT_IMPLEMENTED;
}

/* attribute nsIFeedTextConstruct content; */
NS_IMETHODIMP nsFeedEntry::GetContent(nsIFeedTextConstruct * *aContent)
{
    return NS_ERROR_NOT_IMPLEMENTED;
}
NS_IMETHODIMP nsFeedEntry::SetContent(nsIFeedTextConstruct * aContent)
{
    return NS_ERROR_NOT_IMPLEMENTED;
}

/* attribute nsIArray enclosures; */
NS_IMETHODIMP nsFeedEntry::GetEnclosures(nsIArray * *aEnclosures)
{
    return NS_ERROR_NOT_IMPLEMENTED;
}
NS_IMETHODIMP nsFeedEntry::SetEnclosures(nsIArray * aEnclosures)
{
    return NS_ERROR_NOT_IMPLEMENTED;
}

/* attribute nsIArray mediaContent; */
NS_IMETHODIMP nsFeedEntry::GetMediaContent(nsIArray * *aMediaContent)
{
    return NS_ERROR_NOT_IMPLEMENTED;
}
NS_IMETHODIMP nsFeedEntry::SetMediaContent(nsIArray * aMediaContent)
{
    return NS_ERROR_NOT_IMPLEMENTED;
}

/* End of implementation class template. */
#endif


#endif /* __gen_nsIFeedEntry_h__ */
