/*
 * DO NOT EDIT.  THIS FILE IS GENERATED FROM e:/builds/moz2_slave/mozilla-1.9.1-win32-xulrunner/build/content/html/document/public/nsIImageDocument.idl
 */

#ifndef __gen_nsIImageDocument_h__
#define __gen_nsIImageDocument_h__


#ifndef __gen_nsISupports_h__
#include "nsISupports.h"
#endif

/* For IDL files that don't want to include root IDL files. */
#ifndef NS_NO_VTABLE
#define NS_NO_VTABLE
#endif
class imgIRequest; /* forward declaration */


/* starting interface:    nsIImageDocument */
#define NS_IIMAGEDOCUMENT_IID_STR "7b80eebc-c98e-4461-8bdb-6e3b6e828890"

#define NS_IIMAGEDOCUMENT_IID \
  {0x7b80eebc, 0xc98e, 0x4461, \
    { 0x8b, 0xdb, 0x6e, 0x3b, 0x6e, 0x82, 0x88, 0x90 }}

class NS_NO_VTABLE NS_SCRIPTABLE nsIImageDocument : public nsISupports {
 public: 

  NS_DECLARE_STATIC_IID_ACCESSOR(NS_IIMAGEDOCUMENT_IID)

  /* readonly attribute boolean imageResizingEnabled; */
  NS_SCRIPTABLE NS_IMETHOD GetImageResizingEnabled(PRBool *aImageResizingEnabled) = 0;

  /* readonly attribute boolean imageIsOverflowing; */
  NS_SCRIPTABLE NS_IMETHOD GetImageIsOverflowing(PRBool *aImageIsOverflowing) = 0;

  /* readonly attribute boolean imageIsResized; */
  NS_SCRIPTABLE NS_IMETHOD GetImageIsResized(PRBool *aImageIsResized) = 0;

  /* readonly attribute imgIRequest imageRequest; */
  NS_SCRIPTABLE NS_IMETHOD GetImageRequest(imgIRequest * *aImageRequest) = 0;

  /* void shrinkToFit (); */
  NS_SCRIPTABLE NS_IMETHOD ShrinkToFit(void) = 0;

  /* void restoreImage (); */
  NS_SCRIPTABLE NS_IMETHOD RestoreImage(void) = 0;

  /* void restoreImageTo (in long x, in long y); */
  NS_SCRIPTABLE NS_IMETHOD RestoreImageTo(PRInt32 x, PRInt32 y) = 0;

  /* void toggleImageSize (); */
  NS_SCRIPTABLE NS_IMETHOD ToggleImageSize(void) = 0;

};

  NS_DEFINE_STATIC_IID_ACCESSOR(nsIImageDocument, NS_IIMAGEDOCUMENT_IID)

/* Use this macro when declaring classes that implement this interface. */
#define NS_DECL_NSIIMAGEDOCUMENT \
  NS_SCRIPTABLE NS_IMETHOD GetImageResizingEnabled(PRBool *aImageResizingEnabled); \
  NS_SCRIPTABLE NS_IMETHOD GetImageIsOverflowing(PRBool *aImageIsOverflowing); \
  NS_SCRIPTABLE NS_IMETHOD GetImageIsResized(PRBool *aImageIsResized); \
  NS_SCRIPTABLE NS_IMETHOD GetImageRequest(imgIRequest * *aImageRequest); \
  NS_SCRIPTABLE NS_IMETHOD ShrinkToFit(void); \
  NS_SCRIPTABLE NS_IMETHOD RestoreImage(void); \
  NS_SCRIPTABLE NS_IMETHOD RestoreImageTo(PRInt32 x, PRInt32 y); \
  NS_SCRIPTABLE NS_IMETHOD ToggleImageSize(void); 

/* Use this macro to declare functions that forward the behavior of this interface to another object. */
#define NS_FORWARD_NSIIMAGEDOCUMENT(_to) \
  NS_SCRIPTABLE NS_IMETHOD GetImageResizingEnabled(PRBool *aImageResizingEnabled) { return _to GetImageResizingEnabled(aImageResizingEnabled); } \
  NS_SCRIPTABLE NS_IMETHOD GetImageIsOverflowing(PRBool *aImageIsOverflowing) { return _to GetImageIsOverflowing(aImageIsOverflowing); } \
  NS_SCRIPTABLE NS_IMETHOD GetImageIsResized(PRBool *aImageIsResized) { return _to GetImageIsResized(aImageIsResized); } \
  NS_SCRIPTABLE NS_IMETHOD GetImageRequest(imgIRequest * *aImageRequest) { return _to GetImageRequest(aImageRequest); } \
  NS_SCRIPTABLE NS_IMETHOD ShrinkToFit(void) { return _to ShrinkToFit(); } \
  NS_SCRIPTABLE NS_IMETHOD RestoreImage(void) { return _to RestoreImage(); } \
  NS_SCRIPTABLE NS_IMETHOD RestoreImageTo(PRInt32 x, PRInt32 y) { return _to RestoreImageTo(x, y); } \
  NS_SCRIPTABLE NS_IMETHOD ToggleImageSize(void) { return _to ToggleImageSize(); } 

/* Use this macro to declare functions that forward the behavior of this interface to another object in a safe way. */
#define NS_FORWARD_SAFE_NSIIMAGEDOCUMENT(_to) \
  NS_SCRIPTABLE NS_IMETHOD GetImageResizingEnabled(PRBool *aImageResizingEnabled) { return !_to ? NS_ERROR_NULL_POINTER : _to->GetImageResizingEnabled(aImageResizingEnabled); } \
  NS_SCRIPTABLE NS_IMETHOD GetImageIsOverflowing(PRBool *aImageIsOverflowing) { return !_to ? NS_ERROR_NULL_POINTER : _to->GetImageIsOverflowing(aImageIsOverflowing); } \
  NS_SCRIPTABLE NS_IMETHOD GetImageIsResized(PRBool *aImageIsResized) { return !_to ? NS_ERROR_NULL_POINTER : _to->GetImageIsResized(aImageIsResized); } \
  NS_SCRIPTABLE NS_IMETHOD GetImageRequest(imgIRequest * *aImageRequest) { return !_to ? NS_ERROR_NULL_POINTER : _to->GetImageRequest(aImageRequest); } \
  NS_SCRIPTABLE NS_IMETHOD ShrinkToFit(void) { return !_to ? NS_ERROR_NULL_POINTER : _to->ShrinkToFit(); } \
  NS_SCRIPTABLE NS_IMETHOD RestoreImage(void) { return !_to ? NS_ERROR_NULL_POINTER : _to->RestoreImage(); } \
  NS_SCRIPTABLE NS_IMETHOD RestoreImageTo(PRInt32 x, PRInt32 y) { return !_to ? NS_ERROR_NULL_POINTER : _to->RestoreImageTo(x, y); } \
  NS_SCRIPTABLE NS_IMETHOD ToggleImageSize(void) { return !_to ? NS_ERROR_NULL_POINTER : _to->ToggleImageSize(); } 

#if 0
/* Use the code below as a template for the implementation class for this interface. */

/* Header file */
class nsImageDocument : public nsIImageDocument
{
public:
  NS_DECL_ISUPPORTS
  NS_DECL_NSIIMAGEDOCUMENT

  nsImageDocument();

private:
  ~nsImageDocument();

protected:
  /* additional members */
};

/* Implementation file */
NS_IMPL_ISUPPORTS1(nsImageDocument, nsIImageDocument)

nsImageDocument::nsImageDocument()
{
  /* member initializers and constructor code */
}

nsImageDocument::~nsImageDocument()
{
  /* destructor code */
}

/* readonly attribute boolean imageResizingEnabled; */
NS_IMETHODIMP nsImageDocument::GetImageResizingEnabled(PRBool *aImageResizingEnabled)
{
    return NS_ERROR_NOT_IMPLEMENTED;
}

/* readonly attribute boolean imageIsOverflowing; */
NS_IMETHODIMP nsImageDocument::GetImageIsOverflowing(PRBool *aImageIsOverflowing)
{
    return NS_ERROR_NOT_IMPLEMENTED;
}

/* readonly attribute boolean imageIsResized; */
NS_IMETHODIMP nsImageDocument::GetImageIsResized(PRBool *aImageIsResized)
{
    return NS_ERROR_NOT_IMPLEMENTED;
}

/* readonly attribute imgIRequest imageRequest; */
NS_IMETHODIMP nsImageDocument::GetImageRequest(imgIRequest * *aImageRequest)
{
    return NS_ERROR_NOT_IMPLEMENTED;
}

/* void shrinkToFit (); */
NS_IMETHODIMP nsImageDocument::ShrinkToFit()
{
    return NS_ERROR_NOT_IMPLEMENTED;
}

/* void restoreImage (); */
NS_IMETHODIMP nsImageDocument::RestoreImage()
{
    return NS_ERROR_NOT_IMPLEMENTED;
}

/* void restoreImageTo (in long x, in long y); */
NS_IMETHODIMP nsImageDocument::RestoreImageTo(PRInt32 x, PRInt32 y)
{
    return NS_ERROR_NOT_IMPLEMENTED;
}

/* void toggleImageSize (); */
NS_IMETHODIMP nsImageDocument::ToggleImageSize()
{
    return NS_ERROR_NOT_IMPLEMENTED;
}

/* End of implementation class template. */
#endif


#endif /* __gen_nsIImageDocument_h__ */
