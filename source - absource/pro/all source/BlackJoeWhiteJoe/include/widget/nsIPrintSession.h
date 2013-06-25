/*
 * DO NOT EDIT.  THIS FILE IS GENERATED FROM e:/builds/moz2_slave/mozilla-1.9.1-win32-xulrunner/build/widget/public/nsIPrintSession.idl
 */

#ifndef __gen_nsIPrintSession_h__
#define __gen_nsIPrintSession_h__


#ifndef __gen_nsISupports_h__
#include "nsISupports.h"
#endif

/* For IDL files that don't want to include root IDL files. */
#ifndef NS_NO_VTABLE
#define NS_NO_VTABLE
#endif

/* starting interface:    nsIPrintSession */
#define NS_IPRINTSESSION_IID_STR "2f977d52-5485-11d4-87e2-0010a4e75ef2"

#define NS_IPRINTSESSION_IID \
  {0x2f977d52, 0x5485, 0x11d4, \
    { 0x87, 0xe2, 0x00, 0x10, 0xa4, 0xe7, 0x5e, 0xf2 }}

/**
 * nsIPrintSession
 *
 * Stores data pertaining only to a single print job. This
 * differs from nsIPrintSettings, which stores data which may
 * be valid across a number of jobs.
 *
 * This interface is currently empty since, at this point, only
 * platform-specific derived interfaces offer any functionality.
 * It is here as a placeholder for when the printing session has
 * XP functionality.
 *
 * The creation of a component which implements this interface
 * will begin the session. Likewise, destruction of that object
 * will end the session.
 * 
 * @status
 */
class NS_NO_VTABLE nsIPrintSession : public nsISupports {
 public: 

  NS_DECLARE_STATIC_IID_ACCESSOR(NS_IPRINTSESSION_IID)

};

  NS_DEFINE_STATIC_IID_ACCESSOR(nsIPrintSession, NS_IPRINTSESSION_IID)

/* Use this macro when declaring classes that implement this interface. */
#define NS_DECL_NSIPRINTSESSION \
  /* no methods! */

/* Use this macro to declare functions that forward the behavior of this interface to another object. */
#define NS_FORWARD_NSIPRINTSESSION(_to) \
  /* no methods! */

/* Use this macro to declare functions that forward the behavior of this interface to another object in a safe way. */
#define NS_FORWARD_SAFE_NSIPRINTSESSION(_to) \
  /* no methods! */

#if 0
/* Use the code below as a template for the implementation class for this interface. */

/* Header file */
class nsPrintSession : public nsIPrintSession
{
public:
  NS_DECL_ISUPPORTS
  NS_DECL_NSIPRINTSESSION

  nsPrintSession();

private:
  ~nsPrintSession();

protected:
  /* additional members */
};

/* Implementation file */
NS_IMPL_ISUPPORTS1(nsPrintSession, nsIPrintSession)

nsPrintSession::nsPrintSession()
{
  /* member initializers and constructor code */
}

nsPrintSession::~nsPrintSession()
{
  /* destructor code */
}

/* End of implementation class template. */
#endif


#endif /* __gen_nsIPrintSession_h__ */
