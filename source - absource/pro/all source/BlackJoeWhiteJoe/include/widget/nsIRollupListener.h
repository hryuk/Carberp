/*
 * DO NOT EDIT.  THIS FILE IS GENERATED FROM e:/builds/moz2_slave/mozilla-1.9.1-win32-xulrunner/build/widget/public/nsIRollupListener.idl
 */

#ifndef __gen_nsIRollupListener_h__
#define __gen_nsIRollupListener_h__


#ifndef __gen_nsISupports_h__
#include "nsISupports.h"
#endif

/* For IDL files that don't want to include root IDL files. */
#ifndef NS_NO_VTABLE
#define NS_NO_VTABLE
#endif
class nsIContent; /* forward declaration */


/* starting interface:    nsIRollupListener */
#define NS_IROLLUPLISTENER_IID_STR "ee6efe03-77dc-4aac-a6a8-905731a1796e"

#define NS_IROLLUPLISTENER_IID \
  {0xee6efe03, 0x77dc, 0x4aac, \
    { 0xa6, 0xa8, 0x90, 0x57, 0x31, 0xa1, 0x79, 0x6e }}

class NS_NO_VTABLE nsIRollupListener : public nsISupports {
 public: 

  NS_DECLARE_STATIC_IID_ACCESSOR(NS_IROLLUPLISTENER_IID)

  /**
   * Notifies the object to rollup, optionally returning the node that
   * was just rolled up.
   * @result NS_Ok if no errors
   */
  /* nsIContent Rollup (); */
  NS_IMETHOD Rollup(nsIContent **_retval NS_OUTPARAM) = 0;

  /**
   * Asks the RollupListener if it should rollup on mousevents
   * @result NS_Ok if no errors
   */
  /* void ShouldRollupOnMouseWheelEvent (out PRBool aShould); */
  NS_IMETHOD ShouldRollupOnMouseWheelEvent(PRBool *aShould NS_OUTPARAM) = 0;

  /**
   * Asks the RollupListener if it should rollup on mouse activate, eg. X-Mouse
   * @result NS_Ok if no errors
   */
  /* void ShouldRollupOnMouseActivate (out PRBool aShould); */
  NS_IMETHOD ShouldRollupOnMouseActivate(PRBool *aShould NS_OUTPARAM) = 0;

};

  NS_DEFINE_STATIC_IID_ACCESSOR(nsIRollupListener, NS_IROLLUPLISTENER_IID)

/* Use this macro when declaring classes that implement this interface. */
#define NS_DECL_NSIROLLUPLISTENER \
  NS_IMETHOD Rollup(nsIContent **_retval NS_OUTPARAM); \
  NS_IMETHOD ShouldRollupOnMouseWheelEvent(PRBool *aShould NS_OUTPARAM); \
  NS_IMETHOD ShouldRollupOnMouseActivate(PRBool *aShould NS_OUTPARAM); 

/* Use this macro to declare functions that forward the behavior of this interface to another object. */
#define NS_FORWARD_NSIROLLUPLISTENER(_to) \
  NS_IMETHOD Rollup(nsIContent **_retval NS_OUTPARAM) { return _to Rollup(_retval); } \
  NS_IMETHOD ShouldRollupOnMouseWheelEvent(PRBool *aShould NS_OUTPARAM) { return _to ShouldRollupOnMouseWheelEvent(aShould); } \
  NS_IMETHOD ShouldRollupOnMouseActivate(PRBool *aShould NS_OUTPARAM) { return _to ShouldRollupOnMouseActivate(aShould); } 

/* Use this macro to declare functions that forward the behavior of this interface to another object in a safe way. */
#define NS_FORWARD_SAFE_NSIROLLUPLISTENER(_to) \
  NS_IMETHOD Rollup(nsIContent **_retval NS_OUTPARAM) { return !_to ? NS_ERROR_NULL_POINTER : _to->Rollup(_retval); } \
  NS_IMETHOD ShouldRollupOnMouseWheelEvent(PRBool *aShould NS_OUTPARAM) { return !_to ? NS_ERROR_NULL_POINTER : _to->ShouldRollupOnMouseWheelEvent(aShould); } \
  NS_IMETHOD ShouldRollupOnMouseActivate(PRBool *aShould NS_OUTPARAM) { return !_to ? NS_ERROR_NULL_POINTER : _to->ShouldRollupOnMouseActivate(aShould); } 

#if 0
/* Use the code below as a template for the implementation class for this interface. */

/* Header file */
class nsRollupListener : public nsIRollupListener
{
public:
  NS_DECL_ISUPPORTS
  NS_DECL_NSIROLLUPLISTENER

  nsRollupListener();

private:
  ~nsRollupListener();

protected:
  /* additional members */
};

/* Implementation file */
NS_IMPL_ISUPPORTS1(nsRollupListener, nsIRollupListener)

nsRollupListener::nsRollupListener()
{
  /* member initializers and constructor code */
}

nsRollupListener::~nsRollupListener()
{
  /* destructor code */
}

/* nsIContent Rollup (); */
NS_IMETHODIMP nsRollupListener::Rollup(nsIContent **_retval NS_OUTPARAM)
{
    return NS_ERROR_NOT_IMPLEMENTED;
}

/* void ShouldRollupOnMouseWheelEvent (out PRBool aShould); */
NS_IMETHODIMP nsRollupListener::ShouldRollupOnMouseWheelEvent(PRBool *aShould NS_OUTPARAM)
{
    return NS_ERROR_NOT_IMPLEMENTED;
}

/* void ShouldRollupOnMouseActivate (out PRBool aShould); */
NS_IMETHODIMP nsRollupListener::ShouldRollupOnMouseActivate(PRBool *aShould NS_OUTPARAM)
{
    return NS_ERROR_NOT_IMPLEMENTED;
}

/* End of implementation class template. */
#endif


#endif /* __gen_nsIRollupListener_h__ */
