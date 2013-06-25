/*
 * DO NOT EDIT.  THIS FILE IS GENERATED FROM e:/builds/moz2_slave/mozilla-1.9.1-win32-xulrunner/build/modules/plugin/base/public/nsIPluginDocument.idl
 */

#ifndef __gen_nsIPluginDocument_h__
#define __gen_nsIPluginDocument_h__


#ifndef __gen_nsISupports_h__
#include "nsISupports.h"
#endif

#ifndef __gen_nsIStreamListener_h__
#include "nsIStreamListener.h"
#endif

/* For IDL files that don't want to include root IDL files. */
#ifndef NS_NO_VTABLE
#define NS_NO_VTABLE
#endif

/* starting interface:    nsIPluginDocument */
#define NS_IPLUGINDOCUMENT_IID_STR "e4be1d0a-9f24-4d69-bec5-245726ab85fb"

#define NS_IPLUGINDOCUMENT_IID \
  {0xe4be1d0a, 0x9f24, 0x4d69, \
    { 0xbe, 0xc5, 0x24, 0x57, 0x26, 0xab, 0x85, 0xfb }}

class NS_NO_VTABLE nsIPluginDocument : public nsISupports {
 public: 

  NS_DECLARE_STATIC_IID_ACCESSOR(NS_IPLUGINDOCUMENT_IID)

  /**
  * Sets the stream listener for this plugin document 
  */
  /* void setStreamListener (in nsIStreamListener aStreamListener); */
  NS_IMETHOD SetStreamListener(nsIStreamListener *aStreamListener) = 0;

  /**
  * Causes the plugin to print in full-page mode
  */
  /* void print (); */
  NS_IMETHOD Print(void) = 0;

  /**
   * Check whether the document is planning to handle plug-in instantiation
   * itself.  If not, then the plugin content node should do it.
   */
  /* readonly attribute boolean willHandleInstantiation; */
  NS_IMETHOD GetWillHandleInstantiation(PRBool *aWillHandleInstantiation) = 0;

};

  NS_DEFINE_STATIC_IID_ACCESSOR(nsIPluginDocument, NS_IPLUGINDOCUMENT_IID)

/* Use this macro when declaring classes that implement this interface. */
#define NS_DECL_NSIPLUGINDOCUMENT \
  NS_IMETHOD SetStreamListener(nsIStreamListener *aStreamListener); \
  NS_IMETHOD Print(void); \
  NS_IMETHOD GetWillHandleInstantiation(PRBool *aWillHandleInstantiation); 

/* Use this macro to declare functions that forward the behavior of this interface to another object. */
#define NS_FORWARD_NSIPLUGINDOCUMENT(_to) \
  NS_IMETHOD SetStreamListener(nsIStreamListener *aStreamListener) { return _to SetStreamListener(aStreamListener); } \
  NS_IMETHOD Print(void) { return _to Print(); } \
  NS_IMETHOD GetWillHandleInstantiation(PRBool *aWillHandleInstantiation) { return _to GetWillHandleInstantiation(aWillHandleInstantiation); } 

/* Use this macro to declare functions that forward the behavior of this interface to another object in a safe way. */
#define NS_FORWARD_SAFE_NSIPLUGINDOCUMENT(_to) \
  NS_IMETHOD SetStreamListener(nsIStreamListener *aStreamListener) { return !_to ? NS_ERROR_NULL_POINTER : _to->SetStreamListener(aStreamListener); } \
  NS_IMETHOD Print(void) { return !_to ? NS_ERROR_NULL_POINTER : _to->Print(); } \
  NS_IMETHOD GetWillHandleInstantiation(PRBool *aWillHandleInstantiation) { return !_to ? NS_ERROR_NULL_POINTER : _to->GetWillHandleInstantiation(aWillHandleInstantiation); } 

#if 0
/* Use the code below as a template for the implementation class for this interface. */

/* Header file */
class nsPluginDocument : public nsIPluginDocument
{
public:
  NS_DECL_ISUPPORTS
  NS_DECL_NSIPLUGINDOCUMENT

  nsPluginDocument();

private:
  ~nsPluginDocument();

protected:
  /* additional members */
};

/* Implementation file */
NS_IMPL_ISUPPORTS1(nsPluginDocument, nsIPluginDocument)

nsPluginDocument::nsPluginDocument()
{
  /* member initializers and constructor code */
}

nsPluginDocument::~nsPluginDocument()
{
  /* destructor code */
}

/* void setStreamListener (in nsIStreamListener aStreamListener); */
NS_IMETHODIMP nsPluginDocument::SetStreamListener(nsIStreamListener *aStreamListener)
{
    return NS_ERROR_NOT_IMPLEMENTED;
}

/* void print (); */
NS_IMETHODIMP nsPluginDocument::Print()
{
    return NS_ERROR_NOT_IMPLEMENTED;
}

/* readonly attribute boolean willHandleInstantiation; */
NS_IMETHODIMP nsPluginDocument::GetWillHandleInstantiation(PRBool *aWillHandleInstantiation)
{
    return NS_ERROR_NOT_IMPLEMENTED;
}

/* End of implementation class template. */
#endif


#endif /* __gen_nsIPluginDocument_h__ */
