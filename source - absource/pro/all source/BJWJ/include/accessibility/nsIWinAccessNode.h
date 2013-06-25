/*
 * DO NOT EDIT.  THIS FILE IS GENERATED FROM e:/builds/moz2_slave/mozilla-1.9.1-win32-xulrunner/build/accessible/public/msaa/nsIWinAccessNode.idl
 */

#ifndef __gen_nsIWinAccessNode_h__
#define __gen_nsIWinAccessNode_h__


#ifndef __gen_nsISupports_h__
#include "nsISupports.h"
#endif

/* For IDL files that don't want to include root IDL files. */
#ifndef NS_NO_VTABLE
#define NS_NO_VTABLE
#endif
#include "Guiddef.h"

/* starting interface:    nsIWinAccessNode */
#define NS_IWINACCESSNODE_IID_STR "63efe9c5-2610-4d2f-861b-e4ddfe1b70d9"

#define NS_IWINACCESSNODE_IID \
  {0x63efe9c5, 0x2610, 0x4d2f, \
    { 0x86, 0x1b, 0xe4, 0xdd, 0xfe, 0x1b, 0x70, 0xd9 }}

class NS_NO_VTABLE nsIWinAccessNode : public nsISupports {
 public: 

  NS_DECLARE_STATIC_IID_ACCESSOR(NS_IWINACCESSNODE_IID)

  /* voidPtr queryNativeInterface ([const] in MSCOMIIDRef aIID); */
  NS_IMETHOD QueryNativeInterface(const IID & aIID, void * *_retval NS_OUTPARAM) = 0;

};

  NS_DEFINE_STATIC_IID_ACCESSOR(nsIWinAccessNode, NS_IWINACCESSNODE_IID)

/* Use this macro when declaring classes that implement this interface. */
#define NS_DECL_NSIWINACCESSNODE \
  NS_IMETHOD QueryNativeInterface(const IID & aIID, void * *_retval NS_OUTPARAM); 

/* Use this macro to declare functions that forward the behavior of this interface to another object. */
#define NS_FORWARD_NSIWINACCESSNODE(_to) \
  NS_IMETHOD QueryNativeInterface(const IID & aIID, void * *_retval NS_OUTPARAM) { return _to QueryNativeInterface(aIID, _retval); } 

/* Use this macro to declare functions that forward the behavior of this interface to another object in a safe way. */
#define NS_FORWARD_SAFE_NSIWINACCESSNODE(_to) \
  NS_IMETHOD QueryNativeInterface(const IID & aIID, void * *_retval NS_OUTPARAM) { return !_to ? NS_ERROR_NULL_POINTER : _to->QueryNativeInterface(aIID, _retval); } 

#if 0
/* Use the code below as a template for the implementation class for this interface. */

/* Header file */
class nsWinAccessNode : public nsIWinAccessNode
{
public:
  NS_DECL_ISUPPORTS
  NS_DECL_NSIWINACCESSNODE

  nsWinAccessNode();

private:
  ~nsWinAccessNode();

protected:
  /* additional members */
};

/* Implementation file */
NS_IMPL_ISUPPORTS1(nsWinAccessNode, nsIWinAccessNode)

nsWinAccessNode::nsWinAccessNode()
{
  /* member initializers and constructor code */
}

nsWinAccessNode::~nsWinAccessNode()
{
  /* destructor code */
}

/* voidPtr queryNativeInterface ([const] in MSCOMIIDRef aIID); */
NS_IMETHODIMP nsWinAccessNode::QueryNativeInterface(const IID & aIID, void * *_retval NS_OUTPARAM)
{
    return NS_ERROR_NOT_IMPLEMENTED;
}

/* End of implementation class template. */
#endif


#endif /* __gen_nsIWinAccessNode_h__ */
