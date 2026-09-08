/**
 * Decompiled source of WorldsChat (Worlds1900.exe) produced by Ghidra.
 * This file contains the original low‑level implementation with CRT helpers
 * and Win32 API usage.  The project now provides a modern CMake build, stub
 * implementations for non‑Windows platforms, and documentation comments to aid
 * understanding and further development.
 */
#include "windows_compat.h"
typedef unsigned char   undefined;

typedef unsigned char    byte;
typedef unsigned int    dword;
typedef pointer32 ImageBaseOffset32;

typedef unsigned char    uchar;
typedef unsigned int    uint;
typedef unsigned long    ulong;
typedef unsigned char    undefined1;
typedef unsigned short    undefined2;
typedef unsigned int    undefined4;
typedef unsigned short    ushort;
typedef short    wchar_t;
typedef unsigned short    word;
typedef union IMAGE_RESOURCE_DIRECTORY_ENTRY_DirectoryUnion IMAGE_RESOURCE_DIRECTORY_ENTRY_DirectoryUnion, *PIMAGE_RESOURCE_DIRECTORY_ENTRY_DirectoryUnion;

typedef struct IMAGE_RESOURCE_DIRECTORY_ENTRY_DirectoryStruct IMAGE_RESOURCE_DIRECTORY_ENTRY_DirectoryStruct, *PIMAGE_RESOURCE_DIRECTORY_ENTRY_DirectoryStruct;

struct IMAGE_RESOURCE_DIRECTORY_ENTRY_DirectoryStruct {
    dword OffsetToDirectory:31;
    dword DataIsDirectory:1;
};

union IMAGE_RESOURCE_DIRECTORY_ENTRY_DirectoryUnion {
    dword OffsetToData;
    struct IMAGE_RESOURCE_DIRECTORY_ENTRY_DirectoryStruct IMAGE_RESOURCE_DIRECTORY_ENTRY_DirectoryStruct;
};

typedef struct tagPAINTSTRUCT tagPAINTSTRUCT, *PtagPAINTSTRUCT;

typedef struct tagPAINTSTRUCT PAINTSTRUCT;

typedef struct HDC__ HDC__, *PHDC__;

typedef struct HDC__ *HDC;

typedef int BOOL;

typedef struct tagRECT tagRECT, *PtagRECT;

typedef struct tagRECT RECT;

typedef uchar BYTE;

typedef long LONG;

struct HDC__ {
    int unused;
};

struct tagRECT {
    LONG left;
    LONG top;
    LONG right;
    LONG bottom;
};

struct tagPAINTSTRUCT {
    HDC hdc;
    BOOL fErase;
    RECT rcPaint;
    BOOL fRestore;
    BOOL fIncUpdate;
    BYTE rgbReserved[32];
};

typedef struct tagWNDCLASSA tagWNDCLASSA, *PtagWNDCLASSA;

typedef uint UINT;

typedef long LONG_PTR;

typedef LONG_PTR LRESULT;

typedef struct HWND__ HWND__, *PHWND__;

typedef struct HWND__ *HWND;

typedef uint UINT_PTR;

typedef UINT_PTR WPARAM;

typedef LONG_PTR LPARAM;

typedef LRESULT (*WNDPROC)(HWND, UINT, WPARAM, LPARAM);

typedef struct HINSTANCE__ HINSTANCE__, *PHINSTANCE__;

typedef struct HINSTANCE__ *HINSTANCE;

typedef struct HICON__ HICON__, *PHICON__;

typedef struct HICON__ *HICON;

typedef HICON HCURSOR;

typedef struct HBRUSH__ HBRUSH__, *PHBRUSH__;

typedef struct HBRUSH__ *HBRUSH;

typedef char CHAR;

typedef CHAR *LPCSTR;

struct HBRUSH__ {
    int unused;
};

struct tagWNDCLASSA {
    UINT style;
    WNDPROC lpfnWndProc;
    int cbClsExtra;
    int cbWndExtra;
    HINSTANCE hInstance;
    HICON hIcon;
    HCURSOR hCursor;
    HBRUSH hbrBackground;
    LPCSTR lpszMenuName;
    LPCSTR lpszClassName;
};

struct HICON__ {
    int unused;
};

struct HINSTANCE__ {
    int unused;
};

struct HWND__ {
    int unused;
};

typedef struct tagWNDCLASSA WNDCLASSA;

typedef struct tagPAINTSTRUCT *LPPAINTSTRUCT;

typedef struct _cpinfo _cpinfo, *P_cpinfo;

struct _cpinfo {
    UINT MaxCharSize;
    BYTE DefaultChar[2];
    BYTE LeadByte[12];
};

typedef struct _cpinfo *LPCPINFO;

typedef struct tagPALETTEENTRY tagPALETTEENTRY, *PtagPALETTEENTRY;

typedef struct tagPALETTEENTRY PALETTEENTRY;

struct tagPALETTEENTRY {
    BYTE peRed;
    BYTE peGreen;
    BYTE peBlue;
    BYTE peFlags;
};

typedef struct tagLOGPALETTE tagLOGPALETTE, *PtagLOGPALETTE;

typedef ushort WORD;

struct tagLOGPALETTE {
    WORD palVersion;
    WORD palNumEntries;
    PALETTEENTRY palPalEntry[1];
};

typedef struct tagLOGPALETTE LOGPALETTE;

typedef struct _STARTUPINFOA _STARTUPINFOA, *P_STARTUPINFOA;

typedef ulong DWORD;

typedef CHAR *LPSTR;

typedef BYTE *LPBYTE;

typedef void *HANDLE;

struct _STARTUPINFOA {
    DWORD cb;
    LPSTR lpReserved;
    LPSTR lpDesktop;
    LPSTR lpTitle;
    DWORD dwX;
    DWORD dwY;
    DWORD dwXSize;
    DWORD dwYSize;
    DWORD dwXCountChars;
    DWORD dwYCountChars;
    DWORD dwFillAttribute;
    DWORD dwFlags;
    WORD wShowWindow;
    WORD cbReserved2;
    LPBYTE lpReserved2;
    HANDLE hStdInput;
    HANDLE hStdOutput;
    HANDLE hStdError;
};

typedef struct _STARTUPINFOA *LPSTARTUPINFOA;

typedef struct _OVERLAPPED _OVERLAPPED, *P_OVERLAPPED;

typedef ulong ULONG_PTR;

typedef union _union_518 _union_518, *P_union_518;

typedef struct _struct_519 _struct_519, *P_struct_519;

typedef void *PVOID;

struct _struct_519 {
    DWORD Offset;
    DWORD OffsetHigh;
};

union _union_518 {
    struct _struct_519 s;
    PVOID Pointer;
};

struct _OVERLAPPED {
    ULONG_PTR Internal;
    ULONG_PTR InternalHigh;
    union _union_518 u;
    HANDLE hEvent;
};

typedef struct _OVERLAPPED *LPOVERLAPPED;

typedef struct _CONTEXT _CONTEXT, *P_CONTEXT;

typedef struct _CONTEXT CONTEXT;

typedef struct _FLOATING_SAVE_AREA _FLOATING_SAVE_AREA, *P_FLOATING_SAVE_AREA;

typedef struct _FLOATING_SAVE_AREA FLOATING_SAVE_AREA;

struct _FLOATING_SAVE_AREA {
    DWORD ControlWord;
    DWORD StatusWord;
    DWORD TagWord;
    DWORD ErrorOffset;
    DWORD ErrorSelector;
    DWORD DataOffset;
    DWORD DataSelector;
    BYTE RegisterArea[80];
    DWORD Cr0NpxState;
};

struct _CONTEXT {
    DWORD ContextFlags;
    DWORD Dr0;
    DWORD Dr1;
    DWORD Dr2;
    DWORD Dr3;
    DWORD Dr6;
    DWORD Dr7;
    FLOATING_SAVE_AREA FloatSave;
    DWORD SegGs;
    DWORD SegFs;
    DWORD SegEs;
    DWORD SegDs;
    DWORD Edi;
    DWORD Esi;
    DWORD Ebx;
    DWORD Edx;
    DWORD Ecx;
    DWORD Eax;
    DWORD Ebp;
    DWORD Eip;
    DWORD SegCs;
    DWORD EFlags;
    DWORD Esp;
    DWORD SegSs;
    BYTE ExtendedRegisters[512];
};

typedef struct _EXCEPTION_RECORD _EXCEPTION_RECORD, *P_EXCEPTION_RECORD;

typedef struct _EXCEPTION_RECORD EXCEPTION_RECORD;

typedef EXCEPTION_RECORD *PEXCEPTION_RECORD;

struct _EXCEPTION_RECORD {
    DWORD ExceptionCode;
    DWORD ExceptionFlags;
    struct _EXCEPTION_RECORD *ExceptionRecord;
    PVOID ExceptionAddress;
    DWORD NumberParameters;
    ULONG_PTR ExceptionInformation[15];
};

typedef wchar_t WCHAR;

typedef WCHAR *LPWCH;

typedef WCHAR *LPCWSTR;

typedef CHAR *LPCCH;

typedef CHAR *LPCH;

typedef struct _OSVERSIONINFOA _OSVERSIONINFOA, *P_OSVERSIONINFOA;

struct _OSVERSIONINFOA {
    DWORD dwOSVersionInfoSize;
    DWORD dwMajorVersion;
    DWORD dwMinorVersion;
    DWORD dwBuildNumber;
    DWORD dwPlatformId;
    CHAR szCSDVersion[128];
};

typedef struct _OSVERSIONINFOA *LPOSVERSIONINFOA;

typedef CONTEXT *PCONTEXT;

typedef struct IMAGE_DOS_HEADER IMAGE_DOS_HEADER, *PIMAGE_DOS_HEADER;

struct IMAGE_DOS_HEADER {
    char e_magic[2]; // Magic number
    word e_cblp; // Bytes of last page
    word e_cp; // Pages in file
    word e_crlc; // Relocations
    word e_cparhdr; // Size of header in paragraphs
    word e_minalloc; // Minimum extra paragraphs needed
    word e_maxalloc; // Maximum extra paragraphs needed
    word e_ss; // Initial (relative) SS value
    word e_sp; // Initial SP value
    word e_csum; // Checksum
    word e_ip; // Initial IP value
    word e_cs; // Initial (relative) CS value
    word e_lfarlc; // File address of relocation table
    word e_ovno; // Overlay number
    word e_res[4][4]; // Reserved words
    word e_oemid; // OEM identifier (for e_oeminfo)
    word e_oeminfo; // OEM information; e_oemid specific
    word e_res2[10][10]; // Reserved words
    dword e_lfanew; // File address of new exe header
    byte e_program[64]; // Actual DOS program
};

typedef ULONG_PTR SIZE_T;

typedef struct _EXCEPTION_POINTERS _EXCEPTION_POINTERS, *P_EXCEPTION_POINTERS;

struct _EXCEPTION_POINTERS {
    PEXCEPTION_RECORD ExceptionRecord;
    PCONTEXT ContextRecord;
};

typedef struct HPALETTE__ HPALETTE__, *PHPALETTE__;

struct HPALETTE__ {
    int unused;
};

typedef void *LPVOID;

typedef HINSTANCE HMODULE;

typedef int (*FARPROC)(void);

typedef WORD ATOM;

typedef struct tagRECT *LPRECT;

typedef BOOL *LPBOOL;

typedef void *HGDIOBJ;

typedef DWORD COLORREF;

typedef DWORD *LPDWORD;

typedef struct HPALETTE__ *HPALETTE;

typedef struct HMENU__ HMENU__, *PHMENU__;

typedef struct HMENU__ *HMENU;

struct HMENU__ {
    int unused;
};

typedef int HFILE;

typedef HANDLE HGLOBAL;

typedef void *LPCVOID;

typedef struct IMAGE_OPTIONAL_HEADER32 IMAGE_OPTIONAL_HEADER32, *PIMAGE_OPTIONAL_HEADER32;

typedef struct IMAGE_DATA_DIRECTORY IMAGE_DATA_DIRECTORY, *PIMAGE_DATA_DIRECTORY;

struct IMAGE_DATA_DIRECTORY {
    ImageBaseOffset32 VirtualAddress;
    dword Size;
};

struct IMAGE_OPTIONAL_HEADER32 {
    word Magic;
    byte MajorLinkerVersion;
    byte MinorLinkerVersion;
    dword SizeOfCode;
    dword SizeOfInitializedData;
    dword SizeOfUninitializedData;
    ImageBaseOffset32 AddressOfEntryPoint;
    ImageBaseOffset32 BaseOfCode;
    ImageBaseOffset32 BaseOfData;
    pointer32 ImageBase;
    dword SectionAlignment;
    dword FileAlignment;
    word MajorOperatingSystemVersion;
    word MinorOperatingSystemVersion;
    word MajorImageVersion;
    word MinorImageVersion;
    word MajorSubsystemVersion;
    word MinorSubsystemVersion;
    dword Win32VersionValue;
    dword SizeOfImage;
    dword SizeOfHeaders;
    dword CheckSum;
    word Subsystem;
    word DllCharacteristics;
    dword SizeOfStackReserve;
    dword SizeOfStackCommit;
    dword SizeOfHeapReserve;
    dword SizeOfHeapCommit;
    dword LoaderFlags;
    dword NumberOfRvaAndSizes;
    struct IMAGE_DATA_DIRECTORY DataDirectory[16];
};

typedef struct IMAGE_RESOURCE_DIRECTORY_ENTRY_NameStruct IMAGE_RESOURCE_DIRECTORY_ENTRY_NameStruct, *PIMAGE_RESOURCE_DIRECTORY_ENTRY_NameStruct;

struct IMAGE_RESOURCE_DIRECTORY_ENTRY_NameStruct {
    dword NameOffset:31;
    dword NameIsString:1;
};

typedef struct IMAGE_FILE_HEADER IMAGE_FILE_HEADER, *PIMAGE_FILE_HEADER;

struct IMAGE_FILE_HEADER {
    word Machine; // 332
    word NumberOfSections;
    dword TimeDateStamp;
    dword PointerToSymbolTable;
    dword NumberOfSymbols;
    word SizeOfOptionalHeader;
    word Characteristics;
};

typedef struct IMAGE_NT_HEADERS32 IMAGE_NT_HEADERS32, *PIMAGE_NT_HEADERS32;

struct IMAGE_NT_HEADERS32 {
    char Signature[4];
    struct IMAGE_FILE_HEADER FileHeader;
    struct IMAGE_OPTIONAL_HEADER32 OptionalHeader;
};

typedef struct IMAGE_RESOURCE_DIRECTORY_ENTRY IMAGE_RESOURCE_DIRECTORY_ENTRY, *PIMAGE_RESOURCE_DIRECTORY_ENTRY;

typedef union IMAGE_RESOURCE_DIRECTORY_ENTRY_NameUnion IMAGE_RESOURCE_DIRECTORY_ENTRY_NameUnion, *PIMAGE_RESOURCE_DIRECTORY_ENTRY_NameUnion;

union IMAGE_RESOURCE_DIRECTORY_ENTRY_NameUnion {
    struct IMAGE_RESOURCE_DIRECTORY_ENTRY_NameStruct IMAGE_RESOURCE_DIRECTORY_ENTRY_NameStruct;
    dword Name;
    word Id;
};

struct IMAGE_RESOURCE_DIRECTORY_ENTRY {
    union IMAGE_RESOURCE_DIRECTORY_ENTRY_NameUnion NameUnion;
    union IMAGE_RESOURCE_DIRECTORY_ENTRY_DirectoryUnion DirectoryUnion;
};

typedef struct IMAGE_SECTION_HEADER IMAGE_SECTION_HEADER, *PIMAGE_SECTION_HEADER;

typedef union Misc Misc, *PMisc;

typedef enum SectionFlags {
    IMAGE_SCN_TYPE_NO_PAD=8,
    IMAGE_SCN_RESERVED_0001=16,
    IMAGE_SCN_CNT_CODE=32,
    IMAGE_SCN_CNT_INITIALIZED_DATA=64,
    IMAGE_SCN_CNT_UNINITIALIZED_DATA=128,
    IMAGE_SCN_LNK_OTHER=256,
    IMAGE_SCN_LNK_INFO=512,
    IMAGE_SCN_RESERVED_0040=1024,
    IMAGE_SCN_LNK_REMOVE=2048,
    IMAGE_SCN_LNK_COMDAT=4096,
    IMAGE_SCN_GPREL=32768,
    IMAGE_SCN_MEM_16BIT=131072,
    IMAGE_SCN_MEM_PURGEABLE=131072,
    IMAGE_SCN_MEM_LOCKED=262144,
    IMAGE_SCN_MEM_PRELOAD=524288,
    IMAGE_SCN_ALIGN_1BYTES=1048576,
    IMAGE_SCN_ALIGN_2BYTES=2097152,
    IMAGE_SCN_ALIGN_4BYTES=3145728,
    IMAGE_SCN_ALIGN_8BYTES=4194304,
    IMAGE_SCN_ALIGN_16BYTES=5242880,
    IMAGE_SCN_ALIGN_32BYTES=6291456,
    IMAGE_SCN_ALIGN_64BYTES=7340032,
    IMAGE_SCN_ALIGN_128BYTES=8388608,
    IMAGE_SCN_ALIGN_256BYTES=9437184,
    IMAGE_SCN_ALIGN_512BYTES=10485760,
    IMAGE_SCN_ALIGN_1024BYTES=11534336,
    IMAGE_SCN_ALIGN_2048BYTES=12582912,
    IMAGE_SCN_ALIGN_4096BYTES=13631488,
    IMAGE_SCN_ALIGN_8192BYTES=14680064,
    IMAGE_SCN_LNK_NRELOC_OVFL=16777216,
    IMAGE_SCN_MEM_DISCARDABLE=33554432,
    IMAGE_SCN_MEM_NOT_CACHED=67108864,
    IMAGE_SCN_MEM_NOT_PAGED=134217728,
    IMAGE_SCN_MEM_SHARED=268435456,
    IMAGE_SCN_MEM_EXECUTE=536870912,
    IMAGE_SCN_MEM_READ=1073741824,
    IMAGE_SCN_MEM_WRITE=2147483648
} SectionFlags;

union Misc {
    dword PhysicalAddress;
    dword VirtualSize;
};

struct IMAGE_SECTION_HEADER {
    char Name[8];
    union Misc Misc;
    ImageBaseOffset32 VirtualAddress;
    dword SizeOfRawData;
    dword PointerToRawData;
    dword PointerToRelocations;
    dword PointerToLinenumbers;
    word NumberOfRelocations;
    word NumberOfLinenumbers;
    enum SectionFlags Characteristics;
};

typedef struct IMAGE_BASE_RELOCATION IMAGE_BASE_RELOCATION, *PIMAGE_BASE_RELOCATION;

struct IMAGE_BASE_RELOCATION {
    dword VirtualAddress;
    dword SizeOfBlock;
};

typedef struct IMAGE_RESOURCE_DATA_ENTRY IMAGE_RESOURCE_DATA_ENTRY, *PIMAGE_RESOURCE_DATA_ENTRY;

struct IMAGE_RESOURCE_DATA_ENTRY {
    dword OffsetToData;
    dword Size;
    dword CodePage;
    dword Reserved;
};

typedef struct IMAGE_RESOURCE_DIRECTORY IMAGE_RESOURCE_DIRECTORY, *PIMAGE_RESOURCE_DIRECTORY;

struct IMAGE_RESOURCE_DIRECTORY {
    dword Characteristics;
    dword TimeDateStamp;
    word MajorVersion;
    word MinorVersion;
    word NumberOfNamedEntries;
    word NumberOfIdEntries;
};

typedef struct IMAGE_DIRECTORY_ENTRY_EXPORT IMAGE_DIRECTORY_ENTRY_EXPORT, *PIMAGE_DIRECTORY_ENTRY_EXPORT;

struct IMAGE_DIRECTORY_ENTRY_EXPORT {
    dword Characteristics;
    dword TimeDateStamp;
    word MajorVersion;
    word MinorVersion;
    ImageBaseOffset32 Name;
    dword Base;
    dword NumberOfFunctions;
    dword NumberOfNames;
    ImageBaseOffset32 AddressOfFunctions;
    ImageBaseOffset32 AddressOfNames;
    ImageBaseOffset32 AddressOfNameOrdinals;
};

typedef uint size_t;



HGLOBAL DAT_0040742c;
LPVOID lpBuffer_00407448;
LPVOID DAT_00407428;
HGLOBAL DAT_00407454;
undefined4 *DAT_00407430;
void *DAT_00407430;
uint DAT_00407458;
uint DAT_0040744c;
int DAT_00407420;
uint DAT_0040743c;
int DAT_0040737c;
int DAT_00407428;
undefined DAT_00406178;
int DAT_0040743c;
uint DAT_0040619c;
uint DAT_004061a0;
undefined4 DAT_00406028;
undefined DAT_00406074;
uint DAT_00407438;
uint DAT_00407434;
size_t DAT_0040743c;
void *DAT_004073e8;
byte *DAT_00407428;
uint DAT_00407444;
undefined DAT_00407374;
undefined4 DAT_00407440;
undefined *DAT_00407400;
undefined4 DAT_0040737c;
undefined1 DAT_00407380;
LPVOID lpBuffer_00407394;
undefined DAT_004062b0;
UINT DAT_00407450;
undefined *DAT_00407350;
int DAT_00407368;
undefined DAT_0040736c;
undefined4 DAT_00407434;
UINT DAT_00407438;
HFILE hFile_00407378;
HFILE hFile_00407424;
int DAT_00407450;
undefined4 DAT_00407438;
int DAT_00407434;
undefined4 DAT_0040743c;
undefined4 DAT_00407458;
undefined *DAT_004073fc;
uint DAT_00407420;
char DAT_00407380;
uint DAT_00406020;
int DAT_00407430;
undefined _StubFileWrite@12;
int DAT_00407390;
int DAT_004061b0;
undefined DAT_00407370;
LONG DAT_00407368;
undefined1 DAT_00407398;
undefined DAT_00407360;
undefined DAT_00407364;
undefined FUN_00401fd7;
int DAT_004073d4;
undefined FUN_0040219e;
undefined DAT_004073ec;
undefined DAT_004073f0;
undefined DAT_004073e0;
undefined DAT_004073e4;
int DAT_004073a4;
LPVOID DAT_004073e8;
int DAT_004073a8;
HGDIOBJ DAT_00407404;
FARPROC DAT_0040741c;
FARPROC DAT_004073fc;
FARPROC DAT_004073f8;
FARPROC DAT_00407350;
FARPROC DAT_00407408;
string s_System_DLLs_corrupt_or_missing._004061b8;
string s_Demo_installations_only_run_on_t_004061d8;
string s_Install_0040621c;
string s_HandleFtp_00406224;
string s_FileWrite_00406230;
string s_DiskPrompt_0040623c;
string s_DisplayGraphics_00406248;
undefined lpBuffer_00407410;
string s_UpdateScreen_00406258;
LPVOID lpBuffer_004073d8;
string s_WiseMain_00406268;
LPVOID lpBuffer_004073a0;
HWND hWnd_0040734c;
undefined DAT_0000006c;
undefined DAT_00007f00;
pointer lpClassName_004061b4;
undefined _MainWndProc@16;
int DAT_00407388;
LPCSTR lpWindowName_00406274;
int w_00407384;
LONG DAT_00407388;
undefined *DAT_00407408;
HPALETTE DAT_0040739c;
undefined DAT_0040738c;
HPALETTE DAT_00407404;
undefined2 DAT_00407416;
byte DAT_00407398;
undefined *DAT_004073f8;
string s_\~GLC%04x.TMP_00406278;
string s_Corrupt_installation_detected._00406288;
short DAT_00407418;
short DAT_0040741a;
int DAT_00406310;
uint DAT_00406b34;
HANDLE DAT_00407564;
undefined *DAT_00407574;
undefined DAT_00406000;
undefined DAT_00406004;
undefined DAT_00406008;
undefined DAT_0040600c;
int DAT_004062f8;
undefined DAT_004062f4;
undefined1 DAT_004062f0;
undefined4 *DAT_00407570;
int DAT_0040756c;
undefined DAT_00406010;
undefined DAT_00406014;
undefined DAT_00406018;
undefined DAT_0040601c;
undefined DAT_004062b4;
uint DAT_004062bc;
undefined DAT_004062c8;
undefined DAT_004062c4;
undefined DAT_004062c0;
byte *DAT_00407568;
LPVOID DAT_004062fc;
undefined LAB_00404880;
undefined DAT_00405000;
int DAT_00406308;
undefined *PTR___exit_00406304;
undefined *DAT_00407240;
int DAT_00406b28;
pointer PTR_LOOP_00406318;
undefined *PTR_LOOP_0040631c;
undefined *PTR_LOOP_00406b2c;
undefined4 DAT_00406b28;
int DAT_00406b30;
undefined4 DAT_00406b38;
undefined DAT_00406ca0;
undefined LAB_00403c0c;
undefined4 DAT_00406ca8;
undefined4 DAT_00406ca4;
int DAT_00406cac;
_EXCEPTION_POINTERS *DAT_00406d38;
int DAT_00406d2c;
int DAT_00406d28;
undefined4 DAT_00406d34;
int DAT_00406d30;
undefined4 DAT_00406cb0;
undefined4 DAT_00406d48;
undefined DAT_0040700a;
char *DAT_004062fc;
undefined DAT_004062d8;
undefined DAT_004062e8;
undefined DAT_004062d0;
undefined DAT_004062cc;
undefined DAT_00407248;
int DAT_00406d40;
UINT DAT_00406e4c;
undefined DAT_00406e50;
int DAT_00406e64;
undefined4 DAT_00406e58;
undefined4 DAT_00406e5c;
undefined4 DAT_00406e60;
undefined1 DAT_00406e68;
undefined4 DAT_00406e70;
undefined DAT_00406e74;
undefined DAT_00406e78;
undefined DAT_00406e80;
undefined DAT_00406f60;
uint DAT_00406e64;
int DAT_00407228;
undefined4 DAT_00406e4c;
undefined4 DAT_00407460;
UINT DAT_00407560;
undefined4 DAT_00407464;
int DAT_0040630c;
undefined *DAT_00406ff8;
int DAT_00407460;
undefined4 DAT_00406f68;
undefined4 DAT_00406ff8;
FARPROC DAT_0040722c;
FARPROC DAT_00407230;
FARPROC DAT_00407234;

void FUN_00401000(void)

{
  int iVar1;
  uint uVar2;
  uint uVar3;
  
  DAT_0040742c = GlobalAlloc(2,0x10000);
  DAT_00407428 = GlobalLock(DAT_0040742c);
  DAT_00407454 = GlobalAlloc(2,0x8040);
  lpBuffer_00407448 = GlobalLock(DAT_00407454);
  DAT_00407430 = _malloc(0x400);
  uVar2 = 1;
  *DAT_00407430 = 0;
  do {
    iVar1 = 8;
    uVar3 = uVar2;
    do {
      if ((uVar3 & 1) == 0) {
        uVar3 = uVar3 >> 1;
      }
      else {
        uVar3 = ~((uVar3 ^ 0x248ef9be) >> 1);
      }
      iVar1 = iVar1 + -1;
    } while (iVar1 != 0);
    DAT_00407430[uVar2] = uVar3;
    uVar2 = uVar2 + 1;
  } while ((int)uVar2 < 0x100);
  return;
}



void FUN_00401088(void)

{
  GlobalUnlock(DAT_0040742c);
  GlobalFree(DAT_0040742c);
  GlobalUnlock(DAT_00407454);
  GlobalFree(DAT_00407454);
  _free(DAT_00407430);
  return;
}



int __cdecl FUN_004010c7(uint *param_1)

{
  int iVar1;
  uint uVar2;
  uint local_c;
  uint local_8;
  
  local_8 = DAT_00407458;
  local_c = DAT_0040744c;
  FUN_00401e0f(1,&local_8,&local_c);
  *param_1 = local_8 & 1;
  FUN_00401e64(1,&local_8,(int *)&local_c);
  FUN_00401e0f(2,&local_8,&local_c);
  uVar2 = local_8 & 3;
  FUN_00401e64(2,&local_8,(int *)&local_c);
  DAT_00407458 = local_8;
  DAT_0040744c = local_c;
  if (uVar2 == 0) {
    iVar1 = FUN_00401810();
  }
  else if (uVar2 == 1) {
    iVar1 = FUN_00401928();
  }
  else if (uVar2 == 2) {
    iVar1 = FUN_00401a37();
  }
  else {
    iVar1 = -2;
  }
  return iVar1;
}



// WARNING: Type propagation algorithm not settling

undefined4 __cdecl
FUN_00401177(uint param_1,uint param_2,int *param_3,int param_4,int param_5,undefined4 *param_6,
            uint *param_7)

{
  undefined3 uVar1;
  undefined4 uVar2;
  undefined4 *puVar3;
  undefined4 *puVar4;
  uint *puVar5;
  byte bVar6;
  uint uVar7;
  uint *puVar8;
  int iVar9;
  uint uVar10;
  uint uVar11;
  int iVar12;
  int *piVar13;
  int iVar14;
  uint local_590 [288];
  int local_110 [16];
  uint local_d0 [17];
  uint local_8c [17];
  uint *local_48;
  uint local_44;
  uint *local_40;
  uint local_3c;
  uint *local_38;
  uint local_34;
  uint *local_30;
  int local_2c;
  uint local_28;
  uint *local_24;
  undefined4 local_20;
  uint *local_1c;
  uint local_18;
  uint local_14;
  uint local_10;
  int local_c;
  uint local_8;
  
  _memset(local_8c,0,0x44);
  uVar11 = param_1;
  piVar13 = param_3;
  do {
    iVar14 = *piVar13;
    piVar13 = piVar13 + 1;
    local_8c[iVar14] = local_8c[iVar14] + 1;
    uVar11 = uVar11 - 1;
  } while (uVar11 != 0);
  if (local_8c[0] == param_1) {
    uVar2 = 0;
    *param_7 = 0;
    *param_6 = 0;
  }
  else {
    uVar11 = 1;
    puVar8 = local_8c + 1;
    do {
      if (*puVar8 != 0) break;
      puVar8 = puVar8 + 1;
      uVar11 = uVar11 + 1;
    } while (puVar8 <= local_8c + 0x10);
    local_8 = uVar11;
    local_18 = uVar11;
    uVar10 = *param_7;
    if (*param_7 < uVar11) {
      uVar10 = uVar11;
    }
    uVar7 = 0x10;
    puVar8 = local_8c + 0x10;
    do {
      if (*puVar8 != 0) break;
      puVar8 = puVar8 + -1;
      uVar7 = uVar7 - 1;
    } while (puVar8 != local_8c);
    local_28 = uVar7;
    if (uVar7 < uVar10) {
      uVar10 = uVar7;
    }
    *param_7 = uVar10;
    iVar14 = 1 << ((byte)uVar11 & 0x1f);
    if (uVar11 < uVar7) {
      puVar8 = local_8c + uVar11;
      do {
        if ((int)(iVar14 - *puVar8) < 0) {
          return 0xfffffffd;
        }
        iVar14 = (iVar14 - *puVar8) * 2;
        puVar8 = puVar8 + 1;
        uVar11 = uVar11 + 1;
      } while (uVar11 < uVar7);
    }
    uVar11 = local_8c[uVar7];
    iVar14 = iVar14 - uVar11;
    if (iVar14 < 0) {
      uVar2 = 0xfffffffd;
    }
    else {
      puVar5 = local_8c;
      local_8c[uVar7] = uVar11 + iVar14;
      uVar11 = 0;
      puVar8 = local_d0 + 2;
      local_d0[1] = 0;
      while( true ) {
        puVar5 = puVar5 + 1;
        uVar7 = uVar7 - 1;
        if (uVar7 == 0) break;
        uVar11 = uVar11 + *puVar5;
        *puVar8 = uVar11;
        puVar8 = puVar8 + 1;
      }
      uVar11 = 0;
      do {
        iVar12 = *param_3;
        param_3 = param_3 + 1;
        if (iVar12 != 0) {
          uVar7 = local_d0[iVar12];
          local_d0[iVar12] = uVar7 + 1;
          local_590[uVar7] = uVar11;
        }
        uVar11 = uVar11 + 1;
      } while (uVar11 < param_1);
      puVar8 = (uint *)0x0;
      local_110[0] = 0;
      local_14 = 0;
      local_30 = local_590;
      local_d0[0] = 0;
      local_c = -uVar10;
      local_10 = 0;
      local_2c = -1;
      if ((int)local_8 <= (int)local_28) {
        do {
          local_40 = local_8c + local_18;
          local_34 = local_8c[local_18];
          while (local_3c = local_34, local_34 = local_34 - 1, local_3c != 0) {
            if ((int)(local_c + uVar10) < (int)local_18) {
              iVar12 = local_2c << 2;
              do {
                local_2c = local_2c + 1;
                local_c = local_c + uVar10;
                local_14 = uVar10;
                if ((int)(local_28 - local_c) <= (int)uVar10) {
                  local_14 = local_28 - local_c;
                }
                local_8 = local_18 - local_c;
                uVar11 = 1 << ((byte)local_8 & 0x1f);
                if (local_3c < uVar11) {
                  iVar9 = uVar11 - (local_34 + 1);
                  local_1c = local_40;
                  while (local_8 = local_8 + 1, local_8 < local_14) {
                    local_1c = local_1c + 1;
                    if ((uint)(iVar9 * 2) <= *local_1c) break;
                    iVar9 = iVar9 * 2 - *local_1c;
                  }
                }
                local_14 = 1 << ((byte)local_8 & 0x1f);
                puVar3 = _malloc(local_14 * 8 + 8);
                if (puVar3 == (undefined4 *)0x0) {
                  if (local_2c != 0) {
                    FUN_00401564(local_110[0]);
                  }
                  return 0xfffffffe;
                }
                puVar8 = puVar3 + 2;
                *(uint **)((int)local_110 + iVar12 + 4) = puVar8;
                *param_6 = puVar8;
                DAT_00407420 = DAT_00407420 + local_14 + 1;
                *puVar3 = 0;
                if (iVar12 + 4 != 0) {
                  local_24 = puVar8;
                  *(uint *)((int)local_d0 + iVar12 + 4) = local_10;
                  local_20._0_3_ = CONCAT12((char)uVar10,(undefined2)local_20);
                  local_1c = puVar8;
                  local_20 = CONCAT13((byte)local_8 + '\x10',(undefined3)local_20);
                  local_8 = local_20;
                  puVar4 = (undefined4 *)
                           ((local_10 >> ((char)local_c - (char)uVar10 & 0x1fU)) * 8 +
                           *(int *)((int)local_110 + iVar12));
                  *puVar4 = puVar8;
                  puVar4[1] = local_20;
                }
                iVar12 = iVar12 + 4;
                param_6 = puVar3;
              } while ((int)(local_c + uVar10) < (int)local_18);
            }
            bVar6 = (char)local_18 - (byte)local_c;
            local_20._0_3_ = CONCAT12(bVar6,(undefined2)local_20);
            if (local_30 < local_590 + param_1) {
              uVar11 = *local_30;
              if (uVar11 < param_2) {
                uVar1 = CONCAT12(bVar6,(short)uVar11);
                local_20 = CONCAT13(0x10,uVar1);
                if (0xff < uVar11) {
                  local_20 = CONCAT13(0xf,uVar1);
                }
              }
              else {
                iVar12 = (uVar11 - param_2) * 2;
                local_20 = CONCAT13(*(undefined1 *)(iVar12 + param_5),
                                    CONCAT12(bVar6,*(undefined2 *)(iVar12 + param_4)));
              }
              local_30 = local_30 + 1;
            }
            else {
              local_20 = CONCAT13(0xff,(undefined3)local_20);
            }
            local_8 = 1 << (bVar6 & 0x1f);
            uVar11 = local_10 >> ((byte)local_c & 0x1f);
            if (uVar11 < local_14) {
              local_1c = puVar8 + uVar11 * 2;
              local_3c = local_8 * 8;
              do {
                uVar11 = uVar11 + local_8;
                local_48 = local_24;
                local_44 = local_20;
                local_38 = local_1c;
                *local_1c = (uint)local_24;
                local_1c[1] = local_20;
                local_1c = local_1c + local_8 * 2;
              } while (uVar11 < local_14);
            }
            uVar7 = 1 << ((char)local_18 - 1U & 0x1f);
            uVar11 = local_10 & uVar7;
            while (uVar11 != 0) {
              local_10 = local_10 ^ uVar7;
              uVar7 = uVar7 >> 1;
              uVar11 = local_10 & uVar7;
            }
            bVar6 = (byte)local_c & 0x1f;
            local_10 = local_10 ^ uVar7;
            puVar5 = local_d0 + local_2c;
            if (((1 << bVar6) - 1U & local_10) != *puVar5) {
              do {
                puVar5 = puVar5 + -1;
                local_c = local_c - uVar10;
                iVar12 = local_c;
                local_2c = local_2c + -1;
                bVar6 = (byte)local_c & 0x1f;
                local_c = iVar12;
              } while (((1 << bVar6) - 1U & local_10) != *puVar5);
            }
          }
          local_18 = local_18 + 1;
        } while ((int)local_18 <= (int)local_28);
      }
      if ((local_28 == 1) || (iVar14 == 0)) {
        uVar2 = 0;
      }
      else {
        uVar2 = 0xffffffff;
      }
    }
  }
  return uVar2;
}



void __cdecl FUN_00401564(int param_1)

{
  int *_Memory;
  
  while (param_1 != 0) {
    _Memory = (int *)(param_1 + -8);
    param_1 = *_Memory;
    _free(_Memory);
  }
  return;
}



undefined4 __cdecl FUN_00401583(int param_1,uint param_2,int param_3,uint param_4)

{
  byte bVar1;
  ushort uVar2;
  ushort uVar3;
  ushort uVar4;
  uint uVar5;
  int *piVar6;
  uint uVar7;
  uint uVar8;
  uint local_14;
  uint local_10;
  uint local_c;
  uint local_8;
  
  uVar2 = *(ushort *)(&DAT_00406178 + param_2 * 2);
  uVar3 = *(ushort *)(&DAT_00406178 + param_4 * 2);
  local_8 = DAT_00407458;
  local_c = DAT_0040744c;
  uVar8 = DAT_0040743c;
  while( true ) {
    while( true ) {
      if (DAT_0040737c != 0) {
        return 0xffffffff;
      }
      FUN_00401e0f(param_2,&local_8,&local_c);
      piVar6 = (int *)(param_1 + (local_8 & uVar2) * 8);
      bVar1 = *(byte *)(param_1 + 7 + (local_8 & uVar2) * 8);
      while (uVar5 = (uint)bVar1, 0x10 < uVar5) {
        if (uVar5 == 0xff) {
          return 0xffffffff;
        }
        FUN_00401e64((uint)*(byte *)((int)piVar6 + 6),&local_8,(int *)&local_c);
        FUN_00401e0f(uVar5 - 0x10,&local_8,&local_c);
        piVar6 = (int *)((*(ushort *)(&DAT_00406178 + (uVar5 - 0x10) * 2) & local_8) * 8 + *piVar6);
        bVar1 = *(byte *)((int)piVar6 + 7);
      }
      FUN_00401e64((uint)*(byte *)((int)piVar6 + 6),&local_8,(int *)&local_c);
      if (uVar5 != 0x10) break;
      *(char *)(DAT_00407428 + uVar8) = (char)piVar6[1];
      uVar8 = uVar8 + 1;
      if (uVar8 == 0x8000) {
        DAT_0040743c = uVar8;
        FUN_00401e75();
        uVar8 = 0;
      }
    }
    if (uVar5 == 0xf) break;
    FUN_00401e0f(uVar5,&local_8,&local_c);
    local_14 = (uint)*(ushort *)(piVar6 + 1) + (*(ushort *)(&DAT_00406178 + uVar5 * 2) & local_8);
    FUN_00401e64(uVar5,&local_8,(int *)&local_c);
    FUN_00401e0f(param_4,&local_8,&local_c);
    piVar6 = (int *)(param_3 + (local_8 & uVar3) * 8);
    bVar1 = *(byte *)(param_3 + 7 + (local_8 & uVar3) * 8);
    while (uVar5 = (uint)bVar1, 0x10 < uVar5) {
      if (uVar5 == 0xff) {
        return 0xffffffff;
      }
      FUN_00401e64((uint)*(byte *)((int)piVar6 + 6),&local_8,(int *)&local_c);
      FUN_00401e0f(uVar5 - 0x10,&local_8,&local_c);
      piVar6 = (int *)((*(ushort *)(&DAT_00406178 + (uVar5 - 0x10) * 2) & local_8) * 8 + *piVar6);
      bVar1 = *(byte *)((int)piVar6 + 7);
    }
    FUN_00401e64((uint)*(byte *)((int)piVar6 + 6),&local_8,(int *)&local_c);
    FUN_00401e0f(uVar5,&local_8,&local_c);
    uVar4 = *(ushort *)(piVar6 + 1);
    uVar7 = *(ushort *)(&DAT_00406178 + uVar5 * 2) & local_8;
    FUN_00401e64(uVar5,&local_8,(int *)&local_c);
    local_10 = (uVar8 - uVar7) - (uint)uVar4;
    do {
      local_10 = local_10 & 0x7fff;
      uVar5 = uVar8;
      if (uVar8 < local_10) {
        uVar5 = local_10;
      }
      uVar7 = 0x8000 - uVar5;
      if (local_14 < 0x8000 - uVar5) {
        uVar7 = local_14;
      }
      local_14 = local_14 - uVar7;
      do {
        uVar5 = local_10 + 1;
        *(undefined1 *)(DAT_00407428 + uVar8) = *(undefined1 *)(DAT_00407428 + local_10);
        uVar8 = uVar8 + 1;
        uVar7 = uVar7 - 1;
        local_10 = uVar5;
      } while (uVar7 != 0);
      if (uVar8 == 0x8000) {
        DAT_0040743c = uVar8;
        FUN_00401e75();
        uVar8 = 0;
      }
    } while (local_14 != 0);
  }
  DAT_0040743c = uVar8;
  DAT_0040744c = local_c;
  DAT_00407458 = local_8;
  return 0;
}



undefined4 FUN_00401810(void)

{
  undefined4 uVar1;
  int iVar2;
  uint uVar3;
  uint local_c;
  uint local_8;
  
  iVar2 = DAT_0040743c;
  local_8 = DAT_00407458;
  local_c = DAT_0040744c;
  FUN_00401e64(DAT_0040744c & 7,&local_8,(int *)&local_c);
  FUN_00401e0f(0x10,&local_8,&local_c);
  uVar3 = local_8 & 0xffff;
  FUN_00401e64(0x10,&local_8,(int *)&local_c);
  FUN_00401e0f(0x10,&local_8,&local_c);
  if ((~local_8 & 0xffff) == uVar3) {
    FUN_00401e64(0x10,&local_8,(int *)&local_c);
    for (; uVar3 != 0; uVar3 = uVar3 - 1) {
      if (DAT_0040737c != 0) {
        return 0xffffffff;
      }
      FUN_00401e0f(8,&local_8,&local_c);
      *(undefined1 *)(DAT_00407428 + iVar2) = (undefined1)local_8;
      iVar2 = iVar2 + 1;
      if (iVar2 == 0x8000) {
        DAT_0040743c = iVar2;
        FUN_00401e75();
        iVar2 = 0;
      }
      FUN_00401e64(8,&local_8,(int *)&local_c);
    }
    uVar1 = 0;
    DAT_0040743c = iVar2;
    DAT_0040744c = local_c;
    DAT_00407458 = local_8;
  }
  else {
    uVar1 = 0xffffffff;
  }
  return uVar1;
}



int FUN_00401928(void)

{
  int iVar1;
  int iVar2;
  undefined4 *puVar3;
  int *piVar4;
  int local_494 [144];
  undefined4 local_254 [112];
  undefined4 local_94 [24];
  undefined4 local_34 [8];
  uint local_14;
  uint local_10;
  int local_c;
  int local_8;
  
  piVar4 = local_494;
  for (iVar2 = 0x90; iVar2 != 0; iVar2 = iVar2 + -1) {
    *piVar4 = 8;
    piVar4 = piVar4 + 1;
  }
  puVar3 = local_254;
  for (iVar2 = 0x70; iVar2 != 0; iVar2 = iVar2 + -1) {
    *puVar3 = 9;
    puVar3 = puVar3 + 1;
  }
  puVar3 = local_94;
  for (iVar2 = 0x18; iVar2 != 0; iVar2 = iVar2 + -1) {
    *puVar3 = 7;
    puVar3 = puVar3 + 1;
  }
  puVar3 = local_34;
  for (iVar2 = 8; iVar2 != 0; iVar2 = iVar2 + -1) {
    *puVar3 = 8;
    puVar3 = puVar3 + 1;
  }
  local_10 = 7;
  iVar2 = FUN_00401177(0x120,0x101,local_494,0x406078,0x4060b8,&local_8,&local_10);
  if (iVar2 == 0) {
    piVar4 = local_494;
    for (iVar2 = 0x1e; iVar2 != 0; iVar2 = iVar2 + -1) {
      *piVar4 = 5;
      piVar4 = piVar4 + 1;
    }
    local_14 = 5;
    iVar2 = FUN_00401177(0x1e,0,local_494,0x4060f8,0x406138,&local_c,&local_14);
    if (iVar2 < -1) {
      FUN_00401564(local_8);
    }
    else {
      iVar1 = FUN_00401583(local_8,local_10,local_c,local_14);
      iVar2 = -1;
      if (iVar1 == 0) {
        FUN_00401564(local_8);
        FUN_00401564(local_c);
        iVar2 = 0;
      }
    }
  }
  return iVar2;
}



int FUN_00401a37(void)

{
  int iVar1;
  uint uVar2;
  int iVar3;
  uint uVar4;
  uint uVar5;
  int *piVar6;
  uint *puVar7;
  uint local_520 [316];
  uint local_30;
  uint local_2c;
  uint local_28;
  uint local_24;
  uint local_20;
  uint local_1c;
  uint local_18;
  int local_14;
  int local_10;
  uint local_c;
  uint local_8;
  
  local_8 = DAT_00407458;
  local_c = DAT_0040744c;
  FUN_00401e0f(5,&local_8,&local_c);
  local_20 = (local_8 & 0x1f) + 0x101;
  FUN_00401e64(5,&local_8,(int *)&local_c);
  FUN_00401e0f(5,&local_8,&local_c);
  local_28 = (local_8 & 0x1f) + 1;
  FUN_00401e64(5,&local_8,(int *)&local_c);
  FUN_00401e0f(4,&local_8,&local_c);
  uVar4 = (local_8 & 0xf) + 4;
  FUN_00401e64(4,&local_8,(int *)&local_c);
  if ((local_20 < 0x11f) && (local_28 < 0x1f)) {
    uVar2 = 0;
    if (uVar4 != 0) {
      piVar6 = &DAT_00406028;
      uVar5 = uVar4;
      do {
        FUN_00401e0f(3,&local_8,&local_c);
        iVar1 = *piVar6;
        piVar6 = piVar6 + 1;
        local_520[iVar1] = local_8 & 7;
        FUN_00401e64(3,&local_8,(int *)&local_c);
        uVar5 = uVar5 - 1;
        uVar2 = uVar4;
      } while (uVar5 != 0);
    }
    if (uVar2 < 0x13) {
      piVar6 = &DAT_00406028 + uVar2;
      do {
        iVar1 = *piVar6;
        piVar6 = piVar6 + 1;
        local_520[iVar1] = 0;
      } while (piVar6 < &DAT_00406074);
    }
    local_18 = 7;
    iVar1 = FUN_00401177(0x13,0x13,(int *)local_520,0,0,&local_10,&local_18);
    if (iVar1 != 0) {
      if (iVar1 == -1) {
        FUN_00401564(local_10);
        return -1;
      }
      return iVar1;
    }
    local_1c = local_20 + local_28;
    uVar4 = 0;
    local_30 = (uint)*(ushort *)(&DAT_00406178 + local_18 * 2);
    local_24 = 0;
    if (local_1c != 0) {
      do {
        FUN_00401e0f(local_18,&local_8,&local_c);
        local_14 = (local_8 & local_30) * 8 + local_10;
        FUN_00401e64((uint)*(byte *)(local_14 + 6),&local_8,(int *)&local_c);
        uVar2 = (uint)*(ushort *)(local_14 + 4);
        if (uVar2 < 0x10) {
          local_520[uVar4] = uVar2;
          uVar4 = uVar4 + 1;
          local_24 = uVar2;
        }
        else if (uVar2 == 0x10) {
          FUN_00401e0f(2,&local_8,&local_c);
          iVar1 = (local_8 & 3) + 3;
          FUN_00401e64(2,&local_8,(int *)&local_c);
          uVar2 = local_24;
          if (local_1c < uVar4 + iVar1) {
            return -1;
          }
          if (iVar1 != 0) {
            puVar7 = local_520 + uVar4;
            for (iVar3 = iVar1; iVar3 != 0; iVar3 = iVar3 + -1) {
              *puVar7 = uVar2;
              puVar7 = puVar7 + 1;
            }
            uVar4 = uVar4 + iVar1;
          }
        }
        else {
          if (uVar2 == 0x11) {
            FUN_00401e0f(3,&local_8,&local_c);
            iVar1 = (local_8 & 7) + 3;
            FUN_00401e64(3,&local_8,(int *)&local_c);
            if (local_1c < uVar4 + iVar1) {
              return -1;
            }
          }
          else {
            FUN_00401e0f(7,&local_8,&local_c);
            iVar1 = (local_8 & 0x7f) + 0xb;
            FUN_00401e64(7,&local_8,(int *)&local_c);
            if (local_1c < uVar4 + iVar1) {
              return -1;
            }
          }
          if (iVar1 != 0) {
            puVar7 = local_520 + uVar4;
            for (iVar3 = iVar1; iVar3 != 0; iVar3 = iVar3 + -1) {
              *puVar7 = 0;
              puVar7 = puVar7 + 1;
            }
            uVar4 = uVar4 + iVar1;
          }
          local_24 = 0;
        }
      } while (uVar4 < local_1c);
    }
    FUN_00401564(local_10);
    local_18 = DAT_0040619c;
    DAT_00407458 = local_8;
    DAT_0040744c = local_c;
    iVar1 = FUN_00401177(local_20,0x101,(int *)local_520,0x406078,0x4060b8,&local_10,&local_18);
    if (iVar1 != 0) {
      if (iVar1 == -1) {
        FUN_00401564(local_10);
        return -1;
      }
      return iVar1;
    }
    local_2c = DAT_004061a0;
    iVar1 = FUN_00401177(local_28,0,(int *)(local_520 + local_20),0x4060f8,0x406138,&local_14,
                         &local_2c);
    if (iVar1 != 0) {
      FUN_00401564(local_10);
      if (iVar1 == -1) {
        FUN_00401564(local_14);
        return -1;
      }
      return iVar1;
    }
    iVar1 = FUN_00401583(local_10,local_18,local_14,local_2c);
    if (iVar1 == 0) {
      FUN_00401564(local_10);
      FUN_00401564(local_14);
      return 0;
    }
  }
  return -1;
}



void __cdecl FUN_00401e0f(uint param_1,uint *param_2,uint *param_3)

{
  uint uVar1;
  
  uVar1 = *param_3;
  while (uVar1 < param_1) {
    if (DAT_00407434 < DAT_00407438) {
      uVar1 = (uint)*(byte *)(DAT_00407434 + (int)lpBuffer_00407448);
      DAT_00407434 = DAT_00407434 + 1;
    }
    else {
      uVar1 = FUN_00401f09();
    }
    *param_2 = *param_2 | (uVar1 & 0xff) << ((byte)*param_3 & 0x1f);
    uVar1 = *param_3 + 8;
    *param_3 = uVar1;
  }
  return;
}



void __cdecl FUN_00401e64(int param_1,uint *param_2,int *param_3)

{
  *param_2 = *param_2 >> ((byte)param_1 & 0x1f);
  *param_3 = *param_3 - param_1;
  return;
}



// WARNING: Globals starting with '_' overlap smaller symbols at the same address

void FUN_00401e75(void)

{
  size_t sVar1;
  size_t sVar2;
  
  sVar1 = DAT_0040743c;
  if (DAT_0040743c != 0) {
    if (DAT_004073e8 == (void *)0x0) {
      if ((lpBuffer_00407394._2_1_ & 1) != 0) {
        _DAT_00407374 = _DAT_00407374 + DAT_0040743c;
      }
      sVar2 = (*DAT_00407400)(DAT_00407440,DAT_00407428,DAT_0040743c);
      if (sVar2 != sVar1) {
        DAT_0040737c = 1;
        DAT_00407380 = 1;
      }
    }
    else {
      FID_conflict__memcpy(DAT_004073e8,DAT_00407428,DAT_0040743c);
      DAT_004073e8 = (void *)((int)DAT_004073e8 + DAT_0040743c);
    }
    DAT_00407444 = FUN_0040219e(DAT_00407428,DAT_0040743c);
    DAT_0040743c = 0;
  }
  return;
}



// WARNING: Globals starting with '_' overlap smaller symbols at the same address

uint FUN_00401f09(void)

{
  UINT UVar1;
  int iVar2;
  UINT uBytes;
  
  if (DAT_0040737c == 0) {
    _DAT_004062b0 = 0;
    uBytes = 0x8000;
    if ((int)DAT_00407450 < 0x8001) {
      uBytes = DAT_00407450;
    }
    UVar1 = _lread(hFile_00407424,lpBuffer_00407448,uBytes);
    if ((UVar1 != 0) && (UVar1 != 0xffffffff)) {
LAB_00401faa:
      DAT_00407450 = DAT_00407450 - UVar1;
      DAT_00407368 = DAT_00407368 + UVar1;
      DAT_00407434 = 1;
      DAT_00407438 = UVar1;
      return (uint)*(byte *)lpBuffer_00407448;
    }
    if ((DAT_00407350 != (code *)0x0) && (iVar2 = (*DAT_00407350)(DAT_00407450,uBytes), iVar2 == 0))
    {
      hFile_00407424 = hFile_00407378;
      _llseek(hFile_00407378,DAT_00407368 - _DAT_0040736c,0);
      UVar1 = _lread(hFile_00407424,lpBuffer_00407448,uBytes);
      if ((UVar1 != 0) && (UVar1 != 0xffffffff)) goto LAB_00401faa;
    }
  }
  return 0xffffffff;
}



// WARNING: Globals starting with '_' overlap smaller symbols at the same address

int FUN_00401fd7(HFILE param_1,undefined4 param_2,int param_3,uint *param_4)

{
  int iVar1;
  uint uVar2;
  uint local_1c [3];
  ushort local_10;
  uint local_c;
  uint local_8;
  
  DAT_00407450 = param_3;
  if (param_3 != 0) {
    if ((lpBuffer_00407394._1_1_ & 1) == 0) {
      DAT_00407450 = param_3 + -4;
    }
    else {
      if ((param_1 == -1) && (DAT_00407350 != (code *)0x0)) {
        iVar1 = (*DAT_00407350)(0,0);
        param_1 = hFile_00407378;
        if (iVar1 != 0) {
          return 0;
        }
        _llseek(hFile_00407378,DAT_00407368 - _DAT_0040736c,0);
      }
      _llseek(param_1,0xe,1);
      _lread(param_1,local_1c,0x10);
      local_8 = local_1c[0];
      _llseek(param_1,(uint)local_10,1);
      DAT_00407450 = DAT_00407450 - (local_10 + 0x1e);
    }
    if (DAT_00407450 != 0) {
      DAT_00407444 = FUN_0040219e((byte *)0x0,0);
      uVar2 = 0;
      DAT_00407440 = param_2;
      DAT_0040744c = 0;
      DAT_00407438 = 0;
      DAT_00407434 = 0;
      DAT_0040743c = 0;
      DAT_00407458 = 0;
      hFile_00407424 = param_1;
      do {
        if (DAT_004073fc != (code *)0x0) {
          (*DAT_004073fc)(1);
        }
        DAT_00407420 = 0;
        iVar1 = FUN_004010c7(&local_c);
        if (iVar1 != 0) {
          if (DAT_0040737c == 0) {
            DAT_00407380 = 2;
            return iVar1;
          }
          return iVar1;
        }
        if (uVar2 < DAT_00407420) {
          uVar2 = DAT_00407420;
        }
      } while (((local_c == 0) && (DAT_0040737c == 0)) && (DAT_00407380 == '\0'));
      if (7 < DAT_0040744c) {
        DAT_00407434 = DAT_00407434 - (DAT_0040744c >> 3);
        DAT_0040744c = DAT_0040744c + (DAT_0040744c >> 3) * -8;
      }
      FUN_00401e75();
      if ((lpBuffer_00407394._1_1_ & 1) == 0) {
        _lread(hFile_00407424,&local_8,4);
      }
      if (((DAT_00407444 != local_8) && (DAT_0040737c == 0)) && (DAT_00407380 == '\0')) {
        DAT_00407380 = '\x02';
      }
      if (param_4 != (uint *)0x0) {
        *param_4 = local_8;
      }
    }
  }
  return 0;
}



uint FUN_0040219e(byte *param_1,int param_2)

{
  byte bVar1;
  
  if (param_1 == (byte *)0x0) {
    DAT_00406020 = 0xffffffff;
  }
  else {
    for (; param_2 != 0; param_2 = param_2 + -1) {
      bVar1 = *param_1;
      param_1 = param_1 + 1;
      DAT_00406020 = *(uint *)(DAT_00407430 + ((bVar1 ^ DAT_00406020) & 0xff) * 4) ^
                     DAT_00406020 >> 8;
    }
  }
  return ~DAT_00406020;
}



// WARNING: Globals starting with '_' overlap smaller symbols at the same address

/**
 * Main game initialisation routine.
 * Loads the executable's main DLL (the actual game logic), sets up global
 * structures, processes command‑line flags, and ultimately launches the main
 * entry point obtained via `GetProcAddress` (`s_WiseMain`).  Returns a status
 * code that becomes the process exit code.
 */
unsigned int GameInit(HMODULE param_1,int param_2,char *param_3)

{
  char cVar1;
  ATOM AVar2;
  char *pcVar3;
  HFILE HVar4;
  uint uVar5;
  undefined2 extraout_var;
  LONG lOffset;
  LONG LVar6;
  HMODULE hModule;
  int iVar7;
  undefined1 local_3a4 [128];
  CHAR local_324 [256];
  _OSVERSIONINFOA local_224;
  CHAR local_190 [128];
  CHAR local_110 [256];
  int local_10;
  uint local_c;
  byte local_5;
  
  SetErrorMode(4);
  if ((*param_3 == '/') && ((param_3[1] == 'S' || (param_3[1] == 's')))) {
    DAT_00407390 = 1;
  }
  GetModuleFileNameA(param_1,local_324,0x100);
  cVar1 = *param_3;
  pcVar3 = param_3;
  while ((cVar1 != '\0' && (*pcVar3 != '\x7f'))) {
    pcVar3 = pcVar3 + 1;
    cVar1 = *pcVar3;
  }
  if (*pcVar3 != '\0') {
    iVar7 = 0;
    *pcVar3 = '\0';
    pcVar3 = pcVar3 + 1;
    cVar1 = *pcVar3;
    while ((cVar1 != '\0' && (cVar1 = *pcVar3, cVar1 != ' '))) {
      pcVar3 = pcVar3 + 1;
      iVar7 = cVar1 + -0x30 + iVar7 * 10;
      cVar1 = *pcVar3;
    }
    DAT_004061b0 = DAT_004061b0 + iVar7;
    lstrcpyA(local_324,pcVar3 + 1);
  }
  hFile_00407378 = _lopen(local_324,0);
  if (hFile_00407378 < 0) {
    FUN_00402bde();
    local_c = 0;
  }
  else {
    FUN_00401000();
    _DAT_00407370 = DAT_004061b0;
    DAT_00407368 = DAT_004061b0;
    _llseek(hFile_00407378,DAT_004061b0,0);
    _lread(hFile_00407378,&local_5,1);
    if (local_5 != 0) {
      _lread(hFile_00407378,local_110,(uint)local_5);
      _lread(hFile_00407378,&local_c,4);
      HVar4 = _lopen(local_110,0);
      if (HVar4 < 0) {
        local_110[0] = '\0';
      }
      else {
        uVar5 = _llseek(HVar4,0,2);
        if (uVar5 != local_c) {
          local_110[0] = '\0';
        }
        _lclose(HVar4);
      }
    }
    _lread(hFile_00407378,&lpBuffer_00407394,4);
    _lread(hFile_00407378,&lpBuffer_00407410,0xc);
    _lread(hFile_00407378,&lpBuffer_004073d8,8);
    _lread(hFile_00407378,&lpBuffer_004073a0,0x38);
    if (((uint)lpBuffer_00407394 & 0x1000) != 0) {
      DAT_00407398 = 1;
    }
    if (((((uint)lpBuffer_00407394 & 0x80) != 0) && (DAT_00407390 == 0)) &&
       (((byte)lpBuffer_00407394 & 3) != 2)) {
      FUN_00402bf7();
    }
    if ((param_2 == 0) && (AVar2 = FUN_0040267a(param_1), CONCAT22(extraout_var,AVar2) == 0)) {
      local_c = 0;
    }
    else {
      iVar7 = FUN_004026dc(param_1);
      if (iVar7 == 0) {
        local_c = 0;
      }
      else {
        _DAT_00407360 = hWnd_0040734c;
        _DAT_00407364 = param_1;
        if (DAT_004073d4 != 0) {
          lOffset = _llseek(hFile_00407378,0,1);
          LVar6 = _llseek(hFile_00407378,0,2);
          _llseek(hFile_00407378,lOffset,0);
          if (LVar6 != DAT_004073d4) {
            FUN_00402bde();
            return 0;
          }
        }
        _DAT_004073ec = FUN_00401fd7;
        _DAT_004073f0 = FUN_0040219e;
        _DAT_004073e0 = GlobalAlloc(2,(int)lpBuffer_004073a0 + 1);
        _DAT_004073e4 = GlobalLock(_DAT_004073e0);
        DAT_00407400 = _StubFileWrite_12;
        DAT_004073e8 = _DAT_004073e4;
        FUN_00401fd7(hFile_00407378,0,DAT_004073a4,(uint *)0x0);
        DAT_004073e8 = (LPVOID)0x0;
        if (local_5 == 0) {
          FUN_00402b8f(local_110);
          HVar4 = _lcreat(local_110,0);
          _lclose(HVar4);
          HVar4 = _lopen(local_110,2);
          if (HVar4 < 0) {
            FUN_00402bde();
            return 0;
          }
          FUN_00401fd7(hFile_00407378,HVar4,DAT_004073a8,(uint *)0x0);
          _lclose(HVar4);
        }
        local_10 = 1;
        local_190[0] = '\0';
        if (DAT_00407380 == '\0') {
          hModule = LoadLibraryA(local_110);
          if (hModule != (HMODULE)0x0) {
            DAT_0040741c = GetProcAddress(hModule,s_WiseMain_00406268);
            DAT_004073fc = GetProcAddress(hModule,s_UpdateScreen_00406258);
            DAT_004073f8 = GetProcAddress(hModule,s_DisplayGraphics_00406248);
            DAT_00407350 = GetProcAddress(hModule,s_DiskPrompt_0040623c);
            DAT_00407400 = GetProcAddress(hModule,s_FileWrite_00406230);
            DAT_00407408 = GetProcAddress(hModule,s_HandleFtp_00406224);
          }
          if (DAT_0040741c == (FARPROC)0x0) {
            pcVar3 = s_Demo_installations_only_run_on_t_004061d8;
            if (local_5 == 0) {
              pcVar3 = s_System_DLLs_corrupt_or_missing__004061b8;
            }
            MessageBoxA(hWnd_0040734c,pcVar3,s_Install_0040621c,0);
          }
          else {
            local_c = (*DAT_0040741c)(&DAT_00407360,param_3,&local_10,local_190,local_3a4);
            local_c = local_c & 0xffff;
            FreeLibrary(hModule);
          }
        }
        else {
          FUN_00402bde();
        }
        FUN_00401088();
        if (local_5 == 0) {
          FUN_00403160(local_110);
        }
        if (DAT_00407404 != (HGDIOBJ)0x0) {
          DeleteObject(DAT_00407404);
        }
        if (local_10 != 1) {
          local_224.dwOSVersionInfoSize = 0x94;
          GetVersionExA(&local_224);
          ExitWindowsEx((local_224.dwPlatformId == 2) - 1 & 2,0);
        }
        if (local_190[0] != '\0') {
          WinExec(local_190,5);
        }
      }
    }
  }
  return local_c;
}



ATOM __cdecl FUN_0040267a(HINSTANCE param_1)

{
  ATOM AVar1;
  WNDCLASSA local_2c;
  
  local_2c.style = 0;
  local_2c.cbClsExtra = 0;
  local_2c.cbWndExtra = 0;
  local_2c.lpfnWndProc = _MainWndProc_16;
  local_2c.hInstance = param_1;
  local_2c.hIcon = LoadIconA(param_1,&lpIconName_0000006c);
  local_2c.hCursor = LoadCursorA((HINSTANCE)0x0,&lpCursorName_00007f00);
  local_2c.hbrBackground = GetStockObject(0);
  local_2c.lpszMenuName = (LPCSTR)0x0;
  local_2c.lpszClassName = lpClassName_004061b4;
  AVar1 = RegisterClassA(&local_2c);
  return AVar1;
}



undefined4 __cdecl FUN_004026dc(HINSTANCE param_1)

{
  HDC hdc;
  int nCmdShow;
  
  hWnd_0040734c =
       CreateWindowExA(0,lpClassName_004061b4,(LPCSTR)&lpWindowName_00406274,
                       (-(uint)(((uint)lpBuffer_00407394 & 8) == 0) & 0x7f370000) + 0xcd0000,
                       -0x80000000,0,-0x80000000,0,(HWND)0x0,(HMENU)0x0,param_1,(LPVOID)0x0);
  if (hWnd_0040734c == (HWND)0x0) {
    return 0;
  }
  hdc = GetDC(hWnd_0040734c);
  w_00407384 = GetDeviceCaps(hdc,8);
  DAT_00407388 = GetDeviceCaps(hdc,10);
  ReleaseDC(hWnd_0040734c,hdc);
  if (DAT_00407390 == 0) {
    if (((uint)lpBuffer_00407394 & 3) == 0) {
      nCmdShow = 3;
LAB_004027bc:
      ShowWindow(hWnd_0040734c,nCmdShow);
    }
    else if (((uint)lpBuffer_00407394 & 3) == 1) {
      DAT_00407388 = (int)(DAT_00407388 * 3 + (DAT_00407388 * 3 >> 0x1f & 3U)) >> 2;
      SetWindowPos(hWnd_0040734c,(HWND)0x0,0,0,w_00407384,DAT_00407388,4);
      nCmdShow = 5;
      goto LAB_004027bc;
    }
    if ((DAT_00407390 == 0) && (((byte)lpBuffer_00407394 & 3) != 2)) goto LAB_004027f5;
  }
  SetWindowPos(hWnd_0040734c,(HWND)0x0,0,0,w_00407384,DAT_00407388,4);
LAB_004027f5:
  FUN_0040280d();
  UpdateWindow(hWnd_0040734c);
  return 1;
}



void FUN_0040280d(void)

{
  tagRECT local_10;
  
  GetClientRect(hWnd_0040734c,&local_10);
  w_00407384 = local_10.right;
  DAT_00407388 = local_10.bottom;
  return;
}



// WARNING: Globals starting with '_' overlap smaller symbols at the same address

UINT _MainWndProc_16(HWND param_1,uint param_2,HWND param_3,int param_4)

{
  byte *pbVar1;
  UINT UVar2;
  HDC pHVar3;
  int iVar4;
  HBRUSH h;
  HGDIOBJ h_00;
  HPALETTE pHVar5;
  COLORREF color;
  tagPAINTSTRUCT local_6c;
  byte local_2c [4];
  byte local_28;
  byte local_24;
  int local_1c;
  int local_14;
  HPALETTE local_10;
  uint local_c;
  ushort local_6;
  
                    // 0x2839  1  _MainWndProc@16
  if (param_2 < 6) {
    if (param_2 == 5) {
      InvalidateRect(param_1,(RECT *)0x0,1);
      return 0;
    }
    if (param_2 != 2) {
LAB_004028be:
      UVar2 = DefWindowProcA(param_1,param_2,(WPARAM)param_3,param_4);
      return UVar2;
    }
    PostQuitMessage(0);
  }
  else if (param_2 < 0x15) {
    if (param_2 == 0x14) {
      return 1;
    }
    if (param_2 != 0xf) goto LAB_004028be;
    pHVar3 = BeginPaint(param_1,&local_6c);
    FUN_0040280d();
    if (DAT_00407404 != (HPALETTE)0x0) {
      local_10 = SelectPalette(pHVar3,DAT_00407404,0);
      RealizePalette(pHVar3);
    }
    if ((DAT_00407398 & 3) == 0) {
      local_14 = -1;
      local_c = 0;
      do {
        local_1c = local_14;
        local_6 = 0;
        local_14 = (int)((local_c + 1) * DAT_00407388) / 0x60;
        do {
          pbVar1 = local_2c + (uint)local_6 * 4;
          iVar4 = (int)((int)(short)(&DAT_00407416)[local_6] * local_c) / 0x5f +
                  (int)*(short *)(&lpBuffer_00407410 + (uint)local_6 * 2);
          *(int *)pbVar1 = iVar4;
          if (iVar4 < 0) {
            pbVar1[0] = 0;
            pbVar1[1] = 0;
            pbVar1[2] = 0;
            pbVar1[3] = 0;
          }
          if (0xff < *(int *)pbVar1) {
            pbVar1[0] = 0xff;
            pbVar1[1] = 0;
            pbVar1[2] = 0;
            pbVar1[3] = 0;
          }
          local_6 = local_6 + 1;
        } while (local_6 < 3);
        if (DAT_00407404 == (HPALETTE)0x0) {
          color = (uint)local_24 << 0x10 | (uint)local_28 << 8 | (uint)local_2c[0];
        }
        else {
          color = local_c & 0xffff | 0x1000000;
        }
        local_c = local_c + 1;
        h = CreateSolidBrush(color);
        h_00 = SelectObject(pHVar3,h);
        PatBlt(pHVar3,0,local_1c,w_00407384,local_14 - local_1c,0xf00021);
        SelectObject(pHVar3,h_00);
        DeleteObject(h);
      } while ((int)local_c < 0x60);
    }
    if (DAT_00407404 != (HPALETTE)0x0) {
      SelectPalette(pHVar3,local_10,1);
    }
    if (DAT_004073f8 != (code *)0x0) {
      (*DAT_004073f8)(param_1,pHVar3);
    }
    EndPaint(param_1,&local_6c);
  }
  else if (param_2 == 0x112) {
    if (param_3 != (HWND)0xf060) {
      UVar2 = DefWindowProcA(param_1,0x112,(WPARAM)param_3,param_4);
      return UVar2;
    }
    DAT_0040737c = 1;
  }
  else {
    if (param_2 != 0x113) {
      if (param_2 != 0x30f) {
        if (param_2 != 0x311) {
          if (0x400 < param_2) {
            if (param_2 < 0x403) {
              if (DAT_00407408 == (code *)0x0) {
                return 0;
              }
              (*DAT_00407408)(param_2,param_3,param_4);
              return 0;
            }
            if (param_2 == 0x4c8) {
              if (param_4 != 0x20d) {
                return 0;
              }
              if ((DAT_00407398 & 4) == 0) {
                UVar2 = 0x10;
              }
              else {
                UVar2 = 0x806;
              }
              SendMessageA(param_3,UVar2,0,0);
              return 0;
            }
          }
          goto LAB_004028be;
        }
        if (param_3 == param_1) {
          return 0;
        }
      }
      pHVar5 = DAT_0040739c;
      if ((DAT_0040739c == (HPALETTE)0x0) && (pHVar5 = DAT_00407404, DAT_00407404 == (HPALETTE)0x0))
      {
        return 0;
      }
      pHVar3 = GetDC(param_1);
      pHVar5 = SelectPalette(pHVar3,pHVar5,0);
      UVar2 = RealizePalette(pHVar3);
      if (UVar2 != 0) {
        InvalidateRect(param_1,(RECT *)0x0,1);
      }
      SelectPalette(pHVar3,pHVar5,1);
      RealizePalette(pHVar3);
      ReleaseDC(param_1,pHVar3);
      return UVar2;
    }
    if (param_3 == (HWND)0x2069) {
      _DAT_0040738c = 0;
    }
    else {
      (*DAT_004073fc)(0);
    }
  }
  return 0;
}



void __cdecl FUN_00402b8f(LPSTR param_1)

{
  int iVar1;
  uint uVar2;
  char *pcVar3;
  
  GetWindowsDirectoryA(param_1,0x100);
  iVar1 = lstrlenA(param_1);
  pcVar3 = param_1 + iVar1 + -1;
  uVar2 = 0;
  if (*pcVar3 != '\\') {
    pcVar3 = pcVar3 + 1;
  }
  do {
    wsprintfA(pcVar3,s___GLC_04x_TMP_00406278,uVar2);
    iVar1 = FUN_00403190(param_1,0);
    uVar2 = (uint)(ushort)((short)uVar2 + 1);
  } while (iVar1 == 0);
  return;
}



void FUN_00402bde(void)

{
  MessageBoxA(hWnd_0040734c,s_Corrupt_installation_detected__00406288,s_Install_0040621c,0);
  return;
}



void FUN_00402bf7(void)

{
  int *piVar1;
  HPALETTE ho;
  HDC hdc;
  int iVar2;
  int iVar3;
  HGLOBAL pvVar4;
  LOGPALETTE *plpal;
  short sVar5;
  short local_e;
  int local_c;
  BYTE local_8;
  BYTE local_4;
  
  if (((DAT_00407416 != 0) || (DAT_00407418 != 0)) || (DAT_0040741a != 0)) {
    hdc = GetDC(hWnd_0040734c);
    iVar2 = GetDeviceCaps(hdc,0xc);
    iVar3 = GetDeviceCaps(hdc,0xe);
    if (7 < (short)((short)iVar2 * (short)iVar3)) {
      pvVar4 = GlobalAlloc(0x42,0x184);
      plpal = GlobalLock(pvVar4);
      plpal->palNumEntries = 0x60;
      plpal->palVersion = 0x300;
      local_e = 0;
      do {
        sVar5 = 0;
        do {
          piVar1 = &local_c + sVar5;
          iVar2 = ((int)(&DAT_00407416)[sVar5] * (int)local_e) / 0x5f +
                  (int)*(short *)(&lpBuffer_00407410 + sVar5 * 2);
          *piVar1 = iVar2;
          if (iVar2 < 0) {
            *piVar1 = 0;
          }
          if (0xff < *piVar1) {
            *piVar1 = 0xff;
          }
          sVar5 = sVar5 + 1;
        } while (sVar5 < 3);
        iVar2 = (int)local_e;
        local_e = local_e + 1;
        plpal->palPalEntry[iVar2].peRed = (BYTE)local_c;
        plpal->palPalEntry[iVar2].peGreen = local_8;
        plpal->palPalEntry[iVar2].peBlue = local_4;
        plpal->palPalEntry[iVar2].peFlags = '\0';
        ho = DAT_00407404;
      } while (local_e < 0x60);
      DAT_00407404 = CreatePalette(plpal);
      pvVar4 = GlobalHandle(plpal);
      GlobalFree(pvVar4);
      SelectPalette(hdc,DAT_00407404,0);
      if (ho != (HPALETTE)0x0) {
        DeleteObject(ho);
      }
      RealizePalette(hdc);
    }
    ReleaseDC(hWnd_0040734c,hdc);
  }
  return;
}



void _StubFileWrite_12(HFILE param_1,LPCCH param_2,UINT param_3)

{
                    // 0x2d52  2  _StubFileWrite@12
  _lwrite(param_1,param_2,param_3);
  return;
}



// Library Function - Single Match
//  _malloc
// 
// Library: Visual Studio 1998 Release

void * __cdecl _malloc(size_t _Size)

{
  void *pvVar1;
  
  pvVar1 = __nh_malloc(_Size,DAT_00406310);
  return pvVar1;
}



// Library Function - Single Match
//  __nh_malloc
// 
// Library: Visual Studio 1998 Release

void * __cdecl __nh_malloc(size_t _Size,int _NhFlag)

{
  void *pvVar1;
  int iVar2;
  
  if (0xffffffe0 < _Size) {
    return (void *)0x0;
  }
  if (_Size == 0) {
    _Size = 1;
  }
  do {
    pvVar1 = (void *)0x0;
    if (_Size < 0xffffffe1) {
      pvVar1 = __heap_alloc(_Size);
    }
    if (pvVar1 != (void *)0x0) {
      return pvVar1;
    }
    if (_NhFlag == 0) {
      return (void *)0x0;
    }
    iVar2 = __callnewh(_Size);
  } while (iVar2 != 0);
  return (void *)0x0;
}



// Library Function - Single Match
//  __heap_alloc
// 
// Library: Visual Studio 1998 Release

void * __cdecl __heap_alloc(size_t _Size)

{
  undefined *puVar1;
  LPVOID pvVar2;
  uint dwBytes;
  
  dwBytes = _Size + 0xf & 0xfffffff0;
  if ((dwBytes <= DAT_00406b34) &&
     (puVar1 = ___sbh_alloc_block(_Size + 0xf >> 4), puVar1 != (undefined *)0x0)) {
    return puVar1;
  }
  pvVar2 = HeapAlloc(DAT_00407564,0,dwBytes);
  return pvVar2;
}



// Library Function - Single Match
//  _free
// 
// Library: Visual Studio 1998 Release

void __cdecl _free(void *_Memory)

{
  char *pcVar1;
  uint local_8;
  int local_4;
  
  if (_Memory != (void *)0x0) {
    pcVar1 = (char *)___sbh_find_block(_Memory,&local_4,&local_8);
    if (pcVar1 != (char *)0x0) {
      ___sbh_free_block(local_4,local_8,pcVar1);
      return;
    }
    HeapFree(DAT_00407564,0,_Memory);
  }
  return;
}



// Library Function - Single Match
//  _memset
// 
// Libraries: Visual Studio 1998 Debug, Visual Studio 1998 Release

void * __cdecl _memset(void *_Dst,int _Val,size_t _Size)

{
  uint uVar1;
  uint uVar2;
  size_t sVar3;
  uint *puVar4;
  
  if (_Size == 0) {
    return _Dst;
  }
  uVar1 = _Val & 0xff;
  puVar4 = _Dst;
  if (3 < _Size) {
    uVar2 = -(int)_Dst & 3;
    sVar3 = _Size;
    if (uVar2 != 0) {
      sVar3 = _Size - uVar2;
      do {
        *(undefined1 *)puVar4 = (undefined1)_Val;
        puVar4 = (uint *)((int)puVar4 + 1);
        uVar2 = uVar2 - 1;
      } while (uVar2 != 0);
    }
    uVar1 = uVar1 * 0x1010101;
    _Size = sVar3 & 3;
    uVar2 = sVar3 >> 2;
    if (uVar2 != 0) {
      for (; uVar2 != 0; uVar2 = uVar2 - 1) {
        *puVar4 = uVar1;
        puVar4 = puVar4 + 1;
      }
      if (_Size == 0) {
        return _Dst;
      }
    }
  }
  do {
    *(char *)puVar4 = (char)uVar1;
    puVar4 = (uint *)((int)puVar4 + 1);
    _Size = _Size - 1;
  } while (_Size != 0);
  return _Dst;
}



// Library Function - Multiple Matches With Different Base Names
//  _memcpy
//  _memmove
// 
// Libraries: Visual Studio 1998 Debug, Visual Studio 1998 Release

void * __cdecl FID_conflict__memcpy(void *_Dst,void *_Src,size_t _Size)

{
  uint uVar1;
  int in_EDX;
  uint uVar2;
  undefined4 *puVar3;
  undefined1 *puVar4;
  undefined4 *puVar5;
  undefined1 *puVar6;
  
  if ((_Src < _Dst) && (_Dst < (void *)((int)_Src + _Size))) {
    puVar3 = (undefined4 *)((int)_Src + _Size);
    puVar5 = (undefined4 *)((int)_Dst + _Size);
    if (((uint)puVar5 & 3) == 0) {
      uVar1 = _Size >> 2;
      while( true ) {
        puVar5 = puVar5 + -1;
        puVar3 = puVar3 + -1;
        if (uVar1 == 0) break;
        uVar1 = uVar1 - 1;
        *puVar5 = *puVar3;
      }
      switch(_Size & 3) {
      case 1:
switchD_00402f99_caseD_1:
        *(undefined1 *)((int)puVar5 + 3) = *(undefined1 *)((int)puVar3 + 3);
        return _Dst;
      case 2:
switchD_00402f99_caseD_2:
        *(undefined2 *)((int)puVar5 + 2) = *(undefined2 *)((int)puVar3 + 2);
        return _Dst;
      case 3:
switchD_00402f99_caseD_3:
        *(undefined2 *)((int)puVar5 + 2) = *(undefined2 *)((int)puVar3 + 2);
        *(undefined1 *)((int)puVar5 + 1) = *(undefined1 *)((int)puVar3 + 1);
        return _Dst;
      }
    }
    else {
      puVar4 = (undefined1 *)((int)puVar3 + -1);
      puVar6 = (undefined1 *)((int)puVar5 + -1);
      if (_Size < 0xd) {
        for (; _Size != 0; _Size = _Size - 1) {
          *puVar6 = *puVar4;
          puVar4 = puVar4 + -1;
          puVar6 = puVar6 + -1;
        }
        return _Dst;
      }
      uVar2 = -in_EDX & 3;
      uVar1 = _Size - uVar2;
      for (; uVar2 != 0; uVar2 = uVar2 - 1) {
        *puVar6 = *puVar4;
        puVar4 = puVar4 + -1;
        puVar6 = puVar6 + -1;
      }
      puVar3 = (undefined4 *)(puVar4 + -3);
      puVar5 = (undefined4 *)(puVar6 + -3);
      for (uVar2 = uVar1 >> 2; uVar2 != 0; uVar2 = uVar2 - 1) {
        *puVar5 = *puVar3;
        puVar3 = puVar3 + -1;
        puVar5 = puVar5 + -1;
      }
      switch(uVar1 & 3) {
      case 1:
        goto switchD_00402f99_caseD_1;
      case 2:
        goto switchD_00402f99_caseD_2;
      case 3:
        goto switchD_00402f99_caseD_3;
      }
    }
    return _Dst;
  }
  puVar3 = _Dst;
  if (((uint)_Dst & 3) == 0) {
    for (uVar1 = _Size >> 2; uVar1 != 0; uVar1 = uVar1 - 1) {
      *puVar3 = *(undefined4 *)_Src;
      _Src = (undefined4 *)((int)_Src + 4);
      puVar3 = puVar3 + 1;
    }
    switch(_Size & 3) {
    case 1:
switchD_00402f00_caseD_1:
      *(undefined1 *)puVar3 = *(undefined1 *)_Src;
      return _Dst;
    case 2:
switchD_00402f00_caseD_2:
      *(undefined2 *)puVar3 = *(undefined2 *)_Src;
      return _Dst;
    case 3:
switchD_00402f00_caseD_3:
      *(undefined2 *)puVar3 = *(undefined2 *)_Src;
      *(undefined1 *)((int)puVar3 + 2) = *(undefined1 *)((int)_Src + 2);
      return _Dst;
    }
  }
  else {
    puVar4 = _Dst;
    if (_Size < 0xd) {
      for (; _Size != 0; _Size = _Size - 1) {
        *puVar4 = *(undefined1 *)_Src;
        _Src = (undefined1 *)((int)_Src + 1);
        puVar4 = puVar4 + 1;
      }
      return _Dst;
    }
    uVar2 = -(int)_Dst & 3;
    uVar1 = _Size - uVar2;
    for (; uVar2 != 0; uVar2 = uVar2 - 1) {
      *(undefined1 *)puVar3 = *(undefined1 *)_Src;
      _Src = (undefined4 *)((int)_Src + 1);
      puVar3 = (undefined4 *)((int)puVar3 + 1);
    }
    for (uVar2 = uVar1 >> 2; uVar2 != 0; uVar2 = uVar2 - 1) {
      *puVar3 = *(undefined4 *)_Src;
      _Src = (undefined4 *)((int)_Src + 4);
      puVar3 = puVar3 + 1;
    }
    switch(uVar1 & 3) {
    case 1:
      goto switchD_00402f00_caseD_1;
    case 2:
      goto switchD_00402f00_caseD_2;
    case 3:
      goto switchD_00402f00_caseD_3;
    }
  }
  return _Dst;
}



// Library Function - Single Match
//  __cinit
// 
// Library: Visual Studio 1998 Release

int __cdecl __cinit(int param_1)

{
  int iVar1;
  
  if (DAT_00407574 != (code *)0x0) {
    (*DAT_00407574)();
  }
  __initterm((undefined4 *)&DAT_00406008,(undefined4 *)&DAT_0040600c);
  iVar1 = __initterm((undefined4 *)&DAT_00406000,(undefined4 *)&DAT_00406004);
  return iVar1;
}



// Library Function - Single Match
//  _exit
// 
// Library: Visual Studio 1998 Release

void __cdecl _exit(int _Code)

{
  doexit(_Code,0,0);
  return;
}



// Library Function - Single Match
//  __exit
// 
// Library: Visual Studio 1998 Release

void __cdecl __exit(UINT param_1)

{
  doexit(param_1,1,0);
  return;
}



// WARNING: Globals starting with '_' overlap smaller symbols at the same address
// Library Function - Single Match
//  _doexit
// 
// Library: Visual Studio 1998 Release

void __cdecl doexit(UINT param_1,int param_2,int param_3)

{
  HANDLE hProcess;
  undefined4 *puVar1;
  UINT uExitCode;
  
  if (DAT_004062f8 == 1) {
    uExitCode = param_1;
    hProcess = GetCurrentProcess();
    TerminateProcess(hProcess,uExitCode);
  }
  _DAT_004062f4 = 1;
  DAT_004062f0 = (undefined1)param_3;
  if (param_2 == 0) {
    if ((DAT_00407570 != (undefined4 *)0x0) &&
       (puVar1 = (undefined4 *)(DAT_0040756c + -4), DAT_00407570 <= puVar1)) {
      do {
        if ((code *)*puVar1 != (code *)0x0) {
          (*(code *)*puVar1)();
        }
        puVar1 = puVar1 + -1;
      } while (DAT_00407570 <= puVar1);
    }
    __initterm((undefined4 *)&DAT_00406010,(undefined4 *)&DAT_00406014);
  }
  __initterm((undefined4 *)&DAT_00406018,(undefined4 *)&DAT_0040601c);
  if (param_3 == 0) {
    DAT_004062f8 = 1;
                    // WARNING: Subroutine does not return
    ExitProcess(param_1);
  }
  return;
}



// Library Function - Single Match
//  __initterm
// 
// Library: Visual Studio 1998 Release

void __cdecl __initterm(undefined4 *param_1,undefined4 *param_2)

{
  for (; param_1 < param_2; param_1 = param_1 + 1) {
    if ((code *)*param_1 != (code *)0x0) {
      (*(code *)*param_1)();
    }
  }
  return;
}



undefined4 __cdecl FUN_00403160(LPCSTR param_1)

{
  BOOL BVar1;
  ulong uVar2;
  
  BVar1 = DeleteFileA(param_1);
  uVar2 = 0;
  if (BVar1 == 0) {
    uVar2 = GetLastError();
  }
  if (uVar2 != 0) {
    __dosmaperr(uVar2);
    return 0xffffffff;
  }
  return 0;
}



// WARNING: Globals starting with '_' overlap smaller symbols at the same address

undefined4 __cdecl FUN_00403190(LPCSTR param_1,byte param_2)

{
  DWORD DVar1;
  
  DVar1 = GetFileAttributesA(param_1);
  if (DVar1 == 0xffffffff) {
    DVar1 = GetLastError();
    __dosmaperr(DVar1);
    return 0xffffffff;
  }
  if (((DVar1 & 1) != 0) && ((param_2 & 2) != 0)) {
    _DAT_004062b0 = 0xd;
    _DAT_004062b4 = 5;
    return 0xffffffff;
  }
  return 0;
}



// WARNING: Globals starting with '_' overlap smaller symbols at the same address

/**
 * Program entry point generated by Ghidra.
 * Performs the original Windows-specific initialisation:
 *   • Detects OS version via GetVersion.
 *   • Initializes the CRT heap and IO.
 *   • Retrieves the command line and environment strings.
 *   • Parses the command line to extract the real program arguments.
 *   • Calls the game‑specific startup routine `FUN_004021ee`.
 *   • Exits the process with the code returned from the game.
 *
 * The function uses a mixture of CRT helpers (e.g. __heap_init, __ioinit)
 * and Win32 APIs.  For portability the surrounding build system provides
 * stub implementations of the required Win32 calls on non‑Windows platforms.
 */
void entry(void)

{
  byte bVar1;
  DWORD DVar2;
  int iVar3;
  HMODULE pHVar4;
  uint _Code;
  byte *pbVar5;
  int unaff_EDI;
  undefined4 *unaff_FS_OFFSET;
  _STARTUPINFOA local_74;
  undefined1 *local_1c;
  undefined4 uStack_14;
  undefined1 *puStack_10;
  undefined *puStack_c;
  undefined4 local_8;
  
  uStack_14 = *unaff_FS_OFFSET;
  local_8 = 0xffffffff;
  puStack_c = &DAT_00405000;
  puStack_10 = &LAB_00404880;
  *unaff_FS_OFFSET = &uStack_14;
  local_1c = &stack0xffffff80;
  DVar2 = GetVersion();
  _DAT_004062c8 = DVar2 >> 8 & 0xff;
  DAT_004062bc = DVar2 >> 0x10;
  _DAT_004062c4 = DVar2 & 0xff;
  _DAT_004062c0 = _DAT_004062c4 * 0x100 + _DAT_004062c8;
  iVar3 = __heap_init();
  if (iVar3 == 0) {
    __amsg_exit(0x1c);
  }
  local_8 = 0;
  __ioinit();
  ___initmbctable();
  DAT_00407568 = (byte *)GetCommandLineA();
  DAT_004062fc = ___crtGetEnvironmentStringsA();
  if ((DAT_004062fc == (LPVOID)0x0) || (DAT_00407568 == (byte *)0x0)) {
                    // WARNING: Subroutine does not return
    _exit(-1);
  }
  __setargv();
  __setenvp();
  __cinit(unaff_EDI);
  bVar1 = *DAT_00407568;
  pbVar5 = DAT_00407568;
  if (bVar1 == 0x22) {
    pbVar5 = DAT_00407568 + 1;
    if (*pbVar5 != 0x22) {
      do {
        if (*pbVar5 == 0) break;
        iVar3 = __ismbblead((uint)*pbVar5);
        if (iVar3 != 0) {
          pbVar5 = pbVar5 + 1;
        }
        pbVar5 = pbVar5 + 1;
      } while (*pbVar5 != 0x22);
      if (*pbVar5 != 0x22) goto LAB_004032e5;
    }
    pbVar5 = pbVar5 + 1;
  }
  else {
    while (0x20 < bVar1) {
      bVar1 = pbVar5[1];
      pbVar5 = pbVar5 + 1;
    }
  }
LAB_004032e5:
  bVar1 = *pbVar5;
  while ((bVar1 != 0 && (*pbVar5 < 0x21))) {
    pbVar5 = pbVar5 + 1;
    bVar1 = *pbVar5;
  }
  local_74.dwFlags = 0;
  GetStartupInfoA(&local_74);
  iVar3 = 0;
  pHVar4 = GetModuleHandleA((LPCSTR)0x0);
  _Code = GameInit(pHVar4,iVar3,(char *)pbVar5);
                    // WARNING: Subroutine does not return
  _exit(_Code);
}



// Library Function - Single Match
//  __amsg_exit
// 
// Library: Visual Studio 1998 Release

void __cdecl __amsg_exit(int param_1)

{
  if (DAT_00406308 == 1) {
    __FF_MSGBANNER();
  }
  __NMSG_WRITE(param_1);
  (*(code *)PTR___exit_00406304)(0xff);
  return;
}



// Library Function - Single Match
//  __callnewh
// 
// Library: Visual Studio 1998 Release

int __cdecl __callnewh(size_t _Size)

{
  int iVar1;
  
  if (DAT_00407240 != (code *)0x0) {
    iVar1 = (*DAT_00407240)(_Size);
    if (iVar1 != 0) {
      return 1;
    }
  }
  return 0;
}



// Library Function - Single Match
//  __heap_init
// 
// Library: Visual Studio 1998 Release

int __cdecl __heap_init(void)

{
  undefined **ppuVar1;
  
  DAT_00407564 = HeapCreate(1,0x1000,0);
  if (DAT_00407564 == (HANDLE)0x0) {
    return 0;
  }
  ppuVar1 = ___sbh_new_region();
  if (ppuVar1 == (undefined **)0x0) {
    HeapDestroy(DAT_00407564);
    return 0;
  }
  return 1;
}



// Library Function - Single Match
//  ___sbh_new_region
// 
// Library: Visual Studio 1998 Release

undefined ** ___sbh_new_region(void)

{
  undefined4 *lpAddress;
  LPVOID pvVar1;
  int iVar2;
  int iVar3;
  undefined **lpMem;
  undefined4 *puVar4;
  
  if (DAT_00406b28 == 0) {
    lpMem = &PTR_LOOP_00406318;
  }
  else {
    lpMem = HeapAlloc(DAT_00407564,0,0x814);
    if (lpMem == (undefined **)0x0) {
      return (undefined **)0x0;
    }
  }
  lpAddress = VirtualAlloc((LPVOID)0x0,0x400000,0x2000,4);
  if (lpAddress != (undefined4 *)0x0) {
    pvVar1 = VirtualAlloc(lpAddress,0x10000,0x1000,4);
    if (pvVar1 != (LPVOID)0x0) {
      if (lpMem == &PTR_LOOP_00406318) {
        if (PTR_LOOP_00406318 == (undefined *)0x0) {
          PTR_LOOP_00406318 = (undefined *)&PTR_LOOP_00406318;
        }
        if (PTR_LOOP_0040631c == (undefined *)0x0) {
          PTR_LOOP_0040631c = (undefined *)&PTR_LOOP_00406318;
        }
      }
      else {
        *lpMem = (undefined *)&PTR_LOOP_00406318;
        lpMem[1] = PTR_LOOP_0040631c;
        PTR_LOOP_0040631c = (undefined *)lpMem;
        *(undefined ***)lpMem[1] = lpMem;
      }
      lpMem[0x204] = (undefined *)lpAddress;
      lpMem[2] = (undefined *)0x0;
      lpMem[3] = (undefined *)0x10;
      iVar2 = 0;
      do {
        if (iVar2 < 0x10) {
          *(undefined1 *)((int)lpMem + iVar2 + 0x10) = 0xf0;
        }
        else {
          *(undefined1 *)((int)lpMem + iVar2 + 0x10) = 0xff;
        }
        iVar3 = iVar2 + 1;
        *(undefined1 *)((int)lpMem + iVar2 + 0x410) = 0xf1;
        iVar2 = iVar3;
      } while (iVar3 < 0x400);
      puVar4 = lpAddress;
      for (iVar2 = 0x4000; iVar2 != 0; iVar2 = iVar2 + -1) {
        *puVar4 = 0;
        puVar4 = puVar4 + 1;
      }
      if (lpAddress < lpMem[0x204] + 0x10000) {
        do {
          *lpAddress = lpAddress + 2;
          lpAddress[1] = 0xf0;
          *(undefined1 *)(lpAddress + 0x3e) = 0xff;
          lpAddress = lpAddress + 0x400;
        } while (lpAddress < lpMem[0x204] + 0x10000);
      }
      return lpMem;
    }
    VirtualFree(lpAddress,0,0x8000);
  }
  if (lpMem != &PTR_LOOP_00406318) {
    HeapFree(DAT_00407564,0,lpMem);
  }
  return (undefined **)0x0;
}



// Library Function - Single Match
//  ___sbh_release_region
// 
// Library: Visual Studio 1998 Release

void __cdecl ___sbh_release_region(undefined **param_1)

{
  VirtualFree(param_1[0x204],0,0x8000);
  if ((undefined **)PTR_LOOP_00406b2c == param_1) {
    PTR_LOOP_00406b2c = param_1[1];
  }
  if (param_1 != &PTR_LOOP_00406318) {
    *(undefined **)param_1[1] = *param_1;
    *(undefined **)(*param_1 + 4) = param_1[1];
    HeapFree(DAT_00407564,0,param_1);
    return;
  }
  DAT_00406b28 = 0;
  return;
}



// Library Function - Single Match
//  ___sbh_decommit_pages
// 
// Library: Visual Studio 1998 Release

void __cdecl ___sbh_decommit_pages(int param_1)

{
  BOOL BVar1;
  char *pcVar2;
  undefined *puVar3;
  undefined **ppuVar4;
  undefined **ppuVar5;
  int iVar6;
  int local_4;
  
  ppuVar4 = (undefined **)PTR_LOOP_0040631c;
  do {
    ppuVar5 = ppuVar4;
    if (ppuVar4[0x204] != (undefined *)0x0) {
      puVar3 = (undefined *)0x3ff;
      pcVar2 = (char *)((int)ppuVar4 + 0x40f);
      local_4 = 0;
      iVar6 = 0x3ff000;
      do {
        if (*pcVar2 == -0x10) {
          BVar1 = VirtualFree(ppuVar4[0x204] + iVar6,0x1000,0x4000);
          if (BVar1 != 0) {
            *pcVar2 = -1;
            DAT_00406b30 = DAT_00406b30 + -1;
            if ((ppuVar4[3] == (undefined *)0xffffffff) || ((int)puVar3 < (int)ppuVar4[3])) {
              ppuVar4[3] = puVar3;
            }
            local_4 = local_4 + 1;
            param_1 = param_1 + -1;
            if (param_1 == 0) break;
          }
        }
        iVar6 = iVar6 + -0x1000;
        puVar3 = puVar3 + -1;
        pcVar2 = pcVar2 + -1;
      } while (-1 < iVar6);
      ppuVar5 = (undefined **)ppuVar4[1];
      if ((local_4 != 0) && (*(char *)(ppuVar4 + 4) == -1)) {
        iVar6 = 1;
        pcVar2 = (char *)((int)ppuVar4 + 0x11);
        do {
          if (*pcVar2 != -1) break;
          iVar6 = iVar6 + 1;
          pcVar2 = pcVar2 + 1;
        } while (iVar6 < 0x400);
        if (iVar6 == 0x400) {
          ___sbh_release_region(ppuVar4);
        }
      }
    }
    if ((ppuVar5 == (undefined **)PTR_LOOP_0040631c) || (ppuVar4 = ppuVar5, param_1 < 1)) {
      return;
    }
  } while( true );
}



// Library Function - Single Match
//  ___sbh_find_block
// 
// Library: Visual Studio 1998 Release

int __cdecl ___sbh_find_block(undefined *param_1,undefined4 *param_2,uint *param_3)

{
  undefined *puVar1;
  undefined **ppuVar2;
  uint uVar3;
  
  ppuVar2 = &PTR_LOOP_00406318;
  while (((puVar1 = ppuVar2[0x204], puVar1 == (undefined *)0x0 || (param_1 <= puVar1)) ||
         (puVar1 + 0x400000 <= param_1))) {
    ppuVar2 = (undefined **)*ppuVar2;
    if (ppuVar2 == &PTR_LOOP_00406318) {
      return 0;
    }
  }
  *param_2 = ppuVar2;
  uVar3 = (uint)param_1 & 0xfffff000;
  *param_3 = uVar3;
  return ((int)(param_1 + (-0x100 - uVar3)) >> 4) + 8 + uVar3;
}



// Library Function - Single Match
//  ___sbh_free_block
// 
// Library: Visual Studio 1998 Release

void __cdecl ___sbh_free_block(int param_1,int param_2,char *param_3)

{
  int iVar1;
  
  iVar1 = (param_2 - *(int *)(param_1 + 0x810) >> 0xc) + param_1;
  *(char *)(iVar1 + 0x10) = *(char *)(iVar1 + 0x10) + *param_3;
  *param_3 = '\0';
  *(undefined1 *)(iVar1 + 0x410) = 0xf1;
  if ((*(char *)(iVar1 + 0x10) == -0x10) && (DAT_00406b30 = DAT_00406b30 + 1, DAT_00406b30 == 0x20))
  {
    ___sbh_decommit_pages(0x10);
  }
  return;
}



// Library Function - Single Match
//  ___sbh_alloc_block
// 
// Library: Visual Studio 1998 Release

undefined * __cdecl ___sbh_alloc_block(uint param_1)

{
  char *pcVar1;
  byte bVar2;
  undefined *puVar3;
  undefined *puVar4;
  undefined *puVar5;
  undefined *puVar6;
  undefined4 *puVar7;
  char cVar8;
  int iVar9;
  int iVar10;
  undefined **ppuVar11;
  int *piVar12;
  undefined *puVar13;
  
  piVar12 = (int *)PTR_LOOP_00406b2c;
  do {
    cVar8 = (char)param_1;
    if (piVar12[0x204] != 0) {
      iVar10 = piVar12[2];
      if (iVar10 < 0x400) {
        iVar9 = iVar10 << 0xc;
        do {
          bVar2 = *(byte *)((int)piVar12 + iVar10 + 0x10);
          if (((param_1 <= bVar2) && (bVar2 != 0xff)) &&
             (param_1 < *(byte *)((int)piVar12 + iVar10 + 0x410))) {
            puVar6 = (undefined *)
                     ___sbh_alloc_block_from_page
                               ((int *)(piVar12[0x204] + iVar9),(uint)bVar2,param_1);
            if (puVar6 != (undefined *)0x0) {
              pcVar1 = (char *)((int)piVar12 + iVar10 + 0x10);
              PTR_LOOP_00406b2c = (undefined *)piVar12;
              *pcVar1 = *pcVar1 - cVar8;
              piVar12[2] = iVar10;
              return puVar6;
            }
            *(char *)((int)piVar12 + iVar10 + 0x410) = cVar8;
          }
          iVar9 = iVar9 + 0x1000;
          iVar10 = iVar10 + 1;
        } while (iVar9 < 0x400000);
      }
      iVar10 = 0;
      iVar9 = 0;
      if (0 < piVar12[2]) {
        do {
          bVar2 = *(byte *)((int)piVar12 + iVar9 + 0x10);
          if (((param_1 <= bVar2) && (bVar2 != 0xff)) &&
             (param_1 < *(byte *)((int)piVar12 + iVar9 + 0x410))) {
            puVar6 = (undefined *)
                     ___sbh_alloc_block_from_page
                               ((int *)(piVar12[0x204] + iVar10),(uint)bVar2,param_1);
            if (puVar6 != (undefined *)0x0) {
              pcVar1 = (char *)((int)piVar12 + iVar9 + 0x10);
              PTR_LOOP_00406b2c = (undefined *)piVar12;
              *pcVar1 = *pcVar1 - cVar8;
              piVar12[2] = iVar9;
              return puVar6;
            }
            *(char *)((int)piVar12 + iVar9 + 0x410) = cVar8;
          }
          iVar10 = iVar10 + 0x1000;
          iVar9 = iVar9 + 1;
        } while (iVar9 < piVar12[2]);
      }
    }
    piVar12 = (int *)*piVar12;
  } while ((int *)PTR_LOOP_00406b2c != piVar12);
  ppuVar11 = &PTR_LOOP_00406318;
  while ((ppuVar11[0x204] == (undefined *)0x0 || (ppuVar11[3] == (undefined *)0xffffffff))) {
    ppuVar11 = (undefined **)*ppuVar11;
    if (ppuVar11 == &PTR_LOOP_00406318) {
      ppuVar11 = ___sbh_new_region();
      if (ppuVar11 == (undefined **)0x0) {
        return (undefined *)0x0;
      }
      puVar7 = (undefined4 *)ppuVar11[0x204];
      *(char *)(puVar7 + 2) = cVar8;
      PTR_LOOP_00406b2c = (undefined *)ppuVar11;
      *puVar7 = (undefined *)((int)puVar7 + param_1 + 8);
      puVar7[1] = 0xf0 - param_1;
      *(char *)(ppuVar11 + 4) = *(char *)(ppuVar11 + 4) - cVar8;
      return ppuVar11[0x204] + 0x100;
    }
  }
  puVar3 = ppuVar11[3];
  puVar6 = puVar3 + 0x10;
  puVar5 = puVar3;
  if (0x3ff < (int)puVar6) {
    puVar6 = (undefined *)0x400;
  }
  do {
    puVar13 = puVar5 + 1;
    if ((int)puVar6 <= (int)puVar13) break;
    puVar4 = puVar5 + 0x11;
    puVar5 = puVar13;
  } while (*(char *)((int)ppuVar11 + (int)puVar4) == -1);
  puVar6 = VirtualAlloc(ppuVar11[0x204] + (int)puVar3 * 0x1000,((int)puVar13 - (int)puVar3) * 0x1000
                        ,0x1000,4);
  if (puVar6 != ppuVar11[0x204] + (int)puVar3 * 0x1000) {
    return (undefined *)0x0;
  }
  puVar6 = ppuVar11[3];
  piVar12 = (int *)(ppuVar11[0x204] + (int)puVar6 * 0x1000);
  for (; (int)puVar6 < (int)puVar13; puVar6 = puVar6 + 1) {
    *piVar12 = (int)(piVar12 + 2);
    piVar12[1] = 0xf0;
    *(undefined1 *)(piVar12 + 0x3e) = 0xff;
    *(undefined1 *)((int)ppuVar11 + (int)(puVar6 + 0x10)) = 0xf0;
    *(undefined1 *)((int)ppuVar11 + (int)(puVar6 + 0x410)) = 0xf1;
    piVar12 = piVar12 + 0x400;
  }
  for (; ((int)puVar13 < 0x400 && (*(char *)((int)ppuVar11 + (int)(puVar13 + 0x10)) != -1));
      puVar13 = puVar13 + 1) {
  }
  puVar6 = ppuVar11[3];
  PTR_LOOP_00406b2c = (undefined *)ppuVar11;
  ppuVar11[3] = (undefined *)0xffffffff;
  if ((int)puVar13 < 0x400) {
    ppuVar11[3] = puVar13;
  }
  puVar7 = (undefined4 *)(ppuVar11[0x204] + (int)puVar6 * 0x1000);
  *(char *)(puVar7 + 2) = cVar8;
  ppuVar11[2] = puVar6;
  *(char *)((int)ppuVar11 + (int)(puVar6 + 0x10)) =
       *(char *)((int)ppuVar11 + (int)(puVar6 + 0x10)) - cVar8;
  *puVar7 = (undefined *)((int)puVar7 + param_1 + 8);
  puVar7[1] = puVar7[1] - param_1;
  return ppuVar11[0x204] + (int)puVar6 * 0x1000 + 0x100;
}



// Library Function - Single Match
//  ___sbh_alloc_block_from_page
// 
// Library: Visual Studio 1998 Release

int __cdecl ___sbh_alloc_block_from_page(int *param_1,uint param_2,uint param_3)

{
  byte bVar1;
  byte *pbVar2;
  byte *pbVar3;
  byte bVar4;
  uint uVar5;
  byte *pbVar6;
  
  pbVar2 = (byte *)*param_1;
  bVar4 = (byte)param_3;
  if (param_3 <= (uint)param_1[1]) {
    *pbVar2 = bVar4;
    if (pbVar2 + param_3 < param_1 + 0x3e) {
      *param_1 = *param_1 + param_3;
      param_1[1] = param_1[1] - param_3;
    }
    else {
      param_1[1] = 0;
      *param_1 = (int)(param_1 + 2);
    }
    return (int)pbVar2 * 0x10 + (int)param_1 * -0xf + 0x80;
  }
  pbVar6 = pbVar2;
  if (pbVar2[param_1[1]] != 0) {
    pbVar6 = pbVar2 + param_1[1];
  }
  if (pbVar6 + param_3 < param_1 + 0x3e) {
    do {
      if (*pbVar6 == 0) {
        pbVar3 = pbVar6 + 1;
        uVar5 = 1;
        bVar1 = *pbVar3;
        while (bVar1 == 0) {
          pbVar3 = pbVar3 + 1;
          uVar5 = uVar5 + 1;
          bVar1 = *pbVar3;
        }
        if (param_3 <= uVar5) {
          if (pbVar6 + param_3 < param_1 + 0x3e) {
            *param_1 = (int)(pbVar6 + param_3);
            param_1[1] = uVar5 - param_3;
          }
          else {
            param_1[1] = 0;
            *param_1 = (int)(param_1 + 2);
          }
          *pbVar6 = bVar4;
          return (int)pbVar6 * 0x10 + (int)param_1 * -0xf + 0x80;
        }
        if (pbVar2 == pbVar6) {
          param_1[1] = uVar5;
        }
        else {
          param_2 = param_2 - uVar5;
          if (param_2 < param_3) {
            return 0;
          }
        }
      }
      else {
        pbVar3 = pbVar6 + *pbVar6;
      }
      pbVar6 = pbVar3;
    } while (pbVar3 + param_3 < param_1 + 0x3e);
  }
  pbVar6 = (byte *)(param_1 + 2);
  while( true ) {
    while( true ) {
      if ((pbVar2 <= pbVar6) || ((byte *)((int)param_1 + 0xf7U) < pbVar6 + param_3)) {
        return 0;
      }
      if (*pbVar6 == 0) break;
      pbVar6 = pbVar6 + *pbVar6;
    }
    pbVar3 = pbVar6 + 1;
    uVar5 = 1;
    bVar1 = *pbVar3;
    while (bVar1 == 0) {
      pbVar3 = pbVar3 + 1;
      uVar5 = uVar5 + 1;
      bVar1 = *pbVar3;
    }
    if (param_3 <= uVar5) break;
    param_2 = param_2 - uVar5;
    pbVar6 = pbVar3;
    if (param_2 < param_3) {
      return 0;
    }
  }
  if (pbVar6 + param_3 < param_1 + 0x3e) {
    *param_1 = (int)(pbVar6 + param_3);
    param_1[1] = uVar5 - param_3;
  }
  else {
    param_1[1] = 0;
    *param_1 = (int)(param_1 + 2);
  }
  *pbVar6 = bVar4;
  return (int)pbVar6 * 0x10 + (int)param_1 * -0xf + 0x80;
}



// WARNING: Globals starting with '_' overlap smaller symbols at the same address
// Library Function - Single Match
//  __dosmaperr
// 
// Library: Visual Studio 1998 Release

void __cdecl __dosmaperr(ulong param_1)

{
  int iVar1;
  ulong *puVar2;
  
  iVar1 = 0;
  puVar2 = &DAT_00406b38;
  _DAT_004062b4 = param_1;
  do {
    if (*puVar2 == param_1) {
      _DAT_004062b0 = *(undefined4 *)(iVar1 * 8 + 0x406b3c);
      return;
    }
    puVar2 = puVar2 + 2;
    iVar1 = iVar1 + 1;
  } while (puVar2 < &DAT_00406ca0);
  if ((0x12 < param_1) && (param_1 < 0x25)) {
    _DAT_004062b0 = 0xd;
    return;
  }
  if ((0xbb < param_1) && (param_1 < 0xcb)) {
    _DAT_004062b0 = 8;
    return;
  }
  _DAT_004062b0 = 0x16;
  return;
}



// Library Function - Single Match
//  __global_unwind2
// 
// Library: Visual Studio

void __cdecl __global_unwind2(PVOID param_1)

{
  RtlUnwind(param_1,(PVOID)0x403c04,(PEXCEPTION_RECORD)0x0,(PVOID)0x0);
  return;
}



// Library Function - Single Match
//  __local_unwind2
// 
// Libraries: Visual Studio 1998 Debug, Visual Studio 1998 Release, Visual Studio 2003 Debug, Visual
// Studio 2003 Release

void __cdecl __local_unwind2(int param_1,int param_2)

{
  int iVar1;
  int iVar2;
  undefined4 *unaff_FS_OFFSET;
  undefined4 uStack_1c;
  undefined1 *puStack_18;
  undefined4 local_14;
  int iStack_10;
  
  iStack_10 = param_1;
  puStack_18 = &LAB_00403c0c;
  uStack_1c = *unaff_FS_OFFSET;
  *unaff_FS_OFFSET = &uStack_1c;
  while( true ) {
    iVar1 = *(int *)(param_1 + 8);
    iVar2 = *(int *)(param_1 + 0xc);
    if ((iVar2 == -1) || (iVar2 == param_2)) break;
    local_14 = *(undefined4 *)(iVar1 + iVar2 * 0xc);
    *(undefined4 *)(param_1 + 0xc) = local_14;
    if (*(int *)(iVar1 + 4 + iVar2 * 0xc) == 0) {
      FUN_00403cc2();
      (**(code **)(iVar1 + 8 + iVar2 * 0xc))();
    }
  }
  *unaff_FS_OFFSET = uStack_1c;
  return;
}



void FUN_00403cc2(void)

{
  undefined4 in_EAX;
  int unaff_EBP;
  
  DAT_00406ca8 = *(undefined4 *)(unaff_EBP + 8);
  DAT_00406ca4 = in_EAX;
  DAT_00406cac = unaff_EBP;
  return;
}



// Library Function - Single Match
//  __XcptFilter
// 
// Library: Visual Studio 1998 Release

int __cdecl __XcptFilter(ulong _ExceptionNum,_EXCEPTION_POINTERS *_ExceptionPtr)

{
  code *pcVar1;
  undefined4 uVar2;
  undefined4 uVar3;
  int *piVar4;
  LONG LVar5;
  int iVar6;
  undefined4 *puVar7;
  
  piVar4 = (int *)xcptlookup(_ExceptionNum);
  uVar3 = DAT_00406d38;
  if ((piVar4 == (int *)0x0) || (pcVar1 = (code *)piVar4[2], pcVar1 == (code *)0x0)) {
    LVar5 = UnhandledExceptionFilter(_ExceptionPtr);
    return LVar5;
  }
  if (pcVar1 == (code *)0x5) {
    piVar4[2] = 0;
    return 1;
  }
  if (pcVar1 == (code *)0x1) {
    return -1;
  }
  DAT_00406d38 = _ExceptionPtr;
  if (piVar4[1] == 8) {
    if (DAT_00406d28 < DAT_00406d2c + DAT_00406d28) {
      puVar7 = (undefined4 *)(DAT_00406d28 * 0xc + 0x406cb8);
      iVar6 = DAT_00406d2c;
      do {
        *puVar7 = 0;
        puVar7 = puVar7 + 3;
        iVar6 = iVar6 + -1;
      } while (iVar6 != 0);
    }
    uVar2 = DAT_00406d34;
    iVar6 = *piVar4;
    if (iVar6 == -0x3fffff72) {
      DAT_00406d34 = 0x83;
    }
    else if (iVar6 == -0x3fffff70) {
      DAT_00406d34 = 0x81;
    }
    else if (iVar6 == -0x3fffff6f) {
      DAT_00406d34 = 0x84;
    }
    else if (iVar6 == -0x3fffff6d) {
      DAT_00406d34 = 0x85;
    }
    else if (iVar6 == -0x3fffff73) {
      DAT_00406d34 = 0x82;
    }
    else if (iVar6 == -0x3fffff71) {
      DAT_00406d34 = 0x86;
    }
    else if (iVar6 == -0x3fffff6e) {
      DAT_00406d34 = 0x8a;
    }
    (*pcVar1)(8,DAT_00406d34);
    DAT_00406d34 = uVar2;
  }
  else {
    piVar4[2] = 0;
    (*pcVar1)(piVar4[1]);
  }
  DAT_00406d38 = (_EXCEPTION_POINTERS *)uVar3;
  return -1;
}



// Library Function - Single Match
//  _xcptlookup
// 
// Library: Visual Studio 1998 Release

uint __cdecl xcptlookup(int param_1)

{
  int *piVar1;
  
  piVar1 = &DAT_00406cb0;
  do {
    if (*piVar1 == param_1) break;
    piVar1 = piVar1 + 3;
  } while (piVar1 < &DAT_00406cb0 + DAT_00406d30 * 3);
  return -(uint)(*piVar1 == param_1) & (uint)piVar1;
}



// Library Function - Single Match
//  __ismbblead
// 
// Library: Visual Studio 1998 Release

int __cdecl __ismbblead(uint _C)

{
  int iVar1;
  
  iVar1 = x_ismbbtype((byte)_C,0,4);
  return iVar1;
}



// Library Function - Single Match
//  _x_ismbbtype
// 
// Library: Visual Studio 1998 Release

undefined4 __cdecl x_ismbbtype(byte param_1,uint param_2,byte param_3)

{
  uint uVar1;
  
  if ((param_3 & *(byte *)((int)&DAT_00406d48 + param_1 + 1)) == 0) {
    uVar1 = 0;
    if (param_2 != 0) {
      uVar1 = *(ushort *)(&DAT_0040700a + (uint)param_1 * 2) & param_2;
    }
    if (uVar1 == 0) {
      return 0;
    }
  }
  return 1;
}



// WARNING: Globals starting with '_' overlap smaller symbols at the same address
// Library Function - Single Match
//  __setenvp
// 
// Library: Visual Studio 1998 Release

int __cdecl __setenvp(void)

{
  char cVar1;
  undefined4 *puVar2;
  void *pvVar3;
  int extraout_EAX;
  uint uVar4;
  uint uVar5;
  uint uVar6;
  char *pcVar7;
  int iVar8;
  char *pcVar9;
  char *pcVar10;
  
  iVar8 = 0;
  cVar1 = *DAT_004062fc;
  pcVar7 = DAT_004062fc;
  while (cVar1 != '\0') {
    if (*pcVar7 != '=') {
      iVar8 = iVar8 + 1;
    }
    uVar4 = 0xffffffff;
    pcVar10 = pcVar7;
    do {
      if (uVar4 == 0) break;
      uVar4 = uVar4 - 1;
      cVar1 = *pcVar10;
      pcVar10 = pcVar10 + 1;
    } while (cVar1 != '\0');
    pcVar7 = pcVar7 + ~uVar4;
    cVar1 = *pcVar7;
  }
  puVar2 = _malloc(iVar8 * 4 + 4);
  _DAT_004062d8 = puVar2;
  if (puVar2 == (undefined4 *)0x0) {
    __amsg_exit(9);
  }
  cVar1 = *DAT_004062fc;
  pcVar7 = DAT_004062fc;
  do {
    if (cVar1 == '\0') {
      _free(DAT_004062fc);
      DAT_004062fc = (char *)0x0;
      *puVar2 = 0;
      return extraout_EAX;
    }
    uVar4 = 0xffffffff;
    pcVar10 = pcVar7;
    do {
      if (uVar4 == 0) break;
      uVar4 = uVar4 - 1;
      cVar1 = *pcVar10;
      pcVar10 = pcVar10 + 1;
    } while (cVar1 != '\0');
    if (*pcVar7 != '=') {
      pvVar3 = _malloc(~uVar4);
      *puVar2 = pvVar3;
      if (pvVar3 == (void *)0x0) {
        __amsg_exit(9);
      }
      uVar5 = 0xffffffff;
      pcVar10 = pcVar7;
      do {
        pcVar9 = pcVar10;
        if (uVar5 == 0) break;
        uVar5 = uVar5 - 1;
        pcVar9 = pcVar10 + 1;
        cVar1 = *pcVar10;
        pcVar10 = pcVar9;
      } while (cVar1 != '\0');
      uVar5 = ~uVar5;
      pcVar10 = (char *)*puVar2;
      puVar2 = puVar2 + 1;
      pcVar9 = pcVar9 + -uVar5;
      for (uVar6 = uVar5 >> 2; uVar6 != 0; uVar6 = uVar6 - 1) {
        *(undefined4 *)pcVar10 = *(undefined4 *)pcVar9;
        pcVar9 = pcVar9 + 4;
        pcVar10 = pcVar10 + 4;
      }
      for (uVar5 = uVar5 & 3; uVar5 != 0; uVar5 = uVar5 - 1) {
        *pcVar10 = *pcVar9;
        pcVar9 = pcVar9 + 1;
        pcVar10 = pcVar10 + 1;
      }
    }
    pcVar7 = pcVar7 + ~uVar4;
    cVar1 = *pcVar7;
  } while( true );
}



// WARNING: Globals starting with '_' overlap smaller symbols at the same address
// Library Function - Single Match
//  __setargv
// 
// Library: Visual Studio 1998 Release

int __cdecl __setargv(void)

{
  undefined4 *puVar1;
  byte *pbVar2;
  int local_8;
  int local_4;
  
  GetModuleFileNameA((HMODULE)0x0,&DAT_00407248,0x104);
  _DAT_004062e8 = &DAT_00407248;
  pbVar2 = &DAT_00407248;
  if (*DAT_00407568 != 0) {
    pbVar2 = DAT_00407568;
  }
  parse_cmdline(pbVar2,(undefined4 *)0x0,(byte *)0x0,&local_8,&local_4);
  puVar1 = _malloc(local_8 * 4 + local_4);
  if (puVar1 == (undefined4 *)0x0) {
    __amsg_exit(8);
  }
  parse_cmdline(pbVar2,puVar1,(byte *)(puVar1 + local_8),&local_8,&local_4);
  _DAT_004062d0 = puVar1;
  _DAT_004062cc = local_8 + -1;
  return local_8 + -1;
}



// Library Function - Single Match
//  _parse_cmdline
// 
// Library: Visual Studio 1998 Release

void __cdecl
parse_cmdline(byte *param_1,undefined4 *param_2,byte *param_3,int *param_4,int *param_5)

{
  byte bVar1;
  bool bVar2;
  bool bVar3;
  byte *pbVar4;
  uint uVar5;
  byte *pbVar6;
  
  *param_5 = 0;
  *param_4 = 1;
  if (param_2 != (undefined4 *)0x0) {
    *param_2 = param_3;
    param_2 = param_2 + 1;
  }
  if (*param_1 == 0x22) {
    pbVar6 = param_1 + 1;
    bVar1 = *pbVar6;
    while ((bVar1 != 0x22 && (*pbVar6 != 0))) {
      if (((*(byte *)((int)&DAT_00406d48 + *pbVar6 + 1) & 4) != 0) &&
         (*param_5 = *param_5 + 1, param_3 != (byte *)0x0)) {
        bVar1 = *pbVar6;
        pbVar6 = pbVar6 + 1;
        *param_3 = bVar1;
        param_3 = param_3 + 1;
      }
      *param_5 = *param_5 + 1;
      if (param_3 != (byte *)0x0) {
        *param_3 = *pbVar6;
        param_3 = param_3 + 1;
      }
      pbVar6 = pbVar6 + 1;
      bVar1 = *pbVar6;
    }
    *param_5 = *param_5 + 1;
    if (param_3 != (byte *)0x0) {
      *param_3 = 0;
      param_3 = param_3 + 1;
    }
    if (*pbVar6 == 0x22) {
      pbVar6 = pbVar6 + 1;
    }
  }
  else {
    do {
      *param_5 = *param_5 + 1;
      if (param_3 != (byte *)0x0) {
        *param_3 = *param_1;
        param_3 = param_3 + 1;
      }
      bVar1 = *param_1;
      pbVar6 = param_1 + 1;
      if ((*(byte *)((int)&DAT_00406d48 + bVar1 + 1) & 4) != 0) {
        *param_5 = *param_5 + 1;
        if (param_3 != (byte *)0x0) {
          *param_3 = *pbVar6;
          param_3 = param_3 + 1;
        }
        pbVar6 = param_1 + 2;
      }
      if (bVar1 == 0x20) break;
      if (bVar1 == 0) goto LAB_004040d0;
      param_1 = pbVar6;
    } while (bVar1 != 9);
    if (bVar1 == 0) {
LAB_004040d0:
      pbVar6 = pbVar6 + -1;
    }
    else if (param_3 != (byte *)0x0) {
      param_3[-1] = 0;
    }
  }
  bVar3 = false;
  while (*pbVar6 != 0) {
    for (; (*pbVar6 == 0x20 || (*pbVar6 == 9)); pbVar6 = pbVar6 + 1) {
    }
    if (*pbVar6 == 0) break;
    if (param_2 != (undefined4 *)0x0) {
      *param_2 = param_3;
      param_2 = param_2 + 1;
    }
    *param_4 = *param_4 + 1;
    while( true ) {
      bVar2 = true;
      uVar5 = 0;
      bVar1 = *pbVar6;
      while (bVar1 == 0x5c) {
        pbVar6 = pbVar6 + 1;
        uVar5 = uVar5 + 1;
        bVar1 = *pbVar6;
      }
      if (*pbVar6 == 0x22) {
        pbVar4 = pbVar6;
        if ((uVar5 & 1) == 0) {
          if ((!bVar3) || (pbVar4 = pbVar6 + 1, *pbVar4 != 0x22)) {
            bVar2 = false;
            pbVar4 = pbVar6;
          }
          bVar3 = !bVar3;
        }
        uVar5 = uVar5 >> 1;
        pbVar6 = pbVar4;
      }
      while (uVar5 != 0) {
        uVar5 = uVar5 - 1;
        if (param_3 != (byte *)0x0) {
          *param_3 = 0x5c;
          param_3 = param_3 + 1;
        }
        *param_5 = *param_5 + 1;
      }
      bVar1 = *pbVar6;
      if ((bVar1 == 0) || ((!bVar3 && ((bVar1 == 0x20 || (bVar1 == 9)))))) break;
      if (bVar2) {
        if (param_3 == (byte *)0x0) {
          if ((*(byte *)((int)&DAT_00406d48 + bVar1 + 1) & 4) != 0) {
            pbVar6 = pbVar6 + 1;
            *param_5 = *param_5 + 1;
          }
          *param_5 = *param_5 + 1;
          goto LAB_00404201;
        }
        pbVar4 = param_3;
        if ((*(byte *)((int)&DAT_00406d48 + bVar1 + 1) & 4) != 0) {
          *param_3 = bVar1;
          pbVar6 = pbVar6 + 1;
          pbVar4 = param_3 + 1;
          *param_5 = *param_5 + 1;
        }
        bVar1 = *pbVar6;
        param_3 = pbVar4 + 1;
        pbVar6 = pbVar6 + 1;
        *pbVar4 = bVar1;
        *param_5 = *param_5 + 1;
      }
      else {
LAB_00404201:
        pbVar6 = pbVar6 + 1;
      }
    }
    if (param_3 != (byte *)0x0) {
      *param_3 = 0;
      param_3 = param_3 + 1;
    }
    *param_5 = *param_5 + 1;
  }
  if (param_2 != (undefined4 *)0x0) {
    *param_2 = 0;
  }
  *param_4 = *param_4 + 1;
  return;
}



// Library Function - Single Match
//  ___crtGetEnvironmentStringsA
// 
// Library: Visual Studio 1998 Release

LPVOID __cdecl ___crtGetEnvironmentStringsA(void)

{
  char cVar1;
  WCHAR WVar2;
  size_t _Size;
  LPSTR lpMultiByteStr;
  CHAR *pCVar3;
  uint uVar4;
  LPCH pCVar5;
  char *pcVar6;
  WCHAR *pWVar8;
  int iVar10;
  LPCH pCVar11;
  LPWCH lpWideCharStr;
  CHAR *pCVar12;
  char *pcVar7;
  WCHAR *pWVar9;
  
  pCVar5 = (LPCH)0x0;
  lpWideCharStr = (LPWCH)0x0;
  if (DAT_00406d40 == 0) {
    lpWideCharStr = GetEnvironmentStringsW();
    if (lpWideCharStr == (LPWCH)0x0) {
      pCVar5 = GetEnvironmentStrings();
      if (pCVar5 == (LPCH)0x0) {
        return (LPVOID)0x0;
      }
      DAT_00406d40 = 2;
    }
    else {
      DAT_00406d40 = 1;
    }
  }
  if (DAT_00406d40 != 1) {
    if (DAT_00406d40 != 2) {
      return (LPVOID)0x0;
    }
    if ((pCVar5 == (LPCH)0x0) && (pCVar5 = GetEnvironmentStrings(), pCVar5 == (LPCH)0x0)) {
      return (LPVOID)0x0;
    }
    cVar1 = *pCVar5;
    pcVar6 = pCVar5;
    while (cVar1 != '\0') {
      do {
        pcVar7 = pcVar6;
        pcVar6 = pcVar7 + 1;
      } while (*pcVar6 != '\0');
      pcVar6 = pcVar7 + 2;
      cVar1 = *pcVar6;
    }
    pcVar6 = pcVar6 + (1 - (int)pCVar5);
    pCVar3 = _malloc((size_t)pcVar6);
    if (pCVar3 != (CHAR *)0x0) {
      pCVar11 = pCVar5;
      pCVar12 = pCVar3;
      for (uVar4 = (uint)pcVar6 >> 2; uVar4 != 0; uVar4 = uVar4 - 1) {
        *(undefined4 *)pCVar12 = *(undefined4 *)pCVar11;
        pCVar11 = pCVar11 + 4;
        pCVar12 = pCVar12 + 4;
      }
      for (uVar4 = (uint)pcVar6 & 3; uVar4 != 0; uVar4 = uVar4 - 1) {
        *pCVar12 = *pCVar11;
        pCVar11 = pCVar11 + 1;
        pCVar12 = pCVar12 + 1;
      }
      FreeEnvironmentStringsA(pCVar5);
      return pCVar3;
    }
    FreeEnvironmentStringsA(pCVar5);
    return (LPVOID)0x0;
  }
  if ((lpWideCharStr == (LPWCH)0x0) &&
     (lpWideCharStr = GetEnvironmentStringsW(), lpWideCharStr == (LPWCH)0x0)) {
    return (LPVOID)0x0;
  }
  WVar2 = *lpWideCharStr;
  pWVar8 = lpWideCharStr;
  while (WVar2 != L'\0') {
    do {
      pWVar9 = pWVar8;
      pWVar8 = pWVar9 + 1;
    } while (*pWVar8 != L'\0');
    pWVar8 = pWVar9 + 2;
    WVar2 = *pWVar8;
  }
  iVar10 = ((int)pWVar8 - (int)lpWideCharStr >> 1) + 1;
  _Size = WideCharToMultiByte(0,0,lpWideCharStr,iVar10,(LPSTR)0x0,0,(LPCSTR)0x0,(LPBOOL)0x0);
  if ((_Size != 0) && (lpMultiByteStr = _malloc(_Size), lpMultiByteStr != (LPSTR)0x0)) {
    iVar10 = WideCharToMultiByte(0,0,lpWideCharStr,iVar10,lpMultiByteStr,_Size,(LPCSTR)0x0,
                                 (LPBOOL)0x0);
    if (iVar10 == 0) {
      _free(lpMultiByteStr);
      lpMultiByteStr = (LPSTR)0x0;
    }
    FreeEnvironmentStringsW(lpWideCharStr);
    return lpMultiByteStr;
  }
  FreeEnvironmentStringsW(lpWideCharStr);
  return (LPVOID)0x0;
}



// WARNING: Globals starting with '_' overlap smaller symbols at the same address
// Library Function - Single Match
//  __setmbcp
// 
// Library: Visual Studio 1998 Release

int __cdecl __setmbcp(int _CodePage)

{
  byte *pbVar1;
  byte bVar2;
  UINT CodePage;
  UINT *pUVar3;
  BOOL BVar4;
  int iVar5;
  uint uVar6;
  uint uVar7;
  BYTE *pBVar8;
  byte *pbVar9;
  undefined4 *puVar10;
  int local_18;
  _cpinfo local_14;
  
  CodePage = getSystemCP(_CodePage);
  if (CodePage == DAT_00406e4c) {
    return 0;
  }
  if (CodePage == 0) {
    setSBCS();
    return 0;
  }
  local_18 = 0;
  pUVar3 = &DAT_00406e70;
  do {
    if (*pUVar3 == CodePage) {
      uVar6 = 0;
      puVar10 = &DAT_00406d48;
      for (iVar5 = 0x40; iVar5 != 0; iVar5 = iVar5 + -1) {
        *puVar10 = 0;
        puVar10 = puVar10 + 1;
      }
      *(undefined1 *)puVar10 = 0;
      do {
        pbVar9 = &DAT_00406e80 + (uVar6 + local_18 * 6) * 8;
        bVar2 = *pbVar9;
        while ((bVar2 != 0 && (pbVar9[1] != 0))) {
          uVar7 = (uint)*pbVar9;
          if (uVar7 <= pbVar9[1]) {
            bVar2 = (&DAT_00406e68)[uVar6];
            do {
              pbVar1 = (byte *)((int)&DAT_00406d48 + uVar7 + 1);
              *pbVar1 = *pbVar1 | bVar2;
              uVar7 = uVar7 + 1;
            } while (uVar7 <= pbVar9[1]);
          }
          pbVar9 = pbVar9 + 2;
          bVar2 = *pbVar9;
        }
        uVar6 = uVar6 + 1;
      } while (uVar6 < 4);
      DAT_00406e4c = CodePage;
      _DAT_00406e50 = _CPtoLCID(CodePage);
      DAT_00406e58 = *(undefined4 *)(&DAT_00406e74 + local_18 * 0x30);
      DAT_00406e5c = *(undefined4 *)(&DAT_00406e78 + local_18 * 0x30);
      DAT_00406e60 = *(undefined4 *)(local_18 * 0x30 + 0x406e7c);
      return 0;
    }
    pUVar3 = pUVar3 + 0xc;
    local_18 = local_18 + 1;
  } while (pUVar3 < &DAT_00406f60);
  BVar4 = GetCPInfo(CodePage,&local_14);
  if (BVar4 == 1) {
    puVar10 = &DAT_00406d48;
    for (iVar5 = 0x40; iVar5 != 0; iVar5 = iVar5 + -1) {
      *puVar10 = 0;
      puVar10 = puVar10 + 1;
    }
    *(undefined1 *)puVar10 = 0;
    if (local_14.MaxCharSize < 2) {
      _DAT_00406e50 = 0;
      DAT_00406e4c = 0;
    }
    else {
      pBVar8 = local_14.LeadByte;
      while ((local_14.LeadByte[0] != 0 && (pBVar8[1] != 0))) {
        uVar6 = (uint)*pBVar8;
        if (uVar6 <= pBVar8[1]) {
          do {
            pbVar9 = (byte *)((int)&DAT_00406d48 + uVar6 + 1);
            *pbVar9 = *pbVar9 | 4;
            uVar6 = uVar6 + 1;
          } while (uVar6 <= pBVar8[1]);
        }
        pBVar8 = pBVar8 + 2;
        local_14.LeadByte[0] = *pBVar8;
      }
      uVar6 = 1;
      do {
        pbVar9 = (byte *)((int)&DAT_00406d48 + uVar6 + 1);
        *pbVar9 = *pbVar9 | 8;
        uVar6 = uVar6 + 1;
      } while (uVar6 < 0xff);
      DAT_00406e4c = CodePage;
      _DAT_00406e50 = _CPtoLCID(CodePage);
    }
    DAT_00406e58 = 0;
    DAT_00406e5c = 0;
    DAT_00406e60 = 0;
    return 0;
  }
  if (DAT_00406e64 == 0) {
    return -1;
  }
  setSBCS();
  return 0;
}



// Library Function - Single Match
//  _getSystemCP
// 
// Library: Visual Studio 1998 Release

int __cdecl getSystemCP(int param_1)

{
  int iVar1;
  bool bVar2;
  
  if (param_1 == -2) {
    DAT_00406e64 = 1;
                    // WARNING: Could not recover jumptable at 0x004045cd. Too many branches
                    // WARNING: Treating indirect jump as call
    iVar1 = GetOEMCP();
    return iVar1;
  }
  if (param_1 == -3) {
    DAT_00406e64 = 1;
                    // WARNING: Could not recover jumptable at 0x004045e2. Too many branches
                    // WARNING: Treating indirect jump as call
    iVar1 = GetACP();
    return iVar1;
  }
  bVar2 = param_1 == -4;
  if (bVar2) {
    param_1 = DAT_00407228;
  }
  DAT_00406e64 = (uint)bVar2;
  return param_1;
}



// Library Function - Single Match
//  _CPtoLCID
// 
// Library: Visual Studio 1998 Release

undefined4 __cdecl _CPtoLCID(undefined4 param_1)

{
  switch(param_1) {
  case 0x3a4:
    return 0x411;
  default:
    return 0;
  case 0x3a8:
    return 0x804;
  case 0x3b5:
    return 0x412;
  case 0x3b6:
    return 0x404;
  }
}



// WARNING: Globals starting with '_' overlap smaller symbols at the same address
// Library Function - Single Match
//  _setSBCS
// 
// Library: Visual Studio 1998 Release

void __cdecl setSBCS(void)

{
  int iVar1;
  undefined4 *puVar2;
  
  puVar2 = &DAT_00406d48;
  for (iVar1 = 0x40; iVar1 != 0; iVar1 = iVar1 + -1) {
    *puVar2 = 0;
    puVar2 = puVar2 + 1;
  }
  *(undefined1 *)puVar2 = 0;
  DAT_00406e58 = 0;
  DAT_00406e4c = 0;
  _DAT_00406e50 = 0;
  DAT_00406e5c = 0;
  DAT_00406e60 = 0;
  return;
}



// Library Function - Single Match
//  ___initmbctable
// 
// Library: Visual Studio 1998 Release

void ___initmbctable(void)

{
  __setmbcp(-3);
  return;
}



// Library Function - Single Match
//  __ioinit
// 
// Library: Visual Studio 1998 Release

int __cdecl __ioinit(void)

{
  undefined4 *puVar1;
  DWORD DVar2;
  HANDLE hFile;
  byte *pbVar3;
  int *piVar4;
  uint uVar5;
  undefined4 *puVar6;
  UINT UVar7;
  UINT UVar8;
  int iVar9;
  UINT *pUVar10;
  _STARTUPINFOA local_44;
  
  puVar1 = _malloc(0x100);
  if (puVar1 == (undefined4 *)0x0) {
    __amsg_exit(0x1b);
  }
  DAT_00407560 = 0x20;
  DAT_00407460 = puVar1;
  if (puVar1 < puVar1 + 0x40) {
    do {
      *(undefined1 *)(puVar1 + 1) = 0;
      puVar6 = puVar1 + 2;
      *puVar1 = 0xffffffff;
      *(undefined1 *)((int)puVar1 + 5) = 10;
      puVar1 = puVar6;
    } while (puVar6 < DAT_00407460 + 0x40);
  }
  GetStartupInfoA(&local_44);
  if ((local_44.cbReserved2 != 0) && ((UINT *)local_44.lpReserved2 != (UINT *)0x0)) {
    UVar7 = *(UINT *)local_44.lpReserved2;
    pUVar10 = (UINT *)((int)local_44.lpReserved2 + 4);
    pbVar3 = (byte *)(UVar7 + (int)pUVar10);
    if (0x7ff < (int)UVar7) {
      UVar7 = 0x800;
    }
    UVar8 = UVar7;
    if ((int)DAT_00407560 < (int)UVar7) {
      piVar4 = &DAT_00407464;
      do {
        puVar1 = _malloc(0x100);
        UVar8 = DAT_00407560;
        if (puVar1 == (undefined4 *)0x0) break;
        *piVar4 = (int)puVar1;
        DAT_00407560 = DAT_00407560 + 0x20;
        if (puVar1 < puVar1 + 0x40) {
          do {
            *(undefined1 *)(puVar1 + 1) = 0;
            puVar6 = puVar1 + 2;
            *puVar1 = 0xffffffff;
            *(undefined1 *)((int)puVar1 + 5) = 10;
            puVar1 = puVar6;
          } while (puVar6 < (undefined4 *)(*piVar4 + 0x100));
        }
        piVar4 = piVar4 + 1;
        UVar8 = UVar7;
      } while ((int)DAT_00407560 < (int)UVar7);
    }
    uVar5 = 0;
    if (0 < (int)UVar8) {
      do {
        if (((*(HANDLE *)pbVar3 != (HANDLE)0xffffffff) && ((*pUVar10 & 1) != 0)) &&
           (((*pUVar10 & 8) != 0 || (DVar2 = GetFileType(*(HANDLE *)pbVar3), DVar2 != 0)))) {
          puVar1 = (undefined4 *)
                   (*(int *)((int)&DAT_00407460 + ((int)(uVar5 & 0xffffffe7) >> 3)) +
                   (uVar5 & 0x1f) * 8);
          *puVar1 = *(undefined4 *)pbVar3;
          *(byte *)(puVar1 + 1) = (byte)*pUVar10;
        }
        uVar5 = uVar5 + 1;
        pUVar10 = (UINT *)((int)pUVar10 + 1);
        pbVar3 = pbVar3 + 4;
      } while ((int)uVar5 < (int)UVar8);
    }
  }
  iVar9 = 0;
  do {
    piVar4 = DAT_00407460 + iVar9 * 2;
    if (*piVar4 == -1) {
      DVar2 = 0xfffffff6;
      *(undefined1 *)(piVar4 + 1) = 0x81;
      if (iVar9 != 0) {
        DVar2 = (iVar9 == 1) - 0xc;
      }
      hFile = GetStdHandle(DVar2);
      if ((hFile == (HANDLE)0xffffffff) || (DVar2 = GetFileType(hFile), DVar2 == 0)) {
        *(byte *)(piVar4 + 1) = *(byte *)(piVar4 + 1) | 0x40;
      }
      else {
        *piVar4 = (int)hFile;
        if ((DVar2 & 0xff) == 2) {
          *(byte *)(piVar4 + 1) = *(byte *)(piVar4 + 1) | 0x40;
        }
        else if ((DVar2 & 0xff) == 3) {
          *(byte *)(piVar4 + 1) = *(byte *)(piVar4 + 1) | 8;
        }
      }
    }
    else {
      *(byte *)(piVar4 + 1) = *(byte *)(piVar4 + 1) | 0x80;
    }
    iVar9 = iVar9 + 1;
  } while (iVar9 < 3);
  UVar7 = SetHandleCount(DAT_00407560);
  return UVar7;
}



// Library Function - Single Match
//  __seh_longjmp_unwind@4
// 
// Libraries: Visual Studio 1998 Debug, Visual Studio 1998 Release, Visual Studio 2003 Debug, Visual
// Studio 2003 Release

void __seh_longjmp_unwind_4(int param_1)

{
  __local_unwind2(*(int *)(param_1 + 0x18),*(int *)(param_1 + 0x1c));
  return;
}



// Library Function - Single Match
//  __FF_MSGBANNER
// 
// Library: Visual Studio 1998 Release

void __cdecl __FF_MSGBANNER(void)

{
  if ((DAT_00406308 == 1) || ((DAT_00406308 == 0 && (DAT_0040630c == 1)))) {
    __NMSG_WRITE(0xfc);
    if (DAT_00406ff8 != (code *)0x0) {
      (*DAT_00406ff8)();
    }
    __NMSG_WRITE(0xff);
  }
  return;
}



// Library Function - Single Match
//  __NMSG_WRITE
// 
// Library: Visual Studio 1998 Release

void __cdecl __NMSG_WRITE(int param_1)

{
  char cVar1;
  int *piVar2;
  DWORD DVar3;
  HANDLE hFile;
  int iVar4;
  int iVar5;
  uint uVar6;
  uint uVar7;
  char *pcVar8;
  char *pcVar9;
  CHAR *pCVar10;
  char *pcVar11;
  DWORD local_1a8;
  char local_1a4 [100];
  char acStack_140 [60];
  CHAR local_104 [260];
  
  iVar4 = 0;
  piVar2 = &DAT_00406f68;
  do {
    if (*piVar2 == param_1) break;
    piVar2 = piVar2 + 2;
    iVar4 = iVar4 + 1;
  } while (piVar2 < &DAT_00406ff8);
  if ((&DAT_00406f68)[iVar4 * 2] == param_1) {
    if ((DAT_00406308 == 1) || ((DAT_00406308 == 0 && (DAT_0040630c == 1)))) {
      if ((DAT_00407460 == 0) ||
         (hFile = *(HANDLE *)(DAT_00407460 + 0x10), hFile == (HANDLE)0xffffffff)) {
        hFile = GetStdHandle(0xfffffff4);
      }
      pcVar8 = *(char **)(iVar4 * 8 + 0x406f6c);
      uVar6 = 0xffffffff;
      pcVar9 = pcVar8;
      do {
        if (uVar6 == 0) break;
        uVar6 = uVar6 - 1;
        cVar1 = *pcVar9;
        pcVar9 = pcVar9 + 1;
      } while (cVar1 != '\0');
      WriteFile(hFile,pcVar8,~uVar6 - 1,&local_1a8,(LPOVERLAPPED)0x0);
    }
    else if (param_1 != 0xfc) {
      DVar3 = GetModuleFileNameA((HMODULE)0x0,local_104,0x104);
      if (DVar3 == 0) {
        pcVar8 = "<program name unknown>";
        pCVar10 = local_104;
        for (iVar5 = 5; iVar5 != 0; iVar5 = iVar5 + -1) {
          *(undefined4 *)pCVar10 = *(undefined4 *)pcVar8;
          pcVar8 = pcVar8 + 4;
          pCVar10 = pCVar10 + 4;
        }
        *(undefined2 *)pCVar10 = *(undefined2 *)pcVar8;
        pCVar10[2] = pcVar8[2];
      }
      pcVar8 = local_104;
      uVar6 = 0xffffffff;
      pcVar9 = local_104;
      do {
        if (uVar6 == 0) break;
        uVar6 = uVar6 - 1;
        cVar1 = *pcVar9;
        pcVar9 = pcVar9 + 1;
      } while (cVar1 != '\0');
      if (0x3c < ~uVar6) {
        uVar6 = 0xffffffff;
        pcVar8 = local_104;
        do {
          if (uVar6 == 0) break;
          uVar6 = uVar6 - 1;
          cVar1 = *pcVar8;
          pcVar8 = pcVar8 + 1;
        } while (cVar1 != '\0');
        pcVar8 = acStack_140 + ~uVar6;
        _strncpy(pcVar8,"...",3);
      }
      pcVar9 = "Runtime Error!\n\nProgram: ";
      pcVar11 = local_1a4;
      for (iVar5 = 6; iVar5 != 0; iVar5 = iVar5 + -1) {
        *(undefined4 *)pcVar11 = *(undefined4 *)pcVar9;
        pcVar9 = pcVar9 + 4;
        pcVar11 = pcVar11 + 4;
      }
      *(undefined2 *)pcVar11 = *(undefined2 *)pcVar9;
      uVar6 = 0xffffffff;
      do {
        pcVar9 = pcVar8;
        if (uVar6 == 0) break;
        uVar6 = uVar6 - 1;
        pcVar9 = pcVar8 + 1;
        cVar1 = *pcVar8;
        pcVar8 = pcVar9;
      } while (cVar1 != '\0');
      uVar6 = ~uVar6;
      iVar5 = -1;
      pcVar8 = local_1a4;
      do {
        pcVar11 = pcVar8;
        if (iVar5 == 0) break;
        iVar5 = iVar5 + -1;
        pcVar11 = pcVar8 + 1;
        cVar1 = *pcVar8;
        pcVar8 = pcVar11;
      } while (cVar1 != '\0');
      pcVar8 = pcVar9 + -uVar6;
      pcVar9 = pcVar11 + -1;
      for (uVar7 = uVar6 >> 2; uVar7 != 0; uVar7 = uVar7 - 1) {
        *(undefined4 *)pcVar9 = *(undefined4 *)pcVar8;
        pcVar8 = pcVar8 + 4;
        pcVar9 = pcVar9 + 4;
      }
      for (uVar6 = uVar6 & 3; uVar6 != 0; uVar6 = uVar6 - 1) {
        *pcVar9 = *pcVar8;
        pcVar8 = pcVar8 + 1;
        pcVar9 = pcVar9 + 1;
      }
      uVar6 = 0xffffffff;
      pcVar8 = "\n\n";
      do {
        pcVar9 = pcVar8;
        if (uVar6 == 0) break;
        uVar6 = uVar6 - 1;
        pcVar9 = pcVar8 + 1;
        cVar1 = *pcVar8;
        pcVar8 = pcVar9;
      } while (cVar1 != '\0');
      uVar6 = ~uVar6;
      iVar5 = -1;
      pcVar8 = local_1a4;
      do {
        pcVar11 = pcVar8;
        if (iVar5 == 0) break;
        iVar5 = iVar5 + -1;
        pcVar11 = pcVar8 + 1;
        cVar1 = *pcVar8;
        pcVar8 = pcVar11;
      } while (cVar1 != '\0');
      pcVar8 = pcVar9 + -uVar6;
      pcVar9 = pcVar11 + -1;
      for (uVar7 = uVar6 >> 2; uVar7 != 0; uVar7 = uVar7 - 1) {
        *(undefined4 *)pcVar9 = *(undefined4 *)pcVar8;
        pcVar8 = pcVar8 + 4;
        pcVar9 = pcVar9 + 4;
      }
      for (uVar6 = uVar6 & 3; uVar6 != 0; uVar6 = uVar6 - 1) {
        *pcVar9 = *pcVar8;
        pcVar8 = pcVar8 + 1;
        pcVar9 = pcVar9 + 1;
      }
      uVar6 = 0xffffffff;
      pcVar8 = *(char **)(iVar4 * 8 + 0x406f6c);
      do {
        pcVar9 = pcVar8;
        if (uVar6 == 0) break;
        uVar6 = uVar6 - 1;
        pcVar9 = pcVar8 + 1;
        cVar1 = *pcVar8;
        pcVar8 = pcVar9;
      } while (cVar1 != '\0');
      uVar6 = ~uVar6;
      iVar4 = -1;
      pcVar8 = local_1a4;
      do {
        pcVar11 = pcVar8;
        if (iVar4 == 0) break;
        iVar4 = iVar4 + -1;
        pcVar11 = pcVar8 + 1;
        cVar1 = *pcVar8;
        pcVar8 = pcVar11;
      } while (cVar1 != '\0');
      pcVar8 = pcVar9 + -uVar6;
      pcVar9 = pcVar11 + -1;
      for (uVar7 = uVar6 >> 2; uVar7 != 0; uVar7 = uVar7 - 1) {
        *(undefined4 *)pcVar9 = *(undefined4 *)pcVar8;
        pcVar8 = pcVar8 + 4;
        pcVar9 = pcVar9 + 4;
      }
      for (uVar6 = uVar6 & 3; uVar6 != 0; uVar6 = uVar6 - 1) {
        *pcVar9 = *pcVar8;
        pcVar8 = pcVar8 + 1;
        pcVar9 = pcVar9 + 1;
      }
      ___crtMessageBoxA(local_1a4,"Microsoft Visual C++ Runtime Library",0x12010);
      return;
    }
  }
  return;
}



// Library Function - Single Match
//  ___crtMessageBoxA
// 
// Library: Visual Studio 1998 Release

int __cdecl ___crtMessageBoxA(LPCSTR _LpText,LPCSTR _LpCaption,UINT _UType)

{
  HMODULE hModule;
  int iVar1;
  
  iVar1 = 0;
  if (DAT_0040722c != (FARPROC)0x0) {
LAB_00404bef:
    if (DAT_00407230 != (FARPROC)0x0) {
      iVar1 = (*DAT_00407230)();
    }
    if ((iVar1 != 0) && (DAT_00407234 != (FARPROC)0x0)) {
      iVar1 = (*DAT_00407234)(iVar1);
    }
    iVar1 = (*DAT_0040722c)(iVar1,_LpText,_LpCaption,_UType);
    return iVar1;
  }
  hModule = LoadLibraryA("user32.dll");
  if (hModule != (HMODULE)0x0) {
    DAT_0040722c = GetProcAddress(hModule,"MessageBoxA");
    if (DAT_0040722c != (FARPROC)0x0) {
      DAT_00407230 = GetProcAddress(hModule,"GetActiveWindow");
      DAT_00407234 = GetProcAddress(hModule,"GetLastActivePopup");
      goto LAB_00404bef;
    }
  }
  return 0;
}



// Library Function - Single Match
//  _strncpy
// 
// Library: Visual Studio 1998 Release

char * __cdecl _strncpy(char *_Dest,char *_Source,size_t _Count)

{
  uint uVar1;
  uint uVar2;
  char cVar3;
  uint uVar4;
  uint *puVar5;
  
  if (_Count == 0) {
    return _Dest;
  }
  puVar5 = (uint *)_Dest;
  if (((uint)_Source & 3) != 0) {
    while( true ) {
      uVar4 = *(uint *)_Source;
      _Source = (char *)((int)_Source + 1);
      *(char *)puVar5 = (char)uVar4;
      puVar5 = (uint *)((int)puVar5 + 1);
      _Count = _Count - 1;
      if (_Count == 0) {
        return _Dest;
      }
      if ((char)uVar4 == '\0') break;
      if (((uint)_Source & 3) == 0) {
        uVar4 = _Count >> 2;
        goto joined_r0x00404c7e;
      }
    }
    do {
      if (((uint)puVar5 & 3) == 0) {
        uVar4 = _Count >> 2;
        cVar3 = '\0';
        if (uVar4 == 0) goto LAB_00404cbb;
        goto LAB_00404d29;
      }
      *(char *)puVar5 = '\0';
      puVar5 = (uint *)((int)puVar5 + 1);
      _Count = _Count - 1;
    } while (_Count != 0);
    return _Dest;
  }
  uVar4 = _Count >> 2;
  if (uVar4 != 0) {
    do {
      uVar1 = *(uint *)_Source;
      uVar2 = *(uint *)_Source;
      _Source = (char *)((int)_Source + 4);
      if (((uVar1 ^ 0xffffffff ^ uVar1 + 0x7efefeff) & 0x81010100) != 0) {
        if ((char)uVar2 == '\0') {
          *puVar5 = 0;
joined_r0x00404d25:
          while( true ) {
            uVar4 = uVar4 - 1;
            puVar5 = puVar5 + 1;
            if (uVar4 == 0) break;
LAB_00404d29:
            *puVar5 = 0;
          }
          cVar3 = '\0';
          _Count = _Count & 3;
          if (_Count != 0) goto LAB_00404cbb;
          return _Dest;
        }
        if ((char)(uVar2 >> 8) == '\0') {
          *puVar5 = uVar2 & 0xff;
          goto joined_r0x00404d25;
        }
        if ((uVar2 & 0xff0000) == 0) {
          *puVar5 = uVar2 & 0xffff;
          goto joined_r0x00404d25;
        }
        if ((uVar2 & 0xff000000) == 0) {
          *puVar5 = uVar2;
          goto joined_r0x00404d25;
        }
      }
      *puVar5 = uVar2;
      puVar5 = puVar5 + 1;
      uVar4 = uVar4 - 1;
joined_r0x00404c7e:
    } while (uVar4 != 0);
    _Count = _Count & 3;
    if (_Count == 0) {
      return _Dest;
    }
  }
  do {
    cVar3 = (char)*(uint *)_Source;
    _Source = (char *)((int)_Source + 1);
    *(char *)puVar5 = cVar3;
    puVar5 = (uint *)((int)puVar5 + 1);
    if (cVar3 == '\0') {
      while (_Count = _Count - 1, _Count != 0) {
LAB_00404cbb:
        *(char *)puVar5 = cVar3;
        puVar5 = (uint *)((int)puVar5 + 1);
      }
      return _Dest;
    }
    _Count = _Count - 1;
  } while (_Count != 0);
  return _Dest;
}



void RtlUnwind(PVOID TargetFrame,PVOID TargetIp,PEXCEPTION_RECORD ExceptionRecord,PVOID ReturnValue)

{
                    // WARNING: Could not recover jumptable at 0x00404d3e. Too many branches
                    // WARNING: Treating indirect jump as call
  RtlUnwind(TargetFrame,TargetIp,ExceptionRecord,ReturnValue);
  return;
}


