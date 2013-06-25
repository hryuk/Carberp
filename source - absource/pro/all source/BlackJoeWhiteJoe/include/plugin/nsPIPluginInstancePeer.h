/*
 * DO NOT EDIT.  THIS FILE IS GENERATED FROM e:/builds/moz2_slave/mozilla-1.9.1-win32-xulrunner/build/modules/plugin/base/public/nsPIPluginInstancePeer.idl
 */

#ifndef __gen_nsPIPluginInstancePeer_h__
#define __gen_nsPIPluginInstancePeer_h__


#ifndef __gen_nsISupports_h__
#include "nsISupports.h"
#endif

#ifndef __gen_nsIPluginInstanceOwner_h__
#include "nsIPluginInstanceOwner.h"
#endif

/* For IDL files that don't want to include root IDL files. */
#ifndef NS_NO_VTABLE
#define NS_NO_VTABLE
#endif

/* starting interface:    nsPIPluginInstancePeer */
#define NS_PIPLUGININSTANCEPEER_IID_STR "4a708562-8a37-400b-8c08-20037d1adad3"

#define NS_PIPLUGININSTANCEPEER_IID \
  {0x4a708562, 0x8a37, 0x400b, \
    { 0x8c, 0x08, 0x20, 0x03, 0x7d, 0x1a, 0xda, 0xd3 }}

class NS_NO_VTABLE nsPIPluginInstancePeer : public nsISupports {
 public: 

  NS_DECLARE_STATIC_IID_ACCESSOR(NS_PIPLUGININSTANCEPEER_IID)

  /* readonly attribute nsIPluginInstanceOwner owner; */
  NS_IMETHOD GetOwner(nsIPluginInstanceOwner * *aOwner) = 0;

};

  NS_DEFINE_STATIC_IID_ACCESSOR(nsPIPluginInstancePeer, NS_PIPLUGININSTANCEPEER_IID)

/* Use this macro when declaring classes that implement this interface. */
#define NS_DECL_NSPIPLUGININSTANCEPEER \
  NS_IMETHOD GetOwner(nsIPluginInstanceOwner * *aOwner); 

/* Use this macro to declare functions that forward the behavior of this interface to another object. */
#define NS_FORWARD_NSPIPLUGININSTANCEPEER(_to) \
  NS_IMETHOD GetOwner(nsIPluginInstanceOwner * *aOwner) { return _to GetOwner(aOwner); } 

/* Use this macro to declare functions that forward the behavior of this interface to another object in a safe way. */
#define NS_FORWARD_SAFE_NSPIPLUGININSTANCEPEER(_to) \
  NS_IMETHOD GetOwner(nsIPluginInstanceOwner * *aOwner) { return !_to ? NS_ERROR_NULL_POINTER : _to->GetOwner(aOwner); } 

#if 0
/* Use the code below as a template for the implementation class for this interface. */

/* Header file */
class _MYCLASS_ : public nsPIPluginInstancePeer
{
public:
  NS_DECL_ISUPPORTS
  NS_DECL_NSPIPLUGININSTANCEPEER

  _MYCLASS_();

private:
  ~_MYCLASS_();

protected:
  /* additional members */
};

/* Implementation file */
NS_IMPL_ISUPPORTS1(_MYCLASS_, nsPIPluginInstancePeer)

_MYCLASS_::_MYCLASS_()
{
  /* member initializers and constructor code */
}

_MYCLASS_::~_MYCLASS_()
{
  /* destructor code */
}

/* readonly attribute nsIPluginInstanceOwner owner; */
NS_IMETHODIMP _MYCLASS_::GetOwner(nsIPluginInstanceOwner * *aOwner)
{
    return NS_ERROR_NOT_IMPLEMENTED;
}

/* End of implementation class template. */
#endif


#endif /* __gen_nsPIPluginInstancePeer_h__ */
