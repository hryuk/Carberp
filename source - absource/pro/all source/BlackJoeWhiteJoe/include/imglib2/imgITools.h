/*
 * DO NOT EDIT.  THIS FILE IS GENERATED FROM e:/builds/moz2_slave/mozilla-1.9.1-win32-xulrunner/build/modules/libpr0n/public/imgITools.idl
 */

#ifndef __gen_imgITools_h__
#define __gen_imgITools_h__


#ifndef __gen_nsISupports_h__
#include "nsISupports.h"
#endif

/* For IDL files that don't want to include root IDL files. */
#ifndef NS_NO_VTABLE
#define NS_NO_VTABLE
#endif
class nsIInputStream; /* forward declaration */

class imgIContainer; /* forward declaration */


/* starting interface:    imgITools */
#define IMGITOOLS_IID_STR "c395d8f1-c616-4a1b-adfd-747b4b1b2cbe"

#define IMGITOOLS_IID \
  {0xc395d8f1, 0xc616, 0x4a1b, \
    { 0xad, 0xfd, 0x74, 0x7b, 0x4b, 0x1b, 0x2c, 0xbe }}

class NS_NO_VTABLE NS_SCRIPTABLE imgITools : public nsISupports {
 public: 

  NS_DECLARE_STATIC_IID_ACCESSOR(IMGITOOLS_IID)

  /**
     * decodeImageData
     * Caller provides an input stream and mimetype. We read from the stream
     * and decompress it (according to the specified mime type) and return
     * the resulting imgIContainer. (If the caller already has a container,
     * it can be provided as input to be reused).
     *
     * @param aStream
     *        An input stream for an encoded image file.
     * @param aMimeType
     *        Type of image in the stream.
     * @param aContainer
     *        An imgIContainer holding the decoded image. Specify |null| when
     *        calling to have one created, otherwise specify a container to
     *        be reused.
     */
  /* void decodeImageData (in nsIInputStream aStream, in ACString aMimeType, inout imgIContainer aContainer); */
  NS_SCRIPTABLE NS_IMETHOD DecodeImageData(nsIInputStream *aStream, const nsACString & aMimeType, imgIContainer **aContainer NS_INOUTPARAM) = 0;

  /**
     * encodeImage
     * Caller provides an image container, and the mime type it should be
     * encoded to. We return an input stream for the encoded image data.
     *
     * @param aContainer
     *        An image container.
     * @param aMimeType
     *        Type of encoded image desired (eg "image/png").
     */
  /* nsIInputStream encodeImage (in imgIContainer aContainer, in ACString aMimeType); */
  NS_SCRIPTABLE NS_IMETHOD EncodeImage(imgIContainer *aContainer, const nsACString & aMimeType, nsIInputStream **_retval NS_OUTPARAM) = 0;

  /**
     * encodeScaledImage
     * Caller provides an image container, and the mime type it should be
     * encoded to. We return an input stream for the encoded image data.
     * The encoded image is scaled to the specified dimensions.
     *
     * @param aContainer
     *        An image container.
     * @param aMimeType
     *        Type of encoded image desired (eg "image/png").
     * @param aWidth, aHeight
     *        The size (in pixels) desired for the resulting image.
     */
  /* nsIInputStream encodeScaledImage (in imgIContainer aContainer, in ACString aMimeType, in long aWidth, in long aHeight); */
  NS_SCRIPTABLE NS_IMETHOD EncodeScaledImage(imgIContainer *aContainer, const nsACString & aMimeType, PRInt32 aWidth, PRInt32 aHeight, nsIInputStream **_retval NS_OUTPARAM) = 0;

};

  NS_DEFINE_STATIC_IID_ACCESSOR(imgITools, IMGITOOLS_IID)

/* Use this macro when declaring classes that implement this interface. */
#define NS_DECL_IMGITOOLS \
  NS_SCRIPTABLE NS_IMETHOD DecodeImageData(nsIInputStream *aStream, const nsACString & aMimeType, imgIContainer **aContainer NS_INOUTPARAM); \
  NS_SCRIPTABLE NS_IMETHOD EncodeImage(imgIContainer *aContainer, const nsACString & aMimeType, nsIInputStream **_retval NS_OUTPARAM); \
  NS_SCRIPTABLE NS_IMETHOD EncodeScaledImage(imgIContainer *aContainer, const nsACString & aMimeType, PRInt32 aWidth, PRInt32 aHeight, nsIInputStream **_retval NS_OUTPARAM); 

/* Use this macro to declare functions that forward the behavior of this interface to another object. */
#define NS_FORWARD_IMGITOOLS(_to) \
  NS_SCRIPTABLE NS_IMETHOD DecodeImageData(nsIInputStream *aStream, const nsACString & aMimeType, imgIContainer **aContainer NS_INOUTPARAM) { return _to DecodeImageData(aStream, aMimeType, aContainer); } \
  NS_SCRIPTABLE NS_IMETHOD EncodeImage(imgIContainer *aContainer, const nsACString & aMimeType, nsIInputStream **_retval NS_OUTPARAM) { return _to EncodeImage(aContainer, aMimeType, _retval); } \
  NS_SCRIPTABLE NS_IMETHOD EncodeScaledImage(imgIContainer *aContainer, const nsACString & aMimeType, PRInt32 aWidth, PRInt32 aHeight, nsIInputStream **_retval NS_OUTPARAM) { return _to EncodeScaledImage(aContainer, aMimeType, aWidth, aHeight, _retval); } 

/* Use this macro to declare functions that forward the behavior of this interface to another object in a safe way. */
#define NS_FORWARD_SAFE_IMGITOOLS(_to) \
  NS_SCRIPTABLE NS_IMETHOD DecodeImageData(nsIInputStream *aStream, const nsACString & aMimeType, imgIContainer **aContainer NS_INOUTPARAM) { return !_to ? NS_ERROR_NULL_POINTER : _to->DecodeImageData(aStream, aMimeType, aContainer); } \
  NS_SCRIPTABLE NS_IMETHOD EncodeImage(imgIContainer *aContainer, const nsACString & aMimeType, nsIInputStream **_retval NS_OUTPARAM) { return !_to ? NS_ERROR_NULL_POINTER : _to->EncodeImage(aContainer, aMimeType, _retval); } \
  NS_SCRIPTABLE NS_IMETHOD EncodeScaledImage(imgIContainer *aContainer, const nsACString & aMimeType, PRInt32 aWidth, PRInt32 aHeight, nsIInputStream **_retval NS_OUTPARAM) { return !_to ? NS_ERROR_NULL_POINTER : _to->EncodeScaledImage(aContainer, aMimeType, aWidth, aHeight, _retval); } 

#if 0
/* Use the code below as a template for the implementation class for this interface. */

/* Header file */
class _MYCLASS_ : public imgITools
{
public:
  NS_DECL_ISUPPORTS
  NS_DECL_IMGITOOLS

  _MYCLASS_();

private:
  ~_MYCLASS_();

protected:
  /* additional members */
};

/* Implementation file */
NS_IMPL_ISUPPORTS1(_MYCLASS_, imgITools)

_MYCLASS_::_MYCLASS_()
{
  /* member initializers and constructor code */
}

_MYCLASS_::~_MYCLASS_()
{
  /* destructor code */
}

/* void decodeImageData (in nsIInputStream aStream, in ACString aMimeType, inout imgIContainer aContainer); */
NS_IMETHODIMP _MYCLASS_::DecodeImageData(nsIInputStream *aStream, const nsACString & aMimeType, imgIContainer **aContainer NS_INOUTPARAM)
{
    return NS_ERROR_NOT_IMPLEMENTED;
}

/* nsIInputStream encodeImage (in imgIContainer aContainer, in ACString aMimeType); */
NS_IMETHODIMP _MYCLASS_::EncodeImage(imgIContainer *aContainer, const nsACString & aMimeType, nsIInputStream **_retval NS_OUTPARAM)
{
    return NS_ERROR_NOT_IMPLEMENTED;
}

/* nsIInputStream encodeScaledImage (in imgIContainer aContainer, in ACString aMimeType, in long aWidth, in long aHeight); */
NS_IMETHODIMP _MYCLASS_::EncodeScaledImage(imgIContainer *aContainer, const nsACString & aMimeType, PRInt32 aWidth, PRInt32 aHeight, nsIInputStream **_retval NS_OUTPARAM)
{
    return NS_ERROR_NOT_IMPLEMENTED;
}

/* End of implementation class template. */
#endif


#endif /* __gen_imgITools_h__ */
