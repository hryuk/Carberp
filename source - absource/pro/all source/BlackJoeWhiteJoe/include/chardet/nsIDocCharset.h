/*
 * DO NOT EDIT.  THIS FILE IS GENERATED FROM e:/builds/moz2_slave/mozilla-1.9.1-win32-xulrunner/build/intl/chardet/public/nsIDocCharset.idl
 */

#ifndef __gen_nsIDocCharset_h__
#define __gen_nsIDocCharset_h__


#ifndef __gen_nsISupports_h__
#include "nsISupports.h"
#endif

/* For IDL files that don't want to include root IDL files. */
#ifndef NS_NO_VTABLE
#define NS_NO_VTABLE
#endif

/* starting interface:    nsIDocCharset */
#define NS_IDOCCHARSET_IID_STR "9c18bb4e-1dd1-11b2-bf91-9cc82c275823"

#define NS_IDOCCHARSET_IID \
  {0x9c18bb4e, 0x1dd1, 0x11b2, \
    { 0xbf, 0x91, 0x9c, 0xc8, 0x2c, 0x27, 0x58, 0x23 }}

/**
 * The nsIDocCharset interface allows the user to view, 
 * hint, and set which converter is used to read the document's 
 * data.
 *
 * <P>Inside Mozilla all text is encoded as Unicode. By standardizing  
 * on Unicode every piece of code that handles characters no longer 
 * needs to: 
 *
 *     Have access to a character encoding parameter.
 *     Ask is the data stateful?
 *     Ask is the data single byte?
 *     Ask is the data multi-byte?
 *     If multi-byte: have access to a routine that can
 *         determine how many bytes in the current character.
 *
 * When the document is read in a converter is used to convert 
 * the document's data to Unicode.
 *
 * nsIDocCharset provides the ability to:
 *
 *   See what converter was used when inputting the documents
 *   data.
 *
 *   Override the character set for documents where the specified 
 *   fallback, or auto-detected character set is incorrect
 *
 */
class NS_NO_VTABLE NS_SCRIPTABLE nsIDocCharset : public nsISupports {
 public: 

  NS_DECLARE_STATIC_IID_ACCESSOR(NS_IDOCCHARSET_IID)

  /**
     * Get/sets the encoding (converter) used to read the 
     * document. Get returns the encoding used. Set forces 
     * (overrides) the encoding. After forcing the charset the 
     * embedding application will need to cause the data to be 
     * reparsed in order to update the DOM / display.
     *
     * A force also sets the fallback encoding for this frame.
     */
  /* attribute string charset; */
  NS_SCRIPTABLE NS_IMETHOD GetCharset(char * *aCharset) = 0;
  NS_SCRIPTABLE NS_IMETHOD SetCharset(const char * aCharset) = 0;

};

  NS_DEFINE_STATIC_IID_ACCESSOR(nsIDocCharset, NS_IDOCCHARSET_IID)

/* Use this macro when declaring classes that implement this interface. */
#define NS_DECL_NSIDOCCHARSET \
  NS_SCRIPTABLE NS_IMETHOD GetCharset(char * *aCharset); \
  NS_SCRIPTABLE NS_IMETHOD SetCharset(const char * aCharset); 

/* Use this macro to declare functions that forward the behavior of this interface to another object. */
#define NS_FORWARD_NSIDOCCHARSET(_to) \
  NS_SCRIPTABLE NS_IMETHOD GetCharset(char * *aCharset) { return _to GetCharset(aCharset); } \
  NS_SCRIPTABLE NS_IMETHOD SetCharset(const char * aCharset) { return _to SetCharset(aCharset); } 

/* Use this macro to declare functions that forward the behavior of this interface to another object in a safe way. */
#define NS_FORWARD_SAFE_NSIDOCCHARSET(_to) \
  NS_SCRIPTABLE NS_IMETHOD GetCharset(char * *aCharset) { return !_to ? NS_ERROR_NULL_POINTER : _to->GetCharset(aCharset); } \
  NS_SCRIPTABLE NS_IMETHOD SetCharset(const char * aCharset) { return !_to ? NS_ERROR_NULL_POINTER : _to->SetCharset(aCharset); } 

#if 0
/* Use the code below as a template for the implementation class for this interface. */

/* Header file */
class nsDocCharset : public nsIDocCharset
{
public:
  NS_DECL_ISUPPORTS
  NS_DECL_NSIDOCCHARSET

  nsDocCharset();

private:
  ~nsDocCharset();

protected:
  /* additional members */
};

/* Implementation file */
NS_IMPL_ISUPPORTS1(nsDocCharset, nsIDocCharset)

nsDocCharset::nsDocCharset()
{
  /* member initializers and constructor code */
}

nsDocCharset::~nsDocCharset()
{
  /* destructor code */
}

/* attribute string charset; */
NS_IMETHODIMP nsDocCharset::GetCharset(char * *aCharset)
{
    return NS_ERROR_NOT_IMPLEMENTED;
}
NS_IMETHODIMP nsDocCharset::SetCharset(const char * aCharset)
{
    return NS_ERROR_NOT_IMPLEMENTED;
}

/* End of implementation class template. */
#endif


#endif /* __gen_nsIDocCharset_h__ */
