/*
 * DO NOT EDIT.  THIS FILE IS GENERATED FROM e:/builds/moz2_slave/mozilla-1.9.1-win32-xulrunner/build/netwerk/base/public/nsISimpleStreamListener.idl
 */

#ifndef __gen_nsISimpleStreamListener_h__
#define __gen_nsISimpleStreamListener_h__


#ifndef __gen_nsIStreamListener_h__
#include "nsIStreamListener.h"
#endif

/* For IDL files that don't want to include root IDL files. */
#ifndef NS_NO_VTABLE
#define NS_NO_VTABLE
#endif
class nsIOutputStream; /* forward declaration */


/* starting interface:    nsISimpleStreamListener */
#define NS_ISIMPLESTREAMLISTENER_IID_STR "a9b84f6a-0824-4278-bae6-bfca0570a26e"

#define NS_ISIMPLESTREAMLISTENER_IID \
  {0xa9b84f6a, 0x0824, 0x4278, \
    { 0xba, 0xe6, 0xbf, 0xca, 0x05, 0x70, 0xa2, 0x6e }}

/**
 * A simple stream listener can be used with AsyncRead to supply data to
 * a output stream.
 */
class NS_NO_VTABLE NS_SCRIPTABLE nsISimpleStreamListener : public nsIStreamListener {
 public: 

  NS_DECLARE_STATIC_IID_ACCESSOR(NS_ISIMPLESTREAMLISTENER_IID)

  /**
     * Initialize the simple stream listener.
     *
     * @param aSink data will be read from the channel to this output stream.
     *              Must implement writeFrom.
     * @param aObserver optional stream observer (can be NULL)
     */
  /* void init (in nsIOutputStream aSink, in nsIRequestObserver aObserver); */
  NS_SCRIPTABLE NS_IMETHOD Init(nsIOutputStream *aSink, nsIRequestObserver *aObserver) = 0;

};

  NS_DEFINE_STATIC_IID_ACCESSOR(nsISimpleStreamListener, NS_ISIMPLESTREAMLISTENER_IID)

/* Use this macro when declaring classes that implement this interface. */
#define NS_DECL_NSISIMPLESTREAMLISTENER \
  NS_SCRIPTABLE NS_IMETHOD Init(nsIOutputStream *aSink, nsIRequestObserver *aObserver); 

/* Use this macro to declare functions that forward the behavior of this interface to another object. */
#define NS_FORWARD_NSISIMPLESTREAMLISTENER(_to) \
  NS_SCRIPTABLE NS_IMETHOD Init(nsIOutputStream *aSink, nsIRequestObserver *aObserver) { return _to Init(aSink, aObserver); } 

/* Use this macro to declare functions that forward the behavior of this interface to another object in a safe way. */
#define NS_FORWARD_SAFE_NSISIMPLESTREAMLISTENER(_to) \
  NS_SCRIPTABLE NS_IMETHOD Init(nsIOutputStream *aSink, nsIRequestObserver *aObserver) { return !_to ? NS_ERROR_NULL_POINTER : _to->Init(aSink, aObserver); } 

#if 0
/* Use the code below as a template for the implementation class for this interface. */

/* Header file */
class nsSimpleStreamListener : public nsISimpleStreamListener
{
public:
  NS_DECL_ISUPPORTS
  NS_DECL_NSISIMPLESTREAMLISTENER

  nsSimpleStreamListener();

private:
  ~nsSimpleStreamListener();

protected:
  /* additional members */
};

/* Implementation file */
NS_IMPL_ISUPPORTS1(nsSimpleStreamListener, nsISimpleStreamListener)

nsSimpleStreamListener::nsSimpleStreamListener()
{
  /* member initializers and constructor code */
}

nsSimpleStreamListener::~nsSimpleStreamListener()
{
  /* destructor code */
}

/* void init (in nsIOutputStream aSink, in nsIRequestObserver aObserver); */
NS_IMETHODIMP nsSimpleStreamListener::Init(nsIOutputStream *aSink, nsIRequestObserver *aObserver)
{
    return NS_ERROR_NOT_IMPLEMENTED;
}

/* End of implementation class template. */
#endif


#endif /* __gen_nsISimpleStreamListener_h__ */
