/*
 * DO NOT EDIT.  THIS FILE IS GENERATED FROM e:/builds/moz2_slave/mozilla-1.9.1-win32-xulrunner/build/storage/public/mozIStorageProgressHandler.idl
 */

#ifndef __gen_mozIStorageProgressHandler_h__
#define __gen_mozIStorageProgressHandler_h__


#ifndef __gen_nsISupports_h__
#include "nsISupports.h"
#endif

/* For IDL files that don't want to include root IDL files. */
#ifndef NS_NO_VTABLE
#define NS_NO_VTABLE
#endif
class mozIStorageConnection; /* forward declaration */


/* starting interface:    mozIStorageProgressHandler */
#define MOZISTORAGEPROGRESSHANDLER_IID_STR "a3a6fcd4-bf89-4208-a837-bf2a73afd30c"

#define MOZISTORAGEPROGRESSHANDLER_IID \
  {0xa3a6fcd4, 0xbf89, 0x4208, \
    { 0xa8, 0x37, 0xbf, 0x2a, 0x73, 0xaf, 0xd3, 0x0c }}

/**
 * mozIProgressHandler is to be implemented by storage consumers that
 * wish to receive callbacks during the request execution.
 */
class NS_NO_VTABLE NS_SCRIPTABLE mozIStorageProgressHandler : public nsISupports {
 public: 

  NS_DECLARE_STATIC_IID_ACCESSOR(MOZISTORAGEPROGRESSHANDLER_IID)

  /**
   * onProgress is invoked periodically during long running calls.
   * 
   * @param aConnection    connection, for which progress handler is
   *                       invoked.
   *
   * @return true to abort request, false to continue work.
   */
  /* boolean onProgress (in mozIStorageConnection aConnection); */
  NS_SCRIPTABLE NS_IMETHOD OnProgress(mozIStorageConnection *aConnection, PRBool *_retval NS_OUTPARAM) = 0;

};

  NS_DEFINE_STATIC_IID_ACCESSOR(mozIStorageProgressHandler, MOZISTORAGEPROGRESSHANDLER_IID)

/* Use this macro when declaring classes that implement this interface. */
#define NS_DECL_MOZISTORAGEPROGRESSHANDLER \
  NS_SCRIPTABLE NS_IMETHOD OnProgress(mozIStorageConnection *aConnection, PRBool *_retval NS_OUTPARAM); 

/* Use this macro to declare functions that forward the behavior of this interface to another object. */
#define NS_FORWARD_MOZISTORAGEPROGRESSHANDLER(_to) \
  NS_SCRIPTABLE NS_IMETHOD OnProgress(mozIStorageConnection *aConnection, PRBool *_retval NS_OUTPARAM) { return _to OnProgress(aConnection, _retval); } 

/* Use this macro to declare functions that forward the behavior of this interface to another object in a safe way. */
#define NS_FORWARD_SAFE_MOZISTORAGEPROGRESSHANDLER(_to) \
  NS_SCRIPTABLE NS_IMETHOD OnProgress(mozIStorageConnection *aConnection, PRBool *_retval NS_OUTPARAM) { return !_to ? NS_ERROR_NULL_POINTER : _to->OnProgress(aConnection, _retval); } 

#if 0
/* Use the code below as a template for the implementation class for this interface. */

/* Header file */
class _MYCLASS_ : public mozIStorageProgressHandler
{
public:
  NS_DECL_ISUPPORTS
  NS_DECL_MOZISTORAGEPROGRESSHANDLER

  _MYCLASS_();

private:
  ~_MYCLASS_();

protected:
  /* additional members */
};

/* Implementation file */
NS_IMPL_ISUPPORTS1(_MYCLASS_, mozIStorageProgressHandler)

_MYCLASS_::_MYCLASS_()
{
  /* member initializers and constructor code */
}

_MYCLASS_::~_MYCLASS_()
{
  /* destructor code */
}

/* boolean onProgress (in mozIStorageConnection aConnection); */
NS_IMETHODIMP _MYCLASS_::OnProgress(mozIStorageConnection *aConnection, PRBool *_retval NS_OUTPARAM)
{
    return NS_ERROR_NOT_IMPLEMENTED;
}

/* End of implementation class template. */
#endif


#endif /* __gen_mozIStorageProgressHandler_h__ */
