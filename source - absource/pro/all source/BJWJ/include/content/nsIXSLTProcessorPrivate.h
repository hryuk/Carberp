/*
 * DO NOT EDIT.  THIS FILE IS GENERATED FROM e:/builds/moz2_slave/mozilla-1.9.1-win32-xulrunner/build/content/xslt/public/nsIXSLTProcessorPrivate.idl
 */

#ifndef __gen_nsIXSLTProcessorPrivate_h__
#define __gen_nsIXSLTProcessorPrivate_h__


#ifndef __gen_nsISupports_h__
#include "nsISupports.h"
#endif

/* For IDL files that don't want to include root IDL files. */
#ifndef NS_NO_VTABLE
#define NS_NO_VTABLE
#endif

/* starting interface:    nsIXSLTProcessorPrivate */
#define NS_IXSLTPROCESSORPRIVATE_IID_STR "b8d727f7-67f4-4dc1-a318-ec0c87280816"

#define NS_IXSLTPROCESSORPRIVATE_IID \
  {0xb8d727f7, 0x67f4, 0x4dc1, \
    { 0xa3, 0x18, 0xec, 0x0c, 0x87, 0x28, 0x08, 0x16 }}

class NS_NO_VTABLE NS_SCRIPTABLE nsIXSLTProcessorPrivate : public nsISupports {
 public: 

  NS_DECLARE_STATIC_IID_ACCESSOR(NS_IXSLTPROCESSORPRIVATE_IID)

  /**
   * Disables all loading of external documents, such as from
   * <xsl:import> and document()
   * Defaults to off and is *not* reset by calls to reset()
   */
  enum { DISABLE_ALL_LOADS = 1U };

  /**
   * Flags for this processor. Defaults to 0. See individual flags above
   * for documentation for effect of reset()
   */
  /* attribute unsigned long flags; */
  NS_SCRIPTABLE NS_IMETHOD GetFlags(PRUint32 *aFlags) = 0;
  NS_SCRIPTABLE NS_IMETHOD SetFlags(PRUint32 aFlags) = 0;

};

  NS_DEFINE_STATIC_IID_ACCESSOR(nsIXSLTProcessorPrivate, NS_IXSLTPROCESSORPRIVATE_IID)

/* Use this macro when declaring classes that implement this interface. */
#define NS_DECL_NSIXSLTPROCESSORPRIVATE \
  NS_SCRIPTABLE NS_IMETHOD GetFlags(PRUint32 *aFlags); \
  NS_SCRIPTABLE NS_IMETHOD SetFlags(PRUint32 aFlags); 

/* Use this macro to declare functions that forward the behavior of this interface to another object. */
#define NS_FORWARD_NSIXSLTPROCESSORPRIVATE(_to) \
  NS_SCRIPTABLE NS_IMETHOD GetFlags(PRUint32 *aFlags) { return _to GetFlags(aFlags); } \
  NS_SCRIPTABLE NS_IMETHOD SetFlags(PRUint32 aFlags) { return _to SetFlags(aFlags); } 

/* Use this macro to declare functions that forward the behavior of this interface to another object in a safe way. */
#define NS_FORWARD_SAFE_NSIXSLTPROCESSORPRIVATE(_to) \
  NS_SCRIPTABLE NS_IMETHOD GetFlags(PRUint32 *aFlags) { return !_to ? NS_ERROR_NULL_POINTER : _to->GetFlags(aFlags); } \
  NS_SCRIPTABLE NS_IMETHOD SetFlags(PRUint32 aFlags) { return !_to ? NS_ERROR_NULL_POINTER : _to->SetFlags(aFlags); } 

#if 0
/* Use the code below as a template for the implementation class for this interface. */

/* Header file */
class nsXSLTProcessorPrivate : public nsIXSLTProcessorPrivate
{
public:
  NS_DECL_ISUPPORTS
  NS_DECL_NSIXSLTPROCESSORPRIVATE

  nsXSLTProcessorPrivate();

private:
  ~nsXSLTProcessorPrivate();

protected:
  /* additional members */
};

/* Implementation file */
NS_IMPL_ISUPPORTS1(nsXSLTProcessorPrivate, nsIXSLTProcessorPrivate)

nsXSLTProcessorPrivate::nsXSLTProcessorPrivate()
{
  /* member initializers and constructor code */
}

nsXSLTProcessorPrivate::~nsXSLTProcessorPrivate()
{
  /* destructor code */
}

/* attribute unsigned long flags; */
NS_IMETHODIMP nsXSLTProcessorPrivate::GetFlags(PRUint32 *aFlags)
{
    return NS_ERROR_NOT_IMPLEMENTED;
}
NS_IMETHODIMP nsXSLTProcessorPrivate::SetFlags(PRUint32 aFlags)
{
    return NS_ERROR_NOT_IMPLEMENTED;
}

/* End of implementation class template. */
#endif


#endif /* __gen_nsIXSLTProcessorPrivate_h__ */
