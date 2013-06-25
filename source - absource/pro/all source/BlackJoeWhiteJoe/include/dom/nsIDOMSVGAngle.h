/*
 * DO NOT EDIT.  THIS FILE IS GENERATED FROM e:/builds/moz2_slave/mozilla-1.9.1-win32-xulrunner/build/dom/public/idl/svg/nsIDOMSVGAngle.idl
 */

#ifndef __gen_nsIDOMSVGAngle_h__
#define __gen_nsIDOMSVGAngle_h__


#ifndef __gen_domstubs_h__
#include "domstubs.h"
#endif

/* For IDL files that don't want to include root IDL files. */
#ifndef NS_NO_VTABLE
#define NS_NO_VTABLE
#endif

/* starting interface:    nsIDOMSVGAngle */
#define NS_IDOMSVGANGLE_IID_STR "58b6190e-37b3-412a-ba02-1d5ad6c6ea7c"

#define NS_IDOMSVGANGLE_IID \
  {0x58b6190e, 0x37b3, 0x412a, \
    { 0xba, 0x02, 0x1d, 0x5a, 0xd6, 0xc6, 0xea, 0x7c }}

/**
 * The nsIDOMSVGAngle interface is the interface to an SVG angle.
 *
 * For more information on this interface please see
 * http://www.w3.org/TR/SVG11/types.html#InterfaceSVGAngle
 *
 */
class NS_NO_VTABLE NS_SCRIPTABLE nsIDOMSVGAngle : public nsISupports {
 public: 

  NS_DECLARE_STATIC_IID_ACCESSOR(NS_IDOMSVGANGLE_IID)

  enum { SVG_ANGLETYPE_UNKNOWN = 0U };

  enum { SVG_ANGLETYPE_UNSPECIFIED = 1U };

  enum { SVG_ANGLETYPE_DEG = 2U };

  enum { SVG_ANGLETYPE_RAD = 3U };

  enum { SVG_ANGLETYPE_GRAD = 4U };

  /* readonly attribute unsigned short unitType; */
  NS_SCRIPTABLE NS_IMETHOD GetUnitType(PRUint16 *aUnitType) = 0;

  /* attribute float value; */
  NS_SCRIPTABLE NS_IMETHOD GetValue(float *aValue) = 0;
  NS_SCRIPTABLE NS_IMETHOD SetValue(float aValue) = 0;

  /* attribute float valueInSpecifiedUnits; */
  NS_SCRIPTABLE NS_IMETHOD GetValueInSpecifiedUnits(float *aValueInSpecifiedUnits) = 0;
  NS_SCRIPTABLE NS_IMETHOD SetValueInSpecifiedUnits(float aValueInSpecifiedUnits) = 0;

  /* attribute DOMString valueAsString; */
  NS_SCRIPTABLE NS_IMETHOD GetValueAsString(nsAString & aValueAsString) = 0;
  NS_SCRIPTABLE NS_IMETHOD SetValueAsString(const nsAString & aValueAsString) = 0;

  /* void newValueSpecifiedUnits (in unsigned short unitType, in float valueInSpecifiedUnits); */
  NS_SCRIPTABLE NS_IMETHOD NewValueSpecifiedUnits(PRUint16 unitType, float valueInSpecifiedUnits) = 0;

  /* void convertToSpecifiedUnits (in unsigned short unitType); */
  NS_SCRIPTABLE NS_IMETHOD ConvertToSpecifiedUnits(PRUint16 unitType) = 0;

};

  NS_DEFINE_STATIC_IID_ACCESSOR(nsIDOMSVGAngle, NS_IDOMSVGANGLE_IID)

/* Use this macro when declaring classes that implement this interface. */
#define NS_DECL_NSIDOMSVGANGLE \
  NS_SCRIPTABLE NS_IMETHOD GetUnitType(PRUint16 *aUnitType); \
  NS_SCRIPTABLE NS_IMETHOD GetValue(float *aValue); \
  NS_SCRIPTABLE NS_IMETHOD SetValue(float aValue); \
  NS_SCRIPTABLE NS_IMETHOD GetValueInSpecifiedUnits(float *aValueInSpecifiedUnits); \
  NS_SCRIPTABLE NS_IMETHOD SetValueInSpecifiedUnits(float aValueInSpecifiedUnits); \
  NS_SCRIPTABLE NS_IMETHOD GetValueAsString(nsAString & aValueAsString); \
  NS_SCRIPTABLE NS_IMETHOD SetValueAsString(const nsAString & aValueAsString); \
  NS_SCRIPTABLE NS_IMETHOD NewValueSpecifiedUnits(PRUint16 unitType, float valueInSpecifiedUnits); \
  NS_SCRIPTABLE NS_IMETHOD ConvertToSpecifiedUnits(PRUint16 unitType); 

/* Use this macro to declare functions that forward the behavior of this interface to another object. */
#define NS_FORWARD_NSIDOMSVGANGLE(_to) \
  NS_SCRIPTABLE NS_IMETHOD GetUnitType(PRUint16 *aUnitType) { return _to GetUnitType(aUnitType); } \
  NS_SCRIPTABLE NS_IMETHOD GetValue(float *aValue) { return _to GetValue(aValue); } \
  NS_SCRIPTABLE NS_IMETHOD SetValue(float aValue) { return _to SetValue(aValue); } \
  NS_SCRIPTABLE NS_IMETHOD GetValueInSpecifiedUnits(float *aValueInSpecifiedUnits) { return _to GetValueInSpecifiedUnits(aValueInSpecifiedUnits); } \
  NS_SCRIPTABLE NS_IMETHOD SetValueInSpecifiedUnits(float aValueInSpecifiedUnits) { return _to SetValueInSpecifiedUnits(aValueInSpecifiedUnits); } \
  NS_SCRIPTABLE NS_IMETHOD GetValueAsString(nsAString & aValueAsString) { return _to GetValueAsString(aValueAsString); } \
  NS_SCRIPTABLE NS_IMETHOD SetValueAsString(const nsAString & aValueAsString) { return _to SetValueAsString(aValueAsString); } \
  NS_SCRIPTABLE NS_IMETHOD NewValueSpecifiedUnits(PRUint16 unitType, float valueInSpecifiedUnits) { return _to NewValueSpecifiedUnits(unitType, valueInSpecifiedUnits); } \
  NS_SCRIPTABLE NS_IMETHOD ConvertToSpecifiedUnits(PRUint16 unitType) { return _to ConvertToSpecifiedUnits(unitType); } 

/* Use this macro to declare functions that forward the behavior of this interface to another object in a safe way. */
#define NS_FORWARD_SAFE_NSIDOMSVGANGLE(_to) \
  NS_SCRIPTABLE NS_IMETHOD GetUnitType(PRUint16 *aUnitType) { return !_to ? NS_ERROR_NULL_POINTER : _to->GetUnitType(aUnitType); } \
  NS_SCRIPTABLE NS_IMETHOD GetValue(float *aValue) { return !_to ? NS_ERROR_NULL_POINTER : _to->GetValue(aValue); } \
  NS_SCRIPTABLE NS_IMETHOD SetValue(float aValue) { return !_to ? NS_ERROR_NULL_POINTER : _to->SetValue(aValue); } \
  NS_SCRIPTABLE NS_IMETHOD GetValueInSpecifiedUnits(float *aValueInSpecifiedUnits) { return !_to ? NS_ERROR_NULL_POINTER : _to->GetValueInSpecifiedUnits(aValueInSpecifiedUnits); } \
  NS_SCRIPTABLE NS_IMETHOD SetValueInSpecifiedUnits(float aValueInSpecifiedUnits) { return !_to ? NS_ERROR_NULL_POINTER : _to->SetValueInSpecifiedUnits(aValueInSpecifiedUnits); } \
  NS_SCRIPTABLE NS_IMETHOD GetValueAsString(nsAString & aValueAsString) { return !_to ? NS_ERROR_NULL_POINTER : _to->GetValueAsString(aValueAsString); } \
  NS_SCRIPTABLE NS_IMETHOD SetValueAsString(const nsAString & aValueAsString) { return !_to ? NS_ERROR_NULL_POINTER : _to->SetValueAsString(aValueAsString); } \
  NS_SCRIPTABLE NS_IMETHOD NewValueSpecifiedUnits(PRUint16 unitType, float valueInSpecifiedUnits) { return !_to ? NS_ERROR_NULL_POINTER : _to->NewValueSpecifiedUnits(unitType, valueInSpecifiedUnits); } \
  NS_SCRIPTABLE NS_IMETHOD ConvertToSpecifiedUnits(PRUint16 unitType) { return !_to ? NS_ERROR_NULL_POINTER : _to->ConvertToSpecifiedUnits(unitType); } 

#if 0
/* Use the code below as a template for the implementation class for this interface. */

/* Header file */
class nsDOMSVGAngle : public nsIDOMSVGAngle
{
public:
  NS_DECL_ISUPPORTS
  NS_DECL_NSIDOMSVGANGLE

  nsDOMSVGAngle();

private:
  ~nsDOMSVGAngle();

protected:
  /* additional members */
};

/* Implementation file */
NS_IMPL_ISUPPORTS1(nsDOMSVGAngle, nsIDOMSVGAngle)

nsDOMSVGAngle::nsDOMSVGAngle()
{
  /* member initializers and constructor code */
}

nsDOMSVGAngle::~nsDOMSVGAngle()
{
  /* destructor code */
}

/* readonly attribute unsigned short unitType; */
NS_IMETHODIMP nsDOMSVGAngle::GetUnitType(PRUint16 *aUnitType)
{
    return NS_ERROR_NOT_IMPLEMENTED;
}

/* attribute float value; */
NS_IMETHODIMP nsDOMSVGAngle::GetValue(float *aValue)
{
    return NS_ERROR_NOT_IMPLEMENTED;
}
NS_IMETHODIMP nsDOMSVGAngle::SetValue(float aValue)
{
    return NS_ERROR_NOT_IMPLEMENTED;
}

/* attribute float valueInSpecifiedUnits; */
NS_IMETHODIMP nsDOMSVGAngle::GetValueInSpecifiedUnits(float *aValueInSpecifiedUnits)
{
    return NS_ERROR_NOT_IMPLEMENTED;
}
NS_IMETHODIMP nsDOMSVGAngle::SetValueInSpecifiedUnits(float aValueInSpecifiedUnits)
{
    return NS_ERROR_NOT_IMPLEMENTED;
}

/* attribute DOMString valueAsString; */
NS_IMETHODIMP nsDOMSVGAngle::GetValueAsString(nsAString & aValueAsString)
{
    return NS_ERROR_NOT_IMPLEMENTED;
}
NS_IMETHODIMP nsDOMSVGAngle::SetValueAsString(const nsAString & aValueAsString)
{
    return NS_ERROR_NOT_IMPLEMENTED;
}

/* void newValueSpecifiedUnits (in unsigned short unitType, in float valueInSpecifiedUnits); */
NS_IMETHODIMP nsDOMSVGAngle::NewValueSpecifiedUnits(PRUint16 unitType, float valueInSpecifiedUnits)
{
    return NS_ERROR_NOT_IMPLEMENTED;
}

/* void convertToSpecifiedUnits (in unsigned short unitType); */
NS_IMETHODIMP nsDOMSVGAngle::ConvertToSpecifiedUnits(PRUint16 unitType)
{
    return NS_ERROR_NOT_IMPLEMENTED;
}

/* End of implementation class template. */
#endif


#endif /* __gen_nsIDOMSVGAngle_h__ */
