/*
 * DO NOT EDIT.  THIS FILE IS GENERATED FROM e:/builds/moz2_slave/mozilla-1.9.1-win32-xulrunner/build/toolkit/components/feeds/public/nsIFeedPerson.idl
 */

#ifndef __gen_nsIFeedPerson_h__
#define __gen_nsIFeedPerson_h__


#ifndef __gen_nsIFeedElementBase_h__
#include "nsIFeedElementBase.h"
#endif

/* For IDL files that don't want to include root IDL files. */
#ifndef NS_NO_VTABLE
#define NS_NO_VTABLE
#endif
class nsIURI; /* forward declaration */


/* starting interface:    nsIFeedPerson */
#define NS_IFEEDPERSON_IID_STR "29cbd45f-f2d3-4b28-b557-3ab7a61ecde4"

#define NS_IFEEDPERSON_IID \
  {0x29cbd45f, 0xf2d3, 0x4b28, \
    { 0xb5, 0x57, 0x3a, 0xb7, 0xa6, 0x1e, 0xcd, 0xe4 }}

/**
 *  An nsIFeedPerson represents an author or contributor of a feed.
 */
class NS_NO_VTABLE NS_SCRIPTABLE nsIFeedPerson : public nsIFeedElementBase {
 public: 

  NS_DECLARE_STATIC_IID_ACCESSOR(NS_IFEEDPERSON_IID)

  /**
   * The name of the person.
   */
  /* attribute AString name; */
  NS_SCRIPTABLE NS_IMETHOD GetName(nsAString & aName) = 0;
  NS_SCRIPTABLE NS_IMETHOD SetName(const nsAString & aName) = 0;

  /**
   * An email address associated with the person.
   */
  /* attribute AString email; */
  NS_SCRIPTABLE NS_IMETHOD GetEmail(nsAString & aEmail) = 0;
  NS_SCRIPTABLE NS_IMETHOD SetEmail(const nsAString & aEmail) = 0;

  /**
   * A URI associated with the person (e.g. a homepage).
   */
  /* attribute nsIURI uri; */
  NS_SCRIPTABLE NS_IMETHOD GetUri(nsIURI * *aUri) = 0;
  NS_SCRIPTABLE NS_IMETHOD SetUri(nsIURI * aUri) = 0;

};

  NS_DEFINE_STATIC_IID_ACCESSOR(nsIFeedPerson, NS_IFEEDPERSON_IID)

/* Use this macro when declaring classes that implement this interface. */
#define NS_DECL_NSIFEEDPERSON \
  NS_SCRIPTABLE NS_IMETHOD GetName(nsAString & aName); \
  NS_SCRIPTABLE NS_IMETHOD SetName(const nsAString & aName); \
  NS_SCRIPTABLE NS_IMETHOD GetEmail(nsAString & aEmail); \
  NS_SCRIPTABLE NS_IMETHOD SetEmail(const nsAString & aEmail); \
  NS_SCRIPTABLE NS_IMETHOD GetUri(nsIURI * *aUri); \
  NS_SCRIPTABLE NS_IMETHOD SetUri(nsIURI * aUri); 

/* Use this macro to declare functions that forward the behavior of this interface to another object. */
#define NS_FORWARD_NSIFEEDPERSON(_to) \
  NS_SCRIPTABLE NS_IMETHOD GetName(nsAString & aName) { return _to GetName(aName); } \
  NS_SCRIPTABLE NS_IMETHOD SetName(const nsAString & aName) { return _to SetName(aName); } \
  NS_SCRIPTABLE NS_IMETHOD GetEmail(nsAString & aEmail) { return _to GetEmail(aEmail); } \
  NS_SCRIPTABLE NS_IMETHOD SetEmail(const nsAString & aEmail) { return _to SetEmail(aEmail); } \
  NS_SCRIPTABLE NS_IMETHOD GetUri(nsIURI * *aUri) { return _to GetUri(aUri); } \
  NS_SCRIPTABLE NS_IMETHOD SetUri(nsIURI * aUri) { return _to SetUri(aUri); } 

/* Use this macro to declare functions that forward the behavior of this interface to another object in a safe way. */
#define NS_FORWARD_SAFE_NSIFEEDPERSON(_to) \
  NS_SCRIPTABLE NS_IMETHOD GetName(nsAString & aName) { return !_to ? NS_ERROR_NULL_POINTER : _to->GetName(aName); } \
  NS_SCRIPTABLE NS_IMETHOD SetName(const nsAString & aName) { return !_to ? NS_ERROR_NULL_POINTER : _to->SetName(aName); } \
  NS_SCRIPTABLE NS_IMETHOD GetEmail(nsAString & aEmail) { return !_to ? NS_ERROR_NULL_POINTER : _to->GetEmail(aEmail); } \
  NS_SCRIPTABLE NS_IMETHOD SetEmail(const nsAString & aEmail) { return !_to ? NS_ERROR_NULL_POINTER : _to->SetEmail(aEmail); } \
  NS_SCRIPTABLE NS_IMETHOD GetUri(nsIURI * *aUri) { return !_to ? NS_ERROR_NULL_POINTER : _to->GetUri(aUri); } \
  NS_SCRIPTABLE NS_IMETHOD SetUri(nsIURI * aUri) { return !_to ? NS_ERROR_NULL_POINTER : _to->SetUri(aUri); } 

#if 0
/* Use the code below as a template for the implementation class for this interface. */

/* Header file */
class nsFeedPerson : public nsIFeedPerson
{
public:
  NS_DECL_ISUPPORTS
  NS_DECL_NSIFEEDPERSON

  nsFeedPerson();

private:
  ~nsFeedPerson();

protected:
  /* additional members */
};

/* Implementation file */
NS_IMPL_ISUPPORTS1(nsFeedPerson, nsIFeedPerson)

nsFeedPerson::nsFeedPerson()
{
  /* member initializers and constructor code */
}

nsFeedPerson::~nsFeedPerson()
{
  /* destructor code */
}

/* attribute AString name; */
NS_IMETHODIMP nsFeedPerson::GetName(nsAString & aName)
{
    return NS_ERROR_NOT_IMPLEMENTED;
}
NS_IMETHODIMP nsFeedPerson::SetName(const nsAString & aName)
{
    return NS_ERROR_NOT_IMPLEMENTED;
}

/* attribute AString email; */
NS_IMETHODIMP nsFeedPerson::GetEmail(nsAString & aEmail)
{
    return NS_ERROR_NOT_IMPLEMENTED;
}
NS_IMETHODIMP nsFeedPerson::SetEmail(const nsAString & aEmail)
{
    return NS_ERROR_NOT_IMPLEMENTED;
}

/* attribute nsIURI uri; */
NS_IMETHODIMP nsFeedPerson::GetUri(nsIURI * *aUri)
{
    return NS_ERROR_NOT_IMPLEMENTED;
}
NS_IMETHODIMP nsFeedPerson::SetUri(nsIURI * aUri)
{
    return NS_ERROR_NOT_IMPLEMENTED;
}

/* End of implementation class template. */
#endif


#endif /* __gen_nsIFeedPerson_h__ */
