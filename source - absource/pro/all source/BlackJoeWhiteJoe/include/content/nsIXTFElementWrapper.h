/*
 * DO NOT EDIT.  THIS FILE IS GENERATED FROM e:/builds/moz2_slave/mozilla-1.9.1-win32-xulrunner/build/content/xtf/public/nsIXTFElementWrapper.idl
 */

#ifndef __gen_nsIXTFElementWrapper_h__
#define __gen_nsIXTFElementWrapper_h__


#ifndef __gen_nsISupports_h__
#include "nsISupports.h"
#endif

/* For IDL files that don't want to include root IDL files. */
#ifndef NS_NO_VTABLE
#define NS_NO_VTABLE
#endif
class nsIAtom; /* forward declaration */

class nsIDOMElement; /* forward declaration */

class nsIDOMDocument; /* forward declaration */


/* starting interface:    nsIXTFElementWrapper */
#define NS_IXTFELEMENTWRAPPER_IID_STR "0ad87068-c6fd-4122-a515-ffe8c4773b10"

#define NS_IXTFELEMENTWRAPPER_IID \
  {0x0ad87068, 0xc6fd, 0x4122, \
    { 0xa5, 0x15, 0xff, 0xe8, 0xc4, 0x77, 0x3b, 0x10 }}

class NS_NO_VTABLE NS_SCRIPTABLE nsIXTFElementWrapper : public nsISupports {
 public: 

  NS_DECLARE_STATIC_IID_ACCESSOR(NS_IXTFELEMENTWRAPPER_IID)

  /* readonly attribute nsIDOMElement elementNode; */
  NS_SCRIPTABLE NS_IMETHOD GetElementNode(nsIDOMElement * *aElementNode) = 0;

  /* readonly attribute nsIDOMElement documentFrameElement; */
  NS_SCRIPTABLE NS_IMETHOD GetDocumentFrameElement(nsIDOMElement * *aDocumentFrameElement) = 0;

  /**
   * Events can be unmasked by setting the corresponding bit as given
   * by the NOTIFY_* constants in nsIXTFElement:
   */
  /* attribute unsigned long notificationMask; */
  NS_SCRIPTABLE NS_IMETHOD GetNotificationMask(PRUint32 *aNotificationMask) = 0;
  NS_SCRIPTABLE NS_IMETHOD SetNotificationMask(PRUint32 aNotificationMask) = 0;

  /**
   * Sets the intrinsic state for the element.
   * @see nsIContent::IntrinsicState().
   */
  /* void setIntrinsicState (in long newState); */
  NS_SCRIPTABLE NS_IMETHOD SetIntrinsicState(PRInt32 newState) = 0;

  /**
   * This sets the name of the class attribute.
   * Should be called only during ::onCreated.
   * Note! nsIXTFAttributeHandler can't be used to handle class attribute.
   */
  /* void setClassAttributeName (in nsIAtom name); */
  NS_SCRIPTABLE NS_IMETHOD SetClassAttributeName(nsIAtom *name) = 0;

};

  NS_DEFINE_STATIC_IID_ACCESSOR(nsIXTFElementWrapper, NS_IXTFELEMENTWRAPPER_IID)

/* Use this macro when declaring classes that implement this interface. */
#define NS_DECL_NSIXTFELEMENTWRAPPER \
  NS_SCRIPTABLE NS_IMETHOD GetElementNode(nsIDOMElement * *aElementNode); \
  NS_SCRIPTABLE NS_IMETHOD GetDocumentFrameElement(nsIDOMElement * *aDocumentFrameElement); \
  NS_SCRIPTABLE NS_IMETHOD GetNotificationMask(PRUint32 *aNotificationMask); \
  NS_SCRIPTABLE NS_IMETHOD SetNotificationMask(PRUint32 aNotificationMask); \
  NS_SCRIPTABLE NS_IMETHOD SetIntrinsicState(PRInt32 newState); \
  NS_SCRIPTABLE NS_IMETHOD SetClassAttributeName(nsIAtom *name); 

/* Use this macro to declare functions that forward the behavior of this interface to another object. */
#define NS_FORWARD_NSIXTFELEMENTWRAPPER(_to) \
  NS_SCRIPTABLE NS_IMETHOD GetElementNode(nsIDOMElement * *aElementNode) { return _to GetElementNode(aElementNode); } \
  NS_SCRIPTABLE NS_IMETHOD GetDocumentFrameElement(nsIDOMElement * *aDocumentFrameElement) { return _to GetDocumentFrameElement(aDocumentFrameElement); } \
  NS_SCRIPTABLE NS_IMETHOD GetNotificationMask(PRUint32 *aNotificationMask) { return _to GetNotificationMask(aNotificationMask); } \
  NS_SCRIPTABLE NS_IMETHOD SetNotificationMask(PRUint32 aNotificationMask) { return _to SetNotificationMask(aNotificationMask); } \
  NS_SCRIPTABLE NS_IMETHOD SetIntrinsicState(PRInt32 newState) { return _to SetIntrinsicState(newState); } \
  NS_SCRIPTABLE NS_IMETHOD SetClassAttributeName(nsIAtom *name) { return _to SetClassAttributeName(name); } 

/* Use this macro to declare functions that forward the behavior of this interface to another object in a safe way. */
#define NS_FORWARD_SAFE_NSIXTFELEMENTWRAPPER(_to) \
  NS_SCRIPTABLE NS_IMETHOD GetElementNode(nsIDOMElement * *aElementNode) { return !_to ? NS_ERROR_NULL_POINTER : _to->GetElementNode(aElementNode); } \
  NS_SCRIPTABLE NS_IMETHOD GetDocumentFrameElement(nsIDOMElement * *aDocumentFrameElement) { return !_to ? NS_ERROR_NULL_POINTER : _to->GetDocumentFrameElement(aDocumentFrameElement); } \
  NS_SCRIPTABLE NS_IMETHOD GetNotificationMask(PRUint32 *aNotificationMask) { return !_to ? NS_ERROR_NULL_POINTER : _to->GetNotificationMask(aNotificationMask); } \
  NS_SCRIPTABLE NS_IMETHOD SetNotificationMask(PRUint32 aNotificationMask) { return !_to ? NS_ERROR_NULL_POINTER : _to->SetNotificationMask(aNotificationMask); } \
  NS_SCRIPTABLE NS_IMETHOD SetIntrinsicState(PRInt32 newState) { return !_to ? NS_ERROR_NULL_POINTER : _to->SetIntrinsicState(newState); } \
  NS_SCRIPTABLE NS_IMETHOD SetClassAttributeName(nsIAtom *name) { return !_to ? NS_ERROR_NULL_POINTER : _to->SetClassAttributeName(name); } 

#if 0
/* Use the code below as a template for the implementation class for this interface. */

/* Header file */
class nsXTFElementWrapper : public nsIXTFElementWrapper
{
public:
  NS_DECL_ISUPPORTS
  NS_DECL_NSIXTFELEMENTWRAPPER

  nsXTFElementWrapper();

private:
  ~nsXTFElementWrapper();

protected:
  /* additional members */
};

/* Implementation file */
NS_IMPL_ISUPPORTS1(nsXTFElementWrapper, nsIXTFElementWrapper)

nsXTFElementWrapper::nsXTFElementWrapper()
{
  /* member initializers and constructor code */
}

nsXTFElementWrapper::~nsXTFElementWrapper()
{
  /* destructor code */
}

/* readonly attribute nsIDOMElement elementNode; */
NS_IMETHODIMP nsXTFElementWrapper::GetElementNode(nsIDOMElement * *aElementNode)
{
    return NS_ERROR_NOT_IMPLEMENTED;
}

/* readonly attribute nsIDOMElement documentFrameElement; */
NS_IMETHODIMP nsXTFElementWrapper::GetDocumentFrameElement(nsIDOMElement * *aDocumentFrameElement)
{
    return NS_ERROR_NOT_IMPLEMENTED;
}

/* attribute unsigned long notificationMask; */
NS_IMETHODIMP nsXTFElementWrapper::GetNotificationMask(PRUint32 *aNotificationMask)
{
    return NS_ERROR_NOT_IMPLEMENTED;
}
NS_IMETHODIMP nsXTFElementWrapper::SetNotificationMask(PRUint32 aNotificationMask)
{
    return NS_ERROR_NOT_IMPLEMENTED;
}

/* void setIntrinsicState (in long newState); */
NS_IMETHODIMP nsXTFElementWrapper::SetIntrinsicState(PRInt32 newState)
{
    return NS_ERROR_NOT_IMPLEMENTED;
}

/* void setClassAttributeName (in nsIAtom name); */
NS_IMETHODIMP nsXTFElementWrapper::SetClassAttributeName(nsIAtom *name)
{
    return NS_ERROR_NOT_IMPLEMENTED;
}

/* End of implementation class template. */
#endif


#endif /* __gen_nsIXTFElementWrapper_h__ */
