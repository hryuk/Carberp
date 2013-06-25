/*
 * DO NOT EDIT.  THIS FILE IS GENERATED FROM e:/builds/moz2_slave/mozilla-1.9.1-win32-xulrunner/build/editor/composer/public/nsIEditingSession.idl
 */

#ifndef __gen_nsIEditingSession_h__
#define __gen_nsIEditingSession_h__


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
class nsIEditor; /* forward declaration */


/* starting interface:    nsIEditingSession */
#define NS_IEDITINGSESSION_IID_STR "274cd32e-3675-47e1-9d8a-fc6504ded9ce"

#define NS_IEDITINGSESSION_IID \
  {0x274cd32e, 0x3675, 0x47e1, \
    { 0x9d, 0x8a, 0xfc, 0x65, 0x04, 0xde, 0xd9, 0xce }}

class NS_NO_VTABLE NS_SCRIPTABLE nsIEditingSession : public nsISupports {
 public: 

  NS_DECLARE_STATIC_IID_ACCESSOR(NS_IEDITINGSESSION_IID)

  /**
   *  Error codes when we fail to create an editor
   *  is placed in attribute editorStatus
   */
  enum { eEditorOK = 0 };

  enum { eEditorCreationInProgress = 1 };

  enum { eEditorErrorCantEditMimeType = 2 };

  enum { eEditorErrorFileNotFound = 3 };

  enum { eEditorErrorCantEditFramesets = 8 };

  enum { eEditorErrorUnknown = 9 };

  /**
   *  Status after editor creation and document loading
   *  Value is one of the above error codes
   */
  /* readonly attribute unsigned long editorStatus; */
  NS_SCRIPTABLE NS_IMETHOD GetEditorStatus(PRUint32 *aEditorStatus) = 0;

  /**
   *  Make this window editable
   *  @param aWindow nsIDOMWindow, the window the embedder needs to make editable
   *  @param aEditorType string, "html" "htmlsimple" "text" "textsimple"
   *  @param aMakeWholeDocumentEditable if PR_TRUE make the whole document in
   *                                    aWindow editable, otherwise it's the
   *                                    embedder who should make the document
   *                                    (or part of it) editable.
   *  @param aInteractive if PR_FALSE turn off scripting and plugins
   */
  /* void makeWindowEditable (in nsIDOMWindow window, in string aEditorType, in boolean doAfterUriLoad, in boolean aMakeWholeDocumentEditable, in boolean aInteractive); */
  NS_SCRIPTABLE NS_IMETHOD MakeWindowEditable(nsIDOMWindow *window, const char *aEditorType, PRBool doAfterUriLoad, PRBool aMakeWholeDocumentEditable, PRBool aInteractive) = 0;

  /**
   *  Test whether a specific window has had its editable flag set; it may have an editor
   *  now, or will get one after the uri load.
   *  
   *  Use this, passing the content root window, to test if we've set up editing
   *  for this content.
   */
  /* boolean windowIsEditable (in nsIDOMWindow window); */
  NS_SCRIPTABLE NS_IMETHOD WindowIsEditable(nsIDOMWindow *window, PRBool *_retval NS_OUTPARAM) = 0;

  /**
   *  Get the editor for this window. May return null
   */
  /* nsIEditor getEditorForWindow (in nsIDOMWindow window); */
  NS_SCRIPTABLE NS_IMETHOD GetEditorForWindow(nsIDOMWindow *window, nsIEditor **_retval NS_OUTPARAM) = 0;

  /** 
   *  Setup editor and related support objects
   */
  /* void setupEditorOnWindow (in nsIDOMWindow window); */
  NS_SCRIPTABLE NS_IMETHOD SetupEditorOnWindow(nsIDOMWindow *window) = 0;

  /** 
   *   Destroy editor and related support objects
   */
  /* void tearDownEditorOnWindow (in nsIDOMWindow window); */
  NS_SCRIPTABLE NS_IMETHOD TearDownEditorOnWindow(nsIDOMWindow *window) = 0;

  /* void setEditorOnControllers (in nsIDOMWindow aWindow, in nsIEditor aEditor); */
  NS_SCRIPTABLE NS_IMETHOD SetEditorOnControllers(nsIDOMWindow *aWindow, nsIEditor *aEditor) = 0;

  /**
   * Disable scripts and plugins in aWindow.
   */
  /* void disableJSAndPlugins (in nsIDOMWindow aWindow); */
  NS_SCRIPTABLE NS_IMETHOD DisableJSAndPlugins(nsIDOMWindow *aWindow) = 0;

  /**
   * Restore JS and plugins (enable/disable them) according to the state they
   * were before the last call to disableJSAndPlugins.
   */
  /* void restoreJSAndPlugins (in nsIDOMWindow aWindow); */
  NS_SCRIPTABLE NS_IMETHOD RestoreJSAndPlugins(nsIDOMWindow *aWindow) = 0;

  /**
   * Removes all the editor's controllers/listeners etc and makes the window
   * uneditable.
   */
  /* void detachFromWindow (in nsIDOMWindow aWindow); */
  NS_SCRIPTABLE NS_IMETHOD DetachFromWindow(nsIDOMWindow *aWindow) = 0;

  /**
   * Undos detachFromWindow(), reattaches this editing session/editor
   * to the window.
   */
  /* void reattachToWindow (in nsIDOMWindow aWindow); */
  NS_SCRIPTABLE NS_IMETHOD ReattachToWindow(nsIDOMWindow *aWindow) = 0;

};

  NS_DEFINE_STATIC_IID_ACCESSOR(nsIEditingSession, NS_IEDITINGSESSION_IID)

/* Use this macro when declaring classes that implement this interface. */
#define NS_DECL_NSIEDITINGSESSION \
  NS_SCRIPTABLE NS_IMETHOD GetEditorStatus(PRUint32 *aEditorStatus); \
  NS_SCRIPTABLE NS_IMETHOD MakeWindowEditable(nsIDOMWindow *window, const char *aEditorType, PRBool doAfterUriLoad, PRBool aMakeWholeDocumentEditable, PRBool aInteractive); \
  NS_SCRIPTABLE NS_IMETHOD WindowIsEditable(nsIDOMWindow *window, PRBool *_retval NS_OUTPARAM); \
  NS_SCRIPTABLE NS_IMETHOD GetEditorForWindow(nsIDOMWindow *window, nsIEditor **_retval NS_OUTPARAM); \
  NS_SCRIPTABLE NS_IMETHOD SetupEditorOnWindow(nsIDOMWindow *window); \
  NS_SCRIPTABLE NS_IMETHOD TearDownEditorOnWindow(nsIDOMWindow *window); \
  NS_SCRIPTABLE NS_IMETHOD SetEditorOnControllers(nsIDOMWindow *aWindow, nsIEditor *aEditor); \
  NS_SCRIPTABLE NS_IMETHOD DisableJSAndPlugins(nsIDOMWindow *aWindow); \
  NS_SCRIPTABLE NS_IMETHOD RestoreJSAndPlugins(nsIDOMWindow *aWindow); \
  NS_SCRIPTABLE NS_IMETHOD DetachFromWindow(nsIDOMWindow *aWindow); \
  NS_SCRIPTABLE NS_IMETHOD ReattachToWindow(nsIDOMWindow *aWindow); 

/* Use this macro to declare functions that forward the behavior of this interface to another object. */
#define NS_FORWARD_NSIEDITINGSESSION(_to) \
  NS_SCRIPTABLE NS_IMETHOD GetEditorStatus(PRUint32 *aEditorStatus) { return _to GetEditorStatus(aEditorStatus); } \
  NS_SCRIPTABLE NS_IMETHOD MakeWindowEditable(nsIDOMWindow *window, const char *aEditorType, PRBool doAfterUriLoad, PRBool aMakeWholeDocumentEditable, PRBool aInteractive) { return _to MakeWindowEditable(window, aEditorType, doAfterUriLoad, aMakeWholeDocumentEditable, aInteractive); } \
  NS_SCRIPTABLE NS_IMETHOD WindowIsEditable(nsIDOMWindow *window, PRBool *_retval NS_OUTPARAM) { return _to WindowIsEditable(window, _retval); } \
  NS_SCRIPTABLE NS_IMETHOD GetEditorForWindow(nsIDOMWindow *window, nsIEditor **_retval NS_OUTPARAM) { return _to GetEditorForWindow(window, _retval); } \
  NS_SCRIPTABLE NS_IMETHOD SetupEditorOnWindow(nsIDOMWindow *window) { return _to SetupEditorOnWindow(window); } \
  NS_SCRIPTABLE NS_IMETHOD TearDownEditorOnWindow(nsIDOMWindow *window) { return _to TearDownEditorOnWindow(window); } \
  NS_SCRIPTABLE NS_IMETHOD SetEditorOnControllers(nsIDOMWindow *aWindow, nsIEditor *aEditor) { return _to SetEditorOnControllers(aWindow, aEditor); } \
  NS_SCRIPTABLE NS_IMETHOD DisableJSAndPlugins(nsIDOMWindow *aWindow) { return _to DisableJSAndPlugins(aWindow); } \
  NS_SCRIPTABLE NS_IMETHOD RestoreJSAndPlugins(nsIDOMWindow *aWindow) { return _to RestoreJSAndPlugins(aWindow); } \
  NS_SCRIPTABLE NS_IMETHOD DetachFromWindow(nsIDOMWindow *aWindow) { return _to DetachFromWindow(aWindow); } \
  NS_SCRIPTABLE NS_IMETHOD ReattachToWindow(nsIDOMWindow *aWindow) { return _to ReattachToWindow(aWindow); } 

/* Use this macro to declare functions that forward the behavior of this interface to another object in a safe way. */
#define NS_FORWARD_SAFE_NSIEDITINGSESSION(_to) \
  NS_SCRIPTABLE NS_IMETHOD GetEditorStatus(PRUint32 *aEditorStatus) { return !_to ? NS_ERROR_NULL_POINTER : _to->GetEditorStatus(aEditorStatus); } \
  NS_SCRIPTABLE NS_IMETHOD MakeWindowEditable(nsIDOMWindow *window, const char *aEditorType, PRBool doAfterUriLoad, PRBool aMakeWholeDocumentEditable, PRBool aInteractive) { return !_to ? NS_ERROR_NULL_POINTER : _to->MakeWindowEditable(window, aEditorType, doAfterUriLoad, aMakeWholeDocumentEditable, aInteractive); } \
  NS_SCRIPTABLE NS_IMETHOD WindowIsEditable(nsIDOMWindow *window, PRBool *_retval NS_OUTPARAM) { return !_to ? NS_ERROR_NULL_POINTER : _to->WindowIsEditable(window, _retval); } \
  NS_SCRIPTABLE NS_IMETHOD GetEditorForWindow(nsIDOMWindow *window, nsIEditor **_retval NS_OUTPARAM) { return !_to ? NS_ERROR_NULL_POINTER : _to->GetEditorForWindow(window, _retval); } \
  NS_SCRIPTABLE NS_IMETHOD SetupEditorOnWindow(nsIDOMWindow *window) { return !_to ? NS_ERROR_NULL_POINTER : _to->SetupEditorOnWindow(window); } \
  NS_SCRIPTABLE NS_IMETHOD TearDownEditorOnWindow(nsIDOMWindow *window) { return !_to ? NS_ERROR_NULL_POINTER : _to->TearDownEditorOnWindow(window); } \
  NS_SCRIPTABLE NS_IMETHOD SetEditorOnControllers(nsIDOMWindow *aWindow, nsIEditor *aEditor) { return !_to ? NS_ERROR_NULL_POINTER : _to->SetEditorOnControllers(aWindow, aEditor); } \
  NS_SCRIPTABLE NS_IMETHOD DisableJSAndPlugins(nsIDOMWindow *aWindow) { return !_to ? NS_ERROR_NULL_POINTER : _to->DisableJSAndPlugins(aWindow); } \
  NS_SCRIPTABLE NS_IMETHOD RestoreJSAndPlugins(nsIDOMWindow *aWindow) { return !_to ? NS_ERROR_NULL_POINTER : _to->RestoreJSAndPlugins(aWindow); } \
  NS_SCRIPTABLE NS_IMETHOD DetachFromWindow(nsIDOMWindow *aWindow) { return !_to ? NS_ERROR_NULL_POINTER : _to->DetachFromWindow(aWindow); } \
  NS_SCRIPTABLE NS_IMETHOD ReattachToWindow(nsIDOMWindow *aWindow) { return !_to ? NS_ERROR_NULL_POINTER : _to->ReattachToWindow(aWindow); } 

#if 0
/* Use the code below as a template for the implementation class for this interface. */

/* Header file */
class nsEditingSession : public nsIEditingSession
{
public:
  NS_DECL_ISUPPORTS
  NS_DECL_NSIEDITINGSESSION

  nsEditingSession();

private:
  ~nsEditingSession();

protected:
  /* additional members */
};

/* Implementation file */
NS_IMPL_ISUPPORTS1(nsEditingSession, nsIEditingSession)

nsEditingSession::nsEditingSession()
{
  /* member initializers and constructor code */
}

nsEditingSession::~nsEditingSession()
{
  /* destructor code */
}

/* readonly attribute unsigned long editorStatus; */
NS_IMETHODIMP nsEditingSession::GetEditorStatus(PRUint32 *aEditorStatus)
{
    return NS_ERROR_NOT_IMPLEMENTED;
}

/* void makeWindowEditable (in nsIDOMWindow window, in string aEditorType, in boolean doAfterUriLoad, in boolean aMakeWholeDocumentEditable, in boolean aInteractive); */
NS_IMETHODIMP nsEditingSession::MakeWindowEditable(nsIDOMWindow *window, const char *aEditorType, PRBool doAfterUriLoad, PRBool aMakeWholeDocumentEditable, PRBool aInteractive)
{
    return NS_ERROR_NOT_IMPLEMENTED;
}

/* boolean windowIsEditable (in nsIDOMWindow window); */
NS_IMETHODIMP nsEditingSession::WindowIsEditable(nsIDOMWindow *window, PRBool *_retval NS_OUTPARAM)
{
    return NS_ERROR_NOT_IMPLEMENTED;
}

/* nsIEditor getEditorForWindow (in nsIDOMWindow window); */
NS_IMETHODIMP nsEditingSession::GetEditorForWindow(nsIDOMWindow *window, nsIEditor **_retval NS_OUTPARAM)
{
    return NS_ERROR_NOT_IMPLEMENTED;
}

/* void setupEditorOnWindow (in nsIDOMWindow window); */
NS_IMETHODIMP nsEditingSession::SetupEditorOnWindow(nsIDOMWindow *window)
{
    return NS_ERROR_NOT_IMPLEMENTED;
}

/* void tearDownEditorOnWindow (in nsIDOMWindow window); */
NS_IMETHODIMP nsEditingSession::TearDownEditorOnWindow(nsIDOMWindow *window)
{
    return NS_ERROR_NOT_IMPLEMENTED;
}

/* void setEditorOnControllers (in nsIDOMWindow aWindow, in nsIEditor aEditor); */
NS_IMETHODIMP nsEditingSession::SetEditorOnControllers(nsIDOMWindow *aWindow, nsIEditor *aEditor)
{
    return NS_ERROR_NOT_IMPLEMENTED;
}

/* void disableJSAndPlugins (in nsIDOMWindow aWindow); */
NS_IMETHODIMP nsEditingSession::DisableJSAndPlugins(nsIDOMWindow *aWindow)
{
    return NS_ERROR_NOT_IMPLEMENTED;
}

/* void restoreJSAndPlugins (in nsIDOMWindow aWindow); */
NS_IMETHODIMP nsEditingSession::RestoreJSAndPlugins(nsIDOMWindow *aWindow)
{
    return NS_ERROR_NOT_IMPLEMENTED;
}

/* void detachFromWindow (in nsIDOMWindow aWindow); */
NS_IMETHODIMP nsEditingSession::DetachFromWindow(nsIDOMWindow *aWindow)
{
    return NS_ERROR_NOT_IMPLEMENTED;
}

/* void reattachToWindow (in nsIDOMWindow aWindow); */
NS_IMETHODIMP nsEditingSession::ReattachToWindow(nsIDOMWindow *aWindow)
{
    return NS_ERROR_NOT_IMPLEMENTED;
}

/* End of implementation class template. */
#endif


#endif /* __gen_nsIEditingSession_h__ */
