/*
 * DO NOT EDIT.  THIS FILE IS GENERATED FROM e:/builds/moz2_slave/mozilla-1.9.1-win32-xulrunner/build/dom/public/idl/events/nsIDOMDataContainerEvent.idl
 */

#ifndef __gen_nsIDOMDataContainerEvent_h__
#define __gen_nsIDOMDataContainerEvent_h__


#ifndef __gen_nsIDOMEvent_h__
#include "nsIDOMEvent.h"
#endif

#ifndef __gen_nsIVariant_h__
#include "nsIVariant.h"
#endif

/* For IDL files that don't want to include root IDL files. */
#ifndef NS_NO_VTABLE
#define NS_NO_VTABLE
#endif

/* starting interface:    nsIDOMDataContainerEvent */
#define NS_IDOMDATACONTAINEREVENT_IID_STR "3600d66c-b9ac-4c22-b39a-d64cce619921"

#define NS_IDOMDATACONTAINEREVENT_IID \
  {0x3600d66c, 0xb9ac, 0x4c22, \
    { 0xb3, 0x9a, 0xd6, 0x4c, 0xce, 0x61, 0x99, 0x21 }}

class NS_NO_VTABLE NS_SCRIPTABLE nsIDOMDataContainerEvent : public nsIDOMEvent {
 public: 

  NS_DECLARE_STATIC_IID_ACCESSOR(NS_IDOMDATACONTAINEREVENT_IID)

  /**
   * Return the data associated with the given key.
   *
   * @param  key  the key
   * @return      the data associated with the key
   */
  /* nsIVariant getData (in DOMString key); */
  NS_SCRIPTABLE NS_IMETHOD GetData(const nsAString & key, nsIVariant **_retval NS_OUTPARAM) = 0;

  /**
   * Set the data for the given key.
   *
   * @param  key   the data key
   * @param  data  the data
   * @throws       NS_ERROR_UNEXPECTED if the method is called during event
   *               dispatch
   */
  /* void setData (in DOMString key, in nsIVariant data); */
  NS_SCRIPTABLE NS_IMETHOD SetData(const nsAString & key, nsIVariant *data) = 0;

};

  NS_DEFINE_STATIC_IID_ACCESSOR(nsIDOMDataContainerEvent, NS_IDOMDATACONTAINEREVENT_IID)

/* Use this macro when declaring classes that implement this interface. */
#define NS_DECL_NSIDOMDATACONTAINEREVENT \
  NS_SCRIPTABLE NS_IMETHOD GetData(const nsAString & key, nsIVariant **_retval NS_OUTPARAM); \
  NS_SCRIPTABLE NS_IMETHOD SetData(const nsAString & key, nsIVariant *data); 

/* Use this macro to declare functions that forward the behavior of this interface to another object. */
#define NS_FORWARD_NSIDOMDATACONTAINEREVENT(_to) \
  NS_SCRIPTABLE NS_IMETHOD GetData(const nsAString & key, nsIVariant **_retval NS_OUTPARAM) { return _to GetData(key, _retval); } \
  NS_SCRIPTABLE NS_IMETHOD SetData(const nsAString & key, nsIVariant *data) { return _to SetData(key, data); } 

/* Use this macro to declare functions that forward the behavior of this interface to another object in a safe way. */
#define NS_FORWARD_SAFE_NSIDOMDATACONTAINEREVENT(_to) \
  NS_SCRIPTABLE NS_IMETHOD GetData(const nsAString & key, nsIVariant **_retval NS_OUTPARAM) { return !_to ? NS_ERROR_NULL_POINTER : _to->GetData(key, _retval); } \
  NS_SCRIPTABLE NS_IMETHOD SetData(const nsAString & key, nsIVariant *data) { return !_to ? NS_ERROR_NULL_POINTER : _to->SetData(key, data); } 

#if 0
/* Use the code below as a template for the implementation class for this interface. */

/* Header file */
class nsDOMDataContainerEvent : public nsIDOMDataContainerEvent
{
public:
  NS_DECL_ISUPPORTS
  NS_DECL_NSIDOMDATACONTAINEREVENT

  nsDOMDataContainerEvent();

private:
  ~nsDOMDataContainerEvent();

protected:
  /* additional members */
};

/* Implementation file */
NS_IMPL_ISUPPORTS1(nsDOMDataContainerEvent, nsIDOMDataContainerEvent)

nsDOMDataContainerEvent::nsDOMDataContainerEvent()
{
  /* member initializers and constructor code */
}

nsDOMDataContainerEvent::~nsDOMDataContainerEvent()
{
  /* destructor code */
}

/* nsIVariant getData (in DOMString key); */
NS_IMETHODIMP nsDOMDataContainerEvent::GetData(const nsAString & key, nsIVariant **_retval NS_OUTPARAM)
{
    return NS_ERROR_NOT_IMPLEMENTED;
}

/* void setData (in DOMString key, in nsIVariant data); */
NS_IMETHODIMP nsDOMDataContainerEvent::SetData(const nsAString & key, nsIVariant *data)
{
    return NS_ERROR_NOT_IMPLEMENTED;
}

/* End of implementation class template. */
#endif


#endif /* __gen_nsIDOMDataContainerEvent_h__ */
