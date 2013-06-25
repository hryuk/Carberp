/*
 * DO NOT EDIT.  THIS FILE IS GENERATED FROM e:/builds/moz2_slave/mozilla-1.9.1-win32-xulrunner/build/js/src/xpconnect/idl/xpcIJSModuleLoader.idl
 */

#ifndef __gen_xpcIJSModuleLoader_h__
#define __gen_xpcIJSModuleLoader_h__


#ifndef __gen_nsISupports_h__
#include "nsISupports.h"
#endif

/* For IDL files that don't want to include root IDL files. */
#ifndef NS_NO_VTABLE
#define NS_NO_VTABLE
#endif
struct JSObject;

/* starting interface:    xpcIJSModuleLoader */
#define XPCIJSMODULELOADER_IID_STR "89da3673-e699-4f26-9ed7-11a528011434"

#define XPCIJSMODULELOADER_IID \
  {0x89da3673, 0xe699, 0x4f26, \
    { 0x9e, 0xd7, 0x11, 0xa5, 0x28, 0x01, 0x14, 0x34 }}

class NS_NO_VTABLE NS_SCRIPTABLE xpcIJSModuleLoader : public nsISupports {
 public: 

  NS_DECLARE_STATIC_IID_ACCESSOR(XPCIJSMODULELOADER_IID)

  /**
   * To be called from JavaScript only.
   *
   * Synchronously loads and evaluates the js file located at
   * 'registryLocation' with a new, fully privileged global object.
   *
   * If 'targetObj' is specified and equal to null, returns the
   * module's global object. Otherwise (if 'targetObj' is not
   * specified, or 'targetObj' is != null) looks for a property
   * 'EXPORTED_SYMBOLS' on the new global object. 'EXPORTED_SYMBOLS'
   * is expected to be an array of strings identifying properties on
   * the global object.  These properties will be installed as
   * properties on 'targetObj', or, if 'targetObj' is not specified,
   * on the caller's global object. If 'EXPORTED_SYMBOLS' is not
   * found, an error is thrown.
   *
   * @param resourceURI A resource:// URI string to load the module from.
   * @param targetObj  the object to install the exported properties on.
   *        If this parameter is a primitive value, this method throws
   *        an exception.
   * @returns the module code's global object.
   *
   * The implementation maintains a hash of registryLocation->global obj.
   * Subsequent invocations of importModule with 'registryLocation'
   * pointing to the same file will not cause the module to be re-evaluated,
   * but the symbols in EXPORTED_SYMBOLS will be exported into the
   * specified target object and the global object returned as above.
   *
   * (This comment is duplicated to nsIXPCComponents_Utils.)
   */
  /* void import (in AUTF8String aResourceURI); */
  NS_SCRIPTABLE NS_IMETHOD Import(const nsACString & aResourceURI) = 0;

  /**
   * Imports the JS module at 'registryLocation' to the JS object
   * 'targetObj' (if != null) as described for importModule() and
   * returns the module's global object.
   */
  /* [noscript] JSObjectPtr importInto (in AUTF8String aResourceURI, in JSObjectPtr targetObj, in nsAXPCNativeCallContextPtr cc); */
  NS_IMETHOD ImportInto(const nsACString & aResourceURI, JSObject * targetObj, nsAXPCNativeCallContext * cc, JSObject * *_retval NS_OUTPARAM) = 0;

};

  NS_DEFINE_STATIC_IID_ACCESSOR(xpcIJSModuleLoader, XPCIJSMODULELOADER_IID)

/* Use this macro when declaring classes that implement this interface. */
#define NS_DECL_XPCIJSMODULELOADER \
  NS_SCRIPTABLE NS_IMETHOD Import(const nsACString & aResourceURI); \
  NS_IMETHOD ImportInto(const nsACString & aResourceURI, JSObject * targetObj, nsAXPCNativeCallContext * cc, JSObject * *_retval NS_OUTPARAM); 

/* Use this macro to declare functions that forward the behavior of this interface to another object. */
#define NS_FORWARD_XPCIJSMODULELOADER(_to) \
  NS_SCRIPTABLE NS_IMETHOD Import(const nsACString & aResourceURI) { return _to Import(aResourceURI); } \
  NS_IMETHOD ImportInto(const nsACString & aResourceURI, JSObject * targetObj, nsAXPCNativeCallContext * cc, JSObject * *_retval NS_OUTPARAM) { return _to ImportInto(aResourceURI, targetObj, cc, _retval); } 

/* Use this macro to declare functions that forward the behavior of this interface to another object in a safe way. */
#define NS_FORWARD_SAFE_XPCIJSMODULELOADER(_to) \
  NS_SCRIPTABLE NS_IMETHOD Import(const nsACString & aResourceURI) { return !_to ? NS_ERROR_NULL_POINTER : _to->Import(aResourceURI); } \
  NS_IMETHOD ImportInto(const nsACString & aResourceURI, JSObject * targetObj, nsAXPCNativeCallContext * cc, JSObject * *_retval NS_OUTPARAM) { return !_to ? NS_ERROR_NULL_POINTER : _to->ImportInto(aResourceURI, targetObj, cc, _retval); } 

#if 0
/* Use the code below as a template for the implementation class for this interface. */

/* Header file */
class _MYCLASS_ : public xpcIJSModuleLoader
{
public:
  NS_DECL_ISUPPORTS
  NS_DECL_XPCIJSMODULELOADER

  _MYCLASS_();

private:
  ~_MYCLASS_();

protected:
  /* additional members */
};

/* Implementation file */
NS_IMPL_ISUPPORTS1(_MYCLASS_, xpcIJSModuleLoader)

_MYCLASS_::_MYCLASS_()
{
  /* member initializers and constructor code */
}

_MYCLASS_::~_MYCLASS_()
{
  /* destructor code */
}

/* void import (in AUTF8String aResourceURI); */
NS_IMETHODIMP _MYCLASS_::Import(const nsACString & aResourceURI)
{
    return NS_ERROR_NOT_IMPLEMENTED;
}

/* [noscript] JSObjectPtr importInto (in AUTF8String aResourceURI, in JSObjectPtr targetObj, in nsAXPCNativeCallContextPtr cc); */
NS_IMETHODIMP _MYCLASS_::ImportInto(const nsACString & aResourceURI, JSObject * targetObj, nsAXPCNativeCallContext * cc, JSObject * *_retval NS_OUTPARAM)
{
    return NS_ERROR_NOT_IMPLEMENTED;
}

/* End of implementation class template. */
#endif


#endif /* __gen_xpcIJSModuleLoader_h__ */
