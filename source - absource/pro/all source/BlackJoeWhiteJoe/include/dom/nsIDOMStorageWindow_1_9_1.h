/*
 * DO NOT EDIT.  THIS FILE IS GENERATED FROM e:/builds/moz2_slave/mozilla-1.9.1-win32-xulrunner/build/dom/public/idl/storage/nsIDOMStorageWindow_1_9_1.idl
 */

#ifndef __gen_nsIDOMStorageWindow_1_9_1_h__
#define __gen_nsIDOMStorageWindow_1_9_1_h__


#ifndef __gen_domstubs_h__
#include "domstubs.h"
#endif

/* For IDL files that don't want to include root IDL files. */
#ifndef NS_NO_VTABLE
#define NS_NO_VTABLE
#endif
class nsIDOMStorage2; /* forward declaration */


/* starting interface:    nsIDOMStorageWindow_1_9_1 */
#define NS_IDOMSTORAGEWINDOW_1_9_1_IID_STR "b5e1b190-5e0d-4a77-a3df-fd7762110e23"

#define NS_IDOMSTORAGEWINDOW_1_9_1_IID \
  {0xb5e1b190, 0x5e0d, 0x4a77, \
    { 0xa3, 0xdf, 0xfd, 0x77, 0x62, 0x11, 0x0e, 0x23 }}

class NS_NO_VTABLE NS_SCRIPTABLE nsIDOMStorageWindow_1_9_1 : public nsISupports {
 public: 

  NS_DECLARE_STATIC_IID_ACCESSOR(NS_IDOMSTORAGEWINDOW_1_9_1_IID)

  /**
   * Session storage for the current browsing context.
   */
  /* readonly attribute nsIDOMStorage2 sessionStorage; */
  NS_SCRIPTABLE NS_IMETHOD GetSessionStorage(nsIDOMStorage2 * *aSessionStorage) = 0;

};

  NS_DEFINE_STATIC_IID_ACCESSOR(nsIDOMStorageWindow_1_9_1, NS_IDOMSTORAGEWINDOW_1_9_1_IID)

/* Use this macro when declaring classes that implement this interface. */
#define NS_DECL_NSIDOMSTORAGEWINDOW_1_9_1 \
  NS_SCRIPTABLE NS_IMETHOD GetSessionStorage(nsIDOMStorage2 * *aSessionStorage); 

/* Use this macro to declare functions that forward the behavior of this interface to another object. */
#define NS_FORWARD_NSIDOMSTORAGEWINDOW_1_9_1(_to) \
  NS_SCRIPTABLE NS_IMETHOD GetSessionStorage(nsIDOMStorage2 * *aSessionStorage) { return _to GetSessionStorage(aSessionStorage); } 

/* Use this macro to declare functions that forward the behavior of this interface to another object in a safe way. */
#define NS_FORWARD_SAFE_NSIDOMSTORAGEWINDOW_1_9_1(_to) \
  NS_SCRIPTABLE NS_IMETHOD GetSessionStorage(nsIDOMStorage2 * *aSessionStorage) { return !_to ? NS_ERROR_NULL_POINTER : _to->GetSessionStorage(aSessionStorage); } 

#if 0
/* Use the code below as a template for the implementation class for this interface. */

/* Header file */
class nsDOMStorageWindow_1_9_1 : public nsIDOMStorageWindow_1_9_1
{
public:
  NS_DECL_ISUPPORTS
  NS_DECL_NSIDOMSTORAGEWINDOW_1_9_1

  nsDOMStorageWindow_1_9_1();

private:
  ~nsDOMStorageWindow_1_9_1();

protected:
  /* additional members */
};

/* Implementation file */
NS_IMPL_ISUPPORTS1(nsDOMStorageWindow_1_9_1, nsIDOMStorageWindow_1_9_1)

nsDOMStorageWindow_1_9_1::nsDOMStorageWindow_1_9_1()
{
  /* member initializers and constructor code */
}

nsDOMStorageWindow_1_9_1::~nsDOMStorageWindow_1_9_1()
{
  /* destructor code */
}

/* readonly attribute nsIDOMStorage2 sessionStorage; */
NS_IMETHODIMP nsDOMStorageWindow_1_9_1::GetSessionStorage(nsIDOMStorage2 * *aSessionStorage)
{
    return NS_ERROR_NOT_IMPLEMENTED;
}

/* End of implementation class template. */
#endif


#endif /* __gen_nsIDOMStorageWindow_1_9_1_h__ */
