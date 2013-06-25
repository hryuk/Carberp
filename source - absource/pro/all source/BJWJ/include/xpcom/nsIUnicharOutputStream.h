/*
 * DO NOT EDIT.  THIS FILE IS GENERATED FROM e:/builds/moz2_slave/mozilla-1.9.1-win32-xulrunner/build/xpcom/io/nsIUnicharOutputStream.idl
 */

#ifndef __gen_nsIUnicharOutputStream_h__
#define __gen_nsIUnicharOutputStream_h__


#ifndef __gen_nsISupports_h__
#include "nsISupports.h"
#endif

/* For IDL files that don't want to include root IDL files. */
#ifndef NS_NO_VTABLE
#define NS_NO_VTABLE
#endif

/* starting interface:    nsIUnicharOutputStream */
#define NS_IUNICHAROUTPUTSTREAM_IID_STR "2d00b1bb-8b21-4a63-bcc6-7213f513ac2e"

#define NS_IUNICHAROUTPUTSTREAM_IID \
  {0x2d00b1bb, 0x8b21, 0x4a63, \
    { 0xbc, 0xc6, 0x72, 0x13, 0xf5, 0x13, 0xac, 0x2e }}

/**
 * An interface that allows writing unicode data.
 */
class NS_NO_VTABLE NS_SCRIPTABLE nsIUnicharOutputStream : public nsISupports {
 public: 

  NS_DECLARE_STATIC_IID_ACCESSOR(NS_IUNICHAROUTPUTSTREAM_IID)

  /**
     * Write a single character to the stream. When writing many characters,
     * prefer the string-taking write method.
     *
     * @retval true The character was written successfully
     * @retval false Not all bytes of the character could be written.
     */
  /* boolean write (in unsigned long aCount, [array, size_is (aCount), const] in PRUnichar c); */
  NS_SCRIPTABLE NS_IMETHOD Write(PRUint32 aCount, const PRUnichar *c, PRBool *_retval NS_OUTPARAM) = 0;

  /**
     * Write a string to the stream.
     *
     * @retval true The string was written successfully
     * @retval false Not all bytes of the string could be written.
     */
  /* boolean writeString (in AString str); */
  NS_SCRIPTABLE NS_IMETHOD WriteString(const nsAString & str, PRBool *_retval NS_OUTPARAM) = 0;

  /**
     * Flush the stream. This finishes the conversion and writes any bytes that
     * finish the current byte sequence.
     *
     * It does NOT flush the underlying stream.
     *
     * @see nsIUnicodeEncoder::Finish
     */
  /* void flush (); */
  NS_SCRIPTABLE NS_IMETHOD Flush(void) = 0;

  /**
     * Close the stream and free associated resources. This also closes the
     * underlying stream.
     */
  /* void close (); */
  NS_SCRIPTABLE NS_IMETHOD Close(void) = 0;

};

  NS_DEFINE_STATIC_IID_ACCESSOR(nsIUnicharOutputStream, NS_IUNICHAROUTPUTSTREAM_IID)

/* Use this macro when declaring classes that implement this interface. */
#define NS_DECL_NSIUNICHAROUTPUTSTREAM \
  NS_SCRIPTABLE NS_IMETHOD Write(PRUint32 aCount, const PRUnichar *c, PRBool *_retval NS_OUTPARAM); \
  NS_SCRIPTABLE NS_IMETHOD WriteString(const nsAString & str, PRBool *_retval NS_OUTPARAM); \
  NS_SCRIPTABLE NS_IMETHOD Flush(void); \
  NS_SCRIPTABLE NS_IMETHOD Close(void); 

/* Use this macro to declare functions that forward the behavior of this interface to another object. */
#define NS_FORWARD_NSIUNICHAROUTPUTSTREAM(_to) \
  NS_SCRIPTABLE NS_IMETHOD Write(PRUint32 aCount, const PRUnichar *c, PRBool *_retval NS_OUTPARAM) { return _to Write(aCount, c, _retval); } \
  NS_SCRIPTABLE NS_IMETHOD WriteString(const nsAString & str, PRBool *_retval NS_OUTPARAM) { return _to WriteString(str, _retval); } \
  NS_SCRIPTABLE NS_IMETHOD Flush(void) { return _to Flush(); } \
  NS_SCRIPTABLE NS_IMETHOD Close(void) { return _to Close(); } 

/* Use this macro to declare functions that forward the behavior of this interface to another object in a safe way. */
#define NS_FORWARD_SAFE_NSIUNICHAROUTPUTSTREAM(_to) \
  NS_SCRIPTABLE NS_IMETHOD Write(PRUint32 aCount, const PRUnichar *c, PRBool *_retval NS_OUTPARAM) { return !_to ? NS_ERROR_NULL_POINTER : _to->Write(aCount, c, _retval); } \
  NS_SCRIPTABLE NS_IMETHOD WriteString(const nsAString & str, PRBool *_retval NS_OUTPARAM) { return !_to ? NS_ERROR_NULL_POINTER : _to->WriteString(str, _retval); } \
  NS_SCRIPTABLE NS_IMETHOD Flush(void) { return !_to ? NS_ERROR_NULL_POINTER : _to->Flush(); } \
  NS_SCRIPTABLE NS_IMETHOD Close(void) { return !_to ? NS_ERROR_NULL_POINTER : _to->Close(); } 

#if 0
/* Use the code below as a template for the implementation class for this interface. */

/* Header file */
class nsUnicharOutputStream : public nsIUnicharOutputStream
{
public:
  NS_DECL_ISUPPORTS
  NS_DECL_NSIUNICHAROUTPUTSTREAM

  nsUnicharOutputStream();

private:
  ~nsUnicharOutputStream();

protected:
  /* additional members */
};

/* Implementation file */
NS_IMPL_ISUPPORTS1(nsUnicharOutputStream, nsIUnicharOutputStream)

nsUnicharOutputStream::nsUnicharOutputStream()
{
  /* member initializers and constructor code */
}

nsUnicharOutputStream::~nsUnicharOutputStream()
{
  /* destructor code */
}

/* boolean write (in unsigned long aCount, [array, size_is (aCount), const] in PRUnichar c); */
NS_IMETHODIMP nsUnicharOutputStream::Write(PRUint32 aCount, const PRUnichar *c, PRBool *_retval NS_OUTPARAM)
{
    return NS_ERROR_NOT_IMPLEMENTED;
}

/* boolean writeString (in AString str); */
NS_IMETHODIMP nsUnicharOutputStream::WriteString(const nsAString & str, PRBool *_retval NS_OUTPARAM)
{
    return NS_ERROR_NOT_IMPLEMENTED;
}

/* void flush (); */
NS_IMETHODIMP nsUnicharOutputStream::Flush()
{
    return NS_ERROR_NOT_IMPLEMENTED;
}

/* void close (); */
NS_IMETHODIMP nsUnicharOutputStream::Close()
{
    return NS_ERROR_NOT_IMPLEMENTED;
}

/* End of implementation class template. */
#endif


#endif /* __gen_nsIUnicharOutputStream_h__ */
