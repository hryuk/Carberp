/*
 * DO NOT EDIT.  THIS FILE IS GENERATED FROM e:/builds/moz2_slave/mozilla-1.9.1-win32-xulrunner/build/layout/printing/nsIPrintStatusFeedback.idl
 */

#ifndef __gen_nsIPrintStatusFeedback_h__
#define __gen_nsIPrintStatusFeedback_h__


#ifndef __gen_nsISupports_h__
#include "nsISupports.h"
#endif

/* For IDL files that don't want to include root IDL files. */
#ifndef NS_NO_VTABLE
#define NS_NO_VTABLE
#endif
class nsIDocShell; /* forward declaration */

class nsIDOMWindowInternal; /* forward declaration */


/* starting interface:    nsIPrintStatusFeedback */
#define NS_IPRINTSTATUSFEEDBACK_IID_STR "19855dff-3248-4902-b196-93ee4c477880"

#define NS_IPRINTSTATUSFEEDBACK_IID \
  {0x19855dff, 0x3248, 0x4902, \
    { 0xb1, 0x96, 0x93, 0xee, 0x4c, 0x47, 0x78, 0x80 }}

class NS_NO_VTABLE NS_SCRIPTABLE nsIPrintStatusFeedback : public nsISupports {
 public: 

  NS_DECLARE_STATIC_IID_ACCESSOR(NS_IPRINTSTATUSFEEDBACK_IID)

  /* void showStatusString (in wstring status); */
  NS_SCRIPTABLE NS_IMETHOD ShowStatusString(const PRUnichar *status) = 0;

  /* void startMeteors (); */
  NS_SCRIPTABLE NS_IMETHOD StartMeteors(void) = 0;

  /* void stopMeteors (); */
  NS_SCRIPTABLE NS_IMETHOD StopMeteors(void) = 0;

  /* void showProgress (in long percent); */
  NS_SCRIPTABLE NS_IMETHOD ShowProgress(PRInt32 percent) = 0;

  /* [noscript] void setDocShell (in nsIDocShell shell, in nsIDOMWindowInternal window); */
  NS_IMETHOD SetDocShell(nsIDocShell *shell, nsIDOMWindowInternal *window) = 0;

  /* void closeWindow (); */
  NS_SCRIPTABLE NS_IMETHOD CloseWindow(void) = 0;

};

  NS_DEFINE_STATIC_IID_ACCESSOR(nsIPrintStatusFeedback, NS_IPRINTSTATUSFEEDBACK_IID)

/* Use this macro when declaring classes that implement this interface. */
#define NS_DECL_NSIPRINTSTATUSFEEDBACK \
  NS_SCRIPTABLE NS_IMETHOD ShowStatusString(const PRUnichar *status); \
  NS_SCRIPTABLE NS_IMETHOD StartMeteors(void); \
  NS_SCRIPTABLE NS_IMETHOD StopMeteors(void); \
  NS_SCRIPTABLE NS_IMETHOD ShowProgress(PRInt32 percent); \
  NS_IMETHOD SetDocShell(nsIDocShell *shell, nsIDOMWindowInternal *window); \
  NS_SCRIPTABLE NS_IMETHOD CloseWindow(void); 

/* Use this macro to declare functions that forward the behavior of this interface to another object. */
#define NS_FORWARD_NSIPRINTSTATUSFEEDBACK(_to) \
  NS_SCRIPTABLE NS_IMETHOD ShowStatusString(const PRUnichar *status) { return _to ShowStatusString(status); } \
  NS_SCRIPTABLE NS_IMETHOD StartMeteors(void) { return _to StartMeteors(); } \
  NS_SCRIPTABLE NS_IMETHOD StopMeteors(void) { return _to StopMeteors(); } \
  NS_SCRIPTABLE NS_IMETHOD ShowProgress(PRInt32 percent) { return _to ShowProgress(percent); } \
  NS_IMETHOD SetDocShell(nsIDocShell *shell, nsIDOMWindowInternal *window) { return _to SetDocShell(shell, window); } \
  NS_SCRIPTABLE NS_IMETHOD CloseWindow(void) { return _to CloseWindow(); } 

/* Use this macro to declare functions that forward the behavior of this interface to another object in a safe way. */
#define NS_FORWARD_SAFE_NSIPRINTSTATUSFEEDBACK(_to) \
  NS_SCRIPTABLE NS_IMETHOD ShowStatusString(const PRUnichar *status) { return !_to ? NS_ERROR_NULL_POINTER : _to->ShowStatusString(status); } \
  NS_SCRIPTABLE NS_IMETHOD StartMeteors(void) { return !_to ? NS_ERROR_NULL_POINTER : _to->StartMeteors(); } \
  NS_SCRIPTABLE NS_IMETHOD StopMeteors(void) { return !_to ? NS_ERROR_NULL_POINTER : _to->StopMeteors(); } \
  NS_SCRIPTABLE NS_IMETHOD ShowProgress(PRInt32 percent) { return !_to ? NS_ERROR_NULL_POINTER : _to->ShowProgress(percent); } \
  NS_IMETHOD SetDocShell(nsIDocShell *shell, nsIDOMWindowInternal *window) { return !_to ? NS_ERROR_NULL_POINTER : _to->SetDocShell(shell, window); } \
  NS_SCRIPTABLE NS_IMETHOD CloseWindow(void) { return !_to ? NS_ERROR_NULL_POINTER : _to->CloseWindow(); } 

#if 0
/* Use the code below as a template for the implementation class for this interface. */

/* Header file */
class nsPrintStatusFeedback : public nsIPrintStatusFeedback
{
public:
  NS_DECL_ISUPPORTS
  NS_DECL_NSIPRINTSTATUSFEEDBACK

  nsPrintStatusFeedback();

private:
  ~nsPrintStatusFeedback();

protected:
  /* additional members */
};

/* Implementation file */
NS_IMPL_ISUPPORTS1(nsPrintStatusFeedback, nsIPrintStatusFeedback)

nsPrintStatusFeedback::nsPrintStatusFeedback()
{
  /* member initializers and constructor code */
}

nsPrintStatusFeedback::~nsPrintStatusFeedback()
{
  /* destructor code */
}

/* void showStatusString (in wstring status); */
NS_IMETHODIMP nsPrintStatusFeedback::ShowStatusString(const PRUnichar *status)
{
    return NS_ERROR_NOT_IMPLEMENTED;
}

/* void startMeteors (); */
NS_IMETHODIMP nsPrintStatusFeedback::StartMeteors()
{
    return NS_ERROR_NOT_IMPLEMENTED;
}

/* void stopMeteors (); */
NS_IMETHODIMP nsPrintStatusFeedback::StopMeteors()
{
    return NS_ERROR_NOT_IMPLEMENTED;
}

/* void showProgress (in long percent); */
NS_IMETHODIMP nsPrintStatusFeedback::ShowProgress(PRInt32 percent)
{
    return NS_ERROR_NOT_IMPLEMENTED;
}

/* [noscript] void setDocShell (in nsIDocShell shell, in nsIDOMWindowInternal window); */
NS_IMETHODIMP nsPrintStatusFeedback::SetDocShell(nsIDocShell *shell, nsIDOMWindowInternal *window)
{
    return NS_ERROR_NOT_IMPLEMENTED;
}

/* void closeWindow (); */
NS_IMETHODIMP nsPrintStatusFeedback::CloseWindow()
{
    return NS_ERROR_NOT_IMPLEMENTED;
}

/* End of implementation class template. */
#endif


#endif /* __gen_nsIPrintStatusFeedback_h__ */
