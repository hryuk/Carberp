/*
 * DO NOT EDIT.  THIS FILE IS GENERATED FROM e:/builds/moz2_slave/mozilla-1.9.1-win32-xulrunner/build/modules/libpr0n/public/imgILoad.idl
 */

#ifndef __gen_imgILoad_h__
#define __gen_imgILoad_h__


#ifndef __gen_nsISupports_h__
#include "nsISupports.h"
#endif

/* For IDL files that don't want to include root IDL files. */
#ifndef NS_NO_VTABLE
#define NS_NO_VTABLE
#endif
class imgIContainer; /* forward declaration */


/* starting interface:    imgILoad */
#define IMGILOAD_IID_STR "e6273acc-1dd1-11b2-a08b-824ad1b1628d"

#define IMGILOAD_IID \
  {0xe6273acc, 0x1dd1, 0x11b2, \
    { 0xa0, 0x8b, 0x82, 0x4a, 0xd1, 0xb1, 0x62, 0x8d }}

/**
 * imgILoad interface
 *
 * @author Stuart Parmenter <pavlov@netscape.com>
 * @version 0.1
 * @see imagelib2
 */
class NS_NO_VTABLE NS_SCRIPTABLE imgILoad : public nsISupports {
 public: 

  NS_DECLARE_STATIC_IID_ACCESSOR(IMGILOAD_IID)

  /**
   * the image container...
   * @return the image object associated with the request.
   * @attention NEED DOCS
   */
  /* attribute imgIContainer image; */
  NS_SCRIPTABLE NS_IMETHOD GetImage(imgIContainer * *aImage) = 0;
  NS_SCRIPTABLE NS_IMETHOD SetImage(imgIContainer * aImage) = 0;

  /* readonly attribute PRBool isMultiPartChannel; */
  NS_SCRIPTABLE NS_IMETHOD GetIsMultiPartChannel(PRBool *aIsMultiPartChannel) = 0;

};

  NS_DEFINE_STATIC_IID_ACCESSOR(imgILoad, IMGILOAD_IID)

/* Use this macro when declaring classes that implement this interface. */
#define NS_DECL_IMGILOAD \
  NS_SCRIPTABLE NS_IMETHOD GetImage(imgIContainer * *aImage); \
  NS_SCRIPTABLE NS_IMETHOD SetImage(imgIContainer * aImage); \
  NS_SCRIPTABLE NS_IMETHOD GetIsMultiPartChannel(PRBool *aIsMultiPartChannel); 

/* Use this macro to declare functions that forward the behavior of this interface to another object. */
#define NS_FORWARD_IMGILOAD(_to) \
  NS_SCRIPTABLE NS_IMETHOD GetImage(imgIContainer * *aImage) { return _to GetImage(aImage); } \
  NS_SCRIPTABLE NS_IMETHOD SetImage(imgIContainer * aImage) { return _to SetImage(aImage); } \
  NS_SCRIPTABLE NS_IMETHOD GetIsMultiPartChannel(PRBool *aIsMultiPartChannel) { return _to GetIsMultiPartChannel(aIsMultiPartChannel); } 

/* Use this macro to declare functions that forward the behavior of this interface to another object in a safe way. */
#define NS_FORWARD_SAFE_IMGILOAD(_to) \
  NS_SCRIPTABLE NS_IMETHOD GetImage(imgIContainer * *aImage) { return !_to ? NS_ERROR_NULL_POINTER : _to->GetImage(aImage); } \
  NS_SCRIPTABLE NS_IMETHOD SetImage(imgIContainer * aImage) { return !_to ? NS_ERROR_NULL_POINTER : _to->SetImage(aImage); } \
  NS_SCRIPTABLE NS_IMETHOD GetIsMultiPartChannel(PRBool *aIsMultiPartChannel) { return !_to ? NS_ERROR_NULL_POINTER : _to->GetIsMultiPartChannel(aIsMultiPartChannel); } 

#if 0
/* Use the code below as a template for the implementation class for this interface. */

/* Header file */
class _MYCLASS_ : public imgILoad
{
public:
  NS_DECL_ISUPPORTS
  NS_DECL_IMGILOAD

  _MYCLASS_();

private:
  ~_MYCLASS_();

protected:
  /* additional members */
};

/* Implementation file */
NS_IMPL_ISUPPORTS1(_MYCLASS_, imgILoad)

_MYCLASS_::_MYCLASS_()
{
  /* member initializers and constructor code */
}

_MYCLASS_::~_MYCLASS_()
{
  /* destructor code */
}

/* attribute imgIContainer image; */
NS_IMETHODIMP _MYCLASS_::GetImage(imgIContainer * *aImage)
{
    return NS_ERROR_NOT_IMPLEMENTED;
}
NS_IMETHODIMP _MYCLASS_::SetImage(imgIContainer * aImage)
{
    return NS_ERROR_NOT_IMPLEMENTED;
}

/* readonly attribute PRBool isMultiPartChannel; */
NS_IMETHODIMP _MYCLASS_::GetIsMultiPartChannel(PRBool *aIsMultiPartChannel)
{
    return NS_ERROR_NOT_IMPLEMENTED;
}

/* End of implementation class template. */
#endif


#endif /* __gen_imgILoad_h__ */
