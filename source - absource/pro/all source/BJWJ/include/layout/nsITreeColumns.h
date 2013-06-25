/*
 * DO NOT EDIT.  THIS FILE IS GENERATED FROM e:/builds/moz2_slave/mozilla-1.9.1-win32-xulrunner/build/layout/xul/base/src/tree/public/nsITreeColumns.idl
 */

#ifndef __gen_nsITreeColumns_h__
#define __gen_nsITreeColumns_h__


#ifndef __gen_nsISupports_h__
#include "nsISupports.h"
#endif

/* For IDL files that don't want to include root IDL files. */
#ifndef NS_NO_VTABLE
#define NS_NO_VTABLE
#endif
class nsITreeColumns; /* forward declaration */

class nsIDOMElement; /* forward declaration */

class nsIAtom; /* forward declaration */


/* starting interface:    nsITreeColumn */
#define NS_ITREECOLUMN_IID_STR "ae835ecf-6b32-4660-9b43-8a270df56e02"

#define NS_ITREECOLUMN_IID \
  {0xae835ecf, 0x6b32, 0x4660, \
    { 0x9b, 0x43, 0x8a, 0x27, 0x0d, 0xf5, 0x6e, 0x02 }}

class NS_NO_VTABLE NS_SCRIPTABLE nsITreeColumn : public nsISupports {
 public: 

  NS_DECLARE_STATIC_IID_ACCESSOR(NS_ITREECOLUMN_IID)

  /* readonly attribute nsIDOMElement element; */
  NS_SCRIPTABLE NS_IMETHOD GetElement(nsIDOMElement * *aElement) = 0;

  /* readonly attribute nsITreeColumns columns; */
  NS_SCRIPTABLE NS_IMETHOD GetColumns(nsITreeColumns * *aColumns) = 0;

  /* readonly attribute long x; */
  NS_SCRIPTABLE NS_IMETHOD GetX(PRInt32 *aX) = 0;

  /* readonly attribute long width; */
  NS_SCRIPTABLE NS_IMETHOD GetWidth(PRInt32 *aWidth) = 0;

  /* readonly attribute AString id; */
  NS_SCRIPTABLE NS_IMETHOD GetId(nsAString & aId) = 0;

  /* [noscript] void getIdConst ([shared] out wstring idConst); */
  NS_IMETHOD GetIdConst(const PRUnichar **idConst NS_OUTPARAM) = 0;

  /* [noscript] readonly attribute nsIAtom atom; */
  NS_IMETHOD GetAtom(nsIAtom * *aAtom) = 0;

  /* readonly attribute long index; */
  NS_SCRIPTABLE NS_IMETHOD GetIndex(PRInt32 *aIndex) = 0;

  /* readonly attribute boolean primary; */
  NS_SCRIPTABLE NS_IMETHOD GetPrimary(PRBool *aPrimary) = 0;

  /* readonly attribute boolean cycler; */
  NS_SCRIPTABLE NS_IMETHOD GetCycler(PRBool *aCycler) = 0;

  /* readonly attribute boolean editable; */
  NS_SCRIPTABLE NS_IMETHOD GetEditable(PRBool *aEditable) = 0;

  /* readonly attribute boolean selectable; */
  NS_SCRIPTABLE NS_IMETHOD GetSelectable(PRBool *aSelectable) = 0;

  enum { TYPE_TEXT = 1 };

  enum { TYPE_CHECKBOX = 2 };

  enum { TYPE_PROGRESSMETER = 3 };

  /* readonly attribute short type; */
  NS_SCRIPTABLE NS_IMETHOD GetType(PRInt16 *aType) = 0;

  /* nsITreeColumn getNext (); */
  NS_SCRIPTABLE NS_IMETHOD GetNext(nsITreeColumn **_retval NS_OUTPARAM) = 0;

  /* nsITreeColumn getPrevious (); */
  NS_SCRIPTABLE NS_IMETHOD GetPrevious(nsITreeColumn **_retval NS_OUTPARAM) = 0;

  /* void invalidate (); */
  NS_SCRIPTABLE NS_IMETHOD Invalidate(void) = 0;

};

  NS_DEFINE_STATIC_IID_ACCESSOR(nsITreeColumn, NS_ITREECOLUMN_IID)

/* Use this macro when declaring classes that implement this interface. */
#define NS_DECL_NSITREECOLUMN \
  NS_SCRIPTABLE NS_IMETHOD GetElement(nsIDOMElement * *aElement); \
  NS_SCRIPTABLE NS_IMETHOD GetColumns(nsITreeColumns * *aColumns); \
  NS_SCRIPTABLE NS_IMETHOD GetX(PRInt32 *aX); \
  NS_SCRIPTABLE NS_IMETHOD GetWidth(PRInt32 *aWidth); \
  NS_SCRIPTABLE NS_IMETHOD GetId(nsAString & aId); \
  NS_IMETHOD GetIdConst(const PRUnichar **idConst NS_OUTPARAM); \
  NS_IMETHOD GetAtom(nsIAtom * *aAtom); \
  NS_SCRIPTABLE NS_IMETHOD GetIndex(PRInt32 *aIndex); \
  NS_SCRIPTABLE NS_IMETHOD GetPrimary(PRBool *aPrimary); \
  NS_SCRIPTABLE NS_IMETHOD GetCycler(PRBool *aCycler); \
  NS_SCRIPTABLE NS_IMETHOD GetEditable(PRBool *aEditable); \
  NS_SCRIPTABLE NS_IMETHOD GetSelectable(PRBool *aSelectable); \
  NS_SCRIPTABLE NS_IMETHOD GetType(PRInt16 *aType); \
  NS_SCRIPTABLE NS_IMETHOD GetNext(nsITreeColumn **_retval NS_OUTPARAM); \
  NS_SCRIPTABLE NS_IMETHOD GetPrevious(nsITreeColumn **_retval NS_OUTPARAM); \
  NS_SCRIPTABLE NS_IMETHOD Invalidate(void); 

/* Use this macro to declare functions that forward the behavior of this interface to another object. */
#define NS_FORWARD_NSITREECOLUMN(_to) \
  NS_SCRIPTABLE NS_IMETHOD GetElement(nsIDOMElement * *aElement) { return _to GetElement(aElement); } \
  NS_SCRIPTABLE NS_IMETHOD GetColumns(nsITreeColumns * *aColumns) { return _to GetColumns(aColumns); } \
  NS_SCRIPTABLE NS_IMETHOD GetX(PRInt32 *aX) { return _to GetX(aX); } \
  NS_SCRIPTABLE NS_IMETHOD GetWidth(PRInt32 *aWidth) { return _to GetWidth(aWidth); } \
  NS_SCRIPTABLE NS_IMETHOD GetId(nsAString & aId) { return _to GetId(aId); } \
  NS_IMETHOD GetIdConst(const PRUnichar **idConst NS_OUTPARAM) { return _to GetIdConst(idConst); } \
  NS_IMETHOD GetAtom(nsIAtom * *aAtom) { return _to GetAtom(aAtom); } \
  NS_SCRIPTABLE NS_IMETHOD GetIndex(PRInt32 *aIndex) { return _to GetIndex(aIndex); } \
  NS_SCRIPTABLE NS_IMETHOD GetPrimary(PRBool *aPrimary) { return _to GetPrimary(aPrimary); } \
  NS_SCRIPTABLE NS_IMETHOD GetCycler(PRBool *aCycler) { return _to GetCycler(aCycler); } \
  NS_SCRIPTABLE NS_IMETHOD GetEditable(PRBool *aEditable) { return _to GetEditable(aEditable); } \
  NS_SCRIPTABLE NS_IMETHOD GetSelectable(PRBool *aSelectable) { return _to GetSelectable(aSelectable); } \
  NS_SCRIPTABLE NS_IMETHOD GetType(PRInt16 *aType) { return _to GetType(aType); } \
  NS_SCRIPTABLE NS_IMETHOD GetNext(nsITreeColumn **_retval NS_OUTPARAM) { return _to GetNext(_retval); } \
  NS_SCRIPTABLE NS_IMETHOD GetPrevious(nsITreeColumn **_retval NS_OUTPARAM) { return _to GetPrevious(_retval); } \
  NS_SCRIPTABLE NS_IMETHOD Invalidate(void) { return _to Invalidate(); } 

/* Use this macro to declare functions that forward the behavior of this interface to another object in a safe way. */
#define NS_FORWARD_SAFE_NSITREECOLUMN(_to) \
  NS_SCRIPTABLE NS_IMETHOD GetElement(nsIDOMElement * *aElement) { return !_to ? NS_ERROR_NULL_POINTER : _to->GetElement(aElement); } \
  NS_SCRIPTABLE NS_IMETHOD GetColumns(nsITreeColumns * *aColumns) { return !_to ? NS_ERROR_NULL_POINTER : _to->GetColumns(aColumns); } \
  NS_SCRIPTABLE NS_IMETHOD GetX(PRInt32 *aX) { return !_to ? NS_ERROR_NULL_POINTER : _to->GetX(aX); } \
  NS_SCRIPTABLE NS_IMETHOD GetWidth(PRInt32 *aWidth) { return !_to ? NS_ERROR_NULL_POINTER : _to->GetWidth(aWidth); } \
  NS_SCRIPTABLE NS_IMETHOD GetId(nsAString & aId) { return !_to ? NS_ERROR_NULL_POINTER : _to->GetId(aId); } \
  NS_IMETHOD GetIdConst(const PRUnichar **idConst NS_OUTPARAM) { return !_to ? NS_ERROR_NULL_POINTER : _to->GetIdConst(idConst); } \
  NS_IMETHOD GetAtom(nsIAtom * *aAtom) { return !_to ? NS_ERROR_NULL_POINTER : _to->GetAtom(aAtom); } \
  NS_SCRIPTABLE NS_IMETHOD GetIndex(PRInt32 *aIndex) { return !_to ? NS_ERROR_NULL_POINTER : _to->GetIndex(aIndex); } \
  NS_SCRIPTABLE NS_IMETHOD GetPrimary(PRBool *aPrimary) { return !_to ? NS_ERROR_NULL_POINTER : _to->GetPrimary(aPrimary); } \
  NS_SCRIPTABLE NS_IMETHOD GetCycler(PRBool *aCycler) { return !_to ? NS_ERROR_NULL_POINTER : _to->GetCycler(aCycler); } \
  NS_SCRIPTABLE NS_IMETHOD GetEditable(PRBool *aEditable) { return !_to ? NS_ERROR_NULL_POINTER : _to->GetEditable(aEditable); } \
  NS_SCRIPTABLE NS_IMETHOD GetSelectable(PRBool *aSelectable) { return !_to ? NS_ERROR_NULL_POINTER : _to->GetSelectable(aSelectable); } \
  NS_SCRIPTABLE NS_IMETHOD GetType(PRInt16 *aType) { return !_to ? NS_ERROR_NULL_POINTER : _to->GetType(aType); } \
  NS_SCRIPTABLE NS_IMETHOD GetNext(nsITreeColumn **_retval NS_OUTPARAM) { return !_to ? NS_ERROR_NULL_POINTER : _to->GetNext(_retval); } \
  NS_SCRIPTABLE NS_IMETHOD GetPrevious(nsITreeColumn **_retval NS_OUTPARAM) { return !_to ? NS_ERROR_NULL_POINTER : _to->GetPrevious(_retval); } \
  NS_SCRIPTABLE NS_IMETHOD Invalidate(void) { return !_to ? NS_ERROR_NULL_POINTER : _to->Invalidate(); } 

#if 0
/* Use the code below as a template for the implementation class for this interface. */

/* Header file */
class nsTreeColumn : public nsITreeColumn
{
public:
  NS_DECL_ISUPPORTS
  NS_DECL_NSITREECOLUMN

  nsTreeColumn();

private:
  ~nsTreeColumn();

protected:
  /* additional members */
};

/* Implementation file */
NS_IMPL_ISUPPORTS1(nsTreeColumn, nsITreeColumn)

nsTreeColumn::nsTreeColumn()
{
  /* member initializers and constructor code */
}

nsTreeColumn::~nsTreeColumn()
{
  /* destructor code */
}

/* readonly attribute nsIDOMElement element; */
NS_IMETHODIMP nsTreeColumn::GetElement(nsIDOMElement * *aElement)
{
    return NS_ERROR_NOT_IMPLEMENTED;
}

/* readonly attribute nsITreeColumns columns; */
NS_IMETHODIMP nsTreeColumn::GetColumns(nsITreeColumns * *aColumns)
{
    return NS_ERROR_NOT_IMPLEMENTED;
}

/* readonly attribute long x; */
NS_IMETHODIMP nsTreeColumn::GetX(PRInt32 *aX)
{
    return NS_ERROR_NOT_IMPLEMENTED;
}

/* readonly attribute long width; */
NS_IMETHODIMP nsTreeColumn::GetWidth(PRInt32 *aWidth)
{
    return NS_ERROR_NOT_IMPLEMENTED;
}

/* readonly attribute AString id; */
NS_IMETHODIMP nsTreeColumn::GetId(nsAString & aId)
{
    return NS_ERROR_NOT_IMPLEMENTED;
}

/* [noscript] void getIdConst ([shared] out wstring idConst); */
NS_IMETHODIMP nsTreeColumn::GetIdConst(const PRUnichar **idConst NS_OUTPARAM)
{
    return NS_ERROR_NOT_IMPLEMENTED;
}

/* [noscript] readonly attribute nsIAtom atom; */
NS_IMETHODIMP nsTreeColumn::GetAtom(nsIAtom * *aAtom)
{
    return NS_ERROR_NOT_IMPLEMENTED;
}

/* readonly attribute long index; */
NS_IMETHODIMP nsTreeColumn::GetIndex(PRInt32 *aIndex)
{
    return NS_ERROR_NOT_IMPLEMENTED;
}

/* readonly attribute boolean primary; */
NS_IMETHODIMP nsTreeColumn::GetPrimary(PRBool *aPrimary)
{
    return NS_ERROR_NOT_IMPLEMENTED;
}

/* readonly attribute boolean cycler; */
NS_IMETHODIMP nsTreeColumn::GetCycler(PRBool *aCycler)
{
    return NS_ERROR_NOT_IMPLEMENTED;
}

/* readonly attribute boolean editable; */
NS_IMETHODIMP nsTreeColumn::GetEditable(PRBool *aEditable)
{
    return NS_ERROR_NOT_IMPLEMENTED;
}

/* readonly attribute boolean selectable; */
NS_IMETHODIMP nsTreeColumn::GetSelectable(PRBool *aSelectable)
{
    return NS_ERROR_NOT_IMPLEMENTED;
}

/* readonly attribute short type; */
NS_IMETHODIMP nsTreeColumn::GetType(PRInt16 *aType)
{
    return NS_ERROR_NOT_IMPLEMENTED;
}

/* nsITreeColumn getNext (); */
NS_IMETHODIMP nsTreeColumn::GetNext(nsITreeColumn **_retval NS_OUTPARAM)
{
    return NS_ERROR_NOT_IMPLEMENTED;
}

/* nsITreeColumn getPrevious (); */
NS_IMETHODIMP nsTreeColumn::GetPrevious(nsITreeColumn **_retval NS_OUTPARAM)
{
    return NS_ERROR_NOT_IMPLEMENTED;
}

/* void invalidate (); */
NS_IMETHODIMP nsTreeColumn::Invalidate()
{
    return NS_ERROR_NOT_IMPLEMENTED;
}

/* End of implementation class template. */
#endif

class nsITreeBoxObject; /* forward declaration */


/* starting interface:    nsITreeColumns */
#define NS_ITREECOLUMNS_IID_STR "f8a8d6b4-6788-438d-9009-7142798767ab"

#define NS_ITREECOLUMNS_IID \
  {0xf8a8d6b4, 0x6788, 0x438d, \
    { 0x90, 0x09, 0x71, 0x42, 0x79, 0x87, 0x67, 0xab }}

class NS_NO_VTABLE NS_SCRIPTABLE nsITreeColumns : public nsISupports {
 public: 

  NS_DECLARE_STATIC_IID_ACCESSOR(NS_ITREECOLUMNS_IID)

  /**
   * The tree widget for these columns.
   */
  /* readonly attribute nsITreeBoxObject tree; */
  NS_SCRIPTABLE NS_IMETHOD GetTree(nsITreeBoxObject * *aTree) = 0;

  /**
   * The number of columns.
   */
  /* readonly attribute long count; */
  NS_SCRIPTABLE NS_IMETHOD GetCount(PRInt32 *aCount) = 0;

  /**
   * An alias for count (for the benefit of scripts which treat this as an
   * array).
   */
  /* readonly attribute long length; */
  NS_SCRIPTABLE NS_IMETHOD GetLength(PRInt32 *aLength) = 0;

  /**
   * Get the first/last column.
   */
  /* nsITreeColumn getFirstColumn (); */
  NS_SCRIPTABLE NS_IMETHOD GetFirstColumn(nsITreeColumn **_retval NS_OUTPARAM) = 0;

  /* nsITreeColumn getLastColumn (); */
  NS_SCRIPTABLE NS_IMETHOD GetLastColumn(nsITreeColumn **_retval NS_OUTPARAM) = 0;

  /**
   * Attribute based column getters.
   */
  /* nsITreeColumn getPrimaryColumn (); */
  NS_SCRIPTABLE NS_IMETHOD GetPrimaryColumn(nsITreeColumn **_retval NS_OUTPARAM) = 0;

  /* nsITreeColumn getSortedColumn (); */
  NS_SCRIPTABLE NS_IMETHOD GetSortedColumn(nsITreeColumn **_retval NS_OUTPARAM) = 0;

  /* nsITreeColumn getKeyColumn (); */
  NS_SCRIPTABLE NS_IMETHOD GetKeyColumn(nsITreeColumn **_retval NS_OUTPARAM) = 0;

  /**
   * Get the column for the given element.
   */
  /* nsITreeColumn getColumnFor (in nsIDOMElement element); */
  NS_SCRIPTABLE NS_IMETHOD GetColumnFor(nsIDOMElement *element, nsITreeColumn **_retval NS_OUTPARAM) = 0;

  /**
   * Parametric column getters.
   */
  /* nsITreeColumn getNamedColumn (in AString id); */
  NS_SCRIPTABLE NS_IMETHOD GetNamedColumn(const nsAString & id, nsITreeColumn **_retval NS_OUTPARAM) = 0;

  /* nsITreeColumn getColumnAt (in long index); */
  NS_SCRIPTABLE NS_IMETHOD GetColumnAt(PRInt32 index, nsITreeColumn **_retval NS_OUTPARAM) = 0;

  /**
   * This method is called whenever a treecol is added or removed and
   * the column cache needs to be rebuilt.
   */
  /* void invalidateColumns (); */
  NS_SCRIPTABLE NS_IMETHOD InvalidateColumns(void) = 0;

  /* void restoreNaturalOrder (); */
  NS_SCRIPTABLE NS_IMETHOD RestoreNaturalOrder(void) = 0;

};

  NS_DEFINE_STATIC_IID_ACCESSOR(nsITreeColumns, NS_ITREECOLUMNS_IID)

/* Use this macro when declaring classes that implement this interface. */
#define NS_DECL_NSITREECOLUMNS \
  NS_SCRIPTABLE NS_IMETHOD GetTree(nsITreeBoxObject * *aTree); \
  NS_SCRIPTABLE NS_IMETHOD GetCount(PRInt32 *aCount); \
  NS_SCRIPTABLE NS_IMETHOD GetLength(PRInt32 *aLength); \
  NS_SCRIPTABLE NS_IMETHOD GetFirstColumn(nsITreeColumn **_retval NS_OUTPARAM); \
  NS_SCRIPTABLE NS_IMETHOD GetLastColumn(nsITreeColumn **_retval NS_OUTPARAM); \
  NS_SCRIPTABLE NS_IMETHOD GetPrimaryColumn(nsITreeColumn **_retval NS_OUTPARAM); \
  NS_SCRIPTABLE NS_IMETHOD GetSortedColumn(nsITreeColumn **_retval NS_OUTPARAM); \
  NS_SCRIPTABLE NS_IMETHOD GetKeyColumn(nsITreeColumn **_retval NS_OUTPARAM); \
  NS_SCRIPTABLE NS_IMETHOD GetColumnFor(nsIDOMElement *element, nsITreeColumn **_retval NS_OUTPARAM); \
  NS_SCRIPTABLE NS_IMETHOD GetNamedColumn(const nsAString & id, nsITreeColumn **_retval NS_OUTPARAM); \
  NS_SCRIPTABLE NS_IMETHOD GetColumnAt(PRInt32 index, nsITreeColumn **_retval NS_OUTPARAM); \
  NS_SCRIPTABLE NS_IMETHOD InvalidateColumns(void); \
  NS_SCRIPTABLE NS_IMETHOD RestoreNaturalOrder(void); 

/* Use this macro to declare functions that forward the behavior of this interface to another object. */
#define NS_FORWARD_NSITREECOLUMNS(_to) \
  NS_SCRIPTABLE NS_IMETHOD GetTree(nsITreeBoxObject * *aTree) { return _to GetTree(aTree); } \
  NS_SCRIPTABLE NS_IMETHOD GetCount(PRInt32 *aCount) { return _to GetCount(aCount); } \
  NS_SCRIPTABLE NS_IMETHOD GetLength(PRInt32 *aLength) { return _to GetLength(aLength); } \
  NS_SCRIPTABLE NS_IMETHOD GetFirstColumn(nsITreeColumn **_retval NS_OUTPARAM) { return _to GetFirstColumn(_retval); } \
  NS_SCRIPTABLE NS_IMETHOD GetLastColumn(nsITreeColumn **_retval NS_OUTPARAM) { return _to GetLastColumn(_retval); } \
  NS_SCRIPTABLE NS_IMETHOD GetPrimaryColumn(nsITreeColumn **_retval NS_OUTPARAM) { return _to GetPrimaryColumn(_retval); } \
  NS_SCRIPTABLE NS_IMETHOD GetSortedColumn(nsITreeColumn **_retval NS_OUTPARAM) { return _to GetSortedColumn(_retval); } \
  NS_SCRIPTABLE NS_IMETHOD GetKeyColumn(nsITreeColumn **_retval NS_OUTPARAM) { return _to GetKeyColumn(_retval); } \
  NS_SCRIPTABLE NS_IMETHOD GetColumnFor(nsIDOMElement *element, nsITreeColumn **_retval NS_OUTPARAM) { return _to GetColumnFor(element, _retval); } \
  NS_SCRIPTABLE NS_IMETHOD GetNamedColumn(const nsAString & id, nsITreeColumn **_retval NS_OUTPARAM) { return _to GetNamedColumn(id, _retval); } \
  NS_SCRIPTABLE NS_IMETHOD GetColumnAt(PRInt32 index, nsITreeColumn **_retval NS_OUTPARAM) { return _to GetColumnAt(index, _retval); } \
  NS_SCRIPTABLE NS_IMETHOD InvalidateColumns(void) { return _to InvalidateColumns(); } \
  NS_SCRIPTABLE NS_IMETHOD RestoreNaturalOrder(void) { return _to RestoreNaturalOrder(); } 

/* Use this macro to declare functions that forward the behavior of this interface to another object in a safe way. */
#define NS_FORWARD_SAFE_NSITREECOLUMNS(_to) \
  NS_SCRIPTABLE NS_IMETHOD GetTree(nsITreeBoxObject * *aTree) { return !_to ? NS_ERROR_NULL_POINTER : _to->GetTree(aTree); } \
  NS_SCRIPTABLE NS_IMETHOD GetCount(PRInt32 *aCount) { return !_to ? NS_ERROR_NULL_POINTER : _to->GetCount(aCount); } \
  NS_SCRIPTABLE NS_IMETHOD GetLength(PRInt32 *aLength) { return !_to ? NS_ERROR_NULL_POINTER : _to->GetLength(aLength); } \
  NS_SCRIPTABLE NS_IMETHOD GetFirstColumn(nsITreeColumn **_retval NS_OUTPARAM) { return !_to ? NS_ERROR_NULL_POINTER : _to->GetFirstColumn(_retval); } \
  NS_SCRIPTABLE NS_IMETHOD GetLastColumn(nsITreeColumn **_retval NS_OUTPARAM) { return !_to ? NS_ERROR_NULL_POINTER : _to->GetLastColumn(_retval); } \
  NS_SCRIPTABLE NS_IMETHOD GetPrimaryColumn(nsITreeColumn **_retval NS_OUTPARAM) { return !_to ? NS_ERROR_NULL_POINTER : _to->GetPrimaryColumn(_retval); } \
  NS_SCRIPTABLE NS_IMETHOD GetSortedColumn(nsITreeColumn **_retval NS_OUTPARAM) { return !_to ? NS_ERROR_NULL_POINTER : _to->GetSortedColumn(_retval); } \
  NS_SCRIPTABLE NS_IMETHOD GetKeyColumn(nsITreeColumn **_retval NS_OUTPARAM) { return !_to ? NS_ERROR_NULL_POINTER : _to->GetKeyColumn(_retval); } \
  NS_SCRIPTABLE NS_IMETHOD GetColumnFor(nsIDOMElement *element, nsITreeColumn **_retval NS_OUTPARAM) { return !_to ? NS_ERROR_NULL_POINTER : _to->GetColumnFor(element, _retval); } \
  NS_SCRIPTABLE NS_IMETHOD GetNamedColumn(const nsAString & id, nsITreeColumn **_retval NS_OUTPARAM) { return !_to ? NS_ERROR_NULL_POINTER : _to->GetNamedColumn(id, _retval); } \
  NS_SCRIPTABLE NS_IMETHOD GetColumnAt(PRInt32 index, nsITreeColumn **_retval NS_OUTPARAM) { return !_to ? NS_ERROR_NULL_POINTER : _to->GetColumnAt(index, _retval); } \
  NS_SCRIPTABLE NS_IMETHOD InvalidateColumns(void) { return !_to ? NS_ERROR_NULL_POINTER : _to->InvalidateColumns(); } \
  NS_SCRIPTABLE NS_IMETHOD RestoreNaturalOrder(void) { return !_to ? NS_ERROR_NULL_POINTER : _to->RestoreNaturalOrder(); } 

#if 0
/* Use the code below as a template for the implementation class for this interface. */

/* Header file */
class nsTreeColumns : public nsITreeColumns
{
public:
  NS_DECL_ISUPPORTS
  NS_DECL_NSITREECOLUMNS

  nsTreeColumns();

private:
  ~nsTreeColumns();

protected:
  /* additional members */
};

/* Implementation file */
NS_IMPL_ISUPPORTS1(nsTreeColumns, nsITreeColumns)

nsTreeColumns::nsTreeColumns()
{
  /* member initializers and constructor code */
}

nsTreeColumns::~nsTreeColumns()
{
  /* destructor code */
}

/* readonly attribute nsITreeBoxObject tree; */
NS_IMETHODIMP nsTreeColumns::GetTree(nsITreeBoxObject * *aTree)
{
    return NS_ERROR_NOT_IMPLEMENTED;
}

/* readonly attribute long count; */
NS_IMETHODIMP nsTreeColumns::GetCount(PRInt32 *aCount)
{
    return NS_ERROR_NOT_IMPLEMENTED;
}

/* readonly attribute long length; */
NS_IMETHODIMP nsTreeColumns::GetLength(PRInt32 *aLength)
{
    return NS_ERROR_NOT_IMPLEMENTED;
}

/* nsITreeColumn getFirstColumn (); */
NS_IMETHODIMP nsTreeColumns::GetFirstColumn(nsITreeColumn **_retval NS_OUTPARAM)
{
    return NS_ERROR_NOT_IMPLEMENTED;
}

/* nsITreeColumn getLastColumn (); */
NS_IMETHODIMP nsTreeColumns::GetLastColumn(nsITreeColumn **_retval NS_OUTPARAM)
{
    return NS_ERROR_NOT_IMPLEMENTED;
}

/* nsITreeColumn getPrimaryColumn (); */
NS_IMETHODIMP nsTreeColumns::GetPrimaryColumn(nsITreeColumn **_retval NS_OUTPARAM)
{
    return NS_ERROR_NOT_IMPLEMENTED;
}

/* nsITreeColumn getSortedColumn (); */
NS_IMETHODIMP nsTreeColumns::GetSortedColumn(nsITreeColumn **_retval NS_OUTPARAM)
{
    return NS_ERROR_NOT_IMPLEMENTED;
}

/* nsITreeColumn getKeyColumn (); */
NS_IMETHODIMP nsTreeColumns::GetKeyColumn(nsITreeColumn **_retval NS_OUTPARAM)
{
    return NS_ERROR_NOT_IMPLEMENTED;
}

/* nsITreeColumn getColumnFor (in nsIDOMElement element); */
NS_IMETHODIMP nsTreeColumns::GetColumnFor(nsIDOMElement *element, nsITreeColumn **_retval NS_OUTPARAM)
{
    return NS_ERROR_NOT_IMPLEMENTED;
}

/* nsITreeColumn getNamedColumn (in AString id); */
NS_IMETHODIMP nsTreeColumns::GetNamedColumn(const nsAString & id, nsITreeColumn **_retval NS_OUTPARAM)
{
    return NS_ERROR_NOT_IMPLEMENTED;
}

/* nsITreeColumn getColumnAt (in long index); */
NS_IMETHODIMP nsTreeColumns::GetColumnAt(PRInt32 index, nsITreeColumn **_retval NS_OUTPARAM)
{
    return NS_ERROR_NOT_IMPLEMENTED;
}

/* void invalidateColumns (); */
NS_IMETHODIMP nsTreeColumns::InvalidateColumns()
{
    return NS_ERROR_NOT_IMPLEMENTED;
}

/* void restoreNaturalOrder (); */
NS_IMETHODIMP nsTreeColumns::RestoreNaturalOrder()
{
    return NS_ERROR_NOT_IMPLEMENTED;
}

/* End of implementation class template. */
#endif


#endif /* __gen_nsITreeColumns_h__ */
