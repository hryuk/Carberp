/*
 * DO NOT EDIT.  THIS FILE IS GENERATED FROM e:/builds/moz2_slave/mozilla-1.9.1-win32-xulrunner/build/dom/public/idl/xul/nsIDOMXULCommandDispatcher.idl
 */

#ifndef __gen_nsIDOMXULCommandDispatcher_h__
#define __gen_nsIDOMXULCommandDispatcher_h__


#ifndef __gen_nsISupports_h__
#include "nsISupports.h"
#endif

/* For IDL files that don't want to include root IDL files. */
#ifndef NS_NO_VTABLE
#define NS_NO_VTABLE
#endif
class nsIDOMElement; /* forward declaration */

class nsIController; /* forward declaration */

class nsIControllers; /* forward declaration */

class nsIDOMWindow; /* forward declaration */


/* starting interface:    nsIDOMXULCommandDispatcher */
#define NS_IDOMXULCOMMANDDISPATCHER_IID_STR "f3c50361-14fe-11d3-bf87-00105a1b0627"

#define NS_IDOMXULCOMMANDDISPATCHER_IID \
  {0xf3c50361, 0x14fe, 0x11d3, \
    { 0xbf, 0x87, 0x00, 0x10, 0x5a, 0x1b, 0x06, 0x27 }}

class NS_NO_VTABLE NS_SCRIPTABLE nsIDOMXULCommandDispatcher : public nsISupports {
 public: 

  NS_DECLARE_STATIC_IID_ACCESSOR(NS_IDOMXULCOMMANDDISPATCHER_IID)

  /* attribute nsIDOMElement focusedElement; */
  NS_SCRIPTABLE NS_IMETHOD GetFocusedElement(nsIDOMElement * *aFocusedElement) = 0;
  NS_SCRIPTABLE NS_IMETHOD SetFocusedElement(nsIDOMElement * aFocusedElement) = 0;

  /* attribute nsIDOMWindow focusedWindow; */
  NS_SCRIPTABLE NS_IMETHOD GetFocusedWindow(nsIDOMWindow * *aFocusedWindow) = 0;
  NS_SCRIPTABLE NS_IMETHOD SetFocusedWindow(nsIDOMWindow * aFocusedWindow) = 0;

  /* void addCommandUpdater (in nsIDOMElement updater, in DOMString events, in DOMString targets); */
  NS_SCRIPTABLE NS_IMETHOD AddCommandUpdater(nsIDOMElement *updater, const nsAString & events, const nsAString & targets) = 0;

  /* void removeCommandUpdater (in nsIDOMElement updater); */
  NS_SCRIPTABLE NS_IMETHOD RemoveCommandUpdater(nsIDOMElement *updater) = 0;

  /* void updateCommands (in DOMString eventName); */
  NS_SCRIPTABLE NS_IMETHOD UpdateCommands(const nsAString & eventName) = 0;

  /* nsIController getControllerForCommand (in string command); */
  NS_SCRIPTABLE NS_IMETHOD GetControllerForCommand(const char *command, nsIController **_retval NS_OUTPARAM) = 0;

  /* nsIControllers getControllers (); */
  NS_SCRIPTABLE NS_IMETHOD GetControllers(nsIControllers **_retval NS_OUTPARAM) = 0;

  /* void advanceFocus (); */
  NS_SCRIPTABLE NS_IMETHOD AdvanceFocus(void) = 0;

  /* void rewindFocus (); */
  NS_SCRIPTABLE NS_IMETHOD RewindFocus(void) = 0;

  /* void advanceFocusIntoSubtree (in nsIDOMElement elt); */
  NS_SCRIPTABLE NS_IMETHOD AdvanceFocusIntoSubtree(nsIDOMElement *elt) = 0;

  /* attribute boolean suppressFocusScroll; */
  NS_SCRIPTABLE NS_IMETHOD GetSuppressFocusScroll(PRBool *aSuppressFocusScroll) = 0;
  NS_SCRIPTABLE NS_IMETHOD SetSuppressFocusScroll(PRBool aSuppressFocusScroll) = 0;

};

  NS_DEFINE_STATIC_IID_ACCESSOR(nsIDOMXULCommandDispatcher, NS_IDOMXULCOMMANDDISPATCHER_IID)

/* Use this macro when declaring classes that implement this interface. */
#define NS_DECL_NSIDOMXULCOMMANDDISPATCHER \
  NS_SCRIPTABLE NS_IMETHOD GetFocusedElement(nsIDOMElement * *aFocusedElement); \
  NS_SCRIPTABLE NS_IMETHOD SetFocusedElement(nsIDOMElement * aFocusedElement); \
  NS_SCRIPTABLE NS_IMETHOD GetFocusedWindow(nsIDOMWindow * *aFocusedWindow); \
  NS_SCRIPTABLE NS_IMETHOD SetFocusedWindow(nsIDOMWindow * aFocusedWindow); \
  NS_SCRIPTABLE NS_IMETHOD AddCommandUpdater(nsIDOMElement *updater, const nsAString & events, const nsAString & targets); \
  NS_SCRIPTABLE NS_IMETHOD RemoveCommandUpdater(nsIDOMElement *updater); \
  NS_SCRIPTABLE NS_IMETHOD UpdateCommands(const nsAString & eventName); \
  NS_SCRIPTABLE NS_IMETHOD GetControllerForCommand(const char *command, nsIController **_retval NS_OUTPARAM); \
  NS_SCRIPTABLE NS_IMETHOD GetControllers(nsIControllers **_retval NS_OUTPARAM); \
  NS_SCRIPTABLE NS_IMETHOD AdvanceFocus(void); \
  NS_SCRIPTABLE NS_IMETHOD RewindFocus(void); \
  NS_SCRIPTABLE NS_IMETHOD AdvanceFocusIntoSubtree(nsIDOMElement *elt); \
  NS_SCRIPTABLE NS_IMETHOD GetSuppressFocusScroll(PRBool *aSuppressFocusScroll); \
  NS_SCRIPTABLE NS_IMETHOD SetSuppressFocusScroll(PRBool aSuppressFocusScroll); 

/* Use this macro to declare functions that forward the behavior of this interface to another object. */
#define NS_FORWARD_NSIDOMXULCOMMANDDISPATCHER(_to) \
  NS_SCRIPTABLE NS_IMETHOD GetFocusedElement(nsIDOMElement * *aFocusedElement) { return _to GetFocusedElement(aFocusedElement); } \
  NS_SCRIPTABLE NS_IMETHOD SetFocusedElement(nsIDOMElement * aFocusedElement) { return _to SetFocusedElement(aFocusedElement); } \
  NS_SCRIPTABLE NS_IMETHOD GetFocusedWindow(nsIDOMWindow * *aFocusedWindow) { return _to GetFocusedWindow(aFocusedWindow); } \
  NS_SCRIPTABLE NS_IMETHOD SetFocusedWindow(nsIDOMWindow * aFocusedWindow) { return _to SetFocusedWindow(aFocusedWindow); } \
  NS_SCRIPTABLE NS_IMETHOD AddCommandUpdater(nsIDOMElement *updater, const nsAString & events, const nsAString & targets) { return _to AddCommandUpdater(updater, events, targets); } \
  NS_SCRIPTABLE NS_IMETHOD RemoveCommandUpdater(nsIDOMElement *updater) { return _to RemoveCommandUpdater(updater); } \
  NS_SCRIPTABLE NS_IMETHOD UpdateCommands(const nsAString & eventName) { return _to UpdateCommands(eventName); } \
  NS_SCRIPTABLE NS_IMETHOD GetControllerForCommand(const char *command, nsIController **_retval NS_OUTPARAM) { return _to GetControllerForCommand(command, _retval); } \
  NS_SCRIPTABLE NS_IMETHOD GetControllers(nsIControllers **_retval NS_OUTPARAM) { return _to GetControllers(_retval); } \
  NS_SCRIPTABLE NS_IMETHOD AdvanceFocus(void) { return _to AdvanceFocus(); } \
  NS_SCRIPTABLE NS_IMETHOD RewindFocus(void) { return _to RewindFocus(); } \
  NS_SCRIPTABLE NS_IMETHOD AdvanceFocusIntoSubtree(nsIDOMElement *elt) { return _to AdvanceFocusIntoSubtree(elt); } \
  NS_SCRIPTABLE NS_IMETHOD GetSuppressFocusScroll(PRBool *aSuppressFocusScroll) { return _to GetSuppressFocusScroll(aSuppressFocusScroll); } \
  NS_SCRIPTABLE NS_IMETHOD SetSuppressFocusScroll(PRBool aSuppressFocusScroll) { return _to SetSuppressFocusScroll(aSuppressFocusScroll); } 

/* Use this macro to declare functions that forward the behavior of this interface to another object in a safe way. */
#define NS_FORWARD_SAFE_NSIDOMXULCOMMANDDISPATCHER(_to) \
  NS_SCRIPTABLE NS_IMETHOD GetFocusedElement(nsIDOMElement * *aFocusedElement) { return !_to ? NS_ERROR_NULL_POINTER : _to->GetFocusedElement(aFocusedElement); } \
  NS_SCRIPTABLE NS_IMETHOD SetFocusedElement(nsIDOMElement * aFocusedElement) { return !_to ? NS_ERROR_NULL_POINTER : _to->SetFocusedElement(aFocusedElement); } \
  NS_SCRIPTABLE NS_IMETHOD GetFocusedWindow(nsIDOMWindow * *aFocusedWindow) { return !_to ? NS_ERROR_NULL_POINTER : _to->GetFocusedWindow(aFocusedWindow); } \
  NS_SCRIPTABLE NS_IMETHOD SetFocusedWindow(nsIDOMWindow * aFocusedWindow) { return !_to ? NS_ERROR_NULL_POINTER : _to->SetFocusedWindow(aFocusedWindow); } \
  NS_SCRIPTABLE NS_IMETHOD AddCommandUpdater(nsIDOMElement *updater, const nsAString & events, const nsAString & targets) { return !_to ? NS_ERROR_NULL_POINTER : _to->AddCommandUpdater(updater, events, targets); } \
  NS_SCRIPTABLE NS_IMETHOD RemoveCommandUpdater(nsIDOMElement *updater) { return !_to ? NS_ERROR_NULL_POINTER : _to->RemoveCommandUpdater(updater); } \
  NS_SCRIPTABLE NS_IMETHOD UpdateCommands(const nsAString & eventName) { return !_to ? NS_ERROR_NULL_POINTER : _to->UpdateCommands(eventName); } \
  NS_SCRIPTABLE NS_IMETHOD GetControllerForCommand(const char *command, nsIController **_retval NS_OUTPARAM) { return !_to ? NS_ERROR_NULL_POINTER : _to->GetControllerForCommand(command, _retval); } \
  NS_SCRIPTABLE NS_IMETHOD GetControllers(nsIControllers **_retval NS_OUTPARAM) { return !_to ? NS_ERROR_NULL_POINTER : _to->GetControllers(_retval); } \
  NS_SCRIPTABLE NS_IMETHOD AdvanceFocus(void) { return !_to ? NS_ERROR_NULL_POINTER : _to->AdvanceFocus(); } \
  NS_SCRIPTABLE NS_IMETHOD RewindFocus(void) { return !_to ? NS_ERROR_NULL_POINTER : _to->RewindFocus(); } \
  NS_SCRIPTABLE NS_IMETHOD AdvanceFocusIntoSubtree(nsIDOMElement *elt) { return !_to ? NS_ERROR_NULL_POINTER : _to->AdvanceFocusIntoSubtree(elt); } \
  NS_SCRIPTABLE NS_IMETHOD GetSuppressFocusScroll(PRBool *aSuppressFocusScroll) { return !_to ? NS_ERROR_NULL_POINTER : _to->GetSuppressFocusScroll(aSuppressFocusScroll); } \
  NS_SCRIPTABLE NS_IMETHOD SetSuppressFocusScroll(PRBool aSuppressFocusScroll) { return !_to ? NS_ERROR_NULL_POINTER : _to->SetSuppressFocusScroll(aSuppressFocusScroll); } 

#if 0
/* Use the code below as a template for the implementation class for this interface. */

/* Header file */
class nsDOMXULCommandDispatcher : public nsIDOMXULCommandDispatcher
{
public:
  NS_DECL_ISUPPORTS
  NS_DECL_NSIDOMXULCOMMANDDISPATCHER

  nsDOMXULCommandDispatcher();

private:
  ~nsDOMXULCommandDispatcher();

protected:
  /* additional members */
};

/* Implementation file */
NS_IMPL_ISUPPORTS1(nsDOMXULCommandDispatcher, nsIDOMXULCommandDispatcher)

nsDOMXULCommandDispatcher::nsDOMXULCommandDispatcher()
{
  /* member initializers and constructor code */
}

nsDOMXULCommandDispatcher::~nsDOMXULCommandDispatcher()
{
  /* destructor code */
}

/* attribute nsIDOMElement focusedElement; */
NS_IMETHODIMP nsDOMXULCommandDispatcher::GetFocusedElement(nsIDOMElement * *aFocusedElement)
{
    return NS_ERROR_NOT_IMPLEMENTED;
}
NS_IMETHODIMP nsDOMXULCommandDispatcher::SetFocusedElement(nsIDOMElement * aFocusedElement)
{
    return NS_ERROR_NOT_IMPLEMENTED;
}

/* attribute nsIDOMWindow focusedWindow; */
NS_IMETHODIMP nsDOMXULCommandDispatcher::GetFocusedWindow(nsIDOMWindow * *aFocusedWindow)
{
    return NS_ERROR_NOT_IMPLEMENTED;
}
NS_IMETHODIMP nsDOMXULCommandDispatcher::SetFocusedWindow(nsIDOMWindow * aFocusedWindow)
{
    return NS_ERROR_NOT_IMPLEMENTED;
}

/* void addCommandUpdater (in nsIDOMElement updater, in DOMString events, in DOMString targets); */
NS_IMETHODIMP nsDOMXULCommandDispatcher::AddCommandUpdater(nsIDOMElement *updater, const nsAString & events, const nsAString & targets)
{
    return NS_ERROR_NOT_IMPLEMENTED;
}

/* void removeCommandUpdater (in nsIDOMElement updater); */
NS_IMETHODIMP nsDOMXULCommandDispatcher::RemoveCommandUpdater(nsIDOMElement *updater)
{
    return NS_ERROR_NOT_IMPLEMENTED;
}

/* void updateCommands (in DOMString eventName); */
NS_IMETHODIMP nsDOMXULCommandDispatcher::UpdateCommands(const nsAString & eventName)
{
    return NS_ERROR_NOT_IMPLEMENTED;
}

/* nsIController getControllerForCommand (in string command); */
NS_IMETHODIMP nsDOMXULCommandDispatcher::GetControllerForCommand(const char *command, nsIController **_retval NS_OUTPARAM)
{
    return NS_ERROR_NOT_IMPLEMENTED;
}

/* nsIControllers getControllers (); */
NS_IMETHODIMP nsDOMXULCommandDispatcher::GetControllers(nsIControllers **_retval NS_OUTPARAM)
{
    return NS_ERROR_NOT_IMPLEMENTED;
}

/* void advanceFocus (); */
NS_IMETHODIMP nsDOMXULCommandDispatcher::AdvanceFocus()
{
    return NS_ERROR_NOT_IMPLEMENTED;
}

/* void rewindFocus (); */
NS_IMETHODIMP nsDOMXULCommandDispatcher::RewindFocus()
{
    return NS_ERROR_NOT_IMPLEMENTED;
}

/* void advanceFocusIntoSubtree (in nsIDOMElement elt); */
NS_IMETHODIMP nsDOMXULCommandDispatcher::AdvanceFocusIntoSubtree(nsIDOMElement *elt)
{
    return NS_ERROR_NOT_IMPLEMENTED;
}

/* attribute boolean suppressFocusScroll; */
NS_IMETHODIMP nsDOMXULCommandDispatcher::GetSuppressFocusScroll(PRBool *aSuppressFocusScroll)
{
    return NS_ERROR_NOT_IMPLEMENTED;
}
NS_IMETHODIMP nsDOMXULCommandDispatcher::SetSuppressFocusScroll(PRBool aSuppressFocusScroll)
{
    return NS_ERROR_NOT_IMPLEMENTED;
}

/* End of implementation class template. */
#endif


#endif /* __gen_nsIDOMXULCommandDispatcher_h__ */
