/*
 * DO NOT EDIT.  THIS FILE IS GENERATED FROM e:/builds/moz2_slave/mozilla-1.9.1-win32-xulrunner/build/layout/xul/base/src/tree/public/nsITreeBoxObject.idl
 */

#ifndef __gen_nsITreeBoxObject_h__
#define __gen_nsITreeBoxObject_h__


#ifndef __gen_nsISupports_h__
#include "nsISupports.h"
#endif

#ifndef __gen_domstubs_h__
#include "domstubs.h"
#endif

/* For IDL files that don't want to include root IDL files. */
#ifndef NS_NO_VTABLE
#define NS_NO_VTABLE
#endif
class nsITreeView; /* forward declaration */

class nsITreeSelection; /* forward declaration */

class nsITreeColumn; /* forward declaration */

class nsITreeColumns; /* forward declaration */

class nsIScriptableRegion; /* forward declaration */


/* starting interface:    nsITreeBoxObject */
#define NS_ITREEBOXOBJECT_IID_STR "64ba5199-c4f4-4498-bbdc-f8e4c369086c"

#define NS_ITREEBOXOBJECT_IID \
  {0x64ba5199, 0xc4f4, 0x4498, \
    { 0xbb, 0xdc, 0xf8, 0xe4, 0xc3, 0x69, 0x08, 0x6c }}

class NS_NO_VTABLE NS_SCRIPTABLE nsITreeBoxObject : public nsISupports {
 public: 

  NS_DECLARE_STATIC_IID_ACCESSOR(NS_ITREEBOXOBJECT_IID)

  /**
   * Obtain the columns.
   */
  /* readonly attribute nsITreeColumns columns; */
  NS_SCRIPTABLE NS_IMETHOD GetColumns(nsITreeColumns * *aColumns) = 0;

  /**
   * The view that backs the tree and that supplies it with its data.
   * It is dynamically settable, either using a view attribute on the
   * tree tag or by setting this attribute to a new value.
   */
  /* attribute nsITreeView view; */
  NS_SCRIPTABLE NS_IMETHOD GetView(nsITreeView * *aView) = 0;
  NS_SCRIPTABLE NS_IMETHOD SetView(nsITreeView * aView) = 0;

  /**
   * Whether or not we are currently focused.
   */
  /* attribute boolean focused; */
  NS_SCRIPTABLE NS_IMETHOD GetFocused(PRBool *aFocused) = 0;
  NS_SCRIPTABLE NS_IMETHOD SetFocused(PRBool aFocused) = 0;

  /**
   * Obtain the treebody content node
   */
  /* readonly attribute nsIDOMElement treeBody; */
  NS_SCRIPTABLE NS_IMETHOD GetTreeBody(nsIDOMElement * *aTreeBody) = 0;

  /**
   * Obtain the height of a row.
   */
  /* readonly attribute long rowHeight; */
  NS_SCRIPTABLE NS_IMETHOD GetRowHeight(PRInt32 *aRowHeight) = 0;

  /**
   * Obtain the width of a row.
   */
  /* readonly attribute long rowWidth; */
  NS_SCRIPTABLE NS_IMETHOD GetRowWidth(PRInt32 *aRowWidth) = 0;

  /**
   * Get the pixel position of the horizontal scrollbar. 
   */
  /* readonly attribute long horizontalPosition; */
  NS_SCRIPTABLE NS_IMETHOD GetHorizontalPosition(PRInt32 *aHorizontalPosition) = 0;

  /**
   * Return the region for the visible parts of the selection, in device pixels.
   */
  /* readonly attribute nsIScriptableRegion selectionRegion; */
  NS_SCRIPTABLE NS_IMETHOD GetSelectionRegion(nsIScriptableRegion * *aSelectionRegion) = 0;

  /**
   * Get the index of the first visible row.
   */
  /* long getFirstVisibleRow (); */
  NS_SCRIPTABLE NS_IMETHOD GetFirstVisibleRow(PRInt32 *_retval NS_OUTPARAM) = 0;

  /**
   * Get the index of the last visible row.
   */
  /* long getLastVisibleRow (); */
  NS_SCRIPTABLE NS_IMETHOD GetLastVisibleRow(PRInt32 *_retval NS_OUTPARAM) = 0;

  /**
   * Gets the number of possible visible rows.
   */
  /* long getPageLength (); */
  NS_SCRIPTABLE NS_IMETHOD GetPageLength(PRInt32 *_retval NS_OUTPARAM) = 0;

  /**
   * Ensures that a row at a given index is visible.
   */
  /* void ensureRowIsVisible (in long index); */
  NS_SCRIPTABLE NS_IMETHOD EnsureRowIsVisible(PRInt32 index) = 0;

  /**
   * Ensures that a given cell in the tree is visible.
   */
  /* void ensureCellIsVisible (in long row, in nsITreeColumn col); */
  NS_SCRIPTABLE NS_IMETHOD EnsureCellIsVisible(PRInt32 row, nsITreeColumn *col) = 0;

  /**
   * Scrolls such that the row at index is at the top of the visible view.
   */
  /* void scrollToRow (in long index); */
  NS_SCRIPTABLE NS_IMETHOD ScrollToRow(PRInt32 index) = 0;

  /**
   * Scroll the tree up or down by numLines lines. Positive
   * values move down in the tree. Prevents scrolling off the
   * end of the tree. 
   */
  /* void scrollByLines (in long numLines); */
  NS_SCRIPTABLE NS_IMETHOD ScrollByLines(PRInt32 numLines) = 0;

  /**
   * Scroll the tree up or down by numPages pages. A page
   * is considered to be the amount displayed by the tree.
   * Positive values move down in the tree. Prevents scrolling
   * off the end of the tree.
   */
  /* void scrollByPages (in long numPages); */
  NS_SCRIPTABLE NS_IMETHOD ScrollByPages(PRInt32 numPages) = 0;

  /**
   * Scrolls such that a given cell is visible (if possible) 
   * at the top left corner of the visible view. 
   */
  /* void scrollToCell (in long row, in nsITreeColumn col); */
  NS_SCRIPTABLE NS_IMETHOD ScrollToCell(PRInt32 row, nsITreeColumn *col) = 0;

  /**
   * Scrolls horizontally so that the specified column is 
   * at the left of the view (if possible).
   */
  /* void scrollToColumn (in nsITreeColumn col); */
  NS_SCRIPTABLE NS_IMETHOD ScrollToColumn(nsITreeColumn *col) = 0;

  /**
   * Scroll to a specific horizontal pixel position.
   */
  /* void scrollToHorizontalPosition (in long horizontalPosition); */
  NS_SCRIPTABLE NS_IMETHOD ScrollToHorizontalPosition(PRInt32 horizontalPosition) = 0;

  /**
   * Invalidation methods for fine-grained painting control.
   */
  /* void invalidate (); */
  NS_SCRIPTABLE NS_IMETHOD Invalidate(void) = 0;

  /* void invalidateColumn (in nsITreeColumn col); */
  NS_SCRIPTABLE NS_IMETHOD InvalidateColumn(nsITreeColumn *col) = 0;

  /* void invalidateRow (in long index); */
  NS_SCRIPTABLE NS_IMETHOD InvalidateRow(PRInt32 index) = 0;

  /* void invalidateCell (in long row, in nsITreeColumn col); */
  NS_SCRIPTABLE NS_IMETHOD InvalidateCell(PRInt32 row, nsITreeColumn *col) = 0;

  /* void invalidateRange (in long startIndex, in long endIndex); */
  NS_SCRIPTABLE NS_IMETHOD InvalidateRange(PRInt32 startIndex, PRInt32 endIndex) = 0;

  /* void invalidateColumnRange (in long startIndex, in long endIndex, in nsITreeColumn col); */
  NS_SCRIPTABLE NS_IMETHOD InvalidateColumnRange(PRInt32 startIndex, PRInt32 endIndex, nsITreeColumn *col) = 0;

  /**
   * A hit test that can tell you what row the mouse is over.
   * returns -1 for invalid mouse coordinates.
   *
   * The coordinate system is the client coordinate system for the
   * document this boxObject lives in, and the units are CSS pixels.
   */
  /* long getRowAt (in long x, in long y); */
  NS_SCRIPTABLE NS_IMETHOD GetRowAt(PRInt32 x, PRInt32 y, PRInt32 *_retval NS_OUTPARAM) = 0;

  /**
   * A hit test that can tell you what cell the mouse is over.  Row is the row index
   * hit,  returns -1 for invalid mouse coordinates.  ColID is the column hit.
   * ChildElt is the pseudoelement hit: this can have values of
   * "cell", "twisty", "image", and "text".
   *
   * The coordinate system is the client coordinate system for the
   * document this boxObject lives in, and the units are CSS pixels.
   */
  /* void getCellAt (in long x, in long y, out long row, out nsITreeColumn col, out ACString childElt); */
  NS_SCRIPTABLE NS_IMETHOD GetCellAt(PRInt32 x, PRInt32 y, PRInt32 *row NS_OUTPARAM, nsITreeColumn **col NS_OUTPARAM, nsACString & childElt NS_OUTPARAM) = 0;

  /** 
   * Find the coordinates of an element within a specific cell. 
   */
  /* void getCoordsForCellItem (in long row, in nsITreeColumn col, in ACString element, out long x, out long y, out long width, out long height); */
  NS_SCRIPTABLE NS_IMETHOD GetCoordsForCellItem(PRInt32 row, nsITreeColumn *col, const nsACString & element, PRInt32 *x NS_OUTPARAM, PRInt32 *y NS_OUTPARAM, PRInt32 *width NS_OUTPARAM, PRInt32 *height NS_OUTPARAM) = 0;

  /** 
   * Determine if the text of a cell is being cropped or not.
   */
  /* boolean isCellCropped (in long row, in nsITreeColumn col); */
  NS_SCRIPTABLE NS_IMETHOD IsCellCropped(PRInt32 row, nsITreeColumn *col, PRBool *_retval NS_OUTPARAM) = 0;

  /**
   * The view is responsible for calling these notification methods when
   * rows are added or removed.  Index is the position at which the new
   * rows were added or at which rows were removed.  For
   * non-contiguous additions/removals, this method should be called multiple times.
   */
  /* void rowCountChanged (in long index, in long count); */
  NS_SCRIPTABLE NS_IMETHOD RowCountChanged(PRInt32 index, PRInt32 count) = 0;

  /**
   * Notify the tree that the view is about to perform a batch
   * update, that is, add, remove or invalidate several rows at once.
   * This must be followed by calling endUpdateBatch(), otherwise the tree
   * will get out of sync.
   */
  /* void beginUpdateBatch (); */
  NS_SCRIPTABLE NS_IMETHOD BeginUpdateBatch(void) = 0;

  /**
   * Notify the tree that the view has completed a batch update.
   */
  /* void endUpdateBatch (); */
  NS_SCRIPTABLE NS_IMETHOD EndUpdateBatch(void) = 0;

  /**
   * Called on a theme switch to flush out the tree's style and image caches.
   */
  /* void clearStyleAndImageCaches (); */
  NS_SCRIPTABLE NS_IMETHOD ClearStyleAndImageCaches(void) = 0;

};

  NS_DEFINE_STATIC_IID_ACCESSOR(nsITreeBoxObject, NS_ITREEBOXOBJECT_IID)

/* Use this macro when declaring classes that implement this interface. */
#define NS_DECL_NSITREEBOXOBJECT \
  NS_SCRIPTABLE NS_IMETHOD GetColumns(nsITreeColumns * *aColumns); \
  NS_SCRIPTABLE NS_IMETHOD GetView(nsITreeView * *aView); \
  NS_SCRIPTABLE NS_IMETHOD SetView(nsITreeView * aView); \
  NS_SCRIPTABLE NS_IMETHOD GetFocused(PRBool *aFocused); \
  NS_SCRIPTABLE NS_IMETHOD SetFocused(PRBool aFocused); \
  NS_SCRIPTABLE NS_IMETHOD GetTreeBody(nsIDOMElement * *aTreeBody); \
  NS_SCRIPTABLE NS_IMETHOD GetRowHeight(PRInt32 *aRowHeight); \
  NS_SCRIPTABLE NS_IMETHOD GetRowWidth(PRInt32 *aRowWidth); \
  NS_SCRIPTABLE NS_IMETHOD GetHorizontalPosition(PRInt32 *aHorizontalPosition); \
  NS_SCRIPTABLE NS_IMETHOD GetSelectionRegion(nsIScriptableRegion * *aSelectionRegion); \
  NS_SCRIPTABLE NS_IMETHOD GetFirstVisibleRow(PRInt32 *_retval NS_OUTPARAM); \
  NS_SCRIPTABLE NS_IMETHOD GetLastVisibleRow(PRInt32 *_retval NS_OUTPARAM); \
  NS_SCRIPTABLE NS_IMETHOD GetPageLength(PRInt32 *_retval NS_OUTPARAM); \
  NS_SCRIPTABLE NS_IMETHOD EnsureRowIsVisible(PRInt32 index); \
  NS_SCRIPTABLE NS_IMETHOD EnsureCellIsVisible(PRInt32 row, nsITreeColumn *col); \
  NS_SCRIPTABLE NS_IMETHOD ScrollToRow(PRInt32 index); \
  NS_SCRIPTABLE NS_IMETHOD ScrollByLines(PRInt32 numLines); \
  NS_SCRIPTABLE NS_IMETHOD ScrollByPages(PRInt32 numPages); \
  NS_SCRIPTABLE NS_IMETHOD ScrollToCell(PRInt32 row, nsITreeColumn *col); \
  NS_SCRIPTABLE NS_IMETHOD ScrollToColumn(nsITreeColumn *col); \
  NS_SCRIPTABLE NS_IMETHOD ScrollToHorizontalPosition(PRInt32 horizontalPosition); \
  NS_SCRIPTABLE NS_IMETHOD Invalidate(void); \
  NS_SCRIPTABLE NS_IMETHOD InvalidateColumn(nsITreeColumn *col); \
  NS_SCRIPTABLE NS_IMETHOD InvalidateRow(PRInt32 index); \
  NS_SCRIPTABLE NS_IMETHOD InvalidateCell(PRInt32 row, nsITreeColumn *col); \
  NS_SCRIPTABLE NS_IMETHOD InvalidateRange(PRInt32 startIndex, PRInt32 endIndex); \
  NS_SCRIPTABLE NS_IMETHOD InvalidateColumnRange(PRInt32 startIndex, PRInt32 endIndex, nsITreeColumn *col); \
  NS_SCRIPTABLE NS_IMETHOD GetRowAt(PRInt32 x, PRInt32 y, PRInt32 *_retval NS_OUTPARAM); \
  NS_SCRIPTABLE NS_IMETHOD GetCellAt(PRInt32 x, PRInt32 y, PRInt32 *row NS_OUTPARAM, nsITreeColumn **col NS_OUTPARAM, nsACString & childElt NS_OUTPARAM); \
  NS_SCRIPTABLE NS_IMETHOD GetCoordsForCellItem(PRInt32 row, nsITreeColumn *col, const nsACString & element, PRInt32 *x NS_OUTPARAM, PRInt32 *y NS_OUTPARAM, PRInt32 *width NS_OUTPARAM, PRInt32 *height NS_OUTPARAM); \
  NS_SCRIPTABLE NS_IMETHOD IsCellCropped(PRInt32 row, nsITreeColumn *col, PRBool *_retval NS_OUTPARAM); \
  NS_SCRIPTABLE NS_IMETHOD RowCountChanged(PRInt32 index, PRInt32 count); \
  NS_SCRIPTABLE NS_IMETHOD BeginUpdateBatch(void); \
  NS_SCRIPTABLE NS_IMETHOD EndUpdateBatch(void); \
  NS_SCRIPTABLE NS_IMETHOD ClearStyleAndImageCaches(void); 

/* Use this macro to declare functions that forward the behavior of this interface to another object. */
#define NS_FORWARD_NSITREEBOXOBJECT(_to) \
  NS_SCRIPTABLE NS_IMETHOD GetColumns(nsITreeColumns * *aColumns) { return _to GetColumns(aColumns); } \
  NS_SCRIPTABLE NS_IMETHOD GetView(nsITreeView * *aView) { return _to GetView(aView); } \
  NS_SCRIPTABLE NS_IMETHOD SetView(nsITreeView * aView) { return _to SetView(aView); } \
  NS_SCRIPTABLE NS_IMETHOD GetFocused(PRBool *aFocused) { return _to GetFocused(aFocused); } \
  NS_SCRIPTABLE NS_IMETHOD SetFocused(PRBool aFocused) { return _to SetFocused(aFocused); } \
  NS_SCRIPTABLE NS_IMETHOD GetTreeBody(nsIDOMElement * *aTreeBody) { return _to GetTreeBody(aTreeBody); } \
  NS_SCRIPTABLE NS_IMETHOD GetRowHeight(PRInt32 *aRowHeight) { return _to GetRowHeight(aRowHeight); } \
  NS_SCRIPTABLE NS_IMETHOD GetRowWidth(PRInt32 *aRowWidth) { return _to GetRowWidth(aRowWidth); } \
  NS_SCRIPTABLE NS_IMETHOD GetHorizontalPosition(PRInt32 *aHorizontalPosition) { return _to GetHorizontalPosition(aHorizontalPosition); } \
  NS_SCRIPTABLE NS_IMETHOD GetSelectionRegion(nsIScriptableRegion * *aSelectionRegion) { return _to GetSelectionRegion(aSelectionRegion); } \
  NS_SCRIPTABLE NS_IMETHOD GetFirstVisibleRow(PRInt32 *_retval NS_OUTPARAM) { return _to GetFirstVisibleRow(_retval); } \
  NS_SCRIPTABLE NS_IMETHOD GetLastVisibleRow(PRInt32 *_retval NS_OUTPARAM) { return _to GetLastVisibleRow(_retval); } \
  NS_SCRIPTABLE NS_IMETHOD GetPageLength(PRInt32 *_retval NS_OUTPARAM) { return _to GetPageLength(_retval); } \
  NS_SCRIPTABLE NS_IMETHOD EnsureRowIsVisible(PRInt32 index) { return _to EnsureRowIsVisible(index); } \
  NS_SCRIPTABLE NS_IMETHOD EnsureCellIsVisible(PRInt32 row, nsITreeColumn *col) { return _to EnsureCellIsVisible(row, col); } \
  NS_SCRIPTABLE NS_IMETHOD ScrollToRow(PRInt32 index) { return _to ScrollToRow(index); } \
  NS_SCRIPTABLE NS_IMETHOD ScrollByLines(PRInt32 numLines) { return _to ScrollByLines(numLines); } \
  NS_SCRIPTABLE NS_IMETHOD ScrollByPages(PRInt32 numPages) { return _to ScrollByPages(numPages); } \
  NS_SCRIPTABLE NS_IMETHOD ScrollToCell(PRInt32 row, nsITreeColumn *col) { return _to ScrollToCell(row, col); } \
  NS_SCRIPTABLE NS_IMETHOD ScrollToColumn(nsITreeColumn *col) { return _to ScrollToColumn(col); } \
  NS_SCRIPTABLE NS_IMETHOD ScrollToHorizontalPosition(PRInt32 horizontalPosition) { return _to ScrollToHorizontalPosition(horizontalPosition); } \
  NS_SCRIPTABLE NS_IMETHOD Invalidate(void) { return _to Invalidate(); } \
  NS_SCRIPTABLE NS_IMETHOD InvalidateColumn(nsITreeColumn *col) { return _to InvalidateColumn(col); } \
  NS_SCRIPTABLE NS_IMETHOD InvalidateRow(PRInt32 index) { return _to InvalidateRow(index); } \
  NS_SCRIPTABLE NS_IMETHOD InvalidateCell(PRInt32 row, nsITreeColumn *col) { return _to InvalidateCell(row, col); } \
  NS_SCRIPTABLE NS_IMETHOD InvalidateRange(PRInt32 startIndex, PRInt32 endIndex) { return _to InvalidateRange(startIndex, endIndex); } \
  NS_SCRIPTABLE NS_IMETHOD InvalidateColumnRange(PRInt32 startIndex, PRInt32 endIndex, nsITreeColumn *col) { return _to InvalidateColumnRange(startIndex, endIndex, col); } \
  NS_SCRIPTABLE NS_IMETHOD GetRowAt(PRInt32 x, PRInt32 y, PRInt32 *_retval NS_OUTPARAM) { return _to GetRowAt(x, y, _retval); } \
  NS_SCRIPTABLE NS_IMETHOD GetCellAt(PRInt32 x, PRInt32 y, PRInt32 *row NS_OUTPARAM, nsITreeColumn **col NS_OUTPARAM, nsACString & childElt NS_OUTPARAM) { return _to GetCellAt(x, y, row, col, childElt); } \
  NS_SCRIPTABLE NS_IMETHOD GetCoordsForCellItem(PRInt32 row, nsITreeColumn *col, const nsACString & element, PRInt32 *x NS_OUTPARAM, PRInt32 *y NS_OUTPARAM, PRInt32 *width NS_OUTPARAM, PRInt32 *height NS_OUTPARAM) { return _to GetCoordsForCellItem(row, col, element, x, y, width, height); } \
  NS_SCRIPTABLE NS_IMETHOD IsCellCropped(PRInt32 row, nsITreeColumn *col, PRBool *_retval NS_OUTPARAM) { return _to IsCellCropped(row, col, _retval); } \
  NS_SCRIPTABLE NS_IMETHOD RowCountChanged(PRInt32 index, PRInt32 count) { return _to RowCountChanged(index, count); } \
  NS_SCRIPTABLE NS_IMETHOD BeginUpdateBatch(void) { return _to BeginUpdateBatch(); } \
  NS_SCRIPTABLE NS_IMETHOD EndUpdateBatch(void) { return _to EndUpdateBatch(); } \
  NS_SCRIPTABLE NS_IMETHOD ClearStyleAndImageCaches(void) { return _to ClearStyleAndImageCaches(); } 

/* Use this macro to declare functions that forward the behavior of this interface to another object in a safe way. */
#define NS_FORWARD_SAFE_NSITREEBOXOBJECT(_to) \
  NS_SCRIPTABLE NS_IMETHOD GetColumns(nsITreeColumns * *aColumns) { return !_to ? NS_ERROR_NULL_POINTER : _to->GetColumns(aColumns); } \
  NS_SCRIPTABLE NS_IMETHOD GetView(nsITreeView * *aView) { return !_to ? NS_ERROR_NULL_POINTER : _to->GetView(aView); } \
  NS_SCRIPTABLE NS_IMETHOD SetView(nsITreeView * aView) { return !_to ? NS_ERROR_NULL_POINTER : _to->SetView(aView); } \
  NS_SCRIPTABLE NS_IMETHOD GetFocused(PRBool *aFocused) { return !_to ? NS_ERROR_NULL_POINTER : _to->GetFocused(aFocused); } \
  NS_SCRIPTABLE NS_IMETHOD SetFocused(PRBool aFocused) { return !_to ? NS_ERROR_NULL_POINTER : _to->SetFocused(aFocused); } \
  NS_SCRIPTABLE NS_IMETHOD GetTreeBody(nsIDOMElement * *aTreeBody) { return !_to ? NS_ERROR_NULL_POINTER : _to->GetTreeBody(aTreeBody); } \
  NS_SCRIPTABLE NS_IMETHOD GetRowHeight(PRInt32 *aRowHeight) { return !_to ? NS_ERROR_NULL_POINTER : _to->GetRowHeight(aRowHeight); } \
  NS_SCRIPTABLE NS_IMETHOD GetRowWidth(PRInt32 *aRowWidth) { return !_to ? NS_ERROR_NULL_POINTER : _to->GetRowWidth(aRowWidth); } \
  NS_SCRIPTABLE NS_IMETHOD GetHorizontalPosition(PRInt32 *aHorizontalPosition) { return !_to ? NS_ERROR_NULL_POINTER : _to->GetHorizontalPosition(aHorizontalPosition); } \
  NS_SCRIPTABLE NS_IMETHOD GetSelectionRegion(nsIScriptableRegion * *aSelectionRegion) { return !_to ? NS_ERROR_NULL_POINTER : _to->GetSelectionRegion(aSelectionRegion); } \
  NS_SCRIPTABLE NS_IMETHOD GetFirstVisibleRow(PRInt32 *_retval NS_OUTPARAM) { return !_to ? NS_ERROR_NULL_POINTER : _to->GetFirstVisibleRow(_retval); } \
  NS_SCRIPTABLE NS_IMETHOD GetLastVisibleRow(PRInt32 *_retval NS_OUTPARAM) { return !_to ? NS_ERROR_NULL_POINTER : _to->GetLastVisibleRow(_retval); } \
  NS_SCRIPTABLE NS_IMETHOD GetPageLength(PRInt32 *_retval NS_OUTPARAM) { return !_to ? NS_ERROR_NULL_POINTER : _to->GetPageLength(_retval); } \
  NS_SCRIPTABLE NS_IMETHOD EnsureRowIsVisible(PRInt32 index) { return !_to ? NS_ERROR_NULL_POINTER : _to->EnsureRowIsVisible(index); } \
  NS_SCRIPTABLE NS_IMETHOD EnsureCellIsVisible(PRInt32 row, nsITreeColumn *col) { return !_to ? NS_ERROR_NULL_POINTER : _to->EnsureCellIsVisible(row, col); } \
  NS_SCRIPTABLE NS_IMETHOD ScrollToRow(PRInt32 index) { return !_to ? NS_ERROR_NULL_POINTER : _to->ScrollToRow(index); } \
  NS_SCRIPTABLE NS_IMETHOD ScrollByLines(PRInt32 numLines) { return !_to ? NS_ERROR_NULL_POINTER : _to->ScrollByLines(numLines); } \
  NS_SCRIPTABLE NS_IMETHOD ScrollByPages(PRInt32 numPages) { return !_to ? NS_ERROR_NULL_POINTER : _to->ScrollByPages(numPages); } \
  NS_SCRIPTABLE NS_IMETHOD ScrollToCell(PRInt32 row, nsITreeColumn *col) { return !_to ? NS_ERROR_NULL_POINTER : _to->ScrollToCell(row, col); } \
  NS_SCRIPTABLE NS_IMETHOD ScrollToColumn(nsITreeColumn *col) { return !_to ? NS_ERROR_NULL_POINTER : _to->ScrollToColumn(col); } \
  NS_SCRIPTABLE NS_IMETHOD ScrollToHorizontalPosition(PRInt32 horizontalPosition) { return !_to ? NS_ERROR_NULL_POINTER : _to->ScrollToHorizontalPosition(horizontalPosition); } \
  NS_SCRIPTABLE NS_IMETHOD Invalidate(void) { return !_to ? NS_ERROR_NULL_POINTER : _to->Invalidate(); } \
  NS_SCRIPTABLE NS_IMETHOD InvalidateColumn(nsITreeColumn *col) { return !_to ? NS_ERROR_NULL_POINTER : _to->InvalidateColumn(col); } \
  NS_SCRIPTABLE NS_IMETHOD InvalidateRow(PRInt32 index) { return !_to ? NS_ERROR_NULL_POINTER : _to->InvalidateRow(index); } \
  NS_SCRIPTABLE NS_IMETHOD InvalidateCell(PRInt32 row, nsITreeColumn *col) { return !_to ? NS_ERROR_NULL_POINTER : _to->InvalidateCell(row, col); } \
  NS_SCRIPTABLE NS_IMETHOD InvalidateRange(PRInt32 startIndex, PRInt32 endIndex) { return !_to ? NS_ERROR_NULL_POINTER : _to->InvalidateRange(startIndex, endIndex); } \
  NS_SCRIPTABLE NS_IMETHOD InvalidateColumnRange(PRInt32 startIndex, PRInt32 endIndex, nsITreeColumn *col) { return !_to ? NS_ERROR_NULL_POINTER : _to->InvalidateColumnRange(startIndex, endIndex, col); } \
  NS_SCRIPTABLE NS_IMETHOD GetRowAt(PRInt32 x, PRInt32 y, PRInt32 *_retval NS_OUTPARAM) { return !_to ? NS_ERROR_NULL_POINTER : _to->GetRowAt(x, y, _retval); } \
  NS_SCRIPTABLE NS_IMETHOD GetCellAt(PRInt32 x, PRInt32 y, PRInt32 *row NS_OUTPARAM, nsITreeColumn **col NS_OUTPARAM, nsACString & childElt NS_OUTPARAM) { return !_to ? NS_ERROR_NULL_POINTER : _to->GetCellAt(x, y, row, col, childElt); } \
  NS_SCRIPTABLE NS_IMETHOD GetCoordsForCellItem(PRInt32 row, nsITreeColumn *col, const nsACString & element, PRInt32 *x NS_OUTPARAM, PRInt32 *y NS_OUTPARAM, PRInt32 *width NS_OUTPARAM, PRInt32 *height NS_OUTPARAM) { return !_to ? NS_ERROR_NULL_POINTER : _to->GetCoordsForCellItem(row, col, element, x, y, width, height); } \
  NS_SCRIPTABLE NS_IMETHOD IsCellCropped(PRInt32 row, nsITreeColumn *col, PRBool *_retval NS_OUTPARAM) { return !_to ? NS_ERROR_NULL_POINTER : _to->IsCellCropped(row, col, _retval); } \
  NS_SCRIPTABLE NS_IMETHOD RowCountChanged(PRInt32 index, PRInt32 count) { return !_to ? NS_ERROR_NULL_POINTER : _to->RowCountChanged(index, count); } \
  NS_SCRIPTABLE NS_IMETHOD BeginUpdateBatch(void) { return !_to ? NS_ERROR_NULL_POINTER : _to->BeginUpdateBatch(); } \
  NS_SCRIPTABLE NS_IMETHOD EndUpdateBatch(void) { return !_to ? NS_ERROR_NULL_POINTER : _to->EndUpdateBatch(); } \
  NS_SCRIPTABLE NS_IMETHOD ClearStyleAndImageCaches(void) { return !_to ? NS_ERROR_NULL_POINTER : _to->ClearStyleAndImageCaches(); } 

#if 0
/* Use the code below as a template for the implementation class for this interface. */

/* Header file */
class nsTreeBoxObject : public nsITreeBoxObject
{
public:
  NS_DECL_ISUPPORTS
  NS_DECL_NSITREEBOXOBJECT

  nsTreeBoxObject();

private:
  ~nsTreeBoxObject();

protected:
  /* additional members */
};

/* Implementation file */
NS_IMPL_ISUPPORTS1(nsTreeBoxObject, nsITreeBoxObject)

nsTreeBoxObject::nsTreeBoxObject()
{
  /* member initializers and constructor code */
}

nsTreeBoxObject::~nsTreeBoxObject()
{
  /* destructor code */
}

/* readonly attribute nsITreeColumns columns; */
NS_IMETHODIMP nsTreeBoxObject::GetColumns(nsITreeColumns * *aColumns)
{
    return NS_ERROR_NOT_IMPLEMENTED;
}

/* attribute nsITreeView view; */
NS_IMETHODIMP nsTreeBoxObject::GetView(nsITreeView * *aView)
{
    return NS_ERROR_NOT_IMPLEMENTED;
}
NS_IMETHODIMP nsTreeBoxObject::SetView(nsITreeView * aView)
{
    return NS_ERROR_NOT_IMPLEMENTED;
}

/* attribute boolean focused; */
NS_IMETHODIMP nsTreeBoxObject::GetFocused(PRBool *aFocused)
{
    return NS_ERROR_NOT_IMPLEMENTED;
}
NS_IMETHODIMP nsTreeBoxObject::SetFocused(PRBool aFocused)
{
    return NS_ERROR_NOT_IMPLEMENTED;
}

/* readonly attribute nsIDOMElement treeBody; */
NS_IMETHODIMP nsTreeBoxObject::GetTreeBody(nsIDOMElement * *aTreeBody)
{
    return NS_ERROR_NOT_IMPLEMENTED;
}

/* readonly attribute long rowHeight; */
NS_IMETHODIMP nsTreeBoxObject::GetRowHeight(PRInt32 *aRowHeight)
{
    return NS_ERROR_NOT_IMPLEMENTED;
}

/* readonly attribute long rowWidth; */
NS_IMETHODIMP nsTreeBoxObject::GetRowWidth(PRInt32 *aRowWidth)
{
    return NS_ERROR_NOT_IMPLEMENTED;
}

/* readonly attribute long horizontalPosition; */
NS_IMETHODIMP nsTreeBoxObject::GetHorizontalPosition(PRInt32 *aHorizontalPosition)
{
    return NS_ERROR_NOT_IMPLEMENTED;
}

/* readonly attribute nsIScriptableRegion selectionRegion; */
NS_IMETHODIMP nsTreeBoxObject::GetSelectionRegion(nsIScriptableRegion * *aSelectionRegion)
{
    return NS_ERROR_NOT_IMPLEMENTED;
}

/* long getFirstVisibleRow (); */
NS_IMETHODIMP nsTreeBoxObject::GetFirstVisibleRow(PRInt32 *_retval NS_OUTPARAM)
{
    return NS_ERROR_NOT_IMPLEMENTED;
}

/* long getLastVisibleRow (); */
NS_IMETHODIMP nsTreeBoxObject::GetLastVisibleRow(PRInt32 *_retval NS_OUTPARAM)
{
    return NS_ERROR_NOT_IMPLEMENTED;
}

/* long getPageLength (); */
NS_IMETHODIMP nsTreeBoxObject::GetPageLength(PRInt32 *_retval NS_OUTPARAM)
{
    return NS_ERROR_NOT_IMPLEMENTED;
}

/* void ensureRowIsVisible (in long index); */
NS_IMETHODIMP nsTreeBoxObject::EnsureRowIsVisible(PRInt32 index)
{
    return NS_ERROR_NOT_IMPLEMENTED;
}

/* void ensureCellIsVisible (in long row, in nsITreeColumn col); */
NS_IMETHODIMP nsTreeBoxObject::EnsureCellIsVisible(PRInt32 row, nsITreeColumn *col)
{
    return NS_ERROR_NOT_IMPLEMENTED;
}

/* void scrollToRow (in long index); */
NS_IMETHODIMP nsTreeBoxObject::ScrollToRow(PRInt32 index)
{
    return NS_ERROR_NOT_IMPLEMENTED;
}

/* void scrollByLines (in long numLines); */
NS_IMETHODIMP nsTreeBoxObject::ScrollByLines(PRInt32 numLines)
{
    return NS_ERROR_NOT_IMPLEMENTED;
}

/* void scrollByPages (in long numPages); */
NS_IMETHODIMP nsTreeBoxObject::ScrollByPages(PRInt32 numPages)
{
    return NS_ERROR_NOT_IMPLEMENTED;
}

/* void scrollToCell (in long row, in nsITreeColumn col); */
NS_IMETHODIMP nsTreeBoxObject::ScrollToCell(PRInt32 row, nsITreeColumn *col)
{
    return NS_ERROR_NOT_IMPLEMENTED;
}

/* void scrollToColumn (in nsITreeColumn col); */
NS_IMETHODIMP nsTreeBoxObject::ScrollToColumn(nsITreeColumn *col)
{
    return NS_ERROR_NOT_IMPLEMENTED;
}

/* void scrollToHorizontalPosition (in long horizontalPosition); */
NS_IMETHODIMP nsTreeBoxObject::ScrollToHorizontalPosition(PRInt32 horizontalPosition)
{
    return NS_ERROR_NOT_IMPLEMENTED;
}

/* void invalidate (); */
NS_IMETHODIMP nsTreeBoxObject::Invalidate()
{
    return NS_ERROR_NOT_IMPLEMENTED;
}

/* void invalidateColumn (in nsITreeColumn col); */
NS_IMETHODIMP nsTreeBoxObject::InvalidateColumn(nsITreeColumn *col)
{
    return NS_ERROR_NOT_IMPLEMENTED;
}

/* void invalidateRow (in long index); */
NS_IMETHODIMP nsTreeBoxObject::InvalidateRow(PRInt32 index)
{
    return NS_ERROR_NOT_IMPLEMENTED;
}

/* void invalidateCell (in long row, in nsITreeColumn col); */
NS_IMETHODIMP nsTreeBoxObject::InvalidateCell(PRInt32 row, nsITreeColumn *col)
{
    return NS_ERROR_NOT_IMPLEMENTED;
}

/* void invalidateRange (in long startIndex, in long endIndex); */
NS_IMETHODIMP nsTreeBoxObject::InvalidateRange(PRInt32 startIndex, PRInt32 endIndex)
{
    return NS_ERROR_NOT_IMPLEMENTED;
}

/* void invalidateColumnRange (in long startIndex, in long endIndex, in nsITreeColumn col); */
NS_IMETHODIMP nsTreeBoxObject::InvalidateColumnRange(PRInt32 startIndex, PRInt32 endIndex, nsITreeColumn *col)
{
    return NS_ERROR_NOT_IMPLEMENTED;
}

/* long getRowAt (in long x, in long y); */
NS_IMETHODIMP nsTreeBoxObject::GetRowAt(PRInt32 x, PRInt32 y, PRInt32 *_retval NS_OUTPARAM)
{
    return NS_ERROR_NOT_IMPLEMENTED;
}

/* void getCellAt (in long x, in long y, out long row, out nsITreeColumn col, out ACString childElt); */
NS_IMETHODIMP nsTreeBoxObject::GetCellAt(PRInt32 x, PRInt32 y, PRInt32 *row NS_OUTPARAM, nsITreeColumn **col NS_OUTPARAM, nsACString & childElt NS_OUTPARAM)
{
    return NS_ERROR_NOT_IMPLEMENTED;
}

/* void getCoordsForCellItem (in long row, in nsITreeColumn col, in ACString element, out long x, out long y, out long width, out long height); */
NS_IMETHODIMP nsTreeBoxObject::GetCoordsForCellItem(PRInt32 row, nsITreeColumn *col, const nsACString & element, PRInt32 *x NS_OUTPARAM, PRInt32 *y NS_OUTPARAM, PRInt32 *width NS_OUTPARAM, PRInt32 *height NS_OUTPARAM)
{
    return NS_ERROR_NOT_IMPLEMENTED;
}

/* boolean isCellCropped (in long row, in nsITreeColumn col); */
NS_IMETHODIMP nsTreeBoxObject::IsCellCropped(PRInt32 row, nsITreeColumn *col, PRBool *_retval NS_OUTPARAM)
{
    return NS_ERROR_NOT_IMPLEMENTED;
}

/* void rowCountChanged (in long index, in long count); */
NS_IMETHODIMP nsTreeBoxObject::RowCountChanged(PRInt32 index, PRInt32 count)
{
    return NS_ERROR_NOT_IMPLEMENTED;
}

/* void beginUpdateBatch (); */
NS_IMETHODIMP nsTreeBoxObject::BeginUpdateBatch()
{
    return NS_ERROR_NOT_IMPLEMENTED;
}

/* void endUpdateBatch (); */
NS_IMETHODIMP nsTreeBoxObject::EndUpdateBatch()
{
    return NS_ERROR_NOT_IMPLEMENTED;
}

/* void clearStyleAndImageCaches (); */
NS_IMETHODIMP nsTreeBoxObject::ClearStyleAndImageCaches()
{
    return NS_ERROR_NOT_IMPLEMENTED;
}

/* End of implementation class template. */
#endif


#endif /* __gen_nsITreeBoxObject_h__ */
