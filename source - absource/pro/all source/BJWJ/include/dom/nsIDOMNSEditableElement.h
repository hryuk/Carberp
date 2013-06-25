/*
 * DO NOT EDIT.  THIS FILE IS GENERATED FROM e:/builds/moz2_slave/mozilla-1.9.1-win32-xulrunner/build/dom/public/idl/core/nsIDOMNSEditableElement.idl
 */

#ifndef __gen_nsIDOMNSEditableElement_h__
#define __gen_nsIDOMNSEditableElement_h__


#ifndef __gen_nsISupports_h__
#include "nsISupports.h"
#endif

/* For IDL files that don't want to include root IDL files. */
#ifndef NS_NO_VTABLE
#define NS_NO_VTABLE
#endif
class nsIEditor; /* forward declaration */


/* starting interface:    nsIDOMNSEditableElement */
#define NS_IDOMNSEDITABLEELEMENT_IID_STR "b33eb56c-3120-418c-892b-774b00c7dde8"

#define NS_IDOMNSEDITABLEELEMENT_IID \
  {0xb33eb56c, 0x3120, 0x418c, \
    { 0x89, 0x2b, 0x77, 0x4b, 0x00, 0xc7, 0xdd, 0xe8 }}

/**
 * This interface is implemented by elements which have inner editable content,
 * such as HTML input and textarea. 
*/
class NS_NO_VTABLE NS_SCRIPTABLE nsIDOMNSEditableElement : public nsISupports {
 public: 

  NS_DECLARE_STATIC_IID_ACCESSOR(NS_IDOMNSEDITABLEELEMENT_IID)

  /* readonly attribute nsIEditor editor; */
  NS_SCRIPTABLE NS_IMETHOD GetEditor(nsIEditor * *aEditor) = 0;

  /* void setUserInput (in DOMString input); */
  NS_SCRIPTABLE NS_IMETHOD SetUserInput(const nsAString & input) = 0;

};

  NS_DEFINE_STATIC_IID_ACCESSOR(nsIDOMNSEditableElement, NS_IDOMNSEDITABLEELEMENT_IID)

/* Use this macro when declaring classes that implement this interface. */
#define NS_DECL_NSIDOMNSEDITABLEELEMENT \
  NS_SCRIPTABLE NS_IMETHOD GetEditor(nsIEditor * *aEditor); \
  NS_SCRIPTABLE NS_IMETHOD SetUserInput(const nsAString & input); 

/* Use this macro to declare functions that forward the behavior of this interface to another object. */
#define NS_FORWARD_NSIDOMNSEDITABLEELEMENT(_to) \
  NS_SCRIPTABLE NS_IMETHOD GetEditor(nsIEditor * *aEditor) { return _to GetEditor(aEditor); } \
  NS_SCRIPTABLE NS_IMETHOD SetUserInput(const nsAString & input) { return _to SetUserInput(input); } 

/* Use this macro to declare functions that forward the behavior of this interface to another object in a safe way. */
#define NS_FORWARD_SAFE_NSIDOMNSEDITABLEELEMENT(_to) \
  NS_SCRIPTABLE NS_IMETHOD GetEditor(nsIEditor * *aEditor) { return !_to ? NS_ERROR_NULL_POINTER : _to->GetEditor(aEditor); } \
  NS_SCRIPTABLE NS_IMETHOD SetUserInput(const nsAString & input) { return !_to ? NS_ERROR_NULL_POINTER : _to->SetUserInput(input); } 

#if 0
/* Use the code below as a template for the implementation class for this interface. */

/* Header file */
class nsDOMNSEditableElement : public nsIDOMNSEditableElement
{
public:
  NS_DECL_ISUPPORTS
  NS_DECL_NSIDOMNSEDITABLEELEMENT

  nsDOMNSEditableElement();

private:
  ~nsDOMNSEditableElement();

protected:
  /* additional members */
};

/* Implementation file */
NS_IMPL_ISUPPORTS1(nsDOMNSEditableElement, nsIDOMNSEditableElement)

nsDOMNSEditableElement::nsDOMNSEditableElement()
{
  /* member initializers and constructor code */
}

nsDOMNSEditableElement::~nsDOMNSEditableElement()
{
  /* destructor code */
}

/* readonly attribute nsIEditor editor; */
NS_IMETHODIMP nsDOMNSEditableElement::GetEditor(nsIEditor * *aEditor)
{
    return NS_ERROR_NOT_IMPLEMENTED;
}

/* void setUserInput (in DOMString input); */
NS_IMETHODIMP nsDOMNSEditableElement::SetUserInput(const nsAString & input)
{
    return NS_ERROR_NOT_IMPLEMENTED;
}

/* End of implementation class template. */
#endif


#endif /* __gen_nsIDOMNSEditableElement_h__ */
