/*
 * DO NOT EDIT.  THIS FILE IS GENERATED FROM e:/builds/moz2_slave/mozilla-1.9.1-win32-xulrunner/build/dom/public/idl/xul/nsIDOMXULTreeElement.idl
 */

#ifndef __gen_nsIDOMXULTreeElement_h__
#define __gen_nsIDOMXULTreeElement_h__


#ifndef __gen_nsIDOMXULElement_h__
#include "nsIDOMXULElement.h"
#endif

#ifndef __gen_nsIDOMElement_h__
#include "nsIDOMElement.h"
#endif

/* For IDL files that don't want to include root IDL files. */
#ifndef NS_NO_VTABLE
#define NS_NO_VTABLE
#endif
class nsITreeColumns; /* forward declaration */

class nsITreeView; /* forward declaration */

class nsIDOMXULTextBoxElement; /* forward declaration */


/* starting interface:    nsIDOMXULTreeElement */
#define NS_IDOMXULTREEELEMENT_IID_STR "1f8111b2-d44d-4d11-845a-a70ae06b7d04"

#define NS_IDOMXULTREEELEMENT_IID \
  {0x1f8111b2, 0xd44d, 0x4d11, \
    { 0x84, 0x5a, 0xa7, 0x0a, 0xe0, 0x6b, 0x7d, 0x04 }}

/**
 * @status UNDER_DEVELOPMENT
 */
class NS_NO_VTABLE NS_SCRIPTABLE nsIDOMXULTreeElement : public nsIDOMXULElement {
 public: 

  NS_DECLARE_STATIC_IID_ACCESSOR(NS_IDOMXULTREEELEMENT_IID)

  /* readonly attribute nsITreeColumns columns; */
  NS_SCRIPTABLE NS_IMETHOD GetColumns(nsITreeColumns * *aColumns) = 0;

  /* attribute nsITreeView view; */
  NS_SCRIPTABLE NS_IMETHOD GetView(nsITreeView * *aView) = 0;
  NS_SCRIPTABLE NS_IMETHOD SetView(nsITreeView * aView) = 0;

  /* readonly attribute nsIDOMElement body; */
  NS_SCRIPTABLE NS_IMETHOD GetBody(nsIDOMElement * *aBody) = 0;

  /* attribute boolean editable; */
  NS_SCRIPTABLE NS_IMETHOD GetEditable(PRBool *aEditable) = 0;
  NS_SCRIPTABLE NS_IMETHOD SetEditable(PRBool aEditable) = 0;

  /* readonly attribute nsIDOMXULTextBoxElement inputField; */
  NS_SCRIPTABLE NS_IMETHOD GetInputField(nsIDOMXULTextBoxElement * *aInputField) = 0;

};

  NS_DEFINE_STATIC_IID_ACCESSOR(nsIDOMXULTreeElement, NS_IDOMXULTREEELEMENT_IID)

/* Use this macro when declaring classes that implement this interface. */
#define NS_DECL_NSIDOMXULTREEELEMENT \
  NS_SCRIPTABLE NS_IMETHOD GetColumns(nsITreeColumns * *aColumns); \
  NS_SCRIPTABLE NS_IMETHOD GetView(nsITreeView * *aView); \
  NS_SCRIPTABLE NS_IMETHOD SetView(nsITreeView * aView); \
  NS_SCRIPTABLE NS_IMETHOD GetBody(nsIDOMElement * *aBody); \
  NS_SCRIPTABLE NS_IMETHOD GetEditable(PRBool *aEditable); \
  NS_SCRIPTABLE NS_IMETHOD SetEditable(PRBool aEditable); \
  NS_SCRIPTABLE NS_IMETHOD GetInputField(nsIDOMXULTextBoxElement * *aInputField); 

/* Use this macro to declare functions that forward the behavior of this interface to another object. */
#define NS_FORWARD_NSIDOMXULTREEELEMENT(_to) \
  NS_SCRIPTABLE NS_IMETHOD GetColumns(nsITreeColumns * *aColumns) { return _to GetColumns(aColumns); } \
  NS_SCRIPTABLE NS_IMETHOD GetView(nsITreeView * *aView) { return _to GetView(aView); } \
  NS_SCRIPTABLE NS_IMETHOD SetView(nsITreeView * aView) { return _to SetView(aView); } \
  NS_SCRIPTABLE NS_IMETHOD GetBody(nsIDOMElement * *aBody) { return _to GetBody(aBody); } \
  NS_SCRIPTABLE NS_IMETHOD GetEditable(PRBool *aEditable) { return _to GetEditable(aEditable); } \
  NS_SCRIPTABLE NS_IMETHOD SetEditable(PRBool aEditable) { return _to SetEditable(aEditable); } \
  NS_SCRIPTABLE NS_IMETHOD GetInputField(nsIDOMXULTextBoxElement * *aInputField) { return _to GetInputField(aInputField); } 

/* Use this macro to declare functions that forward the behavior of this interface to another object in a safe way. */
#define NS_FORWARD_SAFE_NSIDOMXULTREEELEMENT(_to) \
  NS_SCRIPTABLE NS_IMETHOD GetColumns(nsITreeColumns * *aColumns) { return !_to ? NS_ERROR_NULL_POINTER : _to->GetColumns(aColumns); } \
  NS_SCRIPTABLE NS_IMETHOD GetView(nsITreeView * *aView) { return !_to ? NS_ERROR_NULL_POINTER : _to->GetView(aView); } \
  NS_SCRIPTABLE NS_IMETHOD SetView(nsITreeView * aView) { return !_to ? NS_ERROR_NULL_POINTER : _to->SetView(aView); } \
  NS_SCRIPTABLE NS_IMETHOD GetBody(nsIDOMElement * *aBody) { return !_to ? NS_ERROR_NULL_POINTER : _to->GetBody(aBody); } \
  NS_SCRIPTABLE NS_IMETHOD GetEditable(PRBool *aEditable) { return !_to ? NS_ERROR_NULL_POINTER : _to->GetEditable(aEditable); } \
  NS_SCRIPTABLE NS_IMETHOD SetEditable(PRBool aEditable) { return !_to ? NS_ERROR_NULL_POINTER : _to->SetEditable(aEditable); } \
  NS_SCRIPTABLE NS_IMETHOD GetInputField(nsIDOMXULTextBoxElement * *aInputField) { return !_to ? NS_ERROR_NULL_POINTER : _to->GetInputField(aInputField); } 

#if 0
/* Use the code below as a template for the implementation class for this interface. */

/* Header file */
class nsDOMXULTreeElement : public nsIDOMXULTreeElement
{
public:
  NS_DECL_ISUPPORTS
  NS_DECL_NSIDOMXULTREEELEMENT

  nsDOMXULTreeElement();

private:
  ~nsDOMXULTreeElement();

protected:
  /* additional members */
};

/* Implementation file */
NS_IMPL_ISUPPORTS1(nsDOMXULTreeElement, nsIDOMXULTreeElement)

nsDOMXULTreeElement::nsDOMXULTreeElement()
{
  /* member initializers and constructor code */
}

nsDOMXULTreeElement::~nsDOMXULTreeElement()
{
  /* destructor code */
}

/* readonly attribute nsITreeColumns columns; */
NS_IMETHODIMP nsDOMXULTreeElement::GetColumns(nsITreeColumns * *aColumns)
{
    return NS_ERROR_NOT_IMPLEMENTED;
}

/* attribute nsITreeView view; */
NS_IMETHODIMP nsDOMXULTreeElement::GetView(nsITreeView * *aView)
{
    return NS_ERROR_NOT_IMPLEMENTED;
}
NS_IMETHODIMP nsDOMXULTreeElement::SetView(nsITreeView * aView)
{
    return NS_ERROR_NOT_IMPLEMENTED;
}

/* readonly attribute nsIDOMElement body; */
NS_IMETHODIMP nsDOMXULTreeElement::GetBody(nsIDOMElement * *aBody)
{
    return NS_ERROR_NOT_IMPLEMENTED;
}

/* attribute boolean editable; */
NS_IMETHODIMP nsDOMXULTreeElement::GetEditable(PRBool *aEditable)
{
    return NS_ERROR_NOT_IMPLEMENTED;
}
NS_IMETHODIMP nsDOMXULTreeElement::SetEditable(PRBool aEditable)
{
    return NS_ERROR_NOT_IMPLEMENTED;
}

/* readonly attribute nsIDOMXULTextBoxElement inputField; */
NS_IMETHODIMP nsDOMXULTreeElement::GetInputField(nsIDOMXULTextBoxElement * *aInputField)
{
    return NS_ERROR_NOT_IMPLEMENTED;
}

/* End of implementation class template. */
#endif


#endif /* __gen_nsIDOMXULTreeElement_h__ */
