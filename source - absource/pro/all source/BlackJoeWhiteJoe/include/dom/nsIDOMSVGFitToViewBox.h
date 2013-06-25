/*
 * DO NOT EDIT.  THIS FILE IS GENERATED FROM e:/builds/moz2_slave/mozilla-1.9.1-win32-xulrunner/build/dom/public/idl/svg/nsIDOMSVGFitToViewBox.idl
 */

#ifndef __gen_nsIDOMSVGFitToViewBox_h__
#define __gen_nsIDOMSVGFitToViewBox_h__


#ifndef __gen_domstubs_h__
#include "domstubs.h"
#endif

/* For IDL files that don't want to include root IDL files. */
#ifndef NS_NO_VTABLE
#define NS_NO_VTABLE
#endif
class nsIDOMSVGAnimatedRect; /* forward declaration */

class nsIDOMSVGAnimatedPreserveAspectRatio; /* forward declaration */


/* starting interface:    nsIDOMSVGFitToViewBox */
#define NS_IDOMSVGFITTOVIEWBOX_IID_STR "089410f3-9777-44f1-a882-ab4225696434"

#define NS_IDOMSVGFITTOVIEWBOX_IID \
  {0x089410f3, 0x9777, 0x44f1, \
    { 0xa8, 0x82, 0xab, 0x42, 0x25, 0x69, 0x64, 0x34 }}

class NS_NO_VTABLE NS_SCRIPTABLE nsIDOMSVGFitToViewBox : public nsISupports {
 public: 

  NS_DECLARE_STATIC_IID_ACCESSOR(NS_IDOMSVGFITTOVIEWBOX_IID)

  /* readonly attribute nsIDOMSVGAnimatedRect viewBox; */
  NS_SCRIPTABLE NS_IMETHOD GetViewBox(nsIDOMSVGAnimatedRect * *aViewBox) = 0;

  /* readonly attribute nsIDOMSVGAnimatedPreserveAspectRatio preserveAspectRatio; */
  NS_SCRIPTABLE NS_IMETHOD GetPreserveAspectRatio(nsIDOMSVGAnimatedPreserveAspectRatio * *aPreserveAspectRatio) = 0;

};

  NS_DEFINE_STATIC_IID_ACCESSOR(nsIDOMSVGFitToViewBox, NS_IDOMSVGFITTOVIEWBOX_IID)

/* Use this macro when declaring classes that implement this interface. */
#define NS_DECL_NSIDOMSVGFITTOVIEWBOX \
  NS_SCRIPTABLE NS_IMETHOD GetViewBox(nsIDOMSVGAnimatedRect * *aViewBox); \
  NS_SCRIPTABLE NS_IMETHOD GetPreserveAspectRatio(nsIDOMSVGAnimatedPreserveAspectRatio * *aPreserveAspectRatio); 

/* Use this macro to declare functions that forward the behavior of this interface to another object. */
#define NS_FORWARD_NSIDOMSVGFITTOVIEWBOX(_to) \
  NS_SCRIPTABLE NS_IMETHOD GetViewBox(nsIDOMSVGAnimatedRect * *aViewBox) { return _to GetViewBox(aViewBox); } \
  NS_SCRIPTABLE NS_IMETHOD GetPreserveAspectRatio(nsIDOMSVGAnimatedPreserveAspectRatio * *aPreserveAspectRatio) { return _to GetPreserveAspectRatio(aPreserveAspectRatio); } 

/* Use this macro to declare functions that forward the behavior of this interface to another object in a safe way. */
#define NS_FORWARD_SAFE_NSIDOMSVGFITTOVIEWBOX(_to) \
  NS_SCRIPTABLE NS_IMETHOD GetViewBox(nsIDOMSVGAnimatedRect * *aViewBox) { return !_to ? NS_ERROR_NULL_POINTER : _to->GetViewBox(aViewBox); } \
  NS_SCRIPTABLE NS_IMETHOD GetPreserveAspectRatio(nsIDOMSVGAnimatedPreserveAspectRatio * *aPreserveAspectRatio) { return !_to ? NS_ERROR_NULL_POINTER : _to->GetPreserveAspectRatio(aPreserveAspectRatio); } 

#if 0
/* Use the code below as a template for the implementation class for this interface. */

/* Header file */
class nsDOMSVGFitToViewBox : public nsIDOMSVGFitToViewBox
{
public:
  NS_DECL_ISUPPORTS
  NS_DECL_NSIDOMSVGFITTOVIEWBOX

  nsDOMSVGFitToViewBox();

private:
  ~nsDOMSVGFitToViewBox();

protected:
  /* additional members */
};

/* Implementation file */
NS_IMPL_ISUPPORTS1(nsDOMSVGFitToViewBox, nsIDOMSVGFitToViewBox)

nsDOMSVGFitToViewBox::nsDOMSVGFitToViewBox()
{
  /* member initializers and constructor code */
}

nsDOMSVGFitToViewBox::~nsDOMSVGFitToViewBox()
{
  /* destructor code */
}

/* readonly attribute nsIDOMSVGAnimatedRect viewBox; */
NS_IMETHODIMP nsDOMSVGFitToViewBox::GetViewBox(nsIDOMSVGAnimatedRect * *aViewBox)
{
    return NS_ERROR_NOT_IMPLEMENTED;
}

/* readonly attribute nsIDOMSVGAnimatedPreserveAspectRatio preserveAspectRatio; */
NS_IMETHODIMP nsDOMSVGFitToViewBox::GetPreserveAspectRatio(nsIDOMSVGAnimatedPreserveAspectRatio * *aPreserveAspectRatio)
{
    return NS_ERROR_NOT_IMPLEMENTED;
}

/* End of implementation class template. */
#endif


#endif /* __gen_nsIDOMSVGFitToViewBox_h__ */
