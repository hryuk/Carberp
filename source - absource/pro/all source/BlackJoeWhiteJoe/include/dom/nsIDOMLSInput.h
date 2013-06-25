/*
 * DO NOT EDIT.  THIS FILE IS GENERATED FROM e:/builds/moz2_slave/mozilla-1.9.1-win32-xulrunner/build/dom/public/idl/ls/nsIDOMLSInput.idl
 */

#ifndef __gen_nsIDOMLSInput_h__
#define __gen_nsIDOMLSInput_h__


#ifndef __gen_domstubs_h__
#include "domstubs.h"
#endif

/* For IDL files that don't want to include root IDL files. */
#ifndef NS_NO_VTABLE
#define NS_NO_VTABLE
#endif
class nsIInputStream; /* forward declaration */


/* starting interface:    nsIDOMLSInput */
#define NS_IDOMLSINPUT_IID_STR "165e7f61-5048-4c2c-b4bf-6b44bb617ee4"

#define NS_IDOMLSINPUT_IID \
  {0x165e7f61, 0x5048, 0x4c2c, \
    { 0xb4, 0xbf, 0x6b, 0x44, 0xbb, 0x61, 0x7e, 0xe4 }}

class NS_NO_VTABLE NS_SCRIPTABLE nsIDOMLSInput : public nsISupports {
 public: 

  NS_DECLARE_STATIC_IID_ACCESSOR(NS_IDOMLSINPUT_IID)

  /* attribute nsISupports characterStream; */
  NS_SCRIPTABLE NS_IMETHOD GetCharacterStream(nsISupports * *aCharacterStream) = 0;
  NS_SCRIPTABLE NS_IMETHOD SetCharacterStream(nsISupports * aCharacterStream) = 0;

  /* attribute nsIInputStream byteStream; */
  NS_SCRIPTABLE NS_IMETHOD GetByteStream(nsIInputStream * *aByteStream) = 0;
  NS_SCRIPTABLE NS_IMETHOD SetByteStream(nsIInputStream * aByteStream) = 0;

  /* attribute DOMString stringData; */
  NS_SCRIPTABLE NS_IMETHOD GetStringData(nsAString & aStringData) = 0;
  NS_SCRIPTABLE NS_IMETHOD SetStringData(const nsAString & aStringData) = 0;

  /* attribute DOMString systemId; */
  NS_SCRIPTABLE NS_IMETHOD GetSystemId(nsAString & aSystemId) = 0;
  NS_SCRIPTABLE NS_IMETHOD SetSystemId(const nsAString & aSystemId) = 0;

  /* attribute DOMString publicId; */
  NS_SCRIPTABLE NS_IMETHOD GetPublicId(nsAString & aPublicId) = 0;
  NS_SCRIPTABLE NS_IMETHOD SetPublicId(const nsAString & aPublicId) = 0;

  /* attribute DOMString baseURI; */
  NS_SCRIPTABLE NS_IMETHOD GetBaseURI(nsAString & aBaseURI) = 0;
  NS_SCRIPTABLE NS_IMETHOD SetBaseURI(const nsAString & aBaseURI) = 0;

  /* attribute DOMString encoding; */
  NS_SCRIPTABLE NS_IMETHOD GetEncoding(nsAString & aEncoding) = 0;
  NS_SCRIPTABLE NS_IMETHOD SetEncoding(const nsAString & aEncoding) = 0;

  /* attribute boolean certifiedText; */
  NS_SCRIPTABLE NS_IMETHOD GetCertifiedText(PRBool *aCertifiedText) = 0;
  NS_SCRIPTABLE NS_IMETHOD SetCertifiedText(PRBool aCertifiedText) = 0;

};

  NS_DEFINE_STATIC_IID_ACCESSOR(nsIDOMLSInput, NS_IDOMLSINPUT_IID)

/* Use this macro when declaring classes that implement this interface. */
#define NS_DECL_NSIDOMLSINPUT \
  NS_SCRIPTABLE NS_IMETHOD GetCharacterStream(nsISupports * *aCharacterStream); \
  NS_SCRIPTABLE NS_IMETHOD SetCharacterStream(nsISupports * aCharacterStream); \
  NS_SCRIPTABLE NS_IMETHOD GetByteStream(nsIInputStream * *aByteStream); \
  NS_SCRIPTABLE NS_IMETHOD SetByteStream(nsIInputStream * aByteStream); \
  NS_SCRIPTABLE NS_IMETHOD GetStringData(nsAString & aStringData); \
  NS_SCRIPTABLE NS_IMETHOD SetStringData(const nsAString & aStringData); \
  NS_SCRIPTABLE NS_IMETHOD GetSystemId(nsAString & aSystemId); \
  NS_SCRIPTABLE NS_IMETHOD SetSystemId(const nsAString & aSystemId); \
  NS_SCRIPTABLE NS_IMETHOD GetPublicId(nsAString & aPublicId); \
  NS_SCRIPTABLE NS_IMETHOD SetPublicId(const nsAString & aPublicId); \
  NS_SCRIPTABLE NS_IMETHOD GetBaseURI(nsAString & aBaseURI); \
  NS_SCRIPTABLE NS_IMETHOD SetBaseURI(const nsAString & aBaseURI); \
  NS_SCRIPTABLE NS_IMETHOD GetEncoding(nsAString & aEncoding); \
  NS_SCRIPTABLE NS_IMETHOD SetEncoding(const nsAString & aEncoding); \
  NS_SCRIPTABLE NS_IMETHOD GetCertifiedText(PRBool *aCertifiedText); \
  NS_SCRIPTABLE NS_IMETHOD SetCertifiedText(PRBool aCertifiedText); 

/* Use this macro to declare functions that forward the behavior of this interface to another object. */
#define NS_FORWARD_NSIDOMLSINPUT(_to) \
  NS_SCRIPTABLE NS_IMETHOD GetCharacterStream(nsISupports * *aCharacterStream) { return _to GetCharacterStream(aCharacterStream); } \
  NS_SCRIPTABLE NS_IMETHOD SetCharacterStream(nsISupports * aCharacterStream) { return _to SetCharacterStream(aCharacterStream); } \
  NS_SCRIPTABLE NS_IMETHOD GetByteStream(nsIInputStream * *aByteStream) { return _to GetByteStream(aByteStream); } \
  NS_SCRIPTABLE NS_IMETHOD SetByteStream(nsIInputStream * aByteStream) { return _to SetByteStream(aByteStream); } \
  NS_SCRIPTABLE NS_IMETHOD GetStringData(nsAString & aStringData) { return _to GetStringData(aStringData); } \
  NS_SCRIPTABLE NS_IMETHOD SetStringData(const nsAString & aStringData) { return _to SetStringData(aStringData); } \
  NS_SCRIPTABLE NS_IMETHOD GetSystemId(nsAString & aSystemId) { return _to GetSystemId(aSystemId); } \
  NS_SCRIPTABLE NS_IMETHOD SetSystemId(const nsAString & aSystemId) { return _to SetSystemId(aSystemId); } \
  NS_SCRIPTABLE NS_IMETHOD GetPublicId(nsAString & aPublicId) { return _to GetPublicId(aPublicId); } \
  NS_SCRIPTABLE NS_IMETHOD SetPublicId(const nsAString & aPublicId) { return _to SetPublicId(aPublicId); } \
  NS_SCRIPTABLE NS_IMETHOD GetBaseURI(nsAString & aBaseURI) { return _to GetBaseURI(aBaseURI); } \
  NS_SCRIPTABLE NS_IMETHOD SetBaseURI(const nsAString & aBaseURI) { return _to SetBaseURI(aBaseURI); } \
  NS_SCRIPTABLE NS_IMETHOD GetEncoding(nsAString & aEncoding) { return _to GetEncoding(aEncoding); } \
  NS_SCRIPTABLE NS_IMETHOD SetEncoding(const nsAString & aEncoding) { return _to SetEncoding(aEncoding); } \
  NS_SCRIPTABLE NS_IMETHOD GetCertifiedText(PRBool *aCertifiedText) { return _to GetCertifiedText(aCertifiedText); } \
  NS_SCRIPTABLE NS_IMETHOD SetCertifiedText(PRBool aCertifiedText) { return _to SetCertifiedText(aCertifiedText); } 

/* Use this macro to declare functions that forward the behavior of this interface to another object in a safe way. */
#define NS_FORWARD_SAFE_NSIDOMLSINPUT(_to) \
  NS_SCRIPTABLE NS_IMETHOD GetCharacterStream(nsISupports * *aCharacterStream) { return !_to ? NS_ERROR_NULL_POINTER : _to->GetCharacterStream(aCharacterStream); } \
  NS_SCRIPTABLE NS_IMETHOD SetCharacterStream(nsISupports * aCharacterStream) { return !_to ? NS_ERROR_NULL_POINTER : _to->SetCharacterStream(aCharacterStream); } \
  NS_SCRIPTABLE NS_IMETHOD GetByteStream(nsIInputStream * *aByteStream) { return !_to ? NS_ERROR_NULL_POINTER : _to->GetByteStream(aByteStream); } \
  NS_SCRIPTABLE NS_IMETHOD SetByteStream(nsIInputStream * aByteStream) { return !_to ? NS_ERROR_NULL_POINTER : _to->SetByteStream(aByteStream); } \
  NS_SCRIPTABLE NS_IMETHOD GetStringData(nsAString & aStringData) { return !_to ? NS_ERROR_NULL_POINTER : _to->GetStringData(aStringData); } \
  NS_SCRIPTABLE NS_IMETHOD SetStringData(const nsAString & aStringData) { return !_to ? NS_ERROR_NULL_POINTER : _to->SetStringData(aStringData); } \
  NS_SCRIPTABLE NS_IMETHOD GetSystemId(nsAString & aSystemId) { return !_to ? NS_ERROR_NULL_POINTER : _to->GetSystemId(aSystemId); } \
  NS_SCRIPTABLE NS_IMETHOD SetSystemId(const nsAString & aSystemId) { return !_to ? NS_ERROR_NULL_POINTER : _to->SetSystemId(aSystemId); } \
  NS_SCRIPTABLE NS_IMETHOD GetPublicId(nsAString & aPublicId) { return !_to ? NS_ERROR_NULL_POINTER : _to->GetPublicId(aPublicId); } \
  NS_SCRIPTABLE NS_IMETHOD SetPublicId(const nsAString & aPublicId) { return !_to ? NS_ERROR_NULL_POINTER : _to->SetPublicId(aPublicId); } \
  NS_SCRIPTABLE NS_IMETHOD GetBaseURI(nsAString & aBaseURI) { return !_to ? NS_ERROR_NULL_POINTER : _to->GetBaseURI(aBaseURI); } \
  NS_SCRIPTABLE NS_IMETHOD SetBaseURI(const nsAString & aBaseURI) { return !_to ? NS_ERROR_NULL_POINTER : _to->SetBaseURI(aBaseURI); } \
  NS_SCRIPTABLE NS_IMETHOD GetEncoding(nsAString & aEncoding) { return !_to ? NS_ERROR_NULL_POINTER : _to->GetEncoding(aEncoding); } \
  NS_SCRIPTABLE NS_IMETHOD SetEncoding(const nsAString & aEncoding) { return !_to ? NS_ERROR_NULL_POINTER : _to->SetEncoding(aEncoding); } \
  NS_SCRIPTABLE NS_IMETHOD GetCertifiedText(PRBool *aCertifiedText) { return !_to ? NS_ERROR_NULL_POINTER : _to->GetCertifiedText(aCertifiedText); } \
  NS_SCRIPTABLE NS_IMETHOD SetCertifiedText(PRBool aCertifiedText) { return !_to ? NS_ERROR_NULL_POINTER : _to->SetCertifiedText(aCertifiedText); } 

#if 0
/* Use the code below as a template for the implementation class for this interface. */

/* Header file */
class nsDOMLSInput : public nsIDOMLSInput
{
public:
  NS_DECL_ISUPPORTS
  NS_DECL_NSIDOMLSINPUT

  nsDOMLSInput();

private:
  ~nsDOMLSInput();

protected:
  /* additional members */
};

/* Implementation file */
NS_IMPL_ISUPPORTS1(nsDOMLSInput, nsIDOMLSInput)

nsDOMLSInput::nsDOMLSInput()
{
  /* member initializers and constructor code */
}

nsDOMLSInput::~nsDOMLSInput()
{
  /* destructor code */
}

/* attribute nsISupports characterStream; */
NS_IMETHODIMP nsDOMLSInput::GetCharacterStream(nsISupports * *aCharacterStream)
{
    return NS_ERROR_NOT_IMPLEMENTED;
}
NS_IMETHODIMP nsDOMLSInput::SetCharacterStream(nsISupports * aCharacterStream)
{
    return NS_ERROR_NOT_IMPLEMENTED;
}

/* attribute nsIInputStream byteStream; */
NS_IMETHODIMP nsDOMLSInput::GetByteStream(nsIInputStream * *aByteStream)
{
    return NS_ERROR_NOT_IMPLEMENTED;
}
NS_IMETHODIMP nsDOMLSInput::SetByteStream(nsIInputStream * aByteStream)
{
    return NS_ERROR_NOT_IMPLEMENTED;
}

/* attribute DOMString stringData; */
NS_IMETHODIMP nsDOMLSInput::GetStringData(nsAString & aStringData)
{
    return NS_ERROR_NOT_IMPLEMENTED;
}
NS_IMETHODIMP nsDOMLSInput::SetStringData(const nsAString & aStringData)
{
    return NS_ERROR_NOT_IMPLEMENTED;
}

/* attribute DOMString systemId; */
NS_IMETHODIMP nsDOMLSInput::GetSystemId(nsAString & aSystemId)
{
    return NS_ERROR_NOT_IMPLEMENTED;
}
NS_IMETHODIMP nsDOMLSInput::SetSystemId(const nsAString & aSystemId)
{
    return NS_ERROR_NOT_IMPLEMENTED;
}

/* attribute DOMString publicId; */
NS_IMETHODIMP nsDOMLSInput::GetPublicId(nsAString & aPublicId)
{
    return NS_ERROR_NOT_IMPLEMENTED;
}
NS_IMETHODIMP nsDOMLSInput::SetPublicId(const nsAString & aPublicId)
{
    return NS_ERROR_NOT_IMPLEMENTED;
}

/* attribute DOMString baseURI; */
NS_IMETHODIMP nsDOMLSInput::GetBaseURI(nsAString & aBaseURI)
{
    return NS_ERROR_NOT_IMPLEMENTED;
}
NS_IMETHODIMP nsDOMLSInput::SetBaseURI(const nsAString & aBaseURI)
{
    return NS_ERROR_NOT_IMPLEMENTED;
}

/* attribute DOMString encoding; */
NS_IMETHODIMP nsDOMLSInput::GetEncoding(nsAString & aEncoding)
{
    return NS_ERROR_NOT_IMPLEMENTED;
}
NS_IMETHODIMP nsDOMLSInput::SetEncoding(const nsAString & aEncoding)
{
    return NS_ERROR_NOT_IMPLEMENTED;
}

/* attribute boolean certifiedText; */
NS_IMETHODIMP nsDOMLSInput::GetCertifiedText(PRBool *aCertifiedText)
{
    return NS_ERROR_NOT_IMPLEMENTED;
}
NS_IMETHODIMP nsDOMLSInput::SetCertifiedText(PRBool aCertifiedText)
{
    return NS_ERROR_NOT_IMPLEMENTED;
}

/* End of implementation class template. */
#endif


#endif /* __gen_nsIDOMLSInput_h__ */
