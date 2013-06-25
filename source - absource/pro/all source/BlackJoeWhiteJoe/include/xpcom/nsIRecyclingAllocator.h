/*
 * DO NOT EDIT.  THIS FILE IS GENERATED FROM e:/builds/moz2_slave/mozilla-1.9.1-win32-xulrunner/build/xpcom/ds/nsIRecyclingAllocator.idl
 */

#ifndef __gen_nsIRecyclingAllocator_h__
#define __gen_nsIRecyclingAllocator_h__


#ifndef __gen_nsIMemory_h__
#include "nsIMemory.h"
#endif

/* For IDL files that don't want to include root IDL files. */
#ifndef NS_NO_VTABLE
#define NS_NO_VTABLE
#endif

/* starting interface:    nsIRecyclingAllocator */
#define NS_IRECYCLINGALLOCATOR_IID_STR "d064a04c-9cee-4319-be31-64d565bccba9"

#define NS_IRECYCLINGALLOCATOR_IID \
  {0xd064a04c, 0x9cee, 0x4319, \
    { 0xbe, 0x31, 0x64, 0xd5, 0x65, 0xbc, 0xcb, 0xa9 }}

/**
 *
 * nsIRecyclingAllocator: A wrapper for the nsRecyclingAllocator
 *
 * Holds allocations and reuses them for subsequent allocs.
 * Thread safe and uses a timer to release freelist.
 *
 * @status UNDER-DEVELOPMENT
 */
class NS_NO_VTABLE NS_SCRIPTABLE nsIRecyclingAllocator : public nsIMemory {
 public: 

  NS_DECLARE_STATIC_IID_ACCESSOR(NS_IRECYCLINGALLOCATOR_IID)

  /* void init (in size_t nblocks, in size_t recycleAfter, in string id); */
  NS_SCRIPTABLE NS_IMETHOD Init(size_t nblocks, size_t recycleAfter, const char *id) = 0;

};

  NS_DEFINE_STATIC_IID_ACCESSOR(nsIRecyclingAllocator, NS_IRECYCLINGALLOCATOR_IID)

/* Use this macro when declaring classes that implement this interface. */
#define NS_DECL_NSIRECYCLINGALLOCATOR \
  NS_SCRIPTABLE NS_IMETHOD Init(size_t nblocks, size_t recycleAfter, const char *id); 

/* Use this macro to declare functions that forward the behavior of this interface to another object. */
#define NS_FORWARD_NSIRECYCLINGALLOCATOR(_to) \
  NS_SCRIPTABLE NS_IMETHOD Init(size_t nblocks, size_t recycleAfter, const char *id) { return _to Init(nblocks, recycleAfter, id); } 

/* Use this macro to declare functions that forward the behavior of this interface to another object in a safe way. */
#define NS_FORWARD_SAFE_NSIRECYCLINGALLOCATOR(_to) \
  NS_SCRIPTABLE NS_IMETHOD Init(size_t nblocks, size_t recycleAfter, const char *id) { return !_to ? NS_ERROR_NULL_POINTER : _to->Init(nblocks, recycleAfter, id); } 

#if 0
/* Use the code below as a template for the implementation class for this interface. */

/* Header file */
class nsRecyclingAllocator : public nsIRecyclingAllocator
{
public:
  NS_DECL_ISUPPORTS
  NS_DECL_NSIRECYCLINGALLOCATOR

  nsRecyclingAllocator();

private:
  ~nsRecyclingAllocator();

protected:
  /* additional members */
};

/* Implementation file */
NS_IMPL_ISUPPORTS1(nsRecyclingAllocator, nsIRecyclingAllocator)

nsRecyclingAllocator::nsRecyclingAllocator()
{
  /* member initializers and constructor code */
}

nsRecyclingAllocator::~nsRecyclingAllocator()
{
  /* destructor code */
}

/* void init (in size_t nblocks, in size_t recycleAfter, in string id); */
NS_IMETHODIMP nsRecyclingAllocator::Init(size_t nblocks, size_t recycleAfter, const char *id)
{
    return NS_ERROR_NOT_IMPLEMENTED;
}

/* End of implementation class template. */
#endif

#define NS_RECYCLINGALLOCATOR_CID \
{ /* ac07ed4c-bf17-4976-a15c-d2194db3b1bf */ \
    0xac07ed4c,                              \
    0xbf17,                                  \
    0x4976,                                  \
    {0xa1, 0x5c, 0xd2, 0x19, 0x4d, 0xb3, 0xb1, 0xbf} }
#define NS_RECYCLINGALLOCATOR_CLASSNAME "Recycling Allocator"
#define NS_RECYCLINGALLOCATOR_CONTRACTID "@mozilla.org/recycling-allocator;1"

#endif /* __gen_nsIRecyclingAllocator_h__ */
