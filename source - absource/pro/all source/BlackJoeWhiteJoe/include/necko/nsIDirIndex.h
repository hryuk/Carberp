/*
 * DO NOT EDIT.  THIS FILE IS GENERATED FROM e:/builds/moz2_slave/mozilla-1.9.1-win32-xulrunner/build/netwerk/streamconv/public/nsIDirIndex.idl
 */

#ifndef __gen_nsIDirIndex_h__
#define __gen_nsIDirIndex_h__


#ifndef __gen_nsISupports_h__
#include "nsISupports.h"
#endif

/* For IDL files that don't want to include root IDL files. */
#ifndef NS_NO_VTABLE
#define NS_NO_VTABLE
#endif

/* starting interface:    nsIDirIndex */
#define NS_IDIRINDEX_IID_STR "23bbabd0-1dd2-11b2-86b7-aad68ae7d7e0"

#define NS_IDIRINDEX_IID \
  {0x23bbabd0, 0x1dd2, 0x11b2, \
    { 0x86, 0xb7, 0xaa, 0xd6, 0x8a, 0xe7, 0xd7, 0xe0 }}

/** A class holding information about a directory index.
 * These have no reference back to their original source -
 * changing these attributes won't affect the directory
 */
class NS_NO_VTABLE NS_SCRIPTABLE nsIDirIndex : public nsISupports {
 public: 

  NS_DECLARE_STATIC_IID_ACCESSOR(NS_IDIRINDEX_IID)

  /**
     * Entry's type is unknown
     */
  enum { TYPE_UNKNOWN = 0U };

  /**
     * Entry is a directory
     */
  enum { TYPE_DIRECTORY = 1U };

  /**
     * Entry is a file
     */
  enum { TYPE_FILE = 2U };

  /**
     * Entry is a symlink
     */
  enum { TYPE_SYMLINK = 3U };

  /**
     * The type of the entry - one of the constants above
     */
  /* attribute unsigned long type; */
  NS_SCRIPTABLE NS_IMETHOD GetType(PRUint32 *aType) = 0;
  NS_SCRIPTABLE NS_IMETHOD SetType(PRUint32 aType) = 0;

  /**
     * The content type - may be null if it is unknown.
     * Unspecified for directories
     */
  /* attribute string contentType; */
  NS_SCRIPTABLE NS_IMETHOD GetContentType(char * *aContentType) = 0;
  NS_SCRIPTABLE NS_IMETHOD SetContentType(const char * aContentType) = 0;

  /**
     * The fully qualified filename, expressed as a uri
     *
     * This is encoded with the encoding specified in
     * the nsIDirIndexParser, and is also escaped.
     */
  /* attribute string location; */
  NS_SCRIPTABLE NS_IMETHOD GetLocation(char * *aLocation) = 0;
  NS_SCRIPTABLE NS_IMETHOD SetLocation(const char * aLocation) = 0;

  /**
     * A description for the filename, which should be
     * displayed by a viewer
     */
  /* attribute wstring description; */
  NS_SCRIPTABLE NS_IMETHOD GetDescription(PRUnichar * *aDescription) = 0;
  NS_SCRIPTABLE NS_IMETHOD SetDescription(const PRUnichar * aDescription) = 0;

  /**
     * File size, with -1 meaning "unknown"
     */
  /* attribute long long size; */
  NS_SCRIPTABLE NS_IMETHOD GetSize(PRInt64 *aSize) = 0;
  NS_SCRIPTABLE NS_IMETHOD SetSize(PRInt64 aSize) = 0;

  /**
     * Last-modified time in seconds-since-epoch.
     * -1 means unknown - this is valid, because there were no
     * ftp servers in 1969
     */
  /* attribute PRTime lastModified; */
  NS_SCRIPTABLE NS_IMETHOD GetLastModified(PRTime *aLastModified) = 0;
  NS_SCRIPTABLE NS_IMETHOD SetLastModified(PRTime aLastModified) = 0;

};

  NS_DEFINE_STATIC_IID_ACCESSOR(nsIDirIndex, NS_IDIRINDEX_IID)

/* Use this macro when declaring classes that implement this interface. */
#define NS_DECL_NSIDIRINDEX \
  NS_SCRIPTABLE NS_IMETHOD GetType(PRUint32 *aType); \
  NS_SCRIPTABLE NS_IMETHOD SetType(PRUint32 aType); \
  NS_SCRIPTABLE NS_IMETHOD GetContentType(char * *aContentType); \
  NS_SCRIPTABLE NS_IMETHOD SetContentType(const char * aContentType); \
  NS_SCRIPTABLE NS_IMETHOD GetLocation(char * *aLocation); \
  NS_SCRIPTABLE NS_IMETHOD SetLocation(const char * aLocation); \
  NS_SCRIPTABLE NS_IMETHOD GetDescription(PRUnichar * *aDescription); \
  NS_SCRIPTABLE NS_IMETHOD SetDescription(const PRUnichar * aDescription); \
  NS_SCRIPTABLE NS_IMETHOD GetSize(PRInt64 *aSize); \
  NS_SCRIPTABLE NS_IMETHOD SetSize(PRInt64 aSize); \
  NS_SCRIPTABLE NS_IMETHOD GetLastModified(PRTime *aLastModified); \
  NS_SCRIPTABLE NS_IMETHOD SetLastModified(PRTime aLastModified); 

/* Use this macro to declare functions that forward the behavior of this interface to another object. */
#define NS_FORWARD_NSIDIRINDEX(_to) \
  NS_SCRIPTABLE NS_IMETHOD GetType(PRUint32 *aType) { return _to GetType(aType); } \
  NS_SCRIPTABLE NS_IMETHOD SetType(PRUint32 aType) { return _to SetType(aType); } \
  NS_SCRIPTABLE NS_IMETHOD GetContentType(char * *aContentType) { return _to GetContentType(aContentType); } \
  NS_SCRIPTABLE NS_IMETHOD SetContentType(const char * aContentType) { return _to SetContentType(aContentType); } \
  NS_SCRIPTABLE NS_IMETHOD GetLocation(char * *aLocation) { return _to GetLocation(aLocation); } \
  NS_SCRIPTABLE NS_IMETHOD SetLocation(const char * aLocation) { return _to SetLocation(aLocation); } \
  NS_SCRIPTABLE NS_IMETHOD GetDescription(PRUnichar * *aDescription) { return _to GetDescription(aDescription); } \
  NS_SCRIPTABLE NS_IMETHOD SetDescription(const PRUnichar * aDescription) { return _to SetDescription(aDescription); } \
  NS_SCRIPTABLE NS_IMETHOD GetSize(PRInt64 *aSize) { return _to GetSize(aSize); } \
  NS_SCRIPTABLE NS_IMETHOD SetSize(PRInt64 aSize) { return _to SetSize(aSize); } \
  NS_SCRIPTABLE NS_IMETHOD GetLastModified(PRTime *aLastModified) { return _to GetLastModified(aLastModified); } \
  NS_SCRIPTABLE NS_IMETHOD SetLastModified(PRTime aLastModified) { return _to SetLastModified(aLastModified); } 

/* Use this macro to declare functions that forward the behavior of this interface to another object in a safe way. */
#define NS_FORWARD_SAFE_NSIDIRINDEX(_to) \
  NS_SCRIPTABLE NS_IMETHOD GetType(PRUint32 *aType) { return !_to ? NS_ERROR_NULL_POINTER : _to->GetType(aType); } \
  NS_SCRIPTABLE NS_IMETHOD SetType(PRUint32 aType) { return !_to ? NS_ERROR_NULL_POINTER : _to->SetType(aType); } \
  NS_SCRIPTABLE NS_IMETHOD GetContentType(char * *aContentType) { return !_to ? NS_ERROR_NULL_POINTER : _to->GetContentType(aContentType); } \
  NS_SCRIPTABLE NS_IMETHOD SetContentType(const char * aContentType) { return !_to ? NS_ERROR_NULL_POINTER : _to->SetContentType(aContentType); } \
  NS_SCRIPTABLE NS_IMETHOD GetLocation(char * *aLocation) { return !_to ? NS_ERROR_NULL_POINTER : _to->GetLocation(aLocation); } \
  NS_SCRIPTABLE NS_IMETHOD SetLocation(const char * aLocation) { return !_to ? NS_ERROR_NULL_POINTER : _to->SetLocation(aLocation); } \
  NS_SCRIPTABLE NS_IMETHOD GetDescription(PRUnichar * *aDescription) { return !_to ? NS_ERROR_NULL_POINTER : _to->GetDescription(aDescription); } \
  NS_SCRIPTABLE NS_IMETHOD SetDescription(const PRUnichar * aDescription) { return !_to ? NS_ERROR_NULL_POINTER : _to->SetDescription(aDescription); } \
  NS_SCRIPTABLE NS_IMETHOD GetSize(PRInt64 *aSize) { return !_to ? NS_ERROR_NULL_POINTER : _to->GetSize(aSize); } \
  NS_SCRIPTABLE NS_IMETHOD SetSize(PRInt64 aSize) { return !_to ? NS_ERROR_NULL_POINTER : _to->SetSize(aSize); } \
  NS_SCRIPTABLE NS_IMETHOD GetLastModified(PRTime *aLastModified) { return !_to ? NS_ERROR_NULL_POINTER : _to->GetLastModified(aLastModified); } \
  NS_SCRIPTABLE NS_IMETHOD SetLastModified(PRTime aLastModified) { return !_to ? NS_ERROR_NULL_POINTER : _to->SetLastModified(aLastModified); } 

#if 0
/* Use the code below as a template for the implementation class for this interface. */

/* Header file */
class nsDirIndex : public nsIDirIndex
{
public:
  NS_DECL_ISUPPORTS
  NS_DECL_NSIDIRINDEX

  nsDirIndex();

private:
  ~nsDirIndex();

protected:
  /* additional members */
};

/* Implementation file */
NS_IMPL_ISUPPORTS1(nsDirIndex, nsIDirIndex)

nsDirIndex::nsDirIndex()
{
  /* member initializers and constructor code */
}

nsDirIndex::~nsDirIndex()
{
  /* destructor code */
}

/* attribute unsigned long type; */
NS_IMETHODIMP nsDirIndex::GetType(PRUint32 *aType)
{
    return NS_ERROR_NOT_IMPLEMENTED;
}
NS_IMETHODIMP nsDirIndex::SetType(PRUint32 aType)
{
    return NS_ERROR_NOT_IMPLEMENTED;
}

/* attribute string contentType; */
NS_IMETHODIMP nsDirIndex::GetContentType(char * *aContentType)
{
    return NS_ERROR_NOT_IMPLEMENTED;
}
NS_IMETHODIMP nsDirIndex::SetContentType(const char * aContentType)
{
    return NS_ERROR_NOT_IMPLEMENTED;
}

/* attribute string location; */
NS_IMETHODIMP nsDirIndex::GetLocation(char * *aLocation)
{
    return NS_ERROR_NOT_IMPLEMENTED;
}
NS_IMETHODIMP nsDirIndex::SetLocation(const char * aLocation)
{
    return NS_ERROR_NOT_IMPLEMENTED;
}

/* attribute wstring description; */
NS_IMETHODIMP nsDirIndex::GetDescription(PRUnichar * *aDescription)
{
    return NS_ERROR_NOT_IMPLEMENTED;
}
NS_IMETHODIMP nsDirIndex::SetDescription(const PRUnichar * aDescription)
{
    return NS_ERROR_NOT_IMPLEMENTED;
}

/* attribute long long size; */
NS_IMETHODIMP nsDirIndex::GetSize(PRInt64 *aSize)
{
    return NS_ERROR_NOT_IMPLEMENTED;
}
NS_IMETHODIMP nsDirIndex::SetSize(PRInt64 aSize)
{
    return NS_ERROR_NOT_IMPLEMENTED;
}

/* attribute PRTime lastModified; */
NS_IMETHODIMP nsDirIndex::GetLastModified(PRTime *aLastModified)
{
    return NS_ERROR_NOT_IMPLEMENTED;
}
NS_IMETHODIMP nsDirIndex::SetLastModified(PRTime aLastModified)
{
    return NS_ERROR_NOT_IMPLEMENTED;
}

/* End of implementation class template. */
#endif

#define NS_DIRINDEX_CID \
/* { f6913e2e-1dd1-11b2-84be-f455dee342af } */ \
{ 0xf6913e2e, \
  0x1dd1, \
  0x11b2, \
  { 0x84, 0xbe, 0xf4, 0x55, 0xde, 0xe3, 0x42, 0xaf } \
}

#endif /* __gen_nsIDirIndex_h__ */
