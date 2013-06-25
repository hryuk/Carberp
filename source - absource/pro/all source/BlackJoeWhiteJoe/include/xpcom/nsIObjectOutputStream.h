/*
 * DO NOT EDIT.  THIS FILE IS GENERATED FROM e:/builds/moz2_slave/mozilla-1.9.1-win32-xulrunner/build/xpcom/io/nsIObjectOutputStream.idl
 */

#ifndef __gen_nsIObjectOutputStream_h__
#define __gen_nsIObjectOutputStream_h__


#ifndef __gen_nsIBinaryOutputStream_h__
#include "nsIBinaryOutputStream.h"
#endif

#ifndef __gen_nsrootidl_h__
#include "nsrootidl.h"
#endif

/* For IDL files that don't want to include root IDL files. */
#ifndef NS_NO_VTABLE
#define NS_NO_VTABLE
#endif

/* starting interface:    nsIObjectOutputStream */
#define NS_IOBJECTOUTPUTSTREAM_IID_STR "92c898ac-5fde-4b99-87b3-5d486422094b"

#define NS_IOBJECTOUTPUTSTREAM_IID \
  {0x92c898ac, 0x5fde, 0x4b99, \
    { 0x87, 0xb3, 0x5d, 0x48, 0x64, 0x22, 0x09, 0x4b }}

/**
 * @See nsIObjectInputStream
 * @See nsIBinaryOutputStream
 */
class NS_NO_VTABLE NS_SCRIPTABLE nsIObjectOutputStream : public nsIBinaryOutputStream {
 public: 

  NS_DECLARE_STATIC_IID_ACCESSOR(NS_IOBJECTOUTPUTSTREAM_IID)

  /**
     * Write the object whose "root" or XPCOM-identity nsISupports is aObject.
     * The cause for writing this object is a strong or weak reference, so the
     * aIsStrongRef argument must tell which kind of pointer is being followed
     * here during serialization.
     *
     * If the object has only one strong reference in the serialization and no
     * weak refs, use writeSingleRefObject.  This is a valuable optimization:
     * it saves space in the stream, and cycles on both ends of the process.
     *
     * If the reference being serialized is a pointer to an interface not on
     * the primary inheritance chain ending in the root nsISupports, you must
     * call writeCompoundObject instead of this method.
     */
  /* void writeObject (in nsISupports aObject, in PRBool aIsStrongRef); */
  NS_SCRIPTABLE NS_IMETHOD WriteObject(nsISupports *aObject, PRBool aIsStrongRef) = 0;

  /**
     * Write an object referenced singly and strongly via its root nsISupports
     * or a subclass of its root nsISupports.  There must not be other refs to
     * aObject in memory, or in the serialization.
     */
  /* void writeSingleRefObject (in nsISupports aObject); */
  NS_SCRIPTABLE NS_IMETHOD WriteSingleRefObject(nsISupports *aObject) = 0;

  /**
     * Write the object referenced by an interface pointer at aObject that
     * inherits from a non-primary nsISupports, i.e., a reference to one of
     * the multiply inherited interfaces derived from an nsISupports other
     * than the root or XPCOM-identity nsISupports; or a reference to an
     * inner object in the case of true XPCOM aggregation.  aIID identifies
     * this interface.
     */
  /* void writeCompoundObject (in nsISupports aObject, in nsIIDRef aIID, in PRBool aIsStrongRef); */
  NS_SCRIPTABLE NS_IMETHOD WriteCompoundObject(nsISupports *aObject, const nsIID & aIID, PRBool aIsStrongRef) = 0;

  /* void writeID (in nsIDRef aID); */
  NS_SCRIPTABLE NS_IMETHOD WriteID(const nsID & aID) = 0;

  /**
     * Optimized serialization support -- see nsIStreamBufferAccess.idl.
     */
  /* [notxpcom] charPtr getBuffer (in PRUint32 aLength, in PRUint32 aAlignMask); */
  NS_IMETHOD_(char *) GetBuffer(PRUint32 aLength, PRUint32 aAlignMask) = 0;

  /* [notxpcom] void putBuffer (in charPtr aBuffer, in PRUint32 aLength); */
  NS_IMETHOD_(void) PutBuffer(char * aBuffer, PRUint32 aLength) = 0;

};

  NS_DEFINE_STATIC_IID_ACCESSOR(nsIObjectOutputStream, NS_IOBJECTOUTPUTSTREAM_IID)

/* Use this macro when declaring classes that implement this interface. */
#define NS_DECL_NSIOBJECTOUTPUTSTREAM \
  NS_SCRIPTABLE NS_IMETHOD WriteObject(nsISupports *aObject, PRBool aIsStrongRef); \
  NS_SCRIPTABLE NS_IMETHOD WriteSingleRefObject(nsISupports *aObject); \
  NS_SCRIPTABLE NS_IMETHOD WriteCompoundObject(nsISupports *aObject, const nsIID & aIID, PRBool aIsStrongRef); \
  NS_SCRIPTABLE NS_IMETHOD WriteID(const nsID & aID); \
  NS_IMETHOD_(char *) GetBuffer(PRUint32 aLength, PRUint32 aAlignMask); \
  NS_IMETHOD_(void) PutBuffer(char * aBuffer, PRUint32 aLength); 

/* Use this macro to declare functions that forward the behavior of this interface to another object. */
#define NS_FORWARD_NSIOBJECTOUTPUTSTREAM(_to) \
  NS_SCRIPTABLE NS_IMETHOD WriteObject(nsISupports *aObject, PRBool aIsStrongRef) { return _to WriteObject(aObject, aIsStrongRef); } \
  NS_SCRIPTABLE NS_IMETHOD WriteSingleRefObject(nsISupports *aObject) { return _to WriteSingleRefObject(aObject); } \
  NS_SCRIPTABLE NS_IMETHOD WriteCompoundObject(nsISupports *aObject, const nsIID & aIID, PRBool aIsStrongRef) { return _to WriteCompoundObject(aObject, aIID, aIsStrongRef); } \
  NS_SCRIPTABLE NS_IMETHOD WriteID(const nsID & aID) { return _to WriteID(aID); } \
  NS_IMETHOD_(char *) GetBuffer(PRUint32 aLength, PRUint32 aAlignMask) { return _to GetBuffer(aLength, aAlignMask); } \
  NS_IMETHOD_(void) PutBuffer(char * aBuffer, PRUint32 aLength) { return _to PutBuffer(aBuffer, aLength); } 

/* Use this macro to declare functions that forward the behavior of this interface to another object in a safe way. */
#define NS_FORWARD_SAFE_NSIOBJECTOUTPUTSTREAM(_to) \
  NS_SCRIPTABLE NS_IMETHOD WriteObject(nsISupports *aObject, PRBool aIsStrongRef) { return !_to ? NS_ERROR_NULL_POINTER : _to->WriteObject(aObject, aIsStrongRef); } \
  NS_SCRIPTABLE NS_IMETHOD WriteSingleRefObject(nsISupports *aObject) { return !_to ? NS_ERROR_NULL_POINTER : _to->WriteSingleRefObject(aObject); } \
  NS_SCRIPTABLE NS_IMETHOD WriteCompoundObject(nsISupports *aObject, const nsIID & aIID, PRBool aIsStrongRef) { return !_to ? NS_ERROR_NULL_POINTER : _to->WriteCompoundObject(aObject, aIID, aIsStrongRef); } \
  NS_SCRIPTABLE NS_IMETHOD WriteID(const nsID & aID) { return !_to ? NS_ERROR_NULL_POINTER : _to->WriteID(aID); } \
  NS_IMETHOD_(char *) GetBuffer(PRUint32 aLength, PRUint32 aAlignMask) { return !_to ? NS_ERROR_NULL_POINTER : _to->GetBuffer(aLength, aAlignMask); } \
  NS_IMETHOD_(void) PutBuffer(char * aBuffer, PRUint32 aLength) { return !_to ? NS_ERROR_NULL_POINTER : _to->PutBuffer(aBuffer, aLength); } 

#if 0
/* Use the code below as a template for the implementation class for this interface. */

/* Header file */
class nsObjectOutputStream : public nsIObjectOutputStream
{
public:
  NS_DECL_ISUPPORTS
  NS_DECL_NSIOBJECTOUTPUTSTREAM

  nsObjectOutputStream();

private:
  ~nsObjectOutputStream();

protected:
  /* additional members */
};

/* Implementation file */
NS_IMPL_ISUPPORTS1(nsObjectOutputStream, nsIObjectOutputStream)

nsObjectOutputStream::nsObjectOutputStream()
{
  /* member initializers and constructor code */
}

nsObjectOutputStream::~nsObjectOutputStream()
{
  /* destructor code */
}

/* void writeObject (in nsISupports aObject, in PRBool aIsStrongRef); */
NS_IMETHODIMP nsObjectOutputStream::WriteObject(nsISupports *aObject, PRBool aIsStrongRef)
{
    return NS_ERROR_NOT_IMPLEMENTED;
}

/* void writeSingleRefObject (in nsISupports aObject); */
NS_IMETHODIMP nsObjectOutputStream::WriteSingleRefObject(nsISupports *aObject)
{
    return NS_ERROR_NOT_IMPLEMENTED;
}

/* void writeCompoundObject (in nsISupports aObject, in nsIIDRef aIID, in PRBool aIsStrongRef); */
NS_IMETHODIMP nsObjectOutputStream::WriteCompoundObject(nsISupports *aObject, const nsIID & aIID, PRBool aIsStrongRef)
{
    return NS_ERROR_NOT_IMPLEMENTED;
}

/* void writeID (in nsIDRef aID); */
NS_IMETHODIMP nsObjectOutputStream::WriteID(const nsID & aID)
{
    return NS_ERROR_NOT_IMPLEMENTED;
}

/* [notxpcom] charPtr getBuffer (in PRUint32 aLength, in PRUint32 aAlignMask); */
NS_IMETHODIMP_(char *) nsObjectOutputStream::GetBuffer(PRUint32 aLength, PRUint32 aAlignMask)
{
    return NS_ERROR_NOT_IMPLEMENTED;
}

/* [notxpcom] void putBuffer (in charPtr aBuffer, in PRUint32 aLength); */
NS_IMETHODIMP_(void) nsObjectOutputStream::PutBuffer(char * aBuffer, PRUint32 aLength)
{
    return NS_ERROR_NOT_IMPLEMENTED;
}

/* End of implementation class template. */
#endif

inline nsresult
NS_WriteOptionalObject(nsIObjectOutputStream* aStream, nsISupports* aObject,
                       PRBool aIsStrongRef)
{
    PRBool nonnull = (aObject != nsnull);
    nsresult rv = aStream->WriteBoolean(nonnull);
    if (NS_SUCCEEDED(rv) && nonnull)
        rv = aStream->WriteObject(aObject, aIsStrongRef);
    return rv;
}
inline nsresult
NS_WriteOptionalSingleRefObject(nsIObjectOutputStream* aStream,
                                nsISupports* aObject)
{
    PRBool nonnull = (aObject != nsnull);
    nsresult rv = aStream->WriteBoolean(nonnull);
    if (NS_SUCCEEDED(rv) && nonnull)
        rv = aStream->WriteSingleRefObject(aObject);
    return rv;
}
inline nsresult
NS_WriteOptionalCompoundObject(nsIObjectOutputStream* aStream,
                               nsISupports* aObject,
                               const nsIID& aIID,
                               PRBool aIsStrongRef)
{
    PRBool nonnull = (aObject != nsnull);
    nsresult rv = aStream->WriteBoolean(nonnull);
    if (NS_SUCCEEDED(rv) && nonnull)
        rv = aStream->WriteCompoundObject(aObject, aIID, aIsStrongRef);
    return rv;
}

#endif /* __gen_nsIObjectOutputStream_h__ */
