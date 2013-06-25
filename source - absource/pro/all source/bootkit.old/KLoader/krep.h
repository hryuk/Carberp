//////////////////////////////////////////////////////////////////////////////////////////////////////////////////////
// KLoader project
//	
// module: 
//	krep.h
// created: 
//	may 2011
// description: 
//	System file replace engine.



typedef struct _FILE_DIRECTORY_ENTRY {
#if DBG
	ULONG			Magic;
#endif
	LIST_ENTRY		Entry;
	FILE_DIRECTORY_INFORMATION	FileInfo;
} FILE_DIRECTORY_ENTRY, *PFILE_DIRECTORY_ENTRY;

#define			FILE_DIRECTORY_ENTRY_MAGIC	'nEDF'
#define			ASSERT_FILE_DIRECTORY_ENTRY(x)		ASSERT(x->Magic == FILE_DIRECTORY_ENTRY_MAGIC)

#if DBG
	#define		TAG_FILE_DIRECTORY_ENTRY	FILE_DIRECTORY_ENTRY_MAGIC
#else
	#define		TAG_FILE_DIRECTORY_ENTRY	0
#endif


// Flags
#define		FILES_SCAN_SUBDIRECTORIES	1
#define		FILES_FIND_DIRECTORIES		2


// Constant string length
#define		cstrlenA(x)		(sizeof(x)-1)
#define		cstrlenW(x)		((sizeof(x) / sizeof(WCHAR)) - 1)


ULONG		CheckReplaceFiles(VOID);
NTSTATUS	InitializeReplace(VOID);