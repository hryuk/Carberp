/*
 * DO NOT EDIT.  THIS FILE IS GENERATED FROM e:/builds/moz2_slave/mozilla-1.9.1-win32-xulrunner/build/rdf/base/idl/nsIRDFPropagatableDataSource.idl
 */

#ifndef __gen_nsIRDFPropagatableDataSource_h__
#define __gen_nsIRDFPropagatableDataSource_h__


#ifndef __gen_nsISupports_h__
#include "nsISupports.h"
#endif

/* For IDL files that don't want to include root IDL files. */
#ifndef NS_NO_VTABLE
#define NS_NO_VTABLE
#endif

/* starting interface:    nsIRDFPropagatableDataSource */
#define NS_IRDFPROPAGATABLEDATASOURCE_IID_STR "5a9b4770-9fcb-4307-a12e-4b6708e78b97"

#define NS_IRDFPROPAGATABLEDATASOURCE_IID \
  {0x5a9b4770, 0x9fcb, 0x4307, \
    { 0xa1, 0x2e, 0x4b, 0x67, 0x08, 0xe7, 0x8b, 0x97 }}

/**
 * An nsIRDFPropagatableDataSource provides an ability to suppress
 * synchronization notifications.
 */
class NS_NO_VTABLE NS_SCRIPTABLE nsIRDFPropagatableDataSource : public nsISupports {
 public: 

  NS_DECLARE_STATIC_IID_ACCESSOR(NS_IRDFPROPAGATABLEDATASOURCE_IID)

  /**
   * Set this value to <code>true</code> to enable synchronization
   * notifications.
   *
   * Set this value to <code>false</code> to disable synchronization
   * notifications.
   *
   * By default, this value is <code>true</code>.
   */
  /* attribute boolean propagateChanges; */
  NS_SCRIPTABLE NS_IMETHOD GetPropagateChanges(PRBool *aPropagateChanges) = 0;
  NS_SCRIPTABLE NS_IMETHOD SetPropagateChanges(PRBool aPropagateChanges) = 0;

};

  NS_DEFINE_STATIC_IID_ACCESSOR(nsIRDFPropagatableDataSource, NS_IRDFPROPAGATABLEDATASOURCE_IID)

/* Use this macro when declaring classes that implement this interface. */
#define NS_DECL_NSIRDFPROPAGATABLEDATASOURCE \
  NS_SCRIPTABLE NS_IMETHOD GetPropagateChanges(PRBool *aPropagateChanges); \
  NS_SCRIPTABLE NS_IMETHOD SetPropagateChanges(PRBool aPropagateChanges); 

/* Use this macro to declare functions that forward the behavior of this interface to another object. */
#define NS_FORWARD_NSIRDFPROPAGATABLEDATASOURCE(_to) \
  NS_SCRIPTABLE NS_IMETHOD GetPropagateChanges(PRBool *aPropagateChanges) { return _to GetPropagateChanges(aPropagateChanges); } \
  NS_SCRIPTABLE NS_IMETHOD SetPropagateChanges(PRBool aPropagateChanges) { return _to SetPropagateChanges(aPropagateChanges); } 

/* Use this macro to declare functions that forward the behavior of this interface to another object in a safe way. */
#define NS_FORWARD_SAFE_NSIRDFPROPAGATABLEDATASOURCE(_to) \
  NS_SCRIPTABLE NS_IMETHOD GetPropagateChanges(PRBool *aPropagateChanges) { return !_to ? NS_ERROR_NULL_POINTER : _to->GetPropagateChanges(aPropagateChanges); } \
  NS_SCRIPTABLE NS_IMETHOD SetPropagateChanges(PRBool aPropagateChanges) { return !_to ? NS_ERROR_NULL_POINTER : _to->SetPropagateChanges(aPropagateChanges); } 

#if 0
/* Use the code below as a template for the implementation class for this interface. */

/* Header file */
class nsRDFPropagatableDataSource : public nsIRDFPropagatableDataSource
{
public:
  NS_DECL_ISUPPORTS
  NS_DECL_NSIRDFPROPAGATABLEDATASOURCE

  nsRDFPropagatableDataSource();

private:
  ~nsRDFPropagatableDataSource();

protected:
  /* additional members */
};

/* Implementation file */
NS_IMPL_ISUPPORTS1(nsRDFPropagatableDataSource, nsIRDFPropagatableDataSource)

nsRDFPropagatableDataSource::nsRDFPropagatableDataSource()
{
  /* member initializers and constructor code */
}

nsRDFPropagatableDataSource::~nsRDFPropagatableDataSource()
{
  /* destructor code */
}

/* attribute boolean propagateChanges; */
NS_IMETHODIMP nsRDFPropagatableDataSource::GetPropagateChanges(PRBool *aPropagateChanges)
{
    return NS_ERROR_NOT_IMPLEMENTED;
}
NS_IMETHODIMP nsRDFPropagatableDataSource::SetPropagateChanges(PRBool aPropagateChanges)
{
    return NS_ERROR_NOT_IMPLEMENTED;
}

/* End of implementation class template. */
#endif


#endif /* __gen_nsIRDFPropagatableDataSource_h__ */
