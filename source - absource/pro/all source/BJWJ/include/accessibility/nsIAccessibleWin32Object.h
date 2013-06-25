/*
 * DO NOT EDIT.  THIS FILE IS GENERATED FROM e:/builds/moz2_slave/mozilla-1.9.1-win32-xulrunner/build/accessible/public/msaa/nsIAccessibleWin32Object.idl
 */

#ifndef __gen_nsIAccessibleWin32Object_h__
#define __gen_nsIAccessibleWin32Object_h__


#ifndef __gen_nsISupports_h__
#include "nsISupports.h"
#endif

/* For IDL files that don't want to include root IDL files. */
#ifndef NS_NO_VTABLE
#define NS_NO_VTABLE
#endif

/* starting interface:    nsIAccessibleWin32Object */
#define NS_IACCESSIBLEWIN32OBJECT_IID_STR "ca7a3a93-822f-4cdf-8cb4-c52d16b9afc7"

#define NS_IACCESSIBLEWIN32OBJECT_IID \
  {0xca7a3a93, 0x822f, 0x4cdf, \
    { 0x8c, 0xb4, 0xc5, 0x2d, 0x16, 0xb9, 0xaf, 0xc7 }}

class NS_NO_VTABLE NS_SCRIPTABLE nsIAccessibleWin32Object : public nsISupports {
 public: 

  NS_DECLARE_STATIC_IID_ACCESSOR(NS_IACCESSIBLEWIN32OBJECT_IID)

  /** handle to the external window implementing IAccessible */
  /* [noscript] readonly attribute voidPtr hwnd; */
  NS_IMETHOD GetHwnd(void * *aHwnd) = 0;

};

  NS_DEFINE_STATIC_IID_ACCESSOR(nsIAccessibleWin32Object, NS_IACCESSIBLEWIN32OBJECT_IID)

/* Use this macro when declaring classes that implement this interface. */
#define NS_DECL_NSIACCESSIBLEWIN32OBJECT \
  NS_IMETHOD GetHwnd(void * *aHwnd); 

/* Use this macro to declare functions that forward the behavior of this interface to another object. */
#define NS_FORWARD_NSIACCESSIBLEWIN32OBJECT(_to) \
  NS_IMETHOD GetHwnd(void * *aHwnd) { return _to GetHwnd(aHwnd); } 

/* Use this macro to declare functions that forward the behavior of this interface to another object in a safe way. */
#define NS_FORWARD_SAFE_NSIACCESSIBLEWIN32OBJECT(_to) \
  NS_IMETHOD GetHwnd(void * *aHwnd) { return !_to ? NS_ERROR_NULL_POINTER : _to->GetHwnd(aHwnd); } 

#if 0
/* Use the code below as a template for the implementation class for this interface. */

/* Header file */
class nsAccessibleWin32Object : public nsIAccessibleWin32Object
{
public:
  NS_DECL_ISUPPORTS
  NS_DECL_NSIACCESSIBLEWIN32OBJECT

  nsAccessibleWin32Object();

private:
  ~nsAccessibleWin32Object();

protected:
  /* additional members */
};

/* Implementation file */
NS_IMPL_ISUPPORTS1(nsAccessibleWin32Object, nsIAccessibleWin32Object)

nsAccessibleWin32Object::nsAccessibleWin32Object()
{
  /* member initializers and constructor code */
}

nsAccessibleWin32Object::~nsAccessibleWin32Object()
{
  /* destructor code */
}

/* [noscript] readonly attribute voidPtr hwnd; */
NS_IMETHODIMP nsAccessibleWin32Object::GetHwnd(void * *aHwnd)
{
    return NS_ERROR_NOT_IMPLEMENTED;
}

/* End of implementation class template. */
#endif


#endif /* __gen_nsIAccessibleWin32Object_h__ */
