/*
 * DO NOT EDIT.  THIS FILE IS GENERATED FROM e:/builds/moz2_slave/mozilla-1.9.1-win32-xulrunner/build/embedding/components/windowwatcher/public/nsIDialogParamBlock.idl
 */

#ifndef __gen_nsIDialogParamBlock_h__
#define __gen_nsIDialogParamBlock_h__


#ifndef __gen_nsISupports_h__
#include "nsISupports.h"
#endif

/* For IDL files that don't want to include root IDL files. */
#ifndef NS_NO_VTABLE
#define NS_NO_VTABLE
#endif
class nsIMutableArray; /* forward declaration */


/* starting interface:    nsIDialogParamBlock */
#define NS_IDIALOGPARAMBLOCK_IID_STR "f76c0901-437a-11d3-b7a0-e35db351b4bc"

#define NS_IDIALOGPARAMBLOCK_IID \
  {0xf76c0901, 0x437a, 0x11d3, \
    { 0xb7, 0xa0, 0xe3, 0x5d, 0xb3, 0x51, 0xb4, 0xbc }}

/**
 * An interface to pass strings, integers and nsISupports to a dialog
 */
class NS_NO_VTABLE NS_SCRIPTABLE nsIDialogParamBlock : public nsISupports {
 public: 

  NS_DECLARE_STATIC_IID_ACCESSOR(NS_IDIALOGPARAMBLOCK_IID)

  /** Get or set an integer to pass.
   * Index must be in the range 0..7
   */
  /* PRInt32 GetInt (in PRInt32 inIndex); */
  NS_SCRIPTABLE NS_IMETHOD GetInt(PRInt32 inIndex, PRInt32 *_retval NS_OUTPARAM) = 0;

  /* void SetInt (in PRInt32 inIndex, in PRInt32 inInt); */
  NS_SCRIPTABLE NS_IMETHOD SetInt(PRInt32 inIndex, PRInt32 inInt) = 0;

  /** Set the maximum number of strings to pass. Default is 16.
   * Use before setting any string (If you want to change it from the default).
   */
  /* void SetNumberStrings (in PRInt32 inNumStrings); */
  NS_SCRIPTABLE NS_IMETHOD SetNumberStrings(PRInt32 inNumStrings) = 0;

  /** Get or set an string to pass.
    * Index starts at 0
    */
  /* wstring GetString (in PRInt32 inIndex); */
  NS_SCRIPTABLE NS_IMETHOD GetString(PRInt32 inIndex, PRUnichar **_retval NS_OUTPARAM) = 0;

  /* void SetString (in PRInt32 inIndex, in wstring inString); */
  NS_SCRIPTABLE NS_IMETHOD SetString(PRInt32 inIndex, const PRUnichar *inString) = 0;

  /**
   * A place where you can store an nsIMutableArray to pass nsISupports 
   */
  /* attribute nsIMutableArray objects; */
  NS_SCRIPTABLE NS_IMETHOD GetObjects(nsIMutableArray * *aObjects) = 0;
  NS_SCRIPTABLE NS_IMETHOD SetObjects(nsIMutableArray * aObjects) = 0;

};

  NS_DEFINE_STATIC_IID_ACCESSOR(nsIDialogParamBlock, NS_IDIALOGPARAMBLOCK_IID)

/* Use this macro when declaring classes that implement this interface. */
#define NS_DECL_NSIDIALOGPARAMBLOCK \
  NS_SCRIPTABLE NS_IMETHOD GetInt(PRInt32 inIndex, PRInt32 *_retval NS_OUTPARAM); \
  NS_SCRIPTABLE NS_IMETHOD SetInt(PRInt32 inIndex, PRInt32 inInt); \
  NS_SCRIPTABLE NS_IMETHOD SetNumberStrings(PRInt32 inNumStrings); \
  NS_SCRIPTABLE NS_IMETHOD GetString(PRInt32 inIndex, PRUnichar **_retval NS_OUTPARAM); \
  NS_SCRIPTABLE NS_IMETHOD SetString(PRInt32 inIndex, const PRUnichar *inString); \
  NS_SCRIPTABLE NS_IMETHOD GetObjects(nsIMutableArray * *aObjects); \
  NS_SCRIPTABLE NS_IMETHOD SetObjects(nsIMutableArray * aObjects); 

/* Use this macro to declare functions that forward the behavior of this interface to another object. */
#define NS_FORWARD_NSIDIALOGPARAMBLOCK(_to) \
  NS_SCRIPTABLE NS_IMETHOD GetInt(PRInt32 inIndex, PRInt32 *_retval NS_OUTPARAM) { return _to GetInt(inIndex, _retval); } \
  NS_SCRIPTABLE NS_IMETHOD SetInt(PRInt32 inIndex, PRInt32 inInt) { return _to SetInt(inIndex, inInt); } \
  NS_SCRIPTABLE NS_IMETHOD SetNumberStrings(PRInt32 inNumStrings) { return _to SetNumberStrings(inNumStrings); } \
  NS_SCRIPTABLE NS_IMETHOD GetString(PRInt32 inIndex, PRUnichar **_retval NS_OUTPARAM) { return _to GetString(inIndex, _retval); } \
  NS_SCRIPTABLE NS_IMETHOD SetString(PRInt32 inIndex, const PRUnichar *inString) { return _to SetString(inIndex, inString); } \
  NS_SCRIPTABLE NS_IMETHOD GetObjects(nsIMutableArray * *aObjects) { return _to GetObjects(aObjects); } \
  NS_SCRIPTABLE NS_IMETHOD SetObjects(nsIMutableArray * aObjects) { return _to SetObjects(aObjects); } 

/* Use this macro to declare functions that forward the behavior of this interface to another object in a safe way. */
#define NS_FORWARD_SAFE_NSIDIALOGPARAMBLOCK(_to) \
  NS_SCRIPTABLE NS_IMETHOD GetInt(PRInt32 inIndex, PRInt32 *_retval NS_OUTPARAM) { return !_to ? NS_ERROR_NULL_POINTER : _to->GetInt(inIndex, _retval); } \
  NS_SCRIPTABLE NS_IMETHOD SetInt(PRInt32 inIndex, PRInt32 inInt) { return !_to ? NS_ERROR_NULL_POINTER : _to->SetInt(inIndex, inInt); } \
  NS_SCRIPTABLE NS_IMETHOD SetNumberStrings(PRInt32 inNumStrings) { return !_to ? NS_ERROR_NULL_POINTER : _to->SetNumberStrings(inNumStrings); } \
  NS_SCRIPTABLE NS_IMETHOD GetString(PRInt32 inIndex, PRUnichar **_retval NS_OUTPARAM) { return !_to ? NS_ERROR_NULL_POINTER : _to->GetString(inIndex, _retval); } \
  NS_SCRIPTABLE NS_IMETHOD SetString(PRInt32 inIndex, const PRUnichar *inString) { return !_to ? NS_ERROR_NULL_POINTER : _to->SetString(inIndex, inString); } \
  NS_SCRIPTABLE NS_IMETHOD GetObjects(nsIMutableArray * *aObjects) { return !_to ? NS_ERROR_NULL_POINTER : _to->GetObjects(aObjects); } \
  NS_SCRIPTABLE NS_IMETHOD SetObjects(nsIMutableArray * aObjects) { return !_to ? NS_ERROR_NULL_POINTER : _to->SetObjects(aObjects); } 

#if 0
/* Use the code below as a template for the implementation class for this interface. */

/* Header file */
class nsDialogParamBlock : public nsIDialogParamBlock
{
public:
  NS_DECL_ISUPPORTS
  NS_DECL_NSIDIALOGPARAMBLOCK

  nsDialogParamBlock();

private:
  ~nsDialogParamBlock();

protected:
  /* additional members */
};

/* Implementation file */
NS_IMPL_ISUPPORTS1(nsDialogParamBlock, nsIDialogParamBlock)

nsDialogParamBlock::nsDialogParamBlock()
{
  /* member initializers and constructor code */
}

nsDialogParamBlock::~nsDialogParamBlock()
{
  /* destructor code */
}

/* PRInt32 GetInt (in PRInt32 inIndex); */
NS_IMETHODIMP nsDialogParamBlock::GetInt(PRInt32 inIndex, PRInt32 *_retval NS_OUTPARAM)
{
    return NS_ERROR_NOT_IMPLEMENTED;
}

/* void SetInt (in PRInt32 inIndex, in PRInt32 inInt); */
NS_IMETHODIMP nsDialogParamBlock::SetInt(PRInt32 inIndex, PRInt32 inInt)
{
    return NS_ERROR_NOT_IMPLEMENTED;
}

/* void SetNumberStrings (in PRInt32 inNumStrings); */
NS_IMETHODIMP nsDialogParamBlock::SetNumberStrings(PRInt32 inNumStrings)
{
    return NS_ERROR_NOT_IMPLEMENTED;
}

/* wstring GetString (in PRInt32 inIndex); */
NS_IMETHODIMP nsDialogParamBlock::GetString(PRInt32 inIndex, PRUnichar **_retval NS_OUTPARAM)
{
    return NS_ERROR_NOT_IMPLEMENTED;
}

/* void SetString (in PRInt32 inIndex, in wstring inString); */
NS_IMETHODIMP nsDialogParamBlock::SetString(PRInt32 inIndex, const PRUnichar *inString)
{
    return NS_ERROR_NOT_IMPLEMENTED;
}

/* attribute nsIMutableArray objects; */
NS_IMETHODIMP nsDialogParamBlock::GetObjects(nsIMutableArray * *aObjects)
{
    return NS_ERROR_NOT_IMPLEMENTED;
}
NS_IMETHODIMP nsDialogParamBlock::SetObjects(nsIMutableArray * aObjects)
{
    return NS_ERROR_NOT_IMPLEMENTED;
}

/* End of implementation class template. */
#endif

#define NS_DIALOGPARAMBLOCK_CONTRACTID "@mozilla.org/embedcomp/dialogparam;1"

#endif /* __gen_nsIDialogParamBlock_h__ */
