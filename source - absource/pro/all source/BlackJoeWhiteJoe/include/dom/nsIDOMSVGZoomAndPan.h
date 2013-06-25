/*
 * DO NOT EDIT.  THIS FILE IS GENERATED FROM e:/builds/moz2_slave/mozilla-1.9.1-win32-xulrunner/build/dom/public/idl/svg/nsIDOMSVGZoomAndPan.idl
 */

#ifndef __gen_nsIDOMSVGZoomAndPan_h__
#define __gen_nsIDOMSVGZoomAndPan_h__


#ifndef __gen_domstubs_h__
#include "domstubs.h"
#endif

/* For IDL files that don't want to include root IDL files. */
#ifndef NS_NO_VTABLE
#define NS_NO_VTABLE
#endif

/* starting interface:    nsIDOMSVGZoomAndPan */
#define NS_IDOMSVGZOOMANDPAN_IID_STR "18967370-921a-4245-8158-a279b190abca"

#define NS_IDOMSVGZOOMANDPAN_IID \
  {0x18967370, 0x921a, 0x4245, \
    { 0x81, 0x58, 0xa2, 0x79, 0xb1, 0x90, 0xab, 0xca }}

class NS_NO_VTABLE NS_SCRIPTABLE nsIDOMSVGZoomAndPan : public nsISupports {
 public: 

  NS_DECLARE_STATIC_IID_ACCESSOR(NS_IDOMSVGZOOMANDPAN_IID)

  enum { SVG_ZOOMANDPAN_UNKNOWN = 0U };

  enum { SVG_ZOOMANDPAN_DISABLE = 1U };

  enum { SVG_ZOOMANDPAN_MAGNIFY = 2U };

  /* attribute unsigned short zoomAndPan; */
  NS_SCRIPTABLE NS_IMETHOD GetZoomAndPan(PRUint16 *aZoomAndPan) = 0;
  NS_SCRIPTABLE NS_IMETHOD SetZoomAndPan(PRUint16 aZoomAndPan) = 0;

};

  NS_DEFINE_STATIC_IID_ACCESSOR(nsIDOMSVGZoomAndPan, NS_IDOMSVGZOOMANDPAN_IID)

/* Use this macro when declaring classes that implement this interface. */
#define NS_DECL_NSIDOMSVGZOOMANDPAN \
  NS_SCRIPTABLE NS_IMETHOD GetZoomAndPan(PRUint16 *aZoomAndPan); \
  NS_SCRIPTABLE NS_IMETHOD SetZoomAndPan(PRUint16 aZoomAndPan); 

/* Use this macro to declare functions that forward the behavior of this interface to another object. */
#define NS_FORWARD_NSIDOMSVGZOOMANDPAN(_to) \
  NS_SCRIPTABLE NS_IMETHOD GetZoomAndPan(PRUint16 *aZoomAndPan) { return _to GetZoomAndPan(aZoomAndPan); } \
  NS_SCRIPTABLE NS_IMETHOD SetZoomAndPan(PRUint16 aZoomAndPan) { return _to SetZoomAndPan(aZoomAndPan); } 

/* Use this macro to declare functions that forward the behavior of this interface to another object in a safe way. */
#define NS_FORWARD_SAFE_NSIDOMSVGZOOMANDPAN(_to) \
  NS_SCRIPTABLE NS_IMETHOD GetZoomAndPan(PRUint16 *aZoomAndPan) { return !_to ? NS_ERROR_NULL_POINTER : _to->GetZoomAndPan(aZoomAndPan); } \
  NS_SCRIPTABLE NS_IMETHOD SetZoomAndPan(PRUint16 aZoomAndPan) { return !_to ? NS_ERROR_NULL_POINTER : _to->SetZoomAndPan(aZoomAndPan); } 

#if 0
/* Use the code below as a template for the implementation class for this interface. */

/* Header file */
class nsDOMSVGZoomAndPan : public nsIDOMSVGZoomAndPan
{
public:
  NS_DECL_ISUPPORTS
  NS_DECL_NSIDOMSVGZOOMANDPAN

  nsDOMSVGZoomAndPan();

private:
  ~nsDOMSVGZoomAndPan();

protected:
  /* additional members */
};

/* Implementation file */
NS_IMPL_ISUPPORTS1(nsDOMSVGZoomAndPan, nsIDOMSVGZoomAndPan)

nsDOMSVGZoomAndPan::nsDOMSVGZoomAndPan()
{
  /* member initializers and constructor code */
}

nsDOMSVGZoomAndPan::~nsDOMSVGZoomAndPan()
{
  /* destructor code */
}

/* attribute unsigned short zoomAndPan; */
NS_IMETHODIMP nsDOMSVGZoomAndPan::GetZoomAndPan(PRUint16 *aZoomAndPan)
{
    return NS_ERROR_NOT_IMPLEMENTED;
}
NS_IMETHODIMP nsDOMSVGZoomAndPan::SetZoomAndPan(PRUint16 aZoomAndPan)
{
    return NS_ERROR_NOT_IMPLEMENTED;
}

/* End of implementation class template. */
#endif


#endif /* __gen_nsIDOMSVGZoomAndPan_h__ */
