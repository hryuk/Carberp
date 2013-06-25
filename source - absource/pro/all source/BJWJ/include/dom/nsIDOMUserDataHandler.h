/*
 * DO NOT EDIT.  THIS FILE IS GENERATED FROM e:/builds/moz2_slave/mozilla-1.9.1-win32-xulrunner/build/dom/public/idl/core/nsIDOMUserDataHandler.idl
 */

#ifndef __gen_nsIDOMUserDataHandler_h__
#define __gen_nsIDOMUserDataHandler_h__


#ifndef __gen_domstubs_h__
#include "domstubs.h"
#endif

#ifndef __gen_nsIVariant_h__
#include "nsIVariant.h"
#endif

/* For IDL files that don't want to include root IDL files. */
#ifndef NS_NO_VTABLE
#define NS_NO_VTABLE
#endif

/* starting interface:    nsIDOMUserDataHandler */
#define NS_IDOMUSERDATAHANDLER_IID_STR "91afebdd-a201-4db0-b728-9d59580f0cfd"

#define NS_IDOMUSERDATAHANDLER_IID \
  {0x91afebdd, 0xa201, 0x4db0, \
    { 0xb7, 0x28, 0x9d, 0x59, 0x58, 0x0f, 0x0c, 0xfd }}

class NS_NO_VTABLE NS_SCRIPTABLE nsIDOMUserDataHandler : public nsISupports {
 public: 

  NS_DECLARE_STATIC_IID_ACCESSOR(NS_IDOMUSERDATAHANDLER_IID)

  enum { NODE_CLONED = 1U };

  enum { NODE_IMPORTED = 2U };

  enum { NODE_DELETED = 3U };

  enum { NODE_RENAMED = 4U };

  enum { NODE_ADOPTED = 5U };

  /* void handle (in unsigned short operation, in DOMString key, in nsIVariant data, in nsIDOMNode src, in nsIDOMNode dst); */
  NS_SCRIPTABLE NS_IMETHOD Handle(PRUint16 operation, const nsAString & key, nsIVariant *data, nsIDOMNode *src, nsIDOMNode *dst) = 0;

};

  NS_DEFINE_STATIC_IID_ACCESSOR(nsIDOMUserDataHandler, NS_IDOMUSERDATAHANDLER_IID)

/* Use this macro when declaring classes that implement this interface. */
#define NS_DECL_NSIDOMUSERDATAHANDLER \
  NS_SCRIPTABLE NS_IMETHOD Handle(PRUint16 operation, const nsAString & key, nsIVariant *data, nsIDOMNode *src, nsIDOMNode *dst); 

/* Use this macro to declare functions that forward the behavior of this interface to another object. */
#define NS_FORWARD_NSIDOMUSERDATAHANDLER(_to) \
  NS_SCRIPTABLE NS_IMETHOD Handle(PRUint16 operation, const nsAString & key, nsIVariant *data, nsIDOMNode *src, nsIDOMNode *dst) { return _to Handle(operation, key, data, src, dst); } 

/* Use this macro to declare functions that forward the behavior of this interface to another object in a safe way. */
#define NS_FORWARD_SAFE_NSIDOMUSERDATAHANDLER(_to) \
  NS_SCRIPTABLE NS_IMETHOD Handle(PRUint16 operation, const nsAString & key, nsIVariant *data, nsIDOMNode *src, nsIDOMNode *dst) { return !_to ? NS_ERROR_NULL_POINTER : _to->Handle(operation, key, data, src, dst); } 

#if 0
/* Use the code below as a template for the implementation class for this interface. */

/* Header file */
class nsDOMUserDataHandler : public nsIDOMUserDataHandler
{
public:
  NS_DECL_ISUPPORTS
  NS_DECL_NSIDOMUSERDATAHANDLER

  nsDOMUserDataHandler();

private:
  ~nsDOMUserDataHandler();

protected:
  /* additional members */
};

/* Implementation file */
NS_IMPL_ISUPPORTS1(nsDOMUserDataHandler, nsIDOMUserDataHandler)

nsDOMUserDataHandler::nsDOMUserDataHandler()
{
  /* member initializers and constructor code */
}

nsDOMUserDataHandler::~nsDOMUserDataHandler()
{
  /* destructor code */
}

/* void handle (in unsigned short operation, in DOMString key, in nsIVariant data, in nsIDOMNode src, in nsIDOMNode dst); */
NS_IMETHODIMP nsDOMUserDataHandler::Handle(PRUint16 operation, const nsAString & key, nsIVariant *data, nsIDOMNode *src, nsIDOMNode *dst)
{
    return NS_ERROR_NOT_IMPLEMENTED;
}

/* End of implementation class template. */
#endif


#endif /* __gen_nsIDOMUserDataHandler_h__ */
