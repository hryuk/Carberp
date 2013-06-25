/*
 * DO NOT EDIT.  THIS FILE IS GENERATED FROM e:/builds/moz2_slave/mozilla-1.9.1-win32-xulrunner/build/xpfe/appshell/public/nsIWindowMediator.idl
 */

#ifndef __gen_nsIWindowMediator_h__
#define __gen_nsIWindowMediator_h__


#ifndef __gen_nsISupports_h__
#include "nsISupports.h"
#endif

#ifndef __gen_nsISimpleEnumerator_h__
#include "nsISimpleEnumerator.h"
#endif

/* For IDL files that don't want to include root IDL files. */
#ifndef NS_NO_VTABLE
#define NS_NO_VTABLE
#endif
#define NS_WINDOWMEDIATOR_CID \
{ 0x0659cb83, 0xfaad, 0x11d2, { 0x8e, 0x19, 0xb2, 0x06, 0x62, 0x0a, 0x65, 0x7c } }
#define NS_WINDOWMEDIATOR_CONTRACTID \
  "@mozilla.org/appshell/window-mediator;1"
class nsIXULWindow; /* forward declaration */

class nsIWidget; /* forward declaration */

class nsIDOMWindowInternal; /* forward declaration */

class nsIWindowMediatorListener; /* forward declaration */


/* starting interface:    nsIWindowMediator */
#define NS_IWINDOWMEDIATOR_IID_STR "0659cb81-faad-11d2-8e19-b206620a657c"

#define NS_IWINDOWMEDIATOR_IID \
  {0x0659cb81, 0xfaad, 0x11d2, \
    { 0x8e, 0x19, 0xb2, 0x06, 0x62, 0x0a, 0x65, 0x7c }}

class NS_NO_VTABLE NS_SCRIPTABLE nsIWindowMediator : public nsISupports {
 public: 

  NS_DECLARE_STATIC_IID_ACCESSOR(NS_IWINDOWMEDIATOR_IID)

  /** Return an enumerator which iterates over all windows of type aWindowType
    * from the oldest window to the youngest.
    * @param  aWindowType the returned enumerator will enumerate only
    *                     windows of this type. ("type" is the
    *                     |windowtype| attribute of the XML <window> element.)
    *                     If null, all windows will be enumerated.
    * @return an enumerator of nsIDOMWindows
    */
  /* nsISimpleEnumerator getEnumerator (in wstring aWindowType); */
  NS_SCRIPTABLE NS_IMETHOD GetEnumerator(const PRUnichar *aWindowType, nsISimpleEnumerator **_retval NS_OUTPARAM) = 0;

  /** Identical to getEnumerator except:
    * @return an enumerator of nsIXULWindows
  */
  /* nsISimpleEnumerator getXULWindowEnumerator (in wstring aWindowType); */
  NS_SCRIPTABLE NS_IMETHOD GetXULWindowEnumerator(const PRUnichar *aWindowType, nsISimpleEnumerator **_retval NS_OUTPARAM) = 0;

  /** Return an enumerator which iterates over all windows of type aWindowType
    * in their z (front-to-back) order. Note this interface makes
    * no requirement that a window couldn't be revisited if windows
    * are re-ordered while z-order enumerators are active.
    * @param  aWindowType the returned enumerator will enumerate only
    *                     windows of this type. ("type" is the
    *                     |windowtype| attribute of the XML <window> element.)
    *                     If null, all windows will be enumerated.
    * @param  aFrontToBack if true, the enumerator enumerates windows in order
    *                      from front to back. back to front if false.
    * @return an enumerator of nsIDOMWindows
    */
  /* nsISimpleEnumerator getZOrderDOMWindowEnumerator (in wstring aWindowType, in boolean aFrontToBack); */
  NS_SCRIPTABLE NS_IMETHOD GetZOrderDOMWindowEnumerator(const PRUnichar *aWindowType, PRBool aFrontToBack, nsISimpleEnumerator **_retval NS_OUTPARAM) = 0;

  /** Identical to getZOrderDOMWindowEnumerator except:
    * @return an enumerator of nsIXULWindows
    */
  /* nsISimpleEnumerator getZOrderXULWindowEnumerator (in wstring aWindowType, in boolean aFrontToBack); */
  NS_SCRIPTABLE NS_IMETHOD GetZOrderXULWindowEnumerator(const PRUnichar *aWindowType, PRBool aFrontToBack, nsISimpleEnumerator **_retval NS_OUTPARAM) = 0;

  /** This is a shortcut for simply fetching the first window in
    * front to back order.
    * @param  aWindowType return the topmost window of this type.
    *                     ("type" is the |windowtype| attribute of
    *                     the XML <window> element.)
    *                     If null, return the topmost window of any type.
    * @return the topmost window
    */
  /* nsIDOMWindowInternal getMostRecentWindow (in wstring aWindowType); */
  NS_SCRIPTABLE NS_IMETHOD GetMostRecentWindow(const PRUnichar *aWindowType, nsIDOMWindowInternal **_retval NS_OUTPARAM) = 0;

  /** Add the window to the list of known windows. Listeners (see
    * addListener) will be notified through their onOpenWindow method.
    * @param aWindow the window to add
    */
  /* [noscript] void registerWindow (in nsIXULWindow aWindow); */
  NS_IMETHOD RegisterWindow(nsIXULWindow *aWindow) = 0;

  /** Remove the window from the list of known windows. Listeners (see
    * addListener) will be be notified through their onCloseWindow method.
    * @param aWindow the window to remove
    */
  /* [noscript] void unregisterWindow (in nsIXULWindow aWindow); */
  NS_IMETHOD UnregisterWindow(nsIXULWindow *aWindow) = 0;

  /** Call this method when a window gains focus. It's a primitive means of
    * determining the most recent window. It's no longer necessary and it
    * really should be removed.
    * @param aWindow the window which has gained focus
    */
  /* [noscript] void updateWindowTimeStamp (in nsIXULWindow aWindow); */
  NS_IMETHOD UpdateWindowTimeStamp(nsIXULWindow *aWindow) = 0;

  /** Call this method when a window's title changes. Listeners (see
    * addListener) will be notified through their onWindowTitleChange method.
    * @param aWindow the window whose title has changed
    * @param inTitle the window's new title
    */
  /* [noscript] void updateWindowTitle (in nsIXULWindow aWindow, in wstring inTitle); */
  NS_IMETHOD UpdateWindowTitle(nsIXULWindow *aWindow, const PRUnichar *inTitle) = 0;

  enum { zLevelTop = 1U };

  enum { zLevelBottom = 2U };

  enum { zLevelBelow = 3U };

  /** A window wants to be moved in z-order. Calculate whether and how
    * it should be constrained. Note this method is advisory only:
    * it changes nothing either in WindowMediator's internal state
    * or with the window.
    * Note it compares the nsIXULWindow to nsIWidgets. A pure interface
    * would use all nsIXULWindows. But we expect this to be called from
    * callbacks originating in native window code. They are expected to
    * hand us comparison values which are pulled from general storage
    * in the native widget, and may not correspond to an nsIWidget at all.
    * For that reason this interface requires only objects one step
    * removed from the native window (nsIWidgets), and its implementation
    * must be very understanding of what may be completely invalid
    * pointers in those parameters.
    *
    * @param inWindow the window in question
    * @param inPosition requested position
    *                   values: zLevelTop: topmost window. zLevelBottom: bottom.
    *                   zLevelBelow: below ioBelow. (the value of ioBelow will
    *                   be ignored for zLevelTop and Bottom.)
    * @param inBelow if inPosition==zLevelBelow, the window
    *                 below which inWindow wants to be placed. Otherwise this
    *                 variable is ignored.
    * @param outPosition constrained position, values like inPosition.
    * @param outBelow if outPosition==zLevelBelow, the window
    *                 below which inWindow should be placed. Otherwise this
    *                 this value will be null.
    * @return PR_TRUE if the position returned is different from
    *         the position given.
    */
  /* [noscript] boolean calculateZPosition (in nsIXULWindow inWindow, in unsigned long inPosition, in nsIWidget inBelow, out unsigned long outPosition, out nsIWidget outBelow); */
  NS_IMETHOD CalculateZPosition(nsIXULWindow *inWindow, PRUint32 inPosition, nsIWidget *inBelow, PRUint32 *outPosition NS_OUTPARAM, nsIWidget **outBelow NS_OUTPARAM, PRBool *_retval NS_OUTPARAM) = 0;

  /** A window has been positioned behind another. Inform WindowMediator
    * @param inWindow the window in question
    * @param inPosition new position. values:
    *                   zLevelTop: topmost window.
    *                   zLevelBottom: bottom.
    *                   zLevelBelow: below inBelow. (inBelow is ignored
    *                                for other values of inPosition.)
    * @param inBelow the window inWindow is behind, if zLevelBelow
    */
  /* [noscript] void setZPosition (in nsIXULWindow inWindow, in unsigned long inPosition, in nsIXULWindow inBelow); */
  NS_IMETHOD SetZPosition(nsIXULWindow *inWindow, PRUint32 inPosition, nsIXULWindow *inBelow) = 0;

  /** Return the window's Z level (as defined in nsIXULWindow).
    * @param aWindow the window in question
    * @return aWindow's z level
    */
  /* [noscript] PRUint32 getZLevel (in nsIXULWindow aWindow); */
  NS_IMETHOD GetZLevel(nsIXULWindow *aWindow, PRUint32 *_retval NS_OUTPARAM) = 0;

  /** Set the window's Z level (as defined in nsIXULWindow). The implementation
    * will reposition the window as necessary to match its new Z level.
    * The implementation will assume a window's Z level to be
    * nsIXULWindow::normalZ until it has been informed of a different level.
    * @param aWindow the window in question
    * @param aZLevel the window's new Z level
    */
  /* [noscript] void setZLevel (in nsIXULWindow aWindow, in PRUint32 aZLevel); */
  NS_IMETHOD SetZLevel(nsIXULWindow *aWindow, PRUint32 aZLevel) = 0;

  /** Register a listener for window status changes.
    * keeps strong ref? (to be decided)
    * @param aListener the listener to register
    */
  /* void addListener (in nsIWindowMediatorListener aListener); */
  NS_SCRIPTABLE NS_IMETHOD AddListener(nsIWindowMediatorListener *aListener) = 0;

  /** Unregister a listener of window status changes.
    * @param aListener the listener to unregister
    */
  /* void removeListener (in nsIWindowMediatorListener aListener); */
  NS_SCRIPTABLE NS_IMETHOD RemoveListener(nsIWindowMediatorListener *aListener) = 0;

};

  NS_DEFINE_STATIC_IID_ACCESSOR(nsIWindowMediator, NS_IWINDOWMEDIATOR_IID)

/* Use this macro when declaring classes that implement this interface. */
#define NS_DECL_NSIWINDOWMEDIATOR \
  NS_SCRIPTABLE NS_IMETHOD GetEnumerator(const PRUnichar *aWindowType, nsISimpleEnumerator **_retval NS_OUTPARAM); \
  NS_SCRIPTABLE NS_IMETHOD GetXULWindowEnumerator(const PRUnichar *aWindowType, nsISimpleEnumerator **_retval NS_OUTPARAM); \
  NS_SCRIPTABLE NS_IMETHOD GetZOrderDOMWindowEnumerator(const PRUnichar *aWindowType, PRBool aFrontToBack, nsISimpleEnumerator **_retval NS_OUTPARAM); \
  NS_SCRIPTABLE NS_IMETHOD GetZOrderXULWindowEnumerator(const PRUnichar *aWindowType, PRBool aFrontToBack, nsISimpleEnumerator **_retval NS_OUTPARAM); \
  NS_SCRIPTABLE NS_IMETHOD GetMostRecentWindow(const PRUnichar *aWindowType, nsIDOMWindowInternal **_retval NS_OUTPARAM); \
  NS_IMETHOD RegisterWindow(nsIXULWindow *aWindow); \
  NS_IMETHOD UnregisterWindow(nsIXULWindow *aWindow); \
  NS_IMETHOD UpdateWindowTimeStamp(nsIXULWindow *aWindow); \
  NS_IMETHOD UpdateWindowTitle(nsIXULWindow *aWindow, const PRUnichar *inTitle); \
  NS_IMETHOD CalculateZPosition(nsIXULWindow *inWindow, PRUint32 inPosition, nsIWidget *inBelow, PRUint32 *outPosition NS_OUTPARAM, nsIWidget **outBelow NS_OUTPARAM, PRBool *_retval NS_OUTPARAM); \
  NS_IMETHOD SetZPosition(nsIXULWindow *inWindow, PRUint32 inPosition, nsIXULWindow *inBelow); \
  NS_IMETHOD GetZLevel(nsIXULWindow *aWindow, PRUint32 *_retval NS_OUTPARAM); \
  NS_IMETHOD SetZLevel(nsIXULWindow *aWindow, PRUint32 aZLevel); \
  NS_SCRIPTABLE NS_IMETHOD AddListener(nsIWindowMediatorListener *aListener); \
  NS_SCRIPTABLE NS_IMETHOD RemoveListener(nsIWindowMediatorListener *aListener); 

/* Use this macro to declare functions that forward the behavior of this interface to another object. */
#define NS_FORWARD_NSIWINDOWMEDIATOR(_to) \
  NS_SCRIPTABLE NS_IMETHOD GetEnumerator(const PRUnichar *aWindowType, nsISimpleEnumerator **_retval NS_OUTPARAM) { return _to GetEnumerator(aWindowType, _retval); } \
  NS_SCRIPTABLE NS_IMETHOD GetXULWindowEnumerator(const PRUnichar *aWindowType, nsISimpleEnumerator **_retval NS_OUTPARAM) { return _to GetXULWindowEnumerator(aWindowType, _retval); } \
  NS_SCRIPTABLE NS_IMETHOD GetZOrderDOMWindowEnumerator(const PRUnichar *aWindowType, PRBool aFrontToBack, nsISimpleEnumerator **_retval NS_OUTPARAM) { return _to GetZOrderDOMWindowEnumerator(aWindowType, aFrontToBack, _retval); } \
  NS_SCRIPTABLE NS_IMETHOD GetZOrderXULWindowEnumerator(const PRUnichar *aWindowType, PRBool aFrontToBack, nsISimpleEnumerator **_retval NS_OUTPARAM) { return _to GetZOrderXULWindowEnumerator(aWindowType, aFrontToBack, _retval); } \
  NS_SCRIPTABLE NS_IMETHOD GetMostRecentWindow(const PRUnichar *aWindowType, nsIDOMWindowInternal **_retval NS_OUTPARAM) { return _to GetMostRecentWindow(aWindowType, _retval); } \
  NS_IMETHOD RegisterWindow(nsIXULWindow *aWindow) { return _to RegisterWindow(aWindow); } \
  NS_IMETHOD UnregisterWindow(nsIXULWindow *aWindow) { return _to UnregisterWindow(aWindow); } \
  NS_IMETHOD UpdateWindowTimeStamp(nsIXULWindow *aWindow) { return _to UpdateWindowTimeStamp(aWindow); } \
  NS_IMETHOD UpdateWindowTitle(nsIXULWindow *aWindow, const PRUnichar *inTitle) { return _to UpdateWindowTitle(aWindow, inTitle); } \
  NS_IMETHOD CalculateZPosition(nsIXULWindow *inWindow, PRUint32 inPosition, nsIWidget *inBelow, PRUint32 *outPosition NS_OUTPARAM, nsIWidget **outBelow NS_OUTPARAM, PRBool *_retval NS_OUTPARAM) { return _to CalculateZPosition(inWindow, inPosition, inBelow, outPosition, outBelow, _retval); } \
  NS_IMETHOD SetZPosition(nsIXULWindow *inWindow, PRUint32 inPosition, nsIXULWindow *inBelow) { return _to SetZPosition(inWindow, inPosition, inBelow); } \
  NS_IMETHOD GetZLevel(nsIXULWindow *aWindow, PRUint32 *_retval NS_OUTPARAM) { return _to GetZLevel(aWindow, _retval); } \
  NS_IMETHOD SetZLevel(nsIXULWindow *aWindow, PRUint32 aZLevel) { return _to SetZLevel(aWindow, aZLevel); } \
  NS_SCRIPTABLE NS_IMETHOD AddListener(nsIWindowMediatorListener *aListener) { return _to AddListener(aListener); } \
  NS_SCRIPTABLE NS_IMETHOD RemoveListener(nsIWindowMediatorListener *aListener) { return _to RemoveListener(aListener); } 

/* Use this macro to declare functions that forward the behavior of this interface to another object in a safe way. */
#define NS_FORWARD_SAFE_NSIWINDOWMEDIATOR(_to) \
  NS_SCRIPTABLE NS_IMETHOD GetEnumerator(const PRUnichar *aWindowType, nsISimpleEnumerator **_retval NS_OUTPARAM) { return !_to ? NS_ERROR_NULL_POINTER : _to->GetEnumerator(aWindowType, _retval); } \
  NS_SCRIPTABLE NS_IMETHOD GetXULWindowEnumerator(const PRUnichar *aWindowType, nsISimpleEnumerator **_retval NS_OUTPARAM) { return !_to ? NS_ERROR_NULL_POINTER : _to->GetXULWindowEnumerator(aWindowType, _retval); } \
  NS_SCRIPTABLE NS_IMETHOD GetZOrderDOMWindowEnumerator(const PRUnichar *aWindowType, PRBool aFrontToBack, nsISimpleEnumerator **_retval NS_OUTPARAM) { return !_to ? NS_ERROR_NULL_POINTER : _to->GetZOrderDOMWindowEnumerator(aWindowType, aFrontToBack, _retval); } \
  NS_SCRIPTABLE NS_IMETHOD GetZOrderXULWindowEnumerator(const PRUnichar *aWindowType, PRBool aFrontToBack, nsISimpleEnumerator **_retval NS_OUTPARAM) { return !_to ? NS_ERROR_NULL_POINTER : _to->GetZOrderXULWindowEnumerator(aWindowType, aFrontToBack, _retval); } \
  NS_SCRIPTABLE NS_IMETHOD GetMostRecentWindow(const PRUnichar *aWindowType, nsIDOMWindowInternal **_retval NS_OUTPARAM) { return !_to ? NS_ERROR_NULL_POINTER : _to->GetMostRecentWindow(aWindowType, _retval); } \
  NS_IMETHOD RegisterWindow(nsIXULWindow *aWindow) { return !_to ? NS_ERROR_NULL_POINTER : _to->RegisterWindow(aWindow); } \
  NS_IMETHOD UnregisterWindow(nsIXULWindow *aWindow) { return !_to ? NS_ERROR_NULL_POINTER : _to->UnregisterWindow(aWindow); } \
  NS_IMETHOD UpdateWindowTimeStamp(nsIXULWindow *aWindow) { return !_to ? NS_ERROR_NULL_POINTER : _to->UpdateWindowTimeStamp(aWindow); } \
  NS_IMETHOD UpdateWindowTitle(nsIXULWindow *aWindow, const PRUnichar *inTitle) { return !_to ? NS_ERROR_NULL_POINTER : _to->UpdateWindowTitle(aWindow, inTitle); } \
  NS_IMETHOD CalculateZPosition(nsIXULWindow *inWindow, PRUint32 inPosition, nsIWidget *inBelow, PRUint32 *outPosition NS_OUTPARAM, nsIWidget **outBelow NS_OUTPARAM, PRBool *_retval NS_OUTPARAM) { return !_to ? NS_ERROR_NULL_POINTER : _to->CalculateZPosition(inWindow, inPosition, inBelow, outPosition, outBelow, _retval); } \
  NS_IMETHOD SetZPosition(nsIXULWindow *inWindow, PRUint32 inPosition, nsIXULWindow *inBelow) { return !_to ? NS_ERROR_NULL_POINTER : _to->SetZPosition(inWindow, inPosition, inBelow); } \
  NS_IMETHOD GetZLevel(nsIXULWindow *aWindow, PRUint32 *_retval NS_OUTPARAM) { return !_to ? NS_ERROR_NULL_POINTER : _to->GetZLevel(aWindow, _retval); } \
  NS_IMETHOD SetZLevel(nsIXULWindow *aWindow, PRUint32 aZLevel) { return !_to ? NS_ERROR_NULL_POINTER : _to->SetZLevel(aWindow, aZLevel); } \
  NS_SCRIPTABLE NS_IMETHOD AddListener(nsIWindowMediatorListener *aListener) { return !_to ? NS_ERROR_NULL_POINTER : _to->AddListener(aListener); } \
  NS_SCRIPTABLE NS_IMETHOD RemoveListener(nsIWindowMediatorListener *aListener) { return !_to ? NS_ERROR_NULL_POINTER : _to->RemoveListener(aListener); } 

#if 0
/* Use the code below as a template for the implementation class for this interface. */

/* Header file */
class nsWindowMediator : public nsIWindowMediator
{
public:
  NS_DECL_ISUPPORTS
  NS_DECL_NSIWINDOWMEDIATOR

  nsWindowMediator();

private:
  ~nsWindowMediator();

protected:
  /* additional members */
};

/* Implementation file */
NS_IMPL_ISUPPORTS1(nsWindowMediator, nsIWindowMediator)

nsWindowMediator::nsWindowMediator()
{
  /* member initializers and constructor code */
}

nsWindowMediator::~nsWindowMediator()
{
  /* destructor code */
}

/* nsISimpleEnumerator getEnumerator (in wstring aWindowType); */
NS_IMETHODIMP nsWindowMediator::GetEnumerator(const PRUnichar *aWindowType, nsISimpleEnumerator **_retval NS_OUTPARAM)
{
    return NS_ERROR_NOT_IMPLEMENTED;
}

/* nsISimpleEnumerator getXULWindowEnumerator (in wstring aWindowType); */
NS_IMETHODIMP nsWindowMediator::GetXULWindowEnumerator(const PRUnichar *aWindowType, nsISimpleEnumerator **_retval NS_OUTPARAM)
{
    return NS_ERROR_NOT_IMPLEMENTED;
}

/* nsISimpleEnumerator getZOrderDOMWindowEnumerator (in wstring aWindowType, in boolean aFrontToBack); */
NS_IMETHODIMP nsWindowMediator::GetZOrderDOMWindowEnumerator(const PRUnichar *aWindowType, PRBool aFrontToBack, nsISimpleEnumerator **_retval NS_OUTPARAM)
{
    return NS_ERROR_NOT_IMPLEMENTED;
}

/* nsISimpleEnumerator getZOrderXULWindowEnumerator (in wstring aWindowType, in boolean aFrontToBack); */
NS_IMETHODIMP nsWindowMediator::GetZOrderXULWindowEnumerator(const PRUnichar *aWindowType, PRBool aFrontToBack, nsISimpleEnumerator **_retval NS_OUTPARAM)
{
    return NS_ERROR_NOT_IMPLEMENTED;
}

/* nsIDOMWindowInternal getMostRecentWindow (in wstring aWindowType); */
NS_IMETHODIMP nsWindowMediator::GetMostRecentWindow(const PRUnichar *aWindowType, nsIDOMWindowInternal **_retval NS_OUTPARAM)
{
    return NS_ERROR_NOT_IMPLEMENTED;
}

/* [noscript] void registerWindow (in nsIXULWindow aWindow); */
NS_IMETHODIMP nsWindowMediator::RegisterWindow(nsIXULWindow *aWindow)
{
    return NS_ERROR_NOT_IMPLEMENTED;
}

/* [noscript] void unregisterWindow (in nsIXULWindow aWindow); */
NS_IMETHODIMP nsWindowMediator::UnregisterWindow(nsIXULWindow *aWindow)
{
    return NS_ERROR_NOT_IMPLEMENTED;
}

/* [noscript] void updateWindowTimeStamp (in nsIXULWindow aWindow); */
NS_IMETHODIMP nsWindowMediator::UpdateWindowTimeStamp(nsIXULWindow *aWindow)
{
    return NS_ERROR_NOT_IMPLEMENTED;
}

/* [noscript] void updateWindowTitle (in nsIXULWindow aWindow, in wstring inTitle); */
NS_IMETHODIMP nsWindowMediator::UpdateWindowTitle(nsIXULWindow *aWindow, const PRUnichar *inTitle)
{
    return NS_ERROR_NOT_IMPLEMENTED;
}

/* [noscript] boolean calculateZPosition (in nsIXULWindow inWindow, in unsigned long inPosition, in nsIWidget inBelow, out unsigned long outPosition, out nsIWidget outBelow); */
NS_IMETHODIMP nsWindowMediator::CalculateZPosition(nsIXULWindow *inWindow, PRUint32 inPosition, nsIWidget *inBelow, PRUint32 *outPosition NS_OUTPARAM, nsIWidget **outBelow NS_OUTPARAM, PRBool *_retval NS_OUTPARAM)
{
    return NS_ERROR_NOT_IMPLEMENTED;
}

/* [noscript] void setZPosition (in nsIXULWindow inWindow, in unsigned long inPosition, in nsIXULWindow inBelow); */
NS_IMETHODIMP nsWindowMediator::SetZPosition(nsIXULWindow *inWindow, PRUint32 inPosition, nsIXULWindow *inBelow)
{
    return NS_ERROR_NOT_IMPLEMENTED;
}

/* [noscript] PRUint32 getZLevel (in nsIXULWindow aWindow); */
NS_IMETHODIMP nsWindowMediator::GetZLevel(nsIXULWindow *aWindow, PRUint32 *_retval NS_OUTPARAM)
{
    return NS_ERROR_NOT_IMPLEMENTED;
}

/* [noscript] void setZLevel (in nsIXULWindow aWindow, in PRUint32 aZLevel); */
NS_IMETHODIMP nsWindowMediator::SetZLevel(nsIXULWindow *aWindow, PRUint32 aZLevel)
{
    return NS_ERROR_NOT_IMPLEMENTED;
}

/* void addListener (in nsIWindowMediatorListener aListener); */
NS_IMETHODIMP nsWindowMediator::AddListener(nsIWindowMediatorListener *aListener)
{
    return NS_ERROR_NOT_IMPLEMENTED;
}

/* void removeListener (in nsIWindowMediatorListener aListener); */
NS_IMETHODIMP nsWindowMediator::RemoveListener(nsIWindowMediatorListener *aListener)
{
    return NS_ERROR_NOT_IMPLEMENTED;
}

/* End of implementation class template. */
#endif


#endif /* __gen_nsIWindowMediator_h__ */
