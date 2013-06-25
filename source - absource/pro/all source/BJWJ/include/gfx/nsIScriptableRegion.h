/*
 * DO NOT EDIT.  THIS FILE IS GENERATED FROM e:/builds/moz2_slave/mozilla-1.9.1-win32-xulrunner/build/gfx/idl/nsIScriptableRegion.idl
 */

#ifndef __gen_nsIScriptableRegion_h__
#define __gen_nsIScriptableRegion_h__


#ifndef __gen_nsISupports_h__
#include "nsISupports.h"
#endif

/* For IDL files that don't want to include root IDL files. */
#ifndef NS_NO_VTABLE
#define NS_NO_VTABLE
#endif
class nsIRegion;

/* starting interface:    nsIScriptableRegion */
#define NS_ISCRIPTABLEREGION_IID_STR "82d8f400-5bde-11d3-b033-b27a62766bbc"

#define NS_ISCRIPTABLEREGION_IID \
  {0x82d8f400, 0x5bde, 0x11d3, \
    { 0xb0, 0x33, 0xb2, 0x7a, 0x62, 0x76, 0x6b, 0xbc }}

class NS_NO_VTABLE NS_SCRIPTABLE nsIScriptableRegion : public nsISupports {
 public: 

  NS_DECLARE_STATIC_IID_ACCESSOR(NS_ISCRIPTABLEREGION_IID)

  /* void init (); */
  NS_SCRIPTABLE NS_IMETHOD Init(void) = 0;

  /**
  * copy operator equivalent that takes another region
  *
  * @param      region to copy
  * @return     void
  *
  **/
  /* void setToRegion (in nsIScriptableRegion aRegion); */
  NS_SCRIPTABLE NS_IMETHOD SetToRegion(nsIScriptableRegion *aRegion) = 0;

  /**
  * copy operator equivalent that takes a rect
  *
  * @param      aX xoffset of rect to set region to
  * @param      aY yoffset of rect to set region to
  * @param      aWidth width of rect to set region to
  * @param      aHeight height of rect to set region to
  * @return     void
  *
  **/
  /* void setToRect (in long aX, in long aY, in long aWidth, in long aHeight); */
  NS_SCRIPTABLE NS_IMETHOD SetToRect(PRInt32 aX, PRInt32 aY, PRInt32 aWidth, PRInt32 aHeight) = 0;

  /**
  * destructively intersect another region with this one
  *
  * @param      region to intersect
  * @return     void
  *
  **/
  /* void intersectRegion (in nsIScriptableRegion aRegion); */
  NS_SCRIPTABLE NS_IMETHOD IntersectRegion(nsIScriptableRegion *aRegion) = 0;

  /**
  * destructively intersect a rect with this region
  *
  * @param      aX xoffset of rect to intersect with region
  * @param      aY yoffset of rect to intersect with region
  * @param      aWidth width of rect to intersect with region
  * @param      aHeight height of rect to intersect with region
  * @return     void
  *
  **/
  /* void intersectRect (in long aX, in long aY, in long aWidth, in long aHeight); */
  NS_SCRIPTABLE NS_IMETHOD IntersectRect(PRInt32 aX, PRInt32 aY, PRInt32 aWidth, PRInt32 aHeight) = 0;

  /**
  * destructively union another region with this one
  *
  * @param      region to union
  * @return     void
  *
  **/
  /* void unionRegion (in nsIScriptableRegion aRegion); */
  NS_SCRIPTABLE NS_IMETHOD UnionRegion(nsIScriptableRegion *aRegion) = 0;

  /**
  * destructively union a rect with this region
  *
  * @param      aX xoffset of rect to union with region
  * @param      aY yoffset of rect to union with region
  * @param      aWidth width of rect to union with region
  * @param      aHeight height of rect to union with region
  * @return     void
  *
  **/
  /* void unionRect (in long aX, in long aY, in long aWidth, in long aHeight); */
  NS_SCRIPTABLE NS_IMETHOD UnionRect(PRInt32 aX, PRInt32 aY, PRInt32 aWidth, PRInt32 aHeight) = 0;

  /**
  * destructively subtract another region with this one
  *
  * @param      region to subtract
  * @return     void
  *
  **/
  /* void subtractRegion (in nsIScriptableRegion aRegion); */
  NS_SCRIPTABLE NS_IMETHOD SubtractRegion(nsIScriptableRegion *aRegion) = 0;

  /**
  * destructively subtract a rect from this region
  *
  * @param      aX xoffset of rect to subtract with region
  * @param      aY yoffset of rect to subtract with region
  * @param      aWidth width of rect to subtract with region
  * @param      aHeight height of rect to subtract with region
  * @return     void
  *
  **/
  /* void subtractRect (in long aX, in long aY, in long aWidth, in long aHeight); */
  NS_SCRIPTABLE NS_IMETHOD SubtractRect(PRInt32 aX, PRInt32 aY, PRInt32 aWidth, PRInt32 aHeight) = 0;

  /**
  * is this region empty? i.e. does it contain any pixels
  *
  * @param      none
  * @return     returns whether the region is empty
  *
  **/
  /* boolean isEmpty (); */
  NS_SCRIPTABLE NS_IMETHOD IsEmpty(PRBool *_retval NS_OUTPARAM) = 0;

  /**
  * == operator equivalent i.e. do the regions contain exactly
  * the same pixels
  *
  * @param      region to compare
  * @return     whether the regions are identical
  *
  **/
  /* boolean isEqualRegion (in nsIScriptableRegion aRegion); */
  NS_SCRIPTABLE NS_IMETHOD IsEqualRegion(nsIScriptableRegion *aRegion, PRBool *_retval NS_OUTPARAM) = 0;

  /**
  * returns the bounding box of the region i.e. the smallest
  * rectangle that completely contains the region.        
  *
  * @param      aX out parameter for xoffset of bounding rect for region
  * @param      aY out parameter for yoffset of bounding rect for region
  * @param      aWidth out parameter for width of bounding rect for region
  * @param      aHeight out parameter for height of bounding rect for region
  * @return     void
  *
  **/
  /* void getBoundingBox (out long aX, out long aY, out long aWidth, out long aHeight); */
  NS_SCRIPTABLE NS_IMETHOD GetBoundingBox(PRInt32 *aX NS_OUTPARAM, PRInt32 *aY NS_OUTPARAM, PRInt32 *aWidth NS_OUTPARAM, PRInt32 *aHeight NS_OUTPARAM) = 0;

  /**
  * offsets the region in x and y
  *
  * @param  xoffset  pixel offset in x
  * @param  yoffset  pixel offset in y
  * @return          void
  *
  **/
  /* void offset (in long aXOffset, in long aYOffset); */
  NS_SCRIPTABLE NS_IMETHOD Offset(PRInt32 aXOffset, PRInt32 aYOffset) = 0;

  /**
  * does the region intersect the rectangle?
  *
  * @param      rect to check for containment
  * @return     true if the region intersects the rect
  *
  **/
  /* boolean containsRect (in long aX, in long aY, in long aWidth, in long aHeight); */
  NS_SCRIPTABLE NS_IMETHOD ContainsRect(PRInt32 aX, PRInt32 aY, PRInt32 aWidth, PRInt32 aHeight, PRBool *_retval NS_OUTPARAM) = 0;

  /* [noscript] readonly attribute nsIRegion region; */
  NS_IMETHOD GetRegion(nsIRegion * *aRegion) = 0;

};

  NS_DEFINE_STATIC_IID_ACCESSOR(nsIScriptableRegion, NS_ISCRIPTABLEREGION_IID)

/* Use this macro when declaring classes that implement this interface. */
#define NS_DECL_NSISCRIPTABLEREGION \
  NS_SCRIPTABLE NS_IMETHOD Init(void); \
  NS_SCRIPTABLE NS_IMETHOD SetToRegion(nsIScriptableRegion *aRegion); \
  NS_SCRIPTABLE NS_IMETHOD SetToRect(PRInt32 aX, PRInt32 aY, PRInt32 aWidth, PRInt32 aHeight); \
  NS_SCRIPTABLE NS_IMETHOD IntersectRegion(nsIScriptableRegion *aRegion); \
  NS_SCRIPTABLE NS_IMETHOD IntersectRect(PRInt32 aX, PRInt32 aY, PRInt32 aWidth, PRInt32 aHeight); \
  NS_SCRIPTABLE NS_IMETHOD UnionRegion(nsIScriptableRegion *aRegion); \
  NS_SCRIPTABLE NS_IMETHOD UnionRect(PRInt32 aX, PRInt32 aY, PRInt32 aWidth, PRInt32 aHeight); \
  NS_SCRIPTABLE NS_IMETHOD SubtractRegion(nsIScriptableRegion *aRegion); \
  NS_SCRIPTABLE NS_IMETHOD SubtractRect(PRInt32 aX, PRInt32 aY, PRInt32 aWidth, PRInt32 aHeight); \
  NS_SCRIPTABLE NS_IMETHOD IsEmpty(PRBool *_retval NS_OUTPARAM); \
  NS_SCRIPTABLE NS_IMETHOD IsEqualRegion(nsIScriptableRegion *aRegion, PRBool *_retval NS_OUTPARAM); \
  NS_SCRIPTABLE NS_IMETHOD GetBoundingBox(PRInt32 *aX NS_OUTPARAM, PRInt32 *aY NS_OUTPARAM, PRInt32 *aWidth NS_OUTPARAM, PRInt32 *aHeight NS_OUTPARAM); \
  NS_SCRIPTABLE NS_IMETHOD Offset(PRInt32 aXOffset, PRInt32 aYOffset); \
  NS_SCRIPTABLE NS_IMETHOD ContainsRect(PRInt32 aX, PRInt32 aY, PRInt32 aWidth, PRInt32 aHeight, PRBool *_retval NS_OUTPARAM); \
  NS_IMETHOD GetRegion(nsIRegion * *aRegion); 

/* Use this macro to declare functions that forward the behavior of this interface to another object. */
#define NS_FORWARD_NSISCRIPTABLEREGION(_to) \
  NS_SCRIPTABLE NS_IMETHOD Init(void) { return _to Init(); } \
  NS_SCRIPTABLE NS_IMETHOD SetToRegion(nsIScriptableRegion *aRegion) { return _to SetToRegion(aRegion); } \
  NS_SCRIPTABLE NS_IMETHOD SetToRect(PRInt32 aX, PRInt32 aY, PRInt32 aWidth, PRInt32 aHeight) { return _to SetToRect(aX, aY, aWidth, aHeight); } \
  NS_SCRIPTABLE NS_IMETHOD IntersectRegion(nsIScriptableRegion *aRegion) { return _to IntersectRegion(aRegion); } \
  NS_SCRIPTABLE NS_IMETHOD IntersectRect(PRInt32 aX, PRInt32 aY, PRInt32 aWidth, PRInt32 aHeight) { return _to IntersectRect(aX, aY, aWidth, aHeight); } \
  NS_SCRIPTABLE NS_IMETHOD UnionRegion(nsIScriptableRegion *aRegion) { return _to UnionRegion(aRegion); } \
  NS_SCRIPTABLE NS_IMETHOD UnionRect(PRInt32 aX, PRInt32 aY, PRInt32 aWidth, PRInt32 aHeight) { return _to UnionRect(aX, aY, aWidth, aHeight); } \
  NS_SCRIPTABLE NS_IMETHOD SubtractRegion(nsIScriptableRegion *aRegion) { return _to SubtractRegion(aRegion); } \
  NS_SCRIPTABLE NS_IMETHOD SubtractRect(PRInt32 aX, PRInt32 aY, PRInt32 aWidth, PRInt32 aHeight) { return _to SubtractRect(aX, aY, aWidth, aHeight); } \
  NS_SCRIPTABLE NS_IMETHOD IsEmpty(PRBool *_retval NS_OUTPARAM) { return _to IsEmpty(_retval); } \
  NS_SCRIPTABLE NS_IMETHOD IsEqualRegion(nsIScriptableRegion *aRegion, PRBool *_retval NS_OUTPARAM) { return _to IsEqualRegion(aRegion, _retval); } \
  NS_SCRIPTABLE NS_IMETHOD GetBoundingBox(PRInt32 *aX NS_OUTPARAM, PRInt32 *aY NS_OUTPARAM, PRInt32 *aWidth NS_OUTPARAM, PRInt32 *aHeight NS_OUTPARAM) { return _to GetBoundingBox(aX, aY, aWidth, aHeight); } \
  NS_SCRIPTABLE NS_IMETHOD Offset(PRInt32 aXOffset, PRInt32 aYOffset) { return _to Offset(aXOffset, aYOffset); } \
  NS_SCRIPTABLE NS_IMETHOD ContainsRect(PRInt32 aX, PRInt32 aY, PRInt32 aWidth, PRInt32 aHeight, PRBool *_retval NS_OUTPARAM) { return _to ContainsRect(aX, aY, aWidth, aHeight, _retval); } \
  NS_IMETHOD GetRegion(nsIRegion * *aRegion) { return _to GetRegion(aRegion); } 

/* Use this macro to declare functions that forward the behavior of this interface to another object in a safe way. */
#define NS_FORWARD_SAFE_NSISCRIPTABLEREGION(_to) \
  NS_SCRIPTABLE NS_IMETHOD Init(void) { return !_to ? NS_ERROR_NULL_POINTER : _to->Init(); } \
  NS_SCRIPTABLE NS_IMETHOD SetToRegion(nsIScriptableRegion *aRegion) { return !_to ? NS_ERROR_NULL_POINTER : _to->SetToRegion(aRegion); } \
  NS_SCRIPTABLE NS_IMETHOD SetToRect(PRInt32 aX, PRInt32 aY, PRInt32 aWidth, PRInt32 aHeight) { return !_to ? NS_ERROR_NULL_POINTER : _to->SetToRect(aX, aY, aWidth, aHeight); } \
  NS_SCRIPTABLE NS_IMETHOD IntersectRegion(nsIScriptableRegion *aRegion) { return !_to ? NS_ERROR_NULL_POINTER : _to->IntersectRegion(aRegion); } \
  NS_SCRIPTABLE NS_IMETHOD IntersectRect(PRInt32 aX, PRInt32 aY, PRInt32 aWidth, PRInt32 aHeight) { return !_to ? NS_ERROR_NULL_POINTER : _to->IntersectRect(aX, aY, aWidth, aHeight); } \
  NS_SCRIPTABLE NS_IMETHOD UnionRegion(nsIScriptableRegion *aRegion) { return !_to ? NS_ERROR_NULL_POINTER : _to->UnionRegion(aRegion); } \
  NS_SCRIPTABLE NS_IMETHOD UnionRect(PRInt32 aX, PRInt32 aY, PRInt32 aWidth, PRInt32 aHeight) { return !_to ? NS_ERROR_NULL_POINTER : _to->UnionRect(aX, aY, aWidth, aHeight); } \
  NS_SCRIPTABLE NS_IMETHOD SubtractRegion(nsIScriptableRegion *aRegion) { return !_to ? NS_ERROR_NULL_POINTER : _to->SubtractRegion(aRegion); } \
  NS_SCRIPTABLE NS_IMETHOD SubtractRect(PRInt32 aX, PRInt32 aY, PRInt32 aWidth, PRInt32 aHeight) { return !_to ? NS_ERROR_NULL_POINTER : _to->SubtractRect(aX, aY, aWidth, aHeight); } \
  NS_SCRIPTABLE NS_IMETHOD IsEmpty(PRBool *_retval NS_OUTPARAM) { return !_to ? NS_ERROR_NULL_POINTER : _to->IsEmpty(_retval); } \
  NS_SCRIPTABLE NS_IMETHOD IsEqualRegion(nsIScriptableRegion *aRegion, PRBool *_retval NS_OUTPARAM) { return !_to ? NS_ERROR_NULL_POINTER : _to->IsEqualRegion(aRegion, _retval); } \
  NS_SCRIPTABLE NS_IMETHOD GetBoundingBox(PRInt32 *aX NS_OUTPARAM, PRInt32 *aY NS_OUTPARAM, PRInt32 *aWidth NS_OUTPARAM, PRInt32 *aHeight NS_OUTPARAM) { return !_to ? NS_ERROR_NULL_POINTER : _to->GetBoundingBox(aX, aY, aWidth, aHeight); } \
  NS_SCRIPTABLE NS_IMETHOD Offset(PRInt32 aXOffset, PRInt32 aYOffset) { return !_to ? NS_ERROR_NULL_POINTER : _to->Offset(aXOffset, aYOffset); } \
  NS_SCRIPTABLE NS_IMETHOD ContainsRect(PRInt32 aX, PRInt32 aY, PRInt32 aWidth, PRInt32 aHeight, PRBool *_retval NS_OUTPARAM) { return !_to ? NS_ERROR_NULL_POINTER : _to->ContainsRect(aX, aY, aWidth, aHeight, _retval); } \
  NS_IMETHOD GetRegion(nsIRegion * *aRegion) { return !_to ? NS_ERROR_NULL_POINTER : _to->GetRegion(aRegion); } 

#if 0
/* Use the code below as a template for the implementation class for this interface. */

/* Header file */
class nsScriptableRegion : public nsIScriptableRegion
{
public:
  NS_DECL_ISUPPORTS
  NS_DECL_NSISCRIPTABLEREGION

  nsScriptableRegion();

private:
  ~nsScriptableRegion();

protected:
  /* additional members */
};

/* Implementation file */
NS_IMPL_ISUPPORTS1(nsScriptableRegion, nsIScriptableRegion)

nsScriptableRegion::nsScriptableRegion()
{
  /* member initializers and constructor code */
}

nsScriptableRegion::~nsScriptableRegion()
{
  /* destructor code */
}

/* void init (); */
NS_IMETHODIMP nsScriptableRegion::Init()
{
    return NS_ERROR_NOT_IMPLEMENTED;
}

/* void setToRegion (in nsIScriptableRegion aRegion); */
NS_IMETHODIMP nsScriptableRegion::SetToRegion(nsIScriptableRegion *aRegion)
{
    return NS_ERROR_NOT_IMPLEMENTED;
}

/* void setToRect (in long aX, in long aY, in long aWidth, in long aHeight); */
NS_IMETHODIMP nsScriptableRegion::SetToRect(PRInt32 aX, PRInt32 aY, PRInt32 aWidth, PRInt32 aHeight)
{
    return NS_ERROR_NOT_IMPLEMENTED;
}

/* void intersectRegion (in nsIScriptableRegion aRegion); */
NS_IMETHODIMP nsScriptableRegion::IntersectRegion(nsIScriptableRegion *aRegion)
{
    return NS_ERROR_NOT_IMPLEMENTED;
}

/* void intersectRect (in long aX, in long aY, in long aWidth, in long aHeight); */
NS_IMETHODIMP nsScriptableRegion::IntersectRect(PRInt32 aX, PRInt32 aY, PRInt32 aWidth, PRInt32 aHeight)
{
    return NS_ERROR_NOT_IMPLEMENTED;
}

/* void unionRegion (in nsIScriptableRegion aRegion); */
NS_IMETHODIMP nsScriptableRegion::UnionRegion(nsIScriptableRegion *aRegion)
{
    return NS_ERROR_NOT_IMPLEMENTED;
}

/* void unionRect (in long aX, in long aY, in long aWidth, in long aHeight); */
NS_IMETHODIMP nsScriptableRegion::UnionRect(PRInt32 aX, PRInt32 aY, PRInt32 aWidth, PRInt32 aHeight)
{
    return NS_ERROR_NOT_IMPLEMENTED;
}

/* void subtractRegion (in nsIScriptableRegion aRegion); */
NS_IMETHODIMP nsScriptableRegion::SubtractRegion(nsIScriptableRegion *aRegion)
{
    return NS_ERROR_NOT_IMPLEMENTED;
}

/* void subtractRect (in long aX, in long aY, in long aWidth, in long aHeight); */
NS_IMETHODIMP nsScriptableRegion::SubtractRect(PRInt32 aX, PRInt32 aY, PRInt32 aWidth, PRInt32 aHeight)
{
    return NS_ERROR_NOT_IMPLEMENTED;
}

/* boolean isEmpty (); */
NS_IMETHODIMP nsScriptableRegion::IsEmpty(PRBool *_retval NS_OUTPARAM)
{
    return NS_ERROR_NOT_IMPLEMENTED;
}

/* boolean isEqualRegion (in nsIScriptableRegion aRegion); */
NS_IMETHODIMP nsScriptableRegion::IsEqualRegion(nsIScriptableRegion *aRegion, PRBool *_retval NS_OUTPARAM)
{
    return NS_ERROR_NOT_IMPLEMENTED;
}

/* void getBoundingBox (out long aX, out long aY, out long aWidth, out long aHeight); */
NS_IMETHODIMP nsScriptableRegion::GetBoundingBox(PRInt32 *aX NS_OUTPARAM, PRInt32 *aY NS_OUTPARAM, PRInt32 *aWidth NS_OUTPARAM, PRInt32 *aHeight NS_OUTPARAM)
{
    return NS_ERROR_NOT_IMPLEMENTED;
}

/* void offset (in long aXOffset, in long aYOffset); */
NS_IMETHODIMP nsScriptableRegion::Offset(PRInt32 aXOffset, PRInt32 aYOffset)
{
    return NS_ERROR_NOT_IMPLEMENTED;
}

/* boolean containsRect (in long aX, in long aY, in long aWidth, in long aHeight); */
NS_IMETHODIMP nsScriptableRegion::ContainsRect(PRInt32 aX, PRInt32 aY, PRInt32 aWidth, PRInt32 aHeight, PRBool *_retval NS_OUTPARAM)
{
    return NS_ERROR_NOT_IMPLEMENTED;
}

/* [noscript] readonly attribute nsIRegion region; */
NS_IMETHODIMP nsScriptableRegion::GetRegion(nsIRegion * *aRegion)
{
    return NS_ERROR_NOT_IMPLEMENTED;
}

/* End of implementation class template. */
#endif


#endif /* __gen_nsIScriptableRegion_h__ */
