/*
 * DO NOT EDIT.  THIS FILE IS GENERATED FROM e:/builds/moz2_slave/mozilla-1.9.1-win32-xulrunner/build/netwerk/base/public/nsIContentSniffer.idl
 */

#ifndef __gen_nsIContentSniffer_h__
#define __gen_nsIContentSniffer_h__


#ifndef __gen_nsISupports_h__
#include "nsISupports.h"
#endif

/* For IDL files that don't want to include root IDL files. */
#ifndef NS_NO_VTABLE
#define NS_NO_VTABLE
#endif
class nsIRequest; /* forward declaration */


/* starting interface:    nsIContentSniffer */
#define NS_ICONTENTSNIFFER_IID_STR "a5772d1b-fc63-495e-a169-96e8d3311af0"

#define NS_ICONTENTSNIFFER_IID \
  {0xa5772d1b, 0xfc63, 0x495e, \
    { 0xa1, 0x69, 0x96, 0xe8, 0xd3, 0x31, 0x1a, 0xf0 }}

/**
 * Content sniffer interface. Components implementing this interface can
 * determine a MIME type from a chunk of bytes.
 */
class NS_NO_VTABLE NS_SCRIPTABLE nsIContentSniffer : public nsISupports {
 public: 

  NS_DECLARE_STATIC_IID_ACCESSOR(NS_ICONTENTSNIFFER_IID)

  /**
   * Given a chunk of data, determines a MIME type. Information from the given
   * request may be used in order to make a better decision.
   *
   * @param aRequest The request where this data came from. May be null.
   * @param aData Data to check
   * @param aLength Length of the data
   *
   * @return The content type
   *
   * @throw NS_ERROR_NOT_AVAILABLE if no MIME type could be determined.
   *
   * @note Implementations should consider the request read-only. Especially,
   * they should not attempt to set the content type property that subclasses of
   * nsIRequest might offer.
   */
  /* ACString getMIMETypeFromContent (in nsIRequest aRequest, [array, size_is (aLength), const] in octet aData, in unsigned long aLength); */
  NS_SCRIPTABLE NS_IMETHOD GetMIMETypeFromContent(nsIRequest *aRequest, const PRUint8 *aData, PRUint32 aLength, nsACString & _retval NS_OUTPARAM) = 0;

};

  NS_DEFINE_STATIC_IID_ACCESSOR(nsIContentSniffer, NS_ICONTENTSNIFFER_IID)

/* Use this macro when declaring classes that implement this interface. */
#define NS_DECL_NSICONTENTSNIFFER \
  NS_SCRIPTABLE NS_IMETHOD GetMIMETypeFromContent(nsIRequest *aRequest, const PRUint8 *aData, PRUint32 aLength, nsACString & _retval NS_OUTPARAM); 

/* Use this macro to declare functions that forward the behavior of this interface to another object. */
#define NS_FORWARD_NSICONTENTSNIFFER(_to) \
  NS_SCRIPTABLE NS_IMETHOD GetMIMETypeFromContent(nsIRequest *aRequest, const PRUint8 *aData, PRUint32 aLength, nsACString & _retval NS_OUTPARAM) { return _to GetMIMETypeFromContent(aRequest, aData, aLength, _retval); } 

/* Use this macro to declare functions that forward the behavior of this interface to another object in a safe way. */
#define NS_FORWARD_SAFE_NSICONTENTSNIFFER(_to) \
  NS_SCRIPTABLE NS_IMETHOD GetMIMETypeFromContent(nsIRequest *aRequest, const PRUint8 *aData, PRUint32 aLength, nsACString & _retval NS_OUTPARAM) { return !_to ? NS_ERROR_NULL_POINTER : _to->GetMIMETypeFromContent(aRequest, aData, aLength, _retval); } 

#if 0
/* Use the code below as a template for the implementation class for this interface. */

/* Header file */
class nsContentSniffer : public nsIContentSniffer
{
public:
  NS_DECL_ISUPPORTS
  NS_DECL_NSICONTENTSNIFFER

  nsContentSniffer();

private:
  ~nsContentSniffer();

protected:
  /* additional members */
};

/* Implementation file */
NS_IMPL_ISUPPORTS1(nsContentSniffer, nsIContentSniffer)

nsContentSniffer::nsContentSniffer()
{
  /* member initializers and constructor code */
}

nsContentSniffer::~nsContentSniffer()
{
  /* destructor code */
}

/* ACString getMIMETypeFromContent (in nsIRequest aRequest, [array, size_is (aLength), const] in octet aData, in unsigned long aLength); */
NS_IMETHODIMP nsContentSniffer::GetMIMETypeFromContent(nsIRequest *aRequest, const PRUint8 *aData, PRUint32 aLength, nsACString & _retval NS_OUTPARAM)
{
    return NS_ERROR_NOT_IMPLEMENTED;
}

/* End of implementation class template. */
#endif


#endif /* __gen_nsIContentSniffer_h__ */
