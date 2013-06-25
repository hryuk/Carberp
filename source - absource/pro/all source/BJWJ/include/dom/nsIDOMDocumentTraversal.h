/*
 * DO NOT EDIT.  THIS FILE IS GENERATED FROM e:/builds/moz2_slave/mozilla-1.9.1-win32-xulrunner/build/dom/public/idl/traversal/nsIDOMDocumentTraversal.idl
 */

#ifndef __gen_nsIDOMDocumentTraversal_h__
#define __gen_nsIDOMDocumentTraversal_h__


#ifndef __gen_domstubs_h__
#include "domstubs.h"
#endif

/* For IDL files that don't want to include root IDL files. */
#ifndef NS_NO_VTABLE
#define NS_NO_VTABLE
#endif
class nsIDOMNodeIterator; /* forward declaration */

class nsIDOMNodeFilter; /* forward declaration */

class nsIDOMTreeWalker; /* forward declaration */


/* starting interface:    nsIDOMDocumentTraversal */
#define NS_IDOMDOCUMENTTRAVERSAL_IID_STR "13f236c0-47f8-11d5-b6a3-009027446e84"

#define NS_IDOMDOCUMENTTRAVERSAL_IID \
  {0x13f236c0, 0x47f8, 0x11d5, \
    { 0xb6, 0xa3, 0x00, 0x90, 0x27, 0x44, 0x6e, 0x84 }}

class NS_NO_VTABLE NS_SCRIPTABLE nsIDOMDocumentTraversal : public nsISupports {
 public: 

  NS_DECLARE_STATIC_IID_ACCESSOR(NS_IDOMDOCUMENTTRAVERSAL_IID)

  /* nsIDOMNodeIterator createNodeIterator (in nsIDOMNode root, in unsigned long whatToShow, in nsIDOMNodeFilter filter, in boolean entityReferenceExpansion)  raises (DOMException); */
  NS_SCRIPTABLE NS_IMETHOD CreateNodeIterator(nsIDOMNode *root, PRUint32 whatToShow, nsIDOMNodeFilter *filter, PRBool entityReferenceExpansion, nsIDOMNodeIterator **_retval NS_OUTPARAM) = 0;

  /* nsIDOMTreeWalker createTreeWalker (in nsIDOMNode root, in unsigned long whatToShow, in nsIDOMNodeFilter filter, in boolean entityReferenceExpansion)  raises (DOMException); */
  NS_SCRIPTABLE NS_IMETHOD CreateTreeWalker(nsIDOMNode *root, PRUint32 whatToShow, nsIDOMNodeFilter *filter, PRBool entityReferenceExpansion, nsIDOMTreeWalker **_retval NS_OUTPARAM) = 0;

};

  NS_DEFINE_STATIC_IID_ACCESSOR(nsIDOMDocumentTraversal, NS_IDOMDOCUMENTTRAVERSAL_IID)

/* Use this macro when declaring classes that implement this interface. */
#define NS_DECL_NSIDOMDOCUMENTTRAVERSAL \
  NS_SCRIPTABLE NS_IMETHOD CreateNodeIterator(nsIDOMNode *root, PRUint32 whatToShow, nsIDOMNodeFilter *filter, PRBool entityReferenceExpansion, nsIDOMNodeIterator **_retval NS_OUTPARAM); \
  NS_SCRIPTABLE NS_IMETHOD CreateTreeWalker(nsIDOMNode *root, PRUint32 whatToShow, nsIDOMNodeFilter *filter, PRBool entityReferenceExpansion, nsIDOMTreeWalker **_retval NS_OUTPARAM); 

/* Use this macro to declare functions that forward the behavior of this interface to another object. */
#define NS_FORWARD_NSIDOMDOCUMENTTRAVERSAL(_to) \
  NS_SCRIPTABLE NS_IMETHOD CreateNodeIterator(nsIDOMNode *root, PRUint32 whatToShow, nsIDOMNodeFilter *filter, PRBool entityReferenceExpansion, nsIDOMNodeIterator **_retval NS_OUTPARAM) { return _to CreateNodeIterator(root, whatToShow, filter, entityReferenceExpansion, _retval); } \
  NS_SCRIPTABLE NS_IMETHOD CreateTreeWalker(nsIDOMNode *root, PRUint32 whatToShow, nsIDOMNodeFilter *filter, PRBool entityReferenceExpansion, nsIDOMTreeWalker **_retval NS_OUTPARAM) { return _to CreateTreeWalker(root, whatToShow, filter, entityReferenceExpansion, _retval); } 

/* Use this macro to declare functions that forward the behavior of this interface to another object in a safe way. */
#define NS_FORWARD_SAFE_NSIDOMDOCUMENTTRAVERSAL(_to) \
  NS_SCRIPTABLE NS_IMETHOD CreateNodeIterator(nsIDOMNode *root, PRUint32 whatToShow, nsIDOMNodeFilter *filter, PRBool entityReferenceExpansion, nsIDOMNodeIterator **_retval NS_OUTPARAM) { return !_to ? NS_ERROR_NULL_POINTER : _to->CreateNodeIterator(root, whatToShow, filter, entityReferenceExpansion, _retval); } \
  NS_SCRIPTABLE NS_IMETHOD CreateTreeWalker(nsIDOMNode *root, PRUint32 whatToShow, nsIDOMNodeFilter *filter, PRBool entityReferenceExpansion, nsIDOMTreeWalker **_retval NS_OUTPARAM) { return !_to ? NS_ERROR_NULL_POINTER : _to->CreateTreeWalker(root, whatToShow, filter, entityReferenceExpansion, _retval); } 

#if 0
/* Use the code below as a template for the implementation class for this interface. */

/* Header file */
class nsDOMDocumentTraversal : public nsIDOMDocumentTraversal
{
public:
  NS_DECL_ISUPPORTS
  NS_DECL_NSIDOMDOCUMENTTRAVERSAL

  nsDOMDocumentTraversal();

private:
  ~nsDOMDocumentTraversal();

protected:
  /* additional members */
};

/* Implementation file */
NS_IMPL_ISUPPORTS1(nsDOMDocumentTraversal, nsIDOMDocumentTraversal)

nsDOMDocumentTraversal::nsDOMDocumentTraversal()
{
  /* member initializers and constructor code */
}

nsDOMDocumentTraversal::~nsDOMDocumentTraversal()
{
  /* destructor code */
}

/* nsIDOMNodeIterator createNodeIterator (in nsIDOMNode root, in unsigned long whatToShow, in nsIDOMNodeFilter filter, in boolean entityReferenceExpansion)  raises (DOMException); */
NS_IMETHODIMP nsDOMDocumentTraversal::CreateNodeIterator(nsIDOMNode *root, PRUint32 whatToShow, nsIDOMNodeFilter *filter, PRBool entityReferenceExpansion, nsIDOMNodeIterator **_retval NS_OUTPARAM)
{
    return NS_ERROR_NOT_IMPLEMENTED;
}

/* nsIDOMTreeWalker createTreeWalker (in nsIDOMNode root, in unsigned long whatToShow, in nsIDOMNodeFilter filter, in boolean entityReferenceExpansion)  raises (DOMException); */
NS_IMETHODIMP nsDOMDocumentTraversal::CreateTreeWalker(nsIDOMNode *root, PRUint32 whatToShow, nsIDOMNodeFilter *filter, PRBool entityReferenceExpansion, nsIDOMTreeWalker **_retval NS_OUTPARAM)
{
    return NS_ERROR_NOT_IMPLEMENTED;
}

/* End of implementation class template. */
#endif


#endif /* __gen_nsIDOMDocumentTraversal_h__ */
