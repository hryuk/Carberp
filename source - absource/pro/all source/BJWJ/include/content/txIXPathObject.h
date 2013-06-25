/*
 * DO NOT EDIT.  THIS FILE IS GENERATED FROM e:/builds/moz2_slave/mozilla-1.9.1-win32-xulrunner/build/content/xslt/public/txIXPathObject.idl
 */

#ifndef __gen_txIXPathObject_h__
#define __gen_txIXPathObject_h__


#ifndef __gen_domstubs_h__
#include "domstubs.h"
#endif

/* For IDL files that don't want to include root IDL files. */
#ifndef NS_NO_VTABLE
#define NS_NO_VTABLE
#endif
class txAExprResult;

/* starting interface:    txIXPathObject */
#define TXIXPATHOBJECT_IID_STR "67706346-dece-4c9b-9fc2-57cf19071014"

#define TXIXPATHOBJECT_IID \
  {0x67706346, 0xdece, 0x4c9b, \
    { 0x9f, 0xc2, 0x57, 0xcf, 0x19, 0x07, 0x10, 0x14 }}

class NS_NO_VTABLE NS_SCRIPTABLE txIXPathObject : public nsISupports {
 public: 

  NS_DECLARE_STATIC_IID_ACCESSOR(TXIXPATHOBJECT_IID)

  /* [noscript, notxpcom] txAExprResultPtr getResult (); */
  NS_IMETHOD_(txAExprResult *) GetResult(void) = 0;

};

  NS_DEFINE_STATIC_IID_ACCESSOR(txIXPathObject, TXIXPATHOBJECT_IID)

/* Use this macro when declaring classes that implement this interface. */
#define NS_DECL_TXIXPATHOBJECT \
  NS_IMETHOD_(txAExprResult *) GetResult(void); 

/* Use this macro to declare functions that forward the behavior of this interface to another object. */
#define NS_FORWARD_TXIXPATHOBJECT(_to) \
  NS_IMETHOD_(txAExprResult *) GetResult(void) { return _to GetResult(); } 

/* Use this macro to declare functions that forward the behavior of this interface to another object in a safe way. */
#define NS_FORWARD_SAFE_TXIXPATHOBJECT(_to) \
  NS_IMETHOD_(txAExprResult *) GetResult(void) { return !_to ? NS_ERROR_NULL_POINTER : _to->GetResult(); } 

#if 0
/* Use the code below as a template for the implementation class for this interface. */

/* Header file */
class txXPathObject : public txIXPathObject
{
public:
  NS_DECL_ISUPPORTS
  NS_DECL_TXIXPATHOBJECT

  txXPathObject();

private:
  ~txXPathObject();

protected:
  /* additional members */
};

/* Implementation file */
NS_IMPL_ISUPPORTS1(txXPathObject, txIXPathObject)

txXPathObject::txXPathObject()
{
  /* member initializers and constructor code */
}

txXPathObject::~txXPathObject()
{
  /* destructor code */
}

/* [noscript, notxpcom] txAExprResultPtr getResult (); */
NS_IMETHODIMP_(txAExprResult *) txXPathObject::GetResult()
{
    return NS_ERROR_NOT_IMPLEMENTED;
}

/* End of implementation class template. */
#endif


#endif /* __gen_txIXPathObject_h__ */
