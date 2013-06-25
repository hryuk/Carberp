/*
 * DO NOT EDIT.  THIS FILE IS GENERATED FROM e:/builds/moz2_slave/mozilla-1.9.1-win32-xulrunner/build/security/manager/ssl/public/nsIUserCertPicker.idl
 */

#ifndef __gen_nsIUserCertPicker_h__
#define __gen_nsIUserCertPicker_h__


#ifndef __gen_nsISupports_h__
#include "nsISupports.h"
#endif

/* For IDL files that don't want to include root IDL files. */
#ifndef NS_NO_VTABLE
#define NS_NO_VTABLE
#endif
class nsIX509Cert; /* forward declaration */

class nsIInterfaceRequestor; /* forward declaration */


/* starting interface:    nsIUserCertPicker */
#define NS_IUSERCERTPICKER_IID_STR "06d018e0-d41b-4629-a4fc-daaa6029888e"

#define NS_IUSERCERTPICKER_IID \
  {0x06d018e0, 0xd41b, 0x4629, \
    { 0xa4, 0xfc, 0xda, 0xaa, 0x60, 0x29, 0x88, 0x8e }}

class NS_NO_VTABLE NS_SCRIPTABLE nsIUserCertPicker : public nsISupports {
 public: 

  NS_DECLARE_STATIC_IID_ACCESSOR(NS_IUSERCERTPICKER_IID)

  /* nsIX509Cert pickByUsage (in nsIInterfaceRequestor ctx, in wstring selectedNickname, in long certUsage, in boolean allowInvalid, in boolean allowDuplicateNicknames, out boolean canceled); */
  NS_SCRIPTABLE NS_IMETHOD PickByUsage(nsIInterfaceRequestor *ctx, const PRUnichar *selectedNickname, PRInt32 certUsage, PRBool allowInvalid, PRBool allowDuplicateNicknames, PRBool *canceled NS_OUTPARAM, nsIX509Cert **_retval NS_OUTPARAM) = 0;

};

  NS_DEFINE_STATIC_IID_ACCESSOR(nsIUserCertPicker, NS_IUSERCERTPICKER_IID)

/* Use this macro when declaring classes that implement this interface. */
#define NS_DECL_NSIUSERCERTPICKER \
  NS_SCRIPTABLE NS_IMETHOD PickByUsage(nsIInterfaceRequestor *ctx, const PRUnichar *selectedNickname, PRInt32 certUsage, PRBool allowInvalid, PRBool allowDuplicateNicknames, PRBool *canceled NS_OUTPARAM, nsIX509Cert **_retval NS_OUTPARAM); 

/* Use this macro to declare functions that forward the behavior of this interface to another object. */
#define NS_FORWARD_NSIUSERCERTPICKER(_to) \
  NS_SCRIPTABLE NS_IMETHOD PickByUsage(nsIInterfaceRequestor *ctx, const PRUnichar *selectedNickname, PRInt32 certUsage, PRBool allowInvalid, PRBool allowDuplicateNicknames, PRBool *canceled NS_OUTPARAM, nsIX509Cert **_retval NS_OUTPARAM) { return _to PickByUsage(ctx, selectedNickname, certUsage, allowInvalid, allowDuplicateNicknames, canceled, _retval); } 

/* Use this macro to declare functions that forward the behavior of this interface to another object in a safe way. */
#define NS_FORWARD_SAFE_NSIUSERCERTPICKER(_to) \
  NS_SCRIPTABLE NS_IMETHOD PickByUsage(nsIInterfaceRequestor *ctx, const PRUnichar *selectedNickname, PRInt32 certUsage, PRBool allowInvalid, PRBool allowDuplicateNicknames, PRBool *canceled NS_OUTPARAM, nsIX509Cert **_retval NS_OUTPARAM) { return !_to ? NS_ERROR_NULL_POINTER : _to->PickByUsage(ctx, selectedNickname, certUsage, allowInvalid, allowDuplicateNicknames, canceled, _retval); } 

#if 0
/* Use the code below as a template for the implementation class for this interface. */

/* Header file */
class nsUserCertPicker : public nsIUserCertPicker
{
public:
  NS_DECL_ISUPPORTS
  NS_DECL_NSIUSERCERTPICKER

  nsUserCertPicker();

private:
  ~nsUserCertPicker();

protected:
  /* additional members */
};

/* Implementation file */
NS_IMPL_ISUPPORTS1(nsUserCertPicker, nsIUserCertPicker)

nsUserCertPicker::nsUserCertPicker()
{
  /* member initializers and constructor code */
}

nsUserCertPicker::~nsUserCertPicker()
{
  /* destructor code */
}

/* nsIX509Cert pickByUsage (in nsIInterfaceRequestor ctx, in wstring selectedNickname, in long certUsage, in boolean allowInvalid, in boolean allowDuplicateNicknames, out boolean canceled); */
NS_IMETHODIMP nsUserCertPicker::PickByUsage(nsIInterfaceRequestor *ctx, const PRUnichar *selectedNickname, PRInt32 certUsage, PRBool allowInvalid, PRBool allowDuplicateNicknames, PRBool *canceled NS_OUTPARAM, nsIX509Cert **_retval NS_OUTPARAM)
{
    return NS_ERROR_NOT_IMPLEMENTED;
}

/* End of implementation class template. */
#endif

#define NS_CERT_PICKER_CONTRACTID "@mozilla.org/user_cert_picker;1"
#define NS_CERT_PICKER_CLASSNAME "Cert Picker Object"

#endif /* __gen_nsIUserCertPicker_h__ */
