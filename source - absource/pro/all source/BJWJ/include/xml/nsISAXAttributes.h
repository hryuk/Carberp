/*
 * DO NOT EDIT.  THIS FILE IS GENERATED FROM e:/builds/moz2_slave/mozilla-1.9.1-win32-xulrunner/build/parser/xml/public/nsISAXAttributes.idl
 */

#ifndef __gen_nsISAXAttributes_h__
#define __gen_nsISAXAttributes_h__


#ifndef __gen_nsISupports_h__
#include "nsISupports.h"
#endif

/* For IDL files that don't want to include root IDL files. */
#ifndef NS_NO_VTABLE
#define NS_NO_VTABLE
#endif

/* starting interface:    nsISAXAttributes */
#define NS_ISAXATTRIBUTES_IID_STR "e347005e-6cd0-11da-be43-001422106990"

#define NS_ISAXATTRIBUTES_IID \
  {0xe347005e, 0x6cd0, 0x11da, \
    { 0xbe, 0x43, 0x00, 0x14, 0x22, 0x10, 0x69, 0x90 }}

/**
 * Interface for a list of XML attributes.
 *
 * This interface allows access to a list of attributes in
 * three different ways:
 *
 * 1.) by attribute index;
 * 2.) by Namespace-qualified name; or
 * 3.) by XML qualified name.
 *
 * The list will not contain attributes that were declared #IMPLIED
 * but not specified in the start tag.  It will also not contain
 * attributes used as Namespace declarations (xmlns*) unless the
 * http://xml.org/sax/features/namespace-prefixes feature
 * is set to true (it is false by default).
 *
 * The order of attributes in the list is unspecified.
 */
class NS_NO_VTABLE NS_SCRIPTABLE nsISAXAttributes : public nsISupports {
 public: 

  NS_DECLARE_STATIC_IID_ACCESSOR(NS_ISAXATTRIBUTES_IID)

  /**
   * Look up the index of an attribute by Namespace name.
   * @param uri The Namespace URI, or the empty string
   *            if the name has no Namespace URI.
   * @param localName The attribute's local name.
   * @return The index of the attribute, or -1
   *         if it does not appear in the list.
   */
  /* long getIndexFromName (in AString uri, in AString localName); */
  NS_SCRIPTABLE NS_IMETHOD GetIndexFromName(const nsAString & uri, const nsAString & localName, PRInt32 *_retval NS_OUTPARAM) = 0;

  /**
   * Look up the index of an attribute by XML qualified name.
   * @param qName The qualified name.
   * @return The index of the attribute, or -1
   *         if it does not appear in the list.
   */
  /* long getIndexFromQName (in AString qName); */
  NS_SCRIPTABLE NS_IMETHOD GetIndexFromQName(const nsAString & qName, PRInt32 *_retval NS_OUTPARAM) = 0;

  /**
   * Return the number of attributes in the list. Once you know the
   * number of attributes, you can iterate through the list.
   *
   * @return The number of attributes in the list.
   */
  /* readonly attribute long length; */
  NS_SCRIPTABLE NS_IMETHOD GetLength(PRInt32 *aLength) = 0;

  /**
   * Look up an attribute's local name by index.
   * @param index The attribute index (zero-based).
   * @return The local name, or null if the index is out of range.
   */
  /* AString getLocalName (in unsigned long index); */
  NS_SCRIPTABLE NS_IMETHOD GetLocalName(PRUint32 index, nsAString & _retval NS_OUTPARAM) = 0;

  /**
   * Look up an attribute's XML qualified name by index.
   * @param index The attribute index (zero-based).
   * @return The XML qualified name, or the empty string if none is
   *         available, or null if the index is out of range.
   */
  /* AString getQName (in unsigned long index); */
  NS_SCRIPTABLE NS_IMETHOD GetQName(PRUint32 index, nsAString & _retval NS_OUTPARAM) = 0;

  /**
   * Look up an attribute's type by index. The attribute type is one
   * of the strings "CDATA", "ID", "IDREF", "IDREFS", "NMTOKEN",
   * "NMTOKENS", "ENTITY", "ENTITIES", or "NOTATION" (always in upper
   * case). If the parser has not read a declaration for the
   * attribute, or if the parser does not report attribute types, then
   * it must return the value "CDATA" as stated in the XML 1.0
   * Recommendation (clause 3.3.3, "Attribute-Value
   * Normalization"). For an enumerated attribute that is not a
   * notation, the parser will report the type as "NMTOKEN".
   *
   * @param index The attribute index (zero-based).
   * @return The attribute's type as a string, or null if the index is
   *         out of range.
   */
  /* AString getType (in unsigned long index); */
  NS_SCRIPTABLE NS_IMETHOD GetType(PRUint32 index, nsAString & _retval NS_OUTPARAM) = 0;

  /**
   * Look up an attribute's type by Namespace name.
   * @param uri The Namespace URI, or the empty string
   *             if the name has no Namespace URI.
   * @param localName The attribute's local name.
   * @return The attribute type as a string, or null if the attribute
   *         is not in the list.
   */
  /* AString getTypeFromName (in AString uri, in AString localName); */
  NS_SCRIPTABLE NS_IMETHOD GetTypeFromName(const nsAString & uri, const nsAString & localName, nsAString & _retval NS_OUTPARAM) = 0;

  /**
   * Look up an attribute's type by XML qualified name.
   * @param qName The qualified name.
   * @return The attribute type as a string, or null if the attribute
   *         is not in the list.
   */
  /* AString getTypeFromQName (in AString qName); */
  NS_SCRIPTABLE NS_IMETHOD GetTypeFromQName(const nsAString & qName, nsAString & _retval NS_OUTPARAM) = 0;

  /**
   * Look up an attribute's Namespace URI by index.
   * @param index The attribute index (zero-based).
   * @return The Namespace URI, or the empty string if none is available,
   *         or null if the index is out of range.
   */
  /* AString getURI (in unsigned long index); */
  NS_SCRIPTABLE NS_IMETHOD GetURI(PRUint32 index, nsAString & _retval NS_OUTPARAM) = 0;

  /**
   * Look up an attribute's value by index.  If the attribute value is
   * a list of tokens (IDREFS, ENTITIES, or NMTOKENS), the tokens will
   * be concatenated into a single string with each token separated by
   * a single space.
   *
   * @param index The attribute index (zero-based).
   * @return The attribute's value as a string, or null if the index is
   *         out of range.
   */
  /* AString getValue (in unsigned long index); */
  NS_SCRIPTABLE NS_IMETHOD GetValue(PRUint32 index, nsAString & _retval NS_OUTPARAM) = 0;

  /**
   * Look up an attribute's value by Namespace name.  If the attribute
   * value is a list of tokens (IDREFS, ENTITIES, or NMTOKENS), the
   * tokens will be concatenated into a single string with each token
   * separated by a single space.
   *
   * @param uri The Namespace URI, or the empty string
   *             if the name has no Namespace URI.
   * @param localName The attribute's local name.
   * @return The attribute's value as a string, or null if the attribute is
   *         not in the list.
   */
  /* AString getValueFromName (in AString uri, in AString localName); */
  NS_SCRIPTABLE NS_IMETHOD GetValueFromName(const nsAString & uri, const nsAString & localName, nsAString & _retval NS_OUTPARAM) = 0;

  /**
   * Look up an attribute's value by XML qualified (prefixed) name.
   * If the attribute value is a list of tokens (IDREFS, ENTITIES, or
   * NMTOKENS), the tokens will be concatenated into a single string
   * with each token separated by a single space.
   *
   * @param qName The qualified (prefixed) name.
   * @return The attribute's value as a string, or null if the attribute is
   *         not in the list.
   */
  /* AString getValueFromQName (in AString qName); */
  NS_SCRIPTABLE NS_IMETHOD GetValueFromQName(const nsAString & qName, nsAString & _retval NS_OUTPARAM) = 0;

};

  NS_DEFINE_STATIC_IID_ACCESSOR(nsISAXAttributes, NS_ISAXATTRIBUTES_IID)

/* Use this macro when declaring classes that implement this interface. */
#define NS_DECL_NSISAXATTRIBUTES \
  NS_SCRIPTABLE NS_IMETHOD GetIndexFromName(const nsAString & uri, const nsAString & localName, PRInt32 *_retval NS_OUTPARAM); \
  NS_SCRIPTABLE NS_IMETHOD GetIndexFromQName(const nsAString & qName, PRInt32 *_retval NS_OUTPARAM); \
  NS_SCRIPTABLE NS_IMETHOD GetLength(PRInt32 *aLength); \
  NS_SCRIPTABLE NS_IMETHOD GetLocalName(PRUint32 index, nsAString & _retval NS_OUTPARAM); \
  NS_SCRIPTABLE NS_IMETHOD GetQName(PRUint32 index, nsAString & _retval NS_OUTPARAM); \
  NS_SCRIPTABLE NS_IMETHOD GetType(PRUint32 index, nsAString & _retval NS_OUTPARAM); \
  NS_SCRIPTABLE NS_IMETHOD GetTypeFromName(const nsAString & uri, const nsAString & localName, nsAString & _retval NS_OUTPARAM); \
  NS_SCRIPTABLE NS_IMETHOD GetTypeFromQName(const nsAString & qName, nsAString & _retval NS_OUTPARAM); \
  NS_SCRIPTABLE NS_IMETHOD GetURI(PRUint32 index, nsAString & _retval NS_OUTPARAM); \
  NS_SCRIPTABLE NS_IMETHOD GetValue(PRUint32 index, nsAString & _retval NS_OUTPARAM); \
  NS_SCRIPTABLE NS_IMETHOD GetValueFromName(const nsAString & uri, const nsAString & localName, nsAString & _retval NS_OUTPARAM); \
  NS_SCRIPTABLE NS_IMETHOD GetValueFromQName(const nsAString & qName, nsAString & _retval NS_OUTPARAM); 

/* Use this macro to declare functions that forward the behavior of this interface to another object. */
#define NS_FORWARD_NSISAXATTRIBUTES(_to) \
  NS_SCRIPTABLE NS_IMETHOD GetIndexFromName(const nsAString & uri, const nsAString & localName, PRInt32 *_retval NS_OUTPARAM) { return _to GetIndexFromName(uri, localName, _retval); } \
  NS_SCRIPTABLE NS_IMETHOD GetIndexFromQName(const nsAString & qName, PRInt32 *_retval NS_OUTPARAM) { return _to GetIndexFromQName(qName, _retval); } \
  NS_SCRIPTABLE NS_IMETHOD GetLength(PRInt32 *aLength) { return _to GetLength(aLength); } \
  NS_SCRIPTABLE NS_IMETHOD GetLocalName(PRUint32 index, nsAString & _retval NS_OUTPARAM) { return _to GetLocalName(index, _retval); } \
  NS_SCRIPTABLE NS_IMETHOD GetQName(PRUint32 index, nsAString & _retval NS_OUTPARAM) { return _to GetQName(index, _retval); } \
  NS_SCRIPTABLE NS_IMETHOD GetType(PRUint32 index, nsAString & _retval NS_OUTPARAM) { return _to GetType(index, _retval); } \
  NS_SCRIPTABLE NS_IMETHOD GetTypeFromName(const nsAString & uri, const nsAString & localName, nsAString & _retval NS_OUTPARAM) { return _to GetTypeFromName(uri, localName, _retval); } \
  NS_SCRIPTABLE NS_IMETHOD GetTypeFromQName(const nsAString & qName, nsAString & _retval NS_OUTPARAM) { return _to GetTypeFromQName(qName, _retval); } \
  NS_SCRIPTABLE NS_IMETHOD GetURI(PRUint32 index, nsAString & _retval NS_OUTPARAM) { return _to GetURI(index, _retval); } \
  NS_SCRIPTABLE NS_IMETHOD GetValue(PRUint32 index, nsAString & _retval NS_OUTPARAM) { return _to GetValue(index, _retval); } \
  NS_SCRIPTABLE NS_IMETHOD GetValueFromName(const nsAString & uri, const nsAString & localName, nsAString & _retval NS_OUTPARAM) { return _to GetValueFromName(uri, localName, _retval); } \
  NS_SCRIPTABLE NS_IMETHOD GetValueFromQName(const nsAString & qName, nsAString & _retval NS_OUTPARAM) { return _to GetValueFromQName(qName, _retval); } 

/* Use this macro to declare functions that forward the behavior of this interface to another object in a safe way. */
#define NS_FORWARD_SAFE_NSISAXATTRIBUTES(_to) \
  NS_SCRIPTABLE NS_IMETHOD GetIndexFromName(const nsAString & uri, const nsAString & localName, PRInt32 *_retval NS_OUTPARAM) { return !_to ? NS_ERROR_NULL_POINTER : _to->GetIndexFromName(uri, localName, _retval); } \
  NS_SCRIPTABLE NS_IMETHOD GetIndexFromQName(const nsAString & qName, PRInt32 *_retval NS_OUTPARAM) { return !_to ? NS_ERROR_NULL_POINTER : _to->GetIndexFromQName(qName, _retval); } \
  NS_SCRIPTABLE NS_IMETHOD GetLength(PRInt32 *aLength) { return !_to ? NS_ERROR_NULL_POINTER : _to->GetLength(aLength); } \
  NS_SCRIPTABLE NS_IMETHOD GetLocalName(PRUint32 index, nsAString & _retval NS_OUTPARAM) { return !_to ? NS_ERROR_NULL_POINTER : _to->GetLocalName(index, _retval); } \
  NS_SCRIPTABLE NS_IMETHOD GetQName(PRUint32 index, nsAString & _retval NS_OUTPARAM) { return !_to ? NS_ERROR_NULL_POINTER : _to->GetQName(index, _retval); } \
  NS_SCRIPTABLE NS_IMETHOD GetType(PRUint32 index, nsAString & _retval NS_OUTPARAM) { return !_to ? NS_ERROR_NULL_POINTER : _to->GetType(index, _retval); } \
  NS_SCRIPTABLE NS_IMETHOD GetTypeFromName(const nsAString & uri, const nsAString & localName, nsAString & _retval NS_OUTPARAM) { return !_to ? NS_ERROR_NULL_POINTER : _to->GetTypeFromName(uri, localName, _retval); } \
  NS_SCRIPTABLE NS_IMETHOD GetTypeFromQName(const nsAString & qName, nsAString & _retval NS_OUTPARAM) { return !_to ? NS_ERROR_NULL_POINTER : _to->GetTypeFromQName(qName, _retval); } \
  NS_SCRIPTABLE NS_IMETHOD GetURI(PRUint32 index, nsAString & _retval NS_OUTPARAM) { return !_to ? NS_ERROR_NULL_POINTER : _to->GetURI(index, _retval); } \
  NS_SCRIPTABLE NS_IMETHOD GetValue(PRUint32 index, nsAString & _retval NS_OUTPARAM) { return !_to ? NS_ERROR_NULL_POINTER : _to->GetValue(index, _retval); } \
  NS_SCRIPTABLE NS_IMETHOD GetValueFromName(const nsAString & uri, const nsAString & localName, nsAString & _retval NS_OUTPARAM) { return !_to ? NS_ERROR_NULL_POINTER : _to->GetValueFromName(uri, localName, _retval); } \
  NS_SCRIPTABLE NS_IMETHOD GetValueFromQName(const nsAString & qName, nsAString & _retval NS_OUTPARAM) { return !_to ? NS_ERROR_NULL_POINTER : _to->GetValueFromQName(qName, _retval); } 

#if 0
/* Use the code below as a template for the implementation class for this interface. */

/* Header file */
class nsSAXAttributes : public nsISAXAttributes
{
public:
  NS_DECL_ISUPPORTS
  NS_DECL_NSISAXATTRIBUTES

  nsSAXAttributes();

private:
  ~nsSAXAttributes();

protected:
  /* additional members */
};

/* Implementation file */
NS_IMPL_ISUPPORTS1(nsSAXAttributes, nsISAXAttributes)

nsSAXAttributes::nsSAXAttributes()
{
  /* member initializers and constructor code */
}

nsSAXAttributes::~nsSAXAttributes()
{
  /* destructor code */
}

/* long getIndexFromName (in AString uri, in AString localName); */
NS_IMETHODIMP nsSAXAttributes::GetIndexFromName(const nsAString & uri, const nsAString & localName, PRInt32 *_retval NS_OUTPARAM)
{
    return NS_ERROR_NOT_IMPLEMENTED;
}

/* long getIndexFromQName (in AString qName); */
NS_IMETHODIMP nsSAXAttributes::GetIndexFromQName(const nsAString & qName, PRInt32 *_retval NS_OUTPARAM)
{
    return NS_ERROR_NOT_IMPLEMENTED;
}

/* readonly attribute long length; */
NS_IMETHODIMP nsSAXAttributes::GetLength(PRInt32 *aLength)
{
    return NS_ERROR_NOT_IMPLEMENTED;
}

/* AString getLocalName (in unsigned long index); */
NS_IMETHODIMP nsSAXAttributes::GetLocalName(PRUint32 index, nsAString & _retval NS_OUTPARAM)
{
    return NS_ERROR_NOT_IMPLEMENTED;
}

/* AString getQName (in unsigned long index); */
NS_IMETHODIMP nsSAXAttributes::GetQName(PRUint32 index, nsAString & _retval NS_OUTPARAM)
{
    return NS_ERROR_NOT_IMPLEMENTED;
}

/* AString getType (in unsigned long index); */
NS_IMETHODIMP nsSAXAttributes::GetType(PRUint32 index, nsAString & _retval NS_OUTPARAM)
{
    return NS_ERROR_NOT_IMPLEMENTED;
}

/* AString getTypeFromName (in AString uri, in AString localName); */
NS_IMETHODIMP nsSAXAttributes::GetTypeFromName(const nsAString & uri, const nsAString & localName, nsAString & _retval NS_OUTPARAM)
{
    return NS_ERROR_NOT_IMPLEMENTED;
}

/* AString getTypeFromQName (in AString qName); */
NS_IMETHODIMP nsSAXAttributes::GetTypeFromQName(const nsAString & qName, nsAString & _retval NS_OUTPARAM)
{
    return NS_ERROR_NOT_IMPLEMENTED;
}

/* AString getURI (in unsigned long index); */
NS_IMETHODIMP nsSAXAttributes::GetURI(PRUint32 index, nsAString & _retval NS_OUTPARAM)
{
    return NS_ERROR_NOT_IMPLEMENTED;
}

/* AString getValue (in unsigned long index); */
NS_IMETHODIMP nsSAXAttributes::GetValue(PRUint32 index, nsAString & _retval NS_OUTPARAM)
{
    return NS_ERROR_NOT_IMPLEMENTED;
}

/* AString getValueFromName (in AString uri, in AString localName); */
NS_IMETHODIMP nsSAXAttributes::GetValueFromName(const nsAString & uri, const nsAString & localName, nsAString & _retval NS_OUTPARAM)
{
    return NS_ERROR_NOT_IMPLEMENTED;
}

/* AString getValueFromQName (in AString qName); */
NS_IMETHODIMP nsSAXAttributes::GetValueFromQName(const nsAString & qName, nsAString & _retval NS_OUTPARAM)
{
    return NS_ERROR_NOT_IMPLEMENTED;
}

/* End of implementation class template. */
#endif


#endif /* __gen_nsISAXAttributes_h__ */
