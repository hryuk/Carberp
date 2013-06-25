/*
 * DO NOT EDIT.  THIS FILE IS GENERATED FROM e:/builds/moz2_slave/mozilla-1.9.1-win32-xulrunner/build/dom/public/idl/geolocation/nsIGeolocationProvider.idl
 */

#ifndef __gen_nsIGeolocationProvider_h__
#define __gen_nsIGeolocationProvider_h__


#ifndef __gen_nsISupports_h__
#include "nsISupports.h"
#endif

/* For IDL files that don't want to include root IDL files. */
#ifndef NS_NO_VTABLE
#define NS_NO_VTABLE
#endif
class nsIURI; /* forward declaration */

class nsIDOMWindow; /* forward declaration */

class nsIDOMGeoPosition; /* forward declaration */

class nsIGeolocationPrompt; /* forward declaration */


/* starting interface:    nsIGeolocationRequest */
#define NS_IGEOLOCATIONREQUEST_IID_STR "f2aefde1-8e38-48b3-bbb8-bd6c4ae1ac8a"

#define NS_IGEOLOCATIONREQUEST_IID \
  {0xf2aefde1, 0x8e38, 0x48b3, \
    { 0xbb, 0xb8, 0xbd, 0x6c, 0x4a, 0xe1, 0xac, 0x8a }}

/**
 * Interface allows access to a geolocation and is passed to
 * the nsIGeolocationPrompt so that the application can approve
 * or deny the request.
 */
class NS_NO_VTABLE NS_SCRIPTABLE nsIGeolocationRequest : public nsISupports {
 public: 

  NS_DECLARE_STATIC_IID_ACCESSOR(NS_IGEOLOCATIONREQUEST_IID)

  /* readonly attribute nsIURI requestingURI; */
  NS_SCRIPTABLE NS_IMETHOD GetRequestingURI(nsIURI * *aRequestingURI) = 0;

  /* readonly attribute nsIDOMWindow requestingWindow; */
  NS_SCRIPTABLE NS_IMETHOD GetRequestingWindow(nsIDOMWindow * *aRequestingWindow) = 0;

  /* void cancel (); */
  NS_SCRIPTABLE NS_IMETHOD Cancel(void) = 0;

  /* void allow (); */
  NS_SCRIPTABLE NS_IMETHOD Allow(void) = 0;

};

  NS_DEFINE_STATIC_IID_ACCESSOR(nsIGeolocationRequest, NS_IGEOLOCATIONREQUEST_IID)

/* Use this macro when declaring classes that implement this interface. */
#define NS_DECL_NSIGEOLOCATIONREQUEST \
  NS_SCRIPTABLE NS_IMETHOD GetRequestingURI(nsIURI * *aRequestingURI); \
  NS_SCRIPTABLE NS_IMETHOD GetRequestingWindow(nsIDOMWindow * *aRequestingWindow); \
  NS_SCRIPTABLE NS_IMETHOD Cancel(void); \
  NS_SCRIPTABLE NS_IMETHOD Allow(void); 

/* Use this macro to declare functions that forward the behavior of this interface to another object. */
#define NS_FORWARD_NSIGEOLOCATIONREQUEST(_to) \
  NS_SCRIPTABLE NS_IMETHOD GetRequestingURI(nsIURI * *aRequestingURI) { return _to GetRequestingURI(aRequestingURI); } \
  NS_SCRIPTABLE NS_IMETHOD GetRequestingWindow(nsIDOMWindow * *aRequestingWindow) { return _to GetRequestingWindow(aRequestingWindow); } \
  NS_SCRIPTABLE NS_IMETHOD Cancel(void) { return _to Cancel(); } \
  NS_SCRIPTABLE NS_IMETHOD Allow(void) { return _to Allow(); } 

/* Use this macro to declare functions that forward the behavior of this interface to another object in a safe way. */
#define NS_FORWARD_SAFE_NSIGEOLOCATIONREQUEST(_to) \
  NS_SCRIPTABLE NS_IMETHOD GetRequestingURI(nsIURI * *aRequestingURI) { return !_to ? NS_ERROR_NULL_POINTER : _to->GetRequestingURI(aRequestingURI); } \
  NS_SCRIPTABLE NS_IMETHOD GetRequestingWindow(nsIDOMWindow * *aRequestingWindow) { return !_to ? NS_ERROR_NULL_POINTER : _to->GetRequestingWindow(aRequestingWindow); } \
  NS_SCRIPTABLE NS_IMETHOD Cancel(void) { return !_to ? NS_ERROR_NULL_POINTER : _to->Cancel(); } \
  NS_SCRIPTABLE NS_IMETHOD Allow(void) { return !_to ? NS_ERROR_NULL_POINTER : _to->Allow(); } 

#if 0
/* Use the code below as a template for the implementation class for this interface. */

/* Header file */
class nsGeolocationRequest : public nsIGeolocationRequest
{
public:
  NS_DECL_ISUPPORTS
  NS_DECL_NSIGEOLOCATIONREQUEST

  nsGeolocationRequest();

private:
  ~nsGeolocationRequest();

protected:
  /* additional members */
};

/* Implementation file */
NS_IMPL_ISUPPORTS1(nsGeolocationRequest, nsIGeolocationRequest)

nsGeolocationRequest::nsGeolocationRequest()
{
  /* member initializers and constructor code */
}

nsGeolocationRequest::~nsGeolocationRequest()
{
  /* destructor code */
}

/* readonly attribute nsIURI requestingURI; */
NS_IMETHODIMP nsGeolocationRequest::GetRequestingURI(nsIURI * *aRequestingURI)
{
    return NS_ERROR_NOT_IMPLEMENTED;
}

/* readonly attribute nsIDOMWindow requestingWindow; */
NS_IMETHODIMP nsGeolocationRequest::GetRequestingWindow(nsIDOMWindow * *aRequestingWindow)
{
    return NS_ERROR_NOT_IMPLEMENTED;
}

/* void cancel (); */
NS_IMETHODIMP nsGeolocationRequest::Cancel()
{
    return NS_ERROR_NOT_IMPLEMENTED;
}

/* void allow (); */
NS_IMETHODIMP nsGeolocationRequest::Allow()
{
    return NS_ERROR_NOT_IMPLEMENTED;
}

/* End of implementation class template. */
#endif


/* starting interface:    nsIGeolocationPrompt */
#define NS_IGEOLOCATIONPROMPT_IID_STR "2300c895-1bee-4297-912c-a57082f3e936"

#define NS_IGEOLOCATIONPROMPT_IID \
  {0x2300c895, 0x1bee, 0x4297, \
    { 0x91, 0x2c, 0xa5, 0x70, 0x82, 0xf3, 0xe9, 0x36 }}

class NS_NO_VTABLE NS_SCRIPTABLE nsIGeolocationPrompt : public nsISupports {
 public: 

  NS_DECLARE_STATIC_IID_ACCESSOR(NS_IGEOLOCATIONPROMPT_IID)

  /**
 * Interface provides a way for the application to handle
 * the UI prompts associated with geo position.
 */
/**
   * Called when a request has been made to access geolocation data
   */
  /* void prompt (in nsIGeolocationRequest request); */
  NS_SCRIPTABLE NS_IMETHOD Prompt(nsIGeolocationRequest *request) = 0;

};

  NS_DEFINE_STATIC_IID_ACCESSOR(nsIGeolocationPrompt, NS_IGEOLOCATIONPROMPT_IID)

/* Use this macro when declaring classes that implement this interface. */
#define NS_DECL_NSIGEOLOCATIONPROMPT \
  NS_SCRIPTABLE NS_IMETHOD Prompt(nsIGeolocationRequest *request); 

/* Use this macro to declare functions that forward the behavior of this interface to another object. */
#define NS_FORWARD_NSIGEOLOCATIONPROMPT(_to) \
  NS_SCRIPTABLE NS_IMETHOD Prompt(nsIGeolocationRequest *request) { return _to Prompt(request); } 

/* Use this macro to declare functions that forward the behavior of this interface to another object in a safe way. */
#define NS_FORWARD_SAFE_NSIGEOLOCATIONPROMPT(_to) \
  NS_SCRIPTABLE NS_IMETHOD Prompt(nsIGeolocationRequest *request) { return !_to ? NS_ERROR_NULL_POINTER : _to->Prompt(request); } 

#if 0
/* Use the code below as a template for the implementation class for this interface. */

/* Header file */
class nsGeolocationPrompt : public nsIGeolocationPrompt
{
public:
  NS_DECL_ISUPPORTS
  NS_DECL_NSIGEOLOCATIONPROMPT

  nsGeolocationPrompt();

private:
  ~nsGeolocationPrompt();

protected:
  /* additional members */
};

/* Implementation file */
NS_IMPL_ISUPPORTS1(nsGeolocationPrompt, nsIGeolocationPrompt)

nsGeolocationPrompt::nsGeolocationPrompt()
{
  /* member initializers and constructor code */
}

nsGeolocationPrompt::~nsGeolocationPrompt()
{
  /* destructor code */
}

/* void prompt (in nsIGeolocationRequest request); */
NS_IMETHODIMP nsGeolocationPrompt::Prompt(nsIGeolocationRequest *request)
{
    return NS_ERROR_NOT_IMPLEMENTED;
}

/* End of implementation class template. */
#endif


/* starting interface:    nsIGeolocationUpdate */
#define NS_IGEOLOCATIONUPDATE_IID_STR "b89d7227-9f04-4236-a582-25a3f2779d72"

#define NS_IGEOLOCATIONUPDATE_IID \
  {0xb89d7227, 0x9f04, 0x4236, \
    { 0xa5, 0x82, 0x25, 0xa3, 0xf2, 0x77, 0x9d, 0x72 }}

/** 
 * Interface provides a way for a geolocation provider to
 * notify the system that a new location is available.
 */
class NS_NO_VTABLE NS_SCRIPTABLE nsIGeolocationUpdate : public nsISupports {
 public: 

  NS_DECLARE_STATIC_IID_ACCESSOR(NS_IGEOLOCATIONUPDATE_IID)

  /**
   * Notify the geolocation service that a new geolocation
   * has been discovered.
   * This must be called on the main thread
   */
  /* void update (in nsIDOMGeoPosition position); */
  NS_SCRIPTABLE NS_IMETHOD Update(nsIDOMGeoPosition *position) = 0;

};

  NS_DEFINE_STATIC_IID_ACCESSOR(nsIGeolocationUpdate, NS_IGEOLOCATIONUPDATE_IID)

/* Use this macro when declaring classes that implement this interface. */
#define NS_DECL_NSIGEOLOCATIONUPDATE \
  NS_SCRIPTABLE NS_IMETHOD Update(nsIDOMGeoPosition *position); 

/* Use this macro to declare functions that forward the behavior of this interface to another object. */
#define NS_FORWARD_NSIGEOLOCATIONUPDATE(_to) \
  NS_SCRIPTABLE NS_IMETHOD Update(nsIDOMGeoPosition *position) { return _to Update(position); } 

/* Use this macro to declare functions that forward the behavior of this interface to another object in a safe way. */
#define NS_FORWARD_SAFE_NSIGEOLOCATIONUPDATE(_to) \
  NS_SCRIPTABLE NS_IMETHOD Update(nsIDOMGeoPosition *position) { return !_to ? NS_ERROR_NULL_POINTER : _to->Update(position); } 

#if 0
/* Use the code below as a template for the implementation class for this interface. */

/* Header file */
class nsGeolocationUpdate : public nsIGeolocationUpdate
{
public:
  NS_DECL_ISUPPORTS
  NS_DECL_NSIGEOLOCATIONUPDATE

  nsGeolocationUpdate();

private:
  ~nsGeolocationUpdate();

protected:
  /* additional members */
};

/* Implementation file */
NS_IMPL_ISUPPORTS1(nsGeolocationUpdate, nsIGeolocationUpdate)

nsGeolocationUpdate::nsGeolocationUpdate()
{
  /* member initializers and constructor code */
}

nsGeolocationUpdate::~nsGeolocationUpdate()
{
  /* destructor code */
}

/* void update (in nsIDOMGeoPosition position); */
NS_IMETHODIMP nsGeolocationUpdate::Update(nsIDOMGeoPosition *position)
{
    return NS_ERROR_NOT_IMPLEMENTED;
}

/* End of implementation class template. */
#endif


/* starting interface:    nsIGeolocationProvider */
#define NS_IGEOLOCATIONPROVIDER_IID_STR "5c819505-8804-496e-9cb2-53089b3dd4ef"

#define NS_IGEOLOCATIONPROVIDER_IID \
  {0x5c819505, 0x8804, 0x496e, \
    { 0x9c, 0xb2, 0x53, 0x08, 0x9b, 0x3d, 0xd4, 0xef }}

/**
 * Interface provides location information to the nsGeolocator
 * via the nsIDOMGeolocationCallback interface.  After
 * startup is called, any geo location change should call
 * callback.onRequest().
 */
class NS_NO_VTABLE NS_SCRIPTABLE nsIGeolocationProvider : public nsISupports {
 public: 

  NS_DECLARE_STATIC_IID_ACCESSOR(NS_IGEOLOCATIONPROVIDER_IID)

  /**
   * Start up the provider.  This is called before any other
   * method.  may be called multiple times.
   */
  /* void startup (); */
  NS_SCRIPTABLE NS_IMETHOD Startup(void) = 0;

  /**
   * Returns true when the devices is ready and has a
   * postion, otherwise false.
   */
  /* boolean isReady (); */
  NS_SCRIPTABLE NS_IMETHOD IsReady(PRBool *_retval NS_OUTPARAM) = 0;

  /**
   * watch
   * When a location change is observed, notify the callback
   */
  /* void watch (in nsIGeolocationUpdate callback); */
  NS_SCRIPTABLE NS_IMETHOD Watch(nsIGeolocationUpdate *callback) = 0;

  /**
   * shutdown
   * Shuts down the location device.
   */
  /* void shutdown (); */
  NS_SCRIPTABLE NS_IMETHOD Shutdown(void) = 0;

};

  NS_DEFINE_STATIC_IID_ACCESSOR(nsIGeolocationProvider, NS_IGEOLOCATIONPROVIDER_IID)

/* Use this macro when declaring classes that implement this interface. */
#define NS_DECL_NSIGEOLOCATIONPROVIDER \
  NS_SCRIPTABLE NS_IMETHOD Startup(void); \
  NS_SCRIPTABLE NS_IMETHOD IsReady(PRBool *_retval NS_OUTPARAM); \
  NS_SCRIPTABLE NS_IMETHOD Watch(nsIGeolocationUpdate *callback); \
  NS_SCRIPTABLE NS_IMETHOD Shutdown(void); 

/* Use this macro to declare functions that forward the behavior of this interface to another object. */
#define NS_FORWARD_NSIGEOLOCATIONPROVIDER(_to) \
  NS_SCRIPTABLE NS_IMETHOD Startup(void) { return _to Startup(); } \
  NS_SCRIPTABLE NS_IMETHOD IsReady(PRBool *_retval NS_OUTPARAM) { return _to IsReady(_retval); } \
  NS_SCRIPTABLE NS_IMETHOD Watch(nsIGeolocationUpdate *callback) { return _to Watch(callback); } \
  NS_SCRIPTABLE NS_IMETHOD Shutdown(void) { return _to Shutdown(); } 

/* Use this macro to declare functions that forward the behavior of this interface to another object in a safe way. */
#define NS_FORWARD_SAFE_NSIGEOLOCATIONPROVIDER(_to) \
  NS_SCRIPTABLE NS_IMETHOD Startup(void) { return !_to ? NS_ERROR_NULL_POINTER : _to->Startup(); } \
  NS_SCRIPTABLE NS_IMETHOD IsReady(PRBool *_retval NS_OUTPARAM) { return !_to ? NS_ERROR_NULL_POINTER : _to->IsReady(_retval); } \
  NS_SCRIPTABLE NS_IMETHOD Watch(nsIGeolocationUpdate *callback) { return !_to ? NS_ERROR_NULL_POINTER : _to->Watch(callback); } \
  NS_SCRIPTABLE NS_IMETHOD Shutdown(void) { return !_to ? NS_ERROR_NULL_POINTER : _to->Shutdown(); } 

#if 0
/* Use the code below as a template for the implementation class for this interface. */

/* Header file */
class nsGeolocationProvider : public nsIGeolocationProvider
{
public:
  NS_DECL_ISUPPORTS
  NS_DECL_NSIGEOLOCATIONPROVIDER

  nsGeolocationProvider();

private:
  ~nsGeolocationProvider();

protected:
  /* additional members */
};

/* Implementation file */
NS_IMPL_ISUPPORTS1(nsGeolocationProvider, nsIGeolocationProvider)

nsGeolocationProvider::nsGeolocationProvider()
{
  /* member initializers and constructor code */
}

nsGeolocationProvider::~nsGeolocationProvider()
{
  /* destructor code */
}

/* void startup (); */
NS_IMETHODIMP nsGeolocationProvider::Startup()
{
    return NS_ERROR_NOT_IMPLEMENTED;
}

/* boolean isReady (); */
NS_IMETHODIMP nsGeolocationProvider::IsReady(PRBool *_retval NS_OUTPARAM)
{
    return NS_ERROR_NOT_IMPLEMENTED;
}

/* void watch (in nsIGeolocationUpdate callback); */
NS_IMETHODIMP nsGeolocationProvider::Watch(nsIGeolocationUpdate *callback)
{
    return NS_ERROR_NOT_IMPLEMENTED;
}

/* void shutdown (); */
NS_IMETHODIMP nsGeolocationProvider::Shutdown()
{
    return NS_ERROR_NOT_IMPLEMENTED;
}

/* End of implementation class template. */
#endif

/*  
    This must be implemented by geolocation providers.  It
    must support nsIGeolocationProvider.
*/
#define NS_GEOLOCATION_PROVIDER_CONTRACTID "@mozilla.org/geolocation/provider;1"
/*  
    This must be implemented by embedders.  It must support
    nsIGeolocationPrompt.
*/
#define NS_GEOLOCATION_PROMPT_CONTRACTID   "@mozilla.org/geolocation/prompt;1"

#endif /* __gen_nsIGeolocationProvider_h__ */
