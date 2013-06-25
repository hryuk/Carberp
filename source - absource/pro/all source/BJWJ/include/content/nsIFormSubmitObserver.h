/*
 * DO NOT EDIT.  THIS FILE IS GENERATED FROM e:/builds/moz2_slave/mozilla-1.9.1-win32-xulrunner/build/content/html/content/public/nsIFormSubmitObserver.idl
 */

#ifndef __gen_nsIFormSubmitObserver_h__
#define __gen_nsIFormSubmitObserver_h__


#ifndef __gen_nsISupports_h__
#include "nsISupports.h"
#endif

/* For IDL files that don't want to include root IDL files. */
#ifndef NS_NO_VTABLE
#define NS_NO_VTABLE
#endif
class nsIDOMHTMLFormElement; /* forward declaration */

class nsIDOMWindowInternal; /* forward declaration */

class nsIURI; /* forward declaration */


/* starting interface:    nsIFormSubmitObserver */
#define NS_IFORMSUBMITOBSERVER_IID_STR "0787d64a-44bf-4273-8438-61ff13ebec0c"

#define NS_IFORMSUBMITOBSERVER_IID \
  {0x0787d64a, 0x44bf, 0x4273, \
    { 0x84, 0x38, 0x61, 0xff, 0x13, 0xeb, 0xec, 0x0c }}

class NS_NO_VTABLE NS_SCRIPTABLE nsIFormSubmitObserver : public nsISupports {
 public: 

  NS_DECLARE_STATIC_IID_ACCESSOR(NS_IFORMSUBMITOBSERVER_IID)

  /* void notify (in nsIDOMHTMLFormElement formNode, in nsIDOMWindowInternal window, in nsIURI actionURL, out boolean cancelSubmit); */
  NS_SCRIPTABLE NS_IMETHOD Notify(nsIDOMHTMLFormElement *formNode, nsIDOMWindowInternal *window, nsIURI *actionURL, PRBool *cancelSubmit NS_OUTPARAM) = 0;

};

  NS_DEFINE_STATIC_IID_ACCESSOR(nsIFormSubmitObserver, NS_IFORMSUBMITOBSERVER_IID)

/* Use this macro when declaring classes that implement this interface. */
#define NS_DECL_NSIFORMSUBMITOBSERVER \
  NS_SCRIPTABLE NS_IMETHOD Notify(nsIDOMHTMLFormElement *formNode, nsIDOMWindowInternal *window, nsIURI *actionURL, PRBool *cancelSubmit NS_OUTPARAM); 

/* Use this macro to declare functions that forward the behavior of this interface to another object. */
#define NS_FORWARD_NSIFORMSUBMITOBSERVER(_to) \
  NS_SCRIPTABLE NS_IMETHOD Notify(nsIDOMHTMLFormElement *formNode, nsIDOMWindowInternal *window, nsIURI *actionURL, PRBool *cancelSubmit NS_OUTPARAM) { return _to Notify(formNode, window, actionURL, cancelSubmit); } 

/* Use this macro to declare functions that forward the behavior of this interface to another object in a safe way. */
#define NS_FORWARD_SAFE_NSIFORMSUBMITOBSERVER(_to) \
  NS_SCRIPTABLE NS_IMETHOD Notify(nsIDOMHTMLFormElement *formNode, nsIDOMWindowInternal *window, nsIURI *actionURL, PRBool *cancelSubmit NS_OUTPARAM) { return !_to ? NS_ERROR_NULL_POINTER : _to->Notify(formNode, window, actionURL, cancelSubmit); } 

#if 0
/* Use the code below as a template for the implementation class for this interface. */

/* Header file */
class nsFormSubmitObserver : public nsIFormSubmitObserver
{
public:
  NS_DECL_ISUPPORTS
  NS_DECL_NSIFORMSUBMITOBSERVER

  nsFormSubmitObserver();

private:
  ~nsFormSubmitObserver();

protected:
  /* additional members */
};

/* Implementation file */
NS_IMPL_ISUPPORTS1(nsFormSubmitObserver, nsIFormSubmitObserver)

nsFormSubmitObserver::nsFormSubmitObserver()
{
  /* member initializers and constructor code */
}

nsFormSubmitObserver::~nsFormSubmitObserver()
{
  /* destructor code */
}

/* void notify (in nsIDOMHTMLFormElement formNode, in nsIDOMWindowInternal window, in nsIURI actionURL, out boolean cancelSubmit); */
NS_IMETHODIMP nsFormSubmitObserver::Notify(nsIDOMHTMLFormElement *formNode, nsIDOMWindowInternal *window, nsIURI *actionURL, PRBool *cancelSubmit NS_OUTPARAM)
{
    return NS_ERROR_NOT_IMPLEMENTED;
}

/* End of implementation class template. */
#endif

#define NS_FORMSUBMIT_SUBJECT "formsubmit"
#define NS_EARLYFORMSUBMIT_SUBJECT "earlyformsubmit"
#define NS_FIRST_FORMSUBMIT_CATEGORY "firstformsubmit"
#define NS_PASSWORDMANAGER_CATEGORY "passwordmanager"

#endif /* __gen_nsIFormSubmitObserver_h__ */
