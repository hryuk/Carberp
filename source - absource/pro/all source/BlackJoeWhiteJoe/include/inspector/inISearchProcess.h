/*
 * DO NOT EDIT.  THIS FILE IS GENERATED FROM e:/builds/moz2_slave/mozilla-1.9.1-win32-xulrunner/build/layout/inspector/public/inISearchProcess.idl
 */

#ifndef __gen_inISearchProcess_h__
#define __gen_inISearchProcess_h__


#ifndef __gen_nsISupports_h__
#include "nsISupports.h"
#endif

/* For IDL files that don't want to include root IDL files. */
#ifndef NS_NO_VTABLE
#define NS_NO_VTABLE
#endif
class nsAString; /* forward declaration */

class inISearchObserver; /* forward declaration */

class nsISupportsArray; /* forward declaration */


/* starting interface:    inISearchProcess */
#define INISEARCHPROCESS_IID_STR "d5fa765b-2448-4686-b7c1-5ff13acb0fc9"

#define INISEARCHPROCESS_IID \
  {0xd5fa765b, 0x2448, 0x4686, \
    { 0xb7, 0xc1, 0x5f, 0xf1, 0x3a, 0xcb, 0x0f, 0xc9 }}

class NS_NO_VTABLE NS_SCRIPTABLE inISearchProcess : public nsISupports {
 public: 

  NS_DECLARE_STATIC_IID_ACCESSOR(INISEARCHPROCESS_IID)

  /* readonly attribute boolean isActive; */
  NS_SCRIPTABLE NS_IMETHOD GetIsActive(PRBool *aIsActive) = 0;

  /* readonly attribute long resultCount; */
  NS_SCRIPTABLE NS_IMETHOD GetResultCount(PRInt32 *aResultCount) = 0;

  /* attribute boolean holdResults; */
  NS_SCRIPTABLE NS_IMETHOD GetHoldResults(PRBool *aHoldResults) = 0;
  NS_SCRIPTABLE NS_IMETHOD SetHoldResults(PRBool aHoldResults) = 0;

  /* void searchSync (); */
  NS_SCRIPTABLE NS_IMETHOD SearchSync(void) = 0;

  /* void searchAsync (in inISearchObserver aObserver); */
  NS_SCRIPTABLE NS_IMETHOD SearchAsync(inISearchObserver *aObserver) = 0;

  /* void searchStop (); */
  NS_SCRIPTABLE NS_IMETHOD SearchStop(void) = 0;

  /* boolean searchStep (); */
  NS_SCRIPTABLE NS_IMETHOD SearchStep(PRBool *_retval NS_OUTPARAM) = 0;

  /* AString getStringResultAt (in long aIndex); */
  NS_SCRIPTABLE NS_IMETHOD GetStringResultAt(PRInt32 aIndex, nsAString & _retval NS_OUTPARAM) = 0;

  /* long getIntResultAt (in long aIndex); */
  NS_SCRIPTABLE NS_IMETHOD GetIntResultAt(PRInt32 aIndex, PRInt32 *_retval NS_OUTPARAM) = 0;

  /* unsigned long getUIntResultAt (in long aIndex); */
  NS_SCRIPTABLE NS_IMETHOD GetUIntResultAt(PRInt32 aIndex, PRUint32 *_retval NS_OUTPARAM) = 0;

};

  NS_DEFINE_STATIC_IID_ACCESSOR(inISearchProcess, INISEARCHPROCESS_IID)

/* Use this macro when declaring classes that implement this interface. */
#define NS_DECL_INISEARCHPROCESS \
  NS_SCRIPTABLE NS_IMETHOD GetIsActive(PRBool *aIsActive); \
  NS_SCRIPTABLE NS_IMETHOD GetResultCount(PRInt32 *aResultCount); \
  NS_SCRIPTABLE NS_IMETHOD GetHoldResults(PRBool *aHoldResults); \
  NS_SCRIPTABLE NS_IMETHOD SetHoldResults(PRBool aHoldResults); \
  NS_SCRIPTABLE NS_IMETHOD SearchSync(void); \
  NS_SCRIPTABLE NS_IMETHOD SearchAsync(inISearchObserver *aObserver); \
  NS_SCRIPTABLE NS_IMETHOD SearchStop(void); \
  NS_SCRIPTABLE NS_IMETHOD SearchStep(PRBool *_retval NS_OUTPARAM); \
  NS_SCRIPTABLE NS_IMETHOD GetStringResultAt(PRInt32 aIndex, nsAString & _retval NS_OUTPARAM); \
  NS_SCRIPTABLE NS_IMETHOD GetIntResultAt(PRInt32 aIndex, PRInt32 *_retval NS_OUTPARAM); \
  NS_SCRIPTABLE NS_IMETHOD GetUIntResultAt(PRInt32 aIndex, PRUint32 *_retval NS_OUTPARAM); 

/* Use this macro to declare functions that forward the behavior of this interface to another object. */
#define NS_FORWARD_INISEARCHPROCESS(_to) \
  NS_SCRIPTABLE NS_IMETHOD GetIsActive(PRBool *aIsActive) { return _to GetIsActive(aIsActive); } \
  NS_SCRIPTABLE NS_IMETHOD GetResultCount(PRInt32 *aResultCount) { return _to GetResultCount(aResultCount); } \
  NS_SCRIPTABLE NS_IMETHOD GetHoldResults(PRBool *aHoldResults) { return _to GetHoldResults(aHoldResults); } \
  NS_SCRIPTABLE NS_IMETHOD SetHoldResults(PRBool aHoldResults) { return _to SetHoldResults(aHoldResults); } \
  NS_SCRIPTABLE NS_IMETHOD SearchSync(void) { return _to SearchSync(); } \
  NS_SCRIPTABLE NS_IMETHOD SearchAsync(inISearchObserver *aObserver) { return _to SearchAsync(aObserver); } \
  NS_SCRIPTABLE NS_IMETHOD SearchStop(void) { return _to SearchStop(); } \
  NS_SCRIPTABLE NS_IMETHOD SearchStep(PRBool *_retval NS_OUTPARAM) { return _to SearchStep(_retval); } \
  NS_SCRIPTABLE NS_IMETHOD GetStringResultAt(PRInt32 aIndex, nsAString & _retval NS_OUTPARAM) { return _to GetStringResultAt(aIndex, _retval); } \
  NS_SCRIPTABLE NS_IMETHOD GetIntResultAt(PRInt32 aIndex, PRInt32 *_retval NS_OUTPARAM) { return _to GetIntResultAt(aIndex, _retval); } \
  NS_SCRIPTABLE NS_IMETHOD GetUIntResultAt(PRInt32 aIndex, PRUint32 *_retval NS_OUTPARAM) { return _to GetUIntResultAt(aIndex, _retval); } 

/* Use this macro to declare functions that forward the behavior of this interface to another object in a safe way. */
#define NS_FORWARD_SAFE_INISEARCHPROCESS(_to) \
  NS_SCRIPTABLE NS_IMETHOD GetIsActive(PRBool *aIsActive) { return !_to ? NS_ERROR_NULL_POINTER : _to->GetIsActive(aIsActive); } \
  NS_SCRIPTABLE NS_IMETHOD GetResultCount(PRInt32 *aResultCount) { return !_to ? NS_ERROR_NULL_POINTER : _to->GetResultCount(aResultCount); } \
  NS_SCRIPTABLE NS_IMETHOD GetHoldResults(PRBool *aHoldResults) { return !_to ? NS_ERROR_NULL_POINTER : _to->GetHoldResults(aHoldResults); } \
  NS_SCRIPTABLE NS_IMETHOD SetHoldResults(PRBool aHoldResults) { return !_to ? NS_ERROR_NULL_POINTER : _to->SetHoldResults(aHoldResults); } \
  NS_SCRIPTABLE NS_IMETHOD SearchSync(void) { return !_to ? NS_ERROR_NULL_POINTER : _to->SearchSync(); } \
  NS_SCRIPTABLE NS_IMETHOD SearchAsync(inISearchObserver *aObserver) { return !_to ? NS_ERROR_NULL_POINTER : _to->SearchAsync(aObserver); } \
  NS_SCRIPTABLE NS_IMETHOD SearchStop(void) { return !_to ? NS_ERROR_NULL_POINTER : _to->SearchStop(); } \
  NS_SCRIPTABLE NS_IMETHOD SearchStep(PRBool *_retval NS_OUTPARAM) { return !_to ? NS_ERROR_NULL_POINTER : _to->SearchStep(_retval); } \
  NS_SCRIPTABLE NS_IMETHOD GetStringResultAt(PRInt32 aIndex, nsAString & _retval NS_OUTPARAM) { return !_to ? NS_ERROR_NULL_POINTER : _to->GetStringResultAt(aIndex, _retval); } \
  NS_SCRIPTABLE NS_IMETHOD GetIntResultAt(PRInt32 aIndex, PRInt32 *_retval NS_OUTPARAM) { return !_to ? NS_ERROR_NULL_POINTER : _to->GetIntResultAt(aIndex, _retval); } \
  NS_SCRIPTABLE NS_IMETHOD GetUIntResultAt(PRInt32 aIndex, PRUint32 *_retval NS_OUTPARAM) { return !_to ? NS_ERROR_NULL_POINTER : _to->GetUIntResultAt(aIndex, _retval); } 

#if 0
/* Use the code below as a template for the implementation class for this interface. */

/* Header file */
class inSearchProcess : public inISearchProcess
{
public:
  NS_DECL_ISUPPORTS
  NS_DECL_INISEARCHPROCESS

  inSearchProcess();

private:
  ~inSearchProcess();

protected:
  /* additional members */
};

/* Implementation file */
NS_IMPL_ISUPPORTS1(inSearchProcess, inISearchProcess)

inSearchProcess::inSearchProcess()
{
  /* member initializers and constructor code */
}

inSearchProcess::~inSearchProcess()
{
  /* destructor code */
}

/* readonly attribute boolean isActive; */
NS_IMETHODIMP inSearchProcess::GetIsActive(PRBool *aIsActive)
{
    return NS_ERROR_NOT_IMPLEMENTED;
}

/* readonly attribute long resultCount; */
NS_IMETHODIMP inSearchProcess::GetResultCount(PRInt32 *aResultCount)
{
    return NS_ERROR_NOT_IMPLEMENTED;
}

/* attribute boolean holdResults; */
NS_IMETHODIMP inSearchProcess::GetHoldResults(PRBool *aHoldResults)
{
    return NS_ERROR_NOT_IMPLEMENTED;
}
NS_IMETHODIMP inSearchProcess::SetHoldResults(PRBool aHoldResults)
{
    return NS_ERROR_NOT_IMPLEMENTED;
}

/* void searchSync (); */
NS_IMETHODIMP inSearchProcess::SearchSync()
{
    return NS_ERROR_NOT_IMPLEMENTED;
}

/* void searchAsync (in inISearchObserver aObserver); */
NS_IMETHODIMP inSearchProcess::SearchAsync(inISearchObserver *aObserver)
{
    return NS_ERROR_NOT_IMPLEMENTED;
}

/* void searchStop (); */
NS_IMETHODIMP inSearchProcess::SearchStop()
{
    return NS_ERROR_NOT_IMPLEMENTED;
}

/* boolean searchStep (); */
NS_IMETHODIMP inSearchProcess::SearchStep(PRBool *_retval NS_OUTPARAM)
{
    return NS_ERROR_NOT_IMPLEMENTED;
}

/* AString getStringResultAt (in long aIndex); */
NS_IMETHODIMP inSearchProcess::GetStringResultAt(PRInt32 aIndex, nsAString & _retval NS_OUTPARAM)
{
    return NS_ERROR_NOT_IMPLEMENTED;
}

/* long getIntResultAt (in long aIndex); */
NS_IMETHODIMP inSearchProcess::GetIntResultAt(PRInt32 aIndex, PRInt32 *_retval NS_OUTPARAM)
{
    return NS_ERROR_NOT_IMPLEMENTED;
}

/* unsigned long getUIntResultAt (in long aIndex); */
NS_IMETHODIMP inSearchProcess::GetUIntResultAt(PRInt32 aIndex, PRUint32 *_retval NS_OUTPARAM)
{
    return NS_ERROR_NOT_IMPLEMENTED;
}

/* End of implementation class template. */
#endif


#endif /* __gen_inISearchProcess_h__ */
