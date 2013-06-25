/*
 * DO NOT EDIT.  THIS FILE IS GENERATED FROM e:/builds/moz2_slave/mozilla-1.9.1-win32-xulrunner/build/netwerk/base/public/nsIAuthPromptAdapterFactory.idl
 */

#ifndef __gen_nsIAuthPromptAdapterFactory_h__
#define __gen_nsIAuthPromptAdapterFactory_h__


#ifndef __gen_nsISupports_h__
#include "nsISupports.h"
#endif

/* For IDL files that don't want to include root IDL files. */
#ifndef NS_NO_VTABLE
#define NS_NO_VTABLE
#endif
class nsIAuthPrompt; /* forward declaration */

class nsIAuthPrompt2; /* forward declaration */


/* starting interface:    nsIAuthPromptAdapterFactory */
#define NS_IAUTHPROMPTADAPTERFACTORY_IID_STR "60e46383-bb9a-4860-8962-80d9c5c05ddc"

#define NS_IAUTHPROMPTADAPTERFACTORY_IID \
  {0x60e46383, 0xbb9a, 0x4860, \
    { 0x89, 0x62, 0x80, 0xd9, 0xc5, 0xc0, 0x5d, 0xdc }}

/**
 * An interface for wrapping nsIAuthPrompt interfaces to make
 * them usable via an nsIAuthPrompt2 interface.
 */
class NS_NO_VTABLE NS_SCRIPTABLE nsIAuthPromptAdapterFactory : public nsISupports {
 public: 

  NS_DECLARE_STATIC_IID_ACCESSOR(NS_IAUTHPROMPTADAPTERFACTORY_IID)

  /**
   * Wrap an object implementing nsIAuthPrompt so that it's usable via
   * nsIAuthPrompt2.
   */
  /* nsIAuthPrompt2 createAdapter (in nsIAuthPrompt aPrompt); */
  NS_SCRIPTABLE NS_IMETHOD CreateAdapter(nsIAuthPrompt *aPrompt, nsIAuthPrompt2 **_retval NS_OUTPARAM) = 0;

};

  NS_DEFINE_STATIC_IID_ACCESSOR(nsIAuthPromptAdapterFactory, NS_IAUTHPROMPTADAPTERFACTORY_IID)

/* Use this macro when declaring classes that implement this interface. */
#define NS_DECL_NSIAUTHPROMPTADAPTERFACTORY \
  NS_SCRIPTABLE NS_IMETHOD CreateAdapter(nsIAuthPrompt *aPrompt, nsIAuthPrompt2 **_retval NS_OUTPARAM); 

/* Use this macro to declare functions that forward the behavior of this interface to another object. */
#define NS_FORWARD_NSIAUTHPROMPTADAPTERFACTORY(_to) \
  NS_SCRIPTABLE NS_IMETHOD CreateAdapter(nsIAuthPrompt *aPrompt, nsIAuthPrompt2 **_retval NS_OUTPARAM) { return _to CreateAdapter(aPrompt, _retval); } 

/* Use this macro to declare functions that forward the behavior of this interface to another object in a safe way. */
#define NS_FORWARD_SAFE_NSIAUTHPROMPTADAPTERFACTORY(_to) \
  NS_SCRIPTABLE NS_IMETHOD CreateAdapter(nsIAuthPrompt *aPrompt, nsIAuthPrompt2 **_retval NS_OUTPARAM) { return !_to ? NS_ERROR_NULL_POINTER : _to->CreateAdapter(aPrompt, _retval); } 

#if 0
/* Use the code below as a template for the implementation class for this interface. */

/* Header file */
class nsAuthPromptAdapterFactory : public nsIAuthPromptAdapterFactory
{
public:
  NS_DECL_ISUPPORTS
  NS_DECL_NSIAUTHPROMPTADAPTERFACTORY

  nsAuthPromptAdapterFactory();

private:
  ~nsAuthPromptAdapterFactory();

protected:
  /* additional members */
};

/* Implementation file */
NS_IMPL_ISUPPORTS1(nsAuthPromptAdapterFactory, nsIAuthPromptAdapterFactory)

nsAuthPromptAdapterFactory::nsAuthPromptAdapterFactory()
{
  /* member initializers and constructor code */
}

nsAuthPromptAdapterFactory::~nsAuthPromptAdapterFactory()
{
  /* destructor code */
}

/* nsIAuthPrompt2 createAdapter (in nsIAuthPrompt aPrompt); */
NS_IMETHODIMP nsAuthPromptAdapterFactory::CreateAdapter(nsIAuthPrompt *aPrompt, nsIAuthPrompt2 **_retval NS_OUTPARAM)
{
    return NS_ERROR_NOT_IMPLEMENTED;
}

/* End of implementation class template. */
#endif


#endif /* __gen_nsIAuthPromptAdapterFactory_h__ */
