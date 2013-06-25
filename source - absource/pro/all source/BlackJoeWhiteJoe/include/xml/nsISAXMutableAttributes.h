/*
 * DO NOT EDIT.  THIS FILE IS GENERATED FROM e:/builds/moz2_slave/mozilla-1.9.1-win32-xulrunner/build/parser/xml/public/nsISAXMutableAttributes.idl
 */

#ifndef __gen_nsISAXMutableAttributes_h__
#define __gen_nsISAXMutableAttributes_h__


#ifndef __gen_nsISupports_h__
#include "nsISupports.h"
#endif

#ifndef __gen_nsISAXAttributes_h__
#include "nsISAXAttributes.h"
#endif

/* For IDL files that don't want to include root IDL files. */
#ifndef NS_NO_VTABLE
#define NS_NO_VTABLE
#endif

/* starting interface:    nsISAXMutableAttributes */
#define NS_ISAXMUTABLEATTRIBUTES_IID_STR "8b1de83d-cebb-49fa-8245-c0fe319eb7b6"

#define NS_ISAXMUTABLEATTRIBUTES_IID \
  {0x8b1de83d, 0xcebb, 0x49fa, \
    { 0x82, 0x45, 0xc0, 0xfe, 0x31, 0x9e, 0xb7, 0xb6 }}

/**
 * This interface extends the nsISAXAttributes interface with
 * manipulators so that the list can be modified or reused.
 */
class NS_NO_VTABLE NS_SCRIPTABLE nsISAXMutableAttributes : public nsISAXAttributes {
 public: 

  NS_DECLARE_STATIC_IID_ACCESSOR(NS_ISAXMUTABLEATTRIBUTES_IID)

  /**
   * Add an attribute to the end of the list.
   *
   * For the sake of speed, this method does no checking
   * to see if the attribute is already in the list: that is
   * the responsibility of the application.
   *
   * @param uri The Namespace URI, or the empty string if
   *        none is available or Namespace processing is not
   *        being performed.
   * @param localName The local name, or the empty string if
   *        Namespace processing is not being performed.
   * @param qName The qualified (prefixed) name, or the empty string
   *        if qualified names are not available.
   * @param type The attribute type as a string.
   * @param value The attribute value.
   */
  /* void addAttribute (in AString uri, in AString localName, in AString qName, in AString type, in AString value); */
  NS_SCRIPTABLE NS_IMETHOD AddAttribute(const nsAString & uri, const nsAString & localName, const nsAString & qName, const nsAString & type, const nsAString & value) = 0;

  /**
   * Clear the attribute list for reuse.
   */
  /* void clear (); */
  NS_SCRIPTABLE NS_IMETHOD Clear(void) = 0;

  /**
   * Remove an attribute from the list.
   *
   * @param index The index of the attribute (zero-based).
   */
  /* void removeAttribute (in unsigned long index); */
  NS_SCRIPTABLE NS_IMETHOD RemoveAttribute(PRUint32 index) = 0;

  /**
   * Set the attributes list. This method will clear any attributes in
   * the list before adding the attributes from the argument.
   *
   * @param attributes The attributes object to replace populate the
   *                   list with.
   */
  /* void setAttributes (in nsISAXAttributes attributes); */
  NS_SCRIPTABLE NS_IMETHOD SetAttributes(nsISAXAttributes *attributes) = 0;

  /**
   * Set an attribute in the list.
   *
   * For the sake of speed, this method does no checking for name
   * conflicts or well-formedness: such checks are the responsibility
   * of the application.
   *
   * @param index The index of the attribute (zero-based).
   * @param uri The Namespace URI, or the empty string if
   *        none is available or Namespace processing is not
   *        being performed.
   * @param localName The local name, or the empty string if
   *        Namespace processing is not being performed.
   * @param qName The qualified name, or the empty string
   *        if qualified names are not available.
   * @param type The attribute type as a string.
   * @param value The attribute value.
   */
  /* void setAttribute (in unsigned long index, in AString uri, in AString localName, in AString qName, in AString type, in AString value); */
  NS_SCRIPTABLE NS_IMETHOD SetAttribute(PRUint32 index, const nsAString & uri, const nsAString & localName, const nsAString & qName, const nsAString & type, const nsAString & value) = 0;

  /**
   * Set the local name of a specific attribute.
   *
   * @param index The index of the attribute (zero-based).
   * @param localName The attribute's local name, or the empty
   *        string for none.
   */
  /* void setLocalName (in unsigned long index, in AString localName); */
  NS_SCRIPTABLE NS_IMETHOD SetLocalName(PRUint32 index, const nsAString & localName) = 0;

  /**
   * Set the qualified name of a specific attribute.
   *
   * @param index The index of the attribute (zero-based).
   * @param qName The attribute's qualified name, or the empty
   *        string for none.
   */
  /* void setQName (in unsigned long index, in AString qName); */
  NS_SCRIPTABLE NS_IMETHOD SetQName(PRUint32 index, const nsAString & qName) = 0;

  /**
   * Set the type of a specific attribute.
   *
   * @param index The index of the attribute (zero-based).
   * @param type The attribute's type.
   */
  /* void setType (in unsigned long index, in AString type); */
  NS_SCRIPTABLE NS_IMETHOD SetType(PRUint32 index, const nsAString & type) = 0;

  /**
   * Set the Namespace URI of a specific attribute.
   *
   * @param index The index of the attribute (zero-based).
   * @param uri The attribute's Namespace URI, or the empty
   *        string for none.
   */
  /* void setURI (in unsigned long index, in AString uri); */
  NS_SCRIPTABLE NS_IMETHOD SetURI(PRUint32 index, const nsAString & uri) = 0;

  /**
   * Set the value of a specific attribute.
   *
   * @param index The index of the attribute (zero-based).
   * @param value The attribute's value.
   */
  /* void setValue (in unsigned long index, in AString value); */
  NS_SCRIPTABLE NS_IMETHOD SetValue(PRUint32 index, const nsAString & value) = 0;

};

  NS_DEFINE_STATIC_IID_ACCESSOR(nsISAXMutableAttributes, NS_ISAXMUTABLEATTRIBUTES_IID)

/* Use this macro when declaring classes that implement this interface. */
#define NS_DECL_NSISAXMUTABLEATTRIBUTES \
  NS_SCRIPTABLE NS_IMETHOD AddAttribute(const nsAString & uri, const nsAString & localName, const nsAString & qName, const nsAString & type, const nsAString & value); \
  NS_SCRIPTABLE NS_IMETHOD Clear(void); \
  NS_SCRIPTABLE NS_IMETHOD RemoveAttribute(PRUint32 index); \
  NS_SCRIPTABLE NS_IMETHOD SetAttributes(nsISAXAttributes *attributes); \
  NS_SCRIPTABLE NS_IMETHOD SetAttribute(PRUint32 index, const nsAString & uri, const nsAString & localName, const nsAString & qName, const nsAString & type, const nsAString & value); \
  NS_SCRIPTABLE NS_IMETHOD SetLocalName(PRUint32 index, const nsAString & localName); \
  NS_SCRIPTABLE NS_IMETHOD SetQName(PRUint32 index, const nsAString & qName); \
  NS_SCRIPTABLE NS_IMETHOD SetType(PRUint32 index, const nsAString & type); \
  NS_SCRIPTABLE NS_IMETHOD SetURI(PRUint32 index, const nsAString & uri); \
  NS_SCRIPTABLE NS_IMETHOD SetValue(PRUint32 index, const nsAString & value); 

/* Use this macro to declare functions that forward the behavior of this interface to another object. */
#define NS_FORWARD_NSISAXMUTABLEATTRIBUTES(_to) \
  NS_SCRIPTABLE NS_IMETHOD AddAttribute(const nsAString & uri, const nsAString & localName, const nsAString & qName, const nsAString & type, const nsAString & value) { return _to AddAttribute(uri, localName, qName, type, value); } \
  NS_SCRIPTABLE NS_IMETHOD Clear(void) { return _to Clear(); } \
  NS_SCRIPTABLE NS_IMETHOD RemoveAttribute(PRUint32 index) { return _to RemoveAttribute(index); } \
  NS_SCRIPTABLE NS_IMETHOD SetAttributes(nsISAXAttributes *attributes) { return _to SetAttributes(attributes); } \
  NS_SCRIPTABLE NS_IMETHOD SetAttribute(PRUint32 index, const nsAString & uri, const nsAString & localName, const nsAString & qName, const nsAString & type, const nsAString & value) { return _to SetAttribute(index, uri, localName, qName, type, value); } \
  NS_SCRIPTABLE NS_IMETHOD SetLocalName(PRUint32 index, const nsAString & localName) { return _to SetLocalName(index, localName); } \
  NS_SCRIPTABLE NS_IMETHOD SetQName(PRUint32 index, const nsAString & qName) { return _to SetQName(index, qName); } \
  NS_SCRIPTABLE NS_IMETHOD SetType(PRUint32 index, const nsAString & type) { return _to SetType(index, type); } \
  NS_SCRIPTABLE NS_IMETHOD SetURI(PRUint32 index, const nsAString & uri) { return _to SetURI(index, uri); } \
  NS_SCRIPTABLE NS_IMETHOD SetValue(PRUint32 index, const nsAString & value) { return _to SetValue(index, value); } 

/* Use this macro to declare functions that forward the behavior of this interface to another object in a safe way. */
#define NS_FORWARD_SAFE_NSISAXMUTABLEATTRIBUTES(_to) \
  NS_SCRIPTABLE NS_IMETHOD AddAttribute(const nsAString & uri, const nsAString & localName, const nsAString & qName, const nsAString & type, const nsAString & value) { return !_to ? NS_ERROR_NULL_POINTER : _to->AddAttribute(uri, localName, qName, type, value); } \
  NS_SCRIPTABLE NS_IMETHOD Clear(void) { return !_to ? NS_ERROR_NULL_POINTER : _to->Clear(); } \
  NS_SCRIPTABLE NS_IMETHOD RemoveAttribute(PRUint32 index) { return !_to ? NS_ERROR_NULL_POINTER : _to->RemoveAttribute(index); } \
  NS_SCRIPTABLE NS_IMETHOD SetAttributes(nsISAXAttributes *attributes) { return !_to ? NS_ERROR_NULL_POINTER : _to->SetAttributes(attributes); } \
  NS_SCRIPTABLE NS_IMETHOD SetAttribute(PRUint32 index, const nsAString & uri, const nsAString & localName, const nsAString & qName, const nsAString & type, const nsAString & value) { return !_to ? NS_ERROR_NULL_POINTER : _to->SetAttribute(index, uri, localName, qName, type, value); } \
  NS_SCRIPTABLE NS_IMETHOD SetLocalName(PRUint32 index, const nsAString & localName) { return !_to ? NS_ERROR_NULL_POINTER : _to->SetLocalName(index, localName); } \
  NS_SCRIPTABLE NS_IMETHOD SetQName(PRUint32 index, const nsAString & qName) { return !_to ? NS_ERROR_NULL_POINTER : _to->SetQName(index, qName); } \
  NS_SCRIPTABLE NS_IMETHOD SetType(PRUint32 index, const nsAString & type) { return !_to ? NS_ERROR_NULL_POINTER : _to->SetType(index, type); } \
  NS_SCRIPTABLE NS_IMETHOD SetURI(PRUint32 index, const nsAString & uri) { return !_to ? NS_ERROR_NULL_POINTER : _to->SetURI(index, uri); } \
  NS_SCRIPTABLE NS_IMETHOD SetValue(PRUint32 index, const nsAString & value) { return !_to ? NS_ERROR_NULL_POINTER : _to->SetValue(index, value); } 

#if 0
/* Use the code below as a template for the implementation class for this interface. */

/* Header file */
class nsSAXMutableAttributes : public nsISAXMutableAttributes
{
public:
  NS_DECL_ISUPPORTS
  NS_DECL_NSISAXMUTABLEATTRIBUTES

  nsSAXMutableAttributes();

private:
  ~nsSAXMutableAttributes();

protected:
  /* additional members */
};

/* Implementation file */
NS_IMPL_ISUPPORTS1(nsSAXMutableAttributes, nsISAXMutableAttributes)

nsSAXMutableAttributes::nsSAXMutableAttributes()
{
  /* member initializers and constructor code */
}

nsSAXMutableAttributes::~nsSAXMutableAttributes()
{
  /* destructor code */
}

/* void addAttribute (in AString uri, in AString localName, in AString qName, in AString type, in AString value); */
NS_IMETHODIMP nsSAXMutableAttributes::AddAttribute(const nsAString & uri, const nsAString & localName, const nsAString & qName, const nsAString & type, const nsAString & value)
{
    return NS_ERROR_NOT_IMPLEMENTED;
}

/* void clear (); */
NS_IMETHODIMP nsSAXMutableAttributes::Clear()
{
    return NS_ERROR_NOT_IMPLEMENTED;
}

/* void removeAttribute (in unsigned long index); */
NS_IMETHODIMP nsSAXMutableAttributes::RemoveAttribute(PRUint32 index)
{
    return NS_ERROR_NOT_IMPLEMENTED;
}

/* void setAttributes (in nsISAXAttributes attributes); */
NS_IMETHODIMP nsSAXMutableAttributes::SetAttributes(nsISAXAttributes *attributes)
{
    return NS_ERROR_NOT_IMPLEMENTED;
}

/* void setAttribute (in unsigned long index, in AString uri, in AString localName, in AString qName, in AString type, in AString value); */
NS_IMETHODIMP nsSAXMutableAttributes::SetAttribute(PRUint32 index, const nsAString & uri, const nsAString & localName, const nsAString & qName, const nsAString & type, const nsAString & value)
{
    return NS_ERROR_NOT_IMPLEMENTED;
}

/* void setLocalName (in unsigned long index, in AString localName); */
NS_IMETHODIMP nsSAXMutableAttributes::SetLocalName(PRUint32 index, const nsAString & localName)
{
    return NS_ERROR_NOT_IMPLEMENTED;
}

/* void setQName (in unsigned long index, in AString qName); */
NS_IMETHODIMP nsSAXMutableAttributes::SetQName(PRUint32 index, const nsAString & qName)
{
    return NS_ERROR_NOT_IMPLEMENTED;
}

/* void setType (in unsigned long index, in AString type); */
NS_IMETHODIMP nsSAXMutableAttributes::SetType(PRUint32 index, const nsAString & type)
{
    return NS_ERROR_NOT_IMPLEMENTED;
}

/* void setURI (in unsigned long index, in AString uri); */
NS_IMETHODIMP nsSAXMutableAttributes::SetURI(PRUint32 index, const nsAString & uri)
{
    return NS_ERROR_NOT_IMPLEMENTED;
}

/* void setValue (in unsigned long index, in AString value); */
NS_IMETHODIMP nsSAXMutableAttributes::SetValue(PRUint32 index, const nsAString & value)
{
    return NS_ERROR_NOT_IMPLEMENTED;
}

/* End of implementation class template. */
#endif


#endif /* __gen_nsISAXMutableAttributes_h__ */
