/*
 * DO NOT EDIT.  THIS FILE IS GENERATED FROM e:/builds/moz2_slave/mozilla-1.9.1-win32-xulrunner/build/js/src/xpconnect/idl/XPCIDispatch.idl
 */

#ifndef __gen_XPCIDispatch_h__
#define __gen_XPCIDispatch_h__


#ifndef __gen_nsISupports_h__
#include "nsISupports.h"
#endif

/* For IDL files that don't want to include root IDL files. */
#ifndef NS_NO_VTABLE
#define NS_NO_VTABLE
#endif
#error "You should not be including this file"

/* starting interface:    IDispatch */
#define IDISPATCH_IID_STR "00020400-0000-0000-c000-000000000046"

#define IDISPATCH_IID \
  {0x00020400, 0x0000, 0x0000, \
    { 0xc0, 0x00, 0x00, 0x00, 0x00, 0x00, 0x00, 0x46 }}

/**
 * This interface is not to be used directly, it is to be used internally
 * for XPConnect's IDispatch support
 */
class NS_NO_VTABLE NS_SCRIPTABLE IDispatch : public nsISupports {
 public: 

  NS_DECLARE_STATIC_IID_ACCESSOR(IDISPATCH_IID)

};

  NS_DEFINE_STATIC_IID_ACCESSOR(IDispatch, IDISPATCH_IID)

/* Use this macro when declaring classes that implement this interface. */
#define NS_DECL_IDISPATCH \
  /* no methods! */

/* Use this macro to declare functions that forward the behavior of this interface to another object. */
#define NS_FORWARD_IDISPATCH(_to) \
  /* no methods! */

/* Use this macro to declare functions that forward the behavior of this interface to another object in a safe way. */
#define NS_FORWARD_SAFE_IDISPATCH(_to) \
  /* no methods! */

#if 0
/* Use the code below as a template for the implementation class for this interface. */

/* Header file */
class _MYCLASS_ : public IDispatch
{
public:
  NS_DECL_ISUPPORTS
  NS_DECL_IDISPATCH

  _MYCLASS_();

private:
  ~_MYCLASS_();

protected:
  /* additional members */
};

/* Implementation file */
NS_IMPL_ISUPPORTS1(_MYCLASS_, IDispatch)

_MYCLASS_::_MYCLASS_()
{
  /* member initializers and constructor code */
}

_MYCLASS_::~_MYCLASS_()
{
  /* destructor code */
}

/* End of implementation class template. */
#endif


#endif /* __gen_XPCIDispatch_h__ */
