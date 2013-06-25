/*
 * DO NOT EDIT.  THIS FILE IS GENERATED FROM e:/builds/moz2_slave/mozilla-1.9.1-win32-xulrunner/build/dom/public/idl/stylesheets/nsIDOMLinkStyle.idl
 */

#ifndef __gen_nsIDOMLinkStyle_h__
#define __gen_nsIDOMLinkStyle_h__


#ifndef __gen_domstubs_h__
#include "domstubs.h"
#endif

/* For IDL files that don't want to include root IDL files. */
#ifndef NS_NO_VTABLE
#define NS_NO_VTABLE
#endif

/* starting interface:    nsIDOMLinkStyle */
#define NS_IDOMLINKSTYLE_IID_STR "24d89a65-f598-481e-a297-23cc02599bbd"

#define NS_IDOMLINKSTYLE_IID \
  {0x24d89a65, 0xf598, 0x481e, \
    { 0xa2, 0x97, 0x23, 0xcc, 0x02, 0x59, 0x9b, 0xbd }}

class NS_NO_VTABLE NS_SCRIPTABLE nsIDOMLinkStyle : public nsISupports {
 public: 

  NS_DECLARE_STATIC_IID_ACCESSOR(NS_IDOMLINKSTYLE_IID)

  /* readonly attribute nsIDOMStyleSheet sheet; */
  NS_SCRIPTABLE NS_IMETHOD GetSheet(nsIDOMStyleSheet * *aSheet) = 0;

};

  NS_DEFINE_STATIC_IID_ACCESSOR(nsIDOMLinkStyle, NS_IDOMLINKSTYLE_IID)

/* Use this macro when declaring classes that implement this interface. */
#define NS_DECL_NSIDOMLINKSTYLE \
  NS_SCRIPTABLE NS_IMETHOD GetSheet(nsIDOMStyleSheet * *aSheet); 

/* Use this macro to declare functions that forward the behavior of this interface to another object. */
#define NS_FORWARD_NSIDOMLINKSTYLE(_to) \
  NS_SCRIPTABLE NS_IMETHOD GetSheet(nsIDOMStyleSheet * *aSheet) { return _to GetSheet(aSheet); } 

/* Use this macro to declare functions that forward the behavior of this interface to another object in a safe way. */
#define NS_FORWARD_SAFE_NSIDOMLINKSTYLE(_to) \
  NS_SCRIPTABLE NS_IMETHOD GetSheet(nsIDOMStyleSheet * *aSheet) { return !_to ? NS_ERROR_NULL_POINTER : _to->GetSheet(aSheet); } 

#if 0
/* Use the code below as a template for the implementation class for this interface. */

/* Header file */
class nsDOMLinkStyle : public nsIDOMLinkStyle
{
public:
  NS_DECL_ISUPPORTS
  NS_DECL_NSIDOMLINKSTYLE

  nsDOMLinkStyle();

private:
  ~nsDOMLinkStyle();

protected:
  /* additional members */
};

/* Implementation file */
NS_IMPL_ISUPPORTS1(nsDOMLinkStyle, nsIDOMLinkStyle)

nsDOMLinkStyle::nsDOMLinkStyle()
{
  /* member initializers and constructor code */
}

nsDOMLinkStyle::~nsDOMLinkStyle()
{
  /* destructor code */
}

/* readonly attribute nsIDOMStyleSheet sheet; */
NS_IMETHODIMP nsDOMLinkStyle::GetSheet(nsIDOMStyleSheet * *aSheet)
{
    return NS_ERROR_NOT_IMPLEMENTED;
}

/* End of implementation class template. */
#endif


#endif /* __gen_nsIDOMLinkStyle_h__ */
