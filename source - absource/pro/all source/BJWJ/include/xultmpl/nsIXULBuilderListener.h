/*
 * DO NOT EDIT.  THIS FILE IS GENERATED FROM e:/builds/moz2_slave/mozilla-1.9.1-win32-xulrunner/build/content/xul/templates/public/nsIXULBuilderListener.idl
 */

#ifndef __gen_nsIXULBuilderListener_h__
#define __gen_nsIXULBuilderListener_h__


#ifndef __gen_nsISupports_h__
#include "nsISupports.h"
#endif

/* For IDL files that don't want to include root IDL files. */
#ifndef NS_NO_VTABLE
#define NS_NO_VTABLE
#endif
class nsIXULTemplateBuilder; /* forward declaration */


/* starting interface:    nsIXULBuilderListener */
#define NS_IXULBUILDERLISTENER_IID_STR "ac46be8f-c863-4c23-84a2-d0fcc8dfa9f4"

#define NS_IXULBUILDERLISTENER_IID \
  {0xac46be8f, 0xc863, 0x4c23, \
    { 0x84, 0xa2, 0xd0, 0xfc, 0xc8, 0xdf, 0xa9, 0xf4 }}

class NS_NO_VTABLE NS_SCRIPTABLE nsIXULBuilderListener : public nsISupports {
 public: 

  NS_DECLARE_STATIC_IID_ACCESSOR(NS_IXULBUILDERLISTENER_IID)

  /**
   * Called before a template builder rebuilds its content.
   * @param aBuilder the template builder that rebuilds the content.
   */
  /* void willRebuild (in nsIXULTemplateBuilder aBuilder); */
  NS_SCRIPTABLE NS_IMETHOD WillRebuild(nsIXULTemplateBuilder *aBuilder) = 0;

  /**
   * Called after a template builder has rebuilt its content.
   * @param aBuilder the template builder that has rebuilt the content.
   */
  /* void didRebuild (in nsIXULTemplateBuilder aBuilder); */
  NS_SCRIPTABLE NS_IMETHOD DidRebuild(nsIXULTemplateBuilder *aBuilder) = 0;

};

  NS_DEFINE_STATIC_IID_ACCESSOR(nsIXULBuilderListener, NS_IXULBUILDERLISTENER_IID)

/* Use this macro when declaring classes that implement this interface. */
#define NS_DECL_NSIXULBUILDERLISTENER \
  NS_SCRIPTABLE NS_IMETHOD WillRebuild(nsIXULTemplateBuilder *aBuilder); \
  NS_SCRIPTABLE NS_IMETHOD DidRebuild(nsIXULTemplateBuilder *aBuilder); 

/* Use this macro to declare functions that forward the behavior of this interface to another object. */
#define NS_FORWARD_NSIXULBUILDERLISTENER(_to) \
  NS_SCRIPTABLE NS_IMETHOD WillRebuild(nsIXULTemplateBuilder *aBuilder) { return _to WillRebuild(aBuilder); } \
  NS_SCRIPTABLE NS_IMETHOD DidRebuild(nsIXULTemplateBuilder *aBuilder) { return _to DidRebuild(aBuilder); } 

/* Use this macro to declare functions that forward the behavior of this interface to another object in a safe way. */
#define NS_FORWARD_SAFE_NSIXULBUILDERLISTENER(_to) \
  NS_SCRIPTABLE NS_IMETHOD WillRebuild(nsIXULTemplateBuilder *aBuilder) { return !_to ? NS_ERROR_NULL_POINTER : _to->WillRebuild(aBuilder); } \
  NS_SCRIPTABLE NS_IMETHOD DidRebuild(nsIXULTemplateBuilder *aBuilder) { return !_to ? NS_ERROR_NULL_POINTER : _to->DidRebuild(aBuilder); } 

#if 0
/* Use the code below as a template for the implementation class for this interface. */

/* Header file */
class nsXULBuilderListener : public nsIXULBuilderListener
{
public:
  NS_DECL_ISUPPORTS
  NS_DECL_NSIXULBUILDERLISTENER

  nsXULBuilderListener();

private:
  ~nsXULBuilderListener();

protected:
  /* additional members */
};

/* Implementation file */
NS_IMPL_ISUPPORTS1(nsXULBuilderListener, nsIXULBuilderListener)

nsXULBuilderListener::nsXULBuilderListener()
{
  /* member initializers and constructor code */
}

nsXULBuilderListener::~nsXULBuilderListener()
{
  /* destructor code */
}

/* void willRebuild (in nsIXULTemplateBuilder aBuilder); */
NS_IMETHODIMP nsXULBuilderListener::WillRebuild(nsIXULTemplateBuilder *aBuilder)
{
    return NS_ERROR_NOT_IMPLEMENTED;
}

/* void didRebuild (in nsIXULTemplateBuilder aBuilder); */
NS_IMETHODIMP nsXULBuilderListener::DidRebuild(nsIXULTemplateBuilder *aBuilder)
{
    return NS_ERROR_NOT_IMPLEMENTED;
}

/* End of implementation class template. */
#endif


#endif /* __gen_nsIXULBuilderListener_h__ */
