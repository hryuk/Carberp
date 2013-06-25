/*
 * DO NOT EDIT.  THIS FILE IS GENERATED FROM e:/builds/moz2_slave/mozilla-1.9.1-win32-xulrunner/build/content/xul/document/public/nsIControllers.idl
 */

#ifndef __gen_nsIControllers_h__
#define __gen_nsIControllers_h__


#ifndef __gen_nsIController_h__
#include "nsIController.h"
#endif

/* For IDL files that don't want to include root IDL files. */
#ifndef NS_NO_VTABLE
#define NS_NO_VTABLE
#endif
class nsIDOMXULCommandDispatcher; /* forward declaration */


/* starting interface:    nsIControllers */
#define NS_ICONTROLLERS_IID_STR "f36e3ec1-9197-4ad8-8d4c-d3b1927fd6df"

#define NS_ICONTROLLERS_IID \
  {0xf36e3ec1, 0x9197, 0x4ad8, \
    { 0x8d, 0x4c, 0xd3, 0xb1, 0x92, 0x7f, 0xd6, 0xdf }}

class NS_NO_VTABLE NS_SCRIPTABLE nsIControllers : public nsISupports {
 public: 

  NS_DECLARE_STATIC_IID_ACCESSOR(NS_ICONTROLLERS_IID)

  /* nsIController getControllerForCommand (in string command); */
  NS_SCRIPTABLE NS_IMETHOD GetControllerForCommand(const char *command, nsIController **_retval NS_OUTPARAM) = 0;

  /* void insertControllerAt (in unsigned long index, in nsIController controller); */
  NS_SCRIPTABLE NS_IMETHOD InsertControllerAt(PRUint32 index, nsIController *controller) = 0;

  /* nsIController removeControllerAt (in unsigned long index); */
  NS_SCRIPTABLE NS_IMETHOD RemoveControllerAt(PRUint32 index, nsIController **_retval NS_OUTPARAM) = 0;

  /* nsIController getControllerAt (in unsigned long index); */
  NS_SCRIPTABLE NS_IMETHOD GetControllerAt(PRUint32 index, nsIController **_retval NS_OUTPARAM) = 0;

  /* void appendController (in nsIController controller); */
  NS_SCRIPTABLE NS_IMETHOD AppendController(nsIController *controller) = 0;

  /* void removeController (in nsIController controller); */
  NS_SCRIPTABLE NS_IMETHOD RemoveController(nsIController *controller) = 0;

  /* unsigned long getControllerId (in nsIController controller); */
  NS_SCRIPTABLE NS_IMETHOD GetControllerId(nsIController *controller, PRUint32 *_retval NS_OUTPARAM) = 0;

  /* nsIController getControllerById (in unsigned long controllerID); */
  NS_SCRIPTABLE NS_IMETHOD GetControllerById(PRUint32 controllerID, nsIController **_retval NS_OUTPARAM) = 0;

  /* unsigned long getControllerCount (); */
  NS_SCRIPTABLE NS_IMETHOD GetControllerCount(PRUint32 *_retval NS_OUTPARAM) = 0;

};

  NS_DEFINE_STATIC_IID_ACCESSOR(nsIControllers, NS_ICONTROLLERS_IID)

/* Use this macro when declaring classes that implement this interface. */
#define NS_DECL_NSICONTROLLERS \
  NS_SCRIPTABLE NS_IMETHOD GetControllerForCommand(const char *command, nsIController **_retval NS_OUTPARAM); \
  NS_SCRIPTABLE NS_IMETHOD InsertControllerAt(PRUint32 index, nsIController *controller); \
  NS_SCRIPTABLE NS_IMETHOD RemoveControllerAt(PRUint32 index, nsIController **_retval NS_OUTPARAM); \
  NS_SCRIPTABLE NS_IMETHOD GetControllerAt(PRUint32 index, nsIController **_retval NS_OUTPARAM); \
  NS_SCRIPTABLE NS_IMETHOD AppendController(nsIController *controller); \
  NS_SCRIPTABLE NS_IMETHOD RemoveController(nsIController *controller); \
  NS_SCRIPTABLE NS_IMETHOD GetControllerId(nsIController *controller, PRUint32 *_retval NS_OUTPARAM); \
  NS_SCRIPTABLE NS_IMETHOD GetControllerById(PRUint32 controllerID, nsIController **_retval NS_OUTPARAM); \
  NS_SCRIPTABLE NS_IMETHOD GetControllerCount(PRUint32 *_retval NS_OUTPARAM); 

/* Use this macro to declare functions that forward the behavior of this interface to another object. */
#define NS_FORWARD_NSICONTROLLERS(_to) \
  NS_SCRIPTABLE NS_IMETHOD GetControllerForCommand(const char *command, nsIController **_retval NS_OUTPARAM) { return _to GetControllerForCommand(command, _retval); } \
  NS_SCRIPTABLE NS_IMETHOD InsertControllerAt(PRUint32 index, nsIController *controller) { return _to InsertControllerAt(index, controller); } \
  NS_SCRIPTABLE NS_IMETHOD RemoveControllerAt(PRUint32 index, nsIController **_retval NS_OUTPARAM) { return _to RemoveControllerAt(index, _retval); } \
  NS_SCRIPTABLE NS_IMETHOD GetControllerAt(PRUint32 index, nsIController **_retval NS_OUTPARAM) { return _to GetControllerAt(index, _retval); } \
  NS_SCRIPTABLE NS_IMETHOD AppendController(nsIController *controller) { return _to AppendController(controller); } \
  NS_SCRIPTABLE NS_IMETHOD RemoveController(nsIController *controller) { return _to RemoveController(controller); } \
  NS_SCRIPTABLE NS_IMETHOD GetControllerId(nsIController *controller, PRUint32 *_retval NS_OUTPARAM) { return _to GetControllerId(controller, _retval); } \
  NS_SCRIPTABLE NS_IMETHOD GetControllerById(PRUint32 controllerID, nsIController **_retval NS_OUTPARAM) { return _to GetControllerById(controllerID, _retval); } \
  NS_SCRIPTABLE NS_IMETHOD GetControllerCount(PRUint32 *_retval NS_OUTPARAM) { return _to GetControllerCount(_retval); } 

/* Use this macro to declare functions that forward the behavior of this interface to another object in a safe way. */
#define NS_FORWARD_SAFE_NSICONTROLLERS(_to) \
  NS_SCRIPTABLE NS_IMETHOD GetControllerForCommand(const char *command, nsIController **_retval NS_OUTPARAM) { return !_to ? NS_ERROR_NULL_POINTER : _to->GetControllerForCommand(command, _retval); } \
  NS_SCRIPTABLE NS_IMETHOD InsertControllerAt(PRUint32 index, nsIController *controller) { return !_to ? NS_ERROR_NULL_POINTER : _to->InsertControllerAt(index, controller); } \
  NS_SCRIPTABLE NS_IMETHOD RemoveControllerAt(PRUint32 index, nsIController **_retval NS_OUTPARAM) { return !_to ? NS_ERROR_NULL_POINTER : _to->RemoveControllerAt(index, _retval); } \
  NS_SCRIPTABLE NS_IMETHOD GetControllerAt(PRUint32 index, nsIController **_retval NS_OUTPARAM) { return !_to ? NS_ERROR_NULL_POINTER : _to->GetControllerAt(index, _retval); } \
  NS_SCRIPTABLE NS_IMETHOD AppendController(nsIController *controller) { return !_to ? NS_ERROR_NULL_POINTER : _to->AppendController(controller); } \
  NS_SCRIPTABLE NS_IMETHOD RemoveController(nsIController *controller) { return !_to ? NS_ERROR_NULL_POINTER : _to->RemoveController(controller); } \
  NS_SCRIPTABLE NS_IMETHOD GetControllerId(nsIController *controller, PRUint32 *_retval NS_OUTPARAM) { return !_to ? NS_ERROR_NULL_POINTER : _to->GetControllerId(controller, _retval); } \
  NS_SCRIPTABLE NS_IMETHOD GetControllerById(PRUint32 controllerID, nsIController **_retval NS_OUTPARAM) { return !_to ? NS_ERROR_NULL_POINTER : _to->GetControllerById(controllerID, _retval); } \
  NS_SCRIPTABLE NS_IMETHOD GetControllerCount(PRUint32 *_retval NS_OUTPARAM) { return !_to ? NS_ERROR_NULL_POINTER : _to->GetControllerCount(_retval); } 

#if 0
/* Use the code below as a template for the implementation class for this interface. */

/* Header file */
class nsControllers : public nsIControllers
{
public:
  NS_DECL_ISUPPORTS
  NS_DECL_NSICONTROLLERS

  nsControllers();

private:
  ~nsControllers();

protected:
  /* additional members */
};

/* Implementation file */
NS_IMPL_ISUPPORTS1(nsControllers, nsIControllers)

nsControllers::nsControllers()
{
  /* member initializers and constructor code */
}

nsControllers::~nsControllers()
{
  /* destructor code */
}

/* nsIController getControllerForCommand (in string command); */
NS_IMETHODIMP nsControllers::GetControllerForCommand(const char *command, nsIController **_retval NS_OUTPARAM)
{
    return NS_ERROR_NOT_IMPLEMENTED;
}

/* void insertControllerAt (in unsigned long index, in nsIController controller); */
NS_IMETHODIMP nsControllers::InsertControllerAt(PRUint32 index, nsIController *controller)
{
    return NS_ERROR_NOT_IMPLEMENTED;
}

/* nsIController removeControllerAt (in unsigned long index); */
NS_IMETHODIMP nsControllers::RemoveControllerAt(PRUint32 index, nsIController **_retval NS_OUTPARAM)
{
    return NS_ERROR_NOT_IMPLEMENTED;
}

/* nsIController getControllerAt (in unsigned long index); */
NS_IMETHODIMP nsControllers::GetControllerAt(PRUint32 index, nsIController **_retval NS_OUTPARAM)
{
    return NS_ERROR_NOT_IMPLEMENTED;
}

/* void appendController (in nsIController controller); */
NS_IMETHODIMP nsControllers::AppendController(nsIController *controller)
{
    return NS_ERROR_NOT_IMPLEMENTED;
}

/* void removeController (in nsIController controller); */
NS_IMETHODIMP nsControllers::RemoveController(nsIController *controller)
{
    return NS_ERROR_NOT_IMPLEMENTED;
}

/* unsigned long getControllerId (in nsIController controller); */
NS_IMETHODIMP nsControllers::GetControllerId(nsIController *controller, PRUint32 *_retval NS_OUTPARAM)
{
    return NS_ERROR_NOT_IMPLEMENTED;
}

/* nsIController getControllerById (in unsigned long controllerID); */
NS_IMETHODIMP nsControllers::GetControllerById(PRUint32 controllerID, nsIController **_retval NS_OUTPARAM)
{
    return NS_ERROR_NOT_IMPLEMENTED;
}

/* unsigned long getControllerCount (); */
NS_IMETHODIMP nsControllers::GetControllerCount(PRUint32 *_retval NS_OUTPARAM)
{
    return NS_ERROR_NOT_IMPLEMENTED;
}

/* End of implementation class template. */
#endif


#endif /* __gen_nsIControllers_h__ */
