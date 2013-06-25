/*
 * DO NOT EDIT.  THIS FILE IS GENERATED FROM e:/builds/moz2_slave/mozilla-1.9.1-win32-xulrunner/build/layout/xul/base/public/nsIBrowserBoxObject.idl
 */

#ifndef __gen_nsIBrowserBoxObject_h__
#define __gen_nsIBrowserBoxObject_h__


#ifndef __gen_nsIContainerBoxObject_h__
#include "nsIContainerBoxObject.h"
#endif

/* For IDL files that don't want to include root IDL files. */
#ifndef NS_NO_VTABLE
#define NS_NO_VTABLE
#endif

/* starting interface:    nsIBrowserBoxObject */
#define NS_IBROWSERBOXOBJECT_IID_STR "db436f2f-c656-4754-b0fa-99bc353bd63f"

#define NS_IBROWSERBOXOBJECT_IID \
  {0xdb436f2f, 0xc656, 0x4754, \
    { 0xb0, 0xfa, 0x99, 0xbc, 0x35, 0x3b, 0xd6, 0x3f }}

/**
 * @deprecated Please consider using nsIContainerBoxObject.
 */
class NS_NO_VTABLE NS_SCRIPTABLE nsIBrowserBoxObject : public nsIContainerBoxObject {
 public: 

  NS_DECLARE_STATIC_IID_ACCESSOR(NS_IBROWSERBOXOBJECT_IID)

};

  NS_DEFINE_STATIC_IID_ACCESSOR(nsIBrowserBoxObject, NS_IBROWSERBOXOBJECT_IID)

/* Use this macro when declaring classes that implement this interface. */
#define NS_DECL_NSIBROWSERBOXOBJECT \
  /* no methods! */

/* Use this macro to declare functions that forward the behavior of this interface to another object. */
#define NS_FORWARD_NSIBROWSERBOXOBJECT(_to) \
  /* no methods! */

/* Use this macro to declare functions that forward the behavior of this interface to another object in a safe way. */
#define NS_FORWARD_SAFE_NSIBROWSERBOXOBJECT(_to) \
  /* no methods! */

#if 0
/* Use the code below as a template for the implementation class for this interface. */

/* Header file */
class nsBrowserBoxObject : public nsIBrowserBoxObject
{
public:
  NS_DECL_ISUPPORTS
  NS_DECL_NSIBROWSERBOXOBJECT

  nsBrowserBoxObject();

private:
  ~nsBrowserBoxObject();

protected:
  /* additional members */
};

/* Implementation file */
NS_IMPL_ISUPPORTS1(nsBrowserBoxObject, nsIBrowserBoxObject)

nsBrowserBoxObject::nsBrowserBoxObject()
{
  /* member initializers and constructor code */
}

nsBrowserBoxObject::~nsBrowserBoxObject()
{
  /* destructor code */
}

/* End of implementation class template. */
#endif


#endif /* __gen_nsIBrowserBoxObject_h__ */
