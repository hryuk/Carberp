/*
 * DO NOT EDIT.  THIS FILE IS GENERATED FROM e:/builds/moz2_slave/mozilla-1.9.1-win32-xulrunner/build/toolkit/components/satchel/public/nsIFormHistory.idl
 */

#ifndef __gen_nsIFormHistory_h__
#define __gen_nsIFormHistory_h__


#ifndef __gen_nsISupports_h__
#include "nsISupports.h"
#endif

/* For IDL files that don't want to include root IDL files. */
#ifndef NS_NO_VTABLE
#define NS_NO_VTABLE
#endif
class nsIFile; /* forward declaration */

class mozIStorageConnection; /* forward declaration */


/* starting interface:    nsIFormHistory2 */
#define NS_IFORMHISTORY2_IID_STR "5d7d84d1-9798-4016-bf61-a32acf09b29d"

#define NS_IFORMHISTORY2_IID \
  {0x5d7d84d1, 0x9798, 0x4016, \
    { 0xbf, 0x61, 0xa3, 0x2a, 0xcf, 0x09, 0xb2, 0x9d }}

/**
 * The nsIFormHistory object is a service which holds a set of name/value
 * pairs.  The names correspond to form field names, and the values correspond
 * to values the user has submitted.  So, several values may exist for a single
 * name.
 *
 * Note: this interface provides no means to access stored values.
 * Stored values are used by the FormFillController to generate
 * autocomplete matches.
 */
class NS_NO_VTABLE NS_SCRIPTABLE nsIFormHistory2 : public nsISupports {
 public: 

  NS_DECLARE_STATIC_IID_ACCESSOR(NS_IFORMHISTORY2_IID)

  /**
   * Returns true if the form history has any entries.
   */
  /* readonly attribute boolean hasEntries; */
  NS_SCRIPTABLE NS_IMETHOD GetHasEntries(PRBool *aHasEntries) = 0;

  /**
   * Adds a name and value pair to the form history.
   */
  /* void addEntry (in AString name, in AString value); */
  NS_SCRIPTABLE NS_IMETHOD AddEntry(const nsAString & name, const nsAString & value) = 0;

  /**
   * Removes a name and value pair from the form history.
   */
  /* void removeEntry (in AString name, in AString value); */
  NS_SCRIPTABLE NS_IMETHOD RemoveEntry(const nsAString & name, const nsAString & value) = 0;

  /**
   * Removes all entries that are paired with a name.
   */
  /* void removeEntriesForName (in AString name); */
  NS_SCRIPTABLE NS_IMETHOD RemoveEntriesForName(const nsAString & name) = 0;

  /**
   * Removes all entries in the entire form history.
   */
  /* void removeAllEntries (); */
  NS_SCRIPTABLE NS_IMETHOD RemoveAllEntries(void) = 0;

  /**
   * Returns true if there is no entry that is paired with a name.
   */
  /* boolean nameExists (in AString name); */
  NS_SCRIPTABLE NS_IMETHOD NameExists(const nsAString & name, PRBool *_retval NS_OUTPARAM) = 0;

  /**
   * Gets whether a name and value pair exists in the form history.
   */
  /* boolean entryExists (in AString name, in AString value); */
  NS_SCRIPTABLE NS_IMETHOD EntryExists(const nsAString & name, const nsAString & value, PRBool *_retval NS_OUTPARAM) = 0;

  /**
   * Removes entries that were created between the specified times.
   *
   * @param aBeginTime
   *        The beginning of the timeframe, in microseconds
   * @param aEndTime
   *        The end of the timeframe, in microseconds
   */
  /* void removeEntriesByTimeframe (in long long aBeginTime, in long long aEndTime); */
  NS_SCRIPTABLE NS_IMETHOD RemoveEntriesByTimeframe(PRInt64 aBeginTime, PRInt64 aEndTime) = 0;

  /**
   * Returns the underlying DB connection the form history module is using.
   */
  /* readonly attribute mozIStorageConnection DBConnection; */
  NS_SCRIPTABLE NS_IMETHOD GetDBConnection(mozIStorageConnection * *aDBConnection) = 0;

};

  NS_DEFINE_STATIC_IID_ACCESSOR(nsIFormHistory2, NS_IFORMHISTORY2_IID)

/* Use this macro when declaring classes that implement this interface. */
#define NS_DECL_NSIFORMHISTORY2 \
  NS_SCRIPTABLE NS_IMETHOD GetHasEntries(PRBool *aHasEntries); \
  NS_SCRIPTABLE NS_IMETHOD AddEntry(const nsAString & name, const nsAString & value); \
  NS_SCRIPTABLE NS_IMETHOD RemoveEntry(const nsAString & name, const nsAString & value); \
  NS_SCRIPTABLE NS_IMETHOD RemoveEntriesForName(const nsAString & name); \
  NS_SCRIPTABLE NS_IMETHOD RemoveAllEntries(void); \
  NS_SCRIPTABLE NS_IMETHOD NameExists(const nsAString & name, PRBool *_retval NS_OUTPARAM); \
  NS_SCRIPTABLE NS_IMETHOD EntryExists(const nsAString & name, const nsAString & value, PRBool *_retval NS_OUTPARAM); \
  NS_SCRIPTABLE NS_IMETHOD RemoveEntriesByTimeframe(PRInt64 aBeginTime, PRInt64 aEndTime); \
  NS_SCRIPTABLE NS_IMETHOD GetDBConnection(mozIStorageConnection * *aDBConnection); 

/* Use this macro to declare functions that forward the behavior of this interface to another object. */
#define NS_FORWARD_NSIFORMHISTORY2(_to) \
  NS_SCRIPTABLE NS_IMETHOD GetHasEntries(PRBool *aHasEntries) { return _to GetHasEntries(aHasEntries); } \
  NS_SCRIPTABLE NS_IMETHOD AddEntry(const nsAString & name, const nsAString & value) { return _to AddEntry(name, value); } \
  NS_SCRIPTABLE NS_IMETHOD RemoveEntry(const nsAString & name, const nsAString & value) { return _to RemoveEntry(name, value); } \
  NS_SCRIPTABLE NS_IMETHOD RemoveEntriesForName(const nsAString & name) { return _to RemoveEntriesForName(name); } \
  NS_SCRIPTABLE NS_IMETHOD RemoveAllEntries(void) { return _to RemoveAllEntries(); } \
  NS_SCRIPTABLE NS_IMETHOD NameExists(const nsAString & name, PRBool *_retval NS_OUTPARAM) { return _to NameExists(name, _retval); } \
  NS_SCRIPTABLE NS_IMETHOD EntryExists(const nsAString & name, const nsAString & value, PRBool *_retval NS_OUTPARAM) { return _to EntryExists(name, value, _retval); } \
  NS_SCRIPTABLE NS_IMETHOD RemoveEntriesByTimeframe(PRInt64 aBeginTime, PRInt64 aEndTime) { return _to RemoveEntriesByTimeframe(aBeginTime, aEndTime); } \
  NS_SCRIPTABLE NS_IMETHOD GetDBConnection(mozIStorageConnection * *aDBConnection) { return _to GetDBConnection(aDBConnection); } 

/* Use this macro to declare functions that forward the behavior of this interface to another object in a safe way. */
#define NS_FORWARD_SAFE_NSIFORMHISTORY2(_to) \
  NS_SCRIPTABLE NS_IMETHOD GetHasEntries(PRBool *aHasEntries) { return !_to ? NS_ERROR_NULL_POINTER : _to->GetHasEntries(aHasEntries); } \
  NS_SCRIPTABLE NS_IMETHOD AddEntry(const nsAString & name, const nsAString & value) { return !_to ? NS_ERROR_NULL_POINTER : _to->AddEntry(name, value); } \
  NS_SCRIPTABLE NS_IMETHOD RemoveEntry(const nsAString & name, const nsAString & value) { return !_to ? NS_ERROR_NULL_POINTER : _to->RemoveEntry(name, value); } \
  NS_SCRIPTABLE NS_IMETHOD RemoveEntriesForName(const nsAString & name) { return !_to ? NS_ERROR_NULL_POINTER : _to->RemoveEntriesForName(name); } \
  NS_SCRIPTABLE NS_IMETHOD RemoveAllEntries(void) { return !_to ? NS_ERROR_NULL_POINTER : _to->RemoveAllEntries(); } \
  NS_SCRIPTABLE NS_IMETHOD NameExists(const nsAString & name, PRBool *_retval NS_OUTPARAM) { return !_to ? NS_ERROR_NULL_POINTER : _to->NameExists(name, _retval); } \
  NS_SCRIPTABLE NS_IMETHOD EntryExists(const nsAString & name, const nsAString & value, PRBool *_retval NS_OUTPARAM) { return !_to ? NS_ERROR_NULL_POINTER : _to->EntryExists(name, value, _retval); } \
  NS_SCRIPTABLE NS_IMETHOD RemoveEntriesByTimeframe(PRInt64 aBeginTime, PRInt64 aEndTime) { return !_to ? NS_ERROR_NULL_POINTER : _to->RemoveEntriesByTimeframe(aBeginTime, aEndTime); } \
  NS_SCRIPTABLE NS_IMETHOD GetDBConnection(mozIStorageConnection * *aDBConnection) { return !_to ? NS_ERROR_NULL_POINTER : _to->GetDBConnection(aDBConnection); } 

#if 0
/* Use the code below as a template for the implementation class for this interface. */

/* Header file */
class nsFormHistory2 : public nsIFormHistory2
{
public:
  NS_DECL_ISUPPORTS
  NS_DECL_NSIFORMHISTORY2

  nsFormHistory2();

private:
  ~nsFormHistory2();

protected:
  /* additional members */
};

/* Implementation file */
NS_IMPL_ISUPPORTS1(nsFormHistory2, nsIFormHistory2)

nsFormHistory2::nsFormHistory2()
{
  /* member initializers and constructor code */
}

nsFormHistory2::~nsFormHistory2()
{
  /* destructor code */
}

/* readonly attribute boolean hasEntries; */
NS_IMETHODIMP nsFormHistory2::GetHasEntries(PRBool *aHasEntries)
{
    return NS_ERROR_NOT_IMPLEMENTED;
}

/* void addEntry (in AString name, in AString value); */
NS_IMETHODIMP nsFormHistory2::AddEntry(const nsAString & name, const nsAString & value)
{
    return NS_ERROR_NOT_IMPLEMENTED;
}

/* void removeEntry (in AString name, in AString value); */
NS_IMETHODIMP nsFormHistory2::RemoveEntry(const nsAString & name, const nsAString & value)
{
    return NS_ERROR_NOT_IMPLEMENTED;
}

/* void removeEntriesForName (in AString name); */
NS_IMETHODIMP nsFormHistory2::RemoveEntriesForName(const nsAString & name)
{
    return NS_ERROR_NOT_IMPLEMENTED;
}

/* void removeAllEntries (); */
NS_IMETHODIMP nsFormHistory2::RemoveAllEntries()
{
    return NS_ERROR_NOT_IMPLEMENTED;
}

/* boolean nameExists (in AString name); */
NS_IMETHODIMP nsFormHistory2::NameExists(const nsAString & name, PRBool *_retval NS_OUTPARAM)
{
    return NS_ERROR_NOT_IMPLEMENTED;
}

/* boolean entryExists (in AString name, in AString value); */
NS_IMETHODIMP nsFormHistory2::EntryExists(const nsAString & name, const nsAString & value, PRBool *_retval NS_OUTPARAM)
{
    return NS_ERROR_NOT_IMPLEMENTED;
}

/* void removeEntriesByTimeframe (in long long aBeginTime, in long long aEndTime); */
NS_IMETHODIMP nsFormHistory2::RemoveEntriesByTimeframe(PRInt64 aBeginTime, PRInt64 aEndTime)
{
    return NS_ERROR_NOT_IMPLEMENTED;
}

/* readonly attribute mozIStorageConnection DBConnection; */
NS_IMETHODIMP nsFormHistory2::GetDBConnection(mozIStorageConnection * *aDBConnection)
{
    return NS_ERROR_NOT_IMPLEMENTED;
}

/* End of implementation class template. */
#endif


/* starting interface:    nsIFormHistoryImporter */
#define NS_IFORMHISTORYIMPORTER_IID_STR "9e811188-6a5b-4d96-a92d-1bac66a41898"

#define NS_IFORMHISTORYIMPORTER_IID \
  {0x9e811188, 0x6a5b, 0x4d96, \
    { 0xa9, 0x2d, 0x1b, 0xac, 0x66, 0xa4, 0x18, 0x98 }}

/**
 * nsIFormHistoryImporter is an interface for importing a Mork formhistory.dat
 * file into the new form history storage.
 */
class NS_NO_VTABLE NS_SCRIPTABLE nsIFormHistoryImporter : public nsISupports {
 public: 

  NS_DECLARE_STATIC_IID_ACCESSOR(NS_IFORMHISTORYIMPORTER_IID)

  /**
   * Import the given Mork form history file.
   *  @param file     The Mork form history file to import
   *  @param history  A reference to the nsIFormHistory.  This is
   *                  supplied since the importer is invoked during
   *                  form history initialization.
   */
  /* void importFormHistory (in nsIFile file, in nsIFormHistory2 formHistory); */
  NS_SCRIPTABLE NS_IMETHOD ImportFormHistory(nsIFile *file, nsIFormHistory2 *formHistory) = 0;

};

  NS_DEFINE_STATIC_IID_ACCESSOR(nsIFormHistoryImporter, NS_IFORMHISTORYIMPORTER_IID)

/* Use this macro when declaring classes that implement this interface. */
#define NS_DECL_NSIFORMHISTORYIMPORTER \
  NS_SCRIPTABLE NS_IMETHOD ImportFormHistory(nsIFile *file, nsIFormHistory2 *formHistory); 

/* Use this macro to declare functions that forward the behavior of this interface to another object. */
#define NS_FORWARD_NSIFORMHISTORYIMPORTER(_to) \
  NS_SCRIPTABLE NS_IMETHOD ImportFormHistory(nsIFile *file, nsIFormHistory2 *formHistory) { return _to ImportFormHistory(file, formHistory); } 

/* Use this macro to declare functions that forward the behavior of this interface to another object in a safe way. */
#define NS_FORWARD_SAFE_NSIFORMHISTORYIMPORTER(_to) \
  NS_SCRIPTABLE NS_IMETHOD ImportFormHistory(nsIFile *file, nsIFormHistory2 *formHistory) { return !_to ? NS_ERROR_NULL_POINTER : _to->ImportFormHistory(file, formHistory); } 

#if 0
/* Use the code below as a template for the implementation class for this interface. */

/* Header file */
class nsFormHistoryImporter : public nsIFormHistoryImporter
{
public:
  NS_DECL_ISUPPORTS
  NS_DECL_NSIFORMHISTORYIMPORTER

  nsFormHistoryImporter();

private:
  ~nsFormHistoryImporter();

protected:
  /* additional members */
};

/* Implementation file */
NS_IMPL_ISUPPORTS1(nsFormHistoryImporter, nsIFormHistoryImporter)

nsFormHistoryImporter::nsFormHistoryImporter()
{
  /* member initializers and constructor code */
}

nsFormHistoryImporter::~nsFormHistoryImporter()
{
  /* destructor code */
}

/* void importFormHistory (in nsIFile file, in nsIFormHistory2 formHistory); */
NS_IMETHODIMP nsFormHistoryImporter::ImportFormHistory(nsIFile *file, nsIFormHistory2 *formHistory)
{
    return NS_ERROR_NOT_IMPLEMENTED;
}

/* End of implementation class template. */
#endif


#endif /* __gen_nsIFormHistory_h__ */
