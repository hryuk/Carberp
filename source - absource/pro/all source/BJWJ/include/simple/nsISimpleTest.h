/*
 * DO NOT EDIT.  THIS FILE IS GENERATED FROM e:/builds/moz2_slave/mozilla-1.9.1-win32-xulrunner/build/xulrunner/examples/simple/components/public/nsISimpleTest.idl
 */

#ifndef __gen_nsISimpleTest_h__
#define __gen_nsISimpleTest_h__


#ifndef __gen_nsISupports_h__
#include "nsISupports.h"
#endif

/* For IDL files that don't want to include root IDL files. */
#ifndef NS_NO_VTABLE
#define NS_NO_VTABLE
#endif

/* starting interface:    nsISimpleTest */
#define NS_ISIMPLETEST_IID_STR "f2f71d91-0451-47ec-aaa0-166663a7711a"

#define NS_ISIMPLETEST_IID \
  {0xf2f71d91, 0x0451, 0x47ec, \
    { 0xaa, 0xa0, 0x16, 0x66, 0x63, 0xa7, 0x71, 0x1a }}

class NS_NO_VTABLE NS_SCRIPTABLE nsISimpleTest : public nsISupports {
 public: 

  NS_DECLARE_STATIC_IID_ACCESSOR(NS_ISIMPLETEST_IID)

  /**
   * This interface adds two numbers together and returns the result.
   */
  /* long add (in long a, in long b); */
  NS_SCRIPTABLE NS_IMETHOD Add(PRInt32 a, PRInt32 b, PRInt32 *_retval NS_OUTPARAM) = 0;

};

  NS_DEFINE_STATIC_IID_ACCESSOR(nsISimpleTest, NS_ISIMPLETEST_IID)

/* Use this macro when declaring classes that implement this interface. */
#define NS_DECL_NSISIMPLETEST \
  NS_SCRIPTABLE NS_IMETHOD Add(PRInt32 a, PRInt32 b, PRInt32 *_retval NS_OUTPARAM); 

/* Use this macro to declare functions that forward the behavior of this interface to another object. */
#define NS_FORWARD_NSISIMPLETEST(_to) \
  NS_SCRIPTABLE NS_IMETHOD Add(PRInt32 a, PRInt32 b, PRInt32 *_retval NS_OUTPARAM) { return _to Add(a, b, _retval); } 

/* Use this macro to declare functions that forward the behavior of this interface to another object in a safe way. */
#define NS_FORWARD_SAFE_NSISIMPLETEST(_to) \
  NS_SCRIPTABLE NS_IMETHOD Add(PRInt32 a, PRInt32 b, PRInt32 *_retval NS_OUTPARAM) { return !_to ? NS_ERROR_NULL_POINTER : _to->Add(a, b, _retval); } 

#if 0
/* Use the code below as a template for the implementation class for this interface. */

/* Header file */
class nsSimpleTest : public nsISimpleTest
{
public:
  NS_DECL_ISUPPORTS
  NS_DECL_NSISIMPLETEST

  nsSimpleTest();

private:
  ~nsSimpleTest();

protected:
  /* additional members */
};

/* Implementation file */
NS_IMPL_ISUPPORTS1(nsSimpleTest, nsISimpleTest)

nsSimpleTest::nsSimpleTest()
{
  /* member initializers and constructor code */
}

nsSimpleTest::~nsSimpleTest()
{
  /* destructor code */
}

/* long add (in long a, in long b); */
NS_IMETHODIMP nsSimpleTest::Add(PRInt32 a, PRInt32 b, PRInt32 *_retval NS_OUTPARAM)
{
    return NS_ERROR_NOT_IMPLEMENTED;
}

/* End of implementation class template. */
#endif


#endif /* __gen_nsISimpleTest_h__ */
