/*
 * DO NOT EDIT.  THIS FILE IS GENERATED FROM e:/builds/moz2_slave/mozilla-1.9.1-win32-xulrunner/build/content/xslt/public/txIFunctionEvaluationContext.idl
 */

#ifndef __gen_txIFunctionEvaluationContext_h__
#define __gen_txIFunctionEvaluationContext_h__


#ifndef __gen_domstubs_h__
#include "domstubs.h"
#endif

/* For IDL files that don't want to include root IDL files. */
#ifndef NS_NO_VTABLE
#define NS_NO_VTABLE
#endif
class txINodeSet; /* forward declaration */


/* starting interface:    txIFunctionEvaluationContext */
#define TXIFUNCTIONEVALUATIONCONTEXT_IID_STR "0ecbb00c-6a78-11d9-9791-000a95dc234c"

#define TXIFUNCTIONEVALUATIONCONTEXT_IID \
  {0x0ecbb00c, 0x6a78, 0x11d9, \
    { 0x97, 0x91, 0x00, 0x0a, 0x95, 0xdc, 0x23, 0x4c }}

class NS_NO_VTABLE NS_SCRIPTABLE txIFunctionEvaluationContext : public nsISupports {
 public: 

  NS_DECLARE_STATIC_IID_ACCESSOR(TXIFUNCTIONEVALUATIONCONTEXT_IID)

  /* readonly attribute PRUint32 position; */
  NS_SCRIPTABLE NS_IMETHOD GetPosition(PRUint32 *aPosition) = 0;

  /* readonly attribute PRUint32 size; */
  NS_SCRIPTABLE NS_IMETHOD GetSize(PRUint32 *aSize) = 0;

  /* readonly attribute nsIDOMNode contextNode; */
  NS_SCRIPTABLE NS_IMETHOD GetContextNode(nsIDOMNode * *aContextNode) = 0;

  /* readonly attribute nsISupports state; */
  NS_SCRIPTABLE NS_IMETHOD GetState(nsISupports * *aState) = 0;

};

  NS_DEFINE_STATIC_IID_ACCESSOR(txIFunctionEvaluationContext, TXIFUNCTIONEVALUATIONCONTEXT_IID)

/* Use this macro when declaring classes that implement this interface. */
#define NS_DECL_TXIFUNCTIONEVALUATIONCONTEXT \
  NS_SCRIPTABLE NS_IMETHOD GetPosition(PRUint32 *aPosition); \
  NS_SCRIPTABLE NS_IMETHOD GetSize(PRUint32 *aSize); \
  NS_SCRIPTABLE NS_IMETHOD GetContextNode(nsIDOMNode * *aContextNode); \
  NS_SCRIPTABLE NS_IMETHOD GetState(nsISupports * *aState); 

/* Use this macro to declare functions that forward the behavior of this interface to another object. */
#define NS_FORWARD_TXIFUNCTIONEVALUATIONCONTEXT(_to) \
  NS_SCRIPTABLE NS_IMETHOD GetPosition(PRUint32 *aPosition) { return _to GetPosition(aPosition); } \
  NS_SCRIPTABLE NS_IMETHOD GetSize(PRUint32 *aSize) { return _to GetSize(aSize); } \
  NS_SCRIPTABLE NS_IMETHOD GetContextNode(nsIDOMNode * *aContextNode) { return _to GetContextNode(aContextNode); } \
  NS_SCRIPTABLE NS_IMETHOD GetState(nsISupports * *aState) { return _to GetState(aState); } 

/* Use this macro to declare functions that forward the behavior of this interface to another object in a safe way. */
#define NS_FORWARD_SAFE_TXIFUNCTIONEVALUATIONCONTEXT(_to) \
  NS_SCRIPTABLE NS_IMETHOD GetPosition(PRUint32 *aPosition) { return !_to ? NS_ERROR_NULL_POINTER : _to->GetPosition(aPosition); } \
  NS_SCRIPTABLE NS_IMETHOD GetSize(PRUint32 *aSize) { return !_to ? NS_ERROR_NULL_POINTER : _to->GetSize(aSize); } \
  NS_SCRIPTABLE NS_IMETHOD GetContextNode(nsIDOMNode * *aContextNode) { return !_to ? NS_ERROR_NULL_POINTER : _to->GetContextNode(aContextNode); } \
  NS_SCRIPTABLE NS_IMETHOD GetState(nsISupports * *aState) { return !_to ? NS_ERROR_NULL_POINTER : _to->GetState(aState); } 

#if 0
/* Use the code below as a template for the implementation class for this interface. */

/* Header file */
class txFunctionEvaluationContext : public txIFunctionEvaluationContext
{
public:
  NS_DECL_ISUPPORTS
  NS_DECL_TXIFUNCTIONEVALUATIONCONTEXT

  txFunctionEvaluationContext();

private:
  ~txFunctionEvaluationContext();

protected:
  /* additional members */
};

/* Implementation file */
NS_IMPL_ISUPPORTS1(txFunctionEvaluationContext, txIFunctionEvaluationContext)

txFunctionEvaluationContext::txFunctionEvaluationContext()
{
  /* member initializers and constructor code */
}

txFunctionEvaluationContext::~txFunctionEvaluationContext()
{
  /* destructor code */
}

/* readonly attribute PRUint32 position; */
NS_IMETHODIMP txFunctionEvaluationContext::GetPosition(PRUint32 *aPosition)
{
    return NS_ERROR_NOT_IMPLEMENTED;
}

/* readonly attribute PRUint32 size; */
NS_IMETHODIMP txFunctionEvaluationContext::GetSize(PRUint32 *aSize)
{
    return NS_ERROR_NOT_IMPLEMENTED;
}

/* readonly attribute nsIDOMNode contextNode; */
NS_IMETHODIMP txFunctionEvaluationContext::GetContextNode(nsIDOMNode * *aContextNode)
{
    return NS_ERROR_NOT_IMPLEMENTED;
}

/* readonly attribute nsISupports state; */
NS_IMETHODIMP txFunctionEvaluationContext::GetState(nsISupports * *aState)
{
    return NS_ERROR_NOT_IMPLEMENTED;
}

/* End of implementation class template. */
#endif


#endif /* __gen_txIFunctionEvaluationContext_h__ */
