/*
 * DO NOT EDIT.  THIS FILE IS GENERATED FROM e:/builds/moz2_slave/mozilla-1.9.1-win32-xulrunner/build/docshell/base/nsIScrollable.idl
 */

#ifndef __gen_nsIScrollable_h__
#define __gen_nsIScrollable_h__


#ifndef __gen_nsISupports_h__
#include "nsISupports.h"
#endif

/* For IDL files that don't want to include root IDL files. */
#ifndef NS_NO_VTABLE
#define NS_NO_VTABLE
#endif

/* starting interface:    nsIScrollable */
#define NS_ISCROLLABLE_IID_STR "919e792a-6490-40b8-bba5-f9e9ad5640c8"

#define NS_ISCROLLABLE_IID \
  {0x919e792a, 0x6490, 0x40b8, \
    { 0xbb, 0xa5, 0xf9, 0xe9, 0xad, 0x56, 0x40, 0xc8 }}

/**
 * The nsIScrollable is an interface that can be implemented by a control that
 * supports scrolling.  This is a generic interface without concern for the 
 * type of content that may be inside.  It simply deals blindly with scroll
 * position as a composite of the lowest possible scroll position, the highest
 * possible position and the current position lying somewhere between the 
 * min and the max. 
 */
class NS_NO_VTABLE NS_SCRIPTABLE nsIScrollable : public nsISupports {
 public: 

  NS_DECLARE_STATIC_IID_ACCESSOR(NS_ISCROLLABLE_IID)

  enum { ScrollOrientation_X = 1 };

  enum { ScrollOrientation_Y = 2 };

  /* long getCurScrollPos (in long scrollOrientation); */
  NS_SCRIPTABLE NS_IMETHOD GetCurScrollPos(PRInt32 scrollOrientation, PRInt32 *_retval NS_OUTPARAM) = 0;

  /* void setCurScrollPos (in long scrollOrientation, in long curPos); */
  NS_SCRIPTABLE NS_IMETHOD SetCurScrollPos(PRInt32 scrollOrientation, PRInt32 curPos) = 0;

  /* void setCurScrollPosEx (in long curHorizontalPos, in long curVerticalPos); */
  NS_SCRIPTABLE NS_IMETHOD SetCurScrollPosEx(PRInt32 curHorizontalPos, PRInt32 curVerticalPos) = 0;

  /* void getScrollRange (in long scrollOrientation, out long minPos, out long maxPos); */
  NS_SCRIPTABLE NS_IMETHOD GetScrollRange(PRInt32 scrollOrientation, PRInt32 *minPos NS_OUTPARAM, PRInt32 *maxPos NS_OUTPARAM) = 0;

  /* void setScrollRange (in long scrollOrientation, in long minPos, in long maxPos); */
  NS_SCRIPTABLE NS_IMETHOD SetScrollRange(PRInt32 scrollOrientation, PRInt32 minPos, PRInt32 maxPos) = 0;

  /* void setScrollRangeEx (in long minHorizontalPos, in long maxHorizontalPos, in long minVerticalPos, in long maxVerticalPos); */
  NS_SCRIPTABLE NS_IMETHOD SetScrollRangeEx(PRInt32 minHorizontalPos, PRInt32 maxHorizontalPos, PRInt32 minVerticalPos, PRInt32 maxVerticalPos) = 0;

  enum { Scrollbar_Auto = 1 };

  enum { Scrollbar_Never = 2 };

  enum { Scrollbar_Always = 3 };

  /* long getDefaultScrollbarPreferences (in long scrollOrientation); */
  NS_SCRIPTABLE NS_IMETHOD GetDefaultScrollbarPreferences(PRInt32 scrollOrientation, PRInt32 *_retval NS_OUTPARAM) = 0;

  /* void setDefaultScrollbarPreferences (in long scrollOrientation, in long scrollbarPref); */
  NS_SCRIPTABLE NS_IMETHOD SetDefaultScrollbarPreferences(PRInt32 scrollOrientation, PRInt32 scrollbarPref) = 0;

  /* void getScrollbarVisibility (out boolean verticalVisible, out boolean horizontalVisible); */
  NS_SCRIPTABLE NS_IMETHOD GetScrollbarVisibility(PRBool *verticalVisible NS_OUTPARAM, PRBool *horizontalVisible NS_OUTPARAM) = 0;

};

  NS_DEFINE_STATIC_IID_ACCESSOR(nsIScrollable, NS_ISCROLLABLE_IID)

/* Use this macro when declaring classes that implement this interface. */
#define NS_DECL_NSISCROLLABLE \
  NS_SCRIPTABLE NS_IMETHOD GetCurScrollPos(PRInt32 scrollOrientation, PRInt32 *_retval NS_OUTPARAM); \
  NS_SCRIPTABLE NS_IMETHOD SetCurScrollPos(PRInt32 scrollOrientation, PRInt32 curPos); \
  NS_SCRIPTABLE NS_IMETHOD SetCurScrollPosEx(PRInt32 curHorizontalPos, PRInt32 curVerticalPos); \
  NS_SCRIPTABLE NS_IMETHOD GetScrollRange(PRInt32 scrollOrientation, PRInt32 *minPos NS_OUTPARAM, PRInt32 *maxPos NS_OUTPARAM); \
  NS_SCRIPTABLE NS_IMETHOD SetScrollRange(PRInt32 scrollOrientation, PRInt32 minPos, PRInt32 maxPos); \
  NS_SCRIPTABLE NS_IMETHOD SetScrollRangeEx(PRInt32 minHorizontalPos, PRInt32 maxHorizontalPos, PRInt32 minVerticalPos, PRInt32 maxVerticalPos); \
  NS_SCRIPTABLE NS_IMETHOD GetDefaultScrollbarPreferences(PRInt32 scrollOrientation, PRInt32 *_retval NS_OUTPARAM); \
  NS_SCRIPTABLE NS_IMETHOD SetDefaultScrollbarPreferences(PRInt32 scrollOrientation, PRInt32 scrollbarPref); \
  NS_SCRIPTABLE NS_IMETHOD GetScrollbarVisibility(PRBool *verticalVisible NS_OUTPARAM, PRBool *horizontalVisible NS_OUTPARAM); 

/* Use this macro to declare functions that forward the behavior of this interface to another object. */
#define NS_FORWARD_NSISCROLLABLE(_to) \
  NS_SCRIPTABLE NS_IMETHOD GetCurScrollPos(PRInt32 scrollOrientation, PRInt32 *_retval NS_OUTPARAM) { return _to GetCurScrollPos(scrollOrientation, _retval); } \
  NS_SCRIPTABLE NS_IMETHOD SetCurScrollPos(PRInt32 scrollOrientation, PRInt32 curPos) { return _to SetCurScrollPos(scrollOrientation, curPos); } \
  NS_SCRIPTABLE NS_IMETHOD SetCurScrollPosEx(PRInt32 curHorizontalPos, PRInt32 curVerticalPos) { return _to SetCurScrollPosEx(curHorizontalPos, curVerticalPos); } \
  NS_SCRIPTABLE NS_IMETHOD GetScrollRange(PRInt32 scrollOrientation, PRInt32 *minPos NS_OUTPARAM, PRInt32 *maxPos NS_OUTPARAM) { return _to GetScrollRange(scrollOrientation, minPos, maxPos); } \
  NS_SCRIPTABLE NS_IMETHOD SetScrollRange(PRInt32 scrollOrientation, PRInt32 minPos, PRInt32 maxPos) { return _to SetScrollRange(scrollOrientation, minPos, maxPos); } \
  NS_SCRIPTABLE NS_IMETHOD SetScrollRangeEx(PRInt32 minHorizontalPos, PRInt32 maxHorizontalPos, PRInt32 minVerticalPos, PRInt32 maxVerticalPos) { return _to SetScrollRangeEx(minHorizontalPos, maxHorizontalPos, minVerticalPos, maxVerticalPos); } \
  NS_SCRIPTABLE NS_IMETHOD GetDefaultScrollbarPreferences(PRInt32 scrollOrientation, PRInt32 *_retval NS_OUTPARAM) { return _to GetDefaultScrollbarPreferences(scrollOrientation, _retval); } \
  NS_SCRIPTABLE NS_IMETHOD SetDefaultScrollbarPreferences(PRInt32 scrollOrientation, PRInt32 scrollbarPref) { return _to SetDefaultScrollbarPreferences(scrollOrientation, scrollbarPref); } \
  NS_SCRIPTABLE NS_IMETHOD GetScrollbarVisibility(PRBool *verticalVisible NS_OUTPARAM, PRBool *horizontalVisible NS_OUTPARAM) { return _to GetScrollbarVisibility(verticalVisible, horizontalVisible); } 

/* Use this macro to declare functions that forward the behavior of this interface to another object in a safe way. */
#define NS_FORWARD_SAFE_NSISCROLLABLE(_to) \
  NS_SCRIPTABLE NS_IMETHOD GetCurScrollPos(PRInt32 scrollOrientation, PRInt32 *_retval NS_OUTPARAM) { return !_to ? NS_ERROR_NULL_POINTER : _to->GetCurScrollPos(scrollOrientation, _retval); } \
  NS_SCRIPTABLE NS_IMETHOD SetCurScrollPos(PRInt32 scrollOrientation, PRInt32 curPos) { return !_to ? NS_ERROR_NULL_POINTER : _to->SetCurScrollPos(scrollOrientation, curPos); } \
  NS_SCRIPTABLE NS_IMETHOD SetCurScrollPosEx(PRInt32 curHorizontalPos, PRInt32 curVerticalPos) { return !_to ? NS_ERROR_NULL_POINTER : _to->SetCurScrollPosEx(curHorizontalPos, curVerticalPos); } \
  NS_SCRIPTABLE NS_IMETHOD GetScrollRange(PRInt32 scrollOrientation, PRInt32 *minPos NS_OUTPARAM, PRInt32 *maxPos NS_OUTPARAM) { return !_to ? NS_ERROR_NULL_POINTER : _to->GetScrollRange(scrollOrientation, minPos, maxPos); } \
  NS_SCRIPTABLE NS_IMETHOD SetScrollRange(PRInt32 scrollOrientation, PRInt32 minPos, PRInt32 maxPos) { return !_to ? NS_ERROR_NULL_POINTER : _to->SetScrollRange(scrollOrientation, minPos, maxPos); } \
  NS_SCRIPTABLE NS_IMETHOD SetScrollRangeEx(PRInt32 minHorizontalPos, PRInt32 maxHorizontalPos, PRInt32 minVerticalPos, PRInt32 maxVerticalPos) { return !_to ? NS_ERROR_NULL_POINTER : _to->SetScrollRangeEx(minHorizontalPos, maxHorizontalPos, minVerticalPos, maxVerticalPos); } \
  NS_SCRIPTABLE NS_IMETHOD GetDefaultScrollbarPreferences(PRInt32 scrollOrientation, PRInt32 *_retval NS_OUTPARAM) { return !_to ? NS_ERROR_NULL_POINTER : _to->GetDefaultScrollbarPreferences(scrollOrientation, _retval); } \
  NS_SCRIPTABLE NS_IMETHOD SetDefaultScrollbarPreferences(PRInt32 scrollOrientation, PRInt32 scrollbarPref) { return !_to ? NS_ERROR_NULL_POINTER : _to->SetDefaultScrollbarPreferences(scrollOrientation, scrollbarPref); } \
  NS_SCRIPTABLE NS_IMETHOD GetScrollbarVisibility(PRBool *verticalVisible NS_OUTPARAM, PRBool *horizontalVisible NS_OUTPARAM) { return !_to ? NS_ERROR_NULL_POINTER : _to->GetScrollbarVisibility(verticalVisible, horizontalVisible); } 

#if 0
/* Use the code below as a template for the implementation class for this interface. */

/* Header file */
class nsScrollable : public nsIScrollable
{
public:
  NS_DECL_ISUPPORTS
  NS_DECL_NSISCROLLABLE

  nsScrollable();

private:
  ~nsScrollable();

protected:
  /* additional members */
};

/* Implementation file */
NS_IMPL_ISUPPORTS1(nsScrollable, nsIScrollable)

nsScrollable::nsScrollable()
{
  /* member initializers and constructor code */
}

nsScrollable::~nsScrollable()
{
  /* destructor code */
}

/* long getCurScrollPos (in long scrollOrientation); */
NS_IMETHODIMP nsScrollable::GetCurScrollPos(PRInt32 scrollOrientation, PRInt32 *_retval NS_OUTPARAM)
{
    return NS_ERROR_NOT_IMPLEMENTED;
}

/* void setCurScrollPos (in long scrollOrientation, in long curPos); */
NS_IMETHODIMP nsScrollable::SetCurScrollPos(PRInt32 scrollOrientation, PRInt32 curPos)
{
    return NS_ERROR_NOT_IMPLEMENTED;
}

/* void setCurScrollPosEx (in long curHorizontalPos, in long curVerticalPos); */
NS_IMETHODIMP nsScrollable::SetCurScrollPosEx(PRInt32 curHorizontalPos, PRInt32 curVerticalPos)
{
    return NS_ERROR_NOT_IMPLEMENTED;
}

/* void getScrollRange (in long scrollOrientation, out long minPos, out long maxPos); */
NS_IMETHODIMP nsScrollable::GetScrollRange(PRInt32 scrollOrientation, PRInt32 *minPos NS_OUTPARAM, PRInt32 *maxPos NS_OUTPARAM)
{
    return NS_ERROR_NOT_IMPLEMENTED;
}

/* void setScrollRange (in long scrollOrientation, in long minPos, in long maxPos); */
NS_IMETHODIMP nsScrollable::SetScrollRange(PRInt32 scrollOrientation, PRInt32 minPos, PRInt32 maxPos)
{
    return NS_ERROR_NOT_IMPLEMENTED;
}

/* void setScrollRangeEx (in long minHorizontalPos, in long maxHorizontalPos, in long minVerticalPos, in long maxVerticalPos); */
NS_IMETHODIMP nsScrollable::SetScrollRangeEx(PRInt32 minHorizontalPos, PRInt32 maxHorizontalPos, PRInt32 minVerticalPos, PRInt32 maxVerticalPos)
{
    return NS_ERROR_NOT_IMPLEMENTED;
}

/* long getDefaultScrollbarPreferences (in long scrollOrientation); */
NS_IMETHODIMP nsScrollable::GetDefaultScrollbarPreferences(PRInt32 scrollOrientation, PRInt32 *_retval NS_OUTPARAM)
{
    return NS_ERROR_NOT_IMPLEMENTED;
}

/* void setDefaultScrollbarPreferences (in long scrollOrientation, in long scrollbarPref); */
NS_IMETHODIMP nsScrollable::SetDefaultScrollbarPreferences(PRInt32 scrollOrientation, PRInt32 scrollbarPref)
{
    return NS_ERROR_NOT_IMPLEMENTED;
}

/* void getScrollbarVisibility (out boolean verticalVisible, out boolean horizontalVisible); */
NS_IMETHODIMP nsScrollable::GetScrollbarVisibility(PRBool *verticalVisible NS_OUTPARAM, PRBool *horizontalVisible NS_OUTPARAM)
{
    return NS_ERROR_NOT_IMPLEMENTED;
}

/* End of implementation class template. */
#endif


#endif /* __gen_nsIScrollable_h__ */
