// 00417870 FUN_00417870 [Global]
// programa: gamma.dll

undefined4 FUN_00417870(void)

{
  int iVar1;
  _OSVERSIONINFOA *p_Var2;
  _OSVERSIONINFOA local_9c;
  
  iVar1 = FUN_004010c0(s_disableOpSysCheck_00470394,0);
  if (iVar1 == 0) {
    p_Var2 = &local_9c;
    for (iVar1 = 0x25; iVar1 != 0; iVar1 = iVar1 + -1) {
      p_Var2->dwOSVersionInfoSize = 0;
      p_Var2 = (_OSVERSIONINFOA *)&p_Var2->dwMajorVersion;
    }
    local_9c.dwOSVersionInfoSize = 0x94;
    GetVersionExA(&local_9c);
    if (local_9c.dwPlatformId == 2) {
      return 1;
    }
  }
  return 0;
}


