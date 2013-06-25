/*
 * DO NOT EDIT.  THIS FILE IS GENERATED FROM e:/builds/moz2_slave/mozilla-1.9.1-win32-xulrunner/build/dom/public/idl/core/nsIDOM3Text.idl
 */

#ifndef __gen_nsIDOM3Text_h__
#define __gen_nsIDOM3Text_h__


#ifndef __gen_domstubs_h__
#include "domstubs.h"
#endif

/* For IDL files that don't want to include root IDL files. */
#ifndef NS_NO_VTABLE
#define NS_NO_VTABLE
#endif

/* starting interface:    nsIDOM3Text */
#define NS_IDOM3TEXT_IID_STR "bcca052e-46f4-4b8e-8859-a86776c2f1d7"

#define NS_IDOM3TEXT_IID \
  {0xbcca052e, 0x46f4, 0x4b8e, \
    { 0x88, 0x59, 0xa8, 0x67, 0x76, 0xc2, 0xf1, 0xd7 }}

class NS_NO_VTABLE NS_SCRIPTABLE nsIDOM3Text : public nsISupports {
 public: 

  NS_DECLARE_STATIC_IID_ACCESSOR(NS_IDOM3TEXT_IID)

  /**
   * Indicates whether this text node contains element content whitespace.
   * A text node is element content whitespace if it contains only XML
   * white space characters and is a child of an element whose content
   * model allows only child elements optionally separated by white space.
   */
  /* readonly attribute boolean isElementContentWhitespace; */
  NS_SCRIPTABLE NS_IMETHOD GetIsElementContentWhitespace(PRBool *aIsElementContentWhitespace) = 0;

  /**
   * The concatenation of all logically adjacent text nodes with this text
   * node, where "logically adjacent" consists of all text nodes which can be
   * reached by traversing the document tree in either direction without
   * passing an element, comment, or processing-instruction boundary.  
   */
  /* readonly attribute DOMString wholeText; */
  NS_SCRIPTABLE NS_IMETHOD GetWholeText(nsAString & aWholeText) = 0;

  /**
   * If content is empty, removes all logically adjacent text nodes (including
   * this node) from the DOM tree, returning null; otherwise, replaces the
   * contents of this node with aContent and removes all other logically
   * adjacent text nodes from the DOM tree, returning this node.
   */
  /* nsIDOMText replaceWholeText (in DOMString content)  raises (DOMException); */
  NS_SCRIPTABLE NS_IMETHOD ReplaceWholeText(const nsAString & content, nsIDOMText **_retval NS_OUTPARAM) = 0;

};

  NS_DEFINE_STATIC_IID_ACCESSOR(nsIDOM3Text, NS_IDOM3TEXT_IID)

/* Use this macro when declaring classes that implement this interface. */
#define NS_DECL_NSIDOM3TEXT \
  NS_SCRIPTABLE NS_IMETHOD GetIsElementContentWhitespace(PRBool *aIsElementContentWhitespace); \
  NS_SCRIPTABLE NS_IMETHOD GetWholeText(nsAString & aWholeText); \
  NS_SCRIPTABLE NS_IMETHOD ReplaceWholeText(const nsAString & content, nsIDOMText **_retval NS_OUTPARAM); 

/* Use this macro to declare functions that forward the behavior of this interface to another object. */
#define NS_FORWARD_NSIDOM3TEXT(_to) \
  NS_SCRIPTABLE NS_IMETHOD GetIsElementContentWhitespace(PRBool *aIsElementContentWhitespace) { return _to GetIsElementContentWhitespace(aIsElementContentWhitespace); } \
  NS_SCRIPTABLE NS_IMETHOD GetWholeText(nsAString & aWholeText) { return _to GetWholeText(aWholeText); } \
  NS_SCRIPTABLE NS_IMETHOD ReplaceWholeText(const nsAString & content, nsIDOMText **_retval NS_OUTPARAM) { return _to ReplaceWholeText(content, _retval); } 

/* Use this macro to declare functions that forward the behavior of this interface to another object in a safe way. */
#define NS_FORWARD_SAFE_NSIDOM3TEXT(_to) \
  NS_SCRIPTABLE NS_IMETHOD GetIsElementContentWhitespace(PRBool *aIsElementContentWhitespace) { return !_to ? NS_ERROR_NULL_POINTER : _to->GetIsElementContentWhitespace(aIsElementContentWhitespace); } \
  NS_SCRIPTABLE NS_IMETHOD GetWholeText(nsAString & aWholeText) { return !_to ? NS_ERROR_NULL_POINTER : _to->GetWholeText(aWholeText); } \
  NS_SCRIPTABLE NS_IMETHOD ReplaceWholeText(const nsAString & content, nsIDOMText **_retval NS_OUTPARAM) { return !_to ? NS_ERROR_NULL_POINTER : _to->ReplaceWholeText(content, _retval); } 

#if 0
/* Use the code below as a template for the implementation class for this interface. */

/* Header file */
class nsDOM3Text : public nsIDOM3Text
{
public:
  NS_DECL_ISUPPORTS
  NS_DECL_NSIDOM3TEXT

  nsDOM3Text();

private:
  ~nsDOM3Text();

protected:
  /* additional members */
};

/* Implementation file */
NS_IMPL_ISUPPORTS1(nsDOM3Text, nsIDOM3Text)

nsDOM3Text::nsDOM3Text()
{
  /* member initializers and constructor code */
}

nsDOM3Text::~nsDOM3Text()
{
  /* destructor code */
}

/* readonly attribute boolean isElementContentWhitespace; */
NS_IMETHODIMP nsDOM3Text::GetIsElementContentWhitespace(PRBool *aIsElementContentWhitespace)
{
    return NS_ERROR_NOT_IMPLEMENTED;
}

/* readonly attribute DOMString wholeText; */
NS_IMETHODIMP nsDOM3Text::GetWholeText(nsAString & aWholeText)
{
    return NS_ERROR_NOT_IMPLEMENTED;
}

/* nsIDOMText replaceWholeText (in DOMString content)  raises (DOMException); */
NS_IMETHODIMP nsDOM3Text::ReplaceWholeText(const nsAString & content, nsIDOMText **_retval NS_OUTPARAM)
{
    return NS_ERROR_NOT_IMPLEMENTED;
}

/* End of implementation class template. */
#endif


#endif /* __gen_nsIDOM3Text_h__ */
