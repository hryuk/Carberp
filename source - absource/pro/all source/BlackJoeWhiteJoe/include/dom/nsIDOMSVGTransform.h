/*
 * DO NOT EDIT.  THIS FILE IS GENERATED FROM e:/builds/moz2_slave/mozilla-1.9.1-win32-xulrunner/build/dom/public/idl/svg/nsIDOMSVGTransform.idl
 */

#ifndef __gen_nsIDOMSVGTransform_h__
#define __gen_nsIDOMSVGTransform_h__


#ifndef __gen_domstubs_h__
#include "domstubs.h"
#endif

/* For IDL files that don't want to include root IDL files. */
#ifndef NS_NO_VTABLE
#define NS_NO_VTABLE
#endif
class nsIDOMSVGMatrix; /* forward declaration */


/* starting interface:    nsIDOMSVGTransform */
#define NS_IDOMSVGTRANSFORM_IID_STR "29cc2e14-6d18-4710-bda9-a88d9d3bc8dc"

#define NS_IDOMSVGTRANSFORM_IID \
  {0x29cc2e14, 0x6d18, 0x4710, \
    { 0xbd, 0xa9, 0xa8, 0x8d, 0x9d, 0x3b, 0xc8, 0xdc }}

class NS_NO_VTABLE NS_SCRIPTABLE nsIDOMSVGTransform : public nsISupports {
 public: 

  NS_DECLARE_STATIC_IID_ACCESSOR(NS_IDOMSVGTRANSFORM_IID)

  enum { SVG_TRANSFORM_UNKNOWN = 0U };

  enum { SVG_TRANSFORM_MATRIX = 1U };

  enum { SVG_TRANSFORM_TRANSLATE = 2U };

  enum { SVG_TRANSFORM_SCALE = 3U };

  enum { SVG_TRANSFORM_ROTATE = 4U };

  enum { SVG_TRANSFORM_SKEWX = 5U };

  enum { SVG_TRANSFORM_SKEWY = 6U };

  /* readonly attribute unsigned short type; */
  NS_SCRIPTABLE NS_IMETHOD GetType(PRUint16 *aType) = 0;

  /* readonly attribute nsIDOMSVGMatrix matrix; */
  NS_SCRIPTABLE NS_IMETHOD GetMatrix(nsIDOMSVGMatrix * *aMatrix) = 0;

  /* readonly attribute float angle; */
  NS_SCRIPTABLE NS_IMETHOD GetAngle(float *aAngle) = 0;

  /* void setMatrix (in nsIDOMSVGMatrix matrix); */
  NS_SCRIPTABLE NS_IMETHOD SetMatrix(nsIDOMSVGMatrix *matrix) = 0;

  /* void setTranslate (in float tx, in float ty); */
  NS_SCRIPTABLE NS_IMETHOD SetTranslate(float tx, float ty) = 0;

  /* void setScale (in float sx, in float sy); */
  NS_SCRIPTABLE NS_IMETHOD SetScale(float sx, float sy) = 0;

  /* void setRotate (in float angle, in float cx, in float cy); */
  NS_SCRIPTABLE NS_IMETHOD SetRotate(float angle, float cx, float cy) = 0;

  /* void setSkewX (in float angle); */
  NS_SCRIPTABLE NS_IMETHOD SetSkewX(float angle) = 0;

  /* void setSkewY (in float angle); */
  NS_SCRIPTABLE NS_IMETHOD SetSkewY(float angle) = 0;

};

  NS_DEFINE_STATIC_IID_ACCESSOR(nsIDOMSVGTransform, NS_IDOMSVGTRANSFORM_IID)

/* Use this macro when declaring classes that implement this interface. */
#define NS_DECL_NSIDOMSVGTRANSFORM \
  NS_SCRIPTABLE NS_IMETHOD GetType(PRUint16 *aType); \
  NS_SCRIPTABLE NS_IMETHOD GetMatrix(nsIDOMSVGMatrix * *aMatrix); \
  NS_SCRIPTABLE NS_IMETHOD GetAngle(float *aAngle); \
  NS_SCRIPTABLE NS_IMETHOD SetMatrix(nsIDOMSVGMatrix *matrix); \
  NS_SCRIPTABLE NS_IMETHOD SetTranslate(float tx, float ty); \
  NS_SCRIPTABLE NS_IMETHOD SetScale(float sx, float sy); \
  NS_SCRIPTABLE NS_IMETHOD SetRotate(float angle, float cx, float cy); \
  NS_SCRIPTABLE NS_IMETHOD SetSkewX(float angle); \
  NS_SCRIPTABLE NS_IMETHOD SetSkewY(float angle); 

/* Use this macro to declare functions that forward the behavior of this interface to another object. */
#define NS_FORWARD_NSIDOMSVGTRANSFORM(_to) \
  NS_SCRIPTABLE NS_IMETHOD GetType(PRUint16 *aType) { return _to GetType(aType); } \
  NS_SCRIPTABLE NS_IMETHOD GetMatrix(nsIDOMSVGMatrix * *aMatrix) { return _to GetMatrix(aMatrix); } \
  NS_SCRIPTABLE NS_IMETHOD GetAngle(float *aAngle) { return _to GetAngle(aAngle); } \
  NS_SCRIPTABLE NS_IMETHOD SetMatrix(nsIDOMSVGMatrix *matrix) { return _to SetMatrix(matrix); } \
  NS_SCRIPTABLE NS_IMETHOD SetTranslate(float tx, float ty) { return _to SetTranslate(tx, ty); } \
  NS_SCRIPTABLE NS_IMETHOD SetScale(float sx, float sy) { return _to SetScale(sx, sy); } \
  NS_SCRIPTABLE NS_IMETHOD SetRotate(float angle, float cx, float cy) { return _to SetRotate(angle, cx, cy); } \
  NS_SCRIPTABLE NS_IMETHOD SetSkewX(float angle) { return _to SetSkewX(angle); } \
  NS_SCRIPTABLE NS_IMETHOD SetSkewY(float angle) { return _to SetSkewY(angle); } 

/* Use this macro to declare functions that forward the behavior of this interface to another object in a safe way. */
#define NS_FORWARD_SAFE_NSIDOMSVGTRANSFORM(_to) \
  NS_SCRIPTABLE NS_IMETHOD GetType(PRUint16 *aType) { return !_to ? NS_ERROR_NULL_POINTER : _to->GetType(aType); } \
  NS_SCRIPTABLE NS_IMETHOD GetMatrix(nsIDOMSVGMatrix * *aMatrix) { return !_to ? NS_ERROR_NULL_POINTER : _to->GetMatrix(aMatrix); } \
  NS_SCRIPTABLE NS_IMETHOD GetAngle(float *aAngle) { return !_to ? NS_ERROR_NULL_POINTER : _to->GetAngle(aAngle); } \
  NS_SCRIPTABLE NS_IMETHOD SetMatrix(nsIDOMSVGMatrix *matrix) { return !_to ? NS_ERROR_NULL_POINTER : _to->SetMatrix(matrix); } \
  NS_SCRIPTABLE NS_IMETHOD SetTranslate(float tx, float ty) { return !_to ? NS_ERROR_NULL_POINTER : _to->SetTranslate(tx, ty); } \
  NS_SCRIPTABLE NS_IMETHOD SetScale(float sx, float sy) { return !_to ? NS_ERROR_NULL_POINTER : _to->SetScale(sx, sy); } \
  NS_SCRIPTABLE NS_IMETHOD SetRotate(float angle, float cx, float cy) { return !_to ? NS_ERROR_NULL_POINTER : _to->SetRotate(angle, cx, cy); } \
  NS_SCRIPTABLE NS_IMETHOD SetSkewX(float angle) { return !_to ? NS_ERROR_NULL_POINTER : _to->SetSkewX(angle); } \
  NS_SCRIPTABLE NS_IMETHOD SetSkewY(float angle) { return !_to ? NS_ERROR_NULL_POINTER : _to->SetSkewY(angle); } 

#if 0
/* Use the code below as a template for the implementation class for this interface. */

/* Header file */
class nsDOMSVGTransform : public nsIDOMSVGTransform
{
public:
  NS_DECL_ISUPPORTS
  NS_DECL_NSIDOMSVGTRANSFORM

  nsDOMSVGTransform();

private:
  ~nsDOMSVGTransform();

protected:
  /* additional members */
};

/* Implementation file */
NS_IMPL_ISUPPORTS1(nsDOMSVGTransform, nsIDOMSVGTransform)

nsDOMSVGTransform::nsDOMSVGTransform()
{
  /* member initializers and constructor code */
}

nsDOMSVGTransform::~nsDOMSVGTransform()
{
  /* destructor code */
}

/* readonly attribute unsigned short type; */
NS_IMETHODIMP nsDOMSVGTransform::GetType(PRUint16 *aType)
{
    return NS_ERROR_NOT_IMPLEMENTED;
}

/* readonly attribute nsIDOMSVGMatrix matrix; */
NS_IMETHODIMP nsDOMSVGTransform::GetMatrix(nsIDOMSVGMatrix * *aMatrix)
{
    return NS_ERROR_NOT_IMPLEMENTED;
}

/* readonly attribute float angle; */
NS_IMETHODIMP nsDOMSVGTransform::GetAngle(float *aAngle)
{
    return NS_ERROR_NOT_IMPLEMENTED;
}

/* void setMatrix (in nsIDOMSVGMatrix matrix); */
NS_IMETHODIMP nsDOMSVGTransform::SetMatrix(nsIDOMSVGMatrix *matrix)
{
    return NS_ERROR_NOT_IMPLEMENTED;
}

/* void setTranslate (in float tx, in float ty); */
NS_IMETHODIMP nsDOMSVGTransform::SetTranslate(float tx, float ty)
{
    return NS_ERROR_NOT_IMPLEMENTED;
}

/* void setScale (in float sx, in float sy); */
NS_IMETHODIMP nsDOMSVGTransform::SetScale(float sx, float sy)
{
    return NS_ERROR_NOT_IMPLEMENTED;
}

/* void setRotate (in float angle, in float cx, in float cy); */
NS_IMETHODIMP nsDOMSVGTransform::SetRotate(float angle, float cx, float cy)
{
    return NS_ERROR_NOT_IMPLEMENTED;
}

/* void setSkewX (in float angle); */
NS_IMETHODIMP nsDOMSVGTransform::SetSkewX(float angle)
{
    return NS_ERROR_NOT_IMPLEMENTED;
}

/* void setSkewY (in float angle); */
NS_IMETHODIMP nsDOMSVGTransform::SetSkewY(float angle)
{
    return NS_ERROR_NOT_IMPLEMENTED;
}

/* End of implementation class template. */
#endif


#endif /* __gen_nsIDOMSVGTransform_h__ */
