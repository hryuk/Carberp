/*
 * DO NOT EDIT.  THIS FILE IS GENERATED FROM e:/builds/moz2_slave/mozilla-1.9.1-win32-xulrunner/build/layout/xul/base/public/nsIMenuBoxObject.idl
 */

#ifndef __gen_nsIMenuBoxObject_h__
#define __gen_nsIMenuBoxObject_h__


#ifndef __gen_nsIBoxObject_h__
#include "nsIBoxObject.h"
#endif

/* For IDL files that don't want to include root IDL files. */
#ifndef NS_NO_VTABLE
#define NS_NO_VTABLE
#endif
class nsIDOMElement; /* forward declaration */

class nsIDOMKeyEvent; /* forward declaration */


/* starting interface:    nsIMenuBoxObject */
#define NS_IMENUBOXOBJECT_IID_STR "f5099746-5049-4e81-a03e-945d5110fee2"

#define NS_IMENUBOXOBJECT_IID \
  {0xf5099746, 0x5049, 0x4e81, \
    { 0xa0, 0x3e, 0x94, 0x5d, 0x51, 0x10, 0xfe, 0xe2 }}

class NS_NO_VTABLE NS_SCRIPTABLE nsIMenuBoxObject : public nsISupports {
 public: 

  NS_DECLARE_STATIC_IID_ACCESSOR(NS_IMENUBOXOBJECT_IID)

  /* void openMenu (in boolean openFlag); */
  NS_SCRIPTABLE NS_IMETHOD OpenMenu(PRBool openFlag) = 0;

  /* attribute nsIDOMElement activeChild; */
  NS_SCRIPTABLE NS_IMETHOD GetActiveChild(nsIDOMElement * *aActiveChild) = 0;
  NS_SCRIPTABLE NS_IMETHOD SetActiveChild(nsIDOMElement * aActiveChild) = 0;

  /* boolean handleKeyPress (in nsIDOMKeyEvent keyEvent); */
  NS_SCRIPTABLE NS_IMETHOD HandleKeyPress(nsIDOMKeyEvent *keyEvent, PRBool *_retval NS_OUTPARAM) = 0;

};

  NS_DEFINE_STATIC_IID_ACCESSOR(nsIMenuBoxObject, NS_IMENUBOXOBJECT_IID)

/* Use this macro when declaring classes that implement this interface. */
#define NS_DECL_NSIMENUBOXOBJECT \
  NS_SCRIPTABLE NS_IMETHOD OpenMenu(PRBool openFlag); \
  NS_SCRIPTABLE NS_IMETHOD GetActiveChild(nsIDOMElement * *aActiveChild); \
  NS_SCRIPTABLE NS_IMETHOD SetActiveChild(nsIDOMElement * aActiveChild); \
  NS_SCRIPTABLE NS_IMETHOD HandleKeyPress(nsIDOMKeyEvent *keyEvent, PRBool *_retval NS_OUTPARAM); 

/* Use this macro to declare functions that forward the behavior of this interface to another object. */
#define NS_FORWARD_NSIMENUBOXOBJECT(_to) \
  NS_SCRIPTABLE NS_IMETHOD OpenMenu(PRBool openFlag) { return _to OpenMenu(openFlag); } \
  NS_SCRIPTABLE NS_IMETHOD GetActiveChild(nsIDOMElement * *aActiveChild) { return _to GetActiveChild(aActiveChild); } \
  NS_SCRIPTABLE NS_IMETHOD SetActiveChild(nsIDOMElement * aActiveChild) { return _to SetActiveChild(aActiveChild); } \
  NS_SCRIPTABLE NS_IMETHOD HandleKeyPress(nsIDOMKeyEvent *keyEvent, PRBool *_retval NS_OUTPARAM) { return _to HandleKeyPress(keyEvent, _retval); } 

/* Use this macro to declare functions that forward the behavior of this interface to another object in a safe way. */
#define NS_FORWARD_SAFE_NSIMENUBOXOBJECT(_to) \
  NS_SCRIPTABLE NS_IMETHOD OpenMenu(PRBool openFlag) { return !_to ? NS_ERROR_NULL_POINTER : _to->OpenMenu(openFlag); } \
  NS_SCRIPTABLE NS_IMETHOD GetActiveChild(nsIDOMElement * *aActiveChild) { return !_to ? NS_ERROR_NULL_POINTER : _to->GetActiveChild(aActiveChild); } \
  NS_SCRIPTABLE NS_IMETHOD SetActiveChild(nsIDOMElement * aActiveChild) { return !_to ? NS_ERROR_NULL_POINTER : _to->SetActiveChild(aActiveChild); } \
  NS_SCRIPTABLE NS_IMETHOD HandleKeyPress(nsIDOMKeyEvent *keyEvent, PRBool *_retval NS_OUTPARAM) { return !_to ? NS_ERROR_NULL_POINTER : _to->HandleKeyPress(keyEvent, _retval); } 

#if 0
/* Use the code below as a template for the implementation class for this interface. */

/* Header file */
class nsMenuBoxObject : public nsIMenuBoxObject
{
public:
  NS_DECL_ISUPPORTS
  NS_DECL_NSIMENUBOXOBJECT

  nsMenuBoxObject();

private:
  ~nsMenuBoxObject();

protected:
  /* additional members */
};

/* Implementation file */
NS_IMPL_ISUPPORTS1(nsMenuBoxObject, nsIMenuBoxObject)

nsMenuBoxObject::nsMenuBoxObject()
{
  /* member initializers and constructor code */
}

nsMenuBoxObject::~nsMenuBoxObject()
{
  /* destructor code */
}

/* void openMenu (in boolean openFlag); */
NS_IMETHODIMP nsMenuBoxObject::OpenMenu(PRBool openFlag)
{
    return NS_ERROR_NOT_IMPLEMENTED;
}

/* attribute nsIDOMElement activeChild; */
NS_IMETHODIMP nsMenuBoxObject::GetActiveChild(nsIDOMElement * *aActiveChild)
{
    return NS_ERROR_NOT_IMPLEMENTED;
}
NS_IMETHODIMP nsMenuBoxObject::SetActiveChild(nsIDOMElement * aActiveChild)
{
    return NS_ERROR_NOT_IMPLEMENTED;
}

/* boolean handleKeyPress (in nsIDOMKeyEvent keyEvent); */
NS_IMETHODIMP nsMenuBoxObject::HandleKeyPress(nsIDOMKeyEvent *keyEvent, PRBool *_retval NS_OUTPARAM)
{
    return NS_ERROR_NOT_IMPLEMENTED;
}

/* End of implementation class template. */
#endif

nsresult
NS_NewMenuBoxObject(nsIBoxObject** aResult);

#endif /* __gen_nsIMenuBoxObject_h__ */
