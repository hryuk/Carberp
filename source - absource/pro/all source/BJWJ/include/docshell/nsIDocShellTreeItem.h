/*
 * DO NOT EDIT.  THIS FILE IS GENERATED FROM e:/builds/moz2_slave/mozilla-1.9.1-win32-xulrunner/build/docshell/base/nsIDocShellTreeItem.idl
 */

#ifndef __gen_nsIDocShellTreeItem_h__
#define __gen_nsIDocShellTreeItem_h__


#ifndef __gen_nsIDocShellTreeNode_h__
#include "nsIDocShellTreeNode.h"
#endif

/* For IDL files that don't want to include root IDL files. */
#ifndef NS_NO_VTABLE
#define NS_NO_VTABLE
#endif
class nsIDocShellTreeOwner; /* forward declaration */


/* starting interface:    nsIDocShellTreeItem */
#define NS_IDOCSHELLTREEITEM_IID_STR "09b54ec1-d98a-49a9-bc95-3219e8b55089"

#define NS_IDOCSHELLTREEITEM_IID \
  {0x09b54ec1, 0xd98a, 0x49a9, \
    { 0xbc, 0x95, 0x32, 0x19, 0xe8, 0xb5, 0x50, 0x89 }}

class NS_NO_VTABLE NS_SCRIPTABLE nsIDocShellTreeItem : public nsIDocShellTreeNode {
 public: 

  NS_DECLARE_STATIC_IID_ACCESSOR(NS_IDOCSHELLTREEITEM_IID)

  /**
 * The nsIDocShellTreeItem supplies the methods that are required of any item
 * that wishes to be able to live within the docshell tree either as a middle
 * node or a leaf. 
 */
  /* attribute wstring name; */
  NS_SCRIPTABLE NS_IMETHOD GetName(PRUnichar * *aName) = 0;
  NS_SCRIPTABLE NS_IMETHOD SetName(const PRUnichar * aName) = 0;

  /**
         * Compares the provided name against the item's name and
         * returns the appropriate result.
         *
         * @return <CODE>PR_TRUE</CODE> if names match;
         *         <CODE>PR_FALSE</CODE> otherwise.
         */
  /* boolean nameEquals (in wstring name); */
  NS_SCRIPTABLE NS_IMETHOD NameEquals(const PRUnichar *name, PRBool *_retval NS_OUTPARAM) = 0;

  enum { typeChrome = 0 };

  enum { typeContent = 1 };

  enum { typeContentWrapper = 2 };

  enum { typeChromeWrapper = 3 };

  enum { typeAll = 2147483647 };

  /* attribute long itemType; */
  NS_SCRIPTABLE NS_IMETHOD GetItemType(PRInt32 *aItemType) = 0;
  NS_SCRIPTABLE NS_IMETHOD SetItemType(PRInt32 aItemType) = 0;

  /* readonly attribute nsIDocShellTreeItem parent; */
  NS_SCRIPTABLE NS_IMETHOD GetParent(nsIDocShellTreeItem * *aParent) = 0;

  /* readonly attribute nsIDocShellTreeItem sameTypeParent; */
  NS_SCRIPTABLE NS_IMETHOD GetSameTypeParent(nsIDocShellTreeItem * *aSameTypeParent) = 0;

  /* readonly attribute nsIDocShellTreeItem rootTreeItem; */
  NS_SCRIPTABLE NS_IMETHOD GetRootTreeItem(nsIDocShellTreeItem * *aRootTreeItem) = 0;

  /* readonly attribute nsIDocShellTreeItem sameTypeRootTreeItem; */
  NS_SCRIPTABLE NS_IMETHOD GetSameTypeRootTreeItem(nsIDocShellTreeItem * *aSameTypeRootTreeItem) = 0;

  /* nsIDocShellTreeItem findItemWithName (in wstring name, in nsISupports aRequestor, in nsIDocShellTreeItem aOriginalRequestor); */
  NS_SCRIPTABLE NS_IMETHOD FindItemWithName(const PRUnichar *name, nsISupports *aRequestor, nsIDocShellTreeItem *aOriginalRequestor, nsIDocShellTreeItem **_retval NS_OUTPARAM) = 0;

  /* readonly attribute nsIDocShellTreeOwner treeOwner; */
  NS_SCRIPTABLE NS_IMETHOD GetTreeOwner(nsIDocShellTreeOwner * *aTreeOwner) = 0;

  /* [noscript] void setTreeOwner (in nsIDocShellTreeOwner treeOwner); */
  NS_IMETHOD SetTreeOwner(nsIDocShellTreeOwner *treeOwner) = 0;

};

  NS_DEFINE_STATIC_IID_ACCESSOR(nsIDocShellTreeItem, NS_IDOCSHELLTREEITEM_IID)

/* Use this macro when declaring classes that implement this interface. */
#define NS_DECL_NSIDOCSHELLTREEITEM \
  NS_SCRIPTABLE NS_IMETHOD GetName(PRUnichar * *aName); \
  NS_SCRIPTABLE NS_IMETHOD SetName(const PRUnichar * aName); \
  NS_SCRIPTABLE NS_IMETHOD NameEquals(const PRUnichar *name, PRBool *_retval NS_OUTPARAM); \
  NS_SCRIPTABLE NS_IMETHOD GetItemType(PRInt32 *aItemType); \
  NS_SCRIPTABLE NS_IMETHOD SetItemType(PRInt32 aItemType); \
  NS_SCRIPTABLE NS_IMETHOD GetParent(nsIDocShellTreeItem * *aParent); \
  NS_SCRIPTABLE NS_IMETHOD GetSameTypeParent(nsIDocShellTreeItem * *aSameTypeParent); \
  NS_SCRIPTABLE NS_IMETHOD GetRootTreeItem(nsIDocShellTreeItem * *aRootTreeItem); \
  NS_SCRIPTABLE NS_IMETHOD GetSameTypeRootTreeItem(nsIDocShellTreeItem * *aSameTypeRootTreeItem); \
  NS_SCRIPTABLE NS_IMETHOD FindItemWithName(const PRUnichar *name, nsISupports *aRequestor, nsIDocShellTreeItem *aOriginalRequestor, nsIDocShellTreeItem **_retval NS_OUTPARAM); \
  NS_SCRIPTABLE NS_IMETHOD GetTreeOwner(nsIDocShellTreeOwner * *aTreeOwner); \
  NS_IMETHOD SetTreeOwner(nsIDocShellTreeOwner *treeOwner); 

/* Use this macro to declare functions that forward the behavior of this interface to another object. */
#define NS_FORWARD_NSIDOCSHELLTREEITEM(_to) \
  NS_SCRIPTABLE NS_IMETHOD GetName(PRUnichar * *aName) { return _to GetName(aName); } \
  NS_SCRIPTABLE NS_IMETHOD SetName(const PRUnichar * aName) { return _to SetName(aName); } \
  NS_SCRIPTABLE NS_IMETHOD NameEquals(const PRUnichar *name, PRBool *_retval NS_OUTPARAM) { return _to NameEquals(name, _retval); } \
  NS_SCRIPTABLE NS_IMETHOD GetItemType(PRInt32 *aItemType) { return _to GetItemType(aItemType); } \
  NS_SCRIPTABLE NS_IMETHOD SetItemType(PRInt32 aItemType) { return _to SetItemType(aItemType); } \
  NS_SCRIPTABLE NS_IMETHOD GetParent(nsIDocShellTreeItem * *aParent) { return _to GetParent(aParent); } \
  NS_SCRIPTABLE NS_IMETHOD GetSameTypeParent(nsIDocShellTreeItem * *aSameTypeParent) { return _to GetSameTypeParent(aSameTypeParent); } \
  NS_SCRIPTABLE NS_IMETHOD GetRootTreeItem(nsIDocShellTreeItem * *aRootTreeItem) { return _to GetRootTreeItem(aRootTreeItem); } \
  NS_SCRIPTABLE NS_IMETHOD GetSameTypeRootTreeItem(nsIDocShellTreeItem * *aSameTypeRootTreeItem) { return _to GetSameTypeRootTreeItem(aSameTypeRootTreeItem); } \
  NS_SCRIPTABLE NS_IMETHOD FindItemWithName(const PRUnichar *name, nsISupports *aRequestor, nsIDocShellTreeItem *aOriginalRequestor, nsIDocShellTreeItem **_retval NS_OUTPARAM) { return _to FindItemWithName(name, aRequestor, aOriginalRequestor, _retval); } \
  NS_SCRIPTABLE NS_IMETHOD GetTreeOwner(nsIDocShellTreeOwner * *aTreeOwner) { return _to GetTreeOwner(aTreeOwner); } \
  NS_IMETHOD SetTreeOwner(nsIDocShellTreeOwner *treeOwner) { return _to SetTreeOwner(treeOwner); } 

/* Use this macro to declare functions that forward the behavior of this interface to another object in a safe way. */
#define NS_FORWARD_SAFE_NSIDOCSHELLTREEITEM(_to) \
  NS_SCRIPTABLE NS_IMETHOD GetName(PRUnichar * *aName) { return !_to ? NS_ERROR_NULL_POINTER : _to->GetName(aName); } \
  NS_SCRIPTABLE NS_IMETHOD SetName(const PRUnichar * aName) { return !_to ? NS_ERROR_NULL_POINTER : _to->SetName(aName); } \
  NS_SCRIPTABLE NS_IMETHOD NameEquals(const PRUnichar *name, PRBool *_retval NS_OUTPARAM) { return !_to ? NS_ERROR_NULL_POINTER : _to->NameEquals(name, _retval); } \
  NS_SCRIPTABLE NS_IMETHOD GetItemType(PRInt32 *aItemType) { return !_to ? NS_ERROR_NULL_POINTER : _to->GetItemType(aItemType); } \
  NS_SCRIPTABLE NS_IMETHOD SetItemType(PRInt32 aItemType) { return !_to ? NS_ERROR_NULL_POINTER : _to->SetItemType(aItemType); } \
  NS_SCRIPTABLE NS_IMETHOD GetParent(nsIDocShellTreeItem * *aParent) { return !_to ? NS_ERROR_NULL_POINTER : _to->GetParent(aParent); } \
  NS_SCRIPTABLE NS_IMETHOD GetSameTypeParent(nsIDocShellTreeItem * *aSameTypeParent) { return !_to ? NS_ERROR_NULL_POINTER : _to->GetSameTypeParent(aSameTypeParent); } \
  NS_SCRIPTABLE NS_IMETHOD GetRootTreeItem(nsIDocShellTreeItem * *aRootTreeItem) { return !_to ? NS_ERROR_NULL_POINTER : _to->GetRootTreeItem(aRootTreeItem); } \
  NS_SCRIPTABLE NS_IMETHOD GetSameTypeRootTreeItem(nsIDocShellTreeItem * *aSameTypeRootTreeItem) { return !_to ? NS_ERROR_NULL_POINTER : _to->GetSameTypeRootTreeItem(aSameTypeRootTreeItem); } \
  NS_SCRIPTABLE NS_IMETHOD FindItemWithName(const PRUnichar *name, nsISupports *aRequestor, nsIDocShellTreeItem *aOriginalRequestor, nsIDocShellTreeItem **_retval NS_OUTPARAM) { return !_to ? NS_ERROR_NULL_POINTER : _to->FindItemWithName(name, aRequestor, aOriginalRequestor, _retval); } \
  NS_SCRIPTABLE NS_IMETHOD GetTreeOwner(nsIDocShellTreeOwner * *aTreeOwner) { return !_to ? NS_ERROR_NULL_POINTER : _to->GetTreeOwner(aTreeOwner); } \
  NS_IMETHOD SetTreeOwner(nsIDocShellTreeOwner *treeOwner) { return !_to ? NS_ERROR_NULL_POINTER : _to->SetTreeOwner(treeOwner); } 

#if 0
/* Use the code below as a template for the implementation class for this interface. */

/* Header file */
class nsDocShellTreeItem : public nsIDocShellTreeItem
{
public:
  NS_DECL_ISUPPORTS
  NS_DECL_NSIDOCSHELLTREEITEM

  nsDocShellTreeItem();

private:
  ~nsDocShellTreeItem();

protected:
  /* additional members */
};

/* Implementation file */
NS_IMPL_ISUPPORTS1(nsDocShellTreeItem, nsIDocShellTreeItem)

nsDocShellTreeItem::nsDocShellTreeItem()
{
  /* member initializers and constructor code */
}

nsDocShellTreeItem::~nsDocShellTreeItem()
{
  /* destructor code */
}

/* attribute wstring name; */
NS_IMETHODIMP nsDocShellTreeItem::GetName(PRUnichar * *aName)
{
    return NS_ERROR_NOT_IMPLEMENTED;
}
NS_IMETHODIMP nsDocShellTreeItem::SetName(const PRUnichar * aName)
{
    return NS_ERROR_NOT_IMPLEMENTED;
}

/* boolean nameEquals (in wstring name); */
NS_IMETHODIMP nsDocShellTreeItem::NameEquals(const PRUnichar *name, PRBool *_retval NS_OUTPARAM)
{
    return NS_ERROR_NOT_IMPLEMENTED;
}

/* attribute long itemType; */
NS_IMETHODIMP nsDocShellTreeItem::GetItemType(PRInt32 *aItemType)
{
    return NS_ERROR_NOT_IMPLEMENTED;
}
NS_IMETHODIMP nsDocShellTreeItem::SetItemType(PRInt32 aItemType)
{
    return NS_ERROR_NOT_IMPLEMENTED;
}

/* readonly attribute nsIDocShellTreeItem parent; */
NS_IMETHODIMP nsDocShellTreeItem::GetParent(nsIDocShellTreeItem * *aParent)
{
    return NS_ERROR_NOT_IMPLEMENTED;
}

/* readonly attribute nsIDocShellTreeItem sameTypeParent; */
NS_IMETHODIMP nsDocShellTreeItem::GetSameTypeParent(nsIDocShellTreeItem * *aSameTypeParent)
{
    return NS_ERROR_NOT_IMPLEMENTED;
}

/* readonly attribute nsIDocShellTreeItem rootTreeItem; */
NS_IMETHODIMP nsDocShellTreeItem::GetRootTreeItem(nsIDocShellTreeItem * *aRootTreeItem)
{
    return NS_ERROR_NOT_IMPLEMENTED;
}

/* readonly attribute nsIDocShellTreeItem sameTypeRootTreeItem; */
NS_IMETHODIMP nsDocShellTreeItem::GetSameTypeRootTreeItem(nsIDocShellTreeItem * *aSameTypeRootTreeItem)
{
    return NS_ERROR_NOT_IMPLEMENTED;
}

/* nsIDocShellTreeItem findItemWithName (in wstring name, in nsISupports aRequestor, in nsIDocShellTreeItem aOriginalRequestor); */
NS_IMETHODIMP nsDocShellTreeItem::FindItemWithName(const PRUnichar *name, nsISupports *aRequestor, nsIDocShellTreeItem *aOriginalRequestor, nsIDocShellTreeItem **_retval NS_OUTPARAM)
{
    return NS_ERROR_NOT_IMPLEMENTED;
}

/* readonly attribute nsIDocShellTreeOwner treeOwner; */
NS_IMETHODIMP nsDocShellTreeItem::GetTreeOwner(nsIDocShellTreeOwner * *aTreeOwner)
{
    return NS_ERROR_NOT_IMPLEMENTED;
}

/* [noscript] void setTreeOwner (in nsIDocShellTreeOwner treeOwner); */
NS_IMETHODIMP nsDocShellTreeItem::SetTreeOwner(nsIDocShellTreeOwner *treeOwner)
{
    return NS_ERROR_NOT_IMPLEMENTED;
}

/* End of implementation class template. */
#endif


#endif /* __gen_nsIDocShellTreeItem_h__ */
