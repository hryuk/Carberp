/*
 * DO NOT EDIT.  THIS FILE IS GENERATED FROM e:/builds/moz2_slave/mozilla-1.9.1-win32-xulrunner/build/security/manager/pki/public/nsIPKIParamBlock.idl
 */

#ifndef __gen_nsIPKIParamBlock_h__
#define __gen_nsIPKIParamBlock_h__


#ifndef __gen_nsISupports_h__
#include "nsISupports.h"
#endif

/* For IDL files that don't want to include root IDL files. */
#ifndef NS_NO_VTABLE
#define NS_NO_VTABLE
#endif

/* starting interface:    nsIPKIParamBlock */
#define NS_IPKIPARAMBLOCK_IID_STR "b6fe3d78-1dd1-11b2-9058-ced9016984c8"

#define NS_IPKIPARAMBLOCK_IID \
  {0xb6fe3d78, 0x1dd1, 0x11b2, \
    { 0x90, 0x58, 0xce, 0xd9, 0x01, 0x69, 0x84, 0xc8 }}

class NS_NO_VTABLE NS_SCRIPTABLE nsIPKIParamBlock : public nsISupports {
 public: 

  NS_DECLARE_STATIC_IID_ACCESSOR(NS_IPKIPARAMBLOCK_IID)

  /* void setISupportAtIndex (in long index, in nsISupports object); */
  NS_SCRIPTABLE NS_IMETHOD SetISupportAtIndex(PRInt32 index, nsISupports *object) = 0;

  /* nsISupports getISupportAtIndex (in long index); */
  NS_SCRIPTABLE NS_IMETHOD GetISupportAtIndex(PRInt32 index, nsISupports **_retval NS_OUTPARAM) = 0;

};

  NS_DEFINE_STATIC_IID_ACCESSOR(nsIPKIParamBlock, NS_IPKIPARAMBLOCK_IID)

/* Use this macro when declaring classes that implement this interface. */
#define NS_DECL_NSIPKIPARAMBLOCK \
  NS_SCRIPTABLE NS_IMETHOD SetISupportAtIndex(PRInt32 index, nsISupports *object); \
  NS_SCRIPTABLE NS_IMETHOD GetISupportAtIndex(PRInt32 index, nsISupports **_retval NS_OUTPARAM); 

/* Use this macro to declare functions that forward the behavior of this interface to another object. */
#define NS_FORWARD_NSIPKIPARAMBLOCK(_to) \
  NS_SCRIPTABLE NS_IMETHOD SetISupportAtIndex(PRInt32 index, nsISupports *object) { return _to SetISupportAtIndex(index, object); } \
  NS_SCRIPTABLE NS_IMETHOD GetISupportAtIndex(PRInt32 index, nsISupports **_retval NS_OUTPARAM) { return _to GetISupportAtIndex(index, _retval); } 

/* Use this macro to declare functions that forward the behavior of this interface to another object in a safe way. */
#define NS_FORWARD_SAFE_NSIPKIPARAMBLOCK(_to) \
  NS_SCRIPTABLE NS_IMETHOD SetISupportAtIndex(PRInt32 index, nsISupports *object) { return !_to ? NS_ERROR_NULL_POINTER : _to->SetISupportAtIndex(index, object); } \
  NS_SCRIPTABLE NS_IMETHOD GetISupportAtIndex(PRInt32 index, nsISupports **_retval NS_OUTPARAM) { return !_to ? NS_ERROR_NULL_POINTER : _to->GetISupportAtIndex(index, _retval); } 

#if 0
/* Use the code below as a template for the implementation class for this interface. */

/* Header file */
class nsPKIParamBlock : public nsIPKIParamBlock
{
public:
  NS_DECL_ISUPPORTS
  NS_DECL_NSIPKIPARAMBLOCK

  nsPKIParamBlock();

private:
  ~nsPKIParamBlock();

protected:
  /* additional members */
};

/* Implementation file */
NS_IMPL_ISUPPORTS1(nsPKIParamBlock, nsIPKIParamBlock)

nsPKIParamBlock::nsPKIParamBlock()
{
  /* member initializers and constructor code */
}

nsPKIParamBlock::~nsPKIParamBlock()
{
  /* destructor code */
}

/* void setISupportAtIndex (in long index, in nsISupports object); */
NS_IMETHODIMP nsPKIParamBlock::SetISupportAtIndex(PRInt32 index, nsISupports *object)
{
    return NS_ERROR_NOT_IMPLEMENTED;
}

/* nsISupports getISupportAtIndex (in long index); */
NS_IMETHODIMP nsPKIParamBlock::GetISupportAtIndex(PRInt32 index, nsISupports **_retval NS_OUTPARAM)
{
    return NS_ERROR_NOT_IMPLEMENTED;
}

/* End of implementation class template. */
#endif


#endif /* __gen_nsIPKIParamBlock_h__ */
