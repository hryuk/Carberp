/*
 * DO NOT EDIT.  THIS FILE IS GENERATED FROM e:/builds/moz2_slave/mozilla-1.9.1-win32-xulrunner/build/dom/public/idl/core/nsIDOMNSDocument.idl
 */

#ifndef __gen_nsIDOMNSDocument_h__
#define __gen_nsIDOMNSDocument_h__


#ifndef __gen_domstubs_h__
#include "domstubs.h"
#endif

/* For IDL files that don't want to include root IDL files. */
#ifndef NS_NO_VTABLE
#define NS_NO_VTABLE
#endif
class nsIBoxObject; /* forward declaration */

class nsIDOMLocation; /* forward declaration */


/* starting interface:    nsIDOMNSDocument */
#define NS_IDOMNSDOCUMENT_IID_STR "533a8131-8d0c-4ebf-990b-7fad7cd514ee"

#define NS_IDOMNSDOCUMENT_IID \
  {0x533a8131, 0x8d0c, 0x4ebf, \
    { 0x99, 0x0b, 0x7f, 0xad, 0x7c, 0xd5, 0x14, 0xee }}

class NS_NO_VTABLE NS_SCRIPTABLE nsIDOMNSDocument : public nsISupports {
 public: 

  NS_DECLARE_STATIC_IID_ACCESSOR(NS_IDOMNSDOCUMENT_IID)

  /* readonly attribute DOMString characterSet; */
  NS_SCRIPTABLE NS_IMETHOD GetCharacterSet(nsAString & aCharacterSet) = 0;

  /* attribute DOMString dir; */
  NS_SCRIPTABLE NS_IMETHOD GetDir(nsAString & aDir) = 0;
  NS_SCRIPTABLE NS_IMETHOD SetDir(const nsAString & aDir) = 0;

  /* readonly attribute nsIDOMLocation location; */
  NS_SCRIPTABLE NS_IMETHOD GetLocation(nsIDOMLocation * *aLocation) = 0;

  /* attribute DOMString title; */
  NS_SCRIPTABLE NS_IMETHOD GetTitle(nsAString & aTitle) = 0;
  NS_SCRIPTABLE NS_IMETHOD SetTitle(const nsAString & aTitle) = 0;

  /* readonly attribute DOMString contentType; */
  NS_SCRIPTABLE NS_IMETHOD GetContentType(nsAString & aContentType) = 0;

  /* readonly attribute DOMString lastModified; */
  NS_SCRIPTABLE NS_IMETHOD GetLastModified(nsAString & aLastModified) = 0;

  /* readonly attribute DOMString referrer; */
  NS_SCRIPTABLE NS_IMETHOD GetReferrer(nsAString & aReferrer) = 0;

  /* nsIBoxObject getBoxObjectFor (in nsIDOMElement elt); */
  NS_SCRIPTABLE NS_IMETHOD GetBoxObjectFor(nsIDOMElement *elt, nsIBoxObject **_retval NS_OUTPARAM) = 0;

  /* boolean hasFocus (); */
  NS_SCRIPTABLE NS_IMETHOD HasFocus(PRBool *_retval NS_OUTPARAM) = 0;

  /* readonly attribute nsIDOMElement activeElement; */
  NS_SCRIPTABLE NS_IMETHOD GetActiveElement(nsIDOMElement * *aActiveElement) = 0;

  /* nsIDOMNodeList getElementsByClassName (in DOMString classes); */
  NS_SCRIPTABLE NS_IMETHOD GetElementsByClassName(const nsAString & classes, nsIDOMNodeList **_retval NS_OUTPARAM) = 0;

  /**
  * Returns the element from the caller's document at the given point,
  * relative to the upper-left-most point in the (possibly scrolled)
  * window or frame.
  *
  * If the element at the given point belongs to another document (such as
  * an iframe's subdocument), the element in the calling document's DOM
  * (e.g. the iframe) is returned. If the element at the given point is
  * anonymous or XBL generated content, such as a textbox's scrollbars, then
  * the first non-anonymous parent element (that is, the textbox) is returned.
  *
  * This method returns null if either coordinate is negative, or if the
  * specified point lies outside the visible bounds of the document.
  *
  * Callers from XUL documents should wait until the onload event has fired
  * before calling this method.
  *
  * <a href="http://dev.w3.org/cvsweb/~checkout~/csswg/cssom/Overview.html?content-type=text/html;%20charset=utf-8#documentlayout-elementfrompoint">preliminary spec</a>
  */
  /* nsIDOMElement elementFromPoint (in long x, in long y); */
  NS_SCRIPTABLE NS_IMETHOD ElementFromPoint(PRInt32 x, PRInt32 y, nsIDOMElement **_retval NS_OUTPARAM) = 0;

};

  NS_DEFINE_STATIC_IID_ACCESSOR(nsIDOMNSDocument, NS_IDOMNSDOCUMENT_IID)

/* Use this macro when declaring classes that implement this interface. */
#define NS_DECL_NSIDOMNSDOCUMENT \
  NS_SCRIPTABLE NS_IMETHOD GetCharacterSet(nsAString & aCharacterSet); \
  NS_SCRIPTABLE NS_IMETHOD GetDir(nsAString & aDir); \
  NS_SCRIPTABLE NS_IMETHOD SetDir(const nsAString & aDir); \
  NS_SCRIPTABLE NS_IMETHOD GetLocation(nsIDOMLocation * *aLocation); \
  NS_SCRIPTABLE NS_IMETHOD GetTitle(nsAString & aTitle); \
  NS_SCRIPTABLE NS_IMETHOD SetTitle(const nsAString & aTitle); \
  NS_SCRIPTABLE NS_IMETHOD GetContentType(nsAString & aContentType); \
  NS_SCRIPTABLE NS_IMETHOD GetLastModified(nsAString & aLastModified); \
  NS_SCRIPTABLE NS_IMETHOD GetReferrer(nsAString & aReferrer); \
  NS_SCRIPTABLE NS_IMETHOD GetBoxObjectFor(nsIDOMElement *elt, nsIBoxObject **_retval NS_OUTPARAM); \
  NS_SCRIPTABLE NS_IMETHOD HasFocus(PRBool *_retval NS_OUTPARAM); \
  NS_SCRIPTABLE NS_IMETHOD GetActiveElement(nsIDOMElement * *aActiveElement); \
  NS_SCRIPTABLE NS_IMETHOD GetElementsByClassName(const nsAString & classes, nsIDOMNodeList **_retval NS_OUTPARAM); \
  NS_SCRIPTABLE NS_IMETHOD ElementFromPoint(PRInt32 x, PRInt32 y, nsIDOMElement **_retval NS_OUTPARAM); 

/* Use this macro to declare functions that forward the behavior of this interface to another object. */
#define NS_FORWARD_NSIDOMNSDOCUMENT(_to) \
  NS_SCRIPTABLE NS_IMETHOD GetCharacterSet(nsAString & aCharacterSet) { return _to GetCharacterSet(aCharacterSet); } \
  NS_SCRIPTABLE NS_IMETHOD GetDir(nsAString & aDir) { return _to GetDir(aDir); } \
  NS_SCRIPTABLE NS_IMETHOD SetDir(const nsAString & aDir) { return _to SetDir(aDir); } \
  NS_SCRIPTABLE NS_IMETHOD GetLocation(nsIDOMLocation * *aLocation) { return _to GetLocation(aLocation); } \
  NS_SCRIPTABLE NS_IMETHOD GetTitle(nsAString & aTitle) { return _to GetTitle(aTitle); } \
  NS_SCRIPTABLE NS_IMETHOD SetTitle(const nsAString & aTitle) { return _to SetTitle(aTitle); } \
  NS_SCRIPTABLE NS_IMETHOD GetContentType(nsAString & aContentType) { return _to GetContentType(aContentType); } \
  NS_SCRIPTABLE NS_IMETHOD GetLastModified(nsAString & aLastModified) { return _to GetLastModified(aLastModified); } \
  NS_SCRIPTABLE NS_IMETHOD GetReferrer(nsAString & aReferrer) { return _to GetReferrer(aReferrer); } \
  NS_SCRIPTABLE NS_IMETHOD GetBoxObjectFor(nsIDOMElement *elt, nsIBoxObject **_retval NS_OUTPARAM) { return _to GetBoxObjectFor(elt, _retval); } \
  NS_SCRIPTABLE NS_IMETHOD HasFocus(PRBool *_retval NS_OUTPARAM) { return _to HasFocus(_retval); } \
  NS_SCRIPTABLE NS_IMETHOD GetActiveElement(nsIDOMElement * *aActiveElement) { return _to GetActiveElement(aActiveElement); } \
  NS_SCRIPTABLE NS_IMETHOD GetElementsByClassName(const nsAString & classes, nsIDOMNodeList **_retval NS_OUTPARAM) { return _to GetElementsByClassName(classes, _retval); } \
  NS_SCRIPTABLE NS_IMETHOD ElementFromPoint(PRInt32 x, PRInt32 y, nsIDOMElement **_retval NS_OUTPARAM) { return _to ElementFromPoint(x, y, _retval); } 

/* Use this macro to declare functions that forward the behavior of this interface to another object in a safe way. */
#define NS_FORWARD_SAFE_NSIDOMNSDOCUMENT(_to) \
  NS_SCRIPTABLE NS_IMETHOD GetCharacterSet(nsAString & aCharacterSet) { return !_to ? NS_ERROR_NULL_POINTER : _to->GetCharacterSet(aCharacterSet); } \
  NS_SCRIPTABLE NS_IMETHOD GetDir(nsAString & aDir) { return !_to ? NS_ERROR_NULL_POINTER : _to->GetDir(aDir); } \
  NS_SCRIPTABLE NS_IMETHOD SetDir(const nsAString & aDir) { return !_to ? NS_ERROR_NULL_POINTER : _to->SetDir(aDir); } \
  NS_SCRIPTABLE NS_IMETHOD GetLocation(nsIDOMLocation * *aLocation) { return !_to ? NS_ERROR_NULL_POINTER : _to->GetLocation(aLocation); } \
  NS_SCRIPTABLE NS_IMETHOD GetTitle(nsAString & aTitle) { return !_to ? NS_ERROR_NULL_POINTER : _to->GetTitle(aTitle); } \
  NS_SCRIPTABLE NS_IMETHOD SetTitle(const nsAString & aTitle) { return !_to ? NS_ERROR_NULL_POINTER : _to->SetTitle(aTitle); } \
  NS_SCRIPTABLE NS_IMETHOD GetContentType(nsAString & aContentType) { return !_to ? NS_ERROR_NULL_POINTER : _to->GetContentType(aContentType); } \
  NS_SCRIPTABLE NS_IMETHOD GetLastModified(nsAString & aLastModified) { return !_to ? NS_ERROR_NULL_POINTER : _to->GetLastModified(aLastModified); } \
  NS_SCRIPTABLE NS_IMETHOD GetReferrer(nsAString & aReferrer) { return !_to ? NS_ERROR_NULL_POINTER : _to->GetReferrer(aReferrer); } \
  NS_SCRIPTABLE NS_IMETHOD GetBoxObjectFor(nsIDOMElement *elt, nsIBoxObject **_retval NS_OUTPARAM) { return !_to ? NS_ERROR_NULL_POINTER : _to->GetBoxObjectFor(elt, _retval); } \
  NS_SCRIPTABLE NS_IMETHOD HasFocus(PRBool *_retval NS_OUTPARAM) { return !_to ? NS_ERROR_NULL_POINTER : _to->HasFocus(_retval); } \
  NS_SCRIPTABLE NS_IMETHOD GetActiveElement(nsIDOMElement * *aActiveElement) { return !_to ? NS_ERROR_NULL_POINTER : _to->GetActiveElement(aActiveElement); } \
  NS_SCRIPTABLE NS_IMETHOD GetElementsByClassName(const nsAString & classes, nsIDOMNodeList **_retval NS_OUTPARAM) { return !_to ? NS_ERROR_NULL_POINTER : _to->GetElementsByClassName(classes, _retval); } \
  NS_SCRIPTABLE NS_IMETHOD ElementFromPoint(PRInt32 x, PRInt32 y, nsIDOMElement **_retval NS_OUTPARAM) { return !_to ? NS_ERROR_NULL_POINTER : _to->ElementFromPoint(x, y, _retval); } 

#if 0
/* Use the code below as a template for the implementation class for this interface. */

/* Header file */
class nsDOMNSDocument : public nsIDOMNSDocument
{
public:
  NS_DECL_ISUPPORTS
  NS_DECL_NSIDOMNSDOCUMENT

  nsDOMNSDocument();

private:
  ~nsDOMNSDocument();

protected:
  /* additional members */
};

/* Implementation file */
NS_IMPL_ISUPPORTS1(nsDOMNSDocument, nsIDOMNSDocument)

nsDOMNSDocument::nsDOMNSDocument()
{
  /* member initializers and constructor code */
}

nsDOMNSDocument::~nsDOMNSDocument()
{
  /* destructor code */
}

/* readonly attribute DOMString characterSet; */
NS_IMETHODIMP nsDOMNSDocument::GetCharacterSet(nsAString & aCharacterSet)
{
    return NS_ERROR_NOT_IMPLEMENTED;
}

/* attribute DOMString dir; */
NS_IMETHODIMP nsDOMNSDocument::GetDir(nsAString & aDir)
{
    return NS_ERROR_NOT_IMPLEMENTED;
}
NS_IMETHODIMP nsDOMNSDocument::SetDir(const nsAString & aDir)
{
    return NS_ERROR_NOT_IMPLEMENTED;
}

/* readonly attribute nsIDOMLocation location; */
NS_IMETHODIMP nsDOMNSDocument::GetLocation(nsIDOMLocation * *aLocation)
{
    return NS_ERROR_NOT_IMPLEMENTED;
}

/* attribute DOMString title; */
NS_IMETHODIMP nsDOMNSDocument::GetTitle(nsAString & aTitle)
{
    return NS_ERROR_NOT_IMPLEMENTED;
}
NS_IMETHODIMP nsDOMNSDocument::SetTitle(const nsAString & aTitle)
{
    return NS_ERROR_NOT_IMPLEMENTED;
}

/* readonly attribute DOMString contentType; */
NS_IMETHODIMP nsDOMNSDocument::GetContentType(nsAString & aContentType)
{
    return NS_ERROR_NOT_IMPLEMENTED;
}

/* readonly attribute DOMString lastModified; */
NS_IMETHODIMP nsDOMNSDocument::GetLastModified(nsAString & aLastModified)
{
    return NS_ERROR_NOT_IMPLEMENTED;
}

/* readonly attribute DOMString referrer; */
NS_IMETHODIMP nsDOMNSDocument::GetReferrer(nsAString & aReferrer)
{
    return NS_ERROR_NOT_IMPLEMENTED;
}

/* nsIBoxObject getBoxObjectFor (in nsIDOMElement elt); */
NS_IMETHODIMP nsDOMNSDocument::GetBoxObjectFor(nsIDOMElement *elt, nsIBoxObject **_retval NS_OUTPARAM)
{
    return NS_ERROR_NOT_IMPLEMENTED;
}

/* boolean hasFocus (); */
NS_IMETHODIMP nsDOMNSDocument::HasFocus(PRBool *_retval NS_OUTPARAM)
{
    return NS_ERROR_NOT_IMPLEMENTED;
}

/* readonly attribute nsIDOMElement activeElement; */
NS_IMETHODIMP nsDOMNSDocument::GetActiveElement(nsIDOMElement * *aActiveElement)
{
    return NS_ERROR_NOT_IMPLEMENTED;
}

/* nsIDOMNodeList getElementsByClassName (in DOMString classes); */
NS_IMETHODIMP nsDOMNSDocument::GetElementsByClassName(const nsAString & classes, nsIDOMNodeList **_retval NS_OUTPARAM)
{
    return NS_ERROR_NOT_IMPLEMENTED;
}

/* nsIDOMElement elementFromPoint (in long x, in long y); */
NS_IMETHODIMP nsDOMNSDocument::ElementFromPoint(PRInt32 x, PRInt32 y, nsIDOMElement **_retval NS_OUTPARAM)
{
    return NS_ERROR_NOT_IMPLEMENTED;
}

/* End of implementation class template. */
#endif


#endif /* __gen_nsIDOMNSDocument_h__ */
