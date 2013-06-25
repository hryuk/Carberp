/*
 * DO NOT EDIT.  THIS FILE IS GENERATED FROM e:/builds/moz2_slave/mozilla-1.9.1-win32-xulrunner/build/embedding/browser/webBrowser/nsICommandHandler.idl
 */

#ifndef __gen_nsICommandHandler_h__
#define __gen_nsICommandHandler_h__


#ifndef __gen_nsISupports_h__
#include "nsISupports.h"
#endif

/* For IDL files that don't want to include root IDL files. */
#ifndef NS_NO_VTABLE
#define NS_NO_VTABLE
#endif
class nsIDOMWindow; /* forward declaration */


/* starting interface:    nsICommandHandlerInit */
#define NS_ICOMMANDHANDLERINIT_IID_STR "731c6c50-67d6-11d4-9529-0020183bf181"

#define NS_ICOMMANDHANDLERINIT_IID \
  {0x731c6c50, 0x67d6, 0x11d4, \
    { 0x95, 0x29, 0x00, 0x20, 0x18, 0x3b, 0xf1, 0x81 }}

class NS_NO_VTABLE NS_SCRIPTABLE nsICommandHandlerInit : public nsISupports {
 public: 

  NS_DECLARE_STATIC_IID_ACCESSOR(NS_ICOMMANDHANDLERINIT_IID)

  /* attribute nsIDOMWindow window; */
  NS_SCRIPTABLE NS_IMETHOD GetWindow(nsIDOMWindow * *aWindow) = 0;
  NS_SCRIPTABLE NS_IMETHOD SetWindow(nsIDOMWindow * aWindow) = 0;

};

  NS_DEFINE_STATIC_IID_ACCESSOR(nsICommandHandlerInit, NS_ICOMMANDHANDLERINIT_IID)

/* Use this macro when declaring classes that implement this interface. */
#define NS_DECL_NSICOMMANDHANDLERINIT \
  NS_SCRIPTABLE NS_IMETHOD GetWindow(nsIDOMWindow * *aWindow); \
  NS_SCRIPTABLE NS_IMETHOD SetWindow(nsIDOMWindow * aWindow); 

/* Use this macro to declare functions that forward the behavior of this interface to another object. */
#define NS_FORWARD_NSICOMMANDHANDLERINIT(_to) \
  NS_SCRIPTABLE NS_IMETHOD GetWindow(nsIDOMWindow * *aWindow) { return _to GetWindow(aWindow); } \
  NS_SCRIPTABLE NS_IMETHOD SetWindow(nsIDOMWindow * aWindow) { return _to SetWindow(aWindow); } 

/* Use this macro to declare functions that forward the behavior of this interface to another object in a safe way. */
#define NS_FORWARD_SAFE_NSICOMMANDHANDLERINIT(_to) \
  NS_SCRIPTABLE NS_IMETHOD GetWindow(nsIDOMWindow * *aWindow) { return !_to ? NS_ERROR_NULL_POINTER : _to->GetWindow(aWindow); } \
  NS_SCRIPTABLE NS_IMETHOD SetWindow(nsIDOMWindow * aWindow) { return !_to ? NS_ERROR_NULL_POINTER : _to->SetWindow(aWindow); } 

#if 0
/* Use the code below as a template for the implementation class for this interface. */

/* Header file */
class nsCommandHandlerInit : public nsICommandHandlerInit
{
public:
  NS_DECL_ISUPPORTS
  NS_DECL_NSICOMMANDHANDLERINIT

  nsCommandHandlerInit();

private:
  ~nsCommandHandlerInit();

protected:
  /* additional members */
};

/* Implementation file */
NS_IMPL_ISUPPORTS1(nsCommandHandlerInit, nsICommandHandlerInit)

nsCommandHandlerInit::nsCommandHandlerInit()
{
  /* member initializers and constructor code */
}

nsCommandHandlerInit::~nsCommandHandlerInit()
{
  /* destructor code */
}

/* attribute nsIDOMWindow window; */
NS_IMETHODIMP nsCommandHandlerInit::GetWindow(nsIDOMWindow * *aWindow)
{
    return NS_ERROR_NOT_IMPLEMENTED;
}
NS_IMETHODIMP nsCommandHandlerInit::SetWindow(nsIDOMWindow * aWindow)
{
    return NS_ERROR_NOT_IMPLEMENTED;
}

/* End of implementation class template. */
#endif


/* starting interface:    nsICommandHandler */
#define NS_ICOMMANDHANDLER_IID_STR "34a4fcf0-66fc-11d4-9528-0020183bf181"

#define NS_ICOMMANDHANDLER_IID \
  {0x34a4fcf0, 0x66fc, 0x11d4, \
    { 0x95, 0x28, 0x00, 0x20, 0x18, 0x3b, 0xf1, 0x81 }}

class NS_NO_VTABLE NS_SCRIPTABLE nsICommandHandler : public nsISupports {
 public: 

  NS_DECLARE_STATIC_IID_ACCESSOR(NS_ICOMMANDHANDLER_IID)

  /* string exec (in string aCommand, in string aParameters); */
  NS_SCRIPTABLE NS_IMETHOD Exec(const char *aCommand, const char *aParameters, char **_retval NS_OUTPARAM) = 0;

  /* string query (in string aCommand, in string aParameters); */
  NS_SCRIPTABLE NS_IMETHOD Query(const char *aCommand, const char *aParameters, char **_retval NS_OUTPARAM) = 0;

};

  NS_DEFINE_STATIC_IID_ACCESSOR(nsICommandHandler, NS_ICOMMANDHANDLER_IID)

/* Use this macro when declaring classes that implement this interface. */
#define NS_DECL_NSICOMMANDHANDLER \
  NS_SCRIPTABLE NS_IMETHOD Exec(const char *aCommand, const char *aParameters, char **_retval NS_OUTPARAM); \
  NS_SCRIPTABLE NS_IMETHOD Query(const char *aCommand, const char *aParameters, char **_retval NS_OUTPARAM); 

/* Use this macro to declare functions that forward the behavior of this interface to another object. */
#define NS_FORWARD_NSICOMMANDHANDLER(_to) \
  NS_SCRIPTABLE NS_IMETHOD Exec(const char *aCommand, const char *aParameters, char **_retval NS_OUTPARAM) { return _to Exec(aCommand, aParameters, _retval); } \
  NS_SCRIPTABLE NS_IMETHOD Query(const char *aCommand, const char *aParameters, char **_retval NS_OUTPARAM) { return _to Query(aCommand, aParameters, _retval); } 

/* Use this macro to declare functions that forward the behavior of this interface to another object in a safe way. */
#define NS_FORWARD_SAFE_NSICOMMANDHANDLER(_to) \
  NS_SCRIPTABLE NS_IMETHOD Exec(const char *aCommand, const char *aParameters, char **_retval NS_OUTPARAM) { return !_to ? NS_ERROR_NULL_POINTER : _to->Exec(aCommand, aParameters, _retval); } \
  NS_SCRIPTABLE NS_IMETHOD Query(const char *aCommand, const char *aParameters, char **_retval NS_OUTPARAM) { return !_to ? NS_ERROR_NULL_POINTER : _to->Query(aCommand, aParameters, _retval); } 

#if 0
/* Use the code below as a template for the implementation class for this interface. */

/* Header file */
class nsCommandHandler : public nsICommandHandler
{
public:
  NS_DECL_ISUPPORTS
  NS_DECL_NSICOMMANDHANDLER

  nsCommandHandler();

private:
  ~nsCommandHandler();

protected:
  /* additional members */
};

/* Implementation file */
NS_IMPL_ISUPPORTS1(nsCommandHandler, nsICommandHandler)

nsCommandHandler::nsCommandHandler()
{
  /* member initializers and constructor code */
}

nsCommandHandler::~nsCommandHandler()
{
  /* destructor code */
}

/* string exec (in string aCommand, in string aParameters); */
NS_IMETHODIMP nsCommandHandler::Exec(const char *aCommand, const char *aParameters, char **_retval NS_OUTPARAM)
{
    return NS_ERROR_NOT_IMPLEMENTED;
}

/* string query (in string aCommand, in string aParameters); */
NS_IMETHODIMP nsCommandHandler::Query(const char *aCommand, const char *aParameters, char **_retval NS_OUTPARAM)
{
    return NS_ERROR_NOT_IMPLEMENTED;
}

/* End of implementation class template. */
#endif

//	{3A449110-66FD-11d4-9528-0020183BF181} - 
#define NS_COMMANDHANDLER_CID \
{ 0x3a449110, 0x66fd, 0x11d4, { 0x95, 0x28, 0x0, 0x20, 0x18, 0x3b, 0xf1, 0x81 } }
#define NS_COMMANDHANDLER_CONTRACTID \
"@mozilla.org/embedding/browser/nsCommandHandler;1"

#endif /* __gen_nsICommandHandler_h__ */
