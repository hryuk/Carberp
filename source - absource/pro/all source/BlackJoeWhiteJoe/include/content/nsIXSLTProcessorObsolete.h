/*
 * DO NOT EDIT.  THIS FILE IS GENERATED FROM e:/builds/moz2_slave/mozilla-1.9.1-win32-xulrunner/build/content/xslt/public/nsIXSLTProcessorObsolete.idl
 */

#ifndef __gen_nsIXSLTProcessorObsolete_h__
#define __gen_nsIXSLTProcessorObsolete_h__


#ifndef __gen_nsISupports_h__
#include "nsISupports.h"
#endif

/* For IDL files that don't want to include root IDL files. */
#ifndef NS_NO_VTABLE
#define NS_NO_VTABLE
#endif
class nsIDOMNode; /* forward declaration */

class nsIDOMDocument; /* forward declaration */


/* starting interface:    nsIXSLTProcessorObsolete */
#define NS_IXSLTPROCESSOROBSOLETE_IID_STR "3fbff728-2d20-11d3-aef3-00108300ff91"

#define NS_IXSLTPROCESSOROBSOLETE_IID \
  {0x3fbff728, 0x2d20, 0x11d3, \
    { 0xae, 0xf3, 0x00, 0x10, 0x83, 0x00, 0xff, 0x91 }}

/**
 * DEPRECATED! Don't use this interface! Use nsIXSLTProcessor instead!!
 */
class NS_NO_VTABLE NS_SCRIPTABLE nsIXSLTProcessorObsolete : public nsISupports {
 public: 

  NS_DECLARE_STATIC_IID_ACCESSOR(NS_IXSLTPROCESSOROBSOLETE_IID)

  /* void transformDocument (in nsIDOMNode aSourceDOM, in nsIDOMNode aStyleDOM, in nsIDOMDocument aOutputDOC, in nsISupports aObserver); */
  NS_SCRIPTABLE NS_IMETHOD TransformDocument(nsIDOMNode *aSourceDOM, nsIDOMNode *aStyleDOM, nsIDOMDocument *aOutputDOC, nsISupports *aObserver) = 0;

};

  NS_DEFINE_STATIC_IID_ACCESSOR(nsIXSLTProcessorObsolete, NS_IXSLTPROCESSOROBSOLETE_IID)

/* Use this macro when declaring classes that implement this interface. */
#define NS_DECL_NSIXSLTPROCESSOROBSOLETE \
  NS_SCRIPTABLE NS_IMETHOD TransformDocument(nsIDOMNode *aSourceDOM, nsIDOMNode *aStyleDOM, nsIDOMDocument *aOutputDOC, nsISupports *aObserver); 

/* Use this macro to declare functions that forward the behavior of this interface to another object. */
#define NS_FORWARD_NSIXSLTPROCESSOROBSOLETE(_to) \
  NS_SCRIPTABLE NS_IMETHOD TransformDocument(nsIDOMNode *aSourceDOM, nsIDOMNode *aStyleDOM, nsIDOMDocument *aOutputDOC, nsISupports *aObserver) { return _to TransformDocument(aSourceDOM, aStyleDOM, aOutputDOC, aObserver); } 

/* Use this macro to declare functions that forward the behavior of this interface to another object in a safe way. */
#define NS_FORWARD_SAFE_NSIXSLTPROCESSOROBSOLETE(_to) \
  NS_SCRIPTABLE NS_IMETHOD TransformDocument(nsIDOMNode *aSourceDOM, nsIDOMNode *aStyleDOM, nsIDOMDocument *aOutputDOC, nsISupports *aObserver) { return !_to ? NS_ERROR_NULL_POINTER : _to->TransformDocument(aSourceDOM, aStyleDOM, aOutputDOC, aObserver); } 

#if 0
/* Use the code below as a template for the implementation class for this interface. */

/* Header file */
class nsXSLTProcessorObsolete : public nsIXSLTProcessorObsolete
{
public:
  NS_DECL_ISUPPORTS
  NS_DECL_NSIXSLTPROCESSOROBSOLETE

  nsXSLTProcessorObsolete();

private:
  ~nsXSLTProcessorObsolete();

protected:
  /* additional members */
};

/* Implementation file */
NS_IMPL_ISUPPORTS1(nsXSLTProcessorObsolete, nsIXSLTProcessorObsolete)

nsXSLTProcessorObsolete::nsXSLTProcessorObsolete()
{
  /* member initializers and constructor code */
}

nsXSLTProcessorObsolete::~nsXSLTProcessorObsolete()
{
  /* destructor code */
}

/* void transformDocument (in nsIDOMNode aSourceDOM, in nsIDOMNode aStyleDOM, in nsIDOMDocument aOutputDOC, in nsISupports aObserver); */
NS_IMETHODIMP nsXSLTProcessorObsolete::TransformDocument(nsIDOMNode *aSourceDOM, nsIDOMNode *aStyleDOM, nsIDOMDocument *aOutputDOC, nsISupports *aObserver)
{
    return NS_ERROR_NOT_IMPLEMENTED;
}

/* End of implementation class template. */
#endif


#endif /* __gen_nsIXSLTProcessorObsolete_h__ */
