// 0040727e GetConsoleMode [KERNEL32.DLL]
// program: gdkup.exe

BOOL GetConsoleMode(HANDLE hConsoleHandle,LPDWORD lpMode)

{
  BOOL BVar1;
  
                    /* WARNING: Could not recover jumptable at 0x0040727e. Too many branches */
                    /* WARNING: Treating indirect jump as call */
  BVar1 = GetConsoleMode(hConsoleHandle,lpMode);
  return BVar1;
}


