/*
 * DO NOT EDIT.  THIS FILE IS GENERATED FROM e:/builds/moz2_slave/mozilla-1.9.1-win32-xulrunner/build/widget/public/nsIBidiKeyboard.idl
 */

#ifndef __gen_nsIBidiKeyboard_h__
#define __gen_nsIBidiKeyboard_h__


#ifndef __gen_nsISupports_h__
#include "nsISupports.h"
#endif

/* For IDL files that don't want to include root IDL files. */
#ifndef NS_NO_VTABLE
#define NS_NO_VTABLE
#endif

/* starting interface:    nsIBidiKeyboard */
#define NS_IBIDIKEYBOARD_IID_STR "0d8f8f10-c92d-4a6a-b2bb-e1921f3f4dda"

#define NS_IBIDIKEYBOARD_IID \
  {0x0d8f8f10, 0xc92d, 0x4a6a, \
    { 0xb2, 0xbb, 0xe1, 0x92, 0x1f, 0x3f, 0x4d, 0xda }}

class NS_NO_VTABLE NS_SCRIPTABLE nsIBidiKeyboard : public nsISupports {
 public: 

  NS_DECLARE_STATIC_IID_ACCESSOR(NS_IBIDIKEYBOARD_IID)

  /**
   * Determines if the current keyboard language is right-to-left
   * @throws NS_ERROR_FAILURE if no right-to-left keyboards are installed
   */
  /* boolean isLangRTL (); */
  NS_SCRIPTABLE NS_IMETHOD IsLangRTL(PRBool *_retval NS_OUTPARAM) = 0;

  /**
   * Sets the keyboard language to left-to-right or right-to-left
   * @param aLevel - if odd set the keyboard to RTL, if even set LTR 
   * @throws NS_ERROR_FAILURE if no right-to-left keyboards are installed
   */
  /* void setLangFromBidiLevel (in PRUint8 aLevel); */
  NS_SCRIPTABLE NS_IMETHOD SetLangFromBidiLevel(PRUint8 aLevel) = 0;

};

  NS_DEFINE_STATIC_IID_ACCESSOR(nsIBidiKeyboard, NS_IBIDIKEYBOARD_IID)

/* Use this macro when declaring classes that implement this interface. */
#define NS_DECL_NSIBIDIKEYBOARD \
  NS_SCRIPTABLE NS_IMETHOD IsLangRTL(PRBool *_retval NS_OUTPARAM); \
  NS_SCRIPTABLE NS_IMETHOD SetLangFromBidiLevel(PRUint8 aLevel); 

/* Use this macro to declare functions that forward the behavior of this interface to another object. */
#define NS_FORWARD_NSIBIDIKEYBOARD(_to) \
  NS_SCRIPTABLE NS_IMETHOD IsLangRTL(PRBool *_retval NS_OUTPARAM) { return _to IsLangRTL(_retval); } \
  NS_SCRIPTABLE NS_IMETHOD SetLangFromBidiLevel(PRUint8 aLevel) { return _to SetLangFromBidiLevel(aLevel); } 

/* Use this macro to declare functions that forward the behavior of this interface to another object in a safe way. */
#define NS_FORWARD_SAFE_NSIBIDIKEYBOARD(_to) \
  NS_SCRIPTABLE NS_IMETHOD IsLangRTL(PRBool *_retval NS_OUTPARAM) { return !_to ? NS_ERROR_NULL_POINTER : _to->IsLangRTL(_retval); } \
  NS_SCRIPTABLE NS_IMETHOD SetLangFromBidiLevel(PRUint8 aLevel) { return !_to ? NS_ERROR_NULL_POINTER : _to->SetLangFromBidiLevel(aLevel); } 

#if 0
/* Use the code below as a template for the implementation class for this interface. */

/* Header file */
class nsBidiKeyboard : public nsIBidiKeyboard
{
public:
  NS_DECL_ISUPPORTS
  NS_DECL_NSIBIDIKEYBOARD

  nsBidiKeyboard();

private:
  ~nsBidiKeyboard();

protected:
  /* additional members */
};

/* Implementation file */
NS_IMPL_ISUPPORTS1(nsBidiKeyboard, nsIBidiKeyboard)

nsBidiKeyboard::nsBidiKeyboard()
{
  /* member initializers and constructor code */
}

nsBidiKeyboard::~nsBidiKeyboard()
{
  /* destructor code */
}

/* boolean isLangRTL (); */
NS_IMETHODIMP nsBidiKeyboard::IsLangRTL(PRBool *_retval NS_OUTPARAM)
{
    return NS_ERROR_NOT_IMPLEMENTED;
}

/* void setLangFromBidiLevel (in PRUint8 aLevel); */
NS_IMETHODIMP nsBidiKeyboard::SetLangFromBidiLevel(PRUint8 aLevel)
{
    return NS_ERROR_NOT_IMPLEMENTED;
}

/* End of implementation class template. */
#endif


#endif /* __gen_nsIBidiKeyboard_h__ */
