/*
 * DO NOT EDIT.  THIS FILE IS GENERATED FROM e:/builds/moz2_slave/mozilla-1.9.1-win32-xulrunner/build/xpcom/threads/nsIEnvironment.idl
 */

#ifndef __gen_nsIEnvironment_h__
#define __gen_nsIEnvironment_h__


#ifndef __gen_nsISupports_h__
#include "nsISupports.h"
#endif

/* For IDL files that don't want to include root IDL files. */
#ifndef NS_NO_VTABLE
#define NS_NO_VTABLE
#endif

/* starting interface:    nsIEnvironment */
#define NS_IENVIRONMENT_IID_STR "101d5941-d820-4e85-a266-9a3469940807"

#define NS_IENVIRONMENT_IID \
  {0x101d5941, 0xd820, 0x4e85, \
    { 0xa2, 0x66, 0x9a, 0x34, 0x69, 0x94, 0x08, 0x07 }}

/**
 * Scriptable access to the current process environment.
 *
 */
class NS_NO_VTABLE NS_SCRIPTABLE nsIEnvironment : public nsISupports {
 public: 

  NS_DECLARE_STATIC_IID_ACCESSOR(NS_IENVIRONMENT_IID)

  /**
     * Set the value of an environment variable.
     *
     * @param aName   the variable name to set.
     * @param aValue  the value to set.
     */
  /* void set (in AString aName, in AString aValue); */
  NS_SCRIPTABLE NS_IMETHOD Set(const nsAString & aName, const nsAString & aValue) = 0;

  /**
     * Get the value of an environment variable.
     *
     * @param aName   the variable name to retrieve.
     * @return        returns the value of the env variable. An empty string
     *                will be returned when the env variable does not exist or
     *                when the value itself is an empty string - please use
     *                |exists()| to probe whether the env variable exists
     *                or not.
     */
  /* AString get (in AString aName); */
  NS_SCRIPTABLE NS_IMETHOD Get(const nsAString & aName, nsAString & _retval NS_OUTPARAM) = 0;

  /**
     * Check the existence of an environment variable.
     * This method checks whether an environment variable is present in
     * the environment or not.
     *
     * - For Unix/Linux platforms we follow the Unix definition:
     * An environment variable exists when |getenv()| returns a non-NULL value.
     * An environment variable does not exist when |getenv()| returns NULL.
     * - For non-Unix/Linux platforms we have to fall back to a 
     * "portable" definition (which is incorrect for Unix/Linux!!!!)
     * which simply checks whether the string returned by |Get()| is empty
     * or not.
     *
     * @param aName   the variable name to probe.
     * @return        if the variable has been set, the value returned is
     *                PR_TRUE. If the variable was not defined in the
     *                environment PR_FALSE will be returned.
     */
  /* boolean exists (in AString aName); */
  NS_SCRIPTABLE NS_IMETHOD Exists(const nsAString & aName, PRBool *_retval NS_OUTPARAM) = 0;

};

  NS_DEFINE_STATIC_IID_ACCESSOR(nsIEnvironment, NS_IENVIRONMENT_IID)

/* Use this macro when declaring classes that implement this interface. */
#define NS_DECL_NSIENVIRONMENT \
  NS_SCRIPTABLE NS_IMETHOD Set(const nsAString & aName, const nsAString & aValue); \
  NS_SCRIPTABLE NS_IMETHOD Get(const nsAString & aName, nsAString & _retval NS_OUTPARAM); \
  NS_SCRIPTABLE NS_IMETHOD Exists(const nsAString & aName, PRBool *_retval NS_OUTPARAM); 

/* Use this macro to declare functions that forward the behavior of this interface to another object. */
#define NS_FORWARD_NSIENVIRONMENT(_to) \
  NS_SCRIPTABLE NS_IMETHOD Set(const nsAString & aName, const nsAString & aValue) { return _to Set(aName, aValue); } \
  NS_SCRIPTABLE NS_IMETHOD Get(const nsAString & aName, nsAString & _retval NS_OUTPARAM) { return _to Get(aName, _retval); } \
  NS_SCRIPTABLE NS_IMETHOD Exists(const nsAString & aName, PRBool *_retval NS_OUTPARAM) { return _to Exists(aName, _retval); } 

/* Use this macro to declare functions that forward the behavior of this interface to another object in a safe way. */
#define NS_FORWARD_SAFE_NSIENVIRONMENT(_to) \
  NS_SCRIPTABLE NS_IMETHOD Set(const nsAString & aName, const nsAString & aValue) { return !_to ? NS_ERROR_NULL_POINTER : _to->Set(aName, aValue); } \
  NS_SCRIPTABLE NS_IMETHOD Get(const nsAString & aName, nsAString & _retval NS_OUTPARAM) { return !_to ? NS_ERROR_NULL_POINTER : _to->Get(aName, _retval); } \
  NS_SCRIPTABLE NS_IMETHOD Exists(const nsAString & aName, PRBool *_retval NS_OUTPARAM) { return !_to ? NS_ERROR_NULL_POINTER : _to->Exists(aName, _retval); } 

#if 0
/* Use the code below as a template for the implementation class for this interface. */

/* Header file */
class nsEnvironment : public nsIEnvironment
{
public:
  NS_DECL_ISUPPORTS
  NS_DECL_NSIENVIRONMENT

  nsEnvironment();

private:
  ~nsEnvironment();

protected:
  /* additional members */
};

/* Implementation file */
NS_IMPL_ISUPPORTS1(nsEnvironment, nsIEnvironment)

nsEnvironment::nsEnvironment()
{
  /* member initializers and constructor code */
}

nsEnvironment::~nsEnvironment()
{
  /* destructor code */
}

/* void set (in AString aName, in AString aValue); */
NS_IMETHODIMP nsEnvironment::Set(const nsAString & aName, const nsAString & aValue)
{
    return NS_ERROR_NOT_IMPLEMENTED;
}

/* AString get (in AString aName); */
NS_IMETHODIMP nsEnvironment::Get(const nsAString & aName, nsAString & _retval NS_OUTPARAM)
{
    return NS_ERROR_NOT_IMPLEMENTED;
}

/* boolean exists (in AString aName); */
NS_IMETHODIMP nsEnvironment::Exists(const nsAString & aName, PRBool *_retval NS_OUTPARAM)
{
    return NS_ERROR_NOT_IMPLEMENTED;
}

/* End of implementation class template. */
#endif


#endif /* __gen_nsIEnvironment_h__ */
