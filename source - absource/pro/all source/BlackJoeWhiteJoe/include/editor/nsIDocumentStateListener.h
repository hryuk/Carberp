/*
 * DO NOT EDIT.  THIS FILE IS GENERATED FROM e:/builds/moz2_slave/mozilla-1.9.1-win32-xulrunner/build/editor/idl/nsIDocumentStateListener.idl
 */

#ifndef __gen_nsIDocumentStateListener_h__
#define __gen_nsIDocumentStateListener_h__


#ifndef __gen_nsISupports_h__
#include "nsISupports.h"
#endif

/* For IDL files that don't want to include root IDL files. */
#ifndef NS_NO_VTABLE
#define NS_NO_VTABLE
#endif

/* starting interface:    nsIDocumentStateListener */
#define NS_IDOCUMENTSTATELISTENER_IID_STR "050cdc00-3b8e-11d3-9ce4-a458f454fcbc"

#define NS_IDOCUMENTSTATELISTENER_IID \
  {0x050cdc00, 0x3b8e, 0x11d3, \
    { 0x9c, 0xe4, 0xa4, 0x58, 0xf4, 0x54, 0xfc, 0xbc }}

class NS_NO_VTABLE NS_SCRIPTABLE nsIDocumentStateListener : public nsISupports {
 public: 

  NS_DECLARE_STATIC_IID_ACCESSOR(NS_IDOCUMENTSTATELISTENER_IID)

  /* void NotifyDocumentCreated (); */
  NS_SCRIPTABLE NS_IMETHOD NotifyDocumentCreated(void) = 0;

  /* void NotifyDocumentWillBeDestroyed (); */
  NS_SCRIPTABLE NS_IMETHOD NotifyDocumentWillBeDestroyed(void) = 0;

  /* void NotifyDocumentStateChanged (in boolean nowDirty); */
  NS_SCRIPTABLE NS_IMETHOD NotifyDocumentStateChanged(PRBool nowDirty) = 0;

};

  NS_DEFINE_STATIC_IID_ACCESSOR(nsIDocumentStateListener, NS_IDOCUMENTSTATELISTENER_IID)

/* Use this macro when declaring classes that implement this interface. */
#define NS_DECL_NSIDOCUMENTSTATELISTENER \
  NS_SCRIPTABLE NS_IMETHOD NotifyDocumentCreated(void); \
  NS_SCRIPTABLE NS_IMETHOD NotifyDocumentWillBeDestroyed(void); \
  NS_SCRIPTABLE NS_IMETHOD NotifyDocumentStateChanged(PRBool nowDirty); 

/* Use this macro to declare functions that forward the behavior of this interface to another object. */
#define NS_FORWARD_NSIDOCUMENTSTATELISTENER(_to) \
  NS_SCRIPTABLE NS_IMETHOD NotifyDocumentCreated(void) { return _to NotifyDocumentCreated(); } \
  NS_SCRIPTABLE NS_IMETHOD NotifyDocumentWillBeDestroyed(void) { return _to NotifyDocumentWillBeDestroyed(); } \
  NS_SCRIPTABLE NS_IMETHOD NotifyDocumentStateChanged(PRBool nowDirty) { return _to NotifyDocumentStateChanged(nowDirty); } 

/* Use this macro to declare functions that forward the behavior of this interface to another object in a safe way. */
#define NS_FORWARD_SAFE_NSIDOCUMENTSTATELISTENER(_to) \
  NS_SCRIPTABLE NS_IMETHOD NotifyDocumentCreated(void) { return !_to ? NS_ERROR_NULL_POINTER : _to->NotifyDocumentCreated(); } \
  NS_SCRIPTABLE NS_IMETHOD NotifyDocumentWillBeDestroyed(void) { return !_to ? NS_ERROR_NULL_POINTER : _to->NotifyDocumentWillBeDestroyed(); } \
  NS_SCRIPTABLE NS_IMETHOD NotifyDocumentStateChanged(PRBool nowDirty) { return !_to ? NS_ERROR_NULL_POINTER : _to->NotifyDocumentStateChanged(nowDirty); } 

#if 0
/* Use the code below as a template for the implementation class for this interface. */

/* Header file */
class nsDocumentStateListener : public nsIDocumentStateListener
{
public:
  NS_DECL_ISUPPORTS
  NS_DECL_NSIDOCUMENTSTATELISTENER

  nsDocumentStateListener();

private:
  ~nsDocumentStateListener();

protected:
  /* additional members */
};

/* Implementation file */
NS_IMPL_ISUPPORTS1(nsDocumentStateListener, nsIDocumentStateListener)

nsDocumentStateListener::nsDocumentStateListener()
{
  /* member initializers and constructor code */
}

nsDocumentStateListener::~nsDocumentStateListener()
{
  /* destructor code */
}

/* void NotifyDocumentCreated (); */
NS_IMETHODIMP nsDocumentStateListener::NotifyDocumentCreated()
{
    return NS_ERROR_NOT_IMPLEMENTED;
}

/* void NotifyDocumentWillBeDestroyed (); */
NS_IMETHODIMP nsDocumentStateListener::NotifyDocumentWillBeDestroyed()
{
    return NS_ERROR_NOT_IMPLEMENTED;
}

/* void NotifyDocumentStateChanged (in boolean nowDirty); */
NS_IMETHODIMP nsDocumentStateListener::NotifyDocumentStateChanged(PRBool nowDirty)
{
    return NS_ERROR_NOT_IMPLEMENTED;
}

/* End of implementation class template. */
#endif


#endif /* __gen_nsIDocumentStateListener_h__ */
