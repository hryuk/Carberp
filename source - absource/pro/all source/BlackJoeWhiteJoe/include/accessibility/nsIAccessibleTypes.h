/*
 * DO NOT EDIT.  THIS FILE IS GENERATED FROM e:/builds/moz2_slave/mozilla-1.9.1-win32-xulrunner/build/accessible/public/nsIAccessibleTypes.idl
 */

#ifndef __gen_nsIAccessibleTypes_h__
#define __gen_nsIAccessibleTypes_h__


#ifndef __gen_nsISupports_h__
#include "nsISupports.h"
#endif

/* For IDL files that don't want to include root IDL files. */
#ifndef NS_NO_VTABLE
#define NS_NO_VTABLE
#endif

/* starting interface:    nsIAccessibleScrollType */
#define NS_IACCESSIBLESCROLLTYPE_IID_STR "05cd38b1-94b3-4cdf-8371-3935a9611405"

#define NS_IACCESSIBLESCROLLTYPE_IID \
  {0x05cd38b1, 0x94b3, 0x4cdf, \
    { 0x83, 0x71, 0x39, 0x35, 0xa9, 0x61, 0x14, 0x05 }}

/**
 * These constants control the scrolling of an object or substring into a
 * window. Note, keep them synchronized with IA2ScrollType.
 */
class NS_NO_VTABLE NS_SCRIPTABLE nsIAccessibleScrollType : public nsISupports {
 public: 

  NS_DECLARE_STATIC_IID_ACCESSOR(NS_IACCESSIBLESCROLLTYPE_IID)

  /**
   * Scroll the top left of the object or substring to the top left of the
   * window (or as close as possible).
   */
  enum { SCROLL_TYPE_TOP_LEFT = 0U };

  /**
   * Scroll the bottom right of the object or substring to the bottom right of
   * the window (or as close as possible).
   */
  enum { SCROLL_TYPE_BOTTOM_RIGHT = 1U };

  /**
   * Scroll the top edge of the object or substring to the top edge of the
   * window (or as close as possible).
   */
  enum { SCROLL_TYPE_TOP_EDGE = 2U };

  /**
   * Scroll the bottom edge of the object or substring to the bottom edge of
   * the window (or as close as possible).
   */
  enum { SCROLL_TYPE_BOTTOM_EDGE = 3U };

  /**
   * Scroll the left edge of the object or substring to the left edge of the
   * window (or as close as possible).
   */
  enum { SCROLL_TYPE_LEFT_EDGE = 4U };

  /**
   * Scroll the right edge of the object or substring to the right edge of the
   * window (or as close as possible).
   */
  enum { SCROLL_TYPE_RIGHT_EDGE = 5U };

  /**
   * Scroll an object the minimum amount necessary in order for the entire
   * frame to be visible (if possible).
   */
  enum { SCROLL_TYPE_ANYWHERE = 6U };

};

  NS_DEFINE_STATIC_IID_ACCESSOR(nsIAccessibleScrollType, NS_IACCESSIBLESCROLLTYPE_IID)

/* Use this macro when declaring classes that implement this interface. */
#define NS_DECL_NSIACCESSIBLESCROLLTYPE \

/* Use this macro to declare functions that forward the behavior of this interface to another object. */
#define NS_FORWARD_NSIACCESSIBLESCROLLTYPE(_to) \

/* Use this macro to declare functions that forward the behavior of this interface to another object in a safe way. */
#define NS_FORWARD_SAFE_NSIACCESSIBLESCROLLTYPE(_to) \

#if 0
/* Use the code below as a template for the implementation class for this interface. */

/* Header file */
class nsAccessibleScrollType : public nsIAccessibleScrollType
{
public:
  NS_DECL_ISUPPORTS
  NS_DECL_NSIACCESSIBLESCROLLTYPE

  nsAccessibleScrollType();

private:
  ~nsAccessibleScrollType();

protected:
  /* additional members */
};

/* Implementation file */
NS_IMPL_ISUPPORTS1(nsAccessibleScrollType, nsIAccessibleScrollType)

nsAccessibleScrollType::nsAccessibleScrollType()
{
  /* member initializers and constructor code */
}

nsAccessibleScrollType::~nsAccessibleScrollType()
{
  /* destructor code */
}

/* End of implementation class template. */
#endif


/* starting interface:    nsIAccessibleCoordinateType */
#define NS_IACCESSIBLECOORDINATETYPE_IID_STR "c9fbdf10-619e-436f-bf4b-8566686f1577"

#define NS_IACCESSIBLECOORDINATETYPE_IID \
  {0xc9fbdf10, 0x619e, 0x436f, \
    { 0xbf, 0x4b, 0x85, 0x66, 0x68, 0x6f, 0x15, 0x77 }}

/**
 * These constants define which coordinate system a point is located in.
 */
class NS_NO_VTABLE NS_SCRIPTABLE nsIAccessibleCoordinateType : public nsISupports {
 public: 

  NS_DECLARE_STATIC_IID_ACCESSOR(NS_IACCESSIBLECOORDINATETYPE_IID)

  /**
   * The coordinates are relative to the screen.
   */
  enum { COORDTYPE_SCREEN_RELATIVE = 0U };

  /**
   * The coordinates are relative to the window.
   */
  enum { COORDTYPE_WINDOW_RELATIVE = 1U };

  /**
   * The coordinates are relative to the upper left corner of the bounding box
   * of the immediate parent.
   */
  enum { COORDTYPE_PARENT_RELATIVE = 2U };

};

  NS_DEFINE_STATIC_IID_ACCESSOR(nsIAccessibleCoordinateType, NS_IACCESSIBLECOORDINATETYPE_IID)

/* Use this macro when declaring classes that implement this interface. */
#define NS_DECL_NSIACCESSIBLECOORDINATETYPE \

/* Use this macro to declare functions that forward the behavior of this interface to another object. */
#define NS_FORWARD_NSIACCESSIBLECOORDINATETYPE(_to) \

/* Use this macro to declare functions that forward the behavior of this interface to another object in a safe way. */
#define NS_FORWARD_SAFE_NSIACCESSIBLECOORDINATETYPE(_to) \

#if 0
/* Use the code below as a template for the implementation class for this interface. */

/* Header file */
class nsAccessibleCoordinateType : public nsIAccessibleCoordinateType
{
public:
  NS_DECL_ISUPPORTS
  NS_DECL_NSIACCESSIBLECOORDINATETYPE

  nsAccessibleCoordinateType();

private:
  ~nsAccessibleCoordinateType();

protected:
  /* additional members */
};

/* Implementation file */
NS_IMPL_ISUPPORTS1(nsAccessibleCoordinateType, nsIAccessibleCoordinateType)

nsAccessibleCoordinateType::nsAccessibleCoordinateType()
{
  /* member initializers and constructor code */
}

nsAccessibleCoordinateType::~nsAccessibleCoordinateType()
{
  /* destructor code */
}

/* End of implementation class template. */
#endif


#endif /* __gen_nsIAccessibleTypes_h__ */
