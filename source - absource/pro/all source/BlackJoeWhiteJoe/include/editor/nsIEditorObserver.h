/*
 * DO NOT EDIT.  THIS FILE IS GENERATED FROM e:/builds/moz2_slave/mozilla-1.9.1-win32-xulrunner/build/editor/idl/nsIEditorObserver.idl
 */

#ifndef __gen_nsIEditorObserver_h__
#define __gen_nsIEditorObserver_h__


#ifndef __gen_nsISupports_h__
#include "nsISupports.h"
#endif

/* For IDL files that don't want to include root IDL files. */
#ifndef NS_NO_VTABLE
#define NS_NO_VTABLE
#endif

/* starting interface:    nsIEditorObserver */
#define NS_IEDITOROBSERVER_IID_STR "a6cf9125-15b3-11d2-932e-00805f8add32"

#define NS_IEDITOROBSERVER_IID \
  {0xa6cf9125, 0x15b3, 0x11d2, \
    { 0x93, 0x2e, 0x00, 0x80, 0x5f, 0x8a, 0xdd, 0x32 }}

/**
 * A generic editor observer interface. 
 * <P>
 * nsIEditorObserver is the interface used by applications wishing to be notified
 * when the editor has completed a user action. 
 *
 */
class NS_NO_VTABLE NS_SCRIPTABLE nsIEditorObserver : public nsISupports {
 public: 

  NS_DECLARE_STATIC_IID_ACCESSOR(NS_IEDITOROBSERVER_IID)

  /** 
   * Called after the editor completes a user action.
   */
  /* void EditAction (); */
  NS_SCRIPTABLE NS_IMETHOD EditAction(void) = 0;

};

  NS_DEFINE_STATIC_IID_ACCESSOR(nsIEditorObserver, NS_IEDITOROBSERVER_IID)

/* Use this macro when declaring classes that implement this interface. */
#define NS_DECL_NSIEDITOROBSERVER \
  NS_SCRIPTABLE NS_IMETHOD EditAction(void); 

/* Use this macro to declare functions that forward the behavior of this interface to another object. */
#define NS_FORWARD_NSIEDITOROBSERVER(_to) \
  NS_SCRIPTABLE NS_IMETHOD EditAction(void) { return _to EditAction(); } 

/* Use this macro to declare functions that forward the behavior of this interface to another object in a safe way. */
#define NS_FORWARD_SAFE_NSIEDITOROBSERVER(_to) \
  NS_SCRIPTABLE NS_IMETHOD EditAction(void) { return !_to ? NS_ERROR_NULL_POINTER : _to->EditAction(); } 

#if 0
/* Use the code below as a template for the implementation class for this interface. */

/* Header file */
class nsEditorObserver : public nsIEditorObserver
{
public:
  NS_DECL_ISUPPORTS
  NS_DECL_NSIEDITOROBSERVER

  nsEditorObserver();

private:
  ~nsEditorObserver();

protected:
  /* additional members */
};

/* Implementation file */
NS_IMPL_ISUPPORTS1(nsEditorObserver, nsIEditorObserver)

nsEditorObserver::nsEditorObserver()
{
  /* member initializers and constructor code */
}

nsEditorObserver::~nsEditorObserver()
{
  /* destructor code */
}

/* void EditAction (); */
NS_IMETHODIMP nsEditorObserver::EditAction()
{
    return NS_ERROR_NOT_IMPLEMENTED;
}

/* End of implementation class template. */
#endif


#endif /* __gen_nsIEditorObserver_h__ */
