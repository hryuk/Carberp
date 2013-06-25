/*
 * DO NOT EDIT.  THIS FILE IS GENERATED FROM e:/builds/moz2_slave/mozilla-1.9.1-win32-xulrunner/build/editor/idl/nsIEditorIMESupport.idl
 */

#ifndef __gen_nsIEditorIMESupport_h__
#define __gen_nsIEditorIMESupport_h__


#ifndef __gen_nsISupports_h__
#include "nsISupports.h"
#endif

#ifndef __gen_domstubs_h__
#include "domstubs.h"
#endif

/* For IDL files that don't want to include root IDL files. */
#ifndef NS_NO_VTABLE
#define NS_NO_VTABLE
#endif
class nsIPrivateTextRangeList;
struct nsTextEventReply;

/* starting interface:    nsIEditorIMESupport */
#define NS_IEDITORIMESUPPORT_IID_STR "57032dcb-e8c7-4eb6-8ec6-a0f8e300809d"

#define NS_IEDITORIMESUPPORT_IID \
  {0x57032dcb, 0xe8c7, 0x4eb6, \
    { 0x8e, 0xc6, 0xa0, 0xf8, 0xe3, 0x00, 0x80, 0x9d }}

class NS_NO_VTABLE NS_SCRIPTABLE nsIEditorIMESupport : public nsISupports {
 public: 

  NS_DECLARE_STATIC_IID_ACCESSOR(NS_IEDITORIMESUPPORT_IID)

  /**
   * beginComposition(nsTextEventReply* aReply) Handles the start of inline input composition.
   */
  /* [noscript] void beginComposition (in nsTextEventReplyPtr aReply); */
  NS_IMETHOD BeginComposition(nsTextEventReply * aReply) = 0;

  /**
   * setCompositionString() Sets the inline input composition string.
   * beginComposition must be called prior to this.
   */
  /* [noscript] void setCompositionString (in DOMString aCompositionString, in nsIPrivateTextRangeListPtr aTextRange, in nsTextEventReplyPtr aReply); */
  NS_IMETHOD SetCompositionString(const nsAString & aCompositionString, nsIPrivateTextRangeList * aTextRange, nsTextEventReply * aReply) = 0;

  /**
   * endComposition() Handles the end of inline input composition.
   */
  /* void endComposition (); */
  NS_SCRIPTABLE NS_IMETHOD EndComposition(void) = 0;

  /**
   * queryComposition()  Get the composition position
   */
  /* [noscript] void queryComposition (in nsTextEventReplyPtr aReply); */
  NS_IMETHOD QueryComposition(nsTextEventReply * aReply) = 0;

  /**
   * forceCompositionEnd() force the composition end
   */
  /* void forceCompositionEnd (); */
  NS_SCRIPTABLE NS_IMETHOD ForceCompositionEnd(void) = 0;

  /**
   * Get preferred IME status of current widget.
   */
  /* [noscript] void getPreferredIMEState (out unsigned long aState); */
  NS_IMETHOD GetPreferredIMEState(PRUint32 *aState NS_OUTPARAM) = 0;

  /**
   * whether this editor has active IME transaction
   */
  /* readonly attribute boolean composing; */
  NS_SCRIPTABLE NS_IMETHOD GetComposing(PRBool *aComposing) = 0;

};

  NS_DEFINE_STATIC_IID_ACCESSOR(nsIEditorIMESupport, NS_IEDITORIMESUPPORT_IID)

/* Use this macro when declaring classes that implement this interface. */
#define NS_DECL_NSIEDITORIMESUPPORT \
  NS_IMETHOD BeginComposition(nsTextEventReply * aReply); \
  NS_IMETHOD SetCompositionString(const nsAString & aCompositionString, nsIPrivateTextRangeList * aTextRange, nsTextEventReply * aReply); \
  NS_SCRIPTABLE NS_IMETHOD EndComposition(void); \
  NS_IMETHOD QueryComposition(nsTextEventReply * aReply); \
  NS_SCRIPTABLE NS_IMETHOD ForceCompositionEnd(void); \
  NS_IMETHOD GetPreferredIMEState(PRUint32 *aState NS_OUTPARAM); \
  NS_SCRIPTABLE NS_IMETHOD GetComposing(PRBool *aComposing); 

/* Use this macro to declare functions that forward the behavior of this interface to another object. */
#define NS_FORWARD_NSIEDITORIMESUPPORT(_to) \
  NS_IMETHOD BeginComposition(nsTextEventReply * aReply) { return _to BeginComposition(aReply); } \
  NS_IMETHOD SetCompositionString(const nsAString & aCompositionString, nsIPrivateTextRangeList * aTextRange, nsTextEventReply * aReply) { return _to SetCompositionString(aCompositionString, aTextRange, aReply); } \
  NS_SCRIPTABLE NS_IMETHOD EndComposition(void) { return _to EndComposition(); } \
  NS_IMETHOD QueryComposition(nsTextEventReply * aReply) { return _to QueryComposition(aReply); } \
  NS_SCRIPTABLE NS_IMETHOD ForceCompositionEnd(void) { return _to ForceCompositionEnd(); } \
  NS_IMETHOD GetPreferredIMEState(PRUint32 *aState NS_OUTPARAM) { return _to GetPreferredIMEState(aState); } \
  NS_SCRIPTABLE NS_IMETHOD GetComposing(PRBool *aComposing) { return _to GetComposing(aComposing); } 

/* Use this macro to declare functions that forward the behavior of this interface to another object in a safe way. */
#define NS_FORWARD_SAFE_NSIEDITORIMESUPPORT(_to) \
  NS_IMETHOD BeginComposition(nsTextEventReply * aReply) { return !_to ? NS_ERROR_NULL_POINTER : _to->BeginComposition(aReply); } \
  NS_IMETHOD SetCompositionString(const nsAString & aCompositionString, nsIPrivateTextRangeList * aTextRange, nsTextEventReply * aReply) { return !_to ? NS_ERROR_NULL_POINTER : _to->SetCompositionString(aCompositionString, aTextRange, aReply); } \
  NS_SCRIPTABLE NS_IMETHOD EndComposition(void) { return !_to ? NS_ERROR_NULL_POINTER : _to->EndComposition(); } \
  NS_IMETHOD QueryComposition(nsTextEventReply * aReply) { return !_to ? NS_ERROR_NULL_POINTER : _to->QueryComposition(aReply); } \
  NS_SCRIPTABLE NS_IMETHOD ForceCompositionEnd(void) { return !_to ? NS_ERROR_NULL_POINTER : _to->ForceCompositionEnd(); } \
  NS_IMETHOD GetPreferredIMEState(PRUint32 *aState NS_OUTPARAM) { return !_to ? NS_ERROR_NULL_POINTER : _to->GetPreferredIMEState(aState); } \
  NS_SCRIPTABLE NS_IMETHOD GetComposing(PRBool *aComposing) { return !_to ? NS_ERROR_NULL_POINTER : _to->GetComposing(aComposing); } 

#if 0
/* Use the code below as a template for the implementation class for this interface. */

/* Header file */
class nsEditorIMESupport : public nsIEditorIMESupport
{
public:
  NS_DECL_ISUPPORTS
  NS_DECL_NSIEDITORIMESUPPORT

  nsEditorIMESupport();

private:
  ~nsEditorIMESupport();

protected:
  /* additional members */
};

/* Implementation file */
NS_IMPL_ISUPPORTS1(nsEditorIMESupport, nsIEditorIMESupport)

nsEditorIMESupport::nsEditorIMESupport()
{
  /* member initializers and constructor code */
}

nsEditorIMESupport::~nsEditorIMESupport()
{
  /* destructor code */
}

/* [noscript] void beginComposition (in nsTextEventReplyPtr aReply); */
NS_IMETHODIMP nsEditorIMESupport::BeginComposition(nsTextEventReply * aReply)
{
    return NS_ERROR_NOT_IMPLEMENTED;
}

/* [noscript] void setCompositionString (in DOMString aCompositionString, in nsIPrivateTextRangeListPtr aTextRange, in nsTextEventReplyPtr aReply); */
NS_IMETHODIMP nsEditorIMESupport::SetCompositionString(const nsAString & aCompositionString, nsIPrivateTextRangeList * aTextRange, nsTextEventReply * aReply)
{
    return NS_ERROR_NOT_IMPLEMENTED;
}

/* void endComposition (); */
NS_IMETHODIMP nsEditorIMESupport::EndComposition()
{
    return NS_ERROR_NOT_IMPLEMENTED;
}

/* [noscript] void queryComposition (in nsTextEventReplyPtr aReply); */
NS_IMETHODIMP nsEditorIMESupport::QueryComposition(nsTextEventReply * aReply)
{
    return NS_ERROR_NOT_IMPLEMENTED;
}

/* void forceCompositionEnd (); */
NS_IMETHODIMP nsEditorIMESupport::ForceCompositionEnd()
{
    return NS_ERROR_NOT_IMPLEMENTED;
}

/* [noscript] void getPreferredIMEState (out unsigned long aState); */
NS_IMETHODIMP nsEditorIMESupport::GetPreferredIMEState(PRUint32 *aState NS_OUTPARAM)
{
    return NS_ERROR_NOT_IMPLEMENTED;
}

/* readonly attribute boolean composing; */
NS_IMETHODIMP nsEditorIMESupport::GetComposing(PRBool *aComposing)
{
    return NS_ERROR_NOT_IMPLEMENTED;
}

/* End of implementation class template. */
#endif


#endif /* __gen_nsIEditorIMESupport_h__ */
