/*
 * DO NOT EDIT.  THIS FILE IS GENERATED FROM e:/builds/moz2_slave/mozilla-1.9.1-win32-xulrunner/build/parser/htmlparser/public/nsIExtendedExpatSink.idl
 */

#ifndef __gen_nsIExtendedExpatSink_h__
#define __gen_nsIExtendedExpatSink_h__


#ifndef __gen_nsIExpatSink_h__
#include "nsIExpatSink.h"
#endif

/* For IDL files that don't want to include root IDL files. */
#ifndef NS_NO_VTABLE
#define NS_NO_VTABLE
#endif

/* starting interface:    nsIExtendedExpatSink */
#define NS_IEXTENDEDEXPATSINK_IID_STR "0c2dc80f-7aa4-467a-9454-b89dba0e0779"

#define NS_IEXTENDEDEXPATSINK_IID \
  {0x0c2dc80f, 0x7aa4, 0x467a, \
    { 0x94, 0x54, 0xb8, 0x9d, 0xba, 0x0e, 0x07, 0x79 }}

/**
 * This interface provides notification of syntax-level events.
 */
class NS_NO_VTABLE NS_SCRIPTABLE nsIExtendedExpatSink : public nsIExpatSink {
 public: 

  NS_DECLARE_STATIC_IID_ACCESSOR(NS_IEXTENDEDEXPATSINK_IID)

  /**
   * Called at the beginning of the DTD, before any entity or notation
   * events.
   * @param aDoctypeName The document type name.
   * @param aSysid The declared system identifier for the external DTD subset,
   *               or null if none was declared.
   * @param aPubid The declared public identifier for the external DTD subset,
   *               or null if none was declared.
   */
  /* void handleStartDTD (in wstring aDoctypeName, in wstring aSysid, in wstring aPubid); */
  NS_SCRIPTABLE NS_IMETHOD HandleStartDTD(const PRUnichar *aDoctypeName, const PRUnichar *aSysid, const PRUnichar *aPubid) = 0;

  /**
   * Called when a prefix mapping starts to be in-scope, before any
   * startElement events.
   * @param aPrefix The Namespace prefix being declared. An empty string
   *                is used for the default element namespace, which has
   *                no prefix.
   * @param aUri The Namespace URI the prefix is mapped to.
   */
  /* void handleStartNamespaceDecl (in wstring aPrefix, in wstring aUri); */
  NS_SCRIPTABLE NS_IMETHOD HandleStartNamespaceDecl(const PRUnichar *aPrefix, const PRUnichar *aUri) = 0;

  /**
   * Called when a prefix mapping is no longer in-scope, after any
   * endElement events.
   * @param aPrefix The prefix that was being mapped. This is the empty string
   *                when a default mapping scope ends.
   */
  /* void handleEndNamespaceDecl (in wstring aPrefix); */
  NS_SCRIPTABLE NS_IMETHOD HandleEndNamespaceDecl(const PRUnichar *aPrefix) = 0;

  /**
   * This is called for a declaration of notation.  The base argument is
   * whatever was set by XML_SetBase. aNotationName will never be
   * null. The other arguments can be.
   * @param aNotationName The notation name.
   * @param aSysId The notation's system identifier, or null if none was given.
   * @param aPubId The notation's pubilc identifier, or null if none was given.
   */
  /* void handleNotationDecl (in wstring aNotationName, in wstring aSysid, in wstring aPubid); */
  NS_SCRIPTABLE NS_IMETHOD HandleNotationDecl(const PRUnichar *aNotationName, const PRUnichar *aSysid, const PRUnichar *aPubid) = 0;

  /**
   * This is called for a declaration of an unparsed (NDATA) entity.
   * aName, aSysid and aNotationName arguments will never be
   * null. The other arguments may be.
   * @param aName  The unparsed entity's name.
   * @param aSysId The notation's system identifier.
   * @param aPubId The notation's pubilc identifier, or null if none was given.
   * @param aNotationName The name of the associated notation.
   */
  /* void handleUnparsedEntityDecl (in wstring aName, in wstring aSysid, in wstring aPubid, in wstring aNotationName); */
  NS_SCRIPTABLE NS_IMETHOD HandleUnparsedEntityDecl(const PRUnichar *aName, const PRUnichar *aSysid, const PRUnichar *aPubid, const PRUnichar *aNotationName) = 0;

};

  NS_DEFINE_STATIC_IID_ACCESSOR(nsIExtendedExpatSink, NS_IEXTENDEDEXPATSINK_IID)

/* Use this macro when declaring classes that implement this interface. */
#define NS_DECL_NSIEXTENDEDEXPATSINK \
  NS_SCRIPTABLE NS_IMETHOD HandleStartDTD(const PRUnichar *aDoctypeName, const PRUnichar *aSysid, const PRUnichar *aPubid); \
  NS_SCRIPTABLE NS_IMETHOD HandleStartNamespaceDecl(const PRUnichar *aPrefix, const PRUnichar *aUri); \
  NS_SCRIPTABLE NS_IMETHOD HandleEndNamespaceDecl(const PRUnichar *aPrefix); \
  NS_SCRIPTABLE NS_IMETHOD HandleNotationDecl(const PRUnichar *aNotationName, const PRUnichar *aSysid, const PRUnichar *aPubid); \
  NS_SCRIPTABLE NS_IMETHOD HandleUnparsedEntityDecl(const PRUnichar *aName, const PRUnichar *aSysid, const PRUnichar *aPubid, const PRUnichar *aNotationName); 

/* Use this macro to declare functions that forward the behavior of this interface to another object. */
#define NS_FORWARD_NSIEXTENDEDEXPATSINK(_to) \
  NS_SCRIPTABLE NS_IMETHOD HandleStartDTD(const PRUnichar *aDoctypeName, const PRUnichar *aSysid, const PRUnichar *aPubid) { return _to HandleStartDTD(aDoctypeName, aSysid, aPubid); } \
  NS_SCRIPTABLE NS_IMETHOD HandleStartNamespaceDecl(const PRUnichar *aPrefix, const PRUnichar *aUri) { return _to HandleStartNamespaceDecl(aPrefix, aUri); } \
  NS_SCRIPTABLE NS_IMETHOD HandleEndNamespaceDecl(const PRUnichar *aPrefix) { return _to HandleEndNamespaceDecl(aPrefix); } \
  NS_SCRIPTABLE NS_IMETHOD HandleNotationDecl(const PRUnichar *aNotationName, const PRUnichar *aSysid, const PRUnichar *aPubid) { return _to HandleNotationDecl(aNotationName, aSysid, aPubid); } \
  NS_SCRIPTABLE NS_IMETHOD HandleUnparsedEntityDecl(const PRUnichar *aName, const PRUnichar *aSysid, const PRUnichar *aPubid, const PRUnichar *aNotationName) { return _to HandleUnparsedEntityDecl(aName, aSysid, aPubid, aNotationName); } 

/* Use this macro to declare functions that forward the behavior of this interface to another object in a safe way. */
#define NS_FORWARD_SAFE_NSIEXTENDEDEXPATSINK(_to) \
  NS_SCRIPTABLE NS_IMETHOD HandleStartDTD(const PRUnichar *aDoctypeName, const PRUnichar *aSysid, const PRUnichar *aPubid) { return !_to ? NS_ERROR_NULL_POINTER : _to->HandleStartDTD(aDoctypeName, aSysid, aPubid); } \
  NS_SCRIPTABLE NS_IMETHOD HandleStartNamespaceDecl(const PRUnichar *aPrefix, const PRUnichar *aUri) { return !_to ? NS_ERROR_NULL_POINTER : _to->HandleStartNamespaceDecl(aPrefix, aUri); } \
  NS_SCRIPTABLE NS_IMETHOD HandleEndNamespaceDecl(const PRUnichar *aPrefix) { return !_to ? NS_ERROR_NULL_POINTER : _to->HandleEndNamespaceDecl(aPrefix); } \
  NS_SCRIPTABLE NS_IMETHOD HandleNotationDecl(const PRUnichar *aNotationName, const PRUnichar *aSysid, const PRUnichar *aPubid) { return !_to ? NS_ERROR_NULL_POINTER : _to->HandleNotationDecl(aNotationName, aSysid, aPubid); } \
  NS_SCRIPTABLE NS_IMETHOD HandleUnparsedEntityDecl(const PRUnichar *aName, const PRUnichar *aSysid, const PRUnichar *aPubid, const PRUnichar *aNotationName) { return !_to ? NS_ERROR_NULL_POINTER : _to->HandleUnparsedEntityDecl(aName, aSysid, aPubid, aNotationName); } 

#if 0
/* Use the code below as a template for the implementation class for this interface. */

/* Header file */
class nsExtendedExpatSink : public nsIExtendedExpatSink
{
public:
  NS_DECL_ISUPPORTS
  NS_DECL_NSIEXTENDEDEXPATSINK

  nsExtendedExpatSink();

private:
  ~nsExtendedExpatSink();

protected:
  /* additional members */
};

/* Implementation file */
NS_IMPL_ISUPPORTS1(nsExtendedExpatSink, nsIExtendedExpatSink)

nsExtendedExpatSink::nsExtendedExpatSink()
{
  /* member initializers and constructor code */
}

nsExtendedExpatSink::~nsExtendedExpatSink()
{
  /* destructor code */
}

/* void handleStartDTD (in wstring aDoctypeName, in wstring aSysid, in wstring aPubid); */
NS_IMETHODIMP nsExtendedExpatSink::HandleStartDTD(const PRUnichar *aDoctypeName, const PRUnichar *aSysid, const PRUnichar *aPubid)
{
    return NS_ERROR_NOT_IMPLEMENTED;
}

/* void handleStartNamespaceDecl (in wstring aPrefix, in wstring aUri); */
NS_IMETHODIMP nsExtendedExpatSink::HandleStartNamespaceDecl(const PRUnichar *aPrefix, const PRUnichar *aUri)
{
    return NS_ERROR_NOT_IMPLEMENTED;
}

/* void handleEndNamespaceDecl (in wstring aPrefix); */
NS_IMETHODIMP nsExtendedExpatSink::HandleEndNamespaceDecl(const PRUnichar *aPrefix)
{
    return NS_ERROR_NOT_IMPLEMENTED;
}

/* void handleNotationDecl (in wstring aNotationName, in wstring aSysid, in wstring aPubid); */
NS_IMETHODIMP nsExtendedExpatSink::HandleNotationDecl(const PRUnichar *aNotationName, const PRUnichar *aSysid, const PRUnichar *aPubid)
{
    return NS_ERROR_NOT_IMPLEMENTED;
}

/* void handleUnparsedEntityDecl (in wstring aName, in wstring aSysid, in wstring aPubid, in wstring aNotationName); */
NS_IMETHODIMP nsExtendedExpatSink::HandleUnparsedEntityDecl(const PRUnichar *aName, const PRUnichar *aSysid, const PRUnichar *aPubid, const PRUnichar *aNotationName)
{
    return NS_ERROR_NOT_IMPLEMENTED;
}

/* End of implementation class template. */
#endif


#endif /* __gen_nsIExtendedExpatSink_h__ */
