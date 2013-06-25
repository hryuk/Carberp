/*
 * DO NOT EDIT.  THIS FILE IS GENERATED FROM e:/builds/moz2_slave/mozilla-1.9.1-win32-xulrunner/build/dom/public/idl/core/nsIDOMXMLDocument.idl
 */

#ifndef __gen_nsIDOMXMLDocument_h__
#define __gen_nsIDOMXMLDocument_h__


#ifndef __gen_nsIDOMDocument_h__
#include "nsIDOMDocument.h"
#endif

/* For IDL files that don't want to include root IDL files. */
#ifndef NS_NO_VTABLE
#define NS_NO_VTABLE
#endif
class nsIXPointerResult; /* forward declaration */


/* starting interface:    nsIDOMXMLDocument */
#define NS_IDOMXMLDOCUMENT_IID_STR "8816d003-e7c8-4065-8827-829b8d07b6e0"

#define NS_IDOMXMLDOCUMENT_IID \
  {0x8816d003, 0xe7c8, 0x4065, \
    { 0x88, 0x27, 0x82, 0x9b, 0x8d, 0x07, 0xb6, 0xe0 }}

class NS_NO_VTABLE NS_SCRIPTABLE nsIDOMXMLDocument : public nsIDOMDocument {
 public: 

  NS_DECLARE_STATIC_IID_ACCESSOR(NS_IDOMXMLDOCUMENT_IID)

  /**
   * Whether to load synchronously or asynchronously.
   * The default is async==true.
   */
  /* attribute boolean async; */
  NS_SCRIPTABLE NS_IMETHOD GetAsync(PRBool *aAsync) = 0;
  NS_SCRIPTABLE NS_IMETHOD SetAsync(PRBool aAsync) = 0;

  /**
   * Load an XML document.
   *
   * @param  url URL to an XML document.
   * @return     True if load successfull.
   */
  /* boolean load (in DOMString url); */
  NS_SCRIPTABLE NS_IMETHOD Load(const nsAString & url, PRBool *_retval NS_OUTPARAM) = 0;

  /**
  * Evaluate FIXptr expression. FIXptr is a W3C NOTE, see
  *
  * http://lists.w3.org/Archives/Public/www-xml-linking-comments/2001AprJun/att-0074/01-NOTE-FIXptr-20010425.htm
  *
  * @param  expression FIXptr string.
  * @return            The range object that results from evaluation
  */
  /* nsIDOMRange evaluateFIXptr (in DOMString expression); */
  NS_SCRIPTABLE NS_IMETHOD EvaluateFIXptr(const nsAString & expression, nsIDOMRange **_retval NS_OUTPARAM) = 0;

  /**
  * Evaluate XPointer expression.
  */
  /* nsIXPointerResult evaluateXPointer (in DOMString expression); */
  NS_SCRIPTABLE NS_IMETHOD EvaluateXPointer(const nsAString & expression, nsIXPointerResult **_retval NS_OUTPARAM) = 0;

};

  NS_DEFINE_STATIC_IID_ACCESSOR(nsIDOMXMLDocument, NS_IDOMXMLDOCUMENT_IID)

/* Use this macro when declaring classes that implement this interface. */
#define NS_DECL_NSIDOMXMLDOCUMENT \
  NS_SCRIPTABLE NS_IMETHOD GetAsync(PRBool *aAsync); \
  NS_SCRIPTABLE NS_IMETHOD SetAsync(PRBool aAsync); \
  NS_SCRIPTABLE NS_IMETHOD Load(const nsAString & url, PRBool *_retval NS_OUTPARAM); \
  NS_SCRIPTABLE NS_IMETHOD EvaluateFIXptr(const nsAString & expression, nsIDOMRange **_retval NS_OUTPARAM); \
  NS_SCRIPTABLE NS_IMETHOD EvaluateXPointer(const nsAString & expression, nsIXPointerResult **_retval NS_OUTPARAM); 

/* Use this macro to declare functions that forward the behavior of this interface to another object. */
#define NS_FORWARD_NSIDOMXMLDOCUMENT(_to) \
  NS_SCRIPTABLE NS_IMETHOD GetAsync(PRBool *aAsync) { return _to GetAsync(aAsync); } \
  NS_SCRIPTABLE NS_IMETHOD SetAsync(PRBool aAsync) { return _to SetAsync(aAsync); } \
  NS_SCRIPTABLE NS_IMETHOD Load(const nsAString & url, PRBool *_retval NS_OUTPARAM) { return _to Load(url, _retval); } \
  NS_SCRIPTABLE NS_IMETHOD EvaluateFIXptr(const nsAString & expression, nsIDOMRange **_retval NS_OUTPARAM) { return _to EvaluateFIXptr(expression, _retval); } \
  NS_SCRIPTABLE NS_IMETHOD EvaluateXPointer(const nsAString & expression, nsIXPointerResult **_retval NS_OUTPARAM) { return _to EvaluateXPointer(expression, _retval); } 

/* Use this macro to declare functions that forward the behavior of this interface to another object in a safe way. */
#define NS_FORWARD_SAFE_NSIDOMXMLDOCUMENT(_to) \
  NS_SCRIPTABLE NS_IMETHOD GetAsync(PRBool *aAsync) { return !_to ? NS_ERROR_NULL_POINTER : _to->GetAsync(aAsync); } \
  NS_SCRIPTABLE NS_IMETHOD SetAsync(PRBool aAsync) { return !_to ? NS_ERROR_NULL_POINTER : _to->SetAsync(aAsync); } \
  NS_SCRIPTABLE NS_IMETHOD Load(const nsAString & url, PRBool *_retval NS_OUTPARAM) { return !_to ? NS_ERROR_NULL_POINTER : _to->Load(url, _retval); } \
  NS_SCRIPTABLE NS_IMETHOD EvaluateFIXptr(const nsAString & expression, nsIDOMRange **_retval NS_OUTPARAM) { return !_to ? NS_ERROR_NULL_POINTER : _to->EvaluateFIXptr(expression, _retval); } \
  NS_SCRIPTABLE NS_IMETHOD EvaluateXPointer(const nsAString & expression, nsIXPointerResult **_retval NS_OUTPARAM) { return !_to ? NS_ERROR_NULL_POINTER : _to->EvaluateXPointer(expression, _retval); } 

#if 0
/* Use the code below as a template for the implementation class for this interface. */

/* Header file */
class nsDOMXMLDocument : public nsIDOMXMLDocument
{
public:
  NS_DECL_ISUPPORTS
  NS_DECL_NSIDOMXMLDOCUMENT

  nsDOMXMLDocument();

private:
  ~nsDOMXMLDocument();

protected:
  /* additional members */
};

/* Implementation file */
NS_IMPL_ISUPPORTS1(nsDOMXMLDocument, nsIDOMXMLDocument)

nsDOMXMLDocument::nsDOMXMLDocument()
{
  /* member initializers and constructor code */
}

nsDOMXMLDocument::~nsDOMXMLDocument()
{
  /* destructor code */
}

/* attribute boolean async; */
NS_IMETHODIMP nsDOMXMLDocument::GetAsync(PRBool *aAsync)
{
    return NS_ERROR_NOT_IMPLEMENTED;
}
NS_IMETHODIMP nsDOMXMLDocument::SetAsync(PRBool aAsync)
{
    return NS_ERROR_NOT_IMPLEMENTED;
}

/* boolean load (in DOMString url); */
NS_IMETHODIMP nsDOMXMLDocument::Load(const nsAString & url, PRBool *_retval NS_OUTPARAM)
{
    return NS_ERROR_NOT_IMPLEMENTED;
}

/* nsIDOMRange evaluateFIXptr (in DOMString expression); */
NS_IMETHODIMP nsDOMXMLDocument::EvaluateFIXptr(const nsAString & expression, nsIDOMRange **_retval NS_OUTPARAM)
{
    return NS_ERROR_NOT_IMPLEMENTED;
}

/* nsIXPointerResult evaluateXPointer (in DOMString expression); */
NS_IMETHODIMP nsDOMXMLDocument::EvaluateXPointer(const nsAString & expression, nsIXPointerResult **_retval NS_OUTPARAM)
{
    return NS_ERROR_NOT_IMPLEMENTED;
}

/* End of implementation class template. */
#endif


#endif /* __gen_nsIDOMXMLDocument_h__ */
