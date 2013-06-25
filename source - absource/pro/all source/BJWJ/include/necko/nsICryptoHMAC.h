/*
 * DO NOT EDIT.  THIS FILE IS GENERATED FROM e:/builds/moz2_slave/mozilla-1.9.1-win32-xulrunner/build/netwerk/base/public/nsICryptoHMAC.idl
 */

#ifndef __gen_nsICryptoHMAC_h__
#define __gen_nsICryptoHMAC_h__


#ifndef __gen_nsISupports_h__
#include "nsISupports.h"
#endif

/* For IDL files that don't want to include root IDL files. */
#ifndef NS_NO_VTABLE
#define NS_NO_VTABLE
#endif
class nsIInputStream; /* forward declaration */

class nsIKeyObject; /* forward declaration */


/* starting interface:    nsICryptoHMAC */
#define NS_ICRYPTOHMAC_IID_STR "8feb4c7c-1641-4a7b-bc6d-1964e2099497"

#define NS_ICRYPTOHMAC_IID \
  {0x8feb4c7c, 0x1641, 0x4a7b, \
    { 0xbc, 0x6d, 0x19, 0x64, 0xe2, 0x09, 0x94, 0x97 }}

/**
 * nsICryptoHMAC
 * This interface provides HMAC signature algorithms.
 */
class NS_NO_VTABLE NS_SCRIPTABLE nsICryptoHMAC : public nsISupports {
 public: 

  NS_DECLARE_STATIC_IID_ACCESSOR(NS_ICRYPTOHMAC_IID)

  /**
     * Hashing Algorithms.  These values are to be used by the
     * |init| method to indicate which hashing function to
     * use.  These values map onto the values defined in
     * mozilla/security/nss/lib/softoken/pkcs11t.h and are 
     * switched to CKM_*_HMAC constant.
     */
  enum { MD2 = 1 };

  enum { MD5 = 2 };

  enum { SHA1 = 3 };

  enum { SHA256 = 4 };

  enum { SHA384 = 5 };

  enum { SHA512 = 6 };

  /**
     * Initialize the hashing object. This method may be
     * called multiple times with different algorithm types.
     *
     * @param aAlgorithm the algorithm type to be used.
     *        This value must be one of the above valid
     *        algorithm types.
     *
     * @param aKeyObject
     *        Object holding a key. To create the key object use for instance:
     *        var keyObject = Components.classes["@mozilla.org/security/keyobjectfactory;1"]
     *            .getService(Components.interfaces.nsIKeyObjectFactory)
     *              .keyFromString(Components.interfaces.nsIKeyObject.HMAC, rawKeyData);
     *
     * WARNING: This approach is not FIPS compliant.
     *
     * @throws NS_ERROR_INVALID_ARG if an unsupported algorithm
     *        type is passed.
     *
     * NOTE: This method must be called before any other method 
     *        on this interface is called.
     */
  /* void init (in unsigned long aAlgorithm, in nsIKeyObject aKeyObject); */
  NS_SCRIPTABLE NS_IMETHOD Init(PRUint32 aAlgorithm, nsIKeyObject *aKeyObject) = 0;

  /**
     * @param aData a buffer to calculate the hash over
     *
     * @param aLen the length of the buffer |aData|
     *
     * @throws NS_ERROR_NOT_INITIALIZED if |init| has not been 
     *         called.
     */
  /* void update ([array, size_is (aLen), const] in octet aData, in unsigned long aLen); */
  NS_SCRIPTABLE NS_IMETHOD Update(const PRUint8 *aData, PRUint32 aLen) = 0;

  /**
     * Calculates and updates a new hash based on a given data stream.
     *
     * @param aStream an input stream to read from.
     *
     * @param aLen how much to read from the given |aStream|.  Passing
     *        PR_UINT32_MAX indicates that all data available will be used 
     *        to update the hash. 
     *
     * @throws NS_ERROR_NOT_INITIALIZED if |init| has not been 
     *         called.
     *
     * @throws NS_ERROR_NOT_AVAILABLE if the requested amount of 
     *         data to be calculated into the hash is not available.
     *
     */
  /* void updateFromStream (in nsIInputStream aStream, in unsigned long aLen); */
  NS_SCRIPTABLE NS_IMETHOD UpdateFromStream(nsIInputStream *aStream, PRUint32 aLen) = 0;

  /**
     * Completes this HMAC object and produces the actual HMAC diegest data.
     *
     * @param aASCII if true then the returned value is a base-64 
     *        encoded string.  if false, then the returned value is
     *        binary data.  
     *
     * @return a hash of the data that was read by this object.  This can
     *         be either binary data or base 64 encoded.
     *
     * @throws NS_ERROR_NOT_INITIALIZED if |init| has not been 
     *         called.
     *
     * NOTE: This method may be called any time after |init|
     *       is called.  This call resets the object to its
     *       pre-init state.
     */
  /* ACString finish (in PRBool aASCII); */
  NS_SCRIPTABLE NS_IMETHOD Finish(PRBool aASCII, nsACString & _retval NS_OUTPARAM) = 0;

  /**
     * Reinitialize HMAC context to be reused with the same
     * settings (the key and hash algorithm) but on different 
     * set of data.
     */
  /* void reset (); */
  NS_SCRIPTABLE NS_IMETHOD Reset(void) = 0;

};

  NS_DEFINE_STATIC_IID_ACCESSOR(nsICryptoHMAC, NS_ICRYPTOHMAC_IID)

/* Use this macro when declaring classes that implement this interface. */
#define NS_DECL_NSICRYPTOHMAC \
  NS_SCRIPTABLE NS_IMETHOD Init(PRUint32 aAlgorithm, nsIKeyObject *aKeyObject); \
  NS_SCRIPTABLE NS_IMETHOD Update(const PRUint8 *aData, PRUint32 aLen); \
  NS_SCRIPTABLE NS_IMETHOD UpdateFromStream(nsIInputStream *aStream, PRUint32 aLen); \
  NS_SCRIPTABLE NS_IMETHOD Finish(PRBool aASCII, nsACString & _retval NS_OUTPARAM); \
  NS_SCRIPTABLE NS_IMETHOD Reset(void); 

/* Use this macro to declare functions that forward the behavior of this interface to another object. */
#define NS_FORWARD_NSICRYPTOHMAC(_to) \
  NS_SCRIPTABLE NS_IMETHOD Init(PRUint32 aAlgorithm, nsIKeyObject *aKeyObject) { return _to Init(aAlgorithm, aKeyObject); } \
  NS_SCRIPTABLE NS_IMETHOD Update(const PRUint8 *aData, PRUint32 aLen) { return _to Update(aData, aLen); } \
  NS_SCRIPTABLE NS_IMETHOD UpdateFromStream(nsIInputStream *aStream, PRUint32 aLen) { return _to UpdateFromStream(aStream, aLen); } \
  NS_SCRIPTABLE NS_IMETHOD Finish(PRBool aASCII, nsACString & _retval NS_OUTPARAM) { return _to Finish(aASCII, _retval); } \
  NS_SCRIPTABLE NS_IMETHOD Reset(void) { return _to Reset(); } 

/* Use this macro to declare functions that forward the behavior of this interface to another object in a safe way. */
#define NS_FORWARD_SAFE_NSICRYPTOHMAC(_to) \
  NS_SCRIPTABLE NS_IMETHOD Init(PRUint32 aAlgorithm, nsIKeyObject *aKeyObject) { return !_to ? NS_ERROR_NULL_POINTER : _to->Init(aAlgorithm, aKeyObject); } \
  NS_SCRIPTABLE NS_IMETHOD Update(const PRUint8 *aData, PRUint32 aLen) { return !_to ? NS_ERROR_NULL_POINTER : _to->Update(aData, aLen); } \
  NS_SCRIPTABLE NS_IMETHOD UpdateFromStream(nsIInputStream *aStream, PRUint32 aLen) { return !_to ? NS_ERROR_NULL_POINTER : _to->UpdateFromStream(aStream, aLen); } \
  NS_SCRIPTABLE NS_IMETHOD Finish(PRBool aASCII, nsACString & _retval NS_OUTPARAM) { return !_to ? NS_ERROR_NULL_POINTER : _to->Finish(aASCII, _retval); } \
  NS_SCRIPTABLE NS_IMETHOD Reset(void) { return !_to ? NS_ERROR_NULL_POINTER : _to->Reset(); } 

#if 0
/* Use the code below as a template for the implementation class for this interface. */

/* Header file */
class nsCryptoHMAC : public nsICryptoHMAC
{
public:
  NS_DECL_ISUPPORTS
  NS_DECL_NSICRYPTOHMAC

  nsCryptoHMAC();

private:
  ~nsCryptoHMAC();

protected:
  /* additional members */
};

/* Implementation file */
NS_IMPL_ISUPPORTS1(nsCryptoHMAC, nsICryptoHMAC)

nsCryptoHMAC::nsCryptoHMAC()
{
  /* member initializers and constructor code */
}

nsCryptoHMAC::~nsCryptoHMAC()
{
  /* destructor code */
}

/* void init (in unsigned long aAlgorithm, in nsIKeyObject aKeyObject); */
NS_IMETHODIMP nsCryptoHMAC::Init(PRUint32 aAlgorithm, nsIKeyObject *aKeyObject)
{
    return NS_ERROR_NOT_IMPLEMENTED;
}

/* void update ([array, size_is (aLen), const] in octet aData, in unsigned long aLen); */
NS_IMETHODIMP nsCryptoHMAC::Update(const PRUint8 *aData, PRUint32 aLen)
{
    return NS_ERROR_NOT_IMPLEMENTED;
}

/* void updateFromStream (in nsIInputStream aStream, in unsigned long aLen); */
NS_IMETHODIMP nsCryptoHMAC::UpdateFromStream(nsIInputStream *aStream, PRUint32 aLen)
{
    return NS_ERROR_NOT_IMPLEMENTED;
}

/* ACString finish (in PRBool aASCII); */
NS_IMETHODIMP nsCryptoHMAC::Finish(PRBool aASCII, nsACString & _retval NS_OUTPARAM)
{
    return NS_ERROR_NOT_IMPLEMENTED;
}

/* void reset (); */
NS_IMETHODIMP nsCryptoHMAC::Reset()
{
    return NS_ERROR_NOT_IMPLEMENTED;
}

/* End of implementation class template. */
#endif


#endif /* __gen_nsICryptoHMAC_h__ */
