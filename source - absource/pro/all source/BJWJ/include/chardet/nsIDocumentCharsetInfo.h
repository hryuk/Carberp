/*
 * DO NOT EDIT.  THIS FILE IS GENERATED FROM e:/builds/moz2_slave/mozilla-1.9.1-win32-xulrunner/build/intl/chardet/public/nsIDocumentCharsetInfo.idl
 */

#ifndef __gen_nsIDocumentCharsetInfo_h__
#define __gen_nsIDocumentCharsetInfo_h__


#ifndef __gen_nsISupports_h__
#include "nsISupports.h"
#endif

#ifndef __gen_nsIAtom_h__
#include "nsIAtom.h"
#endif

/* For IDL files that don't want to include root IDL files. */
#ifndef NS_NO_VTABLE
#define NS_NO_VTABLE
#endif

/* starting interface:    nsIDocumentCharsetInfo */
#define NS_IDOCUMENTCHARSETINFO_IID_STR "2d40b291-01e1-11d4-9d0e-0050040007b2"

#define NS_IDOCUMENTCHARSETINFO_IID \
  {0x2d40b291, 0x01e1, 0x11d4, \
    { 0x9d, 0x0e, 0x00, 0x50, 0x04, 0x00, 0x07, 0xb2 }}

class NS_NO_VTABLE NS_SCRIPTABLE nsIDocumentCharsetInfo : public nsISupports {
 public: 

  NS_DECLARE_STATIC_IID_ACCESSOR(NS_IDOCUMENTCHARSETINFO_IID)

  /* attribute nsIAtom forcedCharset; */
  NS_SCRIPTABLE NS_IMETHOD GetForcedCharset(nsIAtom * *aForcedCharset) = 0;
  NS_SCRIPTABLE NS_IMETHOD SetForcedCharset(nsIAtom * aForcedCharset) = 0;

  /* attribute boolean forcedDetector; */
  NS_SCRIPTABLE NS_IMETHOD GetForcedDetector(PRBool *aForcedDetector) = 0;
  NS_SCRIPTABLE NS_IMETHOD SetForcedDetector(PRBool aForcedDetector) = 0;

  /* attribute nsIAtom parentCharset; */
  NS_SCRIPTABLE NS_IMETHOD GetParentCharset(nsIAtom * *aParentCharset) = 0;
  NS_SCRIPTABLE NS_IMETHOD SetParentCharset(nsIAtom * aParentCharset) = 0;

  /* attribute PRInt32 parentCharsetSource; */
  NS_SCRIPTABLE NS_IMETHOD GetParentCharsetSource(PRInt32 *aParentCharsetSource) = 0;
  NS_SCRIPTABLE NS_IMETHOD SetParentCharsetSource(PRInt32 aParentCharsetSource) = 0;

};

  NS_DEFINE_STATIC_IID_ACCESSOR(nsIDocumentCharsetInfo, NS_IDOCUMENTCHARSETINFO_IID)

/* Use this macro when declaring classes that implement this interface. */
#define NS_DECL_NSIDOCUMENTCHARSETINFO \
  NS_SCRIPTABLE NS_IMETHOD GetForcedCharset(nsIAtom * *aForcedCharset); \
  NS_SCRIPTABLE NS_IMETHOD SetForcedCharset(nsIAtom * aForcedCharset); \
  NS_SCRIPTABLE NS_IMETHOD GetForcedDetector(PRBool *aForcedDetector); \
  NS_SCRIPTABLE NS_IMETHOD SetForcedDetector(PRBool aForcedDetector); \
  NS_SCRIPTABLE NS_IMETHOD GetParentCharset(nsIAtom * *aParentCharset); \
  NS_SCRIPTABLE NS_IMETHOD SetParentCharset(nsIAtom * aParentCharset); \
  NS_SCRIPTABLE NS_IMETHOD GetParentCharsetSource(PRInt32 *aParentCharsetSource); \
  NS_SCRIPTABLE NS_IMETHOD SetParentCharsetSource(PRInt32 aParentCharsetSource); 

/* Use this macro to declare functions that forward the behavior of this interface to another object. */
#define NS_FORWARD_NSIDOCUMENTCHARSETINFO(_to) \
  NS_SCRIPTABLE NS_IMETHOD GetForcedCharset(nsIAtom * *aForcedCharset) { return _to GetForcedCharset(aForcedCharset); } \
  NS_SCRIPTABLE NS_IMETHOD SetForcedCharset(nsIAtom * aForcedCharset) { return _to SetForcedCharset(aForcedCharset); } \
  NS_SCRIPTABLE NS_IMETHOD GetForcedDetector(PRBool *aForcedDetector) { return _to GetForcedDetector(aForcedDetector); } \
  NS_SCRIPTABLE NS_IMETHOD SetForcedDetector(PRBool aForcedDetector) { return _to SetForcedDetector(aForcedDetector); } \
  NS_SCRIPTABLE NS_IMETHOD GetParentCharset(nsIAtom * *aParentCharset) { return _to GetParentCharset(aParentCharset); } \
  NS_SCRIPTABLE NS_IMETHOD SetParentCharset(nsIAtom * aParentCharset) { return _to SetParentCharset(aParentCharset); } \
  NS_SCRIPTABLE NS_IMETHOD GetParentCharsetSource(PRInt32 *aParentCharsetSource) { return _to GetParentCharsetSource(aParentCharsetSource); } \
  NS_SCRIPTABLE NS_IMETHOD SetParentCharsetSource(PRInt32 aParentCharsetSource) { return _to SetParentCharsetSource(aParentCharsetSource); } 

/* Use this macro to declare functions that forward the behavior of this interface to another object in a safe way. */
#define NS_FORWARD_SAFE_NSIDOCUMENTCHARSETINFO(_to) \
  NS_SCRIPTABLE NS_IMETHOD GetForcedCharset(nsIAtom * *aForcedCharset) { return !_to ? NS_ERROR_NULL_POINTER : _to->GetForcedCharset(aForcedCharset); } \
  NS_SCRIPTABLE NS_IMETHOD SetForcedCharset(nsIAtom * aForcedCharset) { return !_to ? NS_ERROR_NULL_POINTER : _to->SetForcedCharset(aForcedCharset); } \
  NS_SCRIPTABLE NS_IMETHOD GetForcedDetector(PRBool *aForcedDetector) { return !_to ? NS_ERROR_NULL_POINTER : _to->GetForcedDetector(aForcedDetector); } \
  NS_SCRIPTABLE NS_IMETHOD SetForcedDetector(PRBool aForcedDetector) { return !_to ? NS_ERROR_NULL_POINTER : _to->SetForcedDetector(aForcedDetector); } \
  NS_SCRIPTABLE NS_IMETHOD GetParentCharset(nsIAtom * *aParentCharset) { return !_to ? NS_ERROR_NULL_POINTER : _to->GetParentCharset(aParentCharset); } \
  NS_SCRIPTABLE NS_IMETHOD SetParentCharset(nsIAtom * aParentCharset) { return !_to ? NS_ERROR_NULL_POINTER : _to->SetParentCharset(aParentCharset); } \
  NS_SCRIPTABLE NS_IMETHOD GetParentCharsetSource(PRInt32 *aParentCharsetSource) { return !_to ? NS_ERROR_NULL_POINTER : _to->GetParentCharsetSource(aParentCharsetSource); } \
  NS_SCRIPTABLE NS_IMETHOD SetParentCharsetSource(PRInt32 aParentCharsetSource) { return !_to ? NS_ERROR_NULL_POINTER : _to->SetParentCharsetSource(aParentCharsetSource); } 

#if 0
/* Use the code below as a template for the implementation class for this interface. */

/* Header file */
class nsDocumentCharsetInfo : public nsIDocumentCharsetInfo
{
public:
  NS_DECL_ISUPPORTS
  NS_DECL_NSIDOCUMENTCHARSETINFO

  nsDocumentCharsetInfo();

private:
  ~nsDocumentCharsetInfo();

protected:
  /* additional members */
};

/* Implementation file */
NS_IMPL_ISUPPORTS1(nsDocumentCharsetInfo, nsIDocumentCharsetInfo)

nsDocumentCharsetInfo::nsDocumentCharsetInfo()
{
  /* member initializers and constructor code */
}

nsDocumentCharsetInfo::~nsDocumentCharsetInfo()
{
  /* destructor code */
}

/* attribute nsIAtom forcedCharset; */
NS_IMETHODIMP nsDocumentCharsetInfo::GetForcedCharset(nsIAtom * *aForcedCharset)
{
    return NS_ERROR_NOT_IMPLEMENTED;
}
NS_IMETHODIMP nsDocumentCharsetInfo::SetForcedCharset(nsIAtom * aForcedCharset)
{
    return NS_ERROR_NOT_IMPLEMENTED;
}

/* attribute boolean forcedDetector; */
NS_IMETHODIMP nsDocumentCharsetInfo::GetForcedDetector(PRBool *aForcedDetector)
{
    return NS_ERROR_NOT_IMPLEMENTED;
}
NS_IMETHODIMP nsDocumentCharsetInfo::SetForcedDetector(PRBool aForcedDetector)
{
    return NS_ERROR_NOT_IMPLEMENTED;
}

/* attribute nsIAtom parentCharset; */
NS_IMETHODIMP nsDocumentCharsetInfo::GetParentCharset(nsIAtom * *aParentCharset)
{
    return NS_ERROR_NOT_IMPLEMENTED;
}
NS_IMETHODIMP nsDocumentCharsetInfo::SetParentCharset(nsIAtom * aParentCharset)
{
    return NS_ERROR_NOT_IMPLEMENTED;
}

/* attribute PRInt32 parentCharsetSource; */
NS_IMETHODIMP nsDocumentCharsetInfo::GetParentCharsetSource(PRInt32 *aParentCharsetSource)
{
    return NS_ERROR_NOT_IMPLEMENTED;
}
NS_IMETHODIMP nsDocumentCharsetInfo::SetParentCharsetSource(PRInt32 aParentCharsetSource)
{
    return NS_ERROR_NOT_IMPLEMENTED;
}

/* End of implementation class template. */
#endif


#endif /* __gen_nsIDocumentCharsetInfo_h__ */
