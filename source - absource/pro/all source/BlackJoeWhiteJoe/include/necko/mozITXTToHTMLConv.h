/*
 * DO NOT EDIT.  THIS FILE IS GENERATED FROM e:/builds/moz2_slave/mozilla-1.9.1-win32-xulrunner/build/netwerk/streamconv/public/mozITXTToHTMLConv.idl
 */

#ifndef __gen_mozITXTToHTMLConv_h__
#define __gen_mozITXTToHTMLConv_h__


#ifndef __gen_nsIStreamConverter_h__
#include "nsIStreamConverter.h"
#endif

#ifndef __gen_nsrootidl_h__
#include "nsrootidl.h"
#endif

/* For IDL files that don't want to include root IDL files. */
#ifndef NS_NO_VTABLE
#define NS_NO_VTABLE
#endif
// {77c0e42a-1dd2-11b2-8ebf-edc6606f2f4b}
#define MOZITXTTOHTMLCONV_CID \
    { 0x77c0e42a, 0x1dd2, 0x11b2, \
    { 0x8e, 0xbf, 0xed, 0xc6, 0x60, 0x6f, 0x2f, 0x4b } }
	
#define MOZ_TXTTOHTMLCONV_CONTRACTID \
  "@mozilla.org/txttohtmlconv;1"

/* starting interface:    mozITXTToHTMLConv */
#define MOZITXTTOHTMLCONV_IID_STR "77c0e42a-1dd2-11b2-8ebf-edc6606f2f4b"

#define MOZITXTTOHTMLCONV_IID \
  {0x77c0e42a, 0x1dd2, 0x11b2, \
    { 0x8e, 0xbf, 0xed, 0xc6, 0x60, 0x6f, 0x2f, 0x4b }}

class NS_NO_VTABLE NS_SCRIPTABLE mozITXTToHTMLConv : public nsIStreamConverter {
 public: 

  NS_DECLARE_STATIC_IID_ACCESSOR(MOZITXTTOHTMLCONV_IID)

  enum { kEntities = 0U };

  enum { kURLs = 2U };

  enum { kGlyphSubstitution = 4U };

  enum { kStructPhrase = 8U };

  /**
  @param text: plain text to scan. May be a line, paragraph (recommended)
               or just a substring.<p>
               Must be non-escaped, pure unicode.<p>
               <em>Note:</em> ScanTXT(a, o) + ScanTXT(b, o) may be !=
               Scan(a + b, o)
  @param whattodo: Bitfield describing the modes of operation
  @result      "<", ">" and "&" are escaped and HTML tags are inserted where
               appropriate.
 */
  /* wstring scanTXT (in wstring text, in unsigned long whattodo); */
  NS_SCRIPTABLE NS_IMETHOD ScanTXT(const PRUnichar *text, PRUint32 whattodo, PRUnichar **_retval NS_OUTPARAM) = 0;

  /**
  Adds additional formatting to user edited text, that the user was too lazy
  or "unknowledged" (DELETEME: is that a word?) to make.
  <p>
  <em>Note:</em> Don't use kGlyphSubstitution with this function. This option
  generates tags, that are unuseable for UAs other than Mozilla. This would
  be a data loss bug.

  @param text: HTML source to scan. May be a line, paragraph (recommended)
               or just a substring.<p>
               Must be correct HTML. "<", ">" and "&" must be escaped,
               other chars must be pure unicode.<p>
               <em>Note:</em> ScanTXT(a, o) + ScanTXT(b, o) may be !=
               Scan(a + b, o)
  @param whattodo: Bitfield describing the modes of operation
  @result      Additional HTML tags are inserted where appropriate.
 */
  /* wstring scanHTML (in wstring text, in unsigned long whattodo); */
  NS_SCRIPTABLE NS_IMETHOD ScanHTML(const PRUnichar *text, PRUint32 whattodo, PRUnichar **_retval NS_OUTPARAM) = 0;

  /**
  @param line: line in original msg, possibly starting starting with
               txt quote tags like ">"
  @param logLineStart: pos in line, where the real content (logical line)
               begins, i.e. pos after all txt quote tags.
               E.g. position of "t" in "> > text".
               Initial value must be 0, unless line is not real line.
  @return      Cite Level, i.e. number of txt quote tags found, i.e. number of
               nested quotes.
 */
  /* unsigned long citeLevelTXT (in wstring line, out unsigned long logLineStart); */
  NS_SCRIPTABLE NS_IMETHOD CiteLevelTXT(const PRUnichar *line, PRUint32 *logLineStart NS_OUTPARAM, PRUint32 *_retval NS_OUTPARAM) = 0;

  /** 
 @param a wide string to scan for the presence of a URL.
 @param aLength --> the length of the buffer to be scanned
 @param aPos --> the position in the buffer to start scanning for a url

 aStartPos --> index into the start of a url (-1 if no url found)
 aEndPos --> index of the last character in the url (-1 if no url found)
 */
  /* void findURLInPlaintext (in wstring text, in long aLength, in long aPos, out long aStartPos, out long aEndPos); */
  NS_SCRIPTABLE NS_IMETHOD FindURLInPlaintext(const PRUnichar *text, PRInt32 aLength, PRInt32 aPos, PRInt32 *aStartPos NS_OUTPARAM, PRInt32 *aEndPos NS_OUTPARAM) = 0;

};

  NS_DEFINE_STATIC_IID_ACCESSOR(mozITXTToHTMLConv, MOZITXTTOHTMLCONV_IID)

/* Use this macro when declaring classes that implement this interface. */
#define NS_DECL_MOZITXTTOHTMLCONV \
  NS_SCRIPTABLE NS_IMETHOD ScanTXT(const PRUnichar *text, PRUint32 whattodo, PRUnichar **_retval NS_OUTPARAM); \
  NS_SCRIPTABLE NS_IMETHOD ScanHTML(const PRUnichar *text, PRUint32 whattodo, PRUnichar **_retval NS_OUTPARAM); \
  NS_SCRIPTABLE NS_IMETHOD CiteLevelTXT(const PRUnichar *line, PRUint32 *logLineStart NS_OUTPARAM, PRUint32 *_retval NS_OUTPARAM); \
  NS_SCRIPTABLE NS_IMETHOD FindURLInPlaintext(const PRUnichar *text, PRInt32 aLength, PRInt32 aPos, PRInt32 *aStartPos NS_OUTPARAM, PRInt32 *aEndPos NS_OUTPARAM); 

/* Use this macro to declare functions that forward the behavior of this interface to another object. */
#define NS_FORWARD_MOZITXTTOHTMLCONV(_to) \
  NS_SCRIPTABLE NS_IMETHOD ScanTXT(const PRUnichar *text, PRUint32 whattodo, PRUnichar **_retval NS_OUTPARAM) { return _to ScanTXT(text, whattodo, _retval); } \
  NS_SCRIPTABLE NS_IMETHOD ScanHTML(const PRUnichar *text, PRUint32 whattodo, PRUnichar **_retval NS_OUTPARAM) { return _to ScanHTML(text, whattodo, _retval); } \
  NS_SCRIPTABLE NS_IMETHOD CiteLevelTXT(const PRUnichar *line, PRUint32 *logLineStart NS_OUTPARAM, PRUint32 *_retval NS_OUTPARAM) { return _to CiteLevelTXT(line, logLineStart, _retval); } \
  NS_SCRIPTABLE NS_IMETHOD FindURLInPlaintext(const PRUnichar *text, PRInt32 aLength, PRInt32 aPos, PRInt32 *aStartPos NS_OUTPARAM, PRInt32 *aEndPos NS_OUTPARAM) { return _to FindURLInPlaintext(text, aLength, aPos, aStartPos, aEndPos); } 

/* Use this macro to declare functions that forward the behavior of this interface to another object in a safe way. */
#define NS_FORWARD_SAFE_MOZITXTTOHTMLCONV(_to) \
  NS_SCRIPTABLE NS_IMETHOD ScanTXT(const PRUnichar *text, PRUint32 whattodo, PRUnichar **_retval NS_OUTPARAM) { return !_to ? NS_ERROR_NULL_POINTER : _to->ScanTXT(text, whattodo, _retval); } \
  NS_SCRIPTABLE NS_IMETHOD ScanHTML(const PRUnichar *text, PRUint32 whattodo, PRUnichar **_retval NS_OUTPARAM) { return !_to ? NS_ERROR_NULL_POINTER : _to->ScanHTML(text, whattodo, _retval); } \
  NS_SCRIPTABLE NS_IMETHOD CiteLevelTXT(const PRUnichar *line, PRUint32 *logLineStart NS_OUTPARAM, PRUint32 *_retval NS_OUTPARAM) { return !_to ? NS_ERROR_NULL_POINTER : _to->CiteLevelTXT(line, logLineStart, _retval); } \
  NS_SCRIPTABLE NS_IMETHOD FindURLInPlaintext(const PRUnichar *text, PRInt32 aLength, PRInt32 aPos, PRInt32 *aStartPos NS_OUTPARAM, PRInt32 *aEndPos NS_OUTPARAM) { return !_to ? NS_ERROR_NULL_POINTER : _to->FindURLInPlaintext(text, aLength, aPos, aStartPos, aEndPos); } 

#if 0
/* Use the code below as a template for the implementation class for this interface. */

/* Header file */
class _MYCLASS_ : public mozITXTToHTMLConv
{
public:
  NS_DECL_ISUPPORTS
  NS_DECL_MOZITXTTOHTMLCONV

  _MYCLASS_();

private:
  ~_MYCLASS_();

protected:
  /* additional members */
};

/* Implementation file */
NS_IMPL_ISUPPORTS1(_MYCLASS_, mozITXTToHTMLConv)

_MYCLASS_::_MYCLASS_()
{
  /* member initializers and constructor code */
}

_MYCLASS_::~_MYCLASS_()
{
  /* destructor code */
}

/* wstring scanTXT (in wstring text, in unsigned long whattodo); */
NS_IMETHODIMP _MYCLASS_::ScanTXT(const PRUnichar *text, PRUint32 whattodo, PRUnichar **_retval NS_OUTPARAM)
{
    return NS_ERROR_NOT_IMPLEMENTED;
}

/* wstring scanHTML (in wstring text, in unsigned long whattodo); */
NS_IMETHODIMP _MYCLASS_::ScanHTML(const PRUnichar *text, PRUint32 whattodo, PRUnichar **_retval NS_OUTPARAM)
{
    return NS_ERROR_NOT_IMPLEMENTED;
}

/* unsigned long citeLevelTXT (in wstring line, out unsigned long logLineStart); */
NS_IMETHODIMP _MYCLASS_::CiteLevelTXT(const PRUnichar *line, PRUint32 *logLineStart NS_OUTPARAM, PRUint32 *_retval NS_OUTPARAM)
{
    return NS_ERROR_NOT_IMPLEMENTED;
}

/* void findURLInPlaintext (in wstring text, in long aLength, in long aPos, out long aStartPos, out long aEndPos); */
NS_IMETHODIMP _MYCLASS_::FindURLInPlaintext(const PRUnichar *text, PRInt32 aLength, PRInt32 aPos, PRInt32 *aStartPos NS_OUTPARAM, PRInt32 *aEndPos NS_OUTPARAM)
{
    return NS_ERROR_NOT_IMPLEMENTED;
}

/* End of implementation class template. */
#endif


#endif /* __gen_mozITXTToHTMLConv_h__ */
