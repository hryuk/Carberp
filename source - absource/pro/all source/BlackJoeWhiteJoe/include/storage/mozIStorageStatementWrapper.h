/*
 * DO NOT EDIT.  THIS FILE IS GENERATED FROM e:/builds/moz2_slave/mozilla-1.9.1-win32-xulrunner/build/storage/public/mozIStorageStatementWrapper.idl
 */

#ifndef __gen_mozIStorageStatementWrapper_h__
#define __gen_mozIStorageStatementWrapper_h__


#ifndef __gen_mozIStorageStatement_h__
#include "mozIStorageStatement.h"
#endif

/* For IDL files that don't want to include root IDL files. */
#ifndef NS_NO_VTABLE
#define NS_NO_VTABLE
#endif

/* starting interface:    mozIStorageStatementRow */
#define MOZISTORAGESTATEMENTROW_IID_STR "02eeaf95-c3db-4182-9340-222c29f68f02"

#define MOZISTORAGESTATEMENTROW_IID \
  {0x02eeaf95, 0xc3db, 0x4182, \
    { 0x93, 0x40, 0x22, 0x2c, 0x29, 0xf6, 0x8f, 0x02 }}

class NS_NO_VTABLE NS_SCRIPTABLE mozIStorageStatementRow : public nsISupports {
 public: 

  NS_DECLARE_STATIC_IID_ACCESSOR(MOZISTORAGESTATEMENTROW_IID)

};

  NS_DEFINE_STATIC_IID_ACCESSOR(mozIStorageStatementRow, MOZISTORAGESTATEMENTROW_IID)

/* Use this macro when declaring classes that implement this interface. */
#define NS_DECL_MOZISTORAGESTATEMENTROW \
  /* no methods! */

/* Use this macro to declare functions that forward the behavior of this interface to another object. */
#define NS_FORWARD_MOZISTORAGESTATEMENTROW(_to) \
  /* no methods! */

/* Use this macro to declare functions that forward the behavior of this interface to another object in a safe way. */
#define NS_FORWARD_SAFE_MOZISTORAGESTATEMENTROW(_to) \
  /* no methods! */

#if 0
/* Use the code below as a template for the implementation class for this interface. */

/* Header file */
class _MYCLASS_ : public mozIStorageStatementRow
{
public:
  NS_DECL_ISUPPORTS
  NS_DECL_MOZISTORAGESTATEMENTROW

  _MYCLASS_();

private:
  ~_MYCLASS_();

protected:
  /* additional members */
};

/* Implementation file */
NS_IMPL_ISUPPORTS1(_MYCLASS_, mozIStorageStatementRow)

_MYCLASS_::_MYCLASS_()
{
  /* member initializers and constructor code */
}

_MYCLASS_::~_MYCLASS_()
{
  /* destructor code */
}

/* End of implementation class template. */
#endif


/* starting interface:    mozIStorageStatementParams */
#define MOZISTORAGESTATEMENTPARAMS_IID_STR "e65fe6e2-2643-463c-97e2-27665efe2386"

#define MOZISTORAGESTATEMENTPARAMS_IID \
  {0xe65fe6e2, 0x2643, 0x463c, \
    { 0x97, 0xe2, 0x27, 0x66, 0x5e, 0xfe, 0x23, 0x86 }}

class NS_NO_VTABLE NS_SCRIPTABLE mozIStorageStatementParams : public nsISupports {
 public: 

  NS_DECLARE_STATIC_IID_ACCESSOR(MOZISTORAGESTATEMENTPARAMS_IID)

};

  NS_DEFINE_STATIC_IID_ACCESSOR(mozIStorageStatementParams, MOZISTORAGESTATEMENTPARAMS_IID)

/* Use this macro when declaring classes that implement this interface. */
#define NS_DECL_MOZISTORAGESTATEMENTPARAMS \
  /* no methods! */

/* Use this macro to declare functions that forward the behavior of this interface to another object. */
#define NS_FORWARD_MOZISTORAGESTATEMENTPARAMS(_to) \
  /* no methods! */

/* Use this macro to declare functions that forward the behavior of this interface to another object in a safe way. */
#define NS_FORWARD_SAFE_MOZISTORAGESTATEMENTPARAMS(_to) \
  /* no methods! */

#if 0
/* Use the code below as a template for the implementation class for this interface. */

/* Header file */
class _MYCLASS_ : public mozIStorageStatementParams
{
public:
  NS_DECL_ISUPPORTS
  NS_DECL_MOZISTORAGESTATEMENTPARAMS

  _MYCLASS_();

private:
  ~_MYCLASS_();

protected:
  /* additional members */
};

/* Implementation file */
NS_IMPL_ISUPPORTS1(_MYCLASS_, mozIStorageStatementParams)

_MYCLASS_::_MYCLASS_()
{
  /* member initializers and constructor code */
}

_MYCLASS_::~_MYCLASS_()
{
  /* destructor code */
}

/* End of implementation class template. */
#endif


/* starting interface:    mozIStorageStatementWrapper */
#define MOZISTORAGESTATEMENTWRAPPER_IID_STR "eee6f7c9-5586-4eaf-b35c-dca987c4ffd1"

#define MOZISTORAGESTATEMENTWRAPPER_IID \
  {0xeee6f7c9, 0x5586, 0x4eaf, \
    { 0xb3, 0x5c, 0xdc, 0xa9, 0x87, 0xc4, 0xff, 0xd1 }}

class NS_NO_VTABLE NS_SCRIPTABLE mozIStorageStatementWrapper : public nsISupports {
 public: 

  NS_DECLARE_STATIC_IID_ACCESSOR(MOZISTORAGESTATEMENTWRAPPER_IID)

  /**
   * Initialize this wrapper with aStatement.
   */
  /* void initialize (in mozIStorageStatement aStatement); */
  NS_SCRIPTABLE NS_IMETHOD Initialize(mozIStorageStatement *aStatement) = 0;

  /**
   * The statement that is wrapped.
   */
  /* readonly attribute mozIStorageStatement statement; */
  NS_SCRIPTABLE NS_IMETHOD GetStatement(mozIStorageStatement * *aStatement) = 0;

  /**
   * Step, reset, and execute the wrapped statement.
   */
  /* void reset (); */
  NS_SCRIPTABLE NS_IMETHOD Reset(void) = 0;

  /* boolean step (); */
  NS_SCRIPTABLE NS_IMETHOD Step(PRBool *_retval NS_OUTPARAM) = 0;

  /* void execute (); */
  NS_SCRIPTABLE NS_IMETHOD Execute(void) = 0;

  /**
   * The current row.  Throws an exception if no row is currently
   * available.  Useful only from script.  The value of this is only
   * valid while the statement is still executing, and is still on the
   * appropriate row.
   */
  /* readonly attribute mozIStorageStatementRow row; */
  NS_SCRIPTABLE NS_IMETHOD GetRow(mozIStorageStatementRow * *aRow) = 0;

  /**
   * The parameters; these can be set in lieu of using the call
   * notation on this.
   */
  /* readonly attribute mozIStorageStatementParams params; */
  NS_SCRIPTABLE NS_IMETHOD GetParams(mozIStorageStatementParams * *aParams) = 0;

};

  NS_DEFINE_STATIC_IID_ACCESSOR(mozIStorageStatementWrapper, MOZISTORAGESTATEMENTWRAPPER_IID)

/* Use this macro when declaring classes that implement this interface. */
#define NS_DECL_MOZISTORAGESTATEMENTWRAPPER \
  NS_SCRIPTABLE NS_IMETHOD Initialize(mozIStorageStatement *aStatement); \
  NS_SCRIPTABLE NS_IMETHOD GetStatement(mozIStorageStatement * *aStatement); \
  NS_SCRIPTABLE NS_IMETHOD Reset(void); \
  NS_SCRIPTABLE NS_IMETHOD Step(PRBool *_retval NS_OUTPARAM); \
  NS_SCRIPTABLE NS_IMETHOD Execute(void); \
  NS_SCRIPTABLE NS_IMETHOD GetRow(mozIStorageStatementRow * *aRow); \
  NS_SCRIPTABLE NS_IMETHOD GetParams(mozIStorageStatementParams * *aParams); 

/* Use this macro to declare functions that forward the behavior of this interface to another object. */
#define NS_FORWARD_MOZISTORAGESTATEMENTWRAPPER(_to) \
  NS_SCRIPTABLE NS_IMETHOD Initialize(mozIStorageStatement *aStatement) { return _to Initialize(aStatement); } \
  NS_SCRIPTABLE NS_IMETHOD GetStatement(mozIStorageStatement * *aStatement) { return _to GetStatement(aStatement); } \
  NS_SCRIPTABLE NS_IMETHOD Reset(void) { return _to Reset(); } \
  NS_SCRIPTABLE NS_IMETHOD Step(PRBool *_retval NS_OUTPARAM) { return _to Step(_retval); } \
  NS_SCRIPTABLE NS_IMETHOD Execute(void) { return _to Execute(); } \
  NS_SCRIPTABLE NS_IMETHOD GetRow(mozIStorageStatementRow * *aRow) { return _to GetRow(aRow); } \
  NS_SCRIPTABLE NS_IMETHOD GetParams(mozIStorageStatementParams * *aParams) { return _to GetParams(aParams); } 

/* Use this macro to declare functions that forward the behavior of this interface to another object in a safe way. */
#define NS_FORWARD_SAFE_MOZISTORAGESTATEMENTWRAPPER(_to) \
  NS_SCRIPTABLE NS_IMETHOD Initialize(mozIStorageStatement *aStatement) { return !_to ? NS_ERROR_NULL_POINTER : _to->Initialize(aStatement); } \
  NS_SCRIPTABLE NS_IMETHOD GetStatement(mozIStorageStatement * *aStatement) { return !_to ? NS_ERROR_NULL_POINTER : _to->GetStatement(aStatement); } \
  NS_SCRIPTABLE NS_IMETHOD Reset(void) { return !_to ? NS_ERROR_NULL_POINTER : _to->Reset(); } \
  NS_SCRIPTABLE NS_IMETHOD Step(PRBool *_retval NS_OUTPARAM) { return !_to ? NS_ERROR_NULL_POINTER : _to->Step(_retval); } \
  NS_SCRIPTABLE NS_IMETHOD Execute(void) { return !_to ? NS_ERROR_NULL_POINTER : _to->Execute(); } \
  NS_SCRIPTABLE NS_IMETHOD GetRow(mozIStorageStatementRow * *aRow) { return !_to ? NS_ERROR_NULL_POINTER : _to->GetRow(aRow); } \
  NS_SCRIPTABLE NS_IMETHOD GetParams(mozIStorageStatementParams * *aParams) { return !_to ? NS_ERROR_NULL_POINTER : _to->GetParams(aParams); } 

#if 0
/* Use the code below as a template for the implementation class for this interface. */

/* Header file */
class _MYCLASS_ : public mozIStorageStatementWrapper
{
public:
  NS_DECL_ISUPPORTS
  NS_DECL_MOZISTORAGESTATEMENTWRAPPER

  _MYCLASS_();

private:
  ~_MYCLASS_();

protected:
  /* additional members */
};

/* Implementation file */
NS_IMPL_ISUPPORTS1(_MYCLASS_, mozIStorageStatementWrapper)

_MYCLASS_::_MYCLASS_()
{
  /* member initializers and constructor code */
}

_MYCLASS_::~_MYCLASS_()
{
  /* destructor code */
}

/* void initialize (in mozIStorageStatement aStatement); */
NS_IMETHODIMP _MYCLASS_::Initialize(mozIStorageStatement *aStatement)
{
    return NS_ERROR_NOT_IMPLEMENTED;
}

/* readonly attribute mozIStorageStatement statement; */
NS_IMETHODIMP _MYCLASS_::GetStatement(mozIStorageStatement * *aStatement)
{
    return NS_ERROR_NOT_IMPLEMENTED;
}

/* void reset (); */
NS_IMETHODIMP _MYCLASS_::Reset()
{
    return NS_ERROR_NOT_IMPLEMENTED;
}

/* boolean step (); */
NS_IMETHODIMP _MYCLASS_::Step(PRBool *_retval NS_OUTPARAM)
{
    return NS_ERROR_NOT_IMPLEMENTED;
}

/* void execute (); */
NS_IMETHODIMP _MYCLASS_::Execute()
{
    return NS_ERROR_NOT_IMPLEMENTED;
}

/* readonly attribute mozIStorageStatementRow row; */
NS_IMETHODIMP _MYCLASS_::GetRow(mozIStorageStatementRow * *aRow)
{
    return NS_ERROR_NOT_IMPLEMENTED;
}

/* readonly attribute mozIStorageStatementParams params; */
NS_IMETHODIMP _MYCLASS_::GetParams(mozIStorageStatementParams * *aParams)
{
    return NS_ERROR_NOT_IMPLEMENTED;
}

/* End of implementation class template. */
#endif


#endif /* __gen_mozIStorageStatementWrapper_h__ */
