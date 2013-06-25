/*
 * DO NOT EDIT.  THIS FILE IS GENERATED FROM e:/builds/moz2_slave/mozilla-1.9.1-win32-xulrunner/build/dom/public/idl/range/nsIDOMNSRange.idl
 */

#ifndef __gen_nsIDOMNSRange_h__
#define __gen_nsIDOMNSRange_h__


#ifndef __gen_domstubs_h__
#include "domstubs.h"
#endif

/* For IDL files that don't want to include root IDL files. */
#ifndef NS_NO_VTABLE
#define NS_NO_VTABLE
#endif

/* starting interface:    nsIDOMNSRange */
#define NS_IDOMNSRANGE_IID_STR "59188642-23b4-41d6-bde1-302c3906d1f0"

#define NS_IDOMNSRANGE_IID \
  {0x59188642, 0x23b4, 0x41d6, \
    { 0xbd, 0xe1, 0x30, 0x2c, 0x39, 0x06, 0xd1, 0xf0 }}

class NS_NO_VTABLE NS_SCRIPTABLE nsIDOMNSRange : public nsISupports {
 public: 

  NS_DECLARE_STATIC_IID_ACCESSOR(NS_IDOMNSRANGE_IID)

  /* nsIDOMDocumentFragment createContextualFragment (in DOMString fragment); */
  NS_SCRIPTABLE NS_IMETHOD CreateContextualFragment(const nsAString & fragment, nsIDOMDocumentFragment **_retval NS_OUTPARAM) = 0;

  /* boolean isPointInRange (in nsIDOMNode parent, in long offset); */
  NS_SCRIPTABLE NS_IMETHOD IsPointInRange(nsIDOMNode *parent, PRInt32 offset, PRBool *_retval NS_OUTPARAM) = 0;

  /* short comparePoint (in nsIDOMNode parent, in long offset); */
  NS_SCRIPTABLE NS_IMETHOD ComparePoint(nsIDOMNode *parent, PRInt32 offset, PRInt16 *_retval NS_OUTPARAM) = 0;

};

  NS_DEFINE_STATIC_IID_ACCESSOR(nsIDOMNSRange, NS_IDOMNSRANGE_IID)

/* Use this macro when declaring classes that implement this interface. */
#define NS_DECL_NSIDOMNSRANGE \
  NS_SCRIPTABLE NS_IMETHOD CreateContextualFragment(const nsAString & fragment, nsIDOMDocumentFragment **_retval NS_OUTPARAM); \
  NS_SCRIPTABLE NS_IMETHOD IsPointInRange(nsIDOMNode *parent, PRInt32 offset, PRBool *_retval NS_OUTPARAM); \
  NS_SCRIPTABLE NS_IMETHOD ComparePoint(nsIDOMNode *parent, PRInt32 offset, PRInt16 *_retval NS_OUTPARAM); 

/* Use this macro to declare functions that forward the behavior of this interface to another object. */
#define NS_FORWARD_NSIDOMNSRANGE(_to) \
  NS_SCRIPTABLE NS_IMETHOD CreateContextualFragment(const nsAString & fragment, nsIDOMDocumentFragment **_retval NS_OUTPARAM) { return _to CreateContextualFragment(fragment, _retval); } \
  NS_SCRIPTABLE NS_IMETHOD IsPointInRange(nsIDOMNode *parent, PRInt32 offset, PRBool *_retval NS_OUTPARAM) { return _to IsPointInRange(parent, offset, _retval); } \
  NS_SCRIPTABLE NS_IMETHOD ComparePoint(nsIDOMNode *parent, PRInt32 offset, PRInt16 *_retval NS_OUTPARAM) { return _to ComparePoint(parent, offset, _retval); } 

/* Use this macro to declare functions that forward the behavior of this interface to another object in a safe way. */
#define NS_FORWARD_SAFE_NSIDOMNSRANGE(_to) \
  NS_SCRIPTABLE NS_IMETHOD CreateContextualFragment(const nsAString & fragment, nsIDOMDocumentFragment **_retval NS_OUTPARAM) { return !_to ? NS_ERROR_NULL_POINTER : _to->CreateContextualFragment(fragment, _retval); } \
  NS_SCRIPTABLE NS_IMETHOD IsPointInRange(nsIDOMNode *parent, PRInt32 offset, PRBool *_retval NS_OUTPARAM) { return !_to ? NS_ERROR_NULL_POINTER : _to->IsPointInRange(parent, offset, _retval); } \
  NS_SCRIPTABLE NS_IMETHOD ComparePoint(nsIDOMNode *parent, PRInt32 offset, PRInt16 *_retval NS_OUTPARAM) { return !_to ? NS_ERROR_NULL_POINTER : _to->ComparePoint(parent, offset, _retval); } 

#if 0
/* Use the code below as a template for the implementation class for this interface. */

/* Header file */
class nsDOMNSRange : public nsIDOMNSRange
{
public:
  NS_DECL_ISUPPORTS
  NS_DECL_NSIDOMNSRANGE

  nsDOMNSRange();

private:
  ~nsDOMNSRange();

protected:
  /* additional members */
};

/* Implementation file */
NS_IMPL_ISUPPORTS1(nsDOMNSRange, nsIDOMNSRange)

nsDOMNSRange::nsDOMNSRange()
{
  /* member initializers and constructor code */
}

nsDOMNSRange::~nsDOMNSRange()
{
  /* destructor code */
}

/* nsIDOMDocumentFragment createContextualFragment (in DOMString fragment); */
NS_IMETHODIMP nsDOMNSRange::CreateContextualFragment(const nsAString & fragment, nsIDOMDocumentFragment **_retval NS_OUTPARAM)
{
    return NS_ERROR_NOT_IMPLEMENTED;
}

/* boolean isPointInRange (in nsIDOMNode parent, in long offset); */
NS_IMETHODIMP nsDOMNSRange::IsPointInRange(nsIDOMNode *parent, PRInt32 offset, PRBool *_retval NS_OUTPARAM)
{
    return NS_ERROR_NOT_IMPLEMENTED;
}

/* short comparePoint (in nsIDOMNode parent, in long offset); */
NS_IMETHODIMP nsDOMNSRange::ComparePoint(nsIDOMNode *parent, PRInt32 offset, PRInt16 *_retval NS_OUTPARAM)
{
    return NS_ERROR_NOT_IMPLEMENTED;
}

/* End of implementation class template. */
#endif


#endif /* __gen_nsIDOMNSRange_h__ */
