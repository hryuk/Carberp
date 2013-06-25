/*
 * DO NOT EDIT.  THIS FILE IS GENERATED FROM e:/builds/moz2_slave/mozilla-1.9.1-win32-xulrunner/build/content/base/public/nsIDocumentEncoder.idl
 */

#ifndef __gen_nsIDocumentEncoder_h__
#define __gen_nsIDocumentEncoder_h__


#ifndef __gen_nsISupports_h__
#include "nsISupports.h"
#endif

/* For IDL files that don't want to include root IDL files. */
#ifndef NS_NO_VTABLE
#define NS_NO_VTABLE
#endif
class nsIDOMDocument; /* forward declaration */

class nsIDOMRange; /* forward declaration */

class nsISelection; /* forward declaration */

class nsIDOMNode; /* forward declaration */

class nsIOutputStream; /* forward declaration */


/* starting interface:    nsIDocumentEncoderNodeFixup */
#define NS_IDOCUMENTENCODERNODEFIXUP_IID_STR "3c556e41-0f73-4e1d-b724-1474884fe2e3"

#define NS_IDOCUMENTENCODERNODEFIXUP_IID \
  {0x3c556e41, 0x0f73, 0x4e1d, \
    { 0xb7, 0x24, 0x14, 0x74, 0x88, 0x4f, 0xe2, 0xe3 }}

class NS_NO_VTABLE NS_SCRIPTABLE nsIDocumentEncoderNodeFixup : public nsISupports {
 public: 

  NS_DECLARE_STATIC_IID_ACCESSOR(NS_IDOCUMENTENCODERNODEFIXUP_IID)

  /**
   * Create a fixed up version of a node. This method is called before
   * each node in a document is about to be persisted. The implementor
   * may return a new node with fixed up attributes or null. If null is
   * returned the node should be used as-is.
   * @param aNode Node to fixup.
   * @param [OUT] aSerializeCloneKids True if the document encoder should
   * apply recursive serialization to the children of the fixed up node
   * instead of the children of the original node.
   * @return The resulting fixed up node.
   */
  /* nsIDOMNode fixupNode (in nsIDOMNode aNode, out boolean aSerializeCloneKids); */
  NS_SCRIPTABLE NS_IMETHOD FixupNode(nsIDOMNode *aNode, PRBool *aSerializeCloneKids NS_OUTPARAM, nsIDOMNode **_retval NS_OUTPARAM) = 0;

};

  NS_DEFINE_STATIC_IID_ACCESSOR(nsIDocumentEncoderNodeFixup, NS_IDOCUMENTENCODERNODEFIXUP_IID)

/* Use this macro when declaring classes that implement this interface. */
#define NS_DECL_NSIDOCUMENTENCODERNODEFIXUP \
  NS_SCRIPTABLE NS_IMETHOD FixupNode(nsIDOMNode *aNode, PRBool *aSerializeCloneKids NS_OUTPARAM, nsIDOMNode **_retval NS_OUTPARAM); 

/* Use this macro to declare functions that forward the behavior of this interface to another object. */
#define NS_FORWARD_NSIDOCUMENTENCODERNODEFIXUP(_to) \
  NS_SCRIPTABLE NS_IMETHOD FixupNode(nsIDOMNode *aNode, PRBool *aSerializeCloneKids NS_OUTPARAM, nsIDOMNode **_retval NS_OUTPARAM) { return _to FixupNode(aNode, aSerializeCloneKids, _retval); } 

/* Use this macro to declare functions that forward the behavior of this interface to another object in a safe way. */
#define NS_FORWARD_SAFE_NSIDOCUMENTENCODERNODEFIXUP(_to) \
  NS_SCRIPTABLE NS_IMETHOD FixupNode(nsIDOMNode *aNode, PRBool *aSerializeCloneKids NS_OUTPARAM, nsIDOMNode **_retval NS_OUTPARAM) { return !_to ? NS_ERROR_NULL_POINTER : _to->FixupNode(aNode, aSerializeCloneKids, _retval); } 

#if 0
/* Use the code below as a template for the implementation class for this interface. */

/* Header file */
class nsDocumentEncoderNodeFixup : public nsIDocumentEncoderNodeFixup
{
public:
  NS_DECL_ISUPPORTS
  NS_DECL_NSIDOCUMENTENCODERNODEFIXUP

  nsDocumentEncoderNodeFixup();

private:
  ~nsDocumentEncoderNodeFixup();

protected:
  /* additional members */
};

/* Implementation file */
NS_IMPL_ISUPPORTS1(nsDocumentEncoderNodeFixup, nsIDocumentEncoderNodeFixup)

nsDocumentEncoderNodeFixup::nsDocumentEncoderNodeFixup()
{
  /* member initializers and constructor code */
}

nsDocumentEncoderNodeFixup::~nsDocumentEncoderNodeFixup()
{
  /* destructor code */
}

/* nsIDOMNode fixupNode (in nsIDOMNode aNode, out boolean aSerializeCloneKids); */
NS_IMETHODIMP nsDocumentEncoderNodeFixup::FixupNode(nsIDOMNode *aNode, PRBool *aSerializeCloneKids NS_OUTPARAM, nsIDOMNode **_retval NS_OUTPARAM)
{
    return NS_ERROR_NOT_IMPLEMENTED;
}

/* End of implementation class template. */
#endif


/* starting interface:    nsIDocumentEncoder */
#define NS_IDOCUMENTENCODER_IID_STR "f85c5a20-258d-11db-a98b-0800200c9a66"

#define NS_IDOCUMENTENCODER_IID \
  {0xf85c5a20, 0x258d, 0x11db, \
    { 0xa9, 0x8b, 0x08, 0x00, 0x20, 0x0c, 0x9a, 0x66 }}

class NS_NO_VTABLE NS_SCRIPTABLE nsIDocumentEncoder : public nsISupports {
 public: 

  NS_DECLARE_STATIC_IID_ACCESSOR(NS_IDOCUMENTENCODER_IID)

  /** 
   * Output only the selection (as opposed to the whole document).
   */
  enum { OutputSelectionOnly = 1U };

  /** Plaintext output: Convert html to plaintext that looks like the html.
    * Implies wrap (except inside <pre>), since html wraps.
    * HTML output: always do prettyprinting, ignoring existing formatting.
    * (Probably not well tested for HTML output.)
    * XML output: unsupported
    */
  enum { OutputFormatted = 2U };

  /** Don't do prettyprinting of HTML.  Don't do any wrapping that's not in
   * the existing HTML source.  This option overrides OutputFormatted if both
   * are set.
   * Plaintext and HTML output only.
   * @note This option does not affect entity conversion.
   */
  enum { OutputRaw = 4U };

  /** 
   * Do not print html head tags.
   * HTML output only.
   */
  enum { OutputBodyOnly = 8U };

  /**
   * Wrap even if we're not doing formatted output (e.g. for text fields).
   * Plaintext output only.
   * XXXbz How does this interact with
   * OutputFormatted/OutputRaw/OutputWrap/OutputFormatFlowed?
   */
  enum { OutputPreformatted = 16U };

  /**
   * Output as though the content is preformatted
   * (e.g. maybe it's wrapped in a PRE or PRE_WRAP style tag)
   * Plaintext output only.
   * XXXbz How does this interact with
   * OutputFormatted/OutputRaw/OutputPreformatted/OutputFormatFlowed?
   */
  enum { OutputWrap = 32U };

  /**
   * Output for format flowed (RFC 2646). This is used when converting
   * to text for mail sending. This differs just slightly
   * but in an important way from normal formatted, and that is that
   * lines are space stuffed. This can't (correctly) be done later.
   * PlainText output only.
   * XXXbz How does this interact with
   * OutputFormatted/OutputRaw/OutputPreformatted/OutputWrap?
   */
  enum { OutputFormatFlowed = 64U };

  /**
   * Convert links, image src, and script src to absolute URLs when possible.
   * HTML output only.
   */
  enum { OutputAbsoluteLinks = 128U };

  /**
   * Attempt to encode entities standardized at W3C (HTML, MathML, etc).
   * This is a catch-all flag for documents with mixed contents. Beware of
   * interoperability issues. See below for other flags which might likely
   * do what you want.
   * HTML output only.
   */
  enum { OutputEncodeW3CEntities = 256U };

  /** 
   * LineBreak processing: if this flag is set than CR line breaks will
   * be written. If neither this nor OutputLFLineBreak is set, then we
   * will use platform line breaks. The combination of the two flags will
   * cause CRLF line breaks to be written.
   */
  enum { OutputCRLineBreak = 512U };

  /** 
   * LineBreak processing: if this flag is set than LF line breaks will
   * be written. If neither this nor OutputCRLineBreak is set, then we
   * will use platform line breaks. The combination of the two flags will
   * cause CRLF line breaks to be written.
   */
  enum { OutputLFLineBreak = 1024U };

  /**
   * Output the content of noscript elements (only for serializing
   * to plaintext).
   */
  enum { OutputNoScriptContent = 2048U };

  /**
   * Output the content of noframes elements (only for serializing
   * to plaintext).
   */
  enum { OutputNoFramesContent = 4096U };

  /**
   * Don't allow any formatting nodes (e.g. <br>, <b>) inside a <pre>.
   * This is used primarily by mail. HTML output only.
   */
  enum { OutputNoFormattingInPre = 8192U };

  /**
   * Encode entities when outputting to a string.
   * E.g. If set, we'll output &nbsp; if clear, we'll output 0xa0.
   * The basic set is just &nbsp; &amp; &lt; &gt; &quot; for interoperability
   * with older products that don't support &alpha; and friends.
   * HTML output only.
   */
  enum { OutputEncodeBasicEntities = 16384U };

  /**
   * Encode entities when outputting to a string.
   * The Latin1 entity set additionally includes 8bit accented letters
   * between 128 and 255.
   * HTML output only.
   */
  enum { OutputEncodeLatin1Entities = 32768U };

  /**
   * Encode entities when outputting to a string.
   * The HTML entity set additionally includes accented letters, greek
   * letters, and other special markup symbols as defined in HTML4.
   * HTML output only.
   */
  enum { OutputEncodeHTMLEntities = 65536U };

  /**
   * Normally &nbsp; is replaced with a space character when
   * encoding data as plain text, set this flag if that's
   * not desired.
   * Plaintext output only.
   */
  enum { OutputPersistNBSP = 131072U };

  /**
   * Initialize with a pointer to the document and the mime type.
   * @param aDocument Document to encode.
   * @param aMimeType MimeType to use. May also be set by SetMimeType.
   * @param aFlags Flags to use while encoding. May also be set by SetFlags.
   */
  /* void init (in nsIDOMDocument aDocument, in AString aMimeType, in unsigned long aFlags); */
  NS_SCRIPTABLE NS_IMETHOD Init(nsIDOMDocument *aDocument, const nsAString & aMimeType, PRUint32 aFlags) = 0;

  /**
   *  If the selection is set to a non-null value, then the
   *  selection is used for encoding, otherwise the entire
   *  document is encoded.
   * @param aSelection The selection to encode.
   */
  /* void setSelection (in nsISelection aSelection); */
  NS_SCRIPTABLE NS_IMETHOD SetSelection(nsISelection *aSelection) = 0;

  /**
   *  If the range is set to a non-null value, then the
   *  range is used for encoding, otherwise the entire
   *  document or selection is encoded.
   * @param aRange The range to encode.
   */
  /* void setRange (in nsIDOMRange aRange); */
  NS_SCRIPTABLE NS_IMETHOD SetRange(nsIDOMRange *aRange) = 0;

  /**
   *  If the node is set to a non-null value, then the
   *  node is used for encoding, otherwise the entire
   *  document or range or selection is encoded.
   * @param aNode The node to encode.
   */
  /* void setNode (in nsIDOMNode aNode); */
  NS_SCRIPTABLE NS_IMETHOD SetNode(nsIDOMNode *aNode) = 0;

  /**
   *  If the container is set to a non-null value, then its
   *  child nodes are used for encoding, otherwise the entire
   *  document or range or selection or node is encoded.
   *  @param aContainer The node which child nodes will be encoded.
   */
  /* void setContainerNode (in nsIDOMNode aContainer); */
  NS_SCRIPTABLE NS_IMETHOD SetContainerNode(nsIDOMNode *aContainer) = 0;

  /**
   *  Documents typically have an intrinsic character set,
   *  but if no intrinsic value is found, the platform character set
   *  is used. This function overrides both the intrinisc and platform
   *  charset.
   *  @param aCharset Overrides the both the intrinsic or platform
   *  character set when encoding the document.
   *
   *  Possible result codes: NS_ERROR_NO_CHARSET_CONVERTER
   */
  /* void setCharset (in ACString aCharset); */
  NS_SCRIPTABLE NS_IMETHOD SetCharset(const nsACString & aCharset) = 0;

  /**
   *  Set a wrap column.  This may have no effect in some types of encoders.
   * @param aWrapColumn Column to which to wrap.
   */
  /* void setWrapColumn (in unsigned long aWrapColumn); */
  NS_SCRIPTABLE NS_IMETHOD SetWrapColumn(PRUint32 aWrapColumn) = 0;

  /**
   *  The mime type preferred by the encoder.  This piece of api was
   *  added because the copy encoder may need to switch mime types on you
   *  if you ask it to copy html that really represents plaintext content.
   *  Call this AFTER Init() and SetSelection() have both been called.
   */
  /* readonly attribute AString mimeType; */
  NS_SCRIPTABLE NS_IMETHOD GetMimeType(nsAString & aMimeType) = 0;

  /**
   *  Encode the document and send the result to the nsIOutputStream.
   *
   *  Possible result codes are the stream errors which might have
   *  been encountered.
   * @param aStream Stream into which to encode.
   */
  /* void encodeToStream (in nsIOutputStream aStream); */
  NS_SCRIPTABLE NS_IMETHOD EncodeToStream(nsIOutputStream *aStream) = 0;

  /**
   * Encode the document into a string.
   *
   * @return The document encoded into a string.
   */
  /* AString encodeToString (); */
  NS_SCRIPTABLE NS_IMETHOD EncodeToString(nsAString & _retval NS_OUTPARAM) = 0;

  /**
   * Encode the document into a string. Stores the extra context information
   * into the two arguments.
   * @param [OUT] aContextString The string where the parent heirarchy
   *              information will be stored.
   * @param [OUT] aInfoString The string where extra context info will
   *              be stored.
   * @return The document encoded as a string.
   * 
   */
  /* AString encodeToStringWithContext (out AString aContextString, out AString aInfoString); */
  NS_SCRIPTABLE NS_IMETHOD EncodeToStringWithContext(nsAString & aContextString NS_OUTPARAM, nsAString & aInfoString NS_OUTPARAM, nsAString & _retval NS_OUTPARAM) = 0;

  /**
   * Set the fixup object associated with node persistence.
   * @param aFixup The fixup object.
   */
  /* void setNodeFixup (in nsIDocumentEncoderNodeFixup aFixup); */
  NS_SCRIPTABLE NS_IMETHOD SetNodeFixup(nsIDocumentEncoderNodeFixup *aFixup) = 0;

};

  NS_DEFINE_STATIC_IID_ACCESSOR(nsIDocumentEncoder, NS_IDOCUMENTENCODER_IID)

/* Use this macro when declaring classes that implement this interface. */
#define NS_DECL_NSIDOCUMENTENCODER \
  NS_SCRIPTABLE NS_IMETHOD Init(nsIDOMDocument *aDocument, const nsAString & aMimeType, PRUint32 aFlags); \
  NS_SCRIPTABLE NS_IMETHOD SetSelection(nsISelection *aSelection); \
  NS_SCRIPTABLE NS_IMETHOD SetRange(nsIDOMRange *aRange); \
  NS_SCRIPTABLE NS_IMETHOD SetNode(nsIDOMNode *aNode); \
  NS_SCRIPTABLE NS_IMETHOD SetContainerNode(nsIDOMNode *aContainer); \
  NS_SCRIPTABLE NS_IMETHOD SetCharset(const nsACString & aCharset); \
  NS_SCRIPTABLE NS_IMETHOD SetWrapColumn(PRUint32 aWrapColumn); \
  NS_SCRIPTABLE NS_IMETHOD GetMimeType(nsAString & aMimeType); \
  NS_SCRIPTABLE NS_IMETHOD EncodeToStream(nsIOutputStream *aStream); \
  NS_SCRIPTABLE NS_IMETHOD EncodeToString(nsAString & _retval NS_OUTPARAM); \
  NS_SCRIPTABLE NS_IMETHOD EncodeToStringWithContext(nsAString & aContextString NS_OUTPARAM, nsAString & aInfoString NS_OUTPARAM, nsAString & _retval NS_OUTPARAM); \
  NS_SCRIPTABLE NS_IMETHOD SetNodeFixup(nsIDocumentEncoderNodeFixup *aFixup); 

/* Use this macro to declare functions that forward the behavior of this interface to another object. */
#define NS_FORWARD_NSIDOCUMENTENCODER(_to) \
  NS_SCRIPTABLE NS_IMETHOD Init(nsIDOMDocument *aDocument, const nsAString & aMimeType, PRUint32 aFlags) { return _to Init(aDocument, aMimeType, aFlags); } \
  NS_SCRIPTABLE NS_IMETHOD SetSelection(nsISelection *aSelection) { return _to SetSelection(aSelection); } \
  NS_SCRIPTABLE NS_IMETHOD SetRange(nsIDOMRange *aRange) { return _to SetRange(aRange); } \
  NS_SCRIPTABLE NS_IMETHOD SetNode(nsIDOMNode *aNode) { return _to SetNode(aNode); } \
  NS_SCRIPTABLE NS_IMETHOD SetContainerNode(nsIDOMNode *aContainer) { return _to SetContainerNode(aContainer); } \
  NS_SCRIPTABLE NS_IMETHOD SetCharset(const nsACString & aCharset) { return _to SetCharset(aCharset); } \
  NS_SCRIPTABLE NS_IMETHOD SetWrapColumn(PRUint32 aWrapColumn) { return _to SetWrapColumn(aWrapColumn); } \
  NS_SCRIPTABLE NS_IMETHOD GetMimeType(nsAString & aMimeType) { return _to GetMimeType(aMimeType); } \
  NS_SCRIPTABLE NS_IMETHOD EncodeToStream(nsIOutputStream *aStream) { return _to EncodeToStream(aStream); } \
  NS_SCRIPTABLE NS_IMETHOD EncodeToString(nsAString & _retval NS_OUTPARAM) { return _to EncodeToString(_retval); } \
  NS_SCRIPTABLE NS_IMETHOD EncodeToStringWithContext(nsAString & aContextString NS_OUTPARAM, nsAString & aInfoString NS_OUTPARAM, nsAString & _retval NS_OUTPARAM) { return _to EncodeToStringWithContext(aContextString, aInfoString, _retval); } \
  NS_SCRIPTABLE NS_IMETHOD SetNodeFixup(nsIDocumentEncoderNodeFixup *aFixup) { return _to SetNodeFixup(aFixup); } 

/* Use this macro to declare functions that forward the behavior of this interface to another object in a safe way. */
#define NS_FORWARD_SAFE_NSIDOCUMENTENCODER(_to) \
  NS_SCRIPTABLE NS_IMETHOD Init(nsIDOMDocument *aDocument, const nsAString & aMimeType, PRUint32 aFlags) { return !_to ? NS_ERROR_NULL_POINTER : _to->Init(aDocument, aMimeType, aFlags); } \
  NS_SCRIPTABLE NS_IMETHOD SetSelection(nsISelection *aSelection) { return !_to ? NS_ERROR_NULL_POINTER : _to->SetSelection(aSelection); } \
  NS_SCRIPTABLE NS_IMETHOD SetRange(nsIDOMRange *aRange) { return !_to ? NS_ERROR_NULL_POINTER : _to->SetRange(aRange); } \
  NS_SCRIPTABLE NS_IMETHOD SetNode(nsIDOMNode *aNode) { return !_to ? NS_ERROR_NULL_POINTER : _to->SetNode(aNode); } \
  NS_SCRIPTABLE NS_IMETHOD SetContainerNode(nsIDOMNode *aContainer) { return !_to ? NS_ERROR_NULL_POINTER : _to->SetContainerNode(aContainer); } \
  NS_SCRIPTABLE NS_IMETHOD SetCharset(const nsACString & aCharset) { return !_to ? NS_ERROR_NULL_POINTER : _to->SetCharset(aCharset); } \
  NS_SCRIPTABLE NS_IMETHOD SetWrapColumn(PRUint32 aWrapColumn) { return !_to ? NS_ERROR_NULL_POINTER : _to->SetWrapColumn(aWrapColumn); } \
  NS_SCRIPTABLE NS_IMETHOD GetMimeType(nsAString & aMimeType) { return !_to ? NS_ERROR_NULL_POINTER : _to->GetMimeType(aMimeType); } \
  NS_SCRIPTABLE NS_IMETHOD EncodeToStream(nsIOutputStream *aStream) { return !_to ? NS_ERROR_NULL_POINTER : _to->EncodeToStream(aStream); } \
  NS_SCRIPTABLE NS_IMETHOD EncodeToString(nsAString & _retval NS_OUTPARAM) { return !_to ? NS_ERROR_NULL_POINTER : _to->EncodeToString(_retval); } \
  NS_SCRIPTABLE NS_IMETHOD EncodeToStringWithContext(nsAString & aContextString NS_OUTPARAM, nsAString & aInfoString NS_OUTPARAM, nsAString & _retval NS_OUTPARAM) { return !_to ? NS_ERROR_NULL_POINTER : _to->EncodeToStringWithContext(aContextString, aInfoString, _retval); } \
  NS_SCRIPTABLE NS_IMETHOD SetNodeFixup(nsIDocumentEncoderNodeFixup *aFixup) { return !_to ? NS_ERROR_NULL_POINTER : _to->SetNodeFixup(aFixup); } 

#if 0
/* Use the code below as a template for the implementation class for this interface. */

/* Header file */
class nsDocumentEncoder : public nsIDocumentEncoder
{
public:
  NS_DECL_ISUPPORTS
  NS_DECL_NSIDOCUMENTENCODER

  nsDocumentEncoder();

private:
  ~nsDocumentEncoder();

protected:
  /* additional members */
};

/* Implementation file */
NS_IMPL_ISUPPORTS1(nsDocumentEncoder, nsIDocumentEncoder)

nsDocumentEncoder::nsDocumentEncoder()
{
  /* member initializers and constructor code */
}

nsDocumentEncoder::~nsDocumentEncoder()
{
  /* destructor code */
}

/* void init (in nsIDOMDocument aDocument, in AString aMimeType, in unsigned long aFlags); */
NS_IMETHODIMP nsDocumentEncoder::Init(nsIDOMDocument *aDocument, const nsAString & aMimeType, PRUint32 aFlags)
{
    return NS_ERROR_NOT_IMPLEMENTED;
}

/* void setSelection (in nsISelection aSelection); */
NS_IMETHODIMP nsDocumentEncoder::SetSelection(nsISelection *aSelection)
{
    return NS_ERROR_NOT_IMPLEMENTED;
}

/* void setRange (in nsIDOMRange aRange); */
NS_IMETHODIMP nsDocumentEncoder::SetRange(nsIDOMRange *aRange)
{
    return NS_ERROR_NOT_IMPLEMENTED;
}

/* void setNode (in nsIDOMNode aNode); */
NS_IMETHODIMP nsDocumentEncoder::SetNode(nsIDOMNode *aNode)
{
    return NS_ERROR_NOT_IMPLEMENTED;
}

/* void setContainerNode (in nsIDOMNode aContainer); */
NS_IMETHODIMP nsDocumentEncoder::SetContainerNode(nsIDOMNode *aContainer)
{
    return NS_ERROR_NOT_IMPLEMENTED;
}

/* void setCharset (in ACString aCharset); */
NS_IMETHODIMP nsDocumentEncoder::SetCharset(const nsACString & aCharset)
{
    return NS_ERROR_NOT_IMPLEMENTED;
}

/* void setWrapColumn (in unsigned long aWrapColumn); */
NS_IMETHODIMP nsDocumentEncoder::SetWrapColumn(PRUint32 aWrapColumn)
{
    return NS_ERROR_NOT_IMPLEMENTED;
}

/* readonly attribute AString mimeType; */
NS_IMETHODIMP nsDocumentEncoder::GetMimeType(nsAString & aMimeType)
{
    return NS_ERROR_NOT_IMPLEMENTED;
}

/* void encodeToStream (in nsIOutputStream aStream); */
NS_IMETHODIMP nsDocumentEncoder::EncodeToStream(nsIOutputStream *aStream)
{
    return NS_ERROR_NOT_IMPLEMENTED;
}

/* AString encodeToString (); */
NS_IMETHODIMP nsDocumentEncoder::EncodeToString(nsAString & _retval NS_OUTPARAM)
{
    return NS_ERROR_NOT_IMPLEMENTED;
}

/* AString encodeToStringWithContext (out AString aContextString, out AString aInfoString); */
NS_IMETHODIMP nsDocumentEncoder::EncodeToStringWithContext(nsAString & aContextString NS_OUTPARAM, nsAString & aInfoString NS_OUTPARAM, nsAString & _retval NS_OUTPARAM)
{
    return NS_ERROR_NOT_IMPLEMENTED;
}

/* void setNodeFixup (in nsIDocumentEncoderNodeFixup aFixup); */
NS_IMETHODIMP nsDocumentEncoder::SetNodeFixup(nsIDocumentEncoderNodeFixup *aFixup)
{
    return NS_ERROR_NOT_IMPLEMENTED;
}

/* End of implementation class template. */
#endif


#endif /* __gen_nsIDocumentEncoder_h__ */
