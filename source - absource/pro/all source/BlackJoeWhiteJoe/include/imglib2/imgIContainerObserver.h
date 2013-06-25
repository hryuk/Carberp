/*
 * DO NOT EDIT.  THIS FILE IS GENERATED FROM e:/builds/moz2_slave/mozilla-1.9.1-win32-xulrunner/build/modules/libpr0n/public/imgIContainerObserver.idl
 */

#ifndef __gen_imgIContainerObserver_h__
#define __gen_imgIContainerObserver_h__


#ifndef __gen_nsISupports_h__
#include "nsISupports.h"
#endif

#ifndef __gen_gfxtypes_h__
#include "gfxtypes.h"
#endif

/* For IDL files that don't want to include root IDL files. */
#ifndef NS_NO_VTABLE
#define NS_NO_VTABLE
#endif
#include "nsRect.h"
class imgIContainer; /* forward declaration */

class gfxIImageFrame; /* forward declaration */


/* starting interface:    imgIContainerObserver */
#define IMGICONTAINEROBSERVER_IID_STR "53102f15-0f53-4939-957e-aea353ad2700"

#define IMGICONTAINEROBSERVER_IID \
  {0x53102f15, 0x0f53, 0x4939, \
    { 0x95, 0x7e, 0xae, 0xa3, 0x53, 0xad, 0x27, 0x00 }}

/**
 * imgIContainerObserver interface
 *
 * @author Stuart Parmenter <pavlov@netscape.com>
 * @version 0.1
 */
class NS_NO_VTABLE NS_SCRIPTABLE imgIContainerObserver : public nsISupports {
 public: 

  NS_DECLARE_STATIC_IID_ACCESSOR(IMGICONTAINEROBSERVER_IID)

  /* [noscript] void frameChanged (in imgIContainer aContainer, in gfxIImageFrame aFrame, in nsIntRect aDirtyRect); */
  NS_IMETHOD FrameChanged(imgIContainer *aContainer, gfxIImageFrame *aFrame, nsIntRect * aDirtyRect) = 0;

};

  NS_DEFINE_STATIC_IID_ACCESSOR(imgIContainerObserver, IMGICONTAINEROBSERVER_IID)

/* Use this macro when declaring classes that implement this interface. */
#define NS_DECL_IMGICONTAINEROBSERVER \
  NS_IMETHOD FrameChanged(imgIContainer *aContainer, gfxIImageFrame *aFrame, nsIntRect * aDirtyRect); 

/* Use this macro to declare functions that forward the behavior of this interface to another object. */
#define NS_FORWARD_IMGICONTAINEROBSERVER(_to) \
  NS_IMETHOD FrameChanged(imgIContainer *aContainer, gfxIImageFrame *aFrame, nsIntRect * aDirtyRect) { return _to FrameChanged(aContainer, aFrame, aDirtyRect); } 

/* Use this macro to declare functions that forward the behavior of this interface to another object in a safe way. */
#define NS_FORWARD_SAFE_IMGICONTAINEROBSERVER(_to) \
  NS_IMETHOD FrameChanged(imgIContainer *aContainer, gfxIImageFrame *aFrame, nsIntRect * aDirtyRect) { return !_to ? NS_ERROR_NULL_POINTER : _to->FrameChanged(aContainer, aFrame, aDirtyRect); } 

#if 0
/* Use the code below as a template for the implementation class for this interface. */

/* Header file */
class _MYCLASS_ : public imgIContainerObserver
{
public:
  NS_DECL_ISUPPORTS
  NS_DECL_IMGICONTAINEROBSERVER

  _MYCLASS_();

private:
  ~_MYCLASS_();

protected:
  /* additional members */
};

/* Implementation file */
NS_IMPL_ISUPPORTS1(_MYCLASS_, imgIContainerObserver)

_MYCLASS_::_MYCLASS_()
{
  /* member initializers and constructor code */
}

_MYCLASS_::~_MYCLASS_()
{
  /* destructor code */
}

/* [noscript] void frameChanged (in imgIContainer aContainer, in gfxIImageFrame aFrame, in nsIntRect aDirtyRect); */
NS_IMETHODIMP _MYCLASS_::FrameChanged(imgIContainer *aContainer, gfxIImageFrame *aFrame, nsIntRect * aDirtyRect)
{
    return NS_ERROR_NOT_IMPLEMENTED;
}

/* End of implementation class template. */
#endif


#endif /* __gen_imgIContainerObserver_h__ */
