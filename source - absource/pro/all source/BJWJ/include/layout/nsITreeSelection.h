/*
 * DO NOT EDIT.  THIS FILE IS GENERATED FROM e:/builds/moz2_slave/mozilla-1.9.1-win32-xulrunner/build/layout/xul/base/src/tree/public/nsITreeSelection.idl
 */

#ifndef __gen_nsITreeSelection_h__
#define __gen_nsITreeSelection_h__


#ifndef __gen_nsISupports_h__
#include "nsISupports.h"
#endif

/* For IDL files that don't want to include root IDL files. */
#ifndef NS_NO_VTABLE
#define NS_NO_VTABLE
#endif
class nsITreeBoxObject; /* forward declaration */

class nsITreeColumn; /* forward declaration */


/* starting interface:    nsITreeSelection */
#define NS_ITREESELECTION_IID_STR "ab6fe746-300b-4ab4-abb9-1c0e3977874c"

#define NS_ITREESELECTION_IID \
  {0xab6fe746, 0x300b, 0x4ab4, \
    { 0xab, 0xb9, 0x1c, 0x0e, 0x39, 0x77, 0x87, 0x4c }}

class NS_NO_VTABLE NS_SCRIPTABLE nsITreeSelection : public nsISupports {
 public: 

  NS_DECLARE_STATIC_IID_ACCESSOR(NS_ITREESELECTION_IID)

  /**
   * The tree widget for this selection.
   */
  /* attribute nsITreeBoxObject tree; */
  NS_SCRIPTABLE NS_IMETHOD GetTree(nsITreeBoxObject * *aTree) = 0;
  NS_SCRIPTABLE NS_IMETHOD SetTree(nsITreeBoxObject * aTree) = 0;

  /**
   * This attribute is a boolean indicating single selection.
   */
  /* readonly attribute boolean single; */
  NS_SCRIPTABLE NS_IMETHOD GetSingle(PRBool *aSingle) = 0;

  /**
   * The number of rows currently selected in this tree.
   */
  /* readonly attribute long count; */
  NS_SCRIPTABLE NS_IMETHOD GetCount(PRInt32 *aCount) = 0;

  /**
   * Indicates whether or not the row at the specified index is
   * part of the selection.
   */
  /* boolean isSelected (in long index); */
  NS_SCRIPTABLE NS_IMETHOD IsSelected(PRInt32 index, PRBool *_retval NS_OUTPARAM) = 0;

  /**
   * Deselect all rows and select the row at the specified index. 
   */
  /* void select (in long index); */
  NS_SCRIPTABLE NS_IMETHOD Select(PRInt32 index) = 0;

  /**
   * Perform a timed select.
   */
  /* void timedSelect (in long index, in long delay); */
  NS_SCRIPTABLE NS_IMETHOD TimedSelect(PRInt32 index, PRInt32 delay) = 0;

  /**
   * Toggle the selection state of the row at the specified index.
   */
  /* void toggleSelect (in long index); */
  NS_SCRIPTABLE NS_IMETHOD ToggleSelect(PRInt32 index) = 0;

  /**
   * Select the range specified by the indices.  If augment is true,
   * then we add the range to the selection without clearing out anything
   * else.  If augment is false, everything is cleared except for the specified range.
   */
  /* void rangedSelect (in long startIndex, in long endIndex, in boolean augment); */
  NS_SCRIPTABLE NS_IMETHOD RangedSelect(PRInt32 startIndex, PRInt32 endIndex, PRBool augment) = 0;

  /**
   * Clears the range.
   */
  /* void clearRange (in long startIndex, in long endIndex); */
  NS_SCRIPTABLE NS_IMETHOD ClearRange(PRInt32 startIndex, PRInt32 endIndex) = 0;

  /**
   * Clears the selection.
   */
  /* void clearSelection (); */
  NS_SCRIPTABLE NS_IMETHOD ClearSelection(void) = 0;

  /**
   * Inverts the selection.
   */
  /* void invertSelection (); */
  NS_SCRIPTABLE NS_IMETHOD InvertSelection(void) = 0;

  /**
   * Selects all rows.
   */
  /* void selectAll (); */
  NS_SCRIPTABLE NS_IMETHOD SelectAll(void) = 0;

  /**
   * Iterate the selection using these methods.
   */
  /* long getRangeCount (); */
  NS_SCRIPTABLE NS_IMETHOD GetRangeCount(PRInt32 *_retval NS_OUTPARAM) = 0;

  /* void getRangeAt (in long i, out long min, out long max); */
  NS_SCRIPTABLE NS_IMETHOD GetRangeAt(PRInt32 i, PRInt32 *min NS_OUTPARAM, PRInt32 *max NS_OUTPARAM) = 0;

  /**
   * Can be used to invalidate the selection.
   */
  /* void invalidateSelection (); */
  NS_SCRIPTABLE NS_IMETHOD InvalidateSelection(void) = 0;

  /**
   * Called when the row count changes to adjust selection indices.
   */
  /* void adjustSelection (in long index, in long count); */
  NS_SCRIPTABLE NS_IMETHOD AdjustSelection(PRInt32 index, PRInt32 count) = 0;

  /**
   * This attribute is a boolean indicating whether or not the
   * "select" event should fire when the selection is changed using
   * one of our methods.  A view can use this to temporarily suppress
   * the selection while manipulating all of the indices, e.g., on 
   * a sort.
   * Note: setting this attribute to false will fire a select event.
   */
  /* attribute boolean selectEventsSuppressed; */
  NS_SCRIPTABLE NS_IMETHOD GetSelectEventsSuppressed(PRBool *aSelectEventsSuppressed) = 0;
  NS_SCRIPTABLE NS_IMETHOD SetSelectEventsSuppressed(PRBool aSelectEventsSuppressed) = 0;

  /**
   * The current item (the one that gets a focus rect in addition to being
   * selected).
   */
  /* attribute long currentIndex; */
  NS_SCRIPTABLE NS_IMETHOD GetCurrentIndex(PRInt32 *aCurrentIndex) = 0;
  NS_SCRIPTABLE NS_IMETHOD SetCurrentIndex(PRInt32 aCurrentIndex) = 0;

  /**
   * The current column.
   */
  /* attribute nsITreeColumn currentColumn; */
  NS_SCRIPTABLE NS_IMETHOD GetCurrentColumn(nsITreeColumn * *aCurrentColumn) = 0;
  NS_SCRIPTABLE NS_IMETHOD SetCurrentColumn(nsITreeColumn * aCurrentColumn) = 0;

  /**
   * The selection "pivot".  This is the first item the user selected as
   * part of a ranged select.
   */
  /* readonly attribute long shiftSelectPivot; */
  NS_SCRIPTABLE NS_IMETHOD GetShiftSelectPivot(PRInt32 *aShiftSelectPivot) = 0;

};

  NS_DEFINE_STATIC_IID_ACCESSOR(nsITreeSelection, NS_ITREESELECTION_IID)

/* Use this macro when declaring classes that implement this interface. */
#define NS_DECL_NSITREESELECTION \
  NS_SCRIPTABLE NS_IMETHOD GetTree(nsITreeBoxObject * *aTree); \
  NS_SCRIPTABLE NS_IMETHOD SetTree(nsITreeBoxObject * aTree); \
  NS_SCRIPTABLE NS_IMETHOD GetSingle(PRBool *aSingle); \
  NS_SCRIPTABLE NS_IMETHOD GetCount(PRInt32 *aCount); \
  NS_SCRIPTABLE NS_IMETHOD IsSelected(PRInt32 index, PRBool *_retval NS_OUTPARAM); \
  NS_SCRIPTABLE NS_IMETHOD Select(PRInt32 index); \
  NS_SCRIPTABLE NS_IMETHOD TimedSelect(PRInt32 index, PRInt32 delay); \
  NS_SCRIPTABLE NS_IMETHOD ToggleSelect(PRInt32 index); \
  NS_SCRIPTABLE NS_IMETHOD RangedSelect(PRInt32 startIndex, PRInt32 endIndex, PRBool augment); \
  NS_SCRIPTABLE NS_IMETHOD ClearRange(PRInt32 startIndex, PRInt32 endIndex); \
  NS_SCRIPTABLE NS_IMETHOD ClearSelection(void); \
  NS_SCRIPTABLE NS_IMETHOD InvertSelection(void); \
  NS_SCRIPTABLE NS_IMETHOD SelectAll(void); \
  NS_SCRIPTABLE NS_IMETHOD GetRangeCount(PRInt32 *_retval NS_OUTPARAM); \
  NS_SCRIPTABLE NS_IMETHOD GetRangeAt(PRInt32 i, PRInt32 *min NS_OUTPARAM, PRInt32 *max NS_OUTPARAM); \
  NS_SCRIPTABLE NS_IMETHOD InvalidateSelection(void); \
  NS_SCRIPTABLE NS_IMETHOD AdjustSelection(PRInt32 index, PRInt32 count); \
  NS_SCRIPTABLE NS_IMETHOD GetSelectEventsSuppressed(PRBool *aSelectEventsSuppressed); \
  NS_SCRIPTABLE NS_IMETHOD SetSelectEventsSuppressed(PRBool aSelectEventsSuppressed); \
  NS_SCRIPTABLE NS_IMETHOD GetCurrentIndex(PRInt32 *aCurrentIndex); \
  NS_SCRIPTABLE NS_IMETHOD SetCurrentIndex(PRInt32 aCurrentIndex); \
  NS_SCRIPTABLE NS_IMETHOD GetCurrentColumn(nsITreeColumn * *aCurrentColumn); \
  NS_SCRIPTABLE NS_IMETHOD SetCurrentColumn(nsITreeColumn * aCurrentColumn); \
  NS_SCRIPTABLE NS_IMETHOD GetShiftSelectPivot(PRInt32 *aShiftSelectPivot); 

/* Use this macro to declare functions that forward the behavior of this interface to another object. */
#define NS_FORWARD_NSITREESELECTION(_to) \
  NS_SCRIPTABLE NS_IMETHOD GetTree(nsITreeBoxObject * *aTree) { return _to GetTree(aTree); } \
  NS_SCRIPTABLE NS_IMETHOD SetTree(nsITreeBoxObject * aTree) { return _to SetTree(aTree); } \
  NS_SCRIPTABLE NS_IMETHOD GetSingle(PRBool *aSingle) { return _to GetSingle(aSingle); } \
  NS_SCRIPTABLE NS_IMETHOD GetCount(PRInt32 *aCount) { return _to GetCount(aCount); } \
  NS_SCRIPTABLE NS_IMETHOD IsSelected(PRInt32 index, PRBool *_retval NS_OUTPARAM) { return _to IsSelected(index, _retval); } \
  NS_SCRIPTABLE NS_IMETHOD Select(PRInt32 index) { return _to Select(index); } \
  NS_SCRIPTABLE NS_IMETHOD TimedSelect(PRInt32 index, PRInt32 delay) { return _to TimedSelect(index, delay); } \
  NS_SCRIPTABLE NS_IMETHOD ToggleSelect(PRInt32 index) { return _to ToggleSelect(index); } \
  NS_SCRIPTABLE NS_IMETHOD RangedSelect(PRInt32 startIndex, PRInt32 endIndex, PRBool augment) { return _to RangedSelect(startIndex, endIndex, augment); } \
  NS_SCRIPTABLE NS_IMETHOD ClearRange(PRInt32 startIndex, PRInt32 endIndex) { return _to ClearRange(startIndex, endIndex); } \
  NS_SCRIPTABLE NS_IMETHOD ClearSelection(void) { return _to ClearSelection(); } \
  NS_SCRIPTABLE NS_IMETHOD InvertSelection(void) { return _to InvertSelection(); } \
  NS_SCRIPTABLE NS_IMETHOD SelectAll(void) { return _to SelectAll(); } \
  NS_SCRIPTABLE NS_IMETHOD GetRangeCount(PRInt32 *_retval NS_OUTPARAM) { return _to GetRangeCount(_retval); } \
  NS_SCRIPTABLE NS_IMETHOD GetRangeAt(PRInt32 i, PRInt32 *min NS_OUTPARAM, PRInt32 *max NS_OUTPARAM) { return _to GetRangeAt(i, min, max); } \
  NS_SCRIPTABLE NS_IMETHOD InvalidateSelection(void) { return _to InvalidateSelection(); } \
  NS_SCRIPTABLE NS_IMETHOD AdjustSelection(PRInt32 index, PRInt32 count) { return _to AdjustSelection(index, count); } \
  NS_SCRIPTABLE NS_IMETHOD GetSelectEventsSuppressed(PRBool *aSelectEventsSuppressed) { return _to GetSelectEventsSuppressed(aSelectEventsSuppressed); } \
  NS_SCRIPTABLE NS_IMETHOD SetSelectEventsSuppressed(PRBool aSelectEventsSuppressed) { return _to SetSelectEventsSuppressed(aSelectEventsSuppressed); } \
  NS_SCRIPTABLE NS_IMETHOD GetCurrentIndex(PRInt32 *aCurrentIndex) { return _to GetCurrentIndex(aCurrentIndex); } \
  NS_SCRIPTABLE NS_IMETHOD SetCurrentIndex(PRInt32 aCurrentIndex) { return _to SetCurrentIndex(aCurrentIndex); } \
  NS_SCRIPTABLE NS_IMETHOD GetCurrentColumn(nsITreeColumn * *aCurrentColumn) { return _to GetCurrentColumn(aCurrentColumn); } \
  NS_SCRIPTABLE NS_IMETHOD SetCurrentColumn(nsITreeColumn * aCurrentColumn) { return _to SetCurrentColumn(aCurrentColumn); } \
  NS_SCRIPTABLE NS_IMETHOD GetShiftSelectPivot(PRInt32 *aShiftSelectPivot) { return _to GetShiftSelectPivot(aShiftSelectPivot); } 

/* Use this macro to declare functions that forward the behavior of this interface to another object in a safe way. */
#define NS_FORWARD_SAFE_NSITREESELECTION(_to) \
  NS_SCRIPTABLE NS_IMETHOD GetTree(nsITreeBoxObject * *aTree) { return !_to ? NS_ERROR_NULL_POINTER : _to->GetTree(aTree); } \
  NS_SCRIPTABLE NS_IMETHOD SetTree(nsITreeBoxObject * aTree) { return !_to ? NS_ERROR_NULL_POINTER : _to->SetTree(aTree); } \
  NS_SCRIPTABLE NS_IMETHOD GetSingle(PRBool *aSingle) { return !_to ? NS_ERROR_NULL_POINTER : _to->GetSingle(aSingle); } \
  NS_SCRIPTABLE NS_IMETHOD GetCount(PRInt32 *aCount) { return !_to ? NS_ERROR_NULL_POINTER : _to->GetCount(aCount); } \
  NS_SCRIPTABLE NS_IMETHOD IsSelected(PRInt32 index, PRBool *_retval NS_OUTPARAM) { return !_to ? NS_ERROR_NULL_POINTER : _to->IsSelected(index, _retval); } \
  NS_SCRIPTABLE NS_IMETHOD Select(PRInt32 index) { return !_to ? NS_ERROR_NULL_POINTER : _to->Select(index); } \
  NS_SCRIPTABLE NS_IMETHOD TimedSelect(PRInt32 index, PRInt32 delay) { return !_to ? NS_ERROR_NULL_POINTER : _to->TimedSelect(index, delay); } \
  NS_SCRIPTABLE NS_IMETHOD ToggleSelect(PRInt32 index) { return !_to ? NS_ERROR_NULL_POINTER : _to->ToggleSelect(index); } \
  NS_SCRIPTABLE NS_IMETHOD RangedSelect(PRInt32 startIndex, PRInt32 endIndex, PRBool augment) { return !_to ? NS_ERROR_NULL_POINTER : _to->RangedSelect(startIndex, endIndex, augment); } \
  NS_SCRIPTABLE NS_IMETHOD ClearRange(PRInt32 startIndex, PRInt32 endIndex) { return !_to ? NS_ERROR_NULL_POINTER : _to->ClearRange(startIndex, endIndex); } \
  NS_SCRIPTABLE NS_IMETHOD ClearSelection(void) { return !_to ? NS_ERROR_NULL_POINTER : _to->ClearSelection(); } \
  NS_SCRIPTABLE NS_IMETHOD InvertSelection(void) { return !_to ? NS_ERROR_NULL_POINTER : _to->InvertSelection(); } \
  NS_SCRIPTABLE NS_IMETHOD SelectAll(void) { return !_to ? NS_ERROR_NULL_POINTER : _to->SelectAll(); } \
  NS_SCRIPTABLE NS_IMETHOD GetRangeCount(PRInt32 *_retval NS_OUTPARAM) { return !_to ? NS_ERROR_NULL_POINTER : _to->GetRangeCount(_retval); } \
  NS_SCRIPTABLE NS_IMETHOD GetRangeAt(PRInt32 i, PRInt32 *min NS_OUTPARAM, PRInt32 *max NS_OUTPARAM) { return !_to ? NS_ERROR_NULL_POINTER : _to->GetRangeAt(i, min, max); } \
  NS_SCRIPTABLE NS_IMETHOD InvalidateSelection(void) { return !_to ? NS_ERROR_NULL_POINTER : _to->InvalidateSelection(); } \
  NS_SCRIPTABLE NS_IMETHOD AdjustSelection(PRInt32 index, PRInt32 count) { return !_to ? NS_ERROR_NULL_POINTER : _to->AdjustSelection(index, count); } \
  NS_SCRIPTABLE NS_IMETHOD GetSelectEventsSuppressed(PRBool *aSelectEventsSuppressed) { return !_to ? NS_ERROR_NULL_POINTER : _to->GetSelectEventsSuppressed(aSelectEventsSuppressed); } \
  NS_SCRIPTABLE NS_IMETHOD SetSelectEventsSuppressed(PRBool aSelectEventsSuppressed) { return !_to ? NS_ERROR_NULL_POINTER : _to->SetSelectEventsSuppressed(aSelectEventsSuppressed); } \
  NS_SCRIPTABLE NS_IMETHOD GetCurrentIndex(PRInt32 *aCurrentIndex) { return !_to ? NS_ERROR_NULL_POINTER : _to->GetCurrentIndex(aCurrentIndex); } \
  NS_SCRIPTABLE NS_IMETHOD SetCurrentIndex(PRInt32 aCurrentIndex) { return !_to ? NS_ERROR_NULL_POINTER : _to->SetCurrentIndex(aCurrentIndex); } \
  NS_SCRIPTABLE NS_IMETHOD GetCurrentColumn(nsITreeColumn * *aCurrentColumn) { return !_to ? NS_ERROR_NULL_POINTER : _to->GetCurrentColumn(aCurrentColumn); } \
  NS_SCRIPTABLE NS_IMETHOD SetCurrentColumn(nsITreeColumn * aCurrentColumn) { return !_to ? NS_ERROR_NULL_POINTER : _to->SetCurrentColumn(aCurrentColumn); } \
  NS_SCRIPTABLE NS_IMETHOD GetShiftSelectPivot(PRInt32 *aShiftSelectPivot) { return !_to ? NS_ERROR_NULL_POINTER : _to->GetShiftSelectPivot(aShiftSelectPivot); } 

#if 0
/* Use the code below as a template for the implementation class for this interface. */

/* Header file */
class nsTreeSelection : public nsITreeSelection
{
public:
  NS_DECL_ISUPPORTS
  NS_DECL_NSITREESELECTION

  nsTreeSelection();

private:
  ~nsTreeSelection();

protected:
  /* additional members */
};

/* Implementation file */
NS_IMPL_ISUPPORTS1(nsTreeSelection, nsITreeSelection)

nsTreeSelection::nsTreeSelection()
{
  /* member initializers and constructor code */
}

nsTreeSelection::~nsTreeSelection()
{
  /* destructor code */
}

/* attribute nsITreeBoxObject tree; */
NS_IMETHODIMP nsTreeSelection::GetTree(nsITreeBoxObject * *aTree)
{
    return NS_ERROR_NOT_IMPLEMENTED;
}
NS_IMETHODIMP nsTreeSelection::SetTree(nsITreeBoxObject * aTree)
{
    return NS_ERROR_NOT_IMPLEMENTED;
}

/* readonly attribute boolean single; */
NS_IMETHODIMP nsTreeSelection::GetSingle(PRBool *aSingle)
{
    return NS_ERROR_NOT_IMPLEMENTED;
}

/* readonly attribute long count; */
NS_IMETHODIMP nsTreeSelection::GetCount(PRInt32 *aCount)
{
    return NS_ERROR_NOT_IMPLEMENTED;
}

/* boolean isSelected (in long index); */
NS_IMETHODIMP nsTreeSelection::IsSelected(PRInt32 index, PRBool *_retval NS_OUTPARAM)
{
    return NS_ERROR_NOT_IMPLEMENTED;
}

/* void select (in long index); */
NS_IMETHODIMP nsTreeSelection::Select(PRInt32 index)
{
    return NS_ERROR_NOT_IMPLEMENTED;
}

/* void timedSelect (in long index, in long delay); */
NS_IMETHODIMP nsTreeSelection::TimedSelect(PRInt32 index, PRInt32 delay)
{
    return NS_ERROR_NOT_IMPLEMENTED;
}

/* void toggleSelect (in long index); */
NS_IMETHODIMP nsTreeSelection::ToggleSelect(PRInt32 index)
{
    return NS_ERROR_NOT_IMPLEMENTED;
}

/* void rangedSelect (in long startIndex, in long endIndex, in boolean augment); */
NS_IMETHODIMP nsTreeSelection::RangedSelect(PRInt32 startIndex, PRInt32 endIndex, PRBool augment)
{
    return NS_ERROR_NOT_IMPLEMENTED;
}

/* void clearRange (in long startIndex, in long endIndex); */
NS_IMETHODIMP nsTreeSelection::ClearRange(PRInt32 startIndex, PRInt32 endIndex)
{
    return NS_ERROR_NOT_IMPLEMENTED;
}

/* void clearSelection (); */
NS_IMETHODIMP nsTreeSelection::ClearSelection()
{
    return NS_ERROR_NOT_IMPLEMENTED;
}

/* void invertSelection (); */
NS_IMETHODIMP nsTreeSelection::InvertSelection()
{
    return NS_ERROR_NOT_IMPLEMENTED;
}

/* void selectAll (); */
NS_IMETHODIMP nsTreeSelection::SelectAll()
{
    return NS_ERROR_NOT_IMPLEMENTED;
}

/* long getRangeCount (); */
NS_IMETHODIMP nsTreeSelection::GetRangeCount(PRInt32 *_retval NS_OUTPARAM)
{
    return NS_ERROR_NOT_IMPLEMENTED;
}

/* void getRangeAt (in long i, out long min, out long max); */
NS_IMETHODIMP nsTreeSelection::GetRangeAt(PRInt32 i, PRInt32 *min NS_OUTPARAM, PRInt32 *max NS_OUTPARAM)
{
    return NS_ERROR_NOT_IMPLEMENTED;
}

/* void invalidateSelection (); */
NS_IMETHODIMP nsTreeSelection::InvalidateSelection()
{
    return NS_ERROR_NOT_IMPLEMENTED;
}

/* void adjustSelection (in long index, in long count); */
NS_IMETHODIMP nsTreeSelection::AdjustSelection(PRInt32 index, PRInt32 count)
{
    return NS_ERROR_NOT_IMPLEMENTED;
}

/* attribute boolean selectEventsSuppressed; */
NS_IMETHODIMP nsTreeSelection::GetSelectEventsSuppressed(PRBool *aSelectEventsSuppressed)
{
    return NS_ERROR_NOT_IMPLEMENTED;
}
NS_IMETHODIMP nsTreeSelection::SetSelectEventsSuppressed(PRBool aSelectEventsSuppressed)
{
    return NS_ERROR_NOT_IMPLEMENTED;
}

/* attribute long currentIndex; */
NS_IMETHODIMP nsTreeSelection::GetCurrentIndex(PRInt32 *aCurrentIndex)
{
    return NS_ERROR_NOT_IMPLEMENTED;
}
NS_IMETHODIMP nsTreeSelection::SetCurrentIndex(PRInt32 aCurrentIndex)
{
    return NS_ERROR_NOT_IMPLEMENTED;
}

/* attribute nsITreeColumn currentColumn; */
NS_IMETHODIMP nsTreeSelection::GetCurrentColumn(nsITreeColumn * *aCurrentColumn)
{
    return NS_ERROR_NOT_IMPLEMENTED;
}
NS_IMETHODIMP nsTreeSelection::SetCurrentColumn(nsITreeColumn * aCurrentColumn)
{
    return NS_ERROR_NOT_IMPLEMENTED;
}

/* readonly attribute long shiftSelectPivot; */
NS_IMETHODIMP nsTreeSelection::GetShiftSelectPivot(PRInt32 *aShiftSelectPivot)
{
    return NS_ERROR_NOT_IMPLEMENTED;
}

/* End of implementation class template. */
#endif


#endif /* __gen_nsITreeSelection_h__ */
