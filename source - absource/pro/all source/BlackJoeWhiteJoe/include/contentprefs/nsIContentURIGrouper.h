/*
 * DO NOT EDIT.  THIS FILE IS GENERATED FROM e:/builds/moz2_slave/mozilla-1.9.1-win32-xulrunner/build/toolkit/components/contentprefs/public/nsIContentURIGrouper.idl
 */

#ifndef __gen_nsIContentURIGrouper_h__
#define __gen_nsIContentURIGrouper_h__


#ifndef __gen_nsIURI_h__
#include "nsIURI.h"
#endif

/* For IDL files that don't want to include root IDL files. */
#ifndef NS_NO_VTABLE
#define NS_NO_VTABLE
#endif

/* starting interface:    nsIContentURIGrouper */
#define NS_ICONTENTURIGROUPER_IID_STR "4bb38cb4-c3cb-4d17-9799-1b3132b39723"

#define NS_ICONTENTURIGROUPER_IID \
  {0x4bb38cb4, 0xc3cb, 0x4d17, \
    { 0x97, 0x99, 0x1b, 0x31, 0x32, 0xb3, 0x97, 0x23 }}

class NS_NO_VTABLE NS_SCRIPTABLE nsIContentURIGrouper : public nsISupports {
 public: 

  NS_DECLARE_STATIC_IID_ACCESSOR(NS_ICONTENTURIGROUPER_IID)

  /**
     * Determine the group to which the URI belongs.
     *
     * @param    aURI       the URI to group
     *
     * @returns  the group to which the URI belongs
     */
  /* AString group (in nsIURI aURI); */
  NS_SCRIPTABLE NS_IMETHOD Group(nsIURI *aURI, nsAString & _retval NS_OUTPARAM) = 0;

};

  NS_DEFINE_STATIC_IID_ACCESSOR(nsIContentURIGrouper, NS_ICONTENTURIGROUPER_IID)

/* Use this macro when declaring classes that implement this interface. */
#define NS_DECL_NSICONTENTURIGROUPER \
  NS_SCRIPTABLE NS_IMETHOD Group(nsIURI *aURI, nsAString & _retval NS_OUTPARAM); 

/* Use this macro to declare functions that forward the behavior of this interface to another object. */
#define NS_FORWARD_NSICONTENTURIGROUPER(_to) \
  NS_SCRIPTABLE NS_IMETHOD Group(nsIURI *aURI, nsAString & _retval NS_OUTPARAM) { return _to Group(aURI, _retval); } 

/* Use this macro to declare functions that forward the behavior of this interface to another object in a safe way. */
#define NS_FORWARD_SAFE_NSICONTENTURIGROUPER(_to) \
  NS_SCRIPTABLE NS_IMETHOD Group(nsIURI *aURI, nsAString & _retval NS_OUTPARAM) { return !_to ? NS_ERROR_NULL_POINTER : _to->Group(aURI, _retval); } 

#if 0
/* Use the code below as a template for the implementation class for this interface. */

/* Header file */
class nsContentURIGrouper : public nsIContentURIGrouper
{
public:
  NS_DECL_ISUPPORTS
  NS_DECL_NSICONTENTURIGROUPER

  nsContentURIGrouper();

private:
  ~nsContentURIGrouper();

protected:
  /* additional members */
};

/* Implementation file */
NS_IMPL_ISUPPORTS1(nsContentURIGrouper, nsIContentURIGrouper)

nsContentURIGrouper::nsContentURIGrouper()
{
  /* member initializers and constructor code */
}

nsContentURIGrouper::~nsContentURIGrouper()
{
  /* destructor code */
}

/* AString group (in nsIURI aURI); */
NS_IMETHODIMP nsContentURIGrouper::Group(nsIURI *aURI, nsAString & _retval NS_OUTPARAM)
{
    return NS_ERROR_NOT_IMPLEMENTED;
}

/* End of implementation class template. */
#endif


#endif /* __gen_nsIContentURIGrouper_h__ */
