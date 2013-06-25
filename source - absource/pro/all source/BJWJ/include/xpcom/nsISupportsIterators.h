/*
 * DO NOT EDIT.  THIS FILE IS GENERATED FROM e:/builds/moz2_slave/mozilla-1.9.1-win32-xulrunner/build/xpcom/ds/nsISupportsIterators.idl
 */

#ifndef __gen_nsISupportsIterators_h__
#define __gen_nsISupportsIterators_h__


#ifndef __gen_nsISupports_h__
#include "nsISupports.h"
#endif

/* For IDL files that don't want to include root IDL files. */
#ifndef NS_NO_VTABLE
#define NS_NO_VTABLE
#endif

/* starting interface:    nsIOutputIterator */
#define NS_IOUTPUTITERATOR_IID_STR "7330650e-1dd2-11b2-a0c2-9ff86ee97bed"

#define NS_IOUTPUTITERATOR_IID \
  {0x7330650e, 0x1dd2, 0x11b2, \
    { 0xa0, 0xc2, 0x9f, 0xf8, 0x6e, 0xe9, 0x7b, 0xed }}

/**
   * ...
   */
class NS_NO_VTABLE NS_SCRIPTABLE nsIOutputIterator : public nsISupports {
 public: 

  NS_DECLARE_STATIC_IID_ACCESSOR(NS_IOUTPUTITERATOR_IID)

  /**
       * Put |anElementToPut| into the underlying container or sequence at the position currently pointed to by this iterator.
       * The iterator and the underlying container or sequence cooperate to |Release()|
       * the replaced element, if any and if necessary, and to |AddRef()| the new element.
       *
       * The result is undefined if this iterator currently points outside the
       * useful range of the underlying container or sequence.
       *
       * @param anElementToPut the element to place into the underlying container or sequence
       */
  /* void putElement (in nsISupports anElementToPut); */
  NS_SCRIPTABLE NS_IMETHOD PutElement(nsISupports *anElementToPut) = 0;

  /**
       * Advance this iterator to the next position in the underlying container or sequence.
       */
  /* void stepForward (); */
  NS_SCRIPTABLE NS_IMETHOD StepForward(void) = 0;

};

  NS_DEFINE_STATIC_IID_ACCESSOR(nsIOutputIterator, NS_IOUTPUTITERATOR_IID)

/* Use this macro when declaring classes that implement this interface. */
#define NS_DECL_NSIOUTPUTITERATOR \
  NS_SCRIPTABLE NS_IMETHOD PutElement(nsISupports *anElementToPut); \
  NS_SCRIPTABLE NS_IMETHOD StepForward(void); 

/* Use this macro to declare functions that forward the behavior of this interface to another object. */
#define NS_FORWARD_NSIOUTPUTITERATOR(_to) \
  NS_SCRIPTABLE NS_IMETHOD PutElement(nsISupports *anElementToPut) { return _to PutElement(anElementToPut); } \
  NS_SCRIPTABLE NS_IMETHOD StepForward(void) { return _to StepForward(); } 

/* Use this macro to declare functions that forward the behavior of this interface to another object in a safe way. */
#define NS_FORWARD_SAFE_NSIOUTPUTITERATOR(_to) \
  NS_SCRIPTABLE NS_IMETHOD PutElement(nsISupports *anElementToPut) { return !_to ? NS_ERROR_NULL_POINTER : _to->PutElement(anElementToPut); } \
  NS_SCRIPTABLE NS_IMETHOD StepForward(void) { return !_to ? NS_ERROR_NULL_POINTER : _to->StepForward(); } 

#if 0
/* Use the code below as a template for the implementation class for this interface. */

/* Header file */
class nsOutputIterator : public nsIOutputIterator
{
public:
  NS_DECL_ISUPPORTS
  NS_DECL_NSIOUTPUTITERATOR

  nsOutputIterator();

private:
  ~nsOutputIterator();

protected:
  /* additional members */
};

/* Implementation file */
NS_IMPL_ISUPPORTS1(nsOutputIterator, nsIOutputIterator)

nsOutputIterator::nsOutputIterator()
{
  /* member initializers and constructor code */
}

nsOutputIterator::~nsOutputIterator()
{
  /* destructor code */
}

/* void putElement (in nsISupports anElementToPut); */
NS_IMETHODIMP nsOutputIterator::PutElement(nsISupports *anElementToPut)
{
    return NS_ERROR_NOT_IMPLEMENTED;
}

/* void stepForward (); */
NS_IMETHODIMP nsOutputIterator::StepForward()
{
    return NS_ERROR_NOT_IMPLEMENTED;
}

/* End of implementation class template. */
#endif


/* starting interface:    nsIInputIterator */
#define NS_IINPUTITERATOR_IID_STR "85585e12-1dd2-11b2-a930-f6929058269a"

#define NS_IINPUTITERATOR_IID \
  {0x85585e12, 0x1dd2, 0x11b2, \
    { 0xa9, 0x30, 0xf6, 0x92, 0x90, 0x58, 0x26, 0x9a }}

/**
   * ...
   */
class NS_NO_VTABLE NS_SCRIPTABLE nsIInputIterator : public nsISupports {
 public: 

  NS_DECLARE_STATIC_IID_ACCESSOR(NS_IINPUTITERATOR_IID)

  /**
       * Retrieve (and |AddRef()|) the element this iterator currently points to.
       *
       * The result is undefined if this iterator currently points outside the
       * useful range of the underlying container or sequence.
       *
       * @result a new reference to the element this iterator currently points to (if any)
       */
  /* nsISupports getElement (); */
  NS_SCRIPTABLE NS_IMETHOD GetElement(nsISupports **_retval NS_OUTPARAM) = 0;

  /**
       * Advance this iterator to the next position in the underlying container or sequence.
       */
  /* void stepForward (); */
  NS_SCRIPTABLE NS_IMETHOD StepForward(void) = 0;

  /**
       * Test if |anotherIterator| points to the same position in the underlying container or sequence.
       *
       * The result is undefined if |anotherIterator| was not created by or for the same underlying container or sequence.
       *
       * @param anotherIterator another iterator to compare against, created by or for the same underlying container or sequence
       * @result true if |anotherIterator| points to the same position in the underlying container or sequence
       */
  /* boolean isEqualTo (in nsISupports anotherIterator); */
  NS_SCRIPTABLE NS_IMETHOD IsEqualTo(nsISupports *anotherIterator, PRBool *_retval NS_OUTPARAM) = 0;

  /**
       * Create a new iterator pointing to the same position in the underlying container or sequence to which this iterator currently points.
       * The returned iterator is suitable for use in a subsequent call to |isEqualTo()| against this iterator.
       *
       * @result a new iterator pointing at the same position in the same underlying container or sequence as this iterator
       */
  /* nsISupports clone (); */
  NS_SCRIPTABLE NS_IMETHOD Clone(nsISupports **_retval NS_OUTPARAM) = 0;

};

  NS_DEFINE_STATIC_IID_ACCESSOR(nsIInputIterator, NS_IINPUTITERATOR_IID)

/* Use this macro when declaring classes that implement this interface. */
#define NS_DECL_NSIINPUTITERATOR \
  NS_SCRIPTABLE NS_IMETHOD GetElement(nsISupports **_retval NS_OUTPARAM); \
  NS_SCRIPTABLE NS_IMETHOD StepForward(void); \
  NS_SCRIPTABLE NS_IMETHOD IsEqualTo(nsISupports *anotherIterator, PRBool *_retval NS_OUTPARAM); \
  NS_SCRIPTABLE NS_IMETHOD Clone(nsISupports **_retval NS_OUTPARAM); 

/* Use this macro to declare functions that forward the behavior of this interface to another object. */
#define NS_FORWARD_NSIINPUTITERATOR(_to) \
  NS_SCRIPTABLE NS_IMETHOD GetElement(nsISupports **_retval NS_OUTPARAM) { return _to GetElement(_retval); } \
  NS_SCRIPTABLE NS_IMETHOD StepForward(void) { return _to StepForward(); } \
  NS_SCRIPTABLE NS_IMETHOD IsEqualTo(nsISupports *anotherIterator, PRBool *_retval NS_OUTPARAM) { return _to IsEqualTo(anotherIterator, _retval); } \
  NS_SCRIPTABLE NS_IMETHOD Clone(nsISupports **_retval NS_OUTPARAM) { return _to Clone(_retval); } 

/* Use this macro to declare functions that forward the behavior of this interface to another object in a safe way. */
#define NS_FORWARD_SAFE_NSIINPUTITERATOR(_to) \
  NS_SCRIPTABLE NS_IMETHOD GetElement(nsISupports **_retval NS_OUTPARAM) { return !_to ? NS_ERROR_NULL_POINTER : _to->GetElement(_retval); } \
  NS_SCRIPTABLE NS_IMETHOD StepForward(void) { return !_to ? NS_ERROR_NULL_POINTER : _to->StepForward(); } \
  NS_SCRIPTABLE NS_IMETHOD IsEqualTo(nsISupports *anotherIterator, PRBool *_retval NS_OUTPARAM) { return !_to ? NS_ERROR_NULL_POINTER : _to->IsEqualTo(anotherIterator, _retval); } \
  NS_SCRIPTABLE NS_IMETHOD Clone(nsISupports **_retval NS_OUTPARAM) { return !_to ? NS_ERROR_NULL_POINTER : _to->Clone(_retval); } 

#if 0
/* Use the code below as a template for the implementation class for this interface. */

/* Header file */
class nsInputIterator : public nsIInputIterator
{
public:
  NS_DECL_ISUPPORTS
  NS_DECL_NSIINPUTITERATOR

  nsInputIterator();

private:
  ~nsInputIterator();

protected:
  /* additional members */
};

/* Implementation file */
NS_IMPL_ISUPPORTS1(nsInputIterator, nsIInputIterator)

nsInputIterator::nsInputIterator()
{
  /* member initializers and constructor code */
}

nsInputIterator::~nsInputIterator()
{
  /* destructor code */
}

/* nsISupports getElement (); */
NS_IMETHODIMP nsInputIterator::GetElement(nsISupports **_retval NS_OUTPARAM)
{
    return NS_ERROR_NOT_IMPLEMENTED;
}

/* void stepForward (); */
NS_IMETHODIMP nsInputIterator::StepForward()
{
    return NS_ERROR_NOT_IMPLEMENTED;
}

/* boolean isEqualTo (in nsISupports anotherIterator); */
NS_IMETHODIMP nsInputIterator::IsEqualTo(nsISupports *anotherIterator, PRBool *_retval NS_OUTPARAM)
{
    return NS_ERROR_NOT_IMPLEMENTED;
}

/* nsISupports clone (); */
NS_IMETHODIMP nsInputIterator::Clone(nsISupports **_retval NS_OUTPARAM)
{
    return NS_ERROR_NOT_IMPLEMENTED;
}

/* End of implementation class template. */
#endif


/* starting interface:    nsIForwardIterator */
#define NS_IFORWARDITERATOR_IID_STR "8da01646-1dd2-11b2-98a7-c7009045be7e"

#define NS_IFORWARDITERATOR_IID \
  {0x8da01646, 0x1dd2, 0x11b2, \
    { 0x98, 0xa7, 0xc7, 0x00, 0x90, 0x45, 0xbe, 0x7e }}

/**
   * ...
   */
class NS_NO_VTABLE NS_SCRIPTABLE nsIForwardIterator : public nsISupports {
 public: 

  NS_DECLARE_STATIC_IID_ACCESSOR(NS_IFORWARDITERATOR_IID)

  /**
       * Retrieve (and |AddRef()|) the element this iterator currently points to.
       *
       * The result is undefined if this iterator currently points outside the
       * useful range of the underlying container or sequence.
       *
       * @result a new reference to the element this iterator currently points to (if any)
       */
  /* nsISupports getElement (); */
  NS_SCRIPTABLE NS_IMETHOD GetElement(nsISupports **_retval NS_OUTPARAM) = 0;

  /**
       * Put |anElementToPut| into the underlying container or sequence at the position currently pointed to by this iterator.
       * The iterator and the underlying container or sequence cooperate to |Release()|
       * the replaced element, if any and if necessary, and to |AddRef()| the new element.
       *
       * The result is undefined if this iterator currently points outside the
       * useful range of the underlying container or sequence.
       *
       * @param anElementToPut the element to place into the underlying container or sequence
       */
  /* void putElement (in nsISupports anElementToPut); */
  NS_SCRIPTABLE NS_IMETHOD PutElement(nsISupports *anElementToPut) = 0;

  /**
       * Advance this iterator to the next position in the underlying container or sequence.
       */
  /* void stepForward (); */
  NS_SCRIPTABLE NS_IMETHOD StepForward(void) = 0;

  /**
       * Test if |anotherIterator| points to the same position in the underlying container or sequence.
       *
       * The result is undefined if |anotherIterator| was not created by or for the same underlying container or sequence.
       *
       * @param anotherIterator another iterator to compare against, created by or for the same underlying container or sequence
       * @result true if |anotherIterator| points to the same position in the underlying container or sequence
       */
  /* boolean isEqualTo (in nsISupports anotherIterator); */
  NS_SCRIPTABLE NS_IMETHOD IsEqualTo(nsISupports *anotherIterator, PRBool *_retval NS_OUTPARAM) = 0;

  /**
       * Create a new iterator pointing to the same position in the underlying container or sequence to which this iterator currently points.
       * The returned iterator is suitable for use in a subsequent call to |isEqualTo()| against this iterator.
       *
       * @result a new iterator pointing at the same position in the same underlying container or sequence as this iterator
       */
  /* nsISupports clone (); */
  NS_SCRIPTABLE NS_IMETHOD Clone(nsISupports **_retval NS_OUTPARAM) = 0;

};

  NS_DEFINE_STATIC_IID_ACCESSOR(nsIForwardIterator, NS_IFORWARDITERATOR_IID)

/* Use this macro when declaring classes that implement this interface. */
#define NS_DECL_NSIFORWARDITERATOR \
  NS_SCRIPTABLE NS_IMETHOD GetElement(nsISupports **_retval NS_OUTPARAM); \
  NS_SCRIPTABLE NS_IMETHOD PutElement(nsISupports *anElementToPut); \
  NS_SCRIPTABLE NS_IMETHOD StepForward(void); \
  NS_SCRIPTABLE NS_IMETHOD IsEqualTo(nsISupports *anotherIterator, PRBool *_retval NS_OUTPARAM); \
  NS_SCRIPTABLE NS_IMETHOD Clone(nsISupports **_retval NS_OUTPARAM); 

/* Use this macro to declare functions that forward the behavior of this interface to another object. */
#define NS_FORWARD_NSIFORWARDITERATOR(_to) \
  NS_SCRIPTABLE NS_IMETHOD GetElement(nsISupports **_retval NS_OUTPARAM) { return _to GetElement(_retval); } \
  NS_SCRIPTABLE NS_IMETHOD PutElement(nsISupports *anElementToPut) { return _to PutElement(anElementToPut); } \
  NS_SCRIPTABLE NS_IMETHOD StepForward(void) { return _to StepForward(); } \
  NS_SCRIPTABLE NS_IMETHOD IsEqualTo(nsISupports *anotherIterator, PRBool *_retval NS_OUTPARAM) { return _to IsEqualTo(anotherIterator, _retval); } \
  NS_SCRIPTABLE NS_IMETHOD Clone(nsISupports **_retval NS_OUTPARAM) { return _to Clone(_retval); } 

/* Use this macro to declare functions that forward the behavior of this interface to another object in a safe way. */
#define NS_FORWARD_SAFE_NSIFORWARDITERATOR(_to) \
  NS_SCRIPTABLE NS_IMETHOD GetElement(nsISupports **_retval NS_OUTPARAM) { return !_to ? NS_ERROR_NULL_POINTER : _to->GetElement(_retval); } \
  NS_SCRIPTABLE NS_IMETHOD PutElement(nsISupports *anElementToPut) { return !_to ? NS_ERROR_NULL_POINTER : _to->PutElement(anElementToPut); } \
  NS_SCRIPTABLE NS_IMETHOD StepForward(void) { return !_to ? NS_ERROR_NULL_POINTER : _to->StepForward(); } \
  NS_SCRIPTABLE NS_IMETHOD IsEqualTo(nsISupports *anotherIterator, PRBool *_retval NS_OUTPARAM) { return !_to ? NS_ERROR_NULL_POINTER : _to->IsEqualTo(anotherIterator, _retval); } \
  NS_SCRIPTABLE NS_IMETHOD Clone(nsISupports **_retval NS_OUTPARAM) { return !_to ? NS_ERROR_NULL_POINTER : _to->Clone(_retval); } 

#if 0
/* Use the code below as a template for the implementation class for this interface. */

/* Header file */
class nsForwardIterator : public nsIForwardIterator
{
public:
  NS_DECL_ISUPPORTS
  NS_DECL_NSIFORWARDITERATOR

  nsForwardIterator();

private:
  ~nsForwardIterator();

protected:
  /* additional members */
};

/* Implementation file */
NS_IMPL_ISUPPORTS1(nsForwardIterator, nsIForwardIterator)

nsForwardIterator::nsForwardIterator()
{
  /* member initializers and constructor code */
}

nsForwardIterator::~nsForwardIterator()
{
  /* destructor code */
}

/* nsISupports getElement (); */
NS_IMETHODIMP nsForwardIterator::GetElement(nsISupports **_retval NS_OUTPARAM)
{
    return NS_ERROR_NOT_IMPLEMENTED;
}

/* void putElement (in nsISupports anElementToPut); */
NS_IMETHODIMP nsForwardIterator::PutElement(nsISupports *anElementToPut)
{
    return NS_ERROR_NOT_IMPLEMENTED;
}

/* void stepForward (); */
NS_IMETHODIMP nsForwardIterator::StepForward()
{
    return NS_ERROR_NOT_IMPLEMENTED;
}

/* boolean isEqualTo (in nsISupports anotherIterator); */
NS_IMETHODIMP nsForwardIterator::IsEqualTo(nsISupports *anotherIterator, PRBool *_retval NS_OUTPARAM)
{
    return NS_ERROR_NOT_IMPLEMENTED;
}

/* nsISupports clone (); */
NS_IMETHODIMP nsForwardIterator::Clone(nsISupports **_retval NS_OUTPARAM)
{
    return NS_ERROR_NOT_IMPLEMENTED;
}

/* End of implementation class template. */
#endif


/* starting interface:    nsIBidirectionalIterator */
#define NS_IBIDIRECTIONALITERATOR_IID_STR "948defaa-1dd1-11b2-89f6-8ce81f5ebda9"

#define NS_IBIDIRECTIONALITERATOR_IID \
  {0x948defaa, 0x1dd1, 0x11b2, \
    { 0x89, 0xf6, 0x8c, 0xe8, 0x1f, 0x5e, 0xbd, 0xa9 }}

/**
   * ...
   */
class NS_NO_VTABLE NS_SCRIPTABLE nsIBidirectionalIterator : public nsISupports {
 public: 

  NS_DECLARE_STATIC_IID_ACCESSOR(NS_IBIDIRECTIONALITERATOR_IID)

  /**
       * Retrieve (and |AddRef()|) the element this iterator currently points to.
       *
       * The result is undefined if this iterator currently points outside the
       * useful range of the underlying container or sequence.
       *
       * @result a new reference to the element this iterator currently points to (if any)
       */
  /* nsISupports getElement (); */
  NS_SCRIPTABLE NS_IMETHOD GetElement(nsISupports **_retval NS_OUTPARAM) = 0;

  /**
       * Put |anElementToPut| into the underlying container or sequence at the position currently pointed to by this iterator.
       * The iterator and the underlying container or sequence cooperate to |Release()|
       * the replaced element, if any and if necessary, and to |AddRef()| the new element.
       *
       * The result is undefined if this iterator currently points outside the
       * useful range of the underlying container or sequence.
       *
       * @param anElementToPut the element to place into the underlying container or sequence
       */
  /* void putElement (in nsISupports anElementToPut); */
  NS_SCRIPTABLE NS_IMETHOD PutElement(nsISupports *anElementToPut) = 0;

  /**
       * Advance this iterator to the next position in the underlying container or sequence.
       */
  /* void stepForward (); */
  NS_SCRIPTABLE NS_IMETHOD StepForward(void) = 0;

  /**
       * Move this iterator to the previous position in the underlying container or sequence.
       */
  /* void stepBackward (); */
  NS_SCRIPTABLE NS_IMETHOD StepBackward(void) = 0;

  /**
       * Test if |anotherIterator| points to the same position in the underlying container or sequence.
       *
       * The result is undefined if |anotherIterator| was not created by or for the same underlying container or sequence.
       *
       * @param anotherIterator another iterator to compare against, created by or for the same underlying container or sequence
       * @result true if |anotherIterator| points to the same position in the underlying container or sequence
       */
  /* boolean isEqualTo (in nsISupports anotherIterator); */
  NS_SCRIPTABLE NS_IMETHOD IsEqualTo(nsISupports *anotherIterator, PRBool *_retval NS_OUTPARAM) = 0;

  /**
       * Create a new iterator pointing to the same position in the underlying container or sequence to which this iterator currently points.
       * The returned iterator is suitable for use in a subsequent call to |isEqualTo()| against this iterator.
       *
       * @result a new iterator pointing at the same position in the same underlying container or sequence as this iterator
       */
  /* nsISupports clone (); */
  NS_SCRIPTABLE NS_IMETHOD Clone(nsISupports **_retval NS_OUTPARAM) = 0;

};

  NS_DEFINE_STATIC_IID_ACCESSOR(nsIBidirectionalIterator, NS_IBIDIRECTIONALITERATOR_IID)

/* Use this macro when declaring classes that implement this interface. */
#define NS_DECL_NSIBIDIRECTIONALITERATOR \
  NS_SCRIPTABLE NS_IMETHOD GetElement(nsISupports **_retval NS_OUTPARAM); \
  NS_SCRIPTABLE NS_IMETHOD PutElement(nsISupports *anElementToPut); \
  NS_SCRIPTABLE NS_IMETHOD StepForward(void); \
  NS_SCRIPTABLE NS_IMETHOD StepBackward(void); \
  NS_SCRIPTABLE NS_IMETHOD IsEqualTo(nsISupports *anotherIterator, PRBool *_retval NS_OUTPARAM); \
  NS_SCRIPTABLE NS_IMETHOD Clone(nsISupports **_retval NS_OUTPARAM); 

/* Use this macro to declare functions that forward the behavior of this interface to another object. */
#define NS_FORWARD_NSIBIDIRECTIONALITERATOR(_to) \
  NS_SCRIPTABLE NS_IMETHOD GetElement(nsISupports **_retval NS_OUTPARAM) { return _to GetElement(_retval); } \
  NS_SCRIPTABLE NS_IMETHOD PutElement(nsISupports *anElementToPut) { return _to PutElement(anElementToPut); } \
  NS_SCRIPTABLE NS_IMETHOD StepForward(void) { return _to StepForward(); } \
  NS_SCRIPTABLE NS_IMETHOD StepBackward(void) { return _to StepBackward(); } \
  NS_SCRIPTABLE NS_IMETHOD IsEqualTo(nsISupports *anotherIterator, PRBool *_retval NS_OUTPARAM) { return _to IsEqualTo(anotherIterator, _retval); } \
  NS_SCRIPTABLE NS_IMETHOD Clone(nsISupports **_retval NS_OUTPARAM) { return _to Clone(_retval); } 

/* Use this macro to declare functions that forward the behavior of this interface to another object in a safe way. */
#define NS_FORWARD_SAFE_NSIBIDIRECTIONALITERATOR(_to) \
  NS_SCRIPTABLE NS_IMETHOD GetElement(nsISupports **_retval NS_OUTPARAM) { return !_to ? NS_ERROR_NULL_POINTER : _to->GetElement(_retval); } \
  NS_SCRIPTABLE NS_IMETHOD PutElement(nsISupports *anElementToPut) { return !_to ? NS_ERROR_NULL_POINTER : _to->PutElement(anElementToPut); } \
  NS_SCRIPTABLE NS_IMETHOD StepForward(void) { return !_to ? NS_ERROR_NULL_POINTER : _to->StepForward(); } \
  NS_SCRIPTABLE NS_IMETHOD StepBackward(void) { return !_to ? NS_ERROR_NULL_POINTER : _to->StepBackward(); } \
  NS_SCRIPTABLE NS_IMETHOD IsEqualTo(nsISupports *anotherIterator, PRBool *_retval NS_OUTPARAM) { return !_to ? NS_ERROR_NULL_POINTER : _to->IsEqualTo(anotherIterator, _retval); } \
  NS_SCRIPTABLE NS_IMETHOD Clone(nsISupports **_retval NS_OUTPARAM) { return !_to ? NS_ERROR_NULL_POINTER : _to->Clone(_retval); } 

#if 0
/* Use the code below as a template for the implementation class for this interface. */

/* Header file */
class nsBidirectionalIterator : public nsIBidirectionalIterator
{
public:
  NS_DECL_ISUPPORTS
  NS_DECL_NSIBIDIRECTIONALITERATOR

  nsBidirectionalIterator();

private:
  ~nsBidirectionalIterator();

protected:
  /* additional members */
};

/* Implementation file */
NS_IMPL_ISUPPORTS1(nsBidirectionalIterator, nsIBidirectionalIterator)

nsBidirectionalIterator::nsBidirectionalIterator()
{
  /* member initializers and constructor code */
}

nsBidirectionalIterator::~nsBidirectionalIterator()
{
  /* destructor code */
}

/* nsISupports getElement (); */
NS_IMETHODIMP nsBidirectionalIterator::GetElement(nsISupports **_retval NS_OUTPARAM)
{
    return NS_ERROR_NOT_IMPLEMENTED;
}

/* void putElement (in nsISupports anElementToPut); */
NS_IMETHODIMP nsBidirectionalIterator::PutElement(nsISupports *anElementToPut)
{
    return NS_ERROR_NOT_IMPLEMENTED;
}

/* void stepForward (); */
NS_IMETHODIMP nsBidirectionalIterator::StepForward()
{
    return NS_ERROR_NOT_IMPLEMENTED;
}

/* void stepBackward (); */
NS_IMETHODIMP nsBidirectionalIterator::StepBackward()
{
    return NS_ERROR_NOT_IMPLEMENTED;
}

/* boolean isEqualTo (in nsISupports anotherIterator); */
NS_IMETHODIMP nsBidirectionalIterator::IsEqualTo(nsISupports *anotherIterator, PRBool *_retval NS_OUTPARAM)
{
    return NS_ERROR_NOT_IMPLEMENTED;
}

/* nsISupports clone (); */
NS_IMETHODIMP nsBidirectionalIterator::Clone(nsISupports **_retval NS_OUTPARAM)
{
    return NS_ERROR_NOT_IMPLEMENTED;
}

/* End of implementation class template. */
#endif


/* starting interface:    nsIRandomAccessIterator */
#define NS_IRANDOMACCESSITERATOR_IID_STR "9bd6fdb0-1dd1-11b2-9101-d15375968230"

#define NS_IRANDOMACCESSITERATOR_IID \
  {0x9bd6fdb0, 0x1dd1, 0x11b2, \
    { 0x91, 0x01, 0xd1, 0x53, 0x75, 0x96, 0x82, 0x30 }}

/**
   * ...
   */
class NS_NO_VTABLE NS_SCRIPTABLE nsIRandomAccessIterator : public nsISupports {
 public: 

  NS_DECLARE_STATIC_IID_ACCESSOR(NS_IRANDOMACCESSITERATOR_IID)

  /**
       * Retrieve (and |AddRef()|) the element this iterator currently points to.
       *
       * The result is undefined if this iterator currently points outside the
       * useful range of the underlying container or sequence.
       *
       * @result a new reference to the element this iterator currently points to (if any)
       */
  /* nsISupports getElement (); */
  NS_SCRIPTABLE NS_IMETHOD GetElement(nsISupports **_retval NS_OUTPARAM) = 0;

  /**
       * Retrieve (and |AddRef()|) an element at some offset from where this iterator currently points.
       * The offset may be negative.  |getElementAt(0)| is equivalent to |getElement()|.
       *
       * The result is undefined if this iterator currently points outside the
       * useful range of the underlying container or sequence.
       *
       * @param anOffset a |0|-based offset from the position to which this iterator currently points
       * @result a new reference to the indicated element (if any)
       */
  /* nsISupports getElementAt (in PRInt32 anOffset); */
  NS_SCRIPTABLE NS_IMETHOD GetElementAt(PRInt32 anOffset, nsISupports **_retval NS_OUTPARAM) = 0;

  /**
       * Put |anElementToPut| into the underlying container or sequence at the position currently pointed to by this iterator.
       * The iterator and the underlying container or sequence cooperate to |Release()|
       * the replaced element, if any and if necessary, and to |AddRef()| the new element.
       *
       * The result is undefined if this iterator currently points outside the
       * useful range of the underlying container or sequence.
       *
       * @param anElementToPut the element to place into the underlying container or sequence
       */
  /* void putElement (in nsISupports anElementToPut); */
  NS_SCRIPTABLE NS_IMETHOD PutElement(nsISupports *anElementToPut) = 0;

  /**
       * Put |anElementToPut| into the underlying container or sequence at the position |anOffset| away from that currently pointed to by this iterator.
       * The iterator and the underlying container or sequence cooperate to |Release()|
       * the replaced element, if any and if necessary, and to |AddRef()| the new element.
       * |putElementAt(0, obj)| is equivalent to |putElement(obj)|.
       *
       * The result is undefined if this iterator currently points outside the
       * useful range of the underlying container or sequence.
       *
       * @param anOffset a |0|-based offset from the position to which this iterator currently points
       * @param anElementToPut the element to place into the underlying container or sequence
       */
  /* void putElementAt (in PRInt32 anOffset, in nsISupports anElementToPut); */
  NS_SCRIPTABLE NS_IMETHOD PutElementAt(PRInt32 anOffset, nsISupports *anElementToPut) = 0;

  /**
       * Advance this iterator to the next position in the underlying container or sequence.
       */
  /* void stepForward (); */
  NS_SCRIPTABLE NS_IMETHOD StepForward(void) = 0;

  /**
       * Move this iterator by |anOffset| positions in the underlying container or sequence.
       * |anOffset| may be negative.  |stepForwardBy(1)| is equivalent to |stepForward()|.
       * |stepForwardBy(0)| is a no-op.
       *
       * @param anOffset a |0|-based offset from the position to which this iterator currently points
       */
  /* void stepForwardBy (in PRInt32 anOffset); */
  NS_SCRIPTABLE NS_IMETHOD StepForwardBy(PRInt32 anOffset) = 0;

  /**
       * Move this iterator to the previous position in the underlying container or sequence.
       */
  /* void stepBackward (); */
  NS_SCRIPTABLE NS_IMETHOD StepBackward(void) = 0;

  /**
       * Move this iterator backwards by |anOffset| positions in the underlying container or sequence.
       * |anOffset| may be negative.  |stepBackwardBy(1)| is equivalent to |stepBackward()|.
       * |stepBackwardBy(n)| is equivalent to |stepForwardBy(-n)|.  |stepBackwardBy(0)| is a no-op.
       *
       * @param anOffset a |0|-based offset from the position to which this iterator currently points
       */
  /* void stepBackwardBy (in PRInt32 anOffset); */
  NS_SCRIPTABLE NS_IMETHOD StepBackwardBy(PRInt32 anOffset) = 0;

  /**
       * Test if |anotherIterator| points to the same position in the underlying container or sequence.
       *
       * The result is undefined if |anotherIterator| was not created by or for the same underlying container or sequence.
       *
       * @param anotherIterator another iterator to compare against, created by or for the same underlying container or sequence
       * @result true if |anotherIterator| points to the same position in the underlying container or sequence
       */
  /* boolean isEqualTo (in nsISupports anotherIterator); */
  NS_SCRIPTABLE NS_IMETHOD IsEqualTo(nsISupports *anotherIterator, PRBool *_retval NS_OUTPARAM) = 0;

  /**
       * Create a new iterator pointing to the same position in the underlying container or sequence to which this iterator currently points.
       * The returned iterator is suitable for use in a subsequent call to |isEqualTo()| against this iterator.
       *
       * @result a new iterator pointing at the same position in the same underlying container or sequence as this iterator
       */
  /* nsISupports clone (); */
  NS_SCRIPTABLE NS_IMETHOD Clone(nsISupports **_retval NS_OUTPARAM) = 0;

};

  NS_DEFINE_STATIC_IID_ACCESSOR(nsIRandomAccessIterator, NS_IRANDOMACCESSITERATOR_IID)

/* Use this macro when declaring classes that implement this interface. */
#define NS_DECL_NSIRANDOMACCESSITERATOR \
  NS_SCRIPTABLE NS_IMETHOD GetElement(nsISupports **_retval NS_OUTPARAM); \
  NS_SCRIPTABLE NS_IMETHOD GetElementAt(PRInt32 anOffset, nsISupports **_retval NS_OUTPARAM); \
  NS_SCRIPTABLE NS_IMETHOD PutElement(nsISupports *anElementToPut); \
  NS_SCRIPTABLE NS_IMETHOD PutElementAt(PRInt32 anOffset, nsISupports *anElementToPut); \
  NS_SCRIPTABLE NS_IMETHOD StepForward(void); \
  NS_SCRIPTABLE NS_IMETHOD StepForwardBy(PRInt32 anOffset); \
  NS_SCRIPTABLE NS_IMETHOD StepBackward(void); \
  NS_SCRIPTABLE NS_IMETHOD StepBackwardBy(PRInt32 anOffset); \
  NS_SCRIPTABLE NS_IMETHOD IsEqualTo(nsISupports *anotherIterator, PRBool *_retval NS_OUTPARAM); \
  NS_SCRIPTABLE NS_IMETHOD Clone(nsISupports **_retval NS_OUTPARAM); 

/* Use this macro to declare functions that forward the behavior of this interface to another object. */
#define NS_FORWARD_NSIRANDOMACCESSITERATOR(_to) \
  NS_SCRIPTABLE NS_IMETHOD GetElement(nsISupports **_retval NS_OUTPARAM) { return _to GetElement(_retval); } \
  NS_SCRIPTABLE NS_IMETHOD GetElementAt(PRInt32 anOffset, nsISupports **_retval NS_OUTPARAM) { return _to GetElementAt(anOffset, _retval); } \
  NS_SCRIPTABLE NS_IMETHOD PutElement(nsISupports *anElementToPut) { return _to PutElement(anElementToPut); } \
  NS_SCRIPTABLE NS_IMETHOD PutElementAt(PRInt32 anOffset, nsISupports *anElementToPut) { return _to PutElementAt(anOffset, anElementToPut); } \
  NS_SCRIPTABLE NS_IMETHOD StepForward(void) { return _to StepForward(); } \
  NS_SCRIPTABLE NS_IMETHOD StepForwardBy(PRInt32 anOffset) { return _to StepForwardBy(anOffset); } \
  NS_SCRIPTABLE NS_IMETHOD StepBackward(void) { return _to StepBackward(); } \
  NS_SCRIPTABLE NS_IMETHOD StepBackwardBy(PRInt32 anOffset) { return _to StepBackwardBy(anOffset); } \
  NS_SCRIPTABLE NS_IMETHOD IsEqualTo(nsISupports *anotherIterator, PRBool *_retval NS_OUTPARAM) { return _to IsEqualTo(anotherIterator, _retval); } \
  NS_SCRIPTABLE NS_IMETHOD Clone(nsISupports **_retval NS_OUTPARAM) { return _to Clone(_retval); } 

/* Use this macro to declare functions that forward the behavior of this interface to another object in a safe way. */
#define NS_FORWARD_SAFE_NSIRANDOMACCESSITERATOR(_to) \
  NS_SCRIPTABLE NS_IMETHOD GetElement(nsISupports **_retval NS_OUTPARAM) { return !_to ? NS_ERROR_NULL_POINTER : _to->GetElement(_retval); } \
  NS_SCRIPTABLE NS_IMETHOD GetElementAt(PRInt32 anOffset, nsISupports **_retval NS_OUTPARAM) { return !_to ? NS_ERROR_NULL_POINTER : _to->GetElementAt(anOffset, _retval); } \
  NS_SCRIPTABLE NS_IMETHOD PutElement(nsISupports *anElementToPut) { return !_to ? NS_ERROR_NULL_POINTER : _to->PutElement(anElementToPut); } \
  NS_SCRIPTABLE NS_IMETHOD PutElementAt(PRInt32 anOffset, nsISupports *anElementToPut) { return !_to ? NS_ERROR_NULL_POINTER : _to->PutElementAt(anOffset, anElementToPut); } \
  NS_SCRIPTABLE NS_IMETHOD StepForward(void) { return !_to ? NS_ERROR_NULL_POINTER : _to->StepForward(); } \
  NS_SCRIPTABLE NS_IMETHOD StepForwardBy(PRInt32 anOffset) { return !_to ? NS_ERROR_NULL_POINTER : _to->StepForwardBy(anOffset); } \
  NS_SCRIPTABLE NS_IMETHOD StepBackward(void) { return !_to ? NS_ERROR_NULL_POINTER : _to->StepBackward(); } \
  NS_SCRIPTABLE NS_IMETHOD StepBackwardBy(PRInt32 anOffset) { return !_to ? NS_ERROR_NULL_POINTER : _to->StepBackwardBy(anOffset); } \
  NS_SCRIPTABLE NS_IMETHOD IsEqualTo(nsISupports *anotherIterator, PRBool *_retval NS_OUTPARAM) { return !_to ? NS_ERROR_NULL_POINTER : _to->IsEqualTo(anotherIterator, _retval); } \
  NS_SCRIPTABLE NS_IMETHOD Clone(nsISupports **_retval NS_OUTPARAM) { return !_to ? NS_ERROR_NULL_POINTER : _to->Clone(_retval); } 

#if 0
/* Use the code below as a template for the implementation class for this interface. */

/* Header file */
class nsRandomAccessIterator : public nsIRandomAccessIterator
{
public:
  NS_DECL_ISUPPORTS
  NS_DECL_NSIRANDOMACCESSITERATOR

  nsRandomAccessIterator();

private:
  ~nsRandomAccessIterator();

protected:
  /* additional members */
};

/* Implementation file */
NS_IMPL_ISUPPORTS1(nsRandomAccessIterator, nsIRandomAccessIterator)

nsRandomAccessIterator::nsRandomAccessIterator()
{
  /* member initializers and constructor code */
}

nsRandomAccessIterator::~nsRandomAccessIterator()
{
  /* destructor code */
}

/* nsISupports getElement (); */
NS_IMETHODIMP nsRandomAccessIterator::GetElement(nsISupports **_retval NS_OUTPARAM)
{
    return NS_ERROR_NOT_IMPLEMENTED;
}

/* nsISupports getElementAt (in PRInt32 anOffset); */
NS_IMETHODIMP nsRandomAccessIterator::GetElementAt(PRInt32 anOffset, nsISupports **_retval NS_OUTPARAM)
{
    return NS_ERROR_NOT_IMPLEMENTED;
}

/* void putElement (in nsISupports anElementToPut); */
NS_IMETHODIMP nsRandomAccessIterator::PutElement(nsISupports *anElementToPut)
{
    return NS_ERROR_NOT_IMPLEMENTED;
}

/* void putElementAt (in PRInt32 anOffset, in nsISupports anElementToPut); */
NS_IMETHODIMP nsRandomAccessIterator::PutElementAt(PRInt32 anOffset, nsISupports *anElementToPut)
{
    return NS_ERROR_NOT_IMPLEMENTED;
}

/* void stepForward (); */
NS_IMETHODIMP nsRandomAccessIterator::StepForward()
{
    return NS_ERROR_NOT_IMPLEMENTED;
}

/* void stepForwardBy (in PRInt32 anOffset); */
NS_IMETHODIMP nsRandomAccessIterator::StepForwardBy(PRInt32 anOffset)
{
    return NS_ERROR_NOT_IMPLEMENTED;
}

/* void stepBackward (); */
NS_IMETHODIMP nsRandomAccessIterator::StepBackward()
{
    return NS_ERROR_NOT_IMPLEMENTED;
}

/* void stepBackwardBy (in PRInt32 anOffset); */
NS_IMETHODIMP nsRandomAccessIterator::StepBackwardBy(PRInt32 anOffset)
{
    return NS_ERROR_NOT_IMPLEMENTED;
}

/* boolean isEqualTo (in nsISupports anotherIterator); */
NS_IMETHODIMP nsRandomAccessIterator::IsEqualTo(nsISupports *anotherIterator, PRBool *_retval NS_OUTPARAM)
{
    return NS_ERROR_NOT_IMPLEMENTED;
}

/* nsISupports clone (); */
NS_IMETHODIMP nsRandomAccessIterator::Clone(nsISupports **_retval NS_OUTPARAM)
{
    return NS_ERROR_NOT_IMPLEMENTED;
}

/* End of implementation class template. */
#endif


#endif /* __gen_nsISupportsIterators_h__ */
