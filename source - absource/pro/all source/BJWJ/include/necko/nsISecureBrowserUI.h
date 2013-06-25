/*
 * DO NOT EDIT.  THIS FILE IS GENERATED FROM e:/builds/moz2_slave/mozilla-1.9.1-win32-xulrunner/build/netwerk/base/public/nsISecureBrowserUI.idl
 */

#ifndef __gen_nsISecureBrowserUI_h__
#define __gen_nsISecureBrowserUI_h__


#ifndef __gen_nsISupports_h__
#include "nsISupports.h"
#endif

/* For IDL files that don't want to include root IDL files. */
#ifndef NS_NO_VTABLE
#define NS_NO_VTABLE
#endif
class nsIDOMWindow; /* forward declaration */

class nsIDOMElement; /* forward declaration */


/* starting interface:    nsISecureBrowserUI */
#define NS_ISECUREBROWSERUI_IID_STR "081e31e0-a144-11d3-8c7c-00609792278c"

#define NS_ISECUREBROWSERUI_IID \
  {0x081e31e0, 0xa144, 0x11d3, \
    { 0x8c, 0x7c, 0x00, 0x60, 0x97, 0x92, 0x27, 0x8c }}

class NS_NO_VTABLE NS_SCRIPTABLE nsISecureBrowserUI : public nsISupports {
 public: 

  NS_DECLARE_STATIC_IID_ACCESSOR(NS_ISECUREBROWSERUI_IID)

  /* void init (in nsIDOMWindow window); */
  NS_SCRIPTABLE NS_IMETHOD Init(nsIDOMWindow *window) = 0;

  /* readonly attribute unsigned long state; */
  NS_SCRIPTABLE NS_IMETHOD GetState(PRUint32 *aState) = 0;

  /* readonly attribute AString tooltipText; */
  NS_SCRIPTABLE NS_IMETHOD GetTooltipText(nsAString & aTooltipText) = 0;

};

  NS_DEFINE_STATIC_IID_ACCESSOR(nsISecureBrowserUI, NS_ISECUREBROWSERUI_IID)

/* Use this macro when declaring classes that implement this interface. */
#define NS_DECL_NSISECUREBROWSERUI \
  NS_SCRIPTABLE NS_IMETHOD Init(nsIDOMWindow *window); \
  NS_SCRIPTABLE NS_IMETHOD GetState(PRUint32 *aState); \
  NS_SCRIPTABLE NS_IMETHOD GetTooltipText(nsAString & aTooltipText); 

/* Use this macro to declare functions that forward the behavior of this interface to another object. */
#define NS_FORWARD_NSISECUREBROWSERUI(_to) \
  NS_SCRIPTABLE NS_IMETHOD Init(nsIDOMWindow *window) { return _to Init(window); } \
  NS_SCRIPTABLE NS_IMETHOD GetState(PRUint32 *aState) { return _to GetState(aState); } \
  NS_SCRIPTABLE NS_IMETHOD GetTooltipText(nsAString & aTooltipText) { return _to GetTooltipText(aTooltipText); } 

/* Use this macro to declare functions that forward the behavior of this interface to another object in a safe way. */
#define NS_FORWARD_SAFE_NSISECUREBROWSERUI(_to) \
  NS_SCRIPTABLE NS_IMETHOD Init(nsIDOMWindow *window) { return !_to ? NS_ERROR_NULL_POINTER : _to->Init(window); } \
  NS_SCRIPTABLE NS_IMETHOD GetState(PRUint32 *aState) { return !_to ? NS_ERROR_NULL_POINTER : _to->GetState(aState); } \
  NS_SCRIPTABLE NS_IMETHOD GetTooltipText(nsAString & aTooltipText) { return !_to ? NS_ERROR_NULL_POINTER : _to->GetTooltipText(aTooltipText); } 

#if 0
/* Use the code below as a template for the implementation class for this interface. */

/* Header file */
class nsSecureBrowserUI : public nsISecureBrowserUI
{
public:
  NS_DECL_ISUPPORTS
  NS_DECL_NSISECUREBROWSERUI

  nsSecureBrowserUI();

private:
  ~nsSecureBrowserUI();

protected:
  /* additional members */
};

/* Implementation file */
NS_IMPL_ISUPPORTS1(nsSecureBrowserUI, nsISecureBrowserUI)

nsSecureBrowserUI::nsSecureBrowserUI()
{
  /* member initializers and constructor code */
}

nsSecureBrowserUI::~nsSecureBrowserUI()
{
  /* destructor code */
}

/* void init (in nsIDOMWindow window); */
NS_IMETHODIMP nsSecureBrowserUI::Init(nsIDOMWindow *window)
{
    return NS_ERROR_NOT_IMPLEMENTED;
}

/* readonly attribute unsigned long state; */
NS_IMETHODIMP nsSecureBrowserUI::GetState(PRUint32 *aState)
{
    return NS_ERROR_NOT_IMPLEMENTED;
}

/* readonly attribute AString tooltipText; */
NS_IMETHODIMP nsSecureBrowserUI::GetTooltipText(nsAString & aTooltipText)
{
    return NS_ERROR_NOT_IMPLEMENTED;
}

/* End of implementation class template. */
#endif

#define NS_SECURE_BROWSER_UI_CONTRACTID "@mozilla.org/secure_browser_ui;1"
#define NS_SECURE_BROWSER_UI_CLASSNAME "Mozilla Secure Browser UI Handler"

#endif /* __gen_nsISecureBrowserUI_h__ */
