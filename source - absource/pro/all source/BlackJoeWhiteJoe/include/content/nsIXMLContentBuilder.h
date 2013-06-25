/*
 * DO NOT EDIT.  THIS FILE IS GENERATED FROM e:/builds/moz2_slave/mozilla-1.9.1-win32-xulrunner/build/content/xtf/public/nsIXMLContentBuilder.idl
 */

#ifndef __gen_nsIXMLContentBuilder_h__
#define __gen_nsIXMLContentBuilder_h__


#ifndef __gen_nsISupports_h__
#include "nsISupports.h"
#endif

/* For IDL files that don't want to include root IDL files. */
#ifndef NS_NO_VTABLE
#define NS_NO_VTABLE
#endif
class nsIDOMElement; /* forward declaration */

class nsIDOMDocument; /* forward declaration */


/* starting interface:    nsIXMLContentBuilder */
#define NS_IXMLCONTENTBUILDER_IID_STR "e9c4cd4f-cd41-43d0-bf3b-48abb9cde90f"

#define NS_IXMLCONTENTBUILDER_IID \
  {0xe9c4cd4f, 0xcd41, 0x43d0, \
    { 0xbf, 0x3b, 0x48, 0xab, 0xb9, 0xcd, 0xe9, 0x0f }}

class NS_NO_VTABLE NS_SCRIPTABLE nsIXMLContentBuilder : public nsISupports {
 public: 

  NS_DECLARE_STATIC_IID_ACCESSOR(NS_IXMLCONTENTBUILDER_IID)

  /* void clear (in nsIDOMElement root); */
  NS_SCRIPTABLE NS_IMETHOD Clear(nsIDOMElement *root) = 0;

  /* void setDocument (in nsIDOMDocument doc); */
  NS_SCRIPTABLE NS_IMETHOD SetDocument(nsIDOMDocument *doc) = 0;

  /* void setElementNamespace (in AString ns); */
  NS_SCRIPTABLE NS_IMETHOD SetElementNamespace(const nsAString & ns) = 0;

  /* void beginElement (in AString tagname); */
  NS_SCRIPTABLE NS_IMETHOD BeginElement(const nsAString & tagname) = 0;

  /* void endElement (); */
  NS_SCRIPTABLE NS_IMETHOD EndElement(void) = 0;

  /* void attrib (in AString name, in AString value); */
  NS_SCRIPTABLE NS_IMETHOD Attrib(const nsAString & name, const nsAString & value) = 0;

  /* void textNode (in AString text); */
  NS_SCRIPTABLE NS_IMETHOD TextNode(const nsAString & text) = 0;

  /* readonly attribute nsIDOMElement root; */
  NS_SCRIPTABLE NS_IMETHOD GetRoot(nsIDOMElement * *aRoot) = 0;

  /* readonly attribute nsIDOMElement current; */
  NS_SCRIPTABLE NS_IMETHOD GetCurrent(nsIDOMElement * *aCurrent) = 0;

};

  NS_DEFINE_STATIC_IID_ACCESSOR(nsIXMLContentBuilder, NS_IXMLCONTENTBUILDER_IID)

/* Use this macro when declaring classes that implement this interface. */
#define NS_DECL_NSIXMLCONTENTBUILDER \
  NS_SCRIPTABLE NS_IMETHOD Clear(nsIDOMElement *root); \
  NS_SCRIPTABLE NS_IMETHOD SetDocument(nsIDOMDocument *doc); \
  NS_SCRIPTABLE NS_IMETHOD SetElementNamespace(const nsAString & ns); \
  NS_SCRIPTABLE NS_IMETHOD BeginElement(const nsAString & tagname); \
  NS_SCRIPTABLE NS_IMETHOD EndElement(void); \
  NS_SCRIPTABLE NS_IMETHOD Attrib(const nsAString & name, const nsAString & value); \
  NS_SCRIPTABLE NS_IMETHOD TextNode(const nsAString & text); \
  NS_SCRIPTABLE NS_IMETHOD GetRoot(nsIDOMElement * *aRoot); \
  NS_SCRIPTABLE NS_IMETHOD GetCurrent(nsIDOMElement * *aCurrent); 

/* Use this macro to declare functions that forward the behavior of this interface to another object. */
#define NS_FORWARD_NSIXMLCONTENTBUILDER(_to) \
  NS_SCRIPTABLE NS_IMETHOD Clear(nsIDOMElement *root) { return _to Clear(root); } \
  NS_SCRIPTABLE NS_IMETHOD SetDocument(nsIDOMDocument *doc) { return _to SetDocument(doc); } \
  NS_SCRIPTABLE NS_IMETHOD SetElementNamespace(const nsAString & ns) { return _to SetElementNamespace(ns); } \
  NS_SCRIPTABLE NS_IMETHOD BeginElement(const nsAString & tagname) { return _to BeginElement(tagname); } \
  NS_SCRIPTABLE NS_IMETHOD EndElement(void) { return _to EndElement(); } \
  NS_SCRIPTABLE NS_IMETHOD Attrib(const nsAString & name, const nsAString & value) { return _to Attrib(name, value); } \
  NS_SCRIPTABLE NS_IMETHOD TextNode(const nsAString & text) { return _to TextNode(text); } \
  NS_SCRIPTABLE NS_IMETHOD GetRoot(nsIDOMElement * *aRoot) { return _to GetRoot(aRoot); } \
  NS_SCRIPTABLE NS_IMETHOD GetCurrent(nsIDOMElement * *aCurrent) { return _to GetCurrent(aCurrent); } 

/* Use this macro to declare functions that forward the behavior of this interface to another object in a safe way. */
#define NS_FORWARD_SAFE_NSIXMLCONTENTBUILDER(_to) \
  NS_SCRIPTABLE NS_IMETHOD Clear(nsIDOMElement *root) { return !_to ? NS_ERROR_NULL_POINTER : _to->Clear(root); } \
  NS_SCRIPTABLE NS_IMETHOD SetDocument(nsIDOMDocument *doc) { return !_to ? NS_ERROR_NULL_POINTER : _to->SetDocument(doc); } \
  NS_SCRIPTABLE NS_IMETHOD SetElementNamespace(const nsAString & ns) { return !_to ? NS_ERROR_NULL_POINTER : _to->SetElementNamespace(ns); } \
  NS_SCRIPTABLE NS_IMETHOD BeginElement(const nsAString & tagname) { return !_to ? NS_ERROR_NULL_POINTER : _to->BeginElement(tagname); } \
  NS_SCRIPTABLE NS_IMETHOD EndElement(void) { return !_to ? NS_ERROR_NULL_POINTER : _to->EndElement(); } \
  NS_SCRIPTABLE NS_IMETHOD Attrib(const nsAString & name, const nsAString & value) { return !_to ? NS_ERROR_NULL_POINTER : _to->Attrib(name, value); } \
  NS_SCRIPTABLE NS_IMETHOD TextNode(const nsAString & text) { return !_to ? NS_ERROR_NULL_POINTER : _to->TextNode(text); } \
  NS_SCRIPTABLE NS_IMETHOD GetRoot(nsIDOMElement * *aRoot) { return !_to ? NS_ERROR_NULL_POINTER : _to->GetRoot(aRoot); } \
  NS_SCRIPTABLE NS_IMETHOD GetCurrent(nsIDOMElement * *aCurrent) { return !_to ? NS_ERROR_NULL_POINTER : _to->GetCurrent(aCurrent); } 

#if 0
/* Use the code below as a template for the implementation class for this interface. */

/* Header file */
class nsXMLContentBuilder : public nsIXMLContentBuilder
{
public:
  NS_DECL_ISUPPORTS
  NS_DECL_NSIXMLCONTENTBUILDER

  nsXMLContentBuilder();

private:
  ~nsXMLContentBuilder();

protected:
  /* additional members */
};

/* Implementation file */
NS_IMPL_ISUPPORTS1(nsXMLContentBuilder, nsIXMLContentBuilder)

nsXMLContentBuilder::nsXMLContentBuilder()
{
  /* member initializers and constructor code */
}

nsXMLContentBuilder::~nsXMLContentBuilder()
{
  /* destructor code */
}

/* void clear (in nsIDOMElement root); */
NS_IMETHODIMP nsXMLContentBuilder::Clear(nsIDOMElement *root)
{
    return NS_ERROR_NOT_IMPLEMENTED;
}

/* void setDocument (in nsIDOMDocument doc); */
NS_IMETHODIMP nsXMLContentBuilder::SetDocument(nsIDOMDocument *doc)
{
    return NS_ERROR_NOT_IMPLEMENTED;
}

/* void setElementNamespace (in AString ns); */
NS_IMETHODIMP nsXMLContentBuilder::SetElementNamespace(const nsAString & ns)
{
    return NS_ERROR_NOT_IMPLEMENTED;
}

/* void beginElement (in AString tagname); */
NS_IMETHODIMP nsXMLContentBuilder::BeginElement(const nsAString & tagname)
{
    return NS_ERROR_NOT_IMPLEMENTED;
}

/* void endElement (); */
NS_IMETHODIMP nsXMLContentBuilder::EndElement()
{
    return NS_ERROR_NOT_IMPLEMENTED;
}

/* void attrib (in AString name, in AString value); */
NS_IMETHODIMP nsXMLContentBuilder::Attrib(const nsAString & name, const nsAString & value)
{
    return NS_ERROR_NOT_IMPLEMENTED;
}

/* void textNode (in AString text); */
NS_IMETHODIMP nsXMLContentBuilder::TextNode(const nsAString & text)
{
    return NS_ERROR_NOT_IMPLEMENTED;
}

/* readonly attribute nsIDOMElement root; */
NS_IMETHODIMP nsXMLContentBuilder::GetRoot(nsIDOMElement * *aRoot)
{
    return NS_ERROR_NOT_IMPLEMENTED;
}

/* readonly attribute nsIDOMElement current; */
NS_IMETHODIMP nsXMLContentBuilder::GetCurrent(nsIDOMElement * *aCurrent)
{
    return NS_ERROR_NOT_IMPLEMENTED;
}

/* End of implementation class template. */
#endif

// {E09AF32D-2A54-4D76-9EF0-3070E83F8BE7}
#define NS_XMLCONTENTBUILDER_CID \
{ 0xe09af32d, 0x2a54, 0x4d76, { 0x9e, 0xf0, 0x30, 0x70, 0xe8, 0x3f, 0x8b, 0xe7 } }
    
#define NS_XMLCONTENTBUILDER_CONTRACTID "@mozilla.org/xtf/xml-contentbuilder;1"
nsresult NS_NewXMLContentBuilder(nsIXMLContentBuilder** aResult);

#endif /* __gen_nsIXMLContentBuilder_h__ */
