/*
 * DO NOT EDIT.  THIS FILE IS GENERATED FROM e:/builds/moz2_slave/mozilla-1.9.1-win32-xulrunner/build/docshell/base/nsIContentViewerEdit.idl
 */

#ifndef __gen_nsIContentViewerEdit_h__
#define __gen_nsIContentViewerEdit_h__


#ifndef __gen_nsISupports_h__
#include "nsISupports.h"
#endif

/* For IDL files that don't want to include root IDL files. */
#ifndef NS_NO_VTABLE
#define NS_NO_VTABLE
#endif

/* starting interface:    nsIContentViewerEdit */
#define NS_ICONTENTVIEWEREDIT_IID_STR "1691a02f-53b2-4cb8-8769-48e7efc908b8"

#define NS_ICONTENTVIEWEREDIT_IID \
  {0x1691a02f, 0x53b2, 0x4cb8, \
    { 0x87, 0x69, 0x48, 0xe7, 0xef, 0xc9, 0x08, 0xb8 }}

class NS_NO_VTABLE NS_SCRIPTABLE nsIContentViewerEdit : public nsISupports {
 public: 

  NS_DECLARE_STATIC_IID_ACCESSOR(NS_ICONTENTVIEWEREDIT_IID)

  /* void search (); */
  NS_SCRIPTABLE NS_IMETHOD Search(void) = 0;

  /* readonly attribute boolean searchable; */
  NS_SCRIPTABLE NS_IMETHOD GetSearchable(PRBool *aSearchable) = 0;

  /* void clearSelection (); */
  NS_SCRIPTABLE NS_IMETHOD ClearSelection(void) = 0;

  /* void selectAll (); */
  NS_SCRIPTABLE NS_IMETHOD SelectAll(void) = 0;

  /* void copySelection (); */
  NS_SCRIPTABLE NS_IMETHOD CopySelection(void) = 0;

  /* readonly attribute boolean copyable; */
  NS_SCRIPTABLE NS_IMETHOD GetCopyable(PRBool *aCopyable) = 0;

  /* void copyLinkLocation (); */
  NS_SCRIPTABLE NS_IMETHOD CopyLinkLocation(void) = 0;

  /* readonly attribute boolean inLink; */
  NS_SCRIPTABLE NS_IMETHOD GetInLink(PRBool *aInLink) = 0;

  enum { COPY_IMAGE_TEXT = 1 };

  enum { COPY_IMAGE_HTML = 2 };

  enum { COPY_IMAGE_DATA = 4 };

  enum { COPY_IMAGE_ALL = -1 };

  /* void copyImage (in long aCopyFlags); */
  NS_SCRIPTABLE NS_IMETHOD CopyImage(PRInt32 aCopyFlags) = 0;

  /* readonly attribute boolean inImage; */
  NS_SCRIPTABLE NS_IMETHOD GetInImage(PRBool *aInImage) = 0;

  /* void cutSelection (); */
  NS_SCRIPTABLE NS_IMETHOD CutSelection(void) = 0;

  /* readonly attribute boolean cutable; */
  NS_SCRIPTABLE NS_IMETHOD GetCutable(PRBool *aCutable) = 0;

  /* void paste (); */
  NS_SCRIPTABLE NS_IMETHOD Paste(void) = 0;

  /* readonly attribute boolean pasteable; */
  NS_SCRIPTABLE NS_IMETHOD GetPasteable(PRBool *aPasteable) = 0;

  /* AString getContents (in string aMimeType, in boolean aSelectionOnly); */
  NS_SCRIPTABLE NS_IMETHOD GetContents(const char *aMimeType, PRBool aSelectionOnly, nsAString & _retval NS_OUTPARAM) = 0;

  /* readonly attribute boolean canGetContents; */
  NS_SCRIPTABLE NS_IMETHOD GetCanGetContents(PRBool *aCanGetContents) = 0;

};

  NS_DEFINE_STATIC_IID_ACCESSOR(nsIContentViewerEdit, NS_ICONTENTVIEWEREDIT_IID)

/* Use this macro when declaring classes that implement this interface. */
#define NS_DECL_NSICONTENTVIEWEREDIT \
  NS_SCRIPTABLE NS_IMETHOD Search(void); \
  NS_SCRIPTABLE NS_IMETHOD GetSearchable(PRBool *aSearchable); \
  NS_SCRIPTABLE NS_IMETHOD ClearSelection(void); \
  NS_SCRIPTABLE NS_IMETHOD SelectAll(void); \
  NS_SCRIPTABLE NS_IMETHOD CopySelection(void); \
  NS_SCRIPTABLE NS_IMETHOD GetCopyable(PRBool *aCopyable); \
  NS_SCRIPTABLE NS_IMETHOD CopyLinkLocation(void); \
  NS_SCRIPTABLE NS_IMETHOD GetInLink(PRBool *aInLink); \
  NS_SCRIPTABLE NS_IMETHOD CopyImage(PRInt32 aCopyFlags); \
  NS_SCRIPTABLE NS_IMETHOD GetInImage(PRBool *aInImage); \
  NS_SCRIPTABLE NS_IMETHOD CutSelection(void); \
  NS_SCRIPTABLE NS_IMETHOD GetCutable(PRBool *aCutable); \
  NS_SCRIPTABLE NS_IMETHOD Paste(void); \
  NS_SCRIPTABLE NS_IMETHOD GetPasteable(PRBool *aPasteable); \
  NS_SCRIPTABLE NS_IMETHOD GetContents(const char *aMimeType, PRBool aSelectionOnly, nsAString & _retval NS_OUTPARAM); \
  NS_SCRIPTABLE NS_IMETHOD GetCanGetContents(PRBool *aCanGetContents); 

/* Use this macro to declare functions that forward the behavior of this interface to another object. */
#define NS_FORWARD_NSICONTENTVIEWEREDIT(_to) \
  NS_SCRIPTABLE NS_IMETHOD Search(void) { return _to Search(); } \
  NS_SCRIPTABLE NS_IMETHOD GetSearchable(PRBool *aSearchable) { return _to GetSearchable(aSearchable); } \
  NS_SCRIPTABLE NS_IMETHOD ClearSelection(void) { return _to ClearSelection(); } \
  NS_SCRIPTABLE NS_IMETHOD SelectAll(void) { return _to SelectAll(); } \
  NS_SCRIPTABLE NS_IMETHOD CopySelection(void) { return _to CopySelection(); } \
  NS_SCRIPTABLE NS_IMETHOD GetCopyable(PRBool *aCopyable) { return _to GetCopyable(aCopyable); } \
  NS_SCRIPTABLE NS_IMETHOD CopyLinkLocation(void) { return _to CopyLinkLocation(); } \
  NS_SCRIPTABLE NS_IMETHOD GetInLink(PRBool *aInLink) { return _to GetInLink(aInLink); } \
  NS_SCRIPTABLE NS_IMETHOD CopyImage(PRInt32 aCopyFlags) { return _to CopyImage(aCopyFlags); } \
  NS_SCRIPTABLE NS_IMETHOD GetInImage(PRBool *aInImage) { return _to GetInImage(aInImage); } \
  NS_SCRIPTABLE NS_IMETHOD CutSelection(void) { return _to CutSelection(); } \
  NS_SCRIPTABLE NS_IMETHOD GetCutable(PRBool *aCutable) { return _to GetCutable(aCutable); } \
  NS_SCRIPTABLE NS_IMETHOD Paste(void) { return _to Paste(); } \
  NS_SCRIPTABLE NS_IMETHOD GetPasteable(PRBool *aPasteable) { return _to GetPasteable(aPasteable); } \
  NS_SCRIPTABLE NS_IMETHOD GetContents(const char *aMimeType, PRBool aSelectionOnly, nsAString & _retval NS_OUTPARAM) { return _to GetContents(aMimeType, aSelectionOnly, _retval); } \
  NS_SCRIPTABLE NS_IMETHOD GetCanGetContents(PRBool *aCanGetContents) { return _to GetCanGetContents(aCanGetContents); } 

/* Use this macro to declare functions that forward the behavior of this interface to another object in a safe way. */
#define NS_FORWARD_SAFE_NSICONTENTVIEWEREDIT(_to) \
  NS_SCRIPTABLE NS_IMETHOD Search(void) { return !_to ? NS_ERROR_NULL_POINTER : _to->Search(); } \
  NS_SCRIPTABLE NS_IMETHOD GetSearchable(PRBool *aSearchable) { return !_to ? NS_ERROR_NULL_POINTER : _to->GetSearchable(aSearchable); } \
  NS_SCRIPTABLE NS_IMETHOD ClearSelection(void) { return !_to ? NS_ERROR_NULL_POINTER : _to->ClearSelection(); } \
  NS_SCRIPTABLE NS_IMETHOD SelectAll(void) { return !_to ? NS_ERROR_NULL_POINTER : _to->SelectAll(); } \
  NS_SCRIPTABLE NS_IMETHOD CopySelection(void) { return !_to ? NS_ERROR_NULL_POINTER : _to->CopySelection(); } \
  NS_SCRIPTABLE NS_IMETHOD GetCopyable(PRBool *aCopyable) { return !_to ? NS_ERROR_NULL_POINTER : _to->GetCopyable(aCopyable); } \
  NS_SCRIPTABLE NS_IMETHOD CopyLinkLocation(void) { return !_to ? NS_ERROR_NULL_POINTER : _to->CopyLinkLocation(); } \
  NS_SCRIPTABLE NS_IMETHOD GetInLink(PRBool *aInLink) { return !_to ? NS_ERROR_NULL_POINTER : _to->GetInLink(aInLink); } \
  NS_SCRIPTABLE NS_IMETHOD CopyImage(PRInt32 aCopyFlags) { return !_to ? NS_ERROR_NULL_POINTER : _to->CopyImage(aCopyFlags); } \
  NS_SCRIPTABLE NS_IMETHOD GetInImage(PRBool *aInImage) { return !_to ? NS_ERROR_NULL_POINTER : _to->GetInImage(aInImage); } \
  NS_SCRIPTABLE NS_IMETHOD CutSelection(void) { return !_to ? NS_ERROR_NULL_POINTER : _to->CutSelection(); } \
  NS_SCRIPTABLE NS_IMETHOD GetCutable(PRBool *aCutable) { return !_to ? NS_ERROR_NULL_POINTER : _to->GetCutable(aCutable); } \
  NS_SCRIPTABLE NS_IMETHOD Paste(void) { return !_to ? NS_ERROR_NULL_POINTER : _to->Paste(); } \
  NS_SCRIPTABLE NS_IMETHOD GetPasteable(PRBool *aPasteable) { return !_to ? NS_ERROR_NULL_POINTER : _to->GetPasteable(aPasteable); } \
  NS_SCRIPTABLE NS_IMETHOD GetContents(const char *aMimeType, PRBool aSelectionOnly, nsAString & _retval NS_OUTPARAM) { return !_to ? NS_ERROR_NULL_POINTER : _to->GetContents(aMimeType, aSelectionOnly, _retval); } \
  NS_SCRIPTABLE NS_IMETHOD GetCanGetContents(PRBool *aCanGetContents) { return !_to ? NS_ERROR_NULL_POINTER : _to->GetCanGetContents(aCanGetContents); } 

#if 0
/* Use the code below as a template for the implementation class for this interface. */

/* Header file */
class nsContentViewerEdit : public nsIContentViewerEdit
{
public:
  NS_DECL_ISUPPORTS
  NS_DECL_NSICONTENTVIEWEREDIT

  nsContentViewerEdit();

private:
  ~nsContentViewerEdit();

protected:
  /* additional members */
};

/* Implementation file */
NS_IMPL_ISUPPORTS1(nsContentViewerEdit, nsIContentViewerEdit)

nsContentViewerEdit::nsContentViewerEdit()
{
  /* member initializers and constructor code */
}

nsContentViewerEdit::~nsContentViewerEdit()
{
  /* destructor code */
}

/* void search (); */
NS_IMETHODIMP nsContentViewerEdit::Search()
{
    return NS_ERROR_NOT_IMPLEMENTED;
}

/* readonly attribute boolean searchable; */
NS_IMETHODIMP nsContentViewerEdit::GetSearchable(PRBool *aSearchable)
{
    return NS_ERROR_NOT_IMPLEMENTED;
}

/* void clearSelection (); */
NS_IMETHODIMP nsContentViewerEdit::ClearSelection()
{
    return NS_ERROR_NOT_IMPLEMENTED;
}

/* void selectAll (); */
NS_IMETHODIMP nsContentViewerEdit::SelectAll()
{
    return NS_ERROR_NOT_IMPLEMENTED;
}

/* void copySelection (); */
NS_IMETHODIMP nsContentViewerEdit::CopySelection()
{
    return NS_ERROR_NOT_IMPLEMENTED;
}

/* readonly attribute boolean copyable; */
NS_IMETHODIMP nsContentViewerEdit::GetCopyable(PRBool *aCopyable)
{
    return NS_ERROR_NOT_IMPLEMENTED;
}

/* void copyLinkLocation (); */
NS_IMETHODIMP nsContentViewerEdit::CopyLinkLocation()
{
    return NS_ERROR_NOT_IMPLEMENTED;
}

/* readonly attribute boolean inLink; */
NS_IMETHODIMP nsContentViewerEdit::GetInLink(PRBool *aInLink)
{
    return NS_ERROR_NOT_IMPLEMENTED;
}

/* void copyImage (in long aCopyFlags); */
NS_IMETHODIMP nsContentViewerEdit::CopyImage(PRInt32 aCopyFlags)
{
    return NS_ERROR_NOT_IMPLEMENTED;
}

/* readonly attribute boolean inImage; */
NS_IMETHODIMP nsContentViewerEdit::GetInImage(PRBool *aInImage)
{
    return NS_ERROR_NOT_IMPLEMENTED;
}

/* void cutSelection (); */
NS_IMETHODIMP nsContentViewerEdit::CutSelection()
{
    return NS_ERROR_NOT_IMPLEMENTED;
}

/* readonly attribute boolean cutable; */
NS_IMETHODIMP nsContentViewerEdit::GetCutable(PRBool *aCutable)
{
    return NS_ERROR_NOT_IMPLEMENTED;
}

/* void paste (); */
NS_IMETHODIMP nsContentViewerEdit::Paste()
{
    return NS_ERROR_NOT_IMPLEMENTED;
}

/* readonly attribute boolean pasteable; */
NS_IMETHODIMP nsContentViewerEdit::GetPasteable(PRBool *aPasteable)
{
    return NS_ERROR_NOT_IMPLEMENTED;
}

/* AString getContents (in string aMimeType, in boolean aSelectionOnly); */
NS_IMETHODIMP nsContentViewerEdit::GetContents(const char *aMimeType, PRBool aSelectionOnly, nsAString & _retval NS_OUTPARAM)
{
    return NS_ERROR_NOT_IMPLEMENTED;
}

/* readonly attribute boolean canGetContents; */
NS_IMETHODIMP nsContentViewerEdit::GetCanGetContents(PRBool *aCanGetContents)
{
    return NS_ERROR_NOT_IMPLEMENTED;
}

/* End of implementation class template. */
#endif


#endif /* __gen_nsIContentViewerEdit_h__ */
