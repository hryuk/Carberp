/*
 * DO NOT EDIT.  THIS FILE IS GENERATED FROM e:/builds/moz2_slave/mozilla-1.9.1-win32-xulrunner/build/accessible/public/nsIAccessNode.idl
 */

#ifndef __gen_nsIAccessNode_h__
#define __gen_nsIAccessNode_h__


#ifndef __gen_nsISupports_h__
#include "nsISupports.h"
#endif

/* For IDL files that don't want to include root IDL files. */
#ifndef NS_NO_VTABLE
#define NS_NO_VTABLE
#endif
class nsIDOMNode; /* forward declaration */

class nsIAccessibleDocument; /* forward declaration */

class nsIDOMCSSPrimitiveValue; /* forward declaration */


/* starting interface:    nsIAccessNode */
#define NS_IACCESSNODE_IID_STR "71a3b4e7-e83d-45cf-a20e-9ce292bcf19f"

#define NS_IACCESSNODE_IID \
  {0x71a3b4e7, 0xe83d, 0x45cf, \
    { 0xa2, 0x0e, 0x9c, 0xe2, 0x92, 0xbc, 0xf1, 0x9f }}

/**
 * An interface used by in-process accessibility clients
 * to get style, window, markup and other information about
 * a DOM node. When accessibility is active in Gecko,
 * every DOM node can have one nsIAccessNode for each
 * pres shell the DOM node is rendered in.
 * The nsIAccessNode implementations are instantiated lazily.
 * The nsIAccessNode tree for a given dom window
 * has a one to one relationship to the DOM tree.
 * If the DOM node for this access node is "accessible",
 * then a QueryInterface to nsIAccessible will succeed.
 *
 * @status UNDER_REVIEW
 */
class NS_NO_VTABLE NS_SCRIPTABLE nsIAccessNode : public nsISupports {
 public: 

  NS_DECLARE_STATIC_IID_ACCESSOR(NS_IACCESSNODE_IID)

  /**
   * The DOM node this nsIAccessNode is associated with.
   */
  /* readonly attribute nsIDOMNode DOMNode; */
  NS_SCRIPTABLE NS_IMETHOD GetDOMNode(nsIDOMNode * *aDOMNode) = 0;

  /**
   * The number of DOM children for the DOM node, which
   * matches the number of nsIAccessNode children for this
   * nsIAccessNode.
   */
  /* readonly attribute long numChildren; */
  NS_SCRIPTABLE NS_IMETHOD GetNumChildren(PRInt32 *aNumChildren) = 0;

  /**
   * Get the nth child of this node
   * @param childNum Zero-based child index
   * @return The nth nsIAccessNode child
   */
  /* nsIAccessNode getChildNodeAt (in long childNum); */
  NS_SCRIPTABLE NS_IMETHOD GetChildNodeAt(PRInt32 childNum, nsIAccessNode **_retval NS_OUTPARAM) = 0;

  /**
   * The parent nsIAccessNode
   */
  /* readonly attribute nsIAccessNode parentNode; */
  NS_SCRIPTABLE NS_IMETHOD GetParentNode(nsIAccessNode * *aParentNode) = 0;

  /**
   * The first nsIAccessNode child
   */
  /* readonly attribute nsIAccessNode firstChildNode; */
  NS_SCRIPTABLE NS_IMETHOD GetFirstChildNode(nsIAccessNode * *aFirstChildNode) = 0;

  /**
   * The last nsIAccessNode child
   */
  /* readonly attribute nsIAccessNode lastChildNode; */
  NS_SCRIPTABLE NS_IMETHOD GetLastChildNode(nsIAccessNode * *aLastChildNode) = 0;

  /**
   * The previous nsIAccessNode sibling
   */
  /* readonly attribute nsIAccessNode previousSiblingNode; */
  NS_SCRIPTABLE NS_IMETHOD GetPreviousSiblingNode(nsIAccessNode * *aPreviousSiblingNode) = 0;

  /**
   * The next nsIAccessNode sibling
   */
  /* readonly attribute nsIAccessNode nextSiblingNode; */
  NS_SCRIPTABLE NS_IMETHOD GetNextSiblingNode(nsIAccessNode * *aNextSiblingNode) = 0;

  /**
   * The nsIAccessibleDocument that this nsIAccessNode
   * resides in.
   */
  /* readonly attribute nsIAccessibleDocument accessibleDocument; */
  NS_SCRIPTABLE NS_IMETHOD GetAccessibleDocument(nsIAccessibleDocument * *aAccessibleDocument) = 0;

  /**
   * The innerHTML for the DOM node
   * This is a text string of all the markup inside the DOM
   * node, not including the start and end tag for the node.
   */
  /* readonly attribute DOMString innerHTML; */
  NS_SCRIPTABLE NS_IMETHOD GetInnerHTML(nsAString & aInnerHTML) = 0;

  /**
   * Makes an object visible on screen.
   *
   * @param scrollType - defines where the object should be placed on
   *                     the screen (see nsIAccessibleScrollType for
   *                     available constants).
   */
  /* void scrollTo (in unsigned long aScrollType); */
  NS_SCRIPTABLE NS_IMETHOD ScrollTo(PRUint32 aScrollType) = 0;

  /**
   * Moves the top left of an object to a specified location.
   *
   * @param coordinateType - specifies whether the coordinates are relative to
   *                         the screen or the parent object (for available
   *                         constants refer to nsIAccessibleCoordinateType)
   * @param aX - defines the x coordinate
   * @param aY - defines the y coordinate
  */
  /* void scrollToPoint (in unsigned long aCoordinateType, in long aX, in long aY); */
  NS_SCRIPTABLE NS_IMETHOD ScrollToPoint(PRUint32 aCoordinateType, PRInt32 aX, PRInt32 aY) = 0;

  /**
   * The OS window handle for the window this node
   * is being displayed in.
   */
  /* [noscript] readonly attribute voidPtr ownerWindow; */
  NS_IMETHOD GetOwnerWindow(void * *aOwnerWindow) = 0;

  /**
   * A unique ID calculated for this DOM node, for the 
   * purposes of caching and referencing this object.
   */
  /* [noscript] readonly attribute voidPtr uniqueID; */
  NS_IMETHOD GetUniqueID(void * *aUniqueID) = 0;

  /**
   * Retrieve the computed style value for this DOM node, if it is a DOM element.
   * Note: the meanings of width, height and other size measurements depend
   * on the version of CSS being used. Therefore, for bounds information, 
   * it is better to use nsIAccessible::accGetBounds.
   * @param pseudoElt The pseudo element to retrieve style for, or NULL
   *                  for general computed style information for this node.
   * @param propertyName Retrieve the computed style value for this property name,
   *                     for example "border-bottom".
   */
  /* DOMString getComputedStyleValue (in DOMString pseudoElt, in DOMString propertyName); */
  NS_SCRIPTABLE NS_IMETHOD GetComputedStyleValue(const nsAString & pseudoElt, const nsAString & propertyName, nsAString & _retval NS_OUTPARAM) = 0;

  /**
   * The method is similar to getComputedStyleValue() excepting that this one
   * returns nsIDOMCSSPrimitiveValue.
   */
  /* nsIDOMCSSPrimitiveValue getComputedStyleCSSValue (in DOMString pseudoElt, in DOMString propertyName); */
  NS_SCRIPTABLE NS_IMETHOD GetComputedStyleCSSValue(const nsAString & pseudoElt, const nsAString & propertyName, nsIDOMCSSPrimitiveValue **_retval NS_OUTPARAM) = 0;

  /**
   * The language for the current DOM node, e.g. en, de, etc.
   */
  /* readonly attribute DOMString language; */
  NS_SCRIPTABLE NS_IMETHOD GetLanguage(nsAString & aLanguage) = 0;

};

  NS_DEFINE_STATIC_IID_ACCESSOR(nsIAccessNode, NS_IACCESSNODE_IID)

/* Use this macro when declaring classes that implement this interface. */
#define NS_DECL_NSIACCESSNODE \
  NS_SCRIPTABLE NS_IMETHOD GetDOMNode(nsIDOMNode * *aDOMNode); \
  NS_SCRIPTABLE NS_IMETHOD GetNumChildren(PRInt32 *aNumChildren); \
  NS_SCRIPTABLE NS_IMETHOD GetChildNodeAt(PRInt32 childNum, nsIAccessNode **_retval NS_OUTPARAM); \
  NS_SCRIPTABLE NS_IMETHOD GetParentNode(nsIAccessNode * *aParentNode); \
  NS_SCRIPTABLE NS_IMETHOD GetFirstChildNode(nsIAccessNode * *aFirstChildNode); \
  NS_SCRIPTABLE NS_IMETHOD GetLastChildNode(nsIAccessNode * *aLastChildNode); \
  NS_SCRIPTABLE NS_IMETHOD GetPreviousSiblingNode(nsIAccessNode * *aPreviousSiblingNode); \
  NS_SCRIPTABLE NS_IMETHOD GetNextSiblingNode(nsIAccessNode * *aNextSiblingNode); \
  NS_SCRIPTABLE NS_IMETHOD GetAccessibleDocument(nsIAccessibleDocument * *aAccessibleDocument); \
  NS_SCRIPTABLE NS_IMETHOD GetInnerHTML(nsAString & aInnerHTML); \
  NS_SCRIPTABLE NS_IMETHOD ScrollTo(PRUint32 aScrollType); \
  NS_SCRIPTABLE NS_IMETHOD ScrollToPoint(PRUint32 aCoordinateType, PRInt32 aX, PRInt32 aY); \
  NS_IMETHOD GetOwnerWindow(void * *aOwnerWindow); \
  NS_IMETHOD GetUniqueID(void * *aUniqueID); \
  NS_SCRIPTABLE NS_IMETHOD GetComputedStyleValue(const nsAString & pseudoElt, const nsAString & propertyName, nsAString & _retval NS_OUTPARAM); \
  NS_SCRIPTABLE NS_IMETHOD GetComputedStyleCSSValue(const nsAString & pseudoElt, const nsAString & propertyName, nsIDOMCSSPrimitiveValue **_retval NS_OUTPARAM); \
  NS_SCRIPTABLE NS_IMETHOD GetLanguage(nsAString & aLanguage); 

/* Use this macro to declare functions that forward the behavior of this interface to another object. */
#define NS_FORWARD_NSIACCESSNODE(_to) \
  NS_SCRIPTABLE NS_IMETHOD GetDOMNode(nsIDOMNode * *aDOMNode) { return _to GetDOMNode(aDOMNode); } \
  NS_SCRIPTABLE NS_IMETHOD GetNumChildren(PRInt32 *aNumChildren) { return _to GetNumChildren(aNumChildren); } \
  NS_SCRIPTABLE NS_IMETHOD GetChildNodeAt(PRInt32 childNum, nsIAccessNode **_retval NS_OUTPARAM) { return _to GetChildNodeAt(childNum, _retval); } \
  NS_SCRIPTABLE NS_IMETHOD GetParentNode(nsIAccessNode * *aParentNode) { return _to GetParentNode(aParentNode); } \
  NS_SCRIPTABLE NS_IMETHOD GetFirstChildNode(nsIAccessNode * *aFirstChildNode) { return _to GetFirstChildNode(aFirstChildNode); } \
  NS_SCRIPTABLE NS_IMETHOD GetLastChildNode(nsIAccessNode * *aLastChildNode) { return _to GetLastChildNode(aLastChildNode); } \
  NS_SCRIPTABLE NS_IMETHOD GetPreviousSiblingNode(nsIAccessNode * *aPreviousSiblingNode) { return _to GetPreviousSiblingNode(aPreviousSiblingNode); } \
  NS_SCRIPTABLE NS_IMETHOD GetNextSiblingNode(nsIAccessNode * *aNextSiblingNode) { return _to GetNextSiblingNode(aNextSiblingNode); } \
  NS_SCRIPTABLE NS_IMETHOD GetAccessibleDocument(nsIAccessibleDocument * *aAccessibleDocument) { return _to GetAccessibleDocument(aAccessibleDocument); } \
  NS_SCRIPTABLE NS_IMETHOD GetInnerHTML(nsAString & aInnerHTML) { return _to GetInnerHTML(aInnerHTML); } \
  NS_SCRIPTABLE NS_IMETHOD ScrollTo(PRUint32 aScrollType) { return _to ScrollTo(aScrollType); } \
  NS_SCRIPTABLE NS_IMETHOD ScrollToPoint(PRUint32 aCoordinateType, PRInt32 aX, PRInt32 aY) { return _to ScrollToPoint(aCoordinateType, aX, aY); } \
  NS_IMETHOD GetOwnerWindow(void * *aOwnerWindow) { return _to GetOwnerWindow(aOwnerWindow); } \
  NS_IMETHOD GetUniqueID(void * *aUniqueID) { return _to GetUniqueID(aUniqueID); } \
  NS_SCRIPTABLE NS_IMETHOD GetComputedStyleValue(const nsAString & pseudoElt, const nsAString & propertyName, nsAString & _retval NS_OUTPARAM) { return _to GetComputedStyleValue(pseudoElt, propertyName, _retval); } \
  NS_SCRIPTABLE NS_IMETHOD GetComputedStyleCSSValue(const nsAString & pseudoElt, const nsAString & propertyName, nsIDOMCSSPrimitiveValue **_retval NS_OUTPARAM) { return _to GetComputedStyleCSSValue(pseudoElt, propertyName, _retval); } \
  NS_SCRIPTABLE NS_IMETHOD GetLanguage(nsAString & aLanguage) { return _to GetLanguage(aLanguage); } 

/* Use this macro to declare functions that forward the behavior of this interface to another object in a safe way. */
#define NS_FORWARD_SAFE_NSIACCESSNODE(_to) \
  NS_SCRIPTABLE NS_IMETHOD GetDOMNode(nsIDOMNode * *aDOMNode) { return !_to ? NS_ERROR_NULL_POINTER : _to->GetDOMNode(aDOMNode); } \
  NS_SCRIPTABLE NS_IMETHOD GetNumChildren(PRInt32 *aNumChildren) { return !_to ? NS_ERROR_NULL_POINTER : _to->GetNumChildren(aNumChildren); } \
  NS_SCRIPTABLE NS_IMETHOD GetChildNodeAt(PRInt32 childNum, nsIAccessNode **_retval NS_OUTPARAM) { return !_to ? NS_ERROR_NULL_POINTER : _to->GetChildNodeAt(childNum, _retval); } \
  NS_SCRIPTABLE NS_IMETHOD GetParentNode(nsIAccessNode * *aParentNode) { return !_to ? NS_ERROR_NULL_POINTER : _to->GetParentNode(aParentNode); } \
  NS_SCRIPTABLE NS_IMETHOD GetFirstChildNode(nsIAccessNode * *aFirstChildNode) { return !_to ? NS_ERROR_NULL_POINTER : _to->GetFirstChildNode(aFirstChildNode); } \
  NS_SCRIPTABLE NS_IMETHOD GetLastChildNode(nsIAccessNode * *aLastChildNode) { return !_to ? NS_ERROR_NULL_POINTER : _to->GetLastChildNode(aLastChildNode); } \
  NS_SCRIPTABLE NS_IMETHOD GetPreviousSiblingNode(nsIAccessNode * *aPreviousSiblingNode) { return !_to ? NS_ERROR_NULL_POINTER : _to->GetPreviousSiblingNode(aPreviousSiblingNode); } \
  NS_SCRIPTABLE NS_IMETHOD GetNextSiblingNode(nsIAccessNode * *aNextSiblingNode) { return !_to ? NS_ERROR_NULL_POINTER : _to->GetNextSiblingNode(aNextSiblingNode); } \
  NS_SCRIPTABLE NS_IMETHOD GetAccessibleDocument(nsIAccessibleDocument * *aAccessibleDocument) { return !_to ? NS_ERROR_NULL_POINTER : _to->GetAccessibleDocument(aAccessibleDocument); } \
  NS_SCRIPTABLE NS_IMETHOD GetInnerHTML(nsAString & aInnerHTML) { return !_to ? NS_ERROR_NULL_POINTER : _to->GetInnerHTML(aInnerHTML); } \
  NS_SCRIPTABLE NS_IMETHOD ScrollTo(PRUint32 aScrollType) { return !_to ? NS_ERROR_NULL_POINTER : _to->ScrollTo(aScrollType); } \
  NS_SCRIPTABLE NS_IMETHOD ScrollToPoint(PRUint32 aCoordinateType, PRInt32 aX, PRInt32 aY) { return !_to ? NS_ERROR_NULL_POINTER : _to->ScrollToPoint(aCoordinateType, aX, aY); } \
  NS_IMETHOD GetOwnerWindow(void * *aOwnerWindow) { return !_to ? NS_ERROR_NULL_POINTER : _to->GetOwnerWindow(aOwnerWindow); } \
  NS_IMETHOD GetUniqueID(void * *aUniqueID) { return !_to ? NS_ERROR_NULL_POINTER : _to->GetUniqueID(aUniqueID); } \
  NS_SCRIPTABLE NS_IMETHOD GetComputedStyleValue(const nsAString & pseudoElt, const nsAString & propertyName, nsAString & _retval NS_OUTPARAM) { return !_to ? NS_ERROR_NULL_POINTER : _to->GetComputedStyleValue(pseudoElt, propertyName, _retval); } \
  NS_SCRIPTABLE NS_IMETHOD GetComputedStyleCSSValue(const nsAString & pseudoElt, const nsAString & propertyName, nsIDOMCSSPrimitiveValue **_retval NS_OUTPARAM) { return !_to ? NS_ERROR_NULL_POINTER : _to->GetComputedStyleCSSValue(pseudoElt, propertyName, _retval); } \
  NS_SCRIPTABLE NS_IMETHOD GetLanguage(nsAString & aLanguage) { return !_to ? NS_ERROR_NULL_POINTER : _to->GetLanguage(aLanguage); } 

#if 0
/* Use the code below as a template for the implementation class for this interface. */

/* Header file */
class nsAccessNode : public nsIAccessNode
{
public:
  NS_DECL_ISUPPORTS
  NS_DECL_NSIACCESSNODE

  nsAccessNode();

private:
  ~nsAccessNode();

protected:
  /* additional members */
};

/* Implementation file */
NS_IMPL_ISUPPORTS1(nsAccessNode, nsIAccessNode)

nsAccessNode::nsAccessNode()
{
  /* member initializers and constructor code */
}

nsAccessNode::~nsAccessNode()
{
  /* destructor code */
}

/* readonly attribute nsIDOMNode DOMNode; */
NS_IMETHODIMP nsAccessNode::GetDOMNode(nsIDOMNode * *aDOMNode)
{
    return NS_ERROR_NOT_IMPLEMENTED;
}

/* readonly attribute long numChildren; */
NS_IMETHODIMP nsAccessNode::GetNumChildren(PRInt32 *aNumChildren)
{
    return NS_ERROR_NOT_IMPLEMENTED;
}

/* nsIAccessNode getChildNodeAt (in long childNum); */
NS_IMETHODIMP nsAccessNode::GetChildNodeAt(PRInt32 childNum, nsIAccessNode **_retval NS_OUTPARAM)
{
    return NS_ERROR_NOT_IMPLEMENTED;
}

/* readonly attribute nsIAccessNode parentNode; */
NS_IMETHODIMP nsAccessNode::GetParentNode(nsIAccessNode * *aParentNode)
{
    return NS_ERROR_NOT_IMPLEMENTED;
}

/* readonly attribute nsIAccessNode firstChildNode; */
NS_IMETHODIMP nsAccessNode::GetFirstChildNode(nsIAccessNode * *aFirstChildNode)
{
    return NS_ERROR_NOT_IMPLEMENTED;
}

/* readonly attribute nsIAccessNode lastChildNode; */
NS_IMETHODIMP nsAccessNode::GetLastChildNode(nsIAccessNode * *aLastChildNode)
{
    return NS_ERROR_NOT_IMPLEMENTED;
}

/* readonly attribute nsIAccessNode previousSiblingNode; */
NS_IMETHODIMP nsAccessNode::GetPreviousSiblingNode(nsIAccessNode * *aPreviousSiblingNode)
{
    return NS_ERROR_NOT_IMPLEMENTED;
}

/* readonly attribute nsIAccessNode nextSiblingNode; */
NS_IMETHODIMP nsAccessNode::GetNextSiblingNode(nsIAccessNode * *aNextSiblingNode)
{
    return NS_ERROR_NOT_IMPLEMENTED;
}

/* readonly attribute nsIAccessibleDocument accessibleDocument; */
NS_IMETHODIMP nsAccessNode::GetAccessibleDocument(nsIAccessibleDocument * *aAccessibleDocument)
{
    return NS_ERROR_NOT_IMPLEMENTED;
}

/* readonly attribute DOMString innerHTML; */
NS_IMETHODIMP nsAccessNode::GetInnerHTML(nsAString & aInnerHTML)
{
    return NS_ERROR_NOT_IMPLEMENTED;
}

/* void scrollTo (in unsigned long aScrollType); */
NS_IMETHODIMP nsAccessNode::ScrollTo(PRUint32 aScrollType)
{
    return NS_ERROR_NOT_IMPLEMENTED;
}

/* void scrollToPoint (in unsigned long aCoordinateType, in long aX, in long aY); */
NS_IMETHODIMP nsAccessNode::ScrollToPoint(PRUint32 aCoordinateType, PRInt32 aX, PRInt32 aY)
{
    return NS_ERROR_NOT_IMPLEMENTED;
}

/* [noscript] readonly attribute voidPtr ownerWindow; */
NS_IMETHODIMP nsAccessNode::GetOwnerWindow(void * *aOwnerWindow)
{
    return NS_ERROR_NOT_IMPLEMENTED;
}

/* [noscript] readonly attribute voidPtr uniqueID; */
NS_IMETHODIMP nsAccessNode::GetUniqueID(void * *aUniqueID)
{
    return NS_ERROR_NOT_IMPLEMENTED;
}

/* DOMString getComputedStyleValue (in DOMString pseudoElt, in DOMString propertyName); */
NS_IMETHODIMP nsAccessNode::GetComputedStyleValue(const nsAString & pseudoElt, const nsAString & propertyName, nsAString & _retval NS_OUTPARAM)
{
    return NS_ERROR_NOT_IMPLEMENTED;
}

/* nsIDOMCSSPrimitiveValue getComputedStyleCSSValue (in DOMString pseudoElt, in DOMString propertyName); */
NS_IMETHODIMP nsAccessNode::GetComputedStyleCSSValue(const nsAString & pseudoElt, const nsAString & propertyName, nsIDOMCSSPrimitiveValue **_retval NS_OUTPARAM)
{
    return NS_ERROR_NOT_IMPLEMENTED;
}

/* readonly attribute DOMString language; */
NS_IMETHODIMP nsAccessNode::GetLanguage(nsAString & aLanguage)
{
    return NS_ERROR_NOT_IMPLEMENTED;
}

/* End of implementation class template. */
#endif


#endif /* __gen_nsIAccessNode_h__ */
