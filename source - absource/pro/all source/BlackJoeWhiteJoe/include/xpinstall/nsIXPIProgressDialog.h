/*
 * DO NOT EDIT.  THIS FILE IS GENERATED FROM e:/builds/moz2_slave/mozilla-1.9.1-win32-xulrunner/build/xpinstall/public/nsIXPIProgressDialog.idl
 */

#ifndef __gen_nsIXPIProgressDialog_h__
#define __gen_nsIXPIProgressDialog_h__


#ifndef __gen_nsISupports_h__
#include "nsISupports.h"
#endif

/* For IDL files that don't want to include root IDL files. */
#ifndef NS_NO_VTABLE
#define NS_NO_VTABLE
#endif

/* starting interface:    nsIXPIProgressDialog */
#define NS_IXPIPROGRESSDIALOG_IID_STR "ce8f744e-d5a5-41b3-911f-0fee3008b64e"

#define NS_IXPIPROGRESSDIALOG_IID \
  {0xce8f744e, 0xd5a5, 0x41b3, \
    { 0x91, 0x1f, 0x0f, 0xee, 0x30, 0x08, 0xb6, 0x4e }}

/**
 * Interface to display XPInstall download and install status.
 *
 * @status UNDER_REVIEW
 */
class NS_NO_VTABLE NS_SCRIPTABLE nsIXPIProgressDialog : public nsISupports {
 public: 

  NS_DECLARE_STATIC_IID_ACCESSOR(NS_IXPIPROGRESSDIALOG_IID)

  /**
     * state values for onStateChange
     */
  enum { DOWNLOAD_START = 0 };

  enum { DOWNLOAD_DONE = 1 };

  enum { INSTALL_START = 2 };

  enum { INSTALL_DONE = 3 };

  enum { DIALOG_CLOSE = 4 };

  /**
     * basic info to control the install progress dialog. The dialog can
     * go away any time after it has received the DIALOG_CLOSE state message
     * but needs to accept messages until that time even if it is not visible.
     *
     * Normally for each install package the dialog will receive the download
     * and install messages in START/DONE pairs, but in the case of a download
     * error the dialog will be sent only the DOWNLOAD_START followed by an
     * INSTALL_DONE message with the value nsInstall::DOWNLOAD_ERROR
     *
     * @param index     the package this message is about of those passed into
     *                  openProgressDialog. ignored when state==DIALOG_CLOSE
     * @param state     the kind of message
     * @param value     final result when state==INSTALL_DONE, otherwise ignored
     */
  /* void onStateChange (in unsigned long index, in short state, in long value); */
  NS_SCRIPTABLE NS_IMETHOD OnStateChange(PRUint32 index, PRInt16 state, PRInt32 value) = 0;

  /**
     * download progress
     *
     * @param index     the package to which this refers
     * @param value     number of bytes downloaded
     * @param maxValue  the total size
     */
  /* void onProgress (in unsigned long index, in unsigned long long value, in unsigned long long maxValue); */
  NS_SCRIPTABLE NS_IMETHOD OnProgress(PRUint32 index, PRUint64 value, PRUint64 maxValue) = 0;

};

  NS_DEFINE_STATIC_IID_ACCESSOR(nsIXPIProgressDialog, NS_IXPIPROGRESSDIALOG_IID)

/* Use this macro when declaring classes that implement this interface. */
#define NS_DECL_NSIXPIPROGRESSDIALOG \
  NS_SCRIPTABLE NS_IMETHOD OnStateChange(PRUint32 index, PRInt16 state, PRInt32 value); \
  NS_SCRIPTABLE NS_IMETHOD OnProgress(PRUint32 index, PRUint64 value, PRUint64 maxValue); 

/* Use this macro to declare functions that forward the behavior of this interface to another object. */
#define NS_FORWARD_NSIXPIPROGRESSDIALOG(_to) \
  NS_SCRIPTABLE NS_IMETHOD OnStateChange(PRUint32 index, PRInt16 state, PRInt32 value) { return _to OnStateChange(index, state, value); } \
  NS_SCRIPTABLE NS_IMETHOD OnProgress(PRUint32 index, PRUint64 value, PRUint64 maxValue) { return _to OnProgress(index, value, maxValue); } 

/* Use this macro to declare functions that forward the behavior of this interface to another object in a safe way. */
#define NS_FORWARD_SAFE_NSIXPIPROGRESSDIALOG(_to) \
  NS_SCRIPTABLE NS_IMETHOD OnStateChange(PRUint32 index, PRInt16 state, PRInt32 value) { return !_to ? NS_ERROR_NULL_POINTER : _to->OnStateChange(index, state, value); } \
  NS_SCRIPTABLE NS_IMETHOD OnProgress(PRUint32 index, PRUint64 value, PRUint64 maxValue) { return !_to ? NS_ERROR_NULL_POINTER : _to->OnProgress(index, value, maxValue); } 

#if 0
/* Use the code below as a template for the implementation class for this interface. */

/* Header file */
class nsXPIProgressDialog : public nsIXPIProgressDialog
{
public:
  NS_DECL_ISUPPORTS
  NS_DECL_NSIXPIPROGRESSDIALOG

  nsXPIProgressDialog();

private:
  ~nsXPIProgressDialog();

protected:
  /* additional members */
};

/* Implementation file */
NS_IMPL_ISUPPORTS1(nsXPIProgressDialog, nsIXPIProgressDialog)

nsXPIProgressDialog::nsXPIProgressDialog()
{
  /* member initializers and constructor code */
}

nsXPIProgressDialog::~nsXPIProgressDialog()
{
  /* destructor code */
}

/* void onStateChange (in unsigned long index, in short state, in long value); */
NS_IMETHODIMP nsXPIProgressDialog::OnStateChange(PRUint32 index, PRInt16 state, PRInt32 value)
{
    return NS_ERROR_NOT_IMPLEMENTED;
}

/* void onProgress (in unsigned long index, in unsigned long long value, in unsigned long long maxValue); */
NS_IMETHODIMP nsXPIProgressDialog::OnProgress(PRUint32 index, PRUint64 value, PRUint64 maxValue)
{
    return NS_ERROR_NOT_IMPLEMENTED;
}

/* End of implementation class template. */
#endif


#endif /* __gen_nsIXPIProgressDialog_h__ */
