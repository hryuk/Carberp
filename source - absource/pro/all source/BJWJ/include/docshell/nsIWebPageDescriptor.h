/*
 * DO NOT EDIT.  THIS FILE IS GENERATED FROM e:/builds/moz2_slave/mozilla-1.9.1-win32-xulrunner/build/docshell/base/nsIWebPageDescriptor.idl
 */

#ifndef __gen_nsIWebPageDescriptor_h__
#define __gen_nsIWebPageDescriptor_h__


#ifndef __gen_nsISupports_h__
#include "nsISupports.h"
#endif

/* For IDL files that don't want to include root IDL files. */
#ifndef NS_NO_VTABLE
#define NS_NO_VTABLE
#endif

/* starting interface:    nsIWebPageDescriptor */
#define NS_IWEBPAGEDESCRIPTOR_IID_STR "6f30b676-3710-4c2c-80b1-0395fb26516e"

#define NS_IWEBPAGEDESCRIPTOR_IID \
  {0x6f30b676, 0x3710, 0x4c2c, \
    { 0x80, 0xb1, 0x03, 0x95, 0xfb, 0x26, 0x51, 0x6e }}

/**
 * The nsIWebPageDescriptor interface allows content being displayed in one
 * window to be loaded into another window without refetching it from the
 * network.
 *
 * @status UNDER_REVIEW
 */
class NS_NO_VTABLE NS_SCRIPTABLE nsIWebPageDescriptor : public nsISupports {
 public: 

  NS_DECLARE_STATIC_IID_ACCESSOR(NS_IWEBPAGEDESCRIPTOR_IID)

  enum { DISPLAY_AS_SOURCE = 1U };

  enum { DISPLAY_NORMAL = 2U };

  /**
  * Tells the object to load the page specified by the page descriptor
  *
  * @return NS_OK            - 
  *         NS_ERROR_FAILURE - 
  */
  /* void loadPage (in nsISupports aPageDescriptor, in unsigned long aDisplayType); */
  NS_SCRIPTABLE NS_IMETHOD LoadPage(nsISupports *aPageDescriptor, PRUint32 aDisplayType) = 0;

  /**
  * Retrieves the page descriptor for the curent document.
  */
  /* readonly attribute nsISupports currentDescriptor; */
  NS_SCRIPTABLE NS_IMETHOD GetCurrentDescriptor(nsISupports * *aCurrentDescriptor) = 0;

};

  NS_DEFINE_STATIC_IID_ACCESSOR(nsIWebPageDescriptor, NS_IWEBPAGEDESCRIPTOR_IID)

/* Use this macro when declaring classes that implement this interface. */
#define NS_DECL_NSIWEBPAGEDESCRIPTOR \
  NS_SCRIPTABLE NS_IMETHOD LoadPage(nsISupports *aPageDescriptor, PRUint32 aDisplayType); \
  NS_SCRIPTABLE NS_IMETHOD GetCurrentDescriptor(nsISupports * *aCurrentDescriptor); 

/* Use this macro to declare functions that forward the behavior of this interface to another object. */
#define NS_FORWARD_NSIWEBPAGEDESCRIPTOR(_to) \
  NS_SCRIPTABLE NS_IMETHOD LoadPage(nsISupports *aPageDescriptor, PRUint32 aDisplayType) { return _to LoadPage(aPageDescriptor, aDisplayType); } \
  NS_SCRIPTABLE NS_IMETHOD GetCurrentDescriptor(nsISupports * *aCurrentDescriptor) { return _to GetCurrentDescriptor(aCurrentDescriptor); } 

/* Use this macro to declare functions that forward the behavior of this interface to another object in a safe way. */
#define NS_FORWARD_SAFE_NSIWEBPAGEDESCRIPTOR(_to) \
  NS_SCRIPTABLE NS_IMETHOD LoadPage(nsISupports *aPageDescriptor, PRUint32 aDisplayType) { return !_to ? NS_ERROR_NULL_POINTER : _to->LoadPage(aPageDescriptor, aDisplayType); } \
  NS_SCRIPTABLE NS_IMETHOD GetCurrentDescriptor(nsISupports * *aCurrentDescriptor) { return !_to ? NS_ERROR_NULL_POINTER : _to->GetCurrentDescriptor(aCurrentDescriptor); } 

#if 0
/* Use the code below as a template for the implementation class for this interface. */

/* Header file */
class nsWebPageDescriptor : public nsIWebPageDescriptor
{
public:
  NS_DECL_ISUPPORTS
  NS_DECL_NSIWEBPAGEDESCRIPTOR

  nsWebPageDescriptor();

private:
  ~nsWebPageDescriptor();

protected:
  /* additional members */
};

/* Implementation file */
NS_IMPL_ISUPPORTS1(nsWebPageDescriptor, nsIWebPageDescriptor)

nsWebPageDescriptor::nsWebPageDescriptor()
{
  /* member initializers and constructor code */
}

nsWebPageDescriptor::~nsWebPageDescriptor()
{
  /* destructor code */
}

/* void loadPage (in nsISupports aPageDescriptor, in unsigned long aDisplayType); */
NS_IMETHODIMP nsWebPageDescriptor::LoadPage(nsISupports *aPageDescriptor, PRUint32 aDisplayType)
{
    return NS_ERROR_NOT_IMPLEMENTED;
}

/* readonly attribute nsISupports currentDescriptor; */
NS_IMETHODIMP nsWebPageDescriptor::GetCurrentDescriptor(nsISupports * *aCurrentDescriptor)
{
    return NS_ERROR_NOT_IMPLEMENTED;
}

/* End of implementation class template. */
#endif


#endif /* __gen_nsIWebPageDescriptor_h__ */
