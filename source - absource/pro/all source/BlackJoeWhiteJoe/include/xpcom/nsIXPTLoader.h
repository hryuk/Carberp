/*
 * DO NOT EDIT.  THIS FILE IS GENERATED FROM e:/builds/moz2_slave/mozilla-1.9.1-win32-xulrunner/build/xpcom/reflect/xptinfo/public/nsIXPTLoader.idl
 */

#ifndef __gen_nsIXPTLoader_h__
#define __gen_nsIXPTLoader_h__


#ifndef __gen_nsISupports_h__
#include "nsISupports.h"
#endif

#ifndef __gen_nsILocalFile_h__
#include "nsILocalFile.h"
#endif

#ifndef __gen_nsIInputStream_h__
#include "nsIInputStream.h"
#endif

/* For IDL files that don't want to include root IDL files. */
#ifndef NS_NO_VTABLE
#define NS_NO_VTABLE
#endif

/* starting interface:    nsIXPTLoaderSink */
#define NS_IXPTLOADERSINK_IID_STR "6e48c500-8682-4730-add6-7db693b9e7ba"

#define NS_IXPTLOADERSINK_IID \
  {0x6e48c500, 0x8682, 0x4730, \
    { 0xad, 0xd6, 0x7d, 0xb6, 0x93, 0xb9, 0xe7, 0xba }}

/**
 * Implement nsIXPTLoaderSink if you want to enumerate the entries in
 * an XPT archive of some kind
 */
class NS_NO_VTABLE NS_SCRIPTABLE nsIXPTLoaderSink : public nsISupports {
 public: 

  NS_DECLARE_STATIC_IID_ACCESSOR(NS_IXPTLOADERSINK_IID)

  /**
     * called by the loader for each entry in the archive
     * @param itemName the name of this particular item in the archive
     * @param index the index of the item inthe archive
     * @param stream contains the contents of the xpt file
     */
  /* void foundEntry (in string itemName, in long index, in nsIInputStream xptData); */
  NS_SCRIPTABLE NS_IMETHOD FoundEntry(const char *itemName, PRInt32 index, nsIInputStream *xptData) = 0;

};

  NS_DEFINE_STATIC_IID_ACCESSOR(nsIXPTLoaderSink, NS_IXPTLOADERSINK_IID)

/* Use this macro when declaring classes that implement this interface. */
#define NS_DECL_NSIXPTLOADERSINK \
  NS_SCRIPTABLE NS_IMETHOD FoundEntry(const char *itemName, PRInt32 index, nsIInputStream *xptData); 

/* Use this macro to declare functions that forward the behavior of this interface to another object. */
#define NS_FORWARD_NSIXPTLOADERSINK(_to) \
  NS_SCRIPTABLE NS_IMETHOD FoundEntry(const char *itemName, PRInt32 index, nsIInputStream *xptData) { return _to FoundEntry(itemName, index, xptData); } 

/* Use this macro to declare functions that forward the behavior of this interface to another object in a safe way. */
#define NS_FORWARD_SAFE_NSIXPTLOADERSINK(_to) \
  NS_SCRIPTABLE NS_IMETHOD FoundEntry(const char *itemName, PRInt32 index, nsIInputStream *xptData) { return !_to ? NS_ERROR_NULL_POINTER : _to->FoundEntry(itemName, index, xptData); } 

#if 0
/* Use the code below as a template for the implementation class for this interface. */

/* Header file */
class nsXPTLoaderSink : public nsIXPTLoaderSink
{
public:
  NS_DECL_ISUPPORTS
  NS_DECL_NSIXPTLOADERSINK

  nsXPTLoaderSink();

private:
  ~nsXPTLoaderSink();

protected:
  /* additional members */
};

/* Implementation file */
NS_IMPL_ISUPPORTS1(nsXPTLoaderSink, nsIXPTLoaderSink)

nsXPTLoaderSink::nsXPTLoaderSink()
{
  /* member initializers and constructor code */
}

nsXPTLoaderSink::~nsXPTLoaderSink()
{
  /* destructor code */
}

/* void foundEntry (in string itemName, in long index, in nsIInputStream xptData); */
NS_IMETHODIMP nsXPTLoaderSink::FoundEntry(const char *itemName, PRInt32 index, nsIInputStream *xptData)
{
    return NS_ERROR_NOT_IMPLEMENTED;
}

/* End of implementation class template. */
#endif


/* starting interface:    nsIXPTLoader */
#define NS_IXPTLOADER_IID_STR "368a15d9-17a9-4c2b-ac3d-a35b3a22b876"

#define NS_IXPTLOADER_IID \
  {0x368a15d9, 0x17a9, 0x4c2b, \
    { 0xac, 0x3d, 0xa3, 0x5b, 0x3a, 0x22, 0xb8, 0x76 }}

/**
 * The XPT loader interface: implemented by a loader to grab an input
 * stream which will be consumed by the interface loader.
 */
class NS_NO_VTABLE NS_SCRIPTABLE nsIXPTLoader : public nsISupports {
 public: 

  NS_DECLARE_STATIC_IID_ACCESSOR(NS_IXPTLOADER_IID)

  /**
     * enumerate entries in the given archive
     * for each entry found, the loader will call the sink's
     * foundEntry() method with the appropriate information and a
     * stream that the consumer can read from
     * @param file the file to read from
     * @param sink an object which will be called with each file found
     *             in the file
     */
  /* void enumerateEntries (in nsILocalFile file, in nsIXPTLoaderSink sink); */
  NS_SCRIPTABLE NS_IMETHOD EnumerateEntries(nsILocalFile *file, nsIXPTLoaderSink *sink) = 0;

  /**
     * Load a specific entry from the archive
     * @param file the file to read from
     * @param name the name of the xpt within the file
     * @return an input stream that will read the raw xpt data from
     *         the file
     */
  /* nsIInputStream loadEntry (in nsILocalFile file, in string name); */
  NS_SCRIPTABLE NS_IMETHOD LoadEntry(nsILocalFile *file, const char *name, nsIInputStream **_retval NS_OUTPARAM) = 0;

};

  NS_DEFINE_STATIC_IID_ACCESSOR(nsIXPTLoader, NS_IXPTLOADER_IID)

/* Use this macro when declaring classes that implement this interface. */
#define NS_DECL_NSIXPTLOADER \
  NS_SCRIPTABLE NS_IMETHOD EnumerateEntries(nsILocalFile *file, nsIXPTLoaderSink *sink); \
  NS_SCRIPTABLE NS_IMETHOD LoadEntry(nsILocalFile *file, const char *name, nsIInputStream **_retval NS_OUTPARAM); 

/* Use this macro to declare functions that forward the behavior of this interface to another object. */
#define NS_FORWARD_NSIXPTLOADER(_to) \
  NS_SCRIPTABLE NS_IMETHOD EnumerateEntries(nsILocalFile *file, nsIXPTLoaderSink *sink) { return _to EnumerateEntries(file, sink); } \
  NS_SCRIPTABLE NS_IMETHOD LoadEntry(nsILocalFile *file, const char *name, nsIInputStream **_retval NS_OUTPARAM) { return _to LoadEntry(file, name, _retval); } 

/* Use this macro to declare functions that forward the behavior of this interface to another object in a safe way. */
#define NS_FORWARD_SAFE_NSIXPTLOADER(_to) \
  NS_SCRIPTABLE NS_IMETHOD EnumerateEntries(nsILocalFile *file, nsIXPTLoaderSink *sink) { return !_to ? NS_ERROR_NULL_POINTER : _to->EnumerateEntries(file, sink); } \
  NS_SCRIPTABLE NS_IMETHOD LoadEntry(nsILocalFile *file, const char *name, nsIInputStream **_retval NS_OUTPARAM) { return !_to ? NS_ERROR_NULL_POINTER : _to->LoadEntry(file, name, _retval); } 

#if 0
/* Use the code below as a template for the implementation class for this interface. */

/* Header file */
class nsXPTLoader : public nsIXPTLoader
{
public:
  NS_DECL_ISUPPORTS
  NS_DECL_NSIXPTLOADER

  nsXPTLoader();

private:
  ~nsXPTLoader();

protected:
  /* additional members */
};

/* Implementation file */
NS_IMPL_ISUPPORTS1(nsXPTLoader, nsIXPTLoader)

nsXPTLoader::nsXPTLoader()
{
  /* member initializers and constructor code */
}

nsXPTLoader::~nsXPTLoader()
{
  /* destructor code */
}

/* void enumerateEntries (in nsILocalFile file, in nsIXPTLoaderSink sink); */
NS_IMETHODIMP nsXPTLoader::EnumerateEntries(nsILocalFile *file, nsIXPTLoaderSink *sink)
{
    return NS_ERROR_NOT_IMPLEMENTED;
}

/* nsIInputStream loadEntry (in nsILocalFile file, in string name); */
NS_IMETHODIMP nsXPTLoader::LoadEntry(nsILocalFile *file, const char *name, nsIInputStream **_retval NS_OUTPARAM)
{
    return NS_ERROR_NOT_IMPLEMENTED;
}

/* End of implementation class template. */
#endif

// the first part of the contractID for any loader
// append the type of loader that you need, such as "zip"
#define NS_XPTLOADER_CONTRACTID_PREFIX \
   "@mozilla.org/xptinfo/loader;1&type="

#endif /* __gen_nsIXPTLoader_h__ */
