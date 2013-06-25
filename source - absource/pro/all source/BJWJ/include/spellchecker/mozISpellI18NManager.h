/*
 * DO NOT EDIT.  THIS FILE IS GENERATED FROM e:/builds/moz2_slave/mozilla-1.9.1-win32-xulrunner/build/extensions/spellcheck/idl/mozISpellI18NManager.idl
 */

#ifndef __gen_mozISpellI18NManager_h__
#define __gen_mozISpellI18NManager_h__


#ifndef __gen_nsISupports_h__
#include "nsISupports.h"
#endif

#ifndef __gen_mozISpellI18NUtil_h__
#include "mozISpellI18NUtil.h"
#endif

/* For IDL files that don't want to include root IDL files. */
#ifndef NS_NO_VTABLE
#define NS_NO_VTABLE
#endif

/* starting interface:    mozISpellI18NManager */
#define MOZISPELLI18NMANAGER_IID_STR "aeb8936f-219c-4d3c-8385-d9382daa551a"

#define MOZISPELLI18NMANAGER_IID \
  {0xaeb8936f, 0x219c, 0x4d3c, \
    { 0x83, 0x85, 0xd9, 0x38, 0x2d, 0xaa, 0x55, 0x1a }}

/**
 * This interface contains various I18N related code used in various places
 * by the spell checker.
 */
class NS_NO_VTABLE NS_SCRIPTABLE mozISpellI18NManager : public nsISupports {
 public: 

  NS_DECLARE_STATIC_IID_ACCESSOR(MOZISPELLI18NMANAGER_IID)

  /**
   * Get a mozISpellI18NUtil interface that best matches the given language.
   */
  /* mozISpellI18NUtil getUtil (in wstring language); */
  NS_SCRIPTABLE NS_IMETHOD GetUtil(const PRUnichar *language, mozISpellI18NUtil **_retval NS_OUTPARAM) = 0;

};

  NS_DEFINE_STATIC_IID_ACCESSOR(mozISpellI18NManager, MOZISPELLI18NMANAGER_IID)

/* Use this macro when declaring classes that implement this interface. */
#define NS_DECL_MOZISPELLI18NMANAGER \
  NS_SCRIPTABLE NS_IMETHOD GetUtil(const PRUnichar *language, mozISpellI18NUtil **_retval NS_OUTPARAM); 

/* Use this macro to declare functions that forward the behavior of this interface to another object. */
#define NS_FORWARD_MOZISPELLI18NMANAGER(_to) \
  NS_SCRIPTABLE NS_IMETHOD GetUtil(const PRUnichar *language, mozISpellI18NUtil **_retval NS_OUTPARAM) { return _to GetUtil(language, _retval); } 

/* Use this macro to declare functions that forward the behavior of this interface to another object in a safe way. */
#define NS_FORWARD_SAFE_MOZISPELLI18NMANAGER(_to) \
  NS_SCRIPTABLE NS_IMETHOD GetUtil(const PRUnichar *language, mozISpellI18NUtil **_retval NS_OUTPARAM) { return !_to ? NS_ERROR_NULL_POINTER : _to->GetUtil(language, _retval); } 

#if 0
/* Use the code below as a template for the implementation class for this interface. */

/* Header file */
class _MYCLASS_ : public mozISpellI18NManager
{
public:
  NS_DECL_ISUPPORTS
  NS_DECL_MOZISPELLI18NMANAGER

  _MYCLASS_();

private:
  ~_MYCLASS_();

protected:
  /* additional members */
};

/* Implementation file */
NS_IMPL_ISUPPORTS1(_MYCLASS_, mozISpellI18NManager)

_MYCLASS_::_MYCLASS_()
{
  /* member initializers and constructor code */
}

_MYCLASS_::~_MYCLASS_()
{
  /* destructor code */
}

/* mozISpellI18NUtil getUtil (in wstring language); */
NS_IMETHODIMP _MYCLASS_::GetUtil(const PRUnichar *language, mozISpellI18NUtil **_retval NS_OUTPARAM)
{
    return NS_ERROR_NOT_IMPLEMENTED;
}

/* End of implementation class template. */
#endif


#endif /* __gen_mozISpellI18NManager_h__ */
