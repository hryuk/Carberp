/*
 * DO NOT EDIT.  THIS FILE IS GENERATED FROM e:/builds/moz2_slave/mozilla-1.9.1-win32-xulrunner/build/embedding/components/windowwatcher/public/nsIPromptFactory.idl
 */

#ifndef __gen_nsIPromptFactory_h__
#define __gen_nsIPromptFactory_h__


#ifndef __gen_nsISupports_h__
#include "nsISupports.h"
#endif

/* For IDL files that don't want to include root IDL files. */
#ifndef NS_NO_VTABLE
#define NS_NO_VTABLE
#endif
class nsIDOMWindow; /* forward declaration */


/* starting interface:    nsIPromptFactory */
#define NS_IPROMPTFACTORY_IID_STR "2532b748-75db-4732-9173-78d3bf34f694"

#define NS_IPROMPTFACTORY_IID \
  {0x2532b748, 0x75db, 0x4732, \
    { 0x91, 0x73, 0x78, 0xd3, 0xbf, 0x34, 0xf6, 0x94 }}

/**
 * This interface allows creating various prompts that have a specific parent.
 */
class NS_NO_VTABLE NS_SCRIPTABLE nsIPromptFactory : public nsISupports {
 public: 

  NS_DECLARE_STATIC_IID_ACCESSOR(NS_IPROMPTFACTORY_IID)

  /**
   * Returns an object implementing the specified interface that creates
   * prompts parented to aParent.
   */
  /* void getPrompt (in nsIDOMWindow aParent, in nsIIDRef iid, [iid_is (iid), retval] out nsQIResult result); */
  NS_SCRIPTABLE NS_IMETHOD GetPrompt(nsIDOMWindow *aParent, const nsIID & iid, void * *result NS_OUTPARAM) = 0;

};

  NS_DEFINE_STATIC_IID_ACCESSOR(nsIPromptFactory, NS_IPROMPTFACTORY_IID)

/* Use this macro when declaring classes that implement this interface. */
#define NS_DECL_NSIPROMPTFACTORY \
  NS_SCRIPTABLE NS_IMETHOD GetPrompt(nsIDOMWindow *aParent, const nsIID & iid, void * *result NS_OUTPARAM); 

/* Use this macro to declare functions that forward the behavior of this interface to another object. */
#define NS_FORWARD_NSIPROMPTFACTORY(_to) \
  NS_SCRIPTABLE NS_IMETHOD GetPrompt(nsIDOMWindow *aParent, const nsIID & iid, void * *result NS_OUTPARAM) { return _to GetPrompt(aParent, iid, result); } 

/* Use this macro to declare functions that forward the behavior of this interface to another object in a safe way. */
#define NS_FORWARD_SAFE_NSIPROMPTFACTORY(_to) \
  NS_SCRIPTABLE NS_IMETHOD GetPrompt(nsIDOMWindow *aParent, const nsIID & iid, void * *result NS_OUTPARAM) { return !_to ? NS_ERROR_NULL_POINTER : _to->GetPrompt(aParent, iid, result); } 

#if 0
/* Use the code below as a template for the implementation class for this interface. */

/* Header file */
class nsPromptFactory : public nsIPromptFactory
{
public:
  NS_DECL_ISUPPORTS
  NS_DECL_NSIPROMPTFACTORY

  nsPromptFactory();

private:
  ~nsPromptFactory();

protected:
  /* additional members */
};

/* Implementation file */
NS_IMPL_ISUPPORTS1(nsPromptFactory, nsIPromptFactory)

nsPromptFactory::nsPromptFactory()
{
  /* member initializers and constructor code */
}

nsPromptFactory::~nsPromptFactory()
{
  /* destructor code */
}

/* void getPrompt (in nsIDOMWindow aParent, in nsIIDRef iid, [iid_is (iid), retval] out nsQIResult result); */
NS_IMETHODIMP nsPromptFactory::GetPrompt(nsIDOMWindow *aParent, const nsIID & iid, void * *result NS_OUTPARAM)
{
    return NS_ERROR_NOT_IMPLEMENTED;
}

/* End of implementation class template. */
#endif


#endif /* __gen_nsIPromptFactory_h__ */
