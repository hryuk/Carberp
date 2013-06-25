/*
 * DO NOT EDIT.  THIS FILE IS GENERATED FROM e:/builds/moz2_slave/mozilla-1.9.1-win32-xulrunner/build/dom/public/idl/svg/nsIDOMSVGViewSpec.idl
 */

#ifndef __gen_nsIDOMSVGViewSpec_h__
#define __gen_nsIDOMSVGViewSpec_h__


#ifndef __gen_nsIDOMSVGZoomAndPan_h__
#include "nsIDOMSVGZoomAndPan.h"
#endif

/* For IDL files that don't want to include root IDL files. */
#ifndef NS_NO_VTABLE
#define NS_NO_VTABLE
#endif
class nsIDOMSVGTransformList; /* forward declaration */

class nsIDOMSVGElement; /* forward declaration */


/* starting interface:    nsIDOMSVGViewSpec */
#define NS_IDOMSVGVIEWSPEC_IID_STR "ede34b03-57b6-45bf-a259-3550b5697286"

#define NS_IDOMSVGVIEWSPEC_IID \
  {0xede34b03, 0x57b6, 0x45bf, \
    { 0xa2, 0x59, 0x35, 0x50, 0xb5, 0x69, 0x72, 0x86 }}

class NS_NO_VTABLE NS_SCRIPTABLE nsIDOMSVGViewSpec : public nsIDOMSVGZoomAndPan {
 public: 

  NS_DECLARE_STATIC_IID_ACCESSOR(NS_IDOMSVGVIEWSPEC_IID)

  /* readonly attribute nsIDOMSVGTransformList transform; */
  NS_SCRIPTABLE NS_IMETHOD GetTransform(nsIDOMSVGTransformList * *aTransform) = 0;

  /* readonly attribute nsIDOMSVGElement viewTarget; */
  NS_SCRIPTABLE NS_IMETHOD GetViewTarget(nsIDOMSVGElement * *aViewTarget) = 0;

  /* readonly attribute DOMString viewBoxString; */
  NS_SCRIPTABLE NS_IMETHOD GetViewBoxString(nsAString & aViewBoxString) = 0;

  /* readonly attribute DOMString preserveAspectRatioString; */
  NS_SCRIPTABLE NS_IMETHOD GetPreserveAspectRatioString(nsAString & aPreserveAspectRatioString) = 0;

  /* readonly attribute DOMString transformString; */
  NS_SCRIPTABLE NS_IMETHOD GetTransformString(nsAString & aTransformString) = 0;

  /* readonly attribute DOMString viewTargetString; */
  NS_SCRIPTABLE NS_IMETHOD GetViewTargetString(nsAString & aViewTargetString) = 0;

};

  NS_DEFINE_STATIC_IID_ACCESSOR(nsIDOMSVGViewSpec, NS_IDOMSVGVIEWSPEC_IID)

/* Use this macro when declaring classes that implement this interface. */
#define NS_DECL_NSIDOMSVGVIEWSPEC \
  NS_SCRIPTABLE NS_IMETHOD GetTransform(nsIDOMSVGTransformList * *aTransform); \
  NS_SCRIPTABLE NS_IMETHOD GetViewTarget(nsIDOMSVGElement * *aViewTarget); \
  NS_SCRIPTABLE NS_IMETHOD GetViewBoxString(nsAString & aViewBoxString); \
  NS_SCRIPTABLE NS_IMETHOD GetPreserveAspectRatioString(nsAString & aPreserveAspectRatioString); \
  NS_SCRIPTABLE NS_IMETHOD GetTransformString(nsAString & aTransformString); \
  NS_SCRIPTABLE NS_IMETHOD GetViewTargetString(nsAString & aViewTargetString); 

/* Use this macro to declare functions that forward the behavior of this interface to another object. */
#define NS_FORWARD_NSIDOMSVGVIEWSPEC(_to) \
  NS_SCRIPTABLE NS_IMETHOD GetTransform(nsIDOMSVGTransformList * *aTransform) { return _to GetTransform(aTransform); } \
  NS_SCRIPTABLE NS_IMETHOD GetViewTarget(nsIDOMSVGElement * *aViewTarget) { return _to GetViewTarget(aViewTarget); } \
  NS_SCRIPTABLE NS_IMETHOD GetViewBoxString(nsAString & aViewBoxString) { return _to GetViewBoxString(aViewBoxString); } \
  NS_SCRIPTABLE NS_IMETHOD GetPreserveAspectRatioString(nsAString & aPreserveAspectRatioString) { return _to GetPreserveAspectRatioString(aPreserveAspectRatioString); } \
  NS_SCRIPTABLE NS_IMETHOD GetTransformString(nsAString & aTransformString) { return _to GetTransformString(aTransformString); } \
  NS_SCRIPTABLE NS_IMETHOD GetViewTargetString(nsAString & aViewTargetString) { return _to GetViewTargetString(aViewTargetString); } 

/* Use this macro to declare functions that forward the behavior of this interface to another object in a safe way. */
#define NS_FORWARD_SAFE_NSIDOMSVGVIEWSPEC(_to) \
  NS_SCRIPTABLE NS_IMETHOD GetTransform(nsIDOMSVGTransformList * *aTransform) { return !_to ? NS_ERROR_NULL_POINTER : _to->GetTransform(aTransform); } \
  NS_SCRIPTABLE NS_IMETHOD GetViewTarget(nsIDOMSVGElement * *aViewTarget) { return !_to ? NS_ERROR_NULL_POINTER : _to->GetViewTarget(aViewTarget); } \
  NS_SCRIPTABLE NS_IMETHOD GetViewBoxString(nsAString & aViewBoxString) { return !_to ? NS_ERROR_NULL_POINTER : _to->GetViewBoxString(aViewBoxString); } \
  NS_SCRIPTABLE NS_IMETHOD GetPreserveAspectRatioString(nsAString & aPreserveAspectRatioString) { return !_to ? NS_ERROR_NULL_POINTER : _to->GetPreserveAspectRatioString(aPreserveAspectRatioString); } \
  NS_SCRIPTABLE NS_IMETHOD GetTransformString(nsAString & aTransformString) { return !_to ? NS_ERROR_NULL_POINTER : _to->GetTransformString(aTransformString); } \
  NS_SCRIPTABLE NS_IMETHOD GetViewTargetString(nsAString & aViewTargetString) { return !_to ? NS_ERROR_NULL_POINTER : _to->GetViewTargetString(aViewTargetString); } 

#if 0
/* Use the code below as a template for the implementation class for this interface. */

/* Header file */
class nsDOMSVGViewSpec : public nsIDOMSVGViewSpec
{
public:
  NS_DECL_ISUPPORTS
  NS_DECL_NSIDOMSVGVIEWSPEC

  nsDOMSVGViewSpec();

private:
  ~nsDOMSVGViewSpec();

protected:
  /* additional members */
};

/* Implementation file */
NS_IMPL_ISUPPORTS1(nsDOMSVGViewSpec, nsIDOMSVGViewSpec)

nsDOMSVGViewSpec::nsDOMSVGViewSpec()
{
  /* member initializers and constructor code */
}

nsDOMSVGViewSpec::~nsDOMSVGViewSpec()
{
  /* destructor code */
}

/* readonly attribute nsIDOMSVGTransformList transform; */
NS_IMETHODIMP nsDOMSVGViewSpec::GetTransform(nsIDOMSVGTransformList * *aTransform)
{
    return NS_ERROR_NOT_IMPLEMENTED;
}

/* readonly attribute nsIDOMSVGElement viewTarget; */
NS_IMETHODIMP nsDOMSVGViewSpec::GetViewTarget(nsIDOMSVGElement * *aViewTarget)
{
    return NS_ERROR_NOT_IMPLEMENTED;
}

/* readonly attribute DOMString viewBoxString; */
NS_IMETHODIMP nsDOMSVGViewSpec::GetViewBoxString(nsAString & aViewBoxString)
{
    return NS_ERROR_NOT_IMPLEMENTED;
}

/* readonly attribute DOMString preserveAspectRatioString; */
NS_IMETHODIMP nsDOMSVGViewSpec::GetPreserveAspectRatioString(nsAString & aPreserveAspectRatioString)
{
    return NS_ERROR_NOT_IMPLEMENTED;
}

/* readonly attribute DOMString transformString; */
NS_IMETHODIMP nsDOMSVGViewSpec::GetTransformString(nsAString & aTransformString)
{
    return NS_ERROR_NOT_IMPLEMENTED;
}

/* readonly attribute DOMString viewTargetString; */
NS_IMETHODIMP nsDOMSVGViewSpec::GetViewTargetString(nsAString & aViewTargetString)
{
    return NS_ERROR_NOT_IMPLEMENTED;
}

/* End of implementation class template. */
#endif


#endif /* __gen_nsIDOMSVGViewSpec_h__ */
