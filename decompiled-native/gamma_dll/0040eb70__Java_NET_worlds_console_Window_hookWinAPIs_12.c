// 0040eb70 _Java_NET_worlds_console_Window_hookWinAPIs@12 [Global]
// program: gamma.dll

void _Java_NET_worlds_console_Window_hookWinAPIs_12
               (int *param_1,undefined4 param_2,undefined4 param_3)

{
  undefined4 uVar1;
  HMODULE pHVar2;
  HPALETTE pHVar3;
  FARPROC pFVar4;
  CHAR local_110 [256];
  
                    /* 0xeb70  97  _Java_NET_worlds_console_Window_hookWinAPIs@12 */
  uVar1 = (**(code **)(*param_1 + 0x2a4))(param_1,param_3,0);
  FUN_0044d650((int)local_110,s__s_dll_0046ea9c);
  FUN_0044d5a0(s_Trying_to_hook_dll__s_0046eaa4);
  pHVar2 = GetModuleHandleA(local_110);
  if (pHVar2 == (HMODULE)0x0) {
    FUN_0044d650((int)local_110,s__s_g_dll_0046eabc);
    pHVar2 = GetModuleHandleA(local_110);
    if (pHVar2 == (HMODULE)0x0) {
      FUN_0044d5a0(s_Failed_to_hook_dll__s_0046eac8);
      return;
    }
  }
  FUN_0044d5a0(s_Hooking_dll__s_0046eae0);
  (**(code **)(*param_1 + 0x2a8))(param_1,param_3,uVar1);
  if (pHVar2 == (HMODULE)0x0) {
    FUN_00402800(s_nWindow_0046e8c4,0x7f5);
  }
  pHVar3 = FUN_0040d7a0();
  if (pHVar3 != (HPALETTE)0x0) {
    pFVar4 = FUN_0040e740((short *)pHVar2,(byte *)s_gdi32_dll_0046eb00,s_SelectPalette_0046eaf0,
                          (FARPROC)&LAB_0040e8f0);
    if (pFVar4 == (FARPROC)0x0) {
      FUN_0044d5a0(s_Failed_to_hook_SelectPalette__0046eb0c);
    }
  }
  pFVar4 = FUN_0040e740((short *)pHVar2,(byte *)s_user32_dll_0046eb3c,s_SetWindowLongA_0046eb2c,
                        (FARPROC)&LAB_0040e970);
  if (pFVar4 == (FARPROC)0x0) {
    FUN_0044d5a0(s_Failed_to_hook_SetWindowLongA__0046eb48);
  }
  pFVar4 = FUN_0040e740((short *)pHVar2,(byte *)s_user32_dll_0046eb3c,s_GetWindowLongA_0046eb68,
                        (FARPROC)&LAB_0040ea60);
  if (pFVar4 == (FARPROC)0x0) {
    FUN_0044d5a0(s_Failed_to_hook_GetWindowLongA__0046eb78);
  }
  pFVar4 = FUN_0040e740((short *)pHVar2,(byte *)s_user32_dll_0046eb3c,s_LoadIconA_0046eb98,
                        (FARPROC)&LAB_0040eac0);
  if (pFVar4 == (FARPROC)0x0) {
    FUN_0044d5a0(s_Failed_to_hook_LoadIconA__0046eba4);
  }
  return;
}


