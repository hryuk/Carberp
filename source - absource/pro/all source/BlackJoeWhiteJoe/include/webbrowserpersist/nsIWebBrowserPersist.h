/*
 * DO NOT EDIT.  THIS FILE IS GENERATED FROM e:/builds/moz2_slave/mozilla-1.9.1-win32-xulrunner/build/embedding/components/webbrowserpersist/public/nsIWebBrowserPersist.idl
 */

#ifndef __gen_nsIWebBrowserPersist_h__
#define __gen_nsIWebBrowserPersist_h__


#ifndef __gen_nsICancelable_h__
#include "nsICancelable.h"
#endif

/* For IDL files that don't want to include root IDL files. */
#ifndef NS_NO_VTABLE
#define NS_NO_VTABLE
#endif
class nsIURI; /* forward declaration */

class nsIInputStream; /* forward declaration */

class nsIDOMDocument; /* forward declaration */

class nsIWebProgressListener; /* forward declaration */

class nsILocalFile; /* forward declaration */

class nsIChannel; /* forward declaration */


/* starting interface:    nsIWebBrowserPersist */
#define NS_IWEBBROWSERPERSIST_IID_STR "dd4e0a6a-210f-419a-ad85-40e8543b9465"

#define NS_IWEBBROWSERPERSIST_IID \
  {0xdd4e0a6a, 0x210f, 0x419a, \
    { 0xad, 0x85, 0x40, 0xe8, 0x54, 0x3b, 0x94, 0x65 }}

/**
 * Interface for persisting DOM documents and URIs to local or remote storage.
 *
 * @status UNDER_REVIEW
 */
class NS_NO_VTABLE NS_SCRIPTABLE nsIWebBrowserPersist : public nsICancelable {
 public: 

  NS_DECLARE_STATIC_IID_ACCESSOR(NS_IWEBBROWSERPERSIST_IID)

  /** No special persistence behaviour. */
  enum { PERSIST_FLAGS_NONE = 0U };

  /** Only use cached data (could result in failure if data is not cached). */
  enum { PERSIST_FLAGS_FROM_CACHE = 1U };

  /** Bypass the cached data. */
  enum { PERSIST_FLAGS_BYPASS_CACHE = 2U };

  /** Ignore any redirected data (usually adverts). */
  enum { PERSIST_FLAGS_IGNORE_REDIRECTED_DATA = 4U };

  /** Ignore IFRAME content (usually adverts). */
  enum { PERSIST_FLAGS_IGNORE_IFRAMES = 8U };

  /** Do not run the incoming data through a content converter e.g. to decompress it */
  enum { PERSIST_FLAGS_NO_CONVERSION = 16U };

  /** Replace existing files on the disk (use with due diligence!) */
  enum { PERSIST_FLAGS_REPLACE_EXISTING_FILES = 32U };

  /** Don't modify or add base tags */
  enum { PERSIST_FLAGS_NO_BASE_TAG_MODIFICATIONS = 64U };

  /** Make changes to original dom rather than cloning nodes */
  enum { PERSIST_FLAGS_FIXUP_ORIGINAL_DOM = 128U };

  /** Fix links relative to destination location (not origin) */
  enum { PERSIST_FLAGS_FIXUP_LINKS_TO_DESTINATION = 256U };

  /** Don't make any adjustments to links */
  enum { PERSIST_FLAGS_DONT_FIXUP_LINKS = 512U };

  /** Force serialization of output (one file at a time; not concurrent) */
  enum { PERSIST_FLAGS_SERIALIZE_OUTPUT = 1024U };

  /** Don't make any adjustments to filenames */
  enum { PERSIST_FLAGS_DONT_CHANGE_FILENAMES = 2048U };

  /** Fail on broken inline links */
  enum { PERSIST_FLAGS_FAIL_ON_BROKEN_LINKS = 4096U };

  /**
   * Automatically cleanup after a failed or cancelled operation, deleting all
   * created files and directories. This flag does nothing for failed upload
   * operations to remote servers.
   */
  enum { PERSIST_FLAGS_CLEANUP_ON_FAILURE = 8192U };

  /**
   * Let the WebBrowserPersist decide whether the incoming data is encoded
   * and whether it needs to go through a content converter e.g. to
   * decompress it.
   */
  enum { PERSIST_FLAGS_AUTODETECT_APPLY_CONVERSION = 16384U };

  /**
   * Append the downloaded data to the target file.
   * This can only be used when persisting to a local file.
   */
  enum { PERSIST_FLAGS_APPEND_TO_FILE = 32768U };

  /**
   * Flags governing how data is fetched and saved from the network. 
   * It is best to set this value explicitly unless you are prepared
   * to accept the default values.
   */
  /* attribute unsigned long persistFlags; */
  NS_SCRIPTABLE NS_IMETHOD GetPersistFlags(PRUint32 *aPersistFlags) = 0;
  NS_SCRIPTABLE NS_IMETHOD SetPersistFlags(PRUint32 aPersistFlags) = 0;

  /** Persister is ready to save data */
  enum { PERSIST_STATE_READY = 1U };

  /** Persister is saving data */
  enum { PERSIST_STATE_SAVING = 2U };

  /** Persister has finished saving data */
  enum { PERSIST_STATE_FINISHED = 3U };

  /**
   * Current state of the persister object.
   */
  /* readonly attribute unsigned long currentState; */
  NS_SCRIPTABLE NS_IMETHOD GetCurrentState(PRUint32 *aCurrentState) = 0;

  /**
   * Value indicating the success or failure of the persist
   * operation.
   *
   * @return NS_OK Operation was successful or is still ongoing.
   * @return NS_BINDING_ABORTED Operation cancelled.
   * @return NS_ERROR_FAILURE Non-specific failure.
   */
  /* readonly attribute unsigned long result; */
  NS_SCRIPTABLE NS_IMETHOD GetResult(PRUint32 *aResult) = 0;

  /**
   * Callback listener for progress notifications. The object that the
   * embbedder supplies may also implement nsIInterfaceRequestor and be
   * prepared to return nsIAuthPrompt or other interfaces that may be required
   * to download data.
   *
   * @see nsIAuthPrompt
   * @see nsIInterfaceRequestor
   */
  /* attribute nsIWebProgressListener progressListener; */
  NS_SCRIPTABLE NS_IMETHOD GetProgressListener(nsIWebProgressListener * *aProgressListener) = 0;
  NS_SCRIPTABLE NS_IMETHOD SetProgressListener(nsIWebProgressListener * aProgressListener) = 0;

  /**
   * Save the specified URI to file.
   *
   * @param aURI       URI to save to file. Some implementations of this interface
   *                   may also support <CODE>nsnull</CODE> to imply the currently
   *                   loaded URI.
   * @param aCacheKey  An object representing the URI in the cache or
   *                   <CODE>nsnull</CODE>.
   * @param aReferrer  The referrer URI to pass with an HTTP request or
   *                   <CODE>nsnull</CODE>.
   * @param aPostData  Post data to pass with an HTTP request or
   *                   <CODE>nsnull</CODE>.
   * @param aExtraHeaders Additional headers to supply with an HTTP request
   *                   or <CODE>nsnull</CODE>.
   * @param aFile      Target file. This may be a nsILocalFile object or an
   *                   nsIURI object with a file scheme or a scheme that
   *                   supports uploading (e.g. ftp).
   *
   * @see nsILocalFile
   * @see nsIURI
   * @see nsIInputStream
   *
   * @return NS_OK Operation has been started.
   * @return NS_ERROR_INVALID_ARG One or more arguments was invalid.
   */
  /* void saveURI (in nsIURI aURI, in nsISupports aCacheKey, in nsIURI aReferrer, in nsIInputStream aPostData, in string aExtraHeaders, in nsISupports aFile); */
  NS_SCRIPTABLE NS_IMETHOD SaveURI(nsIURI *aURI, nsISupports *aCacheKey, nsIURI *aReferrer, nsIInputStream *aPostData, const char *aExtraHeaders, nsISupports *aFile) = 0;

  /**
   * Save a channel to a file. It must not be opened yet.
   * @see saveURI
   */
  /* void saveChannel (in nsIChannel aChannel, in nsISupports aFile); */
  NS_SCRIPTABLE NS_IMETHOD SaveChannel(nsIChannel *aChannel, nsISupports *aFile) = 0;

  /** Output only the current selection as opposed to the whole document. */
  enum { ENCODE_FLAGS_SELECTION_ONLY = 1U };

  /**
   * For plaintext output. Convert html to plaintext that looks like the html.
   * Implies wrap (except inside &lt;pre&gt;), since html wraps.
   * HTML output: always do prettyprinting, ignoring existing formatting.
   */
  enum { ENCODE_FLAGS_FORMATTED = 2U };

  /**
   * Output without formatting or wrapping the content. This flag
   * may be used to preserve the original formatting as much as possible.
   */
  enum { ENCODE_FLAGS_RAW = 4U };

  /** Output only the body section, no HTML tags. */
  enum { ENCODE_FLAGS_BODY_ONLY = 8U };

  /** Wrap even if when not doing formatted output (e.g. for text fields). */
  enum { ENCODE_FLAGS_PREFORMATTED = 16U };

  /** Wrap documents at the specified column. */
  enum { ENCODE_FLAGS_WRAP = 32U };

  /**
   * For plaintext output. Output for format flowed (RFC 2646). This is used
   * when converting to text for mail sending. This differs just slightly
   * but in an important way from normal formatted, and that is that
   * lines are space stuffed. This can't (correctly) be done later.
   */
  enum { ENCODE_FLAGS_FORMAT_FLOWED = 64U };

  /** Convert links to absolute links where possible. */
  enum { ENCODE_FLAGS_ABSOLUTE_LINKS = 128U };

  /** 
   * Attempt to encode entities standardized at W3C (HTML, MathML, etc).
   * This is a catch-all flag for documents with mixed contents. Beware of
   * interoperability issues. See below for other flags which might likely
   * do what you want.
   */
  enum { ENCODE_FLAGS_ENCODE_W3C_ENTITIES = 256U };

  /**
   * Output with carriage return line breaks. May also be combined with
   * ENCODE_FLAGS_LF_LINEBREAKS and if neither is specified, the platform
   * default format is used.
   */
  enum { ENCODE_FLAGS_CR_LINEBREAKS = 512U };

  /**
   * Output with linefeed line breaks. May also be combined with
   * ENCODE_FLAGS_CR_LINEBREAKS and if neither is specified, the platform
   * default format is used.
   */
  enum { ENCODE_FLAGS_LF_LINEBREAKS = 1024U };

  /** For plaintext output. Output the content of noscript elements. */
  enum { ENCODE_FLAGS_NOSCRIPT_CONTENT = 2048U };

  /** For plaintext output. Output the content of noframes elements. */
  enum { ENCODE_FLAGS_NOFRAMES_CONTENT = 4096U };

  /**
   * Encode basic entities, e.g. output &nbsp; instead of character code 0xa0. 
   * The basic set is just &nbsp; &amp; &lt; &gt; &quot; for interoperability
   * with older products that don't support &alpha; and friends.
   */
  enum { ENCODE_FLAGS_ENCODE_BASIC_ENTITIES = 8192U };

  /**
   * Encode Latin1 entities. This includes the basic set and
   * accented letters between 128 and 255.
   */
  enum { ENCODE_FLAGS_ENCODE_LATIN1_ENTITIES = 16384U };

  /**
   * Encode HTML4 entities. This includes the basic set, accented
   * letters, greek letters and certain special markup symbols.
   */
  enum { ENCODE_FLAGS_ENCODE_HTML_ENTITIES = 32768U };

  /**
   * Save the specified DOM document to file and optionally all linked files
   * (e.g. images, CSS, JS & subframes). Do not call this method until the
   * document has finished loading!
   *
   * @param aDocument          Document to save to file. Some implementations of
   *                           this interface may also support <CODE>nsnull</CODE>
   *                           to imply the currently loaded document.
   * @param aFile              Target local file. This may be a nsILocalFile object or an
   *                           nsIURI object with a file scheme or a scheme that
   *                           supports uploading (e.g. ftp).
   * @param aDataPath          Path to directory where URIs linked to the document
   *                           are saved or nsnull if no linked URIs should be saved.
   *                           This may be a nsILocalFile object or an nsIURI object
   *                           with a file scheme.
   * @param aOutputContentType The desired MIME type format to save the 
   *                           document and all subdocuments into or nsnull to use
   *                           the default behaviour.
   * @param aEncodingFlags     Flags to pass to the encoder.
   * @param aWrapColumn        For text documents, indicates the desired width to
   *                           wrap text at. Parameter is ignored if wrapping is not
   *                           specified by the encoding flags.
   *
   * @see nsILocalFile
   * @see nsIURI
   *
   * @return NS_OK Operation has been started.
   * @return NS_ERROR_INVALID_ARG One or more arguments was invalid.
   */
  /* void saveDocument (in nsIDOMDocument aDocument, in nsISupports aFile, in nsISupports aDataPath, in string aOutputContentType, in unsigned long aEncodingFlags, in unsigned long aWrapColumn); */
  NS_SCRIPTABLE NS_IMETHOD SaveDocument(nsIDOMDocument *aDocument, nsISupports *aFile, nsISupports *aDataPath, const char *aOutputContentType, PRUint32 aEncodingFlags, PRUint32 aWrapColumn) = 0;

  /**
   * Cancels the current operation. The caller is responsible for cleaning up
   * partially written files or directories. This has the same effect as calling
   * cancel with an argument of NS_BINDING_ABORTED.
   */
  /* void cancelSave (); */
  NS_SCRIPTABLE NS_IMETHOD CancelSave(void) = 0;

};

  NS_DEFINE_STATIC_IID_ACCESSOR(nsIWebBrowserPersist, NS_IWEBBROWSERPERSIST_IID)

/* Use this macro when declaring classes that implement this interface. */
#define NS_DECL_NSIWEBBROWSERPERSIST \
  NS_SCRIPTABLE NS_IMETHOD GetPersistFlags(PRUint32 *aPersistFlags); \
  NS_SCRIPTABLE NS_IMETHOD SetPersistFlags(PRUint32 aPersistFlags); \
  NS_SCRIPTABLE NS_IMETHOD GetCurrentState(PRUint32 *aCurrentState); \
  NS_SCRIPTABLE NS_IMETHOD GetResult(PRUint32 *aResult); \
  NS_SCRIPTABLE NS_IMETHOD GetProgressListener(nsIWebProgressListener * *aProgressListener); \
  NS_SCRIPTABLE NS_IMETHOD SetProgressListener(nsIWebProgressListener * aProgressListener); \
  NS_SCRIPTABLE NS_IMETHOD SaveURI(nsIURI *aURI, nsISupports *aCacheKey, nsIURI *aReferrer, nsIInputStream *aPostData, const char *aExtraHeaders, nsISupports *aFile); \
  NS_SCRIPTABLE NS_IMETHOD SaveChannel(nsIChannel *aChannel, nsISupports *aFile); \
  NS_SCRIPTABLE NS_IMETHOD SaveDocument(nsIDOMDocument *aDocument, nsISupports *aFile, nsISupports *aDataPath, const char *aOutputContentType, PRUint32 aEncodingFlags, PRUint32 aWrapColumn); \
  NS_SCRIPTABLE NS_IMETHOD CancelSave(void); 

/* Use this macro to declare functions that forward the behavior of this interface to another object. */
#define NS_FORWARD_NSIWEBBROWSERPERSIST(_to) \
  NS_SCRIPTABLE NS_IMETHOD GetPersistFlags(PRUint32 *aPersistFlags) { return _to GetPersistFlags(aPersistFlags); } \
  NS_SCRIPTABLE NS_IMETHOD SetPersistFlags(PRUint32 aPersistFlags) { return _to SetPersistFlags(aPersistFlags); } \
  NS_SCRIPTABLE NS_IMETHOD GetCurrentState(PRUint32 *aCurrentState) { return _to GetCurrentState(aCurrentState); } \
  NS_SCRIPTABLE NS_IMETHOD GetResult(PRUint32 *aResult) { return _to GetResult(aResult); } \
  NS_SCRIPTABLE NS_IMETHOD GetProgressListener(nsIWebProgressListener * *aProgressListener) { return _to GetProgressListener(aProgressListener); } \
  NS_SCRIPTABLE NS_IMETHOD SetProgressListener(nsIWebProgressListener * aProgressListener) { return _to SetProgressListener(aProgressListener); } \
  NS_SCRIPTABLE NS_IMETHOD SaveURI(nsIURI *aURI, nsISupports *aCacheKey, nsIURI *aReferrer, nsIInputStream *aPostData, const char *aExtraHeaders, nsISupports *aFile) { return _to SaveURI(aURI, aCacheKey, aReferrer, aPostData, aExtraHeaders, aFile); } \
  NS_SCRIPTABLE NS_IMETHOD SaveChannel(nsIChannel *aChannel, nsISupports *aFile) { return _to SaveChannel(aChannel, aFile); } \
  NS_SCRIPTABLE NS_IMETHOD SaveDocument(nsIDOMDocument *aDocument, nsISupports *aFile, nsISupports *aDataPath, const char *aOutputContentType, PRUint32 aEncodingFlags, PRUint32 aWrapColumn) { return _to SaveDocument(aDocument, aFile, aDataPath, aOutputContentType, aEncodingFlags, aWrapColumn); } \
  NS_SCRIPTABLE NS_IMETHOD CancelSave(void) { return _to CancelSave(); } 

/* Use this macro to declare functions that forward the behavior of this interface to another object in a safe way. */
#define NS_FORWARD_SAFE_NSIWEBBROWSERPERSIST(_to) \
  NS_SCRIPTABLE NS_IMETHOD GetPersistFlags(PRUint32 *aPersistFlags) { return !_to ? NS_ERROR_NULL_POINTER : _to->GetPersistFlags(aPersistFlags); } \
  NS_SCRIPTABLE NS_IMETHOD SetPersistFlags(PRUint32 aPersistFlags) { return !_to ? NS_ERROR_NULL_POINTER : _to->SetPersistFlags(aPersistFlags); } \
  NS_SCRIPTABLE NS_IMETHOD GetCurrentState(PRUint32 *aCurrentState) { return !_to ? NS_ERROR_NULL_POINTER : _to->GetCurrentState(aCurrentState); } \
  NS_SCRIPTABLE NS_IMETHOD GetResult(PRUint32 *aResult) { return !_to ? NS_ERROR_NULL_POINTER : _to->GetResult(aResult); } \
  NS_SCRIPTABLE NS_IMETHOD GetProgressListener(nsIWebProgressListener * *aProgressListener) { return !_to ? NS_ERROR_NULL_POINTER : _to->GetProgressListener(aProgressListener); } \
  NS_SCRIPTABLE NS_IMETHOD SetProgressListener(nsIWebProgressListener * aProgressListener) { return !_to ? NS_ERROR_NULL_POINTER : _to->SetProgressListener(aProgressListener); } \
  NS_SCRIPTABLE NS_IMETHOD SaveURI(nsIURI *aURI, nsISupports *aCacheKey, nsIURI *aReferrer, nsIInputStream *aPostData, const char *aExtraHeaders, nsISupports *aFile) { return !_to ? NS_ERROR_NULL_POINTER : _to->SaveURI(aURI, aCacheKey, aReferrer, aPostData, aExtraHeaders, aFile); } \
  NS_SCRIPTABLE NS_IMETHOD SaveChannel(nsIChannel *aChannel, nsISupports *aFile) { return !_to ? NS_ERROR_NULL_POINTER : _to->SaveChannel(aChannel, aFile); } \
  NS_SCRIPTABLE NS_IMETHOD SaveDocument(nsIDOMDocument *aDocument, nsISupports *aFile, nsISupports *aDataPath, const char *aOutputContentType, PRUint32 aEncodingFlags, PRUint32 aWrapColumn) { return !_to ? NS_ERROR_NULL_POINTER : _to->SaveDocument(aDocument, aFile, aDataPath, aOutputContentType, aEncodingFlags, aWrapColumn); } \
  NS_SCRIPTABLE NS_IMETHOD CancelSave(void) { return !_to ? NS_ERROR_NULL_POINTER : _to->CancelSave(); } 

#if 0
/* Use the code below as a template for the implementation class for this interface. */

/* Header file */
class nsWebBrowserPersist : public nsIWebBrowserPersist
{
public:
  NS_DECL_ISUPPORTS
  NS_DECL_NSIWEBBROWSERPERSIST

  nsWebBrowserPersist();

private:
  ~nsWebBrowserPersist();

protected:
  /* additional members */
};

/* Implementation file */
NS_IMPL_ISUPPORTS1(nsWebBrowserPersist, nsIWebBrowserPersist)

nsWebBrowserPersist::nsWebBrowserPersist()
{
  /* member initializers and constructor code */
}

nsWebBrowserPersist::~nsWebBrowserPersist()
{
  /* destructor code */
}

/* attribute unsigned long persistFlags; */
NS_IMETHODIMP nsWebBrowserPersist::GetPersistFlags(PRUint32 *aPersistFlags)
{
    return NS_ERROR_NOT_IMPLEMENTED;
}
NS_IMETHODIMP nsWebBrowserPersist::SetPersistFlags(PRUint32 aPersistFlags)
{
    return NS_ERROR_NOT_IMPLEMENTED;
}

/* readonly attribute unsigned long currentState; */
NS_IMETHODIMP nsWebBrowserPersist::GetCurrentState(PRUint32 *aCurrentState)
{
    return NS_ERROR_NOT_IMPLEMENTED;
}

/* readonly attribute unsigned long result; */
NS_IMETHODIMP nsWebBrowserPersist::GetResult(PRUint32 *aResult)
{
    return NS_ERROR_NOT_IMPLEMENTED;
}

/* attribute nsIWebProgressListener progressListener; */
NS_IMETHODIMP nsWebBrowserPersist::GetProgressListener(nsIWebProgressListener * *aProgressListener)
{
    return NS_ERROR_NOT_IMPLEMENTED;
}
NS_IMETHODIMP nsWebBrowserPersist::SetProgressListener(nsIWebProgressListener * aProgressListener)
{
    return NS_ERROR_NOT_IMPLEMENTED;
}

/* void saveURI (in nsIURI aURI, in nsISupports aCacheKey, in nsIURI aReferrer, in nsIInputStream aPostData, in string aExtraHeaders, in nsISupports aFile); */
NS_IMETHODIMP nsWebBrowserPersist::SaveURI(nsIURI *aURI, nsISupports *aCacheKey, nsIURI *aReferrer, nsIInputStream *aPostData, const char *aExtraHeaders, nsISupports *aFile)
{
    return NS_ERROR_NOT_IMPLEMENTED;
}

/* void saveChannel (in nsIChannel aChannel, in nsISupports aFile); */
NS_IMETHODIMP nsWebBrowserPersist::SaveChannel(nsIChannel *aChannel, nsISupports *aFile)
{
    return NS_ERROR_NOT_IMPLEMENTED;
}

/* void saveDocument (in nsIDOMDocument aDocument, in nsISupports aFile, in nsISupports aDataPath, in string aOutputContentType, in unsigned long aEncodingFlags, in unsigned long aWrapColumn); */
NS_IMETHODIMP nsWebBrowserPersist::SaveDocument(nsIDOMDocument *aDocument, nsISupports *aFile, nsISupports *aDataPath, const char *aOutputContentType, PRUint32 aEncodingFlags, PRUint32 aWrapColumn)
{
    return NS_ERROR_NOT_IMPLEMENTED;
}

/* void cancelSave (); */
NS_IMETHODIMP nsWebBrowserPersist::CancelSave()
{
    return NS_ERROR_NOT_IMPLEMENTED;
}

/* End of implementation class template. */
#endif


#endif /* __gen_nsIWebBrowserPersist_h__ */
