/*
 * DO NOT EDIT.  THIS FILE IS GENERATED FROM e:/builds/moz2_slave/mozilla-1.9.1-win32-xulrunner/build/layout/inspector/public/inIDOMUtils.idl
 */

#ifndef __gen_inIDOMUtils_h__
#define __gen_inIDOMUtils_h__


#ifndef __gen_nsISupports_h__
#include "nsISupports.h"
#endif

/* For IDL files that don't want to include root IDL files. */
#ifndef NS_NO_VTABLE
#define NS_NO_VTABLE
#endif
class nsIArray; /* forward declaration */

class nsISupportsArray; /* forward declaration */

class nsIDOMCharacterData; /* forward declaration */

class nsIDOMElement; /* forward declaration */

class nsIDOMDocument; /* forward declaration */

class nsIDOMCSSStyleRule; /* forward declaration */

class nsIDOMNode; /* forward declaration */


/* starting interface:    inIDOMUtils */
#define INIDOMUTILS_IID_STR "78fd16c2-bdfb-4b1d-8738-d536d0a8f430"

#define INIDOMUTILS_IID \
  {0x78fd16c2, 0xbdfb, 0x4b1d, \
    { 0x87, 0x38, 0xd5, 0x36, 0xd0, 0xa8, 0xf4, 0x30 }}

class NS_NO_VTABLE NS_SCRIPTABLE inIDOMUtils : public nsISupports {
 public: 

  NS_DECLARE_STATIC_IID_ACCESSOR(INIDOMUTILS_IID)

  /* nsISupportsArray getCSSStyleRules (in nsIDOMElement aElement); */
  NS_SCRIPTABLE NS_IMETHOD GetCSSStyleRules(nsIDOMElement *aElement, nsISupportsArray **_retval NS_OUTPARAM) = 0;

  /* unsigned long getRuleLine (in nsIDOMCSSStyleRule aRule); */
  NS_SCRIPTABLE NS_IMETHOD GetRuleLine(nsIDOMCSSStyleRule *aRule, PRUint32 *_retval NS_OUTPARAM) = 0;

  /* boolean isIgnorableWhitespace (in nsIDOMCharacterData aDataNode); */
  NS_SCRIPTABLE NS_IMETHOD IsIgnorableWhitespace(nsIDOMCharacterData *aDataNode, PRBool *_retval NS_OUTPARAM) = 0;

  /* nsIDOMNode getParentForNode (in nsIDOMNode aNode, in boolean aShowingAnonymousContent); */
  NS_SCRIPTABLE NS_IMETHOD GetParentForNode(nsIDOMNode *aNode, PRBool aShowingAnonymousContent, nsIDOMNode **_retval NS_OUTPARAM) = 0;

  /* nsIArray getBindingURLs (in nsIDOMElement aElement); */
  NS_SCRIPTABLE NS_IMETHOD GetBindingURLs(nsIDOMElement *aElement, nsIArray **_retval NS_OUTPARAM) = 0;

  /* long getContentState (in nsIDOMElement aElement); */
  NS_SCRIPTABLE NS_IMETHOD GetContentState(nsIDOMElement *aElement, PRInt32 *_retval NS_OUTPARAM) = 0;

  /* void setContentState (in nsIDOMElement aElement, in long aState); */
  NS_SCRIPTABLE NS_IMETHOD SetContentState(nsIDOMElement *aElement, PRInt32 aState) = 0;

};

  NS_DEFINE_STATIC_IID_ACCESSOR(inIDOMUtils, INIDOMUTILS_IID)

/* Use this macro when declaring classes that implement this interface. */
#define NS_DECL_INIDOMUTILS \
  NS_SCRIPTABLE NS_IMETHOD GetCSSStyleRules(nsIDOMElement *aElement, nsISupportsArray **_retval NS_OUTPARAM); \
  NS_SCRIPTABLE NS_IMETHOD GetRuleLine(nsIDOMCSSStyleRule *aRule, PRUint32 *_retval NS_OUTPARAM); \
  NS_SCRIPTABLE NS_IMETHOD IsIgnorableWhitespace(nsIDOMCharacterData *aDataNode, PRBool *_retval NS_OUTPARAM); \
  NS_SCRIPTABLE NS_IMETHOD GetParentForNode(nsIDOMNode *aNode, PRBool aShowingAnonymousContent, nsIDOMNode **_retval NS_OUTPARAM); \
  NS_SCRIPTABLE NS_IMETHOD GetBindingURLs(nsIDOMElement *aElement, nsIArray **_retval NS_OUTPARAM); \
  NS_SCRIPTABLE NS_IMETHOD GetContentState(nsIDOMElement *aElement, PRInt32 *_retval NS_OUTPARAM); \
  NS_SCRIPTABLE NS_IMETHOD SetContentState(nsIDOMElement *aElement, PRInt32 aState); 

/* Use this macro to declare functions that forward the behavior of this interface to another object. */
#define NS_FORWARD_INIDOMUTILS(_to) \
  NS_SCRIPTABLE NS_IMETHOD GetCSSStyleRules(nsIDOMElement *aElement, nsISupportsArray **_retval NS_OUTPARAM) { return _to GetCSSStyleRules(aElement, _retval); } \
  NS_SCRIPTABLE NS_IMETHOD GetRuleLine(nsIDOMCSSStyleRule *aRule, PRUint32 *_retval NS_OUTPARAM) { return _to GetRuleLine(aRule, _retval); } \
  NS_SCRIPTABLE NS_IMETHOD IsIgnorableWhitespace(nsIDOMCharacterData *aDataNode, PRBool *_retval NS_OUTPARAM) { return _to IsIgnorableWhitespace(aDataNode, _retval); } \
  NS_SCRIPTABLE NS_IMETHOD GetParentForNode(nsIDOMNode *aNode, PRBool aShowingAnonymousContent, nsIDOMNode **_retval NS_OUTPARAM) { return _to GetParentForNode(aNode, aShowingAnonymousContent, _retval); } \
  NS_SCRIPTABLE NS_IMETHOD GetBindingURLs(nsIDOMElement *aElement, nsIArray **_retval NS_OUTPARAM) { return _to GetBindingURLs(aElement, _retval); } \
  NS_SCRIPTABLE NS_IMETHOD GetContentState(nsIDOMElement *aElement, PRInt32 *_retval NS_OUTPARAM) { return _to GetContentState(aElement, _retval); } \
  NS_SCRIPTABLE NS_IMETHOD SetContentState(nsIDOMElement *aElement, PRInt32 aState) { return _to SetContentState(aElement, aState); } 

/* Use this macro to declare functions that forward the behavior of this interface to another object in a safe way. */
#define NS_FORWARD_SAFE_INIDOMUTILS(_to) \
  NS_SCRIPTABLE NS_IMETHOD GetCSSStyleRules(nsIDOMElement *aElement, nsISupportsArray **_retval NS_OUTPARAM) { return !_to ? NS_ERROR_NULL_POINTER : _to->GetCSSStyleRules(aElement, _retval); } \
  NS_SCRIPTABLE NS_IMETHOD GetRuleLine(nsIDOMCSSStyleRule *aRule, PRUint32 *_retval NS_OUTPARAM) { return !_to ? NS_ERROR_NULL_POINTER : _to->GetRuleLine(aRule, _retval); } \
  NS_SCRIPTABLE NS_IMETHOD IsIgnorableWhitespace(nsIDOMCharacterData *aDataNode, PRBool *_retval NS_OUTPARAM) { return !_to ? NS_ERROR_NULL_POINTER : _to->IsIgnorableWhitespace(aDataNode, _retval); } \
  NS_SCRIPTABLE NS_IMETHOD GetParentForNode(nsIDOMNode *aNode, PRBool aShowingAnonymousContent, nsIDOMNode **_retval NS_OUTPARAM) { return !_to ? NS_ERROR_NULL_POINTER : _to->GetParentForNode(aNode, aShowingAnonymousContent, _retval); } \
  NS_SCRIPTABLE NS_IMETHOD GetBindingURLs(nsIDOMElement *aElement, nsIArray **_retval NS_OUTPARAM) { return !_to ? NS_ERROR_NULL_POINTER : _to->GetBindingURLs(aElement, _retval); } \
  NS_SCRIPTABLE NS_IMETHOD GetContentState(nsIDOMElement *aElement, PRInt32 *_retval NS_OUTPARAM) { return !_to ? NS_ERROR_NULL_POINTER : _to->GetContentState(aElement, _retval); } \
  NS_SCRIPTABLE NS_IMETHOD SetContentState(nsIDOMElement *aElement, PRInt32 aState) { return !_to ? NS_ERROR_NULL_POINTER : _to->SetContentState(aElement, aState); } 

#if 0
/* Use the code below as a template for the implementation class for this interface. */

/* Header file */
class inDOMUtils : public inIDOMUtils
{
public:
  NS_DECL_ISUPPORTS
  NS_DECL_INIDOMUTILS

  inDOMUtils();

private:
  ~inDOMUtils();

protected:
  /* additional members */
};

/* Implementation file */
NS_IMPL_ISUPPORTS1(inDOMUtils, inIDOMUtils)

inDOMUtils::inDOMUtils()
{
  /* member initializers and constructor code */
}

inDOMUtils::~inDOMUtils()
{
  /* destructor code */
}

/* nsISupportsArray getCSSStyleRules (in nsIDOMElement aElement); */
NS_IMETHODIMP inDOMUtils::GetCSSStyleRules(nsIDOMElement *aElement, nsISupportsArray **_retval NS_OUTPARAM)
{
    return NS_ERROR_NOT_IMPLEMENTED;
}

/* unsigned long getRuleLine (in nsIDOMCSSStyleRule aRule); */
NS_IMETHODIMP inDOMUtils::GetRuleLine(nsIDOMCSSStyleRule *aRule, PRUint32 *_retval NS_OUTPARAM)
{
    return NS_ERROR_NOT_IMPLEMENTED;
}

/* boolean isIgnorableWhitespace (in nsIDOMCharacterData aDataNode); */
NS_IMETHODIMP inDOMUtils::IsIgnorableWhitespace(nsIDOMCharacterData *aDataNode, PRBool *_retval NS_OUTPARAM)
{
    return NS_ERROR_NOT_IMPLEMENTED;
}

/* nsIDOMNode getParentForNode (in nsIDOMNode aNode, in boolean aShowingAnonymousContent); */
NS_IMETHODIMP inDOMUtils::GetParentForNode(nsIDOMNode *aNode, PRBool aShowingAnonymousContent, nsIDOMNode **_retval NS_OUTPARAM)
{
    return NS_ERROR_NOT_IMPLEMENTED;
}

/* nsIArray getBindingURLs (in nsIDOMElement aElement); */
NS_IMETHODIMP inDOMUtils::GetBindingURLs(nsIDOMElement *aElement, nsIArray **_retval NS_OUTPARAM)
{
    return NS_ERROR_NOT_IMPLEMENTED;
}

/* long getContentState (in nsIDOMElement aElement); */
NS_IMETHODIMP inDOMUtils::GetContentState(nsIDOMElement *aElement, PRInt32 *_retval NS_OUTPARAM)
{
    return NS_ERROR_NOT_IMPLEMENTED;
}

/* void setContentState (in nsIDOMElement aElement, in long aState); */
NS_IMETHODIMP inDOMUtils::SetContentState(nsIDOMElement *aElement, PRInt32 aState)
{
    return NS_ERROR_NOT_IMPLEMENTED;
}

/* End of implementation class template. */
#endif


#endif /* __gen_inIDOMUtils_h__ */
