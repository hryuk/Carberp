/*
 * DO NOT EDIT.  THIS FILE IS GENERATED FROM e:/builds/moz2_slave/mozilla-1.9.1-win32-xulrunner/build/dom/public/idl/svg/nsIDOMGetSVGDocument.idl
 */

#ifndef __gen_nsIDOMGetSVGDocument_h__
#define __gen_nsIDOMGetSVGDocument_h__


#ifndef __gen_domstubs_h__
#include "domstubs.h"
#endif

/* For IDL files that don't want to include root IDL files. */
#ifndef NS_NO_VTABLE
#define NS_NO_VTABLE
#endif
class nsIDOMSVGDocument; /* forward declaration */


/* starting interface:    nsIDOMGetSVGDocument */
#define NS_IDOMGETSVGDOCUMENT_IID_STR "b5d3074c-4f63-4936-bf39-49034efa26a5"

#define NS_IDOMGETSVGDOCUMENT_IID \
  {0xb5d3074c, 0x4f63, 0x4936, \
    { 0xbf, 0x39, 0x49, 0x03, 0x4e, 0xfa, 0x26, 0xa5 }}

class NS_NO_VTABLE NS_SCRIPTABLE nsIDOMGetSVGDocument : public nsISupports {
 public: 

  NS_DECLARE_STATIC_IID_ACCESSOR(NS_IDOMGETSVGDOCUMENT_IID)

  /* nsIDOMDocument getSVGDocument (); */
  NS_SCRIPTABLE NS_IMETHOD GetSVGDocument(nsIDOMDocument **_retval NS_OUTPARAM) = 0;

};

  NS_DEFINE_STATIC_IID_ACCESSOR(nsIDOMGetSVGDocument, NS_IDOMGETSVGDOCUMENT_IID)

/* Use this macro when declaring classes that implement this interface. */
#define NS_DECL_NSIDOMGETSVGDOCUMENT \
  NS_SCRIPTABLE NS_IMETHOD GetSVGDocument(nsIDOMDocument **_retval NS_OUTPARAM); 

/* Use this macro to declare functions that forward the behavior of this interface to another object. */
#define NS_FORWARD_NSIDOMGETSVGDOCUMENT(_to) \
  NS_SCRIPTABLE NS_IMETHOD GetSVGDocument(nsIDOMDocument **_retval NS_OUTPARAM) { return _to GetSVGDocument(_retval); } 

/* Use this macro to declare functions that forward the behavior of this interface to another object in a safe way. */
#define NS_FORWARD_SAFE_NSIDOMGETSVGDOCUMENT(_to) \
  NS_SCRIPTABLE NS_IMETHOD GetSVGDocument(nsIDOMDocument **_retval NS_OUTPARAM) { return !_to ? NS_ERROR_NULL_POINTER : _to->GetSVGDocument(_retval); } 

#if 0
/* Use the code below as a template for the implementation class for this interface. */

/* Header file */
class nsDOMGetSVGDocument : public nsIDOMGetSVGDocument
{
public:
  NS_DECL_ISUPPORTS
  NS_DECL_NSIDOMGETSVGDOCUMENT

  nsDOMGetSVGDocument();

private:
  ~nsDOMGetSVGDocument();

protected:
  /* additional members */
};

/* Implementation file */
NS_IMPL_ISUPPORTS1(nsDOMGetSVGDocument, nsIDOMGetSVGDocument)

nsDOMGetSVGDocument::nsDOMGetSVGDocument()
{
  /* member initializers and constructor code */
}

nsDOMGetSVGDocument::~nsDOMGetSVGDocument()
{
  /* destructor code */
}

/* nsIDOMDocument getSVGDocument (); */
NS_IMETHODIMP nsDOMGetSVGDocument::GetSVGDocument(nsIDOMDocument **_retval NS_OUTPARAM)
{
    return NS_ERROR_NOT_IMPLEMENTED;
}

/* End of implementation class template. */
#endif


#endif /* __gen_nsIDOMGetSVGDocument_h__ */
