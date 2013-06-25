/*
 * DO NOT EDIT.  THIS FILE IS GENERATED FROM e:/builds/moz2_slave/mozilla-1.9.1-win32-xulrunner/build/netwerk/base/public/nsIPermissionManager.idl
 */

#ifndef __gen_nsIPermissionManager_h__
#define __gen_nsIPermissionManager_h__


#ifndef __gen_nsISupports_h__
#include "nsISupports.h"
#endif

#ifndef __gen_nsISimpleEnumerator_h__
#include "nsISimpleEnumerator.h"
#endif

/* For IDL files that don't want to include root IDL files. */
#ifndef NS_NO_VTABLE
#define NS_NO_VTABLE
#endif
class nsIURI; /* forward declaration */

class nsIObserver; /* forward declaration */


/* starting interface:    nsIPermissionManager */
#define NS_IPERMISSIONMANAGER_IID_STR "00708302-684c-42d6-a5a3-995d51b1d17c"

#define NS_IPERMISSIONMANAGER_IID \
  {0x00708302, 0x684c, 0x42d6, \
    { 0xa5, 0xa3, 0x99, 0x5d, 0x51, 0xb1, 0xd1, 0x7c }}

class NS_NO_VTABLE NS_SCRIPTABLE nsIPermissionManager : public nsISupports {
 public: 

  NS_DECLARE_STATIC_IID_ACCESSOR(NS_IPERMISSIONMANAGER_IID)

  /**
   * Predefined return values for the testPermission method and for
   * the permission param of the add method
   * NOTE: UNKNOWN_ACTION (0) is reserved to represent the
   * default permission when no entry is found for a host, and
   * should not be used by consumers to indicate otherwise.
   */
  enum { UNKNOWN_ACTION = 0U };

  enum { ALLOW_ACTION = 1U };

  enum { DENY_ACTION = 2U };

  /**
   * Add permission information for a given URI and permission type. This
   * operation will cause the type string to be registered if it does not
   * currently exist. If a permission already exists for a given type, it
   * will be modified.
   *
   * @param uri         the uri to add the permission for
   * @param type        a case-sensitive ASCII string, identifying the consumer.
   *                    Consumers should choose this string to be unique, with
   *                    respect to other consumers.
   * @param permission  an integer representing the desired action (e.g. allow
   *                    or deny). The interpretation of this number is up to the
   *                    consumer, and may represent different actions for different
   *                    types. Consumers may use one of the enumerated permission
   *                    actions defined above, for convenience.
   *                    NOTE: UNKNOWN_ACTION (0) is reserved to represent the
   *                    default permission when no entry is found for a host, and
   *                    should not be used by consumers to indicate otherwise.
   */
  /* void add (in nsIURI uri, in string type, in PRUint32 permission); */
  NS_SCRIPTABLE NS_IMETHOD Add(nsIURI *uri, const char *type, PRUint32 permission) = 0;

  /**
   * Remove permission information for a given host string and permission type.
   * The host string represents the exact entry in the permission list (such as
   * obtained from the enumerator), not a URI which that permission might apply
   * to.
   *
   * @param host   the host to remove the permission for
   * @param type   a case-sensitive ASCII string, identifying the consumer. 
   *               The type must have been previously registered using the
   *               add() method.
   */
  /* void remove (in AUTF8String host, in string type); */
  NS_SCRIPTABLE NS_IMETHOD Remove(const nsACString & host, const char *type) = 0;

  /**
   * Clear permission information for all websites.
   */
  /* void removeAll (); */
  NS_SCRIPTABLE NS_IMETHOD RemoveAll(void) = 0;

  /**
   * Test whether a website has permission to perform the given action.
   * @param uri     the uri to be tested
   * @param type    a case-sensitive ASCII string, identifying the consumer
   * @param return  see add(), param permission. returns UNKNOWN_ACTION when
   *                there is no stored permission for this uri and / or type.
   */
  /* PRUint32 testPermission (in nsIURI uri, in string type); */
  NS_SCRIPTABLE NS_IMETHOD TestPermission(nsIURI *uri, const char *type, PRUint32 *_retval NS_OUTPARAM) = 0;

  /**
   * Test whether a website has permission to perform the given action.
   * This requires an exact hostname match, subdomains are not a match.
   * @param uri     the uri to be tested
   * @param type    a case-sensitive ASCII string, identifying the consumer
   * @param return  see add(), param permission. returns UNKNOWN_ACTION when
   *                there is no stored permission for this uri and / or type.
   */
  /* PRUint32 testExactPermission (in nsIURI uri, in string type); */
  NS_SCRIPTABLE NS_IMETHOD TestExactPermission(nsIURI *uri, const char *type, PRUint32 *_retval NS_OUTPARAM) = 0;

  /**
   * Allows enumeration of all stored permissions
   * @return an nsISimpleEnumerator interface that allows access to
   *         nsIPermission objects
   */
  /* readonly attribute nsISimpleEnumerator enumerator; */
  NS_SCRIPTABLE NS_IMETHOD GetEnumerator(nsISimpleEnumerator * *aEnumerator) = 0;

};

  NS_DEFINE_STATIC_IID_ACCESSOR(nsIPermissionManager, NS_IPERMISSIONMANAGER_IID)

/* Use this macro when declaring classes that implement this interface. */
#define NS_DECL_NSIPERMISSIONMANAGER \
  NS_SCRIPTABLE NS_IMETHOD Add(nsIURI *uri, const char *type, PRUint32 permission); \
  NS_SCRIPTABLE NS_IMETHOD Remove(const nsACString & host, const char *type); \
  NS_SCRIPTABLE NS_IMETHOD RemoveAll(void); \
  NS_SCRIPTABLE NS_IMETHOD TestPermission(nsIURI *uri, const char *type, PRUint32 *_retval NS_OUTPARAM); \
  NS_SCRIPTABLE NS_IMETHOD TestExactPermission(nsIURI *uri, const char *type, PRUint32 *_retval NS_OUTPARAM); \
  NS_SCRIPTABLE NS_IMETHOD GetEnumerator(nsISimpleEnumerator * *aEnumerator); 

/* Use this macro to declare functions that forward the behavior of this interface to another object. */
#define NS_FORWARD_NSIPERMISSIONMANAGER(_to) \
  NS_SCRIPTABLE NS_IMETHOD Add(nsIURI *uri, const char *type, PRUint32 permission) { return _to Add(uri, type, permission); } \
  NS_SCRIPTABLE NS_IMETHOD Remove(const nsACString & host, const char *type) { return _to Remove(host, type); } \
  NS_SCRIPTABLE NS_IMETHOD RemoveAll(void) { return _to RemoveAll(); } \
  NS_SCRIPTABLE NS_IMETHOD TestPermission(nsIURI *uri, const char *type, PRUint32 *_retval NS_OUTPARAM) { return _to TestPermission(uri, type, _retval); } \
  NS_SCRIPTABLE NS_IMETHOD TestExactPermission(nsIURI *uri, const char *type, PRUint32 *_retval NS_OUTPARAM) { return _to TestExactPermission(uri, type, _retval); } \
  NS_SCRIPTABLE NS_IMETHOD GetEnumerator(nsISimpleEnumerator * *aEnumerator) { return _to GetEnumerator(aEnumerator); } 

/* Use this macro to declare functions that forward the behavior of this interface to another object in a safe way. */
#define NS_FORWARD_SAFE_NSIPERMISSIONMANAGER(_to) \
  NS_SCRIPTABLE NS_IMETHOD Add(nsIURI *uri, const char *type, PRUint32 permission) { return !_to ? NS_ERROR_NULL_POINTER : _to->Add(uri, type, permission); } \
  NS_SCRIPTABLE NS_IMETHOD Remove(const nsACString & host, const char *type) { return !_to ? NS_ERROR_NULL_POINTER : _to->Remove(host, type); } \
  NS_SCRIPTABLE NS_IMETHOD RemoveAll(void) { return !_to ? NS_ERROR_NULL_POINTER : _to->RemoveAll(); } \
  NS_SCRIPTABLE NS_IMETHOD TestPermission(nsIURI *uri, const char *type, PRUint32 *_retval NS_OUTPARAM) { return !_to ? NS_ERROR_NULL_POINTER : _to->TestPermission(uri, type, _retval); } \
  NS_SCRIPTABLE NS_IMETHOD TestExactPermission(nsIURI *uri, const char *type, PRUint32 *_retval NS_OUTPARAM) { return !_to ? NS_ERROR_NULL_POINTER : _to->TestExactPermission(uri, type, _retval); } \
  NS_SCRIPTABLE NS_IMETHOD GetEnumerator(nsISimpleEnumerator * *aEnumerator) { return !_to ? NS_ERROR_NULL_POINTER : _to->GetEnumerator(aEnumerator); } 

#if 0
/* Use the code below as a template for the implementation class for this interface. */

/* Header file */
class nsPermissionManager : public nsIPermissionManager
{
public:
  NS_DECL_ISUPPORTS
  NS_DECL_NSIPERMISSIONMANAGER

  nsPermissionManager();

private:
  ~nsPermissionManager();

protected:
  /* additional members */
};

/* Implementation file */
NS_IMPL_ISUPPORTS1(nsPermissionManager, nsIPermissionManager)

nsPermissionManager::nsPermissionManager()
{
  /* member initializers and constructor code */
}

nsPermissionManager::~nsPermissionManager()
{
  /* destructor code */
}

/* void add (in nsIURI uri, in string type, in PRUint32 permission); */
NS_IMETHODIMP nsPermissionManager::Add(nsIURI *uri, const char *type, PRUint32 permission)
{
    return NS_ERROR_NOT_IMPLEMENTED;
}

/* void remove (in AUTF8String host, in string type); */
NS_IMETHODIMP nsPermissionManager::Remove(const nsACString & host, const char *type)
{
    return NS_ERROR_NOT_IMPLEMENTED;
}

/* void removeAll (); */
NS_IMETHODIMP nsPermissionManager::RemoveAll()
{
    return NS_ERROR_NOT_IMPLEMENTED;
}

/* PRUint32 testPermission (in nsIURI uri, in string type); */
NS_IMETHODIMP nsPermissionManager::TestPermission(nsIURI *uri, const char *type, PRUint32 *_retval NS_OUTPARAM)
{
    return NS_ERROR_NOT_IMPLEMENTED;
}

/* PRUint32 testExactPermission (in nsIURI uri, in string type); */
NS_IMETHODIMP nsPermissionManager::TestExactPermission(nsIURI *uri, const char *type, PRUint32 *_retval NS_OUTPARAM)
{
    return NS_ERROR_NOT_IMPLEMENTED;
}

/* readonly attribute nsISimpleEnumerator enumerator; */
NS_IMETHODIMP nsPermissionManager::GetEnumerator(nsISimpleEnumerator * *aEnumerator)
{
    return NS_ERROR_NOT_IMPLEMENTED;
}

/* End of implementation class template. */
#endif

#define NS_PERMISSIONMANAGER_CONTRACTID "@mozilla.org/permissionmanager;1"
#define PERM_CHANGE_NOTIFICATION "perm-changed"

#endif /* __gen_nsIPermissionManager_h__ */
