/*
 * DO NOT EDIT.  THIS FILE IS GENERATED FROM e:/builds/moz2_slave/mozilla-1.9.1-win32-xulrunner/build/intl/lwbrk/idl/nsISemanticUnitScanner.idl
 */

#ifndef __gen_nsISemanticUnitScanner_h__
#define __gen_nsISemanticUnitScanner_h__


#ifndef __gen_nsISupports_h__
#include "nsISupports.h"
#endif

/* For IDL files that don't want to include root IDL files. */
#ifndef NS_NO_VTABLE
#define NS_NO_VTABLE
#endif
// {ADF42751-1CEF-4ad2-AA8E-BCB849D8D31F}
#define NS_SEMANTICUNITSCANNER_CID { 0xadf42751, 0x1cef, 0x4ad2, { 0xaa, 0x8e, 0xbc, 0xb8, 0x49, 0xd8, 0xd3, 0x1f}}
#define NS_SEMANTICUNITSCANNER_CONTRACTID "@mozilla.org/intl/semanticunitscanner;1"

/* starting interface:    nsISemanticUnitScanner */
#define NS_ISEMANTICUNITSCANNER_IID_STR "9f620be4-e535-11d6-b254-00039310a47a"

#define NS_ISEMANTICUNITSCANNER_IID \
  {0x9f620be4, 0xe535, 0x11d6, \
    { 0xb2, 0x54, 0x00, 0x03, 0x93, 0x10, 0xa4, 0x7a }}

/**
 * Provides a language independent way to break UNICODE
 * text into meaningful semantic units (e.g. words).
 */
class NS_NO_VTABLE NS_SCRIPTABLE nsISemanticUnitScanner : public nsISupports {
 public: 

  NS_DECLARE_STATIC_IID_ACCESSOR(NS_ISEMANTICUNITSCANNER_IID)

  /**
     * start()
     *
     * Starts up the semantic unit scanner with an optional
     * character set, which acts as a hint to optimize the heuristics
     * used to determine the language(s) of the processed text.
     *
     * @param characterSet the character set the text was originally
     *                     encoded in (can be NULL)
     */
  /* void start (in string characterSet); */
  NS_SCRIPTABLE NS_IMETHOD Start(const char *characterSet) = 0;

  /**
     * next()
     * Get the begin / end offset of the next unit in the current text
     *
     * @param text the text to be scanned
     * @param length the number of characters in the text to be processed
     * @param pos the current position
     * @param isLastBuffer, the buffer is the last one
     * @param begin the begin offset of the next unit 
     * @param begin the end offset of the next unit 
     * @return has more unit in the current text
     */
  /* boolean next (in wstring text, in long length, in long pos, in boolean isLastBuffer, out long begin, out long end); */
  NS_SCRIPTABLE NS_IMETHOD Next(const PRUnichar *text, PRInt32 length, PRInt32 pos, PRBool isLastBuffer, PRInt32 *begin NS_OUTPARAM, PRInt32 *end NS_OUTPARAM, PRBool *_retval NS_OUTPARAM) = 0;

};

  NS_DEFINE_STATIC_IID_ACCESSOR(nsISemanticUnitScanner, NS_ISEMANTICUNITSCANNER_IID)

/* Use this macro when declaring classes that implement this interface. */
#define NS_DECL_NSISEMANTICUNITSCANNER \
  NS_SCRIPTABLE NS_IMETHOD Start(const char *characterSet); \
  NS_SCRIPTABLE NS_IMETHOD Next(const PRUnichar *text, PRInt32 length, PRInt32 pos, PRBool isLastBuffer, PRInt32 *begin NS_OUTPARAM, PRInt32 *end NS_OUTPARAM, PRBool *_retval NS_OUTPARAM); 

/* Use this macro to declare functions that forward the behavior of this interface to another object. */
#define NS_FORWARD_NSISEMANTICUNITSCANNER(_to) \
  NS_SCRIPTABLE NS_IMETHOD Start(const char *characterSet) { return _to Start(characterSet); } \
  NS_SCRIPTABLE NS_IMETHOD Next(const PRUnichar *text, PRInt32 length, PRInt32 pos, PRBool isLastBuffer, PRInt32 *begin NS_OUTPARAM, PRInt32 *end NS_OUTPARAM, PRBool *_retval NS_OUTPARAM) { return _to Next(text, length, pos, isLastBuffer, begin, end, _retval); } 

/* Use this macro to declare functions that forward the behavior of this interface to another object in a safe way. */
#define NS_FORWARD_SAFE_NSISEMANTICUNITSCANNER(_to) \
  NS_SCRIPTABLE NS_IMETHOD Start(const char *characterSet) { return !_to ? NS_ERROR_NULL_POINTER : _to->Start(characterSet); } \
  NS_SCRIPTABLE NS_IMETHOD Next(const PRUnichar *text, PRInt32 length, PRInt32 pos, PRBool isLastBuffer, PRInt32 *begin NS_OUTPARAM, PRInt32 *end NS_OUTPARAM, PRBool *_retval NS_OUTPARAM) { return !_to ? NS_ERROR_NULL_POINTER : _to->Next(text, length, pos, isLastBuffer, begin, end, _retval); } 

#if 0
/* Use the code below as a template for the implementation class for this interface. */

/* Header file */
class nsSemanticUnitScanner : public nsISemanticUnitScanner
{
public:
  NS_DECL_ISUPPORTS
  NS_DECL_NSISEMANTICUNITSCANNER

  nsSemanticUnitScanner();

private:
  ~nsSemanticUnitScanner();

protected:
  /* additional members */
};

/* Implementation file */
NS_IMPL_ISUPPORTS1(nsSemanticUnitScanner, nsISemanticUnitScanner)

nsSemanticUnitScanner::nsSemanticUnitScanner()
{
  /* member initializers and constructor code */
}

nsSemanticUnitScanner::~nsSemanticUnitScanner()
{
  /* destructor code */
}

/* void start (in string characterSet); */
NS_IMETHODIMP nsSemanticUnitScanner::Start(const char *characterSet)
{
    return NS_ERROR_NOT_IMPLEMENTED;
}

/* boolean next (in wstring text, in long length, in long pos, in boolean isLastBuffer, out long begin, out long end); */
NS_IMETHODIMP nsSemanticUnitScanner::Next(const PRUnichar *text, PRInt32 length, PRInt32 pos, PRBool isLastBuffer, PRInt32 *begin NS_OUTPARAM, PRInt32 *end NS_OUTPARAM, PRBool *_retval NS_OUTPARAM)
{
    return NS_ERROR_NOT_IMPLEMENTED;
}

/* End of implementation class template. */
#endif


#endif /* __gen_nsISemanticUnitScanner_h__ */
