/*
 * DO NOT EDIT.  THIS FILE IS GENERATED FROM e:/builds/moz2_slave/mozilla-1.9.1-win32-xulrunner/build/editor/idl/nsIContentFilter.idl
 */

#ifndef __gen_nsIContentFilter_h__
#define __gen_nsIContentFilter_h__


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
class nsIURL; /* forward declaration */


/* starting interface:    nsIContentFilter */
#define NS_ICONTENTFILTER_IID_STR "c18c49a8-62f0-4045-9884-4aa91e388f14"

#define NS_ICONTENTFILTER_IID \
  {0xc18c49a8, 0x62f0, 0x4045, \
    { 0x98, 0x84, 0x4a, 0xa9, 0x1e, 0x38, 0x8f, 0x14 }}

class NS_NO_VTABLE NS_SCRIPTABLE nsIContentFilter : public nsISupports {
 public: 

  NS_DECLARE_STATIC_IID_ACCESSOR(NS_ICONTENTFILTER_IID)

  /**
   * This notification occurs in an editor during these events:
   *    * open of document (once rendered in window but before editable)
   *    * paste from clipboard
   *    * drop from mouse
   *    * insertion of html (such as with "cmd_insertHTML")
   * It provides a hook so the above actions can be canceled or the data
   * can be modified (using standard DOM APIs) or left untouched.  The data
   * that results (if any) from all filter callbacks is what will be used
   * for transaction purposes (undo/redo) except for the open event.
   *
   * The willDeleteSelection parameter is offered for filters who want to
   * handle the insertion themselves and need to handle drag/drop correctly.
   * The flag is true when the editor intends to delete the selection.
   *
   * Callers who want to cancel all insertion can simply set
   * continueWithInsertion to PR_FALSE and return.
   * Note: If cancellation occurs during the "open" event, the editor will
   * still be available but will be empty.
   *
   * Callers who want to allow insertion of the data with no changes
   * can simply set continueWithInsertion to PR_TRUE and return.
   *
   * Callers who want to modify the content (docFragment) being inserted are 
   * responsible for updating contentStartNode, contentStartOffset, 
   * contentEndNode, and contentEndOffset (if necessary).  
   * Callers are responsible for freeing and addref'ing if they want to 
   * completely replace any of the DOM nodes passed in.
   *
   * The location where insertion will occur should be considered an
   * approximation since the editor may need to adjust it if it deletes
   * the selection as part of the event and later determines that insertion
   * point is an empty container which should also be removed (or in other
   * scenarios such as -moz-user-select:none).
   *
   * In some scenarios the selection will be deleted.  If callers choose
   * to adjust the insertion point, they should be careful that the insertion
   * point is not in the current selection.
   *
   * The contentStartNode and contentEndNode are not necessarily
   * immediate children of the docFragment.  Any nodes outside of the range
   * set by contentStartNode and contentEndNode are for context from the
   * source document.
   *
   * @param mimeType          the mimetype used for retrieving data
   * @param contentSourceURL  location where docFragment came from
   * @param sourceDocument      document where content came from (can be null)
   * @param willDeleteSelection tells hook if selection will/should be deleted
   * @param docFragment         fragment of node to be inserted
   * @param contentStartNode    node under which content to be inserted begins
   * @param contentStartOffset  start offset within contentStartNode
   * @param contentEndNode      node under which content to be inserted ends
   * @param contentEndOffset    ending offset withing contentEndNode
   * @param insertionPointNode     location where insertion will occur
   * @param insertionPointOffset   offset within node where insertion occurs
   * @param continueWithInsertion  flag to cancel insertion (if desired)
   */
  /* void notifyOfInsertion (in AString mimeType, in nsIURL contentSourceURL, in nsIDOMDocument sourceDocument, in PRBool willDeleteSelection, inout nsIDOMNode docFragment, inout nsIDOMNode contentStartNode, inout long contentStartOffset, inout nsIDOMNode contentEndNode, inout long contentEndOffset, inout nsIDOMNode insertionPointNode, inout long insertionPointOffset, out boolean continueWithInsertion); */
  NS_SCRIPTABLE NS_IMETHOD NotifyOfInsertion(const nsAString & mimeType, nsIURL *contentSourceURL, nsIDOMDocument *sourceDocument, PRBool willDeleteSelection, nsIDOMNode **docFragment NS_INOUTPARAM, nsIDOMNode **contentStartNode NS_INOUTPARAM, PRInt32 *contentStartOffset NS_INOUTPARAM, nsIDOMNode **contentEndNode NS_INOUTPARAM, PRInt32 *contentEndOffset NS_INOUTPARAM, nsIDOMNode **insertionPointNode NS_INOUTPARAM, PRInt32 *insertionPointOffset NS_INOUTPARAM, PRBool *continueWithInsertion NS_OUTPARAM) = 0;

};

  NS_DEFINE_STATIC_IID_ACCESSOR(nsIContentFilter, NS_ICONTENTFILTER_IID)

/* Use this macro when declaring classes that implement this interface. */
#define NS_DECL_NSICONTENTFILTER \
  NS_SCRIPTABLE NS_IMETHOD NotifyOfInsertion(const nsAString & mimeType, nsIURL *contentSourceURL, nsIDOMDocument *sourceDocument, PRBool willDeleteSelection, nsIDOMNode **docFragment NS_INOUTPARAM, nsIDOMNode **contentStartNode NS_INOUTPARAM, PRInt32 *contentStartOffset NS_INOUTPARAM, nsIDOMNode **contentEndNode NS_INOUTPARAM, PRInt32 *contentEndOffset NS_INOUTPARAM, nsIDOMNode **insertionPointNode NS_INOUTPARAM, PRInt32 *insertionPointOffset NS_INOUTPARAM, PRBool *continueWithInsertion NS_OUTPARAM); 

/* Use this macro to declare functions that forward the behavior of this interface to another object. */
#define NS_FORWARD_NSICONTENTFILTER(_to) \
  NS_SCRIPTABLE NS_IMETHOD NotifyOfInsertion(const nsAString & mimeType, nsIURL *contentSourceURL, nsIDOMDocument *sourceDocument, PRBool willDeleteSelection, nsIDOMNode **docFragment NS_INOUTPARAM, nsIDOMNode **contentStartNode NS_INOUTPARAM, PRInt32 *contentStartOffset NS_INOUTPARAM, nsIDOMNode **contentEndNode NS_INOUTPARAM, PRInt32 *contentEndOffset NS_INOUTPARAM, nsIDOMNode **insertionPointNode NS_INOUTPARAM, PRInt32 *insertionPointOffset NS_INOUTPARAM, PRBool *continueWithInsertion NS_OUTPARAM) { return _to NotifyOfInsertion(mimeType, contentSourceURL, sourceDocument, willDeleteSelection, docFragment, contentStartNode, contentStartOffset, contentEndNode, contentEndOffset, insertionPointNode, insertionPointOffset, continueWithInsertion); } 

/* Use this macro to declare functions that forward the behavior of this interface to another object in a safe way. */
#define NS_FORWARD_SAFE_NSICONTENTFILTER(_to) \
  NS_SCRIPTABLE NS_IMETHOD NotifyOfInsertion(const nsAString & mimeType, nsIURL *contentSourceURL, nsIDOMDocument *sourceDocument, PRBool willDeleteSelection, nsIDOMNode **docFragment NS_INOUTPARAM, nsIDOMNode **contentStartNode NS_INOUTPARAM, PRInt32 *contentStartOffset NS_INOUTPARAM, nsIDOMNode **contentEndNode NS_INOUTPARAM, PRInt32 *contentEndOffset NS_INOUTPARAM, nsIDOMNode **insertionPointNode NS_INOUTPARAM, PRInt32 *insertionPointOffset NS_INOUTPARAM, PRBool *continueWithInsertion NS_OUTPARAM) { return !_to ? NS_ERROR_NULL_POINTER : _to->NotifyOfInsertion(mimeType, contentSourceURL, sourceDocument, willDeleteSelection, docFragment, contentStartNode, contentStartOffset, contentEndNode, contentEndOffset, insertionPointNode, insertionPointOffset, continueWithInsertion); } 

#if 0
/* Use the code below as a template for the implementation class for this interface. */

/* Header file */
class nsContentFilter : public nsIContentFilter
{
public:
  NS_DECL_ISUPPORTS
  NS_DECL_NSICONTENTFILTER

  nsContentFilter();

private:
  ~nsContentFilter();

protected:
  /* additional members */
};

/* Implementation file */
NS_IMPL_ISUPPORTS1(nsContentFilter, nsIContentFilter)

nsContentFilter::nsContentFilter()
{
  /* member initializers and constructor code */
}

nsContentFilter::~nsContentFilter()
{
  /* destructor code */
}

/* void notifyOfInsertion (in AString mimeType, in nsIURL contentSourceURL, in nsIDOMDocument sourceDocument, in PRBool willDeleteSelection, inout nsIDOMNode docFragment, inout nsIDOMNode contentStartNode, inout long contentStartOffset, inout nsIDOMNode contentEndNode, inout long contentEndOffset, inout nsIDOMNode insertionPointNode, inout long insertionPointOffset, out boolean continueWithInsertion); */
NS_IMETHODIMP nsContentFilter::NotifyOfInsertion(const nsAString & mimeType, nsIURL *contentSourceURL, nsIDOMDocument *sourceDocument, PRBool willDeleteSelection, nsIDOMNode **docFragment NS_INOUTPARAM, nsIDOMNode **contentStartNode NS_INOUTPARAM, PRInt32 *contentStartOffset NS_INOUTPARAM, nsIDOMNode **contentEndNode NS_INOUTPARAM, PRInt32 *contentEndOffset NS_INOUTPARAM, nsIDOMNode **insertionPointNode NS_INOUTPARAM, PRInt32 *insertionPointOffset NS_INOUTPARAM, PRBool *continueWithInsertion NS_OUTPARAM)
{
    return NS_ERROR_NOT_IMPLEMENTED;
}

/* End of implementation class template. */
#endif


#endif /* __gen_nsIContentFilter_h__ */
