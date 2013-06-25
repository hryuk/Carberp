/*
 * DO NOT EDIT.  THIS FILE IS GENERATED FROM e:/builds/moz2_slave/mozilla-1.9.1-win32-xulrunner/build/security/manager/ssl/public/nsICMSEncoder.idl
 */

#ifndef __gen_nsICMSEncoder_h__
#define __gen_nsICMSEncoder_h__


#ifndef __gen_nsISupports_h__
#include "nsISupports.h"
#endif

/* For IDL files that don't want to include root IDL files. */
#ifndef NS_NO_VTABLE
#define NS_NO_VTABLE
#endif
typedef void (*NSSCMSContentCallback)(void *arg, const char *buf, unsigned long len);
#define NS_CMSENCODER_CONTRACTID "@mozilla.org/nsCMSEncoder;1"
class nsICMSMessage; /* forward declaration */


/* starting interface:    nsICMSEncoder */
#define NS_ICMSENCODER_IID_STR "a15789aa-8903-462b-81e9-4aa2cff4d5cb"

#define NS_ICMSENCODER_IID \
  {0xa15789aa, 0x8903, 0x462b, \
    { 0x81, 0xe9, 0x4a, 0xa2, 0xcf, 0xf4, 0xd5, 0xcb }}

/**
 * nsICMSEncoder
 *  Interface to Encode an CMS message
 */
class NS_NO_VTABLE nsICMSEncoder : public nsISupports {
 public: 

  NS_DECLARE_STATIC_IID_ACCESSOR(NS_ICMSENCODER_IID)

  /* void start (in nsICMSMessage aMsg, in NSSCMSContentCallback cb, in voidPtr arg); */
  NS_IMETHOD Start(nsICMSMessage *aMsg, NSSCMSContentCallback cb, void * arg) = 0;

  /* void update (in string aBuf, in long aLen); */
  NS_IMETHOD Update(const char *aBuf, PRInt32 aLen) = 0;

  /* void finish (); */
  NS_IMETHOD Finish(void) = 0;

  /* void encode (in nsICMSMessage aMsg); */
  NS_IMETHOD Encode(nsICMSMessage *aMsg) = 0;

};

  NS_DEFINE_STATIC_IID_ACCESSOR(nsICMSEncoder, NS_ICMSENCODER_IID)

/* Use this macro when declaring classes that implement this interface. */
#define NS_DECL_NSICMSENCODER \
  NS_IMETHOD Start(nsICMSMessage *aMsg, NSSCMSContentCallback cb, void * arg); \
  NS_IMETHOD Update(const char *aBuf, PRInt32 aLen); \
  NS_IMETHOD Finish(void); \
  NS_IMETHOD Encode(nsICMSMessage *aMsg); 

/* Use this macro to declare functions that forward the behavior of this interface to another object. */
#define NS_FORWARD_NSICMSENCODER(_to) \
  NS_IMETHOD Start(nsICMSMessage *aMsg, NSSCMSContentCallback cb, void * arg) { return _to Start(aMsg, cb, arg); } \
  NS_IMETHOD Update(const char *aBuf, PRInt32 aLen) { return _to Update(aBuf, aLen); } \
  NS_IMETHOD Finish(void) { return _to Finish(); } \
  NS_IMETHOD Encode(nsICMSMessage *aMsg) { return _to Encode(aMsg); } 

/* Use this macro to declare functions that forward the behavior of this interface to another object in a safe way. */
#define NS_FORWARD_SAFE_NSICMSENCODER(_to) \
  NS_IMETHOD Start(nsICMSMessage *aMsg, NSSCMSContentCallback cb, void * arg) { return !_to ? NS_ERROR_NULL_POINTER : _to->Start(aMsg, cb, arg); } \
  NS_IMETHOD Update(const char *aBuf, PRInt32 aLen) { return !_to ? NS_ERROR_NULL_POINTER : _to->Update(aBuf, aLen); } \
  NS_IMETHOD Finish(void) { return !_to ? NS_ERROR_NULL_POINTER : _to->Finish(); } \
  NS_IMETHOD Encode(nsICMSMessage *aMsg) { return !_to ? NS_ERROR_NULL_POINTER : _to->Encode(aMsg); } 

#if 0
/* Use the code below as a template for the implementation class for this interface. */

/* Header file */
class nsCMSEncoder : public nsICMSEncoder
{
public:
  NS_DECL_ISUPPORTS
  NS_DECL_NSICMSENCODER

  nsCMSEncoder();

private:
  ~nsCMSEncoder();

protected:
  /* additional members */
};

/* Implementation file */
NS_IMPL_ISUPPORTS1(nsCMSEncoder, nsICMSEncoder)

nsCMSEncoder::nsCMSEncoder()
{
  /* member initializers and constructor code */
}

nsCMSEncoder::~nsCMSEncoder()
{
  /* destructor code */
}

/* void start (in nsICMSMessage aMsg, in NSSCMSContentCallback cb, in voidPtr arg); */
NS_IMETHODIMP nsCMSEncoder::Start(nsICMSMessage *aMsg, NSSCMSContentCallback cb, void * arg)
{
    return NS_ERROR_NOT_IMPLEMENTED;
}

/* void update (in string aBuf, in long aLen); */
NS_IMETHODIMP nsCMSEncoder::Update(const char *aBuf, PRInt32 aLen)
{
    return NS_ERROR_NOT_IMPLEMENTED;
}

/* void finish (); */
NS_IMETHODIMP nsCMSEncoder::Finish()
{
    return NS_ERROR_NOT_IMPLEMENTED;
}

/* void encode (in nsICMSMessage aMsg); */
NS_IMETHODIMP nsCMSEncoder::Encode(nsICMSMessage *aMsg)
{
    return NS_ERROR_NOT_IMPLEMENTED;
}

/* End of implementation class template. */
#endif


#endif /* __gen_nsICMSEncoder_h__ */
