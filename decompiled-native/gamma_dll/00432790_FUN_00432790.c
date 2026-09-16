// 00432790 FUN_00432790 [Global]
// programa: gamma.dll

undefined4 * __thiscall FUN_00432790(int param_1,undefined4 *param_2)

{
  *param_2 = *(undefined4 *)(param_1 + 0x78);
  param_2[1] = *(undefined4 *)(param_1 + 0x7c);
  return param_2;
}


