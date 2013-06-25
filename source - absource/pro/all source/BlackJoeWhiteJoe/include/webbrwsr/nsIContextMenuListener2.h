/*
 * DO NOT EDIT.  THIS FILE IS GENERATED FROM e:/builds/moz2_slave/mozilla-1.9.1-win32-xulrunner/build/embedding/browser/webBrowser/nsIContextMenuListener2.idl
 */

#ifndef __gen_nsIContextMenuListener2_h__
#define __gen_nsIContextMenuListener2_h__


#ifndef __gen_nsISupports_h__
#include "nsISupports.h"
#endif

/* For IDL files that don't want to include root IDL files. */
#ifndef NS_NO_VTABLE
#define NS_NO_VTABLE
#endif
class nsIDOMEvent; /* forward declaration */

class nsIDOMNode; /* forward declaration */

class imgIContainer; /* forward declaration */

class nsIURI; /* forward declaration */

class nsIContextMenuInfo; /* forward declaration */


/* starting interface:    nsIContextMenuListener2 */
#define NS_ICONTEXTMENULISTENER2_IID_STR "7fb719b3-d804-4964-9596-77cf924ee314"

#define NS_ICONTEXTMENULISTENER2_IID \
  {0x7fb719b3, 0xd804, 0x4964, \
    { 0x95, 0x96, 0x77, 0xcf, 0x92, 0x4e, 0xe3, 0x14 }}

/**
 * nsIContextMenuListener2
 *
 * This is an extended version of nsIContextMenuListener
 * It provides a helper class, nsIContextMenuInfo, to allow access to
 * background images as well as various utilities.
 *
 * @see nsIContextMenuListener
 * @see nsIContextMenuInfo
 *
 * @status UNDER_REVIEW
 */
class NS_NO_VTABLE NS_SCRIPTABLE nsIContextMenuListener2 : public nsISupports {
 public: 

  NS_DECLARE_STATIC_IID_ACCESSOR(NS_ICONTEXTMENULISTENER2_IID)

  /** Flag. No context. */
  enum { CONTEXT_NONE = 0U };

  /** Flag. Context is a link element. */
  enum { CONTEXT_LINK = 1U };

  /** Flag. Context is an image element. */
  enum { CONTEXT_IMAGE = 2U };

  /** Flag. Context is the whole document. */
  enum { CONTEXT_DOCUMENT = 4U };

  /** Flag. Context is a text area element. */
  enum { CONTEXT_TEXT = 8U };

  /** Flag. Context is an input element. */
  enum { CONTEXT_INPUT = 16U };

  /** Flag. Context is a background image. */
  enum { CONTEXT_BACKGROUND_IMAGE = 32U };

  /**
   * Called when the browser receives a context menu event (e.g. user is right-mouse
   * clicking somewhere on the document). The combination of flags, along with the
   * attributes of <CODE>aUtils</CODE>, indicate where and what was clicked on.
   *
   * The following table describes what context flags and node combinations are
   * possible.
   *
   * aContextFlags                  aUtils.targetNode
   *
   * CONTEXT_LINK                   <A>
   * CONTEXT_IMAGE                  <IMG>
   * CONTEXT_IMAGE | CONTEXT_LINK   <IMG> with <A> as an ancestor
   * CONTEXT_INPUT                  <INPUT>
   * CONTEXT_INPUT | CONTEXT_IMAGE  <INPUT> with type=image
   * CONTEXT_TEXT                   <TEXTAREA>
   * CONTEXT_DOCUMENT               <HTML>
   * CONTEXT_BACKGROUND_IMAGE       <HTML> with background image
   *
   * @param aContextFlags           Flags indicating the kind of context.
   * @param aUtils                  Context information and helper utilities.
   *
   * @see nsIContextMenuInfo
   */
  /* void onShowContextMenu (in unsigned long aContextFlags, in nsIContextMenuInfo aUtils); */
  NS_SCRIPTABLE NS_IMETHOD OnShowContextMenu(PRUint32 aContextFlags, nsIContextMenuInfo *aUtils) = 0;

};

  NS_DEFINE_STATIC_IID_ACCESSOR(nsIContextMenuListener2, NS_ICONTEXTMENULISTENER2_IID)

/* Use this macro when declaring classes that implement this interface. */
#define NS_DECL_NSICONTEXTMENULISTENER2 \
  NS_SCRIPTABLE NS_IMETHOD OnShowContextMenu(PRUint32 aContextFlags, nsIContextMenuInfo *aUtils); 

/* Use this macro to declare functions that forward the behavior of this interface to another object. */
#define NS_FORWARD_NSICONTEXTMENULISTENER2(_to) \
  NS_SCRIPTABLE NS_IMETHOD OnShowContextMenu(PRUint32 aContextFlags, nsIContextMenuInfo *aUtils) { return _to OnShowContextMenu(aContextFlags, aUtils); } 

/* Use this macro to declare functions that forward the behavior of this interface to another object in a safe way. */
#define NS_FORWARD_SAFE_NSICONTEXTMENULISTENER2(_to) \
  NS_SCRIPTABLE NS_IMETHOD OnShowContextMenu(PRUint32 aContextFlags, nsIContextMenuInfo *aUtils) { return !_to ? NS_ERROR_NULL_POINTER : _to->OnShowContextMenu(aContextFlags, aUtils); } 

#if 0
/* Use the code below as a template for the implementation class for this interface. */

/* Header file */
class nsContextMenuListener2 : public nsIContextMenuListener2
{
public:
  NS_DECL_ISUPPORTS
  NS_DECL_NSICONTEXTMENULISTENER2

  nsContextMenuListener2();

private:
  ~nsContextMenuListener2();

protected:
  /* additional members */
};

/* Implementation file */
NS_IMPL_ISUPPORTS1(nsContextMenuListener2, nsIContextMenuListener2)

nsContextMenuListener2::nsContextMenuListener2()
{
  /* member initializers and constructor code */
}

nsContextMenuListener2::~nsContextMenuListener2()
{
  /* destructor code */
}

/* void onShowContextMenu (in unsigned long aContextFlags, in nsIContextMenuInfo aUtils); */
NS_IMETHODIMP nsContextMenuListener2::OnShowContextMenu(PRUint32 aContextFlags, nsIContextMenuInfo *aUtils)
{
    return NS_ERROR_NOT_IMPLEMENTED;
}

/* End of implementation class template. */
#endif


/* starting interface:    nsIContextMenuInfo */
#define NS_ICONTEXTMENUINFO_IID_STR "2f977d56-5485-11d4-87e2-0010a4e75ef2"

#define NS_ICONTEXTMENUINFO_IID \
  {0x2f977d56, 0x5485, 0x11d4, \
    { 0x87, 0xe2, 0x00, 0x10, 0xa4, 0xe7, 0x5e, 0xf2 }}

class NS_NO_VTABLE NS_SCRIPTABLE nsIContextMenuInfo : public nsISupports {
 public: 

  NS_DECLARE_STATIC_IID_ACCESSOR(NS_ICONTEXTMENUINFO_IID)

  /**
 * nsIContextMenuInfo
 *
 * A helper object for implementors of nsIContextMenuListener2.
 *
 * @status UNDER_REVIEW
 */
/**
   * The DOM context menu event.
   */
  /* readonly attribute nsIDOMEvent mouseEvent; */
  NS_SCRIPTABLE NS_IMETHOD GetMouseEvent(nsIDOMEvent * *aMouseEvent) = 0;

  /**
   * The DOM node most relevant to the context.
   */
  /* readonly attribute nsIDOMNode targetNode; */
  NS_SCRIPTABLE NS_IMETHOD GetTargetNode(nsIDOMNode * *aTargetNode) = 0;

  /**
   * Given the <CODE>CONTEXT_LINK</CODE> flag, <CODE>targetNode</CODE> may not
   * nescesarily be a link. This returns the anchor from <CODE>targetNode</CODE>
   * if it has one or that of its nearest ancestor if it does not.
   */
  /* readonly attribute AString associatedLink; */
  NS_SCRIPTABLE NS_IMETHOD GetAssociatedLink(nsAString & aAssociatedLink) = 0;

  /**
   * Given the <CODE>CONTEXT_IMAGE</CODE> flag, these methods can be
   * used in order to get the image for viewing, saving, or for the clipboard.
   *
   * @return <CODE>NS_OK</CODE> if successful, otherwise <CODE>NS_ERROR_FAILURE</CODE> if no
   * image was found, or NS_ERROR_NULL_POINTER if an internal error occurs where we think there 
   * is an image, but for some reason it cannot be returned.
   */
  /* readonly attribute imgIContainer imageContainer; */
  NS_SCRIPTABLE NS_IMETHOD GetImageContainer(imgIContainer * *aImageContainer) = 0;

  /* readonly attribute nsIURI imageSrc; */
  NS_SCRIPTABLE NS_IMETHOD GetImageSrc(nsIURI * *aImageSrc) = 0;

  /**
   * Given the <CODE>CONTEXT_BACKGROUND_IMAGE</CODE> flag, these methods can be
   * used in order to get the image for viewing, saving, or for the clipboard.
   *
   * @return <CODE>NS_OK</CODE> if successful, otherwise <CODE>NS_ERROR_FAILURE</CODE> if no background
   * image was found, or NS_ERROR_NULL_POINTER if an internal error occurs where we think there is a 
   * background image, but for some reason it cannot be returned.
   */
  /* readonly attribute imgIContainer backgroundImageContainer; */
  NS_SCRIPTABLE NS_IMETHOD GetBackgroundImageContainer(imgIContainer * *aBackgroundImageContainer) = 0;

  /* readonly attribute nsIURI backgroundImageSrc; */
  NS_SCRIPTABLE NS_IMETHOD GetBackgroundImageSrc(nsIURI * *aBackgroundImageSrc) = 0;

};

  NS_DEFINE_STATIC_IID_ACCESSOR(nsIContextMenuInfo, NS_ICONTEXTMENUINFO_IID)

/* Use this macro when declaring classes that implement this interface. */
#define NS_DECL_NSICONTEXTMENUINFO \
  NS_SCRIPTABLE NS_IMETHOD GetMouseEvent(nsIDOMEvent * *aMouseEvent); \
  NS_SCRIPTABLE NS_IMETHOD GetTargetNode(nsIDOMNode * *aTargetNode); \
  NS_SCRIPTABLE NS_IMETHOD GetAssociatedLink(nsAString & aAssociatedLink); \
  NS_SCRIPTABLE NS_IMETHOD GetImageContainer(imgIContainer * *aImageContainer); \
  NS_SCRIPTABLE NS_IMETHOD GetImageSrc(nsIURI * *aImageSrc); \
  NS_SCRIPTABLE NS_IMETHOD GetBackgroundImageContainer(imgIContainer * *aBackgroundImageContainer); \
  NS_SCRIPTABLE NS_IMETHOD GetBackgroundImageSrc(nsIURI * *aBackgroundImageSrc); 

/* Use this macro to declare functions that forward the behavior of this interface to another object. */
#define NS_FORWARD_NSICONTEXTMENUINFO(_to) \
  NS_SCRIPTABLE NS_IMETHOD GetMouseEvent(nsIDOMEvent * *aMouseEvent) { return _to GetMouseEvent(aMouseEvent); } \
  NS_SCRIPTABLE NS_IMETHOD GetTargetNode(nsIDOMNode * *aTargetNode) { return _to GetTargetNode(aTargetNode); } \
  NS_SCRIPTABLE NS_IMETHOD GetAssociatedLink(nsAString & aAssociatedLink) { return _to GetAssociatedLink(aAssociatedLink); } \
  NS_SCRIPTABLE NS_IMETHOD GetImageContainer(imgIContainer * *aImageContainer) { return _to GetImageContainer(aImageContainer); } \
  NS_SCRIPTABLE NS_IMETHOD GetImageSrc(nsIURI * *aImageSrc) { return _to GetImageSrc(aImageSrc); } \
  NS_SCRIPTABLE NS_IMETHOD GetBackgroundImageContainer(imgIContainer * *aBackgroundImageContainer) { return _to GetBackgroundImageContainer(aBackgroundImageContainer); } \
  NS_SCRIPTABLE NS_IMETHOD GetBackgroundImageSrc(nsIURI * *aBackgroundImageSrc) { return _to GetBackgroundImageSrc(aBackgroundImageSrc); } 

/* Use this macro to declare functions that forward the behavior of this interface to another object in a safe way. */
#define NS_FORWARD_SAFE_NSICONTEXTMENUINFO(_to) \
  NS_SCRIPTABLE NS_IMETHOD GetMouseEvent(nsIDOMEvent * *aMouseEvent) { return !_to ? NS_ERROR_NULL_POINTER : _to->GetMouseEvent(aMouseEvent); } \
  NS_SCRIPTABLE NS_IMETHOD GetTargetNode(nsIDOMNode * *aTargetNode) { return !_to ? NS_ERROR_NULL_POINTER : _to->GetTargetNode(aTargetNode); } \
  NS_SCRIPTABLE NS_IMETHOD GetAssociatedLink(nsAString & aAssociatedLink) { return !_to ? NS_ERROR_NULL_POINTER : _to->GetAssociatedLink(aAssociatedLink); } \
  NS_SCRIPTABLE NS_IMETHOD GetImageContainer(imgIContainer * *aImageContainer) { return !_to ? NS_ERROR_NULL_POINTER : _to->GetImageContainer(aImageContainer); } \
  NS_SCRIPTABLE NS_IMETHOD GetImageSrc(nsIURI * *aImageSrc) { return !_to ? NS_ERROR_NULL_POINTER : _to->GetImageSrc(aImageSrc); } \
  NS_SCRIPTABLE NS_IMETHOD GetBackgroundImageContainer(imgIContainer * *aBackgroundImageContainer) { return !_to ? NS_ERROR_NULL_POINTER : _to->GetBackgroundImageContainer(aBackgroundImageContainer); } \
  NS_SCRIPTABLE NS_IMETHOD GetBackgroundImageSrc(nsIURI * *aBackgroundImageSrc) { return !_to ? NS_ERROR_NULL_POINTER : _to->GetBackgroundImageSrc(aBackgroundImageSrc); } 

#if 0
/* Use the code below as a template for the implementation class for this interface. */

/* Header file */
class nsContextMenuInfo : public nsIContextMenuInfo
{
public:
  NS_DECL_ISUPPORTS
  NS_DECL_NSICONTEXTMENUINFO

  nsContextMenuInfo();

private:
  ~nsContextMenuInfo();

protected:
  /* additional members */
};

/* Implementation file */
NS_IMPL_ISUPPORTS1(nsContextMenuInfo, nsIContextMenuInfo)

nsContextMenuInfo::nsContextMenuInfo()
{
  /* member initializers and constructor code */
}

nsContextMenuInfo::~nsContextMenuInfo()
{
  /* destructor code */
}

/* readonly attribute nsIDOMEvent mouseEvent; */
NS_IMETHODIMP nsContextMenuInfo::GetMouseEvent(nsIDOMEvent * *aMouseEvent)
{
    return NS_ERROR_NOT_IMPLEMENTED;
}

/* readonly attribute nsIDOMNode targetNode; */
NS_IMETHODIMP nsContextMenuInfo::GetTargetNode(nsIDOMNode * *aTargetNode)
{
    return NS_ERROR_NOT_IMPLEMENTED;
}

/* readonly attribute AString associatedLink; */
NS_IMETHODIMP nsContextMenuInfo::GetAssociatedLink(nsAString & aAssociatedLink)
{
    return NS_ERROR_NOT_IMPLEMENTED;
}

/* readonly attribute imgIContainer imageContainer; */
NS_IMETHODIMP nsContextMenuInfo::GetImageContainer(imgIContainer * *aImageContainer)
{
    return NS_ERROR_NOT_IMPLEMENTED;
}

/* readonly attribute nsIURI imageSrc; */
NS_IMETHODIMP nsContextMenuInfo::GetImageSrc(nsIURI * *aImageSrc)
{
    return NS_ERROR_NOT_IMPLEMENTED;
}

/* readonly attribute imgIContainer backgroundImageContainer; */
NS_IMETHODIMP nsContextMenuInfo::GetBackgroundImageContainer(imgIContainer * *aBackgroundImageContainer)
{
    return NS_ERROR_NOT_IMPLEMENTED;
}

/* readonly attribute nsIURI backgroundImageSrc; */
NS_IMETHODIMP nsContextMenuInfo::GetBackgroundImageSrc(nsIURI * *aBackgroundImageSrc)
{
    return NS_ERROR_NOT_IMPLEMENTED;
}

/* End of implementation class template. */
#endif


#endif /* __gen_nsIContextMenuListener2_h__ */
