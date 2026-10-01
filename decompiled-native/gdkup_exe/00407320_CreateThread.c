// 00407320 CreateThread [KERNEL32.DLL]
// program: gdkup.exe

HANDLE CreateThread(LPSECURITY_ATTRIBUTES lpThreadAttributes,SIZE_T dwStackSize,
                   LPTHREAD_START_ROUTINE lpStartAddress,LPVOID lpParameter,DWORD dwCreationFlags,
                   LPDWORD lpThreadId)

{
  HANDLE pvVar1;
  
                    /* WARNING: Could not recover jumptable at 0x00407320. Too many branches */
                    /* WARNING: Treating indirect jump as call */
  pvVar1 = CreateThread(lpThreadAttributes,dwStackSize,lpStartAddress,lpParameter,dwCreationFlags,
                        lpThreadId);
  return pvVar1;
}


