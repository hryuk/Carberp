/*
 * DO NOT EDIT.  THIS FILE IS GENERATED FROM e:/builds/moz2_slave/mozilla-1.9.1-win32-xulrunner/build/dom/public/idl/svg/nsIDOMSVGUnitTypes.idl
 */

#ifndef __gen_nsIDOMSVGUnitTypes_h__
#define __gen_nsIDOMSVGUnitTypes_h__


#ifndef __gen_domstubs_h__
#include "domstubs.h"
#endif

/* For IDL files that don't want to include root IDL files. */
#ifndef NS_NO_VTABLE
#define NS_NO_VTABLE
#endif

/* starting interface:    nsIDOMSVGUnitTypes */
#define NS_IDOMSVGUNITTYPES_IID_STR "154b572f-3d0b-49c0-8b5d-8864d05bd3d1"

#define NS_IDOMSVGUNITTYPES_IID \
  {0x154b572f, 0x3d0b, 0x49c0, \
    { 0x8b, 0x5d, 0x88, 0x64, 0xd0, 0x5b, 0xd3, 0xd1 }}

/**
 * The nsIDOMSVGUnitTypes interface is the interface to SVG unit types.
 *
 * For more information on this interface please see
 * http://www.w3.org/TR/SVG11/types.html
 *
 */
class NS_NO_VTABLE NS_SCRIPTABLE nsIDOMSVGUnitTypes : public nsISupports {
 public: 

  NS_DECLARE_STATIC_IID_ACCESSOR(NS_IDOMSVGUNITTYPES_IID)

  enum { SVG_UNIT_TYPE_UNKNOWN = 0U };

  enum { SVG_UNIT_TYPE_USERSPACEONUSE = 1U };

  enum { SVG_UNIT_TYPE_OBJECTBOUNDINGBOX = 2U };

};

  NS_DEFINE_STATIC_IID_ACCESSOR(nsIDOMSVGUnitTypes, NS_IDOMSVGUNITTYPES_IID)

/* Use this macro when declaring classes that implement this interface. */
#define NS_DECL_NSIDOMSVGUNITTYPES \

/* Use this macro to declare functions that forward the behavior of this interface to another object. */
#define NS_FORWARD_NSIDOMSVGUNITTYPES(_to) \

/* Use this macro to declare functions that forward the behavior of this interface to another object in a safe way. */
#define NS_FORWARD_SAFE_NSIDOMSVGUNITTYPES(_to) \

#if 0
/* Use the code below as a template for the implementation class for this interface. */

/* Header file */
class nsDOMSVGUnitTypes : public nsIDOMSVGUnitTypes
{
public:
  NS_DECL_ISUPPORTS
  NS_DECL_NSIDOMSVGUNITTYPES

  nsDOMSVGUnitTypes();

private:
  ~nsDOMSVGUnitTypes();

protected:
  /* additional members */
};

/* Implementation file */
NS_IMPL_ISUPPORTS1(nsDOMSVGUnitTypes, nsIDOMSVGUnitTypes)

nsDOMSVGUnitTypes::nsDOMSVGUnitTypes()
{
  /* member initializers and constructor code */
}

nsDOMSVGUnitTypes::~nsDOMSVGUnitTypes()
{
  /* destructor code */
}

/* End of implementation class template. */
#endif


#endif /* __gen_nsIDOMSVGUnitTypes_h__ */
