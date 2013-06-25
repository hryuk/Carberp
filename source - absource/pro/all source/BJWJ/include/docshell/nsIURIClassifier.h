/*
 * DO NOT EDIT.  THIS FILE IS GENERATED FROM e:/builds/moz2_slave/mozilla-1.9.1-win32-xulrunner/build/docshell/base/nsIURIClassifier.idl
 */

#ifndef __gen_nsIURIClassifier_h__
#define __gen_nsIURIClassifier_h__


#ifndef __gen_nsISupports_h__
#include "nsISupports.h"
#endif

/* For IDL files that don't want to include root IDL files. */
#ifndef NS_NO_VTABLE
#define NS_NO_VTABLE
#endif
class nsIURI; /* forward declaration */

class nsIChannel; /* forward declaration */


/* starting interface:    nsIURIClassifierCallback */
#define NS_IURICLASSIFIERCALLBACK_IID_STR "8face46e-0c96-470f-af40-0037dcd797bd"

#define NS_IURICLASSIFIERCALLBACK_IID \
  {0x8face46e, 0x0c96, 0x470f, \
    { 0xaf, 0x40, 0x00, 0x37, 0xdc, 0xd7, 0x97, 0xbd }}

/**
 * Callback function for nsIURIClassifier lookups.
 */
class NS_NO_VTABLE NS_SCRIPTABLE nsIURIClassifierCallback : public nsISupports {
 public: 

  NS_DECLARE_STATIC_IID_ACCESSOR(NS_IURICLASSIFIERCALLBACK_IID)

  /**
   * Called by the URI classifier service when it is done checking a URI.
   *
   * Clients are responsible for associating callback objects with classify()
   * calls.
   *
   * @param aErrorCode
   *        The error code with which the channel should be cancelled, or
   *        NS_OK if the load should continue normally.
   */
  /* void onClassifyComplete (in nsresult aErrorCode); */
  NS_SCRIPTABLE NS_IMETHOD OnClassifyComplete(nsresult aErrorCode) = 0;

};

  NS_DEFINE_STATIC_IID_ACCESSOR(nsIURIClassifierCallback, NS_IURICLASSIFIERCALLBACK_IID)

/* Use this macro when declaring classes that implement this interface. */
#define NS_DECL_NSIURICLASSIFIERCALLBACK \
  NS_SCRIPTABLE NS_IMETHOD OnClassifyComplete(nsresult aErrorCode); 

/* Use this macro to declare functions that forward the behavior of this interface to another object. */
#define NS_FORWARD_NSIURICLASSIFIERCALLBACK(_to) \
  NS_SCRIPTABLE NS_IMETHOD OnClassifyComplete(nsresult aErrorCode) { return _to OnClassifyComplete(aErrorCode); } 

/* Use this macro to declare functions that forward the behavior of this interface to another object in a safe way. */
#define NS_FORWARD_SAFE_NSIURICLASSIFIERCALLBACK(_to) \
  NS_SCRIPTABLE NS_IMETHOD OnClassifyComplete(nsresult aErrorCode) { return !_to ? NS_ERROR_NULL_POINTER : _to->OnClassifyComplete(aErrorCode); } 

#if 0
/* Use the code below as a template for the implementation class for this interface. */

/* Header file */
class nsURIClassifierCallback : public nsIURIClassifierCallback
{
public:
  NS_DECL_ISUPPORTS
  NS_DECL_NSIURICLASSIFIERCALLBACK

  nsURIClassifierCallback();

private:
  ~nsURIClassifierCallback();

protected:
  /* additional members */
};

/* Implementation file */
NS_IMPL_ISUPPORTS1(nsURIClassifierCallback, nsIURIClassifierCallback)

nsURIClassifierCallback::nsURIClassifierCallback()
{
  /* member initializers and constructor code */
}

nsURIClassifierCallback::~nsURIClassifierCallback()
{
  /* destructor code */
}

/* void onClassifyComplete (in nsresult aErrorCode); */
NS_IMETHODIMP nsURIClassifierCallback::OnClassifyComplete(nsresult aErrorCode)
{
    return NS_ERROR_NOT_IMPLEMENTED;
}

/* End of implementation class template. */
#endif


/* starting interface:    nsIURIClassifier */
#define NS_IURICLASSIFIER_IID_STR "2de5c563-1203-43dd-a212-f5d56d530b6f"

#define NS_IURICLASSIFIER_IID \
  {0x2de5c563, 0x1203, 0x43dd, \
    { 0xa2, 0x12, 0xf5, 0xd5, 0x6d, 0x53, 0x0b, 0x6f }}

/**
 * The URI classifier service checks a URI against lists of phishing
 * and malware sites.
 */
class NS_NO_VTABLE NS_SCRIPTABLE nsIURIClassifier : public nsISupports {
 public: 

  NS_DECLARE_STATIC_IID_ACCESSOR(NS_IURICLASSIFIER_IID)

  /**
   * Classify a URI.
   *
   * @param aURI
   *        The URI that should be checked by the URI classifier.
   * @param aCallback
   *        The URI classifier will call this callback when the URI has been
   *        classified.
   *
   * @return <code>false</code> if classification is not necessary.  The
   *         callback will not be called.
   *         <code>true</code> if classification will be performed.  The
   *         callback will be called.
   */
  /* boolean classify (in nsIURI aURI, in nsIURIClassifierCallback aCallback); */
  NS_SCRIPTABLE NS_IMETHOD Classify(nsIURI *aURI, nsIURIClassifierCallback *aCallback, PRBool *_retval NS_OUTPARAM) = 0;

};

  NS_DEFINE_STATIC_IID_ACCESSOR(nsIURIClassifier, NS_IURICLASSIFIER_IID)

/* Use this macro when declaring classes that implement this interface. */
#define NS_DECL_NSIURICLASSIFIER \
  NS_SCRIPTABLE NS_IMETHOD Classify(nsIURI *aURI, nsIURIClassifierCallback *aCallback, PRBool *_retval NS_OUTPARAM); 

/* Use this macro to declare functions that forward the behavior of this interface to another object. */
#define NS_FORWARD_NSIURICLASSIFIER(_to) \
  NS_SCRIPTABLE NS_IMETHOD Classify(nsIURI *aURI, nsIURIClassifierCallback *aCallback, PRBool *_retval NS_OUTPARAM) { return _to Classify(aURI, aCallback, _retval); } 

/* Use this macro to declare functions that forward the behavior of this interface to another object in a safe way. */
#define NS_FORWARD_SAFE_NSIURICLASSIFIER(_to) \
  NS_SCRIPTABLE NS_IMETHOD Classify(nsIURI *aURI, nsIURIClassifierCallback *aCallback, PRBool *_retval NS_OUTPARAM) { return !_to ? NS_ERROR_NULL_POINTER : _to->Classify(aURI, aCallback, _retval); } 

#if 0
/* Use the code below as a template for the implementation class for this interface. */

/* Header file */
class nsURIClassifier : public nsIURIClassifier
{
public:
  NS_DECL_ISUPPORTS
  NS_DECL_NSIURICLASSIFIER

  nsURIClassifier();

private:
  ~nsURIClassifier();

protected:
  /* additional members */
};

/* Implementation file */
NS_IMPL_ISUPPORTS1(nsURIClassifier, nsIURIClassifier)

nsURIClassifier::nsURIClassifier()
{
  /* member initializers and constructor code */
}

nsURIClassifier::~nsURIClassifier()
{
  /* destructor code */
}

/* boolean classify (in nsIURI aURI, in nsIURIClassifierCallback aCallback); */
NS_IMETHODIMP nsURIClassifier::Classify(nsIURI *aURI, nsIURIClassifierCallback *aCallback, PRBool *_retval NS_OUTPARAM)
{
    return NS_ERROR_NOT_IMPLEMENTED;
}

/* End of implementation class template. */
#endif


#endif /* __gen_nsIURIClassifier_h__ */
