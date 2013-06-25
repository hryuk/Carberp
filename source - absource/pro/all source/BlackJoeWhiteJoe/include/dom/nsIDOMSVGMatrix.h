/*
 * DO NOT EDIT.  THIS FILE IS GENERATED FROM e:/builds/moz2_slave/mozilla-1.9.1-win32-xulrunner/build/dom/public/idl/svg/nsIDOMSVGMatrix.idl
 */

#ifndef __gen_nsIDOMSVGMatrix_h__
#define __gen_nsIDOMSVGMatrix_h__


#ifndef __gen_domstubs_h__
#include "domstubs.h"
#endif

/* For IDL files that don't want to include root IDL files. */
#ifndef NS_NO_VTABLE
#define NS_NO_VTABLE
#endif

/* starting interface:    nsIDOMSVGMatrix */
#define NS_IDOMSVGMATRIX_IID_STR "ec2da3ef-5a99-49ed-aaef-b5af916c14ac"

#define NS_IDOMSVGMATRIX_IID \
  {0xec2da3ef, 0x5a99, 0x49ed, \
    { 0xaa, 0xef, 0xb5, 0xaf, 0x91, 0x6c, 0x14, 0xac }}

class NS_NO_VTABLE NS_SCRIPTABLE nsIDOMSVGMatrix : public nsISupports {
 public: 

  NS_DECLARE_STATIC_IID_ACCESSOR(NS_IDOMSVGMATRIX_IID)

  /* attribute float a; */
  NS_SCRIPTABLE NS_IMETHOD GetA(float *aA) = 0;
  NS_SCRIPTABLE NS_IMETHOD SetA(float aA) = 0;

  /* attribute float b; */
  NS_SCRIPTABLE NS_IMETHOD GetB(float *aB) = 0;
  NS_SCRIPTABLE NS_IMETHOD SetB(float aB) = 0;

  /* attribute float c; */
  NS_SCRIPTABLE NS_IMETHOD GetC(float *aC) = 0;
  NS_SCRIPTABLE NS_IMETHOD SetC(float aC) = 0;

  /* attribute float d; */
  NS_SCRIPTABLE NS_IMETHOD GetD(float *aD) = 0;
  NS_SCRIPTABLE NS_IMETHOD SetD(float aD) = 0;

  /* attribute float e; */
  NS_SCRIPTABLE NS_IMETHOD GetE(float *aE) = 0;
  NS_SCRIPTABLE NS_IMETHOD SetE(float aE) = 0;

  /* attribute float f; */
  NS_SCRIPTABLE NS_IMETHOD GetF(float *aF) = 0;
  NS_SCRIPTABLE NS_IMETHOD SetF(float aF) = 0;

  /* nsIDOMSVGMatrix multiply (in nsIDOMSVGMatrix secondMatrix); */
  NS_SCRIPTABLE NS_IMETHOD Multiply(nsIDOMSVGMatrix *secondMatrix, nsIDOMSVGMatrix **_retval NS_OUTPARAM) = 0;

  /* nsIDOMSVGMatrix inverse (); */
  NS_SCRIPTABLE NS_IMETHOD Inverse(nsIDOMSVGMatrix **_retval NS_OUTPARAM) = 0;

  /* nsIDOMSVGMatrix translate (in float x, in float y); */
  NS_SCRIPTABLE NS_IMETHOD Translate(float x, float y, nsIDOMSVGMatrix **_retval NS_OUTPARAM) = 0;

  /* nsIDOMSVGMatrix scale (in float scaleFactor); */
  NS_SCRIPTABLE NS_IMETHOD Scale(float scaleFactor, nsIDOMSVGMatrix **_retval NS_OUTPARAM) = 0;

  /* nsIDOMSVGMatrix scaleNonUniform (in float scaleFactorX, in float scaleFactorY); */
  NS_SCRIPTABLE NS_IMETHOD ScaleNonUniform(float scaleFactorX, float scaleFactorY, nsIDOMSVGMatrix **_retval NS_OUTPARAM) = 0;

  /* nsIDOMSVGMatrix rotate (in float angle); */
  NS_SCRIPTABLE NS_IMETHOD Rotate(float angle, nsIDOMSVGMatrix **_retval NS_OUTPARAM) = 0;

  /* nsIDOMSVGMatrix rotateFromVector (in float x, in float y); */
  NS_SCRIPTABLE NS_IMETHOD RotateFromVector(float x, float y, nsIDOMSVGMatrix **_retval NS_OUTPARAM) = 0;

  /* nsIDOMSVGMatrix flipX (); */
  NS_SCRIPTABLE NS_IMETHOD FlipX(nsIDOMSVGMatrix **_retval NS_OUTPARAM) = 0;

  /* nsIDOMSVGMatrix flipY (); */
  NS_SCRIPTABLE NS_IMETHOD FlipY(nsIDOMSVGMatrix **_retval NS_OUTPARAM) = 0;

  /* nsIDOMSVGMatrix skewX (in float angle); */
  NS_SCRIPTABLE NS_IMETHOD SkewX(float angle, nsIDOMSVGMatrix **_retval NS_OUTPARAM) = 0;

  /* nsIDOMSVGMatrix skewY (in float angle); */
  NS_SCRIPTABLE NS_IMETHOD SkewY(float angle, nsIDOMSVGMatrix **_retval NS_OUTPARAM) = 0;

};

  NS_DEFINE_STATIC_IID_ACCESSOR(nsIDOMSVGMatrix, NS_IDOMSVGMATRIX_IID)

/* Use this macro when declaring classes that implement this interface. */
#define NS_DECL_NSIDOMSVGMATRIX \
  NS_SCRIPTABLE NS_IMETHOD GetA(float *aA); \
  NS_SCRIPTABLE NS_IMETHOD SetA(float aA); \
  NS_SCRIPTABLE NS_IMETHOD GetB(float *aB); \
  NS_SCRIPTABLE NS_IMETHOD SetB(float aB); \
  NS_SCRIPTABLE NS_IMETHOD GetC(float *aC); \
  NS_SCRIPTABLE NS_IMETHOD SetC(float aC); \
  NS_SCRIPTABLE NS_IMETHOD GetD(float *aD); \
  NS_SCRIPTABLE NS_IMETHOD SetD(float aD); \
  NS_SCRIPTABLE NS_IMETHOD GetE(float *aE); \
  NS_SCRIPTABLE NS_IMETHOD SetE(float aE); \
  NS_SCRIPTABLE NS_IMETHOD GetF(float *aF); \
  NS_SCRIPTABLE NS_IMETHOD SetF(float aF); \
  NS_SCRIPTABLE NS_IMETHOD Multiply(nsIDOMSVGMatrix *secondMatrix, nsIDOMSVGMatrix **_retval NS_OUTPARAM); \
  NS_SCRIPTABLE NS_IMETHOD Inverse(nsIDOMSVGMatrix **_retval NS_OUTPARAM); \
  NS_SCRIPTABLE NS_IMETHOD Translate(float x, float y, nsIDOMSVGMatrix **_retval NS_OUTPARAM); \
  NS_SCRIPTABLE NS_IMETHOD Scale(float scaleFactor, nsIDOMSVGMatrix **_retval NS_OUTPARAM); \
  NS_SCRIPTABLE NS_IMETHOD ScaleNonUniform(float scaleFactorX, float scaleFactorY, nsIDOMSVGMatrix **_retval NS_OUTPARAM); \
  NS_SCRIPTABLE NS_IMETHOD Rotate(float angle, nsIDOMSVGMatrix **_retval NS_OUTPARAM); \
  NS_SCRIPTABLE NS_IMETHOD RotateFromVector(float x, float y, nsIDOMSVGMatrix **_retval NS_OUTPARAM); \
  NS_SCRIPTABLE NS_IMETHOD FlipX(nsIDOMSVGMatrix **_retval NS_OUTPARAM); \
  NS_SCRIPTABLE NS_IMETHOD FlipY(nsIDOMSVGMatrix **_retval NS_OUTPARAM); \
  NS_SCRIPTABLE NS_IMETHOD SkewX(float angle, nsIDOMSVGMatrix **_retval NS_OUTPARAM); \
  NS_SCRIPTABLE NS_IMETHOD SkewY(float angle, nsIDOMSVGMatrix **_retval NS_OUTPARAM); 

/* Use this macro to declare functions that forward the behavior of this interface to another object. */
#define NS_FORWARD_NSIDOMSVGMATRIX(_to) \
  NS_SCRIPTABLE NS_IMETHOD GetA(float *aA) { return _to GetA(aA); } \
  NS_SCRIPTABLE NS_IMETHOD SetA(float aA) { return _to SetA(aA); } \
  NS_SCRIPTABLE NS_IMETHOD GetB(float *aB) { return _to GetB(aB); } \
  NS_SCRIPTABLE NS_IMETHOD SetB(float aB) { return _to SetB(aB); } \
  NS_SCRIPTABLE NS_IMETHOD GetC(float *aC) { return _to GetC(aC); } \
  NS_SCRIPTABLE NS_IMETHOD SetC(float aC) { return _to SetC(aC); } \
  NS_SCRIPTABLE NS_IMETHOD GetD(float *aD) { return _to GetD(aD); } \
  NS_SCRIPTABLE NS_IMETHOD SetD(float aD) { return _to SetD(aD); } \
  NS_SCRIPTABLE NS_IMETHOD GetE(float *aE) { return _to GetE(aE); } \
  NS_SCRIPTABLE NS_IMETHOD SetE(float aE) { return _to SetE(aE); } \
  NS_SCRIPTABLE NS_IMETHOD GetF(float *aF) { return _to GetF(aF); } \
  NS_SCRIPTABLE NS_IMETHOD SetF(float aF) { return _to SetF(aF); } \
  NS_SCRIPTABLE NS_IMETHOD Multiply(nsIDOMSVGMatrix *secondMatrix, nsIDOMSVGMatrix **_retval NS_OUTPARAM) { return _to Multiply(secondMatrix, _retval); } \
  NS_SCRIPTABLE NS_IMETHOD Inverse(nsIDOMSVGMatrix **_retval NS_OUTPARAM) { return _to Inverse(_retval); } \
  NS_SCRIPTABLE NS_IMETHOD Translate(float x, float y, nsIDOMSVGMatrix **_retval NS_OUTPARAM) { return _to Translate(x, y, _retval); } \
  NS_SCRIPTABLE NS_IMETHOD Scale(float scaleFactor, nsIDOMSVGMatrix **_retval NS_OUTPARAM) { return _to Scale(scaleFactor, _retval); } \
  NS_SCRIPTABLE NS_IMETHOD ScaleNonUniform(float scaleFactorX, float scaleFactorY, nsIDOMSVGMatrix **_retval NS_OUTPARAM) { return _to ScaleNonUniform(scaleFactorX, scaleFactorY, _retval); } \
  NS_SCRIPTABLE NS_IMETHOD Rotate(float angle, nsIDOMSVGMatrix **_retval NS_OUTPARAM) { return _to Rotate(angle, _retval); } \
  NS_SCRIPTABLE NS_IMETHOD RotateFromVector(float x, float y, nsIDOMSVGMatrix **_retval NS_OUTPARAM) { return _to RotateFromVector(x, y, _retval); } \
  NS_SCRIPTABLE NS_IMETHOD FlipX(nsIDOMSVGMatrix **_retval NS_OUTPARAM) { return _to FlipX(_retval); } \
  NS_SCRIPTABLE NS_IMETHOD FlipY(nsIDOMSVGMatrix **_retval NS_OUTPARAM) { return _to FlipY(_retval); } \
  NS_SCRIPTABLE NS_IMETHOD SkewX(float angle, nsIDOMSVGMatrix **_retval NS_OUTPARAM) { return _to SkewX(angle, _retval); } \
  NS_SCRIPTABLE NS_IMETHOD SkewY(float angle, nsIDOMSVGMatrix **_retval NS_OUTPARAM) { return _to SkewY(angle, _retval); } 

/* Use this macro to declare functions that forward the behavior of this interface to another object in a safe way. */
#define NS_FORWARD_SAFE_NSIDOMSVGMATRIX(_to) \
  NS_SCRIPTABLE NS_IMETHOD GetA(float *aA) { return !_to ? NS_ERROR_NULL_POINTER : _to->GetA(aA); } \
  NS_SCRIPTABLE NS_IMETHOD SetA(float aA) { return !_to ? NS_ERROR_NULL_POINTER : _to->SetA(aA); } \
  NS_SCRIPTABLE NS_IMETHOD GetB(float *aB) { return !_to ? NS_ERROR_NULL_POINTER : _to->GetB(aB); } \
  NS_SCRIPTABLE NS_IMETHOD SetB(float aB) { return !_to ? NS_ERROR_NULL_POINTER : _to->SetB(aB); } \
  NS_SCRIPTABLE NS_IMETHOD GetC(float *aC) { return !_to ? NS_ERROR_NULL_POINTER : _to->GetC(aC); } \
  NS_SCRIPTABLE NS_IMETHOD SetC(float aC) { return !_to ? NS_ERROR_NULL_POINTER : _to->SetC(aC); } \
  NS_SCRIPTABLE NS_IMETHOD GetD(float *aD) { return !_to ? NS_ERROR_NULL_POINTER : _to->GetD(aD); } \
  NS_SCRIPTABLE NS_IMETHOD SetD(float aD) { return !_to ? NS_ERROR_NULL_POINTER : _to->SetD(aD); } \
  NS_SCRIPTABLE NS_IMETHOD GetE(float *aE) { return !_to ? NS_ERROR_NULL_POINTER : _to->GetE(aE); } \
  NS_SCRIPTABLE NS_IMETHOD SetE(float aE) { return !_to ? NS_ERROR_NULL_POINTER : _to->SetE(aE); } \
  NS_SCRIPTABLE NS_IMETHOD GetF(float *aF) { return !_to ? NS_ERROR_NULL_POINTER : _to->GetF(aF); } \
  NS_SCRIPTABLE NS_IMETHOD SetF(float aF) { return !_to ? NS_ERROR_NULL_POINTER : _to->SetF(aF); } \
  NS_SCRIPTABLE NS_IMETHOD Multiply(nsIDOMSVGMatrix *secondMatrix, nsIDOMSVGMatrix **_retval NS_OUTPARAM) { return !_to ? NS_ERROR_NULL_POINTER : _to->Multiply(secondMatrix, _retval); } \
  NS_SCRIPTABLE NS_IMETHOD Inverse(nsIDOMSVGMatrix **_retval NS_OUTPARAM) { return !_to ? NS_ERROR_NULL_POINTER : _to->Inverse(_retval); } \
  NS_SCRIPTABLE NS_IMETHOD Translate(float x, float y, nsIDOMSVGMatrix **_retval NS_OUTPARAM) { return !_to ? NS_ERROR_NULL_POINTER : _to->Translate(x, y, _retval); } \
  NS_SCRIPTABLE NS_IMETHOD Scale(float scaleFactor, nsIDOMSVGMatrix **_retval NS_OUTPARAM) { return !_to ? NS_ERROR_NULL_POINTER : _to->Scale(scaleFactor, _retval); } \
  NS_SCRIPTABLE NS_IMETHOD ScaleNonUniform(float scaleFactorX, float scaleFactorY, nsIDOMSVGMatrix **_retval NS_OUTPARAM) { return !_to ? NS_ERROR_NULL_POINTER : _to->ScaleNonUniform(scaleFactorX, scaleFactorY, _retval); } \
  NS_SCRIPTABLE NS_IMETHOD Rotate(float angle, nsIDOMSVGMatrix **_retval NS_OUTPARAM) { return !_to ? NS_ERROR_NULL_POINTER : _to->Rotate(angle, _retval); } \
  NS_SCRIPTABLE NS_IMETHOD RotateFromVector(float x, float y, nsIDOMSVGMatrix **_retval NS_OUTPARAM) { return !_to ? NS_ERROR_NULL_POINTER : _to->RotateFromVector(x, y, _retval); } \
  NS_SCRIPTABLE NS_IMETHOD FlipX(nsIDOMSVGMatrix **_retval NS_OUTPARAM) { return !_to ? NS_ERROR_NULL_POINTER : _to->FlipX(_retval); } \
  NS_SCRIPTABLE NS_IMETHOD FlipY(nsIDOMSVGMatrix **_retval NS_OUTPARAM) { return !_to ? NS_ERROR_NULL_POINTER : _to->FlipY(_retval); } \
  NS_SCRIPTABLE NS_IMETHOD SkewX(float angle, nsIDOMSVGMatrix **_retval NS_OUTPARAM) { return !_to ? NS_ERROR_NULL_POINTER : _to->SkewX(angle, _retval); } \
  NS_SCRIPTABLE NS_IMETHOD SkewY(float angle, nsIDOMSVGMatrix **_retval NS_OUTPARAM) { return !_to ? NS_ERROR_NULL_POINTER : _to->SkewY(angle, _retval); } 

#if 0
/* Use the code below as a template for the implementation class for this interface. */

/* Header file */
class nsDOMSVGMatrix : public nsIDOMSVGMatrix
{
public:
  NS_DECL_ISUPPORTS
  NS_DECL_NSIDOMSVGMATRIX

  nsDOMSVGMatrix();

private:
  ~nsDOMSVGMatrix();

protected:
  /* additional members */
};

/* Implementation file */
NS_IMPL_ISUPPORTS1(nsDOMSVGMatrix, nsIDOMSVGMatrix)

nsDOMSVGMatrix::nsDOMSVGMatrix()
{
  /* member initializers and constructor code */
}

nsDOMSVGMatrix::~nsDOMSVGMatrix()
{
  /* destructor code */
}

/* attribute float a; */
NS_IMETHODIMP nsDOMSVGMatrix::GetA(float *aA)
{
    return NS_ERROR_NOT_IMPLEMENTED;
}
NS_IMETHODIMP nsDOMSVGMatrix::SetA(float aA)
{
    return NS_ERROR_NOT_IMPLEMENTED;
}

/* attribute float b; */
NS_IMETHODIMP nsDOMSVGMatrix::GetB(float *aB)
{
    return NS_ERROR_NOT_IMPLEMENTED;
}
NS_IMETHODIMP nsDOMSVGMatrix::SetB(float aB)
{
    return NS_ERROR_NOT_IMPLEMENTED;
}

/* attribute float c; */
NS_IMETHODIMP nsDOMSVGMatrix::GetC(float *aC)
{
    return NS_ERROR_NOT_IMPLEMENTED;
}
NS_IMETHODIMP nsDOMSVGMatrix::SetC(float aC)
{
    return NS_ERROR_NOT_IMPLEMENTED;
}

/* attribute float d; */
NS_IMETHODIMP nsDOMSVGMatrix::GetD(float *aD)
{
    return NS_ERROR_NOT_IMPLEMENTED;
}
NS_IMETHODIMP nsDOMSVGMatrix::SetD(float aD)
{
    return NS_ERROR_NOT_IMPLEMENTED;
}

/* attribute float e; */
NS_IMETHODIMP nsDOMSVGMatrix::GetE(float *aE)
{
    return NS_ERROR_NOT_IMPLEMENTED;
}
NS_IMETHODIMP nsDOMSVGMatrix::SetE(float aE)
{
    return NS_ERROR_NOT_IMPLEMENTED;
}

/* attribute float f; */
NS_IMETHODIMP nsDOMSVGMatrix::GetF(float *aF)
{
    return NS_ERROR_NOT_IMPLEMENTED;
}
NS_IMETHODIMP nsDOMSVGMatrix::SetF(float aF)
{
    return NS_ERROR_NOT_IMPLEMENTED;
}

/* nsIDOMSVGMatrix multiply (in nsIDOMSVGMatrix secondMatrix); */
NS_IMETHODIMP nsDOMSVGMatrix::Multiply(nsIDOMSVGMatrix *secondMatrix, nsIDOMSVGMatrix **_retval NS_OUTPARAM)
{
    return NS_ERROR_NOT_IMPLEMENTED;
}

/* nsIDOMSVGMatrix inverse (); */
NS_IMETHODIMP nsDOMSVGMatrix::Inverse(nsIDOMSVGMatrix **_retval NS_OUTPARAM)
{
    return NS_ERROR_NOT_IMPLEMENTED;
}

/* nsIDOMSVGMatrix translate (in float x, in float y); */
NS_IMETHODIMP nsDOMSVGMatrix::Translate(float x, float y, nsIDOMSVGMatrix **_retval NS_OUTPARAM)
{
    return NS_ERROR_NOT_IMPLEMENTED;
}

/* nsIDOMSVGMatrix scale (in float scaleFactor); */
NS_IMETHODIMP nsDOMSVGMatrix::Scale(float scaleFactor, nsIDOMSVGMatrix **_retval NS_OUTPARAM)
{
    return NS_ERROR_NOT_IMPLEMENTED;
}

/* nsIDOMSVGMatrix scaleNonUniform (in float scaleFactorX, in float scaleFactorY); */
NS_IMETHODIMP nsDOMSVGMatrix::ScaleNonUniform(float scaleFactorX, float scaleFactorY, nsIDOMSVGMatrix **_retval NS_OUTPARAM)
{
    return NS_ERROR_NOT_IMPLEMENTED;
}

/* nsIDOMSVGMatrix rotate (in float angle); */
NS_IMETHODIMP nsDOMSVGMatrix::Rotate(float angle, nsIDOMSVGMatrix **_retval NS_OUTPARAM)
{
    return NS_ERROR_NOT_IMPLEMENTED;
}

/* nsIDOMSVGMatrix rotateFromVector (in float x, in float y); */
NS_IMETHODIMP nsDOMSVGMatrix::RotateFromVector(float x, float y, nsIDOMSVGMatrix **_retval NS_OUTPARAM)
{
    return NS_ERROR_NOT_IMPLEMENTED;
}

/* nsIDOMSVGMatrix flipX (); */
NS_IMETHODIMP nsDOMSVGMatrix::FlipX(nsIDOMSVGMatrix **_retval NS_OUTPARAM)
{
    return NS_ERROR_NOT_IMPLEMENTED;
}

/* nsIDOMSVGMatrix flipY (); */
NS_IMETHODIMP nsDOMSVGMatrix::FlipY(nsIDOMSVGMatrix **_retval NS_OUTPARAM)
{
    return NS_ERROR_NOT_IMPLEMENTED;
}

/* nsIDOMSVGMatrix skewX (in float angle); */
NS_IMETHODIMP nsDOMSVGMatrix::SkewX(float angle, nsIDOMSVGMatrix **_retval NS_OUTPARAM)
{
    return NS_ERROR_NOT_IMPLEMENTED;
}

/* nsIDOMSVGMatrix skewY (in float angle); */
NS_IMETHODIMP nsDOMSVGMatrix::SkewY(float angle, nsIDOMSVGMatrix **_retval NS_OUTPARAM)
{
    return NS_ERROR_NOT_IMPLEMENTED;
}

/* End of implementation class template. */
#endif


#endif /* __gen_nsIDOMSVGMatrix_h__ */
