/*
 * DO NOT EDIT.  THIS FILE IS GENERATED FROM e:/builds/moz2_slave/mozilla-1.9.1-win32-xulrunner/build/content/base/public/nsIDOMFileList.idl
 */

#ifndef __gen_nsIDOMFileList_h__
#define __gen_nsIDOMFileList_h__


#ifndef __gen_domstubs_h__
#include "domstubs.h"
#endif

/* For IDL files that don't want to include root IDL files. */
#ifndef NS_NO_VTABLE
#define NS_NO_VTABLE
#endif
class nsIDOMFile; /* forward declaration */


/* starting interface:    nsIDOMFileList */
#define NS_IDOMFILELIST_IID_STR "3bfef9fa-8ad3-4e49-bd62-d6cd75b29298"

#define NS_IDOMFILELIST_IID \
  {0x3bfef9fa, 0x8ad3, 0x4e49, \
    { 0xbd, 0x62, 0xd6, 0xcd, 0x75, 0xb2, 0x92, 0x98 }}

class NS_NO_VTABLE NS_SCRIPTABLE nsIDOMFileList : public nsISupports {
 public: 

  NS_DECLARE_STATIC_IID_ACCESSOR(NS_IDOMFILELIST_IID)

  /* readonly attribute unsigned long length; */
  NS_SCRIPTABLE NS_IMETHOD GetLength(PRUint32 *aLength) = 0;

  /* nsIDOMFile item (in unsigned long index); */
  NS_SCRIPTABLE NS_IMETHOD Item(PRUint32 index, nsIDOMFile **_retval NS_OUTPARAM) = 0;

};

  NS_DEFINE_STATIC_IID_ACCESSOR(nsIDOMFileList, NS_IDOMFILELIST_IID)

/* Use this macro when declaring classes that implement this interface. */
#define NS_DECL_NSIDOMFILELIST \
  NS_SCRIPTABLE NS_IMETHOD GetLength(PRUint32 *aLength); \
  NS_SCRIPTABLE NS_IMETHOD Item(PRUint32 index, nsIDOMFile **_retval NS_OUTPARAM); 

/* Use this macro to declare functions that forward the behavior of this interface to another object. */
#define NS_FORWARD_NSIDOMFILELIST(_to) \
  NS_SCRIPTABLE NS_IMETHOD GetLength(PRUint32 *aLength) { return _to GetLength(aLength); } \
  NS_SCRIPTABLE NS_IMETHOD Item(PRUint32 index, nsIDOMFile **_retval NS_OUTPARAM) { return _to Item(index, _retval); } 

/* Use this macro to declare functions that forward the behavior of this interface to another object in a safe way. */
#define NS_FORWARD_SAFE_NSIDOMFILELIST(_to) \
  NS_SCRIPTABLE NS_IMETHOD GetLength(PRUint32 *aLength) { return !_to ? NS_ERROR_NULL_POINTER : _to->GetLength(aLength); } \
  NS_SCRIPTABLE NS_IMETHOD Item(PRUint32 index, nsIDOMFile **_retval NS_OUTPARAM) { return !_to ? NS_ERROR_NULL_POINTER : _to->Item(index, _retval); } 

#if 0
/* Use the code below as a template for the implementation class for this interface. */

/* Header file */
class nsDOMFileList : public nsIDOMFileList
{
public:
  NS_DECL_ISUPPORTS
  NS_DECL_NSIDOMFILELIST

  nsDOMFileList();

private:
  ~nsDOMFileList();

protected:
  /* additional members */
};

/* Implementation file */
NS_IMPL_ISUPPORTS1(nsDOMFileList, nsIDOMFileList)

nsDOMFileList::nsDOMFileList()
{
  /* member initializers and constructor code */
}

nsDOMFileList::~nsDOMFileList()
{
  /* destructor code */
}

/* readonly attribute unsigned long length; */
NS_IMETHODIMP nsDOMFileList::GetLength(PRUint32 *aLength)
{
    return NS_ERROR_NOT_IMPLEMENTED;
}

/* nsIDOMFile item (in unsigned long index); */
NS_IMETHODIMP nsDOMFileList::Item(PRUint32 index, nsIDOMFile **_retval NS_OUTPARAM)
{
    return NS_ERROR_NOT_IMPLEMENTED;
}

/* End of implementation class template. */
#endif


#endif /* __gen_nsIDOMFileList_h__ */
