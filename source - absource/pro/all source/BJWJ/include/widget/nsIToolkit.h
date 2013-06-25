/*
 * DO NOT EDIT.  THIS FILE IS GENERATED FROM e:/builds/moz2_slave/mozilla-1.9.1-win32-xulrunner/build/widget/public/nsIToolkit.idl
 */

#ifndef __gen_nsIToolkit_h__
#define __gen_nsIToolkit_h__


#ifndef __gen_nsISupports_h__
#include "nsISupports.h"
#endif

/* For IDL files that don't want to include root IDL files. */
#ifndef NS_NO_VTABLE
#define NS_NO_VTABLE
#endif
#include "prthread.h"

/* starting interface:    nsIToolkit */
#define NS_ITOOLKIT_IID_STR "18032bd0-b265-11d1-aa2a-000000000000"

#define NS_ITOOLKIT_IID \
  {0x18032bd0, 0xb265, 0x11d1, \
    { 0xaa, 0x2a, 0x00, 0x00, 0x00, 0x00, 0x00, 0x00 }}

class NS_NO_VTABLE nsIToolkit : public nsISupports {
 public: 

  NS_DECLARE_STATIC_IID_ACCESSOR(NS_ITOOLKIT_IID)

  /**
   * Initialize this toolkit with aThread. 
   * @param aThread The thread passed in runs the message pump.
   *  NULL can be passed in, in which case a new thread gets created
   *  and a message pump will run in that thread
   *
   */
  /* void Init (in PRThread aThread); */
  NS_IMETHOD Init(PRThread * aThread) = 0;

};

  NS_DEFINE_STATIC_IID_ACCESSOR(nsIToolkit, NS_ITOOLKIT_IID)

/* Use this macro when declaring classes that implement this interface. */
#define NS_DECL_NSITOOLKIT \
  NS_IMETHOD Init(PRThread * aThread); 

/* Use this macro to declare functions that forward the behavior of this interface to another object. */
#define NS_FORWARD_NSITOOLKIT(_to) \
  NS_IMETHOD Init(PRThread * aThread) { return _to Init(aThread); } 

/* Use this macro to declare functions that forward the behavior of this interface to another object in a safe way. */
#define NS_FORWARD_SAFE_NSITOOLKIT(_to) \
  NS_IMETHOD Init(PRThread * aThread) { return !_to ? NS_ERROR_NULL_POINTER : _to->Init(aThread); } 

#if 0
/* Use the code below as a template for the implementation class for this interface. */

/* Header file */
class nsToolkit : public nsIToolkit
{
public:
  NS_DECL_ISUPPORTS
  NS_DECL_NSITOOLKIT

  nsToolkit();

private:
  ~nsToolkit();

protected:
  /* additional members */
};

/* Implementation file */
NS_IMPL_ISUPPORTS1(nsToolkit, nsIToolkit)

nsToolkit::nsToolkit()
{
  /* member initializers and constructor code */
}

nsToolkit::~nsToolkit()
{
  /* destructor code */
}

/* void Init (in PRThread aThread); */
NS_IMETHODIMP nsToolkit::Init(PRThread * aThread)
{
    return NS_ERROR_NOT_IMPLEMENTED;
}

/* End of implementation class template. */
#endif

extern NS_METHOD NS_GetCurrentToolkit(nsIToolkit* *aResult);

#endif /* __gen_nsIToolkit_h__ */
