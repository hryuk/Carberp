/*
 * DO NOT EDIT.  THIS FILE IS GENERATED FROM e:/builds/moz2_slave/mozilla-1.9.1-win32-xulrunner/build/embedding/components/commandhandler/public/nsPICommandUpdater.idl
 */

#ifndef __gen_nsPICommandUpdater_h__
#define __gen_nsPICommandUpdater_h__


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

/* starting interface:    nsPICommandUpdater */
#define NS_PICOMMANDUPDATER_IID_STR "b135f602-0bfe-11d5-a73c-f0e420e8293c"

#define NS_PICOMMANDUPDATER_IID \
  {0xb135f602, 0x0bfe, 0x11d5, \
    { 0xa7, 0x3c, 0xf0, 0xe4, 0x20, 0xe8, 0x29, 0x3c }}

class NS_NO_VTABLE NS_SCRIPTABLE nsPICommandUpdater : public nsISupports {
 public: 

  NS_DECLARE_STATIC_IID_ACCESSOR(NS_PICOMMANDUPDATER_IID)

  /* void init (in nsIDOMWindow aWindow); */
  NS_SCRIPTABLE NS_IMETHOD Init(nsIDOMWindow *aWindow) = 0;

  /* void commandStatusChanged (in string aCommandName); */
  NS_SCRIPTABLE NS_IMETHOD CommandStatusChanged(const char *aCommandName) = 0;

};

  NS_DEFINE_STATIC_IID_ACCESSOR(nsPICommandUpdater, NS_PICOMMANDUPDATER_IID)

/* Use this macro when declaring classes that implement this interface. */
#define NS_DECL_NSPICOMMANDUPDATER \
  NS_SCRIPTABLE NS_IMETHOD Init(nsIDOMWindow *aWindow); \
  NS_SCRIPTABLE NS_IMETHOD CommandStatusChanged(const char *aCommandName); 

/* Use this macro to declare functions that forward the behavior of this interface to another object. */
#define NS_FORWARD_NSPICOMMANDUPDATER(_to) \
  NS_SCRIPTABLE NS_IMETHOD Init(nsIDOMWindow *aWindow) { return _to Init(aWindow); } \
  NS_SCRIPTABLE NS_IMETHOD CommandStatusChanged(const char *aCommandName) { return _to CommandStatusChanged(aCommandName); } 

/* Use this macro to declare functions that forward the behavior of this interface to another object in a safe way. */
#define NS_FORWARD_SAFE_NSPICOMMANDUPDATER(_to) \
  NS_SCRIPTABLE NS_IMETHOD Init(nsIDOMWindow *aWindow) { return !_to ? NS_ERROR_NULL_POINTER : _to->Init(aWindow); } \
  NS_SCRIPTABLE NS_IMETHOD CommandStatusChanged(const char *aCommandName) { return !_to ? NS_ERROR_NULL_POINTER : _to->CommandStatusChanged(aCommandName); } 

#if 0
/* Use the code below as a template for the implementation class for this interface. */

/* Header file */
class _MYCLASS_ : public nsPICommandUpdater
{
public:
  NS_DECL_ISUPPORTS
  NS_DECL_NSPICOMMANDUPDATER

  _MYCLASS_();

private:
  ~_MYCLASS_();

protected:
  /* additional members */
};

/* Implementation file */
NS_IMPL_ISUPPORTS1(_MYCLASS_, nsPICommandUpdater)

_MYCLASS_::_MYCLASS_()
{
  /* member initializers and constructor code */
}

_MYCLASS_::~_MYCLASS_()
{
  /* destructor code */
}

/* void init (in nsIDOMWindow aWindow); */
NS_IMETHODIMP _MYCLASS_::Init(nsIDOMWindow *aWindow)
{
    return NS_ERROR_NOT_IMPLEMENTED;
}

/* void commandStatusChanged (in string aCommandName); */
NS_IMETHODIMP _MYCLASS_::CommandStatusChanged(const char *aCommandName)
{
    return NS_ERROR_NOT_IMPLEMENTED;
}

/* End of implementation class template. */
#endif


#endif /* __gen_nsPICommandUpdater_h__ */
