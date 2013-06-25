/*
 * DO NOT EDIT.  THIS FILE IS GENERATED FROM e:/builds/moz2_slave/mozilla-1.9.1-win32-xulrunner/build/modules/plugin/base/public/nsIClassicPluginFactory.idl
 */

#ifndef __gen_nsIClassicPluginFactory_h__
#define __gen_nsIClassicPluginFactory_h__


#ifndef __gen_nsISupports_h__
#include "nsISupports.h"
#endif

/* For IDL files that don't want to include root IDL files. */
#ifndef NS_NO_VTABLE
#define NS_NO_VTABLE
#endif
#include "nsplugindefs.h"
// {a55d21ca-1dd1-11b2-9b0f-8fe1adaf129d}
#define NS_CLASSIC_PLUGIN_FACTORY_CID \
{ 0xa55d21ca, 0x1dd1, 0x11b2, { 0x9b, 0x0f, 0x8f, 0xe1, 0xad, 0xaf, 0x12, 0x9d } }
// Prefix for ContractID of all plugins
#define NS_CLASSIC_PLUGIN_FACTORY_CONTRACTID "@mozilla.org/plugin/classicpluginfactory;1"
struct PRLibrary;
class nsIServiceManagerObsolete; /* forward declaration */

class nsIPlugin; /* forward declaration */


/* starting interface:    nsIClassicPluginFactory */
#define NS_ICLASSICPLUGINFACTORY_IID_STR "07bfa284-1dd2-11b2-90f8-fef5608e8a56"

#define NS_ICLASSICPLUGINFACTORY_IID \
  {0x07bfa284, 0x1dd2, 0x11b2, \
    { 0x90, 0xf8, 0xfe, 0xf5, 0x60, 0x8e, 0x8a, 0x56 }}

class NS_NO_VTABLE nsIClassicPluginFactory : public nsISupports {
 public: 

  NS_DECLARE_STATIC_IID_ACCESSOR(NS_ICLASSICPLUGINFACTORY_IID)

  /**
  * A factory method for constructing 4.x plugins. 
  * Constructs and initializes an ns4xPlugin object
  */
  /* void createPlugin (in nsIServiceManagerObsolete aServiceMgr, in string aFileName, in string aFullPath, in PRLibraryPtr aLibrary, out nsIPlugin aResult); */
  NS_IMETHOD CreatePlugin(nsIServiceManagerObsolete *aServiceMgr, const char *aFileName, const char *aFullPath, PRLibrary * aLibrary, nsIPlugin **aResult NS_OUTPARAM) = 0;

};

  NS_DEFINE_STATIC_IID_ACCESSOR(nsIClassicPluginFactory, NS_ICLASSICPLUGINFACTORY_IID)

/* Use this macro when declaring classes that implement this interface. */
#define NS_DECL_NSICLASSICPLUGINFACTORY \
  NS_IMETHOD CreatePlugin(nsIServiceManagerObsolete *aServiceMgr, const char *aFileName, const char *aFullPath, PRLibrary * aLibrary, nsIPlugin **aResult NS_OUTPARAM); 

/* Use this macro to declare functions that forward the behavior of this interface to another object. */
#define NS_FORWARD_NSICLASSICPLUGINFACTORY(_to) \
  NS_IMETHOD CreatePlugin(nsIServiceManagerObsolete *aServiceMgr, const char *aFileName, const char *aFullPath, PRLibrary * aLibrary, nsIPlugin **aResult NS_OUTPARAM) { return _to CreatePlugin(aServiceMgr, aFileName, aFullPath, aLibrary, aResult); } 

/* Use this macro to declare functions that forward the behavior of this interface to another object in a safe way. */
#define NS_FORWARD_SAFE_NSICLASSICPLUGINFACTORY(_to) \
  NS_IMETHOD CreatePlugin(nsIServiceManagerObsolete *aServiceMgr, const char *aFileName, const char *aFullPath, PRLibrary * aLibrary, nsIPlugin **aResult NS_OUTPARAM) { return !_to ? NS_ERROR_NULL_POINTER : _to->CreatePlugin(aServiceMgr, aFileName, aFullPath, aLibrary, aResult); } 

#if 0
/* Use the code below as a template for the implementation class for this interface. */

/* Header file */
class nsClassicPluginFactory : public nsIClassicPluginFactory
{
public:
  NS_DECL_ISUPPORTS
  NS_DECL_NSICLASSICPLUGINFACTORY

  nsClassicPluginFactory();

private:
  ~nsClassicPluginFactory();

protected:
  /* additional members */
};

/* Implementation file */
NS_IMPL_ISUPPORTS1(nsClassicPluginFactory, nsIClassicPluginFactory)

nsClassicPluginFactory::nsClassicPluginFactory()
{
  /* member initializers and constructor code */
}

nsClassicPluginFactory::~nsClassicPluginFactory()
{
  /* destructor code */
}

/* void createPlugin (in nsIServiceManagerObsolete aServiceMgr, in string aFileName, in string aFullPath, in PRLibraryPtr aLibrary, out nsIPlugin aResult); */
NS_IMETHODIMP nsClassicPluginFactory::CreatePlugin(nsIServiceManagerObsolete *aServiceMgr, const char *aFileName, const char *aFullPath, PRLibrary * aLibrary, nsIPlugin **aResult NS_OUTPARAM)
{
    return NS_ERROR_NOT_IMPLEMENTED;
}

/* End of implementation class template. */
#endif


#endif /* __gen_nsIClassicPluginFactory_h__ */
