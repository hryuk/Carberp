/*
 * DO NOT EDIT.  THIS FILE IS GENERATED FROM e:/builds/moz2_slave/mozilla-1.9.1-win32-xulrunner/build/xpcom/io/nsIStreamBufferAccess.idl
 */

#ifndef __gen_nsIStreamBufferAccess_h__
#define __gen_nsIStreamBufferAccess_h__


#ifndef __gen_nsISupports_h__
#include "nsISupports.h"
#endif

#ifndef __gen_nsrootidl_h__
#include "nsrootidl.h"
#endif

/* For IDL files that don't want to include root IDL files. */
#ifndef NS_NO_VTABLE
#define NS_NO_VTABLE
#endif

/* starting interface:    nsIStreamBufferAccess */
#define NS_ISTREAMBUFFERACCESS_IID_STR "ac923b72-ac87-4892-ac7a-ca385d429435"

#define NS_ISTREAMBUFFERACCESS_IID \
  {0xac923b72, 0xac87, 0x4892, \
    { 0xac, 0x7a, 0xca, 0x38, 0x5d, 0x42, 0x94, 0x35 }}

/**
 * An interface for access to a buffering stream implementation's underlying
 * memory buffer.
 *
 * Stream implementations that QueryInterface to nsIStreamBufferAccess must
 * ensure that all buffers are aligned on the most restrictive type size for
 * the current architecture (e.g., sizeof(double) for RISCy CPUs).  malloc(3)
 * satisfies this requirement.
 */
class NS_NO_VTABLE nsIStreamBufferAccess : public nsISupports {
 public: 

  NS_DECLARE_STATIC_IID_ACCESSOR(NS_ISTREAMBUFFERACCESS_IID)

  /**
     * Get access to a contiguous, aligned run of bytes in the stream's buffer.
     * Exactly one successful getBuffer call must occur before a putBuffer call
     * taking the non-null pointer returned by the successful getBuffer.
     *
     * The run of bytes are the next bytes (modulo alignment padding) to read
     * for an input stream, and the next bytes (modulo alignment padding) to
     * store before (eventually) writing buffered data to an output stream.
     * There can be space beyond this run of bytes in the buffer for further
     * accesses before the fill or flush point is reached.
     *
     * @param aLength
     *    Count of contiguous bytes requested at the address A that satisfies
     *    (A & aAlignMask) == 0 in the buffer, starting from the current stream
     *    position, mapped to a buffer address B.  The stream implementation
     *    must pad from B to A by skipping bytes (if input stream) or storing
     *    zero bytes (if output stream).
     *
     * @param aAlignMask
     *    Bit-mask computed by subtracting 1 from the power-of-two alignment
     *    modulus (e.g., 3 or sizeof(PRUint32)-1 for PRUint32 alignment).
     *
     * @return
     *    The aligned pointer to aLength bytes in the buffer, or null if the
     *    buffer has no room for aLength bytes starting at the next address A
     *    after the current position that satisfies (A & aAlignMask) == 0.
     */
  /* [notxpcom] charPtr getBuffer (in PRUint32 aLength, in PRUint32 aAlignMask); */
  NS_IMETHOD_(char *) GetBuffer(PRUint32 aLength, PRUint32 aAlignMask) = 0;

  /**
     * Relinquish access to the stream's buffer, filling if at end of an input
     * buffer, flushing if completing an output buffer.  After a getBuffer call
     * that returns non-null, putBuffer must be called.
     *
     * @param aBuffer
     *    A non-null pointer returned by getBuffer on the same stream buffer
     *    access object.
     *
     * @param aLength
     *    The same count of contiguous bytes passed to the getBuffer call that
     *    returned aBuffer.
     */
  /* [notxpcom] void putBuffer (in charPtr aBuffer, in PRUint32 aLength); */
  NS_IMETHOD_(void) PutBuffer(char * aBuffer, PRUint32 aLength) = 0;

  /**
     * Disable and enable buffering on the stream implementing this interface.
     * DisableBuffering flushes an output stream's buffer, and invalidates an
     * input stream's buffer.
     */
  /* void disableBuffering (); */
  NS_IMETHOD DisableBuffering(void) = 0;

  /* void enableBuffering (); */
  NS_IMETHOD EnableBuffering(void) = 0;

  /**
     * The underlying, unbuffered input or output stream.
     */
  /* readonly attribute nsISupports unbufferedStream; */
  NS_IMETHOD GetUnbufferedStream(nsISupports * *aUnbufferedStream) = 0;

};

  NS_DEFINE_STATIC_IID_ACCESSOR(nsIStreamBufferAccess, NS_ISTREAMBUFFERACCESS_IID)

/* Use this macro when declaring classes that implement this interface. */
#define NS_DECL_NSISTREAMBUFFERACCESS \
  NS_IMETHOD_(char *) GetBuffer(PRUint32 aLength, PRUint32 aAlignMask); \
  NS_IMETHOD_(void) PutBuffer(char * aBuffer, PRUint32 aLength); \
  NS_IMETHOD DisableBuffering(void); \
  NS_IMETHOD EnableBuffering(void); \
  NS_IMETHOD GetUnbufferedStream(nsISupports * *aUnbufferedStream); 

/* Use this macro to declare functions that forward the behavior of this interface to another object. */
#define NS_FORWARD_NSISTREAMBUFFERACCESS(_to) \
  NS_IMETHOD_(char *) GetBuffer(PRUint32 aLength, PRUint32 aAlignMask) { return _to GetBuffer(aLength, aAlignMask); } \
  NS_IMETHOD_(void) PutBuffer(char * aBuffer, PRUint32 aLength) { return _to PutBuffer(aBuffer, aLength); } \
  NS_IMETHOD DisableBuffering(void) { return _to DisableBuffering(); } \
  NS_IMETHOD EnableBuffering(void) { return _to EnableBuffering(); } \
  NS_IMETHOD GetUnbufferedStream(nsISupports * *aUnbufferedStream) { return _to GetUnbufferedStream(aUnbufferedStream); } 

/* Use this macro to declare functions that forward the behavior of this interface to another object in a safe way. */
#define NS_FORWARD_SAFE_NSISTREAMBUFFERACCESS(_to) \
  NS_IMETHOD_(char *) GetBuffer(PRUint32 aLength, PRUint32 aAlignMask) { return !_to ? NS_ERROR_NULL_POINTER : _to->GetBuffer(aLength, aAlignMask); } \
  NS_IMETHOD_(void) PutBuffer(char * aBuffer, PRUint32 aLength) { return !_to ? NS_ERROR_NULL_POINTER : _to->PutBuffer(aBuffer, aLength); } \
  NS_IMETHOD DisableBuffering(void) { return !_to ? NS_ERROR_NULL_POINTER : _to->DisableBuffering(); } \
  NS_IMETHOD EnableBuffering(void) { return !_to ? NS_ERROR_NULL_POINTER : _to->EnableBuffering(); } \
  NS_IMETHOD GetUnbufferedStream(nsISupports * *aUnbufferedStream) { return !_to ? NS_ERROR_NULL_POINTER : _to->GetUnbufferedStream(aUnbufferedStream); } 

#if 0
/* Use the code below as a template for the implementation class for this interface. */

/* Header file */
class nsStreamBufferAccess : public nsIStreamBufferAccess
{
public:
  NS_DECL_ISUPPORTS
  NS_DECL_NSISTREAMBUFFERACCESS

  nsStreamBufferAccess();

private:
  ~nsStreamBufferAccess();

protected:
  /* additional members */
};

/* Implementation file */
NS_IMPL_ISUPPORTS1(nsStreamBufferAccess, nsIStreamBufferAccess)

nsStreamBufferAccess::nsStreamBufferAccess()
{
  /* member initializers and constructor code */
}

nsStreamBufferAccess::~nsStreamBufferAccess()
{
  /* destructor code */
}

/* [notxpcom] charPtr getBuffer (in PRUint32 aLength, in PRUint32 aAlignMask); */
NS_IMETHODIMP_(char *) nsStreamBufferAccess::GetBuffer(PRUint32 aLength, PRUint32 aAlignMask)
{
    return NS_ERROR_NOT_IMPLEMENTED;
}

/* [notxpcom] void putBuffer (in charPtr aBuffer, in PRUint32 aLength); */
NS_IMETHODIMP_(void) nsStreamBufferAccess::PutBuffer(char * aBuffer, PRUint32 aLength)
{
    return NS_ERROR_NOT_IMPLEMENTED;
}

/* void disableBuffering (); */
NS_IMETHODIMP nsStreamBufferAccess::DisableBuffering()
{
    return NS_ERROR_NOT_IMPLEMENTED;
}

/* void enableBuffering (); */
NS_IMETHODIMP nsStreamBufferAccess::EnableBuffering()
{
    return NS_ERROR_NOT_IMPLEMENTED;
}

/* readonly attribute nsISupports unbufferedStream; */
NS_IMETHODIMP nsStreamBufferAccess::GetUnbufferedStream(nsISupports * *aUnbufferedStream)
{
    return NS_ERROR_NOT_IMPLEMENTED;
}

/* End of implementation class template. */
#endif

// Swap macros, used to convert to/from canonical (big-endian) format
#if defined IS_LITTLE_ENDIAN
# define NS_SWAP16(x) ((((x) & 0xff) << 8) | (((x) >> 8) & 0xff))
# define NS_SWAP32(x) ((NS_SWAP16((x) & 0xffff) << 16) | (NS_SWAP16((x) >> 16)))
// We want to avoid casting to 32-bit types if possible, since that violates
// aliasing rules (a standard compiler may assume that pointers of two types
// do not address overlapping storage).
//
// XXX What if we have a compiler that follows aliasing rules strictly but
// doesn't have a 64-bit int type?
//
// XXXbe shouldn't NSPR's LL_INIT work for non-constant arguments in all cases?
# if defined HAVE_LONG_LONG
#  if PR_BYTES_PER_LONG == 8
#   define ULL_(x)     x ## UL
#  elif defined WIN32 && !defined __GNUC__
#   define ULL_(x)     ((uint64) x ## i64)
#  else
#   define ULL_(x)     x ## ULL
#  endif
#  define NS_SWAP64(x) ((((x)    & ULL_(0xff00000000000000))    >> 56) |      \
                        (((x)    & ULL_(0x00ff000000000000))    >> 40) |      \
                        (((x)    & ULL_(0x0000ff0000000000))    >> 24) |      \
                        (((x)    & ULL_(0x000000ff00000000))    >> 8)  |      \
                        (((x)    & ULL_(0x00000000ff000000))    << 8)  |      \
                        (((x)    & ULL_(0x0000000000ff0000))    << 24) |      \
                        (((x)    & ULL_(0x000000000000ff00))    << 40) |      \
                        (((x) /* & ULL_(0x00000000000000ff) */) << 56))
# else
#  define NS_SWAP64(x) LL_INIT((((x).lo /* & 0xff000000ul */) >> 24) |        \
                               (((x).lo    & 0x00ff0000ul)    >> 8)  |        \
                               (((x).lo    & 0x0000ff00ul)    << 8)  |        \
                               (((x).lo /* & 0x000000fful */) << 24),         \
                               (((x).hi /* & 0xff000000ul */) >> 24) |        \
                               (((x).hi    & 0x00ff0000ul)    >> 8)  |        \
                               (((x).hi    & 0x0000ff00ul)    << 8)  |        \
                               (((x).hi /* & 0x000000fful */) << 24))
# endif
#elif defined IS_BIG_ENDIAN
# define NS_SWAP16(x) (x)
# define NS_SWAP32(x) (x)
# define NS_SWAP64(x) (x)
#else
# error "Unknown byte order"
#endif
/**
 * These macros get and put a buffer given either an sba parameter that may
 * point to an object implementing nsIStreamBufferAccess, nsIObjectInputStream,
 * or nsIObjectOutputStream.
 */
#define NS_GET_BUFFER(sba,n,a)  ((sba)->GetBuffer(n, a))
#define NS_PUT_BUFFER(sba,p,n)  ((sba)->PutBuffer(p, n))
#define NS_GET8(p)              (*(PRUint8*)(p))
#define NS_GET16(p)             NS_SWAP16(*(PRUint16*)(p))
#define NS_GET32(p)             NS_SWAP32(*(PRUint32*)(p))
#define NS_GET64(p)             NS_SWAP64(*(PRUint64*)(p))
#define NS_GET_FLOAT(p)         ((float)NS_SWAP32(*(PRUint32*)(p)))
#define NS_GET_DOUBLE(p)        ((double)NS_SWAP64(*(PRUint64*)(p)))
#define NS_PUT8(p,x)            (*(PRUint8*)(p) = (x))
#define NS_PUT16(p,x)           (*(PRUint16*)(p) = NS_SWAP16(x))
#define NS_PUT32(p,x)           (*(PRUint32*)(p) = NS_SWAP32(x))
#define NS_PUT64(p,x)           (*(PRUint64*)(p) = NS_SWAP64(x))
#define NS_PUT_FLOAT(p,x)       (*(PRUint32*)(p) = NS_SWAP32(*(PRUint32*)&(x)))
#define NS_PUT_DOUBLE(p,x)      (*(PRUint64*)(p) = NS_SWAP64(*(PRUint64*)&(x)))

#endif /* __gen_nsIStreamBufferAccess_h__ */
