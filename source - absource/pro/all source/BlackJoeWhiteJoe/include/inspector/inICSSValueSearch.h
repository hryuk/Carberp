/*
 * DO NOT EDIT.  THIS FILE IS GENERATED FROM e:/builds/moz2_slave/mozilla-1.9.1-win32-xulrunner/build/layout/inspector/public/inICSSValueSearch.idl
 */

#ifndef __gen_inICSSValueSearch_h__
#define __gen_inICSSValueSearch_h__


#ifndef __gen_inISearchProcess_h__
#include "inISearchProcess.h"
#endif

/* For IDL files that don't want to include root IDL files. */
#ifndef NS_NO_VTABLE
#define NS_NO_VTABLE
#endif
class nsIDOMDocument; /* forward declaration */


/* starting interface:    inICSSValueSearch */
#define INICSSVALUESEARCH_IID_STR "e0d39e48-1dd1-11b2-81bd-9a0c117f0736"

#define INICSSVALUESEARCH_IID \
  {0xe0d39e48, 0x1dd1, 0x11b2, \
    { 0x81, 0xbd, 0x9a, 0x0c, 0x11, 0x7f, 0x07, 0x36 }}

class NS_NO_VTABLE NS_SCRIPTABLE inICSSValueSearch : public inISearchProcess {
 public: 

  NS_DECLARE_STATIC_IID_ACCESSOR(INICSSVALUESEARCH_IID)

  /* attribute nsIDOMDocument document; */
  NS_SCRIPTABLE NS_IMETHOD GetDocument(nsIDOMDocument * *aDocument) = 0;
  NS_SCRIPTABLE NS_IMETHOD SetDocument(nsIDOMDocument * aDocument) = 0;

  /* attribute wstring baseURL; */
  NS_SCRIPTABLE NS_IMETHOD GetBaseURL(PRUnichar * *aBaseURL) = 0;
  NS_SCRIPTABLE NS_IMETHOD SetBaseURL(const PRUnichar * aBaseURL) = 0;

  /* attribute boolean returnRelativeURLs; */
  NS_SCRIPTABLE NS_IMETHOD GetReturnRelativeURLs(PRBool *aReturnRelativeURLs) = 0;
  NS_SCRIPTABLE NS_IMETHOD SetReturnRelativeURLs(PRBool aReturnRelativeURLs) = 0;

  /* attribute boolean normalizeChromeURLs; */
  NS_SCRIPTABLE NS_IMETHOD GetNormalizeChromeURLs(PRBool *aNormalizeChromeURLs) = 0;
  NS_SCRIPTABLE NS_IMETHOD SetNormalizeChromeURLs(PRBool aNormalizeChromeURLs) = 0;

  /* void addPropertyCriteria (in wstring aPropName); */
  NS_SCRIPTABLE NS_IMETHOD AddPropertyCriteria(const PRUnichar *aPropName) = 0;

  /* attribute wstring textCriteria; */
  NS_SCRIPTABLE NS_IMETHOD GetTextCriteria(PRUnichar * *aTextCriteria) = 0;
  NS_SCRIPTABLE NS_IMETHOD SetTextCriteria(const PRUnichar * aTextCriteria) = 0;

};

  NS_DEFINE_STATIC_IID_ACCESSOR(inICSSValueSearch, INICSSVALUESEARCH_IID)

/* Use this macro when declaring classes that implement this interface. */
#define NS_DECL_INICSSVALUESEARCH \
  NS_SCRIPTABLE NS_IMETHOD GetDocument(nsIDOMDocument * *aDocument); \
  NS_SCRIPTABLE NS_IMETHOD SetDocument(nsIDOMDocument * aDocument); \
  NS_SCRIPTABLE NS_IMETHOD GetBaseURL(PRUnichar * *aBaseURL); \
  NS_SCRIPTABLE NS_IMETHOD SetBaseURL(const PRUnichar * aBaseURL); \
  NS_SCRIPTABLE NS_IMETHOD GetReturnRelativeURLs(PRBool *aReturnRelativeURLs); \
  NS_SCRIPTABLE NS_IMETHOD SetReturnRelativeURLs(PRBool aReturnRelativeURLs); \
  NS_SCRIPTABLE NS_IMETHOD GetNormalizeChromeURLs(PRBool *aNormalizeChromeURLs); \
  NS_SCRIPTABLE NS_IMETHOD SetNormalizeChromeURLs(PRBool aNormalizeChromeURLs); \
  NS_SCRIPTABLE NS_IMETHOD AddPropertyCriteria(const PRUnichar *aPropName); \
  NS_SCRIPTABLE NS_IMETHOD GetTextCriteria(PRUnichar * *aTextCriteria); \
  NS_SCRIPTABLE NS_IMETHOD SetTextCriteria(const PRUnichar * aTextCriteria); 

/* Use this macro to declare functions that forward the behavior of this interface to another object. */
#define NS_FORWARD_INICSSVALUESEARCH(_to) \
  NS_SCRIPTABLE NS_IMETHOD GetDocument(nsIDOMDocument * *aDocument) { return _to GetDocument(aDocument); } \
  NS_SCRIPTABLE NS_IMETHOD SetDocument(nsIDOMDocument * aDocument) { return _to SetDocument(aDocument); } \
  NS_SCRIPTABLE NS_IMETHOD GetBaseURL(PRUnichar * *aBaseURL) { return _to GetBaseURL(aBaseURL); } \
  NS_SCRIPTABLE NS_IMETHOD SetBaseURL(const PRUnichar * aBaseURL) { return _to SetBaseURL(aBaseURL); } \
  NS_SCRIPTABLE NS_IMETHOD GetReturnRelativeURLs(PRBool *aReturnRelativeURLs) { return _to GetReturnRelativeURLs(aReturnRelativeURLs); } \
  NS_SCRIPTABLE NS_IMETHOD SetReturnRelativeURLs(PRBool aReturnRelativeURLs) { return _to SetReturnRelativeURLs(aReturnRelativeURLs); } \
  NS_SCRIPTABLE NS_IMETHOD GetNormalizeChromeURLs(PRBool *aNormalizeChromeURLs) { return _to GetNormalizeChromeURLs(aNormalizeChromeURLs); } \
  NS_SCRIPTABLE NS_IMETHOD SetNormalizeChromeURLs(PRBool aNormalizeChromeURLs) { return _to SetNormalizeChromeURLs(aNormalizeChromeURLs); } \
  NS_SCRIPTABLE NS_IMETHOD AddPropertyCriteria(const PRUnichar *aPropName) { return _to AddPropertyCriteria(aPropName); } \
  NS_SCRIPTABLE NS_IMETHOD GetTextCriteria(PRUnichar * *aTextCriteria) { return _to GetTextCriteria(aTextCriteria); } \
  NS_SCRIPTABLE NS_IMETHOD SetTextCriteria(const PRUnichar * aTextCriteria) { return _to SetTextCriteria(aTextCriteria); } 

/* Use this macro to declare functions that forward the behavior of this interface to another object in a safe way. */
#define NS_FORWARD_SAFE_INICSSVALUESEARCH(_to) \
  NS_SCRIPTABLE NS_IMETHOD GetDocument(nsIDOMDocument * *aDocument) { return !_to ? NS_ERROR_NULL_POINTER : _to->GetDocument(aDocument); } \
  NS_SCRIPTABLE NS_IMETHOD SetDocument(nsIDOMDocument * aDocument) { return !_to ? NS_ERROR_NULL_POINTER : _to->SetDocument(aDocument); } \
  NS_SCRIPTABLE NS_IMETHOD GetBaseURL(PRUnichar * *aBaseURL) { return !_to ? NS_ERROR_NULL_POINTER : _to->GetBaseURL(aBaseURL); } \
  NS_SCRIPTABLE NS_IMETHOD SetBaseURL(const PRUnichar * aBaseURL) { return !_to ? NS_ERROR_NULL_POINTER : _to->SetBaseURL(aBaseURL); } \
  NS_SCRIPTABLE NS_IMETHOD GetReturnRelativeURLs(PRBool *aReturnRelativeURLs) { return !_to ? NS_ERROR_NULL_POINTER : _to->GetReturnRelativeURLs(aReturnRelativeURLs); } \
  NS_SCRIPTABLE NS_IMETHOD SetReturnRelativeURLs(PRBool aReturnRelativeURLs) { return !_to ? NS_ERROR_NULL_POINTER : _to->SetReturnRelativeURLs(aReturnRelativeURLs); } \
  NS_SCRIPTABLE NS_IMETHOD GetNormalizeChromeURLs(PRBool *aNormalizeChromeURLs) { return !_to ? NS_ERROR_NULL_POINTER : _to->GetNormalizeChromeURLs(aNormalizeChromeURLs); } \
  NS_SCRIPTABLE NS_IMETHOD SetNormalizeChromeURLs(PRBool aNormalizeChromeURLs) { return !_to ? NS_ERROR_NULL_POINTER : _to->SetNormalizeChromeURLs(aNormalizeChromeURLs); } \
  NS_SCRIPTABLE NS_IMETHOD AddPropertyCriteria(const PRUnichar *aPropName) { return !_to ? NS_ERROR_NULL_POINTER : _to->AddPropertyCriteria(aPropName); } \
  NS_SCRIPTABLE NS_IMETHOD GetTextCriteria(PRUnichar * *aTextCriteria) { return !_to ? NS_ERROR_NULL_POINTER : _to->GetTextCriteria(aTextCriteria); } \
  NS_SCRIPTABLE NS_IMETHOD SetTextCriteria(const PRUnichar * aTextCriteria) { return !_to ? NS_ERROR_NULL_POINTER : _to->SetTextCriteria(aTextCriteria); } 

#if 0
/* Use the code below as a template for the implementation class for this interface. */

/* Header file */
class inCSSValueSearch : public inICSSValueSearch
{
public:
  NS_DECL_ISUPPORTS
  NS_DECL_INICSSVALUESEARCH

  inCSSValueSearch();

private:
  ~inCSSValueSearch();

protected:
  /* additional members */
};

/* Implementation file */
NS_IMPL_ISUPPORTS1(inCSSValueSearch, inICSSValueSearch)

inCSSValueSearch::inCSSValueSearch()
{
  /* member initializers and constructor code */
}

inCSSValueSearch::~inCSSValueSearch()
{
  /* destructor code */
}

/* attribute nsIDOMDocument document; */
NS_IMETHODIMP inCSSValueSearch::GetDocument(nsIDOMDocument * *aDocument)
{
    return NS_ERROR_NOT_IMPLEMENTED;
}
NS_IMETHODIMP inCSSValueSearch::SetDocument(nsIDOMDocument * aDocument)
{
    return NS_ERROR_NOT_IMPLEMENTED;
}

/* attribute wstring baseURL; */
NS_IMETHODIMP inCSSValueSearch::GetBaseURL(PRUnichar * *aBaseURL)
{
    return NS_ERROR_NOT_IMPLEMENTED;
}
NS_IMETHODIMP inCSSValueSearch::SetBaseURL(const PRUnichar * aBaseURL)
{
    return NS_ERROR_NOT_IMPLEMENTED;
}

/* attribute boolean returnRelativeURLs; */
NS_IMETHODIMP inCSSValueSearch::GetReturnRelativeURLs(PRBool *aReturnRelativeURLs)
{
    return NS_ERROR_NOT_IMPLEMENTED;
}
NS_IMETHODIMP inCSSValueSearch::SetReturnRelativeURLs(PRBool aReturnRelativeURLs)
{
    return NS_ERROR_NOT_IMPLEMENTED;
}

/* attribute boolean normalizeChromeURLs; */
NS_IMETHODIMP inCSSValueSearch::GetNormalizeChromeURLs(PRBool *aNormalizeChromeURLs)
{
    return NS_ERROR_NOT_IMPLEMENTED;
}
NS_IMETHODIMP inCSSValueSearch::SetNormalizeChromeURLs(PRBool aNormalizeChromeURLs)
{
    return NS_ERROR_NOT_IMPLEMENTED;
}

/* void addPropertyCriteria (in wstring aPropName); */
NS_IMETHODIMP inCSSValueSearch::AddPropertyCriteria(const PRUnichar *aPropName)
{
    return NS_ERROR_NOT_IMPLEMENTED;
}

/* attribute wstring textCriteria; */
NS_IMETHODIMP inCSSValueSearch::GetTextCriteria(PRUnichar * *aTextCriteria)
{
    return NS_ERROR_NOT_IMPLEMENTED;
}
NS_IMETHODIMP inCSSValueSearch::SetTextCriteria(const PRUnichar * aTextCriteria)
{
    return NS_ERROR_NOT_IMPLEMENTED;
}

/* End of implementation class template. */
#endif


#endif /* __gen_inICSSValueSearch_h__ */
