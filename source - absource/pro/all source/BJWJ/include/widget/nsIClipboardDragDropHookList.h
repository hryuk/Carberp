/*
 * DO NOT EDIT.  THIS FILE IS GENERATED FROM e:/builds/moz2_slave/mozilla-1.9.1-win32-xulrunner/build/widget/public/nsIClipboardDragDropHookList.idl
 */

#ifndef __gen_nsIClipboardDragDropHookList_h__
#define __gen_nsIClipboardDragDropHookList_h__


#ifndef __gen_nsISupports_h__
#include "nsISupports.h"
#endif

/* For IDL files that don't want to include root IDL files. */
#ifndef NS_NO_VTABLE
#define NS_NO_VTABLE
#endif
class nsIClipboardDragDropHooks; /* forward declaration */

class nsISimpleEnumerator; /* forward declaration */


/* starting interface:    nsIClipboardDragDropHookList */
#define NS_ICLIPBOARDDRAGDROPHOOKLIST_IID_STR "876a2015-6b66-11d7-8f18-0003938a9d96"

#define NS_ICLIPBOARDDRAGDROPHOOKLIST_IID \
  {0x876a2015, 0x6b66, 0x11d7, \
    { 0x8f, 0x18, 0x00, 0x03, 0x93, 0x8a, 0x9d, 0x96 }}

/**
 * Please note that the following api is not intended for embedders;
 * it is intended as an internal (to gecko).  Embedders can indirectly
 * call these by sending commands (see description in 
 * nsIClipboardDragDropHooks.idl).
 *
 * Internal gecko usage is accomplished by calling get_Interface on a
 * docshell.
 */
class NS_NO_VTABLE NS_SCRIPTABLE nsIClipboardDragDropHookList : public nsISupports {
 public: 

  NS_DECLARE_STATIC_IID_ACCESSOR(NS_ICLIPBOARDDRAGDROPHOOKLIST_IID)

  /**
   * Add a hook to list.
   * @param aHooks  implementation of hooks
   */
  /* void addClipboardDragDropHooks (in nsIClipboardDragDropHooks aHooks); */
  NS_SCRIPTABLE NS_IMETHOD AddClipboardDragDropHooks(nsIClipboardDragDropHooks *aHooks) = 0;

  /**
   * Remove a hook from list (note if this implementation is not present
   * in the list then removal will be ignored).
   * @param aHooks  implementation of hooks
   */
  /* void removeClipboardDragDropHooks (in nsIClipboardDragDropHooks aHooks); */
  NS_SCRIPTABLE NS_IMETHOD RemoveClipboardDragDropHooks(nsIClipboardDragDropHooks *aHooks) = 0;

  /**
   * Gets an enumerator for all hooks which have been added.
   * @return nsISimpleEnumerator for nsIClipboardDragDropHooks
   */
  /* nsISimpleEnumerator getHookEnumerator (); */
  NS_SCRIPTABLE NS_IMETHOD GetHookEnumerator(nsISimpleEnumerator **_retval NS_OUTPARAM) = 0;

};

  NS_DEFINE_STATIC_IID_ACCESSOR(nsIClipboardDragDropHookList, NS_ICLIPBOARDDRAGDROPHOOKLIST_IID)

/* Use this macro when declaring classes that implement this interface. */
#define NS_DECL_NSICLIPBOARDDRAGDROPHOOKLIST \
  NS_SCRIPTABLE NS_IMETHOD AddClipboardDragDropHooks(nsIClipboardDragDropHooks *aHooks); \
  NS_SCRIPTABLE NS_IMETHOD RemoveClipboardDragDropHooks(nsIClipboardDragDropHooks *aHooks); \
  NS_SCRIPTABLE NS_IMETHOD GetHookEnumerator(nsISimpleEnumerator **_retval NS_OUTPARAM); 

/* Use this macro to declare functions that forward the behavior of this interface to another object. */
#define NS_FORWARD_NSICLIPBOARDDRAGDROPHOOKLIST(_to) \
  NS_SCRIPTABLE NS_IMETHOD AddClipboardDragDropHooks(nsIClipboardDragDropHooks *aHooks) { return _to AddClipboardDragDropHooks(aHooks); } \
  NS_SCRIPTABLE NS_IMETHOD RemoveClipboardDragDropHooks(nsIClipboardDragDropHooks *aHooks) { return _to RemoveClipboardDragDropHooks(aHooks); } \
  NS_SCRIPTABLE NS_IMETHOD GetHookEnumerator(nsISimpleEnumerator **_retval NS_OUTPARAM) { return _to GetHookEnumerator(_retval); } 

/* Use this macro to declare functions that forward the behavior of this interface to another object in a safe way. */
#define NS_FORWARD_SAFE_NSICLIPBOARDDRAGDROPHOOKLIST(_to) \
  NS_SCRIPTABLE NS_IMETHOD AddClipboardDragDropHooks(nsIClipboardDragDropHooks *aHooks) { return !_to ? NS_ERROR_NULL_POINTER : _to->AddClipboardDragDropHooks(aHooks); } \
  NS_SCRIPTABLE NS_IMETHOD RemoveClipboardDragDropHooks(nsIClipboardDragDropHooks *aHooks) { return !_to ? NS_ERROR_NULL_POINTER : _to->RemoveClipboardDragDropHooks(aHooks); } \
  NS_SCRIPTABLE NS_IMETHOD GetHookEnumerator(nsISimpleEnumerator **_retval NS_OUTPARAM) { return !_to ? NS_ERROR_NULL_POINTER : _to->GetHookEnumerator(_retval); } 

#if 0
/* Use the code below as a template for the implementation class for this interface. */

/* Header file */
class nsClipboardDragDropHookList : public nsIClipboardDragDropHookList
{
public:
  NS_DECL_ISUPPORTS
  NS_DECL_NSICLIPBOARDDRAGDROPHOOKLIST

  nsClipboardDragDropHookList();

private:
  ~nsClipboardDragDropHookList();

protected:
  /* additional members */
};

/* Implementation file */
NS_IMPL_ISUPPORTS1(nsClipboardDragDropHookList, nsIClipboardDragDropHookList)

nsClipboardDragDropHookList::nsClipboardDragDropHookList()
{
  /* member initializers and constructor code */
}

nsClipboardDragDropHookList::~nsClipboardDragDropHookList()
{
  /* destructor code */
}

/* void addClipboardDragDropHooks (in nsIClipboardDragDropHooks aHooks); */
NS_IMETHODIMP nsClipboardDragDropHookList::AddClipboardDragDropHooks(nsIClipboardDragDropHooks *aHooks)
{
    return NS_ERROR_NOT_IMPLEMENTED;
}

/* void removeClipboardDragDropHooks (in nsIClipboardDragDropHooks aHooks); */
NS_IMETHODIMP nsClipboardDragDropHookList::RemoveClipboardDragDropHooks(nsIClipboardDragDropHooks *aHooks)
{
    return NS_ERROR_NOT_IMPLEMENTED;
}

/* nsISimpleEnumerator getHookEnumerator (); */
NS_IMETHODIMP nsClipboardDragDropHookList::GetHookEnumerator(nsISimpleEnumerator **_retval NS_OUTPARAM)
{
    return NS_ERROR_NOT_IMPLEMENTED;
}

/* End of implementation class template. */
#endif


#endif /* __gen_nsIClipboardDragDropHookList_h__ */
