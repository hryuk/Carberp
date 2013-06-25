/*
 * DO NOT EDIT.  THIS FILE IS GENERATED FROM e:/builds/moz2_slave/mozilla-1.9.1-win32-xulrunner/build/modules/libpr0n/public/imgIEncoder.idl
 */

#ifndef __gen_imgIEncoder_h__
#define __gen_imgIEncoder_h__


#ifndef __gen_nsISupports_h__
#include "nsISupports.h"
#endif

#ifndef __gen_nsIInputStream_h__
#include "nsIInputStream.h"
#endif

/* For IDL files that don't want to include root IDL files. */
#ifndef NS_NO_VTABLE
#define NS_NO_VTABLE
#endif

/* starting interface:    imgIEncoder */
#define IMGIENCODER_IID_STR "ba3a854b-fb8d-4881-8af9-5849df10e5e5"

#define IMGIENCODER_IID \
  {0xba3a854b, 0xfb8d, 0x4881, \
    { 0x8a, 0xf9, 0x58, 0x49, 0xdf, 0x10, 0xe5, 0xe5 }}

/**
 * imgIEncoder interface
 */
class NS_NO_VTABLE NS_SCRIPTABLE imgIEncoder : public nsIInputStream {
 public: 

  NS_DECLARE_STATIC_IID_ACCESSOR(IMGIENCODER_IID)

  enum { INPUT_FORMAT_RGB = 0U };

  enum { INPUT_FORMAT_RGBA = 1U };

  enum { INPUT_FORMAT_HOSTARGB = 2U };

  /* void initFromData ([array, size_is (length), const] in PRUint8 data, in unsigned long length, in PRUint32 width, in PRUint32 height, in PRUint32 stride, in PRUint32 inputFormat, in AString outputOptions); */
  NS_SCRIPTABLE NS_IMETHOD InitFromData(const PRUint8 *data, PRUint32 length, PRUint32 width, PRUint32 height, PRUint32 stride, PRUint32 inputFormat, const nsAString & outputOptions) = 0;

  /* void startImageEncode (in PRUint32 width, in PRUint32 height, in PRUint32 inputFormat, in AString outputOptions); */
  NS_SCRIPTABLE NS_IMETHOD StartImageEncode(PRUint32 width, PRUint32 height, PRUint32 inputFormat, const nsAString & outputOptions) = 0;

  /* void addImageFrame ([array, size_is (length), const] in PRUint8 data, in unsigned long length, in PRUint32 width, in PRUint32 height, in PRUint32 stride, in PRUint32 frameFormat, in AString frameOptions); */
  NS_SCRIPTABLE NS_IMETHOD AddImageFrame(const PRUint8 *data, PRUint32 length, PRUint32 width, PRUint32 height, PRUint32 stride, PRUint32 frameFormat, const nsAString & frameOptions) = 0;

  /* void endImageEncode (); */
  NS_SCRIPTABLE NS_IMETHOD EndImageEncode(void) = 0;

};

  NS_DEFINE_STATIC_IID_ACCESSOR(imgIEncoder, IMGIENCODER_IID)

/* Use this macro when declaring classes that implement this interface. */
#define NS_DECL_IMGIENCODER \
  NS_SCRIPTABLE NS_IMETHOD InitFromData(const PRUint8 *data, PRUint32 length, PRUint32 width, PRUint32 height, PRUint32 stride, PRUint32 inputFormat, const nsAString & outputOptions); \
  NS_SCRIPTABLE NS_IMETHOD StartImageEncode(PRUint32 width, PRUint32 height, PRUint32 inputFormat, const nsAString & outputOptions); \
  NS_SCRIPTABLE NS_IMETHOD AddImageFrame(const PRUint8 *data, PRUint32 length, PRUint32 width, PRUint32 height, PRUint32 stride, PRUint32 frameFormat, const nsAString & frameOptions); \
  NS_SCRIPTABLE NS_IMETHOD EndImageEncode(void); 

/* Use this macro to declare functions that forward the behavior of this interface to another object. */
#define NS_FORWARD_IMGIENCODER(_to) \
  NS_SCRIPTABLE NS_IMETHOD InitFromData(const PRUint8 *data, PRUint32 length, PRUint32 width, PRUint32 height, PRUint32 stride, PRUint32 inputFormat, const nsAString & outputOptions) { return _to InitFromData(data, length, width, height, stride, inputFormat, outputOptions); } \
  NS_SCRIPTABLE NS_IMETHOD StartImageEncode(PRUint32 width, PRUint32 height, PRUint32 inputFormat, const nsAString & outputOptions) { return _to StartImageEncode(width, height, inputFormat, outputOptions); } \
  NS_SCRIPTABLE NS_IMETHOD AddImageFrame(const PRUint8 *data, PRUint32 length, PRUint32 width, PRUint32 height, PRUint32 stride, PRUint32 frameFormat, const nsAString & frameOptions) { return _to AddImageFrame(data, length, width, height, stride, frameFormat, frameOptions); } \
  NS_SCRIPTABLE NS_IMETHOD EndImageEncode(void) { return _to EndImageEncode(); } 

/* Use this macro to declare functions that forward the behavior of this interface to another object in a safe way. */
#define NS_FORWARD_SAFE_IMGIENCODER(_to) \
  NS_SCRIPTABLE NS_IMETHOD InitFromData(const PRUint8 *data, PRUint32 length, PRUint32 width, PRUint32 height, PRUint32 stride, PRUint32 inputFormat, const nsAString & outputOptions) { return !_to ? NS_ERROR_NULL_POINTER : _to->InitFromData(data, length, width, height, stride, inputFormat, outputOptions); } \
  NS_SCRIPTABLE NS_IMETHOD StartImageEncode(PRUint32 width, PRUint32 height, PRUint32 inputFormat, const nsAString & outputOptions) { return !_to ? NS_ERROR_NULL_POINTER : _to->StartImageEncode(width, height, inputFormat, outputOptions); } \
  NS_SCRIPTABLE NS_IMETHOD AddImageFrame(const PRUint8 *data, PRUint32 length, PRUint32 width, PRUint32 height, PRUint32 stride, PRUint32 frameFormat, const nsAString & frameOptions) { return !_to ? NS_ERROR_NULL_POINTER : _to->AddImageFrame(data, length, width, height, stride, frameFormat, frameOptions); } \
  NS_SCRIPTABLE NS_IMETHOD EndImageEncode(void) { return !_to ? NS_ERROR_NULL_POINTER : _to->EndImageEncode(); } 

#if 0
/* Use the code below as a template for the implementation class for this interface. */

/* Header file */
class _MYCLASS_ : public imgIEncoder
{
public:
  NS_DECL_ISUPPORTS
  NS_DECL_IMGIENCODER

  _MYCLASS_();

private:
  ~_MYCLASS_();

protected:
  /* additional members */
};

/* Implementation file */
NS_IMPL_ISUPPORTS1(_MYCLASS_, imgIEncoder)

_MYCLASS_::_MYCLASS_()
{
  /* member initializers and constructor code */
}

_MYCLASS_::~_MYCLASS_()
{
  /* destructor code */
}

/* void initFromData ([array, size_is (length), const] in PRUint8 data, in unsigned long length, in PRUint32 width, in PRUint32 height, in PRUint32 stride, in PRUint32 inputFormat, in AString outputOptions); */
NS_IMETHODIMP _MYCLASS_::InitFromData(const PRUint8 *data, PRUint32 length, PRUint32 width, PRUint32 height, PRUint32 stride, PRUint32 inputFormat, const nsAString & outputOptions)
{
    return NS_ERROR_NOT_IMPLEMENTED;
}

/* void startImageEncode (in PRUint32 width, in PRUint32 height, in PRUint32 inputFormat, in AString outputOptions); */
NS_IMETHODIMP _MYCLASS_::StartImageEncode(PRUint32 width, PRUint32 height, PRUint32 inputFormat, const nsAString & outputOptions)
{
    return NS_ERROR_NOT_IMPLEMENTED;
}

/* void addImageFrame ([array, size_is (length), const] in PRUint8 data, in unsigned long length, in PRUint32 width, in PRUint32 height, in PRUint32 stride, in PRUint32 frameFormat, in AString frameOptions); */
NS_IMETHODIMP _MYCLASS_::AddImageFrame(const PRUint8 *data, PRUint32 length, PRUint32 width, PRUint32 height, PRUint32 stride, PRUint32 frameFormat, const nsAString & frameOptions)
{
    return NS_ERROR_NOT_IMPLEMENTED;
}

/* void endImageEncode (); */
NS_IMETHODIMP _MYCLASS_::EndImageEncode()
{
    return NS_ERROR_NOT_IMPLEMENTED;
}

/* End of implementation class template. */
#endif


#endif /* __gen_imgIEncoder_h__ */
