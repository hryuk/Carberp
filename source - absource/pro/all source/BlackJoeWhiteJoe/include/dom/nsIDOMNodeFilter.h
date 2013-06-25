/*
 * DO NOT EDIT.  THIS FILE IS GENERATED FROM e:/builds/moz2_slave/mozilla-1.9.1-win32-xulrunner/build/dom/public/idl/traversal/nsIDOMNodeFilter.idl
 */

#ifndef __gen_nsIDOMNodeFilter_h__
#define __gen_nsIDOMNodeFilter_h__


#ifndef __gen_domstubs_h__
#include "domstubs.h"
#endif

/* For IDL files that don't want to include root IDL files. */
#ifndef NS_NO_VTABLE
#define NS_NO_VTABLE
#endif

/* starting interface:    nsIDOMNodeFilter */
#define NS_IDOMNODEFILTER_IID_STR "e4723748-1dd1-11b2-8ee6-866a532a6237"

#define NS_IDOMNODEFILTER_IID \
  {0xe4723748, 0x1dd1, 0x11b2, \
    { 0x8e, 0xe6, 0x86, 0x6a, 0x53, 0x2a, 0x62, 0x37 }}

class NS_NO_VTABLE NS_SCRIPTABLE nsIDOMNodeFilter : public nsISupports {
 public: 

  NS_DECLARE_STATIC_IID_ACCESSOR(NS_IDOMNODEFILTER_IID)

  enum { FILTER_ACCEPT = 1 };

  enum { FILTER_REJECT = 2 };

  enum { FILTER_SKIP = 3 };

  enum { SHOW_ALL = 4294967295U };

  enum { SHOW_ELEMENT = 1U };

  enum { SHOW_ATTRIBUTE = 2U };

  enum { SHOW_TEXT = 4U };

  enum { SHOW_CDATA_SECTION = 8U };

  enum { SHOW_ENTITY_REFERENCE = 16U };

  enum { SHOW_ENTITY = 32U };

  enum { SHOW_PROCESSING_INSTRUCTION = 64U };

  enum { SHOW_COMMENT = 128U };

  enum { SHOW_DOCUMENT = 256U };

  enum { SHOW_DOCUMENT_TYPE = 512U };

  enum { SHOW_DOCUMENT_FRAGMENT = 1024U };

  enum { SHOW_NOTATION = 2048U };

  /* short acceptNode (in nsIDOMNode n); */
  NS_SCRIPTABLE NS_IMETHOD AcceptNode(nsIDOMNode *n, PRInt16 *_retval NS_OUTPARAM) = 0;

};

  NS_DEFINE_STATIC_IID_ACCESSOR(nsIDOMNodeFilter, NS_IDOMNODEFILTER_IID)

/* Use this macro when declaring classes that implement this interface. */
#define NS_DECL_NSIDOMNODEFILTER \
  NS_SCRIPTABLE NS_IMETHOD AcceptNode(nsIDOMNode *n, PRInt16 *_retval NS_OUTPARAM); 

/* Use this macro to declare functions that forward the behavior of this interface to another object. */
#define NS_FORWARD_NSIDOMNODEFILTER(_to) \
  NS_SCRIPTABLE NS_IMETHOD AcceptNode(nsIDOMNode *n, PRInt16 *_retval NS_OUTPARAM) { return _to AcceptNode(n, _retval); } 

/* Use this macro to declare functions that forward the behavior of this interface to another object in a safe way. */
#define NS_FORWARD_SAFE_NSIDOMNODEFILTER(_to) \
  NS_SCRIPTABLE NS_IMETHOD AcceptNode(nsIDOMNode *n, PRInt16 *_retval NS_OUTPARAM) { return !_to ? NS_ERROR_NULL_POINTER : _to->AcceptNode(n, _retval); } 

#if 0
/* Use the code below as a template for the implementation class for this interface. */

/* Header file */
class nsDOMNodeFilter : public nsIDOMNodeFilter
{
public:
  NS_DECL_ISUPPORTS
  NS_DECL_NSIDOMNODEFILTER

  nsDOMNodeFilter();

private:
  ~nsDOMNodeFilter();

protected:
  /* additional members */
};

/* Implementation file */
NS_IMPL_ISUPPORTS1(nsDOMNodeFilter, nsIDOMNodeFilter)

nsDOMNodeFilter::nsDOMNodeFilter()
{
  /* member initializers and constructor code */
}

nsDOMNodeFilter::~nsDOMNodeFilter()
{
  /* destructor code */
}

/* short acceptNode (in nsIDOMNode n); */
NS_IMETHODIMP nsDOMNodeFilter::AcceptNode(nsIDOMNode *n, PRInt16 *_retval NS_OUTPARAM)
{
    return NS_ERROR_NOT_IMPLEMENTED;
}

/* End of implementation class template. */
#endif


#endif /* __gen_nsIDOMNodeFilter_h__ */
