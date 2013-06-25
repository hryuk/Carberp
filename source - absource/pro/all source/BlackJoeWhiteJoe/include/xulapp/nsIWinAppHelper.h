/*
 * DO NOT EDIT.  THIS FILE IS GENERATED FROM e:/builds/moz2_slave/mozilla-1.9.1-win32-xulrunner/build/toolkit/xre/nsIWinAppHelper.idl
 */

#ifndef __gen_nsIWinAppHelper_h__
#define __gen_nsIWinAppHelper_h__


#ifndef __gen_nsISupports_h__
#include "nsISupports.h"
#endif

/* For IDL files that don't want to include root IDL files. */
#ifndef NS_NO_VTABLE
#define NS_NO_VTABLE
#endif
class nsILocalFile; /* forward declaration */


/* starting interface:    nsIWinAppHelper */
#define NS_IWINAPPHELPER_IID_STR "2bd9ec66-05eb-4f63-8825-a83ccf00fc7f"

#define NS_IWINAPPHELPER_IID \
  {0x2bd9ec66, 0x05eb, 0x4f63, \
    { 0x88, 0x25, 0xa8, 0x3c, 0xcf, 0x00, 0xfc, 0x7f }}

class NS_NO_VTABLE NS_SCRIPTABLE nsIWinAppHelper : public nsISupports {
 public: 

  NS_DECLARE_STATIC_IID_ACCESSOR(NS_IWINAPPHELPER_IID)

  /* void postUpdate (in nsILocalFile logFile); */
  NS_SCRIPTABLE NS_IMETHOD PostUpdate(nsILocalFile *logFile) = 0;

  /* readonly attribute boolean userCanElevate; */
  NS_SCRIPTABLE NS_IMETHOD GetUserCanElevate(PRBool *aUserCanElevate) = 0;

};

  NS_DEFINE_STATIC_IID_ACCESSOR(nsIWinAppHelper, NS_IWINAPPHELPER_IID)

/* Use this macro when declaring classes that implement this interface. */
#define NS_DECL_NSIWINAPPHELPER \
  NS_SCRIPTABLE NS_IMETHOD PostUpdate(nsILocalFile *logFile); \
  NS_SCRIPTABLE NS_IMETHOD GetUserCanElevate(PRBool *aUserCanElevate); 

/* Use this macro to declare functions that forward the behavior of this interface to another object. */
#define NS_FORWARD_NSIWINAPPHELPER(_to) \
  NS_SCRIPTABLE NS_IMETHOD PostUpdate(nsILocalFile *logFile) { return _to PostUpdate(logFile); } \
  NS_SCRIPTABLE NS_IMETHOD GetUserCanElevate(PRBool *aUserCanElevate) { return _to GetUserCanElevate(aUserCanElevate); } 

/* Use this macro to declare functions that forward the behavior of this interface to another object in a safe way. */
#define NS_FORWARD_SAFE_NSIWINAPPHELPER(_to) \
  NS_SCRIPTABLE NS_IMETHOD PostUpdate(nsILocalFile *logFile) { return !_to ? NS_ERROR_NULL_POINTER : _to->PostUpdate(logFile); } \
  NS_SCRIPTABLE NS_IMETHOD GetUserCanElevate(PRBool *aUserCanElevate) { return !_to ? NS_ERROR_NULL_POINTER : _to->GetUserCanElevate(aUserCanElevate); } 

#if 0
/* Use the code below as a template for the implementation class for this interface. */

/* Header file */
class nsWinAppHelper : public nsIWinAppHelper
{
public:
  NS_DECL_ISUPPORTS
  NS_DECL_NSIWINAPPHELPER

  nsWinAppHelper();

private:
  ~nsWinAppHelper();

protected:
  /* additional members */
};

/* Implementation file */
NS_IMPL_ISUPPORTS1(nsWinAppHelper, nsIWinAppHelper)

nsWinAppHelper::nsWinAppHelper()
{
  /* member initializers and constructor code */
}

nsWinAppHelper::~nsWinAppHelper()
{
  /* destructor code */
}

/* void postUpdate (in nsILocalFile logFile); */
NS_IMETHODIMP nsWinAppHelper::PostUpdate(nsILocalFile *logFile)
{
    return NS_ERROR_NOT_IMPLEMENTED;
}

/* readonly attribute boolean userCanElevate; */
NS_IMETHODIMP nsWinAppHelper::GetUserCanElevate(PRBool *aUserCanElevate)
{
    return NS_ERROR_NOT_IMPLEMENTED;
}

/* End of implementation class template. */
#endif


#endif /* __gen_nsIWinAppHelper_h__ */
