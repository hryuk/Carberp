/*
 * DO NOT EDIT.  THIS FILE IS GENERATED FROM e:/builds/moz2_slave/mozilla-1.9.1-win32-xulrunner/build/layout/printing/nsIPrintProgressParams.idl
 */

#ifndef __gen_nsIPrintProgressParams_h__
#define __gen_nsIPrintProgressParams_h__


#ifndef __gen_nsISupports_h__
#include "nsISupports.h"
#endif

/* For IDL files that don't want to include root IDL files. */
#ifndef NS_NO_VTABLE
#define NS_NO_VTABLE
#endif

/* starting interface:    nsIPrintProgressParams */
#define NS_IPRINTPROGRESSPARAMS_IID_STR "ca89b55b-6faf-4051-9645-1c03ef5108f8"

#define NS_IPRINTPROGRESSPARAMS_IID \
  {0xca89b55b, 0x6faf, 0x4051, \
    { 0x96, 0x45, 0x1c, 0x03, 0xef, 0x51, 0x08, 0xf8 }}

class NS_NO_VTABLE NS_SCRIPTABLE nsIPrintProgressParams : public nsISupports {
 public: 

  NS_DECLARE_STATIC_IID_ACCESSOR(NS_IPRINTPROGRESSPARAMS_IID)

  /* attribute wstring docTitle; */
  NS_SCRIPTABLE NS_IMETHOD GetDocTitle(PRUnichar * *aDocTitle) = 0;
  NS_SCRIPTABLE NS_IMETHOD SetDocTitle(const PRUnichar * aDocTitle) = 0;

  /* attribute wstring docURL; */
  NS_SCRIPTABLE NS_IMETHOD GetDocURL(PRUnichar * *aDocURL) = 0;
  NS_SCRIPTABLE NS_IMETHOD SetDocURL(const PRUnichar * aDocURL) = 0;

};

  NS_DEFINE_STATIC_IID_ACCESSOR(nsIPrintProgressParams, NS_IPRINTPROGRESSPARAMS_IID)

/* Use this macro when declaring classes that implement this interface. */
#define NS_DECL_NSIPRINTPROGRESSPARAMS \
  NS_SCRIPTABLE NS_IMETHOD GetDocTitle(PRUnichar * *aDocTitle); \
  NS_SCRIPTABLE NS_IMETHOD SetDocTitle(const PRUnichar * aDocTitle); \
  NS_SCRIPTABLE NS_IMETHOD GetDocURL(PRUnichar * *aDocURL); \
  NS_SCRIPTABLE NS_IMETHOD SetDocURL(const PRUnichar * aDocURL); 

/* Use this macro to declare functions that forward the behavior of this interface to another object. */
#define NS_FORWARD_NSIPRINTPROGRESSPARAMS(_to) \
  NS_SCRIPTABLE NS_IMETHOD GetDocTitle(PRUnichar * *aDocTitle) { return _to GetDocTitle(aDocTitle); } \
  NS_SCRIPTABLE NS_IMETHOD SetDocTitle(const PRUnichar * aDocTitle) { return _to SetDocTitle(aDocTitle); } \
  NS_SCRIPTABLE NS_IMETHOD GetDocURL(PRUnichar * *aDocURL) { return _to GetDocURL(aDocURL); } \
  NS_SCRIPTABLE NS_IMETHOD SetDocURL(const PRUnichar * aDocURL) { return _to SetDocURL(aDocURL); } 

/* Use this macro to declare functions that forward the behavior of this interface to another object in a safe way. */
#define NS_FORWARD_SAFE_NSIPRINTPROGRESSPARAMS(_to) \
  NS_SCRIPTABLE NS_IMETHOD GetDocTitle(PRUnichar * *aDocTitle) { return !_to ? NS_ERROR_NULL_POINTER : _to->GetDocTitle(aDocTitle); } \
  NS_SCRIPTABLE NS_IMETHOD SetDocTitle(const PRUnichar * aDocTitle) { return !_to ? NS_ERROR_NULL_POINTER : _to->SetDocTitle(aDocTitle); } \
  NS_SCRIPTABLE NS_IMETHOD GetDocURL(PRUnichar * *aDocURL) { return !_to ? NS_ERROR_NULL_POINTER : _to->GetDocURL(aDocURL); } \
  NS_SCRIPTABLE NS_IMETHOD SetDocURL(const PRUnichar * aDocURL) { return !_to ? NS_ERROR_NULL_POINTER : _to->SetDocURL(aDocURL); } 

#if 0
/* Use the code below as a template for the implementation class for this interface. */

/* Header file */
class nsPrintProgressParams : public nsIPrintProgressParams
{
public:
  NS_DECL_ISUPPORTS
  NS_DECL_NSIPRINTPROGRESSPARAMS

  nsPrintProgressParams();

private:
  ~nsPrintProgressParams();

protected:
  /* additional members */
};

/* Implementation file */
NS_IMPL_ISUPPORTS1(nsPrintProgressParams, nsIPrintProgressParams)

nsPrintProgressParams::nsPrintProgressParams()
{
  /* member initializers and constructor code */
}

nsPrintProgressParams::~nsPrintProgressParams()
{
  /* destructor code */
}

/* attribute wstring docTitle; */
NS_IMETHODIMP nsPrintProgressParams::GetDocTitle(PRUnichar * *aDocTitle)
{
    return NS_ERROR_NOT_IMPLEMENTED;
}
NS_IMETHODIMP nsPrintProgressParams::SetDocTitle(const PRUnichar * aDocTitle)
{
    return NS_ERROR_NOT_IMPLEMENTED;
}

/* attribute wstring docURL; */
NS_IMETHODIMP nsPrintProgressParams::GetDocURL(PRUnichar * *aDocURL)
{
    return NS_ERROR_NOT_IMPLEMENTED;
}
NS_IMETHODIMP nsPrintProgressParams::SetDocURL(const PRUnichar * aDocURL)
{
    return NS_ERROR_NOT_IMPLEMENTED;
}

/* End of implementation class template. */
#endif


#endif /* __gen_nsIPrintProgressParams_h__ */
