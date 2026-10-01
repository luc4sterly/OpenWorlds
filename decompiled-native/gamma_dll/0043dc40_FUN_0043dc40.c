// 0043dc40 FUN_0043dc40 [Global]
// program: gamma.dll

void __fastcall FUN_0043dc40(int *param_1)

{
  FUN_0043dd00(param_1);
  if (*(int *)(*param_1 + 0x2c) == 0) {
    return;
  }
  param_1[1] = 1;
  SendMessageA(*(HWND *)(*param_1 + 0x2c),0x401,0x8002,1);
  return;
}


