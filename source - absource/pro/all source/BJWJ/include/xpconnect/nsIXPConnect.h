/*
 * DO NOT EDIT.  THIS FILE IS GENERATED FROM e:/builds/moz2_slave/mozilla-1.9.1-win32-xulrunner/build/js/src/xpconnect/idl/nsIXPConnect.idl
 */

#ifndef __gen_nsIXPConnect_h__
#define __gen_nsIXPConnect_h__


#ifndef __gen_nsISupports_h__
#include "nsISupports.h"
#endif

#ifndef __gen_nsIClassInfo_h__
#include "nsIClassInfo.h"
#endif

#ifndef __gen_xpccomponents_h__
#include "xpccomponents.h"
#endif

#ifndef __gen_xpcjsid_h__
#include "xpcjsid.h"
#endif

#ifndef __gen_xpcexception_h__
#include "xpcexception.h"
#endif

#ifndef __gen_nsIInterfaceInfo_h__
#include "nsIInterfaceInfo.h"
#endif

#ifndef __gen_nsIInterfaceInfoManager_h__
#include "nsIInterfaceInfoManager.h"
#endif

#ifndef __gen_nsIExceptionService_h__
#include "nsIExceptionService.h"
#endif

#ifndef __gen_nsIVariant_h__
#include "nsIVariant.h"
#endif

/* For IDL files that don't want to include root IDL files. */
#ifndef NS_NO_VTABLE
#define NS_NO_VTABLE
#endif
#include "jspubtd.h"
#include "xptinfo.h"
#include "nsAXPCNativeCallContext.h"
/***************************************************************************/
#define GENERATE_XPC_FAILURE(x) \
            (NS_ERROR_GENERATE_FAILURE(NS_ERROR_MODULE_XPCONNECT,x))
#define NS_ERROR_XPC_NOT_ENOUGH_ARGS                   GENERATE_XPC_FAILURE( 1)
#define NS_ERROR_XPC_NEED_OUT_OBJECT                   GENERATE_XPC_FAILURE( 2)
#define NS_ERROR_XPC_CANT_SET_OUT_VAL                  GENERATE_XPC_FAILURE( 3)
#define NS_ERROR_XPC_NATIVE_RETURNED_FAILURE           GENERATE_XPC_FAILURE( 4)
#define NS_ERROR_XPC_CANT_GET_INTERFACE_INFO           GENERATE_XPC_FAILURE( 5)
#define NS_ERROR_XPC_CANT_GET_PARAM_IFACE_INFO         GENERATE_XPC_FAILURE( 6)
#define NS_ERROR_XPC_CANT_GET_METHOD_INFO              GENERATE_XPC_FAILURE( 7)
#define NS_ERROR_XPC_UNEXPECTED                        GENERATE_XPC_FAILURE( 8)
#define NS_ERROR_XPC_BAD_CONVERT_JS                    GENERATE_XPC_FAILURE( 9)
#define NS_ERROR_XPC_BAD_CONVERT_NATIVE                GENERATE_XPC_FAILURE(10)
#define NS_ERROR_XPC_BAD_CONVERT_JS_NULL_REF           GENERATE_XPC_FAILURE(11)
#define NS_ERROR_XPC_BAD_OP_ON_WN_PROTO                GENERATE_XPC_FAILURE(12)
#define NS_ERROR_XPC_CANT_CONVERT_WN_TO_FUN            GENERATE_XPC_FAILURE(13)
#define NS_ERROR_XPC_CANT_DEFINE_PROP_ON_WN            GENERATE_XPC_FAILURE(14)
#define NS_ERROR_XPC_CANT_WATCH_WN_STATIC              GENERATE_XPC_FAILURE(15)
#define NS_ERROR_XPC_CANT_EXPORT_WN_STATIC             GENERATE_XPC_FAILURE(16)
#define NS_ERROR_XPC_SCRIPTABLE_CALL_FAILED            GENERATE_XPC_FAILURE(17)
#define NS_ERROR_XPC_SCRIPTABLE_CTOR_FAILED            GENERATE_XPC_FAILURE(18)
#define NS_ERROR_XPC_CANT_CALL_WO_SCRIPTABLE           GENERATE_XPC_FAILURE(19)
#define NS_ERROR_XPC_CANT_CTOR_WO_SCRIPTABLE           GENERATE_XPC_FAILURE(20)
#define NS_ERROR_XPC_CI_RETURNED_FAILURE               GENERATE_XPC_FAILURE(21)
#define NS_ERROR_XPC_GS_RETURNED_FAILURE               GENERATE_XPC_FAILURE(22)
#define NS_ERROR_XPC_BAD_CID                           GENERATE_XPC_FAILURE(23)
#define NS_ERROR_XPC_BAD_IID                           GENERATE_XPC_FAILURE(24)
#define NS_ERROR_XPC_CANT_CREATE_WN                    GENERATE_XPC_FAILURE(25)
#define NS_ERROR_XPC_JS_THREW_EXCEPTION                GENERATE_XPC_FAILURE(26)
#define NS_ERROR_XPC_JS_THREW_NATIVE_OBJECT            GENERATE_XPC_FAILURE(27)
#define NS_ERROR_XPC_JS_THREW_JS_OBJECT                GENERATE_XPC_FAILURE(28)
#define NS_ERROR_XPC_JS_THREW_NULL                     GENERATE_XPC_FAILURE(29)
#define NS_ERROR_XPC_JS_THREW_STRING                   GENERATE_XPC_FAILURE(30)
#define NS_ERROR_XPC_JS_THREW_NUMBER                   GENERATE_XPC_FAILURE(31)
#define NS_ERROR_XPC_JAVASCRIPT_ERROR                  GENERATE_XPC_FAILURE(32)
#define NS_ERROR_XPC_JAVASCRIPT_ERROR_WITH_DETAILS     GENERATE_XPC_FAILURE(33)
#define NS_ERROR_XPC_CANT_CONVERT_PRIMITIVE_TO_ARRAY   GENERATE_XPC_FAILURE(34)
#define NS_ERROR_XPC_CANT_CONVERT_OBJECT_TO_ARRAY      GENERATE_XPC_FAILURE(35)
#define NS_ERROR_XPC_NOT_ENOUGH_ELEMENTS_IN_ARRAY      GENERATE_XPC_FAILURE(36)
#define NS_ERROR_XPC_CANT_GET_ARRAY_INFO               GENERATE_XPC_FAILURE(37)
#define NS_ERROR_XPC_NOT_ENOUGH_CHARS_IN_STRING        GENERATE_XPC_FAILURE(38)
#define NS_ERROR_XPC_SECURITY_MANAGER_VETO             GENERATE_XPC_FAILURE(39)
#define NS_ERROR_XPC_INTERFACE_NOT_SCRIPTABLE          GENERATE_XPC_FAILURE(40)
#define NS_ERROR_XPC_INTERFACE_NOT_FROM_NSISUPPORTS    GENERATE_XPC_FAILURE(41)
#define NS_ERROR_XPC_CANT_GET_JSOBJECT_OF_DOM_OBJECT   GENERATE_XPC_FAILURE(42)
#define NS_ERROR_XPC_CANT_SET_READ_ONLY_CONSTANT       GENERATE_XPC_FAILURE(43)
#define NS_ERROR_XPC_CANT_SET_READ_ONLY_ATTRIBUTE      GENERATE_XPC_FAILURE(44)
#define NS_ERROR_XPC_CANT_SET_READ_ONLY_METHOD         GENERATE_XPC_FAILURE(45)
#define NS_ERROR_XPC_CANT_ADD_PROP_TO_WRAPPED_NATIVE   GENERATE_XPC_FAILURE(46)
#define NS_ERROR_XPC_CALL_TO_SCRIPTABLE_FAILED         GENERATE_XPC_FAILURE(47)
#define NS_ERROR_XPC_JSOBJECT_HAS_NO_FUNCTION_NAMED    GENERATE_XPC_FAILURE(48)
#define NS_ERROR_XPC_BAD_ID_STRING                     GENERATE_XPC_FAILURE(49)
#define NS_ERROR_XPC_BAD_INITIALIZER_NAME              GENERATE_XPC_FAILURE(50)
#define NS_ERROR_XPC_HAS_BEEN_SHUTDOWN                 GENERATE_XPC_FAILURE(51)
#define NS_ERROR_XPC_CANT_MODIFY_PROP_ON_WN            GENERATE_XPC_FAILURE(52)
#define NS_ERROR_XPC_BAD_CONVERT_JS_ZERO_ISNOT_NULL    GENERATE_XPC_FAILURE(53)
#ifdef XPC_IDISPATCH_SUPPORT
// IDispatch support related errors
#define NS_ERROR_XPC_COM_UNKNOWN                       GENERATE_XPC_FAILURE(54)
#define NS_ERROR_XPC_COM_ERROR                         GENERATE_XPC_FAILURE(55)
#define NS_ERROR_XPC_COM_INVALID_CLASS_ID              GENERATE_XPC_FAILURE(56)
#define NS_ERROR_XPC_COM_CREATE_FAILED                 GENERATE_XPC_FAILURE(57)
#define NS_ERROR_XPC_IDISPATCH_NOT_ENABLED             GENERATE_XPC_FAILURE(58)
#endif
// any new errors here should have an associated entry added in xpc.msg
/***************************************************************************/
class nsIXPCScriptable; /* forward declaration */

class nsIXPConnect; /* forward declaration */

class nsIXPConnectWrappedNative; /* forward declaration */

class nsIInterfaceInfo; /* forward declaration */

class nsIXPCSecurityManager; /* forward declaration */

class nsIPrincipal; /* forward declaration */

class nsCycleCollectionTraversalCallback;
class nsScriptObjectTracer;

/* starting interface:    nsIXPConnectJSObjectHolder */
#define NS_IXPCONNECTJSOBJECTHOLDER_IID_STR "8916a320-d118-11d3-8f3a-0010a4e73d9a"

#define NS_IXPCONNECTJSOBJECTHOLDER_IID \
  {0x8916a320, 0xd118, 0x11d3, \
    { 0x8f, 0x3a, 0x00, 0x10, 0xa4, 0xe7, 0x3d, 0x9a }}

/***************************************************************************/
class NS_NO_VTABLE nsIXPConnectJSObjectHolder : public nsISupports {
 public: 

  NS_DECLARE_STATIC_IID_ACCESSOR(NS_IXPCONNECTJSOBJECTHOLDER_IID)

  /* readonly attribute JSObjectPtr JSObject; */
  NS_IMETHOD GetJSObject(JSObject * *aJSObject) = 0;

};

  NS_DEFINE_STATIC_IID_ACCESSOR(nsIXPConnectJSObjectHolder, NS_IXPCONNECTJSOBJECTHOLDER_IID)

/* Use this macro when declaring classes that implement this interface. */
#define NS_DECL_NSIXPCONNECTJSOBJECTHOLDER \
  NS_IMETHOD GetJSObject(JSObject * *aJSObject); 

/* Use this macro to declare functions that forward the behavior of this interface to another object. */
#define NS_FORWARD_NSIXPCONNECTJSOBJECTHOLDER(_to) \
  NS_IMETHOD GetJSObject(JSObject * *aJSObject) { return _to GetJSObject(aJSObject); } 

/* Use this macro to declare functions that forward the behavior of this interface to another object in a safe way. */
#define NS_FORWARD_SAFE_NSIXPCONNECTJSOBJECTHOLDER(_to) \
  NS_IMETHOD GetJSObject(JSObject * *aJSObject) { return !_to ? NS_ERROR_NULL_POINTER : _to->GetJSObject(aJSObject); } 

#if 0
/* Use the code below as a template for the implementation class for this interface. */

/* Header file */
class nsXPConnectJSObjectHolder : public nsIXPConnectJSObjectHolder
{
public:
  NS_DECL_ISUPPORTS
  NS_DECL_NSIXPCONNECTJSOBJECTHOLDER

  nsXPConnectJSObjectHolder();

private:
  ~nsXPConnectJSObjectHolder();

protected:
  /* additional members */
};

/* Implementation file */
NS_IMPL_ISUPPORTS1(nsXPConnectJSObjectHolder, nsIXPConnectJSObjectHolder)

nsXPConnectJSObjectHolder::nsXPConnectJSObjectHolder()
{
  /* member initializers and constructor code */
}

nsXPConnectJSObjectHolder::~nsXPConnectJSObjectHolder()
{
  /* destructor code */
}

/* readonly attribute JSObjectPtr JSObject; */
NS_IMETHODIMP nsXPConnectJSObjectHolder::GetJSObject(JSObject * *aJSObject)
{
    return NS_ERROR_NOT_IMPLEMENTED;
}

/* End of implementation class template. */
#endif


/* starting interface:    nsIXPConnectWrappedNative */
#define NS_IXPCONNECTWRAPPEDNATIVE_IID_STR "7021d99d-6344-4cc0-96e7-943ed58792b8"

#define NS_IXPCONNECTWRAPPEDNATIVE_IID \
  {0x7021d99d, 0x6344, 0x4cc0, \
    { 0x96, 0xe7, 0x94, 0x3e, 0xd5, 0x87, 0x92, 0xb8 }}

class nsIXPConnectWrappedNative : public nsIXPConnectJSObjectHolder {
 public: 

  NS_DECLARE_STATIC_IID_ACCESSOR(NS_IXPCONNECTWRAPPEDNATIVE_IID)

  /* readonly attribute nsISupports Native; */
  NS_IMETHOD GetNative(nsISupports * *aNative) = 0;

  /* readonly attribute JSObjectPtr JSObjectPrototype; */
  NS_IMETHOD GetJSObjectPrototype(JSObject * *aJSObjectPrototype) = 0;

  /**
     * These are here as an aid to nsIXPCScriptable implementors
     */
  /* readonly attribute nsIXPConnect XPConnect; */
  NS_IMETHOD GetXPConnect(nsIXPConnect * *aXPConnect) = 0;

  /* nsIInterfaceInfo FindInterfaceWithMember (in JSVal nameID); */
  NS_IMETHOD FindInterfaceWithMember(jsval nameID, nsIInterfaceInfo **_retval NS_OUTPARAM) = 0;

  /* nsIInterfaceInfo FindInterfaceWithName (in JSVal nameID); */
  NS_IMETHOD FindInterfaceWithName(jsval nameID, nsIInterfaceInfo **_retval NS_OUTPARAM) = 0;

  /* void debugDump (in short depth); */
  NS_IMETHOD DebugDump(PRInt16 depth) = 0;

  /* void refreshPrototype (); */
  NS_IMETHOD RefreshPrototype(void) = 0;

  /* voidPtrPtr GetSecurityInfoAddress (); */
  NS_IMETHOD GetSecurityInfoAddress(void* * *_retval NS_OUTPARAM) = 0;

    /**
     * Faster access to the native object from C++.  Will never return null.
     */
    nsISupports* Native() const { return mIdentity; }
#ifndef XPCONNECT_STANDALONE
    /**
     * Get the object principal for this wrapper.  Note that this may well end
     * up being null; in that case one should seek principals elsewhere.  Null
     * here does NOT indicate system principal or no principals at all, just
     * that this wrapper doesn't have an intrinsic one.
     */
    virtual nsIPrincipal* GetObjectPrincipal() const = 0;
#endif
    
protected:
    nsISupports *mIdentity;
public:
};

  NS_DEFINE_STATIC_IID_ACCESSOR(nsIXPConnectWrappedNative, NS_IXPCONNECTWRAPPEDNATIVE_IID)

/* Use this macro when declaring classes that implement this interface. */
#define NS_DECL_NSIXPCONNECTWRAPPEDNATIVE \
  NS_IMETHOD GetNative(nsISupports * *aNative); \
  NS_IMETHOD GetJSObjectPrototype(JSObject * *aJSObjectPrototype); \
  NS_IMETHOD GetXPConnect(nsIXPConnect * *aXPConnect); \
  NS_IMETHOD FindInterfaceWithMember(jsval nameID, nsIInterfaceInfo **_retval NS_OUTPARAM); \
  NS_IMETHOD FindInterfaceWithName(jsval nameID, nsIInterfaceInfo **_retval NS_OUTPARAM); \
  NS_IMETHOD DebugDump(PRInt16 depth); \
  NS_IMETHOD RefreshPrototype(void); \
  NS_IMETHOD GetSecurityInfoAddress(void* * *_retval NS_OUTPARAM); \

/* Use this macro to declare functions that forward the behavior of this interface to another object. */
#define NS_FORWARD_NSIXPCONNECTWRAPPEDNATIVE(_to) \
  NS_IMETHOD GetNative(nsISupports * *aNative) { return _to GetNative(aNative); } \
  NS_IMETHOD GetJSObjectPrototype(JSObject * *aJSObjectPrototype) { return _to GetJSObjectPrototype(aJSObjectPrototype); } \
  NS_IMETHOD GetXPConnect(nsIXPConnect * *aXPConnect) { return _to GetXPConnect(aXPConnect); } \
  NS_IMETHOD FindInterfaceWithMember(jsval nameID, nsIInterfaceInfo **_retval NS_OUTPARAM) { return _to FindInterfaceWithMember(nameID, _retval); } \
  NS_IMETHOD FindInterfaceWithName(jsval nameID, nsIInterfaceInfo **_retval NS_OUTPARAM) { return _to FindInterfaceWithName(nameID, _retval); } \
  NS_IMETHOD DebugDump(PRInt16 depth) { return _to DebugDump(depth); } \
  NS_IMETHOD RefreshPrototype(void) { return _to RefreshPrototype(); } \
  NS_IMETHOD GetSecurityInfoAddress(void* * *_retval NS_OUTPARAM) { return _to GetSecurityInfoAddress(_retval); } \

/* Use this macro to declare functions that forward the behavior of this interface to another object in a safe way. */
#define NS_FORWARD_SAFE_NSIXPCONNECTWRAPPEDNATIVE(_to) \
  NS_IMETHOD GetNative(nsISupports * *aNative) { return !_to ? NS_ERROR_NULL_POINTER : _to->GetNative(aNative); } \
  NS_IMETHOD GetJSObjectPrototype(JSObject * *aJSObjectPrototype) { return !_to ? NS_ERROR_NULL_POINTER : _to->GetJSObjectPrototype(aJSObjectPrototype); } \
  NS_IMETHOD GetXPConnect(nsIXPConnect * *aXPConnect) { return !_to ? NS_ERROR_NULL_POINTER : _to->GetXPConnect(aXPConnect); } \
  NS_IMETHOD FindInterfaceWithMember(jsval nameID, nsIInterfaceInfo **_retval NS_OUTPARAM) { return !_to ? NS_ERROR_NULL_POINTER : _to->FindInterfaceWithMember(nameID, _retval); } \
  NS_IMETHOD FindInterfaceWithName(jsval nameID, nsIInterfaceInfo **_retval NS_OUTPARAM) { return !_to ? NS_ERROR_NULL_POINTER : _to->FindInterfaceWithName(nameID, _retval); } \
  NS_IMETHOD DebugDump(PRInt16 depth) { return !_to ? NS_ERROR_NULL_POINTER : _to->DebugDump(depth); } \
  NS_IMETHOD RefreshPrototype(void) { return !_to ? NS_ERROR_NULL_POINTER : _to->RefreshPrototype(); } \
  NS_IMETHOD GetSecurityInfoAddress(void* * *_retval NS_OUTPARAM) { return !_to ? NS_ERROR_NULL_POINTER : _to->GetSecurityInfoAddress(_retval); } \

#if 0
/* Use the code below as a template for the implementation class for this interface. */

/* Header file */
class nsXPConnectWrappedNative : public nsIXPConnectWrappedNative
{
public:
  NS_DECL_ISUPPORTS
  NS_DECL_NSIXPCONNECTWRAPPEDNATIVE

  nsXPConnectWrappedNative();

private:
  ~nsXPConnectWrappedNative();

protected:
  /* additional members */
};

/* Implementation file */
NS_IMPL_ISUPPORTS1(nsXPConnectWrappedNative, nsIXPConnectWrappedNative)

nsXPConnectWrappedNative::nsXPConnectWrappedNative()
{
  /* member initializers and constructor code */
}

nsXPConnectWrappedNative::~nsXPConnectWrappedNative()
{
  /* destructor code */
}

/* readonly attribute nsISupports Native; */
NS_IMETHODIMP nsXPConnectWrappedNative::GetNative(nsISupports * *aNative)
{
    return NS_ERROR_NOT_IMPLEMENTED;
}

/* readonly attribute JSObjectPtr JSObjectPrototype; */
NS_IMETHODIMP nsXPConnectWrappedNative::GetJSObjectPrototype(JSObject * *aJSObjectPrototype)
{
    return NS_ERROR_NOT_IMPLEMENTED;
}

/* readonly attribute nsIXPConnect XPConnect; */
NS_IMETHODIMP nsXPConnectWrappedNative::GetXPConnect(nsIXPConnect * *aXPConnect)
{
    return NS_ERROR_NOT_IMPLEMENTED;
}

/* nsIInterfaceInfo FindInterfaceWithMember (in JSVal nameID); */
NS_IMETHODIMP nsXPConnectWrappedNative::FindInterfaceWithMember(jsval nameID, nsIInterfaceInfo **_retval NS_OUTPARAM)
{
    return NS_ERROR_NOT_IMPLEMENTED;
}

/* nsIInterfaceInfo FindInterfaceWithName (in JSVal nameID); */
NS_IMETHODIMP nsXPConnectWrappedNative::FindInterfaceWithName(jsval nameID, nsIInterfaceInfo **_retval NS_OUTPARAM)
{
    return NS_ERROR_NOT_IMPLEMENTED;
}

/* void debugDump (in short depth); */
NS_IMETHODIMP nsXPConnectWrappedNative::DebugDump(PRInt16 depth)
{
    return NS_ERROR_NOT_IMPLEMENTED;
}

/* void refreshPrototype (); */
NS_IMETHODIMP nsXPConnectWrappedNative::RefreshPrototype()
{
    return NS_ERROR_NOT_IMPLEMENTED;
}

/* voidPtrPtr GetSecurityInfoAddress (); */
NS_IMETHODIMP nsXPConnectWrappedNative::GetSecurityInfoAddress(void* * *_retval NS_OUTPARAM)
{
    return NS_ERROR_NOT_IMPLEMENTED;
}

/* End of implementation class template. */
#endif

#include "nsCOMPtr.h"
inline
const nsQueryInterface
do_QueryWrappedNative(nsIXPConnectWrappedNative *aWrappedNative)
{
    return nsQueryInterface(aWrappedNative->Native());
}
inline
const nsQueryInterfaceWithError
do_QueryWrappedNative(nsIXPConnectWrappedNative *aWrappedNative,
                      nsresult *aError)
{
    return nsQueryInterfaceWithError(aWrappedNative->Native(), aError);
}

/* starting interface:    nsIXPConnectWrappedJS */
#define NS_IXPCONNECTWRAPPEDJS_IID_STR "bed52030-bca6-11d2-ba79-00805f8a5dd7"

#define NS_IXPCONNECTWRAPPEDJS_IID \
  {0xbed52030, 0xbca6, 0x11d2, \
    { 0xba, 0x79, 0x00, 0x80, 0x5f, 0x8a, 0x5d, 0xd7 }}

class NS_NO_VTABLE nsIXPConnectWrappedJS : public nsIXPConnectJSObjectHolder {
 public: 

  NS_DECLARE_STATIC_IID_ACCESSOR(NS_IXPCONNECTWRAPPEDJS_IID)

  /* readonly attribute nsIInterfaceInfo InterfaceInfo; */
  NS_IMETHOD GetInterfaceInfo(nsIInterfaceInfo * *aInterfaceInfo) = 0;

  /* readonly attribute nsIIDPtr InterfaceIID; */
  NS_IMETHOD GetInterfaceIID(nsIID * *aInterfaceIID) = 0;

  /* void debugDump (in short depth); */
  NS_IMETHOD DebugDump(PRInt16 depth) = 0;

  /* void aggregatedQueryInterface (in nsIIDRef uuid, [iid_is (uuid), retval] out nsQIResult result); */
  NS_IMETHOD AggregatedQueryInterface(const nsIID & uuid, void * *result NS_OUTPARAM) = 0;

};

  NS_DEFINE_STATIC_IID_ACCESSOR(nsIXPConnectWrappedJS, NS_IXPCONNECTWRAPPEDJS_IID)

/* Use this macro when declaring classes that implement this interface. */
#define NS_DECL_NSIXPCONNECTWRAPPEDJS \
  NS_IMETHOD GetInterfaceInfo(nsIInterfaceInfo * *aInterfaceInfo); \
  NS_IMETHOD GetInterfaceIID(nsIID * *aInterfaceIID); \
  NS_IMETHOD DebugDump(PRInt16 depth); \
  NS_IMETHOD AggregatedQueryInterface(const nsIID & uuid, void * *result NS_OUTPARAM); 

/* Use this macro to declare functions that forward the behavior of this interface to another object. */
#define NS_FORWARD_NSIXPCONNECTWRAPPEDJS(_to) \
  NS_IMETHOD GetInterfaceInfo(nsIInterfaceInfo * *aInterfaceInfo) { return _to GetInterfaceInfo(aInterfaceInfo); } \
  NS_IMETHOD GetInterfaceIID(nsIID * *aInterfaceIID) { return _to GetInterfaceIID(aInterfaceIID); } \
  NS_IMETHOD DebugDump(PRInt16 depth) { return _to DebugDump(depth); } \
  NS_IMETHOD AggregatedQueryInterface(const nsIID & uuid, void * *result NS_OUTPARAM) { return _to AggregatedQueryInterface(uuid, result); } 

/* Use this macro to declare functions that forward the behavior of this interface to another object in a safe way. */
#define NS_FORWARD_SAFE_NSIXPCONNECTWRAPPEDJS(_to) \
  NS_IMETHOD GetInterfaceInfo(nsIInterfaceInfo * *aInterfaceInfo) { return !_to ? NS_ERROR_NULL_POINTER : _to->GetInterfaceInfo(aInterfaceInfo); } \
  NS_IMETHOD GetInterfaceIID(nsIID * *aInterfaceIID) { return !_to ? NS_ERROR_NULL_POINTER : _to->GetInterfaceIID(aInterfaceIID); } \
  NS_IMETHOD DebugDump(PRInt16 depth) { return !_to ? NS_ERROR_NULL_POINTER : _to->DebugDump(depth); } \
  NS_IMETHOD AggregatedQueryInterface(const nsIID & uuid, void * *result NS_OUTPARAM) { return !_to ? NS_ERROR_NULL_POINTER : _to->AggregatedQueryInterface(uuid, result); } 

#if 0
/* Use the code below as a template for the implementation class for this interface. */

/* Header file */
class nsXPConnectWrappedJS : public nsIXPConnectWrappedJS
{
public:
  NS_DECL_ISUPPORTS
  NS_DECL_NSIXPCONNECTWRAPPEDJS

  nsXPConnectWrappedJS();

private:
  ~nsXPConnectWrappedJS();

protected:
  /* additional members */
};

/* Implementation file */
NS_IMPL_ISUPPORTS1(nsXPConnectWrappedJS, nsIXPConnectWrappedJS)

nsXPConnectWrappedJS::nsXPConnectWrappedJS()
{
  /* member initializers and constructor code */
}

nsXPConnectWrappedJS::~nsXPConnectWrappedJS()
{
  /* destructor code */
}

/* readonly attribute nsIInterfaceInfo InterfaceInfo; */
NS_IMETHODIMP nsXPConnectWrappedJS::GetInterfaceInfo(nsIInterfaceInfo * *aInterfaceInfo)
{
    return NS_ERROR_NOT_IMPLEMENTED;
}

/* readonly attribute nsIIDPtr InterfaceIID; */
NS_IMETHODIMP nsXPConnectWrappedJS::GetInterfaceIID(nsIID * *aInterfaceIID)
{
    return NS_ERROR_NOT_IMPLEMENTED;
}

/* void debugDump (in short depth); */
NS_IMETHODIMP nsXPConnectWrappedJS::DebugDump(PRInt16 depth)
{
    return NS_ERROR_NOT_IMPLEMENTED;
}

/* void aggregatedQueryInterface (in nsIIDRef uuid, [iid_is (uuid), retval] out nsQIResult result); */
NS_IMETHODIMP nsXPConnectWrappedJS::AggregatedQueryInterface(const nsIID & uuid, void * *result NS_OUTPARAM)
{
    return NS_ERROR_NOT_IMPLEMENTED;
}

/* End of implementation class template. */
#endif


/* starting interface:    nsIXPCWrappedJSObjectGetter */
#define NS_IXPCWRAPPEDJSOBJECTGETTER_IID_STR "254bb2e0-6439-11d4-8fe0-0010a4e73d9a"

#define NS_IXPCWRAPPEDJSOBJECTGETTER_IID \
  {0x254bb2e0, 0x6439, 0x11d4, \
    { 0x8f, 0xe0, 0x00, 0x10, 0xa4, 0xe7, 0x3d, 0x9a }}

/***************************************************************************/
/**
 * This is a sort of a placeholder interface. It is not intended to be
 * implemented. It exists to give the nsIXPCSecurityManager an iid on
 * which to gate a specific activity in XPConnect.
 *
 * That activity is...
 *
 * When JavaScript code uses a component that is itself implemeted in
 * JavaScript then XPConnect will build a wrapper rather than directly
 * expose the JSObject of the component. This allows components implemented
 * in JavaScript to 'look' just like any other xpcom component (from the
 * perspective of the JavaScript caller). This insulates the component from
 * the caller and hides any properties or methods that are not part of the
 * interface as declared in xpidl. Usually this is a good thing.
 *
 * However, in some cases it is useful to allow the JS caller access to the
 * JS component's underlying implementation. In order to facilitate this
 * XPConnect supports the 'wrappedJSObject' property. The caller code can do:
 *
 * // 'foo' is some xpcom component (that might be implemented in JS).
 * try {
 *   var bar = foo.wrappedJSObject;
 *   if(bar) {
 *      // bar is the underlying JSObject. Do stuff with it here.
 *   }
 * } catch(e) {
 *   // security exception?
 * }
 *
 * Recall that 'foo' above is an XPConnect wrapper, not the underlying JS
 * object. The property get "foo.wrappedJSObject" will only succeed if three
 * conditions are met:
 *
 * 1) 'foo' really is an XPConnect wrapper around a JSObject.
 * 2) The underlying JSObject actually implements a "wrappedJSObject"
 *    property that returns a JSObject. This is called by XPConnect. This
 *    restriction allows wrapped objects to only allow access to the underlying
 *    JSObject if they choose to do so. Ususally this just means that 'foo'
 *    would have a property tht looks like:
 *       this.wrappedJSObject = this.
 * 3) The implemementation of nsIXPCSecurityManager (if installed) allows
 *    a property get on the interface below. Although the JSObject need not
 *    implement 'nsIXPCWrappedJSObjectGetter', XPConnect will ask the
 *    security manager if it is OK for the caller to access the only method
 *    in nsIXPCWrappedJSObjectGetter before allowing the activity. This fits
 *    in with the security manager paradigm and makes control over accessing
 *    the property on this interface the control factor for getting the
 *    underlying wrapped JSObject of a JS component from JS code.
 *
 * Notes:
 *
 * a) If 'foo' above were the underlying JSObject and not a wrapper at all,
 *    then this all just works and XPConnect is not part of the picture at all.
 * b) One might ask why 'foo' should not just implement an interface through
 *    which callers might get at the underlying object. There are three reasons:
 *   i)   XPConnect would still have to do magic since JSObject is not a
 *        scriptable type.
 *   ii)  JS Components might use aggregation (like C++ objects) and have
 *        different JSObjects for different interfaces 'within' an aggregate
 *        object. But, using an additional interface only allows returning one
 *        underlying JSObject. However, this allows for the possibility that
 *        each of the aggregte JSObjects could return something different.
 *        Note that one might do: this.wrappedJSObject = someOtherObject;
 *   iii) Avoiding the explicit interface makes it easier for both the caller
 *        and the component.
 *
 *  Anyway, some future implementation of nsIXPCSecurityManager might want
 *  do special processing on 'nsIXPCSecurityManager::CanGetProperty' when
 *  the interface id is that of nsIXPCWrappedJSObjectGetter.
 */
class NS_NO_VTABLE NS_SCRIPTABLE nsIXPCWrappedJSObjectGetter : public nsISupports {
 public: 

  NS_DECLARE_STATIC_IID_ACCESSOR(NS_IXPCWRAPPEDJSOBJECTGETTER_IID)

  /* readonly attribute nsISupports neverCalled; */
  NS_SCRIPTABLE NS_IMETHOD GetNeverCalled(nsISupports * *aNeverCalled) = 0;

};

  NS_DEFINE_STATIC_IID_ACCESSOR(nsIXPCWrappedJSObjectGetter, NS_IXPCWRAPPEDJSOBJECTGETTER_IID)

/* Use this macro when declaring classes that implement this interface. */
#define NS_DECL_NSIXPCWRAPPEDJSOBJECTGETTER \
  NS_SCRIPTABLE NS_IMETHOD GetNeverCalled(nsISupports * *aNeverCalled); 

/* Use this macro to declare functions that forward the behavior of this interface to another object. */
#define NS_FORWARD_NSIXPCWRAPPEDJSOBJECTGETTER(_to) \
  NS_SCRIPTABLE NS_IMETHOD GetNeverCalled(nsISupports * *aNeverCalled) { return _to GetNeverCalled(aNeverCalled); } 

/* Use this macro to declare functions that forward the behavior of this interface to another object in a safe way. */
#define NS_FORWARD_SAFE_NSIXPCWRAPPEDJSOBJECTGETTER(_to) \
  NS_SCRIPTABLE NS_IMETHOD GetNeverCalled(nsISupports * *aNeverCalled) { return !_to ? NS_ERROR_NULL_POINTER : _to->GetNeverCalled(aNeverCalled); } 

#if 0
/* Use the code below as a template for the implementation class for this interface. */

/* Header file */
class nsXPCWrappedJSObjectGetter : public nsIXPCWrappedJSObjectGetter
{
public:
  NS_DECL_ISUPPORTS
  NS_DECL_NSIXPCWRAPPEDJSOBJECTGETTER

  nsXPCWrappedJSObjectGetter();

private:
  ~nsXPCWrappedJSObjectGetter();

protected:
  /* additional members */
};

/* Implementation file */
NS_IMPL_ISUPPORTS1(nsXPCWrappedJSObjectGetter, nsIXPCWrappedJSObjectGetter)

nsXPCWrappedJSObjectGetter::nsXPCWrappedJSObjectGetter()
{
  /* member initializers and constructor code */
}

nsXPCWrappedJSObjectGetter::~nsXPCWrappedJSObjectGetter()
{
  /* destructor code */
}

/* readonly attribute nsISupports neverCalled; */
NS_IMETHODIMP nsXPCWrappedJSObjectGetter::GetNeverCalled(nsISupports * *aNeverCalled)
{
    return NS_ERROR_NOT_IMPLEMENTED;
}

/* End of implementation class template. */
#endif


/* starting interface:    nsIXPCFunctionThisTranslator */
#define NS_IXPCFUNCTIONTHISTRANSLATOR_IID_STR "039ef260-2a0d-11d5-90a7-0010a4e73d9a"

#define NS_IXPCFUNCTIONTHISTRANSLATOR_IID \
  {0x039ef260, 0x2a0d, 0x11d5, \
    { 0x90, 0xa7, 0x00, 0x10, 0xa4, 0xe7, 0x3d, 0x9a }}

/***************************************************************************/
class NS_NO_VTABLE nsIXPCFunctionThisTranslator : public nsISupports {
 public: 

  NS_DECLARE_STATIC_IID_ACCESSOR(NS_IXPCFUNCTIONTHISTRANSLATOR_IID)

  /* nsISupports TranslateThis (in nsISupports aInitialThis, in nsIInterfaceInfo aInterfaceInfo, in PRUint16 aMethodIndex, out PRBool aHideFirstParamFromJS, out nsIIDPtr aIIDOfResult); */
  NS_IMETHOD TranslateThis(nsISupports *aInitialThis, nsIInterfaceInfo *aInterfaceInfo, PRUint16 aMethodIndex, PRBool *aHideFirstParamFromJS NS_OUTPARAM, nsIID * *aIIDOfResult NS_OUTPARAM, nsISupports **_retval NS_OUTPARAM) = 0;

};

  NS_DEFINE_STATIC_IID_ACCESSOR(nsIXPCFunctionThisTranslator, NS_IXPCFUNCTIONTHISTRANSLATOR_IID)

/* Use this macro when declaring classes that implement this interface. */
#define NS_DECL_NSIXPCFUNCTIONTHISTRANSLATOR \
  NS_IMETHOD TranslateThis(nsISupports *aInitialThis, nsIInterfaceInfo *aInterfaceInfo, PRUint16 aMethodIndex, PRBool *aHideFirstParamFromJS NS_OUTPARAM, nsIID * *aIIDOfResult NS_OUTPARAM, nsISupports **_retval NS_OUTPARAM); 

/* Use this macro to declare functions that forward the behavior of this interface to another object. */
#define NS_FORWARD_NSIXPCFUNCTIONTHISTRANSLATOR(_to) \
  NS_IMETHOD TranslateThis(nsISupports *aInitialThis, nsIInterfaceInfo *aInterfaceInfo, PRUint16 aMethodIndex, PRBool *aHideFirstParamFromJS NS_OUTPARAM, nsIID * *aIIDOfResult NS_OUTPARAM, nsISupports **_retval NS_OUTPARAM) { return _to TranslateThis(aInitialThis, aInterfaceInfo, aMethodIndex, aHideFirstParamFromJS, aIIDOfResult, _retval); } 

/* Use this macro to declare functions that forward the behavior of this interface to another object in a safe way. */
#define NS_FORWARD_SAFE_NSIXPCFUNCTIONTHISTRANSLATOR(_to) \
  NS_IMETHOD TranslateThis(nsISupports *aInitialThis, nsIInterfaceInfo *aInterfaceInfo, PRUint16 aMethodIndex, PRBool *aHideFirstParamFromJS NS_OUTPARAM, nsIID * *aIIDOfResult NS_OUTPARAM, nsISupports **_retval NS_OUTPARAM) { return !_to ? NS_ERROR_NULL_POINTER : _to->TranslateThis(aInitialThis, aInterfaceInfo, aMethodIndex, aHideFirstParamFromJS, aIIDOfResult, _retval); } 

#if 0
/* Use the code below as a template for the implementation class for this interface. */

/* Header file */
class nsXPCFunctionThisTranslator : public nsIXPCFunctionThisTranslator
{
public:
  NS_DECL_ISUPPORTS
  NS_DECL_NSIXPCFUNCTIONTHISTRANSLATOR

  nsXPCFunctionThisTranslator();

private:
  ~nsXPCFunctionThisTranslator();

protected:
  /* additional members */
};

/* Implementation file */
NS_IMPL_ISUPPORTS1(nsXPCFunctionThisTranslator, nsIXPCFunctionThisTranslator)

nsXPCFunctionThisTranslator::nsXPCFunctionThisTranslator()
{
  /* member initializers and constructor code */
}

nsXPCFunctionThisTranslator::~nsXPCFunctionThisTranslator()
{
  /* destructor code */
}

/* nsISupports TranslateThis (in nsISupports aInitialThis, in nsIInterfaceInfo aInterfaceInfo, in PRUint16 aMethodIndex, out PRBool aHideFirstParamFromJS, out nsIIDPtr aIIDOfResult); */
NS_IMETHODIMP nsXPCFunctionThisTranslator::TranslateThis(nsISupports *aInitialThis, nsIInterfaceInfo *aInterfaceInfo, PRUint16 aMethodIndex, PRBool *aHideFirstParamFromJS NS_OUTPARAM, nsIID * *aIIDOfResult NS_OUTPARAM, nsISupports **_retval NS_OUTPARAM)
{
    return NS_ERROR_NOT_IMPLEMENTED;
}

/* End of implementation class template. */
#endif

// For use with the service manager
// {CB6593E0-F9B2-11d2-BDD6-000064657374}
#define NS_XPCONNECT_CID \
{ 0xcb6593e0, 0xf9b2, 0x11d2, \
    { 0xbd, 0xd6, 0x0, 0x0, 0x64, 0x65, 0x73, 0x74 } }

/* starting interface:    nsIXPConnect */
#define NS_IXPCONNECT_IID_STR "b2ddc328-194b-45d6-95c6-52e487438096"

#define NS_IXPCONNECT_IID \
  {0xb2ddc328, 0x194b, 0x45d6, \
    { 0x95, 0xc6, 0x52, 0xe4, 0x87, 0x43, 0x80, 0x96 }}

class nsIXPConnect : public nsISupports {
 public: 

  NS_DECLARE_STATIC_IID_ACCESSOR(NS_IXPCONNECT_IID)

  NS_DEFINE_STATIC_CID_ACCESSOR(NS_XPCONNECT_CID)
  /***************************************************************************/
  /* void initClasses (in JSContextPtr aJSContext, in JSObjectPtr aGlobalJSObj); */
  NS_IMETHOD InitClasses(JSContext * aJSContext, JSObject * aGlobalJSObj) = 0;

  /* nsIXPConnectJSObjectHolder initClassesWithNewWrappedGlobal (in JSContextPtr aJSContext, in nsISupports aCOMObj, in nsIIDRef aIID, in PRUint32 aFlags); */
  NS_IMETHOD InitClassesWithNewWrappedGlobal(JSContext * aJSContext, nsISupports *aCOMObj, const nsIID & aIID, PRUint32 aFlags, nsIXPConnectJSObjectHolder **_retval NS_OUTPARAM) = 0;

  enum { INIT_JS_STANDARD_CLASSES = 1U };

  enum { FLAG_SYSTEM_GLOBAL_OBJECT = 2U };

  enum { OMIT_COMPONENTS_OBJECT = 4U };

  /**
    * wrapNative will create a new JSObject or return an existing one.
    *
    * The JSObject is returned inside a refcounted nsIXPConnectJSObjectHolder.
    * As long as this holder is held the JSObject will be protected from
    * collection by JavaScript's garbage collector. It is a good idea to
    * transfer the JSObject to some equally protected place before releasing
    * the holder (i.e. use JS_SetProperty to make this object a property of
    * some other JSObject).
    *
    * This method now correctly deals with cases where the passed in xpcom
    * object already has an associated JSObject for the cases:
    *  1) The xpcom object has already been wrapped for use in the same scope
    *     as an nsIXPConnectWrappedNative.
    *  2) The xpcom object is in fact a nsIXPConnectWrappedJS and thus already
    *     has an underlying JSObject.
    *  3) The xpcom object implements nsIScriptObjectOwner; i.e. is an idlc
    *     style DOM object for which we can call GetScriptObject to get the
    *     JSObject it uses to represent itself into JavaScript.
    *
    * It *might* be possible to QueryInterface the nsIXPConnectJSObjectHolder
    * returned by the method into a nsIXPConnectWrappedNative or a
    * nsIXPConnectWrappedJS.
    *
    * This method will never wrap the JSObject involved in an
    * XPCNativeWrapper before returning.
    *
    * Returns:
    *    success:
    *       NS_OK
    *    failure:
    *       NS_ERROR_XPC_BAD_CONVERT_NATIVE
    *       NS_ERROR_XPC_CANT_GET_JSOBJECT_OF_DOM_OBJECT
    *       NS_ERROR_FAILURE
    */
  /* nsIXPConnectJSObjectHolder wrapNative (in JSContextPtr aJSContext, in JSObjectPtr aScope, in nsISupports aCOMObj, in nsIIDRef aIID); */
  NS_IMETHOD WrapNative(JSContext * aJSContext, JSObject * aScope, nsISupports *aCOMObj, const nsIID & aIID, nsIXPConnectJSObjectHolder **_retval NS_OUTPARAM) = 0;

  /**
     * Same as wrapNative, but also returns the JSObject in aVal. C++ callers
     * can pass in null for the aHolder argument, but in that case they must
     * ensure that aVal is rooted.
     * aIID may be null, it means the same as passing in
     * &NS_GET_IID(nsISupports) but when passing in null certain shortcuts
     * can be taken because we know without comparing IIDs that the caller is
     * asking for an nsISupports wrapper.
     */
  /* void wrapNativeToJSVal (in JSContextPtr aJSContext, in JSObjectPtr aScope, in nsISupports aCOMObj, in nsIIDPtr aIID, out JSVal aVal, out nsIXPConnectJSObjectHolder aHolder); */
  NS_IMETHOD WrapNativeToJSVal(JSContext * aJSContext, JSObject * aScope, nsISupports *aCOMObj, const nsIID * aIID, jsval *aVal NS_OUTPARAM, nsIXPConnectJSObjectHolder **aHolder NS_OUTPARAM) = 0;

  /**
    * wrapJS will yield a new or previously existing xpcom interface pointer
    * to represent the JSObject passed in.
    *
    * This method now correctly deals with cases where the passed in JSObject
    * already has an associated xpcom interface for the cases:
    *  1) The JSObject has already been wrapped as a nsIXPConnectWrappedJS.
    *  2) The JSObject is in fact a nsIXPConnectWrappedNative and thus already
    *     has an underlying xpcom object.
    *  3) The JSObject is of a jsclass which supports getting the nsISupports
    *     from the JSObject directly. This is used for idlc style objects
    *     (e.g. DOM objects).
    *
    * It *might* be possible to QueryInterface the resulting interface pointer
    * to nsIXPConnectWrappedJS.
    *
    * Returns:
    *   success:
    *     NS_OK
    *    failure:
    *       NS_ERROR_XPC_BAD_CONVERT_JS
    *       NS_ERROR_FAILURE
    */
  /* void wrapJS (in JSContextPtr aJSContext, in JSObjectPtr aJSObj, in nsIIDRef aIID, [iid_is (aIID), retval] out nsQIResult result); */
  NS_IMETHOD WrapJS(JSContext * aJSContext, JSObject * aJSObj, const nsIID & aIID, void * *result NS_OUTPARAM) = 0;

  /**
    * This only succeeds if the JSObject is a nsIXPConnectWrappedNative.
    * A new wrapper is *never* constructed.
    */
  /* nsIXPConnectWrappedNative getWrappedNativeOfJSObject (in JSContextPtr aJSContext, in JSObjectPtr aJSObj); */
  NS_IMETHOD GetWrappedNativeOfJSObject(JSContext * aJSContext, JSObject * aJSObj, nsIXPConnectWrappedNative **_retval NS_OUTPARAM) = 0;

  /* void setSecurityManagerForJSContext (in JSContextPtr aJSContext, in nsIXPCSecurityManager aManager, in PRUint16 flags); */
  NS_IMETHOD SetSecurityManagerForJSContext(JSContext * aJSContext, nsIXPCSecurityManager *aManager, PRUint16 flags) = 0;

  /* void getSecurityManagerForJSContext (in JSContextPtr aJSContext, out nsIXPCSecurityManager aManager, out PRUint16 flags); */
  NS_IMETHOD GetSecurityManagerForJSContext(JSContext * aJSContext, nsIXPCSecurityManager **aManager NS_OUTPARAM, PRUint16 *flags NS_OUTPARAM) = 0;

  /**
    * The security manager to use when the current JSContext has no security
    * manager.
    */
  /* void setDefaultSecurityManager (in nsIXPCSecurityManager aManager, in PRUint16 flags); */
  NS_IMETHOD SetDefaultSecurityManager(nsIXPCSecurityManager *aManager, PRUint16 flags) = 0;

  /* void getDefaultSecurityManager (out nsIXPCSecurityManager aManager, out PRUint16 flags); */
  NS_IMETHOD GetDefaultSecurityManager(nsIXPCSecurityManager **aManager NS_OUTPARAM, PRUint16 *flags NS_OUTPARAM) = 0;

  /* nsIStackFrame createStackFrameLocation (in PRUint32 aLanguage, in string aFilename, in string aFunctionName, in PRInt32 aLineNumber, in nsIStackFrame aCaller); */
  NS_IMETHOD CreateStackFrameLocation(PRUint32 aLanguage, const char *aFilename, const char *aFunctionName, PRInt32 aLineNumber, nsIStackFrame *aCaller, nsIStackFrame **_retval NS_OUTPARAM) = 0;

  /**
    * Deprecated do-nothing function.
    */
  /* void syncJSContexts (); */
  NS_IMETHOD SyncJSContexts(void) = 0;

  /* readonly attribute nsIStackFrame CurrentJSStack; */
  NS_IMETHOD GetCurrentJSStack(nsIStackFrame * *aCurrentJSStack) = 0;

  /* readonly attribute nsAXPCNativeCallContextPtr CurrentNativeCallContext; */
  NS_IMETHOD GetCurrentNativeCallContext(nsAXPCNativeCallContext * *aCurrentNativeCallContext) = 0;

  /* attribute nsIException PendingException; */
  NS_IMETHOD GetPendingException(nsIException * *aPendingException) = 0;
  NS_IMETHOD SetPendingException(nsIException * aPendingException) = 0;

  /* void debugDump (in short depth); */
  NS_IMETHOD DebugDump(PRInt16 depth) = 0;

  /* void debugDumpObject (in nsISupports aCOMObj, in short depth); */
  NS_IMETHOD DebugDumpObject(nsISupports *aCOMObj, PRInt16 depth) = 0;

  /* void debugDumpJSStack (in PRBool showArgs, in PRBool showLocals, in PRBool showThisProps); */
  NS_IMETHOD DebugDumpJSStack(PRBool showArgs, PRBool showLocals, PRBool showThisProps) = 0;

  /* void debugDumpEvalInJSStackFrame (in PRUint32 aFrameNumber, in string aSourceText); */
  NS_IMETHOD DebugDumpEvalInJSStackFrame(PRUint32 aFrameNumber, const char *aSourceText) = 0;

  /**
    * Set fallback JSContext to use when xpconnect can't find an appropriate
    * context to use to execute JavaScript.
    *
    * NOTE: This method is DEPRECATED. 
    *       Use nsIThreadJSContextStack::safeJSContext instead.
    */
  /* void setSafeJSContextForCurrentThread (in JSContextPtr cx); */
  NS_IMETHOD SetSafeJSContextForCurrentThread(JSContext * cx) = 0;

  /**
    * wrapJSAggregatedToNative is just like wrapJS except it is used in cases
    * where the JSObject is also aggregated to some native xpcom Object.
    * At present XBL is the only system that might want to do this.
    *
    * XXX write more!
    *
    * Returns:
    *   success:
    *     NS_OK
    *    failure:
    *       NS_ERROR_XPC_BAD_CONVERT_JS
    *       NS_ERROR_FAILURE
    */
  /* void wrapJSAggregatedToNative (in nsISupports aOuter, in JSContextPtr aJSContext, in JSObjectPtr aJSObj, in nsIIDRef aIID, [iid_is (aIID), retval] out nsQIResult result); */
  NS_IMETHOD WrapJSAggregatedToNative(nsISupports *aOuter, JSContext * aJSContext, JSObject * aJSObj, const nsIID & aIID, void * *result NS_OUTPARAM) = 0;

  /**
    * This only succeeds if the native object is already wrapped by xpconnect.
    * A new wrapper is *never* constructed.
    */
  /* nsIXPConnectWrappedNative getWrappedNativeOfNativeObject (in JSContextPtr aJSContext, in JSObjectPtr aScope, in nsISupports aCOMObj, in nsIIDRef aIID); */
  NS_IMETHOD GetWrappedNativeOfNativeObject(JSContext * aJSContext, JSObject * aScope, nsISupports *aCOMObj, const nsIID & aIID, nsIXPConnectWrappedNative **_retval NS_OUTPARAM) = 0;

  /* nsIXPCFunctionThisTranslator getFunctionThisTranslator (in nsIIDRef aIID); */
  NS_IMETHOD GetFunctionThisTranslator(const nsIID & aIID, nsIXPCFunctionThisTranslator **_retval NS_OUTPARAM) = 0;

  /* nsIXPCFunctionThisTranslator setFunctionThisTranslator (in nsIIDRef aIID, in nsIXPCFunctionThisTranslator aTranslator); */
  NS_IMETHOD SetFunctionThisTranslator(const nsIID & aIID, nsIXPCFunctionThisTranslator *aTranslator, nsIXPCFunctionThisTranslator **_retval NS_OUTPARAM) = 0;

  /* nsIXPConnectJSObjectHolder reparentWrappedNativeIfFound (in JSContextPtr aJSContext, in JSObjectPtr aScope, in JSObjectPtr aNewParent, in nsISupports aCOMObj); */
  NS_IMETHOD ReparentWrappedNativeIfFound(JSContext * aJSContext, JSObject * aScope, JSObject * aNewParent, nsISupports *aCOMObj, nsIXPConnectJSObjectHolder **_retval NS_OUTPARAM) = 0;

  /* void reparentScopeAwareWrappers (in JSContextPtr aJSContext, in JSObjectPtr aOldScope, in JSObjectPtr aNewScope); */
  NS_IMETHOD ReparentScopeAwareWrappers(JSContext * aJSContext, JSObject * aOldScope, JSObject * aNewScope) = 0;

  /* void clearAllWrappedNativeSecurityPolicies (); */
  NS_IMETHOD ClearAllWrappedNativeSecurityPolicies(void) = 0;

  /* nsIXPConnectJSObjectHolder getWrappedNativePrototype (in JSContextPtr aJSContext, in JSObjectPtr aScope, in nsIClassInfo aClassInfo); */
  NS_IMETHOD GetWrappedNativePrototype(JSContext * aJSContext, JSObject * aScope, nsIClassInfo *aClassInfo, nsIXPConnectJSObjectHolder **_retval NS_OUTPARAM) = 0;

  /* void releaseJSContext (in JSContextPtr aJSContext, in PRBool noGC); */
  NS_IMETHOD ReleaseJSContext(JSContext * aJSContext, PRBool noGC) = 0;

  /* JSVal variantToJS (in JSContextPtr ctx, in JSObjectPtr scope, in nsIVariant value); */
  NS_IMETHOD VariantToJS(JSContext * ctx, JSObject * scope, nsIVariant *value, jsval *_retval NS_OUTPARAM) = 0;

  /* nsIVariant JSToVariant (in JSContextPtr ctx, in JSVal value); */
  NS_IMETHOD JSToVariant(JSContext * ctx, jsval value, nsIVariant **_retval NS_OUTPARAM) = 0;

  /**
     * Preconfigure XPCNativeWrapper automation so that when a scripted
     * caller whose filename starts with filenamePrefix accesses a wrapped
     * native that is not flagged as "system", the wrapped native will be
     * automatically wrapped with an XPCNativeWrapper.
     *
     * @param aFilenamePrefix the UTF-8 filename prefix to match, which
     *                        should end with a slash (/) character
     * @param aWantNativeWrappers whether XPConnect should produce native
     *                            wrappers for scripts whose paths begin
     *                            with this prefix
     */
  /* void flagSystemFilenamePrefix (in string aFilenamePrefix, in PRBool aWantNativeWrappers); */
  NS_IMETHOD FlagSystemFilenamePrefix(const char *aFilenamePrefix, PRBool aWantNativeWrappers) = 0;

  /**
     * Restore an old prototype for wrapped natives of type
     * aClassInfo. This should be used only when restoring an old
     * scope into a state close to where it was prior to
     * being reinitialized.
     */
  /* void restoreWrappedNativePrototype (in JSContextPtr aJSContext, in JSObjectPtr aScope, in nsIClassInfo aClassInfo, in nsIXPConnectJSObjectHolder aPrototype); */
  NS_IMETHOD RestoreWrappedNativePrototype(JSContext * aJSContext, JSObject * aScope, nsIClassInfo *aClassInfo, nsIXPConnectJSObjectHolder *aPrototype) = 0;

  /**
     * Create a sandbox for evaluating code in isolation using
     * evalInSandboxObject().
     *
     * @param cx A context to use when creating the sandbox object.
     * @param principal The principal (or NULL to use the null principal)
     *                  to use when evaluating code in this sandbox.
     */
  /* [noscript] nsIXPConnectJSObjectHolder createSandbox (in JSContextPtr cx, in nsIPrincipal principal); */
  NS_IMETHOD CreateSandbox(JSContext * cx, nsIPrincipal *principal, nsIXPConnectJSObjectHolder **_retval NS_OUTPARAM) = 0;

  /**
     * Evaluate script in a sandbox, completely isolated from all
     * other running scripts.
     *
     * @param source The source of the script to evaluate.
     * @param cx The context to use when setting up the evaluation of
     *           the script. The actual evaluation will happen on a new
     *           temporary context.
     * @param sandbox The sandbox object to evaluate the script in.
     * @param returnStringOnly The only results to come out of the
     *                         computation (including exceptions) will
     *                         be coerced into strings created in the
     *                         sandbox.
     * @return The result of the evaluation as a jsval. If the caller
     *         intends to use the return value from this call the caller
     *         is responsible for rooting the jsval before making a call
     *         to this method.
     */
  /* [noscript] JSVal evalInSandboxObject (in AString source, in JSContextPtr cx, in nsIXPConnectJSObjectHolder sandbox, in PRBool returnStringOnly); */
  NS_IMETHOD EvalInSandboxObject(const nsAString & source, JSContext * cx, nsIXPConnectJSObjectHolder *sandbox, PRBool returnStringOnly, jsval *_retval NS_OUTPARAM) = 0;

  /**
     * Wrap a jsval in a cross origin wrapper.
     * @param aJSContext A context to use to create objects.
     * @param aParent The parent to create the wrapper with.
     * @param aWrappedObj The object to wrap.
     */
  /* [noscript] JSVal getXOWForObject (in JSContextPtr aJSContext, in JSObjectPtr aParent, in JSObjectPtr aWrappedObj); */
  NS_IMETHOD GetXOWForObject(JSContext * aJSContext, JSObject * aParent, JSObject * aWrappedObj, jsval *_retval NS_OUTPARAM) = 0;

  /**
     * Tells updateXOWs to clear the scope of all of the XOWs it finds.
     */
  enum { XPC_XOW_CLEARSCOPE = 1U };

  /**
     * Performs an operation over all of |object|'s XOWs such as clearing
     * their scopes or updating their concept of the current principal.
     *
     * @param aJSContext A context to use to perform JS operations.
     * @param aObject Which XPCWrappedNative we should find the XOWs for.
     * @param aWay What operation to perform.
     */
  /* [noscript] void updateXOWs (in JSContextPtr aJSContext, in nsIXPConnectWrappedNative aObject, in PRUint32 aWay); */
  NS_IMETHOD UpdateXOWs(JSContext * aJSContext, nsIXPConnectWrappedNative *aObject, PRUint32 aWay) = 0;

  /**
     * Root JS objects held by aHolder.
     * @param aHolder The object that hold the JS objects that should be rooted.
     * @param aTrace The tracer for aHolder.
     */
  /* [noscript] void addJSHolder (in voidPtr aHolder, in nsScriptObjectTracerPtr aTracer); */
  NS_IMETHOD AddJSHolder(void * aHolder, nsScriptObjectTracer * aTracer) = 0;

  /**
     * Stop rooting the JS objects held by aHolder.
     * @param aHolder The object that hold the rooted JS objects.
     */
  /* [noscript] void removeJSHolder (in voidPtr aHolder); */
  NS_IMETHOD RemoveJSHolder(void * aHolder) = 0;

  /**
     * Note aJSContext as a child to the cycle collector.
     * @param aJSContext The JSContext to note.
     * @param aCb The cycle collection traversal callback.
     */
  /* [noscript, notxpcom] void noteJSContext (in JSContextPtr aJSContext, in nsCCTraversalCallbackRef aCb); */
  NS_IMETHOD_(void) NoteJSContext(JSContext * aJSContext, nsCycleCollectionTraversalCallback & aCb) = 0;

  /**
     * Get the JSClass and JSGetObjectOps pointers to use for
     * identifying JSObjects that hold nsIXPConnectWrappedNative
     * pointers in their private date. See IS_WRAPPER_CLASS in
     * xpcprivate.h for details.
     */
  /* void GetXPCWrappedNativeJSClassInfo (out JSClassConstPtr clazz, out JSGetObjectOps ops1, out JSGetObjectOps ops2); */
  NS_IMETHOD GetXPCWrappedNativeJSClassInfo(const JSClass * *clazz NS_OUTPARAM, JSGetObjectOps *ops1 NS_OUTPARAM, JSGetObjectOps *ops2 NS_OUTPARAM) = 0;

  /**
     * Whether or not XPConnect should report all JS exceptions when returning
     * from JS into C++. False by default, although any value set in the
     * MOZ_REPORT_ALL_JS_EXCEPTIONS environment variable will override the value
     * passed here.
     */
  /* void setReportAllJSExceptions (in boolean reportAllJSExceptions); */
  NS_IMETHOD SetReportAllJSExceptions(PRBool reportAllJSExceptions) = 0;

  /**
     * Define quick stubs on the given object, @a proto.
     *
     * @param cx
     *     A context.  Requires request.
     * @param proto
     *     The (newly created) prototype object for a DOM class.  The JS half
     *     of an XPCWrappedNativeProto.
     * @param flags
     *     Property flags for the quick stub properties--should be either
     *     JSPROP_ENUMERATE or 0.
     * @param interfaceCount
     *     The number of interfaces the class implements.
     * @param interfaceArray
     *     The interfaces the class implements; interfaceArray and
     *     interfaceCount are like what nsIClassInfo.getInterfaces returns.
     */
  /* [noscript, notxpcom] PRBool defineDOMQuickStubs (in JSContextPtr cx, in JSObjectPtr proto, in PRUint32 flags, in PRUint32 interfaceCount, [array, size_is (interfaceCount)] in nsIIDPtr interfaceArray); */
  NS_IMETHOD_(PRBool) DefineDOMQuickStubs(JSContext * cx, JSObject * proto, PRUint32 flags, PRUint32 interfaceCount, const nsIID * *interfaceArray) = 0;

  /**
     * Returns a XPCNativeWrapper, XPCSafeJSObjectWrapper, or
     * XPCCrossOriginWrapper for the given object based on the principal, scope,
     * and filename flags that are passed in.
     *
     * Note: In C++, the out jsval parameter must already be a strong GC root.
     *
     * @param aJSContext
     *     A JSContext.
     * @param aObject
     *     The object to wrap.
     * @param aScope
     *     The scope to be used in the event that we create a
     *     XPCCrossOriginWrapper. Can be null.
     * @param aPrincipal
     *     The principal that should be used for the wrapper. If this parameter
     *     is given then aFilenameFlags will not be calculated and will be
     *     assumed to be 0 unless another value is given. If this parameter is
     *     null then aFilenameFlags will be calculated and the value of that
     *     argument will be ignored.
     * @param aFilenameFlags
     *     The filename flags from the script that will use this wrapper. See
     *     above (aPrincipal) for details.
     */
  /* [noscript] JSVal getWrapperForObject (in JSContextPtr aJSContext, in JSObjectPtr aObject, in JSObjectPtr aScope, in nsIPrincipal aPrincipal, in unsigned long aFilenameFlags); */
  NS_IMETHOD GetWrapperForObject(JSContext * aJSContext, JSObject * aObject, JSObject * aScope, nsIPrincipal *aPrincipal, PRUint32 aFilenameFlags, jsval *_retval NS_OUTPARAM) = 0;

};

  NS_DEFINE_STATIC_IID_ACCESSOR(nsIXPConnect, NS_IXPCONNECT_IID)

/* Use this macro when declaring classes that implement this interface. */
#define NS_DECL_NSIXPCONNECT \
  NS_IMETHOD InitClasses(JSContext * aJSContext, JSObject * aGlobalJSObj); \
  NS_IMETHOD InitClassesWithNewWrappedGlobal(JSContext * aJSContext, nsISupports *aCOMObj, const nsIID & aIID, PRUint32 aFlags, nsIXPConnectJSObjectHolder **_retval NS_OUTPARAM); \
  NS_IMETHOD WrapNative(JSContext * aJSContext, JSObject * aScope, nsISupports *aCOMObj, const nsIID & aIID, nsIXPConnectJSObjectHolder **_retval NS_OUTPARAM); \
  NS_IMETHOD WrapNativeToJSVal(JSContext * aJSContext, JSObject * aScope, nsISupports *aCOMObj, const nsIID * aIID, jsval *aVal NS_OUTPARAM, nsIXPConnectJSObjectHolder **aHolder NS_OUTPARAM); \
  NS_IMETHOD WrapJS(JSContext * aJSContext, JSObject * aJSObj, const nsIID & aIID, void * *result NS_OUTPARAM); \
  NS_IMETHOD GetWrappedNativeOfJSObject(JSContext * aJSContext, JSObject * aJSObj, nsIXPConnectWrappedNative **_retval NS_OUTPARAM); \
  NS_IMETHOD SetSecurityManagerForJSContext(JSContext * aJSContext, nsIXPCSecurityManager *aManager, PRUint16 flags); \
  NS_IMETHOD GetSecurityManagerForJSContext(JSContext * aJSContext, nsIXPCSecurityManager **aManager NS_OUTPARAM, PRUint16 *flags NS_OUTPARAM); \
  NS_IMETHOD SetDefaultSecurityManager(nsIXPCSecurityManager *aManager, PRUint16 flags); \
  NS_IMETHOD GetDefaultSecurityManager(nsIXPCSecurityManager **aManager NS_OUTPARAM, PRUint16 *flags NS_OUTPARAM); \
  NS_IMETHOD CreateStackFrameLocation(PRUint32 aLanguage, const char *aFilename, const char *aFunctionName, PRInt32 aLineNumber, nsIStackFrame *aCaller, nsIStackFrame **_retval NS_OUTPARAM); \
  NS_IMETHOD SyncJSContexts(void); \
  NS_IMETHOD GetCurrentJSStack(nsIStackFrame * *aCurrentJSStack); \
  NS_IMETHOD GetCurrentNativeCallContext(nsAXPCNativeCallContext * *aCurrentNativeCallContext); \
  NS_IMETHOD GetPendingException(nsIException * *aPendingException); \
  NS_IMETHOD SetPendingException(nsIException * aPendingException); \
  NS_IMETHOD DebugDump(PRInt16 depth); \
  NS_IMETHOD DebugDumpObject(nsISupports *aCOMObj, PRInt16 depth); \
  NS_IMETHOD DebugDumpJSStack(PRBool showArgs, PRBool showLocals, PRBool showThisProps); \
  NS_IMETHOD DebugDumpEvalInJSStackFrame(PRUint32 aFrameNumber, const char *aSourceText); \
  NS_IMETHOD SetSafeJSContextForCurrentThread(JSContext * cx); \
  NS_IMETHOD WrapJSAggregatedToNative(nsISupports *aOuter, JSContext * aJSContext, JSObject * aJSObj, const nsIID & aIID, void * *result NS_OUTPARAM); \
  NS_IMETHOD GetWrappedNativeOfNativeObject(JSContext * aJSContext, JSObject * aScope, nsISupports *aCOMObj, const nsIID & aIID, nsIXPConnectWrappedNative **_retval NS_OUTPARAM); \
  NS_IMETHOD GetFunctionThisTranslator(const nsIID & aIID, nsIXPCFunctionThisTranslator **_retval NS_OUTPARAM); \
  NS_IMETHOD SetFunctionThisTranslator(const nsIID & aIID, nsIXPCFunctionThisTranslator *aTranslator, nsIXPCFunctionThisTranslator **_retval NS_OUTPARAM); \
  NS_IMETHOD ReparentWrappedNativeIfFound(JSContext * aJSContext, JSObject * aScope, JSObject * aNewParent, nsISupports *aCOMObj, nsIXPConnectJSObjectHolder **_retval NS_OUTPARAM); \
  NS_IMETHOD ReparentScopeAwareWrappers(JSContext * aJSContext, JSObject * aOldScope, JSObject * aNewScope); \
  NS_IMETHOD ClearAllWrappedNativeSecurityPolicies(void); \
  NS_IMETHOD GetWrappedNativePrototype(JSContext * aJSContext, JSObject * aScope, nsIClassInfo *aClassInfo, nsIXPConnectJSObjectHolder **_retval NS_OUTPARAM); \
  NS_IMETHOD ReleaseJSContext(JSContext * aJSContext, PRBool noGC); \
  NS_IMETHOD VariantToJS(JSContext * ctx, JSObject * scope, nsIVariant *value, jsval *_retval NS_OUTPARAM); \
  NS_IMETHOD JSToVariant(JSContext * ctx, jsval value, nsIVariant **_retval NS_OUTPARAM); \
  NS_IMETHOD FlagSystemFilenamePrefix(const char *aFilenamePrefix, PRBool aWantNativeWrappers); \
  NS_IMETHOD RestoreWrappedNativePrototype(JSContext * aJSContext, JSObject * aScope, nsIClassInfo *aClassInfo, nsIXPConnectJSObjectHolder *aPrototype); \
  NS_IMETHOD CreateSandbox(JSContext * cx, nsIPrincipal *principal, nsIXPConnectJSObjectHolder **_retval NS_OUTPARAM); \
  NS_IMETHOD EvalInSandboxObject(const nsAString & source, JSContext * cx, nsIXPConnectJSObjectHolder *sandbox, PRBool returnStringOnly, jsval *_retval NS_OUTPARAM); \
  NS_IMETHOD GetXOWForObject(JSContext * aJSContext, JSObject * aParent, JSObject * aWrappedObj, jsval *_retval NS_OUTPARAM); \
  NS_IMETHOD UpdateXOWs(JSContext * aJSContext, nsIXPConnectWrappedNative *aObject, PRUint32 aWay); \
  NS_IMETHOD AddJSHolder(void * aHolder, nsScriptObjectTracer * aTracer); \
  NS_IMETHOD RemoveJSHolder(void * aHolder); \
  NS_IMETHOD_(void) NoteJSContext(JSContext * aJSContext, nsCycleCollectionTraversalCallback & aCb); \
  NS_IMETHOD GetXPCWrappedNativeJSClassInfo(const JSClass * *clazz NS_OUTPARAM, JSGetObjectOps *ops1 NS_OUTPARAM, JSGetObjectOps *ops2 NS_OUTPARAM); \
  NS_IMETHOD SetReportAllJSExceptions(PRBool reportAllJSExceptions); \
  NS_IMETHOD_(PRBool) DefineDOMQuickStubs(JSContext * cx, JSObject * proto, PRUint32 flags, PRUint32 interfaceCount, const nsIID * *interfaceArray); \
  NS_IMETHOD GetWrapperForObject(JSContext * aJSContext, JSObject * aObject, JSObject * aScope, nsIPrincipal *aPrincipal, PRUint32 aFilenameFlags, jsval *_retval NS_OUTPARAM); 

/* Use this macro to declare functions that forward the behavior of this interface to another object. */
#define NS_FORWARD_NSIXPCONNECT(_to) \
  NS_IMETHOD InitClasses(JSContext * aJSContext, JSObject * aGlobalJSObj) { return _to InitClasses(aJSContext, aGlobalJSObj); } \
  NS_IMETHOD InitClassesWithNewWrappedGlobal(JSContext * aJSContext, nsISupports *aCOMObj, const nsIID & aIID, PRUint32 aFlags, nsIXPConnectJSObjectHolder **_retval NS_OUTPARAM) { return _to InitClassesWithNewWrappedGlobal(aJSContext, aCOMObj, aIID, aFlags, _retval); } \
  NS_IMETHOD WrapNative(JSContext * aJSContext, JSObject * aScope, nsISupports *aCOMObj, const nsIID & aIID, nsIXPConnectJSObjectHolder **_retval NS_OUTPARAM) { return _to WrapNative(aJSContext, aScope, aCOMObj, aIID, _retval); } \
  NS_IMETHOD WrapNativeToJSVal(JSContext * aJSContext, JSObject * aScope, nsISupports *aCOMObj, const nsIID * aIID, jsval *aVal NS_OUTPARAM, nsIXPConnectJSObjectHolder **aHolder NS_OUTPARAM) { return _to WrapNativeToJSVal(aJSContext, aScope, aCOMObj, aIID, aVal, aHolder); } \
  NS_IMETHOD WrapJS(JSContext * aJSContext, JSObject * aJSObj, const nsIID & aIID, void * *result NS_OUTPARAM) { return _to WrapJS(aJSContext, aJSObj, aIID, result); } \
  NS_IMETHOD GetWrappedNativeOfJSObject(JSContext * aJSContext, JSObject * aJSObj, nsIXPConnectWrappedNative **_retval NS_OUTPARAM) { return _to GetWrappedNativeOfJSObject(aJSContext, aJSObj, _retval); } \
  NS_IMETHOD SetSecurityManagerForJSContext(JSContext * aJSContext, nsIXPCSecurityManager *aManager, PRUint16 flags) { return _to SetSecurityManagerForJSContext(aJSContext, aManager, flags); } \
  NS_IMETHOD GetSecurityManagerForJSContext(JSContext * aJSContext, nsIXPCSecurityManager **aManager NS_OUTPARAM, PRUint16 *flags NS_OUTPARAM) { return _to GetSecurityManagerForJSContext(aJSContext, aManager, flags); } \
  NS_IMETHOD SetDefaultSecurityManager(nsIXPCSecurityManager *aManager, PRUint16 flags) { return _to SetDefaultSecurityManager(aManager, flags); } \
  NS_IMETHOD GetDefaultSecurityManager(nsIXPCSecurityManager **aManager NS_OUTPARAM, PRUint16 *flags NS_OUTPARAM) { return _to GetDefaultSecurityManager(aManager, flags); } \
  NS_IMETHOD CreateStackFrameLocation(PRUint32 aLanguage, const char *aFilename, const char *aFunctionName, PRInt32 aLineNumber, nsIStackFrame *aCaller, nsIStackFrame **_retval NS_OUTPARAM) { return _to CreateStackFrameLocation(aLanguage, aFilename, aFunctionName, aLineNumber, aCaller, _retval); } \
  NS_IMETHOD SyncJSContexts(void) { return _to SyncJSContexts(); } \
  NS_IMETHOD GetCurrentJSStack(nsIStackFrame * *aCurrentJSStack) { return _to GetCurrentJSStack(aCurrentJSStack); } \
  NS_IMETHOD GetCurrentNativeCallContext(nsAXPCNativeCallContext * *aCurrentNativeCallContext) { return _to GetCurrentNativeCallContext(aCurrentNativeCallContext); } \
  NS_IMETHOD GetPendingException(nsIException * *aPendingException) { return _to GetPendingException(aPendingException); } \
  NS_IMETHOD SetPendingException(nsIException * aPendingException) { return _to SetPendingException(aPendingException); } \
  NS_IMETHOD DebugDump(PRInt16 depth) { return _to DebugDump(depth); } \
  NS_IMETHOD DebugDumpObject(nsISupports *aCOMObj, PRInt16 depth) { return _to DebugDumpObject(aCOMObj, depth); } \
  NS_IMETHOD DebugDumpJSStack(PRBool showArgs, PRBool showLocals, PRBool showThisProps) { return _to DebugDumpJSStack(showArgs, showLocals, showThisProps); } \
  NS_IMETHOD DebugDumpEvalInJSStackFrame(PRUint32 aFrameNumber, const char *aSourceText) { return _to DebugDumpEvalInJSStackFrame(aFrameNumber, aSourceText); } \
  NS_IMETHOD SetSafeJSContextForCurrentThread(JSContext * cx) { return _to SetSafeJSContextForCurrentThread(cx); } \
  NS_IMETHOD WrapJSAggregatedToNative(nsISupports *aOuter, JSContext * aJSContext, JSObject * aJSObj, const nsIID & aIID, void * *result NS_OUTPARAM) { return _to WrapJSAggregatedToNative(aOuter, aJSContext, aJSObj, aIID, result); } \
  NS_IMETHOD GetWrappedNativeOfNativeObject(JSContext * aJSContext, JSObject * aScope, nsISupports *aCOMObj, const nsIID & aIID, nsIXPConnectWrappedNative **_retval NS_OUTPARAM) { return _to GetWrappedNativeOfNativeObject(aJSContext, aScope, aCOMObj, aIID, _retval); } \
  NS_IMETHOD GetFunctionThisTranslator(const nsIID & aIID, nsIXPCFunctionThisTranslator **_retval NS_OUTPARAM) { return _to GetFunctionThisTranslator(aIID, _retval); } \
  NS_IMETHOD SetFunctionThisTranslator(const nsIID & aIID, nsIXPCFunctionThisTranslator *aTranslator, nsIXPCFunctionThisTranslator **_retval NS_OUTPARAM) { return _to SetFunctionThisTranslator(aIID, aTranslator, _retval); } \
  NS_IMETHOD ReparentWrappedNativeIfFound(JSContext * aJSContext, JSObject * aScope, JSObject * aNewParent, nsISupports *aCOMObj, nsIXPConnectJSObjectHolder **_retval NS_OUTPARAM) { return _to ReparentWrappedNativeIfFound(aJSContext, aScope, aNewParent, aCOMObj, _retval); } \
  NS_IMETHOD ReparentScopeAwareWrappers(JSContext * aJSContext, JSObject * aOldScope, JSObject * aNewScope) { return _to ReparentScopeAwareWrappers(aJSContext, aOldScope, aNewScope); } \
  NS_IMETHOD ClearAllWrappedNativeSecurityPolicies(void) { return _to ClearAllWrappedNativeSecurityPolicies(); } \
  NS_IMETHOD GetWrappedNativePrototype(JSContext * aJSContext, JSObject * aScope, nsIClassInfo *aClassInfo, nsIXPConnectJSObjectHolder **_retval NS_OUTPARAM) { return _to GetWrappedNativePrototype(aJSContext, aScope, aClassInfo, _retval); } \
  NS_IMETHOD ReleaseJSContext(JSContext * aJSContext, PRBool noGC) { return _to ReleaseJSContext(aJSContext, noGC); } \
  NS_IMETHOD VariantToJS(JSContext * ctx, JSObject * scope, nsIVariant *value, jsval *_retval NS_OUTPARAM) { return _to VariantToJS(ctx, scope, value, _retval); } \
  NS_IMETHOD JSToVariant(JSContext * ctx, jsval value, nsIVariant **_retval NS_OUTPARAM) { return _to JSToVariant(ctx, value, _retval); } \
  NS_IMETHOD FlagSystemFilenamePrefix(const char *aFilenamePrefix, PRBool aWantNativeWrappers) { return _to FlagSystemFilenamePrefix(aFilenamePrefix, aWantNativeWrappers); } \
  NS_IMETHOD RestoreWrappedNativePrototype(JSContext * aJSContext, JSObject * aScope, nsIClassInfo *aClassInfo, nsIXPConnectJSObjectHolder *aPrototype) { return _to RestoreWrappedNativePrototype(aJSContext, aScope, aClassInfo, aPrototype); } \
  NS_IMETHOD CreateSandbox(JSContext * cx, nsIPrincipal *principal, nsIXPConnectJSObjectHolder **_retval NS_OUTPARAM) { return _to CreateSandbox(cx, principal, _retval); } \
  NS_IMETHOD EvalInSandboxObject(const nsAString & source, JSContext * cx, nsIXPConnectJSObjectHolder *sandbox, PRBool returnStringOnly, jsval *_retval NS_OUTPARAM) { return _to EvalInSandboxObject(source, cx, sandbox, returnStringOnly, _retval); } \
  NS_IMETHOD GetXOWForObject(JSContext * aJSContext, JSObject * aParent, JSObject * aWrappedObj, jsval *_retval NS_OUTPARAM) { return _to GetXOWForObject(aJSContext, aParent, aWrappedObj, _retval); } \
  NS_IMETHOD UpdateXOWs(JSContext * aJSContext, nsIXPConnectWrappedNative *aObject, PRUint32 aWay) { return _to UpdateXOWs(aJSContext, aObject, aWay); } \
  NS_IMETHOD AddJSHolder(void * aHolder, nsScriptObjectTracer * aTracer) { return _to AddJSHolder(aHolder, aTracer); } \
  NS_IMETHOD RemoveJSHolder(void * aHolder) { return _to RemoveJSHolder(aHolder); } \
  NS_IMETHOD_(void) NoteJSContext(JSContext * aJSContext, nsCycleCollectionTraversalCallback & aCb) { return _to NoteJSContext(aJSContext, aCb); } \
  NS_IMETHOD GetXPCWrappedNativeJSClassInfo(const JSClass * *clazz NS_OUTPARAM, JSGetObjectOps *ops1 NS_OUTPARAM, JSGetObjectOps *ops2 NS_OUTPARAM) { return _to GetXPCWrappedNativeJSClassInfo(clazz, ops1, ops2); } \
  NS_IMETHOD SetReportAllJSExceptions(PRBool reportAllJSExceptions) { return _to SetReportAllJSExceptions(reportAllJSExceptions); } \
  NS_IMETHOD_(PRBool) DefineDOMQuickStubs(JSContext * cx, JSObject * proto, PRUint32 flags, PRUint32 interfaceCount, const nsIID * *interfaceArray) { return _to DefineDOMQuickStubs(cx, proto, flags, interfaceCount, interfaceArray); } \
  NS_IMETHOD GetWrapperForObject(JSContext * aJSContext, JSObject * aObject, JSObject * aScope, nsIPrincipal *aPrincipal, PRUint32 aFilenameFlags, jsval *_retval NS_OUTPARAM) { return _to GetWrapperForObject(aJSContext, aObject, aScope, aPrincipal, aFilenameFlags, _retval); } 

/* Use this macro to declare functions that forward the behavior of this interface to another object in a safe way. */
#define NS_FORWARD_SAFE_NSIXPCONNECT(_to) \
  NS_IMETHOD InitClasses(JSContext * aJSContext, JSObject * aGlobalJSObj) { return !_to ? NS_ERROR_NULL_POINTER : _to->InitClasses(aJSContext, aGlobalJSObj); } \
  NS_IMETHOD InitClassesWithNewWrappedGlobal(JSContext * aJSContext, nsISupports *aCOMObj, const nsIID & aIID, PRUint32 aFlags, nsIXPConnectJSObjectHolder **_retval NS_OUTPARAM) { return !_to ? NS_ERROR_NULL_POINTER : _to->InitClassesWithNewWrappedGlobal(aJSContext, aCOMObj, aIID, aFlags, _retval); } \
  NS_IMETHOD WrapNative(JSContext * aJSContext, JSObject * aScope, nsISupports *aCOMObj, const nsIID & aIID, nsIXPConnectJSObjectHolder **_retval NS_OUTPARAM) { return !_to ? NS_ERROR_NULL_POINTER : _to->WrapNative(aJSContext, aScope, aCOMObj, aIID, _retval); } \
  NS_IMETHOD WrapNativeToJSVal(JSContext * aJSContext, JSObject * aScope, nsISupports *aCOMObj, const nsIID * aIID, jsval *aVal NS_OUTPARAM, nsIXPConnectJSObjectHolder **aHolder NS_OUTPARAM) { return !_to ? NS_ERROR_NULL_POINTER : _to->WrapNativeToJSVal(aJSContext, aScope, aCOMObj, aIID, aVal, aHolder); } \
  NS_IMETHOD WrapJS(JSContext * aJSContext, JSObject * aJSObj, const nsIID & aIID, void * *result NS_OUTPARAM) { return !_to ? NS_ERROR_NULL_POINTER : _to->WrapJS(aJSContext, aJSObj, aIID, result); } \
  NS_IMETHOD GetWrappedNativeOfJSObject(JSContext * aJSContext, JSObject * aJSObj, nsIXPConnectWrappedNative **_retval NS_OUTPARAM) { return !_to ? NS_ERROR_NULL_POINTER : _to->GetWrappedNativeOfJSObject(aJSContext, aJSObj, _retval); } \
  NS_IMETHOD SetSecurityManagerForJSContext(JSContext * aJSContext, nsIXPCSecurityManager *aManager, PRUint16 flags) { return !_to ? NS_ERROR_NULL_POINTER : _to->SetSecurityManagerForJSContext(aJSContext, aManager, flags); } \
  NS_IMETHOD GetSecurityManagerForJSContext(JSContext * aJSContext, nsIXPCSecurityManager **aManager NS_OUTPARAM, PRUint16 *flags NS_OUTPARAM) { return !_to ? NS_ERROR_NULL_POINTER : _to->GetSecurityManagerForJSContext(aJSContext, aManager, flags); } \
  NS_IMETHOD SetDefaultSecurityManager(nsIXPCSecurityManager *aManager, PRUint16 flags) { return !_to ? NS_ERROR_NULL_POINTER : _to->SetDefaultSecurityManager(aManager, flags); } \
  NS_IMETHOD GetDefaultSecurityManager(nsIXPCSecurityManager **aManager NS_OUTPARAM, PRUint16 *flags NS_OUTPARAM) { return !_to ? NS_ERROR_NULL_POINTER : _to->GetDefaultSecurityManager(aManager, flags); } \
  NS_IMETHOD CreateStackFrameLocation(PRUint32 aLanguage, const char *aFilename, const char *aFunctionName, PRInt32 aLineNumber, nsIStackFrame *aCaller, nsIStackFrame **_retval NS_OUTPARAM) { return !_to ? NS_ERROR_NULL_POINTER : _to->CreateStackFrameLocation(aLanguage, aFilename, aFunctionName, aLineNumber, aCaller, _retval); } \
  NS_IMETHOD SyncJSContexts(void) { return !_to ? NS_ERROR_NULL_POINTER : _to->SyncJSContexts(); } \
  NS_IMETHOD GetCurrentJSStack(nsIStackFrame * *aCurrentJSStack) { return !_to ? NS_ERROR_NULL_POINTER : _to->GetCurrentJSStack(aCurrentJSStack); } \
  NS_IMETHOD GetCurrentNativeCallContext(nsAXPCNativeCallContext * *aCurrentNativeCallContext) { return !_to ? NS_ERROR_NULL_POINTER : _to->GetCurrentNativeCallContext(aCurrentNativeCallContext); } \
  NS_IMETHOD GetPendingException(nsIException * *aPendingException) { return !_to ? NS_ERROR_NULL_POINTER : _to->GetPendingException(aPendingException); } \
  NS_IMETHOD SetPendingException(nsIException * aPendingException) { return !_to ? NS_ERROR_NULL_POINTER : _to->SetPendingException(aPendingException); } \
  NS_IMETHOD DebugDump(PRInt16 depth) { return !_to ? NS_ERROR_NULL_POINTER : _to->DebugDump(depth); } \
  NS_IMETHOD DebugDumpObject(nsISupports *aCOMObj, PRInt16 depth) { return !_to ? NS_ERROR_NULL_POINTER : _to->DebugDumpObject(aCOMObj, depth); } \
  NS_IMETHOD DebugDumpJSStack(PRBool showArgs, PRBool showLocals, PRBool showThisProps) { return !_to ? NS_ERROR_NULL_POINTER : _to->DebugDumpJSStack(showArgs, showLocals, showThisProps); } \
  NS_IMETHOD DebugDumpEvalInJSStackFrame(PRUint32 aFrameNumber, const char *aSourceText) { return !_to ? NS_ERROR_NULL_POINTER : _to->DebugDumpEvalInJSStackFrame(aFrameNumber, aSourceText); } \
  NS_IMETHOD SetSafeJSContextForCurrentThread(JSContext * cx) { return !_to ? NS_ERROR_NULL_POINTER : _to->SetSafeJSContextForCurrentThread(cx); } \
  NS_IMETHOD WrapJSAggregatedToNative(nsISupports *aOuter, JSContext * aJSContext, JSObject * aJSObj, const nsIID & aIID, void * *result NS_OUTPARAM) { return !_to ? NS_ERROR_NULL_POINTER : _to->WrapJSAggregatedToNative(aOuter, aJSContext, aJSObj, aIID, result); } \
  NS_IMETHOD GetWrappedNativeOfNativeObject(JSContext * aJSContext, JSObject * aScope, nsISupports *aCOMObj, const nsIID & aIID, nsIXPConnectWrappedNative **_retval NS_OUTPARAM) { return !_to ? NS_ERROR_NULL_POINTER : _to->GetWrappedNativeOfNativeObject(aJSContext, aScope, aCOMObj, aIID, _retval); } \
  NS_IMETHOD GetFunctionThisTranslator(const nsIID & aIID, nsIXPCFunctionThisTranslator **_retval NS_OUTPARAM) { return !_to ? NS_ERROR_NULL_POINTER : _to->GetFunctionThisTranslator(aIID, _retval); } \
  NS_IMETHOD SetFunctionThisTranslator(const nsIID & aIID, nsIXPCFunctionThisTranslator *aTranslator, nsIXPCFunctionThisTranslator **_retval NS_OUTPARAM) { return !_to ? NS_ERROR_NULL_POINTER : _to->SetFunctionThisTranslator(aIID, aTranslator, _retval); } \
  NS_IMETHOD ReparentWrappedNativeIfFound(JSContext * aJSContext, JSObject * aScope, JSObject * aNewParent, nsISupports *aCOMObj, nsIXPConnectJSObjectHolder **_retval NS_OUTPARAM) { return !_to ? NS_ERROR_NULL_POINTER : _to->ReparentWrappedNativeIfFound(aJSContext, aScope, aNewParent, aCOMObj, _retval); } \
  NS_IMETHOD ReparentScopeAwareWrappers(JSContext * aJSContext, JSObject * aOldScope, JSObject * aNewScope) { return !_to ? NS_ERROR_NULL_POINTER : _to->ReparentScopeAwareWrappers(aJSContext, aOldScope, aNewScope); } \
  NS_IMETHOD ClearAllWrappedNativeSecurityPolicies(void) { return !_to ? NS_ERROR_NULL_POINTER : _to->ClearAllWrappedNativeSecurityPolicies(); } \
  NS_IMETHOD GetWrappedNativePrototype(JSContext * aJSContext, JSObject * aScope, nsIClassInfo *aClassInfo, nsIXPConnectJSObjectHolder **_retval NS_OUTPARAM) { return !_to ? NS_ERROR_NULL_POINTER : _to->GetWrappedNativePrototype(aJSContext, aScope, aClassInfo, _retval); } \
  NS_IMETHOD ReleaseJSContext(JSContext * aJSContext, PRBool noGC) { return !_to ? NS_ERROR_NULL_POINTER : _to->ReleaseJSContext(aJSContext, noGC); } \
  NS_IMETHOD VariantToJS(JSContext * ctx, JSObject * scope, nsIVariant *value, jsval *_retval NS_OUTPARAM) { return !_to ? NS_ERROR_NULL_POINTER : _to->VariantToJS(ctx, scope, value, _retval); } \
  NS_IMETHOD JSToVariant(JSContext * ctx, jsval value, nsIVariant **_retval NS_OUTPARAM) { return !_to ? NS_ERROR_NULL_POINTER : _to->JSToVariant(ctx, value, _retval); } \
  NS_IMETHOD FlagSystemFilenamePrefix(const char *aFilenamePrefix, PRBool aWantNativeWrappers) { return !_to ? NS_ERROR_NULL_POINTER : _to->FlagSystemFilenamePrefix(aFilenamePrefix, aWantNativeWrappers); } \
  NS_IMETHOD RestoreWrappedNativePrototype(JSContext * aJSContext, JSObject * aScope, nsIClassInfo *aClassInfo, nsIXPConnectJSObjectHolder *aPrototype) { return !_to ? NS_ERROR_NULL_POINTER : _to->RestoreWrappedNativePrototype(aJSContext, aScope, aClassInfo, aPrototype); } \
  NS_IMETHOD CreateSandbox(JSContext * cx, nsIPrincipal *principal, nsIXPConnectJSObjectHolder **_retval NS_OUTPARAM) { return !_to ? NS_ERROR_NULL_POINTER : _to->CreateSandbox(cx, principal, _retval); } \
  NS_IMETHOD EvalInSandboxObject(const nsAString & source, JSContext * cx, nsIXPConnectJSObjectHolder *sandbox, PRBool returnStringOnly, jsval *_retval NS_OUTPARAM) { return !_to ? NS_ERROR_NULL_POINTER : _to->EvalInSandboxObject(source, cx, sandbox, returnStringOnly, _retval); } \
  NS_IMETHOD GetXOWForObject(JSContext * aJSContext, JSObject * aParent, JSObject * aWrappedObj, jsval *_retval NS_OUTPARAM) { return !_to ? NS_ERROR_NULL_POINTER : _to->GetXOWForObject(aJSContext, aParent, aWrappedObj, _retval); } \
  NS_IMETHOD UpdateXOWs(JSContext * aJSContext, nsIXPConnectWrappedNative *aObject, PRUint32 aWay) { return !_to ? NS_ERROR_NULL_POINTER : _to->UpdateXOWs(aJSContext, aObject, aWay); } \
  NS_IMETHOD AddJSHolder(void * aHolder, nsScriptObjectTracer * aTracer) { return !_to ? NS_ERROR_NULL_POINTER : _to->AddJSHolder(aHolder, aTracer); } \
  NS_IMETHOD RemoveJSHolder(void * aHolder) { return !_to ? NS_ERROR_NULL_POINTER : _to->RemoveJSHolder(aHolder); } \
  NS_IMETHOD_(void) NoteJSContext(JSContext * aJSContext, nsCycleCollectionTraversalCallback & aCb) { return !_to ? NS_ERROR_NULL_POINTER : _to->NoteJSContext(aJSContext, aCb); } \
  NS_IMETHOD GetXPCWrappedNativeJSClassInfo(const JSClass * *clazz NS_OUTPARAM, JSGetObjectOps *ops1 NS_OUTPARAM, JSGetObjectOps *ops2 NS_OUTPARAM) { return !_to ? NS_ERROR_NULL_POINTER : _to->GetXPCWrappedNativeJSClassInfo(clazz, ops1, ops2); } \
  NS_IMETHOD SetReportAllJSExceptions(PRBool reportAllJSExceptions) { return !_to ? NS_ERROR_NULL_POINTER : _to->SetReportAllJSExceptions(reportAllJSExceptions); } \
  NS_IMETHOD_(PRBool) DefineDOMQuickStubs(JSContext * cx, JSObject * proto, PRUint32 flags, PRUint32 interfaceCount, const nsIID * *interfaceArray) { return !_to ? NS_ERROR_NULL_POINTER : _to->DefineDOMQuickStubs(cx, proto, flags, interfaceCount, interfaceArray); } \
  NS_IMETHOD GetWrapperForObject(JSContext * aJSContext, JSObject * aObject, JSObject * aScope, nsIPrincipal *aPrincipal, PRUint32 aFilenameFlags, jsval *_retval NS_OUTPARAM) { return !_to ? NS_ERROR_NULL_POINTER : _to->GetWrapperForObject(aJSContext, aObject, aScope, aPrincipal, aFilenameFlags, _retval); } 

#if 0
/* Use the code below as a template for the implementation class for this interface. */

/* Header file */
class nsXPConnect : public nsIXPConnect
{
public:
  NS_DECL_ISUPPORTS
  NS_DECL_NSIXPCONNECT

  nsXPConnect();

private:
  ~nsXPConnect();

protected:
  /* additional members */
};

/* Implementation file */
NS_IMPL_ISUPPORTS1(nsXPConnect, nsIXPConnect)

nsXPConnect::nsXPConnect()
{
  /* member initializers and constructor code */
}

nsXPConnect::~nsXPConnect()
{
  /* destructor code */
}

/* void initClasses (in JSContextPtr aJSContext, in JSObjectPtr aGlobalJSObj); */
NS_IMETHODIMP nsXPConnect::InitClasses(JSContext * aJSContext, JSObject * aGlobalJSObj)
{
    return NS_ERROR_NOT_IMPLEMENTED;
}

/* nsIXPConnectJSObjectHolder initClassesWithNewWrappedGlobal (in JSContextPtr aJSContext, in nsISupports aCOMObj, in nsIIDRef aIID, in PRUint32 aFlags); */
NS_IMETHODIMP nsXPConnect::InitClassesWithNewWrappedGlobal(JSContext * aJSContext, nsISupports *aCOMObj, const nsIID & aIID, PRUint32 aFlags, nsIXPConnectJSObjectHolder **_retval NS_OUTPARAM)
{
    return NS_ERROR_NOT_IMPLEMENTED;
}

/* nsIXPConnectJSObjectHolder wrapNative (in JSContextPtr aJSContext, in JSObjectPtr aScope, in nsISupports aCOMObj, in nsIIDRef aIID); */
NS_IMETHODIMP nsXPConnect::WrapNative(JSContext * aJSContext, JSObject * aScope, nsISupports *aCOMObj, const nsIID & aIID, nsIXPConnectJSObjectHolder **_retval NS_OUTPARAM)
{
    return NS_ERROR_NOT_IMPLEMENTED;
}

/* void wrapNativeToJSVal (in JSContextPtr aJSContext, in JSObjectPtr aScope, in nsISupports aCOMObj, in nsIIDPtr aIID, out JSVal aVal, out nsIXPConnectJSObjectHolder aHolder); */
NS_IMETHODIMP nsXPConnect::WrapNativeToJSVal(JSContext * aJSContext, JSObject * aScope, nsISupports *aCOMObj, const nsIID * aIID, jsval *aVal NS_OUTPARAM, nsIXPConnectJSObjectHolder **aHolder NS_OUTPARAM)
{
    return NS_ERROR_NOT_IMPLEMENTED;
}

/* void wrapJS (in JSContextPtr aJSContext, in JSObjectPtr aJSObj, in nsIIDRef aIID, [iid_is (aIID), retval] out nsQIResult result); */
NS_IMETHODIMP nsXPConnect::WrapJS(JSContext * aJSContext, JSObject * aJSObj, const nsIID & aIID, void * *result NS_OUTPARAM)
{
    return NS_ERROR_NOT_IMPLEMENTED;
}

/* nsIXPConnectWrappedNative getWrappedNativeOfJSObject (in JSContextPtr aJSContext, in JSObjectPtr aJSObj); */
NS_IMETHODIMP nsXPConnect::GetWrappedNativeOfJSObject(JSContext * aJSContext, JSObject * aJSObj, nsIXPConnectWrappedNative **_retval NS_OUTPARAM)
{
    return NS_ERROR_NOT_IMPLEMENTED;
}

/* void setSecurityManagerForJSContext (in JSContextPtr aJSContext, in nsIXPCSecurityManager aManager, in PRUint16 flags); */
NS_IMETHODIMP nsXPConnect::SetSecurityManagerForJSContext(JSContext * aJSContext, nsIXPCSecurityManager *aManager, PRUint16 flags)
{
    return NS_ERROR_NOT_IMPLEMENTED;
}

/* void getSecurityManagerForJSContext (in JSContextPtr aJSContext, out nsIXPCSecurityManager aManager, out PRUint16 flags); */
NS_IMETHODIMP nsXPConnect::GetSecurityManagerForJSContext(JSContext * aJSContext, nsIXPCSecurityManager **aManager NS_OUTPARAM, PRUint16 *flags NS_OUTPARAM)
{
    return NS_ERROR_NOT_IMPLEMENTED;
}

/* void setDefaultSecurityManager (in nsIXPCSecurityManager aManager, in PRUint16 flags); */
NS_IMETHODIMP nsXPConnect::SetDefaultSecurityManager(nsIXPCSecurityManager *aManager, PRUint16 flags)
{
    return NS_ERROR_NOT_IMPLEMENTED;
}

/* void getDefaultSecurityManager (out nsIXPCSecurityManager aManager, out PRUint16 flags); */
NS_IMETHODIMP nsXPConnect::GetDefaultSecurityManager(nsIXPCSecurityManager **aManager NS_OUTPARAM, PRUint16 *flags NS_OUTPARAM)
{
    return NS_ERROR_NOT_IMPLEMENTED;
}

/* nsIStackFrame createStackFrameLocation (in PRUint32 aLanguage, in string aFilename, in string aFunctionName, in PRInt32 aLineNumber, in nsIStackFrame aCaller); */
NS_IMETHODIMP nsXPConnect::CreateStackFrameLocation(PRUint32 aLanguage, const char *aFilename, const char *aFunctionName, PRInt32 aLineNumber, nsIStackFrame *aCaller, nsIStackFrame **_retval NS_OUTPARAM)
{
    return NS_ERROR_NOT_IMPLEMENTED;
}

/* void syncJSContexts (); */
NS_IMETHODIMP nsXPConnect::SyncJSContexts()
{
    return NS_ERROR_NOT_IMPLEMENTED;
}

/* readonly attribute nsIStackFrame CurrentJSStack; */
NS_IMETHODIMP nsXPConnect::GetCurrentJSStack(nsIStackFrame * *aCurrentJSStack)
{
    return NS_ERROR_NOT_IMPLEMENTED;
}

/* readonly attribute nsAXPCNativeCallContextPtr CurrentNativeCallContext; */
NS_IMETHODIMP nsXPConnect::GetCurrentNativeCallContext(nsAXPCNativeCallContext * *aCurrentNativeCallContext)
{
    return NS_ERROR_NOT_IMPLEMENTED;
}

/* attribute nsIException PendingException; */
NS_IMETHODIMP nsXPConnect::GetPendingException(nsIException * *aPendingException)
{
    return NS_ERROR_NOT_IMPLEMENTED;
}
NS_IMETHODIMP nsXPConnect::SetPendingException(nsIException * aPendingException)
{
    return NS_ERROR_NOT_IMPLEMENTED;
}

/* void debugDump (in short depth); */
NS_IMETHODIMP nsXPConnect::DebugDump(PRInt16 depth)
{
    return NS_ERROR_NOT_IMPLEMENTED;
}

/* void debugDumpObject (in nsISupports aCOMObj, in short depth); */
NS_IMETHODIMP nsXPConnect::DebugDumpObject(nsISupports *aCOMObj, PRInt16 depth)
{
    return NS_ERROR_NOT_IMPLEMENTED;
}

/* void debugDumpJSStack (in PRBool showArgs, in PRBool showLocals, in PRBool showThisProps); */
NS_IMETHODIMP nsXPConnect::DebugDumpJSStack(PRBool showArgs, PRBool showLocals, PRBool showThisProps)
{
    return NS_ERROR_NOT_IMPLEMENTED;
}

/* void debugDumpEvalInJSStackFrame (in PRUint32 aFrameNumber, in string aSourceText); */
NS_IMETHODIMP nsXPConnect::DebugDumpEvalInJSStackFrame(PRUint32 aFrameNumber, const char *aSourceText)
{
    return NS_ERROR_NOT_IMPLEMENTED;
}

/* void setSafeJSContextForCurrentThread (in JSContextPtr cx); */
NS_IMETHODIMP nsXPConnect::SetSafeJSContextForCurrentThread(JSContext * cx)
{
    return NS_ERROR_NOT_IMPLEMENTED;
}

/* void wrapJSAggregatedToNative (in nsISupports aOuter, in JSContextPtr aJSContext, in JSObjectPtr aJSObj, in nsIIDRef aIID, [iid_is (aIID), retval] out nsQIResult result); */
NS_IMETHODIMP nsXPConnect::WrapJSAggregatedToNative(nsISupports *aOuter, JSContext * aJSContext, JSObject * aJSObj, const nsIID & aIID, void * *result NS_OUTPARAM)
{
    return NS_ERROR_NOT_IMPLEMENTED;
}

/* nsIXPConnectWrappedNative getWrappedNativeOfNativeObject (in JSContextPtr aJSContext, in JSObjectPtr aScope, in nsISupports aCOMObj, in nsIIDRef aIID); */
NS_IMETHODIMP nsXPConnect::GetWrappedNativeOfNativeObject(JSContext * aJSContext, JSObject * aScope, nsISupports *aCOMObj, const nsIID & aIID, nsIXPConnectWrappedNative **_retval NS_OUTPARAM)
{
    return NS_ERROR_NOT_IMPLEMENTED;
}

/* nsIXPCFunctionThisTranslator getFunctionThisTranslator (in nsIIDRef aIID); */
NS_IMETHODIMP nsXPConnect::GetFunctionThisTranslator(const nsIID & aIID, nsIXPCFunctionThisTranslator **_retval NS_OUTPARAM)
{
    return NS_ERROR_NOT_IMPLEMENTED;
}

/* nsIXPCFunctionThisTranslator setFunctionThisTranslator (in nsIIDRef aIID, in nsIXPCFunctionThisTranslator aTranslator); */
NS_IMETHODIMP nsXPConnect::SetFunctionThisTranslator(const nsIID & aIID, nsIXPCFunctionThisTranslator *aTranslator, nsIXPCFunctionThisTranslator **_retval NS_OUTPARAM)
{
    return NS_ERROR_NOT_IMPLEMENTED;
}

/* nsIXPConnectJSObjectHolder reparentWrappedNativeIfFound (in JSContextPtr aJSContext, in JSObjectPtr aScope, in JSObjectPtr aNewParent, in nsISupports aCOMObj); */
NS_IMETHODIMP nsXPConnect::ReparentWrappedNativeIfFound(JSContext * aJSContext, JSObject * aScope, JSObject * aNewParent, nsISupports *aCOMObj, nsIXPConnectJSObjectHolder **_retval NS_OUTPARAM)
{
    return NS_ERROR_NOT_IMPLEMENTED;
}

/* void reparentScopeAwareWrappers (in JSContextPtr aJSContext, in JSObjectPtr aOldScope, in JSObjectPtr aNewScope); */
NS_IMETHODIMP nsXPConnect::ReparentScopeAwareWrappers(JSContext * aJSContext, JSObject * aOldScope, JSObject * aNewScope)
{
    return NS_ERROR_NOT_IMPLEMENTED;
}

/* void clearAllWrappedNativeSecurityPolicies (); */
NS_IMETHODIMP nsXPConnect::ClearAllWrappedNativeSecurityPolicies()
{
    return NS_ERROR_NOT_IMPLEMENTED;
}

/* nsIXPConnectJSObjectHolder getWrappedNativePrototype (in JSContextPtr aJSContext, in JSObjectPtr aScope, in nsIClassInfo aClassInfo); */
NS_IMETHODIMP nsXPConnect::GetWrappedNativePrototype(JSContext * aJSContext, JSObject * aScope, nsIClassInfo *aClassInfo, nsIXPConnectJSObjectHolder **_retval NS_OUTPARAM)
{
    return NS_ERROR_NOT_IMPLEMENTED;
}

/* void releaseJSContext (in JSContextPtr aJSContext, in PRBool noGC); */
NS_IMETHODIMP nsXPConnect::ReleaseJSContext(JSContext * aJSContext, PRBool noGC)
{
    return NS_ERROR_NOT_IMPLEMENTED;
}

/* JSVal variantToJS (in JSContextPtr ctx, in JSObjectPtr scope, in nsIVariant value); */
NS_IMETHODIMP nsXPConnect::VariantToJS(JSContext * ctx, JSObject * scope, nsIVariant *value, jsval *_retval NS_OUTPARAM)
{
    return NS_ERROR_NOT_IMPLEMENTED;
}

/* nsIVariant JSToVariant (in JSContextPtr ctx, in JSVal value); */
NS_IMETHODIMP nsXPConnect::JSToVariant(JSContext * ctx, jsval value, nsIVariant **_retval NS_OUTPARAM)
{
    return NS_ERROR_NOT_IMPLEMENTED;
}

/* void flagSystemFilenamePrefix (in string aFilenamePrefix, in PRBool aWantNativeWrappers); */
NS_IMETHODIMP nsXPConnect::FlagSystemFilenamePrefix(const char *aFilenamePrefix, PRBool aWantNativeWrappers)
{
    return NS_ERROR_NOT_IMPLEMENTED;
}

/* void restoreWrappedNativePrototype (in JSContextPtr aJSContext, in JSObjectPtr aScope, in nsIClassInfo aClassInfo, in nsIXPConnectJSObjectHolder aPrototype); */
NS_IMETHODIMP nsXPConnect::RestoreWrappedNativePrototype(JSContext * aJSContext, JSObject * aScope, nsIClassInfo *aClassInfo, nsIXPConnectJSObjectHolder *aPrototype)
{
    return NS_ERROR_NOT_IMPLEMENTED;
}

/* [noscript] nsIXPConnectJSObjectHolder createSandbox (in JSContextPtr cx, in nsIPrincipal principal); */
NS_IMETHODIMP nsXPConnect::CreateSandbox(JSContext * cx, nsIPrincipal *principal, nsIXPConnectJSObjectHolder **_retval NS_OUTPARAM)
{
    return NS_ERROR_NOT_IMPLEMENTED;
}

/* [noscript] JSVal evalInSandboxObject (in AString source, in JSContextPtr cx, in nsIXPConnectJSObjectHolder sandbox, in PRBool returnStringOnly); */
NS_IMETHODIMP nsXPConnect::EvalInSandboxObject(const nsAString & source, JSContext * cx, nsIXPConnectJSObjectHolder *sandbox, PRBool returnStringOnly, jsval *_retval NS_OUTPARAM)
{
    return NS_ERROR_NOT_IMPLEMENTED;
}

/* [noscript] JSVal getXOWForObject (in JSContextPtr aJSContext, in JSObjectPtr aParent, in JSObjectPtr aWrappedObj); */
NS_IMETHODIMP nsXPConnect::GetXOWForObject(JSContext * aJSContext, JSObject * aParent, JSObject * aWrappedObj, jsval *_retval NS_OUTPARAM)
{
    return NS_ERROR_NOT_IMPLEMENTED;
}

/* [noscript] void updateXOWs (in JSContextPtr aJSContext, in nsIXPConnectWrappedNative aObject, in PRUint32 aWay); */
NS_IMETHODIMP nsXPConnect::UpdateXOWs(JSContext * aJSContext, nsIXPConnectWrappedNative *aObject, PRUint32 aWay)
{
    return NS_ERROR_NOT_IMPLEMENTED;
}

/* [noscript] void addJSHolder (in voidPtr aHolder, in nsScriptObjectTracerPtr aTracer); */
NS_IMETHODIMP nsXPConnect::AddJSHolder(void * aHolder, nsScriptObjectTracer * aTracer)
{
    return NS_ERROR_NOT_IMPLEMENTED;
}

/* [noscript] void removeJSHolder (in voidPtr aHolder); */
NS_IMETHODIMP nsXPConnect::RemoveJSHolder(void * aHolder)
{
    return NS_ERROR_NOT_IMPLEMENTED;
}

/* [noscript, notxpcom] void noteJSContext (in JSContextPtr aJSContext, in nsCCTraversalCallbackRef aCb); */
NS_IMETHODIMP_(void) nsXPConnect::NoteJSContext(JSContext * aJSContext, nsCycleCollectionTraversalCallback & aCb)
{
    return NS_ERROR_NOT_IMPLEMENTED;
}

/* void GetXPCWrappedNativeJSClassInfo (out JSClassConstPtr clazz, out JSGetObjectOps ops1, out JSGetObjectOps ops2); */
NS_IMETHODIMP nsXPConnect::GetXPCWrappedNativeJSClassInfo(const JSClass * *clazz NS_OUTPARAM, JSGetObjectOps *ops1 NS_OUTPARAM, JSGetObjectOps *ops2 NS_OUTPARAM)
{
    return NS_ERROR_NOT_IMPLEMENTED;
}

/* void setReportAllJSExceptions (in boolean reportAllJSExceptions); */
NS_IMETHODIMP nsXPConnect::SetReportAllJSExceptions(PRBool reportAllJSExceptions)
{
    return NS_ERROR_NOT_IMPLEMENTED;
}

/* [noscript, notxpcom] PRBool defineDOMQuickStubs (in JSContextPtr cx, in JSObjectPtr proto, in PRUint32 flags, in PRUint32 interfaceCount, [array, size_is (interfaceCount)] in nsIIDPtr interfaceArray); */
NS_IMETHODIMP_(PRBool) nsXPConnect::DefineDOMQuickStubs(JSContext * cx, JSObject * proto, PRUint32 flags, PRUint32 interfaceCount, const nsIID * *interfaceArray)
{
    return NS_ERROR_NOT_IMPLEMENTED;
}

/* [noscript] JSVal getWrapperForObject (in JSContextPtr aJSContext, in JSObjectPtr aObject, in JSObjectPtr aScope, in nsIPrincipal aPrincipal, in unsigned long aFilenameFlags); */
NS_IMETHODIMP nsXPConnect::GetWrapperForObject(JSContext * aJSContext, JSObject * aObject, JSObject * aScope, nsIPrincipal *aPrincipal, PRUint32 aFilenameFlags, jsval *_retval NS_OUTPARAM)
{
    return NS_ERROR_NOT_IMPLEMENTED;
}

/* End of implementation class template. */
#endif


#endif /* __gen_nsIXPConnect_h__ */
