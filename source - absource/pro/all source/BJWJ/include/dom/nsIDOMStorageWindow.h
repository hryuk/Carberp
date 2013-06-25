/*
 * DO NOT EDIT.  THIS FILE IS GENERATED FROM e:/builds/moz2_slave/mozilla-1.9.1-win32-xulrunner/build/dom/public/idl/storage/nsIDOMStorageWindow.idl
 */

#ifndef __gen_nsIDOMStorageWindow_h__
#define __gen_nsIDOMStorageWindow_h__


#ifndef __gen_domstubs_h__
#include "domstubs.h"
#endif

/* For IDL files that don't want to include root IDL files. */
#ifndef NS_NO_VTABLE
#define NS_NO_VTABLE
#endif
class nsIDOMStorage; /* forward declaration */

class nsIDOMStorage2; /* forward declaration */

class nsIDOMStorageList; /* forward declaration */


/* starting interface:    nsIDOMStorageWindow */
#define NS_IDOMSTORAGEWINDOW_IID_STR "b4f572fb-9ba5-480b-9361-c230863323e4"

#define NS_IDOMSTORAGEWINDOW_IID \
  {0xb4f572fb, 0x9ba5, 0x480b, \
    { 0x93, 0x61, 0xc2, 0x30, 0x86, 0x33, 0x23, 0xe4 }}

class NS_NO_VTABLE NS_SCRIPTABLE nsIDOMStorageWindow : public nsISupports {
 public: 

  NS_DECLARE_STATIC_IID_ACCESSOR(NS_IDOMSTORAGEWINDOW_IID)

  /**
   * Session storage for the current browsing context.
   */
  /* readonly attribute nsIDOMStorage sessionStorage; */
  NS_SCRIPTABLE NS_IMETHOD GetSessionStorage(nsIDOMStorage * *aSessionStorage) = 0;

  /**
   * Global storage, accessible by domain.
   */
  /* readonly attribute nsIDOMStorageList globalStorage; */
  NS_SCRIPTABLE NS_IMETHOD GetGlobalStorage(nsIDOMStorageList * *aGlobalStorage) = 0;

  /**
   * Local storage for the current browsing context.
   */
  /* readonly attribute nsIDOMStorage2 localStorage; */
  NS_SCRIPTABLE NS_IMETHOD GetLocalStorage(nsIDOMStorage2 * *aLocalStorage) = 0;

};

  NS_DEFINE_STATIC_IID_ACCESSOR(nsIDOMStorageWindow, NS_IDOMSTORAGEWINDOW_IID)

/* Use this macro when declaring classes that implement this interface. */
#define NS_DECL_NSIDOMSTORAGEWINDOW \
  NS_SCRIPTABLE NS_IMETHOD GetSessionStorage(nsIDOMStorage * *aSessionStorage); \
  NS_SCRIPTABLE NS_IMETHOD GetGlobalStorage(nsIDOMStorageList * *aGlobalStorage); \
  NS_SCRIPTABLE NS_IMETHOD GetLocalStorage(nsIDOMStorage2 * *aLocalStorage); 

/* Use this macro to declare functions that forward the behavior of this interface to another object. */
#define NS_FORWARD_NSIDOMSTORAGEWINDOW(_to) \
  NS_SCRIPTABLE NS_IMETHOD GetSessionStorage(nsIDOMStorage * *aSessionStorage) { return _to GetSessionStorage(aSessionStorage); } \
  NS_SCRIPTABLE NS_IMETHOD GetGlobalStorage(nsIDOMStorageList * *aGlobalStorage) { return _to GetGlobalStorage(aGlobalStorage); } \
  NS_SCRIPTABLE NS_IMETHOD GetLocalStorage(nsIDOMStorage2 * *aLocalStorage) { return _to GetLocalStorage(aLocalStorage); } 

/* Use this macro to declare functions that forward the behavior of this interface to another object in a safe way. */
#define NS_FORWARD_SAFE_NSIDOMSTORAGEWINDOW(_to) \
  NS_SCRIPTABLE NS_IMETHOD GetSessionStorage(nsIDOMStorage * *aSessionStorage) { return !_to ? NS_ERROR_NULL_POINTER : _to->GetSessionStorage(aSessionStorage); } \
  NS_SCRIPTABLE NS_IMETHOD GetGlobalStorage(nsIDOMStorageList * *aGlobalStorage) { return !_to ? NS_ERROR_NULL_POINTER : _to->GetGlobalStorage(aGlobalStorage); } \
  NS_SCRIPTABLE NS_IMETHOD GetLocalStorage(nsIDOMStorage2 * *aLocalStorage) { return !_to ? NS_ERROR_NULL_POINTER : _to->GetLocalStorage(aLocalStorage); } 

#if 0
/* Use the code below as a template for the implementation class for this interface. */

/* Header file */
class nsDOMStorageWindow : public nsIDOMStorageWindow
{
public:
  NS_DECL_ISUPPORTS
  NS_DECL_NSIDOMSTORAGEWINDOW

  nsDOMStorageWindow();

private:
  ~nsDOMStorageWindow();

protected:
  /* additional members */
};

/* Implementation file */
NS_IMPL_ISUPPORTS1(nsDOMStorageWindow, nsIDOMStorageWindow)

nsDOMStorageWindow::nsDOMStorageWindow()
{
  /* member initializers and constructor code */
}

nsDOMStorageWindow::~nsDOMStorageWindow()
{
  /* destructor code */
}

/* readonly attribute nsIDOMStorage sessionStorage; */
NS_IMETHODIMP nsDOMStorageWindow::GetSessionStorage(nsIDOMStorage * *aSessionStorage)
{
    return NS_ERROR_NOT_IMPLEMENTED;
}

/* readonly attribute nsIDOMStorageList globalStorage; */
NS_IMETHODIMP nsDOMStorageWindow::GetGlobalStorage(nsIDOMStorageList * *aGlobalStorage)
{
    return NS_ERROR_NOT_IMPLEMENTED;
}

/* readonly attribute nsIDOMStorage2 localStorage; */
NS_IMETHODIMP nsDOMStorageWindow::GetLocalStorage(nsIDOMStorage2 * *aLocalStorage)
{
    return NS_ERROR_NOT_IMPLEMENTED;
}

/* End of implementation class template. */
#endif


#endif /* __gen_nsIDOMStorageWindow_h__ */
