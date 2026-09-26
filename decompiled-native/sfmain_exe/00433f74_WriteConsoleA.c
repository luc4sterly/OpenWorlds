// 00433f74 WriteConsoleA [KERNEL32.DLL]
// programa: sfmain.exe

BOOL WriteConsoleA(HANDLE hConsoleOutput,void *lpBuffer,DWORD nNumberOfCharsToWrite,
                  LPDWORD lpNumberOfCharsWritten,LPVOID lpReserved)

{
  BOOL BVar1;
  
                    /* WARNING: Could not recover jumptable at 0x00433f74. Too many branches */
                    /* WARNING: Treating indirect jump as call */
  BVar1 = WriteConsoleA(hConsoleOutput,lpBuffer,nNumberOfCharsToWrite,lpNumberOfCharsWritten,
                        lpReserved);
  return BVar1;
}


