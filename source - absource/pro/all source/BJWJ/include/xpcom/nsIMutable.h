/*
 * DO NOT EDIT.  THIS FILE IS GENERATED FROM e:/builds/moz2_slave/mozilla-1.9.1-win32-xulrunner/build/xpcom/base/nsIMutable.idl
 */

#ifndef __gen_nsIMutable_h__
#define __gen_nsIMutable_h__


#ifndef __gen_nsISupports_h__
#include "nsISupports.h"
#endif

/* For IDL files that don't want to include root IDL files. */
#ifndef NS_NO_VTABLE
#define NS_NO_VTABLE
#endif

/* starting interface:    nsIMutable */
#define NS_IMUTABLE_IID_STR "321578d0-03c1-4d95-8821-021ac612d18d"

#define NS_IMUTABLE_IID \
  {0x321578d0, 0x03c1, 0x4d95, \
    { 0x88, 0x21, 0x02, 0x1a, 0xc6, 0x12, 0xd1, 0x8d }}

/**
 * nsIMutable defines an interface to be implemented by objects which
 * can be made immutable.
 */
class NS_NO_VTABLE NS_SCRIPTABLE nsIMutable : public nsISupports {
 public: 

  NS_DECLARE_STATIC_IID_ACCESSOR(NS_IMUTABLE_IID)

  /**
     * Control whether or not this object can be modified.  If the flag is
     * false, no modification is allowed.  Once the flag has been set to false,
     * it cannot be reset back to true -- attempts to do so throw
     * NS_ERROR_INVALID_ARG.
     */
  /* attribute boolean mutable; */
  NS_SCRIPTABLE NS_IMETHOD GetMutable(PRBool *aMutable) = 0;
  NS_SCRIPTABLE NS_IMETHOD SetMutable(PRBool aMutable) = 0;

};

  NS_DEFINE_STATIC_IID_ACCESSOR(nsIMutable, NS_IMUTABLE_IID)

/* Use this macro when declaring classes that implement this interface. */
#define NS_DECL_NSIMUTABLE \
  NS_SCRIPTABLE NS_IMETHOD GetMutable(PRBool *aMutable); \
  NS_SCRIPTABLE NS_IMETHOD SetMutable(PRBool aMutable); 

/* Use this macro to declare functions that forward the behavior of this interface to another object. */
#define NS_FORWARD_NSIMUTABLE(_to) \
  NS_SCRIPTABLE NS_IMETHOD GetMutable(PRBool *aMutable) { return _to GetMutable(aMutable); } \
  NS_SCRIPTABLE NS_IMETHOD SetMutable(PRBool aMutable) { return _to SetMutable(aMutable); } 

/* Use this macro to declare functions that forward the behavior of this interface to another object in a safe way. */
#define NS_FORWARD_SAFE_NSIMUTABLE(_to) \
  NS_SCRIPTABLE NS_IMETHOD GetMutable(PRBool *aMutable) { return !_to ? NS_ERROR_NULL_POINTER : _to->GetMutable(aMutable); } \
  NS_SCRIPTABLE NS_IMETHOD SetMutable(PRBool aMutable) { return !_to ? NS_ERROR_NULL_POINTER : _to->SetMutable(aMutable); } 

#if 0
/* Use the code below as a template for the implementation class for this interface. */

/* Header file */
class nsMutable : public nsIMutable
{
public:
  NS_DECL_ISUPPORTS
  NS_DECL_NSIMUTABLE

  nsMutable();

private:
  ~nsMutable();

protected:
  /* additional members */
};

/* Implementation file */
NS_IMPL_ISUPPORTS1(nsMutable, nsIMutable)

nsMutable::nsMutable()
{
  /* member initializers and constructor code */
}

nsMutable::~nsMutable()
{
  /* destructor code */
}

/* attribute boolean mutable; */
NS_IMETHODIMP nsMutable::GetMutable(PRBool *aMutable)
{
    return NS_ERROR_NOT_IMPLEMENTED;
}
NS_IMETHODIMP nsMutable::SetMutable(PRBool aMutable)
{
    return NS_ERROR_NOT_IMPLEMENTED;
}

/* End of implementation class template. */
#endif


#endif /* __gen_nsIMutable_h__ */
