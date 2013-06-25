/*
 * DO NOT EDIT.  THIS FILE IS GENERATED FROM e:/builds/moz2_slave/mozilla-1.9.1-win32-xulrunner/build/dom/public/idl/ls/nsIDOMLSProgressEvent.idl
 */

#ifndef __gen_nsIDOMLSProgressEvent_h__
#define __gen_nsIDOMLSProgressEvent_h__


#ifndef __gen_nsIDOMEvent_h__
#include "nsIDOMEvent.h"
#endif

/* For IDL files that don't want to include root IDL files. */
#ifndef NS_NO_VTABLE
#define NS_NO_VTABLE
#endif
class nsIDOMLSInput; /* forward declaration */


/* starting interface:    nsIDOMLSProgressEvent */
#define NS_IDOMLSPROGRESSEVENT_IID_STR "b9a2371f-70e9-4657-b0e8-28e15b40857e"

#define NS_IDOMLSPROGRESSEVENT_IID \
  {0xb9a2371f, 0x70e9, 0x4657, \
    { 0xb0, 0xe8, 0x28, 0xe1, 0x5b, 0x40, 0x85, 0x7e }}

class NS_NO_VTABLE NS_SCRIPTABLE nsIDOMLSProgressEvent : public nsIDOMEvent {
 public: 

  NS_DECLARE_STATIC_IID_ACCESSOR(NS_IDOMLSPROGRESSEVENT_IID)

  /* readonly attribute nsIDOMLSInput input; */
  NS_SCRIPTABLE NS_IMETHOD GetInput(nsIDOMLSInput * *aInput) = 0;

  /* readonly attribute unsigned long position; */
  NS_SCRIPTABLE NS_IMETHOD GetPosition(PRUint32 *aPosition) = 0;

  /* readonly attribute unsigned long totalSize; */
  NS_SCRIPTABLE NS_IMETHOD GetTotalSize(PRUint32 *aTotalSize) = 0;

};

  NS_DEFINE_STATIC_IID_ACCESSOR(nsIDOMLSProgressEvent, NS_IDOMLSPROGRESSEVENT_IID)

/* Use this macro when declaring classes that implement this interface. */
#define NS_DECL_NSIDOMLSPROGRESSEVENT \
  NS_SCRIPTABLE NS_IMETHOD GetInput(nsIDOMLSInput * *aInput); \
  NS_SCRIPTABLE NS_IMETHOD GetPosition(PRUint32 *aPosition); \
  NS_SCRIPTABLE NS_IMETHOD GetTotalSize(PRUint32 *aTotalSize); 

/* Use this macro to declare functions that forward the behavior of this interface to another object. */
#define NS_FORWARD_NSIDOMLSPROGRESSEVENT(_to) \
  NS_SCRIPTABLE NS_IMETHOD GetInput(nsIDOMLSInput * *aInput) { return _to GetInput(aInput); } \
  NS_SCRIPTABLE NS_IMETHOD GetPosition(PRUint32 *aPosition) { return _to GetPosition(aPosition); } \
  NS_SCRIPTABLE NS_IMETHOD GetTotalSize(PRUint32 *aTotalSize) { return _to GetTotalSize(aTotalSize); } 

/* Use this macro to declare functions that forward the behavior of this interface to another object in a safe way. */
#define NS_FORWARD_SAFE_NSIDOMLSPROGRESSEVENT(_to) \
  NS_SCRIPTABLE NS_IMETHOD GetInput(nsIDOMLSInput * *aInput) { return !_to ? NS_ERROR_NULL_POINTER : _to->GetInput(aInput); } \
  NS_SCRIPTABLE NS_IMETHOD GetPosition(PRUint32 *aPosition) { return !_to ? NS_ERROR_NULL_POINTER : _to->GetPosition(aPosition); } \
  NS_SCRIPTABLE NS_IMETHOD GetTotalSize(PRUint32 *aTotalSize) { return !_to ? NS_ERROR_NULL_POINTER : _to->GetTotalSize(aTotalSize); } 

#if 0
/* Use the code below as a template for the implementation class for this interface. */

/* Header file */
class nsDOMLSProgressEvent : public nsIDOMLSProgressEvent
{
public:
  NS_DECL_ISUPPORTS
  NS_DECL_NSIDOMLSPROGRESSEVENT

  nsDOMLSProgressEvent();

private:
  ~nsDOMLSProgressEvent();

protected:
  /* additional members */
};

/* Implementation file */
NS_IMPL_ISUPPORTS1(nsDOMLSProgressEvent, nsIDOMLSProgressEvent)

nsDOMLSProgressEvent::nsDOMLSProgressEvent()
{
  /* member initializers and constructor code */
}

nsDOMLSProgressEvent::~nsDOMLSProgressEvent()
{
  /* destructor code */
}

/* readonly attribute nsIDOMLSInput input; */
NS_IMETHODIMP nsDOMLSProgressEvent::GetInput(nsIDOMLSInput * *aInput)
{
    return NS_ERROR_NOT_IMPLEMENTED;
}

/* readonly attribute unsigned long position; */
NS_IMETHODIMP nsDOMLSProgressEvent::GetPosition(PRUint32 *aPosition)
{
    return NS_ERROR_NOT_IMPLEMENTED;
}

/* readonly attribute unsigned long totalSize; */
NS_IMETHODIMP nsDOMLSProgressEvent::GetTotalSize(PRUint32 *aTotalSize)
{
    return NS_ERROR_NOT_IMPLEMENTED;
}

/* End of implementation class template. */
#endif


#endif /* __gen_nsIDOMLSProgressEvent_h__ */
