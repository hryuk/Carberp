/*
 * DO NOT EDIT.  THIS FILE IS GENERATED FROM e:/builds/moz2_slave/mozilla-1.9.1-win32-xulrunner/build/toolkit/components/feeds/public/nsIScriptableUnescapeHTML.idl
 */

#ifndef __gen_nsIScriptableUnescapeHTML_h__
#define __gen_nsIScriptableUnescapeHTML_h__


#ifndef __gen_nsISupports_h__
#include "nsISupports.h"
#endif

/* For IDL files that don't want to include root IDL files. */
#ifndef NS_NO_VTABLE
#define NS_NO_VTABLE
#endif
class nsIDOMElement; /* forward declaration */

class nsIDOMDocumentFragment; /* forward declaration */

class nsIURI; /* forward declaration */


/* starting interface:    nsIScriptableUnescapeHTML */
#define NS_ISCRIPTABLEUNESCAPEHTML_IID_STR "3ab244a9-f09d-44da-9e3f-ee4d67367f2d"

#define NS_ISCRIPTABLEUNESCAPEHTML_IID \
  {0x3ab244a9, 0xf09d, 0x44da, \
    { 0x9e, 0x3f, 0xee, 0x4d, 0x67, 0x36, 0x7f, 0x2d }}

/**
 * A utility class that unescapes HTML strings.
 */
class NS_NO_VTABLE NS_SCRIPTABLE nsIScriptableUnescapeHTML : public nsISupports {
 public: 

  NS_DECLARE_STATIC_IID_ACCESSOR(NS_ISCRIPTABLEUNESCAPEHTML_IID)

  /** 
   * Converts all entities to Unicode.
   *
   * @param src The HTML string to escape.
   */
  /* AString unescape (in AString src); */
  NS_SCRIPTABLE NS_IMETHOD Unescape(const nsAString & src, nsAString & _retval NS_OUTPARAM) = 0;

  /**
   * Appends the text to the element.
   */
  /* nsIDOMDocumentFragment parseFragment (in AString fragment, in PRBool isXML, in nsIURI baseURI, in nsIDOMElement element); */
  NS_SCRIPTABLE NS_IMETHOD ParseFragment(const nsAString & fragment, PRBool isXML, nsIURI *baseURI, nsIDOMElement *element, nsIDOMDocumentFragment **_retval NS_OUTPARAM) = 0;

};

  NS_DEFINE_STATIC_IID_ACCESSOR(nsIScriptableUnescapeHTML, NS_ISCRIPTABLEUNESCAPEHTML_IID)

/* Use this macro when declaring classes that implement this interface. */
#define NS_DECL_NSISCRIPTABLEUNESCAPEHTML \
  NS_SCRIPTABLE NS_IMETHOD Unescape(const nsAString & src, nsAString & _retval NS_OUTPARAM); \
  NS_SCRIPTABLE NS_IMETHOD ParseFragment(const nsAString & fragment, PRBool isXML, nsIURI *baseURI, nsIDOMElement *element, nsIDOMDocumentFragment **_retval NS_OUTPARAM); 

/* Use this macro to declare functions that forward the behavior of this interface to another object. */
#define NS_FORWARD_NSISCRIPTABLEUNESCAPEHTML(_to) \
  NS_SCRIPTABLE NS_IMETHOD Unescape(const nsAString & src, nsAString & _retval NS_OUTPARAM) { return _to Unescape(src, _retval); } \
  NS_SCRIPTABLE NS_IMETHOD ParseFragment(const nsAString & fragment, PRBool isXML, nsIURI *baseURI, nsIDOMElement *element, nsIDOMDocumentFragment **_retval NS_OUTPARAM) { return _to ParseFragment(fragment, isXML, baseURI, element, _retval); } 

/* Use this macro to declare functions that forward the behavior of this interface to another object in a safe way. */
#define NS_FORWARD_SAFE_NSISCRIPTABLEUNESCAPEHTML(_to) \
  NS_SCRIPTABLE NS_IMETHOD Unescape(const nsAString & src, nsAString & _retval NS_OUTPARAM) { return !_to ? NS_ERROR_NULL_POINTER : _to->Unescape(src, _retval); } \
  NS_SCRIPTABLE NS_IMETHOD ParseFragment(const nsAString & fragment, PRBool isXML, nsIURI *baseURI, nsIDOMElement *element, nsIDOMDocumentFragment **_retval NS_OUTPARAM) { return !_to ? NS_ERROR_NULL_POINTER : _to->ParseFragment(fragment, isXML, baseURI, element, _retval); } 

#if 0
/* Use the code below as a template for the implementation class for this interface. */

/* Header file */
class nsScriptableUnescapeHTML : public nsIScriptableUnescapeHTML
{
public:
  NS_DECL_ISUPPORTS
  NS_DECL_NSISCRIPTABLEUNESCAPEHTML

  nsScriptableUnescapeHTML();

private:
  ~nsScriptableUnescapeHTML();

protected:
  /* additional members */
};

/* Implementation file */
NS_IMPL_ISUPPORTS1(nsScriptableUnescapeHTML, nsIScriptableUnescapeHTML)

nsScriptableUnescapeHTML::nsScriptableUnescapeHTML()
{
  /* member initializers and constructor code */
}

nsScriptableUnescapeHTML::~nsScriptableUnescapeHTML()
{
  /* destructor code */
}

/* AString unescape (in AString src); */
NS_IMETHODIMP nsScriptableUnescapeHTML::Unescape(const nsAString & src, nsAString & _retval NS_OUTPARAM)
{
    return NS_ERROR_NOT_IMPLEMENTED;
}

/* nsIDOMDocumentFragment parseFragment (in AString fragment, in PRBool isXML, in nsIURI baseURI, in nsIDOMElement element); */
NS_IMETHODIMP nsScriptableUnescapeHTML::ParseFragment(const nsAString & fragment, PRBool isXML, nsIURI *baseURI, nsIDOMElement *element, nsIDOMDocumentFragment **_retval NS_OUTPARAM)
{
    return NS_ERROR_NOT_IMPLEMENTED;
}

/* End of implementation class template. */
#endif


#endif /* __gen_nsIScriptableUnescapeHTML_h__ */
