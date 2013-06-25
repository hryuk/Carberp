/*
 * DO NOT EDIT.  THIS FILE IS GENERATED FROM e:/builds/moz2_slave/mozilla-1.9.1-win32-xulrunner/build/accessible/public/nsIAccessible.idl
 */

#ifndef __gen_nsIAccessible_h__
#define __gen_nsIAccessible_h__


#ifndef __gen_nsISupports_h__
#include "nsISupports.h"
#endif

#ifndef __gen_nsIArray_h__
#include "nsIArray.h"
#endif

/* For IDL files that don't want to include root IDL files. */
#ifndef NS_NO_VTABLE
#define NS_NO_VTABLE
#endif
class nsIPersistentProperties; /* forward declaration */

class nsIDOMDOMStringList; /* forward declaration */

class nsIAccessibleRelation; /* forward declaration */


/* starting interface:    nsIAccessible */
#define NS_IACCESSIBLE_IID_STR "670fc322-14ec-4f3b-8279-9d62ab8895c0"

#define NS_IACCESSIBLE_IID \
  {0x670fc322, 0x14ec, 0x4f3b, \
    { 0x82, 0x79, 0x9d, 0x62, 0xab, 0x88, 0x95, 0xc0 }}

/**
 * A cross-platform interface that supports platform-specific 
 * accessibility APIs like MSAA and ATK. Contains the sum of what's needed
 * to support IAccessible as well as ATK's generic accessibility objects.
 * Can also be used by in-process accessibility clients to get information
 * about objects in the accessible tree. The accessible tree is a subset of 
 * nodes in the DOM tree -- such as documents, focusable elements and text.
 * Mozilla creates the implementations of nsIAccessible on demand.
 * See http://www.mozilla.org/projects/ui/accessibility for more information.
 *
 * @status UNDER_REVIEW
 */
class NS_NO_VTABLE NS_SCRIPTABLE nsIAccessible : public nsISupports {
 public: 

  NS_DECLARE_STATIC_IID_ACCESSOR(NS_IACCESSIBLE_IID)

  /**
   * Parent node in accessible tree.
   */
  /* readonly attribute nsIAccessible parent; */
  NS_SCRIPTABLE NS_IMETHOD GetParent(nsIAccessible * *aParent) = 0;

  /**
   * Next sibling in accessible tree
   */
  /* readonly attribute nsIAccessible nextSibling; */
  NS_SCRIPTABLE NS_IMETHOD GetNextSibling(nsIAccessible * *aNextSibling) = 0;

  /**
   * Previous sibling in accessible tree
   */
  /* readonly attribute nsIAccessible previousSibling; */
  NS_SCRIPTABLE NS_IMETHOD GetPreviousSibling(nsIAccessible * *aPreviousSibling) = 0;

  /**
   * First child in accessible tree
   */
  /* readonly attribute nsIAccessible firstChild; */
  NS_SCRIPTABLE NS_IMETHOD GetFirstChild(nsIAccessible * *aFirstChild) = 0;

  /**
   * Last child in accessible tree
   */
  /* readonly attribute nsIAccessible lastChild; */
  NS_SCRIPTABLE NS_IMETHOD GetLastChild(nsIAccessible * *aLastChild) = 0;

  /**
   * Array of all this element's children.
   */
  /* readonly attribute nsIArray children; */
  NS_SCRIPTABLE NS_IMETHOD GetChildren(nsIArray * *aChildren) = 0;

  /**
   * Number of accessible children
   */
  /* readonly attribute long childCount; */
  NS_SCRIPTABLE NS_IMETHOD GetChildCount(PRInt32 *aChildCount) = 0;

  /**
   * The 0-based index of this accessible in its parent's list of children,
   * or -1 if this accessible does not have a parent.
   */
  /* readonly attribute long indexInParent; */
  NS_SCRIPTABLE NS_IMETHOD GetIndexInParent(PRInt32 *aIndexInParent) = 0;

  /**
   * Accessible name -- the main text equivalent for this node
   */
  /* attribute AString name; */
  NS_SCRIPTABLE NS_IMETHOD GetName(nsAString & aName) = 0;
  NS_SCRIPTABLE NS_IMETHOD SetName(const nsAString & aName) = 0;

  /**
   * Accessible value -- a number or a secondary text equivalent for this node
   * Widgets that use role attribute can force a value using the valuenow attribute
   */
  /* readonly attribute AString value; */
  NS_SCRIPTABLE NS_IMETHOD GetValue(nsAString & aValue) = 0;

  /**
   * Accessible description -- long text associated with this node
   */
  /* readonly attribute AString description; */
  NS_SCRIPTABLE NS_IMETHOD GetDescription(nsAString & aDescription) = 0;

  /**
   * Provides localized string of accesskey name, such as Alt+D.
   * The modifier may be affected by user and platform preferences.
   * Usually alt+letter, or just the letter alone for menu items. 
   */
  /* readonly attribute AString keyboardShortcut; */
  NS_SCRIPTABLE NS_IMETHOD GetKeyboardShortcut(nsAString & aKeyboardShortcut) = 0;

  /**
   * Provides localized string of global keyboard accelerator for default
   * action, such as Ctrl+O for Open file
   */
  /* readonly attribute AString defaultKeyBinding; */
  NS_SCRIPTABLE NS_IMETHOD GetDefaultKeyBinding(nsAString & aDefaultKeyBinding) = 0;

  /**
   * Provides array of localized string of global keyboard accelerator for
   * the given action index supported by accessible.
   *
   * @param aActionIndex - index of the given action
   */
  /* nsIDOMDOMStringList getKeyBindings (in PRUint8 aActionIndex); */
  NS_SCRIPTABLE NS_IMETHOD GetKeyBindings(PRUint8 aActionIndex, nsIDOMDOMStringList **_retval NS_OUTPARAM) = 0;

  /**
   * Natural enumerated accessible role for the associated element.
   * The values depend on platform because of variations.
   * See the ROLE_* constants defined in nsIAccessibleRole.
   * This does not take into account role attribute as the finalRole does.
   */
  /* readonly attribute unsigned long role; */
  NS_SCRIPTABLE NS_IMETHOD GetRole(PRUint32 *aRole) = 0;

  /**
   * Enumerated accessible role. The values depend on platform because of variations.
   * See the ROLE_* constants defined in nsIAccessibleRole.
   * Widgets can use role attribute to force the final role
   */
  /* readonly attribute unsigned long finalRole; */
  NS_SCRIPTABLE NS_IMETHOD GetFinalRole(PRUint32 *aFinalRole) = 0;

  /**
   * Accessible states -- bit fields which describe boolean properties of node.
   * Many states are only valid given a certain role attribute that supports
   * them.
   *
   * @param aState - the first bit field (see nsIAccessibleStates::STATE_*
   *                 constants)
   * @param aExtraState - the second bit field
   *                      (see nsIAccessibleStates::EXT_STATE_* constants)
   */
  /* void getState (out unsigned long aState, out unsigned long aExtraState); */
  NS_SCRIPTABLE NS_IMETHOD GetState(PRUint32 *aState NS_OUTPARAM, PRUint32 *aExtraState NS_OUTPARAM) = 0;

  /**
   * Help text associated with node
   */
  /* readonly attribute AString help; */
  NS_SCRIPTABLE NS_IMETHOD GetHelp(nsAString & aHelp) = 0;

  /**
   * Focused accessible child of node
   */
  /* readonly attribute nsIAccessible focusedChild; */
  NS_SCRIPTABLE NS_IMETHOD GetFocusedChild(nsIAccessible * *aFocusedChild) = 0;

  /**
   * Attributes of accessible
   */
  /* readonly attribute nsIPersistentProperties attributes; */
  NS_SCRIPTABLE NS_IMETHOD GetAttributes(nsIPersistentProperties * *aAttributes) = 0;

  /**
   * Returns grouping information. Used for tree items, list items, tab panel
   * labels, radio buttons, etc. Also used for collectons of non-text objects.
   *
   * @param groupLevel - 1-based, similar to ARIA 'level' property
   * @param similarItemsInGroup - 1-based, similar to ARIA 'setsize' property,
   *                              inclusive of the current item
   * @param positionInGroup - 1-based, similar to ARIA 'posinset' property
   */
  /* void groupPosition (out long aGroupLevel, out long aSimilarItemsInGroup, out long aPositionInGroup); */
  NS_SCRIPTABLE NS_IMETHOD GroupPosition(PRInt32 *aGroupLevel NS_OUTPARAM, PRInt32 *aSimilarItemsInGroup NS_OUTPARAM, PRInt32 *aPositionInGroup NS_OUTPARAM) = 0;

  /**
   * Accessible child which contains the coordinate at (x, y) in screen pixels.
   * If the point is in the current accessible but not in a child, the
   * current accessible will be returned.
   * If the point is in neither the current accessible or a child, then
   * null will be returned.
   *
   * @param x  screen's x coordinate
   * @param y  screen's y coordinate
   * @return   the deepest accessible child containing the given point
   */
  /* nsIAccessible getChildAtPoint (in long x, in long y); */
  NS_SCRIPTABLE NS_IMETHOD GetChildAtPoint(PRInt32 x, PRInt32 y, nsIAccessible **_retval NS_OUTPARAM) = 0;

  /**
   * Deepest accessible child which contains the coordinate at (x, y) in screen
   * pixels. If the point is in the current accessible but not in a child, the
   * current accessible will be returned. If the point is in neither the current
   * accessible or a child, then null will be returned.
   *
   * @param x  screen's x coordinate
   * @param y  screen's y coordinate
   * @return   the deepest accessible child containing the given point
   */
  /* nsIAccessible getDeepestChildAtPoint (in long x, in long y); */
  NS_SCRIPTABLE NS_IMETHOD GetDeepestChildAtPoint(PRInt32 x, PRInt32 y, nsIAccessible **_retval NS_OUTPARAM) = 0;

  /**
   * Nth accessible child using zero-based index or last child if index less than zero
   */
  /* nsIAccessible getChildAt (in long aChildIndex); */
  NS_SCRIPTABLE NS_IMETHOD GetChildAt(PRInt32 aChildIndex, nsIAccessible **_retval NS_OUTPARAM) = 0;

  /**
   * Accessible node geometrically to the right of this one
   */
  /* nsIAccessible getAccessibleToRight (); */
  NS_SCRIPTABLE NS_IMETHOD GetAccessibleToRight(nsIAccessible **_retval NS_OUTPARAM) = 0;

  /**
   * Accessible node geometrically to the left of this one
   */
  /* nsIAccessible getAccessibleToLeft (); */
  NS_SCRIPTABLE NS_IMETHOD GetAccessibleToLeft(nsIAccessible **_retval NS_OUTPARAM) = 0;

  /**
   * Accessible node geometrically above this one
   */
  /* nsIAccessible getAccessibleAbove (); */
  NS_SCRIPTABLE NS_IMETHOD GetAccessibleAbove(nsIAccessible **_retval NS_OUTPARAM) = 0;

  /**
   * Accessible node geometrically below this one
   */
  /* nsIAccessible getAccessibleBelow (); */
  NS_SCRIPTABLE NS_IMETHOD GetAccessibleBelow(nsIAccessible **_retval NS_OUTPARAM) = 0;

  /**
   * Return accessible related to this one by the given relation type (see.
   * constants defined in nsIAccessibleRelation).
   */
  /* nsIAccessible getAccessibleRelated (in unsigned long aRelationType); */
  NS_SCRIPTABLE NS_IMETHOD GetAccessibleRelated(PRUint32 aRelationType, nsIAccessible **_retval NS_OUTPARAM) = 0;

  /**
   * Returns the number of accessible relations for this object.
   */
  /* readonly attribute unsigned long relationsCount; */
  NS_SCRIPTABLE NS_IMETHOD GetRelationsCount(PRUint32 *aRelationsCount) = 0;

  /**
   * Returns one accessible relation for this object.
   *
   * @param index - relation index (0-based)
   */
  /* nsIAccessibleRelation getRelation (in unsigned long index); */
  NS_SCRIPTABLE NS_IMETHOD GetRelation(PRUint32 index, nsIAccessibleRelation **_retval NS_OUTPARAM) = 0;

  /**
   * Returns multiple accessible relations for this object.
   */
  /* nsIArray getRelations (); */
  NS_SCRIPTABLE NS_IMETHOD GetRelations(nsIArray **_retval NS_OUTPARAM) = 0;

  /**
   * Return accessible's x and y coordinates relative to the screen and
   * accessible's width and height.
   */
  /* void getBounds (out long x, out long y, out long width, out long height); */
  NS_SCRIPTABLE NS_IMETHOD GetBounds(PRInt32 *x NS_OUTPARAM, PRInt32 *y NS_OUTPARAM, PRInt32 *width NS_OUTPARAM, PRInt32 *height NS_OUTPARAM) = 0;

  /**
   * Add or remove this accessible to the current selection
   */
  /* void setSelected (in boolean isSelected); */
  NS_SCRIPTABLE NS_IMETHOD SetSelected(PRBool isSelected) = 0;

  /**
   * Extend the current selection from its current accessible anchor node
   * to this accessible
   */
  /* void extendSelection (); */
  NS_SCRIPTABLE NS_IMETHOD ExtendSelection(void) = 0;

  /**
   * Select this accessible node only
   */
  /* void takeSelection (); */
  NS_SCRIPTABLE NS_IMETHOD TakeSelection(void) = 0;

  /**
   * Focus this accessible node,
   * The state STATE_FOCUSABLE indicates whether this node is normally focusable.
   * It is the callers responsibility to determine whether this node is focusable.
   * accTakeFocus on a node that is not normally focusable (such as a table),
   * will still set focus on that node, although normally that will not be visually 
   * indicated in most style sheets.
   */
  /* void takeFocus (); */
  NS_SCRIPTABLE NS_IMETHOD TakeFocus(void) = 0;

  /**
   * The number of accessible actions associated with this accessible
   */
  /* readonly attribute PRUint8 numActions; */
  NS_SCRIPTABLE NS_IMETHOD GetNumActions(PRUint8 *aNumActions) = 0;

  /**
   * The name of the accessible action at the given zero-based index
   */
  /* AString getActionName (in PRUint8 index); */
  NS_SCRIPTABLE NS_IMETHOD GetActionName(PRUint8 index, nsAString & _retval NS_OUTPARAM) = 0;

  /**
   * The description of the accessible action at the given zero-based index
   */
  /* AString getActionDescription (in PRUint8 aIndex); */
  NS_SCRIPTABLE NS_IMETHOD GetActionDescription(PRUint8 aIndex, nsAString & _retval NS_OUTPARAM) = 0;

  /**
   * Perform the accessible action at the given zero-based index
   * Action number 0 is the default action
   */
  /* void doAction (in PRUint8 index); */
  NS_SCRIPTABLE NS_IMETHOD DoAction(PRUint8 index) = 0;

  /**
   * Get a pointer to accessibility interface for this node, which is specific 
   * to the OS/accessibility toolkit we're running on.
   */
  /* [noscript] void getNativeInterface (out voidPtr aOutAccessible); */
  NS_IMETHOD GetNativeInterface(void * *aOutAccessible NS_OUTPARAM) = 0;

};

  NS_DEFINE_STATIC_IID_ACCESSOR(nsIAccessible, NS_IACCESSIBLE_IID)

/* Use this macro when declaring classes that implement this interface. */
#define NS_DECL_NSIACCESSIBLE \
  NS_SCRIPTABLE NS_IMETHOD GetParent(nsIAccessible * *aParent); \
  NS_SCRIPTABLE NS_IMETHOD GetNextSibling(nsIAccessible * *aNextSibling); \
  NS_SCRIPTABLE NS_IMETHOD GetPreviousSibling(nsIAccessible * *aPreviousSibling); \
  NS_SCRIPTABLE NS_IMETHOD GetFirstChild(nsIAccessible * *aFirstChild); \
  NS_SCRIPTABLE NS_IMETHOD GetLastChild(nsIAccessible * *aLastChild); \
  NS_SCRIPTABLE NS_IMETHOD GetChildren(nsIArray * *aChildren); \
  NS_SCRIPTABLE NS_IMETHOD GetChildCount(PRInt32 *aChildCount); \
  NS_SCRIPTABLE NS_IMETHOD GetIndexInParent(PRInt32 *aIndexInParent); \
  NS_SCRIPTABLE NS_IMETHOD GetName(nsAString & aName); \
  NS_SCRIPTABLE NS_IMETHOD SetName(const nsAString & aName); \
  NS_SCRIPTABLE NS_IMETHOD GetValue(nsAString & aValue); \
  NS_SCRIPTABLE NS_IMETHOD GetDescription(nsAString & aDescription); \
  NS_SCRIPTABLE NS_IMETHOD GetKeyboardShortcut(nsAString & aKeyboardShortcut); \
  NS_SCRIPTABLE NS_IMETHOD GetDefaultKeyBinding(nsAString & aDefaultKeyBinding); \
  NS_SCRIPTABLE NS_IMETHOD GetKeyBindings(PRUint8 aActionIndex, nsIDOMDOMStringList **_retval NS_OUTPARAM); \
  NS_SCRIPTABLE NS_IMETHOD GetRole(PRUint32 *aRole); \
  NS_SCRIPTABLE NS_IMETHOD GetFinalRole(PRUint32 *aFinalRole); \
  NS_SCRIPTABLE NS_IMETHOD GetState(PRUint32 *aState NS_OUTPARAM, PRUint32 *aExtraState NS_OUTPARAM); \
  NS_SCRIPTABLE NS_IMETHOD GetHelp(nsAString & aHelp); \
  NS_SCRIPTABLE NS_IMETHOD GetFocusedChild(nsIAccessible * *aFocusedChild); \
  NS_SCRIPTABLE NS_IMETHOD GetAttributes(nsIPersistentProperties * *aAttributes); \
  NS_SCRIPTABLE NS_IMETHOD GroupPosition(PRInt32 *aGroupLevel NS_OUTPARAM, PRInt32 *aSimilarItemsInGroup NS_OUTPARAM, PRInt32 *aPositionInGroup NS_OUTPARAM); \
  NS_SCRIPTABLE NS_IMETHOD GetChildAtPoint(PRInt32 x, PRInt32 y, nsIAccessible **_retval NS_OUTPARAM); \
  NS_SCRIPTABLE NS_IMETHOD GetDeepestChildAtPoint(PRInt32 x, PRInt32 y, nsIAccessible **_retval NS_OUTPARAM); \
  NS_SCRIPTABLE NS_IMETHOD GetChildAt(PRInt32 aChildIndex, nsIAccessible **_retval NS_OUTPARAM); \
  NS_SCRIPTABLE NS_IMETHOD GetAccessibleToRight(nsIAccessible **_retval NS_OUTPARAM); \
  NS_SCRIPTABLE NS_IMETHOD GetAccessibleToLeft(nsIAccessible **_retval NS_OUTPARAM); \
  NS_SCRIPTABLE NS_IMETHOD GetAccessibleAbove(nsIAccessible **_retval NS_OUTPARAM); \
  NS_SCRIPTABLE NS_IMETHOD GetAccessibleBelow(nsIAccessible **_retval NS_OUTPARAM); \
  NS_SCRIPTABLE NS_IMETHOD GetAccessibleRelated(PRUint32 aRelationType, nsIAccessible **_retval NS_OUTPARAM); \
  NS_SCRIPTABLE NS_IMETHOD GetRelationsCount(PRUint32 *aRelationsCount); \
  NS_SCRIPTABLE NS_IMETHOD GetRelation(PRUint32 index, nsIAccessibleRelation **_retval NS_OUTPARAM); \
  NS_SCRIPTABLE NS_IMETHOD GetRelations(nsIArray **_retval NS_OUTPARAM); \
  NS_SCRIPTABLE NS_IMETHOD GetBounds(PRInt32 *x NS_OUTPARAM, PRInt32 *y NS_OUTPARAM, PRInt32 *width NS_OUTPARAM, PRInt32 *height NS_OUTPARAM); \
  NS_SCRIPTABLE NS_IMETHOD SetSelected(PRBool isSelected); \
  NS_SCRIPTABLE NS_IMETHOD ExtendSelection(void); \
  NS_SCRIPTABLE NS_IMETHOD TakeSelection(void); \
  NS_SCRIPTABLE NS_IMETHOD TakeFocus(void); \
  NS_SCRIPTABLE NS_IMETHOD GetNumActions(PRUint8 *aNumActions); \
  NS_SCRIPTABLE NS_IMETHOD GetActionName(PRUint8 index, nsAString & _retval NS_OUTPARAM); \
  NS_SCRIPTABLE NS_IMETHOD GetActionDescription(PRUint8 aIndex, nsAString & _retval NS_OUTPARAM); \
  NS_SCRIPTABLE NS_IMETHOD DoAction(PRUint8 index); \
  NS_IMETHOD GetNativeInterface(void * *aOutAccessible NS_OUTPARAM); 

/* Use this macro to declare functions that forward the behavior of this interface to another object. */
#define NS_FORWARD_NSIACCESSIBLE(_to) \
  NS_SCRIPTABLE NS_IMETHOD GetParent(nsIAccessible * *aParent) { return _to GetParent(aParent); } \
  NS_SCRIPTABLE NS_IMETHOD GetNextSibling(nsIAccessible * *aNextSibling) { return _to GetNextSibling(aNextSibling); } \
  NS_SCRIPTABLE NS_IMETHOD GetPreviousSibling(nsIAccessible * *aPreviousSibling) { return _to GetPreviousSibling(aPreviousSibling); } \
  NS_SCRIPTABLE NS_IMETHOD GetFirstChild(nsIAccessible * *aFirstChild) { return _to GetFirstChild(aFirstChild); } \
  NS_SCRIPTABLE NS_IMETHOD GetLastChild(nsIAccessible * *aLastChild) { return _to GetLastChild(aLastChild); } \
  NS_SCRIPTABLE NS_IMETHOD GetChildren(nsIArray * *aChildren) { return _to GetChildren(aChildren); } \
  NS_SCRIPTABLE NS_IMETHOD GetChildCount(PRInt32 *aChildCount) { return _to GetChildCount(aChildCount); } \
  NS_SCRIPTABLE NS_IMETHOD GetIndexInParent(PRInt32 *aIndexInParent) { return _to GetIndexInParent(aIndexInParent); } \
  NS_SCRIPTABLE NS_IMETHOD GetName(nsAString & aName) { return _to GetName(aName); } \
  NS_SCRIPTABLE NS_IMETHOD SetName(const nsAString & aName) { return _to SetName(aName); } \
  NS_SCRIPTABLE NS_IMETHOD GetValue(nsAString & aValue) { return _to GetValue(aValue); } \
  NS_SCRIPTABLE NS_IMETHOD GetDescription(nsAString & aDescription) { return _to GetDescription(aDescription); } \
  NS_SCRIPTABLE NS_IMETHOD GetKeyboardShortcut(nsAString & aKeyboardShortcut) { return _to GetKeyboardShortcut(aKeyboardShortcut); } \
  NS_SCRIPTABLE NS_IMETHOD GetDefaultKeyBinding(nsAString & aDefaultKeyBinding) { return _to GetDefaultKeyBinding(aDefaultKeyBinding); } \
  NS_SCRIPTABLE NS_IMETHOD GetKeyBindings(PRUint8 aActionIndex, nsIDOMDOMStringList **_retval NS_OUTPARAM) { return _to GetKeyBindings(aActionIndex, _retval); } \
  NS_SCRIPTABLE NS_IMETHOD GetRole(PRUint32 *aRole) { return _to GetRole(aRole); } \
  NS_SCRIPTABLE NS_IMETHOD GetFinalRole(PRUint32 *aFinalRole) { return _to GetFinalRole(aFinalRole); } \
  NS_SCRIPTABLE NS_IMETHOD GetState(PRUint32 *aState NS_OUTPARAM, PRUint32 *aExtraState NS_OUTPARAM) { return _to GetState(aState, aExtraState); } \
  NS_SCRIPTABLE NS_IMETHOD GetHelp(nsAString & aHelp) { return _to GetHelp(aHelp); } \
  NS_SCRIPTABLE NS_IMETHOD GetFocusedChild(nsIAccessible * *aFocusedChild) { return _to GetFocusedChild(aFocusedChild); } \
  NS_SCRIPTABLE NS_IMETHOD GetAttributes(nsIPersistentProperties * *aAttributes) { return _to GetAttributes(aAttributes); } \
  NS_SCRIPTABLE NS_IMETHOD GroupPosition(PRInt32 *aGroupLevel NS_OUTPARAM, PRInt32 *aSimilarItemsInGroup NS_OUTPARAM, PRInt32 *aPositionInGroup NS_OUTPARAM) { return _to GroupPosition(aGroupLevel, aSimilarItemsInGroup, aPositionInGroup); } \
  NS_SCRIPTABLE NS_IMETHOD GetChildAtPoint(PRInt32 x, PRInt32 y, nsIAccessible **_retval NS_OUTPARAM) { return _to GetChildAtPoint(x, y, _retval); } \
  NS_SCRIPTABLE NS_IMETHOD GetDeepestChildAtPoint(PRInt32 x, PRInt32 y, nsIAccessible **_retval NS_OUTPARAM) { return _to GetDeepestChildAtPoint(x, y, _retval); } \
  NS_SCRIPTABLE NS_IMETHOD GetChildAt(PRInt32 aChildIndex, nsIAccessible **_retval NS_OUTPARAM) { return _to GetChildAt(aChildIndex, _retval); } \
  NS_SCRIPTABLE NS_IMETHOD GetAccessibleToRight(nsIAccessible **_retval NS_OUTPARAM) { return _to GetAccessibleToRight(_retval); } \
  NS_SCRIPTABLE NS_IMETHOD GetAccessibleToLeft(nsIAccessible **_retval NS_OUTPARAM) { return _to GetAccessibleToLeft(_retval); } \
  NS_SCRIPTABLE NS_IMETHOD GetAccessibleAbove(nsIAccessible **_retval NS_OUTPARAM) { return _to GetAccessibleAbove(_retval); } \
  NS_SCRIPTABLE NS_IMETHOD GetAccessibleBelow(nsIAccessible **_retval NS_OUTPARAM) { return _to GetAccessibleBelow(_retval); } \
  NS_SCRIPTABLE NS_IMETHOD GetAccessibleRelated(PRUint32 aRelationType, nsIAccessible **_retval NS_OUTPARAM) { return _to GetAccessibleRelated(aRelationType, _retval); } \
  NS_SCRIPTABLE NS_IMETHOD GetRelationsCount(PRUint32 *aRelationsCount) { return _to GetRelationsCount(aRelationsCount); } \
  NS_SCRIPTABLE NS_IMETHOD GetRelation(PRUint32 index, nsIAccessibleRelation **_retval NS_OUTPARAM) { return _to GetRelation(index, _retval); } \
  NS_SCRIPTABLE NS_IMETHOD GetRelations(nsIArray **_retval NS_OUTPARAM) { return _to GetRelations(_retval); } \
  NS_SCRIPTABLE NS_IMETHOD GetBounds(PRInt32 *x NS_OUTPARAM, PRInt32 *y NS_OUTPARAM, PRInt32 *width NS_OUTPARAM, PRInt32 *height NS_OUTPARAM) { return _to GetBounds(x, y, width, height); } \
  NS_SCRIPTABLE NS_IMETHOD SetSelected(PRBool isSelected) { return _to SetSelected(isSelected); } \
  NS_SCRIPTABLE NS_IMETHOD ExtendSelection(void) { return _to ExtendSelection(); } \
  NS_SCRIPTABLE NS_IMETHOD TakeSelection(void) { return _to TakeSelection(); } \
  NS_SCRIPTABLE NS_IMETHOD TakeFocus(void) { return _to TakeFocus(); } \
  NS_SCRIPTABLE NS_IMETHOD GetNumActions(PRUint8 *aNumActions) { return _to GetNumActions(aNumActions); } \
  NS_SCRIPTABLE NS_IMETHOD GetActionName(PRUint8 index, nsAString & _retval NS_OUTPARAM) { return _to GetActionName(index, _retval); } \
  NS_SCRIPTABLE NS_IMETHOD GetActionDescription(PRUint8 aIndex, nsAString & _retval NS_OUTPARAM) { return _to GetActionDescription(aIndex, _retval); } \
  NS_SCRIPTABLE NS_IMETHOD DoAction(PRUint8 index) { return _to DoAction(index); } \
  NS_IMETHOD GetNativeInterface(void * *aOutAccessible NS_OUTPARAM) { return _to GetNativeInterface(aOutAccessible); } 

/* Use this macro to declare functions that forward the behavior of this interface to another object in a safe way. */
#define NS_FORWARD_SAFE_NSIACCESSIBLE(_to) \
  NS_SCRIPTABLE NS_IMETHOD GetParent(nsIAccessible * *aParent) { return !_to ? NS_ERROR_NULL_POINTER : _to->GetParent(aParent); } \
  NS_SCRIPTABLE NS_IMETHOD GetNextSibling(nsIAccessible * *aNextSibling) { return !_to ? NS_ERROR_NULL_POINTER : _to->GetNextSibling(aNextSibling); } \
  NS_SCRIPTABLE NS_IMETHOD GetPreviousSibling(nsIAccessible * *aPreviousSibling) { return !_to ? NS_ERROR_NULL_POINTER : _to->GetPreviousSibling(aPreviousSibling); } \
  NS_SCRIPTABLE NS_IMETHOD GetFirstChild(nsIAccessible * *aFirstChild) { return !_to ? NS_ERROR_NULL_POINTER : _to->GetFirstChild(aFirstChild); } \
  NS_SCRIPTABLE NS_IMETHOD GetLastChild(nsIAccessible * *aLastChild) { return !_to ? NS_ERROR_NULL_POINTER : _to->GetLastChild(aLastChild); } \
  NS_SCRIPTABLE NS_IMETHOD GetChildren(nsIArray * *aChildren) { return !_to ? NS_ERROR_NULL_POINTER : _to->GetChildren(aChildren); } \
  NS_SCRIPTABLE NS_IMETHOD GetChildCount(PRInt32 *aChildCount) { return !_to ? NS_ERROR_NULL_POINTER : _to->GetChildCount(aChildCount); } \
  NS_SCRIPTABLE NS_IMETHOD GetIndexInParent(PRInt32 *aIndexInParent) { return !_to ? NS_ERROR_NULL_POINTER : _to->GetIndexInParent(aIndexInParent); } \
  NS_SCRIPTABLE NS_IMETHOD GetName(nsAString & aName) { return !_to ? NS_ERROR_NULL_POINTER : _to->GetName(aName); } \
  NS_SCRIPTABLE NS_IMETHOD SetName(const nsAString & aName) { return !_to ? NS_ERROR_NULL_POINTER : _to->SetName(aName); } \
  NS_SCRIPTABLE NS_IMETHOD GetValue(nsAString & aValue) { return !_to ? NS_ERROR_NULL_POINTER : _to->GetValue(aValue); } \
  NS_SCRIPTABLE NS_IMETHOD GetDescription(nsAString & aDescription) { return !_to ? NS_ERROR_NULL_POINTER : _to->GetDescription(aDescription); } \
  NS_SCRIPTABLE NS_IMETHOD GetKeyboardShortcut(nsAString & aKeyboardShortcut) { return !_to ? NS_ERROR_NULL_POINTER : _to->GetKeyboardShortcut(aKeyboardShortcut); } \
  NS_SCRIPTABLE NS_IMETHOD GetDefaultKeyBinding(nsAString & aDefaultKeyBinding) { return !_to ? NS_ERROR_NULL_POINTER : _to->GetDefaultKeyBinding(aDefaultKeyBinding); } \
  NS_SCRIPTABLE NS_IMETHOD GetKeyBindings(PRUint8 aActionIndex, nsIDOMDOMStringList **_retval NS_OUTPARAM) { return !_to ? NS_ERROR_NULL_POINTER : _to->GetKeyBindings(aActionIndex, _retval); } \
  NS_SCRIPTABLE NS_IMETHOD GetRole(PRUint32 *aRole) { return !_to ? NS_ERROR_NULL_POINTER : _to->GetRole(aRole); } \
  NS_SCRIPTABLE NS_IMETHOD GetFinalRole(PRUint32 *aFinalRole) { return !_to ? NS_ERROR_NULL_POINTER : _to->GetFinalRole(aFinalRole); } \
  NS_SCRIPTABLE NS_IMETHOD GetState(PRUint32 *aState NS_OUTPARAM, PRUint32 *aExtraState NS_OUTPARAM) { return !_to ? NS_ERROR_NULL_POINTER : _to->GetState(aState, aExtraState); } \
  NS_SCRIPTABLE NS_IMETHOD GetHelp(nsAString & aHelp) { return !_to ? NS_ERROR_NULL_POINTER : _to->GetHelp(aHelp); } \
  NS_SCRIPTABLE NS_IMETHOD GetFocusedChild(nsIAccessible * *aFocusedChild) { return !_to ? NS_ERROR_NULL_POINTER : _to->GetFocusedChild(aFocusedChild); } \
  NS_SCRIPTABLE NS_IMETHOD GetAttributes(nsIPersistentProperties * *aAttributes) { return !_to ? NS_ERROR_NULL_POINTER : _to->GetAttributes(aAttributes); } \
  NS_SCRIPTABLE NS_IMETHOD GroupPosition(PRInt32 *aGroupLevel NS_OUTPARAM, PRInt32 *aSimilarItemsInGroup NS_OUTPARAM, PRInt32 *aPositionInGroup NS_OUTPARAM) { return !_to ? NS_ERROR_NULL_POINTER : _to->GroupPosition(aGroupLevel, aSimilarItemsInGroup, aPositionInGroup); } \
  NS_SCRIPTABLE NS_IMETHOD GetChildAtPoint(PRInt32 x, PRInt32 y, nsIAccessible **_retval NS_OUTPARAM) { return !_to ? NS_ERROR_NULL_POINTER : _to->GetChildAtPoint(x, y, _retval); } \
  NS_SCRIPTABLE NS_IMETHOD GetDeepestChildAtPoint(PRInt32 x, PRInt32 y, nsIAccessible **_retval NS_OUTPARAM) { return !_to ? NS_ERROR_NULL_POINTER : _to->GetDeepestChildAtPoint(x, y, _retval); } \
  NS_SCRIPTABLE NS_IMETHOD GetChildAt(PRInt32 aChildIndex, nsIAccessible **_retval NS_OUTPARAM) { return !_to ? NS_ERROR_NULL_POINTER : _to->GetChildAt(aChildIndex, _retval); } \
  NS_SCRIPTABLE NS_IMETHOD GetAccessibleToRight(nsIAccessible **_retval NS_OUTPARAM) { return !_to ? NS_ERROR_NULL_POINTER : _to->GetAccessibleToRight(_retval); } \
  NS_SCRIPTABLE NS_IMETHOD GetAccessibleToLeft(nsIAccessible **_retval NS_OUTPARAM) { return !_to ? NS_ERROR_NULL_POINTER : _to->GetAccessibleToLeft(_retval); } \
  NS_SCRIPTABLE NS_IMETHOD GetAccessibleAbove(nsIAccessible **_retval NS_OUTPARAM) { return !_to ? NS_ERROR_NULL_POINTER : _to->GetAccessibleAbove(_retval); } \
  NS_SCRIPTABLE NS_IMETHOD GetAccessibleBelow(nsIAccessible **_retval NS_OUTPARAM) { return !_to ? NS_ERROR_NULL_POINTER : _to->GetAccessibleBelow(_retval); } \
  NS_SCRIPTABLE NS_IMETHOD GetAccessibleRelated(PRUint32 aRelationType, nsIAccessible **_retval NS_OUTPARAM) { return !_to ? NS_ERROR_NULL_POINTER : _to->GetAccessibleRelated(aRelationType, _retval); } \
  NS_SCRIPTABLE NS_IMETHOD GetRelationsCount(PRUint32 *aRelationsCount) { return !_to ? NS_ERROR_NULL_POINTER : _to->GetRelationsCount(aRelationsCount); } \
  NS_SCRIPTABLE NS_IMETHOD GetRelation(PRUint32 index, nsIAccessibleRelation **_retval NS_OUTPARAM) { return !_to ? NS_ERROR_NULL_POINTER : _to->GetRelation(index, _retval); } \
  NS_SCRIPTABLE NS_IMETHOD GetRelations(nsIArray **_retval NS_OUTPARAM) { return !_to ? NS_ERROR_NULL_POINTER : _to->GetRelations(_retval); } \
  NS_SCRIPTABLE NS_IMETHOD GetBounds(PRInt32 *x NS_OUTPARAM, PRInt32 *y NS_OUTPARAM, PRInt32 *width NS_OUTPARAM, PRInt32 *height NS_OUTPARAM) { return !_to ? NS_ERROR_NULL_POINTER : _to->GetBounds(x, y, width, height); } \
  NS_SCRIPTABLE NS_IMETHOD SetSelected(PRBool isSelected) { return !_to ? NS_ERROR_NULL_POINTER : _to->SetSelected(isSelected); } \
  NS_SCRIPTABLE NS_IMETHOD ExtendSelection(void) { return !_to ? NS_ERROR_NULL_POINTER : _to->ExtendSelection(); } \
  NS_SCRIPTABLE NS_IMETHOD TakeSelection(void) { return !_to ? NS_ERROR_NULL_POINTER : _to->TakeSelection(); } \
  NS_SCRIPTABLE NS_IMETHOD TakeFocus(void) { return !_to ? NS_ERROR_NULL_POINTER : _to->TakeFocus(); } \
  NS_SCRIPTABLE NS_IMETHOD GetNumActions(PRUint8 *aNumActions) { return !_to ? NS_ERROR_NULL_POINTER : _to->GetNumActions(aNumActions); } \
  NS_SCRIPTABLE NS_IMETHOD GetActionName(PRUint8 index, nsAString & _retval NS_OUTPARAM) { return !_to ? NS_ERROR_NULL_POINTER : _to->GetActionName(index, _retval); } \
  NS_SCRIPTABLE NS_IMETHOD GetActionDescription(PRUint8 aIndex, nsAString & _retval NS_OUTPARAM) { return !_to ? NS_ERROR_NULL_POINTER : _to->GetActionDescription(aIndex, _retval); } \
  NS_SCRIPTABLE NS_IMETHOD DoAction(PRUint8 index) { return !_to ? NS_ERROR_NULL_POINTER : _to->DoAction(index); } \
  NS_IMETHOD GetNativeInterface(void * *aOutAccessible NS_OUTPARAM) { return !_to ? NS_ERROR_NULL_POINTER : _to->GetNativeInterface(aOutAccessible); } 

#if 0
/* Use the code below as a template for the implementation class for this interface. */

/* Header file */
class nsAccessible : public nsIAccessible
{
public:
  NS_DECL_ISUPPORTS
  NS_DECL_NSIACCESSIBLE

  nsAccessible();

private:
  ~nsAccessible();

protected:
  /* additional members */
};

/* Implementation file */
NS_IMPL_ISUPPORTS1(nsAccessible, nsIAccessible)

nsAccessible::nsAccessible()
{
  /* member initializers and constructor code */
}

nsAccessible::~nsAccessible()
{
  /* destructor code */
}

/* readonly attribute nsIAccessible parent; */
NS_IMETHODIMP nsAccessible::GetParent(nsIAccessible * *aParent)
{
    return NS_ERROR_NOT_IMPLEMENTED;
}

/* readonly attribute nsIAccessible nextSibling; */
NS_IMETHODIMP nsAccessible::GetNextSibling(nsIAccessible * *aNextSibling)
{
    return NS_ERROR_NOT_IMPLEMENTED;
}

/* readonly attribute nsIAccessible previousSibling; */
NS_IMETHODIMP nsAccessible::GetPreviousSibling(nsIAccessible * *aPreviousSibling)
{
    return NS_ERROR_NOT_IMPLEMENTED;
}

/* readonly attribute nsIAccessible firstChild; */
NS_IMETHODIMP nsAccessible::GetFirstChild(nsIAccessible * *aFirstChild)
{
    return NS_ERROR_NOT_IMPLEMENTED;
}

/* readonly attribute nsIAccessible lastChild; */
NS_IMETHODIMP nsAccessible::GetLastChild(nsIAccessible * *aLastChild)
{
    return NS_ERROR_NOT_IMPLEMENTED;
}

/* readonly attribute nsIArray children; */
NS_IMETHODIMP nsAccessible::GetChildren(nsIArray * *aChildren)
{
    return NS_ERROR_NOT_IMPLEMENTED;
}

/* readonly attribute long childCount; */
NS_IMETHODIMP nsAccessible::GetChildCount(PRInt32 *aChildCount)
{
    return NS_ERROR_NOT_IMPLEMENTED;
}

/* readonly attribute long indexInParent; */
NS_IMETHODIMP nsAccessible::GetIndexInParent(PRInt32 *aIndexInParent)
{
    return NS_ERROR_NOT_IMPLEMENTED;
}

/* attribute AString name; */
NS_IMETHODIMP nsAccessible::GetName(nsAString & aName)
{
    return NS_ERROR_NOT_IMPLEMENTED;
}
NS_IMETHODIMP nsAccessible::SetName(const nsAString & aName)
{
    return NS_ERROR_NOT_IMPLEMENTED;
}

/* readonly attribute AString value; */
NS_IMETHODIMP nsAccessible::GetValue(nsAString & aValue)
{
    return NS_ERROR_NOT_IMPLEMENTED;
}

/* readonly attribute AString description; */
NS_IMETHODIMP nsAccessible::GetDescription(nsAString & aDescription)
{
    return NS_ERROR_NOT_IMPLEMENTED;
}

/* readonly attribute AString keyboardShortcut; */
NS_IMETHODIMP nsAccessible::GetKeyboardShortcut(nsAString & aKeyboardShortcut)
{
    return NS_ERROR_NOT_IMPLEMENTED;
}

/* readonly attribute AString defaultKeyBinding; */
NS_IMETHODIMP nsAccessible::GetDefaultKeyBinding(nsAString & aDefaultKeyBinding)
{
    return NS_ERROR_NOT_IMPLEMENTED;
}

/* nsIDOMDOMStringList getKeyBindings (in PRUint8 aActionIndex); */
NS_IMETHODIMP nsAccessible::GetKeyBindings(PRUint8 aActionIndex, nsIDOMDOMStringList **_retval NS_OUTPARAM)
{
    return NS_ERROR_NOT_IMPLEMENTED;
}

/* readonly attribute unsigned long role; */
NS_IMETHODIMP nsAccessible::GetRole(PRUint32 *aRole)
{
    return NS_ERROR_NOT_IMPLEMENTED;
}

/* readonly attribute unsigned long finalRole; */
NS_IMETHODIMP nsAccessible::GetFinalRole(PRUint32 *aFinalRole)
{
    return NS_ERROR_NOT_IMPLEMENTED;
}

/* void getState (out unsigned long aState, out unsigned long aExtraState); */
NS_IMETHODIMP nsAccessible::GetState(PRUint32 *aState NS_OUTPARAM, PRUint32 *aExtraState NS_OUTPARAM)
{
    return NS_ERROR_NOT_IMPLEMENTED;
}

/* readonly attribute AString help; */
NS_IMETHODIMP nsAccessible::GetHelp(nsAString & aHelp)
{
    return NS_ERROR_NOT_IMPLEMENTED;
}

/* readonly attribute nsIAccessible focusedChild; */
NS_IMETHODIMP nsAccessible::GetFocusedChild(nsIAccessible * *aFocusedChild)
{
    return NS_ERROR_NOT_IMPLEMENTED;
}

/* readonly attribute nsIPersistentProperties attributes; */
NS_IMETHODIMP nsAccessible::GetAttributes(nsIPersistentProperties * *aAttributes)
{
    return NS_ERROR_NOT_IMPLEMENTED;
}

/* void groupPosition (out long aGroupLevel, out long aSimilarItemsInGroup, out long aPositionInGroup); */
NS_IMETHODIMP nsAccessible::GroupPosition(PRInt32 *aGroupLevel NS_OUTPARAM, PRInt32 *aSimilarItemsInGroup NS_OUTPARAM, PRInt32 *aPositionInGroup NS_OUTPARAM)
{
    return NS_ERROR_NOT_IMPLEMENTED;
}

/* nsIAccessible getChildAtPoint (in long x, in long y); */
NS_IMETHODIMP nsAccessible::GetChildAtPoint(PRInt32 x, PRInt32 y, nsIAccessible **_retval NS_OUTPARAM)
{
    return NS_ERROR_NOT_IMPLEMENTED;
}

/* nsIAccessible getDeepestChildAtPoint (in long x, in long y); */
NS_IMETHODIMP nsAccessible::GetDeepestChildAtPoint(PRInt32 x, PRInt32 y, nsIAccessible **_retval NS_OUTPARAM)
{
    return NS_ERROR_NOT_IMPLEMENTED;
}

/* nsIAccessible getChildAt (in long aChildIndex); */
NS_IMETHODIMP nsAccessible::GetChildAt(PRInt32 aChildIndex, nsIAccessible **_retval NS_OUTPARAM)
{
    return NS_ERROR_NOT_IMPLEMENTED;
}

/* nsIAccessible getAccessibleToRight (); */
NS_IMETHODIMP nsAccessible::GetAccessibleToRight(nsIAccessible **_retval NS_OUTPARAM)
{
    return NS_ERROR_NOT_IMPLEMENTED;
}

/* nsIAccessible getAccessibleToLeft (); */
NS_IMETHODIMP nsAccessible::GetAccessibleToLeft(nsIAccessible **_retval NS_OUTPARAM)
{
    return NS_ERROR_NOT_IMPLEMENTED;
}

/* nsIAccessible getAccessibleAbove (); */
NS_IMETHODIMP nsAccessible::GetAccessibleAbove(nsIAccessible **_retval NS_OUTPARAM)
{
    return NS_ERROR_NOT_IMPLEMENTED;
}

/* nsIAccessible getAccessibleBelow (); */
NS_IMETHODIMP nsAccessible::GetAccessibleBelow(nsIAccessible **_retval NS_OUTPARAM)
{
    return NS_ERROR_NOT_IMPLEMENTED;
}

/* nsIAccessible getAccessibleRelated (in unsigned long aRelationType); */
NS_IMETHODIMP nsAccessible::GetAccessibleRelated(PRUint32 aRelationType, nsIAccessible **_retval NS_OUTPARAM)
{
    return NS_ERROR_NOT_IMPLEMENTED;
}

/* readonly attribute unsigned long relationsCount; */
NS_IMETHODIMP nsAccessible::GetRelationsCount(PRUint32 *aRelationsCount)
{
    return NS_ERROR_NOT_IMPLEMENTED;
}

/* nsIAccessibleRelation getRelation (in unsigned long index); */
NS_IMETHODIMP nsAccessible::GetRelation(PRUint32 index, nsIAccessibleRelation **_retval NS_OUTPARAM)
{
    return NS_ERROR_NOT_IMPLEMENTED;
}

/* nsIArray getRelations (); */
NS_IMETHODIMP nsAccessible::GetRelations(nsIArray **_retval NS_OUTPARAM)
{
    return NS_ERROR_NOT_IMPLEMENTED;
}

/* void getBounds (out long x, out long y, out long width, out long height); */
NS_IMETHODIMP nsAccessible::GetBounds(PRInt32 *x NS_OUTPARAM, PRInt32 *y NS_OUTPARAM, PRInt32 *width NS_OUTPARAM, PRInt32 *height NS_OUTPARAM)
{
    return NS_ERROR_NOT_IMPLEMENTED;
}

/* void setSelected (in boolean isSelected); */
NS_IMETHODIMP nsAccessible::SetSelected(PRBool isSelected)
{
    return NS_ERROR_NOT_IMPLEMENTED;
}

/* void extendSelection (); */
NS_IMETHODIMP nsAccessible::ExtendSelection()
{
    return NS_ERROR_NOT_IMPLEMENTED;
}

/* void takeSelection (); */
NS_IMETHODIMP nsAccessible::TakeSelection()
{
    return NS_ERROR_NOT_IMPLEMENTED;
}

/* void takeFocus (); */
NS_IMETHODIMP nsAccessible::TakeFocus()
{
    return NS_ERROR_NOT_IMPLEMENTED;
}

/* readonly attribute PRUint8 numActions; */
NS_IMETHODIMP nsAccessible::GetNumActions(PRUint8 *aNumActions)
{
    return NS_ERROR_NOT_IMPLEMENTED;
}

/* AString getActionName (in PRUint8 index); */
NS_IMETHODIMP nsAccessible::GetActionName(PRUint8 index, nsAString & _retval NS_OUTPARAM)
{
    return NS_ERROR_NOT_IMPLEMENTED;
}

/* AString getActionDescription (in PRUint8 aIndex); */
NS_IMETHODIMP nsAccessible::GetActionDescription(PRUint8 aIndex, nsAString & _retval NS_OUTPARAM)
{
    return NS_ERROR_NOT_IMPLEMENTED;
}

/* void doAction (in PRUint8 index); */
NS_IMETHODIMP nsAccessible::DoAction(PRUint8 index)
{
    return NS_ERROR_NOT_IMPLEMENTED;
}

/* [noscript] void getNativeInterface (out voidPtr aOutAccessible); */
NS_IMETHODIMP nsAccessible::GetNativeInterface(void * *aOutAccessible NS_OUTPARAM)
{
    return NS_ERROR_NOT_IMPLEMENTED;
}

/* End of implementation class template. */
#endif


#endif /* __gen_nsIAccessible_h__ */
