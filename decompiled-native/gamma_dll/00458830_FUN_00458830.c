// 00458830 FUN_00458830 [Global]
// programa: gamma.dll

/* WARNING: Globals starting with '_' overlap smaller symbols at the same address */

DWORD __cdecl FUN_00458830(HANDLE param_1,LPHANDLE param_2)

{
  HANDLE hTargetProcessHandle;
  HANDLE hSourceProcessHandle;
  LPHANDLE lpTargetHandle;
  DWORD dwDesiredAccess;
  BOOL BVar1;
  DWORD dwOptions;
  
  dwOptions = 2;
  BVar1 = 1;
  dwDesiredAccess = 0x100000;
  lpTargetHandle = param_2;
  hTargetProcessHandle = GetCurrentProcess();
  hSourceProcessHandle = GetCurrentProcess();
  BVar1 = DuplicateHandle(hSourceProcessHandle,param_1,hTargetProcessHandle,lpTargetHandle,
                          dwDesiredAccess,BVar1,dwOptions);
  if (BVar1 == 0) {
    *param_2 = (HANDLE)0xffffffff;
    _DAT_0049ff4c = GetLastError();
    return _DAT_0049ff4c;
  }
  return 0;
}


