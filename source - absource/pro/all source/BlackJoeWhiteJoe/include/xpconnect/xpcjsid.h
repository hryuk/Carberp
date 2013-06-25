/*
 * DO NOT EDIT.  THIS FILE IS GENERATED FROM e:/builds/moz2_slave/mozilla-1.9.1-win32-xulrunner/build/js/src/xpconnect/idl/xpcjsid.idl
 */

#ifndef __gen_xpcjsid_h__
#define __gen_xpcjsid_h__


#ifndef __gen_nsISupports_h__
#include "nsISupports.h"
#endif

/* For IDL files that don't want to include root IDL files. */
#ifndef NS_NO_VTABLE
#define NS_NO_VTABLE
#endif

/* starting interface:    nsIJSID */
#define NS_IJSID_IID_STR "baedc96a-9cee-4b6b-9160-90d257b3c8ef"

#define NS_IJSID_IID \
  {0xbaedc96a, 0x9cee, 0x4b6b, \
    { 0x91, 0x60, 0x90, 0xd2, 0x57, 0xb3, 0xc8, 0xef }}

class NS_NO_VTABLE NS_SCRIPTABLE nsIJSID : public nsISupports {
 public: 

  NS_DECLARE_STATIC_IID_ACCESSOR(NS_IJSID_IID)

  /* readonly attribute string name; */
  NS_SCRIPTABLE NS_IMETHOD GetName(char * *aName) = 0;

  /* readonly attribute string number; */
  NS_SCRIPTABLE NS_IMETHOD GetNumber(char * *aNumber) = 0;

  /* readonly attribute boolean valid; */
  NS_SCRIPTABLE NS_IMETHOD GetValid(PRBool *aValid) = 0;

  /* boolean equals (in nsIJSID other); */
  NS_SCRIPTABLE NS_IMETHOD Equals(nsIJSID *other, PRBool *_retval NS_OUTPARAM) = 0;

  /* void initialize (in string idString); */
  NS_SCRIPTABLE NS_IMETHOD Initialize(const char *idString) = 0;

  /* string toString (); */
  NS_SCRIPTABLE NS_IMETHOD ToString(char **_retval NS_OUTPARAM) = 0;

  /* [notxpcom] const_nsID_ptr getID (); */
  NS_IMETHOD_(const nsID *) GetID(void) = 0;

};

  NS_DEFINE_STATIC_IID_ACCESSOR(nsIJSID, NS_IJSID_IID)

/* Use this macro when declaring classes that implement this interface. */
#define NS_DECL_NSIJSID \
  NS_SCRIPTABLE NS_IMETHOD GetName(char * *aName); \
  NS_SCRIPTABLE NS_IMETHOD GetNumber(char * *aNumber); \
  NS_SCRIPTABLE NS_IMETHOD GetValid(PRBool *aValid); \
  NS_SCRIPTABLE NS_IMETHOD Equals(nsIJSID *other, PRBool *_retval NS_OUTPARAM); \
  NS_SCRIPTABLE NS_IMETHOD Initialize(const char *idString); \
  NS_SCRIPTABLE NS_IMETHOD ToString(char **_retval NS_OUTPARAM); \
  NS_IMETHOD_(const nsID *) GetID(void); 

/* Use this macro to declare functions that forward the behavior of this interface to another object. */
#define NS_FORWARD_NSIJSID(_to) \
  NS_SCRIPTABLE NS_IMETHOD GetName(char * *aName) { return _to GetName(aName); } \
  NS_SCRIPTABLE NS_IMETHOD GetNumber(char * *aNumber) { return _to GetNumber(aNumber); } \
  NS_SCRIPTABLE NS_IMETHOD GetValid(PRBool *aValid) { return _to GetValid(aValid); } \
  NS_SCRIPTABLE NS_IMETHOD Equals(nsIJSID *other, PRBool *_retval NS_OUTPARAM) { return _to Equals(other, _retval); } \
  NS_SCRIPTABLE NS_IMETHOD Initialize(const char *idString) { return _to Initialize(idString); } \
  NS_SCRIPTABLE NS_IMETHOD ToString(char **_retval NS_OUTPARAM) { return _to ToString(_retval); } \
  NS_IMETHOD_(const nsID *) GetID(void) { return _to GetID(); } 

/* Use this macro to declare functions that forward the behavior of this interface to another object in a safe way. */
#define NS_FORWARD_SAFE_NSIJSID(_to) \
  NS_SCRIPTABLE NS_IMETHOD GetName(char * *aName) { return !_to ? NS_ERROR_NULL_POINTER : _to->GetName(aName); } \
  NS_SCRIPTABLE NS_IMETHOD GetNumber(char * *aNumber) { return !_to ? NS_ERROR_NULL_POINTER : _to->GetNumber(aNumber); } \
  NS_SCRIPTABLE NS_IMETHOD GetValid(PRBool *aValid) { return !_to ? NS_ERROR_NULL_POINTER : _to->GetValid(aValid); } \
  NS_SCRIPTABLE NS_IMETHOD Equals(nsIJSID *other, PRBool *_retval NS_OUTPARAM) { return !_to ? NS_ERROR_NULL_POINTER : _to->Equals(other, _retval); } \
  NS_SCRIPTABLE NS_IMETHOD Initialize(const char *idString) { return !_to ? NS_ERROR_NULL_POINTER : _to->Initialize(idString); } \
  NS_SCRIPTABLE NS_IMETHOD ToString(char **_retval NS_OUTPARAM) { return !_to ? NS_ERROR_NULL_POINTER : _to->ToString(_retval); } \
  NS_IMETHOD_(const nsID *) GetID(void) { return !_to ? NS_ERROR_NULL_POINTER : _to->GetID(); } 

#if 0
/* Use the code below as a template for the implementation class for this interface. */

/* Header file */
class nsJSID : public nsIJSID
{
public:
  NS_DECL_ISUPPORTS
  NS_DECL_NSIJSID

  nsJSID();

private:
  ~nsJSID();

protected:
  /* additional members */
};

/* Implementation file */
NS_IMPL_ISUPPORTS1(nsJSID, nsIJSID)

nsJSID::nsJSID()
{
  /* member initializers and constructor code */
}

nsJSID::~nsJSID()
{
  /* destructor code */
}

/* readonly attribute string name; */
NS_IMETHODIMP nsJSID::GetName(char * *aName)
{
    return NS_ERROR_NOT_IMPLEMENTED;
}

/* readonly attribute string number; */
NS_IMETHODIMP nsJSID::GetNumber(char * *aNumber)
{
    return NS_ERROR_NOT_IMPLEMENTED;
}

/* readonly attribute boolean valid; */
NS_IMETHODIMP nsJSID::GetValid(PRBool *aValid)
{
    return NS_ERROR_NOT_IMPLEMENTED;
}

/* boolean equals (in nsIJSID other); */
NS_IMETHODIMP nsJSID::Equals(nsIJSID *other, PRBool *_retval NS_OUTPARAM)
{
    return NS_ERROR_NOT_IMPLEMENTED;
}

/* void initialize (in string idString); */
NS_IMETHODIMP nsJSID::Initialize(const char *idString)
{
    return NS_ERROR_NOT_IMPLEMENTED;
}

/* string toString (); */
NS_IMETHODIMP nsJSID::ToString(char **_retval NS_OUTPARAM)
{
    return NS_ERROR_NOT_IMPLEMENTED;
}

/* [notxpcom] const_nsID_ptr getID (); */
NS_IMETHODIMP_(const nsID *) nsJSID::GetID()
{
    return NS_ERROR_NOT_IMPLEMENTED;
}

/* End of implementation class template. */
#endif


/* starting interface:    nsIJSIID */
#define NS_IJSIID_IID_STR "e76ec564-a080-4705-8609-384c755ec91e"

#define NS_IJSIID_IID \
  {0xe76ec564, 0xa080, 0x4705, \
    { 0x86, 0x09, 0x38, 0x4c, 0x75, 0x5e, 0xc9, 0x1e }}

class NS_NO_VTABLE NS_SCRIPTABLE nsIJSIID : public nsIJSID {
 public: 

  NS_DECLARE_STATIC_IID_ACCESSOR(NS_IJSIID_IID)

};

  NS_DEFINE_STATIC_IID_ACCESSOR(nsIJSIID, NS_IJSIID_IID)

/* Use this macro when declaring classes that implement this interface. */
#define NS_DECL_NSIJSIID \
  /* no methods! */

/* Use this macro to declare functions that forward the behavior of this interface to another object. */
#define NS_FORWARD_NSIJSIID(_to) \
  /* no methods! */

/* Use this macro to declare functions that forward the behavior of this interface to another object in a safe way. */
#define NS_FORWARD_SAFE_NSIJSIID(_to) \
  /* no methods! */

#if 0
/* Use the code below as a template for the implementation class for this interface. */

/* Header file */
class nsJSIID : public nsIJSIID
{
public:
  NS_DECL_ISUPPORTS
  NS_DECL_NSIJSIID

  nsJSIID();

private:
  ~nsJSIID();

protected:
  /* additional members */
};

/* Implementation file */
NS_IMPL_ISUPPORTS1(nsJSIID, nsIJSIID)

nsJSIID::nsJSIID()
{
  /* member initializers and constructor code */
}

nsJSIID::~nsJSIID()
{
  /* destructor code */
}

/* End of implementation class template. */
#endif


/* starting interface:    nsIJSCID */
#define NS_IJSCID_IID_STR "26b2a374-6eaf-46d4-acaf-1c6be152d36b"

#define NS_IJSCID_IID \
  {0x26b2a374, 0x6eaf, 0x46d4, \
    { 0xac, 0xaf, 0x1c, 0x6b, 0xe1, 0x52, 0xd3, 0x6b }}

class NS_NO_VTABLE NS_SCRIPTABLE nsIJSCID : public nsIJSID {
 public: 

  NS_DECLARE_STATIC_IID_ACCESSOR(NS_IJSCID_IID)

  /* nsISupports createInstance (); */
  NS_SCRIPTABLE NS_IMETHOD CreateInstance(nsISupports **_retval NS_OUTPARAM) = 0;

  /* nsISupports getService (); */
  NS_SCRIPTABLE NS_IMETHOD GetService(nsISupports **_retval NS_OUTPARAM) = 0;

};

  NS_DEFINE_STATIC_IID_ACCESSOR(nsIJSCID, NS_IJSCID_IID)

/* Use this macro when declaring classes that implement this interface. */
#define NS_DECL_NSIJSCID \
  NS_SCRIPTABLE NS_IMETHOD CreateInstance(nsISupports **_retval NS_OUTPARAM); \
  NS_SCRIPTABLE NS_IMETHOD GetService(nsISupports **_retval NS_OUTPARAM); 

/* Use this macro to declare functions that forward the behavior of this interface to another object. */
#define NS_FORWARD_NSIJSCID(_to) \
  NS_SCRIPTABLE NS_IMETHOD CreateInstance(nsISupports **_retval NS_OUTPARAM) { return _to CreateInstance(_retval); } \
  NS_SCRIPTABLE NS_IMETHOD GetService(nsISupports **_retval NS_OUTPARAM) { return _to GetService(_retval); } 

/* Use this macro to declare functions that forward the behavior of this interface to another object in a safe way. */
#define NS_FORWARD_SAFE_NSIJSCID(_to) \
  NS_SCRIPTABLE NS_IMETHOD CreateInstance(nsISupports **_retval NS_OUTPARAM) { return !_to ? NS_ERROR_NULL_POINTER : _to->CreateInstance(_retval); } \
  NS_SCRIPTABLE NS_IMETHOD GetService(nsISupports **_retval NS_OUTPARAM) { return !_to ? NS_ERROR_NULL_POINTER : _to->GetService(_retval); } 

#if 0
/* Use the code below as a template for the implementation class for this interface. */

/* Header file */
class nsJSCID : public nsIJSCID
{
public:
  NS_DECL_ISUPPORTS
  NS_DECL_NSIJSCID

  nsJSCID();

private:
  ~nsJSCID();

protected:
  /* additional members */
};

/* Implementation file */
NS_IMPL_ISUPPORTS1(nsJSCID, nsIJSCID)

nsJSCID::nsJSCID()
{
  /* member initializers and constructor code */
}

nsJSCID::~nsJSCID()
{
  /* destructor code */
}

/* nsISupports createInstance (); */
NS_IMETHODIMP nsJSCID::CreateInstance(nsISupports **_retval NS_OUTPARAM)
{
    return NS_ERROR_NOT_IMPLEMENTED;
}

/* nsISupports getService (); */
NS_IMETHODIMP nsJSCID::GetService(nsISupports **_retval NS_OUTPARAM)
{
    return NS_ERROR_NOT_IMPLEMENTED;
}

/* End of implementation class template. */
#endif

/********************************************************/
// {F24A14F0-4FA1-11d3-9894-006008962422}
#define NS_JS_ID_CID  \
{ 0xf24a14f0, 0x4fa1, 0x11d3, \
    { 0x98, 0x94, 0x0, 0x60, 0x8, 0x96, 0x24, 0x22 } }

#endif /* __gen_xpcjsid_h__ */
