/*
 * DO NOT EDIT.  THIS FILE IS GENERATED FROM e:/builds/moz2_slave/mozilla-1.9.1-win32-xulrunner/build/xpcom/system/nsIBlocklistService.idl
 */

#ifndef __gen_nsIBlocklistService_h__
#define __gen_nsIBlocklistService_h__


#ifndef __gen_nsISupports_h__
#include "nsISupports.h"
#endif

/* For IDL files that don't want to include root IDL files. */
#ifndef NS_NO_VTABLE
#define NS_NO_VTABLE
#endif
class nsIPluginTag; /* forward declaration */


/* starting interface:    nsIBlocklistService */
#define NS_IBLOCKLISTSERVICE_IID_STR "8439f9c0-da03-4260-8b21-dc635eed28fb"

#define NS_IBLOCKLISTSERVICE_IID \
  {0x8439f9c0, 0xda03, 0x4260, \
    { 0x8b, 0x21, 0xdc, 0x63, 0x5e, 0xed, 0x28, 0xfb }}

class NS_NO_VTABLE NS_SCRIPTABLE nsIBlocklistService : public nsISupports {
 public: 

  NS_DECLARE_STATIC_IID_ACCESSOR(NS_IBLOCKLISTSERVICE_IID)

  enum { STATE_NOT_BLOCKED = 0U };

  enum { STATE_SOFTBLOCKED = 1U };

  enum { STATE_BLOCKED = 2U };

  /**
   * Determine if an item is blocklisted
   * @param   id
   *          The ID of the item.
   * @param   version
   *          The item's version.
   * @param   appVersion
   *          The version of the application we are checking in the blocklist.
   *          If this parameter is null, the version of the running application
   *          is used.
   * @param   toolkitVersion
   *          The version of the toolkit we are checking in the blocklist.
   *          If this parameter is null, the version of the running toolkit
   *          is used.
   * @returns true if the item is compatible with this version of the
   *          application or this version of the toolkit, false, otherwise.
   */
  /* boolean isAddonBlocklisted (in AString id, in AString version, [optional] in AString appVersion, [optional] in AString toolkitVersion); */
  NS_SCRIPTABLE NS_IMETHOD IsAddonBlocklisted(const nsAString & id, const nsAString & version, const nsAString & appVersion, const nsAString & toolkitVersion, PRBool *_retval NS_OUTPARAM) = 0;

  /**
   * Determine the blocklist state of an add-on
   * @param   id
   *          The ID of the item.
   * @param   version
   *          The item's version.
   * @param   appVersion
   *          The version of the application we are checking in the blocklist.
   *          If this parameter is null, the version of the running application
   *          is used.
   * @param   toolkitVersion
   *          The version of the toolkit we are checking in the blocklist.
   *          If this parameter is null, the version of the running toolkit
   *          is used.
   * @returns The STATE constant.
   */
  /* unsigned long getAddonBlocklistState (in AString id, in AString version, [optional] in AString appVersion, [optional] in AString toolkitVersion); */
  NS_SCRIPTABLE NS_IMETHOD GetAddonBlocklistState(const nsAString & id, const nsAString & version, const nsAString & appVersion, const nsAString & toolkitVersion, PRUint32 *_retval NS_OUTPARAM) = 0;

  /**
   * Determine the blocklist state of a plugin
   * @param   plugin
   *          The plugin to get the state for
   * @param   appVersion
   *          The version of the application we are checking in the blocklist.
   *          If this parameter is null, the version of the running application
   *          is used.
   * @param   toolkitVersion
   *          The version of the toolkit we are checking in the blocklist.
   *          If this parameter is null, the version of the running toolkit
   *          is used.
   * @returns The STATE constant.
   */
  /* unsigned long getPluginBlocklistState (in nsIPluginTag plugin, [optional] in AString appVersion, [optional] in AString toolkitVersion); */
  NS_SCRIPTABLE NS_IMETHOD GetPluginBlocklistState(nsIPluginTag *plugin, const nsAString & appVersion, const nsAString & toolkitVersion, PRUint32 *_retval NS_OUTPARAM) = 0;

};

  NS_DEFINE_STATIC_IID_ACCESSOR(nsIBlocklistService, NS_IBLOCKLISTSERVICE_IID)

/* Use this macro when declaring classes that implement this interface. */
#define NS_DECL_NSIBLOCKLISTSERVICE \
  NS_SCRIPTABLE NS_IMETHOD IsAddonBlocklisted(const nsAString & id, const nsAString & version, const nsAString & appVersion, const nsAString & toolkitVersion, PRBool *_retval NS_OUTPARAM); \
  NS_SCRIPTABLE NS_IMETHOD GetAddonBlocklistState(const nsAString & id, const nsAString & version, const nsAString & appVersion, const nsAString & toolkitVersion, PRUint32 *_retval NS_OUTPARAM); \
  NS_SCRIPTABLE NS_IMETHOD GetPluginBlocklistState(nsIPluginTag *plugin, const nsAString & appVersion, const nsAString & toolkitVersion, PRUint32 *_retval NS_OUTPARAM); 

/* Use this macro to declare functions that forward the behavior of this interface to another object. */
#define NS_FORWARD_NSIBLOCKLISTSERVICE(_to) \
  NS_SCRIPTABLE NS_IMETHOD IsAddonBlocklisted(const nsAString & id, const nsAString & version, const nsAString & appVersion, const nsAString & toolkitVersion, PRBool *_retval NS_OUTPARAM) { return _to IsAddonBlocklisted(id, version, appVersion, toolkitVersion, _retval); } \
  NS_SCRIPTABLE NS_IMETHOD GetAddonBlocklistState(const nsAString & id, const nsAString & version, const nsAString & appVersion, const nsAString & toolkitVersion, PRUint32 *_retval NS_OUTPARAM) { return _to GetAddonBlocklistState(id, version, appVersion, toolkitVersion, _retval); } \
  NS_SCRIPTABLE NS_IMETHOD GetPluginBlocklistState(nsIPluginTag *plugin, const nsAString & appVersion, const nsAString & toolkitVersion, PRUint32 *_retval NS_OUTPARAM) { return _to GetPluginBlocklistState(plugin, appVersion, toolkitVersion, _retval); } 

/* Use this macro to declare functions that forward the behavior of this interface to another object in a safe way. */
#define NS_FORWARD_SAFE_NSIBLOCKLISTSERVICE(_to) \
  NS_SCRIPTABLE NS_IMETHOD IsAddonBlocklisted(const nsAString & id, const nsAString & version, const nsAString & appVersion, const nsAString & toolkitVersion, PRBool *_retval NS_OUTPARAM) { return !_to ? NS_ERROR_NULL_POINTER : _to->IsAddonBlocklisted(id, version, appVersion, toolkitVersion, _retval); } \
  NS_SCRIPTABLE NS_IMETHOD GetAddonBlocklistState(const nsAString & id, const nsAString & version, const nsAString & appVersion, const nsAString & toolkitVersion, PRUint32 *_retval NS_OUTPARAM) { return !_to ? NS_ERROR_NULL_POINTER : _to->GetAddonBlocklistState(id, version, appVersion, toolkitVersion, _retval); } \
  NS_SCRIPTABLE NS_IMETHOD GetPluginBlocklistState(nsIPluginTag *plugin, const nsAString & appVersion, const nsAString & toolkitVersion, PRUint32 *_retval NS_OUTPARAM) { return !_to ? NS_ERROR_NULL_POINTER : _to->GetPluginBlocklistState(plugin, appVersion, toolkitVersion, _retval); } 

#if 0
/* Use the code below as a template for the implementation class for this interface. */

/* Header file */
class nsBlocklistService : public nsIBlocklistService
{
public:
  NS_DECL_ISUPPORTS
  NS_DECL_NSIBLOCKLISTSERVICE

  nsBlocklistService();

private:
  ~nsBlocklistService();

protected:
  /* additional members */
};

/* Implementation file */
NS_IMPL_ISUPPORTS1(nsBlocklistService, nsIBlocklistService)

nsBlocklistService::nsBlocklistService()
{
  /* member initializers and constructor code */
}

nsBlocklistService::~nsBlocklistService()
{
  /* destructor code */
}

/* boolean isAddonBlocklisted (in AString id, in AString version, [optional] in AString appVersion, [optional] in AString toolkitVersion); */
NS_IMETHODIMP nsBlocklistService::IsAddonBlocklisted(const nsAString & id, const nsAString & version, const nsAString & appVersion, const nsAString & toolkitVersion, PRBool *_retval NS_OUTPARAM)
{
    return NS_ERROR_NOT_IMPLEMENTED;
}

/* unsigned long getAddonBlocklistState (in AString id, in AString version, [optional] in AString appVersion, [optional] in AString toolkitVersion); */
NS_IMETHODIMP nsBlocklistService::GetAddonBlocklistState(const nsAString & id, const nsAString & version, const nsAString & appVersion, const nsAString & toolkitVersion, PRUint32 *_retval NS_OUTPARAM)
{
    return NS_ERROR_NOT_IMPLEMENTED;
}

/* unsigned long getPluginBlocklistState (in nsIPluginTag plugin, [optional] in AString appVersion, [optional] in AString toolkitVersion); */
NS_IMETHODIMP nsBlocklistService::GetPluginBlocklistState(nsIPluginTag *plugin, const nsAString & appVersion, const nsAString & toolkitVersion, PRUint32 *_retval NS_OUTPARAM)
{
    return NS_ERROR_NOT_IMPLEMENTED;
}

/* End of implementation class template. */
#endif


#endif /* __gen_nsIBlocklistService_h__ */
