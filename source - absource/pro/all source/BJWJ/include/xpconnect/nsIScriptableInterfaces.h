/*
 * DO NOT EDIT.  THIS FILE IS GENERATED FROM e:/builds/moz2_slave/mozilla-1.9.1-win32-xulrunner/build/js/src/xpconnect/idl/nsIScriptableInterfaces.idl
 */

#ifndef __gen_nsIScriptableInterfaces_h__
#define __gen_nsIScriptableInterfaces_h__


#ifndef __gen_nsISupports_h__
#include "nsISupports.h"
#endif

#ifndef __gen_nsIInterfaceInfoManager_h__
#include "nsIInterfaceInfoManager.h"
#endif

/* For IDL files that don't want to include root IDL files. */
#ifndef NS_NO_VTABLE
#define NS_NO_VTABLE
#endif

/* starting interface:    nsIScriptableInterfaces */
#define NS_ISCRIPTABLEINTERFACES_IID_STR "01c78c65-31da-456b-90bf-da39d09fdcbf"

#define NS_ISCRIPTABLEINTERFACES_IID \
  {0x01c78c65, 0x31da, 0x456b, \
    { 0x90, 0xbf, 0xda, 0x39, 0xd0, 0x9f, 0xdc, 0xbf }}

/**
* Interface used as Components.interfaces (and elsewhere)
* (interesting stuff only reflected into JavaScript)
*/
class NS_NO_VTABLE NS_SCRIPTABLE nsIScriptableInterfaces : public nsISupports {
 public: 

  NS_DECLARE_STATIC_IID_ACCESSOR(NS_ISCRIPTABLEINTERFACES_IID)

  /* [noscript] attribute nsIInterfaceInfoManager manager; */
  NS_IMETHOD GetManager(nsIInterfaceInfoManager * *aManager) = 0;
  NS_IMETHOD SetManager(nsIInterfaceInfoManager * aManager) = 0;

};

  NS_DEFINE_STATIC_IID_ACCESSOR(nsIScriptableInterfaces, NS_ISCRIPTABLEINTERFACES_IID)

/* Use this macro when declaring classes that implement this interface. */
#define NS_DECL_NSISCRIPTABLEINTERFACES \
  NS_IMETHOD GetManager(nsIInterfaceInfoManager * *aManager); \
  NS_IMETHOD SetManager(nsIInterfaceInfoManager * aManager); 

/* Use this macro to declare functions that forward the behavior of this interface to another object. */
#define NS_FORWARD_NSISCRIPTABLEINTERFACES(_to) \
  NS_IMETHOD GetManager(nsIInterfaceInfoManager * *aManager) { return _to GetManager(aManager); } \
  NS_IMETHOD SetManager(nsIInterfaceInfoManager * aManager) { return _to SetManager(aManager); } 

/* Use this macro to declare functions that forward the behavior of this interface to another object in a safe way. */
#define NS_FORWARD_SAFE_NSISCRIPTABLEINTERFACES(_to) \
  NS_IMETHOD GetManager(nsIInterfaceInfoManager * *aManager) { return !_to ? NS_ERROR_NULL_POINTER : _to->GetManager(aManager); } \
  NS_IMETHOD SetManager(nsIInterfaceInfoManager * aManager) { return !_to ? NS_ERROR_NULL_POINTER : _to->SetManager(aManager); } 

#if 0
/* Use the code below as a template for the implementation class for this interface. */

/* Header file */
class nsScriptableInterfaces : public nsIScriptableInterfaces
{
public:
  NS_DECL_ISUPPORTS
  NS_DECL_NSISCRIPTABLEINTERFACES

  nsScriptableInterfaces();

private:
  ~nsScriptableInterfaces();

protected:
  /* additional members */
};

/* Implementation file */
NS_IMPL_ISUPPORTS1(nsScriptableInterfaces, nsIScriptableInterfaces)

nsScriptableInterfaces::nsScriptableInterfaces()
{
  /* member initializers and constructor code */
}

nsScriptableInterfaces::~nsScriptableInterfaces()
{
  /* destructor code */
}

/* [noscript] attribute nsIInterfaceInfoManager manager; */
NS_IMETHODIMP nsScriptableInterfaces::GetManager(nsIInterfaceInfoManager * *aManager)
{
    return NS_ERROR_NOT_IMPLEMENTED;
}
NS_IMETHODIMP nsScriptableInterfaces::SetManager(nsIInterfaceInfoManager * aManager)
{
    return NS_ERROR_NOT_IMPLEMENTED;
}

/* End of implementation class template. */
#endif

// The contractID for the implementation built into xpconnect
#define NS_SCRIPTABLE_INTERFACES_CONTRACTID "@mozilla.org/scriptableinterfaces;1"

/* starting interface:    nsIScriptableInterfacesByID */
#define NS_ISCRIPTABLEINTERFACESBYID_IID_STR "c99cffac-5aed-4267-ad2f-f4a4c9d4a081"

#define NS_ISCRIPTABLEINTERFACESBYID_IID \
  {0xc99cffac, 0x5aed, 0x4267, \
    { 0xad, 0x2f, 0xf4, 0xa4, 0xc9, 0xd4, 0xa0, 0x81 }}

/**
* interface of Components.interfacesByID
* (interesting stuff only reflected into JavaScript)
*/
class NS_NO_VTABLE NS_SCRIPTABLE nsIScriptableInterfacesByID : public nsISupports {
 public: 

  NS_DECLARE_STATIC_IID_ACCESSOR(NS_ISCRIPTABLEINTERFACESBYID_IID)

};

  NS_DEFINE_STATIC_IID_ACCESSOR(nsIScriptableInterfacesByID, NS_ISCRIPTABLEINTERFACESBYID_IID)

/* Use this macro when declaring classes that implement this interface. */
#define NS_DECL_NSISCRIPTABLEINTERFACESBYID \
  /* no methods! */

/* Use this macro to declare functions that forward the behavior of this interface to another object. */
#define NS_FORWARD_NSISCRIPTABLEINTERFACESBYID(_to) \
  /* no methods! */

/* Use this macro to declare functions that forward the behavior of this interface to another object in a safe way. */
#define NS_FORWARD_SAFE_NSISCRIPTABLEINTERFACESBYID(_to) \
  /* no methods! */

#if 0
/* Use the code below as a template for the implementation class for this interface. */

/* Header file */
class nsScriptableInterfacesByID : public nsIScriptableInterfacesByID
{
public:
  NS_DECL_ISUPPORTS
  NS_DECL_NSISCRIPTABLEINTERFACESBYID

  nsScriptableInterfacesByID();

private:
  ~nsScriptableInterfacesByID();

protected:
  /* additional members */
};

/* Implementation file */
NS_IMPL_ISUPPORTS1(nsScriptableInterfacesByID, nsIScriptableInterfacesByID)

nsScriptableInterfacesByID::nsScriptableInterfacesByID()
{
  /* member initializers and constructor code */
}

nsScriptableInterfacesByID::~nsScriptableInterfacesByID()
{
  /* destructor code */
}

/* End of implementation class template. */
#endif


#endif /* __gen_nsIScriptableInterfaces_h__ */
