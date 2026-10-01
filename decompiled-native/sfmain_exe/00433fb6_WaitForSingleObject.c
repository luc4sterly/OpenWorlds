// 00433fb6 WaitForSingleObject [KERNEL32.DLL]
// program: sfmain.exe

DWORD WaitForSingleObject(HANDLE hHandle,DWORD dwMilliseconds)

{
  DWORD DVar1;
  
                    /* WARNING: Could not recover jumptable at 0x00433fb6. Too many branches */
                    /* WARNING: Treating indirect jump as call */
  DVar1 = WaitForSingleObject(hHandle,dwMilliseconds);
  return DVar1;
}


