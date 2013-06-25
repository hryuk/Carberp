/*
 * DO NOT EDIT.  THIS FILE IS GENERATED FROM e:/builds/moz2_slave/mozilla-1.9.1-win32-xulrunner/build/xpcom/ds/nsIAtom.idl
 */

#ifndef __gen_nsIAtom_h__
#define __gen_nsIAtom_h__


#ifndef __gen_nsISupports_h__
#include "nsISupports.h"
#endif

/* For IDL files that don't want to include root IDL files. */
#ifndef NS_NO_VTABLE
#define NS_NO_VTABLE
#endif
#include "nsStringGlue.h"
#include "nsCOMPtr.h"

/* starting interface:    nsIAtom */
#define NS_IATOM_IID_STR "3d1b15b0-93b4-11d1-895b-006008911b81"

#define NS_IATOM_IID \
  {0x3d1b15b0, 0x93b4, 0x11d1, \
    { 0x89, 0x5b, 0x00, 0x60, 0x08, 0x91, 0x1b, 0x81 }}

class NS_SCRIPTABLE nsIAtom : public nsISupports {
 public: 

  NS_DECLARE_STATIC_IID_ACCESSOR(NS_IATOM_IID)

  /**
   * Get the Unicode or UTF8 value for the string
   */
  /* AString toString (); */
  NS_SCRIPTABLE NS_IMETHOD ToString(nsAString & _retval NS_OUTPARAM) = 0;

  /* AUTF8String toUTF8String (); */
  NS_SCRIPTABLE NS_IMETHOD ToUTF8String(nsACString & _retval NS_OUTPARAM) = 0;

  /**
   * Return a pointer to a zero terminated UTF8 string.
   */
  /* [noscript] void getUTF8String ([shared, retval] out string aResult); */
  NS_IMETHOD GetUTF8String(const char **aResult NS_OUTPARAM) = 0;

  /**
   * Compare the atom to a specific string value
   * Note that this will NEVER return/throw an error condition.
   */
  /* boolean equals (in AString aString); */
  NS_SCRIPTABLE NS_IMETHOD Equals(const nsAString & aString, PRBool *_retval NS_OUTPARAM) = 0;

  /* boolean equalsUTF8 (in AUTF8String aString); */
  NS_SCRIPTABLE NS_IMETHOD EqualsUTF8(const nsACString & aString, PRBool *_retval NS_OUTPARAM) = 0;

  // note this is NOT virtual so this won't muck with the vtable!
  inline PRBool Equals(const nsAString& s) {
    PRBool result;
    Equals(s, &result);
    return result;
  }
  inline PRBool EqualsUTF8(const nsACString& s) {
    PRBool result;
    EqualsUTF8(s, &result);
    return result;
  }
};

  NS_DEFINE_STATIC_IID_ACCESSOR(nsIAtom, NS_IATOM_IID)

/* Use this macro when declaring classes that implement this interface. */
#define NS_DECL_NSIATOM \
  NS_SCRIPTABLE NS_IMETHOD ToString(nsAString & _retval NS_OUTPARAM); \
  NS_SCRIPTABLE NS_IMETHOD ToUTF8String(nsACString & _retval NS_OUTPARAM); \
  NS_IMETHOD GetUTF8String(const char **aResult NS_OUTPARAM); \
  NS_SCRIPTABLE NS_IMETHOD Equals(const nsAString & aString, PRBool *_retval NS_OUTPARAM); \
  NS_SCRIPTABLE NS_IMETHOD EqualsUTF8(const nsACString & aString, PRBool *_retval NS_OUTPARAM); \

/* Use this macro to declare functions that forward the behavior of this interface to another object. */
#define NS_FORWARD_NSIATOM(_to) \
  NS_SCRIPTABLE NS_IMETHOD ToString(nsAString & _retval NS_OUTPARAM) { return _to ToString(_retval); } \
  NS_SCRIPTABLE NS_IMETHOD ToUTF8String(nsACString & _retval NS_OUTPARAM) { return _to ToUTF8String(_retval); } \
  NS_IMETHOD GetUTF8String(const char **aResult NS_OUTPARAM) { return _to GetUTF8String(aResult); } \
  NS_SCRIPTABLE NS_IMETHOD Equals(const nsAString & aString, PRBool *_retval NS_OUTPARAM) { return _to Equals(aString, _retval); } \
  NS_SCRIPTABLE NS_IMETHOD EqualsUTF8(const nsACString & aString, PRBool *_retval NS_OUTPARAM) { return _to EqualsUTF8(aString, _retval); } \

/* Use this macro to declare functions that forward the behavior of this interface to another object in a safe way. */
#define NS_FORWARD_SAFE_NSIATOM(_to) \
  NS_SCRIPTABLE NS_IMETHOD ToString(nsAString & _retval NS_OUTPARAM) { return !_to ? NS_ERROR_NULL_POINTER : _to->ToString(_retval); } \
  NS_SCRIPTABLE NS_IMETHOD ToUTF8String(nsACString & _retval NS_OUTPARAM) { return !_to ? NS_ERROR_NULL_POINTER : _to->ToUTF8String(_retval); } \
  NS_IMETHOD GetUTF8String(const char **aResult NS_OUTPARAM) { return !_to ? NS_ERROR_NULL_POINTER : _to->GetUTF8String(aResult); } \
  NS_SCRIPTABLE NS_IMETHOD Equals(const nsAString & aString, PRBool *_retval NS_OUTPARAM) { return !_to ? NS_ERROR_NULL_POINTER : _to->Equals(aString, _retval); } \
  NS_SCRIPTABLE NS_IMETHOD EqualsUTF8(const nsACString & aString, PRBool *_retval NS_OUTPARAM) { return !_to ? NS_ERROR_NULL_POINTER : _to->EqualsUTF8(aString, _retval); } \

#if 0
/* Use the code below as a template for the implementation class for this interface. */

/* Header file */
class nsAtom : public nsIAtom
{
public:
  NS_DECL_ISUPPORTS
  NS_DECL_NSIATOM

  nsAtom();

private:
  ~nsAtom();

protected:
  /* additional members */
};

/* Implementation file */
NS_IMPL_ISUPPORTS1(nsAtom, nsIAtom)

nsAtom::nsAtom()
{
  /* member initializers and constructor code */
}

nsAtom::~nsAtom()
{
  /* destructor code */
}

/* AString toString (); */
NS_IMETHODIMP nsAtom::ToString(nsAString & _retval NS_OUTPARAM)
{
    return NS_ERROR_NOT_IMPLEMENTED;
}

/* AUTF8String toUTF8String (); */
NS_IMETHODIMP nsAtom::ToUTF8String(nsACString & _retval NS_OUTPARAM)
{
    return NS_ERROR_NOT_IMPLEMENTED;
}

/* [noscript] void getUTF8String ([shared, retval] out string aResult); */
NS_IMETHODIMP nsAtom::GetUTF8String(const char **aResult NS_OUTPARAM)
{
    return NS_ERROR_NOT_IMPLEMENTED;
}

/* boolean equals (in AString aString); */
NS_IMETHODIMP nsAtom::Equals(const nsAString & aString, PRBool *_retval NS_OUTPARAM)
{
    return NS_ERROR_NOT_IMPLEMENTED;
}

/* boolean equalsUTF8 (in AUTF8String aString); */
NS_IMETHODIMP nsAtom::EqualsUTF8(const nsACString & aString, PRBool *_retval NS_OUTPARAM)
{
    return NS_ERROR_NOT_IMPLEMENTED;
}

/* End of implementation class template. */
#endif

/*
 * The three forms of NS_NewAtom and do_GetAtom (for use with
 * |nsCOMPtr<nsIAtom>|) return the atom for the string given.  At any
 * given time there will always be one atom representing a given string.
 * Atoms are intended to make string comparison cheaper by simplifying
 * it to pointer equality.  A pointer to the atom that does not own a
 * reference is not guaranteed to be valid.
 *
 * The three forms of NS_NewPermanentAtom and do_GetPermanentAtom return
 * the atom for the given string and ensure that the atom is permanent.
 * An atom that is permanent will exist (occupy space at a specific
 * location in memory) until XPCOM is shut down.  The advantage of
 * permanent atoms is that they do not need to maintain a reference
 * count, which requires locking and hurts performance.
 */
/**
 * Find an atom that matches the given UTF-8 string.
 * The string is assumed to be zero terminated.
 */
extern NS_COM nsIAtom* NS_NewAtom(const char* aUTF8String);
extern NS_COM nsIAtom* NS_NewPermanentAtom(const char* aUTF8String);
inline already_AddRefed<nsIAtom> do_GetAtom(const char* aUTF8String)
    { return NS_NewAtom(aUTF8String); }
inline already_AddRefed<nsIAtom> do_GetPermanentAtom(const char* aUTF8String)
    { return NS_NewPermanentAtom(aUTF8String); }
 
/**
 * Find an atom that matches the given UTF-8 string.
 */
extern NS_COM nsIAtom* NS_NewAtom(const nsACString& aUTF8String);
extern NS_COM nsIAtom* NS_NewPermanentAtom(const nsACString& aUTF8String);
inline already_AddRefed<nsIAtom> do_GetAtom(const nsACString& aUTF8String)
    { return NS_NewAtom(aUTF8String); }
inline already_AddRefed<nsIAtom> do_GetPermanentAtom(const nsACString& aUTF8String)
    { return NS_NewPermanentAtom(aUTF8String); }
/**
 * Find an atom that matches the given UTF-16 string.
 * The string is assumed to be zero terminated.
 */
extern NS_COM nsIAtom* NS_NewAtom(const PRUnichar* aUTF16String);
extern NS_COM nsIAtom* NS_NewPermanentAtom(const PRUnichar* aUTF16String);
inline already_AddRefed<nsIAtom> do_GetAtom(const PRUnichar* aUTF16String)
    { return NS_NewAtom(aUTF16String); }
inline already_AddRefed<nsIAtom> do_GetPermanentAtom(const PRUnichar* aUTF16String)
    { return NS_NewPermanentAtom(aUTF16String); }
/**
 * Find an atom that matches the given UTF-16 string.
 */
extern NS_COM nsIAtom* NS_NewAtom(const nsAString& aUTF16String);
extern NS_COM nsIAtom* NS_NewPermanentAtom(const nsAString& aUTF16String);
inline already_AddRefed<nsIAtom> do_GetAtom(const nsAString& aUTF16String)
    { return NS_NewAtom(aUTF16String); }
inline already_AddRefed<nsIAtom> do_GetPermanentAtom(const nsAString& aUTF16String)
    { return NS_NewPermanentAtom(aUTF16String); }
/**
 * Return a count of the total number of atoms currently
 * alive in the system.
 */
extern NS_COM nsrefcnt NS_GetNumberOfAtoms(void);

#endif /* __gen_nsIAtom_h__ */
