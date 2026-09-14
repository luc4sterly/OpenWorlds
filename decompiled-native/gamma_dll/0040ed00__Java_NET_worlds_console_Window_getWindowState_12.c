// 0040ed00 _Java_NET_worlds_console_Window_getWindowState@12 [Global]
// programa: gamma.dll

undefined4
_Java_NET_worlds_console_Window_getWindowState_12
          (undefined4 param_1,undefined4 param_2,HWND param_3)

{
  BOOL BVar1;
  
                    /* 0xed00  94  _Java_NET_worlds_console_Window_getWindowState@12 */
  if (param_3 != (HWND)0x0) {
    BVar1 = IsIconic(param_3);
    if (BVar1 != 0) {
      return 1;
    }
    BVar1 = IsZoomed(param_3);
    if (BVar1 != 0) {
      return 2;
    }
  }
  return 0;
}


