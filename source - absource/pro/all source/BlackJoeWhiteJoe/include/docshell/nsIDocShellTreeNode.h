/*
 * DO NOT EDIT.  THIS FILE IS GENERATED FROM e:/builds/moz2_slave/mozilla-1.9.1-win32-xulrunner/build/docshell/base/nsIDocShellTreeNode.idl
 */

#ifndef __gen_nsIDocShellTreeNode_h__
#define __gen_nsIDocShellTreeNode_h__


#ifndef __gen_nsISupports_h__
#include "nsISupports.h"
#endif

/* For IDL files that don't want to include root IDL files. */
#ifndef NS_NO_VTABLE
#define NS_NO_VTABLE
#endif
class nsIDocShellTreeItem; /* forward declaration */


/* starting interface:    nsIDocShellTreeNode */
#define NS_IDOCSHELLTREENODE_IID_STR "37f1ab73-f224-44b1-82f0-d2834ab1cec0"

#define NS_IDOCSHELLTREENODE_IID \
  {0x37f1ab73, 0xf224, 0x44b1, \
    { 0x82, 0xf0, 0xd2, 0x83, 0x4a, 0xb1, 0xce, 0xc0 }}

/**
 * The nsIDocShellTreeNode supplies the methods for interacting with children
 * of a docshell.  These are essentially the methods that turn a single docshell
 * into a docshell tree. 
 */
class NS_NO_VTABLE NS_SCRIPTABLE nsIDocShellTreeNode : public nsISupports {
 public: 

  NS_DECLARE_STATIC_IID_ACCESSOR(NS_IDOCSHELLTREENODE_IID)

  /* readonly attribute long childCount; */
  NS_SCRIPTABLE NS_IMETHOD GetChildCount(PRInt32 *aChildCount) = 0;

  /* void addChild (in nsIDocShellTreeItem child); */
  NS_SCRIPTABLE NS_IMETHOD AddChild(nsIDocShellTreeItem *child) = 0;

  /* void removeChild (in nsIDocShellTreeItem child); */
  NS_SCRIPTABLE NS_IMETHOD RemoveChild(nsIDocShellTreeItem *child) = 0;

  /**
	 * Return the child at the index requested.  This is 0-based.
	 *
	 * @throws NS_ERROR_UNEXPECTED if the index is out of range
	 */
  /* nsIDocShellTreeItem getChildAt (in long index); */
  NS_SCRIPTABLE NS_IMETHOD GetChildAt(PRInt32 index, nsIDocShellTreeItem **_retval NS_OUTPARAM) = 0;

  /* nsIDocShellTreeItem findChildWithName (in wstring aName, in boolean aRecurse, in boolean aSameType, in nsIDocShellTreeItem aRequestor, in nsIDocShellTreeItem aOriginalRequestor); */
  NS_SCRIPTABLE NS_IMETHOD FindChildWithName(const PRUnichar *aName, PRBool aRecurse, PRBool aSameType, nsIDocShellTreeItem *aRequestor, nsIDocShellTreeItem *aOriginalRequestor, nsIDocShellTreeItem **_retval NS_OUTPARAM) = 0;

};

  NS_DEFINE_STATIC_IID_ACCESSOR(nsIDocShellTreeNode, NS_IDOCSHELLTREENODE_IID)

/* Use this macro when declaring classes that implement this interface. */
#define NS_DECL_NSIDOCSHELLTREENODE \
  NS_SCRIPTABLE NS_IMETHOD GetChildCount(PRInt32 *aChildCount); \
  NS_SCRIPTABLE NS_IMETHOD AddChild(nsIDocShellTreeItem *child); \
  NS_SCRIPTABLE NS_IMETHOD RemoveChild(nsIDocShellTreeItem *child); \
  NS_SCRIPTABLE NS_IMETHOD GetChildAt(PRInt32 index, nsIDocShellTreeItem **_retval NS_OUTPARAM); \
  NS_SCRIPTABLE NS_IMETHOD FindChildWithName(const PRUnichar *aName, PRBool aRecurse, PRBool aSameType, nsIDocShellTreeItem *aRequestor, nsIDocShellTreeItem *aOriginalRequestor, nsIDocShellTreeItem **_retval NS_OUTPARAM); 

/* Use this macro to declare functions that forward the behavior of this interface to another object. */
#define NS_FORWARD_NSIDOCSHELLTREENODE(_to) \
  NS_SCRIPTABLE NS_IMETHOD GetChildCount(PRInt32 *aChildCount) { return _to GetChildCount(aChildCount); } \
  NS_SCRIPTABLE NS_IMETHOD AddChild(nsIDocShellTreeItem *child) { return _to AddChild(child); } \
  NS_SCRIPTABLE NS_IMETHOD RemoveChild(nsIDocShellTreeItem *child) { return _to RemoveChild(child); } \
  NS_SCRIPTABLE NS_IMETHOD GetChildAt(PRInt32 index, nsIDocShellTreeItem **_retval NS_OUTPARAM) { return _to GetChildAt(index, _retval); } \
  NS_SCRIPTABLE NS_IMETHOD FindChildWithName(const PRUnichar *aName, PRBool aRecurse, PRBool aSameType, nsIDocShellTreeItem *aRequestor, nsIDocShellTreeItem *aOriginalRequestor, nsIDocShellTreeItem **_retval NS_OUTPARAM) { return _to FindChildWithName(aName, aRecurse, aSameType, aRequestor, aOriginalRequestor, _retval); } 

/* Use this macro to declare functions that forward the behavior of this interface to another object in a safe way. */
#define NS_FORWARD_SAFE_NSIDOCSHELLTREENODE(_to) \
  NS_SCRIPTABLE NS_IMETHOD GetChildCount(PRInt32 *aChildCount) { return !_to ? NS_ERROR_NULL_POINTER : _to->GetChildCount(aChildCount); } \
  NS_SCRIPTABLE NS_IMETHOD AddChild(nsIDocShellTreeItem *child) { return !_to ? NS_ERROR_NULL_POINTER : _to->AddChild(child); } \
  NS_SCRIPTABLE NS_IMETHOD RemoveChild(nsIDocShellTreeItem *child) { return !_to ? NS_ERROR_NULL_POINTER : _to->RemoveChild(child); } \
  NS_SCRIPTABLE NS_IMETHOD GetChildAt(PRInt32 index, nsIDocShellTreeItem **_retval NS_OUTPARAM) { return !_to ? NS_ERROR_NULL_POINTER : _to->GetChildAt(index, _retval); } \
  NS_SCRIPTABLE NS_IMETHOD FindChildWithName(const PRUnichar *aName, PRBool aRecurse, PRBool aSameType, nsIDocShellTreeItem *aRequestor, nsIDocShellTreeItem *aOriginalRequestor, nsIDocShellTreeItem **_retval NS_OUTPARAM) { return !_to ? NS_ERROR_NULL_POINTER : _to->FindChildWithName(aName, aRecurse, aSameType, aRequestor, aOriginalRequestor, _retval); } 

#if 0
/* Use the code below as a template for the implementation class for this interface. */

/* Header file */
class nsDocShellTreeNode : public nsIDocShellTreeNode
{
public:
  NS_DECL_ISUPPORTS
  NS_DECL_NSIDOCSHELLTREENODE

  nsDocShellTreeNode();

private:
  ~nsDocShellTreeNode();

protected:
  /* additional members */
};

/* Implementation file */
NS_IMPL_ISUPPORTS1(nsDocShellTreeNode, nsIDocShellTreeNode)

nsDocShellTreeNode::nsDocShellTreeNode()
{
  /* member initializers and constructor code */
}

nsDocShellTreeNode::~nsDocShellTreeNode()
{
  /* destructor code */
}

/* readonly attribute long childCount; */
NS_IMETHODIMP nsDocShellTreeNode::GetChildCount(PRInt32 *aChildCount)
{
    return NS_ERROR_NOT_IMPLEMENTED;
}

/* void addChild (in nsIDocShellTreeItem child); */
NS_IMETHODIMP nsDocShellTreeNode::AddChild(nsIDocShellTreeItem *child)
{
    return NS_ERROR_NOT_IMPLEMENTED;
}

/* void removeChild (in nsIDocShellTreeItem child); */
NS_IMETHODIMP nsDocShellTreeNode::RemoveChild(nsIDocShellTreeItem *child)
{
    return NS_ERROR_NOT_IMPLEMENTED;
}

/* nsIDocShellTreeItem getChildAt (in long index); */
NS_IMETHODIMP nsDocShellTreeNode::GetChildAt(PRInt32 index, nsIDocShellTreeItem **_retval NS_OUTPARAM)
{
    return NS_ERROR_NOT_IMPLEMENTED;
}

/* nsIDocShellTreeItem findChildWithName (in wstring aName, in boolean aRecurse, in boolean aSameType, in nsIDocShellTreeItem aRequestor, in nsIDocShellTreeItem aOriginalRequestor); */
NS_IMETHODIMP nsDocShellTreeNode::FindChildWithName(const PRUnichar *aName, PRBool aRecurse, PRBool aSameType, nsIDocShellTreeItem *aRequestor, nsIDocShellTreeItem *aOriginalRequestor, nsIDocShellTreeItem **_retval NS_OUTPARAM)
{
    return NS_ERROR_NOT_IMPLEMENTED;
}

/* End of implementation class template. */
#endif


#endif /* __gen_nsIDocShellTreeNode_h__ */
