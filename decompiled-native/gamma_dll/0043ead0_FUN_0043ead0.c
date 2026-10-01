// 0043ead0 FUN_0043ead0 [Global]
// program: gamma.dll

undefined4 FUN_0043ead0(int param_1,undefined4 *param_2)

{
  BOOL BVar1;
  
  BVar1 = IsWindow(*(HWND *)(param_1 + 0x14));
  if (BVar1 == 0) {
    return 1;
  }
  *param_2 = *(undefined4 *)(param_1 + 0x14);
  return 0;
}


