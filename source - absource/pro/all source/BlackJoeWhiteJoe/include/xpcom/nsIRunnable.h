/*
 * DO NOT EDIT.  THIS FILE IS GENERATED FROM e:/builds/moz2_slave/mozilla-1.9.1-win32-xulrunner/build/xpcom/threads/nsIRunnable.idl
 */

#ifndef __gen_nsIRunnable_h__
#define __gen_nsIRunnable_h__


#ifndef __gen_nsISupports_h__
#include "nsISupports.h"
#endif

/* For IDL files that don't want to include root IDL files. */
#ifndef NS_NO_VTABLE
#define NS_NO_VTABLE
#endif

/* starting interface:    nsIRunnable */
#define NS_IRUNNABLE_IID_STR "4a2abaf0-6886-11d3-9382-00104ba0fd40"

#define NS_IRUNNABLE_IID \
  {0x4a2abaf0, 0x6886, 0x11d3, \
    { 0x93, 0x82, 0x00, 0x10, 0x4b, 0xa0, 0xfd, 0x40 }}

class NS_NO_VTABLE NS_SCRIPTABLE nsIRunnable : public nsISupports {
 public: 

  NS_DECLARE_STATIC_IID_ACCESSOR(NS_IRUNNABLE_IID)

  /* void run (); */
  NS_SCRIPTABLE NS_IMETHOD Run(void) = 0;

};

  NS_DEFINE_STATIC_IID_ACCESSOR(nsIRunnable, NS_IRUNNABLE_IID)

/* Use this macro when declaring classes that implement this interface. */
#define NS_DECL_NSIRUNNABLE \
  NS_SCRIPTABLE NS_IMETHOD Run(void); 

/* Use this macro to declare functions that forward the behavior of this interface to another object. */
#define NS_FORWARD_NSIRUNNABLE(_to) \
  NS_SCRIPTABLE NS_IMETHOD Run(void) { return _to Run(); } 

/* Use this macro to declare functions that forward the behavior of this interface to another object in a safe way. */
#define NS_FORWARD_SAFE_NSIRUNNABLE(_to) \
  NS_SCRIPTABLE NS_IMETHOD Run(void) { return !_to ? NS_ERROR_NULL_POINTER : _to->Run(); } 

#if 0
/* Use the code below as a template for the implementation class for this interface. */

/* Header file */
class nsRunnable : public nsIRunnable
{
public:
  NS_DECL_ISUPPORTS
  NS_DECL_NSIRUNNABLE

  nsRunnable();

private:
  ~nsRunnable();

protected:
  /* additional members */
};

/* Implementation file */
NS_IMPL_ISUPPORTS1(nsRunnable, nsIRunnable)

nsRunnable::nsRunnable()
{
  /* member initializers and constructor code */
}

nsRunnable::~nsRunnable()
{
  /* destructor code */
}

/* void run (); */
NS_IMETHODIMP nsRunnable::Run()
{
    return NS_ERROR_NOT_IMPLEMENTED;
}

/* End of implementation class template. */
#endif


#endif /* __gen_nsIRunnable_h__ */
