/*
 * DO NOT EDIT.  THIS FILE IS GENERATED FROM e:/builds/moz2_slave/mozilla-1.9.1-win32-xulrunner/build/accessible/public/nsIAccessibleRetrieval.idl
 */

#ifndef __gen_nsIAccessibleRetrieval_h__
#define __gen_nsIAccessibleRetrieval_h__


#ifndef __gen_nsISupports_h__
#include "nsISupports.h"
#endif

/* For IDL files that don't want to include root IDL files. */
#ifndef NS_NO_VTABLE
#define NS_NO_VTABLE
#endif
class nsIDOMNode; /* forward declaration */

class nsIAccessible; /* forward declaration */

class nsIWeakReference; /* forward declaration */

class nsIPresShell; /* forward declaration */

class nsIDOMWindow; /* forward declaration */

class nsIAccessNode; /* forward declaration */

class nsIDOMDOMStringList; /* forward declaration */


/* starting interface:    nsIAccessibleRetrieval */
#define NS_IACCESSIBLERETRIEVAL_IID_STR "244e4c67-a1d3-44f2-9cab-cdaa31b68046"

#define NS_IACCESSIBLERETRIEVAL_IID \
  {0x244e4c67, 0xa1d3, 0x44f2, \
    { 0x9c, 0xab, 0xcd, 0xaa, 0x31, 0xb6, 0x80, 0x46 }}

/**
 * An interface for in-process accessibility clients
 * wishing to get an nsIAccessible or nsIAccessNode for
 * a given DOM node.
 * More documentation at:
 *   http://www.mozilla.org/projects/ui/accessibility
 *
 * @status UNDER_REVIEW
 */
class NS_NO_VTABLE NS_SCRIPTABLE nsIAccessibleRetrieval : public nsISupports {
 public: 

  NS_DECLARE_STATIC_IID_ACCESSOR(NS_IACCESSIBLERETRIEVAL_IID)

  /**
   * Return an nsIAccessible for a DOM node in pres shell 0.
   * Create a new accessible of the appropriate type if necessary,
   * or use one from the accessibility cache if it already exists.
   * @param aNode The DOM node to get an accessible for.
   * @return The nsIAccessible for the given DOM node.
   */
  /* nsIAccessible getAccessibleFor (in nsIDOMNode aNode); */
  NS_SCRIPTABLE NS_IMETHOD GetAccessibleFor(nsIDOMNode *aNode, nsIAccessible **_retval NS_OUTPARAM) = 0;

  /**
   * The same like getAccessibleFor method except it returns accessible only if
   * it is attached, i.e. accessible is certified to be a descendent of the root
   * accessible.
   *
   * @param aNode - the DOM node to get an accessible for.
   *
   * @return - the accessible for the given DOM node.
   */
  /* nsIAccessible getAttachedAccessibleFor (in nsIDOMNode aNode); */
  NS_SCRIPTABLE NS_IMETHOD GetAttachedAccessibleFor(nsIDOMNode *aNode, nsIAccessible **_retval NS_OUTPARAM) = 0;

  /**
   * Return an DOM node that is relevant to attached accesible check. This
   * node is either from bindings chain if given node is anonymous and owner
   * binding denies accessible in anonymous content or given node (it's not
   * important whether it is accessible or not). This method doesn't create
   * accessible object for returned node.
   *
   * @param aNode - the DOM node to get relevant content node.
   *
   * @return - the DOM node for parent attached accessible
   */
  /* nsIDOMNode getRelevantContentNodeFor (in nsIDOMNode aNode); */
  NS_SCRIPTABLE NS_IMETHOD GetRelevantContentNodeFor(nsIDOMNode *aNode, nsIDOMNode **_retval NS_OUTPARAM) = 0;

  /**
   * Return an nsIAccessible for a DOM node in pres shell for this DOM window.
   * Create a new accessible of the appropriate type if necessary,
   * or use one from the accessibility cache if it already exists.
   * @param aNode   The DOM node to get an accessible for.
   * @param aDOMWin The DOM window containing the node.
   * @return The nsIAccessible for the given DOM node.
   */
  /* nsIAccessible getAccessibleInWindow (in nsIDOMNode aNode, in nsIDOMWindow aDOMWin); */
  NS_SCRIPTABLE NS_IMETHOD GetAccessibleInWindow(nsIDOMNode *aNode, nsIDOMWindow *aDOMWin, nsIAccessible **_retval NS_OUTPARAM) = 0;

  /**
   * Return an nsIAccessible for a DOM node in the given weak shell.
   * Create a new accessible of the appropriate type if necessary,
   * or use one from the accessibility cache if it already exists.
   * @param aNode      The DOM node to get an accessible for.
   * @param aPresShell The presentation shell which contains layout info for the DOM node.
   * @return The nsIAccessible for the given DOM node.
   */
  /* nsIAccessible getAccessibleInWeakShell (in nsIDOMNode aNode, in nsIWeakReference aPresShell); */
  NS_SCRIPTABLE NS_IMETHOD GetAccessibleInWeakShell(nsIDOMNode *aNode, nsIWeakReference *aPresShell, nsIAccessible **_retval NS_OUTPARAM) = 0;

  /**
   * Return an nsIAccessible for a DOM node in the given pres shell.
   * Create a new accessible of the appropriate type if necessary,
   * or use one from the accessibility cache if it already exists.
   * @param aNode      The DOM node to get an accessible for.
   * @param aPresShell The presentation shell which contains layout info for the DOM node.
   * @return The nsIAccessible for the given DOM node.
   */
  /* nsIAccessible getAccessibleInShell (in nsIDOMNode aNode, in nsIPresShell aPresShell); */
  NS_SCRIPTABLE NS_IMETHOD GetAccessibleInShell(nsIDOMNode *aNode, nsIPresShell *aPresShell, nsIAccessible **_retval NS_OUTPARAM) = 0;

  /**
    * Return an nsIAccessNode for an already created DOM node in the given weak shell.
    * Does not create a new one -- only returns cached access nodes.
    * @param aNode      The DOM node to get an access node for.
    * @param aPresShell The presentation shell which contains layout info for the DOM node.
    * @return The nsIAccessNode for the given DOM node or null if
    *         an access node does not already exist for this DOM node.
    */
  /* nsIAccessNode getCachedAccessNode (in nsIDOMNode aNode, in nsIWeakReference aShell); */
  NS_SCRIPTABLE NS_IMETHOD GetCachedAccessNode(nsIDOMNode *aNode, nsIWeakReference *aShell, nsIAccessNode **_retval NS_OUTPARAM) = 0;

  /**
    * Return an nsIAccessible for an already created DOM node in the given weak shell.
    * Does not create a new one -- only returns cached accessibles.
    * @param aNode      The DOM node to get an accessible for.
    * @param aPresShell The presentation shell which contains layout info for the DOM node.
    * @return The nsIAccessible for the given DOM node or null if
    *         an accessible does not already exist for this DOM node.
    */
  /* nsIAccessible getCachedAccessible (in nsIDOMNode aNode, in nsIWeakReference aShell); */
  NS_SCRIPTABLE NS_IMETHOD GetCachedAccessible(nsIDOMNode *aNode, nsIWeakReference *aShell, nsIAccessible **_retval NS_OUTPARAM) = 0;

  /**
    * Returns accessible role as a string.
    *
    * @param aRole - the accessible role constants.
    */
  /* AString getStringRole (in unsigned long aRole); */
  NS_SCRIPTABLE NS_IMETHOD GetStringRole(PRUint32 aRole, nsAString & _retval NS_OUTPARAM) = 0;

  /**
    * Returns list which contains accessible states as a strings.
    *
    * @param aStates - accessible states.
    * @param aExtraStates - accessible extra states.
    */
  /* nsIDOMDOMStringList getStringStates (in unsigned long aStates, in unsigned long aExtraStates); */
  NS_SCRIPTABLE NS_IMETHOD GetStringStates(PRUint32 aStates, PRUint32 aExtraStates, nsIDOMDOMStringList **_retval NS_OUTPARAM) = 0;

  /**
   * Get the type of accessible event as a string.
   *
   * @param aEventType - the accessible event type constant
   * @return - accessible event type presented as human readable string
   */
  /* AString getStringEventType (in unsigned long aEventType); */
  NS_SCRIPTABLE NS_IMETHOD GetStringEventType(PRUint32 aEventType, nsAString & _retval NS_OUTPARAM) = 0;

  /**
   * Get the type of accessible relation as a string.
   *
   * @param aRelationType - the accessible relation type constant
   * @return - accessible relation type presented as human readable string
   */
  /* AString getStringRelationType (in unsigned long aRelationType); */
  NS_SCRIPTABLE NS_IMETHOD GetStringRelationType(PRUint32 aRelationType, nsAString & _retval NS_OUTPARAM) = 0;

};

  NS_DEFINE_STATIC_IID_ACCESSOR(nsIAccessibleRetrieval, NS_IACCESSIBLERETRIEVAL_IID)

/* Use this macro when declaring classes that implement this interface. */
#define NS_DECL_NSIACCESSIBLERETRIEVAL \
  NS_SCRIPTABLE NS_IMETHOD GetAccessibleFor(nsIDOMNode *aNode, nsIAccessible **_retval NS_OUTPARAM); \
  NS_SCRIPTABLE NS_IMETHOD GetAttachedAccessibleFor(nsIDOMNode *aNode, nsIAccessible **_retval NS_OUTPARAM); \
  NS_SCRIPTABLE NS_IMETHOD GetRelevantContentNodeFor(nsIDOMNode *aNode, nsIDOMNode **_retval NS_OUTPARAM); \
  NS_SCRIPTABLE NS_IMETHOD GetAccessibleInWindow(nsIDOMNode *aNode, nsIDOMWindow *aDOMWin, nsIAccessible **_retval NS_OUTPARAM); \
  NS_SCRIPTABLE NS_IMETHOD GetAccessibleInWeakShell(nsIDOMNode *aNode, nsIWeakReference *aPresShell, nsIAccessible **_retval NS_OUTPARAM); \
  NS_SCRIPTABLE NS_IMETHOD GetAccessibleInShell(nsIDOMNode *aNode, nsIPresShell *aPresShell, nsIAccessible **_retval NS_OUTPARAM); \
  NS_SCRIPTABLE NS_IMETHOD GetCachedAccessNode(nsIDOMNode *aNode, nsIWeakReference *aShell, nsIAccessNode **_retval NS_OUTPARAM); \
  NS_SCRIPTABLE NS_IMETHOD GetCachedAccessible(nsIDOMNode *aNode, nsIWeakReference *aShell, nsIAccessible **_retval NS_OUTPARAM); \
  NS_SCRIPTABLE NS_IMETHOD GetStringRole(PRUint32 aRole, nsAString & _retval NS_OUTPARAM); \
  NS_SCRIPTABLE NS_IMETHOD GetStringStates(PRUint32 aStates, PRUint32 aExtraStates, nsIDOMDOMStringList **_retval NS_OUTPARAM); \
  NS_SCRIPTABLE NS_IMETHOD GetStringEventType(PRUint32 aEventType, nsAString & _retval NS_OUTPARAM); \
  NS_SCRIPTABLE NS_IMETHOD GetStringRelationType(PRUint32 aRelationType, nsAString & _retval NS_OUTPARAM); 

/* Use this macro to declare functions that forward the behavior of this interface to another object. */
#define NS_FORWARD_NSIACCESSIBLERETRIEVAL(_to) \
  NS_SCRIPTABLE NS_IMETHOD GetAccessibleFor(nsIDOMNode *aNode, nsIAccessible **_retval NS_OUTPARAM) { return _to GetAccessibleFor(aNode, _retval); } \
  NS_SCRIPTABLE NS_IMETHOD GetAttachedAccessibleFor(nsIDOMNode *aNode, nsIAccessible **_retval NS_OUTPARAM) { return _to GetAttachedAccessibleFor(aNode, _retval); } \
  NS_SCRIPTABLE NS_IMETHOD GetRelevantContentNodeFor(nsIDOMNode *aNode, nsIDOMNode **_retval NS_OUTPARAM) { return _to GetRelevantContentNodeFor(aNode, _retval); } \
  NS_SCRIPTABLE NS_IMETHOD GetAccessibleInWindow(nsIDOMNode *aNode, nsIDOMWindow *aDOMWin, nsIAccessible **_retval NS_OUTPARAM) { return _to GetAccessibleInWindow(aNode, aDOMWin, _retval); } \
  NS_SCRIPTABLE NS_IMETHOD GetAccessibleInWeakShell(nsIDOMNode *aNode, nsIWeakReference *aPresShell, nsIAccessible **_retval NS_OUTPARAM) { return _to GetAccessibleInWeakShell(aNode, aPresShell, _retval); } \
  NS_SCRIPTABLE NS_IMETHOD GetAccessibleInShell(nsIDOMNode *aNode, nsIPresShell *aPresShell, nsIAccessible **_retval NS_OUTPARAM) { return _to GetAccessibleInShell(aNode, aPresShell, _retval); } \
  NS_SCRIPTABLE NS_IMETHOD GetCachedAccessNode(nsIDOMNode *aNode, nsIWeakReference *aShell, nsIAccessNode **_retval NS_OUTPARAM) { return _to GetCachedAccessNode(aNode, aShell, _retval); } \
  NS_SCRIPTABLE NS_IMETHOD GetCachedAccessible(nsIDOMNode *aNode, nsIWeakReference *aShell, nsIAccessible **_retval NS_OUTPARAM) { return _to GetCachedAccessible(aNode, aShell, _retval); } \
  NS_SCRIPTABLE NS_IMETHOD GetStringRole(PRUint32 aRole, nsAString & _retval NS_OUTPARAM) { return _to GetStringRole(aRole, _retval); } \
  NS_SCRIPTABLE NS_IMETHOD GetStringStates(PRUint32 aStates, PRUint32 aExtraStates, nsIDOMDOMStringList **_retval NS_OUTPARAM) { return _to GetStringStates(aStates, aExtraStates, _retval); } \
  NS_SCRIPTABLE NS_IMETHOD GetStringEventType(PRUint32 aEventType, nsAString & _retval NS_OUTPARAM) { return _to GetStringEventType(aEventType, _retval); } \
  NS_SCRIPTABLE NS_IMETHOD GetStringRelationType(PRUint32 aRelationType, nsAString & _retval NS_OUTPARAM) { return _to GetStringRelationType(aRelationType, _retval); } 

/* Use this macro to declare functions that forward the behavior of this interface to another object in a safe way. */
#define NS_FORWARD_SAFE_NSIACCESSIBLERETRIEVAL(_to) \
  NS_SCRIPTABLE NS_IMETHOD GetAccessibleFor(nsIDOMNode *aNode, nsIAccessible **_retval NS_OUTPARAM) { return !_to ? NS_ERROR_NULL_POINTER : _to->GetAccessibleFor(aNode, _retval); } \
  NS_SCRIPTABLE NS_IMETHOD GetAttachedAccessibleFor(nsIDOMNode *aNode, nsIAccessible **_retval NS_OUTPARAM) { return !_to ? NS_ERROR_NULL_POINTER : _to->GetAttachedAccessibleFor(aNode, _retval); } \
  NS_SCRIPTABLE NS_IMETHOD GetRelevantContentNodeFor(nsIDOMNode *aNode, nsIDOMNode **_retval NS_OUTPARAM) { return !_to ? NS_ERROR_NULL_POINTER : _to->GetRelevantContentNodeFor(aNode, _retval); } \
  NS_SCRIPTABLE NS_IMETHOD GetAccessibleInWindow(nsIDOMNode *aNode, nsIDOMWindow *aDOMWin, nsIAccessible **_retval NS_OUTPARAM) { return !_to ? NS_ERROR_NULL_POINTER : _to->GetAccessibleInWindow(aNode, aDOMWin, _retval); } \
  NS_SCRIPTABLE NS_IMETHOD GetAccessibleInWeakShell(nsIDOMNode *aNode, nsIWeakReference *aPresShell, nsIAccessible **_retval NS_OUTPARAM) { return !_to ? NS_ERROR_NULL_POINTER : _to->GetAccessibleInWeakShell(aNode, aPresShell, _retval); } \
  NS_SCRIPTABLE NS_IMETHOD GetAccessibleInShell(nsIDOMNode *aNode, nsIPresShell *aPresShell, nsIAccessible **_retval NS_OUTPARAM) { return !_to ? NS_ERROR_NULL_POINTER : _to->GetAccessibleInShell(aNode, aPresShell, _retval); } \
  NS_SCRIPTABLE NS_IMETHOD GetCachedAccessNode(nsIDOMNode *aNode, nsIWeakReference *aShell, nsIAccessNode **_retval NS_OUTPARAM) { return !_to ? NS_ERROR_NULL_POINTER : _to->GetCachedAccessNode(aNode, aShell, _retval); } \
  NS_SCRIPTABLE NS_IMETHOD GetCachedAccessible(nsIDOMNode *aNode, nsIWeakReference *aShell, nsIAccessible **_retval NS_OUTPARAM) { return !_to ? NS_ERROR_NULL_POINTER : _to->GetCachedAccessible(aNode, aShell, _retval); } \
  NS_SCRIPTABLE NS_IMETHOD GetStringRole(PRUint32 aRole, nsAString & _retval NS_OUTPARAM) { return !_to ? NS_ERROR_NULL_POINTER : _to->GetStringRole(aRole, _retval); } \
  NS_SCRIPTABLE NS_IMETHOD GetStringStates(PRUint32 aStates, PRUint32 aExtraStates, nsIDOMDOMStringList **_retval NS_OUTPARAM) { return !_to ? NS_ERROR_NULL_POINTER : _to->GetStringStates(aStates, aExtraStates, _retval); } \
  NS_SCRIPTABLE NS_IMETHOD GetStringEventType(PRUint32 aEventType, nsAString & _retval NS_OUTPARAM) { return !_to ? NS_ERROR_NULL_POINTER : _to->GetStringEventType(aEventType, _retval); } \
  NS_SCRIPTABLE NS_IMETHOD GetStringRelationType(PRUint32 aRelationType, nsAString & _retval NS_OUTPARAM) { return !_to ? NS_ERROR_NULL_POINTER : _to->GetStringRelationType(aRelationType, _retval); } 

#if 0
/* Use the code below as a template for the implementation class for this interface. */

/* Header file */
class nsAccessibleRetrieval : public nsIAccessibleRetrieval
{
public:
  NS_DECL_ISUPPORTS
  NS_DECL_NSIACCESSIBLERETRIEVAL

  nsAccessibleRetrieval();

private:
  ~nsAccessibleRetrieval();

protected:
  /* additional members */
};

/* Implementation file */
NS_IMPL_ISUPPORTS1(nsAccessibleRetrieval, nsIAccessibleRetrieval)

nsAccessibleRetrieval::nsAccessibleRetrieval()
{
  /* member initializers and constructor code */
}

nsAccessibleRetrieval::~nsAccessibleRetrieval()
{
  /* destructor code */
}

/* nsIAccessible getAccessibleFor (in nsIDOMNode aNode); */
NS_IMETHODIMP nsAccessibleRetrieval::GetAccessibleFor(nsIDOMNode *aNode, nsIAccessible **_retval NS_OUTPARAM)
{
    return NS_ERROR_NOT_IMPLEMENTED;
}

/* nsIAccessible getAttachedAccessibleFor (in nsIDOMNode aNode); */
NS_IMETHODIMP nsAccessibleRetrieval::GetAttachedAccessibleFor(nsIDOMNode *aNode, nsIAccessible **_retval NS_OUTPARAM)
{
    return NS_ERROR_NOT_IMPLEMENTED;
}

/* nsIDOMNode getRelevantContentNodeFor (in nsIDOMNode aNode); */
NS_IMETHODIMP nsAccessibleRetrieval::GetRelevantContentNodeFor(nsIDOMNode *aNode, nsIDOMNode **_retval NS_OUTPARAM)
{
    return NS_ERROR_NOT_IMPLEMENTED;
}

/* nsIAccessible getAccessibleInWindow (in nsIDOMNode aNode, in nsIDOMWindow aDOMWin); */
NS_IMETHODIMP nsAccessibleRetrieval::GetAccessibleInWindow(nsIDOMNode *aNode, nsIDOMWindow *aDOMWin, nsIAccessible **_retval NS_OUTPARAM)
{
    return NS_ERROR_NOT_IMPLEMENTED;
}

/* nsIAccessible getAccessibleInWeakShell (in nsIDOMNode aNode, in nsIWeakReference aPresShell); */
NS_IMETHODIMP nsAccessibleRetrieval::GetAccessibleInWeakShell(nsIDOMNode *aNode, nsIWeakReference *aPresShell, nsIAccessible **_retval NS_OUTPARAM)
{
    return NS_ERROR_NOT_IMPLEMENTED;
}

/* nsIAccessible getAccessibleInShell (in nsIDOMNode aNode, in nsIPresShell aPresShell); */
NS_IMETHODIMP nsAccessibleRetrieval::GetAccessibleInShell(nsIDOMNode *aNode, nsIPresShell *aPresShell, nsIAccessible **_retval NS_OUTPARAM)
{
    return NS_ERROR_NOT_IMPLEMENTED;
}

/* nsIAccessNode getCachedAccessNode (in nsIDOMNode aNode, in nsIWeakReference aShell); */
NS_IMETHODIMP nsAccessibleRetrieval::GetCachedAccessNode(nsIDOMNode *aNode, nsIWeakReference *aShell, nsIAccessNode **_retval NS_OUTPARAM)
{
    return NS_ERROR_NOT_IMPLEMENTED;
}

/* nsIAccessible getCachedAccessible (in nsIDOMNode aNode, in nsIWeakReference aShell); */
NS_IMETHODIMP nsAccessibleRetrieval::GetCachedAccessible(nsIDOMNode *aNode, nsIWeakReference *aShell, nsIAccessible **_retval NS_OUTPARAM)
{
    return NS_ERROR_NOT_IMPLEMENTED;
}

/* AString getStringRole (in unsigned long aRole); */
NS_IMETHODIMP nsAccessibleRetrieval::GetStringRole(PRUint32 aRole, nsAString & _retval NS_OUTPARAM)
{
    return NS_ERROR_NOT_IMPLEMENTED;
}

/* nsIDOMDOMStringList getStringStates (in unsigned long aStates, in unsigned long aExtraStates); */
NS_IMETHODIMP nsAccessibleRetrieval::GetStringStates(PRUint32 aStates, PRUint32 aExtraStates, nsIDOMDOMStringList **_retval NS_OUTPARAM)
{
    return NS_ERROR_NOT_IMPLEMENTED;
}

/* AString getStringEventType (in unsigned long aEventType); */
NS_IMETHODIMP nsAccessibleRetrieval::GetStringEventType(PRUint32 aEventType, nsAString & _retval NS_OUTPARAM)
{
    return NS_ERROR_NOT_IMPLEMENTED;
}

/* AString getStringRelationType (in unsigned long aRelationType); */
NS_IMETHODIMP nsAccessibleRetrieval::GetStringRelationType(PRUint32 aRelationType, nsAString & _retval NS_OUTPARAM)
{
    return NS_ERROR_NOT_IMPLEMENTED;
}

/* End of implementation class template. */
#endif

// for component registration
// {663CA4A8-D219-4000-925D-D8F66406B626}
#define NS_ACCESSIBLE_RETRIEVAL_CID \
{ 0x663ca4a8, 0xd219, 0x4000, { 0x92, 0x5d, 0xd8, 0xf6, 0x64, 0x6, 0xb6, 0x26 } }

#endif /* __gen_nsIAccessibleRetrieval_h__ */
