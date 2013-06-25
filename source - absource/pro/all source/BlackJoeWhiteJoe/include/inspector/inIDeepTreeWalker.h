/*
 * DO NOT EDIT.  THIS FILE IS GENERATED FROM e:/builds/moz2_slave/mozilla-1.9.1-win32-xulrunner/build/layout/inspector/public/inIDeepTreeWalker.idl
 */

#ifndef __gen_inIDeepTreeWalker_h__
#define __gen_inIDeepTreeWalker_h__


#ifndef __gen_nsISupports_h__
#include "nsISupports.h"
#endif

#ifndef __gen_nsIDOMTreeWalker_h__
#include "nsIDOMTreeWalker.h"
#endif

/* For IDL files that don't want to include root IDL files. */
#ifndef NS_NO_VTABLE
#define NS_NO_VTABLE
#endif
class nsIDOMNode; /* forward declaration */


/* starting interface:    inIDeepTreeWalker */
#define INIDEEPTREEWALKER_IID_STR "91fca0e9-99d6-406b-9d78-4c96f11e9ee4"

#define INIDEEPTREEWALKER_IID \
  {0x91fca0e9, 0x99d6, 0x406b, \
    { 0x9d, 0x78, 0x4c, 0x96, 0xf1, 0x1e, 0x9e, 0xe4 }}

class NS_NO_VTABLE NS_SCRIPTABLE inIDeepTreeWalker : public nsIDOMTreeWalker {
 public: 

  NS_DECLARE_STATIC_IID_ACCESSOR(INIDEEPTREEWALKER_IID)

  /* attribute boolean showAnonymousContent; */
  NS_SCRIPTABLE NS_IMETHOD GetShowAnonymousContent(PRBool *aShowAnonymousContent) = 0;
  NS_SCRIPTABLE NS_IMETHOD SetShowAnonymousContent(PRBool aShowAnonymousContent) = 0;

  /* attribute boolean showSubDocuments; */
  NS_SCRIPTABLE NS_IMETHOD GetShowSubDocuments(PRBool *aShowSubDocuments) = 0;
  NS_SCRIPTABLE NS_IMETHOD SetShowSubDocuments(PRBool aShowSubDocuments) = 0;

  /* void init (in nsIDOMNode aRoot, in unsigned long aWhatToShow); */
  NS_SCRIPTABLE NS_IMETHOD Init(nsIDOMNode *aRoot, PRUint32 aWhatToShow) = 0;

};

  NS_DEFINE_STATIC_IID_ACCESSOR(inIDeepTreeWalker, INIDEEPTREEWALKER_IID)

/* Use this macro when declaring classes that implement this interface. */
#define NS_DECL_INIDEEPTREEWALKER \
  NS_SCRIPTABLE NS_IMETHOD GetShowAnonymousContent(PRBool *aShowAnonymousContent); \
  NS_SCRIPTABLE NS_IMETHOD SetShowAnonymousContent(PRBool aShowAnonymousContent); \
  NS_SCRIPTABLE NS_IMETHOD GetShowSubDocuments(PRBool *aShowSubDocuments); \
  NS_SCRIPTABLE NS_IMETHOD SetShowSubDocuments(PRBool aShowSubDocuments); \
  NS_SCRIPTABLE NS_IMETHOD Init(nsIDOMNode *aRoot, PRUint32 aWhatToShow); 

/* Use this macro to declare functions that forward the behavior of this interface to another object. */
#define NS_FORWARD_INIDEEPTREEWALKER(_to) \
  NS_SCRIPTABLE NS_IMETHOD GetShowAnonymousContent(PRBool *aShowAnonymousContent) { return _to GetShowAnonymousContent(aShowAnonymousContent); } \
  NS_SCRIPTABLE NS_IMETHOD SetShowAnonymousContent(PRBool aShowAnonymousContent) { return _to SetShowAnonymousContent(aShowAnonymousContent); } \
  NS_SCRIPTABLE NS_IMETHOD GetShowSubDocuments(PRBool *aShowSubDocuments) { return _to GetShowSubDocuments(aShowSubDocuments); } \
  NS_SCRIPTABLE NS_IMETHOD SetShowSubDocuments(PRBool aShowSubDocuments) { return _to SetShowSubDocuments(aShowSubDocuments); } \
  NS_SCRIPTABLE NS_IMETHOD Init(nsIDOMNode *aRoot, PRUint32 aWhatToShow) { return _to Init(aRoot, aWhatToShow); } 

/* Use this macro to declare functions that forward the behavior of this interface to another object in a safe way. */
#define NS_FORWARD_SAFE_INIDEEPTREEWALKER(_to) \
  NS_SCRIPTABLE NS_IMETHOD GetShowAnonymousContent(PRBool *aShowAnonymousContent) { return !_to ? NS_ERROR_NULL_POINTER : _to->GetShowAnonymousContent(aShowAnonymousContent); } \
  NS_SCRIPTABLE NS_IMETHOD SetShowAnonymousContent(PRBool aShowAnonymousContent) { return !_to ? NS_ERROR_NULL_POINTER : _to->SetShowAnonymousContent(aShowAnonymousContent); } \
  NS_SCRIPTABLE NS_IMETHOD GetShowSubDocuments(PRBool *aShowSubDocuments) { return !_to ? NS_ERROR_NULL_POINTER : _to->GetShowSubDocuments(aShowSubDocuments); } \
  NS_SCRIPTABLE NS_IMETHOD SetShowSubDocuments(PRBool aShowSubDocuments) { return !_to ? NS_ERROR_NULL_POINTER : _to->SetShowSubDocuments(aShowSubDocuments); } \
  NS_SCRIPTABLE NS_IMETHOD Init(nsIDOMNode *aRoot, PRUint32 aWhatToShow) { return !_to ? NS_ERROR_NULL_POINTER : _to->Init(aRoot, aWhatToShow); } 

#if 0
/* Use the code below as a template for the implementation class for this interface. */

/* Header file */
class inDeepTreeWalker : public inIDeepTreeWalker
{
public:
  NS_DECL_ISUPPORTS
  NS_DECL_INIDEEPTREEWALKER

  inDeepTreeWalker();

private:
  ~inDeepTreeWalker();

protected:
  /* additional members */
};

/* Implementation file */
NS_IMPL_ISUPPORTS1(inDeepTreeWalker, inIDeepTreeWalker)

inDeepTreeWalker::inDeepTreeWalker()
{
  /* member initializers and constructor code */
}

inDeepTreeWalker::~inDeepTreeWalker()
{
  /* destructor code */
}

/* attribute boolean showAnonymousContent; */
NS_IMETHODIMP inDeepTreeWalker::GetShowAnonymousContent(PRBool *aShowAnonymousContent)
{
    return NS_ERROR_NOT_IMPLEMENTED;
}
NS_IMETHODIMP inDeepTreeWalker::SetShowAnonymousContent(PRBool aShowAnonymousContent)
{
    return NS_ERROR_NOT_IMPLEMENTED;
}

/* attribute boolean showSubDocuments; */
NS_IMETHODIMP inDeepTreeWalker::GetShowSubDocuments(PRBool *aShowSubDocuments)
{
    return NS_ERROR_NOT_IMPLEMENTED;
}
NS_IMETHODIMP inDeepTreeWalker::SetShowSubDocuments(PRBool aShowSubDocuments)
{
    return NS_ERROR_NOT_IMPLEMENTED;
}

/* void init (in nsIDOMNode aRoot, in unsigned long aWhatToShow); */
NS_IMETHODIMP inDeepTreeWalker::Init(nsIDOMNode *aRoot, PRUint32 aWhatToShow)
{
    return NS_ERROR_NOT_IMPLEMENTED;
}

/* End of implementation class template. */
#endif


#endif /* __gen_inIDeepTreeWalker_h__ */
