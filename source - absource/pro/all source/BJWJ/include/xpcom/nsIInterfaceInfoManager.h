/*
 * DO NOT EDIT.  THIS FILE IS GENERATED FROM e:/builds/moz2_slave/mozilla-1.9.1-win32-xulrunner/build/xpcom/reflect/xptinfo/public/nsIInterfaceInfoManager.idl
 */

#ifndef __gen_nsIInterfaceInfoManager_h__
#define __gen_nsIInterfaceInfoManager_h__


#ifndef __gen_nsISupports_h__
#include "nsISupports.h"
#endif

#ifndef __gen_nsIInterfaceInfo_h__
#include "nsIInterfaceInfo.h"
#endif

#ifndef __gen_nsIEnumerator_h__
#include "nsIEnumerator.h"
#endif

#ifndef __gen_nsISimpleEnumerator_h__
#include "nsISimpleEnumerator.h"
#endif

/* For IDL files that don't want to include root IDL files. */
#ifndef NS_NO_VTABLE
#define NS_NO_VTABLE
#endif

/* starting interface:    nsIInterfaceInfoManager */
#define NS_IINTERFACEINFOMANAGER_IID_STR "8b161900-be2b-11d2-9831-006008962422"

#define NS_IINTERFACEINFOMANAGER_IID \
  {0x8b161900, 0xbe2b, 0x11d2, \
    { 0x98, 0x31, 0x00, 0x60, 0x08, 0x96, 0x24, 0x22 }}

class NS_NO_VTABLE nsIInterfaceInfoManager : public nsISupports {
 public: 

  NS_DECLARE_STATIC_IID_ACCESSOR(NS_IINTERFACEINFOMANAGER_IID)

  /* nsIInterfaceInfo getInfoForIID (in nsIIDPtr iid); */
  NS_IMETHOD GetInfoForIID(const nsIID * iid, nsIInterfaceInfo **_retval NS_OUTPARAM) = 0;

  /* nsIInterfaceInfo getInfoForName (in string name); */
  NS_IMETHOD GetInfoForName(const char *name, nsIInterfaceInfo **_retval NS_OUTPARAM) = 0;

  /* nsIIDPtr getIIDForName (in string name); */
  NS_IMETHOD GetIIDForName(const char *name, nsIID * *_retval NS_OUTPARAM) = 0;

  /* string getNameForIID (in nsIIDPtr iid); */
  NS_IMETHOD GetNameForIID(const nsIID * iid, char **_retval NS_OUTPARAM) = 0;

  /* nsIEnumerator enumerateInterfaces (); */
  NS_IMETHOD EnumerateInterfaces(nsIEnumerator **_retval NS_OUTPARAM) = 0;

  /* void autoRegisterInterfaces (); */
  NS_IMETHOD AutoRegisterInterfaces(void) = 0;

  /* nsIEnumerator enumerateInterfacesWhoseNamesStartWith (in string prefix); */
  NS_IMETHOD EnumerateInterfacesWhoseNamesStartWith(const char *prefix, nsIEnumerator **_retval NS_OUTPARAM) = 0;

};

  NS_DEFINE_STATIC_IID_ACCESSOR(nsIInterfaceInfoManager, NS_IINTERFACEINFOMANAGER_IID)

/* Use this macro when declaring classes that implement this interface. */
#define NS_DECL_NSIINTERFACEINFOMANAGER \
  NS_IMETHOD GetInfoForIID(const nsIID * iid, nsIInterfaceInfo **_retval NS_OUTPARAM); \
  NS_IMETHOD GetInfoForName(const char *name, nsIInterfaceInfo **_retval NS_OUTPARAM); \
  NS_IMETHOD GetIIDForName(const char *name, nsIID * *_retval NS_OUTPARAM); \
  NS_IMETHOD GetNameForIID(const nsIID * iid, char **_retval NS_OUTPARAM); \
  NS_IMETHOD EnumerateInterfaces(nsIEnumerator **_retval NS_OUTPARAM); \
  NS_IMETHOD AutoRegisterInterfaces(void); \
  NS_IMETHOD EnumerateInterfacesWhoseNamesStartWith(const char *prefix, nsIEnumerator **_retval NS_OUTPARAM); 

/* Use this macro to declare functions that forward the behavior of this interface to another object. */
#define NS_FORWARD_NSIINTERFACEINFOMANAGER(_to) \
  NS_IMETHOD GetInfoForIID(const nsIID * iid, nsIInterfaceInfo **_retval NS_OUTPARAM) { return _to GetInfoForIID(iid, _retval); } \
  NS_IMETHOD GetInfoForName(const char *name, nsIInterfaceInfo **_retval NS_OUTPARAM) { return _to GetInfoForName(name, _retval); } \
  NS_IMETHOD GetIIDForName(const char *name, nsIID * *_retval NS_OUTPARAM) { return _to GetIIDForName(name, _retval); } \
  NS_IMETHOD GetNameForIID(const nsIID * iid, char **_retval NS_OUTPARAM) { return _to GetNameForIID(iid, _retval); } \
  NS_IMETHOD EnumerateInterfaces(nsIEnumerator **_retval NS_OUTPARAM) { return _to EnumerateInterfaces(_retval); } \
  NS_IMETHOD AutoRegisterInterfaces(void) { return _to AutoRegisterInterfaces(); } \
  NS_IMETHOD EnumerateInterfacesWhoseNamesStartWith(const char *prefix, nsIEnumerator **_retval NS_OUTPARAM) { return _to EnumerateInterfacesWhoseNamesStartWith(prefix, _retval); } 

/* Use this macro to declare functions that forward the behavior of this interface to another object in a safe way. */
#define NS_FORWARD_SAFE_NSIINTERFACEINFOMANAGER(_to) \
  NS_IMETHOD GetInfoForIID(const nsIID * iid, nsIInterfaceInfo **_retval NS_OUTPARAM) { return !_to ? NS_ERROR_NULL_POINTER : _to->GetInfoForIID(iid, _retval); } \
  NS_IMETHOD GetInfoForName(const char *name, nsIInterfaceInfo **_retval NS_OUTPARAM) { return !_to ? NS_ERROR_NULL_POINTER : _to->GetInfoForName(name, _retval); } \
  NS_IMETHOD GetIIDForName(const char *name, nsIID * *_retval NS_OUTPARAM) { return !_to ? NS_ERROR_NULL_POINTER : _to->GetIIDForName(name, _retval); } \
  NS_IMETHOD GetNameForIID(const nsIID * iid, char **_retval NS_OUTPARAM) { return !_to ? NS_ERROR_NULL_POINTER : _to->GetNameForIID(iid, _retval); } \
  NS_IMETHOD EnumerateInterfaces(nsIEnumerator **_retval NS_OUTPARAM) { return !_to ? NS_ERROR_NULL_POINTER : _to->EnumerateInterfaces(_retval); } \
  NS_IMETHOD AutoRegisterInterfaces(void) { return !_to ? NS_ERROR_NULL_POINTER : _to->AutoRegisterInterfaces(); } \
  NS_IMETHOD EnumerateInterfacesWhoseNamesStartWith(const char *prefix, nsIEnumerator **_retval NS_OUTPARAM) { return !_to ? NS_ERROR_NULL_POINTER : _to->EnumerateInterfacesWhoseNamesStartWith(prefix, _retval); } 

#if 0
/* Use the code below as a template for the implementation class for this interface. */

/* Header file */
class nsInterfaceInfoManager : public nsIInterfaceInfoManager
{
public:
  NS_DECL_ISUPPORTS
  NS_DECL_NSIINTERFACEINFOMANAGER

  nsInterfaceInfoManager();

private:
  ~nsInterfaceInfoManager();

protected:
  /* additional members */
};

/* Implementation file */
NS_IMPL_ISUPPORTS1(nsInterfaceInfoManager, nsIInterfaceInfoManager)

nsInterfaceInfoManager::nsInterfaceInfoManager()
{
  /* member initializers and constructor code */
}

nsInterfaceInfoManager::~nsInterfaceInfoManager()
{
  /* destructor code */
}

/* nsIInterfaceInfo getInfoForIID (in nsIIDPtr iid); */
NS_IMETHODIMP nsInterfaceInfoManager::GetInfoForIID(const nsIID * iid, nsIInterfaceInfo **_retval NS_OUTPARAM)
{
    return NS_ERROR_NOT_IMPLEMENTED;
}

/* nsIInterfaceInfo getInfoForName (in string name); */
NS_IMETHODIMP nsInterfaceInfoManager::GetInfoForName(const char *name, nsIInterfaceInfo **_retval NS_OUTPARAM)
{
    return NS_ERROR_NOT_IMPLEMENTED;
}

/* nsIIDPtr getIIDForName (in string name); */
NS_IMETHODIMP nsInterfaceInfoManager::GetIIDForName(const char *name, nsIID * *_retval NS_OUTPARAM)
{
    return NS_ERROR_NOT_IMPLEMENTED;
}

/* string getNameForIID (in nsIIDPtr iid); */
NS_IMETHODIMP nsInterfaceInfoManager::GetNameForIID(const nsIID * iid, char **_retval NS_OUTPARAM)
{
    return NS_ERROR_NOT_IMPLEMENTED;
}

/* nsIEnumerator enumerateInterfaces (); */
NS_IMETHODIMP nsInterfaceInfoManager::EnumerateInterfaces(nsIEnumerator **_retval NS_OUTPARAM)
{
    return NS_ERROR_NOT_IMPLEMENTED;
}

/* void autoRegisterInterfaces (); */
NS_IMETHODIMP nsInterfaceInfoManager::AutoRegisterInterfaces()
{
    return NS_ERROR_NOT_IMPLEMENTED;
}

/* nsIEnumerator enumerateInterfacesWhoseNamesStartWith (in string prefix); */
NS_IMETHODIMP nsInterfaceInfoManager::EnumerateInterfacesWhoseNamesStartWith(const char *prefix, nsIEnumerator **_retval NS_OUTPARAM)
{
    return NS_ERROR_NOT_IMPLEMENTED;
}

/* End of implementation class template. */
#endif


/* starting interface:    nsIInterfaceInfoSuperManager */
#define NS_IINTERFACEINFOSUPERMANAGER_IID_STR "0ee22850-bc6a-11d5-9134-0010a4e73d9a"

#define NS_IINTERFACEINFOSUPERMANAGER_IID \
  {0x0ee22850, 0xbc6a, 0x11d5, \
    { 0x91, 0x34, 0x00, 0x10, 0xa4, 0xe7, 0x3d, 0x9a }}

class NS_NO_VTABLE nsIInterfaceInfoSuperManager : public nsIInterfaceInfoManager {
 public: 

  NS_DECLARE_STATIC_IID_ACCESSOR(NS_IINTERFACEINFOSUPERMANAGER_IID)

  /* void addAdditionalManager (in nsIInterfaceInfoManager manager); */
  NS_IMETHOD AddAdditionalManager(nsIInterfaceInfoManager *manager) = 0;

  /* void removeAdditionalManager (in nsIInterfaceInfoManager manager); */
  NS_IMETHOD RemoveAdditionalManager(nsIInterfaceInfoManager *manager) = 0;

  /* PRBool hasAdditionalManagers (); */
  NS_IMETHOD HasAdditionalManagers(PRBool *_retval NS_OUTPARAM) = 0;

  /* nsISimpleEnumerator enumerateAdditionalManagers (); */
  NS_IMETHOD EnumerateAdditionalManagers(nsISimpleEnumerator **_retval NS_OUTPARAM) = 0;

};

  NS_DEFINE_STATIC_IID_ACCESSOR(nsIInterfaceInfoSuperManager, NS_IINTERFACEINFOSUPERMANAGER_IID)

/* Use this macro when declaring classes that implement this interface. */
#define NS_DECL_NSIINTERFACEINFOSUPERMANAGER \
  NS_IMETHOD AddAdditionalManager(nsIInterfaceInfoManager *manager); \
  NS_IMETHOD RemoveAdditionalManager(nsIInterfaceInfoManager *manager); \
  NS_IMETHOD HasAdditionalManagers(PRBool *_retval NS_OUTPARAM); \
  NS_IMETHOD EnumerateAdditionalManagers(nsISimpleEnumerator **_retval NS_OUTPARAM); 

/* Use this macro to declare functions that forward the behavior of this interface to another object. */
#define NS_FORWARD_NSIINTERFACEINFOSUPERMANAGER(_to) \
  NS_IMETHOD AddAdditionalManager(nsIInterfaceInfoManager *manager) { return _to AddAdditionalManager(manager); } \
  NS_IMETHOD RemoveAdditionalManager(nsIInterfaceInfoManager *manager) { return _to RemoveAdditionalManager(manager); } \
  NS_IMETHOD HasAdditionalManagers(PRBool *_retval NS_OUTPARAM) { return _to HasAdditionalManagers(_retval); } \
  NS_IMETHOD EnumerateAdditionalManagers(nsISimpleEnumerator **_retval NS_OUTPARAM) { return _to EnumerateAdditionalManagers(_retval); } 

/* Use this macro to declare functions that forward the behavior of this interface to another object in a safe way. */
#define NS_FORWARD_SAFE_NSIINTERFACEINFOSUPERMANAGER(_to) \
  NS_IMETHOD AddAdditionalManager(nsIInterfaceInfoManager *manager) { return !_to ? NS_ERROR_NULL_POINTER : _to->AddAdditionalManager(manager); } \
  NS_IMETHOD RemoveAdditionalManager(nsIInterfaceInfoManager *manager) { return !_to ? NS_ERROR_NULL_POINTER : _to->RemoveAdditionalManager(manager); } \
  NS_IMETHOD HasAdditionalManagers(PRBool *_retval NS_OUTPARAM) { return !_to ? NS_ERROR_NULL_POINTER : _to->HasAdditionalManagers(_retval); } \
  NS_IMETHOD EnumerateAdditionalManagers(nsISimpleEnumerator **_retval NS_OUTPARAM) { return !_to ? NS_ERROR_NULL_POINTER : _to->EnumerateAdditionalManagers(_retval); } 

#if 0
/* Use the code below as a template for the implementation class for this interface. */

/* Header file */
class nsInterfaceInfoSuperManager : public nsIInterfaceInfoSuperManager
{
public:
  NS_DECL_ISUPPORTS
  NS_DECL_NSIINTERFACEINFOSUPERMANAGER

  nsInterfaceInfoSuperManager();

private:
  ~nsInterfaceInfoSuperManager();

protected:
  /* additional members */
};

/* Implementation file */
NS_IMPL_ISUPPORTS1(nsInterfaceInfoSuperManager, nsIInterfaceInfoSuperManager)

nsInterfaceInfoSuperManager::nsInterfaceInfoSuperManager()
{
  /* member initializers and constructor code */
}

nsInterfaceInfoSuperManager::~nsInterfaceInfoSuperManager()
{
  /* destructor code */
}

/* void addAdditionalManager (in nsIInterfaceInfoManager manager); */
NS_IMETHODIMP nsInterfaceInfoSuperManager::AddAdditionalManager(nsIInterfaceInfoManager *manager)
{
    return NS_ERROR_NOT_IMPLEMENTED;
}

/* void removeAdditionalManager (in nsIInterfaceInfoManager manager); */
NS_IMETHODIMP nsInterfaceInfoSuperManager::RemoveAdditionalManager(nsIInterfaceInfoManager *manager)
{
    return NS_ERROR_NOT_IMPLEMENTED;
}

/* PRBool hasAdditionalManagers (); */
NS_IMETHODIMP nsInterfaceInfoSuperManager::HasAdditionalManagers(PRBool *_retval NS_OUTPARAM)
{
    return NS_ERROR_NOT_IMPLEMENTED;
}

/* nsISimpleEnumerator enumerateAdditionalManagers (); */
NS_IMETHODIMP nsInterfaceInfoSuperManager::EnumerateAdditionalManagers(nsISimpleEnumerator **_retval NS_OUTPARAM)
{
    return NS_ERROR_NOT_IMPLEMENTED;
}

/* End of implementation class template. */
#endif

#define NS_INTERFACEINFOMANAGER_SERVICE_CLASSNAME  \
   "Interface Information Manager Service"
#define NS_INTERFACEINFOMANAGER_SERVICE_CID            \
 { /* 13bef784-f8e0-4f96-85c1-09f9ef4f9a19 */          \
  0x13bef784, 0xf8e0, 0x4f96,                          \
  {0x85, 0xc1, 0x09, 0xf9, 0xef, 0x4f, 0x9a, 0x19} }  
#define NS_INTERFACEINFOMANAGER_SERVICE_CONTRACTID  \
   "@mozilla.org/xpti/interfaceinfomanager-service;1"

#endif /* __gen_nsIInterfaceInfoManager_h__ */
