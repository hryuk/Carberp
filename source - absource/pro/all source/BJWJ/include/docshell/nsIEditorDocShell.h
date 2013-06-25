/*
 * DO NOT EDIT.  THIS FILE IS GENERATED FROM e:/builds/moz2_slave/mozilla-1.9.1-win32-xulrunner/build/docshell/base/nsIEditorDocShell.idl
 */

#ifndef __gen_nsIEditorDocShell_h__
#define __gen_nsIEditorDocShell_h__


#ifndef __gen_nsISupports_h__
#include "nsISupports.h"
#endif

/* For IDL files that don't want to include root IDL files. */
#ifndef NS_NO_VTABLE
#define NS_NO_VTABLE
#endif
class nsIEditor; /* forward declaration */


/* starting interface:    nsIEditorDocShell */
#define NS_IEDITORDOCSHELL_IID_STR "3bdb8f01-f141-11d4-a73c-fba4aba8a3fc"

#define NS_IEDITORDOCSHELL_IID \
  {0x3bdb8f01, 0xf141, 0x11d4, \
    { 0xa7, 0x3c, 0xfb, 0xa4, 0xab, 0xa8, 0xa3, 0xfc }}

/**
 * nsIEditorDocShell provides a way to get an editor from
 * a specific frame in a docShell hierarchy. It is intended
 * to be only used internally. Use nsIEditingShell.getEditorForFrame
 * from out side.
 */
class NS_NO_VTABLE NS_SCRIPTABLE nsIEditorDocShell : public nsISupports {
 public: 

  NS_DECLARE_STATIC_IID_ACCESSOR(NS_IEDITORDOCSHELL_IID)

  /* attribute nsIEditor editor; */
  NS_SCRIPTABLE NS_IMETHOD GetEditor(nsIEditor * *aEditor) = 0;
  NS_SCRIPTABLE NS_IMETHOD SetEditor(nsIEditor * aEditor) = 0;

  /* readonly attribute boolean editable; */
  NS_SCRIPTABLE NS_IMETHOD GetEditable(PRBool *aEditable) = 0;

  /* readonly attribute boolean hasEditingSession; */
  NS_SCRIPTABLE NS_IMETHOD GetHasEditingSession(PRBool *aHasEditingSession) = 0;

  /**
     * Make this docShell editable, setting a flag that causes
     * an editor to get created, either immediately, or after
     * a url has been loaded.
     *      @param  inWaitForUriLoad    true to wait for a URI before
     *                                  creating the editor.
     */
  /* void makeEditable (in boolean inWaitForUriLoad); */
  NS_SCRIPTABLE NS_IMETHOD MakeEditable(PRBool inWaitForUriLoad) = 0;

};

  NS_DEFINE_STATIC_IID_ACCESSOR(nsIEditorDocShell, NS_IEDITORDOCSHELL_IID)

/* Use this macro when declaring classes that implement this interface. */
#define NS_DECL_NSIEDITORDOCSHELL \
  NS_SCRIPTABLE NS_IMETHOD GetEditor(nsIEditor * *aEditor); \
  NS_SCRIPTABLE NS_IMETHOD SetEditor(nsIEditor * aEditor); \
  NS_SCRIPTABLE NS_IMETHOD GetEditable(PRBool *aEditable); \
  NS_SCRIPTABLE NS_IMETHOD GetHasEditingSession(PRBool *aHasEditingSession); \
  NS_SCRIPTABLE NS_IMETHOD MakeEditable(PRBool inWaitForUriLoad); 

/* Use this macro to declare functions that forward the behavior of this interface to another object. */
#define NS_FORWARD_NSIEDITORDOCSHELL(_to) \
  NS_SCRIPTABLE NS_IMETHOD GetEditor(nsIEditor * *aEditor) { return _to GetEditor(aEditor); } \
  NS_SCRIPTABLE NS_IMETHOD SetEditor(nsIEditor * aEditor) { return _to SetEditor(aEditor); } \
  NS_SCRIPTABLE NS_IMETHOD GetEditable(PRBool *aEditable) { return _to GetEditable(aEditable); } \
  NS_SCRIPTABLE NS_IMETHOD GetHasEditingSession(PRBool *aHasEditingSession) { return _to GetHasEditingSession(aHasEditingSession); } \
  NS_SCRIPTABLE NS_IMETHOD MakeEditable(PRBool inWaitForUriLoad) { return _to MakeEditable(inWaitForUriLoad); } 

/* Use this macro to declare functions that forward the behavior of this interface to another object in a safe way. */
#define NS_FORWARD_SAFE_NSIEDITORDOCSHELL(_to) \
  NS_SCRIPTABLE NS_IMETHOD GetEditor(nsIEditor * *aEditor) { return !_to ? NS_ERROR_NULL_POINTER : _to->GetEditor(aEditor); } \
  NS_SCRIPTABLE NS_IMETHOD SetEditor(nsIEditor * aEditor) { return !_to ? NS_ERROR_NULL_POINTER : _to->SetEditor(aEditor); } \
  NS_SCRIPTABLE NS_IMETHOD GetEditable(PRBool *aEditable) { return !_to ? NS_ERROR_NULL_POINTER : _to->GetEditable(aEditable); } \
  NS_SCRIPTABLE NS_IMETHOD GetHasEditingSession(PRBool *aHasEditingSession) { return !_to ? NS_ERROR_NULL_POINTER : _to->GetHasEditingSession(aHasEditingSession); } \
  NS_SCRIPTABLE NS_IMETHOD MakeEditable(PRBool inWaitForUriLoad) { return !_to ? NS_ERROR_NULL_POINTER : _to->MakeEditable(inWaitForUriLoad); } 

#if 0
/* Use the code below as a template for the implementation class for this interface. */

/* Header file */
class nsEditorDocShell : public nsIEditorDocShell
{
public:
  NS_DECL_ISUPPORTS
  NS_DECL_NSIEDITORDOCSHELL

  nsEditorDocShell();

private:
  ~nsEditorDocShell();

protected:
  /* additional members */
};

/* Implementation file */
NS_IMPL_ISUPPORTS1(nsEditorDocShell, nsIEditorDocShell)

nsEditorDocShell::nsEditorDocShell()
{
  /* member initializers and constructor code */
}

nsEditorDocShell::~nsEditorDocShell()
{
  /* destructor code */
}

/* attribute nsIEditor editor; */
NS_IMETHODIMP nsEditorDocShell::GetEditor(nsIEditor * *aEditor)
{
    return NS_ERROR_NOT_IMPLEMENTED;
}
NS_IMETHODIMP nsEditorDocShell::SetEditor(nsIEditor * aEditor)
{
    return NS_ERROR_NOT_IMPLEMENTED;
}

/* readonly attribute boolean editable; */
NS_IMETHODIMP nsEditorDocShell::GetEditable(PRBool *aEditable)
{
    return NS_ERROR_NOT_IMPLEMENTED;
}

/* readonly attribute boolean hasEditingSession; */
NS_IMETHODIMP nsEditorDocShell::GetHasEditingSession(PRBool *aHasEditingSession)
{
    return NS_ERROR_NOT_IMPLEMENTED;
}

/* void makeEditable (in boolean inWaitForUriLoad); */
NS_IMETHODIMP nsEditorDocShell::MakeEditable(PRBool inWaitForUriLoad)
{
    return NS_ERROR_NOT_IMPLEMENTED;
}

/* End of implementation class template. */
#endif


#endif /* __gen_nsIEditorDocShell_h__ */
