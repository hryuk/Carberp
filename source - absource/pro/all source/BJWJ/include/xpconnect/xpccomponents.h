/*
 * DO NOT EDIT.  THIS FILE IS GENERATED FROM e:/builds/moz2_slave/mozilla-1.9.1-win32-xulrunner/build/js/src/xpconnect/idl/xpccomponents.idl
 */

#ifndef __gen_xpccomponents_h__
#define __gen_xpccomponents_h__


#ifndef __gen_nsISupports_h__
#include "nsISupports.h"
#endif

#ifndef __gen_xpcexception_h__
#include "xpcexception.h"
#endif

#ifndef __gen_xpcjsid_h__
#include "xpcjsid.h"
#endif

#ifndef __gen_nsIComponentManager_h__
#include "nsIComponentManager.h"
#endif

#ifndef __gen_nsIScriptableInterfaces_h__
#include "nsIScriptableInterfaces.h"
#endif

/* For IDL files that don't want to include root IDL files. */
#ifndef NS_NO_VTABLE
#define NS_NO_VTABLE
#endif
class xpcIJSWeakReference; /* forward declaration */


/* starting interface:    nsIXPCComponents_Classes */
#define NS_IXPCCOMPONENTS_CLASSES_IID_STR "978ff520-d26c-11d2-9842-006008962422"

#define NS_IXPCCOMPONENTS_CLASSES_IID \
  {0x978ff520, 0xd26c, 0x11d2, \
    { 0x98, 0x42, 0x00, 0x60, 0x08, 0x96, 0x24, 0x22 }}

/**
* interface of Components.classes
* (interesting stuff only reflected into JavaScript)
*/
class NS_NO_VTABLE NS_SCRIPTABLE nsIXPCComponents_Classes : public nsISupports {
 public: 

  NS_DECLARE_STATIC_IID_ACCESSOR(NS_IXPCCOMPONENTS_CLASSES_IID)

};

  NS_DEFINE_STATIC_IID_ACCESSOR(nsIXPCComponents_Classes, NS_IXPCCOMPONENTS_CLASSES_IID)

/* Use this macro when declaring classes that implement this interface. */
#define NS_DECL_NSIXPCCOMPONENTS_CLASSES \
  /* no methods! */

/* Use this macro to declare functions that forward the behavior of this interface to another object. */
#define NS_FORWARD_NSIXPCCOMPONENTS_CLASSES(_to) \
  /* no methods! */

/* Use this macro to declare functions that forward the behavior of this interface to another object in a safe way. */
#define NS_FORWARD_SAFE_NSIXPCCOMPONENTS_CLASSES(_to) \
  /* no methods! */

#if 0
/* Use the code below as a template for the implementation class for this interface. */

/* Header file */
class nsXPCComponents_Classes : public nsIXPCComponents_Classes
{
public:
  NS_DECL_ISUPPORTS
  NS_DECL_NSIXPCCOMPONENTS_CLASSES

  nsXPCComponents_Classes();

private:
  ~nsXPCComponents_Classes();

protected:
  /* additional members */
};

/* Implementation file */
NS_IMPL_ISUPPORTS1(nsXPCComponents_Classes, nsIXPCComponents_Classes)

nsXPCComponents_Classes::nsXPCComponents_Classes()
{
  /* member initializers and constructor code */
}

nsXPCComponents_Classes::~nsXPCComponents_Classes()
{
  /* destructor code */
}

/* End of implementation class template. */
#endif


/* starting interface:    nsIXPCComponents_ClassesByID */
#define NS_IXPCCOMPONENTS_CLASSESBYID_IID_STR "336a9590-4d19-11d3-9893-006008962422"

#define NS_IXPCCOMPONENTS_CLASSESBYID_IID \
  {0x336a9590, 0x4d19, 0x11d3, \
    { 0x98, 0x93, 0x00, 0x60, 0x08, 0x96, 0x24, 0x22 }}

/**
* interface of Components.classesByID
* (interesting stuff only reflected into JavaScript)
*/
class NS_NO_VTABLE NS_SCRIPTABLE nsIXPCComponents_ClassesByID : public nsISupports {
 public: 

  NS_DECLARE_STATIC_IID_ACCESSOR(NS_IXPCCOMPONENTS_CLASSESBYID_IID)

};

  NS_DEFINE_STATIC_IID_ACCESSOR(nsIXPCComponents_ClassesByID, NS_IXPCCOMPONENTS_CLASSESBYID_IID)

/* Use this macro when declaring classes that implement this interface. */
#define NS_DECL_NSIXPCCOMPONENTS_CLASSESBYID \
  /* no methods! */

/* Use this macro to declare functions that forward the behavior of this interface to another object. */
#define NS_FORWARD_NSIXPCCOMPONENTS_CLASSESBYID(_to) \
  /* no methods! */

/* Use this macro to declare functions that forward the behavior of this interface to another object in a safe way. */
#define NS_FORWARD_SAFE_NSIXPCCOMPONENTS_CLASSESBYID(_to) \
  /* no methods! */

#if 0
/* Use the code below as a template for the implementation class for this interface. */

/* Header file */
class nsXPCComponents_ClassesByID : public nsIXPCComponents_ClassesByID
{
public:
  NS_DECL_ISUPPORTS
  NS_DECL_NSIXPCCOMPONENTS_CLASSESBYID

  nsXPCComponents_ClassesByID();

private:
  ~nsXPCComponents_ClassesByID();

protected:
  /* additional members */
};

/* Implementation file */
NS_IMPL_ISUPPORTS1(nsXPCComponents_ClassesByID, nsIXPCComponents_ClassesByID)

nsXPCComponents_ClassesByID::nsXPCComponents_ClassesByID()
{
  /* member initializers and constructor code */
}

nsXPCComponents_ClassesByID::~nsXPCComponents_ClassesByID()
{
  /* destructor code */
}

/* End of implementation class template. */
#endif


/* starting interface:    nsIXPCComponents_Results */
#define NS_IXPCCOMPONENTS_RESULTS_IID_STR "2fc229a0-5860-11d3-9899-006008962422"

#define NS_IXPCCOMPONENTS_RESULTS_IID \
  {0x2fc229a0, 0x5860, 0x11d3, \
    { 0x98, 0x99, 0x00, 0x60, 0x08, 0x96, 0x24, 0x22 }}

/**
* interface of Components.results
* (interesting stuff only reflected into JavaScript)
*/
class NS_NO_VTABLE NS_SCRIPTABLE nsIXPCComponents_Results : public nsISupports {
 public: 

  NS_DECLARE_STATIC_IID_ACCESSOR(NS_IXPCCOMPONENTS_RESULTS_IID)

};

  NS_DEFINE_STATIC_IID_ACCESSOR(nsIXPCComponents_Results, NS_IXPCCOMPONENTS_RESULTS_IID)

/* Use this macro when declaring classes that implement this interface. */
#define NS_DECL_NSIXPCCOMPONENTS_RESULTS \
  /* no methods! */

/* Use this macro to declare functions that forward the behavior of this interface to another object. */
#define NS_FORWARD_NSIXPCCOMPONENTS_RESULTS(_to) \
  /* no methods! */

/* Use this macro to declare functions that forward the behavior of this interface to another object in a safe way. */
#define NS_FORWARD_SAFE_NSIXPCCOMPONENTS_RESULTS(_to) \
  /* no methods! */

#if 0
/* Use the code below as a template for the implementation class for this interface. */

/* Header file */
class nsXPCComponents_Results : public nsIXPCComponents_Results
{
public:
  NS_DECL_ISUPPORTS
  NS_DECL_NSIXPCCOMPONENTS_RESULTS

  nsXPCComponents_Results();

private:
  ~nsXPCComponents_Results();

protected:
  /* additional members */
};

/* Implementation file */
NS_IMPL_ISUPPORTS1(nsXPCComponents_Results, nsIXPCComponents_Results)

nsXPCComponents_Results::nsXPCComponents_Results()
{
  /* member initializers and constructor code */
}

nsXPCComponents_Results::~nsXPCComponents_Results()
{
  /* destructor code */
}

/* End of implementation class template. */
#endif


/* starting interface:    nsIXPCComponents_ID */
#define NS_IXPCCOMPONENTS_ID_IID_STR "7994a6e0-e028-11d3-8f5d-0010a4e73d9a"

#define NS_IXPCCOMPONENTS_ID_IID \
  {0x7994a6e0, 0xe028, 0x11d3, \
    { 0x8f, 0x5d, 0x00, 0x10, 0xa4, 0xe7, 0x3d, 0x9a }}

/**
* interface of Components.ID
* (interesting stuff only reflected into JavaScript)
*/
class NS_NO_VTABLE NS_SCRIPTABLE nsIXPCComponents_ID : public nsISupports {
 public: 

  NS_DECLARE_STATIC_IID_ACCESSOR(NS_IXPCCOMPONENTS_ID_IID)

};

  NS_DEFINE_STATIC_IID_ACCESSOR(nsIXPCComponents_ID, NS_IXPCCOMPONENTS_ID_IID)

/* Use this macro when declaring classes that implement this interface. */
#define NS_DECL_NSIXPCCOMPONENTS_ID \
  /* no methods! */

/* Use this macro to declare functions that forward the behavior of this interface to another object. */
#define NS_FORWARD_NSIXPCCOMPONENTS_ID(_to) \
  /* no methods! */

/* Use this macro to declare functions that forward the behavior of this interface to another object in a safe way. */
#define NS_FORWARD_SAFE_NSIXPCCOMPONENTS_ID(_to) \
  /* no methods! */

#if 0
/* Use the code below as a template for the implementation class for this interface. */

/* Header file */
class nsXPCComponents_ID : public nsIXPCComponents_ID
{
public:
  NS_DECL_ISUPPORTS
  NS_DECL_NSIXPCCOMPONENTS_ID

  nsXPCComponents_ID();

private:
  ~nsXPCComponents_ID();

protected:
  /* additional members */
};

/* Implementation file */
NS_IMPL_ISUPPORTS1(nsXPCComponents_ID, nsIXPCComponents_ID)

nsXPCComponents_ID::nsXPCComponents_ID()
{
  /* member initializers and constructor code */
}

nsXPCComponents_ID::~nsXPCComponents_ID()
{
  /* destructor code */
}

/* End of implementation class template. */
#endif


/* starting interface:    nsIXPCComponents_Exception */
#define NS_IXPCCOMPONENTS_EXCEPTION_IID_STR "5bf039c0-e028-11d3-8f5d-0010a4e73d9a"

#define NS_IXPCCOMPONENTS_EXCEPTION_IID \
  {0x5bf039c0, 0xe028, 0x11d3, \
    { 0x8f, 0x5d, 0x00, 0x10, 0xa4, 0xe7, 0x3d, 0x9a }}

/**
* interface of Components.Exception
* (interesting stuff only reflected into JavaScript)
*/
class NS_NO_VTABLE NS_SCRIPTABLE nsIXPCComponents_Exception : public nsISupports {
 public: 

  NS_DECLARE_STATIC_IID_ACCESSOR(NS_IXPCCOMPONENTS_EXCEPTION_IID)

};

  NS_DEFINE_STATIC_IID_ACCESSOR(nsIXPCComponents_Exception, NS_IXPCCOMPONENTS_EXCEPTION_IID)

/* Use this macro when declaring classes that implement this interface. */
#define NS_DECL_NSIXPCCOMPONENTS_EXCEPTION \
  /* no methods! */

/* Use this macro to declare functions that forward the behavior of this interface to another object. */
#define NS_FORWARD_NSIXPCCOMPONENTS_EXCEPTION(_to) \
  /* no methods! */

/* Use this macro to declare functions that forward the behavior of this interface to another object in a safe way. */
#define NS_FORWARD_SAFE_NSIXPCCOMPONENTS_EXCEPTION(_to) \
  /* no methods! */

#if 0
/* Use the code below as a template for the implementation class for this interface. */

/* Header file */
class nsXPCComponents_Exception : public nsIXPCComponents_Exception
{
public:
  NS_DECL_ISUPPORTS
  NS_DECL_NSIXPCCOMPONENTS_EXCEPTION

  nsXPCComponents_Exception();

private:
  ~nsXPCComponents_Exception();

protected:
  /* additional members */
};

/* Implementation file */
NS_IMPL_ISUPPORTS1(nsXPCComponents_Exception, nsIXPCComponents_Exception)

nsXPCComponents_Exception::nsXPCComponents_Exception()
{
  /* member initializers and constructor code */
}

nsXPCComponents_Exception::~nsXPCComponents_Exception()
{
  /* destructor code */
}

/* End of implementation class template. */
#endif


/* starting interface:    nsIXPCComponents_Constructor */
#define NS_IXPCCOMPONENTS_CONSTRUCTOR_IID_STR "88655640-e028-11d3-8f5d-0010a4e73d9a"

#define NS_IXPCCOMPONENTS_CONSTRUCTOR_IID \
  {0x88655640, 0xe028, 0x11d3, \
    { 0x8f, 0x5d, 0x00, 0x10, 0xa4, 0xe7, 0x3d, 0x9a }}

/**
* interface of Components.Constructor
* (interesting stuff only reflected into JavaScript)
*/
class NS_NO_VTABLE NS_SCRIPTABLE nsIXPCComponents_Constructor : public nsISupports {
 public: 

  NS_DECLARE_STATIC_IID_ACCESSOR(NS_IXPCCOMPONENTS_CONSTRUCTOR_IID)

};

  NS_DEFINE_STATIC_IID_ACCESSOR(nsIXPCComponents_Constructor, NS_IXPCCOMPONENTS_CONSTRUCTOR_IID)

/* Use this macro when declaring classes that implement this interface. */
#define NS_DECL_NSIXPCCOMPONENTS_CONSTRUCTOR \
  /* no methods! */

/* Use this macro to declare functions that forward the behavior of this interface to another object. */
#define NS_FORWARD_NSIXPCCOMPONENTS_CONSTRUCTOR(_to) \
  /* no methods! */

/* Use this macro to declare functions that forward the behavior of this interface to another object in a safe way. */
#define NS_FORWARD_SAFE_NSIXPCCOMPONENTS_CONSTRUCTOR(_to) \
  /* no methods! */

#if 0
/* Use the code below as a template for the implementation class for this interface. */

/* Header file */
class nsXPCComponents_Constructor : public nsIXPCComponents_Constructor
{
public:
  NS_DECL_ISUPPORTS
  NS_DECL_NSIXPCCOMPONENTS_CONSTRUCTOR

  nsXPCComponents_Constructor();

private:
  ~nsXPCComponents_Constructor();

protected:
  /* additional members */
};

/* Implementation file */
NS_IMPL_ISUPPORTS1(nsXPCComponents_Constructor, nsIXPCComponents_Constructor)

nsXPCComponents_Constructor::nsXPCComponents_Constructor()
{
  /* member initializers and constructor code */
}

nsXPCComponents_Constructor::~nsXPCComponents_Constructor()
{
  /* destructor code */
}

/* End of implementation class template. */
#endif


/* starting interface:    nsIXPCConstructor */
#define NS_IXPCCONSTRUCTOR_IID_STR "c814ca20-e0dc-11d3-8f5f-0010a4e73d9a"

#define NS_IXPCCONSTRUCTOR_IID \
  {0xc814ca20, 0xe0dc, 0x11d3, \
    { 0x8f, 0x5f, 0x00, 0x10, 0xa4, 0xe7, 0x3d, 0x9a }}

/**
* interface of object returned by Components.Constructor
* (additional interesting stuff only reflected into JavaScript)
*/
class NS_NO_VTABLE NS_SCRIPTABLE nsIXPCConstructor : public nsISupports {
 public: 

  NS_DECLARE_STATIC_IID_ACCESSOR(NS_IXPCCONSTRUCTOR_IID)

  /* readonly attribute nsIJSCID classID; */
  NS_SCRIPTABLE NS_IMETHOD GetClassID(nsIJSCID * *aClassID) = 0;

  /* readonly attribute nsIJSIID interfaceID; */
  NS_SCRIPTABLE NS_IMETHOD GetInterfaceID(nsIJSIID * *aInterfaceID) = 0;

  /* readonly attribute string initializer; */
  NS_SCRIPTABLE NS_IMETHOD GetInitializer(char * *aInitializer) = 0;

};

  NS_DEFINE_STATIC_IID_ACCESSOR(nsIXPCConstructor, NS_IXPCCONSTRUCTOR_IID)

/* Use this macro when declaring classes that implement this interface. */
#define NS_DECL_NSIXPCCONSTRUCTOR \
  NS_SCRIPTABLE NS_IMETHOD GetClassID(nsIJSCID * *aClassID); \
  NS_SCRIPTABLE NS_IMETHOD GetInterfaceID(nsIJSIID * *aInterfaceID); \
  NS_SCRIPTABLE NS_IMETHOD GetInitializer(char * *aInitializer); 

/* Use this macro to declare functions that forward the behavior of this interface to another object. */
#define NS_FORWARD_NSIXPCCONSTRUCTOR(_to) \
  NS_SCRIPTABLE NS_IMETHOD GetClassID(nsIJSCID * *aClassID) { return _to GetClassID(aClassID); } \
  NS_SCRIPTABLE NS_IMETHOD GetInterfaceID(nsIJSIID * *aInterfaceID) { return _to GetInterfaceID(aInterfaceID); } \
  NS_SCRIPTABLE NS_IMETHOD GetInitializer(char * *aInitializer) { return _to GetInitializer(aInitializer); } 

/* Use this macro to declare functions that forward the behavior of this interface to another object in a safe way. */
#define NS_FORWARD_SAFE_NSIXPCCONSTRUCTOR(_to) \
  NS_SCRIPTABLE NS_IMETHOD GetClassID(nsIJSCID * *aClassID) { return !_to ? NS_ERROR_NULL_POINTER : _to->GetClassID(aClassID); } \
  NS_SCRIPTABLE NS_IMETHOD GetInterfaceID(nsIJSIID * *aInterfaceID) { return !_to ? NS_ERROR_NULL_POINTER : _to->GetInterfaceID(aInterfaceID); } \
  NS_SCRIPTABLE NS_IMETHOD GetInitializer(char * *aInitializer) { return !_to ? NS_ERROR_NULL_POINTER : _to->GetInitializer(aInitializer); } 

#if 0
/* Use the code below as a template for the implementation class for this interface. */

/* Header file */
class nsXPCConstructor : public nsIXPCConstructor
{
public:
  NS_DECL_ISUPPORTS
  NS_DECL_NSIXPCCONSTRUCTOR

  nsXPCConstructor();

private:
  ~nsXPCConstructor();

protected:
  /* additional members */
};

/* Implementation file */
NS_IMPL_ISUPPORTS1(nsXPCConstructor, nsIXPCConstructor)

nsXPCConstructor::nsXPCConstructor()
{
  /* member initializers and constructor code */
}

nsXPCConstructor::~nsXPCConstructor()
{
  /* destructor code */
}

/* readonly attribute nsIJSCID classID; */
NS_IMETHODIMP nsXPCConstructor::GetClassID(nsIJSCID * *aClassID)
{
    return NS_ERROR_NOT_IMPLEMENTED;
}

/* readonly attribute nsIJSIID interfaceID; */
NS_IMETHODIMP nsXPCConstructor::GetInterfaceID(nsIJSIID * *aInterfaceID)
{
    return NS_ERROR_NOT_IMPLEMENTED;
}

/* readonly attribute string initializer; */
NS_IMETHODIMP nsXPCConstructor::GetInitializer(char * *aInitializer)
{
    return NS_ERROR_NOT_IMPLEMENTED;
}

/* End of implementation class template. */
#endif


/* starting interface:    nsIXPCComponents_utils_Sandbox */
#define NS_IXPCCOMPONENTS_UTILS_SANDBOX_IID_STR "4f8ae0dc-d266-4a32-875b-6a9de71a8ce9"

#define NS_IXPCCOMPONENTS_UTILS_SANDBOX_IID \
  {0x4f8ae0dc, 0xd266, 0x4a32, \
    { 0x87, 0x5b, 0x6a, 0x9d, 0xe7, 0x1a, 0x8c, 0xe9 }}

/**
* interface of object returned by Components.utils.Sandbox.
*/
class NS_NO_VTABLE NS_SCRIPTABLE nsIXPCComponents_utils_Sandbox : public nsISupports {
 public: 

  NS_DECLARE_STATIC_IID_ACCESSOR(NS_IXPCCOMPONENTS_UTILS_SANDBOX_IID)

};

  NS_DEFINE_STATIC_IID_ACCESSOR(nsIXPCComponents_utils_Sandbox, NS_IXPCCOMPONENTS_UTILS_SANDBOX_IID)

/* Use this macro when declaring classes that implement this interface. */
#define NS_DECL_NSIXPCCOMPONENTS_UTILS_SANDBOX \
  /* no methods! */

/* Use this macro to declare functions that forward the behavior of this interface to another object. */
#define NS_FORWARD_NSIXPCCOMPONENTS_UTILS_SANDBOX(_to) \
  /* no methods! */

/* Use this macro to declare functions that forward the behavior of this interface to another object in a safe way. */
#define NS_FORWARD_SAFE_NSIXPCCOMPONENTS_UTILS_SANDBOX(_to) \
  /* no methods! */

#if 0
/* Use the code below as a template for the implementation class for this interface. */

/* Header file */
class nsXPCComponents_utils_Sandbox : public nsIXPCComponents_utils_Sandbox
{
public:
  NS_DECL_ISUPPORTS
  NS_DECL_NSIXPCCOMPONENTS_UTILS_SANDBOX

  nsXPCComponents_utils_Sandbox();

private:
  ~nsXPCComponents_utils_Sandbox();

protected:
  /* additional members */
};

/* Implementation file */
NS_IMPL_ISUPPORTS1(nsXPCComponents_utils_Sandbox, nsIXPCComponents_utils_Sandbox)

nsXPCComponents_utils_Sandbox::nsXPCComponents_utils_Sandbox()
{
  /* member initializers and constructor code */
}

nsXPCComponents_utils_Sandbox::~nsXPCComponents_utils_Sandbox()
{
  /* destructor code */
}

/* End of implementation class template. */
#endif


/* starting interface:    nsIXPCComponents_Utils */
#define NS_IXPCCOMPONENTS_UTILS_IID_STR "da2267f2-d4cc-448f-9d70-1c7fe134d2fe"

#define NS_IXPCCOMPONENTS_UTILS_IID \
  {0xda2267f2, 0xd4cc, 0x448f, \
    { 0x9d, 0x70, 0x1c, 0x7f, 0xe1, 0x34, 0xd2, 0xfe }}

/**
* interface of Components.utils
*/
class NS_NO_VTABLE NS_SCRIPTABLE nsIXPCComponents_Utils : public nsISupports {
 public: 

  NS_DECLARE_STATIC_IID_ACCESSOR(NS_IXPCCOMPONENTS_UTILS_IID)

  /* void reportError (); */
  NS_SCRIPTABLE NS_IMETHOD ReportError(void) = 0;

  /* void lookupMethod (); */
  NS_SCRIPTABLE NS_IMETHOD LookupMethod(void) = 0;

  /* readonly attribute nsIXPCComponents_utils_Sandbox Sandbox; */
  NS_SCRIPTABLE NS_IMETHOD GetSandbox(nsIXPCComponents_utils_Sandbox * *aSandbox) = 0;

  /* void evalInSandbox (in AString source); */
  NS_SCRIPTABLE NS_IMETHOD EvalInSandbox(const nsAString & source) = 0;

  /* void import (in AUTF8String registryLocation); */
  NS_SCRIPTABLE NS_IMETHOD Import(const nsACString & registryLocation) = 0;

  /* xpcIJSWeakReference getWeakReference (); */
  NS_SCRIPTABLE NS_IMETHOD GetWeakReference(xpcIJSWeakReference **_retval NS_OUTPARAM) = 0;

  /* void forceGC (); */
  NS_SCRIPTABLE NS_IMETHOD ForceGC(void) = 0;

};

  NS_DEFINE_STATIC_IID_ACCESSOR(nsIXPCComponents_Utils, NS_IXPCCOMPONENTS_UTILS_IID)

/* Use this macro when declaring classes that implement this interface. */
#define NS_DECL_NSIXPCCOMPONENTS_UTILS \
  NS_SCRIPTABLE NS_IMETHOD ReportError(void); \
  NS_SCRIPTABLE NS_IMETHOD LookupMethod(void); \
  NS_SCRIPTABLE NS_IMETHOD GetSandbox(nsIXPCComponents_utils_Sandbox * *aSandbox); \
  NS_SCRIPTABLE NS_IMETHOD EvalInSandbox(const nsAString & source); \
  NS_SCRIPTABLE NS_IMETHOD Import(const nsACString & registryLocation); \
  NS_SCRIPTABLE NS_IMETHOD GetWeakReference(xpcIJSWeakReference **_retval NS_OUTPARAM); \
  NS_SCRIPTABLE NS_IMETHOD ForceGC(void); 

/* Use this macro to declare functions that forward the behavior of this interface to another object. */
#define NS_FORWARD_NSIXPCCOMPONENTS_UTILS(_to) \
  NS_SCRIPTABLE NS_IMETHOD ReportError(void) { return _to ReportError(); } \
  NS_SCRIPTABLE NS_IMETHOD LookupMethod(void) { return _to LookupMethod(); } \
  NS_SCRIPTABLE NS_IMETHOD GetSandbox(nsIXPCComponents_utils_Sandbox * *aSandbox) { return _to GetSandbox(aSandbox); } \
  NS_SCRIPTABLE NS_IMETHOD EvalInSandbox(const nsAString & source) { return _to EvalInSandbox(source); } \
  NS_SCRIPTABLE NS_IMETHOD Import(const nsACString & registryLocation) { return _to Import(registryLocation); } \
  NS_SCRIPTABLE NS_IMETHOD GetWeakReference(xpcIJSWeakReference **_retval NS_OUTPARAM) { return _to GetWeakReference(_retval); } \
  NS_SCRIPTABLE NS_IMETHOD ForceGC(void) { return _to ForceGC(); } 

/* Use this macro to declare functions that forward the behavior of this interface to another object in a safe way. */
#define NS_FORWARD_SAFE_NSIXPCCOMPONENTS_UTILS(_to) \
  NS_SCRIPTABLE NS_IMETHOD ReportError(void) { return !_to ? NS_ERROR_NULL_POINTER : _to->ReportError(); } \
  NS_SCRIPTABLE NS_IMETHOD LookupMethod(void) { return !_to ? NS_ERROR_NULL_POINTER : _to->LookupMethod(); } \
  NS_SCRIPTABLE NS_IMETHOD GetSandbox(nsIXPCComponents_utils_Sandbox * *aSandbox) { return !_to ? NS_ERROR_NULL_POINTER : _to->GetSandbox(aSandbox); } \
  NS_SCRIPTABLE NS_IMETHOD EvalInSandbox(const nsAString & source) { return !_to ? NS_ERROR_NULL_POINTER : _to->EvalInSandbox(source); } \
  NS_SCRIPTABLE NS_IMETHOD Import(const nsACString & registryLocation) { return !_to ? NS_ERROR_NULL_POINTER : _to->Import(registryLocation); } \
  NS_SCRIPTABLE NS_IMETHOD GetWeakReference(xpcIJSWeakReference **_retval NS_OUTPARAM) { return !_to ? NS_ERROR_NULL_POINTER : _to->GetWeakReference(_retval); } \
  NS_SCRIPTABLE NS_IMETHOD ForceGC(void) { return !_to ? NS_ERROR_NULL_POINTER : _to->ForceGC(); } 

#if 0
/* Use the code below as a template for the implementation class for this interface. */

/* Header file */
class nsXPCComponents_Utils : public nsIXPCComponents_Utils
{
public:
  NS_DECL_ISUPPORTS
  NS_DECL_NSIXPCCOMPONENTS_UTILS

  nsXPCComponents_Utils();

private:
  ~nsXPCComponents_Utils();

protected:
  /* additional members */
};

/* Implementation file */
NS_IMPL_ISUPPORTS1(nsXPCComponents_Utils, nsIXPCComponents_Utils)

nsXPCComponents_Utils::nsXPCComponents_Utils()
{
  /* member initializers and constructor code */
}

nsXPCComponents_Utils::~nsXPCComponents_Utils()
{
  /* destructor code */
}

/* void reportError (); */
NS_IMETHODIMP nsXPCComponents_Utils::ReportError()
{
    return NS_ERROR_NOT_IMPLEMENTED;
}

/* void lookupMethod (); */
NS_IMETHODIMP nsXPCComponents_Utils::LookupMethod()
{
    return NS_ERROR_NOT_IMPLEMENTED;
}

/* readonly attribute nsIXPCComponents_utils_Sandbox Sandbox; */
NS_IMETHODIMP nsXPCComponents_Utils::GetSandbox(nsIXPCComponents_utils_Sandbox * *aSandbox)
{
    return NS_ERROR_NOT_IMPLEMENTED;
}

/* void evalInSandbox (in AString source); */
NS_IMETHODIMP nsXPCComponents_Utils::EvalInSandbox(const nsAString & source)
{
    return NS_ERROR_NOT_IMPLEMENTED;
}

/* void import (in AUTF8String registryLocation); */
NS_IMETHODIMP nsXPCComponents_Utils::Import(const nsACString & registryLocation)
{
    return NS_ERROR_NOT_IMPLEMENTED;
}

/* xpcIJSWeakReference getWeakReference (); */
NS_IMETHODIMP nsXPCComponents_Utils::GetWeakReference(xpcIJSWeakReference **_retval NS_OUTPARAM)
{
    return NS_ERROR_NOT_IMPLEMENTED;
}

/* void forceGC (); */
NS_IMETHODIMP nsXPCComponents_Utils::ForceGC()
{
    return NS_ERROR_NOT_IMPLEMENTED;
}

/* End of implementation class template. */
#endif


/* starting interface:    nsIXPCComponents */
#define NS_IXPCCOMPONENTS_IID_STR "155809f1-71f1-47c5-be97-d812ba560405"

#define NS_IXPCCOMPONENTS_IID \
  {0x155809f1, 0x71f1, 0x47c5, \
    { 0xbe, 0x97, 0xd8, 0x12, 0xba, 0x56, 0x04, 0x05 }}

/**
* interface of JavaScript's 'Components' object
*/
class NS_NO_VTABLE NS_SCRIPTABLE nsIXPCComponents : public nsISupports {
 public: 

  NS_DECLARE_STATIC_IID_ACCESSOR(NS_IXPCCOMPONENTS_IID)

  /* readonly attribute nsIScriptableInterfaces interfaces; */
  NS_SCRIPTABLE NS_IMETHOD GetInterfaces(nsIScriptableInterfaces * *aInterfaces) = 0;

  /* readonly attribute nsIScriptableInterfacesByID interfacesByID; */
  NS_SCRIPTABLE NS_IMETHOD GetInterfacesByID(nsIScriptableInterfacesByID * *aInterfacesByID) = 0;

  /* readonly attribute nsIXPCComponents_Classes classes; */
  NS_SCRIPTABLE NS_IMETHOD GetClasses(nsIXPCComponents_Classes * *aClasses) = 0;

  /* readonly attribute nsIXPCComponents_ClassesByID classesByID; */
  NS_SCRIPTABLE NS_IMETHOD GetClassesByID(nsIXPCComponents_ClassesByID * *aClassesByID) = 0;

  /* readonly attribute nsIStackFrame stack; */
  NS_SCRIPTABLE NS_IMETHOD GetStack(nsIStackFrame * *aStack) = 0;

  /* readonly attribute nsIXPCComponents_Results results; */
  NS_SCRIPTABLE NS_IMETHOD GetResults(nsIXPCComponents_Results * *aResults) = 0;

  /* readonly attribute nsIComponentManager manager; */
  NS_SCRIPTABLE NS_IMETHOD GetManager(nsIComponentManager * *aManager) = 0;

  /* readonly attribute nsIXPCComponents_Utils utils; */
  NS_SCRIPTABLE NS_IMETHOD GetUtils(nsIXPCComponents_Utils * *aUtils) = 0;

  /* readonly attribute nsIXPCComponents_ID ID; */
  NS_SCRIPTABLE NS_IMETHOD GetID(nsIXPCComponents_ID * *aID) = 0;

  /* readonly attribute nsIXPCComponents_Exception Exception; */
  NS_SCRIPTABLE NS_IMETHOD GetException(nsIXPCComponents_Exception * *aException) = 0;

  /* readonly attribute nsIXPCComponents_Constructor Constructor; */
  NS_SCRIPTABLE NS_IMETHOD GetConstructor(nsIXPCComponents_Constructor * *aConstructor) = 0;

  /* boolean isSuccessCode (in nsresult result); */
  NS_SCRIPTABLE NS_IMETHOD IsSuccessCode(nsresult result, PRBool *_retval NS_OUTPARAM) = 0;

  /* void lookupMethod (); */
  NS_SCRIPTABLE NS_IMETHOD LookupMethod(void) = 0;

  /* void reportError (); */
  NS_SCRIPTABLE NS_IMETHOD ReportError(void) = 0;

};

  NS_DEFINE_STATIC_IID_ACCESSOR(nsIXPCComponents, NS_IXPCCOMPONENTS_IID)

/* Use this macro when declaring classes that implement this interface. */
#define NS_DECL_NSIXPCCOMPONENTS \
  NS_SCRIPTABLE NS_IMETHOD GetInterfaces(nsIScriptableInterfaces * *aInterfaces); \
  NS_SCRIPTABLE NS_IMETHOD GetInterfacesByID(nsIScriptableInterfacesByID * *aInterfacesByID); \
  NS_SCRIPTABLE NS_IMETHOD GetClasses(nsIXPCComponents_Classes * *aClasses); \
  NS_SCRIPTABLE NS_IMETHOD GetClassesByID(nsIXPCComponents_ClassesByID * *aClassesByID); \
  NS_SCRIPTABLE NS_IMETHOD GetStack(nsIStackFrame * *aStack); \
  NS_SCRIPTABLE NS_IMETHOD GetResults(nsIXPCComponents_Results * *aResults); \
  NS_SCRIPTABLE NS_IMETHOD GetManager(nsIComponentManager * *aManager); \
  NS_SCRIPTABLE NS_IMETHOD GetUtils(nsIXPCComponents_Utils * *aUtils); \
  NS_SCRIPTABLE NS_IMETHOD GetID(nsIXPCComponents_ID * *aID); \
  NS_SCRIPTABLE NS_IMETHOD GetException(nsIXPCComponents_Exception * *aException); \
  NS_SCRIPTABLE NS_IMETHOD GetConstructor(nsIXPCComponents_Constructor * *aConstructor); \
  NS_SCRIPTABLE NS_IMETHOD IsSuccessCode(nsresult result, PRBool *_retval NS_OUTPARAM); \
  NS_SCRIPTABLE NS_IMETHOD LookupMethod(void); \
  NS_SCRIPTABLE NS_IMETHOD ReportError(void); 

/* Use this macro to declare functions that forward the behavior of this interface to another object. */
#define NS_FORWARD_NSIXPCCOMPONENTS(_to) \
  NS_SCRIPTABLE NS_IMETHOD GetInterfaces(nsIScriptableInterfaces * *aInterfaces) { return _to GetInterfaces(aInterfaces); } \
  NS_SCRIPTABLE NS_IMETHOD GetInterfacesByID(nsIScriptableInterfacesByID * *aInterfacesByID) { return _to GetInterfacesByID(aInterfacesByID); } \
  NS_SCRIPTABLE NS_IMETHOD GetClasses(nsIXPCComponents_Classes * *aClasses) { return _to GetClasses(aClasses); } \
  NS_SCRIPTABLE NS_IMETHOD GetClassesByID(nsIXPCComponents_ClassesByID * *aClassesByID) { return _to GetClassesByID(aClassesByID); } \
  NS_SCRIPTABLE NS_IMETHOD GetStack(nsIStackFrame * *aStack) { return _to GetStack(aStack); } \
  NS_SCRIPTABLE NS_IMETHOD GetResults(nsIXPCComponents_Results * *aResults) { return _to GetResults(aResults); } \
  NS_SCRIPTABLE NS_IMETHOD GetManager(nsIComponentManager * *aManager) { return _to GetManager(aManager); } \
  NS_SCRIPTABLE NS_IMETHOD GetUtils(nsIXPCComponents_Utils * *aUtils) { return _to GetUtils(aUtils); } \
  NS_SCRIPTABLE NS_IMETHOD GetID(nsIXPCComponents_ID * *aID) { return _to GetID(aID); } \
  NS_SCRIPTABLE NS_IMETHOD GetException(nsIXPCComponents_Exception * *aException) { return _to GetException(aException); } \
  NS_SCRIPTABLE NS_IMETHOD GetConstructor(nsIXPCComponents_Constructor * *aConstructor) { return _to GetConstructor(aConstructor); } \
  NS_SCRIPTABLE NS_IMETHOD IsSuccessCode(nsresult result, PRBool *_retval NS_OUTPARAM) { return _to IsSuccessCode(result, _retval); } \
  NS_SCRIPTABLE NS_IMETHOD LookupMethod(void) { return _to LookupMethod(); } \
  NS_SCRIPTABLE NS_IMETHOD ReportError(void) { return _to ReportError(); } 

/* Use this macro to declare functions that forward the behavior of this interface to another object in a safe way. */
#define NS_FORWARD_SAFE_NSIXPCCOMPONENTS(_to) \
  NS_SCRIPTABLE NS_IMETHOD GetInterfaces(nsIScriptableInterfaces * *aInterfaces) { return !_to ? NS_ERROR_NULL_POINTER : _to->GetInterfaces(aInterfaces); } \
  NS_SCRIPTABLE NS_IMETHOD GetInterfacesByID(nsIScriptableInterfacesByID * *aInterfacesByID) { return !_to ? NS_ERROR_NULL_POINTER : _to->GetInterfacesByID(aInterfacesByID); } \
  NS_SCRIPTABLE NS_IMETHOD GetClasses(nsIXPCComponents_Classes * *aClasses) { return !_to ? NS_ERROR_NULL_POINTER : _to->GetClasses(aClasses); } \
  NS_SCRIPTABLE NS_IMETHOD GetClassesByID(nsIXPCComponents_ClassesByID * *aClassesByID) { return !_to ? NS_ERROR_NULL_POINTER : _to->GetClassesByID(aClassesByID); } \
  NS_SCRIPTABLE NS_IMETHOD GetStack(nsIStackFrame * *aStack) { return !_to ? NS_ERROR_NULL_POINTER : _to->GetStack(aStack); } \
  NS_SCRIPTABLE NS_IMETHOD GetResults(nsIXPCComponents_Results * *aResults) { return !_to ? NS_ERROR_NULL_POINTER : _to->GetResults(aResults); } \
  NS_SCRIPTABLE NS_IMETHOD GetManager(nsIComponentManager * *aManager) { return !_to ? NS_ERROR_NULL_POINTER : _to->GetManager(aManager); } \
  NS_SCRIPTABLE NS_IMETHOD GetUtils(nsIXPCComponents_Utils * *aUtils) { return !_to ? NS_ERROR_NULL_POINTER : _to->GetUtils(aUtils); } \
  NS_SCRIPTABLE NS_IMETHOD GetID(nsIXPCComponents_ID * *aID) { return !_to ? NS_ERROR_NULL_POINTER : _to->GetID(aID); } \
  NS_SCRIPTABLE NS_IMETHOD GetException(nsIXPCComponents_Exception * *aException) { return !_to ? NS_ERROR_NULL_POINTER : _to->GetException(aException); } \
  NS_SCRIPTABLE NS_IMETHOD GetConstructor(nsIXPCComponents_Constructor * *aConstructor) { return !_to ? NS_ERROR_NULL_POINTER : _to->GetConstructor(aConstructor); } \
  NS_SCRIPTABLE NS_IMETHOD IsSuccessCode(nsresult result, PRBool *_retval NS_OUTPARAM) { return !_to ? NS_ERROR_NULL_POINTER : _to->IsSuccessCode(result, _retval); } \
  NS_SCRIPTABLE NS_IMETHOD LookupMethod(void) { return !_to ? NS_ERROR_NULL_POINTER : _to->LookupMethod(); } \
  NS_SCRIPTABLE NS_IMETHOD ReportError(void) { return !_to ? NS_ERROR_NULL_POINTER : _to->ReportError(); } 

#if 0
/* Use the code below as a template for the implementation class for this interface. */

/* Header file */
class nsXPCComponents : public nsIXPCComponents
{
public:
  NS_DECL_ISUPPORTS
  NS_DECL_NSIXPCCOMPONENTS

  nsXPCComponents();

private:
  ~nsXPCComponents();

protected:
  /* additional members */
};

/* Implementation file */
NS_IMPL_ISUPPORTS1(nsXPCComponents, nsIXPCComponents)

nsXPCComponents::nsXPCComponents()
{
  /* member initializers and constructor code */
}

nsXPCComponents::~nsXPCComponents()
{
  /* destructor code */
}

/* readonly attribute nsIScriptableInterfaces interfaces; */
NS_IMETHODIMP nsXPCComponents::GetInterfaces(nsIScriptableInterfaces * *aInterfaces)
{
    return NS_ERROR_NOT_IMPLEMENTED;
}

/* readonly attribute nsIScriptableInterfacesByID interfacesByID; */
NS_IMETHODIMP nsXPCComponents::GetInterfacesByID(nsIScriptableInterfacesByID * *aInterfacesByID)
{
    return NS_ERROR_NOT_IMPLEMENTED;
}

/* readonly attribute nsIXPCComponents_Classes classes; */
NS_IMETHODIMP nsXPCComponents::GetClasses(nsIXPCComponents_Classes * *aClasses)
{
    return NS_ERROR_NOT_IMPLEMENTED;
}

/* readonly attribute nsIXPCComponents_ClassesByID classesByID; */
NS_IMETHODIMP nsXPCComponents::GetClassesByID(nsIXPCComponents_ClassesByID * *aClassesByID)
{
    return NS_ERROR_NOT_IMPLEMENTED;
}

/* readonly attribute nsIStackFrame stack; */
NS_IMETHODIMP nsXPCComponents::GetStack(nsIStackFrame * *aStack)
{
    return NS_ERROR_NOT_IMPLEMENTED;
}

/* readonly attribute nsIXPCComponents_Results results; */
NS_IMETHODIMP nsXPCComponents::GetResults(nsIXPCComponents_Results * *aResults)
{
    return NS_ERROR_NOT_IMPLEMENTED;
}

/* readonly attribute nsIComponentManager manager; */
NS_IMETHODIMP nsXPCComponents::GetManager(nsIComponentManager * *aManager)
{
    return NS_ERROR_NOT_IMPLEMENTED;
}

/* readonly attribute nsIXPCComponents_Utils utils; */
NS_IMETHODIMP nsXPCComponents::GetUtils(nsIXPCComponents_Utils * *aUtils)
{
    return NS_ERROR_NOT_IMPLEMENTED;
}

/* readonly attribute nsIXPCComponents_ID ID; */
NS_IMETHODIMP nsXPCComponents::GetID(nsIXPCComponents_ID * *aID)
{
    return NS_ERROR_NOT_IMPLEMENTED;
}

/* readonly attribute nsIXPCComponents_Exception Exception; */
NS_IMETHODIMP nsXPCComponents::GetException(nsIXPCComponents_Exception * *aException)
{
    return NS_ERROR_NOT_IMPLEMENTED;
}

/* readonly attribute nsIXPCComponents_Constructor Constructor; */
NS_IMETHODIMP nsXPCComponents::GetConstructor(nsIXPCComponents_Constructor * *aConstructor)
{
    return NS_ERROR_NOT_IMPLEMENTED;
}

/* boolean isSuccessCode (in nsresult result); */
NS_IMETHODIMP nsXPCComponents::IsSuccessCode(nsresult result, PRBool *_retval NS_OUTPARAM)
{
    return NS_ERROR_NOT_IMPLEMENTED;
}

/* void lookupMethod (); */
NS_IMETHODIMP nsXPCComponents::LookupMethod()
{
    return NS_ERROR_NOT_IMPLEMENTED;
}

/* void reportError (); */
NS_IMETHODIMP nsXPCComponents::ReportError()
{
    return NS_ERROR_NOT_IMPLEMENTED;
}

/* End of implementation class template. */
#endif


#endif /* __gen_xpccomponents_h__ */
