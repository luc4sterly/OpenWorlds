// 0040e350 _Java_NET_worlds_console_Window_nativeHideChildWindow@12 [Global]
// programa: gamma.dll

void _Java_NET_worlds_console_Window_nativeHideChildWindow_12
               (undefined4 param_1,undefined4 param_2,HWND param_3)

{
  int iVar1;
  byte local_108 [256];
  
                    /* 0xe350  105  _Java_NET_worlds_console_Window_nativeHideChildWindow@12 */
  iVar1 = GetClassNameA(param_3,(LPSTR)local_108,0x100);
  if (iVar1 != 0) {
    iVar1 = FUN_0044d760(local_108,(byte *)s_TempClass_0046ea44,9);
    if (iVar1 == 0) {
      ShowWindow(param_3,0);
    }
  }
  return;
}


