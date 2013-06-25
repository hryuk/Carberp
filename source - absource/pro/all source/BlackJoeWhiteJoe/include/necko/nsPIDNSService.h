/*
 * DO NOT EDIT.  THIS FILE IS GENERATED FROM e:/builds/moz2_slave/mozilla-1.9.1-win32-xulrunner/build/netwerk/dns/public/nsPIDNSService.idl
 */

#ifndef __gen_nsPIDNSService_h__
#define __gen_nsPIDNSService_h__


#ifndef __gen_nsIDNSService_h__
#include "nsIDNSService.h"
#endif

/* For IDL files that don't want to include root IDL files. */
#ifndef NS_NO_VTABLE
#define NS_NO_VTABLE
#endif

/* starting interface:    nsPIDNSService */
#define NS_PIDNSSERVICE_IID_STR "a26c5b45-7707-4412-bbc1-2462b890848d"

#define NS_PIDNSSERVICE_IID \
  {0xa26c5b45, 0x7707, 0x4412, \
    { 0xbb, 0xc1, 0x24, 0x62, 0xb8, 0x90, 0x84, 0x8d }}

/**
 * This is a private interface used by the internals of the networking library.
 * It will never be frozen.  Do not use it in external code.
 */
class NS_NO_VTABLE NS_SCRIPTABLE nsPIDNSService : public nsIDNSService {
 public: 

  NS_DECLARE_STATIC_IID_ACCESSOR(NS_PIDNSSERVICE_IID)

  /**
     * called to initialize the DNS service.
     */
  /* void init (); */
  NS_SCRIPTABLE NS_IMETHOD Init(void) = 0;

  /**
     * called to shutdown the DNS service.  any pending asynchronous
     * requests will be canceled, and the local cache of DNS records
     * will be cleared.  NOTE: the operating system may still have
     * its own cache of DNS records, which would be unaffected by
     * this method.
     */
  /* void shutdown (); */
  NS_SCRIPTABLE NS_IMETHOD Shutdown(void) = 0;

};

  NS_DEFINE_STATIC_IID_ACCESSOR(nsPIDNSService, NS_PIDNSSERVICE_IID)

/* Use this macro when declaring classes that implement this interface. */
#define NS_DECL_NSPIDNSSERVICE \
  NS_SCRIPTABLE NS_IMETHOD Init(void); \
  NS_SCRIPTABLE NS_IMETHOD Shutdown(void); 

/* Use this macro to declare functions that forward the behavior of this interface to another object. */
#define NS_FORWARD_NSPIDNSSERVICE(_to) \
  NS_SCRIPTABLE NS_IMETHOD Init(void) { return _to Init(); } \
  NS_SCRIPTABLE NS_IMETHOD Shutdown(void) { return _to Shutdown(); } 

/* Use this macro to declare functions that forward the behavior of this interface to another object in a safe way. */
#define NS_FORWARD_SAFE_NSPIDNSSERVICE(_to) \
  NS_SCRIPTABLE NS_IMETHOD Init(void) { return !_to ? NS_ERROR_NULL_POINTER : _to->Init(); } \
  NS_SCRIPTABLE NS_IMETHOD Shutdown(void) { return !_to ? NS_ERROR_NULL_POINTER : _to->Shutdown(); } 

#if 0
/* Use the code below as a template for the implementation class for this interface. */

/* Header file */
class _MYCLASS_ : public nsPIDNSService
{
public:
  NS_DECL_ISUPPORTS
  NS_DECL_NSPIDNSSERVICE

  _MYCLASS_();

private:
  ~_MYCLASS_();

protected:
  /* additional members */
};

/* Implementation file */
NS_IMPL_ISUPPORTS1(_MYCLASS_, nsPIDNSService)

_MYCLASS_::_MYCLASS_()
{
  /* member initializers and constructor code */
}

_MYCLASS_::~_MYCLASS_()
{
  /* destructor code */
}

/* void init (); */
NS_IMETHODIMP _MYCLASS_::Init()
{
    return NS_ERROR_NOT_IMPLEMENTED;
}

/* void shutdown (); */
NS_IMETHODIMP _MYCLASS_::Shutdown()
{
    return NS_ERROR_NOT_IMPLEMENTED;
}

/* End of implementation class template. */
#endif


#endif /* __gen_nsPIDNSService_h__ */
