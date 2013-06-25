/*
 * DO NOT EDIT.  THIS FILE IS GENERATED FROM e:/builds/moz2_slave/mozilla-1.9.1-win32-xulrunner/build/docshell/base/nsIWebNavigationInfo.idl
 */

#ifndef __gen_nsIWebNavigationInfo_h__
#define __gen_nsIWebNavigationInfo_h__


#ifndef __gen_nsISupports_h__
#include "nsISupports.h"
#endif

/* For IDL files that don't want to include root IDL files. */
#ifndef NS_NO_VTABLE
#define NS_NO_VTABLE
#endif
class nsIWebNavigation; /* forward declaration */


/* starting interface:    nsIWebNavigationInfo */
#define NS_IWEBNAVIGATIONINFO_IID_STR "62a93afb-93a1-465c-84c8-0432264229de"

#define NS_IWEBNAVIGATIONINFO_IID \
  {0x62a93afb, 0x93a1, 0x465c, \
    { 0x84, 0xc8, 0x04, 0x32, 0x26, 0x42, 0x29, 0xde }}

/**
 * The nsIWebNavigationInfo interface exposes a way to get information
 * on the capabilities of Gecko webnavigation objects.
 *
 * @status UNDER_REVIEW
 */
class NS_NO_VTABLE NS_SCRIPTABLE nsIWebNavigationInfo : public nsISupports {
 public: 

  NS_DECLARE_STATIC_IID_ACCESSOR(NS_IWEBNAVIGATIONINFO_IID)

  /**
   * Returned by isTypeSupported to indicate lack of support for a type.
   * @note this is guaranteed not to change, so that boolean tests can be done
   * on the return value if isTypeSupported to detect whether a type is
   * supported at all.
   */
  enum { UNSUPPORTED = 0U };

  /**
   * Returned by isTypeSupported to indicate that a type is supported as an
   * image.
   */
  enum { IMAGE = 1U };

  /**
   * Returned by isTypeSupported to indicate that a type is supported via an
   * NPAPI ("Netscape 4 API") plug-in.  This is not the value returned for
   * "XPCOM plug-ins".
   */
  enum { PLUGIN = 2U };

  /**
   * @note Other return types may be added here in the future as they become
   * relevant.
   */
/**
   * Returned by isTypeSupported to indicate that a type is supported via some
   * other means.
   */
  enum { OTHER = 32768U };

  /**
   * Query whether aType is supported.
   * @param aType the MIME type in question.
   * @param aWebNav the nsIWebNavigation object for which the request
   *        is being made.  This is allowed to be null.  If it is non-null,
   *        the return value of this method may depend on the exact state of
   *        aWebNav and the values set through nsIWebBrowserSetup; otherwise
   *        the method will assume that the caller is interested in information
   *        about nsIWebNavigation objects in their default state.
   * @return an enum value indicating whether and how aType is supported.
   * @note This method may rescan plugins to ensure that they're properly
   *       registered for the types they support.
   */
  /* unsigned long isTypeSupported (in ACString aType, in nsIWebNavigation aWebNav); */
  NS_SCRIPTABLE NS_IMETHOD IsTypeSupported(const nsACString & aType, nsIWebNavigation *aWebNav, PRUint32 *_retval NS_OUTPARAM) = 0;

};

  NS_DEFINE_STATIC_IID_ACCESSOR(nsIWebNavigationInfo, NS_IWEBNAVIGATIONINFO_IID)

/* Use this macro when declaring classes that implement this interface. */
#define NS_DECL_NSIWEBNAVIGATIONINFO \
  NS_SCRIPTABLE NS_IMETHOD IsTypeSupported(const nsACString & aType, nsIWebNavigation *aWebNav, PRUint32 *_retval NS_OUTPARAM); 

/* Use this macro to declare functions that forward the behavior of this interface to another object. */
#define NS_FORWARD_NSIWEBNAVIGATIONINFO(_to) \
  NS_SCRIPTABLE NS_IMETHOD IsTypeSupported(const nsACString & aType, nsIWebNavigation *aWebNav, PRUint32 *_retval NS_OUTPARAM) { return _to IsTypeSupported(aType, aWebNav, _retval); } 

/* Use this macro to declare functions that forward the behavior of this interface to another object in a safe way. */
#define NS_FORWARD_SAFE_NSIWEBNAVIGATIONINFO(_to) \
  NS_SCRIPTABLE NS_IMETHOD IsTypeSupported(const nsACString & aType, nsIWebNavigation *aWebNav, PRUint32 *_retval NS_OUTPARAM) { return !_to ? NS_ERROR_NULL_POINTER : _to->IsTypeSupported(aType, aWebNav, _retval); } 

#if 0
/* Use the code below as a template for the implementation class for this interface. */

/* Header file */
class nsWebNavigationInfo : public nsIWebNavigationInfo
{
public:
  NS_DECL_ISUPPORTS
  NS_DECL_NSIWEBNAVIGATIONINFO

  nsWebNavigationInfo();

private:
  ~nsWebNavigationInfo();

protected:
  /* additional members */
};

/* Implementation file */
NS_IMPL_ISUPPORTS1(nsWebNavigationInfo, nsIWebNavigationInfo)

nsWebNavigationInfo::nsWebNavigationInfo()
{
  /* member initializers and constructor code */
}

nsWebNavigationInfo::~nsWebNavigationInfo()
{
  /* destructor code */
}

/* unsigned long isTypeSupported (in ACString aType, in nsIWebNavigation aWebNav); */
NS_IMETHODIMP nsWebNavigationInfo::IsTypeSupported(const nsACString & aType, nsIWebNavigation *aWebNav, PRUint32 *_retval NS_OUTPARAM)
{
    return NS_ERROR_NOT_IMPLEMENTED;
}

/* End of implementation class template. */
#endif


#endif /* __gen_nsIWebNavigationInfo_h__ */
