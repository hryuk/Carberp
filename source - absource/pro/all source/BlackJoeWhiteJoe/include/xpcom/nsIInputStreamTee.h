/*
 * DO NOT EDIT.  THIS FILE IS GENERATED FROM e:/builds/moz2_slave/mozilla-1.9.1-win32-xulrunner/build/xpcom/io/nsIInputStreamTee.idl
 */

#ifndef __gen_nsIInputStreamTee_h__
#define __gen_nsIInputStreamTee_h__


#ifndef __gen_nsIInputStream_h__
#include "nsIInputStream.h"
#endif

/* For IDL files that don't want to include root IDL files. */
#ifndef NS_NO_VTABLE
#define NS_NO_VTABLE
#endif
class nsIOutputStream; /* forward declaration */


/* starting interface:    nsIInputStreamTee */
#define NS_IINPUTSTREAMTEE_IID_STR "44e8b2c8-1ecb-4a63-8b23-3e3500c34f32"

#define NS_IINPUTSTREAMTEE_IID \
  {0x44e8b2c8, 0x1ecb, 0x4a63, \
    { 0x8b, 0x23, 0x3e, 0x35, 0x00, 0xc3, 0x4f, 0x32 }}

/**
 * A nsIInputStreamTee is a wrapper for an input stream, that when read
 * reads the specified amount of data from its |source| and copies that
 * data to its |sink|.  |sink| must be a blocking output stream.
 */
class NS_NO_VTABLE NS_SCRIPTABLE nsIInputStreamTee : public nsIInputStream {
 public: 

  NS_DECLARE_STATIC_IID_ACCESSOR(NS_IINPUTSTREAMTEE_IID)

  /* attribute nsIInputStream source; */
  NS_SCRIPTABLE NS_IMETHOD GetSource(nsIInputStream * *aSource) = 0;
  NS_SCRIPTABLE NS_IMETHOD SetSource(nsIInputStream * aSource) = 0;

  /* attribute nsIOutputStream sink; */
  NS_SCRIPTABLE NS_IMETHOD GetSink(nsIOutputStream * *aSink) = 0;
  NS_SCRIPTABLE NS_IMETHOD SetSink(nsIOutputStream * aSink) = 0;

};

  NS_DEFINE_STATIC_IID_ACCESSOR(nsIInputStreamTee, NS_IINPUTSTREAMTEE_IID)

/* Use this macro when declaring classes that implement this interface. */
#define NS_DECL_NSIINPUTSTREAMTEE \
  NS_SCRIPTABLE NS_IMETHOD GetSource(nsIInputStream * *aSource); \
  NS_SCRIPTABLE NS_IMETHOD SetSource(nsIInputStream * aSource); \
  NS_SCRIPTABLE NS_IMETHOD GetSink(nsIOutputStream * *aSink); \
  NS_SCRIPTABLE NS_IMETHOD SetSink(nsIOutputStream * aSink); 

/* Use this macro to declare functions that forward the behavior of this interface to another object. */
#define NS_FORWARD_NSIINPUTSTREAMTEE(_to) \
  NS_SCRIPTABLE NS_IMETHOD GetSource(nsIInputStream * *aSource) { return _to GetSource(aSource); } \
  NS_SCRIPTABLE NS_IMETHOD SetSource(nsIInputStream * aSource) { return _to SetSource(aSource); } \
  NS_SCRIPTABLE NS_IMETHOD GetSink(nsIOutputStream * *aSink) { return _to GetSink(aSink); } \
  NS_SCRIPTABLE NS_IMETHOD SetSink(nsIOutputStream * aSink) { return _to SetSink(aSink); } 

/* Use this macro to declare functions that forward the behavior of this interface to another object in a safe way. */
#define NS_FORWARD_SAFE_NSIINPUTSTREAMTEE(_to) \
  NS_SCRIPTABLE NS_IMETHOD GetSource(nsIInputStream * *aSource) { return !_to ? NS_ERROR_NULL_POINTER : _to->GetSource(aSource); } \
  NS_SCRIPTABLE NS_IMETHOD SetSource(nsIInputStream * aSource) { return !_to ? NS_ERROR_NULL_POINTER : _to->SetSource(aSource); } \
  NS_SCRIPTABLE NS_IMETHOD GetSink(nsIOutputStream * *aSink) { return !_to ? NS_ERROR_NULL_POINTER : _to->GetSink(aSink); } \
  NS_SCRIPTABLE NS_IMETHOD SetSink(nsIOutputStream * aSink) { return !_to ? NS_ERROR_NULL_POINTER : _to->SetSink(aSink); } 

#if 0
/* Use the code below as a template for the implementation class for this interface. */

/* Header file */
class nsInputStreamTee : public nsIInputStreamTee
{
public:
  NS_DECL_ISUPPORTS
  NS_DECL_NSIINPUTSTREAMTEE

  nsInputStreamTee();

private:
  ~nsInputStreamTee();

protected:
  /* additional members */
};

/* Implementation file */
NS_IMPL_ISUPPORTS1(nsInputStreamTee, nsIInputStreamTee)

nsInputStreamTee::nsInputStreamTee()
{
  /* member initializers and constructor code */
}

nsInputStreamTee::~nsInputStreamTee()
{
  /* destructor code */
}

/* attribute nsIInputStream source; */
NS_IMETHODIMP nsInputStreamTee::GetSource(nsIInputStream * *aSource)
{
    return NS_ERROR_NOT_IMPLEMENTED;
}
NS_IMETHODIMP nsInputStreamTee::SetSource(nsIInputStream * aSource)
{
    return NS_ERROR_NOT_IMPLEMENTED;
}

/* attribute nsIOutputStream sink; */
NS_IMETHODIMP nsInputStreamTee::GetSink(nsIOutputStream * *aSink)
{
    return NS_ERROR_NOT_IMPLEMENTED;
}
NS_IMETHODIMP nsInputStreamTee::SetSink(nsIOutputStream * aSink)
{
    return NS_ERROR_NOT_IMPLEMENTED;
}

/* End of implementation class template. */
#endif

// factory method
extern NS_COM nsresult
NS_NewInputStreamTee(nsIInputStream **tee, // read from this input stream
                     nsIInputStream *source,
                     nsIOutputStream *sink);

#endif /* __gen_nsIInputStreamTee_h__ */
