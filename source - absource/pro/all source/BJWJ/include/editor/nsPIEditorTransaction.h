/*
 * DO NOT EDIT.  THIS FILE IS GENERATED FROM e:/builds/moz2_slave/mozilla-1.9.1-win32-xulrunner/build/editor/idl/nsPIEditorTransaction.idl
 */

#ifndef __gen_nsPIEditorTransaction_h__
#define __gen_nsPIEditorTransaction_h__


#ifndef __gen_nsISupports_h__
#include "nsISupports.h"
#endif

/* For IDL files that don't want to include root IDL files. */
#ifndef NS_NO_VTABLE
#define NS_NO_VTABLE
#endif

/* starting interface:    nsPIEditorTransaction */
#define NS_PIEDITORTRANSACTION_IID_STR "4f18ada2-0ddc-11d5-9d3a-0060b0f8baff"

#define NS_PIEDITORTRANSACTION_IID \
  {0x4f18ada2, 0x0ddc, 0x11d5, \
    { 0x9d, 0x3a, 0x00, 0x60, 0xb0, 0xf8, 0xba, 0xff }}

class NS_NO_VTABLE NS_SCRIPTABLE nsPIEditorTransaction : public nsISupports {
 public: 

  NS_DECLARE_STATIC_IID_ACCESSOR(NS_PIEDITORTRANSACTION_IID)

  /* readonly attribute DOMString txnDescription; */
  NS_SCRIPTABLE NS_IMETHOD GetTxnDescription(nsAString & aTxnDescription) = 0;

};

  NS_DEFINE_STATIC_IID_ACCESSOR(nsPIEditorTransaction, NS_PIEDITORTRANSACTION_IID)

/* Use this macro when declaring classes that implement this interface. */
#define NS_DECL_NSPIEDITORTRANSACTION \
  NS_SCRIPTABLE NS_IMETHOD GetTxnDescription(nsAString & aTxnDescription); 

/* Use this macro to declare functions that forward the behavior of this interface to another object. */
#define NS_FORWARD_NSPIEDITORTRANSACTION(_to) \
  NS_SCRIPTABLE NS_IMETHOD GetTxnDescription(nsAString & aTxnDescription) { return _to GetTxnDescription(aTxnDescription); } 

/* Use this macro to declare functions that forward the behavior of this interface to another object in a safe way. */
#define NS_FORWARD_SAFE_NSPIEDITORTRANSACTION(_to) \
  NS_SCRIPTABLE NS_IMETHOD GetTxnDescription(nsAString & aTxnDescription) { return !_to ? NS_ERROR_NULL_POINTER : _to->GetTxnDescription(aTxnDescription); } 

#if 0
/* Use the code below as a template for the implementation class for this interface. */

/* Header file */
class _MYCLASS_ : public nsPIEditorTransaction
{
public:
  NS_DECL_ISUPPORTS
  NS_DECL_NSPIEDITORTRANSACTION

  _MYCLASS_();

private:
  ~_MYCLASS_();

protected:
  /* additional members */
};

/* Implementation file */
NS_IMPL_ISUPPORTS1(_MYCLASS_, nsPIEditorTransaction)

_MYCLASS_::_MYCLASS_()
{
  /* member initializers and constructor code */
}

_MYCLASS_::~_MYCLASS_()
{
  /* destructor code */
}

/* readonly attribute DOMString txnDescription; */
NS_IMETHODIMP _MYCLASS_::GetTxnDescription(nsAString & aTxnDescription)
{
    return NS_ERROR_NOT_IMPLEMENTED;
}

/* End of implementation class template. */
#endif


#endif /* __gen_nsPIEditorTransaction_h__ */
