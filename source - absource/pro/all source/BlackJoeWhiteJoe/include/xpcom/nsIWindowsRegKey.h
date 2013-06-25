/*
 * DO NOT EDIT.  THIS FILE IS GENERATED FROM e:/builds/moz2_slave/mozilla-1.9.1-win32-xulrunner/build/xpcom/ds/nsIWindowsRegKey.idl
 */

#ifndef __gen_nsIWindowsRegKey_h__
#define __gen_nsIWindowsRegKey_h__


#ifndef __gen_nsISupports_h__
#include "nsISupports.h"
#endif

/* For IDL files that don't want to include root IDL files. */
#ifndef NS_NO_VTABLE
#define NS_NO_VTABLE
#endif

/* starting interface:    nsIWindowsRegKey */
#define NS_IWINDOWSREGKEY_IID_STR "2555b930-d64f-437e-9be7-0a2cb252c1f4"

#define NS_IWINDOWSREGKEY_IID \
  {0x2555b930, 0xd64f, 0x437e, \
    { 0x9b, 0xe7, 0x0a, 0x2c, 0xb2, 0x52, 0xc1, 0xf4 }}

/**
 * This interface is designed to provide scriptable access to the Windows
 * registry system ("With Great Power Comes Great Responsibility").  The
 * interface represents a single key in the registry.
 *
 * This interface is highly Win32 specific.
 */
class NS_NO_VTABLE NS_SCRIPTABLE nsIWindowsRegKey : public nsISupports {
 public: 

  NS_DECLARE_STATIC_IID_ACCESSOR(NS_IWINDOWSREGKEY_IID)

  /**
   * Root keys.  The values for these keys correspond to the values from
   * WinReg.h in the MS Platform SDK.  The ROOT_KEY_ prefix corresponds to the
   * HKEY_ prefix in the MS Platform SDK.
   *
   * This interface is not restricted to using only these root keys.
   */
  enum { ROOT_KEY_CLASSES_ROOT = 2147483648U };

  enum { ROOT_KEY_CURRENT_USER = 2147483649U };

  enum { ROOT_KEY_LOCAL_MACHINE = 2147483650U };

  /**
   * Values for the mode parameter passed to the open and create methods.
   * The values defined here correspond to the REGSAM values defined in
   * WinNT.h in the MS Platform SDK, where ACCESS_ is replaced with KEY_.
   *
   * This interface is not restricted to using only these access types.
   */
  enum { ACCESS_BASIC = 131072U };

  enum { ACCESS_QUERY_VALUE = 1U };

  enum { ACCESS_SET_VALUE = 2U };

  enum { ACCESS_CREATE_SUB_KEY = 4U };

  enum { ACCESS_ENUMERATE_SUB_KEYS = 8U };

  enum { ACCESS_NOTIFY = 16U };

  enum { ACCESS_READ = 131097U };

  enum { ACCESS_WRITE = 131078U };

  enum { ACCESS_ALL = 131103U };

  /**
   * Values for the type of a registry value.  The numeric values of these
   * constants are taken directly from WinNT.h in the MS Platform SDK.
   * The Microsoft documentation should be consulted for the exact meaning of
   * these value types.
   *
   * This interface is somewhat restricted to using only these value types.
   * There is no method that is directly equivalent to RegQueryValueEx or
   * RegSetValueEx.  In particular, this interface does not support the
   * REG_MULTI_SZ and REG_EXPAND_SZ value types.  It is still possible to
   * enumerate values that have other types (i.e., getValueType may return a
   * type not defined below).
   */
  enum { TYPE_NONE = 0U };

  enum { TYPE_STRING = 1U };

  enum { TYPE_BINARY = 3U };

  enum { TYPE_INT = 4U };

  enum { TYPE_INT64 = 11U };

  /**
   * This attribute exposes the native HKEY and is available to provide C++
   * consumers with the flexibility of making other Windows registry API calls
   * that are not exposed via this interface.
   * 
   * It is possible to initialize this object by setting an HKEY on it.  In
   * that case, it is the responsibility of the consumer setting the HKEY to
   * ensure that it is a valid HKEY.
   *
   * WARNING: Setting the key does not close the old key.
   */
  /* [noscript] attribute HKEY key; */
  NS_IMETHOD GetKey(HKEY *aKey) = 0;
  NS_IMETHOD SetKey(HKEY aKey) = 0;

  /**
   * This method closes the key.  If the key is already closed, then this
   * method does nothing.
   */
  /* void close (); */
  NS_SCRIPTABLE NS_IMETHOD Close(void) = 0;

  /**
   * This method opens an existing key.  This method fails if the key
   * does not exist.
   *
   * NOTE: On 32-bit Windows, it is valid to pass any HKEY as the rootKey
   * parameter of this function.  However, for compatibility with 64-bit
   * Windows, that usage should probably be avoided in favor of openChild.
   *
   * @param rootKey
   *        A root key defined above or any valid HKEY on 32-bit Windows.
   * @param relPath
   *        A relative path from the given root key.
   * @param mode
   *        Access mode, which is a bit-wise OR of the ACCESS_ values defined
   *        above.
   */
  /* void open (in unsigned long rootKey, in AString relPath, in unsigned long mode); */
  NS_SCRIPTABLE NS_IMETHOD Open(PRUint32 rootKey, const nsAString & relPath, PRUint32 mode) = 0;

  /**
   * This method opens an existing key or creates a new key.
   *
   * NOTE: On 32-bit Windows, it is valid to pass any HKEY as the rootKey
   * parameter of this function.  However, for compatibility with 64-bit
   * Windows, that usage should probably be avoided in favor of createChild.
   *
   * @param rootKey
   *        A root key defined above or any valid HKEY on 32-bit Windows.
   * @param relPath
   *        A relative path from the given root key.
   * @param mode
   *        Access mode, which is a bit-wise OR of the ACCESS_ values defined
   *        above.
   */
  /* void create (in unsigned long rootKey, in AString relPath, in unsigned long mode); */
  NS_SCRIPTABLE NS_IMETHOD Create(PRUint32 rootKey, const nsAString & relPath, PRUint32 mode) = 0;

  /**
   * This method opens a subkey relative to this key.  This method fails if the
   * key does not exist.
   *
   * @return nsIWindowsRegKey for the newly opened subkey.
   */
  /* nsIWindowsRegKey openChild (in AString relPath, in unsigned long mode); */
  NS_SCRIPTABLE NS_IMETHOD OpenChild(const nsAString & relPath, PRUint32 mode, nsIWindowsRegKey **_retval NS_OUTPARAM) = 0;

  /**
   * This method opens or creates a subkey relative to this key.
   *
   * @return nsIWindowsRegKey for the newly opened or created subkey.
   */
  /* nsIWindowsRegKey createChild (in AString relPath, in unsigned long mode); */
  NS_SCRIPTABLE NS_IMETHOD CreateChild(const nsAString & relPath, PRUint32 mode, nsIWindowsRegKey **_retval NS_OUTPARAM) = 0;

  /**
   * This attribute returns the number of child keys.
   */
  /* readonly attribute unsigned long childCount; */
  NS_SCRIPTABLE NS_IMETHOD GetChildCount(PRUint32 *aChildCount) = 0;

  /**
   * This method returns the name of the n'th child key.
   *
   * @param index
   *        The index of the requested child key.
   */
  /* AString getChildName (in unsigned long index); */
  NS_SCRIPTABLE NS_IMETHOD GetChildName(PRUint32 index, nsAString & _retval NS_OUTPARAM) = 0;

  /**
   * This method checks to see if the key has a child by the given name.
   *
   * @param name
   *        The name of the requested child key.
   */
  /* boolean hasChild (in AString name); */
  NS_SCRIPTABLE NS_IMETHOD HasChild(const nsAString & name, PRBool *_retval NS_OUTPARAM) = 0;

  /**
   * This attribute returns the number of values under this key.
   */
  /* readonly attribute unsigned long valueCount; */
  NS_SCRIPTABLE NS_IMETHOD GetValueCount(PRUint32 *aValueCount) = 0;

  /**
   * This method returns the name of the n'th value under this key.
   *
   * @param index
   *        The index of the requested value.
   */
  /* AString getValueName (in unsigned long index); */
  NS_SCRIPTABLE NS_IMETHOD GetValueName(PRUint32 index, nsAString & _retval NS_OUTPARAM) = 0;

  /**
   * This method checks to see if the key has a value by the given name.
   *
   * @param name
   *        The name of the requested value.
   */
  /* boolean hasValue (in AString name); */
  NS_SCRIPTABLE NS_IMETHOD HasValue(const nsAString & name, PRBool *_retval NS_OUTPARAM) = 0;

  /**
   * This method removes a child key and all of its values.  This method will
   * fail if the key has any children of its own. 
   *
   * @param relPath
   *        The relative path from this key to the key to be removed.
   */
  /* void removeChild (in AString relPath); */
  NS_SCRIPTABLE NS_IMETHOD RemoveChild(const nsAString & relPath) = 0;

  /**
   * This method removes the value with the given name.
   *
   * @param name
   *        The name of the value to be removed.
   */
  /* void removeValue (in AString name); */
  NS_SCRIPTABLE NS_IMETHOD RemoveValue(const nsAString & name) = 0;

  /**
   * This method returns the type of the value with the given name.  The return
   * value is one of the "TYPE_" constants defined above.
   *
   * @param name
   *        The name of the value to query.
   */
  /* unsigned long getValueType (in AString name); */
  NS_SCRIPTABLE NS_IMETHOD GetValueType(const nsAString & name, PRUint32 *_retval NS_OUTPARAM) = 0;

  /**
   * This method reads the string contents of the named value as a Unicode
   * string.
   *
   * @param name
   *        The name of the value to query.  This parameter can be the empty
   *        string to request the key's default value.
   */
  /* AString readStringValue (in AString name); */
  NS_SCRIPTABLE NS_IMETHOD ReadStringValue(const nsAString & name, nsAString & _retval NS_OUTPARAM) = 0;

  /**
   * This method reads the integer contents of the named value.
   *
   * @param name
   *        The name of the value to query.
   */
  /* unsigned long readIntValue (in AString name); */
  NS_SCRIPTABLE NS_IMETHOD ReadIntValue(const nsAString & name, PRUint32 *_retval NS_OUTPARAM) = 0;

  /**
   * This method reads the 64-bit integer contents of the named value.
   *
   * @param name
   *        The name of the value to query.
   */
  /* unsigned long long readInt64Value (in AString name); */
  NS_SCRIPTABLE NS_IMETHOD ReadInt64Value(const nsAString & name, PRUint64 *_retval NS_OUTPARAM) = 0;

  /**
   * This method reads the binary contents of the named value under this key.
   *
   * JavaScript callers should take care with the result of this method since
   * it will be byte-expanded to form a JS string.  (The binary data will be
   * treated as an ISO-Latin-1 character string, which it is not).
   *
   * @param name
   *        The name of the value to query.
   */
  /* ACString readBinaryValue (in AString name); */
  NS_SCRIPTABLE NS_IMETHOD ReadBinaryValue(const nsAString & name, nsACString & _retval NS_OUTPARAM) = 0;

  /**
   * This method writes the unicode string contents of the named value.  The
   * value will be created if it does not already exist.
   *
   * @param name
   *        The name of the value to modify.  This parameter can be the empty
   *        string to modify the key's default value.
   * @param data
   *        The data for the value to modify.
   */
  /* void writeStringValue (in AString name, in AString data); */
  NS_SCRIPTABLE NS_IMETHOD WriteStringValue(const nsAString & name, const nsAString & data) = 0;

  /**
   * This method writes the integer contents of the named value.  The value
   * will be created if it does not already exist.
   *
   * @param name
   *        The name of the value to modify.
   * @param data
   *        The data for the value to modify.
   */
  /* void writeIntValue (in AString name, in unsigned long data); */
  NS_SCRIPTABLE NS_IMETHOD WriteIntValue(const nsAString & name, PRUint32 data) = 0;

  /**
   * This method writes the 64-bit integer contents of the named value.  The
   * value will be created if it does not already exist.
   *
   * @param name
   *        The name of the value to modify.
   * @param data
   *        The data for the value to modify.
   */
  /* void writeInt64Value (in AString name, in unsigned long long data); */
  NS_SCRIPTABLE NS_IMETHOD WriteInt64Value(const nsAString & name, PRUint64 data) = 0;

  /**
   * This method writes the binary contents of the named value.  The value will
   * be created if it does not already exist.
   * 
   * JavaScript callers should take care with the value passed to this method
   * since it will be truncated from a JS string (unicode) to a ISO-Latin-1
   * string.  (The binary data will be treated as an ISO-Latin-1 character
   * string, which it is not).  So, JavaScript callers should only pass
   * character values in the range \u0000 to \u00FF, or else data loss will
   * occur.
   *
   * @param name
   *        The name of the value to modify.
   * @param data
   *        The data for the value to modify.
   */
  /* void writeBinaryValue (in AString name, in ACString data); */
  NS_SCRIPTABLE NS_IMETHOD WriteBinaryValue(const nsAString & name, const nsACString & data) = 0;

  /**
   * This method starts watching the key to see if any of its values have
   * changed.  The key must have been opened with mode including ACCESS_NOTIFY.
   * If recurse is true, then this key and any of its descendant keys are
   * watched.  Otherwise, only this key is watched.
   *
   * @param recurse
   *        Indicates whether or not to also watch child keys.
   */
  /* void startWatching (in boolean recurse); */
  NS_SCRIPTABLE NS_IMETHOD StartWatching(PRBool recurse) = 0;

  /**
   * This method stops any watching of the key initiated by a call to
   * startWatching.  This method does nothing if the key is not being watched.
   */
  /* void stopWatching (); */
  NS_SCRIPTABLE NS_IMETHOD StopWatching(void) = 0;

  /**
   * This method returns true if the key is being watched for changes (i.e.,
   * if startWatching() was called).
   */
  /* boolean isWatching (); */
  NS_SCRIPTABLE NS_IMETHOD IsWatching(PRBool *_retval NS_OUTPARAM) = 0;

  /**
   * This method returns true if the key has changed and false otherwise.
   * This method will always return false if startWatching was not called.
   */
  /* boolean hasChanged (); */
  NS_SCRIPTABLE NS_IMETHOD HasChanged(PRBool *_retval NS_OUTPARAM) = 0;

};

  NS_DEFINE_STATIC_IID_ACCESSOR(nsIWindowsRegKey, NS_IWINDOWSREGKEY_IID)

/* Use this macro when declaring classes that implement this interface. */
#define NS_DECL_NSIWINDOWSREGKEY \
  NS_IMETHOD GetKey(HKEY *aKey); \
  NS_IMETHOD SetKey(HKEY aKey); \
  NS_SCRIPTABLE NS_IMETHOD Close(void); \
  NS_SCRIPTABLE NS_IMETHOD Open(PRUint32 rootKey, const nsAString & relPath, PRUint32 mode); \
  NS_SCRIPTABLE NS_IMETHOD Create(PRUint32 rootKey, const nsAString & relPath, PRUint32 mode); \
  NS_SCRIPTABLE NS_IMETHOD OpenChild(const nsAString & relPath, PRUint32 mode, nsIWindowsRegKey **_retval NS_OUTPARAM); \
  NS_SCRIPTABLE NS_IMETHOD CreateChild(const nsAString & relPath, PRUint32 mode, nsIWindowsRegKey **_retval NS_OUTPARAM); \
  NS_SCRIPTABLE NS_IMETHOD GetChildCount(PRUint32 *aChildCount); \
  NS_SCRIPTABLE NS_IMETHOD GetChildName(PRUint32 index, nsAString & _retval NS_OUTPARAM); \
  NS_SCRIPTABLE NS_IMETHOD HasChild(const nsAString & name, PRBool *_retval NS_OUTPARAM); \
  NS_SCRIPTABLE NS_IMETHOD GetValueCount(PRUint32 *aValueCount); \
  NS_SCRIPTABLE NS_IMETHOD GetValueName(PRUint32 index, nsAString & _retval NS_OUTPARAM); \
  NS_SCRIPTABLE NS_IMETHOD HasValue(const nsAString & name, PRBool *_retval NS_OUTPARAM); \
  NS_SCRIPTABLE NS_IMETHOD RemoveChild(const nsAString & relPath); \
  NS_SCRIPTABLE NS_IMETHOD RemoveValue(const nsAString & name); \
  NS_SCRIPTABLE NS_IMETHOD GetValueType(const nsAString & name, PRUint32 *_retval NS_OUTPARAM); \
  NS_SCRIPTABLE NS_IMETHOD ReadStringValue(const nsAString & name, nsAString & _retval NS_OUTPARAM); \
  NS_SCRIPTABLE NS_IMETHOD ReadIntValue(const nsAString & name, PRUint32 *_retval NS_OUTPARAM); \
  NS_SCRIPTABLE NS_IMETHOD ReadInt64Value(const nsAString & name, PRUint64 *_retval NS_OUTPARAM); \
  NS_SCRIPTABLE NS_IMETHOD ReadBinaryValue(const nsAString & name, nsACString & _retval NS_OUTPARAM); \
  NS_SCRIPTABLE NS_IMETHOD WriteStringValue(const nsAString & name, const nsAString & data); \
  NS_SCRIPTABLE NS_IMETHOD WriteIntValue(const nsAString & name, PRUint32 data); \
  NS_SCRIPTABLE NS_IMETHOD WriteInt64Value(const nsAString & name, PRUint64 data); \
  NS_SCRIPTABLE NS_IMETHOD WriteBinaryValue(const nsAString & name, const nsACString & data); \
  NS_SCRIPTABLE NS_IMETHOD StartWatching(PRBool recurse); \
  NS_SCRIPTABLE NS_IMETHOD StopWatching(void); \
  NS_SCRIPTABLE NS_IMETHOD IsWatching(PRBool *_retval NS_OUTPARAM); \
  NS_SCRIPTABLE NS_IMETHOD HasChanged(PRBool *_retval NS_OUTPARAM); 

/* Use this macro to declare functions that forward the behavior of this interface to another object. */
#define NS_FORWARD_NSIWINDOWSREGKEY(_to) \
  NS_IMETHOD GetKey(HKEY *aKey) { return _to GetKey(aKey); } \
  NS_IMETHOD SetKey(HKEY aKey) { return _to SetKey(aKey); } \
  NS_SCRIPTABLE NS_IMETHOD Close(void) { return _to Close(); } \
  NS_SCRIPTABLE NS_IMETHOD Open(PRUint32 rootKey, const nsAString & relPath, PRUint32 mode) { return _to Open(rootKey, relPath, mode); } \
  NS_SCRIPTABLE NS_IMETHOD Create(PRUint32 rootKey, const nsAString & relPath, PRUint32 mode) { return _to Create(rootKey, relPath, mode); } \
  NS_SCRIPTABLE NS_IMETHOD OpenChild(const nsAString & relPath, PRUint32 mode, nsIWindowsRegKey **_retval NS_OUTPARAM) { return _to OpenChild(relPath, mode, _retval); } \
  NS_SCRIPTABLE NS_IMETHOD CreateChild(const nsAString & relPath, PRUint32 mode, nsIWindowsRegKey **_retval NS_OUTPARAM) { return _to CreateChild(relPath, mode, _retval); } \
  NS_SCRIPTABLE NS_IMETHOD GetChildCount(PRUint32 *aChildCount) { return _to GetChildCount(aChildCount); } \
  NS_SCRIPTABLE NS_IMETHOD GetChildName(PRUint32 index, nsAString & _retval NS_OUTPARAM) { return _to GetChildName(index, _retval); } \
  NS_SCRIPTABLE NS_IMETHOD HasChild(const nsAString & name, PRBool *_retval NS_OUTPARAM) { return _to HasChild(name, _retval); } \
  NS_SCRIPTABLE NS_IMETHOD GetValueCount(PRUint32 *aValueCount) { return _to GetValueCount(aValueCount); } \
  NS_SCRIPTABLE NS_IMETHOD GetValueName(PRUint32 index, nsAString & _retval NS_OUTPARAM) { return _to GetValueName(index, _retval); } \
  NS_SCRIPTABLE NS_IMETHOD HasValue(const nsAString & name, PRBool *_retval NS_OUTPARAM) { return _to HasValue(name, _retval); } \
  NS_SCRIPTABLE NS_IMETHOD RemoveChild(const nsAString & relPath) { return _to RemoveChild(relPath); } \
  NS_SCRIPTABLE NS_IMETHOD RemoveValue(const nsAString & name) { return _to RemoveValue(name); } \
  NS_SCRIPTABLE NS_IMETHOD GetValueType(const nsAString & name, PRUint32 *_retval NS_OUTPARAM) { return _to GetValueType(name, _retval); } \
  NS_SCRIPTABLE NS_IMETHOD ReadStringValue(const nsAString & name, nsAString & _retval NS_OUTPARAM) { return _to ReadStringValue(name, _retval); } \
  NS_SCRIPTABLE NS_IMETHOD ReadIntValue(const nsAString & name, PRUint32 *_retval NS_OUTPARAM) { return _to ReadIntValue(name, _retval); } \
  NS_SCRIPTABLE NS_IMETHOD ReadInt64Value(const nsAString & name, PRUint64 *_retval NS_OUTPARAM) { return _to ReadInt64Value(name, _retval); } \
  NS_SCRIPTABLE NS_IMETHOD ReadBinaryValue(const nsAString & name, nsACString & _retval NS_OUTPARAM) { return _to ReadBinaryValue(name, _retval); } \
  NS_SCRIPTABLE NS_IMETHOD WriteStringValue(const nsAString & name, const nsAString & data) { return _to WriteStringValue(name, data); } \
  NS_SCRIPTABLE NS_IMETHOD WriteIntValue(const nsAString & name, PRUint32 data) { return _to WriteIntValue(name, data); } \
  NS_SCRIPTABLE NS_IMETHOD WriteInt64Value(const nsAString & name, PRUint64 data) { return _to WriteInt64Value(name, data); } \
  NS_SCRIPTABLE NS_IMETHOD WriteBinaryValue(const nsAString & name, const nsACString & data) { return _to WriteBinaryValue(name, data); } \
  NS_SCRIPTABLE NS_IMETHOD StartWatching(PRBool recurse) { return _to StartWatching(recurse); } \
  NS_SCRIPTABLE NS_IMETHOD StopWatching(void) { return _to StopWatching(); } \
  NS_SCRIPTABLE NS_IMETHOD IsWatching(PRBool *_retval NS_OUTPARAM) { return _to IsWatching(_retval); } \
  NS_SCRIPTABLE NS_IMETHOD HasChanged(PRBool *_retval NS_OUTPARAM) { return _to HasChanged(_retval); } 

/* Use this macro to declare functions that forward the behavior of this interface to another object in a safe way. */
#define NS_FORWARD_SAFE_NSIWINDOWSREGKEY(_to) \
  NS_IMETHOD GetKey(HKEY *aKey) { return !_to ? NS_ERROR_NULL_POINTER : _to->GetKey(aKey); } \
  NS_IMETHOD SetKey(HKEY aKey) { return !_to ? NS_ERROR_NULL_POINTER : _to->SetKey(aKey); } \
  NS_SCRIPTABLE NS_IMETHOD Close(void) { return !_to ? NS_ERROR_NULL_POINTER : _to->Close(); } \
  NS_SCRIPTABLE NS_IMETHOD Open(PRUint32 rootKey, const nsAString & relPath, PRUint32 mode) { return !_to ? NS_ERROR_NULL_POINTER : _to->Open(rootKey, relPath, mode); } \
  NS_SCRIPTABLE NS_IMETHOD Create(PRUint32 rootKey, const nsAString & relPath, PRUint32 mode) { return !_to ? NS_ERROR_NULL_POINTER : _to->Create(rootKey, relPath, mode); } \
  NS_SCRIPTABLE NS_IMETHOD OpenChild(const nsAString & relPath, PRUint32 mode, nsIWindowsRegKey **_retval NS_OUTPARAM) { return !_to ? NS_ERROR_NULL_POINTER : _to->OpenChild(relPath, mode, _retval); } \
  NS_SCRIPTABLE NS_IMETHOD CreateChild(const nsAString & relPath, PRUint32 mode, nsIWindowsRegKey **_retval NS_OUTPARAM) { return !_to ? NS_ERROR_NULL_POINTER : _to->CreateChild(relPath, mode, _retval); } \
  NS_SCRIPTABLE NS_IMETHOD GetChildCount(PRUint32 *aChildCount) { return !_to ? NS_ERROR_NULL_POINTER : _to->GetChildCount(aChildCount); } \
  NS_SCRIPTABLE NS_IMETHOD GetChildName(PRUint32 index, nsAString & _retval NS_OUTPARAM) { return !_to ? NS_ERROR_NULL_POINTER : _to->GetChildName(index, _retval); } \
  NS_SCRIPTABLE NS_IMETHOD HasChild(const nsAString & name, PRBool *_retval NS_OUTPARAM) { return !_to ? NS_ERROR_NULL_POINTER : _to->HasChild(name, _retval); } \
  NS_SCRIPTABLE NS_IMETHOD GetValueCount(PRUint32 *aValueCount) { return !_to ? NS_ERROR_NULL_POINTER : _to->GetValueCount(aValueCount); } \
  NS_SCRIPTABLE NS_IMETHOD GetValueName(PRUint32 index, nsAString & _retval NS_OUTPARAM) { return !_to ? NS_ERROR_NULL_POINTER : _to->GetValueName(index, _retval); } \
  NS_SCRIPTABLE NS_IMETHOD HasValue(const nsAString & name, PRBool *_retval NS_OUTPARAM) { return !_to ? NS_ERROR_NULL_POINTER : _to->HasValue(name, _retval); } \
  NS_SCRIPTABLE NS_IMETHOD RemoveChild(const nsAString & relPath) { return !_to ? NS_ERROR_NULL_POINTER : _to->RemoveChild(relPath); } \
  NS_SCRIPTABLE NS_IMETHOD RemoveValue(const nsAString & name) { return !_to ? NS_ERROR_NULL_POINTER : _to->RemoveValue(name); } \
  NS_SCRIPTABLE NS_IMETHOD GetValueType(const nsAString & name, PRUint32 *_retval NS_OUTPARAM) { return !_to ? NS_ERROR_NULL_POINTER : _to->GetValueType(name, _retval); } \
  NS_SCRIPTABLE NS_IMETHOD ReadStringValue(const nsAString & name, nsAString & _retval NS_OUTPARAM) { return !_to ? NS_ERROR_NULL_POINTER : _to->ReadStringValue(name, _retval); } \
  NS_SCRIPTABLE NS_IMETHOD ReadIntValue(const nsAString & name, PRUint32 *_retval NS_OUTPARAM) { return !_to ? NS_ERROR_NULL_POINTER : _to->ReadIntValue(name, _retval); } \
  NS_SCRIPTABLE NS_IMETHOD ReadInt64Value(const nsAString & name, PRUint64 *_retval NS_OUTPARAM) { return !_to ? NS_ERROR_NULL_POINTER : _to->ReadInt64Value(name, _retval); } \
  NS_SCRIPTABLE NS_IMETHOD ReadBinaryValue(const nsAString & name, nsACString & _retval NS_OUTPARAM) { return !_to ? NS_ERROR_NULL_POINTER : _to->ReadBinaryValue(name, _retval); } \
  NS_SCRIPTABLE NS_IMETHOD WriteStringValue(const nsAString & name, const nsAString & data) { return !_to ? NS_ERROR_NULL_POINTER : _to->WriteStringValue(name, data); } \
  NS_SCRIPTABLE NS_IMETHOD WriteIntValue(const nsAString & name, PRUint32 data) { return !_to ? NS_ERROR_NULL_POINTER : _to->WriteIntValue(name, data); } \
  NS_SCRIPTABLE NS_IMETHOD WriteInt64Value(const nsAString & name, PRUint64 data) { return !_to ? NS_ERROR_NULL_POINTER : _to->WriteInt64Value(name, data); } \
  NS_SCRIPTABLE NS_IMETHOD WriteBinaryValue(const nsAString & name, const nsACString & data) { return !_to ? NS_ERROR_NULL_POINTER : _to->WriteBinaryValue(name, data); } \
  NS_SCRIPTABLE NS_IMETHOD StartWatching(PRBool recurse) { return !_to ? NS_ERROR_NULL_POINTER : _to->StartWatching(recurse); } \
  NS_SCRIPTABLE NS_IMETHOD StopWatching(void) { return !_to ? NS_ERROR_NULL_POINTER : _to->StopWatching(); } \
  NS_SCRIPTABLE NS_IMETHOD IsWatching(PRBool *_retval NS_OUTPARAM) { return !_to ? NS_ERROR_NULL_POINTER : _to->IsWatching(_retval); } \
  NS_SCRIPTABLE NS_IMETHOD HasChanged(PRBool *_retval NS_OUTPARAM) { return !_to ? NS_ERROR_NULL_POINTER : _to->HasChanged(_retval); } 

#if 0
/* Use the code below as a template for the implementation class for this interface. */

/* Header file */
class nsWindowsRegKey : public nsIWindowsRegKey
{
public:
  NS_DECL_ISUPPORTS
  NS_DECL_NSIWINDOWSREGKEY

  nsWindowsRegKey();

private:
  ~nsWindowsRegKey();

protected:
  /* additional members */
};

/* Implementation file */
NS_IMPL_ISUPPORTS1(nsWindowsRegKey, nsIWindowsRegKey)

nsWindowsRegKey::nsWindowsRegKey()
{
  /* member initializers and constructor code */
}

nsWindowsRegKey::~nsWindowsRegKey()
{
  /* destructor code */
}

/* [noscript] attribute HKEY key; */
NS_IMETHODIMP nsWindowsRegKey::GetKey(HKEY *aKey)
{
    return NS_ERROR_NOT_IMPLEMENTED;
}
NS_IMETHODIMP nsWindowsRegKey::SetKey(HKEY aKey)
{
    return NS_ERROR_NOT_IMPLEMENTED;
}

/* void close (); */
NS_IMETHODIMP nsWindowsRegKey::Close()
{
    return NS_ERROR_NOT_IMPLEMENTED;
}

/* void open (in unsigned long rootKey, in AString relPath, in unsigned long mode); */
NS_IMETHODIMP nsWindowsRegKey::Open(PRUint32 rootKey, const nsAString & relPath, PRUint32 mode)
{
    return NS_ERROR_NOT_IMPLEMENTED;
}

/* void create (in unsigned long rootKey, in AString relPath, in unsigned long mode); */
NS_IMETHODIMP nsWindowsRegKey::Create(PRUint32 rootKey, const nsAString & relPath, PRUint32 mode)
{
    return NS_ERROR_NOT_IMPLEMENTED;
}

/* nsIWindowsRegKey openChild (in AString relPath, in unsigned long mode); */
NS_IMETHODIMP nsWindowsRegKey::OpenChild(const nsAString & relPath, PRUint32 mode, nsIWindowsRegKey **_retval NS_OUTPARAM)
{
    return NS_ERROR_NOT_IMPLEMENTED;
}

/* nsIWindowsRegKey createChild (in AString relPath, in unsigned long mode); */
NS_IMETHODIMP nsWindowsRegKey::CreateChild(const nsAString & relPath, PRUint32 mode, nsIWindowsRegKey **_retval NS_OUTPARAM)
{
    return NS_ERROR_NOT_IMPLEMENTED;
}

/* readonly attribute unsigned long childCount; */
NS_IMETHODIMP nsWindowsRegKey::GetChildCount(PRUint32 *aChildCount)
{
    return NS_ERROR_NOT_IMPLEMENTED;
}

/* AString getChildName (in unsigned long index); */
NS_IMETHODIMP nsWindowsRegKey::GetChildName(PRUint32 index, nsAString & _retval NS_OUTPARAM)
{
    return NS_ERROR_NOT_IMPLEMENTED;
}

/* boolean hasChild (in AString name); */
NS_IMETHODIMP nsWindowsRegKey::HasChild(const nsAString & name, PRBool *_retval NS_OUTPARAM)
{
    return NS_ERROR_NOT_IMPLEMENTED;
}

/* readonly attribute unsigned long valueCount; */
NS_IMETHODIMP nsWindowsRegKey::GetValueCount(PRUint32 *aValueCount)
{
    return NS_ERROR_NOT_IMPLEMENTED;
}

/* AString getValueName (in unsigned long index); */
NS_IMETHODIMP nsWindowsRegKey::GetValueName(PRUint32 index, nsAString & _retval NS_OUTPARAM)
{
    return NS_ERROR_NOT_IMPLEMENTED;
}

/* boolean hasValue (in AString name); */
NS_IMETHODIMP nsWindowsRegKey::HasValue(const nsAString & name, PRBool *_retval NS_OUTPARAM)
{
    return NS_ERROR_NOT_IMPLEMENTED;
}

/* void removeChild (in AString relPath); */
NS_IMETHODIMP nsWindowsRegKey::RemoveChild(const nsAString & relPath)
{
    return NS_ERROR_NOT_IMPLEMENTED;
}

/* void removeValue (in AString name); */
NS_IMETHODIMP nsWindowsRegKey::RemoveValue(const nsAString & name)
{
    return NS_ERROR_NOT_IMPLEMENTED;
}

/* unsigned long getValueType (in AString name); */
NS_IMETHODIMP nsWindowsRegKey::GetValueType(const nsAString & name, PRUint32 *_retval NS_OUTPARAM)
{
    return NS_ERROR_NOT_IMPLEMENTED;
}

/* AString readStringValue (in AString name); */
NS_IMETHODIMP nsWindowsRegKey::ReadStringValue(const nsAString & name, nsAString & _retval NS_OUTPARAM)
{
    return NS_ERROR_NOT_IMPLEMENTED;
}

/* unsigned long readIntValue (in AString name); */
NS_IMETHODIMP nsWindowsRegKey::ReadIntValue(const nsAString & name, PRUint32 *_retval NS_OUTPARAM)
{
    return NS_ERROR_NOT_IMPLEMENTED;
}

/* unsigned long long readInt64Value (in AString name); */
NS_IMETHODIMP nsWindowsRegKey::ReadInt64Value(const nsAString & name, PRUint64 *_retval NS_OUTPARAM)
{
    return NS_ERROR_NOT_IMPLEMENTED;
}

/* ACString readBinaryValue (in AString name); */
NS_IMETHODIMP nsWindowsRegKey::ReadBinaryValue(const nsAString & name, nsACString & _retval NS_OUTPARAM)
{
    return NS_ERROR_NOT_IMPLEMENTED;
}

/* void writeStringValue (in AString name, in AString data); */
NS_IMETHODIMP nsWindowsRegKey::WriteStringValue(const nsAString & name, const nsAString & data)
{
    return NS_ERROR_NOT_IMPLEMENTED;
}

/* void writeIntValue (in AString name, in unsigned long data); */
NS_IMETHODIMP nsWindowsRegKey::WriteIntValue(const nsAString & name, PRUint32 data)
{
    return NS_ERROR_NOT_IMPLEMENTED;
}

/* void writeInt64Value (in AString name, in unsigned long long data); */
NS_IMETHODIMP nsWindowsRegKey::WriteInt64Value(const nsAString & name, PRUint64 data)
{
    return NS_ERROR_NOT_IMPLEMENTED;
}

/* void writeBinaryValue (in AString name, in ACString data); */
NS_IMETHODIMP nsWindowsRegKey::WriteBinaryValue(const nsAString & name, const nsACString & data)
{
    return NS_ERROR_NOT_IMPLEMENTED;
}

/* void startWatching (in boolean recurse); */
NS_IMETHODIMP nsWindowsRegKey::StartWatching(PRBool recurse)
{
    return NS_ERROR_NOT_IMPLEMENTED;
}

/* void stopWatching (); */
NS_IMETHODIMP nsWindowsRegKey::StopWatching()
{
    return NS_ERROR_NOT_IMPLEMENTED;
}

/* boolean isWatching (); */
NS_IMETHODIMP nsWindowsRegKey::IsWatching(PRBool *_retval NS_OUTPARAM)
{
    return NS_ERROR_NOT_IMPLEMENTED;
}

/* boolean hasChanged (); */
NS_IMETHODIMP nsWindowsRegKey::HasChanged(PRBool *_retval NS_OUTPARAM)
{
    return NS_ERROR_NOT_IMPLEMENTED;
}

/* End of implementation class template. */
#endif


#endif /* __gen_nsIWindowsRegKey_h__ */
