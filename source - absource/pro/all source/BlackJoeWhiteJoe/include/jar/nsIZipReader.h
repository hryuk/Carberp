/*
 * DO NOT EDIT.  THIS FILE IS GENERATED FROM e:/builds/moz2_slave/mozilla-1.9.1-win32-xulrunner/build/modules/libjar/nsIZipReader.idl
 */

#ifndef __gen_nsIZipReader_h__
#define __gen_nsIZipReader_h__


#ifndef __gen_nsISupports_h__
#include "nsISupports.h"
#endif

/* For IDL files that don't want to include root IDL files. */
#ifndef NS_NO_VTABLE
#define NS_NO_VTABLE
#endif
class nsIUTF8StringEnumerator; /* forward declaration */

class nsIInputStream; /* forward declaration */

class nsIFile; /* forward declaration */


/* starting interface:    nsIZipEntry */
#define NS_IZIPENTRY_IID_STR "e1c028bc-c478-11da-95a8-00e08161165f"

#define NS_IZIPENTRY_IID \
  {0xe1c028bc, 0xc478, 0x11da, \
    { 0x95, 0xa8, 0x00, 0xe0, 0x81, 0x61, 0x16, 0x5f }}

class NS_NO_VTABLE NS_SCRIPTABLE nsIZipEntry : public nsISupports {
 public: 

  NS_DECLARE_STATIC_IID_ACCESSOR(NS_IZIPENTRY_IID)

  /**
     * The type of compression used for the item.  The possible values and
     * their meanings are defined in the zip file specification at
     * http://www.pkware.com/business_and_developers/developer/appnote/
     */
  /* readonly attribute unsigned short compression; */
  NS_SCRIPTABLE NS_IMETHOD GetCompression(PRUint16 *aCompression) = 0;

  /**
     * The compressed size of the data in the item.
     */
  /* readonly attribute unsigned long size; */
  NS_SCRIPTABLE NS_IMETHOD GetSize(PRUint32 *aSize) = 0;

  /**
     * The uncompressed size of the data in the item.
     */
  /* readonly attribute unsigned long realSize; */
  NS_SCRIPTABLE NS_IMETHOD GetRealSize(PRUint32 *aRealSize) = 0;

  /**
     * The CRC-32 hash of the file in the entry.
     */
  /* readonly attribute unsigned long CRC32; */
  NS_SCRIPTABLE NS_IMETHOD GetCRC32(PRUint32 *aCRC32) = 0;

  /**
     * True if the name of the entry ends with '/' and false otherwise.
     */
  /* readonly attribute boolean isDirectory; */
  NS_SCRIPTABLE NS_IMETHOD GetIsDirectory(PRBool *aIsDirectory) = 0;

  /**
     * The time at which this item was last modified.
     */
  /* readonly attribute PRTime lastModifiedTime; */
  NS_SCRIPTABLE NS_IMETHOD GetLastModifiedTime(PRTime *aLastModifiedTime) = 0;

  /**
     * Use this attribute to determine whether this item is an actual zip entry
     * or is one synthesized for part of a real entry's path.  A synthesized
     * entry represents a directory within the zip file which has no
     * corresponding entry within the zip file.  For example, the entry for the
     * directory foo/ in a zip containing exactly one entry for foo/bar.txt
     * is synthetic.  If the zip file contains an actual entry for a directory,
     * this attribute will be false for the nsIZipEntry for that directory.
     * It is impossible for a file to be synthetic.
     */
  /* readonly attribute boolean isSynthetic; */
  NS_SCRIPTABLE NS_IMETHOD GetIsSynthetic(PRBool *aIsSynthetic) = 0;

};

  NS_DEFINE_STATIC_IID_ACCESSOR(nsIZipEntry, NS_IZIPENTRY_IID)

/* Use this macro when declaring classes that implement this interface. */
#define NS_DECL_NSIZIPENTRY \
  NS_SCRIPTABLE NS_IMETHOD GetCompression(PRUint16 *aCompression); \
  NS_SCRIPTABLE NS_IMETHOD GetSize(PRUint32 *aSize); \
  NS_SCRIPTABLE NS_IMETHOD GetRealSize(PRUint32 *aRealSize); \
  NS_SCRIPTABLE NS_IMETHOD GetCRC32(PRUint32 *aCRC32); \
  NS_SCRIPTABLE NS_IMETHOD GetIsDirectory(PRBool *aIsDirectory); \
  NS_SCRIPTABLE NS_IMETHOD GetLastModifiedTime(PRTime *aLastModifiedTime); \
  NS_SCRIPTABLE NS_IMETHOD GetIsSynthetic(PRBool *aIsSynthetic); 

/* Use this macro to declare functions that forward the behavior of this interface to another object. */
#define NS_FORWARD_NSIZIPENTRY(_to) \
  NS_SCRIPTABLE NS_IMETHOD GetCompression(PRUint16 *aCompression) { return _to GetCompression(aCompression); } \
  NS_SCRIPTABLE NS_IMETHOD GetSize(PRUint32 *aSize) { return _to GetSize(aSize); } \
  NS_SCRIPTABLE NS_IMETHOD GetRealSize(PRUint32 *aRealSize) { return _to GetRealSize(aRealSize); } \
  NS_SCRIPTABLE NS_IMETHOD GetCRC32(PRUint32 *aCRC32) { return _to GetCRC32(aCRC32); } \
  NS_SCRIPTABLE NS_IMETHOD GetIsDirectory(PRBool *aIsDirectory) { return _to GetIsDirectory(aIsDirectory); } \
  NS_SCRIPTABLE NS_IMETHOD GetLastModifiedTime(PRTime *aLastModifiedTime) { return _to GetLastModifiedTime(aLastModifiedTime); } \
  NS_SCRIPTABLE NS_IMETHOD GetIsSynthetic(PRBool *aIsSynthetic) { return _to GetIsSynthetic(aIsSynthetic); } 

/* Use this macro to declare functions that forward the behavior of this interface to another object in a safe way. */
#define NS_FORWARD_SAFE_NSIZIPENTRY(_to) \
  NS_SCRIPTABLE NS_IMETHOD GetCompression(PRUint16 *aCompression) { return !_to ? NS_ERROR_NULL_POINTER : _to->GetCompression(aCompression); } \
  NS_SCRIPTABLE NS_IMETHOD GetSize(PRUint32 *aSize) { return !_to ? NS_ERROR_NULL_POINTER : _to->GetSize(aSize); } \
  NS_SCRIPTABLE NS_IMETHOD GetRealSize(PRUint32 *aRealSize) { return !_to ? NS_ERROR_NULL_POINTER : _to->GetRealSize(aRealSize); } \
  NS_SCRIPTABLE NS_IMETHOD GetCRC32(PRUint32 *aCRC32) { return !_to ? NS_ERROR_NULL_POINTER : _to->GetCRC32(aCRC32); } \
  NS_SCRIPTABLE NS_IMETHOD GetIsDirectory(PRBool *aIsDirectory) { return !_to ? NS_ERROR_NULL_POINTER : _to->GetIsDirectory(aIsDirectory); } \
  NS_SCRIPTABLE NS_IMETHOD GetLastModifiedTime(PRTime *aLastModifiedTime) { return !_to ? NS_ERROR_NULL_POINTER : _to->GetLastModifiedTime(aLastModifiedTime); } \
  NS_SCRIPTABLE NS_IMETHOD GetIsSynthetic(PRBool *aIsSynthetic) { return !_to ? NS_ERROR_NULL_POINTER : _to->GetIsSynthetic(aIsSynthetic); } 

#if 0
/* Use the code below as a template for the implementation class for this interface. */

/* Header file */
class nsZipEntry : public nsIZipEntry
{
public:
  NS_DECL_ISUPPORTS
  NS_DECL_NSIZIPENTRY

  nsZipEntry();

private:
  ~nsZipEntry();

protected:
  /* additional members */
};

/* Implementation file */
NS_IMPL_ISUPPORTS1(nsZipEntry, nsIZipEntry)

nsZipEntry::nsZipEntry()
{
  /* member initializers and constructor code */
}

nsZipEntry::~nsZipEntry()
{
  /* destructor code */
}

/* readonly attribute unsigned short compression; */
NS_IMETHODIMP nsZipEntry::GetCompression(PRUint16 *aCompression)
{
    return NS_ERROR_NOT_IMPLEMENTED;
}

/* readonly attribute unsigned long size; */
NS_IMETHODIMP nsZipEntry::GetSize(PRUint32 *aSize)
{
    return NS_ERROR_NOT_IMPLEMENTED;
}

/* readonly attribute unsigned long realSize; */
NS_IMETHODIMP nsZipEntry::GetRealSize(PRUint32 *aRealSize)
{
    return NS_ERROR_NOT_IMPLEMENTED;
}

/* readonly attribute unsigned long CRC32; */
NS_IMETHODIMP nsZipEntry::GetCRC32(PRUint32 *aCRC32)
{
    return NS_ERROR_NOT_IMPLEMENTED;
}

/* readonly attribute boolean isDirectory; */
NS_IMETHODIMP nsZipEntry::GetIsDirectory(PRBool *aIsDirectory)
{
    return NS_ERROR_NOT_IMPLEMENTED;
}

/* readonly attribute PRTime lastModifiedTime; */
NS_IMETHODIMP nsZipEntry::GetLastModifiedTime(PRTime *aLastModifiedTime)
{
    return NS_ERROR_NOT_IMPLEMENTED;
}

/* readonly attribute boolean isSynthetic; */
NS_IMETHODIMP nsZipEntry::GetIsSynthetic(PRBool *aIsSynthetic)
{
    return NS_ERROR_NOT_IMPLEMENTED;
}

/* End of implementation class template. */
#endif


/* starting interface:    nsIZipReader */
#define NS_IZIPREADER_IID_STR "5cce7f53-23b3-47f8-be05-122c0ba703fd"

#define NS_IZIPREADER_IID \
  {0x5cce7f53, 0x23b3, 0x47f8, \
    { 0xbe, 0x05, 0x12, 0x2c, 0x0b, 0xa7, 0x03, 0xfd }}

class NS_NO_VTABLE NS_SCRIPTABLE nsIZipReader : public nsISupports {
 public: 

  NS_DECLARE_STATIC_IID_ACCESSOR(NS_IZIPREADER_IID)

  /**
     * Opens a zip file for reading.
     * It is allowed to open with another file, 
     * but it needs to be closed first with close().
     */
  /* void open (in nsIFile zipFile); */
  NS_SCRIPTABLE NS_IMETHOD Open(nsIFile *zipFile) = 0;

  /**
     * The file that represents the zip with which this zip reader was
     * initialized.
     */
  /* readonly attribute nsIFile file; */
  NS_SCRIPTABLE NS_IMETHOD GetFile(nsIFile * *aFile) = 0;

  /**
     * Closes a zip reader. Subsequent attempts to extract files or read from
     * its input stream will result in an error.
     */
  /* void close (); */
  NS_SCRIPTABLE NS_IMETHOD Close(void) = 0;

  /**
     * Tests the integrity of the archive by performing a CRC check 
     * on each item expanded into memory.  If an entry is specified
     * the integrity of only that item is tested.  If NULL is passed 
     * in the integrity of all items in the archive are tested.  
     */
  /* void test (in string aEntryName); */
  NS_SCRIPTABLE NS_IMETHOD Test(const char *aEntryName) = 0;

  /**
     * Extracts a zip entry into a local file specified by outFile.
     * The entry must be stored in the zip in either uncompressed or
     * DEFLATE-compressed format for the extraction to be successful.
     * If the entry is a directory, the directory will be extracted
     * non-recursively.
     */
  /* void extract (in string zipEntry, in nsIFile outFile); */
  NS_SCRIPTABLE NS_IMETHOD Extract(const char *zipEntry, nsIFile *outFile) = 0;

  /**
     * Returns a nsIZipEntry describing a specified zip entry.
     */
  /* nsIZipEntry getEntry (in string zipEntry); */
  NS_SCRIPTABLE NS_IMETHOD GetEntry(const char *zipEntry, nsIZipEntry **_retval NS_OUTPARAM) = 0;

  /**
     * Checks whether the zipfile contains an entry specified by entryName.
     */
  /* boolean hasEntry (in AUTF8String zipEntry); */
  NS_SCRIPTABLE NS_IMETHOD HasEntry(const nsACString & zipEntry, PRBool *_retval NS_OUTPARAM) = 0;

  /**
     * Returns a string enumerator containing the matching entry names.
     *
     * @param aPattern
     *   A globbing pattern used to find matching names in the zip file.
     *   Set this parameter to null to get all entries; otherwise, use the
     *   following syntax:
     *
     *   o * matches anything
     *   o ? matches one character
     *   o $ matches the end of the string
     *   o [abc] matches one occurrence of a, b, or c. 
     *   o [^az] matches any character except a or z.  Between brackets,
     *           the only characters that must be escaped are \ and ].  
     *   o [a-z] matches any character between a and z, inclusive.  
     *           The a and z characters must be alphanumeric ASCII characters.
     *           If one is upper case and one is lower case, then the ASCII
     *           non-alphanumeric characters between Z and a will be in range.
     *   o [^a-z] matches any character except those between a and z, inclusive.
     *            These forms cannot be combined, e.g [a-gp-z] does not work.
     *   o yes~no returns matches to the pattern 'yes' that do not also match
     *            the pattern 'no'.  This may be used to filter the results
     *            of one pattern to remove all matches of a second pattern.
     *            Only the outer-most pattern may use this, and at most once.
     *            For example: *~abc will match any string except abc .
     *   o (foo|bar) will match either the pattern foo or the pattern bar.
     *            At least one pipe and two inner patterns are required. 
     *            More are allowed. These inner patterns may NOT use the 
     *            'yes~no' syntax described immediately above, and may not 
     *            contain patterns of this same (foo|bar) form.
     *   o \ will escape a special character.  To treat special characters as
     *            ordinary matching characters, escaping is required for all
     *            special characters, unless otherwise specified above.
     *   o All other characters match case-sensitively.
     *
     *   An aPattern not conforming to this syntax has undefined behavior.
     *
     * @throws NS_ERROR_ILLEGAL_VALUE on many but not all invalid aPattern
     *                                values.
     */
  /* nsIUTF8StringEnumerator findEntries (in string aPattern); */
  NS_SCRIPTABLE NS_IMETHOD FindEntries(const char *aPattern, nsIUTF8StringEnumerator **_retval NS_OUTPARAM) = 0;

  /**
     * Returns an input stream containing the contents of the specified zip
     * entry.
     * @param zipEntry the name of the entry to open the stream from
     */
  /* nsIInputStream getInputStream (in string zipEntry); */
  NS_SCRIPTABLE NS_IMETHOD GetInputStream(const char *zipEntry, nsIInputStream **_retval NS_OUTPARAM) = 0;

  /**
     * Returns an input stream containing the contents of the specified zip
     * entry. If the entry refers to a directory (ends with '/'), a directory stream 
     * is opened, otherwise the contents of the file entry is returned.
     * @param aJarSpec the Spec of the URI for the JAR (only used for directory streams)
     * @param zipEntry the name of the entry to open the stream from
     */
  /* nsIInputStream getInputStreamWithSpec (in AUTF8String aJarSpec, in string zipEntry); */
  NS_SCRIPTABLE NS_IMETHOD GetInputStreamWithSpec(const nsACString & aJarSpec, const char *zipEntry, nsIInputStream **_retval NS_OUTPARAM) = 0;

};

  NS_DEFINE_STATIC_IID_ACCESSOR(nsIZipReader, NS_IZIPREADER_IID)

/* Use this macro when declaring classes that implement this interface. */
#define NS_DECL_NSIZIPREADER \
  NS_SCRIPTABLE NS_IMETHOD Open(nsIFile *zipFile); \
  NS_SCRIPTABLE NS_IMETHOD GetFile(nsIFile * *aFile); \
  NS_SCRIPTABLE NS_IMETHOD Close(void); \
  NS_SCRIPTABLE NS_IMETHOD Test(const char *aEntryName); \
  NS_SCRIPTABLE NS_IMETHOD Extract(const char *zipEntry, nsIFile *outFile); \
  NS_SCRIPTABLE NS_IMETHOD GetEntry(const char *zipEntry, nsIZipEntry **_retval NS_OUTPARAM); \
  NS_SCRIPTABLE NS_IMETHOD HasEntry(const nsACString & zipEntry, PRBool *_retval NS_OUTPARAM); \
  NS_SCRIPTABLE NS_IMETHOD FindEntries(const char *aPattern, nsIUTF8StringEnumerator **_retval NS_OUTPARAM); \
  NS_SCRIPTABLE NS_IMETHOD GetInputStream(const char *zipEntry, nsIInputStream **_retval NS_OUTPARAM); \
  NS_SCRIPTABLE NS_IMETHOD GetInputStreamWithSpec(const nsACString & aJarSpec, const char *zipEntry, nsIInputStream **_retval NS_OUTPARAM); 

/* Use this macro to declare functions that forward the behavior of this interface to another object. */
#define NS_FORWARD_NSIZIPREADER(_to) \
  NS_SCRIPTABLE NS_IMETHOD Open(nsIFile *zipFile) { return _to Open(zipFile); } \
  NS_SCRIPTABLE NS_IMETHOD GetFile(nsIFile * *aFile) { return _to GetFile(aFile); } \
  NS_SCRIPTABLE NS_IMETHOD Close(void) { return _to Close(); } \
  NS_SCRIPTABLE NS_IMETHOD Test(const char *aEntryName) { return _to Test(aEntryName); } \
  NS_SCRIPTABLE NS_IMETHOD Extract(const char *zipEntry, nsIFile *outFile) { return _to Extract(zipEntry, outFile); } \
  NS_SCRIPTABLE NS_IMETHOD GetEntry(const char *zipEntry, nsIZipEntry **_retval NS_OUTPARAM) { return _to GetEntry(zipEntry, _retval); } \
  NS_SCRIPTABLE NS_IMETHOD HasEntry(const nsACString & zipEntry, PRBool *_retval NS_OUTPARAM) { return _to HasEntry(zipEntry, _retval); } \
  NS_SCRIPTABLE NS_IMETHOD FindEntries(const char *aPattern, nsIUTF8StringEnumerator **_retval NS_OUTPARAM) { return _to FindEntries(aPattern, _retval); } \
  NS_SCRIPTABLE NS_IMETHOD GetInputStream(const char *zipEntry, nsIInputStream **_retval NS_OUTPARAM) { return _to GetInputStream(zipEntry, _retval); } \
  NS_SCRIPTABLE NS_IMETHOD GetInputStreamWithSpec(const nsACString & aJarSpec, const char *zipEntry, nsIInputStream **_retval NS_OUTPARAM) { return _to GetInputStreamWithSpec(aJarSpec, zipEntry, _retval); } 

/* Use this macro to declare functions that forward the behavior of this interface to another object in a safe way. */
#define NS_FORWARD_SAFE_NSIZIPREADER(_to) \
  NS_SCRIPTABLE NS_IMETHOD Open(nsIFile *zipFile) { return !_to ? NS_ERROR_NULL_POINTER : _to->Open(zipFile); } \
  NS_SCRIPTABLE NS_IMETHOD GetFile(nsIFile * *aFile) { return !_to ? NS_ERROR_NULL_POINTER : _to->GetFile(aFile); } \
  NS_SCRIPTABLE NS_IMETHOD Close(void) { return !_to ? NS_ERROR_NULL_POINTER : _to->Close(); } \
  NS_SCRIPTABLE NS_IMETHOD Test(const char *aEntryName) { return !_to ? NS_ERROR_NULL_POINTER : _to->Test(aEntryName); } \
  NS_SCRIPTABLE NS_IMETHOD Extract(const char *zipEntry, nsIFile *outFile) { return !_to ? NS_ERROR_NULL_POINTER : _to->Extract(zipEntry, outFile); } \
  NS_SCRIPTABLE NS_IMETHOD GetEntry(const char *zipEntry, nsIZipEntry **_retval NS_OUTPARAM) { return !_to ? NS_ERROR_NULL_POINTER : _to->GetEntry(zipEntry, _retval); } \
  NS_SCRIPTABLE NS_IMETHOD HasEntry(const nsACString & zipEntry, PRBool *_retval NS_OUTPARAM) { return !_to ? NS_ERROR_NULL_POINTER : _to->HasEntry(zipEntry, _retval); } \
  NS_SCRIPTABLE NS_IMETHOD FindEntries(const char *aPattern, nsIUTF8StringEnumerator **_retval NS_OUTPARAM) { return !_to ? NS_ERROR_NULL_POINTER : _to->FindEntries(aPattern, _retval); } \
  NS_SCRIPTABLE NS_IMETHOD GetInputStream(const char *zipEntry, nsIInputStream **_retval NS_OUTPARAM) { return !_to ? NS_ERROR_NULL_POINTER : _to->GetInputStream(zipEntry, _retval); } \
  NS_SCRIPTABLE NS_IMETHOD GetInputStreamWithSpec(const nsACString & aJarSpec, const char *zipEntry, nsIInputStream **_retval NS_OUTPARAM) { return !_to ? NS_ERROR_NULL_POINTER : _to->GetInputStreamWithSpec(aJarSpec, zipEntry, _retval); } 

#if 0
/* Use the code below as a template for the implementation class for this interface. */

/* Header file */
class nsZipReader : public nsIZipReader
{
public:
  NS_DECL_ISUPPORTS
  NS_DECL_NSIZIPREADER

  nsZipReader();

private:
  ~nsZipReader();

protected:
  /* additional members */
};

/* Implementation file */
NS_IMPL_ISUPPORTS1(nsZipReader, nsIZipReader)

nsZipReader::nsZipReader()
{
  /* member initializers and constructor code */
}

nsZipReader::~nsZipReader()
{
  /* destructor code */
}

/* void open (in nsIFile zipFile); */
NS_IMETHODIMP nsZipReader::Open(nsIFile *zipFile)
{
    return NS_ERROR_NOT_IMPLEMENTED;
}

/* readonly attribute nsIFile file; */
NS_IMETHODIMP nsZipReader::GetFile(nsIFile * *aFile)
{
    return NS_ERROR_NOT_IMPLEMENTED;
}

/* void close (); */
NS_IMETHODIMP nsZipReader::Close()
{
    return NS_ERROR_NOT_IMPLEMENTED;
}

/* void test (in string aEntryName); */
NS_IMETHODIMP nsZipReader::Test(const char *aEntryName)
{
    return NS_ERROR_NOT_IMPLEMENTED;
}

/* void extract (in string zipEntry, in nsIFile outFile); */
NS_IMETHODIMP nsZipReader::Extract(const char *zipEntry, nsIFile *outFile)
{
    return NS_ERROR_NOT_IMPLEMENTED;
}

/* nsIZipEntry getEntry (in string zipEntry); */
NS_IMETHODIMP nsZipReader::GetEntry(const char *zipEntry, nsIZipEntry **_retval NS_OUTPARAM)
{
    return NS_ERROR_NOT_IMPLEMENTED;
}

/* boolean hasEntry (in AUTF8String zipEntry); */
NS_IMETHODIMP nsZipReader::HasEntry(const nsACString & zipEntry, PRBool *_retval NS_OUTPARAM)
{
    return NS_ERROR_NOT_IMPLEMENTED;
}

/* nsIUTF8StringEnumerator findEntries (in string aPattern); */
NS_IMETHODIMP nsZipReader::FindEntries(const char *aPattern, nsIUTF8StringEnumerator **_retval NS_OUTPARAM)
{
    return NS_ERROR_NOT_IMPLEMENTED;
}

/* nsIInputStream getInputStream (in string zipEntry); */
NS_IMETHODIMP nsZipReader::GetInputStream(const char *zipEntry, nsIInputStream **_retval NS_OUTPARAM)
{
    return NS_ERROR_NOT_IMPLEMENTED;
}

/* nsIInputStream getInputStreamWithSpec (in AUTF8String aJarSpec, in string zipEntry); */
NS_IMETHODIMP nsZipReader::GetInputStreamWithSpec(const nsACString & aJarSpec, const char *zipEntry, nsIInputStream **_retval NS_OUTPARAM)
{
    return NS_ERROR_NOT_IMPLEMENTED;
}

/* End of implementation class template. */
#endif


/* starting interface:    nsIZipReaderCache */
#define NS_IZIPREADERCACHE_IID_STR "52c45d86-0cc3-11d4-986e-00c04fa0cf4a"

#define NS_IZIPREADERCACHE_IID \
  {0x52c45d86, 0x0cc3, 0x11d4, \
    { 0x98, 0x6e, 0x00, 0xc0, 0x4f, 0xa0, 0xcf, 0x4a }}

class NS_NO_VTABLE NS_SCRIPTABLE nsIZipReaderCache : public nsISupports {
 public: 

  NS_DECLARE_STATIC_IID_ACCESSOR(NS_IZIPREADERCACHE_IID)

  /**
     * Initializes a new zip reader cache. 
     * @param cacheSize - the number of released entries to maintain before
     *   beginning to throw some out (note that the number of outstanding
     *   entries can be much greater than this number -- this is the count
     *   for those otherwise unused entries)
     */
  /* void init (in unsigned long cacheSize); */
  NS_SCRIPTABLE NS_IMETHOD Init(PRUint32 cacheSize) = 0;

  /**
     * Returns a (possibly shared) nsIZipReader for an nsIFile.
     *
     * If the zip reader for given file is not in the cache, a new zip reader
     * is created, initialized, and opened (see nsIZipReader::init and 
     * nsIZipReader::open). Otherwise the previously created zip reader is 
     * returned.
     *
     * @note If someone called close() on the shared nsIZipReader, this method 
     *       will return the closed zip reader.
     */
  /* nsIZipReader getZip (in nsIFile zipFile); */
  NS_SCRIPTABLE NS_IMETHOD GetZip(nsIFile *zipFile, nsIZipReader **_retval NS_OUTPARAM) = 0;

};

  NS_DEFINE_STATIC_IID_ACCESSOR(nsIZipReaderCache, NS_IZIPREADERCACHE_IID)

/* Use this macro when declaring classes that implement this interface. */
#define NS_DECL_NSIZIPREADERCACHE \
  NS_SCRIPTABLE NS_IMETHOD Init(PRUint32 cacheSize); \
  NS_SCRIPTABLE NS_IMETHOD GetZip(nsIFile *zipFile, nsIZipReader **_retval NS_OUTPARAM); 

/* Use this macro to declare functions that forward the behavior of this interface to another object. */
#define NS_FORWARD_NSIZIPREADERCACHE(_to) \
  NS_SCRIPTABLE NS_IMETHOD Init(PRUint32 cacheSize) { return _to Init(cacheSize); } \
  NS_SCRIPTABLE NS_IMETHOD GetZip(nsIFile *zipFile, nsIZipReader **_retval NS_OUTPARAM) { return _to GetZip(zipFile, _retval); } 

/* Use this macro to declare functions that forward the behavior of this interface to another object in a safe way. */
#define NS_FORWARD_SAFE_NSIZIPREADERCACHE(_to) \
  NS_SCRIPTABLE NS_IMETHOD Init(PRUint32 cacheSize) { return !_to ? NS_ERROR_NULL_POINTER : _to->Init(cacheSize); } \
  NS_SCRIPTABLE NS_IMETHOD GetZip(nsIFile *zipFile, nsIZipReader **_retval NS_OUTPARAM) { return !_to ? NS_ERROR_NULL_POINTER : _to->GetZip(zipFile, _retval); } 

#if 0
/* Use the code below as a template for the implementation class for this interface. */

/* Header file */
class nsZipReaderCache : public nsIZipReaderCache
{
public:
  NS_DECL_ISUPPORTS
  NS_DECL_NSIZIPREADERCACHE

  nsZipReaderCache();

private:
  ~nsZipReaderCache();

protected:
  /* additional members */
};

/* Implementation file */
NS_IMPL_ISUPPORTS1(nsZipReaderCache, nsIZipReaderCache)

nsZipReaderCache::nsZipReaderCache()
{
  /* member initializers and constructor code */
}

nsZipReaderCache::~nsZipReaderCache()
{
  /* destructor code */
}

/* void init (in unsigned long cacheSize); */
NS_IMETHODIMP nsZipReaderCache::Init(PRUint32 cacheSize)
{
    return NS_ERROR_NOT_IMPLEMENTED;
}

/* nsIZipReader getZip (in nsIFile zipFile); */
NS_IMETHODIMP nsZipReaderCache::GetZip(nsIFile *zipFile, nsIZipReader **_retval NS_OUTPARAM)
{
    return NS_ERROR_NOT_IMPLEMENTED;
}

/* End of implementation class template. */
#endif

#define NS_ZIPREADER_CID                             \
{ /* 7526a738-9632-11d3-8cd9-0060b0fc14a3 */         \
    0x7526a738,                                      \
    0x9632,                                          \
    0x11d3,                                          \
    {0x8c, 0xd9, 0x00, 0x60, 0xb0, 0xfc, 0x14, 0xa3} \
}
#define NS_ZIPREADERCACHE_CID                        \
{ /* 1b117e16-0cad-11d4-986e-00c04fa0cf4a */         \
    0x1b117e16,                                      \
    0x0cad,                                          \
    0x11d4,                                          \
    {0x98, 0x6e, 0x00, 0xc0, 0x4f, 0xa0, 0xcf, 0x4a} \
}

#endif /* __gen_nsIZipReader_h__ */
