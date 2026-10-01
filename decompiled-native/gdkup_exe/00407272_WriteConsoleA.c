// 00407272 WriteConsoleA [KERNEL32.DLL]
// program: gdkup.exe

BOOL WriteConsoleA(HANDLE hConsoleOutput,void *lpBuffer,DWORD nNumberOfCharsToWrite,
                  LPDWORD lpNumberOfCharsWritten,LPVOID lpReserved)

{
  BOOL BVar1;
  
                    /* WARNING: Could not recover jumptable at 0x00407272. Too many branches */
                    /* WARNING: Treating indirect jump as call */
  BVar1 = WriteConsoleA(hConsoleOutput,lpBuffer,nNumberOfCharsToWrite,lpNumberOfCharsWritten,
                        lpReserved);
  return BVar1;
}


