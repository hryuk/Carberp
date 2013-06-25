/*
 * DO NOT EDIT.  THIS FILE IS GENERATED FROM e:/builds/moz2_slave/mozilla-1.9.1-win32-xulrunner/build/content/base/public/nsIDragDropHandler.idl
 */

#ifndef __gen_nsIDragDropHandler_h__
#define __gen_nsIDragDropHandler_h__


#ifndef __gen_nsISupports_h__
#include "nsISupports.h"
#endif

/* For IDL files that don't want to include root IDL files. */
#ifndef NS_NO_VTABLE
#define NS_NO_VTABLE
#endif
class nsIDOMEventTarget; /* forward declaration */

class nsIWebNavigation; /* forward declaration */


/* starting interface:    nsIDragDropHandler */
#define NS_IDRAGDROPHANDLER_IID_STR "4f418f58-f834-4736-a755-e0395bedca9d"

#define NS_IDRAGDROPHANDLER_IID \
  {0x4f418f58, 0xf834, 0x4736, \
    { 0xa7, 0x55, 0xe0, 0x39, 0x5b, 0xed, 0xca, 0x9d }}

/**
 * @status UNDER_REVIEW
 */
/**
 * Interface for communicating with the built-in drag and drop
 * implementation in the content area. Use this to register where
 * the listeners should attach (something that implements
 * |nsPIDOMEventTarget| which is what we end up using under the hood).
 */
class NS_NO_VTABLE NS_SCRIPTABLE nsIDragDropHandler : public nsISupports {
 public: 

  NS_DECLARE_STATIC_IID_ACCESSOR(NS_IDRAGDROPHANDLER_IID)

  /**
   * Attach drag handlers to receiver specified by |attachPoint| and
   * specify callbacks to allow overriding of the built-in behaviors.
   *
   * @param attachPoint hookup listeners to this location
   * @param navigator loads dropped urls via this interface. If NULL, 
   *                   the client must handle the drop itself, either
   *                   through the method provided via |overrideDrop| or
   *                   by letting the event bubble up through the DOM.
   */
  /* void hookupTo (in nsIDOMEventTarget attachPoint, in nsIWebNavigation navigator); */
  NS_SCRIPTABLE NS_IMETHOD HookupTo(nsIDOMEventTarget *attachPoint, nsIWebNavigation *navigator) = 0;

  /**
   * Unregister all handlers related to drag&drop
   */
  /* void detach (); */
  NS_SCRIPTABLE NS_IMETHOD Detach(void) = 0;

};

  NS_DEFINE_STATIC_IID_ACCESSOR(nsIDragDropHandler, NS_IDRAGDROPHANDLER_IID)

/* Use this macro when declaring classes that implement this interface. */
#define NS_DECL_NSIDRAGDROPHANDLER \
  NS_SCRIPTABLE NS_IMETHOD HookupTo(nsIDOMEventTarget *attachPoint, nsIWebNavigation *navigator); \
  NS_SCRIPTABLE NS_IMETHOD Detach(void); 

/* Use this macro to declare functions that forward the behavior of this interface to another object. */
#define NS_FORWARD_NSIDRAGDROPHANDLER(_to) \
  NS_SCRIPTABLE NS_IMETHOD HookupTo(nsIDOMEventTarget *attachPoint, nsIWebNavigation *navigator) { return _to HookupTo(attachPoint, navigator); } \
  NS_SCRIPTABLE NS_IMETHOD Detach(void) { return _to Detach(); } 

/* Use this macro to declare functions that forward the behavior of this interface to another object in a safe way. */
#define NS_FORWARD_SAFE_NSIDRAGDROPHANDLER(_to) \
  NS_SCRIPTABLE NS_IMETHOD HookupTo(nsIDOMEventTarget *attachPoint, nsIWebNavigation *navigator) { return !_to ? NS_ERROR_NULL_POINTER : _to->HookupTo(attachPoint, navigator); } \
  NS_SCRIPTABLE NS_IMETHOD Detach(void) { return !_to ? NS_ERROR_NULL_POINTER : _to->Detach(); } 

#if 0
/* Use the code below as a template for the implementation class for this interface. */

/* Header file */
class nsDragDropHandler : public nsIDragDropHandler
{
public:
  NS_DECL_ISUPPORTS
  NS_DECL_NSIDRAGDROPHANDLER

  nsDragDropHandler();

private:
  ~nsDragDropHandler();

protected:
  /* additional members */
};

/* Implementation file */
NS_IMPL_ISUPPORTS1(nsDragDropHandler, nsIDragDropHandler)

nsDragDropHandler::nsDragDropHandler()
{
  /* member initializers and constructor code */
}

nsDragDropHandler::~nsDragDropHandler()
{
  /* destructor code */
}

/* void hookupTo (in nsIDOMEventTarget attachPoint, in nsIWebNavigation navigator); */
NS_IMETHODIMP nsDragDropHandler::HookupTo(nsIDOMEventTarget *attachPoint, nsIWebNavigation *navigator)
{
    return NS_ERROR_NOT_IMPLEMENTED;
}

/* void detach (); */
NS_IMETHODIMP nsDragDropHandler::Detach()
{
    return NS_ERROR_NOT_IMPLEMENTED;
}

/* End of implementation class template. */
#endif


#endif /* __gen_nsIDragDropHandler_h__ */
