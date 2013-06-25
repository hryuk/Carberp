/*
 * DO NOT EDIT.  THIS FILE IS GENERATED FROM e:/builds/moz2_slave/mozilla-1.9.1-win32-xulrunner/build/rdf/base/idl/nsIRDFNode.idl
 */

#ifndef __gen_nsIRDFNode_h__
#define __gen_nsIRDFNode_h__


#ifndef __gen_nsISupports_h__
#include "nsISupports.h"
#endif

/* For IDL files that don't want to include root IDL files. */
#ifndef NS_NO_VTABLE
#define NS_NO_VTABLE
#endif

/* starting interface:    nsIRDFNode */
#define NS_IRDFNODE_IID_STR "0f78da50-8321-11d2-8eac-00805f29f370"

#define NS_IRDFNODE_IID \
  {0x0f78da50, 0x8321, 0x11d2, \
    { 0x8e, 0xac, 0x00, 0x80, 0x5f, 0x29, 0xf3, 0x70 }}

class NS_NO_VTABLE NS_SCRIPTABLE nsIRDFNode : public nsISupports {
 public: 

  NS_DECLARE_STATIC_IID_ACCESSOR(NS_IRDFNODE_IID)

  /* boolean EqualsNode (in nsIRDFNode aNode); */
  NS_SCRIPTABLE NS_IMETHOD EqualsNode(nsIRDFNode *aNode, PRBool *_retval NS_OUTPARAM) = 0;

};

  NS_DEFINE_STATIC_IID_ACCESSOR(nsIRDFNode, NS_IRDFNODE_IID)

/* Use this macro when declaring classes that implement this interface. */
#define NS_DECL_NSIRDFNODE \
  NS_SCRIPTABLE NS_IMETHOD EqualsNode(nsIRDFNode *aNode, PRBool *_retval NS_OUTPARAM); 

/* Use this macro to declare functions that forward the behavior of this interface to another object. */
#define NS_FORWARD_NSIRDFNODE(_to) \
  NS_SCRIPTABLE NS_IMETHOD EqualsNode(nsIRDFNode *aNode, PRBool *_retval NS_OUTPARAM) { return _to EqualsNode(aNode, _retval); } 

/* Use this macro to declare functions that forward the behavior of this interface to another object in a safe way. */
#define NS_FORWARD_SAFE_NSIRDFNODE(_to) \
  NS_SCRIPTABLE NS_IMETHOD EqualsNode(nsIRDFNode *aNode, PRBool *_retval NS_OUTPARAM) { return !_to ? NS_ERROR_NULL_POINTER : _to->EqualsNode(aNode, _retval); } 

#if 0
/* Use the code below as a template for the implementation class for this interface. */

/* Header file */
class nsRDFNode : public nsIRDFNode
{
public:
  NS_DECL_ISUPPORTS
  NS_DECL_NSIRDFNODE

  nsRDFNode();

private:
  ~nsRDFNode();

protected:
  /* additional members */
};

/* Implementation file */
NS_IMPL_ISUPPORTS1(nsRDFNode, nsIRDFNode)

nsRDFNode::nsRDFNode()
{
  /* member initializers and constructor code */
}

nsRDFNode::~nsRDFNode()
{
  /* destructor code */
}

/* boolean EqualsNode (in nsIRDFNode aNode); */
NS_IMETHODIMP nsRDFNode::EqualsNode(nsIRDFNode *aNode, PRBool *_retval NS_OUTPARAM)
{
    return NS_ERROR_NOT_IMPLEMENTED;
}

/* End of implementation class template. */
#endif


#endif /* __gen_nsIRDFNode_h__ */
