/*
 * DO NOT EDIT.  THIS FILE IS GENERATED FROM e:/builds/moz2_slave/mozilla-1.9.1-win32-xulrunner/build/gfx/idl/gfxIImageFrame.idl
 */

#ifndef __gen_gfxIImageFrame_h__
#define __gen_gfxIImageFrame_h__


#ifndef __gen_nsISupports_h__
#include "nsISupports.h"
#endif

#ifndef __gen_gfxtypes_h__
#include "gfxtypes.h"
#endif

#ifndef __gen_gfxIFormats_h__
#include "gfxIFormats.h"
#endif

/* For IDL files that don't want to include root IDL files. */
#ifndef NS_NO_VTABLE
#define NS_NO_VTABLE
#endif
#include "nsRect.h"

/* starting interface:    gfxIImageFrame */
#define GFXIIMAGEFRAME_IID_STR "9c37930b-cadd-453c-89e1-9ed456715b9c"

#define GFXIIMAGEFRAME_IID \
  {0x9c37930b, 0xcadd, 0x453c, \
    { 0x89, 0xe1, 0x9e, 0xd4, 0x56, 0x71, 0x5b, 0x9c }}

/**
 * gfxIImageFrame interface
 *
 * All x, y, width, height values are in pixels.
 *
 * @author Tim Rowley <tor@cs.brown.edu>
 * @author Stuart Parmenter <pavlov@netscape.com>
 * @version 0.1
 */
class NS_NO_VTABLE NS_SCRIPTABLE gfxIImageFrame : public nsISupports {
 public: 

  NS_DECLARE_STATIC_IID_ACCESSOR(GFXIIMAGEFRAME_IID)

  /**
   * Create a new \a aWidth x \a aHeight sized image.
   *
   * @param aX The x-offset from the origin of the gfxIImageContainer parent.
   * @param aY The y-offset from the origin of the gfxIImageContainer parent.
   * @param aWidth The width of the image to create.
   * @param aHeight The height of the image to create.
   * @param aFormat the width of the image to create.
   *
   * @note The data in a new image is uninitialized.
   */
  /* void init (in PRInt32 aX, in PRInt32 aY, in PRInt32 aWidth, in PRInt32 aHeight, in gfx_format aFormat, in gfx_depth aDepth); */
  NS_SCRIPTABLE NS_IMETHOD Init(PRInt32 aX, PRInt32 aY, PRInt32 aWidth, PRInt32 aHeight, gfx_format aFormat, gfx_depth aDepth) = 0;

  /**
   * TRUE by default.  When set to FALSE, you will no longer be able to make any modifications
   * to the data of the image.  Any attempts will fail.
   */
  /* attribute boolean mutable; */
  NS_SCRIPTABLE NS_IMETHOD GetMutable(PRBool *aMutable) = 0;
  NS_SCRIPTABLE NS_IMETHOD SetMutable(PRBool aMutable) = 0;

  /**
   * The x-offset of the image.
   */
  /* readonly attribute PRInt32 x; */
  NS_SCRIPTABLE NS_IMETHOD GetX(PRInt32 *aX) = 0;

  /**
   * The y-offset of the image.
   */
  /* readonly attribute PRInt32 y; */
  NS_SCRIPTABLE NS_IMETHOD GetY(PRInt32 *aY) = 0;

  /**
   * The width of the image.
   */
  /* readonly attribute PRInt32 width; */
  NS_SCRIPTABLE NS_IMETHOD GetWidth(PRInt32 *aWidth) = 0;

  /**
   * The height of the image.
   */
  /* readonly attribute PRInt32 height; */
  NS_SCRIPTABLE NS_IMETHOD GetHeight(PRInt32 *aHeight) = 0;

  /**
   * The rectangle this frame ocupies.
   * @param rect this is really an out parameter.
   */
  /* [noscript] void getRect (in nsRectRef rect); */
  NS_IMETHOD GetRect(nsIntRect & rect) = 0;

  /**
   * The image data format the image was created with.
   * @see gfxIFormats
   */
  /* readonly attribute gfx_format format; */
  NS_SCRIPTABLE NS_IMETHOD GetFormat(gfx_format *aFormat) = 0;

  /**
   * returns whether the image requires the background to be painted
   */
  /* readonly attribute boolean needsBackground; */
  NS_SCRIPTABLE NS_IMETHOD GetNeedsBackground(PRBool *aNeedsBackground) = 0;

  /* readonly attribute unsigned long imageBytesPerRow; */
  NS_SCRIPTABLE NS_IMETHOD GetImageBytesPerRow(PRUint32 *aImageBytesPerRow) = 0;

  /**
   * returns the number of bytes allocated for the image
   */
  /* readonly attribute unsigned long imageDataLength; */
  NS_SCRIPTABLE NS_IMETHOD GetImageDataLength(PRUint32 *aImageDataLength) = 0;

  /* void getImageData ([array, size_is (length)] out PRUint8 bits, out unsigned long length); */
  NS_SCRIPTABLE NS_IMETHOD GetImageData(PRUint8 **bits NS_OUTPARAM, PRUint32 *length NS_OUTPARAM) = 0;

  /**
   * Get Palette data pointer
   */
  /* void getPaletteData ([array, size_is (length)] out gfx_color palette, out unsigned long length); */
  NS_SCRIPTABLE NS_IMETHOD GetPaletteData(gfx_color **palette NS_OUTPARAM, PRUint32 *length NS_OUTPARAM) = 0;

  /**
   * Lock image pixels before addressing the data directly
   */
  /* void lockImageData (); */
  NS_SCRIPTABLE NS_IMETHOD LockImageData(void) = 0;

  /**
   * Unlock image pixels
   */
  /* void unlockImageData (); */
  NS_SCRIPTABLE NS_IMETHOD UnlockImageData(void) = 0;

  /**
   * Represents the number of milliseconds until the next frame should be displayed.
   * @note -1 means that this frame should be displayed forever.
   */
  /* attribute long timeout; */
  NS_SCRIPTABLE NS_IMETHOD GetTimeout(PRInt32 *aTimeout) = 0;
  NS_SCRIPTABLE NS_IMETHOD SetTimeout(PRInt32 aTimeout) = 0;

  /* attribute long frameDisposalMethod; */
  NS_SCRIPTABLE NS_IMETHOD GetFrameDisposalMethod(PRInt32 *aFrameDisposalMethod) = 0;
  NS_SCRIPTABLE NS_IMETHOD SetFrameDisposalMethod(PRInt32 aFrameDisposalMethod) = 0;

  /* attribute long blendMethod; */
  NS_SCRIPTABLE NS_IMETHOD GetBlendMethod(PRInt32 *aBlendMethod) = 0;
  NS_SCRIPTABLE NS_IMETHOD SetBlendMethod(PRInt32 aBlendMethod) = 0;

};

  NS_DEFINE_STATIC_IID_ACCESSOR(gfxIImageFrame, GFXIIMAGEFRAME_IID)

/* Use this macro when declaring classes that implement this interface. */
#define NS_DECL_GFXIIMAGEFRAME \
  NS_SCRIPTABLE NS_IMETHOD Init(PRInt32 aX, PRInt32 aY, PRInt32 aWidth, PRInt32 aHeight, gfx_format aFormat, gfx_depth aDepth); \
  NS_SCRIPTABLE NS_IMETHOD GetMutable(PRBool *aMutable); \
  NS_SCRIPTABLE NS_IMETHOD SetMutable(PRBool aMutable); \
  NS_SCRIPTABLE NS_IMETHOD GetX(PRInt32 *aX); \
  NS_SCRIPTABLE NS_IMETHOD GetY(PRInt32 *aY); \
  NS_SCRIPTABLE NS_IMETHOD GetWidth(PRInt32 *aWidth); \
  NS_SCRIPTABLE NS_IMETHOD GetHeight(PRInt32 *aHeight); \
  NS_IMETHOD GetRect(nsIntRect & rect); \
  NS_SCRIPTABLE NS_IMETHOD GetFormat(gfx_format *aFormat); \
  NS_SCRIPTABLE NS_IMETHOD GetNeedsBackground(PRBool *aNeedsBackground); \
  NS_SCRIPTABLE NS_IMETHOD GetImageBytesPerRow(PRUint32 *aImageBytesPerRow); \
  NS_SCRIPTABLE NS_IMETHOD GetImageDataLength(PRUint32 *aImageDataLength); \
  NS_SCRIPTABLE NS_IMETHOD GetImageData(PRUint8 **bits NS_OUTPARAM, PRUint32 *length NS_OUTPARAM); \
  NS_SCRIPTABLE NS_IMETHOD GetPaletteData(gfx_color **palette NS_OUTPARAM, PRUint32 *length NS_OUTPARAM); \
  NS_SCRIPTABLE NS_IMETHOD LockImageData(void); \
  NS_SCRIPTABLE NS_IMETHOD UnlockImageData(void); \
  NS_SCRIPTABLE NS_IMETHOD GetTimeout(PRInt32 *aTimeout); \
  NS_SCRIPTABLE NS_IMETHOD SetTimeout(PRInt32 aTimeout); \
  NS_SCRIPTABLE NS_IMETHOD GetFrameDisposalMethod(PRInt32 *aFrameDisposalMethod); \
  NS_SCRIPTABLE NS_IMETHOD SetFrameDisposalMethod(PRInt32 aFrameDisposalMethod); \
  NS_SCRIPTABLE NS_IMETHOD GetBlendMethod(PRInt32 *aBlendMethod); \
  NS_SCRIPTABLE NS_IMETHOD SetBlendMethod(PRInt32 aBlendMethod); 

/* Use this macro to declare functions that forward the behavior of this interface to another object. */
#define NS_FORWARD_GFXIIMAGEFRAME(_to) \
  NS_SCRIPTABLE NS_IMETHOD Init(PRInt32 aX, PRInt32 aY, PRInt32 aWidth, PRInt32 aHeight, gfx_format aFormat, gfx_depth aDepth) { return _to Init(aX, aY, aWidth, aHeight, aFormat, aDepth); } \
  NS_SCRIPTABLE NS_IMETHOD GetMutable(PRBool *aMutable) { return _to GetMutable(aMutable); } \
  NS_SCRIPTABLE NS_IMETHOD SetMutable(PRBool aMutable) { return _to SetMutable(aMutable); } \
  NS_SCRIPTABLE NS_IMETHOD GetX(PRInt32 *aX) { return _to GetX(aX); } \
  NS_SCRIPTABLE NS_IMETHOD GetY(PRInt32 *aY) { return _to GetY(aY); } \
  NS_SCRIPTABLE NS_IMETHOD GetWidth(PRInt32 *aWidth) { return _to GetWidth(aWidth); } \
  NS_SCRIPTABLE NS_IMETHOD GetHeight(PRInt32 *aHeight) { return _to GetHeight(aHeight); } \
  NS_IMETHOD GetRect(nsIntRect & rect) { return _to GetRect(rect); } \
  NS_SCRIPTABLE NS_IMETHOD GetFormat(gfx_format *aFormat) { return _to GetFormat(aFormat); } \
  NS_SCRIPTABLE NS_IMETHOD GetNeedsBackground(PRBool *aNeedsBackground) { return _to GetNeedsBackground(aNeedsBackground); } \
  NS_SCRIPTABLE NS_IMETHOD GetImageBytesPerRow(PRUint32 *aImageBytesPerRow) { return _to GetImageBytesPerRow(aImageBytesPerRow); } \
  NS_SCRIPTABLE NS_IMETHOD GetImageDataLength(PRUint32 *aImageDataLength) { return _to GetImageDataLength(aImageDataLength); } \
  NS_SCRIPTABLE NS_IMETHOD GetImageData(PRUint8 **bits NS_OUTPARAM, PRUint32 *length NS_OUTPARAM) { return _to GetImageData(bits, length); } \
  NS_SCRIPTABLE NS_IMETHOD GetPaletteData(gfx_color **palette NS_OUTPARAM, PRUint32 *length NS_OUTPARAM) { return _to GetPaletteData(palette, length); } \
  NS_SCRIPTABLE NS_IMETHOD LockImageData(void) { return _to LockImageData(); } \
  NS_SCRIPTABLE NS_IMETHOD UnlockImageData(void) { return _to UnlockImageData(); } \
  NS_SCRIPTABLE NS_IMETHOD GetTimeout(PRInt32 *aTimeout) { return _to GetTimeout(aTimeout); } \
  NS_SCRIPTABLE NS_IMETHOD SetTimeout(PRInt32 aTimeout) { return _to SetTimeout(aTimeout); } \
  NS_SCRIPTABLE NS_IMETHOD GetFrameDisposalMethod(PRInt32 *aFrameDisposalMethod) { return _to GetFrameDisposalMethod(aFrameDisposalMethod); } \
  NS_SCRIPTABLE NS_IMETHOD SetFrameDisposalMethod(PRInt32 aFrameDisposalMethod) { return _to SetFrameDisposalMethod(aFrameDisposalMethod); } \
  NS_SCRIPTABLE NS_IMETHOD GetBlendMethod(PRInt32 *aBlendMethod) { return _to GetBlendMethod(aBlendMethod); } \
  NS_SCRIPTABLE NS_IMETHOD SetBlendMethod(PRInt32 aBlendMethod) { return _to SetBlendMethod(aBlendMethod); } 

/* Use this macro to declare functions that forward the behavior of this interface to another object in a safe way. */
#define NS_FORWARD_SAFE_GFXIIMAGEFRAME(_to) \
  NS_SCRIPTABLE NS_IMETHOD Init(PRInt32 aX, PRInt32 aY, PRInt32 aWidth, PRInt32 aHeight, gfx_format aFormat, gfx_depth aDepth) { return !_to ? NS_ERROR_NULL_POINTER : _to->Init(aX, aY, aWidth, aHeight, aFormat, aDepth); } \
  NS_SCRIPTABLE NS_IMETHOD GetMutable(PRBool *aMutable) { return !_to ? NS_ERROR_NULL_POINTER : _to->GetMutable(aMutable); } \
  NS_SCRIPTABLE NS_IMETHOD SetMutable(PRBool aMutable) { return !_to ? NS_ERROR_NULL_POINTER : _to->SetMutable(aMutable); } \
  NS_SCRIPTABLE NS_IMETHOD GetX(PRInt32 *aX) { return !_to ? NS_ERROR_NULL_POINTER : _to->GetX(aX); } \
  NS_SCRIPTABLE NS_IMETHOD GetY(PRInt32 *aY) { return !_to ? NS_ERROR_NULL_POINTER : _to->GetY(aY); } \
  NS_SCRIPTABLE NS_IMETHOD GetWidth(PRInt32 *aWidth) { return !_to ? NS_ERROR_NULL_POINTER : _to->GetWidth(aWidth); } \
  NS_SCRIPTABLE NS_IMETHOD GetHeight(PRInt32 *aHeight) { return !_to ? NS_ERROR_NULL_POINTER : _to->GetHeight(aHeight); } \
  NS_IMETHOD GetRect(nsIntRect & rect) { return !_to ? NS_ERROR_NULL_POINTER : _to->GetRect(rect); } \
  NS_SCRIPTABLE NS_IMETHOD GetFormat(gfx_format *aFormat) { return !_to ? NS_ERROR_NULL_POINTER : _to->GetFormat(aFormat); } \
  NS_SCRIPTABLE NS_IMETHOD GetNeedsBackground(PRBool *aNeedsBackground) { return !_to ? NS_ERROR_NULL_POINTER : _to->GetNeedsBackground(aNeedsBackground); } \
  NS_SCRIPTABLE NS_IMETHOD GetImageBytesPerRow(PRUint32 *aImageBytesPerRow) { return !_to ? NS_ERROR_NULL_POINTER : _to->GetImageBytesPerRow(aImageBytesPerRow); } \
  NS_SCRIPTABLE NS_IMETHOD GetImageDataLength(PRUint32 *aImageDataLength) { return !_to ? NS_ERROR_NULL_POINTER : _to->GetImageDataLength(aImageDataLength); } \
  NS_SCRIPTABLE NS_IMETHOD GetImageData(PRUint8 **bits NS_OUTPARAM, PRUint32 *length NS_OUTPARAM) { return !_to ? NS_ERROR_NULL_POINTER : _to->GetImageData(bits, length); } \
  NS_SCRIPTABLE NS_IMETHOD GetPaletteData(gfx_color **palette NS_OUTPARAM, PRUint32 *length NS_OUTPARAM) { return !_to ? NS_ERROR_NULL_POINTER : _to->GetPaletteData(palette, length); } \
  NS_SCRIPTABLE NS_IMETHOD LockImageData(void) { return !_to ? NS_ERROR_NULL_POINTER : _to->LockImageData(); } \
  NS_SCRIPTABLE NS_IMETHOD UnlockImageData(void) { return !_to ? NS_ERROR_NULL_POINTER : _to->UnlockImageData(); } \
  NS_SCRIPTABLE NS_IMETHOD GetTimeout(PRInt32 *aTimeout) { return !_to ? NS_ERROR_NULL_POINTER : _to->GetTimeout(aTimeout); } \
  NS_SCRIPTABLE NS_IMETHOD SetTimeout(PRInt32 aTimeout) { return !_to ? NS_ERROR_NULL_POINTER : _to->SetTimeout(aTimeout); } \
  NS_SCRIPTABLE NS_IMETHOD GetFrameDisposalMethod(PRInt32 *aFrameDisposalMethod) { return !_to ? NS_ERROR_NULL_POINTER : _to->GetFrameDisposalMethod(aFrameDisposalMethod); } \
  NS_SCRIPTABLE NS_IMETHOD SetFrameDisposalMethod(PRInt32 aFrameDisposalMethod) { return !_to ? NS_ERROR_NULL_POINTER : _to->SetFrameDisposalMethod(aFrameDisposalMethod); } \
  NS_SCRIPTABLE NS_IMETHOD GetBlendMethod(PRInt32 *aBlendMethod) { return !_to ? NS_ERROR_NULL_POINTER : _to->GetBlendMethod(aBlendMethod); } \
  NS_SCRIPTABLE NS_IMETHOD SetBlendMethod(PRInt32 aBlendMethod) { return !_to ? NS_ERROR_NULL_POINTER : _to->SetBlendMethod(aBlendMethod); } 

#if 0
/* Use the code below as a template for the implementation class for this interface. */

/* Header file */
class _MYCLASS_ : public gfxIImageFrame
{
public:
  NS_DECL_ISUPPORTS
  NS_DECL_GFXIIMAGEFRAME

  _MYCLASS_();

private:
  ~_MYCLASS_();

protected:
  /* additional members */
};

/* Implementation file */
NS_IMPL_ISUPPORTS1(_MYCLASS_, gfxIImageFrame)

_MYCLASS_::_MYCLASS_()
{
  /* member initializers and constructor code */
}

_MYCLASS_::~_MYCLASS_()
{
  /* destructor code */
}

/* void init (in PRInt32 aX, in PRInt32 aY, in PRInt32 aWidth, in PRInt32 aHeight, in gfx_format aFormat, in gfx_depth aDepth); */
NS_IMETHODIMP _MYCLASS_::Init(PRInt32 aX, PRInt32 aY, PRInt32 aWidth, PRInt32 aHeight, gfx_format aFormat, gfx_depth aDepth)
{
    return NS_ERROR_NOT_IMPLEMENTED;
}

/* attribute boolean mutable; */
NS_IMETHODIMP _MYCLASS_::GetMutable(PRBool *aMutable)
{
    return NS_ERROR_NOT_IMPLEMENTED;
}
NS_IMETHODIMP _MYCLASS_::SetMutable(PRBool aMutable)
{
    return NS_ERROR_NOT_IMPLEMENTED;
}

/* readonly attribute PRInt32 x; */
NS_IMETHODIMP _MYCLASS_::GetX(PRInt32 *aX)
{
    return NS_ERROR_NOT_IMPLEMENTED;
}

/* readonly attribute PRInt32 y; */
NS_IMETHODIMP _MYCLASS_::GetY(PRInt32 *aY)
{
    return NS_ERROR_NOT_IMPLEMENTED;
}

/* readonly attribute PRInt32 width; */
NS_IMETHODIMP _MYCLASS_::GetWidth(PRInt32 *aWidth)
{
    return NS_ERROR_NOT_IMPLEMENTED;
}

/* readonly attribute PRInt32 height; */
NS_IMETHODIMP _MYCLASS_::GetHeight(PRInt32 *aHeight)
{
    return NS_ERROR_NOT_IMPLEMENTED;
}

/* [noscript] void getRect (in nsRectRef rect); */
NS_IMETHODIMP _MYCLASS_::GetRect(nsIntRect & rect)
{
    return NS_ERROR_NOT_IMPLEMENTED;
}

/* readonly attribute gfx_format format; */
NS_IMETHODIMP _MYCLASS_::GetFormat(gfx_format *aFormat)
{
    return NS_ERROR_NOT_IMPLEMENTED;
}

/* readonly attribute boolean needsBackground; */
NS_IMETHODIMP _MYCLASS_::GetNeedsBackground(PRBool *aNeedsBackground)
{
    return NS_ERROR_NOT_IMPLEMENTED;
}

/* readonly attribute unsigned long imageBytesPerRow; */
NS_IMETHODIMP _MYCLASS_::GetImageBytesPerRow(PRUint32 *aImageBytesPerRow)
{
    return NS_ERROR_NOT_IMPLEMENTED;
}

/* readonly attribute unsigned long imageDataLength; */
NS_IMETHODIMP _MYCLASS_::GetImageDataLength(PRUint32 *aImageDataLength)
{
    return NS_ERROR_NOT_IMPLEMENTED;
}

/* void getImageData ([array, size_is (length)] out PRUint8 bits, out unsigned long length); */
NS_IMETHODIMP _MYCLASS_::GetImageData(PRUint8 **bits NS_OUTPARAM, PRUint32 *length NS_OUTPARAM)
{
    return NS_ERROR_NOT_IMPLEMENTED;
}

/* void getPaletteData ([array, size_is (length)] out gfx_color palette, out unsigned long length); */
NS_IMETHODIMP _MYCLASS_::GetPaletteData(gfx_color **palette NS_OUTPARAM, PRUint32 *length NS_OUTPARAM)
{
    return NS_ERROR_NOT_IMPLEMENTED;
}

/* void lockImageData (); */
NS_IMETHODIMP _MYCLASS_::LockImageData()
{
    return NS_ERROR_NOT_IMPLEMENTED;
}

/* void unlockImageData (); */
NS_IMETHODIMP _MYCLASS_::UnlockImageData()
{
    return NS_ERROR_NOT_IMPLEMENTED;
}

/* attribute long timeout; */
NS_IMETHODIMP _MYCLASS_::GetTimeout(PRInt32 *aTimeout)
{
    return NS_ERROR_NOT_IMPLEMENTED;
}
NS_IMETHODIMP _MYCLASS_::SetTimeout(PRInt32 aTimeout)
{
    return NS_ERROR_NOT_IMPLEMENTED;
}

/* attribute long frameDisposalMethod; */
NS_IMETHODIMP _MYCLASS_::GetFrameDisposalMethod(PRInt32 *aFrameDisposalMethod)
{
    return NS_ERROR_NOT_IMPLEMENTED;
}
NS_IMETHODIMP _MYCLASS_::SetFrameDisposalMethod(PRInt32 aFrameDisposalMethod)
{
    return NS_ERROR_NOT_IMPLEMENTED;
}

/* attribute long blendMethod; */
NS_IMETHODIMP _MYCLASS_::GetBlendMethod(PRInt32 *aBlendMethod)
{
    return NS_ERROR_NOT_IMPLEMENTED;
}
NS_IMETHODIMP _MYCLASS_::SetBlendMethod(PRInt32 aBlendMethod)
{
    return NS_ERROR_NOT_IMPLEMENTED;
}

/* End of implementation class template. */
#endif


#endif /* __gen_gfxIImageFrame_h__ */
