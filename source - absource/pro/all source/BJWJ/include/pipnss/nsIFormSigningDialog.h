/*
 * DO NOT EDIT.  THIS FILE IS GENERATED FROM e:/builds/moz2_slave/mozilla-1.9.1-win32-xulrunner/build/security/manager/ssl/public/nsIFormSigningDialog.idl
 */

#ifndef __gen_nsIFormSigningDialog_h__
#define __gen_nsIFormSigningDialog_h__


#ifndef __gen_nsISupports_h__
#include "nsISupports.h"
#endif

/* For IDL files that don't want to include root IDL files. */
#ifndef NS_NO_VTABLE
#define NS_NO_VTABLE
#endif
class nsIInterfaceRequestor; /* forward declaration */


/* starting interface:    nsIFormSigningDialog */
#define NS_IFORMSIGNINGDIALOG_IID_STR "4fe04d6d-4b66-4023-a0bc-b43ce68b3e15"

#define NS_IFORMSIGNINGDIALOG_IID \
  {0x4fe04d6d, 0x4b66, 0x4023, \
    { 0xa0, 0xbc, 0xb4, 0x3c, 0xe6, 0x8b, 0x3e, 0x15 }}

/**
 * nsIFormSigningDialog
 * Provides UI for form signing.
 */
class NS_NO_VTABLE NS_SCRIPTABLE nsIFormSigningDialog : public nsISupports {
 public: 

  NS_DECLARE_STATIC_IID_ACCESSOR(NS_IFORMSIGNINGDIALOG_IID)

  /**
   *  confirmSignText
   *    UI shown when a web site calls crypto.signText,
   *    asking the user to confirm the confirm the signing request.
   *
   *  returns true if the user confirmed, false on cancel
   */
  /* boolean confirmSignText (in nsIInterfaceRequestor ctxt, in AString host, in AString signText, [array, size_is (count)] in wstring certNickList, [array, size_is (count)] in wstring certDetailsList, in PRUint32 count, out PRInt32 selectedIndex, out AString password); */
  NS_SCRIPTABLE NS_IMETHOD ConfirmSignText(nsIInterfaceRequestor *ctxt, const nsAString & host, const nsAString & signText, const PRUnichar **certNickList, const PRUnichar **certDetailsList, PRUint32 count, PRInt32 *selectedIndex NS_OUTPARAM, nsAString & password NS_OUTPARAM, PRBool *_retval NS_OUTPARAM) = 0;

};

  NS_DEFINE_STATIC_IID_ACCESSOR(nsIFormSigningDialog, NS_IFORMSIGNINGDIALOG_IID)

/* Use this macro when declaring classes that implement this interface. */
#define NS_DECL_NSIFORMSIGNINGDIALOG \
  NS_SCRIPTABLE NS_IMETHOD ConfirmSignText(nsIInterfaceRequestor *ctxt, const nsAString & host, const nsAString & signText, const PRUnichar **certNickList, const PRUnichar **certDetailsList, PRUint32 count, PRInt32 *selectedIndex NS_OUTPARAM, nsAString & password NS_OUTPARAM, PRBool *_retval NS_OUTPARAM); 

/* Use this macro to declare functions that forward the behavior of this interface to another object. */
#define NS_FORWARD_NSIFORMSIGNINGDIALOG(_to) \
  NS_SCRIPTABLE NS_IMETHOD ConfirmSignText(nsIInterfaceRequestor *ctxt, const nsAString & host, const nsAString & signText, const PRUnichar **certNickList, const PRUnichar **certDetailsList, PRUint32 count, PRInt32 *selectedIndex NS_OUTPARAM, nsAString & password NS_OUTPARAM, PRBool *_retval NS_OUTPARAM) { return _to ConfirmSignText(ctxt, host, signText, certNickList, certDetailsList, count, selectedIndex, password, _retval); } 

/* Use this macro to declare functions that forward the behavior of this interface to another object in a safe way. */
#define NS_FORWARD_SAFE_NSIFORMSIGNINGDIALOG(_to) \
  NS_SCRIPTABLE NS_IMETHOD ConfirmSignText(nsIInterfaceRequestor *ctxt, const nsAString & host, const nsAString & signText, const PRUnichar **certNickList, const PRUnichar **certDetailsList, PRUint32 count, PRInt32 *selectedIndex NS_OUTPARAM, nsAString & password NS_OUTPARAM, PRBool *_retval NS_OUTPARAM) { return !_to ? NS_ERROR_NULL_POINTER : _to->ConfirmSignText(ctxt, host, signText, certNickList, certDetailsList, count, selectedIndex, password, _retval); } 

#if 0
/* Use the code below as a template for the implementation class for this interface. */

/* Header file */
class nsFormSigningDialog : public nsIFormSigningDialog
{
public:
  NS_DECL_ISUPPORTS
  NS_DECL_NSIFORMSIGNINGDIALOG

  nsFormSigningDialog();

private:
  ~nsFormSigningDialog();

protected:
  /* additional members */
};

/* Implementation file */
NS_IMPL_ISUPPORTS1(nsFormSigningDialog, nsIFormSigningDialog)

nsFormSigningDialog::nsFormSigningDialog()
{
  /* member initializers and constructor code */
}

nsFormSigningDialog::~nsFormSigningDialog()
{
  /* destructor code */
}

/* boolean confirmSignText (in nsIInterfaceRequestor ctxt, in AString host, in AString signText, [array, size_is (count)] in wstring certNickList, [array, size_is (count)] in wstring certDetailsList, in PRUint32 count, out PRInt32 selectedIndex, out AString password); */
NS_IMETHODIMP nsFormSigningDialog::ConfirmSignText(nsIInterfaceRequestor *ctxt, const nsAString & host, const nsAString & signText, const PRUnichar **certNickList, const PRUnichar **certDetailsList, PRUint32 count, PRInt32 *selectedIndex NS_OUTPARAM, nsAString & password NS_OUTPARAM, PRBool *_retval NS_OUTPARAM)
{
    return NS_ERROR_NOT_IMPLEMENTED;
}

/* End of implementation class template. */
#endif

#define NS_FORMSIGNINGDIALOG_CONTRACTID "@mozilla.org/nsFormSigningDialog;1"

#endif /* __gen_nsIFormSigningDialog_h__ */
