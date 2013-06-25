/*
 * DO NOT EDIT.  THIS FILE IS GENERATED FROM e:/builds/moz2_slave/mozilla-1.9.1-win32-xulrunner/build/dom/public/nsIEntropyCollector.idl
 */

#ifndef __gen_nsIEntropyCollector_h__
#define __gen_nsIEntropyCollector_h__


#ifndef __gen_nsISupports_h__
#include "nsISupports.h"
#endif

/* For IDL files that don't want to include root IDL files. */
#ifndef NS_NO_VTABLE
#define NS_NO_VTABLE
#endif
/*
 * If anyone wants to collect the entropy distributed by the
 * event handler, they'll have to implement this CONTRACTID
 */
#define NS_ENTROPYCOLLECTOR_CONTRACTID "@mozilla.org/security/entropy;1"

/* starting interface:    nsIEntropyCollector */
#define NS_IENTROPYCOLLECTOR_IID_STR "6f883680-ab9d-11d4-9978-00b0d02354a0"

#define NS_IENTROPYCOLLECTOR_IID \
  {0x6f883680, 0xab9d, 0x11d4, \
    { 0x99, 0x78, 0x00, 0xb0, 0xd0, 0x23, 0x54, 0xa0 }}

class NS_NO_VTABLE nsIEntropyCollector : public nsISupports {
 public: 

  NS_DECLARE_STATIC_IID_ACCESSOR(NS_IENTROPYCOLLECTOR_IID)

  /**
   * Add the following bytes to the pool of data to be used
   * in gathering entropy.
   */
  /* void randomUpdate (in buffer entropy, in long bufLen); */
  NS_IMETHOD RandomUpdate(void * entropy, PRInt32 bufLen) = 0;

};

  NS_DEFINE_STATIC_IID_ACCESSOR(nsIEntropyCollector, NS_IENTROPYCOLLECTOR_IID)

/* Use this macro when declaring classes that implement this interface. */
#define NS_DECL_NSIENTROPYCOLLECTOR \
  NS_IMETHOD RandomUpdate(void * entropy, PRInt32 bufLen); 

/* Use this macro to declare functions that forward the behavior of this interface to another object. */
#define NS_FORWARD_NSIENTROPYCOLLECTOR(_to) \
  NS_IMETHOD RandomUpdate(void * entropy, PRInt32 bufLen) { return _to RandomUpdate(entropy, bufLen); } 

/* Use this macro to declare functions that forward the behavior of this interface to another object in a safe way. */
#define NS_FORWARD_SAFE_NSIENTROPYCOLLECTOR(_to) \
  NS_IMETHOD RandomUpdate(void * entropy, PRInt32 bufLen) { return !_to ? NS_ERROR_NULL_POINTER : _to->RandomUpdate(entropy, bufLen); } 

#if 0
/* Use the code below as a template for the implementation class for this interface. */

/* Header file */
class nsEntropyCollector : public nsIEntropyCollector
{
public:
  NS_DECL_ISUPPORTS
  NS_DECL_NSIENTROPYCOLLECTOR

  nsEntropyCollector();

private:
  ~nsEntropyCollector();

protected:
  /* additional members */
};

/* Implementation file */
NS_IMPL_ISUPPORTS1(nsEntropyCollector, nsIEntropyCollector)

nsEntropyCollector::nsEntropyCollector()
{
  /* member initializers and constructor code */
}

nsEntropyCollector::~nsEntropyCollector()
{
  /* destructor code */
}

/* void randomUpdate (in buffer entropy, in long bufLen); */
NS_IMETHODIMP nsEntropyCollector::RandomUpdate(void * entropy, PRInt32 bufLen)
{
    return NS_ERROR_NOT_IMPLEMENTED;
}

/* End of implementation class template. */
#endif


#endif /* __gen_nsIEntropyCollector_h__ */
