/*
 * DO NOT EDIT.  THIS FILE IS GENERATED FROM e:/builds/moz2_slave/mozilla-1.9.1-win32-xulrunner/build/widget/public/nsIFullScreen.idl
 */

#ifndef __gen_nsIFullScreen_h__
#define __gen_nsIFullScreen_h__


#ifndef __gen_nsISupports_h__
#include "nsISupports.h"
#endif

/* For IDL files that don't want to include root IDL files. */
#ifndef NS_NO_VTABLE
#define NS_NO_VTABLE
#endif
class nsISimpleEnumerator; /* forward declaration */


/* starting interface:    nsIFullScreen */
#define NS_IFULLSCREEN_IID_STR "9854976e-1dd1-11b2-8350-e6d35099fbce"

#define NS_IFULLSCREEN_IID \
  {0x9854976e, 0x1dd1, 0x11b2, \
    { 0x83, 0x50, 0xe6, 0xd3, 0x50, 0x99, 0xfb, 0xce }}

class NS_NO_VTABLE NS_SCRIPTABLE nsIFullScreen : public nsISupports {
 public: 

  NS_DECLARE_STATIC_IID_ACCESSOR(NS_IFULLSCREEN_IID)

  /**
   * Hide all registered OS chrome components
   */
  /* void hideAllOSChrome (); */
  NS_SCRIPTABLE NS_IMETHOD HideAllOSChrome(void) = 0;

  /**
   * Show all registered OS chrome components
   */
  /* void showAllOSChrome (); */
  NS_SCRIPTABLE NS_IMETHOD ShowAllOSChrome(void) = 0;

  /**
   * Return an enumerator of all registered OS chrome components
   */
  /* nsISimpleEnumerator getChromeItems (); */
  NS_SCRIPTABLE NS_IMETHOD GetChromeItems(nsISimpleEnumerator **_retval NS_OUTPARAM) = 0;

};

  NS_DEFINE_STATIC_IID_ACCESSOR(nsIFullScreen, NS_IFULLSCREEN_IID)

/* Use this macro when declaring classes that implement this interface. */
#define NS_DECL_NSIFULLSCREEN \
  NS_SCRIPTABLE NS_IMETHOD HideAllOSChrome(void); \
  NS_SCRIPTABLE NS_IMETHOD ShowAllOSChrome(void); \
  NS_SCRIPTABLE NS_IMETHOD GetChromeItems(nsISimpleEnumerator **_retval NS_OUTPARAM); 

/* Use this macro to declare functions that forward the behavior of this interface to another object. */
#define NS_FORWARD_NSIFULLSCREEN(_to) \
  NS_SCRIPTABLE NS_IMETHOD HideAllOSChrome(void) { return _to HideAllOSChrome(); } \
  NS_SCRIPTABLE NS_IMETHOD ShowAllOSChrome(void) { return _to ShowAllOSChrome(); } \
  NS_SCRIPTABLE NS_IMETHOD GetChromeItems(nsISimpleEnumerator **_retval NS_OUTPARAM) { return _to GetChromeItems(_retval); } 

/* Use this macro to declare functions that forward the behavior of this interface to another object in a safe way. */
#define NS_FORWARD_SAFE_NSIFULLSCREEN(_to) \
  NS_SCRIPTABLE NS_IMETHOD HideAllOSChrome(void) { return !_to ? NS_ERROR_NULL_POINTER : _to->HideAllOSChrome(); } \
  NS_SCRIPTABLE NS_IMETHOD ShowAllOSChrome(void) { return !_to ? NS_ERROR_NULL_POINTER : _to->ShowAllOSChrome(); } \
  NS_SCRIPTABLE NS_IMETHOD GetChromeItems(nsISimpleEnumerator **_retval NS_OUTPARAM) { return !_to ? NS_ERROR_NULL_POINTER : _to->GetChromeItems(_retval); } 

#if 0
/* Use the code below as a template for the implementation class for this interface. */

/* Header file */
class nsFullScreen : public nsIFullScreen
{
public:
  NS_DECL_ISUPPORTS
  NS_DECL_NSIFULLSCREEN

  nsFullScreen();

private:
  ~nsFullScreen();

protected:
  /* additional members */
};

/* Implementation file */
NS_IMPL_ISUPPORTS1(nsFullScreen, nsIFullScreen)

nsFullScreen::nsFullScreen()
{
  /* member initializers and constructor code */
}

nsFullScreen::~nsFullScreen()
{
  /* destructor code */
}

/* void hideAllOSChrome (); */
NS_IMETHODIMP nsFullScreen::HideAllOSChrome()
{
    return NS_ERROR_NOT_IMPLEMENTED;
}

/* void showAllOSChrome (); */
NS_IMETHODIMP nsFullScreen::ShowAllOSChrome()
{
    return NS_ERROR_NOT_IMPLEMENTED;
}

/* nsISimpleEnumerator getChromeItems (); */
NS_IMETHODIMP nsFullScreen::GetChromeItems(nsISimpleEnumerator **_retval NS_OUTPARAM)
{
    return NS_ERROR_NOT_IMPLEMENTED;
}

/* End of implementation class template. */
#endif


/* starting interface:    nsIOSChromeItem */
#define NS_IOSCHROMEITEM_IID_STR "ddd6790a-1dd1-11b2-a804-b522643903b9"

#define NS_IOSCHROMEITEM_IID \
  {0xddd6790a, 0x1dd1, 0x11b2, \
    { 0xa8, 0x04, 0xb5, 0x22, 0x64, 0x39, 0x03, 0xb9 }}

class NS_NO_VTABLE NS_SCRIPTABLE nsIOSChromeItem : public nsISupports {
 public: 

  NS_DECLARE_STATIC_IID_ACCESSOR(NS_IOSCHROMEITEM_IID)

  /* readonly attribute string name; */
  NS_SCRIPTABLE NS_IMETHOD GetName(char * *aName) = 0;

  /* attribute boolean hidden; */
  NS_SCRIPTABLE NS_IMETHOD GetHidden(PRBool *aHidden) = 0;
  NS_SCRIPTABLE NS_IMETHOD SetHidden(PRBool aHidden) = 0;

  /* readonly attribute long x; */
  NS_SCRIPTABLE NS_IMETHOD GetX(PRInt32 *aX) = 0;

  /* readonly attribute long y; */
  NS_SCRIPTABLE NS_IMETHOD GetY(PRInt32 *aY) = 0;

  /* readonly attribute long width; */
  NS_SCRIPTABLE NS_IMETHOD GetWidth(PRInt32 *aWidth) = 0;

  /* readonly attribute long height; */
  NS_SCRIPTABLE NS_IMETHOD GetHeight(PRInt32 *aHeight) = 0;

};

  NS_DEFINE_STATIC_IID_ACCESSOR(nsIOSChromeItem, NS_IOSCHROMEITEM_IID)

/* Use this macro when declaring classes that implement this interface. */
#define NS_DECL_NSIOSCHROMEITEM \
  NS_SCRIPTABLE NS_IMETHOD GetName(char * *aName); \
  NS_SCRIPTABLE NS_IMETHOD GetHidden(PRBool *aHidden); \
  NS_SCRIPTABLE NS_IMETHOD SetHidden(PRBool aHidden); \
  NS_SCRIPTABLE NS_IMETHOD GetX(PRInt32 *aX); \
  NS_SCRIPTABLE NS_IMETHOD GetY(PRInt32 *aY); \
  NS_SCRIPTABLE NS_IMETHOD GetWidth(PRInt32 *aWidth); \
  NS_SCRIPTABLE NS_IMETHOD GetHeight(PRInt32 *aHeight); 

/* Use this macro to declare functions that forward the behavior of this interface to another object. */
#define NS_FORWARD_NSIOSCHROMEITEM(_to) \
  NS_SCRIPTABLE NS_IMETHOD GetName(char * *aName) { return _to GetName(aName); } \
  NS_SCRIPTABLE NS_IMETHOD GetHidden(PRBool *aHidden) { return _to GetHidden(aHidden); } \
  NS_SCRIPTABLE NS_IMETHOD SetHidden(PRBool aHidden) { return _to SetHidden(aHidden); } \
  NS_SCRIPTABLE NS_IMETHOD GetX(PRInt32 *aX) { return _to GetX(aX); } \
  NS_SCRIPTABLE NS_IMETHOD GetY(PRInt32 *aY) { return _to GetY(aY); } \
  NS_SCRIPTABLE NS_IMETHOD GetWidth(PRInt32 *aWidth) { return _to GetWidth(aWidth); } \
  NS_SCRIPTABLE NS_IMETHOD GetHeight(PRInt32 *aHeight) { return _to GetHeight(aHeight); } 

/* Use this macro to declare functions that forward the behavior of this interface to another object in a safe way. */
#define NS_FORWARD_SAFE_NSIOSCHROMEITEM(_to) \
  NS_SCRIPTABLE NS_IMETHOD GetName(char * *aName) { return !_to ? NS_ERROR_NULL_POINTER : _to->GetName(aName); } \
  NS_SCRIPTABLE NS_IMETHOD GetHidden(PRBool *aHidden) { return !_to ? NS_ERROR_NULL_POINTER : _to->GetHidden(aHidden); } \
  NS_SCRIPTABLE NS_IMETHOD SetHidden(PRBool aHidden) { return !_to ? NS_ERROR_NULL_POINTER : _to->SetHidden(aHidden); } \
  NS_SCRIPTABLE NS_IMETHOD GetX(PRInt32 *aX) { return !_to ? NS_ERROR_NULL_POINTER : _to->GetX(aX); } \
  NS_SCRIPTABLE NS_IMETHOD GetY(PRInt32 *aY) { return !_to ? NS_ERROR_NULL_POINTER : _to->GetY(aY); } \
  NS_SCRIPTABLE NS_IMETHOD GetWidth(PRInt32 *aWidth) { return !_to ? NS_ERROR_NULL_POINTER : _to->GetWidth(aWidth); } \
  NS_SCRIPTABLE NS_IMETHOD GetHeight(PRInt32 *aHeight) { return !_to ? NS_ERROR_NULL_POINTER : _to->GetHeight(aHeight); } 

#if 0
/* Use the code below as a template for the implementation class for this interface. */

/* Header file */
class nsOSChromeItem : public nsIOSChromeItem
{
public:
  NS_DECL_ISUPPORTS
  NS_DECL_NSIOSCHROMEITEM

  nsOSChromeItem();

private:
  ~nsOSChromeItem();

protected:
  /* additional members */
};

/* Implementation file */
NS_IMPL_ISUPPORTS1(nsOSChromeItem, nsIOSChromeItem)

nsOSChromeItem::nsOSChromeItem()
{
  /* member initializers and constructor code */
}

nsOSChromeItem::~nsOSChromeItem()
{
  /* destructor code */
}

/* readonly attribute string name; */
NS_IMETHODIMP nsOSChromeItem::GetName(char * *aName)
{
    return NS_ERROR_NOT_IMPLEMENTED;
}

/* attribute boolean hidden; */
NS_IMETHODIMP nsOSChromeItem::GetHidden(PRBool *aHidden)
{
    return NS_ERROR_NOT_IMPLEMENTED;
}
NS_IMETHODIMP nsOSChromeItem::SetHidden(PRBool aHidden)
{
    return NS_ERROR_NOT_IMPLEMENTED;
}

/* readonly attribute long x; */
NS_IMETHODIMP nsOSChromeItem::GetX(PRInt32 *aX)
{
    return NS_ERROR_NOT_IMPLEMENTED;
}

/* readonly attribute long y; */
NS_IMETHODIMP nsOSChromeItem::GetY(PRInt32 *aY)
{
    return NS_ERROR_NOT_IMPLEMENTED;
}

/* readonly attribute long width; */
NS_IMETHODIMP nsOSChromeItem::GetWidth(PRInt32 *aWidth)
{
    return NS_ERROR_NOT_IMPLEMENTED;
}

/* readonly attribute long height; */
NS_IMETHODIMP nsOSChromeItem::GetHeight(PRInt32 *aHeight)
{
    return NS_ERROR_NOT_IMPLEMENTED;
}

/* End of implementation class template. */
#endif


#endif /* __gen_nsIFullScreen_h__ */
