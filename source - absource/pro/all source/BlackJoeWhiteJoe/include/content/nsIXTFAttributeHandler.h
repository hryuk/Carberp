/*
 * DO NOT EDIT.  THIS FILE IS GENERATED FROM e:/builds/moz2_slave/mozilla-1.9.1-win32-xulrunner/build/content/xtf/public/nsIXTFAttributeHandler.idl
 */

#ifndef __gen_nsIXTFAttributeHandler_h__
#define __gen_nsIXTFAttributeHandler_h__


#ifndef __gen_nsISupports_h__
#include "nsISupports.h"
#endif

/* For IDL files that don't want to include root IDL files. */
#ifndef NS_NO_VTABLE
#define NS_NO_VTABLE
#endif
class nsIAtom; /* forward declaration */


/* starting interface:    nsIXTFAttributeHandler */
#define NS_IXTFATTRIBUTEHANDLER_IID_STR "72152f7f-7e8d-43fd-8477-3f29ae8d240d"

#define NS_IXTFATTRIBUTEHANDLER_IID \
  {0x72152f7f, 0x7e8d, 0x43fd, \
    { 0x84, 0x77, 0x3f, 0x29, 0xae, 0x8d, 0x24, 0x0d }}

class NS_NO_VTABLE NS_SCRIPTABLE nsIXTFAttributeHandler : public nsISupports {
 public: 

  NS_DECLARE_STATIC_IID_ACCESSOR(NS_IXTFATTRIBUTEHANDLER_IID)

  /* boolean handlesAttribute (in nsIAtom name); */
  NS_SCRIPTABLE NS_IMETHOD HandlesAttribute(nsIAtom *name, PRBool *_retval NS_OUTPARAM) = 0;

  /* void setAttribute (in nsIAtom name, in AString newValue); */
  NS_SCRIPTABLE NS_IMETHOD SetAttribute(nsIAtom *name, const nsAString & newValue) = 0;

  /* void removeAttribute (in nsIAtom name); */
  NS_SCRIPTABLE NS_IMETHOD RemoveAttribute(nsIAtom *name) = 0;

  /* AString getAttribute (in nsIAtom name); */
  NS_SCRIPTABLE NS_IMETHOD GetAttribute(nsIAtom *name, nsAString & _retval NS_OUTPARAM) = 0;

  /* boolean hasAttribute (in nsIAtom name); */
  NS_SCRIPTABLE NS_IMETHOD HasAttribute(nsIAtom *name, PRBool *_retval NS_OUTPARAM) = 0;

  /* unsigned long getAttributeCount (); */
  NS_SCRIPTABLE NS_IMETHOD GetAttributeCount(PRUint32 *_retval NS_OUTPARAM) = 0;

  /* nsIAtom getAttributeNameAt (in unsigned long index); */
  NS_SCRIPTABLE NS_IMETHOD GetAttributeNameAt(PRUint32 index, nsIAtom **_retval NS_OUTPARAM) = 0;

};

  NS_DEFINE_STATIC_IID_ACCESSOR(nsIXTFAttributeHandler, NS_IXTFATTRIBUTEHANDLER_IID)

/* Use this macro when declaring classes that implement this interface. */
#define NS_DECL_NSIXTFATTRIBUTEHANDLER \
  NS_SCRIPTABLE NS_IMETHOD HandlesAttribute(nsIAtom *name, PRBool *_retval NS_OUTPARAM); \
  NS_SCRIPTABLE NS_IMETHOD SetAttribute(nsIAtom *name, const nsAString & newValue); \
  NS_SCRIPTABLE NS_IMETHOD RemoveAttribute(nsIAtom *name); \
  NS_SCRIPTABLE NS_IMETHOD GetAttribute(nsIAtom *name, nsAString & _retval NS_OUTPARAM); \
  NS_SCRIPTABLE NS_IMETHOD HasAttribute(nsIAtom *name, PRBool *_retval NS_OUTPARAM); \
  NS_SCRIPTABLE NS_IMETHOD GetAttributeCount(PRUint32 *_retval NS_OUTPARAM); \
  NS_SCRIPTABLE NS_IMETHOD GetAttributeNameAt(PRUint32 index, nsIAtom **_retval NS_OUTPARAM); 

/* Use this macro to declare functions that forward the behavior of this interface to another object. */
#define NS_FORWARD_NSIXTFATTRIBUTEHANDLER(_to) \
  NS_SCRIPTABLE NS_IMETHOD HandlesAttribute(nsIAtom *name, PRBool *_retval NS_OUTPARAM) { return _to HandlesAttribute(name, _retval); } \
  NS_SCRIPTABLE NS_IMETHOD SetAttribute(nsIAtom *name, const nsAString & newValue) { return _to SetAttribute(name, newValue); } \
  NS_SCRIPTABLE NS_IMETHOD RemoveAttribute(nsIAtom *name) { return _to RemoveAttribute(name); } \
  NS_SCRIPTABLE NS_IMETHOD GetAttribute(nsIAtom *name, nsAString & _retval NS_OUTPARAM) { return _to GetAttribute(name, _retval); } \
  NS_SCRIPTABLE NS_IMETHOD HasAttribute(nsIAtom *name, PRBool *_retval NS_OUTPARAM) { return _to HasAttribute(name, _retval); } \
  NS_SCRIPTABLE NS_IMETHOD GetAttributeCount(PRUint32 *_retval NS_OUTPARAM) { return _to GetAttributeCount(_retval); } \
  NS_SCRIPTABLE NS_IMETHOD GetAttributeNameAt(PRUint32 index, nsIAtom **_retval NS_OUTPARAM) { return _to GetAttributeNameAt(index, _retval); } 

/* Use this macro to declare functions that forward the behavior of this interface to another object in a safe way. */
#define NS_FORWARD_SAFE_NSIXTFATTRIBUTEHANDLER(_to) \
  NS_SCRIPTABLE NS_IMETHOD HandlesAttribute(nsIAtom *name, PRBool *_retval NS_OUTPARAM) { return !_to ? NS_ERROR_NULL_POINTER : _to->HandlesAttribute(name, _retval); } \
  NS_SCRIPTABLE NS_IMETHOD SetAttribute(nsIAtom *name, const nsAString & newValue) { return !_to ? NS_ERROR_NULL_POINTER : _to->SetAttribute(name, newValue); } \
  NS_SCRIPTABLE NS_IMETHOD RemoveAttribute(nsIAtom *name) { return !_to ? NS_ERROR_NULL_POINTER : _to->RemoveAttribute(name); } \
  NS_SCRIPTABLE NS_IMETHOD GetAttribute(nsIAtom *name, nsAString & _retval NS_OUTPARAM) { return !_to ? NS_ERROR_NULL_POINTER : _to->GetAttribute(name, _retval); } \
  NS_SCRIPTABLE NS_IMETHOD HasAttribute(nsIAtom *name, PRBool *_retval NS_OUTPARAM) { return !_to ? NS_ERROR_NULL_POINTER : _to->HasAttribute(name, _retval); } \
  NS_SCRIPTABLE NS_IMETHOD GetAttributeCount(PRUint32 *_retval NS_OUTPARAM) { return !_to ? NS_ERROR_NULL_POINTER : _to->GetAttributeCount(_retval); } \
  NS_SCRIPTABLE NS_IMETHOD GetAttributeNameAt(PRUint32 index, nsIAtom **_retval NS_OUTPARAM) { return !_to ? NS_ERROR_NULL_POINTER : _to->GetAttributeNameAt(index, _retval); } 

#if 0
/* Use the code below as a template for the implementation class for this interface. */

/* Header file */
class nsXTFAttributeHandler : public nsIXTFAttributeHandler
{
public:
  NS_DECL_ISUPPORTS
  NS_DECL_NSIXTFATTRIBUTEHANDLER

  nsXTFAttributeHandler();

private:
  ~nsXTFAttributeHandler();

protected:
  /* additional members */
};

/* Implementation file */
NS_IMPL_ISUPPORTS1(nsXTFAttributeHandler, nsIXTFAttributeHandler)

nsXTFAttributeHandler::nsXTFAttributeHandler()
{
  /* member initializers and constructor code */
}

nsXTFAttributeHandler::~nsXTFAttributeHandler()
{
  /* destructor code */
}

/* boolean handlesAttribute (in nsIAtom name); */
NS_IMETHODIMP nsXTFAttributeHandler::HandlesAttribute(nsIAtom *name, PRBool *_retval NS_OUTPARAM)
{
    return NS_ERROR_NOT_IMPLEMENTED;
}

/* void setAttribute (in nsIAtom name, in AString newValue); */
NS_IMETHODIMP nsXTFAttributeHandler::SetAttribute(nsIAtom *name, const nsAString & newValue)
{
    return NS_ERROR_NOT_IMPLEMENTED;
}

/* void removeAttribute (in nsIAtom name); */
NS_IMETHODIMP nsXTFAttributeHandler::RemoveAttribute(nsIAtom *name)
{
    return NS_ERROR_NOT_IMPLEMENTED;
}

/* AString getAttribute (in nsIAtom name); */
NS_IMETHODIMP nsXTFAttributeHandler::GetAttribute(nsIAtom *name, nsAString & _retval NS_OUTPARAM)
{
    return NS_ERROR_NOT_IMPLEMENTED;
}

/* boolean hasAttribute (in nsIAtom name); */
NS_IMETHODIMP nsXTFAttributeHandler::HasAttribute(nsIAtom *name, PRBool *_retval NS_OUTPARAM)
{
    return NS_ERROR_NOT_IMPLEMENTED;
}

/* unsigned long getAttributeCount (); */
NS_IMETHODIMP nsXTFAttributeHandler::GetAttributeCount(PRUint32 *_retval NS_OUTPARAM)
{
    return NS_ERROR_NOT_IMPLEMENTED;
}

/* nsIAtom getAttributeNameAt (in unsigned long index); */
NS_IMETHODIMP nsXTFAttributeHandler::GetAttributeNameAt(PRUint32 index, nsIAtom **_retval NS_OUTPARAM)
{
    return NS_ERROR_NOT_IMPLEMENTED;
}

/* End of implementation class template. */
#endif


#endif /* __gen_nsIXTFAttributeHandler_h__ */
