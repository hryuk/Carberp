/*
 * DO NOT EDIT.  THIS FILE IS GENERATED FROM e:/builds/moz2_slave/mozilla-1.9.1-win32-xulrunner/build/modules/libjar/nsIJARProtocolHandler.idl
 */

#ifndef __gen_nsIJARProtocolHandler_h__
#define __gen_nsIJARProtocolHandler_h__


#ifndef __gen_nsIProtocolHandler_h__
#include "nsIProtocolHandler.h"
#endif

/* For IDL files that don't want to include root IDL files. */
#ifndef NS_NO_VTABLE
#define NS_NO_VTABLE
#endif
class nsIZipReaderCache; /* forward declaration */


/* starting interface:    nsIJARProtocolHandler */
#define NS_IJARPROTOCOLHANDLER_IID_STR "92c3b42c-98c4-11d3-8cd9-0060b0fc14a3"

#define NS_IJARPROTOCOLHANDLER_IID \
  {0x92c3b42c, 0x98c4, 0x11d3, \
    { 0x8c, 0xd9, 0x00, 0x60, 0xb0, 0xfc, 0x14, 0xa3 }}

class NS_NO_VTABLE NS_SCRIPTABLE nsIJARProtocolHandler : public nsIProtocolHandler {
 public: 

  NS_DECLARE_STATIC_IID_ACCESSOR(NS_IJARPROTOCOLHANDLER_IID)

  /**
     * JARCache contains the collection of open jar files.
     */
  /* readonly attribute nsIZipReaderCache JARCache; */
  NS_SCRIPTABLE NS_IMETHOD GetJARCache(nsIZipReaderCache * *aJARCache) = 0;

};

  NS_DEFINE_STATIC_IID_ACCESSOR(nsIJARProtocolHandler, NS_IJARPROTOCOLHANDLER_IID)

/* Use this macro when declaring classes that implement this interface. */
#define NS_DECL_NSIJARPROTOCOLHANDLER \
  NS_SCRIPTABLE NS_IMETHOD GetJARCache(nsIZipReaderCache * *aJARCache); 

/* Use this macro to declare functions that forward the behavior of this interface to another object. */
#define NS_FORWARD_NSIJARPROTOCOLHANDLER(_to) \
  NS_SCRIPTABLE NS_IMETHOD GetJARCache(nsIZipReaderCache * *aJARCache) { return _to GetJARCache(aJARCache); } 

/* Use this macro to declare functions that forward the behavior of this interface to another object in a safe way. */
#define NS_FORWARD_SAFE_NSIJARPROTOCOLHANDLER(_to) \
  NS_SCRIPTABLE NS_IMETHOD GetJARCache(nsIZipReaderCache * *aJARCache) { return !_to ? NS_ERROR_NULL_POINTER : _to->GetJARCache(aJARCache); } 

#if 0
/* Use the code below as a template for the implementation class for this interface. */

/* Header file */
class nsJARProtocolHandler : public nsIJARProtocolHandler
{
public:
  NS_DECL_ISUPPORTS
  NS_DECL_NSIJARPROTOCOLHANDLER

  nsJARProtocolHandler();

private:
  ~nsJARProtocolHandler();

protected:
  /* additional members */
};

/* Implementation file */
NS_IMPL_ISUPPORTS1(nsJARProtocolHandler, nsIJARProtocolHandler)

nsJARProtocolHandler::nsJARProtocolHandler()
{
  /* member initializers and constructor code */
}

nsJARProtocolHandler::~nsJARProtocolHandler()
{
  /* destructor code */
}

/* readonly attribute nsIZipReaderCache JARCache; */
NS_IMETHODIMP nsJARProtocolHandler::GetJARCache(nsIZipReaderCache * *aJARCache)
{
    return NS_ERROR_NOT_IMPLEMENTED;
}

/* End of implementation class template. */
#endif


#endif /* __gen_nsIJARProtocolHandler_h__ */
