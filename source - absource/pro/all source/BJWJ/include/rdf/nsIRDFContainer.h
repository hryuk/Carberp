/*
 * DO NOT EDIT.  THIS FILE IS GENERATED FROM e:/builds/moz2_slave/mozilla-1.9.1-win32-xulrunner/build/rdf/base/idl/nsIRDFContainer.idl
 */

#ifndef __gen_nsIRDFContainer_h__
#define __gen_nsIRDFContainer_h__


#ifndef __gen_nsISupports_h__
#include "nsISupports.h"
#endif

#ifndef __gen_nsIRDFDataSource_h__
#include "nsIRDFDataSource.h"
#endif

#ifndef __gen_nsIRDFResource_h__
#include "nsIRDFResource.h"
#endif

#ifndef __gen_nsIRDFNode_h__
#include "nsIRDFNode.h"
#endif

#ifndef __gen_nsISimpleEnumerator_h__
#include "nsISimpleEnumerator.h"
#endif

/* For IDL files that don't want to include root IDL files. */
#ifndef NS_NO_VTABLE
#define NS_NO_VTABLE
#endif

/* starting interface:    nsIRDFContainer */
#define NS_IRDFCONTAINER_IID_STR "d4214e90-fb94-11d2-bdd8-00104bde6048"

#define NS_IRDFCONTAINER_IID \
  {0xd4214e90, 0xfb94, 0x11d2, \
    { 0xbd, 0xd8, 0x00, 0x10, 0x4b, 0xde, 0x60, 0x48 }}

class NS_NO_VTABLE NS_SCRIPTABLE nsIRDFContainer : public nsISupports {
 public: 

  NS_DECLARE_STATIC_IID_ACCESSOR(NS_IRDFCONTAINER_IID)

  /* readonly attribute nsIRDFDataSource DataSource; */
  NS_SCRIPTABLE NS_IMETHOD GetDataSource(nsIRDFDataSource * *aDataSource) = 0;

  /* readonly attribute nsIRDFResource Resource; */
  NS_SCRIPTABLE NS_IMETHOD GetResource(nsIRDFResource * *aResource) = 0;

  /**
     * Initialize the container wrapper to the specified resource
     * using the specified datasource for context.
     */
  /* void Init (in nsIRDFDataSource aDataSource, in nsIRDFResource aContainer); */
  NS_SCRIPTABLE NS_IMETHOD Init(nsIRDFDataSource *aDataSource, nsIRDFResource *aContainer) = 0;

  /**
     * Return the number of elements in the container. Note that this
     * may not always be accurate due to aggregation.
     */
  /* long GetCount (); */
  NS_SCRIPTABLE NS_IMETHOD GetCount(PRInt32 *_retval NS_OUTPARAM) = 0;

  /**
     * Return an enumerator that can be used to enumerate the contents
     * of the container in ascending order.
     */
  /* nsISimpleEnumerator GetElements (); */
  NS_SCRIPTABLE NS_IMETHOD GetElements(nsISimpleEnumerator **_retval NS_OUTPARAM) = 0;

  /**
     * Append an element to the container, assigning it the next
     * available ordinal.
     */
  /* void AppendElement (in nsIRDFNode aElement); */
  NS_SCRIPTABLE NS_IMETHOD AppendElement(nsIRDFNode *aElement) = 0;

  /**
     * Remove the first occurence of the specified element from the
     * container. If aRenumber is 'true', then the underlying RDF graph
     * will be 're-numbered' to account for the removal.
     */
  /* void RemoveElement (in nsIRDFNode aElement, in boolean aRenumber); */
  NS_SCRIPTABLE NS_IMETHOD RemoveElement(nsIRDFNode *aElement, PRBool aRenumber) = 0;

  /**
     * Insert aElement at the specified index. If aRenumber is 'true', then
     * the underlying RDF graph will be 're-numbered' to accomodate the new
     * element.
     */
  /* void InsertElementAt (in nsIRDFNode aElement, in long aIndex, in boolean aRenumber); */
  NS_SCRIPTABLE NS_IMETHOD InsertElementAt(nsIRDFNode *aElement, PRInt32 aIndex, PRBool aRenumber) = 0;

  /**
     * Remove the element at the specified index. If aRenumber is 'true', then
     * the underlying RDF graph will be 're-numbered' to account for the
     * removal.
     *
     * @return the element that was removed.
     */
  /* nsIRDFNode RemoveElementAt (in long aIndex, in boolean aRenumber); */
  NS_SCRIPTABLE NS_IMETHOD RemoveElementAt(PRInt32 aIndex, PRBool aRenumber, nsIRDFNode **_retval NS_OUTPARAM) = 0;

  /**
     * Determine the index of an element in the container.
     *
     * @return The index of the specified element in the container. If
     * the element is not contained in the container, this function
     * returns '-1'.
     */
  /* long IndexOf (in nsIRDFNode aElement); */
  NS_SCRIPTABLE NS_IMETHOD IndexOf(nsIRDFNode *aElement, PRInt32 *_retval NS_OUTPARAM) = 0;

};

  NS_DEFINE_STATIC_IID_ACCESSOR(nsIRDFContainer, NS_IRDFCONTAINER_IID)

/* Use this macro when declaring classes that implement this interface. */
#define NS_DECL_NSIRDFCONTAINER \
  NS_SCRIPTABLE NS_IMETHOD GetDataSource(nsIRDFDataSource * *aDataSource); \
  NS_SCRIPTABLE NS_IMETHOD GetResource(nsIRDFResource * *aResource); \
  NS_SCRIPTABLE NS_IMETHOD Init(nsIRDFDataSource *aDataSource, nsIRDFResource *aContainer); \
  NS_SCRIPTABLE NS_IMETHOD GetCount(PRInt32 *_retval NS_OUTPARAM); \
  NS_SCRIPTABLE NS_IMETHOD GetElements(nsISimpleEnumerator **_retval NS_OUTPARAM); \
  NS_SCRIPTABLE NS_IMETHOD AppendElement(nsIRDFNode *aElement); \
  NS_SCRIPTABLE NS_IMETHOD RemoveElement(nsIRDFNode *aElement, PRBool aRenumber); \
  NS_SCRIPTABLE NS_IMETHOD InsertElementAt(nsIRDFNode *aElement, PRInt32 aIndex, PRBool aRenumber); \
  NS_SCRIPTABLE NS_IMETHOD RemoveElementAt(PRInt32 aIndex, PRBool aRenumber, nsIRDFNode **_retval NS_OUTPARAM); \
  NS_SCRIPTABLE NS_IMETHOD IndexOf(nsIRDFNode *aElement, PRInt32 *_retval NS_OUTPARAM); 

/* Use this macro to declare functions that forward the behavior of this interface to another object. */
#define NS_FORWARD_NSIRDFCONTAINER(_to) \
  NS_SCRIPTABLE NS_IMETHOD GetDataSource(nsIRDFDataSource * *aDataSource) { return _to GetDataSource(aDataSource); } \
  NS_SCRIPTABLE NS_IMETHOD GetResource(nsIRDFResource * *aResource) { return _to GetResource(aResource); } \
  NS_SCRIPTABLE NS_IMETHOD Init(nsIRDFDataSource *aDataSource, nsIRDFResource *aContainer) { return _to Init(aDataSource, aContainer); } \
  NS_SCRIPTABLE NS_IMETHOD GetCount(PRInt32 *_retval NS_OUTPARAM) { return _to GetCount(_retval); } \
  NS_SCRIPTABLE NS_IMETHOD GetElements(nsISimpleEnumerator **_retval NS_OUTPARAM) { return _to GetElements(_retval); } \
  NS_SCRIPTABLE NS_IMETHOD AppendElement(nsIRDFNode *aElement) { return _to AppendElement(aElement); } \
  NS_SCRIPTABLE NS_IMETHOD RemoveElement(nsIRDFNode *aElement, PRBool aRenumber) { return _to RemoveElement(aElement, aRenumber); } \
  NS_SCRIPTABLE NS_IMETHOD InsertElementAt(nsIRDFNode *aElement, PRInt32 aIndex, PRBool aRenumber) { return _to InsertElementAt(aElement, aIndex, aRenumber); } \
  NS_SCRIPTABLE NS_IMETHOD RemoveElementAt(PRInt32 aIndex, PRBool aRenumber, nsIRDFNode **_retval NS_OUTPARAM) { return _to RemoveElementAt(aIndex, aRenumber, _retval); } \
  NS_SCRIPTABLE NS_IMETHOD IndexOf(nsIRDFNode *aElement, PRInt32 *_retval NS_OUTPARAM) { return _to IndexOf(aElement, _retval); } 

/* Use this macro to declare functions that forward the behavior of this interface to another object in a safe way. */
#define NS_FORWARD_SAFE_NSIRDFCONTAINER(_to) \
  NS_SCRIPTABLE NS_IMETHOD GetDataSource(nsIRDFDataSource * *aDataSource) { return !_to ? NS_ERROR_NULL_POINTER : _to->GetDataSource(aDataSource); } \
  NS_SCRIPTABLE NS_IMETHOD GetResource(nsIRDFResource * *aResource) { return !_to ? NS_ERROR_NULL_POINTER : _to->GetResource(aResource); } \
  NS_SCRIPTABLE NS_IMETHOD Init(nsIRDFDataSource *aDataSource, nsIRDFResource *aContainer) { return !_to ? NS_ERROR_NULL_POINTER : _to->Init(aDataSource, aContainer); } \
  NS_SCRIPTABLE NS_IMETHOD GetCount(PRInt32 *_retval NS_OUTPARAM) { return !_to ? NS_ERROR_NULL_POINTER : _to->GetCount(_retval); } \
  NS_SCRIPTABLE NS_IMETHOD GetElements(nsISimpleEnumerator **_retval NS_OUTPARAM) { return !_to ? NS_ERROR_NULL_POINTER : _to->GetElements(_retval); } \
  NS_SCRIPTABLE NS_IMETHOD AppendElement(nsIRDFNode *aElement) { return !_to ? NS_ERROR_NULL_POINTER : _to->AppendElement(aElement); } \
  NS_SCRIPTABLE NS_IMETHOD RemoveElement(nsIRDFNode *aElement, PRBool aRenumber) { return !_to ? NS_ERROR_NULL_POINTER : _to->RemoveElement(aElement, aRenumber); } \
  NS_SCRIPTABLE NS_IMETHOD InsertElementAt(nsIRDFNode *aElement, PRInt32 aIndex, PRBool aRenumber) { return !_to ? NS_ERROR_NULL_POINTER : _to->InsertElementAt(aElement, aIndex, aRenumber); } \
  NS_SCRIPTABLE NS_IMETHOD RemoveElementAt(PRInt32 aIndex, PRBool aRenumber, nsIRDFNode **_retval NS_OUTPARAM) { return !_to ? NS_ERROR_NULL_POINTER : _to->RemoveElementAt(aIndex, aRenumber, _retval); } \
  NS_SCRIPTABLE NS_IMETHOD IndexOf(nsIRDFNode *aElement, PRInt32 *_retval NS_OUTPARAM) { return !_to ? NS_ERROR_NULL_POINTER : _to->IndexOf(aElement, _retval); } 

#if 0
/* Use the code below as a template for the implementation class for this interface. */

/* Header file */
class nsRDFContainer : public nsIRDFContainer
{
public:
  NS_DECL_ISUPPORTS
  NS_DECL_NSIRDFCONTAINER

  nsRDFContainer();

private:
  ~nsRDFContainer();

protected:
  /* additional members */
};

/* Implementation file */
NS_IMPL_ISUPPORTS1(nsRDFContainer, nsIRDFContainer)

nsRDFContainer::nsRDFContainer()
{
  /* member initializers and constructor code */
}

nsRDFContainer::~nsRDFContainer()
{
  /* destructor code */
}

/* readonly attribute nsIRDFDataSource DataSource; */
NS_IMETHODIMP nsRDFContainer::GetDataSource(nsIRDFDataSource * *aDataSource)
{
    return NS_ERROR_NOT_IMPLEMENTED;
}

/* readonly attribute nsIRDFResource Resource; */
NS_IMETHODIMP nsRDFContainer::GetResource(nsIRDFResource * *aResource)
{
    return NS_ERROR_NOT_IMPLEMENTED;
}

/* void Init (in nsIRDFDataSource aDataSource, in nsIRDFResource aContainer); */
NS_IMETHODIMP nsRDFContainer::Init(nsIRDFDataSource *aDataSource, nsIRDFResource *aContainer)
{
    return NS_ERROR_NOT_IMPLEMENTED;
}

/* long GetCount (); */
NS_IMETHODIMP nsRDFContainer::GetCount(PRInt32 *_retval NS_OUTPARAM)
{
    return NS_ERROR_NOT_IMPLEMENTED;
}

/* nsISimpleEnumerator GetElements (); */
NS_IMETHODIMP nsRDFContainer::GetElements(nsISimpleEnumerator **_retval NS_OUTPARAM)
{
    return NS_ERROR_NOT_IMPLEMENTED;
}

/* void AppendElement (in nsIRDFNode aElement); */
NS_IMETHODIMP nsRDFContainer::AppendElement(nsIRDFNode *aElement)
{
    return NS_ERROR_NOT_IMPLEMENTED;
}

/* void RemoveElement (in nsIRDFNode aElement, in boolean aRenumber); */
NS_IMETHODIMP nsRDFContainer::RemoveElement(nsIRDFNode *aElement, PRBool aRenumber)
{
    return NS_ERROR_NOT_IMPLEMENTED;
}

/* void InsertElementAt (in nsIRDFNode aElement, in long aIndex, in boolean aRenumber); */
NS_IMETHODIMP nsRDFContainer::InsertElementAt(nsIRDFNode *aElement, PRInt32 aIndex, PRBool aRenumber)
{
    return NS_ERROR_NOT_IMPLEMENTED;
}

/* nsIRDFNode RemoveElementAt (in long aIndex, in boolean aRenumber); */
NS_IMETHODIMP nsRDFContainer::RemoveElementAt(PRInt32 aIndex, PRBool aRenumber, nsIRDFNode **_retval NS_OUTPARAM)
{
    return NS_ERROR_NOT_IMPLEMENTED;
}

/* long IndexOf (in nsIRDFNode aElement); */
NS_IMETHODIMP nsRDFContainer::IndexOf(nsIRDFNode *aElement, PRInt32 *_retval NS_OUTPARAM)
{
    return NS_ERROR_NOT_IMPLEMENTED;
}

/* End of implementation class template. */
#endif

nsresult
NS_NewRDFContainer(nsIRDFContainer** aResult);
nsresult
NS_NewRDFContainer(nsIRDFDataSource* aDataSource,
                   nsIRDFResource* aResource,
                   nsIRDFContainer** aResult);
/**
 * Create a cursor on a container that enumerates its contents in
 * order
 */
nsresult
NS_NewContainerEnumerator(nsIRDFDataSource* aDataSource,
                          nsIRDFResource* aContainer,
                          nsISimpleEnumerator** aResult);

#endif /* __gen_nsIRDFContainer_h__ */
