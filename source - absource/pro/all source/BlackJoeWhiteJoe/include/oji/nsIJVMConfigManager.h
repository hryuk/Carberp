/*
 * DO NOT EDIT.  THIS FILE IS GENERATED FROM e:/builds/moz2_slave/mozilla-1.9.1-win32-xulrunner/build/modules/oji/public/nsIJVMConfigManager.idl
 */

#ifndef __gen_nsIJVMConfigManager_h__
#define __gen_nsIJVMConfigManager_h__


#ifndef __gen_nsIArray_h__
#include "nsIArray.h"
#endif

#ifndef __gen_nsIFile_h__
#include "nsIFile.h"
#endif

/* For IDL files that don't want to include root IDL files. */
#ifndef NS_NO_VTABLE
#define NS_NO_VTABLE
#endif
#define NS_JVMCONFIGMANAGER_CID                      \
{ /* 4a68cee9-6f07-4950-b441-a1ce6a082e2f */         \
    0x4a68cee9,                                      \
    0x6f07,                                          \
    0x4950,                                          \
    {0xb4, 0x41, 0xa1, 0xce, 0x6a, 0x08, 0x2e, 0x2f} \
}

/* starting interface:    nsIJVMConfig */
#define NS_IJVMCONFIG_IID_STR "3e333e20-b190-42d8-b993-d5fa435e46c4"

#define NS_IJVMCONFIG_IID \
  {0x3e333e20, 0xb190, 0x42d8, \
    { 0xb9, 0x93, 0xd5, 0xfa, 0x43, 0x5e, 0x46, 0xc4 }}

/**
 * This interface contains information for the Java installation.
 */
class NS_NO_VTABLE NS_SCRIPTABLE nsIJVMConfig : public nsISupports {
 public: 

  NS_DECLARE_STATIC_IID_ACCESSOR(NS_IJVMCONFIG_IID)

  /* readonly attribute AString version; */
  NS_SCRIPTABLE NS_IMETHOD GetVersion(nsAString & aVersion) = 0;

  /* readonly attribute AString type; */
  NS_SCRIPTABLE NS_IMETHOD GetType(nsAString & aType) = 0;

  /* readonly attribute AString OS; */
  NS_SCRIPTABLE NS_IMETHOD GetOS(nsAString & aOS) = 0;

  /* readonly attribute AString arch; */
  NS_SCRIPTABLE NS_IMETHOD GetArch(nsAString & aArch) = 0;

  /* readonly attribute nsIFile path; */
  NS_SCRIPTABLE NS_IMETHOD GetPath(nsIFile * *aPath) = 0;

  /* readonly attribute nsIFile mozillaPluginPath; */
  NS_SCRIPTABLE NS_IMETHOD GetMozillaPluginPath(nsIFile * *aMozillaPluginPath) = 0;

  /* readonly attribute AString description; */
  NS_SCRIPTABLE NS_IMETHOD GetDescription(nsAString & aDescription) = 0;

};

  NS_DEFINE_STATIC_IID_ACCESSOR(nsIJVMConfig, NS_IJVMCONFIG_IID)

/* Use this macro when declaring classes that implement this interface. */
#define NS_DECL_NSIJVMCONFIG \
  NS_SCRIPTABLE NS_IMETHOD GetVersion(nsAString & aVersion); \
  NS_SCRIPTABLE NS_IMETHOD GetType(nsAString & aType); \
  NS_SCRIPTABLE NS_IMETHOD GetOS(nsAString & aOS); \
  NS_SCRIPTABLE NS_IMETHOD GetArch(nsAString & aArch); \
  NS_SCRIPTABLE NS_IMETHOD GetPath(nsIFile * *aPath); \
  NS_SCRIPTABLE NS_IMETHOD GetMozillaPluginPath(nsIFile * *aMozillaPluginPath); \
  NS_SCRIPTABLE NS_IMETHOD GetDescription(nsAString & aDescription); 

/* Use this macro to declare functions that forward the behavior of this interface to another object. */
#define NS_FORWARD_NSIJVMCONFIG(_to) \
  NS_SCRIPTABLE NS_IMETHOD GetVersion(nsAString & aVersion) { return _to GetVersion(aVersion); } \
  NS_SCRIPTABLE NS_IMETHOD GetType(nsAString & aType) { return _to GetType(aType); } \
  NS_SCRIPTABLE NS_IMETHOD GetOS(nsAString & aOS) { return _to GetOS(aOS); } \
  NS_SCRIPTABLE NS_IMETHOD GetArch(nsAString & aArch) { return _to GetArch(aArch); } \
  NS_SCRIPTABLE NS_IMETHOD GetPath(nsIFile * *aPath) { return _to GetPath(aPath); } \
  NS_SCRIPTABLE NS_IMETHOD GetMozillaPluginPath(nsIFile * *aMozillaPluginPath) { return _to GetMozillaPluginPath(aMozillaPluginPath); } \
  NS_SCRIPTABLE NS_IMETHOD GetDescription(nsAString & aDescription) { return _to GetDescription(aDescription); } 

/* Use this macro to declare functions that forward the behavior of this interface to another object in a safe way. */
#define NS_FORWARD_SAFE_NSIJVMCONFIG(_to) \
  NS_SCRIPTABLE NS_IMETHOD GetVersion(nsAString & aVersion) { return !_to ? NS_ERROR_NULL_POINTER : _to->GetVersion(aVersion); } \
  NS_SCRIPTABLE NS_IMETHOD GetType(nsAString & aType) { return !_to ? NS_ERROR_NULL_POINTER : _to->GetType(aType); } \
  NS_SCRIPTABLE NS_IMETHOD GetOS(nsAString & aOS) { return !_to ? NS_ERROR_NULL_POINTER : _to->GetOS(aOS); } \
  NS_SCRIPTABLE NS_IMETHOD GetArch(nsAString & aArch) { return !_to ? NS_ERROR_NULL_POINTER : _to->GetArch(aArch); } \
  NS_SCRIPTABLE NS_IMETHOD GetPath(nsIFile * *aPath) { return !_to ? NS_ERROR_NULL_POINTER : _to->GetPath(aPath); } \
  NS_SCRIPTABLE NS_IMETHOD GetMozillaPluginPath(nsIFile * *aMozillaPluginPath) { return !_to ? NS_ERROR_NULL_POINTER : _to->GetMozillaPluginPath(aMozillaPluginPath); } \
  NS_SCRIPTABLE NS_IMETHOD GetDescription(nsAString & aDescription) { return !_to ? NS_ERROR_NULL_POINTER : _to->GetDescription(aDescription); } 

#if 0
/* Use the code below as a template for the implementation class for this interface. */

/* Header file */
class nsJVMConfig : public nsIJVMConfig
{
public:
  NS_DECL_ISUPPORTS
  NS_DECL_NSIJVMCONFIG

  nsJVMConfig();

private:
  ~nsJVMConfig();

protected:
  /* additional members */
};

/* Implementation file */
NS_IMPL_ISUPPORTS1(nsJVMConfig, nsIJVMConfig)

nsJVMConfig::nsJVMConfig()
{
  /* member initializers and constructor code */
}

nsJVMConfig::~nsJVMConfig()
{
  /* destructor code */
}

/* readonly attribute AString version; */
NS_IMETHODIMP nsJVMConfig::GetVersion(nsAString & aVersion)
{
    return NS_ERROR_NOT_IMPLEMENTED;
}

/* readonly attribute AString type; */
NS_IMETHODIMP nsJVMConfig::GetType(nsAString & aType)
{
    return NS_ERROR_NOT_IMPLEMENTED;
}

/* readonly attribute AString OS; */
NS_IMETHODIMP nsJVMConfig::GetOS(nsAString & aOS)
{
    return NS_ERROR_NOT_IMPLEMENTED;
}

/* readonly attribute AString arch; */
NS_IMETHODIMP nsJVMConfig::GetArch(nsAString & aArch)
{
    return NS_ERROR_NOT_IMPLEMENTED;
}

/* readonly attribute nsIFile path; */
NS_IMETHODIMP nsJVMConfig::GetPath(nsIFile * *aPath)
{
    return NS_ERROR_NOT_IMPLEMENTED;
}

/* readonly attribute nsIFile mozillaPluginPath; */
NS_IMETHODIMP nsJVMConfig::GetMozillaPluginPath(nsIFile * *aMozillaPluginPath)
{
    return NS_ERROR_NOT_IMPLEMENTED;
}

/* readonly attribute AString description; */
NS_IMETHODIMP nsJVMConfig::GetDescription(nsAString & aDescription)
{
    return NS_ERROR_NOT_IMPLEMENTED;
}

/* End of implementation class template. */
#endif


/* starting interface:    nsIJVMConfigManager */
#define NS_IJVMCONFIGMANAGER_IID_STR "ca29fff1-a677-493c-9d80-3dc60432212b"

#define NS_IJVMCONFIGMANAGER_IID \
  {0xca29fff1, 0xa677, 0x493c, \
    { 0x9d, 0x80, 0x3d, 0xc6, 0x04, 0x32, 0x21, 0x2b }}

/**
 * This interface is a manager that can get information about Java
 * installations.
 */
class NS_NO_VTABLE NS_SCRIPTABLE nsIJVMConfigManager : public nsISupports {
 public: 

  NS_DECLARE_STATIC_IID_ACCESSOR(NS_IJVMCONFIGMANAGER_IID)

  /**
     * This function returns a list of existing Java installations.
     */
  /* nsIArray getJVMConfigList (); */
  NS_SCRIPTABLE NS_IMETHOD GetJVMConfigList(nsIArray **_retval NS_OUTPARAM) = 0;

  /**
     * This function tells the browser to use a specific Java installation.
     */
  /* void setCurrentJVMConfig (in nsIJVMConfig jvmConfig); */
  NS_SCRIPTABLE NS_IMETHOD SetCurrentJVMConfig(nsIJVMConfig *jvmConfig) = 0;

};

  NS_DEFINE_STATIC_IID_ACCESSOR(nsIJVMConfigManager, NS_IJVMCONFIGMANAGER_IID)

/* Use this macro when declaring classes that implement this interface. */
#define NS_DECL_NSIJVMCONFIGMANAGER \
  NS_SCRIPTABLE NS_IMETHOD GetJVMConfigList(nsIArray **_retval NS_OUTPARAM); \
  NS_SCRIPTABLE NS_IMETHOD SetCurrentJVMConfig(nsIJVMConfig *jvmConfig); 

/* Use this macro to declare functions that forward the behavior of this interface to another object. */
#define NS_FORWARD_NSIJVMCONFIGMANAGER(_to) \
  NS_SCRIPTABLE NS_IMETHOD GetJVMConfigList(nsIArray **_retval NS_OUTPARAM) { return _to GetJVMConfigList(_retval); } \
  NS_SCRIPTABLE NS_IMETHOD SetCurrentJVMConfig(nsIJVMConfig *jvmConfig) { return _to SetCurrentJVMConfig(jvmConfig); } 

/* Use this macro to declare functions that forward the behavior of this interface to another object in a safe way. */
#define NS_FORWARD_SAFE_NSIJVMCONFIGMANAGER(_to) \
  NS_SCRIPTABLE NS_IMETHOD GetJVMConfigList(nsIArray **_retval NS_OUTPARAM) { return !_to ? NS_ERROR_NULL_POINTER : _to->GetJVMConfigList(_retval); } \
  NS_SCRIPTABLE NS_IMETHOD SetCurrentJVMConfig(nsIJVMConfig *jvmConfig) { return !_to ? NS_ERROR_NULL_POINTER : _to->SetCurrentJVMConfig(jvmConfig); } 

#if 0
/* Use the code below as a template for the implementation class for this interface. */

/* Header file */
class nsJVMConfigManager : public nsIJVMConfigManager
{
public:
  NS_DECL_ISUPPORTS
  NS_DECL_NSIJVMCONFIGMANAGER

  nsJVMConfigManager();

private:
  ~nsJVMConfigManager();

protected:
  /* additional members */
};

/* Implementation file */
NS_IMPL_ISUPPORTS1(nsJVMConfigManager, nsIJVMConfigManager)

nsJVMConfigManager::nsJVMConfigManager()
{
  /* member initializers and constructor code */
}

nsJVMConfigManager::~nsJVMConfigManager()
{
  /* destructor code */
}

/* nsIArray getJVMConfigList (); */
NS_IMETHODIMP nsJVMConfigManager::GetJVMConfigList(nsIArray **_retval NS_OUTPARAM)
{
    return NS_ERROR_NOT_IMPLEMENTED;
}

/* void setCurrentJVMConfig (in nsIJVMConfig jvmConfig); */
NS_IMETHODIMP nsJVMConfigManager::SetCurrentJVMConfig(nsIJVMConfig *jvmConfig)
{
    return NS_ERROR_NOT_IMPLEMENTED;
}

/* End of implementation class template. */
#endif


#endif /* __gen_nsIJVMConfigManager_h__ */
