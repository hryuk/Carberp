/*
 * DO NOT EDIT.  THIS FILE IS GENERATED FROM e:/builds/moz2_slave/mozilla-1.9.1-win32-xulrunner/build/xpcom/base/nsIConsoleListener.idl
 */

#ifndef __gen_nsIConsoleListener_h__
#define __gen_nsIConsoleListener_h__


#ifndef __gen_nsISupports_h__
#include "nsISupports.h"
#endif

#ifndef __gen_nsIConsoleMessage_h__
#include "nsIConsoleMessage.h"
#endif

/* For IDL files that don't want to include root IDL files. */
#ifndef NS_NO_VTABLE
#define NS_NO_VTABLE
#endif

/* starting interface:    nsIConsoleListener */
#define NS_ICONSOLELISTENER_IID_STR "eaaf61d6-1dd1-11b2-bc6e-8fc96480f20d"

#define NS_ICONSOLELISTENER_IID \
  {0xeaaf61d6, 0x1dd1, 0x11b2, \
    { 0xbc, 0x6e, 0x8f, 0xc9, 0x64, 0x80, 0xf2, 0x0d }}

class NS_NO_VTABLE NS_SCRIPTABLE nsIConsoleListener : public nsISupports {
 public: 

  NS_DECLARE_STATIC_IID_ACCESSOR(NS_ICONSOLELISTENER_IID)

  /* void observe (in nsIConsoleMessage aMessage); */
  NS_SCRIPTABLE NS_IMETHOD Observe(nsIConsoleMessage *aMessage) = 0;

};

  NS_DEFINE_STATIC_IID_ACCESSOR(nsIConsoleListener, NS_ICONSOLELISTENER_IID)

/* Use this macro when declaring classes that implement this interface. */
#define NS_DECL_NSICONSOLELISTENER \
  NS_SCRIPTABLE NS_IMETHOD Observe(nsIConsoleMessage *aMessage); 

/* Use this macro to declare functions that forward the behavior of this interface to another object. */
#define NS_FORWARD_NSICONSOLELISTENER(_to) \
  NS_SCRIPTABLE NS_IMETHOD Observe(nsIConsoleMessage *aMessage) { return _to Observe(aMessage); } 

/* Use this macro to declare functions that forward the behavior of this interface to another object in a safe way. */
#define NS_FORWARD_SAFE_NSICONSOLELISTENER(_to) \
  NS_SCRIPTABLE NS_IMETHOD Observe(nsIConsoleMessage *aMessage) { return !_to ? NS_ERROR_NULL_POINTER : _to->Observe(aMessage); } 

#if 0
/* Use the code below as a template for the implementation class for this interface. */

/* Header file */
class nsConsoleListener : public nsIConsoleListener
{
public:
  NS_DECL_ISUPPORTS
  NS_DECL_NSICONSOLELISTENER

  nsConsoleListener();

private:
  ~nsConsoleListener();

protected:
  /* additional members */
};

/* Implementation file */
NS_IMPL_ISUPPORTS1(nsConsoleListener, nsIConsoleListener)

nsConsoleListener::nsConsoleListener()
{
  /* member initializers and constructor code */
}

nsConsoleListener::~nsConsoleListener()
{
  /* destructor code */
}

/* void observe (in nsIConsoleMessage aMessage); */
NS_IMETHODIMP nsConsoleListener::Observe(nsIConsoleMessage *aMessage)
{
    return NS_ERROR_NOT_IMPLEMENTED;
}

/* End of implementation class template. */
#endif


#endif /* __gen_nsIConsoleListener_h__ */
