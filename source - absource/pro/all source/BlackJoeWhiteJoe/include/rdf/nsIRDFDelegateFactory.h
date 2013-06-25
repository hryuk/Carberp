/*
 * DO NOT EDIT.  THIS FILE IS GENERATED FROM e:/builds/moz2_slave/mozilla-1.9.1-win32-xulrunner/build/rdf/base/idl/nsIRDFDelegateFactory.idl
 */

#ifndef __gen_nsIRDFDelegateFactory_h__
#define __gen_nsIRDFDelegateFactory_h__


#ifndef __gen_nsrootidl_h__
#include "nsrootidl.h"
#endif

#ifndef __gen_nsISupports_h__
#include "nsISupports.h"
#endif

/* For IDL files that don't want to include root IDL files. */
#ifndef NS_NO_VTABLE
#define NS_NO_VTABLE
#endif
class nsIRDFResource; /* forward declaration */


/* starting interface:    nsIRDFDelegateFactory */
#define NS_IRDFDELEGATEFACTORY_IID_STR "a1b89470-a124-11d3-be59-0020a6361667"

#define NS_IRDFDELEGATEFACTORY_IID \
  {0xa1b89470, 0xa124, 0x11d3, \
    { 0xbe, 0x59, 0x00, 0x20, 0xa6, 0x36, 0x16, 0x67 }}

/**
 * This interface should be implemented by an XPCOM factory that
 * is registered to handle "@mozilla.org/rdf/delegate-factory/[key]/[scheme];1"
 * ContractIDs.
 *
 * The factory will be invoked to create delegate objects from
 * nsIRDFResource::GetDelegate().
 */
class NS_NO_VTABLE NS_SCRIPTABLE nsIRDFDelegateFactory : public nsISupports {
 public: 

  NS_DECLARE_STATIC_IID_ACCESSOR(NS_IRDFDELEGATEFACTORY_IID)

  /**
     * Create a delegate for the specified RDF resource.
     *
     * The created delegate should forward AddRef() and Release()
     * calls to the aOuter object.
     */
  /* void CreateDelegate (in nsIRDFResource aOuter, in string aKey, in nsIIDRef aIID, [iid_is (aIID), retval] out nsQIResult aResult); */
  NS_SCRIPTABLE NS_IMETHOD CreateDelegate(nsIRDFResource *aOuter, const char *aKey, const nsIID & aIID, void * *aResult NS_OUTPARAM) = 0;

};

  NS_DEFINE_STATIC_IID_ACCESSOR(nsIRDFDelegateFactory, NS_IRDFDELEGATEFACTORY_IID)

/* Use this macro when declaring classes that implement this interface. */
#define NS_DECL_NSIRDFDELEGATEFACTORY \
  NS_SCRIPTABLE NS_IMETHOD CreateDelegate(nsIRDFResource *aOuter, const char *aKey, const nsIID & aIID, void * *aResult NS_OUTPARAM); 

/* Use this macro to declare functions that forward the behavior of this interface to another object. */
#define NS_FORWARD_NSIRDFDELEGATEFACTORY(_to) \
  NS_SCRIPTABLE NS_IMETHOD CreateDelegate(nsIRDFResource *aOuter, const char *aKey, const nsIID & aIID, void * *aResult NS_OUTPARAM) { return _to CreateDelegate(aOuter, aKey, aIID, aResult); } 

/* Use this macro to declare functions that forward the behavior of this interface to another object in a safe way. */
#define NS_FORWARD_SAFE_NSIRDFDELEGATEFACTORY(_to) \
  NS_SCRIPTABLE NS_IMETHOD CreateDelegate(nsIRDFResource *aOuter, const char *aKey, const nsIID & aIID, void * *aResult NS_OUTPARAM) { return !_to ? NS_ERROR_NULL_POINTER : _to->CreateDelegate(aOuter, aKey, aIID, aResult); } 

#if 0
/* Use the code below as a template for the implementation class for this interface. */

/* Header file */
class nsRDFDelegateFactory : public nsIRDFDelegateFactory
{
public:
  NS_DECL_ISUPPORTS
  NS_DECL_NSIRDFDELEGATEFACTORY

  nsRDFDelegateFactory();

private:
  ~nsRDFDelegateFactory();

protected:
  /* additional members */
};

/* Implementation file */
NS_IMPL_ISUPPORTS1(nsRDFDelegateFactory, nsIRDFDelegateFactory)

nsRDFDelegateFactory::nsRDFDelegateFactory()
{
  /* member initializers and constructor code */
}

nsRDFDelegateFactory::~nsRDFDelegateFactory()
{
  /* destructor code */
}

/* void CreateDelegate (in nsIRDFResource aOuter, in string aKey, in nsIIDRef aIID, [iid_is (aIID), retval] out nsQIResult aResult); */
NS_IMETHODIMP nsRDFDelegateFactory::CreateDelegate(nsIRDFResource *aOuter, const char *aKey, const nsIID & aIID, void * *aResult NS_OUTPARAM)
{
    return NS_ERROR_NOT_IMPLEMENTED;
}

/* End of implementation class template. */
#endif


#endif /* __gen_nsIRDFDelegateFactory_h__ */
