/*
 * DO NOT EDIT.  THIS FILE IS GENERATED FROM e:/builds/moz2_slave/mozilla-1.9.1-win32-xulrunner/build/parser/xml/public/nsISAXXMLFilter.idl
 */

#ifndef __gen_nsISAXXMLFilter_h__
#define __gen_nsISAXXMLFilter_h__


#ifndef __gen_nsISupports_h__
#include "nsISupports.h"
#endif

#ifndef __gen_nsISAXXMLReader_h__
#include "nsISAXXMLReader.h"
#endif

/* For IDL files that don't want to include root IDL files. */
#ifndef NS_NO_VTABLE
#define NS_NO_VTABLE
#endif

/* starting interface:    nsISAXXMLFilter */
#define NS_ISAXXMLFILTER_IID_STR "77a22cf0-6cdf-11da-be43-001422106990"

#define NS_ISAXXMLFILTER_IID \
  {0x77a22cf0, 0x6cdf, 0x11da, \
    { 0xbe, 0x43, 0x00, 0x14, 0x22, 0x10, 0x69, 0x90 }}

/**
 * Interface for an XML filter.
 *
 * An XML filter is like an XML reader, except that it obtains its
 * events from another XML reader rather than a primary source like an
 * XML document or database.  Filters can modify a stream of events as
 * they pass on to the final application.
 */
class NS_NO_VTABLE NS_SCRIPTABLE nsISAXXMLFilter : public nsISAXXMLReader {
 public: 

  NS_DECLARE_STATIC_IID_ACCESSOR(NS_ISAXXMLFILTER_IID)

  /**
   * The parent reader.
   *
   * Allows the application to query the parent reader (which may be
   * another filter).  It is generally a bad idea to perform any
   * operations on the parent reader directly: they should all pass
   * through this filter.
   */
  /* attribute nsISAXXMLReader parent; */
  NS_SCRIPTABLE NS_IMETHOD GetParent(nsISAXXMLReader * *aParent) = 0;
  NS_SCRIPTABLE NS_IMETHOD SetParent(nsISAXXMLReader * aParent) = 0;

};

  NS_DEFINE_STATIC_IID_ACCESSOR(nsISAXXMLFilter, NS_ISAXXMLFILTER_IID)

/* Use this macro when declaring classes that implement this interface. */
#define NS_DECL_NSISAXXMLFILTER \
  NS_SCRIPTABLE NS_IMETHOD GetParent(nsISAXXMLReader * *aParent); \
  NS_SCRIPTABLE NS_IMETHOD SetParent(nsISAXXMLReader * aParent); 

/* Use this macro to declare functions that forward the behavior of this interface to another object. */
#define NS_FORWARD_NSISAXXMLFILTER(_to) \
  NS_SCRIPTABLE NS_IMETHOD GetParent(nsISAXXMLReader * *aParent) { return _to GetParent(aParent); } \
  NS_SCRIPTABLE NS_IMETHOD SetParent(nsISAXXMLReader * aParent) { return _to SetParent(aParent); } 

/* Use this macro to declare functions that forward the behavior of this interface to another object in a safe way. */
#define NS_FORWARD_SAFE_NSISAXXMLFILTER(_to) \
  NS_SCRIPTABLE NS_IMETHOD GetParent(nsISAXXMLReader * *aParent) { return !_to ? NS_ERROR_NULL_POINTER : _to->GetParent(aParent); } \
  NS_SCRIPTABLE NS_IMETHOD SetParent(nsISAXXMLReader * aParent) { return !_to ? NS_ERROR_NULL_POINTER : _to->SetParent(aParent); } 

#if 0
/* Use the code below as a template for the implementation class for this interface. */

/* Header file */
class nsSAXXMLFilter : public nsISAXXMLFilter
{
public:
  NS_DECL_ISUPPORTS
  NS_DECL_NSISAXXMLFILTER

  nsSAXXMLFilter();

private:
  ~nsSAXXMLFilter();

protected:
  /* additional members */
};

/* Implementation file */
NS_IMPL_ISUPPORTS1(nsSAXXMLFilter, nsISAXXMLFilter)

nsSAXXMLFilter::nsSAXXMLFilter()
{
  /* member initializers and constructor code */
}

nsSAXXMLFilter::~nsSAXXMLFilter()
{
  /* destructor code */
}

/* attribute nsISAXXMLReader parent; */
NS_IMETHODIMP nsSAXXMLFilter::GetParent(nsISAXXMLReader * *aParent)
{
    return NS_ERROR_NOT_IMPLEMENTED;
}
NS_IMETHODIMP nsSAXXMLFilter::SetParent(nsISAXXMLReader * aParent)
{
    return NS_ERROR_NOT_IMPLEMENTED;
}

/* End of implementation class template. */
#endif


#endif /* __gen_nsISAXXMLFilter_h__ */
