/*
 * DO NOT EDIT.  THIS FILE IS GENERATED FROM e:/builds/moz2_slave/mozilla-1.9.1-win32-xulrunner/build/editor/idl/nsIEditor.idl
 */

#ifndef __gen_nsIEditor_h__
#define __gen_nsIEditor_h__


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
class nsIURI; /* forward declaration */

class nsIAtom; /* forward declaration */

class nsIContent; /* forward declaration */

class nsISelection; /* forward declaration */

class nsISelectionController; /* forward declaration */

class nsIDocumentStateListener; /* forward declaration */

class nsIOutputStream; /* forward declaration */

class nsITransactionManager; /* forward declaration */

class nsITransaction; /* forward declaration */

class nsIEditorObserver; /* forward declaration */

class nsIEditActionListener; /* forward declaration */

class nsIInlineSpellChecker; /* forward declaration */

class nsIPresShell;
typedef short EDirection;

/* starting interface:    nsIEditor */
#define NS_IEDITOR_IID_STR "96b60ba0-634a-41e4-928e-78ab0b3c4b46"

#define NS_IEDITOR_IID \
  {0x96b60ba0, 0x634a, 0x41e4, \
    { 0x92, 0x8e, 0x78, 0xab, 0x0b, 0x3c, 0x4b, 0x46 }}

class NS_SCRIPTABLE nsIEditor : public nsISupports {
 public: 

  NS_DECLARE_STATIC_IID_ACCESSOR(NS_IEDITOR_IID)

  typedef short EDirection;
  enum { eNone = 0 };

  enum { eNext = 1 };

  enum { ePrevious = 2 };

  enum { eNextWord = 3 };

  enum { ePreviousWord = 4 };

  enum { eToBeginningOfLine = 5 };

  enum { eToEndOfLine = 6 };

  /* readonly attribute nsISelection selection; */
  NS_SCRIPTABLE NS_IMETHOD GetSelection(nsISelection * *aSelection) = 0;

  /**
   * Init is to tell the implementation of nsIEditor to begin its services
   * @param aDoc          The dom document interface being observed
   * @param aPresShell    TEMP: The presentation shell displaying the document.
   *                      Once events can tell us from what pres shell
   *                      they originated, this will no longer be
   *                      necessary, and the editor will no longer be
   *                      linked to a single pres shell.
   * @param aRoot         This is the root of the editable section of this
   *                      document. If it is null then we get root
   *                      from document body.
   * @param aSelCon       this should be used to get the selection location
   * @param aFlags        A bitmask of flags for specifying the behavior
   *                      of the editor.
   */
  /* [noscript] void init (in nsIDOMDocument doc, in nsIPresShellPtr shell, in nsIContent aRoot, in nsISelectionController aSelCon, in unsigned long aFlags); */
  NS_IMETHOD Init(nsIDOMDocument *doc, nsIPresShell * shell, nsIContent *aRoot, nsISelectionController *aSelCon, PRUint32 aFlags) = 0;

  /* void setAttributeOrEquivalent (in nsIDOMElement element, in AString sourceAttrName, in AString sourceAttrValue, in boolean aSuppressTransaction); */
  NS_SCRIPTABLE NS_IMETHOD SetAttributeOrEquivalent(nsIDOMElement *element, const nsAString & sourceAttrName, const nsAString & sourceAttrValue, PRBool aSuppressTransaction) = 0;

  /* void removeAttributeOrEquivalent (in nsIDOMElement element, in DOMString sourceAttrName, in boolean aSuppressTransaction); */
  NS_SCRIPTABLE NS_IMETHOD RemoveAttributeOrEquivalent(nsIDOMElement *element, const nsAString & sourceAttrName, PRBool aSuppressTransaction) = 0;

  /**
   * postCreate should be called after Init, and is the time that the editor
   * tells its documentStateObservers that the document has been created.
   */
  /* void postCreate (); */
  NS_SCRIPTABLE NS_IMETHOD PostCreate(void) = 0;

  /**
   * preDestroy is called before the editor goes away, and gives the editor a
   * chance to tell its documentStateObservers that the document is going away.
   * @param aDestroyingFrames set to true when the frames being edited
   * are being destroyed (so there is no need to modify any nsISelections,
   * nor is it safe to do so)
   */
  /* void preDestroy (in boolean aDestroyingFrames); */
  NS_SCRIPTABLE NS_IMETHOD PreDestroy(PRBool aDestroyingFrames) = 0;

  /** edit flags for this editor.  May be set at any time. */
  /* attribute unsigned long flags; */
  NS_SCRIPTABLE NS_IMETHOD GetFlags(PRUint32 *aFlags) = 0;
  NS_SCRIPTABLE NS_IMETHOD SetFlags(PRUint32 aFlags) = 0;

  /**
   * the MimeType of the document
   */
  /* attribute string contentsMIMEType; */
  NS_SCRIPTABLE NS_IMETHOD GetContentsMIMEType(char * *aContentsMIMEType) = 0;
  NS_SCRIPTABLE NS_IMETHOD SetContentsMIMEType(const char * aContentsMIMEType) = 0;

  /** Returns true if we have a document that is not marked read-only */
  /* readonly attribute boolean isDocumentEditable; */
  NS_SCRIPTABLE NS_IMETHOD GetIsDocumentEditable(PRBool *aIsDocumentEditable) = 0;

  /**
   * the DOM Document this editor is associated with, refcounted.
   */
  /* readonly attribute nsIDOMDocument document; */
  NS_SCRIPTABLE NS_IMETHOD GetDocument(nsIDOMDocument * *aDocument) = 0;

  /** the body element, i.e. the root of the editable document.
   */
  /* readonly attribute nsIDOMElement rootElement; */
  NS_SCRIPTABLE NS_IMETHOD GetRootElement(nsIDOMElement * *aRootElement) = 0;

  /**
   * the selection controller for the current presentation, refcounted.
   */
  /* readonly attribute nsISelectionController selectionController; */
  NS_SCRIPTABLE NS_IMETHOD GetSelectionController(nsISelectionController * *aSelectionController) = 0;

  /** 
   * DeleteSelection removes all nodes in the current selection.
   * @param aDir  if eNext, delete to the right (for example, the DEL key)
   *              if ePrevious, delete to the left (for example, the BACKSPACE key)
   */
  /* void deleteSelection (in short action); */
  NS_SCRIPTABLE NS_IMETHOD DeleteSelection(PRInt16 action) = 0;

  /** Returns true if the document has no *meaningful* content */
  /* readonly attribute boolean documentIsEmpty; */
  NS_SCRIPTABLE NS_IMETHOD GetDocumentIsEmpty(PRBool *aDocumentIsEmpty) = 0;

  /** Returns true if the document is modifed and needs saving */
  /* readonly attribute boolean documentModified; */
  NS_SCRIPTABLE NS_IMETHOD GetDocumentModified(PRBool *aDocumentModified) = 0;

  /** Sets the current 'Save' document character set */
  /* attribute ACString documentCharacterSet; */
  NS_SCRIPTABLE NS_IMETHOD GetDocumentCharacterSet(nsACString & aDocumentCharacterSet) = 0;
  NS_SCRIPTABLE NS_IMETHOD SetDocumentCharacterSet(const nsACString & aDocumentCharacterSet) = 0;

  /** to be used ONLY when we need to override the doc's modification
    * state (such as when it's saved).
    */
  /* void resetModificationCount (); */
  NS_SCRIPTABLE NS_IMETHOD ResetModificationCount(void) = 0;

  /** Gets the modification count of the document we are editing.
    * @return the modification count of the document being edited.
    *         Zero means unchanged.
    */
  /* long getModificationCount (); */
  NS_SCRIPTABLE NS_IMETHOD GetModificationCount(PRInt32 *_retval NS_OUTPARAM) = 0;

  /** called each time we modify the document.
    * Increments the modification count of the document.
    * @param  aModCount  the number of modifications by which
    *                    to increase or decrease the count
    */
  /* void incrementModificationCount (in long aModCount); */
  NS_SCRIPTABLE NS_IMETHOD IncrementModificationCount(PRInt32 aModCount) = 0;

  /** transactionManager Get the transaction manager the editor is using.
    */
  /* attribute nsITransactionManager transactionManager; */
  NS_SCRIPTABLE NS_IMETHOD GetTransactionManager(nsITransactionManager * *aTransactionManager) = 0;
  NS_SCRIPTABLE NS_IMETHOD SetTransactionManager(nsITransactionManager * aTransactionManager) = 0;

  /** doTransaction() fires a transaction.
    * It is provided here so clients can create their own transactions.
    * If a transaction manager is present, it is used.  
    * Otherwise, the transaction is just executed directly.
    *
    * @param aTxn the transaction to execute
    */
  /* void doTransaction (in nsITransaction txn); */
  NS_SCRIPTABLE NS_IMETHOD DoTransaction(nsITransaction *txn) = 0;

  /** turn the undo system on or off
    * @param aEnable  if PR_TRUE, the undo system is turned on if available
    *                 if PR_FALSE the undo system is turned off if it
    *                 was previously on
    * @return         if aEnable is PR_TRUE, returns NS_OK if
    *                 the undo system could be initialized properly
    *                 if aEnable is PR_FALSE, returns NS_OK.
    */
  /* void enableUndo (in boolean enable); */
  NS_SCRIPTABLE NS_IMETHOD EnableUndo(PRBool enable) = 0;

  /** undo reverses the effects of the last Do operation,
    * if Undo is enabled in the editor.
    * It is provided here so clients need no knowledge of whether
    * the editor has a transaction manager or not.
    * If a transaction manager is present, it is told to undo,
    * and the result of that undo is returned.  
    * Otherwise, the Undo request is ignored and an
    * error NS_ERROR_NOT_AVAILABLE is returned.
    *
    */
  /* void undo (in unsigned long count); */
  NS_SCRIPTABLE NS_IMETHOD Undo(PRUint32 count) = 0;

  /** returns state information about the undo system.
    * @param aIsEnabled [OUT] PR_TRUE if undo is enabled
    * @param aCanUndo   [OUT] PR_TRUE if at least one transaction is
    *                         currently ready to be undone.
    */
  /* void canUndo (out boolean isEnabled, out boolean canUndo); */
  NS_SCRIPTABLE NS_IMETHOD CanUndo(PRBool *isEnabled NS_OUTPARAM, PRBool *canUndo NS_OUTPARAM) = 0;

  /** redo reverses the effects of the last Undo operation
    * It is provided here so clients need no knowledge of whether
    * the editor has a transaction manager or not.
    * If a transaction manager is present, it is told to redo and the
    * result of the previously undone transaction is reapplied to the document.
    * If no transaction is available for Redo, or if the document
    * has no transaction manager, the Redo request is ignored and an
    * error NS_ERROR_NOT_AVAILABLE is returned.
    *
    */
  /* void redo (in unsigned long count); */
  NS_SCRIPTABLE NS_IMETHOD Redo(PRUint32 count) = 0;

  /** returns state information about the redo system.
    * @param aIsEnabled [OUT] PR_TRUE if redo is enabled
    * @param aCanRedo   [OUT] PR_TRUE if at least one transaction is
                              currently ready to be redone.
    */
  /* void canRedo (out boolean isEnabled, out boolean canRedo); */
  NS_SCRIPTABLE NS_IMETHOD CanRedo(PRBool *isEnabled NS_OUTPARAM, PRBool *canRedo NS_OUTPARAM) = 0;

  /** beginTransaction is a signal from the caller to the editor that
    * the caller will execute multiple updates to the content tree
    * that should be treated as a single logical operation,
    * in the most efficient way possible.<br>
    * All transactions executed between a call to beginTransaction and
    * endTransaction will be undoable as an atomic action.<br>
    * endTransaction must be called after beginTransaction.<br>
    * Calls to beginTransaction can be nested, as long as endTransaction
    * is called once per beginUpdate.
    */
  /* void beginTransaction (); */
  NS_SCRIPTABLE NS_IMETHOD BeginTransaction(void) = 0;

  /** endTransaction is a signal to the editor that the caller is
    * finished updating the content model.<br>
    * beginUpdate must be called before endTransaction is called.<br>
    * Calls to beginTransaction can be nested, as long as endTransaction
    * is called once per beginTransaction.
    */
  /* void endTransaction (); */
  NS_SCRIPTABLE NS_IMETHOD EndTransaction(void) = 0;

  /* void beginPlaceHolderTransaction (in nsIAtom name); */
  NS_SCRIPTABLE NS_IMETHOD BeginPlaceHolderTransaction(nsIAtom *name) = 0;

  /* void endPlaceHolderTransaction (); */
  NS_SCRIPTABLE NS_IMETHOD EndPlaceHolderTransaction(void) = 0;

  /* boolean shouldTxnSetSelection (); */
  NS_SCRIPTABLE NS_IMETHOD ShouldTxnSetSelection(PRBool *_retval NS_OUTPARAM) = 0;

  /** Set the flag that prevents insertElementTxn from changing the selection
    * @param   should  Set false to suppress changing the selection;
    *                  i.e., before using InsertElement() to insert
    *                  under <head> element
    * WARNING: You must be very careful to reset back to PR_TRUE after
    *          setting PR_FALSE, else selection/caret is trashed
    *          for further editing.
    */
  /* void setShouldTxnSetSelection (in boolean should); */
  NS_SCRIPTABLE NS_IMETHOD SetShouldTxnSetSelection(PRBool should) = 0;

  /** Returns the inline spell checker associated with this object. The spell
    * checker is lazily created, so this function may create the object for
    * you during this call.
    * @param  autoCreate  If true, this will create a spell checker object
    *                     if one does not exist yet for this editor. If false
    *                     and the object has not been created, this function
    *                     WILL RETURN NULL.
    */
  /* nsIInlineSpellChecker getInlineSpellChecker (in boolean autoCreate); */
  NS_SCRIPTABLE NS_IMETHOD GetInlineSpellChecker(PRBool autoCreate, nsIInlineSpellChecker **_retval NS_OUTPARAM) = 0;

  /** Resyncs spellchecking state (enabled/disabled).  This should be called
    * when anything that affects spellchecking state changes, such as the
    * spellcheck attribute value.
    */
  /* void syncRealTimeSpell (); */
  NS_SCRIPTABLE NS_IMETHOD SyncRealTimeSpell(void) = 0;

  /** Called when the user manually overrides the spellchecking state for this
    * editor.
    * @param  enable  The new state of spellchecking in this editor, as
    *                 requested by the user.
    */
  /* void setSpellcheckUserOverride (in boolean enable); */
  NS_SCRIPTABLE NS_IMETHOD SetSpellcheckUserOverride(PRBool enable) = 0;

  /** cut the currently selected text, putting it into the OS clipboard
    * What if no text is selected?
    * What about mixed selections?
    * What are the clipboard formats?
    */
  /* void cut (); */
  NS_SCRIPTABLE NS_IMETHOD Cut(void) = 0;

  /** Can we cut? True if the doc is modifiable, and we have a non-
    * collapsed selection.
    */
  /* boolean canCut (); */
  NS_SCRIPTABLE NS_IMETHOD CanCut(PRBool *_retval NS_OUTPARAM) = 0;

  /** copy the currently selected text, putting it into the OS clipboard
    * What if no text is selected?
    * What about mixed selections?
    * What are the clipboard formats?
    */
  /* void copy (); */
  NS_SCRIPTABLE NS_IMETHOD Copy(void) = 0;

  /** Can we copy? True if we have a non-collapsed selection.
    */
  /* boolean canCopy (); */
  NS_SCRIPTABLE NS_IMETHOD CanCopy(PRBool *_retval NS_OUTPARAM) = 0;

  /** paste the text in the OS clipboard at the cursor position, replacing
    * the selected text (if any)
    */
  /* void paste (in long aSelectionType); */
  NS_SCRIPTABLE NS_IMETHOD Paste(PRInt32 aSelectionType) = 0;

  /** Can we paste? True if the doc is modifiable, and we have
    * pasteable data in the clipboard.
    */
  /* boolean canPaste (in long aSelectionType); */
  NS_SCRIPTABLE NS_IMETHOD CanPaste(PRInt32 aSelectionType, PRBool *_retval NS_OUTPARAM) = 0;

  /** sets the document selection to the entire contents of the document */
  /* void selectAll (); */
  NS_SCRIPTABLE NS_IMETHOD SelectAll(void) = 0;

  /** sets the document selection to the beginning of the document */
  /* void beginningOfDocument (); */
  NS_SCRIPTABLE NS_IMETHOD BeginningOfDocument(void) = 0;

  /** sets the document selection to the end of the document */
  /* void endOfDocument (); */
  NS_SCRIPTABLE NS_IMETHOD EndOfDocument(void) = 0;

  /** 
    * canDrag decides if a drag should be started
    * (for example, based on the current selection and mousepoint).
    */
  /* boolean canDrag (in nsIDOMEvent aEvent); */
  NS_SCRIPTABLE NS_IMETHOD CanDrag(nsIDOMEvent *aEvent, PRBool *_retval NS_OUTPARAM) = 0;

  /** 
    * doDrag transfers the relevant data (as appropriate)
    * to a transferable so it can later be dropped.
    */
  /* void doDrag (in nsIDOMEvent aEvent); */
  NS_SCRIPTABLE NS_IMETHOD DoDrag(nsIDOMEvent *aEvent) = 0;

  /** 
    * insertFromDrop looks for a dragsession and inserts the
    * relevant data in response to a drop.
    */
  /* void insertFromDrop (in nsIDOMEvent aEvent); */
  NS_SCRIPTABLE NS_IMETHOD InsertFromDrop(nsIDOMEvent *aEvent) = 0;

  /**
   * setAttribute() sets the attribute of aElement.
   * No checking is done to see if aAttribute is a legal attribute of the node,
   * or if aValue is a legal value of aAttribute.
   *
   * @param aElement    the content element to operate on
   * @param aAttribute  the string representation of the attribute to set
   * @param aValue      the value to set aAttribute to
   */
  /* void setAttribute (in nsIDOMElement aElement, in AString attributestr, in AString attvalue); */
  NS_SCRIPTABLE NS_IMETHOD SetAttribute(nsIDOMElement *aElement, const nsAString & attributestr, const nsAString & attvalue) = 0;

  /**
   * getAttributeValue() retrieves the attribute's value for aElement.
   *
   * @param aElement      the content element to operate on
   * @param aAttribute    the string representation of the attribute to get
   * @param aResultValue  [OUT] the value of aAttribute.
   *                      Only valid if aResultIsSet is PR_TRUE
   * @return              PR_TRUE if aAttribute is set on the current node,
   *                      PR_FALSE if it is not.
   */
  /* boolean getAttributeValue (in nsIDOMElement aElement, in AString attributestr, out AString resultValue); */
  NS_SCRIPTABLE NS_IMETHOD GetAttributeValue(nsIDOMElement *aElement, const nsAString & attributestr, nsAString & resultValue NS_OUTPARAM, PRBool *_retval NS_OUTPARAM) = 0;

  /**
   * removeAttribute() deletes aAttribute from the attribute list of aElement.
   * If aAttribute is not an attribute of aElement, nothing is done.
   *
   * @param aElement      the content element to operate on
   * @param aAttribute    the string representation of the attribute to get
   */
  /* void removeAttribute (in nsIDOMElement aElement, in AString aAttribute); */
  NS_SCRIPTABLE NS_IMETHOD RemoveAttribute(nsIDOMElement *aElement, const nsAString & aAttribute) = 0;

  /**
   * cloneAttribute() copies the attribute from the source node to
   * the destination node and delete those not in the source.
   *
   * The supplied nodes MUST BE ELEMENTS (most callers are working with nodes)
   * @param aAttribute    the name of the attribute to copy
   * @param aDestNode     the destination element to operate on
   * @param aSourceNode   the source element to copy attributes from
   * @exception NS_ERROR_NULL_POINTER at least one of the nodes is null
   * @exception NS_ERROR_NO_INTERFACE at least one of the nodes is not an
   *                                  element
   */
  /* void cloneAttribute (in AString aAttribute, in nsIDOMNode aDestNode, in nsIDOMNode aSourceNode); */
  NS_SCRIPTABLE NS_IMETHOD CloneAttribute(const nsAString & aAttribute, nsIDOMNode *aDestNode, nsIDOMNode *aSourceNode) = 0;

  /**
   * cloneAttributes() is similar to nsIDOMNode::cloneNode(),
   *   it assures the attribute nodes of the destination are identical
   *   with the source node by copying all existing attributes from the
   *   source and deleting those not in the source.
   *   This is used when the destination node (element) already exists
   *
   * The supplied nodes MUST BE ELEMENTS (most callers are working with nodes)
   * @param aDestNode     the destination element to operate on
   * @param aSourceNode   the source element to copy attributes from
   */
  /* void cloneAttributes (in nsIDOMNode destNode, in nsIDOMNode sourceNode); */
  NS_SCRIPTABLE NS_IMETHOD CloneAttributes(nsIDOMNode *destNode, nsIDOMNode *sourceNode) = 0;

  /** 
   * createNode instantiates a new element of type aTag and inserts it
   * into aParent at aPosition.
   * @param aTag      The type of object to create
   * @param aParent   The node to insert the new object into
   * @param aPosition The place in aParent to insert the new node
   * @return          The node created.  Caller must release aNewNode.
   */
  /* nsIDOMNode createNode (in AString tag, in nsIDOMNode parent, in long position); */
  NS_SCRIPTABLE NS_IMETHOD CreateNode(const nsAString & tag, nsIDOMNode *parent, PRInt32 position, nsIDOMNode **_retval NS_OUTPARAM) = 0;

  /** 
   * insertNode inserts aNode into aParent at aPosition.
   * No checking is done to verify the legality of the insertion.
   * That is the responsibility of the caller.
   * @param aNode     The DOM Node to insert.
   * @param aParent   The node to insert the new object into
   * @param aPosition The place in aParent to insert the new node
   *                  0=first child, 1=second child, etc.
   *                  any number > number of current children = last child
   */
  /* void insertNode (in nsIDOMNode node, in nsIDOMNode parent, in long aPosition); */
  NS_SCRIPTABLE NS_IMETHOD InsertNode(nsIDOMNode *node, nsIDOMNode *parent, PRInt32 aPosition) = 0;

  /** 
   * splitNode() creates a new node identical to an existing node,
   * and split the contents between the two nodes
   * @param aExistingRightNode   the node to split.
   *                             It will become the new node's next sibling.
   * @param aOffset              the offset of aExistingRightNode's
   *                             content|children to do the split at
   * @param aNewLeftNode         [OUT] the new node resulting from the split,
   *                             becomes aExistingRightNode's previous sibling.
   */
  /* void splitNode (in nsIDOMNode existingRightNode, in long offset, out nsIDOMNode newLeftNode); */
  NS_SCRIPTABLE NS_IMETHOD SplitNode(nsIDOMNode *existingRightNode, PRInt32 offset, nsIDOMNode **newLeftNode NS_OUTPARAM) = 0;

  /** 
   * joinNodes() takes 2 nodes and merge their content|children.
   * @param aLeftNode     The left node.  It will be deleted.
   * @param aRightNode    The right node. It will remain after the join.
   * @param aParent       The parent of aExistingRightNode
   *
   *                      There is no requirement that the two nodes be
   *                      of the same type.  However, a text node can be
   *                      merged only with another text node.
   */
  /* void joinNodes (in nsIDOMNode leftNode, in nsIDOMNode rightNode, in nsIDOMNode parent); */
  NS_SCRIPTABLE NS_IMETHOD JoinNodes(nsIDOMNode *leftNode, nsIDOMNode *rightNode, nsIDOMNode *parent) = 0;

  /** 
   * deleteNode removes aChild from aParent.
   * @param aChild    The node to delete
   */
  /* void deleteNode (in nsIDOMNode child); */
  NS_SCRIPTABLE NS_IMETHOD DeleteNode(nsIDOMNode *child) = 0;

  /** 
   * markNodeDirty() sets a special dirty attribute on the node.
   * Usually this will be called immediately after creating a new node.
   * @param aNode      The node for which to insert formatting.
   */
  /* void markNodeDirty (in nsIDOMNode node); */
  NS_SCRIPTABLE NS_IMETHOD MarkNodeDirty(nsIDOMNode *node) = 0;

  /** 
   * Switches the editor element direction; from "Left-to-Right" to
   * "Right-to-Left", and vice versa.
   */
  /* void switchTextDirection (); */
  NS_SCRIPTABLE NS_IMETHOD SwitchTextDirection(void) = 0;

  /**
   * Output methods:
   * aFormatType is a mime type, like text/plain.
   */
  /* AString outputToString (in AString formatType, in unsigned long flags); */
  NS_SCRIPTABLE NS_IMETHOD OutputToString(const nsAString & formatType, PRUint32 flags, nsAString & _retval NS_OUTPARAM) = 0;

  /* void outputToStream (in nsIOutputStream aStream, in AString formatType, in ACString charsetOverride, in unsigned long flags); */
  NS_SCRIPTABLE NS_IMETHOD OutputToStream(nsIOutputStream *aStream, const nsAString & formatType, const nsACString & charsetOverride, PRUint32 flags) = 0;

  /** add an EditorObserver to the editors list of observers. */
  /* void addEditorObserver (in nsIEditorObserver observer); */
  NS_SCRIPTABLE NS_IMETHOD AddEditorObserver(nsIEditorObserver *observer) = 0;

  /** Remove an EditorObserver from the editor's list of observers. */
  /* void removeEditorObserver (in nsIEditorObserver observer); */
  NS_SCRIPTABLE NS_IMETHOD RemoveEditorObserver(nsIEditorObserver *observer) = 0;

  /** add an EditActionListener to the editors list of listeners. */
  /* void addEditActionListener (in nsIEditActionListener listener); */
  NS_SCRIPTABLE NS_IMETHOD AddEditActionListener(nsIEditActionListener *listener) = 0;

  /** Remove an EditActionListener from the editor's list of listeners. */
  /* void removeEditActionListener (in nsIEditActionListener listener); */
  NS_SCRIPTABLE NS_IMETHOD RemoveEditActionListener(nsIEditActionListener *listener) = 0;

  /** Add a DocumentStateListener to the editors list of doc state listeners. */
  /* void addDocumentStateListener (in nsIDocumentStateListener listener); */
  NS_SCRIPTABLE NS_IMETHOD AddDocumentStateListener(nsIDocumentStateListener *listener) = 0;

  /** Remove a DocumentStateListener to the editors list of doc state listeners. */
  /* void removeDocumentStateListener (in nsIDocumentStateListener listener); */
  NS_SCRIPTABLE NS_IMETHOD RemoveDocumentStateListener(nsIDocumentStateListener *listener) = 0;

  /**
   * And a debug method -- show us what the tree looks like right now
   */
  /* void dumpContentTree (); */
  NS_SCRIPTABLE NS_IMETHOD DumpContentTree(void) = 0;

  /** Dumps a text representation of the content tree to standard out */
  /* void debugDumpContent (); */
  NS_SCRIPTABLE NS_IMETHOD DebugDumpContent(void) = 0;

  /* void debugUnitTests (out long outNumTests, out long outNumTestsFailed); */
  NS_SCRIPTABLE NS_IMETHOD DebugUnitTests(PRInt32 *outNumTests NS_OUTPARAM, PRInt32 *outNumTestsFailed NS_OUTPARAM) = 0;

  /* [notxpcom] boolean isModifiableNode (in nsIDOMNode aNode); */
  NS_IMETHOD_(PRBool) IsModifiableNode(nsIDOMNode *aNode) = 0;

};

  NS_DEFINE_STATIC_IID_ACCESSOR(nsIEditor, NS_IEDITOR_IID)

/* Use this macro when declaring classes that implement this interface. */
#define NS_DECL_NSIEDITOR \
  NS_SCRIPTABLE NS_IMETHOD GetSelection(nsISelection * *aSelection); \
  NS_IMETHOD Init(nsIDOMDocument *doc, nsIPresShell * shell, nsIContent *aRoot, nsISelectionController *aSelCon, PRUint32 aFlags); \
  NS_SCRIPTABLE NS_IMETHOD SetAttributeOrEquivalent(nsIDOMElement *element, const nsAString & sourceAttrName, const nsAString & sourceAttrValue, PRBool aSuppressTransaction); \
  NS_SCRIPTABLE NS_IMETHOD RemoveAttributeOrEquivalent(nsIDOMElement *element, const nsAString & sourceAttrName, PRBool aSuppressTransaction); \
  NS_SCRIPTABLE NS_IMETHOD PostCreate(void); \
  NS_SCRIPTABLE NS_IMETHOD PreDestroy(PRBool aDestroyingFrames); \
  NS_SCRIPTABLE NS_IMETHOD GetFlags(PRUint32 *aFlags); \
  NS_SCRIPTABLE NS_IMETHOD SetFlags(PRUint32 aFlags); \
  NS_SCRIPTABLE NS_IMETHOD GetContentsMIMEType(char * *aContentsMIMEType); \
  NS_SCRIPTABLE NS_IMETHOD SetContentsMIMEType(const char * aContentsMIMEType); \
  NS_SCRIPTABLE NS_IMETHOD GetIsDocumentEditable(PRBool *aIsDocumentEditable); \
  NS_SCRIPTABLE NS_IMETHOD GetDocument(nsIDOMDocument * *aDocument); \
  NS_SCRIPTABLE NS_IMETHOD GetRootElement(nsIDOMElement * *aRootElement); \
  NS_SCRIPTABLE NS_IMETHOD GetSelectionController(nsISelectionController * *aSelectionController); \
  NS_SCRIPTABLE NS_IMETHOD DeleteSelection(PRInt16 action); \
  NS_SCRIPTABLE NS_IMETHOD GetDocumentIsEmpty(PRBool *aDocumentIsEmpty); \
  NS_SCRIPTABLE NS_IMETHOD GetDocumentModified(PRBool *aDocumentModified); \
  NS_SCRIPTABLE NS_IMETHOD GetDocumentCharacterSet(nsACString & aDocumentCharacterSet); \
  NS_SCRIPTABLE NS_IMETHOD SetDocumentCharacterSet(const nsACString & aDocumentCharacterSet); \
  NS_SCRIPTABLE NS_IMETHOD ResetModificationCount(void); \
  NS_SCRIPTABLE NS_IMETHOD GetModificationCount(PRInt32 *_retval NS_OUTPARAM); \
  NS_SCRIPTABLE NS_IMETHOD IncrementModificationCount(PRInt32 aModCount); \
  NS_SCRIPTABLE NS_IMETHOD GetTransactionManager(nsITransactionManager * *aTransactionManager); \
  NS_SCRIPTABLE NS_IMETHOD SetTransactionManager(nsITransactionManager * aTransactionManager); \
  NS_SCRIPTABLE NS_IMETHOD DoTransaction(nsITransaction *txn); \
  NS_SCRIPTABLE NS_IMETHOD EnableUndo(PRBool enable); \
  NS_SCRIPTABLE NS_IMETHOD Undo(PRUint32 count); \
  NS_SCRIPTABLE NS_IMETHOD CanUndo(PRBool *isEnabled NS_OUTPARAM, PRBool *canUndo NS_OUTPARAM); \
  NS_SCRIPTABLE NS_IMETHOD Redo(PRUint32 count); \
  NS_SCRIPTABLE NS_IMETHOD CanRedo(PRBool *isEnabled NS_OUTPARAM, PRBool *canRedo NS_OUTPARAM); \
  NS_SCRIPTABLE NS_IMETHOD BeginTransaction(void); \
  NS_SCRIPTABLE NS_IMETHOD EndTransaction(void); \
  NS_SCRIPTABLE NS_IMETHOD BeginPlaceHolderTransaction(nsIAtom *name); \
  NS_SCRIPTABLE NS_IMETHOD EndPlaceHolderTransaction(void); \
  NS_SCRIPTABLE NS_IMETHOD ShouldTxnSetSelection(PRBool *_retval NS_OUTPARAM); \
  NS_SCRIPTABLE NS_IMETHOD SetShouldTxnSetSelection(PRBool should); \
  NS_SCRIPTABLE NS_IMETHOD GetInlineSpellChecker(PRBool autoCreate, nsIInlineSpellChecker **_retval NS_OUTPARAM); \
  NS_SCRIPTABLE NS_IMETHOD SyncRealTimeSpell(void); \
  NS_SCRIPTABLE NS_IMETHOD SetSpellcheckUserOverride(PRBool enable); \
  NS_SCRIPTABLE NS_IMETHOD Cut(void); \
  NS_SCRIPTABLE NS_IMETHOD CanCut(PRBool *_retval NS_OUTPARAM); \
  NS_SCRIPTABLE NS_IMETHOD Copy(void); \
  NS_SCRIPTABLE NS_IMETHOD CanCopy(PRBool *_retval NS_OUTPARAM); \
  NS_SCRIPTABLE NS_IMETHOD Paste(PRInt32 aSelectionType); \
  NS_SCRIPTABLE NS_IMETHOD CanPaste(PRInt32 aSelectionType, PRBool *_retval NS_OUTPARAM); \
  NS_SCRIPTABLE NS_IMETHOD SelectAll(void); \
  NS_SCRIPTABLE NS_IMETHOD BeginningOfDocument(void); \
  NS_SCRIPTABLE NS_IMETHOD EndOfDocument(void); \
  NS_SCRIPTABLE NS_IMETHOD CanDrag(nsIDOMEvent *aEvent, PRBool *_retval NS_OUTPARAM); \
  NS_SCRIPTABLE NS_IMETHOD DoDrag(nsIDOMEvent *aEvent); \
  NS_SCRIPTABLE NS_IMETHOD InsertFromDrop(nsIDOMEvent *aEvent); \
  NS_SCRIPTABLE NS_IMETHOD SetAttribute(nsIDOMElement *aElement, const nsAString & attributestr, const nsAString & attvalue); \
  NS_SCRIPTABLE NS_IMETHOD GetAttributeValue(nsIDOMElement *aElement, const nsAString & attributestr, nsAString & resultValue NS_OUTPARAM, PRBool *_retval NS_OUTPARAM); \
  NS_SCRIPTABLE NS_IMETHOD RemoveAttribute(nsIDOMElement *aElement, const nsAString & aAttribute); \
  NS_SCRIPTABLE NS_IMETHOD CloneAttribute(const nsAString & aAttribute, nsIDOMNode *aDestNode, nsIDOMNode *aSourceNode); \
  NS_SCRIPTABLE NS_IMETHOD CloneAttributes(nsIDOMNode *destNode, nsIDOMNode *sourceNode); \
  NS_SCRIPTABLE NS_IMETHOD CreateNode(const nsAString & tag, nsIDOMNode *parent, PRInt32 position, nsIDOMNode **_retval NS_OUTPARAM); \
  NS_SCRIPTABLE NS_IMETHOD InsertNode(nsIDOMNode *node, nsIDOMNode *parent, PRInt32 aPosition); \
  NS_SCRIPTABLE NS_IMETHOD SplitNode(nsIDOMNode *existingRightNode, PRInt32 offset, nsIDOMNode **newLeftNode NS_OUTPARAM); \
  NS_SCRIPTABLE NS_IMETHOD JoinNodes(nsIDOMNode *leftNode, nsIDOMNode *rightNode, nsIDOMNode *parent); \
  NS_SCRIPTABLE NS_IMETHOD DeleteNode(nsIDOMNode *child); \
  NS_SCRIPTABLE NS_IMETHOD MarkNodeDirty(nsIDOMNode *node); \
  NS_SCRIPTABLE NS_IMETHOD SwitchTextDirection(void); \
  NS_SCRIPTABLE NS_IMETHOD OutputToString(const nsAString & formatType, PRUint32 flags, nsAString & _retval NS_OUTPARAM); \
  NS_SCRIPTABLE NS_IMETHOD OutputToStream(nsIOutputStream *aStream, const nsAString & formatType, const nsACString & charsetOverride, PRUint32 flags); \
  NS_SCRIPTABLE NS_IMETHOD AddEditorObserver(nsIEditorObserver *observer); \
  NS_SCRIPTABLE NS_IMETHOD RemoveEditorObserver(nsIEditorObserver *observer); \
  NS_SCRIPTABLE NS_IMETHOD AddEditActionListener(nsIEditActionListener *listener); \
  NS_SCRIPTABLE NS_IMETHOD RemoveEditActionListener(nsIEditActionListener *listener); \
  NS_SCRIPTABLE NS_IMETHOD AddDocumentStateListener(nsIDocumentStateListener *listener); \
  NS_SCRIPTABLE NS_IMETHOD RemoveDocumentStateListener(nsIDocumentStateListener *listener); \
  NS_SCRIPTABLE NS_IMETHOD DumpContentTree(void); \
  NS_SCRIPTABLE NS_IMETHOD DebugDumpContent(void); \
  NS_SCRIPTABLE NS_IMETHOD DebugUnitTests(PRInt32 *outNumTests NS_OUTPARAM, PRInt32 *outNumTestsFailed NS_OUTPARAM); \
  NS_IMETHOD_(PRBool) IsModifiableNode(nsIDOMNode *aNode); 

/* Use this macro to declare functions that forward the behavior of this interface to another object. */
#define NS_FORWARD_NSIEDITOR(_to) \
  NS_SCRIPTABLE NS_IMETHOD GetSelection(nsISelection * *aSelection) { return _to GetSelection(aSelection); } \
  NS_IMETHOD Init(nsIDOMDocument *doc, nsIPresShell * shell, nsIContent *aRoot, nsISelectionController *aSelCon, PRUint32 aFlags) { return _to Init(doc, shell, aRoot, aSelCon, aFlags); } \
  NS_SCRIPTABLE NS_IMETHOD SetAttributeOrEquivalent(nsIDOMElement *element, const nsAString & sourceAttrName, const nsAString & sourceAttrValue, PRBool aSuppressTransaction) { return _to SetAttributeOrEquivalent(element, sourceAttrName, sourceAttrValue, aSuppressTransaction); } \
  NS_SCRIPTABLE NS_IMETHOD RemoveAttributeOrEquivalent(nsIDOMElement *element, const nsAString & sourceAttrName, PRBool aSuppressTransaction) { return _to RemoveAttributeOrEquivalent(element, sourceAttrName, aSuppressTransaction); } \
  NS_SCRIPTABLE NS_IMETHOD PostCreate(void) { return _to PostCreate(); } \
  NS_SCRIPTABLE NS_IMETHOD PreDestroy(PRBool aDestroyingFrames) { return _to PreDestroy(aDestroyingFrames); } \
  NS_SCRIPTABLE NS_IMETHOD GetFlags(PRUint32 *aFlags) { return _to GetFlags(aFlags); } \
  NS_SCRIPTABLE NS_IMETHOD SetFlags(PRUint32 aFlags) { return _to SetFlags(aFlags); } \
  NS_SCRIPTABLE NS_IMETHOD GetContentsMIMEType(char * *aContentsMIMEType) { return _to GetContentsMIMEType(aContentsMIMEType); } \
  NS_SCRIPTABLE NS_IMETHOD SetContentsMIMEType(const char * aContentsMIMEType) { return _to SetContentsMIMEType(aContentsMIMEType); } \
  NS_SCRIPTABLE NS_IMETHOD GetIsDocumentEditable(PRBool *aIsDocumentEditable) { return _to GetIsDocumentEditable(aIsDocumentEditable); } \
  NS_SCRIPTABLE NS_IMETHOD GetDocument(nsIDOMDocument * *aDocument) { return _to GetDocument(aDocument); } \
  NS_SCRIPTABLE NS_IMETHOD GetRootElement(nsIDOMElement * *aRootElement) { return _to GetRootElement(aRootElement); } \
  NS_SCRIPTABLE NS_IMETHOD GetSelectionController(nsISelectionController * *aSelectionController) { return _to GetSelectionController(aSelectionController); } \
  NS_SCRIPTABLE NS_IMETHOD DeleteSelection(PRInt16 action) { return _to DeleteSelection(action); } \
  NS_SCRIPTABLE NS_IMETHOD GetDocumentIsEmpty(PRBool *aDocumentIsEmpty) { return _to GetDocumentIsEmpty(aDocumentIsEmpty); } \
  NS_SCRIPTABLE NS_IMETHOD GetDocumentModified(PRBool *aDocumentModified) { return _to GetDocumentModified(aDocumentModified); } \
  NS_SCRIPTABLE NS_IMETHOD GetDocumentCharacterSet(nsACString & aDocumentCharacterSet) { return _to GetDocumentCharacterSet(aDocumentCharacterSet); } \
  NS_SCRIPTABLE NS_IMETHOD SetDocumentCharacterSet(const nsACString & aDocumentCharacterSet) { return _to SetDocumentCharacterSet(aDocumentCharacterSet); } \
  NS_SCRIPTABLE NS_IMETHOD ResetModificationCount(void) { return _to ResetModificationCount(); } \
  NS_SCRIPTABLE NS_IMETHOD GetModificationCount(PRInt32 *_retval NS_OUTPARAM) { return _to GetModificationCount(_retval); } \
  NS_SCRIPTABLE NS_IMETHOD IncrementModificationCount(PRInt32 aModCount) { return _to IncrementModificationCount(aModCount); } \
  NS_SCRIPTABLE NS_IMETHOD GetTransactionManager(nsITransactionManager * *aTransactionManager) { return _to GetTransactionManager(aTransactionManager); } \
  NS_SCRIPTABLE NS_IMETHOD SetTransactionManager(nsITransactionManager * aTransactionManager) { return _to SetTransactionManager(aTransactionManager); } \
  NS_SCRIPTABLE NS_IMETHOD DoTransaction(nsITransaction *txn) { return _to DoTransaction(txn); } \
  NS_SCRIPTABLE NS_IMETHOD EnableUndo(PRBool enable) { return _to EnableUndo(enable); } \
  NS_SCRIPTABLE NS_IMETHOD Undo(PRUint32 count) { return _to Undo(count); } \
  NS_SCRIPTABLE NS_IMETHOD CanUndo(PRBool *isEnabled NS_OUTPARAM, PRBool *canUndo NS_OUTPARAM) { return _to CanUndo(isEnabled, canUndo); } \
  NS_SCRIPTABLE NS_IMETHOD Redo(PRUint32 count) { return _to Redo(count); } \
  NS_SCRIPTABLE NS_IMETHOD CanRedo(PRBool *isEnabled NS_OUTPARAM, PRBool *canRedo NS_OUTPARAM) { return _to CanRedo(isEnabled, canRedo); } \
  NS_SCRIPTABLE NS_IMETHOD BeginTransaction(void) { return _to BeginTransaction(); } \
  NS_SCRIPTABLE NS_IMETHOD EndTransaction(void) { return _to EndTransaction(); } \
  NS_SCRIPTABLE NS_IMETHOD BeginPlaceHolderTransaction(nsIAtom *name) { return _to BeginPlaceHolderTransaction(name); } \
  NS_SCRIPTABLE NS_IMETHOD EndPlaceHolderTransaction(void) { return _to EndPlaceHolderTransaction(); } \
  NS_SCRIPTABLE NS_IMETHOD ShouldTxnSetSelection(PRBool *_retval NS_OUTPARAM) { return _to ShouldTxnSetSelection(_retval); } \
  NS_SCRIPTABLE NS_IMETHOD SetShouldTxnSetSelection(PRBool should) { return _to SetShouldTxnSetSelection(should); } \
  NS_SCRIPTABLE NS_IMETHOD GetInlineSpellChecker(PRBool autoCreate, nsIInlineSpellChecker **_retval NS_OUTPARAM) { return _to GetInlineSpellChecker(autoCreate, _retval); } \
  NS_SCRIPTABLE NS_IMETHOD SyncRealTimeSpell(void) { return _to SyncRealTimeSpell(); } \
  NS_SCRIPTABLE NS_IMETHOD SetSpellcheckUserOverride(PRBool enable) { return _to SetSpellcheckUserOverride(enable); } \
  NS_SCRIPTABLE NS_IMETHOD Cut(void) { return _to Cut(); } \
  NS_SCRIPTABLE NS_IMETHOD CanCut(PRBool *_retval NS_OUTPARAM) { return _to CanCut(_retval); } \
  NS_SCRIPTABLE NS_IMETHOD Copy(void) { return _to Copy(); } \
  NS_SCRIPTABLE NS_IMETHOD CanCopy(PRBool *_retval NS_OUTPARAM) { return _to CanCopy(_retval); } \
  NS_SCRIPTABLE NS_IMETHOD Paste(PRInt32 aSelectionType) { return _to Paste(aSelectionType); } \
  NS_SCRIPTABLE NS_IMETHOD CanPaste(PRInt32 aSelectionType, PRBool *_retval NS_OUTPARAM) { return _to CanPaste(aSelectionType, _retval); } \
  NS_SCRIPTABLE NS_IMETHOD SelectAll(void) { return _to SelectAll(); } \
  NS_SCRIPTABLE NS_IMETHOD BeginningOfDocument(void) { return _to BeginningOfDocument(); } \
  NS_SCRIPTABLE NS_IMETHOD EndOfDocument(void) { return _to EndOfDocument(); } \
  NS_SCRIPTABLE NS_IMETHOD CanDrag(nsIDOMEvent *aEvent, PRBool *_retval NS_OUTPARAM) { return _to CanDrag(aEvent, _retval); } \
  NS_SCRIPTABLE NS_IMETHOD DoDrag(nsIDOMEvent *aEvent) { return _to DoDrag(aEvent); } \
  NS_SCRIPTABLE NS_IMETHOD InsertFromDrop(nsIDOMEvent *aEvent) { return _to InsertFromDrop(aEvent); } \
  NS_SCRIPTABLE NS_IMETHOD SetAttribute(nsIDOMElement *aElement, const nsAString & attributestr, const nsAString & attvalue) { return _to SetAttribute(aElement, attributestr, attvalue); } \
  NS_SCRIPTABLE NS_IMETHOD GetAttributeValue(nsIDOMElement *aElement, const nsAString & attributestr, nsAString & resultValue NS_OUTPARAM, PRBool *_retval NS_OUTPARAM) { return _to GetAttributeValue(aElement, attributestr, resultValue, _retval); } \
  NS_SCRIPTABLE NS_IMETHOD RemoveAttribute(nsIDOMElement *aElement, const nsAString & aAttribute) { return _to RemoveAttribute(aElement, aAttribute); } \
  NS_SCRIPTABLE NS_IMETHOD CloneAttribute(const nsAString & aAttribute, nsIDOMNode *aDestNode, nsIDOMNode *aSourceNode) { return _to CloneAttribute(aAttribute, aDestNode, aSourceNode); } \
  NS_SCRIPTABLE NS_IMETHOD CloneAttributes(nsIDOMNode *destNode, nsIDOMNode *sourceNode) { return _to CloneAttributes(destNode, sourceNode); } \
  NS_SCRIPTABLE NS_IMETHOD CreateNode(const nsAString & tag, nsIDOMNode *parent, PRInt32 position, nsIDOMNode **_retval NS_OUTPARAM) { return _to CreateNode(tag, parent, position, _retval); } \
  NS_SCRIPTABLE NS_IMETHOD InsertNode(nsIDOMNode *node, nsIDOMNode *parent, PRInt32 aPosition) { return _to InsertNode(node, parent, aPosition); } \
  NS_SCRIPTABLE NS_IMETHOD SplitNode(nsIDOMNode *existingRightNode, PRInt32 offset, nsIDOMNode **newLeftNode NS_OUTPARAM) { return _to SplitNode(existingRightNode, offset, newLeftNode); } \
  NS_SCRIPTABLE NS_IMETHOD JoinNodes(nsIDOMNode *leftNode, nsIDOMNode *rightNode, nsIDOMNode *parent) { return _to JoinNodes(leftNode, rightNode, parent); } \
  NS_SCRIPTABLE NS_IMETHOD DeleteNode(nsIDOMNode *child) { return _to DeleteNode(child); } \
  NS_SCRIPTABLE NS_IMETHOD MarkNodeDirty(nsIDOMNode *node) { return _to MarkNodeDirty(node); } \
  NS_SCRIPTABLE NS_IMETHOD SwitchTextDirection(void) { return _to SwitchTextDirection(); } \
  NS_SCRIPTABLE NS_IMETHOD OutputToString(const nsAString & formatType, PRUint32 flags, nsAString & _retval NS_OUTPARAM) { return _to OutputToString(formatType, flags, _retval); } \
  NS_SCRIPTABLE NS_IMETHOD OutputToStream(nsIOutputStream *aStream, const nsAString & formatType, const nsACString & charsetOverride, PRUint32 flags) { return _to OutputToStream(aStream, formatType, charsetOverride, flags); } \
  NS_SCRIPTABLE NS_IMETHOD AddEditorObserver(nsIEditorObserver *observer) { return _to AddEditorObserver(observer); } \
  NS_SCRIPTABLE NS_IMETHOD RemoveEditorObserver(nsIEditorObserver *observer) { return _to RemoveEditorObserver(observer); } \
  NS_SCRIPTABLE NS_IMETHOD AddEditActionListener(nsIEditActionListener *listener) { return _to AddEditActionListener(listener); } \
  NS_SCRIPTABLE NS_IMETHOD RemoveEditActionListener(nsIEditActionListener *listener) { return _to RemoveEditActionListener(listener); } \
  NS_SCRIPTABLE NS_IMETHOD AddDocumentStateListener(nsIDocumentStateListener *listener) { return _to AddDocumentStateListener(listener); } \
  NS_SCRIPTABLE NS_IMETHOD RemoveDocumentStateListener(nsIDocumentStateListener *listener) { return _to RemoveDocumentStateListener(listener); } \
  NS_SCRIPTABLE NS_IMETHOD DumpContentTree(void) { return _to DumpContentTree(); } \
  NS_SCRIPTABLE NS_IMETHOD DebugDumpContent(void) { return _to DebugDumpContent(); } \
  NS_SCRIPTABLE NS_IMETHOD DebugUnitTests(PRInt32 *outNumTests NS_OUTPARAM, PRInt32 *outNumTestsFailed NS_OUTPARAM) { return _to DebugUnitTests(outNumTests, outNumTestsFailed); } \
  NS_IMETHOD_(PRBool) IsModifiableNode(nsIDOMNode *aNode) { return _to IsModifiableNode(aNode); } 

/* Use this macro to declare functions that forward the behavior of this interface to another object in a safe way. */
#define NS_FORWARD_SAFE_NSIEDITOR(_to) \
  NS_SCRIPTABLE NS_IMETHOD GetSelection(nsISelection * *aSelection) { return !_to ? NS_ERROR_NULL_POINTER : _to->GetSelection(aSelection); } \
  NS_IMETHOD Init(nsIDOMDocument *doc, nsIPresShell * shell, nsIContent *aRoot, nsISelectionController *aSelCon, PRUint32 aFlags) { return !_to ? NS_ERROR_NULL_POINTER : _to->Init(doc, shell, aRoot, aSelCon, aFlags); } \
  NS_SCRIPTABLE NS_IMETHOD SetAttributeOrEquivalent(nsIDOMElement *element, const nsAString & sourceAttrName, const nsAString & sourceAttrValue, PRBool aSuppressTransaction) { return !_to ? NS_ERROR_NULL_POINTER : _to->SetAttributeOrEquivalent(element, sourceAttrName, sourceAttrValue, aSuppressTransaction); } \
  NS_SCRIPTABLE NS_IMETHOD RemoveAttributeOrEquivalent(nsIDOMElement *element, const nsAString & sourceAttrName, PRBool aSuppressTransaction) { return !_to ? NS_ERROR_NULL_POINTER : _to->RemoveAttributeOrEquivalent(element, sourceAttrName, aSuppressTransaction); } \
  NS_SCRIPTABLE NS_IMETHOD PostCreate(void) { return !_to ? NS_ERROR_NULL_POINTER : _to->PostCreate(); } \
  NS_SCRIPTABLE NS_IMETHOD PreDestroy(PRBool aDestroyingFrames) { return !_to ? NS_ERROR_NULL_POINTER : _to->PreDestroy(aDestroyingFrames); } \
  NS_SCRIPTABLE NS_IMETHOD GetFlags(PRUint32 *aFlags) { return !_to ? NS_ERROR_NULL_POINTER : _to->GetFlags(aFlags); } \
  NS_SCRIPTABLE NS_IMETHOD SetFlags(PRUint32 aFlags) { return !_to ? NS_ERROR_NULL_POINTER : _to->SetFlags(aFlags); } \
  NS_SCRIPTABLE NS_IMETHOD GetContentsMIMEType(char * *aContentsMIMEType) { return !_to ? NS_ERROR_NULL_POINTER : _to->GetContentsMIMEType(aContentsMIMEType); } \
  NS_SCRIPTABLE NS_IMETHOD SetContentsMIMEType(const char * aContentsMIMEType) { return !_to ? NS_ERROR_NULL_POINTER : _to->SetContentsMIMEType(aContentsMIMEType); } \
  NS_SCRIPTABLE NS_IMETHOD GetIsDocumentEditable(PRBool *aIsDocumentEditable) { return !_to ? NS_ERROR_NULL_POINTER : _to->GetIsDocumentEditable(aIsDocumentEditable); } \
  NS_SCRIPTABLE NS_IMETHOD GetDocument(nsIDOMDocument * *aDocument) { return !_to ? NS_ERROR_NULL_POINTER : _to->GetDocument(aDocument); } \
  NS_SCRIPTABLE NS_IMETHOD GetRootElement(nsIDOMElement * *aRootElement) { return !_to ? NS_ERROR_NULL_POINTER : _to->GetRootElement(aRootElement); } \
  NS_SCRIPTABLE NS_IMETHOD GetSelectionController(nsISelectionController * *aSelectionController) { return !_to ? NS_ERROR_NULL_POINTER : _to->GetSelectionController(aSelectionController); } \
  NS_SCRIPTABLE NS_IMETHOD DeleteSelection(PRInt16 action) { return !_to ? NS_ERROR_NULL_POINTER : _to->DeleteSelection(action); } \
  NS_SCRIPTABLE NS_IMETHOD GetDocumentIsEmpty(PRBool *aDocumentIsEmpty) { return !_to ? NS_ERROR_NULL_POINTER : _to->GetDocumentIsEmpty(aDocumentIsEmpty); } \
  NS_SCRIPTABLE NS_IMETHOD GetDocumentModified(PRBool *aDocumentModified) { return !_to ? NS_ERROR_NULL_POINTER : _to->GetDocumentModified(aDocumentModified); } \
  NS_SCRIPTABLE NS_IMETHOD GetDocumentCharacterSet(nsACString & aDocumentCharacterSet) { return !_to ? NS_ERROR_NULL_POINTER : _to->GetDocumentCharacterSet(aDocumentCharacterSet); } \
  NS_SCRIPTABLE NS_IMETHOD SetDocumentCharacterSet(const nsACString & aDocumentCharacterSet) { return !_to ? NS_ERROR_NULL_POINTER : _to->SetDocumentCharacterSet(aDocumentCharacterSet); } \
  NS_SCRIPTABLE NS_IMETHOD ResetModificationCount(void) { return !_to ? NS_ERROR_NULL_POINTER : _to->ResetModificationCount(); } \
  NS_SCRIPTABLE NS_IMETHOD GetModificationCount(PRInt32 *_retval NS_OUTPARAM) { return !_to ? NS_ERROR_NULL_POINTER : _to->GetModificationCount(_retval); } \
  NS_SCRIPTABLE NS_IMETHOD IncrementModificationCount(PRInt32 aModCount) { return !_to ? NS_ERROR_NULL_POINTER : _to->IncrementModificationCount(aModCount); } \
  NS_SCRIPTABLE NS_IMETHOD GetTransactionManager(nsITransactionManager * *aTransactionManager) { return !_to ? NS_ERROR_NULL_POINTER : _to->GetTransactionManager(aTransactionManager); } \
  NS_SCRIPTABLE NS_IMETHOD SetTransactionManager(nsITransactionManager * aTransactionManager) { return !_to ? NS_ERROR_NULL_POINTER : _to->SetTransactionManager(aTransactionManager); } \
  NS_SCRIPTABLE NS_IMETHOD DoTransaction(nsITransaction *txn) { return !_to ? NS_ERROR_NULL_POINTER : _to->DoTransaction(txn); } \
  NS_SCRIPTABLE NS_IMETHOD EnableUndo(PRBool enable) { return !_to ? NS_ERROR_NULL_POINTER : _to->EnableUndo(enable); } \
  NS_SCRIPTABLE NS_IMETHOD Undo(PRUint32 count) { return !_to ? NS_ERROR_NULL_POINTER : _to->Undo(count); } \
  NS_SCRIPTABLE NS_IMETHOD CanUndo(PRBool *isEnabled NS_OUTPARAM, PRBool *canUndo NS_OUTPARAM) { return !_to ? NS_ERROR_NULL_POINTER : _to->CanUndo(isEnabled, canUndo); } \
  NS_SCRIPTABLE NS_IMETHOD Redo(PRUint32 count) { return !_to ? NS_ERROR_NULL_POINTER : _to->Redo(count); } \
  NS_SCRIPTABLE NS_IMETHOD CanRedo(PRBool *isEnabled NS_OUTPARAM, PRBool *canRedo NS_OUTPARAM) { return !_to ? NS_ERROR_NULL_POINTER : _to->CanRedo(isEnabled, canRedo); } \
  NS_SCRIPTABLE NS_IMETHOD BeginTransaction(void) { return !_to ? NS_ERROR_NULL_POINTER : _to->BeginTransaction(); } \
  NS_SCRIPTABLE NS_IMETHOD EndTransaction(void) { return !_to ? NS_ERROR_NULL_POINTER : _to->EndTransaction(); } \
  NS_SCRIPTABLE NS_IMETHOD BeginPlaceHolderTransaction(nsIAtom *name) { return !_to ? NS_ERROR_NULL_POINTER : _to->BeginPlaceHolderTransaction(name); } \
  NS_SCRIPTABLE NS_IMETHOD EndPlaceHolderTransaction(void) { return !_to ? NS_ERROR_NULL_POINTER : _to->EndPlaceHolderTransaction(); } \
  NS_SCRIPTABLE NS_IMETHOD ShouldTxnSetSelection(PRBool *_retval NS_OUTPARAM) { return !_to ? NS_ERROR_NULL_POINTER : _to->ShouldTxnSetSelection(_retval); } \
  NS_SCRIPTABLE NS_IMETHOD SetShouldTxnSetSelection(PRBool should) { return !_to ? NS_ERROR_NULL_POINTER : _to->SetShouldTxnSetSelection(should); } \
  NS_SCRIPTABLE NS_IMETHOD GetInlineSpellChecker(PRBool autoCreate, nsIInlineSpellChecker **_retval NS_OUTPARAM) { return !_to ? NS_ERROR_NULL_POINTER : _to->GetInlineSpellChecker(autoCreate, _retval); } \
  NS_SCRIPTABLE NS_IMETHOD SyncRealTimeSpell(void) { return !_to ? NS_ERROR_NULL_POINTER : _to->SyncRealTimeSpell(); } \
  NS_SCRIPTABLE NS_IMETHOD SetSpellcheckUserOverride(PRBool enable) { return !_to ? NS_ERROR_NULL_POINTER : _to->SetSpellcheckUserOverride(enable); } \
  NS_SCRIPTABLE NS_IMETHOD Cut(void) { return !_to ? NS_ERROR_NULL_POINTER : _to->Cut(); } \
  NS_SCRIPTABLE NS_IMETHOD CanCut(PRBool *_retval NS_OUTPARAM) { return !_to ? NS_ERROR_NULL_POINTER : _to->CanCut(_retval); } \
  NS_SCRIPTABLE NS_IMETHOD Copy(void) { return !_to ? NS_ERROR_NULL_POINTER : _to->Copy(); } \
  NS_SCRIPTABLE NS_IMETHOD CanCopy(PRBool *_retval NS_OUTPARAM) { return !_to ? NS_ERROR_NULL_POINTER : _to->CanCopy(_retval); } \
  NS_SCRIPTABLE NS_IMETHOD Paste(PRInt32 aSelectionType) { return !_to ? NS_ERROR_NULL_POINTER : _to->Paste(aSelectionType); } \
  NS_SCRIPTABLE NS_IMETHOD CanPaste(PRInt32 aSelectionType, PRBool *_retval NS_OUTPARAM) { return !_to ? NS_ERROR_NULL_POINTER : _to->CanPaste(aSelectionType, _retval); } \
  NS_SCRIPTABLE NS_IMETHOD SelectAll(void) { return !_to ? NS_ERROR_NULL_POINTER : _to->SelectAll(); } \
  NS_SCRIPTABLE NS_IMETHOD BeginningOfDocument(void) { return !_to ? NS_ERROR_NULL_POINTER : _to->BeginningOfDocument(); } \
  NS_SCRIPTABLE NS_IMETHOD EndOfDocument(void) { return !_to ? NS_ERROR_NULL_POINTER : _to->EndOfDocument(); } \
  NS_SCRIPTABLE NS_IMETHOD CanDrag(nsIDOMEvent *aEvent, PRBool *_retval NS_OUTPARAM) { return !_to ? NS_ERROR_NULL_POINTER : _to->CanDrag(aEvent, _retval); } \
  NS_SCRIPTABLE NS_IMETHOD DoDrag(nsIDOMEvent *aEvent) { return !_to ? NS_ERROR_NULL_POINTER : _to->DoDrag(aEvent); } \
  NS_SCRIPTABLE NS_IMETHOD InsertFromDrop(nsIDOMEvent *aEvent) { return !_to ? NS_ERROR_NULL_POINTER : _to->InsertFromDrop(aEvent); } \
  NS_SCRIPTABLE NS_IMETHOD SetAttribute(nsIDOMElement *aElement, const nsAString & attributestr, const nsAString & attvalue) { return !_to ? NS_ERROR_NULL_POINTER : _to->SetAttribute(aElement, attributestr, attvalue); } \
  NS_SCRIPTABLE NS_IMETHOD GetAttributeValue(nsIDOMElement *aElement, const nsAString & attributestr, nsAString & resultValue NS_OUTPARAM, PRBool *_retval NS_OUTPARAM) { return !_to ? NS_ERROR_NULL_POINTER : _to->GetAttributeValue(aElement, attributestr, resultValue, _retval); } \
  NS_SCRIPTABLE NS_IMETHOD RemoveAttribute(nsIDOMElement *aElement, const nsAString & aAttribute) { return !_to ? NS_ERROR_NULL_POINTER : _to->RemoveAttribute(aElement, aAttribute); } \
  NS_SCRIPTABLE NS_IMETHOD CloneAttribute(const nsAString & aAttribute, nsIDOMNode *aDestNode, nsIDOMNode *aSourceNode) { return !_to ? NS_ERROR_NULL_POINTER : _to->CloneAttribute(aAttribute, aDestNode, aSourceNode); } \
  NS_SCRIPTABLE NS_IMETHOD CloneAttributes(nsIDOMNode *destNode, nsIDOMNode *sourceNode) { return !_to ? NS_ERROR_NULL_POINTER : _to->CloneAttributes(destNode, sourceNode); } \
  NS_SCRIPTABLE NS_IMETHOD CreateNode(const nsAString & tag, nsIDOMNode *parent, PRInt32 position, nsIDOMNode **_retval NS_OUTPARAM) { return !_to ? NS_ERROR_NULL_POINTER : _to->CreateNode(tag, parent, position, _retval); } \
  NS_SCRIPTABLE NS_IMETHOD InsertNode(nsIDOMNode *node, nsIDOMNode *parent, PRInt32 aPosition) { return !_to ? NS_ERROR_NULL_POINTER : _to->InsertNode(node, parent, aPosition); } \
  NS_SCRIPTABLE NS_IMETHOD SplitNode(nsIDOMNode *existingRightNode, PRInt32 offset, nsIDOMNode **newLeftNode NS_OUTPARAM) { return !_to ? NS_ERROR_NULL_POINTER : _to->SplitNode(existingRightNode, offset, newLeftNode); } \
  NS_SCRIPTABLE NS_IMETHOD JoinNodes(nsIDOMNode *leftNode, nsIDOMNode *rightNode, nsIDOMNode *parent) { return !_to ? NS_ERROR_NULL_POINTER : _to->JoinNodes(leftNode, rightNode, parent); } \
  NS_SCRIPTABLE NS_IMETHOD DeleteNode(nsIDOMNode *child) { return !_to ? NS_ERROR_NULL_POINTER : _to->DeleteNode(child); } \
  NS_SCRIPTABLE NS_IMETHOD MarkNodeDirty(nsIDOMNode *node) { return !_to ? NS_ERROR_NULL_POINTER : _to->MarkNodeDirty(node); } \
  NS_SCRIPTABLE NS_IMETHOD SwitchTextDirection(void) { return !_to ? NS_ERROR_NULL_POINTER : _to->SwitchTextDirection(); } \
  NS_SCRIPTABLE NS_IMETHOD OutputToString(const nsAString & formatType, PRUint32 flags, nsAString & _retval NS_OUTPARAM) { return !_to ? NS_ERROR_NULL_POINTER : _to->OutputToString(formatType, flags, _retval); } \
  NS_SCRIPTABLE NS_IMETHOD OutputToStream(nsIOutputStream *aStream, const nsAString & formatType, const nsACString & charsetOverride, PRUint32 flags) { return !_to ? NS_ERROR_NULL_POINTER : _to->OutputToStream(aStream, formatType, charsetOverride, flags); } \
  NS_SCRIPTABLE NS_IMETHOD AddEditorObserver(nsIEditorObserver *observer) { return !_to ? NS_ERROR_NULL_POINTER : _to->AddEditorObserver(observer); } \
  NS_SCRIPTABLE NS_IMETHOD RemoveEditorObserver(nsIEditorObserver *observer) { return !_to ? NS_ERROR_NULL_POINTER : _to->RemoveEditorObserver(observer); } \
  NS_SCRIPTABLE NS_IMETHOD AddEditActionListener(nsIEditActionListener *listener) { return !_to ? NS_ERROR_NULL_POINTER : _to->AddEditActionListener(listener); } \
  NS_SCRIPTABLE NS_IMETHOD RemoveEditActionListener(nsIEditActionListener *listener) { return !_to ? NS_ERROR_NULL_POINTER : _to->RemoveEditActionListener(listener); } \
  NS_SCRIPTABLE NS_IMETHOD AddDocumentStateListener(nsIDocumentStateListener *listener) { return !_to ? NS_ERROR_NULL_POINTER : _to->AddDocumentStateListener(listener); } \
  NS_SCRIPTABLE NS_IMETHOD RemoveDocumentStateListener(nsIDocumentStateListener *listener) { return !_to ? NS_ERROR_NULL_POINTER : _to->RemoveDocumentStateListener(listener); } \
  NS_SCRIPTABLE NS_IMETHOD DumpContentTree(void) { return !_to ? NS_ERROR_NULL_POINTER : _to->DumpContentTree(); } \
  NS_SCRIPTABLE NS_IMETHOD DebugDumpContent(void) { return !_to ? NS_ERROR_NULL_POINTER : _to->DebugDumpContent(); } \
  NS_SCRIPTABLE NS_IMETHOD DebugUnitTests(PRInt32 *outNumTests NS_OUTPARAM, PRInt32 *outNumTestsFailed NS_OUTPARAM) { return !_to ? NS_ERROR_NULL_POINTER : _to->DebugUnitTests(outNumTests, outNumTestsFailed); } \
  NS_IMETHOD_(PRBool) IsModifiableNode(nsIDOMNode *aNode) { return !_to ? NS_ERROR_NULL_POINTER : _to->IsModifiableNode(aNode); } 

#if 0
/* Use the code below as a template for the implementation class for this interface. */

/* Header file */
class nsEditor : public nsIEditor
{
public:
  NS_DECL_ISUPPORTS
  NS_DECL_NSIEDITOR

  nsEditor();

private:
  ~nsEditor();

protected:
  /* additional members */
};

/* Implementation file */
NS_IMPL_ISUPPORTS1(nsEditor, nsIEditor)

nsEditor::nsEditor()
{
  /* member initializers and constructor code */
}

nsEditor::~nsEditor()
{
  /* destructor code */
}

/* readonly attribute nsISelection selection; */
NS_IMETHODIMP nsEditor::GetSelection(nsISelection * *aSelection)
{
    return NS_ERROR_NOT_IMPLEMENTED;
}

/* [noscript] void init (in nsIDOMDocument doc, in nsIPresShellPtr shell, in nsIContent aRoot, in nsISelectionController aSelCon, in unsigned long aFlags); */
NS_IMETHODIMP nsEditor::Init(nsIDOMDocument *doc, nsIPresShell * shell, nsIContent *aRoot, nsISelectionController *aSelCon, PRUint32 aFlags)
{
    return NS_ERROR_NOT_IMPLEMENTED;
}

/* void setAttributeOrEquivalent (in nsIDOMElement element, in AString sourceAttrName, in AString sourceAttrValue, in boolean aSuppressTransaction); */
NS_IMETHODIMP nsEditor::SetAttributeOrEquivalent(nsIDOMElement *element, const nsAString & sourceAttrName, const nsAString & sourceAttrValue, PRBool aSuppressTransaction)
{
    return NS_ERROR_NOT_IMPLEMENTED;
}

/* void removeAttributeOrEquivalent (in nsIDOMElement element, in DOMString sourceAttrName, in boolean aSuppressTransaction); */
NS_IMETHODIMP nsEditor::RemoveAttributeOrEquivalent(nsIDOMElement *element, const nsAString & sourceAttrName, PRBool aSuppressTransaction)
{
    return NS_ERROR_NOT_IMPLEMENTED;
}

/* void postCreate (); */
NS_IMETHODIMP nsEditor::PostCreate()
{
    return NS_ERROR_NOT_IMPLEMENTED;
}

/* void preDestroy (in boolean aDestroyingFrames); */
NS_IMETHODIMP nsEditor::PreDestroy(PRBool aDestroyingFrames)
{
    return NS_ERROR_NOT_IMPLEMENTED;
}

/* attribute unsigned long flags; */
NS_IMETHODIMP nsEditor::GetFlags(PRUint32 *aFlags)
{
    return NS_ERROR_NOT_IMPLEMENTED;
}
NS_IMETHODIMP nsEditor::SetFlags(PRUint32 aFlags)
{
    return NS_ERROR_NOT_IMPLEMENTED;
}

/* attribute string contentsMIMEType; */
NS_IMETHODIMP nsEditor::GetContentsMIMEType(char * *aContentsMIMEType)
{
    return NS_ERROR_NOT_IMPLEMENTED;
}
NS_IMETHODIMP nsEditor::SetContentsMIMEType(const char * aContentsMIMEType)
{
    return NS_ERROR_NOT_IMPLEMENTED;
}

/* readonly attribute boolean isDocumentEditable; */
NS_IMETHODIMP nsEditor::GetIsDocumentEditable(PRBool *aIsDocumentEditable)
{
    return NS_ERROR_NOT_IMPLEMENTED;
}

/* readonly attribute nsIDOMDocument document; */
NS_IMETHODIMP nsEditor::GetDocument(nsIDOMDocument * *aDocument)
{
    return NS_ERROR_NOT_IMPLEMENTED;
}

/* readonly attribute nsIDOMElement rootElement; */
NS_IMETHODIMP nsEditor::GetRootElement(nsIDOMElement * *aRootElement)
{
    return NS_ERROR_NOT_IMPLEMENTED;
}

/* readonly attribute nsISelectionController selectionController; */
NS_IMETHODIMP nsEditor::GetSelectionController(nsISelectionController * *aSelectionController)
{
    return NS_ERROR_NOT_IMPLEMENTED;
}

/* void deleteSelection (in short action); */
NS_IMETHODIMP nsEditor::DeleteSelection(PRInt16 action)
{
    return NS_ERROR_NOT_IMPLEMENTED;
}

/* readonly attribute boolean documentIsEmpty; */
NS_IMETHODIMP nsEditor::GetDocumentIsEmpty(PRBool *aDocumentIsEmpty)
{
    return NS_ERROR_NOT_IMPLEMENTED;
}

/* readonly attribute boolean documentModified; */
NS_IMETHODIMP nsEditor::GetDocumentModified(PRBool *aDocumentModified)
{
    return NS_ERROR_NOT_IMPLEMENTED;
}

/* attribute ACString documentCharacterSet; */
NS_IMETHODIMP nsEditor::GetDocumentCharacterSet(nsACString & aDocumentCharacterSet)
{
    return NS_ERROR_NOT_IMPLEMENTED;
}
NS_IMETHODIMP nsEditor::SetDocumentCharacterSet(const nsACString & aDocumentCharacterSet)
{
    return NS_ERROR_NOT_IMPLEMENTED;
}

/* void resetModificationCount (); */
NS_IMETHODIMP nsEditor::ResetModificationCount()
{
    return NS_ERROR_NOT_IMPLEMENTED;
}

/* long getModificationCount (); */
NS_IMETHODIMP nsEditor::GetModificationCount(PRInt32 *_retval NS_OUTPARAM)
{
    return NS_ERROR_NOT_IMPLEMENTED;
}

/* void incrementModificationCount (in long aModCount); */
NS_IMETHODIMP nsEditor::IncrementModificationCount(PRInt32 aModCount)
{
    return NS_ERROR_NOT_IMPLEMENTED;
}

/* attribute nsITransactionManager transactionManager; */
NS_IMETHODIMP nsEditor::GetTransactionManager(nsITransactionManager * *aTransactionManager)
{
    return NS_ERROR_NOT_IMPLEMENTED;
}
NS_IMETHODIMP nsEditor::SetTransactionManager(nsITransactionManager * aTransactionManager)
{
    return NS_ERROR_NOT_IMPLEMENTED;
}

/* void doTransaction (in nsITransaction txn); */
NS_IMETHODIMP nsEditor::DoTransaction(nsITransaction *txn)
{
    return NS_ERROR_NOT_IMPLEMENTED;
}

/* void enableUndo (in boolean enable); */
NS_IMETHODIMP nsEditor::EnableUndo(PRBool enable)
{
    return NS_ERROR_NOT_IMPLEMENTED;
}

/* void undo (in unsigned long count); */
NS_IMETHODIMP nsEditor::Undo(PRUint32 count)
{
    return NS_ERROR_NOT_IMPLEMENTED;
}

/* void canUndo (out boolean isEnabled, out boolean canUndo); */
NS_IMETHODIMP nsEditor::CanUndo(PRBool *isEnabled NS_OUTPARAM, PRBool *canUndo NS_OUTPARAM)
{
    return NS_ERROR_NOT_IMPLEMENTED;
}

/* void redo (in unsigned long count); */
NS_IMETHODIMP nsEditor::Redo(PRUint32 count)
{
    return NS_ERROR_NOT_IMPLEMENTED;
}

/* void canRedo (out boolean isEnabled, out boolean canRedo); */
NS_IMETHODIMP nsEditor::CanRedo(PRBool *isEnabled NS_OUTPARAM, PRBool *canRedo NS_OUTPARAM)
{
    return NS_ERROR_NOT_IMPLEMENTED;
}

/* void beginTransaction (); */
NS_IMETHODIMP nsEditor::BeginTransaction()
{
    return NS_ERROR_NOT_IMPLEMENTED;
}

/* void endTransaction (); */
NS_IMETHODIMP nsEditor::EndTransaction()
{
    return NS_ERROR_NOT_IMPLEMENTED;
}

/* void beginPlaceHolderTransaction (in nsIAtom name); */
NS_IMETHODIMP nsEditor::BeginPlaceHolderTransaction(nsIAtom *name)
{
    return NS_ERROR_NOT_IMPLEMENTED;
}

/* void endPlaceHolderTransaction (); */
NS_IMETHODIMP nsEditor::EndPlaceHolderTransaction()
{
    return NS_ERROR_NOT_IMPLEMENTED;
}

/* boolean shouldTxnSetSelection (); */
NS_IMETHODIMP nsEditor::ShouldTxnSetSelection(PRBool *_retval NS_OUTPARAM)
{
    return NS_ERROR_NOT_IMPLEMENTED;
}

/* void setShouldTxnSetSelection (in boolean should); */
NS_IMETHODIMP nsEditor::SetShouldTxnSetSelection(PRBool should)
{
    return NS_ERROR_NOT_IMPLEMENTED;
}

/* nsIInlineSpellChecker getInlineSpellChecker (in boolean autoCreate); */
NS_IMETHODIMP nsEditor::GetInlineSpellChecker(PRBool autoCreate, nsIInlineSpellChecker **_retval NS_OUTPARAM)
{
    return NS_ERROR_NOT_IMPLEMENTED;
}

/* void syncRealTimeSpell (); */
NS_IMETHODIMP nsEditor::SyncRealTimeSpell()
{
    return NS_ERROR_NOT_IMPLEMENTED;
}

/* void setSpellcheckUserOverride (in boolean enable); */
NS_IMETHODIMP nsEditor::SetSpellcheckUserOverride(PRBool enable)
{
    return NS_ERROR_NOT_IMPLEMENTED;
}

/* void cut (); */
NS_IMETHODIMP nsEditor::Cut()
{
    return NS_ERROR_NOT_IMPLEMENTED;
}

/* boolean canCut (); */
NS_IMETHODIMP nsEditor::CanCut(PRBool *_retval NS_OUTPARAM)
{
    return NS_ERROR_NOT_IMPLEMENTED;
}

/* void copy (); */
NS_IMETHODIMP nsEditor::Copy()
{
    return NS_ERROR_NOT_IMPLEMENTED;
}

/* boolean canCopy (); */
NS_IMETHODIMP nsEditor::CanCopy(PRBool *_retval NS_OUTPARAM)
{
    return NS_ERROR_NOT_IMPLEMENTED;
}

/* void paste (in long aSelectionType); */
NS_IMETHODIMP nsEditor::Paste(PRInt32 aSelectionType)
{
    return NS_ERROR_NOT_IMPLEMENTED;
}

/* boolean canPaste (in long aSelectionType); */
NS_IMETHODIMP nsEditor::CanPaste(PRInt32 aSelectionType, PRBool *_retval NS_OUTPARAM)
{
    return NS_ERROR_NOT_IMPLEMENTED;
}

/* void selectAll (); */
NS_IMETHODIMP nsEditor::SelectAll()
{
    return NS_ERROR_NOT_IMPLEMENTED;
}

/* void beginningOfDocument (); */
NS_IMETHODIMP nsEditor::BeginningOfDocument()
{
    return NS_ERROR_NOT_IMPLEMENTED;
}

/* void endOfDocument (); */
NS_IMETHODIMP nsEditor::EndOfDocument()
{
    return NS_ERROR_NOT_IMPLEMENTED;
}

/* boolean canDrag (in nsIDOMEvent aEvent); */
NS_IMETHODIMP nsEditor::CanDrag(nsIDOMEvent *aEvent, PRBool *_retval NS_OUTPARAM)
{
    return NS_ERROR_NOT_IMPLEMENTED;
}

/* void doDrag (in nsIDOMEvent aEvent); */
NS_IMETHODIMP nsEditor::DoDrag(nsIDOMEvent *aEvent)
{
    return NS_ERROR_NOT_IMPLEMENTED;
}

/* void insertFromDrop (in nsIDOMEvent aEvent); */
NS_IMETHODIMP nsEditor::InsertFromDrop(nsIDOMEvent *aEvent)
{
    return NS_ERROR_NOT_IMPLEMENTED;
}

/* void setAttribute (in nsIDOMElement aElement, in AString attributestr, in AString attvalue); */
NS_IMETHODIMP nsEditor::SetAttribute(nsIDOMElement *aElement, const nsAString & attributestr, const nsAString & attvalue)
{
    return NS_ERROR_NOT_IMPLEMENTED;
}

/* boolean getAttributeValue (in nsIDOMElement aElement, in AString attributestr, out AString resultValue); */
NS_IMETHODIMP nsEditor::GetAttributeValue(nsIDOMElement *aElement, const nsAString & attributestr, nsAString & resultValue NS_OUTPARAM, PRBool *_retval NS_OUTPARAM)
{
    return NS_ERROR_NOT_IMPLEMENTED;
}

/* void removeAttribute (in nsIDOMElement aElement, in AString aAttribute); */
NS_IMETHODIMP nsEditor::RemoveAttribute(nsIDOMElement *aElement, const nsAString & aAttribute)
{
    return NS_ERROR_NOT_IMPLEMENTED;
}

/* void cloneAttribute (in AString aAttribute, in nsIDOMNode aDestNode, in nsIDOMNode aSourceNode); */
NS_IMETHODIMP nsEditor::CloneAttribute(const nsAString & aAttribute, nsIDOMNode *aDestNode, nsIDOMNode *aSourceNode)
{
    return NS_ERROR_NOT_IMPLEMENTED;
}

/* void cloneAttributes (in nsIDOMNode destNode, in nsIDOMNode sourceNode); */
NS_IMETHODIMP nsEditor::CloneAttributes(nsIDOMNode *destNode, nsIDOMNode *sourceNode)
{
    return NS_ERROR_NOT_IMPLEMENTED;
}

/* nsIDOMNode createNode (in AString tag, in nsIDOMNode parent, in long position); */
NS_IMETHODIMP nsEditor::CreateNode(const nsAString & tag, nsIDOMNode *parent, PRInt32 position, nsIDOMNode **_retval NS_OUTPARAM)
{
    return NS_ERROR_NOT_IMPLEMENTED;
}

/* void insertNode (in nsIDOMNode node, in nsIDOMNode parent, in long aPosition); */
NS_IMETHODIMP nsEditor::InsertNode(nsIDOMNode *node, nsIDOMNode *parent, PRInt32 aPosition)
{
    return NS_ERROR_NOT_IMPLEMENTED;
}

/* void splitNode (in nsIDOMNode existingRightNode, in long offset, out nsIDOMNode newLeftNode); */
NS_IMETHODIMP nsEditor::SplitNode(nsIDOMNode *existingRightNode, PRInt32 offset, nsIDOMNode **newLeftNode NS_OUTPARAM)
{
    return NS_ERROR_NOT_IMPLEMENTED;
}

/* void joinNodes (in nsIDOMNode leftNode, in nsIDOMNode rightNode, in nsIDOMNode parent); */
NS_IMETHODIMP nsEditor::JoinNodes(nsIDOMNode *leftNode, nsIDOMNode *rightNode, nsIDOMNode *parent)
{
    return NS_ERROR_NOT_IMPLEMENTED;
}

/* void deleteNode (in nsIDOMNode child); */
NS_IMETHODIMP nsEditor::DeleteNode(nsIDOMNode *child)
{
    return NS_ERROR_NOT_IMPLEMENTED;
}

/* void markNodeDirty (in nsIDOMNode node); */
NS_IMETHODIMP nsEditor::MarkNodeDirty(nsIDOMNode *node)
{
    return NS_ERROR_NOT_IMPLEMENTED;
}

/* void switchTextDirection (); */
NS_IMETHODIMP nsEditor::SwitchTextDirection()
{
    return NS_ERROR_NOT_IMPLEMENTED;
}

/* AString outputToString (in AString formatType, in unsigned long flags); */
NS_IMETHODIMP nsEditor::OutputToString(const nsAString & formatType, PRUint32 flags, nsAString & _retval NS_OUTPARAM)
{
    return NS_ERROR_NOT_IMPLEMENTED;
}

/* void outputToStream (in nsIOutputStream aStream, in AString formatType, in ACString charsetOverride, in unsigned long flags); */
NS_IMETHODIMP nsEditor::OutputToStream(nsIOutputStream *aStream, const nsAString & formatType, const nsACString & charsetOverride, PRUint32 flags)
{
    return NS_ERROR_NOT_IMPLEMENTED;
}

/* void addEditorObserver (in nsIEditorObserver observer); */
NS_IMETHODIMP nsEditor::AddEditorObserver(nsIEditorObserver *observer)
{
    return NS_ERROR_NOT_IMPLEMENTED;
}

/* void removeEditorObserver (in nsIEditorObserver observer); */
NS_IMETHODIMP nsEditor::RemoveEditorObserver(nsIEditorObserver *observer)
{
    return NS_ERROR_NOT_IMPLEMENTED;
}

/* void addEditActionListener (in nsIEditActionListener listener); */
NS_IMETHODIMP nsEditor::AddEditActionListener(nsIEditActionListener *listener)
{
    return NS_ERROR_NOT_IMPLEMENTED;
}

/* void removeEditActionListener (in nsIEditActionListener listener); */
NS_IMETHODIMP nsEditor::RemoveEditActionListener(nsIEditActionListener *listener)
{
    return NS_ERROR_NOT_IMPLEMENTED;
}

/* void addDocumentStateListener (in nsIDocumentStateListener listener); */
NS_IMETHODIMP nsEditor::AddDocumentStateListener(nsIDocumentStateListener *listener)
{
    return NS_ERROR_NOT_IMPLEMENTED;
}

/* void removeDocumentStateListener (in nsIDocumentStateListener listener); */
NS_IMETHODIMP nsEditor::RemoveDocumentStateListener(nsIDocumentStateListener *listener)
{
    return NS_ERROR_NOT_IMPLEMENTED;
}

/* void dumpContentTree (); */
NS_IMETHODIMP nsEditor::DumpContentTree()
{
    return NS_ERROR_NOT_IMPLEMENTED;
}

/* void debugDumpContent (); */
NS_IMETHODIMP nsEditor::DebugDumpContent()
{
    return NS_ERROR_NOT_IMPLEMENTED;
}

/* void debugUnitTests (out long outNumTests, out long outNumTestsFailed); */
NS_IMETHODIMP nsEditor::DebugUnitTests(PRInt32 *outNumTests NS_OUTPARAM, PRInt32 *outNumTestsFailed NS_OUTPARAM)
{
    return NS_ERROR_NOT_IMPLEMENTED;
}

/* [notxpcom] boolean isModifiableNode (in nsIDOMNode aNode); */
NS_IMETHODIMP_(PRBool) nsEditor::IsModifiableNode(nsIDOMNode *aNode)
{
    return NS_ERROR_NOT_IMPLEMENTED;
}

/* End of implementation class template. */
#endif


#endif /* __gen_nsIEditor_h__ */
