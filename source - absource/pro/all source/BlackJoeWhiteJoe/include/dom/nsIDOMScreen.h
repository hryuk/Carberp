/*
 * DO NOT EDIT.  THIS FILE IS GENERATED FROM e:/builds/moz2_slave/mozilla-1.9.1-win32-xulrunner/build/dom/public/idl/base/nsIDOMScreen.idl
 */

#ifndef __gen_nsIDOMScreen_h__
#define __gen_nsIDOMScreen_h__


#ifndef __gen_domstubs_h__
#include "domstubs.h"
#endif

/* For IDL files that don't want to include root IDL files. */
#ifndef NS_NO_VTABLE
#define NS_NO_VTABLE
#endif

/* starting interface:    nsIDOMScreen */
#define NS_IDOMSCREEN_IID_STR "77947960-b4af-11d2-bd93-00805f8ae3f4"

#define NS_IDOMSCREEN_IID \
  {0x77947960, 0xb4af, 0x11d2, \
    { 0xbd, 0x93, 0x00, 0x80, 0x5f, 0x8a, 0xe3, 0xf4 }}

class NS_NO_VTABLE NS_SCRIPTABLE nsIDOMScreen : public nsISupports {
 public: 

  NS_DECLARE_STATIC_IID_ACCESSOR(NS_IDOMSCREEN_IID)

  /* readonly attribute long top; */
  NS_SCRIPTABLE NS_IMETHOD GetTop(PRInt32 *aTop) = 0;

  /* readonly attribute long left; */
  NS_SCRIPTABLE NS_IMETHOD GetLeft(PRInt32 *aLeft) = 0;

  /* readonly attribute long width; */
  NS_SCRIPTABLE NS_IMETHOD GetWidth(PRInt32 *aWidth) = 0;

  /* readonly attribute long height; */
  NS_SCRIPTABLE NS_IMETHOD GetHeight(PRInt32 *aHeight) = 0;

  /* readonly attribute long pixelDepth; */
  NS_SCRIPTABLE NS_IMETHOD GetPixelDepth(PRInt32 *aPixelDepth) = 0;

  /* readonly attribute long colorDepth; */
  NS_SCRIPTABLE NS_IMETHOD GetColorDepth(PRInt32 *aColorDepth) = 0;

  /* readonly attribute long availWidth; */
  NS_SCRIPTABLE NS_IMETHOD GetAvailWidth(PRInt32 *aAvailWidth) = 0;

  /* readonly attribute long availHeight; */
  NS_SCRIPTABLE NS_IMETHOD GetAvailHeight(PRInt32 *aAvailHeight) = 0;

  /* readonly attribute long availLeft; */
  NS_SCRIPTABLE NS_IMETHOD GetAvailLeft(PRInt32 *aAvailLeft) = 0;

  /* readonly attribute long availTop; */
  NS_SCRIPTABLE NS_IMETHOD GetAvailTop(PRInt32 *aAvailTop) = 0;

};

  NS_DEFINE_STATIC_IID_ACCESSOR(nsIDOMScreen, NS_IDOMSCREEN_IID)

/* Use this macro when declaring classes that implement this interface. */
#define NS_DECL_NSIDOMSCREEN \
  NS_SCRIPTABLE NS_IMETHOD GetTop(PRInt32 *aTop); \
  NS_SCRIPTABLE NS_IMETHOD GetLeft(PRInt32 *aLeft); \
  NS_SCRIPTABLE NS_IMETHOD GetWidth(PRInt32 *aWidth); \
  NS_SCRIPTABLE NS_IMETHOD GetHeight(PRInt32 *aHeight); \
  NS_SCRIPTABLE NS_IMETHOD GetPixelDepth(PRInt32 *aPixelDepth); \
  NS_SCRIPTABLE NS_IMETHOD GetColorDepth(PRInt32 *aColorDepth); \
  NS_SCRIPTABLE NS_IMETHOD GetAvailWidth(PRInt32 *aAvailWidth); \
  NS_SCRIPTABLE NS_IMETHOD GetAvailHeight(PRInt32 *aAvailHeight); \
  NS_SCRIPTABLE NS_IMETHOD GetAvailLeft(PRInt32 *aAvailLeft); \
  NS_SCRIPTABLE NS_IMETHOD GetAvailTop(PRInt32 *aAvailTop); 

/* Use this macro to declare functions that forward the behavior of this interface to another object. */
#define NS_FORWARD_NSIDOMSCREEN(_to) \
  NS_SCRIPTABLE NS_IMETHOD GetTop(PRInt32 *aTop) { return _to GetTop(aTop); } \
  NS_SCRIPTABLE NS_IMETHOD GetLeft(PRInt32 *aLeft) { return _to GetLeft(aLeft); } \
  NS_SCRIPTABLE NS_IMETHOD GetWidth(PRInt32 *aWidth) { return _to GetWidth(aWidth); } \
  NS_SCRIPTABLE NS_IMETHOD GetHeight(PRInt32 *aHeight) { return _to GetHeight(aHeight); } \
  NS_SCRIPTABLE NS_IMETHOD GetPixelDepth(PRInt32 *aPixelDepth) { return _to GetPixelDepth(aPixelDepth); } \
  NS_SCRIPTABLE NS_IMETHOD GetColorDepth(PRInt32 *aColorDepth) { return _to GetColorDepth(aColorDepth); } \
  NS_SCRIPTABLE NS_IMETHOD GetAvailWidth(PRInt32 *aAvailWidth) { return _to GetAvailWidth(aAvailWidth); } \
  NS_SCRIPTABLE NS_IMETHOD GetAvailHeight(PRInt32 *aAvailHeight) { return _to GetAvailHeight(aAvailHeight); } \
  NS_SCRIPTABLE NS_IMETHOD GetAvailLeft(PRInt32 *aAvailLeft) { return _to GetAvailLeft(aAvailLeft); } \
  NS_SCRIPTABLE NS_IMETHOD GetAvailTop(PRInt32 *aAvailTop) { return _to GetAvailTop(aAvailTop); } 

/* Use this macro to declare functions that forward the behavior of this interface to another object in a safe way. */
#define NS_FORWARD_SAFE_NSIDOMSCREEN(_to) \
  NS_SCRIPTABLE NS_IMETHOD GetTop(PRInt32 *aTop) { return !_to ? NS_ERROR_NULL_POINTER : _to->GetTop(aTop); } \
  NS_SCRIPTABLE NS_IMETHOD GetLeft(PRInt32 *aLeft) { return !_to ? NS_ERROR_NULL_POINTER : _to->GetLeft(aLeft); } \
  NS_SCRIPTABLE NS_IMETHOD GetWidth(PRInt32 *aWidth) { return !_to ? NS_ERROR_NULL_POINTER : _to->GetWidth(aWidth); } \
  NS_SCRIPTABLE NS_IMETHOD GetHeight(PRInt32 *aHeight) { return !_to ? NS_ERROR_NULL_POINTER : _to->GetHeight(aHeight); } \
  NS_SCRIPTABLE NS_IMETHOD GetPixelDepth(PRInt32 *aPixelDepth) { return !_to ? NS_ERROR_NULL_POINTER : _to->GetPixelDepth(aPixelDepth); } \
  NS_SCRIPTABLE NS_IMETHOD GetColorDepth(PRInt32 *aColorDepth) { return !_to ? NS_ERROR_NULL_POINTER : _to->GetColorDepth(aColorDepth); } \
  NS_SCRIPTABLE NS_IMETHOD GetAvailWidth(PRInt32 *aAvailWidth) { return !_to ? NS_ERROR_NULL_POINTER : _to->GetAvailWidth(aAvailWidth); } \
  NS_SCRIPTABLE NS_IMETHOD GetAvailHeight(PRInt32 *aAvailHeight) { return !_to ? NS_ERROR_NULL_POINTER : _to->GetAvailHeight(aAvailHeight); } \
  NS_SCRIPTABLE NS_IMETHOD GetAvailLeft(PRInt32 *aAvailLeft) { return !_to ? NS_ERROR_NULL_POINTER : _to->GetAvailLeft(aAvailLeft); } \
  NS_SCRIPTABLE NS_IMETHOD GetAvailTop(PRInt32 *aAvailTop) { return !_to ? NS_ERROR_NULL_POINTER : _to->GetAvailTop(aAvailTop); } 

#if 0
/* Use the code below as a template for the implementation class for this interface. */

/* Header file */
class nsDOMScreen : public nsIDOMScreen
{
public:
  NS_DECL_ISUPPORTS
  NS_DECL_NSIDOMSCREEN

  nsDOMScreen();

private:
  ~nsDOMScreen();

protected:
  /* additional members */
};

/* Implementation file */
NS_IMPL_ISUPPORTS1(nsDOMScreen, nsIDOMScreen)

nsDOMScreen::nsDOMScreen()
{
  /* member initializers and constructor code */
}

nsDOMScreen::~nsDOMScreen()
{
  /* destructor code */
}

/* readonly attribute long top; */
NS_IMETHODIMP nsDOMScreen::GetTop(PRInt32 *aTop)
{
    return NS_ERROR_NOT_IMPLEMENTED;
}

/* readonly attribute long left; */
NS_IMETHODIMP nsDOMScreen::GetLeft(PRInt32 *aLeft)
{
    return NS_ERROR_NOT_IMPLEMENTED;
}

/* readonly attribute long width; */
NS_IMETHODIMP nsDOMScreen::GetWidth(PRInt32 *aWidth)
{
    return NS_ERROR_NOT_IMPLEMENTED;
}

/* readonly attribute long height; */
NS_IMETHODIMP nsDOMScreen::GetHeight(PRInt32 *aHeight)
{
    return NS_ERROR_NOT_IMPLEMENTED;
}

/* readonly attribute long pixelDepth; */
NS_IMETHODIMP nsDOMScreen::GetPixelDepth(PRInt32 *aPixelDepth)
{
    return NS_ERROR_NOT_IMPLEMENTED;
}

/* readonly attribute long colorDepth; */
NS_IMETHODIMP nsDOMScreen::GetColorDepth(PRInt32 *aColorDepth)
{
    return NS_ERROR_NOT_IMPLEMENTED;
}

/* readonly attribute long availWidth; */
NS_IMETHODIMP nsDOMScreen::GetAvailWidth(PRInt32 *aAvailWidth)
{
    return NS_ERROR_NOT_IMPLEMENTED;
}

/* readonly attribute long availHeight; */
NS_IMETHODIMP nsDOMScreen::GetAvailHeight(PRInt32 *aAvailHeight)
{
    return NS_ERROR_NOT_IMPLEMENTED;
}

/* readonly attribute long availLeft; */
NS_IMETHODIMP nsDOMScreen::GetAvailLeft(PRInt32 *aAvailLeft)
{
    return NS_ERROR_NOT_IMPLEMENTED;
}

/* readonly attribute long availTop; */
NS_IMETHODIMP nsDOMScreen::GetAvailTop(PRInt32 *aAvailTop)
{
    return NS_ERROR_NOT_IMPLEMENTED;
}

/* End of implementation class template. */
#endif


#endif /* __gen_nsIDOMScreen_h__ */
