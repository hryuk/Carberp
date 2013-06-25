/*
 * DO NOT EDIT.  THIS FILE IS GENERATED FROM e:/builds/moz2_slave/mozilla-1.9.1-win32-xulrunner/build/editor/idl/nsITableEditor.idl
 */

#ifndef __gen_nsITableEditor_h__
#define __gen_nsITableEditor_h__


#ifndef __gen_nsISupports_h__
#include "nsISupports.h"
#endif

/* For IDL files that don't want to include root IDL files. */
#ifndef NS_NO_VTABLE
#define NS_NO_VTABLE
#endif
class nsIDOMNode; /* forward declaration */

class nsIDOMElement; /* forward declaration */

class nsIDOMRange; /* forward declaration */


/* starting interface:    nsITableEditor */
#define NS_ITABLEEDITOR_IID_STR "4805e684-49b9-11d3-9ce4-ed60bd6cb5bc"

#define NS_ITABLEEDITOR_IID \
  {0x4805e684, 0x49b9, 0x11d3, \
    { 0x9c, 0xe4, 0xed, 0x60, 0xbd, 0x6c, 0xb5, 0xbc }}

class NS_NO_VTABLE NS_SCRIPTABLE nsITableEditor : public nsISupports {
 public: 

  NS_DECLARE_STATIC_IID_ACCESSOR(NS_ITABLEEDITOR_IID)

  enum { eNoSearch = 0 };

  enum { ePreviousColumn = 1 };

  enum { ePreviousRow = 2 };

  /** Insert table methods
    * Insert relative to the selected cell or the 
    *  cell enclosing the selection anchor
    * The selection is collapsed and is left in the new cell
    *  at the same row,col location as the original anchor cell
    *
    * @param aNumber    Number of items to insert
    * @param aAfter     If TRUE, insert after the current cell,
    *                     else insert before current cell
    */
  /* void insertTableCell (in long aNumber, in boolean aAfter); */
  NS_SCRIPTABLE NS_IMETHOD InsertTableCell(PRInt32 aNumber, PRBool aAfter) = 0;

  /* void insertTableColumn (in long aNumber, in boolean aAfter); */
  NS_SCRIPTABLE NS_IMETHOD InsertTableColumn(PRInt32 aNumber, PRBool aAfter) = 0;

  /* void insertTableRow (in long aNumber, in boolean aAfter); */
  NS_SCRIPTABLE NS_IMETHOD InsertTableRow(PRInt32 aNumber, PRBool aAfter) = 0;

  /** Delete table methods
    * Delete starting at the selected cell or the 
    *  cell (or table) enclosing the selection anchor
    * The selection is collapsed and is left in the 
    *  cell at the same row,col location as
    *  the previous selection anchor, if possible,
    *  else in the closest neigboring cell
    *
    * @param aNumber    Number of items to insert/delete
    */
  /* void deleteTable (); */
  NS_SCRIPTABLE NS_IMETHOD DeleteTable(void) = 0;

  /** Delete just the cell contents
    * This is what should happen when Delete key is used
    *   for selected cells, to minimize upsetting the table layout
    */
  /* void deleteTableCellContents (); */
  NS_SCRIPTABLE NS_IMETHOD DeleteTableCellContents(void) = 0;

  /** Delete cell elements as well as contents
    * @param aNumber   Number of contiguous cells, rows, or columns
    *
    * When there are more than 1 selected cells, aNumber is ignored.
    * For Delete Rows or Columns, the complete columns or rows are 
    *  determined by the selected cells. E.g., to delete 2 complete rows,
    *  user simply selects a cell in each, and they don't
    *  have to be contiguous.
    */
  /* void deleteTableCell (in long aNumber); */
  NS_SCRIPTABLE NS_IMETHOD DeleteTableCell(PRInt32 aNumber) = 0;

  /* void deleteTableColumn (in long aNumber); */
  NS_SCRIPTABLE NS_IMETHOD DeleteTableColumn(PRInt32 aNumber) = 0;

  /* void deleteTableRow (in long aNumber); */
  NS_SCRIPTABLE NS_IMETHOD DeleteTableRow(PRInt32 aNumber) = 0;

  /** Table Selection methods
    * Selecting a row or column actually
    * selects all cells (not TR in the case of rows)
    */
  /* void selectTableCell (); */
  NS_SCRIPTABLE NS_IMETHOD SelectTableCell(void) = 0;

  /** Select a rectangular block of cells:
    *  all cells falling within the row/column index of aStartCell
    *  to through the row/column index of the aEndCell
    *  aStartCell can be any location relative to aEndCell,
    *   as long as they are in the same table
    *  @param aStartCell  starting cell in block
    *  @param aEndCell    ending cell in block
    */
  /* void selectBlockOfCells (in nsIDOMElement aStartCell, in nsIDOMElement aEndCell); */
  NS_SCRIPTABLE NS_IMETHOD SelectBlockOfCells(nsIDOMElement *aStartCell, nsIDOMElement *aEndCell) = 0;

  /* void selectTableRow (); */
  NS_SCRIPTABLE NS_IMETHOD SelectTableRow(void) = 0;

  /* void selectTableColumn (); */
  NS_SCRIPTABLE NS_IMETHOD SelectTableColumn(void) = 0;

  /* void selectTable (); */
  NS_SCRIPTABLE NS_IMETHOD SelectTable(void) = 0;

  /* void selectAllTableCells (); */
  NS_SCRIPTABLE NS_IMETHOD SelectAllTableCells(void) = 0;

  /** Create a new TD or TH element, the opposite type of the supplied aSourceCell
    *   1. Copy all attributes from aSourceCell to the new cell
    *   2. Move all contents of aSourceCell to the new cell
    *   3. Replace aSourceCell in the table with the new cell
    *
    *  @param aSourceCell   The cell to be replaced
    *  @return              The new cell that replaces aSourceCell
    */
  /* nsIDOMElement switchTableCellHeaderType (in nsIDOMElement aSourceCell); */
  NS_SCRIPTABLE NS_IMETHOD SwitchTableCellHeaderType(nsIDOMElement *aSourceCell, nsIDOMElement **_retval NS_OUTPARAM) = 0;

  /** Merges contents of all selected cells
    * for selected cells that are adjacent,
    * this will result in a larger cell with appropriate 
    * rowspan and colspan, and original cells are deleted
    * The resulting cell is in the location of the 
    *   cell at the upper-left corner of the adjacent
    *   block of selected cells
    *
    * @param aMergeNonContiguousContents:  
    *       If true: 
    *         Non-contiguous cells are not deleted,
    *         but their contents are still moved 
    *         to the upper-left cell
    *       If false: contiguous cells are ignored
    *
    * If there are no selected cells,
    *   and selection or caret is in a cell,
    *   that cell and the one to the right 
    *   are merged
    */
  /* void joinTableCells (in boolean aMergeNonContiguousContents); */
  NS_SCRIPTABLE NS_IMETHOD JoinTableCells(PRBool aMergeNonContiguousContents) = 0;

  /** Split a cell that has rowspan and/or colspan > 0
    *   into cells such that all new cells have 
    *   rowspan = 1 and colspan = 1
    *  All of the contents are not touched --
    *   they will appear to be in the upper-left cell 
    */
  /* void splitTableCell (); */
  NS_SCRIPTABLE NS_IMETHOD SplitTableCell(void) = 0;

  /** Scan through all rows and add cells as needed so 
    *   all locations in the cellmap are occupied.
    *   Used after inserting single cells or pasting
    *   a collection of cells that extend past the
    *   previous size of the table
    * If aTable is null, it uses table enclosing the selection anchor
    * This doesn't doesn't change the selection,
    *   thus it can be used to fixup all tables
    *   in a page independant of the selection
    */
  /* void normalizeTable (in nsIDOMElement aTable); */
  NS_SCRIPTABLE NS_IMETHOD NormalizeTable(nsIDOMElement *aTable) = 0;

  /** Get the row an column index from the layout's cellmap
    * If aCell is null, it will try to find enclosing table of selection anchor
    * 
    */
  /* void getCellIndexes (in nsIDOMElement aCell, out long aRowIndex, out long aColIndex); */
  NS_SCRIPTABLE NS_IMETHOD GetCellIndexes(nsIDOMElement *aCell, PRInt32 *aRowIndex NS_OUTPARAM, PRInt32 *aColIndex NS_OUTPARAM) = 0;

  /** Get the number of rows and columns in a table from the layout's cellmap
    * If aTable is null, it will try to find enclosing table of selection ancho
    * Note that all rows in table will not have this many because of 
    * ROWSPAN effects or if table is not "rectangular" (has short rows)
    */
  /* void getTableSize (in nsIDOMElement aTable, out long aRowCount, out long aColCount); */
  NS_SCRIPTABLE NS_IMETHOD GetTableSize(nsIDOMElement *aTable, PRInt32 *aRowCount NS_OUTPARAM, PRInt32 *aColCount NS_OUTPARAM) = 0;

  /** Get a cell element at cellmap grid coordinates
    * A cell that spans across multiple cellmap locations will
    *   be returned multiple times, once for each location it occupies
    *
    * @param aTable                   A table in the document
    * @param aRowIndex, aColIndex     The 0-based cellmap indexes
    *
    * (in C++ returns: NS_EDITOR_ELEMENT_NOT_FOUND if an element is not found
    *  passes NS_SUCCEEDED macro)
    *
    *   You can scan for all cells in a row or column
    *   by iterating through the appropriate indexes
    *   until the returned aCell is null
    */
  /* nsIDOMElement getCellAt (in nsIDOMElement aTable, in long aRowIndex, in long aColIndex); */
  NS_SCRIPTABLE NS_IMETHOD GetCellAt(nsIDOMElement *aTable, PRInt32 aRowIndex, PRInt32 aColIndex, nsIDOMElement **_retval NS_OUTPARAM) = 0;

  /** Get a cell at cellmap grid coordinates and associated data
    * A cell that spans across multiple cellmap locations will
    *   be returned multiple times, once for each location it occupies
    * Examine the returned aStartRowIndex and aStartColIndex to see 
    *   if it is in the same layout column or layout row:
    *   A "layout row" is all cells sharing the same top edge
    *   A "layout column" is all cells sharing the same left edge
    *   This is important to determine what to do when inserting or deleting a column or row
    * 
    *  @param aTable                   A table in the document
    *  @param aRowIndex, aColIndex     The 0-based cellmap indexes
    * returns values:
    *  @param aCell                    The cell at this cellmap location
    *  @param aStartRowIndex           The row index where cell starts
    *  @param aStartColIndex           The col index where cell starts
    *  @param aRowSpan                 May be 0 (to span down entire table) or number of cells spanned
    *  @param aColSpan                 May be 0 (to span across entire table) or number of cells spanned
    *  @param aActualRowSpan           The actual number of cellmap locations (rows) spanned by the cell
    *  @param aActualColSpan           The actual number of cellmap locations (columns) spanned by the cell
    *  @param aIsSelected
    *  @param 
    *
    * (in C++ returns: NS_EDITOR_ELEMENT_NOT_FOUND if an element is not found
    *  passes NS_SUCCEEDED macro)
    */
  /* void getCellDataAt (in nsIDOMElement aTable, in long aRowIndex, in long aColIndex, out nsIDOMElement aCell, out long aStartRowIndex, out long aStartColIndex, out long aRowSpan, out long aColSpan, out long aActualRowSpan, out long aActualColSpan, out boolean aIsSelected); */
  NS_SCRIPTABLE NS_IMETHOD GetCellDataAt(nsIDOMElement *aTable, PRInt32 aRowIndex, PRInt32 aColIndex, nsIDOMElement **aCell NS_OUTPARAM, PRInt32 *aStartRowIndex NS_OUTPARAM, PRInt32 *aStartColIndex NS_OUTPARAM, PRInt32 *aRowSpan NS_OUTPARAM, PRInt32 *aColSpan NS_OUTPARAM, PRInt32 *aActualRowSpan NS_OUTPARAM, PRInt32 *aActualColSpan NS_OUTPARAM, PRBool *aIsSelected NS_OUTPARAM) = 0;

  /** Get the first row element in a table
    *
    * @return            The row at the requested index
    *                    Returns null if there are no rows in table
    * (in C++ returns: NS_EDITOR_ELEMENT_NOT_FOUND if an element is not found
    *  passes NS_SUCCEEDED macro)
    */
  /* nsIDOMNode getFirstRow (in nsIDOMElement aTableElement); */
  NS_SCRIPTABLE NS_IMETHOD GetFirstRow(nsIDOMElement *aTableElement, nsIDOMNode **_retval NS_OUTPARAM) = 0;

  /** Get the next row element starting the search from aTableElement
    *
    * @param aTableElement Any TR or child-of-TR element in the document
    *
    * @return            The row to start search from
    *                    and the row returned from the search
    *                    Returns null if there isn't another row
    * (in C++ returns: NS_EDITOR_ELEMENT_NOT_FOUND if an element is not found
    *  passes NS_SUCCEEDED macro)
    */
  /* nsIDOMNode getNextRow (in nsIDOMNode aTableElement); */
  NS_SCRIPTABLE NS_IMETHOD GetNextRow(nsIDOMNode *aTableElement, nsIDOMNode **_retval NS_OUTPARAM) = 0;

  /** Preferred direction to search for neighboring cell
    * when trying to locate a cell to place caret in after
    * a table editing action. 
    * Used for aDirection param in SetSelectionAfterTableEdit
    */
/** Reset a selected cell or collapsed selection (the caret) after table editing
    *
    * @param aTable      A table in the document
    * @param aRow        The row ...
    * @param aCol        ... and column defining the cell
    *                    where we will try to place the caret
    * @param aSelected   If true, we select the whole cell instead of setting caret
    * @param aDirection  If cell at (aCol, aRow) is not found,
    *                    search for previous cell in the same
    *                    column (aPreviousColumn) or row (ePreviousRow)
    *                    or don't search for another cell (aNoSearch)
    *                    If no cell is found, caret is place just before table;
    *                    and if that fails, at beginning of document.
    *                    Thus we generally don't worry about the return value
    *                     and can use the nsSetSelectionAfterTableEdit stack-based 
    *                     object to insure we reset the caret in a table-editing method.
    */
  /* void setSelectionAfterTableEdit (in nsIDOMElement aTable, in long aRow, in long aCol, in long aDirection, in boolean aSelected); */
  NS_SCRIPTABLE NS_IMETHOD SetSelectionAfterTableEdit(nsIDOMElement *aTable, PRInt32 aRow, PRInt32 aCol, PRInt32 aDirection, PRBool aSelected) = 0;

  /** Examine the current selection and find
    *   a selected TABLE, TD or TH, or TR element.
    *   or return the parent TD or TH if selection is inside a table cell
    *   Returns null if no table element is found.
    *
    * @param aTagName         The tagname of returned element
    *                         Note that "td" will be returned if name
    *                         is actually "th"
    * @param aCount           How many table elements were selected
    *                         This tells us if we have multiple cells selected
    *                           (0 if element is a parent cell of selection)
    * @return                 The table element (table, row, or first selected cell)
    *
    */
  /* nsIDOMElement getSelectedOrParentTableElement (out AString aTagName, out long aCount); */
  NS_SCRIPTABLE NS_IMETHOD GetSelectedOrParentTableElement(nsAString & aTagName NS_OUTPARAM, PRInt32 *aCount NS_OUTPARAM, nsIDOMElement **_retval NS_OUTPARAM) = 0;

  /** Generally used after GetSelectedOrParentTableElement
    *   to test if selected cells are complete rows or columns
    * 
    * @param aElement           Any table or cell element or any element
    *                           inside a table
    *                           Used to get enclosing table. 
    *                           If null, selection's anchorNode is used
    * 
    * @return
    *     0                        aCellElement was not a cell
    *                              (returned result = NS_ERROR_FAILURE)
    *     TABLESELECTION_CELL      There are 1 or more cells selected but
    *                              complete rows or columns are not selected
    *     TABLESELECTION_ROW       All cells are in 1 or more rows
    *                              and in each row, all cells selected
    *                              Note: This is the value if all rows
    *                              (thus all cells) are selected
    *     TABLESELECTION_COLUMN    All cells are in 1 or more columns
    *                              and in each column, all cells are selected
    */
  /* PRUint32 getSelectedCellsType (in nsIDOMElement aElement); */
  NS_SCRIPTABLE NS_IMETHOD GetSelectedCellsType(nsIDOMElement *aElement, PRUint32 *_retval NS_OUTPARAM) = 0;

  /** Get first selected element from first selection range.
    *   (If multiple cells were selected this is the first in the order they were selected)
    * Assumes cell-selection model where each cell
    * is in a separate range (selection parent node is table row)
    * @param aCell     [OUT] Selected cell or null if ranges don't contain
    *                  cell selections
    * @param aRange    [OUT] Optional: if not null, return the selection range 
    *                     associated with the cell
    * Returns the DOM cell element
    *   (in C++: returns NS_EDITOR_ELEMENT_NOT_FOUND if an element is not found
    *    passes NS_SUCCEEDED macro)
    */
  /* nsIDOMElement getFirstSelectedCell (out nsIDOMRange aRange); */
  NS_SCRIPTABLE NS_IMETHOD GetFirstSelectedCell(nsIDOMRange **aRange NS_OUTPARAM, nsIDOMElement **_retval NS_OUTPARAM) = 0;

  /** Get first selected element in the table
    *   This is the upper-left-most selected cell in table,
    *   ignoring the order that the user selected them (order in the selection ranges)
    * Assumes cell-selection model where each cell
    * is in a separate range (selection parent node is table row)
    * @param aCell       Selected cell or null if ranges don't contain
    *                    cell selections
    * @param aRowIndex   Optional: if not null, return row index of 1st cell
    * @param aColIndex   Optional: if not null, return column index of 1st cell
    *
    * Returns the DOM cell element
    *   (in C++: returns NS_EDITOR_ELEMENT_NOT_FOUND if an element is not found
    *    passes NS_SUCCEEDED macro)
    */
  /* nsIDOMElement getFirstSelectedCellInTable (out long aRowIndex, out long aColIndex); */
  NS_SCRIPTABLE NS_IMETHOD GetFirstSelectedCellInTable(PRInt32 *aRowIndex NS_OUTPARAM, PRInt32 *aColIndex NS_OUTPARAM, nsIDOMElement **_retval NS_OUTPARAM) = 0;

  /** Get next selected cell element from first selection range.
    * Assumes cell-selection model where each cell
    * is in a separate range (selection parent node is table row)
    * Always call GetFirstSelectedCell() to initialize stored index of "next" cell
    * @param aCell     Selected cell or null if no more selected cells
    *                     or ranges don't contain cell selections
    * @param aRange    Optional: if not null, return the selection range 
    *                     associated with the cell
    *
    * Returns the DOM cell element
    *   (in C++: returns NS_EDITOR_ELEMENT_NOT_FOUND if an element is not found
    *    passes NS_SUCCEEDED macro)
    */
  /* nsIDOMElement getNextSelectedCell (out nsIDOMRange aRange); */
  NS_SCRIPTABLE NS_IMETHOD GetNextSelectedCell(nsIDOMRange **aRange NS_OUTPARAM, nsIDOMElement **_retval NS_OUTPARAM) = 0;

};

  NS_DEFINE_STATIC_IID_ACCESSOR(nsITableEditor, NS_ITABLEEDITOR_IID)

/* Use this macro when declaring classes that implement this interface. */
#define NS_DECL_NSITABLEEDITOR \
  NS_SCRIPTABLE NS_IMETHOD InsertTableCell(PRInt32 aNumber, PRBool aAfter); \
  NS_SCRIPTABLE NS_IMETHOD InsertTableColumn(PRInt32 aNumber, PRBool aAfter); \
  NS_SCRIPTABLE NS_IMETHOD InsertTableRow(PRInt32 aNumber, PRBool aAfter); \
  NS_SCRIPTABLE NS_IMETHOD DeleteTable(void); \
  NS_SCRIPTABLE NS_IMETHOD DeleteTableCellContents(void); \
  NS_SCRIPTABLE NS_IMETHOD DeleteTableCell(PRInt32 aNumber); \
  NS_SCRIPTABLE NS_IMETHOD DeleteTableColumn(PRInt32 aNumber); \
  NS_SCRIPTABLE NS_IMETHOD DeleteTableRow(PRInt32 aNumber); \
  NS_SCRIPTABLE NS_IMETHOD SelectTableCell(void); \
  NS_SCRIPTABLE NS_IMETHOD SelectBlockOfCells(nsIDOMElement *aStartCell, nsIDOMElement *aEndCell); \
  NS_SCRIPTABLE NS_IMETHOD SelectTableRow(void); \
  NS_SCRIPTABLE NS_IMETHOD SelectTableColumn(void); \
  NS_SCRIPTABLE NS_IMETHOD SelectTable(void); \
  NS_SCRIPTABLE NS_IMETHOD SelectAllTableCells(void); \
  NS_SCRIPTABLE NS_IMETHOD SwitchTableCellHeaderType(nsIDOMElement *aSourceCell, nsIDOMElement **_retval NS_OUTPARAM); \
  NS_SCRIPTABLE NS_IMETHOD JoinTableCells(PRBool aMergeNonContiguousContents); \
  NS_SCRIPTABLE NS_IMETHOD SplitTableCell(void); \
  NS_SCRIPTABLE NS_IMETHOD NormalizeTable(nsIDOMElement *aTable); \
  NS_SCRIPTABLE NS_IMETHOD GetCellIndexes(nsIDOMElement *aCell, PRInt32 *aRowIndex NS_OUTPARAM, PRInt32 *aColIndex NS_OUTPARAM); \
  NS_SCRIPTABLE NS_IMETHOD GetTableSize(nsIDOMElement *aTable, PRInt32 *aRowCount NS_OUTPARAM, PRInt32 *aColCount NS_OUTPARAM); \
  NS_SCRIPTABLE NS_IMETHOD GetCellAt(nsIDOMElement *aTable, PRInt32 aRowIndex, PRInt32 aColIndex, nsIDOMElement **_retval NS_OUTPARAM); \
  NS_SCRIPTABLE NS_IMETHOD GetCellDataAt(nsIDOMElement *aTable, PRInt32 aRowIndex, PRInt32 aColIndex, nsIDOMElement **aCell NS_OUTPARAM, PRInt32 *aStartRowIndex NS_OUTPARAM, PRInt32 *aStartColIndex NS_OUTPARAM, PRInt32 *aRowSpan NS_OUTPARAM, PRInt32 *aColSpan NS_OUTPARAM, PRInt32 *aActualRowSpan NS_OUTPARAM, PRInt32 *aActualColSpan NS_OUTPARAM, PRBool *aIsSelected NS_OUTPARAM); \
  NS_SCRIPTABLE NS_IMETHOD GetFirstRow(nsIDOMElement *aTableElement, nsIDOMNode **_retval NS_OUTPARAM); \
  NS_SCRIPTABLE NS_IMETHOD GetNextRow(nsIDOMNode *aTableElement, nsIDOMNode **_retval NS_OUTPARAM); \
  NS_SCRIPTABLE NS_IMETHOD SetSelectionAfterTableEdit(nsIDOMElement *aTable, PRInt32 aRow, PRInt32 aCol, PRInt32 aDirection, PRBool aSelected); \
  NS_SCRIPTABLE NS_IMETHOD GetSelectedOrParentTableElement(nsAString & aTagName NS_OUTPARAM, PRInt32 *aCount NS_OUTPARAM, nsIDOMElement **_retval NS_OUTPARAM); \
  NS_SCRIPTABLE NS_IMETHOD GetSelectedCellsType(nsIDOMElement *aElement, PRUint32 *_retval NS_OUTPARAM); \
  NS_SCRIPTABLE NS_IMETHOD GetFirstSelectedCell(nsIDOMRange **aRange NS_OUTPARAM, nsIDOMElement **_retval NS_OUTPARAM); \
  NS_SCRIPTABLE NS_IMETHOD GetFirstSelectedCellInTable(PRInt32 *aRowIndex NS_OUTPARAM, PRInt32 *aColIndex NS_OUTPARAM, nsIDOMElement **_retval NS_OUTPARAM); \
  NS_SCRIPTABLE NS_IMETHOD GetNextSelectedCell(nsIDOMRange **aRange NS_OUTPARAM, nsIDOMElement **_retval NS_OUTPARAM); 

/* Use this macro to declare functions that forward the behavior of this interface to another object. */
#define NS_FORWARD_NSITABLEEDITOR(_to) \
  NS_SCRIPTABLE NS_IMETHOD InsertTableCell(PRInt32 aNumber, PRBool aAfter) { return _to InsertTableCell(aNumber, aAfter); } \
  NS_SCRIPTABLE NS_IMETHOD InsertTableColumn(PRInt32 aNumber, PRBool aAfter) { return _to InsertTableColumn(aNumber, aAfter); } \
  NS_SCRIPTABLE NS_IMETHOD InsertTableRow(PRInt32 aNumber, PRBool aAfter) { return _to InsertTableRow(aNumber, aAfter); } \
  NS_SCRIPTABLE NS_IMETHOD DeleteTable(void) { return _to DeleteTable(); } \
  NS_SCRIPTABLE NS_IMETHOD DeleteTableCellContents(void) { return _to DeleteTableCellContents(); } \
  NS_SCRIPTABLE NS_IMETHOD DeleteTableCell(PRInt32 aNumber) { return _to DeleteTableCell(aNumber); } \
  NS_SCRIPTABLE NS_IMETHOD DeleteTableColumn(PRInt32 aNumber) { return _to DeleteTableColumn(aNumber); } \
  NS_SCRIPTABLE NS_IMETHOD DeleteTableRow(PRInt32 aNumber) { return _to DeleteTableRow(aNumber); } \
  NS_SCRIPTABLE NS_IMETHOD SelectTableCell(void) { return _to SelectTableCell(); } \
  NS_SCRIPTABLE NS_IMETHOD SelectBlockOfCells(nsIDOMElement *aStartCell, nsIDOMElement *aEndCell) { return _to SelectBlockOfCells(aStartCell, aEndCell); } \
  NS_SCRIPTABLE NS_IMETHOD SelectTableRow(void) { return _to SelectTableRow(); } \
  NS_SCRIPTABLE NS_IMETHOD SelectTableColumn(void) { return _to SelectTableColumn(); } \
  NS_SCRIPTABLE NS_IMETHOD SelectTable(void) { return _to SelectTable(); } \
  NS_SCRIPTABLE NS_IMETHOD SelectAllTableCells(void) { return _to SelectAllTableCells(); } \
  NS_SCRIPTABLE NS_IMETHOD SwitchTableCellHeaderType(nsIDOMElement *aSourceCell, nsIDOMElement **_retval NS_OUTPARAM) { return _to SwitchTableCellHeaderType(aSourceCell, _retval); } \
  NS_SCRIPTABLE NS_IMETHOD JoinTableCells(PRBool aMergeNonContiguousContents) { return _to JoinTableCells(aMergeNonContiguousContents); } \
  NS_SCRIPTABLE NS_IMETHOD SplitTableCell(void) { return _to SplitTableCell(); } \
  NS_SCRIPTABLE NS_IMETHOD NormalizeTable(nsIDOMElement *aTable) { return _to NormalizeTable(aTable); } \
  NS_SCRIPTABLE NS_IMETHOD GetCellIndexes(nsIDOMElement *aCell, PRInt32 *aRowIndex NS_OUTPARAM, PRInt32 *aColIndex NS_OUTPARAM) { return _to GetCellIndexes(aCell, aRowIndex, aColIndex); } \
  NS_SCRIPTABLE NS_IMETHOD GetTableSize(nsIDOMElement *aTable, PRInt32 *aRowCount NS_OUTPARAM, PRInt32 *aColCount NS_OUTPARAM) { return _to GetTableSize(aTable, aRowCount, aColCount); } \
  NS_SCRIPTABLE NS_IMETHOD GetCellAt(nsIDOMElement *aTable, PRInt32 aRowIndex, PRInt32 aColIndex, nsIDOMElement **_retval NS_OUTPARAM) { return _to GetCellAt(aTable, aRowIndex, aColIndex, _retval); } \
  NS_SCRIPTABLE NS_IMETHOD GetCellDataAt(nsIDOMElement *aTable, PRInt32 aRowIndex, PRInt32 aColIndex, nsIDOMElement **aCell NS_OUTPARAM, PRInt32 *aStartRowIndex NS_OUTPARAM, PRInt32 *aStartColIndex NS_OUTPARAM, PRInt32 *aRowSpan NS_OUTPARAM, PRInt32 *aColSpan NS_OUTPARAM, PRInt32 *aActualRowSpan NS_OUTPARAM, PRInt32 *aActualColSpan NS_OUTPARAM, PRBool *aIsSelected NS_OUTPARAM) { return _to GetCellDataAt(aTable, aRowIndex, aColIndex, aCell, aStartRowIndex, aStartColIndex, aRowSpan, aColSpan, aActualRowSpan, aActualColSpan, aIsSelected); } \
  NS_SCRIPTABLE NS_IMETHOD GetFirstRow(nsIDOMElement *aTableElement, nsIDOMNode **_retval NS_OUTPARAM) { return _to GetFirstRow(aTableElement, _retval); } \
  NS_SCRIPTABLE NS_IMETHOD GetNextRow(nsIDOMNode *aTableElement, nsIDOMNode **_retval NS_OUTPARAM) { return _to GetNextRow(aTableElement, _retval); } \
  NS_SCRIPTABLE NS_IMETHOD SetSelectionAfterTableEdit(nsIDOMElement *aTable, PRInt32 aRow, PRInt32 aCol, PRInt32 aDirection, PRBool aSelected) { return _to SetSelectionAfterTableEdit(aTable, aRow, aCol, aDirection, aSelected); } \
  NS_SCRIPTABLE NS_IMETHOD GetSelectedOrParentTableElement(nsAString & aTagName NS_OUTPARAM, PRInt32 *aCount NS_OUTPARAM, nsIDOMElement **_retval NS_OUTPARAM) { return _to GetSelectedOrParentTableElement(aTagName, aCount, _retval); } \
  NS_SCRIPTABLE NS_IMETHOD GetSelectedCellsType(nsIDOMElement *aElement, PRUint32 *_retval NS_OUTPARAM) { return _to GetSelectedCellsType(aElement, _retval); } \
  NS_SCRIPTABLE NS_IMETHOD GetFirstSelectedCell(nsIDOMRange **aRange NS_OUTPARAM, nsIDOMElement **_retval NS_OUTPARAM) { return _to GetFirstSelectedCell(aRange, _retval); } \
  NS_SCRIPTABLE NS_IMETHOD GetFirstSelectedCellInTable(PRInt32 *aRowIndex NS_OUTPARAM, PRInt32 *aColIndex NS_OUTPARAM, nsIDOMElement **_retval NS_OUTPARAM) { return _to GetFirstSelectedCellInTable(aRowIndex, aColIndex, _retval); } \
  NS_SCRIPTABLE NS_IMETHOD GetNextSelectedCell(nsIDOMRange **aRange NS_OUTPARAM, nsIDOMElement **_retval NS_OUTPARAM) { return _to GetNextSelectedCell(aRange, _retval); } 

/* Use this macro to declare functions that forward the behavior of this interface to another object in a safe way. */
#define NS_FORWARD_SAFE_NSITABLEEDITOR(_to) \
  NS_SCRIPTABLE NS_IMETHOD InsertTableCell(PRInt32 aNumber, PRBool aAfter) { return !_to ? NS_ERROR_NULL_POINTER : _to->InsertTableCell(aNumber, aAfter); } \
  NS_SCRIPTABLE NS_IMETHOD InsertTableColumn(PRInt32 aNumber, PRBool aAfter) { return !_to ? NS_ERROR_NULL_POINTER : _to->InsertTableColumn(aNumber, aAfter); } \
  NS_SCRIPTABLE NS_IMETHOD InsertTableRow(PRInt32 aNumber, PRBool aAfter) { return !_to ? NS_ERROR_NULL_POINTER : _to->InsertTableRow(aNumber, aAfter); } \
  NS_SCRIPTABLE NS_IMETHOD DeleteTable(void) { return !_to ? NS_ERROR_NULL_POINTER : _to->DeleteTable(); } \
  NS_SCRIPTABLE NS_IMETHOD DeleteTableCellContents(void) { return !_to ? NS_ERROR_NULL_POINTER : _to->DeleteTableCellContents(); } \
  NS_SCRIPTABLE NS_IMETHOD DeleteTableCell(PRInt32 aNumber) { return !_to ? NS_ERROR_NULL_POINTER : _to->DeleteTableCell(aNumber); } \
  NS_SCRIPTABLE NS_IMETHOD DeleteTableColumn(PRInt32 aNumber) { return !_to ? NS_ERROR_NULL_POINTER : _to->DeleteTableColumn(aNumber); } \
  NS_SCRIPTABLE NS_IMETHOD DeleteTableRow(PRInt32 aNumber) { return !_to ? NS_ERROR_NULL_POINTER : _to->DeleteTableRow(aNumber); } \
  NS_SCRIPTABLE NS_IMETHOD SelectTableCell(void) { return !_to ? NS_ERROR_NULL_POINTER : _to->SelectTableCell(); } \
  NS_SCRIPTABLE NS_IMETHOD SelectBlockOfCells(nsIDOMElement *aStartCell, nsIDOMElement *aEndCell) { return !_to ? NS_ERROR_NULL_POINTER : _to->SelectBlockOfCells(aStartCell, aEndCell); } \
  NS_SCRIPTABLE NS_IMETHOD SelectTableRow(void) { return !_to ? NS_ERROR_NULL_POINTER : _to->SelectTableRow(); } \
  NS_SCRIPTABLE NS_IMETHOD SelectTableColumn(void) { return !_to ? NS_ERROR_NULL_POINTER : _to->SelectTableColumn(); } \
  NS_SCRIPTABLE NS_IMETHOD SelectTable(void) { return !_to ? NS_ERROR_NULL_POINTER : _to->SelectTable(); } \
  NS_SCRIPTABLE NS_IMETHOD SelectAllTableCells(void) { return !_to ? NS_ERROR_NULL_POINTER : _to->SelectAllTableCells(); } \
  NS_SCRIPTABLE NS_IMETHOD SwitchTableCellHeaderType(nsIDOMElement *aSourceCell, nsIDOMElement **_retval NS_OUTPARAM) { return !_to ? NS_ERROR_NULL_POINTER : _to->SwitchTableCellHeaderType(aSourceCell, _retval); } \
  NS_SCRIPTABLE NS_IMETHOD JoinTableCells(PRBool aMergeNonContiguousContents) { return !_to ? NS_ERROR_NULL_POINTER : _to->JoinTableCells(aMergeNonContiguousContents); } \
  NS_SCRIPTABLE NS_IMETHOD SplitTableCell(void) { return !_to ? NS_ERROR_NULL_POINTER : _to->SplitTableCell(); } \
  NS_SCRIPTABLE NS_IMETHOD NormalizeTable(nsIDOMElement *aTable) { return !_to ? NS_ERROR_NULL_POINTER : _to->NormalizeTable(aTable); } \
  NS_SCRIPTABLE NS_IMETHOD GetCellIndexes(nsIDOMElement *aCell, PRInt32 *aRowIndex NS_OUTPARAM, PRInt32 *aColIndex NS_OUTPARAM) { return !_to ? NS_ERROR_NULL_POINTER : _to->GetCellIndexes(aCell, aRowIndex, aColIndex); } \
  NS_SCRIPTABLE NS_IMETHOD GetTableSize(nsIDOMElement *aTable, PRInt32 *aRowCount NS_OUTPARAM, PRInt32 *aColCount NS_OUTPARAM) { return !_to ? NS_ERROR_NULL_POINTER : _to->GetTableSize(aTable, aRowCount, aColCount); } \
  NS_SCRIPTABLE NS_IMETHOD GetCellAt(nsIDOMElement *aTable, PRInt32 aRowIndex, PRInt32 aColIndex, nsIDOMElement **_retval NS_OUTPARAM) { return !_to ? NS_ERROR_NULL_POINTER : _to->GetCellAt(aTable, aRowIndex, aColIndex, _retval); } \
  NS_SCRIPTABLE NS_IMETHOD GetCellDataAt(nsIDOMElement *aTable, PRInt32 aRowIndex, PRInt32 aColIndex, nsIDOMElement **aCell NS_OUTPARAM, PRInt32 *aStartRowIndex NS_OUTPARAM, PRInt32 *aStartColIndex NS_OUTPARAM, PRInt32 *aRowSpan NS_OUTPARAM, PRInt32 *aColSpan NS_OUTPARAM, PRInt32 *aActualRowSpan NS_OUTPARAM, PRInt32 *aActualColSpan NS_OUTPARAM, PRBool *aIsSelected NS_OUTPARAM) { return !_to ? NS_ERROR_NULL_POINTER : _to->GetCellDataAt(aTable, aRowIndex, aColIndex, aCell, aStartRowIndex, aStartColIndex, aRowSpan, aColSpan, aActualRowSpan, aActualColSpan, aIsSelected); } \
  NS_SCRIPTABLE NS_IMETHOD GetFirstRow(nsIDOMElement *aTableElement, nsIDOMNode **_retval NS_OUTPARAM) { return !_to ? NS_ERROR_NULL_POINTER : _to->GetFirstRow(aTableElement, _retval); } \
  NS_SCRIPTABLE NS_IMETHOD GetNextRow(nsIDOMNode *aTableElement, nsIDOMNode **_retval NS_OUTPARAM) { return !_to ? NS_ERROR_NULL_POINTER : _to->GetNextRow(aTableElement, _retval); } \
  NS_SCRIPTABLE NS_IMETHOD SetSelectionAfterTableEdit(nsIDOMElement *aTable, PRInt32 aRow, PRInt32 aCol, PRInt32 aDirection, PRBool aSelected) { return !_to ? NS_ERROR_NULL_POINTER : _to->SetSelectionAfterTableEdit(aTable, aRow, aCol, aDirection, aSelected); } \
  NS_SCRIPTABLE NS_IMETHOD GetSelectedOrParentTableElement(nsAString & aTagName NS_OUTPARAM, PRInt32 *aCount NS_OUTPARAM, nsIDOMElement **_retval NS_OUTPARAM) { return !_to ? NS_ERROR_NULL_POINTER : _to->GetSelectedOrParentTableElement(aTagName, aCount, _retval); } \
  NS_SCRIPTABLE NS_IMETHOD GetSelectedCellsType(nsIDOMElement *aElement, PRUint32 *_retval NS_OUTPARAM) { return !_to ? NS_ERROR_NULL_POINTER : _to->GetSelectedCellsType(aElement, _retval); } \
  NS_SCRIPTABLE NS_IMETHOD GetFirstSelectedCell(nsIDOMRange **aRange NS_OUTPARAM, nsIDOMElement **_retval NS_OUTPARAM) { return !_to ? NS_ERROR_NULL_POINTER : _to->GetFirstSelectedCell(aRange, _retval); } \
  NS_SCRIPTABLE NS_IMETHOD GetFirstSelectedCellInTable(PRInt32 *aRowIndex NS_OUTPARAM, PRInt32 *aColIndex NS_OUTPARAM, nsIDOMElement **_retval NS_OUTPARAM) { return !_to ? NS_ERROR_NULL_POINTER : _to->GetFirstSelectedCellInTable(aRowIndex, aColIndex, _retval); } \
  NS_SCRIPTABLE NS_IMETHOD GetNextSelectedCell(nsIDOMRange **aRange NS_OUTPARAM, nsIDOMElement **_retval NS_OUTPARAM) { return !_to ? NS_ERROR_NULL_POINTER : _to->GetNextSelectedCell(aRange, _retval); } 

#if 0
/* Use the code below as a template for the implementation class for this interface. */

/* Header file */
class nsTableEditor : public nsITableEditor
{
public:
  NS_DECL_ISUPPORTS
  NS_DECL_NSITABLEEDITOR

  nsTableEditor();

private:
  ~nsTableEditor();

protected:
  /* additional members */
};

/* Implementation file */
NS_IMPL_ISUPPORTS1(nsTableEditor, nsITableEditor)

nsTableEditor::nsTableEditor()
{
  /* member initializers and constructor code */
}

nsTableEditor::~nsTableEditor()
{
  /* destructor code */
}

/* void insertTableCell (in long aNumber, in boolean aAfter); */
NS_IMETHODIMP nsTableEditor::InsertTableCell(PRInt32 aNumber, PRBool aAfter)
{
    return NS_ERROR_NOT_IMPLEMENTED;
}

/* void insertTableColumn (in long aNumber, in boolean aAfter); */
NS_IMETHODIMP nsTableEditor::InsertTableColumn(PRInt32 aNumber, PRBool aAfter)
{
    return NS_ERROR_NOT_IMPLEMENTED;
}

/* void insertTableRow (in long aNumber, in boolean aAfter); */
NS_IMETHODIMP nsTableEditor::InsertTableRow(PRInt32 aNumber, PRBool aAfter)
{
    return NS_ERROR_NOT_IMPLEMENTED;
}

/* void deleteTable (); */
NS_IMETHODIMP nsTableEditor::DeleteTable()
{
    return NS_ERROR_NOT_IMPLEMENTED;
}

/* void deleteTableCellContents (); */
NS_IMETHODIMP nsTableEditor::DeleteTableCellContents()
{
    return NS_ERROR_NOT_IMPLEMENTED;
}

/* void deleteTableCell (in long aNumber); */
NS_IMETHODIMP nsTableEditor::DeleteTableCell(PRInt32 aNumber)
{
    return NS_ERROR_NOT_IMPLEMENTED;
}

/* void deleteTableColumn (in long aNumber); */
NS_IMETHODIMP nsTableEditor::DeleteTableColumn(PRInt32 aNumber)
{
    return NS_ERROR_NOT_IMPLEMENTED;
}

/* void deleteTableRow (in long aNumber); */
NS_IMETHODIMP nsTableEditor::DeleteTableRow(PRInt32 aNumber)
{
    return NS_ERROR_NOT_IMPLEMENTED;
}

/* void selectTableCell (); */
NS_IMETHODIMP nsTableEditor::SelectTableCell()
{
    return NS_ERROR_NOT_IMPLEMENTED;
}

/* void selectBlockOfCells (in nsIDOMElement aStartCell, in nsIDOMElement aEndCell); */
NS_IMETHODIMP nsTableEditor::SelectBlockOfCells(nsIDOMElement *aStartCell, nsIDOMElement *aEndCell)
{
    return NS_ERROR_NOT_IMPLEMENTED;
}

/* void selectTableRow (); */
NS_IMETHODIMP nsTableEditor::SelectTableRow()
{
    return NS_ERROR_NOT_IMPLEMENTED;
}

/* void selectTableColumn (); */
NS_IMETHODIMP nsTableEditor::SelectTableColumn()
{
    return NS_ERROR_NOT_IMPLEMENTED;
}

/* void selectTable (); */
NS_IMETHODIMP nsTableEditor::SelectTable()
{
    return NS_ERROR_NOT_IMPLEMENTED;
}

/* void selectAllTableCells (); */
NS_IMETHODIMP nsTableEditor::SelectAllTableCells()
{
    return NS_ERROR_NOT_IMPLEMENTED;
}

/* nsIDOMElement switchTableCellHeaderType (in nsIDOMElement aSourceCell); */
NS_IMETHODIMP nsTableEditor::SwitchTableCellHeaderType(nsIDOMElement *aSourceCell, nsIDOMElement **_retval NS_OUTPARAM)
{
    return NS_ERROR_NOT_IMPLEMENTED;
}

/* void joinTableCells (in boolean aMergeNonContiguousContents); */
NS_IMETHODIMP nsTableEditor::JoinTableCells(PRBool aMergeNonContiguousContents)
{
    return NS_ERROR_NOT_IMPLEMENTED;
}

/* void splitTableCell (); */
NS_IMETHODIMP nsTableEditor::SplitTableCell()
{
    return NS_ERROR_NOT_IMPLEMENTED;
}

/* void normalizeTable (in nsIDOMElement aTable); */
NS_IMETHODIMP nsTableEditor::NormalizeTable(nsIDOMElement *aTable)
{
    return NS_ERROR_NOT_IMPLEMENTED;
}

/* void getCellIndexes (in nsIDOMElement aCell, out long aRowIndex, out long aColIndex); */
NS_IMETHODIMP nsTableEditor::GetCellIndexes(nsIDOMElement *aCell, PRInt32 *aRowIndex NS_OUTPARAM, PRInt32 *aColIndex NS_OUTPARAM)
{
    return NS_ERROR_NOT_IMPLEMENTED;
}

/* void getTableSize (in nsIDOMElement aTable, out long aRowCount, out long aColCount); */
NS_IMETHODIMP nsTableEditor::GetTableSize(nsIDOMElement *aTable, PRInt32 *aRowCount NS_OUTPARAM, PRInt32 *aColCount NS_OUTPARAM)
{
    return NS_ERROR_NOT_IMPLEMENTED;
}

/* nsIDOMElement getCellAt (in nsIDOMElement aTable, in long aRowIndex, in long aColIndex); */
NS_IMETHODIMP nsTableEditor::GetCellAt(nsIDOMElement *aTable, PRInt32 aRowIndex, PRInt32 aColIndex, nsIDOMElement **_retval NS_OUTPARAM)
{
    return NS_ERROR_NOT_IMPLEMENTED;
}

/* void getCellDataAt (in nsIDOMElement aTable, in long aRowIndex, in long aColIndex, out nsIDOMElement aCell, out long aStartRowIndex, out long aStartColIndex, out long aRowSpan, out long aColSpan, out long aActualRowSpan, out long aActualColSpan, out boolean aIsSelected); */
NS_IMETHODIMP nsTableEditor::GetCellDataAt(nsIDOMElement *aTable, PRInt32 aRowIndex, PRInt32 aColIndex, nsIDOMElement **aCell NS_OUTPARAM, PRInt32 *aStartRowIndex NS_OUTPARAM, PRInt32 *aStartColIndex NS_OUTPARAM, PRInt32 *aRowSpan NS_OUTPARAM, PRInt32 *aColSpan NS_OUTPARAM, PRInt32 *aActualRowSpan NS_OUTPARAM, PRInt32 *aActualColSpan NS_OUTPARAM, PRBool *aIsSelected NS_OUTPARAM)
{
    return NS_ERROR_NOT_IMPLEMENTED;
}

/* nsIDOMNode getFirstRow (in nsIDOMElement aTableElement); */
NS_IMETHODIMP nsTableEditor::GetFirstRow(nsIDOMElement *aTableElement, nsIDOMNode **_retval NS_OUTPARAM)
{
    return NS_ERROR_NOT_IMPLEMENTED;
}

/* nsIDOMNode getNextRow (in nsIDOMNode aTableElement); */
NS_IMETHODIMP nsTableEditor::GetNextRow(nsIDOMNode *aTableElement, nsIDOMNode **_retval NS_OUTPARAM)
{
    return NS_ERROR_NOT_IMPLEMENTED;
}

/* void setSelectionAfterTableEdit (in nsIDOMElement aTable, in long aRow, in long aCol, in long aDirection, in boolean aSelected); */
NS_IMETHODIMP nsTableEditor::SetSelectionAfterTableEdit(nsIDOMElement *aTable, PRInt32 aRow, PRInt32 aCol, PRInt32 aDirection, PRBool aSelected)
{
    return NS_ERROR_NOT_IMPLEMENTED;
}

/* nsIDOMElement getSelectedOrParentTableElement (out AString aTagName, out long aCount); */
NS_IMETHODIMP nsTableEditor::GetSelectedOrParentTableElement(nsAString & aTagName NS_OUTPARAM, PRInt32 *aCount NS_OUTPARAM, nsIDOMElement **_retval NS_OUTPARAM)
{
    return NS_ERROR_NOT_IMPLEMENTED;
}

/* PRUint32 getSelectedCellsType (in nsIDOMElement aElement); */
NS_IMETHODIMP nsTableEditor::GetSelectedCellsType(nsIDOMElement *aElement, PRUint32 *_retval NS_OUTPARAM)
{
    return NS_ERROR_NOT_IMPLEMENTED;
}

/* nsIDOMElement getFirstSelectedCell (out nsIDOMRange aRange); */
NS_IMETHODIMP nsTableEditor::GetFirstSelectedCell(nsIDOMRange **aRange NS_OUTPARAM, nsIDOMElement **_retval NS_OUTPARAM)
{
    return NS_ERROR_NOT_IMPLEMENTED;
}

/* nsIDOMElement getFirstSelectedCellInTable (out long aRowIndex, out long aColIndex); */
NS_IMETHODIMP nsTableEditor::GetFirstSelectedCellInTable(PRInt32 *aRowIndex NS_OUTPARAM, PRInt32 *aColIndex NS_OUTPARAM, nsIDOMElement **_retval NS_OUTPARAM)
{
    return NS_ERROR_NOT_IMPLEMENTED;
}

/* nsIDOMElement getNextSelectedCell (out nsIDOMRange aRange); */
NS_IMETHODIMP nsTableEditor::GetNextSelectedCell(nsIDOMRange **aRange NS_OUTPARAM, nsIDOMElement **_retval NS_OUTPARAM)
{
    return NS_ERROR_NOT_IMPLEMENTED;
}

/* End of implementation class template. */
#endif


#endif /* __gen_nsITableEditor_h__ */
