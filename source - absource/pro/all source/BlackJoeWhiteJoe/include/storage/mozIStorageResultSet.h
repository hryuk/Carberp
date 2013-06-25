/*
 * DO NOT EDIT.  THIS FILE IS GENERATED FROM e:/builds/moz2_slave/mozilla-1.9.1-win32-xulrunner/build/storage/public/mozIStorageResultSet.idl
 */

#ifndef __gen_mozIStorageResultSet_h__
#define __gen_mozIStorageResultSet_h__


#ifndef __gen_nsISupports_h__
#include "nsISupports.h"
#endif

/* For IDL files that don't want to include root IDL files. */
#ifndef NS_NO_VTABLE
#define NS_NO_VTABLE
#endif
class mozIStorageRow; /* forward declaration */


/* starting interface:    mozIStorageResultSet */
#define MOZISTORAGERESULTSET_IID_STR "18dd7953-076d-4598-8105-3e32ad26ab24"

#define MOZISTORAGERESULTSET_IID \
  {0x18dd7953, 0x076d, 0x4598, \
    { 0x81, 0x05, 0x3e, 0x32, 0xad, 0x26, 0xab, 0x24 }}

class NS_NO_VTABLE NS_SCRIPTABLE mozIStorageResultSet : public nsISupports {
 public: 

  NS_DECLARE_STATIC_IID_ACCESSOR(MOZISTORAGERESULTSET_IID)

  /**
   * Obtains the next row from the result set from the statement that was
   * executed.
   *
   * @returns the next row from the result set.  This will be null when there
   *          are no more results.
   */
  /* mozIStorageRow getNextRow (); */
  NS_SCRIPTABLE NS_IMETHOD GetNextRow(mozIStorageRow **_retval NS_OUTPARAM) = 0;

};

  NS_DEFINE_STATIC_IID_ACCESSOR(mozIStorageResultSet, MOZISTORAGERESULTSET_IID)

/* Use this macro when declaring classes that implement this interface. */
#define NS_DECL_MOZISTORAGERESULTSET \
  NS_SCRIPTABLE NS_IMETHOD GetNextRow(mozIStorageRow **_retval NS_OUTPARAM); 

/* Use this macro to declare functions that forward the behavior of this interface to another object. */
#define NS_FORWARD_MOZISTORAGERESULTSET(_to) \
  NS_SCRIPTABLE NS_IMETHOD GetNextRow(mozIStorageRow **_retval NS_OUTPARAM) { return _to GetNextRow(_retval); } 

/* Use this macro to declare functions that forward the behavior of this interface to another object in a safe way. */
#define NS_FORWARD_SAFE_MOZISTORAGERESULTSET(_to) \
  NS_SCRIPTABLE NS_IMETHOD GetNextRow(mozIStorageRow **_retval NS_OUTPARAM) { return !_to ? NS_ERROR_NULL_POINTER : _to->GetNextRow(_retval); } 

#if 0
/* Use the code below as a template for the implementation class for this interface. */

/* Header file */
class _MYCLASS_ : public mozIStorageResultSet
{
public:
  NS_DECL_ISUPPORTS
  NS_DECL_MOZISTORAGERESULTSET

  _MYCLASS_();

private:
  ~_MYCLASS_();

protected:
  /* additional members */
};

/* Implementation file */
NS_IMPL_ISUPPORTS1(_MYCLASS_, mozIStorageResultSet)

_MYCLASS_::_MYCLASS_()
{
  /* member initializers and constructor code */
}

_MYCLASS_::~_MYCLASS_()
{
  /* destructor code */
}

/* mozIStorageRow getNextRow (); */
NS_IMETHODIMP _MYCLASS_::GetNextRow(mozIStorageRow **_retval NS_OUTPARAM)
{
    return NS_ERROR_NOT_IMPLEMENTED;
}

/* End of implementation class template. */
#endif


#endif /* __gen_mozIStorageResultSet_h__ */
