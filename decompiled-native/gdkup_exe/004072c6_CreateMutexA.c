// 004072c6 CreateMutexA [KERNEL32.DLL]
// program: gdkup.exe

HANDLE CreateMutexA(LPSECURITY_ATTRIBUTES lpMutexAttributes,BOOL bInitialOwner,LPCSTR lpName)

{
  HANDLE pvVar1;
  
                    /* WARNING: Could not recover jumptable at 0x004072c6. Too many branches */
                    /* WARNING: Treating indirect jump as call */
  pvVar1 = CreateMutexA(lpMutexAttributes,bInitialOwner,lpName);
  return pvVar1;
}


