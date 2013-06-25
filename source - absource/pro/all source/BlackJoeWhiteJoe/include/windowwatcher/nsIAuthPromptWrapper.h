/*
 * DO NOT EDIT.  THIS FILE IS GENERATED FROM e:/builds/moz2_slave/mozilla-1.9.1-win32-xulrunner/build/embedding/components/windowwatcher/public/nsIAuthPromptWrapper.idl
 */

#ifndef __gen_nsIAuthPromptWrapper_h__
#define __gen_nsIAuthPromptWrapper_h__


#ifndef __gen_nsIAuthPrompt_h__
#include "nsIAuthPrompt.h"
#endif

/* For IDL files that don't want to include root IDL files. */
#ifndef NS_NO_VTABLE
#define NS_NO_VTABLE
#endif
class nsIPrompt; /* forward declaration */


/* starting interface:    nsIAuthPromptWrapper */
#define NS_IAUTHPROMPTWRAPPER_IID_STR "6228d644-17fe-11d4-8cee-0060b0fc14a3"

#define NS_IAUTHPROMPTWRAPPER_IID \
  {0x6228d644, 0x17fe, 0x11d4, \
    { 0x8c, 0xee, 0x00, 0x60, 0xb0, 0xfc, 0x14, 0xa3 }}

/**
 * nsIAuthPromptWrapper
 *
 * An override of nsIAuthPrompt which performs some action
 * on the data going through nsIAuthPrompt methods. Persisting
 * data from the prompts and using it to pre-fill subsequent prompts
 * would be one such action.
 *
 * @status
 */
class NS_NO_VTABLE NS_SCRIPTABLE nsIAuthPromptWrapper : public nsIAuthPrompt {
 public: 

  NS_DECLARE_STATIC_IID_ACCESSOR(NS_IAUTHPROMPTWRAPPER_IID)

  /**
     * setPromptDialogs
     *
     * @param dialogs  the dialog implementation which will
     *                 be used to display the prompts
     */
  /* void setPromptDialogs (in nsIPrompt dialogs); */
  NS_SCRIPTABLE NS_IMETHOD SetPromptDialogs(nsIPrompt *dialogs) = 0;

};

  NS_DEFINE_STATIC_IID_ACCESSOR(nsIAuthPromptWrapper, NS_IAUTHPROMPTWRAPPER_IID)

/* Use this macro when declaring classes that implement this interface. */
#define NS_DECL_NSIAUTHPROMPTWRAPPER \
  NS_SCRIPTABLE NS_IMETHOD SetPromptDialogs(nsIPrompt *dialogs); 

/* Use this macro to declare functions that forward the behavior of this interface to another object. */
#define NS_FORWARD_NSIAUTHPROMPTWRAPPER(_to) \
  NS_SCRIPTABLE NS_IMETHOD SetPromptDialogs(nsIPrompt *dialogs) { return _to SetPromptDialogs(dialogs); } 

/* Use this macro to declare functions that forward the behavior of this interface to another object in a safe way. */
#define NS_FORWARD_SAFE_NSIAUTHPROMPTWRAPPER(_to) \
  NS_SCRIPTABLE NS_IMETHOD SetPromptDialogs(nsIPrompt *dialogs) { return !_to ? NS_ERROR_NULL_POINTER : _to->SetPromptDialogs(dialogs); } 

#if 0
/* Use the code below as a template for the implementation class for this interface. */

/* Header file */
class nsAuthPromptWrapper : public nsIAuthPromptWrapper
{
public:
  NS_DECL_ISUPPORTS
  NS_DECL_NSIAUTHPROMPTWRAPPER

  nsAuthPromptWrapper();

private:
  ~nsAuthPromptWrapper();

protected:
  /* additional members */
};

/* Implementation file */
NS_IMPL_ISUPPORTS1(nsAuthPromptWrapper, nsIAuthPromptWrapper)

nsAuthPromptWrapper::nsAuthPromptWrapper()
{
  /* member initializers and constructor code */
}

nsAuthPromptWrapper::~nsAuthPromptWrapper()
{
  /* destructor code */
}

/* void setPromptDialogs (in nsIPrompt dialogs); */
NS_IMETHODIMP nsAuthPromptWrapper::SetPromptDialogs(nsIPrompt *dialogs)
{
    return NS_ERROR_NOT_IMPLEMENTED;
}

/* End of implementation class template. */
#endif


#endif /* __gen_nsIAuthPromptWrapper_h__ */
