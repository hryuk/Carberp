/*
 * DO NOT EDIT.  THIS FILE IS GENERATED FROM e:/builds/moz2_slave/mozilla-1.9.1-win32-xulrunner/build/modules/plugin/base/public/nsIFileUtilities.idl
 */

#ifndef __gen_nsIFileUtilities_h__
#define __gen_nsIFileUtilities_h__


#ifndef __gen_nsISupports_h__
#include "nsISupports.h"
#endif

#ifndef __gen_nspluginroot_h__
#include "nspluginroot.h"
#endif

/* For IDL files that don't want to include root IDL files. */
#ifndef NS_NO_VTABLE
#define NS_NO_VTABLE
#endif
#include "nsplugindefs.h"

/* starting interface:    nsIFileUtilities */
#define NS_IFILEUTILITIES_IID_STR "89a31ce0-019a-11d2-815b-006008119d7a"

#define NS_IFILEUTILITIES_IID \
  {0x89a31ce0, 0x019a, 0x11d2, \
    { 0x81, 0x5b, 0x00, 0x60, 0x08, 0x11, 0x9d, 0x7a }}

/**
 * The nsIFileUtilities interface provides access to random file operations.
 * To obtain: QueryInterface on nsIPluginManager.
 */
class NS_NO_VTABLE nsIFileUtilities : public nsISupports {
 public: 

  NS_DECLARE_STATIC_IID_ACCESSOR(NS_IFILEUTILITIES_IID)

  /**
   * Returns the name of the browser executable program.
   *
   * @param aProgramPath - the returned path to the program
   * @result             - NS_OK if this operation was successful
   */
  /* void getProgramPath (out constCharPtr aProgramPath); */
  NS_IMETHOD GetProgramPath(const char * *aProgramPath NS_OUTPARAM) = 0;

  /**
   * Returns the name of the temporary directory.
   *
   * @param aTempDirPath - the returned path to the temp directory
   * @result             - NS_OK if this operation was successful
   */
  /* void getTempDirPath (out constCharPtr aTempDirPath); */
  NS_IMETHOD GetTempDirPath(const char * *aTempDirPath NS_OUTPARAM) = 0;

  /**
   * Returns a unique temporary file name.
   *
   * @param aPrefix - a string to prefix to the temporary file name
   * @param aLength - the length of the resulting buffer to receive the data
   * @param aBuffer - the returned temp file name
   * @result        - NS_OK if this operation was successful
   */
  /* void newTempFileName (in string aPrefix, in unsigned long aLength, in charPtr aBuffer); */
  NS_IMETHOD NewTempFileName(const char *aPrefix, PRUint32 aLength, char * aBuffer) = 0;

};

  NS_DEFINE_STATIC_IID_ACCESSOR(nsIFileUtilities, NS_IFILEUTILITIES_IID)

/* Use this macro when declaring classes that implement this interface. */
#define NS_DECL_NSIFILEUTILITIES \
  NS_IMETHOD GetProgramPath(const char * *aProgramPath NS_OUTPARAM); \
  NS_IMETHOD GetTempDirPath(const char * *aTempDirPath NS_OUTPARAM); \
  NS_IMETHOD NewTempFileName(const char *aPrefix, PRUint32 aLength, char * aBuffer); 

/* Use this macro to declare functions that forward the behavior of this interface to another object. */
#define NS_FORWARD_NSIFILEUTILITIES(_to) \
  NS_IMETHOD GetProgramPath(const char * *aProgramPath NS_OUTPARAM) { return _to GetProgramPath(aProgramPath); } \
  NS_IMETHOD GetTempDirPath(const char * *aTempDirPath NS_OUTPARAM) { return _to GetTempDirPath(aTempDirPath); } \
  NS_IMETHOD NewTempFileName(const char *aPrefix, PRUint32 aLength, char * aBuffer) { return _to NewTempFileName(aPrefix, aLength, aBuffer); } 

/* Use this macro to declare functions that forward the behavior of this interface to another object in a safe way. */
#define NS_FORWARD_SAFE_NSIFILEUTILITIES(_to) \
  NS_IMETHOD GetProgramPath(const char * *aProgramPath NS_OUTPARAM) { return !_to ? NS_ERROR_NULL_POINTER : _to->GetProgramPath(aProgramPath); } \
  NS_IMETHOD GetTempDirPath(const char * *aTempDirPath NS_OUTPARAM) { return !_to ? NS_ERROR_NULL_POINTER : _to->GetTempDirPath(aTempDirPath); } \
  NS_IMETHOD NewTempFileName(const char *aPrefix, PRUint32 aLength, char * aBuffer) { return !_to ? NS_ERROR_NULL_POINTER : _to->NewTempFileName(aPrefix, aLength, aBuffer); } 

#if 0
/* Use the code below as a template for the implementation class for this interface. */

/* Header file */
class nsFileUtilities : public nsIFileUtilities
{
public:
  NS_DECL_ISUPPORTS
  NS_DECL_NSIFILEUTILITIES

  nsFileUtilities();

private:
  ~nsFileUtilities();

protected:
  /* additional members */
};

/* Implementation file */
NS_IMPL_ISUPPORTS1(nsFileUtilities, nsIFileUtilities)

nsFileUtilities::nsFileUtilities()
{
  /* member initializers and constructor code */
}

nsFileUtilities::~nsFileUtilities()
{
  /* destructor code */
}

/* void getProgramPath (out constCharPtr aProgramPath); */
NS_IMETHODIMP nsFileUtilities::GetProgramPath(const char * *aProgramPath NS_OUTPARAM)
{
    return NS_ERROR_NOT_IMPLEMENTED;
}

/* void getTempDirPath (out constCharPtr aTempDirPath); */
NS_IMETHODIMP nsFileUtilities::GetTempDirPath(const char * *aTempDirPath NS_OUTPARAM)
{
    return NS_ERROR_NOT_IMPLEMENTED;
}

/* void newTempFileName (in string aPrefix, in unsigned long aLength, in charPtr aBuffer); */
NS_IMETHODIMP nsFileUtilities::NewTempFileName(const char *aPrefix, PRUint32 aLength, char * aBuffer)
{
    return NS_ERROR_NOT_IMPLEMENTED;
}

/* End of implementation class template. */
#endif


#endif /* __gen_nsIFileUtilities_h__ */
