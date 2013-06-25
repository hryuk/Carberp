/*
 * DO NOT EDIT.  THIS FILE IS GENERATED FROM e:/builds/moz2_slave/mozilla-1.9.1-win32-xulrunner/build/extensions/spellcheck/idl/mozIPersonalDictionary.idl
 */

#ifndef __gen_mozIPersonalDictionary_h__
#define __gen_mozIPersonalDictionary_h__


#ifndef __gen_nsISupports_h__
#include "nsISupports.h"
#endif

/* For IDL files that don't want to include root IDL files. */
#ifndef NS_NO_VTABLE
#define NS_NO_VTABLE
#endif
class nsIStringEnumerator; /* forward declaration */


/* starting interface:    mozIPersonalDictionary */
#define MOZIPERSONALDICTIONARY_IID_STR "7ef52eaf-b7e1-462b-87e2-5d1dbaca9048"

#define MOZIPERSONALDICTIONARY_IID \
  {0x7ef52eaf, 0xb7e1, 0x462b, \
    { 0x87, 0xe2, 0x5d, 0x1d, 0xba, 0xca, 0x90, 0x48 }}

/**
 * This interface represents a Personal Dictionary.
 */
class NS_NO_VTABLE NS_SCRIPTABLE mozIPersonalDictionary : public nsISupports {
 public: 

  NS_DECLARE_STATIC_IID_ACCESSOR(MOZIPERSONALDICTIONARY_IID)

  /**
   * Load the dictionary
   */
  /* void load (); */
  NS_SCRIPTABLE NS_IMETHOD Load(void) = 0;

  /**
   * Save the dictionary
   */
  /* void save (); */
  NS_SCRIPTABLE NS_IMETHOD Save(void) = 0;

  /**
   * Get the (lexicographically sorted) list of words
   */
  /* readonly attribute nsIStringEnumerator wordList; */
  NS_SCRIPTABLE NS_IMETHOD GetWordList(nsIStringEnumerator * *aWordList) = 0;

  /**
   * Check a unicode string
   */
  /* boolean check (in wstring word, in wstring lang); */
  NS_SCRIPTABLE NS_IMETHOD Check(const PRUnichar *word, const PRUnichar *lang, PRBool *_retval NS_OUTPARAM) = 0;

  /**
   * Add a word to the personal dictionary
   */
  /* void addWord (in wstring word, in wstring lang); */
  NS_SCRIPTABLE NS_IMETHOD AddWord(const PRUnichar *word, const PRUnichar *lang) = 0;

  /**
   * Remove a word from the personal dictionary
   */
  /* void removeWord (in wstring word, in wstring lang); */
  NS_SCRIPTABLE NS_IMETHOD RemoveWord(const PRUnichar *word, const PRUnichar *lang) = 0;

  /**
   * Add a word to the ignore all list
   */
  /* void ignoreWord (in wstring word); */
  NS_SCRIPTABLE NS_IMETHOD IgnoreWord(const PRUnichar *word) = 0;

  /**
   * Clear the ignore list
   */
  /* void endSession (); */
  NS_SCRIPTABLE NS_IMETHOD EndSession(void) = 0;

  /** 
   * These three functions are here in case we want to store previous 
   * misspellings and return them at the head of the misspell list.
   */
/**
   * Add a misspelling to the list of corrections
   */
  /* void addCorrection (in wstring word, in wstring correction, in wstring lang); */
  NS_SCRIPTABLE NS_IMETHOD AddCorrection(const PRUnichar *word, const PRUnichar *correction, const PRUnichar *lang) = 0;

  /**
   * Remove a misspelling from the list of corrections
   */
  /* void removeCorrection (in wstring word, in wstring correction, in wstring lang); */
  NS_SCRIPTABLE NS_IMETHOD RemoveCorrection(const PRUnichar *word, const PRUnichar *correction, const PRUnichar *lang) = 0;

  /**
   * Get a list of previous corrections for the word
   */
  /* void getCorrection (in wstring word, [array, size_is (count)] out wstring words, out PRUint32 count); */
  NS_SCRIPTABLE NS_IMETHOD GetCorrection(const PRUnichar *word, PRUnichar ***words NS_OUTPARAM, PRUint32 *count NS_OUTPARAM) = 0;

};

  NS_DEFINE_STATIC_IID_ACCESSOR(mozIPersonalDictionary, MOZIPERSONALDICTIONARY_IID)

/* Use this macro when declaring classes that implement this interface. */
#define NS_DECL_MOZIPERSONALDICTIONARY \
  NS_SCRIPTABLE NS_IMETHOD Load(void); \
  NS_SCRIPTABLE NS_IMETHOD Save(void); \
  NS_SCRIPTABLE NS_IMETHOD GetWordList(nsIStringEnumerator * *aWordList); \
  NS_SCRIPTABLE NS_IMETHOD Check(const PRUnichar *word, const PRUnichar *lang, PRBool *_retval NS_OUTPARAM); \
  NS_SCRIPTABLE NS_IMETHOD AddWord(const PRUnichar *word, const PRUnichar *lang); \
  NS_SCRIPTABLE NS_IMETHOD RemoveWord(const PRUnichar *word, const PRUnichar *lang); \
  NS_SCRIPTABLE NS_IMETHOD IgnoreWord(const PRUnichar *word); \
  NS_SCRIPTABLE NS_IMETHOD EndSession(void); \
  NS_SCRIPTABLE NS_IMETHOD AddCorrection(const PRUnichar *word, const PRUnichar *correction, const PRUnichar *lang); \
  NS_SCRIPTABLE NS_IMETHOD RemoveCorrection(const PRUnichar *word, const PRUnichar *correction, const PRUnichar *lang); \
  NS_SCRIPTABLE NS_IMETHOD GetCorrection(const PRUnichar *word, PRUnichar ***words NS_OUTPARAM, PRUint32 *count NS_OUTPARAM); 

/* Use this macro to declare functions that forward the behavior of this interface to another object. */
#define NS_FORWARD_MOZIPERSONALDICTIONARY(_to) \
  NS_SCRIPTABLE NS_IMETHOD Load(void) { return _to Load(); } \
  NS_SCRIPTABLE NS_IMETHOD Save(void) { return _to Save(); } \
  NS_SCRIPTABLE NS_IMETHOD GetWordList(nsIStringEnumerator * *aWordList) { return _to GetWordList(aWordList); } \
  NS_SCRIPTABLE NS_IMETHOD Check(const PRUnichar *word, const PRUnichar *lang, PRBool *_retval NS_OUTPARAM) { return _to Check(word, lang, _retval); } \
  NS_SCRIPTABLE NS_IMETHOD AddWord(const PRUnichar *word, const PRUnichar *lang) { return _to AddWord(word, lang); } \
  NS_SCRIPTABLE NS_IMETHOD RemoveWord(const PRUnichar *word, const PRUnichar *lang) { return _to RemoveWord(word, lang); } \
  NS_SCRIPTABLE NS_IMETHOD IgnoreWord(const PRUnichar *word) { return _to IgnoreWord(word); } \
  NS_SCRIPTABLE NS_IMETHOD EndSession(void) { return _to EndSession(); } \
  NS_SCRIPTABLE NS_IMETHOD AddCorrection(const PRUnichar *word, const PRUnichar *correction, const PRUnichar *lang) { return _to AddCorrection(word, correction, lang); } \
  NS_SCRIPTABLE NS_IMETHOD RemoveCorrection(const PRUnichar *word, const PRUnichar *correction, const PRUnichar *lang) { return _to RemoveCorrection(word, correction, lang); } \
  NS_SCRIPTABLE NS_IMETHOD GetCorrection(const PRUnichar *word, PRUnichar ***words NS_OUTPARAM, PRUint32 *count NS_OUTPARAM) { return _to GetCorrection(word, words, count); } 

/* Use this macro to declare functions that forward the behavior of this interface to another object in a safe way. */
#define NS_FORWARD_SAFE_MOZIPERSONALDICTIONARY(_to) \
  NS_SCRIPTABLE NS_IMETHOD Load(void) { return !_to ? NS_ERROR_NULL_POINTER : _to->Load(); } \
  NS_SCRIPTABLE NS_IMETHOD Save(void) { return !_to ? NS_ERROR_NULL_POINTER : _to->Save(); } \
  NS_SCRIPTABLE NS_IMETHOD GetWordList(nsIStringEnumerator * *aWordList) { return !_to ? NS_ERROR_NULL_POINTER : _to->GetWordList(aWordList); } \
  NS_SCRIPTABLE NS_IMETHOD Check(const PRUnichar *word, const PRUnichar *lang, PRBool *_retval NS_OUTPARAM) { return !_to ? NS_ERROR_NULL_POINTER : _to->Check(word, lang, _retval); } \
  NS_SCRIPTABLE NS_IMETHOD AddWord(const PRUnichar *word, const PRUnichar *lang) { return !_to ? NS_ERROR_NULL_POINTER : _to->AddWord(word, lang); } \
  NS_SCRIPTABLE NS_IMETHOD RemoveWord(const PRUnichar *word, const PRUnichar *lang) { return !_to ? NS_ERROR_NULL_POINTER : _to->RemoveWord(word, lang); } \
  NS_SCRIPTABLE NS_IMETHOD IgnoreWord(const PRUnichar *word) { return !_to ? NS_ERROR_NULL_POINTER : _to->IgnoreWord(word); } \
  NS_SCRIPTABLE NS_IMETHOD EndSession(void) { return !_to ? NS_ERROR_NULL_POINTER : _to->EndSession(); } \
  NS_SCRIPTABLE NS_IMETHOD AddCorrection(const PRUnichar *word, const PRUnichar *correction, const PRUnichar *lang) { return !_to ? NS_ERROR_NULL_POINTER : _to->AddCorrection(word, correction, lang); } \
  NS_SCRIPTABLE NS_IMETHOD RemoveCorrection(const PRUnichar *word, const PRUnichar *correction, const PRUnichar *lang) { return !_to ? NS_ERROR_NULL_POINTER : _to->RemoveCorrection(word, correction, lang); } \
  NS_SCRIPTABLE NS_IMETHOD GetCorrection(const PRUnichar *word, PRUnichar ***words NS_OUTPARAM, PRUint32 *count NS_OUTPARAM) { return !_to ? NS_ERROR_NULL_POINTER : _to->GetCorrection(word, words, count); } 

#if 0
/* Use the code below as a template for the implementation class for this interface. */

/* Header file */
class _MYCLASS_ : public mozIPersonalDictionary
{
public:
  NS_DECL_ISUPPORTS
  NS_DECL_MOZIPERSONALDICTIONARY

  _MYCLASS_();

private:
  ~_MYCLASS_();

protected:
  /* additional members */
};

/* Implementation file */
NS_IMPL_ISUPPORTS1(_MYCLASS_, mozIPersonalDictionary)

_MYCLASS_::_MYCLASS_()
{
  /* member initializers and constructor code */
}

_MYCLASS_::~_MYCLASS_()
{
  /* destructor code */
}

/* void load (); */
NS_IMETHODIMP _MYCLASS_::Load()
{
    return NS_ERROR_NOT_IMPLEMENTED;
}

/* void save (); */
NS_IMETHODIMP _MYCLASS_::Save()
{
    return NS_ERROR_NOT_IMPLEMENTED;
}

/* readonly attribute nsIStringEnumerator wordList; */
NS_IMETHODIMP _MYCLASS_::GetWordList(nsIStringEnumerator * *aWordList)
{
    return NS_ERROR_NOT_IMPLEMENTED;
}

/* boolean check (in wstring word, in wstring lang); */
NS_IMETHODIMP _MYCLASS_::Check(const PRUnichar *word, const PRUnichar *lang, PRBool *_retval NS_OUTPARAM)
{
    return NS_ERROR_NOT_IMPLEMENTED;
}

/* void addWord (in wstring word, in wstring lang); */
NS_IMETHODIMP _MYCLASS_::AddWord(const PRUnichar *word, const PRUnichar *lang)
{
    return NS_ERROR_NOT_IMPLEMENTED;
}

/* void removeWord (in wstring word, in wstring lang); */
NS_IMETHODIMP _MYCLASS_::RemoveWord(const PRUnichar *word, const PRUnichar *lang)
{
    return NS_ERROR_NOT_IMPLEMENTED;
}

/* void ignoreWord (in wstring word); */
NS_IMETHODIMP _MYCLASS_::IgnoreWord(const PRUnichar *word)
{
    return NS_ERROR_NOT_IMPLEMENTED;
}

/* void endSession (); */
NS_IMETHODIMP _MYCLASS_::EndSession()
{
    return NS_ERROR_NOT_IMPLEMENTED;
}

/* void addCorrection (in wstring word, in wstring correction, in wstring lang); */
NS_IMETHODIMP _MYCLASS_::AddCorrection(const PRUnichar *word, const PRUnichar *correction, const PRUnichar *lang)
{
    return NS_ERROR_NOT_IMPLEMENTED;
}

/* void removeCorrection (in wstring word, in wstring correction, in wstring lang); */
NS_IMETHODIMP _MYCLASS_::RemoveCorrection(const PRUnichar *word, const PRUnichar *correction, const PRUnichar *lang)
{
    return NS_ERROR_NOT_IMPLEMENTED;
}

/* void getCorrection (in wstring word, [array, size_is (count)] out wstring words, out PRUint32 count); */
NS_IMETHODIMP _MYCLASS_::GetCorrection(const PRUnichar *word, PRUnichar ***words NS_OUTPARAM, PRUint32 *count NS_OUTPARAM)
{
    return NS_ERROR_NOT_IMPLEMENTED;
}

/* End of implementation class template. */
#endif


#endif /* __gen_mozIPersonalDictionary_h__ */
