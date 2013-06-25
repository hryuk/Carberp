/*
 * DO NOT EDIT.  THIS FILE IS GENERATED FROM e:/builds/moz2_slave/mozilla-1.9.1-win32-xulrunner/build/dom/public/idl/html/nsIDOMNSHTMLAreaElement2.idl
 */

#ifndef __gen_nsIDOMNSHTMLAreaElement2_h__
#define __gen_nsIDOMNSHTMLAreaElement2_h__


#ifndef __gen_nsIDOMNSHTMLAreaElement_h__
#include "nsIDOMNSHTMLAreaElement.h"
#endif

/* For IDL files that don't want to include root IDL files. */
#ifndef NS_NO_VTABLE
#define NS_NO_VTABLE
#endif

/* starting interface:    nsIDOMNSHTMLAreaElement2 */
#define NS_IDOMNSHTMLAREAELEMENT2_IID_STR "1859b16a-7c16-4ab7-bdb9-52792ba16cc1"

#define NS_IDOMNSHTMLAREAELEMENT2_IID \
  {0x1859b16a, 0x7c16, 0x4ab7, \
    { 0xbd, 0xb9, 0x52, 0x79, 0x2b, 0xa1, 0x6c, 0xc1 }}

class NS_NO_VTABLE NS_SCRIPTABLE nsIDOMNSHTMLAreaElement2 : public nsIDOMNSHTMLAreaElement {
 public: 

  NS_DECLARE_STATIC_IID_ACCESSOR(NS_IDOMNSHTMLAREAELEMENT2_IID)

  /* attribute DOMString ping; */
  NS_SCRIPTABLE NS_IMETHOD GetPing(nsAString & aPing) = 0;
  NS_SCRIPTABLE NS_IMETHOD SetPing(const nsAString & aPing) = 0;

};

  NS_DEFINE_STATIC_IID_ACCESSOR(nsIDOMNSHTMLAreaElement2, NS_IDOMNSHTMLAREAELEMENT2_IID)

/* Use this macro when declaring classes that implement this interface. */
#define NS_DECL_NSIDOMNSHTMLAREAELEMENT2 \
  NS_SCRIPTABLE NS_IMETHOD GetPing(nsAString & aPing); \
  NS_SCRIPTABLE NS_IMETHOD SetPing(const nsAString & aPing); 

/* Use this macro to declare functions that forward the behavior of this interface to another object. */
#define NS_FORWARD_NSIDOMNSHTMLAREAELEMENT2(_to) \
  NS_SCRIPTABLE NS_IMETHOD GetPing(nsAString & aPing) { return _to GetPing(aPing); } \
  NS_SCRIPTABLE NS_IMETHOD SetPing(const nsAString & aPing) { return _to SetPing(aPing); } 

/* Use this macro to declare functions that forward the behavior of this interface to another object in a safe way. */
#define NS_FORWARD_SAFE_NSIDOMNSHTMLAREAELEMENT2(_to) \
  NS_SCRIPTABLE NS_IMETHOD GetPing(nsAString & aPing) { return !_to ? NS_ERROR_NULL_POINTER : _to->GetPing(aPing); } \
  NS_SCRIPTABLE NS_IMETHOD SetPing(const nsAString & aPing) { return !_to ? NS_ERROR_NULL_POINTER : _to->SetPing(aPing); } 

#if 0
/* Use the code below as a template for the implementation class for this interface. */

/* Header file */
class nsDOMNSHTMLAreaElement2 : public nsIDOMNSHTMLAreaElement2
{
public:
  NS_DECL_ISUPPORTS
  NS_DECL_NSIDOMNSHTMLAREAELEMENT2

  nsDOMNSHTMLAreaElement2();

private:
  ~nsDOMNSHTMLAreaElement2();

protected:
  /* additional members */
};

/* Implementation file */
NS_IMPL_ISUPPORTS1(nsDOMNSHTMLAreaElement2, nsIDOMNSHTMLAreaElement2)

nsDOMNSHTMLAreaElement2::nsDOMNSHTMLAreaElement2()
{
  /* member initializers and constructor code */
}

nsDOMNSHTMLAreaElement2::~nsDOMNSHTMLAreaElement2()
{
  /* destructor code */
}

/* attribute DOMString ping; */
NS_IMETHODIMP nsDOMNSHTMLAreaElement2::GetPing(nsAString & aPing)
{
    return NS_ERROR_NOT_IMPLEMENTED;
}
NS_IMETHODIMP nsDOMNSHTMLAreaElement2::SetPing(const nsAString & aPing)
{
    return NS_ERROR_NOT_IMPLEMENTED;
}

/* End of implementation class template. */
#endif


#endif /* __gen_nsIDOMNSHTMLAreaElement2_h__ */
