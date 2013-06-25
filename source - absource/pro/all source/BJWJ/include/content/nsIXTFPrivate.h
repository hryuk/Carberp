/*
 * DO NOT EDIT.  THIS FILE IS GENERATED FROM e:/builds/moz2_slave/mozilla-1.9.1-win32-xulrunner/build/content/xtf/public/nsIXTFPrivate.idl
 */

#ifndef __gen_nsIXTFPrivate_h__
#define __gen_nsIXTFPrivate_h__


#ifndef __gen_nsISupports_h__
#include "nsISupports.h"
#endif

/* For IDL files that don't want to include root IDL files. */
#ifndef NS_NO_VTABLE
#define NS_NO_VTABLE
#endif

/* starting interface:    nsIXTFPrivate */
#define NS_IXTFPRIVATE_IID_STR "13ef3d54-1dd1-4a5c-a8d5-a04a327fb9b6"

#define NS_IXTFPRIVATE_IID \
  {0x13ef3d54, 0x1dd1, 0x4a5c, \
    { 0xa8, 0xd5, 0xa0, 0x4a, 0x32, 0x7f, 0xb9, 0xb6 }}

class NS_NO_VTABLE NS_SCRIPTABLE nsIXTFPrivate : public nsISupports {
 public: 

  NS_DECLARE_STATIC_IID_ACCESSOR(NS_IXTFPRIVATE_IID)

  /* readonly attribute nsISupports inner; */
  NS_SCRIPTABLE NS_IMETHOD GetInner(nsISupports * *aInner) = 0;

};

  NS_DEFINE_STATIC_IID_ACCESSOR(nsIXTFPrivate, NS_IXTFPRIVATE_IID)

/* Use this macro when declaring classes that implement this interface. */
#define NS_DECL_NSIXTFPRIVATE \
  NS_SCRIPTABLE NS_IMETHOD GetInner(nsISupports * *aInner); 

/* Use this macro to declare functions that forward the behavior of this interface to another object. */
#define NS_FORWARD_NSIXTFPRIVATE(_to) \
  NS_SCRIPTABLE NS_IMETHOD GetInner(nsISupports * *aInner) { return _to GetInner(aInner); } 

/* Use this macro to declare functions that forward the behavior of this interface to another object in a safe way. */
#define NS_FORWARD_SAFE_NSIXTFPRIVATE(_to) \
  NS_SCRIPTABLE NS_IMETHOD GetInner(nsISupports * *aInner) { return !_to ? NS_ERROR_NULL_POINTER : _to->GetInner(aInner); } 

#if 0
/* Use the code below as a template for the implementation class for this interface. */

/* Header file */
class nsXTFPrivate : public nsIXTFPrivate
{
public:
  NS_DECL_ISUPPORTS
  NS_DECL_NSIXTFPRIVATE

  nsXTFPrivate();

private:
  ~nsXTFPrivate();

protected:
  /* additional members */
};

/* Implementation file */
NS_IMPL_ISUPPORTS1(nsXTFPrivate, nsIXTFPrivate)

nsXTFPrivate::nsXTFPrivate()
{
  /* member initializers and constructor code */
}

nsXTFPrivate::~nsXTFPrivate()
{
  /* destructor code */
}

/* readonly attribute nsISupports inner; */
NS_IMETHODIMP nsXTFPrivate::GetInner(nsISupports * *aInner)
{
    return NS_ERROR_NOT_IMPLEMENTED;
}

/* End of implementation class template. */
#endif


#endif /* __gen_nsIXTFPrivate_h__ */
