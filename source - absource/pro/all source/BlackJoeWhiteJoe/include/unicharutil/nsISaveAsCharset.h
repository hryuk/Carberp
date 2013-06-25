/*
 * DO NOT EDIT.  THIS FILE IS GENERATED FROM e:/builds/moz2_slave/mozilla-1.9.1-win32-xulrunner/build/intl/unicharutil/idl/nsISaveAsCharset.idl
 */

#ifndef __gen_nsISaveAsCharset_h__
#define __gen_nsISaveAsCharset_h__


#ifndef __gen_nsISupports_h__
#include "nsISupports.h"
#endif

#ifndef __gen_nsIEntityConverter_h__
#include "nsIEntityConverter.h"
#endif

/* For IDL files that don't want to include root IDL files. */
#ifndef NS_NO_VTABLE
#define NS_NO_VTABLE
#endif
#define NS_SAVEASCHARSET_CID { 0xcd233e0, 0x7a86, 0x11d3, { 0x91, 0x5c, 0x0, 0x60, 0x8, 0xa6, 0xed, 0xf6 } }
#define NS_SAVEASCHARSET_CONTRACTID "@mozilla.org/intl/saveascharset;1"

/* starting interface:    nsISaveAsCharset */
#define NS_ISAVEASCHARSET_IID_STR "33b87f70-7a9c-11d3-915c-006008a6edf6"

#define NS_ISAVEASCHARSET_IID \
  {0x33b87f70, 0x7a9c, 0x11d3, \
    { 0x91, 0x5c, 0x00, 0x60, 0x08, 0xa6, 0xed, 0xf6 }}

class NS_NO_VTABLE NS_SCRIPTABLE nsISaveAsCharset : public nsISupports {
 public: 

  NS_DECLARE_STATIC_IID_ACCESSOR(NS_ISAVEASCHARSET_IID)

  enum { mask_Fallback = 255U };

  enum { mask_Entity = 768U };

  enum { mask_CharsetFallback = 1024U };

  enum { attr_FallbackNone = 0U };

  enum { attr_FallbackQuestionMark = 1U };

  enum { attr_FallbackEscapeU = 2U };

  enum { attr_FallbackDecimalNCR = 3U };

  enum { attr_FallbackHexNCR = 4U };

  enum { attr_EntityNone = 0U };

  enum { attr_EntityBeforeCharsetConv = 256U };

  enum { attr_EntityAfterCharsetConv = 512U };

  enum { attr_CharsetFallback = 1024U };

  enum { attr_plainTextDefault = 0U };

  enum { attr_htmlTextDefault = 259U };

  /* readonly attribute string charset; */
  NS_SCRIPTABLE NS_IMETHOD GetCharset(char * *aCharset) = 0;

  /* void Init (in string charset, in unsigned long attr, in unsigned long entityVersion); */
  NS_SCRIPTABLE NS_IMETHOD Init(const char *charset, PRUint32 attr, PRUint32 entityVersion) = 0;

  /* string Convert (in wstring inString); */
  NS_SCRIPTABLE NS_IMETHOD Convert(const PRUnichar *inString, char **_retval NS_OUTPARAM) = 0;

};

  NS_DEFINE_STATIC_IID_ACCESSOR(nsISaveAsCharset, NS_ISAVEASCHARSET_IID)

/* Use this macro when declaring classes that implement this interface. */
#define NS_DECL_NSISAVEASCHARSET \
  NS_SCRIPTABLE NS_IMETHOD GetCharset(char * *aCharset); \
  NS_SCRIPTABLE NS_IMETHOD Init(const char *charset, PRUint32 attr, PRUint32 entityVersion); \
  NS_SCRIPTABLE NS_IMETHOD Convert(const PRUnichar *inString, char **_retval NS_OUTPARAM); 

/* Use this macro to declare functions that forward the behavior of this interface to another object. */
#define NS_FORWARD_NSISAVEASCHARSET(_to) \
  NS_SCRIPTABLE NS_IMETHOD GetCharset(char * *aCharset) { return _to GetCharset(aCharset); } \
  NS_SCRIPTABLE NS_IMETHOD Init(const char *charset, PRUint32 attr, PRUint32 entityVersion) { return _to Init(charset, attr, entityVersion); } \
  NS_SCRIPTABLE NS_IMETHOD Convert(const PRUnichar *inString, char **_retval NS_OUTPARAM) { return _to Convert(inString, _retval); } 

/* Use this macro to declare functions that forward the behavior of this interface to another object in a safe way. */
#define NS_FORWARD_SAFE_NSISAVEASCHARSET(_to) \
  NS_SCRIPTABLE NS_IMETHOD GetCharset(char * *aCharset) { return !_to ? NS_ERROR_NULL_POINTER : _to->GetCharset(aCharset); } \
  NS_SCRIPTABLE NS_IMETHOD Init(const char *charset, PRUint32 attr, PRUint32 entityVersion) { return !_to ? NS_ERROR_NULL_POINTER : _to->Init(charset, attr, entityVersion); } \
  NS_SCRIPTABLE NS_IMETHOD Convert(const PRUnichar *inString, char **_retval NS_OUTPARAM) { return !_to ? NS_ERROR_NULL_POINTER : _to->Convert(inString, _retval); } 

#if 0
/* Use the code below as a template for the implementation class for this interface. */

/* Header file */
class nsSaveAsCharset : public nsISaveAsCharset
{
public:
  NS_DECL_ISUPPORTS
  NS_DECL_NSISAVEASCHARSET

  nsSaveAsCharset();

private:
  ~nsSaveAsCharset();

protected:
  /* additional members */
};

/* Implementation file */
NS_IMPL_ISUPPORTS1(nsSaveAsCharset, nsISaveAsCharset)

nsSaveAsCharset::nsSaveAsCharset()
{
  /* member initializers and constructor code */
}

nsSaveAsCharset::~nsSaveAsCharset()
{
  /* destructor code */
}

/* readonly attribute string charset; */
NS_IMETHODIMP nsSaveAsCharset::GetCharset(char * *aCharset)
{
    return NS_ERROR_NOT_IMPLEMENTED;
}

/* void Init (in string charset, in unsigned long attr, in unsigned long entityVersion); */
NS_IMETHODIMP nsSaveAsCharset::Init(const char *charset, PRUint32 attr, PRUint32 entityVersion)
{
    return NS_ERROR_NOT_IMPLEMENTED;
}

/* string Convert (in wstring inString); */
NS_IMETHODIMP nsSaveAsCharset::Convert(const PRUnichar *inString, char **_retval NS_OUTPARAM)
{
    return NS_ERROR_NOT_IMPLEMENTED;
}

/* End of implementation class template. */
#endif


#endif /* __gen_nsISaveAsCharset_h__ */
