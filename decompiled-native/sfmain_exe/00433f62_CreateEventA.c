// 00433f62 CreateEventA [KERNEL32.DLL]
// program: sfmain.exe

HANDLE CreateEventA(LPSECURITY_ATTRIBUTES lpEventAttributes,BOOL bManualReset,BOOL bInitialState,
                   LPCSTR lpName)

{
  HANDLE pvVar1;
  
                    /* WARNING: Could not recover jumptable at 0x00433f62. Too many branches */
                    /* WARNING: Treating indirect jump as call */
  pvVar1 = CreateEventA(lpEventAttributes,bManualReset,bInitialState,lpName);
  return pvVar1;
}


