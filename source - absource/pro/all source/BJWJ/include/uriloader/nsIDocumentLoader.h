/*
 * DO NOT EDIT.  THIS FILE IS GENERATED FROM e:/builds/moz2_slave/mozilla-1.9.1-win32-xulrunner/build/uriloader/base/nsIDocumentLoader.idl
 */

#ifndef __gen_nsIDocumentLoader_h__
#define __gen_nsIDocumentLoader_h__


#ifndef __gen_nsISupports_h__
#include "nsISupports.h"
#endif

/* For IDL files that don't want to include root IDL files. */
#ifndef NS_NO_VTABLE
#define NS_NO_VTABLE
#endif
class nsILoadGroup; /* forward declaration */

class nsIChannel; /* forward declaration */

class nsIURI; /* forward declaration */

class nsIWebProgress; /* forward declaration */

class nsIRequest; /* forward declaration */


/* starting interface:    nsIDocumentLoader */
#define NS_IDOCUMENTLOADER_IID_STR "bbe961ee-59e9-42bb-be50-0331979bb79f"

#define NS_IDOCUMENTLOADER_IID \
  {0xbbe961ee, 0x59e9, 0x42bb, \
    { 0xbe, 0x50, 0x03, 0x31, 0x97, 0x9b, 0xb7, 0x9f }}

/**
 * An nsIDocumentLoader is an interface responsible for tracking groups of
 * loads that belong together (images, external scripts, etc) and subdocuments
 * (<iframe>, <frame>, etc). It is also responsible for sending
 * nsIWebProgressListener notifications.
 * XXXbz this interface should go away, we think...
 */
class NS_NO_VTABLE NS_SCRIPTABLE nsIDocumentLoader : public nsISupports {
 public: 

  NS_DECLARE_STATIC_IID_ACCESSOR(NS_IDOCUMENTLOADER_IID)

  /* void stop (); */
  NS_SCRIPTABLE NS_IMETHOD Stop(void) = 0;

  /* readonly attribute nsISupports container; */
  NS_SCRIPTABLE NS_IMETHOD GetContainer(nsISupports * *aContainer) = 0;

  /* readonly attribute nsILoadGroup loadGroup; */
  NS_SCRIPTABLE NS_IMETHOD GetLoadGroup(nsILoadGroup * *aLoadGroup) = 0;

  /* readonly attribute nsIChannel documentChannel; */
  NS_SCRIPTABLE NS_IMETHOD GetDocumentChannel(nsIChannel * *aDocumentChannel) = 0;

};

  NS_DEFINE_STATIC_IID_ACCESSOR(nsIDocumentLoader, NS_IDOCUMENTLOADER_IID)

/* Use this macro when declaring classes that implement this interface. */
#define NS_DECL_NSIDOCUMENTLOADER \
  NS_SCRIPTABLE NS_IMETHOD Stop(void); \
  NS_SCRIPTABLE NS_IMETHOD GetContainer(nsISupports * *aContainer); \
  NS_SCRIPTABLE NS_IMETHOD GetLoadGroup(nsILoadGroup * *aLoadGroup); \
  NS_SCRIPTABLE NS_IMETHOD GetDocumentChannel(nsIChannel * *aDocumentChannel); 

/* Use this macro to declare functions that forward the behavior of this interface to another object. */
#define NS_FORWARD_NSIDOCUMENTLOADER(_to) \
  NS_SCRIPTABLE NS_IMETHOD Stop(void) { return _to Stop(); } \
  NS_SCRIPTABLE NS_IMETHOD GetContainer(nsISupports * *aContainer) { return _to GetContainer(aContainer); } \
  NS_SCRIPTABLE NS_IMETHOD GetLoadGroup(nsILoadGroup * *aLoadGroup) { return _to GetLoadGroup(aLoadGroup); } \
  NS_SCRIPTABLE NS_IMETHOD GetDocumentChannel(nsIChannel * *aDocumentChannel) { return _to GetDocumentChannel(aDocumentChannel); } 

/* Use this macro to declare functions that forward the behavior of this interface to another object in a safe way. */
#define NS_FORWARD_SAFE_NSIDOCUMENTLOADER(_to) \
  NS_SCRIPTABLE NS_IMETHOD Stop(void) { return !_to ? NS_ERROR_NULL_POINTER : _to->Stop(); } \
  NS_SCRIPTABLE NS_IMETHOD GetContainer(nsISupports * *aContainer) { return !_to ? NS_ERROR_NULL_POINTER : _to->GetContainer(aContainer); } \
  NS_SCRIPTABLE NS_IMETHOD GetLoadGroup(nsILoadGroup * *aLoadGroup) { return !_to ? NS_ERROR_NULL_POINTER : _to->GetLoadGroup(aLoadGroup); } \
  NS_SCRIPTABLE NS_IMETHOD GetDocumentChannel(nsIChannel * *aDocumentChannel) { return !_to ? NS_ERROR_NULL_POINTER : _to->GetDocumentChannel(aDocumentChannel); } 

#if 0
/* Use the code below as a template for the implementation class for this interface. */

/* Header file */
class nsDocumentLoader : public nsIDocumentLoader
{
public:
  NS_DECL_ISUPPORTS
  NS_DECL_NSIDOCUMENTLOADER

  nsDocumentLoader();

private:
  ~nsDocumentLoader();

protected:
  /* additional members */
};

/* Implementation file */
NS_IMPL_ISUPPORTS1(nsDocumentLoader, nsIDocumentLoader)

nsDocumentLoader::nsDocumentLoader()
{
  /* member initializers and constructor code */
}

nsDocumentLoader::~nsDocumentLoader()
{
  /* destructor code */
}

/* void stop (); */
NS_IMETHODIMP nsDocumentLoader::Stop()
{
    return NS_ERROR_NOT_IMPLEMENTED;
}

/* readonly attribute nsISupports container; */
NS_IMETHODIMP nsDocumentLoader::GetContainer(nsISupports * *aContainer)
{
    return NS_ERROR_NOT_IMPLEMENTED;
}

/* readonly attribute nsILoadGroup loadGroup; */
NS_IMETHODIMP nsDocumentLoader::GetLoadGroup(nsILoadGroup * *aLoadGroup)
{
    return NS_ERROR_NOT_IMPLEMENTED;
}

/* readonly attribute nsIChannel documentChannel; */
NS_IMETHODIMP nsDocumentLoader::GetDocumentChannel(nsIChannel * *aDocumentChannel)
{
    return NS_ERROR_NOT_IMPLEMENTED;
}

/* End of implementation class template. */
#endif


#endif /* __gen_nsIDocumentLoader_h__ */
