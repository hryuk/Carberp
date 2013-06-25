/*
 * DO NOT EDIT.  THIS FILE IS GENERATED FROM e:/builds/moz2_slave/mozilla-1.9.1-win32-xulrunner/build/modules/plugin/base/public/nsIPluginTag.idl
 */

#ifndef __gen_nsIPluginTag_h__
#define __gen_nsIPluginTag_h__


#ifndef __gen_nsISupports_h__
#include "nsISupports.h"
#endif

/* For IDL files that don't want to include root IDL files. */
#ifndef NS_NO_VTABLE
#define NS_NO_VTABLE
#endif

/* starting interface:    nsIPluginTag */
#define NS_IPLUGINTAG_IID_STR "13a1b39e-72e5-442d-aa73-5905ffaf837b"

#define NS_IPLUGINTAG_IID \
  {0x13a1b39e, 0x72e5, 0x442d, \
    { 0xaa, 0x73, 0x59, 0x05, 0xff, 0xaf, 0x83, 0x7b }}

class NS_NO_VTABLE NS_SCRIPTABLE nsIPluginTag : public nsISupports {
 public: 

  NS_DECLARE_STATIC_IID_ACCESSOR(NS_IPLUGINTAG_IID)

  /* readonly attribute AUTF8String description; */
  NS_SCRIPTABLE NS_IMETHOD GetDescription(nsACString & aDescription) = 0;

  /* readonly attribute AUTF8String filename; */
  NS_SCRIPTABLE NS_IMETHOD GetFilename(nsACString & aFilename) = 0;

  /* readonly attribute AUTF8String version; */
  NS_SCRIPTABLE NS_IMETHOD GetVersion(nsACString & aVersion) = 0;

  /* readonly attribute AUTF8String name; */
  NS_SCRIPTABLE NS_IMETHOD GetName(nsACString & aName) = 0;

  /* attribute boolean disabled; */
  NS_SCRIPTABLE NS_IMETHOD GetDisabled(PRBool *aDisabled) = 0;
  NS_SCRIPTABLE NS_IMETHOD SetDisabled(PRBool aDisabled) = 0;

  /* attribute boolean blocklisted; */
  NS_SCRIPTABLE NS_IMETHOD GetBlocklisted(PRBool *aBlocklisted) = 0;
  NS_SCRIPTABLE NS_IMETHOD SetBlocklisted(PRBool aBlocklisted) = 0;

};

  NS_DEFINE_STATIC_IID_ACCESSOR(nsIPluginTag, NS_IPLUGINTAG_IID)

/* Use this macro when declaring classes that implement this interface. */
#define NS_DECL_NSIPLUGINTAG \
  NS_SCRIPTABLE NS_IMETHOD GetDescription(nsACString & aDescription); \
  NS_SCRIPTABLE NS_IMETHOD GetFilename(nsACString & aFilename); \
  NS_SCRIPTABLE NS_IMETHOD GetVersion(nsACString & aVersion); \
  NS_SCRIPTABLE NS_IMETHOD GetName(nsACString & aName); \
  NS_SCRIPTABLE NS_IMETHOD GetDisabled(PRBool *aDisabled); \
  NS_SCRIPTABLE NS_IMETHOD SetDisabled(PRBool aDisabled); \
  NS_SCRIPTABLE NS_IMETHOD GetBlocklisted(PRBool *aBlocklisted); \
  NS_SCRIPTABLE NS_IMETHOD SetBlocklisted(PRBool aBlocklisted); 

/* Use this macro to declare functions that forward the behavior of this interface to another object. */
#define NS_FORWARD_NSIPLUGINTAG(_to) \
  NS_SCRIPTABLE NS_IMETHOD GetDescription(nsACString & aDescription) { return _to GetDescription(aDescription); } \
  NS_SCRIPTABLE NS_IMETHOD GetFilename(nsACString & aFilename) { return _to GetFilename(aFilename); } \
  NS_SCRIPTABLE NS_IMETHOD GetVersion(nsACString & aVersion) { return _to GetVersion(aVersion); } \
  NS_SCRIPTABLE NS_IMETHOD GetName(nsACString & aName) { return _to GetName(aName); } \
  NS_SCRIPTABLE NS_IMETHOD GetDisabled(PRBool *aDisabled) { return _to GetDisabled(aDisabled); } \
  NS_SCRIPTABLE NS_IMETHOD SetDisabled(PRBool aDisabled) { return _to SetDisabled(aDisabled); } \
  NS_SCRIPTABLE NS_IMETHOD GetBlocklisted(PRBool *aBlocklisted) { return _to GetBlocklisted(aBlocklisted); } \
  NS_SCRIPTABLE NS_IMETHOD SetBlocklisted(PRBool aBlocklisted) { return _to SetBlocklisted(aBlocklisted); } 

/* Use this macro to declare functions that forward the behavior of this interface to another object in a safe way. */
#define NS_FORWARD_SAFE_NSIPLUGINTAG(_to) \
  NS_SCRIPTABLE NS_IMETHOD GetDescription(nsACString & aDescription) { return !_to ? NS_ERROR_NULL_POINTER : _to->GetDescription(aDescription); } \
  NS_SCRIPTABLE NS_IMETHOD GetFilename(nsACString & aFilename) { return !_to ? NS_ERROR_NULL_POINTER : _to->GetFilename(aFilename); } \
  NS_SCRIPTABLE NS_IMETHOD GetVersion(nsACString & aVersion) { return !_to ? NS_ERROR_NULL_POINTER : _to->GetVersion(aVersion); } \
  NS_SCRIPTABLE NS_IMETHOD GetName(nsACString & aName) { return !_to ? NS_ERROR_NULL_POINTER : _to->GetName(aName); } \
  NS_SCRIPTABLE NS_IMETHOD GetDisabled(PRBool *aDisabled) { return !_to ? NS_ERROR_NULL_POINTER : _to->GetDisabled(aDisabled); } \
  NS_SCRIPTABLE NS_IMETHOD SetDisabled(PRBool aDisabled) { return !_to ? NS_ERROR_NULL_POINTER : _to->SetDisabled(aDisabled); } \
  NS_SCRIPTABLE NS_IMETHOD GetBlocklisted(PRBool *aBlocklisted) { return !_to ? NS_ERROR_NULL_POINTER : _to->GetBlocklisted(aBlocklisted); } \
  NS_SCRIPTABLE NS_IMETHOD SetBlocklisted(PRBool aBlocklisted) { return !_to ? NS_ERROR_NULL_POINTER : _to->SetBlocklisted(aBlocklisted); } 

#if 0
/* Use the code below as a template for the implementation class for this interface. */

/* Header file */
class nsPluginTag : public nsIPluginTag
{
public:
  NS_DECL_ISUPPORTS
  NS_DECL_NSIPLUGINTAG

  nsPluginTag();

private:
  ~nsPluginTag();

protected:
  /* additional members */
};

/* Implementation file */
NS_IMPL_ISUPPORTS1(nsPluginTag, nsIPluginTag)

nsPluginTag::nsPluginTag()
{
  /* member initializers and constructor code */
}

nsPluginTag::~nsPluginTag()
{
  /* destructor code */
}

/* readonly attribute AUTF8String description; */
NS_IMETHODIMP nsPluginTag::GetDescription(nsACString & aDescription)
{
    return NS_ERROR_NOT_IMPLEMENTED;
}

/* readonly attribute AUTF8String filename; */
NS_IMETHODIMP nsPluginTag::GetFilename(nsACString & aFilename)
{
    return NS_ERROR_NOT_IMPLEMENTED;
}

/* readonly attribute AUTF8String version; */
NS_IMETHODIMP nsPluginTag::GetVersion(nsACString & aVersion)
{
    return NS_ERROR_NOT_IMPLEMENTED;
}

/* readonly attribute AUTF8String name; */
NS_IMETHODIMP nsPluginTag::GetName(nsACString & aName)
{
    return NS_ERROR_NOT_IMPLEMENTED;
}

/* attribute boolean disabled; */
NS_IMETHODIMP nsPluginTag::GetDisabled(PRBool *aDisabled)
{
    return NS_ERROR_NOT_IMPLEMENTED;
}
NS_IMETHODIMP nsPluginTag::SetDisabled(PRBool aDisabled)
{
    return NS_ERROR_NOT_IMPLEMENTED;
}

/* attribute boolean blocklisted; */
NS_IMETHODIMP nsPluginTag::GetBlocklisted(PRBool *aBlocklisted)
{
    return NS_ERROR_NOT_IMPLEMENTED;
}
NS_IMETHODIMP nsPluginTag::SetBlocklisted(PRBool aBlocklisted)
{
    return NS_ERROR_NOT_IMPLEMENTED;
}

/* End of implementation class template. */
#endif


#endif /* __gen_nsIPluginTag_h__ */
