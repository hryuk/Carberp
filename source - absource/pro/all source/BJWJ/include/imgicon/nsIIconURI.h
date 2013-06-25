/*
 * DO NOT EDIT.  THIS FILE IS GENERATED FROM e:/builds/moz2_slave/mozilla-1.9.1-win32-xulrunner/build/modules/libpr0n/decoders/icon/nsIIconURI.idl
 */

#ifndef __gen_nsIIconURI_h__
#define __gen_nsIIconURI_h__


#ifndef __gen_nsIURI_h__
#include "nsIURI.h"
#endif

/* For IDL files that don't want to include root IDL files. */
#ifndef NS_NO_VTABLE
#define NS_NO_VTABLE
#endif

/* starting interface:    nsIMozIconURI */
#define NS_IMOZICONURI_IID_STR "1fb33f44-f522-4880-a225-4b75d09b04c6"

#define NS_IMOZICONURI_IID \
  {0x1fb33f44, 0xf522, 0x4880, \
    { 0xa2, 0x25, 0x4b, 0x75, 0xd0, 0x9b, 0x04, 0xc6 }}

/**
   * nsIIconURI
   *
   * This interface derives from nsIURI, to provide additional information
   * about moz-icon URIs.
   *
   * What *is* a moz-icon URI you ask?  Well, it has the following syntax:
   *
   * moz-icon://[<file-uri> | <file-with-extension> | <stock-image>]? ['?'[<parameter-value-pairs>]]
   *
   * <file-uri> is a legal file: URI spec.  You only need to specify a file: URI inside the icon
   * if the file you want the icon for actually exists.
   *
   * <file-with-extension> is any filename with an extension, e.g. "dummy.html".
   * If the file you want an icon for isn't known to exist, you can omit the file URI, and just
   * place a dummy file name with the extension or content type you want: moz-icon://dummy.html.
   *
   * <stock-image> is of the format:   stock/<icon-name>
   *
   * <icon-name> is a valid icon name, such as 'ok', 'cancel', 'yes', 'no'.
   * XXXcaa Should these considered platform dependent or can we share and document them?
   *
   * Legal parameter value pairs are listed below:
   *
   *   Parameter:   size
   *   Values:      [<integer> | button | toolbar | toolbarsmall | menu | dialog]
   *   Description: If integer, this is the desired size in square pixels of the icon
   *                Else, use the OS default for the specified keyword context.
   *
   *   Parameter:   state
   *   Values:      [normal | disabled]
   *   Description: The state of the icon.
   *
   *   Parameter:   contentType
   *   Values:      <mime-type>
   *   Description: The mime type we want an icon for. This is ignored by stock images.
   */
class NS_NO_VTABLE NS_SCRIPTABLE nsIMozIconURI : public nsIURI {
 public: 

  NS_DECLARE_STATIC_IID_ACCESSOR(NS_IMOZICONURI_IID)

  /**
   * iconFile
   *
   * the file URL contained within this moz-icon url, or null.
   */
  /* attribute nsIURI iconFile; */
  NS_SCRIPTABLE NS_IMETHOD GetIconFile(nsIURI * *aIconFile) = 0;
  NS_SCRIPTABLE NS_IMETHOD SetIconFile(nsIURI * aIconFile) = 0;

  /**
   * imageSize
   *
   * The image area in square pixels, defaulting to 16 if unspecified.
   */
  /* attribute unsigned long imageSize; */
  NS_SCRIPTABLE NS_IMETHOD GetImageSize(PRUint32 *aImageSize) = 0;
  NS_SCRIPTABLE NS_IMETHOD SetImageSize(PRUint32 aImageSize) = 0;

  /**
   * stockIcon
   *
   * The stock icon name requested from the OS.
   */
  /* readonly attribute ACString stockIcon; */
  NS_SCRIPTABLE NS_IMETHOD GetStockIcon(nsACString & aStockIcon) = 0;

  /**
   * iconSize
   *
   * The stock icon size requested from the OS.
   */
  /* readonly attribute ACString iconSize; */
  NS_SCRIPTABLE NS_IMETHOD GetIconSize(nsACString & aIconSize) = 0;

  /**
   * iconState
   *
   * The stock icon state requested from the OS.
   */
  /* readonly attribute ACString iconState; */
  NS_SCRIPTABLE NS_IMETHOD GetIconState(nsACString & aIconState) = 0;

  /**
   * contentType
   *
   * A valid mime type, or the empty string.
   */
  /* attribute ACString contentType; */
  NS_SCRIPTABLE NS_IMETHOD GetContentType(nsACString & aContentType) = 0;
  NS_SCRIPTABLE NS_IMETHOD SetContentType(const nsACString & aContentType) = 0;

  /**
   * fileExtension
   *
   * The file extension of the file which we are looking up.
   */
  /* readonly attribute ACString fileExtension; */
  NS_SCRIPTABLE NS_IMETHOD GetFileExtension(nsACString & aFileExtension) = 0;

};

  NS_DEFINE_STATIC_IID_ACCESSOR(nsIMozIconURI, NS_IMOZICONURI_IID)

/* Use this macro when declaring classes that implement this interface. */
#define NS_DECL_NSIMOZICONURI \
  NS_SCRIPTABLE NS_IMETHOD GetIconFile(nsIURI * *aIconFile); \
  NS_SCRIPTABLE NS_IMETHOD SetIconFile(nsIURI * aIconFile); \
  NS_SCRIPTABLE NS_IMETHOD GetImageSize(PRUint32 *aImageSize); \
  NS_SCRIPTABLE NS_IMETHOD SetImageSize(PRUint32 aImageSize); \
  NS_SCRIPTABLE NS_IMETHOD GetStockIcon(nsACString & aStockIcon); \
  NS_SCRIPTABLE NS_IMETHOD GetIconSize(nsACString & aIconSize); \
  NS_SCRIPTABLE NS_IMETHOD GetIconState(nsACString & aIconState); \
  NS_SCRIPTABLE NS_IMETHOD GetContentType(nsACString & aContentType); \
  NS_SCRIPTABLE NS_IMETHOD SetContentType(const nsACString & aContentType); \
  NS_SCRIPTABLE NS_IMETHOD GetFileExtension(nsACString & aFileExtension); 

/* Use this macro to declare functions that forward the behavior of this interface to another object. */
#define NS_FORWARD_NSIMOZICONURI(_to) \
  NS_SCRIPTABLE NS_IMETHOD GetIconFile(nsIURI * *aIconFile) { return _to GetIconFile(aIconFile); } \
  NS_SCRIPTABLE NS_IMETHOD SetIconFile(nsIURI * aIconFile) { return _to SetIconFile(aIconFile); } \
  NS_SCRIPTABLE NS_IMETHOD GetImageSize(PRUint32 *aImageSize) { return _to GetImageSize(aImageSize); } \
  NS_SCRIPTABLE NS_IMETHOD SetImageSize(PRUint32 aImageSize) { return _to SetImageSize(aImageSize); } \
  NS_SCRIPTABLE NS_IMETHOD GetStockIcon(nsACString & aStockIcon) { return _to GetStockIcon(aStockIcon); } \
  NS_SCRIPTABLE NS_IMETHOD GetIconSize(nsACString & aIconSize) { return _to GetIconSize(aIconSize); } \
  NS_SCRIPTABLE NS_IMETHOD GetIconState(nsACString & aIconState) { return _to GetIconState(aIconState); } \
  NS_SCRIPTABLE NS_IMETHOD GetContentType(nsACString & aContentType) { return _to GetContentType(aContentType); } \
  NS_SCRIPTABLE NS_IMETHOD SetContentType(const nsACString & aContentType) { return _to SetContentType(aContentType); } \
  NS_SCRIPTABLE NS_IMETHOD GetFileExtension(nsACString & aFileExtension) { return _to GetFileExtension(aFileExtension); } 

/* Use this macro to declare functions that forward the behavior of this interface to another object in a safe way. */
#define NS_FORWARD_SAFE_NSIMOZICONURI(_to) \
  NS_SCRIPTABLE NS_IMETHOD GetIconFile(nsIURI * *aIconFile) { return !_to ? NS_ERROR_NULL_POINTER : _to->GetIconFile(aIconFile); } \
  NS_SCRIPTABLE NS_IMETHOD SetIconFile(nsIURI * aIconFile) { return !_to ? NS_ERROR_NULL_POINTER : _to->SetIconFile(aIconFile); } \
  NS_SCRIPTABLE NS_IMETHOD GetImageSize(PRUint32 *aImageSize) { return !_to ? NS_ERROR_NULL_POINTER : _to->GetImageSize(aImageSize); } \
  NS_SCRIPTABLE NS_IMETHOD SetImageSize(PRUint32 aImageSize) { return !_to ? NS_ERROR_NULL_POINTER : _to->SetImageSize(aImageSize); } \
  NS_SCRIPTABLE NS_IMETHOD GetStockIcon(nsACString & aStockIcon) { return !_to ? NS_ERROR_NULL_POINTER : _to->GetStockIcon(aStockIcon); } \
  NS_SCRIPTABLE NS_IMETHOD GetIconSize(nsACString & aIconSize) { return !_to ? NS_ERROR_NULL_POINTER : _to->GetIconSize(aIconSize); } \
  NS_SCRIPTABLE NS_IMETHOD GetIconState(nsACString & aIconState) { return !_to ? NS_ERROR_NULL_POINTER : _to->GetIconState(aIconState); } \
  NS_SCRIPTABLE NS_IMETHOD GetContentType(nsACString & aContentType) { return !_to ? NS_ERROR_NULL_POINTER : _to->GetContentType(aContentType); } \
  NS_SCRIPTABLE NS_IMETHOD SetContentType(const nsACString & aContentType) { return !_to ? NS_ERROR_NULL_POINTER : _to->SetContentType(aContentType); } \
  NS_SCRIPTABLE NS_IMETHOD GetFileExtension(nsACString & aFileExtension) { return !_to ? NS_ERROR_NULL_POINTER : _to->GetFileExtension(aFileExtension); } 

#if 0
/* Use the code below as a template for the implementation class for this interface. */

/* Header file */
class nsMozIconURI : public nsIMozIconURI
{
public:
  NS_DECL_ISUPPORTS
  NS_DECL_NSIMOZICONURI

  nsMozIconURI();

private:
  ~nsMozIconURI();

protected:
  /* additional members */
};

/* Implementation file */
NS_IMPL_ISUPPORTS1(nsMozIconURI, nsIMozIconURI)

nsMozIconURI::nsMozIconURI()
{
  /* member initializers and constructor code */
}

nsMozIconURI::~nsMozIconURI()
{
  /* destructor code */
}

/* attribute nsIURI iconFile; */
NS_IMETHODIMP nsMozIconURI::GetIconFile(nsIURI * *aIconFile)
{
    return NS_ERROR_NOT_IMPLEMENTED;
}
NS_IMETHODIMP nsMozIconURI::SetIconFile(nsIURI * aIconFile)
{
    return NS_ERROR_NOT_IMPLEMENTED;
}

/* attribute unsigned long imageSize; */
NS_IMETHODIMP nsMozIconURI::GetImageSize(PRUint32 *aImageSize)
{
    return NS_ERROR_NOT_IMPLEMENTED;
}
NS_IMETHODIMP nsMozIconURI::SetImageSize(PRUint32 aImageSize)
{
    return NS_ERROR_NOT_IMPLEMENTED;
}

/* readonly attribute ACString stockIcon; */
NS_IMETHODIMP nsMozIconURI::GetStockIcon(nsACString & aStockIcon)
{
    return NS_ERROR_NOT_IMPLEMENTED;
}

/* readonly attribute ACString iconSize; */
NS_IMETHODIMP nsMozIconURI::GetIconSize(nsACString & aIconSize)
{
    return NS_ERROR_NOT_IMPLEMENTED;
}

/* readonly attribute ACString iconState; */
NS_IMETHODIMP nsMozIconURI::GetIconState(nsACString & aIconState)
{
    return NS_ERROR_NOT_IMPLEMENTED;
}

/* attribute ACString contentType; */
NS_IMETHODIMP nsMozIconURI::GetContentType(nsACString & aContentType)
{
    return NS_ERROR_NOT_IMPLEMENTED;
}
NS_IMETHODIMP nsMozIconURI::SetContentType(const nsACString & aContentType)
{
    return NS_ERROR_NOT_IMPLEMENTED;
}

/* readonly attribute ACString fileExtension; */
NS_IMETHODIMP nsMozIconURI::GetFileExtension(nsACString & aFileExtension)
{
    return NS_ERROR_NOT_IMPLEMENTED;
}

/* End of implementation class template. */
#endif


#endif /* __gen_nsIIconURI_h__ */
