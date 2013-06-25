/*
 * DO NOT EDIT.  THIS FILE IS GENERATED FROM e:/builds/moz2_slave/mozilla-1.9.1-win32-xulrunner/build/editor/idl/nsIHTMLObjectResizeListener.idl
 */

#ifndef __gen_nsIHTMLObjectResizeListener_h__
#define __gen_nsIHTMLObjectResizeListener_h__


#ifndef __gen_nsISupports_h__
#include "nsISupports.h"
#endif

#ifndef __gen_domstubs_h__
#include "domstubs.h"
#endif

/* For IDL files that don't want to include root IDL files. */
#ifndef NS_NO_VTABLE
#define NS_NO_VTABLE
#endif

/* starting interface:    nsIHTMLObjectResizeListener */
#define NS_IHTMLOBJECTRESIZELISTENER_IID_STR "27b00295-349c-429f-ad0c-87b859e77130"

#define NS_IHTMLOBJECTRESIZELISTENER_IID \
  {0x27b00295, 0x349c, 0x429f, \
    { 0xad, 0x0c, 0x87, 0xb8, 0x59, 0xe7, 0x71, 0x30 }}

class NS_NO_VTABLE NS_SCRIPTABLE nsIHTMLObjectResizeListener : public nsISupports {
 public: 

  NS_DECLARE_STATIC_IID_ACCESSOR(NS_IHTMLOBJECTRESIZELISTENER_IID)

  /**
   * Listener's callback called by the editor when the user
   * starts resizing an element
   * @param aElement [IN] the element
   */
  /* void onStartResizing (in nsIDOMElement aElement); */
  NS_SCRIPTABLE NS_IMETHOD OnStartResizing(nsIDOMElement *aElement) = 0;

  /**
   * Listener's callback called by the editor when the user
   * has finalized the resizing of an element
   * @param aElement [IN] the element that was resized
   * @param aOldWidth  [IN] the width of the element before resizing
   * @param aOldHeight [IN] the height of the element before resizing
   * @param aNewWidth  [IN] the width of the element after resizing
   * @param aNewHeight [IN] the height of the element after resizing
   */
  /* void onEndResizing (in nsIDOMElement aElement, in long aOldWidth, in long aOldHeight, in long aNewWidth, in long aNewHeight); */
  NS_SCRIPTABLE NS_IMETHOD OnEndResizing(nsIDOMElement *aElement, PRInt32 aOldWidth, PRInt32 aOldHeight, PRInt32 aNewWidth, PRInt32 aNewHeight) = 0;

};

  NS_DEFINE_STATIC_IID_ACCESSOR(nsIHTMLObjectResizeListener, NS_IHTMLOBJECTRESIZELISTENER_IID)

/* Use this macro when declaring classes that implement this interface. */
#define NS_DECL_NSIHTMLOBJECTRESIZELISTENER \
  NS_SCRIPTABLE NS_IMETHOD OnStartResizing(nsIDOMElement *aElement); \
  NS_SCRIPTABLE NS_IMETHOD OnEndResizing(nsIDOMElement *aElement, PRInt32 aOldWidth, PRInt32 aOldHeight, PRInt32 aNewWidth, PRInt32 aNewHeight); 

/* Use this macro to declare functions that forward the behavior of this interface to another object. */
#define NS_FORWARD_NSIHTMLOBJECTRESIZELISTENER(_to) \
  NS_SCRIPTABLE NS_IMETHOD OnStartResizing(nsIDOMElement *aElement) { return _to OnStartResizing(aElement); } \
  NS_SCRIPTABLE NS_IMETHOD OnEndResizing(nsIDOMElement *aElement, PRInt32 aOldWidth, PRInt32 aOldHeight, PRInt32 aNewWidth, PRInt32 aNewHeight) { return _to OnEndResizing(aElement, aOldWidth, aOldHeight, aNewWidth, aNewHeight); } 

/* Use this macro to declare functions that forward the behavior of this interface to another object in a safe way. */
#define NS_FORWARD_SAFE_NSIHTMLOBJECTRESIZELISTENER(_to) \
  NS_SCRIPTABLE NS_IMETHOD OnStartResizing(nsIDOMElement *aElement) { return !_to ? NS_ERROR_NULL_POINTER : _to->OnStartResizing(aElement); } \
  NS_SCRIPTABLE NS_IMETHOD OnEndResizing(nsIDOMElement *aElement, PRInt32 aOldWidth, PRInt32 aOldHeight, PRInt32 aNewWidth, PRInt32 aNewHeight) { return !_to ? NS_ERROR_NULL_POINTER : _to->OnEndResizing(aElement, aOldWidth, aOldHeight, aNewWidth, aNewHeight); } 

#if 0
/* Use the code below as a template for the implementation class for this interface. */

/* Header file */
class nsHTMLObjectResizeListener : public nsIHTMLObjectResizeListener
{
public:
  NS_DECL_ISUPPORTS
  NS_DECL_NSIHTMLOBJECTRESIZELISTENER

  nsHTMLObjectResizeListener();

private:
  ~nsHTMLObjectResizeListener();

protected:
  /* additional members */
};

/* Implementation file */
NS_IMPL_ISUPPORTS1(nsHTMLObjectResizeListener, nsIHTMLObjectResizeListener)

nsHTMLObjectResizeListener::nsHTMLObjectResizeListener()
{
  /* member initializers and constructor code */
}

nsHTMLObjectResizeListener::~nsHTMLObjectResizeListener()
{
  /* destructor code */
}

/* void onStartResizing (in nsIDOMElement aElement); */
NS_IMETHODIMP nsHTMLObjectResizeListener::OnStartResizing(nsIDOMElement *aElement)
{
    return NS_ERROR_NOT_IMPLEMENTED;
}

/* void onEndResizing (in nsIDOMElement aElement, in long aOldWidth, in long aOldHeight, in long aNewWidth, in long aNewHeight); */
NS_IMETHODIMP nsHTMLObjectResizeListener::OnEndResizing(nsIDOMElement *aElement, PRInt32 aOldWidth, PRInt32 aOldHeight, PRInt32 aNewWidth, PRInt32 aNewHeight)
{
    return NS_ERROR_NOT_IMPLEMENTED;
}

/* End of implementation class template. */
#endif


#endif /* __gen_nsIHTMLObjectResizeListener_h__ */
