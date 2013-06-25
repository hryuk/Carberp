/*
 * DO NOT EDIT.  THIS FILE IS GENERATED FROM e:/builds/moz2_slave/mozilla-1.9.1-win32-xulrunner/build/editor/idl/nsIHTMLEditor.idl
 */

#ifndef __gen_nsIHTMLEditor_h__
#define __gen_nsIHTMLEditor_h__


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
class nsIAtom; /* forward declaration */

class nsISupportsArray; /* forward declaration */

class nsISelection; /* forward declaration */

class nsIContentFilter; /* forward declaration */

#define NS_EDITOR_ELEMENT_NOT_FOUND \
  NS_ERROR_GENERATE_SUCCESS(NS_ERROR_MODULE_EDITOR, 1)

/* starting interface:    nsIHTMLEditor */
#define NS_IHTMLEDITOR_IID_STR "afc36593-5787-4420-93d9-b2c0ccbf0cad"

#define NS_IHTMLEDITOR_IID \
  {0xafc36593, 0x5787, 0x4420, \
    { 0x93, 0xd9, 0xb2, 0xc0, 0xcc, 0xbf, 0x0c, 0xad }}

class NS_SCRIPTABLE nsIHTMLEditor : public nsISupports {
 public: 

  NS_DECLARE_STATIC_IID_ACCESSOR(NS_IHTMLEDITOR_IID)

  typedef short EAlignment;
  enum { eLeft = 0 };

  enum { eCenter = 1 };

  enum { eRight = 2 };

  enum { eJustify = 3 };

  /**
   * AddDefaultProperty() registers a default style property with the editor
   *
   * @param aProperty   the property to set by default
   * @param aAttribute  the attribute of the property, if applicable.
   *                    May be null.
   *                    Example: aProperty="font", aAttribute="color"
   * @param aValue      if aAttribute is not null, the value of the attribute.
   *                    Example: aProperty="font", aAttribute="color",
   *                             aValue="0x00FFFF"
   */
  /* void addDefaultProperty (in nsIAtom aProperty, in AString aAttribute, in AString aValue); */
  NS_SCRIPTABLE NS_IMETHOD AddDefaultProperty(nsIAtom *aProperty, const nsAString & aAttribute, const nsAString & aValue) = 0;

  /**
   * RemoveDefaultProperty() unregisters a default style property with the editor
   *
   * @param aProperty   the property to remove from defaults
   * @param aAttribute  the attribute of the property, if applicable.
   *                    May be null.
   *                    Example: aProperty="font", aAttribute="color"
   * @param aValue      if aAttribute is not null, the value of the attribute.
   *                    Example: aProperty="font", aAttribute="color",
   *                             aValue="0x00FFFF"
   */
  /* void removeDefaultProperty (in nsIAtom aProperty, in AString aAttribute, in AString aValue); */
  NS_SCRIPTABLE NS_IMETHOD RemoveDefaultProperty(nsIAtom *aProperty, const nsAString & aAttribute, const nsAString & aValue) = 0;

  /**
   * RemoveAllDefaultProperties() unregisters all default style properties with the editor
   *
   */
  /* void removeAllDefaultProperties (); */
  NS_SCRIPTABLE NS_IMETHOD RemoveAllDefaultProperties(void) = 0;

  /**
   * SetInlineProperty() sets the aggregate properties on the current selection
   *
   * @param aProperty   the property to set on the selection 
   * @param aAttribute  the attribute of the property, if applicable.
   *                    May be null.
   *                    Example: aProperty="font", aAttribute="color"
   * @param aValue      if aAttribute is not null, the value of the attribute.
   *                    May be null.
   *                    Example: aProperty="font", aAttribute="color",
   *                             aValue="0x00FFFF"
   */
  /* void setCSSInlineProperty (in nsIAtom aProperty, in AString aAttribute, in AString aValue); */
  NS_SCRIPTABLE NS_IMETHOD SetCSSInlineProperty(nsIAtom *aProperty, const nsAString & aAttribute, const nsAString & aValue) = 0;

  /* void setInlineProperty (in nsIAtom aProperty, in AString aAttribute, in AString aValue); */
  NS_SCRIPTABLE NS_IMETHOD SetInlineProperty(nsIAtom *aProperty, const nsAString & aAttribute, const nsAString & aValue) = 0;

  /**
   * getInlineProperty() gets aggregate properties of the current selection.
   * All object in the current selection are scanned and their attributes are
   * represented in a list of Property object.
   *
   * @param aProperty   the property to get on the selection 
   * @param aAttribute  the attribute of the property, if applicable.
   *                    May be null.
   *                    Example: aProperty="font", aAttribute="color"
   * @param aValue      if aAttribute is not null, the value of the attribute.
   *                    May be null.
   *                    Example: aProperty="font", aAttribute="color",
   *                             aValue="0x00FFFF"
   * @param aFirst      [OUT] PR_TRUE if the first text node in the
   *                          selection has the property
   * @param aAny        [OUT] PR_TRUE if any of the text nodes in the
   *                          selection have the property
   * @param aAll        [OUT] PR_TRUE if all of the text nodes in the
   *                          selection have the property
   */
  /* void getInlineProperty (in nsIAtom aProperty, in AString aAttribute, in AString aValue, out boolean aFirst, out boolean aAny, out boolean aAll); */
  NS_SCRIPTABLE NS_IMETHOD GetInlineProperty(nsIAtom *aProperty, const nsAString & aAttribute, const nsAString & aValue, PRBool *aFirst NS_OUTPARAM, PRBool *aAny NS_OUTPARAM, PRBool *aAll NS_OUTPARAM) = 0;

  /* AString getInlinePropertyWithAttrValue (in nsIAtom aProperty, in AString aAttribute, in AString aValue, out boolean aFirst, out boolean aAny, out boolean aAll); */
  NS_SCRIPTABLE NS_IMETHOD GetInlinePropertyWithAttrValue(nsIAtom *aProperty, const nsAString & aAttribute, const nsAString & aValue, PRBool *aFirst NS_OUTPARAM, PRBool *aAny NS_OUTPARAM, PRBool *aAll NS_OUTPARAM, nsAString & _retval NS_OUTPARAM) = 0;

  /**
   * removeAllInlineProperties() deletes all the inline properties from all 
   * text in the current selection.
   */
  /* void removeAllInlineProperties (); */
  NS_SCRIPTABLE NS_IMETHOD RemoveAllInlineProperties(void) = 0;

  /**
   * removeInlineProperty() deletes the properties from all text in the current
   * selection.  If aProperty is not set on the selection, nothing is done.
   *
   * @param aProperty   the property to remove from the selection 
   *                    All atoms are for normal HTML tags (e.g.:
   *                    nsIEditorProperty::font) except when you want to
   *                    remove just links and not named anchors.
   *                    For that, use nsIEditorProperty::href
   * @param aAttribute  the attribute of the property, if applicable.
   *                    May be null.
   *                    Example: aProperty=nsIEditorProptery::font,
   *                    aAttribute="color"
   *                    nsIEditProperty::allAttributes is special.
   *                    It indicates that all content-based text properties
   *                    are to be removed from the selection.
   */
  /* void removeInlineProperty (in nsIAtom aProperty, in AString aAttribute); */
  NS_SCRIPTABLE NS_IMETHOD RemoveInlineProperty(nsIAtom *aProperty, const nsAString & aAttribute) = 0;

  /**
   *  Increase font size for text in selection by 1 HTML unit
   *  All existing text is scanned for existing <FONT SIZE> attributes
   *  so they will be incremented instead of inserting new <FONT> tag
   */
  /* void increaseFontSize (); */
  NS_SCRIPTABLE NS_IMETHOD IncreaseFontSize(void) = 0;

  /**
   *  Decrease font size for text in selection by 1 HTML unit
   *  All existing text is scanned for existing <FONT SIZE> attributes
   *  so they will be decreased instead of inserting new <FONT> tag
   */
  /* void decreaseFontSize (); */
  NS_SCRIPTABLE NS_IMETHOD DecreaseFontSize(void) = 0;

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
   * Tests if a node is a BLOCK element according the the HTML 4.0 DTD.
   *   This does NOT consider CSS effect on display type
   *
   * @param aNode      the node to test
   */
  /* boolean nodeIsBlock (in nsIDOMNode node); */
  NS_SCRIPTABLE NS_IMETHOD NodeIsBlock(nsIDOMNode *node, PRBool *_retval NS_OUTPARAM) = 0;

  /**
   * Insert some HTML source at the current location
   *
   * @param aInputString   the string to be inserted
   */
  /* void insertHTML (in AString aInputString); */
  NS_SCRIPTABLE NS_IMETHOD InsertHTML(const nsAString & aInputString) = 0;

  /** 
    * Paste the text in the OS clipboard at the cursor position, replacing
    * the selected text (if any), but strip out any HTML styles and formatting
    */
  /* void pasteNoFormatting (in long aSelectionType); */
  NS_SCRIPTABLE NS_IMETHOD PasteNoFormatting(PRInt32 aSelectionType) = 0;

  /** 
   *  Rebuild the entire document from source HTML
   *  Needed to be able to edit HEAD and other outside-of-BODY content
   *
   *  @param aSourceString   HTML source string of the entire new document
   */
  /* void rebuildDocumentFromSource (in AString aSourceString); */
  NS_SCRIPTABLE NS_IMETHOD RebuildDocumentFromSource(const nsAString & aSourceString) = 0;

  /**
   * Insert some HTML source, interpreting
   * the string argument according to the given context.
   *
   * @param aInputString   the string to be inserted
   * @param aContextStr    Context of insertion
   * @param aInfoStr       Related info to aInputString 
   * @param aFlavor        Transferable flavor, can be ""
   * @param aSourceDoc          document where input was dragged from (may be null)
   * @param aDestinationNode    location for insertion (such as when dropped)
   * @param aDestinationOffset  used with aDestNode to determine insert location
   * @param aDeleteSelection    used with aDestNode during drag&drop 
   * @param aCollapseSelection  used with aDestNode during drag&drop
   */
  /* void insertHTMLWithContext (in AString aInputString, in AString aContextStr, in AString aInfoStr, in AString aFlavor, in nsIDOMDocument aSourceDoc, in nsIDOMNode aDestinationNode, in long aDestinationOffset, in boolean aDeleteSelection); */
  NS_SCRIPTABLE NS_IMETHOD InsertHTMLWithContext(const nsAString & aInputString, const nsAString & aContextStr, const nsAString & aInfoStr, const nsAString & aFlavor, nsIDOMDocument *aSourceDoc, nsIDOMNode *aDestinationNode, PRInt32 aDestinationOffset, PRBool aDeleteSelection) = 0;

  /** 
    * Insert an element, which may have child nodes, at the selection
    * Used primarily to insert a new element for various insert element dialogs,
    *   but it enforces the HTML 4.0 DTD "CanContain" rules, so it should
    *   be useful for other elements.
    *
    * @param aElement           The element to insert
    * @param aDeleteSelection   Delete the selection before inserting
    *     If aDeleteSelection is PR_FALSE, then the element is inserted 
    *     after the end of the selection for all element except
    *     Named Anchors, which insert before the selection
    */
  /* void insertElementAtSelection (in nsIDOMElement aElement, in boolean aDeleteSelection); */
  NS_SCRIPTABLE NS_IMETHOD InsertElementAtSelection(nsIDOMElement *aElement, PRBool aDeleteSelection) = 0;

  /** 
   *   Set the documents title.
   */
  /* void setDocumentTitle (in AString aTitle); */
  NS_SCRIPTABLE NS_IMETHOD SetDocumentTitle(const nsAString & aTitle) = 0;

  /** 
   *   Set the BaseURL for the document to the current URL
   *     but only if the page doesn't have a <base> tag
   *   This should be done after the document URL has changed,
   *     such as after saving a file
   *   This is used as base for relativizing link and image urls
   */
  /* void updateBaseURL (); */
  NS_SCRIPTABLE NS_IMETHOD UpdateBaseURL(void) = 0;

  /** 
    * Set the selection at the suppled element
    *
    * @param aElement   An element in the document
    */
  /* void selectElement (in nsIDOMElement aElement); */
  NS_SCRIPTABLE NS_IMETHOD SelectElement(nsIDOMElement *aElement) = 0;

  /** 
    * Create a collapsed selection just after aElement
    * 
    * XXX could we parameterize SelectElement(before/select/after>?
    *
    * The selection is set to parent-of-aElement with an
    *   offset 1 greater than aElement's offset
    *   but it enforces the HTML 4.0 DTD "CanContain" rules, so it should
    *   be useful for other elements.
    *
    * @param aElement  An element in the document
    */
  /* void setCaretAfterElement (in nsIDOMElement aElement); */
  NS_SCRIPTABLE NS_IMETHOD SetCaretAfterElement(nsIDOMElement *aElement) = 0;

  /**
   * SetParagraphFormat       Insert a block paragraph tag around selection
   * @param aParagraphFormat  "p", "h1" to "h6", "address", "pre", or "blockquote"
   */
  /* void setParagraphFormat (in AString aParagraphFormat); */
  NS_SCRIPTABLE NS_IMETHOD SetParagraphFormat(const nsAString & aParagraphFormat) = 0;

  /**
   * getParagraphState returns what block tag paragraph format is in
   * the selection.
   * @param aMixed     True if there is more than one format
   * @return           Name of block tag. "" is returned for none.
   */
  /* AString getParagraphState (out boolean aMixed); */
  NS_SCRIPTABLE NS_IMETHOD GetParagraphState(PRBool *aMixed NS_OUTPARAM, nsAString & _retval NS_OUTPARAM) = 0;

  /** 
   * getFontFaceState returns what font face is in the selection.
   * @param aMixed    True if there is more than one font face
   * @return          Name of face.  Note: "tt" is returned for
   *                  tt tag.  "" is returned for none.
   */
  /* AString getFontFaceState (out boolean aMixed); */
  NS_SCRIPTABLE NS_IMETHOD GetFontFaceState(PRBool *aMixed NS_OUTPARAM, nsAString & _retval NS_OUTPARAM) = 0;

  /** 
   * getFontColorState returns what font face is in the selection.
   * @param aMixed     True if there is more than one font color
   * @return           Color string. "" is returned for none.
   */
  /* AString getFontColorState (out boolean aMixed); */
  NS_SCRIPTABLE NS_IMETHOD GetFontColorState(PRBool *aMixed NS_OUTPARAM, nsAString & _retval NS_OUTPARAM) = 0;

  /** 
   * getFontColorState returns what font face is in the selection.
   * @param aMixed     True if there is more than one font color
   * @return           Color string. "" is returned for none.
   */
  /* AString getBackgroundColorState (out boolean aMixed); */
  NS_SCRIPTABLE NS_IMETHOD GetBackgroundColorState(PRBool *aMixed NS_OUTPARAM, nsAString & _retval NS_OUTPARAM) = 0;

  /** 
   * getHighlightColorState returns what the highlight color of the selection.
   * @param aMixed     True if there is more than one font color
   * @return           Color string. "" is returned for none.
   */
  /* AString getHighlightColorState (out boolean aMixed); */
  NS_SCRIPTABLE NS_IMETHOD GetHighlightColorState(PRBool *aMixed NS_OUTPARAM, nsAString & _retval NS_OUTPARAM) = 0;

  /** 
   * getListState returns what list type is in the selection.
   * @param aMixed    True if there is more than one type of list, or
   *                  if there is some list and non-list
   * @param aOL       The company that employs me.  No, really, it's 
   *                  true if an "ol" list is selected.
   * @param aUL       true if an "ul" list is selected.
   * @param aDL       true if a "dl" list is selected.
   */
  /* void getListState (out boolean aMixed, out boolean aOL, out boolean aUL, out boolean aDL); */
  NS_SCRIPTABLE NS_IMETHOD GetListState(PRBool *aMixed NS_OUTPARAM, PRBool *aOL NS_OUTPARAM, PRBool *aUL NS_OUTPARAM, PRBool *aDL NS_OUTPARAM) = 0;

  /** 
   * getListItemState returns what list item type is in the selection.
   * @param aMixed    True if there is more than one type of list item, or
   *                  if there is some list and non-list
   * @param aLI       true if "li" list items are selected.
   * @param aDT       true if "dt" list items are selected.
   * @param aDD       true if "dd" list items are selected.
   */
  /* void getListItemState (out boolean aMixed, out boolean aLI, out boolean aDT, out boolean aDD); */
  NS_SCRIPTABLE NS_IMETHOD GetListItemState(PRBool *aMixed NS_OUTPARAM, PRBool *aLI NS_OUTPARAM, PRBool *aDT NS_OUTPARAM, PRBool *aDD NS_OUTPARAM) = 0;

  /** 
   * getAlignment     returns what alignment is in the selection.
   * @param aMixed    True if there is more than one type of list item, or
   *                  if there is some list and non-list
   * @param aAlign    enum value for first encountered alignment
   *                  (left/center/right)
   */
  /* void getAlignment (out boolean aMixed, out short aAlign); */
  NS_SCRIPTABLE NS_IMETHOD GetAlignment(PRBool *aMixed NS_OUTPARAM, PRInt16 *aAlign NS_OUTPARAM) = 0;

  /**
   * Document me!
   * 
   */
  /* void getIndentState (out boolean aCanIndent, out boolean aCanOutdent); */
  NS_SCRIPTABLE NS_IMETHOD GetIndentState(PRBool *aCanIndent NS_OUTPARAM, PRBool *aCanOutdent NS_OUTPARAM) = 0;

  /**
   * Document me!
   * 
   */
  /* void makeOrChangeList (in AString aListType, in boolean entireList, in AString aBulletType); */
  NS_SCRIPTABLE NS_IMETHOD MakeOrChangeList(const nsAString & aListType, PRBool entireList, const nsAString & aBulletType) = 0;

  /**
   * Document me!
   * 
   */
  /* void removeList (in AString aListType); */
  NS_SCRIPTABLE NS_IMETHOD RemoveList(const nsAString & aListType) = 0;

  /**
   * Document me!
   * 
   */
  /* void indent (in AString aIndent); */
  NS_SCRIPTABLE NS_IMETHOD Indent(const nsAString & aIndent) = 0;

  /**
   * Document me!
   * 
   */
  /* void align (in AString aAlign); */
  NS_SCRIPTABLE NS_IMETHOD Align(const nsAString & aAlign) = 0;

  /** 
   * Return the input node or a parent matching the given aTagName,
   *   starting the search at the supplied node.
   * An example of use is for testing if a node is in a table cell
   *   given a selection anchor node.
   *
   * @param aTagName  The HTML tagname
   *  Special input values:
   *    Use "href" to get a link node 
   *      (an "A" tag with the "href" attribute set)
   *    Use "anchor" or "namedanchor" to get a named anchor node
   *      (an "A" tag with the "name" attribute set)
   *    Use "list" to get an OL, UL, or DL list node
   *    Use "td" to get either a TD or TH cell node
   *
   * @param aNode    The node in the document to start the search.
   *     If it is null, the anchor node of the current selection is used.
   * @return         NS_EDITOR_ELEMENT_NOT_FOUND if an element is not found
   *                 (passes NS_SUCCEEDED macro)
   */
  /* nsIDOMElement getElementOrParentByTagName (in AString aTagName, in nsIDOMNode aNode); */
  NS_SCRIPTABLE NS_IMETHOD GetElementOrParentByTagName(const nsAString & aTagName, nsIDOMNode *aNode, nsIDOMElement **_retval NS_OUTPARAM) = 0;

  /** 
   * Return an element only if it is the only node selected,
   *    such as an image, horizontal rule, etc.
   * The exception is a link, which is more like a text attribute:
   *    The Anchor tag is returned if the selection is within the textnode(s)
   *    that are children of the "A" node.
   *    This could be a collapsed selection, i.e., a caret
   *    within the link text.
   *
   * @param aTagName  The HTML tagname or and empty string 
   *       to get any element (but only if it is the only element selected)
   *    Special input values for Links and Named anchors:
   *    Use "href" to get a link node
   *      (an "A" tag with the "href" attribute set)
   *    Use "anchor" or "namedanchor" to get a named anchor node
   *      (an "A" tag with the "name" attribute set)
   * @return          NS_EDITOR_ELEMENT_NOT_FOUND if an element is not found
   *                  (passes NS_SUCCEEDED macro)
   */
  /* nsIDOMElement getSelectedElement (in AString aTagName); */
  NS_SCRIPTABLE NS_IMETHOD GetSelectedElement(const nsAString & aTagName, nsIDOMElement **_retval NS_OUTPARAM) = 0;

  /** 
   * Output the contents of the <HEAD> section as text/HTML format
   */
  /* AString getHeadContentsAsHTML (); */
  NS_SCRIPTABLE NS_IMETHOD GetHeadContentsAsHTML(nsAString & _retval NS_OUTPARAM) = 0;

  /** 
   * Replace all children of <HEAD> with string of HTML source
   */
  /* void replaceHeadContentsWithHTML (in AString aSourceToInsert); */
  NS_SCRIPTABLE NS_IMETHOD ReplaceHeadContentsWithHTML(const nsAString & aSourceToInsert) = 0;

  /** 
   * Return a new element with default attribute values
   * 
   * This does not rely on the selection, and is not sensitive to context.
   * 
   * Used primarily to supply new element for various insert element dialogs
   *  (Image, Link, NamedAnchor, Table, and HorizontalRule 
   *   are the only returned elements as of 7/25/99)
   *
   * @param aTagName  The HTML tagname
   *    Special input values for Links and Named anchors:
   *    Use "href" to get a link node
   *      (an "A" tag with the "href" attribute set)
   *    Use "anchor" or "namedanchor" to get a named anchor node
   *      (an "A" tag with the "name" attribute set)
   * @return          The new element created.
   */
  /* nsIDOMElement createElementWithDefaults (in AString aTagName); */
  NS_SCRIPTABLE NS_IMETHOD CreateElementWithDefaults(const nsAString & aTagName, nsIDOMElement **_retval NS_OUTPARAM) = 0;

  /** 
   * Insert an link element as the parent of the current selection
   *
   * @param aElement   An "A" element with a non-empty "href" attribute
   */
  /* void insertLinkAroundSelection (in nsIDOMElement aAnchorElement); */
  NS_SCRIPTABLE NS_IMETHOD InsertLinkAroundSelection(nsIDOMElement *aAnchorElement) = 0;

  /** 
   * Set the value of the "bgcolor" attribute on the document's <body> element
   *
   * @param aColor  The HTML color string, such as "#ffccff" or "yellow"
   */
  /* void setBackgroundColor (in AString aColor); */
  NS_SCRIPTABLE NS_IMETHOD SetBackgroundColor(const nsAString & aColor) = 0;

  /** 
   * Set an attribute on the document's <body> element
   *    such as text, link, background colors
   *
   * 8/31/00 THIS ISN'T BEING USED? SHOULD WE DROP IT?
   *
   * @param aAttr   The attribute to be set
   * @param aValue  The value of the attribute
   */
  /* void setBodyAttribute (in AString aAttr, in AString aValue); */
  NS_SCRIPTABLE NS_IMETHOD SetBodyAttribute(const nsAString & aAttr, const nsAString & aValue) = 0;

  /** 
   * XXX Used to suppress spurious drag/drop events to workaround bug 50703
   * Don't use this method! It will go away after first release!
   */
  /* void ignoreSpuriousDragEvent (in boolean aIgnoreSpuriousDragEvent); */
  NS_SCRIPTABLE NS_IMETHOD IgnoreSpuriousDragEvent(PRBool aIgnoreSpuriousDragEvent) = 0;

  /**
   * Find all the nodes in the document which contain references
   * to outside URIs (e.g. a href, img src, script src, etc.)
   * The objects in the array will be type nsIURIRefObject.
   *
   * @return aNodeList    the linked nodes found
   */
  /* nsISupportsArray getLinkedObjects (); */
  NS_SCRIPTABLE NS_IMETHOD GetLinkedObjects(nsISupportsArray **_retval NS_OUTPARAM) = 0;

  /** 
   * A boolean which is true is the HTMLEditor has been instantiated
   * with CSS knowledge and if the CSS pref is currently checked
   *
   * @return    true if CSS handled and enabled
   */
  /* attribute boolean isCSSEnabled; */
  NS_SCRIPTABLE NS_IMETHOD GetIsCSSEnabled(PRBool *aIsCSSEnabled) = 0;
  NS_SCRIPTABLE NS_IMETHOD SetIsCSSEnabled(PRBool aIsCSSEnabled) = 0;

  /**
   * Add listener for insertion override
   * @param inFilter  function which callers want called during insertion
   */
  /* void addInsertionListener (in nsIContentFilter inFilter); */
  NS_SCRIPTABLE NS_IMETHOD AddInsertionListener(nsIContentFilter *inFilter) = 0;

  /**
   * Remove listener for insertion override
   * @param inFilter  function which callers do not want called during insertion
   */
  /* void removeInsertionListener (in nsIContentFilter inFilter); */
  NS_SCRIPTABLE NS_IMETHOD RemoveInsertionListener(nsIContentFilter *inFilter) = 0;

  /**
   * Returns an anonymous nsDOMElement of type aTag,
   * child of aParentNode. If aIsCreatedHidden is true, the class
   * "hidden" is added to the created element. If aAnonClass is not
   * the empty string, it becomes the value of the attribute "_moz_anonclass"
   * @return a DOM Element
   * @param aTag             [IN] a string representing the desired type of
   *                              the element to create
   * @param aParentNode      [IN] the parent node of the created anonymous
   *                              element
   * @param aAnonClass       [IN] contents of the _moz_anonclass attribute
   * @param aIsCreatedHidden [IN] a boolean specifying if the class "hidden"
   *                              is to be added to the created anonymous
   *                              element
   */
  /* nsIDOMElement createAnonymousElement (in AString aTag, in nsIDOMNode aParentNode, in AString aAnonClass, in boolean aIsCreatedHidden); */
  NS_SCRIPTABLE NS_IMETHOD CreateAnonymousElement(const nsAString & aTag, nsIDOMNode *aParentNode, const nsAString & aAnonClass, PRBool aIsCreatedHidden, nsIDOMElement **_retval NS_OUTPARAM) = 0;

  /**
   * returns the deepest container of the selection
   * @return a DOM Element
   */
  /* nsIDOMElement getSelectionContainer (); */
  NS_SCRIPTABLE NS_IMETHOD GetSelectionContainer(nsIDOMElement **_retval NS_OUTPARAM) = 0;

  /**
   * Checks if the anonymous nodes created by the HTML editor have to be
   * refreshed or hidden depending on a possible new state of the selection
   * @param aSelection [IN] a selection
   */
  /* void checkSelectionStateForAnonymousButtons (in nsISelection aSelection); */
  NS_SCRIPTABLE NS_IMETHOD CheckSelectionStateForAnonymousButtons(nsISelection *aSelection) = 0;

  /* boolean isAnonymousElement (in nsIDOMElement aElement); */
  NS_SCRIPTABLE NS_IMETHOD IsAnonymousElement(nsIDOMElement *aElement, PRBool *_retval NS_OUTPARAM) = 0;

  /**
   * A boolean indicating if a return key pressed in a paragraph creates
   * another paragraph or just inserts a <br> at the caret
   *
   * @return    true if CR in a paragraph creates a new paragraph
   */
  /* attribute boolean returnInParagraphCreatesNewParagraph; */
  NS_SCRIPTABLE NS_IMETHOD GetReturnInParagraphCreatesNewParagraph(PRBool *aReturnInParagraphCreatesNewParagraph) = 0;
  NS_SCRIPTABLE NS_IMETHOD SetReturnInParagraphCreatesNewParagraph(PRBool aReturnInParagraphCreatesNewParagraph) = 0;

};

  NS_DEFINE_STATIC_IID_ACCESSOR(nsIHTMLEditor, NS_IHTMLEDITOR_IID)

/* Use this macro when declaring classes that implement this interface. */
#define NS_DECL_NSIHTMLEDITOR \
  NS_SCRIPTABLE NS_IMETHOD AddDefaultProperty(nsIAtom *aProperty, const nsAString & aAttribute, const nsAString & aValue); \
  NS_SCRIPTABLE NS_IMETHOD RemoveDefaultProperty(nsIAtom *aProperty, const nsAString & aAttribute, const nsAString & aValue); \
  NS_SCRIPTABLE NS_IMETHOD RemoveAllDefaultProperties(void); \
  NS_SCRIPTABLE NS_IMETHOD SetCSSInlineProperty(nsIAtom *aProperty, const nsAString & aAttribute, const nsAString & aValue); \
  NS_SCRIPTABLE NS_IMETHOD SetInlineProperty(nsIAtom *aProperty, const nsAString & aAttribute, const nsAString & aValue); \
  NS_SCRIPTABLE NS_IMETHOD GetInlineProperty(nsIAtom *aProperty, const nsAString & aAttribute, const nsAString & aValue, PRBool *aFirst NS_OUTPARAM, PRBool *aAny NS_OUTPARAM, PRBool *aAll NS_OUTPARAM); \
  NS_SCRIPTABLE NS_IMETHOD GetInlinePropertyWithAttrValue(nsIAtom *aProperty, const nsAString & aAttribute, const nsAString & aValue, PRBool *aFirst NS_OUTPARAM, PRBool *aAny NS_OUTPARAM, PRBool *aAll NS_OUTPARAM, nsAString & _retval NS_OUTPARAM); \
  NS_SCRIPTABLE NS_IMETHOD RemoveAllInlineProperties(void); \
  NS_SCRIPTABLE NS_IMETHOD RemoveInlineProperty(nsIAtom *aProperty, const nsAString & aAttribute); \
  NS_SCRIPTABLE NS_IMETHOD IncreaseFontSize(void); \
  NS_SCRIPTABLE NS_IMETHOD DecreaseFontSize(void); \
  NS_SCRIPTABLE NS_IMETHOD CanDrag(nsIDOMEvent *aEvent, PRBool *_retval NS_OUTPARAM); \
  NS_SCRIPTABLE NS_IMETHOD DoDrag(nsIDOMEvent *aEvent); \
  NS_SCRIPTABLE NS_IMETHOD InsertFromDrop(nsIDOMEvent *aEvent); \
  NS_SCRIPTABLE NS_IMETHOD NodeIsBlock(nsIDOMNode *node, PRBool *_retval NS_OUTPARAM); \
  NS_SCRIPTABLE NS_IMETHOD InsertHTML(const nsAString & aInputString); \
  NS_SCRIPTABLE NS_IMETHOD PasteNoFormatting(PRInt32 aSelectionType); \
  NS_SCRIPTABLE NS_IMETHOD RebuildDocumentFromSource(const nsAString & aSourceString); \
  NS_SCRIPTABLE NS_IMETHOD InsertHTMLWithContext(const nsAString & aInputString, const nsAString & aContextStr, const nsAString & aInfoStr, const nsAString & aFlavor, nsIDOMDocument *aSourceDoc, nsIDOMNode *aDestinationNode, PRInt32 aDestinationOffset, PRBool aDeleteSelection); \
  NS_SCRIPTABLE NS_IMETHOD InsertElementAtSelection(nsIDOMElement *aElement, PRBool aDeleteSelection); \
  NS_SCRIPTABLE NS_IMETHOD SetDocumentTitle(const nsAString & aTitle); \
  NS_SCRIPTABLE NS_IMETHOD UpdateBaseURL(void); \
  NS_SCRIPTABLE NS_IMETHOD SelectElement(nsIDOMElement *aElement); \
  NS_SCRIPTABLE NS_IMETHOD SetCaretAfterElement(nsIDOMElement *aElement); \
  NS_SCRIPTABLE NS_IMETHOD SetParagraphFormat(const nsAString & aParagraphFormat); \
  NS_SCRIPTABLE NS_IMETHOD GetParagraphState(PRBool *aMixed NS_OUTPARAM, nsAString & _retval NS_OUTPARAM); \
  NS_SCRIPTABLE NS_IMETHOD GetFontFaceState(PRBool *aMixed NS_OUTPARAM, nsAString & _retval NS_OUTPARAM); \
  NS_SCRIPTABLE NS_IMETHOD GetFontColorState(PRBool *aMixed NS_OUTPARAM, nsAString & _retval NS_OUTPARAM); \
  NS_SCRIPTABLE NS_IMETHOD GetBackgroundColorState(PRBool *aMixed NS_OUTPARAM, nsAString & _retval NS_OUTPARAM); \
  NS_SCRIPTABLE NS_IMETHOD GetHighlightColorState(PRBool *aMixed NS_OUTPARAM, nsAString & _retval NS_OUTPARAM); \
  NS_SCRIPTABLE NS_IMETHOD GetListState(PRBool *aMixed NS_OUTPARAM, PRBool *aOL NS_OUTPARAM, PRBool *aUL NS_OUTPARAM, PRBool *aDL NS_OUTPARAM); \
  NS_SCRIPTABLE NS_IMETHOD GetListItemState(PRBool *aMixed NS_OUTPARAM, PRBool *aLI NS_OUTPARAM, PRBool *aDT NS_OUTPARAM, PRBool *aDD NS_OUTPARAM); \
  NS_SCRIPTABLE NS_IMETHOD GetAlignment(PRBool *aMixed NS_OUTPARAM, PRInt16 *aAlign NS_OUTPARAM); \
  NS_SCRIPTABLE NS_IMETHOD GetIndentState(PRBool *aCanIndent NS_OUTPARAM, PRBool *aCanOutdent NS_OUTPARAM); \
  NS_SCRIPTABLE NS_IMETHOD MakeOrChangeList(const nsAString & aListType, PRBool entireList, const nsAString & aBulletType); \
  NS_SCRIPTABLE NS_IMETHOD RemoveList(const nsAString & aListType); \
  NS_SCRIPTABLE NS_IMETHOD Indent(const nsAString & aIndent); \
  NS_SCRIPTABLE NS_IMETHOD Align(const nsAString & aAlign); \
  NS_SCRIPTABLE NS_IMETHOD GetElementOrParentByTagName(const nsAString & aTagName, nsIDOMNode *aNode, nsIDOMElement **_retval NS_OUTPARAM); \
  NS_SCRIPTABLE NS_IMETHOD GetSelectedElement(const nsAString & aTagName, nsIDOMElement **_retval NS_OUTPARAM); \
  NS_SCRIPTABLE NS_IMETHOD GetHeadContentsAsHTML(nsAString & _retval NS_OUTPARAM); \
  NS_SCRIPTABLE NS_IMETHOD ReplaceHeadContentsWithHTML(const nsAString & aSourceToInsert); \
  NS_SCRIPTABLE NS_IMETHOD CreateElementWithDefaults(const nsAString & aTagName, nsIDOMElement **_retval NS_OUTPARAM); \
  NS_SCRIPTABLE NS_IMETHOD InsertLinkAroundSelection(nsIDOMElement *aAnchorElement); \
  NS_SCRIPTABLE NS_IMETHOD SetBackgroundColor(const nsAString & aColor); \
  NS_SCRIPTABLE NS_IMETHOD SetBodyAttribute(const nsAString & aAttr, const nsAString & aValue); \
  NS_SCRIPTABLE NS_IMETHOD IgnoreSpuriousDragEvent(PRBool aIgnoreSpuriousDragEvent); \
  NS_SCRIPTABLE NS_IMETHOD GetLinkedObjects(nsISupportsArray **_retval NS_OUTPARAM); \
  NS_SCRIPTABLE NS_IMETHOD GetIsCSSEnabled(PRBool *aIsCSSEnabled); \
  NS_SCRIPTABLE NS_IMETHOD SetIsCSSEnabled(PRBool aIsCSSEnabled); \
  NS_SCRIPTABLE NS_IMETHOD AddInsertionListener(nsIContentFilter *inFilter); \
  NS_SCRIPTABLE NS_IMETHOD RemoveInsertionListener(nsIContentFilter *inFilter); \
  NS_SCRIPTABLE NS_IMETHOD CreateAnonymousElement(const nsAString & aTag, nsIDOMNode *aParentNode, const nsAString & aAnonClass, PRBool aIsCreatedHidden, nsIDOMElement **_retval NS_OUTPARAM); \
  NS_SCRIPTABLE NS_IMETHOD GetSelectionContainer(nsIDOMElement **_retval NS_OUTPARAM); \
  NS_SCRIPTABLE NS_IMETHOD CheckSelectionStateForAnonymousButtons(nsISelection *aSelection); \
  NS_SCRIPTABLE NS_IMETHOD IsAnonymousElement(nsIDOMElement *aElement, PRBool *_retval NS_OUTPARAM); \
  NS_SCRIPTABLE NS_IMETHOD GetReturnInParagraphCreatesNewParagraph(PRBool *aReturnInParagraphCreatesNewParagraph); \
  NS_SCRIPTABLE NS_IMETHOD SetReturnInParagraphCreatesNewParagraph(PRBool aReturnInParagraphCreatesNewParagraph); 

/* Use this macro to declare functions that forward the behavior of this interface to another object. */
#define NS_FORWARD_NSIHTMLEDITOR(_to) \
  NS_SCRIPTABLE NS_IMETHOD AddDefaultProperty(nsIAtom *aProperty, const nsAString & aAttribute, const nsAString & aValue) { return _to AddDefaultProperty(aProperty, aAttribute, aValue); } \
  NS_SCRIPTABLE NS_IMETHOD RemoveDefaultProperty(nsIAtom *aProperty, const nsAString & aAttribute, const nsAString & aValue) { return _to RemoveDefaultProperty(aProperty, aAttribute, aValue); } \
  NS_SCRIPTABLE NS_IMETHOD RemoveAllDefaultProperties(void) { return _to RemoveAllDefaultProperties(); } \
  NS_SCRIPTABLE NS_IMETHOD SetCSSInlineProperty(nsIAtom *aProperty, const nsAString & aAttribute, const nsAString & aValue) { return _to SetCSSInlineProperty(aProperty, aAttribute, aValue); } \
  NS_SCRIPTABLE NS_IMETHOD SetInlineProperty(nsIAtom *aProperty, const nsAString & aAttribute, const nsAString & aValue) { return _to SetInlineProperty(aProperty, aAttribute, aValue); } \
  NS_SCRIPTABLE NS_IMETHOD GetInlineProperty(nsIAtom *aProperty, const nsAString & aAttribute, const nsAString & aValue, PRBool *aFirst NS_OUTPARAM, PRBool *aAny NS_OUTPARAM, PRBool *aAll NS_OUTPARAM) { return _to GetInlineProperty(aProperty, aAttribute, aValue, aFirst, aAny, aAll); } \
  NS_SCRIPTABLE NS_IMETHOD GetInlinePropertyWithAttrValue(nsIAtom *aProperty, const nsAString & aAttribute, const nsAString & aValue, PRBool *aFirst NS_OUTPARAM, PRBool *aAny NS_OUTPARAM, PRBool *aAll NS_OUTPARAM, nsAString & _retval NS_OUTPARAM) { return _to GetInlinePropertyWithAttrValue(aProperty, aAttribute, aValue, aFirst, aAny, aAll, _retval); } \
  NS_SCRIPTABLE NS_IMETHOD RemoveAllInlineProperties(void) { return _to RemoveAllInlineProperties(); } \
  NS_SCRIPTABLE NS_IMETHOD RemoveInlineProperty(nsIAtom *aProperty, const nsAString & aAttribute) { return _to RemoveInlineProperty(aProperty, aAttribute); } \
  NS_SCRIPTABLE NS_IMETHOD IncreaseFontSize(void) { return _to IncreaseFontSize(); } \
  NS_SCRIPTABLE NS_IMETHOD DecreaseFontSize(void) { return _to DecreaseFontSize(); } \
  NS_SCRIPTABLE NS_IMETHOD CanDrag(nsIDOMEvent *aEvent, PRBool *_retval NS_OUTPARAM) { return _to CanDrag(aEvent, _retval); } \
  NS_SCRIPTABLE NS_IMETHOD DoDrag(nsIDOMEvent *aEvent) { return _to DoDrag(aEvent); } \
  NS_SCRIPTABLE NS_IMETHOD InsertFromDrop(nsIDOMEvent *aEvent) { return _to InsertFromDrop(aEvent); } \
  NS_SCRIPTABLE NS_IMETHOD NodeIsBlock(nsIDOMNode *node, PRBool *_retval NS_OUTPARAM) { return _to NodeIsBlock(node, _retval); } \
  NS_SCRIPTABLE NS_IMETHOD InsertHTML(const nsAString & aInputString) { return _to InsertHTML(aInputString); } \
  NS_SCRIPTABLE NS_IMETHOD PasteNoFormatting(PRInt32 aSelectionType) { return _to PasteNoFormatting(aSelectionType); } \
  NS_SCRIPTABLE NS_IMETHOD RebuildDocumentFromSource(const nsAString & aSourceString) { return _to RebuildDocumentFromSource(aSourceString); } \
  NS_SCRIPTABLE NS_IMETHOD InsertHTMLWithContext(const nsAString & aInputString, const nsAString & aContextStr, const nsAString & aInfoStr, const nsAString & aFlavor, nsIDOMDocument *aSourceDoc, nsIDOMNode *aDestinationNode, PRInt32 aDestinationOffset, PRBool aDeleteSelection) { return _to InsertHTMLWithContext(aInputString, aContextStr, aInfoStr, aFlavor, aSourceDoc, aDestinationNode, aDestinationOffset, aDeleteSelection); } \
  NS_SCRIPTABLE NS_IMETHOD InsertElementAtSelection(nsIDOMElement *aElement, PRBool aDeleteSelection) { return _to InsertElementAtSelection(aElement, aDeleteSelection); } \
  NS_SCRIPTABLE NS_IMETHOD SetDocumentTitle(const nsAString & aTitle) { return _to SetDocumentTitle(aTitle); } \
  NS_SCRIPTABLE NS_IMETHOD UpdateBaseURL(void) { return _to UpdateBaseURL(); } \
  NS_SCRIPTABLE NS_IMETHOD SelectElement(nsIDOMElement *aElement) { return _to SelectElement(aElement); } \
  NS_SCRIPTABLE NS_IMETHOD SetCaretAfterElement(nsIDOMElement *aElement) { return _to SetCaretAfterElement(aElement); } \
  NS_SCRIPTABLE NS_IMETHOD SetParagraphFormat(const nsAString & aParagraphFormat) { return _to SetParagraphFormat(aParagraphFormat); } \
  NS_SCRIPTABLE NS_IMETHOD GetParagraphState(PRBool *aMixed NS_OUTPARAM, nsAString & _retval NS_OUTPARAM) { return _to GetParagraphState(aMixed, _retval); } \
  NS_SCRIPTABLE NS_IMETHOD GetFontFaceState(PRBool *aMixed NS_OUTPARAM, nsAString & _retval NS_OUTPARAM) { return _to GetFontFaceState(aMixed, _retval); } \
  NS_SCRIPTABLE NS_IMETHOD GetFontColorState(PRBool *aMixed NS_OUTPARAM, nsAString & _retval NS_OUTPARAM) { return _to GetFontColorState(aMixed, _retval); } \
  NS_SCRIPTABLE NS_IMETHOD GetBackgroundColorState(PRBool *aMixed NS_OUTPARAM, nsAString & _retval NS_OUTPARAM) { return _to GetBackgroundColorState(aMixed, _retval); } \
  NS_SCRIPTABLE NS_IMETHOD GetHighlightColorState(PRBool *aMixed NS_OUTPARAM, nsAString & _retval NS_OUTPARAM) { return _to GetHighlightColorState(aMixed, _retval); } \
  NS_SCRIPTABLE NS_IMETHOD GetListState(PRBool *aMixed NS_OUTPARAM, PRBool *aOL NS_OUTPARAM, PRBool *aUL NS_OUTPARAM, PRBool *aDL NS_OUTPARAM) { return _to GetListState(aMixed, aOL, aUL, aDL); } \
  NS_SCRIPTABLE NS_IMETHOD GetListItemState(PRBool *aMixed NS_OUTPARAM, PRBool *aLI NS_OUTPARAM, PRBool *aDT NS_OUTPARAM, PRBool *aDD NS_OUTPARAM) { return _to GetListItemState(aMixed, aLI, aDT, aDD); } \
  NS_SCRIPTABLE NS_IMETHOD GetAlignment(PRBool *aMixed NS_OUTPARAM, PRInt16 *aAlign NS_OUTPARAM) { return _to GetAlignment(aMixed, aAlign); } \
  NS_SCRIPTABLE NS_IMETHOD GetIndentState(PRBool *aCanIndent NS_OUTPARAM, PRBool *aCanOutdent NS_OUTPARAM) { return _to GetIndentState(aCanIndent, aCanOutdent); } \
  NS_SCRIPTABLE NS_IMETHOD MakeOrChangeList(const nsAString & aListType, PRBool entireList, const nsAString & aBulletType) { return _to MakeOrChangeList(aListType, entireList, aBulletType); } \
  NS_SCRIPTABLE NS_IMETHOD RemoveList(const nsAString & aListType) { return _to RemoveList(aListType); } \
  NS_SCRIPTABLE NS_IMETHOD Indent(const nsAString & aIndent) { return _to Indent(aIndent); } \
  NS_SCRIPTABLE NS_IMETHOD Align(const nsAString & aAlign) { return _to Align(aAlign); } \
  NS_SCRIPTABLE NS_IMETHOD GetElementOrParentByTagName(const nsAString & aTagName, nsIDOMNode *aNode, nsIDOMElement **_retval NS_OUTPARAM) { return _to GetElementOrParentByTagName(aTagName, aNode, _retval); } \
  NS_SCRIPTABLE NS_IMETHOD GetSelectedElement(const nsAString & aTagName, nsIDOMElement **_retval NS_OUTPARAM) { return _to GetSelectedElement(aTagName, _retval); } \
  NS_SCRIPTABLE NS_IMETHOD GetHeadContentsAsHTML(nsAString & _retval NS_OUTPARAM) { return _to GetHeadContentsAsHTML(_retval); } \
  NS_SCRIPTABLE NS_IMETHOD ReplaceHeadContentsWithHTML(const nsAString & aSourceToInsert) { return _to ReplaceHeadContentsWithHTML(aSourceToInsert); } \
  NS_SCRIPTABLE NS_IMETHOD CreateElementWithDefaults(const nsAString & aTagName, nsIDOMElement **_retval NS_OUTPARAM) { return _to CreateElementWithDefaults(aTagName, _retval); } \
  NS_SCRIPTABLE NS_IMETHOD InsertLinkAroundSelection(nsIDOMElement *aAnchorElement) { return _to InsertLinkAroundSelection(aAnchorElement); } \
  NS_SCRIPTABLE NS_IMETHOD SetBackgroundColor(const nsAString & aColor) { return _to SetBackgroundColor(aColor); } \
  NS_SCRIPTABLE NS_IMETHOD SetBodyAttribute(const nsAString & aAttr, const nsAString & aValue) { return _to SetBodyAttribute(aAttr, aValue); } \
  NS_SCRIPTABLE NS_IMETHOD IgnoreSpuriousDragEvent(PRBool aIgnoreSpuriousDragEvent) { return _to IgnoreSpuriousDragEvent(aIgnoreSpuriousDragEvent); } \
  NS_SCRIPTABLE NS_IMETHOD GetLinkedObjects(nsISupportsArray **_retval NS_OUTPARAM) { return _to GetLinkedObjects(_retval); } \
  NS_SCRIPTABLE NS_IMETHOD GetIsCSSEnabled(PRBool *aIsCSSEnabled) { return _to GetIsCSSEnabled(aIsCSSEnabled); } \
  NS_SCRIPTABLE NS_IMETHOD SetIsCSSEnabled(PRBool aIsCSSEnabled) { return _to SetIsCSSEnabled(aIsCSSEnabled); } \
  NS_SCRIPTABLE NS_IMETHOD AddInsertionListener(nsIContentFilter *inFilter) { return _to AddInsertionListener(inFilter); } \
  NS_SCRIPTABLE NS_IMETHOD RemoveInsertionListener(nsIContentFilter *inFilter) { return _to RemoveInsertionListener(inFilter); } \
  NS_SCRIPTABLE NS_IMETHOD CreateAnonymousElement(const nsAString & aTag, nsIDOMNode *aParentNode, const nsAString & aAnonClass, PRBool aIsCreatedHidden, nsIDOMElement **_retval NS_OUTPARAM) { return _to CreateAnonymousElement(aTag, aParentNode, aAnonClass, aIsCreatedHidden, _retval); } \
  NS_SCRIPTABLE NS_IMETHOD GetSelectionContainer(nsIDOMElement **_retval NS_OUTPARAM) { return _to GetSelectionContainer(_retval); } \
  NS_SCRIPTABLE NS_IMETHOD CheckSelectionStateForAnonymousButtons(nsISelection *aSelection) { return _to CheckSelectionStateForAnonymousButtons(aSelection); } \
  NS_SCRIPTABLE NS_IMETHOD IsAnonymousElement(nsIDOMElement *aElement, PRBool *_retval NS_OUTPARAM) { return _to IsAnonymousElement(aElement, _retval); } \
  NS_SCRIPTABLE NS_IMETHOD GetReturnInParagraphCreatesNewParagraph(PRBool *aReturnInParagraphCreatesNewParagraph) { return _to GetReturnInParagraphCreatesNewParagraph(aReturnInParagraphCreatesNewParagraph); } \
  NS_SCRIPTABLE NS_IMETHOD SetReturnInParagraphCreatesNewParagraph(PRBool aReturnInParagraphCreatesNewParagraph) { return _to SetReturnInParagraphCreatesNewParagraph(aReturnInParagraphCreatesNewParagraph); } 

/* Use this macro to declare functions that forward the behavior of this interface to another object in a safe way. */
#define NS_FORWARD_SAFE_NSIHTMLEDITOR(_to) \
  NS_SCRIPTABLE NS_IMETHOD AddDefaultProperty(nsIAtom *aProperty, const nsAString & aAttribute, const nsAString & aValue) { return !_to ? NS_ERROR_NULL_POINTER : _to->AddDefaultProperty(aProperty, aAttribute, aValue); } \
  NS_SCRIPTABLE NS_IMETHOD RemoveDefaultProperty(nsIAtom *aProperty, const nsAString & aAttribute, const nsAString & aValue) { return !_to ? NS_ERROR_NULL_POINTER : _to->RemoveDefaultProperty(aProperty, aAttribute, aValue); } \
  NS_SCRIPTABLE NS_IMETHOD RemoveAllDefaultProperties(void) { return !_to ? NS_ERROR_NULL_POINTER : _to->RemoveAllDefaultProperties(); } \
  NS_SCRIPTABLE NS_IMETHOD SetCSSInlineProperty(nsIAtom *aProperty, const nsAString & aAttribute, const nsAString & aValue) { return !_to ? NS_ERROR_NULL_POINTER : _to->SetCSSInlineProperty(aProperty, aAttribute, aValue); } \
  NS_SCRIPTABLE NS_IMETHOD SetInlineProperty(nsIAtom *aProperty, const nsAString & aAttribute, const nsAString & aValue) { return !_to ? NS_ERROR_NULL_POINTER : _to->SetInlineProperty(aProperty, aAttribute, aValue); } \
  NS_SCRIPTABLE NS_IMETHOD GetInlineProperty(nsIAtom *aProperty, const nsAString & aAttribute, const nsAString & aValue, PRBool *aFirst NS_OUTPARAM, PRBool *aAny NS_OUTPARAM, PRBool *aAll NS_OUTPARAM) { return !_to ? NS_ERROR_NULL_POINTER : _to->GetInlineProperty(aProperty, aAttribute, aValue, aFirst, aAny, aAll); } \
  NS_SCRIPTABLE NS_IMETHOD GetInlinePropertyWithAttrValue(nsIAtom *aProperty, const nsAString & aAttribute, const nsAString & aValue, PRBool *aFirst NS_OUTPARAM, PRBool *aAny NS_OUTPARAM, PRBool *aAll NS_OUTPARAM, nsAString & _retval NS_OUTPARAM) { return !_to ? NS_ERROR_NULL_POINTER : _to->GetInlinePropertyWithAttrValue(aProperty, aAttribute, aValue, aFirst, aAny, aAll, _retval); } \
  NS_SCRIPTABLE NS_IMETHOD RemoveAllInlineProperties(void) { return !_to ? NS_ERROR_NULL_POINTER : _to->RemoveAllInlineProperties(); } \
  NS_SCRIPTABLE NS_IMETHOD RemoveInlineProperty(nsIAtom *aProperty, const nsAString & aAttribute) { return !_to ? NS_ERROR_NULL_POINTER : _to->RemoveInlineProperty(aProperty, aAttribute); } \
  NS_SCRIPTABLE NS_IMETHOD IncreaseFontSize(void) { return !_to ? NS_ERROR_NULL_POINTER : _to->IncreaseFontSize(); } \
  NS_SCRIPTABLE NS_IMETHOD DecreaseFontSize(void) { return !_to ? NS_ERROR_NULL_POINTER : _to->DecreaseFontSize(); } \
  NS_SCRIPTABLE NS_IMETHOD CanDrag(nsIDOMEvent *aEvent, PRBool *_retval NS_OUTPARAM) { return !_to ? NS_ERROR_NULL_POINTER : _to->CanDrag(aEvent, _retval); } \
  NS_SCRIPTABLE NS_IMETHOD DoDrag(nsIDOMEvent *aEvent) { return !_to ? NS_ERROR_NULL_POINTER : _to->DoDrag(aEvent); } \
  NS_SCRIPTABLE NS_IMETHOD InsertFromDrop(nsIDOMEvent *aEvent) { return !_to ? NS_ERROR_NULL_POINTER : _to->InsertFromDrop(aEvent); } \
  NS_SCRIPTABLE NS_IMETHOD NodeIsBlock(nsIDOMNode *node, PRBool *_retval NS_OUTPARAM) { return !_to ? NS_ERROR_NULL_POINTER : _to->NodeIsBlock(node, _retval); } \
  NS_SCRIPTABLE NS_IMETHOD InsertHTML(const nsAString & aInputString) { return !_to ? NS_ERROR_NULL_POINTER : _to->InsertHTML(aInputString); } \
  NS_SCRIPTABLE NS_IMETHOD PasteNoFormatting(PRInt32 aSelectionType) { return !_to ? NS_ERROR_NULL_POINTER : _to->PasteNoFormatting(aSelectionType); } \
  NS_SCRIPTABLE NS_IMETHOD RebuildDocumentFromSource(const nsAString & aSourceString) { return !_to ? NS_ERROR_NULL_POINTER : _to->RebuildDocumentFromSource(aSourceString); } \
  NS_SCRIPTABLE NS_IMETHOD InsertHTMLWithContext(const nsAString & aInputString, const nsAString & aContextStr, const nsAString & aInfoStr, const nsAString & aFlavor, nsIDOMDocument *aSourceDoc, nsIDOMNode *aDestinationNode, PRInt32 aDestinationOffset, PRBool aDeleteSelection) { return !_to ? NS_ERROR_NULL_POINTER : _to->InsertHTMLWithContext(aInputString, aContextStr, aInfoStr, aFlavor, aSourceDoc, aDestinationNode, aDestinationOffset, aDeleteSelection); } \
  NS_SCRIPTABLE NS_IMETHOD InsertElementAtSelection(nsIDOMElement *aElement, PRBool aDeleteSelection) { return !_to ? NS_ERROR_NULL_POINTER : _to->InsertElementAtSelection(aElement, aDeleteSelection); } \
  NS_SCRIPTABLE NS_IMETHOD SetDocumentTitle(const nsAString & aTitle) { return !_to ? NS_ERROR_NULL_POINTER : _to->SetDocumentTitle(aTitle); } \
  NS_SCRIPTABLE NS_IMETHOD UpdateBaseURL(void) { return !_to ? NS_ERROR_NULL_POINTER : _to->UpdateBaseURL(); } \
  NS_SCRIPTABLE NS_IMETHOD SelectElement(nsIDOMElement *aElement) { return !_to ? NS_ERROR_NULL_POINTER : _to->SelectElement(aElement); } \
  NS_SCRIPTABLE NS_IMETHOD SetCaretAfterElement(nsIDOMElement *aElement) { return !_to ? NS_ERROR_NULL_POINTER : _to->SetCaretAfterElement(aElement); } \
  NS_SCRIPTABLE NS_IMETHOD SetParagraphFormat(const nsAString & aParagraphFormat) { return !_to ? NS_ERROR_NULL_POINTER : _to->SetParagraphFormat(aParagraphFormat); } \
  NS_SCRIPTABLE NS_IMETHOD GetParagraphState(PRBool *aMixed NS_OUTPARAM, nsAString & _retval NS_OUTPARAM) { return !_to ? NS_ERROR_NULL_POINTER : _to->GetParagraphState(aMixed, _retval); } \
  NS_SCRIPTABLE NS_IMETHOD GetFontFaceState(PRBool *aMixed NS_OUTPARAM, nsAString & _retval NS_OUTPARAM) { return !_to ? NS_ERROR_NULL_POINTER : _to->GetFontFaceState(aMixed, _retval); } \
  NS_SCRIPTABLE NS_IMETHOD GetFontColorState(PRBool *aMixed NS_OUTPARAM, nsAString & _retval NS_OUTPARAM) { return !_to ? NS_ERROR_NULL_POINTER : _to->GetFontColorState(aMixed, _retval); } \
  NS_SCRIPTABLE NS_IMETHOD GetBackgroundColorState(PRBool *aMixed NS_OUTPARAM, nsAString & _retval NS_OUTPARAM) { return !_to ? NS_ERROR_NULL_POINTER : _to->GetBackgroundColorState(aMixed, _retval); } \
  NS_SCRIPTABLE NS_IMETHOD GetHighlightColorState(PRBool *aMixed NS_OUTPARAM, nsAString & _retval NS_OUTPARAM) { return !_to ? NS_ERROR_NULL_POINTER : _to->GetHighlightColorState(aMixed, _retval); } \
  NS_SCRIPTABLE NS_IMETHOD GetListState(PRBool *aMixed NS_OUTPARAM, PRBool *aOL NS_OUTPARAM, PRBool *aUL NS_OUTPARAM, PRBool *aDL NS_OUTPARAM) { return !_to ? NS_ERROR_NULL_POINTER : _to->GetListState(aMixed, aOL, aUL, aDL); } \
  NS_SCRIPTABLE NS_IMETHOD GetListItemState(PRBool *aMixed NS_OUTPARAM, PRBool *aLI NS_OUTPARAM, PRBool *aDT NS_OUTPARAM, PRBool *aDD NS_OUTPARAM) { return !_to ? NS_ERROR_NULL_POINTER : _to->GetListItemState(aMixed, aLI, aDT, aDD); } \
  NS_SCRIPTABLE NS_IMETHOD GetAlignment(PRBool *aMixed NS_OUTPARAM, PRInt16 *aAlign NS_OUTPARAM) { return !_to ? NS_ERROR_NULL_POINTER : _to->GetAlignment(aMixed, aAlign); } \
  NS_SCRIPTABLE NS_IMETHOD GetIndentState(PRBool *aCanIndent NS_OUTPARAM, PRBool *aCanOutdent NS_OUTPARAM) { return !_to ? NS_ERROR_NULL_POINTER : _to->GetIndentState(aCanIndent, aCanOutdent); } \
  NS_SCRIPTABLE NS_IMETHOD MakeOrChangeList(const nsAString & aListType, PRBool entireList, const nsAString & aBulletType) { return !_to ? NS_ERROR_NULL_POINTER : _to->MakeOrChangeList(aListType, entireList, aBulletType); } \
  NS_SCRIPTABLE NS_IMETHOD RemoveList(const nsAString & aListType) { return !_to ? NS_ERROR_NULL_POINTER : _to->RemoveList(aListType); } \
  NS_SCRIPTABLE NS_IMETHOD Indent(const nsAString & aIndent) { return !_to ? NS_ERROR_NULL_POINTER : _to->Indent(aIndent); } \
  NS_SCRIPTABLE NS_IMETHOD Align(const nsAString & aAlign) { return !_to ? NS_ERROR_NULL_POINTER : _to->Align(aAlign); } \
  NS_SCRIPTABLE NS_IMETHOD GetElementOrParentByTagName(const nsAString & aTagName, nsIDOMNode *aNode, nsIDOMElement **_retval NS_OUTPARAM) { return !_to ? NS_ERROR_NULL_POINTER : _to->GetElementOrParentByTagName(aTagName, aNode, _retval); } \
  NS_SCRIPTABLE NS_IMETHOD GetSelectedElement(const nsAString & aTagName, nsIDOMElement **_retval NS_OUTPARAM) { return !_to ? NS_ERROR_NULL_POINTER : _to->GetSelectedElement(aTagName, _retval); } \
  NS_SCRIPTABLE NS_IMETHOD GetHeadContentsAsHTML(nsAString & _retval NS_OUTPARAM) { return !_to ? NS_ERROR_NULL_POINTER : _to->GetHeadContentsAsHTML(_retval); } \
  NS_SCRIPTABLE NS_IMETHOD ReplaceHeadContentsWithHTML(const nsAString & aSourceToInsert) { return !_to ? NS_ERROR_NULL_POINTER : _to->ReplaceHeadContentsWithHTML(aSourceToInsert); } \
  NS_SCRIPTABLE NS_IMETHOD CreateElementWithDefaults(const nsAString & aTagName, nsIDOMElement **_retval NS_OUTPARAM) { return !_to ? NS_ERROR_NULL_POINTER : _to->CreateElementWithDefaults(aTagName, _retval); } \
  NS_SCRIPTABLE NS_IMETHOD InsertLinkAroundSelection(nsIDOMElement *aAnchorElement) { return !_to ? NS_ERROR_NULL_POINTER : _to->InsertLinkAroundSelection(aAnchorElement); } \
  NS_SCRIPTABLE NS_IMETHOD SetBackgroundColor(const nsAString & aColor) { return !_to ? NS_ERROR_NULL_POINTER : _to->SetBackgroundColor(aColor); } \
  NS_SCRIPTABLE NS_IMETHOD SetBodyAttribute(const nsAString & aAttr, const nsAString & aValue) { return !_to ? NS_ERROR_NULL_POINTER : _to->SetBodyAttribute(aAttr, aValue); } \
  NS_SCRIPTABLE NS_IMETHOD IgnoreSpuriousDragEvent(PRBool aIgnoreSpuriousDragEvent) { return !_to ? NS_ERROR_NULL_POINTER : _to->IgnoreSpuriousDragEvent(aIgnoreSpuriousDragEvent); } \
  NS_SCRIPTABLE NS_IMETHOD GetLinkedObjects(nsISupportsArray **_retval NS_OUTPARAM) { return !_to ? NS_ERROR_NULL_POINTER : _to->GetLinkedObjects(_retval); } \
  NS_SCRIPTABLE NS_IMETHOD GetIsCSSEnabled(PRBool *aIsCSSEnabled) { return !_to ? NS_ERROR_NULL_POINTER : _to->GetIsCSSEnabled(aIsCSSEnabled); } \
  NS_SCRIPTABLE NS_IMETHOD SetIsCSSEnabled(PRBool aIsCSSEnabled) { return !_to ? NS_ERROR_NULL_POINTER : _to->SetIsCSSEnabled(aIsCSSEnabled); } \
  NS_SCRIPTABLE NS_IMETHOD AddInsertionListener(nsIContentFilter *inFilter) { return !_to ? NS_ERROR_NULL_POINTER : _to->AddInsertionListener(inFilter); } \
  NS_SCRIPTABLE NS_IMETHOD RemoveInsertionListener(nsIContentFilter *inFilter) { return !_to ? NS_ERROR_NULL_POINTER : _to->RemoveInsertionListener(inFilter); } \
  NS_SCRIPTABLE NS_IMETHOD CreateAnonymousElement(const nsAString & aTag, nsIDOMNode *aParentNode, const nsAString & aAnonClass, PRBool aIsCreatedHidden, nsIDOMElement **_retval NS_OUTPARAM) { return !_to ? NS_ERROR_NULL_POINTER : _to->CreateAnonymousElement(aTag, aParentNode, aAnonClass, aIsCreatedHidden, _retval); } \
  NS_SCRIPTABLE NS_IMETHOD GetSelectionContainer(nsIDOMElement **_retval NS_OUTPARAM) { return !_to ? NS_ERROR_NULL_POINTER : _to->GetSelectionContainer(_retval); } \
  NS_SCRIPTABLE NS_IMETHOD CheckSelectionStateForAnonymousButtons(nsISelection *aSelection) { return !_to ? NS_ERROR_NULL_POINTER : _to->CheckSelectionStateForAnonymousButtons(aSelection); } \
  NS_SCRIPTABLE NS_IMETHOD IsAnonymousElement(nsIDOMElement *aElement, PRBool *_retval NS_OUTPARAM) { return !_to ? NS_ERROR_NULL_POINTER : _to->IsAnonymousElement(aElement, _retval); } \
  NS_SCRIPTABLE NS_IMETHOD GetReturnInParagraphCreatesNewParagraph(PRBool *aReturnInParagraphCreatesNewParagraph) { return !_to ? NS_ERROR_NULL_POINTER : _to->GetReturnInParagraphCreatesNewParagraph(aReturnInParagraphCreatesNewParagraph); } \
  NS_SCRIPTABLE NS_IMETHOD SetReturnInParagraphCreatesNewParagraph(PRBool aReturnInParagraphCreatesNewParagraph) { return !_to ? NS_ERROR_NULL_POINTER : _to->SetReturnInParagraphCreatesNewParagraph(aReturnInParagraphCreatesNewParagraph); } 

#if 0
/* Use the code below as a template for the implementation class for this interface. */

/* Header file */
class nsHTMLEditor : public nsIHTMLEditor
{
public:
  NS_DECL_ISUPPORTS
  NS_DECL_NSIHTMLEDITOR

  nsHTMLEditor();

private:
  ~nsHTMLEditor();

protected:
  /* additional members */
};

/* Implementation file */
NS_IMPL_ISUPPORTS1(nsHTMLEditor, nsIHTMLEditor)

nsHTMLEditor::nsHTMLEditor()
{
  /* member initializers and constructor code */
}

nsHTMLEditor::~nsHTMLEditor()
{
  /* destructor code */
}

/* void addDefaultProperty (in nsIAtom aProperty, in AString aAttribute, in AString aValue); */
NS_IMETHODIMP nsHTMLEditor::AddDefaultProperty(nsIAtom *aProperty, const nsAString & aAttribute, const nsAString & aValue)
{
    return NS_ERROR_NOT_IMPLEMENTED;
}

/* void removeDefaultProperty (in nsIAtom aProperty, in AString aAttribute, in AString aValue); */
NS_IMETHODIMP nsHTMLEditor::RemoveDefaultProperty(nsIAtom *aProperty, const nsAString & aAttribute, const nsAString & aValue)
{
    return NS_ERROR_NOT_IMPLEMENTED;
}

/* void removeAllDefaultProperties (); */
NS_IMETHODIMP nsHTMLEditor::RemoveAllDefaultProperties()
{
    return NS_ERROR_NOT_IMPLEMENTED;
}

/* void setCSSInlineProperty (in nsIAtom aProperty, in AString aAttribute, in AString aValue); */
NS_IMETHODIMP nsHTMLEditor::SetCSSInlineProperty(nsIAtom *aProperty, const nsAString & aAttribute, const nsAString & aValue)
{
    return NS_ERROR_NOT_IMPLEMENTED;
}

/* void setInlineProperty (in nsIAtom aProperty, in AString aAttribute, in AString aValue); */
NS_IMETHODIMP nsHTMLEditor::SetInlineProperty(nsIAtom *aProperty, const nsAString & aAttribute, const nsAString & aValue)
{
    return NS_ERROR_NOT_IMPLEMENTED;
}

/* void getInlineProperty (in nsIAtom aProperty, in AString aAttribute, in AString aValue, out boolean aFirst, out boolean aAny, out boolean aAll); */
NS_IMETHODIMP nsHTMLEditor::GetInlineProperty(nsIAtom *aProperty, const nsAString & aAttribute, const nsAString & aValue, PRBool *aFirst NS_OUTPARAM, PRBool *aAny NS_OUTPARAM, PRBool *aAll NS_OUTPARAM)
{
    return NS_ERROR_NOT_IMPLEMENTED;
}

/* AString getInlinePropertyWithAttrValue (in nsIAtom aProperty, in AString aAttribute, in AString aValue, out boolean aFirst, out boolean aAny, out boolean aAll); */
NS_IMETHODIMP nsHTMLEditor::GetInlinePropertyWithAttrValue(nsIAtom *aProperty, const nsAString & aAttribute, const nsAString & aValue, PRBool *aFirst NS_OUTPARAM, PRBool *aAny NS_OUTPARAM, PRBool *aAll NS_OUTPARAM, nsAString & _retval NS_OUTPARAM)
{
    return NS_ERROR_NOT_IMPLEMENTED;
}

/* void removeAllInlineProperties (); */
NS_IMETHODIMP nsHTMLEditor::RemoveAllInlineProperties()
{
    return NS_ERROR_NOT_IMPLEMENTED;
}

/* void removeInlineProperty (in nsIAtom aProperty, in AString aAttribute); */
NS_IMETHODIMP nsHTMLEditor::RemoveInlineProperty(nsIAtom *aProperty, const nsAString & aAttribute)
{
    return NS_ERROR_NOT_IMPLEMENTED;
}

/* void increaseFontSize (); */
NS_IMETHODIMP nsHTMLEditor::IncreaseFontSize()
{
    return NS_ERROR_NOT_IMPLEMENTED;
}

/* void decreaseFontSize (); */
NS_IMETHODIMP nsHTMLEditor::DecreaseFontSize()
{
    return NS_ERROR_NOT_IMPLEMENTED;
}

/* boolean canDrag (in nsIDOMEvent aEvent); */
NS_IMETHODIMP nsHTMLEditor::CanDrag(nsIDOMEvent *aEvent, PRBool *_retval NS_OUTPARAM)
{
    return NS_ERROR_NOT_IMPLEMENTED;
}

/* void doDrag (in nsIDOMEvent aEvent); */
NS_IMETHODIMP nsHTMLEditor::DoDrag(nsIDOMEvent *aEvent)
{
    return NS_ERROR_NOT_IMPLEMENTED;
}

/* void insertFromDrop (in nsIDOMEvent aEvent); */
NS_IMETHODIMP nsHTMLEditor::InsertFromDrop(nsIDOMEvent *aEvent)
{
    return NS_ERROR_NOT_IMPLEMENTED;
}

/* boolean nodeIsBlock (in nsIDOMNode node); */
NS_IMETHODIMP nsHTMLEditor::NodeIsBlock(nsIDOMNode *node, PRBool *_retval NS_OUTPARAM)
{
    return NS_ERROR_NOT_IMPLEMENTED;
}

/* void insertHTML (in AString aInputString); */
NS_IMETHODIMP nsHTMLEditor::InsertHTML(const nsAString & aInputString)
{
    return NS_ERROR_NOT_IMPLEMENTED;
}

/* void pasteNoFormatting (in long aSelectionType); */
NS_IMETHODIMP nsHTMLEditor::PasteNoFormatting(PRInt32 aSelectionType)
{
    return NS_ERROR_NOT_IMPLEMENTED;
}

/* void rebuildDocumentFromSource (in AString aSourceString); */
NS_IMETHODIMP nsHTMLEditor::RebuildDocumentFromSource(const nsAString & aSourceString)
{
    return NS_ERROR_NOT_IMPLEMENTED;
}

/* void insertHTMLWithContext (in AString aInputString, in AString aContextStr, in AString aInfoStr, in AString aFlavor, in nsIDOMDocument aSourceDoc, in nsIDOMNode aDestinationNode, in long aDestinationOffset, in boolean aDeleteSelection); */
NS_IMETHODIMP nsHTMLEditor::InsertHTMLWithContext(const nsAString & aInputString, const nsAString & aContextStr, const nsAString & aInfoStr, const nsAString & aFlavor, nsIDOMDocument *aSourceDoc, nsIDOMNode *aDestinationNode, PRInt32 aDestinationOffset, PRBool aDeleteSelection)
{
    return NS_ERROR_NOT_IMPLEMENTED;
}

/* void insertElementAtSelection (in nsIDOMElement aElement, in boolean aDeleteSelection); */
NS_IMETHODIMP nsHTMLEditor::InsertElementAtSelection(nsIDOMElement *aElement, PRBool aDeleteSelection)
{
    return NS_ERROR_NOT_IMPLEMENTED;
}

/* void setDocumentTitle (in AString aTitle); */
NS_IMETHODIMP nsHTMLEditor::SetDocumentTitle(const nsAString & aTitle)
{
    return NS_ERROR_NOT_IMPLEMENTED;
}

/* void updateBaseURL (); */
NS_IMETHODIMP nsHTMLEditor::UpdateBaseURL()
{
    return NS_ERROR_NOT_IMPLEMENTED;
}

/* void selectElement (in nsIDOMElement aElement); */
NS_IMETHODIMP nsHTMLEditor::SelectElement(nsIDOMElement *aElement)
{
    return NS_ERROR_NOT_IMPLEMENTED;
}

/* void setCaretAfterElement (in nsIDOMElement aElement); */
NS_IMETHODIMP nsHTMLEditor::SetCaretAfterElement(nsIDOMElement *aElement)
{
    return NS_ERROR_NOT_IMPLEMENTED;
}

/* void setParagraphFormat (in AString aParagraphFormat); */
NS_IMETHODIMP nsHTMLEditor::SetParagraphFormat(const nsAString & aParagraphFormat)
{
    return NS_ERROR_NOT_IMPLEMENTED;
}

/* AString getParagraphState (out boolean aMixed); */
NS_IMETHODIMP nsHTMLEditor::GetParagraphState(PRBool *aMixed NS_OUTPARAM, nsAString & _retval NS_OUTPARAM)
{
    return NS_ERROR_NOT_IMPLEMENTED;
}

/* AString getFontFaceState (out boolean aMixed); */
NS_IMETHODIMP nsHTMLEditor::GetFontFaceState(PRBool *aMixed NS_OUTPARAM, nsAString & _retval NS_OUTPARAM)
{
    return NS_ERROR_NOT_IMPLEMENTED;
}

/* AString getFontColorState (out boolean aMixed); */
NS_IMETHODIMP nsHTMLEditor::GetFontColorState(PRBool *aMixed NS_OUTPARAM, nsAString & _retval NS_OUTPARAM)
{
    return NS_ERROR_NOT_IMPLEMENTED;
}

/* AString getBackgroundColorState (out boolean aMixed); */
NS_IMETHODIMP nsHTMLEditor::GetBackgroundColorState(PRBool *aMixed NS_OUTPARAM, nsAString & _retval NS_OUTPARAM)
{
    return NS_ERROR_NOT_IMPLEMENTED;
}

/* AString getHighlightColorState (out boolean aMixed); */
NS_IMETHODIMP nsHTMLEditor::GetHighlightColorState(PRBool *aMixed NS_OUTPARAM, nsAString & _retval NS_OUTPARAM)
{
    return NS_ERROR_NOT_IMPLEMENTED;
}

/* void getListState (out boolean aMixed, out boolean aOL, out boolean aUL, out boolean aDL); */
NS_IMETHODIMP nsHTMLEditor::GetListState(PRBool *aMixed NS_OUTPARAM, PRBool *aOL NS_OUTPARAM, PRBool *aUL NS_OUTPARAM, PRBool *aDL NS_OUTPARAM)
{
    return NS_ERROR_NOT_IMPLEMENTED;
}

/* void getListItemState (out boolean aMixed, out boolean aLI, out boolean aDT, out boolean aDD); */
NS_IMETHODIMP nsHTMLEditor::GetListItemState(PRBool *aMixed NS_OUTPARAM, PRBool *aLI NS_OUTPARAM, PRBool *aDT NS_OUTPARAM, PRBool *aDD NS_OUTPARAM)
{
    return NS_ERROR_NOT_IMPLEMENTED;
}

/* void getAlignment (out boolean aMixed, out short aAlign); */
NS_IMETHODIMP nsHTMLEditor::GetAlignment(PRBool *aMixed NS_OUTPARAM, PRInt16 *aAlign NS_OUTPARAM)
{
    return NS_ERROR_NOT_IMPLEMENTED;
}

/* void getIndentState (out boolean aCanIndent, out boolean aCanOutdent); */
NS_IMETHODIMP nsHTMLEditor::GetIndentState(PRBool *aCanIndent NS_OUTPARAM, PRBool *aCanOutdent NS_OUTPARAM)
{
    return NS_ERROR_NOT_IMPLEMENTED;
}

/* void makeOrChangeList (in AString aListType, in boolean entireList, in AString aBulletType); */
NS_IMETHODIMP nsHTMLEditor::MakeOrChangeList(const nsAString & aListType, PRBool entireList, const nsAString & aBulletType)
{
    return NS_ERROR_NOT_IMPLEMENTED;
}

/* void removeList (in AString aListType); */
NS_IMETHODIMP nsHTMLEditor::RemoveList(const nsAString & aListType)
{
    return NS_ERROR_NOT_IMPLEMENTED;
}

/* void indent (in AString aIndent); */
NS_IMETHODIMP nsHTMLEditor::Indent(const nsAString & aIndent)
{
    return NS_ERROR_NOT_IMPLEMENTED;
}

/* void align (in AString aAlign); */
NS_IMETHODIMP nsHTMLEditor::Align(const nsAString & aAlign)
{
    return NS_ERROR_NOT_IMPLEMENTED;
}

/* nsIDOMElement getElementOrParentByTagName (in AString aTagName, in nsIDOMNode aNode); */
NS_IMETHODIMP nsHTMLEditor::GetElementOrParentByTagName(const nsAString & aTagName, nsIDOMNode *aNode, nsIDOMElement **_retval NS_OUTPARAM)
{
    return NS_ERROR_NOT_IMPLEMENTED;
}

/* nsIDOMElement getSelectedElement (in AString aTagName); */
NS_IMETHODIMP nsHTMLEditor::GetSelectedElement(const nsAString & aTagName, nsIDOMElement **_retval NS_OUTPARAM)
{
    return NS_ERROR_NOT_IMPLEMENTED;
}

/* AString getHeadContentsAsHTML (); */
NS_IMETHODIMP nsHTMLEditor::GetHeadContentsAsHTML(nsAString & _retval NS_OUTPARAM)
{
    return NS_ERROR_NOT_IMPLEMENTED;
}

/* void replaceHeadContentsWithHTML (in AString aSourceToInsert); */
NS_IMETHODIMP nsHTMLEditor::ReplaceHeadContentsWithHTML(const nsAString & aSourceToInsert)
{
    return NS_ERROR_NOT_IMPLEMENTED;
}

/* nsIDOMElement createElementWithDefaults (in AString aTagName); */
NS_IMETHODIMP nsHTMLEditor::CreateElementWithDefaults(const nsAString & aTagName, nsIDOMElement **_retval NS_OUTPARAM)
{
    return NS_ERROR_NOT_IMPLEMENTED;
}

/* void insertLinkAroundSelection (in nsIDOMElement aAnchorElement); */
NS_IMETHODIMP nsHTMLEditor::InsertLinkAroundSelection(nsIDOMElement *aAnchorElement)
{
    return NS_ERROR_NOT_IMPLEMENTED;
}

/* void setBackgroundColor (in AString aColor); */
NS_IMETHODIMP nsHTMLEditor::SetBackgroundColor(const nsAString & aColor)
{
    return NS_ERROR_NOT_IMPLEMENTED;
}

/* void setBodyAttribute (in AString aAttr, in AString aValue); */
NS_IMETHODIMP nsHTMLEditor::SetBodyAttribute(const nsAString & aAttr, const nsAString & aValue)
{
    return NS_ERROR_NOT_IMPLEMENTED;
}

/* void ignoreSpuriousDragEvent (in boolean aIgnoreSpuriousDragEvent); */
NS_IMETHODIMP nsHTMLEditor::IgnoreSpuriousDragEvent(PRBool aIgnoreSpuriousDragEvent)
{
    return NS_ERROR_NOT_IMPLEMENTED;
}

/* nsISupportsArray getLinkedObjects (); */
NS_IMETHODIMP nsHTMLEditor::GetLinkedObjects(nsISupportsArray **_retval NS_OUTPARAM)
{
    return NS_ERROR_NOT_IMPLEMENTED;
}

/* attribute boolean isCSSEnabled; */
NS_IMETHODIMP nsHTMLEditor::GetIsCSSEnabled(PRBool *aIsCSSEnabled)
{
    return NS_ERROR_NOT_IMPLEMENTED;
}
NS_IMETHODIMP nsHTMLEditor::SetIsCSSEnabled(PRBool aIsCSSEnabled)
{
    return NS_ERROR_NOT_IMPLEMENTED;
}

/* void addInsertionListener (in nsIContentFilter inFilter); */
NS_IMETHODIMP nsHTMLEditor::AddInsertionListener(nsIContentFilter *inFilter)
{
    return NS_ERROR_NOT_IMPLEMENTED;
}

/* void removeInsertionListener (in nsIContentFilter inFilter); */
NS_IMETHODIMP nsHTMLEditor::RemoveInsertionListener(nsIContentFilter *inFilter)
{
    return NS_ERROR_NOT_IMPLEMENTED;
}

/* nsIDOMElement createAnonymousElement (in AString aTag, in nsIDOMNode aParentNode, in AString aAnonClass, in boolean aIsCreatedHidden); */
NS_IMETHODIMP nsHTMLEditor::CreateAnonymousElement(const nsAString & aTag, nsIDOMNode *aParentNode, const nsAString & aAnonClass, PRBool aIsCreatedHidden, nsIDOMElement **_retval NS_OUTPARAM)
{
    return NS_ERROR_NOT_IMPLEMENTED;
}

/* nsIDOMElement getSelectionContainer (); */
NS_IMETHODIMP nsHTMLEditor::GetSelectionContainer(nsIDOMElement **_retval NS_OUTPARAM)
{
    return NS_ERROR_NOT_IMPLEMENTED;
}

/* void checkSelectionStateForAnonymousButtons (in nsISelection aSelection); */
NS_IMETHODIMP nsHTMLEditor::CheckSelectionStateForAnonymousButtons(nsISelection *aSelection)
{
    return NS_ERROR_NOT_IMPLEMENTED;
}

/* boolean isAnonymousElement (in nsIDOMElement aElement); */
NS_IMETHODIMP nsHTMLEditor::IsAnonymousElement(nsIDOMElement *aElement, PRBool *_retval NS_OUTPARAM)
{
    return NS_ERROR_NOT_IMPLEMENTED;
}

/* attribute boolean returnInParagraphCreatesNewParagraph; */
NS_IMETHODIMP nsHTMLEditor::GetReturnInParagraphCreatesNewParagraph(PRBool *aReturnInParagraphCreatesNewParagraph)
{
    return NS_ERROR_NOT_IMPLEMENTED;
}
NS_IMETHODIMP nsHTMLEditor::SetReturnInParagraphCreatesNewParagraph(PRBool aReturnInParagraphCreatesNewParagraph)
{
    return NS_ERROR_NOT_IMPLEMENTED;
}

/* End of implementation class template. */
#endif


#endif /* __gen_nsIHTMLEditor_h__ */
