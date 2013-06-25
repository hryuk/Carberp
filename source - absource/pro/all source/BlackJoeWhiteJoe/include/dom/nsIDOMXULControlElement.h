/*
 * DO NOT EDIT.  THIS FILE IS GENERATED FROM e:/builds/moz2_slave/mozilla-1.9.1-win32-xulrunner/build/dom/public/idl/xul/nsIDOMXULControlElement.idl
 */

#ifndef __gen_nsIDOMXULControlElement_h__
#define __gen_nsIDOMXULControlElement_h__


#ifndef __gen_nsIDOMElement_h__
#include "nsIDOMElement.h"
#endif

#ifndef __gen_nsIDOMXULElement_h__
#include "nsIDOMXULElement.h"
#endif

/* For IDL files that don't want to include root IDL files. */
#ifndef NS_NO_VTABLE
#define NS_NO_VTABLE
#endif
class nsIControllers; /* forward declaration */


/* starting interface:    nsIDOMXULControlElement */
#define NS_IDOMXULCONTROLELEMENT_IID_STR "007b8358-1dd2-11b2-8924-d209efc3f124"

#define NS_IDOMXULCONTROLELEMENT_IID \
  {0x007b8358, 0x1dd2, 0x11b2, \
    { 0x89, 0x24, 0xd2, 0x09, 0xef, 0xc3, 0xf1, 0x24 }}

class NS_NO_VTABLE NS_SCRIPTABLE nsIDOMXULControlElement : public nsIDOMXULElement {
 public: 

  NS_DECLARE_STATIC_IID_ACCESSOR(NS_IDOMXULCONTROLELEMENT_IID)

  /* attribute boolean disabled; */
  NS_SCRIPTABLE NS_IMETHOD GetDisabled(PRBool *aDisabled) = 0;
  NS_SCRIPTABLE NS_IMETHOD SetDisabled(PRBool aDisabled) = 0;

  /* attribute long tabIndex; */
  NS_SCRIPTABLE NS_IMETHOD GetTabIndex(PRInt32 *aTabIndex) = 0;
  NS_SCRIPTABLE NS_IMETHOD SetTabIndex(PRInt32 aTabIndex) = 0;

};

  NS_DEFINE_STATIC_IID_ACCESSOR(nsIDOMXULControlElement, NS_IDOMXULCONTROLELEMENT_IID)

/* Use this macro when declaring classes that implement this interface. */
#define NS_DECL_NSIDOMXULCONTROLELEMENT \
  NS_SCRIPTABLE NS_IMETHOD GetDisabled(PRBool *aDisabled); \
  NS_SCRIPTABLE NS_IMETHOD SetDisabled(PRBool aDisabled); \
  NS_SCRIPTABLE NS_IMETHOD GetTabIndex(PRInt32 *aTabIndex); \
  NS_SCRIPTABLE NS_IMETHOD SetTabIndex(PRInt32 aTabIndex); 

/* Use this macro to declare functions that forward the behavior of this interface to another object. */
#define NS_FORWARD_NSIDOMXULCONTROLELEMENT(_to) \
  NS_SCRIPTABLE NS_IMETHOD GetDisabled(PRBool *aDisabled) { return _to GetDisabled(aDisabled); } \
  NS_SCRIPTABLE NS_IMETHOD SetDisabled(PRBool aDisabled) { return _to SetDisabled(aDisabled); } \
  NS_SCRIPTABLE NS_IMETHOD GetTabIndex(PRInt32 *aTabIndex) { return _to GetTabIndex(aTabIndex); } \
  NS_SCRIPTABLE NS_IMETHOD SetTabIndex(PRInt32 aTabIndex) { return _to SetTabIndex(aTabIndex); } 

/* Use this macro to declare functions that forward the behavior of this interface to another object in a safe way. */
#define NS_FORWARD_SAFE_NSIDOMXULCONTROLELEMENT(_to) \
  NS_SCRIPTABLE NS_IMETHOD GetDisabled(PRBool *aDisabled) { return !_to ? NS_ERROR_NULL_POINTER : _to->GetDisabled(aDisabled); } \
  NS_SCRIPTABLE NS_IMETHOD SetDisabled(PRBool aDisabled) { return !_to ? NS_ERROR_NULL_POINTER : _to->SetDisabled(aDisabled); } \
  NS_SCRIPTABLE NS_IMETHOD GetTabIndex(PRInt32 *aTabIndex) { return !_to ? NS_ERROR_NULL_POINTER : _to->GetTabIndex(aTabIndex); } \
  NS_SCRIPTABLE NS_IMETHOD SetTabIndex(PRInt32 aTabIndex) { return !_to ? NS_ERROR_NULL_POINTER : _to->SetTabIndex(aTabIndex); } 

#if 0
/* Use the code below as a template for the implementation class for this interface. */

/* Header file */
class nsDOMXULControlElement : public nsIDOMXULControlElement
{
public:
  NS_DECL_ISUPPORTS
  NS_DECL_NSIDOMXULCONTROLELEMENT

  nsDOMXULControlElement();

private:
  ~nsDOMXULControlElement();

protected:
  /* additional members */
};

/* Implementation file */
NS_IMPL_ISUPPORTS1(nsDOMXULControlElement, nsIDOMXULControlElement)

nsDOMXULControlElement::nsDOMXULControlElement()
{
  /* member initializers and constructor code */
}

nsDOMXULControlElement::~nsDOMXULControlElement()
{
  /* destructor code */
}

/* attribute boolean disabled; */
NS_IMETHODIMP nsDOMXULControlElement::GetDisabled(PRBool *aDisabled)
{
    return NS_ERROR_NOT_IMPLEMENTED;
}
NS_IMETHODIMP nsDOMXULControlElement::SetDisabled(PRBool aDisabled)
{
    return NS_ERROR_NOT_IMPLEMENTED;
}

/* attribute long tabIndex; */
NS_IMETHODIMP nsDOMXULControlElement::GetTabIndex(PRInt32 *aTabIndex)
{
    return NS_ERROR_NOT_IMPLEMENTED;
}
NS_IMETHODIMP nsDOMXULControlElement::SetTabIndex(PRInt32 aTabIndex)
{
    return NS_ERROR_NOT_IMPLEMENTED;
}

/* End of implementation class template. */
#endif


#endif /* __gen_nsIDOMXULControlElement_h__ */
