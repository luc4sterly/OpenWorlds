// 00442340 _Java_NET_worlds_core_SystemInfo_GetPlatformID@8 [Global]
// program: gamma.dll

void _Java_NET_worlds_core_SystemInfo_GetPlatformID_8(int *param_1)

{
  BOOL BVar1;
  int iVar2;
  _OSVERSIONINFOA *p_Var3;
  undefined1 local_1a0 [256];
  _OSVERSIONINFOA local_a0;
  
  p_Var3 = &local_a0;
                    /* 0x42340  170  _Java_NET_worlds_core_SystemInfo_GetPlatformID@8 */
  for (iVar2 = 0x25; iVar2 != 0; iVar2 = iVar2 + -1) {
    p_Var3->dwOSVersionInfoSize = 0;
    p_Var3 = (_OSVERSIONINFOA *)&p_Var3->dwMajorVersion;
  }
  local_a0.dwOSVersionInfoSize = 0x94;
  BVar1 = GetVersionExA(&local_a0);
  if (BVar1 != 0) {
    switch(local_a0.dwPlatformId) {
    case 0:
      FUN_0044d650((int)local_1a0,s_Microsoft_Win32s_00478dbc);
      break;
    case 1:
      if ((local_a0.dwMajorVersion < 5) &&
         ((local_a0.dwMajorVersion != 4 || (local_a0.dwMinorVersion == 0)))) {
        FUN_0044d650((int)local_1a0,s_MS_Windows_95__version__d__d_00478d9c);
      }
      else {
        FUN_0044d650((int)local_1a0,s_MS_Windows_98__version__d__d_00478d7c);
      }
      break;
    case 2:
      FUN_0044d650((int)local_1a0,s_MS_Windows_NT_version__d__d__s___00478d50);
    }
    (**(code **)(*param_1 + 0x29c))(param_1,local_1a0);
    return;
  }
  (**(code **)(*param_1 + 0x29c))(param_1,s_Unknown_00478d48);
  return;
}


