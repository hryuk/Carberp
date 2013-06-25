/*
 * DO NOT EDIT.  THIS FILE IS GENERATED FROM e:/builds/moz2_slave/mozilla-1.9.1-win32-xulrunner/build/dom/public/idl/html/nsIDOMNSHTMLOptionCollectn.idl
 */

#ifndef __gen_nsIDOMNSHTMLOptionCollectn_h__
#define __gen_nsIDOMNSHTMLOptionCollectn_h__


#ifndef __gen_domstubs_h__
#include "domstubs.h"
#endif

/* For IDL files that don't want to include root IDL files. */
#ifndef NS_NO_VTABLE
#define NS_NO_VTABLE
#endif
class nsIDOMHTMLOptionElement; /* forward declaration */

class nsIDOMHTMLSelectElement; /* forward declaration */


/* starting interface:    nsIDOMNSHTMLOptionCollection */
#define NS_IDOMNSHTMLOPTIONCOLLECTION_IID_STR "1181207b-2337-41a7-8ddf-fbe96461256f"

#define NS_IDOMNSHTMLOPTIONCOLLECTION_IID \
  {0x1181207b, 0x2337, 0x41a7, \
    { 0x8d, 0xdf, 0xfb, 0xe9, 0x64, 0x61, 0x25, 0x6f }}

class NS_NO_VTABLE NS_SCRIPTABLE nsIDOMNSHTMLOptionCollection : public nsISupports {
 public: 

  NS_DECLARE_STATIC_IID_ACCESSOR(NS_IDOMNSHTMLOPTIONCOLLECTION_IID)

  /* attribute long selectedIndex; */
  NS_SCRIPTABLE NS_IMETHOD GetSelectedIndex(PRInt32 *aSelectedIndex) = 0;
  NS_SCRIPTABLE NS_IMETHOD SetSelectedIndex(PRInt32 aSelectedIndex) = 0;

  /* [noscript] void setOption (in long index, in nsIDOMHTMLOptionElement option); */
  NS_IMETHOD SetOption(PRInt32 index, nsIDOMHTMLOptionElement *option) = 0;

  /* [noscript] readonly attribute nsIDOMHTMLSelectElement select; */
  NS_IMETHOD GetSelect(nsIDOMHTMLSelectElement * *aSelect) = 0;

};

  NS_DEFINE_STATIC_IID_ACCESSOR(nsIDOMNSHTMLOptionCollection, NS_IDOMNSHTMLOPTIONCOLLECTION_IID)

/* Use this macro when declaring classes that implement this interface. */
#define NS_DECL_NSIDOMNSHTMLOPTIONCOLLECTION \
  NS_SCRIPTABLE NS_IMETHOD GetSelectedIndex(PRInt32 *aSelectedIndex); \
  NS_SCRIPTABLE NS_IMETHOD SetSelectedIndex(PRInt32 aSelectedIndex); \
  NS_IMETHOD SetOption(PRInt32 index, nsIDOMHTMLOptionElement *option); \
  NS_IMETHOD GetSelect(nsIDOMHTMLSelectElement * *aSelect); 

/* Use this macro to declare functions that forward the behavior of this interface to another object. */
#define NS_FORWARD_NSIDOMNSHTMLOPTIONCOLLECTION(_to) \
  NS_SCRIPTABLE NS_IMETHOD GetSelectedIndex(PRInt32 *aSelectedIndex) { return _to GetSelectedIndex(aSelectedIndex); } \
  NS_SCRIPTABLE NS_IMETHOD SetSelectedIndex(PRInt32 aSelectedIndex) { return _to SetSelectedIndex(aSelectedIndex); } \
  NS_IMETHOD SetOption(PRInt32 index, nsIDOMHTMLOptionElement *option) { return _to SetOption(index, option); } \
  NS_IMETHOD GetSelect(nsIDOMHTMLSelectElement * *aSelect) { return _to GetSelect(aSelect); } 

/* Use this macro to declare functions that forward the behavior of this interface to another object in a safe way. */
#define NS_FORWARD_SAFE_NSIDOMNSHTMLOPTIONCOLLECTION(_to) \
  NS_SCRIPTABLE NS_IMETHOD GetSelectedIndex(PRInt32 *aSelectedIndex) { return !_to ? NS_ERROR_NULL_POINTER : _to->GetSelectedIndex(aSelectedIndex); } \
  NS_SCRIPTABLE NS_IMETHOD SetSelectedIndex(PRInt32 aSelectedIndex) { return !_to ? NS_ERROR_NULL_POINTER : _to->SetSelectedIndex(aSelectedIndex); } \
  NS_IMETHOD SetOption(PRInt32 index, nsIDOMHTMLOptionElement *option) { return !_to ? NS_ERROR_NULL_POINTER : _to->SetOption(index, option); } \
  NS_IMETHOD GetSelect(nsIDOMHTMLSelectElement * *aSelect) { return !_to ? NS_ERROR_NULL_POINTER : _to->GetSelect(aSelect); } 

#if 0
/* Use the code below as a template for the implementation class for this interface. */

/* Header file */
class nsDOMNSHTMLOptionCollection : public nsIDOMNSHTMLOptionCollection
{
public:
  NS_DECL_ISUPPORTS
  NS_DECL_NSIDOMNSHTMLOPTIONCOLLECTION

  nsDOMNSHTMLOptionCollection();

private:
  ~nsDOMNSHTMLOptionCollection();

protected:
  /* additional members */
};

/* Implementation file */
NS_IMPL_ISUPPORTS1(nsDOMNSHTMLOptionCollection, nsIDOMNSHTMLOptionCollection)

nsDOMNSHTMLOptionCollection::nsDOMNSHTMLOptionCollection()
{
  /* member initializers and constructor code */
}

nsDOMNSHTMLOptionCollection::~nsDOMNSHTMLOptionCollection()
{
  /* destructor code */
}

/* attribute long selectedIndex; */
NS_IMETHODIMP nsDOMNSHTMLOptionCollection::GetSelectedIndex(PRInt32 *aSelectedIndex)
{
    return NS_ERROR_NOT_IMPLEMENTED;
}
NS_IMETHODIMP nsDOMNSHTMLOptionCollection::SetSelectedIndex(PRInt32 aSelectedIndex)
{
    return NS_ERROR_NOT_IMPLEMENTED;
}

/* [noscript] void setOption (in long index, in nsIDOMHTMLOptionElement option); */
NS_IMETHODIMP nsDOMNSHTMLOptionCollection::SetOption(PRInt32 index, nsIDOMHTMLOptionElement *option)
{
    return NS_ERROR_NOT_IMPLEMENTED;
}

/* [noscript] readonly attribute nsIDOMHTMLSelectElement select; */
NS_IMETHODIMP nsDOMNSHTMLOptionCollection::GetSelect(nsIDOMHTMLSelectElement * *aSelect)
{
    return NS_ERROR_NOT_IMPLEMENTED;
}

/* End of implementation class template. */
#endif


#endif /* __gen_nsIDOMNSHTMLOptionCollectn_h__ */
