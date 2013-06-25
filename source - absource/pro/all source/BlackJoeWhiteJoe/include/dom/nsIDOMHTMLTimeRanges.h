/*
 * DO NOT EDIT.  THIS FILE IS GENERATED FROM e:/builds/moz2_slave/mozilla-1.9.1-win32-xulrunner/build/dom/public/idl/html/nsIDOMHTMLTimeRanges.idl
 */

#ifndef __gen_nsIDOMHTMLTimeRanges_h__
#define __gen_nsIDOMHTMLTimeRanges_h__


#ifndef __gen_domstubs_h__
#include "domstubs.h"
#endif

/* For IDL files that don't want to include root IDL files. */
#ifndef NS_NO_VTABLE
#define NS_NO_VTABLE
#endif

/* starting interface:    nsIDOMHTMLTimeRanges */
#define NS_IDOMHTMLTIMERANGES_IID_STR "5c9995a1-9fce-44e8-aa7f-de52ff4c3f46"

#define NS_IDOMHTMLTIMERANGES_IID \
  {0x5c9995a1, 0x9fce, 0x44e8, \
    { 0xaa, 0x7f, 0xde, 0x52, 0xff, 0x4c, 0x3f, 0x46 }}

class NS_NO_VTABLE NS_SCRIPTABLE nsIDOMHTMLTimeRanges : public nsISupports {
 public: 

  NS_DECLARE_STATIC_IID_ACCESSOR(NS_IDOMHTMLTIMERANGES_IID)

  /* readonly attribute unsigned long length; */
  NS_SCRIPTABLE NS_IMETHOD GetLength(PRUint32 *aLength) = 0;

  /* float start (in unsigned long index); */
  NS_SCRIPTABLE NS_IMETHOD Start(PRUint32 index, float *_retval NS_OUTPARAM) = 0;

  /* float end (in unsigned long index); */
  NS_SCRIPTABLE NS_IMETHOD End(PRUint32 index, float *_retval NS_OUTPARAM) = 0;

};

  NS_DEFINE_STATIC_IID_ACCESSOR(nsIDOMHTMLTimeRanges, NS_IDOMHTMLTIMERANGES_IID)

/* Use this macro when declaring classes that implement this interface. */
#define NS_DECL_NSIDOMHTMLTIMERANGES \
  NS_SCRIPTABLE NS_IMETHOD GetLength(PRUint32 *aLength); \
  NS_SCRIPTABLE NS_IMETHOD Start(PRUint32 index, float *_retval NS_OUTPARAM); \
  NS_SCRIPTABLE NS_IMETHOD End(PRUint32 index, float *_retval NS_OUTPARAM); 

/* Use this macro to declare functions that forward the behavior of this interface to another object. */
#define NS_FORWARD_NSIDOMHTMLTIMERANGES(_to) \
  NS_SCRIPTABLE NS_IMETHOD GetLength(PRUint32 *aLength) { return _to GetLength(aLength); } \
  NS_SCRIPTABLE NS_IMETHOD Start(PRUint32 index, float *_retval NS_OUTPARAM) { return _to Start(index, _retval); } \
  NS_SCRIPTABLE NS_IMETHOD End(PRUint32 index, float *_retval NS_OUTPARAM) { return _to End(index, _retval); } 

/* Use this macro to declare functions that forward the behavior of this interface to another object in a safe way. */
#define NS_FORWARD_SAFE_NSIDOMHTMLTIMERANGES(_to) \
  NS_SCRIPTABLE NS_IMETHOD GetLength(PRUint32 *aLength) { return !_to ? NS_ERROR_NULL_POINTER : _to->GetLength(aLength); } \
  NS_SCRIPTABLE NS_IMETHOD Start(PRUint32 index, float *_retval NS_OUTPARAM) { return !_to ? NS_ERROR_NULL_POINTER : _to->Start(index, _retval); } \
  NS_SCRIPTABLE NS_IMETHOD End(PRUint32 index, float *_retval NS_OUTPARAM) { return !_to ? NS_ERROR_NULL_POINTER : _to->End(index, _retval); } 

#if 0
/* Use the code below as a template for the implementation class for this interface. */

/* Header file */
class nsDOMHTMLTimeRanges : public nsIDOMHTMLTimeRanges
{
public:
  NS_DECL_ISUPPORTS
  NS_DECL_NSIDOMHTMLTIMERANGES

  nsDOMHTMLTimeRanges();

private:
  ~nsDOMHTMLTimeRanges();

protected:
  /* additional members */
};

/* Implementation file */
NS_IMPL_ISUPPORTS1(nsDOMHTMLTimeRanges, nsIDOMHTMLTimeRanges)

nsDOMHTMLTimeRanges::nsDOMHTMLTimeRanges()
{
  /* member initializers and constructor code */
}

nsDOMHTMLTimeRanges::~nsDOMHTMLTimeRanges()
{
  /* destructor code */
}

/* readonly attribute unsigned long length; */
NS_IMETHODIMP nsDOMHTMLTimeRanges::GetLength(PRUint32 *aLength)
{
    return NS_ERROR_NOT_IMPLEMENTED;
}

/* float start (in unsigned long index); */
NS_IMETHODIMP nsDOMHTMLTimeRanges::Start(PRUint32 index, float *_retval NS_OUTPARAM)
{
    return NS_ERROR_NOT_IMPLEMENTED;
}

/* float end (in unsigned long index); */
NS_IMETHODIMP nsDOMHTMLTimeRanges::End(PRUint32 index, float *_retval NS_OUTPARAM)
{
    return NS_ERROR_NOT_IMPLEMENTED;
}

/* End of implementation class template. */
#endif


#endif /* __gen_nsIDOMHTMLTimeRanges_h__ */
