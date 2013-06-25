/*
 * DO NOT EDIT.  THIS FILE IS GENERATED FROM e:/builds/moz2_slave/mozilla-1.9.1-win32-xulrunner/build/content/xml/document/public/nsIModifyableXPointer.idl
 */

#ifndef __gen_nsIModifyableXPointer_h__
#define __gen_nsIModifyableXPointer_h__


#ifndef __gen_nsIXPointer_h__
#include "nsIXPointer.h"
#endif

/* For IDL files that don't want to include root IDL files. */
#ifndef NS_NO_VTABLE
#define NS_NO_VTABLE
#endif
class nsIDOMRange; /* forward declaration */


/* starting interface:    nsIModifyableXPointerResult */
#define NS_IMODIFYABLEXPOINTERRESULT_IID_STR "2dc3be2e-642d-4d7e-b3c5-f3dac51afbee"

#define NS_IMODIFYABLEXPOINTERRESULT_IID \
  {0x2dc3be2e, 0x642d, 0x4d7e, \
    { 0xb3, 0xc5, 0xf3, 0xda, 0xc5, 0x1a, 0xfb, 0xee }}

/**
 * Helper interface that can assist in creating an nsIXPointerResult.
 */
class NS_NO_VTABLE nsIModifyableXPointerResult : public nsIXPointerResult {
 public: 

  NS_DECLARE_STATIC_IID_ACCESSOR(NS_IMODIFYABLEXPOINTERRESULT_IID)

  /* void appendRange (in nsIDOMRange aRange); */
  NS_IMETHOD AppendRange(nsIDOMRange *aRange) = 0;

};

  NS_DEFINE_STATIC_IID_ACCESSOR(nsIModifyableXPointerResult, NS_IMODIFYABLEXPOINTERRESULT_IID)

/* Use this macro when declaring classes that implement this interface. */
#define NS_DECL_NSIMODIFYABLEXPOINTERRESULT \
  NS_IMETHOD AppendRange(nsIDOMRange *aRange); 

/* Use this macro to declare functions that forward the behavior of this interface to another object. */
#define NS_FORWARD_NSIMODIFYABLEXPOINTERRESULT(_to) \
  NS_IMETHOD AppendRange(nsIDOMRange *aRange) { return _to AppendRange(aRange); } 

/* Use this macro to declare functions that forward the behavior of this interface to another object in a safe way. */
#define NS_FORWARD_SAFE_NSIMODIFYABLEXPOINTERRESULT(_to) \
  NS_IMETHOD AppendRange(nsIDOMRange *aRange) { return !_to ? NS_ERROR_NULL_POINTER : _to->AppendRange(aRange); } 

#if 0
/* Use the code below as a template for the implementation class for this interface. */

/* Header file */
class nsModifyableXPointerResult : public nsIModifyableXPointerResult
{
public:
  NS_DECL_ISUPPORTS
  NS_DECL_NSIMODIFYABLEXPOINTERRESULT

  nsModifyableXPointerResult();

private:
  ~nsModifyableXPointerResult();

protected:
  /* additional members */
};

/* Implementation file */
NS_IMPL_ISUPPORTS1(nsModifyableXPointerResult, nsIModifyableXPointerResult)

nsModifyableXPointerResult::nsModifyableXPointerResult()
{
  /* member initializers and constructor code */
}

nsModifyableXPointerResult::~nsModifyableXPointerResult()
{
  /* destructor code */
}

/* void appendRange (in nsIDOMRange aRange); */
NS_IMETHODIMP nsModifyableXPointerResult::AppendRange(nsIDOMRange *aRange)
{
    return NS_ERROR_NOT_IMPLEMENTED;
}

/* End of implementation class template. */
#endif


#endif /* __gen_nsIModifyableXPointer_h__ */
