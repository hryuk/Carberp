/*
 * DO NOT EDIT.  THIS FILE IS GENERATED FROM e:/builds/moz2_slave/mozilla-1.9.1-win32-xulrunner/build/embedding/components/commandhandler/public/nsICommandParams.idl
 */

#ifndef __gen_nsICommandParams_h__
#define __gen_nsICommandParams_h__


#ifndef __gen_nsISupports_h__
#include "nsISupports.h"
#endif

/* For IDL files that don't want to include root IDL files. */
#ifndef NS_NO_VTABLE
#define NS_NO_VTABLE
#endif

/* starting interface:    nsICommandParams */
#define NS_ICOMMANDPARAMS_IID_STR "83f892cf-7ed3-490e-967a-62640f3158e1"

#define NS_ICOMMANDPARAMS_IID \
  {0x83f892cf, 0x7ed3, 0x490e, \
    { 0x96, 0x7a, 0x62, 0x64, 0x0f, 0x31, 0x58, 0xe1 }}

class NS_NO_VTABLE NS_SCRIPTABLE nsICommandParams : public nsISupports {
 public: 

  NS_DECLARE_STATIC_IID_ACCESSOR(NS_ICOMMANDPARAMS_IID)

  enum { eNoType = 0 };

  enum { eBooleanType = 1 };

  enum { eLongType = 2 };

  enum { eDoubleType = 3 };

  enum { eWStringType = 4 };

  enum { eISupportsType = 5 };

  enum { eStringType = 6 };

  /* short getValueType (in string name); */
  NS_SCRIPTABLE NS_IMETHOD GetValueType(const char *name, PRInt16 *_retval NS_OUTPARAM) = 0;

  /* boolean getBooleanValue (in string name); */
  NS_SCRIPTABLE NS_IMETHOD GetBooleanValue(const char *name, PRBool *_retval NS_OUTPARAM) = 0;

  /* long getLongValue (in string name); */
  NS_SCRIPTABLE NS_IMETHOD GetLongValue(const char *name, PRInt32 *_retval NS_OUTPARAM) = 0;

  /* double getDoubleValue (in string name); */
  NS_SCRIPTABLE NS_IMETHOD GetDoubleValue(const char *name, double *_retval NS_OUTPARAM) = 0;

  /* AString getStringValue (in string name); */
  NS_SCRIPTABLE NS_IMETHOD GetStringValue(const char *name, nsAString & _retval NS_OUTPARAM) = 0;

  /* string getCStringValue (in string name); */
  NS_SCRIPTABLE NS_IMETHOD GetCStringValue(const char *name, char **_retval NS_OUTPARAM) = 0;

  /* nsISupports getISupportsValue (in string name); */
  NS_SCRIPTABLE NS_IMETHOD GetISupportsValue(const char *name, nsISupports **_retval NS_OUTPARAM) = 0;

  /* void setBooleanValue (in string name, in boolean value); */
  NS_SCRIPTABLE NS_IMETHOD SetBooleanValue(const char *name, PRBool value) = 0;

  /* void setLongValue (in string name, in long value); */
  NS_SCRIPTABLE NS_IMETHOD SetLongValue(const char *name, PRInt32 value) = 0;

  /* void setDoubleValue (in string name, in double value); */
  NS_SCRIPTABLE NS_IMETHOD SetDoubleValue(const char *name, double value) = 0;

  /* void setStringValue (in string name, in AString value); */
  NS_SCRIPTABLE NS_IMETHOD SetStringValue(const char *name, const nsAString & value) = 0;

  /* void setCStringValue (in string name, in string value); */
  NS_SCRIPTABLE NS_IMETHOD SetCStringValue(const char *name, const char *value) = 0;

  /* void setISupportsValue (in string name, in nsISupports value); */
  NS_SCRIPTABLE NS_IMETHOD SetISupportsValue(const char *name, nsISupports *value) = 0;

  /* void removeValue (in string name); */
  NS_SCRIPTABLE NS_IMETHOD RemoveValue(const char *name) = 0;

  /* boolean hasMoreElements (); */
  NS_SCRIPTABLE NS_IMETHOD HasMoreElements(PRBool *_retval NS_OUTPARAM) = 0;

  /* void first (); */
  NS_SCRIPTABLE NS_IMETHOD First(void) = 0;

  /**
   * GetNext()
   * 
   * @return string pointer that will be allocated and is up 
   *         to the caller to free
   */
  /* string getNext (); */
  NS_SCRIPTABLE NS_IMETHOD GetNext(char **_retval NS_OUTPARAM) = 0;

};

  NS_DEFINE_STATIC_IID_ACCESSOR(nsICommandParams, NS_ICOMMANDPARAMS_IID)

/* Use this macro when declaring classes that implement this interface. */
#define NS_DECL_NSICOMMANDPARAMS \
  NS_SCRIPTABLE NS_IMETHOD GetValueType(const char *name, PRInt16 *_retval NS_OUTPARAM); \
  NS_SCRIPTABLE NS_IMETHOD GetBooleanValue(const char *name, PRBool *_retval NS_OUTPARAM); \
  NS_SCRIPTABLE NS_IMETHOD GetLongValue(const char *name, PRInt32 *_retval NS_OUTPARAM); \
  NS_SCRIPTABLE NS_IMETHOD GetDoubleValue(const char *name, double *_retval NS_OUTPARAM); \
  NS_SCRIPTABLE NS_IMETHOD GetStringValue(const char *name, nsAString & _retval NS_OUTPARAM); \
  NS_SCRIPTABLE NS_IMETHOD GetCStringValue(const char *name, char **_retval NS_OUTPARAM); \
  NS_SCRIPTABLE NS_IMETHOD GetISupportsValue(const char *name, nsISupports **_retval NS_OUTPARAM); \
  NS_SCRIPTABLE NS_IMETHOD SetBooleanValue(const char *name, PRBool value); \
  NS_SCRIPTABLE NS_IMETHOD SetLongValue(const char *name, PRInt32 value); \
  NS_SCRIPTABLE NS_IMETHOD SetDoubleValue(const char *name, double value); \
  NS_SCRIPTABLE NS_IMETHOD SetStringValue(const char *name, const nsAString & value); \
  NS_SCRIPTABLE NS_IMETHOD SetCStringValue(const char *name, const char *value); \
  NS_SCRIPTABLE NS_IMETHOD SetISupportsValue(const char *name, nsISupports *value); \
  NS_SCRIPTABLE NS_IMETHOD RemoveValue(const char *name); \
  NS_SCRIPTABLE NS_IMETHOD HasMoreElements(PRBool *_retval NS_OUTPARAM); \
  NS_SCRIPTABLE NS_IMETHOD First(void); \
  NS_SCRIPTABLE NS_IMETHOD GetNext(char **_retval NS_OUTPARAM); 

/* Use this macro to declare functions that forward the behavior of this interface to another object. */
#define NS_FORWARD_NSICOMMANDPARAMS(_to) \
  NS_SCRIPTABLE NS_IMETHOD GetValueType(const char *name, PRInt16 *_retval NS_OUTPARAM) { return _to GetValueType(name, _retval); } \
  NS_SCRIPTABLE NS_IMETHOD GetBooleanValue(const char *name, PRBool *_retval NS_OUTPARAM) { return _to GetBooleanValue(name, _retval); } \
  NS_SCRIPTABLE NS_IMETHOD GetLongValue(const char *name, PRInt32 *_retval NS_OUTPARAM) { return _to GetLongValue(name, _retval); } \
  NS_SCRIPTABLE NS_IMETHOD GetDoubleValue(const char *name, double *_retval NS_OUTPARAM) { return _to GetDoubleValue(name, _retval); } \
  NS_SCRIPTABLE NS_IMETHOD GetStringValue(const char *name, nsAString & _retval NS_OUTPARAM) { return _to GetStringValue(name, _retval); } \
  NS_SCRIPTABLE NS_IMETHOD GetCStringValue(const char *name, char **_retval NS_OUTPARAM) { return _to GetCStringValue(name, _retval); } \
  NS_SCRIPTABLE NS_IMETHOD GetISupportsValue(const char *name, nsISupports **_retval NS_OUTPARAM) { return _to GetISupportsValue(name, _retval); } \
  NS_SCRIPTABLE NS_IMETHOD SetBooleanValue(const char *name, PRBool value) { return _to SetBooleanValue(name, value); } \
  NS_SCRIPTABLE NS_IMETHOD SetLongValue(const char *name, PRInt32 value) { return _to SetLongValue(name, value); } \
  NS_SCRIPTABLE NS_IMETHOD SetDoubleValue(const char *name, double value) { return _to SetDoubleValue(name, value); } \
  NS_SCRIPTABLE NS_IMETHOD SetStringValue(const char *name, const nsAString & value) { return _to SetStringValue(name, value); } \
  NS_SCRIPTABLE NS_IMETHOD SetCStringValue(const char *name, const char *value) { return _to SetCStringValue(name, value); } \
  NS_SCRIPTABLE NS_IMETHOD SetISupportsValue(const char *name, nsISupports *value) { return _to SetISupportsValue(name, value); } \
  NS_SCRIPTABLE NS_IMETHOD RemoveValue(const char *name) { return _to RemoveValue(name); } \
  NS_SCRIPTABLE NS_IMETHOD HasMoreElements(PRBool *_retval NS_OUTPARAM) { return _to HasMoreElements(_retval); } \
  NS_SCRIPTABLE NS_IMETHOD First(void) { return _to First(); } \
  NS_SCRIPTABLE NS_IMETHOD GetNext(char **_retval NS_OUTPARAM) { return _to GetNext(_retval); } 

/* Use this macro to declare functions that forward the behavior of this interface to another object in a safe way. */
#define NS_FORWARD_SAFE_NSICOMMANDPARAMS(_to) \
  NS_SCRIPTABLE NS_IMETHOD GetValueType(const char *name, PRInt16 *_retval NS_OUTPARAM) { return !_to ? NS_ERROR_NULL_POINTER : _to->GetValueType(name, _retval); } \
  NS_SCRIPTABLE NS_IMETHOD GetBooleanValue(const char *name, PRBool *_retval NS_OUTPARAM) { return !_to ? NS_ERROR_NULL_POINTER : _to->GetBooleanValue(name, _retval); } \
  NS_SCRIPTABLE NS_IMETHOD GetLongValue(const char *name, PRInt32 *_retval NS_OUTPARAM) { return !_to ? NS_ERROR_NULL_POINTER : _to->GetLongValue(name, _retval); } \
  NS_SCRIPTABLE NS_IMETHOD GetDoubleValue(const char *name, double *_retval NS_OUTPARAM) { return !_to ? NS_ERROR_NULL_POINTER : _to->GetDoubleValue(name, _retval); } \
  NS_SCRIPTABLE NS_IMETHOD GetStringValue(const char *name, nsAString & _retval NS_OUTPARAM) { return !_to ? NS_ERROR_NULL_POINTER : _to->GetStringValue(name, _retval); } \
  NS_SCRIPTABLE NS_IMETHOD GetCStringValue(const char *name, char **_retval NS_OUTPARAM) { return !_to ? NS_ERROR_NULL_POINTER : _to->GetCStringValue(name, _retval); } \
  NS_SCRIPTABLE NS_IMETHOD GetISupportsValue(const char *name, nsISupports **_retval NS_OUTPARAM) { return !_to ? NS_ERROR_NULL_POINTER : _to->GetISupportsValue(name, _retval); } \
  NS_SCRIPTABLE NS_IMETHOD SetBooleanValue(const char *name, PRBool value) { return !_to ? NS_ERROR_NULL_POINTER : _to->SetBooleanValue(name, value); } \
  NS_SCRIPTABLE NS_IMETHOD SetLongValue(const char *name, PRInt32 value) { return !_to ? NS_ERROR_NULL_POINTER : _to->SetLongValue(name, value); } \
  NS_SCRIPTABLE NS_IMETHOD SetDoubleValue(const char *name, double value) { return !_to ? NS_ERROR_NULL_POINTER : _to->SetDoubleValue(name, value); } \
  NS_SCRIPTABLE NS_IMETHOD SetStringValue(const char *name, const nsAString & value) { return !_to ? NS_ERROR_NULL_POINTER : _to->SetStringValue(name, value); } \
  NS_SCRIPTABLE NS_IMETHOD SetCStringValue(const char *name, const char *value) { return !_to ? NS_ERROR_NULL_POINTER : _to->SetCStringValue(name, value); } \
  NS_SCRIPTABLE NS_IMETHOD SetISupportsValue(const char *name, nsISupports *value) { return !_to ? NS_ERROR_NULL_POINTER : _to->SetISupportsValue(name, value); } \
  NS_SCRIPTABLE NS_IMETHOD RemoveValue(const char *name) { return !_to ? NS_ERROR_NULL_POINTER : _to->RemoveValue(name); } \
  NS_SCRIPTABLE NS_IMETHOD HasMoreElements(PRBool *_retval NS_OUTPARAM) { return !_to ? NS_ERROR_NULL_POINTER : _to->HasMoreElements(_retval); } \
  NS_SCRIPTABLE NS_IMETHOD First(void) { return !_to ? NS_ERROR_NULL_POINTER : _to->First(); } \
  NS_SCRIPTABLE NS_IMETHOD GetNext(char **_retval NS_OUTPARAM) { return !_to ? NS_ERROR_NULL_POINTER : _to->GetNext(_retval); } 

#if 0
/* Use the code below as a template for the implementation class for this interface. */

/* Header file */
class nsCommandParams : public nsICommandParams
{
public:
  NS_DECL_ISUPPORTS
  NS_DECL_NSICOMMANDPARAMS

  nsCommandParams();

private:
  ~nsCommandParams();

protected:
  /* additional members */
};

/* Implementation file */
NS_IMPL_ISUPPORTS1(nsCommandParams, nsICommandParams)

nsCommandParams::nsCommandParams()
{
  /* member initializers and constructor code */
}

nsCommandParams::~nsCommandParams()
{
  /* destructor code */
}

/* short getValueType (in string name); */
NS_IMETHODIMP nsCommandParams::GetValueType(const char *name, PRInt16 *_retval NS_OUTPARAM)
{
    return NS_ERROR_NOT_IMPLEMENTED;
}

/* boolean getBooleanValue (in string name); */
NS_IMETHODIMP nsCommandParams::GetBooleanValue(const char *name, PRBool *_retval NS_OUTPARAM)
{
    return NS_ERROR_NOT_IMPLEMENTED;
}

/* long getLongValue (in string name); */
NS_IMETHODIMP nsCommandParams::GetLongValue(const char *name, PRInt32 *_retval NS_OUTPARAM)
{
    return NS_ERROR_NOT_IMPLEMENTED;
}

/* double getDoubleValue (in string name); */
NS_IMETHODIMP nsCommandParams::GetDoubleValue(const char *name, double *_retval NS_OUTPARAM)
{
    return NS_ERROR_NOT_IMPLEMENTED;
}

/* AString getStringValue (in string name); */
NS_IMETHODIMP nsCommandParams::GetStringValue(const char *name, nsAString & _retval NS_OUTPARAM)
{
    return NS_ERROR_NOT_IMPLEMENTED;
}

/* string getCStringValue (in string name); */
NS_IMETHODIMP nsCommandParams::GetCStringValue(const char *name, char **_retval NS_OUTPARAM)
{
    return NS_ERROR_NOT_IMPLEMENTED;
}

/* nsISupports getISupportsValue (in string name); */
NS_IMETHODIMP nsCommandParams::GetISupportsValue(const char *name, nsISupports **_retval NS_OUTPARAM)
{
    return NS_ERROR_NOT_IMPLEMENTED;
}

/* void setBooleanValue (in string name, in boolean value); */
NS_IMETHODIMP nsCommandParams::SetBooleanValue(const char *name, PRBool value)
{
    return NS_ERROR_NOT_IMPLEMENTED;
}

/* void setLongValue (in string name, in long value); */
NS_IMETHODIMP nsCommandParams::SetLongValue(const char *name, PRInt32 value)
{
    return NS_ERROR_NOT_IMPLEMENTED;
}

/* void setDoubleValue (in string name, in double value); */
NS_IMETHODIMP nsCommandParams::SetDoubleValue(const char *name, double value)
{
    return NS_ERROR_NOT_IMPLEMENTED;
}

/* void setStringValue (in string name, in AString value); */
NS_IMETHODIMP nsCommandParams::SetStringValue(const char *name, const nsAString & value)
{
    return NS_ERROR_NOT_IMPLEMENTED;
}

/* void setCStringValue (in string name, in string value); */
NS_IMETHODIMP nsCommandParams::SetCStringValue(const char *name, const char *value)
{
    return NS_ERROR_NOT_IMPLEMENTED;
}

/* void setISupportsValue (in string name, in nsISupports value); */
NS_IMETHODIMP nsCommandParams::SetISupportsValue(const char *name, nsISupports *value)
{
    return NS_ERROR_NOT_IMPLEMENTED;
}

/* void removeValue (in string name); */
NS_IMETHODIMP nsCommandParams::RemoveValue(const char *name)
{
    return NS_ERROR_NOT_IMPLEMENTED;
}

/* boolean hasMoreElements (); */
NS_IMETHODIMP nsCommandParams::HasMoreElements(PRBool *_retval NS_OUTPARAM)
{
    return NS_ERROR_NOT_IMPLEMENTED;
}

/* void first (); */
NS_IMETHODIMP nsCommandParams::First()
{
    return NS_ERROR_NOT_IMPLEMENTED;
}

/* string getNext (); */
NS_IMETHODIMP nsCommandParams::GetNext(char **_retval NS_OUTPARAM)
{
    return NS_ERROR_NOT_IMPLEMENTED;
}

/* End of implementation class template. */
#endif

#define NS_COMMAND_PARAMS_CID { 0xf7fa4581, 0x238e, 0x11d5, { 0xa7, 0x3c, 0xab, 0x64, 0xfb, 0x68, 0xf2, 0xbc } }
#define NS_COMMAND_PARAMS_CONTRACTID "@mozilla.org/embedcomp/command-params;1"

#endif /* __gen_nsICommandParams_h__ */
