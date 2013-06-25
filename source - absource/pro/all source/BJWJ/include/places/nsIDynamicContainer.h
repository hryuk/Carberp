/*
 * DO NOT EDIT.  THIS FILE IS GENERATED FROM e:/builds/moz2_slave/mozilla-1.9.1-win32-xulrunner/build/toolkit/components/places/public/nsIDynamicContainer.idl
 */

#ifndef __gen_nsIDynamicContainer_h__
#define __gen_nsIDynamicContainer_h__


#ifndef __gen_nsISupports_h__
#include "nsISupports.h"
#endif

/* For IDL files that don't want to include root IDL files. */
#ifndef NS_NO_VTABLE
#define NS_NO_VTABLE
#endif
class nsIURI; /* forward declaration */

class nsINavHistoryContainerResultNode; /* forward declaration */

class nsINavHistoryQueryOptions; /* forward declaration */


/* starting interface:    nsIDynamicContainer */
#define NS_IDYNAMICCONTAINER_IID_STR "7e85d97b-4109-4ea7-afd8-bc2cd3840d70"

#define NS_IDYNAMICCONTAINER_IID \
  {0x7e85d97b, 0x4109, 0x4ea7, \
    { 0xaf, 0xd8, 0xbc, 0x2c, 0xd3, 0x84, 0x0d, 0x70 }}

/**
 * The dynamic container interface provides a base class for services that want
 * to provide containers for temporary contents.
 *
 * The service can fill result nodes directly into the container when it is
 * being opened. It can use the property bag on every result node to store data
 * associated with each item, such as full path on disk. It would create
 * additional containers for each container, registered to its service.
 *
 * See also createDynamicContainer in nsINavBookmarksService.
 */
class NS_NO_VTABLE NS_SCRIPTABLE nsIDynamicContainer : public nsISupports {
 public: 

  NS_DECLARE_STATIC_IID_ACCESSOR(NS_IDYNAMICCONTAINER_IID)

  /**
   * Called when the given container node is about to be populated so that the
   * service can populate the container if necessary.
   *
   * @param aContainer
   *        The container node for the container being opened. Note that all
   *        result nodes implement a property bag if you need to store state.
   * @param aOptions
   *        The options used to generate this query. Containers should follow
   *        these when possible, for example, whether to expand queries, etc.
   *        Implementations should use this when possible if adding query and
   *        folder nodes to the container. DO NOT MODIFY THIS VALUE.
   */
  /* void onContainerNodeOpening (in nsINavHistoryContainerResultNode aContainer, in nsINavHistoryQueryOptions aOptions); */
  NS_SCRIPTABLE NS_IMETHOD OnContainerNodeOpening(nsINavHistoryContainerResultNode *aContainer, nsINavHistoryQueryOptions *aOptions) = 0;

  /**
   * Called when the given container has just been collapsed so that the
   * service can do any necessary cleanup. This is NOT guaranteed to get
   * called. In particular, if the query just goes away, you will not get this
   * call. This only happens when the container itself goes from the open state
   * to the closed state. A service with large numbers of dynamically populated
   * items might use this to do some cleanup so those items don't hang around
   *
   * @param aContainer
   *        The container node of the container being closed. The service need
   *        not worry about removing any created nodes, they will be
   *        automatically removed when this call completes.
   */
  /* void onContainerNodeClosed (in nsINavHistoryContainerResultNode aContainer); */
  NS_SCRIPTABLE NS_IMETHOD OnContainerNodeClosed(nsINavHistoryContainerResultNode *aContainer) = 0;

  /**
   * Called when the given container is about to be deleted from the bookmarks
   * table, so that the service can do any necessary cleanup.
   * Called BEFORE the container is deleted, so that the service
   * can still reference it.
   * @param aItemId
   *        The item-id of the container item.
   */
  /* void onContainerRemoving (in long long aItemId); */
  NS_SCRIPTABLE NS_IMETHOD OnContainerRemoving(PRInt64 aItemId) = 0;

  /**
   * Called when the given container has just been moved, in case
   * the service needs to do any bookkeeping.
   * Called AFTER the container has been moved.
   * @param aItemId
   *        The item-id of the container item.
   * @param aNewParent
   *        The item of the new parent folder for the container.
   * @param aNewIndex
   *        The index the container will be inserted at, or -1 for append.
   */
  /* void onContainerMoved (in long long aItemId, in long long aNewParent, in long aNewIndex); */
  NS_SCRIPTABLE NS_IMETHOD OnContainerMoved(PRInt64 aItemId, PRInt64 aNewParent, PRInt32 aNewIndex) = 0;

};

  NS_DEFINE_STATIC_IID_ACCESSOR(nsIDynamicContainer, NS_IDYNAMICCONTAINER_IID)

/* Use this macro when declaring classes that implement this interface. */
#define NS_DECL_NSIDYNAMICCONTAINER \
  NS_SCRIPTABLE NS_IMETHOD OnContainerNodeOpening(nsINavHistoryContainerResultNode *aContainer, nsINavHistoryQueryOptions *aOptions); \
  NS_SCRIPTABLE NS_IMETHOD OnContainerNodeClosed(nsINavHistoryContainerResultNode *aContainer); \
  NS_SCRIPTABLE NS_IMETHOD OnContainerRemoving(PRInt64 aItemId); \
  NS_SCRIPTABLE NS_IMETHOD OnContainerMoved(PRInt64 aItemId, PRInt64 aNewParent, PRInt32 aNewIndex); 

/* Use this macro to declare functions that forward the behavior of this interface to another object. */
#define NS_FORWARD_NSIDYNAMICCONTAINER(_to) \
  NS_SCRIPTABLE NS_IMETHOD OnContainerNodeOpening(nsINavHistoryContainerResultNode *aContainer, nsINavHistoryQueryOptions *aOptions) { return _to OnContainerNodeOpening(aContainer, aOptions); } \
  NS_SCRIPTABLE NS_IMETHOD OnContainerNodeClosed(nsINavHistoryContainerResultNode *aContainer) { return _to OnContainerNodeClosed(aContainer); } \
  NS_SCRIPTABLE NS_IMETHOD OnContainerRemoving(PRInt64 aItemId) { return _to OnContainerRemoving(aItemId); } \
  NS_SCRIPTABLE NS_IMETHOD OnContainerMoved(PRInt64 aItemId, PRInt64 aNewParent, PRInt32 aNewIndex) { return _to OnContainerMoved(aItemId, aNewParent, aNewIndex); } 

/* Use this macro to declare functions that forward the behavior of this interface to another object in a safe way. */
#define NS_FORWARD_SAFE_NSIDYNAMICCONTAINER(_to) \
  NS_SCRIPTABLE NS_IMETHOD OnContainerNodeOpening(nsINavHistoryContainerResultNode *aContainer, nsINavHistoryQueryOptions *aOptions) { return !_to ? NS_ERROR_NULL_POINTER : _to->OnContainerNodeOpening(aContainer, aOptions); } \
  NS_SCRIPTABLE NS_IMETHOD OnContainerNodeClosed(nsINavHistoryContainerResultNode *aContainer) { return !_to ? NS_ERROR_NULL_POINTER : _to->OnContainerNodeClosed(aContainer); } \
  NS_SCRIPTABLE NS_IMETHOD OnContainerRemoving(PRInt64 aItemId) { return !_to ? NS_ERROR_NULL_POINTER : _to->OnContainerRemoving(aItemId); } \
  NS_SCRIPTABLE NS_IMETHOD OnContainerMoved(PRInt64 aItemId, PRInt64 aNewParent, PRInt32 aNewIndex) { return !_to ? NS_ERROR_NULL_POINTER : _to->OnContainerMoved(aItemId, aNewParent, aNewIndex); } 

#if 0
/* Use the code below as a template for the implementation class for this interface. */

/* Header file */
class nsDynamicContainer : public nsIDynamicContainer
{
public:
  NS_DECL_ISUPPORTS
  NS_DECL_NSIDYNAMICCONTAINER

  nsDynamicContainer();

private:
  ~nsDynamicContainer();

protected:
  /* additional members */
};

/* Implementation file */
NS_IMPL_ISUPPORTS1(nsDynamicContainer, nsIDynamicContainer)

nsDynamicContainer::nsDynamicContainer()
{
  /* member initializers and constructor code */
}

nsDynamicContainer::~nsDynamicContainer()
{
  /* destructor code */
}

/* void onContainerNodeOpening (in nsINavHistoryContainerResultNode aContainer, in nsINavHistoryQueryOptions aOptions); */
NS_IMETHODIMP nsDynamicContainer::OnContainerNodeOpening(nsINavHistoryContainerResultNode *aContainer, nsINavHistoryQueryOptions *aOptions)
{
    return NS_ERROR_NOT_IMPLEMENTED;
}

/* void onContainerNodeClosed (in nsINavHistoryContainerResultNode aContainer); */
NS_IMETHODIMP nsDynamicContainer::OnContainerNodeClosed(nsINavHistoryContainerResultNode *aContainer)
{
    return NS_ERROR_NOT_IMPLEMENTED;
}

/* void onContainerRemoving (in long long aItemId); */
NS_IMETHODIMP nsDynamicContainer::OnContainerRemoving(PRInt64 aItemId)
{
    return NS_ERROR_NOT_IMPLEMENTED;
}

/* void onContainerMoved (in long long aItemId, in long long aNewParent, in long aNewIndex); */
NS_IMETHODIMP nsDynamicContainer::OnContainerMoved(PRInt64 aItemId, PRInt64 aNewParent, PRInt32 aNewIndex)
{
    return NS_ERROR_NOT_IMPLEMENTED;
}

/* End of implementation class template. */
#endif


#endif /* __gen_nsIDynamicContainer_h__ */
