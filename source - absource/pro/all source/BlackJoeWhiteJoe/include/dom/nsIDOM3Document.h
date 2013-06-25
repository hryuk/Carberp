/*
 * DO NOT EDIT.  THIS FILE IS GENERATED FROM e:/builds/moz2_slave/mozilla-1.9.1-win32-xulrunner/build/dom/public/idl/core/nsIDOM3Document.idl
 */

#ifndef __gen_nsIDOM3Document_h__
#define __gen_nsIDOM3Document_h__


#ifndef __gen_domstubs_h__
#include "domstubs.h"
#endif

#ifndef __gen_nsIDOM3Node_h__
#include "nsIDOM3Node.h"
#endif

/* For IDL files that don't want to include root IDL files. */
#ifndef NS_NO_VTABLE
#define NS_NO_VTABLE
#endif
class nsIDOMDOMConfiguration; /* forward declaration */


/* starting interface:    nsIDOM3Document */
#define NS_IDOM3DOCUMENT_IID_STR "2e0e9ea1-72ab-4d9e-bdeb-ca64e1abeba4"

#define NS_IDOM3DOCUMENT_IID \
  {0x2e0e9ea1, 0x72ab, 0x4d9e, \
    { 0xbd, 0xeb, 0xca, 0x64, 0xe1, 0xab, 0xeb, 0xa4 }}

/**
 * For more information on this interface, please see
 * http://www.w3.org/TR/DOM-Level-3-Core/
 */
class NS_NO_VTABLE NS_SCRIPTABLE nsIDOM3Document : public nsIDOM3Node {
 public: 

  NS_DECLARE_STATIC_IID_ACCESSOR(NS_IDOM3DOCUMENT_IID)

  /* readonly attribute DOMString inputEncoding; */
  NS_SCRIPTABLE NS_IMETHOD GetInputEncoding(nsAString & aInputEncoding) = 0;

  /* readonly attribute DOMString xmlEncoding; */
  NS_SCRIPTABLE NS_IMETHOD GetXmlEncoding(nsAString & aXmlEncoding) = 0;

  /* attribute boolean xmlStandalone; */
  NS_SCRIPTABLE NS_IMETHOD GetXmlStandalone(PRBool *aXmlStandalone) = 0;
  NS_SCRIPTABLE NS_IMETHOD SetXmlStandalone(PRBool aXmlStandalone) = 0;

  /* attribute DOMString xmlVersion; */
  NS_SCRIPTABLE NS_IMETHOD GetXmlVersion(nsAString & aXmlVersion) = 0;
  NS_SCRIPTABLE NS_IMETHOD SetXmlVersion(const nsAString & aXmlVersion) = 0;

  /* attribute boolean strictErrorChecking; */
  NS_SCRIPTABLE NS_IMETHOD GetStrictErrorChecking(PRBool *aStrictErrorChecking) = 0;
  NS_SCRIPTABLE NS_IMETHOD SetStrictErrorChecking(PRBool aStrictErrorChecking) = 0;

  /* attribute DOMString documentURI; */
  NS_SCRIPTABLE NS_IMETHOD GetDocumentURI(nsAString & aDocumentURI) = 0;
  NS_SCRIPTABLE NS_IMETHOD SetDocumentURI(const nsAString & aDocumentURI) = 0;

  /* nsIDOMNode adoptNode (in nsIDOMNode source)  raises (DOMException); */
  NS_SCRIPTABLE NS_IMETHOD AdoptNode(nsIDOMNode *source, nsIDOMNode **_retval NS_OUTPARAM) = 0;

  /* readonly attribute nsIDOMDOMConfiguration domConfig; */
  NS_SCRIPTABLE NS_IMETHOD GetDomConfig(nsIDOMDOMConfiguration * *aDomConfig) = 0;

  /* void normalizeDocument (); */
  NS_SCRIPTABLE NS_IMETHOD NormalizeDocument(void) = 0;

  /* nsIDOMNode renameNode (in nsIDOMNode node, in DOMString namespaceURI, in DOMString qualifiedName)  raises (DOMException); */
  NS_SCRIPTABLE NS_IMETHOD RenameNode(nsIDOMNode *node, const nsAString & namespaceURI, const nsAString & qualifiedName, nsIDOMNode **_retval NS_OUTPARAM) = 0;

};

  NS_DEFINE_STATIC_IID_ACCESSOR(nsIDOM3Document, NS_IDOM3DOCUMENT_IID)

/* Use this macro when declaring classes that implement this interface. */
#define NS_DECL_NSIDOM3DOCUMENT \
  NS_SCRIPTABLE NS_IMETHOD GetInputEncoding(nsAString & aInputEncoding); \
  NS_SCRIPTABLE NS_IMETHOD GetXmlEncoding(nsAString & aXmlEncoding); \
  NS_SCRIPTABLE NS_IMETHOD GetXmlStandalone(PRBool *aXmlStandalone); \
  NS_SCRIPTABLE NS_IMETHOD SetXmlStandalone(PRBool aXmlStandalone); \
  NS_SCRIPTABLE NS_IMETHOD GetXmlVersion(nsAString & aXmlVersion); \
  NS_SCRIPTABLE NS_IMETHOD SetXmlVersion(const nsAString & aXmlVersion); \
  NS_SCRIPTABLE NS_IMETHOD GetStrictErrorChecking(PRBool *aStrictErrorChecking); \
  NS_SCRIPTABLE NS_IMETHOD SetStrictErrorChecking(PRBool aStrictErrorChecking); \
  NS_SCRIPTABLE NS_IMETHOD GetDocumentURI(nsAString & aDocumentURI); \
  NS_SCRIPTABLE NS_IMETHOD SetDocumentURI(const nsAString & aDocumentURI); \
  NS_SCRIPTABLE NS_IMETHOD AdoptNode(nsIDOMNode *source, nsIDOMNode **_retval NS_OUTPARAM); \
  NS_SCRIPTABLE NS_IMETHOD GetDomConfig(nsIDOMDOMConfiguration * *aDomConfig); \
  NS_SCRIPTABLE NS_IMETHOD NormalizeDocument(void); \
  NS_SCRIPTABLE NS_IMETHOD RenameNode(nsIDOMNode *node, const nsAString & namespaceURI, const nsAString & qualifiedName, nsIDOMNode **_retval NS_OUTPARAM); 

/* Use this macro to declare functions that forward the behavior of this interface to another object. */
#define NS_FORWARD_NSIDOM3DOCUMENT(_to) \
  NS_SCRIPTABLE NS_IMETHOD GetInputEncoding(nsAString & aInputEncoding) { return _to GetInputEncoding(aInputEncoding); } \
  NS_SCRIPTABLE NS_IMETHOD GetXmlEncoding(nsAString & aXmlEncoding) { return _to GetXmlEncoding(aXmlEncoding); } \
  NS_SCRIPTABLE NS_IMETHOD GetXmlStandalone(PRBool *aXmlStandalone) { return _to GetXmlStandalone(aXmlStandalone); } \
  NS_SCRIPTABLE NS_IMETHOD SetXmlStandalone(PRBool aXmlStandalone) { return _to SetXmlStandalone(aXmlStandalone); } \
  NS_SCRIPTABLE NS_IMETHOD GetXmlVersion(nsAString & aXmlVersion) { return _to GetXmlVersion(aXmlVersion); } \
  NS_SCRIPTABLE NS_IMETHOD SetXmlVersion(const nsAString & aXmlVersion) { return _to SetXmlVersion(aXmlVersion); } \
  NS_SCRIPTABLE NS_IMETHOD GetStrictErrorChecking(PRBool *aStrictErrorChecking) { return _to GetStrictErrorChecking(aStrictErrorChecking); } \
  NS_SCRIPTABLE NS_IMETHOD SetStrictErrorChecking(PRBool aStrictErrorChecking) { return _to SetStrictErrorChecking(aStrictErrorChecking); } \
  NS_SCRIPTABLE NS_IMETHOD GetDocumentURI(nsAString & aDocumentURI) { return _to GetDocumentURI(aDocumentURI); } \
  NS_SCRIPTABLE NS_IMETHOD SetDocumentURI(const nsAString & aDocumentURI) { return _to SetDocumentURI(aDocumentURI); } \
  NS_SCRIPTABLE NS_IMETHOD AdoptNode(nsIDOMNode *source, nsIDOMNode **_retval NS_OUTPARAM) { return _to AdoptNode(source, _retval); } \
  NS_SCRIPTABLE NS_IMETHOD GetDomConfig(nsIDOMDOMConfiguration * *aDomConfig) { return _to GetDomConfig(aDomConfig); } \
  NS_SCRIPTABLE NS_IMETHOD NormalizeDocument(void) { return _to NormalizeDocument(); } \
  NS_SCRIPTABLE NS_IMETHOD RenameNode(nsIDOMNode *node, const nsAString & namespaceURI, const nsAString & qualifiedName, nsIDOMNode **_retval NS_OUTPARAM) { return _to RenameNode(node, namespaceURI, qualifiedName, _retval); } 

/* Use this macro to declare functions that forward the behavior of this interface to another object in a safe way. */
#define NS_FORWARD_SAFE_NSIDOM3DOCUMENT(_to) \
  NS_SCRIPTABLE NS_IMETHOD GetInputEncoding(nsAString & aInputEncoding) { return !_to ? NS_ERROR_NULL_POINTER : _to->GetInputEncoding(aInputEncoding); } \
  NS_SCRIPTABLE NS_IMETHOD GetXmlEncoding(nsAString & aXmlEncoding) { return !_to ? NS_ERROR_NULL_POINTER : _to->GetXmlEncoding(aXmlEncoding); } \
  NS_SCRIPTABLE NS_IMETHOD GetXmlStandalone(PRBool *aXmlStandalone) { return !_to ? NS_ERROR_NULL_POINTER : _to->GetXmlStandalone(aXmlStandalone); } \
  NS_SCRIPTABLE NS_IMETHOD SetXmlStandalone(PRBool aXmlStandalone) { return !_to ? NS_ERROR_NULL_POINTER : _to->SetXmlStandalone(aXmlStandalone); } \
  NS_SCRIPTABLE NS_IMETHOD GetXmlVersion(nsAString & aXmlVersion) { return !_to ? NS_ERROR_NULL_POINTER : _to->GetXmlVersion(aXmlVersion); } \
  NS_SCRIPTABLE NS_IMETHOD SetXmlVersion(const nsAString & aXmlVersion) { return !_to ? NS_ERROR_NULL_POINTER : _to->SetXmlVersion(aXmlVersion); } \
  NS_SCRIPTABLE NS_IMETHOD GetStrictErrorChecking(PRBool *aStrictErrorChecking) { return !_to ? NS_ERROR_NULL_POINTER : _to->GetStrictErrorChecking(aStrictErrorChecking); } \
  NS_SCRIPTABLE NS_IMETHOD SetStrictErrorChecking(PRBool aStrictErrorChecking) { return !_to ? NS_ERROR_NULL_POINTER : _to->SetStrictErrorChecking(aStrictErrorChecking); } \
  NS_SCRIPTABLE NS_IMETHOD GetDocumentURI(nsAString & aDocumentURI) { return !_to ? NS_ERROR_NULL_POINTER : _to->GetDocumentURI(aDocumentURI); } \
  NS_SCRIPTABLE NS_IMETHOD SetDocumentURI(const nsAString & aDocumentURI) { return !_to ? NS_ERROR_NULL_POINTER : _to->SetDocumentURI(aDocumentURI); } \
  NS_SCRIPTABLE NS_IMETHOD AdoptNode(nsIDOMNode *source, nsIDOMNode **_retval NS_OUTPARAM) { return !_to ? NS_ERROR_NULL_POINTER : _to->AdoptNode(source, _retval); } \
  NS_SCRIPTABLE NS_IMETHOD GetDomConfig(nsIDOMDOMConfiguration * *aDomConfig) { return !_to ? NS_ERROR_NULL_POINTER : _to->GetDomConfig(aDomConfig); } \
  NS_SCRIPTABLE NS_IMETHOD NormalizeDocument(void) { return !_to ? NS_ERROR_NULL_POINTER : _to->NormalizeDocument(); } \
  NS_SCRIPTABLE NS_IMETHOD RenameNode(nsIDOMNode *node, const nsAString & namespaceURI, const nsAString & qualifiedName, nsIDOMNode **_retval NS_OUTPARAM) { return !_to ? NS_ERROR_NULL_POINTER : _to->RenameNode(node, namespaceURI, qualifiedName, _retval); } 

#if 0
/* Use the code below as a template for the implementation class for this interface. */

/* Header file */
class nsDOM3Document : public nsIDOM3Document
{
public:
  NS_DECL_ISUPPORTS
  NS_DECL_NSIDOM3DOCUMENT

  nsDOM3Document();

private:
  ~nsDOM3Document();

protected:
  /* additional members */
};

/* Implementation file */
NS_IMPL_ISUPPORTS1(nsDOM3Document, nsIDOM3Document)

nsDOM3Document::nsDOM3Document()
{
  /* member initializers and constructor code */
}

nsDOM3Document::~nsDOM3Document()
{
  /* destructor code */
}

/* readonly attribute DOMString inputEncoding; */
NS_IMETHODIMP nsDOM3Document::GetInputEncoding(nsAString & aInputEncoding)
{
    return NS_ERROR_NOT_IMPLEMENTED;
}

/* readonly attribute DOMString xmlEncoding; */
NS_IMETHODIMP nsDOM3Document::GetXmlEncoding(nsAString & aXmlEncoding)
{
    return NS_ERROR_NOT_IMPLEMENTED;
}

/* attribute boolean xmlStandalone; */
NS_IMETHODIMP nsDOM3Document::GetXmlStandalone(PRBool *aXmlStandalone)
{
    return NS_ERROR_NOT_IMPLEMENTED;
}
NS_IMETHODIMP nsDOM3Document::SetXmlStandalone(PRBool aXmlStandalone)
{
    return NS_ERROR_NOT_IMPLEMENTED;
}

/* attribute DOMString xmlVersion; */
NS_IMETHODIMP nsDOM3Document::GetXmlVersion(nsAString & aXmlVersion)
{
    return NS_ERROR_NOT_IMPLEMENTED;
}
NS_IMETHODIMP nsDOM3Document::SetXmlVersion(const nsAString & aXmlVersion)
{
    return NS_ERROR_NOT_IMPLEMENTED;
}

/* attribute boolean strictErrorChecking; */
NS_IMETHODIMP nsDOM3Document::GetStrictErrorChecking(PRBool *aStrictErrorChecking)
{
    return NS_ERROR_NOT_IMPLEMENTED;
}
NS_IMETHODIMP nsDOM3Document::SetStrictErrorChecking(PRBool aStrictErrorChecking)
{
    return NS_ERROR_NOT_IMPLEMENTED;
}

/* attribute DOMString documentURI; */
NS_IMETHODIMP nsDOM3Document::GetDocumentURI(nsAString & aDocumentURI)
{
    return NS_ERROR_NOT_IMPLEMENTED;
}
NS_IMETHODIMP nsDOM3Document::SetDocumentURI(const nsAString & aDocumentURI)
{
    return NS_ERROR_NOT_IMPLEMENTED;
}

/* nsIDOMNode adoptNode (in nsIDOMNode source)  raises (DOMException); */
NS_IMETHODIMP nsDOM3Document::AdoptNode(nsIDOMNode *source, nsIDOMNode **_retval NS_OUTPARAM)
{
    return NS_ERROR_NOT_IMPLEMENTED;
}

/* readonly attribute nsIDOMDOMConfiguration domConfig; */
NS_IMETHODIMP nsDOM3Document::GetDomConfig(nsIDOMDOMConfiguration * *aDomConfig)
{
    return NS_ERROR_NOT_IMPLEMENTED;
}

/* void normalizeDocument (); */
NS_IMETHODIMP nsDOM3Document::NormalizeDocument()
{
    return NS_ERROR_NOT_IMPLEMENTED;
}

/* nsIDOMNode renameNode (in nsIDOMNode node, in DOMString namespaceURI, in DOMString qualifiedName)  raises (DOMException); */
NS_IMETHODIMP nsDOM3Document::RenameNode(nsIDOMNode *node, const nsAString & namespaceURI, const nsAString & qualifiedName, nsIDOMNode **_retval NS_OUTPARAM)
{
    return NS_ERROR_NOT_IMPLEMENTED;
}

/* End of implementation class template. */
#endif


#endif /* __gen_nsIDOM3Document_h__ */
