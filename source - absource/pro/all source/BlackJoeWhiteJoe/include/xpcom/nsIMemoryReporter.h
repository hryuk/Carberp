/*
 * DO NOT EDIT.  THIS FILE IS GENERATED FROM e:/builds/moz2_slave/mozilla-1.9.1-win32-xulrunner/build/xpcom/base/nsIMemoryReporter.idl
 */

#ifndef __gen_nsIMemoryReporter_h__
#define __gen_nsIMemoryReporter_h__


#ifndef __gen_nsISupports_h__
#include "nsISupports.h"
#endif

/* For IDL files that don't want to include root IDL files. */
#ifndef NS_NO_VTABLE
#define NS_NO_VTABLE
#endif
class nsISimpleEnumerator; /* forward declaration */


/* starting interface:    nsIMemoryReporter */
#define NS_IMEMORYREPORTER_IID_STR "d298b942-3e66-4cd3-9ff5-46abc69147a7"

#define NS_IMEMORYREPORTER_IID \
  {0xd298b942, 0x3e66, 0x4cd3, \
    { 0x9f, 0xf5, 0x46, 0xab, 0xc6, 0x91, 0x47, 0xa7 }}

class NS_NO_VTABLE NS_SCRIPTABLE nsIMemoryReporter : public nsISupports {
 public: 

  NS_DECLARE_STATIC_IID_ACCESSOR(NS_IMEMORYREPORTER_IID)

  /* readonly attribute string path; */
  NS_SCRIPTABLE NS_IMETHOD GetPath(char * *aPath) = 0;

  /* readonly attribute string description; */
  NS_SCRIPTABLE NS_IMETHOD GetDescription(char * *aDescription) = 0;

  /* readonly attribute long long memoryUsed; */
  NS_SCRIPTABLE NS_IMETHOD GetMemoryUsed(PRInt64 *aMemoryUsed) = 0;

};

  NS_DEFINE_STATIC_IID_ACCESSOR(nsIMemoryReporter, NS_IMEMORYREPORTER_IID)

/* Use this macro when declaring classes that implement this interface. */
#define NS_DECL_NSIMEMORYREPORTER \
  NS_SCRIPTABLE NS_IMETHOD GetPath(char * *aPath); \
  NS_SCRIPTABLE NS_IMETHOD GetDescription(char * *aDescription); \
  NS_SCRIPTABLE NS_IMETHOD GetMemoryUsed(PRInt64 *aMemoryUsed); 

/* Use this macro to declare functions that forward the behavior of this interface to another object. */
#define NS_FORWARD_NSIMEMORYREPORTER(_to) \
  NS_SCRIPTABLE NS_IMETHOD GetPath(char * *aPath) { return _to GetPath(aPath); } \
  NS_SCRIPTABLE NS_IMETHOD GetDescription(char * *aDescription) { return _to GetDescription(aDescription); } \
  NS_SCRIPTABLE NS_IMETHOD GetMemoryUsed(PRInt64 *aMemoryUsed) { return _to GetMemoryUsed(aMemoryUsed); } 

/* Use this macro to declare functions that forward the behavior of this interface to another object in a safe way. */
#define NS_FORWARD_SAFE_NSIMEMORYREPORTER(_to) \
  NS_SCRIPTABLE NS_IMETHOD GetPath(char * *aPath) { return !_to ? NS_ERROR_NULL_POINTER : _to->GetPath(aPath); } \
  NS_SCRIPTABLE NS_IMETHOD GetDescription(char * *aDescription) { return !_to ? NS_ERROR_NULL_POINTER : _to->GetDescription(aDescription); } \
  NS_SCRIPTABLE NS_IMETHOD GetMemoryUsed(PRInt64 *aMemoryUsed) { return !_to ? NS_ERROR_NULL_POINTER : _to->GetMemoryUsed(aMemoryUsed); } 

#if 0
/* Use the code below as a template for the implementation class for this interface. */

/* Header file */
class nsMemoryReporter : public nsIMemoryReporter
{
public:
  NS_DECL_ISUPPORTS
  NS_DECL_NSIMEMORYREPORTER

  nsMemoryReporter();

private:
  ~nsMemoryReporter();

protected:
  /* additional members */
};

/* Implementation file */
NS_IMPL_ISUPPORTS1(nsMemoryReporter, nsIMemoryReporter)

nsMemoryReporter::nsMemoryReporter()
{
  /* member initializers and constructor code */
}

nsMemoryReporter::~nsMemoryReporter()
{
  /* destructor code */
}

/* readonly attribute string path; */
NS_IMETHODIMP nsMemoryReporter::GetPath(char * *aPath)
{
    return NS_ERROR_NOT_IMPLEMENTED;
}

/* readonly attribute string description; */
NS_IMETHODIMP nsMemoryReporter::GetDescription(char * *aDescription)
{
    return NS_ERROR_NOT_IMPLEMENTED;
}

/* readonly attribute long long memoryUsed; */
NS_IMETHODIMP nsMemoryReporter::GetMemoryUsed(PRInt64 *aMemoryUsed)
{
    return NS_ERROR_NOT_IMPLEMENTED;
}

/* End of implementation class template. */
#endif


/* starting interface:    nsIMemoryReporterManager */
#define NS_IMEMORYREPORTERMANAGER_IID_STR "63fc8fbd-509b-4fdb-93b4-2e6caeeddab1"

#define NS_IMEMORYREPORTERMANAGER_IID \
  {0x63fc8fbd, 0x509b, 0x4fdb, \
    { 0x93, 0xb4, 0x2e, 0x6c, 0xae, 0xed, 0xda, 0xb1 }}

class NS_NO_VTABLE NS_SCRIPTABLE nsIMemoryReporterManager : public nsISupports {
 public: 

  NS_DECLARE_STATIC_IID_ACCESSOR(NS_IMEMORYREPORTERMANAGER_IID)

  /* nsISimpleEnumerator enumerateReporters (); */
  NS_SCRIPTABLE NS_IMETHOD EnumerateReporters(nsISimpleEnumerator **_retval NS_OUTPARAM) = 0;

  /* void registerReporter (in nsIMemoryReporter reporter); */
  NS_SCRIPTABLE NS_IMETHOD RegisterReporter(nsIMemoryReporter *reporter) = 0;

  /* void unregisterReporter (in nsIMemoryReporter reporter); */
  NS_SCRIPTABLE NS_IMETHOD UnregisterReporter(nsIMemoryReporter *reporter) = 0;

};

  NS_DEFINE_STATIC_IID_ACCESSOR(nsIMemoryReporterManager, NS_IMEMORYREPORTERMANAGER_IID)

/* Use this macro when declaring classes that implement this interface. */
#define NS_DECL_NSIMEMORYREPORTERMANAGER \
  NS_SCRIPTABLE NS_IMETHOD EnumerateReporters(nsISimpleEnumerator **_retval NS_OUTPARAM); \
  NS_SCRIPTABLE NS_IMETHOD RegisterReporter(nsIMemoryReporter *reporter); \
  NS_SCRIPTABLE NS_IMETHOD UnregisterReporter(nsIMemoryReporter *reporter); 

/* Use this macro to declare functions that forward the behavior of this interface to another object. */
#define NS_FORWARD_NSIMEMORYREPORTERMANAGER(_to) \
  NS_SCRIPTABLE NS_IMETHOD EnumerateReporters(nsISimpleEnumerator **_retval NS_OUTPARAM) { return _to EnumerateReporters(_retval); } \
  NS_SCRIPTABLE NS_IMETHOD RegisterReporter(nsIMemoryReporter *reporter) { return _to RegisterReporter(reporter); } \
  NS_SCRIPTABLE NS_IMETHOD UnregisterReporter(nsIMemoryReporter *reporter) { return _to UnregisterReporter(reporter); } 

/* Use this macro to declare functions that forward the behavior of this interface to another object in a safe way. */
#define NS_FORWARD_SAFE_NSIMEMORYREPORTERMANAGER(_to) \
  NS_SCRIPTABLE NS_IMETHOD EnumerateReporters(nsISimpleEnumerator **_retval NS_OUTPARAM) { return !_to ? NS_ERROR_NULL_POINTER : _to->EnumerateReporters(_retval); } \
  NS_SCRIPTABLE NS_IMETHOD RegisterReporter(nsIMemoryReporter *reporter) { return !_to ? NS_ERROR_NULL_POINTER : _to->RegisterReporter(reporter); } \
  NS_SCRIPTABLE NS_IMETHOD UnregisterReporter(nsIMemoryReporter *reporter) { return !_to ? NS_ERROR_NULL_POINTER : _to->UnregisterReporter(reporter); } 

#if 0
/* Use the code below as a template for the implementation class for this interface. */

/* Header file */
class nsMemoryReporterManager : public nsIMemoryReporterManager
{
public:
  NS_DECL_ISUPPORTS
  NS_DECL_NSIMEMORYREPORTERMANAGER

  nsMemoryReporterManager();

private:
  ~nsMemoryReporterManager();

protected:
  /* additional members */
};

/* Implementation file */
NS_IMPL_ISUPPORTS1(nsMemoryReporterManager, nsIMemoryReporterManager)

nsMemoryReporterManager::nsMemoryReporterManager()
{
  /* member initializers and constructor code */
}

nsMemoryReporterManager::~nsMemoryReporterManager()
{
  /* destructor code */
}

/* nsISimpleEnumerator enumerateReporters (); */
NS_IMETHODIMP nsMemoryReporterManager::EnumerateReporters(nsISimpleEnumerator **_retval NS_OUTPARAM)
{
    return NS_ERROR_NOT_IMPLEMENTED;
}

/* void registerReporter (in nsIMemoryReporter reporter); */
NS_IMETHODIMP nsMemoryReporterManager::RegisterReporter(nsIMemoryReporter *reporter)
{
    return NS_ERROR_NOT_IMPLEMENTED;
}

/* void unregisterReporter (in nsIMemoryReporter reporter); */
NS_IMETHODIMP nsMemoryReporterManager::UnregisterReporter(nsIMemoryReporter *reporter)
{
    return NS_ERROR_NOT_IMPLEMENTED;
}

/* End of implementation class template. */
#endif

#define NS_MEMORY_REPORTER_IMPLEMENT(_classname,_path,_desc,_usageFunction,_dataptr) \
    class MemoryReporter_##_classname : public nsIMemoryReporter {      \
    public:                                                             \
      NS_DECL_ISUPPORTS                                                 \
      NS_IMETHOD GetPath(char **memoryPath) { *memoryPath = strdup(_path); return NS_OK; } \
      NS_IMETHOD GetDescription(char **desc) { *desc = strdup(_desc); return NS_OK; } \
      NS_IMETHOD GetMemoryUsed(PRInt64 *memoryUsed) { *memoryUsed = _usageFunction(_dataptr); return NS_OK; } \
    };                                                                  \
    NS_IMPL_ISUPPORTS1(MemoryReporter_##_classname, nsIMemoryReporter)
#define NS_MEMORY_REPORTER_NAME(_classname)  MemoryReporter_##_classname
NS_COM nsresult NS_RegisterMemoryReporter (nsIMemoryReporter *reporter);
NS_COM nsresult NS_UnregisterMemoryReporter (nsIMemoryReporter *reporter);

#endif /* __gen_nsIMemoryReporter_h__ */
