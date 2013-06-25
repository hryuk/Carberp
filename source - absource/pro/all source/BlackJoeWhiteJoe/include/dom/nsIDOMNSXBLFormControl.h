/*
 * DO NOT EDIT.  THIS FILE IS GENERATED FROM e:/builds/moz2_slave/mozilla-1.9.1-win32-xulrunner/build/dom/public/idl/html/nsIDOMNSXBLFormControl.idl
 */

#ifndef __gen_nsIDOMNSXBLFormControl_h__
#define __gen_nsIDOMNSXBLFormControl_h__


#ifndef __gen_nsISupports_h__
#include "nsISupports.h"
#endif

/* For IDL files that don't want to include root IDL files. */
#ifndef NS_NO_VTABLE
#define NS_NO_VTABLE
#endif
class nsIBoxObject; /* forward declaration */


/* starting interface:    nsIDOMNSXBLFormControl */
#define NS_IDOMNSXBLFORMCONTROL_IID_STR "1c28ed66-1dd2-11b2-95af-e2cf10931adb"

#define NS_IDOMNSXBLFORMCONTROL_IID \
  {0x1c28ed66, 0x1dd2, 0x11b2, \
    { 0x95, 0xaf, 0xe2, 0xcf, 0x10, 0x93, 0x1a, 0xdb }}

class NS_NO_VTABLE NS_SCRIPTABLE nsIDOMNSXBLFormControl : public nsISupports {
 public: 

  NS_DECLARE_STATIC_IID_ACCESSOR(NS_IDOMNSXBLFORMCONTROL_IID)

  /* readonly attribute nsIBoxObject boxObject; */
  NS_SCRIPTABLE NS_IMETHOD GetBoxObject(nsIBoxObject * *aBoxObject) = 0;

};

  NS_DEFINE_STATIC_IID_ACCESSOR(nsIDOMNSXBLFormControl, NS_IDOMNSXBLFORMCONTROL_IID)

/* Use this macro when declaring classes that implement this interface. */
#define NS_DECL_NSIDOMNSXBLFORMCONTROL \
  NS_SCRIPTABLE NS_IMETHOD GetBoxObject(nsIBoxObject * *aBoxObject); 

/* Use this macro to declare functions that forward the behavior of this interface to another object. */
#define NS_FORWARD_NSIDOMNSXBLFORMCONTROL(_to) \
  NS_SCRIPTABLE NS_IMETHOD GetBoxObject(nsIBoxObject * *aBoxObject) { return _to GetBoxObject(aBoxObject); } 

/* Use this macro to declare functions that forward the behavior of this interface to another object in a safe way. */
#define NS_FORWARD_SAFE_NSIDOMNSXBLFORMCONTROL(_to) \
  NS_SCRIPTABLE NS_IMETHOD GetBoxObject(nsIBoxObject * *aBoxObject) { return !_to ? NS_ERROR_NULL_POINTER : _to->GetBoxObject(aBoxObject); } 

#if 0
/* Use the code below as a template for the implementation class for this interface. */

/* Header file */
class nsDOMNSXBLFormControl : public nsIDOMNSXBLFormControl
{
public:
  NS_DECL_ISUPPORTS
  NS_DECL_NSIDOMNSXBLFORMCONTROL

  nsDOMNSXBLFormControl();

private:
  ~nsDOMNSXBLFormControl();

protected:
  /* additional members */
};

/* Implementation file */
NS_IMPL_ISUPPORTS1(nsDOMNSXBLFormControl, nsIDOMNSXBLFormControl)

nsDOMNSXBLFormControl::nsDOMNSXBLFormControl()
{
  /* member initializers and constructor code */
}

nsDOMNSXBLFormControl::~nsDOMNSXBLFormControl()
{
  /* destructor code */
}

/* readonly attribute nsIBoxObject boxObject; */
NS_IMETHODIMP nsDOMNSXBLFormControl::GetBoxObject(nsIBoxObject * *aBoxObject)
{
    return NS_ERROR_NOT_IMPLEMENTED;
}

/* End of implementation class template. */
#endif


#endif /* __gen_nsIDOMNSXBLFormControl_h__ */
