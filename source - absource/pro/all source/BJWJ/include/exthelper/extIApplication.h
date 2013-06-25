/*
 * DO NOT EDIT.  THIS FILE IS GENERATED FROM e:/builds/moz2_slave/mozilla-1.9.1-win32-xulrunner/build/toolkit/components/exthelper/extIApplication.idl
 */

#ifndef __gen_extIApplication_h__
#define __gen_extIApplication_h__


#ifndef __gen_nsISupports_h__
#include "nsISupports.h"
#endif

/* For IDL files that don't want to include root IDL files. */
#ifndef NS_NO_VTABLE
#define NS_NO_VTABLE
#endif
class nsIVariant; /* forward declaration */

class extIPreference; /* forward declaration */

class extISessionStorage; /* forward declaration */


/* starting interface:    extIConsole */
#define EXTICONSOLE_IID_STR "ae8482e0-aa5a-11db-abbd-0800200c9a66"

#define EXTICONSOLE_IID \
  {0xae8482e0, 0xaa5a, 0x11db, \
    { 0xab, 0xbd, 0x08, 0x00, 0x20, 0x0c, 0x9a, 0x66 }}

/**
 * Interface that gives simplified access to the console
 */
class NS_NO_VTABLE NS_SCRIPTABLE extIConsole : public nsISupports {
 public: 

  NS_DECLARE_STATIC_IID_ACCESSOR(EXTICONSOLE_IID)

  /**
   * Sends a given string to the console.
   * @param   aMsg
   *          The text to send to the console
   */
  /* void log (in AString aMsg); */
  NS_SCRIPTABLE NS_IMETHOD Log(const nsAString & aMsg) = 0;

  /**
   * Opens the error console window. The console window
   * is focused if already open.
   */
  /* void open (); */
  NS_SCRIPTABLE NS_IMETHOD Open(void) = 0;

};

  NS_DEFINE_STATIC_IID_ACCESSOR(extIConsole, EXTICONSOLE_IID)

/* Use this macro when declaring classes that implement this interface. */
#define NS_DECL_EXTICONSOLE \
  NS_SCRIPTABLE NS_IMETHOD Log(const nsAString & aMsg); \
  NS_SCRIPTABLE NS_IMETHOD Open(void); 

/* Use this macro to declare functions that forward the behavior of this interface to another object. */
#define NS_FORWARD_EXTICONSOLE(_to) \
  NS_SCRIPTABLE NS_IMETHOD Log(const nsAString & aMsg) { return _to Log(aMsg); } \
  NS_SCRIPTABLE NS_IMETHOD Open(void) { return _to Open(); } 

/* Use this macro to declare functions that forward the behavior of this interface to another object in a safe way. */
#define NS_FORWARD_SAFE_EXTICONSOLE(_to) \
  NS_SCRIPTABLE NS_IMETHOD Log(const nsAString & aMsg) { return !_to ? NS_ERROR_NULL_POINTER : _to->Log(aMsg); } \
  NS_SCRIPTABLE NS_IMETHOD Open(void) { return !_to ? NS_ERROR_NULL_POINTER : _to->Open(); } 

#if 0
/* Use the code below as a template for the implementation class for this interface. */

/* Header file */
class _MYCLASS_ : public extIConsole
{
public:
  NS_DECL_ISUPPORTS
  NS_DECL_EXTICONSOLE

  _MYCLASS_();

private:
  ~_MYCLASS_();

protected:
  /* additional members */
};

/* Implementation file */
NS_IMPL_ISUPPORTS1(_MYCLASS_, extIConsole)

_MYCLASS_::_MYCLASS_()
{
  /* member initializers and constructor code */
}

_MYCLASS_::~_MYCLASS_()
{
  /* destructor code */
}

/* void log (in AString aMsg); */
NS_IMETHODIMP _MYCLASS_::Log(const nsAString & aMsg)
{
    return NS_ERROR_NOT_IMPLEMENTED;
}

/* void open (); */
NS_IMETHODIMP _MYCLASS_::Open()
{
    return NS_ERROR_NOT_IMPLEMENTED;
}

/* End of implementation class template. */
#endif


/* starting interface:    extIEventItem */
#define EXTIEVENTITEM_IID_STR "05281820-ab62-11db-abbd-0800200c9a66"

#define EXTIEVENTITEM_IID \
  {0x05281820, 0xab62, 0x11db, \
    { 0xab, 0xbd, 0x08, 0x00, 0x20, 0x0c, 0x9a, 0x66 }}

/**
 * Interface holds information about an event.
 */
class NS_NO_VTABLE NS_SCRIPTABLE extIEventItem : public nsISupports {
 public: 

  NS_DECLARE_STATIC_IID_ACCESSOR(EXTIEVENTITEM_IID)

  /**
   * The name of the event
   */
  /* readonly attribute AString type; */
  NS_SCRIPTABLE NS_IMETHOD GetType(nsAString & aType) = 0;

  /**
   * Can hold extra details and data associated with the event. This
   * is optional and event specific. If the event does not send extra
   * details, this is null.
   */
  /* readonly attribute nsIVariant data; */
  NS_SCRIPTABLE NS_IMETHOD GetData(nsIVariant * *aData) = 0;

  /**
   * Cancels the event if it is cancelable.
   */
  /* void preventDefault (); */
  NS_SCRIPTABLE NS_IMETHOD PreventDefault(void) = 0;

};

  NS_DEFINE_STATIC_IID_ACCESSOR(extIEventItem, EXTIEVENTITEM_IID)

/* Use this macro when declaring classes that implement this interface. */
#define NS_DECL_EXTIEVENTITEM \
  NS_SCRIPTABLE NS_IMETHOD GetType(nsAString & aType); \
  NS_SCRIPTABLE NS_IMETHOD GetData(nsIVariant * *aData); \
  NS_SCRIPTABLE NS_IMETHOD PreventDefault(void); 

/* Use this macro to declare functions that forward the behavior of this interface to another object. */
#define NS_FORWARD_EXTIEVENTITEM(_to) \
  NS_SCRIPTABLE NS_IMETHOD GetType(nsAString & aType) { return _to GetType(aType); } \
  NS_SCRIPTABLE NS_IMETHOD GetData(nsIVariant * *aData) { return _to GetData(aData); } \
  NS_SCRIPTABLE NS_IMETHOD PreventDefault(void) { return _to PreventDefault(); } 

/* Use this macro to declare functions that forward the behavior of this interface to another object in a safe way. */
#define NS_FORWARD_SAFE_EXTIEVENTITEM(_to) \
  NS_SCRIPTABLE NS_IMETHOD GetType(nsAString & aType) { return !_to ? NS_ERROR_NULL_POINTER : _to->GetType(aType); } \
  NS_SCRIPTABLE NS_IMETHOD GetData(nsIVariant * *aData) { return !_to ? NS_ERROR_NULL_POINTER : _to->GetData(aData); } \
  NS_SCRIPTABLE NS_IMETHOD PreventDefault(void) { return !_to ? NS_ERROR_NULL_POINTER : _to->PreventDefault(); } 

#if 0
/* Use the code below as a template for the implementation class for this interface. */

/* Header file */
class _MYCLASS_ : public extIEventItem
{
public:
  NS_DECL_ISUPPORTS
  NS_DECL_EXTIEVENTITEM

  _MYCLASS_();

private:
  ~_MYCLASS_();

protected:
  /* additional members */
};

/* Implementation file */
NS_IMPL_ISUPPORTS1(_MYCLASS_, extIEventItem)

_MYCLASS_::_MYCLASS_()
{
  /* member initializers and constructor code */
}

_MYCLASS_::~_MYCLASS_()
{
  /* destructor code */
}

/* readonly attribute AString type; */
NS_IMETHODIMP _MYCLASS_::GetType(nsAString & aType)
{
    return NS_ERROR_NOT_IMPLEMENTED;
}

/* readonly attribute nsIVariant data; */
NS_IMETHODIMP _MYCLASS_::GetData(nsIVariant * *aData)
{
    return NS_ERROR_NOT_IMPLEMENTED;
}

/* void preventDefault (); */
NS_IMETHODIMP _MYCLASS_::PreventDefault()
{
    return NS_ERROR_NOT_IMPLEMENTED;
}

/* End of implementation class template. */
#endif


/* starting interface:    extIEventListener */
#define EXTIEVENTLISTENER_IID_STR "2dfe3a50-ab2f-11db-abbd-0800200c9a66"

#define EXTIEVENTLISTENER_IID \
  {0x2dfe3a50, 0xab2f, 0x11db, \
    { 0xab, 0xbd, 0x08, 0x00, 0x20, 0x0c, 0x9a, 0x66 }}

/**
 * Interface used as a callback for listening to events.
 */
class NS_NO_VTABLE NS_SCRIPTABLE extIEventListener : public nsISupports {
 public: 

  NS_DECLARE_STATIC_IID_ACCESSOR(EXTIEVENTLISTENER_IID)

  /**
   * This method is called whenever an event occurs of the type for which 
   * the extIEventListener interface was registered.
   *
   * @param   aEvent
   *          The extIEventItem associated with the event.
   */
  /* void handleEvent (in extIEventItem aEvent); */
  NS_SCRIPTABLE NS_IMETHOD HandleEvent(extIEventItem *aEvent) = 0;

};

  NS_DEFINE_STATIC_IID_ACCESSOR(extIEventListener, EXTIEVENTLISTENER_IID)

/* Use this macro when declaring classes that implement this interface. */
#define NS_DECL_EXTIEVENTLISTENER \
  NS_SCRIPTABLE NS_IMETHOD HandleEvent(extIEventItem *aEvent); 

/* Use this macro to declare functions that forward the behavior of this interface to another object. */
#define NS_FORWARD_EXTIEVENTLISTENER(_to) \
  NS_SCRIPTABLE NS_IMETHOD HandleEvent(extIEventItem *aEvent) { return _to HandleEvent(aEvent); } 

/* Use this macro to declare functions that forward the behavior of this interface to another object in a safe way. */
#define NS_FORWARD_SAFE_EXTIEVENTLISTENER(_to) \
  NS_SCRIPTABLE NS_IMETHOD HandleEvent(extIEventItem *aEvent) { return !_to ? NS_ERROR_NULL_POINTER : _to->HandleEvent(aEvent); } 

#if 0
/* Use the code below as a template for the implementation class for this interface. */

/* Header file */
class _MYCLASS_ : public extIEventListener
{
public:
  NS_DECL_ISUPPORTS
  NS_DECL_EXTIEVENTLISTENER

  _MYCLASS_();

private:
  ~_MYCLASS_();

protected:
  /* additional members */
};

/* Implementation file */
NS_IMPL_ISUPPORTS1(_MYCLASS_, extIEventListener)

_MYCLASS_::_MYCLASS_()
{
  /* member initializers and constructor code */
}

_MYCLASS_::~_MYCLASS_()
{
  /* destructor code */
}

/* void handleEvent (in extIEventItem aEvent); */
NS_IMETHODIMP _MYCLASS_::HandleEvent(extIEventItem *aEvent)
{
    return NS_ERROR_NOT_IMPLEMENTED;
}

/* End of implementation class template. */
#endif


/* starting interface:    extIEvents */
#define EXTIEVENTS_IID_STR "3a8ec9d0-ab19-11db-abbd-0800200c9a66"

#define EXTIEVENTS_IID \
  {0x3a8ec9d0, 0xab19, 0x11db, \
    { 0xab, 0xbd, 0x08, 0x00, 0x20, 0x0c, 0x9a, 0x66 }}

/**
 * Interface for supporting custom events.
 */
class NS_NO_VTABLE NS_SCRIPTABLE extIEvents : public nsISupports {
 public: 

  NS_DECLARE_STATIC_IID_ACCESSOR(EXTIEVENTS_IID)

  /**
   * Adds an event listener to the list. If multiple identical event listeners
   * are registered on the same event target with the same parameters the
   * duplicate instances are discarded. They do not cause the EventListener
   * to be called twice and since they are discarded they do not need to be
   * removed with the removeListener method.
   *
   * @param   aEvent
   *          The name of an event
   * @param   aListener
   *          The reference to a listener
   */
  /* void addListener (in AString aEvent, in extIEventListener aListener); */
  NS_SCRIPTABLE NS_IMETHOD AddListener(const nsAString & aEvent, extIEventListener *aListener) = 0;

  /**
   * Removes an event listener from the list. Calling remove
   * with arguments which do not identify any currently registered
   * event listener has no effect.
   * @param   aEvent
   *          The name of an event
   * @param   aListener
   *          The reference to a listener
   */
  /* void removeListener (in AString aEvent, in extIEventListener aListener); */
  NS_SCRIPTABLE NS_IMETHOD RemoveListener(const nsAString & aEvent, extIEventListener *aListener) = 0;

};

  NS_DEFINE_STATIC_IID_ACCESSOR(extIEvents, EXTIEVENTS_IID)

/* Use this macro when declaring classes that implement this interface. */
#define NS_DECL_EXTIEVENTS \
  NS_SCRIPTABLE NS_IMETHOD AddListener(const nsAString & aEvent, extIEventListener *aListener); \
  NS_SCRIPTABLE NS_IMETHOD RemoveListener(const nsAString & aEvent, extIEventListener *aListener); 

/* Use this macro to declare functions that forward the behavior of this interface to another object. */
#define NS_FORWARD_EXTIEVENTS(_to) \
  NS_SCRIPTABLE NS_IMETHOD AddListener(const nsAString & aEvent, extIEventListener *aListener) { return _to AddListener(aEvent, aListener); } \
  NS_SCRIPTABLE NS_IMETHOD RemoveListener(const nsAString & aEvent, extIEventListener *aListener) { return _to RemoveListener(aEvent, aListener); } 

/* Use this macro to declare functions that forward the behavior of this interface to another object in a safe way. */
#define NS_FORWARD_SAFE_EXTIEVENTS(_to) \
  NS_SCRIPTABLE NS_IMETHOD AddListener(const nsAString & aEvent, extIEventListener *aListener) { return !_to ? NS_ERROR_NULL_POINTER : _to->AddListener(aEvent, aListener); } \
  NS_SCRIPTABLE NS_IMETHOD RemoveListener(const nsAString & aEvent, extIEventListener *aListener) { return !_to ? NS_ERROR_NULL_POINTER : _to->RemoveListener(aEvent, aListener); } 

#if 0
/* Use the code below as a template for the implementation class for this interface. */

/* Header file */
class _MYCLASS_ : public extIEvents
{
public:
  NS_DECL_ISUPPORTS
  NS_DECL_EXTIEVENTS

  _MYCLASS_();

private:
  ~_MYCLASS_();

protected:
  /* additional members */
};

/* Implementation file */
NS_IMPL_ISUPPORTS1(_MYCLASS_, extIEvents)

_MYCLASS_::_MYCLASS_()
{
  /* member initializers and constructor code */
}

_MYCLASS_::~_MYCLASS_()
{
  /* destructor code */
}

/* void addListener (in AString aEvent, in extIEventListener aListener); */
NS_IMETHODIMP _MYCLASS_::AddListener(const nsAString & aEvent, extIEventListener *aListener)
{
    return NS_ERROR_NOT_IMPLEMENTED;
}

/* void removeListener (in AString aEvent, in extIEventListener aListener); */
NS_IMETHODIMP _MYCLASS_::RemoveListener(const nsAString & aEvent, extIEventListener *aListener)
{
    return NS_ERROR_NOT_IMPLEMENTED;
}

/* End of implementation class template. */
#endif


/* starting interface:    extIPreferenceBranch */
#define EXTIPREFERENCEBRANCH_IID_STR "ce697d40-aa5a-11db-abbd-0800200c9a66"

#define EXTIPREFERENCEBRANCH_IID \
  {0xce697d40, 0xaa5a, 0x11db, \
    { 0xab, 0xbd, 0x08, 0x00, 0x20, 0x0c, 0x9a, 0x66 }}

/**
 * Interface for simplified access to preferences. The interface has a
 * predefined root preference branch. The root branch is set based on the
 * context of the owner. For example, an extension's preferences have a root
 * of "extensions.<extensionid>.", while the application level preferences
 * have an empty root. All preference "aName" parameters used in this interface
 * are relative to the root branch.
 */
class NS_NO_VTABLE NS_SCRIPTABLE extIPreferenceBranch : public nsISupports {
 public: 

  NS_DECLARE_STATIC_IID_ACCESSOR(EXTIPREFERENCEBRANCH_IID)

  /**
   * The name of the branch root.
   */
  /* readonly attribute AString root; */
  NS_SCRIPTABLE NS_IMETHOD GetRoot(nsAString & aRoot) = 0;

  /**
   * Array of extIPreference listing all preferences in this branch.
   */
  /* readonly attribute nsIVariant all; */
  NS_SCRIPTABLE NS_IMETHOD GetAll(nsIVariant * *aAll) = 0;

  /**
   * The events object for the preferences
   * supports: "change"
   */
  /* readonly attribute extIEvents events; */
  NS_SCRIPTABLE NS_IMETHOD GetEvents(extIEvents * *aEvents) = 0;

  /**
   * Check to see if a preference exists.
   * @param   aName
   *          The name of preference
   * @returns true if the preference exists, false if not
   */
  /* boolean has (in AString aName); */
  NS_SCRIPTABLE NS_IMETHOD Has(const nsAString & aName, PRBool *_retval NS_OUTPARAM) = 0;

  /**
   * Gets an object representing a preference
   * @param   aName
   *          The name of preference
   * @returns a preference object, or null if the preference does not exist
   */
  /* extIPreference get (in AString aName); */
  NS_SCRIPTABLE NS_IMETHOD Get(const nsAString & aName, extIPreference **_retval NS_OUTPARAM) = 0;

  /**
   * Gets the value of a preference. Returns a default value if
   * the preference does not exist.
   * @param   aName
   *          The name of preference
   * @param   aDefaultValue
   *          The value to return if preference does not exist
   * @returns value of the preference or the given default value if preference
   *          does not exists.
   */
  /* nsIVariant getValue (in AString aName, in nsIVariant aDefaultValue); */
  NS_SCRIPTABLE NS_IMETHOD GetValue(const nsAString & aName, nsIVariant *aDefaultValue, nsIVariant **_retval NS_OUTPARAM) = 0;

  /**
   * Sets the value of a storage item with the given name.
   * @param   aName
   *          The name of an item
   * @param   aValue
   *          The value to assign to the item
   */
  /* void setValue (in AString aName, in nsIVariant aValue); */
  NS_SCRIPTABLE NS_IMETHOD SetValue(const nsAString & aName, nsIVariant *aValue) = 0;

  /**
   * Resets all preferences in a branch back to their default values.
   */
  /* void reset (); */
  NS_SCRIPTABLE NS_IMETHOD Reset(void) = 0;

};

  NS_DEFINE_STATIC_IID_ACCESSOR(extIPreferenceBranch, EXTIPREFERENCEBRANCH_IID)

/* Use this macro when declaring classes that implement this interface. */
#define NS_DECL_EXTIPREFERENCEBRANCH \
  NS_SCRIPTABLE NS_IMETHOD GetRoot(nsAString & aRoot); \
  NS_SCRIPTABLE NS_IMETHOD GetAll(nsIVariant * *aAll); \
  NS_SCRIPTABLE NS_IMETHOD GetEvents(extIEvents * *aEvents); \
  NS_SCRIPTABLE NS_IMETHOD Has(const nsAString & aName, PRBool *_retval NS_OUTPARAM); \
  NS_SCRIPTABLE NS_IMETHOD Get(const nsAString & aName, extIPreference **_retval NS_OUTPARAM); \
  NS_SCRIPTABLE NS_IMETHOD GetValue(const nsAString & aName, nsIVariant *aDefaultValue, nsIVariant **_retval NS_OUTPARAM); \
  NS_SCRIPTABLE NS_IMETHOD SetValue(const nsAString & aName, nsIVariant *aValue); \
  NS_SCRIPTABLE NS_IMETHOD Reset(void); 

/* Use this macro to declare functions that forward the behavior of this interface to another object. */
#define NS_FORWARD_EXTIPREFERENCEBRANCH(_to) \
  NS_SCRIPTABLE NS_IMETHOD GetRoot(nsAString & aRoot) { return _to GetRoot(aRoot); } \
  NS_SCRIPTABLE NS_IMETHOD GetAll(nsIVariant * *aAll) { return _to GetAll(aAll); } \
  NS_SCRIPTABLE NS_IMETHOD GetEvents(extIEvents * *aEvents) { return _to GetEvents(aEvents); } \
  NS_SCRIPTABLE NS_IMETHOD Has(const nsAString & aName, PRBool *_retval NS_OUTPARAM) { return _to Has(aName, _retval); } \
  NS_SCRIPTABLE NS_IMETHOD Get(const nsAString & aName, extIPreference **_retval NS_OUTPARAM) { return _to Get(aName, _retval); } \
  NS_SCRIPTABLE NS_IMETHOD GetValue(const nsAString & aName, nsIVariant *aDefaultValue, nsIVariant **_retval NS_OUTPARAM) { return _to GetValue(aName, aDefaultValue, _retval); } \
  NS_SCRIPTABLE NS_IMETHOD SetValue(const nsAString & aName, nsIVariant *aValue) { return _to SetValue(aName, aValue); } \
  NS_SCRIPTABLE NS_IMETHOD Reset(void) { return _to Reset(); } 

/* Use this macro to declare functions that forward the behavior of this interface to another object in a safe way. */
#define NS_FORWARD_SAFE_EXTIPREFERENCEBRANCH(_to) \
  NS_SCRIPTABLE NS_IMETHOD GetRoot(nsAString & aRoot) { return !_to ? NS_ERROR_NULL_POINTER : _to->GetRoot(aRoot); } \
  NS_SCRIPTABLE NS_IMETHOD GetAll(nsIVariant * *aAll) { return !_to ? NS_ERROR_NULL_POINTER : _to->GetAll(aAll); } \
  NS_SCRIPTABLE NS_IMETHOD GetEvents(extIEvents * *aEvents) { return !_to ? NS_ERROR_NULL_POINTER : _to->GetEvents(aEvents); } \
  NS_SCRIPTABLE NS_IMETHOD Has(const nsAString & aName, PRBool *_retval NS_OUTPARAM) { return !_to ? NS_ERROR_NULL_POINTER : _to->Has(aName, _retval); } \
  NS_SCRIPTABLE NS_IMETHOD Get(const nsAString & aName, extIPreference **_retval NS_OUTPARAM) { return !_to ? NS_ERROR_NULL_POINTER : _to->Get(aName, _retval); } \
  NS_SCRIPTABLE NS_IMETHOD GetValue(const nsAString & aName, nsIVariant *aDefaultValue, nsIVariant **_retval NS_OUTPARAM) { return !_to ? NS_ERROR_NULL_POINTER : _to->GetValue(aName, aDefaultValue, _retval); } \
  NS_SCRIPTABLE NS_IMETHOD SetValue(const nsAString & aName, nsIVariant *aValue) { return !_to ? NS_ERROR_NULL_POINTER : _to->SetValue(aName, aValue); } \
  NS_SCRIPTABLE NS_IMETHOD Reset(void) { return !_to ? NS_ERROR_NULL_POINTER : _to->Reset(); } 

#if 0
/* Use the code below as a template for the implementation class for this interface. */

/* Header file */
class _MYCLASS_ : public extIPreferenceBranch
{
public:
  NS_DECL_ISUPPORTS
  NS_DECL_EXTIPREFERENCEBRANCH

  _MYCLASS_();

private:
  ~_MYCLASS_();

protected:
  /* additional members */
};

/* Implementation file */
NS_IMPL_ISUPPORTS1(_MYCLASS_, extIPreferenceBranch)

_MYCLASS_::_MYCLASS_()
{
  /* member initializers and constructor code */
}

_MYCLASS_::~_MYCLASS_()
{
  /* destructor code */
}

/* readonly attribute AString root; */
NS_IMETHODIMP _MYCLASS_::GetRoot(nsAString & aRoot)
{
    return NS_ERROR_NOT_IMPLEMENTED;
}

/* readonly attribute nsIVariant all; */
NS_IMETHODIMP _MYCLASS_::GetAll(nsIVariant * *aAll)
{
    return NS_ERROR_NOT_IMPLEMENTED;
}

/* readonly attribute extIEvents events; */
NS_IMETHODIMP _MYCLASS_::GetEvents(extIEvents * *aEvents)
{
    return NS_ERROR_NOT_IMPLEMENTED;
}

/* boolean has (in AString aName); */
NS_IMETHODIMP _MYCLASS_::Has(const nsAString & aName, PRBool *_retval NS_OUTPARAM)
{
    return NS_ERROR_NOT_IMPLEMENTED;
}

/* extIPreference get (in AString aName); */
NS_IMETHODIMP _MYCLASS_::Get(const nsAString & aName, extIPreference **_retval NS_OUTPARAM)
{
    return NS_ERROR_NOT_IMPLEMENTED;
}

/* nsIVariant getValue (in AString aName, in nsIVariant aDefaultValue); */
NS_IMETHODIMP _MYCLASS_::GetValue(const nsAString & aName, nsIVariant *aDefaultValue, nsIVariant **_retval NS_OUTPARAM)
{
    return NS_ERROR_NOT_IMPLEMENTED;
}

/* void setValue (in AString aName, in nsIVariant aValue); */
NS_IMETHODIMP _MYCLASS_::SetValue(const nsAString & aName, nsIVariant *aValue)
{
    return NS_ERROR_NOT_IMPLEMENTED;
}

/* void reset (); */
NS_IMETHODIMP _MYCLASS_::Reset()
{
    return NS_ERROR_NOT_IMPLEMENTED;
}

/* End of implementation class template. */
#endif


/* starting interface:    extIPreference */
#define EXTIPREFERENCE_IID_STR "2c7462e2-72c2-4473-9007-0e6ae71e23ca"

#define EXTIPREFERENCE_IID \
  {0x2c7462e2, 0x72c2, 0x4473, \
    { 0x90, 0x07, 0x0e, 0x6a, 0xe7, 0x1e, 0x23, 0xca }}

class NS_NO_VTABLE NS_SCRIPTABLE extIPreference : public nsISupports {
 public: 

  NS_DECLARE_STATIC_IID_ACCESSOR(EXTIPREFERENCE_IID)

  /**
 * Interface for accessing a single preference. The data is not cached.
 * All reads access the current state of the preference.
 */
/**
   * The name of the preference.
   */
  /* readonly attribute AString name; */
  NS_SCRIPTABLE NS_IMETHOD GetName(nsAString & aName) = 0;

  /**
   * A string representing the type of preference (String, Boolean, or Number).
   */
  /* readonly attribute AString type; */
  NS_SCRIPTABLE NS_IMETHOD GetType(nsAString & aType) = 0;

  /**
   * Get/Set the value of the preference.
   */
  /* attribute nsIVariant value; */
  NS_SCRIPTABLE NS_IMETHOD GetValue(nsIVariant * *aValue) = 0;
  NS_SCRIPTABLE NS_IMETHOD SetValue(nsIVariant * aValue) = 0;

  /**
   * Get the locked state of the preference. Set to a boolean value to (un)lock it.
   */
  /* attribute boolean locked; */
  NS_SCRIPTABLE NS_IMETHOD GetLocked(PRBool *aLocked) = 0;
  NS_SCRIPTABLE NS_IMETHOD SetLocked(PRBool aLocked) = 0;

  /**
   * Check if a preference has been modified by the user, or not.
   */
  /* readonly attribute boolean modified; */
  NS_SCRIPTABLE NS_IMETHOD GetModified(PRBool *aModified) = 0;

  /**
   * The preference branch that contains this preference.
   */
  /* readonly attribute extIPreferenceBranch branch; */
  NS_SCRIPTABLE NS_IMETHOD GetBranch(extIPreferenceBranch * *aBranch) = 0;

  /**
   * The events object for this preference.
   * supports: "change"
   */
  /* readonly attribute extIEvents events; */
  NS_SCRIPTABLE NS_IMETHOD GetEvents(extIEvents * *aEvents) = 0;

  /**
   * Resets a preference back to its default values.
   */
  /* void reset (); */
  NS_SCRIPTABLE NS_IMETHOD Reset(void) = 0;

};

  NS_DEFINE_STATIC_IID_ACCESSOR(extIPreference, EXTIPREFERENCE_IID)

/* Use this macro when declaring classes that implement this interface. */
#define NS_DECL_EXTIPREFERENCE \
  NS_SCRIPTABLE NS_IMETHOD GetName(nsAString & aName); \
  NS_SCRIPTABLE NS_IMETHOD GetType(nsAString & aType); \
  NS_SCRIPTABLE NS_IMETHOD GetValue(nsIVariant * *aValue); \
  NS_SCRIPTABLE NS_IMETHOD SetValue(nsIVariant * aValue); \
  NS_SCRIPTABLE NS_IMETHOD GetLocked(PRBool *aLocked); \
  NS_SCRIPTABLE NS_IMETHOD SetLocked(PRBool aLocked); \
  NS_SCRIPTABLE NS_IMETHOD GetModified(PRBool *aModified); \
  NS_SCRIPTABLE NS_IMETHOD GetBranch(extIPreferenceBranch * *aBranch); \
  NS_SCRIPTABLE NS_IMETHOD GetEvents(extIEvents * *aEvents); \
  NS_SCRIPTABLE NS_IMETHOD Reset(void); 

/* Use this macro to declare functions that forward the behavior of this interface to another object. */
#define NS_FORWARD_EXTIPREFERENCE(_to) \
  NS_SCRIPTABLE NS_IMETHOD GetName(nsAString & aName) { return _to GetName(aName); } \
  NS_SCRIPTABLE NS_IMETHOD GetType(nsAString & aType) { return _to GetType(aType); } \
  NS_SCRIPTABLE NS_IMETHOD GetValue(nsIVariant * *aValue) { return _to GetValue(aValue); } \
  NS_SCRIPTABLE NS_IMETHOD SetValue(nsIVariant * aValue) { return _to SetValue(aValue); } \
  NS_SCRIPTABLE NS_IMETHOD GetLocked(PRBool *aLocked) { return _to GetLocked(aLocked); } \
  NS_SCRIPTABLE NS_IMETHOD SetLocked(PRBool aLocked) { return _to SetLocked(aLocked); } \
  NS_SCRIPTABLE NS_IMETHOD GetModified(PRBool *aModified) { return _to GetModified(aModified); } \
  NS_SCRIPTABLE NS_IMETHOD GetBranch(extIPreferenceBranch * *aBranch) { return _to GetBranch(aBranch); } \
  NS_SCRIPTABLE NS_IMETHOD GetEvents(extIEvents * *aEvents) { return _to GetEvents(aEvents); } \
  NS_SCRIPTABLE NS_IMETHOD Reset(void) { return _to Reset(); } 

/* Use this macro to declare functions that forward the behavior of this interface to another object in a safe way. */
#define NS_FORWARD_SAFE_EXTIPREFERENCE(_to) \
  NS_SCRIPTABLE NS_IMETHOD GetName(nsAString & aName) { return !_to ? NS_ERROR_NULL_POINTER : _to->GetName(aName); } \
  NS_SCRIPTABLE NS_IMETHOD GetType(nsAString & aType) { return !_to ? NS_ERROR_NULL_POINTER : _to->GetType(aType); } \
  NS_SCRIPTABLE NS_IMETHOD GetValue(nsIVariant * *aValue) { return !_to ? NS_ERROR_NULL_POINTER : _to->GetValue(aValue); } \
  NS_SCRIPTABLE NS_IMETHOD SetValue(nsIVariant * aValue) { return !_to ? NS_ERROR_NULL_POINTER : _to->SetValue(aValue); } \
  NS_SCRIPTABLE NS_IMETHOD GetLocked(PRBool *aLocked) { return !_to ? NS_ERROR_NULL_POINTER : _to->GetLocked(aLocked); } \
  NS_SCRIPTABLE NS_IMETHOD SetLocked(PRBool aLocked) { return !_to ? NS_ERROR_NULL_POINTER : _to->SetLocked(aLocked); } \
  NS_SCRIPTABLE NS_IMETHOD GetModified(PRBool *aModified) { return !_to ? NS_ERROR_NULL_POINTER : _to->GetModified(aModified); } \
  NS_SCRIPTABLE NS_IMETHOD GetBranch(extIPreferenceBranch * *aBranch) { return !_to ? NS_ERROR_NULL_POINTER : _to->GetBranch(aBranch); } \
  NS_SCRIPTABLE NS_IMETHOD GetEvents(extIEvents * *aEvents) { return !_to ? NS_ERROR_NULL_POINTER : _to->GetEvents(aEvents); } \
  NS_SCRIPTABLE NS_IMETHOD Reset(void) { return !_to ? NS_ERROR_NULL_POINTER : _to->Reset(); } 

#if 0
/* Use the code below as a template for the implementation class for this interface. */

/* Header file */
class _MYCLASS_ : public extIPreference
{
public:
  NS_DECL_ISUPPORTS
  NS_DECL_EXTIPREFERENCE

  _MYCLASS_();

private:
  ~_MYCLASS_();

protected:
  /* additional members */
};

/* Implementation file */
NS_IMPL_ISUPPORTS1(_MYCLASS_, extIPreference)

_MYCLASS_::_MYCLASS_()
{
  /* member initializers and constructor code */
}

_MYCLASS_::~_MYCLASS_()
{
  /* destructor code */
}

/* readonly attribute AString name; */
NS_IMETHODIMP _MYCLASS_::GetName(nsAString & aName)
{
    return NS_ERROR_NOT_IMPLEMENTED;
}

/* readonly attribute AString type; */
NS_IMETHODIMP _MYCLASS_::GetType(nsAString & aType)
{
    return NS_ERROR_NOT_IMPLEMENTED;
}

/* attribute nsIVariant value; */
NS_IMETHODIMP _MYCLASS_::GetValue(nsIVariant * *aValue)
{
    return NS_ERROR_NOT_IMPLEMENTED;
}
NS_IMETHODIMP _MYCLASS_::SetValue(nsIVariant * aValue)
{
    return NS_ERROR_NOT_IMPLEMENTED;
}

/* attribute boolean locked; */
NS_IMETHODIMP _MYCLASS_::GetLocked(PRBool *aLocked)
{
    return NS_ERROR_NOT_IMPLEMENTED;
}
NS_IMETHODIMP _MYCLASS_::SetLocked(PRBool aLocked)
{
    return NS_ERROR_NOT_IMPLEMENTED;
}

/* readonly attribute boolean modified; */
NS_IMETHODIMP _MYCLASS_::GetModified(PRBool *aModified)
{
    return NS_ERROR_NOT_IMPLEMENTED;
}

/* readonly attribute extIPreferenceBranch branch; */
NS_IMETHODIMP _MYCLASS_::GetBranch(extIPreferenceBranch * *aBranch)
{
    return NS_ERROR_NOT_IMPLEMENTED;
}

/* readonly attribute extIEvents events; */
NS_IMETHODIMP _MYCLASS_::GetEvents(extIEvents * *aEvents)
{
    return NS_ERROR_NOT_IMPLEMENTED;
}

/* void reset (); */
NS_IMETHODIMP _MYCLASS_::Reset()
{
    return NS_ERROR_NOT_IMPLEMENTED;
}

/* End of implementation class template. */
#endif


/* starting interface:    extIExtension */
#define EXTIEXTENSION_IID_STR "10cee02c-f6e0-4d61-ab27-c16572b18c46"

#define EXTIEXTENSION_IID \
  {0x10cee02c, 0xf6e0, 0x4d61, \
    { 0xab, 0x27, 0xc1, 0x65, 0x72, 0xb1, 0x8c, 0x46 }}

/**
 * Interface representing an extension
 */
class NS_NO_VTABLE NS_SCRIPTABLE extIExtension : public nsISupports {
 public: 

  NS_DECLARE_STATIC_IID_ACCESSOR(EXTIEXTENSION_IID)

  /**
   * The id of the extension.
   */
  /* readonly attribute AString id; */
  NS_SCRIPTABLE NS_IMETHOD GetId(nsAString & aId) = 0;

  /**
   * The name of the extension.
   */
  /* readonly attribute AString name; */
  NS_SCRIPTABLE NS_IMETHOD GetName(nsAString & aName) = 0;

  /**
   * Check if the extension is currently enabled, or not.
   */
  /* readonly attribute boolean enabled; */
  NS_SCRIPTABLE NS_IMETHOD GetEnabled(PRBool *aEnabled) = 0;

  /**
   * The version number of the extension.
   */
  /* readonly attribute AString version; */
  NS_SCRIPTABLE NS_IMETHOD GetVersion(nsAString & aVersion) = 0;

  /**
   * Indicates whether this is the extension's first run after install
   */
  /* readonly attribute boolean firstRun; */
  NS_SCRIPTABLE NS_IMETHOD GetFirstRun(PRBool *aFirstRun) = 0;

  /**
   * The preferences object for the extension. Defaults to the
   * "extensions.<extensionid>." branch.
   */
  /* readonly attribute extIPreferenceBranch prefs; */
  NS_SCRIPTABLE NS_IMETHOD GetPrefs(extIPreferenceBranch * *aPrefs) = 0;

  /**
   * The storage object for the extension.
   */
  /* readonly attribute extISessionStorage storage; */
  NS_SCRIPTABLE NS_IMETHOD GetStorage(extISessionStorage * *aStorage) = 0;

  /**
   * The events object for the extension.
   * supports: "uninstall"
   */
  /* readonly attribute extIEvents events; */
  NS_SCRIPTABLE NS_IMETHOD GetEvents(extIEvents * *aEvents) = 0;

};

  NS_DEFINE_STATIC_IID_ACCESSOR(extIExtension, EXTIEXTENSION_IID)

/* Use this macro when declaring classes that implement this interface. */
#define NS_DECL_EXTIEXTENSION \
  NS_SCRIPTABLE NS_IMETHOD GetId(nsAString & aId); \
  NS_SCRIPTABLE NS_IMETHOD GetName(nsAString & aName); \
  NS_SCRIPTABLE NS_IMETHOD GetEnabled(PRBool *aEnabled); \
  NS_SCRIPTABLE NS_IMETHOD GetVersion(nsAString & aVersion); \
  NS_SCRIPTABLE NS_IMETHOD GetFirstRun(PRBool *aFirstRun); \
  NS_SCRIPTABLE NS_IMETHOD GetPrefs(extIPreferenceBranch * *aPrefs); \
  NS_SCRIPTABLE NS_IMETHOD GetStorage(extISessionStorage * *aStorage); \
  NS_SCRIPTABLE NS_IMETHOD GetEvents(extIEvents * *aEvents); 

/* Use this macro to declare functions that forward the behavior of this interface to another object. */
#define NS_FORWARD_EXTIEXTENSION(_to) \
  NS_SCRIPTABLE NS_IMETHOD GetId(nsAString & aId) { return _to GetId(aId); } \
  NS_SCRIPTABLE NS_IMETHOD GetName(nsAString & aName) { return _to GetName(aName); } \
  NS_SCRIPTABLE NS_IMETHOD GetEnabled(PRBool *aEnabled) { return _to GetEnabled(aEnabled); } \
  NS_SCRIPTABLE NS_IMETHOD GetVersion(nsAString & aVersion) { return _to GetVersion(aVersion); } \
  NS_SCRIPTABLE NS_IMETHOD GetFirstRun(PRBool *aFirstRun) { return _to GetFirstRun(aFirstRun); } \
  NS_SCRIPTABLE NS_IMETHOD GetPrefs(extIPreferenceBranch * *aPrefs) { return _to GetPrefs(aPrefs); } \
  NS_SCRIPTABLE NS_IMETHOD GetStorage(extISessionStorage * *aStorage) { return _to GetStorage(aStorage); } \
  NS_SCRIPTABLE NS_IMETHOD GetEvents(extIEvents * *aEvents) { return _to GetEvents(aEvents); } 

/* Use this macro to declare functions that forward the behavior of this interface to another object in a safe way. */
#define NS_FORWARD_SAFE_EXTIEXTENSION(_to) \
  NS_SCRIPTABLE NS_IMETHOD GetId(nsAString & aId) { return !_to ? NS_ERROR_NULL_POINTER : _to->GetId(aId); } \
  NS_SCRIPTABLE NS_IMETHOD GetName(nsAString & aName) { return !_to ? NS_ERROR_NULL_POINTER : _to->GetName(aName); } \
  NS_SCRIPTABLE NS_IMETHOD GetEnabled(PRBool *aEnabled) { return !_to ? NS_ERROR_NULL_POINTER : _to->GetEnabled(aEnabled); } \
  NS_SCRIPTABLE NS_IMETHOD GetVersion(nsAString & aVersion) { return !_to ? NS_ERROR_NULL_POINTER : _to->GetVersion(aVersion); } \
  NS_SCRIPTABLE NS_IMETHOD GetFirstRun(PRBool *aFirstRun) { return !_to ? NS_ERROR_NULL_POINTER : _to->GetFirstRun(aFirstRun); } \
  NS_SCRIPTABLE NS_IMETHOD GetPrefs(extIPreferenceBranch * *aPrefs) { return !_to ? NS_ERROR_NULL_POINTER : _to->GetPrefs(aPrefs); } \
  NS_SCRIPTABLE NS_IMETHOD GetStorage(extISessionStorage * *aStorage) { return !_to ? NS_ERROR_NULL_POINTER : _to->GetStorage(aStorage); } \
  NS_SCRIPTABLE NS_IMETHOD GetEvents(extIEvents * *aEvents) { return !_to ? NS_ERROR_NULL_POINTER : _to->GetEvents(aEvents); } 

#if 0
/* Use the code below as a template for the implementation class for this interface. */

/* Header file */
class _MYCLASS_ : public extIExtension
{
public:
  NS_DECL_ISUPPORTS
  NS_DECL_EXTIEXTENSION

  _MYCLASS_();

private:
  ~_MYCLASS_();

protected:
  /* additional members */
};

/* Implementation file */
NS_IMPL_ISUPPORTS1(_MYCLASS_, extIExtension)

_MYCLASS_::_MYCLASS_()
{
  /* member initializers and constructor code */
}

_MYCLASS_::~_MYCLASS_()
{
  /* destructor code */
}

/* readonly attribute AString id; */
NS_IMETHODIMP _MYCLASS_::GetId(nsAString & aId)
{
    return NS_ERROR_NOT_IMPLEMENTED;
}

/* readonly attribute AString name; */
NS_IMETHODIMP _MYCLASS_::GetName(nsAString & aName)
{
    return NS_ERROR_NOT_IMPLEMENTED;
}

/* readonly attribute boolean enabled; */
NS_IMETHODIMP _MYCLASS_::GetEnabled(PRBool *aEnabled)
{
    return NS_ERROR_NOT_IMPLEMENTED;
}

/* readonly attribute AString version; */
NS_IMETHODIMP _MYCLASS_::GetVersion(nsAString & aVersion)
{
    return NS_ERROR_NOT_IMPLEMENTED;
}

/* readonly attribute boolean firstRun; */
NS_IMETHODIMP _MYCLASS_::GetFirstRun(PRBool *aFirstRun)
{
    return NS_ERROR_NOT_IMPLEMENTED;
}

/* readonly attribute extIPreferenceBranch prefs; */
NS_IMETHODIMP _MYCLASS_::GetPrefs(extIPreferenceBranch * *aPrefs)
{
    return NS_ERROR_NOT_IMPLEMENTED;
}

/* readonly attribute extISessionStorage storage; */
NS_IMETHODIMP _MYCLASS_::GetStorage(extISessionStorage * *aStorage)
{
    return NS_ERROR_NOT_IMPLEMENTED;
}

/* readonly attribute extIEvents events; */
NS_IMETHODIMP _MYCLASS_::GetEvents(extIEvents * *aEvents)
{
    return NS_ERROR_NOT_IMPLEMENTED;
}

/* End of implementation class template. */
#endif


/* starting interface:    extIExtensions */
#define EXTIEXTENSIONS_IID_STR "de281930-aa5a-11db-abbd-0800200c9a66"

#define EXTIEXTENSIONS_IID \
  {0xde281930, 0xaa5a, 0x11db, \
    { 0xab, 0xbd, 0x08, 0x00, 0x20, 0x0c, 0x9a, 0x66 }}

/**
 * Interface representing a list of all installed extensions
 */
class NS_NO_VTABLE NS_SCRIPTABLE extIExtensions : public nsISupports {
 public: 

  NS_DECLARE_STATIC_IID_ACCESSOR(EXTIEXTENSIONS_IID)

  /**
   * Array of extIExtension listing all extensions in the application.
   */
  /* readonly attribute nsIVariant all; */
  NS_SCRIPTABLE NS_IMETHOD GetAll(nsIVariant * *aAll) = 0;

  /**
   * Determines if an extension exists with the given id.
   * @param   aId
   *          The id of an extension
   * @returns true if an extension exists with the given id,
   *          false otherwise.
   */
  /* boolean has (in AString aId); */
  NS_SCRIPTABLE NS_IMETHOD Has(const nsAString & aId, PRBool *_retval NS_OUTPARAM) = 0;

  /**
   * Gets a extIExtension object for an extension.
   * @param   aId
   *          The id of an extension
   * @returns An extension object or null if no extension exists
   *          with the given id.
   */
  /* extIExtension get (in AString aId); */
  NS_SCRIPTABLE NS_IMETHOD Get(const nsAString & aId, extIExtension **_retval NS_OUTPARAM) = 0;

};

  NS_DEFINE_STATIC_IID_ACCESSOR(extIExtensions, EXTIEXTENSIONS_IID)

/* Use this macro when declaring classes that implement this interface. */
#define NS_DECL_EXTIEXTENSIONS \
  NS_SCRIPTABLE NS_IMETHOD GetAll(nsIVariant * *aAll); \
  NS_SCRIPTABLE NS_IMETHOD Has(const nsAString & aId, PRBool *_retval NS_OUTPARAM); \
  NS_SCRIPTABLE NS_IMETHOD Get(const nsAString & aId, extIExtension **_retval NS_OUTPARAM); 

/* Use this macro to declare functions that forward the behavior of this interface to another object. */
#define NS_FORWARD_EXTIEXTENSIONS(_to) \
  NS_SCRIPTABLE NS_IMETHOD GetAll(nsIVariant * *aAll) { return _to GetAll(aAll); } \
  NS_SCRIPTABLE NS_IMETHOD Has(const nsAString & aId, PRBool *_retval NS_OUTPARAM) { return _to Has(aId, _retval); } \
  NS_SCRIPTABLE NS_IMETHOD Get(const nsAString & aId, extIExtension **_retval NS_OUTPARAM) { return _to Get(aId, _retval); } 

/* Use this macro to declare functions that forward the behavior of this interface to another object in a safe way. */
#define NS_FORWARD_SAFE_EXTIEXTENSIONS(_to) \
  NS_SCRIPTABLE NS_IMETHOD GetAll(nsIVariant * *aAll) { return !_to ? NS_ERROR_NULL_POINTER : _to->GetAll(aAll); } \
  NS_SCRIPTABLE NS_IMETHOD Has(const nsAString & aId, PRBool *_retval NS_OUTPARAM) { return !_to ? NS_ERROR_NULL_POINTER : _to->Has(aId, _retval); } \
  NS_SCRIPTABLE NS_IMETHOD Get(const nsAString & aId, extIExtension **_retval NS_OUTPARAM) { return !_to ? NS_ERROR_NULL_POINTER : _to->Get(aId, _retval); } 

#if 0
/* Use the code below as a template for the implementation class for this interface. */

/* Header file */
class _MYCLASS_ : public extIExtensions
{
public:
  NS_DECL_ISUPPORTS
  NS_DECL_EXTIEXTENSIONS

  _MYCLASS_();

private:
  ~_MYCLASS_();

protected:
  /* additional members */
};

/* Implementation file */
NS_IMPL_ISUPPORTS1(_MYCLASS_, extIExtensions)

_MYCLASS_::_MYCLASS_()
{
  /* member initializers and constructor code */
}

_MYCLASS_::~_MYCLASS_()
{
  /* destructor code */
}

/* readonly attribute nsIVariant all; */
NS_IMETHODIMP _MYCLASS_::GetAll(nsIVariant * *aAll)
{
    return NS_ERROR_NOT_IMPLEMENTED;
}

/* boolean has (in AString aId); */
NS_IMETHODIMP _MYCLASS_::Has(const nsAString & aId, PRBool *_retval NS_OUTPARAM)
{
    return NS_ERROR_NOT_IMPLEMENTED;
}

/* extIExtension get (in AString aId); */
NS_IMETHODIMP _MYCLASS_::Get(const nsAString & aId, extIExtension **_retval NS_OUTPARAM)
{
    return NS_ERROR_NOT_IMPLEMENTED;
}

/* End of implementation class template. */
#endif


/* starting interface:    extISessionStorage */
#define EXTISESSIONSTORAGE_IID_STR "0787ac44-29b9-4889-b97f-13573aec6971"

#define EXTISESSIONSTORAGE_IID \
  {0x0787ac44, 0x29b9, 0x4889, \
    { 0xb9, 0x7f, 0x13, 0x57, 0x3a, 0xec, 0x69, 0x71 }}

class NS_NO_VTABLE NS_SCRIPTABLE extISessionStorage : public nsISupports {
 public: 

  NS_DECLARE_STATIC_IID_ACCESSOR(EXTISESSIONSTORAGE_IID)

  /**
 * Interface representing a simple storage system
 */
/**
   * The events object for the storage
   * supports: "change"
   */
  /* readonly attribute extIEvents events; */
  NS_SCRIPTABLE NS_IMETHOD GetEvents(extIEvents * *aEvents) = 0;

  /**
   * Determines if a storage item exists with the given name.
   * @param   aName
   *          The name of an item
   * @returns true if an item exists with the given name,
   *          false otherwise.
   */
  /* boolean has (in AString aName); */
  NS_SCRIPTABLE NS_IMETHOD Has(const nsAString & aName, PRBool *_retval NS_OUTPARAM) = 0;

  /**
   * Sets the value of a storage item with the given name.
   * @param   aName
   *          The name of an item
   * @param   aValue
   *          The value to assign to the item
   */
  /* void set (in AString aName, in nsIVariant aValue); */
  NS_SCRIPTABLE NS_IMETHOD Set(const nsAString & aName, nsIVariant *aValue) = 0;

  /**
   * Gets the value of a storage item with the given name. Returns a
   * default value if the item does not exist.
   * @param   aName
   *          The name of an item
   * @param   aDefaultValue
   *          The value to return if no item exists with the given name
   * @returns value of the item or the given default value if no item
   *          exists with the given name.
   */
  /* nsIVariant get (in AString aName, in nsIVariant aDefaultValue); */
  NS_SCRIPTABLE NS_IMETHOD Get(const nsAString & aName, nsIVariant *aDefaultValue, nsIVariant **_retval NS_OUTPARAM) = 0;

};

  NS_DEFINE_STATIC_IID_ACCESSOR(extISessionStorage, EXTISESSIONSTORAGE_IID)

/* Use this macro when declaring classes that implement this interface. */
#define NS_DECL_EXTISESSIONSTORAGE \
  NS_SCRIPTABLE NS_IMETHOD GetEvents(extIEvents * *aEvents); \
  NS_SCRIPTABLE NS_IMETHOD Has(const nsAString & aName, PRBool *_retval NS_OUTPARAM); \
  NS_SCRIPTABLE NS_IMETHOD Set(const nsAString & aName, nsIVariant *aValue); \
  NS_SCRIPTABLE NS_IMETHOD Get(const nsAString & aName, nsIVariant *aDefaultValue, nsIVariant **_retval NS_OUTPARAM); 

/* Use this macro to declare functions that forward the behavior of this interface to another object. */
#define NS_FORWARD_EXTISESSIONSTORAGE(_to) \
  NS_SCRIPTABLE NS_IMETHOD GetEvents(extIEvents * *aEvents) { return _to GetEvents(aEvents); } \
  NS_SCRIPTABLE NS_IMETHOD Has(const nsAString & aName, PRBool *_retval NS_OUTPARAM) { return _to Has(aName, _retval); } \
  NS_SCRIPTABLE NS_IMETHOD Set(const nsAString & aName, nsIVariant *aValue) { return _to Set(aName, aValue); } \
  NS_SCRIPTABLE NS_IMETHOD Get(const nsAString & aName, nsIVariant *aDefaultValue, nsIVariant **_retval NS_OUTPARAM) { return _to Get(aName, aDefaultValue, _retval); } 

/* Use this macro to declare functions that forward the behavior of this interface to another object in a safe way. */
#define NS_FORWARD_SAFE_EXTISESSIONSTORAGE(_to) \
  NS_SCRIPTABLE NS_IMETHOD GetEvents(extIEvents * *aEvents) { return !_to ? NS_ERROR_NULL_POINTER : _to->GetEvents(aEvents); } \
  NS_SCRIPTABLE NS_IMETHOD Has(const nsAString & aName, PRBool *_retval NS_OUTPARAM) { return !_to ? NS_ERROR_NULL_POINTER : _to->Has(aName, _retval); } \
  NS_SCRIPTABLE NS_IMETHOD Set(const nsAString & aName, nsIVariant *aValue) { return !_to ? NS_ERROR_NULL_POINTER : _to->Set(aName, aValue); } \
  NS_SCRIPTABLE NS_IMETHOD Get(const nsAString & aName, nsIVariant *aDefaultValue, nsIVariant **_retval NS_OUTPARAM) { return !_to ? NS_ERROR_NULL_POINTER : _to->Get(aName, aDefaultValue, _retval); } 

#if 0
/* Use the code below as a template for the implementation class for this interface. */

/* Header file */
class _MYCLASS_ : public extISessionStorage
{
public:
  NS_DECL_ISUPPORTS
  NS_DECL_EXTISESSIONSTORAGE

  _MYCLASS_();

private:
  ~_MYCLASS_();

protected:
  /* additional members */
};

/* Implementation file */
NS_IMPL_ISUPPORTS1(_MYCLASS_, extISessionStorage)

_MYCLASS_::_MYCLASS_()
{
  /* member initializers and constructor code */
}

_MYCLASS_::~_MYCLASS_()
{
  /* destructor code */
}

/* readonly attribute extIEvents events; */
NS_IMETHODIMP _MYCLASS_::GetEvents(extIEvents * *aEvents)
{
    return NS_ERROR_NOT_IMPLEMENTED;
}

/* boolean has (in AString aName); */
NS_IMETHODIMP _MYCLASS_::Has(const nsAString & aName, PRBool *_retval NS_OUTPARAM)
{
    return NS_ERROR_NOT_IMPLEMENTED;
}

/* void set (in AString aName, in nsIVariant aValue); */
NS_IMETHODIMP _MYCLASS_::Set(const nsAString & aName, nsIVariant *aValue)
{
    return NS_ERROR_NOT_IMPLEMENTED;
}

/* nsIVariant get (in AString aName, in nsIVariant aDefaultValue); */
NS_IMETHODIMP _MYCLASS_::Get(const nsAString & aName, nsIVariant *aDefaultValue, nsIVariant **_retval NS_OUTPARAM)
{
    return NS_ERROR_NOT_IMPLEMENTED;
}

/* End of implementation class template. */
#endif


/* starting interface:    extIApplication */
#define EXTIAPPLICATION_IID_STR "e53d6610-7468-11dd-ad8b-0800200c9a66"

#define EXTIAPPLICATION_IID \
  {0xe53d6610, 0x7468, 0x11dd, \
    { 0xad, 0x8b, 0x08, 0x00, 0x20, 0x0c, 0x9a, 0x66 }}

class NS_NO_VTABLE NS_SCRIPTABLE extIApplication : public nsISupports {
 public: 

  NS_DECLARE_STATIC_IID_ACCESSOR(EXTIAPPLICATION_IID)

  /**
   * The id of the application.
   */
  /* readonly attribute AString id; */
  NS_SCRIPTABLE NS_IMETHOD GetId(nsAString & aId) = 0;

  /**
   * The name of the application.
   */
  /* readonly attribute AString name; */
  NS_SCRIPTABLE NS_IMETHOD GetName(nsAString & aName) = 0;

  /**
   * The version number of the application.
   */
  /* readonly attribute AString version; */
  NS_SCRIPTABLE NS_IMETHOD GetVersion(nsAString & aVersion) = 0;

  /**
   * The console object for the application.
   */
  /* readonly attribute extIConsole console; */
  NS_SCRIPTABLE NS_IMETHOD GetConsole(extIConsole * *aConsole) = 0;

  /**
   * The extensions object for the application. Contains a list
   * of all installed extensions.
   */
  /* readonly attribute extIExtensions extensions; */
  NS_SCRIPTABLE NS_IMETHOD GetExtensions(extIExtensions * *aExtensions) = 0;

  /**
   * The preferences object for the application. Defaults to an empty
   * root branch.
   */
  /* readonly attribute extIPreferenceBranch prefs; */
  NS_SCRIPTABLE NS_IMETHOD GetPrefs(extIPreferenceBranch * *aPrefs) = 0;

  /**
   * The storage object for the application.
   */
  /* readonly attribute extISessionStorage storage; */
  NS_SCRIPTABLE NS_IMETHOD GetStorage(extISessionStorage * *aStorage) = 0;

  /**
   * The events object for the application.
   * supports: "load", "ready", "quit", "unload"
   */
  /* readonly attribute extIEvents events; */
  NS_SCRIPTABLE NS_IMETHOD GetEvents(extIEvents * *aEvents) = 0;

  /**
   * Quits the application (if nobody objects to quit-application-requested).
   * @returns whether quitting will proceed
   */
  /* boolean quit (); */
  NS_SCRIPTABLE NS_IMETHOD Quit(PRBool *_retval NS_OUTPARAM) = 0;

  /**
   * Restarts the application (if nobody objects to quit-application-requested).
   * @returns whether restarting will proceed
   */
  /* boolean restart (); */
  NS_SCRIPTABLE NS_IMETHOD Restart(PRBool *_retval NS_OUTPARAM) = 0;

};

  NS_DEFINE_STATIC_IID_ACCESSOR(extIApplication, EXTIAPPLICATION_IID)

/* Use this macro when declaring classes that implement this interface. */
#define NS_DECL_EXTIAPPLICATION \
  NS_SCRIPTABLE NS_IMETHOD GetId(nsAString & aId); \
  NS_SCRIPTABLE NS_IMETHOD GetName(nsAString & aName); \
  NS_SCRIPTABLE NS_IMETHOD GetVersion(nsAString & aVersion); \
  NS_SCRIPTABLE NS_IMETHOD GetConsole(extIConsole * *aConsole); \
  NS_SCRIPTABLE NS_IMETHOD GetExtensions(extIExtensions * *aExtensions); \
  NS_SCRIPTABLE NS_IMETHOD GetPrefs(extIPreferenceBranch * *aPrefs); \
  NS_SCRIPTABLE NS_IMETHOD GetStorage(extISessionStorage * *aStorage); \
  NS_SCRIPTABLE NS_IMETHOD GetEvents(extIEvents * *aEvents); \
  NS_SCRIPTABLE NS_IMETHOD Quit(PRBool *_retval NS_OUTPARAM); \
  NS_SCRIPTABLE NS_IMETHOD Restart(PRBool *_retval NS_OUTPARAM); 

/* Use this macro to declare functions that forward the behavior of this interface to another object. */
#define NS_FORWARD_EXTIAPPLICATION(_to) \
  NS_SCRIPTABLE NS_IMETHOD GetId(nsAString & aId) { return _to GetId(aId); } \
  NS_SCRIPTABLE NS_IMETHOD GetName(nsAString & aName) { return _to GetName(aName); } \
  NS_SCRIPTABLE NS_IMETHOD GetVersion(nsAString & aVersion) { return _to GetVersion(aVersion); } \
  NS_SCRIPTABLE NS_IMETHOD GetConsole(extIConsole * *aConsole) { return _to GetConsole(aConsole); } \
  NS_SCRIPTABLE NS_IMETHOD GetExtensions(extIExtensions * *aExtensions) { return _to GetExtensions(aExtensions); } \
  NS_SCRIPTABLE NS_IMETHOD GetPrefs(extIPreferenceBranch * *aPrefs) { return _to GetPrefs(aPrefs); } \
  NS_SCRIPTABLE NS_IMETHOD GetStorage(extISessionStorage * *aStorage) { return _to GetStorage(aStorage); } \
  NS_SCRIPTABLE NS_IMETHOD GetEvents(extIEvents * *aEvents) { return _to GetEvents(aEvents); } \
  NS_SCRIPTABLE NS_IMETHOD Quit(PRBool *_retval NS_OUTPARAM) { return _to Quit(_retval); } \
  NS_SCRIPTABLE NS_IMETHOD Restart(PRBool *_retval NS_OUTPARAM) { return _to Restart(_retval); } 

/* Use this macro to declare functions that forward the behavior of this interface to another object in a safe way. */
#define NS_FORWARD_SAFE_EXTIAPPLICATION(_to) \
  NS_SCRIPTABLE NS_IMETHOD GetId(nsAString & aId) { return !_to ? NS_ERROR_NULL_POINTER : _to->GetId(aId); } \
  NS_SCRIPTABLE NS_IMETHOD GetName(nsAString & aName) { return !_to ? NS_ERROR_NULL_POINTER : _to->GetName(aName); } \
  NS_SCRIPTABLE NS_IMETHOD GetVersion(nsAString & aVersion) { return !_to ? NS_ERROR_NULL_POINTER : _to->GetVersion(aVersion); } \
  NS_SCRIPTABLE NS_IMETHOD GetConsole(extIConsole * *aConsole) { return !_to ? NS_ERROR_NULL_POINTER : _to->GetConsole(aConsole); } \
  NS_SCRIPTABLE NS_IMETHOD GetExtensions(extIExtensions * *aExtensions) { return !_to ? NS_ERROR_NULL_POINTER : _to->GetExtensions(aExtensions); } \
  NS_SCRIPTABLE NS_IMETHOD GetPrefs(extIPreferenceBranch * *aPrefs) { return !_to ? NS_ERROR_NULL_POINTER : _to->GetPrefs(aPrefs); } \
  NS_SCRIPTABLE NS_IMETHOD GetStorage(extISessionStorage * *aStorage) { return !_to ? NS_ERROR_NULL_POINTER : _to->GetStorage(aStorage); } \
  NS_SCRIPTABLE NS_IMETHOD GetEvents(extIEvents * *aEvents) { return !_to ? NS_ERROR_NULL_POINTER : _to->GetEvents(aEvents); } \
  NS_SCRIPTABLE NS_IMETHOD Quit(PRBool *_retval NS_OUTPARAM) { return !_to ? NS_ERROR_NULL_POINTER : _to->Quit(_retval); } \
  NS_SCRIPTABLE NS_IMETHOD Restart(PRBool *_retval NS_OUTPARAM) { return !_to ? NS_ERROR_NULL_POINTER : _to->Restart(_retval); } 

#if 0
/* Use the code below as a template for the implementation class for this interface. */

/* Header file */
class _MYCLASS_ : public extIApplication
{
public:
  NS_DECL_ISUPPORTS
  NS_DECL_EXTIAPPLICATION

  _MYCLASS_();

private:
  ~_MYCLASS_();

protected:
  /* additional members */
};

/* Implementation file */
NS_IMPL_ISUPPORTS1(_MYCLASS_, extIApplication)

_MYCLASS_::_MYCLASS_()
{
  /* member initializers and constructor code */
}

_MYCLASS_::~_MYCLASS_()
{
  /* destructor code */
}

/* readonly attribute AString id; */
NS_IMETHODIMP _MYCLASS_::GetId(nsAString & aId)
{
    return NS_ERROR_NOT_IMPLEMENTED;
}

/* readonly attribute AString name; */
NS_IMETHODIMP _MYCLASS_::GetName(nsAString & aName)
{
    return NS_ERROR_NOT_IMPLEMENTED;
}

/* readonly attribute AString version; */
NS_IMETHODIMP _MYCLASS_::GetVersion(nsAString & aVersion)
{
    return NS_ERROR_NOT_IMPLEMENTED;
}

/* readonly attribute extIConsole console; */
NS_IMETHODIMP _MYCLASS_::GetConsole(extIConsole * *aConsole)
{
    return NS_ERROR_NOT_IMPLEMENTED;
}

/* readonly attribute extIExtensions extensions; */
NS_IMETHODIMP _MYCLASS_::GetExtensions(extIExtensions * *aExtensions)
{
    return NS_ERROR_NOT_IMPLEMENTED;
}

/* readonly attribute extIPreferenceBranch prefs; */
NS_IMETHODIMP _MYCLASS_::GetPrefs(extIPreferenceBranch * *aPrefs)
{
    return NS_ERROR_NOT_IMPLEMENTED;
}

/* readonly attribute extISessionStorage storage; */
NS_IMETHODIMP _MYCLASS_::GetStorage(extISessionStorage * *aStorage)
{
    return NS_ERROR_NOT_IMPLEMENTED;
}

/* readonly attribute extIEvents events; */
NS_IMETHODIMP _MYCLASS_::GetEvents(extIEvents * *aEvents)
{
    return NS_ERROR_NOT_IMPLEMENTED;
}

/* boolean quit (); */
NS_IMETHODIMP _MYCLASS_::Quit(PRBool *_retval NS_OUTPARAM)
{
    return NS_ERROR_NOT_IMPLEMENTED;
}

/* boolean restart (); */
NS_IMETHODIMP _MYCLASS_::Restart(PRBool *_retval NS_OUTPARAM)
{
    return NS_ERROR_NOT_IMPLEMENTED;
}

/* End of implementation class template. */
#endif


#endif /* __gen_extIApplication_h__ */
