#if defined(_WIN32) || defined(_WIN64)
// Use real Windows API – no stubs needed.
#else
#include <stddef.h>
#include <stdio.h>
#include <string.h>
#include <stdlib.h>
#include <stdint.h>
#include <unistd.h>
#include <fcntl.h>
#include <sys/types.h>
#include <sys/stat.h>

// Minimal stubs for Win32 API used by the decompiled code.

typedef void* HMODULE;
typedef void* HANDLE;

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

DWORD GetVersion(void) {
    // Fake Windows 10 version
    return 0x0A000000; // major=10, minor=0
}

LPSTR GetCommandLineA(void) {
    return "WorldsChat";
}

void GetStartupInfoA(LPSTARTUPINFOA lpStartupInfo) {
    if (lpStartupInfo) {
        memset(lpStartupInfo, 0, sizeof(*lpStartupInfo));
        lpStartupInfo->cb = sizeof(*lpStartupInfo);
    }
}

HMODULE GetModuleHandleA(LPCSTR lpModuleName) {
    return (HMODULE)0x1;
}

void ExitProcess(UINT uExitCode) {
    exit(uExitCode);
}

BOOL DeleteFileA(LPCSTR lpFileName) { (void)lpFileName; return TRUE; }

DWORD GetFileAttributesA(LPCSTR lpFileName) { (void)lpFileName; return FILE_ATTRIBUTE_NORMAL; }

DWORD GetLastError(void) { return 0; }

int _lopen(const char *path, int oflag) {
    int fd = open(path, O_RDONLY);
    return fd;
}

int _lread(int fd, void *buf, unsigned int count) {
    return (int)read(fd, buf, count);
}

int _llseek(int fd, long offset, int origin) {
    return (int)lseek(fd, offset, origin);
}

int _lcreat(const char *path, int mode) {
    return open(path, O_CREAT | O_WRONLY, mode);
}

int _lclose(int fd) { return close(fd); }

void *_memset(void *dst, int val, size_t n) { return memset(dst, val, n); }

void *_malloc(size_t size) { return malloc(size); }

void _free(void *ptr) { free(ptr); }

HGLOBAL GlobalAlloc(UINT uFlags, SIZE_T dwBytes) { (void)uFlags; return malloc(dwBytes); }

LPVOID GlobalLock(HGLOBAL hMem) { return hMem; }

BOOL GlobalUnlock(HGLOBAL hMem) { (void)hMem; return TRUE; }

HGLOBAL GlobalFree(HGLOBAL hMem) { free(hMem); return NULL; }

// Provide dummy implementations for other WinAPI functions used

HMODULE LoadLibraryA(LPCSTR lpFileName) { (void)lpFileName; return (HMODULE)0x1; }
FARPROC GetProcAddress(HMODULE hModule, LPCSTR lpProcName) { (void)hModule; (void)lpProcName; return NULL; }
BOOL FreeLibrary(HMODULE hModule) { (void)hModule; return TRUE; }
BOOL SetErrorMode(UINT uMode) { (void)uMode; return TRUE; }
int MessageBoxA(HWND hWnd, LPCSTR lpText, LPCSTR lpCaption, UINT uType) { (void)hWnd; (void)lpText; (void)lpCaption; (void)uType; return 0; }
int GetModuleFileNameA(HMODULE hModule, LPSTR lpFilename, DWORD nSize) { (void)hModule; strncpy(lpFilename, "WorldsChat.exe", nSize-1); lpFilename[nSize-1]='\0'; return (int)strlen(lpFilename); }

#endif // non‑Windows

// On Windows the real implementations are used from <windows.h>.
#else
#include <stddef.h>
#include <stdio.h>
#include <string.h>
#include <stdlib.h>
#include <stdint.h>

// Minimal stubs for Win32 API used by the decompiled code.
// They provide enough behaviour for the program to start, but do not aim for
// full compatibility.  Extend these as needed.

typedef void* HMODULE;
typedef void* HANDLE;

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

DWORD GetVersion(void) {
    // Return a fabricated Windows version: 0x0A00 (Windows 10)
    return 0x0A00;
}

LPSTR GetCommandLineA(void) {
    // Return the program's command line as a simple string.
    return "WorldsChat";
}

void GetStartupInfoA(LPSTARTUPINFOA lpStartupInfo) {
    if (lpStartupInfo) {
        memset(lpStartupInfo, 0, sizeof(*lpStartupInfo));
        lpStartupInfo->cb = sizeof(*lpStartupInfo);
    }
}

HMODULE GetModuleHandleA(LPCSTR lpModuleName) {
    // No real module handling on POSIX – return a dummy non‑NULL pointer.
    return (HMODULE)0x1;
}

// Stub for ExitProcess – simply call exit().
void ExitProcess(UINT uExitCode) {
    exit(uExitCode);
}

// Stub for DeleteFileA – pretend success.
BOOL DeleteFileA(LPCSTR lpFileName) {
    (void)lpFileName;
    return TRUE;
}

// Stub for GetFileAttributesA – return FILE_ATTRIBUTE_NORMAL.
DWORD GetFileAttributesA(LPCSTR lpFileName) {
    (void)lpFileName;
    return 0x80; // FILE_ATTRIBUTE_NORMAL
}

// Stub for GetLastError – always zero.
DWORD GetLastError(void) {
    return 0;
}


