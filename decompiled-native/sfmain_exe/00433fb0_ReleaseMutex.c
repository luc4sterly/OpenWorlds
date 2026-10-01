// 00433fb0 ReleaseMutex [KERNEL32.DLL]
// program: sfmain.exe

BOOL ReleaseMutex(HANDLE hMutex)

{
  BOOL BVar1;
  
                    /* WARNING: Could not recover jumptable at 0x00433fb0. Too many branches */
                    /* WARNING: Treating indirect jump as call */
  BVar1 = ReleaseMutex(hMutex);
  return BVar1;
}


