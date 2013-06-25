/*
 * DO NOT EDIT.  THIS FILE IS GENERATED FROM e:/builds/moz2_slave/mozilla-1.9.1-win32-xulrunner/build/xpcom/io/nsILocalFileWin.idl
 */

#ifndef __gen_nsILocalFileWin_h__
#define __gen_nsILocalFileWin_h__


#ifndef __gen_nsILocalFile_h__
#include "nsILocalFile.h"
#endif

/* For IDL files that don't want to include root IDL files. */
#ifndef NS_NO_VTABLE
#define NS_NO_VTABLE
#endif

/* starting interface:    nsILocalFileWin */
#define NS_ILOCALFILEWIN_IID_STR "def38371-73b0-4dfd-85cd-0a7c91afbec6"

#define NS_ILOCALFILEWIN_IID \
  {0xdef38371, 0x73b0, 0x4dfd, \
    { 0x85, 0xcd, 0x0a, 0x7c, 0x91, 0xaf, 0xbe, 0xc6 }}

class NS_NO_VTABLE NS_SCRIPTABLE nsILocalFileWin : public nsILocalFile {
 public: 

  NS_DECLARE_STATIC_IID_ACCESSOR(NS_ILOCALFILEWIN_IID)

  /**
    * getVersionInfoValue
    *
    * Retrieve a metadata field from the file's VERSIONINFO block.
    * Throws NS_ERROR_FAILURE if no value is found, or the value is empty.
    *
    * @param   aField         The field to look up.
    *
    */
  /* AString getVersionInfoField (in string aField); */
  NS_SCRIPTABLE NS_IMETHOD GetVersionInfoField(const char *aField, nsAString & _retval NS_OUTPARAM) = 0;

  /**
     * The canonical path of the file, which avoids short/long
     * pathname inconsistencies. The nsILocalFile persistent
     * descriptor is not guaranteed to be canonicalized (it may
     * persist either the long or the short path name). The format of
     * the canonical path will vary with the underlying file system:
     * it will typically be the short pathname on filesystems that
     * support both short and long path forms.
     */
  /* readonly attribute AString canonicalPath; */
  NS_SCRIPTABLE NS_IMETHOD GetCanonicalPath(nsAString & aCanonicalPath) = 0;

  /* [noscript] readonly attribute ACString nativeCanonicalPath; */
  NS_IMETHOD GetNativeCanonicalPath(nsACString & aNativeCanonicalPath) = 0;

};

  NS_DEFINE_STATIC_IID_ACCESSOR(nsILocalFileWin, NS_ILOCALFILEWIN_IID)

/* Use this macro when declaring classes that implement this interface. */
#define NS_DECL_NSILOCALFILEWIN \
  NS_SCRIPTABLE NS_IMETHOD GetVersionInfoField(const char *aField, nsAString & _retval NS_OUTPARAM); \
  NS_SCRIPTABLE NS_IMETHOD GetCanonicalPath(nsAString & aCanonicalPath); \
  NS_IMETHOD GetNativeCanonicalPath(nsACString & aNativeCanonicalPath); 

/* Use this macro to declare functions that forward the behavior of this interface to another object. */
#define NS_FORWARD_NSILOCALFILEWIN(_to) \
  NS_SCRIPTABLE NS_IMETHOD GetVersionInfoField(const char *aField, nsAString & _retval NS_OUTPARAM) { return _to GetVersionInfoField(aField, _retval); } \
  NS_SCRIPTABLE NS_IMETHOD GetCanonicalPath(nsAString & aCanonicalPath) { return _to GetCanonicalPath(aCanonicalPath); } \
  NS_IMETHOD GetNativeCanonicalPath(nsACString & aNativeCanonicalPath) { return _to GetNativeCanonicalPath(aNativeCanonicalPath); } 

/* Use this macro to declare functions that forward the behavior of this interface to another object in a safe way. */
#define NS_FORWARD_SAFE_NSILOCALFILEWIN(_to) \
  NS_SCRIPTABLE NS_IMETHOD GetVersionInfoField(const char *aField, nsAString & _retval NS_OUTPARAM) { return !_to ? NS_ERROR_NULL_POINTER : _to->GetVersionInfoField(aField, _retval); } \
  NS_SCRIPTABLE NS_IMETHOD GetCanonicalPath(nsAString & aCanonicalPath) { return !_to ? NS_ERROR_NULL_POINTER : _to->GetCanonicalPath(aCanonicalPath); } \
  NS_IMETHOD GetNativeCanonicalPath(nsACString & aNativeCanonicalPath) { return !_to ? NS_ERROR_NULL_POINTER : _to->GetNativeCanonicalPath(aNativeCanonicalPath); } 

#if 0
/* Use the code below as a template for the implementation class for this interface. */

/* Header file */
class nsLocalFileWin : public nsILocalFileWin
{
public:
  NS_DECL_ISUPPORTS
  NS_DECL_NSILOCALFILEWIN

  nsLocalFileWin();

private:
  ~nsLocalFileWin();

protected:
  /* additional members */
};

/* Implementation file */
NS_IMPL_ISUPPORTS1(nsLocalFileWin, nsILocalFileWin)

nsLocalFileWin::nsLocalFileWin()
{
  /* member initializers and constructor code */
}

nsLocalFileWin::~nsLocalFileWin()
{
  /* destructor code */
}

/* AString getVersionInfoField (in string aField); */
NS_IMETHODIMP nsLocalFileWin::GetVersionInfoField(const char *aField, nsAString & _retval NS_OUTPARAM)
{
    return NS_ERROR_NOT_IMPLEMENTED;
}

/* readonly attribute AString canonicalPath; */
NS_IMETHODIMP nsLocalFileWin::GetCanonicalPath(nsAString & aCanonicalPath)
{
    return NS_ERROR_NOT_IMPLEMENTED;
}

/* [noscript] readonly attribute ACString nativeCanonicalPath; */
NS_IMETHODIMP nsLocalFileWin::GetNativeCanonicalPath(nsACString & aNativeCanonicalPath)
{
    return NS_ERROR_NOT_IMPLEMENTED;
}

/* End of implementation class template. */
#endif


#endif /* __gen_nsILocalFileWin_h__ */
