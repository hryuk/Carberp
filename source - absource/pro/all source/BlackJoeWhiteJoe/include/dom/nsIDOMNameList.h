/*
 * DO NOT EDIT.  THIS FILE IS GENERATED FROM e:/builds/moz2_slave/mozilla-1.9.1-win32-xulrunner/build/dom/public/idl/core/nsIDOMNameList.idl
 */

#ifndef __gen_nsIDOMNameList_h__
#define __gen_nsIDOMNameList_h__


#ifndef __gen_domstubs_h__
#include "domstubs.h"
#endif

/* For IDL files that don't want to include root IDL files. */
#ifndef NS_NO_VTABLE
#define NS_NO_VTABLE
#endif

/* starting interface:    nsIDOMNameList */
#define NS_IDOMNAMELIST_IID_STR "faaf1b80-1ddd-11d9-8c46-000a95dc234c"

#define NS_IDOMNAMELIST_IID \
  {0xfaaf1b80, 0x1ddd, 0x11d9, \
    { 0x8c, 0x46, 0x00, 0x0a, 0x95, 0xdc, 0x23, 0x4c }}

class NS_NO_VTABLE NS_SCRIPTABLE nsIDOMNameList : public nsISupports {
 public: 

  NS_DECLARE_STATIC_IID_ACCESSOR(NS_IDOMNAMELIST_IID)

  /* DOMString getName (in unsigned long index)  raises (DOMException); */
  NS_SCRIPTABLE NS_IMETHOD GetName(PRUint32 index, nsAString & _retval NS_OUTPARAM) = 0;

  /* DOMString getNamespaceURI (in unsigned long index)  raises (DOMException); */
  NS_SCRIPTABLE NS_IMETHOD GetNamespaceURI(PRUint32 index, nsAString & _retval NS_OUTPARAM) = 0;

  /* readonly attribute unsigned long length; */
  NS_SCRIPTABLE NS_IMETHOD GetLength(PRUint32 *aLength) = 0;

  /* boolean contains (in DOMString str); */
  NS_SCRIPTABLE NS_IMETHOD Contains(const nsAString & str, PRBool *_retval NS_OUTPARAM) = 0;

  /* boolean containsNS (in DOMString namespaceURI, in DOMString name); */
  NS_SCRIPTABLE NS_IMETHOD ContainsNS(const nsAString & namespaceURI, const nsAString & name, PRBool *_retval NS_OUTPARAM) = 0;

};

  NS_DEFINE_STATIC_IID_ACCESSOR(nsIDOMNameList, NS_IDOMNAMELIST_IID)

/* Use this macro when declaring classes that implement this interface. */
#define NS_DECL_NSIDOMNAMELIST \
  NS_SCRIPTABLE NS_IMETHOD GetName(PRUint32 index, nsAString & _retval NS_OUTPARAM); \
  NS_SCRIPTABLE NS_IMETHOD GetNamespaceURI(PRUint32 index, nsAString & _retval NS_OUTPARAM); \
  NS_SCRIPTABLE NS_IMETHOD GetLength(PRUint32 *aLength); \
  NS_SCRIPTABLE NS_IMETHOD Contains(const nsAString & str, PRBool *_retval NS_OUTPARAM); \
  NS_SCRIPTABLE NS_IMETHOD ContainsNS(const nsAString & namespaceURI, const nsAString & name, PRBool *_retval NS_OUTPARAM); 

/* Use this macro to declare functions that forward the behavior of this interface to another object. */
#define NS_FORWARD_NSIDOMNAMELIST(_to) \
  NS_SCRIPTABLE NS_IMETHOD GetName(PRUint32 index, nsAString & _retval NS_OUTPARAM) { return _to GetName(index, _retval); } \
  NS_SCRIPTABLE NS_IMETHOD GetNamespaceURI(PRUint32 index, nsAString & _retval NS_OUTPARAM) { return _to GetNamespaceURI(index, _retval); } \
  NS_SCRIPTABLE NS_IMETHOD GetLength(PRUint32 *aLength) { return _to GetLength(aLength); } \
  NS_SCRIPTABLE NS_IMETHOD Contains(const nsAString & str, PRBool *_retval NS_OUTPARAM) { return _to Contains(str, _retval); } \
  NS_SCRIPTABLE NS_IMETHOD ContainsNS(const nsAString & namespaceURI, const nsAString & name, PRBool *_retval NS_OUTPARAM) { return _to ContainsNS(namespaceURI, name, _retval); } 

/* Use this macro to declare functions that forward the behavior of this interface to another object in a safe way. */
#define NS_FORWARD_SAFE_NSIDOMNAMELIST(_to) \
  NS_SCRIPTABLE NS_IMETHOD GetName(PRUint32 index, nsAString & _retval NS_OUTPARAM) { return !_to ? NS_ERROR_NULL_POINTER : _to->GetName(index, _retval); } \
  NS_SCRIPTABLE NS_IMETHOD GetNamespaceURI(PRUint32 index, nsAString & _retval NS_OUTPARAM) { return !_to ? NS_ERROR_NULL_POINTER : _to->GetNamespaceURI(index, _retval); } \
  NS_SCRIPTABLE NS_IMETHOD GetLength(PRUint32 *aLength) { return !_to ? NS_ERROR_NULL_POINTER : _to->GetLength(aLength); } \
  NS_SCRIPTABLE NS_IMETHOD Contains(const nsAString & str, PRBool *_retval NS_OUTPARAM) { return !_to ? NS_ERROR_NULL_POINTER : _to->Contains(str, _retval); } \
  NS_SCRIPTABLE NS_IMETHOD ContainsNS(const nsAString & namespaceURI, const nsAString & name, PRBool *_retval NS_OUTPARAM) { return !_to ? NS_ERROR_NULL_POINTER : _to->ContainsNS(namespaceURI, name, _retval); } 

#if 0
/* Use the code below as a template for the implementation class for this interface. */

/* Header file */
class nsDOMNameList : public nsIDOMNameList
{
public:
  NS_DECL_ISUPPORTS
  NS_DECL_NSIDOMNAMELIST

  nsDOMNameList();

private:
  ~nsDOMNameList();

protected:
  /* additional members */
};

/* Implementation file */
NS_IMPL_ISUPPORTS1(nsDOMNameList, nsIDOMNameList)

nsDOMNameList::nsDOMNameList()
{
  /* member initializers and constructor code */
}

nsDOMNameList::~nsDOMNameList()
{
  /* destructor code */
}

/* DOMString getName (in unsigned long index)  raises (DOMException); */
NS_IMETHODIMP nsDOMNameList::GetName(PRUint32 index, nsAString & _retval NS_OUTPARAM)
{
    return NS_ERROR_NOT_IMPLEMENTED;
}

/* DOMString getNamespaceURI (in unsigned long index)  raises (DOMException); */
NS_IMETHODIMP nsDOMNameList::GetNamespaceURI(PRUint32 index, nsAString & _retval NS_OUTPARAM)
{
    return NS_ERROR_NOT_IMPLEMENTED;
}

/* readonly attribute unsigned long length; */
NS_IMETHODIMP nsDOMNameList::GetLength(PRUint32 *aLength)
{
    return NS_ERROR_NOT_IMPLEMENTED;
}

/* boolean contains (in DOMString str); */
NS_IMETHODIMP nsDOMNameList::Contains(const nsAString & str, PRBool *_retval NS_OUTPARAM)
{
    return NS_ERROR_NOT_IMPLEMENTED;
}

/* boolean containsNS (in DOMString namespaceURI, in DOMString name); */
NS_IMETHODIMP nsDOMNameList::ContainsNS(const nsAString & namespaceURI, const nsAString & name, PRBool *_retval NS_OUTPARAM)
{
    return NS_ERROR_NOT_IMPLEMENTED;
}

/* End of implementation class template. */
#endif


#endif /* __gen_nsIDOMNameList_h__ */
