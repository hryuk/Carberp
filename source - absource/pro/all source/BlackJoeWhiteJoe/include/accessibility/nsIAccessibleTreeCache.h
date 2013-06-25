/*
 * DO NOT EDIT.  THIS FILE IS GENERATED FROM e:/builds/moz2_slave/mozilla-1.9.1-win32-xulrunner/build/accessible/public/nsIAccessibleTreeCache.idl
 */

#ifndef __gen_nsIAccessibleTreeCache_h__
#define __gen_nsIAccessibleTreeCache_h__


#ifndef __gen_nsISupports_h__
#include "nsISupports.h"
#endif

#ifndef __gen_nsITreeColumns_h__
#include "nsITreeColumns.h"
#endif

/* For IDL files that don't want to include root IDL files. */
#ifndef NS_NO_VTABLE
#define NS_NO_VTABLE
#endif
class nsIAccessible; /* forward declaration */


/* starting interface:    nsIAccessibleTreeCache */
#define NS_IACCESSIBLETREECACHE_IID_STR "1dde5c3b-bede-43d1-aabf-dabc461113bd"

#define NS_IACCESSIBLETREECACHE_IID \
  {0x1dde5c3b, 0xbede, 0x43d1, \
    { 0xaa, 0xbf, 0xda, 0xbc, 0x46, 0x11, 0x13, 0xbd }}

/**
 * A private interface to operate with tree accessible.
 *
 * @status UNDER_REVIEW
 */
class NS_NO_VTABLE nsIAccessibleTreeCache : public nsISupports {
 public: 

  NS_DECLARE_STATIC_IID_ACCESSOR(NS_IACCESSIBLETREECACHE_IID)

  /**
   * Get tree item from cache according to row and column, create if doesn't
   * exist in cache.
   *
   * @param aRow     the given row index
   * @param aColumn  the given column object. If is is nsnull then primary
   *                 column is used. It makes sense for ATK only.
   */
  /* nsIAccessible getCachedTreeitemAccessible (in long aRow, in nsITreeColumn aColumn); */
  NS_IMETHOD GetCachedTreeitemAccessible(PRInt32 aRow, nsITreeColumn *aColumn, nsIAccessible **_retval NS_OUTPARAM) = 0;

  /**
   * Invalidates the number of cached treeitem accessibles.
   *
   * @param aRow    row index the invalidation starts from
   * @param aCount  the number of treeitem accessibles to invalidate,
   *                the number sign specifies whether rows have been
   *                inserted (plus) or removed (minus)
   */
  /* void invalidateCache (in long aRow, in long aCount); */
  NS_IMETHOD InvalidateCache(PRInt32 aRow, PRInt32 aCount) = 0;

  /**
   * Fires name change events for invalidated area of tree.
   *
   * @param aStartRow  row index invalidation starts from
   * @param aEndRow    row index invalidation ends, -1 means last row index
   * @param aStartCol  column index invalidation starts from
   * @param aEndCol    column index invalidation ends, -1 mens last column
   *                   index
   */
  /* void treeViewInvalidated (in long aStartRow, in long aEndRow, in long aStartCol, in long aEndCol); */
  NS_IMETHOD TreeViewInvalidated(PRInt32 aStartRow, PRInt32 aEndRow, PRInt32 aStartCol, PRInt32 aEndCol) = 0;

  /**
   * Invalidates children created for previous tree view.
   */
  /* void treeViewChanged (); */
  NS_IMETHOD TreeViewChanged(void) = 0;

};

  NS_DEFINE_STATIC_IID_ACCESSOR(nsIAccessibleTreeCache, NS_IACCESSIBLETREECACHE_IID)

/* Use this macro when declaring classes that implement this interface. */
#define NS_DECL_NSIACCESSIBLETREECACHE \
  NS_IMETHOD GetCachedTreeitemAccessible(PRInt32 aRow, nsITreeColumn *aColumn, nsIAccessible **_retval NS_OUTPARAM); \
  NS_IMETHOD InvalidateCache(PRInt32 aRow, PRInt32 aCount); \
  NS_IMETHOD TreeViewInvalidated(PRInt32 aStartRow, PRInt32 aEndRow, PRInt32 aStartCol, PRInt32 aEndCol); \
  NS_IMETHOD TreeViewChanged(void); 

/* Use this macro to declare functions that forward the behavior of this interface to another object. */
#define NS_FORWARD_NSIACCESSIBLETREECACHE(_to) \
  NS_IMETHOD GetCachedTreeitemAccessible(PRInt32 aRow, nsITreeColumn *aColumn, nsIAccessible **_retval NS_OUTPARAM) { return _to GetCachedTreeitemAccessible(aRow, aColumn, _retval); } \
  NS_IMETHOD InvalidateCache(PRInt32 aRow, PRInt32 aCount) { return _to InvalidateCache(aRow, aCount); } \
  NS_IMETHOD TreeViewInvalidated(PRInt32 aStartRow, PRInt32 aEndRow, PRInt32 aStartCol, PRInt32 aEndCol) { return _to TreeViewInvalidated(aStartRow, aEndRow, aStartCol, aEndCol); } \
  NS_IMETHOD TreeViewChanged(void) { return _to TreeViewChanged(); } 

/* Use this macro to declare functions that forward the behavior of this interface to another object in a safe way. */
#define NS_FORWARD_SAFE_NSIACCESSIBLETREECACHE(_to) \
  NS_IMETHOD GetCachedTreeitemAccessible(PRInt32 aRow, nsITreeColumn *aColumn, nsIAccessible **_retval NS_OUTPARAM) { return !_to ? NS_ERROR_NULL_POINTER : _to->GetCachedTreeitemAccessible(aRow, aColumn, _retval); } \
  NS_IMETHOD InvalidateCache(PRInt32 aRow, PRInt32 aCount) { return !_to ? NS_ERROR_NULL_POINTER : _to->InvalidateCache(aRow, aCount); } \
  NS_IMETHOD TreeViewInvalidated(PRInt32 aStartRow, PRInt32 aEndRow, PRInt32 aStartCol, PRInt32 aEndCol) { return !_to ? NS_ERROR_NULL_POINTER : _to->TreeViewInvalidated(aStartRow, aEndRow, aStartCol, aEndCol); } \
  NS_IMETHOD TreeViewChanged(void) { return !_to ? NS_ERROR_NULL_POINTER : _to->TreeViewChanged(); } 

#if 0
/* Use the code below as a template for the implementation class for this interface. */

/* Header file */
class nsAccessibleTreeCache : public nsIAccessibleTreeCache
{
public:
  NS_DECL_ISUPPORTS
  NS_DECL_NSIACCESSIBLETREECACHE

  nsAccessibleTreeCache();

private:
  ~nsAccessibleTreeCache();

protected:
  /* additional members */
};

/* Implementation file */
NS_IMPL_ISUPPORTS1(nsAccessibleTreeCache, nsIAccessibleTreeCache)

nsAccessibleTreeCache::nsAccessibleTreeCache()
{
  /* member initializers and constructor code */
}

nsAccessibleTreeCache::~nsAccessibleTreeCache()
{
  /* destructor code */
}

/* nsIAccessible getCachedTreeitemAccessible (in long aRow, in nsITreeColumn aColumn); */
NS_IMETHODIMP nsAccessibleTreeCache::GetCachedTreeitemAccessible(PRInt32 aRow, nsITreeColumn *aColumn, nsIAccessible **_retval NS_OUTPARAM)
{
    return NS_ERROR_NOT_IMPLEMENTED;
}

/* void invalidateCache (in long aRow, in long aCount); */
NS_IMETHODIMP nsAccessibleTreeCache::InvalidateCache(PRInt32 aRow, PRInt32 aCount)
{
    return NS_ERROR_NOT_IMPLEMENTED;
}

/* void treeViewInvalidated (in long aStartRow, in long aEndRow, in long aStartCol, in long aEndCol); */
NS_IMETHODIMP nsAccessibleTreeCache::TreeViewInvalidated(PRInt32 aStartRow, PRInt32 aEndRow, PRInt32 aStartCol, PRInt32 aEndCol)
{
    return NS_ERROR_NOT_IMPLEMENTED;
}

/* void treeViewChanged (); */
NS_IMETHODIMP nsAccessibleTreeCache::TreeViewChanged()
{
    return NS_ERROR_NOT_IMPLEMENTED;
}

/* End of implementation class template. */
#endif


/* starting interface:    nsPIAccessibleTreeItem */
#define NS_PIACCESSIBLETREEITEM_IID_STR "b71532f9-53b2-4647-a5b2-1c5f57e9aed6"

#define NS_PIACCESSIBLETREEITEM_IID \
  {0xb71532f9, 0x53b2, 0x4647, \
    { 0xa5, 0xb2, 0x1c, 0x5f, 0x57, 0xe9, 0xae, 0xd6 }}

class NS_NO_VTABLE nsPIAccessibleTreeItem : public nsISupports {
 public: 

  NS_DECLARE_STATIC_IID_ACCESSOR(NS_PIACCESSIBLETREEITEM_IID)

  /**
   * Get/set cached name.
   */
  /* attribute AString cachedName; */
  NS_IMETHOD GetCachedName(nsAString & aCachedName) = 0;
  NS_IMETHOD SetCachedName(const nsAString & aCachedName) = 0;

};

  NS_DEFINE_STATIC_IID_ACCESSOR(nsPIAccessibleTreeItem, NS_PIACCESSIBLETREEITEM_IID)

/* Use this macro when declaring classes that implement this interface. */
#define NS_DECL_NSPIACCESSIBLETREEITEM \
  NS_IMETHOD GetCachedName(nsAString & aCachedName); \
  NS_IMETHOD SetCachedName(const nsAString & aCachedName); 

/* Use this macro to declare functions that forward the behavior of this interface to another object. */
#define NS_FORWARD_NSPIACCESSIBLETREEITEM(_to) \
  NS_IMETHOD GetCachedName(nsAString & aCachedName) { return _to GetCachedName(aCachedName); } \
  NS_IMETHOD SetCachedName(const nsAString & aCachedName) { return _to SetCachedName(aCachedName); } 

/* Use this macro to declare functions that forward the behavior of this interface to another object in a safe way. */
#define NS_FORWARD_SAFE_NSPIACCESSIBLETREEITEM(_to) \
  NS_IMETHOD GetCachedName(nsAString & aCachedName) { return !_to ? NS_ERROR_NULL_POINTER : _to->GetCachedName(aCachedName); } \
  NS_IMETHOD SetCachedName(const nsAString & aCachedName) { return !_to ? NS_ERROR_NULL_POINTER : _to->SetCachedName(aCachedName); } 

#if 0
/* Use the code below as a template for the implementation class for this interface. */

/* Header file */
class _MYCLASS_ : public nsPIAccessibleTreeItem
{
public:
  NS_DECL_ISUPPORTS
  NS_DECL_NSPIACCESSIBLETREEITEM

  _MYCLASS_();

private:
  ~_MYCLASS_();

protected:
  /* additional members */
};

/* Implementation file */
NS_IMPL_ISUPPORTS1(_MYCLASS_, nsPIAccessibleTreeItem)

_MYCLASS_::_MYCLASS_()
{
  /* member initializers and constructor code */
}

_MYCLASS_::~_MYCLASS_()
{
  /* destructor code */
}

/* attribute AString cachedName; */
NS_IMETHODIMP _MYCLASS_::GetCachedName(nsAString & aCachedName)
{
    return NS_ERROR_NOT_IMPLEMENTED;
}
NS_IMETHODIMP _MYCLASS_::SetCachedName(const nsAString & aCachedName)
{
    return NS_ERROR_NOT_IMPLEMENTED;
}

/* End of implementation class template. */
#endif


#endif /* __gen_nsIAccessibleTreeCache_h__ */
