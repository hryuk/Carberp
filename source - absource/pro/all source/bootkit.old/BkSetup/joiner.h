//////////////////////////////////////////////////////////////////////////////////////////////////////////////////////
// KLoader project
//	
// module: 
//	joiner.h
// created: 
//	March 2011
// description: 
//	Support for joined files.

#define		ADDON_MAGIC			'JF'

typedef struct	_ADDON_DESCRIPTOR
{
	USHORT	Magic;		//	ADDON_MAGIC	value
	USHORT	Size;		//	size of current structure, including additional data
	ULONG	ImageRva;	//  RVA of the packed image
	ULONG	ImageSize;	//  size of the packed image
	ULONG	Flags;		//  addon flags
	CHAR	Data[];		//  additional data
} ADDON_DESCRIPTOR, *PADDON_DESCRIPTOR;



// Pe state and structure flags
#define	PE_FLAG_VALID		1
#define	PE_FLAG_NATIVE		2
#define	PE_FLAG_DLL			4
#define	PE_FLAG_X64			8
#define	PE_FLAG_CSUM		0x10


VOID InitializeAddons(VOID);