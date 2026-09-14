// 0040df20 _Java_NET_worlds_console_Window_findWindow@12 [Global]
// programa: gamma.dll

undefined4
_Java_NET_worlds_console_Window_findWindow_12(int *param_1,undefined4 param_2,undefined4 param_3)

{
  char *pcVar1;
  char local_118 [256];
  DWORD local_18;
  undefined4 local_14;
  
                    /* 0xdf20  80  _Java_NET_worlds_console_Window_findWindow@12 */
  local_18 = GetCurrentProcessId();
  local_14 = 0;
  pcVar1 = (char *)(**(code **)(*param_1 + 0x2a4))(param_1,param_3,0);
  FUN_0044d6b0(local_118,pcVar1);
  (**(code **)(*param_1 + 0x2a8))(param_1,param_3,pcVar1);
  EnumWindows((WNDENUMPROC)&LAB_0040de60,(LPARAM)local_118);
  return local_14;
}


