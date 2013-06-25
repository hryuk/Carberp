/*
 * DO NOT EDIT.  THIS FILE IS GENERATED FROM e:/builds/moz2_slave/mozilla-1.9.1-win32-xulrunner/build/dom/public/idl/base/nsIDOMModalContentWindow.idl
 */

#ifndef __gen_nsIDOMModalContentWindow_h__
#define __gen_nsIDOMModalContentWindow_h__


#ifndef __gen_nsISupports_h__
#include "nsISupports.h"
#endif

/* For IDL files that don't want to include root IDL files. */
#ifndef NS_NO_VTABLE
#define NS_NO_VTABLE
#endif
class nsIVariant; /* forward declaration */

class nsIArray; /* forward declaration */


/* starting interface:    nsIDOMModalContentWindow */
#define NS_IDOMMODALCONTENTWINDOW_IID_STR "51aebd45-b979-4ec6-9d11-3a3fd3d5d59e"

#define NS_IDOMMODALCONTENTWINDOW_IID \
  {0x51aebd45, 0xb979, 0x4ec6, \
    { 0x9d, 0x11, 0x3a, 0x3f, 0xd3, 0xd5, 0xd5, 0x9e }}

class NS_NO_VTABLE NS_SCRIPTABLE nsIDOMModalContentWindow : public nsISupports {
 public: 

  NS_DECLARE_STATIC_IID_ACCESSOR(NS_IDOMMODALCONTENTWINDOW_IID)

  /**
   * Readonly attribute containing an array of arguments that was
   * passed to the code that opened this modal content window.
   */
  /* readonly attribute nsIArray dialogArguments; */
  NS_SCRIPTABLE NS_IMETHOD GetDialogArguments(nsIArray * *aDialogArguments) = 0;

  /**
   * The return value that will be returned to the function that
   * opened the modal content window.
   */
  /* attribute nsIVariant returnValue; */
  NS_SCRIPTABLE NS_IMETHOD GetReturnValue(nsIVariant * *aReturnValue) = 0;
  NS_SCRIPTABLE NS_IMETHOD SetReturnValue(nsIVariant * aReturnValue) = 0;

};

  NS_DEFINE_STATIC_IID_ACCESSOR(nsIDOMModalContentWindow, NS_IDOMMODALCONTENTWINDOW_IID)

/* Use this macro when declaring classes that implement this interface. */
#define NS_DECL_NSIDOMMODALCONTENTWINDOW \
  NS_SCRIPTABLE NS_IMETHOD GetDialogArguments(nsIArray * *aDialogArguments); \
  NS_SCRIPTABLE NS_IMETHOD GetReturnValue(nsIVariant * *aReturnValue); \
  NS_SCRIPTABLE NS_IMETHOD SetReturnValue(nsIVariant * aReturnValue); 

/* Use this macro to declare functions that forward the behavior of this interface to another object. */
#define NS_FORWARD_NSIDOMMODALCONTENTWINDOW(_to) \
  NS_SCRIPTABLE NS_IMETHOD GetDialogArguments(nsIArray * *aDialogArguments) { return _to GetDialogArguments(aDialogArguments); } \
  NS_SCRIPTABLE NS_IMETHOD GetReturnValue(nsIVariant * *aReturnValue) { return _to GetReturnValue(aReturnValue); } \
  NS_SCRIPTABLE NS_IMETHOD SetReturnValue(nsIVariant * aReturnValue) { return _to SetReturnValue(aReturnValue); } 

/* Use this macro to declare functions that forward the behavior of this interface to another object in a safe way. */
#define NS_FORWARD_SAFE_NSIDOMMODALCONTENTWINDOW(_to) \
  NS_SCRIPTABLE NS_IMETHOD GetDialogArguments(nsIArray * *aDialogArguments) { return !_to ? NS_ERROR_NULL_POINTER : _to->GetDialogArguments(aDialogArguments); } \
  NS_SCRIPTABLE NS_IMETHOD GetReturnValue(nsIVariant * *aReturnValue) { return !_to ? NS_ERROR_NULL_POINTER : _to->GetReturnValue(aReturnValue); } \
  NS_SCRIPTABLE NS_IMETHOD SetReturnValue(nsIVariant * aReturnValue) { return !_to ? NS_ERROR_NULL_POINTER : _to->SetReturnValue(aReturnValue); } 

#if 0
/* Use the code below as a template for the implementation class for this interface. */

/* Header file */
class nsDOMModalContentWindow : public nsIDOMModalContentWindow
{
public:
  NS_DECL_ISUPPORTS
  NS_DECL_NSIDOMMODALCONTENTWINDOW

  nsDOMModalContentWindow();

private:
  ~nsDOMModalContentWindow();

protected:
  /* additional members */
};

/* Implementation file */
NS_IMPL_ISUPPORTS1(nsDOMModalContentWindow, nsIDOMModalContentWindow)

nsDOMModalContentWindow::nsDOMModalContentWindow()
{
  /* member initializers and constructor code */
}

nsDOMModalContentWindow::~nsDOMModalContentWindow()
{
  /* destructor code */
}

/* readonly attribute nsIArray dialogArguments; */
NS_IMETHODIMP nsDOMModalContentWindow::GetDialogArguments(nsIArray * *aDialogArguments)
{
    return NS_ERROR_NOT_IMPLEMENTED;
}

/* attribute nsIVariant returnValue; */
NS_IMETHODIMP nsDOMModalContentWindow::GetReturnValue(nsIVariant * *aReturnValue)
{
    return NS_ERROR_NOT_IMPLEMENTED;
}
NS_IMETHODIMP nsDOMModalContentWindow::SetReturnValue(nsIVariant * aReturnValue)
{
    return NS_ERROR_NOT_IMPLEMENTED;
}

/* End of implementation class template. */
#endif


#endif /* __gen_nsIDOMModalContentWindow_h__ */
