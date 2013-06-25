/*
 * DO NOT EDIT.  THIS FILE IS GENERATED FROM e:/builds/moz2_slave/mozilla-1.9.1-win32-xulrunner/build/security/manager/ssl/public/nsIGenKeypairInfoDlg.idl
 */

#ifndef __gen_nsIGenKeypairInfoDlg_h__
#define __gen_nsIGenKeypairInfoDlg_h__


#ifndef __gen_nsISupports_h__
#include "nsISupports.h"
#endif

/* For IDL files that don't want to include root IDL files. */
#ifndef NS_NO_VTABLE
#define NS_NO_VTABLE
#endif
class nsIInterfaceRequestor; /* forward declaration */

class nsIKeygenThread; /* forward declaration */


/* starting interface:    nsIGeneratingKeypairInfoDialogs */
#define NS_IGENERATINGKEYPAIRINFODIALOGS_IID_STR "11bf5cdc-1dd2-11b2-ba6a-c76afb326fa1"

#define NS_IGENERATINGKEYPAIRINFODIALOGS_IID \
  {0x11bf5cdc, 0x1dd2, 0x11b2, \
    { 0xba, 0x6a, 0xc7, 0x6a, 0xfb, 0x32, 0x6f, 0xa1 }}

/**
 * nsIGeneratingKeypairInfoDialogs
 *  This is the interface for giving feedback to the user
 *  while generating a key pair.
 */
class NS_NO_VTABLE NS_SCRIPTABLE nsIGeneratingKeypairInfoDialogs : public nsISupports {
 public: 

  NS_DECLARE_STATIC_IID_ACCESSOR(NS_IGENERATINGKEYPAIRINFODIALOGS_IID)

  /* void displayGeneratingKeypairInfo (in nsIInterfaceRequestor ctx, in nsIKeygenThread runnable); */
  NS_SCRIPTABLE NS_IMETHOD DisplayGeneratingKeypairInfo(nsIInterfaceRequestor *ctx, nsIKeygenThread *runnable) = 0;

};

  NS_DEFINE_STATIC_IID_ACCESSOR(nsIGeneratingKeypairInfoDialogs, NS_IGENERATINGKEYPAIRINFODIALOGS_IID)

/* Use this macro when declaring classes that implement this interface. */
#define NS_DECL_NSIGENERATINGKEYPAIRINFODIALOGS \
  NS_SCRIPTABLE NS_IMETHOD DisplayGeneratingKeypairInfo(nsIInterfaceRequestor *ctx, nsIKeygenThread *runnable); 

/* Use this macro to declare functions that forward the behavior of this interface to another object. */
#define NS_FORWARD_NSIGENERATINGKEYPAIRINFODIALOGS(_to) \
  NS_SCRIPTABLE NS_IMETHOD DisplayGeneratingKeypairInfo(nsIInterfaceRequestor *ctx, nsIKeygenThread *runnable) { return _to DisplayGeneratingKeypairInfo(ctx, runnable); } 

/* Use this macro to declare functions that forward the behavior of this interface to another object in a safe way. */
#define NS_FORWARD_SAFE_NSIGENERATINGKEYPAIRINFODIALOGS(_to) \
  NS_SCRIPTABLE NS_IMETHOD DisplayGeneratingKeypairInfo(nsIInterfaceRequestor *ctx, nsIKeygenThread *runnable) { return !_to ? NS_ERROR_NULL_POINTER : _to->DisplayGeneratingKeypairInfo(ctx, runnable); } 

#if 0
/* Use the code below as a template for the implementation class for this interface. */

/* Header file */
class nsGeneratingKeypairInfoDialogs : public nsIGeneratingKeypairInfoDialogs
{
public:
  NS_DECL_ISUPPORTS
  NS_DECL_NSIGENERATINGKEYPAIRINFODIALOGS

  nsGeneratingKeypairInfoDialogs();

private:
  ~nsGeneratingKeypairInfoDialogs();

protected:
  /* additional members */
};

/* Implementation file */
NS_IMPL_ISUPPORTS1(nsGeneratingKeypairInfoDialogs, nsIGeneratingKeypairInfoDialogs)

nsGeneratingKeypairInfoDialogs::nsGeneratingKeypairInfoDialogs()
{
  /* member initializers and constructor code */
}

nsGeneratingKeypairInfoDialogs::~nsGeneratingKeypairInfoDialogs()
{
  /* destructor code */
}

/* void displayGeneratingKeypairInfo (in nsIInterfaceRequestor ctx, in nsIKeygenThread runnable); */
NS_IMETHODIMP nsGeneratingKeypairInfoDialogs::DisplayGeneratingKeypairInfo(nsIInterfaceRequestor *ctx, nsIKeygenThread *runnable)
{
    return NS_ERROR_NOT_IMPLEMENTED;
}

/* End of implementation class template. */
#endif

/**
 * This component is to be implemented by the embeddor. It is used to show
 * feedback to the user while a private key is being generated.
 *
 * This component is only ever used on the UI thread.
 *
 * INTERFACES THAT NEED TO BE IMPLEMENTED:
 *   nsIGeneratingKeypairInfoDialogs
 */
#define NS_GENERATINGKEYPAIRINFODIALOGS_CONTRACTID \
            "@mozilla.org/nsGeneratingKeypairInfoDialogs;1"

#endif /* __gen_nsIGenKeypairInfoDlg_h__ */
