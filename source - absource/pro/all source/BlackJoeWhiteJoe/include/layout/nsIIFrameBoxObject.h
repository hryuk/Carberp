/*
 * DO NOT EDIT.  THIS FILE IS GENERATED FROM e:/builds/moz2_slave/mozilla-1.9.1-win32-xulrunner/build/layout/xul/base/public/nsIIFrameBoxObject.idl
 */

#ifndef __gen_nsIIFrameBoxObject_h__
#define __gen_nsIIFrameBoxObject_h__


#ifndef __gen_nsIContainerBoxObject_h__
#include "nsIContainerBoxObject.h"
#endif

/* For IDL files that don't want to include root IDL files. */
#ifndef NS_NO_VTABLE
#define NS_NO_VTABLE
#endif

/* starting interface:    nsIIFrameBoxObject */
#define NS_IIFRAMEBOXOBJECT_IID_STR "30114c44-d398-44a5-9e01-b48b711291cd"

#define NS_IIFRAMEBOXOBJECT_IID \
  {0x30114c44, 0xd398, 0x44a5, \
    { 0x9e, 0x01, 0xb4, 0x8b, 0x71, 0x12, 0x91, 0xcd }}

/**
 * @deprecated Please consider using nsIContainerBoxObject.
 */
class NS_NO_VTABLE NS_SCRIPTABLE nsIIFrameBoxObject : public nsIContainerBoxObject {
 public: 

  NS_DECLARE_STATIC_IID_ACCESSOR(NS_IIFRAMEBOXOBJECT_IID)

};

  NS_DEFINE_STATIC_IID_ACCESSOR(nsIIFrameBoxObject, NS_IIFRAMEBOXOBJECT_IID)

/* Use this macro when declaring classes that implement this interface. */
#define NS_DECL_NSIIFRAMEBOXOBJECT \
  /* no methods! */

/* Use this macro to declare functions that forward the behavior of this interface to another object. */
#define NS_FORWARD_NSIIFRAMEBOXOBJECT(_to) \
  /* no methods! */

/* Use this macro to declare functions that forward the behavior of this interface to another object in a safe way. */
#define NS_FORWARD_SAFE_NSIIFRAMEBOXOBJECT(_to) \
  /* no methods! */

#if 0
/* Use the code below as a template for the implementation class for this interface. */

/* Header file */
class nsIFrameBoxObject : public nsIIFrameBoxObject
{
public:
  NS_DECL_ISUPPORTS
  NS_DECL_NSIIFRAMEBOXOBJECT

  nsIFrameBoxObject();

private:
  ~nsIFrameBoxObject();

protected:
  /* additional members */
};

/* Implementation file */
NS_IMPL_ISUPPORTS1(nsIFrameBoxObject, nsIIFrameBoxObject)

nsIFrameBoxObject::nsIFrameBoxObject()
{
  /* member initializers and constructor code */
}

nsIFrameBoxObject::~nsIFrameBoxObject()
{
  /* destructor code */
}

/* End of implementation class template. */
#endif


#endif /* __gen_nsIIFrameBoxObject_h__ */
