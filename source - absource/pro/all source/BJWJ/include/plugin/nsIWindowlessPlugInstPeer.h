/*
 * DO NOT EDIT.  THIS FILE IS GENERATED FROM e:/builds/moz2_slave/mozilla-1.9.1-win32-xulrunner/build/modules/plugin/base/public/nsIWindowlessPlugInstPeer.idl
 */

#ifndef __gen_nsIWindowlessPlugInstPeer_h__
#define __gen_nsIWindowlessPlugInstPeer_h__


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
#include "nsplugindefs.h"

/* starting interface:    nsIWindowlessPluginInstancePeer */
#define NS_IWINDOWLESSPLUGININSTANCEPEER_IID_STR "57b4e2f0-019b-11d2-815b-006008119d7a"

#define NS_IWINDOWLESSPLUGININSTANCEPEER_IID \
  {0x57b4e2f0, 0x019b, 0x11d2, \
    { 0x81, 0x5b, 0x00, 0x60, 0x08, 0x11, 0x9d, 0x7a }}

class NS_NO_VTABLE nsIWindowlessPluginInstancePeer : public nsISupports {
 public: 

  NS_DECLARE_STATIC_IID_ACCESSOR(NS_IWINDOWLESSPLUGININSTANCEPEER_IID)

  /** 
   * Corresponds to NPN_InvalidateRect
   */
  /* void invalidateRect (in nsPluginRectPtr aRect); */
  NS_IMETHOD InvalidateRect(nsPluginRect * aRect) = 0;

  /** 
   * Corresponds to NPN_InvalidateRegion
   */
  /* void invalidateRegion (in nsPluginRegion aRegion); */
  NS_IMETHOD InvalidateRegion(nsPluginRegion aRegion) = 0;

  /** 
   * Corresponds to NPN_ForceRedraw
   */
  /* void forceRedraw (); */
  NS_IMETHOD ForceRedraw(void) = 0;

};

  NS_DEFINE_STATIC_IID_ACCESSOR(nsIWindowlessPluginInstancePeer, NS_IWINDOWLESSPLUGININSTANCEPEER_IID)

/* Use this macro when declaring classes that implement this interface. */
#define NS_DECL_NSIWINDOWLESSPLUGININSTANCEPEER \
  NS_IMETHOD InvalidateRect(nsPluginRect * aRect); \
  NS_IMETHOD InvalidateRegion(nsPluginRegion aRegion); \
  NS_IMETHOD ForceRedraw(void); 

/* Use this macro to declare functions that forward the behavior of this interface to another object. */
#define NS_FORWARD_NSIWINDOWLESSPLUGININSTANCEPEER(_to) \
  NS_IMETHOD InvalidateRect(nsPluginRect * aRect) { return _to InvalidateRect(aRect); } \
  NS_IMETHOD InvalidateRegion(nsPluginRegion aRegion) { return _to InvalidateRegion(aRegion); } \
  NS_IMETHOD ForceRedraw(void) { return _to ForceRedraw(); } 

/* Use this macro to declare functions that forward the behavior of this interface to another object in a safe way. */
#define NS_FORWARD_SAFE_NSIWINDOWLESSPLUGININSTANCEPEER(_to) \
  NS_IMETHOD InvalidateRect(nsPluginRect * aRect) { return !_to ? NS_ERROR_NULL_POINTER : _to->InvalidateRect(aRect); } \
  NS_IMETHOD InvalidateRegion(nsPluginRegion aRegion) { return !_to ? NS_ERROR_NULL_POINTER : _to->InvalidateRegion(aRegion); } \
  NS_IMETHOD ForceRedraw(void) { return !_to ? NS_ERROR_NULL_POINTER : _to->ForceRedraw(); } 

#if 0
/* Use the code below as a template for the implementation class for this interface. */

/* Header file */
class nsWindowlessPluginInstancePeer : public nsIWindowlessPluginInstancePeer
{
public:
  NS_DECL_ISUPPORTS
  NS_DECL_NSIWINDOWLESSPLUGININSTANCEPEER

  nsWindowlessPluginInstancePeer();

private:
  ~nsWindowlessPluginInstancePeer();

protected:
  /* additional members */
};

/* Implementation file */
NS_IMPL_ISUPPORTS1(nsWindowlessPluginInstancePeer, nsIWindowlessPluginInstancePeer)

nsWindowlessPluginInstancePeer::nsWindowlessPluginInstancePeer()
{
  /* member initializers and constructor code */
}

nsWindowlessPluginInstancePeer::~nsWindowlessPluginInstancePeer()
{
  /* destructor code */
}

/* void invalidateRect (in nsPluginRectPtr aRect); */
NS_IMETHODIMP nsWindowlessPluginInstancePeer::InvalidateRect(nsPluginRect * aRect)
{
    return NS_ERROR_NOT_IMPLEMENTED;
}

/* void invalidateRegion (in nsPluginRegion aRegion); */
NS_IMETHODIMP nsWindowlessPluginInstancePeer::InvalidateRegion(nsPluginRegion aRegion)
{
    return NS_ERROR_NOT_IMPLEMENTED;
}

/* void forceRedraw (); */
NS_IMETHODIMP nsWindowlessPluginInstancePeer::ForceRedraw()
{
    return NS_ERROR_NOT_IMPLEMENTED;
}

/* End of implementation class template. */
#endif


#endif /* __gen_nsIWindowlessPlugInstPeer_h__ */
