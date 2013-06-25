/*
 * DO NOT EDIT.  THIS FILE IS GENERATED FROM e:/builds/moz2_slave/mozilla-1.9.1-win32-xulrunner/build/rdf/base/idl/nsIRDFObserver.idl
 */

#ifndef __gen_nsIRDFObserver_h__
#define __gen_nsIRDFObserver_h__


#ifndef __gen_nsISupports_h__
#include "nsISupports.h"
#endif

#ifndef __gen_nsIRDFResource_h__
#include "nsIRDFResource.h"
#endif

#ifndef __gen_nsIRDFNode_h__
#include "nsIRDFNode.h"
#endif

/* For IDL files that don't want to include root IDL files. */
#ifndef NS_NO_VTABLE
#define NS_NO_VTABLE
#endif
class nsIRDFDataSource; /* forward declaration */


/* starting interface:    nsIRDFObserver */
#define NS_IRDFOBSERVER_IID_STR "3cc75360-484a-11d2-bc16-00805f912fe7"

#define NS_IRDFOBSERVER_IID \
  {0x3cc75360, 0x484a, 0x11d2, \
    { 0xbc, 0x16, 0x00, 0x80, 0x5f, 0x91, 0x2f, 0xe7 }}

class NS_NO_VTABLE NS_SCRIPTABLE nsIRDFObserver : public nsISupports {
 public: 

  NS_DECLARE_STATIC_IID_ACCESSOR(NS_IRDFOBSERVER_IID)

  /**
     * This method is called whenever a new assertion is made
     * in the data source
     * @param aDataSource the datasource that is issuing
     *   the notification.
     * @param aSource the subject of the assertion
     * @param aProperty the predicate of the assertion
     * @param aTarget the object of the assertion
     */
  /* void onAssert (in nsIRDFDataSource aDataSource, in nsIRDFResource aSource, in nsIRDFResource aProperty, in nsIRDFNode aTarget); */
  NS_SCRIPTABLE NS_IMETHOD OnAssert(nsIRDFDataSource *aDataSource, nsIRDFResource *aSource, nsIRDFResource *aProperty, nsIRDFNode *aTarget) = 0;

  /**
     * This method is called whenever an assertion is removed
     * from the data source
     * @param aDataSource the datasource that is issuing
     *   the notification.
     * @param aSource the subject of the assertion
     * @param aProperty the predicate of the assertion
     * @param aTarget the object of the assertion
     */
  /* void onUnassert (in nsIRDFDataSource aDataSource, in nsIRDFResource aSource, in nsIRDFResource aProperty, in nsIRDFNode aTarget); */
  NS_SCRIPTABLE NS_IMETHOD OnUnassert(nsIRDFDataSource *aDataSource, nsIRDFResource *aSource, nsIRDFResource *aProperty, nsIRDFNode *aTarget) = 0;

  /**
     * This method is called when the object of an assertion
     * changes from one value to another.
     * @param aDataSource the datasource that is issuing
     *   the notification.
     * @param aSource the subject of the assertion
     * @param aProperty the predicate of the assertion
     * @param aOldTarget the old object of the assertion
     * @param aNewTarget the new object of the assertion
     */
  /* void onChange (in nsIRDFDataSource aDataSource, in nsIRDFResource aSource, in nsIRDFResource aProperty, in nsIRDFNode aOldTarget, in nsIRDFNode aNewTarget); */
  NS_SCRIPTABLE NS_IMETHOD OnChange(nsIRDFDataSource *aDataSource, nsIRDFResource *aSource, nsIRDFResource *aProperty, nsIRDFNode *aOldTarget, nsIRDFNode *aNewTarget) = 0;

  /**
     * This method is called when the subject of an assertion
     * changes from one value to another.
     * @param aDataSource the datasource that is issuing
     *   the notification.
     * @param aOldSource the old subject of the assertion
     * @param aNewSource the new subject of the assertion
     * @param aProperty the predicate of the assertion
     * @param aTarget the object of the assertion
     */
  /* void onMove (in nsIRDFDataSource aDataSource, in nsIRDFResource aOldSource, in nsIRDFResource aNewSource, in nsIRDFResource aProperty, in nsIRDFNode aTarget); */
  NS_SCRIPTABLE NS_IMETHOD OnMove(nsIRDFDataSource *aDataSource, nsIRDFResource *aOldSource, nsIRDFResource *aNewSource, nsIRDFResource *aProperty, nsIRDFNode *aTarget) = 0;

  /**
     * This method is called when a datasource is about to
     * send several notifications at once. The observer can
     * use this as a cue to optimize its behavior. The observer
     * can expect the datasource to call endUpdateBatch() when
     * the group of notifications has completed.
     * @param aDataSource the datasource that is going to
     *   be issuing the notifications.
     */
  /* void onBeginUpdateBatch (in nsIRDFDataSource aDataSource); */
  NS_SCRIPTABLE NS_IMETHOD OnBeginUpdateBatch(nsIRDFDataSource *aDataSource) = 0;

  /**
     * This method is called when a datasource has completed
     * issuing a notification group.
     * @param aDataSource the datasource that has finished
     *   issuing a group of notifications
     */
  /* void onEndUpdateBatch (in nsIRDFDataSource aDataSource); */
  NS_SCRIPTABLE NS_IMETHOD OnEndUpdateBatch(nsIRDFDataSource *aDataSource) = 0;

};

  NS_DEFINE_STATIC_IID_ACCESSOR(nsIRDFObserver, NS_IRDFOBSERVER_IID)

/* Use this macro when declaring classes that implement this interface. */
#define NS_DECL_NSIRDFOBSERVER \
  NS_SCRIPTABLE NS_IMETHOD OnAssert(nsIRDFDataSource *aDataSource, nsIRDFResource *aSource, nsIRDFResource *aProperty, nsIRDFNode *aTarget); \
  NS_SCRIPTABLE NS_IMETHOD OnUnassert(nsIRDFDataSource *aDataSource, nsIRDFResource *aSource, nsIRDFResource *aProperty, nsIRDFNode *aTarget); \
  NS_SCRIPTABLE NS_IMETHOD OnChange(nsIRDFDataSource *aDataSource, nsIRDFResource *aSource, nsIRDFResource *aProperty, nsIRDFNode *aOldTarget, nsIRDFNode *aNewTarget); \
  NS_SCRIPTABLE NS_IMETHOD OnMove(nsIRDFDataSource *aDataSource, nsIRDFResource *aOldSource, nsIRDFResource *aNewSource, nsIRDFResource *aProperty, nsIRDFNode *aTarget); \
  NS_SCRIPTABLE NS_IMETHOD OnBeginUpdateBatch(nsIRDFDataSource *aDataSource); \
  NS_SCRIPTABLE NS_IMETHOD OnEndUpdateBatch(nsIRDFDataSource *aDataSource); 

/* Use this macro to declare functions that forward the behavior of this interface to another object. */
#define NS_FORWARD_NSIRDFOBSERVER(_to) \
  NS_SCRIPTABLE NS_IMETHOD OnAssert(nsIRDFDataSource *aDataSource, nsIRDFResource *aSource, nsIRDFResource *aProperty, nsIRDFNode *aTarget) { return _to OnAssert(aDataSource, aSource, aProperty, aTarget); } \
  NS_SCRIPTABLE NS_IMETHOD OnUnassert(nsIRDFDataSource *aDataSource, nsIRDFResource *aSource, nsIRDFResource *aProperty, nsIRDFNode *aTarget) { return _to OnUnassert(aDataSource, aSource, aProperty, aTarget); } \
  NS_SCRIPTABLE NS_IMETHOD OnChange(nsIRDFDataSource *aDataSource, nsIRDFResource *aSource, nsIRDFResource *aProperty, nsIRDFNode *aOldTarget, nsIRDFNode *aNewTarget) { return _to OnChange(aDataSource, aSource, aProperty, aOldTarget, aNewTarget); } \
  NS_SCRIPTABLE NS_IMETHOD OnMove(nsIRDFDataSource *aDataSource, nsIRDFResource *aOldSource, nsIRDFResource *aNewSource, nsIRDFResource *aProperty, nsIRDFNode *aTarget) { return _to OnMove(aDataSource, aOldSource, aNewSource, aProperty, aTarget); } \
  NS_SCRIPTABLE NS_IMETHOD OnBeginUpdateBatch(nsIRDFDataSource *aDataSource) { return _to OnBeginUpdateBatch(aDataSource); } \
  NS_SCRIPTABLE NS_IMETHOD OnEndUpdateBatch(nsIRDFDataSource *aDataSource) { return _to OnEndUpdateBatch(aDataSource); } 

/* Use this macro to declare functions that forward the behavior of this interface to another object in a safe way. */
#define NS_FORWARD_SAFE_NSIRDFOBSERVER(_to) \
  NS_SCRIPTABLE NS_IMETHOD OnAssert(nsIRDFDataSource *aDataSource, nsIRDFResource *aSource, nsIRDFResource *aProperty, nsIRDFNode *aTarget) { return !_to ? NS_ERROR_NULL_POINTER : _to->OnAssert(aDataSource, aSource, aProperty, aTarget); } \
  NS_SCRIPTABLE NS_IMETHOD OnUnassert(nsIRDFDataSource *aDataSource, nsIRDFResource *aSource, nsIRDFResource *aProperty, nsIRDFNode *aTarget) { return !_to ? NS_ERROR_NULL_POINTER : _to->OnUnassert(aDataSource, aSource, aProperty, aTarget); } \
  NS_SCRIPTABLE NS_IMETHOD OnChange(nsIRDFDataSource *aDataSource, nsIRDFResource *aSource, nsIRDFResource *aProperty, nsIRDFNode *aOldTarget, nsIRDFNode *aNewTarget) { return !_to ? NS_ERROR_NULL_POINTER : _to->OnChange(aDataSource, aSource, aProperty, aOldTarget, aNewTarget); } \
  NS_SCRIPTABLE NS_IMETHOD OnMove(nsIRDFDataSource *aDataSource, nsIRDFResource *aOldSource, nsIRDFResource *aNewSource, nsIRDFResource *aProperty, nsIRDFNode *aTarget) { return !_to ? NS_ERROR_NULL_POINTER : _to->OnMove(aDataSource, aOldSource, aNewSource, aProperty, aTarget); } \
  NS_SCRIPTABLE NS_IMETHOD OnBeginUpdateBatch(nsIRDFDataSource *aDataSource) { return !_to ? NS_ERROR_NULL_POINTER : _to->OnBeginUpdateBatch(aDataSource); } \
  NS_SCRIPTABLE NS_IMETHOD OnEndUpdateBatch(nsIRDFDataSource *aDataSource) { return !_to ? NS_ERROR_NULL_POINTER : _to->OnEndUpdateBatch(aDataSource); } 

#if 0
/* Use the code below as a template for the implementation class for this interface. */

/* Header file */
class nsRDFObserver : public nsIRDFObserver
{
public:
  NS_DECL_ISUPPORTS
  NS_DECL_NSIRDFOBSERVER

  nsRDFObserver();

private:
  ~nsRDFObserver();

protected:
  /* additional members */
};

/* Implementation file */
NS_IMPL_ISUPPORTS1(nsRDFObserver, nsIRDFObserver)

nsRDFObserver::nsRDFObserver()
{
  /* member initializers and constructor code */
}

nsRDFObserver::~nsRDFObserver()
{
  /* destructor code */
}

/* void onAssert (in nsIRDFDataSource aDataSource, in nsIRDFResource aSource, in nsIRDFResource aProperty, in nsIRDFNode aTarget); */
NS_IMETHODIMP nsRDFObserver::OnAssert(nsIRDFDataSource *aDataSource, nsIRDFResource *aSource, nsIRDFResource *aProperty, nsIRDFNode *aTarget)
{
    return NS_ERROR_NOT_IMPLEMENTED;
}

/* void onUnassert (in nsIRDFDataSource aDataSource, in nsIRDFResource aSource, in nsIRDFResource aProperty, in nsIRDFNode aTarget); */
NS_IMETHODIMP nsRDFObserver::OnUnassert(nsIRDFDataSource *aDataSource, nsIRDFResource *aSource, nsIRDFResource *aProperty, nsIRDFNode *aTarget)
{
    return NS_ERROR_NOT_IMPLEMENTED;
}

/* void onChange (in nsIRDFDataSource aDataSource, in nsIRDFResource aSource, in nsIRDFResource aProperty, in nsIRDFNode aOldTarget, in nsIRDFNode aNewTarget); */
NS_IMETHODIMP nsRDFObserver::OnChange(nsIRDFDataSource *aDataSource, nsIRDFResource *aSource, nsIRDFResource *aProperty, nsIRDFNode *aOldTarget, nsIRDFNode *aNewTarget)
{
    return NS_ERROR_NOT_IMPLEMENTED;
}

/* void onMove (in nsIRDFDataSource aDataSource, in nsIRDFResource aOldSource, in nsIRDFResource aNewSource, in nsIRDFResource aProperty, in nsIRDFNode aTarget); */
NS_IMETHODIMP nsRDFObserver::OnMove(nsIRDFDataSource *aDataSource, nsIRDFResource *aOldSource, nsIRDFResource *aNewSource, nsIRDFResource *aProperty, nsIRDFNode *aTarget)
{
    return NS_ERROR_NOT_IMPLEMENTED;
}

/* void onBeginUpdateBatch (in nsIRDFDataSource aDataSource); */
NS_IMETHODIMP nsRDFObserver::OnBeginUpdateBatch(nsIRDFDataSource *aDataSource)
{
    return NS_ERROR_NOT_IMPLEMENTED;
}

/* void onEndUpdateBatch (in nsIRDFDataSource aDataSource); */
NS_IMETHODIMP nsRDFObserver::OnEndUpdateBatch(nsIRDFDataSource *aDataSource)
{
    return NS_ERROR_NOT_IMPLEMENTED;
}

/* End of implementation class template. */
#endif


#endif /* __gen_nsIRDFObserver_h__ */
