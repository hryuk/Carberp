/*
 * DO NOT EDIT.  THIS FILE IS GENERATED FROM e:/builds/moz2_slave/mozilla-1.9.1-win32-xulrunner/build/accessible/public/nsIAccessibleTable.idl
 */

#ifndef __gen_nsIAccessibleTable_h__
#define __gen_nsIAccessibleTable_h__


#ifndef __gen_nsISupports_h__
#include "nsISupports.h"
#endif

/* For IDL files that don't want to include root IDL files. */
#ifndef NS_NO_VTABLE
#define NS_NO_VTABLE
#endif
class nsIAccessible; /* forward declaration */


/* starting interface:    nsIAccessibleTable */
#define NS_IACCESSIBLETABLE_IID_STR "dcc1e5c3-966e-45b2-b30a-839d35432b24"

#define NS_IACCESSIBLETABLE_IID \
  {0xdcc1e5c3, 0x966e, 0x45b2, \
    { 0xb3, 0x0a, 0x83, 0x9d, 0x35, 0x43, 0x2b, 0x24 }}

class NS_NO_VTABLE NS_SCRIPTABLE nsIAccessibleTable : public nsISupports {
 public: 

  NS_DECLARE_STATIC_IID_ACCESSOR(NS_IACCESSIBLETABLE_IID)

  /* readonly attribute nsIAccessible caption; */
  NS_SCRIPTABLE NS_IMETHOD GetCaption(nsIAccessible * *aCaption) = 0;

  /* readonly attribute AString summary; */
  NS_SCRIPTABLE NS_IMETHOD GetSummary(nsAString & aSummary) = 0;

  /* readonly attribute long columns; */
  NS_SCRIPTABLE NS_IMETHOD GetColumns(PRInt32 *aColumns) = 0;

  /* readonly attribute nsIAccessibleTable columnHeader; */
  NS_SCRIPTABLE NS_IMETHOD GetColumnHeader(nsIAccessibleTable * *aColumnHeader) = 0;

  /* readonly attribute long rows; */
  NS_SCRIPTABLE NS_IMETHOD GetRows(PRInt32 *aRows) = 0;

  /* readonly attribute nsIAccessibleTable rowHeader; */
  NS_SCRIPTABLE NS_IMETHOD GetRowHeader(nsIAccessibleTable * *aRowHeader) = 0;

  /**
   * Returns the accessible object at the specified row and column in the table.
   * If both row and column index are valid then the corresponding accessible
   * object is returned that represents the requested cell regardless of whether
   * the cell is currently visible (on the screen).
   *
   * @param row - The row index for which to retrieve the cell.
   * @param column - The column index for which to retrieve the cell.
   */
  /* nsIAccessible cellRefAt (in long row, in long column); */
  NS_SCRIPTABLE NS_IMETHOD CellRefAt(PRInt32 row, PRInt32 column, nsIAccessible **_retval NS_OUTPARAM) = 0;

  /**
   * Translates the given row and column indices into the corresponding cell
   * index.
   *
   * @param row - index of the row of the table for which to return the cell
   *              index.
   * @param column - index of the column of the table for which to return
   *                 the cell index.
   */
  /* long getIndexAt (in long row, in long column); */
  NS_SCRIPTABLE NS_IMETHOD GetIndexAt(PRInt32 row, PRInt32 column, PRInt32 *_retval NS_OUTPARAM) = 0;

  /**
   * Translates the given child index into the corresponding column index.
   *
   * @param index - index of the child of the table for which to return
   *                the column index.
   */
  /* long getColumnAtIndex (in long index); */
  NS_SCRIPTABLE NS_IMETHOD GetColumnAtIndex(PRInt32 index, PRInt32 *_retval NS_OUTPARAM) = 0;

  /**
   * Translates the given child index into the corresponding row index.
   *
   * @param index - index of the child of the table for which to return
   *                the row index.
   */
  /* long getRowAtIndex (in long index); */
  NS_SCRIPTABLE NS_IMETHOD GetRowAtIndex(PRInt32 index, PRInt32 *_retval NS_OUTPARAM) = 0;

  /**
   * Returns the number of columns occupied by the accessible object
   * at the specified row and column in the table. The result differs from 1
   * if the specified cell spans multiple columns.
   *
   * @param row - Row index of the accessible for which to return
   *              the column extent.
   * @param column - Column index of the accessible for which to return
   *                 the column extent.
   */
  /* long getColumnExtentAt (in long row, in long column); */
  NS_SCRIPTABLE NS_IMETHOD GetColumnExtentAt(PRInt32 row, PRInt32 column, PRInt32 *_retval NS_OUTPARAM) = 0;

  /**
   * Returns the number of rows occupied by the accessible oject
   * at the specified row and column in the table. The result differs from 1
   * if the specified cell spans multiple rows.
   *
   * @param row  - Row index of the accessible for which to return
   *               the column extent.
   * @param column - Column index of the accessible for which to return
   *                 the column extent.
   */
  /* long getRowExtentAt (in long row, in long column); */
  NS_SCRIPTABLE NS_IMETHOD GetRowExtentAt(PRInt32 row, PRInt32 column, PRInt32 *_retval NS_OUTPARAM) = 0;

  /**
   * Returns the description text of the specified column in the table.
   * @param column - The index of the column for which to retrieve
   *                 the description.
   */
  /* AString getColumnDescription (in long column); */
  NS_SCRIPTABLE NS_IMETHOD GetColumnDescription(PRInt32 column, nsAString & _retval NS_OUTPARAM) = 0;

  /**
   * Returns the description text of the specified row in the table.
   * @param row - The index of the row for which to retrieve the description.
   */
  /* AString getRowDescription (in long row); */
  NS_SCRIPTABLE NS_IMETHOD GetRowDescription(PRInt32 row, nsAString & _retval NS_OUTPARAM) = 0;

  /**
   * Returns a boolean value indicating whether the specified column is
   * completely selected.
   *
   * @param column  - Index of the column for which to determine whether it is
   *                   selected.
   */
  /* boolean isColumnSelected (in long column); */
  NS_SCRIPTABLE NS_IMETHOD IsColumnSelected(PRInt32 column, PRBool *_retval NS_OUTPARAM) = 0;

  /**
   * Returns a boolean value indicating whether the specified row is completely
   * selected.
   *
   * @param row - Index of the row for which to determine whether it is
   *              selected.
   */
  /* boolean isRowSelected (in long row); */
  NS_SCRIPTABLE NS_IMETHOD IsRowSelected(PRInt32 row, PRBool *_retval NS_OUTPARAM) = 0;

  /**
   * Returns a boolean value indicating whether the specified cell is selected.
   *
   * @param row - Index of the row for the cell to determine whether it is
   *              selected.
   * @param column - Index of the column for the cell to determine whether it
   *                 is selected.
   */
  /* boolean isCellSelected (in long row, in long column); */
  NS_SCRIPTABLE NS_IMETHOD IsCellSelected(PRInt32 row, PRInt32 column, PRBool *_retval NS_OUTPARAM) = 0;

  /**
   * Returns the total number of selected cells.
   */
  /* readonly attribute unsigned long selectedCellsCount; */
  NS_SCRIPTABLE NS_IMETHOD GetSelectedCellsCount(PRUint32 *aSelectedCellsCount) = 0;

  /**
   * Returns the total number of selected columns.
   */
  /* readonly attribute unsigned long selectedColumnsCount; */
  NS_SCRIPTABLE NS_IMETHOD GetSelectedColumnsCount(PRUint32 *aSelectedColumnsCount) = 0;

  /**
   * Returns the total number of selected rows.
   */
  /* readonly attribute unsigned long selectedRowsCount; */
  NS_SCRIPTABLE NS_IMETHOD GetSelectedRowsCount(PRUint32 *aSelectedRowsCount) = 0;

  /**
   * Returns a list of cells indexes currently selected.
   *
   * @param cellsSize - length of array
   * @param cells - array of indexes of selected cells
   */
  /* void getSelectedCells (out unsigned long cellsSize, [array, size_is (cellsSize), retval] out long cells); */
  NS_SCRIPTABLE NS_IMETHOD GetSelectedCells(PRUint32 *cellsSize NS_OUTPARAM, PRInt32 **cells NS_OUTPARAM) = 0;

  /**
   * Returns a list of column indexes currently selected.
   *
   * @param columnsSize - Length of array
   * @param columns - Array of indexes of selected columns
   */
  /* void getSelectedColumns (out unsigned long columnsSize, [array, size_is (columnsSize), retval] out long columns); */
  NS_SCRIPTABLE NS_IMETHOD GetSelectedColumns(PRUint32 *columnsSize NS_OUTPARAM, PRInt32 **columns NS_OUTPARAM) = 0;

  /**
   * Returns a list of row indexes currently selected.
   *
   * @param rowsSize - Length of array
   * @param rows - Array of indexes of selected rows
   */
  /* void getSelectedRows (out unsigned long rowsSize, [array, size_is (rowsSize), retval] out long rows); */
  NS_SCRIPTABLE NS_IMETHOD GetSelectedRows(PRUint32 *rowsSize NS_OUTPARAM, PRInt32 **rows NS_OUTPARAM) = 0;

  /**
   * Selects a row and unselects all previously selected rows.
   *
   * @param row - Index of the row to be selected.
   */
  /* void selectRow (in long row); */
  NS_SCRIPTABLE NS_IMETHOD SelectRow(PRInt32 row) = 0;

  /**
   * Selects a column and unselects all previously selected columns.
   *
   * @param column - Index of the column to be selected.
   */
  /* void selectColumn (in long column); */
  NS_SCRIPTABLE NS_IMETHOD SelectColumn(PRInt32 column) = 0;

  /**
   * Unselects one row, leaving other selected rows selected (if any).
   *
   * @param row  - Index of the row to be selected.
  */
  /* void unselectRow (in long row); */
  NS_SCRIPTABLE NS_IMETHOD UnselectRow(PRInt32 row) = 0;

  /**
   * Unselects one column, leaving other selected columns selected (if any).
   *
   * @param column - Index of the column to be selected.
   */
  /* void unselectColumn (in long column); */
  NS_SCRIPTABLE NS_IMETHOD UnselectColumn(PRInt32 column) = 0;

  /**
   * Use heuristics to determine if table is most likely used for layout.
   */
  /* boolean isProbablyForLayout (); */
  NS_SCRIPTABLE NS_IMETHOD IsProbablyForLayout(PRBool *_retval NS_OUTPARAM) = 0;

};

  NS_DEFINE_STATIC_IID_ACCESSOR(nsIAccessibleTable, NS_IACCESSIBLETABLE_IID)

/* Use this macro when declaring classes that implement this interface. */
#define NS_DECL_NSIACCESSIBLETABLE \
  NS_SCRIPTABLE NS_IMETHOD GetCaption(nsIAccessible * *aCaption); \
  NS_SCRIPTABLE NS_IMETHOD GetSummary(nsAString & aSummary); \
  NS_SCRIPTABLE NS_IMETHOD GetColumns(PRInt32 *aColumns); \
  NS_SCRIPTABLE NS_IMETHOD GetColumnHeader(nsIAccessibleTable * *aColumnHeader); \
  NS_SCRIPTABLE NS_IMETHOD GetRows(PRInt32 *aRows); \
  NS_SCRIPTABLE NS_IMETHOD GetRowHeader(nsIAccessibleTable * *aRowHeader); \
  NS_SCRIPTABLE NS_IMETHOD CellRefAt(PRInt32 row, PRInt32 column, nsIAccessible **_retval NS_OUTPARAM); \
  NS_SCRIPTABLE NS_IMETHOD GetIndexAt(PRInt32 row, PRInt32 column, PRInt32 *_retval NS_OUTPARAM); \
  NS_SCRIPTABLE NS_IMETHOD GetColumnAtIndex(PRInt32 index, PRInt32 *_retval NS_OUTPARAM); \
  NS_SCRIPTABLE NS_IMETHOD GetRowAtIndex(PRInt32 index, PRInt32 *_retval NS_OUTPARAM); \
  NS_SCRIPTABLE NS_IMETHOD GetColumnExtentAt(PRInt32 row, PRInt32 column, PRInt32 *_retval NS_OUTPARAM); \
  NS_SCRIPTABLE NS_IMETHOD GetRowExtentAt(PRInt32 row, PRInt32 column, PRInt32 *_retval NS_OUTPARAM); \
  NS_SCRIPTABLE NS_IMETHOD GetColumnDescription(PRInt32 column, nsAString & _retval NS_OUTPARAM); \
  NS_SCRIPTABLE NS_IMETHOD GetRowDescription(PRInt32 row, nsAString & _retval NS_OUTPARAM); \
  NS_SCRIPTABLE NS_IMETHOD IsColumnSelected(PRInt32 column, PRBool *_retval NS_OUTPARAM); \
  NS_SCRIPTABLE NS_IMETHOD IsRowSelected(PRInt32 row, PRBool *_retval NS_OUTPARAM); \
  NS_SCRIPTABLE NS_IMETHOD IsCellSelected(PRInt32 row, PRInt32 column, PRBool *_retval NS_OUTPARAM); \
  NS_SCRIPTABLE NS_IMETHOD GetSelectedCellsCount(PRUint32 *aSelectedCellsCount); \
  NS_SCRIPTABLE NS_IMETHOD GetSelectedColumnsCount(PRUint32 *aSelectedColumnsCount); \
  NS_SCRIPTABLE NS_IMETHOD GetSelectedRowsCount(PRUint32 *aSelectedRowsCount); \
  NS_SCRIPTABLE NS_IMETHOD GetSelectedCells(PRUint32 *cellsSize NS_OUTPARAM, PRInt32 **cells NS_OUTPARAM); \
  NS_SCRIPTABLE NS_IMETHOD GetSelectedColumns(PRUint32 *columnsSize NS_OUTPARAM, PRInt32 **columns NS_OUTPARAM); \
  NS_SCRIPTABLE NS_IMETHOD GetSelectedRows(PRUint32 *rowsSize NS_OUTPARAM, PRInt32 **rows NS_OUTPARAM); \
  NS_SCRIPTABLE NS_IMETHOD SelectRow(PRInt32 row); \
  NS_SCRIPTABLE NS_IMETHOD SelectColumn(PRInt32 column); \
  NS_SCRIPTABLE NS_IMETHOD UnselectRow(PRInt32 row); \
  NS_SCRIPTABLE NS_IMETHOD UnselectColumn(PRInt32 column); \
  NS_SCRIPTABLE NS_IMETHOD IsProbablyForLayout(PRBool *_retval NS_OUTPARAM); 

/* Use this macro to declare functions that forward the behavior of this interface to another object. */
#define NS_FORWARD_NSIACCESSIBLETABLE(_to) \
  NS_SCRIPTABLE NS_IMETHOD GetCaption(nsIAccessible * *aCaption) { return _to GetCaption(aCaption); } \
  NS_SCRIPTABLE NS_IMETHOD GetSummary(nsAString & aSummary) { return _to GetSummary(aSummary); } \
  NS_SCRIPTABLE NS_IMETHOD GetColumns(PRInt32 *aColumns) { return _to GetColumns(aColumns); } \
  NS_SCRIPTABLE NS_IMETHOD GetColumnHeader(nsIAccessibleTable * *aColumnHeader) { return _to GetColumnHeader(aColumnHeader); } \
  NS_SCRIPTABLE NS_IMETHOD GetRows(PRInt32 *aRows) { return _to GetRows(aRows); } \
  NS_SCRIPTABLE NS_IMETHOD GetRowHeader(nsIAccessibleTable * *aRowHeader) { return _to GetRowHeader(aRowHeader); } \
  NS_SCRIPTABLE NS_IMETHOD CellRefAt(PRInt32 row, PRInt32 column, nsIAccessible **_retval NS_OUTPARAM) { return _to CellRefAt(row, column, _retval); } \
  NS_SCRIPTABLE NS_IMETHOD GetIndexAt(PRInt32 row, PRInt32 column, PRInt32 *_retval NS_OUTPARAM) { return _to GetIndexAt(row, column, _retval); } \
  NS_SCRIPTABLE NS_IMETHOD GetColumnAtIndex(PRInt32 index, PRInt32 *_retval NS_OUTPARAM) { return _to GetColumnAtIndex(index, _retval); } \
  NS_SCRIPTABLE NS_IMETHOD GetRowAtIndex(PRInt32 index, PRInt32 *_retval NS_OUTPARAM) { return _to GetRowAtIndex(index, _retval); } \
  NS_SCRIPTABLE NS_IMETHOD GetColumnExtentAt(PRInt32 row, PRInt32 column, PRInt32 *_retval NS_OUTPARAM) { return _to GetColumnExtentAt(row, column, _retval); } \
  NS_SCRIPTABLE NS_IMETHOD GetRowExtentAt(PRInt32 row, PRInt32 column, PRInt32 *_retval NS_OUTPARAM) { return _to GetRowExtentAt(row, column, _retval); } \
  NS_SCRIPTABLE NS_IMETHOD GetColumnDescription(PRInt32 column, nsAString & _retval NS_OUTPARAM) { return _to GetColumnDescription(column, _retval); } \
  NS_SCRIPTABLE NS_IMETHOD GetRowDescription(PRInt32 row, nsAString & _retval NS_OUTPARAM) { return _to GetRowDescription(row, _retval); } \
  NS_SCRIPTABLE NS_IMETHOD IsColumnSelected(PRInt32 column, PRBool *_retval NS_OUTPARAM) { return _to IsColumnSelected(column, _retval); } \
  NS_SCRIPTABLE NS_IMETHOD IsRowSelected(PRInt32 row, PRBool *_retval NS_OUTPARAM) { return _to IsRowSelected(row, _retval); } \
  NS_SCRIPTABLE NS_IMETHOD IsCellSelected(PRInt32 row, PRInt32 column, PRBool *_retval NS_OUTPARAM) { return _to IsCellSelected(row, column, _retval); } \
  NS_SCRIPTABLE NS_IMETHOD GetSelectedCellsCount(PRUint32 *aSelectedCellsCount) { return _to GetSelectedCellsCount(aSelectedCellsCount); } \
  NS_SCRIPTABLE NS_IMETHOD GetSelectedColumnsCount(PRUint32 *aSelectedColumnsCount) { return _to GetSelectedColumnsCount(aSelectedColumnsCount); } \
  NS_SCRIPTABLE NS_IMETHOD GetSelectedRowsCount(PRUint32 *aSelectedRowsCount) { return _to GetSelectedRowsCount(aSelectedRowsCount); } \
  NS_SCRIPTABLE NS_IMETHOD GetSelectedCells(PRUint32 *cellsSize NS_OUTPARAM, PRInt32 **cells NS_OUTPARAM) { return _to GetSelectedCells(cellsSize, cells); } \
  NS_SCRIPTABLE NS_IMETHOD GetSelectedColumns(PRUint32 *columnsSize NS_OUTPARAM, PRInt32 **columns NS_OUTPARAM) { return _to GetSelectedColumns(columnsSize, columns); } \
  NS_SCRIPTABLE NS_IMETHOD GetSelectedRows(PRUint32 *rowsSize NS_OUTPARAM, PRInt32 **rows NS_OUTPARAM) { return _to GetSelectedRows(rowsSize, rows); } \
  NS_SCRIPTABLE NS_IMETHOD SelectRow(PRInt32 row) { return _to SelectRow(row); } \
  NS_SCRIPTABLE NS_IMETHOD SelectColumn(PRInt32 column) { return _to SelectColumn(column); } \
  NS_SCRIPTABLE NS_IMETHOD UnselectRow(PRInt32 row) { return _to UnselectRow(row); } \
  NS_SCRIPTABLE NS_IMETHOD UnselectColumn(PRInt32 column) { return _to UnselectColumn(column); } \
  NS_SCRIPTABLE NS_IMETHOD IsProbablyForLayout(PRBool *_retval NS_OUTPARAM) { return _to IsProbablyForLayout(_retval); } 

/* Use this macro to declare functions that forward the behavior of this interface to another object in a safe way. */
#define NS_FORWARD_SAFE_NSIACCESSIBLETABLE(_to) \
  NS_SCRIPTABLE NS_IMETHOD GetCaption(nsIAccessible * *aCaption) { return !_to ? NS_ERROR_NULL_POINTER : _to->GetCaption(aCaption); } \
  NS_SCRIPTABLE NS_IMETHOD GetSummary(nsAString & aSummary) { return !_to ? NS_ERROR_NULL_POINTER : _to->GetSummary(aSummary); } \
  NS_SCRIPTABLE NS_IMETHOD GetColumns(PRInt32 *aColumns) { return !_to ? NS_ERROR_NULL_POINTER : _to->GetColumns(aColumns); } \
  NS_SCRIPTABLE NS_IMETHOD GetColumnHeader(nsIAccessibleTable * *aColumnHeader) { return !_to ? NS_ERROR_NULL_POINTER : _to->GetColumnHeader(aColumnHeader); } \
  NS_SCRIPTABLE NS_IMETHOD GetRows(PRInt32 *aRows) { return !_to ? NS_ERROR_NULL_POINTER : _to->GetRows(aRows); } \
  NS_SCRIPTABLE NS_IMETHOD GetRowHeader(nsIAccessibleTable * *aRowHeader) { return !_to ? NS_ERROR_NULL_POINTER : _to->GetRowHeader(aRowHeader); } \
  NS_SCRIPTABLE NS_IMETHOD CellRefAt(PRInt32 row, PRInt32 column, nsIAccessible **_retval NS_OUTPARAM) { return !_to ? NS_ERROR_NULL_POINTER : _to->CellRefAt(row, column, _retval); } \
  NS_SCRIPTABLE NS_IMETHOD GetIndexAt(PRInt32 row, PRInt32 column, PRInt32 *_retval NS_OUTPARAM) { return !_to ? NS_ERROR_NULL_POINTER : _to->GetIndexAt(row, column, _retval); } \
  NS_SCRIPTABLE NS_IMETHOD GetColumnAtIndex(PRInt32 index, PRInt32 *_retval NS_OUTPARAM) { return !_to ? NS_ERROR_NULL_POINTER : _to->GetColumnAtIndex(index, _retval); } \
  NS_SCRIPTABLE NS_IMETHOD GetRowAtIndex(PRInt32 index, PRInt32 *_retval NS_OUTPARAM) { return !_to ? NS_ERROR_NULL_POINTER : _to->GetRowAtIndex(index, _retval); } \
  NS_SCRIPTABLE NS_IMETHOD GetColumnExtentAt(PRInt32 row, PRInt32 column, PRInt32 *_retval NS_OUTPARAM) { return !_to ? NS_ERROR_NULL_POINTER : _to->GetColumnExtentAt(row, column, _retval); } \
  NS_SCRIPTABLE NS_IMETHOD GetRowExtentAt(PRInt32 row, PRInt32 column, PRInt32 *_retval NS_OUTPARAM) { return !_to ? NS_ERROR_NULL_POINTER : _to->GetRowExtentAt(row, column, _retval); } \
  NS_SCRIPTABLE NS_IMETHOD GetColumnDescription(PRInt32 column, nsAString & _retval NS_OUTPARAM) { return !_to ? NS_ERROR_NULL_POINTER : _to->GetColumnDescription(column, _retval); } \
  NS_SCRIPTABLE NS_IMETHOD GetRowDescription(PRInt32 row, nsAString & _retval NS_OUTPARAM) { return !_to ? NS_ERROR_NULL_POINTER : _to->GetRowDescription(row, _retval); } \
  NS_SCRIPTABLE NS_IMETHOD IsColumnSelected(PRInt32 column, PRBool *_retval NS_OUTPARAM) { return !_to ? NS_ERROR_NULL_POINTER : _to->IsColumnSelected(column, _retval); } \
  NS_SCRIPTABLE NS_IMETHOD IsRowSelected(PRInt32 row, PRBool *_retval NS_OUTPARAM) { return !_to ? NS_ERROR_NULL_POINTER : _to->IsRowSelected(row, _retval); } \
  NS_SCRIPTABLE NS_IMETHOD IsCellSelected(PRInt32 row, PRInt32 column, PRBool *_retval NS_OUTPARAM) { return !_to ? NS_ERROR_NULL_POINTER : _to->IsCellSelected(row, column, _retval); } \
  NS_SCRIPTABLE NS_IMETHOD GetSelectedCellsCount(PRUint32 *aSelectedCellsCount) { return !_to ? NS_ERROR_NULL_POINTER : _to->GetSelectedCellsCount(aSelectedCellsCount); } \
  NS_SCRIPTABLE NS_IMETHOD GetSelectedColumnsCount(PRUint32 *aSelectedColumnsCount) { return !_to ? NS_ERROR_NULL_POINTER : _to->GetSelectedColumnsCount(aSelectedColumnsCount); } \
  NS_SCRIPTABLE NS_IMETHOD GetSelectedRowsCount(PRUint32 *aSelectedRowsCount) { return !_to ? NS_ERROR_NULL_POINTER : _to->GetSelectedRowsCount(aSelectedRowsCount); } \
  NS_SCRIPTABLE NS_IMETHOD GetSelectedCells(PRUint32 *cellsSize NS_OUTPARAM, PRInt32 **cells NS_OUTPARAM) { return !_to ? NS_ERROR_NULL_POINTER : _to->GetSelectedCells(cellsSize, cells); } \
  NS_SCRIPTABLE NS_IMETHOD GetSelectedColumns(PRUint32 *columnsSize NS_OUTPARAM, PRInt32 **columns NS_OUTPARAM) { return !_to ? NS_ERROR_NULL_POINTER : _to->GetSelectedColumns(columnsSize, columns); } \
  NS_SCRIPTABLE NS_IMETHOD GetSelectedRows(PRUint32 *rowsSize NS_OUTPARAM, PRInt32 **rows NS_OUTPARAM) { return !_to ? NS_ERROR_NULL_POINTER : _to->GetSelectedRows(rowsSize, rows); } \
  NS_SCRIPTABLE NS_IMETHOD SelectRow(PRInt32 row) { return !_to ? NS_ERROR_NULL_POINTER : _to->SelectRow(row); } \
  NS_SCRIPTABLE NS_IMETHOD SelectColumn(PRInt32 column) { return !_to ? NS_ERROR_NULL_POINTER : _to->SelectColumn(column); } \
  NS_SCRIPTABLE NS_IMETHOD UnselectRow(PRInt32 row) { return !_to ? NS_ERROR_NULL_POINTER : _to->UnselectRow(row); } \
  NS_SCRIPTABLE NS_IMETHOD UnselectColumn(PRInt32 column) { return !_to ? NS_ERROR_NULL_POINTER : _to->UnselectColumn(column); } \
  NS_SCRIPTABLE NS_IMETHOD IsProbablyForLayout(PRBool *_retval NS_OUTPARAM) { return !_to ? NS_ERROR_NULL_POINTER : _to->IsProbablyForLayout(_retval); } 

#if 0
/* Use the code below as a template for the implementation class for this interface. */

/* Header file */
class nsAccessibleTable : public nsIAccessibleTable
{
public:
  NS_DECL_ISUPPORTS
  NS_DECL_NSIACCESSIBLETABLE

  nsAccessibleTable();

private:
  ~nsAccessibleTable();

protected:
  /* additional members */
};

/* Implementation file */
NS_IMPL_ISUPPORTS1(nsAccessibleTable, nsIAccessibleTable)

nsAccessibleTable::nsAccessibleTable()
{
  /* member initializers and constructor code */
}

nsAccessibleTable::~nsAccessibleTable()
{
  /* destructor code */
}

/* readonly attribute nsIAccessible caption; */
NS_IMETHODIMP nsAccessibleTable::GetCaption(nsIAccessible * *aCaption)
{
    return NS_ERROR_NOT_IMPLEMENTED;
}

/* readonly attribute AString summary; */
NS_IMETHODIMP nsAccessibleTable::GetSummary(nsAString & aSummary)
{
    return NS_ERROR_NOT_IMPLEMENTED;
}

/* readonly attribute long columns; */
NS_IMETHODIMP nsAccessibleTable::GetColumns(PRInt32 *aColumns)
{
    return NS_ERROR_NOT_IMPLEMENTED;
}

/* readonly attribute nsIAccessibleTable columnHeader; */
NS_IMETHODIMP nsAccessibleTable::GetColumnHeader(nsIAccessibleTable * *aColumnHeader)
{
    return NS_ERROR_NOT_IMPLEMENTED;
}

/* readonly attribute long rows; */
NS_IMETHODIMP nsAccessibleTable::GetRows(PRInt32 *aRows)
{
    return NS_ERROR_NOT_IMPLEMENTED;
}

/* readonly attribute nsIAccessibleTable rowHeader; */
NS_IMETHODIMP nsAccessibleTable::GetRowHeader(nsIAccessibleTable * *aRowHeader)
{
    return NS_ERROR_NOT_IMPLEMENTED;
}

/* nsIAccessible cellRefAt (in long row, in long column); */
NS_IMETHODIMP nsAccessibleTable::CellRefAt(PRInt32 row, PRInt32 column, nsIAccessible **_retval NS_OUTPARAM)
{
    return NS_ERROR_NOT_IMPLEMENTED;
}

/* long getIndexAt (in long row, in long column); */
NS_IMETHODIMP nsAccessibleTable::GetIndexAt(PRInt32 row, PRInt32 column, PRInt32 *_retval NS_OUTPARAM)
{
    return NS_ERROR_NOT_IMPLEMENTED;
}

/* long getColumnAtIndex (in long index); */
NS_IMETHODIMP nsAccessibleTable::GetColumnAtIndex(PRInt32 index, PRInt32 *_retval NS_OUTPARAM)
{
    return NS_ERROR_NOT_IMPLEMENTED;
}

/* long getRowAtIndex (in long index); */
NS_IMETHODIMP nsAccessibleTable::GetRowAtIndex(PRInt32 index, PRInt32 *_retval NS_OUTPARAM)
{
    return NS_ERROR_NOT_IMPLEMENTED;
}

/* long getColumnExtentAt (in long row, in long column); */
NS_IMETHODIMP nsAccessibleTable::GetColumnExtentAt(PRInt32 row, PRInt32 column, PRInt32 *_retval NS_OUTPARAM)
{
    return NS_ERROR_NOT_IMPLEMENTED;
}

/* long getRowExtentAt (in long row, in long column); */
NS_IMETHODIMP nsAccessibleTable::GetRowExtentAt(PRInt32 row, PRInt32 column, PRInt32 *_retval NS_OUTPARAM)
{
    return NS_ERROR_NOT_IMPLEMENTED;
}

/* AString getColumnDescription (in long column); */
NS_IMETHODIMP nsAccessibleTable::GetColumnDescription(PRInt32 column, nsAString & _retval NS_OUTPARAM)
{
    return NS_ERROR_NOT_IMPLEMENTED;
}

/* AString getRowDescription (in long row); */
NS_IMETHODIMP nsAccessibleTable::GetRowDescription(PRInt32 row, nsAString & _retval NS_OUTPARAM)
{
    return NS_ERROR_NOT_IMPLEMENTED;
}

/* boolean isColumnSelected (in long column); */
NS_IMETHODIMP nsAccessibleTable::IsColumnSelected(PRInt32 column, PRBool *_retval NS_OUTPARAM)
{
    return NS_ERROR_NOT_IMPLEMENTED;
}

/* boolean isRowSelected (in long row); */
NS_IMETHODIMP nsAccessibleTable::IsRowSelected(PRInt32 row, PRBool *_retval NS_OUTPARAM)
{
    return NS_ERROR_NOT_IMPLEMENTED;
}

/* boolean isCellSelected (in long row, in long column); */
NS_IMETHODIMP nsAccessibleTable::IsCellSelected(PRInt32 row, PRInt32 column, PRBool *_retval NS_OUTPARAM)
{
    return NS_ERROR_NOT_IMPLEMENTED;
}

/* readonly attribute unsigned long selectedCellsCount; */
NS_IMETHODIMP nsAccessibleTable::GetSelectedCellsCount(PRUint32 *aSelectedCellsCount)
{
    return NS_ERROR_NOT_IMPLEMENTED;
}

/* readonly attribute unsigned long selectedColumnsCount; */
NS_IMETHODIMP nsAccessibleTable::GetSelectedColumnsCount(PRUint32 *aSelectedColumnsCount)
{
    return NS_ERROR_NOT_IMPLEMENTED;
}

/* readonly attribute unsigned long selectedRowsCount; */
NS_IMETHODIMP nsAccessibleTable::GetSelectedRowsCount(PRUint32 *aSelectedRowsCount)
{
    return NS_ERROR_NOT_IMPLEMENTED;
}

/* void getSelectedCells (out unsigned long cellsSize, [array, size_is (cellsSize), retval] out long cells); */
NS_IMETHODIMP nsAccessibleTable::GetSelectedCells(PRUint32 *cellsSize NS_OUTPARAM, PRInt32 **cells NS_OUTPARAM)
{
    return NS_ERROR_NOT_IMPLEMENTED;
}

/* void getSelectedColumns (out unsigned long columnsSize, [array, size_is (columnsSize), retval] out long columns); */
NS_IMETHODIMP nsAccessibleTable::GetSelectedColumns(PRUint32 *columnsSize NS_OUTPARAM, PRInt32 **columns NS_OUTPARAM)
{
    return NS_ERROR_NOT_IMPLEMENTED;
}

/* void getSelectedRows (out unsigned long rowsSize, [array, size_is (rowsSize), retval] out long rows); */
NS_IMETHODIMP nsAccessibleTable::GetSelectedRows(PRUint32 *rowsSize NS_OUTPARAM, PRInt32 **rows NS_OUTPARAM)
{
    return NS_ERROR_NOT_IMPLEMENTED;
}

/* void selectRow (in long row); */
NS_IMETHODIMP nsAccessibleTable::SelectRow(PRInt32 row)
{
    return NS_ERROR_NOT_IMPLEMENTED;
}

/* void selectColumn (in long column); */
NS_IMETHODIMP nsAccessibleTable::SelectColumn(PRInt32 column)
{
    return NS_ERROR_NOT_IMPLEMENTED;
}

/* void unselectRow (in long row); */
NS_IMETHODIMP nsAccessibleTable::UnselectRow(PRInt32 row)
{
    return NS_ERROR_NOT_IMPLEMENTED;
}

/* void unselectColumn (in long column); */
NS_IMETHODIMP nsAccessibleTable::UnselectColumn(PRInt32 column)
{
    return NS_ERROR_NOT_IMPLEMENTED;
}

/* boolean isProbablyForLayout (); */
NS_IMETHODIMP nsAccessibleTable::IsProbablyForLayout(PRBool *_retval NS_OUTPARAM)
{
    return NS_ERROR_NOT_IMPLEMENTED;
}

/* End of implementation class template. */
#endif


#endif /* __gen_nsIAccessibleTable_h__ */
