/*
 * DO NOT EDIT.  THIS FILE IS GENERATED FROM e:/builds/moz2_slave/mozilla-1.9.1-win32-xulrunner/build/toolkit/mozapps/extensions/public/nsIExtensionManager.idl
 */

#ifndef __gen_nsIExtensionManager_h__
#define __gen_nsIExtensionManager_h__


#ifndef __gen_nsISupports_h__
#include "nsISupports.h"
#endif

/* For IDL files that don't want to include root IDL files. */
#ifndef NS_NO_VTABLE
#define NS_NO_VTABLE
#endif
class nsIFile; /* forward declaration */

class nsIRDFDataSource; /* forward declaration */

class nsIUpdateItem; /* forward declaration */

class nsIAddonInstallListener; /* forward declaration */

class nsIAddonUpdateCheckListener; /* forward declaration */

class nsICommandLine; /* forward declaration */

class nsISimpleEnumerator; /* forward declaration */

class nsIDirectoryEnumerator; /* forward declaration */

class nsIObserver; /* forward declaration */


/* starting interface:    nsIInstallLocation */
#define NS_IINSTALLLOCATION_IID_STR "32a74707-ec7c-af19-f4d8-d0cd8cb6a948"

#define NS_IINSTALLLOCATION_IID \
  {0x32a74707, 0xec7c, 0xaf19, \
    { 0xf4, 0xd8, 0xd0, 0xcd, 0x8c, 0xb6, 0xa9, 0x48 }}

/**
 * Interface representing a location where extensions, themes etc are
 * installed.
 */
class NS_NO_VTABLE NS_SCRIPTABLE nsIInstallLocation : public nsISupports {
 public: 

  NS_DECLARE_STATIC_IID_ACCESSOR(NS_IINSTALLLOCATION_IID)

  /**
   * The string identifier of this Install Location
   */
  /* readonly attribute AString name; */
  NS_SCRIPTABLE NS_IMETHOD GetName(nsAString & aName) = 0;

  /**
   * An enumeration of nsIFiles for:
   * - locations that contain items
   * - potential dropped-in XPIs
   * Note: This enumeration resolves Text Links to the directories they
   *       refer to.
   */
  /* readonly attribute nsIDirectoryEnumerator itemLocations; */
  NS_SCRIPTABLE NS_IMETHOD GetItemLocations(nsIDirectoryEnumerator * *aItemLocations) = 0;

  /**
   * The file system location where items live. Items can be dropped in
   * at this location. Can be null for Install Locations that don't have
   * a file system presence.
   * Note: This is a clone of the actual location which the caller can
   *       modify freely.
   */
  /* readonly attribute nsIFile location; */
  NS_SCRIPTABLE NS_IMETHOD GetLocation(nsIFile * *aLocation) = 0;

  /**
   * Whether or not this Install Location is on an area of the file system
   * that could be restricted on a restricted-access account, regardless
   * of whether or not the location is restricted with the current user
   * privileges.
   */
  /* readonly attribute boolean restricted; */
  NS_SCRIPTABLE NS_IMETHOD GetRestricted(PRBool *aRestricted) = 0;

  /**
   * Whether or not the user can write to the Install Location with the
   * current access privileges. This is different from restricted because
   * it's not whether or not the location *might* be restricted, it's
   * whether or not it actually *is* restricted right now.
   */
  /* readonly attribute boolean canAccess; */
  NS_SCRIPTABLE NS_IMETHOD GetCanAccess(PRBool *aCanAccess) = 0;

  /**
   * Constants representing priority of some default Install Locations.
   * XXXben - priority ranking of user-level items vs. global-level items
   *          here is debatable. Should app-system-global trump
   *          xre-system-user?
   * You should not use the exact values here, you should offset from
   * these values each time you create a new Install Location. Offsetting
   * can be brittle but you should know what Install Locations are being
   * defined for your own application.
   */
  enum { PRIORITY_APP_PROFILE = 0U };

  enum { PRIORITY_APP_SYSTEM_USER = 10U };

  enum { PRIORITY_XRE_SYSTEM_USER = 100U };

  enum { PRIORITY_APP_SYSTEM_GLOBAL = 1000U };

  enum { PRIORITY_XRE_SYSTEM_GLOBAL = 10000U };

  /**
   * The priority level of this Install Location in loading.
   */
  /* readonly attribute long priority; */
  NS_SCRIPTABLE NS_IMETHOD GetPriority(PRInt32 *aPriority) = 0;

  /**
   * Gets the directory that contains an item.
   * @param   id
   *          The GUID of the item.
   * @returns The location of the item.
   */
  /* nsIFile getItemLocation (in AString id); */
  NS_SCRIPTABLE NS_IMETHOD GetItemLocation(const nsAString & id, nsIFile **_retval NS_OUTPARAM) = 0;

  /**
   * Retrieves the GUID for an item at the specified location.
   * @param   file
   *          The location where an item might live.
   * @returns The ID for an item that might live at the location specified.
   *
   * N.B. This function makes no promises about whether or not this path is
   *      actually maintained by this Install Location.
   */
  /* AString getIDForLocation (in nsIFile file); */
  NS_SCRIPTABLE NS_IMETHOD GetIDForLocation(nsIFile *file, nsAString & _retval NS_OUTPARAM) = 0;

  /**
   * Gets a nsIFile object for a file within an item's directory structure.
   * @param   id
   *          The GUID of the item.
   * @param   path
   *          The path to the file beneath an Extension's directory
   * @returns A file object at the requested location. The file does not
   *          necessarily have to exist.
   */
  /* nsIFile getItemFile (in AString id, in AString path); */
  NS_SCRIPTABLE NS_IMETHOD GetItemFile(const nsAString & id, const nsAString & path, nsIFile **_retval NS_OUTPARAM) = 0;

  /**
   * Determines whether or not an item's resources are managed by the Extension
   * System or by some other user or process. For example, items linked to by
   * text links are managed by the user, and items linked to from Registry
   * Install Locations are usually managed by other applications or installers.
   *
   * @param   id
   *          The GUID of the item.
   * @returns true if the item's resources are managed independently of the
   *          Extension System, false otherwise.
   */
  /* boolean itemIsManagedIndependently (in AString id); */
  NS_SCRIPTABLE NS_IMETHOD ItemIsManagedIndependently(const nsAString & id, PRBool *_retval NS_OUTPARAM) = 0;

  /**
   * Stages the specified file by copying it to some location from where it
   * can be retrieved later to complete installation.
   *
   * @param   file
   *          The file to stage
   * @param   id
   *          The GUID of the item the file represents
   * @returns The staged file
   */
  /* nsIFile stageFile (in nsIFile file, in AString id); */
  NS_SCRIPTABLE NS_IMETHOD StageFile(nsIFile *file, const nsAString & id, nsIFile **_retval NS_OUTPARAM) = 0;

  /**
   * Returns the most recently staged package (e.g. the last XPI or JAR in a
   * directory) for an item and removes items that do not qualify.
   *
   * @param   id
   *          The ID of the staged package
   * @returns an nsIFile if the package exists otherwise null.
   */
  /* nsIFile getStageFile (in AString id); */
  NS_SCRIPTABLE NS_IMETHOD GetStageFile(const nsAString & id, nsIFile **_retval NS_OUTPARAM) = 0;

  /**
   * Removes a file from the stage. This cleans up the stage if there is nothing
   * else left after the remove operation.
   *
   * @param   file
   *          The file to remove.
   */
  /* void removeFile (in nsIFile file); */
  NS_SCRIPTABLE NS_IMETHOD RemoveFile(nsIFile *file) = 0;

};

  NS_DEFINE_STATIC_IID_ACCESSOR(nsIInstallLocation, NS_IINSTALLLOCATION_IID)

/* Use this macro when declaring classes that implement this interface. */
#define NS_DECL_NSIINSTALLLOCATION \
  NS_SCRIPTABLE NS_IMETHOD GetName(nsAString & aName); \
  NS_SCRIPTABLE NS_IMETHOD GetItemLocations(nsIDirectoryEnumerator * *aItemLocations); \
  NS_SCRIPTABLE NS_IMETHOD GetLocation(nsIFile * *aLocation); \
  NS_SCRIPTABLE NS_IMETHOD GetRestricted(PRBool *aRestricted); \
  NS_SCRIPTABLE NS_IMETHOD GetCanAccess(PRBool *aCanAccess); \
  NS_SCRIPTABLE NS_IMETHOD GetPriority(PRInt32 *aPriority); \
  NS_SCRIPTABLE NS_IMETHOD GetItemLocation(const nsAString & id, nsIFile **_retval NS_OUTPARAM); \
  NS_SCRIPTABLE NS_IMETHOD GetIDForLocation(nsIFile *file, nsAString & _retval NS_OUTPARAM); \
  NS_SCRIPTABLE NS_IMETHOD GetItemFile(const nsAString & id, const nsAString & path, nsIFile **_retval NS_OUTPARAM); \
  NS_SCRIPTABLE NS_IMETHOD ItemIsManagedIndependently(const nsAString & id, PRBool *_retval NS_OUTPARAM); \
  NS_SCRIPTABLE NS_IMETHOD StageFile(nsIFile *file, const nsAString & id, nsIFile **_retval NS_OUTPARAM); \
  NS_SCRIPTABLE NS_IMETHOD GetStageFile(const nsAString & id, nsIFile **_retval NS_OUTPARAM); \
  NS_SCRIPTABLE NS_IMETHOD RemoveFile(nsIFile *file); 

/* Use this macro to declare functions that forward the behavior of this interface to another object. */
#define NS_FORWARD_NSIINSTALLLOCATION(_to) \
  NS_SCRIPTABLE NS_IMETHOD GetName(nsAString & aName) { return _to GetName(aName); } \
  NS_SCRIPTABLE NS_IMETHOD GetItemLocations(nsIDirectoryEnumerator * *aItemLocations) { return _to GetItemLocations(aItemLocations); } \
  NS_SCRIPTABLE NS_IMETHOD GetLocation(nsIFile * *aLocation) { return _to GetLocation(aLocation); } \
  NS_SCRIPTABLE NS_IMETHOD GetRestricted(PRBool *aRestricted) { return _to GetRestricted(aRestricted); } \
  NS_SCRIPTABLE NS_IMETHOD GetCanAccess(PRBool *aCanAccess) { return _to GetCanAccess(aCanAccess); } \
  NS_SCRIPTABLE NS_IMETHOD GetPriority(PRInt32 *aPriority) { return _to GetPriority(aPriority); } \
  NS_SCRIPTABLE NS_IMETHOD GetItemLocation(const nsAString & id, nsIFile **_retval NS_OUTPARAM) { return _to GetItemLocation(id, _retval); } \
  NS_SCRIPTABLE NS_IMETHOD GetIDForLocation(nsIFile *file, nsAString & _retval NS_OUTPARAM) { return _to GetIDForLocation(file, _retval); } \
  NS_SCRIPTABLE NS_IMETHOD GetItemFile(const nsAString & id, const nsAString & path, nsIFile **_retval NS_OUTPARAM) { return _to GetItemFile(id, path, _retval); } \
  NS_SCRIPTABLE NS_IMETHOD ItemIsManagedIndependently(const nsAString & id, PRBool *_retval NS_OUTPARAM) { return _to ItemIsManagedIndependently(id, _retval); } \
  NS_SCRIPTABLE NS_IMETHOD StageFile(nsIFile *file, const nsAString & id, nsIFile **_retval NS_OUTPARAM) { return _to StageFile(file, id, _retval); } \
  NS_SCRIPTABLE NS_IMETHOD GetStageFile(const nsAString & id, nsIFile **_retval NS_OUTPARAM) { return _to GetStageFile(id, _retval); } \
  NS_SCRIPTABLE NS_IMETHOD RemoveFile(nsIFile *file) { return _to RemoveFile(file); } 

/* Use this macro to declare functions that forward the behavior of this interface to another object in a safe way. */
#define NS_FORWARD_SAFE_NSIINSTALLLOCATION(_to) \
  NS_SCRIPTABLE NS_IMETHOD GetName(nsAString & aName) { return !_to ? NS_ERROR_NULL_POINTER : _to->GetName(aName); } \
  NS_SCRIPTABLE NS_IMETHOD GetItemLocations(nsIDirectoryEnumerator * *aItemLocations) { return !_to ? NS_ERROR_NULL_POINTER : _to->GetItemLocations(aItemLocations); } \
  NS_SCRIPTABLE NS_IMETHOD GetLocation(nsIFile * *aLocation) { return !_to ? NS_ERROR_NULL_POINTER : _to->GetLocation(aLocation); } \
  NS_SCRIPTABLE NS_IMETHOD GetRestricted(PRBool *aRestricted) { return !_to ? NS_ERROR_NULL_POINTER : _to->GetRestricted(aRestricted); } \
  NS_SCRIPTABLE NS_IMETHOD GetCanAccess(PRBool *aCanAccess) { return !_to ? NS_ERROR_NULL_POINTER : _to->GetCanAccess(aCanAccess); } \
  NS_SCRIPTABLE NS_IMETHOD GetPriority(PRInt32 *aPriority) { return !_to ? NS_ERROR_NULL_POINTER : _to->GetPriority(aPriority); } \
  NS_SCRIPTABLE NS_IMETHOD GetItemLocation(const nsAString & id, nsIFile **_retval NS_OUTPARAM) { return !_to ? NS_ERROR_NULL_POINTER : _to->GetItemLocation(id, _retval); } \
  NS_SCRIPTABLE NS_IMETHOD GetIDForLocation(nsIFile *file, nsAString & _retval NS_OUTPARAM) { return !_to ? NS_ERROR_NULL_POINTER : _to->GetIDForLocation(file, _retval); } \
  NS_SCRIPTABLE NS_IMETHOD GetItemFile(const nsAString & id, const nsAString & path, nsIFile **_retval NS_OUTPARAM) { return !_to ? NS_ERROR_NULL_POINTER : _to->GetItemFile(id, path, _retval); } \
  NS_SCRIPTABLE NS_IMETHOD ItemIsManagedIndependently(const nsAString & id, PRBool *_retval NS_OUTPARAM) { return !_to ? NS_ERROR_NULL_POINTER : _to->ItemIsManagedIndependently(id, _retval); } \
  NS_SCRIPTABLE NS_IMETHOD StageFile(nsIFile *file, const nsAString & id, nsIFile **_retval NS_OUTPARAM) { return !_to ? NS_ERROR_NULL_POINTER : _to->StageFile(file, id, _retval); } \
  NS_SCRIPTABLE NS_IMETHOD GetStageFile(const nsAString & id, nsIFile **_retval NS_OUTPARAM) { return !_to ? NS_ERROR_NULL_POINTER : _to->GetStageFile(id, _retval); } \
  NS_SCRIPTABLE NS_IMETHOD RemoveFile(nsIFile *file) { return !_to ? NS_ERROR_NULL_POINTER : _to->RemoveFile(file); } 

#if 0
/* Use the code below as a template for the implementation class for this interface. */

/* Header file */
class nsInstallLocation : public nsIInstallLocation
{
public:
  NS_DECL_ISUPPORTS
  NS_DECL_NSIINSTALLLOCATION

  nsInstallLocation();

private:
  ~nsInstallLocation();

protected:
  /* additional members */
};

/* Implementation file */
NS_IMPL_ISUPPORTS1(nsInstallLocation, nsIInstallLocation)

nsInstallLocation::nsInstallLocation()
{
  /* member initializers and constructor code */
}

nsInstallLocation::~nsInstallLocation()
{
  /* destructor code */
}

/* readonly attribute AString name; */
NS_IMETHODIMP nsInstallLocation::GetName(nsAString & aName)
{
    return NS_ERROR_NOT_IMPLEMENTED;
}

/* readonly attribute nsIDirectoryEnumerator itemLocations; */
NS_IMETHODIMP nsInstallLocation::GetItemLocations(nsIDirectoryEnumerator * *aItemLocations)
{
    return NS_ERROR_NOT_IMPLEMENTED;
}

/* readonly attribute nsIFile location; */
NS_IMETHODIMP nsInstallLocation::GetLocation(nsIFile * *aLocation)
{
    return NS_ERROR_NOT_IMPLEMENTED;
}

/* readonly attribute boolean restricted; */
NS_IMETHODIMP nsInstallLocation::GetRestricted(PRBool *aRestricted)
{
    return NS_ERROR_NOT_IMPLEMENTED;
}

/* readonly attribute boolean canAccess; */
NS_IMETHODIMP nsInstallLocation::GetCanAccess(PRBool *aCanAccess)
{
    return NS_ERROR_NOT_IMPLEMENTED;
}

/* readonly attribute long priority; */
NS_IMETHODIMP nsInstallLocation::GetPriority(PRInt32 *aPriority)
{
    return NS_ERROR_NOT_IMPLEMENTED;
}

/* nsIFile getItemLocation (in AString id); */
NS_IMETHODIMP nsInstallLocation::GetItemLocation(const nsAString & id, nsIFile **_retval NS_OUTPARAM)
{
    return NS_ERROR_NOT_IMPLEMENTED;
}

/* AString getIDForLocation (in nsIFile file); */
NS_IMETHODIMP nsInstallLocation::GetIDForLocation(nsIFile *file, nsAString & _retval NS_OUTPARAM)
{
    return NS_ERROR_NOT_IMPLEMENTED;
}

/* nsIFile getItemFile (in AString id, in AString path); */
NS_IMETHODIMP nsInstallLocation::GetItemFile(const nsAString & id, const nsAString & path, nsIFile **_retval NS_OUTPARAM)
{
    return NS_ERROR_NOT_IMPLEMENTED;
}

/* boolean itemIsManagedIndependently (in AString id); */
NS_IMETHODIMP nsInstallLocation::ItemIsManagedIndependently(const nsAString & id, PRBool *_retval NS_OUTPARAM)
{
    return NS_ERROR_NOT_IMPLEMENTED;
}

/* nsIFile stageFile (in nsIFile file, in AString id); */
NS_IMETHODIMP nsInstallLocation::StageFile(nsIFile *file, const nsAString & id, nsIFile **_retval NS_OUTPARAM)
{
    return NS_ERROR_NOT_IMPLEMENTED;
}

/* nsIFile getStageFile (in AString id); */
NS_IMETHODIMP nsInstallLocation::GetStageFile(const nsAString & id, nsIFile **_retval NS_OUTPARAM)
{
    return NS_ERROR_NOT_IMPLEMENTED;
}

/* void removeFile (in nsIFile file); */
NS_IMETHODIMP nsInstallLocation::RemoveFile(nsIFile *file)
{
    return NS_ERROR_NOT_IMPLEMENTED;
}

/* End of implementation class template. */
#endif


/* starting interface:    nsIExtensionManager */
#define NS_IEXTENSIONMANAGER_IID_STR "7fbb049a-00e6-4ce2-82fc-854c52788df9"

#define NS_IEXTENSIONMANAGER_IID \
  {0x7fbb049a, 0x00e6, 0x4ce2, \
    { 0x82, 0xfc, 0x85, 0x4c, 0x52, 0x78, 0x8d, 0xf9 }}

/**
 * Interface representing a system for the installation and management of
 * Extensions, Themes etc.
 *
 * XXXben - Some of this stuff should go into a management-ey interface,
 *          some into an app-startup-ey interface.
 */
class NS_NO_VTABLE NS_SCRIPTABLE nsIExtensionManager : public nsISupports {
 public: 

  NS_DECLARE_STATIC_IID_ACCESSOR(NS_IEXTENSIONMANAGER_IID)

  /**
   * Constants representing types of update checks.
   */
  enum { UPDATE_CHECK_NEWVERSION = 0U };

  enum { UPDATE_CHECK_COMPATIBILITY = 1U };

  enum { UPDATE_SYNC_COMPATIBILITY = 2U };

  enum { UPDATE_NOTIFY_NEWVERSION = 3U };

  /**
   * Starts the Extension Manager, checking for item changes, additions and
   * removals, and finishing pending operations.
   * @param   commandLine
   *          The command line the application was started with.
   * @returns true if the application has rewritten the extensions.ini file
   *          and needs to restart to register components/chrome etc,
   *          false otherwise
   */
  /* boolean start (in nsICommandLine commandLine); */
  NS_SCRIPTABLE NS_IMETHOD Start(nsICommandLine *commandLine, PRBool *_retval NS_OUTPARAM) = 0;

  /**
   * Determines if there are incompatible items installed (and offers to
   * upgrade them to newer versions if available, via a UI).
   * @returns true if there were incompatible items that were disabled
   *          and the application needs to restart to re-register components,
   *          chrome etc, false otherwise.
   */
  /* boolean checkForMismatches (); */
  NS_SCRIPTABLE NS_IMETHOD CheckForMismatches(PRBool *_retval NS_OUTPARAM) = 0;

  /**
   * Handle command line flags, e.g. -install-global-[extension|theme]
   * @param   cmdLine
   *          the command line the application was started with
   * XXXben - move this off this API - currently it is only used for
   *          global installation, and the apprunner can do this directly
   *          with |installItemFromFile|
   */
  /* void handleCommandLineArgs (in nsICommandLine cmdline); */
  NS_SCRIPTABLE NS_IMETHOD HandleCommandLineArgs(nsICommandLine *cmdline) = 0;

  /**
   * Gets the Install Location for an item
   * @param   id
   *          The GUID of the item
   * @returns The Install Location where the item is installed or null if the
   *          location cannot be obtained (e.g. an invalid id).
   */
  /* nsIInstallLocation getInstallLocation (in AString id); */
  NS_SCRIPTABLE NS_IMETHOD GetInstallLocation(const nsAString & id, nsIInstallLocation **_retval NS_OUTPARAM) = 0;

  /**
   * An enumeration of all registered Install Items
   */
  /* readonly attribute nsISimpleEnumerator installLocations; */
  NS_SCRIPTABLE NS_IMETHOD GetInstallLocations(nsISimpleEnumerator * *aInstallLocations) = 0;

  /**
   * Installs an item from a XPI/JAR file into the location specified.
   * @param   xpiFile
   *          The source file to install from. This function stages a copy
   *          of this file for persistence across potential application
   *          restarts, you are responsible for removing the file you pass
   *          in.
   * @param   installLocationKey
   *          The name identifier of an Install Location to install into.
   */
  /* void installItemFromFile (in nsIFile xpiFile, in AString installLocationKey); */
  NS_SCRIPTABLE NS_IMETHOD InstallItemFromFile(nsIFile *xpiFile, const nsAString & installLocationKey) = 0;

  /**
   * Uninstalls an item
   * @param   id
   *          The GUID of the item.
   */
  /* void uninstallItem (in AString id); */
  NS_SCRIPTABLE NS_IMETHOD UninstallItem(const nsAString & id) = 0;

  /**
   * Enables a disabled item
   * @param   id
   *          The GUID of the item.
   */
  /* void enableItem (in AString id); */
  NS_SCRIPTABLE NS_IMETHOD EnableItem(const nsAString & id) = 0;

  /**
   * Disables an enabled item
   * @param   id
   *          The GUID of the item.
   */
  /* void disableItem (in AString id); */
  NS_SCRIPTABLE NS_IMETHOD DisableItem(const nsAString & id) = 0;

  /**
   * Checks for updates to a list of items.
   * @param   items
   *          An array of nsIUpdateItems to check for updates for.
   * @param   itemCount
   *          The length of |items|
   * @param   updateCheckType
   *          UPDATE_CHECK_NEWVERSION if this check should find the newest
   *          versions available and write the results to the extensions
   *          datasource.
   *          UPDATE_CHECK_COMPATIBILITY if this check should only find newer
   *          target application compatibility information for the currently
   *          installed version and write the results to the extensions
   *          datasource.
   *          UPDATE_SYNC_COMPATIBILITY if this check should only find target
   *          application compatibility information for the currently
   *          installed version and synchronize the values to the extensions
   *          datasource.
   *          UPDATE_NOTIFY_NEWVERSION if this check should find the newest
   *          versions available without updating the extensions datasource.
   * @param   listener
   *          An nsIAddonUpdateCheckListener object which will be notified
   *          during the update check process. If not null, the object's
   *          onUpdateStarted() and onUpdateEnded() methods will be called even
   *          if there are no items to update.
   * @param   appVersion (optional)
   *          The version of the application to check for compatible updates.
   *          This param is only honored when updateCheckType is equal to
   *          UPDATE_NOTIFY_NEWVERSION and it defaults to the current version of
   *          the application when it is not specified.
   * @param   platformVersion (optional)
   *          The version of the toolkit to check for compatible updates.
   *          This param is only honored when updateCheckType is equal to
   *          UPDATE_NOTIFY_NEWVERSION and it defaults to the current version of
   *          the toolkit when it is not specified.
   *
   * @throws  NS_ERROR_ILLEGAL_VALUE if any item is invalid.
   */
  /* void update ([array, size_is (itemCount)] in nsIUpdateItem items, in unsigned long itemCount, in unsigned long updateCheckType, in nsIAddonUpdateCheckListener listener, [optional] in AString appVersion, [optional] in AString platformVersion); */
  NS_SCRIPTABLE NS_IMETHOD Update(nsIUpdateItem **items, PRUint32 itemCount, PRUint32 updateCheckType, nsIAddonUpdateCheckListener *listener, const nsAString & appVersion, const nsAString & platformVersion) = 0;

  /**
   * Gets a nsIUpdateItem for the item with the specified id.
   * @param   id
   *          The GUID of the item to construct a nsIUpdateItem for.
   * @returns The nsIUpdateItem representing the item or null if the item does
   *          not exist.
   */
  /* nsIUpdateItem getItemForID (in AString id); */
  NS_SCRIPTABLE NS_IMETHOD GetItemForID(const nsAString & id, nsIUpdateItem **_retval NS_OUTPARAM) = 0;

  /**
   * Retrieves a list of visible nsIUpdateItems of items matching the
   * specified type.
   * @param   type
   *          The type of item to return.
   * @param   countRef
   *          The XPCJS reference to the number of items returned.
   * @returns An array of nsIUpdateItems matching the id/type filter.
   *
   * XXXben - it would be good if this function took an optional
   *          install location.
   */
  /* void getItemList (in unsigned long type, out unsigned long itemCount, [array, size_is (itemCount), retval] out nsIUpdateItem items); */
  NS_SCRIPTABLE NS_IMETHOD GetItemList(PRUint32 type, PRUint32 *itemCount NS_OUTPARAM, nsIUpdateItem ***items NS_OUTPARAM) = 0;

  /**
   * Retrieves a list of nsIUpdateItems of items that are incompatible
   * with the supplied parameters.
   * @param   id
   *          The id of the application to check compatibility against
   * @param   appVersion
   *          The version of the application to check compatibility against
   * @param   platformVersion
   *          The version of the toolkit to check compatibility against
   * @param   type
   *          The type of item to return
   * @param   includeDisabled
   *          true if disabled items should be included in the result set,
   *          false otherwise
   * @param   countRef
   *          The XPCJS reference to the number of items returned.
   * @returns An array of incompatible nsIUpdateItems.
   */
  /* void getIncompatibleItemList (in AString id, in AString appVersion, in AString platformVersion, in unsigned long type, in boolean includeDisabled, out unsigned long itemCount, [array, size_is (itemCount), retval] out nsIUpdateItem items); */
  NS_SCRIPTABLE NS_IMETHOD GetIncompatibleItemList(const nsAString & id, const nsAString & appVersion, const nsAString & platformVersion, PRUint32 type, PRBool includeDisabled, PRUint32 *itemCount NS_OUTPARAM, nsIUpdateItem ***items NS_OUTPARAM) = 0;

  /**
   * The Extensions Datasource
   * XXXben - the datasource should be registered with the RDF system, so it
   *          can be accessed via rdf:extensions, and not exposed through the API
   *          like this.
   */
  /* readonly attribute nsIRDFDataSource datasource; */
  NS_SCRIPTABLE NS_IMETHOD GetDatasource(nsIRDFDataSource * *aDatasource) = 0;

  /**
   * Adds active download entries to the UI
   * @param   items
   *          A list of nsIUpdateItems to entries to add
   * @param   itemCount
   *          The length of |items|
   * @param   manager
   *          null when called from chrome
   *          the XPInstallManager when not called from chrome (e.g. web page)
   *
   * @throws  NS_ERROR_ILLEGAL_VALUE if any item is invalid, or if itemCount == 0.
   */
  /* void addDownloads ([array, size_is (itemCount)] in nsIUpdateItem items, in unsigned long itemCount, in nsIObserver manager); */
  NS_SCRIPTABLE NS_IMETHOD AddDownloads(nsIUpdateItem **items, PRUint32 itemCount, nsIObserver *manager) = 0;

  /**
   * Removes an active download from the UI
   * @param   url
   *          The URL of the active download to remove
   */
  /* void removeDownload (in AString url); */
  NS_SCRIPTABLE NS_IMETHOD RemoveDownload(const nsAString & url) = 0;

  /**
   * Adds an install listener so the front end can listen to download
   * and install progress.
   * @param   listener
   *          The listener to add
   * @returns the index of the added listen in the listener list.
   */
  /* long addInstallListener (in nsIAddonInstallListener listener); */
  NS_SCRIPTABLE NS_IMETHOD AddInstallListener(nsIAddonInstallListener *listener, PRInt32 *_retval NS_OUTPARAM) = 0;

  /**
   * Removes an install progress listener.
   * @param   index
   *          The index of the listener to remove.
   */
  /* void removeInstallListenerAt (in long index); */
  NS_SCRIPTABLE NS_IMETHOD RemoveInstallListenerAt(PRInt32 index) = 0;

  /**
   * Move an Item to the index of another item in its container.
   * @param   movingID
   *          The ID of an item to be moved.
   * @param   destinationID
   *          The ID of an item to move an item to.
   */
  /* void moveToIndexOf (in AString movingID, in AString destinationID); */
  NS_SCRIPTABLE NS_IMETHOD MoveToIndexOf(const nsAString & movingID, const nsAString & destinationID) = 0;

  /**
   * Cancels a pending install or upgrade of an item. If the item does
   * not have a pending install or upgrade then this will do nothing.
   * @param   id
   *          The ID of the item.
   */
  /* void cancelInstallItem (in AString id); */
  NS_SCRIPTABLE NS_IMETHOD CancelInstallItem(const nsAString & id) = 0;

  /**
   * Cancels a pending uninstall of an item
   * @param   id
   *          The ID of the item.
   */
  /* void cancelUninstallItem (in AString id); */
  NS_SCRIPTABLE NS_IMETHOD CancelUninstallItem(const nsAString & id) = 0;

  /**
   * Retrieves a list of installed nsIUpdateItems of items that are dependent
   * on another item.
   * @param   id
   *          The ID of the item that other items depend on.
   * @param   includeDisabled
   *          Whether to include disabled items in the set returned.
   * @param   countRef
   *          The XPCJS reference to the number of items returned.
   * @returns An array of installed nsIUpdateItems that depend on the item
   *          specified by the id parameter.
   */
  /* void getDependentItemListForID (in AString id, in boolean includeDisabled, out unsigned long itemCount, [array, size_is (itemCount), retval] out nsIUpdateItem items); */
  NS_SCRIPTABLE NS_IMETHOD GetDependentItemListForID(const nsAString & id, PRBool includeDisabled, PRUint32 *itemCount NS_OUTPARAM, nsIUpdateItem ***items NS_OUTPARAM) = 0;

  /**
   * Checks for changes to the blocklist using the local blocklist file.
   * This will immediately application disable items that have been hard blocked
   * and application enable items that are no longer hard blocked. It will also
   * return items that are either soft or hard blocked and aren't already
   * disabled or disabled pending a restart.
   *
   * This is likely to change or go away in the future and should not be used
   * by anyone outside of the blocklist service.
   *
   * @returns An array of nsIUpdateItems that are blocklisted or the user should
   *          be warned about but are currently enabled.
   */
  /* void updateAndGetNewBlocklistedItems (out unsigned long itemCount, [array, size_is (itemCount), retval] out nsIUpdateItem items); */
  NS_SCRIPTABLE NS_IMETHOD UpdateAndGetNewBlocklistedItems(PRUint32 *itemCount NS_OUTPARAM, nsIUpdateItem ***items NS_OUTPARAM) = 0;

  /**
   * Sorts addons of the specified type by the specified property in the
   * Extensions Datasource container starting from the top of their container.
   * If the addons are already sorted then no action is performed.
   * @param   type
   *          The nsIUpdateItem type of the items to sort.
   * @param   propertyName
   *          The RDF property name used for sorting.
   * @param   isAscending
   *          true to sort ascending and false to sort descending
   */
  /* void sortTypeByProperty (in unsigned long type, in AString propertyName, in boolean isAscending); */
  NS_SCRIPTABLE NS_IMETHOD SortTypeByProperty(PRUint32 type, const nsAString & propertyName, PRBool isAscending) = 0;

};

  NS_DEFINE_STATIC_IID_ACCESSOR(nsIExtensionManager, NS_IEXTENSIONMANAGER_IID)

/* Use this macro when declaring classes that implement this interface. */
#define NS_DECL_NSIEXTENSIONMANAGER \
  NS_SCRIPTABLE NS_IMETHOD Start(nsICommandLine *commandLine, PRBool *_retval NS_OUTPARAM); \
  NS_SCRIPTABLE NS_IMETHOD CheckForMismatches(PRBool *_retval NS_OUTPARAM); \
  NS_SCRIPTABLE NS_IMETHOD HandleCommandLineArgs(nsICommandLine *cmdline); \
  NS_SCRIPTABLE NS_IMETHOD GetInstallLocation(const nsAString & id, nsIInstallLocation **_retval NS_OUTPARAM); \
  NS_SCRIPTABLE NS_IMETHOD GetInstallLocations(nsISimpleEnumerator * *aInstallLocations); \
  NS_SCRIPTABLE NS_IMETHOD InstallItemFromFile(nsIFile *xpiFile, const nsAString & installLocationKey); \
  NS_SCRIPTABLE NS_IMETHOD UninstallItem(const nsAString & id); \
  NS_SCRIPTABLE NS_IMETHOD EnableItem(const nsAString & id); \
  NS_SCRIPTABLE NS_IMETHOD DisableItem(const nsAString & id); \
  NS_SCRIPTABLE NS_IMETHOD Update(nsIUpdateItem **items, PRUint32 itemCount, PRUint32 updateCheckType, nsIAddonUpdateCheckListener *listener, const nsAString & appVersion, const nsAString & platformVersion); \
  NS_SCRIPTABLE NS_IMETHOD GetItemForID(const nsAString & id, nsIUpdateItem **_retval NS_OUTPARAM); \
  NS_SCRIPTABLE NS_IMETHOD GetItemList(PRUint32 type, PRUint32 *itemCount NS_OUTPARAM, nsIUpdateItem ***items NS_OUTPARAM); \
  NS_SCRIPTABLE NS_IMETHOD GetIncompatibleItemList(const nsAString & id, const nsAString & appVersion, const nsAString & platformVersion, PRUint32 type, PRBool includeDisabled, PRUint32 *itemCount NS_OUTPARAM, nsIUpdateItem ***items NS_OUTPARAM); \
  NS_SCRIPTABLE NS_IMETHOD GetDatasource(nsIRDFDataSource * *aDatasource); \
  NS_SCRIPTABLE NS_IMETHOD AddDownloads(nsIUpdateItem **items, PRUint32 itemCount, nsIObserver *manager); \
  NS_SCRIPTABLE NS_IMETHOD RemoveDownload(const nsAString & url); \
  NS_SCRIPTABLE NS_IMETHOD AddInstallListener(nsIAddonInstallListener *listener, PRInt32 *_retval NS_OUTPARAM); \
  NS_SCRIPTABLE NS_IMETHOD RemoveInstallListenerAt(PRInt32 index); \
  NS_SCRIPTABLE NS_IMETHOD MoveToIndexOf(const nsAString & movingID, const nsAString & destinationID); \
  NS_SCRIPTABLE NS_IMETHOD CancelInstallItem(const nsAString & id); \
  NS_SCRIPTABLE NS_IMETHOD CancelUninstallItem(const nsAString & id); \
  NS_SCRIPTABLE NS_IMETHOD GetDependentItemListForID(const nsAString & id, PRBool includeDisabled, PRUint32 *itemCount NS_OUTPARAM, nsIUpdateItem ***items NS_OUTPARAM); \
  NS_SCRIPTABLE NS_IMETHOD UpdateAndGetNewBlocklistedItems(PRUint32 *itemCount NS_OUTPARAM, nsIUpdateItem ***items NS_OUTPARAM); \
  NS_SCRIPTABLE NS_IMETHOD SortTypeByProperty(PRUint32 type, const nsAString & propertyName, PRBool isAscending); 

/* Use this macro to declare functions that forward the behavior of this interface to another object. */
#define NS_FORWARD_NSIEXTENSIONMANAGER(_to) \
  NS_SCRIPTABLE NS_IMETHOD Start(nsICommandLine *commandLine, PRBool *_retval NS_OUTPARAM) { return _to Start(commandLine, _retval); } \
  NS_SCRIPTABLE NS_IMETHOD CheckForMismatches(PRBool *_retval NS_OUTPARAM) { return _to CheckForMismatches(_retval); } \
  NS_SCRIPTABLE NS_IMETHOD HandleCommandLineArgs(nsICommandLine *cmdline) { return _to HandleCommandLineArgs(cmdline); } \
  NS_SCRIPTABLE NS_IMETHOD GetInstallLocation(const nsAString & id, nsIInstallLocation **_retval NS_OUTPARAM) { return _to GetInstallLocation(id, _retval); } \
  NS_SCRIPTABLE NS_IMETHOD GetInstallLocations(nsISimpleEnumerator * *aInstallLocations) { return _to GetInstallLocations(aInstallLocations); } \
  NS_SCRIPTABLE NS_IMETHOD InstallItemFromFile(nsIFile *xpiFile, const nsAString & installLocationKey) { return _to InstallItemFromFile(xpiFile, installLocationKey); } \
  NS_SCRIPTABLE NS_IMETHOD UninstallItem(const nsAString & id) { return _to UninstallItem(id); } \
  NS_SCRIPTABLE NS_IMETHOD EnableItem(const nsAString & id) { return _to EnableItem(id); } \
  NS_SCRIPTABLE NS_IMETHOD DisableItem(const nsAString & id) { return _to DisableItem(id); } \
  NS_SCRIPTABLE NS_IMETHOD Update(nsIUpdateItem **items, PRUint32 itemCount, PRUint32 updateCheckType, nsIAddonUpdateCheckListener *listener, const nsAString & appVersion, const nsAString & platformVersion) { return _to Update(items, itemCount, updateCheckType, listener, appVersion, platformVersion); } \
  NS_SCRIPTABLE NS_IMETHOD GetItemForID(const nsAString & id, nsIUpdateItem **_retval NS_OUTPARAM) { return _to GetItemForID(id, _retval); } \
  NS_SCRIPTABLE NS_IMETHOD GetItemList(PRUint32 type, PRUint32 *itemCount NS_OUTPARAM, nsIUpdateItem ***items NS_OUTPARAM) { return _to GetItemList(type, itemCount, items); } \
  NS_SCRIPTABLE NS_IMETHOD GetIncompatibleItemList(const nsAString & id, const nsAString & appVersion, const nsAString & platformVersion, PRUint32 type, PRBool includeDisabled, PRUint32 *itemCount NS_OUTPARAM, nsIUpdateItem ***items NS_OUTPARAM) { return _to GetIncompatibleItemList(id, appVersion, platformVersion, type, includeDisabled, itemCount, items); } \
  NS_SCRIPTABLE NS_IMETHOD GetDatasource(nsIRDFDataSource * *aDatasource) { return _to GetDatasource(aDatasource); } \
  NS_SCRIPTABLE NS_IMETHOD AddDownloads(nsIUpdateItem **items, PRUint32 itemCount, nsIObserver *manager) { return _to AddDownloads(items, itemCount, manager); } \
  NS_SCRIPTABLE NS_IMETHOD RemoveDownload(const nsAString & url) { return _to RemoveDownload(url); } \
  NS_SCRIPTABLE NS_IMETHOD AddInstallListener(nsIAddonInstallListener *listener, PRInt32 *_retval NS_OUTPARAM) { return _to AddInstallListener(listener, _retval); } \
  NS_SCRIPTABLE NS_IMETHOD RemoveInstallListenerAt(PRInt32 index) { return _to RemoveInstallListenerAt(index); } \
  NS_SCRIPTABLE NS_IMETHOD MoveToIndexOf(const nsAString & movingID, const nsAString & destinationID) { return _to MoveToIndexOf(movingID, destinationID); } \
  NS_SCRIPTABLE NS_IMETHOD CancelInstallItem(const nsAString & id) { return _to CancelInstallItem(id); } \
  NS_SCRIPTABLE NS_IMETHOD CancelUninstallItem(const nsAString & id) { return _to CancelUninstallItem(id); } \
  NS_SCRIPTABLE NS_IMETHOD GetDependentItemListForID(const nsAString & id, PRBool includeDisabled, PRUint32 *itemCount NS_OUTPARAM, nsIUpdateItem ***items NS_OUTPARAM) { return _to GetDependentItemListForID(id, includeDisabled, itemCount, items); } \
  NS_SCRIPTABLE NS_IMETHOD UpdateAndGetNewBlocklistedItems(PRUint32 *itemCount NS_OUTPARAM, nsIUpdateItem ***items NS_OUTPARAM) { return _to UpdateAndGetNewBlocklistedItems(itemCount, items); } \
  NS_SCRIPTABLE NS_IMETHOD SortTypeByProperty(PRUint32 type, const nsAString & propertyName, PRBool isAscending) { return _to SortTypeByProperty(type, propertyName, isAscending); } 

/* Use this macro to declare functions that forward the behavior of this interface to another object in a safe way. */
#define NS_FORWARD_SAFE_NSIEXTENSIONMANAGER(_to) \
  NS_SCRIPTABLE NS_IMETHOD Start(nsICommandLine *commandLine, PRBool *_retval NS_OUTPARAM) { return !_to ? NS_ERROR_NULL_POINTER : _to->Start(commandLine, _retval); } \
  NS_SCRIPTABLE NS_IMETHOD CheckForMismatches(PRBool *_retval NS_OUTPARAM) { return !_to ? NS_ERROR_NULL_POINTER : _to->CheckForMismatches(_retval); } \
  NS_SCRIPTABLE NS_IMETHOD HandleCommandLineArgs(nsICommandLine *cmdline) { return !_to ? NS_ERROR_NULL_POINTER : _to->HandleCommandLineArgs(cmdline); } \
  NS_SCRIPTABLE NS_IMETHOD GetInstallLocation(const nsAString & id, nsIInstallLocation **_retval NS_OUTPARAM) { return !_to ? NS_ERROR_NULL_POINTER : _to->GetInstallLocation(id, _retval); } \
  NS_SCRIPTABLE NS_IMETHOD GetInstallLocations(nsISimpleEnumerator * *aInstallLocations) { return !_to ? NS_ERROR_NULL_POINTER : _to->GetInstallLocations(aInstallLocations); } \
  NS_SCRIPTABLE NS_IMETHOD InstallItemFromFile(nsIFile *xpiFile, const nsAString & installLocationKey) { return !_to ? NS_ERROR_NULL_POINTER : _to->InstallItemFromFile(xpiFile, installLocationKey); } \
  NS_SCRIPTABLE NS_IMETHOD UninstallItem(const nsAString & id) { return !_to ? NS_ERROR_NULL_POINTER : _to->UninstallItem(id); } \
  NS_SCRIPTABLE NS_IMETHOD EnableItem(const nsAString & id) { return !_to ? NS_ERROR_NULL_POINTER : _to->EnableItem(id); } \
  NS_SCRIPTABLE NS_IMETHOD DisableItem(const nsAString & id) { return !_to ? NS_ERROR_NULL_POINTER : _to->DisableItem(id); } \
  NS_SCRIPTABLE NS_IMETHOD Update(nsIUpdateItem **items, PRUint32 itemCount, PRUint32 updateCheckType, nsIAddonUpdateCheckListener *listener, const nsAString & appVersion, const nsAString & platformVersion) { return !_to ? NS_ERROR_NULL_POINTER : _to->Update(items, itemCount, updateCheckType, listener, appVersion, platformVersion); } \
  NS_SCRIPTABLE NS_IMETHOD GetItemForID(const nsAString & id, nsIUpdateItem **_retval NS_OUTPARAM) { return !_to ? NS_ERROR_NULL_POINTER : _to->GetItemForID(id, _retval); } \
  NS_SCRIPTABLE NS_IMETHOD GetItemList(PRUint32 type, PRUint32 *itemCount NS_OUTPARAM, nsIUpdateItem ***items NS_OUTPARAM) { return !_to ? NS_ERROR_NULL_POINTER : _to->GetItemList(type, itemCount, items); } \
  NS_SCRIPTABLE NS_IMETHOD GetIncompatibleItemList(const nsAString & id, const nsAString & appVersion, const nsAString & platformVersion, PRUint32 type, PRBool includeDisabled, PRUint32 *itemCount NS_OUTPARAM, nsIUpdateItem ***items NS_OUTPARAM) { return !_to ? NS_ERROR_NULL_POINTER : _to->GetIncompatibleItemList(id, appVersion, platformVersion, type, includeDisabled, itemCount, items); } \
  NS_SCRIPTABLE NS_IMETHOD GetDatasource(nsIRDFDataSource * *aDatasource) { return !_to ? NS_ERROR_NULL_POINTER : _to->GetDatasource(aDatasource); } \
  NS_SCRIPTABLE NS_IMETHOD AddDownloads(nsIUpdateItem **items, PRUint32 itemCount, nsIObserver *manager) { return !_to ? NS_ERROR_NULL_POINTER : _to->AddDownloads(items, itemCount, manager); } \
  NS_SCRIPTABLE NS_IMETHOD RemoveDownload(const nsAString & url) { return !_to ? NS_ERROR_NULL_POINTER : _to->RemoveDownload(url); } \
  NS_SCRIPTABLE NS_IMETHOD AddInstallListener(nsIAddonInstallListener *listener, PRInt32 *_retval NS_OUTPARAM) { return !_to ? NS_ERROR_NULL_POINTER : _to->AddInstallListener(listener, _retval); } \
  NS_SCRIPTABLE NS_IMETHOD RemoveInstallListenerAt(PRInt32 index) { return !_to ? NS_ERROR_NULL_POINTER : _to->RemoveInstallListenerAt(index); } \
  NS_SCRIPTABLE NS_IMETHOD MoveToIndexOf(const nsAString & movingID, const nsAString & destinationID) { return !_to ? NS_ERROR_NULL_POINTER : _to->MoveToIndexOf(movingID, destinationID); } \
  NS_SCRIPTABLE NS_IMETHOD CancelInstallItem(const nsAString & id) { return !_to ? NS_ERROR_NULL_POINTER : _to->CancelInstallItem(id); } \
  NS_SCRIPTABLE NS_IMETHOD CancelUninstallItem(const nsAString & id) { return !_to ? NS_ERROR_NULL_POINTER : _to->CancelUninstallItem(id); } \
  NS_SCRIPTABLE NS_IMETHOD GetDependentItemListForID(const nsAString & id, PRBool includeDisabled, PRUint32 *itemCount NS_OUTPARAM, nsIUpdateItem ***items NS_OUTPARAM) { return !_to ? NS_ERROR_NULL_POINTER : _to->GetDependentItemListForID(id, includeDisabled, itemCount, items); } \
  NS_SCRIPTABLE NS_IMETHOD UpdateAndGetNewBlocklistedItems(PRUint32 *itemCount NS_OUTPARAM, nsIUpdateItem ***items NS_OUTPARAM) { return !_to ? NS_ERROR_NULL_POINTER : _to->UpdateAndGetNewBlocklistedItems(itemCount, items); } \
  NS_SCRIPTABLE NS_IMETHOD SortTypeByProperty(PRUint32 type, const nsAString & propertyName, PRBool isAscending) { return !_to ? NS_ERROR_NULL_POINTER : _to->SortTypeByProperty(type, propertyName, isAscending); } 

#if 0
/* Use the code below as a template for the implementation class for this interface. */

/* Header file */
class nsExtensionManager : public nsIExtensionManager
{
public:
  NS_DECL_ISUPPORTS
  NS_DECL_NSIEXTENSIONMANAGER

  nsExtensionManager();

private:
  ~nsExtensionManager();

protected:
  /* additional members */
};

/* Implementation file */
NS_IMPL_ISUPPORTS1(nsExtensionManager, nsIExtensionManager)

nsExtensionManager::nsExtensionManager()
{
  /* member initializers and constructor code */
}

nsExtensionManager::~nsExtensionManager()
{
  /* destructor code */
}

/* boolean start (in nsICommandLine commandLine); */
NS_IMETHODIMP nsExtensionManager::Start(nsICommandLine *commandLine, PRBool *_retval NS_OUTPARAM)
{
    return NS_ERROR_NOT_IMPLEMENTED;
}

/* boolean checkForMismatches (); */
NS_IMETHODIMP nsExtensionManager::CheckForMismatches(PRBool *_retval NS_OUTPARAM)
{
    return NS_ERROR_NOT_IMPLEMENTED;
}

/* void handleCommandLineArgs (in nsICommandLine cmdline); */
NS_IMETHODIMP nsExtensionManager::HandleCommandLineArgs(nsICommandLine *cmdline)
{
    return NS_ERROR_NOT_IMPLEMENTED;
}

/* nsIInstallLocation getInstallLocation (in AString id); */
NS_IMETHODIMP nsExtensionManager::GetInstallLocation(const nsAString & id, nsIInstallLocation **_retval NS_OUTPARAM)
{
    return NS_ERROR_NOT_IMPLEMENTED;
}

/* readonly attribute nsISimpleEnumerator installLocations; */
NS_IMETHODIMP nsExtensionManager::GetInstallLocations(nsISimpleEnumerator * *aInstallLocations)
{
    return NS_ERROR_NOT_IMPLEMENTED;
}

/* void installItemFromFile (in nsIFile xpiFile, in AString installLocationKey); */
NS_IMETHODIMP nsExtensionManager::InstallItemFromFile(nsIFile *xpiFile, const nsAString & installLocationKey)
{
    return NS_ERROR_NOT_IMPLEMENTED;
}

/* void uninstallItem (in AString id); */
NS_IMETHODIMP nsExtensionManager::UninstallItem(const nsAString & id)
{
    return NS_ERROR_NOT_IMPLEMENTED;
}

/* void enableItem (in AString id); */
NS_IMETHODIMP nsExtensionManager::EnableItem(const nsAString & id)
{
    return NS_ERROR_NOT_IMPLEMENTED;
}

/* void disableItem (in AString id); */
NS_IMETHODIMP nsExtensionManager::DisableItem(const nsAString & id)
{
    return NS_ERROR_NOT_IMPLEMENTED;
}

/* void update ([array, size_is (itemCount)] in nsIUpdateItem items, in unsigned long itemCount, in unsigned long updateCheckType, in nsIAddonUpdateCheckListener listener, [optional] in AString appVersion, [optional] in AString platformVersion); */
NS_IMETHODIMP nsExtensionManager::Update(nsIUpdateItem **items, PRUint32 itemCount, PRUint32 updateCheckType, nsIAddonUpdateCheckListener *listener, const nsAString & appVersion, const nsAString & platformVersion)
{
    return NS_ERROR_NOT_IMPLEMENTED;
}

/* nsIUpdateItem getItemForID (in AString id); */
NS_IMETHODIMP nsExtensionManager::GetItemForID(const nsAString & id, nsIUpdateItem **_retval NS_OUTPARAM)
{
    return NS_ERROR_NOT_IMPLEMENTED;
}

/* void getItemList (in unsigned long type, out unsigned long itemCount, [array, size_is (itemCount), retval] out nsIUpdateItem items); */
NS_IMETHODIMP nsExtensionManager::GetItemList(PRUint32 type, PRUint32 *itemCount NS_OUTPARAM, nsIUpdateItem ***items NS_OUTPARAM)
{
    return NS_ERROR_NOT_IMPLEMENTED;
}

/* void getIncompatibleItemList (in AString id, in AString appVersion, in AString platformVersion, in unsigned long type, in boolean includeDisabled, out unsigned long itemCount, [array, size_is (itemCount), retval] out nsIUpdateItem items); */
NS_IMETHODIMP nsExtensionManager::GetIncompatibleItemList(const nsAString & id, const nsAString & appVersion, const nsAString & platformVersion, PRUint32 type, PRBool includeDisabled, PRUint32 *itemCount NS_OUTPARAM, nsIUpdateItem ***items NS_OUTPARAM)
{
    return NS_ERROR_NOT_IMPLEMENTED;
}

/* readonly attribute nsIRDFDataSource datasource; */
NS_IMETHODIMP nsExtensionManager::GetDatasource(nsIRDFDataSource * *aDatasource)
{
    return NS_ERROR_NOT_IMPLEMENTED;
}

/* void addDownloads ([array, size_is (itemCount)] in nsIUpdateItem items, in unsigned long itemCount, in nsIObserver manager); */
NS_IMETHODIMP nsExtensionManager::AddDownloads(nsIUpdateItem **items, PRUint32 itemCount, nsIObserver *manager)
{
    return NS_ERROR_NOT_IMPLEMENTED;
}

/* void removeDownload (in AString url); */
NS_IMETHODIMP nsExtensionManager::RemoveDownload(const nsAString & url)
{
    return NS_ERROR_NOT_IMPLEMENTED;
}

/* long addInstallListener (in nsIAddonInstallListener listener); */
NS_IMETHODIMP nsExtensionManager::AddInstallListener(nsIAddonInstallListener *listener, PRInt32 *_retval NS_OUTPARAM)
{
    return NS_ERROR_NOT_IMPLEMENTED;
}

/* void removeInstallListenerAt (in long index); */
NS_IMETHODIMP nsExtensionManager::RemoveInstallListenerAt(PRInt32 index)
{
    return NS_ERROR_NOT_IMPLEMENTED;
}

/* void moveToIndexOf (in AString movingID, in AString destinationID); */
NS_IMETHODIMP nsExtensionManager::MoveToIndexOf(const nsAString & movingID, const nsAString & destinationID)
{
    return NS_ERROR_NOT_IMPLEMENTED;
}

/* void cancelInstallItem (in AString id); */
NS_IMETHODIMP nsExtensionManager::CancelInstallItem(const nsAString & id)
{
    return NS_ERROR_NOT_IMPLEMENTED;
}

/* void cancelUninstallItem (in AString id); */
NS_IMETHODIMP nsExtensionManager::CancelUninstallItem(const nsAString & id)
{
    return NS_ERROR_NOT_IMPLEMENTED;
}

/* void getDependentItemListForID (in AString id, in boolean includeDisabled, out unsigned long itemCount, [array, size_is (itemCount), retval] out nsIUpdateItem items); */
NS_IMETHODIMP nsExtensionManager::GetDependentItemListForID(const nsAString & id, PRBool includeDisabled, PRUint32 *itemCount NS_OUTPARAM, nsIUpdateItem ***items NS_OUTPARAM)
{
    return NS_ERROR_NOT_IMPLEMENTED;
}

/* void updateAndGetNewBlocklistedItems (out unsigned long itemCount, [array, size_is (itemCount), retval] out nsIUpdateItem items); */
NS_IMETHODIMP nsExtensionManager::UpdateAndGetNewBlocklistedItems(PRUint32 *itemCount NS_OUTPARAM, nsIUpdateItem ***items NS_OUTPARAM)
{
    return NS_ERROR_NOT_IMPLEMENTED;
}

/* void sortTypeByProperty (in unsigned long type, in AString propertyName, in boolean isAscending); */
NS_IMETHODIMP nsExtensionManager::SortTypeByProperty(PRUint32 type, const nsAString & propertyName, PRBool isAscending)
{
    return NS_ERROR_NOT_IMPLEMENTED;
}

/* End of implementation class template. */
#endif


/* starting interface:    nsIUpdateItem */
#define NS_IUPDATEITEM_IID_STR "f559f340-5160-420f-abc8-19b251708e7e"

#define NS_IUPDATEITEM_IID \
  {0xf559f340, 0x5160, 0x420f, \
    { 0xab, 0xc8, 0x19, 0xb2, 0x51, 0x70, 0x8e, 0x7e }}

class NS_NO_VTABLE NS_SCRIPTABLE nsIUpdateItem : public nsISupports {
 public: 

  NS_DECLARE_STATIC_IID_ACCESSOR(NS_IUPDATEITEM_IID)

  /**
 * An item managed by the Extension System. Contains metadata that describes
 * the item.
 * XXXben work in progress, the name of this interface will change after the
 *        update system is complete, probably to nsIAddon
 */
/**
   * The GUID of the item.
   */
  /* readonly attribute AString id; */
  NS_SCRIPTABLE NS_IMETHOD GetId(nsAString & aId) = 0;

  /**
   * The Version of the item, in FVF format.
   */
  /* readonly attribute AString version; */
  NS_SCRIPTABLE NS_IMETHOD GetVersion(nsAString & aVersion) = 0;

  /**
   * The minimum version of the application that this item works with,
   * in FVF format.
   */
  /* readonly attribute AString minAppVersion; */
  NS_SCRIPTABLE NS_IMETHOD GetMinAppVersion(nsAString & aMinAppVersion) = 0;

  /**
   * The maximum version of the application that this item works with,
   * in FVF format.
   */
  /* readonly attribute AString maxAppVersion; */
  NS_SCRIPTABLE NS_IMETHOD GetMaxAppVersion(nsAString & aMaxAppVersion) = 0;

  /**
   * The name of the Install Location where this item is installed.
   */
  /* readonly attribute AString installLocationKey; */
  NS_SCRIPTABLE NS_IMETHOD GetInstallLocationKey(nsAString & aInstallLocationKey) = 0;

  /**
   * The name of this item.
   */
  /* readonly attribute AString name; */
  NS_SCRIPTABLE NS_IMETHOD GetName(nsAString & aName) = 0;

  /**
   * The URL of the XPI where this item can be downloaded.
   */
  /* readonly attribute AString xpiURL; */
  NS_SCRIPTABLE NS_IMETHOD GetXpiURL(nsAString & aXpiURL) = 0;

  /**
   * The string Hash for the XPI file. Can be null and if supplied must be in
   * the format of "type:hash" (see the types in nsICryptoHash and
   * nsIXPInstallManager::initManagerWithHashes).
   */
  /* readonly attribute AString xpiHash; */
  NS_SCRIPTABLE NS_IMETHOD GetXpiHash(nsAString & aXpiHash) = 0;

  /**
   * The URL of the icon that can be shown for this item.
   */
  /* readonly attribute AString iconURL; */
  NS_SCRIPTABLE NS_IMETHOD GetIconURL(nsAString & aIconURL) = 0;

  /**
   * The URL of the update RDF file for this item.
   */
  /* readonly attribute AString updateRDF; */
  NS_SCRIPTABLE NS_IMETHOD GetUpdateRDF(nsAString & aUpdateRDF) = 0;

  /**
   * The public key to verify updates for this item. This must be the public
   * part of the key that was used to sign update manifests for this add-on.
   */
  /* readonly attribute AString updateKey; */
  NS_SCRIPTABLE NS_IMETHOD GetUpdateKey(nsAString & aUpdateKey) = 0;

  enum { TYPE_APP = 1U };

  enum { TYPE_EXTENSION = 2U };

  enum { TYPE_THEME = 4U };

  enum { TYPE_LOCALE = 8U };

  enum { TYPE_MULTI_XPI = 32U };

  enum { TYPE_ADDON = 14U };

  enum { TYPE_ANY = 255U };

  /**
   * The type of this item.
   */
  /* readonly attribute long type; */
  NS_SCRIPTABLE NS_IMETHOD GetType(PRInt32 *aType) = 0;

  /**
   * The target application ID used for checking compatibility for this item.
   *
   * @note Add-ons can specify a targetApplication id of toolkit@mozilla.org in
   *       their install manifest for compatibility with all apps using a
   *       specific release of the toolkit.
   */
  /* readonly attribute AString targetAppID; */
  NS_SCRIPTABLE NS_IMETHOD GetTargetAppID(nsAString & aTargetAppID) = 0;

  /**
   * Initializes this Item object.
   */
  /* void init (in AString id, in AString version, in AString installLocationKey, in AString minAppVersion, in AString maxAppVersion, in AString name, in AString downloadURL, in AString xpiHash, in AString iconURL, in AString updateURL, in AString updateKey, in long type, in AString targetAppID); */
  NS_SCRIPTABLE NS_IMETHOD Init(const nsAString & id, const nsAString & version, const nsAString & installLocationKey, const nsAString & minAppVersion, const nsAString & maxAppVersion, const nsAString & name, const nsAString & downloadURL, const nsAString & xpiHash, const nsAString & iconURL, const nsAString & updateURL, const nsAString & updateKey, PRInt32 type, const nsAString & targetAppID) = 0;

  /**
   * Returns a JS Object source representing an nsIUpdateItem.
   */
  /* readonly attribute AString objectSource; */
  NS_SCRIPTABLE NS_IMETHOD GetObjectSource(nsAString & aObjectSource) = 0;

};

  NS_DEFINE_STATIC_IID_ACCESSOR(nsIUpdateItem, NS_IUPDATEITEM_IID)

/* Use this macro when declaring classes that implement this interface. */
#define NS_DECL_NSIUPDATEITEM \
  NS_SCRIPTABLE NS_IMETHOD GetId(nsAString & aId); \
  NS_SCRIPTABLE NS_IMETHOD GetVersion(nsAString & aVersion); \
  NS_SCRIPTABLE NS_IMETHOD GetMinAppVersion(nsAString & aMinAppVersion); \
  NS_SCRIPTABLE NS_IMETHOD GetMaxAppVersion(nsAString & aMaxAppVersion); \
  NS_SCRIPTABLE NS_IMETHOD GetInstallLocationKey(nsAString & aInstallLocationKey); \
  NS_SCRIPTABLE NS_IMETHOD GetName(nsAString & aName); \
  NS_SCRIPTABLE NS_IMETHOD GetXpiURL(nsAString & aXpiURL); \
  NS_SCRIPTABLE NS_IMETHOD GetXpiHash(nsAString & aXpiHash); \
  NS_SCRIPTABLE NS_IMETHOD GetIconURL(nsAString & aIconURL); \
  NS_SCRIPTABLE NS_IMETHOD GetUpdateRDF(nsAString & aUpdateRDF); \
  NS_SCRIPTABLE NS_IMETHOD GetUpdateKey(nsAString & aUpdateKey); \
  NS_SCRIPTABLE NS_IMETHOD GetType(PRInt32 *aType); \
  NS_SCRIPTABLE NS_IMETHOD GetTargetAppID(nsAString & aTargetAppID); \
  NS_SCRIPTABLE NS_IMETHOD Init(const nsAString & id, const nsAString & version, const nsAString & installLocationKey, const nsAString & minAppVersion, const nsAString & maxAppVersion, const nsAString & name, const nsAString & downloadURL, const nsAString & xpiHash, const nsAString & iconURL, const nsAString & updateURL, const nsAString & updateKey, PRInt32 type, const nsAString & targetAppID); \
  NS_SCRIPTABLE NS_IMETHOD GetObjectSource(nsAString & aObjectSource); 

/* Use this macro to declare functions that forward the behavior of this interface to another object. */
#define NS_FORWARD_NSIUPDATEITEM(_to) \
  NS_SCRIPTABLE NS_IMETHOD GetId(nsAString & aId) { return _to GetId(aId); } \
  NS_SCRIPTABLE NS_IMETHOD GetVersion(nsAString & aVersion) { return _to GetVersion(aVersion); } \
  NS_SCRIPTABLE NS_IMETHOD GetMinAppVersion(nsAString & aMinAppVersion) { return _to GetMinAppVersion(aMinAppVersion); } \
  NS_SCRIPTABLE NS_IMETHOD GetMaxAppVersion(nsAString & aMaxAppVersion) { return _to GetMaxAppVersion(aMaxAppVersion); } \
  NS_SCRIPTABLE NS_IMETHOD GetInstallLocationKey(nsAString & aInstallLocationKey) { return _to GetInstallLocationKey(aInstallLocationKey); } \
  NS_SCRIPTABLE NS_IMETHOD GetName(nsAString & aName) { return _to GetName(aName); } \
  NS_SCRIPTABLE NS_IMETHOD GetXpiURL(nsAString & aXpiURL) { return _to GetXpiURL(aXpiURL); } \
  NS_SCRIPTABLE NS_IMETHOD GetXpiHash(nsAString & aXpiHash) { return _to GetXpiHash(aXpiHash); } \
  NS_SCRIPTABLE NS_IMETHOD GetIconURL(nsAString & aIconURL) { return _to GetIconURL(aIconURL); } \
  NS_SCRIPTABLE NS_IMETHOD GetUpdateRDF(nsAString & aUpdateRDF) { return _to GetUpdateRDF(aUpdateRDF); } \
  NS_SCRIPTABLE NS_IMETHOD GetUpdateKey(nsAString & aUpdateKey) { return _to GetUpdateKey(aUpdateKey); } \
  NS_SCRIPTABLE NS_IMETHOD GetType(PRInt32 *aType) { return _to GetType(aType); } \
  NS_SCRIPTABLE NS_IMETHOD GetTargetAppID(nsAString & aTargetAppID) { return _to GetTargetAppID(aTargetAppID); } \
  NS_SCRIPTABLE NS_IMETHOD Init(const nsAString & id, const nsAString & version, const nsAString & installLocationKey, const nsAString & minAppVersion, const nsAString & maxAppVersion, const nsAString & name, const nsAString & downloadURL, const nsAString & xpiHash, const nsAString & iconURL, const nsAString & updateURL, const nsAString & updateKey, PRInt32 type, const nsAString & targetAppID) { return _to Init(id, version, installLocationKey, minAppVersion, maxAppVersion, name, downloadURL, xpiHash, iconURL, updateURL, updateKey, type, targetAppID); } \
  NS_SCRIPTABLE NS_IMETHOD GetObjectSource(nsAString & aObjectSource) { return _to GetObjectSource(aObjectSource); } 

/* Use this macro to declare functions that forward the behavior of this interface to another object in a safe way. */
#define NS_FORWARD_SAFE_NSIUPDATEITEM(_to) \
  NS_SCRIPTABLE NS_IMETHOD GetId(nsAString & aId) { return !_to ? NS_ERROR_NULL_POINTER : _to->GetId(aId); } \
  NS_SCRIPTABLE NS_IMETHOD GetVersion(nsAString & aVersion) { return !_to ? NS_ERROR_NULL_POINTER : _to->GetVersion(aVersion); } \
  NS_SCRIPTABLE NS_IMETHOD GetMinAppVersion(nsAString & aMinAppVersion) { return !_to ? NS_ERROR_NULL_POINTER : _to->GetMinAppVersion(aMinAppVersion); } \
  NS_SCRIPTABLE NS_IMETHOD GetMaxAppVersion(nsAString & aMaxAppVersion) { return !_to ? NS_ERROR_NULL_POINTER : _to->GetMaxAppVersion(aMaxAppVersion); } \
  NS_SCRIPTABLE NS_IMETHOD GetInstallLocationKey(nsAString & aInstallLocationKey) { return !_to ? NS_ERROR_NULL_POINTER : _to->GetInstallLocationKey(aInstallLocationKey); } \
  NS_SCRIPTABLE NS_IMETHOD GetName(nsAString & aName) { return !_to ? NS_ERROR_NULL_POINTER : _to->GetName(aName); } \
  NS_SCRIPTABLE NS_IMETHOD GetXpiURL(nsAString & aXpiURL) { return !_to ? NS_ERROR_NULL_POINTER : _to->GetXpiURL(aXpiURL); } \
  NS_SCRIPTABLE NS_IMETHOD GetXpiHash(nsAString & aXpiHash) { return !_to ? NS_ERROR_NULL_POINTER : _to->GetXpiHash(aXpiHash); } \
  NS_SCRIPTABLE NS_IMETHOD GetIconURL(nsAString & aIconURL) { return !_to ? NS_ERROR_NULL_POINTER : _to->GetIconURL(aIconURL); } \
  NS_SCRIPTABLE NS_IMETHOD GetUpdateRDF(nsAString & aUpdateRDF) { return !_to ? NS_ERROR_NULL_POINTER : _to->GetUpdateRDF(aUpdateRDF); } \
  NS_SCRIPTABLE NS_IMETHOD GetUpdateKey(nsAString & aUpdateKey) { return !_to ? NS_ERROR_NULL_POINTER : _to->GetUpdateKey(aUpdateKey); } \
  NS_SCRIPTABLE NS_IMETHOD GetType(PRInt32 *aType) { return !_to ? NS_ERROR_NULL_POINTER : _to->GetType(aType); } \
  NS_SCRIPTABLE NS_IMETHOD GetTargetAppID(nsAString & aTargetAppID) { return !_to ? NS_ERROR_NULL_POINTER : _to->GetTargetAppID(aTargetAppID); } \
  NS_SCRIPTABLE NS_IMETHOD Init(const nsAString & id, const nsAString & version, const nsAString & installLocationKey, const nsAString & minAppVersion, const nsAString & maxAppVersion, const nsAString & name, const nsAString & downloadURL, const nsAString & xpiHash, const nsAString & iconURL, const nsAString & updateURL, const nsAString & updateKey, PRInt32 type, const nsAString & targetAppID) { return !_to ? NS_ERROR_NULL_POINTER : _to->Init(id, version, installLocationKey, minAppVersion, maxAppVersion, name, downloadURL, xpiHash, iconURL, updateURL, updateKey, type, targetAppID); } \
  NS_SCRIPTABLE NS_IMETHOD GetObjectSource(nsAString & aObjectSource) { return !_to ? NS_ERROR_NULL_POINTER : _to->GetObjectSource(aObjectSource); } 

#if 0
/* Use the code below as a template for the implementation class for this interface. */

/* Header file */
class nsUpdateItem : public nsIUpdateItem
{
public:
  NS_DECL_ISUPPORTS
  NS_DECL_NSIUPDATEITEM

  nsUpdateItem();

private:
  ~nsUpdateItem();

protected:
  /* additional members */
};

/* Implementation file */
NS_IMPL_ISUPPORTS1(nsUpdateItem, nsIUpdateItem)

nsUpdateItem::nsUpdateItem()
{
  /* member initializers and constructor code */
}

nsUpdateItem::~nsUpdateItem()
{
  /* destructor code */
}

/* readonly attribute AString id; */
NS_IMETHODIMP nsUpdateItem::GetId(nsAString & aId)
{
    return NS_ERROR_NOT_IMPLEMENTED;
}

/* readonly attribute AString version; */
NS_IMETHODIMP nsUpdateItem::GetVersion(nsAString & aVersion)
{
    return NS_ERROR_NOT_IMPLEMENTED;
}

/* readonly attribute AString minAppVersion; */
NS_IMETHODIMP nsUpdateItem::GetMinAppVersion(nsAString & aMinAppVersion)
{
    return NS_ERROR_NOT_IMPLEMENTED;
}

/* readonly attribute AString maxAppVersion; */
NS_IMETHODIMP nsUpdateItem::GetMaxAppVersion(nsAString & aMaxAppVersion)
{
    return NS_ERROR_NOT_IMPLEMENTED;
}

/* readonly attribute AString installLocationKey; */
NS_IMETHODIMP nsUpdateItem::GetInstallLocationKey(nsAString & aInstallLocationKey)
{
    return NS_ERROR_NOT_IMPLEMENTED;
}

/* readonly attribute AString name; */
NS_IMETHODIMP nsUpdateItem::GetName(nsAString & aName)
{
    return NS_ERROR_NOT_IMPLEMENTED;
}

/* readonly attribute AString xpiURL; */
NS_IMETHODIMP nsUpdateItem::GetXpiURL(nsAString & aXpiURL)
{
    return NS_ERROR_NOT_IMPLEMENTED;
}

/* readonly attribute AString xpiHash; */
NS_IMETHODIMP nsUpdateItem::GetXpiHash(nsAString & aXpiHash)
{
    return NS_ERROR_NOT_IMPLEMENTED;
}

/* readonly attribute AString iconURL; */
NS_IMETHODIMP nsUpdateItem::GetIconURL(nsAString & aIconURL)
{
    return NS_ERROR_NOT_IMPLEMENTED;
}

/* readonly attribute AString updateRDF; */
NS_IMETHODIMP nsUpdateItem::GetUpdateRDF(nsAString & aUpdateRDF)
{
    return NS_ERROR_NOT_IMPLEMENTED;
}

/* readonly attribute AString updateKey; */
NS_IMETHODIMP nsUpdateItem::GetUpdateKey(nsAString & aUpdateKey)
{
    return NS_ERROR_NOT_IMPLEMENTED;
}

/* readonly attribute long type; */
NS_IMETHODIMP nsUpdateItem::GetType(PRInt32 *aType)
{
    return NS_ERROR_NOT_IMPLEMENTED;
}

/* readonly attribute AString targetAppID; */
NS_IMETHODIMP nsUpdateItem::GetTargetAppID(nsAString & aTargetAppID)
{
    return NS_ERROR_NOT_IMPLEMENTED;
}

/* void init (in AString id, in AString version, in AString installLocationKey, in AString minAppVersion, in AString maxAppVersion, in AString name, in AString downloadURL, in AString xpiHash, in AString iconURL, in AString updateURL, in AString updateKey, in long type, in AString targetAppID); */
NS_IMETHODIMP nsUpdateItem::Init(const nsAString & id, const nsAString & version, const nsAString & installLocationKey, const nsAString & minAppVersion, const nsAString & maxAppVersion, const nsAString & name, const nsAString & downloadURL, const nsAString & xpiHash, const nsAString & iconURL, const nsAString & updateURL, const nsAString & updateKey, PRInt32 type, const nsAString & targetAppID)
{
    return NS_ERROR_NOT_IMPLEMENTED;
}

/* readonly attribute AString objectSource; */
NS_IMETHODIMP nsUpdateItem::GetObjectSource(nsAString & aObjectSource)
{
    return NS_ERROR_NOT_IMPLEMENTED;
}

/* End of implementation class template. */
#endif


/* starting interface:    nsIAddonInstallListener */
#define NS_IADDONINSTALLLISTENER_IID_STR "2333b04c-f371-4dea-a2f1-d8fdb0c82866"

#define NS_IADDONINSTALLLISTENER_IID \
  {0x2333b04c, 0xf371, 0x4dea, \
    { 0xa2, 0xf1, 0xd8, 0xfd, 0xb0, 0xc8, 0x28, 0x66 }}

class NS_NO_VTABLE NS_SCRIPTABLE nsIAddonInstallListener : public nsISupports {
 public: 

  NS_DECLARE_STATIC_IID_ACCESSOR(NS_IADDONINSTALLLISTENER_IID)

  /**
 * Interface for handling download and install progress notifications for
 * add-ons.
 */
/**
   * Called when an add-on download starts. This will be called for every add-on
   * downloaded including those started by an add-on update.
   * @param   addon
   *          The add-on that is being downloaded
   */
  /* void onDownloadStarted (in nsIUpdateItem addon); */
  NS_SCRIPTABLE NS_IMETHOD OnDownloadStarted(nsIUpdateItem *addon) = 0;

  /**
   * Progress occurred in the download operation. This will be called multiple
   * times during the download of an add-on.
   * @param   addon
   *          The add-on that progress occurred for
   * @param   value
   *          The value of the current progress
   * @param   maxValue
   *          The maximum value |value| can reach
   */
  /* void onDownloadProgress (in nsIUpdateItem addon, in unsigned long value, in unsigned long maxValue); */
  NS_SCRIPTABLE NS_IMETHOD OnDownloadProgress(nsIUpdateItem *addon, PRUint32 value, PRUint32 maxValue) = 0;

  /**
   * Called when an add-on download is complete. This will be called for every
   * add-on downloaded.
   * @param   addon
   *          The add-on that finished downloading
   */
  /* void onDownloadEnded (in nsIUpdateItem addon); */
  NS_SCRIPTABLE NS_IMETHOD OnDownloadEnded(nsIUpdateItem *addon) = 0;

  /**
   * Called when the extension manager starts to install an add-on either
   * through a call to installItemFromFile or from a webpage triggered install.
   * @param   addon
   *          The add-on being installed
   */
  /* void onInstallStarted (in nsIUpdateItem addon); */
  NS_SCRIPTABLE NS_IMETHOD OnInstallStarted(nsIUpdateItem *addon) = 0;

  /**
   * Called when an add-on compatibility check starts. This will be called 
   * during an install if an add-on is incompatible according to its
   * install.rdf.
   * @param   addon
   *          The add-on that the compatibility check will be for
   */
  /* void onCompatibilityCheckStarted (in nsIUpdateItem addon); */
  NS_SCRIPTABLE NS_IMETHOD OnCompatibilityCheckStarted(nsIUpdateItem *addon) = 0;

  /**
   * Called at the end of an add-on compatibility check. The status will be one
   * of the results from nsIAddonUpdateCheckListener to indicate whether new
   * information was found or not.
   * @param   addon
   *          The add-on that is having its compatibility checked
   * @param   status
   *          The status code from nsIAddonUpdateCheckListener for the update
   *          operation
   */
  /* void onCompatibilityCheckEnded (in nsIUpdateItem addon, in long status); */
  NS_SCRIPTABLE NS_IMETHOD OnCompatibilityCheckEnded(nsIUpdateItem *addon, PRInt32 status) = 0;

  /**
   * Called when an add-on install completes. The status will be 0 on success.
   * any other value constitutes a failed install.
   * @param   addon
   *          The add-on that finished installing
   * @param   status
   *          The status of the installation from nsInstall.h
   */
  /* void onInstallEnded (in nsIUpdateItem addon, in long status); */
  NS_SCRIPTABLE NS_IMETHOD OnInstallEnded(nsIUpdateItem *addon, PRInt32 status) = 0;

  /**
   * Called when there are no more add-on downloads or installs in progress.
   */
  /* void onInstallsCompleted (); */
  NS_SCRIPTABLE NS_IMETHOD OnInstallsCompleted(void) = 0;

};

  NS_DEFINE_STATIC_IID_ACCESSOR(nsIAddonInstallListener, NS_IADDONINSTALLLISTENER_IID)

/* Use this macro when declaring classes that implement this interface. */
#define NS_DECL_NSIADDONINSTALLLISTENER \
  NS_SCRIPTABLE NS_IMETHOD OnDownloadStarted(nsIUpdateItem *addon); \
  NS_SCRIPTABLE NS_IMETHOD OnDownloadProgress(nsIUpdateItem *addon, PRUint32 value, PRUint32 maxValue); \
  NS_SCRIPTABLE NS_IMETHOD OnDownloadEnded(nsIUpdateItem *addon); \
  NS_SCRIPTABLE NS_IMETHOD OnInstallStarted(nsIUpdateItem *addon); \
  NS_SCRIPTABLE NS_IMETHOD OnCompatibilityCheckStarted(nsIUpdateItem *addon); \
  NS_SCRIPTABLE NS_IMETHOD OnCompatibilityCheckEnded(nsIUpdateItem *addon, PRInt32 status); \
  NS_SCRIPTABLE NS_IMETHOD OnInstallEnded(nsIUpdateItem *addon, PRInt32 status); \
  NS_SCRIPTABLE NS_IMETHOD OnInstallsCompleted(void); 

/* Use this macro to declare functions that forward the behavior of this interface to another object. */
#define NS_FORWARD_NSIADDONINSTALLLISTENER(_to) \
  NS_SCRIPTABLE NS_IMETHOD OnDownloadStarted(nsIUpdateItem *addon) { return _to OnDownloadStarted(addon); } \
  NS_SCRIPTABLE NS_IMETHOD OnDownloadProgress(nsIUpdateItem *addon, PRUint32 value, PRUint32 maxValue) { return _to OnDownloadProgress(addon, value, maxValue); } \
  NS_SCRIPTABLE NS_IMETHOD OnDownloadEnded(nsIUpdateItem *addon) { return _to OnDownloadEnded(addon); } \
  NS_SCRIPTABLE NS_IMETHOD OnInstallStarted(nsIUpdateItem *addon) { return _to OnInstallStarted(addon); } \
  NS_SCRIPTABLE NS_IMETHOD OnCompatibilityCheckStarted(nsIUpdateItem *addon) { return _to OnCompatibilityCheckStarted(addon); } \
  NS_SCRIPTABLE NS_IMETHOD OnCompatibilityCheckEnded(nsIUpdateItem *addon, PRInt32 status) { return _to OnCompatibilityCheckEnded(addon, status); } \
  NS_SCRIPTABLE NS_IMETHOD OnInstallEnded(nsIUpdateItem *addon, PRInt32 status) { return _to OnInstallEnded(addon, status); } \
  NS_SCRIPTABLE NS_IMETHOD OnInstallsCompleted(void) { return _to OnInstallsCompleted(); } 

/* Use this macro to declare functions that forward the behavior of this interface to another object in a safe way. */
#define NS_FORWARD_SAFE_NSIADDONINSTALLLISTENER(_to) \
  NS_SCRIPTABLE NS_IMETHOD OnDownloadStarted(nsIUpdateItem *addon) { return !_to ? NS_ERROR_NULL_POINTER : _to->OnDownloadStarted(addon); } \
  NS_SCRIPTABLE NS_IMETHOD OnDownloadProgress(nsIUpdateItem *addon, PRUint32 value, PRUint32 maxValue) { return !_to ? NS_ERROR_NULL_POINTER : _to->OnDownloadProgress(addon, value, maxValue); } \
  NS_SCRIPTABLE NS_IMETHOD OnDownloadEnded(nsIUpdateItem *addon) { return !_to ? NS_ERROR_NULL_POINTER : _to->OnDownloadEnded(addon); } \
  NS_SCRIPTABLE NS_IMETHOD OnInstallStarted(nsIUpdateItem *addon) { return !_to ? NS_ERROR_NULL_POINTER : _to->OnInstallStarted(addon); } \
  NS_SCRIPTABLE NS_IMETHOD OnCompatibilityCheckStarted(nsIUpdateItem *addon) { return !_to ? NS_ERROR_NULL_POINTER : _to->OnCompatibilityCheckStarted(addon); } \
  NS_SCRIPTABLE NS_IMETHOD OnCompatibilityCheckEnded(nsIUpdateItem *addon, PRInt32 status) { return !_to ? NS_ERROR_NULL_POINTER : _to->OnCompatibilityCheckEnded(addon, status); } \
  NS_SCRIPTABLE NS_IMETHOD OnInstallEnded(nsIUpdateItem *addon, PRInt32 status) { return !_to ? NS_ERROR_NULL_POINTER : _to->OnInstallEnded(addon, status); } \
  NS_SCRIPTABLE NS_IMETHOD OnInstallsCompleted(void) { return !_to ? NS_ERROR_NULL_POINTER : _to->OnInstallsCompleted(); } 

#if 0
/* Use the code below as a template for the implementation class for this interface. */

/* Header file */
class nsAddonInstallListener : public nsIAddonInstallListener
{
public:
  NS_DECL_ISUPPORTS
  NS_DECL_NSIADDONINSTALLLISTENER

  nsAddonInstallListener();

private:
  ~nsAddonInstallListener();

protected:
  /* additional members */
};

/* Implementation file */
NS_IMPL_ISUPPORTS1(nsAddonInstallListener, nsIAddonInstallListener)

nsAddonInstallListener::nsAddonInstallListener()
{
  /* member initializers and constructor code */
}

nsAddonInstallListener::~nsAddonInstallListener()
{
  /* destructor code */
}

/* void onDownloadStarted (in nsIUpdateItem addon); */
NS_IMETHODIMP nsAddonInstallListener::OnDownloadStarted(nsIUpdateItem *addon)
{
    return NS_ERROR_NOT_IMPLEMENTED;
}

/* void onDownloadProgress (in nsIUpdateItem addon, in unsigned long value, in unsigned long maxValue); */
NS_IMETHODIMP nsAddonInstallListener::OnDownloadProgress(nsIUpdateItem *addon, PRUint32 value, PRUint32 maxValue)
{
    return NS_ERROR_NOT_IMPLEMENTED;
}

/* void onDownloadEnded (in nsIUpdateItem addon); */
NS_IMETHODIMP nsAddonInstallListener::OnDownloadEnded(nsIUpdateItem *addon)
{
    return NS_ERROR_NOT_IMPLEMENTED;
}

/* void onInstallStarted (in nsIUpdateItem addon); */
NS_IMETHODIMP nsAddonInstallListener::OnInstallStarted(nsIUpdateItem *addon)
{
    return NS_ERROR_NOT_IMPLEMENTED;
}

/* void onCompatibilityCheckStarted (in nsIUpdateItem addon); */
NS_IMETHODIMP nsAddonInstallListener::OnCompatibilityCheckStarted(nsIUpdateItem *addon)
{
    return NS_ERROR_NOT_IMPLEMENTED;
}

/* void onCompatibilityCheckEnded (in nsIUpdateItem addon, in long status); */
NS_IMETHODIMP nsAddonInstallListener::OnCompatibilityCheckEnded(nsIUpdateItem *addon, PRInt32 status)
{
    return NS_ERROR_NOT_IMPLEMENTED;
}

/* void onInstallEnded (in nsIUpdateItem addon, in long status); */
NS_IMETHODIMP nsAddonInstallListener::OnInstallEnded(nsIUpdateItem *addon, PRInt32 status)
{
    return NS_ERROR_NOT_IMPLEMENTED;
}

/* void onInstallsCompleted (); */
NS_IMETHODIMP nsAddonInstallListener::OnInstallsCompleted()
{
    return NS_ERROR_NOT_IMPLEMENTED;
}

/* End of implementation class template. */
#endif


/* starting interface:    nsIAddonUpdateCheckListener */
#define NS_IADDONUPDATECHECKLISTENER_IID_STR "c946119f-9e7c-41aa-a794-803148045350"

#define NS_IADDONUPDATECHECKLISTENER_IID \
  {0xc946119f, 0x9e7c, 0x41aa, \
    { 0xa7, 0x94, 0x80, 0x31, 0x48, 0x04, 0x53, 0x50 }}

class NS_NO_VTABLE NS_SCRIPTABLE nsIAddonUpdateCheckListener : public nsISupports {
 public: 

  NS_DECLARE_STATIC_IID_ACCESSOR(NS_IADDONUPDATECHECKLISTENER_IID)

  /**
 * Interface for handling notifications during the addon update check process.
 */
/**
   * Addon update has begun
   */
  /* void onUpdateStarted (); */
  NS_SCRIPTABLE NS_IMETHOD OnUpdateStarted(void) = 0;

  enum { STATUS_NONE = 0U };

  enum { STATUS_UPDATE = 1U };

  enum { STATUS_VERSIONINFO = 2U };

  enum { STATUS_DATA_FOUND = 3U };

  enum { STATUS_FAILURE = 4U };

  enum { STATUS_NO_UPDATE = 8U };

  enum { STATUS_DISABLED = 16U };

  enum { STATUS_APP_MANAGED = 32U };

  enum { STATUS_READ_ONLY = 64U };

  enum { STATUS_PENDING_OP = 128U };

  enum { STATUS_NOT_MANAGED = 256U };

  enum { STATUS_DISALLOWED = 496U };

  /**
   * Addon update has ended
   */
  /* void onUpdateEnded (); */
  NS_SCRIPTABLE NS_IMETHOD OnUpdateEnded(void) = 0;

  /**
   * Update for an individual addon has begun
   * @param   addon
   *          A nsIUpdateItem object representing the addon being updated
   *
   * @throws  NS_ERROR_ILLEGAL_VALUE if the addon is invalid.
   */
  /* void onAddonUpdateStarted (in nsIUpdateItem addon); */
  NS_SCRIPTABLE NS_IMETHOD OnAddonUpdateStarted(nsIUpdateItem *addon) = 0;

  /**
   * Update for an individual addon has ended
   * @param   addon
   *          A nsIUpdateItem object representing the addon being updated
   * @param   status
   *          The success or failure code of the update operation
   *
   * @throws  NS_ERROR_ILLEGAL_VALUE if the addon is invalid.
   */
  /* void onAddonUpdateEnded (in nsIUpdateItem addon, in long status); */
  NS_SCRIPTABLE NS_IMETHOD OnAddonUpdateEnded(nsIUpdateItem *addon, PRInt32 status) = 0;

};

  NS_DEFINE_STATIC_IID_ACCESSOR(nsIAddonUpdateCheckListener, NS_IADDONUPDATECHECKLISTENER_IID)

/* Use this macro when declaring classes that implement this interface. */
#define NS_DECL_NSIADDONUPDATECHECKLISTENER \
  NS_SCRIPTABLE NS_IMETHOD OnUpdateStarted(void); \
  NS_SCRIPTABLE NS_IMETHOD OnUpdateEnded(void); \
  NS_SCRIPTABLE NS_IMETHOD OnAddonUpdateStarted(nsIUpdateItem *addon); \
  NS_SCRIPTABLE NS_IMETHOD OnAddonUpdateEnded(nsIUpdateItem *addon, PRInt32 status); 

/* Use this macro to declare functions that forward the behavior of this interface to another object. */
#define NS_FORWARD_NSIADDONUPDATECHECKLISTENER(_to) \
  NS_SCRIPTABLE NS_IMETHOD OnUpdateStarted(void) { return _to OnUpdateStarted(); } \
  NS_SCRIPTABLE NS_IMETHOD OnUpdateEnded(void) { return _to OnUpdateEnded(); } \
  NS_SCRIPTABLE NS_IMETHOD OnAddonUpdateStarted(nsIUpdateItem *addon) { return _to OnAddonUpdateStarted(addon); } \
  NS_SCRIPTABLE NS_IMETHOD OnAddonUpdateEnded(nsIUpdateItem *addon, PRInt32 status) { return _to OnAddonUpdateEnded(addon, status); } 

/* Use this macro to declare functions that forward the behavior of this interface to another object in a safe way. */
#define NS_FORWARD_SAFE_NSIADDONUPDATECHECKLISTENER(_to) \
  NS_SCRIPTABLE NS_IMETHOD OnUpdateStarted(void) { return !_to ? NS_ERROR_NULL_POINTER : _to->OnUpdateStarted(); } \
  NS_SCRIPTABLE NS_IMETHOD OnUpdateEnded(void) { return !_to ? NS_ERROR_NULL_POINTER : _to->OnUpdateEnded(); } \
  NS_SCRIPTABLE NS_IMETHOD OnAddonUpdateStarted(nsIUpdateItem *addon) { return !_to ? NS_ERROR_NULL_POINTER : _to->OnAddonUpdateStarted(addon); } \
  NS_SCRIPTABLE NS_IMETHOD OnAddonUpdateEnded(nsIUpdateItem *addon, PRInt32 status) { return !_to ? NS_ERROR_NULL_POINTER : _to->OnAddonUpdateEnded(addon, status); } 

#if 0
/* Use the code below as a template for the implementation class for this interface. */

/* Header file */
class nsAddonUpdateCheckListener : public nsIAddonUpdateCheckListener
{
public:
  NS_DECL_ISUPPORTS
  NS_DECL_NSIADDONUPDATECHECKLISTENER

  nsAddonUpdateCheckListener();

private:
  ~nsAddonUpdateCheckListener();

protected:
  /* additional members */
};

/* Implementation file */
NS_IMPL_ISUPPORTS1(nsAddonUpdateCheckListener, nsIAddonUpdateCheckListener)

nsAddonUpdateCheckListener::nsAddonUpdateCheckListener()
{
  /* member initializers and constructor code */
}

nsAddonUpdateCheckListener::~nsAddonUpdateCheckListener()
{
  /* destructor code */
}

/* void onUpdateStarted (); */
NS_IMETHODIMP nsAddonUpdateCheckListener::OnUpdateStarted()
{
    return NS_ERROR_NOT_IMPLEMENTED;
}

/* void onUpdateEnded (); */
NS_IMETHODIMP nsAddonUpdateCheckListener::OnUpdateEnded()
{
    return NS_ERROR_NOT_IMPLEMENTED;
}

/* void onAddonUpdateStarted (in nsIUpdateItem addon); */
NS_IMETHODIMP nsAddonUpdateCheckListener::OnAddonUpdateStarted(nsIUpdateItem *addon)
{
    return NS_ERROR_NOT_IMPLEMENTED;
}

/* void onAddonUpdateEnded (in nsIUpdateItem addon, in long status); */
NS_IMETHODIMP nsAddonUpdateCheckListener::OnAddonUpdateEnded(nsIUpdateItem *addon, PRInt32 status)
{
    return NS_ERROR_NOT_IMPLEMENTED;
}

/* End of implementation class template. */
#endif

/**
 * Install Location Key for Application-Global Items
 */
#define NS_INSTALL_LOCATION_APPGLOBAL NS_LITERAL_STRING("app-global")
/**
 * Install Location Key for Application-Profile Items
 */
#define NS_INSTALL_LOCATION_APPPROFILE NS_LITERAL_STRING("app-profile")
/**
 * The category that contains a list of contract-ids to Install Location
 * services.
 */
#define CATEGORY_INSTALL_LOCATIONS "extension-install-locations"
/**
 * The observer topic to listen to for actions performed on installed
 * items.
 */
#define EM_ACTION_REQUESTED_TOPIC "em-action-requested"
#define EM_ITEM_INSTALLED   "item-installed"
#define EM_ITEM_UPGRADED    "item-upgraded"
#define EM_ITEM_UNINSTALLED "item-uninstalled"
#define EM_ITEM_ENABLED     "item-enabled"
#define EM_ITEM_DISABLED    "item-disabled"
#define EM_ITEM_CANCEL      "item-cancel-action"

#endif /* __gen_nsIExtensionManager_h__ */
