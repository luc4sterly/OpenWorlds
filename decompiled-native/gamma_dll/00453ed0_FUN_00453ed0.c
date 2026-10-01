// 00453ed0 FUN_00453ed0 [Global]
// program: gamma.dll

LPVOID FUN_00453ed0(void)

{
  LPVOID pvVar1;
  
  pvVar1 = TlsGetValue(DAT_00482370);
  if (pvVar1 == (LPVOID)0x0) {
    FUN_00453de0(0);
    pvVar1 = TlsGetValue(DAT_00482370);
  }
  if (pvVar1 == (LPVOID)0x0) {
    MessageBoxA((HWND)0x0,s_Could_not_get_thread_local_data_0048238c,s_MW_Win32_Runtime_00482378,0);
    FUN_00450a90(0);
  }
  return pvVar1;
}


