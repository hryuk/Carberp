/*
 * DO NOT EDIT.  THIS FILE IS GENERATED FROM e:/builds/moz2_slave/mozilla-1.9.1-win32-xulrunner/build/embedding/browser/webBrowser/nsIEmbeddingSiteWindow2.idl
 */

#ifndef __gen_nsIEmbeddingSiteWindow2_h__
#define __gen_nsIEmbeddingSiteWindow2_h__


#ifndef __gen_nsIEmbeddingSiteWindow_h__
#include "nsIEmbeddingSiteWindow.h"
#endif

/* For IDL files that don't want to include root IDL files. */
#ifndef NS_NO_VTABLE
#define NS_NO_VTABLE
#endif

/* starting interface:    nsIEmbeddingSiteWindow2 */
#define NS_IEMBEDDINGSITEWINDOW2_IID_STR "e932bf55-0a64-4beb-923a-1f32d3661044"

#define NS_IEMBEDDINGSITEWINDOW2_IID \
  {0xe932bf55, 0x0a64, 0x4beb, \
    { 0x92, 0x3a, 0x1f, 0x32, 0xd3, 0x66, 0x10, 0x44 }}

/**
 * The nsIEmbeddingSiteWindow is implemented by the embedder to provide
 * Gecko with the means to call up to the host to perform basic windowing
 * operations such as resizing and showing.
 *
 * Changes from version 1 to version 2:
 * A new method: blur()
 */
class NS_NO_VTABLE NS_SCRIPTABLE nsIEmbeddingSiteWindow2 : public nsIEmbeddingSiteWindow {
 public: 

  NS_DECLARE_STATIC_IID_ACCESSOR(NS_IEMBEDDINGSITEWINDOW2_IID)

  /**
     * Blur the window. This should unfocus the window and send an onblur event.
     */
  /* void blur (); */
  NS_SCRIPTABLE NS_IMETHOD Blur(void) = 0;

};

  NS_DEFINE_STATIC_IID_ACCESSOR(nsIEmbeddingSiteWindow2, NS_IEMBEDDINGSITEWINDOW2_IID)

/* Use this macro when declaring classes that implement this interface. */
#define NS_DECL_NSIEMBEDDINGSITEWINDOW2 \
  NS_SCRIPTABLE NS_IMETHOD Blur(void); 

/* Use this macro to declare functions that forward the behavior of this interface to another object. */
#define NS_FORWARD_NSIEMBEDDINGSITEWINDOW2(_to) \
  NS_SCRIPTABLE NS_IMETHOD Blur(void) { return _to Blur(); } 

/* Use this macro to declare functions that forward the behavior of this interface to another object in a safe way. */
#define NS_FORWARD_SAFE_NSIEMBEDDINGSITEWINDOW2(_to) \
  NS_SCRIPTABLE NS_IMETHOD Blur(void) { return !_to ? NS_ERROR_NULL_POINTER : _to->Blur(); } 

#if 0
/* Use the code below as a template for the implementation class for this interface. */

/* Header file */
class nsEmbeddingSiteWindow2 : public nsIEmbeddingSiteWindow2
{
public:
  NS_DECL_ISUPPORTS
  NS_DECL_NSIEMBEDDINGSITEWINDOW2

  nsEmbeddingSiteWindow2();

private:
  ~nsEmbeddingSiteWindow2();

protected:
  /* additional members */
};

/* Implementation file */
NS_IMPL_ISUPPORTS1(nsEmbeddingSiteWindow2, nsIEmbeddingSiteWindow2)

nsEmbeddingSiteWindow2::nsEmbeddingSiteWindow2()
{
  /* member initializers and constructor code */
}

nsEmbeddingSiteWindow2::~nsEmbeddingSiteWindow2()
{
  /* destructor code */
}

/* void blur (); */
NS_IMETHODIMP nsEmbeddingSiteWindow2::Blur()
{
    return NS_ERROR_NOT_IMPLEMENTED;
}

/* End of implementation class template. */
#endif


#endif /* __gen_nsIEmbeddingSiteWindow2_h__ */
