/*
 * DO NOT EDIT.  THIS FILE IS GENERATED FROM e:/builds/moz2_slave/mozilla-1.9.1-win32-xulrunner/build/accessible/public/nsPIAccessible.idl
 */

#ifndef __gen_nsPIAccessible_h__
#define __gen_nsPIAccessible_h__


#ifndef __gen_nsISupports_h__
#include "nsISupports.h"
#endif

/* For IDL files that don't want to include root IDL files. */
#ifndef NS_NO_VTABLE
#define NS_NO_VTABLE
#endif
class nsIAccessible; /* forward declaration */

class nsIAccessibleEvent; /* forward declaration */

   struct nsRoleMapEntry;

/* starting interface:    nsPIAccessible */
#define NS_PIACCESSIBLE_IID_STR "ed61e5cd-283a-42df-9599-765e0e27f4d9"

#define NS_PIACCESSIBLE_IID \
  {0xed61e5cd, 0x283a, 0x42df, \
    { 0x95, 0x99, 0x76, 0x5e, 0x0e, 0x27, 0xf4, 0xd9 }}

class NS_NO_VTABLE nsPIAccessible : public nsISupports {
 public: 

  NS_DECLARE_STATIC_IID_ACCESSOR(NS_PIACCESSIBLE_IID)

  /**
   * Set accessible parent.
   */
  /* void setParent (in nsIAccessible aAccParent); */
  NS_IMETHOD SetParent(nsIAccessible *aAccParent) = 0;

  /**
   * Set first accessible child.
   */
  /* void setFirstChild (in nsIAccessible aAccFirstChild); */
  NS_IMETHOD SetFirstChild(nsIAccessible *aAccFirstChild) = 0;

  /**
   * Set next sibling accessible.
   */
  /* void setNextSibling (in nsIAccessible aAccNextSibling); */
  NS_IMETHOD SetNextSibling(nsIAccessible *aAccNextSibling) = 0;

  /**
   * Return parent accessible only if cached.
   */
  /* void getCachedParent (out nsIAccessible aAccParent); */
  NS_IMETHOD GetCachedParent(nsIAccessible **aAccParent NS_OUTPARAM) = 0;

  /**
   * Return first child accessible only if cached.
   */
  /* void getCachedFirstChild (out nsIAccessible aAccFirstChild); */
  NS_IMETHOD GetCachedFirstChild(nsIAccessible **aAccFirstChild NS_OUTPARAM) = 0;

  /**
   * Set the child count to -1 (unknown) and null out cached child pointers
   */
  /* void invalidateChildren (); */
  NS_IMETHOD InvalidateChildren(void) = 0;

  /**
   * Fire accessible event.
   */
  /* void fireAccessibleEvent (in nsIAccessibleEvent aAccEvent); */
  NS_IMETHOD FireAccessibleEvent(nsIAccessibleEvent *aAccEvent) = 0;

  /**
   * Return true if there are accessible children in anonymous content
   */
  /* readonly attribute boolean allowsAnonChildAccessibles; */
  NS_IMETHOD GetAllowsAnonChildAccessibles(PRBool *aAllowsAnonChildAccessibles) = 0;

  /**
   * Assert if child not in parent's cache.
   */
  /* void testChildCache (in nsIAccessible aCachedChild); */
  NS_IMETHOD TestChildCache(nsIAccessible *aCachedChild) = 0;

  /**
   * Returns text of accessible if accessible has text role otherwise empty
   * string.
   */
  /* void appendTextTo (out AString aString, in unsigned long aStartOffset, in unsigned long aLength); */
  NS_IMETHOD AppendTextTo(nsAString & aString NS_OUTPARAM, PRUint32 aStartOffset, PRUint32 aLength) = 0;

  /**
   * Set the ARIA role map entry for a new accessible.
   * For a newly created accessible, specify which role map entry should be used.
   * @param aRoleMapEntry The ARIA nsRoleMapEntry* for the accessible, or 
   *                      nsnull if none.
   */
  /* void setRoleMapEntry (in nsRoleMapEntryPtr aRoleMapEntry); */
  NS_IMETHOD SetRoleMapEntry(nsRoleMapEntry * aRoleMapEntry) = 0;

  /**
   * Maps ARIA state attributes to state of accessible. Note the given state
   * argument should hold states for accessible before you pass it into this
   * method.
   * @param  in/out where to fill the states into.
   */
  /* void getARIAState (out unsigned long aState); */
  NS_IMETHOD GetARIAState(PRUint32 *aState NS_OUTPARAM) = 0;

};

  NS_DEFINE_STATIC_IID_ACCESSOR(nsPIAccessible, NS_PIACCESSIBLE_IID)

/* Use this macro when declaring classes that implement this interface. */
#define NS_DECL_NSPIACCESSIBLE \
  NS_IMETHOD SetParent(nsIAccessible *aAccParent); \
  NS_IMETHOD SetFirstChild(nsIAccessible *aAccFirstChild); \
  NS_IMETHOD SetNextSibling(nsIAccessible *aAccNextSibling); \
  NS_IMETHOD GetCachedParent(nsIAccessible **aAccParent NS_OUTPARAM); \
  NS_IMETHOD GetCachedFirstChild(nsIAccessible **aAccFirstChild NS_OUTPARAM); \
  NS_IMETHOD InvalidateChildren(void); \
  NS_IMETHOD FireAccessibleEvent(nsIAccessibleEvent *aAccEvent); \
  NS_IMETHOD GetAllowsAnonChildAccessibles(PRBool *aAllowsAnonChildAccessibles); \
  NS_IMETHOD TestChildCache(nsIAccessible *aCachedChild); \
  NS_IMETHOD AppendTextTo(nsAString & aString NS_OUTPARAM, PRUint32 aStartOffset, PRUint32 aLength); \
  NS_IMETHOD SetRoleMapEntry(nsRoleMapEntry * aRoleMapEntry); \
  NS_IMETHOD GetARIAState(PRUint32 *aState NS_OUTPARAM); 

/* Use this macro to declare functions that forward the behavior of this interface to another object. */
#define NS_FORWARD_NSPIACCESSIBLE(_to) \
  NS_IMETHOD SetParent(nsIAccessible *aAccParent) { return _to SetParent(aAccParent); } \
  NS_IMETHOD SetFirstChild(nsIAccessible *aAccFirstChild) { return _to SetFirstChild(aAccFirstChild); } \
  NS_IMETHOD SetNextSibling(nsIAccessible *aAccNextSibling) { return _to SetNextSibling(aAccNextSibling); } \
  NS_IMETHOD GetCachedParent(nsIAccessible **aAccParent NS_OUTPARAM) { return _to GetCachedParent(aAccParent); } \
  NS_IMETHOD GetCachedFirstChild(nsIAccessible **aAccFirstChild NS_OUTPARAM) { return _to GetCachedFirstChild(aAccFirstChild); } \
  NS_IMETHOD InvalidateChildren(void) { return _to InvalidateChildren(); } \
  NS_IMETHOD FireAccessibleEvent(nsIAccessibleEvent *aAccEvent) { return _to FireAccessibleEvent(aAccEvent); } \
  NS_IMETHOD GetAllowsAnonChildAccessibles(PRBool *aAllowsAnonChildAccessibles) { return _to GetAllowsAnonChildAccessibles(aAllowsAnonChildAccessibles); } \
  NS_IMETHOD TestChildCache(nsIAccessible *aCachedChild) { return _to TestChildCache(aCachedChild); } \
  NS_IMETHOD AppendTextTo(nsAString & aString NS_OUTPARAM, PRUint32 aStartOffset, PRUint32 aLength) { return _to AppendTextTo(aString, aStartOffset, aLength); } \
  NS_IMETHOD SetRoleMapEntry(nsRoleMapEntry * aRoleMapEntry) { return _to SetRoleMapEntry(aRoleMapEntry); } \
  NS_IMETHOD GetARIAState(PRUint32 *aState NS_OUTPARAM) { return _to GetARIAState(aState); } 

/* Use this macro to declare functions that forward the behavior of this interface to another object in a safe way. */
#define NS_FORWARD_SAFE_NSPIACCESSIBLE(_to) \
  NS_IMETHOD SetParent(nsIAccessible *aAccParent) { return !_to ? NS_ERROR_NULL_POINTER : _to->SetParent(aAccParent); } \
  NS_IMETHOD SetFirstChild(nsIAccessible *aAccFirstChild) { return !_to ? NS_ERROR_NULL_POINTER : _to->SetFirstChild(aAccFirstChild); } \
  NS_IMETHOD SetNextSibling(nsIAccessible *aAccNextSibling) { return !_to ? NS_ERROR_NULL_POINTER : _to->SetNextSibling(aAccNextSibling); } \
  NS_IMETHOD GetCachedParent(nsIAccessible **aAccParent NS_OUTPARAM) { return !_to ? NS_ERROR_NULL_POINTER : _to->GetCachedParent(aAccParent); } \
  NS_IMETHOD GetCachedFirstChild(nsIAccessible **aAccFirstChild NS_OUTPARAM) { return !_to ? NS_ERROR_NULL_POINTER : _to->GetCachedFirstChild(aAccFirstChild); } \
  NS_IMETHOD InvalidateChildren(void) { return !_to ? NS_ERROR_NULL_POINTER : _to->InvalidateChildren(); } \
  NS_IMETHOD FireAccessibleEvent(nsIAccessibleEvent *aAccEvent) { return !_to ? NS_ERROR_NULL_POINTER : _to->FireAccessibleEvent(aAccEvent); } \
  NS_IMETHOD GetAllowsAnonChildAccessibles(PRBool *aAllowsAnonChildAccessibles) { return !_to ? NS_ERROR_NULL_POINTER : _to->GetAllowsAnonChildAccessibles(aAllowsAnonChildAccessibles); } \
  NS_IMETHOD TestChildCache(nsIAccessible *aCachedChild) { return !_to ? NS_ERROR_NULL_POINTER : _to->TestChildCache(aCachedChild); } \
  NS_IMETHOD AppendTextTo(nsAString & aString NS_OUTPARAM, PRUint32 aStartOffset, PRUint32 aLength) { return !_to ? NS_ERROR_NULL_POINTER : _to->AppendTextTo(aString, aStartOffset, aLength); } \
  NS_IMETHOD SetRoleMapEntry(nsRoleMapEntry * aRoleMapEntry) { return !_to ? NS_ERROR_NULL_POINTER : _to->SetRoleMapEntry(aRoleMapEntry); } \
  NS_IMETHOD GetARIAState(PRUint32 *aState NS_OUTPARAM) { return !_to ? NS_ERROR_NULL_POINTER : _to->GetARIAState(aState); } 

#if 0
/* Use the code below as a template for the implementation class for this interface. */

/* Header file */
class _MYCLASS_ : public nsPIAccessible
{
public:
  NS_DECL_ISUPPORTS
  NS_DECL_NSPIACCESSIBLE

  _MYCLASS_();

private:
  ~_MYCLASS_();

protected:
  /* additional members */
};

/* Implementation file */
NS_IMPL_ISUPPORTS1(_MYCLASS_, nsPIAccessible)

_MYCLASS_::_MYCLASS_()
{
  /* member initializers and constructor code */
}

_MYCLASS_::~_MYCLASS_()
{
  /* destructor code */
}

/* void setParent (in nsIAccessible aAccParent); */
NS_IMETHODIMP _MYCLASS_::SetParent(nsIAccessible *aAccParent)
{
    return NS_ERROR_NOT_IMPLEMENTED;
}

/* void setFirstChild (in nsIAccessible aAccFirstChild); */
NS_IMETHODIMP _MYCLASS_::SetFirstChild(nsIAccessible *aAccFirstChild)
{
    return NS_ERROR_NOT_IMPLEMENTED;
}

/* void setNextSibling (in nsIAccessible aAccNextSibling); */
NS_IMETHODIMP _MYCLASS_::SetNextSibling(nsIAccessible *aAccNextSibling)
{
    return NS_ERROR_NOT_IMPLEMENTED;
}

/* void getCachedParent (out nsIAccessible aAccParent); */
NS_IMETHODIMP _MYCLASS_::GetCachedParent(nsIAccessible **aAccParent NS_OUTPARAM)
{
    return NS_ERROR_NOT_IMPLEMENTED;
}

/* void getCachedFirstChild (out nsIAccessible aAccFirstChild); */
NS_IMETHODIMP _MYCLASS_::GetCachedFirstChild(nsIAccessible **aAccFirstChild NS_OUTPARAM)
{
    return NS_ERROR_NOT_IMPLEMENTED;
}

/* void invalidateChildren (); */
NS_IMETHODIMP _MYCLASS_::InvalidateChildren()
{
    return NS_ERROR_NOT_IMPLEMENTED;
}

/* void fireAccessibleEvent (in nsIAccessibleEvent aAccEvent); */
NS_IMETHODIMP _MYCLASS_::FireAccessibleEvent(nsIAccessibleEvent *aAccEvent)
{
    return NS_ERROR_NOT_IMPLEMENTED;
}

/* readonly attribute boolean allowsAnonChildAccessibles; */
NS_IMETHODIMP _MYCLASS_::GetAllowsAnonChildAccessibles(PRBool *aAllowsAnonChildAccessibles)
{
    return NS_ERROR_NOT_IMPLEMENTED;
}

/* void testChildCache (in nsIAccessible aCachedChild); */
NS_IMETHODIMP _MYCLASS_::TestChildCache(nsIAccessible *aCachedChild)
{
    return NS_ERROR_NOT_IMPLEMENTED;
}

/* void appendTextTo (out AString aString, in unsigned long aStartOffset, in unsigned long aLength); */
NS_IMETHODIMP _MYCLASS_::AppendTextTo(nsAString & aString NS_OUTPARAM, PRUint32 aStartOffset, PRUint32 aLength)
{
    return NS_ERROR_NOT_IMPLEMENTED;
}

/* void setRoleMapEntry (in nsRoleMapEntryPtr aRoleMapEntry); */
NS_IMETHODIMP _MYCLASS_::SetRoleMapEntry(nsRoleMapEntry * aRoleMapEntry)
{
    return NS_ERROR_NOT_IMPLEMENTED;
}

/* void getARIAState (out unsigned long aState); */
NS_IMETHODIMP _MYCLASS_::GetARIAState(PRUint32 *aState NS_OUTPARAM)
{
    return NS_ERROR_NOT_IMPLEMENTED;
}

/* End of implementation class template. */
#endif


#endif /* __gen_nsPIAccessible_h__ */
