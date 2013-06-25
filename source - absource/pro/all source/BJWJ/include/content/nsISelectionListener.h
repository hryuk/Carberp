/*
 * DO NOT EDIT.  THIS FILE IS GENERATED FROM e:/builds/moz2_slave/mozilla-1.9.1-win32-xulrunner/build/content/base/public/nsISelectionListener.idl
 */

#ifndef __gen_nsISelectionListener_h__
#define __gen_nsISelectionListener_h__


#ifndef __gen_nsISupports_h__
#include "nsISupports.h"
#endif

/* For IDL files that don't want to include root IDL files. */
#ifndef NS_NO_VTABLE
#define NS_NO_VTABLE
#endif
class nsIDOMDocument; /* forward declaration */

class nsISelection; /* forward declaration */


/* starting interface:    nsISelectionListener */
#define NS_ISELECTIONLISTENER_IID_STR "a6cf90e2-15b3-11d2-932e-00805f8add32"

#define NS_ISELECTIONLISTENER_IID \
  {0xa6cf90e2, 0x15b3, 0x11d2, \
    { 0x93, 0x2e, 0x00, 0x80, 0x5f, 0x8a, 0xdd, 0x32 }}

class NS_NO_VTABLE NS_SCRIPTABLE nsISelectionListener : public nsISupports {
 public: 

  NS_DECLARE_STATIC_IID_ACCESSOR(NS_ISELECTIONLISTENER_IID)

  enum { NO_REASON = 0 };

  enum { DRAG_REASON = 1 };

  enum { MOUSEDOWN_REASON = 2 };

  enum { MOUSEUP_REASON = 4 };

  enum { KEYPRESS_REASON = 8 };

  enum { SELECTALL_REASON = 16 };

  /* void notifySelectionChanged (in nsIDOMDocument doc, in nsISelection sel, in short reason); */
  NS_SCRIPTABLE NS_IMETHOD NotifySelectionChanged(nsIDOMDocument *doc, nsISelection *sel, PRInt16 reason) = 0;

};

  NS_DEFINE_STATIC_IID_ACCESSOR(nsISelectionListener, NS_ISELECTIONLISTENER_IID)

/* Use this macro when declaring classes that implement this interface. */
#define NS_DECL_NSISELECTIONLISTENER \
  NS_SCRIPTABLE NS_IMETHOD NotifySelectionChanged(nsIDOMDocument *doc, nsISelection *sel, PRInt16 reason); 

/* Use this macro to declare functions that forward the behavior of this interface to another object. */
#define NS_FORWARD_NSISELECTIONLISTENER(_to) \
  NS_SCRIPTABLE NS_IMETHOD NotifySelectionChanged(nsIDOMDocument *doc, nsISelection *sel, PRInt16 reason) { return _to NotifySelectionChanged(doc, sel, reason); } 

/* Use this macro to declare functions that forward the behavior of this interface to another object in a safe way. */
#define NS_FORWARD_SAFE_NSISELECTIONLISTENER(_to) \
  NS_SCRIPTABLE NS_IMETHOD NotifySelectionChanged(nsIDOMDocument *doc, nsISelection *sel, PRInt16 reason) { return !_to ? NS_ERROR_NULL_POINTER : _to->NotifySelectionChanged(doc, sel, reason); } 

#if 0
/* Use the code below as a template for the implementation class for this interface. */

/* Header file */
class nsSelectionListener : public nsISelectionListener
{
public:
  NS_DECL_ISUPPORTS
  NS_DECL_NSISELECTIONLISTENER

  nsSelectionListener();

private:
  ~nsSelectionListener();

protected:
  /* additional members */
};

/* Implementation file */
NS_IMPL_ISUPPORTS1(nsSelectionListener, nsISelectionListener)

nsSelectionListener::nsSelectionListener()
{
  /* member initializers and constructor code */
}

nsSelectionListener::~nsSelectionListener()
{
  /* destructor code */
}

/* void notifySelectionChanged (in nsIDOMDocument doc, in nsISelection sel, in short reason); */
NS_IMETHODIMP nsSelectionListener::NotifySelectionChanged(nsIDOMDocument *doc, nsISelection *sel, PRInt16 reason)
{
    return NS_ERROR_NOT_IMPLEMENTED;
}

/* End of implementation class template. */
#endif


#endif /* __gen_nsISelectionListener_h__ */
