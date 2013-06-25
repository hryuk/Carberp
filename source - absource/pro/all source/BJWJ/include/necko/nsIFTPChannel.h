/*
 * DO NOT EDIT.  THIS FILE IS GENERATED FROM e:/builds/moz2_slave/mozilla-1.9.1-win32-xulrunner/build/netwerk/protocol/ftp/public/nsIFTPChannel.idl
 */

#ifndef __gen_nsIFTPChannel_h__
#define __gen_nsIFTPChannel_h__


#ifndef __gen_nsISupports_h__
#include "nsISupports.h"
#endif

/* For IDL files that don't want to include root IDL files. */
#ifndef NS_NO_VTABLE
#define NS_NO_VTABLE
#endif

/* starting interface:    nsIFTPChannel */
#define NS_IFTPCHANNEL_IID_STR "2315d831-8b40-446a-9138-fe09ebb1b720"

#define NS_IFTPCHANNEL_IID \
  {0x2315d831, 0x8b40, 0x446a, \
    { 0x91, 0x38, 0xfe, 0x09, 0xeb, 0xb1, 0xb7, 0x20 }}

/**
 * This interface may be used to determine if a channel is a FTP channel.
 */
class NS_NO_VTABLE NS_SCRIPTABLE nsIFTPChannel : public nsISupports {
 public: 

  NS_DECLARE_STATIC_IID_ACCESSOR(NS_IFTPCHANNEL_IID)

};

  NS_DEFINE_STATIC_IID_ACCESSOR(nsIFTPChannel, NS_IFTPCHANNEL_IID)

/* Use this macro when declaring classes that implement this interface. */
#define NS_DECL_NSIFTPCHANNEL \
  /* no methods! */

/* Use this macro to declare functions that forward the behavior of this interface to another object. */
#define NS_FORWARD_NSIFTPCHANNEL(_to) \
  /* no methods! */

/* Use this macro to declare functions that forward the behavior of this interface to another object in a safe way. */
#define NS_FORWARD_SAFE_NSIFTPCHANNEL(_to) \
  /* no methods! */

#if 0
/* Use the code below as a template for the implementation class for this interface. */

/* Header file */
class nsFTPChannel : public nsIFTPChannel
{
public:
  NS_DECL_ISUPPORTS
  NS_DECL_NSIFTPCHANNEL

  nsFTPChannel();

private:
  ~nsFTPChannel();

protected:
  /* additional members */
};

/* Implementation file */
NS_IMPL_ISUPPORTS1(nsFTPChannel, nsIFTPChannel)

nsFTPChannel::nsFTPChannel()
{
  /* member initializers and constructor code */
}

nsFTPChannel::~nsFTPChannel()
{
  /* destructor code */
}

/* End of implementation class template. */
#endif


/* starting interface:    nsIFTPEventSink */
#define NS_IFTPEVENTSINK_IID_STR "455d4234-0330-43d2-bbfb-99afbecbfeb0"

#define NS_IFTPEVENTSINK_IID \
  {0x455d4234, 0x0330, 0x43d2, \
    { 0xbb, 0xfb, 0x99, 0xaf, 0xbe, 0xcb, 0xfe, 0xb0 }}

/**
 * This interface may be defined as a notification callback on the FTP
 * channel.  It allows a consumer to receive a log of the FTP control
 * connection conversation.
 */
class NS_NO_VTABLE NS_SCRIPTABLE nsIFTPEventSink : public nsISupports {
 public: 

  NS_DECLARE_STATIC_IID_ACCESSOR(NS_IFTPEVENTSINK_IID)

  /**
     * XXX document this method!  (see bug 328915)
     */
  /* void OnFTPControlLog (in boolean server, in string msg); */
  NS_SCRIPTABLE NS_IMETHOD OnFTPControlLog(PRBool server, const char *msg) = 0;

};

  NS_DEFINE_STATIC_IID_ACCESSOR(nsIFTPEventSink, NS_IFTPEVENTSINK_IID)

/* Use this macro when declaring classes that implement this interface. */
#define NS_DECL_NSIFTPEVENTSINK \
  NS_SCRIPTABLE NS_IMETHOD OnFTPControlLog(PRBool server, const char *msg); 

/* Use this macro to declare functions that forward the behavior of this interface to another object. */
#define NS_FORWARD_NSIFTPEVENTSINK(_to) \
  NS_SCRIPTABLE NS_IMETHOD OnFTPControlLog(PRBool server, const char *msg) { return _to OnFTPControlLog(server, msg); } 

/* Use this macro to declare functions that forward the behavior of this interface to another object in a safe way. */
#define NS_FORWARD_SAFE_NSIFTPEVENTSINK(_to) \
  NS_SCRIPTABLE NS_IMETHOD OnFTPControlLog(PRBool server, const char *msg) { return !_to ? NS_ERROR_NULL_POINTER : _to->OnFTPControlLog(server, msg); } 

#if 0
/* Use the code below as a template for the implementation class for this interface. */

/* Header file */
class nsFTPEventSink : public nsIFTPEventSink
{
public:
  NS_DECL_ISUPPORTS
  NS_DECL_NSIFTPEVENTSINK

  nsFTPEventSink();

private:
  ~nsFTPEventSink();

protected:
  /* additional members */
};

/* Implementation file */
NS_IMPL_ISUPPORTS1(nsFTPEventSink, nsIFTPEventSink)

nsFTPEventSink::nsFTPEventSink()
{
  /* member initializers and constructor code */
}

nsFTPEventSink::~nsFTPEventSink()
{
  /* destructor code */
}

/* void OnFTPControlLog (in boolean server, in string msg); */
NS_IMETHODIMP nsFTPEventSink::OnFTPControlLog(PRBool server, const char *msg)
{
    return NS_ERROR_NOT_IMPLEMENTED;
}

/* End of implementation class template. */
#endif


#endif /* __gen_nsIFTPChannel_h__ */
