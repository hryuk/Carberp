/*
 * DO NOT EDIT.  THIS FILE IS GENERATED FROM e:/builds/moz2_slave/mozilla-1.9.1-win32-xulrunner/build/xpcom/ds/nsIINIParser.idl
 */

#ifndef __gen_nsIINIParser_h__
#define __gen_nsIINIParser_h__


#ifndef __gen_nsISupports_h__
#include "nsISupports.h"
#endif

/* For IDL files that don't want to include root IDL files. */
#ifndef NS_NO_VTABLE
#define NS_NO_VTABLE
#endif
class nsIUTF8StringEnumerator; /* forward declaration */

class nsILocalFile; /* forward declaration */


/* starting interface:    nsIINIParser */
#define NS_IINIPARSER_IID_STR "7eb955f6-3e78-4d39-b72f-c1bf12a94bce"

#define NS_IINIPARSER_IID \
  {0x7eb955f6, 0x3e78, 0x4d39, \
    { 0xb7, 0x2f, 0xc1, 0xbf, 0x12, 0xa9, 0x4b, 0xce }}

class NS_NO_VTABLE NS_SCRIPTABLE nsIINIParser : public nsISupports {
 public: 

  NS_DECLARE_STATIC_IID_ACCESSOR(NS_IINIPARSER_IID)

  /**
   * Enumerates the [section]s available in the INI file.
   */
  /* nsIUTF8StringEnumerator getSections (); */
  NS_SCRIPTABLE NS_IMETHOD GetSections(nsIUTF8StringEnumerator **_retval NS_OUTPARAM) = 0;

  /**
   * Enumerates the keys available within a section.
   */
  /* nsIUTF8StringEnumerator getKeys (in AUTF8String aSection); */
  NS_SCRIPTABLE NS_IMETHOD GetKeys(const nsACString & aSection, nsIUTF8StringEnumerator **_retval NS_OUTPARAM) = 0;

  /**
   * Get the value of a string for a particular section and key.
   */
  /* AUTF8String getString (in AUTF8String aSection, in AUTF8String aKey); */
  NS_SCRIPTABLE NS_IMETHOD GetString(const nsACString & aSection, const nsACString & aKey, nsACString & _retval NS_OUTPARAM) = 0;

};

  NS_DEFINE_STATIC_IID_ACCESSOR(nsIINIParser, NS_IINIPARSER_IID)

/* Use this macro when declaring classes that implement this interface. */
#define NS_DECL_NSIINIPARSER \
  NS_SCRIPTABLE NS_IMETHOD GetSections(nsIUTF8StringEnumerator **_retval NS_OUTPARAM); \
  NS_SCRIPTABLE NS_IMETHOD GetKeys(const nsACString & aSection, nsIUTF8StringEnumerator **_retval NS_OUTPARAM); \
  NS_SCRIPTABLE NS_IMETHOD GetString(const nsACString & aSection, const nsACString & aKey, nsACString & _retval NS_OUTPARAM); 

/* Use this macro to declare functions that forward the behavior of this interface to another object. */
#define NS_FORWARD_NSIINIPARSER(_to) \
  NS_SCRIPTABLE NS_IMETHOD GetSections(nsIUTF8StringEnumerator **_retval NS_OUTPARAM) { return _to GetSections(_retval); } \
  NS_SCRIPTABLE NS_IMETHOD GetKeys(const nsACString & aSection, nsIUTF8StringEnumerator **_retval NS_OUTPARAM) { return _to GetKeys(aSection, _retval); } \
  NS_SCRIPTABLE NS_IMETHOD GetString(const nsACString & aSection, const nsACString & aKey, nsACString & _retval NS_OUTPARAM) { return _to GetString(aSection, aKey, _retval); } 

/* Use this macro to declare functions that forward the behavior of this interface to another object in a safe way. */
#define NS_FORWARD_SAFE_NSIINIPARSER(_to) \
  NS_SCRIPTABLE NS_IMETHOD GetSections(nsIUTF8StringEnumerator **_retval NS_OUTPARAM) { return !_to ? NS_ERROR_NULL_POINTER : _to->GetSections(_retval); } \
  NS_SCRIPTABLE NS_IMETHOD GetKeys(const nsACString & aSection, nsIUTF8StringEnumerator **_retval NS_OUTPARAM) { return !_to ? NS_ERROR_NULL_POINTER : _to->GetKeys(aSection, _retval); } \
  NS_SCRIPTABLE NS_IMETHOD GetString(const nsACString & aSection, const nsACString & aKey, nsACString & _retval NS_OUTPARAM) { return !_to ? NS_ERROR_NULL_POINTER : _to->GetString(aSection, aKey, _retval); } 

#if 0
/* Use the code below as a template for the implementation class for this interface. */

/* Header file */
class nsINIParser : public nsIINIParser
{
public:
  NS_DECL_ISUPPORTS
  NS_DECL_NSIINIPARSER

  nsINIParser();

private:
  ~nsINIParser();

protected:
  /* additional members */
};

/* Implementation file */
NS_IMPL_ISUPPORTS1(nsINIParser, nsIINIParser)

nsINIParser::nsINIParser()
{
  /* member initializers and constructor code */
}

nsINIParser::~nsINIParser()
{
  /* destructor code */
}

/* nsIUTF8StringEnumerator getSections (); */
NS_IMETHODIMP nsINIParser::GetSections(nsIUTF8StringEnumerator **_retval NS_OUTPARAM)
{
    return NS_ERROR_NOT_IMPLEMENTED;
}

/* nsIUTF8StringEnumerator getKeys (in AUTF8String aSection); */
NS_IMETHODIMP nsINIParser::GetKeys(const nsACString & aSection, nsIUTF8StringEnumerator **_retval NS_OUTPARAM)
{
    return NS_ERROR_NOT_IMPLEMENTED;
}

/* AUTF8String getString (in AUTF8String aSection, in AUTF8String aKey); */
NS_IMETHODIMP nsINIParser::GetString(const nsACString & aSection, const nsACString & aKey, nsACString & _retval NS_OUTPARAM)
{
    return NS_ERROR_NOT_IMPLEMENTED;
}

/* End of implementation class template. */
#endif


/* starting interface:    nsIINIParserFactory */
#define NS_IINIPARSERFACTORY_IID_STR "ccae7ea5-1218-4b51-aecb-c2d8ecd46af9"

#define NS_IINIPARSERFACTORY_IID \
  {0xccae7ea5, 0x1218, 0x4b51, \
    { 0xae, 0xcb, 0xc2, 0xd8, 0xec, 0xd4, 0x6a, 0xf9 }}

class NS_NO_VTABLE NS_SCRIPTABLE nsIINIParserFactory : public nsISupports {
 public: 

  NS_DECLARE_STATIC_IID_ACCESSOR(NS_IINIPARSERFACTORY_IID)

  /**
   * Create an iniparser instance from a local file.
   */
  /* nsIINIParser createINIParser (in nsILocalFile aINIFile); */
  NS_SCRIPTABLE NS_IMETHOD CreateINIParser(nsILocalFile *aINIFile, nsIINIParser **_retval NS_OUTPARAM) = 0;

};

  NS_DEFINE_STATIC_IID_ACCESSOR(nsIINIParserFactory, NS_IINIPARSERFACTORY_IID)

/* Use this macro when declaring classes that implement this interface. */
#define NS_DECL_NSIINIPARSERFACTORY \
  NS_SCRIPTABLE NS_IMETHOD CreateINIParser(nsILocalFile *aINIFile, nsIINIParser **_retval NS_OUTPARAM); 

/* Use this macro to declare functions that forward the behavior of this interface to another object. */
#define NS_FORWARD_NSIINIPARSERFACTORY(_to) \
  NS_SCRIPTABLE NS_IMETHOD CreateINIParser(nsILocalFile *aINIFile, nsIINIParser **_retval NS_OUTPARAM) { return _to CreateINIParser(aINIFile, _retval); } 

/* Use this macro to declare functions that forward the behavior of this interface to another object in a safe way. */
#define NS_FORWARD_SAFE_NSIINIPARSERFACTORY(_to) \
  NS_SCRIPTABLE NS_IMETHOD CreateINIParser(nsILocalFile *aINIFile, nsIINIParser **_retval NS_OUTPARAM) { return !_to ? NS_ERROR_NULL_POINTER : _to->CreateINIParser(aINIFile, _retval); } 

#if 0
/* Use the code below as a template for the implementation class for this interface. */

/* Header file */
class nsINIParserFactory : public nsIINIParserFactory
{
public:
  NS_DECL_ISUPPORTS
  NS_DECL_NSIINIPARSERFACTORY

  nsINIParserFactory();

private:
  ~nsINIParserFactory();

protected:
  /* additional members */
};

/* Implementation file */
NS_IMPL_ISUPPORTS1(nsINIParserFactory, nsIINIParserFactory)

nsINIParserFactory::nsINIParserFactory()
{
  /* member initializers and constructor code */
}

nsINIParserFactory::~nsINIParserFactory()
{
  /* destructor code */
}

/* nsIINIParser createINIParser (in nsILocalFile aINIFile); */
NS_IMETHODIMP nsINIParserFactory::CreateINIParser(nsILocalFile *aINIFile, nsIINIParser **_retval NS_OUTPARAM)
{
    return NS_ERROR_NOT_IMPLEMENTED;
}

/* End of implementation class template. */
#endif


#endif /* __gen_nsIINIParser_h__ */
