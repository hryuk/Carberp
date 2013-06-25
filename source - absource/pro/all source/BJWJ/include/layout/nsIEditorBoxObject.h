/*
 * DO NOT EDIT.  THIS FILE IS GENERATED FROM e:/builds/moz2_slave/mozilla-1.9.1-win32-xulrunner/build/layout/xul/base/public/nsIEditorBoxObject.idl
 */

#ifndef __gen_nsIEditorBoxObject_h__
#define __gen_nsIEditorBoxObject_h__


#ifndef __gen_nsIContainerBoxObject_h__
#include "nsIContainerBoxObject.h"
#endif

/* For IDL files that don't want to include root IDL files. */
#ifndef NS_NO_VTABLE
#define NS_NO_VTABLE
#endif

/* starting interface:    nsIEditorBoxObject */
#define NS_IEDITORBOXOBJECT_IID_STR "e3800a23-5b83-49aa-b18c-efa1ac5416e0"

#define NS_IEDITORBOXOBJECT_IID \
  {0xe3800a23, 0x5b83, 0x49aa, \
    { 0xb1, 0x8c, 0xef, 0xa1, 0xac, 0x54, 0x16, 0xe0 }}

/**
 * @deprecated Please consider using nsIContainerBoxObject.
 */
class NS_NO_VTABLE NS_SCRIPTABLE nsIEditorBoxObject : public nsIContainerBoxObject {
 public: 

  NS_DECLARE_STATIC_IID_ACCESSOR(NS_IEDITORBOXOBJECT_IID)

};

  NS_DEFINE_STATIC_IID_ACCESSOR(nsIEditorBoxObject, NS_IEDITORBOXOBJECT_IID)

/* Use this macro when declaring classes that implement this interface. */
#define NS_DECL_NSIEDITORBOXOBJECT \
  /* no methods! */

/* Use this macro to declare functions that forward the behavior of this interface to another object. */
#define NS_FORWARD_NSIEDITORBOXOBJECT(_to) \
  /* no methods! */

/* Use this macro to declare functions that forward the behavior of this interface to another object in a safe way. */
#define NS_FORWARD_SAFE_NSIEDITORBOXOBJECT(_to) \
  /* no methods! */

#if 0
/* Use the code below as a template for the implementation class for this interface. */

/* Header file */
class nsEditorBoxObject : public nsIEditorBoxObject
{
public:
  NS_DECL_ISUPPORTS
  NS_DECL_NSIEDITORBOXOBJECT

  nsEditorBoxObject();

private:
  ~nsEditorBoxObject();

protected:
  /* additional members */
};

/* Implementation file */
NS_IMPL_ISUPPORTS1(nsEditorBoxObject, nsIEditorBoxObject)

nsEditorBoxObject::nsEditorBoxObject()
{
  /* member initializers and constructor code */
}

nsEditorBoxObject::~nsEditorBoxObject()
{
  /* destructor code */
}

/* End of implementation class template. */
#endif


#endif /* __gen_nsIEditorBoxObject_h__ */
