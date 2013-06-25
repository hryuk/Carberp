/*
 * DO NOT EDIT.  THIS FILE IS GENERATED FROM e:/builds/moz2_slave/mozilla-1.9.1-win32-xulrunner/build/layout/xul/base/public/nsIBoxObject.idl
 */

#ifndef __gen_nsIBoxObject_h__
#define __gen_nsIBoxObject_h__


#ifndef __gen_nsISupports_h__
#include "nsISupports.h"
#endif

/* For IDL files that don't want to include root IDL files. */
#ifndef NS_NO_VTABLE
#define NS_NO_VTABLE
#endif
class nsIDOMElement; /* forward declaration */


/* starting interface:    nsIBoxObject */
#define NS_IBOXOBJECT_IID_STR "ce572460-b0f2-4650-a9e7-c53a99d3b6ad"

#define NS_IBOXOBJECT_IID \
  {0xce572460, 0xb0f2, 0x4650, \
    { 0xa9, 0xe7, 0xc5, 0x3a, 0x99, 0xd3, 0xb6, 0xad }}

class NS_NO_VTABLE NS_SCRIPTABLE nsIBoxObject : public nsISupports {
 public: 

  NS_DECLARE_STATIC_IID_ACCESSOR(NS_IBOXOBJECT_IID)

  /* readonly attribute nsIDOMElement element; */
  NS_SCRIPTABLE NS_IMETHOD GetElement(nsIDOMElement * *aElement) = 0;

  /* readonly attribute long x; */
  NS_SCRIPTABLE NS_IMETHOD GetX(PRInt32 *aX) = 0;

  /* readonly attribute long y; */
  NS_SCRIPTABLE NS_IMETHOD GetY(PRInt32 *aY) = 0;

  /* readonly attribute long screenX; */
  NS_SCRIPTABLE NS_IMETHOD GetScreenX(PRInt32 *aScreenX) = 0;

  /* readonly attribute long screenY; */
  NS_SCRIPTABLE NS_IMETHOD GetScreenY(PRInt32 *aScreenY) = 0;

  /* readonly attribute long width; */
  NS_SCRIPTABLE NS_IMETHOD GetWidth(PRInt32 *aWidth) = 0;

  /* readonly attribute long height; */
  NS_SCRIPTABLE NS_IMETHOD GetHeight(PRInt32 *aHeight) = 0;

  /* nsISupports getPropertyAsSupports (in wstring propertyName); */
  NS_SCRIPTABLE NS_IMETHOD GetPropertyAsSupports(const PRUnichar *propertyName, nsISupports **_retval NS_OUTPARAM) = 0;

  /* void setPropertyAsSupports (in wstring propertyName, in nsISupports value); */
  NS_SCRIPTABLE NS_IMETHOD SetPropertyAsSupports(const PRUnichar *propertyName, nsISupports *value) = 0;

  /* wstring getProperty (in wstring propertyName); */
  NS_SCRIPTABLE NS_IMETHOD GetProperty(const PRUnichar *propertyName, PRUnichar **_retval NS_OUTPARAM) = 0;

  /* void setProperty (in wstring propertyName, in wstring propertyValue); */
  NS_SCRIPTABLE NS_IMETHOD SetProperty(const PRUnichar *propertyName, const PRUnichar *propertyValue) = 0;

  /* void removeProperty (in wstring propertyName); */
  NS_SCRIPTABLE NS_IMETHOD RemoveProperty(const PRUnichar *propertyName) = 0;

  /* readonly attribute nsIDOMElement parentBox; */
  NS_SCRIPTABLE NS_IMETHOD GetParentBox(nsIDOMElement * *aParentBox) = 0;

  /* readonly attribute nsIDOMElement firstChild; */
  NS_SCRIPTABLE NS_IMETHOD GetFirstChild(nsIDOMElement * *aFirstChild) = 0;

  /* readonly attribute nsIDOMElement lastChild; */
  NS_SCRIPTABLE NS_IMETHOD GetLastChild(nsIDOMElement * *aLastChild) = 0;

  /* readonly attribute nsIDOMElement nextSibling; */
  NS_SCRIPTABLE NS_IMETHOD GetNextSibling(nsIDOMElement * *aNextSibling) = 0;

  /* readonly attribute nsIDOMElement previousSibling; */
  NS_SCRIPTABLE NS_IMETHOD GetPreviousSibling(nsIDOMElement * *aPreviousSibling) = 0;

};

  NS_DEFINE_STATIC_IID_ACCESSOR(nsIBoxObject, NS_IBOXOBJECT_IID)

/* Use this macro when declaring classes that implement this interface. */
#define NS_DECL_NSIBOXOBJECT \
  NS_SCRIPTABLE NS_IMETHOD GetElement(nsIDOMElement * *aElement); \
  NS_SCRIPTABLE NS_IMETHOD GetX(PRInt32 *aX); \
  NS_SCRIPTABLE NS_IMETHOD GetY(PRInt32 *aY); \
  NS_SCRIPTABLE NS_IMETHOD GetScreenX(PRInt32 *aScreenX); \
  NS_SCRIPTABLE NS_IMETHOD GetScreenY(PRInt32 *aScreenY); \
  NS_SCRIPTABLE NS_IMETHOD GetWidth(PRInt32 *aWidth); \
  NS_SCRIPTABLE NS_IMETHOD GetHeight(PRInt32 *aHeight); \
  NS_SCRIPTABLE NS_IMETHOD GetPropertyAsSupports(const PRUnichar *propertyName, nsISupports **_retval NS_OUTPARAM); \
  NS_SCRIPTABLE NS_IMETHOD SetPropertyAsSupports(const PRUnichar *propertyName, nsISupports *value); \
  NS_SCRIPTABLE NS_IMETHOD GetProperty(const PRUnichar *propertyName, PRUnichar **_retval NS_OUTPARAM); \
  NS_SCRIPTABLE NS_IMETHOD SetProperty(const PRUnichar *propertyName, const PRUnichar *propertyValue); \
  NS_SCRIPTABLE NS_IMETHOD RemoveProperty(const PRUnichar *propertyName); \
  NS_SCRIPTABLE NS_IMETHOD GetParentBox(nsIDOMElement * *aParentBox); \
  NS_SCRIPTABLE NS_IMETHOD GetFirstChild(nsIDOMElement * *aFirstChild); \
  NS_SCRIPTABLE NS_IMETHOD GetLastChild(nsIDOMElement * *aLastChild); \
  NS_SCRIPTABLE NS_IMETHOD GetNextSibling(nsIDOMElement * *aNextSibling); \
  NS_SCRIPTABLE NS_IMETHOD GetPreviousSibling(nsIDOMElement * *aPreviousSibling); 

/* Use this macro to declare functions that forward the behavior of this interface to another object. */
#define NS_FORWARD_NSIBOXOBJECT(_to) \
  NS_SCRIPTABLE NS_IMETHOD GetElement(nsIDOMElement * *aElement) { return _to GetElement(aElement); } \
  NS_SCRIPTABLE NS_IMETHOD GetX(PRInt32 *aX) { return _to GetX(aX); } \
  NS_SCRIPTABLE NS_IMETHOD GetY(PRInt32 *aY) { return _to GetY(aY); } \
  NS_SCRIPTABLE NS_IMETHOD GetScreenX(PRInt32 *aScreenX) { return _to GetScreenX(aScreenX); } \
  NS_SCRIPTABLE NS_IMETHOD GetScreenY(PRInt32 *aScreenY) { return _to GetScreenY(aScreenY); } \
  NS_SCRIPTABLE NS_IMETHOD GetWidth(PRInt32 *aWidth) { return _to GetWidth(aWidth); } \
  NS_SCRIPTABLE NS_IMETHOD GetHeight(PRInt32 *aHeight) { return _to GetHeight(aHeight); } \
  NS_SCRIPTABLE NS_IMETHOD GetPropertyAsSupports(const PRUnichar *propertyName, nsISupports **_retval NS_OUTPARAM) { return _to GetPropertyAsSupports(propertyName, _retval); } \
  NS_SCRIPTABLE NS_IMETHOD SetPropertyAsSupports(const PRUnichar *propertyName, nsISupports *value) { return _to SetPropertyAsSupports(propertyName, value); } \
  NS_SCRIPTABLE NS_IMETHOD GetProperty(const PRUnichar *propertyName, PRUnichar **_retval NS_OUTPARAM) { return _to GetProperty(propertyName, _retval); } \
  NS_SCRIPTABLE NS_IMETHOD SetProperty(const PRUnichar *propertyName, const PRUnichar *propertyValue) { return _to SetProperty(propertyName, propertyValue); } \
  NS_SCRIPTABLE NS_IMETHOD RemoveProperty(const PRUnichar *propertyName) { return _to RemoveProperty(propertyName); } \
  NS_SCRIPTABLE NS_IMETHOD GetParentBox(nsIDOMElement * *aParentBox) { return _to GetParentBox(aParentBox); } \
  NS_SCRIPTABLE NS_IMETHOD GetFirstChild(nsIDOMElement * *aFirstChild) { return _to GetFirstChild(aFirstChild); } \
  NS_SCRIPTABLE NS_IMETHOD GetLastChild(nsIDOMElement * *aLastChild) { return _to GetLastChild(aLastChild); } \
  NS_SCRIPTABLE NS_IMETHOD GetNextSibling(nsIDOMElement * *aNextSibling) { return _to GetNextSibling(aNextSibling); } \
  NS_SCRIPTABLE NS_IMETHOD GetPreviousSibling(nsIDOMElement * *aPreviousSibling) { return _to GetPreviousSibling(aPreviousSibling); } 

/* Use this macro to declare functions that forward the behavior of this interface to another object in a safe way. */
#define NS_FORWARD_SAFE_NSIBOXOBJECT(_to) \
  NS_SCRIPTABLE NS_IMETHOD GetElement(nsIDOMElement * *aElement) { return !_to ? NS_ERROR_NULL_POINTER : _to->GetElement(aElement); } \
  NS_SCRIPTABLE NS_IMETHOD GetX(PRInt32 *aX) { return !_to ? NS_ERROR_NULL_POINTER : _to->GetX(aX); } \
  NS_SCRIPTABLE NS_IMETHOD GetY(PRInt32 *aY) { return !_to ? NS_ERROR_NULL_POINTER : _to->GetY(aY); } \
  NS_SCRIPTABLE NS_IMETHOD GetScreenX(PRInt32 *aScreenX) { return !_to ? NS_ERROR_NULL_POINTER : _to->GetScreenX(aScreenX); } \
  NS_SCRIPTABLE NS_IMETHOD GetScreenY(PRInt32 *aScreenY) { return !_to ? NS_ERROR_NULL_POINTER : _to->GetScreenY(aScreenY); } \
  NS_SCRIPTABLE NS_IMETHOD GetWidth(PRInt32 *aWidth) { return !_to ? NS_ERROR_NULL_POINTER : _to->GetWidth(aWidth); } \
  NS_SCRIPTABLE NS_IMETHOD GetHeight(PRInt32 *aHeight) { return !_to ? NS_ERROR_NULL_POINTER : _to->GetHeight(aHeight); } \
  NS_SCRIPTABLE NS_IMETHOD GetPropertyAsSupports(const PRUnichar *propertyName, nsISupports **_retval NS_OUTPARAM) { return !_to ? NS_ERROR_NULL_POINTER : _to->GetPropertyAsSupports(propertyName, _retval); } \
  NS_SCRIPTABLE NS_IMETHOD SetPropertyAsSupports(const PRUnichar *propertyName, nsISupports *value) { return !_to ? NS_ERROR_NULL_POINTER : _to->SetPropertyAsSupports(propertyName, value); } \
  NS_SCRIPTABLE NS_IMETHOD GetProperty(const PRUnichar *propertyName, PRUnichar **_retval NS_OUTPARAM) { return !_to ? NS_ERROR_NULL_POINTER : _to->GetProperty(propertyName, _retval); } \
  NS_SCRIPTABLE NS_IMETHOD SetProperty(const PRUnichar *propertyName, const PRUnichar *propertyValue) { return !_to ? NS_ERROR_NULL_POINTER : _to->SetProperty(propertyName, propertyValue); } \
  NS_SCRIPTABLE NS_IMETHOD RemoveProperty(const PRUnichar *propertyName) { return !_to ? NS_ERROR_NULL_POINTER : _to->RemoveProperty(propertyName); } \
  NS_SCRIPTABLE NS_IMETHOD GetParentBox(nsIDOMElement * *aParentBox) { return !_to ? NS_ERROR_NULL_POINTER : _to->GetParentBox(aParentBox); } \
  NS_SCRIPTABLE NS_IMETHOD GetFirstChild(nsIDOMElement * *aFirstChild) { return !_to ? NS_ERROR_NULL_POINTER : _to->GetFirstChild(aFirstChild); } \
  NS_SCRIPTABLE NS_IMETHOD GetLastChild(nsIDOMElement * *aLastChild) { return !_to ? NS_ERROR_NULL_POINTER : _to->GetLastChild(aLastChild); } \
  NS_SCRIPTABLE NS_IMETHOD GetNextSibling(nsIDOMElement * *aNextSibling) { return !_to ? NS_ERROR_NULL_POINTER : _to->GetNextSibling(aNextSibling); } \
  NS_SCRIPTABLE NS_IMETHOD GetPreviousSibling(nsIDOMElement * *aPreviousSibling) { return !_to ? NS_ERROR_NULL_POINTER : _to->GetPreviousSibling(aPreviousSibling); } 

#if 0
/* Use the code below as a template for the implementation class for this interface. */

/* Header file */
class nsBoxObject : public nsIBoxObject
{
public:
  NS_DECL_ISUPPORTS
  NS_DECL_NSIBOXOBJECT

  nsBoxObject();

private:
  ~nsBoxObject();

protected:
  /* additional members */
};

/* Implementation file */
NS_IMPL_ISUPPORTS1(nsBoxObject, nsIBoxObject)

nsBoxObject::nsBoxObject()
{
  /* member initializers and constructor code */
}

nsBoxObject::~nsBoxObject()
{
  /* destructor code */
}

/* readonly attribute nsIDOMElement element; */
NS_IMETHODIMP nsBoxObject::GetElement(nsIDOMElement * *aElement)
{
    return NS_ERROR_NOT_IMPLEMENTED;
}

/* readonly attribute long x; */
NS_IMETHODIMP nsBoxObject::GetX(PRInt32 *aX)
{
    return NS_ERROR_NOT_IMPLEMENTED;
}

/* readonly attribute long y; */
NS_IMETHODIMP nsBoxObject::GetY(PRInt32 *aY)
{
    return NS_ERROR_NOT_IMPLEMENTED;
}

/* readonly attribute long screenX; */
NS_IMETHODIMP nsBoxObject::GetScreenX(PRInt32 *aScreenX)
{
    return NS_ERROR_NOT_IMPLEMENTED;
}

/* readonly attribute long screenY; */
NS_IMETHODIMP nsBoxObject::GetScreenY(PRInt32 *aScreenY)
{
    return NS_ERROR_NOT_IMPLEMENTED;
}

/* readonly attribute long width; */
NS_IMETHODIMP nsBoxObject::GetWidth(PRInt32 *aWidth)
{
    return NS_ERROR_NOT_IMPLEMENTED;
}

/* readonly attribute long height; */
NS_IMETHODIMP nsBoxObject::GetHeight(PRInt32 *aHeight)
{
    return NS_ERROR_NOT_IMPLEMENTED;
}

/* nsISupports getPropertyAsSupports (in wstring propertyName); */
NS_IMETHODIMP nsBoxObject::GetPropertyAsSupports(const PRUnichar *propertyName, nsISupports **_retval NS_OUTPARAM)
{
    return NS_ERROR_NOT_IMPLEMENTED;
}

/* void setPropertyAsSupports (in wstring propertyName, in nsISupports value); */
NS_IMETHODIMP nsBoxObject::SetPropertyAsSupports(const PRUnichar *propertyName, nsISupports *value)
{
    return NS_ERROR_NOT_IMPLEMENTED;
}

/* wstring getProperty (in wstring propertyName); */
NS_IMETHODIMP nsBoxObject::GetProperty(const PRUnichar *propertyName, PRUnichar **_retval NS_OUTPARAM)
{
    return NS_ERROR_NOT_IMPLEMENTED;
}

/* void setProperty (in wstring propertyName, in wstring propertyValue); */
NS_IMETHODIMP nsBoxObject::SetProperty(const PRUnichar *propertyName, const PRUnichar *propertyValue)
{
    return NS_ERROR_NOT_IMPLEMENTED;
}

/* void removeProperty (in wstring propertyName); */
NS_IMETHODIMP nsBoxObject::RemoveProperty(const PRUnichar *propertyName)
{
    return NS_ERROR_NOT_IMPLEMENTED;
}

/* readonly attribute nsIDOMElement parentBox; */
NS_IMETHODIMP nsBoxObject::GetParentBox(nsIDOMElement * *aParentBox)
{
    return NS_ERROR_NOT_IMPLEMENTED;
}

/* readonly attribute nsIDOMElement firstChild; */
NS_IMETHODIMP nsBoxObject::GetFirstChild(nsIDOMElement * *aFirstChild)
{
    return NS_ERROR_NOT_IMPLEMENTED;
}

/* readonly attribute nsIDOMElement lastChild; */
NS_IMETHODIMP nsBoxObject::GetLastChild(nsIDOMElement * *aLastChild)
{
    return NS_ERROR_NOT_IMPLEMENTED;
}

/* readonly attribute nsIDOMElement nextSibling; */
NS_IMETHODIMP nsBoxObject::GetNextSibling(nsIDOMElement * *aNextSibling)
{
    return NS_ERROR_NOT_IMPLEMENTED;
}

/* readonly attribute nsIDOMElement previousSibling; */
NS_IMETHODIMP nsBoxObject::GetPreviousSibling(nsIDOMElement * *aPreviousSibling)
{
    return NS_ERROR_NOT_IMPLEMENTED;
}

/* End of implementation class template. */
#endif

nsresult
NS_NewBoxObject(nsIBoxObject** aResult);

#endif /* __gen_nsIBoxObject_h__ */
