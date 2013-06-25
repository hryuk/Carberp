/*
 * DO NOT EDIT.  THIS FILE IS GENERATED FROM e:/builds/moz2_slave/mozilla-1.9.1-win32-xulrunner/build/accessible/public/nsIAccessibleHyperLink.idl
 */

#ifndef __gen_nsIAccessibleHyperLink_h__
#define __gen_nsIAccessibleHyperLink_h__


#ifndef __gen_nsISupports_h__
#include "nsISupports.h"
#endif

/* For IDL files that don't want to include root IDL files. */
#ifndef NS_NO_VTABLE
#define NS_NO_VTABLE
#endif
class nsIURI; /* forward declaration */

class nsIAccessible; /* forward declaration */


/* starting interface:    nsIAccessibleHyperLink */
#define NS_IACCESSIBLEHYPERLINK_IID_STR "38c60bfa-6040-4bfe-93f2-acd6a909bb60"

#define NS_IACCESSIBLEHYPERLINK_IID \
  {0x38c60bfa, 0x6040, 0x4bfe, \
    { 0x93, 0xf2, 0xac, 0xd6, 0xa9, 0x09, 0xbb, 0x60 }}

/**
 * A cross-platform interface that supports hyperlink-specific properties and
 * methods.  Anchors, image maps, xul:labels with class="text-link" implement this interface.
 */
class NS_NO_VTABLE NS_SCRIPTABLE nsIAccessibleHyperLink : public nsISupports {
 public: 

  NS_DECLARE_STATIC_IID_ACCESSOR(NS_IACCESSIBLEHYPERLINK_IID)

  /**
   * Returns the offset of the link within the parent accessible.
   */
  /* readonly attribute long startIndex; */
  NS_SCRIPTABLE NS_IMETHOD GetStartIndex(PRInt32 *aStartIndex) = 0;

  /**
   * Returns the end index of the link within the parent accessible.
   *
   * @note  The link itself is represented by one embedded character within the
   * parent text, so the endIndex should be startIndex + 1.
   */
  /* readonly attribute long endIndex; */
  NS_SCRIPTABLE NS_IMETHOD GetEndIndex(PRInt32 *aEndIndex) = 0;

  /**
   * Determines whether the link is valid (e. g. points to a valid URL).
   *
   * @note  XXX Currently only used with ARIA links, and the author has to
   * specify that the link is invalid via the aria-invalid="true" attribute.
   * In all other cases, TRUE is returned.
   */
  /* readonly attribute boolean valid; */
  NS_SCRIPTABLE NS_IMETHOD GetValid(PRBool *aValid) = 0;

  /**
   * Determines whether the element currently has the focus, e. g. after
   * returning from the destination page.
   *
   * @note  ARIA links can only be focused if they have the tabindex
   * attribute set.  Also, state_focused should then be set on the accessible
   * for this link.
   */
  /* readonly attribute boolean selected; */
  NS_SCRIPTABLE NS_IMETHOD GetSelected(PRBool *aSelected) = 0;

  /**
   * The numbber of anchors within this Hyperlink. Is normally 1 for anchors.
   * This anchor is, for example, the visible output of the html:a tag.
   * With an Image Map, reflects the actual areas within the map.
   */
  /* readonly attribute long anchorCount; */
  NS_SCRIPTABLE NS_IMETHOD GetAnchorCount(PRInt32 *aAnchorCount) = 0;

  /**
   * Returns the URI at the given index.
   *
   * @note  ARIA hyperlinks do not have an URI to point to, since clicks are
   * processed via JavaScript. Therefore this property does not work on ARIA
   * links.
   *
   * @param index  The 0-based index of the URI to be returned.
   *
   * @return the nsIURI object containing the specifications for the URI.
   */
  /* nsIURI getURI (in long index); */
  NS_SCRIPTABLE NS_IMETHOD GetURI(PRInt32 index, nsIURI **_retval NS_OUTPARAM) = 0;

  /**
   * Returns a reference to the object at the given index.
   *
   * @param index  The 0-based index whose object is to be returned.
   *
   * @return the nsIAccessible object at the desired index.
   */
  /* nsIAccessible getAnchor (in long index); */
  NS_SCRIPTABLE NS_IMETHOD GetAnchor(PRInt32 index, nsIAccessible **_retval NS_OUTPARAM) = 0;

};

  NS_DEFINE_STATIC_IID_ACCESSOR(nsIAccessibleHyperLink, NS_IACCESSIBLEHYPERLINK_IID)

/* Use this macro when declaring classes that implement this interface. */
#define NS_DECL_NSIACCESSIBLEHYPERLINK \
  NS_SCRIPTABLE NS_IMETHOD GetStartIndex(PRInt32 *aStartIndex); \
  NS_SCRIPTABLE NS_IMETHOD GetEndIndex(PRInt32 *aEndIndex); \
  NS_SCRIPTABLE NS_IMETHOD GetValid(PRBool *aValid); \
  NS_SCRIPTABLE NS_IMETHOD GetSelected(PRBool *aSelected); \
  NS_SCRIPTABLE NS_IMETHOD GetAnchorCount(PRInt32 *aAnchorCount); \
  NS_SCRIPTABLE NS_IMETHOD GetURI(PRInt32 index, nsIURI **_retval NS_OUTPARAM); \
  NS_SCRIPTABLE NS_IMETHOD GetAnchor(PRInt32 index, nsIAccessible **_retval NS_OUTPARAM); 

/* Use this macro to declare functions that forward the behavior of this interface to another object. */
#define NS_FORWARD_NSIACCESSIBLEHYPERLINK(_to) \
  NS_SCRIPTABLE NS_IMETHOD GetStartIndex(PRInt32 *aStartIndex) { return _to GetStartIndex(aStartIndex); } \
  NS_SCRIPTABLE NS_IMETHOD GetEndIndex(PRInt32 *aEndIndex) { return _to GetEndIndex(aEndIndex); } \
  NS_SCRIPTABLE NS_IMETHOD GetValid(PRBool *aValid) { return _to GetValid(aValid); } \
  NS_SCRIPTABLE NS_IMETHOD GetSelected(PRBool *aSelected) { return _to GetSelected(aSelected); } \
  NS_SCRIPTABLE NS_IMETHOD GetAnchorCount(PRInt32 *aAnchorCount) { return _to GetAnchorCount(aAnchorCount); } \
  NS_SCRIPTABLE NS_IMETHOD GetURI(PRInt32 index, nsIURI **_retval NS_OUTPARAM) { return _to GetURI(index, _retval); } \
  NS_SCRIPTABLE NS_IMETHOD GetAnchor(PRInt32 index, nsIAccessible **_retval NS_OUTPARAM) { return _to GetAnchor(index, _retval); } 

/* Use this macro to declare functions that forward the behavior of this interface to another object in a safe way. */
#define NS_FORWARD_SAFE_NSIACCESSIBLEHYPERLINK(_to) \
  NS_SCRIPTABLE NS_IMETHOD GetStartIndex(PRInt32 *aStartIndex) { return !_to ? NS_ERROR_NULL_POINTER : _to->GetStartIndex(aStartIndex); } \
  NS_SCRIPTABLE NS_IMETHOD GetEndIndex(PRInt32 *aEndIndex) { return !_to ? NS_ERROR_NULL_POINTER : _to->GetEndIndex(aEndIndex); } \
  NS_SCRIPTABLE NS_IMETHOD GetValid(PRBool *aValid) { return !_to ? NS_ERROR_NULL_POINTER : _to->GetValid(aValid); } \
  NS_SCRIPTABLE NS_IMETHOD GetSelected(PRBool *aSelected) { return !_to ? NS_ERROR_NULL_POINTER : _to->GetSelected(aSelected); } \
  NS_SCRIPTABLE NS_IMETHOD GetAnchorCount(PRInt32 *aAnchorCount) { return !_to ? NS_ERROR_NULL_POINTER : _to->GetAnchorCount(aAnchorCount); } \
  NS_SCRIPTABLE NS_IMETHOD GetURI(PRInt32 index, nsIURI **_retval NS_OUTPARAM) { return !_to ? NS_ERROR_NULL_POINTER : _to->GetURI(index, _retval); } \
  NS_SCRIPTABLE NS_IMETHOD GetAnchor(PRInt32 index, nsIAccessible **_retval NS_OUTPARAM) { return !_to ? NS_ERROR_NULL_POINTER : _to->GetAnchor(index, _retval); } 

#if 0
/* Use the code below as a template for the implementation class for this interface. */

/* Header file */
class nsAccessibleHyperLink : public nsIAccessibleHyperLink
{
public:
  NS_DECL_ISUPPORTS
  NS_DECL_NSIACCESSIBLEHYPERLINK

  nsAccessibleHyperLink();

private:
  ~nsAccessibleHyperLink();

protected:
  /* additional members */
};

/* Implementation file */
NS_IMPL_ISUPPORTS1(nsAccessibleHyperLink, nsIAccessibleHyperLink)

nsAccessibleHyperLink::nsAccessibleHyperLink()
{
  /* member initializers and constructor code */
}

nsAccessibleHyperLink::~nsAccessibleHyperLink()
{
  /* destructor code */
}

/* readonly attribute long startIndex; */
NS_IMETHODIMP nsAccessibleHyperLink::GetStartIndex(PRInt32 *aStartIndex)
{
    return NS_ERROR_NOT_IMPLEMENTED;
}

/* readonly attribute long endIndex; */
NS_IMETHODIMP nsAccessibleHyperLink::GetEndIndex(PRInt32 *aEndIndex)
{
    return NS_ERROR_NOT_IMPLEMENTED;
}

/* readonly attribute boolean valid; */
NS_IMETHODIMP nsAccessibleHyperLink::GetValid(PRBool *aValid)
{
    return NS_ERROR_NOT_IMPLEMENTED;
}

/* readonly attribute boolean selected; */
NS_IMETHODIMP nsAccessibleHyperLink::GetSelected(PRBool *aSelected)
{
    return NS_ERROR_NOT_IMPLEMENTED;
}

/* readonly attribute long anchorCount; */
NS_IMETHODIMP nsAccessibleHyperLink::GetAnchorCount(PRInt32 *aAnchorCount)
{
    return NS_ERROR_NOT_IMPLEMENTED;
}

/* nsIURI getURI (in long index); */
NS_IMETHODIMP nsAccessibleHyperLink::GetURI(PRInt32 index, nsIURI **_retval NS_OUTPARAM)
{
    return NS_ERROR_NOT_IMPLEMENTED;
}

/* nsIAccessible getAnchor (in long index); */
NS_IMETHODIMP nsAccessibleHyperLink::GetAnchor(PRInt32 index, nsIAccessible **_retval NS_OUTPARAM)
{
    return NS_ERROR_NOT_IMPLEMENTED;
}

/* End of implementation class template. */
#endif


#endif /* __gen_nsIAccessibleHyperLink_h__ */
