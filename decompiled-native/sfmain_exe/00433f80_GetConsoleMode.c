// 00433f80 GetConsoleMode [KERNEL32.DLL]
// program: sfmain.exe

BOOL GetConsoleMode(HANDLE hConsoleHandle,LPDWORD lpMode)

{
  BOOL BVar1;
  
                    /* WARNING: Could not recover jumptable at 0x00433f80. Too many branches */
                    /* WARNING: Treating indirect jump as call */
  BVar1 = GetConsoleMode(hConsoleHandle,lpMode);
  return BVar1;
}


