/*
 * DO NOT EDIT.  THIS FILE IS GENERATED FROM e:/builds/moz2_slave/mozilla-1.9.1-win32-xulrunner/build/js/src/xpconnect/idl/nsIDispatchSupport.idl
 */

#ifndef __gen_nsIDispatchSupport_h__
#define __gen_nsIDispatchSupport_h__


#ifndef __gen_nsISupports_h__
#include "nsISupports.h"
#endif

#ifndef __gen_nsIVariant_h__
#include "nsIVariant.h"
#endif

/* For IDL files that don't want to include root IDL files. */
#ifndef NS_NO_VTABLE
#define NS_NO_VTABLE
#endif
// Pull in jsval definition
#include "jspubtd.h"
// {40c4883d-079f-43db-82a9-df0a59d37998}
#define NS_IDISPATCH_SUPPORT_CID \
    { 0x40c4883d, 0x079f, 0x43db, \
      { 0x82, 0xa9, 0xdf, 0x0a, 0x59, 0xd3, 0x79, 0x98 } }
#ifdef XPC_IDISPATCH_SUPPORT
#define NS_IDISPATCH_SUPPORT_CONTRACTID "@mozilla.org/nsdispatchsupport;1"
// Disable the warning concerning IDispatch being a struct but now defined
// as a class
#pragma warning(push)
#pragma warning(disable : 4099)
#endif
class IDispatch; /* forward declaration */


/* starting interface:    nsIDispatchSupport */
#define NS_IDISPATCHSUPPORT_IID_STR "38df70e9-12f8-4732-af91-df36c38dc6f6"

#define NS_IDISPATCHSUPPORT_IID \
  {0x38df70e9, 0x12f8, 0x4732, \
    { 0xaf, 0x91, 0xdf, 0x36, 0xc3, 0x8d, 0xc6, 0xf6 }}

class NS_NO_VTABLE nsIDispatchSupport : public nsISupports {
 public: 

  NS_DECLARE_STATIC_IID_ACCESSOR(NS_IDISPATCHSUPPORT_IID)

  /**
     * Converts a COM Variant to a jsval.
     * @param comvar The COM Variant to be converted.
     * @param val The jsval to receive the converted value.
     */
  /* void COMVariant2JSVal (in COMVARIANTPtr comvar, out JSVal val); */
  NS_IMETHOD COMVariant2JSVal(VARIANT * comvar, jsval *val NS_OUTPARAM) = 0;

  /**
     * Converts a jsval to a COM Variant
     * @param var The jsval to be converted.
     * @param comvar The COM Variant to receive the converted value
     */
  /* void JSVal2COMVariant (in JSVal var, out COMVARIANT comvar); */
  NS_IMETHOD JSVal2COMVariant(jsval var, VARIANT *comvar NS_OUTPARAM) = 0;

  /**
     * Test if the class is safe to host.
     * @param clsid The nsID representation of the CLSID to test.
     * @param classExists Returns containing PR_FALSE if the class is
     *                    not registered.
     */
  /* boolean isClassSafeToHost (in JSContextPtr cx, in nsCIDRef cid, in boolean capsCheck, out boolean classExists); */
  NS_IMETHOD IsClassSafeToHost(JSContext * cx, const nsCID & cid, PRBool capsCheck, PRBool *classExists NS_OUTPARAM, PRBool *_retval NS_OUTPARAM) = 0;

  /**
     * Test if the specified class is marked safe for scripting.
     * @param cid The nsID representation of the CLSID to test.
     * @param classExists Returns containing PR_FALSE if the class is not
     *                    registered.
     */
  /* boolean isClassMarkedSafeForScripting (in nsCIDRef cid, out boolean classExists); */
  NS_IMETHOD IsClassMarkedSafeForScripting(const nsCID & cid, PRBool *classExists NS_OUTPARAM, PRBool *_retval NS_OUTPARAM) = 0;

  /**
     * Test if the instantiated object is safe for scripting on the specified
     * interface.
     * @param theObject The object to test (an IUnknown cast into a void *).
     * @param iid The interface to test if it is safe for scripting on.
     */
  /* boolean isObjectSafeForScripting (in voidPtr theObject, in nsIIDRef id); */
  NS_IMETHOD IsObjectSafeForScripting(void * theObject, const nsIID & id, PRBool *_retval NS_OUTPARAM) = 0;

  /**
     * Return the ActiveX security and hosting flags. See nsIActiveXSecurityPolicy
     * for list of flags.
     * @param context The context for which flags are requested. At present the
     *                only valid value is nsnull.
     */
  /* unsigned long getHostingFlags (in string aContext); */
  NS_IMETHOD GetHostingFlags(const char *aContext, PRUint32 *_retval NS_OUTPARAM) = 0;

};

  NS_DEFINE_STATIC_IID_ACCESSOR(nsIDispatchSupport, NS_IDISPATCHSUPPORT_IID)

/* Use this macro when declaring classes that implement this interface. */
#define NS_DECL_NSIDISPATCHSUPPORT \
  NS_IMETHOD COMVariant2JSVal(VARIANT * comvar, jsval *val NS_OUTPARAM); \
  NS_IMETHOD JSVal2COMVariant(jsval var, VARIANT *comvar NS_OUTPARAM); \
  NS_IMETHOD IsClassSafeToHost(JSContext * cx, const nsCID & cid, PRBool capsCheck, PRBool *classExists NS_OUTPARAM, PRBool *_retval NS_OUTPARAM); \
  NS_IMETHOD IsClassMarkedSafeForScripting(const nsCID & cid, PRBool *classExists NS_OUTPARAM, PRBool *_retval NS_OUTPARAM); \
  NS_IMETHOD IsObjectSafeForScripting(void * theObject, const nsIID & id, PRBool *_retval NS_OUTPARAM); \
  NS_IMETHOD GetHostingFlags(const char *aContext, PRUint32 *_retval NS_OUTPARAM); 

/* Use this macro to declare functions that forward the behavior of this interface to another object. */
#define NS_FORWARD_NSIDISPATCHSUPPORT(_to) \
  NS_IMETHOD COMVariant2JSVal(VARIANT * comvar, jsval *val NS_OUTPARAM) { return _to COMVariant2JSVal(comvar, val); } \
  NS_IMETHOD JSVal2COMVariant(jsval var, VARIANT *comvar NS_OUTPARAM) { return _to JSVal2COMVariant(var, comvar); } \
  NS_IMETHOD IsClassSafeToHost(JSContext * cx, const nsCID & cid, PRBool capsCheck, PRBool *classExists NS_OUTPARAM, PRBool *_retval NS_OUTPARAM) { return _to IsClassSafeToHost(cx, cid, capsCheck, classExists, _retval); } \
  NS_IMETHOD IsClassMarkedSafeForScripting(const nsCID & cid, PRBool *classExists NS_OUTPARAM, PRBool *_retval NS_OUTPARAM) { return _to IsClassMarkedSafeForScripting(cid, classExists, _retval); } \
  NS_IMETHOD IsObjectSafeForScripting(void * theObject, const nsIID & id, PRBool *_retval NS_OUTPARAM) { return _to IsObjectSafeForScripting(theObject, id, _retval); } \
  NS_IMETHOD GetHostingFlags(const char *aContext, PRUint32 *_retval NS_OUTPARAM) { return _to GetHostingFlags(aContext, _retval); } 

/* Use this macro to declare functions that forward the behavior of this interface to another object in a safe way. */
#define NS_FORWARD_SAFE_NSIDISPATCHSUPPORT(_to) \
  NS_IMETHOD COMVariant2JSVal(VARIANT * comvar, jsval *val NS_OUTPARAM) { return !_to ? NS_ERROR_NULL_POINTER : _to->COMVariant2JSVal(comvar, val); } \
  NS_IMETHOD JSVal2COMVariant(jsval var, VARIANT *comvar NS_OUTPARAM) { return !_to ? NS_ERROR_NULL_POINTER : _to->JSVal2COMVariant(var, comvar); } \
  NS_IMETHOD IsClassSafeToHost(JSContext * cx, const nsCID & cid, PRBool capsCheck, PRBool *classExists NS_OUTPARAM, PRBool *_retval NS_OUTPARAM) { return !_to ? NS_ERROR_NULL_POINTER : _to->IsClassSafeToHost(cx, cid, capsCheck, classExists, _retval); } \
  NS_IMETHOD IsClassMarkedSafeForScripting(const nsCID & cid, PRBool *classExists NS_OUTPARAM, PRBool *_retval NS_OUTPARAM) { return !_to ? NS_ERROR_NULL_POINTER : _to->IsClassMarkedSafeForScripting(cid, classExists, _retval); } \
  NS_IMETHOD IsObjectSafeForScripting(void * theObject, const nsIID & id, PRBool *_retval NS_OUTPARAM) { return !_to ? NS_ERROR_NULL_POINTER : _to->IsObjectSafeForScripting(theObject, id, _retval); } \
  NS_IMETHOD GetHostingFlags(const char *aContext, PRUint32 *_retval NS_OUTPARAM) { return !_to ? NS_ERROR_NULL_POINTER : _to->GetHostingFlags(aContext, _retval); } 

#if 0
/* Use the code below as a template for the implementation class for this interface. */

/* Header file */
class nsDispatchSupport : public nsIDispatchSupport
{
public:
  NS_DECL_ISUPPORTS
  NS_DECL_NSIDISPATCHSUPPORT

  nsDispatchSupport();

private:
  ~nsDispatchSupport();

protected:
  /* additional members */
};

/* Implementation file */
NS_IMPL_ISUPPORTS1(nsDispatchSupport, nsIDispatchSupport)

nsDispatchSupport::nsDispatchSupport()
{
  /* member initializers and constructor code */
}

nsDispatchSupport::~nsDispatchSupport()
{
  /* destructor code */
}

/* void COMVariant2JSVal (in COMVARIANTPtr comvar, out JSVal val); */
NS_IMETHODIMP nsDispatchSupport::COMVariant2JSVal(VARIANT * comvar, jsval *val NS_OUTPARAM)
{
    return NS_ERROR_NOT_IMPLEMENTED;
}

/* void JSVal2COMVariant (in JSVal var, out COMVARIANT comvar); */
NS_IMETHODIMP nsDispatchSupport::JSVal2COMVariant(jsval var, VARIANT *comvar NS_OUTPARAM)
{
    return NS_ERROR_NOT_IMPLEMENTED;
}

/* boolean isClassSafeToHost (in JSContextPtr cx, in nsCIDRef cid, in boolean capsCheck, out boolean classExists); */
NS_IMETHODIMP nsDispatchSupport::IsClassSafeToHost(JSContext * cx, const nsCID & cid, PRBool capsCheck, PRBool *classExists NS_OUTPARAM, PRBool *_retval NS_OUTPARAM)
{
    return NS_ERROR_NOT_IMPLEMENTED;
}

/* boolean isClassMarkedSafeForScripting (in nsCIDRef cid, out boolean classExists); */
NS_IMETHODIMP nsDispatchSupport::IsClassMarkedSafeForScripting(const nsCID & cid, PRBool *classExists NS_OUTPARAM, PRBool *_retval NS_OUTPARAM)
{
    return NS_ERROR_NOT_IMPLEMENTED;
}

/* boolean isObjectSafeForScripting (in voidPtr theObject, in nsIIDRef id); */
NS_IMETHODIMP nsDispatchSupport::IsObjectSafeForScripting(void * theObject, const nsIID & id, PRBool *_retval NS_OUTPARAM)
{
    return NS_ERROR_NOT_IMPLEMENTED;
}

/* unsigned long getHostingFlags (in string aContext); */
NS_IMETHODIMP nsDispatchSupport::GetHostingFlags(const char *aContext, PRUint32 *_retval NS_OUTPARAM)
{
    return NS_ERROR_NOT_IMPLEMENTED;
}

/* End of implementation class template. */
#endif

#pragma warning(pop)

#endif /* __gen_nsIDispatchSupport_h__ */
