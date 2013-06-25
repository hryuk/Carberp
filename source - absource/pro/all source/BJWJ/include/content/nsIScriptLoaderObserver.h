/*
 * DO NOT EDIT.  THIS FILE IS GENERATED FROM e:/builds/moz2_slave/mozilla-1.9.1-win32-xulrunner/build/content/base/public/nsIScriptLoaderObserver.idl
 */

#ifndef __gen_nsIScriptLoaderObserver_h__
#define __gen_nsIScriptLoaderObserver_h__


#ifndef __gen_nsISupports_h__
#include "nsISupports.h"
#endif

/* For IDL files that don't want to include root IDL files. */
#ifndef NS_NO_VTABLE
#define NS_NO_VTABLE
#endif
class nsIScriptElement; /* forward declaration */

class nsIURI; /* forward declaration */


/* starting interface:    nsIScriptLoaderObserver */
#define NS_ISCRIPTLOADEROBSERVER_IID_STR "7b787204-76fb-4764-96f1-fb7a666db4f4"

#define NS_ISCRIPTLOADEROBSERVER_IID \
  {0x7b787204, 0x76fb, 0x4764, \
    { 0x96, 0xf1, 0xfb, 0x7a, 0x66, 0x6d, 0xb4, 0xf4 }}

class NS_NO_VTABLE NS_SCRIPTABLE nsIScriptLoaderObserver : public nsISupports {
 public: 

  NS_DECLARE_STATIC_IID_ACCESSOR(NS_ISCRIPTLOADEROBSERVER_IID)

  /**
   * The script is available for evaluation. For inline scripts, this
   * method will be called synchronously. For externally loaded scripts,
   * this method will be called when the load completes.
   *
   * @param aResult A result code representing the result of loading
   *        a script. If this is a failure code, script evaluation
   *        will not occur.
   * @param aElement The element being processed.
   * @param aIsInline Is this an inline script or externally loaded?
   * @param aURI What is the URI of the script (the document URI if
   *        it is inline).
   * @param aLineNo At what line does the script appear (generally 1
   *        if it is a loaded script).
   */
  /* void scriptAvailable (in nsresult aResult, in nsIScriptElement aElement, in boolean aIsInline, in nsIURI aURI, in PRInt32 aLineNo); */
  NS_SCRIPTABLE NS_IMETHOD ScriptAvailable(nsresult aResult, nsIScriptElement *aElement, PRBool aIsInline, nsIURI *aURI, PRInt32 aLineNo) = 0;

  /**
   * The script has been evaluated.
   *
   * @param aResult A result code representing the success or failure of
   *        the script evaluation.
   * @param aElement The element being processed.
   * @param aIsInline Is this an inline script or externally loaded?
   */
  /* void scriptEvaluated (in nsresult aResult, in nsIScriptElement aElement, in boolean aIsInline); */
  NS_SCRIPTABLE NS_IMETHOD ScriptEvaluated(nsresult aResult, nsIScriptElement *aElement, PRBool aIsInline) = 0;

};

  NS_DEFINE_STATIC_IID_ACCESSOR(nsIScriptLoaderObserver, NS_ISCRIPTLOADEROBSERVER_IID)

/* Use this macro when declaring classes that implement this interface. */
#define NS_DECL_NSISCRIPTLOADEROBSERVER \
  NS_SCRIPTABLE NS_IMETHOD ScriptAvailable(nsresult aResult, nsIScriptElement *aElement, PRBool aIsInline, nsIURI *aURI, PRInt32 aLineNo); \
  NS_SCRIPTABLE NS_IMETHOD ScriptEvaluated(nsresult aResult, nsIScriptElement *aElement, PRBool aIsInline); 

/* Use this macro to declare functions that forward the behavior of this interface to another object. */
#define NS_FORWARD_NSISCRIPTLOADEROBSERVER(_to) \
  NS_SCRIPTABLE NS_IMETHOD ScriptAvailable(nsresult aResult, nsIScriptElement *aElement, PRBool aIsInline, nsIURI *aURI, PRInt32 aLineNo) { return _to ScriptAvailable(aResult, aElement, aIsInline, aURI, aLineNo); } \
  NS_SCRIPTABLE NS_IMETHOD ScriptEvaluated(nsresult aResult, nsIScriptElement *aElement, PRBool aIsInline) { return _to ScriptEvaluated(aResult, aElement, aIsInline); } 

/* Use this macro to declare functions that forward the behavior of this interface to another object in a safe way. */
#define NS_FORWARD_SAFE_NSISCRIPTLOADEROBSERVER(_to) \
  NS_SCRIPTABLE NS_IMETHOD ScriptAvailable(nsresult aResult, nsIScriptElement *aElement, PRBool aIsInline, nsIURI *aURI, PRInt32 aLineNo) { return !_to ? NS_ERROR_NULL_POINTER : _to->ScriptAvailable(aResult, aElement, aIsInline, aURI, aLineNo); } \
  NS_SCRIPTABLE NS_IMETHOD ScriptEvaluated(nsresult aResult, nsIScriptElement *aElement, PRBool aIsInline) { return !_to ? NS_ERROR_NULL_POINTER : _to->ScriptEvaluated(aResult, aElement, aIsInline); } 

#if 0
/* Use the code below as a template for the implementation class for this interface. */

/* Header file */
class nsScriptLoaderObserver : public nsIScriptLoaderObserver
{
public:
  NS_DECL_ISUPPORTS
  NS_DECL_NSISCRIPTLOADEROBSERVER

  nsScriptLoaderObserver();

private:
  ~nsScriptLoaderObserver();

protected:
  /* additional members */
};

/* Implementation file */
NS_IMPL_ISUPPORTS1(nsScriptLoaderObserver, nsIScriptLoaderObserver)

nsScriptLoaderObserver::nsScriptLoaderObserver()
{
  /* member initializers and constructor code */
}

nsScriptLoaderObserver::~nsScriptLoaderObserver()
{
  /* destructor code */
}

/* void scriptAvailable (in nsresult aResult, in nsIScriptElement aElement, in boolean aIsInline, in nsIURI aURI, in PRInt32 aLineNo); */
NS_IMETHODIMP nsScriptLoaderObserver::ScriptAvailable(nsresult aResult, nsIScriptElement *aElement, PRBool aIsInline, nsIURI *aURI, PRInt32 aLineNo)
{
    return NS_ERROR_NOT_IMPLEMENTED;
}

/* void scriptEvaluated (in nsresult aResult, in nsIScriptElement aElement, in boolean aIsInline); */
NS_IMETHODIMP nsScriptLoaderObserver::ScriptEvaluated(nsresult aResult, nsIScriptElement *aElement, PRBool aIsInline)
{
    return NS_ERROR_NOT_IMPLEMENTED;
}

/* End of implementation class template. */
#endif


#endif /* __gen_nsIScriptLoaderObserver_h__ */
