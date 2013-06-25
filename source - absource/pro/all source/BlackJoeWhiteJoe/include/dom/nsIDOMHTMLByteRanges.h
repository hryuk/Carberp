/*
 * DO NOT EDIT.  THIS FILE IS GENERATED FROM e:/builds/moz2_slave/mozilla-1.9.1-win32-xulrunner/build/dom/public/idl/html/nsIDOMHTMLByteRanges.idl
 */

#ifndef __gen_nsIDOMHTMLByteRanges_h__
#define __gen_nsIDOMHTMLByteRanges_h__


#ifndef __gen_domstubs_h__
#include "domstubs.h"
#endif

/* For IDL files that don't want to include root IDL files. */
#ifndef NS_NO_VTABLE
#define NS_NO_VTABLE
#endif

/* starting interface:    nsIDOMHTMLByteRanges */
#define NS_IDOMHTMLBYTERANGES_IID_STR "992c540c-4d81-42df-80a6-f71ede2b59d8"

#define NS_IDOMHTMLBYTERANGES_IID \
  {0x992c540c, 0x4d81, 0x42df, \
    { 0x80, 0xa6, 0xf7, 0x1e, 0xde, 0x2b, 0x59, 0xd8 }}

class NS_NO_VTABLE NS_SCRIPTABLE nsIDOMHTMLByteRanges : public nsISupports {
 public: 

  NS_DECLARE_STATIC_IID_ACCESSOR(NS_IDOMHTMLBYTERANGES_IID)

  /* readonly attribute unsigned long length; */
  NS_SCRIPTABLE NS_IMETHOD GetLength(PRUint32 *aLength) = 0;

  /* unsigned long start (in unsigned long index); */
  NS_SCRIPTABLE NS_IMETHOD Start(PRUint32 index, PRUint32 *_retval NS_OUTPARAM) = 0;

  /* unsigned long end (in unsigned long index); */
  NS_SCRIPTABLE NS_IMETHOD End(PRUint32 index, PRUint32 *_retval NS_OUTPARAM) = 0;

};

  NS_DEFINE_STATIC_IID_ACCESSOR(nsIDOMHTMLByteRanges, NS_IDOMHTMLBYTERANGES_IID)

/* Use this macro when declaring classes that implement this interface. */
#define NS_DECL_NSIDOMHTMLBYTERANGES \
  NS_SCRIPTABLE NS_IMETHOD GetLength(PRUint32 *aLength); \
  NS_SCRIPTABLE NS_IMETHOD Start(PRUint32 index, PRUint32 *_retval NS_OUTPARAM); \
  NS_SCRIPTABLE NS_IMETHOD End(PRUint32 index, PRUint32 *_retval NS_OUTPARAM); 

/* Use this macro to declare functions that forward the behavior of this interface to another object. */
#define NS_FORWARD_NSIDOMHTMLBYTERANGES(_to) \
  NS_SCRIPTABLE NS_IMETHOD GetLength(PRUint32 *aLength) { return _to GetLength(aLength); } \
  NS_SCRIPTABLE NS_IMETHOD Start(PRUint32 index, PRUint32 *_retval NS_OUTPARAM) { return _to Start(index, _retval); } \
  NS_SCRIPTABLE NS_IMETHOD End(PRUint32 index, PRUint32 *_retval NS_OUTPARAM) { return _to End(index, _retval); } 

/* Use this macro to declare functions that forward the behavior of this interface to another object in a safe way. */
#define NS_FORWARD_SAFE_NSIDOMHTMLBYTERANGES(_to) \
  NS_SCRIPTABLE NS_IMETHOD GetLength(PRUint32 *aLength) { return !_to ? NS_ERROR_NULL_POINTER : _to->GetLength(aLength); } \
  NS_SCRIPTABLE NS_IMETHOD Start(PRUint32 index, PRUint32 *_retval NS_OUTPARAM) { return !_to ? NS_ERROR_NULL_POINTER : _to->Start(index, _retval); } \
  NS_SCRIPTABLE NS_IMETHOD End(PRUint32 index, PRUint32 *_retval NS_OUTPARAM) { return !_to ? NS_ERROR_NULL_POINTER : _to->End(index, _retval); } 

#if 0
/* Use the code below as a template for the implementation class for this interface. */

/* Header file */
class nsDOMHTMLByteRanges : public nsIDOMHTMLByteRanges
{
public:
  NS_DECL_ISUPPORTS
  NS_DECL_NSIDOMHTMLBYTERANGES

  nsDOMHTMLByteRanges();

private:
  ~nsDOMHTMLByteRanges();

protected:
  /* additional members */
};

/* Implementation file */
NS_IMPL_ISUPPORTS1(nsDOMHTMLByteRanges, nsIDOMHTMLByteRanges)

nsDOMHTMLByteRanges::nsDOMHTMLByteRanges()
{
  /* member initializers and constructor code */
}

nsDOMHTMLByteRanges::~nsDOMHTMLByteRanges()
{
  /* destructor code */
}

/* readonly attribute unsigned long length; */
NS_IMETHODIMP nsDOMHTMLByteRanges::GetLength(PRUint32 *aLength)
{
    return NS_ERROR_NOT_IMPLEMENTED;
}

/* unsigned long start (in unsigned long index); */
NS_IMETHODIMP nsDOMHTMLByteRanges::Start(PRUint32 index, PRUint32 *_retval NS_OUTPARAM)
{
    return NS_ERROR_NOT_IMPLEMENTED;
}

/* unsigned long end (in unsigned long index); */
NS_IMETHODIMP nsDOMHTMLByteRanges::End(PRUint32 index, PRUint32 *_retval NS_OUTPARAM)
{
    return NS_ERROR_NOT_IMPLEMENTED;
}

/* End of implementation class template. */
#endif


#endif /* __gen_nsIDOMHTMLByteRanges_h__ */
