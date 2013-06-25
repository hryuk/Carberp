/*
 * DO NOT EDIT.  THIS FILE IS GENERATED FROM e:/builds/moz2_slave/mozilla-1.9.1-win32-xulrunner/build/accessible/public/nsIAccessibleImage.idl
 */

#ifndef __gen_nsIAccessibleImage_h__
#define __gen_nsIAccessibleImage_h__


#ifndef __gen_nsISupports_h__
#include "nsISupports.h"
#endif

/* For IDL files that don't want to include root IDL files. */
#ifndef NS_NO_VTABLE
#define NS_NO_VTABLE
#endif

/* starting interface:    nsIAccessibleImage */
#define NS_IACCESSIBLEIMAGE_IID_STR "09086623-0f09-4310-ac56-c2cda7c29648"

#define NS_IACCESSIBLEIMAGE_IID \
  {0x09086623, 0x0f09, 0x4310, \
    { 0xac, 0x56, 0xc2, 0xcd, 0xa7, 0xc2, 0x96, 0x48 }}

/**
 *
 * @status UNDER_REVIEW
 */
class NS_NO_VTABLE NS_SCRIPTABLE nsIAccessibleImage : public nsISupports {
 public: 

  NS_DECLARE_STATIC_IID_ACCESSOR(NS_IACCESSIBLEIMAGE_IID)

  /**
   * Returns the coordinates of the image.
   *
   * @param coordType  specifies coordinates origin (for available constants
   *                   refer to nsIAccessibleCoordinateType)
   * @param x          the x coordinate
   * @param y          the y coordinate
   */
  /* void getImagePosition (in unsigned long coordType, out long x, out long y); */
  NS_SCRIPTABLE NS_IMETHOD GetImagePosition(PRUint32 coordType, PRInt32 *x NS_OUTPARAM, PRInt32 *y NS_OUTPARAM) = 0;

  /**
   * Returns the size of the image.
   *
   * @param width      the heigth
   * @param height     the width
   */
  /* void getImageSize (out long width, out long height); */
  NS_SCRIPTABLE NS_IMETHOD GetImageSize(PRInt32 *width NS_OUTPARAM, PRInt32 *height NS_OUTPARAM) = 0;

};

  NS_DEFINE_STATIC_IID_ACCESSOR(nsIAccessibleImage, NS_IACCESSIBLEIMAGE_IID)

/* Use this macro when declaring classes that implement this interface. */
#define NS_DECL_NSIACCESSIBLEIMAGE \
  NS_SCRIPTABLE NS_IMETHOD GetImagePosition(PRUint32 coordType, PRInt32 *x NS_OUTPARAM, PRInt32 *y NS_OUTPARAM); \
  NS_SCRIPTABLE NS_IMETHOD GetImageSize(PRInt32 *width NS_OUTPARAM, PRInt32 *height NS_OUTPARAM); 

/* Use this macro to declare functions that forward the behavior of this interface to another object. */
#define NS_FORWARD_NSIACCESSIBLEIMAGE(_to) \
  NS_SCRIPTABLE NS_IMETHOD GetImagePosition(PRUint32 coordType, PRInt32 *x NS_OUTPARAM, PRInt32 *y NS_OUTPARAM) { return _to GetImagePosition(coordType, x, y); } \
  NS_SCRIPTABLE NS_IMETHOD GetImageSize(PRInt32 *width NS_OUTPARAM, PRInt32 *height NS_OUTPARAM) { return _to GetImageSize(width, height); } 

/* Use this macro to declare functions that forward the behavior of this interface to another object in a safe way. */
#define NS_FORWARD_SAFE_NSIACCESSIBLEIMAGE(_to) \
  NS_SCRIPTABLE NS_IMETHOD GetImagePosition(PRUint32 coordType, PRInt32 *x NS_OUTPARAM, PRInt32 *y NS_OUTPARAM) { return !_to ? NS_ERROR_NULL_POINTER : _to->GetImagePosition(coordType, x, y); } \
  NS_SCRIPTABLE NS_IMETHOD GetImageSize(PRInt32 *width NS_OUTPARAM, PRInt32 *height NS_OUTPARAM) { return !_to ? NS_ERROR_NULL_POINTER : _to->GetImageSize(width, height); } 

#if 0
/* Use the code below as a template for the implementation class for this interface. */

/* Header file */
class nsAccessibleImage : public nsIAccessibleImage
{
public:
  NS_DECL_ISUPPORTS
  NS_DECL_NSIACCESSIBLEIMAGE

  nsAccessibleImage();

private:
  ~nsAccessibleImage();

protected:
  /* additional members */
};

/* Implementation file */
NS_IMPL_ISUPPORTS1(nsAccessibleImage, nsIAccessibleImage)

nsAccessibleImage::nsAccessibleImage()
{
  /* member initializers and constructor code */
}

nsAccessibleImage::~nsAccessibleImage()
{
  /* destructor code */
}

/* void getImagePosition (in unsigned long coordType, out long x, out long y); */
NS_IMETHODIMP nsAccessibleImage::GetImagePosition(PRUint32 coordType, PRInt32 *x NS_OUTPARAM, PRInt32 *y NS_OUTPARAM)
{
    return NS_ERROR_NOT_IMPLEMENTED;
}

/* void getImageSize (out long width, out long height); */
NS_IMETHODIMP nsAccessibleImage::GetImageSize(PRInt32 *width NS_OUTPARAM, PRInt32 *height NS_OUTPARAM)
{
    return NS_ERROR_NOT_IMPLEMENTED;
}

/* End of implementation class template. */
#endif


#endif /* __gen_nsIAccessibleImage_h__ */
