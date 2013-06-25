/*
 * DO NOT EDIT.  THIS FILE IS GENERATED FROM e:/builds/moz2_slave/mozilla-1.9.1-win32-xulrunner/build/xpcom/io/nsILineInputStream.idl
 */

#ifndef __gen_nsILineInputStream_h__
#define __gen_nsILineInputStream_h__


#ifndef __gen_nsISupports_h__
#include "nsISupports.h"
#endif

/* For IDL files that don't want to include root IDL files. */
#ifndef NS_NO_VTABLE
#define NS_NO_VTABLE
#endif
class nsILineInputStream; /* forward declaration */


/* starting interface:    nsILineInputStream */
#define NS_ILINEINPUTSTREAM_IID_STR "c97b466c-1e6e-4773-a4ab-2b2b3190a7a6"

#define NS_ILINEINPUTSTREAM_IID \
  {0xc97b466c, 0x1e6e, 0x4773, \
    { 0xa4, 0xab, 0x2b, 0x2b, 0x31, 0x90, 0xa7, 0xa6 }}

class NS_NO_VTABLE NS_SCRIPTABLE nsILineInputStream : public nsISupports {
 public: 

  NS_DECLARE_STATIC_IID_ACCESSOR(NS_ILINEINPUTSTREAM_IID)

  /**
   * Read a single line from the stream, where a line is a 
   * possibly zero length sequence of 8bit chars terminated by a
   * CR, LF, CRLF, LFCR, or eof.
   * The line terminator is not returned.
   * @retval false
   *         End of file. This line is the last line of the file
   *         (aLine is valid).
   * @retval true
   *         The file contains further lines.
   * @note Do not mix readLine with other read functions.
   *       Doing so can cause various problems and is not supported.
   */
  /* boolean readLine (out ACString aLine); */
  NS_SCRIPTABLE NS_IMETHOD ReadLine(nsACString & aLine NS_OUTPARAM, PRBool *_retval NS_OUTPARAM) = 0;

};

  NS_DEFINE_STATIC_IID_ACCESSOR(nsILineInputStream, NS_ILINEINPUTSTREAM_IID)

/* Use this macro when declaring classes that implement this interface. */
#define NS_DECL_NSILINEINPUTSTREAM \
  NS_SCRIPTABLE NS_IMETHOD ReadLine(nsACString & aLine NS_OUTPARAM, PRBool *_retval NS_OUTPARAM); 

/* Use this macro to declare functions that forward the behavior of this interface to another object. */
#define NS_FORWARD_NSILINEINPUTSTREAM(_to) \
  NS_SCRIPTABLE NS_IMETHOD ReadLine(nsACString & aLine NS_OUTPARAM, PRBool *_retval NS_OUTPARAM) { return _to ReadLine(aLine, _retval); } 

/* Use this macro to declare functions that forward the behavior of this interface to another object in a safe way. */
#define NS_FORWARD_SAFE_NSILINEINPUTSTREAM(_to) \
  NS_SCRIPTABLE NS_IMETHOD ReadLine(nsACString & aLine NS_OUTPARAM, PRBool *_retval NS_OUTPARAM) { return !_to ? NS_ERROR_NULL_POINTER : _to->ReadLine(aLine, _retval); } 

#if 0
/* Use the code below as a template for the implementation class for this interface. */

/* Header file */
class nsLineInputStream : public nsILineInputStream
{
public:
  NS_DECL_ISUPPORTS
  NS_DECL_NSILINEINPUTSTREAM

  nsLineInputStream();

private:
  ~nsLineInputStream();

protected:
  /* additional members */
};

/* Implementation file */
NS_IMPL_ISUPPORTS1(nsLineInputStream, nsILineInputStream)

nsLineInputStream::nsLineInputStream()
{
  /* member initializers and constructor code */
}

nsLineInputStream::~nsLineInputStream()
{
  /* destructor code */
}

/* boolean readLine (out ACString aLine); */
NS_IMETHODIMP nsLineInputStream::ReadLine(nsACString & aLine NS_OUTPARAM, PRBool *_retval NS_OUTPARAM)
{
    return NS_ERROR_NOT_IMPLEMENTED;
}

/* End of implementation class template. */
#endif


#endif /* __gen_nsILineInputStream_h__ */
