/*
 * DO NOT EDIT.  THIS FILE IS GENERATED FROM e:/builds/moz2_slave/mozilla-1.9.1-win32-xulrunner/build/xulrunner/setup/nsIXULAppInstall.idl
 */

#ifndef __gen_nsIXULAppInstall_h__
#define __gen_nsIXULAppInstall_h__


#ifndef __gen_nsISupports_h__
#include "nsISupports.h"
#endif

/* For IDL files that don't want to include root IDL files. */
#ifndef NS_NO_VTABLE
#define NS_NO_VTABLE
#endif
class nsIFile; /* forward declaration */


/* starting interface:    nsIXULAppInstall */
#define NS_IXULAPPINSTALL_IID_STR "800ace15-6b38-48c4-b057-7928378f6cd2"

#define NS_IXULAPPINSTALL_IID \
  {0x800ace15, 0x6b38, 0x48c4, \
    { 0xb0, 0x57, 0x79, 0x28, 0x37, 0x8f, 0x6c, 0xd2 }}

/**
 * Installation and management of XUL applications.
 *
 * @status IN_FLUX   This interface is not stable and will change in the
 *                   future.
 */
class NS_NO_VTABLE NS_SCRIPTABLE nsIXULAppInstall : public nsISupports {
 public: 

  NS_DECLARE_STATIC_IID_ACCESSOR(NS_IXULAPPINSTALL_IID)

  /**
   * Install a XUL application into a form that can be run by the native
   * operating system.
   *
   * @param aAppFile   Directory or a zip file containing a 
   *                   XULRunner package (with the required application.ini
   *                   file in the root).
   * @param aDirectory Path specifying the location to install the
   *                   application. If null, an appropriate default install
   *                   location will be used. e.g. "C:\Program Files\<Vendor>"
   *                   on Windows.
   * @param aLeafName  The leaf name of the application directory. If empty
   *                   an appropriate default will be chosen. e.g. "Simple.app"
   *                   on Mac.
   */
  /* void installApplication (in nsIFile aAppFile, in nsIFile aDirectory, in AString aLeafName); */
  NS_SCRIPTABLE NS_IMETHOD InstallApplication(nsIFile *aAppFile, nsIFile *aDirectory, const nsAString & aLeafName) = 0;

};

  NS_DEFINE_STATIC_IID_ACCESSOR(nsIXULAppInstall, NS_IXULAPPINSTALL_IID)

/* Use this macro when declaring classes that implement this interface. */
#define NS_DECL_NSIXULAPPINSTALL \
  NS_SCRIPTABLE NS_IMETHOD InstallApplication(nsIFile *aAppFile, nsIFile *aDirectory, const nsAString & aLeafName); 

/* Use this macro to declare functions that forward the behavior of this interface to another object. */
#define NS_FORWARD_NSIXULAPPINSTALL(_to) \
  NS_SCRIPTABLE NS_IMETHOD InstallApplication(nsIFile *aAppFile, nsIFile *aDirectory, const nsAString & aLeafName) { return _to InstallApplication(aAppFile, aDirectory, aLeafName); } 

/* Use this macro to declare functions that forward the behavior of this interface to another object in a safe way. */
#define NS_FORWARD_SAFE_NSIXULAPPINSTALL(_to) \
  NS_SCRIPTABLE NS_IMETHOD InstallApplication(nsIFile *aAppFile, nsIFile *aDirectory, const nsAString & aLeafName) { return !_to ? NS_ERROR_NULL_POINTER : _to->InstallApplication(aAppFile, aDirectory, aLeafName); } 

#if 0
/* Use the code below as a template for the implementation class for this interface. */

/* Header file */
class nsXULAppInstall : public nsIXULAppInstall
{
public:
  NS_DECL_ISUPPORTS
  NS_DECL_NSIXULAPPINSTALL

  nsXULAppInstall();

private:
  ~nsXULAppInstall();

protected:
  /* additional members */
};

/* Implementation file */
NS_IMPL_ISUPPORTS1(nsXULAppInstall, nsIXULAppInstall)

nsXULAppInstall::nsXULAppInstall()
{
  /* member initializers and constructor code */
}

nsXULAppInstall::~nsXULAppInstall()
{
  /* destructor code */
}

/* void installApplication (in nsIFile aAppFile, in nsIFile aDirectory, in AString aLeafName); */
NS_IMETHODIMP nsXULAppInstall::InstallApplication(nsIFile *aAppFile, nsIFile *aDirectory, const nsAString & aLeafName)
{
    return NS_ERROR_NOT_IMPLEMENTED;
}

/* End of implementation class template. */
#endif


#endif /* __gen_nsIXULAppInstall_h__ */
