/*
 * DO NOT EDIT.  THIS FILE IS GENERATED FROM e:/builds/moz2_slave/mozilla-1.9.1-win32-xulrunner/build/rdf/base/idl/nsIRDFContainerUtils.idl
 */

#ifndef __gen_nsIRDFContainerUtils_h__
#define __gen_nsIRDFContainerUtils_h__


#ifndef __gen_nsISupports_h__
#include "nsISupports.h"
#endif

#ifndef __gen_nsIRDFContainer_h__
#include "nsIRDFContainer.h"
#endif

#ifndef __gen_nsIRDFResource_h__
#include "nsIRDFResource.h"
#endif

/* For IDL files that don't want to include root IDL files. */
#ifndef NS_NO_VTABLE
#define NS_NO_VTABLE
#endif

/* starting interface:    nsIRDFContainerUtils */
#define NS_IRDFCONTAINERUTILS_IID_STR "d4214e91-fb94-11d2-bdd8-00104bde6048"

#define NS_IRDFCONTAINERUTILS_IID \
  {0xd4214e91, 0xfb94, 0x11d2, \
    { 0xbd, 0xd8, 0x00, 0x10, 0x4b, 0xde, 0x60, 0x48 }}

class NS_NO_VTABLE NS_SCRIPTABLE nsIRDFContainerUtils : public nsISupports {
 public: 

  NS_DECLARE_STATIC_IID_ACCESSOR(NS_IRDFCONTAINERUTILS_IID)

  /**
     * Returns 'true' if the property is an RDF ordinal property.
     */
  /* boolean IsOrdinalProperty (in nsIRDFResource aProperty); */
  NS_SCRIPTABLE NS_IMETHOD IsOrdinalProperty(nsIRDFResource *aProperty, PRBool *_retval NS_OUTPARAM) = 0;

  /**
     * Convert the specified index to an ordinal property.
     */
  /* nsIRDFResource IndexToOrdinalResource (in long aIndex); */
  NS_SCRIPTABLE NS_IMETHOD IndexToOrdinalResource(PRInt32 aIndex, nsIRDFResource **_retval NS_OUTPARAM) = 0;

  /**
     * Convert the specified ordinal property into an index
     */
  /* long OrdinalResourceToIndex (in nsIRDFResource aOrdinal); */
  NS_SCRIPTABLE NS_IMETHOD OrdinalResourceToIndex(nsIRDFResource *aOrdinal, PRInt32 *_retval NS_OUTPARAM) = 0;

  /**
     * Return 'true' if the specified resource is a container
     */
  /* boolean IsContainer (in nsIRDFDataSource aDataSource, in nsIRDFResource aResource); */
  NS_SCRIPTABLE NS_IMETHOD IsContainer(nsIRDFDataSource *aDataSource, nsIRDFResource *aResource, PRBool *_retval NS_OUTPARAM) = 0;

  /**
     * Return 'true' if the specified resource is a container and it is empty
     */
  /* boolean IsEmpty (in nsIRDFDataSource aDataSource, in nsIRDFResource aResource); */
  NS_SCRIPTABLE NS_IMETHOD IsEmpty(nsIRDFDataSource *aDataSource, nsIRDFResource *aResource, PRBool *_retval NS_OUTPARAM) = 0;

  /**
     * Return 'true' if the specified resource is a bag
     */
  /* boolean IsBag (in nsIRDFDataSource aDataSource, in nsIRDFResource aResource); */
  NS_SCRIPTABLE NS_IMETHOD IsBag(nsIRDFDataSource *aDataSource, nsIRDFResource *aResource, PRBool *_retval NS_OUTPARAM) = 0;

  /**
     * Return 'true' if the specified resource is a sequence
     */
  /* boolean IsSeq (in nsIRDFDataSource aDataSource, in nsIRDFResource aResource); */
  NS_SCRIPTABLE NS_IMETHOD IsSeq(nsIRDFDataSource *aDataSource, nsIRDFResource *aResource, PRBool *_retval NS_OUTPARAM) = 0;

  /**
     * Return 'true' if the specified resource is an alternation
     */
  /* boolean IsAlt (in nsIRDFDataSource aDataSource, in nsIRDFResource aResource); */
  NS_SCRIPTABLE NS_IMETHOD IsAlt(nsIRDFDataSource *aDataSource, nsIRDFResource *aResource, PRBool *_retval NS_OUTPARAM) = 0;

  /**
     * Decorates the specified resource appropriately to make it
     * usable as an empty bag in the specified data source.
     */
  /* nsIRDFContainer MakeBag (in nsIRDFDataSource aDataSource, in nsIRDFResource aResource); */
  NS_SCRIPTABLE NS_IMETHOD MakeBag(nsIRDFDataSource *aDataSource, nsIRDFResource *aResource, nsIRDFContainer **_retval NS_OUTPARAM) = 0;

  /**
     * Decorates the specified resource appropriately to make it
     * usable as an empty sequence in the specified data source.
     */
  /* nsIRDFContainer MakeSeq (in nsIRDFDataSource aDataSource, in nsIRDFResource aResource); */
  NS_SCRIPTABLE NS_IMETHOD MakeSeq(nsIRDFDataSource *aDataSource, nsIRDFResource *aResource, nsIRDFContainer **_retval NS_OUTPARAM) = 0;

  /**
     * Decorates the specified resource appropriately to make it
     * usable as an empty alternation in the specified data source.
     */
  /* nsIRDFContainer MakeAlt (in nsIRDFDataSource aDataSource, in nsIRDFResource aResource); */
  NS_SCRIPTABLE NS_IMETHOD MakeAlt(nsIRDFDataSource *aDataSource, nsIRDFResource *aResource, nsIRDFContainer **_retval NS_OUTPARAM) = 0;

  /**
     * Retrieve the index of element in the container. Returns -1 if
     * the element is not in the container.
     */
  /* long indexOf (in nsIRDFDataSource aDataSource, in nsIRDFResource aContainer, in nsIRDFNode aElement); */
  NS_SCRIPTABLE NS_IMETHOD IndexOf(nsIRDFDataSource *aDataSource, nsIRDFResource *aContainer, nsIRDFNode *aElement, PRInt32 *_retval NS_OUTPARAM) = 0;

};

  NS_DEFINE_STATIC_IID_ACCESSOR(nsIRDFContainerUtils, NS_IRDFCONTAINERUTILS_IID)

/* Use this macro when declaring classes that implement this interface. */
#define NS_DECL_NSIRDFCONTAINERUTILS \
  NS_SCRIPTABLE NS_IMETHOD IsOrdinalProperty(nsIRDFResource *aProperty, PRBool *_retval NS_OUTPARAM); \
  NS_SCRIPTABLE NS_IMETHOD IndexToOrdinalResource(PRInt32 aIndex, nsIRDFResource **_retval NS_OUTPARAM); \
  NS_SCRIPTABLE NS_IMETHOD OrdinalResourceToIndex(nsIRDFResource *aOrdinal, PRInt32 *_retval NS_OUTPARAM); \
  NS_SCRIPTABLE NS_IMETHOD IsContainer(nsIRDFDataSource *aDataSource, nsIRDFResource *aResource, PRBool *_retval NS_OUTPARAM); \
  NS_SCRIPTABLE NS_IMETHOD IsEmpty(nsIRDFDataSource *aDataSource, nsIRDFResource *aResource, PRBool *_retval NS_OUTPARAM); \
  NS_SCRIPTABLE NS_IMETHOD IsBag(nsIRDFDataSource *aDataSource, nsIRDFResource *aResource, PRBool *_retval NS_OUTPARAM); \
  NS_SCRIPTABLE NS_IMETHOD IsSeq(nsIRDFDataSource *aDataSource, nsIRDFResource *aResource, PRBool *_retval NS_OUTPARAM); \
  NS_SCRIPTABLE NS_IMETHOD IsAlt(nsIRDFDataSource *aDataSource, nsIRDFResource *aResource, PRBool *_retval NS_OUTPARAM); \
  NS_SCRIPTABLE NS_IMETHOD MakeBag(nsIRDFDataSource *aDataSource, nsIRDFResource *aResource, nsIRDFContainer **_retval NS_OUTPARAM); \
  NS_SCRIPTABLE NS_IMETHOD MakeSeq(nsIRDFDataSource *aDataSource, nsIRDFResource *aResource, nsIRDFContainer **_retval NS_OUTPARAM); \
  NS_SCRIPTABLE NS_IMETHOD MakeAlt(nsIRDFDataSource *aDataSource, nsIRDFResource *aResource, nsIRDFContainer **_retval NS_OUTPARAM); \
  NS_SCRIPTABLE NS_IMETHOD IndexOf(nsIRDFDataSource *aDataSource, nsIRDFResource *aContainer, nsIRDFNode *aElement, PRInt32 *_retval NS_OUTPARAM); 

/* Use this macro to declare functions that forward the behavior of this interface to another object. */
#define NS_FORWARD_NSIRDFCONTAINERUTILS(_to) \
  NS_SCRIPTABLE NS_IMETHOD IsOrdinalProperty(nsIRDFResource *aProperty, PRBool *_retval NS_OUTPARAM) { return _to IsOrdinalProperty(aProperty, _retval); } \
  NS_SCRIPTABLE NS_IMETHOD IndexToOrdinalResource(PRInt32 aIndex, nsIRDFResource **_retval NS_OUTPARAM) { return _to IndexToOrdinalResource(aIndex, _retval); } \
  NS_SCRIPTABLE NS_IMETHOD OrdinalResourceToIndex(nsIRDFResource *aOrdinal, PRInt32 *_retval NS_OUTPARAM) { return _to OrdinalResourceToIndex(aOrdinal, _retval); } \
  NS_SCRIPTABLE NS_IMETHOD IsContainer(nsIRDFDataSource *aDataSource, nsIRDFResource *aResource, PRBool *_retval NS_OUTPARAM) { return _to IsContainer(aDataSource, aResource, _retval); } \
  NS_SCRIPTABLE NS_IMETHOD IsEmpty(nsIRDFDataSource *aDataSource, nsIRDFResource *aResource, PRBool *_retval NS_OUTPARAM) { return _to IsEmpty(aDataSource, aResource, _retval); } \
  NS_SCRIPTABLE NS_IMETHOD IsBag(nsIRDFDataSource *aDataSource, nsIRDFResource *aResource, PRBool *_retval NS_OUTPARAM) { return _to IsBag(aDataSource, aResource, _retval); } \
  NS_SCRIPTABLE NS_IMETHOD IsSeq(nsIRDFDataSource *aDataSource, nsIRDFResource *aResource, PRBool *_retval NS_OUTPARAM) { return _to IsSeq(aDataSource, aResource, _retval); } \
  NS_SCRIPTABLE NS_IMETHOD IsAlt(nsIRDFDataSource *aDataSource, nsIRDFResource *aResource, PRBool *_retval NS_OUTPARAM) { return _to IsAlt(aDataSource, aResource, _retval); } \
  NS_SCRIPTABLE NS_IMETHOD MakeBag(nsIRDFDataSource *aDataSource, nsIRDFResource *aResource, nsIRDFContainer **_retval NS_OUTPARAM) { return _to MakeBag(aDataSource, aResource, _retval); } \
  NS_SCRIPTABLE NS_IMETHOD MakeSeq(nsIRDFDataSource *aDataSource, nsIRDFResource *aResource, nsIRDFContainer **_retval NS_OUTPARAM) { return _to MakeSeq(aDataSource, aResource, _retval); } \
  NS_SCRIPTABLE NS_IMETHOD MakeAlt(nsIRDFDataSource *aDataSource, nsIRDFResource *aResource, nsIRDFContainer **_retval NS_OUTPARAM) { return _to MakeAlt(aDataSource, aResource, _retval); } \
  NS_SCRIPTABLE NS_IMETHOD IndexOf(nsIRDFDataSource *aDataSource, nsIRDFResource *aContainer, nsIRDFNode *aElement, PRInt32 *_retval NS_OUTPARAM) { return _to IndexOf(aDataSource, aContainer, aElement, _retval); } 

/* Use this macro to declare functions that forward the behavior of this interface to another object in a safe way. */
#define NS_FORWARD_SAFE_NSIRDFCONTAINERUTILS(_to) \
  NS_SCRIPTABLE NS_IMETHOD IsOrdinalProperty(nsIRDFResource *aProperty, PRBool *_retval NS_OUTPARAM) { return !_to ? NS_ERROR_NULL_POINTER : _to->IsOrdinalProperty(aProperty, _retval); } \
  NS_SCRIPTABLE NS_IMETHOD IndexToOrdinalResource(PRInt32 aIndex, nsIRDFResource **_retval NS_OUTPARAM) { return !_to ? NS_ERROR_NULL_POINTER : _to->IndexToOrdinalResource(aIndex, _retval); } \
  NS_SCRIPTABLE NS_IMETHOD OrdinalResourceToIndex(nsIRDFResource *aOrdinal, PRInt32 *_retval NS_OUTPARAM) { return !_to ? NS_ERROR_NULL_POINTER : _to->OrdinalResourceToIndex(aOrdinal, _retval); } \
  NS_SCRIPTABLE NS_IMETHOD IsContainer(nsIRDFDataSource *aDataSource, nsIRDFResource *aResource, PRBool *_retval NS_OUTPARAM) { return !_to ? NS_ERROR_NULL_POINTER : _to->IsContainer(aDataSource, aResource, _retval); } \
  NS_SCRIPTABLE NS_IMETHOD IsEmpty(nsIRDFDataSource *aDataSource, nsIRDFResource *aResource, PRBool *_retval NS_OUTPARAM) { return !_to ? NS_ERROR_NULL_POINTER : _to->IsEmpty(aDataSource, aResource, _retval); } \
  NS_SCRIPTABLE NS_IMETHOD IsBag(nsIRDFDataSource *aDataSource, nsIRDFResource *aResource, PRBool *_retval NS_OUTPARAM) { return !_to ? NS_ERROR_NULL_POINTER : _to->IsBag(aDataSource, aResource, _retval); } \
  NS_SCRIPTABLE NS_IMETHOD IsSeq(nsIRDFDataSource *aDataSource, nsIRDFResource *aResource, PRBool *_retval NS_OUTPARAM) { return !_to ? NS_ERROR_NULL_POINTER : _to->IsSeq(aDataSource, aResource, _retval); } \
  NS_SCRIPTABLE NS_IMETHOD IsAlt(nsIRDFDataSource *aDataSource, nsIRDFResource *aResource, PRBool *_retval NS_OUTPARAM) { return !_to ? NS_ERROR_NULL_POINTER : _to->IsAlt(aDataSource, aResource, _retval); } \
  NS_SCRIPTABLE NS_IMETHOD MakeBag(nsIRDFDataSource *aDataSource, nsIRDFResource *aResource, nsIRDFContainer **_retval NS_OUTPARAM) { return !_to ? NS_ERROR_NULL_POINTER : _to->MakeBag(aDataSource, aResource, _retval); } \
  NS_SCRIPTABLE NS_IMETHOD MakeSeq(nsIRDFDataSource *aDataSource, nsIRDFResource *aResource, nsIRDFContainer **_retval NS_OUTPARAM) { return !_to ? NS_ERROR_NULL_POINTER : _to->MakeSeq(aDataSource, aResource, _retval); } \
  NS_SCRIPTABLE NS_IMETHOD MakeAlt(nsIRDFDataSource *aDataSource, nsIRDFResource *aResource, nsIRDFContainer **_retval NS_OUTPARAM) { return !_to ? NS_ERROR_NULL_POINTER : _to->MakeAlt(aDataSource, aResource, _retval); } \
  NS_SCRIPTABLE NS_IMETHOD IndexOf(nsIRDFDataSource *aDataSource, nsIRDFResource *aContainer, nsIRDFNode *aElement, PRInt32 *_retval NS_OUTPARAM) { return !_to ? NS_ERROR_NULL_POINTER : _to->IndexOf(aDataSource, aContainer, aElement, _retval); } 

#if 0
/* Use the code below as a template for the implementation class for this interface. */

/* Header file */
class nsRDFContainerUtils : public nsIRDFContainerUtils
{
public:
  NS_DECL_ISUPPORTS
  NS_DECL_NSIRDFCONTAINERUTILS

  nsRDFContainerUtils();

private:
  ~nsRDFContainerUtils();

protected:
  /* additional members */
};

/* Implementation file */
NS_IMPL_ISUPPORTS1(nsRDFContainerUtils, nsIRDFContainerUtils)

nsRDFContainerUtils::nsRDFContainerUtils()
{
  /* member initializers and constructor code */
}

nsRDFContainerUtils::~nsRDFContainerUtils()
{
  /* destructor code */
}

/* boolean IsOrdinalProperty (in nsIRDFResource aProperty); */
NS_IMETHODIMP nsRDFContainerUtils::IsOrdinalProperty(nsIRDFResource *aProperty, PRBool *_retval NS_OUTPARAM)
{
    return NS_ERROR_NOT_IMPLEMENTED;
}

/* nsIRDFResource IndexToOrdinalResource (in long aIndex); */
NS_IMETHODIMP nsRDFContainerUtils::IndexToOrdinalResource(PRInt32 aIndex, nsIRDFResource **_retval NS_OUTPARAM)
{
    return NS_ERROR_NOT_IMPLEMENTED;
}

/* long OrdinalResourceToIndex (in nsIRDFResource aOrdinal); */
NS_IMETHODIMP nsRDFContainerUtils::OrdinalResourceToIndex(nsIRDFResource *aOrdinal, PRInt32 *_retval NS_OUTPARAM)
{
    return NS_ERROR_NOT_IMPLEMENTED;
}

/* boolean IsContainer (in nsIRDFDataSource aDataSource, in nsIRDFResource aResource); */
NS_IMETHODIMP nsRDFContainerUtils::IsContainer(nsIRDFDataSource *aDataSource, nsIRDFResource *aResource, PRBool *_retval NS_OUTPARAM)
{
    return NS_ERROR_NOT_IMPLEMENTED;
}

/* boolean IsEmpty (in nsIRDFDataSource aDataSource, in nsIRDFResource aResource); */
NS_IMETHODIMP nsRDFContainerUtils::IsEmpty(nsIRDFDataSource *aDataSource, nsIRDFResource *aResource, PRBool *_retval NS_OUTPARAM)
{
    return NS_ERROR_NOT_IMPLEMENTED;
}

/* boolean IsBag (in nsIRDFDataSource aDataSource, in nsIRDFResource aResource); */
NS_IMETHODIMP nsRDFContainerUtils::IsBag(nsIRDFDataSource *aDataSource, nsIRDFResource *aResource, PRBool *_retval NS_OUTPARAM)
{
    return NS_ERROR_NOT_IMPLEMENTED;
}

/* boolean IsSeq (in nsIRDFDataSource aDataSource, in nsIRDFResource aResource); */
NS_IMETHODIMP nsRDFContainerUtils::IsSeq(nsIRDFDataSource *aDataSource, nsIRDFResource *aResource, PRBool *_retval NS_OUTPARAM)
{
    return NS_ERROR_NOT_IMPLEMENTED;
}

/* boolean IsAlt (in nsIRDFDataSource aDataSource, in nsIRDFResource aResource); */
NS_IMETHODIMP nsRDFContainerUtils::IsAlt(nsIRDFDataSource *aDataSource, nsIRDFResource *aResource, PRBool *_retval NS_OUTPARAM)
{
    return NS_ERROR_NOT_IMPLEMENTED;
}

/* nsIRDFContainer MakeBag (in nsIRDFDataSource aDataSource, in nsIRDFResource aResource); */
NS_IMETHODIMP nsRDFContainerUtils::MakeBag(nsIRDFDataSource *aDataSource, nsIRDFResource *aResource, nsIRDFContainer **_retval NS_OUTPARAM)
{
    return NS_ERROR_NOT_IMPLEMENTED;
}

/* nsIRDFContainer MakeSeq (in nsIRDFDataSource aDataSource, in nsIRDFResource aResource); */
NS_IMETHODIMP nsRDFContainerUtils::MakeSeq(nsIRDFDataSource *aDataSource, nsIRDFResource *aResource, nsIRDFContainer **_retval NS_OUTPARAM)
{
    return NS_ERROR_NOT_IMPLEMENTED;
}

/* nsIRDFContainer MakeAlt (in nsIRDFDataSource aDataSource, in nsIRDFResource aResource); */
NS_IMETHODIMP nsRDFContainerUtils::MakeAlt(nsIRDFDataSource *aDataSource, nsIRDFResource *aResource, nsIRDFContainer **_retval NS_OUTPARAM)
{
    return NS_ERROR_NOT_IMPLEMENTED;
}

/* long indexOf (in nsIRDFDataSource aDataSource, in nsIRDFResource aContainer, in nsIRDFNode aElement); */
NS_IMETHODIMP nsRDFContainerUtils::IndexOf(nsIRDFDataSource *aDataSource, nsIRDFResource *aContainer, nsIRDFNode *aElement, PRInt32 *_retval NS_OUTPARAM)
{
    return NS_ERROR_NOT_IMPLEMENTED;
}

/* End of implementation class template. */
#endif

extern nsresult
NS_NewRDFContainerUtils(nsIRDFContainerUtils** aResult);

#endif /* __gen_nsIRDFContainerUtils_h__ */
