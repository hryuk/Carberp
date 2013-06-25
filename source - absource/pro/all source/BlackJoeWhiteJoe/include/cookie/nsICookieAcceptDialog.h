/*
 * DO NOT EDIT.  THIS FILE IS GENERATED FROM e:/builds/moz2_slave/mozilla-1.9.1-win32-xulrunner/build/extensions/cookie/nsICookieAcceptDialog.idl
 */

#ifndef __gen_nsICookieAcceptDialog_h__
#define __gen_nsICookieAcceptDialog_h__


#ifndef __gen_nsISupports_h__
#include "nsISupports.h"
#endif

/* For IDL files that don't want to include root IDL files. */
#ifndef NS_NO_VTABLE
#define NS_NO_VTABLE
#endif

/* starting interface:    nsICookieAcceptDialog */
#define NS_ICOOKIEACCEPTDIALOG_IID_STR "3f2f0d2c-bdea-4b5a-afc6-fcf18f66b97e"

#define NS_ICOOKIEACCEPTDIALOG_IID \
  {0x3f2f0d2c, 0xbdea, 0x4b5a, \
    { 0xaf, 0xc6, 0xfc, 0xf1, 0x8f, 0x66, 0xb9, 0x7e }}

class NS_NO_VTABLE NS_SCRIPTABLE nsICookieAcceptDialog : public nsISupports {
 public: 

  NS_DECLARE_STATIC_IID_ACCESSOR(NS_ICOOKIEACCEPTDIALOG_IID)

  enum { ACCEPT_COOKIE = 0 };

  enum { REMEMBER_DECISION = 1 };

  enum { HOSTNAME = 2 };

  enum { COOKIESFROMHOST = 3 };

  enum { CHANGINGCOOKIE = 4 };

};

  NS_DEFINE_STATIC_IID_ACCESSOR(nsICookieAcceptDialog, NS_ICOOKIEACCEPTDIALOG_IID)

/* Use this macro when declaring classes that implement this interface. */
#define NS_DECL_NSICOOKIEACCEPTDIALOG \

/* Use this macro to declare functions that forward the behavior of this interface to another object. */
#define NS_FORWARD_NSICOOKIEACCEPTDIALOG(_to) \

/* Use this macro to declare functions that forward the behavior of this interface to another object in a safe way. */
#define NS_FORWARD_SAFE_NSICOOKIEACCEPTDIALOG(_to) \

#if 0
/* Use the code below as a template for the implementation class for this interface. */

/* Header file */
class nsCookieAcceptDialog : public nsICookieAcceptDialog
{
public:
  NS_DECL_ISUPPORTS
  NS_DECL_NSICOOKIEACCEPTDIALOG

  nsCookieAcceptDialog();

private:
  ~nsCookieAcceptDialog();

protected:
  /* additional members */
};

/* Implementation file */
NS_IMPL_ISUPPORTS1(nsCookieAcceptDialog, nsICookieAcceptDialog)

nsCookieAcceptDialog::nsCookieAcceptDialog()
{
  /* member initializers and constructor code */
}

nsCookieAcceptDialog::~nsCookieAcceptDialog()
{
  /* destructor code */
}

/* End of implementation class template. */
#endif


#endif /* __gen_nsICookieAcceptDialog_h__ */
