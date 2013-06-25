/*
 * DO NOT EDIT.  THIS FILE IS GENERATED FROM e:/builds/moz2_slave/mozilla-1.9.1-win32-xulrunner/build/docshell/base/nsIDocShellLoadInfo.idl
 */

#ifndef __gen_nsIDocShellLoadInfo_h__
#define __gen_nsIDocShellLoadInfo_h__


#ifndef __gen_nsISupports_h__
#include "nsISupports.h"
#endif

/* For IDL files that don't want to include root IDL files. */
#ifndef NS_NO_VTABLE
#define NS_NO_VTABLE
#endif
class nsIURI; /* forward declaration */

class nsIInputStream; /* forward declaration */

class nsISHEntry; /* forward declaration */

typedef PRInt32 nsDocShellInfoLoadType;


/* starting interface:    nsIDocShellLoadInfo */
#define NS_IDOCSHELLLOADINFO_IID_STR "92a0a637-373e-4647-9476-ead11e005c75"

#define NS_IDOCSHELLLOADINFO_IID \
  {0x92a0a637, 0x373e, 0x4647, \
    { 0x94, 0x76, 0xea, 0xd1, 0x1e, 0x00, 0x5c, 0x75 }}

class NS_NO_VTABLE NS_SCRIPTABLE nsIDocShellLoadInfo : public nsISupports {
 public: 

  NS_DECLARE_STATIC_IID_ACCESSOR(NS_IDOCSHELLLOADINFO_IID)

  /** This is the referrer for the load. */
  /* attribute nsIURI referrer; */
  NS_SCRIPTABLE NS_IMETHOD GetReferrer(nsIURI * *aReferrer) = 0;
  NS_SCRIPTABLE NS_IMETHOD SetReferrer(nsIURI * aReferrer) = 0;

  /** The owner of the load, that is, the entity responsible for 
     *  causing the load to occur. This should be a nsIPrincipal typically.
     */
  /* attribute nsISupports owner; */
  NS_SCRIPTABLE NS_IMETHOD GetOwner(nsISupports * *aOwner) = 0;
  NS_SCRIPTABLE NS_IMETHOD SetOwner(nsISupports * aOwner) = 0;

  /** If this attribute is true and no owner is specified, copy
     *  the owner from the referring document.
     */
  /* attribute boolean inheritOwner; */
  NS_SCRIPTABLE NS_IMETHOD GetInheritOwner(PRBool *aInheritOwner) = 0;
  NS_SCRIPTABLE NS_IMETHOD SetInheritOwner(PRBool aInheritOwner) = 0;

  /** If this attribute is true only ever use the owner specify by
     *  the owner and inheritOwner attributes.
     *  If there are security reasons for why this is unsafe, such
     *  as trying to use a systemprincipal owner for a content docshell
     *  the load fails.
     */
  /* attribute boolean ownerIsExplicit; */
  NS_SCRIPTABLE NS_IMETHOD GetOwnerIsExplicit(PRBool *aOwnerIsExplicit) = 0;
  NS_SCRIPTABLE NS_IMETHOD SetOwnerIsExplicit(PRBool aOwnerIsExplicit) = 0;

  enum { loadNormal = 0 };

  enum { loadNormalReplace = 1 };

  enum { loadHistory = 2 };

  enum { loadReloadNormal = 3 };

  enum { loadReloadBypassCache = 4 };

  enum { loadReloadBypassProxy = 5 };

  enum { loadReloadBypassProxyAndCache = 6 };

  enum { loadLink = 7 };

  enum { loadRefresh = 8 };

  enum { loadReloadCharsetChange = 9 };

  enum { loadBypassHistory = 10 };

  enum { loadStopContent = 11 };

  enum { loadStopContentAndReplace = 12 };

  enum { loadNormalExternal = 13 };

  enum { loadNormalBypassCache = 14 };

  enum { loadNormalBypassProxy = 15 };

  enum { loadNormalBypassProxyAndCache = 16 };

  /** Contains a load type as specified by the load* constants */
  /* attribute nsDocShellInfoLoadType loadType; */
  NS_SCRIPTABLE NS_IMETHOD GetLoadType(nsDocShellInfoLoadType *aLoadType) = 0;
  NS_SCRIPTABLE NS_IMETHOD SetLoadType(nsDocShellInfoLoadType aLoadType) = 0;

  /** SHEntry for this page */
  /* attribute nsISHEntry SHEntry; */
  NS_SCRIPTABLE NS_IMETHOD GetSHEntry(nsISHEntry * *aSHEntry) = 0;
  NS_SCRIPTABLE NS_IMETHOD SetSHEntry(nsISHEntry * aSHEntry) = 0;

  /** Target for load, like _content, _blank etc. */
  /* attribute wstring target; */
  NS_SCRIPTABLE NS_IMETHOD GetTarget(PRUnichar * *aTarget) = 0;
  NS_SCRIPTABLE NS_IMETHOD SetTarget(const PRUnichar * aTarget) = 0;

  /** Post data */
  /* attribute nsIInputStream postDataStream; */
  NS_SCRIPTABLE NS_IMETHOD GetPostDataStream(nsIInputStream * *aPostDataStream) = 0;
  NS_SCRIPTABLE NS_IMETHOD SetPostDataStream(nsIInputStream * aPostDataStream) = 0;

  /** Additional headers */
  /* attribute nsIInputStream headersStream; */
  NS_SCRIPTABLE NS_IMETHOD GetHeadersStream(nsIInputStream * *aHeadersStream) = 0;
  NS_SCRIPTABLE NS_IMETHOD SetHeadersStream(nsIInputStream * aHeadersStream) = 0;

  /** True if the referrer should be sent, false if it shouldn't be
     *  sent, even if it's available. This attribute defaults to true.
     */
  /* attribute boolean sendReferrer; */
  NS_SCRIPTABLE NS_IMETHOD GetSendReferrer(PRBool *aSendReferrer) = 0;
  NS_SCRIPTABLE NS_IMETHOD SetSendReferrer(PRBool aSendReferrer) = 0;

};

  NS_DEFINE_STATIC_IID_ACCESSOR(nsIDocShellLoadInfo, NS_IDOCSHELLLOADINFO_IID)

/* Use this macro when declaring classes that implement this interface. */
#define NS_DECL_NSIDOCSHELLLOADINFO \
  NS_SCRIPTABLE NS_IMETHOD GetReferrer(nsIURI * *aReferrer); \
  NS_SCRIPTABLE NS_IMETHOD SetReferrer(nsIURI * aReferrer); \
  NS_SCRIPTABLE NS_IMETHOD GetOwner(nsISupports * *aOwner); \
  NS_SCRIPTABLE NS_IMETHOD SetOwner(nsISupports * aOwner); \
  NS_SCRIPTABLE NS_IMETHOD GetInheritOwner(PRBool *aInheritOwner); \
  NS_SCRIPTABLE NS_IMETHOD SetInheritOwner(PRBool aInheritOwner); \
  NS_SCRIPTABLE NS_IMETHOD GetOwnerIsExplicit(PRBool *aOwnerIsExplicit); \
  NS_SCRIPTABLE NS_IMETHOD SetOwnerIsExplicit(PRBool aOwnerIsExplicit); \
  NS_SCRIPTABLE NS_IMETHOD GetLoadType(nsDocShellInfoLoadType *aLoadType); \
  NS_SCRIPTABLE NS_IMETHOD SetLoadType(nsDocShellInfoLoadType aLoadType); \
  NS_SCRIPTABLE NS_IMETHOD GetSHEntry(nsISHEntry * *aSHEntry); \
  NS_SCRIPTABLE NS_IMETHOD SetSHEntry(nsISHEntry * aSHEntry); \
  NS_SCRIPTABLE NS_IMETHOD GetTarget(PRUnichar * *aTarget); \
  NS_SCRIPTABLE NS_IMETHOD SetTarget(const PRUnichar * aTarget); \
  NS_SCRIPTABLE NS_IMETHOD GetPostDataStream(nsIInputStream * *aPostDataStream); \
  NS_SCRIPTABLE NS_IMETHOD SetPostDataStream(nsIInputStream * aPostDataStream); \
  NS_SCRIPTABLE NS_IMETHOD GetHeadersStream(nsIInputStream * *aHeadersStream); \
  NS_SCRIPTABLE NS_IMETHOD SetHeadersStream(nsIInputStream * aHeadersStream); \
  NS_SCRIPTABLE NS_IMETHOD GetSendReferrer(PRBool *aSendReferrer); \
  NS_SCRIPTABLE NS_IMETHOD SetSendReferrer(PRBool aSendReferrer); 

/* Use this macro to declare functions that forward the behavior of this interface to another object. */
#define NS_FORWARD_NSIDOCSHELLLOADINFO(_to) \
  NS_SCRIPTABLE NS_IMETHOD GetReferrer(nsIURI * *aReferrer) { return _to GetReferrer(aReferrer); } \
  NS_SCRIPTABLE NS_IMETHOD SetReferrer(nsIURI * aReferrer) { return _to SetReferrer(aReferrer); } \
  NS_SCRIPTABLE NS_IMETHOD GetOwner(nsISupports * *aOwner) { return _to GetOwner(aOwner); } \
  NS_SCRIPTABLE NS_IMETHOD SetOwner(nsISupports * aOwner) { return _to SetOwner(aOwner); } \
  NS_SCRIPTABLE NS_IMETHOD GetInheritOwner(PRBool *aInheritOwner) { return _to GetInheritOwner(aInheritOwner); } \
  NS_SCRIPTABLE NS_IMETHOD SetInheritOwner(PRBool aInheritOwner) { return _to SetInheritOwner(aInheritOwner); } \
  NS_SCRIPTABLE NS_IMETHOD GetOwnerIsExplicit(PRBool *aOwnerIsExplicit) { return _to GetOwnerIsExplicit(aOwnerIsExplicit); } \
  NS_SCRIPTABLE NS_IMETHOD SetOwnerIsExplicit(PRBool aOwnerIsExplicit) { return _to SetOwnerIsExplicit(aOwnerIsExplicit); } \
  NS_SCRIPTABLE NS_IMETHOD GetLoadType(nsDocShellInfoLoadType *aLoadType) { return _to GetLoadType(aLoadType); } \
  NS_SCRIPTABLE NS_IMETHOD SetLoadType(nsDocShellInfoLoadType aLoadType) { return _to SetLoadType(aLoadType); } \
  NS_SCRIPTABLE NS_IMETHOD GetSHEntry(nsISHEntry * *aSHEntry) { return _to GetSHEntry(aSHEntry); } \
  NS_SCRIPTABLE NS_IMETHOD SetSHEntry(nsISHEntry * aSHEntry) { return _to SetSHEntry(aSHEntry); } \
  NS_SCRIPTABLE NS_IMETHOD GetTarget(PRUnichar * *aTarget) { return _to GetTarget(aTarget); } \
  NS_SCRIPTABLE NS_IMETHOD SetTarget(const PRUnichar * aTarget) { return _to SetTarget(aTarget); } \
  NS_SCRIPTABLE NS_IMETHOD GetPostDataStream(nsIInputStream * *aPostDataStream) { return _to GetPostDataStream(aPostDataStream); } \
  NS_SCRIPTABLE NS_IMETHOD SetPostDataStream(nsIInputStream * aPostDataStream) { return _to SetPostDataStream(aPostDataStream); } \
  NS_SCRIPTABLE NS_IMETHOD GetHeadersStream(nsIInputStream * *aHeadersStream) { return _to GetHeadersStream(aHeadersStream); } \
  NS_SCRIPTABLE NS_IMETHOD SetHeadersStream(nsIInputStream * aHeadersStream) { return _to SetHeadersStream(aHeadersStream); } \
  NS_SCRIPTABLE NS_IMETHOD GetSendReferrer(PRBool *aSendReferrer) { return _to GetSendReferrer(aSendReferrer); } \
  NS_SCRIPTABLE NS_IMETHOD SetSendReferrer(PRBool aSendReferrer) { return _to SetSendReferrer(aSendReferrer); } 

/* Use this macro to declare functions that forward the behavior of this interface to another object in a safe way. */
#define NS_FORWARD_SAFE_NSIDOCSHELLLOADINFO(_to) \
  NS_SCRIPTABLE NS_IMETHOD GetReferrer(nsIURI * *aReferrer) { return !_to ? NS_ERROR_NULL_POINTER : _to->GetReferrer(aReferrer); } \
  NS_SCRIPTABLE NS_IMETHOD SetReferrer(nsIURI * aReferrer) { return !_to ? NS_ERROR_NULL_POINTER : _to->SetReferrer(aReferrer); } \
  NS_SCRIPTABLE NS_IMETHOD GetOwner(nsISupports * *aOwner) { return !_to ? NS_ERROR_NULL_POINTER : _to->GetOwner(aOwner); } \
  NS_SCRIPTABLE NS_IMETHOD SetOwner(nsISupports * aOwner) { return !_to ? NS_ERROR_NULL_POINTER : _to->SetOwner(aOwner); } \
  NS_SCRIPTABLE NS_IMETHOD GetInheritOwner(PRBool *aInheritOwner) { return !_to ? NS_ERROR_NULL_POINTER : _to->GetInheritOwner(aInheritOwner); } \
  NS_SCRIPTABLE NS_IMETHOD SetInheritOwner(PRBool aInheritOwner) { return !_to ? NS_ERROR_NULL_POINTER : _to->SetInheritOwner(aInheritOwner); } \
  NS_SCRIPTABLE NS_IMETHOD GetOwnerIsExplicit(PRBool *aOwnerIsExplicit) { return !_to ? NS_ERROR_NULL_POINTER : _to->GetOwnerIsExplicit(aOwnerIsExplicit); } \
  NS_SCRIPTABLE NS_IMETHOD SetOwnerIsExplicit(PRBool aOwnerIsExplicit) { return !_to ? NS_ERROR_NULL_POINTER : _to->SetOwnerIsExplicit(aOwnerIsExplicit); } \
  NS_SCRIPTABLE NS_IMETHOD GetLoadType(nsDocShellInfoLoadType *aLoadType) { return !_to ? NS_ERROR_NULL_POINTER : _to->GetLoadType(aLoadType); } \
  NS_SCRIPTABLE NS_IMETHOD SetLoadType(nsDocShellInfoLoadType aLoadType) { return !_to ? NS_ERROR_NULL_POINTER : _to->SetLoadType(aLoadType); } \
  NS_SCRIPTABLE NS_IMETHOD GetSHEntry(nsISHEntry * *aSHEntry) { return !_to ? NS_ERROR_NULL_POINTER : _to->GetSHEntry(aSHEntry); } \
  NS_SCRIPTABLE NS_IMETHOD SetSHEntry(nsISHEntry * aSHEntry) { return !_to ? NS_ERROR_NULL_POINTER : _to->SetSHEntry(aSHEntry); } \
  NS_SCRIPTABLE NS_IMETHOD GetTarget(PRUnichar * *aTarget) { return !_to ? NS_ERROR_NULL_POINTER : _to->GetTarget(aTarget); } \
  NS_SCRIPTABLE NS_IMETHOD SetTarget(const PRUnichar * aTarget) { return !_to ? NS_ERROR_NULL_POINTER : _to->SetTarget(aTarget); } \
  NS_SCRIPTABLE NS_IMETHOD GetPostDataStream(nsIInputStream * *aPostDataStream) { return !_to ? NS_ERROR_NULL_POINTER : _to->GetPostDataStream(aPostDataStream); } \
  NS_SCRIPTABLE NS_IMETHOD SetPostDataStream(nsIInputStream * aPostDataStream) { return !_to ? NS_ERROR_NULL_POINTER : _to->SetPostDataStream(aPostDataStream); } \
  NS_SCRIPTABLE NS_IMETHOD GetHeadersStream(nsIInputStream * *aHeadersStream) { return !_to ? NS_ERROR_NULL_POINTER : _to->GetHeadersStream(aHeadersStream); } \
  NS_SCRIPTABLE NS_IMETHOD SetHeadersStream(nsIInputStream * aHeadersStream) { return !_to ? NS_ERROR_NULL_POINTER : _to->SetHeadersStream(aHeadersStream); } \
  NS_SCRIPTABLE NS_IMETHOD GetSendReferrer(PRBool *aSendReferrer) { return !_to ? NS_ERROR_NULL_POINTER : _to->GetSendReferrer(aSendReferrer); } \
  NS_SCRIPTABLE NS_IMETHOD SetSendReferrer(PRBool aSendReferrer) { return !_to ? NS_ERROR_NULL_POINTER : _to->SetSendReferrer(aSendReferrer); } 

#if 0
/* Use the code below as a template for the implementation class for this interface. */

/* Header file */
class nsDocShellLoadInfo : public nsIDocShellLoadInfo
{
public:
  NS_DECL_ISUPPORTS
  NS_DECL_NSIDOCSHELLLOADINFO

  nsDocShellLoadInfo();

private:
  ~nsDocShellLoadInfo();

protected:
  /* additional members */
};

/* Implementation file */
NS_IMPL_ISUPPORTS1(nsDocShellLoadInfo, nsIDocShellLoadInfo)

nsDocShellLoadInfo::nsDocShellLoadInfo()
{
  /* member initializers and constructor code */
}

nsDocShellLoadInfo::~nsDocShellLoadInfo()
{
  /* destructor code */
}

/* attribute nsIURI referrer; */
NS_IMETHODIMP nsDocShellLoadInfo::GetReferrer(nsIURI * *aReferrer)
{
    return NS_ERROR_NOT_IMPLEMENTED;
}
NS_IMETHODIMP nsDocShellLoadInfo::SetReferrer(nsIURI * aReferrer)
{
    return NS_ERROR_NOT_IMPLEMENTED;
}

/* attribute nsISupports owner; */
NS_IMETHODIMP nsDocShellLoadInfo::GetOwner(nsISupports * *aOwner)
{
    return NS_ERROR_NOT_IMPLEMENTED;
}
NS_IMETHODIMP nsDocShellLoadInfo::SetOwner(nsISupports * aOwner)
{
    return NS_ERROR_NOT_IMPLEMENTED;
}

/* attribute boolean inheritOwner; */
NS_IMETHODIMP nsDocShellLoadInfo::GetInheritOwner(PRBool *aInheritOwner)
{
    return NS_ERROR_NOT_IMPLEMENTED;
}
NS_IMETHODIMP nsDocShellLoadInfo::SetInheritOwner(PRBool aInheritOwner)
{
    return NS_ERROR_NOT_IMPLEMENTED;
}

/* attribute boolean ownerIsExplicit; */
NS_IMETHODIMP nsDocShellLoadInfo::GetOwnerIsExplicit(PRBool *aOwnerIsExplicit)
{
    return NS_ERROR_NOT_IMPLEMENTED;
}
NS_IMETHODIMP nsDocShellLoadInfo::SetOwnerIsExplicit(PRBool aOwnerIsExplicit)
{
    return NS_ERROR_NOT_IMPLEMENTED;
}

/* attribute nsDocShellInfoLoadType loadType; */
NS_IMETHODIMP nsDocShellLoadInfo::GetLoadType(nsDocShellInfoLoadType *aLoadType)
{
    return NS_ERROR_NOT_IMPLEMENTED;
}
NS_IMETHODIMP nsDocShellLoadInfo::SetLoadType(nsDocShellInfoLoadType aLoadType)
{
    return NS_ERROR_NOT_IMPLEMENTED;
}

/* attribute nsISHEntry SHEntry; */
NS_IMETHODIMP nsDocShellLoadInfo::GetSHEntry(nsISHEntry * *aSHEntry)
{
    return NS_ERROR_NOT_IMPLEMENTED;
}
NS_IMETHODIMP nsDocShellLoadInfo::SetSHEntry(nsISHEntry * aSHEntry)
{
    return NS_ERROR_NOT_IMPLEMENTED;
}

/* attribute wstring target; */
NS_IMETHODIMP nsDocShellLoadInfo::GetTarget(PRUnichar * *aTarget)
{
    return NS_ERROR_NOT_IMPLEMENTED;
}
NS_IMETHODIMP nsDocShellLoadInfo::SetTarget(const PRUnichar * aTarget)
{
    return NS_ERROR_NOT_IMPLEMENTED;
}

/* attribute nsIInputStream postDataStream; */
NS_IMETHODIMP nsDocShellLoadInfo::GetPostDataStream(nsIInputStream * *aPostDataStream)
{
    return NS_ERROR_NOT_IMPLEMENTED;
}
NS_IMETHODIMP nsDocShellLoadInfo::SetPostDataStream(nsIInputStream * aPostDataStream)
{
    return NS_ERROR_NOT_IMPLEMENTED;
}

/* attribute nsIInputStream headersStream; */
NS_IMETHODIMP nsDocShellLoadInfo::GetHeadersStream(nsIInputStream * *aHeadersStream)
{
    return NS_ERROR_NOT_IMPLEMENTED;
}
NS_IMETHODIMP nsDocShellLoadInfo::SetHeadersStream(nsIInputStream * aHeadersStream)
{
    return NS_ERROR_NOT_IMPLEMENTED;
}

/* attribute boolean sendReferrer; */
NS_IMETHODIMP nsDocShellLoadInfo::GetSendReferrer(PRBool *aSendReferrer)
{
    return NS_ERROR_NOT_IMPLEMENTED;
}
NS_IMETHODIMP nsDocShellLoadInfo::SetSendReferrer(PRBool aSendReferrer)
{
    return NS_ERROR_NOT_IMPLEMENTED;
}

/* End of implementation class template. */
#endif


#endif /* __gen_nsIDocShellLoadInfo_h__ */
