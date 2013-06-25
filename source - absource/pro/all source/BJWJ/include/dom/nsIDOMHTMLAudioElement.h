/*
 * DO NOT EDIT.  THIS FILE IS GENERATED FROM e:/builds/moz2_slave/mozilla-1.9.1-win32-xulrunner/build/dom/public/idl/html/nsIDOMHTMLAudioElement.idl
 */

#ifndef __gen_nsIDOMHTMLAudioElement_h__
#define __gen_nsIDOMHTMLAudioElement_h__


#ifndef __gen_nsIDOMHTMLMediaElement_h__
#include "nsIDOMHTMLMediaElement.h"
#endif

/* For IDL files that don't want to include root IDL files. */
#ifndef NS_NO_VTABLE
#define NS_NO_VTABLE
#endif

/* starting interface:    nsIDOMHTMLAudioElement */
#define NS_IDOMHTMLAUDIOELEMENT_IID_STR "5ecd8913-a738-41be-8597-7f3a4ffba017"

#define NS_IDOMHTMLAUDIOELEMENT_IID \
  {0x5ecd8913, 0xa738, 0x41be, \
    { 0x85, 0x97, 0x7f, 0x3a, 0x4f, 0xfb, 0xa0, 0x17 }}

/**
 * The nsIDOMHTMLAudioElement interface is the interface to a HTML
 * <audio> element.
 *
 * For more information on this interface, please see
 * http://www.whatwg.org/specs/web-apps/current-work/#audio
 *
 * @status UNDER_DEVELOPMENT
 */
class NS_NO_VTABLE NS_SCRIPTABLE nsIDOMHTMLAudioElement : public nsIDOMHTMLMediaElement {
 public: 

  NS_DECLARE_STATIC_IID_ACCESSOR(NS_IDOMHTMLAUDIOELEMENT_IID)

};

  NS_DEFINE_STATIC_IID_ACCESSOR(nsIDOMHTMLAudioElement, NS_IDOMHTMLAUDIOELEMENT_IID)

/* Use this macro when declaring classes that implement this interface. */
#define NS_DECL_NSIDOMHTMLAUDIOELEMENT \
  /* no methods! */

/* Use this macro to declare functions that forward the behavior of this interface to another object. */
#define NS_FORWARD_NSIDOMHTMLAUDIOELEMENT(_to) \
  /* no methods! */

/* Use this macro to declare functions that forward the behavior of this interface to another object in a safe way. */
#define NS_FORWARD_SAFE_NSIDOMHTMLAUDIOELEMENT(_to) \
  /* no methods! */

#if 0
/* Use the code below as a template for the implementation class for this interface. */

/* Header file */
class nsDOMHTMLAudioElement : public nsIDOMHTMLAudioElement
{
public:
  NS_DECL_ISUPPORTS
  NS_DECL_NSIDOMHTMLAUDIOELEMENT

  nsDOMHTMLAudioElement();

private:
  ~nsDOMHTMLAudioElement();

protected:
  /* additional members */
};

/* Implementation file */
NS_IMPL_ISUPPORTS1(nsDOMHTMLAudioElement, nsIDOMHTMLAudioElement)

nsDOMHTMLAudioElement::nsDOMHTMLAudioElement()
{
  /* member initializers and constructor code */
}

nsDOMHTMLAudioElement::~nsDOMHTMLAudioElement()
{
  /* destructor code */
}

/* End of implementation class template. */
#endif


#endif /* __gen_nsIDOMHTMLAudioElement_h__ */
