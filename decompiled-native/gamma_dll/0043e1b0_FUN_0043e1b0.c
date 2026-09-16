// 0043e1b0 FUN_0043e1b0 [Global]
// programa: gamma.dll

undefined4 FUN_0043e1b0(int param_1,undefined4 *param_2)

{
  BOOL BVar1;
  
  BVar1 = IsWindow(*(HWND *)(param_1 + 0x1c));
  if (BVar1 == 0) {
    return 1;
  }
  *param_2 = *(undefined4 *)(param_1 + 0x1c);
  return 0;
}


