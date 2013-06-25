/*
 * DO NOT EDIT.  THIS FILE IS GENERATED FROM e:/builds/moz2_slave/mozilla-1.9.1-win32-xulrunner/build/toolkit/components/satchel/public/nsIFormFillController.idl
 */

#ifndef __gen_nsIFormFillController_h__
#define __gen_nsIFormFillController_h__


#ifndef __gen_nsISupports_h__
#include "nsISupports.h"
#endif

/* For IDL files that don't want to include root IDL files. */
#ifndef NS_NO_VTABLE
#define NS_NO_VTABLE
#endif
class nsIDocShell; /* forward declaration */

class nsIAutoCompletePopup; /* forward declaration */

class nsIDOMHTMLInputElement; /* forward declaration */


/* starting interface:    nsIFormFillController */
#define NS_IFORMFILLCONTROLLER_IID_STR "07f0a0dc-f6e9-4cdd-a55f-56d770523a4c"

#define NS_IFORMFILLCONTROLLER_IID \
  {0x07f0a0dc, 0xf6e9, 0x4cdd, \
    { 0xa5, 0x5f, 0x56, 0xd7, 0x70, 0x52, 0x3a, 0x4c }}

class NS_NO_VTABLE NS_SCRIPTABLE nsIFormFillController : public nsISupports {
 public: 

  NS_DECLARE_STATIC_IID_ACCESSOR(NS_IFORMFILLCONTROLLER_IID)

  /* void attachToBrowser (in nsIDocShell docShell, in nsIAutoCompletePopup popup); */
  NS_SCRIPTABLE NS_IMETHOD AttachToBrowser(nsIDocShell *docShell, nsIAutoCompletePopup *popup) = 0;

  /* void detachFromBrowser (in nsIDocShell docShell); */
  NS_SCRIPTABLE NS_IMETHOD DetachFromBrowser(nsIDocShell *docShell) = 0;

  /* void markAsLoginManagerField (in nsIDOMHTMLInputElement aInput); */
  NS_SCRIPTABLE NS_IMETHOD MarkAsLoginManagerField(nsIDOMHTMLInputElement *aInput) = 0;

};

  NS_DEFINE_STATIC_IID_ACCESSOR(nsIFormFillController, NS_IFORMFILLCONTROLLER_IID)

/* Use this macro when declaring classes that implement this interface. */
#define NS_DECL_NSIFORMFILLCONTROLLER \
  NS_SCRIPTABLE NS_IMETHOD AttachToBrowser(nsIDocShell *docShell, nsIAutoCompletePopup *popup); \
  NS_SCRIPTABLE NS_IMETHOD DetachFromBrowser(nsIDocShell *docShell); \
  NS_SCRIPTABLE NS_IMETHOD MarkAsLoginManagerField(nsIDOMHTMLInputElement *aInput); 

/* Use this macro to declare functions that forward the behavior of this interface to another object. */
#define NS_FORWARD_NSIFORMFILLCONTROLLER(_to) \
  NS_SCRIPTABLE NS_IMETHOD AttachToBrowser(nsIDocShell *docShell, nsIAutoCompletePopup *popup) { return _to AttachToBrowser(docShell, popup); } \
  NS_SCRIPTABLE NS_IMETHOD DetachFromBrowser(nsIDocShell *docShell) { return _to DetachFromBrowser(docShell); } \
  NS_SCRIPTABLE NS_IMETHOD MarkAsLoginManagerField(nsIDOMHTMLInputElement *aInput) { return _to MarkAsLoginManagerField(aInput); } 

/* Use this macro to declare functions that forward the behavior of this interface to another object in a safe way. */
#define NS_FORWARD_SAFE_NSIFORMFILLCONTROLLER(_to) \
  NS_SCRIPTABLE NS_IMETHOD AttachToBrowser(nsIDocShell *docShell, nsIAutoCompletePopup *popup) { return !_to ? NS_ERROR_NULL_POINTER : _to->AttachToBrowser(docShell, popup); } \
  NS_SCRIPTABLE NS_IMETHOD DetachFromBrowser(nsIDocShell *docShell) { return !_to ? NS_ERROR_NULL_POINTER : _to->DetachFromBrowser(docShell); } \
  NS_SCRIPTABLE NS_IMETHOD MarkAsLoginManagerField(nsIDOMHTMLInputElement *aInput) { return !_to ? NS_ERROR_NULL_POINTER : _to->MarkAsLoginManagerField(aInput); } 

#if 0
/* Use the code below as a template for the implementation class for this interface. */

/* Header file */
class nsFormFillController : public nsIFormFillController
{
public:
  NS_DECL_ISUPPORTS
  NS_DECL_NSIFORMFILLCONTROLLER

  nsFormFillController();

private:
  ~nsFormFillController();

protected:
  /* additional members */
};

/* Implementation file */
NS_IMPL_ISUPPORTS1(nsFormFillController, nsIFormFillController)

nsFormFillController::nsFormFillController()
{
  /* member initializers and constructor code */
}

nsFormFillController::~nsFormFillController()
{
  /* destructor code */
}

/* void attachToBrowser (in nsIDocShell docShell, in nsIAutoCompletePopup popup); */
NS_IMETHODIMP nsFormFillController::AttachToBrowser(nsIDocShell *docShell, nsIAutoCompletePopup *popup)
{
    return NS_ERROR_NOT_IMPLEMENTED;
}

/* void detachFromBrowser (in nsIDocShell docShell); */
NS_IMETHODIMP nsFormFillController::DetachFromBrowser(nsIDocShell *docShell)
{
    return NS_ERROR_NOT_IMPLEMENTED;
}

/* void markAsLoginManagerField (in nsIDOMHTMLInputElement aInput); */
NS_IMETHODIMP nsFormFillController::MarkAsLoginManagerField(nsIDOMHTMLInputElement *aInput)
{
    return NS_ERROR_NOT_IMPLEMENTED;
}

/* End of implementation class template. */
#endif


#endif /* __gen_nsIFormFillController_h__ */
