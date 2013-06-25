/*
 * DO NOT EDIT.  THIS FILE IS GENERATED FROM e:/builds/moz2_slave/mozilla-1.9.1-win32-xulrunner/build/webshell/public/nsIContentViewerContainer.idl
 */

#ifndef __gen_nsIContentViewerContainer_h__
#define __gen_nsIContentViewerContainer_h__


#ifndef __gen_nsISupports_h__
#include "nsISupports.h"
#endif

/* For IDL files that don't want to include root IDL files. */
#ifndef NS_NO_VTABLE
#define NS_NO_VTABLE
#endif
class nsIContentViewer; /* forward declaration */


/* starting interface:    nsIContentViewerContainer */
#define NS_ICONTENTVIEWERCONTAINER_IID_STR "ea2ce7a0-5c3d-11d4-90c2-0050041caf44"

#define NS_ICONTENTVIEWERCONTAINER_IID \
  {0xea2ce7a0, 0x5c3d, 0x11d4, \
    { 0x90, 0xc2, 0x00, 0x50, 0x04, 0x1c, 0xaf, 0x44 }}

class NS_NO_VTABLE NS_SCRIPTABLE nsIContentViewerContainer : public nsISupports {
 public: 

  NS_DECLARE_STATIC_IID_ACCESSOR(NS_ICONTENTVIEWERCONTAINER_IID)

  /* void embed (in nsIContentViewer aDocViewer, in string aCommand, in nsISupports aExtraInfo); */
  NS_SCRIPTABLE NS_IMETHOD Embed(nsIContentViewer *aDocViewer, const char *aCommand, nsISupports *aExtraInfo) = 0;

  /**
   * Allows the PrintEngine to make this call on 
   * an internal interface to the DocShell
   */
  /* void setIsPrinting (in boolean aIsPrinting); */
  NS_SCRIPTABLE NS_IMETHOD SetIsPrinting(PRBool aIsPrinting) = 0;

};

  NS_DEFINE_STATIC_IID_ACCESSOR(nsIContentViewerContainer, NS_ICONTENTVIEWERCONTAINER_IID)

/* Use this macro when declaring classes that implement this interface. */
#define NS_DECL_NSICONTENTVIEWERCONTAINER \
  NS_SCRIPTABLE NS_IMETHOD Embed(nsIContentViewer *aDocViewer, const char *aCommand, nsISupports *aExtraInfo); \
  NS_SCRIPTABLE NS_IMETHOD SetIsPrinting(PRBool aIsPrinting); 

/* Use this macro to declare functions that forward the behavior of this interface to another object. */
#define NS_FORWARD_NSICONTENTVIEWERCONTAINER(_to) \
  NS_SCRIPTABLE NS_IMETHOD Embed(nsIContentViewer *aDocViewer, const char *aCommand, nsISupports *aExtraInfo) { return _to Embed(aDocViewer, aCommand, aExtraInfo); } \
  NS_SCRIPTABLE NS_IMETHOD SetIsPrinting(PRBool aIsPrinting) { return _to SetIsPrinting(aIsPrinting); } 

/* Use this macro to declare functions that forward the behavior of this interface to another object in a safe way. */
#define NS_FORWARD_SAFE_NSICONTENTVIEWERCONTAINER(_to) \
  NS_SCRIPTABLE NS_IMETHOD Embed(nsIContentViewer *aDocViewer, const char *aCommand, nsISupports *aExtraInfo) { return !_to ? NS_ERROR_NULL_POINTER : _to->Embed(aDocViewer, aCommand, aExtraInfo); } \
  NS_SCRIPTABLE NS_IMETHOD SetIsPrinting(PRBool aIsPrinting) { return !_to ? NS_ERROR_NULL_POINTER : _to->SetIsPrinting(aIsPrinting); } 

#if 0
/* Use the code below as a template for the implementation class for this interface. */

/* Header file */
class nsContentViewerContainer : public nsIContentViewerContainer
{
public:
  NS_DECL_ISUPPORTS
  NS_DECL_NSICONTENTVIEWERCONTAINER

  nsContentViewerContainer();

private:
  ~nsContentViewerContainer();

protected:
  /* additional members */
};

/* Implementation file */
NS_IMPL_ISUPPORTS1(nsContentViewerContainer, nsIContentViewerContainer)

nsContentViewerContainer::nsContentViewerContainer()
{
  /* member initializers and constructor code */
}

nsContentViewerContainer::~nsContentViewerContainer()
{
  /* destructor code */
}

/* void embed (in nsIContentViewer aDocViewer, in string aCommand, in nsISupports aExtraInfo); */
NS_IMETHODIMP nsContentViewerContainer::Embed(nsIContentViewer *aDocViewer, const char *aCommand, nsISupports *aExtraInfo)
{
    return NS_ERROR_NOT_IMPLEMENTED;
}

/* void setIsPrinting (in boolean aIsPrinting); */
NS_IMETHODIMP nsContentViewerContainer::SetIsPrinting(PRBool aIsPrinting)
{
    return NS_ERROR_NOT_IMPLEMENTED;
}

/* End of implementation class template. */
#endif


#endif /* __gen_nsIContentViewerContainer_h__ */
