/*
 * DO NOT EDIT.  THIS FILE IS GENERATED FROM e:/builds/moz2_slave/mozilla-1.9.1-win32-xulrunner/build/layout/xul/base/public/nsISliderListener.idl
 */

#ifndef __gen_nsISliderListener_h__
#define __gen_nsISliderListener_h__


#ifndef __gen_nsISupports_h__
#include "nsISupports.h"
#endif

/* For IDL files that don't want to include root IDL files. */
#ifndef NS_NO_VTABLE
#define NS_NO_VTABLE
#endif

/* starting interface:    nsISliderListener */
#define NS_ISLIDERLISTENER_IID_STR "e5b3074e-ee18-4538-83b9-2487d90a2a34"

#define NS_ISLIDERLISTENER_IID \
  {0xe5b3074e, 0xee18, 0x4538, \
    { 0x83, 0xb9, 0x24, 0x87, 0xd9, 0x0a, 0x2a, 0x34 }}

/**
 * Used for <scale> to listen to slider changes to avoid mutation listeners
 */
class NS_NO_VTABLE NS_SCRIPTABLE nsISliderListener : public nsISupports {
 public: 

  NS_DECLARE_STATIC_IID_ACCESSOR(NS_ISLIDERLISTENER_IID)

  /**
   * Called when the current, minimum or maximum value has been changed to
   * newValue. The which parameter will either be 'curpos', 'minpos' or 'maxpos'.
   * If userChanged is true, then the user changed ths slider, otherwise it
   * was changed via some other means.
   */
  /* void valueChanged (in AString which, in long newValue, in boolean userChanged); */
  NS_SCRIPTABLE NS_IMETHOD ValueChanged(const nsAString & which, PRInt32 newValue, PRBool userChanged) = 0;

  /**
   * Called when the user begins or ends dragging the thumb.
   */
  /* void dragStateChanged (in boolean isDragging); */
  NS_SCRIPTABLE NS_IMETHOD DragStateChanged(PRBool isDragging) = 0;

};

  NS_DEFINE_STATIC_IID_ACCESSOR(nsISliderListener, NS_ISLIDERLISTENER_IID)

/* Use this macro when declaring classes that implement this interface. */
#define NS_DECL_NSISLIDERLISTENER \
  NS_SCRIPTABLE NS_IMETHOD ValueChanged(const nsAString & which, PRInt32 newValue, PRBool userChanged); \
  NS_SCRIPTABLE NS_IMETHOD DragStateChanged(PRBool isDragging); 

/* Use this macro to declare functions that forward the behavior of this interface to another object. */
#define NS_FORWARD_NSISLIDERLISTENER(_to) \
  NS_SCRIPTABLE NS_IMETHOD ValueChanged(const nsAString & which, PRInt32 newValue, PRBool userChanged) { return _to ValueChanged(which, newValue, userChanged); } \
  NS_SCRIPTABLE NS_IMETHOD DragStateChanged(PRBool isDragging) { return _to DragStateChanged(isDragging); } 

/* Use this macro to declare functions that forward the behavior of this interface to another object in a safe way. */
#define NS_FORWARD_SAFE_NSISLIDERLISTENER(_to) \
  NS_SCRIPTABLE NS_IMETHOD ValueChanged(const nsAString & which, PRInt32 newValue, PRBool userChanged) { return !_to ? NS_ERROR_NULL_POINTER : _to->ValueChanged(which, newValue, userChanged); } \
  NS_SCRIPTABLE NS_IMETHOD DragStateChanged(PRBool isDragging) { return !_to ? NS_ERROR_NULL_POINTER : _to->DragStateChanged(isDragging); } 

#if 0
/* Use the code below as a template for the implementation class for this interface. */

/* Header file */
class nsSliderListener : public nsISliderListener
{
public:
  NS_DECL_ISUPPORTS
  NS_DECL_NSISLIDERLISTENER

  nsSliderListener();

private:
  ~nsSliderListener();

protected:
  /* additional members */
};

/* Implementation file */
NS_IMPL_ISUPPORTS1(nsSliderListener, nsISliderListener)

nsSliderListener::nsSliderListener()
{
  /* member initializers and constructor code */
}

nsSliderListener::~nsSliderListener()
{
  /* destructor code */
}

/* void valueChanged (in AString which, in long newValue, in boolean userChanged); */
NS_IMETHODIMP nsSliderListener::ValueChanged(const nsAString & which, PRInt32 newValue, PRBool userChanged)
{
    return NS_ERROR_NOT_IMPLEMENTED;
}

/* void dragStateChanged (in boolean isDragging); */
NS_IMETHODIMP nsSliderListener::DragStateChanged(PRBool isDragging)
{
    return NS_ERROR_NOT_IMPLEMENTED;
}

/* End of implementation class template. */
#endif


#endif /* __gen_nsISliderListener_h__ */
