/*
 * DO NOT EDIT.  THIS FILE IS GENERATED FROM e:/builds/moz2_slave/mozilla-1.9.1-win32-xulrunner/build/docshell/base/nsIDocShellTreeOwner.idl
 */

#ifndef __gen_nsIDocShellTreeOwner_h__
#define __gen_nsIDocShellTreeOwner_h__


#ifndef __gen_nsISupports_h__
#include "nsISupports.h"
#endif

/* For IDL files that don't want to include root IDL files. */
#ifndef NS_NO_VTABLE
#define NS_NO_VTABLE
#endif
class nsIDocShellTreeItem; /* forward declaration */


/* starting interface:    nsIDocShellTreeOwner */
#define NS_IDOCSHELLTREEOWNER_IID_STR "bc0eb30e-656e-491e-a7ae-7f460b660c8d"

#define NS_IDOCSHELLTREEOWNER_IID \
  {0xbc0eb30e, 0x656e, 0x491e, \
    { 0xa7, 0xae, 0x7f, 0x46, 0x0b, 0x66, 0x0c, 0x8d }}

class NS_NO_VTABLE NS_SCRIPTABLE nsIDocShellTreeOwner : public nsISupports {
 public: 

  NS_DECLARE_STATIC_IID_ACCESSOR(NS_IDOCSHELLTREEOWNER_IID)

  /* nsIDocShellTreeItem findItemWithName (in wstring name, in nsIDocShellTreeItem aRequestor, in nsIDocShellTreeItem aOriginalRequestor); */
  NS_SCRIPTABLE NS_IMETHOD FindItemWithName(const PRUnichar *name, nsIDocShellTreeItem *aRequestor, nsIDocShellTreeItem *aOriginalRequestor, nsIDocShellTreeItem **_retval NS_OUTPARAM) = 0;

  /**
	 * Called when a content shell is added to the docshell tree.  This is
	 * _only_ called for "root" content shells (that is, ones whose parent is a
	 * chrome shell).
	 *
	 * @param aContentShell the shell being added.
	 * @param aPrimary whether the shell is primary.
	 * @param aTargetable whether the shell can be a target for named window
	 *					targeting.
	 * @param aID the "id" of the shell.  What this actually means is
	 *			undefined. Don't rely on this for anything.
	 */
  /* void contentShellAdded (in nsIDocShellTreeItem aContentShell, in boolean aPrimary, in boolean aTargetable, in AString aID); */
  NS_SCRIPTABLE NS_IMETHOD ContentShellAdded(nsIDocShellTreeItem *aContentShell, PRBool aPrimary, PRBool aTargetable, const nsAString & aID) = 0;

  /**
	 * Called when a content shell is removed from the docshell tree.  This is
	 * _only_ called for "root" content shells (that is, ones whose parent is a
	 * chrome shell).  Note that if aContentShell was never added,
	 * contentShellRemoved should just do nothing.
	 *
	 * @param aContentShell the shell being removed.
	 */
  /* void contentShellRemoved (in nsIDocShellTreeItem aContentShell); */
  NS_SCRIPTABLE NS_IMETHOD ContentShellRemoved(nsIDocShellTreeItem *aContentShell) = 0;

  /* readonly attribute nsIDocShellTreeItem primaryContentShell; */
  NS_SCRIPTABLE NS_IMETHOD GetPrimaryContentShell(nsIDocShellTreeItem * *aPrimaryContentShell) = 0;

  /* void sizeShellTo (in nsIDocShellTreeItem shell, in long cx, in long cy); */
  NS_SCRIPTABLE NS_IMETHOD SizeShellTo(nsIDocShellTreeItem *shell, PRInt32 cx, PRInt32 cy) = 0;

  /* void setPersistence (in boolean aPersistPosition, in boolean aPersistSize, in boolean aPersistSizeMode); */
  NS_SCRIPTABLE NS_IMETHOD SetPersistence(PRBool aPersistPosition, PRBool aPersistSize, PRBool aPersistSizeMode) = 0;

  /* void getPersistence (out boolean aPersistPosition, out boolean aPersistSize, out boolean aPersistSizeMode); */
  NS_SCRIPTABLE NS_IMETHOD GetPersistence(PRBool *aPersistPosition NS_OUTPARAM, PRBool *aPersistSize NS_OUTPARAM, PRBool *aPersistSizeMode NS_OUTPARAM) = 0;

};

  NS_DEFINE_STATIC_IID_ACCESSOR(nsIDocShellTreeOwner, NS_IDOCSHELLTREEOWNER_IID)

/* Use this macro when declaring classes that implement this interface. */
#define NS_DECL_NSIDOCSHELLTREEOWNER \
  NS_SCRIPTABLE NS_IMETHOD FindItemWithName(const PRUnichar *name, nsIDocShellTreeItem *aRequestor, nsIDocShellTreeItem *aOriginalRequestor, nsIDocShellTreeItem **_retval NS_OUTPARAM); \
  NS_SCRIPTABLE NS_IMETHOD ContentShellAdded(nsIDocShellTreeItem *aContentShell, PRBool aPrimary, PRBool aTargetable, const nsAString & aID); \
  NS_SCRIPTABLE NS_IMETHOD ContentShellRemoved(nsIDocShellTreeItem *aContentShell); \
  NS_SCRIPTABLE NS_IMETHOD GetPrimaryContentShell(nsIDocShellTreeItem * *aPrimaryContentShell); \
  NS_SCRIPTABLE NS_IMETHOD SizeShellTo(nsIDocShellTreeItem *shell, PRInt32 cx, PRInt32 cy); \
  NS_SCRIPTABLE NS_IMETHOD SetPersistence(PRBool aPersistPosition, PRBool aPersistSize, PRBool aPersistSizeMode); \
  NS_SCRIPTABLE NS_IMETHOD GetPersistence(PRBool *aPersistPosition NS_OUTPARAM, PRBool *aPersistSize NS_OUTPARAM, PRBool *aPersistSizeMode NS_OUTPARAM); 

/* Use this macro to declare functions that forward the behavior of this interface to another object. */
#define NS_FORWARD_NSIDOCSHELLTREEOWNER(_to) \
  NS_SCRIPTABLE NS_IMETHOD FindItemWithName(const PRUnichar *name, nsIDocShellTreeItem *aRequestor, nsIDocShellTreeItem *aOriginalRequestor, nsIDocShellTreeItem **_retval NS_OUTPARAM) { return _to FindItemWithName(name, aRequestor, aOriginalRequestor, _retval); } \
  NS_SCRIPTABLE NS_IMETHOD ContentShellAdded(nsIDocShellTreeItem *aContentShell, PRBool aPrimary, PRBool aTargetable, const nsAString & aID) { return _to ContentShellAdded(aContentShell, aPrimary, aTargetable, aID); } \
  NS_SCRIPTABLE NS_IMETHOD ContentShellRemoved(nsIDocShellTreeItem *aContentShell) { return _to ContentShellRemoved(aContentShell); } \
  NS_SCRIPTABLE NS_IMETHOD GetPrimaryContentShell(nsIDocShellTreeItem * *aPrimaryContentShell) { return _to GetPrimaryContentShell(aPrimaryContentShell); } \
  NS_SCRIPTABLE NS_IMETHOD SizeShellTo(nsIDocShellTreeItem *shell, PRInt32 cx, PRInt32 cy) { return _to SizeShellTo(shell, cx, cy); } \
  NS_SCRIPTABLE NS_IMETHOD SetPersistence(PRBool aPersistPosition, PRBool aPersistSize, PRBool aPersistSizeMode) { return _to SetPersistence(aPersistPosition, aPersistSize, aPersistSizeMode); } \
  NS_SCRIPTABLE NS_IMETHOD GetPersistence(PRBool *aPersistPosition NS_OUTPARAM, PRBool *aPersistSize NS_OUTPARAM, PRBool *aPersistSizeMode NS_OUTPARAM) { return _to GetPersistence(aPersistPosition, aPersistSize, aPersistSizeMode); } 

/* Use this macro to declare functions that forward the behavior of this interface to another object in a safe way. */
#define NS_FORWARD_SAFE_NSIDOCSHELLTREEOWNER(_to) \
  NS_SCRIPTABLE NS_IMETHOD FindItemWithName(const PRUnichar *name, nsIDocShellTreeItem *aRequestor, nsIDocShellTreeItem *aOriginalRequestor, nsIDocShellTreeItem **_retval NS_OUTPARAM) { return !_to ? NS_ERROR_NULL_POINTER : _to->FindItemWithName(name, aRequestor, aOriginalRequestor, _retval); } \
  NS_SCRIPTABLE NS_IMETHOD ContentShellAdded(nsIDocShellTreeItem *aContentShell, PRBool aPrimary, PRBool aTargetable, const nsAString & aID) { return !_to ? NS_ERROR_NULL_POINTER : _to->ContentShellAdded(aContentShell, aPrimary, aTargetable, aID); } \
  NS_SCRIPTABLE NS_IMETHOD ContentShellRemoved(nsIDocShellTreeItem *aContentShell) { return !_to ? NS_ERROR_NULL_POINTER : _to->ContentShellRemoved(aContentShell); } \
  NS_SCRIPTABLE NS_IMETHOD GetPrimaryContentShell(nsIDocShellTreeItem * *aPrimaryContentShell) { return !_to ? NS_ERROR_NULL_POINTER : _to->GetPrimaryContentShell(aPrimaryContentShell); } \
  NS_SCRIPTABLE NS_IMETHOD SizeShellTo(nsIDocShellTreeItem *shell, PRInt32 cx, PRInt32 cy) { return !_to ? NS_ERROR_NULL_POINTER : _to->SizeShellTo(shell, cx, cy); } \
  NS_SCRIPTABLE NS_IMETHOD SetPersistence(PRBool aPersistPosition, PRBool aPersistSize, PRBool aPersistSizeMode) { return !_to ? NS_ERROR_NULL_POINTER : _to->SetPersistence(aPersistPosition, aPersistSize, aPersistSizeMode); } \
  NS_SCRIPTABLE NS_IMETHOD GetPersistence(PRBool *aPersistPosition NS_OUTPARAM, PRBool *aPersistSize NS_OUTPARAM, PRBool *aPersistSizeMode NS_OUTPARAM) { return !_to ? NS_ERROR_NULL_POINTER : _to->GetPersistence(aPersistPosition, aPersistSize, aPersistSizeMode); } 

#if 0
/* Use the code below as a template for the implementation class for this interface. */

/* Header file */
class nsDocShellTreeOwner : public nsIDocShellTreeOwner
{
public:
  NS_DECL_ISUPPORTS
  NS_DECL_NSIDOCSHELLTREEOWNER

  nsDocShellTreeOwner();

private:
  ~nsDocShellTreeOwner();

protected:
  /* additional members */
};

/* Implementation file */
NS_IMPL_ISUPPORTS1(nsDocShellTreeOwner, nsIDocShellTreeOwner)

nsDocShellTreeOwner::nsDocShellTreeOwner()
{
  /* member initializers and constructor code */
}

nsDocShellTreeOwner::~nsDocShellTreeOwner()
{
  /* destructor code */
}

/* nsIDocShellTreeItem findItemWithName (in wstring name, in nsIDocShellTreeItem aRequestor, in nsIDocShellTreeItem aOriginalRequestor); */
NS_IMETHODIMP nsDocShellTreeOwner::FindItemWithName(const PRUnichar *name, nsIDocShellTreeItem *aRequestor, nsIDocShellTreeItem *aOriginalRequestor, nsIDocShellTreeItem **_retval NS_OUTPARAM)
{
    return NS_ERROR_NOT_IMPLEMENTED;
}

/* void contentShellAdded (in nsIDocShellTreeItem aContentShell, in boolean aPrimary, in boolean aTargetable, in AString aID); */
NS_IMETHODIMP nsDocShellTreeOwner::ContentShellAdded(nsIDocShellTreeItem *aContentShell, PRBool aPrimary, PRBool aTargetable, const nsAString & aID)
{
    return NS_ERROR_NOT_IMPLEMENTED;
}

/* void contentShellRemoved (in nsIDocShellTreeItem aContentShell); */
NS_IMETHODIMP nsDocShellTreeOwner::ContentShellRemoved(nsIDocShellTreeItem *aContentShell)
{
    return NS_ERROR_NOT_IMPLEMENTED;
}

/* readonly attribute nsIDocShellTreeItem primaryContentShell; */
NS_IMETHODIMP nsDocShellTreeOwner::GetPrimaryContentShell(nsIDocShellTreeItem * *aPrimaryContentShell)
{
    return NS_ERROR_NOT_IMPLEMENTED;
}

/* void sizeShellTo (in nsIDocShellTreeItem shell, in long cx, in long cy); */
NS_IMETHODIMP nsDocShellTreeOwner::SizeShellTo(nsIDocShellTreeItem *shell, PRInt32 cx, PRInt32 cy)
{
    return NS_ERROR_NOT_IMPLEMENTED;
}

/* void setPersistence (in boolean aPersistPosition, in boolean aPersistSize, in boolean aPersistSizeMode); */
NS_IMETHODIMP nsDocShellTreeOwner::SetPersistence(PRBool aPersistPosition, PRBool aPersistSize, PRBool aPersistSizeMode)
{
    return NS_ERROR_NOT_IMPLEMENTED;
}

/* void getPersistence (out boolean aPersistPosition, out boolean aPersistSize, out boolean aPersistSizeMode); */
NS_IMETHODIMP nsDocShellTreeOwner::GetPersistence(PRBool *aPersistPosition NS_OUTPARAM, PRBool *aPersistSize NS_OUTPARAM, PRBool *aPersistSizeMode NS_OUTPARAM)
{
    return NS_ERROR_NOT_IMPLEMENTED;
}

/* End of implementation class template. */
#endif


#endif /* __gen_nsIDocShellTreeOwner_h__ */
