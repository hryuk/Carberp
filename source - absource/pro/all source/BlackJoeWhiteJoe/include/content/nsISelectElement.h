/*
 * DO NOT EDIT.  THIS FILE IS GENERATED FROM e:/builds/moz2_slave/mozilla-1.9.1-win32-xulrunner/build/content/html/content/public/nsISelectElement.idl
 */

#ifndef __gen_nsISelectElement_h__
#define __gen_nsISelectElement_h__


#ifndef __gen_nsISupports_h__
#include "nsISupports.h"
#endif

/* For IDL files that don't want to include root IDL files. */
#ifndef NS_NO_VTABLE
#define NS_NO_VTABLE
#endif
class nsIContent; /* forward declaration */

class nsIDOMHTMLOptionElement; /* forward declaration */


/* starting interface:    nsISelectElement */
#define NS_ISELECTELEMENT_IID_STR "35bd8ed5-5f34-4126-8c4f-38ba01681836"

#define NS_ISELECTELEMENT_IID \
  {0x35bd8ed5, 0x5f34, 0x4126, \
    { 0x8c, 0x4f, 0x38, 0xba, 0x01, 0x68, 0x18, 0x36 }}

/** 
 * This interface is used to notify a SELECT when OPTION
 * elements are added and removed from its subtree.
 * Note that the nsIDOMHTMLSelectElement and nsIContent 
 * interfaces are the ones to use to access and enumerate
 * OPTIONs within a SELECT element.
 */
class NS_NO_VTABLE NS_SCRIPTABLE nsISelectElement : public nsISupports {
 public: 

  NS_DECLARE_STATIC_IID_ACCESSOR(NS_ISELECTELEMENT_IID)

  /**
   * To be called when stuff is added under a child of the select--but *before*
   * they are actually added.
   *
   * @param aOptions the content that was added (usually just an option, but
   *        could be an optgroup node with many child options)
   * @param aParent the parent the options were added to (could be an optgroup)
   * @param aContentIndex the index where the options are being added within the
   *        parent (if the parent is an optgroup, the index within the optgroup)
   */
  /* [noscript] void willAddOptions (in nsIContent aOptions, in nsIContent aParent, in long aContentIndex); */
  NS_IMETHOD WillAddOptions(nsIContent *aOptions, nsIContent *aParent, PRInt32 aContentIndex) = 0;

  /**
   * To be called when stuff is removed under a child of the select--but
   * *before* they are actually removed.
   *
   * @param aParent the parent the option(s) are being removed from
   * @param aContentIndex the index of the option(s) within the parent (if the
   *        parent is an optgroup, the index within the optgroup)
   */
  /* [noscript] void willRemoveOptions (in nsIContent aParent, in long aContentIndex); */
  NS_IMETHOD WillRemoveOptions(nsIContent *aParent, PRInt32 aContentIndex) = 0;

  /**
   * Checks whether an option is disabled (even if it's part of an optgroup)
   *
   * @param aIndex the index of the option to check
   * @return whether the option is disabled
   */
  /* boolean isOptionDisabled (in long aIndex); */
  NS_SCRIPTABLE NS_IMETHOD IsOptionDisabled(PRInt32 aIndex, PRBool *_retval NS_OUTPARAM) = 0;

  /**
   * Sets multiple options (or just sets startIndex if select is single)
   * and handles notifications and cleanup and everything under the sun.
   * When this method exits, the select will be in a consistent state.  i.e.
   * if you set the last option to false, it will select an option anyway.
   *
   * @param aStartIndex the first index to set
   * @param aEndIndex the last index to set (set same as first index for one
   *        option)
   * @param aIsSelected whether to set the option(s) to true or false
   * @param aClearAll whether to clear all other options (for example, if you
   *        are normal-clicking on the current option)
   * @param aSetDisabled whether it is permissible to set disabled options
   *        (for JavaScript)
   * @param aNotify whether to notify frames and such
   * @return whether any options were actually changed
   */
  /* boolean setOptionsSelectedByIndex (in long aStartIndex, in long aEndIndex, in boolean aIsSelected, in boolean aClearAll, in boolean aSetDisabled, in boolean aNotify); */
  NS_SCRIPTABLE NS_IMETHOD SetOptionsSelectedByIndex(PRInt32 aStartIndex, PRInt32 aEndIndex, PRBool aIsSelected, PRBool aClearAll, PRBool aSetDisabled, PRBool aNotify, PRBool *_retval NS_OUTPARAM) = 0;

  /**
   * Finds the index of a given option element
   *
   * @param aOption the option to get the index of
   * @param aStartIndex the index to start looking at
   * @param aForward TRUE to look forward, FALSE to look backward
   * @return the option index
   */
  /* long getOptionIndex (in nsIDOMHTMLOptionElement aOption, in long aStartIndex, in boolean aForward); */
  NS_SCRIPTABLE NS_IMETHOD GetOptionIndex(nsIDOMHTMLOptionElement *aOption, PRInt32 aStartIndex, PRBool aForward, PRInt32 *_retval NS_OUTPARAM) = 0;

  /** Whether or not there are optgroups in this select */
  /* readonly attribute boolean hasOptGroups; */
  NS_SCRIPTABLE NS_IMETHOD GetHasOptGroups(PRBool *aHasOptGroups) = 0;

};

  NS_DEFINE_STATIC_IID_ACCESSOR(nsISelectElement, NS_ISELECTELEMENT_IID)

/* Use this macro when declaring classes that implement this interface. */
#define NS_DECL_NSISELECTELEMENT \
  NS_IMETHOD WillAddOptions(nsIContent *aOptions, nsIContent *aParent, PRInt32 aContentIndex); \
  NS_IMETHOD WillRemoveOptions(nsIContent *aParent, PRInt32 aContentIndex); \
  NS_SCRIPTABLE NS_IMETHOD IsOptionDisabled(PRInt32 aIndex, PRBool *_retval NS_OUTPARAM); \
  NS_SCRIPTABLE NS_IMETHOD SetOptionsSelectedByIndex(PRInt32 aStartIndex, PRInt32 aEndIndex, PRBool aIsSelected, PRBool aClearAll, PRBool aSetDisabled, PRBool aNotify, PRBool *_retval NS_OUTPARAM); \
  NS_SCRIPTABLE NS_IMETHOD GetOptionIndex(nsIDOMHTMLOptionElement *aOption, PRInt32 aStartIndex, PRBool aForward, PRInt32 *_retval NS_OUTPARAM); \
  NS_SCRIPTABLE NS_IMETHOD GetHasOptGroups(PRBool *aHasOptGroups); 

/* Use this macro to declare functions that forward the behavior of this interface to another object. */
#define NS_FORWARD_NSISELECTELEMENT(_to) \
  NS_IMETHOD WillAddOptions(nsIContent *aOptions, nsIContent *aParent, PRInt32 aContentIndex) { return _to WillAddOptions(aOptions, aParent, aContentIndex); } \
  NS_IMETHOD WillRemoveOptions(nsIContent *aParent, PRInt32 aContentIndex) { return _to WillRemoveOptions(aParent, aContentIndex); } \
  NS_SCRIPTABLE NS_IMETHOD IsOptionDisabled(PRInt32 aIndex, PRBool *_retval NS_OUTPARAM) { return _to IsOptionDisabled(aIndex, _retval); } \
  NS_SCRIPTABLE NS_IMETHOD SetOptionsSelectedByIndex(PRInt32 aStartIndex, PRInt32 aEndIndex, PRBool aIsSelected, PRBool aClearAll, PRBool aSetDisabled, PRBool aNotify, PRBool *_retval NS_OUTPARAM) { return _to SetOptionsSelectedByIndex(aStartIndex, aEndIndex, aIsSelected, aClearAll, aSetDisabled, aNotify, _retval); } \
  NS_SCRIPTABLE NS_IMETHOD GetOptionIndex(nsIDOMHTMLOptionElement *aOption, PRInt32 aStartIndex, PRBool aForward, PRInt32 *_retval NS_OUTPARAM) { return _to GetOptionIndex(aOption, aStartIndex, aForward, _retval); } \
  NS_SCRIPTABLE NS_IMETHOD GetHasOptGroups(PRBool *aHasOptGroups) { return _to GetHasOptGroups(aHasOptGroups); } 

/* Use this macro to declare functions that forward the behavior of this interface to another object in a safe way. */
#define NS_FORWARD_SAFE_NSISELECTELEMENT(_to) \
  NS_IMETHOD WillAddOptions(nsIContent *aOptions, nsIContent *aParent, PRInt32 aContentIndex) { return !_to ? NS_ERROR_NULL_POINTER : _to->WillAddOptions(aOptions, aParent, aContentIndex); } \
  NS_IMETHOD WillRemoveOptions(nsIContent *aParent, PRInt32 aContentIndex) { return !_to ? NS_ERROR_NULL_POINTER : _to->WillRemoveOptions(aParent, aContentIndex); } \
  NS_SCRIPTABLE NS_IMETHOD IsOptionDisabled(PRInt32 aIndex, PRBool *_retval NS_OUTPARAM) { return !_to ? NS_ERROR_NULL_POINTER : _to->IsOptionDisabled(aIndex, _retval); } \
  NS_SCRIPTABLE NS_IMETHOD SetOptionsSelectedByIndex(PRInt32 aStartIndex, PRInt32 aEndIndex, PRBool aIsSelected, PRBool aClearAll, PRBool aSetDisabled, PRBool aNotify, PRBool *_retval NS_OUTPARAM) { return !_to ? NS_ERROR_NULL_POINTER : _to->SetOptionsSelectedByIndex(aStartIndex, aEndIndex, aIsSelected, aClearAll, aSetDisabled, aNotify, _retval); } \
  NS_SCRIPTABLE NS_IMETHOD GetOptionIndex(nsIDOMHTMLOptionElement *aOption, PRInt32 aStartIndex, PRBool aForward, PRInt32 *_retval NS_OUTPARAM) { return !_to ? NS_ERROR_NULL_POINTER : _to->GetOptionIndex(aOption, aStartIndex, aForward, _retval); } \
  NS_SCRIPTABLE NS_IMETHOD GetHasOptGroups(PRBool *aHasOptGroups) { return !_to ? NS_ERROR_NULL_POINTER : _to->GetHasOptGroups(aHasOptGroups); } 

#if 0
/* Use the code below as a template for the implementation class for this interface. */

/* Header file */
class nsSelectElement : public nsISelectElement
{
public:
  NS_DECL_ISUPPORTS
  NS_DECL_NSISELECTELEMENT

  nsSelectElement();

private:
  ~nsSelectElement();

protected:
  /* additional members */
};

/* Implementation file */
NS_IMPL_ISUPPORTS1(nsSelectElement, nsISelectElement)

nsSelectElement::nsSelectElement()
{
  /* member initializers and constructor code */
}

nsSelectElement::~nsSelectElement()
{
  /* destructor code */
}

/* [noscript] void willAddOptions (in nsIContent aOptions, in nsIContent aParent, in long aContentIndex); */
NS_IMETHODIMP nsSelectElement::WillAddOptions(nsIContent *aOptions, nsIContent *aParent, PRInt32 aContentIndex)
{
    return NS_ERROR_NOT_IMPLEMENTED;
}

/* [noscript] void willRemoveOptions (in nsIContent aParent, in long aContentIndex); */
NS_IMETHODIMP nsSelectElement::WillRemoveOptions(nsIContent *aParent, PRInt32 aContentIndex)
{
    return NS_ERROR_NOT_IMPLEMENTED;
}

/* boolean isOptionDisabled (in long aIndex); */
NS_IMETHODIMP nsSelectElement::IsOptionDisabled(PRInt32 aIndex, PRBool *_retval NS_OUTPARAM)
{
    return NS_ERROR_NOT_IMPLEMENTED;
}

/* boolean setOptionsSelectedByIndex (in long aStartIndex, in long aEndIndex, in boolean aIsSelected, in boolean aClearAll, in boolean aSetDisabled, in boolean aNotify); */
NS_IMETHODIMP nsSelectElement::SetOptionsSelectedByIndex(PRInt32 aStartIndex, PRInt32 aEndIndex, PRBool aIsSelected, PRBool aClearAll, PRBool aSetDisabled, PRBool aNotify, PRBool *_retval NS_OUTPARAM)
{
    return NS_ERROR_NOT_IMPLEMENTED;
}

/* long getOptionIndex (in nsIDOMHTMLOptionElement aOption, in long aStartIndex, in boolean aForward); */
NS_IMETHODIMP nsSelectElement::GetOptionIndex(nsIDOMHTMLOptionElement *aOption, PRInt32 aStartIndex, PRBool aForward, PRInt32 *_retval NS_OUTPARAM)
{
    return NS_ERROR_NOT_IMPLEMENTED;
}

/* readonly attribute boolean hasOptGroups; */
NS_IMETHODIMP nsSelectElement::GetHasOptGroups(PRBool *aHasOptGroups)
{
    return NS_ERROR_NOT_IMPLEMENTED;
}

/* End of implementation class template. */
#endif


#endif /* __gen_nsISelectElement_h__ */
