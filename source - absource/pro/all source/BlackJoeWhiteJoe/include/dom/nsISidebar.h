/*
 * DO NOT EDIT.  THIS FILE IS GENERATED FROM e:/builds/moz2_slave/mozilla-1.9.1-win32-xulrunner/build/dom/public/idl/sidebar/nsISidebar.idl
 */

#ifndef __gen_nsISidebar_h__
#define __gen_nsISidebar_h__


#ifndef __gen_nsISupports_h__
#include "nsISupports.h"
#endif

/* For IDL files that don't want to include root IDL files. */
#ifndef NS_NO_VTABLE
#define NS_NO_VTABLE
#endif

/* starting interface:    nsISidebar */
#define NS_ISIDEBAR_IID_STR "67cf6231-c303-4f7e-b9b1-a0e87772ecfd"

#define NS_ISIDEBAR_IID \
  {0x67cf6231, 0xc303, 0x4f7e, \
    { 0xb9, 0xb1, 0xa0, 0xe8, 0x77, 0x72, 0xec, 0xfd }}

class NS_NO_VTABLE NS_SCRIPTABLE nsISidebar : public nsISupports {
 public: 

  NS_DECLARE_STATIC_IID_ACCESSOR(NS_ISIDEBAR_IID)

  /* void addPanel (in wstring aTitle, in string aContentURL, in string aCustomizeURL); */
  NS_SCRIPTABLE NS_IMETHOD AddPanel(const PRUnichar *aTitle, const char *aContentURL, const char *aCustomizeURL) = 0;

  /* void addPersistentPanel (in wstring aTitle, in string aContentURL, in string aCustomizeURL); */
  NS_SCRIPTABLE NS_IMETHOD AddPersistentPanel(const PRUnichar *aTitle, const char *aContentURL, const char *aCustomizeURL) = 0;

  /* void addSearchEngine (in string engineURL, in string iconURL, in wstring suggestedTitle, in wstring suggestedCategory); */
  NS_SCRIPTABLE NS_IMETHOD AddSearchEngine(const char *engineURL, const char *iconURL, const PRUnichar *suggestedTitle, const PRUnichar *suggestedCategory) = 0;

  /* void addMicrosummaryGenerator (in string generatorURL); */
  NS_SCRIPTABLE NS_IMETHOD AddMicrosummaryGenerator(const char *generatorURL) = 0;

};

  NS_DEFINE_STATIC_IID_ACCESSOR(nsISidebar, NS_ISIDEBAR_IID)

/* Use this macro when declaring classes that implement this interface. */
#define NS_DECL_NSISIDEBAR \
  NS_SCRIPTABLE NS_IMETHOD AddPanel(const PRUnichar *aTitle, const char *aContentURL, const char *aCustomizeURL); \
  NS_SCRIPTABLE NS_IMETHOD AddPersistentPanel(const PRUnichar *aTitle, const char *aContentURL, const char *aCustomizeURL); \
  NS_SCRIPTABLE NS_IMETHOD AddSearchEngine(const char *engineURL, const char *iconURL, const PRUnichar *suggestedTitle, const PRUnichar *suggestedCategory); \
  NS_SCRIPTABLE NS_IMETHOD AddMicrosummaryGenerator(const char *generatorURL); 

/* Use this macro to declare functions that forward the behavior of this interface to another object. */
#define NS_FORWARD_NSISIDEBAR(_to) \
  NS_SCRIPTABLE NS_IMETHOD AddPanel(const PRUnichar *aTitle, const char *aContentURL, const char *aCustomizeURL) { return _to AddPanel(aTitle, aContentURL, aCustomizeURL); } \
  NS_SCRIPTABLE NS_IMETHOD AddPersistentPanel(const PRUnichar *aTitle, const char *aContentURL, const char *aCustomizeURL) { return _to AddPersistentPanel(aTitle, aContentURL, aCustomizeURL); } \
  NS_SCRIPTABLE NS_IMETHOD AddSearchEngine(const char *engineURL, const char *iconURL, const PRUnichar *suggestedTitle, const PRUnichar *suggestedCategory) { return _to AddSearchEngine(engineURL, iconURL, suggestedTitle, suggestedCategory); } \
  NS_SCRIPTABLE NS_IMETHOD AddMicrosummaryGenerator(const char *generatorURL) { return _to AddMicrosummaryGenerator(generatorURL); } 

/* Use this macro to declare functions that forward the behavior of this interface to another object in a safe way. */
#define NS_FORWARD_SAFE_NSISIDEBAR(_to) \
  NS_SCRIPTABLE NS_IMETHOD AddPanel(const PRUnichar *aTitle, const char *aContentURL, const char *aCustomizeURL) { return !_to ? NS_ERROR_NULL_POINTER : _to->AddPanel(aTitle, aContentURL, aCustomizeURL); } \
  NS_SCRIPTABLE NS_IMETHOD AddPersistentPanel(const PRUnichar *aTitle, const char *aContentURL, const char *aCustomizeURL) { return !_to ? NS_ERROR_NULL_POINTER : _to->AddPersistentPanel(aTitle, aContentURL, aCustomizeURL); } \
  NS_SCRIPTABLE NS_IMETHOD AddSearchEngine(const char *engineURL, const char *iconURL, const PRUnichar *suggestedTitle, const PRUnichar *suggestedCategory) { return !_to ? NS_ERROR_NULL_POINTER : _to->AddSearchEngine(engineURL, iconURL, suggestedTitle, suggestedCategory); } \
  NS_SCRIPTABLE NS_IMETHOD AddMicrosummaryGenerator(const char *generatorURL) { return !_to ? NS_ERROR_NULL_POINTER : _to->AddMicrosummaryGenerator(generatorURL); } 

#if 0
/* Use the code below as a template for the implementation class for this interface. */

/* Header file */
class nsSidebar : public nsISidebar
{
public:
  NS_DECL_ISUPPORTS
  NS_DECL_NSISIDEBAR

  nsSidebar();

private:
  ~nsSidebar();

protected:
  /* additional members */
};

/* Implementation file */
NS_IMPL_ISUPPORTS1(nsSidebar, nsISidebar)

nsSidebar::nsSidebar()
{
  /* member initializers and constructor code */
}

nsSidebar::~nsSidebar()
{
  /* destructor code */
}

/* void addPanel (in wstring aTitle, in string aContentURL, in string aCustomizeURL); */
NS_IMETHODIMP nsSidebar::AddPanel(const PRUnichar *aTitle, const char *aContentURL, const char *aCustomizeURL)
{
    return NS_ERROR_NOT_IMPLEMENTED;
}

/* void addPersistentPanel (in wstring aTitle, in string aContentURL, in string aCustomizeURL); */
NS_IMETHODIMP nsSidebar::AddPersistentPanel(const PRUnichar *aTitle, const char *aContentURL, const char *aCustomizeURL)
{
    return NS_ERROR_NOT_IMPLEMENTED;
}

/* void addSearchEngine (in string engineURL, in string iconURL, in wstring suggestedTitle, in wstring suggestedCategory); */
NS_IMETHODIMP nsSidebar::AddSearchEngine(const char *engineURL, const char *iconURL, const PRUnichar *suggestedTitle, const PRUnichar *suggestedCategory)
{
    return NS_ERROR_NOT_IMPLEMENTED;
}

/* void addMicrosummaryGenerator (in string generatorURL); */
NS_IMETHODIMP nsSidebar::AddMicrosummaryGenerator(const char *generatorURL)
{
    return NS_ERROR_NOT_IMPLEMENTED;
}

/* End of implementation class template. */
#endif


/* starting interface:    nsISidebarExternal */
#define NS_ISIDEBAREXTERNAL_IID_STR "4350fb73-9305-41df-a669-11d26222d420"

#define NS_ISIDEBAREXTERNAL_IID \
  {0x4350fb73, 0x9305, 0x41df, \
    { 0xa6, 0x69, 0x11, 0xd2, 0x62, 0x22, 0xd4, 0x20 }}

class NS_NO_VTABLE NS_SCRIPTABLE nsISidebarExternal : public nsISupports {
 public: 

  NS_DECLARE_STATIC_IID_ACCESSOR(NS_ISIDEBAREXTERNAL_IID)

  /* void AddSearchProvider (in string aDescriptionURL); */
  NS_SCRIPTABLE NS_IMETHOD AddSearchProvider(const char *aDescriptionURL) = 0;

  /* unsigned long IsSearchProviderInstalled (in string aSearchURL); */
  NS_SCRIPTABLE NS_IMETHOD IsSearchProviderInstalled(const char *aSearchURL, PRUint32 *_retval NS_OUTPARAM) = 0;

};

  NS_DEFINE_STATIC_IID_ACCESSOR(nsISidebarExternal, NS_ISIDEBAREXTERNAL_IID)

/* Use this macro when declaring classes that implement this interface. */
#define NS_DECL_NSISIDEBAREXTERNAL \
  NS_SCRIPTABLE NS_IMETHOD AddSearchProvider(const char *aDescriptionURL); \
  NS_SCRIPTABLE NS_IMETHOD IsSearchProviderInstalled(const char *aSearchURL, PRUint32 *_retval NS_OUTPARAM); 

/* Use this macro to declare functions that forward the behavior of this interface to another object. */
#define NS_FORWARD_NSISIDEBAREXTERNAL(_to) \
  NS_SCRIPTABLE NS_IMETHOD AddSearchProvider(const char *aDescriptionURL) { return _to AddSearchProvider(aDescriptionURL); } \
  NS_SCRIPTABLE NS_IMETHOD IsSearchProviderInstalled(const char *aSearchURL, PRUint32 *_retval NS_OUTPARAM) { return _to IsSearchProviderInstalled(aSearchURL, _retval); } 

/* Use this macro to declare functions that forward the behavior of this interface to another object in a safe way. */
#define NS_FORWARD_SAFE_NSISIDEBAREXTERNAL(_to) \
  NS_SCRIPTABLE NS_IMETHOD AddSearchProvider(const char *aDescriptionURL) { return !_to ? NS_ERROR_NULL_POINTER : _to->AddSearchProvider(aDescriptionURL); } \
  NS_SCRIPTABLE NS_IMETHOD IsSearchProviderInstalled(const char *aSearchURL, PRUint32 *_retval NS_OUTPARAM) { return !_to ? NS_ERROR_NULL_POINTER : _to->IsSearchProviderInstalled(aSearchURL, _retval); } 

#if 0
/* Use the code below as a template for the implementation class for this interface. */

/* Header file */
class nsSidebarExternal : public nsISidebarExternal
{
public:
  NS_DECL_ISUPPORTS
  NS_DECL_NSISIDEBAREXTERNAL

  nsSidebarExternal();

private:
  ~nsSidebarExternal();

protected:
  /* additional members */
};

/* Implementation file */
NS_IMPL_ISUPPORTS1(nsSidebarExternal, nsISidebarExternal)

nsSidebarExternal::nsSidebarExternal()
{
  /* member initializers and constructor code */
}

nsSidebarExternal::~nsSidebarExternal()
{
  /* destructor code */
}

/* void AddSearchProvider (in string aDescriptionURL); */
NS_IMETHODIMP nsSidebarExternal::AddSearchProvider(const char *aDescriptionURL)
{
    return NS_ERROR_NOT_IMPLEMENTED;
}

/* unsigned long IsSearchProviderInstalled (in string aSearchURL); */
NS_IMETHODIMP nsSidebarExternal::IsSearchProviderInstalled(const char *aSearchURL, PRUint32 *_retval NS_OUTPARAM)
{
    return NS_ERROR_NOT_IMPLEMENTED;
}

/* End of implementation class template. */
#endif

// {577CB744-8CAF-11d3-AAEF-00805F8A4905} 
#define NS_SIDEBAR_CID \
{ 0x577cb744, 0x8caf, 0x11d3, { 0xaa, 0xef, 0x0, 0x80, 0x5f, 0x8a, 0x49, 0x5 } }
#define NS_SIDEBAR_CONTRACTID "@mozilla.org/sidebar;1"

#endif /* __gen_nsISidebar_h__ */
