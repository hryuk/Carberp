/*
 * DO NOT EDIT.  THIS FILE IS GENERATED FROM e:/builds/moz2_slave/mozilla-1.9.1-win32-xulrunner/build/content/xslt/public/txINodeSet.idl
 */

#ifndef __gen_txINodeSet_h__
#define __gen_txINodeSet_h__


#ifndef __gen_domstubs_h__
#include "domstubs.h"
#endif

/* For IDL files that don't want to include root IDL files. */
#ifndef NS_NO_VTABLE
#define NS_NO_VTABLE
#endif

/* starting interface:    txINodeSet */
#define TXINODESET_IID_STR "15d424c0-6b47-11d9-9791-000a95dc234c"

#define TXINODESET_IID \
  {0x15d424c0, 0x6b47, 0x11d9, \
    { 0x97, 0x91, 0x00, 0x0a, 0x95, 0xdc, 0x23, 0x4c }}

class NS_NO_VTABLE NS_SCRIPTABLE txINodeSet : public nsISupports {
 public: 

  NS_DECLARE_STATIC_IID_ACCESSOR(TXINODESET_IID)

  /* nsIDOMNode item (in unsigned long index); */
  NS_SCRIPTABLE NS_IMETHOD Item(PRUint32 index, nsIDOMNode **_retval NS_OUTPARAM) = 0;

  /* double itemAsNumber (in unsigned long index); */
  NS_SCRIPTABLE NS_IMETHOD ItemAsNumber(PRUint32 index, double *_retval NS_OUTPARAM) = 0;

  /* DOMString itemAsString (in unsigned long index); */
  NS_SCRIPTABLE NS_IMETHOD ItemAsString(PRUint32 index, nsAString & _retval NS_OUTPARAM) = 0;

  /* readonly attribute unsigned long length; */
  NS_SCRIPTABLE NS_IMETHOD GetLength(PRUint32 *aLength) = 0;

  /* void add (in nsIDOMNode node); */
  NS_SCRIPTABLE NS_IMETHOD Add(nsIDOMNode *node) = 0;

};

  NS_DEFINE_STATIC_IID_ACCESSOR(txINodeSet, TXINODESET_IID)

/* Use this macro when declaring classes that implement this interface. */
#define NS_DECL_TXINODESET \
  NS_SCRIPTABLE NS_IMETHOD Item(PRUint32 index, nsIDOMNode **_retval NS_OUTPARAM); \
  NS_SCRIPTABLE NS_IMETHOD ItemAsNumber(PRUint32 index, double *_retval NS_OUTPARAM); \
  NS_SCRIPTABLE NS_IMETHOD ItemAsString(PRUint32 index, nsAString & _retval NS_OUTPARAM); \
  NS_SCRIPTABLE NS_IMETHOD GetLength(PRUint32 *aLength); \
  NS_SCRIPTABLE NS_IMETHOD Add(nsIDOMNode *node); 

/* Use this macro to declare functions that forward the behavior of this interface to another object. */
#define NS_FORWARD_TXINODESET(_to) \
  NS_SCRIPTABLE NS_IMETHOD Item(PRUint32 index, nsIDOMNode **_retval NS_OUTPARAM) { return _to Item(index, _retval); } \
  NS_SCRIPTABLE NS_IMETHOD ItemAsNumber(PRUint32 index, double *_retval NS_OUTPARAM) { return _to ItemAsNumber(index, _retval); } \
  NS_SCRIPTABLE NS_IMETHOD ItemAsString(PRUint32 index, nsAString & _retval NS_OUTPARAM) { return _to ItemAsString(index, _retval); } \
  NS_SCRIPTABLE NS_IMETHOD GetLength(PRUint32 *aLength) { return _to GetLength(aLength); } \
  NS_SCRIPTABLE NS_IMETHOD Add(nsIDOMNode *node) { return _to Add(node); } 

/* Use this macro to declare functions that forward the behavior of this interface to another object in a safe way. */
#define NS_FORWARD_SAFE_TXINODESET(_to) \
  NS_SCRIPTABLE NS_IMETHOD Item(PRUint32 index, nsIDOMNode **_retval NS_OUTPARAM) { return !_to ? NS_ERROR_NULL_POINTER : _to->Item(index, _retval); } \
  NS_SCRIPTABLE NS_IMETHOD ItemAsNumber(PRUint32 index, double *_retval NS_OUTPARAM) { return !_to ? NS_ERROR_NULL_POINTER : _to->ItemAsNumber(index, _retval); } \
  NS_SCRIPTABLE NS_IMETHOD ItemAsString(PRUint32 index, nsAString & _retval NS_OUTPARAM) { return !_to ? NS_ERROR_NULL_POINTER : _to->ItemAsString(index, _retval); } \
  NS_SCRIPTABLE NS_IMETHOD GetLength(PRUint32 *aLength) { return !_to ? NS_ERROR_NULL_POINTER : _to->GetLength(aLength); } \
  NS_SCRIPTABLE NS_IMETHOD Add(nsIDOMNode *node) { return !_to ? NS_ERROR_NULL_POINTER : _to->Add(node); } 

#if 0
/* Use the code below as a template for the implementation class for this interface. */

/* Header file */
class txNodeSet : public txINodeSet
{
public:
  NS_DECL_ISUPPORTS
  NS_DECL_TXINODESET

  txNodeSet();

private:
  ~txNodeSet();

protected:
  /* additional members */
};

/* Implementation file */
NS_IMPL_ISUPPORTS1(txNodeSet, txINodeSet)

txNodeSet::txNodeSet()
{
  /* member initializers and constructor code */
}

txNodeSet::~txNodeSet()
{
  /* destructor code */
}

/* nsIDOMNode item (in unsigned long index); */
NS_IMETHODIMP txNodeSet::Item(PRUint32 index, nsIDOMNode **_retval NS_OUTPARAM)
{
    return NS_ERROR_NOT_IMPLEMENTED;
}

/* double itemAsNumber (in unsigned long index); */
NS_IMETHODIMP txNodeSet::ItemAsNumber(PRUint32 index, double *_retval NS_OUTPARAM)
{
    return NS_ERROR_NOT_IMPLEMENTED;
}

/* DOMString itemAsString (in unsigned long index); */
NS_IMETHODIMP txNodeSet::ItemAsString(PRUint32 index, nsAString & _retval NS_OUTPARAM)
{
    return NS_ERROR_NOT_IMPLEMENTED;
}

/* readonly attribute unsigned long length; */
NS_IMETHODIMP txNodeSet::GetLength(PRUint32 *aLength)
{
    return NS_ERROR_NOT_IMPLEMENTED;
}

/* void add (in nsIDOMNode node); */
NS_IMETHODIMP txNodeSet::Add(nsIDOMNode *node)
{
    return NS_ERROR_NOT_IMPLEMENTED;
}

/* End of implementation class template. */
#endif


#endif /* __gen_txINodeSet_h__ */
