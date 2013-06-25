/*
 * DO NOT EDIT.  THIS FILE IS GENERATED FROM e:/builds/moz2_slave/mozilla-1.9.1-win32-xulrunner/build/layout/xul/base/public/nsIScrollBoxObject.idl
 */

#ifndef __gen_nsIScrollBoxObject_h__
#define __gen_nsIScrollBoxObject_h__


#ifndef __gen_nsIBoxObject_h__
#include "nsIBoxObject.h"
#endif

/* For IDL files that don't want to include root IDL files. */
#ifndef NS_NO_VTABLE
#define NS_NO_VTABLE
#endif
class nsIDOMElement; /* forward declaration */


/* starting interface:    nsIScrollBoxObject */
#define NS_ISCROLLBOXOBJECT_IID_STR "56e2ada8-4631-11d4-ba11-001083023c1e"

#define NS_ISCROLLBOXOBJECT_IID \
  {0x56e2ada8, 0x4631, 0x11d4, \
    { 0xba, 0x11, 0x00, 0x10, 0x83, 0x02, 0x3c, 0x1e }}

class NS_NO_VTABLE NS_SCRIPTABLE nsIScrollBoxObject : public nsISupports {
 public: 

  NS_DECLARE_STATIC_IID_ACCESSOR(NS_ISCROLLBOXOBJECT_IID)

  /**
   * Scroll to the given coordinates, in css pixels.
   * (0,0) will put the top left corner of the scrolled element's padding-box
   * at the top left corner of the scrollport (which is its inner-border-box).
   * Values will be clamped to legal values.
   */
  /* void scrollTo (in long x, in long y); */
  NS_SCRIPTABLE NS_IMETHOD ScrollTo(PRInt32 x, PRInt32 y) = 0;

  /**
   * Scroll the given amount of device pixels to the right and down.
   * Values will be clamped to make the resuling position legal.
   */
  /* void scrollBy (in long dx, in long dy); */
  NS_SCRIPTABLE NS_IMETHOD ScrollBy(PRInt32 dx, PRInt32 dy) = 0;

  /* void scrollByLine (in long dlines); */
  NS_SCRIPTABLE NS_IMETHOD ScrollByLine(PRInt32 dlines) = 0;

  /* void scrollByIndex (in long dindexes); */
  NS_SCRIPTABLE NS_IMETHOD ScrollByIndex(PRInt32 dindexes) = 0;

  /* void scrollToLine (in long line); */
  NS_SCRIPTABLE NS_IMETHOD ScrollToLine(PRInt32 line) = 0;

  /* void scrollToElement (in nsIDOMElement child); */
  NS_SCRIPTABLE NS_IMETHOD ScrollToElement(nsIDOMElement *child) = 0;

  /* void scrollToIndex (in long index); */
  NS_SCRIPTABLE NS_IMETHOD ScrollToIndex(PRInt32 index) = 0;

  /**
   * Get the current scroll position in css pixels.
   * @see scrollTo for the definition of x and y.
   */
  /* void getPosition (out long x, out long y); */
  NS_SCRIPTABLE NS_IMETHOD GetPosition(PRInt32 *x NS_OUTPARAM, PRInt32 *y NS_OUTPARAM) = 0;

  /* void getScrolledSize (out long width, out long height); */
  NS_SCRIPTABLE NS_IMETHOD GetScrolledSize(PRInt32 *width NS_OUTPARAM, PRInt32 *height NS_OUTPARAM) = 0;

  /* void ensureElementIsVisible (in nsIDOMElement child); */
  NS_SCRIPTABLE NS_IMETHOD EnsureElementIsVisible(nsIDOMElement *child) = 0;

  /* void ensureIndexIsVisible (in long index); */
  NS_SCRIPTABLE NS_IMETHOD EnsureIndexIsVisible(PRInt32 index) = 0;

  /* void ensureLineIsVisible (in long line); */
  NS_SCRIPTABLE NS_IMETHOD EnsureLineIsVisible(PRInt32 line) = 0;

};

  NS_DEFINE_STATIC_IID_ACCESSOR(nsIScrollBoxObject, NS_ISCROLLBOXOBJECT_IID)

/* Use this macro when declaring classes that implement this interface. */
#define NS_DECL_NSISCROLLBOXOBJECT \
  NS_SCRIPTABLE NS_IMETHOD ScrollTo(PRInt32 x, PRInt32 y); \
  NS_SCRIPTABLE NS_IMETHOD ScrollBy(PRInt32 dx, PRInt32 dy); \
  NS_SCRIPTABLE NS_IMETHOD ScrollByLine(PRInt32 dlines); \
  NS_SCRIPTABLE NS_IMETHOD ScrollByIndex(PRInt32 dindexes); \
  NS_SCRIPTABLE NS_IMETHOD ScrollToLine(PRInt32 line); \
  NS_SCRIPTABLE NS_IMETHOD ScrollToElement(nsIDOMElement *child); \
  NS_SCRIPTABLE NS_IMETHOD ScrollToIndex(PRInt32 index); \
  NS_SCRIPTABLE NS_IMETHOD GetPosition(PRInt32 *x NS_OUTPARAM, PRInt32 *y NS_OUTPARAM); \
  NS_SCRIPTABLE NS_IMETHOD GetScrolledSize(PRInt32 *width NS_OUTPARAM, PRInt32 *height NS_OUTPARAM); \
  NS_SCRIPTABLE NS_IMETHOD EnsureElementIsVisible(nsIDOMElement *child); \
  NS_SCRIPTABLE NS_IMETHOD EnsureIndexIsVisible(PRInt32 index); \
  NS_SCRIPTABLE NS_IMETHOD EnsureLineIsVisible(PRInt32 line); 

/* Use this macro to declare functions that forward the behavior of this interface to another object. */
#define NS_FORWARD_NSISCROLLBOXOBJECT(_to) \
  NS_SCRIPTABLE NS_IMETHOD ScrollTo(PRInt32 x, PRInt32 y) { return _to ScrollTo(x, y); } \
  NS_SCRIPTABLE NS_IMETHOD ScrollBy(PRInt32 dx, PRInt32 dy) { return _to ScrollBy(dx, dy); } \
  NS_SCRIPTABLE NS_IMETHOD ScrollByLine(PRInt32 dlines) { return _to ScrollByLine(dlines); } \
  NS_SCRIPTABLE NS_IMETHOD ScrollByIndex(PRInt32 dindexes) { return _to ScrollByIndex(dindexes); } \
  NS_SCRIPTABLE NS_IMETHOD ScrollToLine(PRInt32 line) { return _to ScrollToLine(line); } \
  NS_SCRIPTABLE NS_IMETHOD ScrollToElement(nsIDOMElement *child) { return _to ScrollToElement(child); } \
  NS_SCRIPTABLE NS_IMETHOD ScrollToIndex(PRInt32 index) { return _to ScrollToIndex(index); } \
  NS_SCRIPTABLE NS_IMETHOD GetPosition(PRInt32 *x NS_OUTPARAM, PRInt32 *y NS_OUTPARAM) { return _to GetPosition(x, y); } \
  NS_SCRIPTABLE NS_IMETHOD GetScrolledSize(PRInt32 *width NS_OUTPARAM, PRInt32 *height NS_OUTPARAM) { return _to GetScrolledSize(width, height); } \
  NS_SCRIPTABLE NS_IMETHOD EnsureElementIsVisible(nsIDOMElement *child) { return _to EnsureElementIsVisible(child); } \
  NS_SCRIPTABLE NS_IMETHOD EnsureIndexIsVisible(PRInt32 index) { return _to EnsureIndexIsVisible(index); } \
  NS_SCRIPTABLE NS_IMETHOD EnsureLineIsVisible(PRInt32 line) { return _to EnsureLineIsVisible(line); } 

/* Use this macro to declare functions that forward the behavior of this interface to another object in a safe way. */
#define NS_FORWARD_SAFE_NSISCROLLBOXOBJECT(_to) \
  NS_SCRIPTABLE NS_IMETHOD ScrollTo(PRInt32 x, PRInt32 y) { return !_to ? NS_ERROR_NULL_POINTER : _to->ScrollTo(x, y); } \
  NS_SCRIPTABLE NS_IMETHOD ScrollBy(PRInt32 dx, PRInt32 dy) { return !_to ? NS_ERROR_NULL_POINTER : _to->ScrollBy(dx, dy); } \
  NS_SCRIPTABLE NS_IMETHOD ScrollByLine(PRInt32 dlines) { return !_to ? NS_ERROR_NULL_POINTER : _to->ScrollByLine(dlines); } \
  NS_SCRIPTABLE NS_IMETHOD ScrollByIndex(PRInt32 dindexes) { return !_to ? NS_ERROR_NULL_POINTER : _to->ScrollByIndex(dindexes); } \
  NS_SCRIPTABLE NS_IMETHOD ScrollToLine(PRInt32 line) { return !_to ? NS_ERROR_NULL_POINTER : _to->ScrollToLine(line); } \
  NS_SCRIPTABLE NS_IMETHOD ScrollToElement(nsIDOMElement *child) { return !_to ? NS_ERROR_NULL_POINTER : _to->ScrollToElement(child); } \
  NS_SCRIPTABLE NS_IMETHOD ScrollToIndex(PRInt32 index) { return !_to ? NS_ERROR_NULL_POINTER : _to->ScrollToIndex(index); } \
  NS_SCRIPTABLE NS_IMETHOD GetPosition(PRInt32 *x NS_OUTPARAM, PRInt32 *y NS_OUTPARAM) { return !_to ? NS_ERROR_NULL_POINTER : _to->GetPosition(x, y); } \
  NS_SCRIPTABLE NS_IMETHOD GetScrolledSize(PRInt32 *width NS_OUTPARAM, PRInt32 *height NS_OUTPARAM) { return !_to ? NS_ERROR_NULL_POINTER : _to->GetScrolledSize(width, height); } \
  NS_SCRIPTABLE NS_IMETHOD EnsureElementIsVisible(nsIDOMElement *child) { return !_to ? NS_ERROR_NULL_POINTER : _to->EnsureElementIsVisible(child); } \
  NS_SCRIPTABLE NS_IMETHOD EnsureIndexIsVisible(PRInt32 index) { return !_to ? NS_ERROR_NULL_POINTER : _to->EnsureIndexIsVisible(index); } \
  NS_SCRIPTABLE NS_IMETHOD EnsureLineIsVisible(PRInt32 line) { return !_to ? NS_ERROR_NULL_POINTER : _to->EnsureLineIsVisible(line); } 

#if 0
/* Use the code below as a template for the implementation class for this interface. */

/* Header file */
class nsScrollBoxObject : public nsIScrollBoxObject
{
public:
  NS_DECL_ISUPPORTS
  NS_DECL_NSISCROLLBOXOBJECT

  nsScrollBoxObject();

private:
  ~nsScrollBoxObject();

protected:
  /* additional members */
};

/* Implementation file */
NS_IMPL_ISUPPORTS1(nsScrollBoxObject, nsIScrollBoxObject)

nsScrollBoxObject::nsScrollBoxObject()
{
  /* member initializers and constructor code */
}

nsScrollBoxObject::~nsScrollBoxObject()
{
  /* destructor code */
}

/* void scrollTo (in long x, in long y); */
NS_IMETHODIMP nsScrollBoxObject::ScrollTo(PRInt32 x, PRInt32 y)
{
    return NS_ERROR_NOT_IMPLEMENTED;
}

/* void scrollBy (in long dx, in long dy); */
NS_IMETHODIMP nsScrollBoxObject::ScrollBy(PRInt32 dx, PRInt32 dy)
{
    return NS_ERROR_NOT_IMPLEMENTED;
}

/* void scrollByLine (in long dlines); */
NS_IMETHODIMP nsScrollBoxObject::ScrollByLine(PRInt32 dlines)
{
    return NS_ERROR_NOT_IMPLEMENTED;
}

/* void scrollByIndex (in long dindexes); */
NS_IMETHODIMP nsScrollBoxObject::ScrollByIndex(PRInt32 dindexes)
{
    return NS_ERROR_NOT_IMPLEMENTED;
}

/* void scrollToLine (in long line); */
NS_IMETHODIMP nsScrollBoxObject::ScrollToLine(PRInt32 line)
{
    return NS_ERROR_NOT_IMPLEMENTED;
}

/* void scrollToElement (in nsIDOMElement child); */
NS_IMETHODIMP nsScrollBoxObject::ScrollToElement(nsIDOMElement *child)
{
    return NS_ERROR_NOT_IMPLEMENTED;
}

/* void scrollToIndex (in long index); */
NS_IMETHODIMP nsScrollBoxObject::ScrollToIndex(PRInt32 index)
{
    return NS_ERROR_NOT_IMPLEMENTED;
}

/* void getPosition (out long x, out long y); */
NS_IMETHODIMP nsScrollBoxObject::GetPosition(PRInt32 *x NS_OUTPARAM, PRInt32 *y NS_OUTPARAM)
{
    return NS_ERROR_NOT_IMPLEMENTED;
}

/* void getScrolledSize (out long width, out long height); */
NS_IMETHODIMP nsScrollBoxObject::GetScrolledSize(PRInt32 *width NS_OUTPARAM, PRInt32 *height NS_OUTPARAM)
{
    return NS_ERROR_NOT_IMPLEMENTED;
}

/* void ensureElementIsVisible (in nsIDOMElement child); */
NS_IMETHODIMP nsScrollBoxObject::EnsureElementIsVisible(nsIDOMElement *child)
{
    return NS_ERROR_NOT_IMPLEMENTED;
}

/* void ensureIndexIsVisible (in long index); */
NS_IMETHODIMP nsScrollBoxObject::EnsureIndexIsVisible(PRInt32 index)
{
    return NS_ERROR_NOT_IMPLEMENTED;
}

/* void ensureLineIsVisible (in long line); */
NS_IMETHODIMP nsScrollBoxObject::EnsureLineIsVisible(PRInt32 line)
{
    return NS_ERROR_NOT_IMPLEMENTED;
}

/* End of implementation class template. */
#endif

nsresult
NS_NewScrollBoxObject(nsIBoxObject** aResult);

#endif /* __gen_nsIScrollBoxObject_h__ */
