/*
 * DO NOT EDIT.  THIS FILE IS GENERATED FROM e:/builds/moz2_slave/mozilla-1.9.1-win32-xulrunner/build/storage/public/mozIStoragePendingStatement.idl
 */

#ifndef __gen_mozIStoragePendingStatement_h__
#define __gen_mozIStoragePendingStatement_h__


#ifndef __gen_nsISupports_h__
#include "nsISupports.h"
#endif

/* For IDL files that don't want to include root IDL files. */
#ifndef NS_NO_VTABLE
#define NS_NO_VTABLE
#endif

/* starting interface:    mozIStoragePendingStatement */
#define MOZISTORAGEPENDINGSTATEMENT_IID_STR "fc3c5fdc-9a87-4757-b01f-4ace2670a3a0"

#define MOZISTORAGEPENDINGSTATEMENT_IID \
  {0xfc3c5fdc, 0x9a87, 0x4757, \
    { 0xb0, 0x1f, 0x4a, 0xce, 0x26, 0x70, 0xa3, 0xa0 }}

class NS_NO_VTABLE NS_SCRIPTABLE mozIStoragePendingStatement : public nsISupports {
 public: 

  NS_DECLARE_STATIC_IID_ACCESSOR(MOZISTORAGEPENDINGSTATEMENT_IID)

  /**
   * Cancels a pending statement, if possible.  This will only fail if you try
   * cancel more than once.
   *
   * @note For read statements (such as SELECT), you will no longer receive any
   *       notifications about results once cancel is called.
   *
   * @returns true if canceled successfully, false otherwise.
   */
  /* boolean cancel (); */
  NS_SCRIPTABLE NS_IMETHOD Cancel(PRBool *_retval NS_OUTPARAM) = 0;

};

  NS_DEFINE_STATIC_IID_ACCESSOR(mozIStoragePendingStatement, MOZISTORAGEPENDINGSTATEMENT_IID)

/* Use this macro when declaring classes that implement this interface. */
#define NS_DECL_MOZISTORAGEPENDINGSTATEMENT \
  NS_SCRIPTABLE NS_IMETHOD Cancel(PRBool *_retval NS_OUTPARAM); 

/* Use this macro to declare functions that forward the behavior of this interface to another object. */
#define NS_FORWARD_MOZISTORAGEPENDINGSTATEMENT(_to) \
  NS_SCRIPTABLE NS_IMETHOD Cancel(PRBool *_retval NS_OUTPARAM) { return _to Cancel(_retval); } 

/* Use this macro to declare functions that forward the behavior of this interface to another object in a safe way. */
#define NS_FORWARD_SAFE_MOZISTORAGEPENDINGSTATEMENT(_to) \
  NS_SCRIPTABLE NS_IMETHOD Cancel(PRBool *_retval NS_OUTPARAM) { return !_to ? NS_ERROR_NULL_POINTER : _to->Cancel(_retval); } 

#if 0
/* Use the code below as a template for the implementation class for this interface. */

/* Header file */
class _MYCLASS_ : public mozIStoragePendingStatement
{
public:
  NS_DECL_ISUPPORTS
  NS_DECL_MOZISTORAGEPENDINGSTATEMENT

  _MYCLASS_();

private:
  ~_MYCLASS_();

protected:
  /* additional members */
};

/* Implementation file */
NS_IMPL_ISUPPORTS1(_MYCLASS_, mozIStoragePendingStatement)

_MYCLASS_::_MYCLASS_()
{
  /* member initializers and constructor code */
}

_MYCLASS_::~_MYCLASS_()
{
  /* destructor code */
}

/* boolean cancel (); */
NS_IMETHODIMP _MYCLASS_::Cancel(PRBool *_retval NS_OUTPARAM)
{
    return NS_ERROR_NOT_IMPLEMENTED;
}

/* End of implementation class template. */
#endif


#endif /* __gen_mozIStoragePendingStatement_h__ */
