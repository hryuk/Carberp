/*
 * DO NOT EDIT.  THIS FILE IS GENERATED FROM e:/builds/moz2_slave/mozilla-1.9.1-win32-xulrunner/build/xpcom/io/nsIPipe.idl
 */

#ifndef __gen_nsIPipe_h__
#define __gen_nsIPipe_h__


#ifndef __gen_nsIAsyncInputStream_h__
#include "nsIAsyncInputStream.h"
#endif

#ifndef __gen_nsIAsyncOutputStream_h__
#include "nsIAsyncOutputStream.h"
#endif

/* For IDL files that don't want to include root IDL files. */
#ifndef NS_NO_VTABLE
#define NS_NO_VTABLE
#endif
class nsIMemory; /* forward declaration */


/* starting interface:    nsIPipe */
#define NS_IPIPE_IID_STR "f4211abc-61b3-11d4-9877-00c04fa0cf4a"

#define NS_IPIPE_IID \
  {0xf4211abc, 0x61b3, 0x11d4, \
    { 0x98, 0x77, 0x00, 0xc0, 0x4f, 0xa0, 0xcf, 0x4a }}

/**
 * nsIPipe represents an in-process buffer that can be read using nsIInputStream
 * and written using nsIOutputStream.  The reader and writer of a pipe do not
 * have to be on the same thread.  As a result, the pipe is an ideal mechanism
 * to bridge data exchange between two threads.  For example, a worker thread
 * might write data to a pipe from which the main thread will read.
 *
 * Each end of the pipe can be either blocking or non-blocking.  Recall that a
 * non-blocking stream will return NS_BASE_STREAM_WOULD_BLOCK if it cannot be
 * read or written to without blocking the calling thread.  For example, if you
 * try to read from an empty pipe that has not yet been closed, then if that
 * pipe's input end is non-blocking, then the read call will fail immediately
 * with NS_BASE_STREAM_WOULD_BLOCK as the error condition.  However, if that
 * pipe's input end is blocking, then the read call will not return until the
 * pipe has data or until the pipe is closed.  This example presumes that the
 * pipe is being filled asynchronously on some background thread.
 *
 * The pipe supports nsIAsyncInputStream and nsIAsyncOutputStream, which give
 * the user of a non-blocking pipe the ability to wait for the pipe to become
 * ready again.  For example, in the case of an empty non-blocking pipe, the
 * user can call AsyncWait on the input end of the pipe to be notified when 
 * the pipe has data to read (or when the pipe becomes closed).
 *
 * NS_NewPipe2 and NS_NewPipe provide convenient pipe constructors.  In most
 * cases nsIPipe is not actually used.  It is usually enough to just get
 * references to the pipe's input and output end.  In which case, the pipe is
 * automatically closed when the respective pipe ends are released.
 */
class NS_NO_VTABLE NS_SCRIPTABLE nsIPipe : public nsISupports {
 public: 

  NS_DECLARE_STATIC_IID_ACCESSOR(NS_IPIPE_IID)

  /**
     * initialize this pipe
     *
     * @param nonBlockingInput
     *        true specifies non-blocking input stream behavior
     * @param nonBlockingOutput
     *        true specifies non-blocking output stream behavior
     * @param segmentSize
     *        specifies the segment size in bytes (pass 0 to use default value)
     * @param segmentCount
     *        specifies the max number of segments (pass 0 to use default
     *        value).   Passing PR_UINT32_MAX here causes the pipe to have
     *        "infinite" space.  This mode can be useful in some cases, but
     *        should always be used with caution.  The default value for this
     *        parameter is a finite value.
     * @param segmentAllocator
     *        pass reference to nsIMemory to have all pipe allocations use this
     *        allocator (pass null to use the default allocator)
     */
  /* void init (in boolean nonBlockingInput, in boolean nonBlockingOutput, in unsigned long segmentSize, in unsigned long segmentCount, in nsIMemory segmentAllocator); */
  NS_SCRIPTABLE NS_IMETHOD Init(PRBool nonBlockingInput, PRBool nonBlockingOutput, PRUint32 segmentSize, PRUint32 segmentCount, nsIMemory *segmentAllocator) = 0;

  /**
     * The pipe's input end, which also implements nsISearchableInputStream.
     */
  /* readonly attribute nsIAsyncInputStream inputStream; */
  NS_SCRIPTABLE NS_IMETHOD GetInputStream(nsIAsyncInputStream * *aInputStream) = 0;

  /**
     * The pipe's output end.
     */
  /* readonly attribute nsIAsyncOutputStream outputStream; */
  NS_SCRIPTABLE NS_IMETHOD GetOutputStream(nsIAsyncOutputStream * *aOutputStream) = 0;

};

  NS_DEFINE_STATIC_IID_ACCESSOR(nsIPipe, NS_IPIPE_IID)

/* Use this macro when declaring classes that implement this interface. */
#define NS_DECL_NSIPIPE \
  NS_SCRIPTABLE NS_IMETHOD Init(PRBool nonBlockingInput, PRBool nonBlockingOutput, PRUint32 segmentSize, PRUint32 segmentCount, nsIMemory *segmentAllocator); \
  NS_SCRIPTABLE NS_IMETHOD GetInputStream(nsIAsyncInputStream * *aInputStream); \
  NS_SCRIPTABLE NS_IMETHOD GetOutputStream(nsIAsyncOutputStream * *aOutputStream); 

/* Use this macro to declare functions that forward the behavior of this interface to another object. */
#define NS_FORWARD_NSIPIPE(_to) \
  NS_SCRIPTABLE NS_IMETHOD Init(PRBool nonBlockingInput, PRBool nonBlockingOutput, PRUint32 segmentSize, PRUint32 segmentCount, nsIMemory *segmentAllocator) { return _to Init(nonBlockingInput, nonBlockingOutput, segmentSize, segmentCount, segmentAllocator); } \
  NS_SCRIPTABLE NS_IMETHOD GetInputStream(nsIAsyncInputStream * *aInputStream) { return _to GetInputStream(aInputStream); } \
  NS_SCRIPTABLE NS_IMETHOD GetOutputStream(nsIAsyncOutputStream * *aOutputStream) { return _to GetOutputStream(aOutputStream); } 

/* Use this macro to declare functions that forward the behavior of this interface to another object in a safe way. */
#define NS_FORWARD_SAFE_NSIPIPE(_to) \
  NS_SCRIPTABLE NS_IMETHOD Init(PRBool nonBlockingInput, PRBool nonBlockingOutput, PRUint32 segmentSize, PRUint32 segmentCount, nsIMemory *segmentAllocator) { return !_to ? NS_ERROR_NULL_POINTER : _to->Init(nonBlockingInput, nonBlockingOutput, segmentSize, segmentCount, segmentAllocator); } \
  NS_SCRIPTABLE NS_IMETHOD GetInputStream(nsIAsyncInputStream * *aInputStream) { return !_to ? NS_ERROR_NULL_POINTER : _to->GetInputStream(aInputStream); } \
  NS_SCRIPTABLE NS_IMETHOD GetOutputStream(nsIAsyncOutputStream * *aOutputStream) { return !_to ? NS_ERROR_NULL_POINTER : _to->GetOutputStream(aOutputStream); } 

#if 0
/* Use the code below as a template for the implementation class for this interface. */

/* Header file */
class nsPipe : public nsIPipe
{
public:
  NS_DECL_ISUPPORTS
  NS_DECL_NSIPIPE

  nsPipe();

private:
  ~nsPipe();

protected:
  /* additional members */
};

/* Implementation file */
NS_IMPL_ISUPPORTS1(nsPipe, nsIPipe)

nsPipe::nsPipe()
{
  /* member initializers and constructor code */
}

nsPipe::~nsPipe()
{
  /* destructor code */
}

/* void init (in boolean nonBlockingInput, in boolean nonBlockingOutput, in unsigned long segmentSize, in unsigned long segmentCount, in nsIMemory segmentAllocator); */
NS_IMETHODIMP nsPipe::Init(PRBool nonBlockingInput, PRBool nonBlockingOutput, PRUint32 segmentSize, PRUint32 segmentCount, nsIMemory *segmentAllocator)
{
    return NS_ERROR_NOT_IMPLEMENTED;
}

/* readonly attribute nsIAsyncInputStream inputStream; */
NS_IMETHODIMP nsPipe::GetInputStream(nsIAsyncInputStream * *aInputStream)
{
    return NS_ERROR_NOT_IMPLEMENTED;
}

/* readonly attribute nsIAsyncOutputStream outputStream; */
NS_IMETHODIMP nsPipe::GetOutputStream(nsIAsyncOutputStream * *aOutputStream)
{
    return NS_ERROR_NOT_IMPLEMENTED;
}

/* End of implementation class template. */
#endif


/* starting interface:    nsISearchableInputStream */
#define NS_ISEARCHABLEINPUTSTREAM_IID_STR "8c39ef62-f7c9-11d4-98f5-001083010e9b"

#define NS_ISEARCHABLEINPUTSTREAM_IID \
  {0x8c39ef62, 0xf7c9, 0x11d4, \
    { 0x98, 0xf5, 0x00, 0x10, 0x83, 0x01, 0x0e, 0x9b }}

/**
 * XXX this interface doesn't really belong in here.  It is here because
 * currently nsPipeInputStream is the only implementation of this interface.
 */
class NS_NO_VTABLE NS_SCRIPTABLE nsISearchableInputStream : public nsISupports {
 public: 

  NS_DECLARE_STATIC_IID_ACCESSOR(NS_ISEARCHABLEINPUTSTREAM_IID)

  /**
     * Searches for a string in the input stream. Since the stream has a notion
     * of EOF, it is possible that the string may at some time be in the 
     * buffer, but is is not currently found up to some offset. Consequently,
     * both the found and not found cases return an offset:
     *    if found, return offset where it was found
     *    if not found, return offset of the first byte not searched
     * In the case the stream is at EOF and the string is not found, the first
     * byte not searched will correspond to the length of the buffer.
     */
  /* void search (in string forString, in boolean ignoreCase, out boolean found, out unsigned long offsetSearchedTo); */
  NS_SCRIPTABLE NS_IMETHOD Search(const char *forString, PRBool ignoreCase, PRBool *found NS_OUTPARAM, PRUint32 *offsetSearchedTo NS_OUTPARAM) = 0;

};

  NS_DEFINE_STATIC_IID_ACCESSOR(nsISearchableInputStream, NS_ISEARCHABLEINPUTSTREAM_IID)

/* Use this macro when declaring classes that implement this interface. */
#define NS_DECL_NSISEARCHABLEINPUTSTREAM \
  NS_SCRIPTABLE NS_IMETHOD Search(const char *forString, PRBool ignoreCase, PRBool *found NS_OUTPARAM, PRUint32 *offsetSearchedTo NS_OUTPARAM); 

/* Use this macro to declare functions that forward the behavior of this interface to another object. */
#define NS_FORWARD_NSISEARCHABLEINPUTSTREAM(_to) \
  NS_SCRIPTABLE NS_IMETHOD Search(const char *forString, PRBool ignoreCase, PRBool *found NS_OUTPARAM, PRUint32 *offsetSearchedTo NS_OUTPARAM) { return _to Search(forString, ignoreCase, found, offsetSearchedTo); } 

/* Use this macro to declare functions that forward the behavior of this interface to another object in a safe way. */
#define NS_FORWARD_SAFE_NSISEARCHABLEINPUTSTREAM(_to) \
  NS_SCRIPTABLE NS_IMETHOD Search(const char *forString, PRBool ignoreCase, PRBool *found NS_OUTPARAM, PRUint32 *offsetSearchedTo NS_OUTPARAM) { return !_to ? NS_ERROR_NULL_POINTER : _to->Search(forString, ignoreCase, found, offsetSearchedTo); } 

#if 0
/* Use the code below as a template for the implementation class for this interface. */

/* Header file */
class nsSearchableInputStream : public nsISearchableInputStream
{
public:
  NS_DECL_ISUPPORTS
  NS_DECL_NSISEARCHABLEINPUTSTREAM

  nsSearchableInputStream();

private:
  ~nsSearchableInputStream();

protected:
  /* additional members */
};

/* Implementation file */
NS_IMPL_ISUPPORTS1(nsSearchableInputStream, nsISearchableInputStream)

nsSearchableInputStream::nsSearchableInputStream()
{
  /* member initializers and constructor code */
}

nsSearchableInputStream::~nsSearchableInputStream()
{
  /* destructor code */
}

/* void search (in string forString, in boolean ignoreCase, out boolean found, out unsigned long offsetSearchedTo); */
NS_IMETHODIMP nsSearchableInputStream::Search(const char *forString, PRBool ignoreCase, PRBool *found NS_OUTPARAM, PRUint32 *offsetSearchedTo NS_OUTPARAM)
{
    return NS_ERROR_NOT_IMPLEMENTED;
}

/* End of implementation class template. */
#endif

/**
 * NS_NewPipe2
 *
 * This function supercedes NS_NewPipe.  It differs from NS_NewPipe in two
 * major ways:
 *  (1) returns nsIAsyncInputStream and nsIAsyncOutputStream, so it is
 *      not necessary to QI in order to access these interfaces.
 *  (2) the size of the pipe is determined by the number of segments
 *      times the size of each segment.
 *
 * @param pipeIn
 *        resulting input end of the pipe
 * @param pipeOut
 *        resulting output end of the pipe
 * @param nonBlockingInput
 *        true specifies non-blocking input stream behavior
 * @param nonBlockingOutput
 *        true specifies non-blocking output stream behavior
 * @param segmentSize
 *        specifies the segment size in bytes (pass 0 to use default value)
 * @param segmentCount
 *        specifies the max number of segments (pass 0 to use default value)
 *        passing PR_UINT32_MAX here causes the pipe to have "infinite" space.
 *        this mode can be useful in some cases, but should always be used with
 *        caution.  the default value for this parameter is a finite value.
 * @param segmentAlloc
 *        pass reference to nsIMemory to have all pipe allocations use this
 *        allocator (pass null to use the default allocator)
 */
extern NS_COM nsresult
NS_NewPipe2(nsIAsyncInputStream **pipeIn,
            nsIAsyncOutputStream **pipeOut,
            PRBool nonBlockingInput = PR_FALSE,
            PRBool nonBlockingOutput = PR_FALSE,
            PRUint32 segmentSize = 0,
            PRUint32 segmentCount = 0,
            nsIMemory *segmentAlloc = nsnull);
/**
 * NS_NewPipe
 *
 * Preserved for backwards compatibility.  Plus, this interface is more
 * amiable in certain contexts (e.g., when you don't need the pipe's async
 * capabilities).
 *
 * @param pipeIn
 *        resulting input end of the pipe
 * @param pipeOut
 *        resulting output end of the pipe
 * @param segmentSize
 *        specifies the segment size in bytes (pass 0 to use default value)
 * @param maxSize
 *        specifies the max size of the pipe (pass 0 to use default value)
 *        number of segments is maxSize / segmentSize, and maxSize must be a
 *        multiple of segmentSize.  passing PR_UINT32_MAX here causes the
 *        pipe to have "infinite" space.  this mode can be useful in some
 *        cases, but should always be used with caution.  the default value
 *        for this parameter is a finite value.
 * @param nonBlockingInput
 *        true specifies non-blocking input stream behavior
 * @param nonBlockingOutput
 *        true specifies non-blocking output stream behavior
 * @param segmentAlloc
 *        pass reference to nsIMemory to have all pipe allocations use this
 *        allocator (pass null to use the default allocator)
 */
extern NS_COM nsresult
NS_NewPipe(nsIInputStream **pipeIn,
           nsIOutputStream **pipeOut,
           PRUint32 segmentSize = 0,
           PRUint32 maxSize = 0,
           PRBool nonBlockingInput = PR_FALSE,
           PRBool nonBlockingOutput = PR_FALSE,
           nsIMemory *segmentAlloc = nsnull);

#endif /* __gen_nsIPipe_h__ */
