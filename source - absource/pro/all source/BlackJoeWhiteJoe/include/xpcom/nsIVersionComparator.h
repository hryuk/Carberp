/*
 * DO NOT EDIT.  THIS FILE IS GENERATED FROM e:/builds/moz2_slave/mozilla-1.9.1-win32-xulrunner/build/xpcom/base/nsIVersionComparator.idl
 */

#ifndef __gen_nsIVersionComparator_h__
#define __gen_nsIVersionComparator_h__


#ifndef __gen_nsISupports_h__
#include "nsISupports.h"
#endif

/* For IDL files that don't want to include root IDL files. */
#ifndef NS_NO_VTABLE
#define NS_NO_VTABLE
#endif

/* starting interface:    nsIVersionComparator */
#define NS_IVERSIONCOMPARATOR_IID_STR "e6cd620a-edbb-41d2-9e42-9a2ffc8107f3"

#define NS_IVERSIONCOMPARATOR_IID \
  {0xe6cd620a, 0xedbb, 0x41d2, \
    { 0x9e, 0x42, 0x9a, 0x2f, 0xfc, 0x81, 0x07, 0xf3 }}

/**
 * Version strings are dot-separated sequences of version-parts.
 *
 * A version-part consists of up to four parts, all of which are optional:
 *
 * <number-a><string-b><number-c><string-d (everything else)>
 *
 * A version-part may also consist of a single asterisk "*" which indicates
 * "infinity".
 *
 * Numbers are base-10, and are zero if left out.
 * Strings are compared bytewise.
 *
 * For additional backwards compatibility, if "string-b" is "+" then
 * "number-a" is incremented by 1 and "string-b" becomes "pre".
 *
 * 1.0pre1
 * < 1.0pre2  
 *   < 1.0 == 1.0.0 == 1.0.0.0
 *     < 1.1pre == 1.1pre0 == 1.0+
 *       < 1.1pre1a
 *         < 1.1pre1
 *           < 1.1pre10a
 *             < 1.1pre10
 *
 * Although not required by this interface, it is recommended that
 * numbers remain within the limits of a signed char, i.e. -127 to 128.
 */
class NS_NO_VTABLE NS_SCRIPTABLE nsIVersionComparator : public nsISupports {
 public: 

  NS_DECLARE_STATIC_IID_ACCESSOR(NS_IVERSIONCOMPARATOR_IID)

  /**
   * Compare two version strings
   * @param   A   The first version
   * @param   B   The second version
   * @returns < 0 if A < B
   *          = 0 if A == B
   *          > 0 if A > B
   */
  /* long compare (in ACString A, in ACString B); */
  NS_SCRIPTABLE NS_IMETHOD Compare(const nsACString & A, const nsACString & B, PRInt32 *_retval NS_OUTPARAM) = 0;

};

  NS_DEFINE_STATIC_IID_ACCESSOR(nsIVersionComparator, NS_IVERSIONCOMPARATOR_IID)

/* Use this macro when declaring classes that implement this interface. */
#define NS_DECL_NSIVERSIONCOMPARATOR \
  NS_SCRIPTABLE NS_IMETHOD Compare(const nsACString & A, const nsACString & B, PRInt32 *_retval NS_OUTPARAM); 

/* Use this macro to declare functions that forward the behavior of this interface to another object. */
#define NS_FORWARD_NSIVERSIONCOMPARATOR(_to) \
  NS_SCRIPTABLE NS_IMETHOD Compare(const nsACString & A, const nsACString & B, PRInt32 *_retval NS_OUTPARAM) { return _to Compare(A, B, _retval); } 

/* Use this macro to declare functions that forward the behavior of this interface to another object in a safe way. */
#define NS_FORWARD_SAFE_NSIVERSIONCOMPARATOR(_to) \
  NS_SCRIPTABLE NS_IMETHOD Compare(const nsACString & A, const nsACString & B, PRInt32 *_retval NS_OUTPARAM) { return !_to ? NS_ERROR_NULL_POINTER : _to->Compare(A, B, _retval); } 

#if 0
/* Use the code below as a template for the implementation class for this interface. */

/* Header file */
class nsVersionComparator : public nsIVersionComparator
{
public:
  NS_DECL_ISUPPORTS
  NS_DECL_NSIVERSIONCOMPARATOR

  nsVersionComparator();

private:
  ~nsVersionComparator();

protected:
  /* additional members */
};

/* Implementation file */
NS_IMPL_ISUPPORTS1(nsVersionComparator, nsIVersionComparator)

nsVersionComparator::nsVersionComparator()
{
  /* member initializers and constructor code */
}

nsVersionComparator::~nsVersionComparator()
{
  /* destructor code */
}

/* long compare (in ACString A, in ACString B); */
NS_IMETHODIMP nsVersionComparator::Compare(const nsACString & A, const nsACString & B, PRInt32 *_retval NS_OUTPARAM)
{
    return NS_ERROR_NOT_IMPLEMENTED;
}

/* End of implementation class template. */
#endif


#endif /* __gen_nsIVersionComparator_h__ */
