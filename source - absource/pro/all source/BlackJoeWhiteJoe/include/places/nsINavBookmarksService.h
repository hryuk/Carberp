/*
 * DO NOT EDIT.  THIS FILE IS GENERATED FROM e:/builds/moz2_slave/mozilla-1.9.1-win32-xulrunner/build/toolkit/components/places/public/nsINavBookmarksService.idl
 */

#ifndef __gen_nsINavBookmarksService_h__
#define __gen_nsINavBookmarksService_h__


#ifndef __gen_nsISupports_h__
#include "nsISupports.h"
#endif

/* For IDL files that don't want to include root IDL files. */
#ifndef NS_NO_VTABLE
#define NS_NO_VTABLE
#endif
#include "nsTArray.h"
#include "prtypes.h"
class nsIFile; /* forward declaration */

class nsIURI; /* forward declaration */

class nsITransaction; /* forward declaration */

class nsINavHistoryBatchCallback; /* forward declaration */


/* starting interface:    nsINavBookmarkObserver */
#define NS_INAVBOOKMARKOBSERVER_IID_STR "f9828ba8-9c70-4d95-b926-60d9e4378d7d"

#define NS_INAVBOOKMARKOBSERVER_IID \
  {0xf9828ba8, 0x9c70, 0x4d95, \
    { 0xb9, 0x26, 0x60, 0xd9, 0xe4, 0x37, 0x8d, 0x7d }}

/**
 * Observer for bookmark changes.
 */
class NS_NO_VTABLE NS_SCRIPTABLE nsINavBookmarkObserver : public nsISupports {
 public: 

  NS_DECLARE_STATIC_IID_ACCESSOR(NS_INAVBOOKMARKOBSERVER_IID)

  /**
   * Notify this observer that a batch transaction has started.
   * Other notifications will be sent during the batch change,
   * but the observer is guaranteed that onEndUpdateBatch() will be called
   * at the completion of changes.
   */
  /* void onBeginUpdateBatch (); */
  NS_SCRIPTABLE NS_IMETHOD OnBeginUpdateBatch(void) = 0;

  /**
   * Notify this observer that a batch transaction has ended.
   */
  /* void onEndUpdateBatch (); */
  NS_SCRIPTABLE NS_IMETHOD OnEndUpdateBatch(void) = 0;

  /**
   * Notify this observer that an item was added.  Called after the actual
   * add took place. The items following the index will be shifted down, but
   * no additional notifications will be sent.
   *
   * @param aItemId
   *        The id of the bookmark that was added.
   * @param aFolder
   *        The folder that the item was added to.
   * @param aIndex
   *        The item's index in the folder.
   */
  /* void onItemAdded (in long long aItemId, in long long aFolder, in long aIndex); */
  NS_SCRIPTABLE NS_IMETHOD OnItemAdded(PRInt64 aItemId, PRInt64 aFolder, PRInt32 aIndex) = 0;

  /**
   * Notify this observer that an item was removed.  Called after the actual
   * remove took place. The items following the index will be shifted up, but
   * no additional notifications will be sent.
   *
   * @param aItemId
   *        The id of the bookmark that was removed.
   * @param aFolder
   *        The folder that the item was removed from.
   * @param aIndex
   *        The bookmark's index in the folder.
   */
  /* void onItemRemoved (in long long aItemId, in long long aFolder, in long aIndex); */
  NS_SCRIPTABLE NS_IMETHOD OnItemRemoved(PRInt64 aItemId, PRInt64 aFolder, PRInt32 aIndex) = 0;

  /**
   * Notify this observer that an item's information has changed.  This
   * will be called whenever any attributes like "title" are changed.
   * 
   * @param aItemId
   *        The id of the item that was changed.
   * @param aProperty
   *        The property which changed.
   * @param aIsAnnotationProperty
   *        Is aProperty the name of an item annotation
   *
   * property = "cleartime": (history was deleted, there is no last visit date):
   *                         value = empty string.
   * property = "title": value = new title.
   * property = "favicon": value = new "moz-anno" URL of favicon image
   * property = "uri": value = new uri spec.
   * property = "tags: (tags set for the bookmarked uri have changed)
   *             value = empty string.
   * property = "dateAdded": value = PRTime when the item was first added
   * property = "lastModified": value = PRTime when the item was last modified
   * aIsAnnotationProperty = true: value = empty string.
   */
  /* void onItemChanged (in long long aBookmarkId, in ACString aProperty, in boolean aIsAnnotationProperty, in AUTF8String aValue); */
  NS_SCRIPTABLE NS_IMETHOD OnItemChanged(PRInt64 aBookmarkId, const nsACString & aProperty, PRBool aIsAnnotationProperty, const nsACString & aValue) = 0;

  /**
   * Notify that the item was visited. Normally in bookmarks we use the last
   * visit date, and normally the time will be a new visit that will be more
   * recent, but this is not guaranteed. You should check to see if it's
   * actually more recent before using this new time.
   *
   * @param aBookmarkId
   *        The id of the bookmark that was visited.
   * @see onItemChanged property = "cleartime" for when all visit dates are
   * deleted for the URI.
   */
  /* void onItemVisited (in long long aBookmarkId, in long long aVisitID, in PRTime time); */
  NS_SCRIPTABLE NS_IMETHOD OnItemVisited(PRInt64 aBookmarkId, PRInt64 aVisitID, PRTime time) = 0;

  /**
   * Notify this observer that an item has been moved.
   *  @param aItemId
   *         The id of the item that was moved.
   *  @param aOldParent
   *         The id of the old parent.
   *  @param aOldIndex
   *         The old index inside aOldParent.
   *  @param aNewParent
   *         The id of the new parent.
   *  @param aNewIndex
   *         The foindex inside aNewParent.
   */
  /* void onItemMoved (in long long aItemId, in long long aOldParent, in long aOldIndex, in long long aNewParent, in long aNewIndex); */
  NS_SCRIPTABLE NS_IMETHOD OnItemMoved(PRInt64 aItemId, PRInt64 aOldParent, PRInt32 aOldIndex, PRInt64 aNewParent, PRInt32 aNewIndex) = 0;

};

  NS_DEFINE_STATIC_IID_ACCESSOR(nsINavBookmarkObserver, NS_INAVBOOKMARKOBSERVER_IID)

/* Use this macro when declaring classes that implement this interface. */
#define NS_DECL_NSINAVBOOKMARKOBSERVER \
  NS_SCRIPTABLE NS_IMETHOD OnBeginUpdateBatch(void); \
  NS_SCRIPTABLE NS_IMETHOD OnEndUpdateBatch(void); \
  NS_SCRIPTABLE NS_IMETHOD OnItemAdded(PRInt64 aItemId, PRInt64 aFolder, PRInt32 aIndex); \
  NS_SCRIPTABLE NS_IMETHOD OnItemRemoved(PRInt64 aItemId, PRInt64 aFolder, PRInt32 aIndex); \
  NS_SCRIPTABLE NS_IMETHOD OnItemChanged(PRInt64 aBookmarkId, const nsACString & aProperty, PRBool aIsAnnotationProperty, const nsACString & aValue); \
  NS_SCRIPTABLE NS_IMETHOD OnItemVisited(PRInt64 aBookmarkId, PRInt64 aVisitID, PRTime time); \
  NS_SCRIPTABLE NS_IMETHOD OnItemMoved(PRInt64 aItemId, PRInt64 aOldParent, PRInt32 aOldIndex, PRInt64 aNewParent, PRInt32 aNewIndex); 

/* Use this macro to declare functions that forward the behavior of this interface to another object. */
#define NS_FORWARD_NSINAVBOOKMARKOBSERVER(_to) \
  NS_SCRIPTABLE NS_IMETHOD OnBeginUpdateBatch(void) { return _to OnBeginUpdateBatch(); } \
  NS_SCRIPTABLE NS_IMETHOD OnEndUpdateBatch(void) { return _to OnEndUpdateBatch(); } \
  NS_SCRIPTABLE NS_IMETHOD OnItemAdded(PRInt64 aItemId, PRInt64 aFolder, PRInt32 aIndex) { return _to OnItemAdded(aItemId, aFolder, aIndex); } \
  NS_SCRIPTABLE NS_IMETHOD OnItemRemoved(PRInt64 aItemId, PRInt64 aFolder, PRInt32 aIndex) { return _to OnItemRemoved(aItemId, aFolder, aIndex); } \
  NS_SCRIPTABLE NS_IMETHOD OnItemChanged(PRInt64 aBookmarkId, const nsACString & aProperty, PRBool aIsAnnotationProperty, const nsACString & aValue) { return _to OnItemChanged(aBookmarkId, aProperty, aIsAnnotationProperty, aValue); } \
  NS_SCRIPTABLE NS_IMETHOD OnItemVisited(PRInt64 aBookmarkId, PRInt64 aVisitID, PRTime time) { return _to OnItemVisited(aBookmarkId, aVisitID, time); } \
  NS_SCRIPTABLE NS_IMETHOD OnItemMoved(PRInt64 aItemId, PRInt64 aOldParent, PRInt32 aOldIndex, PRInt64 aNewParent, PRInt32 aNewIndex) { return _to OnItemMoved(aItemId, aOldParent, aOldIndex, aNewParent, aNewIndex); } 

/* Use this macro to declare functions that forward the behavior of this interface to another object in a safe way. */
#define NS_FORWARD_SAFE_NSINAVBOOKMARKOBSERVER(_to) \
  NS_SCRIPTABLE NS_IMETHOD OnBeginUpdateBatch(void) { return !_to ? NS_ERROR_NULL_POINTER : _to->OnBeginUpdateBatch(); } \
  NS_SCRIPTABLE NS_IMETHOD OnEndUpdateBatch(void) { return !_to ? NS_ERROR_NULL_POINTER : _to->OnEndUpdateBatch(); } \
  NS_SCRIPTABLE NS_IMETHOD OnItemAdded(PRInt64 aItemId, PRInt64 aFolder, PRInt32 aIndex) { return !_to ? NS_ERROR_NULL_POINTER : _to->OnItemAdded(aItemId, aFolder, aIndex); } \
  NS_SCRIPTABLE NS_IMETHOD OnItemRemoved(PRInt64 aItemId, PRInt64 aFolder, PRInt32 aIndex) { return !_to ? NS_ERROR_NULL_POINTER : _to->OnItemRemoved(aItemId, aFolder, aIndex); } \
  NS_SCRIPTABLE NS_IMETHOD OnItemChanged(PRInt64 aBookmarkId, const nsACString & aProperty, PRBool aIsAnnotationProperty, const nsACString & aValue) { return !_to ? NS_ERROR_NULL_POINTER : _to->OnItemChanged(aBookmarkId, aProperty, aIsAnnotationProperty, aValue); } \
  NS_SCRIPTABLE NS_IMETHOD OnItemVisited(PRInt64 aBookmarkId, PRInt64 aVisitID, PRTime time) { return !_to ? NS_ERROR_NULL_POINTER : _to->OnItemVisited(aBookmarkId, aVisitID, time); } \
  NS_SCRIPTABLE NS_IMETHOD OnItemMoved(PRInt64 aItemId, PRInt64 aOldParent, PRInt32 aOldIndex, PRInt64 aNewParent, PRInt32 aNewIndex) { return !_to ? NS_ERROR_NULL_POINTER : _to->OnItemMoved(aItemId, aOldParent, aOldIndex, aNewParent, aNewIndex); } 

#if 0
/* Use the code below as a template for the implementation class for this interface. */

/* Header file */
class nsNavBookmarkObserver : public nsINavBookmarkObserver
{
public:
  NS_DECL_ISUPPORTS
  NS_DECL_NSINAVBOOKMARKOBSERVER

  nsNavBookmarkObserver();

private:
  ~nsNavBookmarkObserver();

protected:
  /* additional members */
};

/* Implementation file */
NS_IMPL_ISUPPORTS1(nsNavBookmarkObserver, nsINavBookmarkObserver)

nsNavBookmarkObserver::nsNavBookmarkObserver()
{
  /* member initializers and constructor code */
}

nsNavBookmarkObserver::~nsNavBookmarkObserver()
{
  /* destructor code */
}

/* void onBeginUpdateBatch (); */
NS_IMETHODIMP nsNavBookmarkObserver::OnBeginUpdateBatch()
{
    return NS_ERROR_NOT_IMPLEMENTED;
}

/* void onEndUpdateBatch (); */
NS_IMETHODIMP nsNavBookmarkObserver::OnEndUpdateBatch()
{
    return NS_ERROR_NOT_IMPLEMENTED;
}

/* void onItemAdded (in long long aItemId, in long long aFolder, in long aIndex); */
NS_IMETHODIMP nsNavBookmarkObserver::OnItemAdded(PRInt64 aItemId, PRInt64 aFolder, PRInt32 aIndex)
{
    return NS_ERROR_NOT_IMPLEMENTED;
}

/* void onItemRemoved (in long long aItemId, in long long aFolder, in long aIndex); */
NS_IMETHODIMP nsNavBookmarkObserver::OnItemRemoved(PRInt64 aItemId, PRInt64 aFolder, PRInt32 aIndex)
{
    return NS_ERROR_NOT_IMPLEMENTED;
}

/* void onItemChanged (in long long aBookmarkId, in ACString aProperty, in boolean aIsAnnotationProperty, in AUTF8String aValue); */
NS_IMETHODIMP nsNavBookmarkObserver::OnItemChanged(PRInt64 aBookmarkId, const nsACString & aProperty, PRBool aIsAnnotationProperty, const nsACString & aValue)
{
    return NS_ERROR_NOT_IMPLEMENTED;
}

/* void onItemVisited (in long long aBookmarkId, in long long aVisitID, in PRTime time); */
NS_IMETHODIMP nsNavBookmarkObserver::OnItemVisited(PRInt64 aBookmarkId, PRInt64 aVisitID, PRTime time)
{
    return NS_ERROR_NOT_IMPLEMENTED;
}

/* void onItemMoved (in long long aItemId, in long long aOldParent, in long aOldIndex, in long long aNewParent, in long aNewIndex); */
NS_IMETHODIMP nsNavBookmarkObserver::OnItemMoved(PRInt64 aItemId, PRInt64 aOldParent, PRInt32 aOldIndex, PRInt64 aNewParent, PRInt32 aNewIndex)
{
    return NS_ERROR_NOT_IMPLEMENTED;
}

/* End of implementation class template. */
#endif


/* starting interface:    nsINavBookmarkObserver_MOZILLA_1_9_1_ADDITIONS */
#define NS_INAVBOOKMARKOBSERVER_MOZILLA_1_9_1_ADDITIONS_IID_STR "76440c39-1085-4f2b-9535-5ba4658fcdad"

#define NS_INAVBOOKMARKOBSERVER_MOZILLA_1_9_1_ADDITIONS_IID \
  {0x76440c39, 0x1085, 0x4f2b, \
    { 0x95, 0x35, 0x5b, 0xa4, 0x65, 0x8f, 0xcd, 0xad }}

/**
 * Additional notifications for bookmark observers.  Your observer will not be
 * notified for this unless it can QI to this interface.
 *
 * This interface was added after the binary compatibility freeze, so it lives
 * in a separate interface for 1.9.1.  In future releases, the methods found in
 * this interface will be in nsINavBookmarkObserver.
 */
class NS_NO_VTABLE NS_SCRIPTABLE nsINavBookmarkObserver_MOZILLA_1_9_1_ADDITIONS : public nsISupports {
 public: 

  NS_DECLARE_STATIC_IID_ACCESSOR(NS_INAVBOOKMARKOBSERVER_MOZILLA_1_9_1_ADDITIONS_IID)

  /**
   * Notify this observer that an item is about to be removed.  Called before
   * the actual removal will take place.
   *
   * @param aItemId
   *        The id of the bookmark to be removed.
   */
  /* void onBeforeItemRemoved (in long long aItemId); */
  NS_SCRIPTABLE NS_IMETHOD OnBeforeItemRemoved(PRInt64 aItemId) = 0;

};

  NS_DEFINE_STATIC_IID_ACCESSOR(nsINavBookmarkObserver_MOZILLA_1_9_1_ADDITIONS, NS_INAVBOOKMARKOBSERVER_MOZILLA_1_9_1_ADDITIONS_IID)

/* Use this macro when declaring classes that implement this interface. */
#define NS_DECL_NSINAVBOOKMARKOBSERVER_MOZILLA_1_9_1_ADDITIONS \
  NS_SCRIPTABLE NS_IMETHOD OnBeforeItemRemoved(PRInt64 aItemId); 

/* Use this macro to declare functions that forward the behavior of this interface to another object. */
#define NS_FORWARD_NSINAVBOOKMARKOBSERVER_MOZILLA_1_9_1_ADDITIONS(_to) \
  NS_SCRIPTABLE NS_IMETHOD OnBeforeItemRemoved(PRInt64 aItemId) { return _to OnBeforeItemRemoved(aItemId); } 

/* Use this macro to declare functions that forward the behavior of this interface to another object in a safe way. */
#define NS_FORWARD_SAFE_NSINAVBOOKMARKOBSERVER_MOZILLA_1_9_1_ADDITIONS(_to) \
  NS_SCRIPTABLE NS_IMETHOD OnBeforeItemRemoved(PRInt64 aItemId) { return !_to ? NS_ERROR_NULL_POINTER : _to->OnBeforeItemRemoved(aItemId); } 

#if 0
/* Use the code below as a template for the implementation class for this interface. */

/* Header file */
class nsNavBookmarkObserver_MOZILLA_1_9_1_ADDITIONS : public nsINavBookmarkObserver_MOZILLA_1_9_1_ADDITIONS
{
public:
  NS_DECL_ISUPPORTS
  NS_DECL_NSINAVBOOKMARKOBSERVER_MOZILLA_1_9_1_ADDITIONS

  nsNavBookmarkObserver_MOZILLA_1_9_1_ADDITIONS();

private:
  ~nsNavBookmarkObserver_MOZILLA_1_9_1_ADDITIONS();

protected:
  /* additional members */
};

/* Implementation file */
NS_IMPL_ISUPPORTS1(nsNavBookmarkObserver_MOZILLA_1_9_1_ADDITIONS, nsINavBookmarkObserver_MOZILLA_1_9_1_ADDITIONS)

nsNavBookmarkObserver_MOZILLA_1_9_1_ADDITIONS::nsNavBookmarkObserver_MOZILLA_1_9_1_ADDITIONS()
{
  /* member initializers and constructor code */
}

nsNavBookmarkObserver_MOZILLA_1_9_1_ADDITIONS::~nsNavBookmarkObserver_MOZILLA_1_9_1_ADDITIONS()
{
  /* destructor code */
}

/* void onBeforeItemRemoved (in long long aItemId); */
NS_IMETHODIMP nsNavBookmarkObserver_MOZILLA_1_9_1_ADDITIONS::OnBeforeItemRemoved(PRInt64 aItemId)
{
    return NS_ERROR_NOT_IMPLEMENTED;
}

/* End of implementation class template. */
#endif


/* starting interface:    nsINavBookmarksService */
#define NS_INAVBOOKMARKSSERVICE_IID_STR "3b6ff5c5-0ab4-4aab-b1be-d569763a6ce0"

#define NS_INAVBOOKMARKSSERVICE_IID \
  {0x3b6ff5c5, 0x0ab4, 0x4aab, \
    { 0xb1, 0xbe, 0xd5, 0x69, 0x76, 0x3a, 0x6c, 0xe0 }}

/**
 * The BookmarksService interface provides methods for managing bookmarked
 * history items.  Bookmarks consist of a set of user-customizable
 * folders.  A URI in history can be contained in one or more such folders.
 */
class NS_NO_VTABLE NS_SCRIPTABLE nsINavBookmarksService : public nsISupports {
 public: 

  NS_DECLARE_STATIC_IID_ACCESSOR(NS_INAVBOOKMARKSSERVICE_IID)

  /**
   * The item ID of the Places root.
   */
  /* readonly attribute long long placesRoot; */
  NS_SCRIPTABLE NS_IMETHOD GetPlacesRoot(PRInt64 *aPlacesRoot) = 0;

  /**
   * The item ID of the bookmarks menu folder.
   */
  /* readonly attribute long long bookmarksMenuFolder; */
  NS_SCRIPTABLE NS_IMETHOD GetBookmarksMenuFolder(PRInt64 *aBookmarksMenuFolder) = 0;

  /**
   * The item ID of the top-level folder that contain the tag "folders".
   */
  /* readonly attribute long long tagsFolder; */
  NS_SCRIPTABLE NS_IMETHOD GetTagsFolder(PRInt64 *aTagsFolder) = 0;

  /**
  * The item ID of the unfiled-bookmarks folder.
  */
  /* readonly attribute long long unfiledBookmarksFolder; */
  NS_SCRIPTABLE NS_IMETHOD GetUnfiledBookmarksFolder(PRInt64 *aUnfiledBookmarksFolder) = 0;

  /**
   * The item ID of the personal toolbar folder.
   */
  /* readonly attribute long long toolbarFolder; */
  NS_SCRIPTABLE NS_IMETHOD GetToolbarFolder(PRInt64 *aToolbarFolder) = 0;

  /**
   * This value should be used for APIs that allow passing in an index
   * where an index is not known, or not required to be specified.
   * e.g.: When appending an item to a folder.
   */
  enum { DEFAULT_INDEX = -1 };

  enum { TYPE_BOOKMARK = 1U };

  enum { TYPE_FOLDER = 2U };

  enum { TYPE_SEPARATOR = 3U };

  enum { TYPE_DYNAMIC_CONTAINER = 4U };

  /**
   * Inserts a child bookmark into the given folder.
   *
   *  @param aParentFolder
   *         The id of the parent folder
   *  @param aURI
   *         The URI to insert
   *  @param aIndex
   *         The index to insert at, or DEFAULT_INDEX to append
   *  @param aTitle
   *         The title for the new bookmark
   *  @returns The ID of the newly-created bookmark
   */
  /* long long insertBookmark (in long long aParentFolder, in nsIURI aURI, in long aIndex, in AUTF8String aTitle); */
  NS_SCRIPTABLE NS_IMETHOD InsertBookmark(PRInt64 aParentFolder, nsIURI *aURI, PRInt32 aIndex, const nsACString & aTitle, PRInt64 *_retval NS_OUTPARAM) = 0;

  /**
   * Removes a child item. Used to delete a bookmark or separator.
   *  @param aItemId
   *         The child item to remove
   */
  /* void removeItem (in long long aItemId); */
  NS_SCRIPTABLE NS_IMETHOD RemoveItem(PRInt64 aItemId) = 0;

  /**
   * Creates a new child folder and inserts it under the given parent.
   *  @param aParentFolder
   *         The id of the parent folder
   *  @param aName
   *         The name of the new folder
   *  @param aIndex
   *         The index to insert at, or DEFAULT_INDEX to append
   *  @returns the ID of the newly-inserted folder
   */
  /* long long createFolder (in long long aParentFolder, in AUTF8String name, in long index); */
  NS_SCRIPTABLE NS_IMETHOD CreateFolder(PRInt64 aParentFolder, const nsACString & name, PRInt32 index, PRInt64 *_retval NS_OUTPARAM) = 0;

  /**
   * Creates a dynamic container under the given parent folder.
   *
   *  @param aParentFolder
   *         The id of the parent folder
   *  @param aName
   *         The name of the new folder
   *  @param aContractId
   *         The contract id of the service which is to manipulate this
   *         container.
   *  @param aIndex
   *         The index to insert at, or DEFAULT_INDEX to append
   *         
   *  @returns the ID of the newly-inserted folder
   */
  /* long long createDynamicContainer (in long long aParentFolder, in AUTF8String aName, in AString aContractId, in long aIndex); */
  NS_SCRIPTABLE NS_IMETHOD CreateDynamicContainer(PRInt64 aParentFolder, const nsACString & aName, const nsAString & aContractId, PRInt32 aIndex, PRInt64 *_retval NS_OUTPARAM) = 0;

  /**
   * Removes a folder from the bookmarks tree.
   *
   * NOTE: This API is deprecated. The correct method to use is removeItem.
   *       This will be removed in the next release after Firefox 3.0. The
   *       removal is in bug 428558.
   *
   *  @param aFolder
   *         The id of the folder to remove.
   */
  /* void removeFolder (in long long aFolder); */
  NS_SCRIPTABLE NS_IMETHOD RemoveFolder(PRInt64 aFolder) = 0;

  /**
   * Gets an undo-able transaction for removing a folder from the bookmarks
   * tree. 
   *  @param folder
   *         The id of the folder to remove.
   *  @returns An object implementing nsITransaction that can be used to undo 
   *           or redo the action. 
   *
   * This method exists because complex delete->undo operations rely on 
   * recreated folders to have the same ID they had before they were deleted, 
   * so that any other items deleted in different transactions can be 
   * re-inserted correctly. This provides a safe encapsulation of this 
   * functionality without exposing the ability to recreate folders with 
   * specific IDs (potentially dangerous if abused by other code!) in the
   * public API.
   */
  /* nsITransaction getRemoveFolderTransaction (in long long aFolder); */
  NS_SCRIPTABLE NS_IMETHOD GetRemoveFolderTransaction(PRInt64 aFolder, nsITransaction **_retval NS_OUTPARAM) = 0;

  /**
   * Convenience function for container services.  Removes
   * all children of the given folder.
   *  @param aFolder
   *         The id of the folder to remove children from.
   */
  /* void removeFolderChildren (in long long aFolder); */
  NS_SCRIPTABLE NS_IMETHOD RemoveFolderChildren(PRInt64 aFolder) = 0;

  /**
   * Moves an item to a different container, preserving its contents.
   *  @param aItemId
   *         The id of the item to move
   *  @param aNewParent
   *         The id of the new parent
   *  @param aIndex
   *         The index under aNewParent, or DEFAULT_INDEX to append
   *
   * NOTE: When moving down in the same container we take into account the
   * removal of the original item. If you want to move from index X to
   * index Y > X you must use moveItem(id, folder, Y + 1)
   */
  /* void moveItem (in long long aItemId, in long long aNewParent, in long aIndex); */
  NS_SCRIPTABLE NS_IMETHOD MoveItem(PRInt64 aItemId, PRInt64 aNewParent, PRInt32 aIndex) = 0;

  /**
   * Returns the ID of a child folder with the given name. This does not
   * recurse, you have to give it an immediate sibling of the given folder.
   * If the given subfolder doesn't exist, it will return 0.
   *  @param aFolder
   *         Parent folder whose children we will search
   *  @param aSubFolder
   *         Name of the folder to search for in folder
   */
  /* long long getChildFolder (in long long aFolder, in AString aSubFolder); */
  NS_SCRIPTABLE NS_IMETHOD GetChildFolder(PRInt64 aFolder, const nsAString & aSubFolder, PRInt64 *_retval NS_OUTPARAM) = 0;

  /**
   * Inserts a bookmark separator into the given folder at the given index.
   * The separator can be removed using removeChildAt().
   *  @param aFolder
   *         Parent folder of the separator
   *  @param aIndex
   *         The separator's index under folder, or DEFAULT_INDEX to append
   *  @returns the id of the new separator
   */
  /* long long insertSeparator (in long long aFolder, in long aIndex); */
  NS_SCRIPTABLE NS_IMETHOD InsertSeparator(PRInt64 aFolder, PRInt32 aIndex, PRInt64 *_retval NS_OUTPARAM) = 0;

  /**
   * Removes any type of child (item, folder, or separator) at the given index.
   *  @param aFolder
   *         The folder to remove a child from
   *  @param aIndex
   *         The index of the child to remove
   */
  /* void removeChildAt (in long long aFolder, in long aIndex); */
  NS_SCRIPTABLE NS_IMETHOD RemoveChildAt(PRInt64 aFolder, PRInt32 aIndex) = 0;

  /**
   * Get the itemId given the containing folder and the index.
   *  @param aFolder
   *         The direct parent folder of the item
   *  @param aIndex
   *         The index of the item within aFolder, DEFAULT_INDEX for the last item
   *  @returns the id of the found item, -1 if the item does not exists
   */
  /* long long getIdForItemAt (in long long aFolder, in long aIndex); */
  NS_SCRIPTABLE NS_IMETHOD GetIdForItemAt(PRInt64 aFolder, PRInt32 aIndex, PRInt64 *_retval NS_OUTPARAM) = 0;

  /**
   * Get a globally unique identifier for an item, meant to be used in
   * sync scenarios.  Even if their contents are exactly the same
   * (including an item in a different profile with the same ItemId),
   * the GUID would be different.
   *  @param   aItemId
   *           The ID of the item to get the GUID for
   *  @returns The GUID string
   */
  /* AString getItemGUID (in long long aItemId); */
  NS_SCRIPTABLE NS_IMETHOD GetItemGUID(PRInt64 aItemId, nsAString & _retval NS_OUTPARAM) = 0;

  /**
   * Set a globally unique identifier.  This can be useful when a sync
   * algorithm deems two independently created items (on different
   * profiles) to be the same item.
   *  @param   aItemId
   *           The id of the item to set the GUID of
   *  @param   aGUID
   *           The GUID string
   */
  /* void setItemGUID (in long long aItemId, in AString aGUID); */
  NS_SCRIPTABLE NS_IMETHOD SetItemGUID(PRInt64 aItemId, const nsAString & aGUID) = 0;

  /**
   * Get the ID of the item with the given GUID.
   * @param   aGUID
   *          The GUID string of the item to search for
   * @returns The item ID, or -1 if not found
   */
  /* long long getItemIdForGUID (in AString aGUID); */
  NS_SCRIPTABLE NS_IMETHOD GetItemIdForGUID(const nsAString & aGUID, PRInt64 *_retval NS_OUTPARAM) = 0;

  /**
   * Set the title for an item.
   *  @param aItemId
   *         The id of the item whose title should be updated 
   *  @param aTitle
   *         The new title for the bookmark.
   */
  /* void setItemTitle (in long long aItemId, in AUTF8String aTitle); */
  NS_SCRIPTABLE NS_IMETHOD SetItemTitle(PRInt64 aItemId, const nsACString & aTitle) = 0;

  /**
   * Get the title for an item.
   *
   * If no item title is available it will return a void string (null in JS).
   *
   *  @param aItemId
   *         The id of the item whose title should be retrieved
   *  @returns The title of the item.
   */
  /* AUTF8String getItemTitle (in long long aItemId); */
  NS_SCRIPTABLE NS_IMETHOD GetItemTitle(PRInt64 aItemId, nsACString & _retval NS_OUTPARAM) = 0;

  /**
   * Set the date added time for an item.
   */
  /* void setItemDateAdded (in long long aItemId, in PRTime aDateAdded); */
  NS_SCRIPTABLE NS_IMETHOD SetItemDateAdded(PRInt64 aItemId, PRTime aDateAdded) = 0;

  /**
   * Get the date added time for an item.
   */
  /* PRTime getItemDateAdded (in long long aItemId); */
  NS_SCRIPTABLE NS_IMETHOD GetItemDateAdded(PRInt64 aItemId, PRTime *_retval NS_OUTPARAM) = 0;

  /**
   * Set the last modified time for an item.
   */
  /* void setItemLastModified (in long long aItemId, in PRTime aLastModified); */
  NS_SCRIPTABLE NS_IMETHOD SetItemLastModified(PRInt64 aItemId, PRTime aLastModified) = 0;

  /**
   * Get the last modified time for an item.
   */
  /* PRTime getItemLastModified (in long long aItemId); */
  NS_SCRIPTABLE NS_IMETHOD GetItemLastModified(PRInt64 aItemId, PRTime *_retval NS_OUTPARAM) = 0;

  /**
   * Get the URI for a bookmark item.
   */
  /* nsIURI getBookmarkURI (in long long aItemId); */
  NS_SCRIPTABLE NS_IMETHOD GetBookmarkURI(PRInt64 aItemId, nsIURI **_retval NS_OUTPARAM) = 0;

  /**
   * Get the index for an item.
   */
  /* long getItemIndex (in long long aItemId); */
  NS_SCRIPTABLE NS_IMETHOD GetItemIndex(PRInt64 aItemId, PRInt32 *_retval NS_OUTPARAM) = 0;

  /**
   * Changes the index for a item. This method does not change the indices of
   * any other items in the same folder, so ensure that the new index does not
   * already exist, or change the index of other items accordingly, otherwise
   * the indices will become corrupted.
   *
   * WARNING: This is API is intended for scenarios such as folder sorting,
   *          where the caller manages the indices of *all* items in the folder.
   *
   *  @param aItemId    The id of the item to modify
   *  @param aNewIndex  The new index
   */
  /* void setItemIndex (in long long aItemId, in long aNewIndex); */
  NS_SCRIPTABLE NS_IMETHOD SetItemIndex(PRInt64 aItemId, PRInt32 aNewIndex) = 0;

  /**
   * Get an item's type (bookmark, separator, folder).
   * The type is one of the TYPE_* constants defined above.
   */
  /* unsigned short getItemType (in long long aItemId); */
  NS_SCRIPTABLE NS_IMETHOD GetItemType(PRInt64 aItemId, PRUint16 *_retval NS_OUTPARAM) = 0;

  /**
   * Checks whether a folder is marked as read-only.
   * If this is set to true, UI will not allow the user to add, remove,
   * or reorder children in this folder. The default for all folders is false.
   * Note: This does not restrict API calls, only UI actions.
   *
   * @param aFolder
   *        the item-id of the folder.
   */
  /* boolean getFolderReadonly (in long long aFolder); */
  NS_SCRIPTABLE NS_IMETHOD GetFolderReadonly(PRInt64 aFolder, PRBool *_retval NS_OUTPARAM) = 0;

  /**
   * Sets or unsets the readonly flag from a folder.
   * If this is set to true, UI will not allow the user to add, remove,
   * or reorder children in this folder. The default for all folders is false.
   * Note: This does not restrict API calls, only UI actions.
   *
   * @param aFolder
   *        the item-id of the folder.
   * @param aReadOnly
   *        the read-only state (boolean).
   */
  /* void setFolderReadonly (in long long aFolder, in boolean aReadOnly); */
  NS_SCRIPTABLE NS_IMETHOD SetFolderReadonly(PRInt64 aFolder, PRBool aReadOnly) = 0;

  /**
   * Returns true if the given URI is in any bookmark folder. If you want the
   * results to be redirect-aware, use getBookmarkedURIFor()
   */
  /* boolean isBookmarked (in nsIURI aURI); */
  NS_SCRIPTABLE NS_IMETHOD IsBookmarked(nsIURI *aURI, PRBool *_retval NS_OUTPARAM) = 0;

  /**
   * Used to see if the given URI is bookmarked, or any page that redirected to
   * it is bookmarked. For example, if I bookmark "mozilla.org" by manually
   * typing it in, and follow the bookmark, I will get redirected to
   * "www.mozilla.org". Logically, this new page is also bookmarked. This
   * function, if given "www.mozilla.org", will return the URI of the bookmark,
   * in this case "mozilla.org".
   *
   * If there is no bookmarked page found, it will return NULL.
   */
  /* nsIURI getBookmarkedURIFor (in nsIURI aURI); */
  NS_SCRIPTABLE NS_IMETHOD GetBookmarkedURIFor(nsIURI *aURI, nsIURI **_retval NS_OUTPARAM) = 0;

  /**
   * Change the bookmarked URI for a bookmark.
   * This changes which "place" the bookmark points at,
   * which means all annotations, etc are carried along.
   */
  /* void changeBookmarkURI (in long long aItemId, in nsIURI aNewURI); */
  NS_SCRIPTABLE NS_IMETHOD ChangeBookmarkURI(PRInt64 aItemId, nsIURI *aNewURI) = 0;

  /**
   * Get the parent folder's id for an item.
   */
  /* long long getFolderIdForItem (in long long aItemId); */
  NS_SCRIPTABLE NS_IMETHOD GetFolderIdForItem(PRInt64 aItemId, PRInt64 *_retval NS_OUTPARAM) = 0;

  /**
   * Returns the list of bookmark ids that contain the given URI.
   */
  /* void getBookmarkIdsForURI (in nsIURI aURI, out unsigned long count, [array, size_is (count), retval] out long long bookmarks); */
  NS_SCRIPTABLE NS_IMETHOD GetBookmarkIdsForURI(nsIURI *aURI, PRUint32 *count NS_OUTPARAM, PRInt64 **bookmarks NS_OUTPARAM) = 0;

  /**
   * TArray version of getBookmarksIdForURI for ease of use in C++ code.
   * Pass in a reference to a TArray; it will get cleared and filled with
   * the resulting list of folder IDs.
   */
  /* [noscript] void getBookmarkIdsForURITArray (in nsIURI aURI, in PRInt64Array aResult); */
  NS_IMETHOD GetBookmarkIdsForURITArray(nsIURI *aURI, nsTArray<PRInt64> * aResult) = 0;

  /**
   * Associates the given keyword with the given bookmark.
   *
   * Use an empty keyword to clear the keyword associated with the URI.
   * In both of these cases, succeeds but does nothing if the URL/keyword is not found.
   */
  /* void setKeywordForBookmark (in long long aItemId, in AString aKeyword); */
  NS_SCRIPTABLE NS_IMETHOD SetKeywordForBookmark(PRInt64 aItemId, const nsAString & aKeyword) = 0;

  /**
   * Retrieves the keyword for the given URI. Will be void string
   * (null in JS) if no such keyword is found.
   */
  /* AString getKeywordForURI (in nsIURI aURI); */
  NS_SCRIPTABLE NS_IMETHOD GetKeywordForURI(nsIURI *aURI, nsAString & _retval NS_OUTPARAM) = 0;

  /**
   * Retrieves the keyword for the given bookmark. Will be void string
   * (null in JS) if no such keyword is found.
   */
  /* AString getKeywordForBookmark (in long long aItemId); */
  NS_SCRIPTABLE NS_IMETHOD GetKeywordForBookmark(PRInt64 aItemId, nsAString & _retval NS_OUTPARAM) = 0;

  /**
   * Returns the URI associated with the given keyword. Empty if no such
   * keyword is found.
   */
  /* nsIURI getURIForKeyword (in AString keyword); */
  NS_SCRIPTABLE NS_IMETHOD GetURIForKeyword(const nsAString & keyword, nsIURI **_retval NS_OUTPARAM) = 0;

  /**
   * Adds a bookmark observer. If ownsWeak is false, the bookmark service will
   * keep an owning reference to the observer.  If ownsWeak is true, then
   * aObserver must implement nsISupportsWeakReference, and the bookmark
   * service will keep a weak reference to the observer.
   */
  /* void addObserver (in nsINavBookmarkObserver observer, in boolean ownsWeak); */
  NS_SCRIPTABLE NS_IMETHOD AddObserver(nsINavBookmarkObserver *observer, PRBool ownsWeak) = 0;

  /**
   * Removes a bookmark observer.
   */
  /* void removeObserver (in nsINavBookmarkObserver observer); */
  NS_SCRIPTABLE NS_IMETHOD RemoveObserver(nsINavBookmarkObserver *observer) = 0;

  /**
   * Runs the passed callback inside of a database transaction.
   * Use this when a lot of things are about to change, for example
   * adding or deleting a large number of bookmark items. Calls can
   * be nested. Observers are notified when batches begin and end, via 
   * nsINavBookmarkObserver.onBeginUpdateBatch/onEndUpdateBatch.
   *
   * @param aCallback
   *        nsINavHistoryBatchCallback interface to call.
   * @param aUserData
   *        Opaque parameter passed to nsINavBookmarksBatchCallback
   */
  /* void runInBatchMode (in nsINavHistoryBatchCallback aCallback, in nsISupports aUserData); */
  NS_SCRIPTABLE NS_IMETHOD RunInBatchMode(nsINavHistoryBatchCallback *aCallback, nsISupports *aUserData) = 0;

};

  NS_DEFINE_STATIC_IID_ACCESSOR(nsINavBookmarksService, NS_INAVBOOKMARKSSERVICE_IID)

/* Use this macro when declaring classes that implement this interface. */
#define NS_DECL_NSINAVBOOKMARKSSERVICE \
  NS_SCRIPTABLE NS_IMETHOD GetPlacesRoot(PRInt64 *aPlacesRoot); \
  NS_SCRIPTABLE NS_IMETHOD GetBookmarksMenuFolder(PRInt64 *aBookmarksMenuFolder); \
  NS_SCRIPTABLE NS_IMETHOD GetTagsFolder(PRInt64 *aTagsFolder); \
  NS_SCRIPTABLE NS_IMETHOD GetUnfiledBookmarksFolder(PRInt64 *aUnfiledBookmarksFolder); \
  NS_SCRIPTABLE NS_IMETHOD GetToolbarFolder(PRInt64 *aToolbarFolder); \
  NS_SCRIPTABLE NS_IMETHOD InsertBookmark(PRInt64 aParentFolder, nsIURI *aURI, PRInt32 aIndex, const nsACString & aTitle, PRInt64 *_retval NS_OUTPARAM); \
  NS_SCRIPTABLE NS_IMETHOD RemoveItem(PRInt64 aItemId); \
  NS_SCRIPTABLE NS_IMETHOD CreateFolder(PRInt64 aParentFolder, const nsACString & name, PRInt32 index, PRInt64 *_retval NS_OUTPARAM); \
  NS_SCRIPTABLE NS_IMETHOD CreateDynamicContainer(PRInt64 aParentFolder, const nsACString & aName, const nsAString & aContractId, PRInt32 aIndex, PRInt64 *_retval NS_OUTPARAM); \
  NS_SCRIPTABLE NS_IMETHOD RemoveFolder(PRInt64 aFolder); \
  NS_SCRIPTABLE NS_IMETHOD GetRemoveFolderTransaction(PRInt64 aFolder, nsITransaction **_retval NS_OUTPARAM); \
  NS_SCRIPTABLE NS_IMETHOD RemoveFolderChildren(PRInt64 aFolder); \
  NS_SCRIPTABLE NS_IMETHOD MoveItem(PRInt64 aItemId, PRInt64 aNewParent, PRInt32 aIndex); \
  NS_SCRIPTABLE NS_IMETHOD GetChildFolder(PRInt64 aFolder, const nsAString & aSubFolder, PRInt64 *_retval NS_OUTPARAM); \
  NS_SCRIPTABLE NS_IMETHOD InsertSeparator(PRInt64 aFolder, PRInt32 aIndex, PRInt64 *_retval NS_OUTPARAM); \
  NS_SCRIPTABLE NS_IMETHOD RemoveChildAt(PRInt64 aFolder, PRInt32 aIndex); \
  NS_SCRIPTABLE NS_IMETHOD GetIdForItemAt(PRInt64 aFolder, PRInt32 aIndex, PRInt64 *_retval NS_OUTPARAM); \
  NS_SCRIPTABLE NS_IMETHOD GetItemGUID(PRInt64 aItemId, nsAString & _retval NS_OUTPARAM); \
  NS_SCRIPTABLE NS_IMETHOD SetItemGUID(PRInt64 aItemId, const nsAString & aGUID); \
  NS_SCRIPTABLE NS_IMETHOD GetItemIdForGUID(const nsAString & aGUID, PRInt64 *_retval NS_OUTPARAM); \
  NS_SCRIPTABLE NS_IMETHOD SetItemTitle(PRInt64 aItemId, const nsACString & aTitle); \
  NS_SCRIPTABLE NS_IMETHOD GetItemTitle(PRInt64 aItemId, nsACString & _retval NS_OUTPARAM); \
  NS_SCRIPTABLE NS_IMETHOD SetItemDateAdded(PRInt64 aItemId, PRTime aDateAdded); \
  NS_SCRIPTABLE NS_IMETHOD GetItemDateAdded(PRInt64 aItemId, PRTime *_retval NS_OUTPARAM); \
  NS_SCRIPTABLE NS_IMETHOD SetItemLastModified(PRInt64 aItemId, PRTime aLastModified); \
  NS_SCRIPTABLE NS_IMETHOD GetItemLastModified(PRInt64 aItemId, PRTime *_retval NS_OUTPARAM); \
  NS_SCRIPTABLE NS_IMETHOD GetBookmarkURI(PRInt64 aItemId, nsIURI **_retval NS_OUTPARAM); \
  NS_SCRIPTABLE NS_IMETHOD GetItemIndex(PRInt64 aItemId, PRInt32 *_retval NS_OUTPARAM); \
  NS_SCRIPTABLE NS_IMETHOD SetItemIndex(PRInt64 aItemId, PRInt32 aNewIndex); \
  NS_SCRIPTABLE NS_IMETHOD GetItemType(PRInt64 aItemId, PRUint16 *_retval NS_OUTPARAM); \
  NS_SCRIPTABLE NS_IMETHOD GetFolderReadonly(PRInt64 aFolder, PRBool *_retval NS_OUTPARAM); \
  NS_SCRIPTABLE NS_IMETHOD SetFolderReadonly(PRInt64 aFolder, PRBool aReadOnly); \
  NS_SCRIPTABLE NS_IMETHOD IsBookmarked(nsIURI *aURI, PRBool *_retval NS_OUTPARAM); \
  NS_SCRIPTABLE NS_IMETHOD GetBookmarkedURIFor(nsIURI *aURI, nsIURI **_retval NS_OUTPARAM); \
  NS_SCRIPTABLE NS_IMETHOD ChangeBookmarkURI(PRInt64 aItemId, nsIURI *aNewURI); \
  NS_SCRIPTABLE NS_IMETHOD GetFolderIdForItem(PRInt64 aItemId, PRInt64 *_retval NS_OUTPARAM); \
  NS_SCRIPTABLE NS_IMETHOD GetBookmarkIdsForURI(nsIURI *aURI, PRUint32 *count NS_OUTPARAM, PRInt64 **bookmarks NS_OUTPARAM); \
  NS_IMETHOD GetBookmarkIdsForURITArray(nsIURI *aURI, nsTArray<PRInt64> * aResult); \
  NS_SCRIPTABLE NS_IMETHOD SetKeywordForBookmark(PRInt64 aItemId, const nsAString & aKeyword); \
  NS_SCRIPTABLE NS_IMETHOD GetKeywordForURI(nsIURI *aURI, nsAString & _retval NS_OUTPARAM); \
  NS_SCRIPTABLE NS_IMETHOD GetKeywordForBookmark(PRInt64 aItemId, nsAString & _retval NS_OUTPARAM); \
  NS_SCRIPTABLE NS_IMETHOD GetURIForKeyword(const nsAString & keyword, nsIURI **_retval NS_OUTPARAM); \
  NS_SCRIPTABLE NS_IMETHOD AddObserver(nsINavBookmarkObserver *observer, PRBool ownsWeak); \
  NS_SCRIPTABLE NS_IMETHOD RemoveObserver(nsINavBookmarkObserver *observer); \
  NS_SCRIPTABLE NS_IMETHOD RunInBatchMode(nsINavHistoryBatchCallback *aCallback, nsISupports *aUserData); 

/* Use this macro to declare functions that forward the behavior of this interface to another object. */
#define NS_FORWARD_NSINAVBOOKMARKSSERVICE(_to) \
  NS_SCRIPTABLE NS_IMETHOD GetPlacesRoot(PRInt64 *aPlacesRoot) { return _to GetPlacesRoot(aPlacesRoot); } \
  NS_SCRIPTABLE NS_IMETHOD GetBookmarksMenuFolder(PRInt64 *aBookmarksMenuFolder) { return _to GetBookmarksMenuFolder(aBookmarksMenuFolder); } \
  NS_SCRIPTABLE NS_IMETHOD GetTagsFolder(PRInt64 *aTagsFolder) { return _to GetTagsFolder(aTagsFolder); } \
  NS_SCRIPTABLE NS_IMETHOD GetUnfiledBookmarksFolder(PRInt64 *aUnfiledBookmarksFolder) { return _to GetUnfiledBookmarksFolder(aUnfiledBookmarksFolder); } \
  NS_SCRIPTABLE NS_IMETHOD GetToolbarFolder(PRInt64 *aToolbarFolder) { return _to GetToolbarFolder(aToolbarFolder); } \
  NS_SCRIPTABLE NS_IMETHOD InsertBookmark(PRInt64 aParentFolder, nsIURI *aURI, PRInt32 aIndex, const nsACString & aTitle, PRInt64 *_retval NS_OUTPARAM) { return _to InsertBookmark(aParentFolder, aURI, aIndex, aTitle, _retval); } \
  NS_SCRIPTABLE NS_IMETHOD RemoveItem(PRInt64 aItemId) { return _to RemoveItem(aItemId); } \
  NS_SCRIPTABLE NS_IMETHOD CreateFolder(PRInt64 aParentFolder, const nsACString & name, PRInt32 index, PRInt64 *_retval NS_OUTPARAM) { return _to CreateFolder(aParentFolder, name, index, _retval); } \
  NS_SCRIPTABLE NS_IMETHOD CreateDynamicContainer(PRInt64 aParentFolder, const nsACString & aName, const nsAString & aContractId, PRInt32 aIndex, PRInt64 *_retval NS_OUTPARAM) { return _to CreateDynamicContainer(aParentFolder, aName, aContractId, aIndex, _retval); } \
  NS_SCRIPTABLE NS_IMETHOD RemoveFolder(PRInt64 aFolder) { return _to RemoveFolder(aFolder); } \
  NS_SCRIPTABLE NS_IMETHOD GetRemoveFolderTransaction(PRInt64 aFolder, nsITransaction **_retval NS_OUTPARAM) { return _to GetRemoveFolderTransaction(aFolder, _retval); } \
  NS_SCRIPTABLE NS_IMETHOD RemoveFolderChildren(PRInt64 aFolder) { return _to RemoveFolderChildren(aFolder); } \
  NS_SCRIPTABLE NS_IMETHOD MoveItem(PRInt64 aItemId, PRInt64 aNewParent, PRInt32 aIndex) { return _to MoveItem(aItemId, aNewParent, aIndex); } \
  NS_SCRIPTABLE NS_IMETHOD GetChildFolder(PRInt64 aFolder, const nsAString & aSubFolder, PRInt64 *_retval NS_OUTPARAM) { return _to GetChildFolder(aFolder, aSubFolder, _retval); } \
  NS_SCRIPTABLE NS_IMETHOD InsertSeparator(PRInt64 aFolder, PRInt32 aIndex, PRInt64 *_retval NS_OUTPARAM) { return _to InsertSeparator(aFolder, aIndex, _retval); } \
  NS_SCRIPTABLE NS_IMETHOD RemoveChildAt(PRInt64 aFolder, PRInt32 aIndex) { return _to RemoveChildAt(aFolder, aIndex); } \
  NS_SCRIPTABLE NS_IMETHOD GetIdForItemAt(PRInt64 aFolder, PRInt32 aIndex, PRInt64 *_retval NS_OUTPARAM) { return _to GetIdForItemAt(aFolder, aIndex, _retval); } \
  NS_SCRIPTABLE NS_IMETHOD GetItemGUID(PRInt64 aItemId, nsAString & _retval NS_OUTPARAM) { return _to GetItemGUID(aItemId, _retval); } \
  NS_SCRIPTABLE NS_IMETHOD SetItemGUID(PRInt64 aItemId, const nsAString & aGUID) { return _to SetItemGUID(aItemId, aGUID); } \
  NS_SCRIPTABLE NS_IMETHOD GetItemIdForGUID(const nsAString & aGUID, PRInt64 *_retval NS_OUTPARAM) { return _to GetItemIdForGUID(aGUID, _retval); } \
  NS_SCRIPTABLE NS_IMETHOD SetItemTitle(PRInt64 aItemId, const nsACString & aTitle) { return _to SetItemTitle(aItemId, aTitle); } \
  NS_SCRIPTABLE NS_IMETHOD GetItemTitle(PRInt64 aItemId, nsACString & _retval NS_OUTPARAM) { return _to GetItemTitle(aItemId, _retval); } \
  NS_SCRIPTABLE NS_IMETHOD SetItemDateAdded(PRInt64 aItemId, PRTime aDateAdded) { return _to SetItemDateAdded(aItemId, aDateAdded); } \
  NS_SCRIPTABLE NS_IMETHOD GetItemDateAdded(PRInt64 aItemId, PRTime *_retval NS_OUTPARAM) { return _to GetItemDateAdded(aItemId, _retval); } \
  NS_SCRIPTABLE NS_IMETHOD SetItemLastModified(PRInt64 aItemId, PRTime aLastModified) { return _to SetItemLastModified(aItemId, aLastModified); } \
  NS_SCRIPTABLE NS_IMETHOD GetItemLastModified(PRInt64 aItemId, PRTime *_retval NS_OUTPARAM) { return _to GetItemLastModified(aItemId, _retval); } \
  NS_SCRIPTABLE NS_IMETHOD GetBookmarkURI(PRInt64 aItemId, nsIURI **_retval NS_OUTPARAM) { return _to GetBookmarkURI(aItemId, _retval); } \
  NS_SCRIPTABLE NS_IMETHOD GetItemIndex(PRInt64 aItemId, PRInt32 *_retval NS_OUTPARAM) { return _to GetItemIndex(aItemId, _retval); } \
  NS_SCRIPTABLE NS_IMETHOD SetItemIndex(PRInt64 aItemId, PRInt32 aNewIndex) { return _to SetItemIndex(aItemId, aNewIndex); } \
  NS_SCRIPTABLE NS_IMETHOD GetItemType(PRInt64 aItemId, PRUint16 *_retval NS_OUTPARAM) { return _to GetItemType(aItemId, _retval); } \
  NS_SCRIPTABLE NS_IMETHOD GetFolderReadonly(PRInt64 aFolder, PRBool *_retval NS_OUTPARAM) { return _to GetFolderReadonly(aFolder, _retval); } \
  NS_SCRIPTABLE NS_IMETHOD SetFolderReadonly(PRInt64 aFolder, PRBool aReadOnly) { return _to SetFolderReadonly(aFolder, aReadOnly); } \
  NS_SCRIPTABLE NS_IMETHOD IsBookmarked(nsIURI *aURI, PRBool *_retval NS_OUTPARAM) { return _to IsBookmarked(aURI, _retval); } \
  NS_SCRIPTABLE NS_IMETHOD GetBookmarkedURIFor(nsIURI *aURI, nsIURI **_retval NS_OUTPARAM) { return _to GetBookmarkedURIFor(aURI, _retval); } \
  NS_SCRIPTABLE NS_IMETHOD ChangeBookmarkURI(PRInt64 aItemId, nsIURI *aNewURI) { return _to ChangeBookmarkURI(aItemId, aNewURI); } \
  NS_SCRIPTABLE NS_IMETHOD GetFolderIdForItem(PRInt64 aItemId, PRInt64 *_retval NS_OUTPARAM) { return _to GetFolderIdForItem(aItemId, _retval); } \
  NS_SCRIPTABLE NS_IMETHOD GetBookmarkIdsForURI(nsIURI *aURI, PRUint32 *count NS_OUTPARAM, PRInt64 **bookmarks NS_OUTPARAM) { return _to GetBookmarkIdsForURI(aURI, count, bookmarks); } \
  NS_IMETHOD GetBookmarkIdsForURITArray(nsIURI *aURI, nsTArray<PRInt64> * aResult) { return _to GetBookmarkIdsForURITArray(aURI, aResult); } \
  NS_SCRIPTABLE NS_IMETHOD SetKeywordForBookmark(PRInt64 aItemId, const nsAString & aKeyword) { return _to SetKeywordForBookmark(aItemId, aKeyword); } \
  NS_SCRIPTABLE NS_IMETHOD GetKeywordForURI(nsIURI *aURI, nsAString & _retval NS_OUTPARAM) { return _to GetKeywordForURI(aURI, _retval); } \
  NS_SCRIPTABLE NS_IMETHOD GetKeywordForBookmark(PRInt64 aItemId, nsAString & _retval NS_OUTPARAM) { return _to GetKeywordForBookmark(aItemId, _retval); } \
  NS_SCRIPTABLE NS_IMETHOD GetURIForKeyword(const nsAString & keyword, nsIURI **_retval NS_OUTPARAM) { return _to GetURIForKeyword(keyword, _retval); } \
  NS_SCRIPTABLE NS_IMETHOD AddObserver(nsINavBookmarkObserver *observer, PRBool ownsWeak) { return _to AddObserver(observer, ownsWeak); } \
  NS_SCRIPTABLE NS_IMETHOD RemoveObserver(nsINavBookmarkObserver *observer) { return _to RemoveObserver(observer); } \
  NS_SCRIPTABLE NS_IMETHOD RunInBatchMode(nsINavHistoryBatchCallback *aCallback, nsISupports *aUserData) { return _to RunInBatchMode(aCallback, aUserData); } 

/* Use this macro to declare functions that forward the behavior of this interface to another object in a safe way. */
#define NS_FORWARD_SAFE_NSINAVBOOKMARKSSERVICE(_to) \
  NS_SCRIPTABLE NS_IMETHOD GetPlacesRoot(PRInt64 *aPlacesRoot) { return !_to ? NS_ERROR_NULL_POINTER : _to->GetPlacesRoot(aPlacesRoot); } \
  NS_SCRIPTABLE NS_IMETHOD GetBookmarksMenuFolder(PRInt64 *aBookmarksMenuFolder) { return !_to ? NS_ERROR_NULL_POINTER : _to->GetBookmarksMenuFolder(aBookmarksMenuFolder); } \
  NS_SCRIPTABLE NS_IMETHOD GetTagsFolder(PRInt64 *aTagsFolder) { return !_to ? NS_ERROR_NULL_POINTER : _to->GetTagsFolder(aTagsFolder); } \
  NS_SCRIPTABLE NS_IMETHOD GetUnfiledBookmarksFolder(PRInt64 *aUnfiledBookmarksFolder) { return !_to ? NS_ERROR_NULL_POINTER : _to->GetUnfiledBookmarksFolder(aUnfiledBookmarksFolder); } \
  NS_SCRIPTABLE NS_IMETHOD GetToolbarFolder(PRInt64 *aToolbarFolder) { return !_to ? NS_ERROR_NULL_POINTER : _to->GetToolbarFolder(aToolbarFolder); } \
  NS_SCRIPTABLE NS_IMETHOD InsertBookmark(PRInt64 aParentFolder, nsIURI *aURI, PRInt32 aIndex, const nsACString & aTitle, PRInt64 *_retval NS_OUTPARAM) { return !_to ? NS_ERROR_NULL_POINTER : _to->InsertBookmark(aParentFolder, aURI, aIndex, aTitle, _retval); } \
  NS_SCRIPTABLE NS_IMETHOD RemoveItem(PRInt64 aItemId) { return !_to ? NS_ERROR_NULL_POINTER : _to->RemoveItem(aItemId); } \
  NS_SCRIPTABLE NS_IMETHOD CreateFolder(PRInt64 aParentFolder, const nsACString & name, PRInt32 index, PRInt64 *_retval NS_OUTPARAM) { return !_to ? NS_ERROR_NULL_POINTER : _to->CreateFolder(aParentFolder, name, index, _retval); } \
  NS_SCRIPTABLE NS_IMETHOD CreateDynamicContainer(PRInt64 aParentFolder, const nsACString & aName, const nsAString & aContractId, PRInt32 aIndex, PRInt64 *_retval NS_OUTPARAM) { return !_to ? NS_ERROR_NULL_POINTER : _to->CreateDynamicContainer(aParentFolder, aName, aContractId, aIndex, _retval); } \
  NS_SCRIPTABLE NS_IMETHOD RemoveFolder(PRInt64 aFolder) { return !_to ? NS_ERROR_NULL_POINTER : _to->RemoveFolder(aFolder); } \
  NS_SCRIPTABLE NS_IMETHOD GetRemoveFolderTransaction(PRInt64 aFolder, nsITransaction **_retval NS_OUTPARAM) { return !_to ? NS_ERROR_NULL_POINTER : _to->GetRemoveFolderTransaction(aFolder, _retval); } \
  NS_SCRIPTABLE NS_IMETHOD RemoveFolderChildren(PRInt64 aFolder) { return !_to ? NS_ERROR_NULL_POINTER : _to->RemoveFolderChildren(aFolder); } \
  NS_SCRIPTABLE NS_IMETHOD MoveItem(PRInt64 aItemId, PRInt64 aNewParent, PRInt32 aIndex) { return !_to ? NS_ERROR_NULL_POINTER : _to->MoveItem(aItemId, aNewParent, aIndex); } \
  NS_SCRIPTABLE NS_IMETHOD GetChildFolder(PRInt64 aFolder, const nsAString & aSubFolder, PRInt64 *_retval NS_OUTPARAM) { return !_to ? NS_ERROR_NULL_POINTER : _to->GetChildFolder(aFolder, aSubFolder, _retval); } \
  NS_SCRIPTABLE NS_IMETHOD InsertSeparator(PRInt64 aFolder, PRInt32 aIndex, PRInt64 *_retval NS_OUTPARAM) { return !_to ? NS_ERROR_NULL_POINTER : _to->InsertSeparator(aFolder, aIndex, _retval); } \
  NS_SCRIPTABLE NS_IMETHOD RemoveChildAt(PRInt64 aFolder, PRInt32 aIndex) { return !_to ? NS_ERROR_NULL_POINTER : _to->RemoveChildAt(aFolder, aIndex); } \
  NS_SCRIPTABLE NS_IMETHOD GetIdForItemAt(PRInt64 aFolder, PRInt32 aIndex, PRInt64 *_retval NS_OUTPARAM) { return !_to ? NS_ERROR_NULL_POINTER : _to->GetIdForItemAt(aFolder, aIndex, _retval); } \
  NS_SCRIPTABLE NS_IMETHOD GetItemGUID(PRInt64 aItemId, nsAString & _retval NS_OUTPARAM) { return !_to ? NS_ERROR_NULL_POINTER : _to->GetItemGUID(aItemId, _retval); } \
  NS_SCRIPTABLE NS_IMETHOD SetItemGUID(PRInt64 aItemId, const nsAString & aGUID) { return !_to ? NS_ERROR_NULL_POINTER : _to->SetItemGUID(aItemId, aGUID); } \
  NS_SCRIPTABLE NS_IMETHOD GetItemIdForGUID(const nsAString & aGUID, PRInt64 *_retval NS_OUTPARAM) { return !_to ? NS_ERROR_NULL_POINTER : _to->GetItemIdForGUID(aGUID, _retval); } \
  NS_SCRIPTABLE NS_IMETHOD SetItemTitle(PRInt64 aItemId, const nsACString & aTitle) { return !_to ? NS_ERROR_NULL_POINTER : _to->SetItemTitle(aItemId, aTitle); } \
  NS_SCRIPTABLE NS_IMETHOD GetItemTitle(PRInt64 aItemId, nsACString & _retval NS_OUTPARAM) { return !_to ? NS_ERROR_NULL_POINTER : _to->GetItemTitle(aItemId, _retval); } \
  NS_SCRIPTABLE NS_IMETHOD SetItemDateAdded(PRInt64 aItemId, PRTime aDateAdded) { return !_to ? NS_ERROR_NULL_POINTER : _to->SetItemDateAdded(aItemId, aDateAdded); } \
  NS_SCRIPTABLE NS_IMETHOD GetItemDateAdded(PRInt64 aItemId, PRTime *_retval NS_OUTPARAM) { return !_to ? NS_ERROR_NULL_POINTER : _to->GetItemDateAdded(aItemId, _retval); } \
  NS_SCRIPTABLE NS_IMETHOD SetItemLastModified(PRInt64 aItemId, PRTime aLastModified) { return !_to ? NS_ERROR_NULL_POINTER : _to->SetItemLastModified(aItemId, aLastModified); } \
  NS_SCRIPTABLE NS_IMETHOD GetItemLastModified(PRInt64 aItemId, PRTime *_retval NS_OUTPARAM) { return !_to ? NS_ERROR_NULL_POINTER : _to->GetItemLastModified(aItemId, _retval); } \
  NS_SCRIPTABLE NS_IMETHOD GetBookmarkURI(PRInt64 aItemId, nsIURI **_retval NS_OUTPARAM) { return !_to ? NS_ERROR_NULL_POINTER : _to->GetBookmarkURI(aItemId, _retval); } \
  NS_SCRIPTABLE NS_IMETHOD GetItemIndex(PRInt64 aItemId, PRInt32 *_retval NS_OUTPARAM) { return !_to ? NS_ERROR_NULL_POINTER : _to->GetItemIndex(aItemId, _retval); } \
  NS_SCRIPTABLE NS_IMETHOD SetItemIndex(PRInt64 aItemId, PRInt32 aNewIndex) { return !_to ? NS_ERROR_NULL_POINTER : _to->SetItemIndex(aItemId, aNewIndex); } \
  NS_SCRIPTABLE NS_IMETHOD GetItemType(PRInt64 aItemId, PRUint16 *_retval NS_OUTPARAM) { return !_to ? NS_ERROR_NULL_POINTER : _to->GetItemType(aItemId, _retval); } \
  NS_SCRIPTABLE NS_IMETHOD GetFolderReadonly(PRInt64 aFolder, PRBool *_retval NS_OUTPARAM) { return !_to ? NS_ERROR_NULL_POINTER : _to->GetFolderReadonly(aFolder, _retval); } \
  NS_SCRIPTABLE NS_IMETHOD SetFolderReadonly(PRInt64 aFolder, PRBool aReadOnly) { return !_to ? NS_ERROR_NULL_POINTER : _to->SetFolderReadonly(aFolder, aReadOnly); } \
  NS_SCRIPTABLE NS_IMETHOD IsBookmarked(nsIURI *aURI, PRBool *_retval NS_OUTPARAM) { return !_to ? NS_ERROR_NULL_POINTER : _to->IsBookmarked(aURI, _retval); } \
  NS_SCRIPTABLE NS_IMETHOD GetBookmarkedURIFor(nsIURI *aURI, nsIURI **_retval NS_OUTPARAM) { return !_to ? NS_ERROR_NULL_POINTER : _to->GetBookmarkedURIFor(aURI, _retval); } \
  NS_SCRIPTABLE NS_IMETHOD ChangeBookmarkURI(PRInt64 aItemId, nsIURI *aNewURI) { return !_to ? NS_ERROR_NULL_POINTER : _to->ChangeBookmarkURI(aItemId, aNewURI); } \
  NS_SCRIPTABLE NS_IMETHOD GetFolderIdForItem(PRInt64 aItemId, PRInt64 *_retval NS_OUTPARAM) { return !_to ? NS_ERROR_NULL_POINTER : _to->GetFolderIdForItem(aItemId, _retval); } \
  NS_SCRIPTABLE NS_IMETHOD GetBookmarkIdsForURI(nsIURI *aURI, PRUint32 *count NS_OUTPARAM, PRInt64 **bookmarks NS_OUTPARAM) { return !_to ? NS_ERROR_NULL_POINTER : _to->GetBookmarkIdsForURI(aURI, count, bookmarks); } \
  NS_IMETHOD GetBookmarkIdsForURITArray(nsIURI *aURI, nsTArray<PRInt64> * aResult) { return !_to ? NS_ERROR_NULL_POINTER : _to->GetBookmarkIdsForURITArray(aURI, aResult); } \
  NS_SCRIPTABLE NS_IMETHOD SetKeywordForBookmark(PRInt64 aItemId, const nsAString & aKeyword) { return !_to ? NS_ERROR_NULL_POINTER : _to->SetKeywordForBookmark(aItemId, aKeyword); } \
  NS_SCRIPTABLE NS_IMETHOD GetKeywordForURI(nsIURI *aURI, nsAString & _retval NS_OUTPARAM) { return !_to ? NS_ERROR_NULL_POINTER : _to->GetKeywordForURI(aURI, _retval); } \
  NS_SCRIPTABLE NS_IMETHOD GetKeywordForBookmark(PRInt64 aItemId, nsAString & _retval NS_OUTPARAM) { return !_to ? NS_ERROR_NULL_POINTER : _to->GetKeywordForBookmark(aItemId, _retval); } \
  NS_SCRIPTABLE NS_IMETHOD GetURIForKeyword(const nsAString & keyword, nsIURI **_retval NS_OUTPARAM) { return !_to ? NS_ERROR_NULL_POINTER : _to->GetURIForKeyword(keyword, _retval); } \
  NS_SCRIPTABLE NS_IMETHOD AddObserver(nsINavBookmarkObserver *observer, PRBool ownsWeak) { return !_to ? NS_ERROR_NULL_POINTER : _to->AddObserver(observer, ownsWeak); } \
  NS_SCRIPTABLE NS_IMETHOD RemoveObserver(nsINavBookmarkObserver *observer) { return !_to ? NS_ERROR_NULL_POINTER : _to->RemoveObserver(observer); } \
  NS_SCRIPTABLE NS_IMETHOD RunInBatchMode(nsINavHistoryBatchCallback *aCallback, nsISupports *aUserData) { return !_to ? NS_ERROR_NULL_POINTER : _to->RunInBatchMode(aCallback, aUserData); } 

#if 0
/* Use the code below as a template for the implementation class for this interface. */

/* Header file */
class nsNavBookmarksService : public nsINavBookmarksService
{
public:
  NS_DECL_ISUPPORTS
  NS_DECL_NSINAVBOOKMARKSSERVICE

  nsNavBookmarksService();

private:
  ~nsNavBookmarksService();

protected:
  /* additional members */
};

/* Implementation file */
NS_IMPL_ISUPPORTS1(nsNavBookmarksService, nsINavBookmarksService)

nsNavBookmarksService::nsNavBookmarksService()
{
  /* member initializers and constructor code */
}

nsNavBookmarksService::~nsNavBookmarksService()
{
  /* destructor code */
}

/* readonly attribute long long placesRoot; */
NS_IMETHODIMP nsNavBookmarksService::GetPlacesRoot(PRInt64 *aPlacesRoot)
{
    return NS_ERROR_NOT_IMPLEMENTED;
}

/* readonly attribute long long bookmarksMenuFolder; */
NS_IMETHODIMP nsNavBookmarksService::GetBookmarksMenuFolder(PRInt64 *aBookmarksMenuFolder)
{
    return NS_ERROR_NOT_IMPLEMENTED;
}

/* readonly attribute long long tagsFolder; */
NS_IMETHODIMP nsNavBookmarksService::GetTagsFolder(PRInt64 *aTagsFolder)
{
    return NS_ERROR_NOT_IMPLEMENTED;
}

/* readonly attribute long long unfiledBookmarksFolder; */
NS_IMETHODIMP nsNavBookmarksService::GetUnfiledBookmarksFolder(PRInt64 *aUnfiledBookmarksFolder)
{
    return NS_ERROR_NOT_IMPLEMENTED;
}

/* readonly attribute long long toolbarFolder; */
NS_IMETHODIMP nsNavBookmarksService::GetToolbarFolder(PRInt64 *aToolbarFolder)
{
    return NS_ERROR_NOT_IMPLEMENTED;
}

/* long long insertBookmark (in long long aParentFolder, in nsIURI aURI, in long aIndex, in AUTF8String aTitle); */
NS_IMETHODIMP nsNavBookmarksService::InsertBookmark(PRInt64 aParentFolder, nsIURI *aURI, PRInt32 aIndex, const nsACString & aTitle, PRInt64 *_retval NS_OUTPARAM)
{
    return NS_ERROR_NOT_IMPLEMENTED;
}

/* void removeItem (in long long aItemId); */
NS_IMETHODIMP nsNavBookmarksService::RemoveItem(PRInt64 aItemId)
{
    return NS_ERROR_NOT_IMPLEMENTED;
}

/* long long createFolder (in long long aParentFolder, in AUTF8String name, in long index); */
NS_IMETHODIMP nsNavBookmarksService::CreateFolder(PRInt64 aParentFolder, const nsACString & name, PRInt32 index, PRInt64 *_retval NS_OUTPARAM)
{
    return NS_ERROR_NOT_IMPLEMENTED;
}

/* long long createDynamicContainer (in long long aParentFolder, in AUTF8String aName, in AString aContractId, in long aIndex); */
NS_IMETHODIMP nsNavBookmarksService::CreateDynamicContainer(PRInt64 aParentFolder, const nsACString & aName, const nsAString & aContractId, PRInt32 aIndex, PRInt64 *_retval NS_OUTPARAM)
{
    return NS_ERROR_NOT_IMPLEMENTED;
}

/* void removeFolder (in long long aFolder); */
NS_IMETHODIMP nsNavBookmarksService::RemoveFolder(PRInt64 aFolder)
{
    return NS_ERROR_NOT_IMPLEMENTED;
}

/* nsITransaction getRemoveFolderTransaction (in long long aFolder); */
NS_IMETHODIMP nsNavBookmarksService::GetRemoveFolderTransaction(PRInt64 aFolder, nsITransaction **_retval NS_OUTPARAM)
{
    return NS_ERROR_NOT_IMPLEMENTED;
}

/* void removeFolderChildren (in long long aFolder); */
NS_IMETHODIMP nsNavBookmarksService::RemoveFolderChildren(PRInt64 aFolder)
{
    return NS_ERROR_NOT_IMPLEMENTED;
}

/* void moveItem (in long long aItemId, in long long aNewParent, in long aIndex); */
NS_IMETHODIMP nsNavBookmarksService::MoveItem(PRInt64 aItemId, PRInt64 aNewParent, PRInt32 aIndex)
{
    return NS_ERROR_NOT_IMPLEMENTED;
}

/* long long getChildFolder (in long long aFolder, in AString aSubFolder); */
NS_IMETHODIMP nsNavBookmarksService::GetChildFolder(PRInt64 aFolder, const nsAString & aSubFolder, PRInt64 *_retval NS_OUTPARAM)
{
    return NS_ERROR_NOT_IMPLEMENTED;
}

/* long long insertSeparator (in long long aFolder, in long aIndex); */
NS_IMETHODIMP nsNavBookmarksService::InsertSeparator(PRInt64 aFolder, PRInt32 aIndex, PRInt64 *_retval NS_OUTPARAM)
{
    return NS_ERROR_NOT_IMPLEMENTED;
}

/* void removeChildAt (in long long aFolder, in long aIndex); */
NS_IMETHODIMP nsNavBookmarksService::RemoveChildAt(PRInt64 aFolder, PRInt32 aIndex)
{
    return NS_ERROR_NOT_IMPLEMENTED;
}

/* long long getIdForItemAt (in long long aFolder, in long aIndex); */
NS_IMETHODIMP nsNavBookmarksService::GetIdForItemAt(PRInt64 aFolder, PRInt32 aIndex, PRInt64 *_retval NS_OUTPARAM)
{
    return NS_ERROR_NOT_IMPLEMENTED;
}

/* AString getItemGUID (in long long aItemId); */
NS_IMETHODIMP nsNavBookmarksService::GetItemGUID(PRInt64 aItemId, nsAString & _retval NS_OUTPARAM)
{
    return NS_ERROR_NOT_IMPLEMENTED;
}

/* void setItemGUID (in long long aItemId, in AString aGUID); */
NS_IMETHODIMP nsNavBookmarksService::SetItemGUID(PRInt64 aItemId, const nsAString & aGUID)
{
    return NS_ERROR_NOT_IMPLEMENTED;
}

/* long long getItemIdForGUID (in AString aGUID); */
NS_IMETHODIMP nsNavBookmarksService::GetItemIdForGUID(const nsAString & aGUID, PRInt64 *_retval NS_OUTPARAM)
{
    return NS_ERROR_NOT_IMPLEMENTED;
}

/* void setItemTitle (in long long aItemId, in AUTF8String aTitle); */
NS_IMETHODIMP nsNavBookmarksService::SetItemTitle(PRInt64 aItemId, const nsACString & aTitle)
{
    return NS_ERROR_NOT_IMPLEMENTED;
}

/* AUTF8String getItemTitle (in long long aItemId); */
NS_IMETHODIMP nsNavBookmarksService::GetItemTitle(PRInt64 aItemId, nsACString & _retval NS_OUTPARAM)
{
    return NS_ERROR_NOT_IMPLEMENTED;
}

/* void setItemDateAdded (in long long aItemId, in PRTime aDateAdded); */
NS_IMETHODIMP nsNavBookmarksService::SetItemDateAdded(PRInt64 aItemId, PRTime aDateAdded)
{
    return NS_ERROR_NOT_IMPLEMENTED;
}

/* PRTime getItemDateAdded (in long long aItemId); */
NS_IMETHODIMP nsNavBookmarksService::GetItemDateAdded(PRInt64 aItemId, PRTime *_retval NS_OUTPARAM)
{
    return NS_ERROR_NOT_IMPLEMENTED;
}

/* void setItemLastModified (in long long aItemId, in PRTime aLastModified); */
NS_IMETHODIMP nsNavBookmarksService::SetItemLastModified(PRInt64 aItemId, PRTime aLastModified)
{
    return NS_ERROR_NOT_IMPLEMENTED;
}

/* PRTime getItemLastModified (in long long aItemId); */
NS_IMETHODIMP nsNavBookmarksService::GetItemLastModified(PRInt64 aItemId, PRTime *_retval NS_OUTPARAM)
{
    return NS_ERROR_NOT_IMPLEMENTED;
}

/* nsIURI getBookmarkURI (in long long aItemId); */
NS_IMETHODIMP nsNavBookmarksService::GetBookmarkURI(PRInt64 aItemId, nsIURI **_retval NS_OUTPARAM)
{
    return NS_ERROR_NOT_IMPLEMENTED;
}

/* long getItemIndex (in long long aItemId); */
NS_IMETHODIMP nsNavBookmarksService::GetItemIndex(PRInt64 aItemId, PRInt32 *_retval NS_OUTPARAM)
{
    return NS_ERROR_NOT_IMPLEMENTED;
}

/* void setItemIndex (in long long aItemId, in long aNewIndex); */
NS_IMETHODIMP nsNavBookmarksService::SetItemIndex(PRInt64 aItemId, PRInt32 aNewIndex)
{
    return NS_ERROR_NOT_IMPLEMENTED;
}

/* unsigned short getItemType (in long long aItemId); */
NS_IMETHODIMP nsNavBookmarksService::GetItemType(PRInt64 aItemId, PRUint16 *_retval NS_OUTPARAM)
{
    return NS_ERROR_NOT_IMPLEMENTED;
}

/* boolean getFolderReadonly (in long long aFolder); */
NS_IMETHODIMP nsNavBookmarksService::GetFolderReadonly(PRInt64 aFolder, PRBool *_retval NS_OUTPARAM)
{
    return NS_ERROR_NOT_IMPLEMENTED;
}

/* void setFolderReadonly (in long long aFolder, in boolean aReadOnly); */
NS_IMETHODIMP nsNavBookmarksService::SetFolderReadonly(PRInt64 aFolder, PRBool aReadOnly)
{
    return NS_ERROR_NOT_IMPLEMENTED;
}

/* boolean isBookmarked (in nsIURI aURI); */
NS_IMETHODIMP nsNavBookmarksService::IsBookmarked(nsIURI *aURI, PRBool *_retval NS_OUTPARAM)
{
    return NS_ERROR_NOT_IMPLEMENTED;
}

/* nsIURI getBookmarkedURIFor (in nsIURI aURI); */
NS_IMETHODIMP nsNavBookmarksService::GetBookmarkedURIFor(nsIURI *aURI, nsIURI **_retval NS_OUTPARAM)
{
    return NS_ERROR_NOT_IMPLEMENTED;
}

/* void changeBookmarkURI (in long long aItemId, in nsIURI aNewURI); */
NS_IMETHODIMP nsNavBookmarksService::ChangeBookmarkURI(PRInt64 aItemId, nsIURI *aNewURI)
{
    return NS_ERROR_NOT_IMPLEMENTED;
}

/* long long getFolderIdForItem (in long long aItemId); */
NS_IMETHODIMP nsNavBookmarksService::GetFolderIdForItem(PRInt64 aItemId, PRInt64 *_retval NS_OUTPARAM)
{
    return NS_ERROR_NOT_IMPLEMENTED;
}

/* void getBookmarkIdsForURI (in nsIURI aURI, out unsigned long count, [array, size_is (count), retval] out long long bookmarks); */
NS_IMETHODIMP nsNavBookmarksService::GetBookmarkIdsForURI(nsIURI *aURI, PRUint32 *count NS_OUTPARAM, PRInt64 **bookmarks NS_OUTPARAM)
{
    return NS_ERROR_NOT_IMPLEMENTED;
}

/* [noscript] void getBookmarkIdsForURITArray (in nsIURI aURI, in PRInt64Array aResult); */
NS_IMETHODIMP nsNavBookmarksService::GetBookmarkIdsForURITArray(nsIURI *aURI, nsTArray<PRInt64> * aResult)
{
    return NS_ERROR_NOT_IMPLEMENTED;
}

/* void setKeywordForBookmark (in long long aItemId, in AString aKeyword); */
NS_IMETHODIMP nsNavBookmarksService::SetKeywordForBookmark(PRInt64 aItemId, const nsAString & aKeyword)
{
    return NS_ERROR_NOT_IMPLEMENTED;
}

/* AString getKeywordForURI (in nsIURI aURI); */
NS_IMETHODIMP nsNavBookmarksService::GetKeywordForURI(nsIURI *aURI, nsAString & _retval NS_OUTPARAM)
{
    return NS_ERROR_NOT_IMPLEMENTED;
}

/* AString getKeywordForBookmark (in long long aItemId); */
NS_IMETHODIMP nsNavBookmarksService::GetKeywordForBookmark(PRInt64 aItemId, nsAString & _retval NS_OUTPARAM)
{
    return NS_ERROR_NOT_IMPLEMENTED;
}

/* nsIURI getURIForKeyword (in AString keyword); */
NS_IMETHODIMP nsNavBookmarksService::GetURIForKeyword(const nsAString & keyword, nsIURI **_retval NS_OUTPARAM)
{
    return NS_ERROR_NOT_IMPLEMENTED;
}

/* void addObserver (in nsINavBookmarkObserver observer, in boolean ownsWeak); */
NS_IMETHODIMP nsNavBookmarksService::AddObserver(nsINavBookmarkObserver *observer, PRBool ownsWeak)
{
    return NS_ERROR_NOT_IMPLEMENTED;
}

/* void removeObserver (in nsINavBookmarkObserver observer); */
NS_IMETHODIMP nsNavBookmarksService::RemoveObserver(nsINavBookmarkObserver *observer)
{
    return NS_ERROR_NOT_IMPLEMENTED;
}

/* void runInBatchMode (in nsINavHistoryBatchCallback aCallback, in nsISupports aUserData); */
NS_IMETHODIMP nsNavBookmarksService::RunInBatchMode(nsINavHistoryBatchCallback *aCallback, nsISupports *aUserData)
{
    return NS_ERROR_NOT_IMPLEMENTED;
}

/* End of implementation class template. */
#endif


#endif /* __gen_nsINavBookmarksService_h__ */
