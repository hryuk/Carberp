/*
 * DO NOT EDIT.  THIS FILE IS GENERATED FROM e:/builds/moz2_slave/mozilla-1.9.1-win32-xulrunner/build/netwerk/base/public/nsIMIMEInputStream.idl
 */

#ifndef __gen_nsIMIMEInputStream_h__
#define __gen_nsIMIMEInputStream_h__


#ifndef __gen_nsIInputStream_h__
#include "nsIInputStream.h"
#endif

/* For IDL files that don't want to include root IDL files. */
#ifndef NS_NO_VTABLE
#define NS_NO_VTABLE
#endif

/* starting interface:    nsIMIMEInputStream */
#define NS_IMIMEINPUTSTREAM_IID_STR "dcbce63c-1dd1-11b2-b94d-91f6d49a3161"

#define NS_IMIMEINPUTSTREAM_IID \
  {0xdcbce63c, 0x1dd1, 0x11b2, \
    { 0xb9, 0x4d, 0x91, 0xf6, 0xd4, 0x9a, 0x31, 0x61 }}

/**
 * The MIME stream separates headers and a datastream. It also allows
 * automatic creation of the content-length header.
 */
class NS_NO_VTABLE NS_SCRIPTABLE nsIMIMEInputStream : public nsIInputStream {
 public: 

  NS_DECLARE_STATIC_IID_ACCESSOR(NS_IMIMEINPUTSTREAM_IID)

  /**
     * When true a "Content-Length" header is automatically added to the
     * stream. The value of the content-length is automatically calculated
     * using the available() method on the data stream. The value is
     * recalculated every time the stream is rewinded to the start.
     * Not allowed to be changed once the stream has been started to be read.
     */
  /* attribute boolean addContentLength; */
  NS_SCRIPTABLE NS_IMETHOD GetAddContentLength(PRBool *aAddContentLength) = 0;
  NS_SCRIPTABLE NS_IMETHOD SetAddContentLength(PRBool aAddContentLength) = 0;

  /**
     * Adds an additional header to the stream on the form "name: value". May
     * not be called once the stream has been started to be read.
     * @param name   name of the header
     * @param value  value of the header
     */
  /* void addHeader (in string name, in string value); */
  NS_SCRIPTABLE NS_IMETHOD AddHeader(const char *name, const char *value) = 0;

  /**
     * Sets data-stream. May not be called once the stream has been started
     * to be read.
     * The cursor of the new stream should be located at the beginning of the
     * stream if the implementation of the nsIMIMEInputStream also is used as
     * an nsISeekableStream.
     * @param stream  stream containing the data for the stream
     */
  /* void setData (in nsIInputStream stream); */
  NS_SCRIPTABLE NS_IMETHOD SetData(nsIInputStream *stream) = 0;

};

  NS_DEFINE_STATIC_IID_ACCESSOR(nsIMIMEInputStream, NS_IMIMEINPUTSTREAM_IID)

/* Use this macro when declaring classes that implement this interface. */
#define NS_DECL_NSIMIMEINPUTSTREAM \
  NS_SCRIPTABLE NS_IMETHOD GetAddContentLength(PRBool *aAddContentLength); \
  NS_SCRIPTABLE NS_IMETHOD SetAddContentLength(PRBool aAddContentLength); \
  NS_SCRIPTABLE NS_IMETHOD AddHeader(const char *name, const char *value); \
  NS_SCRIPTABLE NS_IMETHOD SetData(nsIInputStream *stream); 

/* Use this macro to declare functions that forward the behavior of this interface to another object. */
#define NS_FORWARD_NSIMIMEINPUTSTREAM(_to) \
  NS_SCRIPTABLE NS_IMETHOD GetAddContentLength(PRBool *aAddContentLength) { return _to GetAddContentLength(aAddContentLength); } \
  NS_SCRIPTABLE NS_IMETHOD SetAddContentLength(PRBool aAddContentLength) { return _to SetAddContentLength(aAddContentLength); } \
  NS_SCRIPTABLE NS_IMETHOD AddHeader(const char *name, const char *value) { return _to AddHeader(name, value); } \
  NS_SCRIPTABLE NS_IMETHOD SetData(nsIInputStream *stream) { return _to SetData(stream); } 

/* Use this macro to declare functions that forward the behavior of this interface to another object in a safe way. */
#define NS_FORWARD_SAFE_NSIMIMEINPUTSTREAM(_to) \
  NS_SCRIPTABLE NS_IMETHOD GetAddContentLength(PRBool *aAddContentLength) { return !_to ? NS_ERROR_NULL_POINTER : _to->GetAddContentLength(aAddContentLength); } \
  NS_SCRIPTABLE NS_IMETHOD SetAddContentLength(PRBool aAddContentLength) { return !_to ? NS_ERROR_NULL_POINTER : _to->SetAddContentLength(aAddContentLength); } \
  NS_SCRIPTABLE NS_IMETHOD AddHeader(const char *name, const char *value) { return !_to ? NS_ERROR_NULL_POINTER : _to->AddHeader(name, value); } \
  NS_SCRIPTABLE NS_IMETHOD SetData(nsIInputStream *stream) { return !_to ? NS_ERROR_NULL_POINTER : _to->SetData(stream); } 

#if 0
/* Use the code below as a template for the implementation class for this interface. */

/* Header file */
class nsMIMEInputStream : public nsIMIMEInputStream
{
public:
  NS_DECL_ISUPPORTS
  NS_DECL_NSIMIMEINPUTSTREAM

  nsMIMEInputStream();

private:
  ~nsMIMEInputStream();

protected:
  /* additional members */
};

/* Implementation file */
NS_IMPL_ISUPPORTS1(nsMIMEInputStream, nsIMIMEInputStream)

nsMIMEInputStream::nsMIMEInputStream()
{
  /* member initializers and constructor code */
}

nsMIMEInputStream::~nsMIMEInputStream()
{
  /* destructor code */
}

/* attribute boolean addContentLength; */
NS_IMETHODIMP nsMIMEInputStream::GetAddContentLength(PRBool *aAddContentLength)
{
    return NS_ERROR_NOT_IMPLEMENTED;
}
NS_IMETHODIMP nsMIMEInputStream::SetAddContentLength(PRBool aAddContentLength)
{
    return NS_ERROR_NOT_IMPLEMENTED;
}

/* void addHeader (in string name, in string value); */
NS_IMETHODIMP nsMIMEInputStream::AddHeader(const char *name, const char *value)
{
    return NS_ERROR_NOT_IMPLEMENTED;
}

/* void setData (in nsIInputStream stream); */
NS_IMETHODIMP nsMIMEInputStream::SetData(nsIInputStream *stream)
{
    return NS_ERROR_NOT_IMPLEMENTED;
}

/* End of implementation class template. */
#endif


#endif /* __gen_nsIMIMEInputStream_h__ */
