/*
 * DO NOT EDIT.  THIS FILE IS GENERATED FROM e:/builds/moz2_slave/mozilla-1.9.1-win32-xulrunner/build/dom/public/idl/ls/nsIDOMLSLoadEvent.idl
 */

#ifndef __gen_nsIDOMLSLoadEvent_h__
#define __gen_nsIDOMLSLoadEvent_h__


#ifndef __gen_nsIDOMEvent_h__
#include "nsIDOMEvent.h"
#endif

/* For IDL files that don't want to include root IDL files. */
#ifndef NS_NO_VTABLE
#define NS_NO_VTABLE
#endif
class nsIDOMLSInput; /* forward declaration */


/* starting interface:    nsIDOMLSLoadEvent */
#define NS_IDOMLSLOADEVENT_IID_STR "6c16a810-a37d-4859-b557-337341631aee"

#define NS_IDOMLSLOADEVENT_IID \
  {0x6c16a810, 0xa37d, 0x4859, \
    { 0xb5, 0x57, 0x33, 0x73, 0x41, 0x63, 0x1a, 0xee }}

class NS_NO_VTABLE NS_SCRIPTABLE nsIDOMLSLoadEvent : public nsIDOMEvent {
 public: 

  NS_DECLARE_STATIC_IID_ACCESSOR(NS_IDOMLSLOADEVENT_IID)

  /* readonly attribute nsIDOMDocument newDocument; */
  NS_SCRIPTABLE NS_IMETHOD GetNewDocument(nsIDOMDocument * *aNewDocument) = 0;

  /* readonly attribute nsIDOMLSInput input; */
  NS_SCRIPTABLE NS_IMETHOD GetInput(nsIDOMLSInput * *aInput) = 0;

};

  NS_DEFINE_STATIC_IID_ACCESSOR(nsIDOMLSLoadEvent, NS_IDOMLSLOADEVENT_IID)

/* Use this macro when declaring classes that implement this interface. */
#define NS_DECL_NSIDOMLSLOADEVENT \
  NS_SCRIPTABLE NS_IMETHOD GetNewDocument(nsIDOMDocument * *aNewDocument); \
  NS_SCRIPTABLE NS_IMETHOD GetInput(nsIDOMLSInput * *aInput); 

/* Use this macro to declare functions that forward the behavior of this interface to another object. */
#define NS_FORWARD_NSIDOMLSLOADEVENT(_to) \
  NS_SCRIPTABLE NS_IMETHOD GetNewDocument(nsIDOMDocument * *aNewDocument) { return _to GetNewDocument(aNewDocument); } \
  NS_SCRIPTABLE NS_IMETHOD GetInput(nsIDOMLSInput * *aInput) { return _to GetInput(aInput); } 

/* Use this macro to declare functions that forward the behavior of this interface to another object in a safe way. */
#define NS_FORWARD_SAFE_NSIDOMLSLOADEVENT(_to) \
  NS_SCRIPTABLE NS_IMETHOD GetNewDocument(nsIDOMDocument * *aNewDocument) { return !_to ? NS_ERROR_NULL_POINTER : _to->GetNewDocument(aNewDocument); } \
  NS_SCRIPTABLE NS_IMETHOD GetInput(nsIDOMLSInput * *aInput) { return !_to ? NS_ERROR_NULL_POINTER : _to->GetInput(aInput); } 

#if 0
/* Use the code below as a template for the implementation class for this interface. */

/* Header file */
class nsDOMLSLoadEvent : public nsIDOMLSLoadEvent
{
public:
  NS_DECL_ISUPPORTS
  NS_DECL_NSIDOMLSLOADEVENT

  nsDOMLSLoadEvent();

private:
  ~nsDOMLSLoadEvent();

protected:
  /* additional members */
};

/* Implementation file */
NS_IMPL_ISUPPORTS1(nsDOMLSLoadEvent, nsIDOMLSLoadEvent)

nsDOMLSLoadEvent::nsDOMLSLoadEvent()
{
  /* member initializers and constructor code */
}

nsDOMLSLoadEvent::~nsDOMLSLoadEvent()
{
  /* destructor code */
}

/* readonly attribute nsIDOMDocument newDocument; */
NS_IMETHODIMP nsDOMLSLoadEvent::GetNewDocument(nsIDOMDocument * *aNewDocument)
{
    return NS_ERROR_NOT_IMPLEMENTED;
}

/* readonly attribute nsIDOMLSInput input; */
NS_IMETHODIMP nsDOMLSLoadEvent::GetInput(nsIDOMLSInput * *aInput)
{
    return NS_ERROR_NOT_IMPLEMENTED;
}

/* End of implementation class template. */
#endif


#endif /* __gen_nsIDOMLSLoadEvent_h__ */
