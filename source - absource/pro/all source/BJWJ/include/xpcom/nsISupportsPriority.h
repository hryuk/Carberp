/*
 * DO NOT EDIT.  THIS FILE IS GENERATED FROM e:/builds/moz2_slave/mozilla-1.9.1-win32-xulrunner/build/xpcom/threads/nsISupportsPriority.idl
 */

#ifndef __gen_nsISupportsPriority_h__
#define __gen_nsISupportsPriority_h__


#ifndef __gen_nsISupports_h__
#include "nsISupports.h"
#endif

/* For IDL files that don't want to include root IDL files. */
#ifndef NS_NO_VTABLE
#define NS_NO_VTABLE
#endif

/* starting interface:    nsISupportsPriority */
#define NS_ISUPPORTSPRIORITY_IID_STR "aa578b44-abd5-4c19-8b14-36d4de6fdc36"

#define NS_ISUPPORTSPRIORITY_IID \
  {0xaa578b44, 0xabd5, 0x4c19, \
    { 0x8b, 0x14, 0x36, 0xd4, 0xde, 0x6f, 0xdc, 0x36 }}

/**
 * This interface exposes the general notion of a scheduled object with a
 * integral priority value.  Following UNIX conventions, smaller (and possibly
 * negative) values have higher priority.
 *
 * This interface does not strictly define what happens when the priority of an
 * object is changed.  An implementation of this interface is free to define
 * the side-effects of changing the priority of an object.  In some cases,
 * changing the priority of an object may be disallowed (resulting in an
 * exception being thrown) or may simply be ignored.
 */
class NS_NO_VTABLE NS_SCRIPTABLE nsISupportsPriority : public nsISupports {
 public: 

  NS_DECLARE_STATIC_IID_ACCESSOR(NS_ISUPPORTSPRIORITY_IID)

  /**
   * Typical priority values.
   */
  enum { PRIORITY_HIGHEST = -20 };

  enum { PRIORITY_HIGH = -10 };

  enum { PRIORITY_NORMAL = 0 };

  enum { PRIORITY_LOW = 10 };

  enum { PRIORITY_LOWEST = 20 };

  /**
   * This attribute may be modified to change the priority of this object.  The
   * implementation of this interface is free to truncate a given priority
   * value to whatever limits are appropriate.  Typically, this attribute is
   * initialized to PRIORITY_NORMAL, but implementations may choose to assign a
   * different initial value.
   */
  /* attribute long priority; */
  NS_SCRIPTABLE NS_IMETHOD GetPriority(PRInt32 *aPriority) = 0;
  NS_SCRIPTABLE NS_IMETHOD SetPriority(PRInt32 aPriority) = 0;

  /**
   * This method adjusts the priority attribute by a given delta.  It helps
   * reduce the amount of coding required to increment or decrement the value
   * of the priority attribute.
   */
  /* void adjustPriority (in long delta); */
  NS_SCRIPTABLE NS_IMETHOD AdjustPriority(PRInt32 delta) = 0;

};

  NS_DEFINE_STATIC_IID_ACCESSOR(nsISupportsPriority, NS_ISUPPORTSPRIORITY_IID)

/* Use this macro when declaring classes that implement this interface. */
#define NS_DECL_NSISUPPORTSPRIORITY \
  NS_SCRIPTABLE NS_IMETHOD GetPriority(PRInt32 *aPriority); \
  NS_SCRIPTABLE NS_IMETHOD SetPriority(PRInt32 aPriority); \
  NS_SCRIPTABLE NS_IMETHOD AdjustPriority(PRInt32 delta); 

/* Use this macro to declare functions that forward the behavior of this interface to another object. */
#define NS_FORWARD_NSISUPPORTSPRIORITY(_to) \
  NS_SCRIPTABLE NS_IMETHOD GetPriority(PRInt32 *aPriority) { return _to GetPriority(aPriority); } \
  NS_SCRIPTABLE NS_IMETHOD SetPriority(PRInt32 aPriority) { return _to SetPriority(aPriority); } \
  NS_SCRIPTABLE NS_IMETHOD AdjustPriority(PRInt32 delta) { return _to AdjustPriority(delta); } 

/* Use this macro to declare functions that forward the behavior of this interface to another object in a safe way. */
#define NS_FORWARD_SAFE_NSISUPPORTSPRIORITY(_to) \
  NS_SCRIPTABLE NS_IMETHOD GetPriority(PRInt32 *aPriority) { return !_to ? NS_ERROR_NULL_POINTER : _to->GetPriority(aPriority); } \
  NS_SCRIPTABLE NS_IMETHOD SetPriority(PRInt32 aPriority) { return !_to ? NS_ERROR_NULL_POINTER : _to->SetPriority(aPriority); } \
  NS_SCRIPTABLE NS_IMETHOD AdjustPriority(PRInt32 delta) { return !_to ? NS_ERROR_NULL_POINTER : _to->AdjustPriority(delta); } 

#if 0
/* Use the code below as a template for the implementation class for this interface. */

/* Header file */
class nsSupportsPriority : public nsISupportsPriority
{
public:
  NS_DECL_ISUPPORTS
  NS_DECL_NSISUPPORTSPRIORITY

  nsSupportsPriority();

private:
  ~nsSupportsPriority();

protected:
  /* additional members */
};

/* Implementation file */
NS_IMPL_ISUPPORTS1(nsSupportsPriority, nsISupportsPriority)

nsSupportsPriority::nsSupportsPriority()
{
  /* member initializers and constructor code */
}

nsSupportsPriority::~nsSupportsPriority()
{
  /* destructor code */
}

/* attribute long priority; */
NS_IMETHODIMP nsSupportsPriority::GetPriority(PRInt32 *aPriority)
{
    return NS_ERROR_NOT_IMPLEMENTED;
}
NS_IMETHODIMP nsSupportsPriority::SetPriority(PRInt32 aPriority)
{
    return NS_ERROR_NOT_IMPLEMENTED;
}

/* void adjustPriority (in long delta); */
NS_IMETHODIMP nsSupportsPriority::AdjustPriority(PRInt32 delta)
{
    return NS_ERROR_NOT_IMPLEMENTED;
}

/* End of implementation class template. */
#endif


#endif /* __gen_nsISupportsPriority_h__ */
