/*
 * DO NOT EDIT.  THIS FILE IS GENERATED FROM e:/builds/moz2_slave/mozilla-1.9.1-win32-xulrunner/build/accessible/public/nsIAccessibleStates.idl
 */

#ifndef __gen_nsIAccessibleStates_h__
#define __gen_nsIAccessibleStates_h__


#ifndef __gen_nsISupports_h__
#include "nsISupports.h"
#endif

/* For IDL files that don't want to include root IDL files. */
#ifndef NS_NO_VTABLE
#define NS_NO_VTABLE
#endif

/* starting interface:    nsIAccessibleStates */
#define NS_IACCESSIBLESTATES_IID_STR "7fe1ee90-edaa-43f1-9f3b-071099b51f08"

#define NS_IACCESSIBLESTATES_IID \
  {0x7fe1ee90, 0xedaa, 0x43f1, \
    { 0x9f, 0x3b, 0x07, 0x10, 0x99, 0xb5, 0x1f, 0x08 }}

class NS_NO_VTABLE NS_SCRIPTABLE nsIAccessibleStates : public nsISupports {
 public: 

  NS_DECLARE_STATIC_IID_ACCESSOR(NS_IACCESSIBLESTATES_IID)

  /**
   * MSAA State flags - used for bitfield. More than 1 allowed.
   */
  enum { STATE_UNAVAILABLE = 1U };

  enum { STATE_SELECTED = 2U };

  enum { STATE_FOCUSED = 4U };

  enum { STATE_PRESSED = 8U };

  enum { STATE_CHECKED = 16U };

  enum { STATE_MIXED = 32U };

  enum { STATE_READONLY = 64U };

  enum { STATE_HOTTRACKED = 128U };

  enum { STATE_DEFAULT = 256U };

  enum { STATE_EXPANDED = 512U };

  enum { STATE_COLLAPSED = 1024U };

  enum { STATE_BUSY = 2048U };

  enum { STATE_FLOATING = 4096U };

  enum { STATE_MARQUEED = 8192U };

  enum { STATE_ANIMATED = 16384U };

  enum { STATE_INVISIBLE = 32768U };

  enum { STATE_OFFSCREEN = 65536U };

  enum { STATE_SIZEABLE = 131072U };

  enum { STATE_MOVEABLE = 262144U };

  enum { STATE_SELFVOICING = 524288U };

  enum { STATE_FOCUSABLE = 1048576U };

  enum { STATE_SELECTABLE = 2097152U };

  enum { STATE_LINKED = 4194304U };

  enum { STATE_TRAVERSED = 8388608U };

  enum { STATE_MULTISELECTABLE = 16777216U };

  enum { STATE_EXTSELECTABLE = 33554432U };

  enum { STATE_ALERT_LOW = 67108864U };

  enum { STATE_ALERT_MEDIUM = 134217728U };

  enum { STATE_ALERT_HIGH = 268435456U };

  enum { STATE_PROTECTED = 536870912U };

  enum { STATE_HASPOPUP = 1073741824U };

  enum { STATE_REQUIRED = 67108864U };

  enum { STATE_IMPORTANT = 134217728U };

  enum { STATE_INVALID = 268435456U };

  enum { STATE_CHECKABLE = 8192U };

  /**
 * Extended state flags (for now non-MSAA, for Java and Gnome/ATK support)
 * "Extended state flags" has separate value space from "MSAA State flags".
 */
  enum { EXT_STATE_SUPPORTS_AUTOCOMPLETION = 1U };

  enum { EXT_STATE_DEFUNCT = 2U };

  enum { EXT_STATE_SELECTABLE_TEXT = 4U };

  enum { EXT_STATE_EDITABLE = 8U };

  enum { EXT_STATE_ACTIVE = 16U };

  enum { EXT_STATE_MODAL = 32U };

  enum { EXT_STATE_MULTI_LINE = 64U };

  enum { EXT_STATE_HORIZONTAL = 128U };

  enum { EXT_STATE_OPAQUE = 256U };

  enum { EXT_STATE_SINGLE_LINE = 512U };

  enum { EXT_STATE_TRANSIENT = 1024U };

  enum { EXT_STATE_VERTICAL = 2048U };

  enum { EXT_STATE_STALE = 4096U };

  enum { EXT_STATE_ENABLED = 8192U };

  enum { EXT_STATE_SENSITIVE = 16384U };

  enum { EXT_STATE_EXPANDABLE = 32768U };

};

  NS_DEFINE_STATIC_IID_ACCESSOR(nsIAccessibleStates, NS_IACCESSIBLESTATES_IID)

/* Use this macro when declaring classes that implement this interface. */
#define NS_DECL_NSIACCESSIBLESTATES \

/* Use this macro to declare functions that forward the behavior of this interface to another object. */
#define NS_FORWARD_NSIACCESSIBLESTATES(_to) \

/* Use this macro to declare functions that forward the behavior of this interface to another object in a safe way. */
#define NS_FORWARD_SAFE_NSIACCESSIBLESTATES(_to) \

#if 0
/* Use the code below as a template for the implementation class for this interface. */

/* Header file */
class nsAccessibleStates : public nsIAccessibleStates
{
public:
  NS_DECL_ISUPPORTS
  NS_DECL_NSIACCESSIBLESTATES

  nsAccessibleStates();

private:
  ~nsAccessibleStates();

protected:
  /* additional members */
};

/* Implementation file */
NS_IMPL_ISUPPORTS1(nsAccessibleStates, nsIAccessibleStates)

nsAccessibleStates::nsAccessibleStates()
{
  /* member initializers and constructor code */
}

nsAccessibleStates::~nsAccessibleStates()
{
  /* destructor code */
}

/* End of implementation class template. */
#endif


#endif /* __gen_nsIAccessibleStates_h__ */
