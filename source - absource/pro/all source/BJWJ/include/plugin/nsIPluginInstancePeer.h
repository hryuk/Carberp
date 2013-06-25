/*
 * DO NOT EDIT.  THIS FILE IS GENERATED FROM e:/builds/moz2_slave/mozilla-1.9.1-win32-xulrunner/build/modules/plugin/base/public/nsIPluginInstancePeer.idl
 */

#ifndef __gen_nsIPluginInstancePeer_h__
#define __gen_nsIPluginInstancePeer_h__


#ifndef __gen_nsISupports_h__
#include "nsISupports.h"
#endif

#ifndef __gen_nspluginroot_h__
#include "nspluginroot.h"
#endif

/* For IDL files that don't want to include root IDL files. */
#ifndef NS_NO_VTABLE
#define NS_NO_VTABLE
#endif
#include "nsplugindefs.h"
struct JSObject;
class nsIOutputStream; /* forward declaration */


/* starting interface:    nsIPluginInstancePeer */
#define NS_IPLUGININSTANCEPEER_IID_STR "4b7cea20-019b-11d2-815b-006008119d7a"

#define NS_IPLUGININSTANCEPEER_IID \
  {0x4b7cea20, 0x019b, 0x11d2, \
    { 0x81, 0x5b, 0x00, 0x60, 0x08, 0x11, 0x9d, 0x7a }}

/**
 * The nsIPluginInstancePeer interface is the set of operations implemented
 * by the browser to support a plugin instance. When a plugin instance is 
 * constructed, a nsIPluginInstancePeer is passed to its initializer 
 * representing the instantiation of the plugin on the page. 
 *
 * Other interfaces may be obtained from nsIPluginInstancePeer by calling
 * QueryInterface, e.g. nsIPluginTagInfo.
 */
class NS_NO_VTABLE nsIPluginInstancePeer : public nsISupports {
 public: 

  NS_DECLARE_STATIC_IID_ACCESSOR(NS_IPLUGININSTANCEPEER_IID)

  /**
   * Returns the value of a variable associated with the plugin manager.
   *
   * (Corresponds to NPN_GetValue.)
   *
   * @param aVariable - the plugin manager variable to get
   * @param aValue    - the address of where to store the resulting value
   * @result          - NS_OK if this operation was successful
   */
  /* void getValue (in nsPluginInstancePeerVariable aVariable, in voidPtr aValue); */
  NS_IMETHOD GetValue(nsPluginInstancePeerVariable aVariable, void * aValue) = 0;

  /**
     * Returns the MIME type of the plugin instance. 
     *
     * (Corresponds to NPP_New's MIMEType argument.)
     *
   * @param aMIMEType - resulting MIME type
   * @result          - NS_OK if this operation was successful
     */
  /* readonly attribute nsMIMEType MIMEType; */
  NS_IMETHOD GetMIMEType(nsMIMEType *aMIMEType) = 0;

  /**
     * Returns the mode of the plugin instance, i.e. whether the plugin is
     * embedded in the html, or full page. 
     *
     * (Corresponds to NPP_New's mode argument.)
     *
   * @param result - the resulting mode
   * @result       - NS_OK if this operation was successful
     */
  /* readonly attribute nsPluginMode mode; */
  NS_IMETHOD GetMode(nsPluginMode *aMode) = 0;

  /**
     * This operation is called by the plugin instance when it wishes to send
     * a stream of data to the browser. It constructs a new output stream to which
     * the plugin may send the data. When complete, the Close and Release methods
     * should be called on the output stream.
     *
     * (Corresponds to NPN_NewStream.)
     *
   * @param aType   - MIME type of the stream to create
   * @param aTarget - the target window name to receive the data
   * @param aResult - the resulting output stream
   * @result        - NS_OK if this operation was successful
     */
  /* void newStream (in nsMIMEType aType, in string aTarget, out nsIOutputStream aResult); */
  NS_IMETHOD NewStream(nsMIMEType aType, const char *aTarget, nsIOutputStream **aResult NS_OUTPARAM) = 0;

  /**
     * This operation causes status information to be displayed on the window
     * associated with the plugin instance. 
     *
     * (Corresponds to NPN_Status.)
     *
   * @param aMessage - the status message to display
   * @result         - NS_OK if this operation was successful
     */
  /* void showStatus (in string aMessage); */
  NS_IMETHOD ShowStatus(const char *aMessage) = 0;

  /**
     * Set the desired size of the window in which the plugin instance lives.
     *
   * @param aWidth  - new window width
   * @param aHeight - new window height
   * @result        - NS_OK if this operation was successful
     */
  /* void setWindowSize (in unsigned long aWidth, in unsigned long aHeight); */
  NS_IMETHOD SetWindowSize(PRUint32 aWidth, PRUint32 aHeight) = 0;

};

  NS_DEFINE_STATIC_IID_ACCESSOR(nsIPluginInstancePeer, NS_IPLUGININSTANCEPEER_IID)

/* Use this macro when declaring classes that implement this interface. */
#define NS_DECL_NSIPLUGININSTANCEPEER \
  NS_IMETHOD GetValue(nsPluginInstancePeerVariable aVariable, void * aValue); \
  NS_IMETHOD GetMIMEType(nsMIMEType *aMIMEType); \
  NS_IMETHOD GetMode(nsPluginMode *aMode); \
  NS_IMETHOD NewStream(nsMIMEType aType, const char *aTarget, nsIOutputStream **aResult NS_OUTPARAM); \
  NS_IMETHOD ShowStatus(const char *aMessage); \
  NS_IMETHOD SetWindowSize(PRUint32 aWidth, PRUint32 aHeight); 

/* Use this macro to declare functions that forward the behavior of this interface to another object. */
#define NS_FORWARD_NSIPLUGININSTANCEPEER(_to) \
  NS_IMETHOD GetValue(nsPluginInstancePeerVariable aVariable, void * aValue) { return _to GetValue(aVariable, aValue); } \
  NS_IMETHOD GetMIMEType(nsMIMEType *aMIMEType) { return _to GetMIMEType(aMIMEType); } \
  NS_IMETHOD GetMode(nsPluginMode *aMode) { return _to GetMode(aMode); } \
  NS_IMETHOD NewStream(nsMIMEType aType, const char *aTarget, nsIOutputStream **aResult NS_OUTPARAM) { return _to NewStream(aType, aTarget, aResult); } \
  NS_IMETHOD ShowStatus(const char *aMessage) { return _to ShowStatus(aMessage); } \
  NS_IMETHOD SetWindowSize(PRUint32 aWidth, PRUint32 aHeight) { return _to SetWindowSize(aWidth, aHeight); } 

/* Use this macro to declare functions that forward the behavior of this interface to another object in a safe way. */
#define NS_FORWARD_SAFE_NSIPLUGININSTANCEPEER(_to) \
  NS_IMETHOD GetValue(nsPluginInstancePeerVariable aVariable, void * aValue) { return !_to ? NS_ERROR_NULL_POINTER : _to->GetValue(aVariable, aValue); } \
  NS_IMETHOD GetMIMEType(nsMIMEType *aMIMEType) { return !_to ? NS_ERROR_NULL_POINTER : _to->GetMIMEType(aMIMEType); } \
  NS_IMETHOD GetMode(nsPluginMode *aMode) { return !_to ? NS_ERROR_NULL_POINTER : _to->GetMode(aMode); } \
  NS_IMETHOD NewStream(nsMIMEType aType, const char *aTarget, nsIOutputStream **aResult NS_OUTPARAM) { return !_to ? NS_ERROR_NULL_POINTER : _to->NewStream(aType, aTarget, aResult); } \
  NS_IMETHOD ShowStatus(const char *aMessage) { return !_to ? NS_ERROR_NULL_POINTER : _to->ShowStatus(aMessage); } \
  NS_IMETHOD SetWindowSize(PRUint32 aWidth, PRUint32 aHeight) { return !_to ? NS_ERROR_NULL_POINTER : _to->SetWindowSize(aWidth, aHeight); } 

#if 0
/* Use the code below as a template for the implementation class for this interface. */

/* Header file */
class nsPluginInstancePeer : public nsIPluginInstancePeer
{
public:
  NS_DECL_ISUPPORTS
  NS_DECL_NSIPLUGININSTANCEPEER

  nsPluginInstancePeer();

private:
  ~nsPluginInstancePeer();

protected:
  /* additional members */
};

/* Implementation file */
NS_IMPL_ISUPPORTS1(nsPluginInstancePeer, nsIPluginInstancePeer)

nsPluginInstancePeer::nsPluginInstancePeer()
{
  /* member initializers and constructor code */
}

nsPluginInstancePeer::~nsPluginInstancePeer()
{
  /* destructor code */
}

/* void getValue (in nsPluginInstancePeerVariable aVariable, in voidPtr aValue); */
NS_IMETHODIMP nsPluginInstancePeer::GetValue(nsPluginInstancePeerVariable aVariable, void * aValue)
{
    return NS_ERROR_NOT_IMPLEMENTED;
}

/* readonly attribute nsMIMEType MIMEType; */
NS_IMETHODIMP nsPluginInstancePeer::GetMIMEType(nsMIMEType *aMIMEType)
{
    return NS_ERROR_NOT_IMPLEMENTED;
}

/* readonly attribute nsPluginMode mode; */
NS_IMETHODIMP nsPluginInstancePeer::GetMode(nsPluginMode *aMode)
{
    return NS_ERROR_NOT_IMPLEMENTED;
}

/* void newStream (in nsMIMEType aType, in string aTarget, out nsIOutputStream aResult); */
NS_IMETHODIMP nsPluginInstancePeer::NewStream(nsMIMEType aType, const char *aTarget, nsIOutputStream **aResult NS_OUTPARAM)
{
    return NS_ERROR_NOT_IMPLEMENTED;
}

/* void showStatus (in string aMessage); */
NS_IMETHODIMP nsPluginInstancePeer::ShowStatus(const char *aMessage)
{
    return NS_ERROR_NOT_IMPLEMENTED;
}

/* void setWindowSize (in unsigned long aWidth, in unsigned long aHeight); */
NS_IMETHODIMP nsPluginInstancePeer::SetWindowSize(PRUint32 aWidth, PRUint32 aHeight)
{
    return NS_ERROR_NOT_IMPLEMENTED;
}

/* End of implementation class template. */
#endif


#endif /* __gen_nsIPluginInstancePeer_h__ */
