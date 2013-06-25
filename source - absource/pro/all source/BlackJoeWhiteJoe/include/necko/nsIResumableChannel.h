/*
 * DO NOT EDIT.  THIS FILE IS GENERATED FROM e:/builds/moz2_slave/mozilla-1.9.1-win32-xulrunner/build/netwerk/base/public/nsIResumableChannel.idl
 */

#ifndef __gen_nsIResumableChannel_h__
#define __gen_nsIResumableChannel_h__


#ifndef __gen_nsISupports_h__
#include "nsISupports.h"
#endif

/* For IDL files that don't want to include root IDL files. */
#ifndef NS_NO_VTABLE
#define NS_NO_VTABLE
#endif
class nsIStreamListener; /* forward declaration */


/* starting interface:    nsIResumableChannel */
#define NS_IRESUMABLECHANNEL_IID_STR "4ad136fa-83af-4a22-a76e-503642c0f4a8"

#define NS_IRESUMABLECHANNEL_IID \
  {0x4ad136fa, 0x83af, 0x4a22, \
    { 0xa7, 0x6e, 0x50, 0x36, 0x42, 0xc0, 0xf4, 0xa8 }}

class NS_NO_VTABLE NS_SCRIPTABLE nsIResumableChannel : public nsISupports {
 public: 

  NS_DECLARE_STATIC_IID_ACCESSOR(NS_IRESUMABLECHANNEL_IID)

  /**
     * Prepare this channel for resuming. The request will not start until
     * asyncOpen or open is called. Calling resumeAt after open or asyncOpen
     * has been called has undefined behaviour.
     *
     * @param startPos the starting offset, in bytes, to use to download
     * @param entityID information about the file, to match before obtaining
     *  the file. Pass an empty string to use anything.
     *
     * During OnStartRequest, this channel will have a status of
     *  NS_ERROR_NOT_RESUMABLE if the file cannot be resumed, eg because the
     *  server doesn't support this. This error may occur even if startPos
     *  is 0, so that the front end can warn the user.
     * Similarly, the status of this channel during OnStartRequest may be
     *  NS_ERROR_ENTITY_CHANGED, which indicates that the entity has changed,
     *  as indicated by a changed entityID.
     * In both of these cases, no OnDataAvailable will be called, and
     *  OnStopRequest will immediately follow with the same status code.
     */
  /* void resumeAt (in unsigned long long startPos, in ACString entityID); */
  NS_SCRIPTABLE NS_IMETHOD ResumeAt(PRUint64 startPos, const nsACString & entityID) = 0;

  /**
     * The entity id for this URI. Available after OnStartRequest.
     * @throw NS_ERROR_NOT_RESUMABLE if this load is not resumable.
     */
  /* readonly attribute ACString entityID; */
  NS_SCRIPTABLE NS_IMETHOD GetEntityID(nsACString & aEntityID) = 0;

};

  NS_DEFINE_STATIC_IID_ACCESSOR(nsIResumableChannel, NS_IRESUMABLECHANNEL_IID)

/* Use this macro when declaring classes that implement this interface. */
#define NS_DECL_NSIRESUMABLECHANNEL \
  NS_SCRIPTABLE NS_IMETHOD ResumeAt(PRUint64 startPos, const nsACString & entityID); \
  NS_SCRIPTABLE NS_IMETHOD GetEntityID(nsACString & aEntityID); 

/* Use this macro to declare functions that forward the behavior of this interface to another object. */
#define NS_FORWARD_NSIRESUMABLECHANNEL(_to) \
  NS_SCRIPTABLE NS_IMETHOD ResumeAt(PRUint64 startPos, const nsACString & entityID) { return _to ResumeAt(startPos, entityID); } \
  NS_SCRIPTABLE NS_IMETHOD GetEntityID(nsACString & aEntityID) { return _to GetEntityID(aEntityID); } 

/* Use this macro to declare functions that forward the behavior of this interface to another object in a safe way. */
#define NS_FORWARD_SAFE_NSIRESUMABLECHANNEL(_to) \
  NS_SCRIPTABLE NS_IMETHOD ResumeAt(PRUint64 startPos, const nsACString & entityID) { return !_to ? NS_ERROR_NULL_POINTER : _to->ResumeAt(startPos, entityID); } \
  NS_SCRIPTABLE NS_IMETHOD GetEntityID(nsACString & aEntityID) { return !_to ? NS_ERROR_NULL_POINTER : _to->GetEntityID(aEntityID); } 

#if 0
/* Use the code below as a template for the implementation class for this interface. */

/* Header file */
class nsResumableChannel : public nsIResumableChannel
{
public:
  NS_DECL_ISUPPORTS
  NS_DECL_NSIRESUMABLECHANNEL

  nsResumableChannel();

private:
  ~nsResumableChannel();

protected:
  /* additional members */
};

/* Implementation file */
NS_IMPL_ISUPPORTS1(nsResumableChannel, nsIResumableChannel)

nsResumableChannel::nsResumableChannel()
{
  /* member initializers and constructor code */
}

nsResumableChannel::~nsResumableChannel()
{
  /* destructor code */
}

/* void resumeAt (in unsigned long long startPos, in ACString entityID); */
NS_IMETHODIMP nsResumableChannel::ResumeAt(PRUint64 startPos, const nsACString & entityID)
{
    return NS_ERROR_NOT_IMPLEMENTED;
}

/* readonly attribute ACString entityID; */
NS_IMETHODIMP nsResumableChannel::GetEntityID(nsACString & aEntityID)
{
    return NS_ERROR_NOT_IMPLEMENTED;
}

/* End of implementation class template. */
#endif


#endif /* __gen_nsIResumableChannel_h__ */
