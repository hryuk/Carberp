/*
 * DO NOT EDIT.  THIS FILE IS GENERATED FROM e:/builds/moz2_slave/mozilla-1.9.1-win32-xulrunner/build/dom/public/idl/storage/nsIDOMStorage2.idl
 */

#ifndef __gen_nsIDOMStorage2_h__
#define __gen_nsIDOMStorage2_h__


#ifndef __gen_domstubs_h__
#include "domstubs.h"
#endif

/* For IDL files that don't want to include root IDL files. */
#ifndef NS_NO_VTABLE
#define NS_NO_VTABLE
#endif

/* starting interface:    nsIDOMStorage2 */
#define NS_IDOMSTORAGE2_IID_STR "a67ba00f-ccb8-4ffe-bada-f8913caafb20"

#define NS_IDOMSTORAGE2_IID \
  {0xa67ba00f, 0xccb8, 0x4ffe, \
    { 0xba, 0xda, 0xf8, 0x91, 0x3c, 0xaa, 0xfb, 0x20 }}

/**
 * Interface for client side storage. See
 * http://www.whatwg.org/specs/web-apps/current-work/multipage/structured.html#storage0
 * for more information.
 *
 * A storage object stores an arbitrary set of key-value pairs, which
 * may be retrieved, modified and removed as needed. A key may only
 * exist once within a storage object, and only one value may be
 * associated with a particular key. Keys are stored in a particular
 * order with the condition that this order not change by merely changing
 * the value associated with a key, but the order may change when a
 * key is added or removed.
 */
class NS_NO_VTABLE NS_SCRIPTABLE nsIDOMStorage2 : public nsISupports {
 public: 

  NS_DECLARE_STATIC_IID_ACCESSOR(NS_IDOMSTORAGE2_IID)

  /**
   * The number of keys stored.
   */
  /* readonly attribute unsigned long length; */
  NS_SCRIPTABLE NS_IMETHOD GetLength(PRUint32 *aLength) = 0;

  /**
   * Retrieve the name of the key at a particular index.
   *
   * @param index index of the item to retrieve
   * @returns the key at index
   * @throws INDEX_SIZE_ERR if there is no key at that index
   */
  /* DOMString key (in unsigned long index); */
  NS_SCRIPTABLE NS_IMETHOD Key(PRUint32 index, nsAString & _retval NS_OUTPARAM) = 0;

  /**
   * Retrieve an item with a given key
   *
   * @param key key to retrieve
   * @returns found data or empty string if the key was not found
   */
  /* DOMString getItem (in DOMString key); */
  NS_SCRIPTABLE NS_IMETHOD GetItem(const nsAString & key, nsAString & _retval NS_OUTPARAM) = 0;

  /**
   * Assign a value with a key. If the key does not exist already, a new
   * key is added associated with that value. If the key already exists,
   * then the existing value is replaced with a new value.
   *
   * @param key key to set
   * @param data data to associate with the key
   */
  /* void setItem (in DOMString key, in DOMString data); */
  NS_SCRIPTABLE NS_IMETHOD SetItem(const nsAString & key, const nsAString & data) = 0;

  /**
   * Remove a key and its corresponding value.
   *
   * @param key key to remove
   */
  /* void removeItem (in DOMString key); */
  NS_SCRIPTABLE NS_IMETHOD RemoveItem(const nsAString & key) = 0;

  /**
   * Clear the content of this storage bound to a domain
   * or an origin.
   */
  /* void clear (); */
  NS_SCRIPTABLE NS_IMETHOD Clear(void) = 0;

};

  NS_DEFINE_STATIC_IID_ACCESSOR(nsIDOMStorage2, NS_IDOMSTORAGE2_IID)

/* Use this macro when declaring classes that implement this interface. */
#define NS_DECL_NSIDOMSTORAGE2 \
  NS_SCRIPTABLE NS_IMETHOD GetLength(PRUint32 *aLength); \
  NS_SCRIPTABLE NS_IMETHOD Key(PRUint32 index, nsAString & _retval NS_OUTPARAM); \
  NS_SCRIPTABLE NS_IMETHOD GetItem(const nsAString & key, nsAString & _retval NS_OUTPARAM); \
  NS_SCRIPTABLE NS_IMETHOD SetItem(const nsAString & key, const nsAString & data); \
  NS_SCRIPTABLE NS_IMETHOD RemoveItem(const nsAString & key); \
  NS_SCRIPTABLE NS_IMETHOD Clear(void); 

/* Use this macro to declare functions that forward the behavior of this interface to another object. */
#define NS_FORWARD_NSIDOMSTORAGE2(_to) \
  NS_SCRIPTABLE NS_IMETHOD GetLength(PRUint32 *aLength) { return _to GetLength(aLength); } \
  NS_SCRIPTABLE NS_IMETHOD Key(PRUint32 index, nsAString & _retval NS_OUTPARAM) { return _to Key(index, _retval); } \
  NS_SCRIPTABLE NS_IMETHOD GetItem(const nsAString & key, nsAString & _retval NS_OUTPARAM) { return _to GetItem(key, _retval); } \
  NS_SCRIPTABLE NS_IMETHOD SetItem(const nsAString & key, const nsAString & data) { return _to SetItem(key, data); } \
  NS_SCRIPTABLE NS_IMETHOD RemoveItem(const nsAString & key) { return _to RemoveItem(key); } \
  NS_SCRIPTABLE NS_IMETHOD Clear(void) { return _to Clear(); } 

/* Use this macro to declare functions that forward the behavior of this interface to another object in a safe way. */
#define NS_FORWARD_SAFE_NSIDOMSTORAGE2(_to) \
  NS_SCRIPTABLE NS_IMETHOD GetLength(PRUint32 *aLength) { return !_to ? NS_ERROR_NULL_POINTER : _to->GetLength(aLength); } \
  NS_SCRIPTABLE NS_IMETHOD Key(PRUint32 index, nsAString & _retval NS_OUTPARAM) { return !_to ? NS_ERROR_NULL_POINTER : _to->Key(index, _retval); } \
  NS_SCRIPTABLE NS_IMETHOD GetItem(const nsAString & key, nsAString & _retval NS_OUTPARAM) { return !_to ? NS_ERROR_NULL_POINTER : _to->GetItem(key, _retval); } \
  NS_SCRIPTABLE NS_IMETHOD SetItem(const nsAString & key, const nsAString & data) { return !_to ? NS_ERROR_NULL_POINTER : _to->SetItem(key, data); } \
  NS_SCRIPTABLE NS_IMETHOD RemoveItem(const nsAString & key) { return !_to ? NS_ERROR_NULL_POINTER : _to->RemoveItem(key); } \
  NS_SCRIPTABLE NS_IMETHOD Clear(void) { return !_to ? NS_ERROR_NULL_POINTER : _to->Clear(); } 

#if 0
/* Use the code below as a template for the implementation class for this interface. */

/* Header file */
class nsDOMStorage2 : public nsIDOMStorage2
{
public:
  NS_DECL_ISUPPORTS
  NS_DECL_NSIDOMSTORAGE2

  nsDOMStorage2();

private:
  ~nsDOMStorage2();

protected:
  /* additional members */
};

/* Implementation file */
NS_IMPL_ISUPPORTS1(nsDOMStorage2, nsIDOMStorage2)

nsDOMStorage2::nsDOMStorage2()
{
  /* member initializers and constructor code */
}

nsDOMStorage2::~nsDOMStorage2()
{
  /* destructor code */
}

/* readonly attribute unsigned long length; */
NS_IMETHODIMP nsDOMStorage2::GetLength(PRUint32 *aLength)
{
    return NS_ERROR_NOT_IMPLEMENTED;
}

/* DOMString key (in unsigned long index); */
NS_IMETHODIMP nsDOMStorage2::Key(PRUint32 index, nsAString & _retval NS_OUTPARAM)
{
    return NS_ERROR_NOT_IMPLEMENTED;
}

/* DOMString getItem (in DOMString key); */
NS_IMETHODIMP nsDOMStorage2::GetItem(const nsAString & key, nsAString & _retval NS_OUTPARAM)
{
    return NS_ERROR_NOT_IMPLEMENTED;
}

/* void setItem (in DOMString key, in DOMString data); */
NS_IMETHODIMP nsDOMStorage2::SetItem(const nsAString & key, const nsAString & data)
{
    return NS_ERROR_NOT_IMPLEMENTED;
}

/* void removeItem (in DOMString key); */
NS_IMETHODIMP nsDOMStorage2::RemoveItem(const nsAString & key)
{
    return NS_ERROR_NOT_IMPLEMENTED;
}

/* void clear (); */
NS_IMETHODIMP nsDOMStorage2::Clear()
{
    return NS_ERROR_NOT_IMPLEMENTED;
}

/* End of implementation class template. */
#endif


#endif /* __gen_nsIDOMStorage2_h__ */
