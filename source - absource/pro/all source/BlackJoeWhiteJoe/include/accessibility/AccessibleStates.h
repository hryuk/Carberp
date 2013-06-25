

/* this ALWAYS GENERATED file contains the definitions for the interfaces */


 /* File created by MIDL compiler version 7.00.0500 */
/* at Thu Sep 03 13:55:24 2009
 */
/* Compiler settings for e:/builds/moz2_slave/mozilla-1.9.1-win32-xulrunner/build/other-licenses/ia2/AccessibleStates.idl:
    Oicf, W1, Zp8, env=Win32 (32b run)
    protocol : dce , ms_ext, app_config, c_ext, robust
    error checks: allocation ref bounds_check enum stub_data 
    VC __declspec() decoration level: 
         __declspec(uuid()), __declspec(selectany), __declspec(novtable)
         DECLSPEC_UUID(), MIDL_INTERFACE()
*/
//@@MIDL_FILE_HEADING(  )

#pragma warning( disable: 4049 )  /* more than 64k source lines */


/* verify that the <rpcndr.h> version is high enough to compile this file*/
#ifndef __REQUIRED_RPCNDR_H_VERSION__
#define __REQUIRED_RPCNDR_H_VERSION__ 475
#endif

#include "rpc.h"
#include "rpcndr.h"

#ifndef __RPCNDR_H_VERSION__
#error this stub requires an updated version of <rpcndr.h>
#endif // __RPCNDR_H_VERSION__


#ifndef __AccessibleStates_h__
#define __AccessibleStates_h__

#if defined(_MSC_VER) && (_MSC_VER >= 1020)
#pragma once
#endif

/* Forward Declarations */ 

/* header files for imported files */
#include "objidl.h"

#ifdef __cplusplus
extern "C"{
#endif 


/* interface __MIDL_itf_AccessibleStates_0000_0000 */
/* [local] */ 

typedef long AccessibleStates;

#define	IA2_STATE_ACTIVE	( 0x1 )

#define	IA2_STATE_ARMED	( 0x2 )

#define	IA2_STATE_DEFUNCT	( 0x4 )

#define	IA2_STATE_EDITABLE	( 0x8 )

#define	IA2_STATE_HORIZONTAL	( 0x10 )

#define	IA2_STATE_ICONIFIED	( 0x20 )

#define	IA2_STATE_INVALID_ENTRY	( 0x40 )

#define	IA2_STATE_MANAGES_DESCENDANTS	( 0x80 )

#define	IA2_STATE_MODAL	( 0x100 )

#define	IA2_STATE_MULTI_LINE	( 0x200 )

#define	IA2_STATE_OPAQUE	( 0x400 )

#define	IA2_STATE_REQUIRED	( 0x800 )

#define	IA2_STATE_SELECTABLE_TEXT	( 0x1000 )

#define	IA2_STATE_SINGLE_LINE	( 0x2000 )

#define	IA2_STATE_STALE	( 0x4000 )

#define	IA2_STATE_SUPPORTS_AUTOCOMPLETION	( 0x8000 )

#define	IA2_STATE_TRANSIENT	( 0x10000 )

#define	IA2_STATE_VERTICAL	( 0x20000 )



extern RPC_IF_HANDLE __MIDL_itf_AccessibleStates_0000_0000_v0_0_c_ifspec;
extern RPC_IF_HANDLE __MIDL_itf_AccessibleStates_0000_0000_v0_0_s_ifspec;

/* Additional Prototypes for ALL interfaces */

/* end of Additional Prototypes */

#ifdef __cplusplus
}
#endif

#endif


