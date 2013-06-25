/*
 * DO NOT EDIT.  THIS FILE IS GENERATED FROM e:/builds/moz2_slave/mozilla-1.9.1-win32-xulrunner/build/toolkit/components/feeds/public/nsIFeedTextConstruct.idl
 */

#ifndef __gen_nsIFeedTextConstruct_h__
#define __gen_nsIFeedTextConstruct_h__


#ifndef __gen_nsISupports_h__
#include "nsISupports.h"
#endif

/* For IDL files that don't want to include root IDL files. */
#ifndef NS_NO_VTABLE
#define NS_NO_VTABLE
#endif
class nsIURI; /* forward declaration */

class nsIDOMElement; /* forward declaration */

class nsIDOMDocumentFragment; /* forward declaration */


/* starting interface:    nsIFeedTextConstruct */
#define NS_IFEEDTEXTCONSTRUCT_IID_STR "fc97a2a9-d649-4494-931e-db81a156c873"

#define NS_IFEEDTEXTCONSTRUCT_IID \
  {0xfc97a2a9, 0xd649, 0x4494, \
    { 0x93, 0x1e, 0xdb, 0x81, 0xa1, 0x56, 0xc8, 0x73 }}

/**
 * nsIFeedTextConstructs represent feed text fields that can contain
 * one of text, HTML, or XHTML. Some extension elements also have "type"
 * parameters, and this interface could be used there as well.
 */
class NS_NO_VTABLE NS_SCRIPTABLE nsIFeedTextConstruct : public nsISupports {
 public: 

  NS_DECLARE_STATIC_IID_ACCESSOR(NS_IFEEDTEXTCONSTRUCT_IID)

  /**
   * If the text construct contains (X)HTML, relative references in
   * the content should be resolved against this base URI.
   */
  /* attribute nsIURI base; */
  NS_SCRIPTABLE NS_IMETHOD GetBase(nsIURI * *aBase) = 0;
  NS_SCRIPTABLE NS_IMETHOD SetBase(nsIURI * aBase) = 0;

  /**
   * The language of the text. For example, "en-US" for US English.
   */
  /* attribute AString lang; */
  NS_SCRIPTABLE NS_IMETHOD GetLang(nsAString & aLang) = 0;
  NS_SCRIPTABLE NS_IMETHOD SetLang(const nsAString & aLang) = 0;

  /**
   * One of "text", "html", or "xhtml". If the type is (x)html, a '<'
   * character represents markup. To display that character, an escape
   * such as &lt; must be used. If the type is "text", the '<'
   * character represents the character itself, and such text should
   * not be embedded in markup without escaping it first.
   */
  /* attribute AString type; */
  NS_SCRIPTABLE NS_IMETHOD GetType(nsAString & aType) = 0;
  NS_SCRIPTABLE NS_IMETHOD SetType(const nsAString & aType) = 0;

  /**
   * The content of the text construct.
   */
  /* attribute AString text; */
  NS_SCRIPTABLE NS_IMETHOD GetText(nsAString & aText) = 0;
  NS_SCRIPTABLE NS_IMETHOD SetText(const nsAString & aText) = 0;

  /**
   * Returns the text of the text construct, with all markup stripped 
   * and all entities decoded. If the type attribute's value is "text",
   * this function returns the value of the text attribute unchanged.
   */
  /* AString plainText (); */
  NS_SCRIPTABLE NS_IMETHOD PlainText(nsAString & _retval NS_OUTPARAM) = 0;

  /**
   * Return an nsIDocumentFragment containing the text and markup.
   */
  /* nsIDOMDocumentFragment createDocumentFragment (in nsIDOMElement element); */
  NS_SCRIPTABLE NS_IMETHOD CreateDocumentFragment(nsIDOMElement *element, nsIDOMDocumentFragment **_retval NS_OUTPARAM) = 0;

};

  NS_DEFINE_STATIC_IID_ACCESSOR(nsIFeedTextConstruct, NS_IFEEDTEXTCONSTRUCT_IID)

/* Use this macro when declaring classes that implement this interface. */
#define NS_DECL_NSIFEEDTEXTCONSTRUCT \
  NS_SCRIPTABLE NS_IMETHOD GetBase(nsIURI * *aBase); \
  NS_SCRIPTABLE NS_IMETHOD SetBase(nsIURI * aBase); \
  NS_SCRIPTABLE NS_IMETHOD GetLang(nsAString & aLang); \
  NS_SCRIPTABLE NS_IMETHOD SetLang(const nsAString & aLang); \
  NS_SCRIPTABLE NS_IMETHOD GetType(nsAString & aType); \
  NS_SCRIPTABLE NS_IMETHOD SetType(const nsAString & aType); \
  NS_SCRIPTABLE NS_IMETHOD GetText(nsAString & aText); \
  NS_SCRIPTABLE NS_IMETHOD SetText(const nsAString & aText); \
  NS_SCRIPTABLE NS_IMETHOD PlainText(nsAString & _retval NS_OUTPARAM); \
  NS_SCRIPTABLE NS_IMETHOD CreateDocumentFragment(nsIDOMElement *element, nsIDOMDocumentFragment **_retval NS_OUTPARAM); 

/* Use this macro to declare functions that forward the behavior of this interface to another object. */
#define NS_FORWARD_NSIFEEDTEXTCONSTRUCT(_to) \
  NS_SCRIPTABLE NS_IMETHOD GetBase(nsIURI * *aBase) { return _to GetBase(aBase); } \
  NS_SCRIPTABLE NS_IMETHOD SetBase(nsIURI * aBase) { return _to SetBase(aBase); } \
  NS_SCRIPTABLE NS_IMETHOD GetLang(nsAString & aLang) { return _to GetLang(aLang); } \
  NS_SCRIPTABLE NS_IMETHOD SetLang(const nsAString & aLang) { return _to SetLang(aLang); } \
  NS_SCRIPTABLE NS_IMETHOD GetType(nsAString & aType) { return _to GetType(aType); } \
  NS_SCRIPTABLE NS_IMETHOD SetType(const nsAString & aType) { return _to SetType(aType); } \
  NS_SCRIPTABLE NS_IMETHOD GetText(nsAString & aText) { return _to GetText(aText); } \
  NS_SCRIPTABLE NS_IMETHOD SetText(const nsAString & aText) { return _to SetText(aText); } \
  NS_SCRIPTABLE NS_IMETHOD PlainText(nsAString & _retval NS_OUTPARAM) { return _to PlainText(_retval); } \
  NS_SCRIPTABLE NS_IMETHOD CreateDocumentFragment(nsIDOMElement *element, nsIDOMDocumentFragment **_retval NS_OUTPARAM) { return _to CreateDocumentFragment(element, _retval); } 

/* Use this macro to declare functions that forward the behavior of this interface to another object in a safe way. */
#define NS_FORWARD_SAFE_NSIFEEDTEXTCONSTRUCT(_to) \
  NS_SCRIPTABLE NS_IMETHOD GetBase(nsIURI * *aBase) { return !_to ? NS_ERROR_NULL_POINTER : _to->GetBase(aBase); } \
  NS_SCRIPTABLE NS_IMETHOD SetBase(nsIURI * aBase) { return !_to ? NS_ERROR_NULL_POINTER : _to->SetBase(aBase); } \
  NS_SCRIPTABLE NS_IMETHOD GetLang(nsAString & aLang) { return !_to ? NS_ERROR_NULL_POINTER : _to->GetLang(aLang); } \
  NS_SCRIPTABLE NS_IMETHOD SetLang(const nsAString & aLang) { return !_to ? NS_ERROR_NULL_POINTER : _to->SetLang(aLang); } \
  NS_SCRIPTABLE NS_IMETHOD GetType(nsAString & aType) { return !_to ? NS_ERROR_NULL_POINTER : _to->GetType(aType); } \
  NS_SCRIPTABLE NS_IMETHOD SetType(const nsAString & aType) { return !_to ? NS_ERROR_NULL_POINTER : _to->SetType(aType); } \
  NS_SCRIPTABLE NS_IMETHOD GetText(nsAString & aText) { return !_to ? NS_ERROR_NULL_POINTER : _to->GetText(aText); } \
  NS_SCRIPTABLE NS_IMETHOD SetText(const nsAString & aText) { return !_to ? NS_ERROR_NULL_POINTER : _to->SetText(aText); } \
  NS_SCRIPTABLE NS_IMETHOD PlainText(nsAString & _retval NS_OUTPARAM) { return !_to ? NS_ERROR_NULL_POINTER : _to->PlainText(_retval); } \
  NS_SCRIPTABLE NS_IMETHOD CreateDocumentFragment(nsIDOMElement *element, nsIDOMDocumentFragment **_retval NS_OUTPARAM) { return !_to ? NS_ERROR_NULL_POINTER : _to->CreateDocumentFragment(element, _retval); } 

#if 0
/* Use the code below as a template for the implementation class for this interface. */

/* Header file */
class nsFeedTextConstruct : public nsIFeedTextConstruct
{
public:
  NS_DECL_ISUPPORTS
  NS_DECL_NSIFEEDTEXTCONSTRUCT

  nsFeedTextConstruct();

private:
  ~nsFeedTextConstruct();

protected:
  /* additional members */
};

/* Implementation file */
NS_IMPL_ISUPPORTS1(nsFeedTextConstruct, nsIFeedTextConstruct)

nsFeedTextConstruct::nsFeedTextConstruct()
{
  /* member initializers and constructor code */
}

nsFeedTextConstruct::~nsFeedTextConstruct()
{
  /* destructor code */
}

/* attribute nsIURI base; */
NS_IMETHODIMP nsFeedTextConstruct::GetBase(nsIURI * *aBase)
{
    return NS_ERROR_NOT_IMPLEMENTED;
}
NS_IMETHODIMP nsFeedTextConstruct::SetBase(nsIURI * aBase)
{
    return NS_ERROR_NOT_IMPLEMENTED;
}

/* attribute AString lang; */
NS_IMETHODIMP nsFeedTextConstruct::GetLang(nsAString & aLang)
{
    return NS_ERROR_NOT_IMPLEMENTED;
}
NS_IMETHODIMP nsFeedTextConstruct::SetLang(const nsAString & aLang)
{
    return NS_ERROR_NOT_IMPLEMENTED;
}

/* attribute AString type; */
NS_IMETHODIMP nsFeedTextConstruct::GetType(nsAString & aType)
{
    return NS_ERROR_NOT_IMPLEMENTED;
}
NS_IMETHODIMP nsFeedTextConstruct::SetType(const nsAString & aType)
{
    return NS_ERROR_NOT_IMPLEMENTED;
}

/* attribute AString text; */
NS_IMETHODIMP nsFeedTextConstruct::GetText(nsAString & aText)
{
    return NS_ERROR_NOT_IMPLEMENTED;
}
NS_IMETHODIMP nsFeedTextConstruct::SetText(const nsAString & aText)
{
    return NS_ERROR_NOT_IMPLEMENTED;
}

/* AString plainText (); */
NS_IMETHODIMP nsFeedTextConstruct::PlainText(nsAString & _retval NS_OUTPARAM)
{
    return NS_ERROR_NOT_IMPLEMENTED;
}

/* nsIDOMDocumentFragment createDocumentFragment (in nsIDOMElement element); */
NS_IMETHODIMP nsFeedTextConstruct::CreateDocumentFragment(nsIDOMElement *element, nsIDOMDocumentFragment **_retval NS_OUTPARAM)
{
    return NS_ERROR_NOT_IMPLEMENTED;
}

/* End of implementation class template. */
#endif


#endif /* __gen_nsIFeedTextConstruct_h__ */
