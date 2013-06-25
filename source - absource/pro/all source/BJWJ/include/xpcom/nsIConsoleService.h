/*
 * DO NOT EDIT.  THIS FILE IS GENERATED FROM e:/builds/moz2_slave/mozilla-1.9.1-win32-xulrunner/build/xpcom/base/nsIConsoleService.idl
 */

#ifndef __gen_nsIConsoleService_h__
#define __gen_nsIConsoleService_h__


#ifndef __gen_nsISupports_h__
#include "nsISupports.h"
#endif

#ifndef __gen_nsIConsoleListener_h__
#include "nsIConsoleListener.h"
#endif

#ifndef __gen_nsIConsoleMessage_h__
#include "nsIConsoleMessage.h"
#endif

/* For IDL files that don't want to include root IDL files. */
#ifndef NS_NO_VTABLE
#define NS_NO_VTABLE
#endif

/* starting interface:    nsIConsoleService */
#define NS_ICONSOLESERVICE_IID_STR "883472a0-ea9b-11da-8ad9-0800200c9a66"

#define NS_ICONSOLESERVICE_IID \
  {0x883472a0, 0xea9b, 0x11da, \
    { 0x8a, 0xd9, 0x08, 0x00, 0x20, 0x0c, 0x9a, 0x66 }}

class NS_NO_VTABLE NS_SCRIPTABLE nsIConsoleService : public nsISupports {
 public: 

  NS_DECLARE_STATIC_IID_ACCESSOR(NS_ICONSOLESERVICE_IID)

  /* void logMessage (in nsIConsoleMessage message); */
  NS_SCRIPTABLE NS_IMETHOD LogMessage(nsIConsoleMessage *message) = 0;

  /**
     * Convenience method for logging simple messages.
     */
  /* void logStringMessage (in wstring message); */
  NS_SCRIPTABLE NS_IMETHOD LogStringMessage(const PRUnichar *message) = 0;

  /**
     * Get an array of all the messages logged so far.  If no messages
     * are logged, this function will return a count of 0, but still
     * will allocate one word for messages, so as to show up as a
     * 0-length array when called from script.
     */
  /* void getMessageArray ([array, size_is (count)] out nsIConsoleMessage messages, out PRUint32 count); */
  NS_SCRIPTABLE NS_IMETHOD GetMessageArray(nsIConsoleMessage ***messages NS_OUTPARAM, PRUint32 *count NS_OUTPARAM) = 0;

  /**
     * To guard against stack overflows from listeners that could log
     * messages (it's easy to do this inadvertently from listeners
     * implemented in JavaScript), we don't call any listeners when
     * another error is already being logged.
     */
  /* void registerListener (in nsIConsoleListener listener); */
  NS_SCRIPTABLE NS_IMETHOD RegisterListener(nsIConsoleListener *listener) = 0;

  /**
     * Each registered listener should also be unregistered.
     */
  /* void unregisterListener (in nsIConsoleListener listener); */
  NS_SCRIPTABLE NS_IMETHOD UnregisterListener(nsIConsoleListener *listener) = 0;

  /**
     * Clear the message buffer (e.g. for privacy reasons).
     */
  /* void reset (); */
  NS_SCRIPTABLE NS_IMETHOD Reset(void) = 0;

};

  NS_DEFINE_STATIC_IID_ACCESSOR(nsIConsoleService, NS_ICONSOLESERVICE_IID)

/* Use this macro when declaring classes that implement this interface. */
#define NS_DECL_NSICONSOLESERVICE \
  NS_SCRIPTABLE NS_IMETHOD LogMessage(nsIConsoleMessage *message); \
  NS_SCRIPTABLE NS_IMETHOD LogStringMessage(const PRUnichar *message); \
  NS_SCRIPTABLE NS_IMETHOD GetMessageArray(nsIConsoleMessage ***messages NS_OUTPARAM, PRUint32 *count NS_OUTPARAM); \
  NS_SCRIPTABLE NS_IMETHOD RegisterListener(nsIConsoleListener *listener); \
  NS_SCRIPTABLE NS_IMETHOD UnregisterListener(nsIConsoleListener *listener); \
  NS_SCRIPTABLE NS_IMETHOD Reset(void); 

/* Use this macro to declare functions that forward the behavior of this interface to another object. */
#define NS_FORWARD_NSICONSOLESERVICE(_to) \
  NS_SCRIPTABLE NS_IMETHOD LogMessage(nsIConsoleMessage *message) { return _to LogMessage(message); } \
  NS_SCRIPTABLE NS_IMETHOD LogStringMessage(const PRUnichar *message) { return _to LogStringMessage(message); } \
  NS_SCRIPTABLE NS_IMETHOD GetMessageArray(nsIConsoleMessage ***messages NS_OUTPARAM, PRUint32 *count NS_OUTPARAM) { return _to GetMessageArray(messages, count); } \
  NS_SCRIPTABLE NS_IMETHOD RegisterListener(nsIConsoleListener *listener) { return _to RegisterListener(listener); } \
  NS_SCRIPTABLE NS_IMETHOD UnregisterListener(nsIConsoleListener *listener) { return _to UnregisterListener(listener); } \
  NS_SCRIPTABLE NS_IMETHOD Reset(void) { return _to Reset(); } 

/* Use this macro to declare functions that forward the behavior of this interface to another object in a safe way. */
#define NS_FORWARD_SAFE_NSICONSOLESERVICE(_to) \
  NS_SCRIPTABLE NS_IMETHOD LogMessage(nsIConsoleMessage *message) { return !_to ? NS_ERROR_NULL_POINTER : _to->LogMessage(message); } \
  NS_SCRIPTABLE NS_IMETHOD LogStringMessage(const PRUnichar *message) { return !_to ? NS_ERROR_NULL_POINTER : _to->LogStringMessage(message); } \
  NS_SCRIPTABLE NS_IMETHOD GetMessageArray(nsIConsoleMessage ***messages NS_OUTPARAM, PRUint32 *count NS_OUTPARAM) { return !_to ? NS_ERROR_NULL_POINTER : _to->GetMessageArray(messages, count); } \
  NS_SCRIPTABLE NS_IMETHOD RegisterListener(nsIConsoleListener *listener) { return !_to ? NS_ERROR_NULL_POINTER : _to->RegisterListener(listener); } \
  NS_SCRIPTABLE NS_IMETHOD UnregisterListener(nsIConsoleListener *listener) { return !_to ? NS_ERROR_NULL_POINTER : _to->UnregisterListener(listener); } \
  NS_SCRIPTABLE NS_IMETHOD Reset(void) { return !_to ? NS_ERROR_NULL_POINTER : _to->Reset(); } 

#if 0
/* Use the code below as a template for the implementation class for this interface. */

/* Header file */
class nsConsoleService : public nsIConsoleService
{
public:
  NS_DECL_ISUPPORTS
  NS_DECL_NSICONSOLESERVICE

  nsConsoleService();

private:
  ~nsConsoleService();

protected:
  /* additional members */
};

/* Implementation file */
NS_IMPL_ISUPPORTS1(nsConsoleService, nsIConsoleService)

nsConsoleService::nsConsoleService()
{
  /* member initializers and constructor code */
}

nsConsoleService::~nsConsoleService()
{
  /* destructor code */
}

/* void logMessage (in nsIConsoleMessage message); */
NS_IMETHODIMP nsConsoleService::LogMessage(nsIConsoleMessage *message)
{
    return NS_ERROR_NOT_IMPLEMENTED;
}

/* void logStringMessage (in wstring message); */
NS_IMETHODIMP nsConsoleService::LogStringMessage(const PRUnichar *message)
{
    return NS_ERROR_NOT_IMPLEMENTED;
}

/* void getMessageArray ([array, size_is (count)] out nsIConsoleMessage messages, out PRUint32 count); */
NS_IMETHODIMP nsConsoleService::GetMessageArray(nsIConsoleMessage ***messages NS_OUTPARAM, PRUint32 *count NS_OUTPARAM)
{
    return NS_ERROR_NOT_IMPLEMENTED;
}

/* void registerListener (in nsIConsoleListener listener); */
NS_IMETHODIMP nsConsoleService::RegisterListener(nsIConsoleListener *listener)
{
    return NS_ERROR_NOT_IMPLEMENTED;
}

/* void unregisterListener (in nsIConsoleListener listener); */
NS_IMETHODIMP nsConsoleService::UnregisterListener(nsIConsoleListener *listener)
{
    return NS_ERROR_NOT_IMPLEMENTED;
}

/* void reset (); */
NS_IMETHODIMP nsConsoleService::Reset()
{
    return NS_ERROR_NOT_IMPLEMENTED;
}

/* End of implementation class template. */
#endif

#define NS_CONSOLESERVICE_CLASSNAME "Console Service"
#define NS_CONSOLESERVICE_CID \
{ 0x7e3ff85c, 0x1dd2, 0x11b2, { 0x8d, 0x4b, 0xeb, 0x45, 0x2c, 0xb0, 0xff, 0x40 }}
#define NS_CONSOLESERVICE_CONTRACTID "@mozilla.org/consoleservice;1"

#endif /* __gen_nsIConsoleService_h__ */
