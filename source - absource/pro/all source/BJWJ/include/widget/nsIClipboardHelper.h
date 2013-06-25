/*
 * DO NOT EDIT.  THIS FILE IS GENERATED FROM e:/builds/moz2_slave/mozilla-1.9.1-win32-xulrunner/build/widget/public/nsIClipboardHelper.idl
 */

#ifndef __gen_nsIClipboardHelper_h__
#define __gen_nsIClipboardHelper_h__


#ifndef __gen_nsISupports_h__
#include "nsISupports.h"
#endif

#ifndef __gen_nsIClipboard_h__
#include "nsIClipboard.h"
#endif

/* For IDL files that don't want to include root IDL files. */
#ifndef NS_NO_VTABLE
#define NS_NO_VTABLE
#endif
#include "nsString.h" // needed for AString -> nsAString, unfortunately

/* starting interface:    nsIClipboardHelper */
#define NS_ICLIPBOARDHELPER_IID_STR "44073a98-1dd2-11b2-8600-d0ae854dbe93"

#define NS_ICLIPBOARDHELPER_IID \
  {0x44073a98, 0x1dd2, 0x11b2, \
    { 0x86, 0x00, 0xd0, 0xae, 0x85, 0x4d, 0xbe, 0x93 }}

/**
 * helper service for common uses of nsIClipboard.
 */
class NS_NO_VTABLE NS_SCRIPTABLE nsIClipboardHelper : public nsISupports {
 public: 

  NS_DECLARE_STATIC_IID_ACCESSOR(NS_ICLIPBOARDHELPER_IID)

  /**
   * copy string to given clipboard
   *
   * @param aString, the string to copy to the clipboard
   * @param aClipboardID, the ID of the clipboard to copy to
   *        (eg. kSelectionClipboard -- see nsIClipboard.idl)
   */
  /* void copyStringToClipboard (in AString aString, in long aClipboardID); */
  NS_SCRIPTABLE NS_IMETHOD CopyStringToClipboard(const nsAString & aString, PRInt32 aClipboardID) = 0;

  /**
   * copy string to (default) clipboard
   *
   * @param aString, the string to copy to the clipboard
   */
  /* void copyString (in AString aString); */
  NS_SCRIPTABLE NS_IMETHOD CopyString(const nsAString & aString) = 0;

};

  NS_DEFINE_STATIC_IID_ACCESSOR(nsIClipboardHelper, NS_ICLIPBOARDHELPER_IID)

/* Use this macro when declaring classes that implement this interface. */
#define NS_DECL_NSICLIPBOARDHELPER \
  NS_SCRIPTABLE NS_IMETHOD CopyStringToClipboard(const nsAString & aString, PRInt32 aClipboardID); \
  NS_SCRIPTABLE NS_IMETHOD CopyString(const nsAString & aString); 

/* Use this macro to declare functions that forward the behavior of this interface to another object. */
#define NS_FORWARD_NSICLIPBOARDHELPER(_to) \
  NS_SCRIPTABLE NS_IMETHOD CopyStringToClipboard(const nsAString & aString, PRInt32 aClipboardID) { return _to CopyStringToClipboard(aString, aClipboardID); } \
  NS_SCRIPTABLE NS_IMETHOD CopyString(const nsAString & aString) { return _to CopyString(aString); } 

/* Use this macro to declare functions that forward the behavior of this interface to another object in a safe way. */
#define NS_FORWARD_SAFE_NSICLIPBOARDHELPER(_to) \
  NS_SCRIPTABLE NS_IMETHOD CopyStringToClipboard(const nsAString & aString, PRInt32 aClipboardID) { return !_to ? NS_ERROR_NULL_POINTER : _to->CopyStringToClipboard(aString, aClipboardID); } \
  NS_SCRIPTABLE NS_IMETHOD CopyString(const nsAString & aString) { return !_to ? NS_ERROR_NULL_POINTER : _to->CopyString(aString); } 

#if 0
/* Use the code below as a template for the implementation class for this interface. */

/* Header file */
class nsClipboardHelper : public nsIClipboardHelper
{
public:
  NS_DECL_ISUPPORTS
  NS_DECL_NSICLIPBOARDHELPER

  nsClipboardHelper();

private:
  ~nsClipboardHelper();

protected:
  /* additional members */
};

/* Implementation file */
NS_IMPL_ISUPPORTS1(nsClipboardHelper, nsIClipboardHelper)

nsClipboardHelper::nsClipboardHelper()
{
  /* member initializers and constructor code */
}

nsClipboardHelper::~nsClipboardHelper()
{
  /* destructor code */
}

/* void copyStringToClipboard (in AString aString, in long aClipboardID); */
NS_IMETHODIMP nsClipboardHelper::CopyStringToClipboard(const nsAString & aString, PRInt32 aClipboardID)
{
    return NS_ERROR_NOT_IMPLEMENTED;
}

/* void copyString (in AString aString); */
NS_IMETHODIMP nsClipboardHelper::CopyString(const nsAString & aString)
{
    return NS_ERROR_NOT_IMPLEMENTED;
}

/* End of implementation class template. */
#endif


#endif /* __gen_nsIClipboardHelper_h__ */
