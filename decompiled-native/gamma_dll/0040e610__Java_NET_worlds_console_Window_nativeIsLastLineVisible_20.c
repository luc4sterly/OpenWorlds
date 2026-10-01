// 0040e610 _Java_NET_worlds_console_Window_nativeIsLastLineVisible@20 [Global]
// program: gamma.dll

bool _Java_NET_worlds_console_Window_nativeIsLastLineVisible_20
               (undefined4 param_1,undefined4 param_2,HWND param_3,undefined4 param_4,int param_5)

{
  LRESULT LVar1;
  uint uVar2;
  
                    /* 0xe610  107  _Java_NET_worlds_console_Window_nativeIsLastLineVisible@20 */
  LVar1 = SendMessageA(param_3,0xba,0,0);
  uVar2 = SendMessageA(param_3,0xd7,0,(param_5 + -8) * 0x10000 | 5);
  return LVar1 + -1 <= (int)(uVar2 >> 0x10);
}


