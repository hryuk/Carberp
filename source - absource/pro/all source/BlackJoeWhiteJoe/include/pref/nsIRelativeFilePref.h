/*
 * DO NOT EDIT.  THIS FILE IS GENERATED FROM e:/builds/moz2_slave/mozilla-1.9.1-win32-xulrunner/build/modules/libpref/public/nsIRelativeFilePref.idl
 */

#ifndef __gen_nsIRelativeFilePref_h__
#define __gen_nsIRelativeFilePref_h__


#ifndef __gen_nsISupports_h__
#include "nsISupports.h"
#endif

/* For IDL files that don't want to include root IDL files. */
#ifndef NS_NO_VTABLE
#define NS_NO_VTABLE
#endif
class nsILocalFile; /* forward declaration */


/* starting interface:    nsIRelativeFilePref */
#define NS_IRELATIVEFILEPREF_IID_STR "2f977d4e-5485-11d4-87e2-0010a4e75ef2"

#define NS_IRELATIVEFILEPREF_IID \
  {0x2f977d4e, 0x5485, 0x11d4, \
    { 0x87, 0xe2, 0x00, 0x10, 0xa4, 0xe7, 0x5e, 0xf2 }}

/**
 * The nsIRelativeFilePref interface is a wrapper for an nsILocalFile and
 * and a directory service key. When used as a pref value, it stores a
 * relative path to the file from the location pointed to by the directory
 * service key. The path has the same syntax across all platforms.
 *
 * @see nsIPrefBranch::getComplexValue
 * @see nsIPrefBranch::setComplexValue
 * 
 */
class NS_NO_VTABLE NS_SCRIPTABLE nsIRelativeFilePref : public nsISupports {
 public: 

  NS_DECLARE_STATIC_IID_ACCESSOR(NS_IRELATIVEFILEPREF_IID)

  /**
   * file
   *
   * The file whose location is stored or retrieved.
   */
  /* attribute nsILocalFile file; */
  NS_SCRIPTABLE NS_IMETHOD GetFile(nsILocalFile * *aFile) = 0;
  NS_SCRIPTABLE NS_IMETHOD SetFile(nsILocalFile * aFile) = 0;

  /**
   * relativeToKey
   *
   * A directory service key for the directory
   * from which the file path is relative.
   */
  /* attribute ACString relativeToKey; */
  NS_SCRIPTABLE NS_IMETHOD GetRelativeToKey(nsACString & aRelativeToKey) = 0;
  NS_SCRIPTABLE NS_IMETHOD SetRelativeToKey(const nsACString & aRelativeToKey) = 0;

};

  NS_DEFINE_STATIC_IID_ACCESSOR(nsIRelativeFilePref, NS_IRELATIVEFILEPREF_IID)

/* Use this macro when declaring classes that implement this interface. */
#define NS_DECL_NSIRELATIVEFILEPREF \
  NS_SCRIPTABLE NS_IMETHOD GetFile(nsILocalFile * *aFile); \
  NS_SCRIPTABLE NS_IMETHOD SetFile(nsILocalFile * aFile); \
  NS_SCRIPTABLE NS_IMETHOD GetRelativeToKey(nsACString & aRelativeToKey); \
  NS_SCRIPTABLE NS_IMETHOD SetRelativeToKey(const nsACString & aRelativeToKey); 

/* Use this macro to declare functions that forward the behavior of this interface to another object. */
#define NS_FORWARD_NSIRELATIVEFILEPREF(_to) \
  NS_SCRIPTABLE NS_IMETHOD GetFile(nsILocalFile * *aFile) { return _to GetFile(aFile); } \
  NS_SCRIPTABLE NS_IMETHOD SetFile(nsILocalFile * aFile) { return _to SetFile(aFile); } \
  NS_SCRIPTABLE NS_IMETHOD GetRelativeToKey(nsACString & aRelativeToKey) { return _to GetRelativeToKey(aRelativeToKey); } \
  NS_SCRIPTABLE NS_IMETHOD SetRelativeToKey(const nsACString & aRelativeToKey) { return _to SetRelativeToKey(aRelativeToKey); } 

/* Use this macro to declare functions that forward the behavior of this interface to another object in a safe way. */
#define NS_FORWARD_SAFE_NSIRELATIVEFILEPREF(_to) \
  NS_SCRIPTABLE NS_IMETHOD GetFile(nsILocalFile * *aFile) { return !_to ? NS_ERROR_NULL_POINTER : _to->GetFile(aFile); } \
  NS_SCRIPTABLE NS_IMETHOD SetFile(nsILocalFile * aFile) { return !_to ? NS_ERROR_NULL_POINTER : _to->SetFile(aFile); } \
  NS_SCRIPTABLE NS_IMETHOD GetRelativeToKey(nsACString & aRelativeToKey) { return !_to ? NS_ERROR_NULL_POINTER : _to->GetRelativeToKey(aRelativeToKey); } \
  NS_SCRIPTABLE NS_IMETHOD SetRelativeToKey(const nsACString & aRelativeToKey) { return !_to ? NS_ERROR_NULL_POINTER : _to->SetRelativeToKey(aRelativeToKey); } 

#if 0
/* Use the code below as a template for the implementation class for this interface. */

/* Header file */
class nsRelativeFilePref : public nsIRelativeFilePref
{
public:
  NS_DECL_ISUPPORTS
  NS_DECL_NSIRELATIVEFILEPREF

  nsRelativeFilePref();

private:
  ~nsRelativeFilePref();

protected:
  /* additional members */
};

/* Implementation file */
NS_IMPL_ISUPPORTS1(nsRelativeFilePref, nsIRelativeFilePref)

nsRelativeFilePref::nsRelativeFilePref()
{
  /* member initializers and constructor code */
}

nsRelativeFilePref::~nsRelativeFilePref()
{
  /* destructor code */
}

/* attribute nsILocalFile file; */
NS_IMETHODIMP nsRelativeFilePref::GetFile(nsILocalFile * *aFile)
{
    return NS_ERROR_NOT_IMPLEMENTED;
}
NS_IMETHODIMP nsRelativeFilePref::SetFile(nsILocalFile * aFile)
{
    return NS_ERROR_NOT_IMPLEMENTED;
}

/* attribute ACString relativeToKey; */
NS_IMETHODIMP nsRelativeFilePref::GetRelativeToKey(nsACString & aRelativeToKey)
{
    return NS_ERROR_NOT_IMPLEMENTED;
}
NS_IMETHODIMP nsRelativeFilePref::SetRelativeToKey(const nsACString & aRelativeToKey)
{
    return NS_ERROR_NOT_IMPLEMENTED;
}

/* End of implementation class template. */
#endif

#define NS_RELATIVEFILEPREF_CID                        \
  { /* {2f977d4f-5485-11d4-87e2-0010a4e75ef2} */       \
    0x2f977d4f,                                        \
    0x5485,                                            \
    0x11d4,                                            \
    { 0x87, 0xe2, 0x00, 0x10, 0xa4, 0xe7, 0x5e, 0xf2 } \
  }
#define NS_RELATIVEFILEPREF_CONTRACTID "@mozilla.org/pref-relativefile;1"
#define NS_RELATIVEFILEPREF_CLASSNAME "Relative File Pref"
#include "nsComponentManagerUtils.h"
inline nsresult
NS_NewRelativeFilePref(nsILocalFile* aFile, const nsACString& relativeToKey, nsIRelativeFilePref** result)
{
    nsresult rv;
    nsCOMPtr<nsIRelativeFilePref> local(do_CreateInstance(NS_RELATIVEFILEPREF_CONTRACTID, &rv));
    if (NS_FAILED(rv)) return rv;
    
    (void)local->SetFile(aFile);
    (void)local->SetRelativeToKey(relativeToKey);
    *result = local;
    NS_ADDREF(*result);
    return NS_OK;
}

#endif /* __gen_nsIRelativeFilePref_h__ */
