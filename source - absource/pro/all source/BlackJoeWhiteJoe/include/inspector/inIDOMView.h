/*
 * DO NOT EDIT.  THIS FILE IS GENERATED FROM e:/builds/moz2_slave/mozilla-1.9.1-win32-xulrunner/build/layout/inspector/public/inIDOMView.idl
 */

#ifndef __gen_inIDOMView_h__
#define __gen_inIDOMView_h__


#ifndef __gen_nsISupports_h__
#include "nsISupports.h"
#endif

/* For IDL files that don't want to include root IDL files. */
#ifndef NS_NO_VTABLE
#define NS_NO_VTABLE
#endif
class nsIDOMNode; /* forward declaration */


/* starting interface:    inIDOMView */
#define INIDOMVIEW_IID_STR "fbb67442-27a3-483c-8eb2-29c3eed7514c"

#define INIDOMVIEW_IID \
  {0xfbb67442, 0x27a3, 0x483c, \
    { 0x8e, 0xb2, 0x29, 0xc3, 0xee, 0xd7, 0x51, 0x4c }}

class NS_NO_VTABLE NS_SCRIPTABLE inIDOMView : public nsISupports {
 public: 

  NS_DECLARE_STATIC_IID_ACCESSOR(INIDOMVIEW_IID)

  /* attribute nsIDOMNode rootNode; */
  NS_SCRIPTABLE NS_IMETHOD GetRootNode(nsIDOMNode * *aRootNode) = 0;
  NS_SCRIPTABLE NS_IMETHOD SetRootNode(nsIDOMNode * aRootNode) = 0;

  /* attribute boolean showAnonymousContent; */
  NS_SCRIPTABLE NS_IMETHOD GetShowAnonymousContent(PRBool *aShowAnonymousContent) = 0;
  NS_SCRIPTABLE NS_IMETHOD SetShowAnonymousContent(PRBool aShowAnonymousContent) = 0;

  /* attribute boolean showSubDocuments; */
  NS_SCRIPTABLE NS_IMETHOD GetShowSubDocuments(PRBool *aShowSubDocuments) = 0;
  NS_SCRIPTABLE NS_IMETHOD SetShowSubDocuments(PRBool aShowSubDocuments) = 0;

  /* attribute boolean showWhitespaceNodes; */
  NS_SCRIPTABLE NS_IMETHOD GetShowWhitespaceNodes(PRBool *aShowWhitespaceNodes) = 0;
  NS_SCRIPTABLE NS_IMETHOD SetShowWhitespaceNodes(PRBool aShowWhitespaceNodes) = 0;

  /* attribute boolean showAccessibleNodes; */
  NS_SCRIPTABLE NS_IMETHOD GetShowAccessibleNodes(PRBool *aShowAccessibleNodes) = 0;
  NS_SCRIPTABLE NS_IMETHOD SetShowAccessibleNodes(PRBool aShowAccessibleNodes) = 0;

  /* attribute unsigned long whatToShow; */
  NS_SCRIPTABLE NS_IMETHOD GetWhatToShow(PRUint32 *aWhatToShow) = 0;
  NS_SCRIPTABLE NS_IMETHOD SetWhatToShow(PRUint32 aWhatToShow) = 0;

  /* nsIDOMNode getNodeFromRowIndex (in long rowIndex); */
  NS_SCRIPTABLE NS_IMETHOD GetNodeFromRowIndex(PRInt32 rowIndex, nsIDOMNode **_retval NS_OUTPARAM) = 0;

  /* long getRowIndexFromNode (in nsIDOMNode node); */
  NS_SCRIPTABLE NS_IMETHOD GetRowIndexFromNode(nsIDOMNode *node, PRInt32 *_retval NS_OUTPARAM) = 0;

  /* void rebuild (); */
  NS_SCRIPTABLE NS_IMETHOD Rebuild(void) = 0;

};

  NS_DEFINE_STATIC_IID_ACCESSOR(inIDOMView, INIDOMVIEW_IID)

/* Use this macro when declaring classes that implement this interface. */
#define NS_DECL_INIDOMVIEW \
  NS_SCRIPTABLE NS_IMETHOD GetRootNode(nsIDOMNode * *aRootNode); \
  NS_SCRIPTABLE NS_IMETHOD SetRootNode(nsIDOMNode * aRootNode); \
  NS_SCRIPTABLE NS_IMETHOD GetShowAnonymousContent(PRBool *aShowAnonymousContent); \
  NS_SCRIPTABLE NS_IMETHOD SetShowAnonymousContent(PRBool aShowAnonymousContent); \
  NS_SCRIPTABLE NS_IMETHOD GetShowSubDocuments(PRBool *aShowSubDocuments); \
  NS_SCRIPTABLE NS_IMETHOD SetShowSubDocuments(PRBool aShowSubDocuments); \
  NS_SCRIPTABLE NS_IMETHOD GetShowWhitespaceNodes(PRBool *aShowWhitespaceNodes); \
  NS_SCRIPTABLE NS_IMETHOD SetShowWhitespaceNodes(PRBool aShowWhitespaceNodes); \
  NS_SCRIPTABLE NS_IMETHOD GetShowAccessibleNodes(PRBool *aShowAccessibleNodes); \
  NS_SCRIPTABLE NS_IMETHOD SetShowAccessibleNodes(PRBool aShowAccessibleNodes); \
  NS_SCRIPTABLE NS_IMETHOD GetWhatToShow(PRUint32 *aWhatToShow); \
  NS_SCRIPTABLE NS_IMETHOD SetWhatToShow(PRUint32 aWhatToShow); \
  NS_SCRIPTABLE NS_IMETHOD GetNodeFromRowIndex(PRInt32 rowIndex, nsIDOMNode **_retval NS_OUTPARAM); \
  NS_SCRIPTABLE NS_IMETHOD GetRowIndexFromNode(nsIDOMNode *node, PRInt32 *_retval NS_OUTPARAM); \
  NS_SCRIPTABLE NS_IMETHOD Rebuild(void); 

/* Use this macro to declare functions that forward the behavior of this interface to another object. */
#define NS_FORWARD_INIDOMVIEW(_to) \
  NS_SCRIPTABLE NS_IMETHOD GetRootNode(nsIDOMNode * *aRootNode) { return _to GetRootNode(aRootNode); } \
  NS_SCRIPTABLE NS_IMETHOD SetRootNode(nsIDOMNode * aRootNode) { return _to SetRootNode(aRootNode); } \
  NS_SCRIPTABLE NS_IMETHOD GetShowAnonymousContent(PRBool *aShowAnonymousContent) { return _to GetShowAnonymousContent(aShowAnonymousContent); } \
  NS_SCRIPTABLE NS_IMETHOD SetShowAnonymousContent(PRBool aShowAnonymousContent) { return _to SetShowAnonymousContent(aShowAnonymousContent); } \
  NS_SCRIPTABLE NS_IMETHOD GetShowSubDocuments(PRBool *aShowSubDocuments) { return _to GetShowSubDocuments(aShowSubDocuments); } \
  NS_SCRIPTABLE NS_IMETHOD SetShowSubDocuments(PRBool aShowSubDocuments) { return _to SetShowSubDocuments(aShowSubDocuments); } \
  NS_SCRIPTABLE NS_IMETHOD GetShowWhitespaceNodes(PRBool *aShowWhitespaceNodes) { return _to GetShowWhitespaceNodes(aShowWhitespaceNodes); } \
  NS_SCRIPTABLE NS_IMETHOD SetShowWhitespaceNodes(PRBool aShowWhitespaceNodes) { return _to SetShowWhitespaceNodes(aShowWhitespaceNodes); } \
  NS_SCRIPTABLE NS_IMETHOD GetShowAccessibleNodes(PRBool *aShowAccessibleNodes) { return _to GetShowAccessibleNodes(aShowAccessibleNodes); } \
  NS_SCRIPTABLE NS_IMETHOD SetShowAccessibleNodes(PRBool aShowAccessibleNodes) { return _to SetShowAccessibleNodes(aShowAccessibleNodes); } \
  NS_SCRIPTABLE NS_IMETHOD GetWhatToShow(PRUint32 *aWhatToShow) { return _to GetWhatToShow(aWhatToShow); } \
  NS_SCRIPTABLE NS_IMETHOD SetWhatToShow(PRUint32 aWhatToShow) { return _to SetWhatToShow(aWhatToShow); } \
  NS_SCRIPTABLE NS_IMETHOD GetNodeFromRowIndex(PRInt32 rowIndex, nsIDOMNode **_retval NS_OUTPARAM) { return _to GetNodeFromRowIndex(rowIndex, _retval); } \
  NS_SCRIPTABLE NS_IMETHOD GetRowIndexFromNode(nsIDOMNode *node, PRInt32 *_retval NS_OUTPARAM) { return _to GetRowIndexFromNode(node, _retval); } \
  NS_SCRIPTABLE NS_IMETHOD Rebuild(void) { return _to Rebuild(); } 

/* Use this macro to declare functions that forward the behavior of this interface to another object in a safe way. */
#define NS_FORWARD_SAFE_INIDOMVIEW(_to) \
  NS_SCRIPTABLE NS_IMETHOD GetRootNode(nsIDOMNode * *aRootNode) { return !_to ? NS_ERROR_NULL_POINTER : _to->GetRootNode(aRootNode); } \
  NS_SCRIPTABLE NS_IMETHOD SetRootNode(nsIDOMNode * aRootNode) { return !_to ? NS_ERROR_NULL_POINTER : _to->SetRootNode(aRootNode); } \
  NS_SCRIPTABLE NS_IMETHOD GetShowAnonymousContent(PRBool *aShowAnonymousContent) { return !_to ? NS_ERROR_NULL_POINTER : _to->GetShowAnonymousContent(aShowAnonymousContent); } \
  NS_SCRIPTABLE NS_IMETHOD SetShowAnonymousContent(PRBool aShowAnonymousContent) { return !_to ? NS_ERROR_NULL_POINTER : _to->SetShowAnonymousContent(aShowAnonymousContent); } \
  NS_SCRIPTABLE NS_IMETHOD GetShowSubDocuments(PRBool *aShowSubDocuments) { return !_to ? NS_ERROR_NULL_POINTER : _to->GetShowSubDocuments(aShowSubDocuments); } \
  NS_SCRIPTABLE NS_IMETHOD SetShowSubDocuments(PRBool aShowSubDocuments) { return !_to ? NS_ERROR_NULL_POINTER : _to->SetShowSubDocuments(aShowSubDocuments); } \
  NS_SCRIPTABLE NS_IMETHOD GetShowWhitespaceNodes(PRBool *aShowWhitespaceNodes) { return !_to ? NS_ERROR_NULL_POINTER : _to->GetShowWhitespaceNodes(aShowWhitespaceNodes); } \
  NS_SCRIPTABLE NS_IMETHOD SetShowWhitespaceNodes(PRBool aShowWhitespaceNodes) { return !_to ? NS_ERROR_NULL_POINTER : _to->SetShowWhitespaceNodes(aShowWhitespaceNodes); } \
  NS_SCRIPTABLE NS_IMETHOD GetShowAccessibleNodes(PRBool *aShowAccessibleNodes) { return !_to ? NS_ERROR_NULL_POINTER : _to->GetShowAccessibleNodes(aShowAccessibleNodes); } \
  NS_SCRIPTABLE NS_IMETHOD SetShowAccessibleNodes(PRBool aShowAccessibleNodes) { return !_to ? NS_ERROR_NULL_POINTER : _to->SetShowAccessibleNodes(aShowAccessibleNodes); } \
  NS_SCRIPTABLE NS_IMETHOD GetWhatToShow(PRUint32 *aWhatToShow) { return !_to ? NS_ERROR_NULL_POINTER : _to->GetWhatToShow(aWhatToShow); } \
  NS_SCRIPTABLE NS_IMETHOD SetWhatToShow(PRUint32 aWhatToShow) { return !_to ? NS_ERROR_NULL_POINTER : _to->SetWhatToShow(aWhatToShow); } \
  NS_SCRIPTABLE NS_IMETHOD GetNodeFromRowIndex(PRInt32 rowIndex, nsIDOMNode **_retval NS_OUTPARAM) { return !_to ? NS_ERROR_NULL_POINTER : _to->GetNodeFromRowIndex(rowIndex, _retval); } \
  NS_SCRIPTABLE NS_IMETHOD GetRowIndexFromNode(nsIDOMNode *node, PRInt32 *_retval NS_OUTPARAM) { return !_to ? NS_ERROR_NULL_POINTER : _to->GetRowIndexFromNode(node, _retval); } \
  NS_SCRIPTABLE NS_IMETHOD Rebuild(void) { return !_to ? NS_ERROR_NULL_POINTER : _to->Rebuild(); } 

#if 0
/* Use the code below as a template for the implementation class for this interface. */

/* Header file */
class inDOMView : public inIDOMView
{
public:
  NS_DECL_ISUPPORTS
  NS_DECL_INIDOMVIEW

  inDOMView();

private:
  ~inDOMView();

protected:
  /* additional members */
};

/* Implementation file */
NS_IMPL_ISUPPORTS1(inDOMView, inIDOMView)

inDOMView::inDOMView()
{
  /* member initializers and constructor code */
}

inDOMView::~inDOMView()
{
  /* destructor code */
}

/* attribute nsIDOMNode rootNode; */
NS_IMETHODIMP inDOMView::GetRootNode(nsIDOMNode * *aRootNode)
{
    return NS_ERROR_NOT_IMPLEMENTED;
}
NS_IMETHODIMP inDOMView::SetRootNode(nsIDOMNode * aRootNode)
{
    return NS_ERROR_NOT_IMPLEMENTED;
}

/* attribute boolean showAnonymousContent; */
NS_IMETHODIMP inDOMView::GetShowAnonymousContent(PRBool *aShowAnonymousContent)
{
    return NS_ERROR_NOT_IMPLEMENTED;
}
NS_IMETHODIMP inDOMView::SetShowAnonymousContent(PRBool aShowAnonymousContent)
{
    return NS_ERROR_NOT_IMPLEMENTED;
}

/* attribute boolean showSubDocuments; */
NS_IMETHODIMP inDOMView::GetShowSubDocuments(PRBool *aShowSubDocuments)
{
    return NS_ERROR_NOT_IMPLEMENTED;
}
NS_IMETHODIMP inDOMView::SetShowSubDocuments(PRBool aShowSubDocuments)
{
    return NS_ERROR_NOT_IMPLEMENTED;
}

/* attribute boolean showWhitespaceNodes; */
NS_IMETHODIMP inDOMView::GetShowWhitespaceNodes(PRBool *aShowWhitespaceNodes)
{
    return NS_ERROR_NOT_IMPLEMENTED;
}
NS_IMETHODIMP inDOMView::SetShowWhitespaceNodes(PRBool aShowWhitespaceNodes)
{
    return NS_ERROR_NOT_IMPLEMENTED;
}

/* attribute boolean showAccessibleNodes; */
NS_IMETHODIMP inDOMView::GetShowAccessibleNodes(PRBool *aShowAccessibleNodes)
{
    return NS_ERROR_NOT_IMPLEMENTED;
}
NS_IMETHODIMP inDOMView::SetShowAccessibleNodes(PRBool aShowAccessibleNodes)
{
    return NS_ERROR_NOT_IMPLEMENTED;
}

/* attribute unsigned long whatToShow; */
NS_IMETHODIMP inDOMView::GetWhatToShow(PRUint32 *aWhatToShow)
{
    return NS_ERROR_NOT_IMPLEMENTED;
}
NS_IMETHODIMP inDOMView::SetWhatToShow(PRUint32 aWhatToShow)
{
    return NS_ERROR_NOT_IMPLEMENTED;
}

/* nsIDOMNode getNodeFromRowIndex (in long rowIndex); */
NS_IMETHODIMP inDOMView::GetNodeFromRowIndex(PRInt32 rowIndex, nsIDOMNode **_retval NS_OUTPARAM)
{
    return NS_ERROR_NOT_IMPLEMENTED;
}

/* long getRowIndexFromNode (in nsIDOMNode node); */
NS_IMETHODIMP inDOMView::GetRowIndexFromNode(nsIDOMNode *node, PRInt32 *_retval NS_OUTPARAM)
{
    return NS_ERROR_NOT_IMPLEMENTED;
}

/* void rebuild (); */
NS_IMETHODIMP inDOMView::Rebuild()
{
    return NS_ERROR_NOT_IMPLEMENTED;
}

/* End of implementation class template. */
#endif


#endif /* __gen_inIDOMView_h__ */
