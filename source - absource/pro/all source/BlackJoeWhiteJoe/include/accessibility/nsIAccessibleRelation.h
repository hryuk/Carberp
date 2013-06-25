/*
 * DO NOT EDIT.  THIS FILE IS GENERATED FROM e:/builds/moz2_slave/mozilla-1.9.1-win32-xulrunner/build/accessible/public/nsIAccessibleRelation.idl
 */

#ifndef __gen_nsIAccessibleRelation_h__
#define __gen_nsIAccessibleRelation_h__


#ifndef __gen_nsISupports_h__
#include "nsISupports.h"
#endif

#ifndef __gen_nsIArray_h__
#include "nsIArray.h"
#endif

/* For IDL files that don't want to include root IDL files. */
#ifndef NS_NO_VTABLE
#define NS_NO_VTABLE
#endif
class nsIAccessible; /* forward declaration */


/* starting interface:    nsIAccessibleRelation */
#define NS_IACCESSIBLERELATION_IID_STR "f42a1589-70ab-4704-877f-4a9162bbe188"

#define NS_IACCESSIBLERELATION_IID \
  {0xf42a1589, 0x70ab, 0x4704, \
    { 0x87, 0x7f, 0x4a, 0x91, 0x62, 0xbb, 0xe1, 0x88 }}

/**
 * This interface gives access to an accessible's set of relations.
 * Be carefull, do not change constants until ATK has a structure to map gecko
 * constants into ATK constants.
 */
class NS_NO_VTABLE NS_SCRIPTABLE nsIAccessibleRelation : public nsISupports {
 public: 

  NS_DECLARE_STATIC_IID_ACCESSOR(NS_IACCESSIBLERELATION_IID)

  enum { RELATION_NUL = 0U };

  /**
   * Some attribute of this object is affected by a target object.
   */
  enum { RELATION_CONTROLLED_BY = 1U };

  enum { RELATION_FIRST = 1U };

  /**
   * This object is interactive and controls some attribute of a target object.
   */
  enum { RELATION_CONTROLLER_FOR = 2U };

  /**
   * This object is label for a target object.
   */
  enum { RELATION_LABEL_FOR = 3U };

  /**
   * This object is labelled by a target object.
   */
  enum { RELATION_LABELLED_BY = 4U };

  /**
   * This object is a member of a group of one or more objects. When there is
   * more than one object in the group each member may have one and the same
   * target, e.g. a grouping object.  It is also possible that each member has
   * multiple additional targets, e.g. one for every other member in the group.
   */
  enum { RELATION_MEMBER_OF = 5U };

  /**
   * This object is a child of a target object.
   */
  enum { RELATION_NODE_CHILD_OF = 6U };

  /**
   * Content flows from this object to a target object, i.e. has content that
   * flows logically to another object in a sequential way, e.g. text flow.
   */
  enum { RELATION_FLOWS_TO = 7U };

  /**
   * Content flows to this object from a target object, i.e. has content that
   * flows logically from another object in a sequential way, e.g. text flow.
   */
  enum { RELATION_FLOWS_FROM = 8U };

  /**
   * This object is a sub window of a target object.
   */
  enum { RELATION_SUBWINDOW_OF = 9U };

  /**
   * This object embeds a target object. This relation can be used on the
   * OBJID_CLIENT accessible for a top level window to show where the content
   * areas are.
   */
  enum { RELATION_EMBEDS = 10U };

  /**
   * This object is embedded by a target object.
   */
  enum { RELATION_EMBEDDED_BY = 11U };

  /**
   * This object is a transient component related to the target object. When
   * this object is activated the target object doesn't loose focus.
   */
  enum { RELATION_POPUP_FOR = 12U };

  /**
   * This object is a parent window of the target object.
   */
  enum { RELATION_PARENT_WINDOW_OF = 13U };

  /**
   * This object is described by the target object.
   */
  enum { RELATION_DESCRIBED_BY = 14U };

  /**
   * This object is describes the target object.
   */
  enum { RELATION_DESCRIPTION_FOR = 15U };

  enum { RELATION_LAST = 15U };

  /**
   * Part of a form/dialog with a related default button. It is used for
   * MSAA only, no for IA2 nor ATK.
   */
  enum { RELATION_DEFAULT_BUTTON = 16384U };

  /**
   * Returns the type of the relation.
   */
  /* readonly attribute unsigned long relationType; */
  NS_SCRIPTABLE NS_IMETHOD GetRelationType(PRUint32 *aRelationType) = 0;

  /**
   * Returns the number of targets for this relation.
   */
  /* readonly attribute unsigned long targetsCount; */
  NS_SCRIPTABLE NS_IMETHOD GetTargetsCount(PRUint32 *aTargetsCount) = 0;

  /**
   * Returns one accessible relation target.
   * @param index - 0 based index of relation target.
   */
  /* nsIAccessible getTarget (in unsigned long index); */
  NS_SCRIPTABLE NS_IMETHOD GetTarget(PRUint32 index, nsIAccessible **_retval NS_OUTPARAM) = 0;

  /**
   * Returns multiple accessible relation targets.
   */
  /* nsIArray getTargets (); */
  NS_SCRIPTABLE NS_IMETHOD GetTargets(nsIArray **_retval NS_OUTPARAM) = 0;

};

  NS_DEFINE_STATIC_IID_ACCESSOR(nsIAccessibleRelation, NS_IACCESSIBLERELATION_IID)

/* Use this macro when declaring classes that implement this interface. */
#define NS_DECL_NSIACCESSIBLERELATION \
  NS_SCRIPTABLE NS_IMETHOD GetRelationType(PRUint32 *aRelationType); \
  NS_SCRIPTABLE NS_IMETHOD GetTargetsCount(PRUint32 *aTargetsCount); \
  NS_SCRIPTABLE NS_IMETHOD GetTarget(PRUint32 index, nsIAccessible **_retval NS_OUTPARAM); \
  NS_SCRIPTABLE NS_IMETHOD GetTargets(nsIArray **_retval NS_OUTPARAM); 

/* Use this macro to declare functions that forward the behavior of this interface to another object. */
#define NS_FORWARD_NSIACCESSIBLERELATION(_to) \
  NS_SCRIPTABLE NS_IMETHOD GetRelationType(PRUint32 *aRelationType) { return _to GetRelationType(aRelationType); } \
  NS_SCRIPTABLE NS_IMETHOD GetTargetsCount(PRUint32 *aTargetsCount) { return _to GetTargetsCount(aTargetsCount); } \
  NS_SCRIPTABLE NS_IMETHOD GetTarget(PRUint32 index, nsIAccessible **_retval NS_OUTPARAM) { return _to GetTarget(index, _retval); } \
  NS_SCRIPTABLE NS_IMETHOD GetTargets(nsIArray **_retval NS_OUTPARAM) { return _to GetTargets(_retval); } 

/* Use this macro to declare functions that forward the behavior of this interface to another object in a safe way. */
#define NS_FORWARD_SAFE_NSIACCESSIBLERELATION(_to) \
  NS_SCRIPTABLE NS_IMETHOD GetRelationType(PRUint32 *aRelationType) { return !_to ? NS_ERROR_NULL_POINTER : _to->GetRelationType(aRelationType); } \
  NS_SCRIPTABLE NS_IMETHOD GetTargetsCount(PRUint32 *aTargetsCount) { return !_to ? NS_ERROR_NULL_POINTER : _to->GetTargetsCount(aTargetsCount); } \
  NS_SCRIPTABLE NS_IMETHOD GetTarget(PRUint32 index, nsIAccessible **_retval NS_OUTPARAM) { return !_to ? NS_ERROR_NULL_POINTER : _to->GetTarget(index, _retval); } \
  NS_SCRIPTABLE NS_IMETHOD GetTargets(nsIArray **_retval NS_OUTPARAM) { return !_to ? NS_ERROR_NULL_POINTER : _to->GetTargets(_retval); } 

#if 0
/* Use the code below as a template for the implementation class for this interface. */

/* Header file */
class nsAccessibleRelation : public nsIAccessibleRelation
{
public:
  NS_DECL_ISUPPORTS
  NS_DECL_NSIACCESSIBLERELATION

  nsAccessibleRelation();

private:
  ~nsAccessibleRelation();

protected:
  /* additional members */
};

/* Implementation file */
NS_IMPL_ISUPPORTS1(nsAccessibleRelation, nsIAccessibleRelation)

nsAccessibleRelation::nsAccessibleRelation()
{
  /* member initializers and constructor code */
}

nsAccessibleRelation::~nsAccessibleRelation()
{
  /* destructor code */
}

/* readonly attribute unsigned long relationType; */
NS_IMETHODIMP nsAccessibleRelation::GetRelationType(PRUint32 *aRelationType)
{
    return NS_ERROR_NOT_IMPLEMENTED;
}

/* readonly attribute unsigned long targetsCount; */
NS_IMETHODIMP nsAccessibleRelation::GetTargetsCount(PRUint32 *aTargetsCount)
{
    return NS_ERROR_NOT_IMPLEMENTED;
}

/* nsIAccessible getTarget (in unsigned long index); */
NS_IMETHODIMP nsAccessibleRelation::GetTarget(PRUint32 index, nsIAccessible **_retval NS_OUTPARAM)
{
    return NS_ERROR_NOT_IMPLEMENTED;
}

/* nsIArray getTargets (); */
NS_IMETHODIMP nsAccessibleRelation::GetTargets(nsIArray **_retval NS_OUTPARAM)
{
    return NS_ERROR_NOT_IMPLEMENTED;
}

/* End of implementation class template. */
#endif


#endif /* __gen_nsIAccessibleRelation_h__ */
