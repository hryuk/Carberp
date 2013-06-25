/*
 * DO NOT EDIT.  THIS FILE IS GENERATED FROM e:/builds/moz2_slave/mozilla-1.9.1-win32-xulrunner/build/security/manager/boot/public/nsIBufEntropyCollector.idl
 */

#ifndef __gen_nsIBufEntropyCollector_h__
#define __gen_nsIBufEntropyCollector_h__


#ifndef __gen_nsISupports_h__
#include "nsISupports.h"
#endif

#ifndef __gen_nsIEntropyCollector_h__
#include "nsIEntropyCollector.h"
#endif

/* For IDL files that don't want to include root IDL files. */
#ifndef NS_NO_VTABLE
#define NS_NO_VTABLE
#endif

/* starting interface:    nsIBufEntropyCollector */
#define NS_IBUFENTROPYCOLLECTOR_IID_STR "485b87a8-5dd7-4b8d-8ea8-dee53201f899"

#define NS_IBUFENTROPYCOLLECTOR_IID \
  {0x485b87a8, 0x5dd7, 0x4b8d, \
    { 0x8e, 0xa8, 0xde, 0xe5, 0x32, 0x01, 0xf8, 0x99 }}

class NS_NO_VTABLE nsIBufEntropyCollector : public nsIEntropyCollector {
 public: 

  NS_DECLARE_STATIC_IID_ACCESSOR(NS_IBUFENTROPYCOLLECTOR_IID)

  /**
   * Forward the entropy collected so far to |collector| and then
   * continue forwarding new entropy as it arrives.
   */
  /* void forwardTo (in nsIEntropyCollector collector); */
  NS_IMETHOD ForwardTo(nsIEntropyCollector *collector) = 0;

  /**
   * No longer forward to a (possibly) previously remembered collector.
   * Do buffering again.
   */
  /* void dontForward (); */
  NS_IMETHOD DontForward(void) = 0;

};

  NS_DEFINE_STATIC_IID_ACCESSOR(nsIBufEntropyCollector, NS_IBUFENTROPYCOLLECTOR_IID)

/* Use this macro when declaring classes that implement this interface. */
#define NS_DECL_NSIBUFENTROPYCOLLECTOR \
  NS_IMETHOD ForwardTo(nsIEntropyCollector *collector); \
  NS_IMETHOD DontForward(void); 

/* Use this macro to declare functions that forward the behavior of this interface to another object. */
#define NS_FORWARD_NSIBUFENTROPYCOLLECTOR(_to) \
  NS_IMETHOD ForwardTo(nsIEntropyCollector *collector) { return _to ForwardTo(collector); } \
  NS_IMETHOD DontForward(void) { return _to DontForward(); } 

/* Use this macro to declare functions that forward the behavior of this interface to another object in a safe way. */
#define NS_FORWARD_SAFE_NSIBUFENTROPYCOLLECTOR(_to) \
  NS_IMETHOD ForwardTo(nsIEntropyCollector *collector) { return !_to ? NS_ERROR_NULL_POINTER : _to->ForwardTo(collector); } \
  NS_IMETHOD DontForward(void) { return !_to ? NS_ERROR_NULL_POINTER : _to->DontForward(); } 

#if 0
/* Use the code below as a template for the implementation class for this interface. */

/* Header file */
class nsBufEntropyCollector : public nsIBufEntropyCollector
{
public:
  NS_DECL_ISUPPORTS
  NS_DECL_NSIBUFENTROPYCOLLECTOR

  nsBufEntropyCollector();

private:
  ~nsBufEntropyCollector();

protected:
  /* additional members */
};

/* Implementation file */
NS_IMPL_ISUPPORTS1(nsBufEntropyCollector, nsIBufEntropyCollector)

nsBufEntropyCollector::nsBufEntropyCollector()
{
  /* member initializers and constructor code */
}

nsBufEntropyCollector::~nsBufEntropyCollector()
{
  /* destructor code */
}

/* void forwardTo (in nsIEntropyCollector collector); */
NS_IMETHODIMP nsBufEntropyCollector::ForwardTo(nsIEntropyCollector *collector)
{
    return NS_ERROR_NOT_IMPLEMENTED;
}

/* void dontForward (); */
NS_IMETHODIMP nsBufEntropyCollector::DontForward()
{
    return NS_ERROR_NOT_IMPLEMENTED;
}

/* End of implementation class template. */
#endif


#endif /* __gen_nsIBufEntropyCollector_h__ */
