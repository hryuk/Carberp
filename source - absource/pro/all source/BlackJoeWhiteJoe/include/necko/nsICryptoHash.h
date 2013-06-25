/*
 * DO NOT EDIT.  THIS FILE IS GENERATED FROM e:/builds/moz2_slave/mozilla-1.9.1-win32-xulrunner/build/netwerk/base/public/nsICryptoHash.idl
 */

#ifndef __gen_nsICryptoHash_h__
#define __gen_nsICryptoHash_h__


#ifndef __gen_nsISupports_h__
#include "nsISupports.h"
#endif

/* For IDL files that don't want to include root IDL files. */
#ifndef NS_NO_VTABLE
#define NS_NO_VTABLE
#endif
class nsIInputStream; /* forward declaration */


/* starting interface:    nsICryptoHash */
#define NS_ICRYPTOHASH_IID_STR "1e5b7c43-4688-45ce-92e1-77ed931e3bbe"

#define NS_ICRYPTOHASH_IID \
  {0x1e5b7c43, 0x4688, 0x45ce, \
    { 0x92, 0xe1, 0x77, 0xed, 0x93, 0x1e, 0x3b, 0xbe }}

/**
 * nsICryptoHash
 * This interface provides crytographic hashing algorithms.
 */
class NS_NO_VTABLE NS_SCRIPTABLE nsICryptoHash : public nsISupports {
 public: 

  NS_DECLARE_STATIC_IID_ACCESSOR(NS_ICRYPTOHASH_IID)

  /**
     * Hashing Algorithms.  These values are to be used by the
     * |init| method to indicate which hashing function to
     * use.  These values map directly onto the values defined
     * in mozilla/security/nss/lib/cryptohi/hasht.h.
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
     * @throws NS_ERROR_INVALID_ARG if an unsupported algorithm
     *         type is passed.
     *
     * NOTE: This method or initWithString must be called
     *       before any other method on this interface is called.
     */
  /* void init (in unsigned long aAlgorithm); */
  NS_SCRIPTABLE NS_IMETHOD Init(PRUint32 aAlgorithm) = 0;

  /**
     * Initialize the hashing object. This method may be
     * called multiple times with different algorithm types.
     *
     * @param aAlgorithm the algorithm type to be used.
     *
     * @throws NS_ERROR_INVALID_ARG if an unsupported algorithm
     *         type is passed.
     *
     * NOTE: This method or init must be called before any
     *       other method on this interface is called.
     */
  /* void initWithString (in ACString aAlgorithm); */
  NS_SCRIPTABLE NS_IMETHOD InitWithString(const nsACString & aAlgorithm) = 0;

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
     * Completes this hash object and produces the actual hash data.
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

};

  NS_DEFINE_STATIC_IID_ACCESSOR(nsICryptoHash, NS_ICRYPTOHASH_IID)

/* Use this macro when declaring classes that implement this interface. */
#define NS_DECL_NSICRYPTOHASH \
  NS_SCRIPTABLE NS_IMETHOD Init(PRUint32 aAlgorithm); \
  NS_SCRIPTABLE NS_IMETHOD InitWithString(const nsACString & aAlgorithm); \
  NS_SCRIPTABLE NS_IMETHOD Update(const PRUint8 *aData, PRUint32 aLen); \
  NS_SCRIPTABLE NS_IMETHOD UpdateFromStream(nsIInputStream *aStream, PRUint32 aLen); \
  NS_SCRIPTABLE NS_IMETHOD Finish(PRBool aASCII, nsACString & _retval NS_OUTPARAM); 

/* Use this macro to declare functions that forward the behavior of this interface to another object. */
#define NS_FORWARD_NSICRYPTOHASH(_to) \
  NS_SCRIPTABLE NS_IMETHOD Init(PRUint32 aAlgorithm) { return _to Init(aAlgorithm); } \
  NS_SCRIPTABLE NS_IMETHOD InitWithString(const nsACString & aAlgorithm) { return _to InitWithString(aAlgorithm); } \
  NS_SCRIPTABLE NS_IMETHOD Update(const PRUint8 *aData, PRUint32 aLen) { return _to Update(aData, aLen); } \
  NS_SCRIPTABLE NS_IMETHOD UpdateFromStream(nsIInputStream *aStream, PRUint32 aLen) { return _to UpdateFromStream(aStream, aLen); } \
  NS_SCRIPTABLE NS_IMETHOD Finish(PRBool aASCII, nsACString & _retval NS_OUTPARAM) { return _to Finish(aASCII, _retval); } 

/* Use this macro to declare functions that forward the behavior of this interface to another object in a safe way. */
#define NS_FORWARD_SAFE_NSICRYPTOHASH(_to) \
  NS_SCRIPTABLE NS_IMETHOD Init(PRUint32 aAlgorithm) { return !_to ? NS_ERROR_NULL_POINTER : _to->Init(aAlgorithm); } \
  NS_SCRIPTABLE NS_IMETHOD InitWithString(const nsACString & aAlgorithm) { return !_to ? NS_ERROR_NULL_POINTER : _to->InitWithString(aAlgorithm); } \
  NS_SCRIPTABLE NS_IMETHOD Update(const PRUint8 *aData, PRUint32 aLen) { return !_to ? NS_ERROR_NULL_POINTER : _to->Update(aData, aLen); } \
  NS_SCRIPTABLE NS_IMETHOD UpdateFromStream(nsIInputStream *aStream, PRUint32 aLen) { return !_to ? NS_ERROR_NULL_POINTER : _to->UpdateFromStream(aStream, aLen); } \
  NS_SCRIPTABLE NS_IMETHOD Finish(PRBool aASCII, nsACString & _retval NS_OUTPARAM) { return !_to ? NS_ERROR_NULL_POINTER : _to->Finish(aASCII, _retval); } 

#if 0
/* Use the code below as a template for the implementation class for this interface. */

/* Header file */
class nsCryptoHash : public nsICryptoHash
{
public:
  NS_DECL_ISUPPORTS
  NS_DECL_NSICRYPTOHASH

  nsCryptoHash();

private:
  ~nsCryptoHash();

protected:
  /* additional members */
};

/* Implementation file */
NS_IMPL_ISUPPORTS1(nsCryptoHash, nsICryptoHash)

nsCryptoHash::nsCryptoHash()
{
  /* member initializers and constructor code */
}

nsCryptoHash::~nsCryptoHash()
{
  /* destructor code */
}

/* void init (in unsigned long aAlgorithm); */
NS_IMETHODIMP nsCryptoHash::Init(PRUint32 aAlgorithm)
{
    return NS_ERROR_NOT_IMPLEMENTED;
}

/* void initWithString (in ACString aAlgorithm); */
NS_IMETHODIMP nsCryptoHash::InitWithString(const nsACString & aAlgorithm)
{
    return NS_ERROR_NOT_IMPLEMENTED;
}

/* void update ([array, size_is (aLen), const] in octet aData, in unsigned long aLen); */
NS_IMETHODIMP nsCryptoHash::Update(const PRUint8 *aData, PRUint32 aLen)
{
    return NS_ERROR_NOT_IMPLEMENTED;
}

/* void updateFromStream (in nsIInputStream aStream, in unsigned long aLen); */
NS_IMETHODIMP nsCryptoHash::UpdateFromStream(nsIInputStream *aStream, PRUint32 aLen)
{
    return NS_ERROR_NOT_IMPLEMENTED;
}

/* ACString finish (in PRBool aASCII); */
NS_IMETHODIMP nsCryptoHash::Finish(PRBool aASCII, nsACString & _retval NS_OUTPARAM)
{
    return NS_ERROR_NOT_IMPLEMENTED;
}

/* End of implementation class template. */
#endif


#endif /* __gen_nsICryptoHash_h__ */
