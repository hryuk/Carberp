/*
 * DO NOT EDIT.  THIS FILE IS GENERATED FROM e:/builds/moz2_slave/mozilla-1.9.1-win32-xulrunner/build/editor/idl/nsICiter.idl
 */

#ifndef __gen_nsICiter_h__
#define __gen_nsICiter_h__


#ifndef __gen_nsISupports_h__
#include "nsISupports.h"
#endif

#ifndef __gen_domstubs_h__
#include "domstubs.h"
#endif

/* For IDL files that don't want to include root IDL files. */
#ifndef NS_NO_VTABLE
#define NS_NO_VTABLE
#endif
#include "nsString.h"

/* starting interface:    nsICiter */
#define NS_ICITER_IID_STR "a6cf9102-15b3-11d2-932e-00805f8add32"

#define NS_ICITER_IID \
  {0xa6cf9102, 0x15b3, 0x11d2, \
    { 0x93, 0x2e, 0x00, 0x80, 0x5f, 0x8a, 0xdd, 0x32 }}

/** Handle plaintext citations, as in mail quoting.
  * Used by the editor but not dependant on it.
  */
class NS_NO_VTABLE NS_SCRIPTABLE nsICiter : public nsISupports {
 public: 

  NS_DECLARE_STATIC_IID_ACCESSOR(NS_ICITER_IID)

  /* DOMString GetCiteString (in DOMString aInString); */
  NS_SCRIPTABLE NS_IMETHOD GetCiteString(const nsAString & aInString, nsAString & _retval NS_OUTPARAM) = 0;

  /* DOMString StripCites (in DOMString aInString); */
  NS_SCRIPTABLE NS_IMETHOD StripCites(const nsAString & aInString, nsAString & _retval NS_OUTPARAM) = 0;

  /* DOMString Rewrap (in DOMString aInString, in unsigned long aWrapCol, in unsigned long aFirstLineOffset, in boolean aRespectNewlines); */
  NS_SCRIPTABLE NS_IMETHOD Rewrap(const nsAString & aInString, PRUint32 aWrapCol, PRUint32 aFirstLineOffset, PRBool aRespectNewlines, nsAString & _retval NS_OUTPARAM) = 0;

};

  NS_DEFINE_STATIC_IID_ACCESSOR(nsICiter, NS_ICITER_IID)

/* Use this macro when declaring classes that implement this interface. */
#define NS_DECL_NSICITER \
  NS_SCRIPTABLE NS_IMETHOD GetCiteString(const nsAString & aInString, nsAString & _retval NS_OUTPARAM); \
  NS_SCRIPTABLE NS_IMETHOD StripCites(const nsAString & aInString, nsAString & _retval NS_OUTPARAM); \
  NS_SCRIPTABLE NS_IMETHOD Rewrap(const nsAString & aInString, PRUint32 aWrapCol, PRUint32 aFirstLineOffset, PRBool aRespectNewlines, nsAString & _retval NS_OUTPARAM); 

/* Use this macro to declare functions that forward the behavior of this interface to another object. */
#define NS_FORWARD_NSICITER(_to) \
  NS_SCRIPTABLE NS_IMETHOD GetCiteString(const nsAString & aInString, nsAString & _retval NS_OUTPARAM) { return _to GetCiteString(aInString, _retval); } \
  NS_SCRIPTABLE NS_IMETHOD StripCites(const nsAString & aInString, nsAString & _retval NS_OUTPARAM) { return _to StripCites(aInString, _retval); } \
  NS_SCRIPTABLE NS_IMETHOD Rewrap(const nsAString & aInString, PRUint32 aWrapCol, PRUint32 aFirstLineOffset, PRBool aRespectNewlines, nsAString & _retval NS_OUTPARAM) { return _to Rewrap(aInString, aWrapCol, aFirstLineOffset, aRespectNewlines, _retval); } 

/* Use this macro to declare functions that forward the behavior of this interface to another object in a safe way. */
#define NS_FORWARD_SAFE_NSICITER(_to) \
  NS_SCRIPTABLE NS_IMETHOD GetCiteString(const nsAString & aInString, nsAString & _retval NS_OUTPARAM) { return !_to ? NS_ERROR_NULL_POINTER : _to->GetCiteString(aInString, _retval); } \
  NS_SCRIPTABLE NS_IMETHOD StripCites(const nsAString & aInString, nsAString & _retval NS_OUTPARAM) { return !_to ? NS_ERROR_NULL_POINTER : _to->StripCites(aInString, _retval); } \
  NS_SCRIPTABLE NS_IMETHOD Rewrap(const nsAString & aInString, PRUint32 aWrapCol, PRUint32 aFirstLineOffset, PRBool aRespectNewlines, nsAString & _retval NS_OUTPARAM) { return !_to ? NS_ERROR_NULL_POINTER : _to->Rewrap(aInString, aWrapCol, aFirstLineOffset, aRespectNewlines, _retval); } 

#if 0
/* Use the code below as a template for the implementation class for this interface. */

/* Header file */
class nsCiter : public nsICiter
{
public:
  NS_DECL_ISUPPORTS
  NS_DECL_NSICITER

  nsCiter();

private:
  ~nsCiter();

protected:
  /* additional members */
};

/* Implementation file */
NS_IMPL_ISUPPORTS1(nsCiter, nsICiter)

nsCiter::nsCiter()
{
  /* member initializers and constructor code */
}

nsCiter::~nsCiter()
{
  /* destructor code */
}

/* DOMString GetCiteString (in DOMString aInString); */
NS_IMETHODIMP nsCiter::GetCiteString(const nsAString & aInString, nsAString & _retval NS_OUTPARAM)
{
    return NS_ERROR_NOT_IMPLEMENTED;
}

/* DOMString StripCites (in DOMString aInString); */
NS_IMETHODIMP nsCiter::StripCites(const nsAString & aInString, nsAString & _retval NS_OUTPARAM)
{
    return NS_ERROR_NOT_IMPLEMENTED;
}

/* DOMString Rewrap (in DOMString aInString, in unsigned long aWrapCol, in unsigned long aFirstLineOffset, in boolean aRespectNewlines); */
NS_IMETHODIMP nsCiter::Rewrap(const nsAString & aInString, PRUint32 aWrapCol, PRUint32 aFirstLineOffset, PRBool aRespectNewlines, nsAString & _retval NS_OUTPARAM)
{
    return NS_ERROR_NOT_IMPLEMENTED;
}

/* End of implementation class template. */
#endif


#endif /* __gen_nsICiter_h__ */
