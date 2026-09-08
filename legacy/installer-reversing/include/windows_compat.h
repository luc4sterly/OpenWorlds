#ifndef WINDOWS_COMPAT_H
#define WINDOWS_COMPAT_H

/* Minimal compatibility header for Windows types.
 * On Windows we simply include <windows.h>. On non‑Windows platforms we
 * provide opaque placeholder types so the code can compile (real implementations
 * are provided in src/platform_stub.c).
 */

#if defined(_WIN32) || defined(_WIN64)
#include <windows.h>
#else
/* Basic integral types */
#include <stddef.h>
#include <stdint.h>
#define FILE_ATTRIBUTE_NORMAL 0x80

typedef void* HMODULE;
typedef void* HINSTANCE;
typedef void* HWND;
typedef int HFILE;
typedef void* HANDLE;
typedef uint8_t BYTE;
typedef uint16_t WORD;
typedef uint32_t DWORD;
typedef int32_t LONG;
typedef char CHAR;
typedef const char* LPCSTR;
typedef void* LPVOID;
typedef char* LPSTR;
typedef uint32_t UINT;
typedef uint16_t USHORT;
typedef uint64_t ULONGLONG;
typedef int BOOL;
#define TRUE 1
#define FALSE 0

/* Minimal definitions for structures used in the original code */
typedef struct _STARTUPINFOA {
    DWORD   cb;
    LPSTR   lpReserved;
    LPSTR   lpDesktop;
    LPSTR   lpTitle;
    DWORD   dwX;
    DWORD   dwY;
    DWORD   dwXSize;
    DWORD   dwYSize;
    DWORD   dwXCountChars;
    DWORD   dwYCountChars;
    DWORD   dwFillAttribute;
    DWORD   dwFlags;
    WORD    wShowWindow;
    WORD    cbReserved2;
    LPBYTE  lpReserved2;
    HANDLE  hStdInput;
    HANDLE  hStdOutput;
    HANDLE  hStdError;
} STARTUPINFOA, *LPSTARTUPINFOA;

typedef struct _OSVERSIONINFOA {
    DWORD dwOSVersionInfoSize;
    DWORD dwMajorVersion;
    DWORD dwMinorVersion;
    DWORD dwBuildNumber;
    DWORD dwPlatformId;
    CHAR  szCSDVersion[128];
} OSVERSIONINFOA, *POSVERSIONINFOA, *LPOSVERSIONINFOA;

/* Symbolic constants used in the code */
#define WINAPI __stdcall
#define APIENTRY WINAPI
#define CALLBACK __stdcall

#endif // non‑Windows

#endif // WINDOWS_COMPAT_H

#if !defined(_WIN32) && !defined(_WIN64)
/* Additional minimal definitions required by the decompiled code */

typedef uint32_t pointer32;

typedef struct _IMAGE_DATA_DIRECTORY {
    DWORD VirtualAddress;
    DWORD Size;
} IMAGE_DATA_DIRECTORY, *PIMAGE_DATA_DIRECTORY;

#define IMAGE_NUMBEROF_DIRECTORY_ENTRIES 16

typedef struct _IMAGE_OPTIONAL_HEADER32 {
    WORD Magic;
    BYTE MajorLinkerVersion;
    BYTE MinorLinkerVersion;
    DWORD SizeOfCode;
    DWORD SizeOfInitializedData;
    DWORD SizeOfUninitializedData;
    DWORD AddressOfEntryPoint;
    DWORD BaseOfCode;
    DWORD BaseOfData;
    DWORD ImageBase;
    DWORD SectionAlignment;
    DWORD FileAlignment;
    WORD MajorOperatingSystemVersion;
    WORD MinorOperatingSystemVersion;
    WORD MajorImageVersion;
    WORD MinorImageVersion;
    WORD MajorSubsystemVersion;
    WORD MinorSubsystemVersion;
    DWORD Win32VersionValue;
    DWORD SizeOfImage;
    DWORD SizeOfHeaders;
    DWORD CheckSum;
    WORD Subsystem;
    WORD DllCharacteristics;
    DWORD SizeOfStackReserve;
    DWORD SizeOfStackCommit;
    DWORD SizeOfHeapReserve;
    DWORD SizeOfHeapCommit;
    DWORD LoaderFlags;
    DWORD NumberOfRvaAndSizes;
    IMAGE_DATA_DIRECTORY DataDirectory[IMAGE_NUMBEROF_DIRECTORY_ENTRIES];
} IMAGE_OPTIONAL_HEADER32, *PIMAGE_OPTIONAL_HEADER32;

typedef struct _IMAGE_NT_HEADERS32 {
    DWORD Signature;
    // Skipping FileHeader for brevity
    IMAGE_OPTIONAL_HEADER32 OptionalHeader;
} IMAGE_NT_HEADERS32, *PIMAGE_NT_HEADERS32;

typedef LONG_PTR ATOM; // simple placeholder
typedef void* FARPROC;
typedef void* HGDIOBJ;
#endif // non‑Windows

