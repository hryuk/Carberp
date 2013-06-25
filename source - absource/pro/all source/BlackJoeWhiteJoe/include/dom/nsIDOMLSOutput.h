/*
 * DO NOT EDIT.  THIS FILE IS GENERATED FROM e:/builds/moz2_slave/mozilla-1.9.1-win32-xulrunner/build/dom/public/idl/ls/nsIDOMLSOutput.idl
 */

#ifndef __gen_nsIDOMLSOutput_h__
#define __gen_nsIDOMLSOutput_h__


#ifndef __gen_domstubs_h__
#include "domstubs.h"
#endif

/* For IDL files that don't want to include root IDL files. */
#ifndef NS_NO_VTABLE
#define NS_NO_VTABLE
#endif
class nsIOutputStream; /* forward declaration */


/* starting interface:    nsIDOMLSOutput */
#define NS_IDOMLSOUTPUT_IID_STR "757e9971-8890-478d-a53a-07f9f6f6e0d3"

#define NS_IDOMLSOUTPUT_IID \
  {0x757e9971, 0x8890, 0x478d, \
    { 0xa5, 0x3a, 0x07, 0xf9, 0xf6, 0xf6, 0xe0, 0xd3 }}

class NS_NO_VTABLE NS_SCRIPTABLE nsIDOMLSOutput : public nsISupports {
 public: 

  NS_DECLARE_STATIC_IID_ACCESSOR(NS_IDOMLSOUTPUT_IID)

  /* attribute nsISupports characterStream; */
  NS_SCRIPTABLE NS_IMETHOD GetCharacterStream(nsISupports * *aCharacterStream) = 0;
  NS_SCRIPTABLE NS_IMETHOD SetCharacterStream(nsISupports * aCharacterStream) = 0;

  /* attribute nsIOutputStream byteStream; */
  NS_SCRIPTABLE NS_IMETHOD GetByteStream(nsIOutputStream * *aByteStream) = 0;
  NS_SCRIPTABLE NS_IMETHOD SetByteStream(nsIOutputStream * aByteStream) = 0;

  /* attribute DOMString systemId; */
  NS_SCRIPTABLE NS_IMETHOD GetSystemId(nsAString & aSystemId) = 0;
  NS_SCRIPTABLE NS_IMETHOD SetSystemId(const nsAString & aSystemId) = 0;

  /* attribute DOMString encoding; */
  NS_SCRIPTABLE NS_IMETHOD GetEncoding(nsAString & aEncoding) = 0;
  NS_SCRIPTABLE NS_IMETHOD SetEncoding(const nsAString & aEncoding) = 0;

};

  NS_DEFINE_STATIC_IID_ACCESSOR(nsIDOMLSOutput, NS_IDOMLSOUTPUT_IID)

/* Use this macro when declaring classes that implement this interface. */
#define NS_DECL_NSIDOMLSOUTPUT \
  NS_SCRIPTABLE NS_IMETHOD GetCharacterStream(nsISupports * *aCharacterStream); \
  NS_SCRIPTABLE NS_IMETHOD SetCharacterStream(nsISupports * aCharacterStream); \
  NS_SCRIPTABLE NS_IMETHOD GetByteStream(nsIOutputStream * *aByteStream); \
  NS_SCRIPTABLE NS_IMETHOD SetByteStream(nsIOutputStream * aByteStream); \
  NS_SCRIPTABLE NS_IMETHOD GetSystemId(nsAString & aSystemId); \
  NS_SCRIPTABLE NS_IMETHOD SetSystemId(const nsAString & aSystemId); \
  NS_SCRIPTABLE NS_IMETHOD GetEncoding(nsAString & aEncoding); \
  NS_SCRIPTABLE NS_IMETHOD SetEncoding(const nsAString & aEncoding); 

/* Use this macro to declare functions that forward the behavior of this interface to another object. */
#define NS_FORWARD_NSIDOMLSOUTPUT(_to) \
  NS_SCRIPTABLE NS_IMETHOD GetCharacterStream(nsISupports * *aCharacterStream) { return _to GetCharacterStream(aCharacterStream); } \
  NS_SCRIPTABLE NS_IMETHOD SetCharacterStream(nsISupports * aCharacterStream) { return _to SetCharacterStream(aCharacterStream); } \
  NS_SCRIPTABLE NS_IMETHOD GetByteStream(nsIOutputStream * *aByteStream) { return _to GetByteStream(aByteStream); } \
  NS_SCRIPTABLE NS_IMETHOD SetByteStream(nsIOutputStream * aByteStream) { return _to SetByteStream(aByteStream); } \
  NS_SCRIPTABLE NS_IMETHOD GetSystemId(nsAString & aSystemId) { return _to GetSystemId(aSystemId); } \
  NS_SCRIPTABLE NS_IMETHOD SetSystemId(const nsAString & aSystemId) { return _to SetSystemId(aSystemId); } \
  NS_SCRIPTABLE NS_IMETHOD GetEncoding(nsAString & aEncoding) { return _to GetEncoding(aEncoding); } \
  NS_SCRIPTABLE NS_IMETHOD SetEncoding(const nsAString & aEncoding) { return _to SetEncoding(aEncoding); } 

/* Use this macro to declare functions that forward the behavior of this interface to another object in a safe way. */
#define NS_FORWARD_SAFE_NSIDOMLSOUTPUT(_to) \
  NS_SCRIPTABLE NS_IMETHOD GetCharacterStream(nsISupports * *aCharacterStream) { return !_to ? NS_ERROR_NULL_POINTER : _to->GetCharacterStream(aCharacterStream); } \
  NS_SCRIPTABLE NS_IMETHOD SetCharacterStream(nsISupports * aCharacterStream) { return !_to ? NS_ERROR_NULL_POINTER : _to->SetCharacterStream(aCharacterStream); } \
  NS_SCRIPTABLE NS_IMETHOD GetByteStream(nsIOutputStream * *aByteStream) { return !_to ? NS_ERROR_NULL_POINTER : _to->GetByteStream(aByteStream); } \
  NS_SCRIPTABLE NS_IMETHOD SetByteStream(nsIOutputStream * aByteStream) { return !_to ? NS_ERROR_NULL_POINTER : _to->SetByteStream(aByteStream); } \
  NS_SCRIPTABLE NS_IMETHOD GetSystemId(nsAString & aSystemId) { return !_to ? NS_ERROR_NULL_POINTER : _to->GetSystemId(aSystemId); } \
  NS_SCRIPTABLE NS_IMETHOD SetSystemId(const nsAString & aSystemId) { return !_to ? NS_ERROR_NULL_POINTER : _to->SetSystemId(aSystemId); } \
  NS_SCRIPTABLE NS_IMETHOD GetEncoding(nsAString & aEncoding) { return !_to ? NS_ERROR_NULL_POINTER : _to->GetEncoding(aEncoding); } \
  NS_SCRIPTABLE NS_IMETHOD SetEncoding(const nsAString & aEncoding) { return !_to ? NS_ERROR_NULL_POINTER : _to->SetEncoding(aEncoding); } 

#if 0
/* Use the code below as a template for the implementation class for this interface. */

/* Header file */
class nsDOMLSOutput : public nsIDOMLSOutput
{
public:
  NS_DECL_ISUPPORTS
  NS_DECL_NSIDOMLSOUTPUT

  nsDOMLSOutput();

private:
  ~nsDOMLSOutput();

protected:
  /* additional members */
};

/* Implementation file */
NS_IMPL_ISUPPORTS1(nsDOMLSOutput, nsIDOMLSOutput)

nsDOMLSOutput::nsDOMLSOutput()
{
  /* member initializers and constructor code */
}

nsDOMLSOutput::~nsDOMLSOutput()
{
  /* destructor code */
}

/* attribute nsISupports characterStream; */
NS_IMETHODIMP nsDOMLSOutput::GetCharacterStream(nsISupports * *aCharacterStream)
{
    return NS_ERROR_NOT_IMPLEMENTED;
}
NS_IMETHODIMP nsDOMLSOutput::SetCharacterStream(nsISupports * aCharacterStream)
{
    return NS_ERROR_NOT_IMPLEMENTED;
}

/* attribute nsIOutputStream byteStream; */
NS_IMETHODIMP nsDOMLSOutput::GetByteStream(nsIOutputStream * *aByteStream)
{
    return NS_ERROR_NOT_IMPLEMENTED;
}
NS_IMETHODIMP nsDOMLSOutput::SetByteStream(nsIOutputStream * aByteStream)
{
    return NS_ERROR_NOT_IMPLEMENTED;
}

/* attribute DOMString systemId; */
NS_IMETHODIMP nsDOMLSOutput::GetSystemId(nsAString & aSystemId)
{
    return NS_ERROR_NOT_IMPLEMENTED;
}
NS_IMETHODIMP nsDOMLSOutput::SetSystemId(const nsAString & aSystemId)
{
    return NS_ERROR_NOT_IMPLEMENTED;
}

/* attribute DOMString encoding; */
NS_IMETHODIMP nsDOMLSOutput::GetEncoding(nsAString & aEncoding)
{
    return NS_ERROR_NOT_IMPLEMENTED;
}
NS_IMETHODIMP nsDOMLSOutput::SetEncoding(const nsAString & aEncoding)
{
    return NS_ERROR_NOT_IMPLEMENTED;
}

/* End of implementation class template. */
#endif


#endif /* __gen_nsIDOMLSOutput_h__ */
