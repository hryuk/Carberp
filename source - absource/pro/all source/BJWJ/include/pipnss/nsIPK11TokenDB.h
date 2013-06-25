/*
 * DO NOT EDIT.  THIS FILE IS GENERATED FROM e:/builds/moz2_slave/mozilla-1.9.1-win32-xulrunner/build/security/manager/ssl/public/nsIPK11TokenDB.idl
 */

#ifndef __gen_nsIPK11TokenDB_h__
#define __gen_nsIPK11TokenDB_h__


#ifndef __gen_nsISupports_h__
#include "nsISupports.h"
#endif

/* For IDL files that don't want to include root IDL files. */
#ifndef NS_NO_VTABLE
#define NS_NO_VTABLE
#endif
class nsIPK11Token; /* forward declaration */

class nsIEnumerator; /* forward declaration */

#define NS_PK11TOKENDB_CONTRACTID "@mozilla.org/security/pk11tokendb;1"

/* starting interface:    nsIPK11TokenDB */
#define NS_IPK11TOKENDB_IID_STR "4ee28c82-1dd2-11b2-aabf-bb4017abe395"

#define NS_IPK11TOKENDB_IID \
  {0x4ee28c82, 0x1dd2, 0x11b2, \
    { 0xaa, 0xbf, 0xbb, 0x40, 0x17, 0xab, 0xe3, 0x95 }}

/**
 * The PK11 Token Database provides access to the PK11 modules
 * that are installed, and the tokens that are available.
 * Interfaces: nsIPK11TokenDB
 * Threading: ??
 */
/**
 * nsIPK11TokenDB - Manages PK11 Tokens
 */
class NS_NO_VTABLE NS_SCRIPTABLE nsIPK11TokenDB : public nsISupports {
 public: 

  NS_DECLARE_STATIC_IID_ACCESSOR(NS_IPK11TOKENDB_IID)

  /* nsIPK11Token getInternalKeyToken (); */
  NS_SCRIPTABLE NS_IMETHOD GetInternalKeyToken(nsIPK11Token **_retval NS_OUTPARAM) = 0;

  /* nsIPK11Token findTokenByName (in wstring tokenName); */
  NS_SCRIPTABLE NS_IMETHOD FindTokenByName(const PRUnichar *tokenName, nsIPK11Token **_retval NS_OUTPARAM) = 0;

  /* nsIEnumerator listTokens (); */
  NS_SCRIPTABLE NS_IMETHOD ListTokens(nsIEnumerator **_retval NS_OUTPARAM) = 0;

};

  NS_DEFINE_STATIC_IID_ACCESSOR(nsIPK11TokenDB, NS_IPK11TOKENDB_IID)

/* Use this macro when declaring classes that implement this interface. */
#define NS_DECL_NSIPK11TOKENDB \
  NS_SCRIPTABLE NS_IMETHOD GetInternalKeyToken(nsIPK11Token **_retval NS_OUTPARAM); \
  NS_SCRIPTABLE NS_IMETHOD FindTokenByName(const PRUnichar *tokenName, nsIPK11Token **_retval NS_OUTPARAM); \
  NS_SCRIPTABLE NS_IMETHOD ListTokens(nsIEnumerator **_retval NS_OUTPARAM); 

/* Use this macro to declare functions that forward the behavior of this interface to another object. */
#define NS_FORWARD_NSIPK11TOKENDB(_to) \
  NS_SCRIPTABLE NS_IMETHOD GetInternalKeyToken(nsIPK11Token **_retval NS_OUTPARAM) { return _to GetInternalKeyToken(_retval); } \
  NS_SCRIPTABLE NS_IMETHOD FindTokenByName(const PRUnichar *tokenName, nsIPK11Token **_retval NS_OUTPARAM) { return _to FindTokenByName(tokenName, _retval); } \
  NS_SCRIPTABLE NS_IMETHOD ListTokens(nsIEnumerator **_retval NS_OUTPARAM) { return _to ListTokens(_retval); } 

/* Use this macro to declare functions that forward the behavior of this interface to another object in a safe way. */
#define NS_FORWARD_SAFE_NSIPK11TOKENDB(_to) \
  NS_SCRIPTABLE NS_IMETHOD GetInternalKeyToken(nsIPK11Token **_retval NS_OUTPARAM) { return !_to ? NS_ERROR_NULL_POINTER : _to->GetInternalKeyToken(_retval); } \
  NS_SCRIPTABLE NS_IMETHOD FindTokenByName(const PRUnichar *tokenName, nsIPK11Token **_retval NS_OUTPARAM) { return !_to ? NS_ERROR_NULL_POINTER : _to->FindTokenByName(tokenName, _retval); } \
  NS_SCRIPTABLE NS_IMETHOD ListTokens(nsIEnumerator **_retval NS_OUTPARAM) { return !_to ? NS_ERROR_NULL_POINTER : _to->ListTokens(_retval); } 

#if 0
/* Use the code below as a template for the implementation class for this interface. */

/* Header file */
class nsPK11TokenDB : public nsIPK11TokenDB
{
public:
  NS_DECL_ISUPPORTS
  NS_DECL_NSIPK11TOKENDB

  nsPK11TokenDB();

private:
  ~nsPK11TokenDB();

protected:
  /* additional members */
};

/* Implementation file */
NS_IMPL_ISUPPORTS1(nsPK11TokenDB, nsIPK11TokenDB)

nsPK11TokenDB::nsPK11TokenDB()
{
  /* member initializers and constructor code */
}

nsPK11TokenDB::~nsPK11TokenDB()
{
  /* destructor code */
}

/* nsIPK11Token getInternalKeyToken (); */
NS_IMETHODIMP nsPK11TokenDB::GetInternalKeyToken(nsIPK11Token **_retval NS_OUTPARAM)
{
    return NS_ERROR_NOT_IMPLEMENTED;
}

/* nsIPK11Token findTokenByName (in wstring tokenName); */
NS_IMETHODIMP nsPK11TokenDB::FindTokenByName(const PRUnichar *tokenName, nsIPK11Token **_retval NS_OUTPARAM)
{
    return NS_ERROR_NOT_IMPLEMENTED;
}

/* nsIEnumerator listTokens (); */
NS_IMETHODIMP nsPK11TokenDB::ListTokens(nsIEnumerator **_retval NS_OUTPARAM)
{
    return NS_ERROR_NOT_IMPLEMENTED;
}

/* End of implementation class template. */
#endif


#endif /* __gen_nsIPK11TokenDB_h__ */
