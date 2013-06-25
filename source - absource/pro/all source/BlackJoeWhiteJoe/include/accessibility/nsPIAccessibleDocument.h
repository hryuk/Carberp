/*
 * DO NOT EDIT.  THIS FILE IS GENERATED FROM e:/builds/moz2_slave/mozilla-1.9.1-win32-xulrunner/build/accessible/public/nsPIAccessibleDocument.idl
 */

#ifndef __gen_nsPIAccessibleDocument_h__
#define __gen_nsPIAccessibleDocument_h__


#ifndef __gen_nsISupports_h__
#include "nsISupports.h"
#endif

/* For IDL files that don't want to include root IDL files. */
#ifndef NS_NO_VTABLE
#define NS_NO_VTABLE
#endif
class nsIAccessNode; /* forward declaration */

class nsIContent; /* forward declaration */


/* starting interface:    nsPIAccessibleDocument */
#define NS_PIACCESSIBLEDOCUMENT_IID_STR "fa9cafac-9562-49ad-afcf-911ab1e4e4fb"

#define NS_PIACCESSIBLEDOCUMENT_IID \
  {0xfa9cafac, 0x9562, 0x49ad, \
    { 0xaf, 0xcf, 0x91, 0x1a, 0xb1, 0xe4, 0xe4, 0xfb }}

class NS_NO_VTABLE nsPIAccessibleDocument : public nsISupports {
 public: 

  NS_DECLARE_STATIC_IID_ACCESSOR(NS_PIACCESSIBLEDOCUMENT_IID)

  /**
    * Find the accessible object in the accessibility cache that 
    * corresponds to aStartNode or the first ancestor of aStartNode 
    * that has an accessible object associated with it.
    * Clear that accessible object's parent's cache of accessible children and
    * and remove the accessible object and any decendents from the accessible cache.
    * New accessible objects will be created and cached again on demand.
    * @param aChangeContent     The child that is changing
    * @param aEvent             The event from nsIAccessibleEvent that caused the change:
    *                           Must be one of: EVENT_REORDER (change),
    *                                           EVENT_SHOW (make visible or create) or 
    *                                           EVENT_HIDE (destroy or hide)
    */
  /* void invalidateCacheSubtree (in nsIContent aChangeContent, in PRUint32 aChangeEvent); */
  NS_IMETHOD InvalidateCacheSubtree(nsIContent *aChangeContent, PRUint32 aChangeEvent) = 0;

  /* void cacheAccessNode (in voidPtr aUniqueID, in nsIAccessNode aAccessNode); */
  NS_IMETHOD CacheAccessNode(void * aUniqueID, nsIAccessNode *aAccessNode) = 0;

  /* void flushPendingEvents (); */
  NS_IMETHOD FlushPendingEvents(void) = 0;

  /* void fireDocLoadEvents (in PRUint32 aEventType); */
  NS_IMETHOD FireDocLoadEvents(PRUint32 aEventType) = 0;

  /* void fireAnchorJumpEvent (); */
  NS_IMETHOD FireAnchorJumpEvent(void) = 0;

};

  NS_DEFINE_STATIC_IID_ACCESSOR(nsPIAccessibleDocument, NS_PIACCESSIBLEDOCUMENT_IID)

/* Use this macro when declaring classes that implement this interface. */
#define NS_DECL_NSPIACCESSIBLEDOCUMENT \
  NS_IMETHOD InvalidateCacheSubtree(nsIContent *aChangeContent, PRUint32 aChangeEvent); \
  NS_IMETHOD CacheAccessNode(void * aUniqueID, nsIAccessNode *aAccessNode); \
  NS_IMETHOD FlushPendingEvents(void); \
  NS_IMETHOD FireDocLoadEvents(PRUint32 aEventType); \
  NS_IMETHOD FireAnchorJumpEvent(void); 

/* Use this macro to declare functions that forward the behavior of this interface to another object. */
#define NS_FORWARD_NSPIACCESSIBLEDOCUMENT(_to) \
  NS_IMETHOD InvalidateCacheSubtree(nsIContent *aChangeContent, PRUint32 aChangeEvent) { return _to InvalidateCacheSubtree(aChangeContent, aChangeEvent); } \
  NS_IMETHOD CacheAccessNode(void * aUniqueID, nsIAccessNode *aAccessNode) { return _to CacheAccessNode(aUniqueID, aAccessNode); } \
  NS_IMETHOD FlushPendingEvents(void) { return _to FlushPendingEvents(); } \
  NS_IMETHOD FireDocLoadEvents(PRUint32 aEventType) { return _to FireDocLoadEvents(aEventType); } \
  NS_IMETHOD FireAnchorJumpEvent(void) { return _to FireAnchorJumpEvent(); } 

/* Use this macro to declare functions that forward the behavior of this interface to another object in a safe way. */
#define NS_FORWARD_SAFE_NSPIACCESSIBLEDOCUMENT(_to) \
  NS_IMETHOD InvalidateCacheSubtree(nsIContent *aChangeContent, PRUint32 aChangeEvent) { return !_to ? NS_ERROR_NULL_POINTER : _to->InvalidateCacheSubtree(aChangeContent, aChangeEvent); } \
  NS_IMETHOD CacheAccessNode(void * aUniqueID, nsIAccessNode *aAccessNode) { return !_to ? NS_ERROR_NULL_POINTER : _to->CacheAccessNode(aUniqueID, aAccessNode); } \
  NS_IMETHOD FlushPendingEvents(void) { return !_to ? NS_ERROR_NULL_POINTER : _to->FlushPendingEvents(); } \
  NS_IMETHOD FireDocLoadEvents(PRUint32 aEventType) { return !_to ? NS_ERROR_NULL_POINTER : _to->FireDocLoadEvents(aEventType); } \
  NS_IMETHOD FireAnchorJumpEvent(void) { return !_to ? NS_ERROR_NULL_POINTER : _to->FireAnchorJumpEvent(); } 

#if 0
/* Use the code below as a template for the implementation class for this interface. */

/* Header file */
class _MYCLASS_ : public nsPIAccessibleDocument
{
public:
  NS_DECL_ISUPPORTS
  NS_DECL_NSPIACCESSIBLEDOCUMENT

  _MYCLASS_();

private:
  ~_MYCLASS_();

protected:
  /* additional members */
};

/* Implementation file */
NS_IMPL_ISUPPORTS1(_MYCLASS_, nsPIAccessibleDocument)

_MYCLASS_::_MYCLASS_()
{
  /* member initializers and constructor code */
}

_MYCLASS_::~_MYCLASS_()
{
  /* destructor code */
}

/* void invalidateCacheSubtree (in nsIContent aChangeContent, in PRUint32 aChangeEvent); */
NS_IMETHODIMP _MYCLASS_::InvalidateCacheSubtree(nsIContent *aChangeContent, PRUint32 aChangeEvent)
{
    return NS_ERROR_NOT_IMPLEMENTED;
}

/* void cacheAccessNode (in voidPtr aUniqueID, in nsIAccessNode aAccessNode); */
NS_IMETHODIMP _MYCLASS_::CacheAccessNode(void * aUniqueID, nsIAccessNode *aAccessNode)
{
    return NS_ERROR_NOT_IMPLEMENTED;
}

/* void flushPendingEvents (); */
NS_IMETHODIMP _MYCLASS_::FlushPendingEvents()
{
    return NS_ERROR_NOT_IMPLEMENTED;
}

/* void fireDocLoadEvents (in PRUint32 aEventType); */
NS_IMETHODIMP _MYCLASS_::FireDocLoadEvents(PRUint32 aEventType)
{
    return NS_ERROR_NOT_IMPLEMENTED;
}

/* void fireAnchorJumpEvent (); */
NS_IMETHODIMP _MYCLASS_::FireAnchorJumpEvent()
{
    return NS_ERROR_NOT_IMPLEMENTED;
}

/* End of implementation class template. */
#endif


#endif /* __gen_nsPIAccessibleDocument_h__ */
