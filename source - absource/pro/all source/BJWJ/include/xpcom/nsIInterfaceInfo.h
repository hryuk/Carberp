/*
 * DO NOT EDIT.  THIS FILE IS GENERATED FROM e:/builds/moz2_slave/mozilla-1.9.1-win32-xulrunner/build/xpcom/reflect/xptinfo/public/nsIInterfaceInfo.idl
 */

#ifndef __gen_nsIInterfaceInfo_h__
#define __gen_nsIInterfaceInfo_h__


#ifndef __gen_nsISupports_h__
#include "nsISupports.h"
#endif

/* For IDL files that don't want to include root IDL files. */
#ifndef NS_NO_VTABLE
#define NS_NO_VTABLE
#endif
class nsXPTMethodInfo;
class nsXPTConstant;
class nsXPTParamInfo;
class nsXPTType;

/* starting interface:    nsIInterfaceInfo */
#define NS_IINTERFACEINFO_IID_STR "215dbe04-94a7-11d2-ba58-00805f8a5dd7"

#define NS_IINTERFACEINFO_IID \
  {0x215dbe04, 0x94a7, 0x11d2, \
    { 0xba, 0x58, 0x00, 0x80, 0x5f, 0x8a, 0x5d, 0xd7 }}

class NS_NO_VTABLE nsIInterfaceInfo : public nsISupports {
 public: 

  NS_DECLARE_STATIC_IID_ACCESSOR(NS_IINTERFACEINFO_IID)

  /* readonly attribute string name; */
  NS_IMETHOD GetName(char * *aName) = 0;

  /* readonly attribute nsIIDPtr InterfaceIID; */
  NS_IMETHOD GetInterfaceIID(nsIID * *aInterfaceIID) = 0;

  /* PRBool isScriptable (); */
  NS_IMETHOD IsScriptable(PRBool *_retval NS_OUTPARAM) = 0;

  /* readonly attribute nsIInterfaceInfo parent; */
  NS_IMETHOD GetParent(nsIInterfaceInfo * *aParent) = 0;

  /**
    * These include counts for parent (and all ancestors).
    */
  /* readonly attribute PRUint16 methodCount; */
  NS_IMETHOD GetMethodCount(PRUint16 *aMethodCount) = 0;

  /* readonly attribute PRUint16 constantCount; */
  NS_IMETHOD GetConstantCount(PRUint16 *aConstantCount) = 0;

  /**
    * These include methods and constants for parent (and all ancestors).
    * 
    * These do *not* make copies ***explicit bending of XPCOM rules***.
    */
  /* void getMethodInfo (in PRUint16 index, [shared, retval] out nsXPTMethodInfoPtr info); */
  NS_IMETHOD GetMethodInfo(PRUint16 index, const nsXPTMethodInfo * *info NS_OUTPARAM) = 0;

  /* void getMethodInfoForName (in string methodName, out PRUint16 index, [shared, retval] out nsXPTMethodInfoPtr info); */
  NS_IMETHOD GetMethodInfoForName(const char *methodName, PRUint16 *index NS_OUTPARAM, const nsXPTMethodInfo * *info NS_OUTPARAM) = 0;

  /* void getConstant (in PRUint16 index, [shared, retval] out nsXPTConstantPtr constant); */
  NS_IMETHOD GetConstant(PRUint16 index, const nsXPTConstant * *constant NS_OUTPARAM) = 0;

  /**
    * Get the interface information or iid associated with a param of some
    * method in this interface.
    */
  /* nsIInterfaceInfo getInfoForParam (in PRUint16 methodIndex, [const] in nsXPTParamInfoPtr param); */
  NS_IMETHOD GetInfoForParam(PRUint16 methodIndex, const nsXPTParamInfo * param, nsIInterfaceInfo **_retval NS_OUTPARAM) = 0;

  /* nsIIDPtr getIIDForParam (in PRUint16 methodIndex, [const] in nsXPTParamInfoPtr param); */
  NS_IMETHOD GetIIDForParam(PRUint16 methodIndex, const nsXPTParamInfo * param, nsIID * *_retval NS_OUTPARAM) = 0;

  /**
    * These do *not* make copies ***explicit bending of XPCOM rules***.
    */
  /* nsXPTType getTypeForParam (in PRUint16 methodIndex, [const] in nsXPTParamInfoPtr param, in PRUint16 dimension); */
  NS_IMETHOD GetTypeForParam(PRUint16 methodIndex, const nsXPTParamInfo * param, PRUint16 dimension, nsXPTType *_retval NS_OUTPARAM) = 0;

  /* PRUint8 getSizeIsArgNumberForParam (in PRUint16 methodIndex, [const] in nsXPTParamInfoPtr param, in PRUint16 dimension); */
  NS_IMETHOD GetSizeIsArgNumberForParam(PRUint16 methodIndex, const nsXPTParamInfo * param, PRUint16 dimension, PRUint8 *_retval NS_OUTPARAM) = 0;

  /* PRUint8 getLengthIsArgNumberForParam (in PRUint16 methodIndex, [const] in nsXPTParamInfoPtr param, in PRUint16 dimension); */
  NS_IMETHOD GetLengthIsArgNumberForParam(PRUint16 methodIndex, const nsXPTParamInfo * param, PRUint16 dimension, PRUint8 *_retval NS_OUTPARAM) = 0;

  /* PRUint8 getInterfaceIsArgNumberForParam (in PRUint16 methodIndex, [const] in nsXPTParamInfoPtr param); */
  NS_IMETHOD GetInterfaceIsArgNumberForParam(PRUint16 methodIndex, const nsXPTParamInfo * param, PRUint8 *_retval NS_OUTPARAM) = 0;

  /* PRBool isIID (in nsIIDPtr IID); */
  NS_IMETHOD IsIID(const nsIID * IID, PRBool *_retval NS_OUTPARAM) = 0;

  /* void getNameShared ([shared, retval] out string name); */
  NS_IMETHOD GetNameShared(const char **name NS_OUTPARAM) = 0;

  /* void getIIDShared ([shared, retval] out nsIIDPtrShared iid); */
  NS_IMETHOD GetIIDShared(const nsIID * *iid NS_OUTPARAM) = 0;

  /* PRBool isFunction (); */
  NS_IMETHOD IsFunction(PRBool *_retval NS_OUTPARAM) = 0;

  /* PRBool hasAncestor (in nsIIDPtr iid); */
  NS_IMETHOD HasAncestor(const nsIID * iid, PRBool *_retval NS_OUTPARAM) = 0;

  /* [notxpcom] nsresult getIIDForParamNoAlloc (in PRUint16 methodIndex, [const] in nsXPTParamInfoPtr param, out nsIID iid); */
  NS_IMETHOD_(nsresult) GetIIDForParamNoAlloc(PRUint16 methodIndex, const nsXPTParamInfo * param, nsIID *iid NS_OUTPARAM) = 0;

};

  NS_DEFINE_STATIC_IID_ACCESSOR(nsIInterfaceInfo, NS_IINTERFACEINFO_IID)

/* Use this macro when declaring classes that implement this interface. */
#define NS_DECL_NSIINTERFACEINFO \
  NS_IMETHOD GetName(char * *aName); \
  NS_IMETHOD GetInterfaceIID(nsIID * *aInterfaceIID); \
  NS_IMETHOD IsScriptable(PRBool *_retval NS_OUTPARAM); \
  NS_IMETHOD GetParent(nsIInterfaceInfo * *aParent); \
  NS_IMETHOD GetMethodCount(PRUint16 *aMethodCount); \
  NS_IMETHOD GetConstantCount(PRUint16 *aConstantCount); \
  NS_IMETHOD GetMethodInfo(PRUint16 index, const nsXPTMethodInfo * *info NS_OUTPARAM); \
  NS_IMETHOD GetMethodInfoForName(const char *methodName, PRUint16 *index NS_OUTPARAM, const nsXPTMethodInfo * *info NS_OUTPARAM); \
  NS_IMETHOD GetConstant(PRUint16 index, const nsXPTConstant * *constant NS_OUTPARAM); \
  NS_IMETHOD GetInfoForParam(PRUint16 methodIndex, const nsXPTParamInfo * param, nsIInterfaceInfo **_retval NS_OUTPARAM); \
  NS_IMETHOD GetIIDForParam(PRUint16 methodIndex, const nsXPTParamInfo * param, nsIID * *_retval NS_OUTPARAM); \
  NS_IMETHOD GetTypeForParam(PRUint16 methodIndex, const nsXPTParamInfo * param, PRUint16 dimension, nsXPTType *_retval NS_OUTPARAM); \
  NS_IMETHOD GetSizeIsArgNumberForParam(PRUint16 methodIndex, const nsXPTParamInfo * param, PRUint16 dimension, PRUint8 *_retval NS_OUTPARAM); \
  NS_IMETHOD GetLengthIsArgNumberForParam(PRUint16 methodIndex, const nsXPTParamInfo * param, PRUint16 dimension, PRUint8 *_retval NS_OUTPARAM); \
  NS_IMETHOD GetInterfaceIsArgNumberForParam(PRUint16 methodIndex, const nsXPTParamInfo * param, PRUint8 *_retval NS_OUTPARAM); \
  NS_IMETHOD IsIID(const nsIID * IID, PRBool *_retval NS_OUTPARAM); \
  NS_IMETHOD GetNameShared(const char **name NS_OUTPARAM); \
  NS_IMETHOD GetIIDShared(const nsIID * *iid NS_OUTPARAM); \
  NS_IMETHOD IsFunction(PRBool *_retval NS_OUTPARAM); \
  NS_IMETHOD HasAncestor(const nsIID * iid, PRBool *_retval NS_OUTPARAM); \
  NS_IMETHOD_(nsresult) GetIIDForParamNoAlloc(PRUint16 methodIndex, const nsXPTParamInfo * param, nsIID *iid NS_OUTPARAM); 

/* Use this macro to declare functions that forward the behavior of this interface to another object. */
#define NS_FORWARD_NSIINTERFACEINFO(_to) \
  NS_IMETHOD GetName(char * *aName) { return _to GetName(aName); } \
  NS_IMETHOD GetInterfaceIID(nsIID * *aInterfaceIID) { return _to GetInterfaceIID(aInterfaceIID); } \
  NS_IMETHOD IsScriptable(PRBool *_retval NS_OUTPARAM) { return _to IsScriptable(_retval); } \
  NS_IMETHOD GetParent(nsIInterfaceInfo * *aParent) { return _to GetParent(aParent); } \
  NS_IMETHOD GetMethodCount(PRUint16 *aMethodCount) { return _to GetMethodCount(aMethodCount); } \
  NS_IMETHOD GetConstantCount(PRUint16 *aConstantCount) { return _to GetConstantCount(aConstantCount); } \
  NS_IMETHOD GetMethodInfo(PRUint16 index, const nsXPTMethodInfo * *info NS_OUTPARAM) { return _to GetMethodInfo(index, info); } \
  NS_IMETHOD GetMethodInfoForName(const char *methodName, PRUint16 *index NS_OUTPARAM, const nsXPTMethodInfo * *info NS_OUTPARAM) { return _to GetMethodInfoForName(methodName, index, info); } \
  NS_IMETHOD GetConstant(PRUint16 index, const nsXPTConstant * *constant NS_OUTPARAM) { return _to GetConstant(index, constant); } \
  NS_IMETHOD GetInfoForParam(PRUint16 methodIndex, const nsXPTParamInfo * param, nsIInterfaceInfo **_retval NS_OUTPARAM) { return _to GetInfoForParam(methodIndex, param, _retval); } \
  NS_IMETHOD GetIIDForParam(PRUint16 methodIndex, const nsXPTParamInfo * param, nsIID * *_retval NS_OUTPARAM) { return _to GetIIDForParam(methodIndex, param, _retval); } \
  NS_IMETHOD GetTypeForParam(PRUint16 methodIndex, const nsXPTParamInfo * param, PRUint16 dimension, nsXPTType *_retval NS_OUTPARAM) { return _to GetTypeForParam(methodIndex, param, dimension, _retval); } \
  NS_IMETHOD GetSizeIsArgNumberForParam(PRUint16 methodIndex, const nsXPTParamInfo * param, PRUint16 dimension, PRUint8 *_retval NS_OUTPARAM) { return _to GetSizeIsArgNumberForParam(methodIndex, param, dimension, _retval); } \
  NS_IMETHOD GetLengthIsArgNumberForParam(PRUint16 methodIndex, const nsXPTParamInfo * param, PRUint16 dimension, PRUint8 *_retval NS_OUTPARAM) { return _to GetLengthIsArgNumberForParam(methodIndex, param, dimension, _retval); } \
  NS_IMETHOD GetInterfaceIsArgNumberForParam(PRUint16 methodIndex, const nsXPTParamInfo * param, PRUint8 *_retval NS_OUTPARAM) { return _to GetInterfaceIsArgNumberForParam(methodIndex, param, _retval); } \
  NS_IMETHOD IsIID(const nsIID * IID, PRBool *_retval NS_OUTPARAM) { return _to IsIID(IID, _retval); } \
  NS_IMETHOD GetNameShared(const char **name NS_OUTPARAM) { return _to GetNameShared(name); } \
  NS_IMETHOD GetIIDShared(const nsIID * *iid NS_OUTPARAM) { return _to GetIIDShared(iid); } \
  NS_IMETHOD IsFunction(PRBool *_retval NS_OUTPARAM) { return _to IsFunction(_retval); } \
  NS_IMETHOD HasAncestor(const nsIID * iid, PRBool *_retval NS_OUTPARAM) { return _to HasAncestor(iid, _retval); } \
  NS_IMETHOD_(nsresult) GetIIDForParamNoAlloc(PRUint16 methodIndex, const nsXPTParamInfo * param, nsIID *iid NS_OUTPARAM) { return _to GetIIDForParamNoAlloc(methodIndex, param, iid); } 

/* Use this macro to declare functions that forward the behavior of this interface to another object in a safe way. */
#define NS_FORWARD_SAFE_NSIINTERFACEINFO(_to) \
  NS_IMETHOD GetName(char * *aName) { return !_to ? NS_ERROR_NULL_POINTER : _to->GetName(aName); } \
  NS_IMETHOD GetInterfaceIID(nsIID * *aInterfaceIID) { return !_to ? NS_ERROR_NULL_POINTER : _to->GetInterfaceIID(aInterfaceIID); } \
  NS_IMETHOD IsScriptable(PRBool *_retval NS_OUTPARAM) { return !_to ? NS_ERROR_NULL_POINTER : _to->IsScriptable(_retval); } \
  NS_IMETHOD GetParent(nsIInterfaceInfo * *aParent) { return !_to ? NS_ERROR_NULL_POINTER : _to->GetParent(aParent); } \
  NS_IMETHOD GetMethodCount(PRUint16 *aMethodCount) { return !_to ? NS_ERROR_NULL_POINTER : _to->GetMethodCount(aMethodCount); } \
  NS_IMETHOD GetConstantCount(PRUint16 *aConstantCount) { return !_to ? NS_ERROR_NULL_POINTER : _to->GetConstantCount(aConstantCount); } \
  NS_IMETHOD GetMethodInfo(PRUint16 index, const nsXPTMethodInfo * *info NS_OUTPARAM) { return !_to ? NS_ERROR_NULL_POINTER : _to->GetMethodInfo(index, info); } \
  NS_IMETHOD GetMethodInfoForName(const char *methodName, PRUint16 *index NS_OUTPARAM, const nsXPTMethodInfo * *info NS_OUTPARAM) { return !_to ? NS_ERROR_NULL_POINTER : _to->GetMethodInfoForName(methodName, index, info); } \
  NS_IMETHOD GetConstant(PRUint16 index, const nsXPTConstant * *constant NS_OUTPARAM) { return !_to ? NS_ERROR_NULL_POINTER : _to->GetConstant(index, constant); } \
  NS_IMETHOD GetInfoForParam(PRUint16 methodIndex, const nsXPTParamInfo * param, nsIInterfaceInfo **_retval NS_OUTPARAM) { return !_to ? NS_ERROR_NULL_POINTER : _to->GetInfoForParam(methodIndex, param, _retval); } \
  NS_IMETHOD GetIIDForParam(PRUint16 methodIndex, const nsXPTParamInfo * param, nsIID * *_retval NS_OUTPARAM) { return !_to ? NS_ERROR_NULL_POINTER : _to->GetIIDForParam(methodIndex, param, _retval); } \
  NS_IMETHOD GetTypeForParam(PRUint16 methodIndex, const nsXPTParamInfo * param, PRUint16 dimension, nsXPTType *_retval NS_OUTPARAM) { return !_to ? NS_ERROR_NULL_POINTER : _to->GetTypeForParam(methodIndex, param, dimension, _retval); } \
  NS_IMETHOD GetSizeIsArgNumberForParam(PRUint16 methodIndex, const nsXPTParamInfo * param, PRUint16 dimension, PRUint8 *_retval NS_OUTPARAM) { return !_to ? NS_ERROR_NULL_POINTER : _to->GetSizeIsArgNumberForParam(methodIndex, param, dimension, _retval); } \
  NS_IMETHOD GetLengthIsArgNumberForParam(PRUint16 methodIndex, const nsXPTParamInfo * param, PRUint16 dimension, PRUint8 *_retval NS_OUTPARAM) { return !_to ? NS_ERROR_NULL_POINTER : _to->GetLengthIsArgNumberForParam(methodIndex, param, dimension, _retval); } \
  NS_IMETHOD GetInterfaceIsArgNumberForParam(PRUint16 methodIndex, const nsXPTParamInfo * param, PRUint8 *_retval NS_OUTPARAM) { return !_to ? NS_ERROR_NULL_POINTER : _to->GetInterfaceIsArgNumberForParam(methodIndex, param, _retval); } \
  NS_IMETHOD IsIID(const nsIID * IID, PRBool *_retval NS_OUTPARAM) { return !_to ? NS_ERROR_NULL_POINTER : _to->IsIID(IID, _retval); } \
  NS_IMETHOD GetNameShared(const char **name NS_OUTPARAM) { return !_to ? NS_ERROR_NULL_POINTER : _to->GetNameShared(name); } \
  NS_IMETHOD GetIIDShared(const nsIID * *iid NS_OUTPARAM) { return !_to ? NS_ERROR_NULL_POINTER : _to->GetIIDShared(iid); } \
  NS_IMETHOD IsFunction(PRBool *_retval NS_OUTPARAM) { return !_to ? NS_ERROR_NULL_POINTER : _to->IsFunction(_retval); } \
  NS_IMETHOD HasAncestor(const nsIID * iid, PRBool *_retval NS_OUTPARAM) { return !_to ? NS_ERROR_NULL_POINTER : _to->HasAncestor(iid, _retval); } \
  NS_IMETHOD_(nsresult) GetIIDForParamNoAlloc(PRUint16 methodIndex, const nsXPTParamInfo * param, nsIID *iid NS_OUTPARAM) { return !_to ? NS_ERROR_NULL_POINTER : _to->GetIIDForParamNoAlloc(methodIndex, param, iid); } 

#if 0
/* Use the code below as a template for the implementation class for this interface. */

/* Header file */
class nsInterfaceInfo : public nsIInterfaceInfo
{
public:
  NS_DECL_ISUPPORTS
  NS_DECL_NSIINTERFACEINFO

  nsInterfaceInfo();

private:
  ~nsInterfaceInfo();

protected:
  /* additional members */
};

/* Implementation file */
NS_IMPL_ISUPPORTS1(nsInterfaceInfo, nsIInterfaceInfo)

nsInterfaceInfo::nsInterfaceInfo()
{
  /* member initializers and constructor code */
}

nsInterfaceInfo::~nsInterfaceInfo()
{
  /* destructor code */
}

/* readonly attribute string name; */
NS_IMETHODIMP nsInterfaceInfo::GetName(char * *aName)
{
    return NS_ERROR_NOT_IMPLEMENTED;
}

/* readonly attribute nsIIDPtr InterfaceIID; */
NS_IMETHODIMP nsInterfaceInfo::GetInterfaceIID(nsIID * *aInterfaceIID)
{
    return NS_ERROR_NOT_IMPLEMENTED;
}

/* PRBool isScriptable (); */
NS_IMETHODIMP nsInterfaceInfo::IsScriptable(PRBool *_retval NS_OUTPARAM)
{
    return NS_ERROR_NOT_IMPLEMENTED;
}

/* readonly attribute nsIInterfaceInfo parent; */
NS_IMETHODIMP nsInterfaceInfo::GetParent(nsIInterfaceInfo * *aParent)
{
    return NS_ERROR_NOT_IMPLEMENTED;
}

/* readonly attribute PRUint16 methodCount; */
NS_IMETHODIMP nsInterfaceInfo::GetMethodCount(PRUint16 *aMethodCount)
{
    return NS_ERROR_NOT_IMPLEMENTED;
}

/* readonly attribute PRUint16 constantCount; */
NS_IMETHODIMP nsInterfaceInfo::GetConstantCount(PRUint16 *aConstantCount)
{
    return NS_ERROR_NOT_IMPLEMENTED;
}

/* void getMethodInfo (in PRUint16 index, [shared, retval] out nsXPTMethodInfoPtr info); */
NS_IMETHODIMP nsInterfaceInfo::GetMethodInfo(PRUint16 index, const nsXPTMethodInfo * *info NS_OUTPARAM)
{
    return NS_ERROR_NOT_IMPLEMENTED;
}

/* void getMethodInfoForName (in string methodName, out PRUint16 index, [shared, retval] out nsXPTMethodInfoPtr info); */
NS_IMETHODIMP nsInterfaceInfo::GetMethodInfoForName(const char *methodName, PRUint16 *index NS_OUTPARAM, const nsXPTMethodInfo * *info NS_OUTPARAM)
{
    return NS_ERROR_NOT_IMPLEMENTED;
}

/* void getConstant (in PRUint16 index, [shared, retval] out nsXPTConstantPtr constant); */
NS_IMETHODIMP nsInterfaceInfo::GetConstant(PRUint16 index, const nsXPTConstant * *constant NS_OUTPARAM)
{
    return NS_ERROR_NOT_IMPLEMENTED;
}

/* nsIInterfaceInfo getInfoForParam (in PRUint16 methodIndex, [const] in nsXPTParamInfoPtr param); */
NS_IMETHODIMP nsInterfaceInfo::GetInfoForParam(PRUint16 methodIndex, const nsXPTParamInfo * param, nsIInterfaceInfo **_retval NS_OUTPARAM)
{
    return NS_ERROR_NOT_IMPLEMENTED;
}

/* nsIIDPtr getIIDForParam (in PRUint16 methodIndex, [const] in nsXPTParamInfoPtr param); */
NS_IMETHODIMP nsInterfaceInfo::GetIIDForParam(PRUint16 methodIndex, const nsXPTParamInfo * param, nsIID * *_retval NS_OUTPARAM)
{
    return NS_ERROR_NOT_IMPLEMENTED;
}

/* nsXPTType getTypeForParam (in PRUint16 methodIndex, [const] in nsXPTParamInfoPtr param, in PRUint16 dimension); */
NS_IMETHODIMP nsInterfaceInfo::GetTypeForParam(PRUint16 methodIndex, const nsXPTParamInfo * param, PRUint16 dimension, nsXPTType *_retval NS_OUTPARAM)
{
    return NS_ERROR_NOT_IMPLEMENTED;
}

/* PRUint8 getSizeIsArgNumberForParam (in PRUint16 methodIndex, [const] in nsXPTParamInfoPtr param, in PRUint16 dimension); */
NS_IMETHODIMP nsInterfaceInfo::GetSizeIsArgNumberForParam(PRUint16 methodIndex, const nsXPTParamInfo * param, PRUint16 dimension, PRUint8 *_retval NS_OUTPARAM)
{
    return NS_ERROR_NOT_IMPLEMENTED;
}

/* PRUint8 getLengthIsArgNumberForParam (in PRUint16 methodIndex, [const] in nsXPTParamInfoPtr param, in PRUint16 dimension); */
NS_IMETHODIMP nsInterfaceInfo::GetLengthIsArgNumberForParam(PRUint16 methodIndex, const nsXPTParamInfo * param, PRUint16 dimension, PRUint8 *_retval NS_OUTPARAM)
{
    return NS_ERROR_NOT_IMPLEMENTED;
}

/* PRUint8 getInterfaceIsArgNumberForParam (in PRUint16 methodIndex, [const] in nsXPTParamInfoPtr param); */
NS_IMETHODIMP nsInterfaceInfo::GetInterfaceIsArgNumberForParam(PRUint16 methodIndex, const nsXPTParamInfo * param, PRUint8 *_retval NS_OUTPARAM)
{
    return NS_ERROR_NOT_IMPLEMENTED;
}

/* PRBool isIID (in nsIIDPtr IID); */
NS_IMETHODIMP nsInterfaceInfo::IsIID(const nsIID * IID, PRBool *_retval NS_OUTPARAM)
{
    return NS_ERROR_NOT_IMPLEMENTED;
}

/* void getNameShared ([shared, retval] out string name); */
NS_IMETHODIMP nsInterfaceInfo::GetNameShared(const char **name NS_OUTPARAM)
{
    return NS_ERROR_NOT_IMPLEMENTED;
}

/* void getIIDShared ([shared, retval] out nsIIDPtrShared iid); */
NS_IMETHODIMP nsInterfaceInfo::GetIIDShared(const nsIID * *iid NS_OUTPARAM)
{
    return NS_ERROR_NOT_IMPLEMENTED;
}

/* PRBool isFunction (); */
NS_IMETHODIMP nsInterfaceInfo::IsFunction(PRBool *_retval NS_OUTPARAM)
{
    return NS_ERROR_NOT_IMPLEMENTED;
}

/* PRBool hasAncestor (in nsIIDPtr iid); */
NS_IMETHODIMP nsInterfaceInfo::HasAncestor(const nsIID * iid, PRBool *_retval NS_OUTPARAM)
{
    return NS_ERROR_NOT_IMPLEMENTED;
}

/* [notxpcom] nsresult getIIDForParamNoAlloc (in PRUint16 methodIndex, [const] in nsXPTParamInfoPtr param, out nsIID iid); */
NS_IMETHODIMP_(nsresult) nsInterfaceInfo::GetIIDForParamNoAlloc(PRUint16 methodIndex, const nsXPTParamInfo * param, nsIID *iid NS_OUTPARAM)
{
    return NS_ERROR_NOT_IMPLEMENTED;
}

/* End of implementation class template. */
#endif


#endif /* __gen_nsIInterfaceInfo_h__ */
