/*
 * DO NOT EDIT.  THIS FILE IS GENERATED FROM e:/builds/moz2_slave/mozilla-1.9.1-win32-xulrunner/build/xpcom/io/nsIFastLoadService.idl
 */

#ifndef __gen_nsIFastLoadService_h__
#define __gen_nsIFastLoadService_h__


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
class nsIFastLoadReadControl; /* forward declaration */

class nsIFile; /* forward declaration */

class nsIInputStream; /* forward declaration */

class nsIOutputStream; /* forward declaration */

class nsIObjectInputStream; /* forward declaration */

class nsIObjectOutputStream; /* forward declaration */


/* starting interface:    nsIFastLoadFileIO */
#define NS_IFASTLOADFILEIO_IID_STR "715577db-d9c5-464a-a32e-0a40c29b22d4"

#define NS_IFASTLOADFILEIO_IID \
  {0x715577db, 0xd9c5, 0x464a, \
    { 0xa3, 0x2e, 0x0a, 0x40, 0xc2, 0x9b, 0x22, 0xd4 }}

class NS_NO_VTABLE NS_SCRIPTABLE nsIFastLoadFileIO : public nsISupports {
 public: 

  NS_DECLARE_STATIC_IID_ACCESSOR(NS_IFASTLOADFILEIO_IID)

  /* readonly attribute nsIInputStream inputStream; */
  NS_SCRIPTABLE NS_IMETHOD GetInputStream(nsIInputStream * *aInputStream) = 0;

  /* readonly attribute nsIOutputStream outputStream; */
  NS_SCRIPTABLE NS_IMETHOD GetOutputStream(nsIOutputStream * *aOutputStream) = 0;

};

  NS_DEFINE_STATIC_IID_ACCESSOR(nsIFastLoadFileIO, NS_IFASTLOADFILEIO_IID)

/* Use this macro when declaring classes that implement this interface. */
#define NS_DECL_NSIFASTLOADFILEIO \
  NS_SCRIPTABLE NS_IMETHOD GetInputStream(nsIInputStream * *aInputStream); \
  NS_SCRIPTABLE NS_IMETHOD GetOutputStream(nsIOutputStream * *aOutputStream); 

/* Use this macro to declare functions that forward the behavior of this interface to another object. */
#define NS_FORWARD_NSIFASTLOADFILEIO(_to) \
  NS_SCRIPTABLE NS_IMETHOD GetInputStream(nsIInputStream * *aInputStream) { return _to GetInputStream(aInputStream); } \
  NS_SCRIPTABLE NS_IMETHOD GetOutputStream(nsIOutputStream * *aOutputStream) { return _to GetOutputStream(aOutputStream); } 

/* Use this macro to declare functions that forward the behavior of this interface to another object in a safe way. */
#define NS_FORWARD_SAFE_NSIFASTLOADFILEIO(_to) \
  NS_SCRIPTABLE NS_IMETHOD GetInputStream(nsIInputStream * *aInputStream) { return !_to ? NS_ERROR_NULL_POINTER : _to->GetInputStream(aInputStream); } \
  NS_SCRIPTABLE NS_IMETHOD GetOutputStream(nsIOutputStream * *aOutputStream) { return !_to ? NS_ERROR_NULL_POINTER : _to->GetOutputStream(aOutputStream); } 

#if 0
/* Use the code below as a template for the implementation class for this interface. */

/* Header file */
class nsFastLoadFileIO : public nsIFastLoadFileIO
{
public:
  NS_DECL_ISUPPORTS
  NS_DECL_NSIFASTLOADFILEIO

  nsFastLoadFileIO();

private:
  ~nsFastLoadFileIO();

protected:
  /* additional members */
};

/* Implementation file */
NS_IMPL_ISUPPORTS1(nsFastLoadFileIO, nsIFastLoadFileIO)

nsFastLoadFileIO::nsFastLoadFileIO()
{
  /* member initializers and constructor code */
}

nsFastLoadFileIO::~nsFastLoadFileIO()
{
  /* destructor code */
}

/* readonly attribute nsIInputStream inputStream; */
NS_IMETHODIMP nsFastLoadFileIO::GetInputStream(nsIInputStream * *aInputStream)
{
    return NS_ERROR_NOT_IMPLEMENTED;
}

/* readonly attribute nsIOutputStream outputStream; */
NS_IMETHODIMP nsFastLoadFileIO::GetOutputStream(nsIOutputStream * *aOutputStream)
{
    return NS_ERROR_NOT_IMPLEMENTED;
}

/* End of implementation class template. */
#endif


/* starting interface:    nsIFastLoadService */
#define NS_IFASTLOADSERVICE_IID_STR "759e475e-0c23-4dbf-b1b8-78c9369e3072"

#define NS_IFASTLOADSERVICE_IID \
  {0x759e475e, 0x0c23, 0x4dbf, \
    { 0xb1, 0xb8, 0x78, 0xc9, 0x36, 0x9e, 0x30, 0x72 }}

class NS_NO_VTABLE NS_SCRIPTABLE nsIFastLoadService : public nsISupports {
 public: 

  NS_DECLARE_STATIC_IID_ACCESSOR(NS_IFASTLOADSERVICE_IID)

  /* nsIFile newFastLoadFile (in string aBaseName); */
  NS_SCRIPTABLE NS_IMETHOD NewFastLoadFile(const char *aBaseName, nsIFile **_retval NS_OUTPARAM) = 0;

  /* nsIObjectInputStream newInputStream (in nsIInputStream aSrcStream); */
  NS_SCRIPTABLE NS_IMETHOD NewInputStream(nsIInputStream *aSrcStream, nsIObjectInputStream **_retval NS_OUTPARAM) = 0;

  /* nsIObjectOutputStream newOutputStream (in nsIOutputStream aDestStream); */
  NS_SCRIPTABLE NS_IMETHOD NewOutputStream(nsIOutputStream *aDestStream, nsIObjectOutputStream **_retval NS_OUTPARAM) = 0;

  enum { NS_FASTLOAD_READ = 1 };

  enum { NS_FASTLOAD_WRITE = 2 };

  /* attribute nsIObjectInputStream inputStream; */
  NS_SCRIPTABLE NS_IMETHOD GetInputStream(nsIObjectInputStream * *aInputStream) = 0;
  NS_SCRIPTABLE NS_IMETHOD SetInputStream(nsIObjectInputStream * aInputStream) = 0;

  /* attribute nsIObjectOutputStream outputStream; */
  NS_SCRIPTABLE NS_IMETHOD GetOutputStream(nsIObjectOutputStream * *aOutputStream) = 0;
  NS_SCRIPTABLE NS_IMETHOD SetOutputStream(nsIObjectOutputStream * aOutputStream) = 0;

  /* attribute nsIFastLoadFileIO fileIO; */
  NS_SCRIPTABLE NS_IMETHOD GetFileIO(nsIFastLoadFileIO * *aFileIO) = 0;
  NS_SCRIPTABLE NS_IMETHOD SetFileIO(nsIFastLoadFileIO * aFileIO) = 0;

  /* readonly attribute PRInt32 direction; */
  NS_SCRIPTABLE NS_IMETHOD GetDirection(PRInt32 *aDirection) = 0;

  /**
     * These methods associate a URI object with its spec, for faster select
     * using the object pointer as a key, rather than the spec string.  The
     * selectMuxedDocument method returns the previously selected URI object,
     * in case a caller needs to reselect the previous after muxing data for
     * a given URI synchronously.  For the non-blocking or "asynchronous" i/o
     * case, the caller must select the source URI from the FastLoad multiplex
     * before writing a new burst of data parsed from the slow-loaded source.
     *
     * Clients of inputStream and outputStream should try to demultiplex data
     * from the input stream only if fastLoadService->StartMuxedDocument(uri,
     * urispec, NS_FASTLOAD_READ) succeeds.  If StartMuxedDocument fails with
     * NS_ERROR_NOT_AVAILABLE, callers should slow-load the documents, muxing
     * their data to the current output stream.
     */
  /* void startMuxedDocument (in nsISupports aURI, in string aURISpec, in PRInt32 aDirectionFlags); */
  NS_SCRIPTABLE NS_IMETHOD StartMuxedDocument(nsISupports *aURI, const char *aURISpec, PRInt32 aDirectionFlags) = 0;

  /* nsISupports selectMuxedDocument (in nsISupports aURI); */
  NS_SCRIPTABLE NS_IMETHOD SelectMuxedDocument(nsISupports *aURI, nsISupports **_retval NS_OUTPARAM) = 0;

  /* void endMuxedDocument (in nsISupports aURI); */
  NS_SCRIPTABLE NS_IMETHOD EndMuxedDocument(nsISupports *aURI) = 0;

  /* void addDependency (in nsIFile aFile); */
  NS_SCRIPTABLE NS_IMETHOD AddDependency(nsIFile *aFile) = 0;

  /* PRUint32 computeChecksum (in nsIFile aFile, in nsIFastLoadReadControl aControl); */
  NS_SCRIPTABLE NS_IMETHOD ComputeChecksum(nsIFile *aFile, nsIFastLoadReadControl *aControl, PRUint32 *_retval NS_OUTPARAM) = 0;

  /* void cacheChecksum (in nsIFile aFile, in nsIObjectOutputStream aStream); */
  NS_SCRIPTABLE NS_IMETHOD CacheChecksum(nsIFile *aFile, nsIObjectOutputStream *aStream) = 0;

  /* [noscript] void getFastLoadReferent (inout nsISupports aPtr); */
  NS_IMETHOD GetFastLoadReferent(nsISupports **aPtr NS_INOUTPARAM) = 0;

  /* [noscript] void readFastLoadPtr (in nsIObjectInputStream aInputStream, inout nsISupports aPtr); */
  NS_IMETHOD ReadFastLoadPtr(nsIObjectInputStream *aInputStream, nsISupports **aPtr NS_INOUTPARAM) = 0;

  /* [noscript] void writeFastLoadPtr (in nsIObjectOutputStream aOutputStream, in nsISupports aPtr); */
  NS_IMETHOD WriteFastLoadPtr(nsIObjectOutputStream *aOutputStream, nsISupports *aPtr) = 0;

  /**
     * Return true if aURISpec identifies a muxed document in the FastLoad
     * file, false otherwise.
     */
  /* boolean hasMuxedDocument (in string aURISpec); */
  NS_SCRIPTABLE NS_IMETHOD HasMuxedDocument(const char *aURISpec, PRBool *_retval NS_OUTPARAM) = 0;

};

  NS_DEFINE_STATIC_IID_ACCESSOR(nsIFastLoadService, NS_IFASTLOADSERVICE_IID)

/* Use this macro when declaring classes that implement this interface. */
#define NS_DECL_NSIFASTLOADSERVICE \
  NS_SCRIPTABLE NS_IMETHOD NewFastLoadFile(const char *aBaseName, nsIFile **_retval NS_OUTPARAM); \
  NS_SCRIPTABLE NS_IMETHOD NewInputStream(nsIInputStream *aSrcStream, nsIObjectInputStream **_retval NS_OUTPARAM); \
  NS_SCRIPTABLE NS_IMETHOD NewOutputStream(nsIOutputStream *aDestStream, nsIObjectOutputStream **_retval NS_OUTPARAM); \
  NS_SCRIPTABLE NS_IMETHOD GetInputStream(nsIObjectInputStream * *aInputStream); \
  NS_SCRIPTABLE NS_IMETHOD SetInputStream(nsIObjectInputStream * aInputStream); \
  NS_SCRIPTABLE NS_IMETHOD GetOutputStream(nsIObjectOutputStream * *aOutputStream); \
  NS_SCRIPTABLE NS_IMETHOD SetOutputStream(nsIObjectOutputStream * aOutputStream); \
  NS_SCRIPTABLE NS_IMETHOD GetFileIO(nsIFastLoadFileIO * *aFileIO); \
  NS_SCRIPTABLE NS_IMETHOD SetFileIO(nsIFastLoadFileIO * aFileIO); \
  NS_SCRIPTABLE NS_IMETHOD GetDirection(PRInt32 *aDirection); \
  NS_SCRIPTABLE NS_IMETHOD StartMuxedDocument(nsISupports *aURI, const char *aURISpec, PRInt32 aDirectionFlags); \
  NS_SCRIPTABLE NS_IMETHOD SelectMuxedDocument(nsISupports *aURI, nsISupports **_retval NS_OUTPARAM); \
  NS_SCRIPTABLE NS_IMETHOD EndMuxedDocument(nsISupports *aURI); \
  NS_SCRIPTABLE NS_IMETHOD AddDependency(nsIFile *aFile); \
  NS_SCRIPTABLE NS_IMETHOD ComputeChecksum(nsIFile *aFile, nsIFastLoadReadControl *aControl, PRUint32 *_retval NS_OUTPARAM); \
  NS_SCRIPTABLE NS_IMETHOD CacheChecksum(nsIFile *aFile, nsIObjectOutputStream *aStream); \
  NS_IMETHOD GetFastLoadReferent(nsISupports **aPtr NS_INOUTPARAM); \
  NS_IMETHOD ReadFastLoadPtr(nsIObjectInputStream *aInputStream, nsISupports **aPtr NS_INOUTPARAM); \
  NS_IMETHOD WriteFastLoadPtr(nsIObjectOutputStream *aOutputStream, nsISupports *aPtr); \
  NS_SCRIPTABLE NS_IMETHOD HasMuxedDocument(const char *aURISpec, PRBool *_retval NS_OUTPARAM); 

/* Use this macro to declare functions that forward the behavior of this interface to another object. */
#define NS_FORWARD_NSIFASTLOADSERVICE(_to) \
  NS_SCRIPTABLE NS_IMETHOD NewFastLoadFile(const char *aBaseName, nsIFile **_retval NS_OUTPARAM) { return _to NewFastLoadFile(aBaseName, _retval); } \
  NS_SCRIPTABLE NS_IMETHOD NewInputStream(nsIInputStream *aSrcStream, nsIObjectInputStream **_retval NS_OUTPARAM) { return _to NewInputStream(aSrcStream, _retval); } \
  NS_SCRIPTABLE NS_IMETHOD NewOutputStream(nsIOutputStream *aDestStream, nsIObjectOutputStream **_retval NS_OUTPARAM) { return _to NewOutputStream(aDestStream, _retval); } \
  NS_SCRIPTABLE NS_IMETHOD GetInputStream(nsIObjectInputStream * *aInputStream) { return _to GetInputStream(aInputStream); } \
  NS_SCRIPTABLE NS_IMETHOD SetInputStream(nsIObjectInputStream * aInputStream) { return _to SetInputStream(aInputStream); } \
  NS_SCRIPTABLE NS_IMETHOD GetOutputStream(nsIObjectOutputStream * *aOutputStream) { return _to GetOutputStream(aOutputStream); } \
  NS_SCRIPTABLE NS_IMETHOD SetOutputStream(nsIObjectOutputStream * aOutputStream) { return _to SetOutputStream(aOutputStream); } \
  NS_SCRIPTABLE NS_IMETHOD GetFileIO(nsIFastLoadFileIO * *aFileIO) { return _to GetFileIO(aFileIO); } \
  NS_SCRIPTABLE NS_IMETHOD SetFileIO(nsIFastLoadFileIO * aFileIO) { return _to SetFileIO(aFileIO); } \
  NS_SCRIPTABLE NS_IMETHOD GetDirection(PRInt32 *aDirection) { return _to GetDirection(aDirection); } \
  NS_SCRIPTABLE NS_IMETHOD StartMuxedDocument(nsISupports *aURI, const char *aURISpec, PRInt32 aDirectionFlags) { return _to StartMuxedDocument(aURI, aURISpec, aDirectionFlags); } \
  NS_SCRIPTABLE NS_IMETHOD SelectMuxedDocument(nsISupports *aURI, nsISupports **_retval NS_OUTPARAM) { return _to SelectMuxedDocument(aURI, _retval); } \
  NS_SCRIPTABLE NS_IMETHOD EndMuxedDocument(nsISupports *aURI) { return _to EndMuxedDocument(aURI); } \
  NS_SCRIPTABLE NS_IMETHOD AddDependency(nsIFile *aFile) { return _to AddDependency(aFile); } \
  NS_SCRIPTABLE NS_IMETHOD ComputeChecksum(nsIFile *aFile, nsIFastLoadReadControl *aControl, PRUint32 *_retval NS_OUTPARAM) { return _to ComputeChecksum(aFile, aControl, _retval); } \
  NS_SCRIPTABLE NS_IMETHOD CacheChecksum(nsIFile *aFile, nsIObjectOutputStream *aStream) { return _to CacheChecksum(aFile, aStream); } \
  NS_IMETHOD GetFastLoadReferent(nsISupports **aPtr NS_INOUTPARAM) { return _to GetFastLoadReferent(aPtr); } \
  NS_IMETHOD ReadFastLoadPtr(nsIObjectInputStream *aInputStream, nsISupports **aPtr NS_INOUTPARAM) { return _to ReadFastLoadPtr(aInputStream, aPtr); } \
  NS_IMETHOD WriteFastLoadPtr(nsIObjectOutputStream *aOutputStream, nsISupports *aPtr) { return _to WriteFastLoadPtr(aOutputStream, aPtr); } \
  NS_SCRIPTABLE NS_IMETHOD HasMuxedDocument(const char *aURISpec, PRBool *_retval NS_OUTPARAM) { return _to HasMuxedDocument(aURISpec, _retval); } 

/* Use this macro to declare functions that forward the behavior of this interface to another object in a safe way. */
#define NS_FORWARD_SAFE_NSIFASTLOADSERVICE(_to) \
  NS_SCRIPTABLE NS_IMETHOD NewFastLoadFile(const char *aBaseName, nsIFile **_retval NS_OUTPARAM) { return !_to ? NS_ERROR_NULL_POINTER : _to->NewFastLoadFile(aBaseName, _retval); } \
  NS_SCRIPTABLE NS_IMETHOD NewInputStream(nsIInputStream *aSrcStream, nsIObjectInputStream **_retval NS_OUTPARAM) { return !_to ? NS_ERROR_NULL_POINTER : _to->NewInputStream(aSrcStream, _retval); } \
  NS_SCRIPTABLE NS_IMETHOD NewOutputStream(nsIOutputStream *aDestStream, nsIObjectOutputStream **_retval NS_OUTPARAM) { return !_to ? NS_ERROR_NULL_POINTER : _to->NewOutputStream(aDestStream, _retval); } \
  NS_SCRIPTABLE NS_IMETHOD GetInputStream(nsIObjectInputStream * *aInputStream) { return !_to ? NS_ERROR_NULL_POINTER : _to->GetInputStream(aInputStream); } \
  NS_SCRIPTABLE NS_IMETHOD SetInputStream(nsIObjectInputStream * aInputStream) { return !_to ? NS_ERROR_NULL_POINTER : _to->SetInputStream(aInputStream); } \
  NS_SCRIPTABLE NS_IMETHOD GetOutputStream(nsIObjectOutputStream * *aOutputStream) { return !_to ? NS_ERROR_NULL_POINTER : _to->GetOutputStream(aOutputStream); } \
  NS_SCRIPTABLE NS_IMETHOD SetOutputStream(nsIObjectOutputStream * aOutputStream) { return !_to ? NS_ERROR_NULL_POINTER : _to->SetOutputStream(aOutputStream); } \
  NS_SCRIPTABLE NS_IMETHOD GetFileIO(nsIFastLoadFileIO * *aFileIO) { return !_to ? NS_ERROR_NULL_POINTER : _to->GetFileIO(aFileIO); } \
  NS_SCRIPTABLE NS_IMETHOD SetFileIO(nsIFastLoadFileIO * aFileIO) { return !_to ? NS_ERROR_NULL_POINTER : _to->SetFileIO(aFileIO); } \
  NS_SCRIPTABLE NS_IMETHOD GetDirection(PRInt32 *aDirection) { return !_to ? NS_ERROR_NULL_POINTER : _to->GetDirection(aDirection); } \
  NS_SCRIPTABLE NS_IMETHOD StartMuxedDocument(nsISupports *aURI, const char *aURISpec, PRInt32 aDirectionFlags) { return !_to ? NS_ERROR_NULL_POINTER : _to->StartMuxedDocument(aURI, aURISpec, aDirectionFlags); } \
  NS_SCRIPTABLE NS_IMETHOD SelectMuxedDocument(nsISupports *aURI, nsISupports **_retval NS_OUTPARAM) { return !_to ? NS_ERROR_NULL_POINTER : _to->SelectMuxedDocument(aURI, _retval); } \
  NS_SCRIPTABLE NS_IMETHOD EndMuxedDocument(nsISupports *aURI) { return !_to ? NS_ERROR_NULL_POINTER : _to->EndMuxedDocument(aURI); } \
  NS_SCRIPTABLE NS_IMETHOD AddDependency(nsIFile *aFile) { return !_to ? NS_ERROR_NULL_POINTER : _to->AddDependency(aFile); } \
  NS_SCRIPTABLE NS_IMETHOD ComputeChecksum(nsIFile *aFile, nsIFastLoadReadControl *aControl, PRUint32 *_retval NS_OUTPARAM) { return !_to ? NS_ERROR_NULL_POINTER : _to->ComputeChecksum(aFile, aControl, _retval); } \
  NS_SCRIPTABLE NS_IMETHOD CacheChecksum(nsIFile *aFile, nsIObjectOutputStream *aStream) { return !_to ? NS_ERROR_NULL_POINTER : _to->CacheChecksum(aFile, aStream); } \
  NS_IMETHOD GetFastLoadReferent(nsISupports **aPtr NS_INOUTPARAM) { return !_to ? NS_ERROR_NULL_POINTER : _to->GetFastLoadReferent(aPtr); } \
  NS_IMETHOD ReadFastLoadPtr(nsIObjectInputStream *aInputStream, nsISupports **aPtr NS_INOUTPARAM) { return !_to ? NS_ERROR_NULL_POINTER : _to->ReadFastLoadPtr(aInputStream, aPtr); } \
  NS_IMETHOD WriteFastLoadPtr(nsIObjectOutputStream *aOutputStream, nsISupports *aPtr) { return !_to ? NS_ERROR_NULL_POINTER : _to->WriteFastLoadPtr(aOutputStream, aPtr); } \
  NS_SCRIPTABLE NS_IMETHOD HasMuxedDocument(const char *aURISpec, PRBool *_retval NS_OUTPARAM) { return !_to ? NS_ERROR_NULL_POINTER : _to->HasMuxedDocument(aURISpec, _retval); } 

#if 0
/* Use the code below as a template for the implementation class for this interface. */

/* Header file */
class nsFastLoadService : public nsIFastLoadService
{
public:
  NS_DECL_ISUPPORTS
  NS_DECL_NSIFASTLOADSERVICE

  nsFastLoadService();

private:
  ~nsFastLoadService();

protected:
  /* additional members */
};

/* Implementation file */
NS_IMPL_ISUPPORTS1(nsFastLoadService, nsIFastLoadService)

nsFastLoadService::nsFastLoadService()
{
  /* member initializers and constructor code */
}

nsFastLoadService::~nsFastLoadService()
{
  /* destructor code */
}

/* nsIFile newFastLoadFile (in string aBaseName); */
NS_IMETHODIMP nsFastLoadService::NewFastLoadFile(const char *aBaseName, nsIFile **_retval NS_OUTPARAM)
{
    return NS_ERROR_NOT_IMPLEMENTED;
}

/* nsIObjectInputStream newInputStream (in nsIInputStream aSrcStream); */
NS_IMETHODIMP nsFastLoadService::NewInputStream(nsIInputStream *aSrcStream, nsIObjectInputStream **_retval NS_OUTPARAM)
{
    return NS_ERROR_NOT_IMPLEMENTED;
}

/* nsIObjectOutputStream newOutputStream (in nsIOutputStream aDestStream); */
NS_IMETHODIMP nsFastLoadService::NewOutputStream(nsIOutputStream *aDestStream, nsIObjectOutputStream **_retval NS_OUTPARAM)
{
    return NS_ERROR_NOT_IMPLEMENTED;
}

/* attribute nsIObjectInputStream inputStream; */
NS_IMETHODIMP nsFastLoadService::GetInputStream(nsIObjectInputStream * *aInputStream)
{
    return NS_ERROR_NOT_IMPLEMENTED;
}
NS_IMETHODIMP nsFastLoadService::SetInputStream(nsIObjectInputStream * aInputStream)
{
    return NS_ERROR_NOT_IMPLEMENTED;
}

/* attribute nsIObjectOutputStream outputStream; */
NS_IMETHODIMP nsFastLoadService::GetOutputStream(nsIObjectOutputStream * *aOutputStream)
{
    return NS_ERROR_NOT_IMPLEMENTED;
}
NS_IMETHODIMP nsFastLoadService::SetOutputStream(nsIObjectOutputStream * aOutputStream)
{
    return NS_ERROR_NOT_IMPLEMENTED;
}

/* attribute nsIFastLoadFileIO fileIO; */
NS_IMETHODIMP nsFastLoadService::GetFileIO(nsIFastLoadFileIO * *aFileIO)
{
    return NS_ERROR_NOT_IMPLEMENTED;
}
NS_IMETHODIMP nsFastLoadService::SetFileIO(nsIFastLoadFileIO * aFileIO)
{
    return NS_ERROR_NOT_IMPLEMENTED;
}

/* readonly attribute PRInt32 direction; */
NS_IMETHODIMP nsFastLoadService::GetDirection(PRInt32 *aDirection)
{
    return NS_ERROR_NOT_IMPLEMENTED;
}

/* void startMuxedDocument (in nsISupports aURI, in string aURISpec, in PRInt32 aDirectionFlags); */
NS_IMETHODIMP nsFastLoadService::StartMuxedDocument(nsISupports *aURI, const char *aURISpec, PRInt32 aDirectionFlags)
{
    return NS_ERROR_NOT_IMPLEMENTED;
}

/* nsISupports selectMuxedDocument (in nsISupports aURI); */
NS_IMETHODIMP nsFastLoadService::SelectMuxedDocument(nsISupports *aURI, nsISupports **_retval NS_OUTPARAM)
{
    return NS_ERROR_NOT_IMPLEMENTED;
}

/* void endMuxedDocument (in nsISupports aURI); */
NS_IMETHODIMP nsFastLoadService::EndMuxedDocument(nsISupports *aURI)
{
    return NS_ERROR_NOT_IMPLEMENTED;
}

/* void addDependency (in nsIFile aFile); */
NS_IMETHODIMP nsFastLoadService::AddDependency(nsIFile *aFile)
{
    return NS_ERROR_NOT_IMPLEMENTED;
}

/* PRUint32 computeChecksum (in nsIFile aFile, in nsIFastLoadReadControl aControl); */
NS_IMETHODIMP nsFastLoadService::ComputeChecksum(nsIFile *aFile, nsIFastLoadReadControl *aControl, PRUint32 *_retval NS_OUTPARAM)
{
    return NS_ERROR_NOT_IMPLEMENTED;
}

/* void cacheChecksum (in nsIFile aFile, in nsIObjectOutputStream aStream); */
NS_IMETHODIMP nsFastLoadService::CacheChecksum(nsIFile *aFile, nsIObjectOutputStream *aStream)
{
    return NS_ERROR_NOT_IMPLEMENTED;
}

/* [noscript] void getFastLoadReferent (inout nsISupports aPtr); */
NS_IMETHODIMP nsFastLoadService::GetFastLoadReferent(nsISupports **aPtr NS_INOUTPARAM)
{
    return NS_ERROR_NOT_IMPLEMENTED;
}

/* [noscript] void readFastLoadPtr (in nsIObjectInputStream aInputStream, inout nsISupports aPtr); */
NS_IMETHODIMP nsFastLoadService::ReadFastLoadPtr(nsIObjectInputStream *aInputStream, nsISupports **aPtr NS_INOUTPARAM)
{
    return NS_ERROR_NOT_IMPLEMENTED;
}

/* [noscript] void writeFastLoadPtr (in nsIObjectOutputStream aOutputStream, in nsISupports aPtr); */
NS_IMETHODIMP nsFastLoadService::WriteFastLoadPtr(nsIObjectOutputStream *aOutputStream, nsISupports *aPtr)
{
    return NS_ERROR_NOT_IMPLEMENTED;
}

/* boolean hasMuxedDocument (in string aURISpec); */
NS_IMETHODIMP nsFastLoadService::HasMuxedDocument(const char *aURISpec, PRBool *_retval NS_OUTPARAM)
{
    return NS_ERROR_NOT_IMPLEMENTED;
}

/* End of implementation class template. */
#endif

#define NS_FASTLOADSERVICE_CLASSNAME "Mozilla FastLoad Service"
#define NS_FASTLOADSERVICE_CID \
    {0xc943093c,0xac94,0x4bee,{0x84,0x0b,0x8b,0x5a,0x6e,0x31,0x4f,0xa7}}
#define NS_FASTLOADSERVICE_CONTRACTID \
    "@mozilla.org/fast-load-service;1"
#ifndef nsCOMPtr_h___
# include "nsCOMPtr.h"
#endif
#ifndef __gen_nsIFile_h__
# include "nsIFile.h"
#endif
#ifndef nsIServiceManager_h___
# include "nsIServiceManager.h"
#endif
inline const nsGetServiceByContractID
do_GetFastLoadService()
{
    return nsGetServiceByContractID(NS_FASTLOADSERVICE_CONTRACTID);
}
inline const nsGetServiceByContractIDWithError
do_GetFastLoadService(nsresult *aResultCode)
{
    return nsGetServiceByContractIDWithError(NS_FASTLOADSERVICE_CONTRACTID,
                                             aResultCode);
}
inline nsresult
NS_AddFastLoadDependency(nsIFile* aFile)
{
    nsCOMPtr<nsIFastLoadService> fastLoadService(do_GetFastLoadService());
    if (fastLoadService) {
        nsresult rv = fastLoadService->AddDependency(aFile);
        if (NS_FAILED(rv) && rv != NS_ERROR_NOT_AVAILABLE)
            return rv;
    }
    return NS_OK;
}
#if defined(XP_UNIX) || defined(XP_BEOS)
#define PLATFORM_FASL_SUFFIX ".mfasl"
#elif defined(XP_WIN) || defined(XP_OS2)
#define PLATFORM_FASL_SUFFIX ".mfl"
#endif

#endif /* __gen_nsIFastLoadService_h__ */
