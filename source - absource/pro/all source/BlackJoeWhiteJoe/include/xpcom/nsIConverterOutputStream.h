/*
 * DO NOT EDIT.  THIS FILE IS GENERATED FROM e:/builds/moz2_slave/mozilla-1.9.1-win32-xulrunner/build/xpcom/io/nsIConverterOutputStream.idl
 */

#ifndef __gen_nsIConverterOutputStream_h__
#define __gen_nsIConverterOutputStream_h__


#ifndef __gen_nsIUnicharOutputStream_h__
#include "nsIUnicharOutputStream.h"
#endif

/* For IDL files that don't want to include root IDL files. */
#ifndef NS_NO_VTABLE
#define NS_NO_VTABLE
#endif
class nsIOutputStream; /* forward declaration */


/* starting interface:    nsIConverterOutputStream */
#define NS_ICONVERTEROUTPUTSTREAM_IID_STR "4b71113a-cb0d-479f-8ed5-01daeba2e8d4"

#define NS_ICONVERTEROUTPUTSTREAM_IID \
  {0x4b71113a, 0xcb0d, 0x479f, \
    { 0x8e, 0xd5, 0x01, 0xda, 0xeb, 0xa2, 0xe8, 0xd4 }}

/**
 * This interface allows writing strings to a stream, doing automatic
 * character encoding conversion.
 */
class NS_NO_VTABLE NS_SCRIPTABLE nsIConverterOutputStream : public nsIUnicharOutputStream {
 public: 

  NS_DECLARE_STATIC_IID_ACCESSOR(NS_ICONVERTEROUTPUTSTREAM_IID)

  /**
     * Initialize this stream. Must be called before any other method on this
     * interface, or you will crash. The output stream passed to this method
     * must not be null, or you will crash.
     *
     * @param aOutStream
     *        The underlying output stream to which the converted strings will
     *        be written.
     * @param aCharset
     *        The character set to use for encoding the characters. A null
     *        charset will be interpreted as UTF-8.
     * @param aBufferSize
     *        How many bytes to buffer. A value of 0 means that no bytes will be
     *        buffered. Implementations not supporting buffering may ignore
     *        this parameter.
     * @param aReplacementCharacter
     *        The replacement character to use when an unsupported character is found.
     *        The character must be encodable in the selected character
     *        encoding; otherwise, attempts to write an unsupported character
     *        will throw NS_ERROR_LOSS_OF_SIGNIFICANT_DATA.
     *
     *        A value of 0x0000 will cause an exception to be thrown upon
     *        attempts to write unsupported characters.
     */
  /* void init (in nsIOutputStream aOutStream, in string aCharset, in unsigned long aBufferSize, in PRUnichar aReplacementCharacter); */
  NS_SCRIPTABLE NS_IMETHOD Init(nsIOutputStream *aOutStream, const char *aCharset, PRUint32 aBufferSize, PRUnichar aReplacementCharacter) = 0;

};

  NS_DEFINE_STATIC_IID_ACCESSOR(nsIConverterOutputStream, NS_ICONVERTEROUTPUTSTREAM_IID)

/* Use this macro when declaring classes that implement this interface. */
#define NS_DECL_NSICONVERTEROUTPUTSTREAM \
  NS_SCRIPTABLE NS_IMETHOD Init(nsIOutputStream *aOutStream, const char *aCharset, PRUint32 aBufferSize, PRUnichar aReplacementCharacter); 

/* Use this macro to declare functions that forward the behavior of this interface to another object. */
#define NS_FORWARD_NSICONVERTEROUTPUTSTREAM(_to) \
  NS_SCRIPTABLE NS_IMETHOD Init(nsIOutputStream *aOutStream, const char *aCharset, PRUint32 aBufferSize, PRUnichar aReplacementCharacter) { return _to Init(aOutStream, aCharset, aBufferSize, aReplacementCharacter); } 

/* Use this macro to declare functions that forward the behavior of this interface to another object in a safe way. */
#define NS_FORWARD_SAFE_NSICONVERTEROUTPUTSTREAM(_to) \
  NS_SCRIPTABLE NS_IMETHOD Init(nsIOutputStream *aOutStream, const char *aCharset, PRUint32 aBufferSize, PRUnichar aReplacementCharacter) { return !_to ? NS_ERROR_NULL_POINTER : _to->Init(aOutStream, aCharset, aBufferSize, aReplacementCharacter); } 

#if 0
/* Use the code below as a template for the implementation class for this interface. */

/* Header file */
class nsConverterOutputStream : public nsIConverterOutputStream
{
public:
  NS_DECL_ISUPPORTS
  NS_DECL_NSICONVERTEROUTPUTSTREAM

  nsConverterOutputStream();

private:
  ~nsConverterOutputStream();

protected:
  /* additional members */
};

/* Implementation file */
NS_IMPL_ISUPPORTS1(nsConverterOutputStream, nsIConverterOutputStream)

nsConverterOutputStream::nsConverterOutputStream()
{
  /* member initializers and constructor code */
}

nsConverterOutputStream::~nsConverterOutputStream()
{
  /* destructor code */
}

/* void init (in nsIOutputStream aOutStream, in string aCharset, in unsigned long aBufferSize, in PRUnichar aReplacementCharacter); */
NS_IMETHODIMP nsConverterOutputStream::Init(nsIOutputStream *aOutStream, const char *aCharset, PRUint32 aBufferSize, PRUnichar aReplacementCharacter)
{
    return NS_ERROR_NOT_IMPLEMENTED;
}

/* End of implementation class template. */
#endif


#endif /* __gen_nsIConverterOutputStream_h__ */
