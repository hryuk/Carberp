/*
 * DO NOT EDIT.  THIS FILE IS GENERATED FROM e:/builds/moz2_slave/mozilla-1.9.1-win32-xulrunner/build/xpcom/io/nsIObjectInputStream.idl
 */

#ifndef __gen_nsIObjectInputStream_h__
#define __gen_nsIObjectInputStream_h__


#ifndef __gen_nsIBinaryInputStream_h__
#include "nsIBinaryInputStream.h"
#endif

#ifndef __gen_nsrootidl_h__
#include "nsrootidl.h"
#endif

/* For IDL files that don't want to include root IDL files. */
#ifndef NS_NO_VTABLE
#define NS_NO_VTABLE
#endif

/* starting interface:    nsIObjectInputStream */
#define NS_IOBJECTINPUTSTREAM_IID_STR "6c248606-4eae-46fa-9df0-ba58502368eb"

#define NS_IOBJECTINPUTSTREAM_IID \
  {0x6c248606, 0x4eae, 0x46fa, \
    { 0x9d, 0xf0, 0xba, 0x58, 0x50, 0x23, 0x68, 0xeb }}

/**
 * @see nsIObjectOutputStream
 * @see nsIBinaryInputStream
 */
class NS_NO_VTABLE NS_SCRIPTABLE nsIObjectInputStream : public nsIBinaryInputStream {
 public: 

  NS_DECLARE_STATIC_IID_ACCESSOR(NS_IOBJECTINPUTSTREAM_IID)

  /**
     * Read an object from this stream to satisfy a strong or weak reference
     * to one of its interfaces.  If the interface was not along the primary
     * inheritance chain ending in the "root" or XPCOM-identity nsISupports,
     * readObject will QueryInterface from the deserialized object root to the
     * correct interface, which was specified when the object was serialized.
     *
     * @see nsIObjectOutputStream
     */
  /* nsISupports readObject (in PRBool aIsStrongRef); */
  NS_SCRIPTABLE NS_IMETHOD ReadObject(PRBool aIsStrongRef, nsISupports **_retval NS_OUTPARAM) = 0;

  /* [notxpcom] nsresult readID (out nsID aID); */
  NS_IMETHOD_(nsresult) ReadID(nsID *aID NS_OUTPARAM) = 0;

  /**
     * Optimized deserialization support -- see nsIStreamBufferAccess.idl.
     */
  /* [notxpcom] charPtr getBuffer (in PRUint32 aLength, in PRUint32 aAlignMask); */
  NS_IMETHOD_(char *) GetBuffer(PRUint32 aLength, PRUint32 aAlignMask) = 0;

  /* [notxpcom] void putBuffer (in charPtr aBuffer, in PRUint32 aLength); */
  NS_IMETHOD_(void) PutBuffer(char * aBuffer, PRUint32 aLength) = 0;

};

  NS_DEFINE_STATIC_IID_ACCESSOR(nsIObjectInputStream, NS_IOBJECTINPUTSTREAM_IID)

/* Use this macro when declaring classes that implement this interface. */
#define NS_DECL_NSIOBJECTINPUTSTREAM \
  NS_SCRIPTABLE NS_IMETHOD ReadObject(PRBool aIsStrongRef, nsISupports **_retval NS_OUTPARAM); \
  NS_IMETHOD_(nsresult) ReadID(nsID *aID NS_OUTPARAM); \
  NS_IMETHOD_(char *) GetBuffer(PRUint32 aLength, PRUint32 aAlignMask); \
  NS_IMETHOD_(void) PutBuffer(char * aBuffer, PRUint32 aLength); 

/* Use this macro to declare functions that forward the behavior of this interface to another object. */
#define NS_FORWARD_NSIOBJECTINPUTSTREAM(_to) \
  NS_SCRIPTABLE NS_IMETHOD ReadObject(PRBool aIsStrongRef, nsISupports **_retval NS_OUTPARAM) { return _to ReadObject(aIsStrongRef, _retval); } \
  NS_IMETHOD_(nsresult) ReadID(nsID *aID NS_OUTPARAM) { return _to ReadID(aID); } \
  NS_IMETHOD_(char *) GetBuffer(PRUint32 aLength, PRUint32 aAlignMask) { return _to GetBuffer(aLength, aAlignMask); } \
  NS_IMETHOD_(void) PutBuffer(char * aBuffer, PRUint32 aLength) { return _to PutBuffer(aBuffer, aLength); } 

/* Use this macro to declare functions that forward the behavior of this interface to another object in a safe way. */
#define NS_FORWARD_SAFE_NSIOBJECTINPUTSTREAM(_to) \
  NS_SCRIPTABLE NS_IMETHOD ReadObject(PRBool aIsStrongRef, nsISupports **_retval NS_OUTPARAM) { return !_to ? NS_ERROR_NULL_POINTER : _to->ReadObject(aIsStrongRef, _retval); } \
  NS_IMETHOD_(nsresult) ReadID(nsID *aID NS_OUTPARAM) { return !_to ? NS_ERROR_NULL_POINTER : _to->ReadID(aID); } \
  NS_IMETHOD_(char *) GetBuffer(PRUint32 aLength, PRUint32 aAlignMask) { return !_to ? NS_ERROR_NULL_POINTER : _to->GetBuffer(aLength, aAlignMask); } \
  NS_IMETHOD_(void) PutBuffer(char * aBuffer, PRUint32 aLength) { return !_to ? NS_ERROR_NULL_POINTER : _to->PutBuffer(aBuffer, aLength); } 

#if 0
/* Use the code below as a template for the implementation class for this interface. */

/* Header file */
class nsObjectInputStream : public nsIObjectInputStream
{
public:
  NS_DECL_ISUPPORTS
  NS_DECL_NSIOBJECTINPUTSTREAM

  nsObjectInputStream();

private:
  ~nsObjectInputStream();

protected:
  /* additional members */
};

/* Implementation file */
NS_IMPL_ISUPPORTS1(nsObjectInputStream, nsIObjectInputStream)

nsObjectInputStream::nsObjectInputStream()
{
  /* member initializers and constructor code */
}

nsObjectInputStream::~nsObjectInputStream()
{
  /* destructor code */
}

/* nsISupports readObject (in PRBool aIsStrongRef); */
NS_IMETHODIMP nsObjectInputStream::ReadObject(PRBool aIsStrongRef, nsISupports **_retval NS_OUTPARAM)
{
    return NS_ERROR_NOT_IMPLEMENTED;
}

/* [notxpcom] nsresult readID (out nsID aID); */
NS_IMETHODIMP_(nsresult) nsObjectInputStream::ReadID(nsID *aID NS_OUTPARAM)
{
    return NS_ERROR_NOT_IMPLEMENTED;
}

/* [notxpcom] charPtr getBuffer (in PRUint32 aLength, in PRUint32 aAlignMask); */
NS_IMETHODIMP_(char *) nsObjectInputStream::GetBuffer(PRUint32 aLength, PRUint32 aAlignMask)
{
    return NS_ERROR_NOT_IMPLEMENTED;
}

/* [notxpcom] void putBuffer (in charPtr aBuffer, in PRUint32 aLength); */
NS_IMETHODIMP_(void) nsObjectInputStream::PutBuffer(char * aBuffer, PRUint32 aLength)
{
    return NS_ERROR_NOT_IMPLEMENTED;
}

/* End of implementation class template. */
#endif

inline nsresult
NS_ReadOptionalObject(nsIObjectInputStream* aStream, PRBool aIsStrongRef,
                      nsISupports* *aResult)
{
    PRBool nonnull;
    nsresult rv = aStream->ReadBoolean(&nonnull);
    if (NS_SUCCEEDED(rv)) {
        if (nonnull)
            rv = aStream->ReadObject(aIsStrongRef, aResult);
        else
            *aResult = nsnull;
    }
    return rv;
}

#endif /* __gen_nsIObjectInputStream_h__ */
