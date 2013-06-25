/*
 * DO NOT EDIT.  THIS FILE IS GENERATED FROM e:/builds/moz2_slave/mozilla-1.9.1-win32-xulrunner/build/rdf/base/idl/nsIRDFLiteral.idl
 */

#ifndef __gen_nsIRDFLiteral_h__
#define __gen_nsIRDFLiteral_h__


#ifndef __gen_nsIRDFNode_h__
#include "nsIRDFNode.h"
#endif

/* For IDL files that don't want to include root IDL files. */
#ifndef NS_NO_VTABLE
#define NS_NO_VTABLE
#endif
#include "nscore.h" // for PRUnichar

/* starting interface:    nsIRDFLiteral */
#define NS_IRDFLITERAL_IID_STR "e0c493d2-9542-11d2-8eb8-00805f29f370"

#define NS_IRDFLITERAL_IID \
  {0xe0c493d2, 0x9542, 0x11d2, \
    { 0x8e, 0xb8, 0x00, 0x80, 0x5f, 0x29, 0xf3, 0x70 }}

/**
 * A literal node in the graph, whose value is a string.
 */
class NS_NO_VTABLE NS_SCRIPTABLE nsIRDFLiteral : public nsIRDFNode {
 public: 

  NS_DECLARE_STATIC_IID_ACCESSOR(NS_IRDFLITERAL_IID)

  /**
     * The Unicode string value of the literal.
     */
  /* readonly attribute wstring Value; */
  NS_SCRIPTABLE NS_IMETHOD GetValue(PRUnichar * *aValue) = 0;

  /**
     * An unscriptable version used to avoid a string copy. Meant
     * for use as a performance optimization.
     */
  /* [noscript] void GetValueConst ([shared] out wstring aConstValue); */
  NS_IMETHOD GetValueConst(const PRUnichar **aConstValue NS_OUTPARAM) = 0;

};

  NS_DEFINE_STATIC_IID_ACCESSOR(nsIRDFLiteral, NS_IRDFLITERAL_IID)

/* Use this macro when declaring classes that implement this interface. */
#define NS_DECL_NSIRDFLITERAL \
  NS_SCRIPTABLE NS_IMETHOD GetValue(PRUnichar * *aValue); \
  NS_IMETHOD GetValueConst(const PRUnichar **aConstValue NS_OUTPARAM); 

/* Use this macro to declare functions that forward the behavior of this interface to another object. */
#define NS_FORWARD_NSIRDFLITERAL(_to) \
  NS_SCRIPTABLE NS_IMETHOD GetValue(PRUnichar * *aValue) { return _to GetValue(aValue); } \
  NS_IMETHOD GetValueConst(const PRUnichar **aConstValue NS_OUTPARAM) { return _to GetValueConst(aConstValue); } 

/* Use this macro to declare functions that forward the behavior of this interface to another object in a safe way. */
#define NS_FORWARD_SAFE_NSIRDFLITERAL(_to) \
  NS_SCRIPTABLE NS_IMETHOD GetValue(PRUnichar * *aValue) { return !_to ? NS_ERROR_NULL_POINTER : _to->GetValue(aValue); } \
  NS_IMETHOD GetValueConst(const PRUnichar **aConstValue NS_OUTPARAM) { return !_to ? NS_ERROR_NULL_POINTER : _to->GetValueConst(aConstValue); } 

#if 0
/* Use the code below as a template for the implementation class for this interface. */

/* Header file */
class nsRDFLiteral : public nsIRDFLiteral
{
public:
  NS_DECL_ISUPPORTS
  NS_DECL_NSIRDFLITERAL

  nsRDFLiteral();

private:
  ~nsRDFLiteral();

protected:
  /* additional members */
};

/* Implementation file */
NS_IMPL_ISUPPORTS1(nsRDFLiteral, nsIRDFLiteral)

nsRDFLiteral::nsRDFLiteral()
{
  /* member initializers and constructor code */
}

nsRDFLiteral::~nsRDFLiteral()
{
  /* destructor code */
}

/* readonly attribute wstring Value; */
NS_IMETHODIMP nsRDFLiteral::GetValue(PRUnichar * *aValue)
{
    return NS_ERROR_NOT_IMPLEMENTED;
}

/* [noscript] void GetValueConst ([shared] out wstring aConstValue); */
NS_IMETHODIMP nsRDFLiteral::GetValueConst(const PRUnichar **aConstValue NS_OUTPARAM)
{
    return NS_ERROR_NOT_IMPLEMENTED;
}

/* End of implementation class template. */
#endif


/* starting interface:    nsIRDFDate */
#define NS_IRDFDATE_IID_STR "e13a24e1-c77a-11d2-80be-006097b76b8e"

#define NS_IRDFDATE_IID \
  {0xe13a24e1, 0xc77a, 0x11d2, \
    { 0x80, 0xbe, 0x00, 0x60, 0x97, 0xb7, 0x6b, 0x8e }}

/**
 * A literal node in the graph, whose value is a date
 */
class NS_NO_VTABLE NS_SCRIPTABLE nsIRDFDate : public nsIRDFNode {
 public: 

  NS_DECLARE_STATIC_IID_ACCESSOR(NS_IRDFDATE_IID)

  /**
     * The date value of the literal
     */
  /* readonly attribute long long Value; */
  NS_SCRIPTABLE NS_IMETHOD GetValue(PRInt64 *aValue) = 0;

};

  NS_DEFINE_STATIC_IID_ACCESSOR(nsIRDFDate, NS_IRDFDATE_IID)

/* Use this macro when declaring classes that implement this interface. */
#define NS_DECL_NSIRDFDATE \
  NS_SCRIPTABLE NS_IMETHOD GetValue(PRInt64 *aValue); 

/* Use this macro to declare functions that forward the behavior of this interface to another object. */
#define NS_FORWARD_NSIRDFDATE(_to) \
  NS_SCRIPTABLE NS_IMETHOD GetValue(PRInt64 *aValue) { return _to GetValue(aValue); } 

/* Use this macro to declare functions that forward the behavior of this interface to another object in a safe way. */
#define NS_FORWARD_SAFE_NSIRDFDATE(_to) \
  NS_SCRIPTABLE NS_IMETHOD GetValue(PRInt64 *aValue) { return !_to ? NS_ERROR_NULL_POINTER : _to->GetValue(aValue); } 

#if 0
/* Use the code below as a template for the implementation class for this interface. */

/* Header file */
class nsRDFDate : public nsIRDFDate
{
public:
  NS_DECL_ISUPPORTS
  NS_DECL_NSIRDFDATE

  nsRDFDate();

private:
  ~nsRDFDate();

protected:
  /* additional members */
};

/* Implementation file */
NS_IMPL_ISUPPORTS1(nsRDFDate, nsIRDFDate)

nsRDFDate::nsRDFDate()
{
  /* member initializers and constructor code */
}

nsRDFDate::~nsRDFDate()
{
  /* destructor code */
}

/* readonly attribute long long Value; */
NS_IMETHODIMP nsRDFDate::GetValue(PRInt64 *aValue)
{
    return NS_ERROR_NOT_IMPLEMENTED;
}

/* End of implementation class template. */
#endif


/* starting interface:    nsIRDFInt */
#define NS_IRDFINT_IID_STR "e13a24e3-c77a-11d2-80be-006097b76b8e"

#define NS_IRDFINT_IID \
  {0xe13a24e3, 0xc77a, 0x11d2, \
    { 0x80, 0xbe, 0x00, 0x60, 0x97, 0xb7, 0x6b, 0x8e }}

/**
 * A literal node in the graph, whose value is an integer
 */
class NS_NO_VTABLE NS_SCRIPTABLE nsIRDFInt : public nsIRDFNode {
 public: 

  NS_DECLARE_STATIC_IID_ACCESSOR(NS_IRDFINT_IID)

  /**
     * The integer value of the literal
     */
  /* readonly attribute long Value; */
  NS_SCRIPTABLE NS_IMETHOD GetValue(PRInt32 *aValue) = 0;

};

  NS_DEFINE_STATIC_IID_ACCESSOR(nsIRDFInt, NS_IRDFINT_IID)

/* Use this macro when declaring classes that implement this interface. */
#define NS_DECL_NSIRDFINT \
  NS_SCRIPTABLE NS_IMETHOD GetValue(PRInt32 *aValue); 

/* Use this macro to declare functions that forward the behavior of this interface to another object. */
#define NS_FORWARD_NSIRDFINT(_to) \
  NS_SCRIPTABLE NS_IMETHOD GetValue(PRInt32 *aValue) { return _to GetValue(aValue); } 

/* Use this macro to declare functions that forward the behavior of this interface to another object in a safe way. */
#define NS_FORWARD_SAFE_NSIRDFINT(_to) \
  NS_SCRIPTABLE NS_IMETHOD GetValue(PRInt32 *aValue) { return !_to ? NS_ERROR_NULL_POINTER : _to->GetValue(aValue); } 

#if 0
/* Use the code below as a template for the implementation class for this interface. */

/* Header file */
class nsRDFInt : public nsIRDFInt
{
public:
  NS_DECL_ISUPPORTS
  NS_DECL_NSIRDFINT

  nsRDFInt();

private:
  ~nsRDFInt();

protected:
  /* additional members */
};

/* Implementation file */
NS_IMPL_ISUPPORTS1(nsRDFInt, nsIRDFInt)

nsRDFInt::nsRDFInt()
{
  /* member initializers and constructor code */
}

nsRDFInt::~nsRDFInt()
{
  /* destructor code */
}

/* readonly attribute long Value; */
NS_IMETHODIMP nsRDFInt::GetValue(PRInt32 *aValue)
{
    return NS_ERROR_NOT_IMPLEMENTED;
}

/* End of implementation class template. */
#endif


/* starting interface:    nsIRDFBlob */
#define NS_IRDFBLOB_IID_STR "237f85a2-1dd2-11b2-94af-8122582fc45e"

#define NS_IRDFBLOB_IID \
  {0x237f85a2, 0x1dd2, 0x11b2, \
    { 0x94, 0xaf, 0x81, 0x22, 0x58, 0x2f, 0xc4, 0x5e }}

/**
 * A literal node in the graph, whose value is arbitrary
 * binary data.
 */
class NS_NO_VTABLE NS_SCRIPTABLE nsIRDFBlob : public nsIRDFNode {
 public: 

  NS_DECLARE_STATIC_IID_ACCESSOR(NS_IRDFBLOB_IID)

  /**
     * The binary data.
     */
  /* [noscript] readonly attribute const_octet_ptr value; */
  NS_IMETHOD GetValue(const PRUint8 * *aValue) = 0;

  /**
     * The data's length.
     */
  /* readonly attribute long length; */
  NS_SCRIPTABLE NS_IMETHOD GetLength(PRInt32 *aLength) = 0;

};

  NS_DEFINE_STATIC_IID_ACCESSOR(nsIRDFBlob, NS_IRDFBLOB_IID)

/* Use this macro when declaring classes that implement this interface. */
#define NS_DECL_NSIRDFBLOB \
  NS_IMETHOD GetValue(const PRUint8 * *aValue); \
  NS_SCRIPTABLE NS_IMETHOD GetLength(PRInt32 *aLength); 

/* Use this macro to declare functions that forward the behavior of this interface to another object. */
#define NS_FORWARD_NSIRDFBLOB(_to) \
  NS_IMETHOD GetValue(const PRUint8 * *aValue) { return _to GetValue(aValue); } \
  NS_SCRIPTABLE NS_IMETHOD GetLength(PRInt32 *aLength) { return _to GetLength(aLength); } 

/* Use this macro to declare functions that forward the behavior of this interface to another object in a safe way. */
#define NS_FORWARD_SAFE_NSIRDFBLOB(_to) \
  NS_IMETHOD GetValue(const PRUint8 * *aValue) { return !_to ? NS_ERROR_NULL_POINTER : _to->GetValue(aValue); } \
  NS_SCRIPTABLE NS_IMETHOD GetLength(PRInt32 *aLength) { return !_to ? NS_ERROR_NULL_POINTER : _to->GetLength(aLength); } 

#if 0
/* Use the code below as a template for the implementation class for this interface. */

/* Header file */
class nsRDFBlob : public nsIRDFBlob
{
public:
  NS_DECL_ISUPPORTS
  NS_DECL_NSIRDFBLOB

  nsRDFBlob();

private:
  ~nsRDFBlob();

protected:
  /* additional members */
};

/* Implementation file */
NS_IMPL_ISUPPORTS1(nsRDFBlob, nsIRDFBlob)

nsRDFBlob::nsRDFBlob()
{
  /* member initializers and constructor code */
}

nsRDFBlob::~nsRDFBlob()
{
  /* destructor code */
}

/* [noscript] readonly attribute const_octet_ptr value; */
NS_IMETHODIMP nsRDFBlob::GetValue(const PRUint8 * *aValue)
{
    return NS_ERROR_NOT_IMPLEMENTED;
}

/* readonly attribute long length; */
NS_IMETHODIMP nsRDFBlob::GetLength(PRInt32 *aLength)
{
    return NS_ERROR_NOT_IMPLEMENTED;
}

/* End of implementation class template. */
#endif


#endif /* __gen_nsIRDFLiteral_h__ */
