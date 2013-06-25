/*
 * DO NOT EDIT.  THIS FILE IS GENERATED FROM e:/builds/moz2_slave/mozilla-1.9.1-win32-xulrunner/build/dom/public/idl/html/nsIDOMNSHTMLAnchorElement2.idl
 */

#ifndef __gen_nsIDOMNSHTMLAnchorElement2_h__
#define __gen_nsIDOMNSHTMLAnchorElement2_h__


#ifndef __gen_nsIDOMNSHTMLAnchorElement_h__
#include "nsIDOMNSHTMLAnchorElement.h"
#endif

/* For IDL files that don't want to include root IDL files. */
#ifndef NS_NO_VTABLE
#define NS_NO_VTABLE
#endif

/* starting interface:    nsIDOMNSHTMLAnchorElement2 */
#define NS_IDOMNSHTMLANCHORELEMENT2_IID_STR "d7627eda-6ec0-4326-87c4-c3067fe6e324"

#define NS_IDOMNSHTMLANCHORELEMENT2_IID \
  {0xd7627eda, 0x6ec0, 0x4326, \
    { 0x87, 0xc4, 0xc3, 0x06, 0x7f, 0xe6, 0xe3, 0x24 }}

class NS_NO_VTABLE NS_SCRIPTABLE nsIDOMNSHTMLAnchorElement2 : public nsIDOMNSHTMLAnchorElement {
 public: 

  NS_DECLARE_STATIC_IID_ACCESSOR(NS_IDOMNSHTMLANCHORELEMENT2_IID)

  /* attribute DOMString ping; */
  NS_SCRIPTABLE NS_IMETHOD GetPing(nsAString & aPing) = 0;
  NS_SCRIPTABLE NS_IMETHOD SetPing(const nsAString & aPing) = 0;

};

  NS_DEFINE_STATIC_IID_ACCESSOR(nsIDOMNSHTMLAnchorElement2, NS_IDOMNSHTMLANCHORELEMENT2_IID)

/* Use this macro when declaring classes that implement this interface. */
#define NS_DECL_NSIDOMNSHTMLANCHORELEMENT2 \
  NS_SCRIPTABLE NS_IMETHOD GetPing(nsAString & aPing); \
  NS_SCRIPTABLE NS_IMETHOD SetPing(const nsAString & aPing); 

/* Use this macro to declare functions that forward the behavior of this interface to another object. */
#define NS_FORWARD_NSIDOMNSHTMLANCHORELEMENT2(_to) \
  NS_SCRIPTABLE NS_IMETHOD GetPing(nsAString & aPing) { return _to GetPing(aPing); } \
  NS_SCRIPTABLE NS_IMETHOD SetPing(const nsAString & aPing) { return _to SetPing(aPing); } 

/* Use this macro to declare functions that forward the behavior of this interface to another object in a safe way. */
#define NS_FORWARD_SAFE_NSIDOMNSHTMLANCHORELEMENT2(_to) \
  NS_SCRIPTABLE NS_IMETHOD GetPing(nsAString & aPing) { return !_to ? NS_ERROR_NULL_POINTER : _to->GetPing(aPing); } \
  NS_SCRIPTABLE NS_IMETHOD SetPing(const nsAString & aPing) { return !_to ? NS_ERROR_NULL_POINTER : _to->SetPing(aPing); } 

#if 0
/* Use the code below as a template for the implementation class for this interface. */

/* Header file */
class nsDOMNSHTMLAnchorElement2 : public nsIDOMNSHTMLAnchorElement2
{
public:
  NS_DECL_ISUPPORTS
  NS_DECL_NSIDOMNSHTMLANCHORELEMENT2

  nsDOMNSHTMLAnchorElement2();

private:
  ~nsDOMNSHTMLAnchorElement2();

protected:
  /* additional members */
};

/* Implementation file */
NS_IMPL_ISUPPORTS1(nsDOMNSHTMLAnchorElement2, nsIDOMNSHTMLAnchorElement2)

nsDOMNSHTMLAnchorElement2::nsDOMNSHTMLAnchorElement2()
{
  /* member initializers and constructor code */
}

nsDOMNSHTMLAnchorElement2::~nsDOMNSHTMLAnchorElement2()
{
  /* destructor code */
}

/* attribute DOMString ping; */
NS_IMETHODIMP nsDOMNSHTMLAnchorElement2::GetPing(nsAString & aPing)
{
    return NS_ERROR_NOT_IMPLEMENTED;
}
NS_IMETHODIMP nsDOMNSHTMLAnchorElement2::SetPing(const nsAString & aPing)
{
    return NS_ERROR_NOT_IMPLEMENTED;
}

/* End of implementation class template. */
#endif


#endif /* __gen_nsIDOMNSHTMLAnchorElement2_h__ */
