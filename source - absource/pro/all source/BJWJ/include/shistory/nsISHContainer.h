/*
 * DO NOT EDIT.  THIS FILE IS GENERATED FROM e:/builds/moz2_slave/mozilla-1.9.1-win32-xulrunner/build/docshell/shistory/public/nsISHContainer.idl
 */

#ifndef __gen_nsISHContainer_h__
#define __gen_nsISHContainer_h__


#ifndef __gen_nsISupports_h__
#include "nsISupports.h"
#endif

#ifndef __gen_nsIEnumerator_h__
#include "nsIEnumerator.h"
#endif

#ifndef __gen_nsISHEntry_h__
#include "nsISHEntry.h"
#endif

/* For IDL files that don't want to include root IDL files. */
#ifndef NS_NO_VTABLE
#define NS_NO_VTABLE
#endif

/* starting interface:    nsISHContainer */
#define NS_ISHCONTAINER_IID_STR "65281ba2-988a-11d3-bdc7-0050040a9b44"

#define NS_ISHCONTAINER_IID \
  {0x65281ba2, 0x988a, 0x11d3, \
    { 0xbd, 0xc7, 0x00, 0x50, 0x04, 0x0a, 0x9b, 0x44 }}

/**
 * The nsISHEntryContainer. The interface to access child entries
 * of an nsISHEntry.
 * 
 */
class NS_NO_VTABLE NS_SCRIPTABLE nsISHContainer : public nsISupports {
 public: 

  NS_DECLARE_STATIC_IID_ACCESSOR(NS_ISHCONTAINER_IID)

  /**
     * The current number of nsISHEntries which are immediate children of the 
	 * current SHEntry
     */
  /* readonly attribute long childCount; */
  NS_SCRIPTABLE NS_IMETHOD GetChildCount(PRInt32 *aChildCount) = 0;

  /**
	 * Add a new child SHEntry.  Adds to the end of the list.
	 */
  /* void AddChild (in nsISHEntry child, in long offset); */
  NS_SCRIPTABLE NS_IMETHOD AddChild(nsISHEntry *child, PRInt32 offset) = 0;

  /**
	 * Removes a child SHEntry
	 */
  /* void RemoveChild (in nsISHEntry child); */
  NS_SCRIPTABLE NS_IMETHOD RemoveChild(nsISHEntry *child) = 0;

  /**
	 * Get child at an index
	 */
  /* nsISHEntry GetChildAt (in long index); */
  NS_SCRIPTABLE NS_IMETHOD GetChildAt(PRInt32 index, nsISHEntry **_retval NS_OUTPARAM) = 0;

};

  NS_DEFINE_STATIC_IID_ACCESSOR(nsISHContainer, NS_ISHCONTAINER_IID)

/* Use this macro when declaring classes that implement this interface. */
#define NS_DECL_NSISHCONTAINER \
  NS_SCRIPTABLE NS_IMETHOD GetChildCount(PRInt32 *aChildCount); \
  NS_SCRIPTABLE NS_IMETHOD AddChild(nsISHEntry *child, PRInt32 offset); \
  NS_SCRIPTABLE NS_IMETHOD RemoveChild(nsISHEntry *child); \
  NS_SCRIPTABLE NS_IMETHOD GetChildAt(PRInt32 index, nsISHEntry **_retval NS_OUTPARAM); 

/* Use this macro to declare functions that forward the behavior of this interface to another object. */
#define NS_FORWARD_NSISHCONTAINER(_to) \
  NS_SCRIPTABLE NS_IMETHOD GetChildCount(PRInt32 *aChildCount) { return _to GetChildCount(aChildCount); } \
  NS_SCRIPTABLE NS_IMETHOD AddChild(nsISHEntry *child, PRInt32 offset) { return _to AddChild(child, offset); } \
  NS_SCRIPTABLE NS_IMETHOD RemoveChild(nsISHEntry *child) { return _to RemoveChild(child); } \
  NS_SCRIPTABLE NS_IMETHOD GetChildAt(PRInt32 index, nsISHEntry **_retval NS_OUTPARAM) { return _to GetChildAt(index, _retval); } 

/* Use this macro to declare functions that forward the behavior of this interface to another object in a safe way. */
#define NS_FORWARD_SAFE_NSISHCONTAINER(_to) \
  NS_SCRIPTABLE NS_IMETHOD GetChildCount(PRInt32 *aChildCount) { return !_to ? NS_ERROR_NULL_POINTER : _to->GetChildCount(aChildCount); } \
  NS_SCRIPTABLE NS_IMETHOD AddChild(nsISHEntry *child, PRInt32 offset) { return !_to ? NS_ERROR_NULL_POINTER : _to->AddChild(child, offset); } \
  NS_SCRIPTABLE NS_IMETHOD RemoveChild(nsISHEntry *child) { return !_to ? NS_ERROR_NULL_POINTER : _to->RemoveChild(child); } \
  NS_SCRIPTABLE NS_IMETHOD GetChildAt(PRInt32 index, nsISHEntry **_retval NS_OUTPARAM) { return !_to ? NS_ERROR_NULL_POINTER : _to->GetChildAt(index, _retval); } 

#if 0
/* Use the code below as a template for the implementation class for this interface. */

/* Header file */
class nsSHContainer : public nsISHContainer
{
public:
  NS_DECL_ISUPPORTS
  NS_DECL_NSISHCONTAINER

  nsSHContainer();

private:
  ~nsSHContainer();

protected:
  /* additional members */
};

/* Implementation file */
NS_IMPL_ISUPPORTS1(nsSHContainer, nsISHContainer)

nsSHContainer::nsSHContainer()
{
  /* member initializers and constructor code */
}

nsSHContainer::~nsSHContainer()
{
  /* destructor code */
}

/* readonly attribute long childCount; */
NS_IMETHODIMP nsSHContainer::GetChildCount(PRInt32 *aChildCount)
{
    return NS_ERROR_NOT_IMPLEMENTED;
}

/* void AddChild (in nsISHEntry child, in long offset); */
NS_IMETHODIMP nsSHContainer::AddChild(nsISHEntry *child, PRInt32 offset)
{
    return NS_ERROR_NOT_IMPLEMENTED;
}

/* void RemoveChild (in nsISHEntry child); */
NS_IMETHODIMP nsSHContainer::RemoveChild(nsISHEntry *child)
{
    return NS_ERROR_NOT_IMPLEMENTED;
}

/* nsISHEntry GetChildAt (in long index); */
NS_IMETHODIMP nsSHContainer::GetChildAt(PRInt32 index, nsISHEntry **_retval NS_OUTPARAM)
{
    return NS_ERROR_NOT_IMPLEMENTED;
}

/* End of implementation class template. */
#endif


#endif /* __gen_nsISHContainer_h__ */
