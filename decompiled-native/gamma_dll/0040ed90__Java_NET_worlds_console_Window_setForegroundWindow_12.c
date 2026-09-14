// 0040ed90 _Java_NET_worlds_console_Window_setForegroundWindow@12 [Global]
// programa: gamma.dll

void _Java_NET_worlds_console_Window_setForegroundWindow_12
               (undefined4 param_1,undefined4 param_2,HWND param_3)

{
                    /* 0xed90  115  _Java_NET_worlds_console_Window_setForegroundWindow@12 */
  if (param_3 != (HWND)0x0) {
    SetForegroundWindow(param_3);
  }
  return;
}


