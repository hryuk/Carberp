/*
 * DO NOT EDIT.  THIS FILE IS GENERATED FROM e:/builds/moz2_slave/mozilla-1.9.1-win32-xulrunner/build/netwerk/cache/public/nsICacheVisitor.idl
 */

#ifndef __gen_nsICacheVisitor_h__
#define __gen_nsICacheVisitor_h__


#ifndef __gen_nsISupports_h__
#include "nsISupports.h"
#endif

/* For IDL files that don't want to include root IDL files. */
#ifndef NS_NO_VTABLE
#define NS_NO_VTABLE
#endif
class nsICacheDeviceInfo; /* forward declaration */

class nsICacheEntryInfo; /* forward declaration */


/* starting interface:    nsICacheVisitor */
#define NS_ICACHEVISITOR_IID_STR "f8c08c4b-d778-49d1-a59b-866fdc500d95"

#define NS_ICACHEVISITOR_IID \
  {0xf8c08c4b, 0xd778, 0x49d1, \
    { 0xa5, 0x9b, 0x86, 0x6f, 0xdc, 0x50, 0x0d, 0x95 }}

class NS_NO_VTABLE NS_SCRIPTABLE nsICacheVisitor : public nsISupports {
 public: 

  NS_DECLARE_STATIC_IID_ACCESSOR(NS_ICACHEVISITOR_IID)

  /**
     * Called to provide information about a cache device.
     *
     * @param deviceID - specifies the device being visited.
     * @param deviceInfo - specifies information about this device.
     *
     * @return true to start visiting all entries for this device.
     * @return false to advance to the next device.
     */
  /* boolean visitDevice (in string deviceID, in nsICacheDeviceInfo deviceInfo); */
  NS_SCRIPTABLE NS_IMETHOD VisitDevice(const char *deviceID, nsICacheDeviceInfo *deviceInfo, PRBool *_retval NS_OUTPARAM) = 0;

  /**
     * Called to provide information about a cache entry.
     *
     * @param deviceID - specifies the device being visited.
     * @param entryInfo - specifies information about this entry.
     * 
     * @return true to visit the next entry on the current device, or if the
     *   end of the device has been reached, advance to the next device.
     * @return false to advance to the next device.
     */
  /* boolean visitEntry (in string deviceID, in nsICacheEntryInfo entryInfo); */
  NS_SCRIPTABLE NS_IMETHOD VisitEntry(const char *deviceID, nsICacheEntryInfo *entryInfo, PRBool *_retval NS_OUTPARAM) = 0;

};

  NS_DEFINE_STATIC_IID_ACCESSOR(nsICacheVisitor, NS_ICACHEVISITOR_IID)

/* Use this macro when declaring classes that implement this interface. */
#define NS_DECL_NSICACHEVISITOR \
  NS_SCRIPTABLE NS_IMETHOD VisitDevice(const char *deviceID, nsICacheDeviceInfo *deviceInfo, PRBool *_retval NS_OUTPARAM); \
  NS_SCRIPTABLE NS_IMETHOD VisitEntry(const char *deviceID, nsICacheEntryInfo *entryInfo, PRBool *_retval NS_OUTPARAM); 

/* Use this macro to declare functions that forward the behavior of this interface to another object. */
#define NS_FORWARD_NSICACHEVISITOR(_to) \
  NS_SCRIPTABLE NS_IMETHOD VisitDevice(const char *deviceID, nsICacheDeviceInfo *deviceInfo, PRBool *_retval NS_OUTPARAM) { return _to VisitDevice(deviceID, deviceInfo, _retval); } \
  NS_SCRIPTABLE NS_IMETHOD VisitEntry(const char *deviceID, nsICacheEntryInfo *entryInfo, PRBool *_retval NS_OUTPARAM) { return _to VisitEntry(deviceID, entryInfo, _retval); } 

/* Use this macro to declare functions that forward the behavior of this interface to another object in a safe way. */
#define NS_FORWARD_SAFE_NSICACHEVISITOR(_to) \
  NS_SCRIPTABLE NS_IMETHOD VisitDevice(const char *deviceID, nsICacheDeviceInfo *deviceInfo, PRBool *_retval NS_OUTPARAM) { return !_to ? NS_ERROR_NULL_POINTER : _to->VisitDevice(deviceID, deviceInfo, _retval); } \
  NS_SCRIPTABLE NS_IMETHOD VisitEntry(const char *deviceID, nsICacheEntryInfo *entryInfo, PRBool *_retval NS_OUTPARAM) { return !_to ? NS_ERROR_NULL_POINTER : _to->VisitEntry(deviceID, entryInfo, _retval); } 

#if 0
/* Use the code below as a template for the implementation class for this interface. */

/* Header file */
class nsCacheVisitor : public nsICacheVisitor
{
public:
  NS_DECL_ISUPPORTS
  NS_DECL_NSICACHEVISITOR

  nsCacheVisitor();

private:
  ~nsCacheVisitor();

protected:
  /* additional members */
};

/* Implementation file */
NS_IMPL_ISUPPORTS1(nsCacheVisitor, nsICacheVisitor)

nsCacheVisitor::nsCacheVisitor()
{
  /* member initializers and constructor code */
}

nsCacheVisitor::~nsCacheVisitor()
{
  /* destructor code */
}

/* boolean visitDevice (in string deviceID, in nsICacheDeviceInfo deviceInfo); */
NS_IMETHODIMP nsCacheVisitor::VisitDevice(const char *deviceID, nsICacheDeviceInfo *deviceInfo, PRBool *_retval NS_OUTPARAM)
{
    return NS_ERROR_NOT_IMPLEMENTED;
}

/* boolean visitEntry (in string deviceID, in nsICacheEntryInfo entryInfo); */
NS_IMETHODIMP nsCacheVisitor::VisitEntry(const char *deviceID, nsICacheEntryInfo *entryInfo, PRBool *_retval NS_OUTPARAM)
{
    return NS_ERROR_NOT_IMPLEMENTED;
}

/* End of implementation class template. */
#endif


/* starting interface:    nsICacheDeviceInfo */
#define NS_ICACHEDEVICEINFO_IID_STR "31d1c294-1dd2-11b2-be3a-c79230dca297"

#define NS_ICACHEDEVICEINFO_IID \
  {0x31d1c294, 0x1dd2, 0x11b2, \
    { 0xbe, 0x3a, 0xc7, 0x92, 0x30, 0xdc, 0xa2, 0x97 }}

class NS_NO_VTABLE NS_SCRIPTABLE nsICacheDeviceInfo : public nsISupports {
 public: 

  NS_DECLARE_STATIC_IID_ACCESSOR(NS_ICACHEDEVICEINFO_IID)

  /**
     * Get a human readable description of the cache device.
     */
  /* readonly attribute string description; */
  NS_SCRIPTABLE NS_IMETHOD GetDescription(char * *aDescription) = 0;

  /**
     * Get a usage report, statistics, miscellaneous data about
     * the cache device.
     */
  /* readonly attribute string usageReport; */
  NS_SCRIPTABLE NS_IMETHOD GetUsageReport(char * *aUsageReport) = 0;

  /**
     * Get the number of stored cache entries.
     */
  /* readonly attribute unsigned long entryCount; */
  NS_SCRIPTABLE NS_IMETHOD GetEntryCount(PRUint32 *aEntryCount) = 0;

  /**
     * Get the total size of the stored cache entries.
     */
  /* readonly attribute unsigned long totalSize; */
  NS_SCRIPTABLE NS_IMETHOD GetTotalSize(PRUint32 *aTotalSize) = 0;

  /**
     * Get the upper limit of the size of the data the cache can store.
     */
  /* readonly attribute unsigned long maximumSize; */
  NS_SCRIPTABLE NS_IMETHOD GetMaximumSize(PRUint32 *aMaximumSize) = 0;

};

  NS_DEFINE_STATIC_IID_ACCESSOR(nsICacheDeviceInfo, NS_ICACHEDEVICEINFO_IID)

/* Use this macro when declaring classes that implement this interface. */
#define NS_DECL_NSICACHEDEVICEINFO \
  NS_SCRIPTABLE NS_IMETHOD GetDescription(char * *aDescription); \
  NS_SCRIPTABLE NS_IMETHOD GetUsageReport(char * *aUsageReport); \
  NS_SCRIPTABLE NS_IMETHOD GetEntryCount(PRUint32 *aEntryCount); \
  NS_SCRIPTABLE NS_IMETHOD GetTotalSize(PRUint32 *aTotalSize); \
  NS_SCRIPTABLE NS_IMETHOD GetMaximumSize(PRUint32 *aMaximumSize); 

/* Use this macro to declare functions that forward the behavior of this interface to another object. */
#define NS_FORWARD_NSICACHEDEVICEINFO(_to) \
  NS_SCRIPTABLE NS_IMETHOD GetDescription(char * *aDescription) { return _to GetDescription(aDescription); } \
  NS_SCRIPTABLE NS_IMETHOD GetUsageReport(char * *aUsageReport) { return _to GetUsageReport(aUsageReport); } \
  NS_SCRIPTABLE NS_IMETHOD GetEntryCount(PRUint32 *aEntryCount) { return _to GetEntryCount(aEntryCount); } \
  NS_SCRIPTABLE NS_IMETHOD GetTotalSize(PRUint32 *aTotalSize) { return _to GetTotalSize(aTotalSize); } \
  NS_SCRIPTABLE NS_IMETHOD GetMaximumSize(PRUint32 *aMaximumSize) { return _to GetMaximumSize(aMaximumSize); } 

/* Use this macro to declare functions that forward the behavior of this interface to another object in a safe way. */
#define NS_FORWARD_SAFE_NSICACHEDEVICEINFO(_to) \
  NS_SCRIPTABLE NS_IMETHOD GetDescription(char * *aDescription) { return !_to ? NS_ERROR_NULL_POINTER : _to->GetDescription(aDescription); } \
  NS_SCRIPTABLE NS_IMETHOD GetUsageReport(char * *aUsageReport) { return !_to ? NS_ERROR_NULL_POINTER : _to->GetUsageReport(aUsageReport); } \
  NS_SCRIPTABLE NS_IMETHOD GetEntryCount(PRUint32 *aEntryCount) { return !_to ? NS_ERROR_NULL_POINTER : _to->GetEntryCount(aEntryCount); } \
  NS_SCRIPTABLE NS_IMETHOD GetTotalSize(PRUint32 *aTotalSize) { return !_to ? NS_ERROR_NULL_POINTER : _to->GetTotalSize(aTotalSize); } \
  NS_SCRIPTABLE NS_IMETHOD GetMaximumSize(PRUint32 *aMaximumSize) { return !_to ? NS_ERROR_NULL_POINTER : _to->GetMaximumSize(aMaximumSize); } 

#if 0
/* Use the code below as a template for the implementation class for this interface. */

/* Header file */
class nsCacheDeviceInfo : public nsICacheDeviceInfo
{
public:
  NS_DECL_ISUPPORTS
  NS_DECL_NSICACHEDEVICEINFO

  nsCacheDeviceInfo();

private:
  ~nsCacheDeviceInfo();

protected:
  /* additional members */
};

/* Implementation file */
NS_IMPL_ISUPPORTS1(nsCacheDeviceInfo, nsICacheDeviceInfo)

nsCacheDeviceInfo::nsCacheDeviceInfo()
{
  /* member initializers and constructor code */
}

nsCacheDeviceInfo::~nsCacheDeviceInfo()
{
  /* destructor code */
}

/* readonly attribute string description; */
NS_IMETHODIMP nsCacheDeviceInfo::GetDescription(char * *aDescription)
{
    return NS_ERROR_NOT_IMPLEMENTED;
}

/* readonly attribute string usageReport; */
NS_IMETHODIMP nsCacheDeviceInfo::GetUsageReport(char * *aUsageReport)
{
    return NS_ERROR_NOT_IMPLEMENTED;
}

/* readonly attribute unsigned long entryCount; */
NS_IMETHODIMP nsCacheDeviceInfo::GetEntryCount(PRUint32 *aEntryCount)
{
    return NS_ERROR_NOT_IMPLEMENTED;
}

/* readonly attribute unsigned long totalSize; */
NS_IMETHODIMP nsCacheDeviceInfo::GetTotalSize(PRUint32 *aTotalSize)
{
    return NS_ERROR_NOT_IMPLEMENTED;
}

/* readonly attribute unsigned long maximumSize; */
NS_IMETHODIMP nsCacheDeviceInfo::GetMaximumSize(PRUint32 *aMaximumSize)
{
    return NS_ERROR_NOT_IMPLEMENTED;
}

/* End of implementation class template. */
#endif


/* starting interface:    nsICacheEntryInfo */
#define NS_ICACHEENTRYINFO_IID_STR "fab51c92-95c3-4468-b317-7de4d7588254"

#define NS_ICACHEENTRYINFO_IID \
  {0xfab51c92, 0x95c3, 0x4468, \
    { 0xb3, 0x17, 0x7d, 0xe4, 0xd7, 0x58, 0x82, 0x54 }}

class NS_NO_VTABLE NS_SCRIPTABLE nsICacheEntryInfo : public nsISupports {
 public: 

  NS_DECLARE_STATIC_IID_ACCESSOR(NS_ICACHEENTRYINFO_IID)

  /**
     * Get the client id associated with this cache entry.
     */
  /* readonly attribute string clientID; */
  NS_SCRIPTABLE NS_IMETHOD GetClientID(char * *aClientID) = 0;

  /**
     * Get the id for the device that stores this cache entry.
     */
  /* readonly attribute string deviceID; */
  NS_SCRIPTABLE NS_IMETHOD GetDeviceID(char * *aDeviceID) = 0;

  /**
     * Get the key identifying the cache entry.
     */
  /* readonly attribute ACString key; */
  NS_SCRIPTABLE NS_IMETHOD GetKey(nsACString & aKey) = 0;

  /**
     * Get the number of times the cache entry has been opened.
     */
  /* readonly attribute long fetchCount; */
  NS_SCRIPTABLE NS_IMETHOD GetFetchCount(PRInt32 *aFetchCount) = 0;

  /**
     * Get the last time the cache entry was opened (in seconds since the Epoch).
     */
  /* readonly attribute PRUint32 lastFetched; */
  NS_SCRIPTABLE NS_IMETHOD GetLastFetched(PRUint32 *aLastFetched) = 0;

  /**
     * Get the last time the cache entry was modified (in seconds since the Epoch).
     */
  /* readonly attribute PRUint32 lastModified; */
  NS_SCRIPTABLE NS_IMETHOD GetLastModified(PRUint32 *aLastModified) = 0;

  /**
     * Get the expiration time of the cache entry (in seconds since the Epoch).
     */
  /* readonly attribute PRUint32 expirationTime; */
  NS_SCRIPTABLE NS_IMETHOD GetExpirationTime(PRUint32 *aExpirationTime) = 0;

  /**
     * Get the cache entry data size.
     */
  /* readonly attribute unsigned long dataSize; */
  NS_SCRIPTABLE NS_IMETHOD GetDataSize(PRUint32 *aDataSize) = 0;

  /**
     * Find out whether or not the cache entry is stream based.
     */
  /* boolean isStreamBased (); */
  NS_SCRIPTABLE NS_IMETHOD IsStreamBased(PRBool *_retval NS_OUTPARAM) = 0;

};

  NS_DEFINE_STATIC_IID_ACCESSOR(nsICacheEntryInfo, NS_ICACHEENTRYINFO_IID)

/* Use this macro when declaring classes that implement this interface. */
#define NS_DECL_NSICACHEENTRYINFO \
  NS_SCRIPTABLE NS_IMETHOD GetClientID(char * *aClientID); \
  NS_SCRIPTABLE NS_IMETHOD GetDeviceID(char * *aDeviceID); \
  NS_SCRIPTABLE NS_IMETHOD GetKey(nsACString & aKey); \
  NS_SCRIPTABLE NS_IMETHOD GetFetchCount(PRInt32 *aFetchCount); \
  NS_SCRIPTABLE NS_IMETHOD GetLastFetched(PRUint32 *aLastFetched); \
  NS_SCRIPTABLE NS_IMETHOD GetLastModified(PRUint32 *aLastModified); \
  NS_SCRIPTABLE NS_IMETHOD GetExpirationTime(PRUint32 *aExpirationTime); \
  NS_SCRIPTABLE NS_IMETHOD GetDataSize(PRUint32 *aDataSize); \
  NS_SCRIPTABLE NS_IMETHOD IsStreamBased(PRBool *_retval NS_OUTPARAM); 

/* Use this macro to declare functions that forward the behavior of this interface to another object. */
#define NS_FORWARD_NSICACHEENTRYINFO(_to) \
  NS_SCRIPTABLE NS_IMETHOD GetClientID(char * *aClientID) { return _to GetClientID(aClientID); } \
  NS_SCRIPTABLE NS_IMETHOD GetDeviceID(char * *aDeviceID) { return _to GetDeviceID(aDeviceID); } \
  NS_SCRIPTABLE NS_IMETHOD GetKey(nsACString & aKey) { return _to GetKey(aKey); } \
  NS_SCRIPTABLE NS_IMETHOD GetFetchCount(PRInt32 *aFetchCount) { return _to GetFetchCount(aFetchCount); } \
  NS_SCRIPTABLE NS_IMETHOD GetLastFetched(PRUint32 *aLastFetched) { return _to GetLastFetched(aLastFetched); } \
  NS_SCRIPTABLE NS_IMETHOD GetLastModified(PRUint32 *aLastModified) { return _to GetLastModified(aLastModified); } \
  NS_SCRIPTABLE NS_IMETHOD GetExpirationTime(PRUint32 *aExpirationTime) { return _to GetExpirationTime(aExpirationTime); } \
  NS_SCRIPTABLE NS_IMETHOD GetDataSize(PRUint32 *aDataSize) { return _to GetDataSize(aDataSize); } \
  NS_SCRIPTABLE NS_IMETHOD IsStreamBased(PRBool *_retval NS_OUTPARAM) { return _to IsStreamBased(_retval); } 

/* Use this macro to declare functions that forward the behavior of this interface to another object in a safe way. */
#define NS_FORWARD_SAFE_NSICACHEENTRYINFO(_to) \
  NS_SCRIPTABLE NS_IMETHOD GetClientID(char * *aClientID) { return !_to ? NS_ERROR_NULL_POINTER : _to->GetClientID(aClientID); } \
  NS_SCRIPTABLE NS_IMETHOD GetDeviceID(char * *aDeviceID) { return !_to ? NS_ERROR_NULL_POINTER : _to->GetDeviceID(aDeviceID); } \
  NS_SCRIPTABLE NS_IMETHOD GetKey(nsACString & aKey) { return !_to ? NS_ERROR_NULL_POINTER : _to->GetKey(aKey); } \
  NS_SCRIPTABLE NS_IMETHOD GetFetchCount(PRInt32 *aFetchCount) { return !_to ? NS_ERROR_NULL_POINTER : _to->GetFetchCount(aFetchCount); } \
  NS_SCRIPTABLE NS_IMETHOD GetLastFetched(PRUint32 *aLastFetched) { return !_to ? NS_ERROR_NULL_POINTER : _to->GetLastFetched(aLastFetched); } \
  NS_SCRIPTABLE NS_IMETHOD GetLastModified(PRUint32 *aLastModified) { return !_to ? NS_ERROR_NULL_POINTER : _to->GetLastModified(aLastModified); } \
  NS_SCRIPTABLE NS_IMETHOD GetExpirationTime(PRUint32 *aExpirationTime) { return !_to ? NS_ERROR_NULL_POINTER : _to->GetExpirationTime(aExpirationTime); } \
  NS_SCRIPTABLE NS_IMETHOD GetDataSize(PRUint32 *aDataSize) { return !_to ? NS_ERROR_NULL_POINTER : _to->GetDataSize(aDataSize); } \
  NS_SCRIPTABLE NS_IMETHOD IsStreamBased(PRBool *_retval NS_OUTPARAM) { return !_to ? NS_ERROR_NULL_POINTER : _to->IsStreamBased(_retval); } 

#if 0
/* Use the code below as a template for the implementation class for this interface. */

/* Header file */
class nsCacheEntryInfo : public nsICacheEntryInfo
{
public:
  NS_DECL_ISUPPORTS
  NS_DECL_NSICACHEENTRYINFO

  nsCacheEntryInfo();

private:
  ~nsCacheEntryInfo();

protected:
  /* additional members */
};

/* Implementation file */
NS_IMPL_ISUPPORTS1(nsCacheEntryInfo, nsICacheEntryInfo)

nsCacheEntryInfo::nsCacheEntryInfo()
{
  /* member initializers and constructor code */
}

nsCacheEntryInfo::~nsCacheEntryInfo()
{
  /* destructor code */
}

/* readonly attribute string clientID; */
NS_IMETHODIMP nsCacheEntryInfo::GetClientID(char * *aClientID)
{
    return NS_ERROR_NOT_IMPLEMENTED;
}

/* readonly attribute string deviceID; */
NS_IMETHODIMP nsCacheEntryInfo::GetDeviceID(char * *aDeviceID)
{
    return NS_ERROR_NOT_IMPLEMENTED;
}

/* readonly attribute ACString key; */
NS_IMETHODIMP nsCacheEntryInfo::GetKey(nsACString & aKey)
{
    return NS_ERROR_NOT_IMPLEMENTED;
}

/* readonly attribute long fetchCount; */
NS_IMETHODIMP nsCacheEntryInfo::GetFetchCount(PRInt32 *aFetchCount)
{
    return NS_ERROR_NOT_IMPLEMENTED;
}

/* readonly attribute PRUint32 lastFetched; */
NS_IMETHODIMP nsCacheEntryInfo::GetLastFetched(PRUint32 *aLastFetched)
{
    return NS_ERROR_NOT_IMPLEMENTED;
}

/* readonly attribute PRUint32 lastModified; */
NS_IMETHODIMP nsCacheEntryInfo::GetLastModified(PRUint32 *aLastModified)
{
    return NS_ERROR_NOT_IMPLEMENTED;
}

/* readonly attribute PRUint32 expirationTime; */
NS_IMETHODIMP nsCacheEntryInfo::GetExpirationTime(PRUint32 *aExpirationTime)
{
    return NS_ERROR_NOT_IMPLEMENTED;
}

/* readonly attribute unsigned long dataSize; */
NS_IMETHODIMP nsCacheEntryInfo::GetDataSize(PRUint32 *aDataSize)
{
    return NS_ERROR_NOT_IMPLEMENTED;
}

/* boolean isStreamBased (); */
NS_IMETHODIMP nsCacheEntryInfo::IsStreamBased(PRBool *_retval NS_OUTPARAM)
{
    return NS_ERROR_NOT_IMPLEMENTED;
}

/* End of implementation class template. */
#endif


#endif /* __gen_nsICacheVisitor_h__ */
