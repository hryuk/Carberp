/*
 * DO NOT EDIT.  THIS FILE IS GENERATED FROM e:/builds/moz2_slave/mozilla-1.9.1-win32-xulrunner/build/xpcom/io/nsIFastLoadFileControl.idl
 */

#ifndef __gen_nsIFastLoadFileControl_h__
#define __gen_nsIFastLoadFileControl_h__


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
class nsIFile; /* forward declaration */

class nsISimpleEnumerator; /* forward declaration */


/* starting interface:    nsIFastLoadFileControl */
#define NS_IFASTLOADFILECONTROL_IID_STR "8a1e2c63-af50-4147-af7e-26289dc180dd"

#define NS_IFASTLOADFILECONTROL_IID \
  {0x8a1e2c63, 0xaf50, 0x4147, \
    { 0xaf, 0x7e, 0x26, 0x28, 0x9d, 0xc1, 0x80, 0xdd }}

/**
 * The nsIFastLoadFileControl interface and its subinterfaces are mix-ins for
 * classes implementing nsIObjectInputStream and nsIObjectOutputStream, so that
 * those stream types can be used with nsIFastLoadService to access and compute
 * FastLoad file checksums, update and check FastLoad file dependencies, and
 * multiplex documents loaded via non-blocking i/o.
 *
 * If an nsIObjectInputStream class doesn't support nsIFastLoadReadControl, or
 * an nsIObjectOutputStream class doesn't support nsIFastLoadWriteControl, that
 * implementation may still be useful for object serialization, but it can't be
 * used to read or write a Mozilla FastLoad file.
 */
class NS_NO_VTABLE NS_SCRIPTABLE nsIFastLoadFileControl : public nsISupports {
 public: 

  NS_DECLARE_STATIC_IID_ACCESSOR(NS_IFASTLOADFILECONTROL_IID)

  /**
     * Get and set the recorded checksum value from the FastLoad file header.
     */
  /* attribute PRUint32 checksum; */
  NS_SCRIPTABLE NS_IMETHOD GetChecksum(PRUint32 *aChecksum) = 0;
  NS_SCRIPTABLE NS_IMETHOD SetChecksum(PRUint32 aChecksum) = 0;

  /**
     * Multiplexed document control methods.  A FastLoad file may contain
     * multiple interleaved documents identified by a URI specifier string,
     * and indexed for fast multiplexor select by an opaque URI object key.
     * You StartMuxedDocument when initiating a document load, then Select
     * before every batch of calls to (de)serialize document data, and End
     * when the load completes.
     *
     * Document multiplexing is necessary to support incremental FastLoad
     * development in a non-blocking i/o architecture such as Mozilla, where
     * some (but not all, at first, or for a while during development) of the
     * results of parsing and compiling various inputs can be multiplexed to
     * or from a FastLoad file.
     *
     * Note: Select returns the previously selected URI object in case the
     * caller is synchronously selecting and writing data to the FastLoad
     * file, so the caller can reselect the previous URI and return to code
     * the continues to write FastLoad data for the previous URI, unaware of
     * the nested select/write/reselect.
     */
  /* void startMuxedDocument (in nsISupports aURI, in string aURISpec); */
  NS_SCRIPTABLE NS_IMETHOD StartMuxedDocument(nsISupports *aURI, const char *aURISpec) = 0;

  /* nsISupports selectMuxedDocument (in nsISupports aURI); */
  NS_SCRIPTABLE NS_IMETHOD SelectMuxedDocument(nsISupports *aURI, nsISupports **_retval NS_OUTPARAM) = 0;

  /* void endMuxedDocument (in nsISupports aURI); */
  NS_SCRIPTABLE NS_IMETHOD EndMuxedDocument(nsISupports *aURI) = 0;

  /**
     * Return true if aURISpec identifies a muxed document in the FastLoad
     * file, false otherwise.
     */
  /* boolean hasMuxedDocument (in string aURISpec); */
  NS_SCRIPTABLE NS_IMETHOD HasMuxedDocument(const char *aURISpec, PRBool *_retval NS_OUTPARAM) = 0;

};

  NS_DEFINE_STATIC_IID_ACCESSOR(nsIFastLoadFileControl, NS_IFASTLOADFILECONTROL_IID)

/* Use this macro when declaring classes that implement this interface. */
#define NS_DECL_NSIFASTLOADFILECONTROL \
  NS_SCRIPTABLE NS_IMETHOD GetChecksum(PRUint32 *aChecksum); \
  NS_SCRIPTABLE NS_IMETHOD SetChecksum(PRUint32 aChecksum); \
  NS_SCRIPTABLE NS_IMETHOD StartMuxedDocument(nsISupports *aURI, const char *aURISpec); \
  NS_SCRIPTABLE NS_IMETHOD SelectMuxedDocument(nsISupports *aURI, nsISupports **_retval NS_OUTPARAM); \
  NS_SCRIPTABLE NS_IMETHOD EndMuxedDocument(nsISupports *aURI); \
  NS_SCRIPTABLE NS_IMETHOD HasMuxedDocument(const char *aURISpec, PRBool *_retval NS_OUTPARAM); 

/* Use this macro to declare functions that forward the behavior of this interface to another object. */
#define NS_FORWARD_NSIFASTLOADFILECONTROL(_to) \
  NS_SCRIPTABLE NS_IMETHOD GetChecksum(PRUint32 *aChecksum) { return _to GetChecksum(aChecksum); } \
  NS_SCRIPTABLE NS_IMETHOD SetChecksum(PRUint32 aChecksum) { return _to SetChecksum(aChecksum); } \
  NS_SCRIPTABLE NS_IMETHOD StartMuxedDocument(nsISupports *aURI, const char *aURISpec) { return _to StartMuxedDocument(aURI, aURISpec); } \
  NS_SCRIPTABLE NS_IMETHOD SelectMuxedDocument(nsISupports *aURI, nsISupports **_retval NS_OUTPARAM) { return _to SelectMuxedDocument(aURI, _retval); } \
  NS_SCRIPTABLE NS_IMETHOD EndMuxedDocument(nsISupports *aURI) { return _to EndMuxedDocument(aURI); } \
  NS_SCRIPTABLE NS_IMETHOD HasMuxedDocument(const char *aURISpec, PRBool *_retval NS_OUTPARAM) { return _to HasMuxedDocument(aURISpec, _retval); } 

/* Use this macro to declare functions that forward the behavior of this interface to another object in a safe way. */
#define NS_FORWARD_SAFE_NSIFASTLOADFILECONTROL(_to) \
  NS_SCRIPTABLE NS_IMETHOD GetChecksum(PRUint32 *aChecksum) { return !_to ? NS_ERROR_NULL_POINTER : _to->GetChecksum(aChecksum); } \
  NS_SCRIPTABLE NS_IMETHOD SetChecksum(PRUint32 aChecksum) { return !_to ? NS_ERROR_NULL_POINTER : _to->SetChecksum(aChecksum); } \
  NS_SCRIPTABLE NS_IMETHOD StartMuxedDocument(nsISupports *aURI, const char *aURISpec) { return !_to ? NS_ERROR_NULL_POINTER : _to->StartMuxedDocument(aURI, aURISpec); } \
  NS_SCRIPTABLE NS_IMETHOD SelectMuxedDocument(nsISupports *aURI, nsISupports **_retval NS_OUTPARAM) { return !_to ? NS_ERROR_NULL_POINTER : _to->SelectMuxedDocument(aURI, _retval); } \
  NS_SCRIPTABLE NS_IMETHOD EndMuxedDocument(nsISupports *aURI) { return !_to ? NS_ERROR_NULL_POINTER : _to->EndMuxedDocument(aURI); } \
  NS_SCRIPTABLE NS_IMETHOD HasMuxedDocument(const char *aURISpec, PRBool *_retval NS_OUTPARAM) { return !_to ? NS_ERROR_NULL_POINTER : _to->HasMuxedDocument(aURISpec, _retval); } 

#if 0
/* Use the code below as a template for the implementation class for this interface. */

/* Header file */
class nsFastLoadFileControl : public nsIFastLoadFileControl
{
public:
  NS_DECL_ISUPPORTS
  NS_DECL_NSIFASTLOADFILECONTROL

  nsFastLoadFileControl();

private:
  ~nsFastLoadFileControl();

protected:
  /* additional members */
};

/* Implementation file */
NS_IMPL_ISUPPORTS1(nsFastLoadFileControl, nsIFastLoadFileControl)

nsFastLoadFileControl::nsFastLoadFileControl()
{
  /* member initializers and constructor code */
}

nsFastLoadFileControl::~nsFastLoadFileControl()
{
  /* destructor code */
}

/* attribute PRUint32 checksum; */
NS_IMETHODIMP nsFastLoadFileControl::GetChecksum(PRUint32 *aChecksum)
{
    return NS_ERROR_NOT_IMPLEMENTED;
}
NS_IMETHODIMP nsFastLoadFileControl::SetChecksum(PRUint32 aChecksum)
{
    return NS_ERROR_NOT_IMPLEMENTED;
}

/* void startMuxedDocument (in nsISupports aURI, in string aURISpec); */
NS_IMETHODIMP nsFastLoadFileControl::StartMuxedDocument(nsISupports *aURI, const char *aURISpec)
{
    return NS_ERROR_NOT_IMPLEMENTED;
}

/* nsISupports selectMuxedDocument (in nsISupports aURI); */
NS_IMETHODIMP nsFastLoadFileControl::SelectMuxedDocument(nsISupports *aURI, nsISupports **_retval NS_OUTPARAM)
{
    return NS_ERROR_NOT_IMPLEMENTED;
}

/* void endMuxedDocument (in nsISupports aURI); */
NS_IMETHODIMP nsFastLoadFileControl::EndMuxedDocument(nsISupports *aURI)
{
    return NS_ERROR_NOT_IMPLEMENTED;
}

/* boolean hasMuxedDocument (in string aURISpec); */
NS_IMETHODIMP nsFastLoadFileControl::HasMuxedDocument(const char *aURISpec, PRBool *_retval NS_OUTPARAM)
{
    return NS_ERROR_NOT_IMPLEMENTED;
}

/* End of implementation class template. */
#endif


/* starting interface:    nsIFastLoadReadControl */
#define NS_IFASTLOADREADCONTROL_IID_STR "652ecec6-d40b-45b6-afef-641d6c63a35b"

#define NS_IFASTLOADREADCONTROL_IID \
  {0x652ecec6, 0xd40b, 0x45b6, \
    { 0xaf, 0xef, 0x64, 0x1d, 0x6c, 0x63, 0xa3, 0x5b }}

class NS_NO_VTABLE NS_SCRIPTABLE nsIFastLoadReadControl : public nsIFastLoadFileControl {
 public: 

  NS_DECLARE_STATIC_IID_ACCESSOR(NS_IFASTLOADREADCONTROL_IID)

  /**
     * Computes the correct checksum of the FastLoad file, independent of the
     * header's checksum value.  The header checksum field is treated as zero
     * when computing the checksum.
     */
  /* PRUint32 computeChecksum (); */
  NS_SCRIPTABLE NS_IMETHOD ComputeChecksum(PRUint32 *_retval NS_OUTPARAM) = 0;

  /**
     * Get the collection of dependency nsIFile instances recorded during the
     * FastLoad file write or read/update process, and checked during the read
     * process to invalidate the FastLoad file if any dependencies are newer.
     */
  /* readonly attribute nsISimpleEnumerator dependencies; */
  NS_SCRIPTABLE NS_IMETHOD GetDependencies(nsISimpleEnumerator * *aDependencies) = 0;

};

  NS_DEFINE_STATIC_IID_ACCESSOR(nsIFastLoadReadControl, NS_IFASTLOADREADCONTROL_IID)

/* Use this macro when declaring classes that implement this interface. */
#define NS_DECL_NSIFASTLOADREADCONTROL \
  NS_SCRIPTABLE NS_IMETHOD ComputeChecksum(PRUint32 *_retval NS_OUTPARAM); \
  NS_SCRIPTABLE NS_IMETHOD GetDependencies(nsISimpleEnumerator * *aDependencies); 

/* Use this macro to declare functions that forward the behavior of this interface to another object. */
#define NS_FORWARD_NSIFASTLOADREADCONTROL(_to) \
  NS_SCRIPTABLE NS_IMETHOD ComputeChecksum(PRUint32 *_retval NS_OUTPARAM) { return _to ComputeChecksum(_retval); } \
  NS_SCRIPTABLE NS_IMETHOD GetDependencies(nsISimpleEnumerator * *aDependencies) { return _to GetDependencies(aDependencies); } 

/* Use this macro to declare functions that forward the behavior of this interface to another object in a safe way. */
#define NS_FORWARD_SAFE_NSIFASTLOADREADCONTROL(_to) \
  NS_SCRIPTABLE NS_IMETHOD ComputeChecksum(PRUint32 *_retval NS_OUTPARAM) { return !_to ? NS_ERROR_NULL_POINTER : _to->ComputeChecksum(_retval); } \
  NS_SCRIPTABLE NS_IMETHOD GetDependencies(nsISimpleEnumerator * *aDependencies) { return !_to ? NS_ERROR_NULL_POINTER : _to->GetDependencies(aDependencies); } 

#if 0
/* Use the code below as a template for the implementation class for this interface. */

/* Header file */
class nsFastLoadReadControl : public nsIFastLoadReadControl
{
public:
  NS_DECL_ISUPPORTS
  NS_DECL_NSIFASTLOADREADCONTROL

  nsFastLoadReadControl();

private:
  ~nsFastLoadReadControl();

protected:
  /* additional members */
};

/* Implementation file */
NS_IMPL_ISUPPORTS1(nsFastLoadReadControl, nsIFastLoadReadControl)

nsFastLoadReadControl::nsFastLoadReadControl()
{
  /* member initializers and constructor code */
}

nsFastLoadReadControl::~nsFastLoadReadControl()
{
  /* destructor code */
}

/* PRUint32 computeChecksum (); */
NS_IMETHODIMP nsFastLoadReadControl::ComputeChecksum(PRUint32 *_retval NS_OUTPARAM)
{
    return NS_ERROR_NOT_IMPLEMENTED;
}

/* readonly attribute nsISimpleEnumerator dependencies; */
NS_IMETHODIMP nsFastLoadReadControl::GetDependencies(nsISimpleEnumerator * *aDependencies)
{
    return NS_ERROR_NOT_IMPLEMENTED;
}

/* End of implementation class template. */
#endif


/* starting interface:    nsIFastLoadWriteControl */
#define NS_IFASTLOADWRITECONTROL_IID_STR "2ad6e9e6-1379-4e45-a899-a54b27ff915c"

#define NS_IFASTLOADWRITECONTROL_IID \
  {0x2ad6e9e6, 0x1379, 0x4e45, \
    { 0xa8, 0x99, 0xa5, 0x4b, 0x27, 0xff, 0x91, 0x5c }}

class NS_NO_VTABLE NS_SCRIPTABLE nsIFastLoadWriteControl : public nsIFastLoadFileControl {
 public: 

  NS_DECLARE_STATIC_IID_ACCESSOR(NS_IFASTLOADWRITECONTROL_IID)

  /**
     * Add a file dependency of the FastLoad file (e.g., a .jar file) to the
     * set of dependencies that trigger regeneration if any dependency has a
     * last-modified-time greater than the FastLoad file's mtime.
     */
  /* void addDependency (in nsIFile aFile); */
  NS_SCRIPTABLE NS_IMETHOD AddDependency(nsIFile *aFile) = 0;

};

  NS_DEFINE_STATIC_IID_ACCESSOR(nsIFastLoadWriteControl, NS_IFASTLOADWRITECONTROL_IID)

/* Use this macro when declaring classes that implement this interface. */
#define NS_DECL_NSIFASTLOADWRITECONTROL \
  NS_SCRIPTABLE NS_IMETHOD AddDependency(nsIFile *aFile); 

/* Use this macro to declare functions that forward the behavior of this interface to another object. */
#define NS_FORWARD_NSIFASTLOADWRITECONTROL(_to) \
  NS_SCRIPTABLE NS_IMETHOD AddDependency(nsIFile *aFile) { return _to AddDependency(aFile); } 

/* Use this macro to declare functions that forward the behavior of this interface to another object in a safe way. */
#define NS_FORWARD_SAFE_NSIFASTLOADWRITECONTROL(_to) \
  NS_SCRIPTABLE NS_IMETHOD AddDependency(nsIFile *aFile) { return !_to ? NS_ERROR_NULL_POINTER : _to->AddDependency(aFile); } 

#if 0
/* Use the code below as a template for the implementation class for this interface. */

/* Header file */
class nsFastLoadWriteControl : public nsIFastLoadWriteControl
{
public:
  NS_DECL_ISUPPORTS
  NS_DECL_NSIFASTLOADWRITECONTROL

  nsFastLoadWriteControl();

private:
  ~nsFastLoadWriteControl();

protected:
  /* additional members */
};

/* Implementation file */
NS_IMPL_ISUPPORTS1(nsFastLoadWriteControl, nsIFastLoadWriteControl)

nsFastLoadWriteControl::nsFastLoadWriteControl()
{
  /* member initializers and constructor code */
}

nsFastLoadWriteControl::~nsFastLoadWriteControl()
{
  /* destructor code */
}

/* void addDependency (in nsIFile aFile); */
NS_IMETHODIMP nsFastLoadWriteControl::AddDependency(nsIFile *aFile)
{
    return NS_ERROR_NOT_IMPLEMENTED;
}

/* End of implementation class template. */
#endif


#endif /* __gen_nsIFastLoadFileControl_h__ */
