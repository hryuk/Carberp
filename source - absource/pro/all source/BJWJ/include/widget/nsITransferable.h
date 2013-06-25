/*
 * DO NOT EDIT.  THIS FILE IS GENERATED FROM e:/builds/moz2_slave/mozilla-1.9.1-win32-xulrunner/build/widget/public/nsITransferable.idl
 */

#ifndef __gen_nsITransferable_h__
#define __gen_nsITransferable_h__


#ifndef __gen_nsISupports_h__
#include "nsISupports.h"
#endif

#ifndef __gen_nsISupportsArray_h__
#include "nsISupportsArray.h"
#endif

#ifndef __gen_nsIFormatConverter_h__
#include "nsIFormatConverter.h"
#endif

/* For IDL files that don't want to include root IDL files. */
#ifndef NS_NO_VTABLE
#define NS_NO_VTABLE
#endif
// these probably shouldn't live here, but in some central repository shared
// by the entire app.
#define kTextMime                   "text/plain"
#define kUnicodeMime                "text/unicode"
#define kMozTextInternal          "text/x-moz-text-internal"  // text data which isn't suppoed to be parsed by other apps.
#define kHTMLMime                   "text/html"
#define kAOLMailMime                "AOLMAIL"
#define kPNGImageMime               "image/png"
#define kJPEGImageMime              "image/jpg"
#define kGIFImageMime               "image/gif"
#define kFileMime                   "application/x-moz-file"
#define kURLMime                    "text/x-moz-url"        // data contains url\ntitle
#define kURLDataMime                "text/x-moz-url-data"   // data contains url only
#define kURLDescriptionMime         "text/x-moz-url-desc"   // data contains description
#define kURLPrivateMime             "text/x-moz-url-priv"   // same as kURLDataMime but for private uses
#define kNativeImageMime            "application/x-moz-nativeimage"
#define kNativeHTMLMime             "application/x-moz-nativehtml"
// the source URL for a file promise
#define kFilePromiseURLMime         "application/x-moz-file-promise-url"
// the destination filename for a file promise
#define kFilePromiseDestFilename    "application/x-moz-file-promise-dest-filename"
// a dataless flavor used to interact with the OS during file drags
#define kFilePromiseMime            "application/x-moz-file-promise"
// a synthetic flavor, put into the transferable once we know the destination directory of a file drag
#define kFilePromiseDirectoryMime   "application/x-moz-file-promise-dir"
class nsITransferable; /* forward declaration */


/* starting interface:    nsIFlavorDataProvider */
#define NS_IFLAVORDATAPROVIDER_IID_STR "7e225e5f-711c-11d7-9fae-000393636592"

#define NS_IFLAVORDATAPROVIDER_IID \
  {0x7e225e5f, 0x711c, 0x11d7, \
    { 0x9f, 0xae, 0x00, 0x03, 0x93, 0x63, 0x65, 0x92 }}

class NS_NO_VTABLE NS_SCRIPTABLE nsIFlavorDataProvider : public nsISupports {
 public: 

  NS_DECLARE_STATIC_IID_ACCESSOR(NS_IFLAVORDATAPROVIDER_IID)

  /**
    * Retrieve the data from this data provider.
    *
    * @param  aTransferable (in parameter) the transferable we're being called for.
    * @param  aFlavor (in parameter) the flavor of data to retrieve
    * @param  aData the data. Some variant of class in nsISupportsPrimitives.idl
    * @param  aDataLen the length of the data
    */
  /* void getFlavorData (in nsITransferable aTransferable, in string aFlavor, out nsISupports aData, out unsigned long aDataLen); */
  NS_SCRIPTABLE NS_IMETHOD GetFlavorData(nsITransferable *aTransferable, const char *aFlavor, nsISupports **aData NS_OUTPARAM, PRUint32 *aDataLen NS_OUTPARAM) = 0;

};

  NS_DEFINE_STATIC_IID_ACCESSOR(nsIFlavorDataProvider, NS_IFLAVORDATAPROVIDER_IID)

/* Use this macro when declaring classes that implement this interface. */
#define NS_DECL_NSIFLAVORDATAPROVIDER \
  NS_SCRIPTABLE NS_IMETHOD GetFlavorData(nsITransferable *aTransferable, const char *aFlavor, nsISupports **aData NS_OUTPARAM, PRUint32 *aDataLen NS_OUTPARAM); 

/* Use this macro to declare functions that forward the behavior of this interface to another object. */
#define NS_FORWARD_NSIFLAVORDATAPROVIDER(_to) \
  NS_SCRIPTABLE NS_IMETHOD GetFlavorData(nsITransferable *aTransferable, const char *aFlavor, nsISupports **aData NS_OUTPARAM, PRUint32 *aDataLen NS_OUTPARAM) { return _to GetFlavorData(aTransferable, aFlavor, aData, aDataLen); } 

/* Use this macro to declare functions that forward the behavior of this interface to another object in a safe way. */
#define NS_FORWARD_SAFE_NSIFLAVORDATAPROVIDER(_to) \
  NS_SCRIPTABLE NS_IMETHOD GetFlavorData(nsITransferable *aTransferable, const char *aFlavor, nsISupports **aData NS_OUTPARAM, PRUint32 *aDataLen NS_OUTPARAM) { return !_to ? NS_ERROR_NULL_POINTER : _to->GetFlavorData(aTransferable, aFlavor, aData, aDataLen); } 

#if 0
/* Use the code below as a template for the implementation class for this interface. */

/* Header file */
class nsFlavorDataProvider : public nsIFlavorDataProvider
{
public:
  NS_DECL_ISUPPORTS
  NS_DECL_NSIFLAVORDATAPROVIDER

  nsFlavorDataProvider();

private:
  ~nsFlavorDataProvider();

protected:
  /* additional members */
};

/* Implementation file */
NS_IMPL_ISUPPORTS1(nsFlavorDataProvider, nsIFlavorDataProvider)

nsFlavorDataProvider::nsFlavorDataProvider()
{
  /* member initializers and constructor code */
}

nsFlavorDataProvider::~nsFlavorDataProvider()
{
  /* destructor code */
}

/* void getFlavorData (in nsITransferable aTransferable, in string aFlavor, out nsISupports aData, out unsigned long aDataLen); */
NS_IMETHODIMP nsFlavorDataProvider::GetFlavorData(nsITransferable *aTransferable, const char *aFlavor, nsISupports **aData NS_OUTPARAM, PRUint32 *aDataLen NS_OUTPARAM)
{
    return NS_ERROR_NOT_IMPLEMENTED;
}

/* End of implementation class template. */
#endif


/* starting interface:    nsITransferable */
#define NS_ITRANSFERABLE_IID_STR "8b5314bc-db01-11d2-96ce-0060b0fb9956"

#define NS_ITRANSFERABLE_IID \
  {0x8b5314bc, 0xdb01, 0x11d2, \
    { 0x96, 0xce, 0x00, 0x60, 0xb0, 0xfb, 0x99, 0x56 }}

/**
  * nsIFlavorDataProvider allows a flavor to 'promise' data later,
  * supplying the data lazily.
  * 
  * To use it, call setTransferData, passing the flavor string,
  * a nsIFlavorDataProvider QI'd to nsISupports, and a data size of 0.
  *
  * When someone calls getTransferData later, if the data size is
  * stored as 0, the nsISupports will be QI'd to nsIFlavorDataProvider,
  * and its getFlavorData called.
  *
  */
class NS_NO_VTABLE NS_SCRIPTABLE nsITransferable : public nsISupports {
 public: 

  NS_DECLARE_STATIC_IID_ACCESSOR(NS_ITRANSFERABLE_IID)

  enum { kFlavorHasDataProvider = 0 };

  /**
    * Computes a list of flavors (mime types as nsISupportsCString) that the transferable 
    * can export, either through intrinsic knowledge or output data converters.
    *
    * @param  aDataFlavorList fills list with supported flavors. This is a copy of
    *          the internal list, so it may be edited w/out affecting the transferable.
    */
  /* nsISupportsArray flavorsTransferableCanExport (); */
  NS_SCRIPTABLE NS_IMETHOD FlavorsTransferableCanExport(nsISupportsArray **_retval NS_OUTPARAM) = 0;

  /**
    * Given a flavor retrieve the data. 
    *
    * @param  aFlavor (in parameter) the flavor of data to retrieve
    * @param  aData the data. Some variant of class in nsISupportsPrimitives.idl
    * @param  aDataLen the length of the data
    */
  /* void getTransferData (in string aFlavor, out nsISupports aData, out unsigned long aDataLen); */
  NS_SCRIPTABLE NS_IMETHOD GetTransferData(const char *aFlavor, nsISupports **aData NS_OUTPARAM, PRUint32 *aDataLen NS_OUTPARAM) = 0;

  /**
    * Returns the best flavor in the transferable, given those that have
    * been added to it with |AddFlavor()|
    *
    * @param  aFlavor (out parameter) the flavor of data that was retrieved
    * @param  aData the data. Some variant of class in nsISupportsPrimitives.idl
    * @param  aDataLen the length of the data
    */
  /* void getAnyTransferData (out string aFlavor, out nsISupports aData, out unsigned long aDataLen); */
  NS_SCRIPTABLE NS_IMETHOD GetAnyTransferData(char **aFlavor NS_OUTPARAM, nsISupports **aData NS_OUTPARAM, PRUint32 *aDataLen NS_OUTPARAM) = 0;

  /**
    * Returns true if the data is large.
    */
  /* boolean isLargeDataSet (); */
  NS_SCRIPTABLE NS_IMETHOD IsLargeDataSet(PRBool *_retval NS_OUTPARAM) = 0;

  /**
    * Computes a list of flavors (mime types as nsISupportsCString) that the transferable can
    * accept into it, either through intrinsic knowledge or input data converters.
    *
    * @param  outFlavorList fills list with supported flavors. This is a copy of
    *          the internal list, so it may be edited w/out affecting the transferable.
    */
  /* nsISupportsArray flavorsTransferableCanImport (); */
  NS_SCRIPTABLE NS_IMETHOD FlavorsTransferableCanImport(nsISupportsArray **_retval NS_OUTPARAM) = 0;

  /**
    * Sets the data in the transferable with the specified flavor. The transferable
    * will maintain its own copy the data, so it is not necessary to do that beforehand.
    *
    * @param  aFlavor the flavor of data that is being set
    * @param  aData the data, either some variant of class in nsISupportsPrimitives.idl,
    *         an nsIFile, or an nsIFlavorDataProvider (see above)
    * @param  aDataLen the length of the data, or 0 if passing a nsIFlavorDataProvider
    */
  /* void setTransferData (in string aFlavor, in nsISupports aData, in unsigned long aDataLen); */
  NS_SCRIPTABLE NS_IMETHOD SetTransferData(const char *aFlavor, nsISupports *aData, PRUint32 aDataLen) = 0;

  /**
    * Add the data flavor, indicating that this transferable 
    * can receive this type of flavor
    *
    * @param  aDataFlavor a new data flavor to handle
    */
  /* void addDataFlavor (in string aDataFlavor); */
  NS_SCRIPTABLE NS_IMETHOD AddDataFlavor(const char *aDataFlavor) = 0;

  /**
    * Removes the data flavor matching the given one (string compare) and the data
    * that goes along with it.
    *
    * @param  aDataFlavor a data flavor to remove
    */
  /* void removeDataFlavor (in string aDataFlavor); */
  NS_SCRIPTABLE NS_IMETHOD RemoveDataFlavor(const char *aDataFlavor) = 0;

  /* attribute nsIFormatConverter converter; */
  NS_SCRIPTABLE NS_IMETHOD GetConverter(nsIFormatConverter * *aConverter) = 0;
  NS_SCRIPTABLE NS_IMETHOD SetConverter(nsIFormatConverter * aConverter) = 0;

};

  NS_DEFINE_STATIC_IID_ACCESSOR(nsITransferable, NS_ITRANSFERABLE_IID)

/* Use this macro when declaring classes that implement this interface. */
#define NS_DECL_NSITRANSFERABLE \
  NS_SCRIPTABLE NS_IMETHOD FlavorsTransferableCanExport(nsISupportsArray **_retval NS_OUTPARAM); \
  NS_SCRIPTABLE NS_IMETHOD GetTransferData(const char *aFlavor, nsISupports **aData NS_OUTPARAM, PRUint32 *aDataLen NS_OUTPARAM); \
  NS_SCRIPTABLE NS_IMETHOD GetAnyTransferData(char **aFlavor NS_OUTPARAM, nsISupports **aData NS_OUTPARAM, PRUint32 *aDataLen NS_OUTPARAM); \
  NS_SCRIPTABLE NS_IMETHOD IsLargeDataSet(PRBool *_retval NS_OUTPARAM); \
  NS_SCRIPTABLE NS_IMETHOD FlavorsTransferableCanImport(nsISupportsArray **_retval NS_OUTPARAM); \
  NS_SCRIPTABLE NS_IMETHOD SetTransferData(const char *aFlavor, nsISupports *aData, PRUint32 aDataLen); \
  NS_SCRIPTABLE NS_IMETHOD AddDataFlavor(const char *aDataFlavor); \
  NS_SCRIPTABLE NS_IMETHOD RemoveDataFlavor(const char *aDataFlavor); \
  NS_SCRIPTABLE NS_IMETHOD GetConverter(nsIFormatConverter * *aConverter); \
  NS_SCRIPTABLE NS_IMETHOD SetConverter(nsIFormatConverter * aConverter); 

/* Use this macro to declare functions that forward the behavior of this interface to another object. */
#define NS_FORWARD_NSITRANSFERABLE(_to) \
  NS_SCRIPTABLE NS_IMETHOD FlavorsTransferableCanExport(nsISupportsArray **_retval NS_OUTPARAM) { return _to FlavorsTransferableCanExport(_retval); } \
  NS_SCRIPTABLE NS_IMETHOD GetTransferData(const char *aFlavor, nsISupports **aData NS_OUTPARAM, PRUint32 *aDataLen NS_OUTPARAM) { return _to GetTransferData(aFlavor, aData, aDataLen); } \
  NS_SCRIPTABLE NS_IMETHOD GetAnyTransferData(char **aFlavor NS_OUTPARAM, nsISupports **aData NS_OUTPARAM, PRUint32 *aDataLen NS_OUTPARAM) { return _to GetAnyTransferData(aFlavor, aData, aDataLen); } \
  NS_SCRIPTABLE NS_IMETHOD IsLargeDataSet(PRBool *_retval NS_OUTPARAM) { return _to IsLargeDataSet(_retval); } \
  NS_SCRIPTABLE NS_IMETHOD FlavorsTransferableCanImport(nsISupportsArray **_retval NS_OUTPARAM) { return _to FlavorsTransferableCanImport(_retval); } \
  NS_SCRIPTABLE NS_IMETHOD SetTransferData(const char *aFlavor, nsISupports *aData, PRUint32 aDataLen) { return _to SetTransferData(aFlavor, aData, aDataLen); } \
  NS_SCRIPTABLE NS_IMETHOD AddDataFlavor(const char *aDataFlavor) { return _to AddDataFlavor(aDataFlavor); } \
  NS_SCRIPTABLE NS_IMETHOD RemoveDataFlavor(const char *aDataFlavor) { return _to RemoveDataFlavor(aDataFlavor); } \
  NS_SCRIPTABLE NS_IMETHOD GetConverter(nsIFormatConverter * *aConverter) { return _to GetConverter(aConverter); } \
  NS_SCRIPTABLE NS_IMETHOD SetConverter(nsIFormatConverter * aConverter) { return _to SetConverter(aConverter); } 

/* Use this macro to declare functions that forward the behavior of this interface to another object in a safe way. */
#define NS_FORWARD_SAFE_NSITRANSFERABLE(_to) \
  NS_SCRIPTABLE NS_IMETHOD FlavorsTransferableCanExport(nsISupportsArray **_retval NS_OUTPARAM) { return !_to ? NS_ERROR_NULL_POINTER : _to->FlavorsTransferableCanExport(_retval); } \
  NS_SCRIPTABLE NS_IMETHOD GetTransferData(const char *aFlavor, nsISupports **aData NS_OUTPARAM, PRUint32 *aDataLen NS_OUTPARAM) { return !_to ? NS_ERROR_NULL_POINTER : _to->GetTransferData(aFlavor, aData, aDataLen); } \
  NS_SCRIPTABLE NS_IMETHOD GetAnyTransferData(char **aFlavor NS_OUTPARAM, nsISupports **aData NS_OUTPARAM, PRUint32 *aDataLen NS_OUTPARAM) { return !_to ? NS_ERROR_NULL_POINTER : _to->GetAnyTransferData(aFlavor, aData, aDataLen); } \
  NS_SCRIPTABLE NS_IMETHOD IsLargeDataSet(PRBool *_retval NS_OUTPARAM) { return !_to ? NS_ERROR_NULL_POINTER : _to->IsLargeDataSet(_retval); } \
  NS_SCRIPTABLE NS_IMETHOD FlavorsTransferableCanImport(nsISupportsArray **_retval NS_OUTPARAM) { return !_to ? NS_ERROR_NULL_POINTER : _to->FlavorsTransferableCanImport(_retval); } \
  NS_SCRIPTABLE NS_IMETHOD SetTransferData(const char *aFlavor, nsISupports *aData, PRUint32 aDataLen) { return !_to ? NS_ERROR_NULL_POINTER : _to->SetTransferData(aFlavor, aData, aDataLen); } \
  NS_SCRIPTABLE NS_IMETHOD AddDataFlavor(const char *aDataFlavor) { return !_to ? NS_ERROR_NULL_POINTER : _to->AddDataFlavor(aDataFlavor); } \
  NS_SCRIPTABLE NS_IMETHOD RemoveDataFlavor(const char *aDataFlavor) { return !_to ? NS_ERROR_NULL_POINTER : _to->RemoveDataFlavor(aDataFlavor); } \
  NS_SCRIPTABLE NS_IMETHOD GetConverter(nsIFormatConverter * *aConverter) { return !_to ? NS_ERROR_NULL_POINTER : _to->GetConverter(aConverter); } \
  NS_SCRIPTABLE NS_IMETHOD SetConverter(nsIFormatConverter * aConverter) { return !_to ? NS_ERROR_NULL_POINTER : _to->SetConverter(aConverter); } 

#if 0
/* Use the code below as a template for the implementation class for this interface. */

/* Header file */
class nsTransferable : public nsITransferable
{
public:
  NS_DECL_ISUPPORTS
  NS_DECL_NSITRANSFERABLE

  nsTransferable();

private:
  ~nsTransferable();

protected:
  /* additional members */
};

/* Implementation file */
NS_IMPL_ISUPPORTS1(nsTransferable, nsITransferable)

nsTransferable::nsTransferable()
{
  /* member initializers and constructor code */
}

nsTransferable::~nsTransferable()
{
  /* destructor code */
}

/* nsISupportsArray flavorsTransferableCanExport (); */
NS_IMETHODIMP nsTransferable::FlavorsTransferableCanExport(nsISupportsArray **_retval NS_OUTPARAM)
{
    return NS_ERROR_NOT_IMPLEMENTED;
}

/* void getTransferData (in string aFlavor, out nsISupports aData, out unsigned long aDataLen); */
NS_IMETHODIMP nsTransferable::GetTransferData(const char *aFlavor, nsISupports **aData NS_OUTPARAM, PRUint32 *aDataLen NS_OUTPARAM)
{
    return NS_ERROR_NOT_IMPLEMENTED;
}

/* void getAnyTransferData (out string aFlavor, out nsISupports aData, out unsigned long aDataLen); */
NS_IMETHODIMP nsTransferable::GetAnyTransferData(char **aFlavor NS_OUTPARAM, nsISupports **aData NS_OUTPARAM, PRUint32 *aDataLen NS_OUTPARAM)
{
    return NS_ERROR_NOT_IMPLEMENTED;
}

/* boolean isLargeDataSet (); */
NS_IMETHODIMP nsTransferable::IsLargeDataSet(PRBool *_retval NS_OUTPARAM)
{
    return NS_ERROR_NOT_IMPLEMENTED;
}

/* nsISupportsArray flavorsTransferableCanImport (); */
NS_IMETHODIMP nsTransferable::FlavorsTransferableCanImport(nsISupportsArray **_retval NS_OUTPARAM)
{
    return NS_ERROR_NOT_IMPLEMENTED;
}

/* void setTransferData (in string aFlavor, in nsISupports aData, in unsigned long aDataLen); */
NS_IMETHODIMP nsTransferable::SetTransferData(const char *aFlavor, nsISupports *aData, PRUint32 aDataLen)
{
    return NS_ERROR_NOT_IMPLEMENTED;
}

/* void addDataFlavor (in string aDataFlavor); */
NS_IMETHODIMP nsTransferable::AddDataFlavor(const char *aDataFlavor)
{
    return NS_ERROR_NOT_IMPLEMENTED;
}

/* void removeDataFlavor (in string aDataFlavor); */
NS_IMETHODIMP nsTransferable::RemoveDataFlavor(const char *aDataFlavor)
{
    return NS_ERROR_NOT_IMPLEMENTED;
}

/* attribute nsIFormatConverter converter; */
NS_IMETHODIMP nsTransferable::GetConverter(nsIFormatConverter * *aConverter)
{
    return NS_ERROR_NOT_IMPLEMENTED;
}
NS_IMETHODIMP nsTransferable::SetConverter(nsIFormatConverter * aConverter)
{
    return NS_ERROR_NOT_IMPLEMENTED;
}

/* End of implementation class template. */
#endif


#endif /* __gen_nsITransferable_h__ */
