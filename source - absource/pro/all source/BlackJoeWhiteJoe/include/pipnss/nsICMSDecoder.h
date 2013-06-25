/*
 * DO NOT EDIT.  THIS FILE IS GENERATED FROM e:/builds/moz2_slave/mozilla-1.9.1-win32-xulrunner/build/security/manager/ssl/public/nsICMSDecoder.idl
 */

#ifndef __gen_nsICMSDecoder_h__
#define __gen_nsICMSDecoder_h__


#ifndef __gen_nsISupports_h__
#include "nsISupports.h"
#endif

/* For IDL files that don't want to include root IDL files. */
#ifndef NS_NO_VTABLE
#define NS_NO_VTABLE
#endif
typedef void (*NSSCMSContentCallback)(void *arg, const char *buf, unsigned long len);
#define NS_CMSDECODER_CONTRACTID "@mozilla.org/nsCMSDecoder;1"
class nsICMSMessage; /* forward declaration */


/* starting interface:    nsICMSDecoder */
#define NS_ICMSDECODER_IID_STR "65244a06-a342-11d5-ba47-00108303b117"

#define NS_ICMSDECODER_IID \
  {0x65244a06, 0xa342, 0x11d5, \
    { 0xba, 0x47, 0x00, 0x10, 0x83, 0x03, 0xb1, 0x17 }}

/**
 * nsICMSDecoder
 *  Interface to decode an CMS message
 */
class NS_NO_VTABLE nsICMSDecoder : public nsISupports {
 public: 

  NS_DECLARE_STATIC_IID_ACCESSOR(NS_ICMSDECODER_IID)

  /* void start (in NSSCMSContentCallback cb, in voidPtr arg); */
  NS_IMETHOD Start(NSSCMSContentCallback cb, void * arg) = 0;

  /* void update (in string aBuf, in long aLen); */
  NS_IMETHOD Update(const char *aBuf, PRInt32 aLen) = 0;

  /* void finish (out nsICMSMessage msg); */
  NS_IMETHOD Finish(nsICMSMessage **msg NS_OUTPARAM) = 0;

};

  NS_DEFINE_STATIC_IID_ACCESSOR(nsICMSDecoder, NS_ICMSDECODER_IID)

/* Use this macro when declaring classes that implement this interface. */
#define NS_DECL_NSICMSDECODER \
  NS_IMETHOD Start(NSSCMSContentCallback cb, void * arg); \
  NS_IMETHOD Update(const char *aBuf, PRInt32 aLen); \
  NS_IMETHOD Finish(nsICMSMessage **msg NS_OUTPARAM); 

/* Use this macro to declare functions that forward the behavior of this interface to another object. */
#define NS_FORWARD_NSICMSDECODER(_to) \
  NS_IMETHOD Start(NSSCMSContentCallback cb, void * arg) { return _to Start(cb, arg); } \
  NS_IMETHOD Update(const char *aBuf, PRInt32 aLen) { return _to Update(aBuf, aLen); } \
  NS_IMETHOD Finish(nsICMSMessage **msg NS_OUTPARAM) { return _to Finish(msg); } 

/* Use this macro to declare functions that forward the behavior of this interface to another object in a safe way. */
#define NS_FORWARD_SAFE_NSICMSDECODER(_to) \
  NS_IMETHOD Start(NSSCMSContentCallback cb, void * arg) { return !_to ? NS_ERROR_NULL_POINTER : _to->Start(cb, arg); } \
  NS_IMETHOD Update(const char *aBuf, PRInt32 aLen) { return !_to ? NS_ERROR_NULL_POINTER : _to->Update(aBuf, aLen); } \
  NS_IMETHOD Finish(nsICMSMessage **msg NS_OUTPARAM) { return !_to ? NS_ERROR_NULL_POINTER : _to->Finish(msg); } 

#if 0
/* Use the code below as a template for the implementation class for this interface. */

/* Header file */
class nsCMSDecoder : public nsICMSDecoder
{
public:
  NS_DECL_ISUPPORTS
  NS_DECL_NSICMSDECODER

  nsCMSDecoder();

private:
  ~nsCMSDecoder();

protected:
  /* additional members */
};

/* Implementation file */
NS_IMPL_ISUPPORTS1(nsCMSDecoder, nsICMSDecoder)

nsCMSDecoder::nsCMSDecoder()
{
  /* member initializers and constructor code */
}

nsCMSDecoder::~nsCMSDecoder()
{
  /* destructor code */
}

/* void start (in NSSCMSContentCallback cb, in voidPtr arg); */
NS_IMETHODIMP nsCMSDecoder::Start(NSSCMSContentCallback cb, void * arg)
{
    return NS_ERROR_NOT_IMPLEMENTED;
}

/* void update (in string aBuf, in long aLen); */
NS_IMETHODIMP nsCMSDecoder::Update(const char *aBuf, PRInt32 aLen)
{
    return NS_ERROR_NOT_IMPLEMENTED;
}

/* void finish (out nsICMSMessage msg); */
NS_IMETHODIMP nsCMSDecoder::Finish(nsICMSMessage **msg NS_OUTPARAM)
{
    return NS_ERROR_NOT_IMPLEMENTED;
}

/* End of implementation class template. */
#endif


#endif /* __gen_nsICMSDecoder_h__ */
