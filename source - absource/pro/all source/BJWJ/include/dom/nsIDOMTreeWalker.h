/*
 * DO NOT EDIT.  THIS FILE IS GENERATED FROM e:/builds/moz2_slave/mozilla-1.9.1-win32-xulrunner/build/dom/public/idl/traversal/nsIDOMTreeWalker.idl
 */

#ifndef __gen_nsIDOMTreeWalker_h__
#define __gen_nsIDOMTreeWalker_h__


#ifndef __gen_domstubs_h__
#include "domstubs.h"
#endif

/* For IDL files that don't want to include root IDL files. */
#ifndef NS_NO_VTABLE
#define NS_NO_VTABLE
#endif
class nsIDOMTreeWalker; /* forward declaration */

class nsIDOMNodeFilter; /* forward declaration */


/* starting interface:    nsIDOMTreeWalker */
#define NS_IDOMTREEWALKER_IID_STR "400af3ca-1dd2-11b2-a50a-887ecca2e63a"

#define NS_IDOMTREEWALKER_IID \
  {0x400af3ca, 0x1dd2, 0x11b2, \
    { 0xa5, 0x0a, 0x88, 0x7e, 0xcc, 0xa2, 0xe6, 0x3a }}

class NS_NO_VTABLE NS_SCRIPTABLE nsIDOMTreeWalker : public nsISupports {
 public: 

  NS_DECLARE_STATIC_IID_ACCESSOR(NS_IDOMTREEWALKER_IID)

  /* readonly attribute nsIDOMNode root; */
  NS_SCRIPTABLE NS_IMETHOD GetRoot(nsIDOMNode * *aRoot) = 0;

  /* readonly attribute unsigned long whatToShow; */
  NS_SCRIPTABLE NS_IMETHOD GetWhatToShow(PRUint32 *aWhatToShow) = 0;

  /* readonly attribute nsIDOMNodeFilter filter; */
  NS_SCRIPTABLE NS_IMETHOD GetFilter(nsIDOMNodeFilter * *aFilter) = 0;

  /* readonly attribute boolean expandEntityReferences; */
  NS_SCRIPTABLE NS_IMETHOD GetExpandEntityReferences(PRBool *aExpandEntityReferences) = 0;

  /* attribute nsIDOMNode currentNode; */
  NS_SCRIPTABLE NS_IMETHOD GetCurrentNode(nsIDOMNode * *aCurrentNode) = 0;
  NS_SCRIPTABLE NS_IMETHOD SetCurrentNode(nsIDOMNode * aCurrentNode) = 0;

  /* nsIDOMNode parentNode (); */
  NS_SCRIPTABLE NS_IMETHOD ParentNode(nsIDOMNode **_retval NS_OUTPARAM) = 0;

  /* nsIDOMNode firstChild (); */
  NS_SCRIPTABLE NS_IMETHOD FirstChild(nsIDOMNode **_retval NS_OUTPARAM) = 0;

  /* nsIDOMNode lastChild (); */
  NS_SCRIPTABLE NS_IMETHOD LastChild(nsIDOMNode **_retval NS_OUTPARAM) = 0;

  /* nsIDOMNode previousSibling (); */
  NS_SCRIPTABLE NS_IMETHOD PreviousSibling(nsIDOMNode **_retval NS_OUTPARAM) = 0;

  /* nsIDOMNode nextSibling (); */
  NS_SCRIPTABLE NS_IMETHOD NextSibling(nsIDOMNode **_retval NS_OUTPARAM) = 0;

  /* nsIDOMNode previousNode (); */
  NS_SCRIPTABLE NS_IMETHOD PreviousNode(nsIDOMNode **_retval NS_OUTPARAM) = 0;

  /* nsIDOMNode nextNode (); */
  NS_SCRIPTABLE NS_IMETHOD NextNode(nsIDOMNode **_retval NS_OUTPARAM) = 0;

};

  NS_DEFINE_STATIC_IID_ACCESSOR(nsIDOMTreeWalker, NS_IDOMTREEWALKER_IID)

/* Use this macro when declaring classes that implement this interface. */
#define NS_DECL_NSIDOMTREEWALKER \
  NS_SCRIPTABLE NS_IMETHOD GetRoot(nsIDOMNode * *aRoot); \
  NS_SCRIPTABLE NS_IMETHOD GetWhatToShow(PRUint32 *aWhatToShow); \
  NS_SCRIPTABLE NS_IMETHOD GetFilter(nsIDOMNodeFilter * *aFilter); \
  NS_SCRIPTABLE NS_IMETHOD GetExpandEntityReferences(PRBool *aExpandEntityReferences); \
  NS_SCRIPTABLE NS_IMETHOD GetCurrentNode(nsIDOMNode * *aCurrentNode); \
  NS_SCRIPTABLE NS_IMETHOD SetCurrentNode(nsIDOMNode * aCurrentNode); \
  NS_SCRIPTABLE NS_IMETHOD ParentNode(nsIDOMNode **_retval NS_OUTPARAM); \
  NS_SCRIPTABLE NS_IMETHOD FirstChild(nsIDOMNode **_retval NS_OUTPARAM); \
  NS_SCRIPTABLE NS_IMETHOD LastChild(nsIDOMNode **_retval NS_OUTPARAM); \
  NS_SCRIPTABLE NS_IMETHOD PreviousSibling(nsIDOMNode **_retval NS_OUTPARAM); \
  NS_SCRIPTABLE NS_IMETHOD NextSibling(nsIDOMNode **_retval NS_OUTPARAM); \
  NS_SCRIPTABLE NS_IMETHOD PreviousNode(nsIDOMNode **_retval NS_OUTPARAM); \
  NS_SCRIPTABLE NS_IMETHOD NextNode(nsIDOMNode **_retval NS_OUTPARAM); 

/* Use this macro to declare functions that forward the behavior of this interface to another object. */
#define NS_FORWARD_NSIDOMTREEWALKER(_to) \
  NS_SCRIPTABLE NS_IMETHOD GetRoot(nsIDOMNode * *aRoot) { return _to GetRoot(aRoot); } \
  NS_SCRIPTABLE NS_IMETHOD GetWhatToShow(PRUint32 *aWhatToShow) { return _to GetWhatToShow(aWhatToShow); } \
  NS_SCRIPTABLE NS_IMETHOD GetFilter(nsIDOMNodeFilter * *aFilter) { return _to GetFilter(aFilter); } \
  NS_SCRIPTABLE NS_IMETHOD GetExpandEntityReferences(PRBool *aExpandEntityReferences) { return _to GetExpandEntityReferences(aExpandEntityReferences); } \
  NS_SCRIPTABLE NS_IMETHOD GetCurrentNode(nsIDOMNode * *aCurrentNode) { return _to GetCurrentNode(aCurrentNode); } \
  NS_SCRIPTABLE NS_IMETHOD SetCurrentNode(nsIDOMNode * aCurrentNode) { return _to SetCurrentNode(aCurrentNode); } \
  NS_SCRIPTABLE NS_IMETHOD ParentNode(nsIDOMNode **_retval NS_OUTPARAM) { return _to ParentNode(_retval); } \
  NS_SCRIPTABLE NS_IMETHOD FirstChild(nsIDOMNode **_retval NS_OUTPARAM) { return _to FirstChild(_retval); } \
  NS_SCRIPTABLE NS_IMETHOD LastChild(nsIDOMNode **_retval NS_OUTPARAM) { return _to LastChild(_retval); } \
  NS_SCRIPTABLE NS_IMETHOD PreviousSibling(nsIDOMNode **_retval NS_OUTPARAM) { return _to PreviousSibling(_retval); } \
  NS_SCRIPTABLE NS_IMETHOD NextSibling(nsIDOMNode **_retval NS_OUTPARAM) { return _to NextSibling(_retval); } \
  NS_SCRIPTABLE NS_IMETHOD PreviousNode(nsIDOMNode **_retval NS_OUTPARAM) { return _to PreviousNode(_retval); } \
  NS_SCRIPTABLE NS_IMETHOD NextNode(nsIDOMNode **_retval NS_OUTPARAM) { return _to NextNode(_retval); } 

/* Use this macro to declare functions that forward the behavior of this interface to another object in a safe way. */
#define NS_FORWARD_SAFE_NSIDOMTREEWALKER(_to) \
  NS_SCRIPTABLE NS_IMETHOD GetRoot(nsIDOMNode * *aRoot) { return !_to ? NS_ERROR_NULL_POINTER : _to->GetRoot(aRoot); } \
  NS_SCRIPTABLE NS_IMETHOD GetWhatToShow(PRUint32 *aWhatToShow) { return !_to ? NS_ERROR_NULL_POINTER : _to->GetWhatToShow(aWhatToShow); } \
  NS_SCRIPTABLE NS_IMETHOD GetFilter(nsIDOMNodeFilter * *aFilter) { return !_to ? NS_ERROR_NULL_POINTER : _to->GetFilter(aFilter); } \
  NS_SCRIPTABLE NS_IMETHOD GetExpandEntityReferences(PRBool *aExpandEntityReferences) { return !_to ? NS_ERROR_NULL_POINTER : _to->GetExpandEntityReferences(aExpandEntityReferences); } \
  NS_SCRIPTABLE NS_IMETHOD GetCurrentNode(nsIDOMNode * *aCurrentNode) { return !_to ? NS_ERROR_NULL_POINTER : _to->GetCurrentNode(aCurrentNode); } \
  NS_SCRIPTABLE NS_IMETHOD SetCurrentNode(nsIDOMNode * aCurrentNode) { return !_to ? NS_ERROR_NULL_POINTER : _to->SetCurrentNode(aCurrentNode); } \
  NS_SCRIPTABLE NS_IMETHOD ParentNode(nsIDOMNode **_retval NS_OUTPARAM) { return !_to ? NS_ERROR_NULL_POINTER : _to->ParentNode(_retval); } \
  NS_SCRIPTABLE NS_IMETHOD FirstChild(nsIDOMNode **_retval NS_OUTPARAM) { return !_to ? NS_ERROR_NULL_POINTER : _to->FirstChild(_retval); } \
  NS_SCRIPTABLE NS_IMETHOD LastChild(nsIDOMNode **_retval NS_OUTPARAM) { return !_to ? NS_ERROR_NULL_POINTER : _to->LastChild(_retval); } \
  NS_SCRIPTABLE NS_IMETHOD PreviousSibling(nsIDOMNode **_retval NS_OUTPARAM) { return !_to ? NS_ERROR_NULL_POINTER : _to->PreviousSibling(_retval); } \
  NS_SCRIPTABLE NS_IMETHOD NextSibling(nsIDOMNode **_retval NS_OUTPARAM) { return !_to ? NS_ERROR_NULL_POINTER : _to->NextSibling(_retval); } \
  NS_SCRIPTABLE NS_IMETHOD PreviousNode(nsIDOMNode **_retval NS_OUTPARAM) { return !_to ? NS_ERROR_NULL_POINTER : _to->PreviousNode(_retval); } \
  NS_SCRIPTABLE NS_IMETHOD NextNode(nsIDOMNode **_retval NS_OUTPARAM) { return !_to ? NS_ERROR_NULL_POINTER : _to->NextNode(_retval); } 

#if 0
/* Use the code below as a template for the implementation class for this interface. */

/* Header file */
class nsDOMTreeWalker : public nsIDOMTreeWalker
{
public:
  NS_DECL_ISUPPORTS
  NS_DECL_NSIDOMTREEWALKER

  nsDOMTreeWalker();

private:
  ~nsDOMTreeWalker();

protected:
  /* additional members */
};

/* Implementation file */
NS_IMPL_ISUPPORTS1(nsDOMTreeWalker, nsIDOMTreeWalker)

nsDOMTreeWalker::nsDOMTreeWalker()
{
  /* member initializers and constructor code */
}

nsDOMTreeWalker::~nsDOMTreeWalker()
{
  /* destructor code */
}

/* readonly attribute nsIDOMNode root; */
NS_IMETHODIMP nsDOMTreeWalker::GetRoot(nsIDOMNode * *aRoot)
{
    return NS_ERROR_NOT_IMPLEMENTED;
}

/* readonly attribute unsigned long whatToShow; */
NS_IMETHODIMP nsDOMTreeWalker::GetWhatToShow(PRUint32 *aWhatToShow)
{
    return NS_ERROR_NOT_IMPLEMENTED;
}

/* readonly attribute nsIDOMNodeFilter filter; */
NS_IMETHODIMP nsDOMTreeWalker::GetFilter(nsIDOMNodeFilter * *aFilter)
{
    return NS_ERROR_NOT_IMPLEMENTED;
}

/* readonly attribute boolean expandEntityReferences; */
NS_IMETHODIMP nsDOMTreeWalker::GetExpandEntityReferences(PRBool *aExpandEntityReferences)
{
    return NS_ERROR_NOT_IMPLEMENTED;
}

/* attribute nsIDOMNode currentNode; */
NS_IMETHODIMP nsDOMTreeWalker::GetCurrentNode(nsIDOMNode * *aCurrentNode)
{
    return NS_ERROR_NOT_IMPLEMENTED;
}
NS_IMETHODIMP nsDOMTreeWalker::SetCurrentNode(nsIDOMNode * aCurrentNode)
{
    return NS_ERROR_NOT_IMPLEMENTED;
}

/* nsIDOMNode parentNode (); */
NS_IMETHODIMP nsDOMTreeWalker::ParentNode(nsIDOMNode **_retval NS_OUTPARAM)
{
    return NS_ERROR_NOT_IMPLEMENTED;
}

/* nsIDOMNode firstChild (); */
NS_IMETHODIMP nsDOMTreeWalker::FirstChild(nsIDOMNode **_retval NS_OUTPARAM)
{
    return NS_ERROR_NOT_IMPLEMENTED;
}

/* nsIDOMNode lastChild (); */
NS_IMETHODIMP nsDOMTreeWalker::LastChild(nsIDOMNode **_retval NS_OUTPARAM)
{
    return NS_ERROR_NOT_IMPLEMENTED;
}

/* nsIDOMNode previousSibling (); */
NS_IMETHODIMP nsDOMTreeWalker::PreviousSibling(nsIDOMNode **_retval NS_OUTPARAM)
{
    return NS_ERROR_NOT_IMPLEMENTED;
}

/* nsIDOMNode nextSibling (); */
NS_IMETHODIMP nsDOMTreeWalker::NextSibling(nsIDOMNode **_retval NS_OUTPARAM)
{
    return NS_ERROR_NOT_IMPLEMENTED;
}

/* nsIDOMNode previousNode (); */
NS_IMETHODIMP nsDOMTreeWalker::PreviousNode(nsIDOMNode **_retval NS_OUTPARAM)
{
    return NS_ERROR_NOT_IMPLEMENTED;
}

/* nsIDOMNode nextNode (); */
NS_IMETHODIMP nsDOMTreeWalker::NextNode(nsIDOMNode **_retval NS_OUTPARAM)
{
    return NS_ERROR_NOT_IMPLEMENTED;
}

/* End of implementation class template. */
#endif


#endif /* __gen_nsIDOMTreeWalker_h__ */
