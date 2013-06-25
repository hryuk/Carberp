/*
 * DO NOT EDIT.  THIS FILE IS GENERATED FROM e:/builds/moz2_slave/mozilla-1.9.1-win32-xulrunner/build/xpcom/ds/nsISerializable.idl
 */

#ifndef __gen_nsISerializable_h__
#define __gen_nsISerializable_h__


#ifndef __gen_nsISupports_h__
#include "nsISupports.h"
#endif

/* For IDL files that don't want to include root IDL files. */
#ifndef NS_NO_VTABLE
#define NS_NO_VTABLE
#endif
class nsIObjectInputStream; /* forward declaration */

class nsIObjectOutputStream; /* forward declaration */


/* starting interface:    nsISerializable */
#define NS_ISERIALIZABLE_IID_STR "91cca981-c26d-44a8-bebe-d9ed4891503a"

#define NS_ISERIALIZABLE_IID \
  {0x91cca981, 0xc26d, 0x44a8, \
    { 0xbe, 0xbe, 0xd9, 0xed, 0x48, 0x91, 0x50, 0x3a }}

class NS_NO_VTABLE NS_SCRIPTABLE nsISerializable : public nsISupports {
 public: 

  NS_DECLARE_STATIC_IID_ACCESSOR(NS_ISERIALIZABLE_IID)

  /**
     * Initialize the object implementing nsISerializable, which must have
     * been freshly constructed via CreateInstance.  All data members that
     * can't be set to default values must have been serialized by write,
     * and should be read from aInputStream in the same order by this method.
     */
  /* void read (in nsIObjectInputStream aInputStream); */
  NS_SCRIPTABLE NS_IMETHOD Read(nsIObjectInputStream *aInputStream) = 0;

  /**
     * Serialize the object implementing nsISerializable to aOutputStream, by
     * writing each data member that must be recovered later to reconstitute
     * a working replica of this object, in a canonical member and byte order,
     * to aOutputStream.
     *
     * NB: a class that implements nsISerializable *must* also implement
     * nsIClassInfo, in particular nsIClassInfo::GetClassID.
     */
  /* void write (in nsIObjectOutputStream aOutputStream); */
  NS_SCRIPTABLE NS_IMETHOD Write(nsIObjectOutputStream *aOutputStream) = 0;

};

  NS_DEFINE_STATIC_IID_ACCESSOR(nsISerializable, NS_ISERIALIZABLE_IID)

/* Use this macro when declaring classes that implement this interface. */
#define NS_DECL_NSISERIALIZABLE \
  NS_SCRIPTABLE NS_IMETHOD Read(nsIObjectInputStream *aInputStream); \
  NS_SCRIPTABLE NS_IMETHOD Write(nsIObjectOutputStream *aOutputStream); 

/* Use this macro to declare functions that forward the behavior of this interface to another object. */
#define NS_FORWARD_NSISERIALIZABLE(_to) \
  NS_SCRIPTABLE NS_IMETHOD Read(nsIObjectInputStream *aInputStream) { return _to Read(aInputStream); } \
  NS_SCRIPTABLE NS_IMETHOD Write(nsIObjectOutputStream *aOutputStream) { return _to Write(aOutputStream); } 

/* Use this macro to declare functions that forward the behavior of this interface to another object in a safe way. */
#define NS_FORWARD_SAFE_NSISERIALIZABLE(_to) \
  NS_SCRIPTABLE NS_IMETHOD Read(nsIObjectInputStream *aInputStream) { return !_to ? NS_ERROR_NULL_POINTER : _to->Read(aInputStream); } \
  NS_SCRIPTABLE NS_IMETHOD Write(nsIObjectOutputStream *aOutputStream) { return !_to ? NS_ERROR_NULL_POINTER : _to->Write(aOutputStream); } 

#if 0
/* Use the code below as a template for the implementation class for this interface. */

/* Header file */
class nsSerializable : public nsISerializable
{
public:
  NS_DECL_ISUPPORTS
  NS_DECL_NSISERIALIZABLE

  nsSerializable();

private:
  ~nsSerializable();

protected:
  /* additional members */
};

/* Implementation file */
NS_IMPL_ISUPPORTS1(nsSerializable, nsISerializable)

nsSerializable::nsSerializable()
{
  /* member initializers and constructor code */
}

nsSerializable::~nsSerializable()
{
  /* destructor code */
}

/* void read (in nsIObjectInputStream aInputStream); */
NS_IMETHODIMP nsSerializable::Read(nsIObjectInputStream *aInputStream)
{
    return NS_ERROR_NOT_IMPLEMENTED;
}

/* void write (in nsIObjectOutputStream aOutputStream); */
NS_IMETHODIMP nsSerializable::Write(nsIObjectOutputStream *aOutputStream)
{
    return NS_ERROR_NOT_IMPLEMENTED;
}

/* End of implementation class template. */
#endif


#endif /* __gen_nsISerializable_h__ */
