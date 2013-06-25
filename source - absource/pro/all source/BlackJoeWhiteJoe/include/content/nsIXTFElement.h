/*
 * DO NOT EDIT.  THIS FILE IS GENERATED FROM e:/builds/moz2_slave/mozilla-1.9.1-win32-xulrunner/build/content/xtf/public/nsIXTFElement.idl
 */

#ifndef __gen_nsIXTFElement_h__
#define __gen_nsIXTFElement_h__


#ifndef __gen_nsISupports_h__
#include "nsISupports.h"
#endif

/* For IDL files that don't want to include root IDL files. */
#ifndef NS_NO_VTABLE
#define NS_NO_VTABLE
#endif
class nsIAtom; /* forward declaration */

class nsIDOMDocument; /* forward declaration */

class nsIDOMElement; /* forward declaration */

class nsIDOMNode; /* forward declaration */

class nsIDOMAttr; /* forward declaration */

class nsIDOMEvent; /* forward declaration */

class nsIXTFElementWrapper; /* forward declaration */


/* starting interface:    nsIXTFElement */
#define NS_IXTFELEMENT_IID_STR "4f144387-796d-4baf-8641-5db45dba1808"

#define NS_IXTFELEMENT_IID \
  {0x4f144387, 0x796d, 0x4baf, \
    { 0x86, 0x41, 0x5d, 0xb4, 0x5d, 0xba, 0x18, 0x08 }}

class NS_NO_VTABLE NS_SCRIPTABLE nsIXTFElement : public nsISupports {
 public: 

  NS_DECLARE_STATIC_IID_ACCESSOR(NS_IXTFELEMENT_IID)

  /* void onCreated (in nsIXTFElementWrapper wrapper); */
  NS_SCRIPTABLE NS_IMETHOD OnCreated(nsIXTFElementWrapper *wrapper) = 0;

  /* void onDestroyed (); */
  NS_SCRIPTABLE NS_IMETHOD OnDestroyed(void) = 0;

  /* readonly attribute boolean isAttributeHandler; */
  NS_SCRIPTABLE NS_IMETHOD GetIsAttributeHandler(PRBool *aIsAttributeHandler) = 0;

  /* void getScriptingInterfaces (out unsigned long count, [array, size_is (count), retval] out nsIIDPtr array); */
  NS_SCRIPTABLE NS_IMETHOD GetScriptingInterfaces(PRUint32 *count NS_OUTPARAM, nsIID * **array NS_OUTPARAM) = 0;

  enum { NOTIFY_WILL_CHANGE_DOCUMENT = 1U };

  enum { NOTIFY_DOCUMENT_CHANGED = 2U };

  enum { NOTIFY_WILL_CHANGE_PARENT = 4U };

  enum { NOTIFY_PARENT_CHANGED = 8U };

  enum { NOTIFY_WILL_INSERT_CHILD = 16U };

  enum { NOTIFY_CHILD_INSERTED = 32U };

  enum { NOTIFY_WILL_APPEND_CHILD = 64U };

  enum { NOTIFY_CHILD_APPENDED = 128U };

  enum { NOTIFY_WILL_REMOVE_CHILD = 256U };

  enum { NOTIFY_CHILD_REMOVED = 512U };

  enum { NOTIFY_WILL_SET_ATTRIBUTE = 1024U };

  enum { NOTIFY_ATTRIBUTE_SET = 2048U };

  enum { NOTIFY_WILL_REMOVE_ATTRIBUTE = 4096U };

  enum { NOTIFY_ATTRIBUTE_REMOVED = 8192U };

  enum { NOTIFY_BEGIN_ADDING_CHILDREN = 16384U };

  enum { NOTIFY_DONE_ADDING_CHILDREN = 32768U };

  enum { NOTIFY_HANDLE_DEFAULT = 65536U };

  enum { NOTIFY_PERFORM_ACCESSKEY = 131072U };

  /* void willChangeDocument (in nsIDOMDocument newDoc); */
  NS_SCRIPTABLE NS_IMETHOD WillChangeDocument(nsIDOMDocument *newDoc) = 0;

  /* void documentChanged (in nsIDOMDocument newDoc); */
  NS_SCRIPTABLE NS_IMETHOD DocumentChanged(nsIDOMDocument *newDoc) = 0;

  /* void willChangeParent (in nsIDOMElement newParent); */
  NS_SCRIPTABLE NS_IMETHOD WillChangeParent(nsIDOMElement *newParent) = 0;

  /* void parentChanged (in nsIDOMElement newParent); */
  NS_SCRIPTABLE NS_IMETHOD ParentChanged(nsIDOMElement *newParent) = 0;

  /* void willInsertChild (in nsIDOMNode child, in unsigned long index); */
  NS_SCRIPTABLE NS_IMETHOD WillInsertChild(nsIDOMNode *child, PRUint32 index) = 0;

  /* void childInserted (in nsIDOMNode child, in unsigned long index); */
  NS_SCRIPTABLE NS_IMETHOD ChildInserted(nsIDOMNode *child, PRUint32 index) = 0;

  /* void willAppendChild (in nsIDOMNode child); */
  NS_SCRIPTABLE NS_IMETHOD WillAppendChild(nsIDOMNode *child) = 0;

  /* void childAppended (in nsIDOMNode child); */
  NS_SCRIPTABLE NS_IMETHOD ChildAppended(nsIDOMNode *child) = 0;

  /* void willRemoveChild (in unsigned long index); */
  NS_SCRIPTABLE NS_IMETHOD WillRemoveChild(PRUint32 index) = 0;

  /* void childRemoved (in unsigned long index); */
  NS_SCRIPTABLE NS_IMETHOD ChildRemoved(PRUint32 index) = 0;

  /* void willSetAttribute (in nsIAtom name, in AString newValue); */
  NS_SCRIPTABLE NS_IMETHOD WillSetAttribute(nsIAtom *name, const nsAString & newValue) = 0;

  /* void attributeSet (in nsIAtom name, in AString newValue); */
  NS_SCRIPTABLE NS_IMETHOD AttributeSet(nsIAtom *name, const nsAString & newValue) = 0;

  /* void willRemoveAttribute (in nsIAtom name); */
  NS_SCRIPTABLE NS_IMETHOD WillRemoveAttribute(nsIAtom *name) = 0;

  /* void attributeRemoved (in nsIAtom name); */
  NS_SCRIPTABLE NS_IMETHOD AttributeRemoved(nsIAtom *name) = 0;

  /* void beginAddingChildren (); */
  NS_SCRIPTABLE NS_IMETHOD BeginAddingChildren(void) = 0;

  /* void doneAddingChildren (); */
  NS_SCRIPTABLE NS_IMETHOD DoneAddingChildren(void) = 0;

  /* boolean handleDefault (in nsIDOMEvent aEvent); */
  NS_SCRIPTABLE NS_IMETHOD HandleDefault(nsIDOMEvent *aEvent, PRBool *_retval NS_OUTPARAM) = 0;

  /* void cloneState (in nsIDOMElement aElement); */
  NS_SCRIPTABLE NS_IMETHOD CloneState(nsIDOMElement *aElement) = 0;

  /**
   * Returns accesskey attribute node.
   */
  /* readonly attribute nsIDOMAttr accesskeyNode; */
  NS_SCRIPTABLE NS_IMETHOD GetAccesskeyNode(nsIDOMAttr * *aAccesskeyNode) = 0;

  /**
   * Performs accesskey. The method is called when accesskey is activated.
   */
  /* void performAccesskey (); */
  NS_SCRIPTABLE NS_IMETHOD PerformAccesskey(void) = 0;

};

  NS_DEFINE_STATIC_IID_ACCESSOR(nsIXTFElement, NS_IXTFELEMENT_IID)

/* Use this macro when declaring classes that implement this interface. */
#define NS_DECL_NSIXTFELEMENT \
  NS_SCRIPTABLE NS_IMETHOD OnCreated(nsIXTFElementWrapper *wrapper); \
  NS_SCRIPTABLE NS_IMETHOD OnDestroyed(void); \
  NS_SCRIPTABLE NS_IMETHOD GetIsAttributeHandler(PRBool *aIsAttributeHandler); \
  NS_SCRIPTABLE NS_IMETHOD GetScriptingInterfaces(PRUint32 *count NS_OUTPARAM, nsIID * **array NS_OUTPARAM); \
  NS_SCRIPTABLE NS_IMETHOD WillChangeDocument(nsIDOMDocument *newDoc); \
  NS_SCRIPTABLE NS_IMETHOD DocumentChanged(nsIDOMDocument *newDoc); \
  NS_SCRIPTABLE NS_IMETHOD WillChangeParent(nsIDOMElement *newParent); \
  NS_SCRIPTABLE NS_IMETHOD ParentChanged(nsIDOMElement *newParent); \
  NS_SCRIPTABLE NS_IMETHOD WillInsertChild(nsIDOMNode *child, PRUint32 index); \
  NS_SCRIPTABLE NS_IMETHOD ChildInserted(nsIDOMNode *child, PRUint32 index); \
  NS_SCRIPTABLE NS_IMETHOD WillAppendChild(nsIDOMNode *child); \
  NS_SCRIPTABLE NS_IMETHOD ChildAppended(nsIDOMNode *child); \
  NS_SCRIPTABLE NS_IMETHOD WillRemoveChild(PRUint32 index); \
  NS_SCRIPTABLE NS_IMETHOD ChildRemoved(PRUint32 index); \
  NS_SCRIPTABLE NS_IMETHOD WillSetAttribute(nsIAtom *name, const nsAString & newValue); \
  NS_SCRIPTABLE NS_IMETHOD AttributeSet(nsIAtom *name, const nsAString & newValue); \
  NS_SCRIPTABLE NS_IMETHOD WillRemoveAttribute(nsIAtom *name); \
  NS_SCRIPTABLE NS_IMETHOD AttributeRemoved(nsIAtom *name); \
  NS_SCRIPTABLE NS_IMETHOD BeginAddingChildren(void); \
  NS_SCRIPTABLE NS_IMETHOD DoneAddingChildren(void); \
  NS_SCRIPTABLE NS_IMETHOD HandleDefault(nsIDOMEvent *aEvent, PRBool *_retval NS_OUTPARAM); \
  NS_SCRIPTABLE NS_IMETHOD CloneState(nsIDOMElement *aElement); \
  NS_SCRIPTABLE NS_IMETHOD GetAccesskeyNode(nsIDOMAttr * *aAccesskeyNode); \
  NS_SCRIPTABLE NS_IMETHOD PerformAccesskey(void); 

/* Use this macro to declare functions that forward the behavior of this interface to another object. */
#define NS_FORWARD_NSIXTFELEMENT(_to) \
  NS_SCRIPTABLE NS_IMETHOD OnCreated(nsIXTFElementWrapper *wrapper) { return _to OnCreated(wrapper); } \
  NS_SCRIPTABLE NS_IMETHOD OnDestroyed(void) { return _to OnDestroyed(); } \
  NS_SCRIPTABLE NS_IMETHOD GetIsAttributeHandler(PRBool *aIsAttributeHandler) { return _to GetIsAttributeHandler(aIsAttributeHandler); } \
  NS_SCRIPTABLE NS_IMETHOD GetScriptingInterfaces(PRUint32 *count NS_OUTPARAM, nsIID * **array NS_OUTPARAM) { return _to GetScriptingInterfaces(count, array); } \
  NS_SCRIPTABLE NS_IMETHOD WillChangeDocument(nsIDOMDocument *newDoc) { return _to WillChangeDocument(newDoc); } \
  NS_SCRIPTABLE NS_IMETHOD DocumentChanged(nsIDOMDocument *newDoc) { return _to DocumentChanged(newDoc); } \
  NS_SCRIPTABLE NS_IMETHOD WillChangeParent(nsIDOMElement *newParent) { return _to WillChangeParent(newParent); } \
  NS_SCRIPTABLE NS_IMETHOD ParentChanged(nsIDOMElement *newParent) { return _to ParentChanged(newParent); } \
  NS_SCRIPTABLE NS_IMETHOD WillInsertChild(nsIDOMNode *child, PRUint32 index) { return _to WillInsertChild(child, index); } \
  NS_SCRIPTABLE NS_IMETHOD ChildInserted(nsIDOMNode *child, PRUint32 index) { return _to ChildInserted(child, index); } \
  NS_SCRIPTABLE NS_IMETHOD WillAppendChild(nsIDOMNode *child) { return _to WillAppendChild(child); } \
  NS_SCRIPTABLE NS_IMETHOD ChildAppended(nsIDOMNode *child) { return _to ChildAppended(child); } \
  NS_SCRIPTABLE NS_IMETHOD WillRemoveChild(PRUint32 index) { return _to WillRemoveChild(index); } \
  NS_SCRIPTABLE NS_IMETHOD ChildRemoved(PRUint32 index) { return _to ChildRemoved(index); } \
  NS_SCRIPTABLE NS_IMETHOD WillSetAttribute(nsIAtom *name, const nsAString & newValue) { return _to WillSetAttribute(name, newValue); } \
  NS_SCRIPTABLE NS_IMETHOD AttributeSet(nsIAtom *name, const nsAString & newValue) { return _to AttributeSet(name, newValue); } \
  NS_SCRIPTABLE NS_IMETHOD WillRemoveAttribute(nsIAtom *name) { return _to WillRemoveAttribute(name); } \
  NS_SCRIPTABLE NS_IMETHOD AttributeRemoved(nsIAtom *name) { return _to AttributeRemoved(name); } \
  NS_SCRIPTABLE NS_IMETHOD BeginAddingChildren(void) { return _to BeginAddingChildren(); } \
  NS_SCRIPTABLE NS_IMETHOD DoneAddingChildren(void) { return _to DoneAddingChildren(); } \
  NS_SCRIPTABLE NS_IMETHOD HandleDefault(nsIDOMEvent *aEvent, PRBool *_retval NS_OUTPARAM) { return _to HandleDefault(aEvent, _retval); } \
  NS_SCRIPTABLE NS_IMETHOD CloneState(nsIDOMElement *aElement) { return _to CloneState(aElement); } \
  NS_SCRIPTABLE NS_IMETHOD GetAccesskeyNode(nsIDOMAttr * *aAccesskeyNode) { return _to GetAccesskeyNode(aAccesskeyNode); } \
  NS_SCRIPTABLE NS_IMETHOD PerformAccesskey(void) { return _to PerformAccesskey(); } 

/* Use this macro to declare functions that forward the behavior of this interface to another object in a safe way. */
#define NS_FORWARD_SAFE_NSIXTFELEMENT(_to) \
  NS_SCRIPTABLE NS_IMETHOD OnCreated(nsIXTFElementWrapper *wrapper) { return !_to ? NS_ERROR_NULL_POINTER : _to->OnCreated(wrapper); } \
  NS_SCRIPTABLE NS_IMETHOD OnDestroyed(void) { return !_to ? NS_ERROR_NULL_POINTER : _to->OnDestroyed(); } \
  NS_SCRIPTABLE NS_IMETHOD GetIsAttributeHandler(PRBool *aIsAttributeHandler) { return !_to ? NS_ERROR_NULL_POINTER : _to->GetIsAttributeHandler(aIsAttributeHandler); } \
  NS_SCRIPTABLE NS_IMETHOD GetScriptingInterfaces(PRUint32 *count NS_OUTPARAM, nsIID * **array NS_OUTPARAM) { return !_to ? NS_ERROR_NULL_POINTER : _to->GetScriptingInterfaces(count, array); } \
  NS_SCRIPTABLE NS_IMETHOD WillChangeDocument(nsIDOMDocument *newDoc) { return !_to ? NS_ERROR_NULL_POINTER : _to->WillChangeDocument(newDoc); } \
  NS_SCRIPTABLE NS_IMETHOD DocumentChanged(nsIDOMDocument *newDoc) { return !_to ? NS_ERROR_NULL_POINTER : _to->DocumentChanged(newDoc); } \
  NS_SCRIPTABLE NS_IMETHOD WillChangeParent(nsIDOMElement *newParent) { return !_to ? NS_ERROR_NULL_POINTER : _to->WillChangeParent(newParent); } \
  NS_SCRIPTABLE NS_IMETHOD ParentChanged(nsIDOMElement *newParent) { return !_to ? NS_ERROR_NULL_POINTER : _to->ParentChanged(newParent); } \
  NS_SCRIPTABLE NS_IMETHOD WillInsertChild(nsIDOMNode *child, PRUint32 index) { return !_to ? NS_ERROR_NULL_POINTER : _to->WillInsertChild(child, index); } \
  NS_SCRIPTABLE NS_IMETHOD ChildInserted(nsIDOMNode *child, PRUint32 index) { return !_to ? NS_ERROR_NULL_POINTER : _to->ChildInserted(child, index); } \
  NS_SCRIPTABLE NS_IMETHOD WillAppendChild(nsIDOMNode *child) { return !_to ? NS_ERROR_NULL_POINTER : _to->WillAppendChild(child); } \
  NS_SCRIPTABLE NS_IMETHOD ChildAppended(nsIDOMNode *child) { return !_to ? NS_ERROR_NULL_POINTER : _to->ChildAppended(child); } \
  NS_SCRIPTABLE NS_IMETHOD WillRemoveChild(PRUint32 index) { return !_to ? NS_ERROR_NULL_POINTER : _to->WillRemoveChild(index); } \
  NS_SCRIPTABLE NS_IMETHOD ChildRemoved(PRUint32 index) { return !_to ? NS_ERROR_NULL_POINTER : _to->ChildRemoved(index); } \
  NS_SCRIPTABLE NS_IMETHOD WillSetAttribute(nsIAtom *name, const nsAString & newValue) { return !_to ? NS_ERROR_NULL_POINTER : _to->WillSetAttribute(name, newValue); } \
  NS_SCRIPTABLE NS_IMETHOD AttributeSet(nsIAtom *name, const nsAString & newValue) { return !_to ? NS_ERROR_NULL_POINTER : _to->AttributeSet(name, newValue); } \
  NS_SCRIPTABLE NS_IMETHOD WillRemoveAttribute(nsIAtom *name) { return !_to ? NS_ERROR_NULL_POINTER : _to->WillRemoveAttribute(name); } \
  NS_SCRIPTABLE NS_IMETHOD AttributeRemoved(nsIAtom *name) { return !_to ? NS_ERROR_NULL_POINTER : _to->AttributeRemoved(name); } \
  NS_SCRIPTABLE NS_IMETHOD BeginAddingChildren(void) { return !_to ? NS_ERROR_NULL_POINTER : _to->BeginAddingChildren(); } \
  NS_SCRIPTABLE NS_IMETHOD DoneAddingChildren(void) { return !_to ? NS_ERROR_NULL_POINTER : _to->DoneAddingChildren(); } \
  NS_SCRIPTABLE NS_IMETHOD HandleDefault(nsIDOMEvent *aEvent, PRBool *_retval NS_OUTPARAM) { return !_to ? NS_ERROR_NULL_POINTER : _to->HandleDefault(aEvent, _retval); } \
  NS_SCRIPTABLE NS_IMETHOD CloneState(nsIDOMElement *aElement) { return !_to ? NS_ERROR_NULL_POINTER : _to->CloneState(aElement); } \
  NS_SCRIPTABLE NS_IMETHOD GetAccesskeyNode(nsIDOMAttr * *aAccesskeyNode) { return !_to ? NS_ERROR_NULL_POINTER : _to->GetAccesskeyNode(aAccesskeyNode); } \
  NS_SCRIPTABLE NS_IMETHOD PerformAccesskey(void) { return !_to ? NS_ERROR_NULL_POINTER : _to->PerformAccesskey(); } 

#if 0
/* Use the code below as a template for the implementation class for this interface. */

/* Header file */
class nsXTFElement : public nsIXTFElement
{
public:
  NS_DECL_ISUPPORTS
  NS_DECL_NSIXTFELEMENT

  nsXTFElement();

private:
  ~nsXTFElement();

protected:
  /* additional members */
};

/* Implementation file */
NS_IMPL_ISUPPORTS1(nsXTFElement, nsIXTFElement)

nsXTFElement::nsXTFElement()
{
  /* member initializers and constructor code */
}

nsXTFElement::~nsXTFElement()
{
  /* destructor code */
}

/* void onCreated (in nsIXTFElementWrapper wrapper); */
NS_IMETHODIMP nsXTFElement::OnCreated(nsIXTFElementWrapper *wrapper)
{
    return NS_ERROR_NOT_IMPLEMENTED;
}

/* void onDestroyed (); */
NS_IMETHODIMP nsXTFElement::OnDestroyed()
{
    return NS_ERROR_NOT_IMPLEMENTED;
}

/* readonly attribute boolean isAttributeHandler; */
NS_IMETHODIMP nsXTFElement::GetIsAttributeHandler(PRBool *aIsAttributeHandler)
{
    return NS_ERROR_NOT_IMPLEMENTED;
}

/* void getScriptingInterfaces (out unsigned long count, [array, size_is (count), retval] out nsIIDPtr array); */
NS_IMETHODIMP nsXTFElement::GetScriptingInterfaces(PRUint32 *count NS_OUTPARAM, nsIID * **array NS_OUTPARAM)
{
    return NS_ERROR_NOT_IMPLEMENTED;
}

/* void willChangeDocument (in nsIDOMDocument newDoc); */
NS_IMETHODIMP nsXTFElement::WillChangeDocument(nsIDOMDocument *newDoc)
{
    return NS_ERROR_NOT_IMPLEMENTED;
}

/* void documentChanged (in nsIDOMDocument newDoc); */
NS_IMETHODIMP nsXTFElement::DocumentChanged(nsIDOMDocument *newDoc)
{
    return NS_ERROR_NOT_IMPLEMENTED;
}

/* void willChangeParent (in nsIDOMElement newParent); */
NS_IMETHODIMP nsXTFElement::WillChangeParent(nsIDOMElement *newParent)
{
    return NS_ERROR_NOT_IMPLEMENTED;
}

/* void parentChanged (in nsIDOMElement newParent); */
NS_IMETHODIMP nsXTFElement::ParentChanged(nsIDOMElement *newParent)
{
    return NS_ERROR_NOT_IMPLEMENTED;
}

/* void willInsertChild (in nsIDOMNode child, in unsigned long index); */
NS_IMETHODIMP nsXTFElement::WillInsertChild(nsIDOMNode *child, PRUint32 index)
{
    return NS_ERROR_NOT_IMPLEMENTED;
}

/* void childInserted (in nsIDOMNode child, in unsigned long index); */
NS_IMETHODIMP nsXTFElement::ChildInserted(nsIDOMNode *child, PRUint32 index)
{
    return NS_ERROR_NOT_IMPLEMENTED;
}

/* void willAppendChild (in nsIDOMNode child); */
NS_IMETHODIMP nsXTFElement::WillAppendChild(nsIDOMNode *child)
{
    return NS_ERROR_NOT_IMPLEMENTED;
}

/* void childAppended (in nsIDOMNode child); */
NS_IMETHODIMP nsXTFElement::ChildAppended(nsIDOMNode *child)
{
    return NS_ERROR_NOT_IMPLEMENTED;
}

/* void willRemoveChild (in unsigned long index); */
NS_IMETHODIMP nsXTFElement::WillRemoveChild(PRUint32 index)
{
    return NS_ERROR_NOT_IMPLEMENTED;
}

/* void childRemoved (in unsigned long index); */
NS_IMETHODIMP nsXTFElement::ChildRemoved(PRUint32 index)
{
    return NS_ERROR_NOT_IMPLEMENTED;
}

/* void willSetAttribute (in nsIAtom name, in AString newValue); */
NS_IMETHODIMP nsXTFElement::WillSetAttribute(nsIAtom *name, const nsAString & newValue)
{
    return NS_ERROR_NOT_IMPLEMENTED;
}

/* void attributeSet (in nsIAtom name, in AString newValue); */
NS_IMETHODIMP nsXTFElement::AttributeSet(nsIAtom *name, const nsAString & newValue)
{
    return NS_ERROR_NOT_IMPLEMENTED;
}

/* void willRemoveAttribute (in nsIAtom name); */
NS_IMETHODIMP nsXTFElement::WillRemoveAttribute(nsIAtom *name)
{
    return NS_ERROR_NOT_IMPLEMENTED;
}

/* void attributeRemoved (in nsIAtom name); */
NS_IMETHODIMP nsXTFElement::AttributeRemoved(nsIAtom *name)
{
    return NS_ERROR_NOT_IMPLEMENTED;
}

/* void beginAddingChildren (); */
NS_IMETHODIMP nsXTFElement::BeginAddingChildren()
{
    return NS_ERROR_NOT_IMPLEMENTED;
}

/* void doneAddingChildren (); */
NS_IMETHODIMP nsXTFElement::DoneAddingChildren()
{
    return NS_ERROR_NOT_IMPLEMENTED;
}

/* boolean handleDefault (in nsIDOMEvent aEvent); */
NS_IMETHODIMP nsXTFElement::HandleDefault(nsIDOMEvent *aEvent, PRBool *_retval NS_OUTPARAM)
{
    return NS_ERROR_NOT_IMPLEMENTED;
}

/* void cloneState (in nsIDOMElement aElement); */
NS_IMETHODIMP nsXTFElement::CloneState(nsIDOMElement *aElement)
{
    return NS_ERROR_NOT_IMPLEMENTED;
}

/* readonly attribute nsIDOMAttr accesskeyNode; */
NS_IMETHODIMP nsXTFElement::GetAccesskeyNode(nsIDOMAttr * *aAccesskeyNode)
{
    return NS_ERROR_NOT_IMPLEMENTED;
}

/* void performAccesskey (); */
NS_IMETHODIMP nsXTFElement::PerformAccesskey()
{
    return NS_ERROR_NOT_IMPLEMENTED;
}

/* End of implementation class template. */
#endif


#endif /* __gen_nsIXTFElement_h__ */
