/*
 * DO NOT EDIT.  THIS FILE IS GENERATED FROM e:/builds/moz2_slave/mozilla-1.9.1-win32-xulrunner/build/netwerk/streamconv/public/nsIDirIndexListener.idl
 */

#ifndef __gen_nsIDirIndexListener_h__
#define __gen_nsIDirIndexListener_h__


#ifndef __gen_nsIStreamListener_h__
#include "nsIStreamListener.h"
#endif

/* For IDL files that don't want to include root IDL files. */
#ifndef NS_NO_VTABLE
#define NS_NO_VTABLE
#endif
class nsIDirIndex; /* forward declaration */


/* starting interface:    nsIDirIndexListener */
#define NS_IDIRINDEXLISTENER_IID_STR "fae4e9a8-1dd1-11b2-b53c-8f3aa1bbf8f5"

#define NS_IDIRINDEXLISTENER_IID \
  {0xfae4e9a8, 0x1dd1, 0x11b2, \
    { 0xb5, 0x3c, 0x8f, 0x3a, 0xa1, 0xbb, 0xf8, 0xf5 }}

/**
 * This interface is used to receive contents of directory index listings
 * from a protocol. They can then be transformed into an output format
 * (such as rdf, html, etc)
 */
class NS_NO_VTABLE NS_SCRIPTABLE nsIDirIndexListener : public nsISupports {
 public: 

  NS_DECLARE_STATIC_IID_ACCESSOR(NS_IDIRINDEXLISTENER_IID)

  /**
     * Called for each directory entry
     *
     * @param request - the request
     * @param ctxt - opaque parameter
     * @param index - new index to add
     */
  /* void onIndexAvailable (in nsIRequest aRequest, in nsISupports aCtxt, in nsIDirIndex aIndex); */
  NS_SCRIPTABLE NS_IMETHOD OnIndexAvailable(nsIRequest *aRequest, nsISupports *aCtxt, nsIDirIndex *aIndex) = 0;

  /**
     * Called for each information line
     *
     * @param request - the request
     * @param ctxt - opaque parameter
     * @param info - new info to add
     */
  /* void onInformationAvailable (in nsIRequest aRequest, in nsISupports aCtxt, in AString aInfo); */
  NS_SCRIPTABLE NS_IMETHOD OnInformationAvailable(nsIRequest *aRequest, nsISupports *aCtxt, const nsAString & aInfo) = 0;

};

  NS_DEFINE_STATIC_IID_ACCESSOR(nsIDirIndexListener, NS_IDIRINDEXLISTENER_IID)

/* Use this macro when declaring classes that implement this interface. */
#define NS_DECL_NSIDIRINDEXLISTENER \
  NS_SCRIPTABLE NS_IMETHOD OnIndexAvailable(nsIRequest *aRequest, nsISupports *aCtxt, nsIDirIndex *aIndex); \
  NS_SCRIPTABLE NS_IMETHOD OnInformationAvailable(nsIRequest *aRequest, nsISupports *aCtxt, const nsAString & aInfo); 

/* Use this macro to declare functions that forward the behavior of this interface to another object. */
#define NS_FORWARD_NSIDIRINDEXLISTENER(_to) \
  NS_SCRIPTABLE NS_IMETHOD OnIndexAvailable(nsIRequest *aRequest, nsISupports *aCtxt, nsIDirIndex *aIndex) { return _to OnIndexAvailable(aRequest, aCtxt, aIndex); } \
  NS_SCRIPTABLE NS_IMETHOD OnInformationAvailable(nsIRequest *aRequest, nsISupports *aCtxt, const nsAString & aInfo) { return _to OnInformationAvailable(aRequest, aCtxt, aInfo); } 

/* Use this macro to declare functions that forward the behavior of this interface to another object in a safe way. */
#define NS_FORWARD_SAFE_NSIDIRINDEXLISTENER(_to) \
  NS_SCRIPTABLE NS_IMETHOD OnIndexAvailable(nsIRequest *aRequest, nsISupports *aCtxt, nsIDirIndex *aIndex) { return !_to ? NS_ERROR_NULL_POINTER : _to->OnIndexAvailable(aRequest, aCtxt, aIndex); } \
  NS_SCRIPTABLE NS_IMETHOD OnInformationAvailable(nsIRequest *aRequest, nsISupports *aCtxt, const nsAString & aInfo) { return !_to ? NS_ERROR_NULL_POINTER : _to->OnInformationAvailable(aRequest, aCtxt, aInfo); } 

#if 0
/* Use the code below as a template for the implementation class for this interface. */

/* Header file */
class nsDirIndexListener : public nsIDirIndexListener
{
public:
  NS_DECL_ISUPPORTS
  NS_DECL_NSIDIRINDEXLISTENER

  nsDirIndexListener();

private:
  ~nsDirIndexListener();

protected:
  /* additional members */
};

/* Implementation file */
NS_IMPL_ISUPPORTS1(nsDirIndexListener, nsIDirIndexListener)

nsDirIndexListener::nsDirIndexListener()
{
  /* member initializers and constructor code */
}

nsDirIndexListener::~nsDirIndexListener()
{
  /* destructor code */
}

/* void onIndexAvailable (in nsIRequest aRequest, in nsISupports aCtxt, in nsIDirIndex aIndex); */
NS_IMETHODIMP nsDirIndexListener::OnIndexAvailable(nsIRequest *aRequest, nsISupports *aCtxt, nsIDirIndex *aIndex)
{
    return NS_ERROR_NOT_IMPLEMENTED;
}

/* void onInformationAvailable (in nsIRequest aRequest, in nsISupports aCtxt, in AString aInfo); */
NS_IMETHODIMP nsDirIndexListener::OnInformationAvailable(nsIRequest *aRequest, nsISupports *aCtxt, const nsAString & aInfo)
{
    return NS_ERROR_NOT_IMPLEMENTED;
}

/* End of implementation class template. */
#endif

#define NS_IDIRINDEXLISTENER_KEY         "@mozilla.org/dirIndexListener;1"

/* starting interface:    nsIDirIndexParser */
#define NS_IDIRINDEXPARSER_IID_STR "38e3066c-1dd2-11b2-9b59-8be515c1ee3f"

#define NS_IDIRINDEXPARSER_IID \
  {0x38e3066c, 0x1dd2, 0x11b2, \
    { 0x9b, 0x59, 0x8b, 0xe5, 0x15, 0xc1, 0xee, 0x3f }}

/**
 * A parser for application/http-index-format
 */
class NS_NO_VTABLE NS_SCRIPTABLE nsIDirIndexParser : public nsIStreamListener {
 public: 

  NS_DECLARE_STATIC_IID_ACCESSOR(NS_IDIRINDEXPARSER_IID)

  /**
     * The interface to use as a callback for new entries
     */
  /* attribute nsIDirIndexListener listener; */
  NS_SCRIPTABLE NS_IMETHOD GetListener(nsIDirIndexListener * *aListener) = 0;
  NS_SCRIPTABLE NS_IMETHOD SetListener(nsIDirIndexListener * aListener) = 0;

  /**
     * The comment given, if any
     * This result is only valid _after_ OnStopRequest has occurred,
     * because it can occur anywhere in the datastream
     */
  /* readonly attribute string comment; */
  NS_SCRIPTABLE NS_IMETHOD GetComment(char * *aComment) = 0;

  /**
     * The encoding to use
     */
  /* attribute string encoding; */
  NS_SCRIPTABLE NS_IMETHOD GetEncoding(char * *aEncoding) = 0;
  NS_SCRIPTABLE NS_IMETHOD SetEncoding(const char * aEncoding) = 0;

};

  NS_DEFINE_STATIC_IID_ACCESSOR(nsIDirIndexParser, NS_IDIRINDEXPARSER_IID)

/* Use this macro when declaring classes that implement this interface. */
#define NS_DECL_NSIDIRINDEXPARSER \
  NS_SCRIPTABLE NS_IMETHOD GetListener(nsIDirIndexListener * *aListener); \
  NS_SCRIPTABLE NS_IMETHOD SetListener(nsIDirIndexListener * aListener); \
  NS_SCRIPTABLE NS_IMETHOD GetComment(char * *aComment); \
  NS_SCRIPTABLE NS_IMETHOD GetEncoding(char * *aEncoding); \
  NS_SCRIPTABLE NS_IMETHOD SetEncoding(const char * aEncoding); 

/* Use this macro to declare functions that forward the behavior of this interface to another object. */
#define NS_FORWARD_NSIDIRINDEXPARSER(_to) \
  NS_SCRIPTABLE NS_IMETHOD GetListener(nsIDirIndexListener * *aListener) { return _to GetListener(aListener); } \
  NS_SCRIPTABLE NS_IMETHOD SetListener(nsIDirIndexListener * aListener) { return _to SetListener(aListener); } \
  NS_SCRIPTABLE NS_IMETHOD GetComment(char * *aComment) { return _to GetComment(aComment); } \
  NS_SCRIPTABLE NS_IMETHOD GetEncoding(char * *aEncoding) { return _to GetEncoding(aEncoding); } \
  NS_SCRIPTABLE NS_IMETHOD SetEncoding(const char * aEncoding) { return _to SetEncoding(aEncoding); } 

/* Use this macro to declare functions that forward the behavior of this interface to another object in a safe way. */
#define NS_FORWARD_SAFE_NSIDIRINDEXPARSER(_to) \
  NS_SCRIPTABLE NS_IMETHOD GetListener(nsIDirIndexListener * *aListener) { return !_to ? NS_ERROR_NULL_POINTER : _to->GetListener(aListener); } \
  NS_SCRIPTABLE NS_IMETHOD SetListener(nsIDirIndexListener * aListener) { return !_to ? NS_ERROR_NULL_POINTER : _to->SetListener(aListener); } \
  NS_SCRIPTABLE NS_IMETHOD GetComment(char * *aComment) { return !_to ? NS_ERROR_NULL_POINTER : _to->GetComment(aComment); } \
  NS_SCRIPTABLE NS_IMETHOD GetEncoding(char * *aEncoding) { return !_to ? NS_ERROR_NULL_POINTER : _to->GetEncoding(aEncoding); } \
  NS_SCRIPTABLE NS_IMETHOD SetEncoding(const char * aEncoding) { return !_to ? NS_ERROR_NULL_POINTER : _to->SetEncoding(aEncoding); } 

#if 0
/* Use the code below as a template for the implementation class for this interface. */

/* Header file */
class nsDirIndexParser : public nsIDirIndexParser
{
public:
  NS_DECL_ISUPPORTS
  NS_DECL_NSIDIRINDEXPARSER

  nsDirIndexParser();

private:
  ~nsDirIndexParser();

protected:
  /* additional members */
};

/* Implementation file */
NS_IMPL_ISUPPORTS1(nsDirIndexParser, nsIDirIndexParser)

nsDirIndexParser::nsDirIndexParser()
{
  /* member initializers and constructor code */
}

nsDirIndexParser::~nsDirIndexParser()
{
  /* destructor code */
}

/* attribute nsIDirIndexListener listener; */
NS_IMETHODIMP nsDirIndexParser::GetListener(nsIDirIndexListener * *aListener)
{
    return NS_ERROR_NOT_IMPLEMENTED;
}
NS_IMETHODIMP nsDirIndexParser::SetListener(nsIDirIndexListener * aListener)
{
    return NS_ERROR_NOT_IMPLEMENTED;
}

/* readonly attribute string comment; */
NS_IMETHODIMP nsDirIndexParser::GetComment(char * *aComment)
{
    return NS_ERROR_NOT_IMPLEMENTED;
}

/* attribute string encoding; */
NS_IMETHODIMP nsDirIndexParser::GetEncoding(char * *aEncoding)
{
    return NS_ERROR_NOT_IMPLEMENTED;
}
NS_IMETHODIMP nsDirIndexParser::SetEncoding(const char * aEncoding)
{
    return NS_ERROR_NOT_IMPLEMENTED;
}

/* End of implementation class template. */
#endif

#define NS_DIRINDEXPARSER_CID \
{ /* a0d6ad32-1dd1-11b2-aa55-a40187b54036 */ \
    0xa0d6ad32, \
    0x1dd1, \
    0x11b2, \
    { 0xaa, 0x55, 0xa4, 0x01, 0x87, 0xb5, 0x40, 0x36 } \
}
#define NS_DIRINDEXPARSER_CONTRACTID "@mozilla.org/dirIndexParser;1"

#endif /* __gen_nsIDirIndexListener_h__ */
