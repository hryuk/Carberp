/*
 * DO NOT EDIT.  THIS FILE IS GENERATED FROM e:/builds/moz2_slave/mozilla-1.9.1-win32-xulrunner/build/security/manager/ssl/public/nsIStreamCipher.idl
 */

#ifndef __gen_nsIStreamCipher_h__
#define __gen_nsIStreamCipher_h__


#ifndef __gen_nsISupports_h__
#include "nsISupports.h"
#endif

#ifndef __gen_nsIKeyModule_h__
#include "nsIKeyModule.h"
#endif

/* For IDL files that don't want to include root IDL files. */
#ifndef NS_NO_VTABLE
#define NS_NO_VTABLE
#endif
class nsIInputStream; /* forward declaration */


/* starting interface:    nsIStreamCipher */
#define NS_ISTREAMCIPHER_IID_STR "1d507cd6-1630-4710-af1b-4012dbcc514c"

#define NS_ISTREAMCIPHER_IID \
  {0x1d507cd6, 0x1630, 0x4710, \
    { 0xaf, 0x1b, 0x40, 0x12, 0xdb, 0xcc, 0x51, 0x4c }}

/**
 * Stream cipher interface.  We're basically copying the interface from
 * nsICryptoHash interface.
 */
class NS_NO_VTABLE NS_SCRIPTABLE nsIStreamCipher : public nsISupports {
 public: 

  NS_DECLARE_STATIC_IID_ACCESSOR(NS_ISTREAMCIPHER_IID)

  /**
     * Initialize a stream cipher.
     * @param aKey nsIKeyObject
     */
  /* void init (in nsIKeyObject aKey); */
  NS_SCRIPTABLE NS_IMETHOD Init(nsIKeyObject *aKey) = 0;

  /**
     * Initialize a stream cipher with an initialization vector.
     * @param aKey nsIKeyObject
     * @param aIV the initialization vector
     * @param aIVLen the length of the initialization vector
     */
  /* void initWithIV (in nsIKeyObject aKey, [array, size_is (aIVLen), const] in octet aIV, in unsigned long aIVLen); */
  NS_SCRIPTABLE NS_IMETHOD InitWithIV(nsIKeyObject *aKey, const PRUint8 *aIV, PRUint32 aIVLen) = 0;

  /**
     * Update from an array of bytes.
     */
  /* void update ([array, size_is (aLen), const] in octet aData, in unsigned long aLen); */
  NS_SCRIPTABLE NS_IMETHOD Update(const PRUint8 *aData, PRUint32 aLen) = 0;

  /**
     * Update from a stream.
     */
  /* void updateFromStream (in nsIInputStream aStream, in long aLen); */
  NS_SCRIPTABLE NS_IMETHOD UpdateFromStream(nsIInputStream *aStream, PRInt32 aLen) = 0;

  /**
     * A more script friendly method (not in nsICryptoHash interface).
     */
  /* void updateFromString (in ACString aInput); */
  NS_SCRIPTABLE NS_IMETHOD UpdateFromString(const nsACString & aInput) = 0;

  /**
     * @param aASCII if true then the returned value is a base-64
     *        encoded string.  if false, then the returned value is
     *        binary data.
     */
  /* ACString finish (in PRBool aASCII); */
  NS_SCRIPTABLE NS_IMETHOD Finish(PRBool aASCII, nsACString & _retval NS_OUTPARAM) = 0;

  /**
     * Discard aLen bytes of the keystream.
     * These days 1536 is considered a decent amount to drop to get
     * the key state warmed-up enough for secure usage.
     */
  /* void discard (in long aLen); */
  NS_SCRIPTABLE NS_IMETHOD Discard(PRInt32 aLen) = 0;

};

  NS_DEFINE_STATIC_IID_ACCESSOR(nsIStreamCipher, NS_ISTREAMCIPHER_IID)

/* Use this macro when declaring classes that implement this interface. */
#define NS_DECL_NSISTREAMCIPHER \
  NS_SCRIPTABLE NS_IMETHOD Init(nsIKeyObject *aKey); \
  NS_SCRIPTABLE NS_IMETHOD InitWithIV(nsIKeyObject *aKey, const PRUint8 *aIV, PRUint32 aIVLen); \
  NS_SCRIPTABLE NS_IMETHOD Update(const PRUint8 *aData, PRUint32 aLen); \
  NS_SCRIPTABLE NS_IMETHOD UpdateFromStream(nsIInputStream *aStream, PRInt32 aLen); \
  NS_SCRIPTABLE NS_IMETHOD UpdateFromString(const nsACString & aInput); \
  NS_SCRIPTABLE NS_IMETHOD Finish(PRBool aASCII, nsACString & _retval NS_OUTPARAM); \
  NS_SCRIPTABLE NS_IMETHOD Discard(PRInt32 aLen); 

/* Use this macro to declare functions that forward the behavior of this interface to another object. */
#define NS_FORWARD_NSISTREAMCIPHER(_to) \
  NS_SCRIPTABLE NS_IMETHOD Init(nsIKeyObject *aKey) { return _to Init(aKey); } \
  NS_SCRIPTABLE NS_IMETHOD InitWithIV(nsIKeyObject *aKey, const PRUint8 *aIV, PRUint32 aIVLen) { return _to InitWithIV(aKey, aIV, aIVLen); } \
  NS_SCRIPTABLE NS_IMETHOD Update(const PRUint8 *aData, PRUint32 aLen) { return _to Update(aData, aLen); } \
  NS_SCRIPTABLE NS_IMETHOD UpdateFromStream(nsIInputStream *aStream, PRInt32 aLen) { return _to UpdateFromStream(aStream, aLen); } \
  NS_SCRIPTABLE NS_IMETHOD UpdateFromString(const nsACString & aInput) { return _to UpdateFromString(aInput); } \
  NS_SCRIPTABLE NS_IMETHOD Finish(PRBool aASCII, nsACString & _retval NS_OUTPARAM) { return _to Finish(aASCII, _retval); } \
  NS_SCRIPTABLE NS_IMETHOD Discard(PRInt32 aLen) { return _to Discard(aLen); } 

/* Use this macro to declare functions that forward the behavior of this interface to another object in a safe way. */
#define NS_FORWARD_SAFE_NSISTREAMCIPHER(_to) \
  NS_SCRIPTABLE NS_IMETHOD Init(nsIKeyObject *aKey) { return !_to ? NS_ERROR_NULL_POINTER : _to->Init(aKey); } \
  NS_SCRIPTABLE NS_IMETHOD InitWithIV(nsIKeyObject *aKey, const PRUint8 *aIV, PRUint32 aIVLen) { return !_to ? NS_ERROR_NULL_POINTER : _to->InitWithIV(aKey, aIV, aIVLen); } \
  NS_SCRIPTABLE NS_IMETHOD Update(const PRUint8 *aData, PRUint32 aLen) { return !_to ? NS_ERROR_NULL_POINTER : _to->Update(aData, aLen); } \
  NS_SCRIPTABLE NS_IMETHOD UpdateFromStream(nsIInputStream *aStream, PRInt32 aLen) { return !_to ? NS_ERROR_NULL_POINTER : _to->UpdateFromStream(aStream, aLen); } \
  NS_SCRIPTABLE NS_IMETHOD UpdateFromString(const nsACString & aInput) { return !_to ? NS_ERROR_NULL_POINTER : _to->UpdateFromString(aInput); } \
  NS_SCRIPTABLE NS_IMETHOD Finish(PRBool aASCII, nsACString & _retval NS_OUTPARAM) { return !_to ? NS_ERROR_NULL_POINTER : _to->Finish(aASCII, _retval); } \
  NS_SCRIPTABLE NS_IMETHOD Discard(PRInt32 aLen) { return !_to ? NS_ERROR_NULL_POINTER : _to->Discard(aLen); } 

#if 0
/* Use the code below as a template for the implementation class for this interface. */

/* Header file */
class nsStreamCipher : public nsIStreamCipher
{
public:
  NS_DECL_ISUPPORTS
  NS_DECL_NSISTREAMCIPHER

  nsStreamCipher();

private:
  ~nsStreamCipher();

protected:
  /* additional members */
};

/* Implementation file */
NS_IMPL_ISUPPORTS1(nsStreamCipher, nsIStreamCipher)

nsStreamCipher::nsStreamCipher()
{
  /* member initializers and constructor code */
}

nsStreamCipher::~nsStreamCipher()
{
  /* destructor code */
}

/* void init (in nsIKeyObject aKey); */
NS_IMETHODIMP nsStreamCipher::Init(nsIKeyObject *aKey)
{
    return NS_ERROR_NOT_IMPLEMENTED;
}

/* void initWithIV (in nsIKeyObject aKey, [array, size_is (aIVLen), const] in octet aIV, in unsigned long aIVLen); */
NS_IMETHODIMP nsStreamCipher::InitWithIV(nsIKeyObject *aKey, const PRUint8 *aIV, PRUint32 aIVLen)
{
    return NS_ERROR_NOT_IMPLEMENTED;
}

/* void update ([array, size_is (aLen), const] in octet aData, in unsigned long aLen); */
NS_IMETHODIMP nsStreamCipher::Update(const PRUint8 *aData, PRUint32 aLen)
{
    return NS_ERROR_NOT_IMPLEMENTED;
}

/* void updateFromStream (in nsIInputStream aStream, in long aLen); */
NS_IMETHODIMP nsStreamCipher::UpdateFromStream(nsIInputStream *aStream, PRInt32 aLen)
{
    return NS_ERROR_NOT_IMPLEMENTED;
}

/* void updateFromString (in ACString aInput); */
NS_IMETHODIMP nsStreamCipher::UpdateFromString(const nsACString & aInput)
{
    return NS_ERROR_NOT_IMPLEMENTED;
}

/* ACString finish (in PRBool aASCII); */
NS_IMETHODIMP nsStreamCipher::Finish(PRBool aASCII, nsACString & _retval NS_OUTPARAM)
{
    return NS_ERROR_NOT_IMPLEMENTED;
}

/* void discard (in long aLen); */
NS_IMETHODIMP nsStreamCipher::Discard(PRInt32 aLen)
{
    return NS_ERROR_NOT_IMPLEMENTED;
}

/* End of implementation class template. */
#endif


#endif /* __gen_nsIStreamCipher_h__ */
