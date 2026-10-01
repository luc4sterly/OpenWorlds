// 0040c6a0 _Java_NET_worlds_console_Window_setDeltaMode@12 [Global]
// program: gamma.dll

void _Java_NET_worlds_console_Window_setDeltaMode_12(int *param_1,undefined4 param_2,byte param_3)

{
  SHORT SVar1;
  undefined4 *puVar2;
  
                    /* 0xc6a0  114  _Java_NET_worlds_console_Window_setDeltaMode@12 */
  puVar2 = (undefined4 *)(**(code **)(*param_1 + 400))(param_1,param_2,DAT_004891ac);
  if (*(byte *)(puVar2 + 9) != param_3) {
    if ((((param_3 != 0) && (SVar1 = GetAsyncKeyState(1), ((int)SVar1 & 0x8000U) == 0)) &&
        (SVar1 = GetAsyncKeyState(4), ((int)SVar1 & 0x8000U) == 0)) &&
       (SVar1 = GetAsyncKeyState(2), ((int)SVar1 & 0x8000U) == 0)) {
      return;
    }
    SendMessageA((HWND)*puVar2,0x8065,(uint)param_3,0);
    *(byte *)(puVar2 + 9) = param_3;
  }
  return;
}


