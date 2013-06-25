/*
 * DO NOT EDIT.  THIS FILE IS GENERATED FROM e:/builds/moz2_slave/mozilla-1.9.1-win32-xulrunner/build/accessible/public/nsIAccessibleHyperText.idl
 */

#ifndef __gen_nsIAccessibleHyperText_h__
#define __gen_nsIAccessibleHyperText_h__


#ifndef __gen_nsISupports_h__
#include "nsISupports.h"
#endif

#ifndef __gen_nsIAccessibleHyperLink_h__
#include "nsIAccessibleHyperLink.h"
#endif

/* For IDL files that don't want to include root IDL files. */
#ifndef NS_NO_VTABLE
#define NS_NO_VTABLE
#endif

/* starting interface:    nsIAccessibleHyperText */
#define NS_IACCESSIBLEHYPERTEXT_IID_STR "d56bd454-8ff3-4edc-b266-baeada00267b"

#define NS_IACCESSIBLEHYPERTEXT_IID \
  {0xd56bd454, 0x8ff3, 0x4edc, \
    { 0xb2, 0x66, 0xba, 0xea, 0xda, 0x00, 0x26, 0x7b }}

/**
 * A cross-platform interface that deals with text which contains hyperlinks.
 */
class NS_NO_VTABLE NS_SCRIPTABLE nsIAccessibleHyperText : public nsISupports {
 public: 

  NS_DECLARE_STATIC_IID_ACCESSOR(NS_IACCESSIBLEHYPERTEXT_IID)

  /**
   * Returns the number of links contained within this hypertext object.
   */
  /* readonly attribute long linkCount; */
  NS_SCRIPTABLE NS_IMETHOD GetLinkCount(PRInt32 *aLinkCount) = 0;

  /* long getLinkIndex (in long charIndex); */
  NS_SCRIPTABLE NS_IMETHOD GetLinkIndex(PRInt32 charIndex, PRInt32 *_retval NS_OUTPARAM) = 0;

  /**
   * Retrieves the nsIAccessibleHyperLink object at the given link index.
   *
   * @param linkIndex  0-based index of the link that is to be retrieved.
   * This can be retrieved via getLinkIndex (see above).
   *
   * @returns nsIAccessibleHyperLink  Object representing the link properties
   * or NS_ERROR_INVALID_ARG if there is no link at that index.
   */
  /* nsIAccessibleHyperLink getLink (in long linkIndex); */
  NS_SCRIPTABLE NS_IMETHOD GetLink(PRInt32 linkIndex, nsIAccessibleHyperLink **_retval NS_OUTPARAM) = 0;

};

  NS_DEFINE_STATIC_IID_ACCESSOR(nsIAccessibleHyperText, NS_IACCESSIBLEHYPERTEXT_IID)

/* Use this macro when declaring classes that implement this interface. */
#define NS_DECL_NSIACCESSIBLEHYPERTEXT \
  NS_SCRIPTABLE NS_IMETHOD GetLinkCount(PRInt32 *aLinkCount); \
  NS_SCRIPTABLE NS_IMETHOD GetLinkIndex(PRInt32 charIndex, PRInt32 *_retval NS_OUTPARAM); \
  NS_SCRIPTABLE NS_IMETHOD GetLink(PRInt32 linkIndex, nsIAccessibleHyperLink **_retval NS_OUTPARAM); 

/* Use this macro to declare functions that forward the behavior of this interface to another object. */
#define NS_FORWARD_NSIACCESSIBLEHYPERTEXT(_to) \
  NS_SCRIPTABLE NS_IMETHOD GetLinkCount(PRInt32 *aLinkCount) { return _to GetLinkCount(aLinkCount); } \
  NS_SCRIPTABLE NS_IMETHOD GetLinkIndex(PRInt32 charIndex, PRInt32 *_retval NS_OUTPARAM) { return _to GetLinkIndex(charIndex, _retval); } \
  NS_SCRIPTABLE NS_IMETHOD GetLink(PRInt32 linkIndex, nsIAccessibleHyperLink **_retval NS_OUTPARAM) { return _to GetLink(linkIndex, _retval); } 

/* Use this macro to declare functions that forward the behavior of this interface to another object in a safe way. */
#define NS_FORWARD_SAFE_NSIACCESSIBLEHYPERTEXT(_to) \
  NS_SCRIPTABLE NS_IMETHOD GetLinkCount(PRInt32 *aLinkCount) { return !_to ? NS_ERROR_NULL_POINTER : _to->GetLinkCount(aLinkCount); } \
  NS_SCRIPTABLE NS_IMETHOD GetLinkIndex(PRInt32 charIndex, PRInt32 *_retval NS_OUTPARAM) { return !_to ? NS_ERROR_NULL_POINTER : _to->GetLinkIndex(charIndex, _retval); } \
  NS_SCRIPTABLE NS_IMETHOD GetLink(PRInt32 linkIndex, nsIAccessibleHyperLink **_retval NS_OUTPARAM) { return !_to ? NS_ERROR_NULL_POINTER : _to->GetLink(linkIndex, _retval); } 

#if 0
/* Use the code below as a template for the implementation class for this interface. */

/* Header file */
class nsAccessibleHyperText : public nsIAccessibleHyperText
{
public:
  NS_DECL_ISUPPORTS
  NS_DECL_NSIACCESSIBLEHYPERTEXT

  nsAccessibleHyperText();

private:
  ~nsAccessibleHyperText();

protected:
  /* additional members */
};

/* Implementation file */
NS_IMPL_ISUPPORTS1(nsAccessibleHyperText, nsIAccessibleHyperText)

nsAccessibleHyperText::nsAccessibleHyperText()
{
  /* member initializers and constructor code */
}

nsAccessibleHyperText::~nsAccessibleHyperText()
{
  /* destructor code */
}

/* readonly attribute long linkCount; */
NS_IMETHODIMP nsAccessibleHyperText::GetLinkCount(PRInt32 *aLinkCount)
{
    return NS_ERROR_NOT_IMPLEMENTED;
}

/* long getLinkIndex (in long charIndex); */
NS_IMETHODIMP nsAccessibleHyperText::GetLinkIndex(PRInt32 charIndex, PRInt32 *_retval NS_OUTPARAM)
{
    return NS_ERROR_NOT_IMPLEMENTED;
}

/* nsIAccessibleHyperLink getLink (in long linkIndex); */
NS_IMETHODIMP nsAccessibleHyperText::GetLink(PRInt32 linkIndex, nsIAccessibleHyperLink **_retval NS_OUTPARAM)
{
    return NS_ERROR_NOT_IMPLEMENTED;
}

/* End of implementation class template. */
#endif


#endif /* __gen_nsIAccessibleHyperText_h__ */
