/*
 * DO NOT EDIT.  THIS FILE IS GENERATED FROM e:/builds/moz2_slave/mozilla-1.9.1-win32-xulrunner/build/intl/unicharutil/idl/nsIEntityConverter.idl
 */

#ifndef __gen_nsIEntityConverter_h__
#define __gen_nsIEntityConverter_h__


#ifndef __gen_nsISupports_h__
#include "nsISupports.h"
#endif

/* For IDL files that don't want to include root IDL files. */
#ifndef NS_NO_VTABLE
#define NS_NO_VTABLE
#endif
// {9E9B565A-8E52-4C1A-8805-B2B91655F874}
#define NS_ENTITYCONVERTER_CID { 0x9e9b565a, 0x8e52, 0x4c1a, {0x88, 0x05, 0xb2, 0xb9, 0x16, 0x55, 0xf8, 0x74}}
#define NS_ENTITYCONVERTER_CONTRACTID "@mozilla.org/intl/entityconverter;1"

/* starting interface:    nsIEntityConverter */
#define NS_IENTITYCONVERTER_IID_STR "d14c7111-55e0-11d3-91d9-00105aa3f7dc"

#define NS_IENTITYCONVERTER_IID \
  {0xd14c7111, 0x55e0, 0x11d3, \
    { 0x91, 0xd9, 0x00, 0x10, 0x5a, 0xa3, 0xf7, 0xdc }}

class NS_NO_VTABLE NS_SCRIPTABLE nsIEntityConverter : public nsISupports {
 public: 

  NS_DECLARE_STATIC_IID_ACCESSOR(NS_IENTITYCONVERTER_IID)

  enum { entityNone = 0U };

  enum { html40Latin1 = 1U };

  enum { html40Symbols = 2U };

  enum { html40Special = 4U };

  enum { transliterate = 8U };

  enum { mathml20 = 16U };

  enum { html32 = 1U };

  enum { html40 = 7U };

  enum { entityW3C = 23U };

  /* string ConvertUTF32ToEntity (in unsigned long character, in unsigned long entityVersion); */
  NS_SCRIPTABLE NS_IMETHOD ConvertUTF32ToEntity(PRUint32 character, PRUint32 entityVersion, char **_retval NS_OUTPARAM) = 0;

  /* string ConvertToEntity (in wchar character, in unsigned long entityVersion); */
  NS_SCRIPTABLE NS_IMETHOD ConvertToEntity(PRUnichar character, PRUint32 entityVersion, char **_retval NS_OUTPARAM) = 0;

  /* wstring ConvertToEntities (in wstring inString, in unsigned long entityVersion); */
  NS_SCRIPTABLE NS_IMETHOD ConvertToEntities(const PRUnichar *inString, PRUint32 entityVersion, PRUnichar **_retval NS_OUTPARAM) = 0;

};

  NS_DEFINE_STATIC_IID_ACCESSOR(nsIEntityConverter, NS_IENTITYCONVERTER_IID)

/* Use this macro when declaring classes that implement this interface. */
#define NS_DECL_NSIENTITYCONVERTER \
  NS_SCRIPTABLE NS_IMETHOD ConvertUTF32ToEntity(PRUint32 character, PRUint32 entityVersion, char **_retval NS_OUTPARAM); \
  NS_SCRIPTABLE NS_IMETHOD ConvertToEntity(PRUnichar character, PRUint32 entityVersion, char **_retval NS_OUTPARAM); \
  NS_SCRIPTABLE NS_IMETHOD ConvertToEntities(const PRUnichar *inString, PRUint32 entityVersion, PRUnichar **_retval NS_OUTPARAM); 

/* Use this macro to declare functions that forward the behavior of this interface to another object. */
#define NS_FORWARD_NSIENTITYCONVERTER(_to) \
  NS_SCRIPTABLE NS_IMETHOD ConvertUTF32ToEntity(PRUint32 character, PRUint32 entityVersion, char **_retval NS_OUTPARAM) { return _to ConvertUTF32ToEntity(character, entityVersion, _retval); } \
  NS_SCRIPTABLE NS_IMETHOD ConvertToEntity(PRUnichar character, PRUint32 entityVersion, char **_retval NS_OUTPARAM) { return _to ConvertToEntity(character, entityVersion, _retval); } \
  NS_SCRIPTABLE NS_IMETHOD ConvertToEntities(const PRUnichar *inString, PRUint32 entityVersion, PRUnichar **_retval NS_OUTPARAM) { return _to ConvertToEntities(inString, entityVersion, _retval); } 

/* Use this macro to declare functions that forward the behavior of this interface to another object in a safe way. */
#define NS_FORWARD_SAFE_NSIENTITYCONVERTER(_to) \
  NS_SCRIPTABLE NS_IMETHOD ConvertUTF32ToEntity(PRUint32 character, PRUint32 entityVersion, char **_retval NS_OUTPARAM) { return !_to ? NS_ERROR_NULL_POINTER : _to->ConvertUTF32ToEntity(character, entityVersion, _retval); } \
  NS_SCRIPTABLE NS_IMETHOD ConvertToEntity(PRUnichar character, PRUint32 entityVersion, char **_retval NS_OUTPARAM) { return !_to ? NS_ERROR_NULL_POINTER : _to->ConvertToEntity(character, entityVersion, _retval); } \
  NS_SCRIPTABLE NS_IMETHOD ConvertToEntities(const PRUnichar *inString, PRUint32 entityVersion, PRUnichar **_retval NS_OUTPARAM) { return !_to ? NS_ERROR_NULL_POINTER : _to->ConvertToEntities(inString, entityVersion, _retval); } 

#if 0
/* Use the code below as a template for the implementation class for this interface. */

/* Header file */
class nsEntityConverter : public nsIEntityConverter
{
public:
  NS_DECL_ISUPPORTS
  NS_DECL_NSIENTITYCONVERTER

  nsEntityConverter();

private:
  ~nsEntityConverter();

protected:
  /* additional members */
};

/* Implementation file */
NS_IMPL_ISUPPORTS1(nsEntityConverter, nsIEntityConverter)

nsEntityConverter::nsEntityConverter()
{
  /* member initializers and constructor code */
}

nsEntityConverter::~nsEntityConverter()
{
  /* destructor code */
}

/* string ConvertUTF32ToEntity (in unsigned long character, in unsigned long entityVersion); */
NS_IMETHODIMP nsEntityConverter::ConvertUTF32ToEntity(PRUint32 character, PRUint32 entityVersion, char **_retval NS_OUTPARAM)
{
    return NS_ERROR_NOT_IMPLEMENTED;
}

/* string ConvertToEntity (in wchar character, in unsigned long entityVersion); */
NS_IMETHODIMP nsEntityConverter::ConvertToEntity(PRUnichar character, PRUint32 entityVersion, char **_retval NS_OUTPARAM)
{
    return NS_ERROR_NOT_IMPLEMENTED;
}

/* wstring ConvertToEntities (in wstring inString, in unsigned long entityVersion); */
NS_IMETHODIMP nsEntityConverter::ConvertToEntities(const PRUnichar *inString, PRUint32 entityVersion, PRUnichar **_retval NS_OUTPARAM)
{
    return NS_ERROR_NOT_IMPLEMENTED;
}

/* End of implementation class template. */
#endif


#endif /* __gen_nsIEntityConverter_h__ */
