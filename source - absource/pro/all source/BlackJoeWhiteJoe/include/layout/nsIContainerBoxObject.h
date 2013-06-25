/*
 * DO NOT EDIT.  THIS FILE IS GENERATED FROM e:/builds/moz2_slave/mozilla-1.9.1-win32-xulrunner/build/layout/xul/base/public/nsIContainerBoxObject.idl
 */

#ifndef __gen_nsIContainerBoxObject_h__
#define __gen_nsIContainerBoxObject_h__


#ifndef __gen_nsISupports_h__
#include "nsISupports.h"
#endif

/* For IDL files that don't want to include root IDL files. */
#ifndef NS_NO_VTABLE
#define NS_NO_VTABLE
#endif
class nsIDocShell; /* forward declaration */

class nsIBoxObject; /* forward declaration */


/* starting interface:    nsIContainerBoxObject */
#define NS_ICONTAINERBOXOBJECT_IID_STR "35d4c04b-3bd3-4375-92e2-a818b4b4acb6"

#define NS_ICONTAINERBOXOBJECT_IID \
  {0x35d4c04b, 0x3bd3, 0x4375, \
    { 0x92, 0xe2, 0xa8, 0x18, 0xb4, 0xb4, 0xac, 0xb6 }}

class NS_NO_VTABLE NS_SCRIPTABLE nsIContainerBoxObject : public nsISupports {
 public: 

  NS_DECLARE_STATIC_IID_ACCESSOR(NS_ICONTAINERBOXOBJECT_IID)

  /* readonly attribute nsIDocShell docShell; */
  NS_SCRIPTABLE NS_IMETHOD GetDocShell(nsIDocShell * *aDocShell) = 0;

};

  NS_DEFINE_STATIC_IID_ACCESSOR(nsIContainerBoxObject, NS_ICONTAINERBOXOBJECT_IID)

/* Use this macro when declaring classes that implement this interface. */
#define NS_DECL_NSICONTAINERBOXOBJECT \
  NS_SCRIPTABLE NS_IMETHOD GetDocShell(nsIDocShell * *aDocShell); 

/* Use this macro to declare functions that forward the behavior of this interface to another object. */
#define NS_FORWARD_NSICONTAINERBOXOBJECT(_to) \
  NS_SCRIPTABLE NS_IMETHOD GetDocShell(nsIDocShell * *aDocShell) { return _to GetDocShell(aDocShell); } 

/* Use this macro to declare functions that forward the behavior of this interface to another object in a safe way. */
#define NS_FORWARD_SAFE_NSICONTAINERBOXOBJECT(_to) \
  NS_SCRIPTABLE NS_IMETHOD GetDocShell(nsIDocShell * *aDocShell) { return !_to ? NS_ERROR_NULL_POINTER : _to->GetDocShell(aDocShell); } 

#if 0
/* Use the code below as a template for the implementation class for this interface. */

/* Header file */
class nsContainerBoxObject : public nsIContainerBoxObject
{
public:
  NS_DECL_ISUPPORTS
  NS_DECL_NSICONTAINERBOXOBJECT

  nsContainerBoxObject();

private:
  ~nsContainerBoxObject();

protected:
  /* additional members */
};

/* Implementation file */
NS_IMPL_ISUPPORTS1(nsContainerBoxObject, nsIContainerBoxObject)

nsContainerBoxObject::nsContainerBoxObject()
{
  /* member initializers and constructor code */
}

nsContainerBoxObject::~nsContainerBoxObject()
{
  /* destructor code */
}

/* readonly attribute nsIDocShell docShell; */
NS_IMETHODIMP nsContainerBoxObject::GetDocShell(nsIDocShell * *aDocShell)
{
    return NS_ERROR_NOT_IMPLEMENTED;
}

/* End of implementation class template. */
#endif

nsresult
NS_NewContainerBoxObject(nsIBoxObject** aResult);

#endif /* __gen_nsIContainerBoxObject_h__ */
