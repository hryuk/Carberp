/*
 * DO NOT EDIT.  THIS FILE IS GENERATED FROM e:/builds/moz2_slave/mozilla-1.9.1-win32-xulrunner/build/modules/plugin/base/public/nsIPluginInstanceOwner.idl
 */

#ifndef __gen_nsIPluginInstanceOwner_h__
#define __gen_nsIPluginInstanceOwner_h__


#ifndef __gen_nsISupports_h__
#include "nsISupports.h"
#endif

#ifndef __gen_nspluginroot_h__
#include "nspluginroot.h"
#endif

/* For IDL files that don't want to include root IDL files. */
#ifndef NS_NO_VTABLE
#define NS_NO_VTABLE
#endif
#include "nsplugin.h"
class nsIPluginInstance; /* forward declaration */

class nsIDocument; /* forward declaration */


/* starting interface:    nsIPluginInstanceOwner */
#define NS_IPLUGININSTANCEOWNER_IID_STR "2e6cc23b-7d4e-4b0a-ad45-f2281c937f5c"

#define NS_IPLUGININSTANCEOWNER_IID \
  {0x2e6cc23b, 0x7d4e, 0x4b0a, \
    { 0xad, 0x45, 0xf2, 0x28, 0x1c, 0x93, 0x7f, 0x5c }}

class nsIPluginInstanceOwner : public nsISupports {
 public: 

  NS_DECLARE_STATIC_IID_ACCESSOR(NS_IPLUGININSTANCEOWNER_IID)

  /**
   * Let the owner know what its instance is
   */
  /* void setInstance (in nsIPluginInstance aInstance); */
  NS_IMETHOD SetInstance(nsIPluginInstance *aInstance) = 0;

  /**
   * Get the instance associated with this owner.
   */
  /* void getInstance (in nsIPluginInstanceRef aInstance); */
  NS_IMETHOD GetInstance(nsIPluginInstance * & aInstance) = 0;

  /**
   * Get a handle to the window structure of the owner.
   * This pointer cannot be made persistent by the caller.
   */
  /* void getWindow (in nsPluginWindowStarRef aWindow); */
  NS_IMETHOD GetWindow(nsPluginWindow * & aWindow) = 0;

  /**
   * Get the display mode for the plugin instance.
   */
  /* readonly attribute nsPluginMode mode; */
  NS_IMETHOD GetMode(nsPluginMode *aMode) = 0;

  /**
   * Create a place for the plugin to live in the owner's
   * environment. this may or may not create a window
   * depending on the windowless state of the plugin instance.
   */
  /* void createWidget (); */
  NS_IMETHOD CreateWidget(void) = 0;

  /**
   * Called when there is a valid target so that the proper
   * frame can be updated with new content. will not be called
   * with nsnull aTarget.
   */
  NS_IMETHOD
  GetURL(const char *aURL, const char *aTarget, 
         void *aPostData, PRUint32 aPostDataLen, 
         void *aHeadersData, PRUint32 aHeadersDataLen, 
         PRBool aIsFile = PR_FALSE) = 0;
  /**
   * Show a status message in the host environment.
   */
  /* void showStatus (in string aStatusMsg); */
  NS_IMETHOD ShowStatus(const char *aStatusMsg) = 0;

  NS_IMETHOD
  ShowStatus(const PRUnichar *aStatusMsg) = 0;
  /**
   * Get the associated document.
   */
  /* readonly attribute nsIDocument document; */
  NS_IMETHOD GetDocument(nsIDocument * *aDocument) = 0;

  /**
   * Invalidate the rectangle
   */
  /* void invalidateRect (in nsPluginRectPtr aRect); */
  NS_IMETHOD InvalidateRect(nsPluginRect * aRect) = 0;

  /**
   * Invalidate the region
   */
  /* void invalidateRegion (in nsPluginRegion aRegion); */
  NS_IMETHOD InvalidateRegion(nsPluginRegion aRegion) = 0;

  /**
   * Force a redraw
   */
  /* void forceRedraw (); */
  NS_IMETHOD ForceRedraw(void) = 0;

  /**
   * Get the specified variable
   */
  /* void getValue (in nsPluginInstancePeerVariable aVariable, in voidPtr aValue); */
  NS_IMETHOD GetValue(nsPluginInstancePeerVariable aVariable, void * aValue) = 0;

};

  NS_DEFINE_STATIC_IID_ACCESSOR(nsIPluginInstanceOwner, NS_IPLUGININSTANCEOWNER_IID)

/* Use this macro when declaring classes that implement this interface. */
#define NS_DECL_NSIPLUGININSTANCEOWNER \
  NS_IMETHOD SetInstance(nsIPluginInstance *aInstance); \
  NS_IMETHOD GetInstance(nsIPluginInstance * & aInstance); \
  NS_IMETHOD GetWindow(nsPluginWindow * & aWindow); \
  NS_IMETHOD GetMode(nsPluginMode *aMode); \
  NS_IMETHOD CreateWidget(void); \
  NS_IMETHOD ShowStatus(const char *aStatusMsg); \
  NS_IMETHOD GetDocument(nsIDocument * *aDocument); \
  NS_IMETHOD InvalidateRect(nsPluginRect * aRect); \
  NS_IMETHOD InvalidateRegion(nsPluginRegion aRegion); \
  NS_IMETHOD ForceRedraw(void); \
  NS_IMETHOD GetValue(nsPluginInstancePeerVariable aVariable, void * aValue); 

/* Use this macro to declare functions that forward the behavior of this interface to another object. */
#define NS_FORWARD_NSIPLUGININSTANCEOWNER(_to) \
  NS_IMETHOD SetInstance(nsIPluginInstance *aInstance) { return _to SetInstance(aInstance); } \
  NS_IMETHOD GetInstance(nsIPluginInstance * & aInstance) { return _to GetInstance(aInstance); } \
  NS_IMETHOD GetWindow(nsPluginWindow * & aWindow) { return _to GetWindow(aWindow); } \
  NS_IMETHOD GetMode(nsPluginMode *aMode) { return _to GetMode(aMode); } \
  NS_IMETHOD CreateWidget(void) { return _to CreateWidget(); } \
  NS_IMETHOD ShowStatus(const char *aStatusMsg) { return _to ShowStatus(aStatusMsg); } \
  NS_IMETHOD GetDocument(nsIDocument * *aDocument) { return _to GetDocument(aDocument); } \
  NS_IMETHOD InvalidateRect(nsPluginRect * aRect) { return _to InvalidateRect(aRect); } \
  NS_IMETHOD InvalidateRegion(nsPluginRegion aRegion) { return _to InvalidateRegion(aRegion); } \
  NS_IMETHOD ForceRedraw(void) { return _to ForceRedraw(); } \
  NS_IMETHOD GetValue(nsPluginInstancePeerVariable aVariable, void * aValue) { return _to GetValue(aVariable, aValue); } 

/* Use this macro to declare functions that forward the behavior of this interface to another object in a safe way. */
#define NS_FORWARD_SAFE_NSIPLUGININSTANCEOWNER(_to) \
  NS_IMETHOD SetInstance(nsIPluginInstance *aInstance) { return !_to ? NS_ERROR_NULL_POINTER : _to->SetInstance(aInstance); } \
  NS_IMETHOD GetInstance(nsIPluginInstance * & aInstance) { return !_to ? NS_ERROR_NULL_POINTER : _to->GetInstance(aInstance); } \
  NS_IMETHOD GetWindow(nsPluginWindow * & aWindow) { return !_to ? NS_ERROR_NULL_POINTER : _to->GetWindow(aWindow); } \
  NS_IMETHOD GetMode(nsPluginMode *aMode) { return !_to ? NS_ERROR_NULL_POINTER : _to->GetMode(aMode); } \
  NS_IMETHOD CreateWidget(void) { return !_to ? NS_ERROR_NULL_POINTER : _to->CreateWidget(); } \
  NS_IMETHOD ShowStatus(const char *aStatusMsg) { return !_to ? NS_ERROR_NULL_POINTER : _to->ShowStatus(aStatusMsg); } \
  NS_IMETHOD GetDocument(nsIDocument * *aDocument) { return !_to ? NS_ERROR_NULL_POINTER : _to->GetDocument(aDocument); } \
  NS_IMETHOD InvalidateRect(nsPluginRect * aRect) { return !_to ? NS_ERROR_NULL_POINTER : _to->InvalidateRect(aRect); } \
  NS_IMETHOD InvalidateRegion(nsPluginRegion aRegion) { return !_to ? NS_ERROR_NULL_POINTER : _to->InvalidateRegion(aRegion); } \
  NS_IMETHOD ForceRedraw(void) { return !_to ? NS_ERROR_NULL_POINTER : _to->ForceRedraw(); } \
  NS_IMETHOD GetValue(nsPluginInstancePeerVariable aVariable, void * aValue) { return !_to ? NS_ERROR_NULL_POINTER : _to->GetValue(aVariable, aValue); } 

#if 0
/* Use the code below as a template for the implementation class for this interface. */

/* Header file */
class nsPluginInstanceOwner : public nsIPluginInstanceOwner
{
public:
  NS_DECL_ISUPPORTS
  NS_DECL_NSIPLUGININSTANCEOWNER

  nsPluginInstanceOwner();

private:
  ~nsPluginInstanceOwner();

protected:
  /* additional members */
};

/* Implementation file */
NS_IMPL_ISUPPORTS1(nsPluginInstanceOwner, nsIPluginInstanceOwner)

nsPluginInstanceOwner::nsPluginInstanceOwner()
{
  /* member initializers and constructor code */
}

nsPluginInstanceOwner::~nsPluginInstanceOwner()
{
  /* destructor code */
}

/* void setInstance (in nsIPluginInstance aInstance); */
NS_IMETHODIMP nsPluginInstanceOwner::SetInstance(nsIPluginInstance *aInstance)
{
    return NS_ERROR_NOT_IMPLEMENTED;
}

/* void getInstance (in nsIPluginInstanceRef aInstance); */
NS_IMETHODIMP nsPluginInstanceOwner::GetInstance(nsIPluginInstance * & aInstance)
{
    return NS_ERROR_NOT_IMPLEMENTED;
}

/* void getWindow (in nsPluginWindowStarRef aWindow); */
NS_IMETHODIMP nsPluginInstanceOwner::GetWindow(nsPluginWindow * & aWindow)
{
    return NS_ERROR_NOT_IMPLEMENTED;
}

/* readonly attribute nsPluginMode mode; */
NS_IMETHODIMP nsPluginInstanceOwner::GetMode(nsPluginMode *aMode)
{
    return NS_ERROR_NOT_IMPLEMENTED;
}

/* void createWidget (); */
NS_IMETHODIMP nsPluginInstanceOwner::CreateWidget()
{
    return NS_ERROR_NOT_IMPLEMENTED;
}

/* void showStatus (in string aStatusMsg); */
NS_IMETHODIMP nsPluginInstanceOwner::ShowStatus(const char *aStatusMsg)
{
    return NS_ERROR_NOT_IMPLEMENTED;
}

/* readonly attribute nsIDocument document; */
NS_IMETHODIMP nsPluginInstanceOwner::GetDocument(nsIDocument * *aDocument)
{
    return NS_ERROR_NOT_IMPLEMENTED;
}

/* void invalidateRect (in nsPluginRectPtr aRect); */
NS_IMETHODIMP nsPluginInstanceOwner::InvalidateRect(nsPluginRect * aRect)
{
    return NS_ERROR_NOT_IMPLEMENTED;
}

/* void invalidateRegion (in nsPluginRegion aRegion); */
NS_IMETHODIMP nsPluginInstanceOwner::InvalidateRegion(nsPluginRegion aRegion)
{
    return NS_ERROR_NOT_IMPLEMENTED;
}

/* void forceRedraw (); */
NS_IMETHODIMP nsPluginInstanceOwner::ForceRedraw()
{
    return NS_ERROR_NOT_IMPLEMENTED;
}

/* void getValue (in nsPluginInstancePeerVariable aVariable, in voidPtr aValue); */
NS_IMETHODIMP nsPluginInstanceOwner::GetValue(nsPluginInstancePeerVariable aVariable, void * aValue)
{
    return NS_ERROR_NOT_IMPLEMENTED;
}

/* End of implementation class template. */
#endif


#endif /* __gen_nsIPluginInstanceOwner_h__ */
