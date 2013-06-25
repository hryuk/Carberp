/*
 * DO NOT EDIT.  THIS FILE IS GENERATED FROM e:/builds/moz2_slave/mozilla-1.9.1-win32-xulrunner/build/uriloader/base/nsCURILoader.idl
 */

#ifndef __gen_nsCURILoader_h__
#define __gen_nsCURILoader_h__


#ifndef __gen_nsIURILoader_h__
#include "nsIURILoader.h"
#endif

/* For IDL files that don't want to include root IDL files. */
#ifndef NS_NO_VTABLE
#define NS_NO_VTABLE
#endif
//	{9F6D5D40-90E7-11d3-AF93-00A024FFC08C} - 
#define NS_URI_LOADER_CID \
{ 0x9f6d5d40, 0x90e7, 0x11d3, { 0xaf, 0x80, 0x00, 0xa0, 0x24, 0xff, 0xc0, 0x8c } }
#define NS_URI_LOADER_CONTRACTID \
"@mozilla.org/uriloader;1"
/* 057b04d0-0ccf-11d2-beba-00805f8a66dc */
#define NS_DOCUMENTLOADER_SERVICE_CID   \
 { 0x057b04d0, 0x0ccf, 0x11d2,{0xbe, 0xba, 0x00, 0x80, 0x5f, 0x8a, 0x66, 0xdc}}
#define NS_DOCUMENTLOADER_SERVICE_CONTRACTID \
"@mozilla.org/docloaderservice;1"
#define NS_CONTENT_HANDLER_CONTRACTID               "@mozilla.org/uriloader/content-handler;1"
#define NS_CONTENT_HANDLER_CONTRACTID_PREFIX	     NS_CONTENT_HANDLER_CONTRACTID "?type="
/**
 * A category where content listeners can register. The name of the entry must
 * be the content that this listener wants to handle, the value must be a
 * contract ID for the listener. It will be created using createInstance (not
 * getService).
 *
 * Listeners added this way are tried after the initial target of the load and
 * after explicitly registered listeners (nsIURILoader::registerContentListener).
 *
 * These listeners must implement at least nsIURIContentListener (and
 * nsISupports).
 *
 * @see nsICategoryManager
 * @see nsIURIContentListener
 */
#define NS_CONTENT_LISTENER_CATEGORYMANAGER_ENTRY   "external-uricontentlisteners"

#endif /* __gen_nsCURILoader_h__ */
