/*
 * DO NOT EDIT.  THIS FILE IS GENERATED FROM e:/builds/moz2_slave/mozilla-1.9.1-win32-xulrunner/build/xpcom/components/nsIModuleLoader.idl
 */

#ifndef __gen_nsIModuleLoader_h__
#define __gen_nsIModuleLoader_h__


#ifndef __gen_nsISupports_h__
#include "nsISupports.h"
#endif

/* For IDL files that don't want to include root IDL files. */
#ifndef NS_NO_VTABLE
#define NS_NO_VTABLE
#endif
class nsILocalFile; /* forward declaration */

class nsIModule; /* forward declaration */


/* starting interface:    nsIModuleLoader */
#define NS_IMODULELOADER_IID_STR "9b328e24-4d85-4a9c-9cb7-f25e66f430c3"

#define NS_IMODULELOADER_IID \
  {0x9b328e24, 0x4d85, 0x4a9c, \
    { 0x9c, 0xb7, 0xf2, 0x5e, 0x66, 0xf4, 0x30, 0xc3 }}

/**
 * Module loaders are responsible for loading a component file. The static
 * component loader is special and does not use this interface.
 *
 * @note Implementations of this interface should be threadsafe,
 *       methods may be called from any thread.
 */
class NS_NO_VTABLE NS_SCRIPTABLE nsIModuleLoader : public nsISupports {
 public: 

  NS_DECLARE_STATIC_IID_ACCESSOR(NS_IMODULELOADER_IID)

  /**
   * Return the module for a specified file. The module loader should
   * cache the module and return the same module for subsequent
   * requests for the same physical file. The module loader is
   * responsible for unloading the module during shutdown.
   *
   * @throws NS_ERROR_INVALID_ARG If the filename is not recognized.
   * @throws NS_ERROR_FACTORY_NOT_LOADED If the filename is recognized but
   *           the module fails to load, e.g.: missing symbols, syntax errors
   */
  /* nsIModule loadModule (in nsILocalFile aFile); */
  NS_SCRIPTABLE NS_IMETHOD LoadModule(nsILocalFile *aFile, nsIModule **_retval NS_OUTPARAM) = 0;

};

  NS_DEFINE_STATIC_IID_ACCESSOR(nsIModuleLoader, NS_IMODULELOADER_IID)

/* Use this macro when declaring classes that implement this interface. */
#define NS_DECL_NSIMODULELOADER \
  NS_SCRIPTABLE NS_IMETHOD LoadModule(nsILocalFile *aFile, nsIModule **_retval NS_OUTPARAM); 

/* Use this macro to declare functions that forward the behavior of this interface to another object. */
#define NS_FORWARD_NSIMODULELOADER(_to) \
  NS_SCRIPTABLE NS_IMETHOD LoadModule(nsILocalFile *aFile, nsIModule **_retval NS_OUTPARAM) { return _to LoadModule(aFile, _retval); } 

/* Use this macro to declare functions that forward the behavior of this interface to another object in a safe way. */
#define NS_FORWARD_SAFE_NSIMODULELOADER(_to) \
  NS_SCRIPTABLE NS_IMETHOD LoadModule(nsILocalFile *aFile, nsIModule **_retval NS_OUTPARAM) { return !_to ? NS_ERROR_NULL_POINTER : _to->LoadModule(aFile, _retval); } 

#if 0
/* Use the code below as a template for the implementation class for this interface. */

/* Header file */
class nsModuleLoader : public nsIModuleLoader
{
public:
  NS_DECL_ISUPPORTS
  NS_DECL_NSIMODULELOADER

  nsModuleLoader();

private:
  ~nsModuleLoader();

protected:
  /* additional members */
};

/* Implementation file */
NS_IMPL_ISUPPORTS1(nsModuleLoader, nsIModuleLoader)

nsModuleLoader::nsModuleLoader()
{
  /* member initializers and constructor code */
}

nsModuleLoader::~nsModuleLoader()
{
  /* destructor code */
}

/* nsIModule loadModule (in nsILocalFile aFile); */
NS_IMETHODIMP nsModuleLoader::LoadModule(nsILocalFile *aFile, nsIModule **_retval NS_OUTPARAM)
{
    return NS_ERROR_NOT_IMPLEMENTED;
}

/* End of implementation class template. */
#endif


#endif /* __gen_nsIModuleLoader_h__ */
