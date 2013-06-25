/*
 * DO NOT EDIT.  THIS FILE IS GENERATED FROM e:/builds/moz2_slave/mozilla-1.9.1-win32-xulrunner/build/dom/public/idl/ls/nsIDOMLSSerializerFilter.idl
 */

#ifndef __gen_nsIDOMLSSerializerFilter_h__
#define __gen_nsIDOMLSSerializerFilter_h__


#ifndef __gen_nsIDOMNodeFilter_h__
#include "nsIDOMNodeFilter.h"
#endif

/* For IDL files that don't want to include root IDL files. */
#ifndef NS_NO_VTABLE
#define NS_NO_VTABLE
#endif

/* starting interface:    nsIDOMLSSerializerFilter */
#define NS_IDOMLSSERIALIZERFILTER_IID_STR "b9b6ec85-f69f-4a5a-a96a-8a7a8f07e2b4"

#define NS_IDOMLSSERIALIZERFILTER_IID \
  {0xb9b6ec85, 0xf69f, 0x4a5a, \
    { 0xa9, 0x6a, 0x8a, 0x7a, 0x8f, 0x07, 0xe2, 0xb4 }}

class NS_NO_VTABLE NS_SCRIPTABLE nsIDOMLSSerializerFilter : public nsIDOMNodeFilter {
 public: 

  NS_DECLARE_STATIC_IID_ACCESSOR(NS_IDOMLSSERIALIZERFILTER_IID)

  /* readonly attribute unsigned long whatToShow; */
  NS_SCRIPTABLE NS_IMETHOD GetWhatToShow(PRUint32 *aWhatToShow) = 0;

};

  NS_DEFINE_STATIC_IID_ACCESSOR(nsIDOMLSSerializerFilter, NS_IDOMLSSERIALIZERFILTER_IID)

/* Use this macro when declaring classes that implement this interface. */
#define NS_DECL_NSIDOMLSSERIALIZERFILTER \
  NS_SCRIPTABLE NS_IMETHOD GetWhatToShow(PRUint32 *aWhatToShow); 

/* Use this macro to declare functions that forward the behavior of this interface to another object. */
#define NS_FORWARD_NSIDOMLSSERIALIZERFILTER(_to) \
  NS_SCRIPTABLE NS_IMETHOD GetWhatToShow(PRUint32 *aWhatToShow) { return _to GetWhatToShow(aWhatToShow); } 

/* Use this macro to declare functions that forward the behavior of this interface to another object in a safe way. */
#define NS_FORWARD_SAFE_NSIDOMLSSERIALIZERFILTER(_to) \
  NS_SCRIPTABLE NS_IMETHOD GetWhatToShow(PRUint32 *aWhatToShow) { return !_to ? NS_ERROR_NULL_POINTER : _to->GetWhatToShow(aWhatToShow); } 

#if 0
/* Use the code below as a template for the implementation class for this interface. */

/* Header file */
class nsDOMLSSerializerFilter : public nsIDOMLSSerializerFilter
{
public:
  NS_DECL_ISUPPORTS
  NS_DECL_NSIDOMLSSERIALIZERFILTER

  nsDOMLSSerializerFilter();

private:
  ~nsDOMLSSerializerFilter();

protected:
  /* additional members */
};

/* Implementation file */
NS_IMPL_ISUPPORTS1(nsDOMLSSerializerFilter, nsIDOMLSSerializerFilter)

nsDOMLSSerializerFilter::nsDOMLSSerializerFilter()
{
  /* member initializers and constructor code */
}

nsDOMLSSerializerFilter::~nsDOMLSSerializerFilter()
{
  /* destructor code */
}

/* readonly attribute unsigned long whatToShow; */
NS_IMETHODIMP nsDOMLSSerializerFilter::GetWhatToShow(PRUint32 *aWhatToShow)
{
    return NS_ERROR_NOT_IMPLEMENTED;
}

/* End of implementation class template. */
#endif


#endif /* __gen_nsIDOMLSSerializerFilter_h__ */
