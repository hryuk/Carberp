/*
 * DO NOT EDIT.  THIS FILE IS GENERATED FROM e:/builds/moz2_slave/mozilla-1.9.1-win32-xulrunner/build/embedding/components/windowwatcher/public/nsPIPromptService.idl
 */

#ifndef __gen_nsPIPromptService_h__
#define __gen_nsPIPromptService_h__


#ifndef __gen_nsISupports_h__
#include "nsISupports.h"
#endif

/* For IDL files that don't want to include root IDL files. */
#ifndef NS_NO_VTABLE
#define NS_NO_VTABLE
#endif
class nsIDOMWindow; /* forward declaration */

class nsIDialogParamBlock; /* forward declaration */


/* starting interface:    nsPIPromptService */
#define NS_PIPROMPTSERVICE_IID_STR "d16e906d-bab3-49e0-8688-7f49a6f4293a"

#define NS_PIPROMPTSERVICE_IID \
  {0xd16e906d, 0xbab3, 0x49e0, \
    { 0x86, 0x88, 0x7f, 0x49, 0xa6, 0xf4, 0x29, 0x3a }}

class nsPIPromptService : public nsISupports {
 public: 

  NS_DECLARE_STATIC_IID_ACCESSOR(NS_PIPROMPTSERVICE_IID)

  enum {eMsg=0, eCheckboxMsg=1, eIconClass=2, eTitleMessage=3, eEditfield1Msg=4,
        eEditfield2Msg=5, eEditfield1Value=6, eEditfield2Value=7,
        eButton0Text=8, eButton1Text=9, eButton2Text=10, eButton3Text=11,
        eDialogTitle=12, eOpeningSound=13};
  enum {eButtonPressed=0, eCheckboxState=1, eNumberButtons=2,
        eNumberEditfields=3, eEditField1Password=4, eDefaultButton=5,
        eDelayButtonEnable=6};
  /* void doDialog (in nsIDOMWindow aParent, in nsIDialogParamBlock aParamBlock, in string aChromeURL); */
  NS_IMETHOD DoDialog(nsIDOMWindow *aParent, nsIDialogParamBlock *aParamBlock, const char *aChromeURL) = 0;

};

  NS_DEFINE_STATIC_IID_ACCESSOR(nsPIPromptService, NS_PIPROMPTSERVICE_IID)

/* Use this macro when declaring classes that implement this interface. */
#define NS_DECL_NSPIPROMPTSERVICE \
  NS_IMETHOD DoDialog(nsIDOMWindow *aParent, nsIDialogParamBlock *aParamBlock, const char *aChromeURL); 

/* Use this macro to declare functions that forward the behavior of this interface to another object. */
#define NS_FORWARD_NSPIPROMPTSERVICE(_to) \
  NS_IMETHOD DoDialog(nsIDOMWindow *aParent, nsIDialogParamBlock *aParamBlock, const char *aChromeURL) { return _to DoDialog(aParent, aParamBlock, aChromeURL); } 

/* Use this macro to declare functions that forward the behavior of this interface to another object in a safe way. */
#define NS_FORWARD_SAFE_NSPIPROMPTSERVICE(_to) \
  NS_IMETHOD DoDialog(nsIDOMWindow *aParent, nsIDialogParamBlock *aParamBlock, const char *aChromeURL) { return !_to ? NS_ERROR_NULL_POINTER : _to->DoDialog(aParent, aParamBlock, aChromeURL); } 

#if 0
/* Use the code below as a template for the implementation class for this interface. */

/* Header file */
class _MYCLASS_ : public nsPIPromptService
{
public:
  NS_DECL_ISUPPORTS
  NS_DECL_NSPIPROMPTSERVICE

  _MYCLASS_();

private:
  ~_MYCLASS_();

protected:
  /* additional members */
};

/* Implementation file */
NS_IMPL_ISUPPORTS1(_MYCLASS_, nsPIPromptService)

_MYCLASS_::_MYCLASS_()
{
  /* member initializers and constructor code */
}

_MYCLASS_::~_MYCLASS_()
{
  /* destructor code */
}

/* void doDialog (in nsIDOMWindow aParent, in nsIDialogParamBlock aParamBlock, in string aChromeURL); */
NS_IMETHODIMP _MYCLASS_::DoDialog(nsIDOMWindow *aParent, nsIDialogParamBlock *aParamBlock, const char *aChromeURL)
{
    return NS_ERROR_NOT_IMPLEMENTED;
}

/* End of implementation class template. */
#endif


#endif /* __gen_nsPIPromptService_h__ */
