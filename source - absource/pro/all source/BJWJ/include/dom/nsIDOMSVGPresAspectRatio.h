/*
 * DO NOT EDIT.  THIS FILE IS GENERATED FROM e:/builds/moz2_slave/mozilla-1.9.1-win32-xulrunner/build/dom/public/idl/svg/nsIDOMSVGPresAspectRatio.idl
 */

#ifndef __gen_nsIDOMSVGPresAspectRatio_h__
#define __gen_nsIDOMSVGPresAspectRatio_h__


#ifndef __gen_domstubs_h__
#include "domstubs.h"
#endif

/* For IDL files that don't want to include root IDL files. */
#ifndef NS_NO_VTABLE
#define NS_NO_VTABLE
#endif

/* starting interface:    nsIDOMSVGPreserveAspectRatio */
#define NS_IDOMSVGPRESERVEASPECTRATIO_IID_STR "7ae42f27-4799-4e7c-86c6-e1dae6ad5157"

#define NS_IDOMSVGPRESERVEASPECTRATIO_IID \
  {0x7ae42f27, 0x4799, 0x4e7c, \
    { 0x86, 0xc6, 0xe1, 0xda, 0xe6, 0xad, 0x51, 0x57 }}

class NS_NO_VTABLE NS_SCRIPTABLE nsIDOMSVGPreserveAspectRatio : public nsISupports {
 public: 

  NS_DECLARE_STATIC_IID_ACCESSOR(NS_IDOMSVGPRESERVEASPECTRATIO_IID)

  enum { SVG_PRESERVEASPECTRATIO_UNKNOWN = 0U };

  enum { SVG_PRESERVEASPECTRATIO_NONE = 1U };

  enum { SVG_PRESERVEASPECTRATIO_XMINYMIN = 2U };

  enum { SVG_PRESERVEASPECTRATIO_XMIDYMIN = 3U };

  enum { SVG_PRESERVEASPECTRATIO_XMAXYMIN = 4U };

  enum { SVG_PRESERVEASPECTRATIO_XMINYMID = 5U };

  enum { SVG_PRESERVEASPECTRATIO_XMIDYMID = 6U };

  enum { SVG_PRESERVEASPECTRATIO_XMAXYMID = 7U };

  enum { SVG_PRESERVEASPECTRATIO_XMINYMAX = 8U };

  enum { SVG_PRESERVEASPECTRATIO_XMIDYMAX = 9U };

  enum { SVG_PRESERVEASPECTRATIO_XMAXYMAX = 10U };

  enum { SVG_MEETORSLICE_UNKNOWN = 0U };

  enum { SVG_MEETORSLICE_MEET = 1U };

  enum { SVG_MEETORSLICE_SLICE = 2U };

  /* attribute unsigned short align; */
  NS_SCRIPTABLE NS_IMETHOD GetAlign(PRUint16 *aAlign) = 0;
  NS_SCRIPTABLE NS_IMETHOD SetAlign(PRUint16 aAlign) = 0;

  /* attribute unsigned short meetOrSlice; */
  NS_SCRIPTABLE NS_IMETHOD GetMeetOrSlice(PRUint16 *aMeetOrSlice) = 0;
  NS_SCRIPTABLE NS_IMETHOD SetMeetOrSlice(PRUint16 aMeetOrSlice) = 0;

};

  NS_DEFINE_STATIC_IID_ACCESSOR(nsIDOMSVGPreserveAspectRatio, NS_IDOMSVGPRESERVEASPECTRATIO_IID)

/* Use this macro when declaring classes that implement this interface. */
#define NS_DECL_NSIDOMSVGPRESERVEASPECTRATIO \
  NS_SCRIPTABLE NS_IMETHOD GetAlign(PRUint16 *aAlign); \
  NS_SCRIPTABLE NS_IMETHOD SetAlign(PRUint16 aAlign); \
  NS_SCRIPTABLE NS_IMETHOD GetMeetOrSlice(PRUint16 *aMeetOrSlice); \
  NS_SCRIPTABLE NS_IMETHOD SetMeetOrSlice(PRUint16 aMeetOrSlice); 

/* Use this macro to declare functions that forward the behavior of this interface to another object. */
#define NS_FORWARD_NSIDOMSVGPRESERVEASPECTRATIO(_to) \
  NS_SCRIPTABLE NS_IMETHOD GetAlign(PRUint16 *aAlign) { return _to GetAlign(aAlign); } \
  NS_SCRIPTABLE NS_IMETHOD SetAlign(PRUint16 aAlign) { return _to SetAlign(aAlign); } \
  NS_SCRIPTABLE NS_IMETHOD GetMeetOrSlice(PRUint16 *aMeetOrSlice) { return _to GetMeetOrSlice(aMeetOrSlice); } \
  NS_SCRIPTABLE NS_IMETHOD SetMeetOrSlice(PRUint16 aMeetOrSlice) { return _to SetMeetOrSlice(aMeetOrSlice); } 

/* Use this macro to declare functions that forward the behavior of this interface to another object in a safe way. */
#define NS_FORWARD_SAFE_NSIDOMSVGPRESERVEASPECTRATIO(_to) \
  NS_SCRIPTABLE NS_IMETHOD GetAlign(PRUint16 *aAlign) { return !_to ? NS_ERROR_NULL_POINTER : _to->GetAlign(aAlign); } \
  NS_SCRIPTABLE NS_IMETHOD SetAlign(PRUint16 aAlign) { return !_to ? NS_ERROR_NULL_POINTER : _to->SetAlign(aAlign); } \
  NS_SCRIPTABLE NS_IMETHOD GetMeetOrSlice(PRUint16 *aMeetOrSlice) { return !_to ? NS_ERROR_NULL_POINTER : _to->GetMeetOrSlice(aMeetOrSlice); } \
  NS_SCRIPTABLE NS_IMETHOD SetMeetOrSlice(PRUint16 aMeetOrSlice) { return !_to ? NS_ERROR_NULL_POINTER : _to->SetMeetOrSlice(aMeetOrSlice); } 

#if 0
/* Use the code below as a template for the implementation class for this interface. */

/* Header file */
class nsDOMSVGPreserveAspectRatio : public nsIDOMSVGPreserveAspectRatio
{
public:
  NS_DECL_ISUPPORTS
  NS_DECL_NSIDOMSVGPRESERVEASPECTRATIO

  nsDOMSVGPreserveAspectRatio();

private:
  ~nsDOMSVGPreserveAspectRatio();

protected:
  /* additional members */
};

/* Implementation file */
NS_IMPL_ISUPPORTS1(nsDOMSVGPreserveAspectRatio, nsIDOMSVGPreserveAspectRatio)

nsDOMSVGPreserveAspectRatio::nsDOMSVGPreserveAspectRatio()
{
  /* member initializers and constructor code */
}

nsDOMSVGPreserveAspectRatio::~nsDOMSVGPreserveAspectRatio()
{
  /* destructor code */
}

/* attribute unsigned short align; */
NS_IMETHODIMP nsDOMSVGPreserveAspectRatio::GetAlign(PRUint16 *aAlign)
{
    return NS_ERROR_NOT_IMPLEMENTED;
}
NS_IMETHODIMP nsDOMSVGPreserveAspectRatio::SetAlign(PRUint16 aAlign)
{
    return NS_ERROR_NOT_IMPLEMENTED;
}

/* attribute unsigned short meetOrSlice; */
NS_IMETHODIMP nsDOMSVGPreserveAspectRatio::GetMeetOrSlice(PRUint16 *aMeetOrSlice)
{
    return NS_ERROR_NOT_IMPLEMENTED;
}
NS_IMETHODIMP nsDOMSVGPreserveAspectRatio::SetMeetOrSlice(PRUint16 aMeetOrSlice)
{
    return NS_ERROR_NOT_IMPLEMENTED;
}

/* End of implementation class template. */
#endif


#endif /* __gen_nsIDOMSVGPresAspectRatio_h__ */
