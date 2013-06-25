/*
 * DO NOT EDIT.  THIS FILE IS GENERATED FROM e:/builds/moz2_slave/mozilla-1.9.1-win32-xulrunner/build/uriloader/exthandler/nsIHandlerService.idl
 */

#ifndef __gen_nsIHandlerService_h__
#define __gen_nsIHandlerService_h__


#ifndef __gen_nsISupports_h__
#include "nsISupports.h"
#endif

/* For IDL files that don't want to include root IDL files. */
#ifndef NS_NO_VTABLE
#define NS_NO_VTABLE
#endif
class nsIHandlerInfo; /* forward declaration */

class nsISimpleEnumerator; /* forward declaration */


/* starting interface:    nsIHandlerService */
#define NS_IHANDLERSERVICE_IID_STR "53f0ad17-ec62-46a1-adbc-efccc06babcd"

#define NS_IHANDLERSERVICE_IID \
  {0x53f0ad17, 0xec62, 0x46a1, \
    { 0xad, 0xbc, 0xef, 0xcc, 0xc0, 0x6b, 0xab, 0xcd }}

class NS_NO_VTABLE NS_SCRIPTABLE nsIHandlerService : public nsISupports {
 public: 

  NS_DECLARE_STATIC_IID_ACCESSOR(NS_IHANDLERSERVICE_IID)

  /**
   * Retrieve a list of all handlers in the datastore.  This list is not
   * guaranteed to be in any particular order, and callers should not assume
   * it will remain in the same order in the future.
   *
   * @returns a list of all handlers in the datastore
   */
  /* nsISimpleEnumerator enumerate (); */
  NS_SCRIPTABLE NS_IMETHOD Enumerate(nsISimpleEnumerator **_retval NS_OUTPARAM) = 0;

  /**
   * Fill a handler info object with information from the datastore.
   *
   * Note: because of the way the external helper app service currently mixes
   * OS and user handler info in the same handler info object, this method
   * takes an existing handler info object (probably retrieved from the OS)
   * and "fills it in" with information from the datastore, overriding any
   * existing properties on the object with properties from the datastore.
   *
   * Ultimately, however, we're going to separate OS and user handler info
   * into separate objects, at which point this method should be renamed to
   * something like "get" or "retrieve", take a class and type (or perhaps
   * a type whose class can be determined by querying the type, for example
   * an nsIContentType which is also an nsIMIMEType or an nsIProtocolScheme),
   * and return a handler info object representing only the user info.
   *
   * Note: if you specify an override type, then the service will fill in
   * the handler info object with information about that type instead of
   * the type specified by the object's nsIHandlerInfo::type attribute.
   *
   * This is useful when you are trying to retrieve information about a MIME
   * type that doesn't exist in the datastore, but you have a file extension
   * for that type, and nsIHandlerService::getTypeFromExtension returns another
   * MIME type that does exist in the datastore and can handle that extension.
   *
   * For example, the user clicks on a link, and the content has a MIME type
   * that isn't in the datastore, but the link has a file extension, and that
   * extension is associated with another MIME type in the datastore (perhaps
   * an unofficial MIME type preceded an official one, like with image/x-png
   * and image/png).
   *
   * In that situation, you can call this method to fill in the handler info
   * object with information about that other type by passing the other type
   * as the aOverrideType parameter.
   *
   * @param aHandlerInfo   the handler info object
   * @param aOverrideType  a type to use instead of aHandlerInfo::type
   *
   * Note: if there is no information in the datastore about this type,
   * this method throws NS_ERROR_NOT_AVAILABLE. Callers are encouraged to
   * check exists() before calling fillHandlerInfo(), to prevent spamming the
   * console with XPCOM exception errors.
   */
  /* void fillHandlerInfo (in nsIHandlerInfo aHandlerInfo, in ACString aOverrideType); */
  NS_SCRIPTABLE NS_IMETHOD FillHandlerInfo(nsIHandlerInfo *aHandlerInfo, const nsACString & aOverrideType) = 0;

  /**
   * Save the preferred action, preferred handler, possible handlers, and
   * always ask properties of the given handler info object to the datastore.
   * Updates an existing record or creates a new one if necessary.
   *
   * Note: if preferred action is undefined or invalid, then we assume
   * the default value nsIHandlerInfo::useHelperApp.
   *
   * @param aHandlerInfo  the handler info object
   */
  /* void store (in nsIHandlerInfo aHandlerInfo); */
  NS_SCRIPTABLE NS_IMETHOD Store(nsIHandlerInfo *aHandlerInfo) = 0;

  /**
   * Whether or not a record for the given handler info object exists
   * in the datastore. If the datastore is corrupt (or some other error
   * is caught in the implementation), false will be returned.
   *
   * @param aHandlerInfo  a handler info object
   *
   * @returns whether or not a record exists
   */
  /* boolean exists (in nsIHandlerInfo aHandlerInfo); */
  NS_SCRIPTABLE NS_IMETHOD Exists(nsIHandlerInfo *aHandlerInfo, PRBool *_retval NS_OUTPARAM) = 0;

  /**
   * Remove the given handler info object from the datastore.  Deletes all
   * records associated with the object, including the preferred handler, info,
   * and type records plus the entry in the list of types, if they exist.
   * Otherwise, it does nothing and does not return an error.
   *
   * @param aHandlerInfo  the handler info object
   */
  /* void remove (in nsIHandlerInfo aHandlerInfo); */
  NS_SCRIPTABLE NS_IMETHOD Remove(nsIHandlerInfo *aHandlerInfo) = 0;

  /**
   * Get the MIME type mapped to the given file extension in the datastore.
   *
   * XXX If we ever support extension -> protocol scheme mappings, then this
   * method should work for those as well.
   *
   * Note: in general, you should use nsIMIMEService::getTypeFromExtension
   * to get a MIME type from a file extension, as that method checks a variety
   * of other sources besides just the datastore.  Use this only when you want
   * to specifically get only the mapping available in the datastore.
   *
   * @param aFileExtension  the file extension
   *
   * @returns the MIME type, if any; otherwise returns an empty string ("").
   */
  /* ACString getTypeFromExtension (in ACString aFileExtension); */
  NS_SCRIPTABLE NS_IMETHOD GetTypeFromExtension(const nsACString & aFileExtension, nsACString & _retval NS_OUTPARAM) = 0;

};

  NS_DEFINE_STATIC_IID_ACCESSOR(nsIHandlerService, NS_IHANDLERSERVICE_IID)

/* Use this macro when declaring classes that implement this interface. */
#define NS_DECL_NSIHANDLERSERVICE \
  NS_SCRIPTABLE NS_IMETHOD Enumerate(nsISimpleEnumerator **_retval NS_OUTPARAM); \
  NS_SCRIPTABLE NS_IMETHOD FillHandlerInfo(nsIHandlerInfo *aHandlerInfo, const nsACString & aOverrideType); \
  NS_SCRIPTABLE NS_IMETHOD Store(nsIHandlerInfo *aHandlerInfo); \
  NS_SCRIPTABLE NS_IMETHOD Exists(nsIHandlerInfo *aHandlerInfo, PRBool *_retval NS_OUTPARAM); \
  NS_SCRIPTABLE NS_IMETHOD Remove(nsIHandlerInfo *aHandlerInfo); \
  NS_SCRIPTABLE NS_IMETHOD GetTypeFromExtension(const nsACString & aFileExtension, nsACString & _retval NS_OUTPARAM); 

/* Use this macro to declare functions that forward the behavior of this interface to another object. */
#define NS_FORWARD_NSIHANDLERSERVICE(_to) \
  NS_SCRIPTABLE NS_IMETHOD Enumerate(nsISimpleEnumerator **_retval NS_OUTPARAM) { return _to Enumerate(_retval); } \
  NS_SCRIPTABLE NS_IMETHOD FillHandlerInfo(nsIHandlerInfo *aHandlerInfo, const nsACString & aOverrideType) { return _to FillHandlerInfo(aHandlerInfo, aOverrideType); } \
  NS_SCRIPTABLE NS_IMETHOD Store(nsIHandlerInfo *aHandlerInfo) { return _to Store(aHandlerInfo); } \
  NS_SCRIPTABLE NS_IMETHOD Exists(nsIHandlerInfo *aHandlerInfo, PRBool *_retval NS_OUTPARAM) { return _to Exists(aHandlerInfo, _retval); } \
  NS_SCRIPTABLE NS_IMETHOD Remove(nsIHandlerInfo *aHandlerInfo) { return _to Remove(aHandlerInfo); } \
  NS_SCRIPTABLE NS_IMETHOD GetTypeFromExtension(const nsACString & aFileExtension, nsACString & _retval NS_OUTPARAM) { return _to GetTypeFromExtension(aFileExtension, _retval); } 

/* Use this macro to declare functions that forward the behavior of this interface to another object in a safe way. */
#define NS_FORWARD_SAFE_NSIHANDLERSERVICE(_to) \
  NS_SCRIPTABLE NS_IMETHOD Enumerate(nsISimpleEnumerator **_retval NS_OUTPARAM) { return !_to ? NS_ERROR_NULL_POINTER : _to->Enumerate(_retval); } \
  NS_SCRIPTABLE NS_IMETHOD FillHandlerInfo(nsIHandlerInfo *aHandlerInfo, const nsACString & aOverrideType) { return !_to ? NS_ERROR_NULL_POINTER : _to->FillHandlerInfo(aHandlerInfo, aOverrideType); } \
  NS_SCRIPTABLE NS_IMETHOD Store(nsIHandlerInfo *aHandlerInfo) { return !_to ? NS_ERROR_NULL_POINTER : _to->Store(aHandlerInfo); } \
  NS_SCRIPTABLE NS_IMETHOD Exists(nsIHandlerInfo *aHandlerInfo, PRBool *_retval NS_OUTPARAM) { return !_to ? NS_ERROR_NULL_POINTER : _to->Exists(aHandlerInfo, _retval); } \
  NS_SCRIPTABLE NS_IMETHOD Remove(nsIHandlerInfo *aHandlerInfo) { return !_to ? NS_ERROR_NULL_POINTER : _to->Remove(aHandlerInfo); } \
  NS_SCRIPTABLE NS_IMETHOD GetTypeFromExtension(const nsACString & aFileExtension, nsACString & _retval NS_OUTPARAM) { return !_to ? NS_ERROR_NULL_POINTER : _to->GetTypeFromExtension(aFileExtension, _retval); } 

#if 0
/* Use the code below as a template for the implementation class for this interface. */

/* Header file */
class nsHandlerService : public nsIHandlerService
{
public:
  NS_DECL_ISUPPORTS
  NS_DECL_NSIHANDLERSERVICE

  nsHandlerService();

private:
  ~nsHandlerService();

protected:
  /* additional members */
};

/* Implementation file */
NS_IMPL_ISUPPORTS1(nsHandlerService, nsIHandlerService)

nsHandlerService::nsHandlerService()
{
  /* member initializers and constructor code */
}

nsHandlerService::~nsHandlerService()
{
  /* destructor code */
}

/* nsISimpleEnumerator enumerate (); */
NS_IMETHODIMP nsHandlerService::Enumerate(nsISimpleEnumerator **_retval NS_OUTPARAM)
{
    return NS_ERROR_NOT_IMPLEMENTED;
}

/* void fillHandlerInfo (in nsIHandlerInfo aHandlerInfo, in ACString aOverrideType); */
NS_IMETHODIMP nsHandlerService::FillHandlerInfo(nsIHandlerInfo *aHandlerInfo, const nsACString & aOverrideType)
{
    return NS_ERROR_NOT_IMPLEMENTED;
}

/* void store (in nsIHandlerInfo aHandlerInfo); */
NS_IMETHODIMP nsHandlerService::Store(nsIHandlerInfo *aHandlerInfo)
{
    return NS_ERROR_NOT_IMPLEMENTED;
}

/* boolean exists (in nsIHandlerInfo aHandlerInfo); */
NS_IMETHODIMP nsHandlerService::Exists(nsIHandlerInfo *aHandlerInfo, PRBool *_retval NS_OUTPARAM)
{
    return NS_ERROR_NOT_IMPLEMENTED;
}

/* void remove (in nsIHandlerInfo aHandlerInfo); */
NS_IMETHODIMP nsHandlerService::Remove(nsIHandlerInfo *aHandlerInfo)
{
    return NS_ERROR_NOT_IMPLEMENTED;
}

/* ACString getTypeFromExtension (in ACString aFileExtension); */
NS_IMETHODIMP nsHandlerService::GetTypeFromExtension(const nsACString & aFileExtension, nsACString & _retval NS_OUTPARAM)
{
    return NS_ERROR_NOT_IMPLEMENTED;
}

/* End of implementation class template. */
#endif


#endif /* __gen_nsIHandlerService_h__ */
