/*
 * DO NOT EDIT.  THIS FILE IS GENERATED FROM e:/builds/moz2_slave/mozilla-1.9.1-win32-xulrunner/build/modules/libpref/public/nsIPrefBranchInternal.idl
 */

#ifndef __gen_nsIPrefBranchInternal_h__
#define __gen_nsIPrefBranchInternal_h__


#ifndef __gen_nsIPrefBranch2_h__
#include "nsIPrefBranch2.h"
#endif

/* For IDL files that don't want to include root IDL files. */
#ifndef NS_NO_VTABLE
#define NS_NO_VTABLE
#endif

/* starting interface:    nsIPrefBranchInternal */
#define NS_IPREFBRANCHINTERNAL_IID_STR "d1d412d9-15d6-4a6a-9533-b949dc175ff5"

#define NS_IPREFBRANCHINTERNAL_IID \
  {0xd1d412d9, 0x15d6, 0x4a6a, \
    { 0x95, 0x33, 0xb9, 0x49, 0xdc, 0x17, 0x5f, 0xf5 }}

/**
 * An empty interface to provide backwards compatibility for existing code that
 * bsmedberg didn't want to break all at once. Don't use me!
 *
 * @status NON-FROZEN interface WHICH WILL PROBABLY GO AWAY.
 */
class NS_NO_VTABLE NS_SCRIPTABLE nsIPrefBranchInternal : public nsIPrefBranch2 {
 public: 

  NS_DECLARE_STATIC_IID_ACCESSOR(NS_IPREFBRANCHINTERNAL_IID)

};

  NS_DEFINE_STATIC_IID_ACCESSOR(nsIPrefBranchInternal, NS_IPREFBRANCHINTERNAL_IID)

/* Use this macro when declaring classes that implement this interface. */
#define NS_DECL_NSIPREFBRANCHINTERNAL \
  /* no methods! */

/* Use this macro to declare functions that forward the behavior of this interface to another object. */
#define NS_FORWARD_NSIPREFBRANCHINTERNAL(_to) \
  /* no methods! */

/* Use this macro to declare functions that forward the behavior of this interface to another object in a safe way. */
#define NS_FORWARD_SAFE_NSIPREFBRANCHINTERNAL(_to) \
  /* no methods! */

#if 0
/* Use the code below as a template for the implementation class for this interface. */

/* Header file */
class nsPrefBranchInternal : public nsIPrefBranchInternal
{
public:
  NS_DECL_ISUPPORTS
  NS_DECL_NSIPREFBRANCHINTERNAL

  nsPrefBranchInternal();

private:
  ~nsPrefBranchInternal();

protected:
  /* additional members */
};

/* Implementation file */
NS_IMPL_ISUPPORTS1(nsPrefBranchInternal, nsIPrefBranchInternal)

nsPrefBranchInternal::nsPrefBranchInternal()
{
  /* member initializers and constructor code */
}

nsPrefBranchInternal::~nsPrefBranchInternal()
{
  /* destructor code */
}

/* End of implementation class template. */
#endif


#endif /* __gen_nsIPrefBranchInternal_h__ */
