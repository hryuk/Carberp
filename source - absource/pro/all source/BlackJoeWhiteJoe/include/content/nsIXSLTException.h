/*
 * DO NOT EDIT.  THIS FILE IS GENERATED FROM e:/builds/moz2_slave/mozilla-1.9.1-win32-xulrunner/build/content/xslt/public/nsIXSLTException.idl
 */

#ifndef __gen_nsIXSLTException_h__
#define __gen_nsIXSLTException_h__


#ifndef __gen_nsIException_h__
#include "nsIException.h"
#endif

#ifndef __gen_domstubs_h__
#include "domstubs.h"
#endif

/* For IDL files that don't want to include root IDL files. */
#ifndef NS_NO_VTABLE
#define NS_NO_VTABLE
#endif

/* starting interface:    nsIXSLTException */
#define NS_IXSLTEXCEPTION_IID_STR "e06dfaea-92d5-47f7-a800-c5f5404d8771"

#define NS_IXSLTEXCEPTION_IID \
  {0xe06dfaea, 0x92d5, 0x47f7, \
    { 0xa8, 0x00, 0xc5, 0xf5, 0x40, 0x4d, 0x87, 0x71 }}

class NS_NO_VTABLE NS_SCRIPTABLE nsIXSLTException : public nsIException {
 public: 

  NS_DECLARE_STATIC_IID_ACCESSOR(NS_IXSLTEXCEPTION_IID)

  /**
     * The node in the stylesheet that triggered the exception.
     */
  /* readonly attribute nsIDOMNode styleNode; */
  NS_SCRIPTABLE NS_IMETHOD GetStyleNode(nsIDOMNode * *aStyleNode) = 0;

  /**
     * The context node, may be null
     */
  /* readonly attribute nsIDOMNode sourceNode; */
  NS_SCRIPTABLE NS_IMETHOD GetSourceNode(nsIDOMNode * *aSourceNode) = 0;

};

  NS_DEFINE_STATIC_IID_ACCESSOR(nsIXSLTException, NS_IXSLTEXCEPTION_IID)

/* Use this macro when declaring classes that implement this interface. */
#define NS_DECL_NSIXSLTEXCEPTION \
  NS_SCRIPTABLE NS_IMETHOD GetStyleNode(nsIDOMNode * *aStyleNode); \
  NS_SCRIPTABLE NS_IMETHOD GetSourceNode(nsIDOMNode * *aSourceNode); 

/* Use this macro to declare functions that forward the behavior of this interface to another object. */
#define NS_FORWARD_NSIXSLTEXCEPTION(_to) \
  NS_SCRIPTABLE NS_IMETHOD GetStyleNode(nsIDOMNode * *aStyleNode) { return _to GetStyleNode(aStyleNode); } \
  NS_SCRIPTABLE NS_IMETHOD GetSourceNode(nsIDOMNode * *aSourceNode) { return _to GetSourceNode(aSourceNode); } 

/* Use this macro to declare functions that forward the behavior of this interface to another object in a safe way. */
#define NS_FORWARD_SAFE_NSIXSLTEXCEPTION(_to) \
  NS_SCRIPTABLE NS_IMETHOD GetStyleNode(nsIDOMNode * *aStyleNode) { return !_to ? NS_ERROR_NULL_POINTER : _to->GetStyleNode(aStyleNode); } \
  NS_SCRIPTABLE NS_IMETHOD GetSourceNode(nsIDOMNode * *aSourceNode) { return !_to ? NS_ERROR_NULL_POINTER : _to->GetSourceNode(aSourceNode); } 

#if 0
/* Use the code below as a template for the implementation class for this interface. */

/* Header file */
class nsXSLTException : public nsIXSLTException
{
public:
  NS_DECL_ISUPPORTS
  NS_DECL_NSIXSLTEXCEPTION

  nsXSLTException();

private:
  ~nsXSLTException();

protected:
  /* additional members */
};

/* Implementation file */
NS_IMPL_ISUPPORTS1(nsXSLTException, nsIXSLTException)

nsXSLTException::nsXSLTException()
{
  /* member initializers and constructor code */
}

nsXSLTException::~nsXSLTException()
{
  /* destructor code */
}

/* readonly attribute nsIDOMNode styleNode; */
NS_IMETHODIMP nsXSLTException::GetStyleNode(nsIDOMNode * *aStyleNode)
{
    return NS_ERROR_NOT_IMPLEMENTED;
}

/* readonly attribute nsIDOMNode sourceNode; */
NS_IMETHODIMP nsXSLTException::GetSourceNode(nsIDOMNode * *aSourceNode)
{
    return NS_ERROR_NOT_IMPLEMENTED;
}

/* End of implementation class template. */
#endif


#endif /* __gen_nsIXSLTException_h__ */
