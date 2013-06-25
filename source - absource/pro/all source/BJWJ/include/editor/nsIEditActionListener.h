/*
 * DO NOT EDIT.  THIS FILE IS GENERATED FROM e:/builds/moz2_slave/mozilla-1.9.1-win32-xulrunner/build/editor/idl/nsIEditActionListener.idl
 */

#ifndef __gen_nsIEditActionListener_h__
#define __gen_nsIEditActionListener_h__


#ifndef __gen_nsISupports_h__
#include "nsISupports.h"
#endif

#ifndef __gen_domstubs_h__
#include "domstubs.h"
#endif

/* For IDL files that don't want to include root IDL files. */
#ifndef NS_NO_VTABLE
#define NS_NO_VTABLE
#endif
class nsISelection; /* forward declaration */


/* starting interface:    nsIEditActionListener */
#define NS_IEDITACTIONLISTENER_IID_STR "b22907b1-ee93-11d2-8d50-000064657374"

#define NS_IEDITACTIONLISTENER_IID \
  {0xb22907b1, 0xee93, 0x11d2, \
    { 0x8d, 0x50, 0x00, 0x00, 0x64, 0x65, 0x73, 0x74 }}

/**
 * A generic editor action listener interface. 
 * <P>
 * nsIEditActionListener is the interface used by applications wishing to be notified
 * when the editor modifies the DOM tree.
 *
 * Note:  this is the wrong class to implement if you are interested in generic
 * change notifications.  For generic notifications, you should implement
 * nsIDocumentObserver.
 */
class NS_NO_VTABLE NS_SCRIPTABLE nsIEditActionListener : public nsISupports {
 public: 

  NS_DECLARE_STATIC_IID_ACCESSOR(NS_IEDITACTIONLISTENER_IID)

  /** 
   * Called before the editor creates a node.
   * @param aTag      The tag name of the DOM Node to create.
   * @param aParent   The node to insert the new object into
   * @param aPosition The place in aParent to insert the new node
   *                  0=first child, 1=second child, etc.
   *                  any number > number of current children = last child
   */
  /* void WillCreateNode (in DOMString aTag, in nsIDOMNode aParent, in long aPosition); */
  NS_SCRIPTABLE NS_IMETHOD WillCreateNode(const nsAString & aTag, nsIDOMNode *aParent, PRInt32 aPosition) = 0;

  /** 
   * Called after the editor creates a node.
   * @param aTag      The tag name of the DOM Node to create.
   * @param aNode     The DOM Node that was created.
   * @param aParent   The node to insert the new object into
   * @param aPosition The place in aParent to insert the new node
   *                  0=first child, 1=second child, etc.
   *                  any number > number of current children = last child
   * @param aResult   The result of the create node operation.
   */
  /* void DidCreateNode (in DOMString aTag, in nsIDOMNode aNode, in nsIDOMNode aParent, in long aPosition, in nsresult aResult); */
  NS_SCRIPTABLE NS_IMETHOD DidCreateNode(const nsAString & aTag, nsIDOMNode *aNode, nsIDOMNode *aParent, PRInt32 aPosition, nsresult aResult) = 0;

  /** 
   * Called before the editor inserts a node.
   * @param aNode     The DOM Node to insert.
   * @param aParent   The node to insert the new object into
   * @param aPosition The place in aParent to insert the new node
   *                  0=first child, 1=second child, etc.
   *                  any number > number of current children = last child
   */
  /* void WillInsertNode (in nsIDOMNode aNode, in nsIDOMNode aParent, in long aPosition); */
  NS_SCRIPTABLE NS_IMETHOD WillInsertNode(nsIDOMNode *aNode, nsIDOMNode *aParent, PRInt32 aPosition) = 0;

  /** 
   * Called after the editor inserts a node.
   * @param aNode     The DOM Node to insert.
   * @param aParent   The node to insert the new object into
   * @param aPosition The place in aParent to insert the new node
   *                  0=first child, 1=second child, etc.
   *                  any number > number of current children = last child
   * @param aResult   The result of the insert node operation.
   */
  /* void DidInsertNode (in nsIDOMNode aNode, in nsIDOMNode aParent, in long aPosition, in nsresult aResult); */
  NS_SCRIPTABLE NS_IMETHOD DidInsertNode(nsIDOMNode *aNode, nsIDOMNode *aParent, PRInt32 aPosition, nsresult aResult) = 0;

  /** 
   * Called before the editor deletes a node.
   * @param aChild    The node to delete
   */
  /* void WillDeleteNode (in nsIDOMNode aChild); */
  NS_SCRIPTABLE NS_IMETHOD WillDeleteNode(nsIDOMNode *aChild) = 0;

  /** 
   * Called after the editor deletes a node.
   * @param aChild    The node to delete
   * @param aResult   The result of the delete node operation.
   */
  /* void DidDeleteNode (in nsIDOMNode aChild, in nsresult aResult); */
  NS_SCRIPTABLE NS_IMETHOD DidDeleteNode(nsIDOMNode *aChild, nsresult aResult) = 0;

  /** 
   * Called before the editor splits a node.
   * @param aExistingRightNode   the node to split.  It will become the new node's next sibling.
   * @param aOffset              the offset of aExistingRightNode's content|children to do the split at
   * @param aNewLeftNode         [OUT] the new node resulting from the split, becomes aExistingRightNode's previous sibling.
   */
  /* void WillSplitNode (in nsIDOMNode aExistingRightNode, in long aOffset); */
  NS_SCRIPTABLE NS_IMETHOD WillSplitNode(nsIDOMNode *aExistingRightNode, PRInt32 aOffset) = 0;

  /** 
   * Called after the editor splits a node.
   * @param aExistingRightNode   the node to split.  It will become the new node's next sibling.
   * @param aOffset              the offset of aExistingRightNode's content|children to do the split at
   * @param aNewLeftNode         [OUT] the new node resulting from the split, becomes aExistingRightNode's previous sibling.
   */
  /* void DidSplitNode (in nsIDOMNode aExistingRightNode, in long aOffset, in nsIDOMNode aNewLeftNode, in nsresult aResult); */
  NS_SCRIPTABLE NS_IMETHOD DidSplitNode(nsIDOMNode *aExistingRightNode, PRInt32 aOffset, nsIDOMNode *aNewLeftNode, nsresult aResult) = 0;

  /** 
   * Called before the editor joins 2 nodes.
   * @param aLeftNode   This node will be merged into the right node
   * @param aRightNode  The node that will be merged into.
   *                    There is no requirement that the two nodes be of
   *                    the same type.
   * @param aParent     The parent of aRightNode
   */
  /* void WillJoinNodes (in nsIDOMNode aLeftNode, in nsIDOMNode aRightNode, in nsIDOMNode aParent); */
  NS_SCRIPTABLE NS_IMETHOD WillJoinNodes(nsIDOMNode *aLeftNode, nsIDOMNode *aRightNode, nsIDOMNode *aParent) = 0;

  /** 
   * Called after the editor joins 2 nodes.
   * @param aLeftNode   This node will be merged into the right node
   * @param aRightNode  The node that will be merged into.
   *                    There is no requirement that the two nodes be of
   *                    the same type.
   * @param aParent     The parent of aRightNode
   * @param aResult     The result of the join operation.
   */
  /* void DidJoinNodes (in nsIDOMNode aLeftNode, in nsIDOMNode aRightNode, in nsIDOMNode aParent, in nsresult aResult); */
  NS_SCRIPTABLE NS_IMETHOD DidJoinNodes(nsIDOMNode *aLeftNode, nsIDOMNode *aRightNode, nsIDOMNode *aParent, nsresult aResult) = 0;

  /** 
   * Called before the editor inserts text.
   * @param aTextNode   This node getting inserted text
   * @param aOffset     The offset in aTextNode to insert at.
   * @param aString     The string that gets inserted.
   */
  /* void WillInsertText (in nsIDOMCharacterData aTextNode, in long aOffset, in DOMString aString); */
  NS_SCRIPTABLE NS_IMETHOD WillInsertText(nsIDOMCharacterData *aTextNode, PRInt32 aOffset, const nsAString & aString) = 0;

  /** 
   * Called after the editor inserts text.
   * @param aTextNode   This node getting inserted text
   * @param aOffset     The offset in aTextNode to insert at.
   * @param aString     The string that gets inserted.
   * @param aResult     The result of the insert text operation.
   */
  /* void DidInsertText (in nsIDOMCharacterData aTextNode, in long aOffset, in DOMString aString, in nsresult aResult); */
  NS_SCRIPTABLE NS_IMETHOD DidInsertText(nsIDOMCharacterData *aTextNode, PRInt32 aOffset, const nsAString & aString, nsresult aResult) = 0;

  /** 
   * Called before the editor deletes text.
   * @param aTextNode   This node getting text deleted
   * @param aOffset     The offset in aTextNode to delete at.
   * @param aLength     The amount of text to delete.
   */
  /* void WillDeleteText (in nsIDOMCharacterData aTextNode, in long aOffset, in long aLength); */
  NS_SCRIPTABLE NS_IMETHOD WillDeleteText(nsIDOMCharacterData *aTextNode, PRInt32 aOffset, PRInt32 aLength) = 0;

  /** 
   * Called before the editor deletes text.
   * @param aTextNode   This node getting text deleted
   * @param aOffset     The offset in aTextNode to delete at.
   * @param aLength     The amount of text to delete.
   * @param aResult     The result of the delete text operation.
   */
  /* void DidDeleteText (in nsIDOMCharacterData aTextNode, in long aOffset, in long aLength, in nsresult aResult); */
  NS_SCRIPTABLE NS_IMETHOD DidDeleteText(nsIDOMCharacterData *aTextNode, PRInt32 aOffset, PRInt32 aLength, nsresult aResult) = 0;

  /** 
   * Called before the editor deletes the selection.
   * @param aSelection   The selection to be deleted
   */
  /* void WillDeleteSelection (in nsISelection aSelection); */
  NS_SCRIPTABLE NS_IMETHOD WillDeleteSelection(nsISelection *aSelection) = 0;

  /** 
   * Called after the editor deletes the selection.
   * @param aSelection   The selection, after deletion
   */
  /* void DidDeleteSelection (in nsISelection aSelection); */
  NS_SCRIPTABLE NS_IMETHOD DidDeleteSelection(nsISelection *aSelection) = 0;

};

  NS_DEFINE_STATIC_IID_ACCESSOR(nsIEditActionListener, NS_IEDITACTIONLISTENER_IID)

/* Use this macro when declaring classes that implement this interface. */
#define NS_DECL_NSIEDITACTIONLISTENER \
  NS_SCRIPTABLE NS_IMETHOD WillCreateNode(const nsAString & aTag, nsIDOMNode *aParent, PRInt32 aPosition); \
  NS_SCRIPTABLE NS_IMETHOD DidCreateNode(const nsAString & aTag, nsIDOMNode *aNode, nsIDOMNode *aParent, PRInt32 aPosition, nsresult aResult); \
  NS_SCRIPTABLE NS_IMETHOD WillInsertNode(nsIDOMNode *aNode, nsIDOMNode *aParent, PRInt32 aPosition); \
  NS_SCRIPTABLE NS_IMETHOD DidInsertNode(nsIDOMNode *aNode, nsIDOMNode *aParent, PRInt32 aPosition, nsresult aResult); \
  NS_SCRIPTABLE NS_IMETHOD WillDeleteNode(nsIDOMNode *aChild); \
  NS_SCRIPTABLE NS_IMETHOD DidDeleteNode(nsIDOMNode *aChild, nsresult aResult); \
  NS_SCRIPTABLE NS_IMETHOD WillSplitNode(nsIDOMNode *aExistingRightNode, PRInt32 aOffset); \
  NS_SCRIPTABLE NS_IMETHOD DidSplitNode(nsIDOMNode *aExistingRightNode, PRInt32 aOffset, nsIDOMNode *aNewLeftNode, nsresult aResult); \
  NS_SCRIPTABLE NS_IMETHOD WillJoinNodes(nsIDOMNode *aLeftNode, nsIDOMNode *aRightNode, nsIDOMNode *aParent); \
  NS_SCRIPTABLE NS_IMETHOD DidJoinNodes(nsIDOMNode *aLeftNode, nsIDOMNode *aRightNode, nsIDOMNode *aParent, nsresult aResult); \
  NS_SCRIPTABLE NS_IMETHOD WillInsertText(nsIDOMCharacterData *aTextNode, PRInt32 aOffset, const nsAString & aString); \
  NS_SCRIPTABLE NS_IMETHOD DidInsertText(nsIDOMCharacterData *aTextNode, PRInt32 aOffset, const nsAString & aString, nsresult aResult); \
  NS_SCRIPTABLE NS_IMETHOD WillDeleteText(nsIDOMCharacterData *aTextNode, PRInt32 aOffset, PRInt32 aLength); \
  NS_SCRIPTABLE NS_IMETHOD DidDeleteText(nsIDOMCharacterData *aTextNode, PRInt32 aOffset, PRInt32 aLength, nsresult aResult); \
  NS_SCRIPTABLE NS_IMETHOD WillDeleteSelection(nsISelection *aSelection); \
  NS_SCRIPTABLE NS_IMETHOD DidDeleteSelection(nsISelection *aSelection); 

/* Use this macro to declare functions that forward the behavior of this interface to another object. */
#define NS_FORWARD_NSIEDITACTIONLISTENER(_to) \
  NS_SCRIPTABLE NS_IMETHOD WillCreateNode(const nsAString & aTag, nsIDOMNode *aParent, PRInt32 aPosition) { return _to WillCreateNode(aTag, aParent, aPosition); } \
  NS_SCRIPTABLE NS_IMETHOD DidCreateNode(const nsAString & aTag, nsIDOMNode *aNode, nsIDOMNode *aParent, PRInt32 aPosition, nsresult aResult) { return _to DidCreateNode(aTag, aNode, aParent, aPosition, aResult); } \
  NS_SCRIPTABLE NS_IMETHOD WillInsertNode(nsIDOMNode *aNode, nsIDOMNode *aParent, PRInt32 aPosition) { return _to WillInsertNode(aNode, aParent, aPosition); } \
  NS_SCRIPTABLE NS_IMETHOD DidInsertNode(nsIDOMNode *aNode, nsIDOMNode *aParent, PRInt32 aPosition, nsresult aResult) { return _to DidInsertNode(aNode, aParent, aPosition, aResult); } \
  NS_SCRIPTABLE NS_IMETHOD WillDeleteNode(nsIDOMNode *aChild) { return _to WillDeleteNode(aChild); } \
  NS_SCRIPTABLE NS_IMETHOD DidDeleteNode(nsIDOMNode *aChild, nsresult aResult) { return _to DidDeleteNode(aChild, aResult); } \
  NS_SCRIPTABLE NS_IMETHOD WillSplitNode(nsIDOMNode *aExistingRightNode, PRInt32 aOffset) { return _to WillSplitNode(aExistingRightNode, aOffset); } \
  NS_SCRIPTABLE NS_IMETHOD DidSplitNode(nsIDOMNode *aExistingRightNode, PRInt32 aOffset, nsIDOMNode *aNewLeftNode, nsresult aResult) { return _to DidSplitNode(aExistingRightNode, aOffset, aNewLeftNode, aResult); } \
  NS_SCRIPTABLE NS_IMETHOD WillJoinNodes(nsIDOMNode *aLeftNode, nsIDOMNode *aRightNode, nsIDOMNode *aParent) { return _to WillJoinNodes(aLeftNode, aRightNode, aParent); } \
  NS_SCRIPTABLE NS_IMETHOD DidJoinNodes(nsIDOMNode *aLeftNode, nsIDOMNode *aRightNode, nsIDOMNode *aParent, nsresult aResult) { return _to DidJoinNodes(aLeftNode, aRightNode, aParent, aResult); } \
  NS_SCRIPTABLE NS_IMETHOD WillInsertText(nsIDOMCharacterData *aTextNode, PRInt32 aOffset, const nsAString & aString) { return _to WillInsertText(aTextNode, aOffset, aString); } \
  NS_SCRIPTABLE NS_IMETHOD DidInsertText(nsIDOMCharacterData *aTextNode, PRInt32 aOffset, const nsAString & aString, nsresult aResult) { return _to DidInsertText(aTextNode, aOffset, aString, aResult); } \
  NS_SCRIPTABLE NS_IMETHOD WillDeleteText(nsIDOMCharacterData *aTextNode, PRInt32 aOffset, PRInt32 aLength) { return _to WillDeleteText(aTextNode, aOffset, aLength); } \
  NS_SCRIPTABLE NS_IMETHOD DidDeleteText(nsIDOMCharacterData *aTextNode, PRInt32 aOffset, PRInt32 aLength, nsresult aResult) { return _to DidDeleteText(aTextNode, aOffset, aLength, aResult); } \
  NS_SCRIPTABLE NS_IMETHOD WillDeleteSelection(nsISelection *aSelection) { return _to WillDeleteSelection(aSelection); } \
  NS_SCRIPTABLE NS_IMETHOD DidDeleteSelection(nsISelection *aSelection) { return _to DidDeleteSelection(aSelection); } 

/* Use this macro to declare functions that forward the behavior of this interface to another object in a safe way. */
#define NS_FORWARD_SAFE_NSIEDITACTIONLISTENER(_to) \
  NS_SCRIPTABLE NS_IMETHOD WillCreateNode(const nsAString & aTag, nsIDOMNode *aParent, PRInt32 aPosition) { return !_to ? NS_ERROR_NULL_POINTER : _to->WillCreateNode(aTag, aParent, aPosition); } \
  NS_SCRIPTABLE NS_IMETHOD DidCreateNode(const nsAString & aTag, nsIDOMNode *aNode, nsIDOMNode *aParent, PRInt32 aPosition, nsresult aResult) { return !_to ? NS_ERROR_NULL_POINTER : _to->DidCreateNode(aTag, aNode, aParent, aPosition, aResult); } \
  NS_SCRIPTABLE NS_IMETHOD WillInsertNode(nsIDOMNode *aNode, nsIDOMNode *aParent, PRInt32 aPosition) { return !_to ? NS_ERROR_NULL_POINTER : _to->WillInsertNode(aNode, aParent, aPosition); } \
  NS_SCRIPTABLE NS_IMETHOD DidInsertNode(nsIDOMNode *aNode, nsIDOMNode *aParent, PRInt32 aPosition, nsresult aResult) { return !_to ? NS_ERROR_NULL_POINTER : _to->DidInsertNode(aNode, aParent, aPosition, aResult); } \
  NS_SCRIPTABLE NS_IMETHOD WillDeleteNode(nsIDOMNode *aChild) { return !_to ? NS_ERROR_NULL_POINTER : _to->WillDeleteNode(aChild); } \
  NS_SCRIPTABLE NS_IMETHOD DidDeleteNode(nsIDOMNode *aChild, nsresult aResult) { return !_to ? NS_ERROR_NULL_POINTER : _to->DidDeleteNode(aChild, aResult); } \
  NS_SCRIPTABLE NS_IMETHOD WillSplitNode(nsIDOMNode *aExistingRightNode, PRInt32 aOffset) { return !_to ? NS_ERROR_NULL_POINTER : _to->WillSplitNode(aExistingRightNode, aOffset); } \
  NS_SCRIPTABLE NS_IMETHOD DidSplitNode(nsIDOMNode *aExistingRightNode, PRInt32 aOffset, nsIDOMNode *aNewLeftNode, nsresult aResult) { return !_to ? NS_ERROR_NULL_POINTER : _to->DidSplitNode(aExistingRightNode, aOffset, aNewLeftNode, aResult); } \
  NS_SCRIPTABLE NS_IMETHOD WillJoinNodes(nsIDOMNode *aLeftNode, nsIDOMNode *aRightNode, nsIDOMNode *aParent) { return !_to ? NS_ERROR_NULL_POINTER : _to->WillJoinNodes(aLeftNode, aRightNode, aParent); } \
  NS_SCRIPTABLE NS_IMETHOD DidJoinNodes(nsIDOMNode *aLeftNode, nsIDOMNode *aRightNode, nsIDOMNode *aParent, nsresult aResult) { return !_to ? NS_ERROR_NULL_POINTER : _to->DidJoinNodes(aLeftNode, aRightNode, aParent, aResult); } \
  NS_SCRIPTABLE NS_IMETHOD WillInsertText(nsIDOMCharacterData *aTextNode, PRInt32 aOffset, const nsAString & aString) { return !_to ? NS_ERROR_NULL_POINTER : _to->WillInsertText(aTextNode, aOffset, aString); } \
  NS_SCRIPTABLE NS_IMETHOD DidInsertText(nsIDOMCharacterData *aTextNode, PRInt32 aOffset, const nsAString & aString, nsresult aResult) { return !_to ? NS_ERROR_NULL_POINTER : _to->DidInsertText(aTextNode, aOffset, aString, aResult); } \
  NS_SCRIPTABLE NS_IMETHOD WillDeleteText(nsIDOMCharacterData *aTextNode, PRInt32 aOffset, PRInt32 aLength) { return !_to ? NS_ERROR_NULL_POINTER : _to->WillDeleteText(aTextNode, aOffset, aLength); } \
  NS_SCRIPTABLE NS_IMETHOD DidDeleteText(nsIDOMCharacterData *aTextNode, PRInt32 aOffset, PRInt32 aLength, nsresult aResult) { return !_to ? NS_ERROR_NULL_POINTER : _to->DidDeleteText(aTextNode, aOffset, aLength, aResult); } \
  NS_SCRIPTABLE NS_IMETHOD WillDeleteSelection(nsISelection *aSelection) { return !_to ? NS_ERROR_NULL_POINTER : _to->WillDeleteSelection(aSelection); } \
  NS_SCRIPTABLE NS_IMETHOD DidDeleteSelection(nsISelection *aSelection) { return !_to ? NS_ERROR_NULL_POINTER : _to->DidDeleteSelection(aSelection); } 

#if 0
/* Use the code below as a template for the implementation class for this interface. */

/* Header file */
class nsEditActionListener : public nsIEditActionListener
{
public:
  NS_DECL_ISUPPORTS
  NS_DECL_NSIEDITACTIONLISTENER

  nsEditActionListener();

private:
  ~nsEditActionListener();

protected:
  /* additional members */
};

/* Implementation file */
NS_IMPL_ISUPPORTS1(nsEditActionListener, nsIEditActionListener)

nsEditActionListener::nsEditActionListener()
{
  /* member initializers and constructor code */
}

nsEditActionListener::~nsEditActionListener()
{
  /* destructor code */
}

/* void WillCreateNode (in DOMString aTag, in nsIDOMNode aParent, in long aPosition); */
NS_IMETHODIMP nsEditActionListener::WillCreateNode(const nsAString & aTag, nsIDOMNode *aParent, PRInt32 aPosition)
{
    return NS_ERROR_NOT_IMPLEMENTED;
}

/* void DidCreateNode (in DOMString aTag, in nsIDOMNode aNode, in nsIDOMNode aParent, in long aPosition, in nsresult aResult); */
NS_IMETHODIMP nsEditActionListener::DidCreateNode(const nsAString & aTag, nsIDOMNode *aNode, nsIDOMNode *aParent, PRInt32 aPosition, nsresult aResult)
{
    return NS_ERROR_NOT_IMPLEMENTED;
}

/* void WillInsertNode (in nsIDOMNode aNode, in nsIDOMNode aParent, in long aPosition); */
NS_IMETHODIMP nsEditActionListener::WillInsertNode(nsIDOMNode *aNode, nsIDOMNode *aParent, PRInt32 aPosition)
{
    return NS_ERROR_NOT_IMPLEMENTED;
}

/* void DidInsertNode (in nsIDOMNode aNode, in nsIDOMNode aParent, in long aPosition, in nsresult aResult); */
NS_IMETHODIMP nsEditActionListener::DidInsertNode(nsIDOMNode *aNode, nsIDOMNode *aParent, PRInt32 aPosition, nsresult aResult)
{
    return NS_ERROR_NOT_IMPLEMENTED;
}

/* void WillDeleteNode (in nsIDOMNode aChild); */
NS_IMETHODIMP nsEditActionListener::WillDeleteNode(nsIDOMNode *aChild)
{
    return NS_ERROR_NOT_IMPLEMENTED;
}

/* void DidDeleteNode (in nsIDOMNode aChild, in nsresult aResult); */
NS_IMETHODIMP nsEditActionListener::DidDeleteNode(nsIDOMNode *aChild, nsresult aResult)
{
    return NS_ERROR_NOT_IMPLEMENTED;
}

/* void WillSplitNode (in nsIDOMNode aExistingRightNode, in long aOffset); */
NS_IMETHODIMP nsEditActionListener::WillSplitNode(nsIDOMNode *aExistingRightNode, PRInt32 aOffset)
{
    return NS_ERROR_NOT_IMPLEMENTED;
}

/* void DidSplitNode (in nsIDOMNode aExistingRightNode, in long aOffset, in nsIDOMNode aNewLeftNode, in nsresult aResult); */
NS_IMETHODIMP nsEditActionListener::DidSplitNode(nsIDOMNode *aExistingRightNode, PRInt32 aOffset, nsIDOMNode *aNewLeftNode, nsresult aResult)
{
    return NS_ERROR_NOT_IMPLEMENTED;
}

/* void WillJoinNodes (in nsIDOMNode aLeftNode, in nsIDOMNode aRightNode, in nsIDOMNode aParent); */
NS_IMETHODIMP nsEditActionListener::WillJoinNodes(nsIDOMNode *aLeftNode, nsIDOMNode *aRightNode, nsIDOMNode *aParent)
{
    return NS_ERROR_NOT_IMPLEMENTED;
}

/* void DidJoinNodes (in nsIDOMNode aLeftNode, in nsIDOMNode aRightNode, in nsIDOMNode aParent, in nsresult aResult); */
NS_IMETHODIMP nsEditActionListener::DidJoinNodes(nsIDOMNode *aLeftNode, nsIDOMNode *aRightNode, nsIDOMNode *aParent, nsresult aResult)
{
    return NS_ERROR_NOT_IMPLEMENTED;
}

/* void WillInsertText (in nsIDOMCharacterData aTextNode, in long aOffset, in DOMString aString); */
NS_IMETHODIMP nsEditActionListener::WillInsertText(nsIDOMCharacterData *aTextNode, PRInt32 aOffset, const nsAString & aString)
{
    return NS_ERROR_NOT_IMPLEMENTED;
}

/* void DidInsertText (in nsIDOMCharacterData aTextNode, in long aOffset, in DOMString aString, in nsresult aResult); */
NS_IMETHODIMP nsEditActionListener::DidInsertText(nsIDOMCharacterData *aTextNode, PRInt32 aOffset, const nsAString & aString, nsresult aResult)
{
    return NS_ERROR_NOT_IMPLEMENTED;
}

/* void WillDeleteText (in nsIDOMCharacterData aTextNode, in long aOffset, in long aLength); */
NS_IMETHODIMP nsEditActionListener::WillDeleteText(nsIDOMCharacterData *aTextNode, PRInt32 aOffset, PRInt32 aLength)
{
    return NS_ERROR_NOT_IMPLEMENTED;
}

/* void DidDeleteText (in nsIDOMCharacterData aTextNode, in long aOffset, in long aLength, in nsresult aResult); */
NS_IMETHODIMP nsEditActionListener::DidDeleteText(nsIDOMCharacterData *aTextNode, PRInt32 aOffset, PRInt32 aLength, nsresult aResult)
{
    return NS_ERROR_NOT_IMPLEMENTED;
}

/* void WillDeleteSelection (in nsISelection aSelection); */
NS_IMETHODIMP nsEditActionListener::WillDeleteSelection(nsISelection *aSelection)
{
    return NS_ERROR_NOT_IMPLEMENTED;
}

/* void DidDeleteSelection (in nsISelection aSelection); */
NS_IMETHODIMP nsEditActionListener::DidDeleteSelection(nsISelection *aSelection)
{
    return NS_ERROR_NOT_IMPLEMENTED;
}

/* End of implementation class template. */
#endif


#endif /* __gen_nsIEditActionListener_h__ */
