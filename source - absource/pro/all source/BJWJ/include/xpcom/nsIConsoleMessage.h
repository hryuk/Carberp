/*
 * DO NOT EDIT.  THIS FILE IS GENERATED FROM e:/builds/moz2_slave/mozilla-1.9.1-win32-xulrunner/build/xpcom/base/nsIConsoleMessage.idl
 */

#ifndef __gen_nsIConsoleMessage_h__
#define __gen_nsIConsoleMessage_h__


#ifndef __gen_nsISupports_h__
#include "nsISupports.h"
#endif

/* For IDL files that don't want to include root IDL files. */
#ifndef NS_NO_VTABLE
#define NS_NO_VTABLE
#endif

/* starting interface:    nsIConsoleMessage */
#define NS_ICONSOLEMESSAGE_IID_STR "41bd8784-1dd2-11b2-9553-8606958fffe1"

#define NS_ICONSOLEMESSAGE_IID \
  {0x41bd8784, 0x1dd2, 0x11b2, \
    { 0x95, 0x53, 0x86, 0x06, 0x95, 0x8f, 0xff, 0xe1 }}

/**
 * This is intended as a base interface; implementations may want to
 * provide an object that can be qi'ed to provide more specific
 * message information.
 */
class NS_NO_VTABLE NS_SCRIPTABLE nsIConsoleMessage : public nsISupports {
 public: 

  NS_DECLARE_STATIC_IID_ACCESSOR(NS_ICONSOLEMESSAGE_IID)

  /* [binaryname (MessageMoz)] readonly attribute wstring message; */
  NS_SCRIPTABLE NS_IMETHOD GetMessageMoz(PRUnichar * *aMessage) = 0;

};

  NS_DEFINE_STATIC_IID_ACCESSOR(nsIConsoleMessage, NS_ICONSOLEMESSAGE_IID)

/* Use this macro when declaring classes that implement this interface. */
#define NS_DECL_NSICONSOLEMESSAGE \
  NS_SCRIPTABLE NS_IMETHOD GetMessageMoz(PRUnichar * *aMessage); 

/* Use this macro to declare functions that forward the behavior of this interface to another object. */
#define NS_FORWARD_NSICONSOLEMESSAGE(_to) \
  NS_SCRIPTABLE NS_IMETHOD GetMessageMoz(PRUnichar * *aMessage) { return _to GetMessageMoz(aMessage); } 

/* Use this macro to declare functions that forward the behavior of this interface to another object in a safe way. */
#define NS_FORWARD_SAFE_NSICONSOLEMESSAGE(_to) \
  NS_SCRIPTABLE NS_IMETHOD GetMessageMoz(PRUnichar * *aMessage) { return !_to ? NS_ERROR_NULL_POINTER : _to->GetMessageMoz(aMessage); } 

#if 0
/* Use the code below as a template for the implementation class for this interface. */

/* Header file */
class nsConsoleMessage : public nsIConsoleMessage
{
public:
  NS_DECL_ISUPPORTS
  NS_DECL_NSICONSOLEMESSAGE

  nsConsoleMessage();

private:
  ~nsConsoleMessage();

protected:
  /* additional members */
};

/* Implementation file */
NS_IMPL_ISUPPORTS1(nsConsoleMessage, nsIConsoleMessage)

nsConsoleMessage::nsConsoleMessage()
{
  /* member initializers and constructor code */
}

nsConsoleMessage::~nsConsoleMessage()
{
  /* destructor code */
}

/* [binaryname (MessageMoz)] readonly attribute wstring message; */
NS_IMETHODIMP nsConsoleMessage::GetMessageMoz(PRUnichar * *aMessage)
{
    return NS_ERROR_NOT_IMPLEMENTED;
}

/* End of implementation class template. */
#endif

#define NS_CONSOLEMESSAGE_CID \
{ 0x56c9d666, 0x1dd2, 0x11b2, { 0xb4, 0x3c, 0xa8, 0x4b, 0xf3, 0xb3, 0xec, 0xbb }}
#define NS_CONSOLEMESSAGE_CONTRACTID "@mozilla.org/consolemessage;1"

#endif /* __gen_nsIConsoleMessage_h__ */
