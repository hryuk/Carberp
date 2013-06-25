/*
 * DO NOT EDIT.  THIS FILE IS GENERATED FROM e:/builds/moz2_slave/mozilla-1.9.1-win32-xulrunner/build/js/src/xpconnect/idl/xpcIJSWeakReference.idl
 */

#ifndef __gen_xpcIJSWeakReference_h__
#define __gen_xpcIJSWeakReference_h__


#ifndef __gen_nsISupports_h__
#include "nsISupports.h"
#endif

/* For IDL files that don't want to include root IDL files. */
#ifndef NS_NO_VTABLE
#define NS_NO_VTABLE
#endif

/* starting interface:    xpcIJSWeakReference */
#define XPCIJSWEAKREFERENCE_IID_STR "5b776cd4-952b-45a2-b363-84e99e8fe608"

#define XPCIJSWEAKREFERENCE_IID \
  {0x5b776cd4, 0x952b, 0x45a2, \
    { 0xb3, 0x63, 0x84, 0xe9, 0x9e, 0x8f, 0xe6, 0x08 }}

class NS_NO_VTABLE NS_SCRIPTABLE xpcIJSWeakReference : public nsISupports {
 public: 

  NS_DECLARE_STATIC_IID_ACCESSOR(XPCIJSWEAKREFERENCE_IID)

  /**
   * To be called from JS only.
   *
   * Returns the referenced JS object or null if the JS object has
   * been garbage collected.
   */
  /* void get (); */
  NS_SCRIPTABLE NS_IMETHOD Get(void) = 0;

};

  NS_DEFINE_STATIC_IID_ACCESSOR(xpcIJSWeakReference, XPCIJSWEAKREFERENCE_IID)

/* Use this macro when declaring classes that implement this interface. */
#define NS_DECL_XPCIJSWEAKREFERENCE \
  NS_SCRIPTABLE NS_IMETHOD Get(void); 

/* Use this macro to declare functions that forward the behavior of this interface to another object. */
#define NS_FORWARD_XPCIJSWEAKREFERENCE(_to) \
  NS_SCRIPTABLE NS_IMETHOD Get(void) { return _to Get(); } 

/* Use this macro to declare functions that forward the behavior of this interface to another object in a safe way. */
#define NS_FORWARD_SAFE_XPCIJSWEAKREFERENCE(_to) \
  NS_SCRIPTABLE NS_IMETHOD Get(void) { return !_to ? NS_ERROR_NULL_POINTER : _to->Get(); } 

#if 0
/* Use the code below as a template for the implementation class for this interface. */

/* Header file */
class _MYCLASS_ : public xpcIJSWeakReference
{
public:
  NS_DECL_ISUPPORTS
  NS_DECL_XPCIJSWEAKREFERENCE

  _MYCLASS_();

private:
  ~_MYCLASS_();

protected:
  /* additional members */
};

/* Implementation file */
NS_IMPL_ISUPPORTS1(_MYCLASS_, xpcIJSWeakReference)

_MYCLASS_::_MYCLASS_()
{
  /* member initializers and constructor code */
}

_MYCLASS_::~_MYCLASS_()
{
  /* destructor code */
}

/* void get (); */
NS_IMETHODIMP _MYCLASS_::Get()
{
    return NS_ERROR_NOT_IMPLEMENTED;
}

/* End of implementation class template. */
#endif


#endif /* __gen_xpcIJSWeakReference_h__ */
