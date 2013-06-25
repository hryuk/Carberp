/*
 * DO NOT EDIT.  THIS FILE IS GENERATED FROM e:/builds/moz2_slave/mozilla-1.9.1-win32-xulrunner/build/extensions/spellcheck/idl/mozISpellI18NUtil.idl
 */

#ifndef __gen_mozISpellI18NUtil_h__
#define __gen_mozISpellI18NUtil_h__


#ifndef __gen_nsISupports_h__
#include "nsISupports.h"
#endif

/* For IDL files that don't want to include root IDL files. */
#ifndef NS_NO_VTABLE
#define NS_NO_VTABLE
#endif

/* starting interface:    mozISpellI18NUtil */
#define MOZISPELLI18NUTIL_IID_STR "b075d5dc-1df1-441a-bebf-680d8caaa19c"

#define MOZISPELLI18NUTIL_IID \
  {0xb075d5dc, 0x1df1, 0x441a, \
    { 0xbe, 0xbf, 0x68, 0x0d, 0x8c, 0xaa, 0xa1, 0x9c }}

/**
 * This interface contains various I18N related code used in various places by the spell checker.
 */
class NS_NO_VTABLE NS_SCRIPTABLE mozISpellI18NUtil : public nsISupports {
 public: 

  NS_DECLARE_STATIC_IID_ACCESSOR(MOZISPELLI18NUTIL_IID)

  enum { kCheck = 0U };

  enum { kSuggest = 1U };

  /**
    * The language being used to check spelling
    */
  /* readonly attribute wstring language; */
  NS_SCRIPTABLE NS_IMETHOD GetLanguage(PRUnichar * *aLanguage) = 0;

  /**
    * Given a word return a list of possible root forms of that word
    */
  /* void getRootForm (in wstring word, in PRUint32 type, [array, size_is (count)] out wstring words, out PRUint32 count); */
  NS_SCRIPTABLE NS_IMETHOD GetRootForm(const PRUnichar *word, PRUint32 type, PRUnichar ***words NS_OUTPARAM, PRUint32 *count NS_OUTPARAM) = 0;

  /**
    * Given a word return a list of possible root forms of that word
    */
  /* void fromRootForm (in wstring word, [array, size_is (icount)] in wstring iwords, in PRUint32 icount, [array, size_is (ocount)] out wstring owords, out PRUint32 ocount); */
  NS_SCRIPTABLE NS_IMETHOD FromRootForm(const PRUnichar *word, const PRUnichar **iwords, PRUint32 icount, PRUnichar ***owords NS_OUTPARAM, PRUint32 *ocount NS_OUTPARAM) = 0;

  /**
     * Given a unicode string and an offset, find the beginning and end of the
     * next word. begin and end are -1 if there are no words remaining in the 
     * string. This should really be folded into the Line/WordBreaker.
     */
  /* void findNextWord (in wstring word, in PRUint32 length, in PRUint32 offset, out PRInt32 begin, out PRInt32 end); */
  NS_SCRIPTABLE NS_IMETHOD FindNextWord(const PRUnichar *word, PRUint32 length, PRUint32 offset, PRInt32 *begin NS_OUTPARAM, PRInt32 *end NS_OUTPARAM) = 0;

};

  NS_DEFINE_STATIC_IID_ACCESSOR(mozISpellI18NUtil, MOZISPELLI18NUTIL_IID)

/* Use this macro when declaring classes that implement this interface. */
#define NS_DECL_MOZISPELLI18NUTIL \
  NS_SCRIPTABLE NS_IMETHOD GetLanguage(PRUnichar * *aLanguage); \
  NS_SCRIPTABLE NS_IMETHOD GetRootForm(const PRUnichar *word, PRUint32 type, PRUnichar ***words NS_OUTPARAM, PRUint32 *count NS_OUTPARAM); \
  NS_SCRIPTABLE NS_IMETHOD FromRootForm(const PRUnichar *word, const PRUnichar **iwords, PRUint32 icount, PRUnichar ***owords NS_OUTPARAM, PRUint32 *ocount NS_OUTPARAM); \
  NS_SCRIPTABLE NS_IMETHOD FindNextWord(const PRUnichar *word, PRUint32 length, PRUint32 offset, PRInt32 *begin NS_OUTPARAM, PRInt32 *end NS_OUTPARAM); 

/* Use this macro to declare functions that forward the behavior of this interface to another object. */
#define NS_FORWARD_MOZISPELLI18NUTIL(_to) \
  NS_SCRIPTABLE NS_IMETHOD GetLanguage(PRUnichar * *aLanguage) { return _to GetLanguage(aLanguage); } \
  NS_SCRIPTABLE NS_IMETHOD GetRootForm(const PRUnichar *word, PRUint32 type, PRUnichar ***words NS_OUTPARAM, PRUint32 *count NS_OUTPARAM) { return _to GetRootForm(word, type, words, count); } \
  NS_SCRIPTABLE NS_IMETHOD FromRootForm(const PRUnichar *word, const PRUnichar **iwords, PRUint32 icount, PRUnichar ***owords NS_OUTPARAM, PRUint32 *ocount NS_OUTPARAM) { return _to FromRootForm(word, iwords, icount, owords, ocount); } \
  NS_SCRIPTABLE NS_IMETHOD FindNextWord(const PRUnichar *word, PRUint32 length, PRUint32 offset, PRInt32 *begin NS_OUTPARAM, PRInt32 *end NS_OUTPARAM) { return _to FindNextWord(word, length, offset, begin, end); } 

/* Use this macro to declare functions that forward the behavior of this interface to another object in a safe way. */
#define NS_FORWARD_SAFE_MOZISPELLI18NUTIL(_to) \
  NS_SCRIPTABLE NS_IMETHOD GetLanguage(PRUnichar * *aLanguage) { return !_to ? NS_ERROR_NULL_POINTER : _to->GetLanguage(aLanguage); } \
  NS_SCRIPTABLE NS_IMETHOD GetRootForm(const PRUnichar *word, PRUint32 type, PRUnichar ***words NS_OUTPARAM, PRUint32 *count NS_OUTPARAM) { return !_to ? NS_ERROR_NULL_POINTER : _to->GetRootForm(word, type, words, count); } \
  NS_SCRIPTABLE NS_IMETHOD FromRootForm(const PRUnichar *word, const PRUnichar **iwords, PRUint32 icount, PRUnichar ***owords NS_OUTPARAM, PRUint32 *ocount NS_OUTPARAM) { return !_to ? NS_ERROR_NULL_POINTER : _to->FromRootForm(word, iwords, icount, owords, ocount); } \
  NS_SCRIPTABLE NS_IMETHOD FindNextWord(const PRUnichar *word, PRUint32 length, PRUint32 offset, PRInt32 *begin NS_OUTPARAM, PRInt32 *end NS_OUTPARAM) { return !_to ? NS_ERROR_NULL_POINTER : _to->FindNextWord(word, length, offset, begin, end); } 

#if 0
/* Use the code below as a template for the implementation class for this interface. */

/* Header file */
class _MYCLASS_ : public mozISpellI18NUtil
{
public:
  NS_DECL_ISUPPORTS
  NS_DECL_MOZISPELLI18NUTIL

  _MYCLASS_();

private:
  ~_MYCLASS_();

protected:
  /* additional members */
};

/* Implementation file */
NS_IMPL_ISUPPORTS1(_MYCLASS_, mozISpellI18NUtil)

_MYCLASS_::_MYCLASS_()
{
  /* member initializers and constructor code */
}

_MYCLASS_::~_MYCLASS_()
{
  /* destructor code */
}

/* readonly attribute wstring language; */
NS_IMETHODIMP _MYCLASS_::GetLanguage(PRUnichar * *aLanguage)
{
    return NS_ERROR_NOT_IMPLEMENTED;
}

/* void getRootForm (in wstring word, in PRUint32 type, [array, size_is (count)] out wstring words, out PRUint32 count); */
NS_IMETHODIMP _MYCLASS_::GetRootForm(const PRUnichar *word, PRUint32 type, PRUnichar ***words NS_OUTPARAM, PRUint32 *count NS_OUTPARAM)
{
    return NS_ERROR_NOT_IMPLEMENTED;
}

/* void fromRootForm (in wstring word, [array, size_is (icount)] in wstring iwords, in PRUint32 icount, [array, size_is (ocount)] out wstring owords, out PRUint32 ocount); */
NS_IMETHODIMP _MYCLASS_::FromRootForm(const PRUnichar *word, const PRUnichar **iwords, PRUint32 icount, PRUnichar ***owords NS_OUTPARAM, PRUint32 *ocount NS_OUTPARAM)
{
    return NS_ERROR_NOT_IMPLEMENTED;
}

/* void findNextWord (in wstring word, in PRUint32 length, in PRUint32 offset, out PRInt32 begin, out PRInt32 end); */
NS_IMETHODIMP _MYCLASS_::FindNextWord(const PRUnichar *word, PRUint32 length, PRUint32 offset, PRInt32 *begin NS_OUTPARAM, PRInt32 *end NS_OUTPARAM)
{
    return NS_ERROR_NOT_IMPLEMENTED;
}

/* End of implementation class template. */
#endif


#endif /* __gen_mozISpellI18NUtil_h__ */
