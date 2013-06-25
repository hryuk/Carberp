/*
 * DO NOT EDIT.  THIS FILE IS GENERATED FROM e:/builds/moz2_slave/mozilla-1.9.1-win32-xulrunner/build/dom/public/idl/events/nsIDOMMutationEvent.idl
 */

#ifndef __gen_nsIDOMMutationEvent_h__
#define __gen_nsIDOMMutationEvent_h__


#ifndef __gen_nsIDOMEvent_h__
#include "nsIDOMEvent.h"
#endif

/* For IDL files that don't want to include root IDL files. */
#ifndef NS_NO_VTABLE
#define NS_NO_VTABLE
#endif

/* starting interface:    nsIDOMMutationEvent */
#define NS_IDOMMUTATIONEVENT_IID_STR "8e440d86-886a-4e76-9e59-c13b939c9a4b"

#define NS_IDOMMUTATIONEVENT_IID \
  {0x8e440d86, 0x886a, 0x4e76, \
    { 0x9e, 0x59, 0xc1, 0x3b, 0x93, 0x9c, 0x9a, 0x4b }}

class NS_NO_VTABLE NS_SCRIPTABLE nsIDOMMutationEvent : public nsIDOMEvent {
 public: 

  NS_DECLARE_STATIC_IID_ACCESSOR(NS_IDOMMUTATIONEVENT_IID)

  enum { MODIFICATION = 1U };

  enum { ADDITION = 2U };

  enum { REMOVAL = 3U };

  /* readonly attribute nsIDOMNode relatedNode; */
  NS_SCRIPTABLE NS_IMETHOD GetRelatedNode(nsIDOMNode * *aRelatedNode) = 0;

  /* readonly attribute DOMString prevValue; */
  NS_SCRIPTABLE NS_IMETHOD GetPrevValue(nsAString & aPrevValue) = 0;

  /* readonly attribute DOMString newValue; */
  NS_SCRIPTABLE NS_IMETHOD GetNewValue(nsAString & aNewValue) = 0;

  /* readonly attribute DOMString attrName; */
  NS_SCRIPTABLE NS_IMETHOD GetAttrName(nsAString & aAttrName) = 0;

  /* readonly attribute unsigned short attrChange; */
  NS_SCRIPTABLE NS_IMETHOD GetAttrChange(PRUint16 *aAttrChange) = 0;

  /* void initMutationEvent (in DOMString typeArg, in boolean canBubbleArg, in boolean cancelableArg, in nsIDOMNode relatedNodeArg, in DOMString prevValueArg, in DOMString newValueArg, in DOMString attrNameArg, in unsigned short attrChangeArg); */
  NS_SCRIPTABLE NS_IMETHOD InitMutationEvent(const nsAString & typeArg, PRBool canBubbleArg, PRBool cancelableArg, nsIDOMNode *relatedNodeArg, const nsAString & prevValueArg, const nsAString & newValueArg, const nsAString & attrNameArg, PRUint16 attrChangeArg) = 0;

};

  NS_DEFINE_STATIC_IID_ACCESSOR(nsIDOMMutationEvent, NS_IDOMMUTATIONEVENT_IID)

/* Use this macro when declaring classes that implement this interface. */
#define NS_DECL_NSIDOMMUTATIONEVENT \
  NS_SCRIPTABLE NS_IMETHOD GetRelatedNode(nsIDOMNode * *aRelatedNode); \
  NS_SCRIPTABLE NS_IMETHOD GetPrevValue(nsAString & aPrevValue); \
  NS_SCRIPTABLE NS_IMETHOD GetNewValue(nsAString & aNewValue); \
  NS_SCRIPTABLE NS_IMETHOD GetAttrName(nsAString & aAttrName); \
  NS_SCRIPTABLE NS_IMETHOD GetAttrChange(PRUint16 *aAttrChange); \
  NS_SCRIPTABLE NS_IMETHOD InitMutationEvent(const nsAString & typeArg, PRBool canBubbleArg, PRBool cancelableArg, nsIDOMNode *relatedNodeArg, const nsAString & prevValueArg, const nsAString & newValueArg, const nsAString & attrNameArg, PRUint16 attrChangeArg); 

/* Use this macro to declare functions that forward the behavior of this interface to another object. */
#define NS_FORWARD_NSIDOMMUTATIONEVENT(_to) \
  NS_SCRIPTABLE NS_IMETHOD GetRelatedNode(nsIDOMNode * *aRelatedNode) { return _to GetRelatedNode(aRelatedNode); } \
  NS_SCRIPTABLE NS_IMETHOD GetPrevValue(nsAString & aPrevValue) { return _to GetPrevValue(aPrevValue); } \
  NS_SCRIPTABLE NS_IMETHOD GetNewValue(nsAString & aNewValue) { return _to GetNewValue(aNewValue); } \
  NS_SCRIPTABLE NS_IMETHOD GetAttrName(nsAString & aAttrName) { return _to GetAttrName(aAttrName); } \
  NS_SCRIPTABLE NS_IMETHOD GetAttrChange(PRUint16 *aAttrChange) { return _to GetAttrChange(aAttrChange); } \
  NS_SCRIPTABLE NS_IMETHOD InitMutationEvent(const nsAString & typeArg, PRBool canBubbleArg, PRBool cancelableArg, nsIDOMNode *relatedNodeArg, const nsAString & prevValueArg, const nsAString & newValueArg, const nsAString & attrNameArg, PRUint16 attrChangeArg) { return _to InitMutationEvent(typeArg, canBubbleArg, cancelableArg, relatedNodeArg, prevValueArg, newValueArg, attrNameArg, attrChangeArg); } 

/* Use this macro to declare functions that forward the behavior of this interface to another object in a safe way. */
#define NS_FORWARD_SAFE_NSIDOMMUTATIONEVENT(_to) \
  NS_SCRIPTABLE NS_IMETHOD GetRelatedNode(nsIDOMNode * *aRelatedNode) { return !_to ? NS_ERROR_NULL_POINTER : _to->GetRelatedNode(aRelatedNode); } \
  NS_SCRIPTABLE NS_IMETHOD GetPrevValue(nsAString & aPrevValue) { return !_to ? NS_ERROR_NULL_POINTER : _to->GetPrevValue(aPrevValue); } \
  NS_SCRIPTABLE NS_IMETHOD GetNewValue(nsAString & aNewValue) { return !_to ? NS_ERROR_NULL_POINTER : _to->GetNewValue(aNewValue); } \
  NS_SCRIPTABLE NS_IMETHOD GetAttrName(nsAString & aAttrName) { return !_to ? NS_ERROR_NULL_POINTER : _to->GetAttrName(aAttrName); } \
  NS_SCRIPTABLE NS_IMETHOD GetAttrChange(PRUint16 *aAttrChange) { return !_to ? NS_ERROR_NULL_POINTER : _to->GetAttrChange(aAttrChange); } \
  NS_SCRIPTABLE NS_IMETHOD InitMutationEvent(const nsAString & typeArg, PRBool canBubbleArg, PRBool cancelableArg, nsIDOMNode *relatedNodeArg, const nsAString & prevValueArg, const nsAString & newValueArg, const nsAString & attrNameArg, PRUint16 attrChangeArg) { return !_to ? NS_ERROR_NULL_POINTER : _to->InitMutationEvent(typeArg, canBubbleArg, cancelableArg, relatedNodeArg, prevValueArg, newValueArg, attrNameArg, attrChangeArg); } 

#if 0
/* Use the code below as a template for the implementation class for this interface. */

/* Header file */
class nsDOMMutationEvent : public nsIDOMMutationEvent
{
public:
  NS_DECL_ISUPPORTS
  NS_DECL_NSIDOMMUTATIONEVENT

  nsDOMMutationEvent();

private:
  ~nsDOMMutationEvent();

protected:
  /* additional members */
};

/* Implementation file */
NS_IMPL_ISUPPORTS1(nsDOMMutationEvent, nsIDOMMutationEvent)

nsDOMMutationEvent::nsDOMMutationEvent()
{
  /* member initializers and constructor code */
}

nsDOMMutationEvent::~nsDOMMutationEvent()
{
  /* destructor code */
}

/* readonly attribute nsIDOMNode relatedNode; */
NS_IMETHODIMP nsDOMMutationEvent::GetRelatedNode(nsIDOMNode * *aRelatedNode)
{
    return NS_ERROR_NOT_IMPLEMENTED;
}

/* readonly attribute DOMString prevValue; */
NS_IMETHODIMP nsDOMMutationEvent::GetPrevValue(nsAString & aPrevValue)
{
    return NS_ERROR_NOT_IMPLEMENTED;
}

/* readonly attribute DOMString newValue; */
NS_IMETHODIMP nsDOMMutationEvent::GetNewValue(nsAString & aNewValue)
{
    return NS_ERROR_NOT_IMPLEMENTED;
}

/* readonly attribute DOMString attrName; */
NS_IMETHODIMP nsDOMMutationEvent::GetAttrName(nsAString & aAttrName)
{
    return NS_ERROR_NOT_IMPLEMENTED;
}

/* readonly attribute unsigned short attrChange; */
NS_IMETHODIMP nsDOMMutationEvent::GetAttrChange(PRUint16 *aAttrChange)
{
    return NS_ERROR_NOT_IMPLEMENTED;
}

/* void initMutationEvent (in DOMString typeArg, in boolean canBubbleArg, in boolean cancelableArg, in nsIDOMNode relatedNodeArg, in DOMString prevValueArg, in DOMString newValueArg, in DOMString attrNameArg, in unsigned short attrChangeArg); */
NS_IMETHODIMP nsDOMMutationEvent::InitMutationEvent(const nsAString & typeArg, PRBool canBubbleArg, PRBool cancelableArg, nsIDOMNode *relatedNodeArg, const nsAString & prevValueArg, const nsAString & newValueArg, const nsAString & attrNameArg, PRUint16 attrChangeArg)
{
    return NS_ERROR_NOT_IMPLEMENTED;
}

/* End of implementation class template. */
#endif


#endif /* __gen_nsIDOMMutationEvent_h__ */
