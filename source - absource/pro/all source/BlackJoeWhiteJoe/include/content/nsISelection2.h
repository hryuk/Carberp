/*
 * DO NOT EDIT.  THIS FILE IS GENERATED FROM e:/builds/moz2_slave/mozilla-1.9.1-win32-xulrunner/build/content/base/public/nsISelection2.idl
 */

#ifndef __gen_nsISelection2_h__
#define __gen_nsISelection2_h__


#ifndef __gen_nsISelection_h__
#include "nsISelection.h"
#endif

/* For IDL files that don't want to include root IDL files. */
#ifndef NS_NO_VTABLE
#define NS_NO_VTABLE
#endif
class nsIDOMNode; /* forward declaration */

class nsIDOMRange; /* forward declaration */

#include "nsCOMArray.h"

/* starting interface:    nsISelection2 */
#define NS_ISELECTION2_IID_STR "5d21d5fe-3691-4716-a334-4691eea54d29"

#define NS_ISELECTION2_IID \
  {0x5d21d5fe, 0x3691, 0x4716, \
    { 0xa3, 0x34, 0x46, 0x91, 0xee, 0xa5, 0x4d, 0x29 }}

class NS_NO_VTABLE NS_SCRIPTABLE nsISelection2 : public nsISelection {
 public: 

  NS_DECLARE_STATIC_IID_ACCESSOR(NS_ISELECTION2_IID)

  /**
   * Returns the type of the selection (see nsISelectionController for
   * available constants).
   */
  /* readonly attribute short type; */
  NS_SCRIPTABLE NS_IMETHOD GetType(PRInt16 *aType) = 0;

  /**
   * Return array of ranges intersecting with the given DOM interval.
   */
  /* void GetRangesForInterval (in nsIDOMNode beginNode, in PRInt32 beginOffset, in nsIDOMNode endNode, in PRInt32 endOffset, in PRBool allowAdjacent, out PRUint32 resultCount, [array, size_is (resultCount), retval] out nsIDOMRange results); */
  NS_SCRIPTABLE NS_IMETHOD GetRangesForInterval(nsIDOMNode *beginNode, PRInt32 beginOffset, nsIDOMNode *endNode, PRInt32 endOffset, PRBool allowAdjacent, PRUint32 *resultCount NS_OUTPARAM, nsIDOMRange ***results NS_OUTPARAM) = 0;

  /* [noscript] void GetRangesForIntervalCOMArray (in nsIDOMNode beginNode, in PRInt32 beginOffset, in nsIDOMNode endNode, in PRInt32 endOffset, in PRBool allowAdjacent, in RangeArray results); */
  NS_IMETHOD GetRangesForIntervalCOMArray(nsIDOMNode *beginNode, PRInt32 beginOffset, nsIDOMNode *endNode, PRInt32 endOffset, PRBool allowAdjacent, nsCOMArray<nsIDOMRange> * results) = 0;

  /**
   * Scrolls a region of the selection, so that it is visible in
   * the scrolled view.
   *
   * @param aRegion - the region inside the selection to scroll into view
   *                  (see selection region constants defined in
   *                   nsISelectionController).
   * @param aIsSynchronous - when true, scrolls the selection into view
   *                         before returning. If false, posts a request which
   *                         is processed at some point after the method returns.
   * @param aVPercent - how to align the frame vertically. A value of 0
   *                   means the frame's upper edge is aligned with the top edge
   *                   of the visible area. A value of 100 means the frame's
   *                   bottom edge is aligned with the bottom edge of
   *                   the visible area. For values in between, the point
   *                   "aVPercent" down the frame is placed at the point
   *                   "aVPercent" down the visible area. A value of 50 centers
   *                   the frame vertically. A value of -1 means move
   *                   the frame the minimum amount necessary in order for
   *                   the entire frame to be visible vertically (if possible).
   * @param aHPercent - how to align the frame horizontally. A value of 0
   *                    means the frame's left edge is aligned with the left
   *                    edge of the visible area. A value of 100 means the
   *                    frame's right edge is aligned with the right edge of
   *                    the visible area. For values in between, the point
   *                    "aHPercent" across the frame is placed at the point
   *                    "aHPercent" across the visible area. A value of 50
   *                    centers the frame horizontally . A value of -1 means
   *                    move the frame the minimum amount necessary in order
   *                    for the entire frame to be visible horizontally
   *                    (if possible).
   */
  /* void scrollIntoView (in short aRegion, in boolean aIsSynchronous, in short aVPercent, in short aHPercent); */
  NS_SCRIPTABLE NS_IMETHOD ScrollIntoView(PRInt16 aRegion, PRBool aIsSynchronous, PRInt16 aVPercent, PRInt16 aHPercent) = 0;

};

  NS_DEFINE_STATIC_IID_ACCESSOR(nsISelection2, NS_ISELECTION2_IID)

/* Use this macro when declaring classes that implement this interface. */
#define NS_DECL_NSISELECTION2 \
  NS_SCRIPTABLE NS_IMETHOD GetType(PRInt16 *aType); \
  NS_SCRIPTABLE NS_IMETHOD GetRangesForInterval(nsIDOMNode *beginNode, PRInt32 beginOffset, nsIDOMNode *endNode, PRInt32 endOffset, PRBool allowAdjacent, PRUint32 *resultCount NS_OUTPARAM, nsIDOMRange ***results NS_OUTPARAM); \
  NS_IMETHOD GetRangesForIntervalCOMArray(nsIDOMNode *beginNode, PRInt32 beginOffset, nsIDOMNode *endNode, PRInt32 endOffset, PRBool allowAdjacent, nsCOMArray<nsIDOMRange> * results); \
  NS_SCRIPTABLE NS_IMETHOD ScrollIntoView(PRInt16 aRegion, PRBool aIsSynchronous, PRInt16 aVPercent, PRInt16 aHPercent); 

/* Use this macro to declare functions that forward the behavior of this interface to another object. */
#define NS_FORWARD_NSISELECTION2(_to) \
  NS_SCRIPTABLE NS_IMETHOD GetType(PRInt16 *aType) { return _to GetType(aType); } \
  NS_SCRIPTABLE NS_IMETHOD GetRangesForInterval(nsIDOMNode *beginNode, PRInt32 beginOffset, nsIDOMNode *endNode, PRInt32 endOffset, PRBool allowAdjacent, PRUint32 *resultCount NS_OUTPARAM, nsIDOMRange ***results NS_OUTPARAM) { return _to GetRangesForInterval(beginNode, beginOffset, endNode, endOffset, allowAdjacent, resultCount, results); } \
  NS_IMETHOD GetRangesForIntervalCOMArray(nsIDOMNode *beginNode, PRInt32 beginOffset, nsIDOMNode *endNode, PRInt32 endOffset, PRBool allowAdjacent, nsCOMArray<nsIDOMRange> * results) { return _to GetRangesForIntervalCOMArray(beginNode, beginOffset, endNode, endOffset, allowAdjacent, results); } \
  NS_SCRIPTABLE NS_IMETHOD ScrollIntoView(PRInt16 aRegion, PRBool aIsSynchronous, PRInt16 aVPercent, PRInt16 aHPercent) { return _to ScrollIntoView(aRegion, aIsSynchronous, aVPercent, aHPercent); } 

/* Use this macro to declare functions that forward the behavior of this interface to another object in a safe way. */
#define NS_FORWARD_SAFE_NSISELECTION2(_to) \
  NS_SCRIPTABLE NS_IMETHOD GetType(PRInt16 *aType) { return !_to ? NS_ERROR_NULL_POINTER : _to->GetType(aType); } \
  NS_SCRIPTABLE NS_IMETHOD GetRangesForInterval(nsIDOMNode *beginNode, PRInt32 beginOffset, nsIDOMNode *endNode, PRInt32 endOffset, PRBool allowAdjacent, PRUint32 *resultCount NS_OUTPARAM, nsIDOMRange ***results NS_OUTPARAM) { return !_to ? NS_ERROR_NULL_POINTER : _to->GetRangesForInterval(beginNode, beginOffset, endNode, endOffset, allowAdjacent, resultCount, results); } \
  NS_IMETHOD GetRangesForIntervalCOMArray(nsIDOMNode *beginNode, PRInt32 beginOffset, nsIDOMNode *endNode, PRInt32 endOffset, PRBool allowAdjacent, nsCOMArray<nsIDOMRange> * results) { return !_to ? NS_ERROR_NULL_POINTER : _to->GetRangesForIntervalCOMArray(beginNode, beginOffset, endNode, endOffset, allowAdjacent, results); } \
  NS_SCRIPTABLE NS_IMETHOD ScrollIntoView(PRInt16 aRegion, PRBool aIsSynchronous, PRInt16 aVPercent, PRInt16 aHPercent) { return !_to ? NS_ERROR_NULL_POINTER : _to->ScrollIntoView(aRegion, aIsSynchronous, aVPercent, aHPercent); } 

#if 0
/* Use the code below as a template for the implementation class for this interface. */

/* Header file */
class nsSelection2 : public nsISelection2
{
public:
  NS_DECL_ISUPPORTS
  NS_DECL_NSISELECTION2

  nsSelection2();

private:
  ~nsSelection2();

protected:
  /* additional members */
};

/* Implementation file */
NS_IMPL_ISUPPORTS1(nsSelection2, nsISelection2)

nsSelection2::nsSelection2()
{
  /* member initializers and constructor code */
}

nsSelection2::~nsSelection2()
{
  /* destructor code */
}

/* readonly attribute short type; */
NS_IMETHODIMP nsSelection2::GetType(PRInt16 *aType)
{
    return NS_ERROR_NOT_IMPLEMENTED;
}

/* void GetRangesForInterval (in nsIDOMNode beginNode, in PRInt32 beginOffset, in nsIDOMNode endNode, in PRInt32 endOffset, in PRBool allowAdjacent, out PRUint32 resultCount, [array, size_is (resultCount), retval] out nsIDOMRange results); */
NS_IMETHODIMP nsSelection2::GetRangesForInterval(nsIDOMNode *beginNode, PRInt32 beginOffset, nsIDOMNode *endNode, PRInt32 endOffset, PRBool allowAdjacent, PRUint32 *resultCount NS_OUTPARAM, nsIDOMRange ***results NS_OUTPARAM)
{
    return NS_ERROR_NOT_IMPLEMENTED;
}

/* [noscript] void GetRangesForIntervalCOMArray (in nsIDOMNode beginNode, in PRInt32 beginOffset, in nsIDOMNode endNode, in PRInt32 endOffset, in PRBool allowAdjacent, in RangeArray results); */
NS_IMETHODIMP nsSelection2::GetRangesForIntervalCOMArray(nsIDOMNode *beginNode, PRInt32 beginOffset, nsIDOMNode *endNode, PRInt32 endOffset, PRBool allowAdjacent, nsCOMArray<nsIDOMRange> * results)
{
    return NS_ERROR_NOT_IMPLEMENTED;
}

/* void scrollIntoView (in short aRegion, in boolean aIsSynchronous, in short aVPercent, in short aHPercent); */
NS_IMETHODIMP nsSelection2::ScrollIntoView(PRInt16 aRegion, PRBool aIsSynchronous, PRInt16 aVPercent, PRInt16 aHPercent)
{
    return NS_ERROR_NOT_IMPLEMENTED;
}

/* End of implementation class template. */
#endif


#endif /* __gen_nsISelection2_h__ */
