/*
 * DO NOT EDIT.  THIS FILE IS GENERATED FROM e:/builds/moz2_slave/mozilla-1.9.1-win32-xulrunner/build/dom/public/idl/svg/nsIDOMSVGPathSeg.idl
 */

#ifndef __gen_nsIDOMSVGPathSeg_h__
#define __gen_nsIDOMSVGPathSeg_h__


#ifndef __gen_domstubs_h__
#include "domstubs.h"
#endif

/* For IDL files that don't want to include root IDL files. */
#ifndef NS_NO_VTABLE
#define NS_NO_VTABLE
#endif

/* starting interface:    nsIDOMSVGPathSeg */
#define NS_IDOMSVGPATHSEG_IID_STR "b9022da7-e26d-4df3-8c94-b45c4aedda7c"

#define NS_IDOMSVGPATHSEG_IID \
  {0xb9022da7, 0xe26d, 0x4df3, \
    { 0x8c, 0x94, 0xb4, 0x5c, 0x4a, 0xed, 0xda, 0x7c }}

class NS_NO_VTABLE NS_SCRIPTABLE nsIDOMSVGPathSeg : public nsISupports {
 public: 

  NS_DECLARE_STATIC_IID_ACCESSOR(NS_IDOMSVGPATHSEG_IID)

  enum { PATHSEG_UNKNOWN = 0U };

  enum { PATHSEG_CLOSEPATH = 1U };

  enum { PATHSEG_MOVETO_ABS = 2U };

  enum { PATHSEG_MOVETO_REL = 3U };

  enum { PATHSEG_LINETO_ABS = 4U };

  enum { PATHSEG_LINETO_REL = 5U };

  enum { PATHSEG_CURVETO_CUBIC_ABS = 6U };

  enum { PATHSEG_CURVETO_CUBIC_REL = 7U };

  enum { PATHSEG_CURVETO_QUADRATIC_ABS = 8U };

  enum { PATHSEG_CURVETO_QUADRATIC_REL = 9U };

  enum { PATHSEG_ARC_ABS = 10U };

  enum { PATHSEG_ARC_REL = 11U };

  enum { PATHSEG_LINETO_HORIZONTAL_ABS = 12U };

  enum { PATHSEG_LINETO_HORIZONTAL_REL = 13U };

  enum { PATHSEG_LINETO_VERTICAL_ABS = 14U };

  enum { PATHSEG_LINETO_VERTICAL_REL = 15U };

  enum { PATHSEG_CURVETO_CUBIC_SMOOTH_ABS = 16U };

  enum { PATHSEG_CURVETO_CUBIC_SMOOTH_REL = 17U };

  enum { PATHSEG_CURVETO_QUADRATIC_SMOOTH_ABS = 18U };

  enum { PATHSEG_CURVETO_QUADRATIC_SMOOTH_REL = 19U };

  /* readonly attribute unsigned short pathSegType; */
  NS_SCRIPTABLE NS_IMETHOD GetPathSegType(PRUint16 *aPathSegType) = 0;

  /* readonly attribute DOMString pathSegTypeAsLetter; */
  NS_SCRIPTABLE NS_IMETHOD GetPathSegTypeAsLetter(nsAString & aPathSegTypeAsLetter) = 0;

};

  NS_DEFINE_STATIC_IID_ACCESSOR(nsIDOMSVGPathSeg, NS_IDOMSVGPATHSEG_IID)

/* Use this macro when declaring classes that implement this interface. */
#define NS_DECL_NSIDOMSVGPATHSEG \
  NS_SCRIPTABLE NS_IMETHOD GetPathSegType(PRUint16 *aPathSegType); \
  NS_SCRIPTABLE NS_IMETHOD GetPathSegTypeAsLetter(nsAString & aPathSegTypeAsLetter); 

/* Use this macro to declare functions that forward the behavior of this interface to another object. */
#define NS_FORWARD_NSIDOMSVGPATHSEG(_to) \
  NS_SCRIPTABLE NS_IMETHOD GetPathSegType(PRUint16 *aPathSegType) { return _to GetPathSegType(aPathSegType); } \
  NS_SCRIPTABLE NS_IMETHOD GetPathSegTypeAsLetter(nsAString & aPathSegTypeAsLetter) { return _to GetPathSegTypeAsLetter(aPathSegTypeAsLetter); } 

/* Use this macro to declare functions that forward the behavior of this interface to another object in a safe way. */
#define NS_FORWARD_SAFE_NSIDOMSVGPATHSEG(_to) \
  NS_SCRIPTABLE NS_IMETHOD GetPathSegType(PRUint16 *aPathSegType) { return !_to ? NS_ERROR_NULL_POINTER : _to->GetPathSegType(aPathSegType); } \
  NS_SCRIPTABLE NS_IMETHOD GetPathSegTypeAsLetter(nsAString & aPathSegTypeAsLetter) { return !_to ? NS_ERROR_NULL_POINTER : _to->GetPathSegTypeAsLetter(aPathSegTypeAsLetter); } 

#if 0
/* Use the code below as a template for the implementation class for this interface. */

/* Header file */
class nsDOMSVGPathSeg : public nsIDOMSVGPathSeg
{
public:
  NS_DECL_ISUPPORTS
  NS_DECL_NSIDOMSVGPATHSEG

  nsDOMSVGPathSeg();

private:
  ~nsDOMSVGPathSeg();

protected:
  /* additional members */
};

/* Implementation file */
NS_IMPL_ISUPPORTS1(nsDOMSVGPathSeg, nsIDOMSVGPathSeg)

nsDOMSVGPathSeg::nsDOMSVGPathSeg()
{
  /* member initializers and constructor code */
}

nsDOMSVGPathSeg::~nsDOMSVGPathSeg()
{
  /* destructor code */
}

/* readonly attribute unsigned short pathSegType; */
NS_IMETHODIMP nsDOMSVGPathSeg::GetPathSegType(PRUint16 *aPathSegType)
{
    return NS_ERROR_NOT_IMPLEMENTED;
}

/* readonly attribute DOMString pathSegTypeAsLetter; */
NS_IMETHODIMP nsDOMSVGPathSeg::GetPathSegTypeAsLetter(nsAString & aPathSegTypeAsLetter)
{
    return NS_ERROR_NOT_IMPLEMENTED;
}

/* End of implementation class template. */
#endif


/* starting interface:    nsIDOMSVGPathSegClosePath */
#define NS_IDOMSVGPATHSEGCLOSEPATH_IID_STR "4970505f-2cc0-4afa-92e6-0cf4bdbf5a53"

#define NS_IDOMSVGPATHSEGCLOSEPATH_IID \
  {0x4970505f, 0x2cc0, 0x4afa, \
    { 0x92, 0xe6, 0x0c, 0xf4, 0xbd, 0xbf, 0x5a, 0x53 }}

class NS_NO_VTABLE NS_SCRIPTABLE nsIDOMSVGPathSegClosePath : public nsISupports {
 public: 

  NS_DECLARE_STATIC_IID_ACCESSOR(NS_IDOMSVGPATHSEGCLOSEPATH_IID)

};

  NS_DEFINE_STATIC_IID_ACCESSOR(nsIDOMSVGPathSegClosePath, NS_IDOMSVGPATHSEGCLOSEPATH_IID)

/* Use this macro when declaring classes that implement this interface. */
#define NS_DECL_NSIDOMSVGPATHSEGCLOSEPATH \
  /* no methods! */

/* Use this macro to declare functions that forward the behavior of this interface to another object. */
#define NS_FORWARD_NSIDOMSVGPATHSEGCLOSEPATH(_to) \
  /* no methods! */

/* Use this macro to declare functions that forward the behavior of this interface to another object in a safe way. */
#define NS_FORWARD_SAFE_NSIDOMSVGPATHSEGCLOSEPATH(_to) \
  /* no methods! */

#if 0
/* Use the code below as a template for the implementation class for this interface. */

/* Header file */
class nsDOMSVGPathSegClosePath : public nsIDOMSVGPathSegClosePath
{
public:
  NS_DECL_ISUPPORTS
  NS_DECL_NSIDOMSVGPATHSEGCLOSEPATH

  nsDOMSVGPathSegClosePath();

private:
  ~nsDOMSVGPathSegClosePath();

protected:
  /* additional members */
};

/* Implementation file */
NS_IMPL_ISUPPORTS1(nsDOMSVGPathSegClosePath, nsIDOMSVGPathSegClosePath)

nsDOMSVGPathSegClosePath::nsDOMSVGPathSegClosePath()
{
  /* member initializers and constructor code */
}

nsDOMSVGPathSegClosePath::~nsDOMSVGPathSegClosePath()
{
  /* destructor code */
}

/* End of implementation class template. */
#endif


/* starting interface:    nsIDOMSVGPathSegMovetoAbs */
#define NS_IDOMSVGPATHSEGMOVETOABS_IID_STR "30cf7749-bf1f-4f9c-9558-8ee24da3a22c"

#define NS_IDOMSVGPATHSEGMOVETOABS_IID \
  {0x30cf7749, 0xbf1f, 0x4f9c, \
    { 0x95, 0x58, 0x8e, 0xe2, 0x4d, 0xa3, 0xa2, 0x2c }}

class NS_NO_VTABLE NS_SCRIPTABLE nsIDOMSVGPathSegMovetoAbs : public nsISupports {
 public: 

  NS_DECLARE_STATIC_IID_ACCESSOR(NS_IDOMSVGPATHSEGMOVETOABS_IID)

  /* attribute float x; */
  NS_SCRIPTABLE NS_IMETHOD GetX(float *aX) = 0;
  NS_SCRIPTABLE NS_IMETHOD SetX(float aX) = 0;

  /* attribute float y; */
  NS_SCRIPTABLE NS_IMETHOD GetY(float *aY) = 0;
  NS_SCRIPTABLE NS_IMETHOD SetY(float aY) = 0;

};

  NS_DEFINE_STATIC_IID_ACCESSOR(nsIDOMSVGPathSegMovetoAbs, NS_IDOMSVGPATHSEGMOVETOABS_IID)

/* Use this macro when declaring classes that implement this interface. */
#define NS_DECL_NSIDOMSVGPATHSEGMOVETOABS \
  NS_SCRIPTABLE NS_IMETHOD GetX(float *aX); \
  NS_SCRIPTABLE NS_IMETHOD SetX(float aX); \
  NS_SCRIPTABLE NS_IMETHOD GetY(float *aY); \
  NS_SCRIPTABLE NS_IMETHOD SetY(float aY); 

/* Use this macro to declare functions that forward the behavior of this interface to another object. */
#define NS_FORWARD_NSIDOMSVGPATHSEGMOVETOABS(_to) \
  NS_SCRIPTABLE NS_IMETHOD GetX(float *aX) { return _to GetX(aX); } \
  NS_SCRIPTABLE NS_IMETHOD SetX(float aX) { return _to SetX(aX); } \
  NS_SCRIPTABLE NS_IMETHOD GetY(float *aY) { return _to GetY(aY); } \
  NS_SCRIPTABLE NS_IMETHOD SetY(float aY) { return _to SetY(aY); } 

/* Use this macro to declare functions that forward the behavior of this interface to another object in a safe way. */
#define NS_FORWARD_SAFE_NSIDOMSVGPATHSEGMOVETOABS(_to) \
  NS_SCRIPTABLE NS_IMETHOD GetX(float *aX) { return !_to ? NS_ERROR_NULL_POINTER : _to->GetX(aX); } \
  NS_SCRIPTABLE NS_IMETHOD SetX(float aX) { return !_to ? NS_ERROR_NULL_POINTER : _to->SetX(aX); } \
  NS_SCRIPTABLE NS_IMETHOD GetY(float *aY) { return !_to ? NS_ERROR_NULL_POINTER : _to->GetY(aY); } \
  NS_SCRIPTABLE NS_IMETHOD SetY(float aY) { return !_to ? NS_ERROR_NULL_POINTER : _to->SetY(aY); } 

#if 0
/* Use the code below as a template for the implementation class for this interface. */

/* Header file */
class nsDOMSVGPathSegMovetoAbs : public nsIDOMSVGPathSegMovetoAbs
{
public:
  NS_DECL_ISUPPORTS
  NS_DECL_NSIDOMSVGPATHSEGMOVETOABS

  nsDOMSVGPathSegMovetoAbs();

private:
  ~nsDOMSVGPathSegMovetoAbs();

protected:
  /* additional members */
};

/* Implementation file */
NS_IMPL_ISUPPORTS1(nsDOMSVGPathSegMovetoAbs, nsIDOMSVGPathSegMovetoAbs)

nsDOMSVGPathSegMovetoAbs::nsDOMSVGPathSegMovetoAbs()
{
  /* member initializers and constructor code */
}

nsDOMSVGPathSegMovetoAbs::~nsDOMSVGPathSegMovetoAbs()
{
  /* destructor code */
}

/* attribute float x; */
NS_IMETHODIMP nsDOMSVGPathSegMovetoAbs::GetX(float *aX)
{
    return NS_ERROR_NOT_IMPLEMENTED;
}
NS_IMETHODIMP nsDOMSVGPathSegMovetoAbs::SetX(float aX)
{
    return NS_ERROR_NOT_IMPLEMENTED;
}

/* attribute float y; */
NS_IMETHODIMP nsDOMSVGPathSegMovetoAbs::GetY(float *aY)
{
    return NS_ERROR_NOT_IMPLEMENTED;
}
NS_IMETHODIMP nsDOMSVGPathSegMovetoAbs::SetY(float aY)
{
    return NS_ERROR_NOT_IMPLEMENTED;
}

/* End of implementation class template. */
#endif


/* starting interface:    nsIDOMSVGPathSegMovetoRel */
#define NS_IDOMSVGPATHSEGMOVETOREL_IID_STR "58ca7e86-661a-473a-96de-89682e7e24d6"

#define NS_IDOMSVGPATHSEGMOVETOREL_IID \
  {0x58ca7e86, 0x661a, 0x473a, \
    { 0x96, 0xde, 0x89, 0x68, 0x2e, 0x7e, 0x24, 0xd6 }}

class NS_NO_VTABLE NS_SCRIPTABLE nsIDOMSVGPathSegMovetoRel : public nsISupports {
 public: 

  NS_DECLARE_STATIC_IID_ACCESSOR(NS_IDOMSVGPATHSEGMOVETOREL_IID)

  /* attribute float x; */
  NS_SCRIPTABLE NS_IMETHOD GetX(float *aX) = 0;
  NS_SCRIPTABLE NS_IMETHOD SetX(float aX) = 0;

  /* attribute float y; */
  NS_SCRIPTABLE NS_IMETHOD GetY(float *aY) = 0;
  NS_SCRIPTABLE NS_IMETHOD SetY(float aY) = 0;

};

  NS_DEFINE_STATIC_IID_ACCESSOR(nsIDOMSVGPathSegMovetoRel, NS_IDOMSVGPATHSEGMOVETOREL_IID)

/* Use this macro when declaring classes that implement this interface. */
#define NS_DECL_NSIDOMSVGPATHSEGMOVETOREL \
  NS_SCRIPTABLE NS_IMETHOD GetX(float *aX); \
  NS_SCRIPTABLE NS_IMETHOD SetX(float aX); \
  NS_SCRIPTABLE NS_IMETHOD GetY(float *aY); \
  NS_SCRIPTABLE NS_IMETHOD SetY(float aY); 

/* Use this macro to declare functions that forward the behavior of this interface to another object. */
#define NS_FORWARD_NSIDOMSVGPATHSEGMOVETOREL(_to) \
  NS_SCRIPTABLE NS_IMETHOD GetX(float *aX) { return _to GetX(aX); } \
  NS_SCRIPTABLE NS_IMETHOD SetX(float aX) { return _to SetX(aX); } \
  NS_SCRIPTABLE NS_IMETHOD GetY(float *aY) { return _to GetY(aY); } \
  NS_SCRIPTABLE NS_IMETHOD SetY(float aY) { return _to SetY(aY); } 

/* Use this macro to declare functions that forward the behavior of this interface to another object in a safe way. */
#define NS_FORWARD_SAFE_NSIDOMSVGPATHSEGMOVETOREL(_to) \
  NS_SCRIPTABLE NS_IMETHOD GetX(float *aX) { return !_to ? NS_ERROR_NULL_POINTER : _to->GetX(aX); } \
  NS_SCRIPTABLE NS_IMETHOD SetX(float aX) { return !_to ? NS_ERROR_NULL_POINTER : _to->SetX(aX); } \
  NS_SCRIPTABLE NS_IMETHOD GetY(float *aY) { return !_to ? NS_ERROR_NULL_POINTER : _to->GetY(aY); } \
  NS_SCRIPTABLE NS_IMETHOD SetY(float aY) { return !_to ? NS_ERROR_NULL_POINTER : _to->SetY(aY); } 

#if 0
/* Use the code below as a template for the implementation class for this interface. */

/* Header file */
class nsDOMSVGPathSegMovetoRel : public nsIDOMSVGPathSegMovetoRel
{
public:
  NS_DECL_ISUPPORTS
  NS_DECL_NSIDOMSVGPATHSEGMOVETOREL

  nsDOMSVGPathSegMovetoRel();

private:
  ~nsDOMSVGPathSegMovetoRel();

protected:
  /* additional members */
};

/* Implementation file */
NS_IMPL_ISUPPORTS1(nsDOMSVGPathSegMovetoRel, nsIDOMSVGPathSegMovetoRel)

nsDOMSVGPathSegMovetoRel::nsDOMSVGPathSegMovetoRel()
{
  /* member initializers and constructor code */
}

nsDOMSVGPathSegMovetoRel::~nsDOMSVGPathSegMovetoRel()
{
  /* destructor code */
}

/* attribute float x; */
NS_IMETHODIMP nsDOMSVGPathSegMovetoRel::GetX(float *aX)
{
    return NS_ERROR_NOT_IMPLEMENTED;
}
NS_IMETHODIMP nsDOMSVGPathSegMovetoRel::SetX(float aX)
{
    return NS_ERROR_NOT_IMPLEMENTED;
}

/* attribute float y; */
NS_IMETHODIMP nsDOMSVGPathSegMovetoRel::GetY(float *aY)
{
    return NS_ERROR_NOT_IMPLEMENTED;
}
NS_IMETHODIMP nsDOMSVGPathSegMovetoRel::SetY(float aY)
{
    return NS_ERROR_NOT_IMPLEMENTED;
}

/* End of implementation class template. */
#endif


/* starting interface:    nsIDOMSVGPathSegLinetoAbs */
#define NS_IDOMSVGPATHSEGLINETOABS_IID_STR "5c7ba7b0-c7c5-4a7b-bc1c-2d784153be77"

#define NS_IDOMSVGPATHSEGLINETOABS_IID \
  {0x5c7ba7b0, 0xc7c5, 0x4a7b, \
    { 0xbc, 0x1c, 0x2d, 0x78, 0x41, 0x53, 0xbe, 0x77 }}

class NS_NO_VTABLE NS_SCRIPTABLE nsIDOMSVGPathSegLinetoAbs : public nsISupports {
 public: 

  NS_DECLARE_STATIC_IID_ACCESSOR(NS_IDOMSVGPATHSEGLINETOABS_IID)

  /* attribute float x; */
  NS_SCRIPTABLE NS_IMETHOD GetX(float *aX) = 0;
  NS_SCRIPTABLE NS_IMETHOD SetX(float aX) = 0;

  /* attribute float y; */
  NS_SCRIPTABLE NS_IMETHOD GetY(float *aY) = 0;
  NS_SCRIPTABLE NS_IMETHOD SetY(float aY) = 0;

};

  NS_DEFINE_STATIC_IID_ACCESSOR(nsIDOMSVGPathSegLinetoAbs, NS_IDOMSVGPATHSEGLINETOABS_IID)

/* Use this macro when declaring classes that implement this interface. */
#define NS_DECL_NSIDOMSVGPATHSEGLINETOABS \
  NS_SCRIPTABLE NS_IMETHOD GetX(float *aX); \
  NS_SCRIPTABLE NS_IMETHOD SetX(float aX); \
  NS_SCRIPTABLE NS_IMETHOD GetY(float *aY); \
  NS_SCRIPTABLE NS_IMETHOD SetY(float aY); 

/* Use this macro to declare functions that forward the behavior of this interface to another object. */
#define NS_FORWARD_NSIDOMSVGPATHSEGLINETOABS(_to) \
  NS_SCRIPTABLE NS_IMETHOD GetX(float *aX) { return _to GetX(aX); } \
  NS_SCRIPTABLE NS_IMETHOD SetX(float aX) { return _to SetX(aX); } \
  NS_SCRIPTABLE NS_IMETHOD GetY(float *aY) { return _to GetY(aY); } \
  NS_SCRIPTABLE NS_IMETHOD SetY(float aY) { return _to SetY(aY); } 

/* Use this macro to declare functions that forward the behavior of this interface to another object in a safe way. */
#define NS_FORWARD_SAFE_NSIDOMSVGPATHSEGLINETOABS(_to) \
  NS_SCRIPTABLE NS_IMETHOD GetX(float *aX) { return !_to ? NS_ERROR_NULL_POINTER : _to->GetX(aX); } \
  NS_SCRIPTABLE NS_IMETHOD SetX(float aX) { return !_to ? NS_ERROR_NULL_POINTER : _to->SetX(aX); } \
  NS_SCRIPTABLE NS_IMETHOD GetY(float *aY) { return !_to ? NS_ERROR_NULL_POINTER : _to->GetY(aY); } \
  NS_SCRIPTABLE NS_IMETHOD SetY(float aY) { return !_to ? NS_ERROR_NULL_POINTER : _to->SetY(aY); } 

#if 0
/* Use the code below as a template for the implementation class for this interface. */

/* Header file */
class nsDOMSVGPathSegLinetoAbs : public nsIDOMSVGPathSegLinetoAbs
{
public:
  NS_DECL_ISUPPORTS
  NS_DECL_NSIDOMSVGPATHSEGLINETOABS

  nsDOMSVGPathSegLinetoAbs();

private:
  ~nsDOMSVGPathSegLinetoAbs();

protected:
  /* additional members */
};

/* Implementation file */
NS_IMPL_ISUPPORTS1(nsDOMSVGPathSegLinetoAbs, nsIDOMSVGPathSegLinetoAbs)

nsDOMSVGPathSegLinetoAbs::nsDOMSVGPathSegLinetoAbs()
{
  /* member initializers and constructor code */
}

nsDOMSVGPathSegLinetoAbs::~nsDOMSVGPathSegLinetoAbs()
{
  /* destructor code */
}

/* attribute float x; */
NS_IMETHODIMP nsDOMSVGPathSegLinetoAbs::GetX(float *aX)
{
    return NS_ERROR_NOT_IMPLEMENTED;
}
NS_IMETHODIMP nsDOMSVGPathSegLinetoAbs::SetX(float aX)
{
    return NS_ERROR_NOT_IMPLEMENTED;
}

/* attribute float y; */
NS_IMETHODIMP nsDOMSVGPathSegLinetoAbs::GetY(float *aY)
{
    return NS_ERROR_NOT_IMPLEMENTED;
}
NS_IMETHODIMP nsDOMSVGPathSegLinetoAbs::SetY(float aY)
{
    return NS_ERROR_NOT_IMPLEMENTED;
}

/* End of implementation class template. */
#endif


/* starting interface:    nsIDOMSVGPathSegLinetoRel */
#define NS_IDOMSVGPATHSEGLINETOREL_IID_STR "7933a81a-72c5-4489-ba64-5635f4c23063"

#define NS_IDOMSVGPATHSEGLINETOREL_IID \
  {0x7933a81a, 0x72c5, 0x4489, \
    { 0xba, 0x64, 0x56, 0x35, 0xf4, 0xc2, 0x30, 0x63 }}

class NS_NO_VTABLE NS_SCRIPTABLE nsIDOMSVGPathSegLinetoRel : public nsISupports {
 public: 

  NS_DECLARE_STATIC_IID_ACCESSOR(NS_IDOMSVGPATHSEGLINETOREL_IID)

  /* attribute float x; */
  NS_SCRIPTABLE NS_IMETHOD GetX(float *aX) = 0;
  NS_SCRIPTABLE NS_IMETHOD SetX(float aX) = 0;

  /* attribute float y; */
  NS_SCRIPTABLE NS_IMETHOD GetY(float *aY) = 0;
  NS_SCRIPTABLE NS_IMETHOD SetY(float aY) = 0;

};

  NS_DEFINE_STATIC_IID_ACCESSOR(nsIDOMSVGPathSegLinetoRel, NS_IDOMSVGPATHSEGLINETOREL_IID)

/* Use this macro when declaring classes that implement this interface. */
#define NS_DECL_NSIDOMSVGPATHSEGLINETOREL \
  NS_SCRIPTABLE NS_IMETHOD GetX(float *aX); \
  NS_SCRIPTABLE NS_IMETHOD SetX(float aX); \
  NS_SCRIPTABLE NS_IMETHOD GetY(float *aY); \
  NS_SCRIPTABLE NS_IMETHOD SetY(float aY); 

/* Use this macro to declare functions that forward the behavior of this interface to another object. */
#define NS_FORWARD_NSIDOMSVGPATHSEGLINETOREL(_to) \
  NS_SCRIPTABLE NS_IMETHOD GetX(float *aX) { return _to GetX(aX); } \
  NS_SCRIPTABLE NS_IMETHOD SetX(float aX) { return _to SetX(aX); } \
  NS_SCRIPTABLE NS_IMETHOD GetY(float *aY) { return _to GetY(aY); } \
  NS_SCRIPTABLE NS_IMETHOD SetY(float aY) { return _to SetY(aY); } 

/* Use this macro to declare functions that forward the behavior of this interface to another object in a safe way. */
#define NS_FORWARD_SAFE_NSIDOMSVGPATHSEGLINETOREL(_to) \
  NS_SCRIPTABLE NS_IMETHOD GetX(float *aX) { return !_to ? NS_ERROR_NULL_POINTER : _to->GetX(aX); } \
  NS_SCRIPTABLE NS_IMETHOD SetX(float aX) { return !_to ? NS_ERROR_NULL_POINTER : _to->SetX(aX); } \
  NS_SCRIPTABLE NS_IMETHOD GetY(float *aY) { return !_to ? NS_ERROR_NULL_POINTER : _to->GetY(aY); } \
  NS_SCRIPTABLE NS_IMETHOD SetY(float aY) { return !_to ? NS_ERROR_NULL_POINTER : _to->SetY(aY); } 

#if 0
/* Use the code below as a template for the implementation class for this interface. */

/* Header file */
class nsDOMSVGPathSegLinetoRel : public nsIDOMSVGPathSegLinetoRel
{
public:
  NS_DECL_ISUPPORTS
  NS_DECL_NSIDOMSVGPATHSEGLINETOREL

  nsDOMSVGPathSegLinetoRel();

private:
  ~nsDOMSVGPathSegLinetoRel();

protected:
  /* additional members */
};

/* Implementation file */
NS_IMPL_ISUPPORTS1(nsDOMSVGPathSegLinetoRel, nsIDOMSVGPathSegLinetoRel)

nsDOMSVGPathSegLinetoRel::nsDOMSVGPathSegLinetoRel()
{
  /* member initializers and constructor code */
}

nsDOMSVGPathSegLinetoRel::~nsDOMSVGPathSegLinetoRel()
{
  /* destructor code */
}

/* attribute float x; */
NS_IMETHODIMP nsDOMSVGPathSegLinetoRel::GetX(float *aX)
{
    return NS_ERROR_NOT_IMPLEMENTED;
}
NS_IMETHODIMP nsDOMSVGPathSegLinetoRel::SetX(float aX)
{
    return NS_ERROR_NOT_IMPLEMENTED;
}

/* attribute float y; */
NS_IMETHODIMP nsDOMSVGPathSegLinetoRel::GetY(float *aY)
{
    return NS_ERROR_NOT_IMPLEMENTED;
}
NS_IMETHODIMP nsDOMSVGPathSegLinetoRel::SetY(float aY)
{
    return NS_ERROR_NOT_IMPLEMENTED;
}

/* End of implementation class template. */
#endif


/* starting interface:    nsIDOMSVGPathSegCurvetoCubicAbs */
#define NS_IDOMSVGPATHSEGCURVETOCUBICABS_IID_STR "380afecd-f884-4da7-a0d7-5ffc4531b70b"

#define NS_IDOMSVGPATHSEGCURVETOCUBICABS_IID \
  {0x380afecd, 0xf884, 0x4da7, \
    { 0xa0, 0xd7, 0x5f, 0xfc, 0x45, 0x31, 0xb7, 0x0b }}

class NS_NO_VTABLE NS_SCRIPTABLE nsIDOMSVGPathSegCurvetoCubicAbs : public nsISupports {
 public: 

  NS_DECLARE_STATIC_IID_ACCESSOR(NS_IDOMSVGPATHSEGCURVETOCUBICABS_IID)

  /* attribute float x; */
  NS_SCRIPTABLE NS_IMETHOD GetX(float *aX) = 0;
  NS_SCRIPTABLE NS_IMETHOD SetX(float aX) = 0;

  /* attribute float y; */
  NS_SCRIPTABLE NS_IMETHOD GetY(float *aY) = 0;
  NS_SCRIPTABLE NS_IMETHOD SetY(float aY) = 0;

  /* attribute float x1; */
  NS_SCRIPTABLE NS_IMETHOD GetX1(float *aX1) = 0;
  NS_SCRIPTABLE NS_IMETHOD SetX1(float aX1) = 0;

  /* attribute float y1; */
  NS_SCRIPTABLE NS_IMETHOD GetY1(float *aY1) = 0;
  NS_SCRIPTABLE NS_IMETHOD SetY1(float aY1) = 0;

  /* attribute float x2; */
  NS_SCRIPTABLE NS_IMETHOD GetX2(float *aX2) = 0;
  NS_SCRIPTABLE NS_IMETHOD SetX2(float aX2) = 0;

  /* attribute float y2; */
  NS_SCRIPTABLE NS_IMETHOD GetY2(float *aY2) = 0;
  NS_SCRIPTABLE NS_IMETHOD SetY2(float aY2) = 0;

};

  NS_DEFINE_STATIC_IID_ACCESSOR(nsIDOMSVGPathSegCurvetoCubicAbs, NS_IDOMSVGPATHSEGCURVETOCUBICABS_IID)

/* Use this macro when declaring classes that implement this interface. */
#define NS_DECL_NSIDOMSVGPATHSEGCURVETOCUBICABS \
  NS_SCRIPTABLE NS_IMETHOD GetX(float *aX); \
  NS_SCRIPTABLE NS_IMETHOD SetX(float aX); \
  NS_SCRIPTABLE NS_IMETHOD GetY(float *aY); \
  NS_SCRIPTABLE NS_IMETHOD SetY(float aY); \
  NS_SCRIPTABLE NS_IMETHOD GetX1(float *aX1); \
  NS_SCRIPTABLE NS_IMETHOD SetX1(float aX1); \
  NS_SCRIPTABLE NS_IMETHOD GetY1(float *aY1); \
  NS_SCRIPTABLE NS_IMETHOD SetY1(float aY1); \
  NS_SCRIPTABLE NS_IMETHOD GetX2(float *aX2); \
  NS_SCRIPTABLE NS_IMETHOD SetX2(float aX2); \
  NS_SCRIPTABLE NS_IMETHOD GetY2(float *aY2); \
  NS_SCRIPTABLE NS_IMETHOD SetY2(float aY2); 

/* Use this macro to declare functions that forward the behavior of this interface to another object. */
#define NS_FORWARD_NSIDOMSVGPATHSEGCURVETOCUBICABS(_to) \
  NS_SCRIPTABLE NS_IMETHOD GetX(float *aX) { return _to GetX(aX); } \
  NS_SCRIPTABLE NS_IMETHOD SetX(float aX) { return _to SetX(aX); } \
  NS_SCRIPTABLE NS_IMETHOD GetY(float *aY) { return _to GetY(aY); } \
  NS_SCRIPTABLE NS_IMETHOD SetY(float aY) { return _to SetY(aY); } \
  NS_SCRIPTABLE NS_IMETHOD GetX1(float *aX1) { return _to GetX1(aX1); } \
  NS_SCRIPTABLE NS_IMETHOD SetX1(float aX1) { return _to SetX1(aX1); } \
  NS_SCRIPTABLE NS_IMETHOD GetY1(float *aY1) { return _to GetY1(aY1); } \
  NS_SCRIPTABLE NS_IMETHOD SetY1(float aY1) { return _to SetY1(aY1); } \
  NS_SCRIPTABLE NS_IMETHOD GetX2(float *aX2) { return _to GetX2(aX2); } \
  NS_SCRIPTABLE NS_IMETHOD SetX2(float aX2) { return _to SetX2(aX2); } \
  NS_SCRIPTABLE NS_IMETHOD GetY2(float *aY2) { return _to GetY2(aY2); } \
  NS_SCRIPTABLE NS_IMETHOD SetY2(float aY2) { return _to SetY2(aY2); } 

/* Use this macro to declare functions that forward the behavior of this interface to another object in a safe way. */
#define NS_FORWARD_SAFE_NSIDOMSVGPATHSEGCURVETOCUBICABS(_to) \
  NS_SCRIPTABLE NS_IMETHOD GetX(float *aX) { return !_to ? NS_ERROR_NULL_POINTER : _to->GetX(aX); } \
  NS_SCRIPTABLE NS_IMETHOD SetX(float aX) { return !_to ? NS_ERROR_NULL_POINTER : _to->SetX(aX); } \
  NS_SCRIPTABLE NS_IMETHOD GetY(float *aY) { return !_to ? NS_ERROR_NULL_POINTER : _to->GetY(aY); } \
  NS_SCRIPTABLE NS_IMETHOD SetY(float aY) { return !_to ? NS_ERROR_NULL_POINTER : _to->SetY(aY); } \
  NS_SCRIPTABLE NS_IMETHOD GetX1(float *aX1) { return !_to ? NS_ERROR_NULL_POINTER : _to->GetX1(aX1); } \
  NS_SCRIPTABLE NS_IMETHOD SetX1(float aX1) { return !_to ? NS_ERROR_NULL_POINTER : _to->SetX1(aX1); } \
  NS_SCRIPTABLE NS_IMETHOD GetY1(float *aY1) { return !_to ? NS_ERROR_NULL_POINTER : _to->GetY1(aY1); } \
  NS_SCRIPTABLE NS_IMETHOD SetY1(float aY1) { return !_to ? NS_ERROR_NULL_POINTER : _to->SetY1(aY1); } \
  NS_SCRIPTABLE NS_IMETHOD GetX2(float *aX2) { return !_to ? NS_ERROR_NULL_POINTER : _to->GetX2(aX2); } \
  NS_SCRIPTABLE NS_IMETHOD SetX2(float aX2) { return !_to ? NS_ERROR_NULL_POINTER : _to->SetX2(aX2); } \
  NS_SCRIPTABLE NS_IMETHOD GetY2(float *aY2) { return !_to ? NS_ERROR_NULL_POINTER : _to->GetY2(aY2); } \
  NS_SCRIPTABLE NS_IMETHOD SetY2(float aY2) { return !_to ? NS_ERROR_NULL_POINTER : _to->SetY2(aY2); } 

#if 0
/* Use the code below as a template for the implementation class for this interface. */

/* Header file */
class nsDOMSVGPathSegCurvetoCubicAbs : public nsIDOMSVGPathSegCurvetoCubicAbs
{
public:
  NS_DECL_ISUPPORTS
  NS_DECL_NSIDOMSVGPATHSEGCURVETOCUBICABS

  nsDOMSVGPathSegCurvetoCubicAbs();

private:
  ~nsDOMSVGPathSegCurvetoCubicAbs();

protected:
  /* additional members */
};

/* Implementation file */
NS_IMPL_ISUPPORTS1(nsDOMSVGPathSegCurvetoCubicAbs, nsIDOMSVGPathSegCurvetoCubicAbs)

nsDOMSVGPathSegCurvetoCubicAbs::nsDOMSVGPathSegCurvetoCubicAbs()
{
  /* member initializers and constructor code */
}

nsDOMSVGPathSegCurvetoCubicAbs::~nsDOMSVGPathSegCurvetoCubicAbs()
{
  /* destructor code */
}

/* attribute float x; */
NS_IMETHODIMP nsDOMSVGPathSegCurvetoCubicAbs::GetX(float *aX)
{
    return NS_ERROR_NOT_IMPLEMENTED;
}
NS_IMETHODIMP nsDOMSVGPathSegCurvetoCubicAbs::SetX(float aX)
{
    return NS_ERROR_NOT_IMPLEMENTED;
}

/* attribute float y; */
NS_IMETHODIMP nsDOMSVGPathSegCurvetoCubicAbs::GetY(float *aY)
{
    return NS_ERROR_NOT_IMPLEMENTED;
}
NS_IMETHODIMP nsDOMSVGPathSegCurvetoCubicAbs::SetY(float aY)
{
    return NS_ERROR_NOT_IMPLEMENTED;
}

/* attribute float x1; */
NS_IMETHODIMP nsDOMSVGPathSegCurvetoCubicAbs::GetX1(float *aX1)
{
    return NS_ERROR_NOT_IMPLEMENTED;
}
NS_IMETHODIMP nsDOMSVGPathSegCurvetoCubicAbs::SetX1(float aX1)
{
    return NS_ERROR_NOT_IMPLEMENTED;
}

/* attribute float y1; */
NS_IMETHODIMP nsDOMSVGPathSegCurvetoCubicAbs::GetY1(float *aY1)
{
    return NS_ERROR_NOT_IMPLEMENTED;
}
NS_IMETHODIMP nsDOMSVGPathSegCurvetoCubicAbs::SetY1(float aY1)
{
    return NS_ERROR_NOT_IMPLEMENTED;
}

/* attribute float x2; */
NS_IMETHODIMP nsDOMSVGPathSegCurvetoCubicAbs::GetX2(float *aX2)
{
    return NS_ERROR_NOT_IMPLEMENTED;
}
NS_IMETHODIMP nsDOMSVGPathSegCurvetoCubicAbs::SetX2(float aX2)
{
    return NS_ERROR_NOT_IMPLEMENTED;
}

/* attribute float y2; */
NS_IMETHODIMP nsDOMSVGPathSegCurvetoCubicAbs::GetY2(float *aY2)
{
    return NS_ERROR_NOT_IMPLEMENTED;
}
NS_IMETHODIMP nsDOMSVGPathSegCurvetoCubicAbs::SetY2(float aY2)
{
    return NS_ERROR_NOT_IMPLEMENTED;
}

/* End of implementation class template. */
#endif


/* starting interface:    nsIDOMSVGPathSegCurvetoCubicRel */
#define NS_IDOMSVGPATHSEGCURVETOCUBICREL_IID_STR "0e661233-0c4f-4e0d-94d3-fbc460ad1f88"

#define NS_IDOMSVGPATHSEGCURVETOCUBICREL_IID \
  {0x0e661233, 0x0c4f, 0x4e0d, \
    { 0x94, 0xd3, 0xfb, 0xc4, 0x60, 0xad, 0x1f, 0x88 }}

class NS_NO_VTABLE NS_SCRIPTABLE nsIDOMSVGPathSegCurvetoCubicRel : public nsISupports {
 public: 

  NS_DECLARE_STATIC_IID_ACCESSOR(NS_IDOMSVGPATHSEGCURVETOCUBICREL_IID)

  /* attribute float x; */
  NS_SCRIPTABLE NS_IMETHOD GetX(float *aX) = 0;
  NS_SCRIPTABLE NS_IMETHOD SetX(float aX) = 0;

  /* attribute float y; */
  NS_SCRIPTABLE NS_IMETHOD GetY(float *aY) = 0;
  NS_SCRIPTABLE NS_IMETHOD SetY(float aY) = 0;

  /* attribute float x1; */
  NS_SCRIPTABLE NS_IMETHOD GetX1(float *aX1) = 0;
  NS_SCRIPTABLE NS_IMETHOD SetX1(float aX1) = 0;

  /* attribute float y1; */
  NS_SCRIPTABLE NS_IMETHOD GetY1(float *aY1) = 0;
  NS_SCRIPTABLE NS_IMETHOD SetY1(float aY1) = 0;

  /* attribute float x2; */
  NS_SCRIPTABLE NS_IMETHOD GetX2(float *aX2) = 0;
  NS_SCRIPTABLE NS_IMETHOD SetX2(float aX2) = 0;

  /* attribute float y2; */
  NS_SCRIPTABLE NS_IMETHOD GetY2(float *aY2) = 0;
  NS_SCRIPTABLE NS_IMETHOD SetY2(float aY2) = 0;

};

  NS_DEFINE_STATIC_IID_ACCESSOR(nsIDOMSVGPathSegCurvetoCubicRel, NS_IDOMSVGPATHSEGCURVETOCUBICREL_IID)

/* Use this macro when declaring classes that implement this interface. */
#define NS_DECL_NSIDOMSVGPATHSEGCURVETOCUBICREL \
  NS_SCRIPTABLE NS_IMETHOD GetX(float *aX); \
  NS_SCRIPTABLE NS_IMETHOD SetX(float aX); \
  NS_SCRIPTABLE NS_IMETHOD GetY(float *aY); \
  NS_SCRIPTABLE NS_IMETHOD SetY(float aY); \
  NS_SCRIPTABLE NS_IMETHOD GetX1(float *aX1); \
  NS_SCRIPTABLE NS_IMETHOD SetX1(float aX1); \
  NS_SCRIPTABLE NS_IMETHOD GetY1(float *aY1); \
  NS_SCRIPTABLE NS_IMETHOD SetY1(float aY1); \
  NS_SCRIPTABLE NS_IMETHOD GetX2(float *aX2); \
  NS_SCRIPTABLE NS_IMETHOD SetX2(float aX2); \
  NS_SCRIPTABLE NS_IMETHOD GetY2(float *aY2); \
  NS_SCRIPTABLE NS_IMETHOD SetY2(float aY2); 

/* Use this macro to declare functions that forward the behavior of this interface to another object. */
#define NS_FORWARD_NSIDOMSVGPATHSEGCURVETOCUBICREL(_to) \
  NS_SCRIPTABLE NS_IMETHOD GetX(float *aX) { return _to GetX(aX); } \
  NS_SCRIPTABLE NS_IMETHOD SetX(float aX) { return _to SetX(aX); } \
  NS_SCRIPTABLE NS_IMETHOD GetY(float *aY) { return _to GetY(aY); } \
  NS_SCRIPTABLE NS_IMETHOD SetY(float aY) { return _to SetY(aY); } \
  NS_SCRIPTABLE NS_IMETHOD GetX1(float *aX1) { return _to GetX1(aX1); } \
  NS_SCRIPTABLE NS_IMETHOD SetX1(float aX1) { return _to SetX1(aX1); } \
  NS_SCRIPTABLE NS_IMETHOD GetY1(float *aY1) { return _to GetY1(aY1); } \
  NS_SCRIPTABLE NS_IMETHOD SetY1(float aY1) { return _to SetY1(aY1); } \
  NS_SCRIPTABLE NS_IMETHOD GetX2(float *aX2) { return _to GetX2(aX2); } \
  NS_SCRIPTABLE NS_IMETHOD SetX2(float aX2) { return _to SetX2(aX2); } \
  NS_SCRIPTABLE NS_IMETHOD GetY2(float *aY2) { return _to GetY2(aY2); } \
  NS_SCRIPTABLE NS_IMETHOD SetY2(float aY2) { return _to SetY2(aY2); } 

/* Use this macro to declare functions that forward the behavior of this interface to another object in a safe way. */
#define NS_FORWARD_SAFE_NSIDOMSVGPATHSEGCURVETOCUBICREL(_to) \
  NS_SCRIPTABLE NS_IMETHOD GetX(float *aX) { return !_to ? NS_ERROR_NULL_POINTER : _to->GetX(aX); } \
  NS_SCRIPTABLE NS_IMETHOD SetX(float aX) { return !_to ? NS_ERROR_NULL_POINTER : _to->SetX(aX); } \
  NS_SCRIPTABLE NS_IMETHOD GetY(float *aY) { return !_to ? NS_ERROR_NULL_POINTER : _to->GetY(aY); } \
  NS_SCRIPTABLE NS_IMETHOD SetY(float aY) { return !_to ? NS_ERROR_NULL_POINTER : _to->SetY(aY); } \
  NS_SCRIPTABLE NS_IMETHOD GetX1(float *aX1) { return !_to ? NS_ERROR_NULL_POINTER : _to->GetX1(aX1); } \
  NS_SCRIPTABLE NS_IMETHOD SetX1(float aX1) { return !_to ? NS_ERROR_NULL_POINTER : _to->SetX1(aX1); } \
  NS_SCRIPTABLE NS_IMETHOD GetY1(float *aY1) { return !_to ? NS_ERROR_NULL_POINTER : _to->GetY1(aY1); } \
  NS_SCRIPTABLE NS_IMETHOD SetY1(float aY1) { return !_to ? NS_ERROR_NULL_POINTER : _to->SetY1(aY1); } \
  NS_SCRIPTABLE NS_IMETHOD GetX2(float *aX2) { return !_to ? NS_ERROR_NULL_POINTER : _to->GetX2(aX2); } \
  NS_SCRIPTABLE NS_IMETHOD SetX2(float aX2) { return !_to ? NS_ERROR_NULL_POINTER : _to->SetX2(aX2); } \
  NS_SCRIPTABLE NS_IMETHOD GetY2(float *aY2) { return !_to ? NS_ERROR_NULL_POINTER : _to->GetY2(aY2); } \
  NS_SCRIPTABLE NS_IMETHOD SetY2(float aY2) { return !_to ? NS_ERROR_NULL_POINTER : _to->SetY2(aY2); } 

#if 0
/* Use the code below as a template for the implementation class for this interface. */

/* Header file */
class nsDOMSVGPathSegCurvetoCubicRel : public nsIDOMSVGPathSegCurvetoCubicRel
{
public:
  NS_DECL_ISUPPORTS
  NS_DECL_NSIDOMSVGPATHSEGCURVETOCUBICREL

  nsDOMSVGPathSegCurvetoCubicRel();

private:
  ~nsDOMSVGPathSegCurvetoCubicRel();

protected:
  /* additional members */
};

/* Implementation file */
NS_IMPL_ISUPPORTS1(nsDOMSVGPathSegCurvetoCubicRel, nsIDOMSVGPathSegCurvetoCubicRel)

nsDOMSVGPathSegCurvetoCubicRel::nsDOMSVGPathSegCurvetoCubicRel()
{
  /* member initializers and constructor code */
}

nsDOMSVGPathSegCurvetoCubicRel::~nsDOMSVGPathSegCurvetoCubicRel()
{
  /* destructor code */
}

/* attribute float x; */
NS_IMETHODIMP nsDOMSVGPathSegCurvetoCubicRel::GetX(float *aX)
{
    return NS_ERROR_NOT_IMPLEMENTED;
}
NS_IMETHODIMP nsDOMSVGPathSegCurvetoCubicRel::SetX(float aX)
{
    return NS_ERROR_NOT_IMPLEMENTED;
}

/* attribute float y; */
NS_IMETHODIMP nsDOMSVGPathSegCurvetoCubicRel::GetY(float *aY)
{
    return NS_ERROR_NOT_IMPLEMENTED;
}
NS_IMETHODIMP nsDOMSVGPathSegCurvetoCubicRel::SetY(float aY)
{
    return NS_ERROR_NOT_IMPLEMENTED;
}

/* attribute float x1; */
NS_IMETHODIMP nsDOMSVGPathSegCurvetoCubicRel::GetX1(float *aX1)
{
    return NS_ERROR_NOT_IMPLEMENTED;
}
NS_IMETHODIMP nsDOMSVGPathSegCurvetoCubicRel::SetX1(float aX1)
{
    return NS_ERROR_NOT_IMPLEMENTED;
}

/* attribute float y1; */
NS_IMETHODIMP nsDOMSVGPathSegCurvetoCubicRel::GetY1(float *aY1)
{
    return NS_ERROR_NOT_IMPLEMENTED;
}
NS_IMETHODIMP nsDOMSVGPathSegCurvetoCubicRel::SetY1(float aY1)
{
    return NS_ERROR_NOT_IMPLEMENTED;
}

/* attribute float x2; */
NS_IMETHODIMP nsDOMSVGPathSegCurvetoCubicRel::GetX2(float *aX2)
{
    return NS_ERROR_NOT_IMPLEMENTED;
}
NS_IMETHODIMP nsDOMSVGPathSegCurvetoCubicRel::SetX2(float aX2)
{
    return NS_ERROR_NOT_IMPLEMENTED;
}

/* attribute float y2; */
NS_IMETHODIMP nsDOMSVGPathSegCurvetoCubicRel::GetY2(float *aY2)
{
    return NS_ERROR_NOT_IMPLEMENTED;
}
NS_IMETHODIMP nsDOMSVGPathSegCurvetoCubicRel::SetY2(float aY2)
{
    return NS_ERROR_NOT_IMPLEMENTED;
}

/* End of implementation class template. */
#endif


/* starting interface:    nsIDOMSVGPathSegCurvetoQuadraticAbs */
#define NS_IDOMSVGPATHSEGCURVETOQUADRATICABS_IID_STR "b7aef0f0-2830-4145-b04f-fe05789ccf8a"

#define NS_IDOMSVGPATHSEGCURVETOQUADRATICABS_IID \
  {0xb7aef0f0, 0x2830, 0x4145, \
    { 0xb0, 0x4f, 0xfe, 0x05, 0x78, 0x9c, 0xcf, 0x8a }}

class NS_NO_VTABLE NS_SCRIPTABLE nsIDOMSVGPathSegCurvetoQuadraticAbs : public nsISupports {
 public: 

  NS_DECLARE_STATIC_IID_ACCESSOR(NS_IDOMSVGPATHSEGCURVETOQUADRATICABS_IID)

  /* attribute float x; */
  NS_SCRIPTABLE NS_IMETHOD GetX(float *aX) = 0;
  NS_SCRIPTABLE NS_IMETHOD SetX(float aX) = 0;

  /* attribute float y; */
  NS_SCRIPTABLE NS_IMETHOD GetY(float *aY) = 0;
  NS_SCRIPTABLE NS_IMETHOD SetY(float aY) = 0;

  /* attribute float x1; */
  NS_SCRIPTABLE NS_IMETHOD GetX1(float *aX1) = 0;
  NS_SCRIPTABLE NS_IMETHOD SetX1(float aX1) = 0;

  /* attribute float y1; */
  NS_SCRIPTABLE NS_IMETHOD GetY1(float *aY1) = 0;
  NS_SCRIPTABLE NS_IMETHOD SetY1(float aY1) = 0;

};

  NS_DEFINE_STATIC_IID_ACCESSOR(nsIDOMSVGPathSegCurvetoQuadraticAbs, NS_IDOMSVGPATHSEGCURVETOQUADRATICABS_IID)

/* Use this macro when declaring classes that implement this interface. */
#define NS_DECL_NSIDOMSVGPATHSEGCURVETOQUADRATICABS \
  NS_SCRIPTABLE NS_IMETHOD GetX(float *aX); \
  NS_SCRIPTABLE NS_IMETHOD SetX(float aX); \
  NS_SCRIPTABLE NS_IMETHOD GetY(float *aY); \
  NS_SCRIPTABLE NS_IMETHOD SetY(float aY); \
  NS_SCRIPTABLE NS_IMETHOD GetX1(float *aX1); \
  NS_SCRIPTABLE NS_IMETHOD SetX1(float aX1); \
  NS_SCRIPTABLE NS_IMETHOD GetY1(float *aY1); \
  NS_SCRIPTABLE NS_IMETHOD SetY1(float aY1); 

/* Use this macro to declare functions that forward the behavior of this interface to another object. */
#define NS_FORWARD_NSIDOMSVGPATHSEGCURVETOQUADRATICABS(_to) \
  NS_SCRIPTABLE NS_IMETHOD GetX(float *aX) { return _to GetX(aX); } \
  NS_SCRIPTABLE NS_IMETHOD SetX(float aX) { return _to SetX(aX); } \
  NS_SCRIPTABLE NS_IMETHOD GetY(float *aY) { return _to GetY(aY); } \
  NS_SCRIPTABLE NS_IMETHOD SetY(float aY) { return _to SetY(aY); } \
  NS_SCRIPTABLE NS_IMETHOD GetX1(float *aX1) { return _to GetX1(aX1); } \
  NS_SCRIPTABLE NS_IMETHOD SetX1(float aX1) { return _to SetX1(aX1); } \
  NS_SCRIPTABLE NS_IMETHOD GetY1(float *aY1) { return _to GetY1(aY1); } \
  NS_SCRIPTABLE NS_IMETHOD SetY1(float aY1) { return _to SetY1(aY1); } 

/* Use this macro to declare functions that forward the behavior of this interface to another object in a safe way. */
#define NS_FORWARD_SAFE_NSIDOMSVGPATHSEGCURVETOQUADRATICABS(_to) \
  NS_SCRIPTABLE NS_IMETHOD GetX(float *aX) { return !_to ? NS_ERROR_NULL_POINTER : _to->GetX(aX); } \
  NS_SCRIPTABLE NS_IMETHOD SetX(float aX) { return !_to ? NS_ERROR_NULL_POINTER : _to->SetX(aX); } \
  NS_SCRIPTABLE NS_IMETHOD GetY(float *aY) { return !_to ? NS_ERROR_NULL_POINTER : _to->GetY(aY); } \
  NS_SCRIPTABLE NS_IMETHOD SetY(float aY) { return !_to ? NS_ERROR_NULL_POINTER : _to->SetY(aY); } \
  NS_SCRIPTABLE NS_IMETHOD GetX1(float *aX1) { return !_to ? NS_ERROR_NULL_POINTER : _to->GetX1(aX1); } \
  NS_SCRIPTABLE NS_IMETHOD SetX1(float aX1) { return !_to ? NS_ERROR_NULL_POINTER : _to->SetX1(aX1); } \
  NS_SCRIPTABLE NS_IMETHOD GetY1(float *aY1) { return !_to ? NS_ERROR_NULL_POINTER : _to->GetY1(aY1); } \
  NS_SCRIPTABLE NS_IMETHOD SetY1(float aY1) { return !_to ? NS_ERROR_NULL_POINTER : _to->SetY1(aY1); } 

#if 0
/* Use the code below as a template for the implementation class for this interface. */

/* Header file */
class nsDOMSVGPathSegCurvetoQuadraticAbs : public nsIDOMSVGPathSegCurvetoQuadraticAbs
{
public:
  NS_DECL_ISUPPORTS
  NS_DECL_NSIDOMSVGPATHSEGCURVETOQUADRATICABS

  nsDOMSVGPathSegCurvetoQuadraticAbs();

private:
  ~nsDOMSVGPathSegCurvetoQuadraticAbs();

protected:
  /* additional members */
};

/* Implementation file */
NS_IMPL_ISUPPORTS1(nsDOMSVGPathSegCurvetoQuadraticAbs, nsIDOMSVGPathSegCurvetoQuadraticAbs)

nsDOMSVGPathSegCurvetoQuadraticAbs::nsDOMSVGPathSegCurvetoQuadraticAbs()
{
  /* member initializers and constructor code */
}

nsDOMSVGPathSegCurvetoQuadraticAbs::~nsDOMSVGPathSegCurvetoQuadraticAbs()
{
  /* destructor code */
}

/* attribute float x; */
NS_IMETHODIMP nsDOMSVGPathSegCurvetoQuadraticAbs::GetX(float *aX)
{
    return NS_ERROR_NOT_IMPLEMENTED;
}
NS_IMETHODIMP nsDOMSVGPathSegCurvetoQuadraticAbs::SetX(float aX)
{
    return NS_ERROR_NOT_IMPLEMENTED;
}

/* attribute float y; */
NS_IMETHODIMP nsDOMSVGPathSegCurvetoQuadraticAbs::GetY(float *aY)
{
    return NS_ERROR_NOT_IMPLEMENTED;
}
NS_IMETHODIMP nsDOMSVGPathSegCurvetoQuadraticAbs::SetY(float aY)
{
    return NS_ERROR_NOT_IMPLEMENTED;
}

/* attribute float x1; */
NS_IMETHODIMP nsDOMSVGPathSegCurvetoQuadraticAbs::GetX1(float *aX1)
{
    return NS_ERROR_NOT_IMPLEMENTED;
}
NS_IMETHODIMP nsDOMSVGPathSegCurvetoQuadraticAbs::SetX1(float aX1)
{
    return NS_ERROR_NOT_IMPLEMENTED;
}

/* attribute float y1; */
NS_IMETHODIMP nsDOMSVGPathSegCurvetoQuadraticAbs::GetY1(float *aY1)
{
    return NS_ERROR_NOT_IMPLEMENTED;
}
NS_IMETHODIMP nsDOMSVGPathSegCurvetoQuadraticAbs::SetY1(float aY1)
{
    return NS_ERROR_NOT_IMPLEMENTED;
}

/* End of implementation class template. */
#endif


/* starting interface:    nsIDOMSVGPathSegCurvetoQuadraticRel */
#define NS_IDOMSVGPATHSEGCURVETOQUADRATICREL_IID_STR "c46eb661-9c05-4d46-9b2a-c2ae5b166060"

#define NS_IDOMSVGPATHSEGCURVETOQUADRATICREL_IID \
  {0xc46eb661, 0x9c05, 0x4d46, \
    { 0x9b, 0x2a, 0xc2, 0xae, 0x5b, 0x16, 0x60, 0x60 }}

class NS_NO_VTABLE NS_SCRIPTABLE nsIDOMSVGPathSegCurvetoQuadraticRel : public nsISupports {
 public: 

  NS_DECLARE_STATIC_IID_ACCESSOR(NS_IDOMSVGPATHSEGCURVETOQUADRATICREL_IID)

  /* attribute float x; */
  NS_SCRIPTABLE NS_IMETHOD GetX(float *aX) = 0;
  NS_SCRIPTABLE NS_IMETHOD SetX(float aX) = 0;

  /* attribute float y; */
  NS_SCRIPTABLE NS_IMETHOD GetY(float *aY) = 0;
  NS_SCRIPTABLE NS_IMETHOD SetY(float aY) = 0;

  /* attribute float x1; */
  NS_SCRIPTABLE NS_IMETHOD GetX1(float *aX1) = 0;
  NS_SCRIPTABLE NS_IMETHOD SetX1(float aX1) = 0;

  /* attribute float y1; */
  NS_SCRIPTABLE NS_IMETHOD GetY1(float *aY1) = 0;
  NS_SCRIPTABLE NS_IMETHOD SetY1(float aY1) = 0;

};

  NS_DEFINE_STATIC_IID_ACCESSOR(nsIDOMSVGPathSegCurvetoQuadraticRel, NS_IDOMSVGPATHSEGCURVETOQUADRATICREL_IID)

/* Use this macro when declaring classes that implement this interface. */
#define NS_DECL_NSIDOMSVGPATHSEGCURVETOQUADRATICREL \
  NS_SCRIPTABLE NS_IMETHOD GetX(float *aX); \
  NS_SCRIPTABLE NS_IMETHOD SetX(float aX); \
  NS_SCRIPTABLE NS_IMETHOD GetY(float *aY); \
  NS_SCRIPTABLE NS_IMETHOD SetY(float aY); \
  NS_SCRIPTABLE NS_IMETHOD GetX1(float *aX1); \
  NS_SCRIPTABLE NS_IMETHOD SetX1(float aX1); \
  NS_SCRIPTABLE NS_IMETHOD GetY1(float *aY1); \
  NS_SCRIPTABLE NS_IMETHOD SetY1(float aY1); 

/* Use this macro to declare functions that forward the behavior of this interface to another object. */
#define NS_FORWARD_NSIDOMSVGPATHSEGCURVETOQUADRATICREL(_to) \
  NS_SCRIPTABLE NS_IMETHOD GetX(float *aX) { return _to GetX(aX); } \
  NS_SCRIPTABLE NS_IMETHOD SetX(float aX) { return _to SetX(aX); } \
  NS_SCRIPTABLE NS_IMETHOD GetY(float *aY) { return _to GetY(aY); } \
  NS_SCRIPTABLE NS_IMETHOD SetY(float aY) { return _to SetY(aY); } \
  NS_SCRIPTABLE NS_IMETHOD GetX1(float *aX1) { return _to GetX1(aX1); } \
  NS_SCRIPTABLE NS_IMETHOD SetX1(float aX1) { return _to SetX1(aX1); } \
  NS_SCRIPTABLE NS_IMETHOD GetY1(float *aY1) { return _to GetY1(aY1); } \
  NS_SCRIPTABLE NS_IMETHOD SetY1(float aY1) { return _to SetY1(aY1); } 

/* Use this macro to declare functions that forward the behavior of this interface to another object in a safe way. */
#define NS_FORWARD_SAFE_NSIDOMSVGPATHSEGCURVETOQUADRATICREL(_to) \
  NS_SCRIPTABLE NS_IMETHOD GetX(float *aX) { return !_to ? NS_ERROR_NULL_POINTER : _to->GetX(aX); } \
  NS_SCRIPTABLE NS_IMETHOD SetX(float aX) { return !_to ? NS_ERROR_NULL_POINTER : _to->SetX(aX); } \
  NS_SCRIPTABLE NS_IMETHOD GetY(float *aY) { return !_to ? NS_ERROR_NULL_POINTER : _to->GetY(aY); } \
  NS_SCRIPTABLE NS_IMETHOD SetY(float aY) { return !_to ? NS_ERROR_NULL_POINTER : _to->SetY(aY); } \
  NS_SCRIPTABLE NS_IMETHOD GetX1(float *aX1) { return !_to ? NS_ERROR_NULL_POINTER : _to->GetX1(aX1); } \
  NS_SCRIPTABLE NS_IMETHOD SetX1(float aX1) { return !_to ? NS_ERROR_NULL_POINTER : _to->SetX1(aX1); } \
  NS_SCRIPTABLE NS_IMETHOD GetY1(float *aY1) { return !_to ? NS_ERROR_NULL_POINTER : _to->GetY1(aY1); } \
  NS_SCRIPTABLE NS_IMETHOD SetY1(float aY1) { return !_to ? NS_ERROR_NULL_POINTER : _to->SetY1(aY1); } 

#if 0
/* Use the code below as a template for the implementation class for this interface. */

/* Header file */
class nsDOMSVGPathSegCurvetoQuadraticRel : public nsIDOMSVGPathSegCurvetoQuadraticRel
{
public:
  NS_DECL_ISUPPORTS
  NS_DECL_NSIDOMSVGPATHSEGCURVETOQUADRATICREL

  nsDOMSVGPathSegCurvetoQuadraticRel();

private:
  ~nsDOMSVGPathSegCurvetoQuadraticRel();

protected:
  /* additional members */
};

/* Implementation file */
NS_IMPL_ISUPPORTS1(nsDOMSVGPathSegCurvetoQuadraticRel, nsIDOMSVGPathSegCurvetoQuadraticRel)

nsDOMSVGPathSegCurvetoQuadraticRel::nsDOMSVGPathSegCurvetoQuadraticRel()
{
  /* member initializers and constructor code */
}

nsDOMSVGPathSegCurvetoQuadraticRel::~nsDOMSVGPathSegCurvetoQuadraticRel()
{
  /* destructor code */
}

/* attribute float x; */
NS_IMETHODIMP nsDOMSVGPathSegCurvetoQuadraticRel::GetX(float *aX)
{
    return NS_ERROR_NOT_IMPLEMENTED;
}
NS_IMETHODIMP nsDOMSVGPathSegCurvetoQuadraticRel::SetX(float aX)
{
    return NS_ERROR_NOT_IMPLEMENTED;
}

/* attribute float y; */
NS_IMETHODIMP nsDOMSVGPathSegCurvetoQuadraticRel::GetY(float *aY)
{
    return NS_ERROR_NOT_IMPLEMENTED;
}
NS_IMETHODIMP nsDOMSVGPathSegCurvetoQuadraticRel::SetY(float aY)
{
    return NS_ERROR_NOT_IMPLEMENTED;
}

/* attribute float x1; */
NS_IMETHODIMP nsDOMSVGPathSegCurvetoQuadraticRel::GetX1(float *aX1)
{
    return NS_ERROR_NOT_IMPLEMENTED;
}
NS_IMETHODIMP nsDOMSVGPathSegCurvetoQuadraticRel::SetX1(float aX1)
{
    return NS_ERROR_NOT_IMPLEMENTED;
}

/* attribute float y1; */
NS_IMETHODIMP nsDOMSVGPathSegCurvetoQuadraticRel::GetY1(float *aY1)
{
    return NS_ERROR_NOT_IMPLEMENTED;
}
NS_IMETHODIMP nsDOMSVGPathSegCurvetoQuadraticRel::SetY1(float aY1)
{
    return NS_ERROR_NOT_IMPLEMENTED;
}

/* End of implementation class template. */
#endif


/* starting interface:    nsIDOMSVGPathSegArcAbs */
#define NS_IDOMSVGPATHSEGARCABS_IID_STR "c9e222e5-31fd-4083-ae1f-fcf013681340"

#define NS_IDOMSVGPATHSEGARCABS_IID \
  {0xc9e222e5, 0x31fd, 0x4083, \
    { 0xae, 0x1f, 0xfc, 0xf0, 0x13, 0x68, 0x13, 0x40 }}

class NS_NO_VTABLE NS_SCRIPTABLE nsIDOMSVGPathSegArcAbs : public nsISupports {
 public: 

  NS_DECLARE_STATIC_IID_ACCESSOR(NS_IDOMSVGPATHSEGARCABS_IID)

  /* attribute float x; */
  NS_SCRIPTABLE NS_IMETHOD GetX(float *aX) = 0;
  NS_SCRIPTABLE NS_IMETHOD SetX(float aX) = 0;

  /* attribute float y; */
  NS_SCRIPTABLE NS_IMETHOD GetY(float *aY) = 0;
  NS_SCRIPTABLE NS_IMETHOD SetY(float aY) = 0;

  /* attribute float r1; */
  NS_SCRIPTABLE NS_IMETHOD GetR1(float *aR1) = 0;
  NS_SCRIPTABLE NS_IMETHOD SetR1(float aR1) = 0;

  /* attribute float r2; */
  NS_SCRIPTABLE NS_IMETHOD GetR2(float *aR2) = 0;
  NS_SCRIPTABLE NS_IMETHOD SetR2(float aR2) = 0;

  /* attribute float angle; */
  NS_SCRIPTABLE NS_IMETHOD GetAngle(float *aAngle) = 0;
  NS_SCRIPTABLE NS_IMETHOD SetAngle(float aAngle) = 0;

  /* attribute boolean largeArcFlag; */
  NS_SCRIPTABLE NS_IMETHOD GetLargeArcFlag(PRBool *aLargeArcFlag) = 0;
  NS_SCRIPTABLE NS_IMETHOD SetLargeArcFlag(PRBool aLargeArcFlag) = 0;

  /* attribute boolean sweepFlag; */
  NS_SCRIPTABLE NS_IMETHOD GetSweepFlag(PRBool *aSweepFlag) = 0;
  NS_SCRIPTABLE NS_IMETHOD SetSweepFlag(PRBool aSweepFlag) = 0;

};

  NS_DEFINE_STATIC_IID_ACCESSOR(nsIDOMSVGPathSegArcAbs, NS_IDOMSVGPATHSEGARCABS_IID)

/* Use this macro when declaring classes that implement this interface. */
#define NS_DECL_NSIDOMSVGPATHSEGARCABS \
  NS_SCRIPTABLE NS_IMETHOD GetX(float *aX); \
  NS_SCRIPTABLE NS_IMETHOD SetX(float aX); \
  NS_SCRIPTABLE NS_IMETHOD GetY(float *aY); \
  NS_SCRIPTABLE NS_IMETHOD SetY(float aY); \
  NS_SCRIPTABLE NS_IMETHOD GetR1(float *aR1); \
  NS_SCRIPTABLE NS_IMETHOD SetR1(float aR1); \
  NS_SCRIPTABLE NS_IMETHOD GetR2(float *aR2); \
  NS_SCRIPTABLE NS_IMETHOD SetR2(float aR2); \
  NS_SCRIPTABLE NS_IMETHOD GetAngle(float *aAngle); \
  NS_SCRIPTABLE NS_IMETHOD SetAngle(float aAngle); \
  NS_SCRIPTABLE NS_IMETHOD GetLargeArcFlag(PRBool *aLargeArcFlag); \
  NS_SCRIPTABLE NS_IMETHOD SetLargeArcFlag(PRBool aLargeArcFlag); \
  NS_SCRIPTABLE NS_IMETHOD GetSweepFlag(PRBool *aSweepFlag); \
  NS_SCRIPTABLE NS_IMETHOD SetSweepFlag(PRBool aSweepFlag); 

/* Use this macro to declare functions that forward the behavior of this interface to another object. */
#define NS_FORWARD_NSIDOMSVGPATHSEGARCABS(_to) \
  NS_SCRIPTABLE NS_IMETHOD GetX(float *aX) { return _to GetX(aX); } \
  NS_SCRIPTABLE NS_IMETHOD SetX(float aX) { return _to SetX(aX); } \
  NS_SCRIPTABLE NS_IMETHOD GetY(float *aY) { return _to GetY(aY); } \
  NS_SCRIPTABLE NS_IMETHOD SetY(float aY) { return _to SetY(aY); } \
  NS_SCRIPTABLE NS_IMETHOD GetR1(float *aR1) { return _to GetR1(aR1); } \
  NS_SCRIPTABLE NS_IMETHOD SetR1(float aR1) { return _to SetR1(aR1); } \
  NS_SCRIPTABLE NS_IMETHOD GetR2(float *aR2) { return _to GetR2(aR2); } \
  NS_SCRIPTABLE NS_IMETHOD SetR2(float aR2) { return _to SetR2(aR2); } \
  NS_SCRIPTABLE NS_IMETHOD GetAngle(float *aAngle) { return _to GetAngle(aAngle); } \
  NS_SCRIPTABLE NS_IMETHOD SetAngle(float aAngle) { return _to SetAngle(aAngle); } \
  NS_SCRIPTABLE NS_IMETHOD GetLargeArcFlag(PRBool *aLargeArcFlag) { return _to GetLargeArcFlag(aLargeArcFlag); } \
  NS_SCRIPTABLE NS_IMETHOD SetLargeArcFlag(PRBool aLargeArcFlag) { return _to SetLargeArcFlag(aLargeArcFlag); } \
  NS_SCRIPTABLE NS_IMETHOD GetSweepFlag(PRBool *aSweepFlag) { return _to GetSweepFlag(aSweepFlag); } \
  NS_SCRIPTABLE NS_IMETHOD SetSweepFlag(PRBool aSweepFlag) { return _to SetSweepFlag(aSweepFlag); } 

/* Use this macro to declare functions that forward the behavior of this interface to another object in a safe way. */
#define NS_FORWARD_SAFE_NSIDOMSVGPATHSEGARCABS(_to) \
  NS_SCRIPTABLE NS_IMETHOD GetX(float *aX) { return !_to ? NS_ERROR_NULL_POINTER : _to->GetX(aX); } \
  NS_SCRIPTABLE NS_IMETHOD SetX(float aX) { return !_to ? NS_ERROR_NULL_POINTER : _to->SetX(aX); } \
  NS_SCRIPTABLE NS_IMETHOD GetY(float *aY) { return !_to ? NS_ERROR_NULL_POINTER : _to->GetY(aY); } \
  NS_SCRIPTABLE NS_IMETHOD SetY(float aY) { return !_to ? NS_ERROR_NULL_POINTER : _to->SetY(aY); } \
  NS_SCRIPTABLE NS_IMETHOD GetR1(float *aR1) { return !_to ? NS_ERROR_NULL_POINTER : _to->GetR1(aR1); } \
  NS_SCRIPTABLE NS_IMETHOD SetR1(float aR1) { return !_to ? NS_ERROR_NULL_POINTER : _to->SetR1(aR1); } \
  NS_SCRIPTABLE NS_IMETHOD GetR2(float *aR2) { return !_to ? NS_ERROR_NULL_POINTER : _to->GetR2(aR2); } \
  NS_SCRIPTABLE NS_IMETHOD SetR2(float aR2) { return !_to ? NS_ERROR_NULL_POINTER : _to->SetR2(aR2); } \
  NS_SCRIPTABLE NS_IMETHOD GetAngle(float *aAngle) { return !_to ? NS_ERROR_NULL_POINTER : _to->GetAngle(aAngle); } \
  NS_SCRIPTABLE NS_IMETHOD SetAngle(float aAngle) { return !_to ? NS_ERROR_NULL_POINTER : _to->SetAngle(aAngle); } \
  NS_SCRIPTABLE NS_IMETHOD GetLargeArcFlag(PRBool *aLargeArcFlag) { return !_to ? NS_ERROR_NULL_POINTER : _to->GetLargeArcFlag(aLargeArcFlag); } \
  NS_SCRIPTABLE NS_IMETHOD SetLargeArcFlag(PRBool aLargeArcFlag) { return !_to ? NS_ERROR_NULL_POINTER : _to->SetLargeArcFlag(aLargeArcFlag); } \
  NS_SCRIPTABLE NS_IMETHOD GetSweepFlag(PRBool *aSweepFlag) { return !_to ? NS_ERROR_NULL_POINTER : _to->GetSweepFlag(aSweepFlag); } \
  NS_SCRIPTABLE NS_IMETHOD SetSweepFlag(PRBool aSweepFlag) { return !_to ? NS_ERROR_NULL_POINTER : _to->SetSweepFlag(aSweepFlag); } 

#if 0
/* Use the code below as a template for the implementation class for this interface. */

/* Header file */
class nsDOMSVGPathSegArcAbs : public nsIDOMSVGPathSegArcAbs
{
public:
  NS_DECL_ISUPPORTS
  NS_DECL_NSIDOMSVGPATHSEGARCABS

  nsDOMSVGPathSegArcAbs();

private:
  ~nsDOMSVGPathSegArcAbs();

protected:
  /* additional members */
};

/* Implementation file */
NS_IMPL_ISUPPORTS1(nsDOMSVGPathSegArcAbs, nsIDOMSVGPathSegArcAbs)

nsDOMSVGPathSegArcAbs::nsDOMSVGPathSegArcAbs()
{
  /* member initializers and constructor code */
}

nsDOMSVGPathSegArcAbs::~nsDOMSVGPathSegArcAbs()
{
  /* destructor code */
}

/* attribute float x; */
NS_IMETHODIMP nsDOMSVGPathSegArcAbs::GetX(float *aX)
{
    return NS_ERROR_NOT_IMPLEMENTED;
}
NS_IMETHODIMP nsDOMSVGPathSegArcAbs::SetX(float aX)
{
    return NS_ERROR_NOT_IMPLEMENTED;
}

/* attribute float y; */
NS_IMETHODIMP nsDOMSVGPathSegArcAbs::GetY(float *aY)
{
    return NS_ERROR_NOT_IMPLEMENTED;
}
NS_IMETHODIMP nsDOMSVGPathSegArcAbs::SetY(float aY)
{
    return NS_ERROR_NOT_IMPLEMENTED;
}

/* attribute float r1; */
NS_IMETHODIMP nsDOMSVGPathSegArcAbs::GetR1(float *aR1)
{
    return NS_ERROR_NOT_IMPLEMENTED;
}
NS_IMETHODIMP nsDOMSVGPathSegArcAbs::SetR1(float aR1)
{
    return NS_ERROR_NOT_IMPLEMENTED;
}

/* attribute float r2; */
NS_IMETHODIMP nsDOMSVGPathSegArcAbs::GetR2(float *aR2)
{
    return NS_ERROR_NOT_IMPLEMENTED;
}
NS_IMETHODIMP nsDOMSVGPathSegArcAbs::SetR2(float aR2)
{
    return NS_ERROR_NOT_IMPLEMENTED;
}

/* attribute float angle; */
NS_IMETHODIMP nsDOMSVGPathSegArcAbs::GetAngle(float *aAngle)
{
    return NS_ERROR_NOT_IMPLEMENTED;
}
NS_IMETHODIMP nsDOMSVGPathSegArcAbs::SetAngle(float aAngle)
{
    return NS_ERROR_NOT_IMPLEMENTED;
}

/* attribute boolean largeArcFlag; */
NS_IMETHODIMP nsDOMSVGPathSegArcAbs::GetLargeArcFlag(PRBool *aLargeArcFlag)
{
    return NS_ERROR_NOT_IMPLEMENTED;
}
NS_IMETHODIMP nsDOMSVGPathSegArcAbs::SetLargeArcFlag(PRBool aLargeArcFlag)
{
    return NS_ERROR_NOT_IMPLEMENTED;
}

/* attribute boolean sweepFlag; */
NS_IMETHODIMP nsDOMSVGPathSegArcAbs::GetSweepFlag(PRBool *aSweepFlag)
{
    return NS_ERROR_NOT_IMPLEMENTED;
}
NS_IMETHODIMP nsDOMSVGPathSegArcAbs::SetSweepFlag(PRBool aSweepFlag)
{
    return NS_ERROR_NOT_IMPLEMENTED;
}

/* End of implementation class template. */
#endif


/* starting interface:    nsIDOMSVGPathSegArcRel */
#define NS_IDOMSVGPATHSEGARCREL_IID_STR "49d0360d-bb66-4ab9-b9b0-f49b93398595"

#define NS_IDOMSVGPATHSEGARCREL_IID \
  {0x49d0360d, 0xbb66, 0x4ab9, \
    { 0xb9, 0xb0, 0xf4, 0x9b, 0x93, 0x39, 0x85, 0x95 }}

class NS_NO_VTABLE NS_SCRIPTABLE nsIDOMSVGPathSegArcRel : public nsISupports {
 public: 

  NS_DECLARE_STATIC_IID_ACCESSOR(NS_IDOMSVGPATHSEGARCREL_IID)

  /* attribute float x; */
  NS_SCRIPTABLE NS_IMETHOD GetX(float *aX) = 0;
  NS_SCRIPTABLE NS_IMETHOD SetX(float aX) = 0;

  /* attribute float y; */
  NS_SCRIPTABLE NS_IMETHOD GetY(float *aY) = 0;
  NS_SCRIPTABLE NS_IMETHOD SetY(float aY) = 0;

  /* attribute float r1; */
  NS_SCRIPTABLE NS_IMETHOD GetR1(float *aR1) = 0;
  NS_SCRIPTABLE NS_IMETHOD SetR1(float aR1) = 0;

  /* attribute float r2; */
  NS_SCRIPTABLE NS_IMETHOD GetR2(float *aR2) = 0;
  NS_SCRIPTABLE NS_IMETHOD SetR2(float aR2) = 0;

  /* attribute float angle; */
  NS_SCRIPTABLE NS_IMETHOD GetAngle(float *aAngle) = 0;
  NS_SCRIPTABLE NS_IMETHOD SetAngle(float aAngle) = 0;

  /* attribute boolean largeArcFlag; */
  NS_SCRIPTABLE NS_IMETHOD GetLargeArcFlag(PRBool *aLargeArcFlag) = 0;
  NS_SCRIPTABLE NS_IMETHOD SetLargeArcFlag(PRBool aLargeArcFlag) = 0;

  /* attribute boolean sweepFlag; */
  NS_SCRIPTABLE NS_IMETHOD GetSweepFlag(PRBool *aSweepFlag) = 0;
  NS_SCRIPTABLE NS_IMETHOD SetSweepFlag(PRBool aSweepFlag) = 0;

};

  NS_DEFINE_STATIC_IID_ACCESSOR(nsIDOMSVGPathSegArcRel, NS_IDOMSVGPATHSEGARCREL_IID)

/* Use this macro when declaring classes that implement this interface. */
#define NS_DECL_NSIDOMSVGPATHSEGARCREL \
  NS_SCRIPTABLE NS_IMETHOD GetX(float *aX); \
  NS_SCRIPTABLE NS_IMETHOD SetX(float aX); \
  NS_SCRIPTABLE NS_IMETHOD GetY(float *aY); \
  NS_SCRIPTABLE NS_IMETHOD SetY(float aY); \
  NS_SCRIPTABLE NS_IMETHOD GetR1(float *aR1); \
  NS_SCRIPTABLE NS_IMETHOD SetR1(float aR1); \
  NS_SCRIPTABLE NS_IMETHOD GetR2(float *aR2); \
  NS_SCRIPTABLE NS_IMETHOD SetR2(float aR2); \
  NS_SCRIPTABLE NS_IMETHOD GetAngle(float *aAngle); \
  NS_SCRIPTABLE NS_IMETHOD SetAngle(float aAngle); \
  NS_SCRIPTABLE NS_IMETHOD GetLargeArcFlag(PRBool *aLargeArcFlag); \
  NS_SCRIPTABLE NS_IMETHOD SetLargeArcFlag(PRBool aLargeArcFlag); \
  NS_SCRIPTABLE NS_IMETHOD GetSweepFlag(PRBool *aSweepFlag); \
  NS_SCRIPTABLE NS_IMETHOD SetSweepFlag(PRBool aSweepFlag); 

/* Use this macro to declare functions that forward the behavior of this interface to another object. */
#define NS_FORWARD_NSIDOMSVGPATHSEGARCREL(_to) \
  NS_SCRIPTABLE NS_IMETHOD GetX(float *aX) { return _to GetX(aX); } \
  NS_SCRIPTABLE NS_IMETHOD SetX(float aX) { return _to SetX(aX); } \
  NS_SCRIPTABLE NS_IMETHOD GetY(float *aY) { return _to GetY(aY); } \
  NS_SCRIPTABLE NS_IMETHOD SetY(float aY) { return _to SetY(aY); } \
  NS_SCRIPTABLE NS_IMETHOD GetR1(float *aR1) { return _to GetR1(aR1); } \
  NS_SCRIPTABLE NS_IMETHOD SetR1(float aR1) { return _to SetR1(aR1); } \
  NS_SCRIPTABLE NS_IMETHOD GetR2(float *aR2) { return _to GetR2(aR2); } \
  NS_SCRIPTABLE NS_IMETHOD SetR2(float aR2) { return _to SetR2(aR2); } \
  NS_SCRIPTABLE NS_IMETHOD GetAngle(float *aAngle) { return _to GetAngle(aAngle); } \
  NS_SCRIPTABLE NS_IMETHOD SetAngle(float aAngle) { return _to SetAngle(aAngle); } \
  NS_SCRIPTABLE NS_IMETHOD GetLargeArcFlag(PRBool *aLargeArcFlag) { return _to GetLargeArcFlag(aLargeArcFlag); } \
  NS_SCRIPTABLE NS_IMETHOD SetLargeArcFlag(PRBool aLargeArcFlag) { return _to SetLargeArcFlag(aLargeArcFlag); } \
  NS_SCRIPTABLE NS_IMETHOD GetSweepFlag(PRBool *aSweepFlag) { return _to GetSweepFlag(aSweepFlag); } \
  NS_SCRIPTABLE NS_IMETHOD SetSweepFlag(PRBool aSweepFlag) { return _to SetSweepFlag(aSweepFlag); } 

/* Use this macro to declare functions that forward the behavior of this interface to another object in a safe way. */
#define NS_FORWARD_SAFE_NSIDOMSVGPATHSEGARCREL(_to) \
  NS_SCRIPTABLE NS_IMETHOD GetX(float *aX) { return !_to ? NS_ERROR_NULL_POINTER : _to->GetX(aX); } \
  NS_SCRIPTABLE NS_IMETHOD SetX(float aX) { return !_to ? NS_ERROR_NULL_POINTER : _to->SetX(aX); } \
  NS_SCRIPTABLE NS_IMETHOD GetY(float *aY) { return !_to ? NS_ERROR_NULL_POINTER : _to->GetY(aY); } \
  NS_SCRIPTABLE NS_IMETHOD SetY(float aY) { return !_to ? NS_ERROR_NULL_POINTER : _to->SetY(aY); } \
  NS_SCRIPTABLE NS_IMETHOD GetR1(float *aR1) { return !_to ? NS_ERROR_NULL_POINTER : _to->GetR1(aR1); } \
  NS_SCRIPTABLE NS_IMETHOD SetR1(float aR1) { return !_to ? NS_ERROR_NULL_POINTER : _to->SetR1(aR1); } \
  NS_SCRIPTABLE NS_IMETHOD GetR2(float *aR2) { return !_to ? NS_ERROR_NULL_POINTER : _to->GetR2(aR2); } \
  NS_SCRIPTABLE NS_IMETHOD SetR2(float aR2) { return !_to ? NS_ERROR_NULL_POINTER : _to->SetR2(aR2); } \
  NS_SCRIPTABLE NS_IMETHOD GetAngle(float *aAngle) { return !_to ? NS_ERROR_NULL_POINTER : _to->GetAngle(aAngle); } \
  NS_SCRIPTABLE NS_IMETHOD SetAngle(float aAngle) { return !_to ? NS_ERROR_NULL_POINTER : _to->SetAngle(aAngle); } \
  NS_SCRIPTABLE NS_IMETHOD GetLargeArcFlag(PRBool *aLargeArcFlag) { return !_to ? NS_ERROR_NULL_POINTER : _to->GetLargeArcFlag(aLargeArcFlag); } \
  NS_SCRIPTABLE NS_IMETHOD SetLargeArcFlag(PRBool aLargeArcFlag) { return !_to ? NS_ERROR_NULL_POINTER : _to->SetLargeArcFlag(aLargeArcFlag); } \
  NS_SCRIPTABLE NS_IMETHOD GetSweepFlag(PRBool *aSweepFlag) { return !_to ? NS_ERROR_NULL_POINTER : _to->GetSweepFlag(aSweepFlag); } \
  NS_SCRIPTABLE NS_IMETHOD SetSweepFlag(PRBool aSweepFlag) { return !_to ? NS_ERROR_NULL_POINTER : _to->SetSweepFlag(aSweepFlag); } 

#if 0
/* Use the code below as a template for the implementation class for this interface. */

/* Header file */
class nsDOMSVGPathSegArcRel : public nsIDOMSVGPathSegArcRel
{
public:
  NS_DECL_ISUPPORTS
  NS_DECL_NSIDOMSVGPATHSEGARCREL

  nsDOMSVGPathSegArcRel();

private:
  ~nsDOMSVGPathSegArcRel();

protected:
  /* additional members */
};

/* Implementation file */
NS_IMPL_ISUPPORTS1(nsDOMSVGPathSegArcRel, nsIDOMSVGPathSegArcRel)

nsDOMSVGPathSegArcRel::nsDOMSVGPathSegArcRel()
{
  /* member initializers and constructor code */
}

nsDOMSVGPathSegArcRel::~nsDOMSVGPathSegArcRel()
{
  /* destructor code */
}

/* attribute float x; */
NS_IMETHODIMP nsDOMSVGPathSegArcRel::GetX(float *aX)
{
    return NS_ERROR_NOT_IMPLEMENTED;
}
NS_IMETHODIMP nsDOMSVGPathSegArcRel::SetX(float aX)
{
    return NS_ERROR_NOT_IMPLEMENTED;
}

/* attribute float y; */
NS_IMETHODIMP nsDOMSVGPathSegArcRel::GetY(float *aY)
{
    return NS_ERROR_NOT_IMPLEMENTED;
}
NS_IMETHODIMP nsDOMSVGPathSegArcRel::SetY(float aY)
{
    return NS_ERROR_NOT_IMPLEMENTED;
}

/* attribute float r1; */
NS_IMETHODIMP nsDOMSVGPathSegArcRel::GetR1(float *aR1)
{
    return NS_ERROR_NOT_IMPLEMENTED;
}
NS_IMETHODIMP nsDOMSVGPathSegArcRel::SetR1(float aR1)
{
    return NS_ERROR_NOT_IMPLEMENTED;
}

/* attribute float r2; */
NS_IMETHODIMP nsDOMSVGPathSegArcRel::GetR2(float *aR2)
{
    return NS_ERROR_NOT_IMPLEMENTED;
}
NS_IMETHODIMP nsDOMSVGPathSegArcRel::SetR2(float aR2)
{
    return NS_ERROR_NOT_IMPLEMENTED;
}

/* attribute float angle; */
NS_IMETHODIMP nsDOMSVGPathSegArcRel::GetAngle(float *aAngle)
{
    return NS_ERROR_NOT_IMPLEMENTED;
}
NS_IMETHODIMP nsDOMSVGPathSegArcRel::SetAngle(float aAngle)
{
    return NS_ERROR_NOT_IMPLEMENTED;
}

/* attribute boolean largeArcFlag; */
NS_IMETHODIMP nsDOMSVGPathSegArcRel::GetLargeArcFlag(PRBool *aLargeArcFlag)
{
    return NS_ERROR_NOT_IMPLEMENTED;
}
NS_IMETHODIMP nsDOMSVGPathSegArcRel::SetLargeArcFlag(PRBool aLargeArcFlag)
{
    return NS_ERROR_NOT_IMPLEMENTED;
}

/* attribute boolean sweepFlag; */
NS_IMETHODIMP nsDOMSVGPathSegArcRel::GetSweepFlag(PRBool *aSweepFlag)
{
    return NS_ERROR_NOT_IMPLEMENTED;
}
NS_IMETHODIMP nsDOMSVGPathSegArcRel::SetSweepFlag(PRBool aSweepFlag)
{
    return NS_ERROR_NOT_IMPLEMENTED;
}

/* End of implementation class template. */
#endif


/* starting interface:    nsIDOMSVGPathSegLinetoHorizontalAbs */
#define NS_IDOMSVGPATHSEGLINETOHORIZONTALABS_IID_STR "4a54a4d2-edef-4e19-9600-2330311000f4"

#define NS_IDOMSVGPATHSEGLINETOHORIZONTALABS_IID \
  {0x4a54a4d2, 0xedef, 0x4e19, \
    { 0x96, 0x00, 0x23, 0x30, 0x31, 0x10, 0x00, 0xf4 }}

class NS_NO_VTABLE NS_SCRIPTABLE nsIDOMSVGPathSegLinetoHorizontalAbs : public nsISupports {
 public: 

  NS_DECLARE_STATIC_IID_ACCESSOR(NS_IDOMSVGPATHSEGLINETOHORIZONTALABS_IID)

  /* attribute float x; */
  NS_SCRIPTABLE NS_IMETHOD GetX(float *aX) = 0;
  NS_SCRIPTABLE NS_IMETHOD SetX(float aX) = 0;

};

  NS_DEFINE_STATIC_IID_ACCESSOR(nsIDOMSVGPathSegLinetoHorizontalAbs, NS_IDOMSVGPATHSEGLINETOHORIZONTALABS_IID)

/* Use this macro when declaring classes that implement this interface. */
#define NS_DECL_NSIDOMSVGPATHSEGLINETOHORIZONTALABS \
  NS_SCRIPTABLE NS_IMETHOD GetX(float *aX); \
  NS_SCRIPTABLE NS_IMETHOD SetX(float aX); 

/* Use this macro to declare functions that forward the behavior of this interface to another object. */
#define NS_FORWARD_NSIDOMSVGPATHSEGLINETOHORIZONTALABS(_to) \
  NS_SCRIPTABLE NS_IMETHOD GetX(float *aX) { return _to GetX(aX); } \
  NS_SCRIPTABLE NS_IMETHOD SetX(float aX) { return _to SetX(aX); } 

/* Use this macro to declare functions that forward the behavior of this interface to another object in a safe way. */
#define NS_FORWARD_SAFE_NSIDOMSVGPATHSEGLINETOHORIZONTALABS(_to) \
  NS_SCRIPTABLE NS_IMETHOD GetX(float *aX) { return !_to ? NS_ERROR_NULL_POINTER : _to->GetX(aX); } \
  NS_SCRIPTABLE NS_IMETHOD SetX(float aX) { return !_to ? NS_ERROR_NULL_POINTER : _to->SetX(aX); } 

#if 0
/* Use the code below as a template for the implementation class for this interface. */

/* Header file */
class nsDOMSVGPathSegLinetoHorizontalAbs : public nsIDOMSVGPathSegLinetoHorizontalAbs
{
public:
  NS_DECL_ISUPPORTS
  NS_DECL_NSIDOMSVGPATHSEGLINETOHORIZONTALABS

  nsDOMSVGPathSegLinetoHorizontalAbs();

private:
  ~nsDOMSVGPathSegLinetoHorizontalAbs();

protected:
  /* additional members */
};

/* Implementation file */
NS_IMPL_ISUPPORTS1(nsDOMSVGPathSegLinetoHorizontalAbs, nsIDOMSVGPathSegLinetoHorizontalAbs)

nsDOMSVGPathSegLinetoHorizontalAbs::nsDOMSVGPathSegLinetoHorizontalAbs()
{
  /* member initializers and constructor code */
}

nsDOMSVGPathSegLinetoHorizontalAbs::~nsDOMSVGPathSegLinetoHorizontalAbs()
{
  /* destructor code */
}

/* attribute float x; */
NS_IMETHODIMP nsDOMSVGPathSegLinetoHorizontalAbs::GetX(float *aX)
{
    return NS_ERROR_NOT_IMPLEMENTED;
}
NS_IMETHODIMP nsDOMSVGPathSegLinetoHorizontalAbs::SetX(float aX)
{
    return NS_ERROR_NOT_IMPLEMENTED;
}

/* End of implementation class template. */
#endif


/* starting interface:    nsIDOMSVGPathSegLinetoHorizontalRel */
#define NS_IDOMSVGPATHSEGLINETOHORIZONTALREL_IID_STR "8693268c-5180-43fd-acc3-5b9c09f43386"

#define NS_IDOMSVGPATHSEGLINETOHORIZONTALREL_IID \
  {0x8693268c, 0x5180, 0x43fd, \
    { 0xac, 0xc3, 0x5b, 0x9c, 0x09, 0xf4, 0x33, 0x86 }}

class NS_NO_VTABLE NS_SCRIPTABLE nsIDOMSVGPathSegLinetoHorizontalRel : public nsISupports {
 public: 

  NS_DECLARE_STATIC_IID_ACCESSOR(NS_IDOMSVGPATHSEGLINETOHORIZONTALREL_IID)

  /* attribute float x; */
  NS_SCRIPTABLE NS_IMETHOD GetX(float *aX) = 0;
  NS_SCRIPTABLE NS_IMETHOD SetX(float aX) = 0;

};

  NS_DEFINE_STATIC_IID_ACCESSOR(nsIDOMSVGPathSegLinetoHorizontalRel, NS_IDOMSVGPATHSEGLINETOHORIZONTALREL_IID)

/* Use this macro when declaring classes that implement this interface. */
#define NS_DECL_NSIDOMSVGPATHSEGLINETOHORIZONTALREL \
  NS_SCRIPTABLE NS_IMETHOD GetX(float *aX); \
  NS_SCRIPTABLE NS_IMETHOD SetX(float aX); 

/* Use this macro to declare functions that forward the behavior of this interface to another object. */
#define NS_FORWARD_NSIDOMSVGPATHSEGLINETOHORIZONTALREL(_to) \
  NS_SCRIPTABLE NS_IMETHOD GetX(float *aX) { return _to GetX(aX); } \
  NS_SCRIPTABLE NS_IMETHOD SetX(float aX) { return _to SetX(aX); } 

/* Use this macro to declare functions that forward the behavior of this interface to another object in a safe way. */
#define NS_FORWARD_SAFE_NSIDOMSVGPATHSEGLINETOHORIZONTALREL(_to) \
  NS_SCRIPTABLE NS_IMETHOD GetX(float *aX) { return !_to ? NS_ERROR_NULL_POINTER : _to->GetX(aX); } \
  NS_SCRIPTABLE NS_IMETHOD SetX(float aX) { return !_to ? NS_ERROR_NULL_POINTER : _to->SetX(aX); } 

#if 0
/* Use the code below as a template for the implementation class for this interface. */

/* Header file */
class nsDOMSVGPathSegLinetoHorizontalRel : public nsIDOMSVGPathSegLinetoHorizontalRel
{
public:
  NS_DECL_ISUPPORTS
  NS_DECL_NSIDOMSVGPATHSEGLINETOHORIZONTALREL

  nsDOMSVGPathSegLinetoHorizontalRel();

private:
  ~nsDOMSVGPathSegLinetoHorizontalRel();

protected:
  /* additional members */
};

/* Implementation file */
NS_IMPL_ISUPPORTS1(nsDOMSVGPathSegLinetoHorizontalRel, nsIDOMSVGPathSegLinetoHorizontalRel)

nsDOMSVGPathSegLinetoHorizontalRel::nsDOMSVGPathSegLinetoHorizontalRel()
{
  /* member initializers and constructor code */
}

nsDOMSVGPathSegLinetoHorizontalRel::~nsDOMSVGPathSegLinetoHorizontalRel()
{
  /* destructor code */
}

/* attribute float x; */
NS_IMETHODIMP nsDOMSVGPathSegLinetoHorizontalRel::GetX(float *aX)
{
    return NS_ERROR_NOT_IMPLEMENTED;
}
NS_IMETHODIMP nsDOMSVGPathSegLinetoHorizontalRel::SetX(float aX)
{
    return NS_ERROR_NOT_IMPLEMENTED;
}

/* End of implementation class template. */
#endif


/* starting interface:    nsIDOMSVGPathSegLinetoVerticalAbs */
#define NS_IDOMSVGPATHSEGLINETOVERTICALABS_IID_STR "fd5ffb7b-7279-4c09-abfd-b733dc872e80"

#define NS_IDOMSVGPATHSEGLINETOVERTICALABS_IID \
  {0xfd5ffb7b, 0x7279, 0x4c09, \
    { 0xab, 0xfd, 0xb7, 0x33, 0xdc, 0x87, 0x2e, 0x80 }}

class NS_NO_VTABLE NS_SCRIPTABLE nsIDOMSVGPathSegLinetoVerticalAbs : public nsISupports {
 public: 

  NS_DECLARE_STATIC_IID_ACCESSOR(NS_IDOMSVGPATHSEGLINETOVERTICALABS_IID)

  /* attribute float y; */
  NS_SCRIPTABLE NS_IMETHOD GetY(float *aY) = 0;
  NS_SCRIPTABLE NS_IMETHOD SetY(float aY) = 0;

};

  NS_DEFINE_STATIC_IID_ACCESSOR(nsIDOMSVGPathSegLinetoVerticalAbs, NS_IDOMSVGPATHSEGLINETOVERTICALABS_IID)

/* Use this macro when declaring classes that implement this interface. */
#define NS_DECL_NSIDOMSVGPATHSEGLINETOVERTICALABS \
  NS_SCRIPTABLE NS_IMETHOD GetY(float *aY); \
  NS_SCRIPTABLE NS_IMETHOD SetY(float aY); 

/* Use this macro to declare functions that forward the behavior of this interface to another object. */
#define NS_FORWARD_NSIDOMSVGPATHSEGLINETOVERTICALABS(_to) \
  NS_SCRIPTABLE NS_IMETHOD GetY(float *aY) { return _to GetY(aY); } \
  NS_SCRIPTABLE NS_IMETHOD SetY(float aY) { return _to SetY(aY); } 

/* Use this macro to declare functions that forward the behavior of this interface to another object in a safe way. */
#define NS_FORWARD_SAFE_NSIDOMSVGPATHSEGLINETOVERTICALABS(_to) \
  NS_SCRIPTABLE NS_IMETHOD GetY(float *aY) { return !_to ? NS_ERROR_NULL_POINTER : _to->GetY(aY); } \
  NS_SCRIPTABLE NS_IMETHOD SetY(float aY) { return !_to ? NS_ERROR_NULL_POINTER : _to->SetY(aY); } 

#if 0
/* Use the code below as a template for the implementation class for this interface. */

/* Header file */
class nsDOMSVGPathSegLinetoVerticalAbs : public nsIDOMSVGPathSegLinetoVerticalAbs
{
public:
  NS_DECL_ISUPPORTS
  NS_DECL_NSIDOMSVGPATHSEGLINETOVERTICALABS

  nsDOMSVGPathSegLinetoVerticalAbs();

private:
  ~nsDOMSVGPathSegLinetoVerticalAbs();

protected:
  /* additional members */
};

/* Implementation file */
NS_IMPL_ISUPPORTS1(nsDOMSVGPathSegLinetoVerticalAbs, nsIDOMSVGPathSegLinetoVerticalAbs)

nsDOMSVGPathSegLinetoVerticalAbs::nsDOMSVGPathSegLinetoVerticalAbs()
{
  /* member initializers and constructor code */
}

nsDOMSVGPathSegLinetoVerticalAbs::~nsDOMSVGPathSegLinetoVerticalAbs()
{
  /* destructor code */
}

/* attribute float y; */
NS_IMETHODIMP nsDOMSVGPathSegLinetoVerticalAbs::GetY(float *aY)
{
    return NS_ERROR_NOT_IMPLEMENTED;
}
NS_IMETHODIMP nsDOMSVGPathSegLinetoVerticalAbs::SetY(float aY)
{
    return NS_ERROR_NOT_IMPLEMENTED;
}

/* End of implementation class template. */
#endif


/* starting interface:    nsIDOMSVGPathSegLinetoVerticalRel */
#define NS_IDOMSVGPATHSEGLINETOVERTICALREL_IID_STR "d3ef2128-8de3-4aac-a6b4-13c7563119a6"

#define NS_IDOMSVGPATHSEGLINETOVERTICALREL_IID \
  {0xd3ef2128, 0x8de3, 0x4aac, \
    { 0xa6, 0xb4, 0x13, 0xc7, 0x56, 0x31, 0x19, 0xa6 }}

class NS_NO_VTABLE NS_SCRIPTABLE nsIDOMSVGPathSegLinetoVerticalRel : public nsISupports {
 public: 

  NS_DECLARE_STATIC_IID_ACCESSOR(NS_IDOMSVGPATHSEGLINETOVERTICALREL_IID)

  /* attribute float y; */
  NS_SCRIPTABLE NS_IMETHOD GetY(float *aY) = 0;
  NS_SCRIPTABLE NS_IMETHOD SetY(float aY) = 0;

};

  NS_DEFINE_STATIC_IID_ACCESSOR(nsIDOMSVGPathSegLinetoVerticalRel, NS_IDOMSVGPATHSEGLINETOVERTICALREL_IID)

/* Use this macro when declaring classes that implement this interface. */
#define NS_DECL_NSIDOMSVGPATHSEGLINETOVERTICALREL \
  NS_SCRIPTABLE NS_IMETHOD GetY(float *aY); \
  NS_SCRIPTABLE NS_IMETHOD SetY(float aY); 

/* Use this macro to declare functions that forward the behavior of this interface to another object. */
#define NS_FORWARD_NSIDOMSVGPATHSEGLINETOVERTICALREL(_to) \
  NS_SCRIPTABLE NS_IMETHOD GetY(float *aY) { return _to GetY(aY); } \
  NS_SCRIPTABLE NS_IMETHOD SetY(float aY) { return _to SetY(aY); } 

/* Use this macro to declare functions that forward the behavior of this interface to another object in a safe way. */
#define NS_FORWARD_SAFE_NSIDOMSVGPATHSEGLINETOVERTICALREL(_to) \
  NS_SCRIPTABLE NS_IMETHOD GetY(float *aY) { return !_to ? NS_ERROR_NULL_POINTER : _to->GetY(aY); } \
  NS_SCRIPTABLE NS_IMETHOD SetY(float aY) { return !_to ? NS_ERROR_NULL_POINTER : _to->SetY(aY); } 

#if 0
/* Use the code below as a template for the implementation class for this interface. */

/* Header file */
class nsDOMSVGPathSegLinetoVerticalRel : public nsIDOMSVGPathSegLinetoVerticalRel
{
public:
  NS_DECL_ISUPPORTS
  NS_DECL_NSIDOMSVGPATHSEGLINETOVERTICALREL

  nsDOMSVGPathSegLinetoVerticalRel();

private:
  ~nsDOMSVGPathSegLinetoVerticalRel();

protected:
  /* additional members */
};

/* Implementation file */
NS_IMPL_ISUPPORTS1(nsDOMSVGPathSegLinetoVerticalRel, nsIDOMSVGPathSegLinetoVerticalRel)

nsDOMSVGPathSegLinetoVerticalRel::nsDOMSVGPathSegLinetoVerticalRel()
{
  /* member initializers and constructor code */
}

nsDOMSVGPathSegLinetoVerticalRel::~nsDOMSVGPathSegLinetoVerticalRel()
{
  /* destructor code */
}

/* attribute float y; */
NS_IMETHODIMP nsDOMSVGPathSegLinetoVerticalRel::GetY(float *aY)
{
    return NS_ERROR_NOT_IMPLEMENTED;
}
NS_IMETHODIMP nsDOMSVGPathSegLinetoVerticalRel::SetY(float aY)
{
    return NS_ERROR_NOT_IMPLEMENTED;
}

/* End of implementation class template. */
#endif


/* starting interface:    nsIDOMSVGPathSegCurvetoCubicSmoothAbs */
#define NS_IDOMSVGPATHSEGCURVETOCUBICSMOOTHABS_IID_STR "5fa8fea8-bdd1-4315-ac44-a39b3ff347b5"

#define NS_IDOMSVGPATHSEGCURVETOCUBICSMOOTHABS_IID \
  {0x5fa8fea8, 0xbdd1, 0x4315, \
    { 0xac, 0x44, 0xa3, 0x9b, 0x3f, 0xf3, 0x47, 0xb5 }}

class NS_NO_VTABLE NS_SCRIPTABLE nsIDOMSVGPathSegCurvetoCubicSmoothAbs : public nsISupports {
 public: 

  NS_DECLARE_STATIC_IID_ACCESSOR(NS_IDOMSVGPATHSEGCURVETOCUBICSMOOTHABS_IID)

  /* attribute float x; */
  NS_SCRIPTABLE NS_IMETHOD GetX(float *aX) = 0;
  NS_SCRIPTABLE NS_IMETHOD SetX(float aX) = 0;

  /* attribute float y; */
  NS_SCRIPTABLE NS_IMETHOD GetY(float *aY) = 0;
  NS_SCRIPTABLE NS_IMETHOD SetY(float aY) = 0;

  /* attribute float x2; */
  NS_SCRIPTABLE NS_IMETHOD GetX2(float *aX2) = 0;
  NS_SCRIPTABLE NS_IMETHOD SetX2(float aX2) = 0;

  /* attribute float y2; */
  NS_SCRIPTABLE NS_IMETHOD GetY2(float *aY2) = 0;
  NS_SCRIPTABLE NS_IMETHOD SetY2(float aY2) = 0;

};

  NS_DEFINE_STATIC_IID_ACCESSOR(nsIDOMSVGPathSegCurvetoCubicSmoothAbs, NS_IDOMSVGPATHSEGCURVETOCUBICSMOOTHABS_IID)

/* Use this macro when declaring classes that implement this interface. */
#define NS_DECL_NSIDOMSVGPATHSEGCURVETOCUBICSMOOTHABS \
  NS_SCRIPTABLE NS_IMETHOD GetX(float *aX); \
  NS_SCRIPTABLE NS_IMETHOD SetX(float aX); \
  NS_SCRIPTABLE NS_IMETHOD GetY(float *aY); \
  NS_SCRIPTABLE NS_IMETHOD SetY(float aY); \
  NS_SCRIPTABLE NS_IMETHOD GetX2(float *aX2); \
  NS_SCRIPTABLE NS_IMETHOD SetX2(float aX2); \
  NS_SCRIPTABLE NS_IMETHOD GetY2(float *aY2); \
  NS_SCRIPTABLE NS_IMETHOD SetY2(float aY2); 

/* Use this macro to declare functions that forward the behavior of this interface to another object. */
#define NS_FORWARD_NSIDOMSVGPATHSEGCURVETOCUBICSMOOTHABS(_to) \
  NS_SCRIPTABLE NS_IMETHOD GetX(float *aX) { return _to GetX(aX); } \
  NS_SCRIPTABLE NS_IMETHOD SetX(float aX) { return _to SetX(aX); } \
  NS_SCRIPTABLE NS_IMETHOD GetY(float *aY) { return _to GetY(aY); } \
  NS_SCRIPTABLE NS_IMETHOD SetY(float aY) { return _to SetY(aY); } \
  NS_SCRIPTABLE NS_IMETHOD GetX2(float *aX2) { return _to GetX2(aX2); } \
  NS_SCRIPTABLE NS_IMETHOD SetX2(float aX2) { return _to SetX2(aX2); } \
  NS_SCRIPTABLE NS_IMETHOD GetY2(float *aY2) { return _to GetY2(aY2); } \
  NS_SCRIPTABLE NS_IMETHOD SetY2(float aY2) { return _to SetY2(aY2); } 

/* Use this macro to declare functions that forward the behavior of this interface to another object in a safe way. */
#define NS_FORWARD_SAFE_NSIDOMSVGPATHSEGCURVETOCUBICSMOOTHABS(_to) \
  NS_SCRIPTABLE NS_IMETHOD GetX(float *aX) { return !_to ? NS_ERROR_NULL_POINTER : _to->GetX(aX); } \
  NS_SCRIPTABLE NS_IMETHOD SetX(float aX) { return !_to ? NS_ERROR_NULL_POINTER : _to->SetX(aX); } \
  NS_SCRIPTABLE NS_IMETHOD GetY(float *aY) { return !_to ? NS_ERROR_NULL_POINTER : _to->GetY(aY); } \
  NS_SCRIPTABLE NS_IMETHOD SetY(float aY) { return !_to ? NS_ERROR_NULL_POINTER : _to->SetY(aY); } \
  NS_SCRIPTABLE NS_IMETHOD GetX2(float *aX2) { return !_to ? NS_ERROR_NULL_POINTER : _to->GetX2(aX2); } \
  NS_SCRIPTABLE NS_IMETHOD SetX2(float aX2) { return !_to ? NS_ERROR_NULL_POINTER : _to->SetX2(aX2); } \
  NS_SCRIPTABLE NS_IMETHOD GetY2(float *aY2) { return !_to ? NS_ERROR_NULL_POINTER : _to->GetY2(aY2); } \
  NS_SCRIPTABLE NS_IMETHOD SetY2(float aY2) { return !_to ? NS_ERROR_NULL_POINTER : _to->SetY2(aY2); } 

#if 0
/* Use the code below as a template for the implementation class for this interface. */

/* Header file */
class nsDOMSVGPathSegCurvetoCubicSmoothAbs : public nsIDOMSVGPathSegCurvetoCubicSmoothAbs
{
public:
  NS_DECL_ISUPPORTS
  NS_DECL_NSIDOMSVGPATHSEGCURVETOCUBICSMOOTHABS

  nsDOMSVGPathSegCurvetoCubicSmoothAbs();

private:
  ~nsDOMSVGPathSegCurvetoCubicSmoothAbs();

protected:
  /* additional members */
};

/* Implementation file */
NS_IMPL_ISUPPORTS1(nsDOMSVGPathSegCurvetoCubicSmoothAbs, nsIDOMSVGPathSegCurvetoCubicSmoothAbs)

nsDOMSVGPathSegCurvetoCubicSmoothAbs::nsDOMSVGPathSegCurvetoCubicSmoothAbs()
{
  /* member initializers and constructor code */
}

nsDOMSVGPathSegCurvetoCubicSmoothAbs::~nsDOMSVGPathSegCurvetoCubicSmoothAbs()
{
  /* destructor code */
}

/* attribute float x; */
NS_IMETHODIMP nsDOMSVGPathSegCurvetoCubicSmoothAbs::GetX(float *aX)
{
    return NS_ERROR_NOT_IMPLEMENTED;
}
NS_IMETHODIMP nsDOMSVGPathSegCurvetoCubicSmoothAbs::SetX(float aX)
{
    return NS_ERROR_NOT_IMPLEMENTED;
}

/* attribute float y; */
NS_IMETHODIMP nsDOMSVGPathSegCurvetoCubicSmoothAbs::GetY(float *aY)
{
    return NS_ERROR_NOT_IMPLEMENTED;
}
NS_IMETHODIMP nsDOMSVGPathSegCurvetoCubicSmoothAbs::SetY(float aY)
{
    return NS_ERROR_NOT_IMPLEMENTED;
}

/* attribute float x2; */
NS_IMETHODIMP nsDOMSVGPathSegCurvetoCubicSmoothAbs::GetX2(float *aX2)
{
    return NS_ERROR_NOT_IMPLEMENTED;
}
NS_IMETHODIMP nsDOMSVGPathSegCurvetoCubicSmoothAbs::SetX2(float aX2)
{
    return NS_ERROR_NOT_IMPLEMENTED;
}

/* attribute float y2; */
NS_IMETHODIMP nsDOMSVGPathSegCurvetoCubicSmoothAbs::GetY2(float *aY2)
{
    return NS_ERROR_NOT_IMPLEMENTED;
}
NS_IMETHODIMP nsDOMSVGPathSegCurvetoCubicSmoothAbs::SetY2(float aY2)
{
    return NS_ERROR_NOT_IMPLEMENTED;
}

/* End of implementation class template. */
#endif


/* starting interface:    nsIDOMSVGPathSegCurvetoCubicSmoothRel */
#define NS_IDOMSVGPATHSEGCURVETOCUBICSMOOTHREL_IID_STR "dd5b4b00-edaa-493a-b477-bbc2576b4a98"

#define NS_IDOMSVGPATHSEGCURVETOCUBICSMOOTHREL_IID \
  {0xdd5b4b00, 0xedaa, 0x493a, \
    { 0xb4, 0x77, 0xbb, 0xc2, 0x57, 0x6b, 0x4a, 0x98 }}

class NS_NO_VTABLE NS_SCRIPTABLE nsIDOMSVGPathSegCurvetoCubicSmoothRel : public nsISupports {
 public: 

  NS_DECLARE_STATIC_IID_ACCESSOR(NS_IDOMSVGPATHSEGCURVETOCUBICSMOOTHREL_IID)

  /* attribute float x; */
  NS_SCRIPTABLE NS_IMETHOD GetX(float *aX) = 0;
  NS_SCRIPTABLE NS_IMETHOD SetX(float aX) = 0;

  /* attribute float y; */
  NS_SCRIPTABLE NS_IMETHOD GetY(float *aY) = 0;
  NS_SCRIPTABLE NS_IMETHOD SetY(float aY) = 0;

  /* attribute float x2; */
  NS_SCRIPTABLE NS_IMETHOD GetX2(float *aX2) = 0;
  NS_SCRIPTABLE NS_IMETHOD SetX2(float aX2) = 0;

  /* attribute float y2; */
  NS_SCRIPTABLE NS_IMETHOD GetY2(float *aY2) = 0;
  NS_SCRIPTABLE NS_IMETHOD SetY2(float aY2) = 0;

};

  NS_DEFINE_STATIC_IID_ACCESSOR(nsIDOMSVGPathSegCurvetoCubicSmoothRel, NS_IDOMSVGPATHSEGCURVETOCUBICSMOOTHREL_IID)

/* Use this macro when declaring classes that implement this interface. */
#define NS_DECL_NSIDOMSVGPATHSEGCURVETOCUBICSMOOTHREL \
  NS_SCRIPTABLE NS_IMETHOD GetX(float *aX); \
  NS_SCRIPTABLE NS_IMETHOD SetX(float aX); \
  NS_SCRIPTABLE NS_IMETHOD GetY(float *aY); \
  NS_SCRIPTABLE NS_IMETHOD SetY(float aY); \
  NS_SCRIPTABLE NS_IMETHOD GetX2(float *aX2); \
  NS_SCRIPTABLE NS_IMETHOD SetX2(float aX2); \
  NS_SCRIPTABLE NS_IMETHOD GetY2(float *aY2); \
  NS_SCRIPTABLE NS_IMETHOD SetY2(float aY2); 

/* Use this macro to declare functions that forward the behavior of this interface to another object. */
#define NS_FORWARD_NSIDOMSVGPATHSEGCURVETOCUBICSMOOTHREL(_to) \
  NS_SCRIPTABLE NS_IMETHOD GetX(float *aX) { return _to GetX(aX); } \
  NS_SCRIPTABLE NS_IMETHOD SetX(float aX) { return _to SetX(aX); } \
  NS_SCRIPTABLE NS_IMETHOD GetY(float *aY) { return _to GetY(aY); } \
  NS_SCRIPTABLE NS_IMETHOD SetY(float aY) { return _to SetY(aY); } \
  NS_SCRIPTABLE NS_IMETHOD GetX2(float *aX2) { return _to GetX2(aX2); } \
  NS_SCRIPTABLE NS_IMETHOD SetX2(float aX2) { return _to SetX2(aX2); } \
  NS_SCRIPTABLE NS_IMETHOD GetY2(float *aY2) { return _to GetY2(aY2); } \
  NS_SCRIPTABLE NS_IMETHOD SetY2(float aY2) { return _to SetY2(aY2); } 

/* Use this macro to declare functions that forward the behavior of this interface to another object in a safe way. */
#define NS_FORWARD_SAFE_NSIDOMSVGPATHSEGCURVETOCUBICSMOOTHREL(_to) \
  NS_SCRIPTABLE NS_IMETHOD GetX(float *aX) { return !_to ? NS_ERROR_NULL_POINTER : _to->GetX(aX); } \
  NS_SCRIPTABLE NS_IMETHOD SetX(float aX) { return !_to ? NS_ERROR_NULL_POINTER : _to->SetX(aX); } \
  NS_SCRIPTABLE NS_IMETHOD GetY(float *aY) { return !_to ? NS_ERROR_NULL_POINTER : _to->GetY(aY); } \
  NS_SCRIPTABLE NS_IMETHOD SetY(float aY) { return !_to ? NS_ERROR_NULL_POINTER : _to->SetY(aY); } \
  NS_SCRIPTABLE NS_IMETHOD GetX2(float *aX2) { return !_to ? NS_ERROR_NULL_POINTER : _to->GetX2(aX2); } \
  NS_SCRIPTABLE NS_IMETHOD SetX2(float aX2) { return !_to ? NS_ERROR_NULL_POINTER : _to->SetX2(aX2); } \
  NS_SCRIPTABLE NS_IMETHOD GetY2(float *aY2) { return !_to ? NS_ERROR_NULL_POINTER : _to->GetY2(aY2); } \
  NS_SCRIPTABLE NS_IMETHOD SetY2(float aY2) { return !_to ? NS_ERROR_NULL_POINTER : _to->SetY2(aY2); } 

#if 0
/* Use the code below as a template for the implementation class for this interface. */

/* Header file */
class nsDOMSVGPathSegCurvetoCubicSmoothRel : public nsIDOMSVGPathSegCurvetoCubicSmoothRel
{
public:
  NS_DECL_ISUPPORTS
  NS_DECL_NSIDOMSVGPATHSEGCURVETOCUBICSMOOTHREL

  nsDOMSVGPathSegCurvetoCubicSmoothRel();

private:
  ~nsDOMSVGPathSegCurvetoCubicSmoothRel();

protected:
  /* additional members */
};

/* Implementation file */
NS_IMPL_ISUPPORTS1(nsDOMSVGPathSegCurvetoCubicSmoothRel, nsIDOMSVGPathSegCurvetoCubicSmoothRel)

nsDOMSVGPathSegCurvetoCubicSmoothRel::nsDOMSVGPathSegCurvetoCubicSmoothRel()
{
  /* member initializers and constructor code */
}

nsDOMSVGPathSegCurvetoCubicSmoothRel::~nsDOMSVGPathSegCurvetoCubicSmoothRel()
{
  /* destructor code */
}

/* attribute float x; */
NS_IMETHODIMP nsDOMSVGPathSegCurvetoCubicSmoothRel::GetX(float *aX)
{
    return NS_ERROR_NOT_IMPLEMENTED;
}
NS_IMETHODIMP nsDOMSVGPathSegCurvetoCubicSmoothRel::SetX(float aX)
{
    return NS_ERROR_NOT_IMPLEMENTED;
}

/* attribute float y; */
NS_IMETHODIMP nsDOMSVGPathSegCurvetoCubicSmoothRel::GetY(float *aY)
{
    return NS_ERROR_NOT_IMPLEMENTED;
}
NS_IMETHODIMP nsDOMSVGPathSegCurvetoCubicSmoothRel::SetY(float aY)
{
    return NS_ERROR_NOT_IMPLEMENTED;
}

/* attribute float x2; */
NS_IMETHODIMP nsDOMSVGPathSegCurvetoCubicSmoothRel::GetX2(float *aX2)
{
    return NS_ERROR_NOT_IMPLEMENTED;
}
NS_IMETHODIMP nsDOMSVGPathSegCurvetoCubicSmoothRel::SetX2(float aX2)
{
    return NS_ERROR_NOT_IMPLEMENTED;
}

/* attribute float y2; */
NS_IMETHODIMP nsDOMSVGPathSegCurvetoCubicSmoothRel::GetY2(float *aY2)
{
    return NS_ERROR_NOT_IMPLEMENTED;
}
NS_IMETHODIMP nsDOMSVGPathSegCurvetoCubicSmoothRel::SetY2(float aY2)
{
    return NS_ERROR_NOT_IMPLEMENTED;
}

/* End of implementation class template. */
#endif


/* starting interface:    nsIDOMSVGPathSegCurvetoQuadraticSmoothAbs */
#define NS_IDOMSVGPATHSEGCURVETOQUADRATICSMOOTHABS_IID_STR "ff5bbb58-b49a-450f-b91b-e50585c34b3d"

#define NS_IDOMSVGPATHSEGCURVETOQUADRATICSMOOTHABS_IID \
  {0xff5bbb58, 0xb49a, 0x450f, \
    { 0xb9, 0x1b, 0xe5, 0x05, 0x85, 0xc3, 0x4b, 0x3d }}

class NS_NO_VTABLE NS_SCRIPTABLE nsIDOMSVGPathSegCurvetoQuadraticSmoothAbs : public nsISupports {
 public: 

  NS_DECLARE_STATIC_IID_ACCESSOR(NS_IDOMSVGPATHSEGCURVETOQUADRATICSMOOTHABS_IID)

  /* attribute float x; */
  NS_SCRIPTABLE NS_IMETHOD GetX(float *aX) = 0;
  NS_SCRIPTABLE NS_IMETHOD SetX(float aX) = 0;

  /* attribute float y; */
  NS_SCRIPTABLE NS_IMETHOD GetY(float *aY) = 0;
  NS_SCRIPTABLE NS_IMETHOD SetY(float aY) = 0;

};

  NS_DEFINE_STATIC_IID_ACCESSOR(nsIDOMSVGPathSegCurvetoQuadraticSmoothAbs, NS_IDOMSVGPATHSEGCURVETOQUADRATICSMOOTHABS_IID)

/* Use this macro when declaring classes that implement this interface. */
#define NS_DECL_NSIDOMSVGPATHSEGCURVETOQUADRATICSMOOTHABS \
  NS_SCRIPTABLE NS_IMETHOD GetX(float *aX); \
  NS_SCRIPTABLE NS_IMETHOD SetX(float aX); \
  NS_SCRIPTABLE NS_IMETHOD GetY(float *aY); \
  NS_SCRIPTABLE NS_IMETHOD SetY(float aY); 

/* Use this macro to declare functions that forward the behavior of this interface to another object. */
#define NS_FORWARD_NSIDOMSVGPATHSEGCURVETOQUADRATICSMOOTHABS(_to) \
  NS_SCRIPTABLE NS_IMETHOD GetX(float *aX) { return _to GetX(aX); } \
  NS_SCRIPTABLE NS_IMETHOD SetX(float aX) { return _to SetX(aX); } \
  NS_SCRIPTABLE NS_IMETHOD GetY(float *aY) { return _to GetY(aY); } \
  NS_SCRIPTABLE NS_IMETHOD SetY(float aY) { return _to SetY(aY); } 

/* Use this macro to declare functions that forward the behavior of this interface to another object in a safe way. */
#define NS_FORWARD_SAFE_NSIDOMSVGPATHSEGCURVETOQUADRATICSMOOTHABS(_to) \
  NS_SCRIPTABLE NS_IMETHOD GetX(float *aX) { return !_to ? NS_ERROR_NULL_POINTER : _to->GetX(aX); } \
  NS_SCRIPTABLE NS_IMETHOD SetX(float aX) { return !_to ? NS_ERROR_NULL_POINTER : _to->SetX(aX); } \
  NS_SCRIPTABLE NS_IMETHOD GetY(float *aY) { return !_to ? NS_ERROR_NULL_POINTER : _to->GetY(aY); } \
  NS_SCRIPTABLE NS_IMETHOD SetY(float aY) { return !_to ? NS_ERROR_NULL_POINTER : _to->SetY(aY); } 

#if 0
/* Use the code below as a template for the implementation class for this interface. */

/* Header file */
class nsDOMSVGPathSegCurvetoQuadraticSmoothAbs : public nsIDOMSVGPathSegCurvetoQuadraticSmoothAbs
{
public:
  NS_DECL_ISUPPORTS
  NS_DECL_NSIDOMSVGPATHSEGCURVETOQUADRATICSMOOTHABS

  nsDOMSVGPathSegCurvetoQuadraticSmoothAbs();

private:
  ~nsDOMSVGPathSegCurvetoQuadraticSmoothAbs();

protected:
  /* additional members */
};

/* Implementation file */
NS_IMPL_ISUPPORTS1(nsDOMSVGPathSegCurvetoQuadraticSmoothAbs, nsIDOMSVGPathSegCurvetoQuadraticSmoothAbs)

nsDOMSVGPathSegCurvetoQuadraticSmoothAbs::nsDOMSVGPathSegCurvetoQuadraticSmoothAbs()
{
  /* member initializers and constructor code */
}

nsDOMSVGPathSegCurvetoQuadraticSmoothAbs::~nsDOMSVGPathSegCurvetoQuadraticSmoothAbs()
{
  /* destructor code */
}

/* attribute float x; */
NS_IMETHODIMP nsDOMSVGPathSegCurvetoQuadraticSmoothAbs::GetX(float *aX)
{
    return NS_ERROR_NOT_IMPLEMENTED;
}
NS_IMETHODIMP nsDOMSVGPathSegCurvetoQuadraticSmoothAbs::SetX(float aX)
{
    return NS_ERROR_NOT_IMPLEMENTED;
}

/* attribute float y; */
NS_IMETHODIMP nsDOMSVGPathSegCurvetoQuadraticSmoothAbs::GetY(float *aY)
{
    return NS_ERROR_NOT_IMPLEMENTED;
}
NS_IMETHODIMP nsDOMSVGPathSegCurvetoQuadraticSmoothAbs::SetY(float aY)
{
    return NS_ERROR_NOT_IMPLEMENTED;
}

/* End of implementation class template. */
#endif


/* starting interface:    nsIDOMSVGPathSegCurvetoQuadraticSmoothRel */
#define NS_IDOMSVGPATHSEGCURVETOQUADRATICSMOOTHREL_IID_STR "ac0b2007-04e4-4e70-a0e0-294f374b29c4"

#define NS_IDOMSVGPATHSEGCURVETOQUADRATICSMOOTHREL_IID \
  {0xac0b2007, 0x04e4, 0x4e70, \
    { 0xa0, 0xe0, 0x29, 0x4f, 0x37, 0x4b, 0x29, 0xc4 }}

class NS_NO_VTABLE NS_SCRIPTABLE nsIDOMSVGPathSegCurvetoQuadraticSmoothRel : public nsISupports {
 public: 

  NS_DECLARE_STATIC_IID_ACCESSOR(NS_IDOMSVGPATHSEGCURVETOQUADRATICSMOOTHREL_IID)

  /* attribute float x; */
  NS_SCRIPTABLE NS_IMETHOD GetX(float *aX) = 0;
  NS_SCRIPTABLE NS_IMETHOD SetX(float aX) = 0;

  /* attribute float y; */
  NS_SCRIPTABLE NS_IMETHOD GetY(float *aY) = 0;
  NS_SCRIPTABLE NS_IMETHOD SetY(float aY) = 0;

};

  NS_DEFINE_STATIC_IID_ACCESSOR(nsIDOMSVGPathSegCurvetoQuadraticSmoothRel, NS_IDOMSVGPATHSEGCURVETOQUADRATICSMOOTHREL_IID)

/* Use this macro when declaring classes that implement this interface. */
#define NS_DECL_NSIDOMSVGPATHSEGCURVETOQUADRATICSMOOTHREL \
  NS_SCRIPTABLE NS_IMETHOD GetX(float *aX); \
  NS_SCRIPTABLE NS_IMETHOD SetX(float aX); \
  NS_SCRIPTABLE NS_IMETHOD GetY(float *aY); \
  NS_SCRIPTABLE NS_IMETHOD SetY(float aY); 

/* Use this macro to declare functions that forward the behavior of this interface to another object. */
#define NS_FORWARD_NSIDOMSVGPATHSEGCURVETOQUADRATICSMOOTHREL(_to) \
  NS_SCRIPTABLE NS_IMETHOD GetX(float *aX) { return _to GetX(aX); } \
  NS_SCRIPTABLE NS_IMETHOD SetX(float aX) { return _to SetX(aX); } \
  NS_SCRIPTABLE NS_IMETHOD GetY(float *aY) { return _to GetY(aY); } \
  NS_SCRIPTABLE NS_IMETHOD SetY(float aY) { return _to SetY(aY); } 

/* Use this macro to declare functions that forward the behavior of this interface to another object in a safe way. */
#define NS_FORWARD_SAFE_NSIDOMSVGPATHSEGCURVETOQUADRATICSMOOTHREL(_to) \
  NS_SCRIPTABLE NS_IMETHOD GetX(float *aX) { return !_to ? NS_ERROR_NULL_POINTER : _to->GetX(aX); } \
  NS_SCRIPTABLE NS_IMETHOD SetX(float aX) { return !_to ? NS_ERROR_NULL_POINTER : _to->SetX(aX); } \
  NS_SCRIPTABLE NS_IMETHOD GetY(float *aY) { return !_to ? NS_ERROR_NULL_POINTER : _to->GetY(aY); } \
  NS_SCRIPTABLE NS_IMETHOD SetY(float aY) { return !_to ? NS_ERROR_NULL_POINTER : _to->SetY(aY); } 

#if 0
/* Use the code below as a template for the implementation class for this interface. */

/* Header file */
class nsDOMSVGPathSegCurvetoQuadraticSmoothRel : public nsIDOMSVGPathSegCurvetoQuadraticSmoothRel
{
public:
  NS_DECL_ISUPPORTS
  NS_DECL_NSIDOMSVGPATHSEGCURVETOQUADRATICSMOOTHREL

  nsDOMSVGPathSegCurvetoQuadraticSmoothRel();

private:
  ~nsDOMSVGPathSegCurvetoQuadraticSmoothRel();

protected:
  /* additional members */
};

/* Implementation file */
NS_IMPL_ISUPPORTS1(nsDOMSVGPathSegCurvetoQuadraticSmoothRel, nsIDOMSVGPathSegCurvetoQuadraticSmoothRel)

nsDOMSVGPathSegCurvetoQuadraticSmoothRel::nsDOMSVGPathSegCurvetoQuadraticSmoothRel()
{
  /* member initializers and constructor code */
}

nsDOMSVGPathSegCurvetoQuadraticSmoothRel::~nsDOMSVGPathSegCurvetoQuadraticSmoothRel()
{
  /* destructor code */
}

/* attribute float x; */
NS_IMETHODIMP nsDOMSVGPathSegCurvetoQuadraticSmoothRel::GetX(float *aX)
{
    return NS_ERROR_NOT_IMPLEMENTED;
}
NS_IMETHODIMP nsDOMSVGPathSegCurvetoQuadraticSmoothRel::SetX(float aX)
{
    return NS_ERROR_NOT_IMPLEMENTED;
}

/* attribute float y; */
NS_IMETHODIMP nsDOMSVGPathSegCurvetoQuadraticSmoothRel::GetY(float *aY)
{
    return NS_ERROR_NOT_IMPLEMENTED;
}
NS_IMETHODIMP nsDOMSVGPathSegCurvetoQuadraticSmoothRel::SetY(float aY)
{
    return NS_ERROR_NOT_IMPLEMENTED;
}

/* End of implementation class template. */
#endif


#endif /* __gen_nsIDOMSVGPathSeg_h__ */
