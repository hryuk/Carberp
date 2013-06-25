/*
 * DO NOT EDIT.  THIS FILE IS GENERATED FROM e:/builds/moz2_slave/mozilla-1.9.1-win32-xulrunner/build/dom/public/idl/svg/nsIDOMSVGTextContentElement.idl
 */

#ifndef __gen_nsIDOMSVGTextContentElement_h__
#define __gen_nsIDOMSVGTextContentElement_h__


#ifndef __gen_nsIDOMSVGElement_h__
#include "nsIDOMSVGElement.h"
#endif

/* For IDL files that don't want to include root IDL files. */
#ifndef NS_NO_VTABLE
#define NS_NO_VTABLE
#endif
class nsIDOMSVGAnimatedLength; /* forward declaration */

class nsIDOMSVGAnimatedEnumeration; /* forward declaration */

class nsIDOMSVGPoint; /* forward declaration */

class nsIDOMSVGRect; /* forward declaration */


/* starting interface:    nsIDOMSVGTextContentElement */
#define NS_IDOMSVGTEXTCONTENTELEMENT_IID_STR "87ad94bc-07c9-412b-b2d8-de245a2e84a5"

#define NS_IDOMSVGTEXTCONTENTELEMENT_IID \
  {0x87ad94bc, 0x07c9, 0x412b, \
    { 0xb2, 0xd8, 0xde, 0x24, 0x5a, 0x2e, 0x84, 0xa5 }}

class NS_NO_VTABLE NS_SCRIPTABLE nsIDOMSVGTextContentElement : public nsIDOMSVGElement {
 public: 

  NS_DECLARE_STATIC_IID_ACCESSOR(NS_IDOMSVGTEXTCONTENTELEMENT_IID)

  enum { LENGTHADJUST_UNKNOWN = 0U };

  enum { LENGTHADJUST_SPACING = 1U };

  enum { LENGTHADJUST_SPACINGANDGLYPHS = 2U };

  /* readonly attribute nsIDOMSVGAnimatedLength textLength; */
  NS_SCRIPTABLE NS_IMETHOD GetTextLength(nsIDOMSVGAnimatedLength * *aTextLength) = 0;

  /* readonly attribute nsIDOMSVGAnimatedEnumeration lengthAdjust; */
  NS_SCRIPTABLE NS_IMETHOD GetLengthAdjust(nsIDOMSVGAnimatedEnumeration * *aLengthAdjust) = 0;

  /* long getNumberOfChars (); */
  NS_SCRIPTABLE NS_IMETHOD GetNumberOfChars(PRInt32 *_retval NS_OUTPARAM) = 0;

  /* float getComputedTextLength (); */
  NS_SCRIPTABLE NS_IMETHOD GetComputedTextLength(float *_retval NS_OUTPARAM) = 0;

  /* float getSubStringLength (in unsigned long charnum, in unsigned long nchars); */
  NS_SCRIPTABLE NS_IMETHOD GetSubStringLength(PRUint32 charnum, PRUint32 nchars, float *_retval NS_OUTPARAM) = 0;

  /* nsIDOMSVGPoint getStartPositionOfChar (in unsigned long charnum); */
  NS_SCRIPTABLE NS_IMETHOD GetStartPositionOfChar(PRUint32 charnum, nsIDOMSVGPoint **_retval NS_OUTPARAM) = 0;

  /* nsIDOMSVGPoint getEndPositionOfChar (in unsigned long charnum); */
  NS_SCRIPTABLE NS_IMETHOD GetEndPositionOfChar(PRUint32 charnum, nsIDOMSVGPoint **_retval NS_OUTPARAM) = 0;

  /* nsIDOMSVGRect getExtentOfChar (in unsigned long charnum); */
  NS_SCRIPTABLE NS_IMETHOD GetExtentOfChar(PRUint32 charnum, nsIDOMSVGRect **_retval NS_OUTPARAM) = 0;

  /* float getRotationOfChar (in unsigned long charnum); */
  NS_SCRIPTABLE NS_IMETHOD GetRotationOfChar(PRUint32 charnum, float *_retval NS_OUTPARAM) = 0;

  /* long getCharNumAtPosition (in nsIDOMSVGPoint point); */
  NS_SCRIPTABLE NS_IMETHOD GetCharNumAtPosition(nsIDOMSVGPoint *point, PRInt32 *_retval NS_OUTPARAM) = 0;

  /* void selectSubString (in unsigned long charnum, in unsigned long nchars); */
  NS_SCRIPTABLE NS_IMETHOD SelectSubString(PRUint32 charnum, PRUint32 nchars) = 0;

};

  NS_DEFINE_STATIC_IID_ACCESSOR(nsIDOMSVGTextContentElement, NS_IDOMSVGTEXTCONTENTELEMENT_IID)

/* Use this macro when declaring classes that implement this interface. */
#define NS_DECL_NSIDOMSVGTEXTCONTENTELEMENT \
  NS_SCRIPTABLE NS_IMETHOD GetTextLength(nsIDOMSVGAnimatedLength * *aTextLength); \
  NS_SCRIPTABLE NS_IMETHOD GetLengthAdjust(nsIDOMSVGAnimatedEnumeration * *aLengthAdjust); \
  NS_SCRIPTABLE NS_IMETHOD GetNumberOfChars(PRInt32 *_retval NS_OUTPARAM); \
  NS_SCRIPTABLE NS_IMETHOD GetComputedTextLength(float *_retval NS_OUTPARAM); \
  NS_SCRIPTABLE NS_IMETHOD GetSubStringLength(PRUint32 charnum, PRUint32 nchars, float *_retval NS_OUTPARAM); \
  NS_SCRIPTABLE NS_IMETHOD GetStartPositionOfChar(PRUint32 charnum, nsIDOMSVGPoint **_retval NS_OUTPARAM); \
  NS_SCRIPTABLE NS_IMETHOD GetEndPositionOfChar(PRUint32 charnum, nsIDOMSVGPoint **_retval NS_OUTPARAM); \
  NS_SCRIPTABLE NS_IMETHOD GetExtentOfChar(PRUint32 charnum, nsIDOMSVGRect **_retval NS_OUTPARAM); \
  NS_SCRIPTABLE NS_IMETHOD GetRotationOfChar(PRUint32 charnum, float *_retval NS_OUTPARAM); \
  NS_SCRIPTABLE NS_IMETHOD GetCharNumAtPosition(nsIDOMSVGPoint *point, PRInt32 *_retval NS_OUTPARAM); \
  NS_SCRIPTABLE NS_IMETHOD SelectSubString(PRUint32 charnum, PRUint32 nchars); 

/* Use this macro to declare functions that forward the behavior of this interface to another object. */
#define NS_FORWARD_NSIDOMSVGTEXTCONTENTELEMENT(_to) \
  NS_SCRIPTABLE NS_IMETHOD GetTextLength(nsIDOMSVGAnimatedLength * *aTextLength) { return _to GetTextLength(aTextLength); } \
  NS_SCRIPTABLE NS_IMETHOD GetLengthAdjust(nsIDOMSVGAnimatedEnumeration * *aLengthAdjust) { return _to GetLengthAdjust(aLengthAdjust); } \
  NS_SCRIPTABLE NS_IMETHOD GetNumberOfChars(PRInt32 *_retval NS_OUTPARAM) { return _to GetNumberOfChars(_retval); } \
  NS_SCRIPTABLE NS_IMETHOD GetComputedTextLength(float *_retval NS_OUTPARAM) { return _to GetComputedTextLength(_retval); } \
  NS_SCRIPTABLE NS_IMETHOD GetSubStringLength(PRUint32 charnum, PRUint32 nchars, float *_retval NS_OUTPARAM) { return _to GetSubStringLength(charnum, nchars, _retval); } \
  NS_SCRIPTABLE NS_IMETHOD GetStartPositionOfChar(PRUint32 charnum, nsIDOMSVGPoint **_retval NS_OUTPARAM) { return _to GetStartPositionOfChar(charnum, _retval); } \
  NS_SCRIPTABLE NS_IMETHOD GetEndPositionOfChar(PRUint32 charnum, nsIDOMSVGPoint **_retval NS_OUTPARAM) { return _to GetEndPositionOfChar(charnum, _retval); } \
  NS_SCRIPTABLE NS_IMETHOD GetExtentOfChar(PRUint32 charnum, nsIDOMSVGRect **_retval NS_OUTPARAM) { return _to GetExtentOfChar(charnum, _retval); } \
  NS_SCRIPTABLE NS_IMETHOD GetRotationOfChar(PRUint32 charnum, float *_retval NS_OUTPARAM) { return _to GetRotationOfChar(charnum, _retval); } \
  NS_SCRIPTABLE NS_IMETHOD GetCharNumAtPosition(nsIDOMSVGPoint *point, PRInt32 *_retval NS_OUTPARAM) { return _to GetCharNumAtPosition(point, _retval); } \
  NS_SCRIPTABLE NS_IMETHOD SelectSubString(PRUint32 charnum, PRUint32 nchars) { return _to SelectSubString(charnum, nchars); } 

/* Use this macro to declare functions that forward the behavior of this interface to another object in a safe way. */
#define NS_FORWARD_SAFE_NSIDOMSVGTEXTCONTENTELEMENT(_to) \
  NS_SCRIPTABLE NS_IMETHOD GetTextLength(nsIDOMSVGAnimatedLength * *aTextLength) { return !_to ? NS_ERROR_NULL_POINTER : _to->GetTextLength(aTextLength); } \
  NS_SCRIPTABLE NS_IMETHOD GetLengthAdjust(nsIDOMSVGAnimatedEnumeration * *aLengthAdjust) { return !_to ? NS_ERROR_NULL_POINTER : _to->GetLengthAdjust(aLengthAdjust); } \
  NS_SCRIPTABLE NS_IMETHOD GetNumberOfChars(PRInt32 *_retval NS_OUTPARAM) { return !_to ? NS_ERROR_NULL_POINTER : _to->GetNumberOfChars(_retval); } \
  NS_SCRIPTABLE NS_IMETHOD GetComputedTextLength(float *_retval NS_OUTPARAM) { return !_to ? NS_ERROR_NULL_POINTER : _to->GetComputedTextLength(_retval); } \
  NS_SCRIPTABLE NS_IMETHOD GetSubStringLength(PRUint32 charnum, PRUint32 nchars, float *_retval NS_OUTPARAM) { return !_to ? NS_ERROR_NULL_POINTER : _to->GetSubStringLength(charnum, nchars, _retval); } \
  NS_SCRIPTABLE NS_IMETHOD GetStartPositionOfChar(PRUint32 charnum, nsIDOMSVGPoint **_retval NS_OUTPARAM) { return !_to ? NS_ERROR_NULL_POINTER : _to->GetStartPositionOfChar(charnum, _retval); } \
  NS_SCRIPTABLE NS_IMETHOD GetEndPositionOfChar(PRUint32 charnum, nsIDOMSVGPoint **_retval NS_OUTPARAM) { return !_to ? NS_ERROR_NULL_POINTER : _to->GetEndPositionOfChar(charnum, _retval); } \
  NS_SCRIPTABLE NS_IMETHOD GetExtentOfChar(PRUint32 charnum, nsIDOMSVGRect **_retval NS_OUTPARAM) { return !_to ? NS_ERROR_NULL_POINTER : _to->GetExtentOfChar(charnum, _retval); } \
  NS_SCRIPTABLE NS_IMETHOD GetRotationOfChar(PRUint32 charnum, float *_retval NS_OUTPARAM) { return !_to ? NS_ERROR_NULL_POINTER : _to->GetRotationOfChar(charnum, _retval); } \
  NS_SCRIPTABLE NS_IMETHOD GetCharNumAtPosition(nsIDOMSVGPoint *point, PRInt32 *_retval NS_OUTPARAM) { return !_to ? NS_ERROR_NULL_POINTER : _to->GetCharNumAtPosition(point, _retval); } \
  NS_SCRIPTABLE NS_IMETHOD SelectSubString(PRUint32 charnum, PRUint32 nchars) { return !_to ? NS_ERROR_NULL_POINTER : _to->SelectSubString(charnum, nchars); } 

#if 0
/* Use the code below as a template for the implementation class for this interface. */

/* Header file */
class nsDOMSVGTextContentElement : public nsIDOMSVGTextContentElement
{
public:
  NS_DECL_ISUPPORTS
  NS_DECL_NSIDOMSVGTEXTCONTENTELEMENT

  nsDOMSVGTextContentElement();

private:
  ~nsDOMSVGTextContentElement();

protected:
  /* additional members */
};

/* Implementation file */
NS_IMPL_ISUPPORTS1(nsDOMSVGTextContentElement, nsIDOMSVGTextContentElement)

nsDOMSVGTextContentElement::nsDOMSVGTextContentElement()
{
  /* member initializers and constructor code */
}

nsDOMSVGTextContentElement::~nsDOMSVGTextContentElement()
{
  /* destructor code */
}

/* readonly attribute nsIDOMSVGAnimatedLength textLength; */
NS_IMETHODIMP nsDOMSVGTextContentElement::GetTextLength(nsIDOMSVGAnimatedLength * *aTextLength)
{
    return NS_ERROR_NOT_IMPLEMENTED;
}

/* readonly attribute nsIDOMSVGAnimatedEnumeration lengthAdjust; */
NS_IMETHODIMP nsDOMSVGTextContentElement::GetLengthAdjust(nsIDOMSVGAnimatedEnumeration * *aLengthAdjust)
{
    return NS_ERROR_NOT_IMPLEMENTED;
}

/* long getNumberOfChars (); */
NS_IMETHODIMP nsDOMSVGTextContentElement::GetNumberOfChars(PRInt32 *_retval NS_OUTPARAM)
{
    return NS_ERROR_NOT_IMPLEMENTED;
}

/* float getComputedTextLength (); */
NS_IMETHODIMP nsDOMSVGTextContentElement::GetComputedTextLength(float *_retval NS_OUTPARAM)
{
    return NS_ERROR_NOT_IMPLEMENTED;
}

/* float getSubStringLength (in unsigned long charnum, in unsigned long nchars); */
NS_IMETHODIMP nsDOMSVGTextContentElement::GetSubStringLength(PRUint32 charnum, PRUint32 nchars, float *_retval NS_OUTPARAM)
{
    return NS_ERROR_NOT_IMPLEMENTED;
}

/* nsIDOMSVGPoint getStartPositionOfChar (in unsigned long charnum); */
NS_IMETHODIMP nsDOMSVGTextContentElement::GetStartPositionOfChar(PRUint32 charnum, nsIDOMSVGPoint **_retval NS_OUTPARAM)
{
    return NS_ERROR_NOT_IMPLEMENTED;
}

/* nsIDOMSVGPoint getEndPositionOfChar (in unsigned long charnum); */
NS_IMETHODIMP nsDOMSVGTextContentElement::GetEndPositionOfChar(PRUint32 charnum, nsIDOMSVGPoint **_retval NS_OUTPARAM)
{
    return NS_ERROR_NOT_IMPLEMENTED;
}

/* nsIDOMSVGRect getExtentOfChar (in unsigned long charnum); */
NS_IMETHODIMP nsDOMSVGTextContentElement::GetExtentOfChar(PRUint32 charnum, nsIDOMSVGRect **_retval NS_OUTPARAM)
{
    return NS_ERROR_NOT_IMPLEMENTED;
}

/* float getRotationOfChar (in unsigned long charnum); */
NS_IMETHODIMP nsDOMSVGTextContentElement::GetRotationOfChar(PRUint32 charnum, float *_retval NS_OUTPARAM)
{
    return NS_ERROR_NOT_IMPLEMENTED;
}

/* long getCharNumAtPosition (in nsIDOMSVGPoint point); */
NS_IMETHODIMP nsDOMSVGTextContentElement::GetCharNumAtPosition(nsIDOMSVGPoint *point, PRInt32 *_retval NS_OUTPARAM)
{
    return NS_ERROR_NOT_IMPLEMENTED;
}

/* void selectSubString (in unsigned long charnum, in unsigned long nchars); */
NS_IMETHODIMP nsDOMSVGTextContentElement::SelectSubString(PRUint32 charnum, PRUint32 nchars)
{
    return NS_ERROR_NOT_IMPLEMENTED;
}

/* End of implementation class template. */
#endif


#endif /* __gen_nsIDOMSVGTextContentElement_h__ */
