/*
 * DO NOT EDIT.  THIS FILE IS GENERATED FROM e:/builds/moz2_slave/mozilla-1.9.1-win32-xulrunner/build/netwerk/mime/public/nsIMIMEService.idl
 */

#ifndef __gen_nsIMIMEService_h__
#define __gen_nsIMIMEService_h__


#ifndef __gen_nsISupports_h__
#include "nsISupports.h"
#endif

#ifndef __gen_nsIMIMEInfo_h__
#include "nsIMIMEInfo.h"
#endif

#ifndef __gen_nsIURI_h__
#include "nsIURI.h"
#endif

#ifndef __gen_nsIFile_h__
#include "nsIFile.h"
#endif

/* For IDL files that don't want to include root IDL files. */
#ifndef NS_NO_VTABLE
#define NS_NO_VTABLE
#endif
#define NS_MIMESERVICE_CID                           \
{ /* 03af31da-3109-11d3-8cd0-0060b0fc14a3 */         \
    0x03af31da,                                      \
    0x3109,                                          \
    0x11d3,                                          \
    {0x8c, 0xd0, 0x00, 0x60, 0xb0, 0xfc, 0x14, 0xa3} \
}

/* starting interface:    nsIMIMEService */
#define NS_IMIMESERVICE_IID_STR "5b3675a1-02db-4f8f-a560-b34736635f47"

#define NS_IMIMESERVICE_IID \
  {0x5b3675a1, 0x02db, 0x4f8f, \
    { 0xa5, 0x60, 0xb3, 0x47, 0x36, 0x63, 0x5f, 0x47 }}

/**
 * The MIME service is responsible for mapping file extensions to MIME-types
 * (see RFC 2045). It also provides access to nsIMIMEInfo interfaces and
 * acts as a general convenience wrapper of nsIMIMEInfo interfaces.
 *
 * The MIME service maintains a database with a <b>one</b> MIME type <b>to many</b>
 * file extensions rule. Adding the same file extension to multiple MIME types
 * is illegal and behavior is undefined.
 *
 * @see nsIMIMEInfo
 */
class NS_NO_VTABLE NS_SCRIPTABLE nsIMIMEService : public nsISupports {
 public: 

  NS_DECLARE_STATIC_IID_ACCESSOR(NS_IMIMESERVICE_IID)

  /**
     * Retrieves an nsIMIMEInfo using both the extension
     * and the type of a file. The type is given preference
     * during the lookup. One of aMIMEType and aFileExt
     * can be an empty string. At least one of aMIMEType and aFileExt
     * must be nonempty.
     */
  /* nsIMIMEInfo getFromTypeAndExtension (in ACString aMIMEType, in AUTF8String aFileExt); */
  NS_SCRIPTABLE NS_IMETHOD GetFromTypeAndExtension(const nsACString & aMIMEType, const nsACString & aFileExt, nsIMIMEInfo **_retval NS_OUTPARAM) = 0;

  /**
     * Retrieves a ACString representation of the MIME type
     * associated with this file extension.
     *
     * @param  A file extension (excluding the dot ('.')).
     * @return The MIME type, if any.
     */
  /* ACString getTypeFromExtension (in AUTF8String aFileExt); */
  NS_SCRIPTABLE NS_IMETHOD GetTypeFromExtension(const nsACString & aFileExt, nsACString & _retval NS_OUTPARAM) = 0;

  /**
     * Retrieves a ACString representation of the MIME type
     * associated with this URI. The association is purely
     * file extension to MIME type based. No attempt to determine
     * the type via server headers or byte scanning is made.
     *
     * @param  The URI the user wants MIME info on.
     * @return The MIME type, if any.
     */
  /* ACString getTypeFromURI (in nsIURI aURI); */
  NS_SCRIPTABLE NS_IMETHOD GetTypeFromURI(nsIURI *aURI, nsACString & _retval NS_OUTPARAM) = 0;

  /* ACString getTypeFromFile (in nsIFile aFile); */
  NS_SCRIPTABLE NS_IMETHOD GetTypeFromFile(nsIFile *aFile, nsACString & _retval NS_OUTPARAM) = 0;

  /**
     * Given a Type/Extension combination, returns the default extension
     * for this type. This may be identical to the passed-in extension.
     *
     * @param aMIMEType The Type to get information on. Must not be empty.
     * @param aFileExt  File Extension. Can be empty.
     */
  /* AUTF8String getPrimaryExtension (in ACString aMIMEType, in AUTF8String aFileExt); */
  NS_SCRIPTABLE NS_IMETHOD GetPrimaryExtension(const nsACString & aMIMEType, const nsACString & aFileExt, nsACString & _retval NS_OUTPARAM) = 0;

};

  NS_DEFINE_STATIC_IID_ACCESSOR(nsIMIMEService, NS_IMIMESERVICE_IID)

/* Use this macro when declaring classes that implement this interface. */
#define NS_DECL_NSIMIMESERVICE \
  NS_SCRIPTABLE NS_IMETHOD GetFromTypeAndExtension(const nsACString & aMIMEType, const nsACString & aFileExt, nsIMIMEInfo **_retval NS_OUTPARAM); \
  NS_SCRIPTABLE NS_IMETHOD GetTypeFromExtension(const nsACString & aFileExt, nsACString & _retval NS_OUTPARAM); \
  NS_SCRIPTABLE NS_IMETHOD GetTypeFromURI(nsIURI *aURI, nsACString & _retval NS_OUTPARAM); \
  NS_SCRIPTABLE NS_IMETHOD GetTypeFromFile(nsIFile *aFile, nsACString & _retval NS_OUTPARAM); \
  NS_SCRIPTABLE NS_IMETHOD GetPrimaryExtension(const nsACString & aMIMEType, const nsACString & aFileExt, nsACString & _retval NS_OUTPARAM); 

/* Use this macro to declare functions that forward the behavior of this interface to another object. */
#define NS_FORWARD_NSIMIMESERVICE(_to) \
  NS_SCRIPTABLE NS_IMETHOD GetFromTypeAndExtension(const nsACString & aMIMEType, const nsACString & aFileExt, nsIMIMEInfo **_retval NS_OUTPARAM) { return _to GetFromTypeAndExtension(aMIMEType, aFileExt, _retval); } \
  NS_SCRIPTABLE NS_IMETHOD GetTypeFromExtension(const nsACString & aFileExt, nsACString & _retval NS_OUTPARAM) { return _to GetTypeFromExtension(aFileExt, _retval); } \
  NS_SCRIPTABLE NS_IMETHOD GetTypeFromURI(nsIURI *aURI, nsACString & _retval NS_OUTPARAM) { return _to GetTypeFromURI(aURI, _retval); } \
  NS_SCRIPTABLE NS_IMETHOD GetTypeFromFile(nsIFile *aFile, nsACString & _retval NS_OUTPARAM) { return _to GetTypeFromFile(aFile, _retval); } \
  NS_SCRIPTABLE NS_IMETHOD GetPrimaryExtension(const nsACString & aMIMEType, const nsACString & aFileExt, nsACString & _retval NS_OUTPARAM) { return _to GetPrimaryExtension(aMIMEType, aFileExt, _retval); } 

/* Use this macro to declare functions that forward the behavior of this interface to another object in a safe way. */
#define NS_FORWARD_SAFE_NSIMIMESERVICE(_to) \
  NS_SCRIPTABLE NS_IMETHOD GetFromTypeAndExtension(const nsACString & aMIMEType, const nsACString & aFileExt, nsIMIMEInfo **_retval NS_OUTPARAM) { return !_to ? NS_ERROR_NULL_POINTER : _to->GetFromTypeAndExtension(aMIMEType, aFileExt, _retval); } \
  NS_SCRIPTABLE NS_IMETHOD GetTypeFromExtension(const nsACString & aFileExt, nsACString & _retval NS_OUTPARAM) { return !_to ? NS_ERROR_NULL_POINTER : _to->GetTypeFromExtension(aFileExt, _retval); } \
  NS_SCRIPTABLE NS_IMETHOD GetTypeFromURI(nsIURI *aURI, nsACString & _retval NS_OUTPARAM) { return !_to ? NS_ERROR_NULL_POINTER : _to->GetTypeFromURI(aURI, _retval); } \
  NS_SCRIPTABLE NS_IMETHOD GetTypeFromFile(nsIFile *aFile, nsACString & _retval NS_OUTPARAM) { return !_to ? NS_ERROR_NULL_POINTER : _to->GetTypeFromFile(aFile, _retval); } \
  NS_SCRIPTABLE NS_IMETHOD GetPrimaryExtension(const nsACString & aMIMEType, const nsACString & aFileExt, nsACString & _retval NS_OUTPARAM) { return !_to ? NS_ERROR_NULL_POINTER : _to->GetPrimaryExtension(aMIMEType, aFileExt, _retval); } 

#if 0
/* Use the code below as a template for the implementation class for this interface. */

/* Header file */
class nsMIMEService : public nsIMIMEService
{
public:
  NS_DECL_ISUPPORTS
  NS_DECL_NSIMIMESERVICE

  nsMIMEService();

private:
  ~nsMIMEService();

protected:
  /* additional members */
};

/* Implementation file */
NS_IMPL_ISUPPORTS1(nsMIMEService, nsIMIMEService)

nsMIMEService::nsMIMEService()
{
  /* member initializers and constructor code */
}

nsMIMEService::~nsMIMEService()
{
  /* destructor code */
}

/* nsIMIMEInfo getFromTypeAndExtension (in ACString aMIMEType, in AUTF8String aFileExt); */
NS_IMETHODIMP nsMIMEService::GetFromTypeAndExtension(const nsACString & aMIMEType, const nsACString & aFileExt, nsIMIMEInfo **_retval NS_OUTPARAM)
{
    return NS_ERROR_NOT_IMPLEMENTED;
}

/* ACString getTypeFromExtension (in AUTF8String aFileExt); */
NS_IMETHODIMP nsMIMEService::GetTypeFromExtension(const nsACString & aFileExt, nsACString & _retval NS_OUTPARAM)
{
    return NS_ERROR_NOT_IMPLEMENTED;
}

/* ACString getTypeFromURI (in nsIURI aURI); */
NS_IMETHODIMP nsMIMEService::GetTypeFromURI(nsIURI *aURI, nsACString & _retval NS_OUTPARAM)
{
    return NS_ERROR_NOT_IMPLEMENTED;
}

/* ACString getTypeFromFile (in nsIFile aFile); */
NS_IMETHODIMP nsMIMEService::GetTypeFromFile(nsIFile *aFile, nsACString & _retval NS_OUTPARAM)
{
    return NS_ERROR_NOT_IMPLEMENTED;
}

/* AUTF8String getPrimaryExtension (in ACString aMIMEType, in AUTF8String aFileExt); */
NS_IMETHODIMP nsMIMEService::GetPrimaryExtension(const nsACString & aMIMEType, const nsACString & aFileExt, nsACString & _retval NS_OUTPARAM)
{
    return NS_ERROR_NOT_IMPLEMENTED;
}

/* End of implementation class template. */
#endif


#endif /* __gen_nsIMIMEService_h__ */
