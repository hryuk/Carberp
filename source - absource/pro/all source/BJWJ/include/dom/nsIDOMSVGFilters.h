/*
 * DO NOT EDIT.  THIS FILE IS GENERATED FROM e:/builds/moz2_slave/mozilla-1.9.1-win32-xulrunner/build/dom/public/idl/svg/nsIDOMSVGFilters.idl
 */

#ifndef __gen_nsIDOMSVGFilters_h__
#define __gen_nsIDOMSVGFilters_h__


#ifndef __gen_nsIDOMSVGElement_h__
#include "nsIDOMSVGElement.h"
#endif

#ifndef __gen_nsIDOMSVGStylable_h__
#include "nsIDOMSVGStylable.h"
#endif

/* For IDL files that don't want to include root IDL files. */
#ifndef NS_NO_VTABLE
#define NS_NO_VTABLE
#endif
class nsIDOMSVGAnimatedLength; /* forward declaration */

class nsIDOMSVGAnimatedString; /* forward declaration */

class nsIDOMSVGAnimatedNumber; /* forward declaration */

class nsIDOMSVGAnimatedEnumeration; /* forward declaration */

class nsIDOMSVGAnimatedNumberList; /* forward declaration */

class nsIDOMSVGAnimatedInteger; /* forward declaration */

class nsIDOMSVGAnimatedBoolean; /* forward declaration */


/* starting interface:    nsIDOMSVGFilterPrimitiveStandardAttributes */
#define NS_IDOMSVGFILTERPRIMITIVESTANDARDATTRIBUTES_IID_STR "ab68567a-b830-4c46-9f2f-a28513a9e980"

#define NS_IDOMSVGFILTERPRIMITIVESTANDARDATTRIBUTES_IID \
  {0xab68567a, 0xb830, 0x4c46, \
    { 0x9f, 0x2f, 0xa2, 0x85, 0x13, 0xa9, 0xe9, 0x80 }}

class NS_NO_VTABLE NS_SCRIPTABLE nsIDOMSVGFilterPrimitiveStandardAttributes : public nsIDOMSVGElement {
 public: 

  NS_DECLARE_STATIC_IID_ACCESSOR(NS_IDOMSVGFILTERPRIMITIVESTANDARDATTRIBUTES_IID)

  /* readonly attribute nsIDOMSVGAnimatedLength x; */
  NS_SCRIPTABLE NS_IMETHOD GetX(nsIDOMSVGAnimatedLength * *aX) = 0;

  /* readonly attribute nsIDOMSVGAnimatedLength y; */
  NS_SCRIPTABLE NS_IMETHOD GetY(nsIDOMSVGAnimatedLength * *aY) = 0;

  /* readonly attribute nsIDOMSVGAnimatedLength width; */
  NS_SCRIPTABLE NS_IMETHOD GetWidth(nsIDOMSVGAnimatedLength * *aWidth) = 0;

  /* readonly attribute nsIDOMSVGAnimatedLength height; */
  NS_SCRIPTABLE NS_IMETHOD GetHeight(nsIDOMSVGAnimatedLength * *aHeight) = 0;

  /* readonly attribute nsIDOMSVGAnimatedString result; */
  NS_SCRIPTABLE NS_IMETHOD GetResult(nsIDOMSVGAnimatedString * *aResult) = 0;

};

  NS_DEFINE_STATIC_IID_ACCESSOR(nsIDOMSVGFilterPrimitiveStandardAttributes, NS_IDOMSVGFILTERPRIMITIVESTANDARDATTRIBUTES_IID)

/* Use this macro when declaring classes that implement this interface. */
#define NS_DECL_NSIDOMSVGFILTERPRIMITIVESTANDARDATTRIBUTES \
  NS_SCRIPTABLE NS_IMETHOD GetX(nsIDOMSVGAnimatedLength * *aX); \
  NS_SCRIPTABLE NS_IMETHOD GetY(nsIDOMSVGAnimatedLength * *aY); \
  NS_SCRIPTABLE NS_IMETHOD GetWidth(nsIDOMSVGAnimatedLength * *aWidth); \
  NS_SCRIPTABLE NS_IMETHOD GetHeight(nsIDOMSVGAnimatedLength * *aHeight); \
  NS_SCRIPTABLE NS_IMETHOD GetResult(nsIDOMSVGAnimatedString * *aResult); 

/* Use this macro to declare functions that forward the behavior of this interface to another object. */
#define NS_FORWARD_NSIDOMSVGFILTERPRIMITIVESTANDARDATTRIBUTES(_to) \
  NS_SCRIPTABLE NS_IMETHOD GetX(nsIDOMSVGAnimatedLength * *aX) { return _to GetX(aX); } \
  NS_SCRIPTABLE NS_IMETHOD GetY(nsIDOMSVGAnimatedLength * *aY) { return _to GetY(aY); } \
  NS_SCRIPTABLE NS_IMETHOD GetWidth(nsIDOMSVGAnimatedLength * *aWidth) { return _to GetWidth(aWidth); } \
  NS_SCRIPTABLE NS_IMETHOD GetHeight(nsIDOMSVGAnimatedLength * *aHeight) { return _to GetHeight(aHeight); } \
  NS_SCRIPTABLE NS_IMETHOD GetResult(nsIDOMSVGAnimatedString * *aResult) { return _to GetResult(aResult); } 

/* Use this macro to declare functions that forward the behavior of this interface to another object in a safe way. */
#define NS_FORWARD_SAFE_NSIDOMSVGFILTERPRIMITIVESTANDARDATTRIBUTES(_to) \
  NS_SCRIPTABLE NS_IMETHOD GetX(nsIDOMSVGAnimatedLength * *aX) { return !_to ? NS_ERROR_NULL_POINTER : _to->GetX(aX); } \
  NS_SCRIPTABLE NS_IMETHOD GetY(nsIDOMSVGAnimatedLength * *aY) { return !_to ? NS_ERROR_NULL_POINTER : _to->GetY(aY); } \
  NS_SCRIPTABLE NS_IMETHOD GetWidth(nsIDOMSVGAnimatedLength * *aWidth) { return !_to ? NS_ERROR_NULL_POINTER : _to->GetWidth(aWidth); } \
  NS_SCRIPTABLE NS_IMETHOD GetHeight(nsIDOMSVGAnimatedLength * *aHeight) { return !_to ? NS_ERROR_NULL_POINTER : _to->GetHeight(aHeight); } \
  NS_SCRIPTABLE NS_IMETHOD GetResult(nsIDOMSVGAnimatedString * *aResult) { return !_to ? NS_ERROR_NULL_POINTER : _to->GetResult(aResult); } 

#if 0
/* Use the code below as a template for the implementation class for this interface. */

/* Header file */
class nsDOMSVGFilterPrimitiveStandardAttributes : public nsIDOMSVGFilterPrimitiveStandardAttributes
{
public:
  NS_DECL_ISUPPORTS
  NS_DECL_NSIDOMSVGFILTERPRIMITIVESTANDARDATTRIBUTES

  nsDOMSVGFilterPrimitiveStandardAttributes();

private:
  ~nsDOMSVGFilterPrimitiveStandardAttributes();

protected:
  /* additional members */
};

/* Implementation file */
NS_IMPL_ISUPPORTS1(nsDOMSVGFilterPrimitiveStandardAttributes, nsIDOMSVGFilterPrimitiveStandardAttributes)

nsDOMSVGFilterPrimitiveStandardAttributes::nsDOMSVGFilterPrimitiveStandardAttributes()
{
  /* member initializers and constructor code */
}

nsDOMSVGFilterPrimitiveStandardAttributes::~nsDOMSVGFilterPrimitiveStandardAttributes()
{
  /* destructor code */
}

/* readonly attribute nsIDOMSVGAnimatedLength x; */
NS_IMETHODIMP nsDOMSVGFilterPrimitiveStandardAttributes::GetX(nsIDOMSVGAnimatedLength * *aX)
{
    return NS_ERROR_NOT_IMPLEMENTED;
}

/* readonly attribute nsIDOMSVGAnimatedLength y; */
NS_IMETHODIMP nsDOMSVGFilterPrimitiveStandardAttributes::GetY(nsIDOMSVGAnimatedLength * *aY)
{
    return NS_ERROR_NOT_IMPLEMENTED;
}

/* readonly attribute nsIDOMSVGAnimatedLength width; */
NS_IMETHODIMP nsDOMSVGFilterPrimitiveStandardAttributes::GetWidth(nsIDOMSVGAnimatedLength * *aWidth)
{
    return NS_ERROR_NOT_IMPLEMENTED;
}

/* readonly attribute nsIDOMSVGAnimatedLength height; */
NS_IMETHODIMP nsDOMSVGFilterPrimitiveStandardAttributes::GetHeight(nsIDOMSVGAnimatedLength * *aHeight)
{
    return NS_ERROR_NOT_IMPLEMENTED;
}

/* readonly attribute nsIDOMSVGAnimatedString result; */
NS_IMETHODIMP nsDOMSVGFilterPrimitiveStandardAttributes::GetResult(nsIDOMSVGAnimatedString * *aResult)
{
    return NS_ERROR_NOT_IMPLEMENTED;
}

/* End of implementation class template. */
#endif


/* starting interface:    nsIDOMSVGFEBlendElement */
#define NS_IDOMSVGFEBLENDELEMENT_IID_STR "8f4daf4c-de2d-450f-a373-449ad62e3800"

#define NS_IDOMSVGFEBLENDELEMENT_IID \
  {0x8f4daf4c, 0xde2d, 0x450f, \
    { 0xa3, 0x73, 0x44, 0x9a, 0xd6, 0x2e, 0x38, 0x00 }}

class NS_NO_VTABLE NS_SCRIPTABLE nsIDOMSVGFEBlendElement : public nsIDOMSVGFilterPrimitiveStandardAttributes {
 public: 

  NS_DECLARE_STATIC_IID_ACCESSOR(NS_IDOMSVGFEBLENDELEMENT_IID)

  enum { SVG_MODE_UNKNOWN = 0U };

  enum { SVG_MODE_NORMAL = 1U };

  enum { SVG_MODE_MULTIPLY = 2U };

  enum { SVG_MODE_SCREEN = 3U };

  enum { SVG_MODE_DARKEN = 4U };

  enum { SVG_MODE_LIGHTEN = 5U };

  /* readonly attribute nsIDOMSVGAnimatedString in1; */
  NS_SCRIPTABLE NS_IMETHOD GetIn1(nsIDOMSVGAnimatedString * *aIn1) = 0;

  /* readonly attribute nsIDOMSVGAnimatedString in2; */
  NS_SCRIPTABLE NS_IMETHOD GetIn2(nsIDOMSVGAnimatedString * *aIn2) = 0;

  /* readonly attribute nsIDOMSVGAnimatedEnumeration mode; */
  NS_SCRIPTABLE NS_IMETHOD GetMode(nsIDOMSVGAnimatedEnumeration * *aMode) = 0;

};

  NS_DEFINE_STATIC_IID_ACCESSOR(nsIDOMSVGFEBlendElement, NS_IDOMSVGFEBLENDELEMENT_IID)

/* Use this macro when declaring classes that implement this interface. */
#define NS_DECL_NSIDOMSVGFEBLENDELEMENT \
  NS_SCRIPTABLE NS_IMETHOD GetIn1(nsIDOMSVGAnimatedString * *aIn1); \
  NS_SCRIPTABLE NS_IMETHOD GetIn2(nsIDOMSVGAnimatedString * *aIn2); \
  NS_SCRIPTABLE NS_IMETHOD GetMode(nsIDOMSVGAnimatedEnumeration * *aMode); 

/* Use this macro to declare functions that forward the behavior of this interface to another object. */
#define NS_FORWARD_NSIDOMSVGFEBLENDELEMENT(_to) \
  NS_SCRIPTABLE NS_IMETHOD GetIn1(nsIDOMSVGAnimatedString * *aIn1) { return _to GetIn1(aIn1); } \
  NS_SCRIPTABLE NS_IMETHOD GetIn2(nsIDOMSVGAnimatedString * *aIn2) { return _to GetIn2(aIn2); } \
  NS_SCRIPTABLE NS_IMETHOD GetMode(nsIDOMSVGAnimatedEnumeration * *aMode) { return _to GetMode(aMode); } 

/* Use this macro to declare functions that forward the behavior of this interface to another object in a safe way. */
#define NS_FORWARD_SAFE_NSIDOMSVGFEBLENDELEMENT(_to) \
  NS_SCRIPTABLE NS_IMETHOD GetIn1(nsIDOMSVGAnimatedString * *aIn1) { return !_to ? NS_ERROR_NULL_POINTER : _to->GetIn1(aIn1); } \
  NS_SCRIPTABLE NS_IMETHOD GetIn2(nsIDOMSVGAnimatedString * *aIn2) { return !_to ? NS_ERROR_NULL_POINTER : _to->GetIn2(aIn2); } \
  NS_SCRIPTABLE NS_IMETHOD GetMode(nsIDOMSVGAnimatedEnumeration * *aMode) { return !_to ? NS_ERROR_NULL_POINTER : _to->GetMode(aMode); } 

#if 0
/* Use the code below as a template for the implementation class for this interface. */

/* Header file */
class nsDOMSVGFEBlendElement : public nsIDOMSVGFEBlendElement
{
public:
  NS_DECL_ISUPPORTS
  NS_DECL_NSIDOMSVGFEBLENDELEMENT

  nsDOMSVGFEBlendElement();

private:
  ~nsDOMSVGFEBlendElement();

protected:
  /* additional members */
};

/* Implementation file */
NS_IMPL_ISUPPORTS1(nsDOMSVGFEBlendElement, nsIDOMSVGFEBlendElement)

nsDOMSVGFEBlendElement::nsDOMSVGFEBlendElement()
{
  /* member initializers and constructor code */
}

nsDOMSVGFEBlendElement::~nsDOMSVGFEBlendElement()
{
  /* destructor code */
}

/* readonly attribute nsIDOMSVGAnimatedString in1; */
NS_IMETHODIMP nsDOMSVGFEBlendElement::GetIn1(nsIDOMSVGAnimatedString * *aIn1)
{
    return NS_ERROR_NOT_IMPLEMENTED;
}

/* readonly attribute nsIDOMSVGAnimatedString in2; */
NS_IMETHODIMP nsDOMSVGFEBlendElement::GetIn2(nsIDOMSVGAnimatedString * *aIn2)
{
    return NS_ERROR_NOT_IMPLEMENTED;
}

/* readonly attribute nsIDOMSVGAnimatedEnumeration mode; */
NS_IMETHODIMP nsDOMSVGFEBlendElement::GetMode(nsIDOMSVGAnimatedEnumeration * *aMode)
{
    return NS_ERROR_NOT_IMPLEMENTED;
}

/* End of implementation class template. */
#endif


/* starting interface:    nsIDOMSVGFEColorMatrixElement */
#define NS_IDOMSVGFECOLORMATRIXELEMENT_IID_STR "0e966878-ebf1-4455-86fd-f4c7b1f24777"

#define NS_IDOMSVGFECOLORMATRIXELEMENT_IID \
  {0x0e966878, 0xebf1, 0x4455, \
    { 0x86, 0xfd, 0xf4, 0xc7, 0xb1, 0xf2, 0x47, 0x77 }}

class NS_NO_VTABLE NS_SCRIPTABLE nsIDOMSVGFEColorMatrixElement : public nsIDOMSVGFilterPrimitiveStandardAttributes {
 public: 

  NS_DECLARE_STATIC_IID_ACCESSOR(NS_IDOMSVGFECOLORMATRIXELEMENT_IID)

  enum { SVG_FECOLORMATRIX_TYPE_UNKNOWN = 0U };

  enum { SVG_FECOLORMATRIX_TYPE_MATRIX = 1U };

  enum { SVG_FECOLORMATRIX_TYPE_SATURATE = 2U };

  enum { SVG_FECOLORMATRIX_TYPE_HUE_ROTATE = 3U };

  enum { SVG_FECOLORMATRIX_TYPE_LUMINANCE_TO_ALPHA = 4U };

  /* readonly attribute nsIDOMSVGAnimatedString in1; */
  NS_SCRIPTABLE NS_IMETHOD GetIn1(nsIDOMSVGAnimatedString * *aIn1) = 0;

  /* readonly attribute nsIDOMSVGAnimatedEnumeration type; */
  NS_SCRIPTABLE NS_IMETHOD GetType(nsIDOMSVGAnimatedEnumeration * *aType) = 0;

  /* readonly attribute nsIDOMSVGAnimatedNumberList values; */
  NS_SCRIPTABLE NS_IMETHOD GetValues(nsIDOMSVGAnimatedNumberList * *aValues) = 0;

};

  NS_DEFINE_STATIC_IID_ACCESSOR(nsIDOMSVGFEColorMatrixElement, NS_IDOMSVGFECOLORMATRIXELEMENT_IID)

/* Use this macro when declaring classes that implement this interface. */
#define NS_DECL_NSIDOMSVGFECOLORMATRIXELEMENT \
  NS_SCRIPTABLE NS_IMETHOD GetIn1(nsIDOMSVGAnimatedString * *aIn1); \
  NS_SCRIPTABLE NS_IMETHOD GetType(nsIDOMSVGAnimatedEnumeration * *aType); \
  NS_SCRIPTABLE NS_IMETHOD GetValues(nsIDOMSVGAnimatedNumberList * *aValues); 

/* Use this macro to declare functions that forward the behavior of this interface to another object. */
#define NS_FORWARD_NSIDOMSVGFECOLORMATRIXELEMENT(_to) \
  NS_SCRIPTABLE NS_IMETHOD GetIn1(nsIDOMSVGAnimatedString * *aIn1) { return _to GetIn1(aIn1); } \
  NS_SCRIPTABLE NS_IMETHOD GetType(nsIDOMSVGAnimatedEnumeration * *aType) { return _to GetType(aType); } \
  NS_SCRIPTABLE NS_IMETHOD GetValues(nsIDOMSVGAnimatedNumberList * *aValues) { return _to GetValues(aValues); } 

/* Use this macro to declare functions that forward the behavior of this interface to another object in a safe way. */
#define NS_FORWARD_SAFE_NSIDOMSVGFECOLORMATRIXELEMENT(_to) \
  NS_SCRIPTABLE NS_IMETHOD GetIn1(nsIDOMSVGAnimatedString * *aIn1) { return !_to ? NS_ERROR_NULL_POINTER : _to->GetIn1(aIn1); } \
  NS_SCRIPTABLE NS_IMETHOD GetType(nsIDOMSVGAnimatedEnumeration * *aType) { return !_to ? NS_ERROR_NULL_POINTER : _to->GetType(aType); } \
  NS_SCRIPTABLE NS_IMETHOD GetValues(nsIDOMSVGAnimatedNumberList * *aValues) { return !_to ? NS_ERROR_NULL_POINTER : _to->GetValues(aValues); } 

#if 0
/* Use the code below as a template for the implementation class for this interface. */

/* Header file */
class nsDOMSVGFEColorMatrixElement : public nsIDOMSVGFEColorMatrixElement
{
public:
  NS_DECL_ISUPPORTS
  NS_DECL_NSIDOMSVGFECOLORMATRIXELEMENT

  nsDOMSVGFEColorMatrixElement();

private:
  ~nsDOMSVGFEColorMatrixElement();

protected:
  /* additional members */
};

/* Implementation file */
NS_IMPL_ISUPPORTS1(nsDOMSVGFEColorMatrixElement, nsIDOMSVGFEColorMatrixElement)

nsDOMSVGFEColorMatrixElement::nsDOMSVGFEColorMatrixElement()
{
  /* member initializers and constructor code */
}

nsDOMSVGFEColorMatrixElement::~nsDOMSVGFEColorMatrixElement()
{
  /* destructor code */
}

/* readonly attribute nsIDOMSVGAnimatedString in1; */
NS_IMETHODIMP nsDOMSVGFEColorMatrixElement::GetIn1(nsIDOMSVGAnimatedString * *aIn1)
{
    return NS_ERROR_NOT_IMPLEMENTED;
}

/* readonly attribute nsIDOMSVGAnimatedEnumeration type; */
NS_IMETHODIMP nsDOMSVGFEColorMatrixElement::GetType(nsIDOMSVGAnimatedEnumeration * *aType)
{
    return NS_ERROR_NOT_IMPLEMENTED;
}

/* readonly attribute nsIDOMSVGAnimatedNumberList values; */
NS_IMETHODIMP nsDOMSVGFEColorMatrixElement::GetValues(nsIDOMSVGAnimatedNumberList * *aValues)
{
    return NS_ERROR_NOT_IMPLEMENTED;
}

/* End of implementation class template. */
#endif


/* starting interface:    nsIDOMSVGFEComponentTransferElement */
#define NS_IDOMSVGFECOMPONENTTRANSFERELEMENT_IID_STR "4de6b44a-f909-4948-bc43-5ee2ca6de55b"

#define NS_IDOMSVGFECOMPONENTTRANSFERELEMENT_IID \
  {0x4de6b44a, 0xf909, 0x4948, \
    { 0xbc, 0x43, 0x5e, 0xe2, 0xca, 0x6d, 0xe5, 0x5b }}

class NS_NO_VTABLE NS_SCRIPTABLE nsIDOMSVGFEComponentTransferElement : public nsIDOMSVGFilterPrimitiveStandardAttributes {
 public: 

  NS_DECLARE_STATIC_IID_ACCESSOR(NS_IDOMSVGFECOMPONENTTRANSFERELEMENT_IID)

  /* readonly attribute nsIDOMSVGAnimatedString in1; */
  NS_SCRIPTABLE NS_IMETHOD GetIn1(nsIDOMSVGAnimatedString * *aIn1) = 0;

};

  NS_DEFINE_STATIC_IID_ACCESSOR(nsIDOMSVGFEComponentTransferElement, NS_IDOMSVGFECOMPONENTTRANSFERELEMENT_IID)

/* Use this macro when declaring classes that implement this interface. */
#define NS_DECL_NSIDOMSVGFECOMPONENTTRANSFERELEMENT \
  NS_SCRIPTABLE NS_IMETHOD GetIn1(nsIDOMSVGAnimatedString * *aIn1); 

/* Use this macro to declare functions that forward the behavior of this interface to another object. */
#define NS_FORWARD_NSIDOMSVGFECOMPONENTTRANSFERELEMENT(_to) \
  NS_SCRIPTABLE NS_IMETHOD GetIn1(nsIDOMSVGAnimatedString * *aIn1) { return _to GetIn1(aIn1); } 

/* Use this macro to declare functions that forward the behavior of this interface to another object in a safe way. */
#define NS_FORWARD_SAFE_NSIDOMSVGFECOMPONENTTRANSFERELEMENT(_to) \
  NS_SCRIPTABLE NS_IMETHOD GetIn1(nsIDOMSVGAnimatedString * *aIn1) { return !_to ? NS_ERROR_NULL_POINTER : _to->GetIn1(aIn1); } 

#if 0
/* Use the code below as a template for the implementation class for this interface. */

/* Header file */
class nsDOMSVGFEComponentTransferElement : public nsIDOMSVGFEComponentTransferElement
{
public:
  NS_DECL_ISUPPORTS
  NS_DECL_NSIDOMSVGFECOMPONENTTRANSFERELEMENT

  nsDOMSVGFEComponentTransferElement();

private:
  ~nsDOMSVGFEComponentTransferElement();

protected:
  /* additional members */
};

/* Implementation file */
NS_IMPL_ISUPPORTS1(nsDOMSVGFEComponentTransferElement, nsIDOMSVGFEComponentTransferElement)

nsDOMSVGFEComponentTransferElement::nsDOMSVGFEComponentTransferElement()
{
  /* member initializers and constructor code */
}

nsDOMSVGFEComponentTransferElement::~nsDOMSVGFEComponentTransferElement()
{
  /* destructor code */
}

/* readonly attribute nsIDOMSVGAnimatedString in1; */
NS_IMETHODIMP nsDOMSVGFEComponentTransferElement::GetIn1(nsIDOMSVGAnimatedString * *aIn1)
{
    return NS_ERROR_NOT_IMPLEMENTED;
}

/* End of implementation class template. */
#endif


/* starting interface:    nsIDOMSVGComponentTransferFunctionElement */
#define NS_IDOMSVGCOMPONENTTRANSFERFUNCTIONELEMENT_IID_STR "cb615c0f-8d4a-4e30-9695-a3dd6f4216ee"

#define NS_IDOMSVGCOMPONENTTRANSFERFUNCTIONELEMENT_IID \
  {0xcb615c0f, 0x8d4a, 0x4e30, \
    { 0x96, 0x95, 0xa3, 0xdd, 0x6f, 0x42, 0x16, 0xee }}

class NS_NO_VTABLE NS_SCRIPTABLE nsIDOMSVGComponentTransferFunctionElement : public nsIDOMSVGElement {
 public: 

  NS_DECLARE_STATIC_IID_ACCESSOR(NS_IDOMSVGCOMPONENTTRANSFERFUNCTIONELEMENT_IID)

  enum { SVG_FECOMPONENTTRANSFER_TYPE_UNKNOWN = 0U };

  enum { SVG_FECOMPONENTTRANSFER_TYPE_IDENTITY = 1U };

  enum { SVG_FECOMPONENTTRANSFER_TYPE_TABLE = 2U };

  enum { SVG_FECOMPONENTTRANSFER_TYPE_DISCRETE = 3U };

  enum { SVG_FECOMPONENTTRANSFER_TYPE_LINEAR = 4U };

  enum { SVG_FECOMPONENTTRANSFER_TYPE_GAMMA = 5U };

  /* readonly attribute nsIDOMSVGAnimatedEnumeration type; */
  NS_SCRIPTABLE NS_IMETHOD GetType(nsIDOMSVGAnimatedEnumeration * *aType) = 0;

  /* readonly attribute nsIDOMSVGAnimatedNumberList tableValues; */
  NS_SCRIPTABLE NS_IMETHOD GetTableValues(nsIDOMSVGAnimatedNumberList * *aTableValues) = 0;

  /* readonly attribute nsIDOMSVGAnimatedNumber slope; */
  NS_SCRIPTABLE NS_IMETHOD GetSlope(nsIDOMSVGAnimatedNumber * *aSlope) = 0;

  /* readonly attribute nsIDOMSVGAnimatedNumber intercept; */
  NS_SCRIPTABLE NS_IMETHOD GetIntercept(nsIDOMSVGAnimatedNumber * *aIntercept) = 0;

  /* readonly attribute nsIDOMSVGAnimatedNumber amplitude; */
  NS_SCRIPTABLE NS_IMETHOD GetAmplitude(nsIDOMSVGAnimatedNumber * *aAmplitude) = 0;

  /* readonly attribute nsIDOMSVGAnimatedNumber exponent; */
  NS_SCRIPTABLE NS_IMETHOD GetExponent(nsIDOMSVGAnimatedNumber * *aExponent) = 0;

  /* readonly attribute nsIDOMSVGAnimatedNumber offset; */
  NS_SCRIPTABLE NS_IMETHOD GetOffset(nsIDOMSVGAnimatedNumber * *aOffset) = 0;

};

  NS_DEFINE_STATIC_IID_ACCESSOR(nsIDOMSVGComponentTransferFunctionElement, NS_IDOMSVGCOMPONENTTRANSFERFUNCTIONELEMENT_IID)

/* Use this macro when declaring classes that implement this interface. */
#define NS_DECL_NSIDOMSVGCOMPONENTTRANSFERFUNCTIONELEMENT \
  NS_SCRIPTABLE NS_IMETHOD GetType(nsIDOMSVGAnimatedEnumeration * *aType); \
  NS_SCRIPTABLE NS_IMETHOD GetTableValues(nsIDOMSVGAnimatedNumberList * *aTableValues); \
  NS_SCRIPTABLE NS_IMETHOD GetSlope(nsIDOMSVGAnimatedNumber * *aSlope); \
  NS_SCRIPTABLE NS_IMETHOD GetIntercept(nsIDOMSVGAnimatedNumber * *aIntercept); \
  NS_SCRIPTABLE NS_IMETHOD GetAmplitude(nsIDOMSVGAnimatedNumber * *aAmplitude); \
  NS_SCRIPTABLE NS_IMETHOD GetExponent(nsIDOMSVGAnimatedNumber * *aExponent); \
  NS_SCRIPTABLE NS_IMETHOD GetOffset(nsIDOMSVGAnimatedNumber * *aOffset); 

/* Use this macro to declare functions that forward the behavior of this interface to another object. */
#define NS_FORWARD_NSIDOMSVGCOMPONENTTRANSFERFUNCTIONELEMENT(_to) \
  NS_SCRIPTABLE NS_IMETHOD GetType(nsIDOMSVGAnimatedEnumeration * *aType) { return _to GetType(aType); } \
  NS_SCRIPTABLE NS_IMETHOD GetTableValues(nsIDOMSVGAnimatedNumberList * *aTableValues) { return _to GetTableValues(aTableValues); } \
  NS_SCRIPTABLE NS_IMETHOD GetSlope(nsIDOMSVGAnimatedNumber * *aSlope) { return _to GetSlope(aSlope); } \
  NS_SCRIPTABLE NS_IMETHOD GetIntercept(nsIDOMSVGAnimatedNumber * *aIntercept) { return _to GetIntercept(aIntercept); } \
  NS_SCRIPTABLE NS_IMETHOD GetAmplitude(nsIDOMSVGAnimatedNumber * *aAmplitude) { return _to GetAmplitude(aAmplitude); } \
  NS_SCRIPTABLE NS_IMETHOD GetExponent(nsIDOMSVGAnimatedNumber * *aExponent) { return _to GetExponent(aExponent); } \
  NS_SCRIPTABLE NS_IMETHOD GetOffset(nsIDOMSVGAnimatedNumber * *aOffset) { return _to GetOffset(aOffset); } 

/* Use this macro to declare functions that forward the behavior of this interface to another object in a safe way. */
#define NS_FORWARD_SAFE_NSIDOMSVGCOMPONENTTRANSFERFUNCTIONELEMENT(_to) \
  NS_SCRIPTABLE NS_IMETHOD GetType(nsIDOMSVGAnimatedEnumeration * *aType) { return !_to ? NS_ERROR_NULL_POINTER : _to->GetType(aType); } \
  NS_SCRIPTABLE NS_IMETHOD GetTableValues(nsIDOMSVGAnimatedNumberList * *aTableValues) { return !_to ? NS_ERROR_NULL_POINTER : _to->GetTableValues(aTableValues); } \
  NS_SCRIPTABLE NS_IMETHOD GetSlope(nsIDOMSVGAnimatedNumber * *aSlope) { return !_to ? NS_ERROR_NULL_POINTER : _to->GetSlope(aSlope); } \
  NS_SCRIPTABLE NS_IMETHOD GetIntercept(nsIDOMSVGAnimatedNumber * *aIntercept) { return !_to ? NS_ERROR_NULL_POINTER : _to->GetIntercept(aIntercept); } \
  NS_SCRIPTABLE NS_IMETHOD GetAmplitude(nsIDOMSVGAnimatedNumber * *aAmplitude) { return !_to ? NS_ERROR_NULL_POINTER : _to->GetAmplitude(aAmplitude); } \
  NS_SCRIPTABLE NS_IMETHOD GetExponent(nsIDOMSVGAnimatedNumber * *aExponent) { return !_to ? NS_ERROR_NULL_POINTER : _to->GetExponent(aExponent); } \
  NS_SCRIPTABLE NS_IMETHOD GetOffset(nsIDOMSVGAnimatedNumber * *aOffset) { return !_to ? NS_ERROR_NULL_POINTER : _to->GetOffset(aOffset); } 

#if 0
/* Use the code below as a template for the implementation class for this interface. */

/* Header file */
class nsDOMSVGComponentTransferFunctionElement : public nsIDOMSVGComponentTransferFunctionElement
{
public:
  NS_DECL_ISUPPORTS
  NS_DECL_NSIDOMSVGCOMPONENTTRANSFERFUNCTIONELEMENT

  nsDOMSVGComponentTransferFunctionElement();

private:
  ~nsDOMSVGComponentTransferFunctionElement();

protected:
  /* additional members */
};

/* Implementation file */
NS_IMPL_ISUPPORTS1(nsDOMSVGComponentTransferFunctionElement, nsIDOMSVGComponentTransferFunctionElement)

nsDOMSVGComponentTransferFunctionElement::nsDOMSVGComponentTransferFunctionElement()
{
  /* member initializers and constructor code */
}

nsDOMSVGComponentTransferFunctionElement::~nsDOMSVGComponentTransferFunctionElement()
{
  /* destructor code */
}

/* readonly attribute nsIDOMSVGAnimatedEnumeration type; */
NS_IMETHODIMP nsDOMSVGComponentTransferFunctionElement::GetType(nsIDOMSVGAnimatedEnumeration * *aType)
{
    return NS_ERROR_NOT_IMPLEMENTED;
}

/* readonly attribute nsIDOMSVGAnimatedNumberList tableValues; */
NS_IMETHODIMP nsDOMSVGComponentTransferFunctionElement::GetTableValues(nsIDOMSVGAnimatedNumberList * *aTableValues)
{
    return NS_ERROR_NOT_IMPLEMENTED;
}

/* readonly attribute nsIDOMSVGAnimatedNumber slope; */
NS_IMETHODIMP nsDOMSVGComponentTransferFunctionElement::GetSlope(nsIDOMSVGAnimatedNumber * *aSlope)
{
    return NS_ERROR_NOT_IMPLEMENTED;
}

/* readonly attribute nsIDOMSVGAnimatedNumber intercept; */
NS_IMETHODIMP nsDOMSVGComponentTransferFunctionElement::GetIntercept(nsIDOMSVGAnimatedNumber * *aIntercept)
{
    return NS_ERROR_NOT_IMPLEMENTED;
}

/* readonly attribute nsIDOMSVGAnimatedNumber amplitude; */
NS_IMETHODIMP nsDOMSVGComponentTransferFunctionElement::GetAmplitude(nsIDOMSVGAnimatedNumber * *aAmplitude)
{
    return NS_ERROR_NOT_IMPLEMENTED;
}

/* readonly attribute nsIDOMSVGAnimatedNumber exponent; */
NS_IMETHODIMP nsDOMSVGComponentTransferFunctionElement::GetExponent(nsIDOMSVGAnimatedNumber * *aExponent)
{
    return NS_ERROR_NOT_IMPLEMENTED;
}

/* readonly attribute nsIDOMSVGAnimatedNumber offset; */
NS_IMETHODIMP nsDOMSVGComponentTransferFunctionElement::GetOffset(nsIDOMSVGAnimatedNumber * *aOffset)
{
    return NS_ERROR_NOT_IMPLEMENTED;
}

/* End of implementation class template. */
#endif


/* starting interface:    nsIDOMSVGFECompositeElement */
#define NS_IDOMSVGFECOMPOSITEELEMENT_IID_STR "6ff3c539-1a3b-4a3f-8acd-354d349eb7fc"

#define NS_IDOMSVGFECOMPOSITEELEMENT_IID \
  {0x6ff3c539, 0x1a3b, 0x4a3f, \
    { 0x8a, 0xcd, 0x35, 0x4d, 0x34, 0x9e, 0xb7, 0xfc }}

class NS_NO_VTABLE NS_SCRIPTABLE nsIDOMSVGFECompositeElement : public nsIDOMSVGFilterPrimitiveStandardAttributes {
 public: 

  NS_DECLARE_STATIC_IID_ACCESSOR(NS_IDOMSVGFECOMPOSITEELEMENT_IID)

  enum { SVG_OPERATOR_UNKNOWN = 0U };

  enum { SVG_OPERATOR_OVER = 1U };

  enum { SVG_OPERATOR_IN = 2U };

  enum { SVG_OPERATOR_OUT = 3U };

  enum { SVG_OPERATOR_ATOP = 4U };

  enum { SVG_OPERATOR_XOR = 5U };

  enum { SVG_OPERATOR_ARITHMETIC = 6U };

  /* readonly attribute nsIDOMSVGAnimatedString in1; */
  NS_SCRIPTABLE NS_IMETHOD GetIn1(nsIDOMSVGAnimatedString * *aIn1) = 0;

  /* readonly attribute nsIDOMSVGAnimatedString in2; */
  NS_SCRIPTABLE NS_IMETHOD GetIn2(nsIDOMSVGAnimatedString * *aIn2) = 0;

  /* readonly attribute nsIDOMSVGAnimatedNumber k1; */
  NS_SCRIPTABLE NS_IMETHOD GetK1(nsIDOMSVGAnimatedNumber * *aK1) = 0;

  /* readonly attribute nsIDOMSVGAnimatedNumber k2; */
  NS_SCRIPTABLE NS_IMETHOD GetK2(nsIDOMSVGAnimatedNumber * *aK2) = 0;

  /* readonly attribute nsIDOMSVGAnimatedNumber k3; */
  NS_SCRIPTABLE NS_IMETHOD GetK3(nsIDOMSVGAnimatedNumber * *aK3) = 0;

  /* readonly attribute nsIDOMSVGAnimatedNumber k4; */
  NS_SCRIPTABLE NS_IMETHOD GetK4(nsIDOMSVGAnimatedNumber * *aK4) = 0;

  /* readonly attribute nsIDOMSVGAnimatedEnumeration operator; */
  NS_SCRIPTABLE NS_IMETHOD GetOperator(nsIDOMSVGAnimatedEnumeration * *aOperator) = 0;

  /* void setK (in float k1, in float k2, in float k3, in float k4); */
  NS_SCRIPTABLE NS_IMETHOD SetK(float k1, float k2, float k3, float k4) = 0;

};

  NS_DEFINE_STATIC_IID_ACCESSOR(nsIDOMSVGFECompositeElement, NS_IDOMSVGFECOMPOSITEELEMENT_IID)

/* Use this macro when declaring classes that implement this interface. */
#define NS_DECL_NSIDOMSVGFECOMPOSITEELEMENT \
  NS_SCRIPTABLE NS_IMETHOD GetIn1(nsIDOMSVGAnimatedString * *aIn1); \
  NS_SCRIPTABLE NS_IMETHOD GetIn2(nsIDOMSVGAnimatedString * *aIn2); \
  NS_SCRIPTABLE NS_IMETHOD GetK1(nsIDOMSVGAnimatedNumber * *aK1); \
  NS_SCRIPTABLE NS_IMETHOD GetK2(nsIDOMSVGAnimatedNumber * *aK2); \
  NS_SCRIPTABLE NS_IMETHOD GetK3(nsIDOMSVGAnimatedNumber * *aK3); \
  NS_SCRIPTABLE NS_IMETHOD GetK4(nsIDOMSVGAnimatedNumber * *aK4); \
  NS_SCRIPTABLE NS_IMETHOD GetOperator(nsIDOMSVGAnimatedEnumeration * *aOperator); \
  NS_SCRIPTABLE NS_IMETHOD SetK(float k1, float k2, float k3, float k4); 

/* Use this macro to declare functions that forward the behavior of this interface to another object. */
#define NS_FORWARD_NSIDOMSVGFECOMPOSITEELEMENT(_to) \
  NS_SCRIPTABLE NS_IMETHOD GetIn1(nsIDOMSVGAnimatedString * *aIn1) { return _to GetIn1(aIn1); } \
  NS_SCRIPTABLE NS_IMETHOD GetIn2(nsIDOMSVGAnimatedString * *aIn2) { return _to GetIn2(aIn2); } \
  NS_SCRIPTABLE NS_IMETHOD GetK1(nsIDOMSVGAnimatedNumber * *aK1) { return _to GetK1(aK1); } \
  NS_SCRIPTABLE NS_IMETHOD GetK2(nsIDOMSVGAnimatedNumber * *aK2) { return _to GetK2(aK2); } \
  NS_SCRIPTABLE NS_IMETHOD GetK3(nsIDOMSVGAnimatedNumber * *aK3) { return _to GetK3(aK3); } \
  NS_SCRIPTABLE NS_IMETHOD GetK4(nsIDOMSVGAnimatedNumber * *aK4) { return _to GetK4(aK4); } \
  NS_SCRIPTABLE NS_IMETHOD GetOperator(nsIDOMSVGAnimatedEnumeration * *aOperator) { return _to GetOperator(aOperator); } \
  NS_SCRIPTABLE NS_IMETHOD SetK(float k1, float k2, float k3, float k4) { return _to SetK(k1, k2, k3, k4); } 

/* Use this macro to declare functions that forward the behavior of this interface to another object in a safe way. */
#define NS_FORWARD_SAFE_NSIDOMSVGFECOMPOSITEELEMENT(_to) \
  NS_SCRIPTABLE NS_IMETHOD GetIn1(nsIDOMSVGAnimatedString * *aIn1) { return !_to ? NS_ERROR_NULL_POINTER : _to->GetIn1(aIn1); } \
  NS_SCRIPTABLE NS_IMETHOD GetIn2(nsIDOMSVGAnimatedString * *aIn2) { return !_to ? NS_ERROR_NULL_POINTER : _to->GetIn2(aIn2); } \
  NS_SCRIPTABLE NS_IMETHOD GetK1(nsIDOMSVGAnimatedNumber * *aK1) { return !_to ? NS_ERROR_NULL_POINTER : _to->GetK1(aK1); } \
  NS_SCRIPTABLE NS_IMETHOD GetK2(nsIDOMSVGAnimatedNumber * *aK2) { return !_to ? NS_ERROR_NULL_POINTER : _to->GetK2(aK2); } \
  NS_SCRIPTABLE NS_IMETHOD GetK3(nsIDOMSVGAnimatedNumber * *aK3) { return !_to ? NS_ERROR_NULL_POINTER : _to->GetK3(aK3); } \
  NS_SCRIPTABLE NS_IMETHOD GetK4(nsIDOMSVGAnimatedNumber * *aK4) { return !_to ? NS_ERROR_NULL_POINTER : _to->GetK4(aK4); } \
  NS_SCRIPTABLE NS_IMETHOD GetOperator(nsIDOMSVGAnimatedEnumeration * *aOperator) { return !_to ? NS_ERROR_NULL_POINTER : _to->GetOperator(aOperator); } \
  NS_SCRIPTABLE NS_IMETHOD SetK(float k1, float k2, float k3, float k4) { return !_to ? NS_ERROR_NULL_POINTER : _to->SetK(k1, k2, k3, k4); } 

#if 0
/* Use the code below as a template for the implementation class for this interface. */

/* Header file */
class nsDOMSVGFECompositeElement : public nsIDOMSVGFECompositeElement
{
public:
  NS_DECL_ISUPPORTS
  NS_DECL_NSIDOMSVGFECOMPOSITEELEMENT

  nsDOMSVGFECompositeElement();

private:
  ~nsDOMSVGFECompositeElement();

protected:
  /* additional members */
};

/* Implementation file */
NS_IMPL_ISUPPORTS1(nsDOMSVGFECompositeElement, nsIDOMSVGFECompositeElement)

nsDOMSVGFECompositeElement::nsDOMSVGFECompositeElement()
{
  /* member initializers and constructor code */
}

nsDOMSVGFECompositeElement::~nsDOMSVGFECompositeElement()
{
  /* destructor code */
}

/* readonly attribute nsIDOMSVGAnimatedString in1; */
NS_IMETHODIMP nsDOMSVGFECompositeElement::GetIn1(nsIDOMSVGAnimatedString * *aIn1)
{
    return NS_ERROR_NOT_IMPLEMENTED;
}

/* readonly attribute nsIDOMSVGAnimatedString in2; */
NS_IMETHODIMP nsDOMSVGFECompositeElement::GetIn2(nsIDOMSVGAnimatedString * *aIn2)
{
    return NS_ERROR_NOT_IMPLEMENTED;
}

/* readonly attribute nsIDOMSVGAnimatedNumber k1; */
NS_IMETHODIMP nsDOMSVGFECompositeElement::GetK1(nsIDOMSVGAnimatedNumber * *aK1)
{
    return NS_ERROR_NOT_IMPLEMENTED;
}

/* readonly attribute nsIDOMSVGAnimatedNumber k2; */
NS_IMETHODIMP nsDOMSVGFECompositeElement::GetK2(nsIDOMSVGAnimatedNumber * *aK2)
{
    return NS_ERROR_NOT_IMPLEMENTED;
}

/* readonly attribute nsIDOMSVGAnimatedNumber k3; */
NS_IMETHODIMP nsDOMSVGFECompositeElement::GetK3(nsIDOMSVGAnimatedNumber * *aK3)
{
    return NS_ERROR_NOT_IMPLEMENTED;
}

/* readonly attribute nsIDOMSVGAnimatedNumber k4; */
NS_IMETHODIMP nsDOMSVGFECompositeElement::GetK4(nsIDOMSVGAnimatedNumber * *aK4)
{
    return NS_ERROR_NOT_IMPLEMENTED;
}

/* readonly attribute nsIDOMSVGAnimatedEnumeration operator; */
NS_IMETHODIMP nsDOMSVGFECompositeElement::GetOperator(nsIDOMSVGAnimatedEnumeration * *aOperator)
{
    return NS_ERROR_NOT_IMPLEMENTED;
}

/* void setK (in float k1, in float k2, in float k3, in float k4); */
NS_IMETHODIMP nsDOMSVGFECompositeElement::SetK(float k1, float k2, float k3, float k4)
{
    return NS_ERROR_NOT_IMPLEMENTED;
}

/* End of implementation class template. */
#endif


/* starting interface:    nsIDOMSVGFEFuncRElement */
#define NS_IDOMSVGFEFUNCRELEMENT_IID_STR "85719a5d-9688-4c5f-bad5-c21847515200"

#define NS_IDOMSVGFEFUNCRELEMENT_IID \
  {0x85719a5d, 0x9688, 0x4c5f, \
    { 0xba, 0xd5, 0xc2, 0x18, 0x47, 0x51, 0x52, 0x00 }}

class NS_NO_VTABLE NS_SCRIPTABLE nsIDOMSVGFEFuncRElement : public nsIDOMSVGComponentTransferFunctionElement {
 public: 

  NS_DECLARE_STATIC_IID_ACCESSOR(NS_IDOMSVGFEFUNCRELEMENT_IID)

};

  NS_DEFINE_STATIC_IID_ACCESSOR(nsIDOMSVGFEFuncRElement, NS_IDOMSVGFEFUNCRELEMENT_IID)

/* Use this macro when declaring classes that implement this interface. */
#define NS_DECL_NSIDOMSVGFEFUNCRELEMENT \
  /* no methods! */

/* Use this macro to declare functions that forward the behavior of this interface to another object. */
#define NS_FORWARD_NSIDOMSVGFEFUNCRELEMENT(_to) \
  /* no methods! */

/* Use this macro to declare functions that forward the behavior of this interface to another object in a safe way. */
#define NS_FORWARD_SAFE_NSIDOMSVGFEFUNCRELEMENT(_to) \
  /* no methods! */

#if 0
/* Use the code below as a template for the implementation class for this interface. */

/* Header file */
class nsDOMSVGFEFuncRElement : public nsIDOMSVGFEFuncRElement
{
public:
  NS_DECL_ISUPPORTS
  NS_DECL_NSIDOMSVGFEFUNCRELEMENT

  nsDOMSVGFEFuncRElement();

private:
  ~nsDOMSVGFEFuncRElement();

protected:
  /* additional members */
};

/* Implementation file */
NS_IMPL_ISUPPORTS1(nsDOMSVGFEFuncRElement, nsIDOMSVGFEFuncRElement)

nsDOMSVGFEFuncRElement::nsDOMSVGFEFuncRElement()
{
  /* member initializers and constructor code */
}

nsDOMSVGFEFuncRElement::~nsDOMSVGFEFuncRElement()
{
  /* destructor code */
}

/* End of implementation class template. */
#endif


/* starting interface:    nsIDOMSVGFEFuncGElement */
#define NS_IDOMSVGFEFUNCGELEMENT_IID_STR "28555e78-c6c2-4a98-af53-bfc2c6944295"

#define NS_IDOMSVGFEFUNCGELEMENT_IID \
  {0x28555e78, 0xc6c2, 0x4a98, \
    { 0xaf, 0x53, 0xbf, 0xc2, 0xc6, 0x94, 0x42, 0x95 }}

class NS_NO_VTABLE NS_SCRIPTABLE nsIDOMSVGFEFuncGElement : public nsIDOMSVGComponentTransferFunctionElement {
 public: 

  NS_DECLARE_STATIC_IID_ACCESSOR(NS_IDOMSVGFEFUNCGELEMENT_IID)

};

  NS_DEFINE_STATIC_IID_ACCESSOR(nsIDOMSVGFEFuncGElement, NS_IDOMSVGFEFUNCGELEMENT_IID)

/* Use this macro when declaring classes that implement this interface. */
#define NS_DECL_NSIDOMSVGFEFUNCGELEMENT \
  /* no methods! */

/* Use this macro to declare functions that forward the behavior of this interface to another object. */
#define NS_FORWARD_NSIDOMSVGFEFUNCGELEMENT(_to) \
  /* no methods! */

/* Use this macro to declare functions that forward the behavior of this interface to another object in a safe way. */
#define NS_FORWARD_SAFE_NSIDOMSVGFEFUNCGELEMENT(_to) \
  /* no methods! */

#if 0
/* Use the code below as a template for the implementation class for this interface. */

/* Header file */
class nsDOMSVGFEFuncGElement : public nsIDOMSVGFEFuncGElement
{
public:
  NS_DECL_ISUPPORTS
  NS_DECL_NSIDOMSVGFEFUNCGELEMENT

  nsDOMSVGFEFuncGElement();

private:
  ~nsDOMSVGFEFuncGElement();

protected:
  /* additional members */
};

/* Implementation file */
NS_IMPL_ISUPPORTS1(nsDOMSVGFEFuncGElement, nsIDOMSVGFEFuncGElement)

nsDOMSVGFEFuncGElement::nsDOMSVGFEFuncGElement()
{
  /* member initializers and constructor code */
}

nsDOMSVGFEFuncGElement::~nsDOMSVGFEFuncGElement()
{
  /* destructor code */
}

/* End of implementation class template. */
#endif


/* starting interface:    nsIDOMSVGFEFuncBElement */
#define NS_IDOMSVGFEFUNCBELEMENT_IID_STR "8b139fe7-5d21-4af3-beda-414aa089b3fb"

#define NS_IDOMSVGFEFUNCBELEMENT_IID \
  {0x8b139fe7, 0x5d21, 0x4af3, \
    { 0xbe, 0xda, 0x41, 0x4a, 0xa0, 0x89, 0xb3, 0xfb }}

class NS_NO_VTABLE NS_SCRIPTABLE nsIDOMSVGFEFuncBElement : public nsIDOMSVGComponentTransferFunctionElement {
 public: 

  NS_DECLARE_STATIC_IID_ACCESSOR(NS_IDOMSVGFEFUNCBELEMENT_IID)

};

  NS_DEFINE_STATIC_IID_ACCESSOR(nsIDOMSVGFEFuncBElement, NS_IDOMSVGFEFUNCBELEMENT_IID)

/* Use this macro when declaring classes that implement this interface. */
#define NS_DECL_NSIDOMSVGFEFUNCBELEMENT \
  /* no methods! */

/* Use this macro to declare functions that forward the behavior of this interface to another object. */
#define NS_FORWARD_NSIDOMSVGFEFUNCBELEMENT(_to) \
  /* no methods! */

/* Use this macro to declare functions that forward the behavior of this interface to another object in a safe way. */
#define NS_FORWARD_SAFE_NSIDOMSVGFEFUNCBELEMENT(_to) \
  /* no methods! */

#if 0
/* Use the code below as a template for the implementation class for this interface. */

/* Header file */
class nsDOMSVGFEFuncBElement : public nsIDOMSVGFEFuncBElement
{
public:
  NS_DECL_ISUPPORTS
  NS_DECL_NSIDOMSVGFEFUNCBELEMENT

  nsDOMSVGFEFuncBElement();

private:
  ~nsDOMSVGFEFuncBElement();

protected:
  /* additional members */
};

/* Implementation file */
NS_IMPL_ISUPPORTS1(nsDOMSVGFEFuncBElement, nsIDOMSVGFEFuncBElement)

nsDOMSVGFEFuncBElement::nsDOMSVGFEFuncBElement()
{
  /* member initializers and constructor code */
}

nsDOMSVGFEFuncBElement::~nsDOMSVGFEFuncBElement()
{
  /* destructor code */
}

/* End of implementation class template. */
#endif


/* starting interface:    nsIDOMSVGFEFuncAElement */
#define NS_IDOMSVGFEFUNCAELEMENT_IID_STR "fa48511c-283a-437f-9507-c309ac6f0f57"

#define NS_IDOMSVGFEFUNCAELEMENT_IID \
  {0xfa48511c, 0x283a, 0x437f, \
    { 0x95, 0x07, 0xc3, 0x09, 0xac, 0x6f, 0x0f, 0x57 }}

class NS_NO_VTABLE NS_SCRIPTABLE nsIDOMSVGFEFuncAElement : public nsIDOMSVGComponentTransferFunctionElement {
 public: 

  NS_DECLARE_STATIC_IID_ACCESSOR(NS_IDOMSVGFEFUNCAELEMENT_IID)

};

  NS_DEFINE_STATIC_IID_ACCESSOR(nsIDOMSVGFEFuncAElement, NS_IDOMSVGFEFUNCAELEMENT_IID)

/* Use this macro when declaring classes that implement this interface. */
#define NS_DECL_NSIDOMSVGFEFUNCAELEMENT \
  /* no methods! */

/* Use this macro to declare functions that forward the behavior of this interface to another object. */
#define NS_FORWARD_NSIDOMSVGFEFUNCAELEMENT(_to) \
  /* no methods! */

/* Use this macro to declare functions that forward the behavior of this interface to another object in a safe way. */
#define NS_FORWARD_SAFE_NSIDOMSVGFEFUNCAELEMENT(_to) \
  /* no methods! */

#if 0
/* Use the code below as a template for the implementation class for this interface. */

/* Header file */
class nsDOMSVGFEFuncAElement : public nsIDOMSVGFEFuncAElement
{
public:
  NS_DECL_ISUPPORTS
  NS_DECL_NSIDOMSVGFEFUNCAELEMENT

  nsDOMSVGFEFuncAElement();

private:
  ~nsDOMSVGFEFuncAElement();

protected:
  /* additional members */
};

/* Implementation file */
NS_IMPL_ISUPPORTS1(nsDOMSVGFEFuncAElement, nsIDOMSVGFEFuncAElement)

nsDOMSVGFEFuncAElement::nsDOMSVGFEFuncAElement()
{
  /* member initializers and constructor code */
}

nsDOMSVGFEFuncAElement::~nsDOMSVGFEFuncAElement()
{
  /* destructor code */
}

/* End of implementation class template. */
#endif


/* starting interface:    nsIDOMSVGFEGaussianBlurElement */
#define NS_IDOMSVGFEGAUSSIANBLURELEMENT_IID_STR "43ff8d42-3380-4dbd-a916-7c2daa3ed7f4"

#define NS_IDOMSVGFEGAUSSIANBLURELEMENT_IID \
  {0x43ff8d42, 0x3380, 0x4dbd, \
    { 0xa9, 0x16, 0x7c, 0x2d, 0xaa, 0x3e, 0xd7, 0xf4 }}

class NS_NO_VTABLE NS_SCRIPTABLE nsIDOMSVGFEGaussianBlurElement : public nsIDOMSVGFilterPrimitiveStandardAttributes {
 public: 

  NS_DECLARE_STATIC_IID_ACCESSOR(NS_IDOMSVGFEGAUSSIANBLURELEMENT_IID)

  /* readonly attribute nsIDOMSVGAnimatedString in1; */
  NS_SCRIPTABLE NS_IMETHOD GetIn1(nsIDOMSVGAnimatedString * *aIn1) = 0;

  /* readonly attribute nsIDOMSVGAnimatedNumber stdDeviationX; */
  NS_SCRIPTABLE NS_IMETHOD GetStdDeviationX(nsIDOMSVGAnimatedNumber * *aStdDeviationX) = 0;

  /* readonly attribute nsIDOMSVGAnimatedNumber stdDeviationY; */
  NS_SCRIPTABLE NS_IMETHOD GetStdDeviationY(nsIDOMSVGAnimatedNumber * *aStdDeviationY) = 0;

  /* void setStdDeviation (in float stdDeviationX, in float stdDeviationY); */
  NS_SCRIPTABLE NS_IMETHOD SetStdDeviation(float stdDeviationX, float stdDeviationY) = 0;

};

  NS_DEFINE_STATIC_IID_ACCESSOR(nsIDOMSVGFEGaussianBlurElement, NS_IDOMSVGFEGAUSSIANBLURELEMENT_IID)

/* Use this macro when declaring classes that implement this interface. */
#define NS_DECL_NSIDOMSVGFEGAUSSIANBLURELEMENT \
  NS_SCRIPTABLE NS_IMETHOD GetIn1(nsIDOMSVGAnimatedString * *aIn1); \
  NS_SCRIPTABLE NS_IMETHOD GetStdDeviationX(nsIDOMSVGAnimatedNumber * *aStdDeviationX); \
  NS_SCRIPTABLE NS_IMETHOD GetStdDeviationY(nsIDOMSVGAnimatedNumber * *aStdDeviationY); \
  NS_SCRIPTABLE NS_IMETHOD SetStdDeviation(float stdDeviationX, float stdDeviationY); 

/* Use this macro to declare functions that forward the behavior of this interface to another object. */
#define NS_FORWARD_NSIDOMSVGFEGAUSSIANBLURELEMENT(_to) \
  NS_SCRIPTABLE NS_IMETHOD GetIn1(nsIDOMSVGAnimatedString * *aIn1) { return _to GetIn1(aIn1); } \
  NS_SCRIPTABLE NS_IMETHOD GetStdDeviationX(nsIDOMSVGAnimatedNumber * *aStdDeviationX) { return _to GetStdDeviationX(aStdDeviationX); } \
  NS_SCRIPTABLE NS_IMETHOD GetStdDeviationY(nsIDOMSVGAnimatedNumber * *aStdDeviationY) { return _to GetStdDeviationY(aStdDeviationY); } \
  NS_SCRIPTABLE NS_IMETHOD SetStdDeviation(float stdDeviationX, float stdDeviationY) { return _to SetStdDeviation(stdDeviationX, stdDeviationY); } 

/* Use this macro to declare functions that forward the behavior of this interface to another object in a safe way. */
#define NS_FORWARD_SAFE_NSIDOMSVGFEGAUSSIANBLURELEMENT(_to) \
  NS_SCRIPTABLE NS_IMETHOD GetIn1(nsIDOMSVGAnimatedString * *aIn1) { return !_to ? NS_ERROR_NULL_POINTER : _to->GetIn1(aIn1); } \
  NS_SCRIPTABLE NS_IMETHOD GetStdDeviationX(nsIDOMSVGAnimatedNumber * *aStdDeviationX) { return !_to ? NS_ERROR_NULL_POINTER : _to->GetStdDeviationX(aStdDeviationX); } \
  NS_SCRIPTABLE NS_IMETHOD GetStdDeviationY(nsIDOMSVGAnimatedNumber * *aStdDeviationY) { return !_to ? NS_ERROR_NULL_POINTER : _to->GetStdDeviationY(aStdDeviationY); } \
  NS_SCRIPTABLE NS_IMETHOD SetStdDeviation(float stdDeviationX, float stdDeviationY) { return !_to ? NS_ERROR_NULL_POINTER : _to->SetStdDeviation(stdDeviationX, stdDeviationY); } 

#if 0
/* Use the code below as a template for the implementation class for this interface. */

/* Header file */
class nsDOMSVGFEGaussianBlurElement : public nsIDOMSVGFEGaussianBlurElement
{
public:
  NS_DECL_ISUPPORTS
  NS_DECL_NSIDOMSVGFEGAUSSIANBLURELEMENT

  nsDOMSVGFEGaussianBlurElement();

private:
  ~nsDOMSVGFEGaussianBlurElement();

protected:
  /* additional members */
};

/* Implementation file */
NS_IMPL_ISUPPORTS1(nsDOMSVGFEGaussianBlurElement, nsIDOMSVGFEGaussianBlurElement)

nsDOMSVGFEGaussianBlurElement::nsDOMSVGFEGaussianBlurElement()
{
  /* member initializers and constructor code */
}

nsDOMSVGFEGaussianBlurElement::~nsDOMSVGFEGaussianBlurElement()
{
  /* destructor code */
}

/* readonly attribute nsIDOMSVGAnimatedString in1; */
NS_IMETHODIMP nsDOMSVGFEGaussianBlurElement::GetIn1(nsIDOMSVGAnimatedString * *aIn1)
{
    return NS_ERROR_NOT_IMPLEMENTED;
}

/* readonly attribute nsIDOMSVGAnimatedNumber stdDeviationX; */
NS_IMETHODIMP nsDOMSVGFEGaussianBlurElement::GetStdDeviationX(nsIDOMSVGAnimatedNumber * *aStdDeviationX)
{
    return NS_ERROR_NOT_IMPLEMENTED;
}

/* readonly attribute nsIDOMSVGAnimatedNumber stdDeviationY; */
NS_IMETHODIMP nsDOMSVGFEGaussianBlurElement::GetStdDeviationY(nsIDOMSVGAnimatedNumber * *aStdDeviationY)
{
    return NS_ERROR_NOT_IMPLEMENTED;
}

/* void setStdDeviation (in float stdDeviationX, in float stdDeviationY); */
NS_IMETHODIMP nsDOMSVGFEGaussianBlurElement::SetStdDeviation(float stdDeviationX, float stdDeviationY)
{
    return NS_ERROR_NOT_IMPLEMENTED;
}

/* End of implementation class template. */
#endif


/* starting interface:    nsIDOMSVGFEMergeElement */
#define NS_IDOMSVGFEMERGEELEMENT_IID_STR "b860512c-2547-4d1f-bb43-b57b54d39014"

#define NS_IDOMSVGFEMERGEELEMENT_IID \
  {0xb860512c, 0x2547, 0x4d1f, \
    { 0xbb, 0x43, 0xb5, 0x7b, 0x54, 0xd3, 0x90, 0x14 }}

class NS_NO_VTABLE NS_SCRIPTABLE nsIDOMSVGFEMergeElement : public nsIDOMSVGFilterPrimitiveStandardAttributes {
 public: 

  NS_DECLARE_STATIC_IID_ACCESSOR(NS_IDOMSVGFEMERGEELEMENT_IID)

};

  NS_DEFINE_STATIC_IID_ACCESSOR(nsIDOMSVGFEMergeElement, NS_IDOMSVGFEMERGEELEMENT_IID)

/* Use this macro when declaring classes that implement this interface. */
#define NS_DECL_NSIDOMSVGFEMERGEELEMENT \
  /* no methods! */

/* Use this macro to declare functions that forward the behavior of this interface to another object. */
#define NS_FORWARD_NSIDOMSVGFEMERGEELEMENT(_to) \
  /* no methods! */

/* Use this macro to declare functions that forward the behavior of this interface to another object in a safe way. */
#define NS_FORWARD_SAFE_NSIDOMSVGFEMERGEELEMENT(_to) \
  /* no methods! */

#if 0
/* Use the code below as a template for the implementation class for this interface. */

/* Header file */
class nsDOMSVGFEMergeElement : public nsIDOMSVGFEMergeElement
{
public:
  NS_DECL_ISUPPORTS
  NS_DECL_NSIDOMSVGFEMERGEELEMENT

  nsDOMSVGFEMergeElement();

private:
  ~nsDOMSVGFEMergeElement();

protected:
  /* additional members */
};

/* Implementation file */
NS_IMPL_ISUPPORTS1(nsDOMSVGFEMergeElement, nsIDOMSVGFEMergeElement)

nsDOMSVGFEMergeElement::nsDOMSVGFEMergeElement()
{
  /* member initializers and constructor code */
}

nsDOMSVGFEMergeElement::~nsDOMSVGFEMergeElement()
{
  /* destructor code */
}

/* End of implementation class template. */
#endif


/* starting interface:    nsIDOMSVGFEMergeNodeElement */
#define NS_IDOMSVGFEMERGENODEELEMENT_IID_STR "540c3447-4b07-4bd3-84df-30f66b68df14"

#define NS_IDOMSVGFEMERGENODEELEMENT_IID \
  {0x540c3447, 0x4b07, 0x4bd3, \
    { 0x84, 0xdf, 0x30, 0xf6, 0x6b, 0x68, 0xdf, 0x14 }}

class NS_NO_VTABLE NS_SCRIPTABLE nsIDOMSVGFEMergeNodeElement : public nsIDOMSVGElement {
 public: 

  NS_DECLARE_STATIC_IID_ACCESSOR(NS_IDOMSVGFEMERGENODEELEMENT_IID)

  /* readonly attribute nsIDOMSVGAnimatedString in1; */
  NS_SCRIPTABLE NS_IMETHOD GetIn1(nsIDOMSVGAnimatedString * *aIn1) = 0;

};

  NS_DEFINE_STATIC_IID_ACCESSOR(nsIDOMSVGFEMergeNodeElement, NS_IDOMSVGFEMERGENODEELEMENT_IID)

/* Use this macro when declaring classes that implement this interface. */
#define NS_DECL_NSIDOMSVGFEMERGENODEELEMENT \
  NS_SCRIPTABLE NS_IMETHOD GetIn1(nsIDOMSVGAnimatedString * *aIn1); 

/* Use this macro to declare functions that forward the behavior of this interface to another object. */
#define NS_FORWARD_NSIDOMSVGFEMERGENODEELEMENT(_to) \
  NS_SCRIPTABLE NS_IMETHOD GetIn1(nsIDOMSVGAnimatedString * *aIn1) { return _to GetIn1(aIn1); } 

/* Use this macro to declare functions that forward the behavior of this interface to another object in a safe way. */
#define NS_FORWARD_SAFE_NSIDOMSVGFEMERGENODEELEMENT(_to) \
  NS_SCRIPTABLE NS_IMETHOD GetIn1(nsIDOMSVGAnimatedString * *aIn1) { return !_to ? NS_ERROR_NULL_POINTER : _to->GetIn1(aIn1); } 

#if 0
/* Use the code below as a template for the implementation class for this interface. */

/* Header file */
class nsDOMSVGFEMergeNodeElement : public nsIDOMSVGFEMergeNodeElement
{
public:
  NS_DECL_ISUPPORTS
  NS_DECL_NSIDOMSVGFEMERGENODEELEMENT

  nsDOMSVGFEMergeNodeElement();

private:
  ~nsDOMSVGFEMergeNodeElement();

protected:
  /* additional members */
};

/* Implementation file */
NS_IMPL_ISUPPORTS1(nsDOMSVGFEMergeNodeElement, nsIDOMSVGFEMergeNodeElement)

nsDOMSVGFEMergeNodeElement::nsDOMSVGFEMergeNodeElement()
{
  /* member initializers and constructor code */
}

nsDOMSVGFEMergeNodeElement::~nsDOMSVGFEMergeNodeElement()
{
  /* destructor code */
}

/* readonly attribute nsIDOMSVGAnimatedString in1; */
NS_IMETHODIMP nsDOMSVGFEMergeNodeElement::GetIn1(nsIDOMSVGAnimatedString * *aIn1)
{
    return NS_ERROR_NOT_IMPLEMENTED;
}

/* End of implementation class template. */
#endif


/* starting interface:    nsIDOMSVGFEOffsetElement */
#define NS_IDOMSVGFEOFFSETELEMENT_IID_STR "c080f191-b22c-4fc0-85d5-a79dc3fa7ec8"

#define NS_IDOMSVGFEOFFSETELEMENT_IID \
  {0xc080f191, 0xb22c, 0x4fc0, \
    { 0x85, 0xd5, 0xa7, 0x9d, 0xc3, 0xfa, 0x7e, 0xc8 }}

class NS_NO_VTABLE NS_SCRIPTABLE nsIDOMSVGFEOffsetElement : public nsIDOMSVGFilterPrimitiveStandardAttributes {
 public: 

  NS_DECLARE_STATIC_IID_ACCESSOR(NS_IDOMSVGFEOFFSETELEMENT_IID)

  /* readonly attribute nsIDOMSVGAnimatedString in1; */
  NS_SCRIPTABLE NS_IMETHOD GetIn1(nsIDOMSVGAnimatedString * *aIn1) = 0;

  /* readonly attribute nsIDOMSVGAnimatedNumber dx; */
  NS_SCRIPTABLE NS_IMETHOD GetDx(nsIDOMSVGAnimatedNumber * *aDx) = 0;

  /* readonly attribute nsIDOMSVGAnimatedNumber dy; */
  NS_SCRIPTABLE NS_IMETHOD GetDy(nsIDOMSVGAnimatedNumber * *aDy) = 0;

};

  NS_DEFINE_STATIC_IID_ACCESSOR(nsIDOMSVGFEOffsetElement, NS_IDOMSVGFEOFFSETELEMENT_IID)

/* Use this macro when declaring classes that implement this interface. */
#define NS_DECL_NSIDOMSVGFEOFFSETELEMENT \
  NS_SCRIPTABLE NS_IMETHOD GetIn1(nsIDOMSVGAnimatedString * *aIn1); \
  NS_SCRIPTABLE NS_IMETHOD GetDx(nsIDOMSVGAnimatedNumber * *aDx); \
  NS_SCRIPTABLE NS_IMETHOD GetDy(nsIDOMSVGAnimatedNumber * *aDy); 

/* Use this macro to declare functions that forward the behavior of this interface to another object. */
#define NS_FORWARD_NSIDOMSVGFEOFFSETELEMENT(_to) \
  NS_SCRIPTABLE NS_IMETHOD GetIn1(nsIDOMSVGAnimatedString * *aIn1) { return _to GetIn1(aIn1); } \
  NS_SCRIPTABLE NS_IMETHOD GetDx(nsIDOMSVGAnimatedNumber * *aDx) { return _to GetDx(aDx); } \
  NS_SCRIPTABLE NS_IMETHOD GetDy(nsIDOMSVGAnimatedNumber * *aDy) { return _to GetDy(aDy); } 

/* Use this macro to declare functions that forward the behavior of this interface to another object in a safe way. */
#define NS_FORWARD_SAFE_NSIDOMSVGFEOFFSETELEMENT(_to) \
  NS_SCRIPTABLE NS_IMETHOD GetIn1(nsIDOMSVGAnimatedString * *aIn1) { return !_to ? NS_ERROR_NULL_POINTER : _to->GetIn1(aIn1); } \
  NS_SCRIPTABLE NS_IMETHOD GetDx(nsIDOMSVGAnimatedNumber * *aDx) { return !_to ? NS_ERROR_NULL_POINTER : _to->GetDx(aDx); } \
  NS_SCRIPTABLE NS_IMETHOD GetDy(nsIDOMSVGAnimatedNumber * *aDy) { return !_to ? NS_ERROR_NULL_POINTER : _to->GetDy(aDy); } 

#if 0
/* Use the code below as a template for the implementation class for this interface. */

/* Header file */
class nsDOMSVGFEOffsetElement : public nsIDOMSVGFEOffsetElement
{
public:
  NS_DECL_ISUPPORTS
  NS_DECL_NSIDOMSVGFEOFFSETELEMENT

  nsDOMSVGFEOffsetElement();

private:
  ~nsDOMSVGFEOffsetElement();

protected:
  /* additional members */
};

/* Implementation file */
NS_IMPL_ISUPPORTS1(nsDOMSVGFEOffsetElement, nsIDOMSVGFEOffsetElement)

nsDOMSVGFEOffsetElement::nsDOMSVGFEOffsetElement()
{
  /* member initializers and constructor code */
}

nsDOMSVGFEOffsetElement::~nsDOMSVGFEOffsetElement()
{
  /* destructor code */
}

/* readonly attribute nsIDOMSVGAnimatedString in1; */
NS_IMETHODIMP nsDOMSVGFEOffsetElement::GetIn1(nsIDOMSVGAnimatedString * *aIn1)
{
    return NS_ERROR_NOT_IMPLEMENTED;
}

/* readonly attribute nsIDOMSVGAnimatedNumber dx; */
NS_IMETHODIMP nsDOMSVGFEOffsetElement::GetDx(nsIDOMSVGAnimatedNumber * *aDx)
{
    return NS_ERROR_NOT_IMPLEMENTED;
}

/* readonly attribute nsIDOMSVGAnimatedNumber dy; */
NS_IMETHODIMP nsDOMSVGFEOffsetElement::GetDy(nsIDOMSVGAnimatedNumber * *aDy)
{
    return NS_ERROR_NOT_IMPLEMENTED;
}

/* End of implementation class template. */
#endif


/* starting interface:    nsIDOMSVGFEFloodElement */
#define NS_IDOMSVGFEFLOODELEMENT_IID_STR "2743af95-28c5-429d-9812-12b7b017887e"

#define NS_IDOMSVGFEFLOODELEMENT_IID \
  {0x2743af95, 0x28c5, 0x429d, \
    { 0x98, 0x12, 0x12, 0xb7, 0xb0, 0x17, 0x88, 0x7e }}

class NS_NO_VTABLE NS_SCRIPTABLE nsIDOMSVGFEFloodElement : public nsIDOMSVGFilterPrimitiveStandardAttributes {
 public: 

  NS_DECLARE_STATIC_IID_ACCESSOR(NS_IDOMSVGFEFLOODELEMENT_IID)

};

  NS_DEFINE_STATIC_IID_ACCESSOR(nsIDOMSVGFEFloodElement, NS_IDOMSVGFEFLOODELEMENT_IID)

/* Use this macro when declaring classes that implement this interface. */
#define NS_DECL_NSIDOMSVGFEFLOODELEMENT \
  /* no methods! */

/* Use this macro to declare functions that forward the behavior of this interface to another object. */
#define NS_FORWARD_NSIDOMSVGFEFLOODELEMENT(_to) \
  /* no methods! */

/* Use this macro to declare functions that forward the behavior of this interface to another object in a safe way. */
#define NS_FORWARD_SAFE_NSIDOMSVGFEFLOODELEMENT(_to) \
  /* no methods! */

#if 0
/* Use the code below as a template for the implementation class for this interface. */

/* Header file */
class nsDOMSVGFEFloodElement : public nsIDOMSVGFEFloodElement
{
public:
  NS_DECL_ISUPPORTS
  NS_DECL_NSIDOMSVGFEFLOODELEMENT

  nsDOMSVGFEFloodElement();

private:
  ~nsDOMSVGFEFloodElement();

protected:
  /* additional members */
};

/* Implementation file */
NS_IMPL_ISUPPORTS1(nsDOMSVGFEFloodElement, nsIDOMSVGFEFloodElement)

nsDOMSVGFEFloodElement::nsDOMSVGFEFloodElement()
{
  /* member initializers and constructor code */
}

nsDOMSVGFEFloodElement::~nsDOMSVGFEFloodElement()
{
  /* destructor code */
}

/* End of implementation class template. */
#endif


/* starting interface:    nsIDOMSVGFETileElement */
#define NS_IDOMSVGFETILEELEMENT_IID_STR "ed042a81-39fc-4c89-9385-75758a2434b5"

#define NS_IDOMSVGFETILEELEMENT_IID \
  {0xed042a81, 0x39fc, 0x4c89, \
    { 0x93, 0x85, 0x75, 0x75, 0x8a, 0x24, 0x34, 0xb5 }}

class NS_NO_VTABLE NS_SCRIPTABLE nsIDOMSVGFETileElement : public nsIDOMSVGFilterPrimitiveStandardAttributes {
 public: 

  NS_DECLARE_STATIC_IID_ACCESSOR(NS_IDOMSVGFETILEELEMENT_IID)

  /* readonly attribute nsIDOMSVGAnimatedString in1; */
  NS_SCRIPTABLE NS_IMETHOD GetIn1(nsIDOMSVGAnimatedString * *aIn1) = 0;

};

  NS_DEFINE_STATIC_IID_ACCESSOR(nsIDOMSVGFETileElement, NS_IDOMSVGFETILEELEMENT_IID)

/* Use this macro when declaring classes that implement this interface. */
#define NS_DECL_NSIDOMSVGFETILEELEMENT \
  NS_SCRIPTABLE NS_IMETHOD GetIn1(nsIDOMSVGAnimatedString * *aIn1); 

/* Use this macro to declare functions that forward the behavior of this interface to another object. */
#define NS_FORWARD_NSIDOMSVGFETILEELEMENT(_to) \
  NS_SCRIPTABLE NS_IMETHOD GetIn1(nsIDOMSVGAnimatedString * *aIn1) { return _to GetIn1(aIn1); } 

/* Use this macro to declare functions that forward the behavior of this interface to another object in a safe way. */
#define NS_FORWARD_SAFE_NSIDOMSVGFETILEELEMENT(_to) \
  NS_SCRIPTABLE NS_IMETHOD GetIn1(nsIDOMSVGAnimatedString * *aIn1) { return !_to ? NS_ERROR_NULL_POINTER : _to->GetIn1(aIn1); } 

#if 0
/* Use the code below as a template for the implementation class for this interface. */

/* Header file */
class nsDOMSVGFETileElement : public nsIDOMSVGFETileElement
{
public:
  NS_DECL_ISUPPORTS
  NS_DECL_NSIDOMSVGFETILEELEMENT

  nsDOMSVGFETileElement();

private:
  ~nsDOMSVGFETileElement();

protected:
  /* additional members */
};

/* Implementation file */
NS_IMPL_ISUPPORTS1(nsDOMSVGFETileElement, nsIDOMSVGFETileElement)

nsDOMSVGFETileElement::nsDOMSVGFETileElement()
{
  /* member initializers and constructor code */
}

nsDOMSVGFETileElement::~nsDOMSVGFETileElement()
{
  /* destructor code */
}

/* readonly attribute nsIDOMSVGAnimatedString in1; */
NS_IMETHODIMP nsDOMSVGFETileElement::GetIn1(nsIDOMSVGAnimatedString * *aIn1)
{
    return NS_ERROR_NOT_IMPLEMENTED;
}

/* End of implementation class template. */
#endif


/* starting interface:    nsIDOMSVGFETurbulenceElement */
#define NS_IDOMSVGFETURBULENCEELEMENT_IID_STR "77bc4d70-0d49-4c81-b7a7-7432f0fe3e04"

#define NS_IDOMSVGFETURBULENCEELEMENT_IID \
  {0x77bc4d70, 0x0d49, 0x4c81, \
    { 0xb7, 0xa7, 0x74, 0x32, 0xf0, 0xfe, 0x3e, 0x04 }}

class NS_NO_VTABLE NS_SCRIPTABLE nsIDOMSVGFETurbulenceElement : public nsIDOMSVGFilterPrimitiveStandardAttributes {
 public: 

  NS_DECLARE_STATIC_IID_ACCESSOR(NS_IDOMSVGFETURBULENCEELEMENT_IID)

  enum { SVG_TURBULENCE_TYPE_UNKNOWN = 0U };

  enum { SVG_TURBULENCE_TYPE_FRACTALNOISE = 1U };

  enum { SVG_TURBULENCE_TYPE_TURBULENCE = 2U };

  enum { SVG_STITCHTYPE_UNKNOWN = 0U };

  enum { SVG_STITCHTYPE_STITCH = 1U };

  enum { SVG_STITCHTYPE_NOSTITCH = 2U };

  /* readonly attribute nsIDOMSVGAnimatedNumber baseFrequencyX; */
  NS_SCRIPTABLE NS_IMETHOD GetBaseFrequencyX(nsIDOMSVGAnimatedNumber * *aBaseFrequencyX) = 0;

  /* readonly attribute nsIDOMSVGAnimatedNumber baseFrequencyY; */
  NS_SCRIPTABLE NS_IMETHOD GetBaseFrequencyY(nsIDOMSVGAnimatedNumber * *aBaseFrequencyY) = 0;

  /* readonly attribute nsIDOMSVGAnimatedInteger numOctaves; */
  NS_SCRIPTABLE NS_IMETHOD GetNumOctaves(nsIDOMSVGAnimatedInteger * *aNumOctaves) = 0;

  /* readonly attribute nsIDOMSVGAnimatedNumber seed; */
  NS_SCRIPTABLE NS_IMETHOD GetSeed(nsIDOMSVGAnimatedNumber * *aSeed) = 0;

  /* readonly attribute nsIDOMSVGAnimatedEnumeration stitchTiles; */
  NS_SCRIPTABLE NS_IMETHOD GetStitchTiles(nsIDOMSVGAnimatedEnumeration * *aStitchTiles) = 0;

  /* readonly attribute nsIDOMSVGAnimatedEnumeration type; */
  NS_SCRIPTABLE NS_IMETHOD GetType(nsIDOMSVGAnimatedEnumeration * *aType) = 0;

};

  NS_DEFINE_STATIC_IID_ACCESSOR(nsIDOMSVGFETurbulenceElement, NS_IDOMSVGFETURBULENCEELEMENT_IID)

/* Use this macro when declaring classes that implement this interface. */
#define NS_DECL_NSIDOMSVGFETURBULENCEELEMENT \
  NS_SCRIPTABLE NS_IMETHOD GetBaseFrequencyX(nsIDOMSVGAnimatedNumber * *aBaseFrequencyX); \
  NS_SCRIPTABLE NS_IMETHOD GetBaseFrequencyY(nsIDOMSVGAnimatedNumber * *aBaseFrequencyY); \
  NS_SCRIPTABLE NS_IMETHOD GetNumOctaves(nsIDOMSVGAnimatedInteger * *aNumOctaves); \
  NS_SCRIPTABLE NS_IMETHOD GetSeed(nsIDOMSVGAnimatedNumber * *aSeed); \
  NS_SCRIPTABLE NS_IMETHOD GetStitchTiles(nsIDOMSVGAnimatedEnumeration * *aStitchTiles); \
  NS_SCRIPTABLE NS_IMETHOD GetType(nsIDOMSVGAnimatedEnumeration * *aType); 

/* Use this macro to declare functions that forward the behavior of this interface to another object. */
#define NS_FORWARD_NSIDOMSVGFETURBULENCEELEMENT(_to) \
  NS_SCRIPTABLE NS_IMETHOD GetBaseFrequencyX(nsIDOMSVGAnimatedNumber * *aBaseFrequencyX) { return _to GetBaseFrequencyX(aBaseFrequencyX); } \
  NS_SCRIPTABLE NS_IMETHOD GetBaseFrequencyY(nsIDOMSVGAnimatedNumber * *aBaseFrequencyY) { return _to GetBaseFrequencyY(aBaseFrequencyY); } \
  NS_SCRIPTABLE NS_IMETHOD GetNumOctaves(nsIDOMSVGAnimatedInteger * *aNumOctaves) { return _to GetNumOctaves(aNumOctaves); } \
  NS_SCRIPTABLE NS_IMETHOD GetSeed(nsIDOMSVGAnimatedNumber * *aSeed) { return _to GetSeed(aSeed); } \
  NS_SCRIPTABLE NS_IMETHOD GetStitchTiles(nsIDOMSVGAnimatedEnumeration * *aStitchTiles) { return _to GetStitchTiles(aStitchTiles); } \
  NS_SCRIPTABLE NS_IMETHOD GetType(nsIDOMSVGAnimatedEnumeration * *aType) { return _to GetType(aType); } 

/* Use this macro to declare functions that forward the behavior of this interface to another object in a safe way. */
#define NS_FORWARD_SAFE_NSIDOMSVGFETURBULENCEELEMENT(_to) \
  NS_SCRIPTABLE NS_IMETHOD GetBaseFrequencyX(nsIDOMSVGAnimatedNumber * *aBaseFrequencyX) { return !_to ? NS_ERROR_NULL_POINTER : _to->GetBaseFrequencyX(aBaseFrequencyX); } \
  NS_SCRIPTABLE NS_IMETHOD GetBaseFrequencyY(nsIDOMSVGAnimatedNumber * *aBaseFrequencyY) { return !_to ? NS_ERROR_NULL_POINTER : _to->GetBaseFrequencyY(aBaseFrequencyY); } \
  NS_SCRIPTABLE NS_IMETHOD GetNumOctaves(nsIDOMSVGAnimatedInteger * *aNumOctaves) { return !_to ? NS_ERROR_NULL_POINTER : _to->GetNumOctaves(aNumOctaves); } \
  NS_SCRIPTABLE NS_IMETHOD GetSeed(nsIDOMSVGAnimatedNumber * *aSeed) { return !_to ? NS_ERROR_NULL_POINTER : _to->GetSeed(aSeed); } \
  NS_SCRIPTABLE NS_IMETHOD GetStitchTiles(nsIDOMSVGAnimatedEnumeration * *aStitchTiles) { return !_to ? NS_ERROR_NULL_POINTER : _to->GetStitchTiles(aStitchTiles); } \
  NS_SCRIPTABLE NS_IMETHOD GetType(nsIDOMSVGAnimatedEnumeration * *aType) { return !_to ? NS_ERROR_NULL_POINTER : _to->GetType(aType); } 

#if 0
/* Use the code below as a template for the implementation class for this interface. */

/* Header file */
class nsDOMSVGFETurbulenceElement : public nsIDOMSVGFETurbulenceElement
{
public:
  NS_DECL_ISUPPORTS
  NS_DECL_NSIDOMSVGFETURBULENCEELEMENT

  nsDOMSVGFETurbulenceElement();

private:
  ~nsDOMSVGFETurbulenceElement();

protected:
  /* additional members */
};

/* Implementation file */
NS_IMPL_ISUPPORTS1(nsDOMSVGFETurbulenceElement, nsIDOMSVGFETurbulenceElement)

nsDOMSVGFETurbulenceElement::nsDOMSVGFETurbulenceElement()
{
  /* member initializers and constructor code */
}

nsDOMSVGFETurbulenceElement::~nsDOMSVGFETurbulenceElement()
{
  /* destructor code */
}

/* readonly attribute nsIDOMSVGAnimatedNumber baseFrequencyX; */
NS_IMETHODIMP nsDOMSVGFETurbulenceElement::GetBaseFrequencyX(nsIDOMSVGAnimatedNumber * *aBaseFrequencyX)
{
    return NS_ERROR_NOT_IMPLEMENTED;
}

/* readonly attribute nsIDOMSVGAnimatedNumber baseFrequencyY; */
NS_IMETHODIMP nsDOMSVGFETurbulenceElement::GetBaseFrequencyY(nsIDOMSVGAnimatedNumber * *aBaseFrequencyY)
{
    return NS_ERROR_NOT_IMPLEMENTED;
}

/* readonly attribute nsIDOMSVGAnimatedInteger numOctaves; */
NS_IMETHODIMP nsDOMSVGFETurbulenceElement::GetNumOctaves(nsIDOMSVGAnimatedInteger * *aNumOctaves)
{
    return NS_ERROR_NOT_IMPLEMENTED;
}

/* readonly attribute nsIDOMSVGAnimatedNumber seed; */
NS_IMETHODIMP nsDOMSVGFETurbulenceElement::GetSeed(nsIDOMSVGAnimatedNumber * *aSeed)
{
    return NS_ERROR_NOT_IMPLEMENTED;
}

/* readonly attribute nsIDOMSVGAnimatedEnumeration stitchTiles; */
NS_IMETHODIMP nsDOMSVGFETurbulenceElement::GetStitchTiles(nsIDOMSVGAnimatedEnumeration * *aStitchTiles)
{
    return NS_ERROR_NOT_IMPLEMENTED;
}

/* readonly attribute nsIDOMSVGAnimatedEnumeration type; */
NS_IMETHODIMP nsDOMSVGFETurbulenceElement::GetType(nsIDOMSVGAnimatedEnumeration * *aType)
{
    return NS_ERROR_NOT_IMPLEMENTED;
}

/* End of implementation class template. */
#endif


/* starting interface:    nsIDOMSVGFEMorphologyElement */
#define NS_IDOMSVGFEMORPHOLOGYELEMENT_IID_STR "16154319-fb5f-4473-b360-5065b6096d33"

#define NS_IDOMSVGFEMORPHOLOGYELEMENT_IID \
  {0x16154319, 0xfb5f, 0x4473, \
    { 0xb3, 0x60, 0x50, 0x65, 0xb6, 0x09, 0x6d, 0x33 }}

class NS_NO_VTABLE NS_SCRIPTABLE nsIDOMSVGFEMorphologyElement : public nsIDOMSVGFilterPrimitiveStandardAttributes {
 public: 

  NS_DECLARE_STATIC_IID_ACCESSOR(NS_IDOMSVGFEMORPHOLOGYELEMENT_IID)

  enum { SVG_OPERATOR_UNKNOWN = 0U };

  enum { SVG_OPERATOR_ERODE = 1U };

  enum { SVG_OPERATOR_DILATE = 2U };

  /* readonly attribute nsIDOMSVGAnimatedString in1; */
  NS_SCRIPTABLE NS_IMETHOD GetIn1(nsIDOMSVGAnimatedString * *aIn1) = 0;

  /* readonly attribute nsIDOMSVGAnimatedNumber radiusX; */
  NS_SCRIPTABLE NS_IMETHOD GetRadiusX(nsIDOMSVGAnimatedNumber * *aRadiusX) = 0;

  /* readonly attribute nsIDOMSVGAnimatedNumber radiusY; */
  NS_SCRIPTABLE NS_IMETHOD GetRadiusY(nsIDOMSVGAnimatedNumber * *aRadiusY) = 0;

  /* readonly attribute nsIDOMSVGAnimatedEnumeration operator; */
  NS_SCRIPTABLE NS_IMETHOD GetOperator(nsIDOMSVGAnimatedEnumeration * *aOperator) = 0;

  /* void setRadius (in float rx, in float ry); */
  NS_SCRIPTABLE NS_IMETHOD SetRadius(float rx, float ry) = 0;

};

  NS_DEFINE_STATIC_IID_ACCESSOR(nsIDOMSVGFEMorphologyElement, NS_IDOMSVGFEMORPHOLOGYELEMENT_IID)

/* Use this macro when declaring classes that implement this interface. */
#define NS_DECL_NSIDOMSVGFEMORPHOLOGYELEMENT \
  NS_SCRIPTABLE NS_IMETHOD GetIn1(nsIDOMSVGAnimatedString * *aIn1); \
  NS_SCRIPTABLE NS_IMETHOD GetRadiusX(nsIDOMSVGAnimatedNumber * *aRadiusX); \
  NS_SCRIPTABLE NS_IMETHOD GetRadiusY(nsIDOMSVGAnimatedNumber * *aRadiusY); \
  NS_SCRIPTABLE NS_IMETHOD GetOperator(nsIDOMSVGAnimatedEnumeration * *aOperator); \
  NS_SCRIPTABLE NS_IMETHOD SetRadius(float rx, float ry); 

/* Use this macro to declare functions that forward the behavior of this interface to another object. */
#define NS_FORWARD_NSIDOMSVGFEMORPHOLOGYELEMENT(_to) \
  NS_SCRIPTABLE NS_IMETHOD GetIn1(nsIDOMSVGAnimatedString * *aIn1) { return _to GetIn1(aIn1); } \
  NS_SCRIPTABLE NS_IMETHOD GetRadiusX(nsIDOMSVGAnimatedNumber * *aRadiusX) { return _to GetRadiusX(aRadiusX); } \
  NS_SCRIPTABLE NS_IMETHOD GetRadiusY(nsIDOMSVGAnimatedNumber * *aRadiusY) { return _to GetRadiusY(aRadiusY); } \
  NS_SCRIPTABLE NS_IMETHOD GetOperator(nsIDOMSVGAnimatedEnumeration * *aOperator) { return _to GetOperator(aOperator); } \
  NS_SCRIPTABLE NS_IMETHOD SetRadius(float rx, float ry) { return _to SetRadius(rx, ry); } 

/* Use this macro to declare functions that forward the behavior of this interface to another object in a safe way. */
#define NS_FORWARD_SAFE_NSIDOMSVGFEMORPHOLOGYELEMENT(_to) \
  NS_SCRIPTABLE NS_IMETHOD GetIn1(nsIDOMSVGAnimatedString * *aIn1) { return !_to ? NS_ERROR_NULL_POINTER : _to->GetIn1(aIn1); } \
  NS_SCRIPTABLE NS_IMETHOD GetRadiusX(nsIDOMSVGAnimatedNumber * *aRadiusX) { return !_to ? NS_ERROR_NULL_POINTER : _to->GetRadiusX(aRadiusX); } \
  NS_SCRIPTABLE NS_IMETHOD GetRadiusY(nsIDOMSVGAnimatedNumber * *aRadiusY) { return !_to ? NS_ERROR_NULL_POINTER : _to->GetRadiusY(aRadiusY); } \
  NS_SCRIPTABLE NS_IMETHOD GetOperator(nsIDOMSVGAnimatedEnumeration * *aOperator) { return !_to ? NS_ERROR_NULL_POINTER : _to->GetOperator(aOperator); } \
  NS_SCRIPTABLE NS_IMETHOD SetRadius(float rx, float ry) { return !_to ? NS_ERROR_NULL_POINTER : _to->SetRadius(rx, ry); } 

#if 0
/* Use the code below as a template for the implementation class for this interface. */

/* Header file */
class nsDOMSVGFEMorphologyElement : public nsIDOMSVGFEMorphologyElement
{
public:
  NS_DECL_ISUPPORTS
  NS_DECL_NSIDOMSVGFEMORPHOLOGYELEMENT

  nsDOMSVGFEMorphologyElement();

private:
  ~nsDOMSVGFEMorphologyElement();

protected:
  /* additional members */
};

/* Implementation file */
NS_IMPL_ISUPPORTS1(nsDOMSVGFEMorphologyElement, nsIDOMSVGFEMorphologyElement)

nsDOMSVGFEMorphologyElement::nsDOMSVGFEMorphologyElement()
{
  /* member initializers and constructor code */
}

nsDOMSVGFEMorphologyElement::~nsDOMSVGFEMorphologyElement()
{
  /* destructor code */
}

/* readonly attribute nsIDOMSVGAnimatedString in1; */
NS_IMETHODIMP nsDOMSVGFEMorphologyElement::GetIn1(nsIDOMSVGAnimatedString * *aIn1)
{
    return NS_ERROR_NOT_IMPLEMENTED;
}

/* readonly attribute nsIDOMSVGAnimatedNumber radiusX; */
NS_IMETHODIMP nsDOMSVGFEMorphologyElement::GetRadiusX(nsIDOMSVGAnimatedNumber * *aRadiusX)
{
    return NS_ERROR_NOT_IMPLEMENTED;
}

/* readonly attribute nsIDOMSVGAnimatedNumber radiusY; */
NS_IMETHODIMP nsDOMSVGFEMorphologyElement::GetRadiusY(nsIDOMSVGAnimatedNumber * *aRadiusY)
{
    return NS_ERROR_NOT_IMPLEMENTED;
}

/* readonly attribute nsIDOMSVGAnimatedEnumeration operator; */
NS_IMETHODIMP nsDOMSVGFEMorphologyElement::GetOperator(nsIDOMSVGAnimatedEnumeration * *aOperator)
{
    return NS_ERROR_NOT_IMPLEMENTED;
}

/* void setRadius (in float rx, in float ry); */
NS_IMETHODIMP nsDOMSVGFEMorphologyElement::SetRadius(float rx, float ry)
{
    return NS_ERROR_NOT_IMPLEMENTED;
}

/* End of implementation class template. */
#endif


/* starting interface:    nsIDOMSVGFEConvolveMatrixElement */
#define NS_IDOMSVGFECONVOLVEMATRIXELEMENT_IID_STR "42109b58-a8c1-4078-b44c-ec1d5d6b9574"

#define NS_IDOMSVGFECONVOLVEMATRIXELEMENT_IID \
  {0x42109b58, 0xa8c1, 0x4078, \
    { 0xb4, 0x4c, 0xec, 0x1d, 0x5d, 0x6b, 0x95, 0x74 }}

class NS_NO_VTABLE NS_SCRIPTABLE nsIDOMSVGFEConvolveMatrixElement : public nsIDOMSVGFilterPrimitiveStandardAttributes {
 public: 

  NS_DECLARE_STATIC_IID_ACCESSOR(NS_IDOMSVGFECONVOLVEMATRIXELEMENT_IID)

  enum { SVG_EDGEMODE_UNKNOWN = 0U };

  enum { SVG_EDGEMODE_DUPLICATE = 1U };

  enum { SVG_EDGEMODE_WRAP = 2U };

  enum { SVG_EDGEMODE_NONE = 3U };

  /* readonly attribute nsIDOMSVGAnimatedString in1; */
  NS_SCRIPTABLE NS_IMETHOD GetIn1(nsIDOMSVGAnimatedString * *aIn1) = 0;

  /* readonly attribute nsIDOMSVGAnimatedInteger orderX; */
  NS_SCRIPTABLE NS_IMETHOD GetOrderX(nsIDOMSVGAnimatedInteger * *aOrderX) = 0;

  /* readonly attribute nsIDOMSVGAnimatedInteger orderY; */
  NS_SCRIPTABLE NS_IMETHOD GetOrderY(nsIDOMSVGAnimatedInteger * *aOrderY) = 0;

  /* readonly attribute nsIDOMSVGAnimatedNumberList kernelMatrix; */
  NS_SCRIPTABLE NS_IMETHOD GetKernelMatrix(nsIDOMSVGAnimatedNumberList * *aKernelMatrix) = 0;

  /* readonly attribute nsIDOMSVGAnimatedNumber divisor; */
  NS_SCRIPTABLE NS_IMETHOD GetDivisor(nsIDOMSVGAnimatedNumber * *aDivisor) = 0;

  /* readonly attribute nsIDOMSVGAnimatedNumber bias; */
  NS_SCRIPTABLE NS_IMETHOD GetBias(nsIDOMSVGAnimatedNumber * *aBias) = 0;

  /* readonly attribute nsIDOMSVGAnimatedInteger targetX; */
  NS_SCRIPTABLE NS_IMETHOD GetTargetX(nsIDOMSVGAnimatedInteger * *aTargetX) = 0;

  /* readonly attribute nsIDOMSVGAnimatedInteger targetY; */
  NS_SCRIPTABLE NS_IMETHOD GetTargetY(nsIDOMSVGAnimatedInteger * *aTargetY) = 0;

  /* readonly attribute nsIDOMSVGAnimatedEnumeration edgeMode; */
  NS_SCRIPTABLE NS_IMETHOD GetEdgeMode(nsIDOMSVGAnimatedEnumeration * *aEdgeMode) = 0;

  /* readonly attribute nsIDOMSVGAnimatedNumber kernelUnitLengthX; */
  NS_SCRIPTABLE NS_IMETHOD GetKernelUnitLengthX(nsIDOMSVGAnimatedNumber * *aKernelUnitLengthX) = 0;

  /* readonly attribute nsIDOMSVGAnimatedNumber kernelUnitLengthY; */
  NS_SCRIPTABLE NS_IMETHOD GetKernelUnitLengthY(nsIDOMSVGAnimatedNumber * *aKernelUnitLengthY) = 0;

  /* readonly attribute nsIDOMSVGAnimatedBoolean preserveAlpha; */
  NS_SCRIPTABLE NS_IMETHOD GetPreserveAlpha(nsIDOMSVGAnimatedBoolean * *aPreserveAlpha) = 0;

};

  NS_DEFINE_STATIC_IID_ACCESSOR(nsIDOMSVGFEConvolveMatrixElement, NS_IDOMSVGFECONVOLVEMATRIXELEMENT_IID)

/* Use this macro when declaring classes that implement this interface. */
#define NS_DECL_NSIDOMSVGFECONVOLVEMATRIXELEMENT \
  NS_SCRIPTABLE NS_IMETHOD GetIn1(nsIDOMSVGAnimatedString * *aIn1); \
  NS_SCRIPTABLE NS_IMETHOD GetOrderX(nsIDOMSVGAnimatedInteger * *aOrderX); \
  NS_SCRIPTABLE NS_IMETHOD GetOrderY(nsIDOMSVGAnimatedInteger * *aOrderY); \
  NS_SCRIPTABLE NS_IMETHOD GetKernelMatrix(nsIDOMSVGAnimatedNumberList * *aKernelMatrix); \
  NS_SCRIPTABLE NS_IMETHOD GetDivisor(nsIDOMSVGAnimatedNumber * *aDivisor); \
  NS_SCRIPTABLE NS_IMETHOD GetBias(nsIDOMSVGAnimatedNumber * *aBias); \
  NS_SCRIPTABLE NS_IMETHOD GetTargetX(nsIDOMSVGAnimatedInteger * *aTargetX); \
  NS_SCRIPTABLE NS_IMETHOD GetTargetY(nsIDOMSVGAnimatedInteger * *aTargetY); \
  NS_SCRIPTABLE NS_IMETHOD GetEdgeMode(nsIDOMSVGAnimatedEnumeration * *aEdgeMode); \
  NS_SCRIPTABLE NS_IMETHOD GetKernelUnitLengthX(nsIDOMSVGAnimatedNumber * *aKernelUnitLengthX); \
  NS_SCRIPTABLE NS_IMETHOD GetKernelUnitLengthY(nsIDOMSVGAnimatedNumber * *aKernelUnitLengthY); \
  NS_SCRIPTABLE NS_IMETHOD GetPreserveAlpha(nsIDOMSVGAnimatedBoolean * *aPreserveAlpha); 

/* Use this macro to declare functions that forward the behavior of this interface to another object. */
#define NS_FORWARD_NSIDOMSVGFECONVOLVEMATRIXELEMENT(_to) \
  NS_SCRIPTABLE NS_IMETHOD GetIn1(nsIDOMSVGAnimatedString * *aIn1) { return _to GetIn1(aIn1); } \
  NS_SCRIPTABLE NS_IMETHOD GetOrderX(nsIDOMSVGAnimatedInteger * *aOrderX) { return _to GetOrderX(aOrderX); } \
  NS_SCRIPTABLE NS_IMETHOD GetOrderY(nsIDOMSVGAnimatedInteger * *aOrderY) { return _to GetOrderY(aOrderY); } \
  NS_SCRIPTABLE NS_IMETHOD GetKernelMatrix(nsIDOMSVGAnimatedNumberList * *aKernelMatrix) { return _to GetKernelMatrix(aKernelMatrix); } \
  NS_SCRIPTABLE NS_IMETHOD GetDivisor(nsIDOMSVGAnimatedNumber * *aDivisor) { return _to GetDivisor(aDivisor); } \
  NS_SCRIPTABLE NS_IMETHOD GetBias(nsIDOMSVGAnimatedNumber * *aBias) { return _to GetBias(aBias); } \
  NS_SCRIPTABLE NS_IMETHOD GetTargetX(nsIDOMSVGAnimatedInteger * *aTargetX) { return _to GetTargetX(aTargetX); } \
  NS_SCRIPTABLE NS_IMETHOD GetTargetY(nsIDOMSVGAnimatedInteger * *aTargetY) { return _to GetTargetY(aTargetY); } \
  NS_SCRIPTABLE NS_IMETHOD GetEdgeMode(nsIDOMSVGAnimatedEnumeration * *aEdgeMode) { return _to GetEdgeMode(aEdgeMode); } \
  NS_SCRIPTABLE NS_IMETHOD GetKernelUnitLengthX(nsIDOMSVGAnimatedNumber * *aKernelUnitLengthX) { return _to GetKernelUnitLengthX(aKernelUnitLengthX); } \
  NS_SCRIPTABLE NS_IMETHOD GetKernelUnitLengthY(nsIDOMSVGAnimatedNumber * *aKernelUnitLengthY) { return _to GetKernelUnitLengthY(aKernelUnitLengthY); } \
  NS_SCRIPTABLE NS_IMETHOD GetPreserveAlpha(nsIDOMSVGAnimatedBoolean * *aPreserveAlpha) { return _to GetPreserveAlpha(aPreserveAlpha); } 

/* Use this macro to declare functions that forward the behavior of this interface to another object in a safe way. */
#define NS_FORWARD_SAFE_NSIDOMSVGFECONVOLVEMATRIXELEMENT(_to) \
  NS_SCRIPTABLE NS_IMETHOD GetIn1(nsIDOMSVGAnimatedString * *aIn1) { return !_to ? NS_ERROR_NULL_POINTER : _to->GetIn1(aIn1); } \
  NS_SCRIPTABLE NS_IMETHOD GetOrderX(nsIDOMSVGAnimatedInteger * *aOrderX) { return !_to ? NS_ERROR_NULL_POINTER : _to->GetOrderX(aOrderX); } \
  NS_SCRIPTABLE NS_IMETHOD GetOrderY(nsIDOMSVGAnimatedInteger * *aOrderY) { return !_to ? NS_ERROR_NULL_POINTER : _to->GetOrderY(aOrderY); } \
  NS_SCRIPTABLE NS_IMETHOD GetKernelMatrix(nsIDOMSVGAnimatedNumberList * *aKernelMatrix) { return !_to ? NS_ERROR_NULL_POINTER : _to->GetKernelMatrix(aKernelMatrix); } \
  NS_SCRIPTABLE NS_IMETHOD GetDivisor(nsIDOMSVGAnimatedNumber * *aDivisor) { return !_to ? NS_ERROR_NULL_POINTER : _to->GetDivisor(aDivisor); } \
  NS_SCRIPTABLE NS_IMETHOD GetBias(nsIDOMSVGAnimatedNumber * *aBias) { return !_to ? NS_ERROR_NULL_POINTER : _to->GetBias(aBias); } \
  NS_SCRIPTABLE NS_IMETHOD GetTargetX(nsIDOMSVGAnimatedInteger * *aTargetX) { return !_to ? NS_ERROR_NULL_POINTER : _to->GetTargetX(aTargetX); } \
  NS_SCRIPTABLE NS_IMETHOD GetTargetY(nsIDOMSVGAnimatedInteger * *aTargetY) { return !_to ? NS_ERROR_NULL_POINTER : _to->GetTargetY(aTargetY); } \
  NS_SCRIPTABLE NS_IMETHOD GetEdgeMode(nsIDOMSVGAnimatedEnumeration * *aEdgeMode) { return !_to ? NS_ERROR_NULL_POINTER : _to->GetEdgeMode(aEdgeMode); } \
  NS_SCRIPTABLE NS_IMETHOD GetKernelUnitLengthX(nsIDOMSVGAnimatedNumber * *aKernelUnitLengthX) { return !_to ? NS_ERROR_NULL_POINTER : _to->GetKernelUnitLengthX(aKernelUnitLengthX); } \
  NS_SCRIPTABLE NS_IMETHOD GetKernelUnitLengthY(nsIDOMSVGAnimatedNumber * *aKernelUnitLengthY) { return !_to ? NS_ERROR_NULL_POINTER : _to->GetKernelUnitLengthY(aKernelUnitLengthY); } \
  NS_SCRIPTABLE NS_IMETHOD GetPreserveAlpha(nsIDOMSVGAnimatedBoolean * *aPreserveAlpha) { return !_to ? NS_ERROR_NULL_POINTER : _to->GetPreserveAlpha(aPreserveAlpha); } 

#if 0
/* Use the code below as a template for the implementation class for this interface. */

/* Header file */
class nsDOMSVGFEConvolveMatrixElement : public nsIDOMSVGFEConvolveMatrixElement
{
public:
  NS_DECL_ISUPPORTS
  NS_DECL_NSIDOMSVGFECONVOLVEMATRIXELEMENT

  nsDOMSVGFEConvolveMatrixElement();

private:
  ~nsDOMSVGFEConvolveMatrixElement();

protected:
  /* additional members */
};

/* Implementation file */
NS_IMPL_ISUPPORTS1(nsDOMSVGFEConvolveMatrixElement, nsIDOMSVGFEConvolveMatrixElement)

nsDOMSVGFEConvolveMatrixElement::nsDOMSVGFEConvolveMatrixElement()
{
  /* member initializers and constructor code */
}

nsDOMSVGFEConvolveMatrixElement::~nsDOMSVGFEConvolveMatrixElement()
{
  /* destructor code */
}

/* readonly attribute nsIDOMSVGAnimatedString in1; */
NS_IMETHODIMP nsDOMSVGFEConvolveMatrixElement::GetIn1(nsIDOMSVGAnimatedString * *aIn1)
{
    return NS_ERROR_NOT_IMPLEMENTED;
}

/* readonly attribute nsIDOMSVGAnimatedInteger orderX; */
NS_IMETHODIMP nsDOMSVGFEConvolveMatrixElement::GetOrderX(nsIDOMSVGAnimatedInteger * *aOrderX)
{
    return NS_ERROR_NOT_IMPLEMENTED;
}

/* readonly attribute nsIDOMSVGAnimatedInteger orderY; */
NS_IMETHODIMP nsDOMSVGFEConvolveMatrixElement::GetOrderY(nsIDOMSVGAnimatedInteger * *aOrderY)
{
    return NS_ERROR_NOT_IMPLEMENTED;
}

/* readonly attribute nsIDOMSVGAnimatedNumberList kernelMatrix; */
NS_IMETHODIMP nsDOMSVGFEConvolveMatrixElement::GetKernelMatrix(nsIDOMSVGAnimatedNumberList * *aKernelMatrix)
{
    return NS_ERROR_NOT_IMPLEMENTED;
}

/* readonly attribute nsIDOMSVGAnimatedNumber divisor; */
NS_IMETHODIMP nsDOMSVGFEConvolveMatrixElement::GetDivisor(nsIDOMSVGAnimatedNumber * *aDivisor)
{
    return NS_ERROR_NOT_IMPLEMENTED;
}

/* readonly attribute nsIDOMSVGAnimatedNumber bias; */
NS_IMETHODIMP nsDOMSVGFEConvolveMatrixElement::GetBias(nsIDOMSVGAnimatedNumber * *aBias)
{
    return NS_ERROR_NOT_IMPLEMENTED;
}

/* readonly attribute nsIDOMSVGAnimatedInteger targetX; */
NS_IMETHODIMP nsDOMSVGFEConvolveMatrixElement::GetTargetX(nsIDOMSVGAnimatedInteger * *aTargetX)
{
    return NS_ERROR_NOT_IMPLEMENTED;
}

/* readonly attribute nsIDOMSVGAnimatedInteger targetY; */
NS_IMETHODIMP nsDOMSVGFEConvolveMatrixElement::GetTargetY(nsIDOMSVGAnimatedInteger * *aTargetY)
{
    return NS_ERROR_NOT_IMPLEMENTED;
}

/* readonly attribute nsIDOMSVGAnimatedEnumeration edgeMode; */
NS_IMETHODIMP nsDOMSVGFEConvolveMatrixElement::GetEdgeMode(nsIDOMSVGAnimatedEnumeration * *aEdgeMode)
{
    return NS_ERROR_NOT_IMPLEMENTED;
}

/* readonly attribute nsIDOMSVGAnimatedNumber kernelUnitLengthX; */
NS_IMETHODIMP nsDOMSVGFEConvolveMatrixElement::GetKernelUnitLengthX(nsIDOMSVGAnimatedNumber * *aKernelUnitLengthX)
{
    return NS_ERROR_NOT_IMPLEMENTED;
}

/* readonly attribute nsIDOMSVGAnimatedNumber kernelUnitLengthY; */
NS_IMETHODIMP nsDOMSVGFEConvolveMatrixElement::GetKernelUnitLengthY(nsIDOMSVGAnimatedNumber * *aKernelUnitLengthY)
{
    return NS_ERROR_NOT_IMPLEMENTED;
}

/* readonly attribute nsIDOMSVGAnimatedBoolean preserveAlpha; */
NS_IMETHODIMP nsDOMSVGFEConvolveMatrixElement::GetPreserveAlpha(nsIDOMSVGAnimatedBoolean * *aPreserveAlpha)
{
    return NS_ERROR_NOT_IMPLEMENTED;
}

/* End of implementation class template. */
#endif


/* starting interface:    nsIDOMSVGFEDiffuseLightingElement */
#define NS_IDOMSVGFEDIFFUSELIGHTINGELEMENT_IID_STR "2e9eb422-2398-4be9-a9b8-b1cc7aa9dd6f"

#define NS_IDOMSVGFEDIFFUSELIGHTINGELEMENT_IID \
  {0x2e9eb422, 0x2398, 0x4be9, \
    { 0xa9, 0xb8, 0xb1, 0xcc, 0x7a, 0xa9, 0xdd, 0x6f }}

class NS_NO_VTABLE NS_SCRIPTABLE nsIDOMSVGFEDiffuseLightingElement : public nsIDOMSVGFilterPrimitiveStandardAttributes {
 public: 

  NS_DECLARE_STATIC_IID_ACCESSOR(NS_IDOMSVGFEDIFFUSELIGHTINGELEMENT_IID)

  /* readonly attribute nsIDOMSVGAnimatedString in1; */
  NS_SCRIPTABLE NS_IMETHOD GetIn1(nsIDOMSVGAnimatedString * *aIn1) = 0;

  /* readonly attribute nsIDOMSVGAnimatedNumber surfaceScale; */
  NS_SCRIPTABLE NS_IMETHOD GetSurfaceScale(nsIDOMSVGAnimatedNumber * *aSurfaceScale) = 0;

  /* readonly attribute nsIDOMSVGAnimatedNumber diffuseConstant; */
  NS_SCRIPTABLE NS_IMETHOD GetDiffuseConstant(nsIDOMSVGAnimatedNumber * *aDiffuseConstant) = 0;

  /* readonly attribute nsIDOMSVGAnimatedNumber kernelUnitLengthX; */
  NS_SCRIPTABLE NS_IMETHOD GetKernelUnitLengthX(nsIDOMSVGAnimatedNumber * *aKernelUnitLengthX) = 0;

  /* readonly attribute nsIDOMSVGAnimatedNumber kernelUnitLengthY; */
  NS_SCRIPTABLE NS_IMETHOD GetKernelUnitLengthY(nsIDOMSVGAnimatedNumber * *aKernelUnitLengthY) = 0;

};

  NS_DEFINE_STATIC_IID_ACCESSOR(nsIDOMSVGFEDiffuseLightingElement, NS_IDOMSVGFEDIFFUSELIGHTINGELEMENT_IID)

/* Use this macro when declaring classes that implement this interface. */
#define NS_DECL_NSIDOMSVGFEDIFFUSELIGHTINGELEMENT \
  NS_SCRIPTABLE NS_IMETHOD GetIn1(nsIDOMSVGAnimatedString * *aIn1); \
  NS_SCRIPTABLE NS_IMETHOD GetSurfaceScale(nsIDOMSVGAnimatedNumber * *aSurfaceScale); \
  NS_SCRIPTABLE NS_IMETHOD GetDiffuseConstant(nsIDOMSVGAnimatedNumber * *aDiffuseConstant); \
  NS_SCRIPTABLE NS_IMETHOD GetKernelUnitLengthX(nsIDOMSVGAnimatedNumber * *aKernelUnitLengthX); \
  NS_SCRIPTABLE NS_IMETHOD GetKernelUnitLengthY(nsIDOMSVGAnimatedNumber * *aKernelUnitLengthY); 

/* Use this macro to declare functions that forward the behavior of this interface to another object. */
#define NS_FORWARD_NSIDOMSVGFEDIFFUSELIGHTINGELEMENT(_to) \
  NS_SCRIPTABLE NS_IMETHOD GetIn1(nsIDOMSVGAnimatedString * *aIn1) { return _to GetIn1(aIn1); } \
  NS_SCRIPTABLE NS_IMETHOD GetSurfaceScale(nsIDOMSVGAnimatedNumber * *aSurfaceScale) { return _to GetSurfaceScale(aSurfaceScale); } \
  NS_SCRIPTABLE NS_IMETHOD GetDiffuseConstant(nsIDOMSVGAnimatedNumber * *aDiffuseConstant) { return _to GetDiffuseConstant(aDiffuseConstant); } \
  NS_SCRIPTABLE NS_IMETHOD GetKernelUnitLengthX(nsIDOMSVGAnimatedNumber * *aKernelUnitLengthX) { return _to GetKernelUnitLengthX(aKernelUnitLengthX); } \
  NS_SCRIPTABLE NS_IMETHOD GetKernelUnitLengthY(nsIDOMSVGAnimatedNumber * *aKernelUnitLengthY) { return _to GetKernelUnitLengthY(aKernelUnitLengthY); } 

/* Use this macro to declare functions that forward the behavior of this interface to another object in a safe way. */
#define NS_FORWARD_SAFE_NSIDOMSVGFEDIFFUSELIGHTINGELEMENT(_to) \
  NS_SCRIPTABLE NS_IMETHOD GetIn1(nsIDOMSVGAnimatedString * *aIn1) { return !_to ? NS_ERROR_NULL_POINTER : _to->GetIn1(aIn1); } \
  NS_SCRIPTABLE NS_IMETHOD GetSurfaceScale(nsIDOMSVGAnimatedNumber * *aSurfaceScale) { return !_to ? NS_ERROR_NULL_POINTER : _to->GetSurfaceScale(aSurfaceScale); } \
  NS_SCRIPTABLE NS_IMETHOD GetDiffuseConstant(nsIDOMSVGAnimatedNumber * *aDiffuseConstant) { return !_to ? NS_ERROR_NULL_POINTER : _to->GetDiffuseConstant(aDiffuseConstant); } \
  NS_SCRIPTABLE NS_IMETHOD GetKernelUnitLengthX(nsIDOMSVGAnimatedNumber * *aKernelUnitLengthX) { return !_to ? NS_ERROR_NULL_POINTER : _to->GetKernelUnitLengthX(aKernelUnitLengthX); } \
  NS_SCRIPTABLE NS_IMETHOD GetKernelUnitLengthY(nsIDOMSVGAnimatedNumber * *aKernelUnitLengthY) { return !_to ? NS_ERROR_NULL_POINTER : _to->GetKernelUnitLengthY(aKernelUnitLengthY); } 

#if 0
/* Use the code below as a template for the implementation class for this interface. */

/* Header file */
class nsDOMSVGFEDiffuseLightingElement : public nsIDOMSVGFEDiffuseLightingElement
{
public:
  NS_DECL_ISUPPORTS
  NS_DECL_NSIDOMSVGFEDIFFUSELIGHTINGELEMENT

  nsDOMSVGFEDiffuseLightingElement();

private:
  ~nsDOMSVGFEDiffuseLightingElement();

protected:
  /* additional members */
};

/* Implementation file */
NS_IMPL_ISUPPORTS1(nsDOMSVGFEDiffuseLightingElement, nsIDOMSVGFEDiffuseLightingElement)

nsDOMSVGFEDiffuseLightingElement::nsDOMSVGFEDiffuseLightingElement()
{
  /* member initializers and constructor code */
}

nsDOMSVGFEDiffuseLightingElement::~nsDOMSVGFEDiffuseLightingElement()
{
  /* destructor code */
}

/* readonly attribute nsIDOMSVGAnimatedString in1; */
NS_IMETHODIMP nsDOMSVGFEDiffuseLightingElement::GetIn1(nsIDOMSVGAnimatedString * *aIn1)
{
    return NS_ERROR_NOT_IMPLEMENTED;
}

/* readonly attribute nsIDOMSVGAnimatedNumber surfaceScale; */
NS_IMETHODIMP nsDOMSVGFEDiffuseLightingElement::GetSurfaceScale(nsIDOMSVGAnimatedNumber * *aSurfaceScale)
{
    return NS_ERROR_NOT_IMPLEMENTED;
}

/* readonly attribute nsIDOMSVGAnimatedNumber diffuseConstant; */
NS_IMETHODIMP nsDOMSVGFEDiffuseLightingElement::GetDiffuseConstant(nsIDOMSVGAnimatedNumber * *aDiffuseConstant)
{
    return NS_ERROR_NOT_IMPLEMENTED;
}

/* readonly attribute nsIDOMSVGAnimatedNumber kernelUnitLengthX; */
NS_IMETHODIMP nsDOMSVGFEDiffuseLightingElement::GetKernelUnitLengthX(nsIDOMSVGAnimatedNumber * *aKernelUnitLengthX)
{
    return NS_ERROR_NOT_IMPLEMENTED;
}

/* readonly attribute nsIDOMSVGAnimatedNumber kernelUnitLengthY; */
NS_IMETHODIMP nsDOMSVGFEDiffuseLightingElement::GetKernelUnitLengthY(nsIDOMSVGAnimatedNumber * *aKernelUnitLengthY)
{
    return NS_ERROR_NOT_IMPLEMENTED;
}

/* End of implementation class template. */
#endif


/* starting interface:    nsIDOMSVGFESpecularLightingElement */
#define NS_IDOMSVGFESPECULARLIGHTINGELEMENT_IID_STR "49c38287-a7c2-4895-a630-86d2b45df23c"

#define NS_IDOMSVGFESPECULARLIGHTINGELEMENT_IID \
  {0x49c38287, 0xa7c2, 0x4895, \
    { 0xa6, 0x30, 0x86, 0xd2, 0xb4, 0x5d, 0xf2, 0x3c }}

class NS_NO_VTABLE NS_SCRIPTABLE nsIDOMSVGFESpecularLightingElement : public nsIDOMSVGFilterPrimitiveStandardAttributes {
 public: 

  NS_DECLARE_STATIC_IID_ACCESSOR(NS_IDOMSVGFESPECULARLIGHTINGELEMENT_IID)

  /* readonly attribute nsIDOMSVGAnimatedString in1; */
  NS_SCRIPTABLE NS_IMETHOD GetIn1(nsIDOMSVGAnimatedString * *aIn1) = 0;

  /* readonly attribute nsIDOMSVGAnimatedNumber surfaceScale; */
  NS_SCRIPTABLE NS_IMETHOD GetSurfaceScale(nsIDOMSVGAnimatedNumber * *aSurfaceScale) = 0;

  /* readonly attribute nsIDOMSVGAnimatedNumber specularConstant; */
  NS_SCRIPTABLE NS_IMETHOD GetSpecularConstant(nsIDOMSVGAnimatedNumber * *aSpecularConstant) = 0;

  /* readonly attribute nsIDOMSVGAnimatedNumber specularExponent; */
  NS_SCRIPTABLE NS_IMETHOD GetSpecularExponent(nsIDOMSVGAnimatedNumber * *aSpecularExponent) = 0;

  /* readonly attribute nsIDOMSVGAnimatedNumber kernelUnitLengthX; */
  NS_SCRIPTABLE NS_IMETHOD GetKernelUnitLengthX(nsIDOMSVGAnimatedNumber * *aKernelUnitLengthX) = 0;

  /* readonly attribute nsIDOMSVGAnimatedNumber kernelUnitLengthY; */
  NS_SCRIPTABLE NS_IMETHOD GetKernelUnitLengthY(nsIDOMSVGAnimatedNumber * *aKernelUnitLengthY) = 0;

};

  NS_DEFINE_STATIC_IID_ACCESSOR(nsIDOMSVGFESpecularLightingElement, NS_IDOMSVGFESPECULARLIGHTINGELEMENT_IID)

/* Use this macro when declaring classes that implement this interface. */
#define NS_DECL_NSIDOMSVGFESPECULARLIGHTINGELEMENT \
  NS_SCRIPTABLE NS_IMETHOD GetIn1(nsIDOMSVGAnimatedString * *aIn1); \
  NS_SCRIPTABLE NS_IMETHOD GetSurfaceScale(nsIDOMSVGAnimatedNumber * *aSurfaceScale); \
  NS_SCRIPTABLE NS_IMETHOD GetSpecularConstant(nsIDOMSVGAnimatedNumber * *aSpecularConstant); \
  NS_SCRIPTABLE NS_IMETHOD GetSpecularExponent(nsIDOMSVGAnimatedNumber * *aSpecularExponent); \
  NS_SCRIPTABLE NS_IMETHOD GetKernelUnitLengthX(nsIDOMSVGAnimatedNumber * *aKernelUnitLengthX); \
  NS_SCRIPTABLE NS_IMETHOD GetKernelUnitLengthY(nsIDOMSVGAnimatedNumber * *aKernelUnitLengthY); 

/* Use this macro to declare functions that forward the behavior of this interface to another object. */
#define NS_FORWARD_NSIDOMSVGFESPECULARLIGHTINGELEMENT(_to) \
  NS_SCRIPTABLE NS_IMETHOD GetIn1(nsIDOMSVGAnimatedString * *aIn1) { return _to GetIn1(aIn1); } \
  NS_SCRIPTABLE NS_IMETHOD GetSurfaceScale(nsIDOMSVGAnimatedNumber * *aSurfaceScale) { return _to GetSurfaceScale(aSurfaceScale); } \
  NS_SCRIPTABLE NS_IMETHOD GetSpecularConstant(nsIDOMSVGAnimatedNumber * *aSpecularConstant) { return _to GetSpecularConstant(aSpecularConstant); } \
  NS_SCRIPTABLE NS_IMETHOD GetSpecularExponent(nsIDOMSVGAnimatedNumber * *aSpecularExponent) { return _to GetSpecularExponent(aSpecularExponent); } \
  NS_SCRIPTABLE NS_IMETHOD GetKernelUnitLengthX(nsIDOMSVGAnimatedNumber * *aKernelUnitLengthX) { return _to GetKernelUnitLengthX(aKernelUnitLengthX); } \
  NS_SCRIPTABLE NS_IMETHOD GetKernelUnitLengthY(nsIDOMSVGAnimatedNumber * *aKernelUnitLengthY) { return _to GetKernelUnitLengthY(aKernelUnitLengthY); } 

/* Use this macro to declare functions that forward the behavior of this interface to another object in a safe way. */
#define NS_FORWARD_SAFE_NSIDOMSVGFESPECULARLIGHTINGELEMENT(_to) \
  NS_SCRIPTABLE NS_IMETHOD GetIn1(nsIDOMSVGAnimatedString * *aIn1) { return !_to ? NS_ERROR_NULL_POINTER : _to->GetIn1(aIn1); } \
  NS_SCRIPTABLE NS_IMETHOD GetSurfaceScale(nsIDOMSVGAnimatedNumber * *aSurfaceScale) { return !_to ? NS_ERROR_NULL_POINTER : _to->GetSurfaceScale(aSurfaceScale); } \
  NS_SCRIPTABLE NS_IMETHOD GetSpecularConstant(nsIDOMSVGAnimatedNumber * *aSpecularConstant) { return !_to ? NS_ERROR_NULL_POINTER : _to->GetSpecularConstant(aSpecularConstant); } \
  NS_SCRIPTABLE NS_IMETHOD GetSpecularExponent(nsIDOMSVGAnimatedNumber * *aSpecularExponent) { return !_to ? NS_ERROR_NULL_POINTER : _to->GetSpecularExponent(aSpecularExponent); } \
  NS_SCRIPTABLE NS_IMETHOD GetKernelUnitLengthX(nsIDOMSVGAnimatedNumber * *aKernelUnitLengthX) { return !_to ? NS_ERROR_NULL_POINTER : _to->GetKernelUnitLengthX(aKernelUnitLengthX); } \
  NS_SCRIPTABLE NS_IMETHOD GetKernelUnitLengthY(nsIDOMSVGAnimatedNumber * *aKernelUnitLengthY) { return !_to ? NS_ERROR_NULL_POINTER : _to->GetKernelUnitLengthY(aKernelUnitLengthY); } 

#if 0
/* Use the code below as a template for the implementation class for this interface. */

/* Header file */
class nsDOMSVGFESpecularLightingElement : public nsIDOMSVGFESpecularLightingElement
{
public:
  NS_DECL_ISUPPORTS
  NS_DECL_NSIDOMSVGFESPECULARLIGHTINGELEMENT

  nsDOMSVGFESpecularLightingElement();

private:
  ~nsDOMSVGFESpecularLightingElement();

protected:
  /* additional members */
};

/* Implementation file */
NS_IMPL_ISUPPORTS1(nsDOMSVGFESpecularLightingElement, nsIDOMSVGFESpecularLightingElement)

nsDOMSVGFESpecularLightingElement::nsDOMSVGFESpecularLightingElement()
{
  /* member initializers and constructor code */
}

nsDOMSVGFESpecularLightingElement::~nsDOMSVGFESpecularLightingElement()
{
  /* destructor code */
}

/* readonly attribute nsIDOMSVGAnimatedString in1; */
NS_IMETHODIMP nsDOMSVGFESpecularLightingElement::GetIn1(nsIDOMSVGAnimatedString * *aIn1)
{
    return NS_ERROR_NOT_IMPLEMENTED;
}

/* readonly attribute nsIDOMSVGAnimatedNumber surfaceScale; */
NS_IMETHODIMP nsDOMSVGFESpecularLightingElement::GetSurfaceScale(nsIDOMSVGAnimatedNumber * *aSurfaceScale)
{
    return NS_ERROR_NOT_IMPLEMENTED;
}

/* readonly attribute nsIDOMSVGAnimatedNumber specularConstant; */
NS_IMETHODIMP nsDOMSVGFESpecularLightingElement::GetSpecularConstant(nsIDOMSVGAnimatedNumber * *aSpecularConstant)
{
    return NS_ERROR_NOT_IMPLEMENTED;
}

/* readonly attribute nsIDOMSVGAnimatedNumber specularExponent; */
NS_IMETHODIMP nsDOMSVGFESpecularLightingElement::GetSpecularExponent(nsIDOMSVGAnimatedNumber * *aSpecularExponent)
{
    return NS_ERROR_NOT_IMPLEMENTED;
}

/* readonly attribute nsIDOMSVGAnimatedNumber kernelUnitLengthX; */
NS_IMETHODIMP nsDOMSVGFESpecularLightingElement::GetKernelUnitLengthX(nsIDOMSVGAnimatedNumber * *aKernelUnitLengthX)
{
    return NS_ERROR_NOT_IMPLEMENTED;
}

/* readonly attribute nsIDOMSVGAnimatedNumber kernelUnitLengthY; */
NS_IMETHODIMP nsDOMSVGFESpecularLightingElement::GetKernelUnitLengthY(nsIDOMSVGAnimatedNumber * *aKernelUnitLengthY)
{
    return NS_ERROR_NOT_IMPLEMENTED;
}

/* End of implementation class template. */
#endif


/* starting interface:    nsIDOMSVGFEDistantLightElement */
#define NS_IDOMSVGFEDISTANTLIGHTELEMENT_IID_STR "02141672-7f2c-412a-a7d7-4caa194842e9"

#define NS_IDOMSVGFEDISTANTLIGHTELEMENT_IID \
  {0x02141672, 0x7f2c, 0x412a, \
    { 0xa7, 0xd7, 0x4c, 0xaa, 0x19, 0x48, 0x42, 0xe9 }}

class NS_NO_VTABLE NS_SCRIPTABLE nsIDOMSVGFEDistantLightElement : public nsIDOMSVGElement {
 public: 

  NS_DECLARE_STATIC_IID_ACCESSOR(NS_IDOMSVGFEDISTANTLIGHTELEMENT_IID)

  /* readonly attribute nsIDOMSVGAnimatedNumber azimuth; */
  NS_SCRIPTABLE NS_IMETHOD GetAzimuth(nsIDOMSVGAnimatedNumber * *aAzimuth) = 0;

  /* readonly attribute nsIDOMSVGAnimatedNumber elevation; */
  NS_SCRIPTABLE NS_IMETHOD GetElevation(nsIDOMSVGAnimatedNumber * *aElevation) = 0;

};

  NS_DEFINE_STATIC_IID_ACCESSOR(nsIDOMSVGFEDistantLightElement, NS_IDOMSVGFEDISTANTLIGHTELEMENT_IID)

/* Use this macro when declaring classes that implement this interface. */
#define NS_DECL_NSIDOMSVGFEDISTANTLIGHTELEMENT \
  NS_SCRIPTABLE NS_IMETHOD GetAzimuth(nsIDOMSVGAnimatedNumber * *aAzimuth); \
  NS_SCRIPTABLE NS_IMETHOD GetElevation(nsIDOMSVGAnimatedNumber * *aElevation); 

/* Use this macro to declare functions that forward the behavior of this interface to another object. */
#define NS_FORWARD_NSIDOMSVGFEDISTANTLIGHTELEMENT(_to) \
  NS_SCRIPTABLE NS_IMETHOD GetAzimuth(nsIDOMSVGAnimatedNumber * *aAzimuth) { return _to GetAzimuth(aAzimuth); } \
  NS_SCRIPTABLE NS_IMETHOD GetElevation(nsIDOMSVGAnimatedNumber * *aElevation) { return _to GetElevation(aElevation); } 

/* Use this macro to declare functions that forward the behavior of this interface to another object in a safe way. */
#define NS_FORWARD_SAFE_NSIDOMSVGFEDISTANTLIGHTELEMENT(_to) \
  NS_SCRIPTABLE NS_IMETHOD GetAzimuth(nsIDOMSVGAnimatedNumber * *aAzimuth) { return !_to ? NS_ERROR_NULL_POINTER : _to->GetAzimuth(aAzimuth); } \
  NS_SCRIPTABLE NS_IMETHOD GetElevation(nsIDOMSVGAnimatedNumber * *aElevation) { return !_to ? NS_ERROR_NULL_POINTER : _to->GetElevation(aElevation); } 

#if 0
/* Use the code below as a template for the implementation class for this interface. */

/* Header file */
class nsDOMSVGFEDistantLightElement : public nsIDOMSVGFEDistantLightElement
{
public:
  NS_DECL_ISUPPORTS
  NS_DECL_NSIDOMSVGFEDISTANTLIGHTELEMENT

  nsDOMSVGFEDistantLightElement();

private:
  ~nsDOMSVGFEDistantLightElement();

protected:
  /* additional members */
};

/* Implementation file */
NS_IMPL_ISUPPORTS1(nsDOMSVGFEDistantLightElement, nsIDOMSVGFEDistantLightElement)

nsDOMSVGFEDistantLightElement::nsDOMSVGFEDistantLightElement()
{
  /* member initializers and constructor code */
}

nsDOMSVGFEDistantLightElement::~nsDOMSVGFEDistantLightElement()
{
  /* destructor code */
}

/* readonly attribute nsIDOMSVGAnimatedNumber azimuth; */
NS_IMETHODIMP nsDOMSVGFEDistantLightElement::GetAzimuth(nsIDOMSVGAnimatedNumber * *aAzimuth)
{
    return NS_ERROR_NOT_IMPLEMENTED;
}

/* readonly attribute nsIDOMSVGAnimatedNumber elevation; */
NS_IMETHODIMP nsDOMSVGFEDistantLightElement::GetElevation(nsIDOMSVGAnimatedNumber * *aElevation)
{
    return NS_ERROR_NOT_IMPLEMENTED;
}

/* End of implementation class template. */
#endif


/* starting interface:    nsIDOMSVGFEPointLightElement */
#define NS_IDOMSVGFEPOINTLIGHTELEMENT_IID_STR "557f128a-026b-4fa8-a44c-605df7bfd62e"

#define NS_IDOMSVGFEPOINTLIGHTELEMENT_IID \
  {0x557f128a, 0x026b, 0x4fa8, \
    { 0xa4, 0x4c, 0x60, 0x5d, 0xf7, 0xbf, 0xd6, 0x2e }}

class NS_NO_VTABLE NS_SCRIPTABLE nsIDOMSVGFEPointLightElement : public nsIDOMSVGElement {
 public: 

  NS_DECLARE_STATIC_IID_ACCESSOR(NS_IDOMSVGFEPOINTLIGHTELEMENT_IID)

  /* readonly attribute nsIDOMSVGAnimatedNumber x; */
  NS_SCRIPTABLE NS_IMETHOD GetX(nsIDOMSVGAnimatedNumber * *aX) = 0;

  /* readonly attribute nsIDOMSVGAnimatedNumber y; */
  NS_SCRIPTABLE NS_IMETHOD GetY(nsIDOMSVGAnimatedNumber * *aY) = 0;

  /* readonly attribute nsIDOMSVGAnimatedNumber z; */
  NS_SCRIPTABLE NS_IMETHOD GetZ(nsIDOMSVGAnimatedNumber * *aZ) = 0;

};

  NS_DEFINE_STATIC_IID_ACCESSOR(nsIDOMSVGFEPointLightElement, NS_IDOMSVGFEPOINTLIGHTELEMENT_IID)

/* Use this macro when declaring classes that implement this interface. */
#define NS_DECL_NSIDOMSVGFEPOINTLIGHTELEMENT \
  NS_SCRIPTABLE NS_IMETHOD GetX(nsIDOMSVGAnimatedNumber * *aX); \
  NS_SCRIPTABLE NS_IMETHOD GetY(nsIDOMSVGAnimatedNumber * *aY); \
  NS_SCRIPTABLE NS_IMETHOD GetZ(nsIDOMSVGAnimatedNumber * *aZ); 

/* Use this macro to declare functions that forward the behavior of this interface to another object. */
#define NS_FORWARD_NSIDOMSVGFEPOINTLIGHTELEMENT(_to) \
  NS_SCRIPTABLE NS_IMETHOD GetX(nsIDOMSVGAnimatedNumber * *aX) { return _to GetX(aX); } \
  NS_SCRIPTABLE NS_IMETHOD GetY(nsIDOMSVGAnimatedNumber * *aY) { return _to GetY(aY); } \
  NS_SCRIPTABLE NS_IMETHOD GetZ(nsIDOMSVGAnimatedNumber * *aZ) { return _to GetZ(aZ); } 

/* Use this macro to declare functions that forward the behavior of this interface to another object in a safe way. */
#define NS_FORWARD_SAFE_NSIDOMSVGFEPOINTLIGHTELEMENT(_to) \
  NS_SCRIPTABLE NS_IMETHOD GetX(nsIDOMSVGAnimatedNumber * *aX) { return !_to ? NS_ERROR_NULL_POINTER : _to->GetX(aX); } \
  NS_SCRIPTABLE NS_IMETHOD GetY(nsIDOMSVGAnimatedNumber * *aY) { return !_to ? NS_ERROR_NULL_POINTER : _to->GetY(aY); } \
  NS_SCRIPTABLE NS_IMETHOD GetZ(nsIDOMSVGAnimatedNumber * *aZ) { return !_to ? NS_ERROR_NULL_POINTER : _to->GetZ(aZ); } 

#if 0
/* Use the code below as a template for the implementation class for this interface. */

/* Header file */
class nsDOMSVGFEPointLightElement : public nsIDOMSVGFEPointLightElement
{
public:
  NS_DECL_ISUPPORTS
  NS_DECL_NSIDOMSVGFEPOINTLIGHTELEMENT

  nsDOMSVGFEPointLightElement();

private:
  ~nsDOMSVGFEPointLightElement();

protected:
  /* additional members */
};

/* Implementation file */
NS_IMPL_ISUPPORTS1(nsDOMSVGFEPointLightElement, nsIDOMSVGFEPointLightElement)

nsDOMSVGFEPointLightElement::nsDOMSVGFEPointLightElement()
{
  /* member initializers and constructor code */
}

nsDOMSVGFEPointLightElement::~nsDOMSVGFEPointLightElement()
{
  /* destructor code */
}

/* readonly attribute nsIDOMSVGAnimatedNumber x; */
NS_IMETHODIMP nsDOMSVGFEPointLightElement::GetX(nsIDOMSVGAnimatedNumber * *aX)
{
    return NS_ERROR_NOT_IMPLEMENTED;
}

/* readonly attribute nsIDOMSVGAnimatedNumber y; */
NS_IMETHODIMP nsDOMSVGFEPointLightElement::GetY(nsIDOMSVGAnimatedNumber * *aY)
{
    return NS_ERROR_NOT_IMPLEMENTED;
}

/* readonly attribute nsIDOMSVGAnimatedNumber z; */
NS_IMETHODIMP nsDOMSVGFEPointLightElement::GetZ(nsIDOMSVGAnimatedNumber * *aZ)
{
    return NS_ERROR_NOT_IMPLEMENTED;
}

/* End of implementation class template. */
#endif


/* starting interface:    nsIDOMSVGFESpotLightElement */
#define NS_IDOMSVGFESPOTLIGHTELEMENT_IID_STR "5515dd05-3d9d-4d6c-8460-a04aaf5afe15"

#define NS_IDOMSVGFESPOTLIGHTELEMENT_IID \
  {0x5515dd05, 0x3d9d, 0x4d6c, \
    { 0x84, 0x60, 0xa0, 0x4a, 0xaf, 0x5a, 0xfe, 0x15 }}

class NS_NO_VTABLE NS_SCRIPTABLE nsIDOMSVGFESpotLightElement : public nsIDOMSVGElement {
 public: 

  NS_DECLARE_STATIC_IID_ACCESSOR(NS_IDOMSVGFESPOTLIGHTELEMENT_IID)

  /* readonly attribute nsIDOMSVGAnimatedNumber x; */
  NS_SCRIPTABLE NS_IMETHOD GetX(nsIDOMSVGAnimatedNumber * *aX) = 0;

  /* readonly attribute nsIDOMSVGAnimatedNumber y; */
  NS_SCRIPTABLE NS_IMETHOD GetY(nsIDOMSVGAnimatedNumber * *aY) = 0;

  /* readonly attribute nsIDOMSVGAnimatedNumber z; */
  NS_SCRIPTABLE NS_IMETHOD GetZ(nsIDOMSVGAnimatedNumber * *aZ) = 0;

  /* readonly attribute nsIDOMSVGAnimatedNumber pointsAtX; */
  NS_SCRIPTABLE NS_IMETHOD GetPointsAtX(nsIDOMSVGAnimatedNumber * *aPointsAtX) = 0;

  /* readonly attribute nsIDOMSVGAnimatedNumber pointsAtY; */
  NS_SCRIPTABLE NS_IMETHOD GetPointsAtY(nsIDOMSVGAnimatedNumber * *aPointsAtY) = 0;

  /* readonly attribute nsIDOMSVGAnimatedNumber pointsAtZ; */
  NS_SCRIPTABLE NS_IMETHOD GetPointsAtZ(nsIDOMSVGAnimatedNumber * *aPointsAtZ) = 0;

  /* readonly attribute nsIDOMSVGAnimatedNumber specularExponent; */
  NS_SCRIPTABLE NS_IMETHOD GetSpecularExponent(nsIDOMSVGAnimatedNumber * *aSpecularExponent) = 0;

  /* readonly attribute nsIDOMSVGAnimatedNumber limitingConeAngle; */
  NS_SCRIPTABLE NS_IMETHOD GetLimitingConeAngle(nsIDOMSVGAnimatedNumber * *aLimitingConeAngle) = 0;

};

  NS_DEFINE_STATIC_IID_ACCESSOR(nsIDOMSVGFESpotLightElement, NS_IDOMSVGFESPOTLIGHTELEMENT_IID)

/* Use this macro when declaring classes that implement this interface. */
#define NS_DECL_NSIDOMSVGFESPOTLIGHTELEMENT \
  NS_SCRIPTABLE NS_IMETHOD GetX(nsIDOMSVGAnimatedNumber * *aX); \
  NS_SCRIPTABLE NS_IMETHOD GetY(nsIDOMSVGAnimatedNumber * *aY); \
  NS_SCRIPTABLE NS_IMETHOD GetZ(nsIDOMSVGAnimatedNumber * *aZ); \
  NS_SCRIPTABLE NS_IMETHOD GetPointsAtX(nsIDOMSVGAnimatedNumber * *aPointsAtX); \
  NS_SCRIPTABLE NS_IMETHOD GetPointsAtY(nsIDOMSVGAnimatedNumber * *aPointsAtY); \
  NS_SCRIPTABLE NS_IMETHOD GetPointsAtZ(nsIDOMSVGAnimatedNumber * *aPointsAtZ); \
  NS_SCRIPTABLE NS_IMETHOD GetSpecularExponent(nsIDOMSVGAnimatedNumber * *aSpecularExponent); \
  NS_SCRIPTABLE NS_IMETHOD GetLimitingConeAngle(nsIDOMSVGAnimatedNumber * *aLimitingConeAngle); 

/* Use this macro to declare functions that forward the behavior of this interface to another object. */
#define NS_FORWARD_NSIDOMSVGFESPOTLIGHTELEMENT(_to) \
  NS_SCRIPTABLE NS_IMETHOD GetX(nsIDOMSVGAnimatedNumber * *aX) { return _to GetX(aX); } \
  NS_SCRIPTABLE NS_IMETHOD GetY(nsIDOMSVGAnimatedNumber * *aY) { return _to GetY(aY); } \
  NS_SCRIPTABLE NS_IMETHOD GetZ(nsIDOMSVGAnimatedNumber * *aZ) { return _to GetZ(aZ); } \
  NS_SCRIPTABLE NS_IMETHOD GetPointsAtX(nsIDOMSVGAnimatedNumber * *aPointsAtX) { return _to GetPointsAtX(aPointsAtX); } \
  NS_SCRIPTABLE NS_IMETHOD GetPointsAtY(nsIDOMSVGAnimatedNumber * *aPointsAtY) { return _to GetPointsAtY(aPointsAtY); } \
  NS_SCRIPTABLE NS_IMETHOD GetPointsAtZ(nsIDOMSVGAnimatedNumber * *aPointsAtZ) { return _to GetPointsAtZ(aPointsAtZ); } \
  NS_SCRIPTABLE NS_IMETHOD GetSpecularExponent(nsIDOMSVGAnimatedNumber * *aSpecularExponent) { return _to GetSpecularExponent(aSpecularExponent); } \
  NS_SCRIPTABLE NS_IMETHOD GetLimitingConeAngle(nsIDOMSVGAnimatedNumber * *aLimitingConeAngle) { return _to GetLimitingConeAngle(aLimitingConeAngle); } 

/* Use this macro to declare functions that forward the behavior of this interface to another object in a safe way. */
#define NS_FORWARD_SAFE_NSIDOMSVGFESPOTLIGHTELEMENT(_to) \
  NS_SCRIPTABLE NS_IMETHOD GetX(nsIDOMSVGAnimatedNumber * *aX) { return !_to ? NS_ERROR_NULL_POINTER : _to->GetX(aX); } \
  NS_SCRIPTABLE NS_IMETHOD GetY(nsIDOMSVGAnimatedNumber * *aY) { return !_to ? NS_ERROR_NULL_POINTER : _to->GetY(aY); } \
  NS_SCRIPTABLE NS_IMETHOD GetZ(nsIDOMSVGAnimatedNumber * *aZ) { return !_to ? NS_ERROR_NULL_POINTER : _to->GetZ(aZ); } \
  NS_SCRIPTABLE NS_IMETHOD GetPointsAtX(nsIDOMSVGAnimatedNumber * *aPointsAtX) { return !_to ? NS_ERROR_NULL_POINTER : _to->GetPointsAtX(aPointsAtX); } \
  NS_SCRIPTABLE NS_IMETHOD GetPointsAtY(nsIDOMSVGAnimatedNumber * *aPointsAtY) { return !_to ? NS_ERROR_NULL_POINTER : _to->GetPointsAtY(aPointsAtY); } \
  NS_SCRIPTABLE NS_IMETHOD GetPointsAtZ(nsIDOMSVGAnimatedNumber * *aPointsAtZ) { return !_to ? NS_ERROR_NULL_POINTER : _to->GetPointsAtZ(aPointsAtZ); } \
  NS_SCRIPTABLE NS_IMETHOD GetSpecularExponent(nsIDOMSVGAnimatedNumber * *aSpecularExponent) { return !_to ? NS_ERROR_NULL_POINTER : _to->GetSpecularExponent(aSpecularExponent); } \
  NS_SCRIPTABLE NS_IMETHOD GetLimitingConeAngle(nsIDOMSVGAnimatedNumber * *aLimitingConeAngle) { return !_to ? NS_ERROR_NULL_POINTER : _to->GetLimitingConeAngle(aLimitingConeAngle); } 

#if 0
/* Use the code below as a template for the implementation class for this interface. */

/* Header file */
class nsDOMSVGFESpotLightElement : public nsIDOMSVGFESpotLightElement
{
public:
  NS_DECL_ISUPPORTS
  NS_DECL_NSIDOMSVGFESPOTLIGHTELEMENT

  nsDOMSVGFESpotLightElement();

private:
  ~nsDOMSVGFESpotLightElement();

protected:
  /* additional members */
};

/* Implementation file */
NS_IMPL_ISUPPORTS1(nsDOMSVGFESpotLightElement, nsIDOMSVGFESpotLightElement)

nsDOMSVGFESpotLightElement::nsDOMSVGFESpotLightElement()
{
  /* member initializers and constructor code */
}

nsDOMSVGFESpotLightElement::~nsDOMSVGFESpotLightElement()
{
  /* destructor code */
}

/* readonly attribute nsIDOMSVGAnimatedNumber x; */
NS_IMETHODIMP nsDOMSVGFESpotLightElement::GetX(nsIDOMSVGAnimatedNumber * *aX)
{
    return NS_ERROR_NOT_IMPLEMENTED;
}

/* readonly attribute nsIDOMSVGAnimatedNumber y; */
NS_IMETHODIMP nsDOMSVGFESpotLightElement::GetY(nsIDOMSVGAnimatedNumber * *aY)
{
    return NS_ERROR_NOT_IMPLEMENTED;
}

/* readonly attribute nsIDOMSVGAnimatedNumber z; */
NS_IMETHODIMP nsDOMSVGFESpotLightElement::GetZ(nsIDOMSVGAnimatedNumber * *aZ)
{
    return NS_ERROR_NOT_IMPLEMENTED;
}

/* readonly attribute nsIDOMSVGAnimatedNumber pointsAtX; */
NS_IMETHODIMP nsDOMSVGFESpotLightElement::GetPointsAtX(nsIDOMSVGAnimatedNumber * *aPointsAtX)
{
    return NS_ERROR_NOT_IMPLEMENTED;
}

/* readonly attribute nsIDOMSVGAnimatedNumber pointsAtY; */
NS_IMETHODIMP nsDOMSVGFESpotLightElement::GetPointsAtY(nsIDOMSVGAnimatedNumber * *aPointsAtY)
{
    return NS_ERROR_NOT_IMPLEMENTED;
}

/* readonly attribute nsIDOMSVGAnimatedNumber pointsAtZ; */
NS_IMETHODIMP nsDOMSVGFESpotLightElement::GetPointsAtZ(nsIDOMSVGAnimatedNumber * *aPointsAtZ)
{
    return NS_ERROR_NOT_IMPLEMENTED;
}

/* readonly attribute nsIDOMSVGAnimatedNumber specularExponent; */
NS_IMETHODIMP nsDOMSVGFESpotLightElement::GetSpecularExponent(nsIDOMSVGAnimatedNumber * *aSpecularExponent)
{
    return NS_ERROR_NOT_IMPLEMENTED;
}

/* readonly attribute nsIDOMSVGAnimatedNumber limitingConeAngle; */
NS_IMETHODIMP nsDOMSVGFESpotLightElement::GetLimitingConeAngle(nsIDOMSVGAnimatedNumber * *aLimitingConeAngle)
{
    return NS_ERROR_NOT_IMPLEMENTED;
}

/* End of implementation class template. */
#endif


/* starting interface:    nsIDOMSVGFEImageElement */
#define NS_IDOMSVGFEIMAGEELEMENT_IID_STR "3250f5c9-9c76-4e77-96d8-5f0cc85f41c4"

#define NS_IDOMSVGFEIMAGEELEMENT_IID \
  {0x3250f5c9, 0x9c76, 0x4e77, \
    { 0x96, 0xd8, 0x5f, 0x0c, 0xc8, 0x5f, 0x41, 0xc4 }}

class NS_NO_VTABLE NS_SCRIPTABLE nsIDOMSVGFEImageElement : public nsIDOMSVGFilterPrimitiveStandardAttributes {
 public: 

  NS_DECLARE_STATIC_IID_ACCESSOR(NS_IDOMSVGFEIMAGEELEMENT_IID)

};

  NS_DEFINE_STATIC_IID_ACCESSOR(nsIDOMSVGFEImageElement, NS_IDOMSVGFEIMAGEELEMENT_IID)

/* Use this macro when declaring classes that implement this interface. */
#define NS_DECL_NSIDOMSVGFEIMAGEELEMENT \
  /* no methods! */

/* Use this macro to declare functions that forward the behavior of this interface to another object. */
#define NS_FORWARD_NSIDOMSVGFEIMAGEELEMENT(_to) \
  /* no methods! */

/* Use this macro to declare functions that forward the behavior of this interface to another object in a safe way. */
#define NS_FORWARD_SAFE_NSIDOMSVGFEIMAGEELEMENT(_to) \
  /* no methods! */

#if 0
/* Use the code below as a template for the implementation class for this interface. */

/* Header file */
class nsDOMSVGFEImageElement : public nsIDOMSVGFEImageElement
{
public:
  NS_DECL_ISUPPORTS
  NS_DECL_NSIDOMSVGFEIMAGEELEMENT

  nsDOMSVGFEImageElement();

private:
  ~nsDOMSVGFEImageElement();

protected:
  /* additional members */
};

/* Implementation file */
NS_IMPL_ISUPPORTS1(nsDOMSVGFEImageElement, nsIDOMSVGFEImageElement)

nsDOMSVGFEImageElement::nsDOMSVGFEImageElement()
{
  /* member initializers and constructor code */
}

nsDOMSVGFEImageElement::~nsDOMSVGFEImageElement()
{
  /* destructor code */
}

/* End of implementation class template. */
#endif


/* starting interface:    nsIDOMSVGFEDisplacementMapElement */
#define NS_IDOMSVGFEDISPLACEMENTMAPELEMENT_IID_STR "80e1ea9c-eff3-490a-8c98-918963d2e7e9"

#define NS_IDOMSVGFEDISPLACEMENTMAPELEMENT_IID \
  {0x80e1ea9c, 0xeff3, 0x490a, \
    { 0x8c, 0x98, 0x91, 0x89, 0x63, 0xd2, 0xe7, 0xe9 }}

class NS_NO_VTABLE NS_SCRIPTABLE nsIDOMSVGFEDisplacementMapElement : public nsIDOMSVGFilterPrimitiveStandardAttributes {
 public: 

  NS_DECLARE_STATIC_IID_ACCESSOR(NS_IDOMSVGFEDISPLACEMENTMAPELEMENT_IID)

  enum { SVG_CHANNEL_UNKNOWN = 0U };

  enum { SVG_CHANNEL_R = 1U };

  enum { SVG_CHANNEL_G = 2U };

  enum { SVG_CHANNEL_B = 3U };

  enum { SVG_CHANNEL_A = 4U };

  /* readonly attribute nsIDOMSVGAnimatedString in1; */
  NS_SCRIPTABLE NS_IMETHOD GetIn1(nsIDOMSVGAnimatedString * *aIn1) = 0;

  /* readonly attribute nsIDOMSVGAnimatedString in2; */
  NS_SCRIPTABLE NS_IMETHOD GetIn2(nsIDOMSVGAnimatedString * *aIn2) = 0;

  /* readonly attribute nsIDOMSVGAnimatedNumber scale; */
  NS_SCRIPTABLE NS_IMETHOD GetScale(nsIDOMSVGAnimatedNumber * *aScale) = 0;

  /* readonly attribute nsIDOMSVGAnimatedEnumeration xChannelSelector; */
  NS_SCRIPTABLE NS_IMETHOD GetXChannelSelector(nsIDOMSVGAnimatedEnumeration * *aXChannelSelector) = 0;

  /* readonly attribute nsIDOMSVGAnimatedEnumeration yChannelSelector; */
  NS_SCRIPTABLE NS_IMETHOD GetYChannelSelector(nsIDOMSVGAnimatedEnumeration * *aYChannelSelector) = 0;

};

  NS_DEFINE_STATIC_IID_ACCESSOR(nsIDOMSVGFEDisplacementMapElement, NS_IDOMSVGFEDISPLACEMENTMAPELEMENT_IID)

/* Use this macro when declaring classes that implement this interface. */
#define NS_DECL_NSIDOMSVGFEDISPLACEMENTMAPELEMENT \
  NS_SCRIPTABLE NS_IMETHOD GetIn1(nsIDOMSVGAnimatedString * *aIn1); \
  NS_SCRIPTABLE NS_IMETHOD GetIn2(nsIDOMSVGAnimatedString * *aIn2); \
  NS_SCRIPTABLE NS_IMETHOD GetScale(nsIDOMSVGAnimatedNumber * *aScale); \
  NS_SCRIPTABLE NS_IMETHOD GetXChannelSelector(nsIDOMSVGAnimatedEnumeration * *aXChannelSelector); \
  NS_SCRIPTABLE NS_IMETHOD GetYChannelSelector(nsIDOMSVGAnimatedEnumeration * *aYChannelSelector); 

/* Use this macro to declare functions that forward the behavior of this interface to another object. */
#define NS_FORWARD_NSIDOMSVGFEDISPLACEMENTMAPELEMENT(_to) \
  NS_SCRIPTABLE NS_IMETHOD GetIn1(nsIDOMSVGAnimatedString * *aIn1) { return _to GetIn1(aIn1); } \
  NS_SCRIPTABLE NS_IMETHOD GetIn2(nsIDOMSVGAnimatedString * *aIn2) { return _to GetIn2(aIn2); } \
  NS_SCRIPTABLE NS_IMETHOD GetScale(nsIDOMSVGAnimatedNumber * *aScale) { return _to GetScale(aScale); } \
  NS_SCRIPTABLE NS_IMETHOD GetXChannelSelector(nsIDOMSVGAnimatedEnumeration * *aXChannelSelector) { return _to GetXChannelSelector(aXChannelSelector); } \
  NS_SCRIPTABLE NS_IMETHOD GetYChannelSelector(nsIDOMSVGAnimatedEnumeration * *aYChannelSelector) { return _to GetYChannelSelector(aYChannelSelector); } 

/* Use this macro to declare functions that forward the behavior of this interface to another object in a safe way. */
#define NS_FORWARD_SAFE_NSIDOMSVGFEDISPLACEMENTMAPELEMENT(_to) \
  NS_SCRIPTABLE NS_IMETHOD GetIn1(nsIDOMSVGAnimatedString * *aIn1) { return !_to ? NS_ERROR_NULL_POINTER : _to->GetIn1(aIn1); } \
  NS_SCRIPTABLE NS_IMETHOD GetIn2(nsIDOMSVGAnimatedString * *aIn2) { return !_to ? NS_ERROR_NULL_POINTER : _to->GetIn2(aIn2); } \
  NS_SCRIPTABLE NS_IMETHOD GetScale(nsIDOMSVGAnimatedNumber * *aScale) { return !_to ? NS_ERROR_NULL_POINTER : _to->GetScale(aScale); } \
  NS_SCRIPTABLE NS_IMETHOD GetXChannelSelector(nsIDOMSVGAnimatedEnumeration * *aXChannelSelector) { return !_to ? NS_ERROR_NULL_POINTER : _to->GetXChannelSelector(aXChannelSelector); } \
  NS_SCRIPTABLE NS_IMETHOD GetYChannelSelector(nsIDOMSVGAnimatedEnumeration * *aYChannelSelector) { return !_to ? NS_ERROR_NULL_POINTER : _to->GetYChannelSelector(aYChannelSelector); } 

#if 0
/* Use the code below as a template for the implementation class for this interface. */

/* Header file */
class nsDOMSVGFEDisplacementMapElement : public nsIDOMSVGFEDisplacementMapElement
{
public:
  NS_DECL_ISUPPORTS
  NS_DECL_NSIDOMSVGFEDISPLACEMENTMAPELEMENT

  nsDOMSVGFEDisplacementMapElement();

private:
  ~nsDOMSVGFEDisplacementMapElement();

protected:
  /* additional members */
};

/* Implementation file */
NS_IMPL_ISUPPORTS1(nsDOMSVGFEDisplacementMapElement, nsIDOMSVGFEDisplacementMapElement)

nsDOMSVGFEDisplacementMapElement::nsDOMSVGFEDisplacementMapElement()
{
  /* member initializers and constructor code */
}

nsDOMSVGFEDisplacementMapElement::~nsDOMSVGFEDisplacementMapElement()
{
  /* destructor code */
}

/* readonly attribute nsIDOMSVGAnimatedString in1; */
NS_IMETHODIMP nsDOMSVGFEDisplacementMapElement::GetIn1(nsIDOMSVGAnimatedString * *aIn1)
{
    return NS_ERROR_NOT_IMPLEMENTED;
}

/* readonly attribute nsIDOMSVGAnimatedString in2; */
NS_IMETHODIMP nsDOMSVGFEDisplacementMapElement::GetIn2(nsIDOMSVGAnimatedString * *aIn2)
{
    return NS_ERROR_NOT_IMPLEMENTED;
}

/* readonly attribute nsIDOMSVGAnimatedNumber scale; */
NS_IMETHODIMP nsDOMSVGFEDisplacementMapElement::GetScale(nsIDOMSVGAnimatedNumber * *aScale)
{
    return NS_ERROR_NOT_IMPLEMENTED;
}

/* readonly attribute nsIDOMSVGAnimatedEnumeration xChannelSelector; */
NS_IMETHODIMP nsDOMSVGFEDisplacementMapElement::GetXChannelSelector(nsIDOMSVGAnimatedEnumeration * *aXChannelSelector)
{
    return NS_ERROR_NOT_IMPLEMENTED;
}

/* readonly attribute nsIDOMSVGAnimatedEnumeration yChannelSelector; */
NS_IMETHODIMP nsDOMSVGFEDisplacementMapElement::GetYChannelSelector(nsIDOMSVGAnimatedEnumeration * *aYChannelSelector)
{
    return NS_ERROR_NOT_IMPLEMENTED;
}

/* End of implementation class template. */
#endif


#endif /* __gen_nsIDOMSVGFilters_h__ */
