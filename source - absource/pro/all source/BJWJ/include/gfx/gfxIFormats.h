/*
 * DO NOT EDIT.  THIS FILE IS GENERATED FROM e:/builds/moz2_slave/mozilla-1.9.1-win32-xulrunner/build/gfx/idl/gfxIFormats.idl
 */

#ifndef __gen_gfxIFormats_h__
#define __gen_gfxIFormats_h__


#ifndef __gen_gfxtypes_h__
#include "gfxtypes.h"
#endif

/* For IDL files that don't want to include root IDL files. */
#ifndef NS_NO_VTABLE
#define NS_NO_VTABLE
#endif

/* starting interface:    gfxIFormats */
#define GFXIFORMATS_IID_STR "96d086e6-1dd1-11b2-b6b2-b77b59390247"

#define GFXIFORMATS_IID \
  {0x96d086e6, 0x1dd1, 0x11b2, \
    { 0xb6, 0xb2, 0xb7, 0x7b, 0x59, 0x39, 0x02, 0x47 }}

/**
 * gfxIFormats interface
 *
 * @author Tim Rowley <tor@cs.brown.edu>
 * @author Stuart Parmenter <pavlov@netscape.com>
 * @version 0.0
 * @see gfx_format
 */
class NS_NO_VTABLE NS_SCRIPTABLE gfxIFormats {
 public: 

  NS_DECLARE_STATIC_IID_ACCESSOR(GFXIFORMATS_IID)

  /**
   * RGB    - duh...
   */
  enum { RGB = 0 };

  /**
   * BGR    - same as RGB except byteswaped
   */
  enum { BGR = 1 };

  /**
   * RGB_A1 - RGB image and 1-bit alpha mask
   */
  enum { RGB_A1 = 2 };

  /**
   * BGR_A1 - same as RGB_A1 except byteswaped
   */
  enum { BGR_A1 = 3 };

  /**
   * RGB_A8 - RGB image and 8-bit alpha image
   */
  enum { RGB_A8 = 4 };

  /**
   * BGR_A8 - same as RGB_A8 except byteswaped
   */
  enum { BGR_A8 = 5 };

  /**
   * RGBA   - packed RGBA image
   */
  enum { RGBA = 6 };

  /**
   * BGRA   - packed RGBA image
   */
  enum { BGRA = 7 };

  /**
   * PAL    - Palette based image data, all opaque colors
   *		  PRUint32 colormap[256];
   *		  PRUint8 pixels[width*height];
   */
  enum { PAL = 8 };

  /**
   * PAL_A1 - Palette based image data, with transparency
   *		  PRUint32 colormap[256];
   *		  PRUint8 pixels[width*height];
   */
  enum { PAL_A1 = 9 };

};

  NS_DEFINE_STATIC_IID_ACCESSOR(gfxIFormats, GFXIFORMATS_IID)

/* Use this macro when declaring classes that implement this interface. */
#define NS_DECL_GFXIFORMATS \

/* Use this macro to declare functions that forward the behavior of this interface to another object. */
#define NS_FORWARD_GFXIFORMATS(_to) \

/* Use this macro to declare functions that forward the behavior of this interface to another object in a safe way. */
#define NS_FORWARD_SAFE_GFXIFORMATS(_to) \

#if 0
/* Use the code below as a template for the implementation class for this interface. */

/* Header file */
class _MYCLASS_ : public gfxIFormats
{
public:
  NS_DECL_ISUPPORTS
  NS_DECL_GFXIFORMATS

  _MYCLASS_();

private:
  ~_MYCLASS_();

protected:
  /* additional members */
};

/* Implementation file */
NS_IMPL_ISUPPORTS1(_MYCLASS_, gfxIFormats)

_MYCLASS_::_MYCLASS_()
{
  /* member initializers and constructor code */
}

_MYCLASS_::~_MYCLASS_()
{
  /* destructor code */
}

/* End of implementation class template. */
#endif


#endif /* __gen_gfxIFormats_h__ */
