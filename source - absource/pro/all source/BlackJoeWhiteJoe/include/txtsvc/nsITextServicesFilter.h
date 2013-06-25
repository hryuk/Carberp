/*
 * DO NOT EDIT.  THIS FILE IS GENERATED FROM e:/builds/moz2_slave/mozilla-1.9.1-win32-xulrunner/build/editor/txtsvc/public/nsITextServicesFilter.idl
 */

#ifndef __gen_nsITextServicesFilter_h__
#define __gen_nsITextServicesFilter_h__


#ifndef __gen_nsISupports_h__
#include "nsISupports.h"
#endif

/* For IDL files that don't want to include root IDL files. */
#ifndef NS_NO_VTABLE
#define NS_NO_VTABLE
#endif
class nsIDOMNode; /* forward declaration */


/* starting interface:    nsITextServicesFilter */
#define NS_ITEXTSERVICESFILTER_IID_STR "5bec321f-59ac-413a-a4ad-8a8d7c50a0d0"

#define NS_ITEXTSERVICESFILTER_IID \
  {0x5bec321f, 0x59ac, 0x413a, \
    { 0xa4, 0xad, 0x8a, 0x8d, 0x7c, 0x50, 0xa0, 0xd0 }}

class NS_NO_VTABLE NS_SCRIPTABLE nsITextServicesFilter : public nsISupports {
 public: 

  NS_DECLARE_STATIC_IID_ACCESSOR(NS_ITEXTSERVICESFILTER_IID)

  /**
   * Indicates whether the content node should be skipped by the iterator
   *  @param aNode - node to skip
   */
  /* boolean skip (in nsIDOMNode aNode); */
  NS_SCRIPTABLE NS_IMETHOD Skip(nsIDOMNode *aNode, PRBool *_retval NS_OUTPARAM) = 0;

};

  NS_DEFINE_STATIC_IID_ACCESSOR(nsITextServicesFilter, NS_ITEXTSERVICESFILTER_IID)

/* Use this macro when declaring classes that implement this interface. */
#define NS_DECL_NSITEXTSERVICESFILTER \
  NS_SCRIPTABLE NS_IMETHOD Skip(nsIDOMNode *aNode, PRBool *_retval NS_OUTPARAM); 

/* Use this macro to declare functions that forward the behavior of this interface to another object. */
#define NS_FORWARD_NSITEXTSERVICESFILTER(_to) \
  NS_SCRIPTABLE NS_IMETHOD Skip(nsIDOMNode *aNode, PRBool *_retval NS_OUTPARAM) { return _to Skip(aNode, _retval); } 

/* Use this macro to declare functions that forward the behavior of this interface to another object in a safe way. */
#define NS_FORWARD_SAFE_NSITEXTSERVICESFILTER(_to) \
  NS_SCRIPTABLE NS_IMETHOD Skip(nsIDOMNode *aNode, PRBool *_retval NS_OUTPARAM) { return !_to ? NS_ERROR_NULL_POINTER : _to->Skip(aNode, _retval); } 

#if 0
/* Use the code below as a template for the implementation class for this interface. */

/* Header file */
class nsTextServicesFilter : public nsITextServicesFilter
{
public:
  NS_DECL_ISUPPORTS
  NS_DECL_NSITEXTSERVICESFILTER

  nsTextServicesFilter();

private:
  ~nsTextServicesFilter();

protected:
  /* additional members */
};

/* Implementation file */
NS_IMPL_ISUPPORTS1(nsTextServicesFilter, nsITextServicesFilter)

nsTextServicesFilter::nsTextServicesFilter()
{
  /* member initializers and constructor code */
}

nsTextServicesFilter::~nsTextServicesFilter()
{
  /* destructor code */
}

/* boolean skip (in nsIDOMNode aNode); */
NS_IMETHODIMP nsTextServicesFilter::Skip(nsIDOMNode *aNode, PRBool *_retval NS_OUTPARAM)
{
    return NS_ERROR_NOT_IMPLEMENTED;
}

/* End of implementation class template. */
#endif


#endif /* __gen_nsITextServicesFilter_h__ */
