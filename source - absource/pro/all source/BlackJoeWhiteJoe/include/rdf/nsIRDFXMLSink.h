/*
 * DO NOT EDIT.  THIS FILE IS GENERATED FROM e:/builds/moz2_slave/mozilla-1.9.1-win32-xulrunner/build/rdf/base/idl/nsIRDFXMLSink.idl
 */

#ifndef __gen_nsIRDFXMLSink_h__
#define __gen_nsIRDFXMLSink_h__


#ifndef __gen_nsISupports_h__
#include "nsISupports.h"
#endif

/* For IDL files that don't want to include root IDL files. */
#ifndef NS_NO_VTABLE
#define NS_NO_VTABLE
#endif
class nsIAtom;
class nsString;
class nsIRDFXMLSink; /* forward declaration */


/* starting interface:    nsIRDFXMLSinkObserver */
#define NS_IRDFXMLSINKOBSERVER_IID_STR "eb1a5d30-ab33-11d2-8ec6-00805f29f370"

#define NS_IRDFXMLSINKOBSERVER_IID \
  {0xeb1a5d30, 0xab33, 0x11d2, \
    { 0x8e, 0xc6, 0x00, 0x80, 0x5f, 0x29, 0xf3, 0x70 }}

/**
 * An observer that is notified as progress is made on the load
 * of an RDF/XML document in an <code>nsIRDFXMLSink</code>.
 */
class NS_NO_VTABLE NS_SCRIPTABLE nsIRDFXMLSinkObserver : public nsISupports {
 public: 

  NS_DECLARE_STATIC_IID_ACCESSOR(NS_IRDFXMLSINKOBSERVER_IID)

  /**
     * Called when the load begins.
     * @param aSink the RDF/XML sink on which the load is beginning.
     */
  /* void onBeginLoad (in nsIRDFXMLSink aSink); */
  NS_SCRIPTABLE NS_IMETHOD OnBeginLoad(nsIRDFXMLSink *aSink) = 0;

  /**
     * Called when the load is suspended (e.g., for network quantization).
     * @param aSink the RDF/XML sink that is being interrupted.
     */
  /* void onInterrupt (in nsIRDFXMLSink aSink); */
  NS_SCRIPTABLE NS_IMETHOD OnInterrupt(nsIRDFXMLSink *aSink) = 0;

  /**
     * Called when a suspended load is resuming.
     * @param aSink the RDF/XML sink that is resuming.
     */
  /* void onResume (in nsIRDFXMLSink aSink); */
  NS_SCRIPTABLE NS_IMETHOD OnResume(nsIRDFXMLSink *aSink) = 0;

  /**
     * Called when an RDF/XML load completes successfully.
     * @param aSink the RDF/XML sink that has finished loading.
     */
  /* void onEndLoad (in nsIRDFXMLSink aSink); */
  NS_SCRIPTABLE NS_IMETHOD OnEndLoad(nsIRDFXMLSink *aSink) = 0;

  /**
     * Called when an error occurs during the load
     * @param aSink the RDF/XML sink in which the error occurred
     * @param aStatus the networking result code
     * @param aErrorMsg an error message, if applicable
     */
  /* void onError (in nsIRDFXMLSink aSink, in nsresult aStatus, in wstring aErrorMsg); */
  NS_SCRIPTABLE NS_IMETHOD OnError(nsIRDFXMLSink *aSink, nsresult aStatus, const PRUnichar *aErrorMsg) = 0;

};

  NS_DEFINE_STATIC_IID_ACCESSOR(nsIRDFXMLSinkObserver, NS_IRDFXMLSINKOBSERVER_IID)

/* Use this macro when declaring classes that implement this interface. */
#define NS_DECL_NSIRDFXMLSINKOBSERVER \
  NS_SCRIPTABLE NS_IMETHOD OnBeginLoad(nsIRDFXMLSink *aSink); \
  NS_SCRIPTABLE NS_IMETHOD OnInterrupt(nsIRDFXMLSink *aSink); \
  NS_SCRIPTABLE NS_IMETHOD OnResume(nsIRDFXMLSink *aSink); \
  NS_SCRIPTABLE NS_IMETHOD OnEndLoad(nsIRDFXMLSink *aSink); \
  NS_SCRIPTABLE NS_IMETHOD OnError(nsIRDFXMLSink *aSink, nsresult aStatus, const PRUnichar *aErrorMsg); 

/* Use this macro to declare functions that forward the behavior of this interface to another object. */
#define NS_FORWARD_NSIRDFXMLSINKOBSERVER(_to) \
  NS_SCRIPTABLE NS_IMETHOD OnBeginLoad(nsIRDFXMLSink *aSink) { return _to OnBeginLoad(aSink); } \
  NS_SCRIPTABLE NS_IMETHOD OnInterrupt(nsIRDFXMLSink *aSink) { return _to OnInterrupt(aSink); } \
  NS_SCRIPTABLE NS_IMETHOD OnResume(nsIRDFXMLSink *aSink) { return _to OnResume(aSink); } \
  NS_SCRIPTABLE NS_IMETHOD OnEndLoad(nsIRDFXMLSink *aSink) { return _to OnEndLoad(aSink); } \
  NS_SCRIPTABLE NS_IMETHOD OnError(nsIRDFXMLSink *aSink, nsresult aStatus, const PRUnichar *aErrorMsg) { return _to OnError(aSink, aStatus, aErrorMsg); } 

/* Use this macro to declare functions that forward the behavior of this interface to another object in a safe way. */
#define NS_FORWARD_SAFE_NSIRDFXMLSINKOBSERVER(_to) \
  NS_SCRIPTABLE NS_IMETHOD OnBeginLoad(nsIRDFXMLSink *aSink) { return !_to ? NS_ERROR_NULL_POINTER : _to->OnBeginLoad(aSink); } \
  NS_SCRIPTABLE NS_IMETHOD OnInterrupt(nsIRDFXMLSink *aSink) { return !_to ? NS_ERROR_NULL_POINTER : _to->OnInterrupt(aSink); } \
  NS_SCRIPTABLE NS_IMETHOD OnResume(nsIRDFXMLSink *aSink) { return !_to ? NS_ERROR_NULL_POINTER : _to->OnResume(aSink); } \
  NS_SCRIPTABLE NS_IMETHOD OnEndLoad(nsIRDFXMLSink *aSink) { return !_to ? NS_ERROR_NULL_POINTER : _to->OnEndLoad(aSink); } \
  NS_SCRIPTABLE NS_IMETHOD OnError(nsIRDFXMLSink *aSink, nsresult aStatus, const PRUnichar *aErrorMsg) { return !_to ? NS_ERROR_NULL_POINTER : _to->OnError(aSink, aStatus, aErrorMsg); } 

#if 0
/* Use the code below as a template for the implementation class for this interface. */

/* Header file */
class nsRDFXMLSinkObserver : public nsIRDFXMLSinkObserver
{
public:
  NS_DECL_ISUPPORTS
  NS_DECL_NSIRDFXMLSINKOBSERVER

  nsRDFXMLSinkObserver();

private:
  ~nsRDFXMLSinkObserver();

protected:
  /* additional members */
};

/* Implementation file */
NS_IMPL_ISUPPORTS1(nsRDFXMLSinkObserver, nsIRDFXMLSinkObserver)

nsRDFXMLSinkObserver::nsRDFXMLSinkObserver()
{
  /* member initializers and constructor code */
}

nsRDFXMLSinkObserver::~nsRDFXMLSinkObserver()
{
  /* destructor code */
}

/* void onBeginLoad (in nsIRDFXMLSink aSink); */
NS_IMETHODIMP nsRDFXMLSinkObserver::OnBeginLoad(nsIRDFXMLSink *aSink)
{
    return NS_ERROR_NOT_IMPLEMENTED;
}

/* void onInterrupt (in nsIRDFXMLSink aSink); */
NS_IMETHODIMP nsRDFXMLSinkObserver::OnInterrupt(nsIRDFXMLSink *aSink)
{
    return NS_ERROR_NOT_IMPLEMENTED;
}

/* void onResume (in nsIRDFXMLSink aSink); */
NS_IMETHODIMP nsRDFXMLSinkObserver::OnResume(nsIRDFXMLSink *aSink)
{
    return NS_ERROR_NOT_IMPLEMENTED;
}

/* void onEndLoad (in nsIRDFXMLSink aSink); */
NS_IMETHODIMP nsRDFXMLSinkObserver::OnEndLoad(nsIRDFXMLSink *aSink)
{
    return NS_ERROR_NOT_IMPLEMENTED;
}

/* void onError (in nsIRDFXMLSink aSink, in nsresult aStatus, in wstring aErrorMsg); */
NS_IMETHODIMP nsRDFXMLSinkObserver::OnError(nsIRDFXMLSink *aSink, nsresult aStatus, const PRUnichar *aErrorMsg)
{
    return NS_ERROR_NOT_IMPLEMENTED;
}

/* End of implementation class template. */
#endif


/* starting interface:    nsIRDFXMLSink */
#define NS_IRDFXMLSINK_IID_STR "eb1a5d31-ab33-11d2-8ec6-00805f29f370"

#define NS_IRDFXMLSINK_IID \
  {0xeb1a5d31, 0xab33, 0x11d2, \
    { 0x8e, 0xc6, 0x00, 0x80, 0x5f, 0x29, 0xf3, 0x70 }}

class NS_NO_VTABLE NS_SCRIPTABLE nsIRDFXMLSink : public nsISupports {
 public: 

  NS_DECLARE_STATIC_IID_ACCESSOR(NS_IRDFXMLSINK_IID)

  /**
 * A "sink" that receives and processes RDF/XML. This interface is used
 * by the RDF/XML parser.
 */
/**
     * Set to <code>true</code> if the sink is read-only and cannot
     * be modified
     */
  /* attribute boolean readOnly; */
  NS_SCRIPTABLE NS_IMETHOD GetReadOnly(PRBool *aReadOnly) = 0;
  NS_SCRIPTABLE NS_IMETHOD SetReadOnly(PRBool aReadOnly) = 0;

  /**
     * Initiate the RDF/XML load.
     */
  /* void beginLoad (); */
  NS_SCRIPTABLE NS_IMETHOD BeginLoad(void) = 0;

  /**
     * Suspend the RDF/XML load.
     */
  /* void interrupt (); */
  NS_SCRIPTABLE NS_IMETHOD Interrupt(void) = 0;

  /**
     * Resume the RDF/XML load.
     */
  /* void resume (); */
  NS_SCRIPTABLE NS_IMETHOD Resume(void) = 0;

  /**
     * Complete the RDF/XML load.
     */
  /* void endLoad (); */
  NS_SCRIPTABLE NS_IMETHOD EndLoad(void) = 0;

  /**
     * Add namespace information to the RDF/XML sink.
     * @param aPrefix the namespace prefix
     * @param aURI the namespace URI
     */
  /* [noscript] void addNameSpace (in nsIAtomPtr aPrefix, [const] in nsStringRef aURI); */
  NS_IMETHOD AddNameSpace(nsIAtom * aPrefix, const nsString & aURI) = 0;

  /**
     * Add an observer that will be notified as the RDF/XML load
     * progresses.
     * <p>
     *
     * Note that the sink will acquire a strong reference to the
     * observer, so care should be taken to avoid cyclical references
     * that cannot be released (i.e., if the observer holds a
     * reference to the sink, it should be sure that it eventually
     * clears the reference).
     *
     * @param aObserver the observer to add to the sink's set of
     * load observers.
     */
  /* void addXMLSinkObserver (in nsIRDFXMLSinkObserver aObserver); */
  NS_SCRIPTABLE NS_IMETHOD AddXMLSinkObserver(nsIRDFXMLSinkObserver *aObserver) = 0;

  /**
     * Remove an observer from the sink's set of observers.
     * @param aObserver the observer to remove.
     */
  /* void removeXMLSinkObserver (in nsIRDFXMLSinkObserver aObserver); */
  NS_SCRIPTABLE NS_IMETHOD RemoveXMLSinkObserver(nsIRDFXMLSinkObserver *aObserver) = 0;

};

  NS_DEFINE_STATIC_IID_ACCESSOR(nsIRDFXMLSink, NS_IRDFXMLSINK_IID)

/* Use this macro when declaring classes that implement this interface. */
#define NS_DECL_NSIRDFXMLSINK \
  NS_SCRIPTABLE NS_IMETHOD GetReadOnly(PRBool *aReadOnly); \
  NS_SCRIPTABLE NS_IMETHOD SetReadOnly(PRBool aReadOnly); \
  NS_SCRIPTABLE NS_IMETHOD BeginLoad(void); \
  NS_SCRIPTABLE NS_IMETHOD Interrupt(void); \
  NS_SCRIPTABLE NS_IMETHOD Resume(void); \
  NS_SCRIPTABLE NS_IMETHOD EndLoad(void); \
  NS_IMETHOD AddNameSpace(nsIAtom * aPrefix, const nsString & aURI); \
  NS_SCRIPTABLE NS_IMETHOD AddXMLSinkObserver(nsIRDFXMLSinkObserver *aObserver); \
  NS_SCRIPTABLE NS_IMETHOD RemoveXMLSinkObserver(nsIRDFXMLSinkObserver *aObserver); 

/* Use this macro to declare functions that forward the behavior of this interface to another object. */
#define NS_FORWARD_NSIRDFXMLSINK(_to) \
  NS_SCRIPTABLE NS_IMETHOD GetReadOnly(PRBool *aReadOnly) { return _to GetReadOnly(aReadOnly); } \
  NS_SCRIPTABLE NS_IMETHOD SetReadOnly(PRBool aReadOnly) { return _to SetReadOnly(aReadOnly); } \
  NS_SCRIPTABLE NS_IMETHOD BeginLoad(void) { return _to BeginLoad(); } \
  NS_SCRIPTABLE NS_IMETHOD Interrupt(void) { return _to Interrupt(); } \
  NS_SCRIPTABLE NS_IMETHOD Resume(void) { return _to Resume(); } \
  NS_SCRIPTABLE NS_IMETHOD EndLoad(void) { return _to EndLoad(); } \
  NS_IMETHOD AddNameSpace(nsIAtom * aPrefix, const nsString & aURI) { return _to AddNameSpace(aPrefix, aURI); } \
  NS_SCRIPTABLE NS_IMETHOD AddXMLSinkObserver(nsIRDFXMLSinkObserver *aObserver) { return _to AddXMLSinkObserver(aObserver); } \
  NS_SCRIPTABLE NS_IMETHOD RemoveXMLSinkObserver(nsIRDFXMLSinkObserver *aObserver) { return _to RemoveXMLSinkObserver(aObserver); } 

/* Use this macro to declare functions that forward the behavior of this interface to another object in a safe way. */
#define NS_FORWARD_SAFE_NSIRDFXMLSINK(_to) \
  NS_SCRIPTABLE NS_IMETHOD GetReadOnly(PRBool *aReadOnly) { return !_to ? NS_ERROR_NULL_POINTER : _to->GetReadOnly(aReadOnly); } \
  NS_SCRIPTABLE NS_IMETHOD SetReadOnly(PRBool aReadOnly) { return !_to ? NS_ERROR_NULL_POINTER : _to->SetReadOnly(aReadOnly); } \
  NS_SCRIPTABLE NS_IMETHOD BeginLoad(void) { return !_to ? NS_ERROR_NULL_POINTER : _to->BeginLoad(); } \
  NS_SCRIPTABLE NS_IMETHOD Interrupt(void) { return !_to ? NS_ERROR_NULL_POINTER : _to->Interrupt(); } \
  NS_SCRIPTABLE NS_IMETHOD Resume(void) { return !_to ? NS_ERROR_NULL_POINTER : _to->Resume(); } \
  NS_SCRIPTABLE NS_IMETHOD EndLoad(void) { return !_to ? NS_ERROR_NULL_POINTER : _to->EndLoad(); } \
  NS_IMETHOD AddNameSpace(nsIAtom * aPrefix, const nsString & aURI) { return !_to ? NS_ERROR_NULL_POINTER : _to->AddNameSpace(aPrefix, aURI); } \
  NS_SCRIPTABLE NS_IMETHOD AddXMLSinkObserver(nsIRDFXMLSinkObserver *aObserver) { return !_to ? NS_ERROR_NULL_POINTER : _to->AddXMLSinkObserver(aObserver); } \
  NS_SCRIPTABLE NS_IMETHOD RemoveXMLSinkObserver(nsIRDFXMLSinkObserver *aObserver) { return !_to ? NS_ERROR_NULL_POINTER : _to->RemoveXMLSinkObserver(aObserver); } 

#if 0
/* Use the code below as a template for the implementation class for this interface. */

/* Header file */
class nsRDFXMLSink : public nsIRDFXMLSink
{
public:
  NS_DECL_ISUPPORTS
  NS_DECL_NSIRDFXMLSINK

  nsRDFXMLSink();

private:
  ~nsRDFXMLSink();

protected:
  /* additional members */
};

/* Implementation file */
NS_IMPL_ISUPPORTS1(nsRDFXMLSink, nsIRDFXMLSink)

nsRDFXMLSink::nsRDFXMLSink()
{
  /* member initializers and constructor code */
}

nsRDFXMLSink::~nsRDFXMLSink()
{
  /* destructor code */
}

/* attribute boolean readOnly; */
NS_IMETHODIMP nsRDFXMLSink::GetReadOnly(PRBool *aReadOnly)
{
    return NS_ERROR_NOT_IMPLEMENTED;
}
NS_IMETHODIMP nsRDFXMLSink::SetReadOnly(PRBool aReadOnly)
{
    return NS_ERROR_NOT_IMPLEMENTED;
}

/* void beginLoad (); */
NS_IMETHODIMP nsRDFXMLSink::BeginLoad()
{
    return NS_ERROR_NOT_IMPLEMENTED;
}

/* void interrupt (); */
NS_IMETHODIMP nsRDFXMLSink::Interrupt()
{
    return NS_ERROR_NOT_IMPLEMENTED;
}

/* void resume (); */
NS_IMETHODIMP nsRDFXMLSink::Resume()
{
    return NS_ERROR_NOT_IMPLEMENTED;
}

/* void endLoad (); */
NS_IMETHODIMP nsRDFXMLSink::EndLoad()
{
    return NS_ERROR_NOT_IMPLEMENTED;
}

/* [noscript] void addNameSpace (in nsIAtomPtr aPrefix, [const] in nsStringRef aURI); */
NS_IMETHODIMP nsRDFXMLSink::AddNameSpace(nsIAtom * aPrefix, const nsString & aURI)
{
    return NS_ERROR_NOT_IMPLEMENTED;
}

/* void addXMLSinkObserver (in nsIRDFXMLSinkObserver aObserver); */
NS_IMETHODIMP nsRDFXMLSink::AddXMLSinkObserver(nsIRDFXMLSinkObserver *aObserver)
{
    return NS_ERROR_NOT_IMPLEMENTED;
}

/* void removeXMLSinkObserver (in nsIRDFXMLSinkObserver aObserver); */
NS_IMETHODIMP nsRDFXMLSink::RemoveXMLSinkObserver(nsIRDFXMLSinkObserver *aObserver)
{
    return NS_ERROR_NOT_IMPLEMENTED;
}

/* End of implementation class template. */
#endif


#endif /* __gen_nsIRDFXMLSink_h__ */
