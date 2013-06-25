/*
 * DO NOT EDIT.  THIS FILE IS GENERATED FROM e:/builds/moz2_slave/mozilla-1.9.1-win32-xulrunner/build/dom/public/idl/events/nsIDOMMouseScrollEvent.idl
 */

#ifndef __gen_nsIDOMMouseScrollEvent_h__
#define __gen_nsIDOMMouseScrollEvent_h__


#ifndef __gen_domstubs_h__
#include "domstubs.h"
#endif

/* For IDL files that don't want to include root IDL files. */
#ifndef NS_NO_VTABLE
#define NS_NO_VTABLE
#endif

/* starting interface:    nsIDOMMouseScrollEvent */
#define NS_IDOMMOUSESCROLLEVENT_IID_STR "f172af88-48c3-4989-b814-60449823fc7d"

#define NS_IDOMMOUSESCROLLEVENT_IID \
  {0xf172af88, 0x48c3, 0x4989, \
    { 0xb8, 0x14, 0x60, 0x44, 0x98, 0x23, 0xfc, 0x7d }}

class NS_NO_VTABLE NS_SCRIPTABLE nsIDOMMouseScrollEvent : public nsISupports {
 public: 

  NS_DECLARE_STATIC_IID_ACCESSOR(NS_IDOMMOUSESCROLLEVENT_IID)

  enum { HORIZONTAL_AXIS = 1 };

  enum { VERTICAL_AXIS = 2 };

  /* readonly attribute long axis; */
  NS_SCRIPTABLE NS_IMETHOD GetAxis(PRInt32 *aAxis) = 0;

  /* void initMouseScrollEvent (in DOMString typeArg, in boolean canBubbleArg, in boolean cancelableArg, in nsIDOMAbstractView viewArg, in long detailArg, in long screenXArg, in long screenYArg, in long clientXArg, in long clientYArg, in boolean ctrlKeyArg, in boolean altKeyArg, in boolean shiftKeyArg, in boolean metaKeyArg, in unsigned short buttonArg, in nsIDOMEventTarget relatedTargetArg, in long axis); */
  NS_SCRIPTABLE NS_IMETHOD InitMouseScrollEvent(const nsAString & typeArg, PRBool canBubbleArg, PRBool cancelableArg, nsIDOMAbstractView *viewArg, PRInt32 detailArg, PRInt32 screenXArg, PRInt32 screenYArg, PRInt32 clientXArg, PRInt32 clientYArg, PRBool ctrlKeyArg, PRBool altKeyArg, PRBool shiftKeyArg, PRBool metaKeyArg, PRUint16 buttonArg, nsIDOMEventTarget *relatedTargetArg, PRInt32 axis) = 0;

};

  NS_DEFINE_STATIC_IID_ACCESSOR(nsIDOMMouseScrollEvent, NS_IDOMMOUSESCROLLEVENT_IID)

/* Use this macro when declaring classes that implement this interface. */
#define NS_DECL_NSIDOMMOUSESCROLLEVENT \
  NS_SCRIPTABLE NS_IMETHOD GetAxis(PRInt32 *aAxis); \
  NS_SCRIPTABLE NS_IMETHOD InitMouseScrollEvent(const nsAString & typeArg, PRBool canBubbleArg, PRBool cancelableArg, nsIDOMAbstractView *viewArg, PRInt32 detailArg, PRInt32 screenXArg, PRInt32 screenYArg, PRInt32 clientXArg, PRInt32 clientYArg, PRBool ctrlKeyArg, PRBool altKeyArg, PRBool shiftKeyArg, PRBool metaKeyArg, PRUint16 buttonArg, nsIDOMEventTarget *relatedTargetArg, PRInt32 axis); 

/* Use this macro to declare functions that forward the behavior of this interface to another object. */
#define NS_FORWARD_NSIDOMMOUSESCROLLEVENT(_to) \
  NS_SCRIPTABLE NS_IMETHOD GetAxis(PRInt32 *aAxis) { return _to GetAxis(aAxis); } \
  NS_SCRIPTABLE NS_IMETHOD InitMouseScrollEvent(const nsAString & typeArg, PRBool canBubbleArg, PRBool cancelableArg, nsIDOMAbstractView *viewArg, PRInt32 detailArg, PRInt32 screenXArg, PRInt32 screenYArg, PRInt32 clientXArg, PRInt32 clientYArg, PRBool ctrlKeyArg, PRBool altKeyArg, PRBool shiftKeyArg, PRBool metaKeyArg, PRUint16 buttonArg, nsIDOMEventTarget *relatedTargetArg, PRInt32 axis) { return _to InitMouseScrollEvent(typeArg, canBubbleArg, cancelableArg, viewArg, detailArg, screenXArg, screenYArg, clientXArg, clientYArg, ctrlKeyArg, altKeyArg, shiftKeyArg, metaKeyArg, buttonArg, relatedTargetArg, axis); } 

/* Use this macro to declare functions that forward the behavior of this interface to another object in a safe way. */
#define NS_FORWARD_SAFE_NSIDOMMOUSESCROLLEVENT(_to) \
  NS_SCRIPTABLE NS_IMETHOD GetAxis(PRInt32 *aAxis) { return !_to ? NS_ERROR_NULL_POINTER : _to->GetAxis(aAxis); } \
  NS_SCRIPTABLE NS_IMETHOD InitMouseScrollEvent(const nsAString & typeArg, PRBool canBubbleArg, PRBool cancelableArg, nsIDOMAbstractView *viewArg, PRInt32 detailArg, PRInt32 screenXArg, PRInt32 screenYArg, PRInt32 clientXArg, PRInt32 clientYArg, PRBool ctrlKeyArg, PRBool altKeyArg, PRBool shiftKeyArg, PRBool metaKeyArg, PRUint16 buttonArg, nsIDOMEventTarget *relatedTargetArg, PRInt32 axis) { return !_to ? NS_ERROR_NULL_POINTER : _to->InitMouseScrollEvent(typeArg, canBubbleArg, cancelableArg, viewArg, detailArg, screenXArg, screenYArg, clientXArg, clientYArg, ctrlKeyArg, altKeyArg, shiftKeyArg, metaKeyArg, buttonArg, relatedTargetArg, axis); } 

#if 0
/* Use the code below as a template for the implementation class for this interface. */

/* Header file */
class nsDOMMouseScrollEvent : public nsIDOMMouseScrollEvent
{
public:
  NS_DECL_ISUPPORTS
  NS_DECL_NSIDOMMOUSESCROLLEVENT

  nsDOMMouseScrollEvent();

private:
  ~nsDOMMouseScrollEvent();

protected:
  /* additional members */
};

/* Implementation file */
NS_IMPL_ISUPPORTS1(nsDOMMouseScrollEvent, nsIDOMMouseScrollEvent)

nsDOMMouseScrollEvent::nsDOMMouseScrollEvent()
{
  /* member initializers and constructor code */
}

nsDOMMouseScrollEvent::~nsDOMMouseScrollEvent()
{
  /* destructor code */
}

/* readonly attribute long axis; */
NS_IMETHODIMP nsDOMMouseScrollEvent::GetAxis(PRInt32 *aAxis)
{
    return NS_ERROR_NOT_IMPLEMENTED;
}

/* void initMouseScrollEvent (in DOMString typeArg, in boolean canBubbleArg, in boolean cancelableArg, in nsIDOMAbstractView viewArg, in long detailArg, in long screenXArg, in long screenYArg, in long clientXArg, in long clientYArg, in boolean ctrlKeyArg, in boolean altKeyArg, in boolean shiftKeyArg, in boolean metaKeyArg, in unsigned short buttonArg, in nsIDOMEventTarget relatedTargetArg, in long axis); */
NS_IMETHODIMP nsDOMMouseScrollEvent::InitMouseScrollEvent(const nsAString & typeArg, PRBool canBubbleArg, PRBool cancelableArg, nsIDOMAbstractView *viewArg, PRInt32 detailArg, PRInt32 screenXArg, PRInt32 screenYArg, PRInt32 clientXArg, PRInt32 clientYArg, PRBool ctrlKeyArg, PRBool altKeyArg, PRBool shiftKeyArg, PRBool metaKeyArg, PRUint16 buttonArg, nsIDOMEventTarget *relatedTargetArg, PRInt32 axis)
{
    return NS_ERROR_NOT_IMPLEMENTED;
}

/* End of implementation class template. */
#endif


#endif /* __gen_nsIDOMMouseScrollEvent_h__ */
